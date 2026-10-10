#include "../common/types.h"

struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));

extern "C" {

void func_001396b0(u8*);
void func_0031a260(u8*, s32);
void func_0031ac78(u8*, s32);

// 00138748: reset the state block and run the two settle passes
void func_00138748(u8* p)
{
    *(u32*)(p + 368) = 0;
    *(u32*)(p + 372) = 0;
    *(u32*)(p + 376) = 0;
    *(f32*)(p + 384) = 1.0f;
    *(u32*)(p + 380) = 0;
    *(u32*)(p + 396) = 0;
    func_001396b0(p);
    if (*(u32*)(p + 396)) {
        *(u32*)(p + 400) = 0;
        func_001396b0(p);
        if (*(u32*)(p + 400)) func_0031a260(p, 0);
    }
    *(u32*)(p + 400) = 0;
    func_001396b0(p);
    if (*(u32*)(p + 400)) {
        *(u32*)(p + 396) = 0;
        func_001396b0(p);
        if (*(u32*)(p + 396)) func_0031ac78(p, 0);
    }
    p[405] = 0;
}

void func_00138d60(u8*, s32, u32, u32, u32, u32, u32);
void func_00139620(u8*);
void func_00239988(u8*, u32, u32);
void func_0013ac60(u8*, u32, u32);

void func_0013aa78(u8* p, u32 x, u32 y, u32 z, u32 w, u32 v, u32 u)
{
    func_00138d60(p, 5303, y, z, x, 0, v);
    *(s32*)(p + 412) = 10;
    *(s32*)(p + 416) = -7;
    *(s32*)(p + 424) = 14;
    *(s32*)(p + 428) = 1;
    func_00139620(p);
    func_00239988(p + 436, y, z);
    func_0013ac60(p, u, w);
}

s32 func_0013d390(void);
void func_00139a38(s32);
void func_001399c0(s32);
void func_00139ab0(s32);
void func_00139948(s32);
void func_0013b2d8(f32);
f32 func_0013b2a8(u8*);  // mul_float684_692
void func_00138d48(u8*, f32, f32, f32, f32);

void func_0013d3f8(u8* p)
{
    if (!p[253]) {
        if (func_0013d390() == 0) {
            func_00139a38(2);
            func_001399c0(2);
        } else {
            p[253] = 1;
            func_0013b2d8(1.0f);
            func_00139ab0(2);
            func_00139948(2);
        }
    }
    func_00138d48(p + 260, 1.0f, 1.0f, 1.0f, func_0013b2a8(p));
}

f32 func_002f8870(f32);  // fabsf
void func_0013fda0(u8*);
void func_0013fdc8(u8*);

// 00140150: step the value at +72 towards the target at +200
void func_00140150(u8* p, f32 x)
{
    if (func_002f8870(*(f32*)(p + 72) - *(f32*)(p + 200)) >= 1.0f) {  // fabsf
        if (*(f32*)(p + 200) < *(f32*)(p + 72)) {
            *(f32*)(p + 72) = *(f32*)(p + 72) - x * 0.5f;
            func_0013fda0(p);
        } else {
            *(f32*)(p + 72) = *(f32*)(p + 72) + x * 0.5f;
            func_0013fdc8(p);
        }
    }
}

s32 func_0015b4f8(void*, u32, s32*);
void func_00239c38(void*, s32);
s32 func_0023aa98(void*);
extern u8 D_0034a5e8[];
struct E344 { u8 d[344]; };
struct S151 { u8 pad[456]; E344 e[7]; s32 arr[7]; u32 key; s32 n; };

// 00151d48: load up to 7 entries and keep a running total of their sizes
void func_00151d48(S151* p)
{
    s32 buf[8];
    s32 sum = 0;
    p->n = func_0015b4f8(D_0034a5e8, p->key, buf);
    for (s32 i = 0; i < p->n; i++) {
        func_00239c38(&p->e[i], buf[i]);
        sum += func_0023aa98(&p->e[i]);
        p->arr[i] = sum;
    }
}

extern void* D_0034aaa8;
extern void* D_0034aaa4;
extern void* D_0034aa9c;
extern void* D_0034aaa0;
typedef void (*VFn)(void*);
#define VDEL(o) if (o) { (*(VFn*)(*(u8**)o + 16))(o); o = 0; }
void func_0015b100(void*) asm("_Z13func_0015b100Pv");
// 0015b100: destroy the four global singletons
void func_0015b100(void*)
{
    VDEL(D_0034aaa8);
    VDEL(D_0034aaa4);
    VDEL(D_0034aa9c);
    VDEL(D_0034aaa0);
}

extern u8 D_0034af40[];
extern u8 D_0034b0e0[];
void func_002361a0(u8*);
void func_00239700(u8*);
void func_00239870(u8*);
void func_002361d0(u8*);
void wtarget_0015d730(u32, u32, u32, u32) asm("_Z16wtarget_0015d730jjjj");
void wtarget_0015d730(u32 a, u32 b, u32, u32)
{
    if (b == 0xffff && a == 1) func_002361a0(D_0034af40);
    if (b == 0xffff && a == 1) func_00239700(D_0034b0e0);
    if (b == 0xffff && a == 0) func_00239870(D_0034b0e0);
    if (b == 0xffff && a == 0) func_002361d0(D_0034af40);
}

extern u8 D_003502d8[];
extern u8 D_0032bae0[];
void func_001980d0(u8*, u32, s32, u32);
u32 func_0016ac38(u8*, s32, s32, s32, s32);
s32 func_0016a020(u8*);
s32 func_00196388(u8, u8);
void func_001963c8(s32);

void func_00195e28(u8* p, u32 a, u32 b)
{
    func_001980d0(p, a, 7, b);
    *(u32*)(p + 2552) = 0;
    *(void**)p = D_003502d8;
    p[2557] = 1;
    *(u32*)(p + 1416) |= 0x1000;
    p[2556] = 0;
    *(u32*)(p + 2548) = func_0016ac38(p, 1, 1, 0, 0);
    if (func_0016a020(p) == 569) {
        s32 r = func_00196388(D_0032bae0[0], D_0032bae0[1]);
        if (r >= 0) func_001963c8(r);
    }
}

extern u8 D_00350e8c;
extern u32 D_0034f240;
s32 func_0019c590(void);
s32 func_0019c768(u8*);
s32 func_002be5f8(void);

s32 func_0019c650(u8* p)
{
    s32 r;
    u32 f = *(u32*)(p + 268);
    u32 b = f & 0x80;
    u32 a = f & 0x200;
    r = 0;
    if (b || a || D_00350e8c || func_0019c590() || (D_0034f240 & 0x1000) || func_0019c768(p) || func_002be5f8()) r = 1;
    return r;
}

u8* func_001ba158(void);
s32 func_0019ba60(u8*);

// 001a2200: scale a count by the party size (divide when the flag is set)
s32 func_001a2200(u8* p, s32 n)
{
    if (n <= 0) return n;
    if (!(D_0034f240 & 0x20000)) return n;
    s32 c = *(s32*)(func_001ba158() + 8) + 1;
    if (c < 2) return n;
    if (func_0019ba60(*(u8**)(p + 604)) && (*(u32*)(*(u8**)(p + 604) + 1416) & 0x80)) {
        n /= c;
        if (n <= 0) n = 1;
    } else {
        n *= c;
    }
    return n;
}

struct Rd { u32 a; u32 obj; u32 buf; u32 size; u32 e; };
extern Rd D_00350cb0;
extern u8 D_00350ca8[];
s32 func_002f79c8(s32);
s32 func_002f7be8(u32, u32, u32, u8*);
void func_001ae678(void);  // to_306698_arg10

// 001ae8d8: record a read request and retry until the drive accepts it
void func_001ae8d8(u8* p, u32 buf, u32 size, u32 a, u32 e)
{
    u32* f = (u32*)(*(u32*)(p + 8) + 8);
    D_00350cb0.a = a;
    D_00350cb0.obj = *(u32*)(p + 8);
    D_00350cb0.size = size;
    D_00350cb0.buf = buf;
    D_00350cb0.e = e;
    u32 n = (size + 2047) >> 11;
    for (;;) {
        if (func_002f79c8(1) == 2 && func_002f7be8(*f, n, buf, D_00350ca8) == 1) break;
        func_001ae678();  // to_306698_arg10
    }
}

V4* func_0016c028(u8*);  // obj_get_attach_or_alt
f32 func_001849d8(u8*);

s32 func_001b2d10(u8* p, f32* q)
{
    V4 t;
    V4* src = func_0016c028(p);  // obj_get_attach_or_alt
    // 128-bit copy (lq/sq)
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&t), "r"(src) : "$8", "memory");
    f32 s = t.y + q[1];
    if (func_001849d8(p) - 100.0f <= s) { q[1] = 0; return 1; }
    if (*(f32*)(p + 224) <= s) { q[1] = *(f32*)(p + 224) - t.y; return 1; }
    return 0;
}

struct Bits { u32 a, b; u64 on; u64 off; };
extern u8* D_01d49978;
extern u8 D_00321058[];
Bits* func_002fd248(u32, u8*, u32, s32, u8*);
void func_0015ee90(s32);
void func_0015ee10(s32);

void func_001c8ec0(u32 a0)
{
    Bits* b = func_002fd248(a0, D_01d49978 + 8, *(u32*)(D_01d49978 + 4), 24, D_00321058);
    for (s32 i = 0; i < 64; i++) {
        if ((u8)((b->on >> i) & 1)) func_0015ee90(i);
        else if ((u8)((b->off >> i) & 1)) func_0015ee10(i);
    }
}

struct B32 { f32 a, y, c; u32 d; V4 pos; };
struct It { u8* cur; u8 pad[28]; };
void func_00190128(It*);
u8* func_00190730(It*, u8*);
void func_001cdbc8(u32, B32*, s32);
void func_0018a818(B32*, u8*, u8*);

void func_001cddb8(u32 a)
{
    It it;
    func_00190128(&it);
    B32 b;
    b.d = 0;
    u8* o = 0;
    while ((o = func_00190730(&it, o)) != 0) {
        if (*(u32*)(it.cur + 1416) & 0x20000) {
            func_0018a818(&b, it.cur, o);
            func_001cdbc8(a, &b, 2);
        }
    }
}

void func_001d1720(u8*, s32);
void func_001d17b0(u8*, s32);

// 001d1da0: clamp the gauge value to [0, max], firing the empty/full events
void func_001d1da0(u8* p, f32 x)
{
    if (x <= 0.0f) {
        if (0.0f < *(f32*)(p + 44)) func_001d1720(p, 136);
        x = 0.0f;
    } else if ((f32)*(s32*)(p + 24) <= x) {
        if (*(f32*)(p + 44) < (f32)*(s32*)(p + 24)) func_001d1720(p, 137);
        x = (f32)*(s32*)(p + 24);
    }
    func_001d17b0(p, (s32)x);
    *(f32*)(p + 44) = x;
}

extern u8* D_0035ed4c;
extern s8 D_0035ed69;
extern u8* D_0035ed64;
s32 func_002891e8(u8*);
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void func_00138c10(u8*, s32);
void func_00243230(s32, s32);

void func_002493c8(void)
{
    s32 i = func_002891e8(D_0035ed4c);
    if (!((D_0035ed69 >> i) & 1)) return;
    if (u_call4_00139d78(D_0035ed64 + i * 408)) {
        u8* o = D_0035ed64 + i * 408;
        if (*(s32*)(o + 388) != 37) func_00138c10(o, 37);
    }
    func_00243230(5, i);
}

extern u8* D_0035edcc;
extern u8* D_0035edd0;
s32 func_002892f8(u8*);
s32 func_0028acc8(u8*);
void func_00288e88(u8*);

void func_0024dea8(void)
{
    if (D_0035edcc) {
        s32 a = func_002892f8(D_0035edcc);
        if (!func_0028acc8(D_0035edcc) && a) func_00288e88(D_0035edcc);
    }
    if (D_0035edd0) {
        s32 a = func_002892f8(D_0035edd0);
        if (!func_0028acc8(D_0035edd0) && a) func_00288e88(D_0035edd0);
    }
}

}

extern "C" {

u8* func_00294000(s32);
s32 func_00276c18(void);
struct Ent16 { u16 id; u8 pad[14]; };
s32 func_002a99c8(Ent16*);

// 002a9b88: is there a matching table-8 entry (id < 0 = any) that accepts?
s32 func_002a9b88(s32 id)
{
    u8* t = func_00294000(8);
    Ent16* e = (Ent16*)(t + 16);
    s32 i;
    for (i = 0; i < *(s32*)(t + 8); i++) {
        if (id >= 0 && e[i].id != id) continue;
        if (func_00276c18()) break;
        if (func_002a99c8(&e[i])) break;
    }
    return i < *(s32*)(t + 8);
}

// Tz::CmSLBase::GetCurrentListItem: release every live item in the 3x4 slot grid
extern u8* D_0035f690[3][4];
void CmSLBase_GetCurrentListItem(void) asm("_ZN2Tz8CmSLBase18GetCurrentListItemEv");
void CmSLBase_GetCurrentListItem(void)
{
    for (s32 i = 0; i < 3; i++) {
        u8** p = D_0035f690[i];
        for (s32 j = 3; j >= 0; j--, p++) {
            if (*p) {
                if (u_call4_00139d78(*p)) (*(VFn*)(*(u8**)*p + 20))(*p);
                *p = 0;
            }
        }
    }
}

f32 func_00106558(f32);
s32 func_001064a8(s32);  // int_to_float_scaled
typedef void (*Fn84)(u8*, s32, s32);

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

u32 func_002eaf40(u8*);
s32 func_001c0cd8(u32);
void func_0017f488(u8*, s32, f32, f32);
s32 func_0019c090(u8*);  // obj_is_enabled
void func_0017c430(u8*, s32, f32);
void func_0016bd60(u8*, s32);

s32 func_002eb3b8(u8* p)
{
    u32 r = func_002eaf40(p);
    u8* q = p + 320;
    if ((*(u32*)(p + 352) & 0x4000) && func_001c0cd8(r)) return 0;
    if (*(u32*)(p + 352) & 0x4000) func_0017f488(q, 0, 0.0f, 0.0f);
    if (func_0019c090(p)) {  // obj_is_enabled
        func_0017c430(p, 0, 0.0f);
        func_0016bd60(p, 1);
    } else {
        func_0016bd60(p, 0);
    }
    return 1;
}

}

extern "C" {
// 002ffc50: newlib __sbprintf: print through an unbuffered stream via a stack buffer
struct SFile {
    u8* p; s32 r; s32 w; u16 flags; s16 file; u8* base; s32 size; s32 lbfsize;
    void* cookie; void* read; void* write; void* seek; void* close;
    u8 pad[36]; void* data; u8 pad2[8];
};
s32 func_002ffd00(SFile*, const char*, void*);  // fprintf_stream_va
s32 func_00302b18(SFile*);
s32 func_002ffc50(SFile* fp, const char* fmt, void* ap)
{
    SFile fake;
    u8 buf[1024];
    fake.data = fp->data;
    fake.flags = fp->flags & ~2;
    fake.file = fp->file;
    fake.cookie = fp->cookie;
    fake.write = fp->write;
    fake.base = fake.p = buf;
    fake.size = fake.w = 1024;
    fake.lbfsize = 0;
    s32 ret = func_002ffd00(&fake, fmt, ap);  // fprintf_stream_va
    if (ret >= 0 && func_00302b18(&fake)) ret = -1;
    if (fake.flags & 0x40) fp->flags |= 0x40;
    return ret;
}
}

extern "C" {
// 0031f820 / 0031c518: destructors (member arrays destroyed back to front)
extern u8 D_00350bb0[];
extern u8 D_0034e8a8[];
void func_00239870(u8*);
void func_00239848(u8*);  // set_vtbl_36eb28_then_call
void func_001ac5b8(u8*);
void func_00105110(u8*);
void func_0031f820(u8* p)
{
    *(void**)p = D_00350bb0;
    if (p != (u8*)-1544) {
        u8* q = p + 2920;
        u8* a = p + 1544;
    loop1544:
        if (a == q) goto done1544;
        q -= 344;
        (**(VFn**)q)(q);
        goto loop1544;
    }
done1544:
    func_00239870(p + 1200);
    func_00239870(p + 848);
    func_00239870(p + 484);
    *(void**)(p + 132) = D_0034e8a8;
    func_00239848(p + 132);  // set_vtbl_36eb28_then_call
    func_001ac5b8(p);
    func_00105110(p);
}
extern u8 D_0034a5d0[];
extern u8 D_00347e80[];
extern u8 D_00347f98[];
extern u32 D_00347f80;
void func_002361d0(u8*);
typedef void (*FreeFn)(u8*, u8*);
void func_0031c518(u8* p)
{
    *(void**)p = D_0034a5d0;
    if (p != (u8*)-840) {
        u8* q = p + 2880;
        u8* a = p + 840;
    loop840:
        if (a == q) goto done840;
        q -= 408;
        (*(VFn*)(*(u8**)q + 12))(q);
        goto loop840;
    }
done840:
    func_00239870(p + 496);
    *(void**)(p + 48) = D_00347e80;
    func_002361d0(p + 80);
    *(u32*)(p + 48) = (u32)D_00347f98;
    *(u32*)p = (u32)D_00347f98;
    u8* al = *(u8**)(D_00347f80 + 20);
    (*(FreeFn*)(*(u8**)al + 4))(al, p);
}
}

