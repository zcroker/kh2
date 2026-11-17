// Linked unit 0x194790-0x195c80 (YS, after the previous file's I/D stubs at 0x194750/0x194770):
// area info, battle camera data, queue/solver wrappers, the climb/ledge test (0x1958d0).
// Gap functions written: 0x1949f8, 0x195318, 0x195778 (C2 copy of the 0x1957e8 ctor),
// 0x195c08.
// Flags: -G0 -fno-strict-aliasing (old _nsa copies 0x1955a8).
#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/menu_sound.hpp"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"

// ---- 00194790 from src/anon/tiny.cpp
namespace n00194790 {
void func_00194790(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00194790jjjj");
void func_00194790(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x01c6u << 16);
    *(u32*)((u32)b + (6896)) = (u32)a0;
}
}  // namespace n00194790

// ---- 001947a0 from src/anon/tiny_jal_tail_wrappers.cpp
namespace n001947a0 {
u32 func_00194980() asm("_Z13func_00194980v");
u32 func_00194930() asm("_Z13func_00194930v");
u32 func_001947a0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001947a0jjjj");
u32 func_001947a0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u;
    r15 = (u32)(0x01c6u << 16);
    *(u8*)((u32)r15 + (s32)(6901)) = (u8)0u;
    r2 = func_00194980();
    return func_00194930();
}
}  // namespace n001947a0

// ---- 001947c0 from src/anon/batch_w46.cpp
namespace n001947c0 {
u8* ctarget_001947c0(s32 a, s32 b, u32, u32) asm("_Z16ctarget_001947c0jjjj");
struct E194 { u16 n; u16 off; };
struct T194 { u32 pad; s32 n; E194 e[1]; };
extern u8 D_0032bae0 asm("D_0032bae0");
extern T194* D_01c61af0 asm("D_01c61af0");
u8* ctarget_001947c0(s32 a, s32 b, u32, u32) {
    u8* g = &D_0032bae0;
    if (a < 0) a = g[1];
    if (b < 0) b = g[0];
    if (b >= 0) {
        T194* t = D_01c61af0;
        if (b < t->n && a >= 0 && a < t->e[b].n) return (u8*)t + t->e[b].off + a * 64;
    }
    return 0;
}
}  // namespace n001947c0

// ---- 00194830 from src/anon/batch_w25.cpp
namespace n00194830 {
u32 u_call4_00194830(u32, u32, u32, u32) asm("_Z16u_call4_00194830jjjj");
u32* func_001947c0(u32, u32, u32, u32) asm("func_001947c0");
u32 u_call4_00194830(u32 a, u32 b, u32 c, u32 d) {
    u32* r = func_001947c0(a, b, c, d);
    if (r) {
        if (*r & (1 << c)) return 1;
        return 0;
    }
    return 0;
}
}  // namespace n00194830

