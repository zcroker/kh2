#include "../common/types.h"

struct W260B20 { union { int w[5]; u8 c; }; };
struct W260Hdr { u16 h0; u16 h2; u8 b4; u8 b5; u8 b6, b7; W260B20* p8; };
struct W260Ent { u8 pad[12]; W260B20 d; u8 pad2[4]; W260Hdr hdr; };
struct W260Q { f32 x, y, z, w; } __attribute__((aligned(16)));
struct W260Cam { u8 pad0[16]; f32 x, y, z; };
struct W260Z { u8 pad[12]; int f12; u8 pad2[20]; u8 b36; };
struct W260V {
    f32 x, y, z, w;
    W260V() {}
    W260V(const W260V& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W260V& operator=(const W260V& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
// VU0 dot product of the xyz parts.
static inline __attribute__((always_inline)) f32 W260Dot(const W260V& a, const W260V& b)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(&a), "r"(&b) : "$8", "memory");
    return r;
}
// VU0 squared length of the xyz part.
static inline __attribute__((always_inline)) f32 W260LenSq(const W260Q& a)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(&a) : "$8", "memory");
    return r;
}
struct W260Lim { u8 pad[34]; u8 b34; s8 b35; };
struct W260Own { u8 pad[12]; int f12; u8 pad2[24]; W260Lim* p40; };
struct W260Tgt;
struct W260TgtVT { void* p[3]; W260V (*f12)(W260Tgt*, int); };
struct W260Tgt { W260TgtVT* vt; };
struct W260Ctl { W260Own* own; };
struct W260Col { f32 a[3]; int n; W260Q b; W260Col() : n(0) {} };
struct W260Tg { u8* obj; };
extern "C" int w260_is_exist(W260Tg*) asm("_ZNK2YS6TARGET8is_existEv");
static inline __attribute__((always_inline)) bool W260Valid(W260Tg* t) { return w260_is_exist(t) && t->obj; }

extern "C" {
W260Z* w260_u_call4(int) asm("_Z16u_call4_001b8e88jjjj");
int w260_is_same(void*, void*) asm("_ZNK2YS6TARGET7is_sameERKS0_");
void func_0019d548(W260Ent*);
void func_0019d588(W260Ent*, int);

void func_0019d5f8(W260Ent* e, W260Hdr* h)
{
    W260Z* z = w260_u_call4(h->h2);
    if (e->hdr.h2 != h->h2 || !w260_is_same(&e->d, h->p8)) func_0019d548(e);
    if (e->hdr.h2 == h->h2 && e->hdr.b5 != h->b5 && e->hdr.b5 == 8 && (u8)((z->f12 >> 3) & 1)) h->h0 |= 2;
    e->hdr = *h;
    __builtin_memcpy(&e->d, h->p8, 20);
    e->hdr.p8 = &e->d;
    func_0019d588(e, h->b5 == 8 ? 0 : z->b36);
}

u8 func_002f3f88(void*, void*);  // memcpy16
void func_002f3d98(W260Q*, W260Q*);  // vec4_normalize
void func_002f3d50(W260Q*, W260Q*, W260Q*);  // vec3_cross
void w260_mtx(void*, void*, void*) asm("_Z16wtarget_002f3d08jjjj");
extern u8 D_00354bc0[];
extern u8 D_00354be0[];
extern W260Cam D_01d9e840;
extern W260Q D_01d9e870, D_01d9e880, D_01d9e890, D_01d9e8a0, D_01d9e8b0;
extern u8 D_01d9e8c0[], D_01d9e940[];

void func_00200950(u8* p, u8* q)
{
    W260Q a, b, c;
    u8* s = p + *(s32*)(*(u8**)(q + 12) + 4);
    func_002f3f88(s + 160, D_00354bc0);  // memcpy16
    func_002f3f88(s + 176, D_00354be0);  // memcpy16
    b.x = D_01d9e840.x; b.w = 0; b.y = D_01d9e840.y; b.z = D_01d9e840.z;
    func_002f3d98(&b, &b);  // vec4_normalize
    D_01d9e890 = b;
    a.x = b.y; a.y = -b.x; a.z = 0; a.w = 0;
    func_002f3d98(&a, &a);  // vec4_normalize
    D_01d9e880 = a;
    func_002f3d50(&c, &a, &b);  // vec3_cross
    func_002f3d98(&c, &c);  // vec4_normalize
    D_01d9e8a0 = c;
    D_01d9e8b0 = D_01d9e870;
    w260_mtx(D_01d9e940, D_01d9e8c0, &D_01d9e880);
}

f32 func_002f87c0(f32);
W260V func_0016af58(int);
W260V func_0017d538(const W260V&, f32);

int func_0018e698(W260Ctl* c, W260Tgt** t)
{
    u8 b = c->own->p40->b34;
    if (!b) return 1;
    f32 lim = -func_002f87c0((f32)b * 0.017453292f);
    W260V d;
    d = func_0016af58(c->own->f12);
    s8 e = c->own->p40->b35;
    if (e) d = func_0017d538(d, (f32)(e * 2) * 0.017453292f);
    W260V w = (*t)->vt->f12(*t, c->own->f12);
    return W260Dot(w, d) < lim;
}

W260Q func_00190388(W260Tg*);  // vec4_from_arg
int func_0016bba8(u8*, int, int);
void func_0018a818(W260Col*, u8*, int);

int func_00112f88(W260Tg* t)
{
    int best = 0;
    if (W260Valid(t)) {
        u8* o = t->obj;
        if (*(u32*)(o + 1416) & 2) {
            W260Col r;
            f32 bd = 0;
            W260Q tp = func_00190388(t);  // vec4_from_arg
            int c = 0;
            while ((c = func_0016bba8(o, 2, c)) != 0) {
                func_0018a818(&r, o, c);
                W260Q d;
                asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)" : : "r"(&tp), "r"(&r.b), "r"(&d) : "memory");
                f32 ds = W260LenSq(d);
                if (!best || ds < bd) { bd = ds; best = c; }
            }
        }
    }
    return best;
}

}
