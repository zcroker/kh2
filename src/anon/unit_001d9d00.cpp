// Linked unit 0x001d9d00-0x001dbbe0.
#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "tiny_auto80_solver_structs.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// 001d9d00 (was src/anon/batch_w6.cpp)
namespace n001d9d00 {
// 0x001d9820: definition moved into src/anon/unit_001d7458.cpp

u32 func_001b1448(u32) asm("func_001b1448");
extern u32 D_003528fc asm("D_003528fc");
extern u32 D_01d5baa8 asm("D_01d5baa8");
/*TARGET 001d9d00*/
void func_001d9d00(void) asm("func_001d9d00");
void func_001d9d00(void) {
    D_01d5baa8 = func_001b1448(D_003528fc);
}
}  // namespace n001d9d00

// 001d9d28 (was src/anon/tiny_wrappers_more.cpp)
namespace n001d9d28 {
u32 YS_JIGSAW_Get(u32, u32, u32, u32) asm("_ZN2YS6JIGSAW3GetEii");
/*TARGET 001d9d28*/
// 0x001d9ce0: definition moved into src/anon/unit_001d7458.cpp

u32 func_001d9d28(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001d9d28jjjj");
// 0x001d9ce0: definition moved into src/anon/unit_001d7458.cpp

u32 func_001d9d28(u32 a0, u32 a1, u32 a2, u32 a3) {
    return YS_JIGSAW_Get(((u32)(*(u8*)((u32)(a0) + 0u))), ((u32)(*(u8*)((u32)(a0) + 1u))), a2, a3);
}
}  // namespace n001d9d28

// 001d9d48 (was src/anon/batch_w1735.cpp)
namespace n001d9d48 {
// Per-id bit sets: 64 bits per id.
struct BitRow { u32 w[2]; };
struct BitKey { u8 id; u8 bit; };
static inline bool BitTest(u32* bits, u32 n) { return (bits[n >> 5] & (1 << (n & 31))) != 0; }
extern BitRow D_0032dfd0[] asm("D_0032dfd0");
/*TARGET 001d9d48*/
// 0x0019bad8: definition moved into src/anon/unit_0019ba60.cpp

s32 func_001d9d48(BitKey* k) asm("func_001d9d48");
// 0x0019bad8: definition moved into src/anon/unit_0019ba60.cpp

s32 func_001d9d48(BitKey* k) {
    return BitTest(D_0032dfd0[k->id].w, k->bit);
}
}  // namespace n001d9d48

// 001d9d88 (was src/anon/tiny_auto80_queue.cpp)
namespace n001d9d88 {
u32 func_00181500(...) asm("func_00181500");
/*TARGET 001d9d88*/
u32 func_001d9d88(u8* a0) asm("_Z13func_001d9d88Ph");
u32 func_001d9d88(u8* a0) {
    u32 s0 = 0;
    u32 v0;
    u32 t15 = *(u16*)(a0 + 8);
    if (t15 == 0) {
        goto set1;
    }
    if (func_00181500(t15) == 0) {
        goto end;
    }
set1:
    s0 = 1;
end:
    v0 = s0;
    return v0;
}
}  // namespace n001d9d88

// 001d9dd0 (was src/anon/batch_w1759.cpp)
namespace n001d9dd0 {
struct W1759Entry { u8 pad[4]; u8 a, b, c; u8 pad2[3]; };
struct W1759Table { u32 x0; s32 n; W1759Entry e[1]; };
extern W1759Table* D_01d5baa8 asm("D_01d5baa8");
/*TARGET 001d9dd0*/
W1759Entry* func_001d9dd0(s32 a, s32 b, s32 c) asm("func_001d9dd0");
W1759Entry* func_001d9dd0(s32 a, s32 b, s32 c) {
    s32 i = 0;
    W1759Entry* e = D_01d5baa8->e;
    while (i < D_01d5baa8->n) {
        if (e->a == a && e->b == b && e->c == c) return e;
        i++;
        e++;
    }
    return 0;
}
}  // namespace n001d9dd0

// 001d9e30 (was src/anon/batch_w31.cpp)
namespace n001d9e30 {
extern u8* D_01d5baa8 asm("D_01d5baa8");
/*TARGET 001d9e30*/
// 0x001ca448: definition moved into src/anon/unit_001ca148.cpp

// Next 10-byte entry after e (or the first when e is null); null past the end.
u8* func_001d9e30(u8* e) asm("func_001d9e30");
// 0x001ca448: definition moved into src/anon/unit_001ca148.cpp

// Next 10-byte entry after e (or the first when e is null); null past the end.
u8* func_001d9e30(u8* e) {  // record_range_check_or_first
    if (e == 0) return D_01d5baa8 + 8;
    e += 10;
    u8* t = D_01d5baa8;
    return e < t + *(s32*)(t + 4) * 10 + 8 ? e : 0;
}
}  // namespace n001d9e30

// 001d9e78 (was src/anon/tiny_auto80_solver.cpp)
namespace n001d9e78 {
// set bit n of the 64-bit row for id
struct Row9e78 { u32 w[2]; };
extern Row9e78 D_0032dfd0[] asm("D_0032dfd0");
void func_001d9e78(u32 id, u32 n) asm("_Z13func_001d9e78jjjjjjjj");
void func_001d9e78(u32 id, u32 n) {
    u32* b = D_0032dfd0[id].w; u32* q = &b[n >> 5]; *q = *q | (1 << (n & 31));
}
}  // namespace n001d9e78

// 001d9eb0 (was src/anon/batch_w18.cpp)
namespace n001d9eb0 {
// 0x001d7a50: definition moved into src/anon/unit_001d7458.cpp

extern u32 D_00352908 asm("D_00352908");
void func_001980d0(void*, u32, u32, u32) asm("func_001980d0");
/*TARGET 001d9eb0*/
void func_001d9eb0(u8* p, u32 a, u32 b) asm("func_001d9eb0");
void func_001d9eb0(u8* p, u32 a, u32 b) {
    func_001980d0(p, a, 10, b);
    *(u32*)(p + 2552) = 0;
    *(u32*)(p + 2548) = 0;
    *(void**)p = &D_00352908;
}
}  // namespace n001d9eb0

// 001d9ef0 (was src/anon/batch_w19.cpp)
namespace n001d9ef0 {
// entry_array_find_nth
void func_001980d0(void*, u32, s32, u32) asm("func_001980d0");
extern u8 D_00352908[] asm("D_00352908");
/*TARGET 001d9ef0*/
// 0x001d5030: definition moved into src/anon/unit_001d4f40.cpp

void func_001d9ef0(u8* p, u32 a, u32 b) asm("func_001d9ef0");
// 0x001d5030: definition moved into src/anon/unit_001d4f40.cpp

void func_001d9ef0(u8* p, u32 a, u32 b) {
    func_001980d0(p, a, 10, b);
    *(u32*)(p + 0x9f8) = 0;
    *(u32*)(p + 0x9f4) = 0;
    *(void**)p = D_00352908;
}
}  // namespace n001d9ef0

// 001d9f30 (was src/anon/batch_wcx.cpp)
namespace n001d9f30 {
extern u8 D_0032bae0[] asm("D_0032bae0");
void func_00198450(u8*) asm("func_00198450");
u32 func_0016c008(u8*, s32) asm("func_0016c008");
u32 func_001d9dd0(u8, u8, u32) asm("func_001d9dd0");
s32 func_001d9d48(u32) asm("func_001d9d48");
u32 func_0016ac38(u8*, s32, s32, s32, s32) asm("func_0016ac38");
typedef void (*VFn)(u8*);
/*TARGET 001d9f30*/
void func_001d9f30(u8* p) asm("func_001d9f30");
void func_001d9f30(u8* p)
{
    u8* k = D_0032bae0;
    func_00198450(p);
    u32 r = func_001d9dd0(k[0], k[1], func_0016c008(p, 1));
    *(u32*)(p + 2552) = r;
    if (!r || !func_001d9d48(r)) *(u32*)(p + 2548) = func_0016ac38(p, 0, 1, 0, 0);
    else (*(VFn*)(*(u8**)p + 32))(p);
}
}  // namespace n001d9f30

// 001d9fd8 (was gap)
namespace n001d9fd8 {
typedef void (*VFn9fd8)(u8*);
s32 func_001da070(void*) asm("func_001da070");
u32 func_001d9d28_fd8(u32) asm("_Z13func_001d9d28jjjj");
u32 u_tail4_00192048(u32) asm("_Z16u_tail4_00192048jjjj");
void func_00138210(u32) asm("func_00138210");
void fadeout_kill_9fd8(u32, f32) asm("_ZN3ryj6EFFECT12fadeout_killEf");
u32 func_0016ac38(void*, s32, s32, s32, s32) asm("func_0016ac38");
void gap_001d9fd8(u8* p) asm("gap_001d9fd8");
void gap_001d9fd8(u8* p) {
    if (!func_001da070(p)) return;
    u32 t = *(u32*)(p + 2552);
    if (t) {
        func_001d9d28_fd8(t);
        func_00138210(u_tail4_00192048(*(u16*)(*(u32*)(p + 2552) + 2)));
    }
    fadeout_kill_9fd8(*(u32*)(p + 2548), 8.0f);
    *(u32*)(p + 2548) = 0;
    func_0016ac38(p, 1, 1, 0, 0);
    (*(VFn9fd8*)(*(u8**)p + 32))(p);
}
}  // namespace n001d9fd8

// 001da070 (was src/anon/batch_w86.cpp)
namespace n001da070 {
struct QWord { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline QWord Sub(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 Length(const QWord& v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(&v) : "$8", "memory");
    return r;
}
extern void* D_0034e948 asm("D_0034e948");
s32 func_0019ba60(void*) asm("func_0019ba60");
QWord* func_0016c028(void*) asm("func_0016c028");
// obj_get_attach_or_alt
f32 fabsf(f32) asm("fabsf");
/*TARGET 001da070*/
// fabsf
s32 func_001da070(void* o) asm("func_001da070");
// fabsf
s32 func_001da070(void* o)
{
    void* p = D_0034e948;
    if (!func_0019ba60(p)) return 0;
    QWord* a = func_0016c028(p);  // obj_get_attach_or_alt
    QWord d = Sub(*a, *func_0016c028(o));  // obj_get_attach_or_alt
    d.y += -50.0f;
    if (fabsf(d.y) > 90.0f) return 0;
    *(u32*)&d.y = 0;
    return Length(d) <= 80.0f;
}
}  // namespace n001da070

// 001da158 (was src/anon/tiny_auto80_queue.cpp)
namespace n001da158 {
u32 func_0016b5b8(...) asm("func_0016b5b8");
u32 func_001dc920(...) asm("func_001dc920");
/*TARGET 001da158*/
u32 func_001da158(u32 a0) asm("_Z13func_001da158j");
u32 func_001da158(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r16 = r4;
    r15 = *(volatile u32*)((u32)r4 + (s32)(2548));
    r4 = r15;
    if (r15 != 0u) {
        r2 = ((u32(*)(u32))func_001dc920)(r4);
        *(volatile u32*)((u32)r16 + (s32)(2548)) = 0u;
    }
    r4 = r16;
    return ((u32(*)(u32))func_0016b5b8)(r4);
}
}  // namespace n001da158

// 001da198 (was gap)
namespace n001da198 {
void func_001a4db0(void*, u32, s32, s32) asm("func_001a4db0");
extern void* D_00352960 asm("D_00352960");
extern u8 D_00352970[] asm("D_00352970");
void gap_001da198(void* p, u32 a1) asm("gap_001da198");
void gap_001da198(void* p, u32 a1) {
    func_001a4db0(p, a1, 256, 96);
    *(u32*)p = (u32)D_00352970;
    D_00352960 = p;
}
}  // namespace n001da198

// 001da1d8 (was src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n001da1d8 {
u32 func_001a4db0(u32, u32, u32, u32) asm("_Z13func_001a4db0jjjj");
extern u8 D_00352970 asm("D_00352970");
/*TARGET 001da1d8*/
// 0x001d7458: definition moved into src/anon/unit_001d7458.cpp

u32 func_001da1d8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001da1d8jjjj");
// 0x001d7458: definition moved into src/anon/unit_001d7458.cpp

u32 func_001da1d8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    r6 = (u32)((s32)0u + (256));
    r7 = (u32)((s32)0u + (96));
    r16 = r4;
    r2 = func_001a4db0(r4, r5, r6, r7);
    r15 = (u32)&D_00352970;
    r14 = (u32)(0x0035u << 16);
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    *(u32*)((u32)r14 + (s32)(10592)) = r16;
    return r2;
}
}  // namespace n001da1d8

