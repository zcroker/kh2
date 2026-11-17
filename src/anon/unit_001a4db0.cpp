#include "../common/types.h"

// YS prize/attack-effect manager (0x1a4db0-0x1a5b58, vtable 0x350798): C2/C1 constructors that
// register the single instance (D_00350790), D2/D1/D0, the hit test, the prize drops and the
// static init that sets the 30-degree angle (0x1c6cb18). Each function keeps the declarations of
// the source it was matched in (namespace nADDR); every external symbol is bound by asm label.
// The vtable and the two tables after 0x36d4e8 stay retail data.

void* D_00350790 = 0;

// 001a4db0 (from anon/tiny_auto80_fptr4.cpp)
namespace n001a4db0 {
u32 func_001c6e58(u32, u32, u32, u32) asm("func_001c6e58");
extern u8 D_003507a0 asm("D_003507a0");
u32 func_001a4db0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001a4db0");
u32 func_001a4db0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r13, r14, r15, r16;
    r16 = r4;
    u32 (*fp_call4_001c6e58)(u32, u32, u32, u32) = func_001c6e58;
    r2 = fp_call4_001c6e58(r4, r5, r6, r7);
    r14 = (u32)&D_003507a0;
    r13 = (u32)(0x0035u << 16);
    *(u32*)((u32)r16 + (s32)(0)) = r14;
    r15 = *(u32*)((u32)r13 + (s32)(1936));
    if (r15 == 0u) r15 = r16;
    *(u32*)((u32)r13 + (s32)(1936)) = r15;
    return r2;
}
}  // namespace n001a4db0

// 001a4df0 (from anon/tiny_auto80_fptr4.cpp)
namespace n001a4df0 {
u32 func_001c6e58(u32, u32, u32, u32) asm("func_001c6e58");
extern u8 D_003507a0 asm("D_003507a0");
u32 func_001a4df0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001a4df0");
u32 func_001a4df0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r13, r14, r15, r16;
    r16 = r4;
    u32 (*fp_call4_001c6e58)(u32, u32, u32, u32) = func_001c6e58;
    r2 = fp_call4_001c6e58(r4, r5, r6, r7);
    r14 = (u32)&D_003507a0;
    r13 = (u32)(0x0035u << 16);
    *(u32*)((u32)r16 + (s32)(0)) = r14;
    r15 = *(u32*)((u32)r13 + (s32)(1936));
    if (r15 == 0u) r15 = r16;
    *(u32*)((u32)r13 + (s32)(1936)) = r15;
    return r2;
}
}  // namespace n001a4df0

// 001a4e30 (from anon/batch_w57.cpp)
namespace n001a4e30 {
void func_001d5718(void*) asm("func_001d5718");
void func_0031e7f8(void*) asm("func_0031e7f8");
void func_0016a358(void*) asm("_Z16u_call4_0016a358jjjj");
extern u8 D_003507a0 asm("D_003507a0");
extern u8 D_003503e0 asm("D_003503e0");
extern union DU { void* p; u8 c; } D_00350790 asm("D_00350790");
void func_00105110(void*) asm("_ZN4AREA4FreeEPv");
struct Base4 { void* vt; ~Base4() { func_0016a358(this); } };
struct M2492 { u8 d[32]; ~M2492() { func_0031e7f8(this); } };
struct E12 { u8 d[12]; ~E12() { func_001d5718(this); } };
struct C4 : Base4 {
    u8 p[2492 - 4]; M2492 m; E12 arr[2];
    ~C4() {
        vt = &D_003507a0;
        if (D_00350790.p == this) D_00350790.p = 0;
        vt = &D_003503e0;
    }
    static void operator delete(void* p) { func_00105110(p); }
};
void u_call4_001a4e30(u32 a, u32, u32, u32) asm("_Z16u_call4_001a4e30jjjj");
void u_call4_001a4e30(u32 a, u32, u32, u32) { ((C4*)a)->~C4(); }
void func_001a4ec8(C4* p) asm("func_001a4ec8");
void func_001a4ec8(C4* p) { p->~C4(); }
void func_001a4f60(C4* p) asm("func_001a4f60");
void func_001a4f60(C4* p) {
    p->~C4();
    C4::operator delete(p);
}
}  // namespace n001a4e30

