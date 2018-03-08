
#define APIF /**/
sds stripBaseName(const char *path);

@type
   {  
      "typeName": "BinFilePayload",
      "fields":[  
         {  
            "group":"noPersist"
         },
         {  
            "getter":"none",
            "name":"portFind",
            "setter":"none",
            "type":"PortFind *"
         }
      ]
   }
@end

#define BinFile_nullLengthFieldSizeStr "11"
#define BinFile_maxLength              2147483647
#define BinFileFlag_tag                1
#define BinFile_writeBackLength(bf, location, err) BinFile_writeBackLengthFlags(bf, location, -1, err)
#define BinFile_readLength(bf, err) BinFile_readLengthFlags(bf, NULL, err)
#define BinFile_writeLength(bf, length, err) BinFile_writeLengthFlags(bf, length, -1, err)

@type
   {  
      "typeName": "BinFile",
      "fields":[  
         {  
            "group":"noPersist"
         },
         {  
            "name":"version",
            "type":"int"
         },
         {  
            "name":"filename",
            "type":"sds"
         },
         {  
            "name":"buffer",
            "type":"sds"
         },
         {  
            "name":"stream",
            "type":"FILE *"
         },
         {  
            "getter":"none",
            "name":"payload",
            "setter":"none",
            "type":"BinFilePayload *"
         }
      ]
   }
@end

static inline PortFind *BinFile_portFindPayload(BinFile *self){ return (self->payload == NULL ? NULL : self->payload->portFind); }
static inline void BinFile_setPayload(BinFile *self, BinFilePayload *payload) { self->payload = payload;}

typedef struct MEvent_t
{
    uint8_t type;
    union
    {
        uint8_t b[2];
        uint16_t bend;
    } b;
    Ticks t;
    Ticks duration;
} MEvent;

#define MEvent_newUninitialized() ((MEvent*)sysmem_newptrclear(sizeof(MEvent)))
#define MEvent_type(cell) ((cell).type)
#define MEvent_t(cell) ((cell).t)
#define MEvent_notePitch(cell) ((cell).b.b[0])
#define MEvent_noteVelocity(cell) ((cell).b.b[1])
#define MEvent_noteDuration(cell) ((cell).duration)
#define MEvent_ccNumber(cell) ((cell).b.b[0])
#define MEvent_ccValue(cell) ((cell).b.b[1])
#define MEvent_bendValue(cell) ((cell).b.bend)
#include "mEventAr.h"

const int Midiseq_notetype   = 1;
const int Midiseq_bendtype   = 2;
const int Midiseq_cctype     = 3;
const int Midiseq_cycletype  = 4;
const int Midiseq_endgrptype = 5;

@type
   {  
      // FOO
      "typeName":"Midiseq",
      "fields":[  
         {  

            "group":"persist"
         },
         {  
            "name":"useMasterClock",
            "type":"bool"
         },
         {  
            "name":"sequenceLength",
            "type":"Ticks"
         },
         {  
            "name":"events",
            "type":"MEventAr"
         },
         {  
            "group":"noPersist"
         },
         {  
            "comment":[  
               "startTime is the time offset that t = 0 that is stored in the sequence corresponds too.",
               "Specifically, if useMasterClock is true, the startTime is updated whenever the ptr rolls",
               "off the end of the sequence, and raps around back to the beginning."
            ],
            "name":"startTime",
            "type":"Ticks"
         },
         {  
            "name":"ptr",
            "type":"int"
         }
      ]      
   }
@end

// @type
//    {  
//       "typeName":"NoteEvent",
//       "fields":[  
//          {  
//             "name":"type",
//             "type":"uint8_t"
//          },
//          {  
//             "name":"pitch",
//             "type":"uint8_t"
//          },
//          {  
//             "name":"velocity",
//             "type":"uint8_t"
//          },
//          {  
//             "name":"t",
//             "type":"Ticks"
//          },
//          {  
//             "name":"duration",
//             "type":"Ticks"
//          },
//       ],
//       "containers": [
//          {"type": "array", "typename": "NoteEventAr", "elemname": "NoteEvent"}
//       ]      
//    }
// @end

// @type
//    {  
//       "typeName":"NoteSequence",
//       "fields":[  
//          {  
//             "group":"persist"
//          },
//          {  
//             "name":"useMasterClock",
//             "type":"bool"
//          },
//          {  
//             "name":"sequenceLength",
//             "type":"Ticks"
//          },
//          {  
//             "name":"events",
//             "type":"NoteEventAr"
//          },
//          {  
//             "group":"noPersist"
//          },
//          {  
//             "name":"startTime",
//             "type":"Ticks"
//          },
//          {  
//             "name":"ptr",
//             "type":"int"
//          }
//       ]      
//    }
// @end


