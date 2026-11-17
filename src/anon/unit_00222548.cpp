// Linked unit 0x00222548-0x00222aa8 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// 00222548-00222aa8 gap functions (unwritten before) are written in place below.
namespace n00222548 {
extern u32 D_0035da30 asm("D_0035da30");
u32 func_00222548(void) asm("func_00222548");
u32 func_00222548(void) { u32 r = (D_0035da30 * 2061 + 7) & 0xffff; D_0035da30 = r; return r; }
}  // namespace n00222548

// 00222568 (was src/anon/batch_w206.cpp)
namespace n00222568 {
/*TARGET 00222568*/
// 0x001702e0: definition moved into src/anon/unit_0016e8f8.cpp

// VU0 random number in [0,1) scaled to 0..32767
s32 func_00222568(void) asm("func_00222568");
// 0x001702e0: definition moved into src/anon/unit_0016e8f8.cpp

// VU0 random number in [0,1) scaled to 0..32767
s32 func_00222568(void) {  // vu_const_5f_d
    f32 r;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\tvrxor R, $vf2x\n\tvitof0.x $vf2, $vf2\n\tvrnext.x $vf1, R\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1" : "=r"(r) : : "$8");
    return (s32)(r * 32768.0f);
}
}  // namespace n00222568

// 002225a8 (was src/anon/batch_w1797.cpp)
namespace n002225a8 {
struct Ray_002225a8 { f32 ox, oy, oz, pad0; f32 dx, dy, dz, pad1; f32 r; f32 t; };
f32 func_00222978(f32) asm("func_00222978");
/*TARGET 002225a8*/
s32 func_002225a8(Ray_002225a8* s) asm("func_002225a8");
s32 func_002225a8(Ray_002225a8* s) {
    s32 ret = 0;
    f32 a = s->dx * s->dx + s->dy * s->dy + s->dz * s->dz;
    f32 b = s->dx * s->ox + s->dy * s->oy + s->dz * s->oz;
    b = b + b;
    f32 c = s->ox * s->ox + s->oy * s->oy + s->oz * s->oz - s->r * s->r;
    f32 disc = b * b - 4.0f * a * c;
    c = -b;
    b = a + a;
    if (!(disc < 0.0f)) {
        ret = 1;
        s->t = (c - func_00222978(disc)) / b;
    }
    return ret;
}
}  // namespace n002225a8

// 00222678 (was src/anon/batch_w1.cpp)
namespace n00222678 {
/*TARGET 00222678*/
// VU0: return max(x, y).
f32 func_00222678(f32 x, f32 y) asm("func_00222678");
// VU0: return max(x, y).
f32 func_00222678(f32 x, f32 y) {
    f32 v[4] __attribute__((aligned(16)));
    v[0] = x;
    v[1] = y;
    asm volatile("lqc2 $vf1, %0\n\tvmaxy.x $vf1, $vf1, $vf1y\n\tsqc2 $vf1, %0" : "+m"(v));
    return v[0];
}
}  // namespace n00222678

// 002226a0 (was src/anon/batch_w1.cpp)
namespace n002226a0 {
/*TARGET 002226a0*/
// VU0: meant to copy xy of s into d, but stores vf31 (bug in the original).
void func_002226a0(f32* d, f32* s) asm("func_002226a0");
// VU0: meant to copy xy of s into d, but stores vf31 (bug in the original).
void func_002226a0(f32* d, f32* s) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvmove.xy $vf1, $vf2\n\tsqc2 $vf31, 0(%0)\n\t.set reorder"
                 : : "r"(d), "r"(s) : "memory");
}
}  // namespace n002226a0

// 002226b8 (was src/anon/batch_w2.cpp)
namespace n002226b8 {
/*TARGET 002226b8*/
// VU0 macro: d.xyz = s.xyz.
void func_002226b8(void* d, void* s) asm("func_002226b8");
// VU0 macro: d.xyz = s.xyz.
void func_002226b8(void* d, void* s) {  // vec3_copy
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvmove.xyz $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(d), "r"(s) : "memory");
}
}  // namespace n002226b8

