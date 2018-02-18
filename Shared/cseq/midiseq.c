#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
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
const int Midiseq_maxLineLength = 1024;

// Create new empty midi sequence
#define Midiseq_newUninitialized() ((Midiseq*)sysmem_newptrclear(sizeof(Midiseq)))
Midiseq *Midiseq_new()
{
    Midiseq *midi = Midiseq_newUninitialized();
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

void Midiseq_toBinFile(Midiseq *mseq, BinFile *bf, Error *err) {
    BinFile_writeTag(bf, "midiseq", err);
    Error_returnVoidOnError(err);

    BinFile_writeBool(bf, Midiseq_useMasterClock(mseq), err);
    Error_returnVoidOnError(err);

    BinFile_writeTicks(bf, Midiseq_sequenceLength(mseq), err);
    Error_returnVoidOnError(err);

    BinFile_writeInteger(bf, sb_count(Midiseq_data(mseq)), err);
    Error_returnVoidOnError(err);

    BinFile_writeTag(bf, "midiseq_start_data", err);
    Error_returnVoidOnError(err);

    for (int i = 0; i < sb_count(Midiseq_data(mseq)); i++) {
        MidiseqCell cell = Midiseq_data(mseq)[i];
        if (fprintf(BinFile_stream(bf), " %u %u %lld", MidiseqCell_type(cell), MidiseqCell_bendValue(cell), MidiseqCell_t(cell)) < 0) {
            Error_format(err, "Midiseq_toBinFile failed at fprintf[1] while writing %s", BinFile_filename(bf));
            return;
        }

        if (MidiseqCell_type(cell) == Midiseq_notetype) {
            if (fprintf(BinFile_stream(bf), " %lld", MidiseqCell_noteDuration(cell)) < 0) {
                Error_format(err, "Midiseq_toBinFile failed at fprintf[2] while writing %s", BinFile_filename(bf));
                return;       
            }
        }
    }
    BinFile_writeTag(bf, "midiseq_end_data", err);
    Error_returnVoidOnError(err);
}


Midiseq *Midiseq_fromBinFile(BinFile *bf, Error *err) {
    Midiseq *mseq = Midiseq_newUninitialized();
    Midiseq_fromBinFileUnititialized(mseq, bf, err);
    if (Error_iserror(err)) {
        sysmem_freeptr(mseq);
        return NULL;
    }
    return mseq;
}

void Midiseq_fromBinFileUnititialized(Midiseq *mseq, BinFile *bf, Error *err) {
    BinFile_verifyTag(bf, "midiseq", err);
    Error_returnVoidOnError(err);

    Midiseq_useMasterClock(mseq) = BinFile_readBool(bf, err);
    Error_returnVoidOnError(err);

    Midiseq_sequenceLength(mseq) = BinFile_readTicks(bf,  err);
    Error_returnVoidOnError(err);

    long length = BinFile_readInteger(bf, err);
    Error_returnVoidOnError(err);

    BinFile_verifyTag(bf, "midiseq_start_data", err);
    Error_returnVoidOnError(err);

    MidiseqCell *data = NULL;
    sb_add(data, length);
    sb_clear(data);
    for (int i = 0; i < length; i++) {
        MidiseqCell cell = {0};
        unsigned int type = 0, bendVal = 0;
        if (fscanf(BinFile_stream(bf), " %u %u %lld", &type, &bendVal, &MidiseqCell_t(cell)) != 3) {
            Error_format(err, "Midiseq_fromBinFile failed at fscanf[1] while reading %s", BinFile_filename(bf));
            goto END;
        }
        MidiseqCell_type(cell)      = type;
        MidiseqCell_bendValue(cell) = bendVal;

        if (MidiseqCell_type(cell) == Midiseq_notetype) {
            if (fscanf(BinFile_stream(bf), " %lld", &MidiseqCell_noteDuration(cell)) != 1) {
                Error_format(err, "Midiseq_fromBinFile failed at fscanf[2] while reading %s", BinFile_filename(bf));
                goto END;
            }
        }
        data[i] = cell;
    }
    
    BinFile_verifyTag(bf, "midiseq_end_data", err);
    Error_gotoLabelOnError(err, END);

    Midiseq_data(mseq) = data;
    return;

  END:
    sb_free(data);
    return;
}

Midiseq *Midiseq_newNote(int pitch)
{
    Midiseq *midi = (Midiseq*)sysmem_newptrclear(sizeof(Midiseq));
    midi->sequenceLength = 480*4;

    MidiseqCell zero = {
        0
    }
    , cell = {
        0
    };

    MidiseqCell_t(cell)    = 0;
    MidiseqCell_type(cell) = Midiseq_endgrptype;
    sb_push(midi->data, cell);

    cell = zero;
    MidiseqCell_t(cell)            = 0;
    MidiseqCell_type(cell)         = Midiseq_notetype;
    MidiseqCell_notePitch(cell)    = pitch;
    MidiseqCell_noteVelocity(cell) = 90;
    MidiseqCell_noteDuration(cell) = 480;
    sb_push(midi->data, cell);

    cell                   = zero;
    MidiseqCell_t(cell)    = midi->sequenceLength;
    MidiseqCell_type(cell) = Midiseq_cycletype;
    sb_push(midi->data, cell);

    return midi;
}


void Midiseq_init(Midiseq *midi)
{
    if (midi != NULL) {
        Midiseq zero = {0};
        *midi = zero;
    }
}


void Midiseq_clear(Midiseq *midi)
{
    if (midi != NULL) {
        sb_free(midi->data);
        Midiseq zero = {0};
        *midi = zero;
    }
}


void Midiseq_free(Midiseq *midi)
{
    if (midi != NULL) {
        Midiseq_clear(midi);
        sysmem_freeptr(midi);
    }
}


int Midiseq_len(Midiseq *midi)
{
    // REMEMBER: because of cycle and endgroup, every midi sequence has at least 2 elements.
    return sb_count(midi->data);
}


void Midiseq_push(Midiseq *midi, MidiseqCell cell)
{
    sb_push(midi->data, cell);
}


MidiseqCell *Midiseq_get(Midiseq *midi, int index, Error *err)
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
void Midiseq_setMidicsvExecPath()
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
    Port *port          = (Port*)obj;
    pfc.reciever        = port;
    pfc.varname         = varname;
    sb_push(pf->objectsFound, pfc);

    Port_hub(port)              = PortFind_hub(pf);
    Port_anythingDispatch(port) = PortFind_anythingDispatch(pf);
    Port_intDispatch(port)      = PortFind_intDispatch(pf);

    return 0;
}


