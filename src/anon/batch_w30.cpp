#include "../common/types.h"

extern "C" {
void func_00139858(s32);
void func_00139ab0(s32);
extern u8* D_003484a0;
s16 func_00147050(u32, u32, void*, u32, void*);  // entry48_process_5args
extern u32 D_00348800;
void func_001398d0(s32);
void func_00139a38(s32);
void func_001ca148(void*, u32, u32, f32);
extern u8 D_01c5f480[16];
u32 func_00106a60(s32);  // buffer_get_by_index
void func_00107478(u32, void*);  // vec_copy_at96_if_diff
u32 func_002cd1d8(void*, u32);
void func_002cd290(u32, void*, u32);
void func_00192f78(void*);  // obj_init_float_const
void func_001ab750(u32, void*);
extern s32* D_01c94040[];
extern void* D_01c9408c;
s32 func_001a4ff8(void*, void*);
u8* func_00321728(void*, s32, u32);
void func_001d4f40(void*, u32, u32);
void func_001d7b10(u32, u32);
void func_001c23a8(void*, u32, u32, u32, u32, u32, u32);
extern u8 D_00352a78[];
extern u64 D_01da8bb0[];
extern u64 D_00359940[];
extern u32 D_003591c8;
void sceGsSyncPath(u32, u32);
u8 func_002f3918(u32, void*);
extern u8 D_0035de54;
extern s32 D_0035de20;
extern s32 D_0035de5c;
void* func_0022b688(u32);
void func_001391a8(void*, void*);  // vec_copy_at416_if_diff
void func_002251c8(u32);
u32 func_001064a8(s32);  // int_to_float_scaled
extern u16 D_0035f0a8[3];
void func_001a17c8(u32);
u8* func_00103eb0(void);
u8* func_00102818(u32, u32, u32, void*, u32);
void func_00292608(void*) asm("_ZN2Tz8LoadData9FlushTaskEP4TASK");
void func_00292620(void);
u32* func_002a9d68(void);
void func_002b7fbc(u32);
void func_002bce40(void*);
void func_002bce50(void*);
void func_002b9b78(void);
void func_002ba390(void);
void func_002b9ed0(void);
extern u8 D_01e2a410[];
void func_002baa78(void);
void func_002bcfe8(void*);
void func_002bd030(void*);
void func_002bd078(void*);
void func_002bd0b8(void*);
void func_002bd100(void*);
void func_002bd140(void*);
extern u8 D_01e2a568[];
extern u8 D_00374f70[];
void func_002fee78(void*, void*, u32);
void strlen(void*);  // strlen
extern u8 D_0034ee08[];
void func_0019f9a8(void*);  // array8_free_slots
void func_001c0248(void*);
u8 func_00319fb0(void*);  // big_obj_dtor
void func_00105110(void*);
void* func_001050d8(u32);
void* func_002d1550(void*, u32, u32);
void func_002cfeb0(void*, u32, u32, u32);  // obj_init_field1416_bit800
extern u8 D_00362858[];
void func_002cf280(void*, u32, u32);
extern u8 D_00362eb8[];
void func_002e70b0(void*);
void func_00106420(void*);
u8 func_002cea28(void*);
void func_00195858(void*, u32);
extern void* D_00347f98[];
extern void** D_00347f80;
extern u8 D_0035eb98[];
void func_0023c098(void*);  // set_vtbl_36eae8_then_call
void func_002369f0(void*);  // set_vtbl_36eac8_then_call
void func_0023ee68(void*);
}

extern "C" {
void wtarget_0013b4b0(u32, u32, u32, u32) asm("_Z16wtarget_0013b4b0jjjj");
void wtarget_00185050(u32, u32, u32, u32) asm("_Z16wtarget_00185050jjjj");
void wtarget_001d7a08(u32, u32, u32, u32) asm("_Z16wtarget_001d7a08jjjj");
// YS::trap_camera_at(BD_VALUE*)
void trap_camera_at(void**) asm("_ZN2YS14trap_camera_atEP8BD_VALUE");
void func_00281008_impl(void*) asm("_Z13func_00281008Pv");
}