extern "C" {
// 0016d760: pos += normalize(dir) * speed * dt (VU0 macro code, hand-written asm)
extern f32 D_00349e10;
static inline f32 VNormalize(V4* d, V4* s)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%2)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(d), "r"(s) : "$8", "memory");
    return r;
}
static inline void VScale(V4* d, V4* s, f32 k)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(s), "f"(k) : "$8", "memory");
}
static inline void VAdd(V4* d, V4* a, V4* b)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
struct Mv { V4* pos; V4* dir; f32 speed; };
void func_0016d760(Mv* m)
{
    V4* pos = m->pos;
    V4 n;
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&n), "r"(m->dir) : "$8", "memory");
    VNormalize(&n, &n);
    V4 b, a;
    VScale(&a, &n, m->speed);
    VScale(&b, &a, D_00349e10);
    VAdd(pos, pos, &b);
}
}
namespace w70_p {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
struct M4 { V4 r[4]; };
extern M4 D_003478f0;
static inline void VCp(V4* d, V4* s) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory"); }

typedef void (*Fn52)(u8*, s32, u32);
u8* func_00124748(u8*, s32);  // list_nth_node_rel

void func_00138988(u8*);
void func_00138de0(u8*);
extern s32 D_0034805c;
void func_0023a9c0(u8*, s32*, s32*);
s32 func_0023aa18(u8*);
s32 func_0023aa38(u8*);
void func_0023ade0(u8*);

extern u8* D_003484a0;
extern u32 D_00348050;
struct P2 { u32 a, b; };
extern P2 D_00348578;
void func_0013b348(s32);
void func_00138698(u32, u32);
void func_0013d4c8(void);
u8* func_0013cb80(void);  // get_global_358050
void func_001387f8(u8*, u32, u8*, u32);
void func_0013b2d8(f32);
void func_0013d6b0(u32 a, u32 b)
{
    if (!D_003484a0) func_0013b348(0);
    func_00138698(D_00348050, a);
    *(u32*)(D_003484a0 + 676) = b;
    func_0013d4c8();
    u8* r = func_0013cb80();  // get_global_358050
    func_001387f8(D_003484a0 + 260, b, r + 32, D_00348578.a);
    *(u32*)(D_003484a0 + 652) = D_00348578.b;
    func_0013b2d8(0.0f);
}

void func_002f3cd8(f32*);

extern u8* D_00348808;
void func_00141c18(u8*, s32, s32, s32, s32);
s32 func_00141ff0(u8*, u32, u32, u16*, s32);

void func_00144860(f32* d, f32* a, f32* b) asm("_Z13func_00144860Pv");

void func_0014d8d0(u8*);

s32 func_0015b4f8(void*, u32, s32*);
void func_00239c38(void*, s32);
s32 func_0023aa98(void*);
extern u8 D_0034a630[];
struct E344 { u8 d[344]; };
struct S151 { u8 pad[456]; E344 e[7]; s32 arr[7]; u32 key; s32 n; };
void func_00152120(S151* p)
{
    s32 buf[8];
    s32 sum = 0;
    p->n = func_0015b4f8(D_0034a630, p->key, buf);
    for (s32 i = 0; i < p->n; i++) {
        func_00239c38(&p->e[i], buf[i]);
        sum += func_0023aa98(&p->e[i]);
        p->arr[i] = sum;
    }
}
}

}
namespace w70_q {
extern "C" {
typedef void (*Fn52)(u8*, s32, u32);
u8* func_00124748(u8*, s32);  // list_nth_node_rel
void func_001241b8(u8* p, s32 base, u32 c)
{
    u8* o = func_00124748(p, 0);  // list_nth_node_rel
    (*(Fn52*)(*(u8**)o + 52))(o, base, c);
    for (s32 i = 1; i < *(s32*)(p + 16); i++) {
        o = func_00124748(p, i);  // list_nth_node_rel
        (*(Fn52*)(*(u8**)o + 52))(o, base + ((s32*)(p + 28))[i], c);
    }
}
void func_00138988(u8*);
void func_00138de0(u8*);
extern s32 D_0034805c;
void func_0023a9c0(u8*, s32*, s32*);
s32 func_0023aa18(u8*);
s32 func_0023aa38(u8*);
void func_0023ade0(u8*);
union FI { f32 f; s32 i; s16 h; };
void func_002f3cd8(FI*);
void func_0013ea50(u8* p, u32, FI* v, s32* ox, s32* oy)
{
    func_002f3cd8(v);
    *ox = (s32)(v[0].f * 16.0f);
    *oy = (s32)(v[1].f * 16.0f);
    *ox = ((FI*)(p + 8))->h * 16 + *ox + 28672;
    *oy = ((FI*)(p + 10))->h * 16 + *oy + 29440;
}
static inline f32 Mn(f32 a, f32 b) { return a < b ? a : b; }
static inline f32 Mx(f32 a, f32 b) { return b < a ? a : b; }
}

}
namespace w70_r {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
typedef u8* (*AllocFn)(u8*, s32, void*);
extern u8* D_0032b91c;
void func_00168958(u8*, s32, u32);  // obj_init_name_string

extern u8 D_0032bae0;
u8* func_0016c028(u8*);  // obj_get_attach_or_alt
void func_001cc3b8(u8*, u8);

extern u8* D_0034dca0;
s32 func_002ff1a4(u8*, u32);  // strcmp
static inline u8* NextA(u8* n) { if (!n) return D_0034dca0; return *(u8**)(n + 60); }
u8* ctarget_00170240(u32, u32, u32, u32) asm("_Z16ctarget_00170240jjjj");
u8* ctarget_00170240(u32 name, u32 id, u32, u32)
{
    u8* n = 0;
    while ((n = NextA(n))) {
        if (func_002ff1a4(n + 4, name)) continue;
        if ((s32)id == -1 || id == *(u32*)(n + 40)) return n;
    }
    return 0;
}

struct E12 { u32 a; u32 flags; u32 c; };
extern E12 D_01c60588[];
extern s32 D_0034ed00;
void func_00182c60(void);
void func_00102c18(s32, s32, void (*)(void));
void func_00182940(E12*);

V4* func_0016c028v(u8*) asm("func_0016c028");
void func_0018b008(u8*, V4*, u32, V4*);

extern u8 D_003502d8[];
extern u8 D_0032bae0a[] asm("D_0032bae0");
void func_001980d0(u8*, u32, s32, u32);
u32 func_0016ac38(u8*, s32, s32, s32, s32);
s32 func_0016a020(u8*);
s32 func_00196388(u8, u8);
void func_001963c8(s32);
void func_00195ed8(u8* p, u32 a, u32 b)
{
    func_001980d0(p, a, 7, b);
    *(u32*)(p + 2552) = 0;
    *(void**)p = D_003502d8;
    p[2557] = 1;
    *(u32*)(p + 1416) |= 0x1000;
    p[2556] = 0;
    *(u32*)(p + 2548) = func_0016ac38(p, 1, 1, 0, 0);
    if (func_0016a020(p) == 569) {
        s32 r = func_00196388(D_0032bae0a[0], D_0032bae0a[1]);
        if (r >= 0) func_001963c8(r);
    }
}

f32 func_0017ce10(f32);
u8* func_0016f000(u32, u32, f32);
s32 func_001997c0(u8*);
void func_001956d0(u8*, u16);
extern u8 D_0034f250[];
typedef void (*Fn56)(u8*, u32, u8*);
u8* func_00199890(u8* p, u32 a, u32 b)
{
    f32 r = func_0017ce10(3.14159274f - *(f32*)(p + 20));
    u8* o = func_0016f000(*(u32*)p, b, r);
    if (o) {
        (*(Fn56*)(*(u8**)o + 56))(o, a, p);
        if (func_001997c0(p)) func_001956d0(D_0034f250, *(u16*)(p + 30));
    }
    return o;
}

void func_0019cbe8(u8*);
u32* func_00177860(u8*);
s32 func_0019ba60(u8*);
u32 func_00154b40(u32, u32);

struct S20 { u32 w[5]; };
struct Job { u32 b; S20 s; };
extern Job D_01c6cb78;
u32 func_001b8680(u32, u32);
u8* func_00102c48(s32, s32, u32, s32);
void func_001a6dd8(u32* p, u32 b, S20* src, u32 d, u32 e)
{
    if (!p[1]) p[1] = func_001b8680(p[0], e);
    D_01c6cb78.b = b;
    D_01c6cb78.s = *src;
    *(u32**)(func_00102c48(1, 15000, d, 4096) + 4) = p;
}
}

}
namespace w70_s2 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
typedef u8* (*AllocFn)(u8*, s32, void*);
extern u8* D_0032b91c;
void func_00168958(u8*, s32, u32);  // obj_init_name_string
void func_00168410(u32 a, u32 b, u32 c, u16 d, u32 e, u32 f)
{
    u8* al = D_0032b91c;
    u8* o = (**(AllocFn**)al)(al, 76, __builtin_return_address(0));
    func_00168958(o, 0, a);  // obj_init_name_string
    *(u32*)(o + 52) = b;
    *(u32*)(o + 56) = e;
    *(u32*)(o + 60) = f;
    *(u32*)(o + 68) = c;
    *(u16*)(o + 74) = d;
}
struct E12 { u32 a; u32 flags; u32 c; };
extern E12 D_01c60588[];
extern s32 D_0034ed00;
void func_00182c60(void);
void func_00102c18(s32, s32, void (*)(void));
void func_00182940(E12*);
void func_00182b18(void)
{
    func_00102c18(1, 12000, func_00182c60);
    for (s32 i = 0; i < D_0034ed00; i++) {
        u32 off = i * 12;
        if (!(*(u32*)(off + (u8*)&D_01c60588[0].flags) & 2)) func_00182940((E12*)(off + (u8*)D_01c60588));
    }
}
struct B32 { f32 a, y, c; u32 d; V4 pos; };
void func_0019cbe8(u8*);
u32* func_00177860(u8*);
s32 func_0019ba60(u8*);
u32 func_00154b40(u32, u32);
}

}
namespace w70_u {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
extern u8 D_0036da70[];
s32 func_001883d8(u8*, u8*);
void func_001880b0(u8*, u8*);
struct Tmp48 { u8 d[16]; };
void func_0016c2b0(Tmp48*, u8*);
void func_001b4198(u8*, u32, Tmp48*);
void func_0016be00(u8*, u16);
void func_00187850(u8*);
void func_001b40e0(u8* p)
{
    u8* q = p + 768;
    if (func_001883d8(q, D_0036da70)) func_001880b0(q, D_0036da70);
    u8* t = *(u8**)(p + 1164);
    if (t && *(u8**)(t + 612)) {
        Tmp48 tmp;
        func_0016c2b0(&tmp, p);
        func_001b4198(*(u8**)(*(u8**)(p + 1164) + 612), *(u32*)(p + 2788), &tmp);
        u16 v = *(u16*)(*(u8**)(*(u8**)(p + 1164) + 612) + 88);
        if (v) func_0016be00(p, v);
    }
    func_00187850(p);
}

extern u8* D_01d48da0;
static inline u8* NextB(u8* n) { if (!n) return D_01d48da0; return *(u8**)(n + 2228); }
typedef s32 (*Fn60)(u8*);
void func_001b9f80(s32 lv)
{
    u8* n = 0;
    while ((n = NextB(n))) {
        if (*(u32*)(n + 1416) & 0x20) continue;
        if ((*(Fn60*)(*(u8**)n + 60))(n) < lv) *(u32*)(n + 268) &= ~0x80;
    }
}

extern u8* D_01d5ba20;
extern f32 D_00349e10;
static inline u8* NextC(u8* n) { if (!n) return D_01d5ba20; return *(u8**)(n + 48); }
void func_001d38a0(u8*, V4*, u32);
V4* func_001d3ac0(V4* out, u32 b)
{
    V4 acc;
    acc.w = acc.z = acc.y = acc.x = 0.0f;
    u8* n = 0;
    while ((n = NextC(n))) func_001d38a0(n, &acc, b);
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(out), "r"(&acc), "f"(D_00349e10) : "$8", "memory");
    return out;
}

struct E8 { u16 id; u8 v[3]; u8 pad; u16 res; };
extern E8 D_0036e568[4];
s32 func_00181500(u16);
u32 ctarget_001d52c0(u32, u32, u32, u32) asm("_Z16ctarget_001d52c0jjjj");
u32 ctarget_001d52c0(u32 a, u32 b, u32, u32)
{
    if (a != 16) return 0;
    for (u32 i = 0; i < 4; i++) {
        if (func_00181500(D_0036e568[i].id))
            for (s32 j = 0; j < 3; j++)
                if (D_0036e568[i].v[j] == b) return D_0036e568[i].res;
    }
    return 0;
}

u8* func_00168b38(u32, s32, u8);  // entry_array_find_nth
void func_001d5370(u32*, u32, s32);
union UH { u32 w; u16 h; };

typedef void (*VF0)(u8*, u8);
typedef void (*VF5)(u8*, u32, u32, u32);
void func_001d5370b(u8*, u32, s32) asm("func_001d5370");
void func_001d16e8(u8*, u8, s32);
void u_tail4_001d8190(u32, u32, u32, u32) asm("_Z16u_tail4_001d8190jjjj");

extern u32 D_003638d0;
u64 func_00312db8(u64, u64);