@type
   {  
      "typeName": "Pad",
      "fields":[  
         {  
            "group":"persist"
         },
         {  
            "name":"trackName",
            "type":"t_symbol *"
         },
         {  
            "name":"padIndex",
            "type":"int"
         },
         {  
            "name":"sequence",
            "setter":"proto",
            "type":"Midiseq *"
         },
         {  
            "name":"chokeGroupGlobal",
            "type":"bool"
         },
         {  
            "name":"chokeGroupInstrument",
            "type":"int"
         },
         {  
            "name":"chokeGroupIndex",
            "type":"int"
         },
         {  
            "group":"noPersist"
         },
         {  
            "name":"chokeGroup",
            "type":"int64_t"
         },
         {  
            "name":"noteReleasePending",
            "type":"bool"
         },
         {  
            "name":"inEndgroup",
            "type":"bool"
         },
         {  
            "name":"track",
            "type":"Track *"
         }
      ],
      "containers": [
         {"type": "array", "typename": "PadAr", "elemname": "Pad"},
         {"type": "array", "typename": "PadPtrAr", "elemname": "Pad *"}
      ]
   }
@end

@type
   {  
      "typeName": "IndexedOff",
      "argDeclare":1,
      "fields":[  
         {  
            "name":"padIndex",
            "type":"int"
         },
         {  
            "name":"pitch",
            "type":"int"
         }
      ],
      "containers": [
         {
            "type": "array",
            "typename": "IndexedOffAr", 
            "elemname": "IndexedOff",
            "binarySearch": [
               {"compare": "IndexedOff_cmpPadIndex", "multi": true, "tag": "PadIndex"}
            ]
         }
      ]
   }
@end

@type
   {  
      "typeName":"TimedOff",
      "argDeclare":1,
      "fields":[  
         {  
            "name":"time",
            "type":"Ticks"
         },
         {  
            "name":"pitch",
            "type":"int"
         }
      ],
      "containers": [
         {
            "type": "array",
            "typename": "TimedOffAr", 
            "elemname": "TimedOff",
            "binarySearch": [
               {"compare": "TimedOff_cmpTime", "multi": false, "tag": "Time"}
            ]
         }
      ]
   }
@end

@type
   {  
      "typeName":"NoteManager",
      "fields":[  
         {  
            "group":"noPersist"
         },
         {  
            "name":"pending",
            "type":"TimedOffAr"
         },
         {  
            "name":"endgroups",
            "type":"IndexedOffAr"
         },
         {  
            "name":"output",
            "type":"Port *"
         },
         {  
            "name":"atoms",
            "type":"t_atom *"
         }
      ]
   }
@end

@type
   {  
      "typeName":"PortFindCell",
      "fields":[  
         {  
            "group":"noPersist"
         },
         {  
            "name":"reciever",
            "type":"Port *"
         },
         {  
            "name":"varname",
            "type":"t_symbol *"
         }
      ],
      "containers": [
         {
            "type": "array",
            "typename": "PortFindCellAr", 
            "elemname": "PortFindCell"
         }
      ]
   }
@end

@type
   {  
      "typeName": "PortFind",
      "fields":[  
         {  
            "group":"noPersist"
         },
         {  
            "name":"objects",
            "type":"PortFindCellAr"
         },
         {  
            "name":"hub",
            "type":"void *"
         },
         {  
            "name":"anythingDispatch",
            "type":"Port_anythingDispatchFunc"
         },
         {  
            "name":"intDispatch",
            "type":"Port_intDispatchFunc"
         }
      ]
   }
@end
#define PortFind_declare(name) PortFind _##name; PortFind *name = &_##name; memset(name, 0, sizeof(PortFind)); PortFind_init(name)        


@type
   {  
      "typeName": "PadList",
      "fields":[  
         {  
            "getterReturn":"pointer",
            "name":"pads",
            "setter":"none",
            "type":"PadAr"
         },
         {  
            "getterReturn":"pointer",
            "name":"running",
            "setter":"none",
            "type":"PadPtrAr"
         }
      ]
   }
@end

