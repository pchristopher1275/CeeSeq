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
#include "../../../../Shared/cseq/shared.c"

#ifndef PORT_BUILD_NUMBER
#define PORT_BUILD_NUMBER 0
#endif

static t_class *Port_class = NULL;

void *Port_new(t_symbol *s, long argc, t_atom *argv);
void Port_anything(Port *port, t_symbol *msg, long argc, t_atom *argv);
void Port_free(Port *x);

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
    CLASS_ATTR_SYM(c, "track", 0, Port, track);
    CLASS_ATTR_SYM(c, "type", 0, Port, type);
    class_register(CLASS_BOX, c);
    Error_maypost(err);
    Port_class = c;
}


void *Port_new(t_symbol *s, long argc, t_atom *argv)
{
    Port *x = (Port *)object_alloc(Port_class);
    attr_args_process(x, argc, argv);

    x->porttype              = Port_vstType;
    x->outlet1               = outlet_new(x, NULL);
    Port_hub(x)              = NULL;
    Port_anythingDispatch(x) = NULL;

    if (x->track == NULL) {
        x->track = gensym("unknown");
    }
    if (x->type == NULL) {
        x->type  = gensym("unknown");
    }
    return x;
}
void Port_anything(Port *port, t_symbol *msg, long argc, t_atom *argv) {
    if (Port_anythingDispatch(port) != NULL) {
        dblog("GOT %s", msg->s_name);
        Port_anythingDispatch(port)(Port_hub(port), port, msg, argc, argv);
    }
}

void Port_free(Port *port)
{
}
