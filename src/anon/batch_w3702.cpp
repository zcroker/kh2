#include "../common/types.h"

/* 00124c48: walk a table of variable-length entries (id, count, then count 16-byte items)
   ending at id -1; return the entry whose id matches, or 0.
   Partial asm: register pins (h/nx in t6, cur in t4, it in t5) reproduce the original's
   allocation (cur kept apart from the reloaded id, copied with move t4,t6). */
typedef struct Hdr00124c48 { u32 x0; u32 x4; s32 off; s32 cnt; } Hdr00124c48;
typedef struct Item00124c48 { u32 a, b, c, d; } Item00124c48;
typedef struct Ent00124c48 { s32 id; s32 n; u32 x8, xc; } Ent00124c48;
typedef struct Obj00124c48 { u32 x0; Hdr00124c48* h; } Obj00124c48;

/* 0019ee28: wtarget handler; on (1, 0xffff) clears D_00350448 and D_00350464.
   Partial asm: an empty asm volatile barrier keeps the +0x20 store before the +0 store. */
struct S00350448 { s32 a; u8 pad[0x1c]; f32 c; };
extern "C" {
extern S00350448 D_00350448;
extern f32 D_00350464;

Ent00124c48* func_00124c48(Obj00124c48* o, s32 id) {
    register Hdr00124c48* h asm("$14") = o->h;
    Ent00124c48* e = h->cnt ? (Ent00124c48*)((u8*)h + h->off) : 0;
    if (e) {
        register s32 cur asm("$12") = e->id;
        if (cur != -1) {
            for (;;) {
                register Item00124c48* it asm("$13") = (Item00124c48*)(e + 1);
                if (cur == id) return e;
                e = (Ent00124c48*)(it + e->n);
                register s32 nx asm("$14") = e->id;
                if (nx == -1) break;
                cur = nx;
            }
        }
    }
    return 0;
}

void wtarget_0019ee28(u32, u32, u32, u32) asm("_Z16wtarget_0019ee28jjjj");
void wtarget_0019ee28(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        S00350448* p = &D_00350448;
        f32 z = 0.0f;
        p->c = z;
        asm volatile("");
        D_00350448.a = 0;
        D_00350464 = z;
    }
}
}
