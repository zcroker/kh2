#include "../common/types.h"

struct FV {
    f32 x, y, z, w;
    FV() {}
    FV(const FV& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    FV& operator=(const FV& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct FM {
    FV r[4];
    FV operator*(const FV& v) const {
        FV o;
        asm volatile("lqc2 $vf5, 0(%1)\n\tlqc2 $vf1, 0(%2)\n\tlqc2 $vf2, 16(%2)\n\tlqc2 $vf3, 32(%2)\n\tlqc2 $vf4, 48(%2)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(&v), "r"(this) : "memory");
        return o;
    }
};
struct FTri { u16 x0, v0, v1, v2, v3, plane, x0c, mat; };
struct FPoly { FV* v[4]; s32 n; };
struct FColl {
    u8 pad0[0xc];
    FTri* tris;
    FV* verts;
    u32* mats;
    FV* planes;
    u8 pad1c[0x74];
    FM mtx;
    u8 padd0;
    u8 noMtx;
};
struct FFlags { u64 b0:1; u64 pad:31; u64 hit:1; u64 hi:31; };
struct FRes {
    FV base;
    f32 x10, x14, x18, x1c;
    f32 x20, x24, x28, x2c;
    FV pos;
    u8 pad40[0x20];
    s16 idx;
    u8 pad62[0xa];
    f32 x6c;
    FFlags fl;
    u8 pad78[8];
    f32 x80;
};

extern "C" {
void func_00141988(FColl*, FTri*, FPoly*);
s32 func_00163828(FV*, FV*, FV*);

// Collision triangle hit test: resolves a hit against triangle idx (or a height test when bit 0 is clear).
void func_001419f8(FColl* c, u16 idx, FRes* r, FV* p) {
    if (idx == 0xffff) {
        r->fl.hit = 1;
        r->idx = -1;
        return;
    }
    if (r->fl.b0) {
        // Register pins + no-code asm: the triangle pointer lives in s4 and the index offset stays in t7
        // (without them gcc swaps idx/tri between s3 and s4).
        FTri* tb = c->tris;
        register u32 off asm("$15") = (u32)idx << 4;
        register FTri* t asm("$20") = (FTri*)((u8*)tb + off);
        asm("" : "+r"(t) : "r"(tb), "r"(off));
        FV* pl = &c->planes[t->plane];
        FPoly poly;
        func_00141988(c, t, &poly);
        FV v = r->pos;
        if (!c->noMtx) v = c->mtx * v;
        if (func_00163828(&v, poly.v[0], pl)) {
            r->fl.hit = 1;
        } else {
            if ((*(u32*)((u8*)c->mats + (t->mat << 2)) & 0xf) == 2) r->fl.hit = 1;
            else r->fl.hit = 0;
            r->pos = *p;
        }
    } else {
        f32 z = 0.0f;
        asm("" : "+f"(z)); // no code: keeps mtc1 zero before the q copy

        FV q = r->base;
        f32 d = r->x14;
        if (z < d) q.y += d;
        if (q.y + (r->x6c - r->x24) + r->x80 - 1.0f < p->y) {
            r->fl.hit = 1;
        } else {
            r->fl.hit = 0;
            r->pos = *p;
        }
    }
    r->idx = idx;
}
}