@type
   {  
      "typeName": "Track",
      "fields":[  
         {  
            "name":"name",
            "type":"Symbol *"
         },
         {  
            "name":"noteManager",
            "type":"NoteManager *"
         }
      ],
      "containers": [
         {
            "type": "array",
            "typename": "TrackAr", 
            "elemname": "Track"
         }
      ]
   }
@end


@type
   {  
      "typeName": "TrackList",
      "fields":[  
         {  
            "getterReturn":"pointer",
            "name":"list",
            "setter":"none",
            "type":"TrackAr"
         }
      ]
   }
@end

@type
   {  
      "typeName": "PortRef",
      "fields":[  
         {  
            "name":"port",
            "type":"Port *"
         },
         {  
            "name":"outlet",
            "type":"int"
         }
      ],
      "noNewUnitialized":1
   }
@end

#define PortRef_declare(name, port, outlet)    PortRef _##name = {port, outlet}; PortRef *name = &_##name
static inline void PortRef_set(PortRef *pr, Port *port, int outlet) {
   pr->port   = port;
   pr->outlet = outlet;
}
#define PortRef_send(pr, argc, argv, err)      Port_send(PortRef_port(pr), PortRef_outlet(pr), argc, argv, err)
#define PortRef_sendInteger(pr, value, err)    Port_sendInteger(PortRef_port(pr), PortRef_outlet(pr), value, err)


@type
   {  
      "typeName": "DropDown",
      "fields":[  
         {  
            "getterReturn":"pointer",
            "name":"table",
            "setter":"none",
            "type":"SymbolPtrAr"
         },
         {  
            "name":"selected",
            "setter":"none",
            "type":"int"
         },
         {  
            "getter":"none",
            "name":"portRef",
            "setter":"none",
            "type":"PortRef"
         }
      ]
   }
@end

static inline PortRef *DropDown_portRef(DropDown *dd) {
    return &dd->portRef;
}

static inline void DropDown_setPortRef(DropDown *dd, PortRef *pr) {
   dd->portRef = *pr;
}

@type
   {  
      "typeName": "Hub",
      "fields":[  
         {  
            "name":"padList",
            "type":"PadList *"
         },
         {  
            "name":"trackList",
            "type":"TrackList *"
         },
         {  
            "name":"currBankPort",
            "type":"Port *"
         },
         {  
            "name":"currFramePort",
            "type":"Port *"
         },
         {  
            "name":"selBankPort",
            "type":"Port *"
         },
         {  
            "name":"selFramePort",
            "type":"Port *"
         },
         {  
            "name":"selPadPort",
            "type":"Port *"
         },
         {  
            "name":"chokeGroupPort",
            "type":"Port *"
         },
         {  
            "getterReturn":"pointer",
            "name":"cgLocalGlobalMenu",
            "setter":"none",
            "type":"DropDown"
         },
         {  
            "getterReturn":"pointer",
            "name":"cgInstrumentMenu",
            "setter":"none",
            "type":"DropDown"
         },
         {  
            "getterReturn":"pointer",
            "name":"cgIndexMenu",
            "setter":"none",
            "type":"DropDown"
         },
         {  
            "comment":"bank varies from 0-infinity",
            "name":"bank",
            "type":"int"
         },
         {  
            "comment":"frame varies from 0-7",
            "name":"frame",
            "type":"int"
         },
         {  
            "comment":"true if the next padIndex tapped should be written into selectedPad",
            "name":"grabNextTappedPad",
            "type":"bool"
         },
         {  
            "comment":"which pad has been selected",
            "name":"selectedPad",
            "type":"int"
         }
      ]
   }

@end

#define Hub_padsPerFrame           24
#define Hub_framesPerBank           8
#define Hub_padsPerBank            (Hub_padsPerFrame*Hub_framesPerBank)
#define Hub_firstMidiNote          48

#define hub_padIndexToBank(index)         (index / Hub_padsPerBank)
#define hub_padIndexToFrame(index)        (index / Hub_framesPerBank)
#define hub_padIndexToRelativePad(index)  (index % Hub_padsPerFrame)

#define Hub_selectedBank(hub)        hub_padIndexToBank(Hub_selectedPad(hub))
#define Hub_selectedFrame(hub)       hub_padIndexToFrame(Hub_selectedPad(hub))
#define Hub_relativeSelectedPad(hub) hub_padIndexToRelativePad(Hub_selectedPad(hub))

#define Hub_padIndexFromInNote(hub, inputNote) (Hub_bank(hub)*Hub_padsPerBank + Hub_frame(hub)*Hub_padsPerFrame + (inputNote - Hub_firstMidiNote))