namespace n002226d0 {
// VU0: d.xyz = s.xyz * k (k is stored into d.x first).
void func_002226d0(f32* d, void* s, f32 k) asm("func_002226d0");
void func_002226d0(f32* d, void* s, f32 k) {
    d[0] = k;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvmulx.xyz $vf2, $vf2, $vf1x\n\tsqc2 $vf2, 0(%0)\n\t.set reorder" : : "r"(d), "r"(s) : "memory");
}
// VU0: d.xy = s.xy * k.
void func_002226f0(f32* d, void* s, f32 k) asm("func_002226f0");
void func_002226f0(f32* d, void* s, f32 k) {
    d[0] = k;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvmulx.xy $vf2, $vf2, $vf1x\n\tsqc2 $vf2, 0(%0)\n\t.set reorder" : : "r"(d), "r"(s) : "memory");
}
}  // namespace n002226d0

// 00222710 (was src/anon/batch_w3.cpp)
namespace n00222710 {
/*TARGET 00222710*/
// dst.xy = a.xy + b.xy (VU0).
void func_00222710(void* dst, void* a, void* b) asm("func_00222710");
// dst.xy = a.xy + b.xy (VU0).
void func_00222710(void* dst, void* a, void* b) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tlqc2 $vf3, 0(%0)\n\t"
                 "vadd.xy $vf3, $vf1, $vf2\n\tsqc2 $vf3, 0(%0)\n\t.set reorder"
                 : : "r"(dst), "r"(a), "r"(b) : "memory");
}
}  // namespace n00222710

// 00222730 (was src/anon/batch_w4.cpp)
namespace n00222730 {
/*TARGET 00222730*/
// d.xyz = a.xyz - b.xyz (VU0 macro mode).
void func_00222730(void* d, void* a, void* b) asm("func_00222730");
// d.xyz = a.xyz - b.xyz (VU0 macro mode).
void func_00222730(void* d, void* a, void* b) {
    asm volatile(".set noreorder\n\t"
                 "lqc2 $vf1, 0(%1)\n\t"
                 "lqc2 $vf2, 0(%2)\n\t"
                 "lqc2 $vf3, 0(%0)\n\t"
                 "vsub.xyz $vf3, $vf1, $vf2\n\t"
                 "sqc2 $vf3, 0(%0)\n\t"
                 ".set reorder"
                 :
                 : "r"(d), "r"(a), "r"(b)
                 : "memory");
}
}  // namespace n00222730

// 00222750 (was src/anon/batch_w5.cpp)
namespace n00222750 {
/*TARGET 00222750*/
// VU0 macro code: dst.xyz = a.xyz + b.xyz (dst.w kept).
void func_00222750(void* dst, void* a, void* b) asm("func_00222750");
// VU0 macro code: dst.xyz = a.xyz + b.xyz (dst.w kept).
void func_00222750(void* dst, void* a, void* b) {
    asm volatile(
        ".set noreorder\n\t"
        "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tlqc2 $vf3, 0(%0)\n\t"
        "vadd.xyz $vf3, $vf1, $vf2\n\tsqc2 $vf3, 0(%0)\n\t.set reorder"
        : : "r"(dst), "r"(a), "r"(b) : "memory");
}
}  // namespace n00222750

// 00222770 (was src/anon/batch_w1.cpp)
namespace n00222770 {
/*TARGET 00222770*/
// VU0: d.xy = a.xy - b.xy (zw kept).
void func_00222770(f32* d, f32* a, f32* b) asm("func_00222770");
// VU0: d.xy = a.xy - b.xy (zw kept).
void func_00222770(f32* d, f32* a, f32* b) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tlqc2 $vf3, 0(%0)\n\tvsub.xy $vf3, $vf1, $vf2\n\tsqc2 $vf3, 0(%0)\n\t.set reorder"
                 : : "r"(d), "r"(a), "r"(b) : "memory");
}
}  // namespace n00222770

