// Linked unit 0x2c10e0-0x2c1e80 (starts after the whole-asm ctor 0x2c0ca0, src/anon/batch_w3940.s).
// dk::WM_TOTAL_INFO (D2/D1/D0, update, task hooks; vtable 0x361a98), the worldmap object classes
// with vtables 0x361ab8 / 0x361ae8, worldmap::Gumi (vtable 0x361b18) and the course flag loop
// 0x2c1dc0. Vtables and .data stay retail data; .rodata 0x3754e8-0x375534 is defined here.
// Bodies come from the old split files named above each function; every callee and global is
// bound by asm label, one namespace per old file, so prototypes from different files do not clash.
#include "../common/types.h"

// ---- 002c10e0 from src/anon/batch_wcx2.cpp
namespace n002c10e0 {
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
void func_00239870(u8*) asm("func_00239870");
struct V2e2350 {
    f32 x, y, z, w;
    V2e2350() {}
    V2e2350(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
                                        
    V2e2350& operator=(const V2e2350& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
extern u8 D_00361aa0_2c10e0[] asm("D_00361aa0");
extern u8 D_00347e60_2c10e0[] asm("D_00347e60");
extern u8 D_00347f98_2c10e0[] asm("D_00347f98");
extern u8 D_0035eb98_2c10e0[] asm("D_0035eb98");
struct E2c10e0;
struct EVt2c10e0 { void* p[3]; void (*dtor)(E2c10e0*); };
struct E2c10e0 { EVt2c10e0* vt; u8 pad[404]; };
struct X2c10e0 { u32 vt; u8 pad[20]; u8 y[16]; };
struct Z2c10e0 { u32 vt; u8 pad[20]; u8 m24[24]; u8 m48[112]; u32 f160; };
struct O2c10e0 { u32 vt; u8 pad[24]; Z2c10e0 z; X2c10e0 y; u8 p2[368]; E2c10e0 b[3]; X2c10e0 x; u8 p3[368]; E2c10e0 a[2]; u8 p4[188 - 188]; };
extern struct O2c10e0* D_00361a90 asm("D_00361a90");
void func_00170950(u32) asm("func_00170950");
void func_0023c098(u8*) asm("func_0023c098");
void func_002369f0(u8*) asm("func_002369f0");
void func_002c10e0(O2c10e0* o) asm("func_002c10e0");
void func_002c10e0(O2c10e0* o)
{
    o->vt = (u32)D_00361aa0_2c10e0;
    func_00170950(o->z.f160);
    if (D_00361a90 == o) D_00361a90 = 0;
    if ((u8*)o + 2232 != 0) {
        E2c10e0* p = o->a + 2;
        E2c10e0* b = o->a;
        for (;;) { if (b == p) break; --p; p->vt->dtor(p); }
    }
    X2c10e0* x = &o->x;
    x->vt = (u32)D_00347e60_2c10e0;
    func_00239870(x->y);
    x->vt = (u32)D_00347f98_2c10e0;
    if ((u8*)o + 600 != 0) {
        E2c10e0* p = o->b + 3;
        E2c10e0* b = o->b;
        for (;;) { if (b == p) break; --p; p->vt->dtor(p); }
    }
    o->y.vt = (u32)D_00347e60_2c10e0;
    func_00239870(o->y.y);
    o->y.vt = (u32)D_00347f98_2c10e0;
    o->z.vt = (u32)D_0035eb98_2c10e0;
    func_0023c098(o->z.m48);
    func_002369f0(o->z.m24);
    o->z.vt = (u32)D_00347f98_2c10e0;
    o->vt = (u32)D_00347f98_2c10e0;
}
}  // namespace n002c10e0

// ---- 002c1200 from src/anon/batch_w258.cpp
namespace n002c1200 {
extern u8 D_00361aa0[] asm("D_00361aa0");
extern u8* D_00361a90 asm("D_00361a90");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_0035eb98[] asm("D_0035eb98");
void CACHE_BUFF_Free(void*) asm("_ZN2YS10CACHE_BUFF4FreeEPv");
void SEQUENCE_dtor(u8*) asm("_ZN2YI8SEQUENCED1Ev");
void func_0023c098(u8*) asm("func_0023c098");
void func_002369f0(u8*) asm("func_002369f0");
typedef void (*VF12)(u8*);
void func_002c1200(u8* p) asm("func_002c1200");
void func_002c1200(u8* p) {
    u8* e;
    *(u8**)p = D_00361aa0;
    CACHE_BUFF_Free(*(void**)(p + 188));
    D_00361a90 = (D_00361a90 == p) ? 0 : D_00361a90;
    if (p + 2232) {
        e = p + 3048;
    L1:
        if (p + 2232 != e) {
            e -= 408;
            (*(VF12*)(*(u8**)e + 12))(e);
            goto L1;
        }
    }
    e = p + 1824;
    *(u8**)(p + 1824) = D_00347e60;
    SEQUENCE_dtor(p + 1848);
    *(u8**)(p + 1824) = D_00347f98;
    if (p + 600) {
    L2:
        if (p + 600 != e) {
            e -= 408;
            (*(VF12*)(*(u8**)e + 12))(e);
            goto L2;
        }
    }
    *(u8**)(p + 192) = D_00347e60;
    SEQUENCE_dtor(p + 216);
    *(u8**)(p + 192) = D_00347f98;
    *(u8**)(p + 28) = D_0035eb98;
    func_0023c098(p + 76);                              
    func_002369f0(p + 52);                              
    *(u8**)(p + 28) = D_00347f98;
    *(u8**)(p + 0) = D_00347f98;
}
}  // namespace n002c1200

// ---- 002c1320 from src/anon/batch_w265.cpp
namespace n002c1320 {
extern u8 D_00361aa0[] asm("D_00361aa0");
extern u8* D_00361a90 asm("D_00361a90");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_0035eb98[] asm("D_0035eb98");
extern void* D_00347f80 asm("D_00347f80");
void func_00170950(u32) asm("func_00170950");
void func_00239870(u8*) asm("func_00239870");
void func_0023c098(u8*) asm("func_0023c098");
void func_002369f0(u8*) asm("func_002369f0");
typedef void (*VF265)(u8*);
typedef void (*VF265b)(u8*, u8*);
void func_002c1320(u8* p) asm("func_002c1320");
void func_002c1320(u8* p) {
    *(void**)p = D_00361aa0;
    func_00170950(*(u32*)(p + 188));
    D_00361a90 = (D_00361a90 == p) ? 0 : D_00361a90;
    if (p + 2232 != 0) {
        u8* e = p + 3048;
    top1:
        if (p + 2232 == e) goto out1;
        e -= 408;
        (*(VF265**)e)[3](e);
        goto top1;
    out1:;
    }
    {
        u8* m = p + 1824;
        *(void**)m = D_00347e60;
        func_00239870(p + 1848);
        *(void**)m = D_00347f98;
        if (p + 600 != 0) {
        top2:
            if (p + 600 == m) goto out2;
            m -= 408;
            (*(VF265**)m)[3](m);
            goto top2;
        out2:;
        }
    }
    *(void**)(p + 192) = D_00347e60;
    func_00239870(p + 216);
    *(void**)(p + 192) = D_00347f98;
    *(void**)(p + 28) = D_0035eb98;
    func_0023c098(p + 76);                              
    func_002369f0(p + 52);                              
    *(void**)(p + 28) = D_00347f98;
    *(void**)p = D_00347f98;
    {
        u8* o = *(u8**)((u8*)D_00347f80 + 20);
        (*(VF265b**)o)[1](o, p);
    }
}
}  // namespace n002c1320

// ---- 002c1460 from src/worldmap/wm_total_info.cpp (dk::WM_TOTAL_INFO::getBaseNum)
namespace n002c1460 {
extern u32 D_00375540 asm("D_00375540");
s32 getBaseNum(void*, s32 index) asm("_ZN2dk13WM_TOTAL_INFO10getBaseNumEi");
s32 getBaseNum(void*, s32 index) {
    return (s32)(*(s16*)((u32)&D_00375540 + ((u32)index << 1)));
}
}  // namespace n002c1460

// ---- 002c1478 from src/anon/tiny_auto80.cpp
namespace n002c1478 {
void func_002c1478(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002c1478jjjj");
void func_002c1478(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14, r15;
    if (r4 != 0u) {
        r15 = *(volatile u32*)((u32)r4 + (s32)(0));
        r14 = *(volatile u32*)((u32)r15 + (s32)(16));
        ((void(*)(u32,u32,u32,u32))(u32)r14)(r4, r5, r6, r7);
    }
}
}  // namespace n002c1478

// ---- 002c14a8 from src/anon/batch_w24.cpp
namespace n002c14a8 {
void wm_total_info_fadeout(void*) asm("_ZN2dk13WM_TOTAL_INFO7fadeoutEv");
void func_00138c10(u8*, s32) asm("func_00138c10");
void wm_total_info_fadeout(void* self) {
    u8* s = (u8*)self + 192;
    if (*(s32*)(s + 388) != 77) {
        func_00138c10(s, 77);
        *(s32*)(s + 392) = -1;
    }
}
}  // namespace n002c14a8

// ---- 002c14e8 from src/anon/batch_w109.cpp
namespace n002c14e8 {
void func_00236d60(u8*) asm("func_00236d60");
s32 func_00139d78(u8*) asm("func_00139d78");
void func_00139510(u8*) asm("func_00139510");
s32 func_00139538(u8*) asm("func_00139538");
void func_0014cbe0(s32*, s32*, s32*, s32*) asm("func_0014cbe0");
s32 func_002c5238(s32, s32, s32*) asm("func_002c5238");
s32 func_0023aa98(u8*) asm("func_0023aa98");
s32 func_001396c0(u8*) asm("func_001396c0");
void func_00138c10(u8*, s32) asm("func_00138c10");
void func_00138c68(u8*, s32, s32) asm("func_00138c68");
void func_00139580(u8*) asm("func_00139580");
void func_00139570(u8*) asm("func_00139570");
void func_0023f0c0(u8*) asm("func_0023f0c0");
void func_002c1460(u8*, s32) asm("func_002c1460");
typedef void (*VFn2c14e8)(u8*);
struct F2c14e8 { u32 f : 1; };
void func_002c14e8(u8* self) asm("func_002c14e8");
void func_002c14e8(u8* self) {
    s32 ids[3];
    s32 ids2[2];
    s32 a, b, c, d;
    func_00236d60(self);                        
    if (((F2c14e8*)(self + 24))->f) {
        if (func_00139d78(self + 28)) func_00139510(self + 28);
        (*(VFn2c14e8*)(*(u8**)self + 20))(self);
        return;
    }
    if (func_00139538(self + 192)) {
        ((F2c14e8*)(self + 24))->f = 1;
        return;
    }
    func_0014cbe0(&a, &b, &c, &d);
    s32 pos = 0;
    s32 n = func_002c5238(a, 3, ids);
    s32 step = func_0023aa98(self + 624);
    if (!func_001396c0(self + 192)) {
        for (s32 i = 0; i < 3; i++) {
            u8* o = self + 600 + i * 408;
            func_00138c10(o, ids[i] + 39);
            func_00138c68(o, pos, 0);
            if (2 - i < n) {
                func_00139580(o);
                pos += step;
            } else {
                func_00139570(o);
            }
        }
    }
    func_00138c68(self + 1824, pos, 0);
    pos += func_0023aa98(self + 1848);
    func_002c5238(b, 2, ids2);
    u8* o = self + 2232;
    for (s32 i = 0; i < 2; i++) {
        func_00138c10(o, ids2[i] + 39);
        func_00138c68(o, pos, 0);
        pos += step;
        o += 408;
    }
    func_0023f0c0(self + 28);
    func_002c1460(self, 2);
}
}  // namespace n002c14e8

// ---- 002c16e8 (gap, never written): dk::WM_TOTAL_INFO vtable 0x361a98 slot 2
namespace n002c16e8 {
void func_00236788(u32) asm("func_00236788");
s32 isLeave(u8*) asm("_ZN2dk5Obj2D7isLeaveEv");
void getNum(u8*) asm("_ZN2Tz6Layout6getNumEv");
void getBaseNum(u8*, s32) asm("_ZN2dk13WM_TOTAL_INFO10getBaseNumEi");
void func_002c16e8(u8* self) asm("func_002c16e8");
void func_002c16e8(u8* self) {
    u8* s = self + 28;
    func_00236788(*(u32*)(self + 3048));
    if (isLeave(s)) return;
    getNum(s);
    getBaseNum(self, 2);
}
}  // namespace n002c16e8

// ---- 002c1750 from src/anon/tiny_auto80_queue.cpp
namespace n002c1750 {
extern u32 func_00361a90 asm("func_00361a90");
extern u32 D_00347f80 asm("D_00347f80");
void func_002c0ca0(...) asm("func_002c0ca0");
void func_002c1750() asm("_Z13func_002c1750v");
void func_002c1750() {
    if (func_00361a90 != 0) {
        return;
    }
    u32 t6 = D_00347f80;
    u32 a0 = *(u32*)(t6 + 20);
    u32 t7 = *(u32*)a0;
    u32 v0 = ((u32(*)(u32, u32, u32))(*(u32*)t7))(a0, 3052, 0);
    func_002c0ca0(v0);
}
}  // namespace n002c1750

// ---- 002c17a0 from src/worldmap/wm_total_info.cpp (dk::WM_TOTAL_INFO::exit)
namespace n002c17a0 {
extern u32 D_00361a90 asm("D_00361a90");
void fadeout(u32) asm("_ZN2dk13WM_TOTAL_INFO7fadeoutEv");
void wm_exit() asm("_ZN2dk13WM_TOTAL_INFO4exitEv");
void wm_exit() {
    u32 ptr = D_00361a90;
    if (ptr) {
        fadeout(ptr);
        D_00361a90 = 0;
    }
}
}  // namespace n002c17a0

// ---- 002c17d8 from src/anon/batch_w41.cpp
namespace n002c17d8 {
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
void func_0017f5e0(u8*, u32, u32, f32, f32) asm("func_0017f5e0");
void func_002c17d8(u32, u8* p) asm("func_002c17d8");
void func_002c17d8(u32, u8* p) {
    *(u32*)(p + 264) |= 2;
    asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(p + 32) : "memory");
    f32 z = 0.0f;
    u8* q = p + 320;
    func_0017f488(q, 161, z, z);
    func_0017f5e0(q, 0, 0, z, z);
}
}  // namespace n002c17d8

// ---- 002c1848 (gap, never written): vtable 0x361ab8 slot 1
namespace n002c1848 {
void func_002c1848(u32, u8* p) asm("func_002c1848");
void func_002c1848(u32, u8* p) {
    *(u32*)(p + 264) &= ~2;
}
}  // namespace n002c1848

// ---- 002c1860 from src/anon/batch_w42.cpp
namespace n002c1860 {
void change_action(void*, s32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
void func_002c7060(void*) asm("func_002c7060");
static inline bool positive(f32 x) { return 0.0f < x; }
void func_002c1860(u32, u8* obj) asm("func_002c1860");
void func_002c1860(u32, u8* obj)
{
    u8* s = obj + 2928;
    func_002c7060(s);
    if (!positive(*(f32*)(s + 84))) change_action(obj, 47);
}
}  // namespace n002c1860

// ---- 002c18d0 (gap, never written): vtable 0x361ab8 slot 7, returns a zero vector by hidden pointer
namespace n002c18d0 {
u8* func_002c18d0(u8* r) asm("func_002c18d0");
u8* func_002c18d0(u8* r) {
    asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(r) : "memory");
    return r;
}
}  // namespace n002c18d0

// ---- 002c18e0 from src/anon/batch_w36.cpp
namespace n002c18e0 {
struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
void func_002c5f78(u8*) asm("func_002c5f78");
void func_002c18e0(u32, u8* p) asm("func_002c18e0");
void func_002c18e0(u32, u8* p) {
    Q16 tmp;
    Q16* d = (Q16*)(p + 32);
    f32 s = *(f32*)(*(u8**)(p + 300) + 36);
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
        : : "r"(&tmp), "r"(p + 16), "f"(s) : "$8", "memory");
    if (d != &tmp) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(&tmp) : "$8", "memory");
    func_0017f488(p + 320, 154, 0.0f, 0.0f);
    func_002c5f78(p);
}
}  // namespace n002c18e0

// ---- 002c1950 from src/anon/batch_w207.cpp
namespace n002c1950 {
void func_0017f488(void*, s32, f32, f32) asm("func_0017f488");
u32 func_002c5fa0(u32) asm("func_002c5fa0");
u32 func_002c1950(u32 a, u32 b) asm("func_002c1950");
u32 func_002c1950(u32 a, u32 b) {
    func_0017f488((void*)(b + 320), 0, 8.0f, 0.0f);
    return func_002c5fa0(b);
}
}  // namespace n002c1950

// ---- 002c1990 from src/anon/tiny_wrappers_more.cpp
namespace n002c1990 {
extern "C" u32 YS_OBJ_change_action(u32, u32, u32, u32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
u32 func_002c1990(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002c1990jjjj");
u32 func_002c1990(u32 a0, u32 a1, u32 a2, u32 a3) {
    return YS_OBJ_change_action(a1, 0x0000003bu, a2, a3);
}
}  // namespace n002c1990

// ---- 002c19b0 (gap, never written): vtable 0x361ae8 slot 6
namespace n002c19b0 {
s32 func_00180618(u8*) asm("_Z16ctarget_00180618jjjj");
void change_action(u8*, s32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
void func_002c19b0(u32, u8* o) asm("func_002c19b0");
void func_002c19b0(u32, u8* o) {
    *(f32*)(o + 28) = *(f32*)(*(u8**)(o + 300) + 36);
    if (!func_00180618(o + 320)) return;
    u32 t = *(u32*)(*(u8**)(o + 2884) + 8) & 1;
    if (t) return;
    change_action(o, 47);
}
}  // namespace n002c19b0

// ---- 002c1a18 from src/anon/batch_wlit.cpp
namespace n002c1a18 {
void func_00184540(u8* p, u32 a, f32 x, f32 y) asm("func_00184540");
u8* func_002c1a18(u8* p, u32 a, u32 b) asm("func_002c1a18");
u8* func_002c1a18(u8* p, u32 a, u32 b) { f32 f = 0.95f; func_00184540(p, b, f, f); return p; }
}  // namespace n002c1a18

// .rodata tables of this file, emitted in place: worldmap::Gumi::getCourseName message ids
// (0x3754f0) and the per-course triples used by 0x2c1ae8 (0x375518).
extern const u32 R_003754f0[9] asm("D_003754f0") = {
    0x8224, 0x8225, 0x8226, 0x8227, 0x8228, 0x8229, 0x822a, 0x822b, 0x822c,
};
extern const u8 R_00375518[9][3] asm("D_00375518") = {
    { 0x00, 0x09, 0x12 }, { 0x01, 0x0a, 0x13 }, { 0x05, 0x0e, 0x14 }, { 0x06, 0x0f, 0x15 },
    { 0x02, 0x0b, 0x16 }, { 0x07, 0x10, 0x17 }, { 0x03, 0x0c, 0x18 }, { 0x04, 0x0d, 0x19 },
    { 0x08, 0x11, 0x1a },
};

// ---- 002c1a58 from src/anon/batch_w58.cpp
namespace n002c1a58 {
void func_002be770(u8*) asm("func_002be770");
extern u8 D_00361b20[] asm("D_00361b20");
void func_002c1a58(u8* p) asm("func_002c1a58");
void func_002c1a58(u8* p) {
    func_002be770(p);
    p[2792] = 0;
    *(void**)p = D_00361b20;
    *(u32*)(p + 1420) |= 1;
    *(u32*)(p + 2788) = 0;
}
}  // namespace n002c1a58

// ---- 002c1aa0 from src/anon/batch_w59.cpp
namespace n002c1aa0 {
void func_002be770(u8*) asm("func_002be770");
extern u8 D_00361b20[] asm("D_00361b20");
void func_002c1aa0(u8* p) asm("func_002c1aa0");
void func_002c1aa0(u8* p) {
    func_002be770(p);
    *(u32*)p = (u32)D_00361b20;
    *(u32*)(p + 1420) |= 1;
    *(u8*)(p + 2792) = 0;
    *(u32*)(p + 2788) = 0;
}
}  // namespace n002c1aa0

// ---- 002c1ae8 from src/anon/batch_w43.cpp
namespace n002c1ae8 {
s32 func_002c1b48(void*) asm("func_002c1b48");
struct B3 { u8 b[3]; };
extern B3 D_00375518[] asm("D_00375518");
u32 func_001c2b58(s32) asm("func_001c2b58");
void func_002c1b60(void*, u32) asm("func_002c1b60");
void func_00198450(void*) asm("func_00198450");
void func_002c1ae8(u8* p) asm("func_002c1ae8");
void func_002c1ae8(u8* p) {
    *(B3**)(p + 2788) = &D_00375518[func_002c1b48(p) - 1];
    func_002c1b60(p, func_001c2b58(func_002c1b48(p)));
    func_00198450(p);
}
}  // namespace n002c1ae8

// ---- 002c1b48 from src/worldmap/gumi.cpp (worldmap::Gumi::getCourse)
namespace n002c1b48 {
u32 get_unit_arg(void*, int) asm("_ZN2YS3OBJ12get_unit_argEi");
u32 getCourse(void* self) asm("_ZN8worldmap4Gumi9getCourseEv");
u32 getCourse(void* self) {
    return get_unit_arg(self, 1);
}
}  // namespace n002c1b48

// ---- 002c1b60 from src/anon/batch_w61.cpp
namespace n002c1b60 {
void func_002c1cb0(u32, u8) asm("func_002c1cb0");
void func_002c1b60(u8* p, u8* a) asm("func_002c1b60");
void func_002c1b60(u8* p, u8* a) {
    if (*a == 1) goto clr;
    if (*a != 2) goto set;
clr:
    *(u32*)(p + 264) &= ~2;
    *(u32*)(p + 264) &= ~0x20;
    *(u32*)(p + 264) &= ~0x40;
    goto done;
set:
    *(u32*)(p + 264) |= 0x62;
done:
    func_002c1cb0(*(u32*)(p + 2788), *a);
    p[2792] = *a;
}
}  // namespace n002c1b60

// ---- 002c1be0 (gap, never written): worldmap::Gumi vtable 0x361b18 last slot
namespace n002c1be0 {
u32 getCourse(u8*) asm("_ZN8worldmap4Gumi9getCourseEv");
u8* courseGet(u32) asm("_ZN2YS6COURSE3GetEi");
void func_0016ac38(u8*, s32, s32, s32, s32) asm("func_0016ac38");
void func_002c1be0(u8* p) asm("func_002c1be0");
void func_002c1be0(u8* p) {
    u8* c = courseGet(getCourse(p));
    if (p[2792] == 1 && c[0] == 2) func_0016ac38(p, 0, 1, 0, 0);
}
}  // namespace n002c1be0

// ---- 002c1c50 from src/anon/batch_w15.cpp
namespace n002c1c50 {
u32 func_002c1b48(void*) asm("func_002c1b48");
u32 func_001c2b58(u32) asm("func_001c2b58");
void func_002c1b60(void*, u32) asm("func_002c1b60");
void func_002c1c50(void* p) asm("func_002c1c50");
void func_002c1c50(void* p) {
    func_002c1b60(p, func_001c2b58(func_002c1b48(p)));
}
}  // namespace n002c1c50

// ---- 002c1c88 from src/anon/tiny_auto80_fptr4.cpp
namespace n002c1c88 {
u32 func_00192048(u32, u32, u32, u32) asm("_Z13func_00192048jjjj");
extern u8 D_003754f0 asm("D_003754f0");
u32 func_002c1c88(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002c1c88jjjj");
u32 func_002c1c88(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15;
    r15 = (u32)&D_003754f0;
    r4 = (u32)(r4 << 2);
    r4 = (u32)(r4 + r15);
    r4 = *(u32*)((u32)r4 + (s32)(-4));
    return func_00192048(r4, r5, r6, r7);
}
}  // namespace n002c1c88

// ---- 002c1cb0 from src/anon/batch_w52.cpp
namespace n002c1cb0 {
void func_00161000(u8) asm("func_00161000");
void func_00160fd0(u8) asm("func_00160fd0");
void func_002c1cb0(u8* c, s32 mode) asm("func_002c1cb0");
void func_002c1cb0(u8* c, s32 mode) {
    switch (mode) {
    case 1:
        func_00160fd0(c[0]);
        func_00161000(c[1]);
        func_00161000(c[2]);
        break;
    case 2:
        func_00161000(c[0]);
        func_00160fd0(c[1]);
        func_00160fd0(c[2]);
        break;
    default:
        func_00161000(c[0]);
        func_00161000(c[1]);
        func_00161000(c[2]);
        break;
    }
}
}  // namespace n002c1cb0

// ---- 002c1d48 (gap, never written): find the Gumi object of a course
namespace n002c1d48 {
u8* nextObj(u8*) asm("_Z16ctarget_001b9bc8jjjj");
u32 getCourse(u8*) asm("_ZN8worldmap4Gumi9getCourseEv");
u8* func_002c1d48(u32 course) asm("func_002c1d48");
u8* func_002c1d48(u32 course) {
    u8* o = 0;
    u8* r;
    while ((o = nextObj(o)) != 0) {
        u32 flags = *(u32*)(o + 1420);
        if (flags & 1) {
            if (getCourse(o) == course) { r = o; goto done; }
        }
    }
    r = 0;
done:
    return r;
}
}  // namespace n002c1d48

// ---- 002c1dc0 from src/anon/auto80_199_queue.cpp
namespace n002c1dc0 {
extern u8 D_00361ba8 asm("D_00361ba8");
u8* func_001c2b58(...) asm("_ZN2YS6COURSE3GetEi");
void func_002c2288(u32) asm("func_002c2288");
void func_002c2248(u32) asm("func_002c2248");
void func_002c2268(u32) asm("func_002c2268");
void func_002c2228(u32) asm("func_002c2228");
void func_002c1dc0() asm("_Z13func_002c1dc0v");
void func_002c1dc0() {
    u8* s0 = &D_00361ba8;
    u32 s1 = 1;
    while ((s32)s1 < 22) {
        u8 t7 = func_001c2b58(s1)[0];
        switch (t7) {
        case 1:
            func_002c2268(s0[1]);
            func_002c2288(s0[0]);
            func_002c2248(s0[2]);
            break;
        case 2:
            func_002c2288(s0[1]);
            func_002c2268(s0[0]);
            func_002c2228(s0[2]);
            break;
        default:
            func_002c2288(s0[1]);
            func_002c2288(s0[0]);
            func_002c2248(s0[2]);
            break;
        }
        s1 = s1 + 1;
        s0 = s0 + 3;
    }
}
}  // namespace n002c1dc0

