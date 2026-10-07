#include "../common/types.h"

typedef void (*VFn)(void*);

extern "C" {
u32 func_00112740(void*);
void func_00112730(void*, u32);
void* func_00124748(void*, s32);
void* func_0016e920(void*, void*);
void func_0016f6a0(void*, void*);
void func_0016adc8(void*, void*);
void func_001ad990(void*, f32, f32, f32);
void func_001b1bb8(void*, u32, u32, u32, s32, f32);
void* func_00180698(void);
void func_0016cc18(void*, void*, void*, void*, s32);
void func_001a1840(void*);
void func_001a11e0(void*, s32);
void func_00187650(void*, void*);
void func_001a1990(void*, void*, u8);
void* func_0016bff0(void*);
void func_001956d0(void*, void*);
void func_001b7f88(void);
void func_001bdc18(void*);
void func_001bd5b0(void*, u32, s32);
void func_0016a9a0(void*);
void func_001c1428(void*);
void func_001dba98(void*);
void func_0016b5b8(void*);
u8* func_001ba158(void);
void func_001ada38(s32);
void func_001dc9e0(void*);
void func_001e6cf8(void*);
s32 func_001e2c78(void*);
void* func_0022c4b8(void);
void func_00170518(void*, s32, s32);
void func_00234400(void*, s32, void*, void*, void*, void*);
void func_0023fbc8(void);
void func_00288648(void);
s16* func_00253330(s32);
void func_00103500(s32);
void func_001037b8(void);
void* func_0014aba8(void);
void func_0014aa58(void*, s32, s32);
void func_00287cc0(s32);
void func_0026b470(void);
void func_0026b508(void);
void func_0026b5a0(s32);
void* func_002537c8(s32);
void* func_0023fa08(void*, void*);
s32 func_00287bc0(void);
void func_00276c50(s32, s32);
u8* func_001d56c8(void);
void func_002b8824(void*, void*, s32, void*, void*);
void* func_001050d8(s32);
void func_002e20d8(void*, void*);
void func_002e9610(void*, void*);
s32 func_002ef7b8(void);
void func_001b8228(void);
void func_001b8258(void);
void func_0017c430(void*);
void func_0016bd60(void*, s32);
void func_00106420(void*);

extern s32 D_00349df4;
extern u8 D_00349e00;
extern s32 D_00349df8;
extern s32 D_00349dfc;
extern struct { u8 a, b, c, d; } D_004f3700;
extern u8 D_0034fa78;
extern struct { u32 a, b; } D_01d48c80;
extern s32 D_003511b8;
extern u8 D_003511c1;
extern u16 D_0032f218;
extern void** D_01d9e340;
extern struct { u32 a, b, c; } D_0035db00;
extern s32 D_0035ebe0;
extern s32 D_0035ebec;
extern u8 D_0035f3a8;
extern s32 D_003617f0;
extern void* D_003617ec;
extern u32 D_0033cae8[];
extern u8 D_00348d58;
extern u8 D_00348698;

void Peterpan_acceptNotifyPlayerTarget(void*) asm("_ZN2kn8Peterpan24acceptNotifyPlayerTargetEv");
void Timer_setCountDown(u32) asm("_ZN2dk5Timer12setCountDownEj");
void trap_obj_leave_force(void*) asm("_ZN2YS20trap_obj_leave_forceEP8BD_VALUE");
void SHEET_reload(void*) asm("_ZN2YS5SHEET6reloadEv");
void FIELDOBJ_mark_history(void*) asm("_ZN2YS8FIELDOBJ12mark_historyEv");
void wtarget_001b26e0(u32, u32, u32, u32) asm("_Z16wtarget_001b26e0jjjj");
void MASSOBJ_OVR_exec(void*) asm("_ZN2YS7MASSOBJ9_OVR_execEv");
void EFFECT_color(void*) asm("_ZN3ryj6EFFECT5colorEv");
bool EFFECT_is_loop(void*) asm("_ZN3ryj6EFFECT7is_loopEv");
void wtarget_00228420(u32, u32, u32, u32) asm("_Z16wtarget_00228420jjjj");
void CampMenu_StartBasic(s32) asm("_ZN2Tz8CampMenu10StartBasicEi");
void* CMData_GetPtr(s32) asm("_ZN2Tz6CMData6GetPtrEi");

void Peterpan_acceptNotifyPlayerTarget(void* s) {
    func_00112730(*(void**)((u8*)s + 4), func_00112740(*(void**)((u8*)s + 4)) | 0x200);
}

void* func_00123dd0(void* a) {
    void* o = func_00124748(a, 0);
    return (*(void* (**)(void*))(*(u8**)o + 28))(o);
}

void func_00135ff0(u8* p) {
    s32 i;
    *(u32*)(p + 12) = 0;
    for (i = 31; i >= 0; i--) {
        *(u32*)(p + 16) = 0;
        *(u32*)(p + 20) = 0;
        p += 8;
    }
}

void Timer_setCountDown(u32 n) {
    n *= 60;
    D_00349dfc = 0;
    D_00349df8 = n;
    D_00349e00 = 1;
    D_00349df4 = n;
}

void func_0015cbb8(u8 a, u8 b, u8 c, u8 d) {
    D_004f3700.a = a;
    D_004f3700.b = b;
    D_004f3700.c = c;
    D_004f3700.d = d;
}

void func_0016eb18(void* a, void* b) {
    func_0016f6a0(func_0016e920(a, b), b);
}

void func_00171480(u8* p) {
    u32 tmp[4] __attribute__((aligned(16)));
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(tmp), "r"(*(void**)(p + 4)) : "$8", "memory");
    func_0016adc8(*(void**)(*(u8**)p + 4), tmp);
}

