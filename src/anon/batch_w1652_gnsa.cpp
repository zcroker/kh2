#include "../common/types.h"

#define W1652_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

struct W1652Vec {
    f32 x, y, z, w;
    W1652Vec() {}
    W1652Vec(const W1652Vec& o) { W1652_QCOPY(this, &o); }
    W1652Vec& operator=(const W1652Vec& o) { if (this != &o) W1652_QCOPY(this, &o); return *this; }
    W1652Vec operator+(const W1652Vec& o) const {
        W1652Vec r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    W1652Vec operator-(const W1652Vec& o) const {
        W1652Vec r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    W1652Vec& operator+=(const W1652Vec& o) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "r"(&o) : "memory");
        return *this;
    }
    W1652Vec operator*(f32 k) const {
        W1652Vec r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    void zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); }
    void unit() { asm volatile("sqc2 $vf0, 0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));

struct W1652Tag {
    u8 b[4];
};

struct W1652Ctl {
    void** vt;
    u8 pad4[4];
    u32 flags;
};

typedef W1652Vec (*W1652GetFn)(W1652Ctl*, void*);

struct W1652Par;
struct W1652Obj {
    u8 pad0[0xc];
    W1652Ctl* ctl;
    u8 pad10[0xd8 - 0x10];
    f32 height;
    u8 padDC[0x108 - 0xdc];
    u32 flags108;
    u32 flags10C;
    u8 pad110[0x160 - 0x110];
    u32 flags160;
    u8 pad164[0x540 - 0x164];
    W1652Vec pos;
    u8 pad550[0x560 - 0x550];
    W1652Vec push;
    W1652Par* parent;
    u8 pad574[0x588 - 0x574];
    u32 flags588;
    u8 pad58C[0x654 - 0x58c];
    u8 b654;
    u8 pad655[0x7f8 - 0x655];
    u32 flags7F8;
    u8 pad7FC[0x810 - 0x7fc];
    s32 unk810;
    u8 pad814[0x840 - 0x814];
    W1652Vec oldPos;
    W1652Vec move;
    W1652Vec vel;
    W1652Vec v870;
    W1652Vec v880;
    u8 pad890[0x8bc - 0x890];
    W1652Tag tag;
    u8 pad8C0[0x8dc - 0x8c0];
    u8 b8DC;
} __attribute__((aligned(16)));

struct W1652Par { u8 pad0[0x8bc]; W1652Tag tag; u8 pad8C0[0x8dc - 0x8c0]; u8 b8DC; };
extern "C" {

extern f32 D_00349e10;
extern f32 D_00349e18;
extern f32* D_00352130;
s32 W1652_IsAttach(W1652Obj*) asm("_ZN2YS3OBJ9is_attachEv");
W1652Vec func_001835f8(W1652Obj*);
W1652Vec func_00186b90(W1652Obj*);
s32 func_0019bad8(W1652Obj*);
s32 func_0019c090(W1652Obj*);
W1652Vec func_00184bb0(W1652Obj*);
W1652Vec func_001d3ac0(W1652Obj*);
W1652Vec func_001b3428(s32*, W1652Obj*);
void func_00183918(W1652Obj*, const W1652Vec&, const W1652Vec&, W1652Vec&);

static inline __attribute__((always_inline)) void W1652_CopyTag(W1652Tag* d, W1652Tag* s) { __builtin_memcpy(d, s, 4); }

static inline bool W1652_CtlBusy(W1652Obj* self) { return (self->ctl->flags & 2) || (self->flags160 & 0x40); }
static inline bool W1652_CanPush(W1652Obj* self) { bool skip = false; if (func_0019c090(self) || W1652_CtlBusy(self)) skip = true; return !skip; }

// 00183088: moved to src/anon/unit_00183088.cpp

}
