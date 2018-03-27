/**
    @file
    CseqHub - an ITM-based delay

    @ingroup	examples
*/

#include "ext.h"
#include "ext_common.h"
#include "ext_obex.h"
#include "ext_time.h"
#include "ext_itm.h"

#include "mem.c"
#include "core.c"
// #include "types.h"
// #include "array.c"
// #include "interface.h"

// #include "mEventAr.h"
// #include "symbolPtrAr.h"
// #include "ptrAr.h"
// #include "intAr.h"

// #include "sequence.h"


// #include "dispatch.h"
// #include "midiseq.h"
// #include "interface.c"
// #include "dispatch.c"
// #include "midiseq.c"
#include "application.c"


typedef struct _CseqHub
{
    t_object d_obj;

    // Be careful initializing these. I assume that object_new DOES NOT zero the whole struct.
    void *proxy;
    long inletnum;
    t_timeobject *schedular;
    Hub hub;
} CseqHub;

#define CseqHub_hub(cseq)               (&(cseq)->hub)

#define CseqHub_padList(cseq)           Hub_padList(CseqHub_hub(cseq))
#define CseqHub_trackList(cseq)         Hub_trackList(CseqHub_hub(cseq))
#define CseqHub_bank(cseq)              Hub_bank(CseqHub_hub(cseq))
#define CseqHub_selectedPad(cseq)       Hub_selectedPad(CseqHub_hub(cseq))
#define CseqHub_grabNextTappedPad(cseq) Hub_grabNextTappedPad(CseqHub_hub(cseq))
#define CseqHub_padIndexFromInNote(cseq, inputNote) Hub_padIndexFromInNote(CseqHub_hub(cseq), inputNote)

void *CseqHub_new(Symbol *s, long argc, t_atom *argv);
void CseqHub_free(CseqHub *x);
void CseqHub_assist(CseqHub *x, void *b, long m, long a, char *s);
void CseqHub_int(CseqHub *x, long n);
void CseqHub_playnotes(CseqHub *x);

static t_class *CseqHub_class = NULL;

#ifndef CSEQ_BUILD_NUMBER
#define CSEQ_BUILD_NUMBER 0
#endif

void ext_main(void *r)
{
    // NOTE: If class_new makes a copy of className, than className has essentially leaked.
    sds className = NULL;
    if (CSEQ_BUILD_NUMBER == 0) {
        className = sdsnew("Hub");
    }
    else {
        className = sdscatprintf(sdsempty(), "Hub%d", CSEQ_BUILD_NUMBER);
    }
    Error_declare(err);
    DBLog_init("hub", err);
    Midiseq_setMidicsvExecPath();

    t_class *c = class_new(className, (method)CseqHub_new, (method)CseqHub_free,
        sizeof(CseqHub), (method)0L, A_GIMME, 0);
    class_addmethod(c, (method)CseqHub_int, "int", A_LONG, 0);
    class_register(CLASS_BOX, c);
    if (Error_iserror(err)) {
        post("DBLog failed: %s", Error_message(err));
        Error_clear(err);
    }

    Error_clear(err);
    CseqHub_class = c;
}


// initial optional arg is delay time

void *CseqHub_new(Symbol *s, long argc, t_atom *argv)
{
    Error_declare(err);
    CseqHub *x = (CseqHub *)object_alloc(CseqHub_class);
    x->inletnum        = 0;
    x->proxy           = proxy_new(x, 1, &x->inletnum);
    x->schedular       = (t_object *)time_new((t_object *)x, gensym("schedular"), (method)CseqHub_playnotes,
        TIME_FLAGS_TICKSONLY | TIME_FLAGS_USECLOCK);
    Hub *hub = CseqHub_hub(x);
    Hub zero = {0};
    *hub = zero;

    t_atom a = {0};
    atom_setfloat(&a, 0.0);
    time_setvalue(x->schedular, NULL, 1, &a);

    PortFind_declare(pf);
    PortFind_discover(pf, (t_object*)x, CseqHub_hub(x) ,err);
    Error_maypost(err);

    Hub_init(hub, pf, err);    
    
    // Symbol *pianoName = gensym("piano");
    Symbol *organName = gensym("organ");
    const int npads = Hub_padsPerBank;
    Hub_setPadList(CseqHub_hub(x), PadList_new(npads));
    PadAr *pads = PadList_pads(CseqHub_padList(x));
    PadAr_foreach(it, pads) {
        Pad *pad = it.var;
        Pad_setPadIndex(pad, it.index);

        // Pad_setChokeGroupGlobal(pad, it.index % 5 == 0 ? true : false);
        // Pad_setChokeGroupInstrument(pad, it.index % 6);
        // Pad_setChokeGroupIndex(pad, it.index % 17); 

        Pad_setChokeGroupGlobal(pad, 1);
        Pad_setChokeGroupInstrument(pad, 1);
        Pad_setChokeGroupIndex(pad, 1); 

        Pad_computeChokeGroup(pad);
        Pad_setTrackName(pad, organName);
        int pitch = 48 + (it.index % 24);
        Midiseq *mseq = Midiseq_newNote(pitch);
        Pad_setSequence(pad, mseq);        
    }

    // START TRANSPORT
    itm_resume(time_getitm(x->schedular));

    Hub_setTrackList(CseqHub_hub(x), TrackList_new(pf));
    PadList_assignTrack(CseqHub_padList(x), CseqHub_trackList(x));

    Hub_changeSelectedPad(hub, 0, err);
    Error_maypost(err);
    return x;
}