// ---- 00194878 from src/anon/tiny_auto80_fptr4.cpp
namespace n00194878 {
u32 func_00194830(u32, u32, u32, u32) asm("_Z13func_00194830jjjj");
u32 func_00194878(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00194878jjjj");
u32 func_00194878(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r6 = 0u;
    u32 (*fp_call4_00194830)(u32, u32, u32, u32) = func_00194830;
    r2 = fp_call4_00194830(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00194878

// ---- 00194898 from src/anon/tiny_auto80_fptr4.cpp
namespace n00194898 {
u32 func_00194830(u32, u32, u32, u32) asm("_Z13func_00194830jjjj");
u32 func_00194898(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00194898jjjj");
u32 func_00194898(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r4 = (u32)((s32)0u + (-1));
    r5 = (u32)((s32)0u + (-1));
    r6 = (u32)((s32)0u + (1));
    u32 (*fp_call4_00194830)(u32, u32, u32, u32) = func_00194830;
    r2 = fp_call4_00194830(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00194898

// ---- 001948c0 from src/anon/tiny_auto80_fptr4.cpp
namespace n001948c0 {
u32 func_00194830(u32, u32, u32, u32) asm("_Z13func_00194830jjjj");
u32 func_001948c0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001948c0jjjj");
u32 func_001948c0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r6 = (u32)((s32)0u + (2));
    u32 (*fp_call4_00194830)(u32, u32, u32, u32) = func_00194830;
    r2 = fp_call4_00194830(r4, r5, r6, r7);
    return r2;
}
}  // namespace n001948c0

// ---- 001948e0 from src/anon/tiny_auto80_fptr4.cpp
namespace n001948e0 {
u32 func_00194830(u32, u32, u32, u32) asm("_Z13func_00194830jjjj");
u32 func_001948e0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001948e0jjjj");
u32 func_001948e0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r4 = (u32)((s32)0u + (-1));
    r5 = (u32)((s32)0u + (-1));
    r6 = (u32)((s32)0u + (3));
    u32 (*fp_call4_00194830)(u32, u32, u32, u32) = func_00194830;
    r2 = fp_call4_00194830(r4, r5, r6, r7);
    return r2;
}
}  // namespace n001948e0

// ---- 00194908 from src/anon/tiny_auto80_fptr4.cpp
namespace n00194908 {
u32 func_00194830(u32, u32, u32, u32) asm("_Z13func_00194830jjjj");
u32 func_00194908(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00194908jjjj");
u32 func_00194908(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r4 = (u32)((s32)0u + (-1));
    r5 = (u32)((s32)0u + (-1));
    r6 = (u32)((s32)0u + (4));
    u32 (*fp_call4_00194830)(u32, u32, u32, u32) = func_00194830;
    r2 = fp_call4_00194830(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00194908

// ---- 00194930 from src/anon/batch_w50.cpp
namespace n00194930 {
extern u8 D_0032bae0[] asm("D_0032bae0");
extern u8 D_0032bb30[] asm("D_0032bb30");
u8* func_001947c0(u32, u32) asm("func_001947c0");
void func_001a9110(void*) asm("func_001a9110");
void func_00194930(void) asm("func_00194930");
void func_00194930(void) {
    u8* v = func_001947c0(D_0032bae0[1], D_0032bae0[0]);
    func_001a9110(v + D_0032bb30[D_0032bae0[0] + 9196] * 4 + 16);
}
}  // namespace n00194930

// ---- 00194980 from src/anon/batch_w2363.cpp
namespace n00194980 {
struct Entry2363 { u8 pad[50]; u16 id; };
extern u8 D_01c61af4 asm("D_01c61af4");
Entry2363* ctarget_001947c0_w2363(s32 a, s32 b) asm("_Z16ctarget_001947c0jjjj");
s32 has_ansem_entry_w2363(u32 id) asm("_ZN2Tz6JmInfo13HasAnsemEntryEj");
void ctarget0_00194980(void) asm("_Z17ctarget0_00194980v");
void ctarget0_00194980(void)
{
    u8 found = 0;
    Entry2363* e = ctarget_001947c0_w2363(-1, -1);
                                                                            
    while (e->id != 0 && has_ansem_entry_w2363(e->id) > 0) {
        found = 1;
        break;
    }
    D_01c61af4 = found;
}
}  // namespace n00194980

// ---- 001949d0 from src/anon/auto200_999.cpp
namespace n001949d0 {
extern u8 D_01c61af4 asm("D_01c61af4");
extern u8 D_01c61af5 asm("D_01c61af5");
u32 func_001949d0() asm("_Z13func_001949d0v");
u32 func_001949d0() {
    u32 ret = 0;
    if (D_01c61af4 != 0) {
        ret = D_01c61af5 < 1;
    }
    return ret;
}
}  // namespace n001949d0

// ---- 001949f8 gap: set flag byte 0x1c61af5
namespace n001949f8 {
extern u8 D_01c61af5 asm("D_01c61af5");
void func_001949f8() asm("func_001949f8");
void func_001949f8() { D_01c61af5 = 1; }
}  // namespace n001949f8

// ---- 00194a08 from src/anon/tiny_jal_wrappers.cpp
namespace n00194a08 {
u32 func_001947c0(u32, u32, u32, u32) asm("_Z13func_001947c0jjjj");
u32 func_00194a08(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00194a08jjjj");
u32 func_00194a08(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r4 = (u32)((s32)0u + (-1));
    r5 = (u32)((s32)0u + (-1));
    r2 = func_001947c0(r4, r5, r6, r7);
    r2 = (u32)(*(u8*)((u32)r2 + (s32)(52)));
    return r2;
}
}  // namespace n00194a08

// ---- 00194a30 from src/anon/batch_wcx2.cpp
namespace n00194a30 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14;
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
struct V2e8d08 {
    f32 x, y, z, w;
    V2e8d08() {}
    V2e8d08& operator=(const V2e8d08& o) { if (this != &o) QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct BarEnt194a30 { u32 f0; u32 f4; void* data; };
void* func_001b1490__194a30(void*) asm("func_001b1490");
BarEnt194a30* func_00168b88__194a30(void*, s32, s32, s32) asm("func_00168b88");
BarEnt194a30* func_00168b38__194a30(void*, s32, s32) asm("func_00168b38");
void func_00264318__194a30(void*) asm("func_00264318");
extern void* D_0034f248 asm("D_0034f248");
extern void* D_0034f24c asm("D_0034f24c");
extern void* D_01c61af8 asm("D_01c61af8");
extern void* D_01c61afc asm("D_01c61afc");
void func_00185880__194a30(void*) asm("func_00185880");
void func_00185910__194a30(void*) asm("func_00185910");
void func_00194790__194a30(void*) asm("func_00194790");
void func_0019fe80__194a30(void*) asm("func_0019fe80");
void func_001a5b58__194a30(void*) asm("func_001a5b58");
void func_001a6648__194a30(void*) asm("func_001a6648");
void func_001a8098__194a30(void*) asm("func_001a8098");
void func_001a81e0__194a30(void*) asm("func_001a81e0");
void func_001a8908__194a30(void*) asm("func_001a8908");
void func_001a97e8__194a30(void*) asm("func_001a97e8");
void func_001afa30__194a30(void*) asm("func_001afa30");
void func_001b1e58__194a30(void*) asm("func_001b1e58");
void func_001b6fa0__194a30(void*) asm("func_001b6fa0");
void func_001b8e78__194a30(void*) asm("func_001b8e78");
void func_001c0638__194a30(void*) asm("func_001c0638");
void func_001c09f0__194a30(void*) asm("func_001c09f0");
void func_001c0c70__194a30(void*) asm("func_001c0c70");
void func_001c20d8__194a30(void*) asm("func_001c20d8");
void func_001c2d38__194a30(void*) asm("func_001c2d38");
void func_001c2d78__194a30(void*) asm("func_001c2d78");
void func_001ce1a0__194a30(void*) asm("func_001ce1a0");
void func_001d23d0__194a30(void*) asm("func_001d23d0");
void func_001d30b0__194a30(void*) asm("func_001d30b0");
void func_001d3c08__194a30(void*) asm("func_001d3c08");
void func_001d5030__194a30(void*) asm("func_001d5030");
void func_001d5b68__194a30(void*) asm("func_001d5b68");
void func_001d6cb8__194a30(void*) asm("func_001d6cb8");
void func_001d7970__194a30(void*) asm("func_001d7970");
void func_001d7eb8__194a30(void*) asm("func_001d7eb8");
void func_001db598__194a30(void*) asm("func_001db598");
extern char D_0036cf28[] asm("D_0036cf28");
extern char D_0036cf30[] asm("D_0036cf30");
extern char D_0036cf38[] asm("D_0036cf38");
extern char D_0036cf40[] asm("D_0036cf40");
extern char D_0036cf48[] asm("D_0036cf48");
extern char D_0036cf50[] asm("D_0036cf50");
extern char D_0036cf58[] asm("D_0036cf58");
extern char D_0036cf60[] asm("D_0036cf60");
extern char D_0036cf68[] asm("D_0036cf68");
extern char D_0036cf70[] asm("D_0036cf70");
extern char D_0036cf78[] asm("D_0036cf78");
extern char D_0036cf80[] asm("D_0036cf80");
extern char D_0036cf88[] asm("D_0036cf88");
extern char D_0036cf90[] asm("D_0036cf90");
extern char D_0036cf98[] asm("D_0036cf98");
extern char D_0036cfa0[] asm("D_0036cfa0");
extern char D_0036cfa8[] asm("D_0036cfa8");
extern char D_0036cfb0[] asm("D_0036cfb0");
extern char D_0036cfb8[] asm("D_0036cfb8");
extern char D_0036cfc0[] asm("D_0036cfc0");
extern char D_0036cfc8[] asm("D_0036cfc8");
extern char D_0036cfd0[] asm("D_0036cfd0");
extern char D_0036cfd8[] asm("D_0036cfd8");
extern char D_0036cfe0[] asm("D_0036cfe0");
extern char D_0036cfe8[] asm("D_0036cfe8");
extern char D_0036cff0[] asm("D_0036cff0");
extern char D_0036cff8[] asm("D_0036cff8");
extern char D_0036d000[] asm("D_0036d000");
extern char D_0036d008[] asm("D_0036d008");
extern char D_0036d010[] asm("D_0036d010");
static inline s32 Tag194a30(char* s) { return s[0] | (s[1] << 8) | (s[2] << 16) | (s[3] << 24); }
void func_00194a30(void) asm("func_00194a30");
void func_00194a30(void)
{
    void* b;
    BarEnt194a30* e;
    D_01c61af8 = b = func_001b1490__194a30(D_0034f248);
    func_001ce1a0__194a30(func_00168b88__194a30(b, 1, Tag194a30(D_0036cf28), 0)->data);
    func_001d23d0__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cf30), 0)->data);
    func_001b8e78__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cf38), 0)->data);
    func_00185880__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cf40), 0)->data);
    func_00185910__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cf48), 0)->data);
    func_00194790__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cf50), 0)->data);
    func_001a8098__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cf58), 0)->data);
    func_001a81e0__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cf60), 0)->data);
    func_001a8908__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cf68), 0)->data);
    func_001a97e8__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cf70), 0)->data);
    func_001b1e58__194a30(func_00168b88__194a30(b, 25, Tag194a30(D_0036cf78), 0)->data);
    e = func_00168b38__194a30(b, 41, 0);
    if (e && e->data) func_00264318__194a30(e->data);
    func_001c2d38__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cf80), 0)->data);
    func_001d30b0__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cf88), 0)->data);
    D_01c61afc = b = func_001b1490__194a30(D_0034f24c);
    func_0019fe80__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cf90), 0)->data);
    func_001d7eb8__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cf98), 0)->data);
    func_001db598__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cfa0), 0)->data);
    func_001a5b58__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cfa8), 0)->data);
    func_001afa30__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cfb0), 0)->data);
    func_001b6fa0__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cfb8), 0)->data);
    func_001c0638__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cfc0), 0)->data);
    func_001c09f0__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cfc8), 0)->data);
    func_001c0c70__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cfd0), 0)->data);
    func_001c20d8__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cfd8), 0)->data);
    func_001c2d78__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cfe0), 0)->data);
    func_001d3c08__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cfe8), 0)->data);
    func_001d6cb8__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cff0), 0)->data);
    func_001a6648__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cff8), 0)->data);
    func_001d5030__194a30(func_00168b88__194a30(b, 1, Tag194a30(D_0036d000), 0)->data);
    func_001d5b68__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036d008), 0)->data);
    func_001d7970__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036d010), 0)->data);
}
}  // namespace n00194a30

