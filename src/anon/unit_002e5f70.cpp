// Linked unit 0x002e5f28-0x002e7658 (0x2e5f28 is a twin of 0x2e5f70).
#include "../common/types.h"
#include "../taito/afp.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../tozawa/cmenu_top.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"

// 002e5f70 (was src/anon/batch_w35.cpp)
namespace n002e5f70 {
// 0x002dc788: definition moved into src/anon/unit_002da040.cpp

void func_00108398(void*) asm("func_00108398");
// 0x2e5f28 (gap): twin of func_002e5f70 below (C2/C1 pair)
extern "C" void func_002e5f28(u8* p) {
    func_00108398(p + 16);
    func_00108398(p + 288);
    *(u32*)(p + 544) = 0;
    *(u32*)(p + 548) = 0;
    *(u32*)(p + 552) = 0;
    *(u32*)(p + 556) = 0;
    *(u64*)(p + 560) = 0;
}
/*TARGET 002e5f70*/
// clear_quads_set_flags
void func_002e5f70(u8* p) asm("func_002e5f70");
// clear_quads_set_flags
void func_002e5f70(u8* p) {
    func_00108398(p + 16);  // clear_quads_set_flags
    func_00108398(p + 288);  // clear_quads_set_flags
    *(u32*)(p + 544) = 0;
    *(u32*)(p + 548) = 0;
    *(u32*)(p + 552) = 0;
    *(u32*)(p + 556) = 0;
    *(u64*)(p + 560) = 0;
}
}  // namespace n002e5f70

// 002e5fb8 (was src/anon/batch_w3720_nsa.cpp)
namespace n002e5fb8 {
struct H18 { u8 pad[8]; u32 sz8; u16 sz12; u8 pad2[5]; u8 f13; };
struct P18 { u8 pad[5]; u8 type; };
struct W18 { u8 pad[0x90]; u64 a[16]; u8 pad2[0x1a0 - 0x110]; u64 b[16]; u8 pad3[0x220 - 0x220]; P18* src; H18* hdr; u8* p2; u8* p3; };
static inline u32 al18(u32 x, u32 a) { u32 m = x % a; return m ? x + (a - m) : x; }
/*TARGET 002e5fb8*/
void func_002e5fb8(W18* w, P18* s) asm("func_002e5fb8");
void func_002e5fb8(W18* w, P18* s) {
    w->src = s;
u8 t = s->type; u32 a = 16; if (t) { a = t == 1 ? 128 : 0; asm("" : : "r"(t)); }
    u32 p = (u32)s + 16; asm("" : : "r"(s));
    p = al18(p, a);
    H18* h = (H18*)p;
    w->hdr = h;
    p += 48;
    p = al18(p, a);
    p = p + h->sz12 - 48;
    p = al18(p, a);
    w->p2 = (u8*)p;
    p += h->sz8;
    p = al18(p, a);
    w->p3 = h->f13 < 4 ? 0 : (u8*)p;
    for (s32 i = 0; i < 16; i++) { w->a[i] = 0; w->b[i] = 0; }
}
}  // namespace n002e5fb8

// 002e60c0 (was src/anon/perm_002e60c0.cpp)
namespace n002e60c0 {
typedef unsigned long long u64;
typedef signed int s32;
extern u64 D_01e2be80[16] asm("D_01e2be80");
void func_001342c8(void *, s32, s32) asm("func_001342c8");
/*TARGET 002e60c0*/
void func_002e60c0(s32 p0, s32 p1, s32 p2, s32 p3, s32 p4, s32 p5, s32 p6, s32 p7, s32 w, s32 h) asm("func_002e60c0");
void func_002e60c0(s32 p0, s32 p1, s32 p2, s32 p3, s32 p4, s32 p5, s32 p6, s32 p7, s32 w, s32 h)
{
  u64 *new_var2;
  u64 new_var;
  s32 f = p5 & 7;
  s32 n;
  u64 new_var3;
  n = 8;
  if (f == 1)
  {
    n = 6;
  }
  if (f == 2)
  {
    n = 4;
  }
  if (f == 3)
  {
    n = 2;
  }
  if (f == 4)
  {
    n = 1;
  }
  s32 sz = (w * h) * n;
  if (p5)
  {
    n = p5;
  }
  else
  {
    n = p5;
  }
  s32 q = sz / 32;
  if (sz & 0x1f)
  {
    q++;
  }
  u64 b = ((((u64) p3) << 32) | (((u64) p4) << 48)) | (((u64) n) << 56);
  new_var = ((u64) p6) << 32;
  u64 r = ((u64) w) | (((u64) h) << 32);
  new_var2 = D_01e2be80;
  new_var3 = new_var;
  u64 p = new_var3 | (((u64) p7) << 48);
  u64 *d = new_var2;
  D_01e2be80[0] = (1ULL << 60) | 5;
  D_01e2be80[1] = 14;
  D_01e2be80[2] = 0;
  D_01e2be80[3] = 0x3f;
  D_01e2be80[4] = b;
  D_01e2be80[5] = 0x50;
  D_01e2be80[6] = p;
  D_01e2be80[7] = 0x51;
  D_01e2be80[8] = r;
  D_01e2be80[9] = 0x52;
  d[10] = 0;
  D_01e2be80[12] = (((u64) q) | 0x8000) | (1ULL << 59);
  D_01e2be80[11] = 0x53;
  D_01e2be80[15] = (D_01e2be80[13] = 0);
  D_01e2be80[14] = 0;
  func_001342c8(new_var2, 7, 0x13000000);
  func_001342c8((void *) p2, q, 0x13000000);
}
}  // namespace n002e60c0

