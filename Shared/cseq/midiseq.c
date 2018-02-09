#include <string.h>
#include <stdlib.h>
#include "shared.c"
#include "midiseq.h"

//
// Memory allocation Notes. These are the functions that are used in sdsalloc.h
//

// malloc
//          t_ptr sysmem_newptr	(long size)
// realloc
//          t_ptr sysmem_resizeptr	(void *ptr, long newsize)
// calloc
//          t_ptr sysmem_newptrclear(long size)
// free
//          void sysmem_freeptr	(	void * 	ptr	)

//
// U t i l i t y
//
static int convertIntFileLine(const char *src, Error *err, const char *file, int line)
{
    errno = 0;
    long v = strtol(src, NULL, 10);
    if (errno != 0) {
        Error_formatFileLine(err, file, line,
            sdscatprintf(sdsempty(), "Failed to convert int error code %s",
            (errno == EINVAL ? "EINVAL" : errno == ERANGE ? "ERANGE" : "Unknown")));

    }
    return v;
}


#define convertInt(src, err) convertIntFileLine(src, err, __FILE__, __LINE__)

//
// M I D I S E Q
//
const int Midiseq_notetype   = 1;
const int Midiseq_bendtype   = 2;
const int Midiseq_cctype     = 3;
const int Midiseq_cycletype  = 4;
const int Midiseq_endgrptype = 5;


#define MidiseqCell_type(cell) ((cell).type)
#define MidiseqCell_t(cell) ((cell).t)
#define MidiseqCell_notePitch(cell) ((cell).b.b[0])
#define MidiseqCell_noteVelocity(cell) ((cell).b.b[1])
#define MidiseqCell_noteDuration(cell) ((cell).duration)
#define MidiseqCell_ccNumber(cell) ((cell).b.b[0])
#define MidiseqCell_ccValue(cell) ((cell).b.b[1])
#define MidiseqCell_bendValue(cell) ((cell).b.bend)

const int Midiseq_maxLineLength = 1024;

// Create new empty midi sequence
static inline Midiseq *Midiseq_new()
{
    Midiseq *midi = (Midiseq*)sysmem_newptrclear(sizeof(Midiseq));
    midi->sequenceLength = 480*4;
    sb_add(midi->data, 2);
    MidiseqCell cell = {0};
    cell.t = 0;
    cell.type = Midiseq_endgrptype;
    midi->data[0] = cell;
    cell.t = midi->sequenceLength;
    cell.type = Midiseq_cycletype;
    midi->data[1] = cell;
    return midi;
}


static inline void Midiseq_init(Midiseq *midi)
{
    if (midi != NULL) {
        Midiseq zero = {0};
        *midi = zero;
    }
}


static inline void Midiseq_clear(Midiseq *midi)
{
    if (midi != NULL) {
        sb_free(midi->data);
        Midiseq zero = {0};
        *midi = zero;
    }
}


static inline void Midiseq_free(Midiseq *midi)
{
    if (midi != NULL) {
        Midiseq_clear(midi);
        sysmem_freeptr(midi);
    }
}


static inline int Midiseq_len(Midiseq *midi)
{
    // REMEMBER: because of cycle and endgroup, every midi sequence has at least 2 elements.
    return sb_count(midi->data);
}


static inline void Midiseq_push(Midiseq *midi, MidiseqCell cell)
{
    sb_push(midi->data, cell);
}


static inline MidiseqCell *Midiseq_get(Midiseq *midi, int index, Error *err)
{
    if (index < 0 || index >= Midiseq_len(midi)) {
        Error_format(err, "Index out of range (%d, %d)", index, Midiseq_len(midi));
        return NULL;
    }
    return midi->data+index;
}


