#include "../common/types.h"
struct QW2d3 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct Sub2d3 { u8 pad[24]; s16 h; };
struct Act2d3 {
    u8 p0[1416]; u32 flags;            /* 0x588 */
    u8 p1[2040 - 1420]; u32 f7f8;      /* 0x7f8 */
    u8 p2[2092 - 2044]; u8 snd[2780 - 2092]; f32 fadc; /* 0x82c, 0xadc */
    u8 p3[2808 - 2784]; Sub2d3* sub;   /* 0xaf8 */
    u8 p4[2936 - 2812]; f32 fb78; u8 p5[4]; u8 bb80; /* 0xb78, 0xb80 */
};
struct Hit2d3 { u8 pad[16]; Act2d3* other; };
static inline u8 IsPos2d3(f32 v) { return v > 0.0f; }
void func_001ad990(void*, f32, f32, f32);
extern "C" {
void ctarget_0016bda8(QW2d3*, Act2d3*) asm("_Z16ctarget_0016bda8jjjj");
void ctarget_00186a90(Act2d3*, QW2d3*, f32) asm("_Z16ctarget_00186a90jjjj");
void func_0016ac38(Act2d3*, s32, s32, s32, s32);
f32 func_002f8870(f32);
void func_002d39c8(Act2d3* a, Hit2d3* h) {
    QW2d3 d, pa, pb;
    Act2d3* b = h->other;
    if (!(b->flags & 0x8000000)) return;
    if (IsPos2d3(a->fadc)) return;
    if (IsPos2d3(b->fadc)) return;
    s16 ha = a->sub->h;
    if (ha == 0) return;
    s16 hb = b->sub->h;
    if (hb == 0) return;
    if (hb < ha) return;
    if (!(a->f7f8 & 0x10)) func_001ad990(a->snd, 1.0f, 0.0f, 0.0f);
    // s0 for &pa: local-alloc priority gives it to &pb otherwise (partial asm, see asm_review.tsv)
    register QW2d3* ppa asm("$16");
        ppa = &pa;
    func_0016ac38(a, 0, 1, 0, 0);
    a->bb80 = 1;
    ctarget_0016bda8(ppa, a);
    ctarget_0016bda8(&pb, h->other);
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&d), "r"(ppa), "r"(&pb) : "memory");
    d.z = 0.0f;
    {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                     : "=f"(r) : "r"(&d) : "$8", "memory");
    }
    if (a->fb78 < 0.0f) asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(&d) : "memory");
    ctarget_00186a90(a, &d, func_002f8870(a->fb78));
}
}


struct W1640Info {
    u16 flags;
    u16 id;
    u8 pad4;
    u8 kind;
};

struct W1640Owner {
    u8 pad0[0xa1c];
    W1640Info info;
};

struct W1640Cmd {
    u8 pad0[0xf0];
    s32 lastId;
    s32 lastCol;
    u8 padF8[0xfc - 0xf8];
    u8 active;
    u8 padFD;
    u8 flash;
    u8 padFF;
    s32 tag;
    u8 pad104[0x29c - 0x104];
    W1640Owner* owner;
    u8 pad2a0[4];
    s32 unk2A4;
};

struct W1640Spr {
    u8 pad0[0x110];
    s32 unk110;
    u8 pad114[0x198 - 0x114];
};

struct W1640Pool {
    u8 pad0[0x3300];
    s32 freeIdx[32];
    s32 nFree;
};

extern "C" {

extern s32 D_00348548[][6];
extern s32 D_003484f8[];
extern f32 D_0036ad70[];
extern W1640Pool* D_00348054;
s32 func_0013cb90(void);
s32 func_0013cb80(void);
s32 func_0013cb30(void);
u8* func_001b8e88(u32);
u32 func_00192048(u32);
void* func_0013b5d0(W1640Cmd*, s32, s32, void*, u32, s32, s32, u32, f32, u32, s32);
void func_00139580(void*);
void func_00139570(void*);
void func_00139740(void*);
s32 func_001396c0(void*);
void func_0013cdc8(W1640Cmd*, void*);
void func_001386e0(W1640Spr*, s32, s32, s32, s32, s32);
void func_00138c40(W1640Spr*, s32, s32);
f32 func_0013b2e8(void);
void func_00138d48(f32, f32, f32, f32, W1640Spr*);

static inline __attribute__((always_inline)) W1640Spr* W1640_Alloc(void)
{
    W1640Pool* o = D_00348054;
    o->nFree--;
    return (W1640Spr*)((u8*)o + o->freeIdx[o->nFree] * 0x198);
}

void func_0013ce08(W1640Cmd* self, s32 n)
{
    s32 y = 377 - n * 22;
    s32 idx = func_0013cb90();
    W1640Info* info = &self->owner->info;
    u32 id = info->id;
    u8 kind = info->kind;
    u32 changed = 0;
    if (info->flags & 2) changed = 1;
    if (self->lastId != id) changed = 1;
    s32 c;
    void* p;
    if (id) {
        self->active = 1;
        u8* item = func_001b8e88(id);
        s32 r = idx * 6;
        c = ((s32*)D_00348548)[r];
        if (kind == 7) c = D_00348548[idx][1];
        else if ((u8)((*(s32*)(item + 12) >> 3) & 1)) c = D_00348548[idx][2];
        if (c != self->lastCol) changed = 1;
        u32 t = func_00192048(*(u32*)(item + 8));
        self->tag = t;
        asm("" : "+r"(changed)); // no code: sched2 order of the arg moves (partial asm, see asm_review.tsv)
        p = func_0013b5d0(self, 0, c, info, changed, 36, y, t, D_0036ad70[kind], D_003484f8[kind], 2);
        func_00139580(p);
        if (!self->flash) self->tag = 0;
    } else {
        if (self->tag == 0) c = D_00348548[idx][3];
        else c = D_00348548[idx][4];
        p = func_0013b5d0(self, 0, c, info, changed, 36, y, self->tag, 1.0f, 0x80e6e6e6, 2);
        func_00139740(p);
        if (changed != 1) {
            if (self->active != 1) goto hide;
            if (func_001396c0(p)) goto clr;
        }
        func_00139580(p);
        goto common;
    clr:
        self->active = 0;
    hide:
        func_00139570(p);
    }
common:
    func_0013cdc8(self, p);
    self->lastId = id;
    self->lastCol = c;
    if (self->flash == 1) {
        W1640Spr* s = W1640_Alloc();
        s32 z = func_0013cb80() + 32;
        func_001386e0(s, 5303, func_0013cb30(), z, D_00348548[idx][5], 2);
        func_00138c40(s, 36, y);
        func_00138d48(1.0f, 1.0f, 1.0f, func_0013b2e8(), s);
        self->flash = 0;
        if (self->unk2A4 && s->unk110 >= 100) {
            s = W1640_Alloc();
            func_001386e0(s, 5400, func_0013cb30(), z, 99, 2);
            func_00138c40(s, 28, 322);
        }
    }
}

}
