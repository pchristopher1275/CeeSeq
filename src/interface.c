const char *Interface_toString(int itype)
{
    switch(itype) {
        case Undefined_itype:
            return "Undefined";
        case MarshalSi_itype:
            return "MarshalSi";
        case MarshalSii_itype:
            return "MarshalSii";
        case MarshalSs_itype:
            return "MarshalSs";
        case IncrementFrameDispatch_itype:
            return "IncrementFrameDispatch";
        case DecrementFrameDispatch_itype:
            return "DecrementFrameDispatch";
        case SelectNextPushedPadDispatch_itype:
            return "SelectNextPushedPadDispatch";
        case MidiFileDropDispatch_itype:
            return "MidiFileDropDispatch";
        case ManageChokeGroupsDispatch_itype:
            return "ManageChokeGroupsDispatch";
    }
    return "Unknown";
}