bool Midiseq_pathsAllocated = false;
sds Midiseq_midiCsvExecPath = NULL;
sds Midiseq_csvMidiExecPath = NULL;
static void Midiseq_setMidicsvExecPath()
{
    if (!Midiseq_pathsAllocated) {
        const char *HOME = getenv("HOME");
        if (HOME == NULL) {
            post("Failed to find HOME variable");
            return;
        }
        Midiseq_midiCsvExecPath = sdscatprintf(sdsempty(), "%s/CeeSeq/Shared/midicsv-1.1/midicsv", HOME);
        Midiseq_csvMidiExecPath = sdscatprintf(sdsempty(), "%s/CeeSeq/Shared/midicsv-1.1/csvmidi", HOME);
        Midiseq_pathsAllocated = true;
    }

}

void Midiseq_dblog(Midiseq *midi)
{
    dblog("Midiseq %p", midi);
    for (int i = 0; i < Midiseq_len(midi); i++) {
        MidiseqCell cell = midi->data[i];
        switch (MidiseqCell_type(cell)) {
            case Midiseq_notetype:
                dblog("    %15lld note %15ld %15ld %15ld", MidiseqCell_t(cell),
                    (long)MidiseqCell_notePitch(cell), (long)MidiseqCell_noteVelocity(cell), (long)MidiseqCell_noteDuration(cell));
                break;
            case Midiseq_bendtype:
                dblog("    %15lld bend", MidiseqCell_t(cell));
                break;
            case Midiseq_cctype:
                dblog("    %15lld cc", MidiseqCell_t(cell));
                break;
            case Midiseq_endgrptype:
                dblog("    %15lld endgroup", MidiseqCell_t(cell));
                break;
            case Midiseq_cycletype:
                dblog("    %15lld cycle", MidiseqCell_t(cell));
                break;
        }
    }
    return;
}

//
// P A T C H E R    F I N D
//
long PortFind_iterator(PortFind *pf, t_object *targetBox)
{
    t_object *obj = jbox_get_object(targetBox);
    if (gensym("Port") != object_classname(obj)) {
        return 0;
    }

    t_symbol *varname = object_attr_getsym(targetBox, gensym("varname"));
    if (varname == NULL) {
        varname = gensym("unknown");
    }


    PortFindCell pfc = {0};
    pfc.reciever        = (Port*)obj;
    pfc.varname         = varname;
    sb_push(pf->objectsFound, pfc);
    return 0;
}


int PortFind_discover(PortFind *pf, t_object *sourceMaxObject, Error *err)
{
    t_object *patcher = NULL;
    long result       = 0;
    t_max_err maxErr = object_obex_lookup(sourceMaxObject, gensym("#P"), &patcher);
    if (maxErr != MAX_ERR_NONE) {
        Error_format(err, "Failed object_obex_lookup (%s)", Error_maxErrToString(maxErr));
        return 0;
    }
    object_method(patcher, gensym("iterate"), PortFind_iterator, (void *)pf, PI_WANTBOX | PI_DEEP, &result);
    return 0;
}


#define PortFind_declare(name) PortFind _##name = {0}; PortFind *name = &_##name
void PortFind_clear(PortFind *pf)
{
    sb_free(pf->objectsFound);
    pf->objectsFound = NULL;
}


Port *PortFind_findByVarname(PortFind *pf, t_symbol *symbol)
{
    for (int i = 0; i < sb_count(pf->objectsFound); i++) {
        PortFindCell *pfc = pf->objectsFound + i;
        if (pfc->varname == symbol) {
            return pfc->reciever;
        }
    }
    return Port_null;
}

Port *PortFind_findByTrack(PortFind *pf, t_symbol *symbol)
{
    for (int i = 0; i < sb_count(pf->objectsFound); i++) {
        PortFindCell *pfc = pf->objectsFound + i;
        if (pfc->reciever->track == symbol) {
            return pfc->reciever;
        }
    }
    return Port_null;   
}

Port *PortFind_findByType(PortFind *pf, t_symbol *symbol)
{
    for (int i = 0; i < sb_count(pf->objectsFound); i++) {
        PortFindCell *pfc = pf->objectsFound + i;
        if (pfc->reciever->type == symbol) {
            return pfc->reciever;
        }
    }
    return Port_null;   
}

