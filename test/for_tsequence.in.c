

APIF Port *Port_newTrackId(Symbol *track, Symbol *id)
{
	Port *self = Mem_calloc(sizeof(Port));
	self->obj.utilityPointer = AtomArAr_new(0);
	self->track              = track;
	self->id                 = id;
	return self;
}

APIF void Port_free(Port *self)
{
	if (self->obj.utilityPointer != NULL) {
		AtomArAr_free(self->obj.utilityPointer);
	}
	Mem_free(self);
}

APIF PortFind *PortFind_newFromTable(int argc, PortFindCell *cells)
{
    PortFind *self = PortFind_new();
    for (int i = 0; i < argc; i++) {
        PortFindCellAr_push(&self->objects, cells[i]);       
    }
    return self;
}

APIF PortFind *PortFind_createStandardSpoof(void)
{
	const int ncells = 3;
	Coverage_off;
	PortFindCell cells[ncells] = {
		{.reciever = Port_newTrackId(Symbol_gen("piano"),  Symbol_gen("idPiano")),  .varname = Symbol_gen("unknown")},
		{.reciever = Port_newTrackId(Symbol_gen("guitar"), Symbol_gen("idGuitar")), .varname = Symbol_gen("unknown")},
		{.reciever = Port_newTrackId(Symbol_gen("drums"),  Symbol_gen("idDrums")),  .varname = Symbol_gen("unknown")},
	};
	Coverage_on;
	return PortFind_newFromTable(ncells, cells);
}

APIF void PortFind_userClear(PortFind *self)
{
	PortFindCellAr_foreach(it, &self->objects) {
		Port_free(it.var->reciever);
	}
}

NoteEventAr *NoteOutlet_dbSent = NULL;

APIF void NoteOutlet_dbRewindSent() 
{
    if (NoteOutlet_dbSent != NULL) {
        NoteEventAr_truncate(NoteOutlet_dbSent);    
    }
}

APIF void NoteOutlet_dbRecordEvent(int pitch, int velocity) 
{
   	if (NoteOutlet_dbSent == NULL) {
        NoteOutlet_dbSent = NoteEventAr_new(0);
    }
    NoteEvent e = {.pitch = pitch, .velocity = velocity, .stime = Ticks_dbCurrent, .duration = 0};
    NoteEventAr_push(NoteOutlet_dbSent, e);
}
APIF void NoteOutlet_dbGetResults(NoteEventAr *arr)
{
	if (NoteOutlet_dbSent == NULL) {
		return;
	}
	NoteEventAr_truncate(arr);

	Ticks offTime[128] = {0};
	NoteEventAr_rforeach(it, NoteOutlet_dbSent) {
		if (it.var->velocity == 0) {
			offTime[it.var->pitch] = it.var->stime;
		} else {
			NoteEvent e = *it.var;
			e.duration  = offTime[e.pitch] - e.stime;
			NoteEventAr_push(arr, e);
		}
	}
	NoteOutlet_dbRewindSent();
}
