#include "../common/types.h"

typedef unsigned int w264_u128 __attribute__((mode(TI)));
struct W264A52 { u32 w[13]; };
struct W264V192 { w264_u128 q[12]; };
struct W264D144 { u64 d[18]; } __attribute__((aligned(16)));
struct W264Blk {
    u32 vt;
    W264A52 a;
    u32 b;
    u32 c;
    W264V192 m;
    W264D144 n;
    u8 e;
    u32 f;
    u32 g;
};

union W264H { u16 h; u8 b; };
struct W264In8 { u32 id; s32 o; s8 c[4]; u8 k; };
struct W264In16 { u32 id; s32 o; s16 c[4]; u8 k; };

extern "C" {
extern u32 D_01d9ea9c;
extern u8* D_01d9e6e0;
extern u8 D_01d9e360;

// Colour/offset animation steps: four channel values from one curve, then per-channel deltas
// added onto the target (or a scratch sink). The memory barriers and pre-loaded next arguments
// reproduce the original's non-strict-aliasing ordering.

// Member-wise copy (skips the word at 0); the 16-byte rows copy as alias-set-0 block moves.
W264Blk* func_0031a068(W264Blk* d, W264Blk* s)
{
    d->a = s->a;
    d->b = s->b;
    d->c = s->c;
    __builtin_memcpy(&d->m.q[0], &s->m.q[0], 16);
    __builtin_memcpy(&d->m.q[1], &s->m.q[1], 16);
    __builtin_memcpy(&d->m.q[2], &s->m.q[2], 16);
    __builtin_memcpy(&d->m.q[3], &s->m.q[3], 16);
    __builtin_memcpy(&d->m.q[4], &s->m.q[4], 16);
    __builtin_memcpy(&d->m.q[5], &s->m.q[5], 16);
    __builtin_memcpy(&d->m.q[6], &s->m.q[6], 16);
    __builtin_memcpy(&d->m.q[7], &s->m.q[7], 16);
    __builtin_memcpy(&d->m.q[8], &s->m.q[8], 16);
    __builtin_memcpy(&d->m.q[9], &s->m.q[9], 16);
    __builtin_memcpy(&d->m.q[10], &s->m.q[10], 16);
    __builtin_memcpy(&d->m.q[11], &s->m.q[11], 16);
    d->n = s->n;
    d->e = s->e;
    d->f = s->f;
    d->g = s->g;
    return d;
}

f32 func_001eeb90(u8);
s8 func_001eeb60(s8, f32);  // fix8_mul_sub
void func_001eec28(u8* base, const W264In8* in, u8* desc)
{
    if (D_01d9ea9c) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) return;
    if (in->id != *(u32*)(base + 12)) return;
    u32 off = **(u32**)(desc + 12);
    f32 t = func_001eeb90(in->k);
    u8* p = base + off;
    f32* q = (f32*)(p + 160);
    q[0] = t;
    q[1] = func_001eeb90(in->k);
    q[2] = func_001eeb90(in->k);
    q[3] = func_001eeb90(in->k);
    asm volatile("" ::: "memory");
    p = (u8*)&D_01d9e360;
    asm volatile("" ::: "memory");
    if (in->o != -1) p = base + in->o + 160;
    f32 v = q[0];
    s8 r = func_001eeb60(in->c[0], v);  // fix8_mul_sub
    s8 c = in->c[1];
    p[0] = r + p[0];
    r = func_001eeb60(c, q[1]);  // fix8_mul_sub
    c = in->c[2];
    p[1] = r + p[1];
    r = func_001eeb60(c, q[2]);  // fix8_mul_sub
    c = in->c[3];
    p[2] = r + p[2];
    p[3] = func_001eeb60(c, q[3]) + p[3];
}

f32 func_001eed88(u8);
s8 func_001eed60(s8, f32);  // fix8_mul_b
void func_001eee30(u8* base, const W264In8* in, u8* desc)
{
    if (D_01d9ea9c) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) return;
    if (in->id != *(u32*)(base + 12)) return;
    u32 off = **(u32**)(desc + 12);
    f32 t = func_001eed88(in->k);
    u8* p = base + off;
    f32* q = (f32*)(p + 160);
    q[0] = t;
    q[1] = func_001eed88(in->k);
    q[2] = func_001eed88(in->k);
    q[3] = func_001eed88(in->k);
    asm volatile("" ::: "memory");
    p = (u8*)&D_01d9e360;
    asm volatile("" ::: "memory");
    if (in->o != -1) p = base + in->o + 160;
    f32 v = q[0];
    s8 r = func_001eed60(in->c[0], v);  // fix8_mul_b
    s8 c = in->c[1];
    p[0] = r + p[0];
    r = func_001eed60(c, q[1]);  // fix8_mul_b
    c = in->c[2];
    p[1] = r + p[1];
    r = func_001eed60(c, q[2]);  // fix8_mul_b
    c = in->c[3];
    p[2] = r + p[2];
    p[3] = func_001eed60(c, q[3]) + p[3];
}