void trap_obj_leave_force(void* v) {
    void* o = *(void**)(*(u8**)v + 4);
    (*(VFn*)(*(u8**)o + 32))(o);
}

void func_00174728(u8* p) {
    u8* o = *(u8**)p;
    f32 x = *(f32*)(p + 4), y = *(f32*)(p + 8), z = *(f32*)(p + 12);
    func_001ad990(*(u8**)(o + 4) + 2248, x, y, z);
}

void func_00174af8(u8* p) {
    void* o = *(void**)p;
    func_001b1bb8(o, *(u32*)(p + 4), *(u32*)(p + 8), *(u32*)(p + 12), 128, *(f32*)(p + 16));
}

void func_00180770(void) {
    void* o = func_00180698();
    (*(VFn*)(*(u8**)o + 28))(o);
}

void func_0018ef68(u8* p, void* a, void* b) {
    func_0016cc18(*(void**)p, *(void**)(p + 4), a, b, 0);
}

void func_0018f218(u8* p) {
    void* o = *(void**)(*(u8**)p + 4);
    (*(void (**)(void*, void*))(*(u8**)o + 104))(o, *(void**)(p + 4));
}

void SHEET_reload(void* s) {
    func_001a1840(s);
    func_001a11e0(s, 0);
}

void func_001a1a20(u8* p, void* a, u8 b) {
    void* o = *(void**)(p + 604);
    if (o) {
        func_00187650(o, a);
    } else {
        func_001a1990(p, a, b);
    }
}

void FIELDOBJ_mark_history(void* o) {
    func_001956d0(&D_0034fa78, func_0016bff0(o));
}

void wtarget_001b26e0(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        D_01d48c80.b = 0;
        D_01d48c80.a = 0;
    }
}

s32 func_001b81e8(void) {
    func_001b7f88();
    D_003511c1 = 1;
    return D_003511b8;
}

s32 func_001bdd20(u8* p) {
    return (*(u32*)(p + 32) & 0x10) || D_0032f218 == 0;
}

void func_001befa8(u8* p) {
    func_001bdc18(p);
    func_001bd5b0(p, *(u32*)(p + 2724), 0);
}

void MASSOBJ_OVR_exec(void* o) {
    func_0016a9a0(o);
    func_001c1428(*(void**)((u8*)o + 2548));
}

void func_001ce458(u8* p) {
    func_001dba98(*(void**)(p + 2548));
    func_0016b5b8(p);
}

void func_001d7940(void) {
    u8* v = func_001ba158();
    *(u32*)(v + 4) = 0;
    *(u32*)(v + 12) = 0;
    *(u32*)(v + 20) = 0;
    *(u32*)(v + 24) = 0;
    func_001ada38(12);
}

void EFFECT_color(void* e) {
    func_001dc9e0(e);
    func_001e6cf8(*(void**)((u8*)e + 28));
}