int PortFind_discover(PortFind *pf, t_object *sourceMaxObject, void *hub, Error *err)
{
    PortFind_hub(pf)              = hub;
    PortFind_anythingDispatch(pf) = Hub_anythingDispatch;
    PortFind_intDispatch(pf)      = Hub_intDispatch;

    t_object *patcher = NULL;
    long result       = 0;
    t_max_err maxErr = object_obex_lookup(sourceMaxObject, gensym("#P"), &patcher);
    if (maxErr != MAX_ERR_NONE) {
        Error_format(err, "Failed object_obex_lookup (%s)", Error_maxErrToString(maxErr));
        return 0;
    }
    object_method(patcher, gensym("iterate"), PortFind_iterator, (void *)pf, PI_WANTBOX | PI_DEEP, &result);

    PortFind_hub(pf)              = NULL;
    PortFind_anythingDispatch(pf) = NULL;
    PortFind_intDispatch(pf)      = NULL;

    return 0;
}

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


Port *PortFind_findById(PortFind *pf, t_symbol *symbol)
{
    for (int i = 0; i < sb_count(pf->objectsFound); i++) {
        PortFindCell *pfc = pf->objectsFound + i;
        if (Port_id(pfc->reciever) == symbol) {
            return pfc->reciever;
        }
    }
    return Port_null;
}


int PortFind_portCount(PortFind *pf)
{
    return sb_count(pf->objectsFound);
}


