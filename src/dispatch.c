

APIF void MarshalSi_process(MarshalSi *self, Arguments *args, long argc, Atom *argv, Error *err)
{
   if (argc != 1) {
      Error_format(err, "MarshalSi expected 1 additional argument, found %d", (int)argc);
      return;
   }
   if (!Atom_isNumber(argv + 0)) {
      Error_format0(err, "MarshalSi second argument should be an integer");
      return;  
   }
   Arguments_setI1(args, Atom_toSymbol(argv + 0));
}

APIF void MarshalSi_zeroArgs(MarshalSi *self, Arguments *args) {
   Arguments_setI1(args, 0);
}

APIF void MarshalSii_process(MarshalSii *self, Arguments *args, long argc, Atom *argv, Error *err)
{
   if (argc != 2) {
      Error_format(err, "MarshalSii expected 2 additional arguments, found %d", (int)argc);
      return;
   }
   if (!Atom_isNumber(argv + 0)) {
      Error_format0(err, "MarshalSii second argument should be an integer");
      return;  
   }
   if (!Atom_isNumber(argv + 1)) {
      Error_format0(err, "MarshalSii third argument should be an integer");
      return;  
   }
   Arguments_setI1(args, Atom_toInteger(argv + 0));
   Arguments_setI2(args, Atom_toInteger(argv + 1));
}

APIF void MarshalSii_zeroArgs(MarshalSi *self, Arguments *args) {
   Arguments_setI1(args, 0);
   Arguments_setI2(args, 0);
}

APIF void MarshalSs_process(MarshalSs *self, Arguments *args, long argc, Atom *argv, Error *err)
{
   if (argc != 1) {
      Error_format(err, "MarshalSs expected 1 additional arguments, found %d", (int)argc);
      return;
   }
   if (!Atom_isSymbol(argv + 0)) {
      Error_format0(err, "MarshalSs second argument should be an symbol");
      return;  
   }
   Arguments_setS1(args, Atom_toSymbol(argv + 0));
}

APIF void MarshalSs_zeroArgs(MarshalSi *self, Arguments *args) {
   Arguments_setS1(args, NULL);
}

APIF Marshal *Marshal_create(int itype) {
   Marshal *self = (Marshal*)Mem_malloc(itype);
   self->itype = itype;
   return self;
}

APIF void Marshal_free(Marshal *self) {
   Mem_free(self);
}

APIF Dispatch *IncrementFrameDispatch_create(int itype) {
   Dispatch *self = (Dispatch *)Mem_malloc(sizeof(Dispatch));
   memset(self, 0, sizeof(Dispatch));
   self->itype    = itype;
   self->selector = Symbol_gen("incrementFrame");
   self->portId   = Symbol_gen("guiBottom");
   self->inlet    = 0;
   self->marshal  = NULL;
   return self;
}

APIF void IncrementFrameDispatch_exec(IncrementFrameDispatch *self, Hub *hub, Arguments *args, Error *err) {
      if (Hub_frame(hub) >= (Hub_framesPerBank-1)) {
        return;
    }

    Hub_setFrame(hub, Hub_frame(hub)+1);
    Hub_updateGuiCurrentCoordinates(hub);
}

APIF Dispatch *DecrementFrameDispatch_create(int itype) {
   Dispatch *self = (Dispatch *)Mem_malloc(sizeof(Dispatch));
   memset(self, 0, sizeof(Dispatch));
   self->itype    = itype;
   self->selector = Symbol_gen("decrementFrame");
   self->portId   = Symbol_gen("guiBottom");
   self->inlet    = 0;
   self->marshal  = NULL;
   return self;
}

APIF void DecrementFrameDispatch_exec(DecrementFrameDispatch *self, Hub *hub, Arguments *args, Error *err) {
    if (Hub_frame(hub) <= 0) {
        return;
    }

    Hub_setFrame(hub, Hub_frame(hub)-1);
    Hub_updateGuiCurrentCoordinates(hub);
}


APIF Dispatch *SelectNextPushedPadDispatch_create(int itype) {
   Dispatch *self = (Dispatch *)Mem_malloc(sizeof(Dispatch));
   memset(self, 0, sizeof(Dispatch));
   self->itype    = itype;
   self->selector = Symbol_gen("selectNextPushedPad");
   self->portId   = Symbol_gen("guiBottom");
   self->inlet    = 0;
   self->marshal  = NULL;
   return self;
}

APIF void SelectNextPushedPadDispatch_exec(SelectNextPushedPadDispatch *self, Hub *hub, Arguments *args, Error *err) {
   Hub_setGrabNextTappedPad(hub, true);
}


APIF Dispatch *MidiFileDropDispatch_create(int itype) {
   Dispatch *self = (Dispatch *)Mem_malloc(sizeof(Dispatch));
   memset(self, 0, sizeof(Dispatch));
   self->itype    = itype;
   self->selector = Symbol_gen("midiFileDrop");
   self->portId   = Symbol_gen("guiBottom");
   self->inlet    = 0;
   self->marshal  = Marshal_create(MarshalSs_itype); 
   return self;
}

