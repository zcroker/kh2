#include "../common/types.h"

// YS::PRIZE (prize effect set) and YS::PRIZE_CA, first part (0x1cc048-0x1cc3b8): the effect set's
// constructor and destructors, prize spawning, and the pick-up hand-over. The burst spawners after
// it (0x1cc3b8, 0x1cc5c8) are still separate functions; unit_001cc868.cpp and unit_001cd078.cpp continue the file.

struct Vn1cc0 {
    f32 x, y, z, w;
    Vn1cc0& operator=(const Vn1cc0& o) {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

struct PrizeSet;
struct PrizeSetVt { void* f[22]; void (*take)(PrizeSet*, u8*); };
struct PrizeSet { PrizeSetVt* vt; };

struct O1cc220 { u8 pad[0x588]; u32 flags; u8 pad2[0x7f8 - 0x58c]; u32 flags2; };

extern "C" {
extern u8 D_00352060;
extern void* D_00352050;
extern u8 D_0036e228[];
extern f32 D_0036d4a8;
u32 func_001a4db0(u32, u32, u32, u32);
u32 func_001a4e30(...);
void func_001a4e30_v(void*) asm("func_001a4e30");
void func_00105110(void*);
u8* func_001a5420(void*, u8*, void*);
Vn1cc0 func_0016bda8(u8*);
s32 o1cc220_get_entry_id(void*) asm("_ZN2YS3OBJ12get_entry_idEv");
O1cc220* func_00186078(O1cc220*);
s32 c1cc220_00186ce8(O1cc220*) asm("_Z16ctarget_00186ce8jjjj");
s32 func_00186d18(O1cc220*);
s32 func_001c7950(void*, O1cc220*, f32, f32);
void func_001c79a0(void*, O1cc220*, s32);
s32 func_001991a8(s32, s32);
void func_001c71f8(u8*, f32);
s32 func_001cc358(void);

u32 func_001cc048(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    r6 = (u32)((s32)0u + (256));
    r7 = (u32)((s32)0u + (96));
    r16 = r4;
    r2 = func_001a4db0(r4, r5, r6, r7);
    r15 = (u32)&D_00352060;
    r14 = (u32)(0x0035u << 16);
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    *(u32*)((u32)r14 + (s32)(8272)) = r16;
    return r2;
}

u32 func_001cc088(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r13, r14;
    r14 = (u32)&D_00352060;
    *(u32*)((u32)r4 + (s32)(0)) = r14;
    r13 = (u32)(0x0035u << 16);
    *(u32*)((u32)r13 + (s32)(8272)) = 0u;
    u32 (*fp_call4_001a4e30)(u32, u32, u32, u32) = func_001a4e30;
    r2 = fp_call4_001a4e30(r4, r5, r6, r7);
    return r2;
}

u32 func_001cc0b8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r13, r14;
    r14 = (u32)&D_00352060;
    *(u32*)((u32)r4 + (s32)(0)) = r14;
    r13 = (u32)(0x0035u << 16);
    *(u32*)((u32)r13 + (s32)(8272)) = 0u;
    u32 (*fp_call4_001a4e30)(u32, u32, u32, u32) = func_001a4e30;
    r2 = fp_call4_001a4e30(r4, r5, r6, r7);
    return r2;
}

void func_001cc0e8(void** self) {
    *self = &D_00352060;
    D_00352050 = 0;
    func_001a4e30_v(self);
    func_00105110(self);
}

u8* PrizeSetAppear(void* self, void* pos) asm("_ZN2YS5PRIZE6appearEPKNS_11PRIZEEFFECT5PARAMERKN2kn7FVectorE");
u8* PrizeSetAppear(void* self, void* pos)
{
    u8* p = func_001a5420(self, D_0036e228, pos);
    if (p) *(u32*)(p + 40) |= 4;
    return p;
}

// Spawn up to n prizes at the object's position.
void PrizeAppear(u8* obj, s32 n) asm("_ZN2YS8PRIZE_CA6AppearEPNS_6BTLOBJEi");
void PrizeAppear(u8* obj, s32 n)
{
    if (*(s32*)(obj + 2760) < n) n = *(s32*)(obj + 2760);
    if (!D_00352050) return;
    if (n == 0) return;
    Vn1cc0 pos;
    pos = func_0016bda8(obj);
    s32 i;
    for (i = 0; i < n; i++) {
        u8* p = PrizeSetAppear(D_00352050, &pos);
        if (!p) return;
        *(u32*)(p + 16) = (u32)func_001cc358;
        (*(s32*)(obj + 2760))--;
    }
}

s32 func_001cc310(O1cc220* p, void* target);

// Find the first object in range that can be targeted and hand it over.
s32 func_001cc220(void* self, void* target)
{
    bool special = o1cc220_get_entry_id(self) == 0x898;
    O1cc220* p = 0;
    while ((p = func_00186078(p)) != 0) {
        if (!(p->flags & 0x80)) {
            if (!(p->flags & 0x10)) continue;
            if (!special) continue;
        }
        if (p->flags2 & 4) continue;
        if (c1cc220_00186ce8(p)) continue;
        if (func_00186d18(p)) continue;
        if (!func_001c7950(target, p, D_0036d4a8, 0.0f)) continue;
        return func_001cc310(p, target);
    }
}

s32 func_001cc310(O1cc220* o, void* b)
{
    func_001c79a0(b, o, 0);
    (*(s32*)((u8*)o + 0xac8))++;
    return func_001991a8(0x11, 0);
}

// The prize's per-frame callback (set by PRIZE_CA::Appear).
s32 func_001cc358(void)
{
    u8* p;
    func_001c71f8(p, -0.5f);
    if (p[68] >= 2) { PrizeSet* s = (PrizeSet*)D_00352050; s->vt->take(s, p); }
    return 1;
}
}
