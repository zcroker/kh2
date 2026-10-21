#include "../common/types.h"
struct Obj1dc;
struct Vt1dc { s32 (*f0)(Obj1dc*, s32, s32); };
struct Obj1dc { Vt1dc* vt; };
struct Pair1dc { s32 a; s32 b; };
struct V143 {
    f32 x, y, z, w;
    V143() {}
    V143& operator=(const V143& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline V143 v143_sub(const V143& a, const V143& b) {
    V143 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct O143 {
    V143 v0;
    V143 v10;
    V143 v20;
    V143 v30;
    u8 pad40[0x22];
    s16 h62;
    s16 h64;
    s16 pad66;
    f32 f68;
    s32 pad6c;
    u64 flags;
    s32 i78;
};
struct E1bc { u8 pad0[4]; s16 h4; u8 pad6[0x16]; u8 b1c; };
struct T1bc { u8 pad[8]; u32 f8; };
struct P1bc { u8 pad[0x1b1]; u8 b1b1; };
struct B1bc { u8 pad0[0xc]; T1bc* t; u8 pad10[0x48c - 0x10]; P1bc* p; u8 pad490[0x588 - 0x490]; u32 f588; u8 pad58c[0xb50 - 0x58c]; s32 mode; };
struct S1f5 { s16 x, y, z; };
struct A1f5 { u8 pad[0xc]; s32 idx; s32 off10; s32 pad14; s32 off18; };
struct M1f5 { u8 pad[0x80]; u8* tbl; };
struct R1f5 { s32 f0; s32 f4; };
extern "C" {
extern Obj1dc* D_01d5bb00;
extern s32 D_01d5bb04;
extern s32 D_01d5bb08;
extern Pair1dc D_00352ae0;
extern s32 D_00352ae8;
void func_001e6d38(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1, u32 t2, u32 t3, u32 s0, u32 s1, u32 s2, u64 c,
                   u64 d0, u64 d1, u64 d2, u64 d3, u64 d4, u64 d5);
extern s32 D_00348804;
s32 func_00165a10();
s32 func_00164718(s32, O143*);
s32 func_00165ad8(O143*, f32*);
s32 func_001424c0(s32, O143*);
extern u8 D_00351eb8[];
extern u8 D_00351ec0[];
extern u32 D_0034f240;
s32 elem_is_menu(E1bc*) asm("_ZNK2YS12COMMAND_ELEM7is_menuEv");
s32 func_001c8db8(void*, s32);
s32 func_0019ba60(B1bc*);
s32 func_001c9b38(E1bc*);
s32 func_001bbf40(void);
extern M1f5* D_01d9e6e0;
extern u8* D_01d9e6e8;
R1f5* func_001e7a98(M1f5*, u8*);
void func_002226b8(void*, f32*);
void func_002f3cd8(f32*, void*, f32*);
void func_002f3f10(f32*, f32*, void*);
void func_002f3d98(f32*, f32*);
struct S8 { s16 a, b, c, d; };
union US8 { S8 s; u32 u; };
u8 func_00263cc0(void);
void func_0028b520(void*, u32, u32, u32, u32, void*, void*, s32, s32, s32);
u32 func_0023aa18(u32);
u32 func_0023aa38(u32);
void func_00138c68(void*, u32, u32);
void func_001395f8(void*);
void func_00138c10(void*, s32);
extern u32 D_0035f3d4, D_0035f0bc, D_0035f0b8, D_0035f0c0;
extern S8 D_0035f0c8;
extern US8 D_0035f0d0_ asm("D_0035f0d0");
#define D_0035f0d0 D_0035f0d0_.s
union UP { u8* p; u32 u; };
extern UP D_0035f0dc;
#define G D_0035f0dc.p

void func_001dcdb8(Obj1dc* o, s32 a, s32 b) {
    D_01d5bb00 = o;
    D_01d5bb04 = o->vt->f0(o, a, 0);
    D_01d5bb08 = D_01d5bb00->vt->f0(D_01d5bb00, b, 0);
    func_001e6d38(D_01d5bb04, a, D_01d5bb08, b, 512, 448, 512, 416, 112, 216, 0, 0x800d8, 0x31000070,
                  0x730000007000ULL, 0x19f000001ff0000ULL, 0x5000d, 0, 1);
    Pair1dc* p = &D_00352ae0;
    p->a = 0;
    p->b = 0;
    D_00352ae8 = 0;
}

s32 func_00143928(O143* o) {
    o->h64 = -1;
    o->flags &= ~(1ULL << 34);
    f32 t = 10000000.0f;
    o->h62 = -1;
    s32 r = func_00165a10() | func_00164718(D_00348804, o);
    o->i78 = 0;
    if (func_00165ad8(o, &t) == 0) {
        if (func_001424c0(D_00348804, o)) o->i78 = 0;
    } else {
        o->v10 = v143_sub(o->v30, o->v0);
        r |= func_00164718(D_00348804, o);
    }
    if (t != 10000000.0f) {
        o->f68 = t;
        o->flags &= ~(1ULL << 33);
    }
    return r;
}

s32 func_001bc568(E1bc* e, B1bc* b) {
    if (elem_is_menu(e)) return 1;
    if (func_001c8db8(D_00351eb8, 0) || func_001c8db8(D_00351ec0, 0)) return 0;
    if (func_0019ba60(b) == 0 || (b->f588 & 0x1000000) == 0) return 0;
    if (func_001c9b38(e) || (b->t->f8 & 0x20)) return 0;
    switch (b->mode) { case 7: case 12: return 0; }
    if (e->h4 == 3) {
        if (func_001bbf40()) return 0;
    }
    s32 r = 0;
    if (!(D_0034f240 & 0x40000)) { s32 lt = (b->p->b1b1 < e->b1c); r = !lt; }
    return r;
}

void func_001f5f10(s32 id, A1f5* a, S1f5* s) {
    f32 v[4] __attribute__((aligned(16)));
    R1f5* r = 0;
    u8* p = D_01d9e6e0->tbl + a->idx * 16;
    if (p) {
        r = func_001e7a98(D_01d9e6e0, p);
        r->f4 = id;
    }
    u8* d0 = (u8*)r + a->off10 + 0xa0;
    u8* d1 = (u8*)r + a->off18 + 0xa0;
    v[0] = s->x;
    v[1] = s->y;
    v[2] = s->z;
    v[3] = 1.0f;
    func_002f3cd8(v, D_01d9e6e8 + 16, v);
    func_002226b8(d0, v);
    func_002f3f10(v, v, D_01d9e6e8 + 64);
    func_002f3d98(v, v);
    func_002226b8(d1, v);
}

void func_00263a90(u32 a0, u8 a1) {
    if (func_00263cc0() == 0) {
        u32 p1 = D_0035f3d4;
        func_0028b520(G, p1, D_0035f0bc, D_0035f0b8, D_0035f0c0, &D_0035f0c8, &D_0035f0d0, D_0035f0d0.d, -1, 0);
        *(u32*)(G + 0x198) = a0;
        if (a1) {
            u32 h = *(u32*)(G + 0x190);
            u32 x = func_0023aa18(h);
            func_00138c68(G, x, func_0023aa38(h));
        }
        func_001395f8(G);
        return;
    }
    *(u32*)(G + 0x198) = a0;
    if (*(s32*)(G + 0x184) != D_0035f0d0.d) {
        func_00138c10(G, D_0035f0d0.d);
        *(s32*)(G + 0x188) = -1;
    }
}

}
