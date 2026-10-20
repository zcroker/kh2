#include "../common/types.h"

struct W1775Ctl { u8 pad[8]; u32 flags; };
struct W1775Obj { u8 pad0[0xc]; W1775Ctl* ctl; u8 pad10[0x160 - 0x10]; u32 flags160; };
struct W1775Hold { u8 pad[4]; W1775Obj* obj; };
struct W1775Self { W1775Hold* h; };


extern "C" {
void func_0019ba60(W1775Obj*);
s32 func_0019c090(W1775Obj*);
s32 func_001b9d40(W1775Obj*);
u8 func_001791e8(W1775Obj*, void*);

static inline bool W1775_CtlBusy(W1775Obj* o) { return (o->ctl->flags & 2) || (o->flags160 & 0x40); }
static inline bool W1775_Busy(W1775Obj* o) { bool r = false; if (func_0019c090(o) || W1775_CtlBusy(o)) r = true; return r; }
static inline bool W1775_CanAct(W1775Obj* o) { bool r = false; if (func_0019c090(o) || W1775_CtlBusy(o)) r = true; return !r; }


/* Notifies the held object, then replaces the holder pointer with the object's busy flag. */
void func_00173878(W1775Self* s) {
    if (s->h) func_0019ba60(s->h->obj);
    W1775Obj* o = s->h->obj;
    *(u32*)s = W1775_Busy(o);
}

s32 func_00179148(W1775Obj* o) {
    if (W1775_CanAct(o)) {
        if (func_001b9d40(o)) return func_001791e8(o, (u8*)o + 0x10);
        return 0;
    }
    return 0;
}

}
