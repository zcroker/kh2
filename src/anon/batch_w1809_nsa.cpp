#include "../common/types.h"

// 16-byte vector with an lq/sq copy (self-assignment checked) and a VU0 zero.
struct W1809V4 {
    f32 x, y, z, w;
    W1809V4() {}
    W1809V4& operator=(const W1809V4& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    void zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));
struct W1809O76;
struct W1809C76 { virtual void m0(); virtual void m1(); virtual void fn(W1809O76*, W1809V4*); };
struct W1809S76 { u8 pad[0x50]; f32 f50; f32 f54; };
struct W1809O76 {
    u8 pad0[12]; W1809C76* p0c; W1809V4 v10; u8 pad20[0x110]; W1809S76* p130; u8 pad134[0xc]; u8 x140[0x10];
};

struct W1809S19a1 { u8 type; u8 pad; u16 h2; };
struct W1809O19a1 { u8 pad[8]; W1809S19a1* p; };

struct W1809Heap;
struct W1809HeapVt { void* (*alloc)(W1809Heap*, u32, void*); };
struct W1809Heap { W1809HeapVt* vt; };
struct W1809InfoC8 { u8 pad[16]; s32 n10; u32 sz14; u32 sz18; };
struct W1809RefC8 { u8 pad[0x488]; s32 refs; };
struct W1809ObjC8 {
    W1809InfoC8* info; s32 f4; void* f8; void* fc; void* f10; void* f14; void* f18;
    s32 f1c, f20, f24; s32 f28; s32 f2c, f30; void* f34; W1809RefC8* f38;
};

struct W1809V2d5 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct W1809R2d5 { u8 pad[16]; s16 h10; };

extern "C" {
s32 func_0019a480();
void func_0019a808();
void func_0019af98();
void func_0019b4d0();
void func_0019b500();
void func_0019b5d8();
void func_0019b668();
extern u8* D_0034e948;

s32 func_0019a1a0(W1809O19a1* o, s32 a1) {
    W1809S19a1* p = o->p;
    switch (p->type) {
    case 1:
        if (a1 == 0 || func_0019a480() == 0) return 0;
        break;
    case 2: func_0019a808(); break;
    case 3: func_0019af98(); break;
    case 6: func_0019b500(); break;
    case 7:
        if (a1 == 0) break;
        func_0019b4d0(); return 0;
    case 8:
        if (a1 == 0) break;
        func_0019b5d8();
        break;
    case 9: func_0019b668(); break;
    case 10: *(s32*)(D_0034e948 + 0xb4c) = p->h2; break;
    }
    return 1;
}

void func_0017f488(void*, s32, f32, f32);
void func_0017f5e0(void*, s32, s32, f32, f32);
void func_0016aef0(W1809O76*, W1809V4*);

void func_00176970(W1809O76* o) {
    W1809S76* s = o->p130;
    func_0017f488(o->x140, 40, 0.0f, 0.0f);
    func_0017f5e0(o->x140, 4, 0, 0.0f, 0.0f);
    W1809V4 t;
    if (o->v10.w > 0.0f) {
        t = o->v10;
        t.w = s->f54;
        func_0016aef0(o, &o->v10);
    } else {
        t.zero();
    }
    t.y = s->f50;
    o->p0c->fn(o, &t);
    o->v10.zero();
}
extern W1809Heap* D_004f6288;
void* func_0016d1a0(s32);
void* func_0016d1d8(void*);

void func_0016c808(W1809ObjC8* o, W1809InfoC8* info, void* a2, W1809RefC8* a3) {
    o->f34 = a2;
    o->f38 = a3;
    o->info = info;
    o->f1c = 0;
    o->f20 = 0;
    o->f24 = 0;
    o->f30 = 0;
    o->f2c = 0;
    void* p = D_004f6288->vt->alloc(D_004f6288, info->sz14 + 256, __builtin_return_address(0));
    o->f14 = p;
    o->f8 = p;
    p = D_004f6288->vt->alloc(D_004f6288, o->info->sz18 + 256, __builtin_return_address(0));
    o->f18 = p;
    o->fc = p;
    if (o->f34 == 0) {
        if (o->info->n10 > 0) o->f34 = func_0016d1a0(o->info->n10);
    }
    void* b = o->f34;
    o->f10 = b ? func_0016d1d8(b) : 0;
    o->f4 = 0;
    if (o->f38) o->f38->refs++;
}

void func_0016c8f8(W1809ObjC8* o, W1809InfoC8* info, void* a2, W1809RefC8* a3) {
    o->f34 = a2;
    o->f38 = a3;
    o->info = info;
    o->f1c = 0;
    o->f20 = 0;
    o->f24 = 0;
    o->f30 = 0;
    o->f2c = 0;
    void* p = D_004f6288->vt->alloc(D_004f6288, info->sz14 + 256, __builtin_return_address(0));
    o->f14 = p;
    o->f8 = p;
    p = D_004f6288->vt->alloc(D_004f6288, o->info->sz18 + 256, __builtin_return_address(0));
    o->f18 = p;
    o->fc = p;
    if (o->f34 == 0) {
        if (o->info->n10 > 0) o->f34 = func_0016d1a0(o->info->n10);
    }
    void* b = o->f34;
    o->f10 = b ? func_0016d1d8(b) : 0;
    o->f4 = 0;
    if (o->f38) o->f38->refs++;
}

extern s32 D_00361f60;
s32 func_001c0cd8(void*);
W1809R2d5* func_0016bc20(void*, s32, s32);
void func_0016bda8(W1809V2d5*, void*);

// VU0 macro code: d = a - b, then the xyz length of d.
s32 func_002d55b8(u8* a0) {
    s32 r = 0;
    if (D_00361f60 != 0) {
        void* t = *(void**)(a0 + 0xc14);
        if (t != 0) {
            if (func_001c0cd8(t) != 0) goto no;
            {
            W1809V2d5 d, a, b;
            W1809V2d5* pd = &d;
            f32 len;
            f32 range = func_0016bc20(*(void**)(a0 + 0xc14), 5, -1)->h10;
            func_0016bda8(&a, a0);
            func_0016bda8(&b, *(void**)(a0 + 0xc14));
            asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(pd), "r"(&a), "r"(&b) : "memory");
            pd->z = 0.0f;
            asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(len) : "r"(pd) : "$8", "memory");
            r = 1;
            if (len < range) goto out;
            }
        no:
            r = 0;
        }
    }
out:
    return r;
}
}
