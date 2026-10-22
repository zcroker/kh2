#include "../common/types.h"
// 0016a9b8: VU0 macro zero store and a 16-byte lq/sq copy as inline asm.
struct W2044Obj;
struct W2044PVt { u8 pad[16]; void (*f16)(struct W2044P*, W2044Obj*); u8 pad2[4]; void (*f24)(struct W2044P*, W2044Obj*); };
struct W2044P { W2044PVt* vt; u8 pad[4]; u32 flags; };
struct W2044OVt { u8 pad[44]; void (*f44)(W2044Obj*); };
struct W2044Q { u8 pad[72]; u16 b0:5; u16 bit:1; };
struct W2044V4 { f32 x, y, z, w;
  W2044V4& operator=(const W2044V4& o) { if (this != &o) asm volatile("lq $8,0(%1)\n\tsq $8,0(%0)" :: "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
struct W2044Obj {
  W2044OVt* vt; u8 pad4[4]; W2044Q* q; W2044P* p;   // 0..16
  u8 pad16[16];
  W2044V4 v32;                 // 32
  u8 pad48[208-48];
  f32 f208; s32 f212; f32 f216; union { f32 f; s32 i; } f220; // 208..224
  u8 pad224[264-224];
  u32 f264; // 264
  u8 pad268[284-268];
  f32 f284;
  u8 pad288[352-288];
  u32 f352;
  u8 pad356[496-356];
  W2044V4 v496;
  u8 pad512[1184-512];
  u8 sub1184[1288-1184];
  void* p1288;
  u8 pad1292[1348-1292];
  f32 f1348;
  u8 pad1352[1372-1352];
  f32 f1372;
  u8 pad1376[1644-1376];
  f32 f1644;
  u8 pad1648[2144-1648];
  W2044V4 v2144;
};
extern "C" {
s32 func_001c0cd8(W2044Obj*);
s32 func_0019c400(W2044Obj*);
f32 func_0017ce80(f32, f32, f32);
void func_0016ae58(W2044Obj*, f32);
void func_002ccf98(void*, W2044Obj*);
void func_001b04d8(void*);
void func_00194318(W2044Obj*);
extern f32 D_00349e10;

static inline u32 t264a(W2044Obj* o) { return o->f264 & 0x800000; }
static inline u32 t264b(W2044Obj* o) { return o->f264 & 0x1000000; }
static inline u32 t352a(W2044Obj* o) { return o->f352 & 0x20; }
static inline u32 t352b(W2044Obj* o) { return o->f352 & 0x1000000; }
static inline u32 t352c(W2044Obj* o) { return o->f352 & 0x40; }
static inline u32 tp2(W2044P* p) { return p->flags & 2; }
static inline u32 tp20(W2044P* p) { return p->flags & 0x20; }
static inline bool isA(W2044Obj* o) { return t264a(o) || t264b(o); }
static inline bool isC(W2044Obj* o) { return t352a(o) || t352b(o); }
static inline bool isB(W2044Obj* o) { return isC(o) || t352c(o); }
static inline bool qbit(W2044Obj* o) { return o->q->bit; }
static inline bool notB(W2044Obj* o) { return !isB(o); }

void func_0016a9b8(W2044Obj* o) {
  if (!tp2(o->p) || tp20(o->p)) {
    if (func_001c0cd8(o) == 0 && isA(o) && notB(o)) {
      asm volatile("vsub.xyzw $vf1,$vf0,$vf0\n\tsqc2 $vf1,0(%0)" :: "r"(&o->v496) : "memory");
      o->f264 &= ~0x4000000;
      W2044P* p = o->p;
      p->vt->f16(p, o);
      if (!(o->f264 & 0x4000000)) o->vt->f44(o);
      o->f220.i = 0;
      o->f212 = 0;
      f32 y = o->v2144.y;
      f32 t = (o->f220.f < y) ? y / 0.40816324949264526f : o->f220.f;
      o->f208 = t;
      o->f216 = o->f1348 - t * 0.40816324949264526f * t * 0.5f;
      o->v32 = o->v2144;
    }
  }
  W2044P* p = o->p;
  p->vt->f24(p, o);
  if (func_0019c400(o) == 0) func_0016ae58(o, func_0017ce80(o->f1372, o->f1644, o->f284 * D_00349e10));
  if (o->p1288) func_002ccf98(o->p1288, o);
  func_001b04d8(o->sub1184);
  if (qbit(o)) func_00194318(o);
}
}

// 002e4af8: lq/sq copy, VU0 vector subtract and length as inline asm.
struct W2044QV { f32 x, y, z, w;
  W2044QV() {}
  W2044QV(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
  W2044QV& operator=(const W2044QV& o) { if (this != &o) asm volatile("lq $8,0(%1)\n\tsq $8,0(%0)" :: "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
static inline W2044QV operator-(const W2044QV& a, const W2044QV& b) { W2044QV r; asm volatile("lqc2 $vf1,0(%1)\n\tlqc2 $vf2,0(%2)\n\tvsub.xyzw $vf1,$vf1,$vf2\n\tsqc2 $vf1,0(%0)" :: "r"(&r), "r"(&a), "r"(&b) : "memory"); return r; }
static inline f32 vlen(const W2044QV& v) { f32 l; asm volatile("lqc2 $vf1,0(%1)\n\tvmul.xyz $vf1,$vf1,$vf1\n\tvaddy.x $vf1,$vf1,$vf1y\n\tvaddz.x $vf1,$vf1,$vf1z\n\tvsqrt Q,$vf1x\n\tvwaitq\n\tcfc2.ni $8,$vi22\n\tmtc1 $8,%0" : "=f"(l) : "r"(&v) : "$8", "memory"); return l; }
struct W2044Node { W2044QV pos, v1, v2, v3, v4; u8 flag; u8 pad[15]; };
struct W2044Seg { f32 a; s32 b; f32 len; };
struct W2044Rope { f32 len; u8 pad[12]; W2044Node n[41]; W2044Seg s[40]; f32 tbl[11]; };
extern "C" {
f32 func_002f8ae8(f32);
void func_002e4af8(W2044Rope* r) {
  f32 h = r->len * 0.5f;
  s32 i;
  for (i = 0; i < 41; i++) {
    W2044Node* n = &r->n[i];
    n->pos = W2044QV(r->len * i / 40.0f - h, 0.0f, 0.0f, 0.0f);
    n->v3 = W2044QV(0.0f, 0.0f, 0.0f, 0.0f);
    n->v4 = W2044QV(0.0f, 0.0f, 0.0f, 0.0f);
    n->v2 = W2044QV(0.0f, 0.0f, 0.0f, 0.0f);
    n->v1 = W2044QV(0.0f, 0.0f, 0.0f, 0.0f);
    n->flag = 0;
  }
  r->n[0].flag = 1;
  r->n[40].flag = 1;
  s32 j = 0;
  for (; j < 40; ) {
    s32 k = j + 1;
    W2044Seg* s = &r->s[j];
    s->a = 1000.0f;
    s->b = 0;
    s->len = vlen(r->n[j].pos - r->n[k].pos);
    j = k;
  }
  s32 m;
  s32 n = 10;
  for (m = 0; m <= n; m++) {
    f32 x = m * 1.3f / n;
    r->tbl[m] = func_002f8ae8(-x * x);
  }
}
}
