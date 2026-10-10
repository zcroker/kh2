#include "../common/types.h"
#define QCOPY142(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV142 {
    f32 x, y, z, w;
    QV142() {}
    QV142(const QV142& o) { QCOPY142(this, &o); }
    QV142& operator=(const QV142& o) {
        if (this != &o) QCOPY142(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct Seg142 {
    QV142 a, b;
    Seg142(const QV142& p, const QV142& q) { a = p; b = q; }
};
static inline f32 clamp142(f32 v, f32 lo, f32 hi) { if (v < lo) return lo; if (hi < v) return hi; return v; }

extern "C" {

struct Fog15c { u8 r, g, b, a; f32 near, far, fmin, fmax; };
struct Cfg15c { u8 pad[0x44]; Fog15c fog; };
extern Cfg15c D_004f3700;
extern Cfg15c D_004f36a8;
extern Cfg15c D_004f3650;
void func_0015cbb8(s32, s32, s32, s32);
void func_0015c4b8(void);
void func_0015cc18(s32, s32, s32, s32, s32);
s32 func_0015cc80(Fog15c*);  // test_float12_zero_and_bits
void func_0010a8a8(f32, f32);  // store_global_float_pair
void func_0010a828(f32, f32);
void func_0010a7d8(u8, u8, u8);  // store_triple_bytes
void func_001dd1e8(u8, u8);
void func_001dd1b0(f32, f32);  // to_1e7018
void func_001dd1c8(u8, u8, u8);  // to_1e7030_masked

void func_0015c500(void)
{
    s32 i;
    Fog15c* f;
    func_0015cbb8(0, 0, 0, 128);
    func_0015c4b8();
    for (i = 0; i < 16; i++) func_0015cc18(i, 128, 128, 128, 128);
    f = &D_004f3700.fog;
    f->near = 1000.0f;
    f->fmin = 0.0f;
    f->far = 1000000.0f;
    f->fmax = 255.0f;
    s32 c = 128;
    f->r = c;
    f->g = c;
    f->b = c;
    f->a = c;
    if (!func_0015cc80(f)) {  // test_float12_zero_and_bits
        func_0010a8a8(f->fmin, f->fmax);  // store_global_float_pair
        func_0010a828(f->near, f->far);
        func_0010a7d8(f->r, f->g, f->b);  // store_triple_bytes
    }
    func_001dd1e8((s32)f->fmin, (s32)f->fmax);
    func_001dd1b0(f->near, f->far);  // to_1e7018
    func_001dd1c8(f->r, f->g, f->b);  // to_1e7030_masked
    D_004f36a8 = D_004f3700;
    D_004f3650 = D_004f36a8;
}


struct G2ad { u8 pad[320]; u32 bits[4]; };
extern s32 D_0035f628;
extern s32 D_0035f620;
extern s32 D_0035f62c;
u8* func_001058e8(void);
s32 func_002a7490(void);
s32 func_002a74c0(void);

static inline s32 tb2ad(u32* base, u32 n) { return base[n >> 5] & (1 << (n & 31)); }
static inline void sb2ad(u32* base, u32 n) { u32 m = 1 << (n & 31); u32* p = base + (n >> 5); *p |= m; }
static inline s32 cnt2ad(u8* s, s32 off, s32 n)
{
    s32 c = 0;
    s32 j;
    for (j = 0; j < n; j++) if (tb2ad((u32*)(s + off), j)) c++;
    return c;
}

void func_002add90(void)
{
    u8* s;
    s32 a, b, i, ok;
    s = func_001058e8() + 18932;
    a = func_002a7490();
    b = func_002a74c0();
    D_0035f628 += 4;
    for (i = 0; i < 4; i++) {
        ok = (i == 0 || i == 3) ? a : b;
        if (!ok) continue;
        switch (i) {
        case 0: ok = s[576] + 1 >= 9; break;
        case 1: ok = cnt2ad(s, 0, 60) >= 60; break;
        case 2: ok = cnt2ad(s, 8, 54) >= 54; break;
        case 3: ok = cnt2ad(s, 28, 80) >= 59; break;
        }
        if (ok) {
            sb2ad(((G2ad*)D_0035f620)->bits, i);
            D_0035f62c++;
        }
    }
}

extern s32 D_0035f650;
s32 func_00289380(s32);
s32 func_00287cd0(void);
s32 func_0028acc8(s32);
s32 func_00289310(s32);
void func_00287f90(s32);
void func_0028abe0(s32);
void func_00287c30(void);
void func_0025d560(void);
s32 func_0028ae28(s32, s32);
void func_0028ab20(s32);
void func_00287cc0(s32);
s32 func_00287df0(s32, s32, s32, s32, s32);
s32 func_00242848(s32);
void func_0028aa40(s32);
void func_00287c00(s32);
void func_0025ccc0(void);
void func_00287bd0(s32, s32);

void func_0025caf0(void)
{
    s32 a = func_00289380(D_0035f650);
    s32 st = func_00287cd0();
    if (st == 2) {
        if (func_0028acc8(D_0035f650)) {
            if (a != -1 || func_00289310(D_0035f650)) {
                func_00287f90(0);
                func_0028abe0(D_0035f650);
            }
        } else {
            func_00287c30();
            func_0025d560();
        }
        return;
    }
    if (a != -1 || func_00289310(D_0035f650)) {
        if (!func_0028ae28(D_0035f650, 0)) func_0028ab20(D_0035f650);
    }
    if (st == 0 && func_0028ae28(D_0035f650, 0)) func_00287cc0(1);
    if (func_00242848(func_00287df0(a, func_00289310(D_0035f650), 1, 0, 1))) return;
    switch (a) {
    case -1:
        break;
    case -2:
    case 0:
        func_0028aa40(D_0035f650);
        func_00287cc0(2);
        func_00287c00(0);
        break;
    case 1:
        func_0025ccc0();
        func_00287bd0(23, 0);
        break;
    }
}

struct K231 { u8 b[16]; };
struct H231 { u8 pad[6]; struct { u16 start, count; } ch[8]; u8 pad2[40 - 38]; K231 keys[1]; };
extern u8 D_0035de90[8][32];
f32 func_00230f10(K231*, s32, void*, f32);

void func_002311c0(f32* out, H231* h, f32 t)
{
    if (h->ch[0].count) out[0] = func_00230f10(&h->keys[h->ch[0].start], h->ch[0].count, D_0035de90[0], t);
    if (h->ch[1].count) out[1] = -func_00230f10(&h->keys[h->ch[1].start], h->ch[1].count, D_0035de90[1], t);
    if (h->ch[2].count) out[2] = -func_00230f10(&h->keys[h->ch[2].start], h->ch[2].count, D_0035de90[2], t);
    if (h->ch[3].count) out[3] = func_00230f10(&h->keys[h->ch[3].start], h->ch[3].count, D_0035de90[3], t);
    if (h->ch[4].count) out[4] = -func_00230f10(&h->keys[h->ch[4].start], h->ch[4].count, D_0035de90[4], t);
    if (h->ch[5].count) out[5] = -func_00230f10(&h->keys[h->ch[5].start], h->ch[5].count, D_0035de90[5], t);
    if (h->ch[6].count) out[6] = func_00230f10(&h->keys[h->ch[6].start], h->ch[6].count, D_0035de90[6], t) * 3.14159274f / 180.0f;
    if (h->ch[7].count) out[7] = func_00230f10(&h->keys[h->ch[7].start], h->ch[7].count, D_0035de90[7], t);
}

struct Obj142 {
    u8 pad[20]; f32 rad; u8 pad2[48 - 24]; QV142 pos; u8 pad3[104 - 64]; f32 f104; f32 h;
    u64 lo : 3; u64 kind : 4; u64 mid : 26; u64 miss : 1; u64 hi : 30;
};
f32 func_002f8870(f32);  // fabsf
void func_00141c18(void*, s32, s32, s32, s32);
s32 func_00141ff0(void*, Seg142*, QV142*, s16*, s32);
void func_001419f8(void*, u16, Obj142*, QV142);

s32 func_001424c0(void* self, Obj142* o)
{
    QV142 p(o->pos);
    QV142 q(o->pos);
    f32 r = func_002f8870(o->rad);  // fabsf
    if (o->kind == 0) r = clamp142(r, 0.0f, 100.0f);
    p.y = p.y - o->h - r;
    q.y = q.y + o->h * 3.0f;
    Seg142 seg(p, q);
    QV142 out;
    s16 hit = -1;
    func_00141c18(self, 15, 4, 1, 0);
    if (func_00141ff0(self, &seg, &out, &hit, (s32)(*(u64*)((u8*)o + 112) >> 3) & 0xf)) {
        o->miss = 0;
        o->f104 = out.y;
        func_001419f8(self, hit, o, out);
        return 1;
    }
    o->miss = 1;
    o->f104 = 320000.0f;
    func_001419f8(self, hit, o, o->pos);
    return 0;
}
}