// 002e6210 (was src/anon/batch_w2409.cpp)
namespace n002e6210 {
#define GS_SET_TEX0(tbp, tbw, psm, tw, th, tcc, tfx, cbp, cpsm, csm, csa, cld) \
    ((u64)(tbp) | ((u64)(tbw) << 14) | ((u64)(psm) << 20) | ((u64)(tw) << 26) | ((u64)(th) << 30) | \
     ((u64)(tcc) << 34) | ((u64)(tfx) << 35) | ((u64)(cbp) << 37) | ((u64)(cpsm) << 51) | ((u64)(csm) << 55) | \
     ((u64)(csa) << 56) | ((u64)(cld) << 61))
struct Img2e6210 { u8 pad0[8]; s32 size; u8 pad1[7]; u8 format; u16 w; u16 h; };
struct Tex2e6210 {
    u8 pad0[272];
    u8 clutObj[548 - 272];
    Img2e6210* img;
    void* pixels;
    void* clut;
    u64 tex0 __attribute__((aligned(4)));
};
void func_001097e8(void*, s32, s32, s32, s32, s32, s32, s32, void*) asm("func_001097e8");
void func_00133c60(void*, void*, s32, s32, s32) asm("func_00133c60");
static inline void ld1(void* co, void* pkt, s32 cbp, s32 h, void* data) { func_001097e8(co, cbp, 64, 0, 0, 16, h, 0, data); func_00133c60(pkt, co, 0, 0, 0); }
/*TARGET 002e6210*/
void func_002e6210(Tex2e6210* t, void* pkt, s32 tbp) asm("func_002e6210");
void func_002e6210(Tex2e6210* t, void* pkt, s32 tbp)
{
    s16 psm = 0;
    switch (t->img->format) {
    case 0:
        break;
    case 1:
        psm = 2;
        break;
    case 2:
        psm = 1;
        break;
    case 3:
        psm = 0;
        break;
    case 4:
        psm = 20;
        break;
    case 5:
        psm = 19;
        break;
    }
    func_001097e8(t, tbp, t->img->w >> 6, 0, 0, t->img->w, t->img->h, psm, t->pixels);
    func_00133c60(pkt, t, 0, 0, 0);
    s32 cbp = tbp + t->img->size / 256;
    s32 tw = 0;
    while ((1 << tw) < t->img->w) tw++;
    s32 th = 0;
    while ((1 << th) < t->img->h) th++;
    if (t->clut) {
        if (psm == 20) ld1(t->clutObj, pkt, cbp, 2, t->clut);
        else ld1(t->clutObj, pkt, cbp, 16, t->clut);
        t->tex0 = GS_SET_TEX0(tbp, (u16)(t->img->w >> 6), psm, tw, th, 1, 0, cbp, 0, 0, 0, 1);
    } else { t->tex0 = GS_SET_TEX0(tbp, (u16)(t->img->w >> 6), psm, tw, th, 1, 0, 0, 0, 0, 0, 0); }
}
}  // namespace n002e6210

// 002e64b0 (was src/taito/afp.cpp)
namespace Ti { // method 002e64b0
/*TARGET 002e64b0*/
s32 Afp::getCount(void* p) {
    (void)p;
    return reinterpret_cast<AfpLayout*>(this)->count;
}
}  // Ti

// 002e64b8 (was src/anon/tiny_auto80_queue.cpp)
namespace n002e64b8 {
/*TARGET 002e64b8*/
u32 func_002e64b8(s32 a0, u32 a1) asm("_Z13func_002e64b8ij");
u32 func_002e64b8(s32 a0, u32 a1) {  // list_advance_count
    u32 v0 = a1 + 16;
    if (a0 > 0) {
        do {
            u32 t = *(u32*)(v0 + 12);
            a0 -= 1;
            v0 = v0 + t;
        } while (a0 != 0);
    }
    return v0;
}
}  // namespace n002e64b8

