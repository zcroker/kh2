#include "../common/types.h"
extern "C" {

void func_002d0ea8(void*);
extern u8 D_003622c0[];

typedef struct V4_w3717 { f32 x, y, z, w; } V4_w3717;
typedef struct O2d4_w3717 {
    void* vt;
    u8 pad[0xbec];
    union { s32 i; f32 f; } bf0;
    u8 pad2[0xc];
    V4_w3717 c00;
    f32 c10;
    f32 c14, c18, c1c;
    u8 pad3[0x10];
    f32 c30, c34;
} O2d4_w3717;

// Constructor: base init, vtable, then clears the colour/scale fields.
// The empty asm ties the x store to the c10 store (the original stores x after c10
// although it is independent); v is pinned to $f1 as in the original.
void func_002d49c0(O2d4_w3717* o) {
    func_002d0ea8(o);
    o->vt = D_003622c0;
    o->bf0.i = 0;
    V4_w3717* q = &o->c00;
    register f32 v asm("$f1") = o->bf0.f;
    q->y = v;
    q->z = v;
    q->w = v;
    o->c34 = 0.0f;
    o->c14 = 0.0f;
    o->c18 = 0.0f;
    o->c1c = 0.0f;
    o->c30 = 0.0f;
    o->c10 = 0.004f;
    asm("" : "+f"(v) : "m"(o->c10));
    q->x = v;
}

u8* func_002766d0(void);
s32 func_0023aa18(u8*);
s32 func_0023aa38(u8*);
s32 func_0023f1b0(s32);
s32 func_0023c4b8(s32, s32);
s32 func_0023f988(s32, s32);
void func_002362b0(u8*, s32);
void func_001386e0(u8*, s32, s32, u8*, s32, s32);
void func_00139620(u8*);
void func_0028dcc0(u8*, u8*);
void func_00138c68(u8*, s32, s32);
extern u8 D_0035f590;
extern u8 D_0035f591;
extern s32 D_0035f3d4;
extern s32 D_0035f210;
extern s32 D_0035f58c;
extern s32 D_00374738;
extern s32 D_0037473c;
extern s32 D_00374740;
extern s32 D_00374744;
extern s32 D_00374748;
extern s32 D_0037474c;

// Sets up the two party-member panels (i = 0, 1) once, then marks D_0035f591.
// Register pins (p in s7, d in t7, the constant 1 in t6) and the empty asms reproduce the
// original's register choice and scheduling; the else arm reads D_00374738 through a hidden
// high half (0x370000 + 0x4738) so its lui is issued before id = d + 1.
void func_00296b80(u8 flag) {
    u8* w = func_002766d0();
    if (D_0035f590 == 0) return;
    if (D_0035f591 != 0) return;
    u8* q0 = w + 0x18;
    s32 i = 0;
    s32 a = func_0023aa18(q0);
    register u8* p asm("$23") = w + 0x4398;
    s32 b = func_0023aa38(q0);
    do {
        register s32 d asm("$15") = D_0035f3d4;
        s32 id = d;
        id += 2;
        s32 m;
        if (i == 0) { m = D_0037473c; }
        else {
            u32 hb = 0x370000;  // &D_00374738 high half
            asm volatile("" : "+r"(hb));
            id = d + 1;
            asm volatile("");
            m = *(s32*)(hb + 0x4738);
        }
        s32 c = func_0023c4b8(func_0023f1b0(D_0035f210), m);
        s32 e = func_0023f988(D_0035f58c, i);
        u8* q = w + i * 0x1a0 + 0xdca0;
        func_002362b0(q, e);
        register u8 one asm("$14") = 1;
        q[0x190] = one;
        s32 x, y;
        if (flag) {
            x = i == 0 ? D_00374748 : D_00374740;
            y = i == 0 ? D_0037474c : D_00374744;
        } else {
            x = i == 0 ? D_0037474c : D_00374744;
            y = -1;
        }
        u8* ob = w + i * 0x198;
        u8* o = ob + 0x4398;
        u8* o2 = ob + 0x43b0;
        func_001386e0(o, id, c, w + i * 0x1a0 + 0xdca0, x, 0);
        *(s32*)(o + 0x188) = y;
        func_00139620(o);
        *(u32*)(o2 + 0xb8) |= 8;
        o[0x195] = 1;
        if (i == 0) {
            func_0028dcc0(p, w);
            func_00138c68(p, a, b);
        } else {
            func_0028dcc0(o, w + 0x330);
        }
        i++;
    } while (i < 2);
    D_0035f591 = 1;
}

}
