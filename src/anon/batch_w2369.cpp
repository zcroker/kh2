#include "../common/types.h"

struct RingEnt { s32 v; s32 t; };
struct Ring16 { s32 head; s32 tail; RingEnt ent[16]; };

extern "C" {
void func_0031cc28(s32*);

// Push v into a 16-entry ring buffer (if not full); the entry's second word is filled by func_0031cc28.
void func_00187ef0(Ring16* r, s32 v) {
    s32 i = r->head;
    s32 c = (i - r->tail + 16) % 16;
    if (c < 15) {
        RingEnt* p = &r->ent[i];
        r->head = (i + 1) % 16;
        RingEnt e;
        e.v = v;
        e.t = 0;
        func_0031cc28(&e.t);
        *p = e;
    }
}
}

struct FindEnt { u8 pad[12]; s32 flags; u8 pad2[34 - 16]; u16 id; };
struct FindPl { u8 pad[0x160]; u32 st; u8 pad2[0x50c - 0x164]; u32 id; };
struct FindWk { u8 pad[0x9e0]; FindPl* pl; };
struct FindCtx { FindWk** w; };

extern "C" {
FindEnt* func_001b8e88(s32);
s32 func_001917c0(void);

// Look up entity id; reject it by flag bits 4/6 and the player's state/id.
FindEnt* func_0019e5f8(FindCtx* c, s32 id) {
    FindPl* pl = (*c->w)->pl;
    if (id == 0) return 0;
    FindEnt* e = func_001b8e88(id);
    if (func_001917c0() != 0) {
        u8 b = (e->flags >> 4) & 1;
        if (!b) return 0;
    }
    u8 b6 = (e->flags >> 6) & 1;
    if (b6) {
        if (!(pl->st & 0x200000) || pl->id != e->id) return 0;
    }
    return e;
}
}

struct Blk36 { u32 w[9]; };

extern "C" {
extern u8 D_00352770;
extern u8 D_00350379;
s32 func_001bb4a0(void);
void func_00199098(Blk36*, s32);

// If both flags are set and func_001bb4a0() reports 0, fill *out via func_00199098 and return 1.
s32 func_001d5a58(void* self, Blk36* out) {
    if (D_00352770 == 0 || D_00350379 == 0 || func_001bb4a0() != 0) return 0;
    Blk36 t;
    func_00199098(&t, 0);
    *out = t;
    return 1;
}
}

struct CallSub { f32 a; u32 b; u32 c; u32 d; u32 e; };
struct CallMgr { u8 pad[24]; CallSub s0; u8 pad2[9644 - 44]; CallSub s1; u8 pad3[12064 - 9664]; CallSub s2; };

extern "C" {
extern u32 D_0034a6f0; // CallMgr*, kept as an integer (it is reloaded after the u32 stores)
void func_001398d0(s32);
void func_001397d8(s32);
}

// Reset three sub-records of the manager and set bit 0 of each one's c word.
void u_call0_00153158(void) {
    func_001398d0(14);
    func_001397d8(14);
    {
        CallMgr* m = (CallMgr*)D_0034a6f0;
        CallSub* s = &m->s0;
        *(f32*)((u8*)m + 24) = 0;
        *(u32*)((u8*)s + 4) = 0;
        *(u32*)((u8*)m + 32) = 0;
        *(u32*)((u8*)s + 12) = 0;
        s->c |= 1;
        *(u32*)((u8*)m + 40) = 0;
    }
    {
        CallMgr* m = (CallMgr*)D_0034a6f0;
        CallSub* s = &m->s1;
        *(f32*)((u8*)m + 9644) = 0;
        *(u32*)((u8*)s + 4) = 0;
        *(u32*)((u8*)m + 9652) = 0;
        *(u32*)((u8*)s + 12) = 0;
        s->c |= 1;
        *(u32*)((u8*)m + 9660) = 0;
    }
    {
        CallMgr* m = (CallMgr*)D_0034a6f0;
        CallSub* s = &m->s2;
        *(f32*)((u8*)m + 12064) = 0;
        *(u32*)((u8*)s + 4) = 0;
        *(u32*)((u8*)m + 12072) = 0;
        *(u32*)((u8*)s + 12) = 0;
        s->c |= 1;
        *(u32*)((u8*)m + 12080) = 0;
    }
}