// ---- 00195318 gap: read word 0x1c61af8
namespace n00195318 {
extern u32 D_01c61af8 asm("D_01c61af8");
u32 func_00195318() asm("func_00195318");
u32 func_00195318() { return D_01c61af8; }
}  // namespace n00195318

// ---- 00195328 from src/anon/tiny_auto80_queue.cpp
namespace n00195328 {
u32 func_00168b38(...) asm("func_00168b38");
u32 func_00195328(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00195328jjjjjjjj");
u32 func_00195328(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r15 = (u32)(0x01c6u << 16);
    r6 = r4;
    r5 = (u32)((s32)0u + (22));
    r4 = *(volatile u32*)((u32)r15 + (s32)(6908));
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00168b38)(r4, r5, r6, r7, r8, r9, r10, r11);
    r15 = 0u;
    if (r2 != 0u) {
        r15 = *(volatile u32*)((u32)r2 + (s32)(8));
    }
    r2 = r15;
    return r2;
}
}  // namespace n00195328

// ---- 00195360 from src/anon/batch_w2376.cpp
namespace n00195360 {
struct Rec_195360 { u8 pad[8]; s32 v; };
struct Pair_195360 { s32 a, b; };
Rec_195360* func_00168b88(s32, s32, s32, s32) asm("func_00168b88");
extern s32 D_01c61afc asm("D_01c61afc");
extern s8 D_0036d018[] asm("D_0036d018");
static inline s32 tag_195360(const s8* s) { return s[0] | (s[1] << 8) | (s[2] << 16) | (s[3] << 24); }
static inline Rec_195360* find_195360(s32 g, s32 id) { return func_00168b88(g, id, tag_195360(D_0036d018), 0); }
void func_00195360(Pair_195360* out) asm("func_00195360");
void func_00195360(Pair_195360* out) {
    Rec_195360* a = find_195360(D_01c61afc, 0x18);
    Rec_195360* b = find_195360(D_01c61afc, 0x19);
    s32 x = a->v; s32 y = b->v;
    out->a = x; out->b = y;
}
}  // namespace n00195360

