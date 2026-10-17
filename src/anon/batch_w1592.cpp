#include "../common/types.h"

struct Q1592 { u8 v[16] __attribute__((aligned(16))); Q1592() {} ~Q1592() {} };
struct B1592 { u64 a, b, c, d; Q1592 q[2]; f32 f; B1592() {} };

extern "C" {
union U1592W { u32 w; u8 c; };
union U1592H { u16 h; u8 c; };
struct S1592 { u8 p0[4]; s16 n; u8 p6[8]; s16 e; u8 p10[6]; s16 m; u8 p18[0x10]; U1592W* a; U1592H* b; U1592H* c; };

void func_00288ce0(S1592* s, u32 x, s32 i, u16* p, u16* q) {
    s32 j;
    s->a[i].w = x;
    if (i >= s->n) s->n = i + 1;
    for (j = 0; j < 4; j++) {
        s->b[i * 4 + j].h = p ? p[j] : 0xffff;
        s->c[i * 4 + j].h = q ? q[j] : s->b[i * 4 + j].h;
    }
    s->e = 0;
    s->m = s->n;
}

void* func_00167f18(s32);
void func_00323af8(B1592*, void*);
s32 func_00288040(void);
u64* func_00288008(void);

s32 func_0028b258(u32 m) {
    B1592 b;
    func_00323af8(&b, func_00167f18(0));
    if (func_00288040()) b.a |= *func_00288008();
    return (b.a & m) != 0;
}

struct E1592b { u16 id; u16 p[3]; };
struct T1592b { s8 n; u8 pad[0x4f]; E1592b e[1]; };
extern T1592b* D_0035f5d4;
void func_002a18d0(void);
s32 func_002a9e98(u16);
s32 func_002a9f50(u16);

s32 func_002a1b18(void) {
    s32 i = 0; s32 r = 0;
    func_002a18d0();
    for (; i < D_0035f5d4->n; i++) {
        u16 id = D_0035f5d4->e[i].id;
        if (func_002a9e98(id)) {
            r = 1;
            if (!func_002a9f50(id)) break;
            r = 2;
        }
    }
    return r;
}

s32 func_002538f8(void*);
s32 func_00253928(void*);
s32 func_00253918(void);
s32 func_002539e8(void*, s32);
void func_00102448(void*, s32);

s32 func_002593b8(void* a, void* t) {
    if (func_002538f8(a)) return 1;
    if (!func_00253928(a)) {
    top:
        if (!func_00253918() && !func_002539e8(a, 0)) goto out;
        func_00102448(t, 0); goto top;
    }
out:
    if (!func_002538f8(a)) { func_00102448(t, 0); goto out; }
    return 1;
}


s32 func_00287bc0(void);
u32 func_00257070(s32);
s32 func_00286418(s32);
void func_002865d0(s32);

void func_00266b58(void) {
    s32 n;
    if (func_00287bc0() != 24) return;
    switch (func_00257070(23)) {
    case 1: n = 0; break;
    case 2: n = 1; break;
    case 3: n = 2; break;
    case 4: n = 3; break;
    case 5: n = 4; break;
    default: return;
    }
    if (func_00286418(n)) func_002865d0(n);
}


struct O1592 { u8 p[0x188]; s32 v; };
struct S1592b { u8 p0[0x28]; O1592** a; s16 (*b)[4]; s16 (*c)[4]; };
void func_00138c10(O1592*, s32);

void func_00289038(S1592b* s, s32 i, u8 sel, u8 f1, s32 x, u8 f2, s32 y) {
    O1592* o = s->a[i];
    if (o) {
        s16* t = (sel ? s->c : s->b)[i];
        func_00138c10(o, f1 ? t[x] : x);
        o->v = f2 ? t[y] : y;
    }
}


extern s8 D_0035f0b5;
s32 func_00257130(void);
void func_00282240(s32, s32, s32);
void func_00282d70(s32);

void func_002634d8(s32 a) {
    s32 n;
    if (a < 0) a = D_0035f0b5;
    switch (a) {
    case 2: n = 11; break;
    default:
    case 0: n = 0; break;
    case 1: n = 13; break;
    case 3: n = 12; break;
    case 4: n = 14; break;
    }
    func_00282240(func_00257130(), 0, n);
    func_00282d70(func_00257130());
}

}

// ---- 002a4d48: frees two owned buffers (array delete of 436-byte polymorphic elements)
namespace n002a4d48 {
struct Heap { void (**vt)(Heap*, void*); };
struct HeapHolder { u8 pad[20]; Heap* heap; };
extern "C" HeapHolder* D_00347f80;
struct El {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual ~El();
    u8 pad[432];
    static void operator delete[](void* p) { D_00347f80->heap->vt[1](D_00347f80->heap, p); }
};
extern "C" {
extern void* D_0035f5ec;
extern El* D_0035f5f0;
void func_00106420(void*);
void func_002a4d48(void) {
    if (D_0035f5ec) { func_00106420(D_0035f5ec); D_0035f5ec = 0; }
    if (D_0035f5f0) { delete[] D_0035f5f0; D_0035f5f0 = 0; }
}
}
}
