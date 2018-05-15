
@type 
   {
      "typeName": "Arguments",
      "fields": [
         {"valName": "s1", "type": "Symbol *"},
         {"valName": "i1", "type": "long"},
         {"valName": "i2", "type": "long"},

         {"valName": "ivalue", "type": "long"},
         {"valName": "inlet", "type": "long"}
      ]
   }
@end

@interface
   {
      "typeName": "Marshal",
      "methods": [
         {
            "name": "process",
            "valReturn": "void",
            // "args": ["Arguments *", "long", "Atom *", "Error *"]
            "args": [["ref", "Arguments"], ["val", "long"], ["val", "Atom *"], ["val", "Error *"]]
         },
         {
            "name": "zeroArgs",
            "valReturn": "void",
            // "args": ["Arguments *"]
            "args": [["ref", "Arguments"]]
         }
      ]
   }
@end

@type 
   {
      "typeName": "MarshalSi",
      "fields": [
         {
            "valName": "selector",
            "type": "Symbol *"
         },
         {
            "valName": "portId",
            "type": "Symbol *"
         },
         {
            "valName": "inlet",
            "type": "int"
         }
      ],
      "implements": ["Marshal"]
   }
@end

@type
   { 
      "typeName": "MarshalSii",
       "fields": [
          {
            "valName": "selector",
            "type": "Symbol *"
         },
         {
            "valName": "portId",
            "type": "Symbol *"
         },
         {
            "valName": "inlet",
            "type": "int"
         }
      ],
      "implements": ["Marshal"]
   }
@end

@type
   { 
      "typeName": "MarshalSs",
      "fields": [
         {
            "valName": "selector",
            "type": "Symbol *"
         },
         {
            "valName": "portId",
            "type": "Symbol *"
         },
         {
            "valName": "inlet",
            "type": "int"
         }
      ],
      "implements": ["Marshal"]
   }
@end

@interface
   {
      "typeName": "Dispatch",
      "methods": [
         {
            "name": "exec",
            "valReturn": "void",
            // "args": ["Hub *", "Arguments *", "Error *"]
            "args": [["ref", "Hub"], ["ref", "Arguments"], ["val", "Error *"]]
         },
         {
            "name": "create",
            "classMethod": true,
            "refReturn": "Dispatch",
            "args": []
         },
         {
            "name": "free",
            "valReturn": "void",
            "args": [],
            "defMethod": "Dispatch_freeDefault"
         },
         {
            "name": "initDispatchAr",
            "valReturn": "void",
            // "args": ["DispatchAr *", "Error *"],
            "args": [["ref", "DispatchAr"], ["val", "Error *"]],
            "absentOk": true,
            "classMethod": true,
            "defMethod": "Dispatch_initDispatchArDefault"
         }
      ],
      "containers": [
         {
            "type": "array",
            "typeName": "DispatchAr", 
            "refName": "Dispatch",
            "binarySearch": [
               {"compare": "Dispatch_cmp"}
            ]
         }
      ],
      "argDeclare": 1
   }
@end

@type
{
   "typeName": "IncrementFrameDispatch",
   "fields": [
      {
         "valName": "selector",
         "type": "Symbol *"
      },
      {
         "valName": "portId",
         "type": "Symbol *"
      },
      {
         "valName": "inlet",
         "type": "int"
      },
      {
         "valName": "marshal",
         "type": "Marshal *"
      }
   ],
   "implements": ["Dispatch"]
}
@end

@type
{
   "typeName": "DecrementFrameDispatch",
   "fields": [
      {
         "valName": "selector",
         "type": "Symbol *"
      },
      {
         "valName": "portId",
         "type": "Symbol *"
      },
      {
         "valName": "inlet",
         "type": "int"
      },
      {
         "valName": "marshal",
         "type": "Marshal *"
      }
   ],
   "implements": ["Dispatch"]
}
@end

@type
{
   "typeName": "SelectNextPushedPadDispatch",
   "fields": [
      {
         "valName": "selector",
         "type": "Symbol *"
      },
      {
         "valName": "portId",
         "type": "Symbol *"
      },
      {
         "valName": "inlet",
         "type": "int"
      },
      {
         "valName": "marshal",
         "type": "Marshal *"
      }
   ],
   "implements": ["Dispatch"]
}
@end

@type
{
   "typeName": "MidiFileDropDispatch",
   "fields": [
      {
         "valName": "selector",
         "type": "Symbol *"
      },
      {
         "valName": "portId",
         "type": "Symbol *"
      },
      {
         "valName": "inlet",
         "type": "int"
      },
      {
         "valName": "marshal",
         "type": "Marshal *"
      }
   ],
   "implements": ["Dispatch"]
}
@end

@type
{
   "typeName": "ManageChokeGroupsDispatch",
   "fields": [
      {
         "valName": "selector",
         "type": "Symbol *"
      },
      {
         "valName": "portId",
         "type": "Symbol *"
      },
      {
         "valName": "inlet",
         "type": "int"
      },
      {
         "valName": "marshal",
         "type": "Marshal *"
      }
   ],
   "implements": ["Dispatch"]
}
@end





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
   Arguments_setI1(args, Atom_toInteger(argv + 0));
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
   String *filename = String_fmt("%s", colon+1);
   Midiseq *mseq = Midiseq_fromfile(filename, err);
   if (Error_iserror(err)) {
     return;
   }
   String_free(filename);
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

APIF void ManageChokeGroupsDispatch_initDispatchAr(int itype, DispatchAr *disPtAr, Error *ignored) {
   for (int i = 0; i < 3; i++) {
      Dispatch *dis = ManageChokeGroupsDispatch_create(itype);
      dis->inlet    = i;
      DispatchAr_push(disPtAr, dis);
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

APIF void Dispatch_initDispatchArDefault(int itype, DispatchAr *disPtAr, Error *err) {
   Dispatch *dis = Dispatch_create(itype, err);
   Error_returnVoidOnError(err);
   DispatchAr_push(disPtAr, dis);
}

APIF void DispatchAr_populate(DispatchAr *self, Error *err) {
   DispatchAr_truncate(self);
   Dispatch_foreachIType(itype) {
      Dispatch_initDispatchAr(itype, self, err);
      Error_maypost(err);
   }
   DispatchAr_sort(self);
}