// 001da218 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n001da218 {
u32 func_001a4e30(u32, u32, u32, u32) asm("_Z13func_001a4e30jjjj");
extern u8 D_00352970 asm("D_00352970");
/*TARGET 001da218*/
// 0x001d9028: definition moved into src/anon/unit_001d7458.cpp

u32 func_001da218(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001da218jjjj");
// 0x001d9028: definition moved into src/anon/unit_001d7458.cpp

u32 func_001da218(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r13, r14;
    r14 = (u32)&D_00352970;
    *(u32*)((u32)r4 + (s32)(0)) = r14;
    r13 = (u32)(0x0035u << 16);
    *(u32*)((u32)r13 + (s32)(10592)) = 0u;
    u32 (*fp_call4_001a4e30)(u32, u32, u32, u32) = func_001a4e30;
    r2 = fp_call4_001a4e30(r4, r5, r6, r7);
    return r2;
}
}  // namespace n001da218

// 001da248 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n001da248 {
u32 func_001a4e30(u32, u32, u32, u32) asm("_Z13func_001a4e30jjjj");
extern u8 D_00352970 asm("D_00352970");
/*TARGET 001da248*/
u32 func_001da248(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001da248jjjj");
u32 func_001da248(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r13, r14;
    r14 = (u32)&D_00352970;
    *(u32*)((u32)r4 + (s32)(0)) = r14;
    r13 = (u32)(0x0035u << 16);
    *(u32*)((u32)r13 + (s32)(10592)) = 0u;
    u32 (*fp_call4_001a4e30)(u32, u32, u32, u32) = func_001a4e30;
    r2 = fp_call4_001a4e30(r4, r5, r6, r7);
    return r2;
}
}  // namespace n001da248