int PortFind_portCount(PortFind *pf) {
    return sb_count(pf->objectsFound);
}

Port *PortFind_findByIndex(PortFind *pf, int index, Error *err) {
    if (index < 0 || index >= PortFind_portCount(pf)) {
        Error_format(err, "Index out of range (%d, %d)", index, PortFind_portCount(pf));
        return Port_null;
    }
    return pf->objectsFound[index].reciever;
}
//
// F R O M     F I L E
//
int midiseq_tokenize(FILE *fd, int *nfields, sds **fields, Error *err)
{
    char line[Midiseq_maxLineLength] = "";
    char *flag = fgets(line, Midiseq_maxLineLength, fd);
    if (flag == NULL) {
        if (!feof(fd)) {
            Error_format0(err, "Bad IO");
            return 1;
        }
        return -1;
    }
    *fields = sdssplitlen(line, strlen(line), ",", 1, nfields);
    for (int i = 0; i < *nfields; i++) {
        (*fields)[i] = sdstrim((*fields)[i], " ");
    }
    return 0;
}


int Midiseq_assignLength(Midiseq *midi)
{
    const long ppqn = 480;
    const long measureLength = ppqn*4;
    if (Midiseq_len(midi) == 0) {
        midi->sequenceLength = measureLength;
        return 0;
    }

    long end = 0;
    for (int i = 0; i < sb_count(midi->data); i++) {
        long t = midi->data[i].t;
        if (midi->data[i].type == Midiseq_notetype) {
            t += midi->data[i].duration;
        }
        if (t > end) {
            end = t;
        }
    }

    midi->sequenceLength = (end/measureLength)*measureLength + (end % measureLength == 0 ? 0 : measureLength);
    return 0;
}


int Midiseq_insertCell(Midiseq *midi, MidiseqCell cell, int index, Error *err)
{
    if (index < 0 || index > Midiseq_len(midi)) {
        Error_format(err, "Index out of range (%d, %d)", index, Midiseq_len(midi));
        return 1;
    }

    sb_add(midi->data, 1);
    if (Midiseq_len(midi) == 1) {
        midi->data[0] = cell;
        return 0;
    }

    for (int i = Midiseq_len(midi)-2; i >= index; i--) {
        midi->data[i+1] = midi->data[i];
    }
    midi->data[index] = cell;
    return 0;
}


int Midiseq_insertEndgroup(Midiseq *midi, Error *err)
{
    MidiseqCell cell = {0};
    cell.type = Midiseq_endgrptype;

    for (int i = Midiseq_len(midi)-1; i >= 0; i--) {
        if (midi->data[i].type == Midiseq_notetype) {
            cell.t = midi->data[i].t;
            if (Midiseq_insertCell(midi, cell, i, err)) {
                return 1;
            }
            return 0;
        }
    }

    cell.t = midi->data[0].t;
    if (Midiseq_insertCell(midi, cell, 0, err)) {
        return 1;
    }

    return 0;
}


int Midiseq_start(Midiseq *midi, Ticks startTime, Ticks currentTime, bool useMasterClock, Error *err)
{
    if (startTime > currentTime) {
        Error_format0(err, "INTERNAL ERROR");
        return 1;
    }
    Ticks adj            = midi->sequenceLength*((currentTime-startTime)/midi->sequenceLength);
    midi->startTime      = startTime + adj;
    midi->useMasterClock = useMasterClock;
    midi->ptr            = 0;
    if (useMasterClock) {
        if (Midiseq_fastfwrd(midi, currentTime, err)) {
            return 1;
        }
    }
    return 0;
}


void Midiseq_stop(Midiseq *midi)
{
    midi->startTime = 0;
    return;
}


enum
{
    Midiseq_nextEventErrored  = 1,
    Midiseq_nextEventComplete = 2,
    Midiseq_nextEventContinue = 3,
    Midiseq_nextEventBreak    = 4,
};

