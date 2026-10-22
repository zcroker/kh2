#include "../common/types.h"
// 001b60e0 and 001b6298 are constructor twins. The flags store goes through a
// byte offset, so it has no MEM_EXPR and sched2 puts the id store before sd ra.
struct W8021Sub { u8 pad[8]; u32 f8; };
struct W8021Owner { u8 pad[0xc]; W8021Sub* p0c; u8 pad2[0x160 - 0x10]; u32 f160; };
struct W8021Obj { u8 pad[4]; void* back; u8 pad2[0x30 - 8]; void* cb; };
struct W8021T { W8021Owner* owner; s32 id; s32 x; u32 flags; s32 f10; s32 f14; W8021Obj* f18; u8 f1c; };
extern "C" {
extern W8021T* D_00351184;
extern u32 D_00351214;
extern u8 D_00351ec0[];
void func_001b6d00(void);
s32 func_001a1658(s32, s32);
s32 func_001d1438(s32);
s32 func_0019c090(W8021Owner*);
void func_001c8d80(void*, s32);
W8021Obj* func_00102818(u32, u32, u32, void*, s32);
void func_00102788(u32, u32, u32, void*);
void func_001b6ca8(void);
void func_001b6cc8(void);
void func_001b6a50(void);
static inline __attribute__((always_inline)) bool ok(s32 id) { return id != 0 && id < 7; }
static inline __attribute__((always_inline)) bool isA(u32 f) {
    bool r = false;
    if (f & 0x20) goto yes;
    if (f & 0x1000000) goto yes;
    goto no;
yes: r = true;
no: return r;
}
static inline __attribute__((always_inline)) bool isB(u32 f) {
    bool r = false;
    if (isA(f)) goto yes;
    if (f & 0x40) goto yes;
    goto no;
yes: r = true;
no: return r;
}
void func_001b60e0(W8021T* t, W8021Owner* o, s32 id, s32 x) {
    t->owner = o;
    t->id = id;
    t->x = x;
    *(u32*)((u8*)t + 12) = 0;
    t->f10 = 0;
    t->f14 = 0;
    t->f1c = 0;
    if (D_00351184) func_001b6d00();
    D_00351184 = t;
    if (ok(id)) t->f14 = func_001a1658(1, -1);
    if (t->x == 0) t->x = func_001d1438(t->id);
    if (func_0019c090(t->owner)) {
        W8021Owner* ow = t->owner;
        t->flags |= 1;
        if (!isB(ow->f160)) {
            u32 g = ow->p0c->f8;
            if (g & 0x40) goto out;
            if (g & 0x4000) goto out;
            t->flags |= 2;
        }
    }
out:
    func_001c8d80(D_00351ec0, 1);
    t->f18 = func_00102818(D_00351214, 0, 1, (void*)func_001b6ca8, 0x2000);
    t->f18->back = t;
    t->f18->cb = (void*)func_001b6cc8;
    if (t->f14) func_00102788(D_00351214, 0, 1, (void*)func_001b6a50);
}
void u_tail4_001b6298(W8021T* t, W8021Owner* o, s32 id, s32 x) asm("_Z16u_tail4_001b6298jjjj");
void u_tail4_001b6298(W8021T* t, W8021Owner* o, s32 id, s32 x) {
    t->owner = o;
    t->id = id;
    t->x = x;
    *(u32*)((u8*)t + 12) = 0;
    t->f10 = 0;
    t->f14 = 0;
    t->f1c = 0;
    if (D_00351184) func_001b6d00();
    D_00351184 = t;
    if (ok(id)) t->f14 = func_001a1658(1, -1);
    if (t->x == 0) t->x = func_001d1438(t->id);
    if (func_0019c090(t->owner)) {
        W8021Owner* ow = t->owner;
        t->flags |= 1;
        if (!isB(ow->f160)) {
            u32 g = ow->p0c->f8;
            if (g & 0x40) goto out;
            if (g & 0x4000) goto out;
            t->flags |= 2;
        }
    }
out:
    func_001c8d80(D_00351ec0, 1);
    t->f18 = func_00102818(D_00351214, 0, 1, (void*)func_001b6ca8, 0x2000);
    t->f18->back = t;
    t->f18->cb = (void*)func_001b6cc8;
    if (t->f14) func_00102788(D_00351214, 0, 1, (void*)func_001b6a50);
}
}