// 002e64e8 (was src/anon/batch_w214.cpp)
namespace n002e64e8 {
/*TARGET 002e64e8*/
// 0x002deac0: definition moved into src/anon/unit_002de3c8.cpp

s32 func_002e64e8(u32 a0, u32 a1, u8* a2) asm("func_002e64e8");
// 0x002deac0: definition moved into src/anon/unit_002de3c8.cpp

s32 func_002e64e8(u32 a0, u32 a1, u8* a2) {
    s32 n = *(s32*)(a2 + 12);
    a0 &= 0xff; a1 &= 0xff;
    s32 i = 0;
    u8* p = a2 + 16;
    if (n > 0) {
        s32 m = n;
        do {
            n = p[0];
            if (n == a0) { if (p[1] == a1) return i; }
            i++;
            p += *(s32*)(p + 12);
        } while (i < m);
    }
    return -1;
}
}  // namespace n002e64e8

// 002e6540, 002e6598 (were unwritten gaps): find an entry by its two id bytes; time to key position
namespace n002e6540 {
u8* gap_002e6540(u32 a0, u32 a1, u8* a2) asm("gap_002e6540");
u8* gap_002e6540(u32 a0, u32 a1, u8* a2) {
    s32 n = *(s32*)(a2 + 12);
    a0 &= 0xff; a1 &= 0xff;
    s32 i = 0;
    u8* p = a2 + 16;
    if (n > 0) {
        s32 m = n;
        do {
            n = p[0];
            if (n == a0) { if (p[1] == a1) return p; }
            i++;
            p += *(s32*)(p + 12);
        } while (i < m);
    }
    return 0;
}
struct Row { f32 v[8]; };
struct Tbl { u32 f0; s32 count; f32 start; u32 fc; Row row[1]; };
f32 gap_002e6598(Tbl* h, s32 c, f32 t) asm("gap_002e6598");
f32 gap_002e6598(Tbl* h, s32 c, f32 t) {
    s32 n = h->count;
    f32 a = h->row[0].v[c];
    f32 b = h->row[n - 1].v[c];
    s32 lo, hi;
    if (a < b) {
        if (t <= a) return h->start;
        if (b <= t) return (f32)(n - 1) + h->start;
        hi = n - 1; lo = 0;
    } else {
        if (t <= b) return h->start;
        if (a <= t) return (f32)(n - 1) + h->start;
        lo = n - 1; hi = 0;
    }
    while (hi - lo >= 2) {
        s32 mid = (hi - lo) / 2 + lo;
        f32 m = ((Row*)((u8*)h + (mid << 5) + 16))->v[c];
        if (t == m) return (f32)mid + h->start;
        if (((Row*)((u8*)h + (lo << 5) + 16))->v[c] < t && t <= m) hi = mid;
        else lo = mid;
    }
    return (t - h->row[lo].v[c]) / (h->row[hi].v[c] - h->row[lo].v[c]) + (f32)lo;
}
}  // namespace n002e6540

// 002e66f0 (was src/anon/batch_w89.cpp)
namespace n002e66f0 {
struct KEnt { u8 pad[12]; u32 loop : 1; u32 rest : 31; u8 pad2[12]; f32 t; };
struct KHdr { u32 f0; s32 count; u8 pad[8]; KEnt e[1]; };
/*TARGET 002e66f0*/
// Finds the key segment containing t: index of the left key and the blend fraction.
void func_002e66f0(KHdr* h, s32* idx, f32* frac, f32 t) asm("func_002e66f0");
// Finds the key segment containing t: index of the left key and the blend fraction.
void func_002e66f0(KHdr* h, s32* idx, f32* frac, f32 t) {
    s32 n = h->count;
    if (h->e[0].t >= t) { *idx = 0; goto zero; }
    if (h->e[n - 1].t <= t) { *idx = n - 1; goto zero; }
    {
        s32 hi = n - 1, lo = 0;
        while (hi - lo >= 2) {
            s32 mid = (hi - lo) / 2 + lo;
            f32 m = *(f32*)((u8*)h + (mid << 5) + 44);
            if (t == m) { *idx = mid; goto zero; }
            if (*(f32*)((u8*)h + (lo << 5) + 44) < t && t <= m) hi = mid;
            else lo = mid;
        }
        *idx = lo;
        if (h->e[lo].loop) goto zero;
        *frac = (t - h->e[lo].t) / (h->e[hi].t - h->e[lo].t);
        return;
    }
zero:
    *frac = 0.0f;
}
}  // namespace n002e66f0

