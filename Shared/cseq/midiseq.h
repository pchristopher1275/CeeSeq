sds stripBaseName(const char *path);
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef struct
{
    uint8 type;
    union
    {
        uint8 b[2];
        uint16 bend;
    } b;
    Ticks t;
    Ticks duration;
} MidiseqCell;

typedef struct
{
    MidiseqCell *data;                            // This is an stretchy_buffer
    int ptr;
    bool useMasterClock;

    Ticks sequenceLength;

    // startTime is the time offset that t = 0 that is stored in the sequence corresponds too.
    // Specifically, if useMasterClock is true, the startTime is updated whenever the ptr rolls
    // off the end of the sequence, and raps around back to the beginning.
    Ticks startTime;
} Midiseq;

int Midiseq_fastfwrd(Midiseq *midi, long t, Error *err);

typedef struct
{
    t_symbol *chokeGroup;
    Midiseq *sequence;
} Pad;

typedef struct PendingNoteOff_t 
{
    struct PendingNoteOff_t *next;
    Ticks timestamp;
    int pitch;
} PendingNoteOff;

typedef struct 
{
    PendingNoteOff *pending;
    Port *output;
    t_atom *atoms;
} NoteManager;

typedef struct
{
    Port *reciever;
    t_symbol *varname;
    t_symbol *track;
    t_symbol *type;
} PortFindCell;

typedef struct
{
    PortFindCell *objectsFound;
} PortFind;

typedef struct
{
    Pad *pads;
    Pad **running;
} LiveList;