extern u8* D_0035dcf0;
s32 func_002ff1a4(u8*, u32);  // strcmp
}

}
namespace w70_w {
extern "C" {
typedef void (*VF0)(u8*, u8);
typedef void (*VF5)(u8*, u32, u32, u32);
void func_001d5370b(u8*, u32, s32) asm("func_001d5370");
void func_001d16e8(u8*, u8, s32);
struct Ow { u8 pad[72]; u32 k; u8 pad2[600]; u8* arr[9]; s32 n; };
void u_tail4_001d8190(u32, u32, u32, u32) asm("_Z16u_tail4_001d8190jjjj");
void u_tail4_001d8190(u32 a, u32 b, u32 c, u32)
{
    Ow* p = (Ow*)a; u8* d = (u8*)b; u8* o = (u8*)c;
    (**(VF0**)o)(o, d[19]);
    (*(VF5*)(*(u8**)o + 20))(o, *(u32*)(d + 4), *(u32*)(d + 8), *(u32*)(d + 12));
    if (p->k) {
        u16 k = *(u16*)(d + 16);
        if (k) {
            func_001d5370b(o + 4, p->k, k - 1);
            func_001d16e8(o, d[18], p->n + 3);
        }
    }
    p->arr[p->n++] = o;
}
extern u8* D_0035dcf0;
s32 func_002ff1a4(u8*, u32);  // strcmp
struct E84 { s32 id; u32 used; u8 pad[40]; u8 name[36]; };
extern E84* D_0035dcf0b asm("D_0035dcf0");
E84* func_00227a60(u32 name, s32 id)
{
    for (s32 i = 0; i < 128; i++) {
        if (D_0035dcf0b[i].used && D_0035dcf0b[i].id == id && !func_002ff1a4(D_0035dcf0b[i].name, name)) return &D_0035dcf0b[i];
    }
    return 0;
}
}

}
namespace w70_x {
extern "C" {
void func_001991a8(s32, s32);
void func_002249f8(s32);
u32 func_002282d8(void);  // limit_15000_or_25000
void func_0022c840(void);
u8* func_00102c18(s32, u32, void (*)(void));
void func_0022c8f8(s32 a)
{
    switch (a) {
    case 101: func_001991a8(135, 0); break;
    case 100: func_002249f8(135); break;
    case 200: {
        u8* o = func_00102c18(1, func_002282d8(), func_0022c840);
        *(f32*)(o + 4) = 64.0f;
        *(f32*)(o + 8) = -6850.0f;
        break;
    }
    }
}

struct E40 { u32 a; u32 b; u8* o; u8 pad[28]; };
extern E40* volatile D_0035dcfc;
void func_001ba028(u8*);  // list_contains_ptr
void func_00232db0(u32);
typedef void (*VFn)(u8*);

extern u8* D_0035ed70;
extern s8 D_0035ed9c;
extern u8* D_0035ed8c;
s32 func_002891e8(u8*);
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void func_00138c10(u8*, s32);
void func_00243230(s32, s32);
void func_0024b0e8(void)
{
    s32 i = func_002891e8(D_0035ed70);
    if (!((D_0035ed9c >> i) & 1)) return;
    if (u_call4_00139d78(D_0035ed8c + i * 408)) {
        u8* o = D_0035ed8c + i * 408;
        if (*(s32*)(o + 388) != 37) func_00138c10(o, 37);
    }
    func_00243230(2, i);
}

extern u8* D_0035ee34;
extern u8* D_0035ee38;
s32 func_002892f8(u8*);
s32 func_0028acc8(u8*);
void func_00288e88(u8*);
void func_00250698(void)
{
    if (D_0035ee34) {
        s32 a = func_002892f8(D_0035ee34);
        if (!func_0028acc8(D_0035ee34) && a) func_00288e88(D_0035ee34);
    }
    if (D_0035ee38) {
        s32 a = func_002892f8(D_0035ee38);
        if (!func_0028acc8(D_0035ee38) && a) func_00288e88(D_0035ee38);
    }
}

extern u8* D_0035f01c;
extern u8* D_0035f024;
u32 func_0028b1b8(u8*);
void func_0028b1b0(u8*, u32);
s32 func_0028b1c0(u8*, s32);  // test_bit_field32
void func_002891f0(u8*, s32, s32, s32, s32);
void func_00287cc0(s32);
void func_0026cb38(void);
void func_0026c760(void)
{
    s32 j = 1;
    s32 i = func_002891e8(D_0035f01c);
    j = (j << i) | func_0028b1b8(D_0035f01c);
    func_0028b1b0(D_0035f024, j);
    j = i + 1;
    if (!(j < func_002892f8(D_0035f024)) || func_0028b1c0(D_0035f024, j)) j = i - 1;
    func_002891f0(D_0035f024, j, 0, -1, -1);
    func_00287cc0(0);
    func_0026cb38();
}

// Tz::Jiminy::Init
extern u8* D_0035f010;
s32 func_00257070(s32);
s32 func_00281100(u8*);
void func_00257050(s32, s32, s32);
u32 func_00281140(u8*, s32);
void func_0028fb68(s32, u32);
s32 Jiminy_Init(u8, u8) asm("_ZN2Tz6Jiminy4InitEv");
s32 Jiminy_Init(u8 fwd, u8 apply)
{
    s32 cur = func_00257070(25);
    s32 n = func_00281100(D_0035f010);
    if (fwd) {
        cur++;
        if (!(cur < n)) cur = 0;
    } else {
        cur--;
        if (cur < 0) cur = n - 1;
    }
    if (apply) {
        func_00257050(25, cur, 0);
        func_0028fb68(1, func_00281140(D_0035f010, cur));
    }
    return cur;
}

u32 func_0013a1d8(void);
u32* func_001063f0(s32, u32);
void func_00239700(u8*);
}

}
namespace w70_y {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
union GP { s16* p; s16 h; };
extern GP D_0035f4e8;
extern GP D_0035f4ec;
u32 func_00103570(void);
s16* func_001063f0(s32, u32);
void func_002936e8(void);
void func_00293240(void)
{
    D_0035f4e8.p = func_001063f0(48, func_00103570());
    D_0035f4ec.p = func_001063f0(48, func_00103570());
    for (s32 i = 0; i < 8; i++) {
        D_0035f4e8.p[i * 3 + 0] = -1;
        D_0035f4e8.p[i * 3 + 1] = -1;
        D_0035f4e8.p[i * 3 + 2] = -1;
        D_0035f4ec.p[i * 3 + 0] = -1;
        D_0035f4ec.p[i * 3 + 1] = -1;
        D_0035f4ec.p[i * 3 + 2] = -1;
    }
    func_002936e8();
}

u32 func_00287bc0(void);
void func_00276150(u32, s32*, s32*);
s8* func_00276568(void);
s32 func_0029a5f0(s32);
s32 func_0029a780(s32 a)
{
    s32 r = 0;
    u32 o = func_00287bc0();
    if ((u32)(a + 9) < 2) {
        s32 x, y;
        func_00276150(o, &x, &y);
        s32 v = a == -8 ? y : x;
        s32 c = *func_00276568();
        if (v != 2) r = 1;
        else if ((u32)c < 15) r = 1;
    } else {
        r = (u32)func_0029a5f0(a) < 12;
    }
    return r;
}

u8* func_00294000(s32);
extern u32* D_0035f610;
s32 func_002a9e98(s32 id)
{
    s32 r = 0;
    u8* t = func_00294000(3);
    if (id < 0) {
        for (u32 i = 0; (s32)i < *(s32*)(t + 8); i++) {
            r = (D_0035f610[i >> 5] & (1 << (i & 31))) != 0;
            if (r) break;
        }
    } else {
        r = (D_0035f610[(u32)id >> 5] & (1 << (id & 31))) != 0;
    }
    return r;
}

struct D8 { u32 a, b; };
extern D8 D_01e2a5e8;
extern D8 D_01e2a5f0;
struct T32 { u8 pad[1024]; s32 v[32]; s32 n; };
extern T32 D_01e2a5f8;
void wtarget_002bafb0(u32, u32, u32, u32) asm("_Z16wtarget_002bafb0jjjj");
void wtarget_002bafb0(u32 a, u32 b, u32, u32)
{
    if (b == 0xffff && a == 1) { D_01e2a5e8.a = 0; D_01e2a5e8.b = 0; }
    if (b == 0xffff && a == 1) { D_01e2a5f0.a = 0; D_01e2a5f0.b = 0; }
    if (b == 0xffff && a == 1) {
        T32* t = &D_01e2a5f8;
        s32 i = 0;
        bool c;
        s32* w = t->v;
        do {
            *w = i;
            i++;
            c = i < 32;
            // R5900 short-loop padding
            asm volatile("nop\n\tnop");
            w++;
        } while (c);
        t->n = 32;
    }
}

s32 func_00197920(u8*);
void func_002e2728(u8*, s32, u8);
void func_002e24e0(u8*);
extern V4 D_00362e70;
extern u8* D_0034e948;
void func_0016ace0(u8*, V4*);
void wtarget_002e2440(u32, u32, u32, u32) asm("_Z16wtarget_002e2440jjjj");
void wtarget_002e2440(u32 a, u32, u32, u32)
{
    u8* p = (u8*)a;
    if (func_00197920(p)) return;
    s32 k = *(s32*)(p + 276);
    if (k >= 0) {
        func_002e2728(p, k, p[280]);
        *(s32*)(p + 276) = -1;
    }
    asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(p + 240) : "memory");
    func_002e24e0(p);
    if (p[268]) {
        V4 t;
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&t), "r"(p + 224) : "$8", "memory");
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&t), "r"(&t), "r"(&D_00362e70) : "memory");
        func_0016ace0(D_0034e948, &t);
        p[268] = 0;
    }
}

u8* func_001b9bc8(u8*);
s32 func_0019c6f0(u32);
void func_0016c568(u8*, u32, f32);
void func_002e8400(u8* p)
{
    u8* a = *(u8**)(*(u8**)p + 4);
    u8* b = *(u8**)(*(u8**)(p + 12) + 4);
    u8* n = 0;
    while ((n = func_001b9bc8(n))) {
        if (n == a || n == b) continue;
        if ((*(u32*)(n + 1416) & 0x40) && !func_0019c6f0(*(u32*)(n + 2548))) continue;
        func_0016c568(n, *(u32*)(p + 4), *(f32*)(p + 8));
    }
}

