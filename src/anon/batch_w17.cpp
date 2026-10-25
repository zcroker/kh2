#include "../common/types.h"

extern "C" {

extern u32 D_0032b9a4;
void func_00102818(u32, u32, u32, u32, u32);
// 00102f38: moved to src/common/title.cpp

extern u32 D_0032b91c;
extern u8 D_0032ba28;
void func_00102788(u32, u32, u32, void*);
void func_001037f8(void);
void func_001037b8(void) {
    func_00102788(D_0032b91c, 0, 0x50910, (void*)func_001037f8);
    D_0032ba28 = 1;
}

extern u32 D_00346e80;
void func_00113668(void*);
void func_00105110(void*);
void func_00115290(void** p) {
    *p = &D_00346e80;
    func_00113668(p);
    func_00105110(p);
}

extern u32 D_00347c60;
void func_001322f0(void*);  // set_vtbl_347c00
void func_00106420(void*);
void func_00133228(void** p) {
    *p = &D_00347c60;
    func_001322f0(p);  // set_vtbl_347c00
    func_00106420(p);
}

void func_00139598(void*);


void func_0014cf80(void);
void func_001b7f88(void);
void func_002ef7c8(void);
void func_0014d060(void);
u32 func_0014e088(void);
void func_0014e5f0(u32);
void func_0014cf88(void) {
    func_0014cf80();
    func_001b7f88();
    func_002ef7c8();
    func_0014d060();
    func_0014e5f0(func_0014e088());
}

void forceLeaveCounter(void* c) asm("_ZN2dk11INFORMATION17forceLeaveCounterEPNS_7COUNTERE");
u32 func_00139d78(void*);
void func_001506e0(void*);
void forceLeaveCounter(void* c) {
    if (func_00139d78(c)) func_001506e0(c);
}

void func_00152508(void*, u32, u32, u32, u32);


extern char D_001dda78[];
extern u32 D_001ddb30;
u8* func_00102c18(u32, u32, const char*);
void func_001618b8(void) {
    u8* v = func_00102c18(1, 0x16b48, D_001dda78);
    *(void**)(v + 48) = &D_001ddb30;
}

extern u32 D_004f5250;
extern u32 D_004f5258[];
extern s32 D_0034d780;
void func_00167f38(void);
void func_00167fc8(void) {
    D_004f5258[D_0034d780++] = D_004f5250;
    func_00167f38();
}

u32 func_001c0cd8(void*);
u8* func_0016c028(u8* p) {  // obj_get_attach_or_alt
    return func_001c0cd8(p) ? p + 112 : p + 1344;
}

u8* func_00170400(u32, u32, u32);
u8* func_00170530(u32 a, u32 b, s32 c, u32 d) {
    u8* v = func_00170400(a, b, d);
    *v = 1;
    *(s16*)(v + 56) = c;
    *(s16*)(v + 58) = -1;
    return v;
}

typedef void (*VFn4)(void*, u32, u32, void*);
void func_00185a68(u8* p, u32 a, u32 b) {
    void* o = *(void**)(p + 2548);
    (*(VFn4*)((*(u8**)o) + 80))(o, a, b, p);
}

extern void* D_01c608b8;
u32 func_0019ba60(void*);
void* func_0016b0d0(void);
void* ctarget_00185de0(u32, u32, u32, u32) asm("_Z16ctarget_00185de0jjjj");
void* ctarget_00185de0(u32, u32, u32, u32) {
    if (func_0019ba60(D_01c608b8)) return D_01c608b8;
    return func_0016b0d0();
}

u8* func_001b9bc8(void*);
u8* func_00186078(u8* p) {
    do {
        p = func_001b9bc8(p);
    } while (p && !(*(u32*)(p + 1416) & 2));
    return p;
}

extern u32 D_01c60bc8[2];
void func_00188340(void*, u32, void*, u32);
void func_001883f8(u8* p, u32 a) {
    D_01c60bc8[0] = *(u32*)(p + 136);
    D_01c60bc8[1] = a;
    func_00188340(p, 3, D_01c60bc8, 2);
}

extern void* D_0035037c;
void func_00196e00(void*);
// YS::EVENT::Exit: tear down the current event object, if any.
u8 opDelete_u8(void*) asm("func_00105110");
u8 EventExit(void) asm("_ZN2YS5EVENT4ExitEv");
u8 EventExit(void) {
    void* e = D_0035037c;
    if (e) {
        func_00196e00(e);
        return opDelete_u8(e);
    }
}

void func_001a49a0(u8* p, u8* a, u8* b) {
    u8* d = p + 224;
    if (d != a) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(a) : "$8", "memory");
    d = p + 240;
    if (d != b) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(b) : "$8", "memory");
    *(u32*)(p + 4) |= 0x20;
}

