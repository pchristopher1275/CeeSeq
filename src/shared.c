#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//
// P O R T
//

enum
{
    // XXX: Port type is deprecated use the track and type symbols on Port
    Port_nullType = 0,
    Port_vstType = 1,
};

// struct Port_t;
struct Port_t
{
    t_object d_obj;
    int porttype;
    long inletnum;
    PtrAr proxy;
    PtrAr outlet;
    Symbol *track;
    Symbol *id;
    long intInlets;
    long intOutlets;
    void *hub;
    Port_anythingDispatchFunc anythingDispatch;
    Port_intDispatchFunc intDispatch;
    Atom *sendBuffer;
};

Port PORT_NULL_IMPL =
{
    {
        0
    }
};

#define Port_null (&PORT_NULL_IMPL)
#define Port_track(p)            ((p)->track)
#define Port_id(p)               ((p)->id)
#define Port_hub(p)              ((p)->hub)
#define Port_anythingDispatch(p) ((p)->anythingDispatch)
#define Port_intDispatch(p)      ((p)->intDispatch)
#define Port_sendBuffer(p)       ((p)->sendBuffer)
#define Port_outlet(p, n)        ((p)->outlet[(n)])
#define Port_proxy(p, n)         ((p)->proxy[(n)])
#define Port_intInlets(p)        ((p)->intInlets)
#define Port_intOutlets(p)       ((p)->intOutlets)
#define Port_inletnum(p)         (p)->inletnum

// Will parse id's of the form ev\d+ and return the \d+ number. Returns -1 otherwise
APIF int port_parseEvSymbol(Symbol *id)
{
    int r = -1;
    int consumed = 0;
    if (id == NULL) {
        return -1;
    }

    if (sscanf(Symbol_cstr(id), "ev%d%n", &r, &consumed) != 1) {
        return -1;
    }
    if (strlen(Symbol_cstr(id)) != consumed) {
        return -1;
    }
    return r;
}


APIF static const char *Port_idString(Port *port)
{
    switch(port->porttype) {
        case Port_nullType:
            return "Port_nullType";
        case Port_vstType:
            return "Port_vstType";
        default:
            return "PORT-UNKNOWN";
    }
}


APIF static int Port_isVstType(Port *port)
{
    return port->porttype == Port_vstType;
}


APIF static int Port_isNullType(Port *port)
{
    return port->porttype == Port_nullType;
}


APIF void Port_send(Port *port, int outletIndex, short argc, Atom *argv, Error *err)
{
    if (Port_isNullType(port)) {
        return;
    }
    else if (Port_isVstType(port)) {
        Symbol *selector = atom_getsym(argv + 0);
        void *out = PtrAr_get(&port->outlet, outletIndex, err);
        Error_returnVoidOnError(err);
        outlet_anything(out, selector, argc-1, argv+1);
    }
    else {
        Error_format(err, "Port_send called on porttype = %s", Port_idString(port));
    }
}

APIF void Port_sendInteger(Port *p, int outlet, long value) {
    Error_declare(err);
    void *out = PtrAr_get(&p->outlet, outlet, err);
    if (Error_maypost(err)) {
        return;
    }
    outlet_int(out, value);   
}

APIF void Port_sendSelectorAndInteger(Port *port, Symbol *selector, int value)
{
    Error_declare(err);
    Atom a = {0};
    atom_setlong(&a, value);
    void *outlet = PtrAr_get(&port->outlet, 0, err);
    if (Error_maypost(err)) {
        return;
    }
    outlet_anything(outlet, selector, 1, &a);
}