// 002e67e8 (was an unwritten gap): path position at time t (lerp between two keys, y/z flipped, w = 0)
namespace n002e67e8 {
struct QV {
    f32 x, y, z, w;
    QV() {}
    QV(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    QV& operator=(const QV& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    QV operator+(const QV& b) const {
        QV r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    QV operator-(const QV& b) const {
        QV r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    QV operator*(f32 s) const {
        QV r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(s) : "$8", "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct KV { f32 x, y, z, w; } __attribute__((aligned(16)));
struct PathKey { KV pos; KV pad; };
struct Path { u32 pad0; s32 count; f32 start; u32 padc; PathKey key[1]; };
static inline QV conv(const KV& p) { return QV(p.x, -p.y, -p.z, 0.0f); }
void gap_002e67e8(Path* p, QV* out, f32 t) asm("gap_002e67e8");
void gap_002e67e8(Path* p, QV* out, f32 t)
{
    t -= p->start;
    s32 i = (s32)t;
    t -= (f32)i;
    if (i < 0) { t = 0.0f; i = 0; }
    s32 n = p->count - 1;
    if (i >= n) { t = 0.0f; i = n; }
    PathKey* k = &p->key[i];
    KV* a0 = &k[0].pos;
    KV* b0 = &k[1].pos;
    if (t > 9.99999975e-05f) {
        QV a = conv(*a0);
        QV b = conv(*b0);
        *out = a + (b - a) * t;
    } else {
        *out = conv(*a0);
    }
}
}  // namespace n002e67e8

// 002e6930 (was src/anon/batch_w2391_gnsa.cpp)
namespace n002e6930 {
// Built with -g and -fno-strict-aliasing (_gnsa).

// 002e6930: path direction at time t: normalized (key[i+1] - key[i]) with y/z flipped, w = 0.
// The key positions are their own vector type (KV), which lets their loads move above the QV stack stores.
struct QV {
    f32 x, y, z, w;
    QV() {}
    QV(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    QV& operator=(const QV& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    QV operator-(const QV& b) const {
        QV r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
static inline f32 Normalize(QV* v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
struct KV { f32 x, y, z, w; } __attribute__((aligned(16)));
struct PathKey { KV pos; KV pad; };
struct Path { u32 pad0; s32 count; f32 start; u32 padc; PathKey key[1]; };
static inline QV conv(const KV& p) { return QV(p.x, -p.y, -p.z, 0.0f); }
/*TARGET 002e6930*/
void func_002e6930(Path* p, QV* out, f32 t) asm("func_002e6930");
void func_002e6930(Path* p, QV* out, f32 t)
{
    s32 n = p->count - 1;
    s32 i = (s32)(t - p->start);
    if (i < 0) i = 0;
    if (i >= n) {
        QV a = conv(p->key[n - 1].pos);
        QV b = conv(p->key[n].pos);
        QV d = b - a;
        *out = d;
    } else {
        QV a = conv(p->key[i].pos);
        QV b = conv(p->key[i + 1].pos);
        QV d = b - a;
        *out = d;
    }
    Normalize(out);
}
}  // namespace n002e6930

// 002e6ab0 (was src/anon/batch_w2463_nsa.cpp)
namespace n002e6ab0 {
struct Mtx;
struct Quat;
struct QV {
    f32 x, y, z, w;
    QV() {}
    QV(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    QV operator+(const QV& b) const {
        QV r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    QV operator-(const QV& b) const {
        QV r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    QV operator*(f32 s) const {
        QV r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(s) : "$8", "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct Row {
    f32 x, y, z, w;
    void operator+=(const QV& v) {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&v) : "memory");
    }
} __attribute__((aligned(16)));
void mtx_ident(void*) asm("func_0011b6a8");
void mtx_rotxyz(Mtx*, const QV&) asm("_ZN2kn7FMatrix9rotateXYZERKNS_7FVectorE");
struct Mtx {
    Row r[4];
    Mtx() {}
    void Identity() { mtx_ident(this); }
    void RotateXYZ(const QV& v) { mtx_rotxyz(this, v); }
    void AddTrans(const QV& v) {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 48(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 48(%0)\n\t.set reorder" : : "r"(this), "r"(&v) : "memory");
    }
    Mtx& operator=(const Mtx& o) {
        if (this != &o)
            asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)\n\t.set reorder"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    Mtx operator*(const Mtx& b) const {
        Mtx o;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
            "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
            "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&b) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
void quat_dtor(Quat*) asm("_Z13func_002e44b8Pv");
void quat_from_mtx(Quat*, Mtx*) asm("func_002e42d8");
struct Quat {
    f32 x, y, z, w;
    Quat() {}
    ~Quat() { quat_dtor(this); }
} __attribute__((aligned(16)));
Quat func_002e47a8(const Quat&, const Quat&, f32) asm("func_002e47a8");
Mtx quat_to_mtx(const Quat&) asm("func_002e4588");
struct KV { f32 x, y, z, w; } __attribute__((aligned(16)));
struct PathKey { KV pos; KV rot; };
struct Path { u8 pad0[3]; u8 flags; s32 count; f32 start; u32 padc; PathKey key[1]; };
static inline QV conv(const KV& p) { return QV(p.x, -p.y, -p.z, 0.0f); }
void path_seek(Path* p, s32* idx, f32* frac, f32 t) asm("func_002e66f0");
/*TARGET 002e6ab0*/
void func_002e6ab0(Path* p, Mtx* m, f32 t) asm("func_002e6ab0");
void func_002e6ab0(Path* p, Mtx* m, f32 t)
{
    s32 idx;
    f32 frac;
    path_seek(p, &idx, &frac, t);
    PathKey* k0 = &p->key[idx];
    PathKey* k1 = &p->key[idx + 1];
    if (frac > 0.0001f) {
        QV r0(k0->rot.x, -k0->rot.y, -k0->rot.z, 0.0f);
        QV r1(k1->rot.x, -k1->rot.y, -k1->rot.z, 0.0f);
        Mtx m0, m1;
        m0.Identity();
        m1.Identity();
        m0.RotateXYZ(r0);
        m1.RotateXYZ(r1);
        Quat q0;
        quat_from_mtx(&q0, &m0);
        Quat q1;
        quat_from_mtx(&q1, &m1);
        Quat q = func_002e47a8(q0, q1, frac);
        QV a = conv(k0->pos);
        QV b = conv(k1->pos);
        QV pos = a + (b - a) * frac;
        m->Identity();
        if (p->flags & 1) {
            m->AddTrans(QV(0.0f, 100.0f, 0.0f, 0.0f));
            *m = quat_to_mtx(q) * *m;
            m->AddTrans(QV(0.0f, -100.0f, 0.0f, 0.0f));
        } else {
            *m = quat_to_mtx(q);
        }
        m->AddTrans(pos);
    } else {
        QV pos = conv(k0->pos);
        QV rot(k0->rot.x, -k0->rot.y, -k0->rot.z, 0.0f);
        m->Identity();
        if (p->flags & 1) {
            m->AddTrans(QV(0.0f, 100.0f, 0.0f, 1.0f));
            m->RotateXYZ(rot);
            m->AddTrans(QV(0.0f, -100.0f, 0.0f, 1.0f));
        } else {
            m->RotateXYZ(rot);
        }
        m->AddTrans(pos);
    }
}
}  // namespace n002e6ab0

// 002e6fc0 (was src/anon/batch_w55.cpp)
namespace n002e6fc0 {
struct HeapW55;
void* operator new[](unsigned int, HeapW55*) asm("func_001063f0");
struct ElemW55 { u8 d[64]; ElemW55() {} ~ElemW55() {} } __attribute__((aligned(16)));
u32 func_002e64b0(u32) asm("func_002e64b0");
HeapW55* func_001050c8(void) asm("func_001050c8");
// 002e6f28 (was an unwritten gap): the twin of 0x2e6fc0
void gap_002e6f28(u32* p, u32 b) asm("gap_002e6f28");
void gap_002e6f28(u32* p, u32 b) {
    p[0] = b;
    p[1] = 0;
    u32 n = func_002e64b0(b);
    p[2] = n;
    p[1] = (u32) new (func_001050c8()) ElemW55[n];
}
/*TARGET 002e6fc0*/
void func_002e6fc0(u32* p, u32 b) asm("func_002e6fc0");
void func_002e6fc0(u32* p, u32 b) {
    p[0] = b;
    p[1] = 0;
    u32 n = func_002e64b0(b);
    p[2] = n;
    p[1] = (u32) new (func_001050c8()) ElemW55[n];
}
}  // namespace n002e6fc0

// 002e7058 (was src/anon/batch_w31.cpp)
namespace n002e7058 {
struct Elem64 { u8 d[64]; ~Elem64() {} } __attribute__((aligned(16)));
/*TARGET 002e7058*/
// delete[] of an array of 64-byte elements with an empty destructor.
void func_002e7058(u8* p) asm("func_002e7058");
// delete[] of an array of 64-byte elements with an empty destructor.
void func_002e7058(u8* p) {
    delete[] *(Elem64**)(p + 4);
}
}  // namespace n002e7058

// 002e70b0 (was src/anon/batch_w32.cpp)
namespace n002e70b0 {
// 64-byte element with an empty destructor; arrays of it get a destructor loop.
struct Elem64 { u8 d[64] __attribute__((aligned(16))); ~Elem64() {} };
/*TARGET 002e70b0*/
// 0x002daca0: definition moved into src/anon/unit_002da040.cpp

// delete[] of the 64-byte element array.
void func_002e70b0(u8* o) asm("func_002e70b0");
// 0x002daca0: definition moved into src/anon/unit_002da040.cpp

// delete[] of the 64-byte element array.
void func_002e70b0(u8* o) {
    delete[] *(Elem64**)(o + 4);
}
}  // namespace n002e70b0

// 002e7108 (was src/anon/batch_w50.cpp)
namespace n002e7108 {
struct List64 { u32 f0; u8* arr; s32 n; };
u32 func_002e64b8(s32, u32) asm("func_002e64b8");
// list_advance_count
void func_002e6ab0(u32, u8*, f32) asm("func_002e6ab0");
/*TARGET 002e7108*/
// 0x002dea00: definition moved into src/anon/unit_002de3c8.cpp

void func_002e7108(List64* l, f32 x) asm("func_002e7108");
// 0x002dea00: definition moved into src/anon/unit_002de3c8.cpp

void func_002e7108(List64* l, f32 x) {
    s32 n = l->n;
    for (s32 i = 0; i < n; i++) {
        u8* e = l->arr + i * 64;
        func_002e6ab0(func_002e64b8(i, l->f0), e, x);
    }
}
}  // namespace n002e7108

// 002e7190 (was an unwritten gap): element i of a 64-byte array
namespace n002e7190 {
struct List64 { u32 f0; u8* arr; s32 n; };
u8* gap_002e7190(List64* l, s32 i) asm("gap_002e7190");
u8* gap_002e7190(List64* l, s32 i) { return l->arr + i * 64; }
}  // namespace n002e7190

// 002e71a0 (was src/anon/batch_w94.cpp)
namespace n002e71a0 {
u32 func_002e64e8(u8, u8, u32) asm("func_002e64e8");
u8* func_002e64b8(u32, u32) asm("func_002e64b8");
struct Skel2e7 {
    u32 id;
    u8* mats;
};
static inline void mcopy4(void* d, void* s) {
    asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                 "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                 : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory");
}
static inline void mmul(void* d, void* a, void* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf6x\n\tvmadday.xyzw ACC, $vf2, $vf6y\n\tvmaddaz.xyzw ACC, $vf3, $vf6z\n\tvmaddw.xyzw $vf6, $vf4, $vf6w\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf7x\n\tvmadday.xyzw ACC, $vf2, $vf7y\n\tvmaddaz.xyzw ACC, $vf3, $vf7z\n\tvmaddw.xyzw $vf7, $vf4, $vf7w\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf8x\n\tvmadday.xyzw ACC, $vf2, $vf8y\n\tvmaddaz.xyzw ACC, $vf3, $vf8z\n\tvmaddw.xyzw $vf8, $vf4, $vf8w\n\t"
                 "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)"
                 : : "r"(d), "r"(a), "r"(b) : "memory");
}
/*TARGET 002e71a0*/
// Builds a bone's model matrix by walking up its parent chain.
f32* ctarget_002e71a0(u32 out_, u32 skel_, u32 a, u32 b) asm("_Z16ctarget_002e71a0jjjj");
// Builds a bone's model matrix by walking up its parent chain.
f32* ctarget_002e71a0(u32 out_, u32 skel_, u32 a, u32 b) {
    f32* out = (f32*)out_;
    Skel2e7* sk = (Skel2e7*)skel_;
    u32 i = func_002e64e8(a, b, sk->id);
    u8* bone = func_002e64b8(i, sk->id);  // list_advance_count
    mcopy4(out, sk->mats + i * 64);
    u32 p;
    while ((p = bone[2]) < 255) {
        f32 tmp[16] __attribute__((aligned(16)));
        bone = func_002e64b8(p, sk->id);  // list_advance_count
        mmul(tmp, sk->mats + p * 64, out);
        if (out != tmp) mcopy4(out, tmp);
    }
    return out;
}
}  // namespace n002e71a0

// 002e7300 (was an unwritten gap): empty, the twin of 0x2e7308
namespace n002e7300 {
void gap_002e7300(void* self) asm("gap_002e7300");
void gap_002e7300(void* self) {}
}  // namespace n002e7300

// 002e7308 (was src/anon/misc_2.cpp)
namespace n002e7308 {
/*TARGET 002e7308*/
void func_002e7308(void* self) asm("_Z13func_002e7308Pv");
void func_002e7308(void* self) {}
}  // namespace n002e7308

// 002e7310 (was src/anon/tiny.cpp)
namespace n002e7310 {
// to_16a950
void func_002e7458(void*) asm("_Z13func_002e7458Pv");
/*TARGET 002e7310*/
// 0x002dabd0: definition moved into src/anon/unit_002da040.cpp
void func_002e7310(BD_VALUE* bd) asm("_Z13func_002e7310P8BD_VALUE");
// 0x002dabd0: definition moved into src/anon/unit_002da040.cpp
void func_002e7310(BD_VALUE* bd) { func_002e7458(bd); }
}  // namespace n002e7310

// 002e7328 (was src/anon/tiny.cpp)
namespace n002e7328 {
// to_16a950
void func_002e7458(void*) asm("_Z13func_002e7458Pv");
/*TARGET 002e7328*/
void func_002e7328(BD_VALUE* bd) asm("_Z13func_002e7328P8BD_VALUE");
void func_002e7328(BD_VALUE* bd) { func_002e7458(bd); }
}  // namespace n002e7328

// 002e7340 (was src/anon/batch_w1762_nsa.cpp)
namespace n002e7340 {
struct Node1762 { Node1762* next; s32 a; s32 b; u8* p; f32 x; f32 y; s32 c; };
struct List1762 { Node1762* head; Node1762* tail; };
extern List1762 D_01e2bf00 asm("D_01e2bf00");
void func_002e73a8(Node1762*) asm("func_002e73a8");
/*TARGET 002e7340*/
void func_002e7340(Node1762* n, s32 a, s32 b, u8* p, f32 x, f32 y) asm("func_002e7340");
void func_002e7340(Node1762* n, s32 a, s32 b, u8* p, f32 x, f32 y) {
    n->a = a;
    n->p = p + 1;
    n->b = b - 1;
    n->x = x;
    n->y = y;
    n->c = *p;
    if (D_01e2bf00.tail == 0) {
        D_01e2bf00.tail = n;
        D_01e2bf00.head = n;
        n->next = 0;
    } else {
        D_01e2bf00.tail->next = n;
        n->next = 0;
        D_01e2bf00.tail = n;
    }
    func_002e73a8(n);
}
}  // namespace n002e7340

// 002e73a8 (was src/anon/batch_w1669.cpp)
namespace n002e73a8 {
f32 func_001065a8(f32, f32) asm("_Z13func_001065a8jjjjjjjj");
/*TARGET 002e73a8*/
// 0x001a9160: definition moved into src/anon/unit_001a9130.cpp
void func_002e73a8(u8* p) asm("func_002e73a8");
// 0x001a9160: definition moved into src/anon/unit_001a9130.cpp
void func_002e73a8(u8* p) {
    *(f32*)(p + 0x1c) = func_001065a8(*(f32*)(p + 0x10), *(f32*)(p + 0x14));
}
}  // namespace n002e73a8

// 002e73d8 (was src/anon/auto80_199_queue.cpp)
namespace n002e73d8 {
/*TARGET 002e73d8*/
void func_002e73d8(u32 a0) asm("_Z13func_002e73d8j");
void func_002e73d8(u32 a0) {  // timer_decrement
    f32 t = *(f32*)(a0 + 28) - D_00349e10;
    *(f32*)(a0 + 28) = t;
    if (t <= 0.0f) {
        u32 v0 = func_001064a8(*(u32*)(a0 + 8));  // int_to_float_scaled
        u32 obj = *(u32*)(a0 + 4);
        u32 t7 = *(u32*)(a0 + 12) + v0;
        u32 vt = *(u32*)obj;
        u32 a2 = *(u32*)(a0 + 24);
        VFn73d8 fn = *(VFn73d8*)(vt + 84);
        fn(obj, *(u8*)t7, a2);
        func_002e73a8(a0);
    }
}
}  // namespace n002e73d8

// 002e7458 (was src/anon/batch_w68.cpp)
namespace n002e7458 {
// 0x002dda88: definition moved into src/anon/unit_002dd650.cpp

/* ---- 002e7458 ---- */
struct N23 { N23* next; };
struct L23 { N23* head; N23* tail; };
extern L23 D_01e2bf00 asm("D_01e2bf00");
static inline N23* Next23(N23* n) { if (!n) return D_01e2bf00.head; return n->next; }
static inline bool has23(N23* x) {
    N23* n = 0;
    while ((n = Next23(n))) if (n == x) return true;
    return false;
}
void f_002e7458(N23* n) asm("_Z13func_002e7458Pv");
/*TARGET 002e7458*/
void f_002e7458(N23* n) asm("_Z13func_002e7458Pv");
void f_002e7458(N23* n) {
    N23* prev;
    if (!has23(n)) return;
    if (n == D_01e2bf00.head) {
        D_01e2bf00.head = n->next;
        prev = 0;
    } else {
        for (prev = D_01e2bf00.head; prev->next != n; prev = prev->next) ;
        prev->next = n->next;
    }
    if (n == D_01e2bf00.tail) D_01e2bf00.tail = prev;
    n->next = 0;
}
}  // namespace n002e7458

// 002e7500 (was src/anon/batch_w5.cpp)
namespace n002e7500 {
// 0x002ddbb8: definition moved into src/anon/unit_002dd650.cpp

struct Pair { u32 a, b; };
extern Pair D_01e2bf00 asm("D_01e2bf00");
/*TARGET 002e7500*/
void func_002e7500(void) asm("func_002e7500");
void func_002e7500(void) {
    D_01e2bf00.a = 0;
    D_01e2bf00.b = 0;
}
}  // namespace n002e7500

// 002e7518 (was src/anon/batch_wcx2.cpp)
namespace n002e7518 {
// 0x001ddd30: definition moved into src/anon/unit_001ddcf0.cpp

// ---- 002e7518
struct Nd_002e7518 { Nd_002e7518* next; };
extern Nd_002e7518* D_01e2bf00 asm("D_01e2bf00");
void func_002e73d8(Nd_002e7518*) asm("func_002e73d8");
static inline Nd_002e7518* Next_002e7518(Nd_002e7518* n) { if (!n) return D_01e2bf00; return n->next; }
void wt_002e7518() asm("_Z16wtarget_002e7518jjjj");
/*TARGET 002e7518*/
void wt_002e7518() asm("_Z16wtarget_002e7518jjjj");
void wt_002e7518() {
    Nd_002e7518* n = 0;
    while ((n = Next_002e7518(n))) func_002e73d8(n);
}
}  // namespace n002e7518

// 002e7568 (was src/anon/batch_wcx.cpp)
namespace n002e7568 {
// 0x002b5a50: definition moved into src/anon/unit_002b3ac8.cpp

f32 func_00106558(f32) asm("func_00106558");
s32 func_001064a8(s32) asm("func_001064a8");
// int_to_float_scaled
typedef void (*Fn84)(u8*, s32, s32);
/*TARGET 002e7568*/
// 002e7568: with probability x pick a random entry of the table and apply it
s32 func_002e7568(u8* obj, s32 n, u8* tbl, f32 x) asm("func_002e7568");
// 002e7568: with probability x pick a random entry of the table and apply it
s32 func_002e7568(u8* obj, s32 n, u8* tbl, f32 x)
{
    s32 m = n - 1;
    if (x < 1.0f && x < func_00106558(1.0f)) return -1;
    s32 a = tbl[0];
    s32 b = tbl[func_001064a8(m) + 1];
    (*(Fn84*)(*(u8**)obj + 84))(obj, b, a);
    return b;
}
}  // namespace n002e7568

// 002e7610 (was src/anon/batch_w1669.cpp)
namespace n002e7610 {
struct W1669Pair { u32 a, b; };
extern W1669Pair D_01e2bf00 asm("D_01e2bf00");
// 0x002ce910: definition moved into src/taito/path.cpp
void wtarget_002e7610(u32 a0, u32 a1, u32, u32) asm("_Z16wtarget_002e7610jjjj");
/*TARGET 002e7610*/
void wtarget_002e7610(u32 a0, u32 a1, u32, u32) asm("_Z16wtarget_002e7610jjjj");
void wtarget_002e7610(u32 a0, u32 a1, u32, u32) {
    if (a1 == 0xffff && a0 == 1) { D_01e2bf00.b = 0; D_01e2bf00.a = 0; }
}
}  // namespace n002e7610

// 002e7638 (was src/anon/tiny_wrappers_more.cpp)
namespace n002e7638 {
u32 func_002e7610(u32, u32, u32, u32) asm("_Z13func_002e7610jjjj");
/*TARGET 002e7638*/
// 0x002e18b8: definition moved into src/anon/unit_002de3c8.cpp

// 002e2428: moved to src/anon/unit_002e1908.cpp

// 002e2c50: moved to src/anon/unit_002e1908.cpp

// 002e2c68: moved to src/anon/unit_002e1908.cpp

// 002e2c80: moved to src/anon/unit_002e1908.cpp

// 002e2e90: moved to src/anon/unit_002e2d18.cpp

// 002e33d8: moved to src/anon/unit_002e2f08.cpp

// 002e33f8: moved to src/anon/unit_002e2f08.cpp

// 002e3ca8: moved to src/anon/unit_002e2f08.cpp

// 002e3cc8: moved to src/anon/unit_002e2f08.cpp

// 002e3ef8: moved to src/anon/unit_002e2f08.cpp

u32 func_002e7638(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002e7638jjjj");
// 0x002e18b8: definition moved into src/anon/unit_002de3c8.cpp

// 002e2428: moved to src/anon/unit_002e1908.cpp

// 002e2c50: moved to src/anon/unit_002e1908.cpp

// 002e2c68: moved to src/anon/unit_002e1908.cpp

// 002e2c80: moved to src/anon/unit_002e1908.cpp

// 002e2e90: moved to src/anon/unit_002e2d18.cpp

// 002e33d8: moved to src/anon/unit_002e2f08.cpp

// 002e33f8: moved to src/anon/unit_002e2f08.cpp

// 002e3ca8: moved to src/anon/unit_002e2f08.cpp

// 002e3cc8: moved to src/anon/unit_002e2f08.cpp

// 002e3ef8: moved to src/anon/unit_002e2f08.cpp

u32 func_002e7638(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002e7610(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n002e7638

