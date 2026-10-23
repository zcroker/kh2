// Batch w2351 functions that need -fno-strict-aliasing (the build compiles *_nsa.cpp with it).
#include "../common/types.h"

#define QCOPY2040(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V2040 {
    f32 x, y, z, w;
    V2040() {}
    V2040(const V2040& o) { QCOPY2040(this, &o); }
    V2040& operator=(const V2040& o) { if (this != &o) QCOPY2040(this, &o); return *this; }
    V2040 operator-(const V2040& b) const {
        V2040 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V2040 operator+(const V2040& b) const {
        V2040 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 normalize() {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
                     : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
    V2040& operator*=(f32 k) {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Q2040 { u8 pad0[12]; s32 f12; V2040 v; };
struct Info2040 { u8 b0; u8 b1; u16 h2; };
struct Res2040 { u8 pad[0x18]; u32 flag : 1; bool isFlag() { return flag; } };
struct Ent2040 { void** vt; };
struct Ctx2040 { u8 pad[8]; void* f8; };
typedef void (*EntFn2040)(Ent2040*, Res2040*);

extern "C" {
s32 func_0018d940(Ctx2040*, Ent2040*);
Info2040* func_00112f88(Ent2040**);
void func_0018a818(Q2040*, Ent2040*, Info2040*);
f32 func_0018a970(Q2040*, V2040);
Res2040* func_0018db38(Ctx2040*, Ent2040*, u16, u8);
void func_0018ca10(Res2040*);
void* func_0016ac80(void*, s32, V2040*, s32, s32);
V2040* func_001dc648(void*);
V2040 func_0017d050(const V2040&);
void func_001c2c00(void*);

}
extern "C" {
// Moves pos toward the target the query found, then runs the entity's hit callback and,
// for id >= 0, spawns effect id at the new position facing dir.
s32 func_001130b0(V2040* pos, Ent2040** pe, Ctx2040* ctx, s32 id) {
    s32 r = 0;
    Res2040* res = 0;
    Ent2040* e = *pe;
    if (func_0018d940(ctx, e) != 0) {
        Info2040* info = func_00112f88(pe);
        if (info != 0) {
            Q2040 q;
            V2040 p;
            V2040 dir;
            V2040* pp = &p;
            V2040* qv = &q.v;
            q.f12 = 0;
            func_0018a818(&q, e, info);
            dir = *qv - *pos;
            f32 d = func_0018a970(&q, *pos);
            dir.normalize();
            dir *= d;
            *pp = *pos + dir;
            pp->w = 1.0f;
            res = func_0018db38(ctx, e, info->h2, info->b1);
            if (res != 0 && !res->isFlag()) {
                r = 1;
                ((EntFn2040)e->vt[25])(e, res);
                if (id >= 0 && ctx->f8 != 0) {
                    void* v = func_0016ac80(ctx->f8, id, pp, 1, 10000);
                    if (v != 0) {
                        *func_001dc648(v) = func_0017d050(dir);
                        func_001c2c00(v);
                    }
                }
            }
        }
    }
    if (res) func_0018ca10(res);
    return r;
}
}

extern "C" {
struct Mem { u8 b[4]; };
struct Sel { u8 a, b, c; u8 pad; u16 d, e, f; };
struct Cmd { s32 f0; u8 b4; u8 p[11]; s32 f10; s32 f14; s32 f18; s32 f1c; };
void func_001a8bb8(Mem*);
s32 func_0019f2a8(Cmd*, Sel*);
Mem* func_001a8bd0(s32);
void func_001a8d40(Mem*, s32);
void func_001d94f8(Mem, Mem*);
void func_001a60c8(void);
void func_002533e0(s32, const void*);
void func_00104f58(Sel*, u32, s32, s32, s32);
void func_001ada38(s32);
void func_00149fe0(s32, u32);
void func_0014a138(s32);
void func_00253180(s32, s32);
extern s8 D_01c62fa0;
extern Mem D_01c62fa8 __attribute__((aligned(4)));
extern s32 D_01c62f98;

void func_0019f070(Cmd* o, u32 a1) {
    Sel s;
    s32 ff = 0xffff;
    s.a = ff; s.b = ff; s.c = ff;
    s.d = ff; s.e = ff; s.f = ff;
    s32 mode = 0;
    if (D_01c62fa0 == 0) {
        func_001a8bb8(&D_01c62fa8);
        D_01c62fa0 = 1;
    }
    u32 fl = 0;
    s32 t = o->f10;
    if (t >= 0) {
        if (t & 0x4000) fl = (t & ~0x4000) | 0x80000000;
        else fl = t;
    }
    s32 v = func_0019f2a8(o, &s);
    fl |= a1;
    switch (o->f0) {
    case 4:
        fl = 1;
        if (v) {
            D_01c62f98 = o->b4;
        } else {
            if (D_01c62f98 >= 0) {
                o->b4 = D_01c62f98;
                D_01c62f98 = -1;
            }
            func_00149fe0(o->b4, 0);
        }
        break;
    case 6:
        func_0014a138(0);
        break;
    case 5:
        func_00253180(15, -1);
        break;
    }
    if (o->f14 >= 0) {
        Mem* m = func_001a8bd0(v ? s.a : -1);
        D_01c62fa8 = *m;
        func_001a8d40(m, o->f14);
        Mem* ps = &D_01c62fa8;
        s32 k = o->f1c;
        if (k != 0) {
            s32 a = 0;
            if (k == 1) goto blk;
            if (k == 2) {
                a = 2;
                func_001d94f8(D_01c62fa8, m);
            blk:
                func_001a60c8();
                func_002533e0(a, ps);
            }
            mode = 2;
        }
    }
    if (v) {
        func_00104f58(&s, fl, mode, 0, o->f18);
    } else if (o->f18) {
        func_001ada38(o->f18);
    }
}
}
namespace w2351 {
struct SprInfo { volatile u16 flags; u8 p2[2]; u8 kind; };
struct Spr { u8 p0[0x198]; s32 tag; u8 p19c[8]; u32 col; };
// 9 bytes per row; the per-slot flag bytes start at +8
struct SprRow { u8 pad[8]; u8 flag[1]; };
struct SprPool { u8 p0[0xa0]; SprRow rows[4]; };
}
using namespace w2351;
extern "C" {
extern s32 D_004573c0[];
s32 func_0013cb30(void);
s32 func_0013cb80(void);
s32 func_0013cb90(void);
Spr* func_0013aca0(s32, s32, s32, s32, s32, u8);
void func_0013ac60(Spr*, u8, s32);
void func_00138c10(Spr*, s32);
void func_00138c40(Spr*, s32, s32);
f32 func_0013b298(u8*);
void func_001395d0(Spr*);
void func_001395e8(Spr*);
s32 func_00313bc0(f32);
void func_00138d48(Spr*, f32, f32, f32, f32);

// Takes the next sprite slot of list idx (creating the sprite on first use), positions it,
// sets its alpha from the fade level and records the info flag for the slot.
Spr* func_0013b5d0(u8* self, s32 idx, s32 c, SprInfo* info, u8 changed, s32 x, s32 y, s32 tag, f32 scale, u32 col, s32 mode) {
    u8 flag;
    u8 kind;
    if (info == 0) {
        flag = 0;
        kind = 0;
    } else {
        kind = info->kind;
        flag = info->flags & 1;
    }
    s32 n = D_004573c0[idx];
    Spr** slot = (Spr**)((idx * 9 + n) * 4 + (u32)self + 0x18);
    Spr* e = *slot;
    s32 s2 = func_0013cb90();
    if (e == 0) {
        s32 s0 = func_0013cb30();
        e = func_0013aca0(c, s0, func_0013cb80(), s2, mode, kind);
        *slot = e;
    } else {
        if (changed == 1) func_00138c10(e, c);
        func_0013ac60(e, kind, s2);
    }
    e->tag = tag;
    func_00138c40(e, x, y);
    f32 r = func_0013b298(self);
    if (r < 1.0f) func_001395d0(e); else func_001395e8(e);
    col &= 0xffffff;
    col |= func_00313bc0(r * 128.0f) << 24;
    e->col = col;
    func_00138d48(e, scale, scale, scale, r);
    ((SprRow*)((u8*)&((SprPool*)self)->rows[idx] + n))->flag[0] = flag;
    D_004573c0[idx]++;
    return e;
}
}