void wtarget_0013b4b0(u32, u32, u32, u32);  // 0x0013b4b0: definition moved into src/anon/unit_0013a8b8.cpp

// 00185050: moved to src/anon/unit_00183088.cpp

// Clears the first of four slots whose id matches.
void wtarget_001d7a08(u32 a, u32 b, u32, u32);  // 0x001d7a08: definition moved into src/anon/unit_001d7458.cpp

void trap_camera_at(void** v);  // 0x00174d98: definition moved into src/anon/unit_00171e58.cpp

void func_00281008_impl(void* p);  // 0x00281008: definition moved into src/anon/unit_0027f2b0.cpp

namespace Tz {
void LoadDataFlush();
}
// 002925c0: moved to src/anon/unit_00290f78.cpp

static inline bool in_1_6(s32 a) { return a != 0 && a < 7; }

extern "C" {

void func_00143348(u8* p);  // 0x00143348: definition moved into src/anon/unit_00142c90.cpp

// GS SCISSOR register value from x/y/w/h.
void func_0014b950(u8* p, s16 x, s16 y, u16 w, u16 h) {
    *(u64*)(p + 16) = (u64)x | ((u64)(x + w - 1) << 16) | ((u64)y << 32) | ((u64)(y + h - 1) << 48);
}

void func_0014f528(void) {
    func_001398d0(7);
    func_001398d0(9);
    func_001398d0(8);
    func_001398d0(10);
    func_00139a38(7);
    func_00139a38(9);
    func_00139a38(8);
    func_00139a38(10);
}

// dot(a.xyz, b.xyz) + b.w -> *out; returns 1 when it is <= a[4].
s32 func_00162b68(f32* a, f32* b, f32* out) {
    f32 d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
        : "=f"(d) : "r"(a), "r"(b) : "$8", "memory");
    d += b[3];
    *out = d;
    return a[4] < d ? 0 : 1;
}

void func_00171ea8(u8* p);  // 0x00171ea8: definition moved into src/anon/unit_00171e58.cpp

struct E19f740 {
    u32 a;
    s32 b;
    u8 c;
};

// 1 if one of the 8 entries matches a and b (-1 = any b) and is not flagged.
s32 func_0019f740(E19f740* e, u32 a, s32 b);  // 0x0019f740: definition moved into src/anon/unit_0019ee80.cpp

struct Q3 {
    u32 a, b, c;
};

void func_001aa7f0(u32* p, u32 a);  // 0x001aa7f0: definition moved into src/anon/unit_001a9130.cpp

void func_001aebf0(u8* a);  // 0x001aebf0: definition moved into src/anon/unit_001ada38.cpp

struct F28 {
    u8 pad[0x28];
    u32 on : 1;
};

// 001c7950: moved to src/anon/unit_001c7148.cpp (linked unit)

u8 func_001c9958(s32 a, s32 b);  // 0x001c9958: definition moved into src/yasui/libys/sacrifice.cpp

void func_001d4ef0(u8* p, u8* a);  // 0x001d4ef0: definition moved into src/anon/unit_001d3c08.cpp

void func_001db950(u8* p, u32 a, u32 b, u32 c) {
    func_001c23a8(p, a, b, 0, 0, 96, c);
    *(u32*)(p + 0x9f8) = 0;
    *(u32*)(p + 0x588) |= 0x10000000;
    *(void**)p = D_00352a78;
}

s32 func_0020f188(void) {
    D_00359940[4] = D_01da8bb0[8];
    D_00359940[5] = D_01da8bb0[9];
    sceGsSyncPath(0, 0);
    return func_002f3918(D_003591c8, D_00359940);
}