Port *PortFind_findByIndex(PortFind *pf, int index, Error *err)
{
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
int Midiseq_nextevent(Midiseq *midi, Ticks until, MidiseqCell *cell, Error *err)
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
Pad *Pad_new(){
    Pad *pad = Pad_newUninitialized();
    Pad_init(pad);
    return pad;
}

void Pad_init(Pad *pad)
{
    if (pad != NULL) {
        Pad p = {0};
        *pad = p;
        pad->sequence = Midiseq_new();
    }
}

void Pad_free(Pad *pad) {
    if (pad != NULL) {
        Pad_clear(pad);
        sysmem_freeptr(pad);
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



void Pad_setSequence(Pad *pad, Midiseq *midi)
{
    if (Pad_sequence(pad) != NULL) {
        Midiseq_free(Pad_sequence(pad));
    }
    pad->sequence = midi;
}

void Pad_toBinFile(Pad *pad, BinFile *bf, Error *err) {
    BinFile_writeSymbol(bf, Pad_chokeGroup(pad), err);
    Error_returnVoidOnError(err);

    BinFile_writeSymbol(bf, Pad_trackName(pad), err);
    Error_returnVoidOnError(err);    

    BinFile_writeInteger(bf, Pad_padIndex(pad), err);
    Error_returnVoidOnError(err);    

    Midiseq_toBinFile(Pad_sequence(pad), bf, err);
    Error_returnVoidOnError(err);
}

Pad *Pad_fromBinFile(BinFile *bf, Error *err) {
    Pad *pad = Pad_newUninitialized();
    Pad_fromBinFileUninitialized(pad, bf, err);
    if (Error_iserror(err)) {
        sysmem_freeptr(pad);
        return NULL;
    }
    return pad;
}

void Pad_fromBinFileUninitialized(Pad *pad, BinFile *bf, Error *err) {
    Pad_chokeGroup(pad) = BinFile_readSymbol(bf, err);
    Error_returnVoidOnError(err);
    
    Pad_trackName(pad) = BinFile_readSymbol(bf, err);
    Error_returnVoidOnError(err);

    Pad_padIndex(pad)  = BinFile_readInteger(bf, err);
    Error_returnVoidOnError(err);

    Pad_setSequence(pad, Midiseq_fromBinFile(bf, err));
    Error_returnVoidOnError(err);    
}


//
// P A D   L I S T
//
#define PadList_newUninitialized() (PadList*)sysmem_newptrclear(sizeof(PadList))

PadList *PadList_new(int npads)
{
    PadList *llst = PadList_newUninitialized();
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


int PadList_play(PadList *llst, int padIndex, Ticks startTime, Ticks currentTime, bool useMasterClock, Error *err)
{
    int padsLength = sb_count(llst->pads);
    if (padIndex < 0 || padIndex >= padsLength) {
        Error_format(err, "Index out of range (%d, %d)", padIndex, padsLength);
        return 1;
    }
    Pad *pad = llst->pads + padIndex;
    // Since we're starting to play, we just recieved a Note-on for this pad. Reset the pad
    Pad_inEndgroup(pad)         = false;
    Pad_noteReleasePending(pad) = true;

    // Now let's find a place to stick this pad into the running array
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
        if (chokeIndex < 0 && Pad_chokeGroup(pad) != NULL && Pad_chokeGroup(pad) == Pad_chokeGroup(p)) {
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
        // Remove choked Pad
        llst->running[chokeIndex] = NULL;
    }
    if (insertIndex < 0) {
        llst->running = sb_add(llst->running, 1);
        insertIndex = sb_count(llst->running)-1;
    }
    llst->running[insertIndex] = pad;
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


void PadList_markReleasePending(PadList *llst, int padIndex, bool pending, Error *err)
{
    if (padIndex < 0 || padIndex >= PadList_padsLength(llst)) {
        Error_format(err, "Index out of range (%d, %d)", padIndex, PadList_padsLength(llst));
        return;
    }
    Pad *pad = llst->pads + padIndex;
    Pad_noteReleasePending(pad) = pending;
    if (!pending) {
        // We recieved a note-off. So cancel any pending endgroups
        NoteManager_padNoteOff(Track_noteManager(Pad_track(pad)), padIndex);
    }
}


int PadList_runningLength(PadList *llst)
{
    return sb_count(llst->running);
}

// iterator always points at the same element that is saved in the pad argument. This is done so that the iterator
// is left in a state that can be sent to PadList_clearRunning.
bool PadList_iterateRunning(PadList *llst, PadListIterator *iterator, Pad **pad)
{
    *pad = NULL;
    if (iterator->index < -1) {
        return false;
    }
    while (iterator->index+1 < PadList_runningLength(llst)) {
        iterator->index++;
        *pad = llst->running[iterator->index];
        if (*pad != NULL) {
            return true;
        }

    }
    return false;
}


void PadList_clearRunning(PadList *llst, PadListIterator *iterator)
{
    if (iterator->index >= 0 && iterator->index < PadList_runningLength(llst)) {
        llst->running[iterator->index] = NULL;
    }
    return;
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


void PadList_assignTrack(PadList *llst, TrackList *tl)
{
    for (int i = 0; i < sb_count(llst->pads); i++) {
        Pad *pad = llst->pads + i;
        Pad_track(pad) = TrackList_findTrackByName(tl, Pad_trackName(pad));
    }
}

void PadList_toBinFile(PadList *llst, BinFile *bf, Error *err) {
    BinFile_writeTag(bf, "padlist_start", err);
    Error_returnVoidOnError(err);

    BinFile_writeInteger(bf, PadList_padsLength(llst), err);
    Error_returnVoidOnError(err);

    for (int i = 0; i < PadList_padsLength(llst); i++) {
        Pad *pad = PadList_pad(llst, i, err);
        Error_returnVoidOnError(err);

        Pad_toBinFile(pad, bf, err);
        Error_returnVoidOnError(err);                
    }

    BinFile_writeTag(bf, "padlist_end", err);
    Error_returnVoidOnError(err);
}

PadList *PadList_fromBinFile(BinFile *bf, Error *err) {
    PadList *llst = PadList_newUninitialized();
    PadList_fromBinFileUninitialized(llst, bf, err);
    if (Error_iserror(err)) {
        sysmem_freeptr(llst);
        return NULL;
    }
    return llst;
}

// Remember the rul is that if there is an error, the PadList passed in remains uninitialized.
void PadList_fromBinFileUninitialized(PadList *llst, BinFile *bf, Error *err) {
    BinFile_verifyTag(bf, "padlist_start", err);
    Error_returnVoidOnError(err);

    long len = BinFile_readInteger(bf, err);
    Error_returnVoidOnError(err);
            
    Pad *pads = NULL;
    sb_add(pads, len);
    sb_clear(pads);

    for (int i = 0; i < len; i++) {
        Pad_fromBinFileUninitialized(pads + i, bf, err);
        Error_returnVoidOnError(err);
    }
    BinFile_verifyTag(bf, "padlist_end", err);

    PadList_pads(llst) = pads;
    Error_returnVoidOnError(err);
}

//
// T R A C K
//

TrackList *TrackList_new(PortFind *pf)
{
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


void TrackList_free(TrackList *tl_in)
{
    Track *tl = (Track*)tl_in;
    for (int i = 0; i < sb_count(tl); i++) {
        NoteManager_free(tl[i].noteManager);
    }
    sb_free(tl);
}


Track *TrackList_findTrackByName(TrackList *tl_in, t_symbol *name)
{
    Track *tl = (Track*)tl_in;
    for (int i = 0; i < sb_count(tl); i++) {
        if (tl[i].name == name) {
            return tl + i;
        }
    }
    return tl + 0;                                // Always return the Null track if didn't find.
}


int TrackList_count(TrackList *tl_in)
{
    Track *tl = (Track*)tl_in;
    return sb_count(tl);
}


Track *TrackList_findTrackByIndex(TrackList *tl_in, int index, Error *err)
{
    Track *tl = (Track*)tl_in;
    if (index < 0 || index >= sb_count(tl)) {
        Error_format(err, "Index out of range (%d, %d)", index, sb_count(tl));
        return tl + 0;
    }
    return tl + index;
}

// NOTE: currently nothing is actually stored in the output file. The complete tracklist comes from a port find payload in the BinFile instance.
TrackList *TrackList_fromBinFile(BinFile *bf, Error *err)
{
    PortFind *pf = BinFile_portFindPayload(bf);
    if (pf == NULL) {
        Error_format0(err, "Expected portFindPayload on BinFile, but didn't see one");
        return NULL;
    }

    return TrackList_new(pf);
}

void TrackList_toBinFile(TrackList *tl, BinFile *bf, Error *err) {
    // NO-op since nothing in the tracklist is written to file.
}


//
// N O T E    M A N A G E R
//

const int PendingNoteOff_nodepoolsize = 120;
static PendingNoteOff *PendingNoteOff_freelist = NULL;

// freecount is how many items are on the free list
static int PendingNoteOff_freecount = 0;

PendingNoteOff *PendingNoteOff_new()
{
    if (PendingNoteOff_freecount <= 0) {
        for (int i = 0; i <  PendingNoteOff_nodepoolsize; i++) {
            PendingNoteOff *node = (PendingNoteOff*)sysmem_newptrclear(sizeof(PendingNoteOff));
            PendingNoteOff_next(node) = PendingNoteOff_freelist;
            PendingNoteOff_freelist = node;
            PendingNoteOff_freecount++;
        }
    }
    PendingNoteOff *r = PendingNoteOff_freelist;
    PendingNoteOff_freelist = PendingNoteOff_next(r);
    PendingNoteOff_freecount--;
    PendingNoteOff_next(r) = NULL;
    return r;
}


void PendingNoteOff_free(PendingNoteOff *node)
{
    if (PendingNoteOff_freecount > PendingNoteOff_nodepoolsize) {
        sysmem_freeptr(node);
    }
    else {
        PendingNoteOff zero = {0};
        *node = zero;
        PendingNoteOff_next(node) = PendingNoteOff_freelist;
        PendingNoteOff_freelist = node;
        PendingNoteOff_freecount++;
    }
}


bool PendingNoteOff_removePitch(PendingNoteOff **head, int pitch)
{
    // First remove the pitch from endgroups
    PendingNoteOff *p    = *head;
    PendingNoteOff *last = NULL;
    while (p != NULL) {
        if (PendingNoteOff_pitch(p) == pitch) {
            if (last == NULL) {
                *head = PendingNoteOff_next(p);
            }
            else {
                PendingNoteOff_next(last) = PendingNoteOff_next(p);
            }
            PendingNoteOff_free(p);
            return true;
        }
        last = p;
        p    = PendingNoteOff_next(p);
    }
    return false;
}


void PendingNoteOff_removePadIndexed(PendingNoteOff **head, int padIndex, int **pitchesRemoved)
{
    // First remove the pitch from endgroups
    sb_clear(*pitchesRemoved);
    PendingNoteOff *p    = *head;
    PendingNoteOff *last = NULL;
    while (p != NULL) {
        if (PendingNoteOff_padIndex(p) == padIndex) {
            sb_push(*pitchesRemoved, PendingNoteOff_pitch(p));
            PendingNoteOff *n = PendingNoteOff_next(p);
            if (last == NULL) {
                *head = n;
            }
            else {
                PendingNoteOff_next(last) = n;
            }
            PendingNoteOff_free(p);
            p = n;
            continue;
        }
        last = p;
        p    = PendingNoteOff_next(p);
    }
    return;
}


void PendingNoteOff_insertTimestamped(PendingNoteOff **head, int pitch, Ticks timestamp)
{
    PendingNoteOff *node = PendingNoteOff_new();
    PendingNoteOff_pitch(node)     = pitch;
    PendingNoteOff_timestamp(node) = timestamp;

    PendingNoteOff *p    = *head;
    PendingNoteOff *last = NULL;
    while (p != NULL) {
        if (PendingNoteOff_timestamp(p) > timestamp) {
            // This will make p point to the element AFTER node, and last be EITHER (a) the element BEFORE node, or (b) if last == NULL
            // than node will be the first (and only) element of the list
            break;
        }
        last = p;
        p    = PendingNoteOff_next(p);
    }

    if (last == NULL) {
        PendingNoteOff_next(node) = *head;
        *head                     = node;
    }
    else {
        PendingNoteOff_next(node) = p;
        PendingNoteOff_next(last) = node;
    }

    return;
}


void PendingNoteOff_insertPadIndexed(PendingNoteOff **head, int pitch, int padIndex)
{
    PendingNoteOff *node = PendingNoteOff_new();
    PendingNoteOff_pitch(node)     = pitch;
    PendingNoteOff_padIndex(node)  = padIndex;
    PendingNoteOff_next(node)      = *head;
    *head                          = node;
}


// pop the first element off the list
void PendingNoteOff_pop(PendingNoteOff **head)
{
    if (*head) {
        PendingNoteOff *n = *head;
        *head = PendingNoteOff_next(*head);
        PendingNoteOff_free(n);
    }
}


void PendingNoteOff_freeAll(PendingNoteOff *start)
{
    PendingNoteOff *p = start;
    while (p != NULL) {
        PendingNoteOff *n = p;
        p = PendingNoteOff_next(p);
        PendingNoteOff_free(n);
    }
}


const int NoteManager_atomcount = 4;

NoteManager *NoteManager_new(Port *port)
{
    NoteManager *nm = (NoteManager*)sysmem_newptrclear(sizeof(NoteManager));
    nm->atoms       = (t_atom*)sysmem_newptrclear(sizeof(t_atom) * NoteManager_atomcount);
    nm->output      = port;
    return nm;
}


void NoteManager_free(NoteManager *nm)
{
    PendingNoteOff_freeAll(NoteManager_pending(nm));
    sb_free(nm->removedPitches);
    sb_free(nm->pending);
    sb_free(nm->endgroups);
    NoteManager zero = {0};
    sysmem_freeptr(nm->atoms);
    *nm = zero;
    sysmem_freeptr(nm);
}


// insert a note off, and remove any single pitch that is already there. Return true if a note-off was removed
bool NoteManager_insertNoteOff(NoteManager *manager, Ticks timestamp, int pitch, int padIndexForEndgroup)
{
    bool removedPitch = PendingNoteOff_removePitch(&NoteManager_endgroups(manager), pitch);
    bool q            = PendingNoteOff_removePitch(&NoteManager_pending(manager),   pitch);
    removedPitch      = removedPitch || q;
    if (padIndexForEndgroup >= 0) {
        // Mark this pitch as endgroup
        PendingNoteOff_insertPadIndexed(&NoteManager_endgroups(manager), pitch, padIndexForEndgroup);
    }
    else {
        PendingNoteOff_insertTimestamped(&NoteManager_pending(manager), pitch, timestamp);
    }

    return removedPitch;
}


// This is 10010000 which is a note-on (1001), on channel 0 (0000)
const int NOTEON_COMMAND = 144;

void NoteManager_sendNoteOn(NoteManager *manager, int pitch, int velocity)
{
    t_atom *av = manager->atoms;
    atom_setsym(av + 0, gensym("midievent"));
    atom_setlong(av + 1, NOTEON_COMMAND);
    atom_setlong(av + 2, pitch);
    atom_setlong(av + 3, velocity);
    Error_declare(err);
    Port_send(manager->output, 4, av, err);
    Error_maypost(err);
}


void NoteManager_flushOffs(NoteManager *manager)
{
    PendingNoteOff *p = NoteManager_endgroups(manager);
    while (p != NULL) {
        NoteManager_sendNoteOn(manager, PendingNoteOff_pitch(p), 0);
        PendingNoteOff *n = p;
        p = PendingNoteOff_next(p);
        PendingNoteOff_free(n);
    }
    NoteManager_pending(manager) = NULL;

    p = NoteManager_pending(manager);
    while (p != NULL) {
        NoteManager_sendNoteOn(manager, PendingNoteOff_pitch(p), 0);
        PendingNoteOff *n = p;
        p = PendingNoteOff_next(p);
        PendingNoteOff_free(n);
    }
    NoteManager_pending(manager) = NULL;
}


void NoteManager_dblogPending(NoteManager *manager, Ticks current)
{
    dblog("dbPending %lld:", current);
    PendingNoteOff *p = NoteManager_pending(manager);
    while (p != NULL) {
        dblog("  %lld %d", PendingNoteOff_timestamp(p)-current, PendingNoteOff_pitch(p));
        p = PendingNoteOff_next(p);
    }
}


Ticks NoteManager_scheduleOffs(NoteManager *manager, Ticks current)
{
    while (NoteManager_pending(manager) != NULL) {
        if (PendingNoteOff_timestamp(NoteManager_pending(manager)) > current) {
            break;
        }
        NoteManager_sendNoteOn(manager, PendingNoteOff_pitch(NoteManager_pending(manager)), 0);
        PendingNoteOff_pop(&NoteManager_pending(manager));
    }
    if (NoteManager_pending(manager) != NULL) {
        return PendingNoteOff_timestamp(NoteManager_pending(manager)) - current;
    }
    else {
        return -1;
    }
}


// padIndexForEndgroup should be -1 if this cell is not in an endgroup
void NoteManager_midievent(NoteManager *manager, MidiseqCell cell, int padIndexForEndgroup)
{
    if (MidiseqCell_type(cell) == Midiseq_notetype) {
        int pitch     = MidiseqCell_notePitch(cell);
        int velocity  = MidiseqCell_noteVelocity(cell);
        Ticks offtime = MidiseqCell_t(cell) + MidiseqCell_noteDuration(cell);

        if (NoteManager_insertNoteOff(manager, offtime, pitch, padIndexForEndgroup)) {
            NoteManager_sendNoteOn(manager, pitch, 0);
        }
        NoteManager_sendNoteOn(manager, pitch, velocity);
    }
}


void NoteManager_padNoteOff(NoteManager *manager, int padIndex)
{
    PendingNoteOff_removePadIndexed(&NoteManager_endgroups(manager), padIndex, &manager->removedPitches);
    for (int i = 0; i < sb_count(manager->removedPitches); i++) {
        NoteManager_sendNoteOn(manager, manager->removedPitches[i], 0);
    }
}


//
// G U I
//
Gui *Gui_new(PortFind *pf)
{
    Gui *gui = (Gui*)sysmem_newptrclear(sizeof(Gui));
    Gui_init(gui, pf);
    return gui;
}

void Gui_init(Gui *gui, PortFind *pf) 
{
    Gui_currBank(gui)  = PortFind_findById(pf, gensym("currBank"));
    Gui_currFrame(gui) = PortFind_findById(pf, gensym("currFrame"));
    Gui_selBank(gui)   = PortFind_findById(pf, gensym("selBank"));
    Gui_selFrame(gui)  = PortFind_findById(pf, gensym("selFrame"));
    Gui_selPad(gui)    = PortFind_findById(pf, gensym("selPad"));
    t_atom a[2] = {{0}};
    Error_declare(err);
    atom_setsym(a+0,  gensym("cantchange"));
    atom_setlong(a+1, 1);
    Port_send(Gui_currBank(gui), 2, a, err);
    Error_maypost(err);
    Port_send(Gui_currFrame(gui), 2, a, err);
    Error_maypost(err);
    Port_send(Gui_selBank(gui), 2, a, err);
    Error_maypost(err);
    Port_send(Gui_selFrame(gui), 2, a, err);
    Error_maypost(err);
    Port_send(Gui_selPad(gui), 2, a, err);
    Error_maypost(err);
}

void Gui_setCurrentCoordinates(Gui *gui, int bank, int frame) 
{
    Port_sendInteger(Gui_currBank(gui),  (long)bank);
    Port_sendInteger(Gui_currFrame(gui), (long)frame);
}

void Gui_setSelectedCoordinates(Gui *gui, int bank, int frame, int pad) 
{
    Port_sendInteger(Gui_selBank(gui),  (long)bank);
    Port_sendInteger(Gui_selFrame(gui), (long)frame);  
    Port_sendInteger(Gui_selPad(gui), (long)pad);   
}

//
// H U B
//

#define Hub_newUninitialized() (Hub*)sysmem_newptrclear(sizeof(Hub))

Hub *Hub_new() {
    return Hub_newUninitialized();
}
void Hub_init(Hub *hub) {}

void Hub_free(Hub *hub) {
    PadList_free(Hub_padList(hub));
    TrackList_free(Hub_trackList(hub));
}

void Hub_incrementFrame(Hub *hub)
{
    if (Hub_frame(hub) >= (Hub_framesPerBank-1)) {
        return;
    }

    Hub_frame(hub)++;
    Gui_setCurrentCoordinates(Hub_gui(hub), Hub_bank(hub), Hub_frame(hub));
}


void Hub_decrementFrame(Hub *hub)
{
    if (Hub_frame(hub) <= 0) {
        return;
    }

    Hub_frame(hub)--;
    Gui_setCurrentCoordinates(Hub_gui(hub), Hub_bank(hub), Hub_frame(hub));
}


void Hub_selectNextPushedPad(Hub *hub)
{
    Hub_grabNextTappedPad(hub) = true;
}

void Hub_midiFileDrop(Hub *hub, t_atom *pathAtom) {
    Error_declare(err);
    if (pathAtom == NULL) {
        post("midiFileDrop requires at least 1 symbol argument");
        return;
    }
    t_symbol *path = atom_getsym(pathAtom);
    if (path == gensym("")) {
        post("midiFileDrop requires at least 1 symbol argument");
        return;
    }
    const char *colon = strchr(path->s_name, ':');
    if (colon == NULL) {
        post("midiFileDrop expected to find colon (:) in filename");
        return;
    }
    sds filename = sdsnew(colon+1);
    Midiseq *mseq = Midiseq_fromfile(filename, err);
    if (Error_iserror(err)) {
        post("midiFileDrop: %s", Error_message(err));
        Error_clear(err);
        return;
    }
    sdsfree(filename);
    Pad *pad = PadList_pad(Hub_padList(hub), Hub_selectedPad(hub), err);
    if (Error_iserror(err)) {
        post("midiFileDrop: %s", Error_message(err));
        Midiseq_free(mseq);
        Error_clear(err);
        return;
    }
    Pad_setSequence(pad, mseq);
}

void Hub_anythingDispatch(void *hub_in, struct Port_t *port, t_symbol *msg, long argc, t_atom *argv)
{
    Hub *hub = (Hub*)hub_in;
    if (msg == gensym("incrementFrame")) {
        Hub_incrementFrame(hub);
    }
    else if (msg == gensym("decrementFrame")) {
        Hub_decrementFrame(hub);
    }
    else if (msg == gensym("selectNextPushedPad")) {
        Hub_selectNextPushedPad(hub);
    } else if (msg == gensym("midiFileDrop")) {
        Hub_midiFileDrop(hub, (argc > 0 ? argv + 0 : NULL));
    }
}


void Hub_intDispatch(void *hub, struct Port_t *port, long value, long inlet)
{
    int ev = port_parseEvSymbol(Port_id(port));
    if (ev >= 0) {
        dblog("Ev sent to %d: inlet %ld", ev, inlet);
    }
}

void Hub_toBinFile(Hub *hub, BinFile *bf, Error *err) {
    BinFile_writeTag(bf, "hub_start", err);
    Error_returnVoidOnError(err);

    PadList_toBinFile(Hub_padList(hub), bf, err);
    Error_returnVoidOnError(err);

    TrackList_toBinFile(Hub_trackList(hub), bf, err);
    Error_returnVoidOnError(err);

    BinFile_writeTag(bf, "hub_end", err);    
    Error_returnVoidOnError(err);
}

Hub *Hub_fromBinFile(BinFile *bf, Error *err) {
    Hub *hub = Hub_newUninitialized();
    Hub_fromBinFileUninitialized(hub, bf, err);
    if (Error_iserror(err)) {
        Hub_free(hub);
        return NULL;
    }
    return hub;
}

void Hub_fromBinFileUninitialized(Hub *hub, BinFile *bf, Error *err) {
    BinFile_verifyTag(bf, "hub_start", err);
    Error_returnVoidOnError(err);

    Hub_padList(hub) = PadList_fromBinFile(bf, err);
    Error_returnVoidOnError(err);
    
    Hub_trackList(hub) = TrackList_fromBinFile(bf, err);
    Error_returnVoidOnError(err);

    BinFile_verifyTag(bf, "hub_end", err);    
    Error_returnVoidOnError(err);
}


//
// B I N    F I L E
//

BinFile *BinFile_new() {
    BinFile *bf = (BinFile*)sysmem_newptrclear(sizeof(BinFile));
    BinFile_filename(bf) = sdsempty();
    BinFile_buffer(bf)   = sdsempty();
    return bf;
}

BinFile *BinFile_newWriter(const char *file, Error *err) {
    BinFile *bf =  BinFile_new();
    BinFile_stream(bf) = fopen(file, "w");
    if (BinFile_stream(bf) == NULL) {
        Error_format(err, "Failed to open file %s", file);
        BinFile_free(bf);
        return NULL;
    }
    sdsfree(BinFile_filename(bf));
    BinFile_filename(bf) = sdsnew(file);

    if (fprintf(BinFile_stream(bf), "%d ", BinFile_version(bf)) < 0) {
        Error_format(err, "Failed to write version number to file %s", file);
        BinFile_free(bf);
        return NULL;
    }

    return bf;
}

BinFile *BinFile_newReader(const char *file, Error *err) {
    BinFile *bf =  BinFile_new();
    BinFile_stream(bf) = fopen(file, "r");
    if (BinFile_stream(bf) == NULL) {
        Error_format(err, "Failed to open file %s", file);
        BinFile_free(bf);
        return NULL;
    }
    BinFile_filename(bf) = sdsnew(file);
    if (fscanf(BinFile_stream(bf), "%d ", &BinFile_version(bf))) {
        Error_format(err, "Failed to read version number from file  %s", file);
        BinFile_free(bf);
        return NULL;
    }
    return bf;
}

void BinFile_free(BinFile *bf) {
    if (BinFile_stream(bf) != NULL) {
        fclose(BinFile_stream(bf));
        BinFile_stream(bf) = NULL;
    }
    
    sdsfree(BinFile_filename(bf));
    BinFile_filename(bf) = NULL;
    sdsfree(BinFile_buffer(bf));
    BinFile_buffer(bf) = NULL;
    sysmem_freeptr(bf);
}

int binFile_hexDigitToInt(char hex) {
    switch (hex) {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        case 'a': return 10;
        case 'b': return 11;
        case 'c': return 12;
        case 'd': return 13;
        case 'e': return 14;
        case 'f': return 15;
    }
    return 0;
}
char binFile_intToHexDigit(int digit) {
    switch (digit) {
        case 0: return '0';
        case 1: return '1';
        case 2: return '2';
        case 3: return '3';
        case 4: return '4';
        case 5: return '5';
        case 6: return '6';
        case 7: return '7';
        case 8: return '8';
        case 9: return '9';
        case 10: return 'a';
        case 11: return 'b';
        case 12: return 'c';
        case 13: return 'd';
        case 14: return 'e';
        case 15: return 'f';
    }
    return 0;
}

off_t BinFile_writeNullLength(BinFile *bf, bool spaceForFlags, Error *err) {
    errno = 0;
    off_t start = BinFile_tell(bf, err);
    Error_returnZeroOnError(err);

    const char *format = ("%" BinFile_nullLengthFieldSizeStr "s ");
    if (fprintf(BinFile_stream(bf), format, "") < 0) {
        Error_format(err, "Failed fprintf while writing %s", BinFile_filename(bf));
        return 0;
    }
    if (spaceForFlags) {
        if (fprintf(BinFile_stream(bf), "0000 ") < 0) {
            Error_format(err, "Failed fprintf while writing %s", BinFile_filename(bf));
            return 0;
        }
    }
    return start;
} 

void BinFile_writeFlags(BinFile *bf, long flags, Error *err) {
    char hex[4] = {
        binFile_intToHexDigit((flags)       & 0xFF),
        binFile_intToHexDigit((flags >> 8)  & 0xFF),
        binFile_intToHexDigit((flags >> 16) & 0xFF),
        binFile_intToHexDigit((flags >> 24) & 0xFF),
    };
    if (fprintf(BinFile_stream(bf), "%c%c%c%c ", hex[0], hex[1], hex[2], hex[3]) < 0) {
        Error_format(err, "Failed fprintf while writing %s", BinFile_filename(bf));
        return;
    }
}

void BinFile_writeBackLengthFlags(BinFile *bf, off_t location, long flags, Error *err) {
    off_t end = BinFile_tell(bf, err);
    Error_returnVoidOnError(err);

    long length = (long)(end-location);
    if (length > BinFile_maxLength) {
        Error_format(err, "Length is too large (%ld) while writing %s", length, BinFile_filename(bf));
        return;
    }
    if (fseeko(BinFile_stream(bf), location, SEEK_SET) != 0){
        Error_format(err, "Failed fseeko[1] while writing %s", BinFile_filename(bf));
        return;
    }

    if (flags >= 0) {
        length = -length;
    }

    const char *format = ("%" BinFile_nullLengthFieldSizeStr "ld ");
    if (fprintf(BinFile_stream(bf), format, length) < 0) {
        Error_format(err, "Failed fprintf while writing %s", BinFile_filename(bf));
        return;
    }

    if (flags >= 0) {
        BinFile_writeFlags(bf, flags, err);
    }

    if (fseeko(BinFile_stream(bf), end, SEEK_SET) != 0){
        Error_format(err, "Failed fseeko[2] while writing %s", BinFile_filename(bf));
        return;
    }
    
    return;
}

void BinFile_writeLengthFlags(BinFile *bf, long length, long flags, Error *err) {
    if (length > BinFile_maxLength) {
        Error_format(err, "Length is too large (%ld) while writing %s", length, BinFile_filename(bf));
        return;
    }
    if (flags >= 0) {
        length = -length;
    }
    if (fprintf(BinFile_stream(bf), "%ld ", length) < 0) {
        Error_format(err, "Failed fprintf while writing %s", BinFile_filename(bf));
        return;
    }
    if (flags >= 0) {
        BinFile_writeFlags(bf, flags, err);
    }

}

long BinFile_readLengthFlags(BinFile *bf, long *flags, Error *err) {
    long length;
    char space;
    if (fscanf(BinFile_stream(bf), " %ld%c", &length, &space) != 2 || space != ' ') {
        Error_format(err, "Failed sscanf[1] while reading %s", BinFile_filename(bf));
        return 0;   
    }
    if (length < 0) {
        length = -length;
        char f[4] = "\0\0\0\0";
        if (fscanf(BinFile_stream(bf), "%c%c%c%c%c", f+0, f+1, f+2, f+3, &space) != 5 || space != ' ') {
            Error_format(err, "Failed sscanf[2] while reading %s", BinFile_filename(bf));
            return 0;   
        }   
        if (flags != NULL) {
            *flags = 0;
            for (int i = 0; i < 4; i++) {
                int v = binFile_hexDigitToInt(f[i]) << i*8;
                *flags = *flags | v;
            }
        }
    }
    return length;
}

off_t BinFile_tell(BinFile *bf, Error *err) {
    errno = 0;
    off_t location = ftello(BinFile_stream(bf));
    if (errno != 0) {
        Error_format(err, "Failed ftello while working with %s", BinFile_filename(bf));
        return 0;
    }
    return location;
}

void BinFile_fillBuffer(BinFile *bf, long size, Error *err) {
    // Want buffer to contain size+1 characters INCLUDING the null byte
    if (sdslen(BinFile_buffer(bf)) < size) {
        // NOTE: I verified that this call DOES NOT shrink the buffer.
        // NOTE: sdsMakeRoomFor always allocates sdslen()+1 bytes  
        BinFile_buffer(bf) = sdsgrowzero(BinFile_buffer(bf), (size_t)size);
    }
    sdssetlen(BinFile_buffer(bf), size);
    if (fread(BinFile_buffer(bf), size, 1, BinFile_stream(bf)) != size) {
        Error_format(err, "Failed fread while working with %s", BinFile_filename(bf));
        return;   
    }
    // NOTE: this means that the buffer can be used like a string in the correct context. IT DOES NOT say that there aren't
    // other nulls embedded in the string. I think that the way I'm preparing this string, there might be 2 nulls at the end
    // of it. 
    BinFile_buffer(bf)[size] = '\0';
}

void BinFile_writeInteger(BinFile *bf, long value, Error *err) {
    sdsclear(BinFile_buffer(bf));
    sdscatprintf(BinFile_buffer(bf), "%ld", value);
    
    BinFile_writeLength(bf, sdslen(BinFile_buffer(bf)), err);
    Error_returnVoidOnError(err);

    if (fwrite(BinFile_buffer(bf), sdslen(BinFile_buffer(bf)), 0, BinFile_stream(bf)) != sdslen(BinFile_buffer(bf))) {
        Error_format(err, "Failed fwrite while writing %s", BinFile_filename(bf));
        return;
    }
}

long BinFile_readInteger(BinFile *bf, Error *err) {
    long length = BinFile_readLength(bf, err);
    Error_returnZeroOnError(err);
    
    BinFile_fillBuffer(bf, length, err);
    Error_returnZeroOnError(err);
    
    long value = 0;
    if (sscanf(BinFile_buffer(bf), "%ld", &value) != 1) {
        Error_format(err, "Failed sscanf while reading %s", BinFile_filename(bf));
        return 0;
    }
    return value;
}

void BinFile_writeString(BinFile *bf, sds value, Error *err) {
    BinFile_writeLength(bf, sdslen(value), err);
    Error_returnVoidOnError(err);

    if (fwrite(BinFile_buffer(bf), sdslen(BinFile_buffer(bf)), 1, BinFile_stream(bf)) != sdslen(BinFile_buffer(bf))) {
        Error_format(err, "Failed fprintf while writing %s", BinFile_filename(bf));
        return;
    }

}

// must call sdsfree on any non-NULL return value
sds BinFile_readString(BinFile *bf, Error *err) {
    uint32_t length = BinFile_readLength(bf, err);
    Error_returnNullOnError(err);

    BinFile_fillBuffer(bf, length, err);
    Error_returnNullOnError(err);    
    
    return sdsdup(BinFile_buffer(bf));
}

void BinFile_writeSymbol(BinFile *bf, t_symbol *value, Error *err) {
    BinFile_writeString(bf, value->s_name, err);
    return;
}

t_symbol *BinFile_readSymbol(BinFile *bf, Error *err) {
    long length = BinFile_readLength(bf, err);
    Error_returnNullOnError(err);

    BinFile_fillBuffer(bf, length, err);
    Error_returnNullOnError(err);
    
    return gensym(BinFile_buffer(bf));
}

void BinFile_writeTicks(BinFile *bf, Ticks value, Error *err) {
    sdsclear(BinFile_buffer(bf));
    sdscatprintf(BinFile_buffer(bf), "%lld", value);

    BinFile_writeLength(bf, sdslen(BinFile_buffer(bf)), err);
    Error_returnVoidOnError(err);

    if (fwrite(BinFile_buffer(bf), sdslen(BinFile_buffer(bf)), 1, BinFile_stream(bf)) != sdslen(BinFile_buffer(bf))) {
        Error_format(err, "Failed fprintf while writing %s", BinFile_filename(bf));
        return;
    }
}

Ticks BinFile_readTicks(BinFile *bf, Error *err) {
    uint32_t length = BinFile_readLength(bf, err);
    Error_returnZeroOnError(err);
    
    BinFile_fillBuffer(bf, length, err);
    Error_returnZeroOnError(err);
    
    Ticks value = 0;
    if (sscanf(BinFile_buffer(bf), "%lld", &value) != 1) {
        Error_format(err, "Failed sscanf while reading %s", BinFile_filename(bf));
        return 0;
    }
    return value;
}

void BinFile_writeBool(BinFile *bf, bool value, Error *err) {
    BinFile_writeInteger(bf, value ? 1 : 0, err);
}

bool BinFile_readBool(BinFile *bf, Error *err) {
    return BinFile_readInteger(bf, err) ? true : false;
}

void BinFile_writeTag(BinFile *bf, const char *tag, Error *err) {
    int len = strlen(tag);
    BinFile_writeLengthFlags(bf, len, BinFileFlag_tag, err);
    Error_returnVoidOnError(err);

    if (fwrite(tag, len, 1, BinFile_stream(bf)) != len) {
        Error_format(err, "Failed fwrite while writing %s", BinFile_filename(bf));
        return;
    }
}

void BinFile_verifyTag(BinFile *bf, const char *tag, Error *err) {
    long flags  = 0;
    long length = BinFile_readLengthFlags(bf, &flags, err);
    Error_returnVoidOnError(err);
    if (flags & BinFileFlag_tag) {
        Error_format0(err, "Expected flag marked with BinFileFlag_tag");
        return;
    }
    BinFile_fillBuffer(bf, length, err);
    if (strcmp(tag, BinFile_buffer(bf)) != 0) {
        Error_format(err, "Expected tag '%s', but found '%s'", tag, BinFile_buffer(bf));
        return;
    }
    return;
}