// Midiseq_nextevent always writes the current cell into the cell pointer. If the event
// stored in cell happened before until, then (a) the sequence is advanced and (b) the
// function returns 1. Otherwise 0 is returned and the sequence is left alone.
static int Midiseq_nextevent(Midiseq *midi, Ticks until, MidiseqCell *cell, Error *err)
{
    if (midi->startTime == 0) {
        Error_format0(err, "Called nextevent on stoped sequence");
        return Midiseq_nextEventErrored;
    }
    if (midi->ptr >= Midiseq_len(midi)) {
        // This is the case when the entire sequence has been played, and this
        // is NOT a useMasterClock sequence. If useMasterClock is true midi->ptr should
        // never satisfy the if criterion.
        *cell = sb_last(midi->data);
        return Midiseq_nextEventComplete;
    }

    Ticks t = midi->data[midi->ptr].t + midi->startTime;
    Ticks diff = t-until >= 0 ? t-until : until-t;

    if ( (diff-1)/midi->sequenceLength > 0) {
        Error_format(err, "INTERNAL ERROR %lld %lld %lld", diff, midi->sequenceLength, diff/midi->sequenceLength);
        return Midiseq_nextEventErrored;
    }

    *cell = midi->data[midi->ptr];
    cell->t = t;
    if (t > until) {
        return Midiseq_nextEventBreak;
    }

    midi->ptr++;
    if (midi->ptr >= Midiseq_len(midi) && midi->useMasterClock) {
        midi->ptr        = 0;
        midi->startTime += midi->sequenceLength;
    }
    return Midiseq_nextEventContinue;
}


int Midiseq_fastfwrd(Midiseq *midi, long t, Error *err)
{
    if (midi->startTime == 0) {
        return 1;
    }

    for (int i = 0; i < Midiseq_len(midi); i++) {
        if (midi->data[i].t + midi->startTime >= t) {
            midi->ptr = i;
            return 0;
        }
    }

    midi->ptr = 0;
    return 0;
}


