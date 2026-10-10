#include "../common/types.h"

namespace w228 {
struct V4 {
    f32 x, y, z, w;
    V4(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
};
struct Obj { void** vt; };
struct Hold { u32 pad[5]; Obj* o; };

extern "C" {
// externs
void* func_001b8680(u32, void*);
void func_002edf68(void*);
void func_002c20f8(void*);
void func_002c2168(void*);
extern char D_002be408[];
extern u32 D_003617fc;
extern char D_0034a568[], D_00347e60[], D_00347f98[];
extern Hold* D_00347f80;
void func_00239870(void*);
void func_0031a840(void*);
s32 func_001805a8(u8*, s32);
void func_0017f488(u8*, s32, f32, f32);
void func_0017f5e0(u8*, s32, s32, f32, f32);
void func_0016bd60(u8*, s32);
void func_00290740(u8*);
void func_002362b0(u8*, u32);
void func_002367c8(u8*);  // obj_dispatch_bitfield64
void func_001386e0(u8*, u32, u32, u8*, u32, u32);
void func_002b740c(u32, u32, u32, u32);

void func_002bd8f8(u32* p, u32 a1) {
    p[0] = a1;
    p[1] = (u32)func_001b8680(a1, D_002be408);
    func_002edf68(p + 2);
    p[15] = 0;
    p[26] = 0;
    D_003617fc = (u32)p;
    u32* q = p + 11;
    int i = 3;
    do { *q = 0; i--; q++; } while (i >= 0);
    ((u8*)p)[64] = 0;
    V4 v(0.0f, 0.0f, 0.0f, 0.0f);
    func_002c20f8(&v);
    func_002c2168(&v);
}

void func_0031c2c8(u32* p) {
    p[0] = (u32)D_0034a568;
    p[140] = (u32)D_00347e60;
    func_00239870(p + 146);
    u32* q = p + 12;
    q[0] = (u32)D_00347e60;
    p[140] = (u32)D_00347f98;
    func_00239870(p + 18);
    func_0031a840(q);
    p[0] = (u32)D_00347f98;
    asm volatile("" ::: "memory");
    Obj* o = D_00347f80->o;
    ((void(*)(Obj*, void*))o->vt[1])(o, p);
}

void func_001843d8(u8* p) {
    u8* m = p + 320;
    if (!(*(u32*)(p + 360) & 0x10)) {
        if (func_001805a8(m, 5)) {
            func_0017f488(m, 5, 0.0f, 0.0f);
            func_0017f5e0(m, 0, 0, 0.0f, 0.0f);
        }
    }
    func_0016bd60(p, 0);
    *(u32*)(p + 264) |= 0x08000000;
}

void Selector_CreateHelpGra(u8* t, u32 a1, u32 a2, u32 a3) asm("_ZN2Tz8Selector13CreateHelpGraEz");
void Selector_CreateHelpGra(u8* t, u32 a1, u32 a2, u32 a3) {
    func_00290740(t);
    u8* s0 = t + 416;
    func_002362b0(s0, a2);
    func_002367c8(s0);  // obj_dispatch_bitfield64
    func_001386e0(t, *(u32*)(t + 408), a1, s0, a3, 0);
    u32* q = (u32*)(t + 24);
    q[46] |= 8;
    t[405] = 1;
}

s32 func_002bb8b0(u8* p) {
    if (p[49] == 3) return *(s16*)(p + 40);
    func_002b740c(*(u32*)(p + 24), *(u32*)(p + 16), *(u32*)(p + 20), 0);
    u32 fl = *(u32*)(p + 36);
    s32 v;
    if (fl & 4) v = (s32)((f32)*(s16*)(p + 40) * 0.8f);
    else v = *(s16*)(p + 40);
    if (fl & 8) {
        func_002b740c(*(u32*)(p + 24), *(u32*)(p + 16), *(u32*)(p + 20), 1);
        return 0;
    }
    return v;
}
}
}
