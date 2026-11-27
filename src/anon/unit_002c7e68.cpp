// Linked unit 0x2c7e68-0x2c87f8: world map landing info window (dk::WM_LANDING_INFO), second part:
// D2/D1/D0 dtors to the end of the file. The first part (unit_002c6eb8.cpp) needs -fno-strict-aliasing,
// this part needs strict aliasing (vptr store before the handle load in the dtors).
#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"

// ---- 002c7e68 (from batch_w289.cpp)
namespace n002c7e68 {
extern void* D_00347f98[] asm("D_00347f98");
extern void* D_00347e60[] asm("D_00347e60");
extern void* D_00361de8[] asm("D_00361de8");
extern void* D_0035eb98[] asm("D_0035eb98");
extern u8* D_00361dd8 asm("D_00361dd8");
void func_00170950(void*) asm("func_00170950");
void func_00239870(u8*) asm("func_00239870");
void func_0023c098(u8*) asm("func_0023c098");
// set_vtbl_36eae8_then_call
void func_002369f0(u8*) asm("func_002369f0");
// set_vtbl_36eac8_then_call
typedef void (*Dtor2c7e68)(u8*);
#define DestroyArr2c7e68(B, E, SZ) \
    if ((B) != 0) { \
        u8* e = (E); \
        u8* b = (B); \
        for (;;) { \
            if (b == e) break; \
            e -= (SZ); \
            (*(Dtor2c7e68*)(*(u8**)e + 12))(e); \
        } \
    }
static inline __attribute__((always_inline)) void Seq2c7e68(u8* q) {
    *(void***)q = D_00347e60;
    func_00239870(q + 24);
    *(void***)q = D_00347f98;
}
static inline __attribute__((always_inline)) void Body2c7e68(u8* p) {
    *(void***)p = D_00361de8;
    func_00170950(*(void**)(p + 188));
    D_00361dd8 = (D_00361dd8 == p) ? 0 : D_00361dd8;
    DestroyArr2c7e68(p + 5120, p + 5936, 408);
    Seq2c7e68(p + 4712);
    DestroyArr2c7e68(p + 3488, p + 4712, 408);
    DestroyArr2c7e68(p + 2672, p + 3488, 408);
    Seq2c7e68(p + 2264);
    Seq2c7e68(p + 1856);
    DestroyArr2c7e68(p + 632, p + 1856, 408);
    Seq2c7e68(p + 196);
    *(void***)(p + 28) = D_0035eb98;
    func_0023c098(p + 76);  // set_vtbl_36eae8_then_call
    func_002369f0(p + 52);  // set_vtbl_36eac8_then_call
    *(void***)(p + 28) = D_00347f98;
    *(void***)p = D_00347f98;
}

void func_002c7e68(u8* p) asm("func_002c7e68");
void func_002c7e68(u8* p) {
    Body2c7e68(p);
}
#undef DestroyArr2c7e68
}  // namespace n002c7e68

