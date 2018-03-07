/**
    @file
    CseqHub - an ITM-based delay

    @ingroup	examples
*/

#include <stdlib.h>
#include "ext.h"
#include "ext_common.h"
#include "ext_obex.h"
#include "ext_time.h"
#include "ext_itm.h"
#include "mem.c"
#include "core.c"
#include "array.c"
#include "ptrAr.h"
#include "shared.c"

#ifndef PORT_BUILD_NUMBER
#define PORT_BUILD_NUMBER 0
#endif

static t_class *Port_class = NULL;

void *Port_new(Symbol *s, long argc, t_atom *argv);
void Port_anything(Port *port, Symbol *msg, long argc, t_atom *argv);
void Port_free(Port *x);
void Port_int(Port *port, long value);

void ext_main(void *r)
{
    // NOTE: If class_new makes a copy of className, than className has essentially leaked.
    sds className = NULL;
    if (PORT_BUILD_NUMBER == 0) {
        className = sdsnew("Port");
    }
    else {
        className = sdscatprintf(sdsempty(), "Port%d", PORT_BUILD_NUMBER);
    }
    Error_declare(err);
    DBLog_init("port", err);

    t_class *c = class_new(className, (method)Port_new, (method)Port_free,
        sizeof(Port), (method)0L, A_GIMME, 0);
    class_addmethod(c, (method)Port_anything, "anything", A_GIMME, 0);
    class_addmethod(c, (method)Port_int, "int", A_LONG, 0);
    CLASS_ATTR_SYM(c, "track", 0, Port, track);
    CLASS_ATTR_SYM(c, "id", 0, Port, id);
    CLASS_ATTR_LONG(c, "iinps", 0, Port, intInlets);
    CLASS_ATTR_LONG(c, "iouts", 0, Port, intOutlets);
    class_register(CLASS_BOX, c);
    Error_maypost(err);
    Port_class = c;
}


void *Port_new(Symbol *s, long argc, t_atom *argv)
{
    Error_declare(err);
    Port *port = (Port *)object_alloc(Port_class);
    attr_args_process(port, argc, argv);
    if (Port_id(port) == NULL) {
        Port_id(port) = gensym("unknown");
    }
    if (Port_id(port) == NULL) {
        Port_id(port) = gensym("unknown");
    }

    port->porttype              = Port_vstType;
    PtrAr_init(&port->proxy, 0);
    PtrAr_init(&port->outlet, 0);

    int ev = port_parseEvSymbol(Port_id(port));
    if (ev >= 0) {
        PtrAr_changeLength(&port->proxy, 4);
        PtrAr_changeLength(&port->outlet, 4);
        for (int i = 3; i >= 0; i--) {
            void *p = NULL;
            if (i != 0) {
                p = proxy_new(port, (long)i, &port->inletnum);
            }
            PtrAr_set(&port->proxy, i, p, err);
            if (Error_maypost(err)) {
                break;
            }
            PtrAr_set(&port->outlet, i, intout(port), err);
            if (Error_maypost(err)) {
                break;
            }
        }

    } else if (Port_intInlets(port) > 0 || Port_intOutlets(port) > 0) {
        if (Port_intInlets(port) <= 0) {
            Port_intInlets(port) = 1;
        }
        if (Port_intOutlets(port) <= 0) {
            Port_intOutlets(port) = 1;
        } 
        PtrAr_changeLength(&port->proxy,  Port_intInlets(port));
        PtrAr_changeLength(&port->outlet, Port_intOutlets(port));
        for (int i = Port_intInlets(port)-1; i >= 0; i--) {
            void *p = NULL;
            if (i != 0) {
                p = proxy_new(port, (long)i, &Port_inletnum(port));
            }
            PtrAr_set(&port->proxy, i, p, err);
            if (Error_maypost(err)) {
                break;
            }
        }
        for (int i = Port_intOutlets(port)-1; i >= 0; i--) {
            PtrAr_set(&port->outlet, i, outlet_new(port, NULL), err);
            if (Error_maypost(err)) {
                break;
            }   
        }
    }
    else {
        PtrAr_push(&port->outlet, outlet_new(port, NULL));
    }

    Port_hub(port)              = NULL;
    Port_anythingDispatch(port) = NULL;
    Port_intDispatch(port)      = NULL;
    Port_sendBuffer(port)       = NULL;

    return port;
}


void Port_anything(Port *port, Symbol *msg, long argc, t_atom *argv)
{
    if (Port_anythingDispatch(port) != NULL) {
        Port_anythingDispatch(port)(Port_hub(port), port, msg, argc, argv);
    }
}


void Port_int(Port *port, long value)
{
    if (Port_intDispatch(port) != NULL) {
        int inlet = proxy_getinlet((t_object *)port);
        Port_intDispatch(port)(Port_hub(port), port, value, inlet);
    }
}


void Port_free(Port *port)
{
    if (port != NULL) {
        PtrAr_foreach(it, &port->proxy) {
            object_free(it.var);
        }
        PtrAr_clear(&port->proxy);
        PtrAr_clear(&port->outlet);
    }
}