APIF void MidiFileDropDispatch_exec(MidiFileDropDispatch *self, Hub *hub, Arguments *args, Error *err) {
   Symbol *path = Arguments_s1(args);
   
   const char *colon = strchr(Symbol_cstr(path), ':');
   if (colon == NULL) {
     Error_format0(err, "midiFileDrop expected to find colon (:) in filename");
     return;
   }
   sds filename = sdsnew(colon+1);
   Midiseq *mseq = Midiseq_fromfile(filename, err);
   if (Error_iserror(err)) {
     return;
   }
   sdsfree(filename);
   Pad *pad = PadList_pad(Hub_padList(hub), Hub_selectedPad(hub), err);
   if (Error_iserror(err)) {
     Midiseq_free(mseq);
     return;
   }
   Pad_setSequence(pad, mseq);
}

APIF Dispatch *ManageChokeGroupsDispatch_create(int itype) {
   Dispatch *self = (Dispatch *)Mem_malloc(sizeof(Dispatch));
   memset(self, 0, sizeof(Dispatch));
   self->itype    = itype;
   self->selector = NULL;
   self->portId   = Symbol_gen("chokeGroup");
   self->inlet    = 0;
   self->marshal  = NULL;
   return self;
}

APIF void ManageChokeGroupsDispatch_initDispatchPtAr(int itype, DispatchPtAr *disPtAr, Error *ignored) {
   for (int i = 0; i < 3; i++) {
      Dispatch *dis = ManageChokeGroupsDispatch_create(itype);
      dis->inlet    = i;
      DispatchPtAr_push(disPtAr, dis);
   }
   return;
}

APIF void ManageChokeGroupsDispatch_exec(ManageChokeGroupsDispatch *self, Hub *hub, Arguments *args, Error *err) {
   Pad *pad   = PadList_pad(Hub_padList(hub), Hub_selectedPad(hub), err);
   long value = Arguments_ivalue(args);
   switch (self->inlet) {
      case 0:
         DropDown_setSelected(Hub_cgLocalGlobalMenu(hub), value, err);
         Error_returnVoidOnError(err);
         Pad_setChokeGroupGlobal(pad, value ? true : false);
         break;
      case 1:
         DropDown_setSelected(Hub_cgInstrumentMenu(hub), value, err);
         Error_returnVoidOnError(err);
         Pad_setChokeGroupInstrument(pad, value);
         break;
      case 2:
         DropDown_setSelected(Hub_cgIndexMenu(hub), value, err);
         Error_returnVoidOnError(err);
         Pad_setChokeGroupIndex(pad, value);
         break;
      default:
         Error_format(err, "INTERNAL ERROR: bad inlet %d", self->inlet);
         return;
   }
   Pad_computeChokeGroup(pad);
}

APIF int Dispatch_cmp(Dispatch **leftp, Dispatch **rightp) 
{
// #define s(x) (x!= NULL) ? Symbol_cstr(x) : "NONE"   
//    dblog("Hmmm %s %s %d | %s %s %d", s(left->selector), s(left->portId), left->inlet, s(right->selector), s(right->portId), right->inlet);
   Dispatch *left = *leftp;
   Dispatch *right = *rightp;
   if (left->selector < right->selector) {
      return -1;
   } else if (left->selector > right->selector) {
      return 1;
   } else if (left->portId < right->portId) {
      return -1;
   } else if (left->portId > right->portId) {
      return 1;
   } else if (left->inlet < right->inlet) {
      return -1;
   } else if (left->inlet > right->inlet) {
      return 1;
   }
   return 0;
}

APIF void Dispatch_freeDefault(Dispatch *d) {
   Marshal_free(d->marshal);
   Mem_free(d);
}

APIF void Dispatch_initDispatchPtArDefault(int itype, DispatchPtAr *disPtAr, Error *err) {
   Dispatch *dis = Dispatch_create(itype, err);
   Error_returnVoidOnError(err);
   DispatchPtAr_push(disPtAr, dis);
}

APIF void DispatchPtAr_populate(DispatchPtAr *self, Error *err) {
   DispatchPtAr_truncate(self);
   Dispatch_foreachIType(itype) {
      Dispatch_initDispatchPtAr(itype, self, err);
      Error_maypost(err);
   }
   DispatchPtAr_sort(self);
}

Dispatch *baz(int i) {
   return NULL;
}
int bar(int i) {
   return NULL;
}
Dispatch *foo(int i) {
   switch (i) {
      case 1:
         return baz(i);
      case 2:
         return bar(i);
      case 3:
         Dispatch *f = bar(i);
         // return f;
         return NULL;
   }
   return NULL;
}

