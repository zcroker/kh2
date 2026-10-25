#include "../common/types.h"

// Batch w6: small leaf / wrapper functions.

// Object whose first word is a vtable pointer.
struct VObj { void** vt; };

extern "C" {

void ys_area_read(void* task) asm("_ZN2YS8AreaReadEP4TASK");
void ys_prepare_scene(void) asm("_ZN2YS5EVENT12PrepareSceneEv");
u32 ys_is_mark_history(void) asm("_ZN2YS8FIELDOBJ15is_mark_historyEv");
u32 ys_can_end(void) asm("_ZN2YS9SACRIFICE6CanEndEv");

// Forward a to the global object's second virtual method.
extern VObj* D_0032b9cc;
// 00102ed8: moved to src/common/title.cpp

// True when the state at +0xb6c is 16, 12 or 15.
u32 func_00111278(u8* p) {
    s32 v = *(s32*)(p + 0xb6c);
    if (v == 16 || v == 12 || v == 15) return 1;
    return 0;
}

void func_0011c798(u8* p, u32 a) {
    VObj* o = *(VObj**)(p + 20);
    ((void (*)(VObj*, u32, u32))o->vt[13])(o, *(u32*)(p + 260), a);
}

// Set a timer (at least 15000) with a byte parameter and raise its flag.
struct S4240 { u8 flag; u8 b; u8 pad[2]; s32 time; };
extern S4240 D_004f4240;
void func_001671e8(s32 t, u8 b) {
    if (t < 15000) t = 15000;
    D_004f4240.time = t;
    D_004f4240.flag = 1;
    D_004f4240.b = b;
}

void func_00170888(void*);
void func_001badd8(void);
void func_001afaf0(void*);
void ys_area_read(void* task) {
    func_00170888(task);
    func_001badd8();
    func_001afaf0(task);
}

void func_0017f488(u32, u32, f32, f32);
void func_00171150(u32* p) {
    func_0017f488(p[0] + 320, p[1], *(f32*)&p[2], 0.0f);
}

void func_001cfac0(u32, f32, f32, f32, f32);
struct S1a40 { u32* obj; f32 a, b, c, d; };
void func_00171a40(S1a40* p) {
    func_001cfac0(p->obj[1], p->a, p->b, p->c, p->d);
}

void func_00187a18(u32, u32, u32, u32, void*);
void func_00172f00(u32* p) {
    func_00187a18(p[0], p[1], p[2], p[3], p + 4);
}

// Zero three VU0 vectors.
void func_00178cf8(u8* p) {  // clear_vecs_three
    asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(p + 32) : "memory");
    asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(*(u8**)(p + 0xb44) + 0xa30) : "memory");
    asm volatile(".set noreorder\n\tvsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(p + 16) : "memory");
}

u32 func_001a6a20(u32, u32);
void func_0018fd10(u32* p) {
    p[0] = func_001a6a20(p[0], p[1]);
}

void func_00187018(u32, u32, u32, u32, f32);
void func_0018fd40(u32* p) {
    u32 c = p[2];
    u32 b = p[1];
    u32 a = p[0];
    func_00187018(a, b, c, p[3], *(f32*)&p[4]);
}

void func_001b9db0(u32);
void func_00197c90(void);
void func_001ada38(u32);
void ys_prepare_scene(void) {
    func_001b9db0(2000);
    func_00197c90();
    func_001ada38(11);
}

u32 func_0016bff0(void);
u8 func_00195700(void*, u32);
extern u8 D_0034fa78;
u32 ys_is_mark_history(void) {
    return func_00195700(&D_0034fa78, func_0016bff0());
}

void func_0017c430(u32);
void func_0016bd60(u32, u32);
void func_001b27c0(u32, u32 a) {
    func_0017c430(a);
    func_0016bd60(a, 20);
}

extern u8 D_003511c3;
extern u8 D_003511c2;
u32 func_001b7fd0(void) {
    if (D_003511c3 != 0) return 0;
    return D_003511c2 == 1;
}

void func_002fd248(u32, void*, u32, u32, void*);
extern u32* D_01d48cc4;
extern u8 D_00320408;
void func_001b83f0(u32 a) {  // to_2fd248_block8
    u32* p = D_01d48cc4;
    func_002fd248(a, p + 2, p[1], 8, &D_00320408);
}

void func_001be4e0(u8*, u32);
void func_002ba2e8(u32, u32);
void func_001be4b0(u8* p) {
    func_001be4e0(p, *(u32*)(p + 0xaa4) ? 0 : 6);
    func_002ba2e8(20, 0);
}

extern u32* D_01d49558;
extern u8 D_00320c08;
void func_001c2d48(u32 a) {
    u32* p = D_01d49558;
    func_002fd248(a, p + 2, p[1], 8, &D_00320c08);
}

u32 func_001a8b68(void);
u32 func_0017e668(u32);
u32 ys_can_end(void) {
    return func_0017e668(func_001a8b68()) == 0;
}

// Increment a u16 counter, saturating at 999.
extern u16 D_0032fafe[];
void func_001d9820(s32 i) {
    if (D_0032fafe[i + 9] < 999) D_0032fafe[i + 9]++;
}

u32 func_001b1448(u32);
extern u32 D_003528fc;
extern u32 D_01d5baa8;
void func_001d9d00(void) {
    D_01d5baa8 = func_001b1448(D_003528fc);
}

