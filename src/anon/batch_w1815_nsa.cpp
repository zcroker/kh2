#include "../common/types.h"
extern "C" {
void func_0031e2b8(void*);
struct E18cf18 { u8 a[24]; u8 m[24]; ~E18cf18() {} };
struct G18cf18 { E18cf18 e[4]; s32 idx[4]; s32 n; };
extern G18cf18 D_01c60bf0;
void wtarget_0018cf18(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_0018cf18jjjj");
// Static init/destroy (priority 0xffff); the empty destructor loop gets the r5900 short-loop nop padding.
void wtarget_0018cf18(u32 a0, u32 a1, u32 a2, u32 a3) {
    if (a1 == 0xffff && a0 == 1) {
        E18cf18* p = D_01c60bf0.e;
        s32 i = 3;
        do { func_0031e2b8(p->m); i--; p++; } while (i != -1);
        G18cf18* d = &D_01c60bf0;
        for (s32 j = 0; j < 4; j++) d->idx[j] = j;
        d->n = 4;
    }
    if (a1 == 0xffff && a0 == 0) {
        if (D_01c60bf0.e) {
            E18cf18* e = D_01c60bf0.e + 4;
            for (;;) { e->~E18cf18(); if (e == D_01c60bf0.e) break; --e; }
        }
    }
}

struct B178 { u16 id; u16 pad; u32 flags; };
struct D178 { u32 a; B178 b; };
struct O178 {
    void** vt; u8 p4[0xc]; u8 v10[16]; u8 p20[0x10c - 0x20]; u32 f10c; u8 p110[0x160 - 0x110]; u32 f160;
    u8 p164[0x7f8 - 0x164]; u32 f7f8; u8 p7fc[0xb44 - 0x7fc]; D178* b44; u32 b48;
};
void func_00179dd0(O178*, u16);
void func_001991a8(s32, u16);
void* func_00175c88(O178*, B178*);
void func_001bbcf8(void*);
void func_0017a2d0(O178*);
void func_001774e0(O178*);
static inline __attribute__((always_inline)) u32 tA(u32 x) { return x & 4; }
static inline __attribute__((always_inline)) u32 tB(u32 x) { return x & 8; }
static inline __attribute__((always_inline)) u32 tC(u32 x) { return x & 0x10; }
static inline __attribute__((always_inline)) bool busyC(u32 x) { return tA(x) || tB(x) || tC(x); }
// VU0 asm: zero a 128-bit vector (vsub + sqc2), no C equivalent.
void func_001788b8(O178* o) {
    if (!(o->f7f8 & 4)) {
        ((void (*)(O178*))o->vt[0x90 / 4])(o);
        D178* p = o->b44;
        if (p->b.id) {
            o->b48 = 0;
            if (p->b.flags & 0x10) func_00179dd0(o, p->b.id);
            func_001991a8(31, o->b44->b.id);
        }
        void* r = func_00175c88(o, o->b44 ? &o->b44->b : 0);
        if (r) {
            o->f10c &= ~2;
            func_001bbcf8(r);
        }
        u32 x = o->f160;
        bool b = busyC(x);
        if (!b && (s32)x >= 0) {
            asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" :: "r"(o->v10) : "memory");
        }
        func_0017a2d0(o);
    }
    func_001774e0(o);
}

struct V4e9 { f32 x, y, z, w; };
struct V3e9 { f32 x, y, z; };
struct Oe9 { u8 p0[0x80]; u8* f80; };
struct Re9 { u32 a; s32 f4; };
struct Ae9 { u8 p0[0xc]; s32 idx; s32 f10; };
extern Oe9* D_01d9e6e0;
extern u8* D_01d9e6e8;
Re9* func_001e7a98(Oe9*, void*);
void func_002f3cd8(V4e9*, void*, V4e9*);
void func_001e9d48(s32 a0, Ae9* a1, s16* a2) {
    if (a1->idx != -1) {
        Re9* r = 0;
        Oe9* o = D_01d9e6e0;
        void* p = o->f80 + a1->idx * 16;
        if (p) {
            r = func_001e7a98(o, p);
            r->f4 = a0;
        }
        V4e9 v;
        v.x = a2[0]; v.y = a2[1]; v.z = a2[2]; v.w = 1.0f;
        func_002f3cd8(&v, D_01d9e6e8 + 16, &v);
        V3e9* d = (V3e9*)((u8*)r + a1->f10 + 0xa0);
        d->x = v.x; d->y = v.y; d->z = v.z;
    }
}

struct Peb { u16 a0; u16 flags; u8 c[4]; u64 f8; u8* f10; s32 f14; u8 f18; u32 f1c; u8 pad[16]; };
struct Teb { s32 a; s32 b; };
struct A2eb { u8 p0[0xc]; Teb* fc; };
struct A1eb { u32 p0; s32 f4; u8 p8[4]; u8 bc; u8 bd; };
struct Eeb { u8* data; s32 x; };
struct Oeb { u8 p0[0x14]; Eeb* f14; };
extern Oeb* D_01d9e6e4;
extern s32 D_01d9eaa4;
s32 func_0021d048(u8*, Peb*, s32);
void func_001ebb30(u8* a0, A1eb* a1, A2eb* a2) {
    u8* q = a0 + a2->fc->a + 0xa0;
    u8* t = a0 + a2->fc->b + 0xa0;
    if (a1->f4 != 0xffff) {
        Eeb* e = &D_01d9e6e4->f14[a1->f4];
        Peb p;
        p.f10 = D_01d9e6e8 + 80;
        p.f8 = 0;
        p.f18 = 0;
        p.f1c = 0;
        if (!a1->bc) p.flags = 0x80; else p.flags = 0;
        if (a1->bd == 1) p.flags |= 0x10;
        s32 old = D_01d9eaa4;
        p.c[0] = t[8]; p.c[1] = t[9]; p.c[2] = t[10]; p.c[3] = t[11];
        s32 o = *(u16*)(q + 4) * 8;
        u8* d = e->data;
        u8* a = d + *(s16*)(d + o + 16);
        p.f14 = old;
        s32 x = e->x;
        D_01d9eaa4 = func_0021d048(a, &p, x);
    }
}

struct A23 { u32 p0; s16 s4; u8 p6[4]; u16 u10; };
struct E23a { A23* a; void* b; s32 c; };
struct E23b { s32 f0; s32 f4; s32 f8; u8 pc[28]; };
struct T23 { u32 p0; s16 s4; };
struct E23c { T23* p; u32 x; };
extern E23a* D_0035dcec;
extern E23b* D_0035dcfc;
extern E23c* D_0035dce8;
void func_002308c8(A23* a) {
    for (s32 i = 0; i < 64; i++) {
        if (D_0035dcec[i].a == 0) {
            D_0035dcec[i].c = 0;
            for (s32 j = 0; j < 96; j++) {
                if (D_0035dcfc[j].f0 >= 0 && a->s4 == D_0035dcfc[j].f4) D_0035dcec[i].c = D_0035dcfc[j].f8;
            }
            for (s32 k = 0; k < 64; k++) {
                if (D_0035dce8[k].p && D_0035dce8[k].p->s4 == a->u10) {
                    D_0035dcec[i].a = a;
                    D_0035dcec[i].b = &D_0035dce8[k];
                    return;
                }
            }
        }
    }
}
}