// ---- 002c8028 (from batch_w289.cpp)
namespace n002c8028 {
extern void* D_00347f98[] asm("D_00347f98");
extern void* D_00347e60[] asm("D_00347e60");
extern void* D_00361de8[] asm("D_00361de8");
extern void* D_0035eb98[] asm("D_0035eb98");
extern u8* D_00361dd8 asm("D_00361dd8");
void func_00170950(void*) asm("func_00170950");
void func_00239870(u8*) asm("func_00239870");
void func_0023c098(u8*) asm("func_0023c098");
// set_vtbl_36eae8_then_call
void func_002369f0(u8*) asm("func_002369f0");
// set_vtbl_36eac8_then_call
typedef void (*Dtor2c7e68)(u8*);
#define DestroyArr2c7e68(B, E, SZ) \
    if ((B) != 0) { \
        u8* e = (E); \
        u8* b = (B); \
        for (;;) { \
            if (b == e) break; \
            e -= (SZ); \
            (*(Dtor2c7e68*)(*(u8**)e + 12))(e); \
        } \
    }
static inline __attribute__((always_inline)) void Seq2c7e68(u8* q) {
    *(void***)q = D_00347e60;
    func_00239870(q + 24);
    *(void***)q = D_00347f98;
}
static inline __attribute__((always_inline)) void Body2c7e68(u8* p) {
    *(void***)p = D_00361de8;
    func_00170950(*(void**)(p + 188));
    D_00361dd8 = (D_00361dd8 == p) ? 0 : D_00361dd8;
    DestroyArr2c7e68(p + 5120, p + 5936, 408);
    Seq2c7e68(p + 4712);
    DestroyArr2c7e68(p + 3488, p + 4712, 408);
    DestroyArr2c7e68(p + 2672, p + 3488, 408);
    Seq2c7e68(p + 2264);
    Seq2c7e68(p + 1856);
    DestroyArr2c7e68(p + 632, p + 1856, 408);
    Seq2c7e68(p + 196);
    *(void***)(p + 28) = D_0035eb98;
    func_0023c098(p + 76);  // set_vtbl_36eae8_then_call
    func_002369f0(p + 52);  // set_vtbl_36eac8_then_call
    *(void***)(p + 28) = D_00347f98;
    *(void***)p = D_00347f98;
}

void func_002c8028(u8* p) asm("func_002c8028");
void func_002c8028(u8* p) {
    Body2c7e68(p);
}
#undef DestroyArr2c7e68
}  // namespace n002c8028

// ---- 002c81e8 (from batch_w290.cpp)
namespace n002c81e8 {
extern void* D_00361de8[] asm("D_00361de8");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_0035eb98[] asm("D_0035eb98");
extern u32 D_00361dd8 asm("D_00361dd8");
void func_00170950(u32) asm("func_00170950");
void func_00239870(void*) asm("func_00239870");
void func_0023c098(void*) asm("func_0023c098");
// set_vtbl_36eae8_then_call
void func_002369f0(void*) asm("func_002369f0");
// set_vtbl_36eac8_then_call
void func_00105110(void*) asm("func_00105110");
struct W290VE { virtual void f0(); virtual void f1(); virtual void f2(); virtual ~W290VE(); u8 pad[404]; };
struct W290B0 { u32 vt; ~W290B0() { vt = (u32)D_00347f98; } };
struct W290S24 { u8 d[384]; ~W290S24() { func_00239870(this); } };
struct W290E1 : W290B0 { u8 p[20]; W290S24 s; ~W290E1() { vt = (u32)D_00347e60; } };
struct W290S52 { u8 d[24]; ~W290S52() { func_002369f0(this); } };
struct W290S76 { u8 d[120]; ~W290S76() { func_0023c098(this); } };
struct W290M28 : W290B0 { u8 p[20]; W290S52 a; W290S76 b; ~W290M28() { vt = (u32)D_0035eb98; } };
struct W290Big : W290B0 {
    u8 p4[24];
    W290M28 m28;
    W290E1 m196;
    u8 p604[28];
    W290VE a632[3];
    W290E1 m1856;
    W290E1 m2264;
    W290VE a2672[2];
    W290VE a3488[3];
    W290E1 m4712;
    W290VE a5120[2];
    ~W290Big() __attribute__((always_inline));
};
inline W290Big::~W290Big() {
        *(void***)this = D_00361de8;
        func_00170950(*(u32*)((u8*)this + 188));
        u32 t = D_00361dd8;
        if (t == (u32)this) t = 0;
        D_00361dd8 = t;
}


void func_002c81e8(W290Big* p) asm("func_002c81e8");
void func_002c81e8(W290Big* p) {
    p->~W290Big();
    func_00105110(p);
}
}  // namespace n002c81e8