f32 func_001ef1a0(u8);
s16 func_001ef170(s16, f32);  // fix16_mul_sub
void func_001ef238(u8* base, const W264In16* in, u8* desc)
{
    if (D_01d9ea9c) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) return;
    if (in->id != *(u32*)(base + 12)) return;
    u32 off = **(u32**)(desc + 12);
    f32 t = func_001ef1a0(in->k);
    u8* p = base + off;
    f32* q = (f32*)(p + 160);
    q[0] = t;
    q[1] = func_001ef1a0(in->k);
    q[2] = func_001ef1a0(in->k);
    q[3] = func_001ef1a0(in->k);
    asm volatile("" ::: "memory");
    p = (u8*)&D_01d9e360;
    asm volatile("" ::: "memory");
    if (in->o != -1) p = base + in->o + 160;
    f32 v = q[0];
    s16 r = func_001ef170(in->c[0], v);  // fix16_mul_sub
    s16 c = in->c[1];
    ((W264H*)p)[0].h = r + ((W264H*)p)[0].h;
    r = func_001ef170(c, q[1]);  // fix16_mul_sub
    c = in->c[2];
    ((W264H*)p)[1].h = r + ((W264H*)p)[1].h;
    r = func_001ef170(c, q[2]);  // fix16_mul_sub
    c = in->c[3];
    ((W264H*)p)[2].h = r + ((W264H*)p)[2].h;
    ((W264H*)p)[3].h = func_001ef170(c, q[3]) + ((W264H*)p)[3].h;
}

f32 func_001ef398(u8);
s8 func_001ef370(s16, f32);  // fix16_mul_b
void func_001ef440(u8* base, const W264In16* in, u8* desc)
{
    if (D_01d9ea9c) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) return;
    if (in->id != *(u32*)(base + 12)) return;
    u32 off = **(u32**)(desc + 12);
    f32 t = func_001ef398(in->k);
    u8* p = base + off;
    f32* q = (f32*)(p + 160);
    q[0] = t;
    q[1] = func_001ef398(in->k);
    q[2] = func_001ef398(in->k);
    q[3] = func_001ef398(in->k);
    asm volatile("" ::: "memory");
    p = (u8*)&D_01d9e360;
    asm volatile("" ::: "memory");
    if (in->o != -1) p = base + in->o + 160;
    f32 v = q[0];
    s8 r = func_001ef370(in->c[0], v);  // fix16_mul_b
    s16 c = in->c[1];
    ((W264H*)p)[0].h = r + ((W264H*)p)[0].h;
    r = func_001ef370(c, q[1]);  // fix16_mul_b
    c = in->c[2];
    ((W264H*)p)[1].h = r + ((W264H*)p)[1].h;
    r = func_001ef370(c, q[2]);  // fix16_mul_b
    c = in->c[3];
    ((W264H*)p)[2].h = r + ((W264H*)p)[2].h;
    ((W264H*)p)[3].h = func_001ef370(c, q[3]) + ((W264H*)p)[3].h;
}

f32 func_001ef5a0(u8);
s8 func_001ef578(s16, f32);  // fix16_mul
void func_001ef648(u8* base, const W264In16* in, u8* desc)
{
    if (D_01d9ea9c) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) return;
    if (in->id != *(u32*)(base + 12)) return;
    u32 off = **(u32**)(desc + 12);
    f32 t = func_001ef5a0(in->k);
    u8* p = base + off;
    f32* q = (f32*)(p + 160);
    q[0] = t;
    q[1] = func_001ef5a0(in->k);
    q[2] = func_001ef5a0(in->k);
    q[3] = func_001ef5a0(in->k);
    asm volatile("" ::: "memory");
    p = (u8*)&D_01d9e360;
    asm volatile("" ::: "memory");
    if (in->o != -1) p = base + in->o + 160;
    f32 v = q[0];
    s8 r = func_001ef578(in->c[0], v);  // fix16_mul
    s16 c = in->c[1];
    ((W264H*)p)[0].h = r + ((W264H*)p)[0].h;
    r = func_001ef578(c, q[1]);  // fix16_mul
    c = in->c[2];
    ((W264H*)p)[1].h = r + ((W264H*)p)[1].h;
    r = func_001ef578(c, q[2]);  // fix16_mul
    c = in->c[3];
    ((W264H*)p)[2].h = r + ((W264H*)p)[2].h;
    ((W264H*)p)[3].h = func_001ef578(c, q[3]) + ((W264H*)p)[3].h;
}

}