Midiseq *Midiseq_fromfile(const char *fullpath, Error *err)
{
    char tempfile[] = "/tmp/MidiseqMaxMSPXXXXXX";
    Midiseq *midi = (Midiseq*)sysmem_newptrclear(sizeof(Midiseq));
    sds buffer = sdsempty();
    FILE *fd = NULL;
    int nfields = 0;
    sds *fields = NULL;
    bool allOK = false;

    // Call midicsv. To do this we create a new destination file, then route our output to it
    int tempFd = mkstemp(tempfile);
    if (tempFd < 0) {
        Error_format0(err, "Failed to create temp file");
        goto END;
    }
    close(tempFd);

    buffer = sdscatprintf(buffer, "'%s' '%s' > '%s'", Midiseq_midiCsvExecPath, fullpath, tempfile);
    int exitCode = system(buffer);
    if (exitCode != 0) {
        Error_format(err, "Failed '%s' with exit code %d", buffer, exitCode);
        goto END;
    }

    // Open the result file and parse away
    fd = fopen(tempfile, "r");
    if (fd == NULL) {
        Error_format(err, "Failed to open temp file '%s'", tempfile);
        goto END;
    }

    int desiredPPQN = 480;
    float tickFactor = 1.0;

    // ons[i] holds the index-1 of the last note-on of pitch i. Or zero if there is no pending note-on
    int ons[128] = {0};
    int linenum = 0;
    while (true) {
        int q = midiseq_tokenize(fd, &nfields, &fields, err);
        if (q != 0) {
            if (Error_iserror(err)) {
                goto END;
            }
            break;
        }
        linenum++;

        if (nfields < 3) {
            Error_format(err, "Not enough fields in midicsv file '%s' line %d", tempfile, linenum);
            goto END;
        }

        MidiseqCell cell = {0};
        cell.t = (long)(tickFactor*convertInt(fields[1], err));
        if (Error_iserror(err)) {
            goto END;
        }

        const char *typ = fields[2];

        bool isOn = strcmp(typ, "Note_on_c") == 0;
        bool isOff = strcmp(typ, "Note_off_c") == 0;
        if ( isOn || isOff ) {
            if (nfields < 6) {
                Error_format(err, "Bad Note_on_c file '%s' line %d", tempfile, linenum);
                goto END;
            }
            long pitch    = convertInt(fields[4], err);
            long velocity = convertInt(fields[5], err);
            if (Error_iserror(err)) {
                goto END;
            }
            if (velocity == 0) {
                isOn = false;
                isOff = true;
            }

            if (isOn) {
                cell.type = Midiseq_notetype;
                cell.b.b[0]  = (uint8)pitch;
                cell.b.b[1]  = (uint8)velocity;
                if (ons[pitch] != 0) {
                    Error_format(err, "Found an unbalanced NOTE-ON: while working on` file '%s' line %d", tempfile, linenum);
                    goto END;
                }
                Midiseq_push(midi, cell);
                ons[pitch] = Midiseq_len(midi);
            }
            else {
                if (ons[pitch] == 0) {
                    Error_format(err, "Found an unmatched note-off: while working on` file '%s' line %d", tempfile, linenum);
                    goto END;
                }
                int index = ons[pitch]-1;
                if (index >= Midiseq_len(midi)) {
                    Error_format0(err, "INTERNAL ERROR");
                    goto END;
                }
                MidiseqCell *c = Midiseq_get(midi, index, err);
                if (Error_iserror(err)) {
                    goto END;
                }
                c->duration = cell.t - c->t;
                ons[pitch] = 0;
            }
        }
        else if (strcmp(typ, "Pitch_bend_c") == 0) {
            if (nfields < 5) {
                Error_format(err, "Bad Pitch_bend_c file '%s' line %d", tempfile, linenum);
                goto END;
            }
            long value = convertInt(fields[4], err);
            if (Error_iserror(err)) {
                goto END;
            }
            cell.type   = Midiseq_bendtype;
            cell.b.bend = value;
            Midiseq_push(midi, cell);
        }
        else if (strcmp(typ, "Control_c") == 0) {
            if (nfields < 5) {
                Error_format(err, "Bad Control_c file '%s' line %d", tempfile, linenum);
                goto END;
            }
            long cc = convertInt(fields[4], err);
            long val  = convertInt(fields[5], err);
            if (Error_iserror(err)) {
                goto END;
            }
            cell.type = Midiseq_cctype;
            cell.b.b[0]  = (uint8)cc;
            cell.b.b[1]  = (uint8)val;
            Midiseq_push(midi, cell);
        }
        else if (strcmp(typ, "Header") == 0) {
            if (nfields < 6) {
                Error_format(err, "Bad Header file '%s' line %d", tempfile, linenum);
                goto END;
            }
            long ppqn = convertInt(fields[5], err);
            if (Error_iserror(err)) {
                goto END;
            }
            tickFactor = (float)(desiredPPQN)/(float)(ppqn);
        }

        // Free anything left over from tokenization
        sdsfreesplitres(fields, nfields);
        fields = NULL;
        nfields = 0;
    }

    // Compute length and install cycle and end group
    Midiseq_assignLength(midi);
    MidiseqCell cycle = {0};
    cycle.t = midi->sequenceLength;
    cycle.type = Midiseq_cycletype;
    Midiseq_push(midi, cycle);
    if (Midiseq_insertEndgroup(midi, err)) {
        goto END;
    }
    allOK = true;

    END:
    if (buffer != NULL) {
        sdsfree(buffer);
    }
    if (fields != NULL) {
        sdsfreesplitres(fields, nfields);
    }
    if (fd != NULL) {
        fclose(fd);
    }
    unlink(tempfile);

    if (allOK) {
        return midi;
    }

    // Error state
    Midiseq_free(midi);
    return NULL;
}


//
// P A D
//
void Pad_init(Pad *pad)
{
    if (pad != NULL) {
        Pad p = {0};
        *pad = p;
        pad->sequence = Midiseq_new();
    }
}