// ---- 002c83a8 (from tiny.cpp)
namespace n002c83a8 {
extern u32 D_00375540 asm("D_00375540");


u32 func_002c83a8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002c83a8");
u32 func_002c83a8(u32 a0, u32 a1, u32 a2, u32 a3) {  // halfword_375540_b
    (void)a1;
    (void)a2;
    (void)a3;
    return (u32)(s32)(*(s16*)((u32)&D_00375540 + ((u32)a1 << 1) + (0)));
}
}  // namespace n002c83a8

// ---- 002c83c0 (from auto80_199_queue.cpp)
namespace n002c83c0 {


void func_002c83c0(u8* a0) asm("func_002c83c0");
void func_002c83c0(u8* a0) {
    u8* s1 = a0;
    u8* t6 = a0 + 196;
    u8* s0;

    u32 t7 = *(u32*)(a0 + 24);
    t7 = t7 & 1;
    if (t7 != 0) {
        u32* vt = *(u32**)a0;
        ((VCall20)vt[5])(a0);
        return;
    }

    if (func_00139538(t6) == 0) {
        goto L_fail;
    }
    if (func_00139538(s1 + 1856) == 0) {
        goto L_fail;
    }
    if (func_00139538(s1 + 2264) == 0) {
        goto L_fail;
    }

    s0 = s1 + 28;
    if (func_00139d78(s0) != 0) {
        func_00139510(s0);
    }

    t7 = *(u32*)(s1 + 24);
    t7 = t7 | 1;
    *(u32*)(s1 + 24) = t7;
    return;

L_fail:
    func_00236d60();  // clear_64_entries_24
}
}  // namespace n002c83c0

// ---- 002c8478: forwards the object's handle at +5936 (never written before)
namespace n002c8478 {
void func_00236788(u32) asm("func_00236788");
void func_002c8478(u8* p) asm("func_002c8478");
void func_002c8478(u8* p) { func_00236788(*(u32*)(p + 5936)); }
}  // namespace n002c8478

// ---- 002c8490 (from auto80_199_queue.cpp)
namespace n002c8490 {


void func_002c8490(u8* a0) asm("func_002c8490");
void func_002c8490(u8* a0) {
    u8* s0 = a0 + 196;
    u8* s1 = a0 + 1856;
    u8* s2 = a0 + 2264;

    if (func_00139d78(s0) != 0) {
        func_00139510(s0);
    }

    if (func_00139d78(s1) != 0) {
        func_00139510(s1);
    }

    if (func_00139d78(s2) != 0) {
        func_00139510(s2);
    }
}
}  // namespace n002c8490