void Marshal_process(Marshal *self, Arguments *a1, long a2, Atom *a3, Error *err)
{
    switch(self->itype) {
        case MarshalSi_itype:
            MarshalSi_process((MarshalSi*)self, a1, a2, a3, err);
            return;
        case MarshalSii_itype:
            MarshalSii_process((MarshalSii*)self, a1, a2, a3, err);
            return;
        case MarshalSs_itype:
            MarshalSs_process((MarshalSs*)self, a1, a2, a3, err);
            return;
       default:
            Error_format(err, "Failed to resolve interface call in MarshalSs_process: found type %s", Interface_toString(self->itype));
    }
    return;
}

void Marshal_zeroArgs(Marshal *self, Arguments *a1, Error *err)
{
    switch(self->itype) {
        case MarshalSi_itype:
            MarshalSi_zeroArgs((MarshalSi*)self, a1);
            return;
        case MarshalSii_itype:
            MarshalSii_zeroArgs((MarshalSii*)self, a1);
            return;
        case MarshalSs_itype:
            MarshalSs_zeroArgs((MarshalSs*)self, a1);
            return;
       default:
            Error_format(err, "Failed to resolve interface call in MarshalSs_zeroArgs: found type %s", Interface_toString(self->itype));
    }
    return;
}

void Dispatch_exec(Dispatch *self, Hub *a1, Arguments *a2, Error *err)
{
    switch(self->itype) {
        case DecrementFrameDispatch_itype:
            DecrementFrameDispatch_exec((DecrementFrameDispatch*)self, a1, a2, err);
            return;
        case IncrementFrameDispatch_itype:
            IncrementFrameDispatch_exec((IncrementFrameDispatch*)self, a1, a2, err);
            return;
        case ManageChokeGroupsDispatch_itype:
            ManageChokeGroupsDispatch_exec((ManageChokeGroupsDispatch*)self, a1, a2, err);
            return;
        case MidiFileDropDispatch_itype:
            MidiFileDropDispatch_exec((MidiFileDropDispatch*)self, a1, a2, err);
            return;
        case SelectNextPushedPadDispatch_itype:
            SelectNextPushedPadDispatch_exec((SelectNextPushedPadDispatch*)self, a1, a2, err);
            return;
       default:
            Error_format(err, "Failed to resolve interface call in SelectNextPushedPadDispatch_exec: found type %s", Interface_toString(self->itype));
    }
    return;
}

Dispatch *Dispatch_create(int itype, Error *err)
{
    switch(itype) {
        case DecrementFrameDispatch_itype:
            return DecrementFrameDispatch_create(itype);
        case IncrementFrameDispatch_itype:
            return IncrementFrameDispatch_create(itype);
        case ManageChokeGroupsDispatch_itype:
            return ManageChokeGroupsDispatch_create(itype);
        case MidiFileDropDispatch_itype:
            return MidiFileDropDispatch_create(itype);
        case SelectNextPushedPadDispatch_itype:
            return SelectNextPushedPadDispatch_create(itype);
        default:
            Error_format(err, "Failed to resolve interface call in SelectNextPushedPadDispatch_create: found type %s", Interface_toString(itype));
    }
    return NULL;
}

void Dispatch_free(Dispatch *self, Error *err)
{
    switch(self->itype) {
        case DecrementFrameDispatch_itype:
            Dispatch_freeDefault(self);
            return;
        case IncrementFrameDispatch_itype:
            Dispatch_freeDefault(self);
            return;
        case ManageChokeGroupsDispatch_itype:
            Dispatch_freeDefault(self);
            return;
        case MidiFileDropDispatch_itype:
            Dispatch_freeDefault(self);
            return;
        case SelectNextPushedPadDispatch_itype:
            Dispatch_freeDefault(self);
            return;
       default:
            Error_format(err, "Failed to resolve interface call in SelectNextPushedPadDispatch_free: found type %s", Interface_toString(self->itype));
    }
    return;
}

void Dispatch_initDispatchPtAr(int itype, DispatchPtAr *a1, Error *err)
{
    switch(itype) {
        case DecrementFrameDispatch_itype:
            Dispatch_initDispatchPtArDefault(itype, a1, err);
            return;
        case IncrementFrameDispatch_itype:
            Dispatch_initDispatchPtArDefault(itype, a1, err);
            return;
        case ManageChokeGroupsDispatch_itype:
            ManageChokeGroupsDispatch_initDispatchPtAr(itype, a1, err);
            return;
        case MidiFileDropDispatch_itype:
            Dispatch_initDispatchPtArDefault(itype, a1, err);
            return;
        case SelectNextPushedPadDispatch_itype:
            Dispatch_initDispatchPtArDefault(itype, a1, err);
            return;
       default:
            Error_format(err, "Failed to resolve interface call in SelectNextPushedPadDispatch_initDispatchPtAr: found type %s", Interface_toString(itype));
    }
    return;
}
