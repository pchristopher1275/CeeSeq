
@type 
   {
      "typeName": "Arguments",
      "fields": [
         {"name": "s1", "type": "Symbol *"},
         {"name": "i1", "type": "long"},
         {"name": "i2", "type": "long"},

         {"name": "ivalue", "type": "long"},
         {"name": "inlet", "type": "long"}
      ]
   }
@end

@interface
   {
      "typeName": "Marshal",
      "fields": [],
      "methods": [
         {
            "name": "process",
            "retVal": "void",
            "args": ["Arguments *", "long", "Atom *", "Error *"]
         },
         {
            "name": "zeroArgs",
            "retVal": "void",
            "args": ["Arguments *"]
         }
      ]
   }
@end

@type 
   {
      "typeName": "MarshalSi",
      "aliasFor": "Marshal",
      "implements": ["Marshal"]
   }
@end

@type
   { 
      "typeName": "MarshalSii",
      "aliasFor": "Marshal",
      "implements": ["Marshal"]
   }
@end

@type
   { 
      "typeName": "MarshalSs",
      "aliasFor": "Marshal",
      "implements": ["Marshal"]
   }
@end

@interface
   {
      "typeName": "Dispatch",
      "fields": [
         {
            "name": "selector",
            "type": "Symbol *"
         },
         {
            "name": "portId",
            "type": "Symbol *"
         },
         {
            "name": "inlet",
            "type": "int"
         },
         {
            "name": "marshal",
            "type": "Marshal *"
         }
      ],
      "methods": [
         {
            "name": "exec",
            "retVal": "void",
            "args": ["Hub *", "Arguments *", "Error *"]
         },
         {
            "name": "create",
            "itypeReceiver": true,
            "retVal": "Dispatch *",
            "args": []
         },
         {
            "name": "free",
            "retVal": "void",
            "args": [],
            "defMethod": "Dispatch_freeDefault"
         },
         {
            "name": "initDispatchPtAr",
            "retVal": "void",
            "args": ["DispatchPtAr *", "Error *"],
            "absentOk": true,
            "itypeReceiver": true,
            "defMethod": "Dispatch_initDispatchPtArDefault"
         }
      ],
      "containers": [
         {
            "type": "array",
            "typeName": "DispatchPtAr", 
            "elemName": "Dispatch *",
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
      "aliasFor": "Dispatch",
      "implements": ["Dispatch"]
   }
@end

@type
   {
      "typeName": "DecrementFrameDispatch",
      "aliasFor": "Dispatch",
      "implements": ["Dispatch"]
   }
@end

@type
   {
      "typeName": "SelectNextPushedPadDispatch",
      "aliasFor": "Dispatch",
      "implements": ["Dispatch"]
   }
@end

@type
   {
      "typeName": "MidiFileDropDispatch",
      "aliasFor": "Dispatch",
      "implements": ["Dispatch"]
   }
@end

@type
   {
      "typeName": "ManageChokeGroupsDispatch",
      "aliasFor": "Dispatch",
      "implements": ["Dispatch"]
   }
@end