// ---- 00195430 from src/anon/tiny_auto80_queue.cpp
namespace n00195430 {
void func_00195430(u32 a0) asm("_Z13func_00195430j");
void func_00195430(u32 a0) {
    u32 t7 = (u32)-1;
    *(u32*)((u32)a0 + (s32)(4)) = 0u;
    *(u32*)((u32)a0 + (s32)(0)) = t7;
    u32 t6 = 255u;
    t7 = (u32)((s32)a0 + (8));
L0:
    *(u16*)((u32)t7 + (s32)(0)) = 0u;
    t6 = (u32)((s32)t6 + (-1));
    if ((s32)t6 >= 0) {
        t7 = (u32)((s32)t7 + (2));
        goto L0;
    }
}
}  // namespace n00195430

// ---- 00195468 from src/anon/batch_w22.cpp
namespace n00195468 {
s32 ctarget_00195468(u32, u32, u32, u32) asm("_Z16ctarget_00195468jjjj");
s32 ctarget_00195468(u32 a, u32 key, u32, u32) {
    s16* q = (s16*)(a + 8);
    for (s32 i = 0; i < 256; i++) {
        if (q[i] == (s32)key) return i;
    }
    return -1;
}
}  // namespace n00195468

// ---- 001954a0 from src/anon/batch_w27.cpp
namespace n001954a0 {
void wtarget_001954a0(u32, u32, u32, u32) asm("_Z16wtarget_001954a0jjjj");
s32 func_00195530(void*) asm("func_00195530");
s32 func_00195468(void*, u32) asm("func_00195468");
void wtarget_001954a0(u32 a, u32 b, u32, u32) {
    u8* p = (u8*)a;
    if (func_00195530(p) == 0) {
        s32 i = func_00195468(p, 0);
        if (i >= 0) *(u16*)(p + i * 2 + 8) = b;
    }
}
}  // namespace n001954a0

