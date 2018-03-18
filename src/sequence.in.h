@interface 
   {
      "typeName": "Outlet",
      "fields": [
      ],       
      "methods": [
         {
            "name": "sendNote",
            "retVal": "void",
            "args": ["uint8_t", "uint8_t"]
         },
         {
            "name": "sendFloat",
            "retVal": "void",
            "args": ["double"]
         },
      ]
   }
@end


@type
   {
      "typeName": "Timed",
      "fields": [
         {"name": "time", "type": "Ticks"},
         {"name": "version", "type": "int"},
         {"name": "sequence", "type": "Sequence *"},
      ],       
      "containers": [
         {"type": "array", "typename": "TimedAr", "elemname": "Timed"}
      ]
   }
@end


@type 
   {
      "typeName": "NoteEvent",
      "fields": [
         {"name": "pitch", "type": "uint8_t"},
         {"name": "velocity", "type": "uint8_t"},
         {"name": "stime", "type": "Ticks"},
         {"name": "duration", "type": "Ticks"}
      ], 
      "containers": [
         {"type": "array", "typename": "NoteEventAr", "elemname": "NoteEvent"}
      ]
   }
@end

@type
   {
      "typeName": "FloatEvent",
      "fields": [
         {"name": "time", "type": "Ticks"},
         {"name": "value", "type": "double"}
      ],
      "containers": [
         {"type": "array", "typename": "FloatEventAr", "elemname": "FloatEvent"}
      ]
   }
@end

@type 
   {
      "typeName": "NoteSequence",
      "fields":[  
         {
            "name": "version", 
            "type": "long"
         },
         {  
            "name":"sequenceLength",
            "type":"Ticks"
         },
         {  
            "name":"startTime",
            "type":"Ticks"
         },
         {  
            "name":"cursor",
            "type":"int"
         },
         {  
            "name":"cycle",
            "type":"bool"
         },
         {  
            "name":"outlet",
            "type":"Outlet *"
         },
         {  
            "name":"recordBuffer",
            "type":"NoteSequence *"
         },
         {  
            "name":"offs",
            "type":"TimedOffAr"
         },
         {  
            "name":"events",
            "type":"NoteEventAr"
         },
      ]
   }
@end


@interface
   {
      "typeName": "Sequence",
      "fields": [
         {
            "name": "version", 
            "type": "long"
         }
      ],
      "methods": [
         {
            "name": "start",
            "retVal": "void",
            "args": ["Ticks", "Ticks", "TimedAr *"]
         },
         {
            "name": "drive",
            "retVal": "void",
            "args": ["Ticks", "TimedAr *"]
         },
         {
            "name": "startRecord",
            "retVal": "void",
            "args": []
         },
         {
            "name": "recordingSeq",
            "retVal": "Sequence *",
            "args": ["Ticks"]
         },
         {
            "name": "stop",
            "retVal": "void",
            "args": []
         },
      ],
      "containers": [
         {"type": "array", "typename": "SequenceAr", "elemname": "Sequence *"}
      ]
   }
@end

@type
   {
      "typeName": "RecordBuffer",
      "fields": [
         {
            "name": "recordStart", 
            "type": "Ticks"
         },
         {
            "name": "sequences", 
            "type": "SequenceAr"
         }
      ],
   }
@end