u8 func_00225b00(s32 n) {  // flag_query_by_index
    if (n == -1) return D_0035de54;
    u8 r = 0;
    if (D_0035de54 || (n < D_0035de20 && D_0035de20 == D_0035de5c)) r = 1;
    return r;
}

void* func_0022af48(u8* p);  // 0022af48: moved to src/sasa/musical_input.cpp (linked unit)

void func_00242088(u8* p) {
    u32* d = *(u32**)(p + 4);
    s32 i;
    for (i = 255; i >= 0; i--) {
        *d++ = func_001064a8(-1);
    }
}

void func_00258ce8(u16* a);  // 0x00258ce8: definition moved into src/anon/unit_002588e8.cpp

// Sets bit n in the bitmap returned by func_002a9d68.
void func_002aa048(u32 n);  // 0x002aa048: definition moved into src/anon/unit_002a99c8.cpp

void func_002b9e80(void) {
    func_002b7fbc(0);
    func_002bce40(D_01e2a410);
    func_002bce50(D_01e2a410);
    func_002b9b78();
    func_002ba390();
    func_002b9ed0();
}

void func_002b9ed0(void) {
    func_002baa78();
    func_002bcfe8(D_01e2a410);
    func_002bd030(D_01e2a410);
    func_002bd078(D_01e2a410);
    func_002bd0b8(D_01e2a410);
    func_002bd100(D_01e2a410);
    func_002bd140(D_01e2a410);
}

void* func_002ba0b0(u32 a) {
    func_002fee78(D_01e2a568, D_00374f70, a);
    strlen(D_01e2a568);  // strlen
    return D_01e2a568;
}

// Deleting destructor.
void func_002d0028(u8* p);  // 0x002d0028: definition moved into src/anon/unit_002cf260.cpp

void* func_002d1270(u32 a, u32 b);  // 0x002d1270: definition moved into src/anon/unit_002cf260.cpp

void func_002daa98(u8* p, u32 a, u32 b) {
    func_002cfeb0(p, a, 3, b);  // obj_init_field1416_bit800
    *(void**)p = D_00362858;
    func_002cf280(p + 2800, 1, 0);
}

// 002e2240: moved to src/anon/unit_002e1908.cpp

void func_002ecdf8(u8* p, u8* a) {
    func_00195858(a + 272, 60);
    (*(void (**)(void*, void*))(*(u8**)p + 36))(p, a);
}

struct FpNum {
    s32 cls;
    u32 sign;
    s32 exp;
    u64 frac;
};
void func_003147a0(void*, FpNum*);
f32 func_00314698(s32, u32, s32, u32);

// Software double -> float (libgcc fp-bit __truncdfsf2).
f32 __truncdfsf2(u64 a) {  // double_trunc
    FpNum in;
    u64 au = a;
    func_003147a0(&au, &in);
    u32 f = in.frac >> 30;
    if (in.frac & 0x3fffffff) f |= 1;
    return func_00314698(in.cls, in.sign, in.exp, f);
}

void func_0031ae18(void** p) {
    *p = D_00347f98;
    void** o = (void**)D_00347f80[5];
    (*(void (**)(void*, void*))((u8*)*o + 4))(o, p);
}

s32 func_0031eb68(u8* p) {
    *(void**)p = D_0034ee08;
    func_0019f9a8(p + 2568);  // array8_free_slots
    func_001c0248(p + 2640);
    return func_00319fb0(p);  // big_obj_dtor
}

void func_00320bc0(u8* p) {
    *(void**)p = D_0034ee08;
    func_0019f9a8(p + 2568);  // array8_free_slots
    func_001c0248(p + 2640);
    func_00319fb0(p);  // big_obj_dtor
    func_00105110(p);
}

void func_00322db8(u8* p) {
    *(void**)p = D_0035eb98;
    func_0023c098(p + 48);  // set_vtbl_36eae8_then_call
    func_002369f0(p + 24);  // set_vtbl_36eac8_then_call
    *(void**)p = D_00347f98;
    func_0023ee68(p);
}

}