// ---- 001954f8 from src/anon/tiny_auto80_queue.cpp
namespace n001954f8 {
u32 func_00195468(...) asm("func_00195468");
void func_001954f8(u32 a0, u32 a1) asm("_Z13func_001954f8jj");
void func_001954f8(u32 a0, u32 a1) {
    u32 s0 = a0;
    s32 v0 = (s32)func_00195468(a0, a1);
    if (v0 >= 0) {
        u32 t7 = (u32)((u32)v0 << 1);
        t7 = (u32)(t7 + s0);
        *(u16*)((u32)t7 + (s32)(8)) = 0u;
    }
}
}  // namespace n001954f8

// ---- 00195530 from src/anon/tiny_jal_wrappers.cpp
namespace n00195530 {
u32 func_00195468(u32, u32, u32, u32) asm("_Z13func_00195468jjjj");
u32 func_00195530(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00195530jjjj");
u32 func_00195530(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_00195468(r4, r5, r6, r7);
    r2 = (u32)(~(0u | r2));
    r2 = (u32)(r2 >> 31);
    return r2;
}
}  // namespace n00195530

// ---- 00195558 from src/anon/batch_w52.cpp
namespace n00195558 {
void func_00195430(u8*) asm("func_00195430");
void func_00195558(u8* p) asm("func_00195558");
void func_00195558(u8* p) {
    u8* q;
    for (q = p; (s32)q < (s32)(p + 2080); q += 520) func_00195430(q);
    *(u32*)(p + 2084) = 0;
}
}  // namespace n00195558

// ---- 001955a8 from src/anon/batch_w1832_nsa.cpp
namespace n001955a8 {
struct Entry1832 { s32 id; s32 time; u8 pad[0x200]; };
struct Cache1832 { Entry1832 e[4]; Entry1832* cur; s32 counter; };
extern u8 D_0032bae1 asm("D_0032bae1");
void func_00195430(Entry1832*) asm("func_00195430");
void func_001955a8(Cache1832* c, s32 range) asm("func_001955a8");
void func_001955a8(Cache1832* c, s32 range) {
    Entry1832* e = c->e;
    Entry1832* found = 0;
    Entry1832* lru = c->e;
    u8 id = D_0032bae1;
    s32 i;
    c->cur = 0;
    for (i = 3; i >= 0; i--, e++) {
        if (e->id == id && e->time >= c->counter - range && (found == 0 || found->time < e->time)) {
            c->cur = e;
            found = e;
        }
        if (e->id < 0 || (lru->id >= 0 && e->time < lru->time)) lru = e;
    }
    if (found == 0) {
        c->cur = lru;
        func_00195430(lru);
        c->cur->id = id;
        found = c->cur;
    } else {
        for (i = 0; i < 4; i++) {
            if (c->e[i].time < found->time) { c->e[i].time++; found = c->cur; }
        }
    }
    found->time = c->counter++;
}
}  // namespace n001955a8

// ---- 001956d0 from src/anon/tiny_wrappers_more.cpp
namespace n001956d0 {
u32 func_001954a0(u32, u32, u32, u32) asm("_Z13func_001954a0jjjj");
u32 func_001956d0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001956d0jjjj");
u32 func_001956d0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001954a0(((u32)(*(u32*)((u32)(a0) + 2080u))), a1, a2, a3);
}
}  // namespace n001956d0