void Pad_clear(Pad *pad)
{
    if (pad != NULL) {
        Midiseq_free(pad->sequence);
        Pad p = {0};
        *pad = p;
    }
}


#define Pad_chokeGroup(pad) (pad)->chokeGroup
#define Pad_trackName(pad)  (pad)->trackName
#define Pad_track(pad)      (pad)->track

static inline Midiseq *Pad_sequence(Pad *pad) {
    return pad->sequence;
}

void Pad_setSequence(Pad *pad, Midiseq *midi)
{
    Midiseq_free(Pad_sequence(pad));
    pad->sequence = midi;
}


//
// P A D   L I S T
//
PadList *PadList_new(int npads)
{
    PadList *llst = (PadList*)sysmem_newptrclear(sizeof(PadList));
    sb_add(llst->pads, npads);
    for (int i = 0; i < npads; i++) {
        Pad_init(llst->pads + i);
    }
    return llst;
}


void PadList_free(PadList *llst)
{
    if (llst != NULL) {
        for (int i = 0; i < sb_count(llst->pads); i++) {
            Pad_clear(llst->pads + i);
        }
        sb_free(llst->pads);
        sb_free(llst->running);
        sysmem_freeptr(llst);
    }
}


int PadList_play(PadList *llst, int index, Ticks startTime, Ticks currentTime, bool useMasterClock, Error *err)
{
    int padsLength = sb_count(llst->pads);
    if (index < 0 || index >= padsLength) {
        Error_format(err, "Index out of range (%d, %d)", index, padsLength);
        return 1;
    }
    Pad *nwPad = llst->pads + index;
    int runningLength = sb_count(llst->running);
    int chokeIndex  = -1;
    int insertIndex = -1;
    for (int i = 0; i < runningLength; i++) {
        Pad *p = llst->running[i];
        if (p == NULL) {
            if (insertIndex < 0) {
                insertIndex = i;
            }
            continue;
        }
        if (chokeIndex < 0 && Pad_chokeGroup(nwPad) != NULL && Pad_chokeGroup(nwPad) == Pad_chokeGroup(p)) {
            chokeIndex = i;
            if (insertIndex < 0) {
                insertIndex = i;
            }
        }

        if (insertIndex >= 0 && chokeIndex >= 0) {
            break;
        }
    }

    if (chokeIndex >= 0) {
        llst->running[chokeIndex] = NULL;
    }
    if (insertIndex < 0) {
        sb_add(llst->running, 1);
        insertIndex = sb_count(llst->running)-1;
    }
    llst->running[insertIndex] = nwPad;
    for (int i = runningLength-1; i >= 0; i--) {
        if (llst->running[i] == NULL) {
            sb_pop(llst->running);
        }
        else {
            break;
        }
    }

    return Midiseq_start(Pad_sequence(llst->running[insertIndex]), startTime, currentTime, false, err);
}


int PadList_runningLength(PadList *llst)
{
    return sb_count(llst->running);
}


Pad *PadList_runningPad(PadList *llst, int index, Error *err)
{
    if (index < 0 || index >= PadList_runningLength(llst)) {
        Error_format(err, "Index out of range (%d, %d)", index, PadList_runningLength(llst));
        return NULL;
    }
    return llst->running[index];
}


int PadList_padsLength(PadList *llst)
{
    return sb_count(llst->pads);
}


Pad *PadList_pad(PadList *llst, int index, Error *err)
{
    if (index < 0 || index >= sb_count(llst->pads)) {
        Error_format(err, "Index out of range (%d, %d)", index, sb_count(llst->pads));
        return NULL;
    }
    return llst->pads + index;
}

void PadList_assignTrack(PadList *llst, TrackList *tl) {
    for (int i = 0; i < sb_count(llst->pads); i++) {
        Pad *pad = llst->pads + i;
        Pad_track(pad) = TrackList_findTrackByName(tl, Pad_trackName(pad));
    }
}

//
// T R A C K
//

#define Track_noteManager(t) ((t)->noteManager)
#define Track_name(t) ((t)->name)