extern s32 D_01c6cba0[2];
s32 func_001a8510(void) {  // mod8_of_difference
    return (D_01c6cba0[0] - D_01c6cba0[1] + 8) % 8;
}

extern u32 D_00350c50;
extern u8 D_01c6ced0;
void func_0031fe00(void*, void*);
void func_001ac660(void** p) {
    *p = &D_00350c50;
    func_0031fe00(&D_01c6ced0, p);
    func_00105110(p);
}

void func_001b7958(s32* p, void* v) {  // add_vec_to_records
    for (s32 i = 0; i < *p; i++) {
        u8* q = (u8*)p + 32 + i * 32;
        asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(q), "r"(v) : "memory");
    }
}

void func_001bb890(s32);
void func_001bb468(void);
void func_001991a8(s32, s32);
void MissionExit(s32 a) asm("_ZN2YS7MISSION4ExitEi");
void MissionExit(s32 a) {
    func_001bb890(a);
    func_001bb468();
    func_001991a8(15, a);
}

u32 func_001bb4a0(void);
u8* func_001bbcb0(void);
u32 func_001bbf40(void) {
    u32 r = 0;
    if (func_001bb4a0()) {
        u8* v = func_001bbcb0();
        u32 x = *(u16*)(*(u8**)(v + 8) + 4);
        r = (x >> 1) & 1;
    }
    return r;
}

u32 func_001d01e0(void);
void func_00170320(u32);
void func_0016ed50(u32, u32, u32);


extern u8* D_01d5ba0c;
u8 func_002fd248_u8(u32, void*, u32, u32, void*) asm("func_002fd248");
extern u32 D_003216a8;
// 001d30c0: moved to src/anon/unit_001d30b0.cpp

extern u8* D_01d5ba98;


extern u32 D_0032dfd0[][2];


extern u32 D_01d9e6b4;
extern u8 D_01d9e6b0;
void func_001e65d0(void);
void func_001e6630(void);
void func_0021c9b0(void);
void func_001e6648(void) {
    func_001e65d0();
    func_001e6630();
    func_0021c9b0();
    D_01d9e6b4 = 0;
    D_01d9e6b0 = 0;
}

extern u32 D_0035dae4;
void func_00225fa0(u32, u32);
void func_00227930(void*);
void func_00225690(u8* p) {
    func_00225fa0(D_0035dae4, *(u32*)(p + 24));
    func_00227930(p);
}

// Store the vector (x, y, z, 0) into slot p[2916 + i] of the 320-byte table at p + 1664.
void func_0023e918(u8* p, s32 i, f32 x, f32 y, f32 z) {
    u8* d = p + *(u8*)(i + (u32)p + 2916) * 320 + 1664;
    struct { f32 f[3]; u32 w; } __attribute__((aligned(16))) v;
    v.f[0] = x; v.f[1] = y; v.f[2] = z; v.w = 0;
    if (d != (u8*)&v) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(&v) : "$8", "memory");
}

