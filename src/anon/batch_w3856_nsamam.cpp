// 0011d740: draw a null-terminated list of child models under a parent matrix with GS register setup, then the owner model. Built as _nsamam (-fno-strict-aliasing -fmove-all-movables).
// Partial asm: VU0/lq-sq helpers (lq/sq copies, vmul) and one empty asm memory barrier after the pkt.zbuf store (keeps the flags load after the sd and keeps gcse sharing).
// In the loop desc->flags is read through the Pkt type: different fields of one struct type do not alias, so the load loses its anti-dependences on the pkt stores and issues beside the mult as in the original.
#include "../common/types.h"
extern "C" {
struct V11d740 {
    f32 x, y, z, w;
    V11d740() {}
    V11d740& operator*=(f32 s) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "f"(s) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct M11d740 {
    V11d740 r[4];
    M11d740() {}
    M11d740& operator=(const M11d740& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    static void mul(M11d740* o, const M11d740* a, const M11d740* b) {
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
            "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
            "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)" : : "r"(o), "r"(a), "r"(b) : "memory");
    }
    M11d740 operator*(const M11d740& b) const {
        M11d740 o;
        mul(&o, this, &b);
        return o;
    }
} __attribute__((aligned(16)));
struct Desc11d740 {
    u32 flags;
    bool lit() const { return flags & 1; }
    u8 ulit() const { u32 f = flags; return f & 1; }
    u8 b4, b5, b6, b7;
    u8 pad8[8];
    u64 a16;
    u64 a24;
};
struct Pkt11d740 {
    s32 kind;
    u8 r, g, b, a;
    u8 c8[4];
    u8 pad12[4];
    u64 frame;
    u64 zbuf;
    s32 f32, f36;
    u8 c40[4];
    s32 f44, f48, f52;
};
struct Seq11d740 { s32 id; };
struct Self11d740;
struct Mdl11d740 {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5();
    virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12();
    virtual void begin(s32, s32);
    virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18();
    virtual s32 draw(M11d740*, s32, Pkt11d740*, s32, s32, s32, s32);
    virtual s32 draw2(M11d740*, s32, Pkt11d740*, s32, s32, s32, s32);
    virtual void f21();
    virtual s32 drawm(s32, s32, Desc11d740*, s32, s32, M11d740*);
    Seq11d740* seq;
};
struct Self11d740 {
    u8 pad0[20];
    Mdl11d740* mdl;
    u8 pad1[52 - 24];
    s32 p52;
    s32 p56;
    u8 pad2[260 - 60];
    s32 base;
    s32 tbl;
};
struct Item11d740 {
    Self11d740* obj;
    u8 pad4[11];
    u8 alpha;
    u8 pad16[52 - 16];
    s32 f52;
    u8 pad56[8];
    M11d740 m;
};
s32 func_0010ae90();
void func_0010a918(s32);
void func_00108698(Pkt11d740*);
Mdl11d740* func_00124748(Mdl11d740*, u32);
void func_0010ab08(s32);
void func_00134408();
void func_00134428(s32, u64);
void func_00134450(s32);
void func_00108998(s32);
void func_0011f120(Mdl11d740*, s32);
void func_0011f1a8(Mdl11d740*, s32);
// draw a null-terminated list of child models under a parent matrix, then the owner's own model
void func_0011d740(Self11d740* s, s32 a1, Desc11d740* desc, s32 a3, M11d740* own, M11d740* parent, Item11d740** list, s32 mode)
{
    s32 pk = func_0010ae90();
    if (list) {
        func_0010a918(mode);
        M11d740 local;
        Pkt11d740 pkt;
        func_00108698(&pkt);
        u64 v;
        switch (mode) {
        case 0: v = 0x10140; break;
        case 1: v = 0x20140; break;
        case 2: v = 0x40140; break;
        default: v = 0; break;
        }
        pkt.frame = v;
        switch (mode) {
        case 0: v = 0x30000142; break;
        case 1: v = 0x30000148; break;
        case 2: v = 0x30000160; break;
        default: v = 0; break;
        }
        pkt.zbuf = v;
        asm volatile("" ::: "memory");
        u32 fl = desc->flags;
        pkt.kind = 2;
        u8 b = fl & 1;
        if (!b) {
            pkt.r = 0;
            pkt.g = 0;
            pkt.b = 0;
        }
        pkt.a = desc->b7;
        for (Item11d740** p = list; *p; p++) {
            local = (*p)->m;
            local.r[1] *= -1.0f;
            local.r[2] *= -1.0f;
            local = *parent * local;
            Self11d740* o = (*p)->obj;
            Mdl11d740* m = o->mdl;
            if (m->seq->id == -1) {
                m = func_00124748(m, 0);
                if (!m) m = o->mdl;
            }
            Item11d740* it = *p;
            s32 al = it->alpha * desc->b7;
            pkt.f44 = it->f52;
            u32 fl2 = ((Pkt11d740*)desc)->kind; // desc->flags
            u8 c = fl2 & 1;
            pkt.a = al >> 7;
            if (c) {
                pkt.f36 = o->p52;
                if (!m->draw(&local, o->tbl, &pkt, o->base, s->p56, 0, 0))
                    m->draw(&local, o->tbl, &pkt, o->base, s->p56, 1, 0);
            } else {
                if (!m->draw2(&local, o->tbl, &pkt, o->base, s->p56, 0, 0))
                    m->draw2(&local, o->tbl, &pkt, o->base, s->p56, 1, 0);
            }
        }
        if (!(desc->lit())) func_0010ab08(mode);
        func_00134408();
        func_00134428(76, 0x800d8);
        func_00134428(78, 0x31000070);
        func_00134428(71, 0x5000d);
        func_00134428(24, 0x730000007000ULL);
        func_00134428(64, 0x019f000001ff0000ULL);
        func_00134450(1);
    }
    func_00108998(pk);
    func_00134408();
    u64 t;
    if (!(desc->lit())) {
        switch (mode) {
        case 0: t = 0x598006840ULL; break;
        case 1: t = 0x5dc00a900ULL; break;
        case 2: t = 0x620012c00ULL; break;
        default: t = 0; break;
        }
    } else {
        switch (mode) {
        case 0: t = 0x598006800ULL; break;
        case 1: t = 0x5dc00a800ULL; break;
        case 2: t = 0x620012800ULL; break;
        default: t = 0; break;
        }
    }
    func_00134428(6, t);
    func_00134428(66, 0x8000000044ULL);
    func_00134428(76, desc->a16);
    func_00134428(78, desc->a24 | 0xff00000000000000ULL);
    func_00134428(71, 0x5000d);
    func_00134450(1);
    desc->b7 = 0x80;
    func_0011f120(s->mdl, s->base);
    s->mdl->begin(s->base, a3);
    M11d740 local2;
    local2 = *own;
    if (!s->mdl->drawm(a1, s->tbl, desc, s->base, 0, &local2))
        s->mdl->drawm(a1, s->tbl, desc, s->base, 1, &local2);
    func_0011f1a8(s->mdl, s->base);
}


}