void func_00168388(u32, void*, void (*)(void), u32);
extern u32 D_00352aec;
extern u8 D_01d5bb40;
void func_001dcd68(void);
void func_001dcd88(void) {
    func_00168388(D_00352aec, &D_01d5bb40, func_001dcd68, 0);
}

struct Pair { u32 a, b; };
void func_001de690(u32);
void func_001dced0(void);
extern Pair D_01d9e348;
void func_001de910(void) {
    func_001de690(0);
    D_01d9e348.a = 0;
    D_01d9e348.b = 0;
    func_001dced0();
}

extern VObj* D_01d9e340;
u32 func_001e0188(u32 a) {
    VObj* o = D_01d9e340;
    return ((u32 (*)(VObj*, u32, u32))o->vt[0])(o, a, 0);
}

u32 func_002fea18(void);
// Seed the VU0 random generator.
void func_0020e138(void) {
    register u32 s asm("$15") = func_002fea18();
    asm volatile("qmtc2 %0, $vf31\n\tvrxor R, $vf31x" : : "r"(s));
}

void func_00228bd8(VObj*);
void func_00228e28(VObj* o) {
    ((void (*)(VObj*))o->vt[7])(o);
    func_00228bd8(o);
}

void func_002344c0(u32, u32, u32, u32, u32);
void func_00234720(u32 a, u32 b, u32 c, u32 d) {
    func_002344c0(a, 0, b, c, d);
}

void func_0023c728(u32*);
void func_0023c598(u32*);
void func_0023c6f8(u32* p) {
    func_0023c728(p);
    p[14] = 1;
    func_0023c598(p);
}

void func_0023fc08(void);
extern u32 D_0035ebe0;
extern u32 D_0035ebec;
void func_0023fb28(void) {
    func_0023fc08();
    D_0035ebe0 = 0;
    D_0035ebec = 0;
}

u32 func_002537c8(u32);
void func_0023fa08(void*, u32);
extern u8 D_0035f3a8;
void func_00256b40(void) {
    func_0023fa08(&D_0035f3a8, func_002537c8(2));
}

struct S408 { u8 d[408]; };
u8 func_00139d78(S408*);
extern S408* D_0035f028;
u32 func_00256b80(s32 i) {
    return func_00139d78(&D_0035f028[i]);
}

// Clear four doublewords of the buffer.
extern volatile u64* volatile D_0035f324;
void func_00288018(void) {  // global_zero_4dwords
    D_0035f324[0] = 0;
    D_0035f324[1] = 0;
    D_0035f324[2] = 0;
    D_0035f324[3] = 0;
}

u32 func_00287bc0(void);
void func_00276c50(u32, u32);
void func_002a65a0(void) {
    func_00276c50(func_00287bc0() == 0x25 ? 18680 : 19200, 0);
}

struct S16d8 { u8 pad[22012]; s32 a; u8 pad2[23292 - 22016]; s32 b; };
extern S16d8* D_0035f634;
u32 func_002b16d8(void) {
    S16d8* p = D_0035f634;
    s32 a = p->a;
    s32 b = p->b;
    u32 r = 0;
    if (a == 126) r = (b == 0x81);
    return r;
}

void func_002e7670(u8*);
void func_002e76b0(u8*);
void func_002e77a8(u8*);
// 002e7768: moved to src/anon/unit_002e7658.cpp

void func_0016c568(u32, u32, f32);
void func_002e7c78(u32* p) {
    u32 o = ((u32*)p[0])[1];
    func_0016c568(o, p[1], *(f32*)&p[2]);
}
void func_002f0948(u32* p) {
    u32 o = ((u32*)p[0])[1];
    func_0016c568(o, p[1], *(f32*)&p[2]);
}

// atoi: (int)strtol(s, 0, 10).
s64 func_002ffbb0(const char*, char**, s32);
s32 func_002fd220(const char* s) {  // strtol10
    return (s32)func_002ffbb0(s, 0, 10);
}

}

u32 ctarget_00186ce8(u32 a0, u32, u32, u32) {
    u32* p = (u32*)(a0 + 320);
    if (p[0] == 0) return 0;
    s32 v = p[5];
    if (v < 10) return 0;
    if (v < 40) return 1;
    return 0;
}

extern Pair D_01c6ced0;
void wtarget_001ad948(u32 a0, u32 a1, u32, u32) {
    if (a1 == 0xffff && a0 == 1) {
        D_01c6ced0.b = 0;
        D_01c6ced0.a = 0;
    }
}

// dst = mat * vec (VU0 COP2 macro sequence, written as asm).
void wtarget_002f3cd8(u32 a0, u32 a1, u32 a2, u32) {
    asm volatile(
        "lqc2 $vf4, 0(%1)\n\t"
        "lqc2 $vf5, 16(%1)\n\t"
        "lqc2 $vf6, 32(%1)\n\t"
        "lqc2 $vf7, 48(%1)\n\t"
        "lqc2 $vf8, 0(%2)\n\t"
        "vmulax.xyzw ACC, $vf4, $vf8x\n\t"
        "vmadday.xyzw ACC, $vf5, $vf8y\n\t"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n\t"
        "vmaddw.xyzw $vf9, $vf7, $vf8w\n\t"
        "sqc2 $vf9, 0(%0)" : : "r"(a0), "r"(a1), "r"(a2) : "memory");
}