void func_0023f628(u8* p, u32 a) {
    func_00139d78(p);
    *(u32*)(p + 64) = a;
}

void func_00242088(void*);
void func_002ef938(u32);
void func_002421c0(u8* p) {
    u32 s = *(u32*)(p + 4);
    func_00242088(p);
    func_002ef938(s);
}

u8* func_001058e8(void);
struct Pair16 { s16 a, b; };
void func_002429c0(s32 a, s32 b) {
    Pair16* s = (Pair16*)(func_001058e8() + 16800);
    s->a = a;
    s->b = b;
}

u8* func_00246868(s32);
u8 func_001a6d08(s32);
u8 Cur2SelPos(s32 i) asm("_ZN2Tz4HECO10Cur2SelPosEi");
u8 Cur2SelPos(s32 i) {
    u8* v = func_00246868(i);
    return func_001a6d08(*(s8*)(v + i * 36 + 28));
}

extern u32 D_0035f034;
extern u32 D_0035f024;
u32 func_0028acc8(u32);
u32 IsWarningEnabled(...) asm("_ZN2Tz5CmTop16IsWarningEnabledEz");
u32 IsWarningEnabled(...) {
    u32 r = func_00139d78((void*)D_0035f034);
    if (r == 0) r = func_0028acc8(D_0035f024);
    return r;
}



typedef void (*VFn2)(void*, void*);
extern void* D_0035f570;
void func_00293f78(void* a) {
    if (a) {
        void* o = D_0035f570;
        (*(VFn2*)((*(u8**)o) + 4))(o, a);
    }
}

u8* func_002766d0(void);
u8 func_00139d78_u8(void*) asm("func_00139d78");
u8 func_0029e2f8(s32 i) {
    i++;
    return func_00139d78_u8(func_002766d0() + i * 408 + 17304);
}

u32 func_00287bc0(void);
void func_00276c50(u32, u32);
void func_002a03a0(void) {
    func_00276c50(func_00287bc0() == 24 ? 18668 : 18669, 0);
}

void func_002c6380(void);
void func_002c6190(void*);
void func_002c6158(u32* p) {
    p[0] = 1;
    p[1] = 26000;
    p[2] = (u32)func_002c6380;
    p[3] = 0;
    func_002c6190(p);
}

extern u32 D_00362428;
void func_002cfeb0(void*, u32, u32, u32);  // obj_init_field1416_bit800
void func_002e7308(void*);
void func_002d5d10(u8* p, u32 a, u32 b) {
    func_002cfeb0(p, a, 1, b);  // obj_init_field1416_bit800
    *(void**)p = &D_00362428;
    func_002e7308(p + 2872);
}

void func_0017c430(void*);
void func_0016bd60(void*, u32);
void func_002eb4b0(u8* p) {
    func_0017c430(p);
    *(u32*)(p + 256) = 256;
    *(u32*)(p + 260) = 257;
    func_0016bd60(p, 49);
}

u32 func_0010c7e8(u32);
void func_00117808(u32, u32);
void trap_empty_func(u32** p) asm("_ZN2kn15trap_empty_funcEP8BD_VALUE");
void trap_empty_func(u32** p) {
    func_00117808(func_0010c7e8(p[0][1]), (u32)p[1]);
}

extern u32 D_003677e8;
void func_00315768(void*);
void func_00315840(void** p) {
    *p = &D_003677e8;
    func_00315768(p);
    func_00106420(p);
}

extern u32 D_003678f8[];
void func_003167f8(void*);  // set_vtbl_367910
u8 func_00106420_u8(void*) asm("func_00106420");
u8 func_00316890(void** p) {
    *p = D_003678f8;
    func_003167f8(p);  // set_vtbl_367910
    return func_00106420_u8(p);
}

extern u32 D_00352560;
void func_001d1ed0(void*);
void func_00321648(void** p) {
    *p = &D_00352560;
    func_001d1ed0(p);
    func_00106420(p);
}

}
