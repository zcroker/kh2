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
void func_002f25a0(u32, u32);
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
void func_002ff3fc(void*);  // strlen
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

void wtarget_0013b4b0(u32, u32, u32, u32) {
    u8* p = D_003484a0;
    if (p && p[680]) {
        func_00139858(2);
        func_00139858(1);
        func_00139ab0(2);
        func_00139ab0(1);
    }
}

// Lazily creates the object at +0x508, otherwise forwards to it.
void wtarget_00185050(u32 a, u32 b, u32, u32) {
    u8* p = (u8*)a;
    u32 o = *(u32*)(p + 0x508);
    if (!o) *(u32*)(p + 0x508) = func_002cd1d8(p, b);
    else func_002cd290(o, p, b);
}

// Clears the first of four slots whose id matches.
void wtarget_001d7a08(u32 a, u32 b, u32, u32) {
    u32* p = (u32*)a;
    s32 i;
    for (i = 3; i >= 0; i--) {
        if (p[1] == b) {
            p[1] = 0;
            func_001d7b10(a, b);
            return;
        }
        p += 2;
    }
}

void trap_camera_at(void** v) {
    func_00107478(func_00106a60(1), D_01c5f480);  // vec_copy_at96_if_diff
    *v = D_01c5f480;
}

void func_00281008_impl(void* p) {
    u32* e = (u32*)((u8*)p + 20);
    s32 i;
    for (i = 3; i >= 0; i--) {
        if (*e) func_001a17c8(*e);
        e += 5;
    }
}

namespace Tz {
void LoadDataFlush();
}
void Tz::LoadDataFlush() {
    u8* t = func_00103eb0();
    u8* r = func_00102818(*(u32*)(t + 4), 0, 0x222e0, (void*)func_00292608, 4096);
    *(void**)(r + 0x30) = (void*)func_00292620;
}

static inline bool in_1_6(s32 a) { return a != 0 && a < 7; }

extern "C" {

void func_00143348(u8* p) {  // state_get_entry
    s16 t[2];
    *(s32*)t = 0;
    *(s16*)(p + 0x118) = func_00147050(D_00348800, 0, p, 0, t);
    *(s16*)(p + 0x11a) = t[0];
}

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

void func_00171ea8(u8* p) {
    u8 tmp[16] __attribute__((aligned(16)));
    func_001ca148(tmp, *(u32*)(*(u8**)p + 4), *(u32*)(*(u8**)(p + 4) + 4), *(f32*)(p + 8));
    u8* d = D_01c5f480;
    if (d != tmp) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(tmp) : "$8", "memory");
    }
    *(u8**)p = d;
}

struct E19f740 {
    u32 a;
    s32 b;
    u8 c;
};

// 1 if one of the 8 entries matches a and b (-1 = any b) and is not flagged.
s32 func_0019f740(E19f740* e, u32 a, s32 b) {
    s32 m = -1;
    E19f740* end = e + 8;
    for (; (s32)e < (s32)end; e++) {
        if (e->a == a && (e->b == m || e->b == b) && !e->c) return 1;
    }
    return 0;
}

struct Q3 {
    u32 a, b, c;
};

void func_001aa7f0(u32* p, u32 a) {
    p[0] = a;
    p[5] = 0x60000000;
    p[1] = 0;
    func_00192f78(p + 8);  // obj_init_float_const
    p[14] = 0;
    p[15] = 0;
    Q3* q = (Q3*)(p + 16);
    q->a = 0;
    q->c = 0;
    q->b = 0;
    p[19] = 0;
    func_001ab750(p[0], q);
}

void func_001aebf0(u8* a) {
    s32* t = D_01c94040[a[0]];
    if (a[1] >= *t) D_01c9408c = 0;
    else D_01c9408c = (u8*)t + a[1] * 24 + 4;
}

struct F28 {
    u8 pad[0x28];
    u32 on : 1;
};

