// Linked unit 0x001614a8-0x00163898.
#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "../harata/libdk/camera.hpp"
#include "../common/task.hpp"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"

// 001614a8: C2 constructor copy (same body as the C1 at 0x1614e8)
namespace n001614a8 {
// 00158050: moved to src/anon/unit_00158050.cpp

void func_00144450(void*) asm("func_00144450");
void func_001616d8(void*) asm("func_001616d8");
/*TARGET 001614e8*/
void func_001614a8(u8* p, u32 v) asm("func_001614a8");
void func_001614a8(u8* p, u32 v) {
    *(u32*)(p + 68) = v;
    *(u32*)(p + 64) = 0;
    *(u32*)(p + 72) = 0;
    *(u32*)(p + 76) = 0;
    *(u32*)(p + 80) = 0;
    func_00144450(p + 84);
    func_001616d8(p);
}
}  // namespace n001614a8

// 001614e8 (was src/anon/batch_w15.cpp)
namespace n001614e8 {
// 00158050: moved to src/anon/unit_00158050.cpp

void func_00144450(void*) asm("func_00144450");
void func_001616d8(void*) asm("func_001616d8");
/*TARGET 001614e8*/
void func_001614e8(u8* p, u32 v) asm("func_001614e8");
void func_001614e8(u8* p, u32 v) {
    *(u32*)(p + 68) = v;
    *(u32*)(p + 64) = 0;
    *(u32*)(p + 72) = 0;
    *(u32*)(p + 76) = 0;
    *(u32*)(p + 80) = 0;
    func_00144450(p + 84);
    func_001616d8(p);
}
}  // namespace n001614e8

// 00161528 (was gap)
namespace g00161528 {
void f(void) asm("func_00161528");
void f(void) {}
}  // namespace g00161528