TrackList *TrackList_new(PortFind *pf) {
    Error_declare(err);
    Track *tl = NULL;
    {
        // Insert the null track at position 1 of the tracklist
        Track t = {0};
        t.name  = gensym("null");
        t.noteManager = NoteManager_new(Port_null);
        sb_push(tl, t);
    }

    for (int i = 0; i < PortFind_portCount(pf); i++) {
        // Notice I don't handle any error that occures. I assume none do since I bound findByIndex by portCount
        Port *p = PortFind_findByIndex(pf, i, err);
        Track t = {0};
        Track_name(&t)        = Port_track(p);
        Track_noteManager(&t) = NoteManager_new(p);
        sb_push(tl, t);
    }    

    Error_clear(err);
    return (TrackList*)tl;
}

void TrackList_free(TrackList *tl_in) {
    Track *tl = (Track*)tl_in;
    for (int i = 0; i < sb_count(tl); i++) {
        NoteManager_free(tl[i].noteManager);
    }
    sb_free(tl);
}

Track *TrackList_findTrackByName(TrackList *tl_in, t_symbol *name) {
    Track *tl = (Track*)tl_in;
    for (int i = 0; i < sb_count(tl); i++) {
        if (tl[i].name == name) {
            return tl + i;
        }
    }
    return tl + 0; // Always return the Null track if didn't find.
}

int TrackList_count(TrackList *tl_in) {
    Track *tl = (Track*)tl_in;
    return sb_count(tl);
}

Track *TrackList_findTrackByIndex(TrackList *tl_in, int index, Error *err) {
    Track *tl = (Track*)tl_in;
    if (index < 0 || index >= sb_count(tl)) {
        Error_format(err, "Index out of range (%d, %d)", index, sb_count(tl));
        return tl + 0;
    }
    return tl + index;
}
//
// N O T E    M A N A G E R
//

const int PendingNoteOff_nodepoolsize = 120;
static PendingNoteOff *PendingNoteOff_freelist = NULL;

// freecount is how many items are on the free list
static int PendingNoteOff_freecount = 0;

PendingNoteOff *PendingNoteOff_new() {
    if (PendingNoteOff_freecount <= 0) {
        for (int i = 0; i <  PendingNoteOff_nodepoolsize; i++) {
            PendingNoteOff *node = (PendingNoteOff*)sysmem_newptrclear(sizeof(PendingNoteOff));
            node->next = PendingNoteOff_freelist;
            PendingNoteOff_freelist = node;
            PendingNoteOff_freecount++;
        }    
    }
    PendingNoteOff *r = PendingNoteOff_freelist;
    PendingNoteOff_freelist = r->next;
    PendingNoteOff_freecount--;
    r->next = NULL;
    return r;
}

void PendingNoteOff_free(PendingNoteOff *node) {
    if (PendingNoteOff_freecount > PendingNoteOff_nodepoolsize) {
        sysmem_freeptr(node);
    } else {
        PendingNoteOff zero = {0};
        *node = zero;
        node->next = PendingNoteOff_freelist;
        PendingNoteOff_freelist = node;
        PendingNoteOff_freecount++;
    }
}

const int NoteManager_atomcount = 4;

NoteManager *NoteManager_new(Port *port) {
    NoteManager *nm = (NoteManager*)sysmem_newptrclear(sizeof(NoteManager));
    nm->atoms       = (t_atom*)sysmem_newptrclear(sizeof(t_atom) * NoteManager_atomcount);
    nm->output      = port;
    return nm;
}

void NoteManager_free(NoteManager *nm) {
    NoteManager zero = {0};
    sysmem_freeptr(nm->atoms);
    *nm = zero;
    sysmem_freeptr(nm);
}

void NoteManager_removePendingNoteOff(NoteManager *manager, PendingNoteOff *previous, PendingNoteOff *target) {
    PendingNoteOff *next = target->next;
    if (previous == NULL) {
        manager->pending = next;
    } else {
        previous->next   = next;
    }
    PendingNoteOff_free(target);
    return;
}