// Two literals that no code loads (an earlier copy of the 0x1a4ff8 defaults).
extern const f32 D_0036d4a8 asm("D_0036d4a8") = 120.0f;
extern const f32 D_0036d4ac asm("D_0036d4ac") = 30.0f;

// 001a4ff8 (from anon/batch_w96.cpp)
namespace n001a4ff8 {
struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
Q16* func_0016c028(u8*) asm("func_0016c028");
struct Vq_w96 {
    f32 x, y, z, w;
    Vq_w96& operator=(const Vq_w96& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline Vq_w96 vsubn_w96(const Vq_w96& a, const Vq_w96& b) {
    Vq_w96 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 vlen_w96(const Vq_w96& a) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(&a) : "$8", "memory");
    return r;
}
u8* func_00177860(void) asm("_ZN2YS5PARTY11get_abilityEv");
f32 fabsf(f32) asm("fabsf");
s32 func_001a4ff8(u8* o, Vq_w96* p, f32 r, f32 h) asm("func_001a4ff8");
s32 func_001a4ff8(u8* o, Vq_w96* p, f32 r, f32 h) {
    Vq_w96 d;
    if (*(u32*)(o + 2040) & 4) return 0;
    if (*(u32*)(*(u8**)(o + 12) + 8) & 0x40000) return 1;
    if (r <= 0.0f) {
        r = 120.0f;
        if (*(u32*)(o + 1416) & 4) r = *(f32*)(func_00177860() + 52) + r;
    }
    if (*(u8**)(o + 1164)) r = r + *(f32*)(*(u8**)(o + 1164) + 452);
    if (h <= 0.0f) h = 30.0f;
    d = vsubn_w96(*p, *(Vq_w96*)func_0016c028(o));  // obj_get_attach_or_alt
    if (h < fabsf(d.y)) return 0;
    d.y = 0.0f;
    if (vlen_w96(d) <= r) return 1;
    return 0;
}
}  // namespace n001a4ff8

// 001a5140 (from anon/batch_wcx2.cpp)
namespace n001a5140 {
extern u8* D_0034e948 asm("D_0034e948");
s32 func_0019ba60(u8*) asm("_Z16ctarget_0019ba60jjjj");
u8* func_00176b20(s32) asm("_ZN2YS5PARTY3GetEi");
s32 func_0019ba60(u8*) asm("_Z16ctarget_0019ba60jjjj");
s32 func_0019ba60(u8*) asm("_Z16ctarget_0019ba60jjjj");
s32 func_0019ba60(u8*) asm("_Z16ctarget_0019ba60jjjj");
struct Act40 { u8 pad[20]; u8 kind; u8 pad2[19]; u32 fl; u8 pad3[24]; u8 lv; };
extern u8* D_0034e948 asm("D_0034e948");
s32 func_001919f8(void) asm("func_001919f8");
s32 func_001919d0(void) asm("func_001919d0");
void func_001a5380(u8*, u8*, Act40*) asm("func_001a5380");
u8* func_00176b20(s32) asm("_ZN2YS5PARTY3GetEi");
s32 func_0019ba60(u8*) asm("_Z16ctarget_0019ba60jjjj");
s32 func_001c7950(Act40*, u8*, f32, f32) asm("func_001c7950");
static inline bool Is40(u8* e) { return *(s32*)(e + 2896) == 6; }
struct Vec4x { f32 a,b,c,d; } __attribute__((aligned(16)));
struct NoTail40 { Vec4x v; ~NoTail40() {} };
void func_001a5140(u8* o, Act40* a) asm("func_001a5140");
void func_001a5140(u8* o, Act40* a)
{
    NoTail40 nt;
    if (func_001919f8()) a->fl |= 8;
    if (func_001919d0()) {
        func_001a5380(o, D_0034e948, a);
        return;
    }
    if ((a->fl & 8) && a->lv >= 3) func_001a5380(o, D_0034e948, a);
    for (s32 i = 0; i < 3; i++) {
        u8* e = func_00176b20(i);
        if (!func_0019ba60(e)) continue;
        if (*(u32*)(e + 2040) & 4) continue;
        if (*(u32*)(e + 1416) & 0x80) {
            if (Is40(e) && a->kind < 2) continue;
        } else {
            if ((u32)(a->kind - 7) < 2) continue;
        }
        if (func_001c7950(a, e, 0.0f, 0.0f)) {  // copy_quad_if_flag
            func_001a5380(o, e, a);
            return;
        }
    }
}
}  // namespace n001a5140

// 001a52a8 (from anon/batch_w79.cpp)
namespace n001a52a8 {
struct E1a5 { f32 f; u8 b4, b5, b6, b7; };
typedef s32 (*VF4)(void*, u8, s32, s32);
extern struct E1a5 D_0036d578[] asm("D_0036d578");
void func_00176be0(void*, f32) asm("func_00176be0");
void func_00187650(void*, u8, s32) asm("_Z16ctarget_00187650jjjj");
void func_00179a68(void*, f32) asm("func_00179a68");
void func_001d6110(u8, void*) asm("_ZN2YS10FORM_LEVEL11CheckMasterEiPNS_6PLAYERE");
void func_0014f668(u8) asm("func_0014f668");
void func_00242500(u8) asm("_ZN2Tz5Munny3AddEj");
void func_001a52a8(void* a0, void** o, u8* c) asm("func_001a52a8");
void func_001a52a8(void* a0, void** o, u8* c) {
    struct E1a5* e = &D_0036d578[c[20]];
    if (e->f > 0.0f) func_00176be0(o, e->f);
    if (e->b4) (*(VF4*)((u8*)*o + 120))(o, e->b4, 0, 0);
    if (e->b5) func_00187650(o, e->b5, 0);
    if (e->b6) {
        func_00179a68(o, e->b6);
        func_001d6110(e->b6, o);
    }
    if (e->b7) {
        func_0014f668(e->b7);
        func_00242500(e->b7);
    }
}
}  // namespace n001a52a8

// 001a5380 (from anon/batch_w54.cpp)
namespace n001a5380 {
extern void (*D_0032ba34)(void);
void func_001c79a0(void*, void*, s32) asm("func_001c79a0");
void func_001a52a8(void*, void*, void*) asm("func_001a52a8");
void func_001a5380(void* a0, void* a1, void* a2) asm("func_001a5380");
void func_001a5380(void* a0, void* a1, void* a2) {
    func_001c79a0(a2, a1, 0);
    func_001a52a8(a0, a1, a2);
}
}  // namespace n001a5380

// 001a53d0 (from anon/batch_w55.cpp)
namespace n001a53d0 {
void func_001c79a0(u32, u32, s32) asm("func_001c79a0");
void func_001a52a8(u32, u32, u32) asm("func_001a52a8");
void func_001a53d0(u32 a, u32 b, u32 c) asm("func_001a53d0");
void func_001a53d0(u32 a, u32 b, u32 c) {
    func_001c79a0(c, b, 1);
    func_001a52a8(a, b, c);
}
}  // namespace n001a53d0

// 001a5420 (from anon/batch_w3678.cpp)
namespace n001a5420 {
extern u32 D_003638d0 asm("D_003638d0");
u8* func_001c6f10(u32, u32, u32, void*) asm("func_001c6f10");
void func_001c7420(void) asm("func_001c7420");
struct V4 { f32 x, y, z, w; };
static inline f32 frnd() { D_003638d0 = D_003638d0 * 0x10dcd; return (f32)D_003638d0 * 2.3283064e-10f; }
static inline f32 add8(f32 lo, f32 r) { return lo + r; }
u8* func_001a5420(u32 a, u32 b, u32 c) asm("func_001a5420");
u8* func_001a5420(u32 a, u32 b, u32 c) {
    u8* v = func_001c6f10(a, b, c, (void*)func_001c7420);
    if (v != 0) {
        V4* p = (V4*)(v + 0x30);
        f32 x = add8(-20.0f, frnd() * 40.0f);
        f32 y = add8(-40.0f, frnd() * 20.0f);
        f32 z = add8(-20.0f, frnd() * 40.0f);
        p->y = y; p->x = x; *(s32*)&p->w = 0; p->z = z;
    }
    return v;
}
}  // namespace n001a5420

// 001a55a8 (from anon/batch_w1687.cpp)
namespace n001a55a8 {
struct W1687Party { u8 pad[0x48c]; s32 active; };
struct W1687Ability { u8 pad[0x68]; f32 luck; u8 pad2[4]; f32 prizeRate; };
struct W1687PrizeDrop { u16 item; u16 rate; };
struct W1687PrizeTable { u8 pad[0xc]; W1687PrizeDrop drop[3]; };
W1687Party* party_Get(s32) asm("_ZN2YS5PARTY3GetEi");
W1687Ability* party_get_ability(W1687Party*) asm("_ZN2YS5PARTY11get_abilityEv");
s32 ctarget_0019ba60(W1687Party*) asm("_Z16ctarget_0019ba60jjjj");
W1687PrizeTable* prizetable_Get(s32) asm("_ZN2YS10PRIZETABLE3GetEi");
s32 status_GetPrizeRatio(W1687PrizeTable*, s32, f32) asm("_ZN2YS6STATUS13GetPrizeRatioEv");
f32 func_00191b70(void) asm("_ZNK2YS10PRIZETABLE7get_numEif");
s32 func_001d0820(void) asm("func_001d0820");
s32 func_001a5af0(s32) asm("func_001a5af0");
void func_001a5880(u32, s32, s32) asm("func_001a5880");
void func_001bf620(u32, u32) asm("func_001bf620");
void func_001c7ca8(u32, W1687PrizeTable*) asm("func_001c7ca8");
void func_001ca758(u32, W1687PrizeTable*) asm("func_001ca758");
void func_001d7538(u32, W1687PrizeTable*) asm("func_001d7538");
extern s32 D_00350790 asm("D_00350790");
extern u32 D_0034f240 asm("D_0034f240");
extern u32 D_003638d0 asm("D_003638d0");
static inline f32 party_prize_rate() {
    f32 r = 1.0f;
    for (s32 i = 0; i < 3; i++) {
        W1687Party* p = party_Get(i);
        if (ctarget_0019ba60(p) && p->active)
            r *= party_get_ability(p)->prizeRate;
    }
    return r;
}
static inline f32 party_luck() {
    f32 r = 1.0f;
    for (s32 i = 0; i < 3; i++) {
        W1687Party* p = party_Get(i);
        if (ctarget_0019ba60(p) && p->active)
            r += party_get_ability(p)->luck;
    }
    return r;
}
static inline f32 frand(f32 max) {
    D_003638d0 = D_003638d0 * 0x10dcd;
    return (f32)D_003638d0 * 2.3283064e-10f * max;
}
static inline void drop_items(u32 obj, W1687PrizeTable* t, f32 luck) {
    for (s32 i = 0; i < 3; i++) {
        f32 th = t->drop[i].rate * luck;
        if (frand(100.0f) < th)
            func_001bf620(t->drop[i].item, obj);
    }
}
struct W1687NoTail { ~W1687NoTail() {} } __attribute__((aligned(16)));
void func_001a55a8(u32 obj, s32 id) asm("func_001a55a8");
void func_001a55a8(u32 obj, s32 id)
{
    W1687NoTail nt;
    W1687PrizeTable* t;
    f32 k = func_00191b70();
    s32 flag = func_001d0820();
    if (D_00350790) {
        t = prizetable_Get(id);
        if (!(D_0034f240 & 0x200) || flag) {
            f32 r = party_prize_rate();
            for (s32 i = 0; i < 9; i++) {
                s32 kind = i;
                if (flag) kind = func_001a5af0(i);
                s32 n = status_GetPrizeRatio(t, i, k);
                if ((u32)(kind - 2) < 3) {
                    s32 m = n - (s32)(n * r);
                    n -= m;
                    func_001a5880(obj, func_001a5af0(kind), m);
                }
                func_001a5880(obj, kind, n);
            }
            if (!(D_0034f240 & 0x400) && !flag) {
                f32 luck = party_luck();
                drop_items(obj, t, luck);
            }
        }
        if (!flag) {
            func_001c7ca8(obj, t);
            func_001ca758(obj, t);
            func_001d7538(obj, t);
        }
    }
}
}  // namespace n001a55a8

// 001a5880 (from anon/batch_w36.cpp)
namespace n001a5880 {
extern u32 D_00350790 asm("D_00350790");
extern u8 D_0036d4e8[] asm("D_0036d4e8");
void func_001a5420(u32, u8*, u32) asm("func_001a5420");
void func_001a5880(u32 a, s32 k, s32 n) asm("func_001a5880");
void func_001a5880(u32 a, s32 k, s32 n) {
    s32 i;
    for (i = 0; i < n; i++) func_001a5420(D_00350790, D_0036d4e8 + k * 16, a);
}
}  // namespace n001a5880

// 001a58f8 (from anon/tiny_auto80_queue.cpp)
namespace n001a58f8 {
extern u32 func_001c1708(...) asm("func_001c1708");
extern u32 func_001c7ee0(...) asm("func_001c7ee0");
u32 func_001a58f8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_001a58f8");
u32 func_001a58f8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r15 = (u32)(0x0035u << 16);
    r15 = ((u32*)(u32)r15)[484];
    if (r15 != 0u) {
        r4 = ((u32*)(u32)r15)[637];
        r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_001c1708)(r4, r5, r6, r7, r8, r9, r10, r11);
    }
    return ((u32(*)())func_001c7ee0)();
}
}  // namespace n001a58f8