// 001da278 (was src/anon/batch_w11.cpp)
namespace n001da278 {
void func_00105110(void*) asm("func_00105110");
// 0x001d97f0: definition moved into src/anon/unit_001d7458.cpp

extern u32 D_00352970 asm("D_00352970");
extern void* D_00352960 asm("D_00352960");
void func_001a4e30(void*) asm("func_001a4e30");
/*TARGET 001da278*/
void func_001da278(void** p) asm("func_001da278");
void func_001da278(void** p) {
    *p = &D_00352970;
    D_00352960 = 0;
    func_001a4e30(p);
    func_00105110(p);
}
}  // namespace n001da278

// 001da2b8 (was src/anon/batch_w1672.cpp)
namespace n001da2b8 {
// 0x001d1380: definition moved into src/anon/unit_001d12e8.cpp

extern u32 D_00352960 asm("D_00352960");
extern u8 D_0036e680 asm("D_0036e680");
u8* func_001a5420(u32, u8*, u32) asm("func_001a5420");
/*TARGET 001da2b8*/
void func_001da2b8(u32 a, s32 n) asm("func_001da2b8");
void func_001da2b8(u32 a, s32 n) {
    if (D_00352960 != 0) {
        for (s32 i = 0; i < n; i++) {
            *(f32*)(func_001a5420(D_00352960, &D_0036e680, a) + 0x40) = 120.0f;
        }
    }
}
}  // namespace n001da2b8

// .rodata 0x36e67c-0x36e690 in place (pad word + the table 0x1da2b8 reads)
extern const u32 R_0036e67c[1] asm("D_0036e67c") __attribute__((aligned(4))) = { 0x0 };
extern const u32 R_0036e680[4] asm("D_0036e680") __attribute__((aligned(4))) = { 0x0, 0x41b66666, 0x29, 0x2a };

// 001da340 (was src/anon/auto80_199_queue.cpp)
namespace n001da340 {
/*TARGET 001da340*/
// 0x001d9768: definition moved into src/anon/unit_001d7458.cpp

void func_001da340(u32 a0, u32 a1) asm("_Z13func_001da340jj");
// 0x001d9768: definition moved into src/anon/unit_001d7458.cpp

void func_001da340(u32 a0, u32 a1) {
    (void)a0;
    u32 s17 = a1;
    u32 s16 = D_0034e948;

    if (func_0019ba60(s16) != 0) {
        u32 t7 = *(u32*)(s17 + 40);
        t7 = t7 & 1u;
        if (t7 != 0) {
            if (((u32(*)(u32, u32, f32, f32))func_001c7950)(s17, s16, 0.0f, 0.0f) != 0) {
                func_001c79a0(s17, s16, 0);
                func_001d86a0(1, 0);
                return;
            }
        }
    }
}
}  // namespace n001da340

// 001da3d8 (was src/anon/batch_w3.cpp)
namespace n001da3d8 {
// 0x001d4528: definition moved into src/anon/unit_001d3c08.cpp

// Append 4 (unaligned) bytes to a write cursor.
struct Bytes4 {
    u8 b[4];
};
struct Writer {
    u8 pad[12];
    Bytes4* cur;
};
/*TARGET 001da3d8*/
void func_001da3d8(Writer* w, Bytes4* src) asm("func_001da3d8");
void func_001da3d8(Writer* w, Bytes4* src) { *w->cur++ = *src; }
}  // namespace n001da3d8

// 001da3f8 (was src/anon/batch_w1726_g.cpp)
namespace n001da3f8 {
struct U4 { u8 b[4]; };
// 0x001a9110: definition moved into src/anon/unit_001a9110.cpp

struct PopStack { u8 pad[12]; union { U4* p; u32 u; u8 c; } sp; };
/*TARGET 001da3f8*/
void func_001da3f8(PopStack* s, U4* out) asm("func_001da3f8");
void func_001da3f8(PopStack* s, U4* out) { s->sp.u -= 4; *out = *s->sp.p; }
}  // namespace n001da3f8

// 001da420 (was src/anon/batch_w19.cpp)
namespace n001da420 {
// 0x001afa50: definition moved into src/anon/unit_001ada38.cpp

struct KeyVal { u32 k, v; };
/*TARGET 001da420*/
u32 wtarget_001da420(u32, u32, u32, u32) asm("_Z16wtarget_001da420jjjj");
// Looks up key in a zero-terminated {key, value} table at (*a)+28.
u32 wtarget_001da420(u32 a, u32 key, u32, u32) {
    KeyVal* e = (KeyVal*)(*(u32*)a + 28);
    for (; e->v; e++)
        if (e->k == key) return e->v;
    return 0;
}
}  // namespace n001da420

// 001da458 (was src/anon/batch_w59.cpp)
namespace n001da458 {
// 0x001d8ad8: definition moved into src/anon/unit_001d7458.cpp

// --- 001da458
struct P1da { u32 a; u32 b; u32 cur; };
void func_001da3d8(P1da*, u32*) asm("func_001da3d8");
/*TARGET 001da458*/
// stream_append_unaligned
void func_001da458(P1da* p, u32 a, u32* arr, s32 n) asm("func_001da458");
// stream_append_unaligned
void func_001da458(P1da* p, u32 a, u32* arr, s32 n) {  // stream_init_fields
    u32 i;
    p->b = a;
    for (i = 0; i < 4; i++) {
        u32* c = (u32*)p->cur;
        *c = 0;
        p->cur = (u32)(c + 1);
    }
    for (i = 0; (s32)i < n; i++) func_001da3d8(p, &arr[i]);  // stream_append_unaligned
}
}  // namespace n001da458

// 001da4d8 (was src/anon/batch_w60.cpp)
namespace n001da4d8 {
// 0x001d9630: definition moved into src/anon/unit_001d7458.cpp

union U16Any { u16 h; s32 i; };
struct Reader1da { u8* base; s32 idx; u32 a; u32 pad; u32 b; };
/*TARGET 001da4d8*/
u32 func_001da4d8(Reader1da* s, u16 k) asm("func_001da4d8");
u32 func_001da4d8(Reader1da* s, u16 k) {  // stream_op_by_subtype
    u32 v = ((U16Any*)(s->base + 16 + s->idx * 2))->h;
    s->idx++;
    u32 r;
    switch (k >> 6) {
    case 0: r = s->a; break;
    case 1: r = s->b; break;
    case 2: r = *(u32*)s->a; break;
    case 3: r = (u32)s->base + 16; v *= 2; break;
    default: r = 0; break;
    }
    return r + v;
}
}  // namespace n001da4d8

