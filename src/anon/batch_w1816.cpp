#include "../common/types.h"

// --- 002f12b0: start a timed turn towards an angle (degrees) around an object
struct W1816Turn { bool rev; u32 h; f32 time; f32 dst; f32 speed; f32 val; };
struct W1816Q { f32 x, y, z, w; };

// --- 00187300
#define W1816_AI __attribute__((always_inline))
struct W1816V {
    f32 x, y, z, w;
    W1816V& operator=(const W1816V& o) {
        if (this != &o) {
            asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        }
        return *this;
    }
} __attribute__((aligned(16)));
static inline W1816_AI W1816V operator+(const W1816V& a, const W1816V& b) {
    W1816V r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline W1816_AI W1816V operator-(const W1816V& a, const W1816V& b) {
    W1816V r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline W1816_AI f32 W1816Len(const W1816V& v) {
    f32 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(r) : "r"(&v) : "$8", "memory");
    return r;
}
struct W1816Ob { u8 pad[1376]; W1816V pos; };
struct W1816Tg { W1816Ob* owner; };

// --- 00189e18
struct W1816Act;
struct W1816Sub { u8 pad[32]; u32 flags; u8 pad2[252 - 36]; W1816Act* tgt; };
struct W1816Act { u8 p0[320]; W1816Sub sub; };
struct W1816Buf { f32 v[8]; };
#define W1816F(o, off, T) (*(T*)((u8*)(o) + (off)))

extern "C" {
void func_0016af58(W1816Q*, u32);
f32 func_0017ce10(f32);
f32 func_002f8ad0(f32, f32);
void func_002f12b0(W1816Turn* s, f32 deg, u32 h, f32 t, s32 flag) {
    s->rev = flag != 0;
    s->h = h; s->time = t;
    s->dst = 3.1415927f - deg * 0.017453292f;
    W1816Q v; func_0016af58(&v, h);
    s->val = func_002f8ad0(v.x, v.z);
    s->val = func_0017ce10(s->val);
    s->dst = func_0017ce10(s->dst);
    f32 d;
    if (s->dst < s->val) { d = s->val - s->dst; if (s->rev == false) d = 6.283185f - d; }
    else { d = s->dst - s->val; if (s->rev == true) d = 6.283185f - d; }
    s->speed = d / s->time;
    if (s->rev == true) s->speed = -s->speed;
}

s32 func_00190180(W1816Tg*);
void func_00190388(W1816V*, W1816Tg*);
W1816V* func_0016c028(W1816Ob*);
void func_00184ad0(W1816Ob*, W1816V*, f32);
}
static inline W1816V W1816Pos(W1816Tg* t) { W1816V r; func_00190388(&r, t); return r; }
extern "C" {
s32 u_call4_00187300(W1816Ob* self, W1816Tg* t, f32 r) asm("_Z16u_call4_00187300jjjj");
s32 u_call4_00187300(W1816Ob* self, W1816Tg* t, f32 r) {
    if (!func_00190180(t)) return 0;
    if (t->owner != self) {
        W1816V v; v = W1816Pos(t) - (*func_0016c028(self) + self->pos);
        v.y = 0.0f;
        if (50.0f < W1816Len(v)) func_00184ad0(self, &v, r);
    }
    return 1;
}

extern W1816Act* D_0034e948;
s32 func_0019ba60(W1816Act*);
void func_00190128(W1816Buf*);
void func_00190878(W1816Buf*, W1816Act*, s32);
s32 func_001bd418(s32, s32, s32, W1816Buf*, s32, s32);
s32 func_001bd3e0(s32, s32, s32, W1816Buf*, s32, s32);
void func_00189e18(W1816Act* self, s32 a, s32 b) {
    W1816Act* pl = D_0034e948;
    if (!func_0019ba60(pl)) return;
    W1816Buf v; func_00190128(&v);
    if (W1816F(self, 0x588, u32) & 0x80) {
        W1816Sub* s = &self->sub;
        if (W1816F(self, 0x160, u32) & 0x4000) { func_00190878(&v, s->tgt, b); goto done; }
    }
    func_00190878(&v, self, b);
done:
    if (pl == self) { if (!func_001bd418(W1816F(pl, 0xb44, s32), 1, a, &v, 1, 100)) return; }
    else if (!func_001bd3e0(W1816F(pl, 0xb44, s32), 1, a, &v, 1, 100)) return;
    W1816F(pl, 0x50c, s32) = a; W1816F(pl, 0x160, u32) |= 0x20000;
}
}