// 00222790 (was src/anon/batch_w45.cpp)
namespace n00222790 {
/*TARGET 00222790*/
// Hand-written VU0 macro code: d = ftoi4/ftoi0 of (a + b) with an overflow-flag fix-up
void func_00222790(void* d, const void* a, const void* b) asm("func_00222790");
// Hand-written VU0 macro code: d = ftoi4/ftoi0 of (a + b) with an overflow-flag fix-up
void func_00222790(void* d, const void* a, const void* b) {  // vec2_add_round_pack
    asm volatile(
        ".set noreorder\n\t"
        "lqc2 $vf1, 0($5)\n\t"
        "lqc2 $vf2, 0($6)\n\t"
        "vadd.xy $vf1, $vf1, $vf2\n\t"
        "vftoi4.xy $vf31, $vf1\n\t"
        "vftoi0.zw $vf31, $vf1\n\t"
        "lui $2, 0x4580\n\t"
        "dsll $2, $2, 16\n\t"
        "ori $2, $2, 0x4580\n\t"
        "dsll $2, $2, 16\n\t"
        "qmtc2 $2, $vf29\n\t"
        "ctc2 $0, $vi16\n\t"
        "vsub.xyw $vf0, $vf1, $vf0\n\t"
        "vsub.xy $vf0, $vf29, $vf1\n\t"
        "vnop\n\t"
        "vnop\n\t"
        "vnop\n\t"
        "vnop\n\t"
        "cfc2 $2, $vi16\n\t"
        "andi $2, $2, 0xc0\n\t"
        "beqz $2, 1f\n\t"
        "nop\n\t"
        "addiu $2, $0, 0\n\t"
        "ori $2, $0, 0x8000\n\t"
        "ctc2 $2, $vi1\n\t"
        "vmfir.w $vf31, $vi1\n"
        "1:\n\t"
        "sqc2 $vf31, 0($4)\n\t"
        ".set reorder"
        : : "r"(d), "r"(a), "r"(b) : "$2", "memory");
}
}  // namespace n00222790

// 00222800 (was src/anon/batch_w39.cpp)
namespace n00222800 {
/*TARGET 00222800*/
// --- 00222800
// VU0: d.xy = ftoi4(s.xy), d.zw = ftoi0(s.zw); if s.xy falls outside
// [0, 4096) (clip flags), d.w is replaced by 0x8000.
void func_00222800(void* d, void* s) asm("func_00222800");
// --- 00222800
// VU0: d.xy = ftoi4(s.xy), d.zw = ftoi0(s.zw); if s.xy falls outside
// [0, 4096) (clip flags), d.w is replaced by 0x8000.
void func_00222800(void* d, void* s) {  // vec2_ftoi_round_pack
    asm volatile(
        ".set noreorder\n\t"
        "lqc2 $vf1, 0(%1)\n\t"
        "vftoi4.xy $vf2, $vf1\n\t"
        "vftoi0.zw $vf2, $vf1\n\t"
        "lui $2, 0x4580\n\t"
        "dsll $2, $2, 16\n\t"
        "ori $2, $2, 0x4580\n\t"
        "dsll $2, $2, 16\n\t"
        "qmtc2 $2, $vf29\n\t"
        "ctc2 $0, $vi16\n\t"
        "vsub.xyw $vf0, $vf1, $vf0\n\t"
        "vsub.xy $vf0, $vf29, $vf1\n\t"
        "vnop\n\t"
        "vnop\n\t"
        "vnop\n\t"
        "vnop\n\t"
        "cfc2 $2, $vi16\n\t"
        "andi $2, $2, 0xc0\n\t"
        "beqz $2, 1f\n\t"
        "nop\n\t"
        "li $2, 0\n\t"
        "li $2, 0x8000\n\t"
        "ctc2 $2, $vi1\n\t"
        "vmfir.w $vf2, $vi1\n"
        "1:\n\t"
        "sqc2 $vf2, 0(%0)\n\t"
        ".set reorder"
        : : "r"(d), "r"(s) : "$2", "memory");
}
}  // namespace n00222800

