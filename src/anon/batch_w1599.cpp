#include "../common/types.h"
namespace n002a2010 {
struct El {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual ~El();
    u8 pad[432];
};
struct Ab {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual ~Ab();
    u8 pad[0x194];
};
extern "C" {
extern void* D_0035f5e4;
extern u8* D_0035f5e8;
extern u8 D_00347e60[];
extern u8 D_00347f98[];
void func_00106420(void*);
void func_0031acc0(void*);
void func_00239870(void*);

void func_002a2010(void) {
    if (D_0035f5e4) { func_00106420(D_0035f5e4); D_0035f5e4 = 0; }
    u8* q = D_0035f5e8;
    if (q) {
        if (q + 0x88c8) {
            El* e = (El*)(q + 0x981c);
            El* end = (El*)(q + 0x88c8);
        t1:
            if (end == e) goto o1;
            e--;
            e->~El();
            goto t1;
        o1:;
        }
        if (q + 0x7974) {
            El* e = (El*)(q + 0x88c8);
            El* end = (El*)(q + 0x7974);
        t2:
            if (end == e) goto o2;
            e--;
            e->~El();
            goto t2;
        o2:;
        }
        Ab* a = (Ab*)(q + 0x72c0);
        func_0031acc0(q + 0x77c0);
        func_0031acc0(q + 0x760c);
        func_0031acc0(q + 0x7458);
        *(u8**)(q + 0x72c0) = D_00347e60;
        func_00239870(q + 0x72d8);
        *(u8**)(q + 0x72c0) = D_00347f98;
        if (q) {
        t3:
            if ((Ab*)q == a) goto o3;
            a--;
            a->~Ab();
            goto t3;
        o3:;
        }
        func_00106420(q);
        D_0035f5e8 = 0;
    }
}
}
}

namespace n002ac2e8 {
struct Ent { u8 a; u8 b; u8 pad[6]; u16 id; };
struct Bits {
    u32 w[2];
    s32 Test(u32 b) { return w[b >> 5] & (1 << (b & 31)); }
    void Set(u32 b) { u32* p = &w[b >> 5]; *p |= 1 << (b & 31); }
};
struct Flags { u8 pad[0x144]; Bits x[10]; Bits y[10]; };
extern "C" {
extern Flags* D_0035f610;
Flags* func_002a9d68(void);
Ent* func_001d9e30(Ent*);
s32 func_001d9d48(Ent*);
s32 func_00181500(u16);

void func_002ac2e8(void) {
    Ent* e = 0;
    Flags* f = func_002a9d68();
    while ((e = func_001d9e30(e)) != 0) {
        if (func_001d9d48(e)) {
            if (!f->x[e->a].Test(e->b)) D_0035f610->x[e->a].Set(e->b);
        }
        if (func_00181500(e->id)) {
            if (!f->y[e->a].Test(e->b)) D_0035f610->y[e->a].Set(e->b);
        }
    }
}
}
}

namespace n0028cc78 {
struct Sub { u8 pad[184]; u32 flags; };
struct Ent { u8 pad[24]; Sub sub; u8 pad2[408 - 24 - 188]; };
struct Pair { s16 a, b; };
union GP { Pair* p; s16 h; };
union GE { Ent* p; u32 w; s16 h; };
struct Obj { u8 pad[40]; s32 x28; };
extern "C" {
extern GE D_0035f3fc;
extern GP D_0035f400;
union GW { u32* p; s16 h; };
extern GW D_0035f408;
extern s32* D_0035f40c;
extern u32 D_0035f410;
Obj* func_0023f1b0(u8*);
s32 func_0023c4b8(Obj*, s32);
u8* func_00236ca8(s32, s32);
void func_001386e0(Ent*, s32, s32, u8*, s32, s32);
static inline void setf(Sub* s) { s->flags |= 8; }
void func_0028cc78(s32 idx, s32 a1, s32 a2, u8* a3, s32 a4, s32 a5) {
    s32 r1 = func_0023c4b8(func_0023f1b0(a3), a1);
    u8* r2 = func_00236ca8(func_0023f1b0(a3)->x28, a2);
    func_001386e0(&D_0035f3fc.p[idx], D_0035f40c[idx], r1, r2, a4, 0);
    D_0035f400.p[idx].a = a4;
    D_0035f400.p[idx].b = a5;
    D_0035f408.p[idx] = 0;
    D_0035f410 &= ~(1 << idx);
    if (r2[400]) setf(&D_0035f3fc.p[idx].sub);
}
}
}