s32* func_00316e10(void);  // get_data_369928
s32 func_0030edb0(void);
void func_0030ee00(void);  // ee_intr_get_enable
s32 func_00316c68(s32* out, s32 flag)
{
    s32* t = func_00316e10();  // get_data_369928
    s32 st = func_0030edb0();
    for (s32 i = 0; i < 8; i++, t++) {
        if (!*t && flag) {
            *t = 1;
            if (st) func_0030ee00();  // ee_intr_get_enable
            *out = i;
            return 0;
        }
    }
    if (st) func_0030ee00();  // ee_intr_get_enable
    return -1;
}
}

}
namespace w70_z {
extern "C" {
s32 func_00224910(u8*);  // get_global_36dac4
void func_00239f18(u8*, f32);  // obj_set_float312_and_flags
static inline f32 Clamp(f32 v, f32 lo, f32 hi) { return v < lo ? lo : (hi < v ? hi : v); }
f32 func_0028f1e0(f32* a, f32* b, f32 x)
{
    f32 dx = b[0] - a[0];
    f32 t = (x - a[0]) / dx;
    f32 t2 = t * t;
    f32 t3 = t2 * t;
    f32 h00 = t3 + t3 - t2 * 3.0f + 1.0f;
    f32 h01 = t3 * -2.0f + t2 * 3.0f;
    f32 h10 = t3 - (t2 + t2) + t;
    f32 h11 = t3 - t2;
    return h00 * a[1] + h01 * b[1] + (h10 * a[3] + h11 * b[2]) * dx;
}
}
extern "C" {
}

}
namespace w70_a2 {
extern "C" {
typedef void (*VFn)(void*);
extern u8 D_00350bb0[];
extern u8 D_0034e8a8[];
void func_00239870(u8*);
void func_00239848(u8*);  // set_vtbl_36eb28_then_call
void func_001ac5b8(u8*);
void func_00105110(u8*);
// same shape as 0031f820
void func_0031fa18(u8* p)
{
    *(void**)p = D_00350bb0;
    if (p != (u8*)-1544) {
        u8* q = p + 2920;
        u8* a = p + 1544;
    loop:
        if (a == q) goto done;
        q -= 344;
        (**(VFn**)q)(q);
        goto loop;
    }
done:
    func_00239870(p + 1200);
    func_00239870(p + 848);
    func_00239870(p + 484);
    *(void**)(p + 132) = D_0034e8a8;
    func_00239848(p + 132);  // set_vtbl_36eb28_then_call
    func_001ac5b8(p);
    func_00105110(p);
}
f32 func_001142a0(u32);
f32 func_0010f660(void);  // cvt_20001_scaled
void func_001111c8(u8* p)
{
    *(u32*)(p + 2940) &= ~0x20;
    if (*(u8**)(p + 1164)) {
        f32 a = func_001142a0(*(u32*)(p + 2912));
        u8* q = *(u8**)(p + 1164);
        a *= (f32)*(s32*)(q + 384) / (f32)*(s32*)(q + 388) * 0.75f + 0.25f;
        if (func_0010f660() <= a) *(u32*)(p + 2940) |= 0x20;
    }
}
}

}
namespace w71_b1 {
extern "C" {
void func_001025f8(u8*, u8*);
void wtarget_00102688(u32, u32, u32, u32) asm("_Z16wtarget_00102688jjjj");
typedef void (*Fn60)(u8*, s32, u32);
u8* func_00124748(u8*, s32);  // list_nth_node_rel
void func_00124278(u8* p, s32 base, u32 c)
{
    u8* o = func_00124748(p, 0);  // list_nth_node_rel
    (*(Fn60*)(*(u8**)o + 60))(o, base, c);
    for (s32 i = 1; i < *(s32*)(p + 16); i++) {
        o = func_00124748(p, i);  // list_nth_node_rel
        (*(Fn60*)(*(u8**)o + 60))(o, base + ((s32*)(p + 28))[i], c);
    }
}
f32* func_001333c8(u8*);
f32 func_002f8870(f32);  // fabsf
void func_0013fda0(u8*);
void func_0013fdc8(u8*);
void func_001400b0(u8* p, f32 x)
{
    if (func_002f8870(*(f32*)(p + 72) - *(f32*)(p + 204)) >= 1.0f) {  // fabsf
        if (*(f32*)(p + 204) < *(f32*)(p + 72)) {
            *(f32*)(p + 72) = *(f32*)(p + 72) - x;
            func_0013fda0(p);
        } else {
            *(f32*)(p + 72) = *(f32*)(p + 72) + x;
            func_0013fdc8(p);
        }
    }
}
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct Seg { V4 a, b; };
void func_00144490(Seg*, f32, f32, f32, f32, f32, f32);
void func_00144e30(Seg*);  // zero_6_halfwords
u32 func_00141970(u8*);  // vtable_get12
void func_00144e50(Seg*, Seg*, u32);
void func_00141c18(u8*, s32, s32, s32, s32);
void func_00141c38(u8*, s32, Seg*, u16*, s32);
static inline u8* NextK(u8* n, u8* c) { if (!c) return *(u8**)(n + 240); return *(u8**)(c + 236); }
struct S10 { u8 a, b, c; u16 d, e, f; };
void func_001991a8(s32, s32);
u8* func_001058e8(void);
u8 func_00149fa8(s32);
void func_00104f58(S10*, u32, s32, s32, s32);
void func_00239f18(u8*, f32);  // obj_set_float312_and_flags
void func_00138c68(u8*, s32, s32);
void func_00155ab0(u8* p, s32 v, s32 i)
{
    f32 f = (f32)v;
    func_00239f18(p + i * 412 + 6728, f / 100.0f);  // obj_set_float312_and_flags
    if (i == 9) func_00138c68(p + 11236, (s32)-f, 0);
}
}

}
namespace w71_b3 {
extern "C" {
void func_001025f8(u8*, u8*);
void wtarget_00102688(u32, u32, u32, u32) asm("_Z16wtarget_00102688jjjj");
f32* func_001333c8(u8*);
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct Seg { V4 a, b; };
void func_00144490(Seg*, f32, f32, f32, f32, f32, f32);
void func_00144e30(V4*);  // zero_6_halfwords
u32 func_00141970(u8*);  // vtable_get12
void func_00144e50(V4*, Seg*, u32);
void func_00141c18(u8*, s32, s32, s32, s32);
void func_00141c38(u8*, s32, V4*, u16*, s32);
u16 func_00142848(u8* o, u8* p)
{
    Seg a;
    V4 b;
    func_00144490(&a, *(f32*)(p + 48), *(f32*)(p + 52) - *(f32*)(p + 108), *(f32*)(p + 56), *(f32*)(p + 48), *(f32*)(p + 52) + 320000.0f, *(f32*)(p + 56));
    func_00144e30(&b);  // zero_6_halfwords
    func_00144e50(&b, &a, func_00141970(o));
    u16 r = 0;
    func_00141c18(o, 0, 0, 0, 0);
    func_00141c38(o, 0, &b, &r, 15);
    return r;
}
void func_00144b38(f32* b, f32* v)
{
    f32 x0 = b[0], y0 = b[1], z0 = b[2], x1 = b[3], y1 = b[4], z1 = b[5];
    v[0] = x0; v[1] = y0; v[2] = z0; v[3] = 1.0f;
    v[4] = x0; v[5] = y1; v[6] = z0; v[7] = 1.0f;
    v[8] = x1; v[9] = y1; v[10] = z0; v[11] = 1.0f;
    v[12] = x1; v[13] = y0; v[14] = z0; v[15] = 1.0f;
    v[16] = x0; v[17] = y0; v[18] = z1; v[19] = 1.0f;
    v[20] = x0; v[21] = y1; v[22] = z1; v[23] = 1.0f;
    v[24] = x1; v[25] = y1; v[26] = z1; v[27] = 1.0f;
    v[28] = x1; v[29] = y0; v[30] = z1; v[31] = 1.0f;
}
static inline u8* NextK(u8* n, u8* c) { if (!c) return *(u8**)(n + 240); return *(u8**)(c + 236); }
void func_00148e40(u32 ctx, u8* n, u8** out, s32* cnt)
{
    u32 f = *(u32*)(n + 248);
    u32 a = f & 8;
    if (a || (f & 0x40)) out[(*cnt)++] = n;
    u8* c = 0;
    while ((c = NextK(n, c))) func_00148e40(ctx, c, out, cnt);
}
struct S10 { u8 a, b, c; u16 d, e, f; };
void func_001991a8(s32, s32);
u8* func_001058e8(void);
u8 func_00149fa8(s32);
void func_00104f58(S10*, u32, s32, s32, s32);
void func_00149fe0(s32 a, u32 b)
{
    func_001991a8(33, 0);
    S10 s;
    u16 m = 0xffff;
    s.a = m;
    s.b = m;
    s.c = m;
    s.d = m;
    s.e = m;
    s.f = m;
    if (a < 0) a = func_001058e8()[12];
    func_001058e8()[12] = 15; s.a = 15;
    func_001058e8()[13] = 0; s.b = 0;
    u8* g = func_001058e8();
    u8 r = func_00149fa8(a);
    g[14] = r;
    s.c = r;
    func_00104f58(&s, b | 1, 0, 0, 0);
}
}

}
namespace w71_b4 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
struct B32 { f32 a, y, c; u32 d; V4 pos; };
u8* func_001b9bc8(u8*);
u32 func_0016bba8(u8*, s32, u32);
void func_0018a818(B32*, u8*, u32);
extern u8* D_0034dca0;
extern u32 D_0034dcb0;
void func_001700e8(u8*, s32);
void func_0016fc10(u8*);
void func_001707d8(void)
{
    u32 lim = D_0034dcb0;
    u8* n = D_0034dca0;
    while (n) {
        u8* nx = *(u8**)(n + 60);
        if (*(s32*)(n + 40) >= 0 && lim < *(u32*)(n + 48) + *(u32*)(n + 44)) func_001700e8(n, 0);
        else func_0016fc10(n);
        n = nx;
    }
    n = D_0034dca0;
    while (n) {
        u8* nx = *(u8**)(n + 60);
        if (*(u32*)(n + 36) & 2) func_001700e8(n, 0);
        n = nx;
    }
}
s32 func_002ff1a4(u8*, u32);  // strcmp
static inline u8* NextA(u8* n) { if (!n) return D_0034dca0; return *(u8**)(n + 60); }
u8* func_0018bc60(u8*, s32);
u32 func_0018bae8(u8*, u8*);
// YS::STDOBJ::hook_command_image
extern s8 D_0036d0c8[4];
u8* func_00168b88(u32, s32, u32, s32);  // find_entry16_by_half_word
void func_0013d6b0(u32, u32);
static inline u32 Key4(s8* k) { return k[0] | k[3] << 24 | (k[2] << 16 | k[1] << 8); }
void STDOBJ_hook_command_image(u8*) asm("_ZN2YS6STDOBJ18hook_command_imageEv");
typedef s32 (*Fn8)(u8*, u32);
static inline u8* NextR(u8* p, u8* n) { if (!n) return *(u8**)(p + 12); return *(u8**)(n + 96); }
struct E56 { u32 a; u32 b; u8 pad[4]; u32 c; u32 d; u8 pad2[36]; };
extern E56 D_01c62198[64];
void func_00199cd0(E56*);
void wtarget_0019b970(u32, u32, u32, u32) asm("_Z16wtarget_0019b970jjjj");
void func_0019e210(u8**, u32);
void func_0019e170(u8** p)
{
    u8* o = *(u8**)(**(u8***)p + 2528);
    if (*(u32*)(o + 1416) & 0x20000000) {
        u32* s = *(u32**)(o + 2880);
        if (s[0] == 2) { func_0019e210(p, s[1]); return; }
    }
    u8* n = 0;
    while ((n = func_001b9bc8(n))) func_0019e210(p, (u32)n);
}
extern u8 D_00350ab0[];
void func_001ac970(u8*, s32, s32, u32, s32, s32, s32, s32);
void func_001ac258(u8*);
void func_00239700(u8*);
void func_001a9970(u8*, s32);
void func_001ad280(u8* p, u32 a)
{
    func_001ac970(p, 0, 6, a, 0, 256, 52, 4);
    *(void**)p = D_00350ab0;
    func_001ac258(p + 2924);
    u8* q = p + 3280;
    for (s32 k = 3; k != -1; k--) { func_00239700(q); q += 344; }
    func_001a9970(p + 12, 16);
    *(u32*)(p + 104) = 0;
    *(u32*)(p + 8) += *(u32*)(p + 96) >> 1;
}
}

}
namespace w71_b6 {
extern "C" {
void func_001d02c8(u32);
u8* func_00176b58(u32);
s32 func_0019ba60(u8*);
u8* func_00177860(u8*);
s32 func_001a2a50(u32, u32, u32, s32);
void func_001d97c8(void);
void func_001ba598(u32* p)
{
    if (!p[1]) return;
    if (p[3] == 4) { func_001d02c8(p[2]); p[1] = 0; return; }
    s32 pri = 100;
    u8* o = func_00176b58(p[3]);
    if (func_0019ba60(o)) pri = *(u16*)(func_00177860(o) + 80) + 100;
    if (func_001a2a50(p[1], p[4], p[3], pri) && p[3] == 1) func_001d97c8();
    p[1] = 0;
}
u32 func_001050c8(void);
void func_001db710(u32*, u32, u32, u32);
u32 func_001050d8(s32);
struct E4 { u8 used; u8 cnt; u16 id; };
void func_001d4f40(u8*, u16, u8);
void func_0019d188(u8*);
void func_001bd6a8(u8*);
void func_001d6ab0(u8*);
typedef s32 (*Fn64)(u8*);
void func_001d6ba0(u8* p)
{
    if (!*(u8**)(p + 2804)) return;
    struct BF { u32 on : 1; };
    if ((u8)((BF*)(p + 2800))->on) func_0019d188(p + 2752);
    func_001bd6a8(p);
    u8 c = p[2808];
    if (!c) return;
    if (c < 2) {
        u8* o = *(u8**)(p + 2804);
        if (!(*(Fn64*)(*(u8**)o + 64))(o)) return;
    }
    if (--p[2808] == 0) func_001d6ab0(p);
}
extern u8 D_01dad990[];
s32 func_002282f0(s16);
s32 func_00225b00(s16);  // flag_query_by_index
void func_002f1460(u8*, s32, f32, f32, f32, f32);
void func_0022cf18(void);
void func_00102c18(s32, s32, void (*)(void));
void func_0022cf60(s16* p)
{
    if (func_002282f0(p[2])) return;
    if (func_00225b00(p[2])) return;
    f32 h = (f32)p[6];
    func_002f1460(D_01dad990, p[7], (f32)p[3], (f32)p[4], (f32)p[5], h + h);
    func_00102c18(1, 29999, func_0022cf18);
}
struct R32 { u32 a; u32 id; u8 pad[24]; };
extern R32 D_01dadc00[64];
extern s32 D_0035e364;
extern s32 D_0035e360;
extern u32 D_0035e370;
extern u32 D_0035e36c;
}

}
namespace w71_b7 {
extern "C" {
void func_0023f168(u8*);
void func_0023ca80(u8*);
s32 func_0023c900(u8*);
void func_0023f108(u8*);
typedef void (*VFn)(u8*);
void func_0023efb8(u8* p)
{
    func_0023f168(p);
    u8* q = p + 48;
    func_0023ca80(q);
    if (p[148]) p[148] = 0;
    if (func_0023c900(q)) return;
    if (*(s32*)(p + 144) != -1) {
        func_0023f108(p);
        func_0023f168(p);
        func_0023ca80(q);
        p[148] = 1;
    } else {
        (*(VFn*)(*(u8**)p + 20))(p);
    }
}
extern u8* D_0035eda8;
extern s8 D_0035edc5;
extern u8* D_0035edbc;
s32 func_002891e8(u8*);
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void func_00138c10(u8*, s32);
void func_00243230(s32, s32);
void func_0024c898(void)
{
    s32 i = func_002891e8(D_0035eda8);
    if (!((D_0035edc5 >> i) & 1)) return;
    if (u_call4_00139d78(D_0035edbc + i * 408)) {
        u8* o = D_0035edbc + i * 408;
        if (*(s32*)(o + 388) != 37) func_00138c10(o, 37);
    }
    func_00243230(7, i);
}
u8* func_001058e8(void);
extern u8* D_0035ee70;
void func_00252660(s32 i)
{
    u32* bits = (u32*)(func_001058e8() + 18904);
    u32 k = i + 8;
    u32 m = 1 << (k & 31);
    u32 w = bits[k >> 5];
    if (!(w & m)) bits[k >> 5] = w | m;
    if (u_call4_00139d78(D_0035ee70 + i * 432)) {
        u8* o = D_0035ee70 + i * 432;
        if (*(s32*)(o + 388) != 24) func_00138c10(o, 24);
    }
}
extern u8* D_0035f264;
extern u32 D_0035f250;
void func_002806a0(void);
u32 func_0023f1b0(u32);
u32 func_0023c4b8(u32, s32);
u32 func_00236ca8(u8*, s32);
void func_001386e0(u8*, s32, u32, u32, s32, s32);
void func_002805d0(void)
{
    func_002806a0();
    u8* s0 = D_0035f264;
    u8* s1 = s0 + 896;
    s0 += 920;
    u32 x = func_0023c4b8(func_0023f1b0(D_0035f250), 0);
    u32 y = func_00236ca8(D_0035f264, 0);
    func_001386e0(s1, 30047, x, y, 1, 0);
    *(s32*)(s1 + 392) = 2;
    s1[405] = 1;
    *(u32*)(s0 + 184) |= 8;
}
// Tz::CmItem::FadeOutHelp
extern u8 D_0035f299;
extern u32 D_0035f274;
extern u8* D_0035f28c;
extern u8* D_0035f290;
extern s16 D_0035f2a2;
extern s16 D_0035f2aa;
extern s16 D_0035f280;
void func_0028dac8(u8*, s32);
s32 func_00281c30(void);
void CmItem_FadeOutHelp(void) asm("_ZN2Tz6CmItem11FadeOutHelpEv");
void CmItem_FadeOutHelp(void)
{
    if (D_0035f299 && !D_0035f274 && u_call4_00139d78(D_0035f28c) && *(s32*)(D_0035f28c + 388) != D_0035f2a2) {
        func_0028dac8(D_0035f28c, D_0035f2a2);
        D_0035f280 = -1;
    }
    if (func_00281c30() && *(s32*)(D_0035f290 + 388) != D_0035f2aa) {
        func_0028dac8(D_0035f290, D_0035f2aa);
        D_0035f280 = -1;
    }
}
// Tz::Select::Destroy
s32 func_0028acc8(u8*);
void Select_Destroy(u8*) asm("_ZN2Tz6Select7DestroyEz");
// Tz::Selector::CreateHelpGra
void func_00290740(u8*);
void func_002362b0(u8*, u32);
void func_002367c8(u8*);  // obj_dispatch_bitfield64
void Selector_CreateHelpGra(u8*, u32, u32, u32) asm("_ZN2Tz8Selector13CreateHelpGraEz");
extern s8* D_0035f5d4;
void func_002a18d0(void);
s32 func_002a9e98(s32);
s32 func_002a9f50(s32);
u8* func_00294000(s32);
s32 func_002aacd8(s32);  // test_bit_global_d
extern u8* D_0035f610;
}

}
namespace w71_b8 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
u8* func_001d9e30(u8*);  // record_range_check_or_first
s32 func_002764b0(u8);
extern u8* D_0035f610;
s32 func_002b7d5c(u32, u32, s32, u32);
s32 func_002b97d8(u32, u32, s32, u32);
u8 func_002b73ac(u32, u32, u32, s32, u32);
extern u8* D_01e2aa80;
s32 ctarget_002bb468(u32, u32, u32, u32) asm("_Z16ctarget_002bb468jjjj");
void func_002b740c(u32, u32, u32, s32);
void func_002e34c8(u8*);  // obj_get_field8_by_vtable
s32* func_002e34d8(u8*, s32);  // list_walk_stride12
void func_001d14b0(u8*, s32);
u8 func_002cd008(u8*, u32);
extern u32 D_00363560;
extern u8 D_01e2c064;
extern u32 D_003637d0;
extern f32 D_0036354c;
void func_002eda90(u32, s32, f32);
void func_002edaf8(u32, s32, f32);
extern u8* D_00352130;
void func_0017f488(u8*, s32, f32, f32);
void func_0016bd60(u8*, s32);
void func_002f04e0(u32, u8* p)
{
    V4* v = (V4*)(p + 32);
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(v), "r"(v), "f"(*(f32*)(D_00352130 + 60)) : "$8", "memory");
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(v) : "$8", "memory");
    if (len < *(f32*)(p + 244)) {
        asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(v) : "memory");
        func_0017f488(p + 320, 0, 0.0f, 0.0f);
        func_0016bd60(p, 31);
    }
}
extern u8 D_00347d70[];
extern u8 D_00347f98[];
void func_0031a508(u8*);
void func_0031a3d8(u8*);
}

}
namespace w71_c1 {
extern "C" {
u32 func_00317138(u32);
u32 func_00317130(u32);
u32 func_00317128(u32);
void func_002fd160(void) __attribute__((noreturn));
// libgcc unwind-pe.h base_of_encoded_value
u32 func_00316e88(u8 enc, u32 ctx)
{
    if (enc == 0xff) return 0;
    switch (enc & 0x70) {
    case 0x00:
    case 0x10:
    case 0x50:
        return 0;
    case 0x20:
        return func_00317138(ctx);
    case 0x30:
        return func_00317130(ctx);
    case 0x40:
        return func_00317128(ctx);
    }
    func_002fd160();
}
extern u8* D_0035f5e4;
s32 func_002a4990(u8*);
s32 func_002a4ad8(s32 a)
{
    if (a < 0) a = *(s32*)(D_0035f5e4 + 4232);
    s32 n = func_002a4990(*(u8**)(D_0035f5e4 + 4228) + a / 8);
    s32 sum = 0;
    if (n > 0) {
        u8* q = D_0035f5e4 + 4097;
        do {
            sum += *q;
            n--;
            // R5900 short-loop padding
            asm volatile("nop\n\tnop");
            q += 8;
        } while (n);
    }
    return a - (sum - *(s32*)(D_0035f5e4 + 4228)) * 8;
}
}

}
namespace w72_d2 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
typedef void (*Fn64)(u8*, s32, u32);
u8* func_00124748(u8*, s32);  // list_nth_node_rel
void func_00124338(u8* p, s32 base, u32 c)
{
    u8* o = func_00124748(p, 0);  // list_nth_node_rel
    (*(Fn64*)(*(u8**)o + 64))(o, base, c);
    for (s32 i = 1; i < *(s32*)(p + 16); i++) {
        o = func_00124748(p, i);  // list_nth_node_rel
        (*(Fn64*)(*(u8**)o + 64))(o, base + ((s32*)(p + 28))[i], c);
    }
}
u32 func_00313bc0(f32);
u32 func_001333f8(u8* p, u32 a, u32 b)
{
    f32 r = (f32)a / (f32)b;
    return (func_00313bc0((f32)*(u32*)(p + 36) * r) >> 16) & 0xfff;
}
void func_00144908(f32* b, V4* out)
{
    V4 d;
    d.w = 1.0f;
    d.x = b[3] - b[0];
    d.y = b[4] - b[1];
    d.z = b[5] - b[2];
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&d), "r"(&d), "f"(0.5f) : "$8", "memory");
    out->x = b[0] + d.x;
    out->y = b[1] + d.y;
    out->z = b[2] + d.z;
    out->w = 1.0f;
}
void func_00148a68(u32, u8*);
void func_00147f08(u32, u8*);
static inline u8* NextK(u8* n, u8* c) { if (!c) return *(u8**)(n + 240); return *(u8**)(c + 236); }
s32 func_001541d8(u8*, u32*, u32);
u32 func_00154288(u8*, u32, u32);  // state_index_0_1_2
void func_001386e0(u8*, u32, u32, u8*, u32, u32);
void func_001391c8(u8*, u32);
void func_00138748(u8*);
void func_00153fa0(u8* p, u32 a, u32 b, u32 c, u32 d, u32 e)
{
    *(u32*)(p + 832) = b;
    u32 v = 0;
    if (func_001541d8(p, &v, c) == 1) {
        func_001386e0(p, a, v, p + 416, func_00154288(p, d, e), e);
    } else {
        func_001391c8(p, a);
        func_00138748(p);
    }
}
extern s8 D_004f3590;
extern f32 D_004f3598;
f32 func_0017ce10(f32);
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void func_0013edd0(u8*, f32);
void func_0014b1e0(u8*, s32, s32);
void func_00155cb0(u8* p, s32 a, s32 b)
{
    f32 x = (f32)a * (23.0f / (f32)b * 0.01745329238474369f);
    x = func_0017ce10(x);
    u_call4_00139d78(p + 12896);
    func_0013edd0(p + 12928, x);
    u_call4_00139d78(p + 12896);
    func_0014b1e0(p + 12928, 50, 100);
}
static inline f32 VNormalize(V4* d, V4* s)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%2)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(d), "r"(s) : "$8", "memory");
    return r;
}
static inline void VCp(V4* d, V4* s) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory"); }
static inline f32 VDot(V4* a, V4* b)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(a), "r"(b) : "$8", "memory");
    return r;
}
struct DotArg { V4* a; V4* b; };
void func_0016da20(DotArg* p)
{
    V4 n1, n2;
    VCp(&n1, p->a);
    VNormalize(&n1, &n1);
    VCp(&n2, p->b);
    VNormalize(&n2, &n2);
    *(f32*)p = VDot(&n1, &n2);
}
u32 func_0016a070(u32);
void func_0017f488(u8*, s32, f32, f32);
void func_0017f5e0(u8*, s32, s32, f32, f32);
}

}
namespace w72_d3 {
extern "C" {
extern u8 D_0032bae0[];
void func_00198450(u8*);
u32 func_0016c008(u8*, s32);
u32 func_001d9dd0(u8, u8, u32);
s32 func_001d9d48(u32);
u32 func_0016ac38(u8*, s32, s32, s32, s32);
typedef void (*VFn)(u8*);
void func_001d9f30(u8* p)
{
    u8* k = D_0032bae0;
    func_00198450(p);
    u32 r = func_001d9dd0(k[0], k[1], func_0016c008(p, 1));
    *(u32*)(p + 2552) = r;
    if (!r || !func_001d9d48(r)) *(u32*)(p + 2548) = func_0016ac38(p, 0, 1, 0, 0);
    else (*(VFn*)(*(u8**)p + 32))(p);
}
extern u8* D_00352ae0;
s32 func_001dc9d0(u8*);
s32 func_001dc738(u8*);  // state_gate_flags
void func_001dda78(void)
{
    u8* n = D_00352ae0;
    if (!n) return;
    do {
        u8* nx = *(u8**)(n + 40);
        if (func_001dc9d0(n)) goto next;
        if ((u8)((*(s32*)(n + 8) >> 26) & 1)) goto next;
        if (!func_001dc738(n)) {  // state_gate_flags
            u32 f = *(u32*)(n + 8);
            if (f & 0x100000) {
                if (n) (*(VFn*)(*(u8**)n + 4))(n);
            } else if ((u8)(f & 1)) {
                *(u32*)(n + 8) = f | 0x100000;
            }
        }
    next:
        n = nx;
    } while (n);
}
typedef void (*Fn32)(u8*, u8*);
extern u8* D_01d9e6e0;
u8* func_001e7a98(u8*, u8*);
union HF { s16 h; f32 f; };
void func_001ea100(u32 x, u8* d, HF* v)
{
    s32 k = *(s32*)(d + 12);
    if (k == -1) return;
    u8* r = 0;
    u8* base = D_01d9e6e0;
    u8* a = *(u8**)(base + 128) + k * 16;
    if (a) { r = func_001e7a98(base, a); *(u32*)(r + 4) = x; }
    f32* q = (f32*)(r + *(s32*)(d + 16) + 160);
    q[0] = ((HF*)((s16*)v + 0))->h;
    q[1] = ((HF*)((s16*)v + 1))->h;
    q[2] = ((HF*)((s16*)v + 2))->h;
}
s32 func_002282f0(s16);
u8* func_00227d10(s16);
void func_001ba028(u8*);  // list_contains_ptr
s32 func_001c0cd8(u8*);
void func_001c0e60(u8*);
void func_00232db0(s16);
void func_00227950(void);
u8* func_00102c18(s32, s32, void (*)(void));
union HP { s16 h[4]; u8* q; };
void func_0022f308(HP* hp)
{
    s16* p = hp->h;
    if (func_002282f0(p[2])) return;
    u8* e = func_00227d10(p[3]);
    func_001ba028(*(u8**)(e + 8));  // list_contains_ptr
    if (func_001c0cd8(*(u8**)(e + 8))) func_001c0e60(*(u8**)(e + 8));
    (*(VFn*)(**(u8***)(e + 8) + 40))(*(u8**)(e + 8));
    *(u8**)(e + 8) = 0;
    func_00232db0(hp->h[3]);
    *(s32*)(func_00102c18(1, 0xa7ee, func_00227950) + 4) = hp->h[3];
}
extern u32 D_0035eb88;
void func_001391c8(u8*, u32, u32);
void func_00236a58(u8*, u32, u32);
void func_0023c100(u8*, u32, u8*, u32);
void func_0023f070(u8*, u32, s32);
void func_0023f168(u8*);
void func_0023eea0(u8* p, u32 a, u32 b, u32 c, u32 d, u32 e)
{
    func_001391c8(p, a, e);
    u8* q = p + 24;
    func_00236a58(q, c, D_0035eb88);
    func_0023c100(p + 48, b, q, D_0035eb88);
    *(s32*)(p + 152) = -10;
    *(s32*)(p + 156) = -10;
    func_0023f070(p, d, -1);
    p[148] = 0;
    func_0023f168(p);
}
extern char D_00371698[];
void func_002ff2e8(char*, const char*);
s32 func_002ff3fc(const char*);  // strlen
void func_00240118(char*, u32, u32);
extern u8* D_0035ee34;
extern s8 D_0035ee51;
extern u8* D_0035ee48;
s32 func_002891e8(u8*);
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void func_00138c10(u8*, s32);
void func_00243230(s32, s32);
void func_00250998(void)
{
    s32 i = func_002891e8(D_0035ee34);
    if (!((D_0035ee51 >> i) & 1)) return;
    if (u_call4_00139d78(D_0035ee48 + i * 408)) {
        u8* o = D_0035ee48 + i * 408;
        if (*(s32*)(o + 388) != 34) func_00138c10(o, 34);
    }
    func_00243230(6, i);
}
struct S36 { u32 w[9]; };
extern u8 D_00352770;
extern u8 D_00350379;
s32 func_001bb4a0(void);
S36 func_00199098(void);
}

}
namespace w72_e1 {
extern "C" {
extern u8 D_00350ab0[];
void func_001ac970(u8*, s32, s32, u32, s32, s32, s32, s32);
void func_001ac258(u8*);
void func_00239700(u8*);
void func_001a9970(u8*, s32);
void func_001ad330(u8* p, u32 a)
{
    func_001ac970(p, 0, 6, a, 0, 256, 52, 4);
    *(void**)p = D_00350ab0;
    func_001ac258(p + 2924);
    u8* q = p + 3280;
    for (s32 k = 3; k != -1; k--) { func_00239700(q); q += 344; }
    func_001a9970(p + 12, 16);
    *(u32*)(p + 104) = 0;
    *(u32*)(p + 8) += *(u32*)(p + 96) >> 1;
}
}

}
namespace w72_e2 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
typedef void (*VFn)(void*);
extern u8 D_00350bb0[];
extern u8 D_0034e8a8[];
void func_00239870(u8*);
void func_00239848(u8*);  // set_vtbl_36eb28_then_call
void func_001ac5b8(u8*);
struct NoTail { ~NoTail() {} };
void func_0031e590(u8* p)
{
    NoTail g;
    *(void**)p = D_00350bb0;
    if (p != (u8*)-1544) {
        u8* q = p + 2920;
        u8* a = p + 1544;
    loop:
        if (a == q) goto done;
        q -= 344;
        (**(VFn**)q)(q);
        goto loop;
    }
done:
    func_00239870(p + 1200);
    func_00239870(p + 848);
    func_00239870(p + 484);
    *(void**)(p + 132) = D_0034e8a8;
    func_00239848(p + 132);  // set_vtbl_36eb28_then_call
    func_001ac5b8(p);
}
s32 func_00168aa0(u32, s32);
u8* func_00168b38(u32, s32, s32);  // entry_array_find_nth
void func_0031ae58(u32* p, u32 a)
{
    p[0] = a;
    s32 n = func_00168aa0(a, 25);
    p[1] = n;
    for (s32 i = 0; i < (s32)p[1]; i++) {
        u32* e = p + i * 2;
        e[3] = *(u32*)(func_00168b38(p[0], 25, i) + 8);  // entry_array_find_nth
        if (func_00168b38(p[0], 24, 0)) e[2] = *(u32*)(func_00168b38(p[0], 24, i) + 8);  // entry_array_find_nth
        else e[2] = 0;
    }
}
u8* func_001b9bc8(u8*);
s32 func_0016a070(u8*);
s32 func_0016c008(u8*, s32);
u8* ctarget_002edbf8(u32, u32, u32, u32) asm("_Z16ctarget_002edbf8jjjj");
u8* ctarget_002edbf8(u32 want, u32, u32, u32)
{
    u8* n = 0;
    while ((n = func_001b9bc8(n))) {
        if (func_0016a070(n) != 4007) continue;
        if (func_0016c008(n, 1) == 1) { if (!want) return n; }
        else { if (want) return n; }
    }
    return 0;
}
extern u8* D_0034e948;
extern u8 D_00362698[];
void func_001c0d38(u8*, u8*, s32, s32);
void func_002cf2b0(u8*, s32);
void func_0016ace0(u8*, V4*);
void func_0016b070(u8*, V4*);
s32 func_002e7568(u8*, s32, u8*, f32);
void func_002dae38(u8* p)
{
    f32 z = 0.0f;
    func_001c0d38(p, D_0034e948, 16384, 0);
    func_002cf2b0(p + 2800, 1);
    V4 v;
    v.x = z; v.y = z; v.w = z; v.z = -70.0f;
    func_0016ace0(p, &v);
    v.w = v.z = v.y = v.x = z;
    func_0016b070(p, &v);
    func_002e7568(p, 2, D_00362698, 1.0f);
}
extern V4 D_01e2be20;
V4* func_0016c028(u8*);  // obj_get_attach_or_alt
void func_0016af58(V4*, u8*);
void func_002cba88(V4*, u32, V4*, V4*, f32, f32);
void func_002e35e8(u8** p)
{
    u8* o = *(u8**)(p[0] + 4);
    if (!*(u32*)(o + 1288)) return;
    V4* a = func_0016c028(o);  // obj_get_attach_or_alt
    V4 r, b;
    func_0016af58(&b, o);
    func_002cba88(&r, *(u32*)(o + 1288), a, &b, ((f32*)p)[1], ((f32*)p)[2]);
    if (&D_01e2be20 != &r) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&D_01e2be20), "r"(&r) : "$8", "memory");
    p[0] = (u8*)&D_01e2be20;
}
typedef s32 (*Fn8)(u8*);
void func_002c65f8(u8*, s32);
void func_002c6280(u8*, s32);
struct S20 { u32 w[5]; };
extern u8 D_00361da8[];
extern u8 D_00361a80[];
extern u8* D_00361a70;
void func_0031cc28(u8*);
void func_002c6420(u8*);
}

}
namespace w72_e5 {
extern "C" {
#define GS_SET_RGBAQ(r, g, b, a, q) ((u64)(r) | ((u64)(g) << 8) | ((u64)(b) << 16) | ((u64)(a) << 24) | ((u64)(q) << 32))
#define GS_SET_XYZ(x, y, z) ((u64)(x) | ((u64)(y) << 16) | ((u64)(z) << 32))
struct Spr { u8 pad[4]; u16 w, h; s16 x, y; u32 z; u8 r, g, b, a; u8 pad2[180]; u64 rgbaq; u8 pad3[8]; u64 xyz0; u8 pad4[8]; u64 xyz1; u8 pad5[16]; u8 next[4]; };
void func_0014d8d0(u8*);
void func_0014b838(Spr* p)
{
    p->rgbaq = GS_SET_RGBAQ(p->r, p->g, p->b, p->a, 1);
    p->xyz0 = GS_SET_XYZ(p->x * 16 + 0x7000, p->y * 16 + 0x7300, p->z);
    p->xyz1 = GS_SET_XYZ((p->x + p->w) * 16 + 0x7000, (p->y + p->h) * 16 + 0x7300, p->z);
    func_0014d8d0(p->next);
}

void func_0014c350(Spr* p)
{
    p->rgbaq = GS_SET_RGBAQ(p->r, p->g, p->b, p->a, 1);
    p->xyz0 = GS_SET_XYZ(p->x * 16 + 0x7000, p->y * 16 + 0x7300, p->z);
    p->xyz1 = GS_SET_XYZ((p->x + p->w) * 16 + 0x7000, (p->y + p->h) * 16 + 0x7300, p->z);
    func_0014d8d0(p->next);
}

void func_0014c738(Spr* p)
{
    p->rgbaq = GS_SET_RGBAQ(p->r, p->g, p->b, p->a, 1);
    p->xyz0 = GS_SET_XYZ(p->x * 16 + 0x7000, p->y * 16 + 0x7300, p->z);
    p->xyz1 = GS_SET_XYZ((p->x + p->w) * 16 + 0x7000, (p->y + p->h) * 16 + 0x7300, p->z);
    func_0014d8d0(p->next);
}

}

}
namespace w73_f1 {
extern "C" {
typedef void (*Fn68)(u8*, s32, u32);
u8* func_00124748(u8*, s32);  // list_nth_node_rel
void func_001243f8(u8* p, s32 base, u32 c)
{
    u8* o = func_00124748(p, 0);  // list_nth_node_rel
    (*(Fn68*)(*(u8**)o + 68))(o, base, c);
    for (s32 i = 1; i < *(s32*)(p + 16); i++) {
        o = func_00124748(p, i);  // list_nth_node_rel
        (*(Fn68*)(*(u8**)o + 68))(o, base + ((s32*)(p + 28))[i], c);
    }
}
u32 func_00313bc0(f32);
u32 func_001334a8(u8* p, u32 a, u32 b)
{
    f32 r = (f32)a / (f32)b;
    return (func_00313bc0((f32)*(u32*)(p + 40) * r) >> 16) & 0xfff;
}
void func_0014b220(u8*, s32, s32, s32, s32);
void func_0014b620(u8*, s32);
extern u8* D_00347f80;
typedef u8* (*AllocFn)(u8*, s32, s32);
void func_0031bcf8(u8*);
void func_001516b0(u8*, u32, u32, u32, u32, u32, f32);
struct T96 { u8 pad[80]; s32 v; u8 pad2[12]; };
void func_002ba2e8(s32, s32);
void func_001395a8(u8*);
void func_001a98e8(T96*, s32, u32, s32, s32);
s32 func_0023aa18(u8*);
void func_001508a0(u8* p, u32 a)
{
    func_002ba2e8(34, 0);
    u8* q = p + 48;
    *(u32*)(p + 972) &= ~2;
    func_001395a8(p + 560);
    T96 t;
    func_001a98e8(&t, 0, a, 0, 0);
    s32 v = func_0023aa18(p + 72);
    *(s32*)(p + 968) = v - t.v;
    *(s32*)(q + 412) = v;
    *(s32*)(q + 416) = 0;
    *(f32*)(p + 976) = 180.0f;
}
void func_00139598(u8*);
}

}
namespace w73_f2 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct M4 { V4 r[4]; };
extern "C" {
typedef void (*VFn)(u8*);
static inline void VCopyChk(V4* d, V4* s)
{
    if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
static inline f32 VNormalize(V4* d, V4* s)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%2)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(d), "r"(s) : "$8", "memory");
    return r;
}
static inline void VScale(V4* d, V4* s, f32 k)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(s), "f"(k) : "$8", "memory");
}
static inline void CopyM(M4* d, M4* s)
{
    if (d != s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory");
}
static inline void ApplyM(V4* d, M4* m, V4* v)
{
    asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(d), "r"(m), "r"(v) : "memory");
}
s32 func_00197920(u8*);
void func_00138c10(u8*, s32);
void func_001390a8(u8*);
extern f32 D_00349e14;
void func_0017c430(u8*, V4*, f32);
void func_0011b6a8(M4*);
M4* func_0011b6d8(M4*, f32);
M4* func_0011b720(M4*, f32);
f32 func_0017ce10(f32);
V4* func_0017d5e8(V4* out, V4* in, f32 ang)
{
    M4 m;
    func_0011b6a8(&m);
    CopyM(&m, func_0011b6d8(&m, func_0017ce10(ang)));
    ApplyM(out, &m, in);
    return out;
}
V4* func_0017d538(V4* out, V4* in, f32 ang)
{
    M4 m;
    func_0011b6a8(&m);
    CopyM(&m, func_0011b720(&m, func_0017ce10(ang)));
    ApplyM(out, &m, in);
    return out;
}
typedef void (*Fn20)(u8*, f32*, f32*);
V4* func_0016c028(u8*);  // obj_get_attach_or_alt
s32 func_002bc420(u8*);
s32 func_0019c6f0(u8*);
void func_002bc3f0(u8*, V4*);
void func_002bc398(u8*, V4*);
struct E8b { u32 a; u8* p; };
extern E8b D_01c61970[];
u32 func_00191f20(u8*, u32);
void func_001920f0(u32);
void u_tail4_00192048(u32, u32, u32, u32) asm("_Z16u_tail4_00192048jjjj");
struct NoTail { ~NoTail() {} };
void u_tail4_00192048(u32 id, u32, u32, u32)
{
    NoTail g;
    u32 r = 0;
    for (s32 i = 0; i < 3; i++) {
        u8* o = D_01c61970[i].p;
        if (o && (r = func_00191f20(o, id))) break;
    }
    if (!r) r = func_00191f20(D_01c61970[1].p, 0x8adc);
    if (id - 19136 < 3) func_001920f0(r);
}
extern u8 D_01c62fb8[];
extern u8 D_0032e020[];
u8* func_0031f168(u8*, u8*);
void func_001a1840(u8*);
u8* func_001a0e78(void);
u32 func_00188fe0(u8*, s32);
u8* func_001a1490(s32 k)
{
    if ((u32)(k - 1) >= 15) return 0;
    u8* o = 0;
    while ((o = func_0031f168(D_01c62fb8, o))) {
        if (*(s32*)(o + 596) == k) {
            (*(s32*)(o + 600))++;
            func_001a1840(o);
            return o;
        }
    }
    o = func_001a0e78();
    *(s32*)(o + 596) = k;
    *(u32*)(o + 580) = func_00188fe0(D_0032e020, k);
    return o;
}
s32 func_001de2e0(u32, u32);
u8* func_001de168(u32, s32, u32, u32, u32, s32);  // scan_list_by_half
V4* func_001dc5f8(u8*);
u8* func_001a3b48(u32 a, u32 b, V4* v, u32 c, u32 d, u32 e)
{
    s32 id = func_001de2e0(a, b);
    u8* r = 0;
    if (id >= 0) {
        u8* o = func_001de168(a, id, c, d, e, 0);  // scan_list_by_half
        if (o) {
            V4* dst = func_001dc5f8(o);
            if (dst != v) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(dst), "r"(v) : "$8", "memory");
        }
        r = o;
    }
    return r;
}
s32 func_001d35e0(V4*, V4*, V4*, u32);
s32 func_001a7610(V4*, V4*, u32, f32, f32) asm("_Z13func_001a7610jjjff");
}

}
namespace w73_f3 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
static inline void VCopyChk(V4* d, V4* s)
{
    if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
static inline void VScale(V4* d, V4* s, f32 k)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(s), "f"(k) : "$8", "memory");
}
static inline void VAdd(V4* d, V4* a, V4* b)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
void func_0023acd8(u8*);
void func_0023ade0(u8*);
void func_001abba8(u8*, u32, u32);
void func_001abf38(s32* p, u32 a, u32 b)
{
    u8* q = (u8*)p + 4;
    switch (p[0]) {
    case 0:
        break;
    case 1:
        func_0023acd8(q);
        *(u32*)(q + 328) = a;
        *(u32*)(q + 332) = b;
        func_0023ade0(q);
        break;
    case 2:
        func_001abba8((u8*)p + 348, a, b);
        break;
    }
}
typedef void (*CbFn)(u32, u32, s32);
struct Rd { CbFn volatile cb; u8* obj; u32 buf; u32 size; s32 e; };
extern Rd D_00350cb0;
void func_003058a0(s32);
s32 func_002f7dc8(void);
void func_001c1748(u8*, u32, u32, u32);  // obj_init_from_src
struct Hit { u8 pad[16]; u32 a; s32 id; };
s32 func_00143b88(V4*, Hit*, u16*, u32*, u32);
s32 func_00143ae0(V4*, Hit*, u16*);
s32 func_001bb4a0(void);
u8* func_001bbcb0(void);
void func_001d1b60(u8*, s32);
void func_001d8718(s32 base, s32 i)
{
    if (!func_001bb4a0()) return;
    struct BF { u32 on : 1; };
    u8* t = func_001bbcb0();
    t += i * 56;
    if (!(u8)((BF*)(t + 244))->on) return;
    u8* e = func_001bbcb0() + i * 56;
    func_001d1b60(e + 232, *(s32*)(i * 56 + func_001bbcb0() + 276) + base);
}
extern f32 D_00349e10;
V4* func_001e0cc8(u8*);  // entry64_by_field32
V4* func_001e0ce8(u8*);  // entry64_by_field32_b
void func_001e0d08(u8*, V4*);
static inline void VCp(V4* d, V4* s) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory"); }
void func_001e1500(u8* p)
{
    V4 a, b, u, t;
    VCp(&a, func_001e0cc8(p));  // entry64_by_field32
    VCp(&b, func_001e0ce8(p));  // entry64_by_field32_b
    VScale(&t, &b, 40.0f);
    VScale(&u, &t, D_00349e10);
    VAdd(&a, &a, &u);
    func_001e0d08(p, &a);
}
extern u8* D_01d9e6e8;
void func_001fa668(u8*, u32, u8*);
void func_002f3cd8(V4*, u8*, V4*);
void func_002f3f40(u8*, V4*, f32);  // vec_scale_by_f12
void func_001faea8(u8*, s32, s32);
}

}
namespace w73_f4 {
extern "C" {
extern s32 D_0035ece0;
extern s32 D_003718d0[];
void func_0023d320(s32);
void func_00242740(s32);
void func_00287910(s32, s32, s32);
u32 func_00103570(void);
void func_0028c878(u32, s32);
void func_002425d0(s32);
void func_00242fa0(void);
typedef void (*KFn)(s32);
u8* func_00243150(void);
extern u8* D_0035eea4;
extern s16 D_0035eea0;
extern s16* D_0035ee9c;
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
s32 func_0023f100(u8*);
s32 func_0023f0c0(u8*);
void func_0023f0c8(u8*, s32);
void func_00252ce0(void)
{
    u_call4_00139d78(D_0035eea4);
    if (func_0023f100(D_0035eea4) != -1) return;
    s32 v = func_0023f0c0(D_0035eea4);
    s32 r = -1;
    for (s32 i = 0; i < D_0035eea0; i++) {
        if (v == D_0035ee9c[i]) { r = D_0035ee9c[i + 1]; break; }
    }
    if (r >= 0) func_0023f0c8(D_0035eea4, r);
}
u8* func_00257770(void);
s32 func_002570a0(s32);
u8* func_002632d0(s32);
u32 tail4_00192048(u32) asm("_Z16u_tail4_00192048jjjj");
u32 func_002594b8(u8);
void func_00192e50(u32, u8*, s32, u32, u32);
void func_00257458(u8*, s32);
void func_002571e0(s32);
void func_00287cc0(s32);
void func_001391c8(u8*, u32, u32);
void func_0028e2a8(u8*, s32);
void func_0028e190(u8*, s32);
void func_0028e3b8(u8*, s32, u32, u32, s16);
void func_0028e0d8(u8* p, u32 a1, u32 a2, u32 a3, s16* list, s32 n, u32 t2)
{
    func_001391c8(p, a1, t2);
    func_0028e2a8(p, n);
    func_0028e190(p, n);
    for (s32 i = 0; i < n; i++) func_0028e3b8(p, i, a2, a3, list[i]);
}
extern u8* D_0035f480;
s16* func_0028f690(s32);  // record884_type_index
void func_00138c10(u8*, s32);
void func_0028d5d0(u8*);
s32 func_0028d6e8(u8*);
union GPi { u8* p; s32 i; };
extern GPi D_0035f480u asm("D_0035f480");
s32 func_0028f930(s32 k)
{
    s32 r = 0;
    for (s32 i = 0; i < 4; i++) {
        if (k >= 0 && k != i) continue;
        if (u_call4_00139d78(D_0035f480 + i * 884) || func_0028d6e8(D_0035f480 + i * 884 + 436)) { r = 1; break; }
    }
    return r;
}
struct E16c { s8 id; u8 pad[3]; u16 a, b; u8 pad2[2]; u16 c, d; u8 pad3[2]; };
u8* func_00294000(s32);
s32 func_002941d8(E16c*);
}

}
namespace w73_f5 {
extern "C" {
u32 func_00317138(u32);
u32 func_00317130(u32);
u32 func_00317128(u32);
void func_002fd160(void) __attribute__((noreturn));
// libgcc unwind-pe.h base_of_encoded_value (second copy)
u32 func_00314a50(u8 enc, u32 ctx)
{
    if (enc == 0xff) return 0;
    switch (enc & 0x70) {
    case 0x00:
    case 0x10:
    case 0x50:
        return 0;
    case 0x20:
        return func_00317138(ctx);
    case 0x30:
        return func_00317130(ctx);
    case 0x40:
        return func_00317128(ctx);
    }
    func_002fd160();
}
void func_002f1900(u8*, s32, u8*);
void func_002f19c8(u8*);
void func_002c6050(u8* p, s32 k)
{
    switch (k) {
    case 1: func_002f1900(p + 3028, 5, p); func_002f19c8(p + 3032); break;
    case 2: func_002f19c8(p + 3028); func_002f1900(p + 3032, 6, p); break;
    default: {
        for (s32 i = 0; i < 2; i++) func_002f19c8(p + 3028 + i * 4);
    }
    }
}
u8* func_00294000(s32);
s32 func_002944d0(u8*);
s32 func_00276c18(void);
union U52 { u8 b; s8 c; u32 w; };
extern u8* D_0035f638;
s32 func_00292630(void);
void func_002b2840(void);
void func_00293bd0(s32, u8*, s32);
void func_002925c0(void);
void func_002b2428(u32 v)
{
    ((U52*)(D_0035f638 + 52))->b = v;
    if (func_00292630()) { ((U52*)(D_0035f638 + 52))->w &= ~0x100; return; }
    u8* t = func_00294000(9) + 16;
    func_002b2840();
    func_00293bd0(5, t + ((U52*)(D_0035f638 + 52))->c * 16 + 6, 0);
    func_002925c0();
    ((U52*)(D_0035f638 + 52))->w |= 0x100;
}
extern u8 D_01e2a410[];
extern u32 D_003616e0;
extern u32 D_01e2a400[3];
void func_002b7fbc(s32);
void func_002b6bc4(s32);
void func_002b9ab8(s32);
void func_002ba298(s32);
void func_002ba390(void);
void func_002bce40(u8*);
void func_002bce50(u8*);
void func_002b9b78(void);
void func_002bd218(void);
void u_tail0_002b9ad0(void) asm("_Z16u_tail0_002b9ad0v");
void u_tail0_002b9ad0(void)
{
    func_002b7fbc(0);
    func_002b6bc4(1);
    func_002b9ab8(20);
    func_002ba298(0);
    func_002ba298(1);
    func_002ba390();
    func_002bce40(D_01e2a410);
    func_002bce50(D_01e2a410);
    func_002b9b78();
    func_002bd218();
    D_003616e0 = 0;
    u32* w = D_01e2a400;
    s32 i = 2;
    do {
        *w = 0;
        i--;
        // R5900 short-loop padding
        asm volatile("nop\n\tnop\n\tnop");
        w++;
    } while (i >= 0);
}
extern f32 D_00349e10;
void func_00187750(u8*);
f32 func_002f8870(f32);  // fabsf
u8* func_00168b38(u32, s32, s32);  // entry_array_find_nth
void func_002ef180(u32*, f32, f32);
typedef s32 (*Fn8)(u8*);
extern u8 D_0034a548[];
extern u8 D_00347e80[];
extern u8 D_00347e60[];
void func_002361a0(u8*);
void func_00239700(u8*);
}

}
namespace w74_g1 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
typedef void (*Fn72)(u8*, s32, u32);
u8* func_00124748(u8*, s32);  // list_nth_node_rel
void func_001244b8(u8* p, s32 base, u32 c)
{
    u8* o = func_00124748(p, 0);  // list_nth_node_rel
    (*(Fn72*)(*(u8**)o + 72))(o, base, c);
    for (s32 i = 1; i < *(s32*)(p + 16); i++) {
        o = func_00124748(p, i);  // list_nth_node_rel
        (*(Fn72*)(*(u8**)o + 72))(o, base + ((s32*)(p + 28))[i], c);
    }
}
extern f32 D_00349e10;
f32 func_0017ce10(f32);
f32 func_002f8870(f32);  // fabsf
s32 func_00116d08(u8* p)
{
    V4 d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&d), "r"(p + 1600), "r"(p + 1616) : "memory");
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(&d) : "$8", "memory");
    if (!(len < *(f32*)(p + 1576) * D_00349e10)) return 0;
    f32 a = func_002f8870(func_0017ce10(d.w));  // fabsf
    f32 k = D_00349e10;
    if (a < *(f32*)(p + 1580) * k) return 1;
    return 0;
}
void func_00136200(u8*, u32);
void func_00136020(u8*);
u32 func_001dc5f0(u32);
void func_00136158(u8* p, u32 v)
{
    if (!v) return;
    func_00136200(p, v);
    s32 n = *(s32*)(p + 12);
    if (n == 32) {
        func_00136020(p);
        if (*(s32*)(p + 12) == n) func_00136200(p, *(u32*)(p + 16));
    }
    ((u32*)(p + 16))[*(s32*)(p + 12) * 2] = v;
    s32 i = *(s32*)(p + 12);
    ((u32*)(p + 20))[i * 2] = func_001dc5f0(v);
    (*(s32*)(p + 12))++;
}
extern u8 D_003495c0[];
extern u8 D_003496d0[];
extern u8 D_003497e0[];
extern u8 D_003498f0[];
void func_0014b1e0(u8*, s32, s32);
void func_0014b208(u8*, s32, s32);
void func_0014ad58(void)
{
    func_0014b1e0(D_003495c0, 0, 0);
    func_0014b208(D_003495c0, 512, 35);
    func_0014b1e0(D_003496d0, 0, 381);
    func_0014b208(D_003496d0, 512, 35);
    func_0014b1e0(D_003497e0, 0, 0);
    func_0014b208(D_003497e0, 512, 35);
    func_0014b1e0(D_003498f0, 0, 381);
    func_0014b208(D_003498f0, 512, 35);
}
extern u8 D_0034a6b8[];
u32 func_00152598(u8*, u32, u32, u8*);
void func_00152508(u8*, u32, u32, u32, u32);
void func_00152990(u8* p, u32 a1, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g)
{
    u32 r = func_00152598(p, f, d, D_0034a6b8);
    *(u32*)(p + 448) = f;
    *(u32*)(p + 444) = e;
    *(u32*)(p + 440) = d;
    *(u32*)(p + 436) = b;
    func_00152508(p, r, b, c, g);
}
extern u8 D_0035eb98[];
extern u8 D_0034a7c0[];
u8* func_0023ee30(s32);
void func_002369a0(u8*);  // obj_ctor_36eac8
void func_0023c008(u8*);  // obj_ctor_36eae8
void func_00153cc8(u8*, u32, s32, u32, s32);
s32 func_0013a9d0(void);
void func_00236bb8(u8*, f32);
u8* func_00153d70(u32 a, u32 b)
{
    u8* o = func_0023ee30(164);
    *(u32*)(o + 12) = 0;
    *(void**)o = D_0035eb98;
    func_002369a0(o + 24);  // obj_ctor_36eac8
    func_0023c008(o + 48);  // obj_ctor_36eae8
    *(void**)o = D_0034a7c0;
    func_00153cc8(o, a, 4800, b, 0);
    if (func_0013a9d0()) func_00236bb8(o + 24, 1.0f);
    return o;
}
extern u8 D_0034af40[];
extern u8 D_0034b0e0[];
void func_00236788(u8*);  // to_236830
u8 func_00239d30(u8*, u32);
s32 func_00239d10(u8*);
u32 func_0014aba8(void);
void func_0014aa58(u32, s32, s32);
void func_0013f020(void);
void func_0023acd8(u8*);
void func_0023ade0(u8*);
}

}
namespace w74_g2 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct M4 { V4 r[4]; };
extern "C" {
static inline void VCopyChk(V4* d, V4* s)
{
    if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
static inline f32 VNormalize(V4* d, V4* s)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%2)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(d), "r"(s) : "$8", "memory");
    return r;
}
static inline void VSub(V4* d, V4* a, V4* b)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline f32 VDot(V4* a, V4* b)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(a), "r"(b) : "$8", "memory");
    return r;
}
static inline void CopyM(M4* d, M4* s)
{
    if (d != s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory");
}
static inline void ApplyM(V4* d, M4* m, V4* v)
{
    asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(d), "r"(m), "r"(v) : "memory");
}
extern u8 D_0034c70c;
extern u8 D_0034c6f0[];
void func_001431c0(void);
void func_00161228(void);
u8* func_001de4b0(u8*, s32, u8*);
s32 func_001dc9e0(u8*);
void func_001dc698(u8*, s32);
void func_0015f298(void)
{
    u8* o = 0;
    func_001431c0();
    func_00161228();
    if (D_0034c70c != 1) return;
    for (s32 i = 0; i < 64; i++) {
        while ((o = func_001de4b0(D_0034c6f0, i, o))) {
            if (func_001dc9e0(o)) func_001dc698(o, 0);
        }
    }
}
struct E12 { u32 a; u32 flags; u32 c; };
extern E12 D_01c60588[];
extern s32 D_0034ed00;
void func_00182940(E12*);
void func_00182bc0(s8* k)
{
    u32 key = k[0] | k[1] << 8 | k[2] << 16 | k[3] << 24;
    for (s32 i = 0; i < D_0034ed00; i++)
        if (D_01c60588[i].a == key) func_00182940(&D_01c60588[i]);
}
f32 func_0017ce10(f32);
void func_0017d1d8(M4*, u32, f32);
struct B32 { f32 a, y, c; u32 d; V4 pos; };
f32 func_002f8870(f32);  // fabsf
s32 func_0018a420(B32* a, B32* b)
{
    V4 t, d;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder" : : "r"(&b->pos), "r"(&a->pos), "r"(&d) : "memory");
    VCopyChk(&t, &d);
    f32 dy = func_002f8870(t.y);  // fabsf
    if (a->c + b->c <= dy) return 0;
    f32 r = a->y + b->y;
    *(u32*)&t.y = 0;
    if (VDot(&t, &t) < r * r) return 1;
    return 0;
}
typedef void (*PosFn)(V4*, u8*);
V4* func_0018df90(V4* out, u8* p, u8* o)
{
    V4 d, a;
    u8* q = *(u8**)(p + 12) + 1840;
    (*(PosFn*)(*(u8**)o + 8))(&a, o);
    VSub(&d, (V4*)q, &a);
    VCopyChk(out, &d);
    *(u32*)&out->y = 0;
    VNormalize(out, out);
    return out;
}
struct S36 { u32 w[9]; };
u8* func_001050d8(s32);
u32 func_00181c80(u32);
void func_00196ca8(u8*, u32, u32);
void func_00196f00(u8*);
void func_00197930(u32 a, u32 b, S36* c)
{
    u8* o = func_001050d8(176);
    func_00196ca8(o, b, func_00181c80(a));
    *(S36*)(o + 12) = *c;
    func_00196f00(o);
}
s32 func_00181500(s32);
s32 func_001afee8(s32 a, s32 b)
{
    if (a == b) return -1;
    if (!func_00181500(6220) && !func_00181500(6156) && !func_00181500(6190)) {
        if (a == 5 || b == 5) return -1;
    }
    if ((u32)(b - 1) >= 15) return -1;
    if ((u32)(b - 1) < 3) return b - 1;
    return b == 15 ? 4 : 3;
}
}

}
namespace w74_g3 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
static inline void VCopyChk(V4* d, V4* s)
{
    if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
typedef void (*Fn20)(u8*, u8*);
void func_0017c870(V4*, f32, f32);
s32 func_001b2d10(u8*, V4*);
u8* func_001b9bc8(u8*);
u8* func_0016b800(s32);
s32 func_0019ba60(u8*);
void func_00190878(u8*, u8*, s32);
void func_001bc778(u8*);
s32 func_001c8bb8(s8*);
u32 func_001c8cc0(s8);
void func_001bc780(u8*, u32, u8*, s32);
u8* func_001bf010(u8* p)
{
    u8* o = func_0016b800(201);
    func_0019ba60(o);
    func_00190878(p + 2704, o, 0);
    u8* q = p + 384;
    func_001bc778(q);
    s8 buf[16];
    s32 n = func_001c8bb8(buf);
    for (s32 i = 0; i < n; i++) func_001bc780(q, func_001c8cc0(buf[i]), p + 2704, 1);
    return q;
}
extern f32 D_00349e10;
f32* func_001dc670(u8*);
void func_001dc878(u8*);
void func_001dcae0(u8* p)
{
    f32 v = *(f32*)(p + 36);
    if (v != 0.0f) {
        f32 a = *(f32*)(p + 32) + v * D_00349e10;
        *(f32*)(p + 32) = a;
        if (a < 0.0f) { *(f32*)(p + 32) = 0.0f; *(f32*)(p + 36) = 0.0f; }
        if (0.0f < *(f32*)(p + 32)) {
            f32* q = func_001dc670(p);
            q[3] *= *(f32*)(p + 32);
        }
    }
    if ((*(u32*)(p + 8) & 0x20000) && *(f32*)(p + 32) <= 0.0f) func_001dc878(p);
}
u8* func_00102c80(void);
u8* func_00104190(void);
void func_00102180(u8**);
void func_001e02f8(s32);
void func_001de8a8(u32, s32, s32, s32);
extern f32 D_00354be0[3];
extern u8* D_01d9e6e8;
extern u8 D_01d9e940[];
extern u8 D_01d9e900[];
void func_002f3f40(u8*, u8*, f32);  // vec_scale_by_f12
void func_002f3d08(u8*, u8*, u8*);
void func_002f3cd8(u8*, u8*, u8*);
union GPV { u8* p; V4 v; };
extern GPV D_01d9e6e8u asm("D_01d9e6e8");
void func_001eb460(void)
{
    f32* s = D_00354be0;
    func_002f3f40(D_01d9e6e8u.p + 80, D_01d9e6e8u.p + 16, s[0]);  // vec_scale_by_f12
    func_002f3f40(D_01d9e6e8u.p + 96, D_01d9e6e8u.p + 32, s[1]);  // vec_scale_by_f12
    func_002f3f40(D_01d9e6e8u.p + 112, D_01d9e6e8u.p + 48, s[2]);  // vec_scale_by_f12
    *(V4*)(D_01d9e6e8u.p + 128) = *(V4*)(D_01d9e6e8u.p + 64);
    func_002f3d08(D_01d9e6e8u.p + 80, D_01d9e940, D_01d9e6e8u.p + 80);
    func_002f3cd8(D_01d9e6e8u.p + 128, D_01d9e900, D_01d9e6e8u.p + 64);
}
}

}
namespace w74_g4 {
extern "C" {
extern u8* D_0035ece8;
extern u8* D_0035ecec;
s32 func_002892f8(u8*);
s32 func_0028acc8(u8*);
void func_00288e88(u8*);
void func_00244888(void)
{
    if (D_0035ece8) {
        s32 a = func_002892f8(D_0035ece8);
        if (!func_0028acc8(D_0035ece8) && a) func_00288e88(D_0035ece8);
    }
    if (D_0035ecec) {
        s32 a = func_002892f8(D_0035ecec);
        if (!func_0028acc8(D_0035ecec) && a) func_00288e88(D_0035ecec);
    }
}
struct E6 { s16 a, b, c; };
extern s32 D_0035ee2c;
extern u8* D_0035ee10;
extern E6 D_00372390[];
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
s32 func_0024f2b8(s32);  // word_table_372368
void func_00138c10(u8*, s32);
void func_0024f1a0(void)
{
    if (D_0035ee2c < 0) return;
    if (!D_0035ee10) return;
    if (!u_call4_00139d78(D_0035ee10)) return;
    s32 k = func_0024f2b8(D_0035ee2c);  // word_table_372368
    s16 v = D_00372390[k].b;
    if (*(s32*)(D_0035ee10 + 388) == v) return;
    D_0035ee2c = -1;
    func_00138c10(D_0035ee10, v);
    *(s32*)(D_0035ee10 + 392) = -1;
}
extern u8* D_0035f02c;
extern u8 D_0035f056;
void func_0028dac8(u8*, s32);
s32 func_00256b80(s32);
u8* func_00256b68(s32);
u32 func_00287dc0(void);
void func_0023d820(u32);
void func_00254e60(void)
{
    if (u_call4_00139d78(D_0035f02c)) func_0028dac8(D_0035f02c, 48);
    if (!func_00256b80(0)) return;
    u8* o = func_00256b68(0);
    if (*(s32*)(o + 388) != 117) { func_00138c10(o, 117); *(s32*)(o + 392) = -1; }
    if (D_0035f056) return;
    func_0023d820(func_00287dc0());
}
extern E6 D_00373798[];
u8* func_00257770(void);
s32 func_00287bc0(void);
s32 func_002570a0(s32);
s32 func_00269508(s32);
s32 func_00269fc0(void)
{
    s32 r = 0;
    u8* o = func_00257770();
    s32 k = func_00287bc0();
    if (o && u_call4_00139d78(o)) {
        s32 v = 228;
        if (k != 2) v = D_00373798[func_00269508(func_002570a0(2))].c;
        r = *(s32*)(o + 388) == v;
    }
    return r;
}
extern u32 D_0035f4bc, D_0035f4c0, D_0035f4c4, D_0035f4c8, D_0035f4cc, D_0035f4d0;
extern u16 D_0035f4d8, D_0035f4e0;
extern u8 D_0035f4e2;
extern void* D_0035f4d4;
extern void* D_0035f4dc;
extern void* D_0035f4e4;
void func_00106450(void*);
void func_002927b8(void)
{
    D_0035f4bc = 0;
    D_0035f4c0 = 0;
    D_0035f4c4 = 0;
    D_0035f4d8 = 0;
    D_0035f4e0 = 0;
    D_0035f4d0 = 0;
    D_0035f4c8 = 0;
    D_0035f4cc = 0;
    D_0035f4e2 = 0;
    if (D_0035f4d4) { func_00106450(D_0035f4d4); D_0035f4d4 = 0; }
    if (D_0035f4dc) { func_00106450(D_0035f4dc); D_0035f4dc = 0; }
    if (D_0035f4e4) { func_00106450(D_0035f4e4); D_0035f4e4 = 0; }
}
extern u32 D_0035f570;
extern u8* D_0035f574;
extern u32* D_0035f578;
u8* func_001063c0(s32, u32);
void func_002907c0(u8*, u32, s32);
void func_00276150(u32, s32*, s32*);
s32 func_00276568(void);
s32 func_002956c0(s32);
s32 func_00295710(s32 a)
{
    s32 r = 0;
    u32 o = func_00287bc0();
    if ((u32)(a + 9) < 2) {
        s32 x, y;
        func_00276150(o, &x, &y);
        s32 v = a == -8 ? y : x;
        s32 c = *(s8*)func_00276568();
        if (v != 2) r = 1;
        else if ((u32)c < 15) r = 1;
    } else if (a >= 0) {
        r = func_002956c0(a);
    }
    return r;
}
extern u32 D_0035f59c;
extern s16* D_0035f598;
extern s8 D_0035f5a1;
extern u8 D_0035f5a2;
void func_0023f900(u32);
s32 func_00292630(void);
s8* func_002983d8(s16);
char* func_00293de8(s8);
void func_002ff2e8(char*, const char*);
void func_002feee8(char*, const char*);
u32 func_00293db8(s32, char*);
void func_0023fa08(u32, u32);
void func_00298ee0(void)
{
    char buf[32];
    func_0023f900(D_0035f59c);
    if (func_00292630()) return;
    s8* s = func_002983d8(D_0035f598[D_0035f5a1 + 2]);
    func_002ff2e8(buf, func_00293de8(s[0]));
    func_002feee8(buf, (char*)s + 1);
    func_0023fa08(D_0035f59c, func_00293db8(3, buf));
    D_0035f5a2 = 1;
}
extern u8* D_0035f5f4;
extern u8* D_0035f5f8;
extern s8 D_0035f5fc;
extern s8 D_0035f5fd;
void func_00106420(u8*);
typedef void (*VFn)(u8*);
void func_002a6970(void)
{
    u8* a = D_0035f5f4;
    if (a) {
        u8* q = a + 3488;
    loop:
        if (a == q) goto done;
        q -= 436;
        (*(VFn*)(*(u8**)q + 12))(q);
        goto loop;
    done:
        func_00106420(a);
        D_0035f5f4 = 0;
    }
    if (D_0035f5f8) { (*(VFn*)(*(u8**)D_0035f5f8 + 4))(D_0035f5f8); D_0035f5f8 = 0; }
    D_0035f5fc = -1;
    D_0035f5fd = -1;
}
}

}
namespace w74_g6 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
typedef void (*VFn)(u8*);
extern u8* D_01e2aa80;
void func_002bbf68(u8*, s32);
static inline u8* NextZ(u8* n) { if (!n) return D_01e2aa80; return *(u8**)(n + 28); }
void func_002bc470(u32 id)
{
    u8* n = 0;
    while ((n = NextZ(n))) {
        if (*(u32*)(n + 24) != id) continue;
        u8 s = n[49];
        if (s < 3 || s == 4 || s == 3) func_002bbf68(n, 1);
    }
}
extern u8* D_0034e948;
extern s8 D_01e2bc20;
extern V4 D_01e2bc30;
u32 func_0016b740(s32);
void func_001c0d38(u8*, u32, s32, s32);
void func_002fd188(void (*)(void));  // pool_alloc_block
void func_002be6e8(void);
void func_0016b070(u8*, V4*);
void func_0017f488(u8*, s32, f32, f32);
extern f32 D_00349e18;
extern f32 D_00349e10;
static inline void VSub(V4* d, V4* a, V4* b)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline void VScale(V4* d, V4* s, f32 k)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(s), "f"(k) : "$8", "memory");
}
static inline f32 VNormalize(V4* d, V4* s)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%2)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(d), "r"(s) : "$8", "memory");
    return r;
}
V4* func_002c6610(V4* out, u32, V4* a, V4* b, f32 k, f32 lim)
{
    V4 t, d;
    VSub(&d, b, a);
    VScale(&t, &d, k);
    f32 s = VNormalize(&t, &t) * D_00349e18;
    if (lim < s) s = lim;
    VScale(out, &t, s * D_00349e10);
    return out;
}
extern u32 D_00361f60;
void func_001780d8(u8*);
void func_00198860(u8*, s32);
u8* func_002d1f00(u32);  // ptr_add160
void func_0016ace0(u8*, V4*);
void func_0016aef0(u8*, V4*);
void func_0016bd60(u8*, s32);
void func_002d4aa0(u8* p)
{
    func_001780d8(p);
    func_00198860(p, 6);
    V4 a, b;
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&a), "r"(func_002d1f00(D_00361f60) + 48) : "$8", "memory");  // ptr_add160
    *(u32*)&a.z = 0;
    func_0016ace0(p, &a);
    asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(p + 3104) : "memory");
    f32 z = 0.0f;
    b.x = 1.0f;
    b.y = z;
    b.z = z;
    b.w = z;
    func_0016aef0(p, &b);
    func_0016bd60(p, 37);
}
struct HT { u8* head; u8* tail; };
extern HT D_01e2c080;
extern u8 D_00363808[];
extern u32 D_003637f8;
void func_002edf28(u8*);  // obj_ctor_3637e0
u8* func_002ee840(void);  // get_data_1e2c088
void func_002ee498(void);
u32 func_00102788(u32, s32, s32, void (*)(void));
void func_002ee220(u8* p)
{
    func_002edf28(p);  // obj_ctor_3637e0
    *(u32*)p = (u32)D_00363808;
    if (!D_003637f8) {
        u8* o = func_002ee840();  // get_data_1e2c088
        (**(VFn**)o)(o);
        D_003637f8 = func_00102788(*(u32*)(o + 4), 0, 2000, func_002ee498);
    }
    if (!D_01e2c080.head) {
        D_01e2c080.tail = p;
        D_01e2c080.head = p;
        *(u8**)(p + 32) = 0;
    } else {
        *(u8**)(p + 32) = D_01e2c080.head;
        D_01e2c080.head = p;
    }
}
extern s8 D_003638c8;
s32 func_002ef7b8(void);
void func_002ef7a0(s32, s32);
extern u8 D_00347dd0[];
extern u8 D_00347e60[];
extern u8 D_00347e80[];
extern u8 D_00347f98[];
extern u32 D_00347f80;
void func_00239870(u8*);
void func_002361d0(u8*);
void func_0031a840(u8*);
typedef void (*FreeFn)(u8*, u8*);
void func_0031a460(u8* p)
{
    *(void**)p = D_00347dd0;
    *(void**)(p + 896) = D_00347e60;
    func_00239870(p + 920);
    *(void**)(p + 896) = D_00347f98;
    *(void**)(p + 448) = D_00347e80;
    func_002361d0(p + 480);
    *(void**)(p + 448) = D_00347f98;
    *(void**)p = D_00347e60;
    func_00239870(p + 24);
    func_0031a840(p);
    u8* al = *(u8**)(D_00347f80 + 20);
    (*(FreeFn*)(*(u8**)al + 4))(al, p);
}
extern u8 D_0034a618[];
void func_0031c6f8(u8* p)
{
    *(void**)p = D_0034a618;
    if (p != (u8*)-456) {
        u8* q = p + 2864;
        u8* a = p + 456;
    loop:
        if (a == q) goto done;
        q -= 344;
        (**(VFn**)q)(q);
        goto loop;
    }
done:
    *(void**)(p + 48) = D_00347e60;
    func_00239870(p + 72);
    *(u32*)(p + 48) = (u32)D_00347f98;
    *(u32*)p = (u32)D_00347f98;
    u8* al = *(u8**)(D_00347f80 + 20);
    (*(FreeFn*)(*(u8**)al + 4))(al, p);
}
}

}
namespace w74_b4 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
struct B32 { f32 a, y, c; u32 d; V4 pos; };
u8* func_001b9bc8(u8*);
u32 func_0016bba8(u8*, s32, u32);
void func_0018a818(B32*, u8*, u32);
extern u8* D_0034dca0;
extern u32 D_0034dcb0;
void func_001700e8(u8*, s32);
void func_0016fc10(u8*);
s32 func_002ff1a4(u8*, u32);  // strcmp
static inline u8* NextA(u8* n) { if (!n) return D_0034dca0; return *(u8**)(n + 60); }
u8* func_0018bc60(u8*, s32);
u32 func_0018bae8(u8*, u8*);
// YS::STDOBJ::hook_command_image
extern s8 D_0036d0c8[4];
u8* func_00168b88(u32, s32, u32, s32);  // find_entry16_by_half_word
void func_0013d6b0(u32, u32);
static inline u32 Key4(s8* k) { return k[0] | k[1] << 8 | k[2] << 16 | k[3] << 24; }
void STDOBJ_hook_command_image(u8*) asm("_ZN2YS6STDOBJ18hook_command_imageEv");
void STDOBJ_hook_command_image(u8* p)
{
    u8* q = p + 1952;
    u8* r1 = func_00168b88(*(u32*)(q + 16), 24, Key4(D_0036d0c8), 0);  // find_entry16_by_half_word
    u32 k2 = Key4(D_0036d0c8);
    u32 o = *(u32*)(q + 16);
    u32 a = *(u32*)(r1 + 8);
    u32 b = *(u32*)(func_00168b88(o, 25, k2, 0) + 8);  // find_entry16_by_half_word
    func_0013d6b0(a, b);
}
typedef s32 (*Fn8)(u8*, u32);
static inline u8* NextR(u8* p, u8* n) { if (!n) return *(u8**)(p + 12); return *(u8**)(n + 96); }
struct E56 { u32 a; u32 b; u8 pad[4]; u32 c; u32 d; u8 pad2[36]; };
extern E56 D_01c62198[64];
void func_00199cd0(E56*);
void wtarget_0019b970(u32, u32, u32, u32) asm("_Z16wtarget_0019b970jjjj");
void func_0019e210(u8**, u32);
extern u8 D_00350ab0[];
void func_001ac970(u8*, s32, s32, u32, s32, s32, s32, s32);
void func_001ac258(u8*);
void func_00239700(u8*);
void func_001a9970(u8*, s32);
}

}
namespace w75_h1 {
extern "C" {
typedef void* (*AllocFn)(u8*, u32, void*);
extern s32 D_0033cc68;
extern void* D_0033cc64;
extern void* D_0033cc6c;
extern void* D_0033cc70;
void func_00133cf0(void*, u32);
void func_00109070(void);
struct E6 { s16 a, b, c; };
extern E6 D_00347770[6];
void func_00194108(u32, s16);
void func_001940f0(u32, s16);
void func_001c8cf8(s32);
void func_00119e60(u8* p, s32 v)
{
    *(s32*)(p + 20) = v;
    s32 i;
    for (i = 0; i < 6; i++) func_00194108(*(u32*)(p + 4), D_00347770[i].c);
    for (i = 0; i < 6; i++)
        if (*(s32*)(p + 20) == D_00347770[i].a) { func_001940f0(*(u32*)(p + 4), D_00347770[i].c); break; }
    func_001c8cf8(i + 1);
}
u32* func_002f35e8(s32);
void func_003058a0(s32);
extern u8* D_00347d64;
void func_00192c90(u8*, u8*);
void func_00192b30(u8*);
void func_002362b0(u8*, u32);
s32 func_0013a9d0(void);
void func_002368e8(u8*, f32);
void func_002367c8(u8*);  // obj_dispatch_bitfield64
void func_001386e0(u8*, u32, u32, u8*, u32, u32);
void func_00154048(u8* p, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1)
{
    *(u32*)(p + 832) = 0;
    u8* q = p + 416;
    func_002362b0(q, a3);
    if (func_0013a9d0()) func_002368e8(q, 1.0f);
    func_002367c8(q);  // obj_dispatch_bitfield64
    func_001386e0(p, a1, a2, q, t0, t1);
    p[836] = 1;
}
s32 func_0013c7d0(void);
s32 func_00155d58(u8*, s32);  // table_word_indexed_by_3
s32 func_00155f40(u8*);
s32 func_00155fc0(u8*);
void func_00138c10(u8*, s32);
void func_00157aa0(u8*);
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void func_001578d8(u8* p)
{
    if (p[32]) return;
    if (func_0013c7d0()) {
        u8* s = p + 12060;
        func_00138c10(p + 6704, func_00155d58(p, 0));
        func_00138c10(p + 11648, func_00155f40(p));
        if (u_call4_00139d78(s)) func_00138c10(s, func_00155fc0(p));
        func_00157aa0(p);
        p[32] = 1;
    } else if (p[12052]) {
        p[32] = 1;
    }
}
extern u64 D_0034c710;
extern u8 D_0034c70c;
extern u8 D_0034c6f0[];
void func_00143228(void);
void func_0015c4a0(s32);
void func_001de3d8(u8*, s32);
void func_0015f4a0(void)
{
    func_00143228();
    for (s32 i = 0; i < 64; i++) {
        u64 bit = (u64)1 << i;
        if (!(D_0034c710 & bit)) continue;
        func_0015c4a0(i);
        if (D_0034c70c == 1) func_001de3d8(D_0034c6f0, i);
    }
}
}

}
namespace w75_h2 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct M4 { V4 r[4]; };
extern "C" {
static inline void VCopyM(M4* d, M4* s)
{
    if (d != s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory");
}
void func_0011b6a8(M4*);
M4* func_0011b7b0(M4*, u8*);
void func_001604f8(u8* p)
{
    M4* m = (M4*)(p + 16);
    func_0011b6a8(m);
    VCopyM(m, func_0011b7b0(m, p + 96));
    asm volatile("lqc2 $vf1, 48(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 48(%0)" : : "r"(m), "r"(p + 80) : "memory");
    asm volatile("lqc2 $vf4, 0(%1)\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tvmulx.wxyz $vf1, $vf1, $vf4x\n\tvmuly.wxyz $vf2, $vf2, $vf4y\n\tvmulz.wxyz $vf3, $vf3, $vf4z\n\tsqc2 $vf1, 0(%0)\n\tsqc2 $vf2, 16(%0)\n\tsqc2 $vf3, 32(%0)" : : "r"(m), "r"(p + 112) : "memory");
}
s32 func_0019c5d0(u8*);
u32 func_0016ac38(u8*, s32, s32, s32, s32);
s32 func_001dc9e0(u32);
void func_001dc818(u32);
void func_00185988(u8* p)
{
    u32 h = *(u32*)(p + 2552);
    if (!h) {
        if (func_0019c5d0(p)) return;
        if (*(u32*)(p + 352) & 0x800) *(u32*)(p + 2552) = func_0016ac38(p, 10, 1, 0, 0);
        return;
    }
    if (func_001dc9e0(h)) {
        if (!func_0019c5d0(p) && (*(u32*)(p + 352) & 0x800)) return;
        func_001dc818(*(u32*)(p + 2552));
    }
    *(u32*)(p + 2552) = 0;
}
V4* func_0016c028(u8*);  // obj_get_attach_or_alt
void func_0016aef0(u8*, V4*);
s32 func_0019ba60(u8*);
void func_0017f488(u8*, s32, f32, f32);
void func_0018b288(u8* p, V4* v, f32 x)
{
    if (!(*(u32*)(p + 2820) & 0x10)) {
        V4 d;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&d), "r"(v), "r"(func_0016c028(p)) : "memory");  // obj_get_attach_or_alt
        func_0016aef0(p, &d);
    }
    if ((*(u8**)(p + 8))[4] != 15) return;
    u8* o = *(u8**)(p + 2824);
    if (o && func_0019ba60(o)) func_0017f488(*(u8**)(p + 2824) + 320, 50, x, 0.0f);
}
s32 func_0018bd50(u32, s32);
s32 u_call4_0018c598(u32, u32, u32, u32) asm("_Z16u_call4_0018c598jjjj");
extern u8* D_0034e948;
extern u8 D_01c60d10[];
u8* func_001cd7a8(u8*);
s32 func_0016a090(u8*);  // get_byte74
void func_00190878(u8*, u8*, s32);
s32 func_0019f528(u8*, u32);  // test_bit_by_index
s32 func_0019f550(u8*, u32);  // test_bit_addressable
void func_0019f490(u8*, u32);
typedef void (*Fn80)(u8*, u32, u32, u8*, u32);
void func_00198ae0(u8* p, u32 a, u32 b, u32 c)
{
    u8* q = p + 1148;
    if (func_0019f528(q, b) || !func_0019f550(q, b)) {  // test_bit_by_index
        func_0019f490(p + 1140, b);
        (*(Fn80*)(*(u8**)p + 80))(p, a, b, p, c);
    }
}
extern u32 D_0034f240;
extern u8 D_0036d8b8[];
void func_001c8ba8(void);
u8* func_001050d8(s32);
u32 func_0016e920(s32);
f32 func_0016afe0(u8*);
void func_001c7fb8(u8*, u32, V4*, f32);
void func_001880b0(u8*, u8*);
void func_001373d8(void);
extern u32 D_01d48cb0;
extern u8 D_00351eb8[];
typedef s32 (*Fn64)(u8*);
void func_001b5250(u32, s32);
u8 func_001c8db8(u8*, s32);
void func_001d4180(void);
}

}
namespace w75_h4 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
void func_001bd668(u8*);
void func_001d4818(u8*, u32, u32, u32, u32);
void func_001d48e8(u8*, u32, u8*);
void func_001bd5b0(u8*, s32, s32);
void func_001bdb70(u8* p, u32 a, u32 b, u32 c, u32 d)
{
    func_001bd668(p);
    u8* q = p + 2496;
    func_001d4818(q, a, b, c, d);
    func_001d48e8(q, *(u32*)(p + 2528), p + 1660);
    func_001bd5b0(p, 14, 0);
    *(u32*)(p + 32) &= ~2;
}
extern u32 D_01d49960;
extern u32 D_01d49968;
extern u8 D_0036e068[];
u8* func_001d6d88(void);
u8* func_001050d8(s32);
u32 func_0016e920(u32);
void func_001c7fb8(u8*, u32, V4*, f32);
void func_00188120(u8*, u8*);
u8* func_001c88a8(V4* pos, f32 ang)
{
    u8* e = func_001d6d88();
    if (D_01d49960) return 0;
    D_01d49968 = 2;
    u8* o = func_001050d8(3328);
    func_001c7fb8(o, func_0016e920(*(u32*)(e + 4)), pos, ang);
    func_00188120(o + 768, D_0036e068);
    return o;
}
void func_001ddef0(u8**, u8*, u32, u32, u32, u32);
void func_001de228(u8** p, u32 k, u32 c, u32 d, u32 e, u32 f)
{
    s32 n = *(s32*)(p[0] + 8);
    for (s32 i = 0; i < n; i++) {
        u8* x = p[1] + i * 80;
        if (x[4] == k) func_001ddef0(p, x, c, d, e, f);
    }
}
union UF { u32 i; f32 f; };
static inline f32 VRand(void)
{
    f32 u;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1" : "=r"(u) : : "$8");
    return u;
}
f32 func_001ee7a8(u8 two)
{
    f32 r = VRand();
    if (two) r = (r + VRand()) * 0.5f;
    return r;
}
f32 func_001ee988(u8 two)
{
    f32 r = VRand();
    r = -r;
    if (two) r = (r - VRand()) * 0.5f;
    return r;
}
extern u8 D_0035de24, D_0035de25, D_0035de56;
extern s32 D_0035de28, D_0035dd04;
extern u32 D_0035de4c, D_0035de50, D_0035de2c;
extern u32 D_0035dd08[64];
extern V4 D_0035de70;
void func_0022d7c8(void);
void func_00225a00(void);  // zero_global_byte_e
void func_00225a20(void);
void func_0022d7e8(void);
void func_00226fc8(void)
{
    D_0035de24 = 0;
    D_0035de25 = 0;
    D_0035de28 = -1;
    func_0022d7c8();
    func_00225a00();  // zero_global_byte_e
    func_00225a20();
    D_0035de4c = 0;
    D_0035de50 = 0;
    D_0035de2c = 0;
    D_0035de56 = 0;
    D_0035dd04 = -1;
    u32* w = D_0035dd08;
    s32 i = 63;
    do {
        *w = 0;
        i--;
        // R5900 short-loop padding
        asm volatile("nop\n\tnop\n\tnop");
        w++;
    } while (i >= 0);
    func_0022d7e8();
    asm volatile("sqc2 $vf0, 0(%0)" : : "r"(&D_0035de70) : "memory");
}
extern f32 D_00349e10;
struct Seg { V4 a, b; };
void func_00144490(Seg*, f32, f32, f32, f32, f32, f32);
void func_001d6790(Seg*);
void func_001024a8(u8*);
void func_0022c840(u8* p)
{
    Seg s;
    f32 z = 0.0f;
    f32 y = *(f32*)(p + 8);
    func_00144490(&s, -18000.0f, z, y - 187.5f, 18000.0f, z, y + 187.5f);
    func_001d6790(&s);
    *(f32*)(p + 8) -= 375.0f;
    *(f32*)(p + 4) -= D_00349e10;
    if (*(f32*)(p + 4) < z) func_001024a8(p);
}
}

}
namespace w75_h5 {
extern "C" {
extern u8* D_0035ed20;
extern u8* D_0035ed24;
s32 func_002892f8(u8*);
s32 func_0028acc8(u8*);
void func_00288e88(u8*);
void func_00246708(void)
{
    if (D_0035ed20) {
        s32 a = func_002892f8(D_0035ed20);
        if (!func_0028acc8(D_0035ed20) && a) func_00288e88(D_0035ed20);
    }
    if (D_0035ed24) {
        s32 a = func_002892f8(D_0035ed24);
        if (!func_0028acc8(D_0035ed24) && a) func_00288e88(D_0035ed24);
    }
}
extern u8 D_0035f0e8;
extern u8* D_0035f0e4;
u32 func_00267248(void);  // global_ptr_by_flag32
s32 func_0028b040(u32);
s32 func_0028afa8(u32);
void func_002891f0(u32, s32, s32, s32, s32);
u32 func_00257130(void);
s32 func_002827e0(u32, s32);  // get_indexed_word
s32 func_002813b8(void);
s32 func_00281420(void);
extern u32 D_0035f0fc;
u32 func_00293bc0(void);
s32 func_001a8bf8(u32, s32);  // get_bits5_at
s32 func_0026d8c0(s32 x)
{
    s32 r = -1;
    u32 a = func_00293bc0();
    for (s32 i = 0; i < 4; i++)
        if (func_001a8bf8(D_0035f0fc, i) == func_001a8bf8(a, x)) { r = i; break; }
    return r;
}
extern u8 D_00373ab0[];
extern u8 D_00373af8[];
extern u8 D_00373ae0[];
u8* func_00273180(s32 k, s32 id)
{
    u8* r = 0;
    u8* t = 0;
    s32 n = 0;
    switch (k) {
    case 3: t = D_00373ab0; n = 6; break;
    case 2: t = D_00373af8; n = 2; break;
    case 4: t = D_00373ae0; n = 3; break;
    }
    if (id < 0) return t;
    for (s32 i = 0; i < n; i++)
        if (t[i * 8 + 5] == id) { r = t + i * 8; break; }
    return r;
}
extern u8* D_0035f5d8;
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void func_00139510(u8*);
void func_002a0860(void)
{
    if (!D_0035f5d8) return;
    if (u_call4_00139d78(D_0035f5d8)) func_00139510(D_0035f5d8);
    if (u_call4_00139d78(D_0035f5d8 + 408)) func_00139510(D_0035f5d8 + 408);
    if (u_call4_00139d78(D_0035f5d8 + 816)) func_00139510(D_0035f5d8 + 816);
    if (u_call4_00139d78(D_0035f5d8 + 1224)) func_00139510(D_0035f5d8 + 1224);
}
extern u8* D_0035f5f4;
typedef void (*VFn)(u8*);
void func_00276a18(void);
void func_00276b10(void);
extern u8* D_0035f604;
s32 func_00276a90(void);
void func_00276b90(void);
extern u8* D_0035f5f8;
extern u8 D_0035f5fc;
extern u8 D_0035f5fd;
void func_002b64d8(u8*);
u8* func_00290948(u8*, s32);
void func_002b6530(u8*);
void func_00293d80(s32);
void func_002a75c0(void)
{
    func_002b64d8(D_0035f5f8);
    u8* t = func_00290948(D_0035f5f8, 0);
    s32 c = 0;
    u8* e = t + 16;
    s32 n = *(s32*)(t + 8);
    for (s32 i = 0; i < n; i++, e += 32) {
        c++;
        if (*(s16*)(e + 6)) c++;
    }
    D_0035f5fd = c;
    D_0035f5fc = func_00290948(D_0035f5f8, 1)[8];
    func_002b6530(D_0035f5f8);
    func_00293d80(5102);
    if (D_0035f5f8) { (*(VFn*)(*(u8**)D_0035f5f8 + 4))(D_0035f5f8); D_0035f5f8 = 0; }
}
extern u32* D_0035f610;
s32 func_002a9e98(s32);
u8* func_00294000(s32);
s32 func_002aa098(s32 id)
{
    s32 r = 0;
    if (id < 0) {
        r = func_002a9e98(-1);
    } else {
        u8* t = func_00294000(3);
        s32 n = *(s32*)(t + 8);
        u8* e = t + 16;
        for (s32 i = 0; i < n; i++, e += 36) {
            if (*(s8*)e == id) {
                u32 k = *(u16*)(e + 4);
                if (D_0035f610[k >> 5] & (1 << (k & 31))) { r = 1; break; }
            }
        }
    }
    return r;
}
}

}
namespace w75_h7 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
typedef void (*VFn)(u8*);
typedef void (*FreeFn)(u8*, u8*);
extern u8 D_00347d90[];
extern u8 D_00347e60[];
extern u8 D_00347e80[];
extern u8 D_00347f98[];
extern u32 D_00347f80;
void func_00239870(u8*);
void func_002361d0(u8*);
void func_0031a840(u8*);
void func_0031a628(u8* p)
{
    *(void**)p = D_00347d90;
    *(void**)(p + 896) = D_00347e60;
    func_00239870(p + 920);
    *(void**)(p + 896) = D_00347f98;
    *(void**)(p + 448) = D_00347e80;
    func_002361d0(p + 480);
    *(void**)(p + 448) = D_00347f98;
    *(void**)p = D_00347e60;
    func_00239870(p + 24);
    func_0031a840(p);
    u8* al = *(u8**)(D_00347f80 + 20);
    (*(FreeFn*)(*(u8**)al + 4))(al, p);
}
extern u8 D_0034a660[];
void func_0031c838(u8* p)
{
    *(void**)p = D_0034a660;
    if (p != (u8*)-456) {
        u8* q = p + 2864;
        u8* a = p + 456;
    loop:
        if (a == q) goto done;
        q -= 344;
        (**(VFn**)q)(q);
        goto loop;
    }
done:
    *(void**)(p + 48) = D_00347e60;
    func_00239870(p + 72);
    *(u32*)(p + 48) = (u32)D_00347f98;
    *(u32*)p = (u32)D_00347f98;
    u8* al = *(u8**)(D_00347f80 + 20);
    (*(FreeFn*)(*(u8**)al + 4))(al, p);
}
extern u8 D_0034a568[];
void func_002d00a0(u8*);
void func_0016bd60(u8*, s32);
u32 func_002d1260(void);
void func_001c0d38(u8*, u32, s32, s32);
void func_0016b070(u8*, V4*);
void func_0016ace0(u8*, V4*);
s32 func_001c0cd8(u8*);
void func_0017f488(u8*, s32, f32, f32);
void func_00180378(u8*, u8*, s32, f32);
void func_002da958(u8* p)
{
    if (*(u8**)(p + 3060)) func_0017f488(*(u8**)(p + 3060) + 320, 173, 8.0f, 0.0f);
    u8* o = *(u8**)(p + 3056);
    if (!o) return;
    if (func_001c0cd8(o)) func_0017f488(*(u8**)(p + 3056) + 320, 173, 8.0f, 0.0f);
    func_00180378(*(u8**)(p + 3056) + 320, p, 254, 8.0f);
}
}

}
namespace wcx_retry_r1 {
extern "C" {
extern u8* D_0035f5f4;
typedef void (*VFn)(u8*);
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void func_00276a18(void);
void func_00276b10(void);
struct E436 { u8 d[436]; };
extern E436 (*D_0035f5f4b)[2] asm("D_0035f5f4");
void func_002a73d0(void)
{
    for (s32 i = 0; i < 4; i++) {
        for (s32 j = 0; j < 2; j++) {
            if (u_call4_00139d78(&D_0035f5f4b[i][j])) {
                u8* o = D_0035f5f4b[i][j].d;
                (*(VFn*)(*(u8**)o + 20))(o);
            }
        }
    }
    func_00276a18();
    func_00276b10();
}
}
extern "C" {
extern E436 (*D_0035f604b)[2] asm("D_0035f604");
s32 func_00276a90(void);
void func_00276b90(void);
s32 func_002a81a8(void)
{
    for (s32 i = 0; i < 10; i++) {
        for (s32 j = 0; j < 2; j++) {
            if (u_call4_00139d78(&D_0035f604b[i][j])) {
                u8* o = D_0035f604b[i][j].d;
                (*(VFn*)(*(u8**)o + 20))(o);
            }
        }
    }
    if (!func_00276a90()) func_00276b90();
    return 0;
}
}

}
namespace wcx_retry_f1 {
extern "C" {
typedef void (*Fn68)(u8*, s32, u32);
u8* func_00124748(u8*, s32);  // list_nth_node_rel
u32 func_00313bc0(f32);
void func_0014b220(u8*, s32, s32, s32, s32);
void func_0014b620(u8*, s32);
extern u8* D_00347f80;
typedef u8* (*AllocFn)(u8*, s32, s32);
void func_0031bcf8(u8*);
void func_001516b0(u8*, u32, u32, u32, u32, u32, f32);
struct T96 { u8 pad[80]; s32 v; u8 pad2[12]; };
void func_002ba2e8(s32, s32);
void func_001395a8(u8*);
void func_001a98e8(T96*, s32, u32, s32, s32);
s32 func_0023aa18(u8*);
void func_00139598(u8*);
void func_001544b0(u8* p)
{
    u8* q = p;
    u8* end = p + 13056;
    do {
        for (s32 j = 0; j < 2; j++) func_00139598(q + 2496 + j * 408);
        q += 816;
    } while ((s32)q < (s32)end);
    for (s32 i = 0; i < *(s32*)(p + 15568); i++)
        if (i < 16) func_001395a8(p + 2496 + i * 816);
}
}

}
namespace wcx_retry_r2 {
extern "C" {
u8* func_00294000(s32);
extern u8* D_0035f620;
s32 func_002ad7d0(s32 id)
{
    s32 r = 1;
    u8* t = func_00294000(8);
    s32 n = *(s32*)(t + 8);
    u16* e = (u16*)(t + 16);
    for (u32 i = 0; (s32)i < n; i++, e += 8) {
        if (id >= 0 && *e != id) continue;
        u32* bits = (u32*)(D_0035f620 + 148);
        if (!(bits[i >> 5] & (1 << (i & 31)))) { r = 0; break; }
    }
    return r;
}
s32 func_002ad950(s32 id)
{
    s32 r = 1;
    u8* t = func_00294000(7);
    s32 n = *(s32*)(t + 8);
    u16* e = (u16*)(t + 16);
    for (u32 i = 0; (s32)i < n; i++, e += 4) {
        if (id >= 0 && *e != id) continue;
        u32* bits = (u32*)(D_0035f620 + 136);
        if (!(bits[i >> 5] & (1 << (i & 31)))) { r = 0; break; }
    }
    return r;
}
}
extern "C" {
extern u8* D_0035f610;
s32 func_002aacd8(s32);  // test_bit_global_d
s32 func_002ab100(s32);  // test_bit_global_c
}

}