// 00222868 (was src/anon/batch_w10.cpp)
namespace n00222868 {
/*TARGET 00222868*/
// Normalize the 2D vector at s (xy) into d.
void func_00222868(void* d, void* s) asm("func_00222868");
// Normalize the 2D vector at s (xy) into d.
void func_00222868(void* d, void* s) {  // vec2_normalize
    asm volatile(
        ".set noreorder\n\t"
        "lqc2 $vf1, 0(%1)\n\t"
        "vmul.xy $vf31, $vf1, $vf1\n\t"
        "vaddy.x $vf31, $vf31, $vf31y\n\t"
        "vsqrt Q, $vf31x\n\t"
        "vwaitq\n\t"
        "vaddq.x $vf31, $vf0, Q\n\t"
        "vdiv Q, $vf0w, $vf31x\n\t"
        "vwaitq\n\t"
        "vmulq.xy $vf31, $vf1, Q\n\t"
        "sqc2 $vf31, 0(%0)\n\t"
        ".set reorder"
        : : "r"(d), "r"(s) : "memory");
}
}  // namespace n00222868

// 00222898 (was src/anon/batch_w51.cpp)
namespace n00222898 {
/*TARGET 00222898*/
// Transform v by matrix m, project, store to out; returns screen clip flags (hand-written VU0 asm).
u32 func_00222898(void* out, void* m, void* v) asm("func_00222898");
// Transform v by matrix m, project, store to out; returns screen clip flags (hand-written VU0 asm).
u32 func_00222898(void* out, void* m, void* v) {  // mat4_transform_vec
    register u32 r asm("$2");
    asm volatile(
        ".set noreorder\n\t"
        "lqc2 $vf1, 0(%2)\n\t"
        "lqc2 $vf2, 16(%2)\n\t"
        "lqc2 $vf3, 32(%2)\n\t"
        "lqc2 $vf4, 48(%2)\n\t"
        "lqc2 $vf5, 0(%3)\n\t"
        "vmulax.wxyz ACC, $vf1, $vf5x\n\t"
        "vmadday.wxyz ACC, $vf2, $vf5y\n\t"
        "vmaddaz.wxyz ACC, $vf3, $vf5z\n\t"
        "vmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
        "vdiv Q, $vf0w, $vf5w\n\t"
        "lui $2, 0x4580\n\t"
        "dsll $2, $2, 16\n\t"
        "ori $2, $2, 0x4580\n\t"
        "dsll $2, $2, 16\n\t"
        "qmtc2 $2, $vf29\n\t"
        "vwaitq\n\t"
        "vmulq.xyz $vf5, $vf5, Q\n\t"
        "vnop\n\t"
        "vnop\n\t"
        "vnop\n\t"
        "ctc2.ni $0, $vi16\n\t"
        "vsub.wxy $vf0, $vf5, $vf0\n\t"
        "vsub.xy $vf0, $vf29, $vf5\n\t"
        "vnop\n\t"
        "vnop\n\t"
        "vnop\n\t"
        "vnop\n\t"
        "cfc2.ni $2, $vi16\n\t"
        "andi $2, $2, 0xc0\n\t"
        "sqc2 $vf5, 0(%1)\n\t"
        ".set reorder"
        : "=r"(r) : "r"(out), "r"(m), "r"(v) : "memory");
    return r;
}
}  // namespace n00222898

namespace n00222918 {
// VU0: perspective divide, then xy to 12.4 fixed point and z/w to integers.
void func_00222918(void* d, void* s) asm("func_00222918");
void func_00222918(void* d, void* s) {
    asm volatile(".set noreorder\n\tlqc2 $vf10, 0(%1)\n\tvdiv Q, $vf0w, $vf10w\n\tvwaitq\n\tvmulq.xyz $vf9, $vf10, Q\n\tvftoi4.xy $vf9, $vf9\n\tvftoi0.z $vf9, $vf9\n\tvftoi0.w $vf9, $vf10\n\tsqc2 $vf9, 0(%0)\n\t.set reorder" : : "r"(d), "r"(s) : "memory");
}
// x to the n-th power (n >= 0).
f32 func_00222940(s32 n, f32 x) asm("func_00222940");
f32 func_00222940(s32 n, f32 x) { f32 r = 1.0f; if (n > 0) { do { r *= x; } while (--n); } return r; }
}  // namespace n00222918

