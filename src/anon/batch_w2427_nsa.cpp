#include "../common/types.h"
extern "C" {
struct V115848 {
    f32 x, y, z, w;
    V115848 operator*(f32 k) const
    {
        V115848 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    V115848& operator+=(const V115848& b)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory");
        return *this;
    }
    void zero() { asm volatile(".set noreorder\n\tvsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this) : "memory"); }
};
struct Tgt115848;
void func_00190128(Tgt115848*);
struct Tgt115848 {
    s32 f0, f4, f8, f12, f16;
    Tgt115848() { func_00190128(this); }
};
struct Parm115848 { u8 pad[4]; f32 f4; u8 pad2[8]; f32 f16; f32 f20; };
struct Ent115848;
struct Who115848;
typedef s32 (Who115848::*Pick115848)(Ent115848*, Tgt115848*, s32*, s32);
struct Ent115848 { u32 flags; Pick115848 pick; };
struct Who115848 {
    u8 pad0[20];
    Parm115848* parm;
    u8 pad1[1580 - 24];
    f32 f1580;
    union { u32 f1584; struct { s32 init : 1; s32 rest : 31; } fb; };
    u8 pad2[1600 - 1588];
    V115848 v1600;
    V115848 v1616;
    V115848 v1632;
    f32 f1648;
    f32 f1652;
    u8 pad4[1928 - 1656];
    s32 count;
};
struct Stats115848 { s32 f0, f4; u8 pad[376]; s32 f384, f388; bool full() { return f0 >= f4; } };
struct Lead115848 {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
    virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24();
    virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
    virtual s32 act(s32, s32, s32);
    u8 pad[1160];
    Stats115848* stats;
};
struct Fr115848 {
    u8 pad0[352];
    u32 f352;
    u8 pad1[2912 - 356];
    Who115848* who;
    u8 pad2[2940 - 2916];
    u32 flags;
    u8 pad3[3168 - 2944];
    Ent115848* cur;
    bool isA() { if (f352 & 4) return true; return false; }
    bool isB() { if (f352 & 8) return true; return false; }
    bool isC() { if (f352 & 0x10) return true; return false; }
    bool busy() { return isA() || isB() || isC(); }
};
extern Lead115848* D_00341708;
extern f32 D_00349e10;
extern const Pick115848 D_0036a760;
extern const Pick115848 D_0036a768;
void func_0016bd60(Fr115848*, s32);
void func_00117808(Who115848*, V115848*);
void func_00116798(Who115848*);
s32 func_001917c0(void);
s32 func_001b58a8(void);
f32 func_0010f660(void);
Ent115848* func_001144e8(Who115848*, Pick115848);
void func_0010eed8(Fr115848*, Ent115848*, s32);
void func_0010ff08(Fr115848*);
f32 func_0017ce80(f32, f32, f32);
void func_00115848(Fr115848* o)
{
    Lead115848* lead = D_00341708;
    func_0016bd60(o, 3);
    if (!o->busy() && !(o->f352 & 0x40000000)) goto tail;
    {
        if (o->busy()) {
            if (!(o->flags & 0x80000000)) o->flags |= 0x80000000;
            if (!o->who->fb.init) {
                V115848 z;
                z.w = z.z = z.y = z.x = 0.0f;
                func_00117808(o->who, &z);
                o->who->f1584 |= 1;
            }
        }
        func_00116798(o->who);
        o->who->v1632.zero();
        s32 pick = 0;
        if (func_001917c0() && !func_001b58a8() && o->who->parm->f16 < (f32)o->who->count) {
            if (func_0010f660() < o->who->parm->f20) pick = 1;
            o->who->count = 0;
        }
        if (pick) {
            Stats115848* st = lead->stats;
            Ent115848* e;
            s32 h0=st->f0, m=st->f388, m0=st->f4, h=st->f384; if (h*m0 < h0*m) e = func_001144e8(o->who, D_0036a760);
            else e = func_001144e8(o->who, D_0036a768);
            Tgt115848 t;
            s32 score = 0;
            func_00190128(&t);
            func_0010eed8(o, 0, 0);
            o->flags &= ~4;
            (o->who->*e->pick)(e, &t, &score, 0);
            func_0010eed8(o, e, 0);
        } else {
            Ent115848* prev = o->cur;
            func_0010ff08(o);
            if (prev != o->cur || !(o->flags & 4)) o->who->count++;
        }
        Who115848* w = o->who;
        f32 r = func_0017ce80(w->v1600.w, w->v1616.w, w->f1580 * D_00349e10);
        o->who->v1600 += o->who->v1632 * o->who->v1632.w * D_00349e10;
        o->who->v1600.w = r;
    }
tail:
    if (lead->stats->full()) return;
    o->who->f1652 -= D_00349e10;
    if (o->who->f1652 <= 0.0f) {
        lead->act(1, 0, 0);
        o->who->f1652 = o->who->parm->f4;
    }
}
}