// 001da558 (was src/anon/batch_w2479_nsa.cpp)
namespace n001da558 {
union BdVal { s32 i; u32 u; f32 f; };
struct BdOpF { u16 code : 4; u16 type : 2; u16 arg : 10; };
struct BdProg { u8 hdr[16]; u16 code[1]; };
union BdOp { u16 raw; BdOpF f; };
struct BdBytes4 { u8 b[4]; };
struct BdVM {
    BdProg* prog;
    s32 pc;
    s32* csp;
};
struct BdFunc { void (*fn)(BdVal*); u32 info; };
typedef void (*BdHook)(BdVM*, s32, void*);
void func_001da3d8(BdVM*, BdVal*) asm("func_001da3d8");
void func_001da3f8(BdVM*, BdVal*) asm("func_001da3f8");
u32 func_001da4d8(BdVM*, BdOpF) asm("func_001da4d8");
void memcpy(void*, void*, u32) asm("memcpy");
// memcpy
static inline void BdCopy(void* d, void* s, u32 n) { memcpy(d, s, n); }
f32 func_002f8b00(f32, f32) asm("func_002f8b00");
// fmodf
f32 sinf(f32) asm("sinf");
f32 cosf(f32) asm("cosf");
/*TARGET 001da558*/
// Bytecode interpreter: fetch a 16-bit opcode (code:4 type:2 arg:10) and run it on the VM
// value stack (001da3d8 push, 001da3f8 pop, 001da4d8 operand address); hook runs after every op.
s32 BdExecVM(BdVM* vm, BdFunc** fns, BdHook hook, void* arg) asm("BdExecVM");
// Bytecode interpreter: fetch a 16-bit opcode (code:4 type:2 arg:10) and run it on the VM
// value stack (001da3d8 push, 001da3f8 pop, 001da4d8 operand address); hook runs after every op.
s32 BdExecVM(BdVM* vm, BdFunc** fns, BdHook hook, void* arg)
{
    s32 st = 0;
    BdVal v[4];
    BdVal args[16];
    BdVal tmp;
    s32 off; u32 n;
    do {
        BdOp op;
        op.raw = *(u16*)((u32)vm->prog->code + vm->pc++ * 2);
        switch (op.f.code) {
        case 0:
            switch (op.f.type) {
            case 0:
            case 1:
                func_001da3d8(vm, (BdVal*)&vm->prog->code[vm->pc]);
                vm->pc += 2;
                break;
            case 3:
                tmp.u = func_001da4d8(vm, op.f);
                func_001da3d8(vm, (BdVal*)tmp.u);
                break;
            case 2:
                tmp.u = func_001da4d8(vm, op.f);
                func_001da3d8(vm, &tmp);
                break;
            default:
                st = 5;
                break;
            }
            break;
        case 1:
            tmp.u = func_001da4d8(vm, op.f);
            func_001da3f8(vm, (BdVal*)tmp.u);
            break;
        case 2: {
            func_001da3f8(vm, &tmp);
            n = vm->prog->code[vm->pc++];
            memcpy((void*)func_001da4d8(vm, op.f), (void*)tmp.u, n);
            break;
        }
        case 3:
            func_001da3f8(vm, &tmp);
            tmp.u += vm->prog->code[vm->pc++];
            func_001da3d8(vm, (BdVal*)tmp.u);
            break;
        case 4:
            func_001da3f8(vm, &v[0]);
            func_001da3f8(vm, &tmp);
            if (!op.f.arg) __builtin_memcpy((void*)tmp.u, &v[0], 4);
            else BdCopy((void*)tmp.u, (void*)v[0].u, op.f.arg);
            break;
        case 5:
            func_001da3f8(vm, &v[0]);
            switch (op.f.type) {
            case 0:
                switch (op.f.arg) {
                case 0: v[0].f = (f32)v[0].i; break;
                case 2: v[0].i = -v[0].i; break;
                case 3: v[0].i = ~v[0].i; break;
                case 4: v[0].i = !v[0].i; break;
                case 5: v[0].i = __builtin_abs(v[0].i); break;
                case 6: v[0].i = v[0].i < 0; break;
                case 7: v[0].i = v[0].i <= 0; break;
                case 8: v[0].i = v[0].i == 0; break;
                case 9: v[0].i = v[0].i != 0; break;
                case 10: v[0].i = v[0].i >= 0; break;
                case 11: v[0].i = v[0].i > 0; break;
                default: st = 5; break;
                }
                break;
            case 1:
                switch (op.f.arg) {
                case 1: v[0].i = (s32)v[0].f; break;
                case 2: v[0].f = -v[0].f; break;
                case 5: v[0].f = __builtin_fabsf(v[0].f); break;
                case 6: v[0].i = v[0].f < 0.0f; break;
                case 7: v[0].i = v[0].f <= 0.0f; break;
                case 8: v[0].i = v[0].f == 0.0f; break;
                case 9: v[0].i = v[0].f != 0.0f; break;
                case 10: v[0].i = v[0].f >= 0.0f; break;
                case 11: v[0].i = v[0].f > 0.0f; break;
                default: st = 5; break;
                }
                break;
            default:
                st = 5;
                break;
            }
            func_001da3d8(vm, &v[0]);
            break;
        case 6:
            func_001da3f8(vm, &v[1]);
            func_001da3f8(vm, &v[0]);
            switch (op.f.type) {
            case 0:
                switch (op.f.arg) {
                case 0: v[0].i = v[0].i + v[1].i; break;
                case 1: v[0].i = v[0].i - v[1].i; break;
                case 2: v[0].i = v[0].i * v[1].i; break;
                case 3: v[0].i = v[0].i / v[1].i; break;
                case 4: v[0].i = v[0].i % v[1].i; break;
                case 5: v[0].i = v[0].i & v[1].i; break;
                case 6: v[0].i = v[0].i | v[1].i; break;
                case 7: v[0].i = v[0].i ^ v[1].i; break;
                case 8: v[0].i = v[0].i << v[1].i; break;
                case 9: v[0].i = v[0].i >> v[1].i; break;
                case 10: v[0].i = v[0].i && v[1].i; break;
                case 11: v[0].i = v[0].i || v[1].i; break;
                }
                break;
            case 1:
                switch (op.f.arg) {
                case 0: v[0].f = v[0].f + v[1].f; break;
                case 1: v[0].f = v[0].f - v[1].f; break;
                case 2: v[0].f = v[0].f * v[1].f; break;
                case 3: v[0].f = v[0].f / v[1].f; break;
                case 4: v[0].f = func_002f8b00(v[0].f, v[1].f); break;
                default: st = 5; break;
                }
                break;
            default:
                st = 5;
                break;
            }
            func_001da3d8(vm, &v[0]);
            break;
        case 7:
            off = (s16)vm->prog->code[vm->pc++];
            switch (op.f.arg) {
            case 0:
                vm->pc += off;
                break;
            case 1:
                func_001da3f8(vm, &v[0]);
                if (!v[0].i) vm->pc += off;
                break;
            case 2:
                func_001da3f8(vm, &v[0]);
                if (v[0].i) vm->pc += off;
                break;
            default:
                st = 5;
                break;
            }
            break;
        case 11: {
            u32 n = op.f.arg;
            *(BdBytes4*)&off = *(BdBytes4*)&vm->prog->code[vm->pc];
            vm->pc += 2;
            vm->csp += n;
            vm->csp[-1] = vm->pc;
            vm->csp[-2] = n;
            vm->pc += off;
            break;
        }
        case 8: {
            u32 n = op.f.arg;
            off = (s16)vm->prog->code[vm->pc++];
            vm->csp += n;
            vm->csp[-1] = vm->pc;
            vm->csp[-2] = n;
            vm->pc += off;
            break;
        }
        case 9:
            switch (op.f.arg) {
            case 0: st = 1; break;
            case 1: st = 2; break;
            case 2: {
                s32* csp = vm->csp;
                vm->pc = csp[-1];
                n = csp[-2]; vm->csp = csp - n;
                if (!vm->pc) st = 3;
                break;
            }
            case 3:
                func_001da3f8(vm, &v[0]);
                break;
            case 5:
                func_001da3f8(vm, &v[0]);
                func_001da3d8(vm, &v[0]);
                func_001da3d8(vm, &v[0]);
                break;
            case 6:
                func_001da3f8(vm, &v[0]);
                v[0].f = sinf(func_002f8b00(v[0].f + 3.1415925f, 6.283185f) - 3.1415925f);
                func_001da3d8(vm, &v[0]);
                break;
            case 7:
                func_001da3f8(vm, &v[0]);
                v[0].f = cosf(func_002f8b00(v[0].f + 3.1415925f, 6.283185f) - 3.1415925f);
                func_001da3d8(vm, &v[0]);
                break;
            case 8:
                func_001da3f8(vm, &v[0]);
                v[0].f = func_002f8b00(v[0].f * 3.1415925f / 180.0f + 3.1415925f, 6.283185f) - 3.1415925f;
                func_001da3d8(vm, &v[0]);
                break;
            case 9:
                func_001da3f8(vm, &v[0]);
                v[0].f = v[0].f * 180.0f / 3.1415925f;
                func_001da3d8(vm, &v[0]);
                break;
            default:
                st = 5;
                break;
            }
            break;
        case 10: {
            BdFunc* f = fns[op.f.arg]; f += vm->prog->code[vm->pc++];
            s32 i = (u16)f->info; for (i--; i >= 0; i--) func_001da3f8(vm, &args[i]);
            f->fn(args);
            if (f->info & 0x40000000) func_001da3d8(vm, args);
            break;
        }
        default:
            st = 5;
            break;
        }
        if (hook) hook(vm, st, arg);
    } while (!st);
    return st;
}
}  // namespace n001da558

