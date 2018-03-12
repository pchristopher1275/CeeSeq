

APIF void MarshalSi_process(MarshalSi *self, Arguments *args, long argc, Atom *argv, Error *err)
{
   if (argc != 1) {
      Error_format(err, "MarshalSi expected 1 additional argument, found %d", argc);
      return;
   }
   if (!Atom_isInteger(argv + 0)) {
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
      Error_format(err, "MarshalSii expected 2 additional arguments, found %d", argc);
      return;
   }
   if (!Atom_isInteger(argv + 0)) {
      Error_format0(err, "MarshalSii second argument should be an integer");
      return;  
   }
   if (!Atom_isInteger(argv + 1)) {
      Error_format0(err, "MarshalSii third argument should be an integer");
      return;  
   }
   Arguments_setI1(args, Atom_toInteger(argv + 0));
   Arguments_setI2(args, Atom_toInteger(argv + 1));
}

APIF void MarshalSi_zeroArgs(MarshalSi *self, Arguments *args) {
   Arguments_setI1(args, 0);
   Arguments_setI2(args, 0);
}

APIF void MarshalSs_process(MarshalSs *self, Arguments *args, long argc, Atom *argv, Error *err)
{
   if (argc != 1) {
      Error_format(err, "MarshalSs expected 1 additional arguments, found %d", argc);
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

APIF void Marshal_free(Marshal *self) {
   Mem_free(self);
}

APIF int DispatchBase_cmp(DispatchBase *left, DispatchBase *right) 
{
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

APIF void IncrementFrameDispatch_init(IncrementFrameDispatch *self) {
   self->selector = Symbol_gen("incrementFrame");
   self->portId   = Symbol_gen("guiBottom");
   self->inlet    = 0;
   self->marshal  = NULL;
}

APIF void IncrementFrameDispatch_exec(IncrementFrameDispatch *self, Hub *hub, Arguments *args, Error *err) {
      if (Hub_frame(hub) >= (Hub_framesPerBank-1)) {
        return;
    }

    Hub_setFrame(hub, Hub_frame(hub)+1);
    Hub_updateGuiCurrentCoordinates(hub);
}

APIF void DecrementFrameDispatch_init(DecrementFrameDispatch *self) {
   self->selector = Symbol_gen("decrementFrame");
   self->portId   = Symbol_gen("guiBottom");
   self->inlet    = 0;
   self->marshal  = NULL;
}

APIF void DecrementFrameDispatch_exec(DecrementFrameDispatch *self, Hub *hub, Arguments *args, Error *err) {
    if (Hub_frame(hub) <= 0) {
        return;
    }

    Hub_setFrame(hub, Hub_frame(hub)-1);
    Hub_updateGuiCurrentCoordinates(hub);
}


APIF void SelectNextPushedPadDispatch_init(SelectNextPushedPadDispatch *self) {
   self->selector = Symbol_gen("selectNextPushedPad");
   self->portId   = Symbol_gen("guiBottom");
   self->inlet    = 0;
   self->marshal  = NULL;
}

APIF void SelectNextPushedPadDispatch_exec(SelectNextPushedPadDispatch *self, Hub *hub, Arguments *args, Error *err) {
   Hub_setGrabNextTappedPad(hub, true);
}


APIF void MidiFileDropDispatch_init(MidiFileDropDispatch *self) {
   self->selector = Symbol_gen("midiFileDrop");
   self->portId   = Symbol_gen("guiBottom");
   self->inlet    = 0;
   Error_declare(err);
   self->marshal  = MarshalSs_newUnititialized(); 
   Error_maypost(err);
}

APIF void MidiFileDropDispatch_exec(MidiFileDropDispatch *self, Hub *hub, Arguments *args, Error *err) {
   Symbol *path = Arguments_s1(args);
   
   const char *colon = strchr(Symbol_cstr(path), ':');
   if (colon == NULL) {
     Error_format0("midiFileDrop expected to find colon (:) in filename");
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

APIF void MidiFileDropDispatch_clear(MidiFileDropDispatch *self) {
   Marshal_free(self->marshal);
   self->marshal = NULL;
}

APIF int ManageChokeGroupsDispatch_initDispatchPtAr(ManageChokeGroupsDispatch *self, DispatchPtAr *disPtAr) {
   for (int i = 0; i < 3; i++) {
      ManageChokeGroupsDispatch *mcg = ManageChokeGroupsDispatch_newUnitialized();
      mcg->selector = NULL;
      mcg->portId   = Symbol_gen("chokeGroup")
      mcg->inlet    = i;
      mcg->marshal  = NULL;
      DispatchPtAr_push(disPtAr, ManageChokeGroupsDispatch_castToDispatch(mcg));
   }
   return 1;
}

APIF void ManageChokeGroupsDispatch_exec(ManageChokeGroupsDispatch *self, Hub *hub, Arguments *args, Error *err) {
   Pad *pad   = PadList_pad(Hub_padList(hub), Hub_selectedPad(hub), err);
   long value = Arguments_ivalue(args)
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
         Error_format(err, "INTERNAL ERROR: bad inlet %ld", inlet);
         return;
   }
   Pad_computeChokeGroup(pad);
}

APIF void DispatchPtAr_populate(DispatchPtAr *self) {
   DispatchPtAr_truncate(self);
   Dispatch_itypeForeach(itype) {
      DispatchBase *base = DispatchBase_newUninitialized();
      base->itype        = itype;
      if (!Dispatch_initDispatchPtAr(DispatchBase_castToDispatch(base), self)) {
         Dispatch_init(DispatchBase_castToDispatch(base), self);
         DispatchPtAr_push(self, DispatchBase_castToDispatch(base));
      } else {
         Mem_free(base);
      }
   }
   DispatchPtAr_sort(self);
}

// NEED TO
// 1. Each type that implements, must have a custom newUnitialized that inserts the itype into the struct
// 2. For each interface, _isa${InterfaceName} returns true if the type belongs to InterfaceName
// 3. 
