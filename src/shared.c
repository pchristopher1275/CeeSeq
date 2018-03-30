
//
// P O R T
//

// struct Port_t
// {
//     t_object d_obj;
//     long inletnum;
//     PtrAr proxy;
//     PtrAr outlet;
//     Symbol *track;
//     Symbol *id;
//     long intInlets;
//     long intOutlets;
//     void *hub;
//     Port_anythingDispatchFunc anythingDispatch;
//     Port_intDispatchFunc intDispatch;
// };

// Port PORT_NULL_IMPL =
// {
//     {
//         0
//     }
// };

// #define Port_null (&PORT_NULL_IMPL)
// #define Port_track(p)            ((p)->track)
// #define Port_id(p)               ((p)->id)
// #define Port_hub(p)              ((p)->hub)
// #define Port_anythingDispatch(p) ((p)->anythingDispatch)
// #define Port_intDispatch(p)      ((p)->intDispatch)
// #define Port_outlet(p, n)        ((p)->outlet[(n)])
// #define Port_proxy(p, n)         ((p)->proxy[(n)])
// #define Port_intInlets(p)        ((p)->intInlets)
// #define Port_intOutlets(p)       ((p)->intOutlets)
// #define Port_inletnum(p)         (p)->inletnum
// void Port_send(Port *port, int outletIndex, short argc, Atom *argv, Error *err);
// void Port_sendInteger(Port *p, int outlet, long value);

// // Will parse id's of the form ev\d+ and return the \d+ number. Returns -1 otherwise
// APIF int port_parseEvSymbol(Symbol *id)
// {
//     int r = -1;
//     int consumed = 0;
//     if (id == NULL) {
//         return -1;
//     }

//     if (sscanf(Symbol_cstr(id), "ev%d%n", &r, &consumed) != 1) {
//         return -1;
//     }
//     if (strlen(Symbol_cstr(id)) != consumed) {
//         return -1;
//     }
//     return r;
// }

// APIF void Port_send(Port *port, int outletIndex, short argc, Atom *argv, Error *err)
// {   
//     Symbol *selector = Atom_toSymbol(argv + 0);
//     void *out = PtrAr_get(&port->outlet, outletIndex, err);
//     Error_returnVoidOnError(err);
//     outlet_anything(out, selector, argc-1, argv+1);  
// }

// APIF void Port_sendInteger(Port *p, int outlet, long value) 
// {
//     Error_declare(err);
//     void *out = PtrAr_get(&p->outlet, outlet, err);
//     if (Error_maypost(err)) {
//         return;
//     }
//     outlet_int(out, value);   
// }