// 00161530 (was src/anon/tiny.cpp)
namespace n00161530 {
/*TARGET 00161530*/
// 0x0015b770: definition moved into src/anon/unit_0015b100.cpp

// 0015ce80: moved to src/anon/unit_0015cdb0.cpp

// 0015ce90: moved to src/anon/unit_0015cdb0.cpp

// 0015f268: moved to src/harata/libdk/map_effect.cpp

// 0015f288: moved to src/harata/libdk/map_effect.cpp

// 001604f0: moved to src/harata/libdk/bgobj.cpp

// 00160d18: moved to src/harata/libdk/bgobj.cpp

// 00160d28: moved to src/harata/libdk/bgobj.cpp

// 00161228: moved to src/anon/unit_001611a8.cpp

void func_00161530(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00161530jjjj");
// 0x0015b770: definition moved into src/anon/unit_0015b100.cpp

// 0015ce80: moved to src/anon/unit_0015cdb0.cpp

// 0015ce90: moved to src/anon/unit_0015cdb0.cpp

// 0015f268: moved to src/harata/libdk/map_effect.cpp

// 0015f288: moved to src/harata/libdk/map_effect.cpp

// 001604f0: moved to src/harata/libdk/bgobj.cpp

// 00160d18: moved to src/harata/libdk/bgobj.cpp

// 00160d28: moved to src/harata/libdk/bgobj.cpp

// 00161228: moved to src/anon/unit_001611a8.cpp

void func_00161530(u32 a0, u32 a1, u32 a2, u32 a3) {  // noop_ret_b
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n00161530

// 00161538 (was gap)
namespace g00161538 {
void f(u8* p) asm("func_00161538");
void f(u8* p) { *(u32*)(p + 76) = 0; }
}  // namespace g00161538

// 00161540 (was src/anon/misc_1.cpp)
namespace n00161540 {
/*TARGET 00161540*/
// 0x0014f200: definition moved into src/anon/unit_0014ecb8.cpp

void func_00161540(void* self, s32 v) asm("_Z13func_00161540Pvi");
// 0x0014f200: definition moved into src/anon/unit_0014ecb8.cpp

void func_00161540(void* self, s32 v) { *(s32*)((char*)self + 64) = v; }
}  // namespace n00161540

// 00161548 (was src/anon/batch_w2362.cpp)
namespace n00161548 {
struct Res { u32 a, b; s32 v; };
struct Holder { u8 pad[0x40]; void* tbl; };
// scan_list_by_half
Res* func_00168b38(void*, s32, s32) asm("func_00168b38");
/*TARGET 00161548*/
// 0x0016ac38: definition moved into src/anon/unit_00169f98.cpp

// 00192450: moved to src/yasui/libys/message.cpp

// Looks up entry n (kind 9) in the holder's table and returns its value, 0 if none.
s32 func_00161548(Holder* h, s32 n) asm("func_00161548");
// 0x0016ac38: definition moved into src/anon/unit_00169f98.cpp

// 00192450: moved to src/yasui/libys/message.cpp

// Looks up entry n (kind 9) in the holder's table and returns its value, 0 if none.
s32 func_00161548(Holder* h, s32 n) {
    Res* r;
    if (n < 0 || !h->tbl) return 0;
    r = func_00168b38(h->tbl, 9, n);
    if (!r) return 0;
    return r->v;
}
}  // namespace n00161548

// 00161598 (was src/anon/batch_w34.cpp)
namespace n00161598 {
void func_0011c4e8(u32, void*, u32, u32, u32, u32, f32) asm("func_0011c4e8");
void func_0011c4b0(u32, void*) asm("func_0011c4b0");
/*TARGET 00161598*/
// 0x0015c450: definition moved into src/anon/unit_0015bab8.cpp

void func_00161598(u8* p) asm("func_00161598");
// 0x0015c450: definition moved into src/anon/unit_0015bab8.cpp

void func_00161598(u8* p) {
    u8* o = *(u8**)(p + 68);
    u32 t = *(u32*)(p + 72);
    u32 h = *(u32*)(o + 448);
    if (t) func_0011c4e8(h, o + 512, t, 0, 0, 0, *(f32*)(p + 76));
    else func_0011c4b0(h, o + 512);
}
}  // namespace n00161598

// 001615e8 (was src/anon/batch_w61.cpp)
namespace n001615e8 {
union FU { f32 f; void* p; u32 u; };
// 00108600: moved to src/anon/unit_001085a8.cpp

struct VObj { s32 (**vt)(...); };
// 0x0015aa98: definition moved into src/anon/unit_0015a810.cpp

void* func_00161548(void*) asm("func_00161548");
void func_00161770(void*) asm("func_00161770");
void func_001616d8(void*) asm("func_001616d8");
/*TARGET 001615e8*/
void func_001615e8(u8* p, f32 f) asm("func_001615e8");
void func_001615e8(u8* p, f32 f) {
    VObj* v = (VObj*)func_00161548(p);
    *(VObj**)(p + 72) = v;
    if (v) {
        ((FU*)(p + 76))->f = f;
        *(f32*)(p + 80) = (f32)((s32 (*)(VObj*))v->vt[2])(v);
        func_00161770(p);
        func_001616d8(p);
    }
}
}  // namespace n001615e8

// 00161668 (was src/anon/auto80_199_queue.cpp)
namespace n00161668 {
/*TARGET 00161668*/
// 0x0015b5d8: definition moved into src/anon/unit_0015b100.cpp

// 0015ee90: moved to src/harata/libdk/map.cpp

// 0015f738: moved to src/harata/libdk/map_effect.cpp

// 00160960: moved to src/harata/libdk/bgobj.cpp

void func_00161668(u8* a0, f32 a1) asm("_Z13func_00161668Phf");
// 0x0015b5d8: definition moved into src/anon/unit_0015b100.cpp

// 0015ee90: moved to src/harata/libdk/map.cpp

// 0015f738: moved to src/harata/libdk/map_effect.cpp

// 00160960: moved to src/harata/libdk/bgobj.cpp

void func_00161668(u8* a0, f32 a1) {
    if (*(u32*)(a0 + 72) == 0) {
        return;
    }

    f32 f0 = *(f32*)(a0 + 76) + a1;
    *(f32*)(a0 + 76) = f0;
    func_001616f0((u32)a0, f0);

    f32 f2 = *(f32*)(a0 + 80);
    f32 f1 = *(f32*)(a0 + 76);
    if (f2 < f1) {
        *(f32*)(a0 + 76) = f1 - f2;
        return func_001616f0((u32)a0, f2);
    }
}
}  // namespace n00161668

// 001616d8 (was src/anon/tiny.cpp)
namespace n001616d8 {
void func_0011b6a8(void*) asm("_Z13func_0011b6a8Pv");
/*TARGET 001616d8*/
// 0015ef38: moved to src/harata/libdk/map.cpp
// 0015f6e8: moved to src/harata/libdk/map_effect.cpp
// 0015f700: moved to src/harata/libdk/map_effect.cpp
void func_001616d8(BD_VALUE* bd) asm("_Z13func_001616d8P8BD_VALUE");
// 0015ef38: moved to src/harata/libdk/map.cpp
// 0015f6e8: moved to src/harata/libdk/map_effect.cpp
// 0015f700: moved to src/harata/libdk/map_effect.cpp
void func_001616d8(BD_VALUE* bd) { func_0011b6a8(bd); }
}  // namespace n001616d8

// 001616f0 (was src/anon/batch_w62.cpp)
namespace n001616f0 {
struct u128 { u32 w[4]; } __attribute__((aligned(16)));
// 0015edb8: moved to src/harata/libdk/map.cpp

struct Blk64 {
    u128 q[4];
    void operator=(const Blk64& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
};
struct VObj6 { s32 (**vt)(VObj6*, Blk64*); };
void func_001616d8(Blk64*) asm("func_001616d8");
/*TARGET 001616f0*/
void func_001616f0(Blk64* p) asm("func_001616f0");
void func_001616f0(Blk64* p) {
    Blk64 b;
    VObj6* o = *(VObj6**)((u8*)p + 72);
    if (!o) return;
    if (o->vt[6](o, &b)) {
        func_001616d8(p);
        return;
    }
    *p = b;
}
}  // namespace n001616f0

// 00161770 (was src/anon/batch_w63.cpp)
namespace n00161770 {
void func_001447e0(void*, void*, void*) asm("func_001447e0");
// 0x0015b4f8: definition moved into src/anon/unit_0015b100.cpp

typedef void (*VFn3)(void*, void*, void*);
/*TARGET 00161770*/
void func_00161770(u8* p) asm("func_00161770");
void func_00161770(u8* p) {
    u8 a[16];
    u8 b[16];
    u8* o = *(u8**)(p + 72);
    (*(VFn3*)(*(u8**)o + 20))(o, a, b);
    func_001447e0(p + 84, a, b);
}
}  // namespace n00161770

// 001617c8 (was src/anon/tiny.cpp)
namespace n001617c8 {
extern u32 D_0034c772 asm("D_0034c772");
/*TARGET 001617c8*/
// 0x0014ce78: definition moved into src/anon/unit_0014c7f0.cpp

// 0014dda0: moved to src/anon/unit_0014d680.cpp

// 0014df88: moved to src/anon/unit_0014d680.cpp

// 0015ced0: moved to src/anon/unit_0015cdb0.cpp

// 0015cee0: moved to src/anon/unit_0015cdb0.cpp

// 0015f278: moved to src/harata/libdk/map_effect.cpp

// 00160d38: moved to src/harata/libdk/bgobj.cpp

void func_001617c8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001617c8jjjj");
// 0x0014ce78: definition moved into src/anon/unit_0014c7f0.cpp

// 0014dda0: moved to src/anon/unit_0014d680.cpp

// 0014df88: moved to src/anon/unit_0014d680.cpp

// 0015ced0: moved to src/anon/unit_0015cdb0.cpp

// 0015cee0: moved to src/anon/unit_0015cdb0.cpp

// 0015f278: moved to src/harata/libdk/map_effect.cpp

// 00160d38: moved to src/harata/libdk/bgobj.cpp

void func_001617c8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = (u32)((s32)1);
    *(u8*)&D_0034c772 = (u8)v;
}
}  // namespace n001617c8

// 001617d8 (was src/harata/libdk/camera.cpp)
namespace dk { // method 001617d8
/*TARGET 001617d8*/
void Camera::setNoKick() {
    u32 b = (0x0035u << 16);
    *(u8*)((u32)b + (-14478)) = (u8)0;
}
}  // dk

// 001617e8 (was src/anon/batch_w13.cpp)
namespace n001617e8 {
void func_0014e098(s32) asm("func_0014e098");
void func_001024a8(void*) asm("func_001024a8");
extern void (*D_0035e380[])(void) asm("D_0035e380");
void Camera_onceCover(void*) asm("_ZN2dk6Camera9onceCoverEP4TASK");
/*TARGET 001617e8*/
// 0x001514b0: definition moved into src/anon/unit_0014ecb8.cpp


void Camera_onceCover(void* task) asm("_ZN2dk6Camera9onceCoverEP4TASK");
// 0x001514b0: definition moved into src/anon/unit_0014ecb8.cpp


void Camera_onceCover(void* task) {
    func_0014e098(216);
    func_001024a8(task);
}
}  // namespace n001617e8

// 00161818 (was gap)
namespace g00161818 {
extern u8 D_0034c772 asm("D_0034c772");
u8* func_00102c18(s32, s32, void (*)(void*)) asm("func_00102c18");
void Camera_onceCover(void*) asm("_ZN2dk6Camera9onceCoverEP4TASK");
void func_00109e30(s32) asm("_Z13func_00109e30i");
void func_001617c8(void) asm("func_001617c8");
// Camera kick task: queue the cover task unless kicking is off, then hand the flag on.
void f(void) asm("func_00161818");
void f(void) {
    if (!D_0034c772) func_00102c18(3, 0x16184, Camera_onceCover);
    func_00109e30(D_0034c772);
    func_001617c8();
}
}  // namespace g00161818

// 00161868 (was src/anon/tiny.cpp)
namespace n00161868 {
void func_00109e30(s32) asm("_Z13func_00109e30i");
/*TARGET 00161868*/
// 0x00153140: definition moved into src/anon/unit_0014ecb8.cpp
void func_00161868(BD_VALUE* bd) asm("_Z13func_00161868P8BD_VALUE");
// 0x00153140: definition moved into src/anon/unit_0014ecb8.cpp
void func_00161868(BD_VALUE* bd) { func_00109e30(1); }
}  // namespace n00161868

// 00161880 (was src/anon/tiny_jal_tail_wrappers.cpp)
namespace n00161880 {
u32 func_0010a618() asm("_Z13func_0010a618v");
u32 func_00109e18() asm("_Z13func_00109e18v");
/*TARGET 00161880*/
// 0x0014f268: definition moved into src/anon/unit_0014ecb8.cpp

u32 func_00161880(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00161880jjjj");
// 0x0014f268: definition moved into src/anon/unit_0014ecb8.cpp

u32 func_00161880(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_0010a618();
    return func_00109e18();
}
}  // namespace n00161880

// 001618a0 (was gap)
namespace g001618a0 {
void func_00109e90(void) asm("func_00109e90");
void f(void) asm("func_001618a0");
void f(void) { func_00109e90(); }
}  // namespace g001618a0

// 001618b8 (was src/anon/batch_w17.cpp)
namespace n001618b8 {
extern char D_001dda78[] asm("D_001dda78");
extern u32 D_001ddb30 asm("D_001ddb30");
u8* func_00102c18(u32, u32, const char*) asm("func_00102c18");
/*TARGET 001618b8*/
void dk__Camera__createEffectDestroyTask(void) asm("dk__Camera__createEffectDestroyTask");
void dk__Camera__createEffectDestroyTask(void) {
    u8* v = func_00102c18(1, 0x16b48, D_001dda78);
    *(void**)(v + 48) = &D_001ddb30;
}
}  // namespace n001618b8

// 001618f0 (was src/anon/batch_w85.cpp)
namespace n001618f0 {
void func_001617c8(void) asm("func_001617c8");
void func_00106998(s32) asm("func_00106998");
void func_001069f8(s32) asm("func_001069f8");
u8* func_00102c18(s32, s32, void (*)(void)) asm("func_00102c18");
void func_00161818(void) asm("func_00161818");
void func_001433e8(void) asm("func_001433e8");
void kn__camera_task(void) asm("kn__camera_task");
void func_001dd2b8(void) asm("func_001dd2b8");
void func_00144250(void) asm("func_00144250");
void func_00161880(void) asm("func_00161880");
void func_001618a0(void) asm("func_001618a0");
void func_001dd920(void) asm("func_001dd920");
void func_00167228(void) asm("func_00167228");
void func_0015de18(void) asm("func_0015de18");
/*TARGET 001618f0*/
// registers this module's handlers
void func_001618f0(void) asm("func_001618f0");
// registers this module's handlers
void func_001618f0(void) {
    func_001617c8();
    func_00106998(0);
    func_001069f8(0);
    func_00102c18(3, 6000, func_00161818);
    func_00102c18(3, 6001, func_001433e8);
    func_00102c18(3, 30000, kn__camera_task);
    func_00102c18(3, 41000, func_001dd2b8);
    func_00102c18(3, 43000, func_00144250);
    func_00102c18(3, 49999, func_00161880);
    func_00102c18(3, 50000, func_001618a0);
    func_00102c18(3, 60001, func_001dd920);
    func_00102c18(3, 71000, func_00167228)[4] = 0;
    func_00102c18(3, 65000, func_0015de18);
}
}  // namespace n001618f0

// 001619e8 (was src/anon/batch_w5.cpp)
namespace n001619e8 {
// 0015ceb8: moved to src/anon/unit_0015cdb0.cpp

u32* func_00102c80(void) asm("func_00102c80");
void func_00102688(u32, u32, u32) asm("func_00102688");
/*TARGET 001619e8*/
void func_001619e8(void) asm("func_001619e8");
void func_001619e8(void) {
    func_00102688(func_00102c80()[1], 3, 3);
}
}  // namespace n001619e8

// 00161a10 (was src/anon/tiny.cpp)
namespace n00161a10 {
void setCameraNumber(s32) asm("_ZN2kn15setCameraNumberEi");
/*TARGET 00161a10*/
void func_00161a10(BD_VALUE* bd) asm("_Z13func_00161a10P8BD_VALUE");
void func_00161a10(BD_VALUE* bd) { setCameraNumber(0); }
}  // namespace n00161a10

// 00161a28 (was src/anon/tiny.cpp)
namespace n00161a28 {
void setCameraNumber(s32) asm("_ZN2kn15setCameraNumberEi");
/*TARGET 00161a28*/
void func_00161a28(BD_VALUE* bd) asm("_Z13func_00161a28P8BD_VALUE");
void func_00161a28(BD_VALUE* bd) { setCameraNumber(1); }
}  // namespace n00161a28

// 00161a40 (was src/harata/libdk/camera.cpp)
namespace dk { // method 00161a40
extern void storeImage() asm("_ZN2dk10storeImageEv");
/*TARGET 00161a40*/
void Camera::after1CameraTask(TASK* task) {
    (void)task;
    storeImage();
}
}  // dk

// 00161a58 (was src/anon/batch_w1.cpp)
namespace n00161a58 {
extern s32 D_0034c768 asm("D_0034c768");
/*TARGET 00161a58*/
// Clamp to [0, 128].
void func_00161a58(s32 v) asm("func_00161a58");
// Clamp to [0, 128].
void func_00161a58(s32 v) {
    s32 r = (v < 0) ? 0 : (v > 128 ? 128 : v);
    D_0034c768 = r;
}
}  // namespace n00161a58

// 00161a80 (was src/anon/batch_w2.cpp)
namespace n00161a80 {
extern s32 D_0034c76c asm("D_0034c76c");
/*TARGET 00161a80*/
// 0x00152598: definition moved into src/anon/unit_0014ecb8.cpp

// Clamp to 0..128 and store.
void func_00161a80(s32 v) asm("func_00161a80");
// 0x00152598: definition moved into src/anon/unit_0014ecb8.cpp

// Clamp to 0..128 and store.
void func_00161a80(s32 v) {
    s32 r;
    if (v >= 0) {
        r = v;
        if (v > 128) r = 128;
    } else {
        r = 0;
    }
    D_0034c76c = r;
}
}  // namespace n00161a80

// 00161aa8 (was src/anon/batch_wcx2.cpp)
namespace n00161aa8 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
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
// --------------------
// dk::Camera::draw2Camera: lazily construct the two full-screen fade sprites, then draw them.
extern s8 D_004f3b50 asm("D_004f3b50");
extern s8 D_004f3b58 asm("D_004f3b58");
extern u8 D_004f3b60[] asm("D_004f3b60");
extern u8 D_004f3e70[] asm("D_004f3e70");
extern u8 D_0034c768 asm("D_0034c768");
extern u8 D_0034c76c asm("D_0034c76c");
void func_0014c050(u8* s) asm("func_0014c050");
void func_002fd188(void (*fn)(void)) asm("func_002fd188");
void func_001623d8(void) asm("func_001623d8");
void func_001623f0(void) asm("func_001623f0");
void func_0014b5e0(u8* s, s32 tex) asm("func_0014b5e0");
void func_0014b630(u8* s, s32 a) asm("func_0014b630");
void func_0014b208(u8* s, u16 w, u16 h) asm("func_0014b208");
void func_0014b5e8(u8* s, u64 uv0, u64 uv1) asm("func_0014b5e8");
void func_0014b628(u8* s, u64 a) asm("func_0014b628");
void func_0014b220(u8* s, u8 r, u8 g, u8 b, u8 a) asm("func_0014b220");
void func_0014c350(u8* s) asm("func_0014c350");
void func_0014e098(s32 a) asm("func_0014e098");
void draw2Camera_161aa8(void) asm("_ZN2dk6Camera11draw2CameraEv");
/*TARGET 00161aa8*/
void draw2Camera_161aa8(void) asm("_ZN2dk6Camera11draw2CameraEv");
void draw2Camera_161aa8(void)
{
    u8* s0;
    u8* s1;
    if (!D_004f3b50) {
        func_0014c050(D_004f3b60);
        D_004f3b50 = 1;
        func_002fd188(func_001623d8);
    }
    if (!D_004f3b58) {
        func_0014c050(D_004f3e70);
        D_004f3b58 = 1;
        func_002fd188(func_001623f0);
    }
    s0 = D_004f3b60;
    s1 = D_004f3e70;
    func_0014b5e0(s0, 342);
    func_0014b630(s0, 0);
    func_0014b208(s0, 512, 416);
    func_0014b5e8(s0, 0x80008, 0x1a082008);
    func_0014b628(s0, 0x2000000264121b00ULL);
    func_0014b220(s0, 128, 128, 128, D_0034c76c);
    func_0014c350(s0);
    func_0014e098(320);
    func_0014b5e0(s1, 342);
    func_0014b630(s1, 0);
    func_0014b208(s1, 512, 416);
    func_0014b5e8(s1, 0x80008, 0x1a082008);
    func_0014b628(s1, 0x2000000264122800ULL);
    func_0014b220(s1, 128, 128, 128, D_0034c768);
    func_0014c350(s1);
}
}  // namespace n00161aa8

// 00161c20 (was src/anon/tiny_auto80_queue.cpp)
namespace n00161c20 {
extern u8  D_0034c770 asm("D_0034c770");
extern u32 D_0034c778 asm("D_0034c778");
void func_00161aa8(...) asm("func_00161aa8");
// 0x0013f1e8: definition moved into src/anon/unit_0013ef70.cpp

extern "C" u32 func_001024a8(...) asm("func_001024a8");
/*TARGET 00161c20*/
void func_00161c20(u32 a0) asm("_Z13func_00161c20j");
void func_00161c20(u32 a0) {
    func_00161aa8(a0);
    if (D_0034c770 != 0u) {
        return;
    }
    D_0034c778 = 0;
    func_001024a8(a0);
}
}  // namespace n00161c20

// 00161c70 (was src/harata/libdk/camera.cpp)
namespace dk { // method 00161c70
extern s32 Camera_draw2Camera(void*) asm("_ZN2dk6Camera11draw2CameraEv");
/*TARGET 00161c70*/
void Camera::multiAfter2CameraTask(TASK* task) {
    (void)task;
    Camera_draw2Camera(this);
}
}  // dk

// 00161c88 (was gap)
namespace g00161c88 {
extern u32 D_0034c774 asm("D_0034c774");
extern u32 D_0034c778 asm("D_0034c778");
extern u8 D_0034c771 asm("D_0034c771");
extern f32 D_00349e10 asm("D_00349e10");
void func_001623b0(void) asm("func_001623b0");
void func_001618f0(void) asm("func_001618f0");
void func_001024a8(void*) asm("func_001024a8");
void func_00161a58(s32) asm("func_00161a58");
void func_00161a80(s32) asm("func_00161a80");
struct Fade { u32 pad; f32 t; f32 len; f32 k; };
// Fade task step: counts t down by the frame time, drives both screen fades, ends when t reaches 0.
void f(Fade* o) asm("func_00161c88");
void f(Fade* o) {
    f32 t = o->t;
    if (t <= 0.0f) {
        func_001623b0();
        func_001618f0();
        func_001024a8(o);
        D_0034c778 = 0;
        D_0034c774 = 0;
        return;
    }
    s32 a = (s32)(t * o->k);
    s32 b = (s32)((o->len - t) * o->k);
    func_00161a58(a);
    func_00161a80(b);
    f32 n = o->t - D_00349e10;
    o->t = n;
    if (n <= 0.0f) D_0034c771 = 0;
}
}  // namespace g00161c88

// 00161d48 (was gap)
namespace g00161d48 {
extern u32 D_0034c774 asm("D_0034c774");
extern u8 D_0034c770 asm("D_0034c770");
extern f32 D_00349e10 asm("D_00349e10");
void func_001024a8(void*) asm("func_001024a8");
void func_00161a58(s32) asm("func_00161a58");
void func_00161a80(s32) asm("func_00161a80");
struct Fade { u32 pad; f32 t; f32 len; f32 k; };
void f(Fade* o) asm("func_00161d48");
void f(Fade* o) {
    f32 t = o->t - D_00349e10;
    o->t = t;
    s32 a = (s32)(t * o->k);
    s32 b = (s32)((o->len - t) * o->k);
    func_00161a58(a);
    func_00161a80(b);
    if (o->t <= 0.0f) {
        D_0034c770 = 0;
        func_001024a8(o);
        D_0034c774 = 0;
    }
}
}  // namespace g00161d48

// 00161de0 (was gap)
namespace g00161de0 {
extern u32 D_0034c774 asm("D_0034c774");
void f(void) asm("func_00161de0");
void f(void) { D_0034c774 = 0; }
}  // namespace g00161de0

// 00161df0 (was src/anon/batch_w1814_nsa.cpp)
namespace n00161df0 {
struct W1814Obj { u32 pad0; f32 f4; f32 f8; f32 fc; s32 m10; u8 pad[0x1c]; void* cb30; };
struct W1814Arg { u32 pad0; f32 f4; u32 pad8; u32 padc; s32 m10; };
struct W1814Cur { u32 pad0; s32 id; };
extern W1814Obj* D_0034c774 asm("D_0034c774");
void func_001024a8(void*) asm("func_001024a8");
void func_00102670(s32, W1814Obj*) asm("func_00102670");
W1814Obj* func_00102c18(s32, s32, void*) asm("func_00102c18");
W1814Cur* func_00102c80(void) asm("func_00102c80");
void func_001619e8(void) asm("func_001619e8");
void func_001620a8(void) asm("func_001620a8");
void func_001623b0(void) asm("func_001623b0");
void func_00161c88(void) asm("func_00161c88");
void func_00161d48(void) asm("func_00161d48");
void func_00161de0(void) asm("func_00161de0");
/*TARGET 00161df0*/
void func_00161df0(W1814Arg* a) asm("func_00161df0");
void func_00161df0(W1814Arg* a) {
    if (D_0034c774 != 0) {
        func_00102670(func_00102c80()->id, D_0034c774);
        func_001623b0();
    }
    if (a->m10 == 0) {
        func_001619e8();
        func_001620a8();
    }
    W1814Obj* o;
    if (a->m10 == 1) D_0034c774 = o = func_00102c18(1, 0x16007, (void*)func_00161d48);
    else D_0034c774 = o = func_00102c18(1, 0x16007, (void*)func_00161c88);
    D_0034c774->cb30 = (void*)func_00161de0;
    f32 f = a->f4;
    o->f4 = f;
    o->f8 = f;
    o->fc = 128.0f / f;
    o->m10 = a->m10;
    func_001024a8(a);
}
}  // namespace n00161df0

// 00161ee8 (was src/anon/batch_w2.cpp)
namespace n00161ee8 {
extern u8 D_0034c770 asm("D_0034c770");
extern u8 D_0034c771 asm("D_0034c771");
extern u32 D_0034c774 asm("D_0034c774");
extern u32 D_0034c778 asm("D_0034c778");
/*TARGET 00161ee8*/
void func_00161ee8(void) asm("func_00161ee8");
void func_00161ee8(void) {
    D_0034c770 = 0;
    D_0034c771 = 0;
    D_0034c774 = 0;
    D_0034c778 = 0;
}
}  // namespace n00161ee8

// 00161f10 (was src/anon/batch_w3.cpp)
namespace n00161f10 {
// 00158920: moved to src/yasui/libys/light.cpp

void func_0014e0d8(void*) asm("func_0014e0d8");
void func_001024a8(void*) asm("func_001024a8");
/*TARGET 00161f10*/
void dk__Camera__storeImageTask(void* p) asm("dk__Camera__storeImageTask");
void dk__Camera__storeImageTask(void* p) {
    func_0014e0d8(p);
    func_001024a8(p);
}
}  // namespace n00161f10

// 00161f38 (was gap)
namespace g00161f38 {
extern u32 D_0034c778 asm("D_0034c778");
void f(void) asm("func_00161f38");
void f(void) { D_0034c778 = 0; }
}  // namespace g00161f38

// 00161f48 (was src/anon/batch_w95.cpp)
namespace n00161f48 {
struct TaskB { u8 pad0[4]; f32 t; u8 pad8[8]; u32 mode; u8 pad20[28]; void* fn; };
void func_00161f48_impl(u8 mode, f32 t) asm("_Z13func_00161f48i");
// 0015e8c8: moved to src/anon/unit_0015e070.cpp

TaskB* func_00102c18(s32, s32, void (*)(void)) asm("func_00102c18");
struct TaskMgr { u32 pad; void* q; };
TaskMgr* func_00102c80(void) asm("func_00102c80");
void func_00102670(void*, TaskB*) asm("func_00102670");
// to_1025f8
void func_00161df0(void) asm("func_00161df0");
void dk__Camera__storeImageTask(void) asm("dk__Camera__storeImageTask");
void func_00161c20(void) asm("func_00161c20");
void func_00161f38(void) asm("func_00161f38");
struct U8Flag { u8 v; };
extern U8Flag D_0034c770 asm("D_0034c770");
extern U8Flag D_0034c771 asm("D_0034c771");
extern void* D_0034c778 asm("D_0034c778");
/*TARGET 00161f48*/
void func_00161f48_impl(u8 mode, f32 t) asm("_Z13func_00161f48i");
void func_00161f48_impl(u8 mode, f32 t) {
    if (mode == 1) {
        TaskB* k = func_00102c18(1, 0x186a0, func_00161df0);
        k->mode = mode;
        k->t = t + t;
        D_0034c770.v = 1;
        func_00102c18(1, 0x15f90, dk__Camera__storeImageTask);
        if (D_0034c778) func_00102670(func_00102c80()->q, (TaskB*)D_0034c778);  // to_1025f8
        D_0034c778 = func_00102c18(1, 0x16008, func_00161c20);
        ((TaskB*)D_0034c778)->fn = (void*)func_00161f38;
    } else {
        TaskB* k = func_00102c18(1, 0x186a0, func_00161df0);
        k->mode = mode;
        t -= 1.0f;
        k->t = t + t;
        D_0034c771.v = 1;
    }
}
}  // namespace n00161f48

// 00162058 (was src/anon/tiny.cpp)
namespace n00162058 {
void func_00161f48(s32) asm("_Z13func_00161f48i");
/*TARGET 00162058*/
void func_00162058(BD_VALUE* bd) asm("_Z13func_00162058P8BD_VALUE");
void func_00162058(BD_VALUE* bd) { func_00161f48(1); }
}  // namespace n00162058

// 00162070 (was src/anon/tiny.cpp)
namespace n00162070 {
void func_00161f48(s32) asm("_Z13func_00161f48i");
/*TARGET 00162070*/
void func_00162070(BD_VALUE* bd) asm("_Z13func_00162070P8BD_VALUE");
void func_00162070(BD_VALUE* bd) { func_00161f48(0); }
}  // namespace n00162070

// 00162088 (was src/anon/tiny.cpp)
namespace n00162088 {
/*TARGET 00162088*/
u32 func_00162088(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00162088jjjj");
u32 func_00162088(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0035u << 16);
    return (u32)(*(u8*)((u32)b + (-14479)));
}
}  // namespace n00162088

// 00162098 (was src/anon/tiny.cpp)
namespace n00162098 {
/*TARGET 00162098*/
u32 func_00162098(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00162098jjjj");
u32 func_00162098(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0035u << 16);
    return (u32)(*(u8*)((u32)b + (-14480)));
}
}  // namespace n00162098

// 001620a8 (was src/anon/batch_wcx2.cpp)
namespace n001620a8 {
// 0x002f9bc0: definition moved into src/newlib/libm/ef_log.c

// ---- 001620a8
void kn__camera_task(void) asm("kn__camera_task");
void func_001433e8(void) asm("func_001433e8");
void func_00144250(void) asm("func_00144250");
void func_0014df48(void) asm("func_0014df48");
void func_0015de18(void) asm("func_0015de18");
void func_00161868(void) asm("func_00161868");
void func_00161880(void) asm("func_00161880");
void func_001618a0(void) asm("func_001618a0");
void func_00161a10(void) asm("func_00161a10");
void func_00161a28(void) asm("func_00161a28");
void func_00161a40(void) asm("func_00161a40");
void func_00161c70(void) asm("func_00161c70");
void func_00167228(void) asm("func_00167228");
void func_001dd2b8(void) asm("func_001dd2b8");
void func_001dd920(void) asm("func_001dd920");
void func_00106998(s32) asm("func_00106998");
u8* func_00102c18(s32, s32, void (*)(void)) asm("func_00102c18");
/*TARGET 001620a8*/
void func_001620a8(void) asm("func_001620a8");
void func_001620a8(void)
{
    func_00106998(1);
    func_00102c18(5, 6000, func_00161868);
    func_00102c18(5, 6001, func_001433e8);
    func_00102c18(5, 6002, func_00161a10);
    func_00102c18(5, 29999, func_00161a28);
    func_00102c18(5, 30000, kn__camera_task);
    func_00102c18(5, 40999, func_00161a10);
    func_00102c18(5, 41000, func_001dd2b8);
    func_00102c18(5, 42999, func_00161a28);
    func_00102c18(5, 43000, func_00144250);
    func_00102c18(5, 49999, func_00161880);
    func_00102c18(5, 50000, func_001618a0);
    func_00102c18(5, 60000, func_00161a10);
    func_00102c18(5, 60001, func_001dd920);
    func_00102c18(5, 71000, func_00167228)[4] = 0;
    func_00102c18(5, 65000, func_0015de18);
    func_00102c18(5, 90000, func_00161a40);
    func_00102c18(5, 90005, func_0014df48);
    func_00102c18(5, 90010, func_00161868);
    func_00102c18(5, 90020, func_00161a10);
    func_00102c18(5, 90030, kn__camera_task);
    func_00102c18(5, 90039, func_00161a28);
    func_00102c18(5, 90040, func_001dd2b8);
    func_00102c18(5, 90049, func_00161a10);
    func_00102c18(5, 90050, func_00144250);
    func_00102c18(5, 90060, func_00161880);
    func_00102c18(5, 90070, func_001618a0);
    func_00102c18(5, 90079, func_00161a28);
    func_00102c18(5, 90080, func_001dd920);
    func_00102c18(5, 90100, func_00167228)[4] = 0;
    func_00102c18(5, 90110, func_0015de18);
    func_00102c18(5, 90130, func_00161c70);
}
}  // namespace n001620a8

// 001623b0 (was src/anon/batch_w4.cpp)
namespace n001623b0 {
void* func_00102c80(void) asm("func_00102c80");
void func_00102688(u32, u32, u32) asm("func_00102688");
/*TARGET 001623b0*/
// 0x0015b780: definition moved into src/anon/unit_0015b100.cpp

// 0015cea0: moved to src/anon/unit_0015cdb0.cpp

void func_001623b0(void) asm("func_001623b0");
// 0x0015b780: definition moved into src/anon/unit_0015b100.cpp

// 0015cea0: moved to src/anon/unit_0015cdb0.cpp

void func_001623b0(void) {
    func_00102688(*(u32*)((u8*)func_00102c80() + 4), 5, 5);
}
}  // namespace n001623b0

// 001623d8 (was gap)
namespace g001623d8 {
extern u8 D_00348698[] asm("D_00348698");
extern void* D_004f3b60 asm("D_004f3b60");
void f(void) asm("func_001623d8");
void f(void) { D_004f3b60 = D_00348698; }
}  // namespace g001623d8

// 001623f0 (was gap)
namespace g001623f0 {
extern u8 D_00348698[] asm("D_00348698");
extern void* D_004f3e70 asm("D_004f3e70");
void f(void) asm("func_001623f0");
void f(void) { D_004f3e70 = D_00348698; }
}  // namespace g001623f0

// 00162408 (was src/anon/batch_w271.cpp)
namespace n00162408 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QW_w271 {
    f32 x, y, z, w;
    QW_w271() {}
    QW_w271(const QW_w271& o) { QCOPY(this, &o); }
    QW_w271& operator=(const QW_w271& o) { if (this != &o) QCOPY(this, &o); return *this; }
    ~QW_w271() {}
} __attribute__((aligned(16)));
static inline QW_w271 operator-(const QW_w271& a, const QW_w271& b)
{
    QW_w271 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline QW_w271 Cross_w271(const QW_w271& a, const QW_w271& b)
{
    QW_w271 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct Poly_w271 { QW_w271* v[4]; s32 n; };
extern s32 D_0034c780[] asm("D_0034c780");
extern s32 D_0034c790[] asm("D_0034c790");
/*TARGET 00162408*/
s32 func_00162408(Poly_w271* o, QW_w271* pt) asm("func_00162408");
s32 func_00162408(Poly_w271* o, QW_w271* pt) {
    s32 n = o->n;
    s32* idx = (n == 3) ? D_0034c780 : D_0034c790;
    QW_w271 e[2];
    QW_w271 c;
    for (s32 i = 0; i < n; i++) {
        e[0] = *o->v[idx[i]] - *o->v[i];
        e[1] = *pt - *o->v[i];
        c = Cross_w271(e[1], e[0]);
        if (c.y < 0.0f) return 0;
    }
    return 1;
}
}  // namespace n00162408

// 00162560 (was src/anon/batch_w1941_nsa.cpp)
namespace n00162560 {
// ---- 00162560 types
struct V1941 { f32 x, y, z, w;
    V1941() {}
    ~V1941() {}
    V1941& operator=(const V1941& o) {
        if (this != &o) asm volatile("lq $8,0(%1)\n\tsq $8,0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V1941 operator-(const V1941& b) const {
        V1941 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1,0(%1)\n\tlqc2 $vf2,0(%2)\n\tvsub.wxyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V1941 cross(const V1941& b) const {
        V1941 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1,0(%1)\n\tlqc2 $vf2,0(%2)\n\tvsub.wxyz $vf3,$vf0,$vf0\n\tvopmula.xyz ACC,$vf1,$vf2\n\tvopmsub.xyz $vf3,$vf2,$vf1\n\tsqc2 $vf3,0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 dot(const V1941& b) const {
        f32 r;
        asm volatile("lqc2 $vf1,0(%1)\n\tlqc2 $vf2,0(%2)\n\tvmul.xyz $vf1,$vf1,$vf2\n\tvaddy.x $vf1,$vf1,$vf1y\n\tvaddz.x $vf1,$vf1,$vf1z\n\tqmfc2 $8,$vf1\n\tmtc1 $8,%0" : "=f"(r) : "r"(this), "r"(&b) : "$8", "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct Poly1941 { V1941* v[4]; s32 n; };
// 0x00153678: definition moved into src/anon/unit_00153678.cpp

// --- 00162560: is the point inside the polygon (every edge cross product faces away from the normal)
extern s32 D_0034c780[] asm("D_0034c780");
extern s32 D_0034c790[] asm("D_0034c790");
/*TARGET 00162560*/
s32 func_00162560(Poly1941* o, V1941* p, V1941* nrm) asm("func_00162560");
s32 func_00162560(Poly1941* o, V1941* p, V1941* nrm) {
    s32 n = o->n;
    s32* tbl = (n == 3) ? D_0034c780 : D_0034c790;
    V1941 e[2];
    V1941 c;
    for (s32 i = 0; i < n; i++) {
        e[0] = *o->v[tbl[i]] - *o->v[i];
        e[1] = *p - *o->v[i];
        c = e[1].cross(e[0]);
        if (0.01f < c.dot(*nrm)) return 0;
    }
    return 1;
}
}  // namespace n00162560

// 001626e0 (was src/anon/batch_w273.cpp)
namespace n001626e0 {
struct V4w273 {
  f32 x, y, z, w;
  V4w273& operator=(const V4w273& o) {
    if (this != &o) asm volatile("lq $8,0(%1)\n\tsq $8,0(%0)" :: "r"(this), "r"(&o) : "$8", "memory");
    return *this;
  }
} __attribute__((aligned(16)));
struct Src273 { V4w273* v[4]; s32 n; };
/*TARGET 001626e0*/
void func_001626e0(Src273* p, V4w273* m) asm("func_001626e0");
void func_001626e0(Src273* p, V4w273* m) {
  if (p->n == 3) {
    m[0] = m[3] = m[6] = *p->v[0];
    m[1] = m[4] = m[7] = *p->v[1];
    m[2] = m[5] = *p->v[2];
  } else {
    m[0] = m[4] = *p->v[0];
    m[1] = m[5] = *p->v[1];
    m[2] = m[6] = *p->v[2];
    m[3] = m[7] = *p->v[3];
  }
  m[0].w = m[1].w = m[2].w = m[3].w = m[4].w = m[5].w = m[6].w = m[7].w = 1.0f;
}
}  // namespace n001626e0

// 00162848 (was gap)
namespace g00162848 {
struct Q {
    u32 w[4];
    Q& operator=(const Q& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Pair { Q a; Q b; };
void f(Pair* p, const Q* a, const Q* b) asm("func_00162848");
void f(Pair* p, const Q* a, const Q* b) {
    Q* q = &p->b;
    p->a = *a;
    *q = *b;
}
}  // namespace g00162848

// 00162870 (was gap)
namespace g00162870 {
struct Q {
    u32 w[4];
    Q& operator=(const Q& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Pair { Q a; Q b; };
void f(Pair* p, const Q* a, const Q* b) asm("func_00162870");
void f(Pair* p, const Q* a, const Q* b) {
    Q* q = &p->b;
    p->a = *a;
    *q = *b;
}
}  // namespace g00162870

// 00162898 (was gap)
namespace g00162898 {
struct V { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline f32 dot(const V* a, const V* b) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(a), "r"(b) : "$8", "memory");
    return r;
}
// True when the point is on the front side of the plane (n.p + d >= 0).
s32 f(const V* p, const V* pl) asm("func_00162898");
s32 f(const V* p, const V* pl) {
    f32 d = dot(p, pl) + pl->w;
    if (d < 0.0f) return 0;
    return 1;
}
}  // namespace g00162898

// 001628d8 (was src/anon/batch_w3711.cpp)
namespace n001628d8 {
struct V1628 {
    f32 x, y, z, w;
    V1628() {}
    V1628& operator=(const V1628& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Ray1628 { V1628 pos; V1628 dir; };
static inline f32 dot(const V1628* a, const V1628* b) {
    f32 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder"
        : "=f"(r) : "r"(a), "r"(b) : "$8", "memory");
    return r;
}
static inline V1628 mul(const V1628& v, f32 s) {
    V1628 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&v), "f"(s) : "$8", "memory");
    return r;
}
static inline V1628 add(const V1628& a, const V1628& b) {
    V1628 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
s32 func_00162560(V1628**, V1628*) asm("func_00162560");
/*TARGET 001628d8*/
s32 func_001628d8(Ray1628* ray, V1628** pp, V1628* n, V1628* out) asm("func_001628d8");
s32 func_001628d8(Ray1628* ray, V1628** pp, V1628* n, V1628* out)
{
    register s32 k asm("$14");  // pin: occupies t6 (no code)
    asm("" : "=r"(k));
    f32 d = dot(n, &ray->dir);
    if (0.0f <= d) return 0;
    f32 a = dot(n, *pp);
    f32 b = dot(n, &ray->pos);
    f32 t = (a - b) / d;
    if (1.0f < t) return 0;
    if (t < 0.0f) return 0;
    *out = mul(ray->dir, t);
    *out = add(*out, ray->pos);
    out->w = 1.0f;
    asm("" : : "r"(k));
    return func_00162560(pp, out) != 0;
}
}  // namespace n001628d8

// 001629e8 (was gap)
namespace g001629e8 {
void f(u32 a0, u32 a1) asm("func_001629e8");
void f(u32 a0, u32 a1) {
    *(f32*)(a0 + 0) = *(f32*)(a1 + 0);
    *(f32*)(a0 + 4) = *(f32*)(a1 + 4);
    *(f32*)(a0 + 8) = *(f32*)(a1 + 8);
    *(f32*)(a0 + 16) = *(f32*)(a1 + 12);
    *(f32*)(a0 + 20) = *(f32*)(a1 + 16);
    *(f32*)(a0 + 24) = *(f32*)(a1 + 20);
}
}  // namespace g001629e8

// 00162a20 (was src/anon/tiny_auto80_queue.cpp)
namespace n00162a20 {
/*TARGET 00162a20*/
void func_00162a20(u32 a0, u32 a1) asm("_Z13func_00162a20jj");
void func_00162a20(u32 a0, u32 a1) {
    *(f32*)((u32)a0 + (s32)(0)) = *(f32*)((u32)a1 + (s32)(0));
    *(f32*)((u32)a0 + (s32)(4)) = *(f32*)((u32)a1 + (s32)(4));
    *(f32*)((u32)a0 + (s32)(8)) = *(f32*)((u32)a1 + (s32)(8));
    *(f32*)((u32)a0 + (s32)(16)) = *(f32*)((u32)a1 + (s32)(12));
    *(f32*)((u32)a0 + (s32)(20)) = *(f32*)((u32)a1 + (s32)(16));
    *(f32*)((u32)a0 + (s32)(24)) = *(f32*)((u32)a1 + (s32)(20));
}
}  // namespace n00162a20

// 00162a58 (was src/anon/batch_owner1022.cpp)
namespace n00162a58 {
void func_00162a88(u8* p, u32 b) asm("func_00162a88");
/*TARGET 00162a58*/
void func_00162a58(u8* p, u32 b) asm("func_00162a58");
void func_00162a58(u8* p, u32 b) { func_00162a88(p, b); }
}  // namespace n00162a58

// 00162a70 (was src/anon/batch_owner1022.cpp)
namespace n00162a70 {
void func_00162a88(u8* p, u32 b) asm("func_00162a88");
/*TARGET 00162a70*/
void func_00162a70(u8* p, u32 b) asm("func_00162a70");
void func_00162a70(u8* p, u32 b) { func_00162a88(p, b); }
}  // namespace n00162a70

// 00162a88 (was src/anon/batch_w1672.cpp)
namespace n00162a88 {
// 0x001da2b8: definition moved into src/anon/unit_001d9d00.cpp

struct V4w1672 { f32 v[4]; } __attribute__((aligned(16)));
void func_00162a20(V4w1672*) asm("func_00162a20");
void func_00144908(u32, u8*) asm("func_00144908");
/*TARGET 00162a88*/
void func_00162a88(u8* p, u32 b) asm("func_00162a88");
void func_00162a88(u8* p, u32 b) {
    V4w1672 buf[2];
    V4w1672 d;
    func_00162a20(buf);
    asm volatile("lqc2 $vf1,0(%1)\n lqc2 $vf2,0(%2)\n vsub.xyzw $vf1,$vf1,$vf2\n sqc2 $vf1,0(%0)" : : "r"(&d), "r"(&buf[1]), "r"(&buf[0]) : "memory");
    f32 len;
    asm volatile("lqc2 $vf1,0(%1)\n vmul.xyz $vf1,$vf1,$vf1\n vaddy.x $vf1,$vf1,$vf1y\n vaddz.x $vf1,$vf1,$vf1z\n vsqrt Q,$vf1x\n vwaitq\n cfc2 $8,$vi22\n mtc1 $8,%0" : "=f"(len) : "r"(&d) : "$8", "memory");
    *(f32*)(p + 16) = len * 0.5f;
    func_00144908(b, p);
}
}  // namespace n00162a88

// 00162b18 (was src/anon/batch_w35.cpp)
namespace n00162b18 {
/*TARGET 00162b18*/
// obj_get_attach_or_alt
// 00159ef8: moved to src/harata/libdk/targetcamera.cpp

// Scales the base colour at +420 by (r, g, b)/128 into +680.
// 00160488: moved to src/harata/libdk/bgobj.cpp

// Plane test: d = dot(a.xyz, b.xyz) + b.w -> *out; 1 when 0 <= d <= a[4].
s32 func_00162b18(f32* a, f32* b, f32* out) asm("func_00162b18");
// obj_get_attach_or_alt
// 00159ef8: moved to src/harata/libdk/targetcamera.cpp

// Scales the base colour at +420 by (r, g, b)/128 into +680.
// 00160488: moved to src/harata/libdk/bgobj.cpp

// Plane test: d = dot(a.xyz, b.xyz) + b.w -> *out; 1 when 0 <= d <= a[4].
s32 func_00162b18(f32* a, f32* b, f32* out) {  // vec3_dot_plus_scale
    f32 d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
        : "=f"(d) : "r"(a), "r"(b) : "$8", "memory");
    d += b[3];
    *out = d;
    if (a[4] < d) return 0;
    if (d < 0.0f) return 0;
    return 1;
}
}  // namespace n00162b18

// 00162b68 (was src/anon/batch_w30.cpp)
namespace n00162b68 {
/*TARGET 00162b68*/
// 0x0014f528: definition moved into src/anon/unit_0014ecb8.cpp

// dot(a.xyz, b.xyz) + b.w -> *out; returns 1 when it is <= a[4].
s32 func_00162b68(f32* a, f32* b, f32* out) asm("func_00162b68");
// 0x0014f528: definition moved into src/anon/unit_0014ecb8.cpp

// dot(a.xyz, b.xyz) + b.w -> *out; returns 1 when it is <= a[4].
s32 func_00162b68(f32* a, f32* b, f32* out) {
    f32 d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
        : "=f"(d) : "r"(a), "r"(b) : "$8", "memory");
    d += b[3];
    *out = d;
    return a[4] < d ? 0 : 1;
}
}  // namespace n00162b68

// 00162bb0 (was src/anon/batch_w37.cpp)
namespace n00162bb0 {
// 16-byte vector; assignment copies with a 128-bit lq/sq.
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline Vq vscale162(const Vq& v, f32 s) {
    Vq r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&v), "f"(s) : "$8", "$15", "memory");
    return r;
}
static inline Vq vsub162(const Vq& a, const Vq& b) {
    Vq r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
s32 func_00162560(void*, Vq*) asm("func_00162560");
/*TARGET 00162bb0*/
s32 func_00162bb0(const Vq* a, void* b, const Vq* c, const f32* s, Vq* out) asm("func_00162bb0");
s32 func_00162bb0(const Vq* a, void* b, const Vq* c, const f32* s, Vq* out) {
    Vq t;
    t = vscale162(*c, *s);
    *out = vsub162(*a, t);
    return func_00162560(b, out) != 0;
}
}  // namespace n00162bb0

// 00162c28 (was src/anon/batch_w3846_gnsa.cpp)
namespace n00162c28 {
inline void* operator new(unsigned int, void* p) { return p; }
struct W3846V {
    f32 x, y, z, w;
    W3846V() {}
    W3846V(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    ~W3846V() {}
    W3846V& operator=(const W3846V& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    W3846V operator+(const W3846V& o) const {
        W3846V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    W3846V operator-(const W3846V& o) const {
        W3846V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    W3846V operator*(f32 s) const {
        W3846V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "f"(s) : "$8", "memory");
        return r;
    }
    f32 dot(const W3846V& o) const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(this), "r"(&o) : "$8");
        return r;
    }
    f32 lenSq() const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(this) : "$8");
        return r;
    }
} __attribute__((aligned(16)));
static inline __attribute__((always_inline)) f32 W3846Dist2(const W3846V& a, const W3846V& b) {
    f32 r;
    asm volatile("lqc2 $vf6, 0(%1)\n\tlqc2 $vf4, 0(%2)\n\tvsub.wxyz $vf5, $vf6, $vf4\n\tvmove.wxyz $vf4, $vf5\n\tvmul.xyz $vf5, $vf4, $vf5\n\tvaddy.x $vf5, $vf5, $vf5y\n\tvaddz.x $vf5, $vf5, $vf5z\n\tqmfc2 $2, $vf5\n\tmtc1 $2, %0" : "=f"(r) : "r"(&a), "r"(&b) : "$2");
    return r;
}
struct W3846Line { W3846V o, d; };
struct W3846Sphere { W3846V c; f32 r; };
struct W3846Poly { W3846V* v[4]; s32 n; };
extern s8 D_004f4180 asm("D_004f4180");
extern W3846V D_004f4190 asm("D_004f4190");
extern const s32 D_0034c780[] asm("D_0034c780");
extern const s32 D_0034c790[] asm("D_0034c790");
void func_00163520(void) asm("func_00163520");
void func_002fd188(void (*)(void)) asm("func_002fd188");
static inline __attribute__((always_inline)) bool W3846InBox(const W3846V& p, const W3846V& lo, const W3846V& hi) {
    s32 o;
    o = p.x < lo.x; if (hi.x < p.x) { if ((o ^ 1) == 0) goto yes; } else if (o == 0) goto yes;
    o = p.y < lo.y; if (hi.y < p.y) { if ((o ^ 1) == 0) goto yes; } else if (o == 0) goto yes;
    o = p.z < lo.z; if (hi.z < p.z) { if ((o ^ 1) == 0) goto yes; } else if (o == 0) goto yes;
    o = 0; return o;
yes:
    o = 1; return o;
}
/*TARGET 00162c28*/
s32 func_00162c28(W3846Sphere* s, W3846Poly* p, W3846V* out) asm("func_00162c28");
s32 func_00162c28(W3846Sphere* s, W3846Poly* p, W3846V* out) {
    if (!D_004f4180) {
        new (&D_004f4190) W3846V(0.008f, 0.008f, 0.008f, 1.0f);
        D_004f4180 = 1;
        func_002fd188(func_00163520);
    }
    f32 r2 = s->r * s->r;
    s32 cnt = 0;
    W3846V buf[4];
    s32 n = p->n;
    const s32* next = n == 3 ? D_0034c780 : D_0034c790;
    s32 i;
    for (i = 0; i < n; i++) {
        W3846V* pa = p->v[i];
        W3846V* pb = p->v[next[i]];
        W3846V a; a = *pa;
        W3846V b; b = *pb;
        W3846Line l;
        l.o = a;
        l.d = b - a;
        l.d.w = 1.0f;
        l.o.w = 1.0f;
        *out = l.d * -((l.o - s->c).dot(l.d) / l.d.lenSq()) + l.o;
        if (W3846Dist2(s->c, *out) <= r2) {
            W3846V lo = a + D_004f4190;
            W3846V hi = b + D_004f4190;
            if (W3846InBox(*out, lo, hi)) buf[cnt++] = *out;
        }
    }
    if (cnt != 0) {
        if (cnt == 1) { *out = buf[0]; return 1; }
        f32 best = 99999991988224.0f;
        s32 idx = 0;
        for (s32 j = 0; j < cnt; j++) {
            f32 d = W3846Dist2(s->c, buf[j]);
            if (d < best) { best = d; idx = j; }
        }
        *out = buf[idx];
        return 1;
    }
    f32 best = r2;
    s32 idx = 4;
    for (s32 k = 0; k < n; k++) {
        f32 d = W3846Dist2(s->c, *p->v[k]);
        if (d <= best) { best = d; idx = k; }
    }
    if (idx != 4) { *out = *p->v[idx]; return 1; }
    return 0;
}
}  // namespace n00162c28

// 00163168 (was src/anon/batch_w67.cpp)
namespace n00163168 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define QCOPYN(d, s) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(d), "r"(s) : "$8", "memory")
// 16-byte aligned vector: copy-construct = quadword copy, assignment skips self.
struct Vec4 {
    f32 x, y, z, w;
    Vec4() {}
    Vec4(const Vec4& o) { QCOPYN(this, &o); }
    Vec4& operator=(const Vec4& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
// Squared distance of two points (xyz) on VU0.
static inline f32 vu0DistSq(const void* a, const void* b) {
    f32 d;
    asm volatile("lqc2 $vf6, 0(%1)\n\tlqc2 $vf4, 0(%2)\n\tvsub.xyzw $vf5, $vf6, $vf4\n\tvmove.xyzw $vf4, $vf5\n\t"
                 "vmul.xyz $vf5, $vf4, $vf5\n\tvaddy.x $vf5, $vf5, $vf5y\n\tvaddz.x $vf5, $vf5, $vf5z\n\tqmfc2 $2, $vf5\n\tmtc1 $2, %0"
                 : "=f"(d) : "r"(a), "r"(b) : "$2");
    return d;
}
// 0x00143c68: definition moved into src/anon/unit_00142c90.cpp

struct Sphere { Vec4 c; f32 r; };
struct PointList { Vec4* v[4]; s32 n; };
/*TARGET 00163168*/
// 00163168: the list point nearest to the sphere centre, if inside it
s32 func_00163168(Sphere* s, PointList* l, Vec4* out) asm("func_00163168");
// 00163168: the list point nearest to the sphere centre, if inside it
s32 func_00163168(Sphere* s, PointList* l, Vec4* out)
{
    f32 best = s->r * s->r;
    s32 idx = 4;
    for (s32 i = 0; i < l->n; i++) {
        f32 d = vu0DistSq(s, l->v[i]);
        if (d <= best) { best = d; idx = i; }
    }
    if (idx != 4) {
        *out = *l->v[idx];
        return 1;
    }
    return 0;
}
}  // namespace n00163168

// 00163210 (was src/anon/batch_w64.cpp)
namespace n00163210 {
/*TARGET 00163210*/
// Applies func_00160488 to every node of the list.
// 001611a8: moved to src/anon/unit_001611a8.cpp

// ---------------------------------------------------------------------------
// Sphere overlap: |a - b| <= a.r + b.r (radius in word 4).
s32 func_00163210(f32* a, f32* b) asm("func_00163210");
// Applies func_00160488 to every node of the list.
// 001611a8: moved to src/anon/unit_001611a8.cpp

// ---------------------------------------------------------------------------
// Sphere overlap: |a - b| <= a.r + b.r (radius in word 4).
s32 func_00163210(f32* a, f32* b) {
    u32 t[4] __attribute__((aligned(16)));
    f32 d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(t), "r"(a), "r"(b) : "memory");
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2 $8, $vi22\n\tmtc1 $8, %0" : "=f"(d) : "r"(t) : "$8", "memory");
    if (d <= a[4] + b[4]) return 1;
    return 0;
}
}  // namespace n00163210

// 00163268 (was src/anon/batch_w27.cpp)
namespace n00163268 {
/*TARGET 00163268*/
// 0014a188: moved to src/anon/unit_00149fa8.cpp

s32 func_00163268(f32* a, f32* b, f32* out) asm("func_00163268");
// 0014a188: moved to src/anon/unit_00149fa8.cpp

s32 func_00163268(f32* a, f32* b, f32* out) {  // vec3_distance
    u32 t[4] __attribute__((aligned(16)));
    f32 d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(t), "r"(a), "r"(b) : "memory");
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2 $8, $vi22\n\tmtc1 $8, %0" : "=f"(d) : "r"(t) : "$8", "memory");
    *out = d;
    if (d <= a[4]) return 1;
    return 0;
}
}  // namespace n00163268

// 001632c0 (was src/anon/batch_w2404_gnsa.cpp)
namespace n001632c0 {
struct V2404g {
    f32 x, y, z, w;
    V2404g() {}
    V2404g& operator=(const V2404g& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V2404g operator+(const V2404g& o) const {
        V2404g r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    V2404g operator-(const V2404g& o) const {
        V2404g r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    V2404g operator*(f32 s) const {
        V2404g r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "f"(s) : "$8", "memory");
        return r;
    }
    V2404g operator/(f32 s) const {
        V2404g r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.wxyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "f"(s) : "$8", "memory");
        return r;
    }
    f32 dot(const V2404g& o) const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(this), "r"(&o) : "$8");
        return r;
    }
} __attribute__((aligned(16)));
struct Sphere2404g { V2404g c; f32 r; };
struct Seg2404g { V2404g a, b; };
/*TARGET 001632c0*/
s32 func_001632c0(Sphere2404g* s, Seg2404g* l, V2404g* out) asm("func_001632c0");
s32 func_001632c0(Sphere2404g* s, Seg2404g* l, V2404g* out)
{
    s32 ret = 0;
    f32 t;
    V2404g c, d, e;
    c = (l->a + l->b) * 0.5f;
    d = l->b - c;
    e = s->c - c;
    f32 dd = d.dot(d);
    if (dd < 1.17549435e-38f) return 0;
    f32 ee = e.dot(e);
    f32 de = d.dot(e);
    f32 h = ee - de * de / dd;
    f32 r2 = s->r * s->r;
    if (r2 < h) return 0;
    V2404g w, p;
    p = c + d * de / dd;
    if (dd < de) {
        w = s->c - l->b;
        if (w.dot(w) <= r2) { t = __builtin_sqrtf((r2 - h) / dd); *out = p - d * t; ret = 1; }
    } else if (de < -dd) {
        w = s->c - l->a;
        if (w.dot(w) <= r2) { t = __builtin_sqrtf((r2 - h) / dd); *out = p - d * t; ret = 1; }
    } else {
        t = __builtin_sqrtf((r2 - h) / dd); *out = p - d * t; ret = 1;
    }
    return ret;
}
}  // namespace n001632c0

// 00163520 (was gap)
namespace g00163520 {
void f(void) asm("func_00163520");
void f(void) {}
}  // namespace g00163520

// 00163528 (was gap)
namespace g00163528 {
struct V { f32 x, y, z, w; };
void f(V* p, const V* s, f32 w) asm("func_00163528");
void f(V* p, const V* s, f32 w) { p->x = s->x; p->y = s->y; p->z = s->z; p->w = w; }
}  // namespace g00163528

// 00163548 (was gap)
namespace g00163548 {
struct V { f32 x, y, z, w; };
void f(V* p, const V* s, f32 w) asm("func_00163548");
void f(V* p, const V* s, f32 w) { p->x = s->x; p->y = s->y; p->z = s->z; p->w = w; }
}  // namespace g00163548

// 00163568 (was src/anon/batch_w89.cpp)
namespace n00163568 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
// 16-byte vector with a qword copy constructor and a self-checking assignment.
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline QWord operator-(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline void Cross(QWord* r, const QWord& a, const QWord& b)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)"
                 : : "r"(r), "r"(&a), "r"(&b) : "memory");
}
static inline f32 Normalize(QWord* v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
static inline f32 Dot(const QWord& a, const QWord& b)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(&a), "r"(&b) : "$8");
    return r;
}
struct Plane { f32 x, y, z, d; };
/*TARGET 00163568*/
// Plane through three points: unit normal and signed distance.
void func_00163568(Plane* out, const QWord& p0, const QWord& p1, const QWord& p2) asm("func_00163568");
// Plane through three points: unit normal and signed distance.
void func_00163568(Plane* out, const QWord& p0, const QWord& p1, const QWord& p2) {
    QWord e1, e2, n;
    e1 = p1 - p0;
    e2 = p2 - p0;
    Cross(&n, e1, e2);
    Normalize(&n);
    out->x = n.f[0];
    out->y = n.f[1];
    out->z = n.f[2];
    out->d = -Dot(n, p0);
}
}  // namespace n00163568

// 00163650 (was src/anon/batch_w90.cpp)
namespace n00163650 {
struct FV {
    f32 x, y, z, w;
    FV() {}
    FV& operator=(const FV& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline FV Sub(const FV* a, const FV* b)
{
    FV r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(a), "r"(b) : "memory");
    return r;
}
static inline void Cross(FV* d, const FV* a, const FV* b)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline void Normalize(FV* v)
{
    asm volatile(
        "lqc2 $vf1, 0(%0)\n\t"
        "vmul.xyz $vf2, $vf1, $vf1\n\t"
        "vaddy.x $vf2, $vf2, $vf2y\n\t"
        "vaddz.x $vf2, $vf2, $vf2z\n\t"
        "vsqrt Q, $vf2x\n\t"
        "vwaitq\n\t"
        "cfc2.ni $8, $vi22\n\t"
        "vaddq.x $vf2, $vf0, Q\n\t"
        "mtc1 $8, $f1\n\t"
        "vnop\n\t"
        "vdiv Q, $vf0w, $vf2x\n\t"
        "vwaitq\n\t"
        "vmulq.xyz $vf1, $vf1, Q\n\t"
        "sqc2 $vf1, 0(%0)"
        : : "r"(v) : "$8", "$f1", "memory");
}
static inline f32 Dot(const FV* a, const FV* b)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(a), "r"(b) : "$8", "memory");
    return r;
}
/*TARGET 00163650*/
// 00163650: plane (normal, -d) through three points.
void func_00163650(f32* out, FV* p0, FV* p1, FV* p2) asm("func_00163650");
// 00163650: plane (normal, -d) through three points.
void func_00163650(f32* out, FV* p0, FV* p1, FV* p2)
{
    FV e1, e2, n;
    e1 = Sub(p1, p0);
    e2 = Sub(p2, p0);
    Cross(&n, &e1, &e2);
    Normalize(&n);
    out[0] = n.x;
    out[1] = n.y;
    out[2] = n.z;
    out[3] = -Dot(&n, p0);
}
}  // namespace n00163650

// 00163738 (was gap)
namespace g00163738 {
struct V { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline f32 normalize(V* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
static inline f32 dot(const V* a, const V* b) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(a), "r"(b) : "$8", "memory");
    return r;
}
// Plane through point pt with normal n (n is normalized in place).
void f(V* pl, const V* pt, V* n) asm("func_00163738");
void f(V* pl, const V* pt, V* n) {
    normalize(n);
    pl->x = n->x;
    pl->y = n->y;
    pl->z = n->z;
    pl->w = -dot(n, pt);
}
}  // namespace g00163738

// 001637b0 (was gap)
namespace g001637b0 {
struct V { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline f32 normalize(V* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
static inline f32 dot(const V* a, const V* b) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(a), "r"(b) : "$8", "memory");
    return r;
}
void f(V* pl, const V* pt, V* n) asm("func_001637b0");
void f(V* pl, const V* pt, V* n) {
    normalize(n);
    pl->x = n->x;
    pl->y = n->y;
    pl->z = n->z;
    pl->w = -dot(n, pt);
}
}  // namespace g001637b0

// 00163828 (was src/anon/batch_w36.cpp)
namespace n00163828 {
struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
/*TARGET 00163828*/
// 0x0015ac68: definition moved into src/anon/unit_0015a810.cpp

// Which side of a plane: (b - a) . n
s32 func_00163828(const f32* a, const f32* b, const f32* n) asm("func_00163828");
// 0x0015ac68: definition moved into src/anon/unit_0015a810.cpp

// Which side of a plane: (b - a) . n
s32 func_00163828(const f32* a, const f32* b, const f32* n) {
    Q16 d;
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%0)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)" : : "r"(a), "r"(b), "r"(&d) : "memory");
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
        : "=f"(r) : "r"(&d), "r"(n) : "$8", "memory");
    if (r < -0.001f) return 1;
    if (0.001f < r) return 0;
    return 2;
}
}  // namespace n00163828


// The float literal pool of the whole-asm function 0x163898 (batch_w3959.s, which loads it by address) follows
// this file's .rodata. Defined here so the 8-aligned section ends at 0x36b4c8 without a pad word over 0x36b4bc.
extern "C" const f32 D_0036b4bc = 0.008f;
extern "C" const f32 D_0036b4c0 = 0.5f;
extern "C" const f32 D_0036b4c4 = 1.02f;