// ---- 002c8520 (from tiny_auto80.cpp)
namespace n002c8520 {


void func_002c8520(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002c8520");
void func_002c8520(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14, r15;
    if (r4 != 0u) {
        r15 = *(u32*)((u32)r4 + (s32)(0));
        r14 = *(u32*)((u32)r15 + (s32)(16));
        ((void(*)(u32,u32,u32,u32))(u32)r14)(r4, r5, r6, r7);
    }
}
}  // namespace n002c8520

// ---- 002c8550 (from auto80_199_queue.cpp)
namespace n002c8550 {


void func_002c8550(u8* a0) asm("func_002c8550");
void func_002c8550(u8* a0) {
    u8* s0 = a0;
    u8* s2 = a0 + 196;
    s32 s1 = -1;

    func_00138c10(s2, 154);
    *(s32*)(s2 + 392) = s1;

    u8* s3 = s0 + 1856;
    func_00138c10(s3, 74);
    *(s32*)(s3 + 392) = s1;

    s0 = s0 + 2264;
    func_00138c10(s0, 67);
    *(s32*)(s0 + 392) = s1;
}
}  // namespace n002c8550

// ---- 002c85c8 (from batch_w56.cpp)
namespace n002c85c8 {
// 002c85c8
s32 func_002c5150(u32) asm("func_002c5150");
void func_002c8490(u8*) asm("func_002c8490");
void* func_001050d8(u32) asm("func_001050d8");
void func_002c77b8(void*, u32) asm("func_002c77b8");
extern u8* D_00361dd8 asm("D_00361dd8");

void func_002c85c8(u32 a) asm("func_002c85c8");
void func_002c85c8(u32 a)
{
    if (func_002c5150(a)) return;
    u8* p = D_00361dd8;
    if (p) {
        if (*(u32*)(p + 192) == a) return;
        func_002c8490(p);
        D_00361dd8 = 0;
    }
    func_002c77b8(func_001050d8(5944), a);
}
}  // namespace n002c85c8

// ---- 002c8648: dk::WM_LANDING_INFO::exit (from src/worldmap/wm_landing_info.cpp)
namespace n002c8648 {
extern u32 D_00361dd8 asm("D_00361dd8");
void WM_LANDING_INFO_fadeout(u32) asm("func_002c8550");
void WM_LANDING_INFO_exit() asm("_ZN2dk15WM_LANDING_INFO4exitEv");
void WM_LANDING_INFO_exit() {
    u32 ptr = D_00361dd8;
    if (ptr) {
        WM_LANDING_INFO_fadeout(ptr);
        D_00361dd8 = 0;
    }
}
}  // namespace n002c8648

// ---- 002c8680 (from batch_w3708.cpp)
namespace n002c8680 {
struct Sub { u8 pad[0x18c]; void* p18c; s32 x190; u8 pad2[4]; };
struct Cnt { u8 pad[0x19c]; s32 x19c; s32 x1a0; };
struct Self {
    u8 pad0[0xc4];
    Cnt cnt;          // 0xc4 .. 0x264
    u8 pad1[0x278 - 0x268];
    Sub subs[1];      // 0x278 (overlaps 0x290)
};
s32 func_002c22f0(s32) asm("func_002c22f0");
s32 func_002c2358(s32) asm("func_002c2358");
void func_001386e0(Sub*, s32, s32, s32, s32, s32) asm("func_001386e0");
void func_001396b0(Sub*) asm("func_001396b0");
void func_0031a260(Sub*, s32) asm("func_0031a260");
void func_00139660(Sub*) asm("func_00139660");
void func_00139688(Sub*) asm("func_00139688");
s32 func_0023aa18(void*) asm("func_0023aa18");
s32 func_0023aa58(void*) asm("func_0023aa58");
void func_00138c68(Sub*, s32, s32) asm("func_00138c68");

void func_002c8680(Self* self, s32 arg) asm("func_002c8680");
// Every use goes through this accessor (no pointer variable in the loop): loop.c then makes the
// pointer a reduced giv whose start value is set after the hoisted 150, as in the original.
static inline Sub* SubAt(Self* self, s32 i) { return &self->subs[i]; }
void func_002c8680(Self* self, s32 arg) {
    s32 n = func_002c22f0(arg);
    if (n != 0) {
        s32 i = 0;
        s32 m = func_002c2358(arg);
        Cnt* c; u8* z;
        if (i < n) {
c = &self->cnt; z = (u8*)self + 0x290;
            do {
                func_001386e0(SubAt(self, i), 0x7585, *(s32*)((u8*)self + 0x1734), *(s32*)((u8*)self + 0x1730), i < m ? 150 : 149, 201);
                SubAt(self, i)->p18c = c;
                func_001396b0(SubAt(self, i));
                if (SubAt(self, i)->p18c) {
                    SubAt(self, i)->x190 = 0;
                    func_001396b0(SubAt(self, i));
                    if (SubAt(self, i)->x190) func_0031a260(SubAt(self, i), 0);
                }
                func_00139660(SubAt(self, i));
                func_00139688(SubAt(self, i));
                s32 a = func_0023aa18(z);
                func_00138c68(SubAt(self, i), a - func_0023aa58(z) * i, 0);
                func_001396b0(SubAt(self, i));
                i++;
            } while (i < n);
        } else {
c = &self->cnt; z = (u8*)self + 0x290;
        }
        s32 v = -func_0023aa58(z);
        c->x1a0 = 0;
        c->x19c = v * n / 2;
    }
}
}  // namespace n002c8680