// ---- 001956e8 from src/anon/tiny_wrappers_more.cpp
namespace n001956e8 {
u32 func_001954f8(u32, u32, u32, u32) asm("_Z13func_001954f8jjjj");
u32 func_001956e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001956e8jjjj");
u32 func_001956e8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001954f8(((u32)(*(u32*)((u32)(a0) + 2080u))), a1, a2, a3);
}
}  // namespace n001956e8

// ---- 00195700 from src/anon/tiny_auto80_fptr4.cpp
namespace n00195700 {
u32 func_00195530(u32, u32, u32, u32) asm("_Z13func_00195530jjjj");
u32 func_00195700(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00195700jjjj");
u32 func_00195700(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r4 = *(u32*)((u32)r4 + (s32)(2080));
    u32 (*fp_call4_00195530)(u32, u32, u32, u32) = func_00195530;
    r2 = fp_call4_00195530(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00195700

// ---- 00195720 from src/anon/tiny_wrappers_more.cpp
namespace n00195720 {
u32 func_00195430(u32, u32, u32, u32) asm("_Z13func_00195430jjjj");
u32 func_00195720(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00195720jjjj");
u32 func_00195720(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00195430(((u32)(*(u32*)((u32)(a0) + 2080u))), a1, a2, a3);
}
}  // namespace n00195720

// ---- 00195738 from src/anon/tiny.cpp
namespace n00195738 {
void func_00195750(void*) asm("_Z13func_00195750Pv");
void func_00195738(BD_VALUE* bd) asm("_Z13func_00195738P8BD_VALUE");
void func_00195738(BD_VALUE* bd) { func_00195750(bd); }
}  // namespace n00195738

// ---- 00195750 from src/anon/batch_w2.cpp
namespace n00195750 {
extern u8 D_0034f250[] asm("D_0034f250");
extern u8 D_0034fa78[] asm("D_0034fa78");
void func_00195558(void*) asm("func_00195558");
void func_00195750(void) asm("func_00195750");
void func_00195750(void) {
    func_00195558(D_0034f250);
    func_00195558(D_0034fa78);
}
}  // namespace n00195750

// ---- 00195778 gap: C2 copy of the ctor at 0x1957e8
namespace n00195778 {
union U195 { u8* p; f32 f; };
extern U195 D_00352130 asm("D_00352130");
void func_00195778(f32* p) asm("func_00195778");
void func_00195778(f32* p) {
    p[0] = 2.0f;
    p[1] = 8.0f;
    p[2] = 160.0f;
    p[3] = 0.19634955f;
    p[4] = *(f32*)(D_00352130.p + 20);
    p[6] = 0.95f;
    p[5] = 0;
    p[7] = 0;
    p[8] = 0;
}
}  // namespace n00195778

// ---- 001957e8 from src/anon/batch_w40.cpp
namespace n001957e8 {
union U195 { u8* p; f32 f; };
extern U195 D_00352130 asm("D_00352130");
void func_001957e8(f32* p) asm("func_001957e8");
void func_001957e8(f32* p) {
    p[0] = 2.0f;
    p[1] = 8.0f;
    p[2] = 160.0f;
    p[3] = 0.19634955f;
    p[4] = *(f32*)(D_00352130.p + 20);
    p[6] = 0.95f;
    p[5] = 0;
    p[7] = 0;
    p[8] = 0;
}
}  // namespace n001957e8

// ---- 00195858 from src/anon/batch_w48.cpp
namespace n00195858 {
f32* func_001ce328(u32) asm("_Z13func_001ce328j");
u32 func_001ce2d8(u32) asm("_Z13func_001ce2d8j");
void u_call4_00195858(u32 a0, u32 a1, u32, u32) asm("_Z16u_call4_00195858jjjj");
void u_call4_00195858(u32 a0, u32 a1, u32, u32) {
    f32* o = (f32*)a0;
    *(f32**)(o + 7) = func_001ce328(a1);
    *(f32**)(o + 8) = (f32*)func_001ce2d8(a1);
    asm volatile("" ::: "memory");
    f32* m = *(f32**)(o + 7);
    o[0] = m[0];
    o[1] = m[1];
    o[2] = m[2];
    o[3] = m[3];
    o[5] = m[8];
    o[6] = m[10];
}
}  // namespace n00195858

// ---- 001958d0 from src/anon/batch_w1618.cpp
namespace n001958d0 {
struct W1618V {
    f32 x, y, z, w;
    W1618V() {}
    W1618V(const W1618V& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1618V& operator=(const W1618V& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    W1618V operator-(const W1618V& b) const {
        W1618V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    W1618V operator+(const W1618V& b) const {
        W1618V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    W1618V operator*(f32 s) const {
        W1618V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "f"(s) : "$8", "memory");
        return r;
    }
    f32 length() const {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
    f32 normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));

struct W1618Box {
    f32 mn[3];
    f32 mx[3];
    W1618Box();
};

// Climb/ledge parameters (pointer at obj+0x12c).
struct W1618Ledge { u8 pad[0x10]; f32 drop; f32 minHeight; };
// Collision body at obj+0x590.
struct W1618Body { u8 pad[0x20]; f32 radius; };
// Global collision settings (D_00352130).
struct W1618Cfg { u8 pad[8]; f32 below; f32 above; f32 margin; };
struct W1618Flags { u64 lo:33; u64 noStep:1; u64 hi:30; };

struct W1618Obj;
struct W1618Obj {
    bool canStep() const { return !f600.noStep; }
    u8 pad0[0x10c];
    u32 flags;
    u8 pad110[0x12c - 0x110];
    W1618Ledge* ledge;
    u8 pad130[0x590 - 0x130];
    W1618Body body;
    u8 pad5b4[0x600 - 0x5b4];
    W1618Flags f600;
    u8 pad608[0xb34 - 0x608];
    u8 colB34[4];
};

// BGM slot table at 0x347d30 (16 bytes per slot).
struct W1618Bgm { s32 f0; s32 id; s32 vol; u32 flags; };
// Sequence/stream request filled from a slot.
struct W1618Req { u32 f0; s32 handle; s32 id; s32 slot; void* alloc; };

extern W1618Cfg* D_00352130 asm("D_00352130");
void W1618Box_init(W1618Box*) asm("_ZN2dk6Aabbox4initEv");
void W1618Box_set(W1618Box*, f32, f32, f32, f32, f32, f32) asm("_ZN2dk6Aabbox3setEffffff");
W1618V* func_0016c028(W1618Obj*) asm("func_0016c028");
W1618V func_0016af58(W1618Obj*) asm("func_0016af58");
s32 func_00143470(W1618V*, W1618Box*, W1618V*, W1618V*, W1618V*, W1618V*, u8*) asm("func_00143470");
f32 W1618_get_step_height(W1618Obj*) asm("_ZN2YS3OBJ15get_step_heightEv");
bool func_0019bfd0(W1618Obj*, const W1618V&) asm("func_0019bfd0");
void W1618_set_dir(W1618Obj*, const W1618V&) asm("_ZN2YS3OBJ7set_dirERKN2kn7FVectorE");
void W1618_set_pos(W1618Obj*, const W1618V&) asm("_ZN2YS3OBJ7set_posERKN2kn7FVectorE");
void W1618_change_action(W1618Obj*, s32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
inline W1618Box::W1618Box() { W1618Box_init(this); }
bool func_001958d0(W1618Obj* o) asm("func_001958d0");
bool func_001958d0(W1618Obj* o) {
    W1618V pos;
    W1618V hit;
    W1618V d;
    W1618V dir;
    W1618V ea;
    W1618V eb;
    W1618Box box;
    W1618Ledge* l = o->ledge;
    if (!l || l->minHeight == 0.0f || (o->flags & 0x4000)) return 0;
    f32 drop = l->drop;
    W1618Body* b = &o->body;
    f32 r = b->radius + D_00352130->margin;
    pos = *func_0016c028(o);
    pos.y -= drop;
    W1618Box_set(&box, pos.x - r, pos.y - D_00352130->below, pos.z - r,
                 pos.x + r, pos.y + D_00352130->above, pos.z + r);
    dir = func_0016af58(o);
    if (!func_00143470(&pos, &box, &hit, &ea, &eb, &dir, o->colB34)) return 0;
    if (hit.y < box.mn[1] || box.mx[1] < hit.y) return 0;
    if (o->canStep()) {
        if (W1618_get_step_height(o) - hit.y < l->minHeight) return 0;
    }
    d = hit - pos;
    d.y = 0.0f;
    if (r < d.length()) return 0;
    d = eb - ea;
    d.y = 0.0f;
    d.normalize();
    dir.x = -d.z;
    dir.y = 0.0f;
    dir.z = d.x;
    d = dir * -b->radius;
    d.y = drop;
    if (!func_0019bfd0(o, hit + d)) return 0;
    W1618_set_dir(o, dir);
    W1618_set_pos(o, hit + d);
    W1618_change_action(o, 2);
    return 1;
}
}  // namespace n001958d0

// ---- 00195c08 gap
namespace n00195c08 {
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
void func_00158f40() asm("func_00158f40");
void func_00195c08(u8*, u8* o) asm("func_00195c08");
void func_00195c08(u8*, u8* o) {
    func_0017f488(o + 320, 7, 0.0f, 0.0f);
    if (*(u32*)(o + 1416) & 0x80) func_00158f40();
}
}  // namespace n00195c08

// ---- 00195c58 from src/anon/batch_w1727.cpp
namespace n00195c58 {
void func_00158f90(void*) asm("func_00158f90");
void func_00195c58(void* a0, u8* a1) asm("func_00195c58");
void func_00195c58(void* a0, u8* a1) {
    if (*(u32*)(a1 + 0x588) & 0x80) func_00158f90(a0);
}
}  // namespace n00195c58