// 001daef8 (was src/anon/batch_w1881_nsa.cpp)
namespace n001daef8 {
struct QV1881 {
    f32 x, y, z, w;
    QV1881() {}
    QV1881(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    QV1881& operator=(const QV1881& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct QM1881 {
    QV1881 r[4];
    QM1881& operator=(const QM1881& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    // VU0 orthonormal matrix inverse (hand-written VU0 macro sequence)
    void invOrtho() {
        asm volatile("lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)" : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
} __attribute__((aligned(16)));
struct Src1881 { u8 pad[4]; f32 p[3]; f32 q[3]; u8 pad2[4]; f32 rot; };
struct Obj1881 { void* vt; u8 pad[12]; QM1881 m; QV1881 v; u8 pad2[8]; u32 f68; Src1881* src; };
extern u8 D_00352a20[] asm("D_00352a20");
static inline __attribute__((always_inline)) void initv1881(QV1881* v, f32 a, f32 b, f32 c, f32 d) {
    v->x = a;
    v->w = d;
    v->z = c;
    v->y = b;
}
void func_0011b6a8(QM1881*) asm("func_0011b6a8");
QM1881* func_0011b720(QM1881*, f32) asm("func_0011b720");
/*TARGET 001daef8*/
void func_001daef8(Obj1881* o, Src1881* s) asm("func_001daef8");
void func_001daef8(Obj1881* o, Src1881* s) {
    *(u32*)o = (u32)D_00352a20;
    initv1881(&o->v, s->q[0], s->q[1], s->q[2], 0.0f);
    o->f68 = 0;
    o->src = s;
    QV1881 t(s->p[0], s->p[1], s->p[2], 0.0f);
    func_0011b6a8(&o->m);
    o->m = *func_0011b720(&o->m, -s->rot);
    o->m.r[3] = t;
    o->m.r[3].w = 1.0f;
    o->m.invOrtho();
}
}  // namespace n001daef8

// 001db048 (was gap)
namespace n001daef8 {
// C1/C2 twin of 0x1daef8
void gap_001db048(Obj1881* o, Src1881* s) asm("gap_001db048");
void gap_001db048(Obj1881* o, Src1881* s) {
    *(u32*)o = (u32)D_00352a20;
    initv1881(&o->v, s->q[0], s->q[1], s->q[2], 0.0f);
    o->f68 = 0;
    o->src = s;
    QV1881 t(s->p[0], s->p[1], s->p[2], 0.0f);
    func_0011b6a8(&o->m);
    o->m = *func_0011b720(&o->m, -s->rot);
    o->m.r[3] = t;
    o->m.r[3].w = 1.0f;
    o->m.invOrtho();
}
}  // namespace n001daef8

// 001db198 (was src/anon/batch_w38.cpp)
namespace n001db198 {
// 0x001d59b0: definition moved into src/anon/unit_001d4f40.cpp

s32 func_001db200(void*, s32) asm("func_001db200");
s32 func_001db250(void*) asm("func_001db250");
/*TARGET 001db198*/
s32 func_001db198(void* p, s32 n) asm("func_001db198");
s32 func_001db198(void* p, s32 n) {
    switch (n) {
    case 0:
        return 1;
    case 1:
    case 2: {
        s32 r = 0;
        if (func_001db200(p, n) && func_001db250(p)) r = 1;
        return r;
    }
    }
    return 0;
}
}  // namespace n001db198

// 001db200 (was src/anon/tiny_auto80_queue.cpp)
namespace n001db200 {
u32 func_001b9d40(...) asm("func_001b9d40");
// 0x0018ffb8: definition moved into src/anon/unit_0018f140.cpp

extern "C" u32 func_0019ba60(...) asm("func_0019ba60");
// 001919d0: moved to src/yasui/libys/status.cpp

extern u8 D_0034e948 asm("D_0034e948");
/*TARGET 001db200*/
u32 func_001db200() asm("_Z13func_001db200v");
u32 func_001db200() {
    u32 s0 = *(u32*)&D_0034e948;
    u32 s1 = 0;
    if (func_0019ba60(s0) != 0) {
        s1 = (u32)(func_001b9d40(s0) != 0);  // vtable_call_slot64_flags
    }
    return s1;
}
}  // namespace n001db200

// 001db250 (was src/anon/batch_w209.cpp)
namespace n001db250 {
// 001a8450: moved to src/anon/unit_001a82f0.cpp

// --- 001db250
extern u8* D_0034e948 asm("D_0034e948");
extern void func_0017d0e8(void* out, f32 f) asm("func_0017d0e8");
extern void func_0019c778(void* a, void* b) asm("func_0019c778");
/*TARGET 001db250*/
void func_001db250(u8* a) asm("func_001db250");
void func_001db250(u8* a) {
    u8 tmp[16] __attribute__((aligned(16)));
    f32 f = *(f32*)(*(u8**)(a + 0x6c) + 0x20);
    func_0017d0e8(tmp, -1.5707964f - f);
    func_0019c778(D_0034e948, tmp);
}
}  // namespace n001db250

// 001db298 (was src/anon/batch_w83.cpp)
namespace n001db298 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct Vec4 {
    f32 x, y, z, w;
    Vec4() {}
    Vec4(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    Vec4(const Vec4& o) { QCOPY(this, &o); }
    Vec4& operator=(const Vec4& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
// 0x001d6790: definition moved into src/anon/unit_001d63a8.cpp

// r = m * v (4x4 matrix at m, column vectors), via VU0.
static inline Vec4 xform(const void* m, const Vec4& v) {
    Vec4 r;
    asm volatile(
        "lqc2 $vf5, 0(%1)\n\t"
        "lqc2 $vf1, 0(%2)\n\t"
        "lqc2 $vf2, 16(%2)\n\t"
        "lqc2 $vf3, 32(%2)\n\t"
        "lqc2 $vf4, 48(%2)\n\t"
        "vmulax.xyzw ACC, $vf1, $vf5x\n\t"
        "vmadday.xyzw ACC, $vf2, $vf5y\n\t"
        "vmaddaz.xyzw ACC, $vf3, $vf5z\n\t"
        "vmaddw.xyzw $vf5, $vf4, $vf5w\n\t"
        "sqc2 $vf5, 0(%0)"
        : : "r"(&r), "r"(&v), "r"(m) : "memory");
    return r;
}
struct XBox { u8 pad[16]; f32 m[16]; f32 ex, ey, ez; };
/*TARGET 001db298*/
// Is point inside the box's local half-extents after transforming by its matrix?
bool func_001db298(XBox* p, const Vec4* in) asm("func_001db298");
// Is point inside the box's local half-extents after transforming by its matrix?
bool func_001db298(XBox* p, const Vec4* in) {
    Vec4 v;
    v = *in;
    v.w = 1.0f;
    v = xform(p->m, v);
    bool r = false;
    if (-p->ex <= v.x && v.x <= p->ex && -p->ey <= v.y && v.y <= p->ey && -p->ez <= v.z && v.z <= p->ez) r = true;
    return r;
}
}  // namespace n001db298

// 001db368 (was src/anon/batch_w85.cpp)
namespace n001db368 {
// 128-bit vector with the engine's self-checking quadword copy
struct Vec4 {
    f32 x, y, z, w;
    Vec4& operator=(const Vec4& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline void vu_mulmv(void* out, const void* m, const void* v) {
    asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)"
                 : : "r"(out), "r"(m), "r"(v) : "memory");
}
/*TARGET 001db368*/
// 001a2910: moved to src/anon/unit_001a28f8.cpp

// transforms a point into the volume's space and tests it against the ellipse/height bounds
s32 func_001db368(u8* o, const Vec4* in) asm("func_001db368");
// 001a2910: moved to src/anon/unit_001a28f8.cpp

// transforms a point into the volume's space and tests it against the ellipse/height bounds
s32 func_001db368(u8* o, const Vec4* in) {
    Vec4 v;
    Vec4 t;
    f32 one;
    s32 r;
    v = *in;
    one = 1.0f;
    v.w = one;
    vu_mulmv(&t, o + 16, &v);
    v = t;
    r = 0;
    if (!(v.y < -*(f32*)(o + 84)) && !(*(f32*)(o + 84) < v.y)) {
        r = 1;
        v.x = v.x / *(f32*)(o + 80);
        v.z = v.z / *(f32*)(o + 88);
        if (!(v.x * v.x + v.z * v.z <= one)) r = 0;
    }
    return r;
}
}  // namespace n001db368

// 001db440 (was src/anon/batch_w84.cpp)
namespace n001db440 {
void* func_001050d8(u32) asm("func_001050d8");
void* func_001daef8(void*, void*) asm("func_001daef8");
extern void* D_00352a08[] asm("D_00352a08");
extern void* D_003529f0[] asm("D_003529f0");
extern void* D_003529d8[] asm("D_003529d8");
// Creates the event object matching the record type.
struct W84Ev {
    void** vt;
    u8 pad[108];
    static void* operator new(unsigned int n) { return func_001050d8(n); }
    W84Ev(u16* p) { func_001daef8(this, p); }
};
struct W84Ev0 : W84Ev { W84Ev0(u16* p) : W84Ev(p) { vt = D_00352a08; } };
struct W84Ev1 : W84Ev { W84Ev1(u16* p) : W84Ev(p) { vt = D_003529f0; } };
struct W84Ev2 : W84Ev { W84Ev2(u16* p) : W84Ev(p) { vt = D_003529d8; } };
/*TARGET 001db440*/
// 0x00272938: definition moved into src/anon/unit_00271e08.cpp


W84Ev* func_001db440(u16* p) asm("func_001db440");
// 0x00272938: definition moved into src/anon/unit_00271e08.cpp


W84Ev* func_001db440(u16* p) {
    switch (*p) {
    case 0: return new W84Ev0(p);
    case 1: return new W84Ev1(p);
    case 2: return new W84Ev2(p);
    }
    return 0;
}
}  // namespace n001db440

// 001db510 (was src/anon/batch_w1770.cpp)
namespace n001db510 {
#define QC1770(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV1770 {
    f32 x, y, z, w;
    QV1770() {}
    QV1770(const QV1770& o) { QC1770(this, &o); }
    QV1770& operator=(const QV1770& o) { if (this != &o) QC1770(this, &o); return *this; }
} __attribute__((aligned(16)));
struct QM1770 {
    QV1770 r[4];
    QV1770 operator*(const QV1770& v) const {
        QV1770 o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct Ob1770 { u8 pad[16]; QM1770 m; f32 f50; };
/*TARGET 001db510*/
f32 func_001db510(Ob1770* o, const QV1770* p) asm("func_001db510");
f32 func_001db510(Ob1770* o, const QV1770* p) {
    QV1770 v;
    v = *p;
    v.w = 1.0f;
    v = o->m * v;
    return (v.x + o->f50) / (o->f50 + o->f50);
}
}  // namespace n001db510

// 001db598 (was src/anon/tiny.cpp)
namespace n001db598 {
/*TARGET 001db598*/
// 0x001d7eb8: definition moved into src/anon/unit_001d7458.cpp

void func_001db598(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001db598jjjj");
// 0x001d7eb8: definition moved into src/anon/unit_001d7458.cpp

void func_001db598(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x01d6u << 16);
    *(u32*)((u32)b + (-17748)) = (u32)a0;
}
}  // namespace n001db598

// 001db5a8 (was src/anon/batch_w39.cpp)
namespace n001db5a8 {
// A local of this type keeps gcc from turning the final call into a sibling call.
struct NoTail { ~NoTail() {} };
// 0x001d6e60: definition moved into src/anon/unit_001d68e0.cpp

// --- 001db5a8
struct S1db { u32 a; u32 n; u8 data[1]; };
extern S1db* D_01d5baac asm("D_01d5baac");
extern char D_00321b28[] asm("D_00321b28");
int func_002fd248(int, void*, u32, int, const char*) asm("func_002fd248");
/*TARGET 001db5a8*/
void func_001db5a8(int id) asm("func_001db5a8");
void func_001db5a8(int id) {
    NoTail nt;
    if (!func_002fd248(id, D_01d5baac->data, D_01d5baac->n, 92, D_00321b28))
        func_002fd248(69, D_01d5baac->data, D_01d5baac->n, 92, D_00321b28);
}
}  // namespace n001db5a8

// 001db610 (was src/anon/auto80_199_queue.cpp)
namespace n001db610 {
/*TARGET 001db610*/
u32 func_001db610(u32 a0, Func_001db610_cb a1, u32 a2) asm("_Z13func_001db610jPFjjjEj");
u32 func_001db610(u32 a0, Func_001db610_cb a1, u32 a2) {
    u32 s0 = a0;
    u32 s1 = a2;
    Func_001db610_cb s2 = a1;
    u32 ret;

    if (*(u16*)(s0 + 0) == 0) {
        goto L_zero;
    }

    while (1) {
        u32 v0 = s2(s0, s1);
        u32 t7 = *(u16*)(s0 + 2);
        t7 = t7 << 2;
        t7 = func_001db610_add(s0, t7);
        s0 = t7 + 4;
        if (v0 == 0) {
            ret = s0;
            goto L_ret;
        }
        t7 = *(u16*)(t7 + 4);
        if (t7 == 0) {
            goto L_zero;
        }
    }

L_zero:
    ret = 0;

L_ret:
    return ret;
}
}  // namespace n001db610

// 001db688 (was src/anon/batch_w8009_nsa.cpp)
namespace n001db688 {
typedef struct W8009AlVt { u8* (*alloc)(struct W8009Al*, s32, s32); } W8009AlVt;
struct W8009Al { W8009AlVt* vt; };
extern u8 D_00352a38[] asm("D_00352a38");
struct W8009Pool {
    void* vt;
    W8009Al* al;
    s32 p8;
    u8* buf;
    u8* end;
    const s32 sz;
    const s32 cnt;
    static void* operator new(unsigned int, void* p) { return p; }
    inline W8009Pool(W8009Al* a, s32 s, s32 c)
        : vt(D_00352a38), al(a), buf(a->vt->alloc(a, (s + 4) * c, 0)), end(buf + s * c), sz(s), cnt(c) {}
};
void func_001db850(W8009Pool*) asm("func_001db850");
/*TARGET 001db688*/
void func_001db688(W8009Pool* p, W8009Al* a, s32 sz, s32 cnt) asm("func_001db688");
void func_001db688(W8009Pool* p, W8009Al* a, s32 sz, s32 cnt) {
    new (p) W8009Pool(a, sz, cnt);
    func_001db850(p);
}
}  // namespace n001db688

// 001db710 (was src/anon/batch_w8009_nsa.cpp)
namespace n001db710 {
typedef struct W8009AlVt { u8* (*alloc)(struct W8009Al*, s32, s32); } W8009AlVt;
struct W8009Al { W8009AlVt* vt; };
extern u8 D_00352a38[] asm("D_00352a38");
struct W8009Pool {
    void* vt;
    W8009Al* al;
    s32 p8;
    u8* buf;
    u8* end;
    const s32 sz;
    const s32 cnt;
    static void* operator new(unsigned int, void* p) { return p; }
    inline W8009Pool(W8009Al* a, s32 s, s32 c)
        : vt(D_00352a38), al(a), buf(a->vt->alloc(a, (s + 4) * c, 0)), end(buf + s * c), sz(s), cnt(c) {}
};
void func_001db850(W8009Pool*) asm("func_001db850");
/*TARGET 001db710*/
void func_001db710(W8009Pool* p, W8009Al* a, s32 sz, s32 cnt) asm("func_001db710");
void func_001db710(W8009Pool* p, W8009Al* a, s32 sz, s32 cnt) {
    new (p) W8009Pool(a, sz, cnt);
    func_001db850(p);
}
}  // namespace n001db710

// 001db798 (was gap)
namespace n001db798 {
struct VObj1db7d0 { void** vt; };
struct S1db7d0 { void* vt; VObj1db7d0* o; u32 p8; u32 c; };
extern void* D_00352a38 asm("D_00352a38");
// twin of 0x1db7d0
void gap_001db798(S1db7d0* s) asm("gap_001db798");
void gap_001db798(S1db7d0* s) {
    s->vt = &D_00352a38;
    VObj1db7d0* o = s->o;
    ((void (*)(VObj1db7d0*, u32))o->vt[1])(o, s->c);
}
}  // namespace n001db798

// 001db7d0 (was src/anon/batch_w1733_nsa.cpp)
namespace n001db7d0 {
struct VObj1db7d0 { void** vt; };
struct S1db7d0 { void* vt; VObj1db7d0* o; u32 p8; u32 c; };
extern void* D_00352a38 asm("D_00352a38");
/*TARGET 001db7d0*/
void func_001db7d0(S1db7d0* s) asm("func_001db7d0");
void func_001db7d0(S1db7d0* s) {
    s->vt = &D_00352a38;
    VObj1db7d0* o = s->o;
    ((void (*)(VObj1db7d0*, u32))o->vt[1])(o, s->c);
}
}  // namespace n001db7d0

// 001db808 (was src/anon/batch_wcx2_nsa.cpp)
namespace n001db808 {
struct Obj1db808 { void** vt; };
struct B1db808 { void* vt; Obj1db808* o; u32 p8; s32 c; };
typedef void (*Fn1db808)(Obj1db808*, s32);
void func_00106420(void*) asm("func_00106420");
extern void* D_00352a38 asm("D_00352a38");
/*TARGET 001db808*/
void func_001db808(B1db808* b) asm("func_001db808");
void func_001db808(B1db808* b) {
    b->vt = &D_00352a38;
    Obj1db808* o = b->o;
    ((Fn1db808)o->vt[1])(o, b->c);
    func_00106420(b);
}
}  // namespace n001db808

// 001db850 (was src/anon/batch_w21.cpp)
namespace n001db850 {
/*TARGET 001db850*/
// 0x001d7e00: definition moved into src/anon/unit_001d7458.cpp

// Fill the index table with 0..n-1 and reset the count.
void func_001db850(u8* p) asm("func_001db850");
// 0x001d7e00: definition moved into src/anon/unit_001d7458.cpp

// Fill the index table with 0..n-1 and reset the count.
void func_001db850(u8* p) {
    s32 i;
    for (i = 0; i < *(s32*)(p + 24); i++) ((s32*)*(u32*)(p + 16))[i] = i;
    *(s32*)(p + 8) = *(s32*)(p + 24);
}
}  // namespace n001db850

// 001db888 (was src/anon/batch_w7.cpp)
namespace n001db888 {
/*TARGET 001db888*/
// 0x001c90c0: definition moved into src/anon/unit_001c8e80.cpp

// 001cd520: moved to src/anon/unit_001cd078.cpp

// Pops one entry: --count; return base + scale * table[count].
s32 func_001db888(s32* a0) asm("func_001db888");
// 0x001c90c0: definition moved into src/anon/unit_001c8e80.cpp

// 001cd520: moved to src/anon/unit_001cd078.cpp

// Pops one entry: --count; return base + scale * table[count].
s32 func_001db888(s32* a0) {  // record_index_calc
    a0[2]--;
    return a0[3] + a0[5] * ((s32*)a0[4])[a0[2]];
}
}  // namespace n001db888

// 001db8b8 (was src/anon/batch_w2029.cpp)
namespace n001db8b8 {
struct W2029_Q { int a, b; int n; int base; u32* arr; u32 div; };
/*TARGET 001db8b8*/
void func_001db8b8(W2029_Q* q, int v) asm("func_001db8b8");
void func_001db8b8(W2029_Q* q, int v) {
    int n = q->n;
    u32 r = (u32)(v - q->base) / q->div;
    q->arr[n] = r;
    q->n = n + 1;
}
}  // namespace n001db8b8

// 001db8f8 (was src/anon/batch_w29.cpp)
namespace n001db8f8 {
void ctarget_001db8f8(u8* p, u32 a, u32 b, u32 c) asm("_Z16ctarget_001db8f8jjjj");
void func_001c23a8(u8*, u32, u32, u32, u32, u32, u32) asm("func_001c23a8");
extern u8 D_00352a78[] asm("D_00352a78");
/*TARGET 001db8f8*/
// 0x001d9228: definition moved into src/anon/unit_001d7458.cpp

void ctarget_001db8f8(u8* p, u32 a, u32 b, u32 c) asm("_Z16ctarget_001db8f8jjjj");
// 0x001d9228: definition moved into src/anon/unit_001d7458.cpp

void ctarget_001db8f8(u8* p, u32 a, u32 b, u32 c) {
    func_001c23a8(p, a, b, 0, 0, 96, c);
    *(u32*)(p + 1416) |= 0x10000000;
    *(u32*)(p + 2552) = 0;
    *(void**)p = D_00352a78;
}
}  // namespace n001db8f8

// 001db950 (was src/anon/batch_w30.cpp)
namespace n001db950 {
void func_001c23a8(void*, u32, u32, u32, u32, u32, u32) asm("func_001c23a8");
extern u8 D_00352a78[] asm("D_00352a78");
/*TARGET 001db950*/
// 0x001d4ef0: definition moved into src/anon/unit_001d3c08.cpp

void func_001db950(u8* p, u32 a, u32 b, u32 c) asm("func_001db950");
// 0x001d4ef0: definition moved into src/anon/unit_001d3c08.cpp

void func_001db950(u8* p, u32 a, u32 b, u32 c) {
    func_001c23a8(p, a, b, 0, 0, 96, c);
    *(u32*)(p + 0x9f8) = 0;
    *(u32*)(p + 0x588) |= 0x10000000;
    *(void**)p = D_00352a78;
}
}  // namespace n001db950

// 001db9a8 (was src/anon/batch_w41.cpp)
namespace n001db9a8 {
// 0x001d9320: definition moved into src/anon/unit_001d7458.cpp

u32 func_001dba18(u32, u32, u32) asm("func_001dba18");
u32 func_001050d8(u32) asm("func_001050d8");
void func_001db950(u32, u32, u32, u32) asm("func_001db950");
static inline u32 w41Create(u32 a, u32 b, u32 c) {
    u32 p = func_001050d8(2560);
    func_001db950(p, a, b, c);
    return p;
}
/*TARGET 001db9a8*/
u32 func_001db9a8(u32 a, u32 b, u32 c) asm("func_001db9a8");
u32 func_001db9a8(u32 a, u32 b, u32 c) {
    u32 r = func_001dba18(a, b, c);
    if (!r) return w41Create(a, b, c);
    return r;
}
}  // namespace n001db9a8

// 001dba18 (was src/anon/batch_w43.cpp)
namespace n001dba18 {
u8* func_001b9bc8(u8*) asm("func_001b9bc8");
/*TARGET 001dba18*/
// 0x001d5370: definition moved into src/anon/unit_001d4f40.cpp

u8* func_001dba18(u32 id) asm("func_001dba18");
// 0x001d5370: definition moved into src/anon/unit_001d4f40.cpp

u8* func_001dba18(u32 id) {
    u8* v = 0;
    while ((v = func_001b9bc8(v)) != 0) {
        if (!(*(u32*)(v + 1416) & 0x10000000)) continue;
        if (*(u32*)(v + 8) == id) return v;
    }
    return 0;
}
}  // namespace n001dba18

// 001dba88 (was src/anon/tiny_leaf.cpp)
namespace n001dba88 {
/*TARGET 001dba88*/
// 0x001d96e8: definition moved into src/anon/unit_001d7458.cpp

void func_001dba88(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001dba88jjjj");
// 0x001d96e8: definition moved into src/anon/unit_001d7458.cpp

void func_001dba88(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15 = 0u;
    r15 = *(u32*)((u32)r4 + (s32)(2552));
    r15 = (u32)((s32)r15 + (1));
    *(u32*)((u32)r4 + (s32)(2552)) = r15;
}
}  // namespace n001dba88

// 001dba98 (was src/anon/batch_w11.cpp)
namespace n001dba98 {
typedef void (*VFn)(void*);
/*TARGET 001dba98*/
void func_001dba98(u8* p) asm("func_001dba98");
void func_001dba98(u8* p) {
    s32 n = *(s32*)(p + 2552) - 1;
    *(s32*)(p + 2552) = n;
    if (n == 0) (*(VFn*)((*(u8**)p) + 32))(p);
}
}  // namespace n001dba98

// 001dbad0 (was src/anon/batch_w40.cpp)
namespace n001dbad0 {
// 0x001d87b8: definition moved into src/anon/unit_001d7458.cpp

s32 func_0019ba60(u32) asm("func_0019ba60");
u8* func_0016c028(u32) asm("func_0016c028");
// obj_get_attach_or_alt
void func_001dbcd0(void) asm("func_001dbcd0");
void func_001c2578(u32) asm("func_001c2578");
extern u32 D_0034e948 asm("D_0034e948");
extern u8 D_00352a60[] asm("D_00352a60");
/*TARGET 001dbad0*/
void func_001dbad0(u32 a) asm("func_001dbad0");
void func_001dbad0(u32 a) {
    if (func_0019ba60(D_0034e948)) {
        u8* v = func_0016c028(D_0034e948);  // obj_get_attach_or_alt
        if (v != D_00352a60)
            asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(D_00352a60), "r"(v) : "$8", "memory");
    }
    func_001dbcd0();
    func_001c2578(a);
}
}  // namespace n001dbad0

// 001dbb38 (was src/anon/batch_w31.cpp)
namespace n001dbb38 {
typedef void (*VFn)(void*);
void* func_00185da8(void*) asm("func_00185da8");
int func_0019c410(void*) asm("func_0019c410");
/*TARGET 001dbb38*/
void func_001dbb38(void) asm("func_001dbb38");
void func_001dbb38(void) {
    void* o = 0;
    while ((o = func_00185da8(o)) != 0) {
        if (func_0019c410(o)) {
            (*(VFn*)(*(u8**)o + 32))(o);
            return;
        }
    }
}
}  // namespace n001dbb38

// 001dbb98 (was src/anon/batch_w1664.cpp)
namespace n001dbb98 {
// 0x001ae4b8: definition moved into src/anon/unit_001ada38.cpp
void wtarget_001dbb98(u32, u32, u32, u32) asm("_Z16wtarget_001dbb98jjjj");
/*TARGET 001dbb98*/
void wtarget_001dbb98(u32, u32, u32, u32) asm("_Z16wtarget_001dbb98jjjj");
void wtarget_001dbb98(u32, u32, u32, u32) {}
}  // namespace n001dbb98

// 001dbba0 (was src/anon/tiny_wrappers_more.cpp)
namespace n001dbba0 {
u32 func_001dbb98(u32, u32, u32, u32) asm("_Z13func_001dbb98jjjj");
/*TARGET 001dbba0*/
u32 func_001dbba0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001dbba0jjjj");
u32 func_001dbba0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001dbb98(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n001dbba0

// 001dbbc0 (was gap)
namespace n001dbbc0 {
u32 func_001dbb98(u32, u32, u32, u32) asm("_Z13func_001dbb98jjjj");
u32 gap_001dbbc0(u32 a0, u32 a1, u32 a2, u32 a3) asm("gap_001dbbc0");
u32 gap_001dbbc0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001dbb98(0x00000000u, 0x0000ffffu, a2, a3);
}
}  // namespace n001dbbc0