bool EFFECT_is_loop(void* e) {
    func_001dc9e0(e);
    return func_001e2c78(*(void**)((u8*)e + 28)) != 0;
}

void* func_001e0128(void* a) {
    void** o = D_01d9e340;
    return (*(void* (**)(void*, void*, s32))*o)(o, a, 0);
}

// Normalize the 2D vector at s (xy) into d.
void func_00222868(void* d, void* s) {
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

void wtarget_00228420(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        D_0035db00.a = 0;
        D_0035db00.b = 0;
        D_0035db00.c = 0;
    }
}

void func_0022c508(void) {
    func_00170518(func_0022c4b8(), -200, 0);
}

void func_002346c0(void* a, void* b, void* c, void* d, void* e) {
    func_00234400(a, 0, b, c, d, e);
}

void func_0023fb00(s32 a) {
    D_0035ebe0 = a;
    func_0023fbc8();
    D_0035ebec = 0;
}

void CampMenu_StartBasic(s32) {
    func_00288648();
    func_00103500(func_00253330(10)[1]);
    func_001037b8();
}

void func_0025ccc0(void) {
    func_0014aa58(func_0014aba8(), 15, 0);
    func_00287cc0(0);
}

void func_0026b448(void) {
    func_0026b470();
    func_0026b508();
    func_0026b5a0(-1);
}

void* CMData_GetPtr(s32) {
    return func_0023fa08(&D_0035f3a8, func_002537c8(5));
}

void func_0028b218(u8* p, u8 on) {
    p[39] = on;
    if (on) {
        *(u32*)(p + 52) |= 0x3000;
    } else {
        *(u32*)(p + 52) &= ~0x3000;
    }
}

void func_00299260(void) {
    func_00276c50(func_00287bc0() == 4 ? 18648 : 18649, 0);
}

bool func_002a8920(void) {
    return *func_001d56c8() >= 2;
}

void func_002bd730(s32 a, void* b, void* c, void* d) {
    D_003617f0 = a;
    func_002b8824(D_003617ec, b, 64, c, d);
}

void func_002e1f40(void* a) {
    func_002e20d8(func_001050d8(320), a);
}

void func_002e8c28(u8* p) {
    u32 tmp[4] __attribute__((aligned(16)));
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(tmp), "r"(*(void**)(p + 4)) : "$8", "memory");
    func_002e9610(*(void**)p, tmp);
}

void func_002ef7c8(void) {
    if (func_002ef7b8()) {
        func_001b8228();
    } else {
        func_001b8258();
    }
}

void func_002f05d8(void* p) {
    func_0017c430(p);
    func_0016bd60(p, 63);
}

bool func_002f1ae0(u32 n) {
    return (D_0033cae8[n >> 5] & (1 << (n & 31))) != 0;
}

// Store a 4x4 identity matrix at m (rows written last-to-first).
void func_002f4000(void* m) {
    asm volatile(
        "vsub.xyzw $vf4, $vf0, $vf0\n\t"
        "vadd.w $vf4, $vf4, $vf0\n\t"
        "vmr32.xyzw $vf5, $vf4\n\t"
        "vmr32.xyzw $vf6, $vf5\n\t"
        "vmr32.xyzw $vf7, $vf6\n\t"
        "sqc2 $vf4, 48(%0)\n\t"
        "sqc2 $vf5, 32(%0)\n\t"
        "sqc2 $vf6, 16(%0)\n\t"
        "sqc2 $vf7, 0(%0)"
        : : "r"(m) : "memory");
}

// 64-byte (4 quadword) copy.
void func_0031bae0(void* d, void* s) {
    asm volatile(
        ".set noreorder\n\t"
        "lq $8, 0(%1)\n\t"
        "lq $9, 16(%1)\n\t"
        "lq $10, 32(%1)\n\t"
        "lq $11, 48(%1)\n\t"
        "sq $8, 0(%0)\n\t"
        "sq $9, 16(%0)\n\t"
        "sq $10, 32(%0)\n\t"
        "sq $11, 48(%0)\n\t"
        ".set reorder"
        : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory");
}

void func_0031e0b8(u8* p) {
    *(void**)(p + 80) = &D_00348698;
    *(void**)p = &D_00348d58;
    func_00106420(p);
}

}
