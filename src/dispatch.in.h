
@type 
   {
      "typeName": "Arguments",
      "fields": [
         {"name": "s1", "type": "Symbol *"},
         {"name": "i1", "type": "long"},
         {"name": "i2", "type": "long"},

         {"name": "ivalue", "type": "long"},
         {"name": "inlet", "type": "long"}
      ],
   }
@end

@interface
   {
      "typeName": "Marshal",
      "baseType": "MarshalBase",
      "fields": [],
      "methods": [
         {
            "name": "process",
            "retVal": "void",
            "args": ["Arguments *", "long", "Atom *", "Error *"],
         },
         {
            "name": "zeroArgs",
            "retVal": "void",
            "args": ["Arguments *"],
         },
      ]
   }
@end

@type 
   {
      "typeName": "MarshalSi",
      "aliasFor": "MarshalBase",
      "implements": ["Marshal"]
   }
@end

@type
   { 
      "typeName": "MarshalSii",
      "aliasFor": "MarshalBase",
      "implements": ["Marshal"]
   }
@end

@type
   { 
      "typeName": "MarshalSs",
      "aliasFor": "MarshalBase",
      "implements": ["Marshal"]
   }
@end

@interface
   {
      "typeName": "Dispatch",
      "baseType": "DispatchBase",
      "fields": [
         {
            "name": "selector",
            "type": "Symbol *",
         },
         {
            "name": "portId",
            "type": "Symbol *",
         },
         {
            "name": "inlet",
            "type": "int",
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
            "args": ["Hub *", "Arguments *", "Error *"],
         },
         {
            "name": "clear",
            "retVal": "void",
            "args": [],
            "absentOk": true,
         },
         {
            "name": "init",
            "retVal": "void",
            "args": [],
            "absentOk": true,
         },
         {
            "name": "initDispatchPtAr",
            "retVal": "int",
            "args": ["DispatchPtAr *"],
            "absentOk": true,
         },
      ],
      "containers": [
         {
            "type": "array",
            "typename": "DispatchPtAr", 
            "elemname": "Dispatch *",
            "binarySearch": [
               {"compare": "DispatchBase_cmp"}
            ]
         }
      ]
   }
@end

@type
   {
      "typeName": "IncrementFrameDispatch",
      "aliasFor": "DispatchBase",
      "implements": ["Dispatch"]
   }
@end

@type
   {
      "typeName": "DecrementFrameDispatch",
      "aliasFor": "DispatchBase",
      "implements": ["Dispatch"]
   }
@end

@type
   {
      "typeName": "SelectNextPushedPadDispatch",
      "aliasFor": "DispatchBase",
      "implements": ["Dispatch"]
   }
@end

@type
   {
      "typeName": "MidiFileDropDispatch",
      "aliasFor": "DispatchBase",
      "implements": ["Dispatch"]
   }
@end

@type
   {
      "typeName": "ManageChokeGroupsDispatch",
      "aliasFor": "DispatchBase",
      "implements": ["Dispatch"]
   }
@end