s32 func_001c7950(u8* p, void* o) {  // copy_quad_if_flag
    if (!((F28*)p)->on) return 0;
    f32 v[4] __attribute__((aligned(16)));
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(v), "r"(p) : "$8", "memory");
    v[1] += *(f32*)(*(u8**)(p + 0x4c) + 4);
    return func_001a4ff8(o, v);
}

u8 func_001c9958(s32 a, s32 b) {  // state_pair_check
    if (!in_1_6(a)) return 0;
    switch (a) {
    case 2: return b == 2;
    case 1: return b == 3;
    case 3: return 0;
    }
    return 1;
}

void func_001d4ef0(u8* p, u8* a) {
    u8* v = func_00321728(p + 56, 1, a[0]);
    u32 c = v[1];
    v[1] = c + 1;
    func_001d4f40(p, *(u16*)(a + 0x42), c);
}

void func_001db950(u8* p, u32 a, u32 b, u32 c) {
    func_001c23a8(p, a, b, 0, 0, 96, c);
    *(u32*)(p + 0x9f8) = 0;
    *(u32*)(p + 0x588) |= 0x10000000;
    *(void**)p = D_00352a78;
}

s32 func_0020f188(void) {
    D_00359940[4] = D_01da8bb0[8];
    D_00359940[5] = D_01da8bb0[9];
    func_002f25a0(0, 0);
    return func_002f3918(D_003591c8, D_00359940);
}

u8 func_00225b00(s32 n) {  // flag_query_by_index
    if (n == -1) return D_0035de54;
    u8 r = 0;
    if (D_0035de54 || (n < D_0035de20 && D_0035de20 == D_0035de5c)) r = 1;
    return r;
}

void* func_0022af48(u8* p) {
    u8 tmp[16] __attribute__((aligned(16)));
    void* v = func_0022b688(140);
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(tmp), "r"(p) : "$8", "memory");
    func_001391a8(v, tmp);  // vec_copy_at416_if_diff
    func_002251c8(12103);
    return v;
}

void func_00242088(u8* p) {
    u32* d = *(u32**)(p + 4);
    s32 i;
    for (i = 255; i >= 0; i--) {
        *d++ = func_001064a8(-1);
    }
}

void func_00258ce8(u16* a) {
    if (!a) {
        D_0035f0a8[0] = 0x9fcf;
        D_0035f0a8[1] = 0x9fd0;
        D_0035f0a8[2] = 0x9fd1;
        return;
    }
    u16* d = D_0035f0a8;
    s32 i;
    for (i = 2; i >= 0; i--) {
        *d++ = *a++;
    }
}

// Sets bit n in the bitmap returned by func_002a9d68.
void func_002aa048(u32 n) {
    u32* b = func_002a9d68();
    u32 bit = 1 << (n & 31);
    if (!(b[n >> 5] & bit)) b[n >> 5] |= bit;
}

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
    func_002ff3fc(D_01e2a568);  // strlen
    return D_01e2a568;
}

// Deleting destructor.
void func_002d0028(u8* p) {
    *(void**)p = D_0034ee08;
    func_0019f9a8(p + 2568);  // array8_free_slots
    func_001c0248(p + 2640);
    func_00319fb0(p);  // big_obj_dtor
    func_00105110(p);
}

void* func_002d1270(u32 a, u32 b) {
    return func_002d1550(func_001050d8(336), a, b);
}

void func_002daa98(u8* p, u32 a, u32 b) {
    func_002cfeb0(p, a, 3, b);  // obj_init_field1416_bit800
    *(void**)p = D_00362858;
    func_002cf280(p + 2800, 1, 0);
}

s32 func_002e2240(u8* p) {
    *(void**)p = D_00362eb8;
    void* o = *(void**)(p + 0x6c);
    if (o) {
        func_002e70b0(o);
        func_00106420(o);
    }
    return func_002cea28(p);
}

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
f32 func_003144b0(u64 a) {  // double_trunc
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