void NoteManager_insertPendingNoteOff(NoteManager *manager, PendingNoteOff *previous, PendingNoteOff *newNode) {
    if (previous == NULL) {
        newNode->next    = manager->pending;
        manager->pending = newNode;
    } else {
        newNode->next    = previous->next;
        previous->next   = newNode;
    }
    return;
}



// insert a note off, and remove any single pitch that is already there. Return true if a note-off was removed
bool NoteManager_insertNoteOff(NoteManager *manager, Ticks offTimestamp, int pitch) {
    PendingNoteOff *node = PendingNoteOff_new();
    node->pitch     = pitch;
    node->timestamp = offTimestamp;

    bool removedPitch    = false;
    bool insertedNode    = false;
    PendingNoteOff *p    = manager->pending;
    PendingNoteOff *last = NULL;
    while (p != NULL) {
        // Remove a pitch if it is present
        if (!removedPitch && p->pitch == pitch) {
            removedPitch = true;
            PendingNoteOff *n = p->next;
            NoteManager_removePendingNoteOff(manager, last, p);
            p = n;
            continue;
        } 

        // Add the pitch at the correct timestamp
        if (!insertedNode && p->timestamp > offTimestamp) {
            insertedNode = true;
            NoteManager_insertPendingNoteOff(manager, last, node);
            p = node;
        } 

        if (removedPitch && insertedNode) {
            break;
        }
        last = p;
        p    = p->next;    
    }
    if (!insertedNode) {
        NoteManager_insertPendingNoteOff(manager, last, node);
        
    }
    return removedPitch;
}


// This is 10010000 which is a note-on (1001), on channel 0 (0000)
const int NOTEON_COMMAND = 144;


void NoteManager_sendNoteOn(NoteManager *manager, int pitch, int velocity) {
    t_atom *av = manager->atoms;
    atom_setsym(av + 0, gensym("midievent"));
    atom_setlong(av + 1, NOTEON_COMMAND);
    atom_setlong(av + 2, pitch);
    atom_setlong(av + 3, velocity);
    Error_declare(err);
    Port_send(manager->output, 4, av, err);
    Error_maypost(err);
}

void NoteManager_flushOffs(NoteManager *manager) {
    PendingNoteOff *p = manager->pending;
    while (p != NULL) {
        NoteManager_sendNoteOn(manager, p->pitch, 0);
        PendingNoteOff *n = p;
        p = p->next;
        PendingNoteOff_free(n);
    }
    manager->pending = NULL;
}

void NoteManager_dblogPending(NoteManager *manager, Ticks current) {
    dblog("dbPending %lld:", current);
    PendingNoteOff *p = manager->pending;
    while (p != NULL) {
        dblog("  %lld %d", p->timestamp-current, p->pitch);
        p = p->next;
    }
}

Ticks NoteManager_scheduleOffs(NoteManager *manager, Ticks current) {
    while (manager->pending != NULL) {
        if (manager->pending->timestamp > current) {
            break;
        }
        NoteManager_sendNoteOn(manager, manager->pending->pitch, 0);  
        PendingNoteOff *n = manager->pending;
        manager->pending  = manager->pending->next;
        PendingNoteOff_free(n);
    }
    if (manager->pending != NULL) {
        return manager->pending->timestamp - current;
    } else {
        return -1;
    }
}

void NoteManager_midievent(NoteManager *manager, MidiseqCell cell) {
    if (MidiseqCell_type(cell) == Midiseq_notetype) {
        int pitch     = MidiseqCell_notePitch(cell);
        int velocity  = MidiseqCell_noteVelocity(cell);
        Ticks offtime = MidiseqCell_t(cell) + MidiseqCell_noteDuration(cell);

        if (NoteManager_insertNoteOff(manager, offtime, pitch)){
            NoteManager_sendNoteOn(manager, pitch, 0);
        }        
        NoteManager_sendNoteOn(manager, pitch, velocity);
    }
}