void CseqHub_free(CseqHub *x)
{
    PadList_free(CseqHub_padList(x));
    TrackList_free(CseqHub_trackList(x));
    object_free((t_object *) x->proxy);
    object_free(x->schedular);
}

static int lastVelocity = 0;
void CseqHub_int(CseqHub *x, long val)
{
    Error_declare(err);
    if (proxy_getinlet((t_object *)x) == 1) {
        lastVelocity = val;
        return;
    }

    int padIndex = CseqHub_padIndexFromInNote(x, val);
    if (padIndex >= PadAr_len(PadList_pads(CseqHub_padList(x)))) {
        post("Bad padIndex %d", padIndex);
        return;
    }

    if (CseqHub_grabNextTappedPad(x)) {
        Hub_setGrabNextTappedPad(CseqHub_hub(x), false);
        Hub *hub = CseqHub_hub(x);
        Error_declare(err);
        Hub_changeSelectedPad(hub, padIndex, err);
        Error_maypost(err);
    }

    if (lastVelocity == 0) {
        Pad *pad     = PadList_pad(CseqHub_padList(x), padIndex, err);
        if (Error_maypost(err)) {
            return;
        }
        Pad_setNoteReleasePending(pad, false);
        NoteManager_padNoteOff(Track_noteManager(Pad_track(pad)), padIndex);
        return;
    }

    Ticks now = cseqHub_now();
    PadList_play(CseqHub_padList(x), padIndex, now, now, false, err);
    Error_maypost(err);
    time_stop(x->schedular);
    time_now(x->schedular,  NULL);
    Error_clear(err);
}


void CseqHub_playnotes(CseqHub *x)
{
    Error_declare(err);
    Ticks now = cseqHub_now();
    MEvent cell = {0};
    int status = 0;
    Ticks smallestDelta = -1;
    for (int i = 0; i < TrackList_count(CseqHub_trackList(x)); i++) {
        Track *track = TrackList_findTrackByIndex(CseqHub_trackList(x), i, err);
        Error_maypost(err);
        Ticks delta = NoteManager_scheduleOffs(Track_noteManager(track), now);
        if (smallestDelta < 0) {
            smallestDelta = delta;
        }
        else if (delta >= 0 && delta < smallestDelta) {
            smallestDelta = delta;
        }
    }

    PadPtrAr *running = PadList_running(CseqHub_padList(x));

    int count = 0;
    PadPtrAr_foreach(it, running) {
        Pad *pad                 = *it.var;
        dblog("count = %d: %s (%d, %d, %d)", count++, pad == NULL ? "yes" : "no", it.index, it.lBound, it.uBound);
        Midiseq *mseq            = Pad_sequence(pad);
        NoteManager *noteManager = Track_noteManager(Pad_track(pad));
        while ( (status = Midiseq_nextevent(mseq, now, &cell, err)) == Midiseq_nextEventContinue) {
            if (MEvent_type(cell) == Midiseq_endgrptype) {
                Pad_setInEndgroup(pad, true);
            }

            NoteManager_midievent(noteManager, cell, (Pad_noteReleasePending(pad) && Pad_inEndgroup(pad)) ? Pad_padIndex(pad) : -1);
        }
        if (Error_maypost(err)) {
            continue;
        }
        if (status == Midiseq_nextEventBreak) {
            Ticks delta = cell.t-now;
            if (smallestDelta < 0) {
                smallestDelta = delta;
            }
            else if (delta < smallestDelta) {
                smallestDelta = delta;
            }
        }
        else if (status == Midiseq_nextEventComplete) {
            PadPtrArFIt_remove(&it);            
        }
    }


    // PadPtrAr_foreach(it, running) {

    //     Pad *pad                 = *it.var;
    //     Midiseq *mseq            = Pad_sequence(pad);
    //     NoteManager *noteManager = Track_noteManager(Pad_track(pad));
    //     while ( (status = Midiseq_nextevent(mseq, now, &cell, err)) == Midiseq_nextEventContinue) {
    //         if (MEvent_type(cell) == Midiseq_endgrptype) {
    //             Pad_setInEndgroup(pad, true);
    //         }

    //         NoteManager_midievent(noteManager, cell, (Pad_noteReleasePending(pad) && Pad_inEndgroup(pad)) ? Pad_padIndex(pad) : -1);
    //     }
    //     if (Error_maypost(err)) {
    //         continue;
    //     }
    //     if (status == Midiseq_nextEventBreak) {
    //         Ticks delta = cell.t-now;
    //         if (smallestDelta < 0) {
    //             smallestDelta = delta;
    //         }
    //         else if (delta < smallestDelta) {
    //             smallestDelta = delta;
    //         }
    //     }
    //     else if (status == Midiseq_nextEventComplete) {
    //         PadPtrAr_remove(running, it.index, err);
    //         if (Error_maypost(err)) {
    //             continue;
    //         }            
    //         it.index--;             
    //     }
    // }
    if (smallestDelta >= 0) {
        t_atom callbackInterval = {0};
        atom_setfloat(&callbackInterval, smallestDelta);
        time_setvalue(x->schedular, NULL, 1, &callbackInterval);
        time_schedule(x->schedular, NULL);
    }
    Error_clear(err);
}
