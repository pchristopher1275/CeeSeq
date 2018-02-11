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
#include "../../../../Shared/cseq/midiseq.c"

typedef struct _CseqHub
{
    t_object d_obj;

    void *d_proxy;
    long d_inletnum;

    void *pitch_outlet;
    void *velocity_outlet;
    void *duration_outlet;

    t_timeobject *schedular;

    Hub hub;
} CseqHub;

#define CseqHub_hub(cseq)       (&(cseq)->hub)
#define CseqHub_padList(cseq)   (Hub_padList(CseqHub_hub(cseq)))
#define CseqHub_trackList(cseq) (Hub_trackList(CseqHub_hub(cseq)))

void *CseqHub_new(t_symbol *s, long argc, t_atom *argv);
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
        className = sdsnew("cseqHub");
    }
    else {
        className = sdscatprintf(sdsempty(), "cseqHub%d", CSEQ_BUILD_NUMBER);
    }
    Error_declare(err);
    DBLog_init("hub", err);
    Midiseq_setMidicsvExecPath();

    t_class *c = class_new(className, (method)CseqHub_new, (method)CseqHub_free,
        sizeof(CseqHub), (method)0L, A_GIMME, 0);
    class_addmethod(c, (method)CseqHub_assist, "assist", A_CANT, 0);
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

void *CseqHub_new(t_symbol *s, long argc, t_atom *argv)
{
    CseqHub *x = (CseqHub *)object_alloc(CseqHub_class);
    x->d_inletnum = 0;
    x->d_proxy = proxy_new(x, 1, &x->d_inletnum);
    x->duration_outlet = intout(x);
    x->velocity_outlet = intout(x);
    x->pitch_outlet    = intout(x);
    x->schedular = (t_object *)time_new((t_object *)x, gensym("schedular"), (method)CseqHub_playnotes,
        TIME_FLAGS_TICKSONLY | TIME_FLAGS_USECLOCK);

    t_atom a = {0};
    atom_setfloat(&a, 0.0);
    time_setvalue(x->schedular, NULL, 1, &a);

    Error_declare(err);
    const char *HOME = getenv("HOME");
    if (HOME == NULL) {
        post("Failed to find HOME");
        HOME = "foobar";
    }

    t_symbol *cg = gensym("cg");
    t_symbol *pianoName = gensym("piano");
    t_symbol *organName = gensym("organ");
    const int npads = 128;
    CseqHub_padList(x) = PadList_new(npads);
    const bool initWithNotes = true;
    for (int i = 0; i < PadList_padsLength(CseqHub_padList(x)); i++) {
        Pad *pad            = PadList_pad(CseqHub_padList(x), i, err);
        Pad_padIndex(pad)   = i;
        Pad_chokeGroup(pad) = cg;
        
        if (initWithNotes) {
            int roll           = (i % 24);
            int pitch          = 48 + roll;
            Pad_trackName(pad) = organName;
            if (roll >= 8) {
                Midiseq *midi = Midiseq_newNote(pitch);                                
                Pad_setSequence(pad, midi);
            } else {
                sds midifile = sdscatprintf(sdsempty(), "%s/Desktop/test%d.mid", HOME, roll);
                if (Error_maypost(err)) {
                    sdsfree(midifile);
                    continue;
                }

                Midiseq *midi = Midiseq_fromfile(midifile, err);
                Error_maypost(err);
                sdsfree(midifile);
                if (midi != NULL) {
                    Pad_setSequence(pad, midi);
                }
            }
        } else {
            int index = i % 8;
            bool useOrgan = (i % 16) >= 8;
            Pad_trackName(pad)  = useOrgan ? organName : pianoName;    
            if (index != 7) {
                sds midifile = sdscatprintf(sdsempty(), "%s/Desktop/test%d.mid", HOME, index);
                if (Error_maypost(err)) {
                    sdsfree(midifile);
                    continue;
                }

                Midiseq *midi = Midiseq_fromfile(midifile, err);
                Error_maypost(err);
                sdsfree(midifile);
                if (midi != NULL) {
                    Pad_setSequence(pad, midi);
                }
            }
        }
    }
    // START TRANSPORT
    itm_resume(time_getitm(x->schedular));

    PortFind_declare(pf);
    PortFind_discover(pf, (t_object*)x, CseqHub_hub(x) ,err);
    Error_maypost(err);
    CseqHub_trackList(x) = TrackList_new(pf);
    PadList_assignTrack(CseqHub_padList(x), CseqHub_trackList(x));
    PortFind_clear(pf);

    Error_clear(err);
    CseqHub_int(x, 60);
    return x;
}


void CseqHub_free(CseqHub *x)
{
    PadList_free(CseqHub_padList(x));
    TrackList_free(CseqHub_trackList(x));
    object_free((t_object *) x->d_proxy);
    object_free(x->schedular);
}


void CseqHub_assist(CseqHub *x, void *b, long m, long a, char *s)
{
    if (m == ASSIST_INLET) {                      // Inlets
        switch (a) {
            case 0: sprintf(s, "bang Gets Delayed, stop Cancels"); break;
            case 1: sprintf(s, "Set Delay Time"); break;
        }
    }
    else {                                        // Outlets
        switch (a) {
            case 0: sprintf(s, "Delayed bang"); break;
            case 1: sprintf(s, "Another Delayed bang"); break;
        }
    }
}


static int lastVelocity = 0;
void CseqHub_int(CseqHub *x, long val)
{
    Error_declare(err);
    if (proxy_getinlet((t_object *)x) == 1) {
        lastVelocity = val;
        return;
    }

    if (lastVelocity == 0) {
        int padIndex = (int)val;
        Pad *pad     = PadList_pad(CseqHub_padList(x), padIndex, err);
        if (Error_maypost(err)) {
            return;
        }
        Pad_noteReleasePending(pad) = false;
        NoteManager_padNoteOff(Track_noteManager(Pad_track(pad)), padIndex);
        return;
    }

    int padIndex = (int)val;
    Ticks now = cseqHub_now();
    PadList_play(CseqHub_padList(x), padIndex, now, now, false, err);
    Error_maypost(err);
    time_stop(x->schedular);
    time_now(x->schedular, NULL);
    Error_clear(err);
}


void CseqHub_playnotes(CseqHub *x)
{
    Error_declare(err);
    Ticks now = cseqHub_now();
    MidiseqCell cell = {0};
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

    Pad *pad = NULL;
    PadListIterator_declare(iterator);
    while (PadList_iterateRunning(CseqHub_padList(x), iterator, &pad)) {
        Midiseq *midi            = Pad_sequence(pad);
        NoteManager *noteManager = Track_noteManager(Pad_track(pad));
        while ( (status = Midiseq_nextevent(midi, now, &cell, err)) == Midiseq_nextEventContinue) {
            if (MidiseqCell_type(cell) == Midiseq_endgrptype) {
                Pad_inEndgroup(pad) = true;
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
        } else if (status == Midiseq_nextEventComplete) {
            PadList_clearRunning(CseqHub_padList(x), iterator); 
        }
    }
    if (smallestDelta >= 0) {
        t_atom callbackInterval = {0};
        atom_setfloat(&callbackInterval, smallestDelta);
        time_setvalue(x->schedular, NULL, 1, &callbackInterval);
        time_schedule(x->schedular, NULL);
    }
    Error_clear(err);
}