// 001a5928 (from anon/batch_w1578_g.cpp)
namespace n001a5928 {
void* W1578_AREA_Alloc(u32) asm("_ZN4AREA5AllocEj");
void func_001c70e8(void) asm("func_001c70e8");
void* W1578_JmInfo_GetCharaData(u32) asm("_ZN2Tz6JmInfo12GetCharaDataEj");
void func_001a4df0(void*, void*, s32, s32) asm("func_001a4df0");
void func_001a5928(void) asm("func_001a5928");
void func_001a5928(void) {
    func_001c70e8();
    void* p = W1578_AREA_Alloc(0xa00);
    func_001a4df0(p, W1578_JmInfo_GetCharaData(0x5c3), 0x100, 0x60);
}
}  // namespace n001a5928

// 001a5970 (from anon/tiny_wrappers_more.cpp)
namespace n001a5970 {
u32 func_0016ed50(u32, u32, u32, u32) asm("_Z16wtarget_0016ed50jjjj");
u32 func_001a5970(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001a5970");
u32 func_001a5970(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0016ed50(0x000005c3u, 0x000003fcu, 0x0000001eu, a3);
}
}  // namespace n001a5970

// 001a5990 (from anon/auto80_199_queue.cpp)
namespace n001a5990 {
extern u32 D_0034e948 asm("D_0034e948");
u32 func_0019ba60(...) asm("func_0019ba60");
u32 func_001c7950(...) asm("func_001c7950");
u32 func_001c79a0(...) asm("func_001c79a0");
void func_001d8d08(u32 a0, f32 a1) asm("func_001d8d08");
void func_001a5990(u32 a0, u32 a1, f32 a2) asm("func_001a5990");
void func_001a5990(u32 a0, u32 a1, f32 a2) {
    u32 s0 = D_0034e948;
    if (func_0019ba60(s0) == 0) {
        return;
    }
    if ((*(u32*)(a0 + 40) & 1) == 0) {
        return;
    }
    if (((u32(*)(u32, u32, f32, f32))func_001c7950)(a0, s0, 0.0f, 0.0f) == 0) {
        return;
    }
    func_001c79a0(a0, s0, 0);
    func_001d8d08(a1, a2);
}
}  // namespace n001a5990

// 001a5a48 (from anon/batch_w50.cpp)
namespace n001a5a48 {
void ctarget0_001a5a48(void) asm("_Z17ctarget0_001a5a48v");
struct Ent { u8 pad[40]; u32 on : 1; };
Ent* func_001c16f0(void*, Ent*) asm("_ZN2YS10MASSEFFECT7MANAGER4eachEPS0_");
void func_001a53d0(void*, u32, Ent*) asm("func_001a53d0");
extern u8* D_00350790 asm("D_00350790");
extern u32 D_0034e948 asm("D_0034e948");
void ctarget0_001a5a48(void) asm("_Z17ctarget0_001a5a48v");
void ctarget0_001a5a48(void) {
    Ent* p = 0;
    Ent* q;
    while ((q = func_001c16f0(*(void**)(D_00350790 + 2548), p)) != 0) {
        p = q;
        if (!q->on) continue;
        u32 k = D_0034e948;
        func_001a53d0(D_00350790, k, q);
    }
}
}  // namespace n001a5a48

// 001a5ac8 (from anon/tiny_auto80_queue.cpp)
namespace n001a5ac8 {
extern u32 D_00350790 asm("D_00350790");
u32 func_001a5ac8(void) asm("_ZN2YS5PRIZE12GetAppearNumEv");
u32 func_001a5ac8(void) {
    u32 p = D_00350790;
    if (p != 0u) {
        return *(u32*)(*(u32*)(p + 0x9F4) + 0x34);
    }
    return 0;
}
}  // namespace n001a5ac8

// Item kind of each prize kind, read by 0x1a5af0.
extern const u8 D_0036d4d8_tbl[9] asm("D_0036d4d8") = { 7, 8, 8, 8, 7, 7, 8, 7, 8 };

// 001a5af0 (from anon/tiny_more2.cpp)
namespace n001a5af0 {
extern u32 D_0036d4d8 asm("D_0036d4d8");
u32 func_001a5af0(u32 a0,u32 a1,u32 a2,u32 a3) asm("func_001a5af0");
u32 func_001a5af0(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; return *(u8*)((u32)&D_0036d4d8 + (u32)a0 + (0)); }
}  // namespace n001a5af0

// 001a5b08 (from anon/batch_wlit.cpp)
namespace n001a5b08 {
extern f32 D_01c6cb18 asm("D_01c6cb18");
void wtarget_001a5b08(u32 a, u32 b, u32, u32) asm("_Z16wtarget_001a5b08jjjj");
void wtarget_001a5b08(u32 a, u32 b, u32, u32) { if (b == 0xffff && a == 1) D_01c6cb18 = 0.52359873f; }
}  // namespace n001a5b08

// 001a5b38 (from anon/tiny_wrappers_more.cpp)
namespace n001a5b38 {
u32 func_001a5b08(u32, u32, u32, u32) asm("_Z16wtarget_001a5b08jjjj");
u32 func_001a5b38(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001a5b38");
u32 func_001a5b38(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001a5b08(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n001a5b38

