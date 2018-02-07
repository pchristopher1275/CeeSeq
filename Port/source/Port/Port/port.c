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
    class_register(CLASS_BOX, c);
    Error_maypost(err);
    Port_class = c;
}


void *Port_new(t_symbol *s, long argc, t_atom *argv)
{
    Port *x = (Port *)object_alloc(Port_class);
    x->porttype = Port_vstType;
    x->outlet1 = outlet_new(x, NULL);
    return x;
}


void Port_free(Port *port)
{
    object_free((t_object *)port);
}