// 00222978 (was src/anon/batch_w2.cpp)
namespace n00222978 {
/*TARGET 00222978*/
// VU0 square root.
f32 func_00222978(f32 x) asm("func_00222978");
// VU0 square root.
f32 func_00222978(f32 x) {  // vu_sqrt_f12
    f32 v[4] __attribute__((aligned(16)));
    f32 r;
    v[1] = x;
    asm volatile("lqc2 $vf10, 0(%1)\n\tvsqrt Q, $vf10y\n\tvwaitq\n\tcfc2 $2, $vi22\n\tmtc1 $2, %0"
                 : "=f"(r) : "r"(v) : "$2", "memory");
    return r;
}
}  // namespace n00222978

// 002229a0 (was src/anon/batch_w16.cpp)
namespace n002229a0 {
/*TARGET 002229a0*/
// 0x001e4f00: definition moved into src/anon/unit_001e0cb8.cpp

// 3D vector length (VU0).
f32 func_002229a0(void* v) asm("func_002229a0");
// 0x001e4f00: definition moved into src/anon/unit_001e0cb8.cpp

// 3D vector length (VU0).
f32 func_002229a0(void* v) {  // vec3_length
    f32 r[4] __attribute__((aligned(16)));
    asm volatile("lqc2 $vf10, 0(%1)\n\tvmul.xyz $vf10, $vf10, $vf10\n\tvmove.xyz $vf9, $vf10\n\t"
                 "vaddx.y $vf9, $vf9, $vf9x\n\tvaddy.z $vf9, $vf9, $vf9y\n\tvsqrt Q, $vf9z\n\tvwaitq\n\t"
                 "vaddq.x $vf10, $vf0, Q\n\tsqc2 $vf10, %0"
                 : "=m"(r) : "r"(v));
    return r[0];
}
}  // namespace n002229a0

// 002229d8 (was src/anon/batch_w3.cpp)
namespace n002229d8 {
/*TARGET 002229d8*/
// 2D length sqrt(x*x + y*y) (VU0).
f32 func_002229d8(void* v) asm("func_002229d8");
// 2D length sqrt(x*x + y*y) (VU0).
f32 func_002229d8(void* v) {
    f32 r;
    asm volatile(".set noreorder\n\tlqc2 $vf10, 0(%1)\n\tvmul.xy $vf10, $vf10, $vf10\n\t"
                 "vaddx.y $vf10, $vf10, $vf10x\n\tvsqrt Q, $vf10y\n\tvwaitq\n\t"
                 "cfc2 $2, $vi22\n\tmtc1 $2, %0\n\t.set reorder"
                 : "=f"(r) : "r"(v) : "$2");
    return r;
}
}  // namespace n002229d8

// 00222a00 (was src/anon/tiny_auto80_queue.cpp)
namespace n00222a00 {
void func_002229a0(...) asm("func_002229a0");
void sceVu0SubVector(...) asm("sceVu0SubVector");
/*TARGET 00222a00*/
void func_00222a00(u32 a0, u32 a1) asm("_Z13func_00222a00jj");
void func_00222a00(u32 a0, u32 a1) {
    V4_222a00 tmp;
    sceVu0SubVector((u32)&tmp, a0, a1);  // vec4_sub
    (void)func_002229a0((u32)&tmp);  // vec3_length
}
}  // namespace n00222a00


// u16 index free list
namespace n00222a30 {
struct IdxList { u16* tab; u16 n; u16 head; };
u16 func_00222a30(IdxList* l) asm("func_00222a30");
u16 func_00222a30(IdxList* l) { u16 h = l->head; if (h == 0xffff) return 0xffff; l->head = l->tab[h]; return h; }
void func_00222a60(IdxList* l, u16* tab, u16 n) asm("func_00222a60");
void func_00222a60(IdxList* l, u16* tab, u16 n) {
    l->n = n; l->head = 0; l->tab = tab;
    for (u16 i = 1; i < n; i++) *tab++ = i;
    *tab = 0xffff;
}
}  // namespace n00222a30
