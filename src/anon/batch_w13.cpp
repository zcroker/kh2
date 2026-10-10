#include "../common/types.h"

struct Q128 { u32 w[4]; };

extern "C" {
void func_00113668(void*);
void func_00105110(void*);
void func_0011ee58(void*);  // set_vtbl_347940
void func_00106420(void*);
void* func_00124748(void*, s32);  // list_nth_node_rel
void func_002ba848(s32);
void func_00136a18(void);
void func_0013f030(void);
void* func_00102c80(void);
void func_00102818(u32, s32, u32, void*, s32);
void func_0013f450(void);
void func_001666a0(void*);  // zero_fields_0_4_6_8
void func_00138c10(void*, s32);
void func_0014e098(s32);
void func_001024a8(void*);
u8 func_00176db0(void*, u32);
u8 func_0016b558(void*, u32);
u32 func_001a7588(u32, u32, u32, u32);
void* func_00168b38(void*, s32, s32);  // entry_array_find_nth
void func_00188340(void*, s32, void*, s32);
void func_0019cc20(void*);
u8* func_0019f7d0(void);
void func_001d59b0(void);
void func_003201e8(void*, void*);
s32 func_001bb4a0(void);
void func_0016a9a0(void*);  // to_16a950
void func_001c14e0(void*);
void func_001c8d98(void*, s32);
void func_0014c9f0(s32);
void func_001bbe78(s32);
void func_0016c640(s32);
void func_0017c4c8(void*, void*);
void func_0016bd60(void*, s32);
void func_001a4e30(void*);
void func_001d2210(void*);
void func_001dc878(void*);
void func_001e17b8(void*);
s32 func_002282f0(s32);
void func_00102c18(s32, s32, void*);
void func_0022dc30(void);
void func_00237238(void*);
s32 func_00139d78(void*);
void func_00139510(void*);
void func_00283960(s32);
void func_00287c78(s32);
void func_0028b8a0(void*);
u8 func_0023f820(void*);
u32 func_002b823c(void);
Q128* func_002cb890(void*, void*);  // hash_bucket_get
void func_002cd878(void*, u32, s32, f32);
void func_002cff98(void*);
f32 func_001906f0(void*, void*);
void func_00239870(void*);
u8 func_0031a840(void*);
void func_001b0188(void*);
void func_002dea80(void*);  // set_vtbl_362d20

extern u8 D_003467b8;
extern u8 D_00347a28;
extern u8 D_00347d54;
extern u8 D_00347d55;
extern u8 D_00347d56;
extern u8* D_004f41c0;
extern u32 D_01c60bd0[3];
extern void* D_00350444;
extern u32 D_0032dec0[];
extern u8 D_01d48c80;
extern u8* D_01d49320;
extern u8 D_00351ec0;
extern u8 D_00351f78;
extern void* D_00351f68;
extern u8 D_003525e8;
extern u8* D_00352ae0;
extern u8* D_01d9e340;
extern u32* D_0035dcf8;
extern s32 D_0035e370;
extern void (*D_0035e380[])(void);
extern u8 D_0035eaf8;
extern u8* D_0035f2b8;
extern s32 D_0035f2f0;
extern s32 D_0035f2f4;
extern s32 D_0035f2f8;
extern s32 D_0035f2fc;
extern u8 D_0035f3a0;
extern u32 D_003617e0;
extern u32 D_003617e4;
extern u8 D_003617e8;
extern u8 D_00362ad8;
extern u8* D_01e2c0d0;
extern u8 D_00347e60;
extern u8 D_00350e60;
extern u8 D_00362c18;

void Camera_onceCover(void*) asm("_ZN2dk6Camera9onceCoverEP4TASK");
void trap_bg_cross_pos(u32*) asm("_ZN2YS17trap_bg_cross_posEP8BD_VALUE");
void MANAGER_exec_zsort(u8*) asm("_ZN2YS10MASSEFFECT7MANAGER10exec_zsortEv");
void SEQUENCE_D0(void*) asm("_ZN2YI8SEQUENCED0Ev");
void* func_002cd910_f(void*, u32, f32) asm("_Z13func_002cd910f");

void func_00114cc8(void** p) {
    *p = &D_003467b8;
    func_00113668(p);
    func_00105110(p);
}

void func_001207c8(void** p) {
    *p = &D_00347a28;
    func_0011ee58(p);  // set_vtbl_347940
    func_00106420(p);
}

typedef s32 (*VFn2)(void*, s32);
s32 func_00123d90(void* a, s32 b) {
    void* o = func_00124748(a, 0);  // list_nth_node_rel
    return (*(VFn2*)(*(u8**)o + 24))(o, b);
}

void func_001373a0(void) {
    D_00347d55 = 0;
    D_00347d56 = D_00347d54;
    D_00347d54 = 0;
    func_002ba848(960);
    func_00136a18();
}

void func_0013f4d8(void) {
    func_0013f030();
    u8* v = (u8*)func_00102c80();
    func_00102818(*(u32*)(v + 4), 1, 0x493e0, (void*)func_0013f450, 4096);
}

void func_0014dbc8(u8* p) {
    func_001666a0(p);  // zero_fields_0_4_6_8
    *(u32*)(p + 464) = 0;
    *(u16*)(p + 468) = 0;
    p[470] = 0;
    p[471] = 0;
    p[472] = 0;
    p[473] = 0;
}

void func_001514b0(u8* p) {
    func_00138c10(p + 496, 0);
    func_00138c10(p + 904, 6);
}


void Camera_onceCover(void* task) {
    func_0014e098(216);
    func_001024a8(task);
}

u8* func_00165ef0(u8* p) {
    do {
        p = p ? *(u8**)(p + 12) : D_004f41c0;
    } while (p && (*(u32*)(p + 8) & 2));
    return p;
}

u8 func_0016b518(u8* p, u32 a1, u32 a2) {
    if (*(u32*)(p + 1416) & 4) {
        return func_00176db0(p, a1);
    }
    return func_0016b558(p, a2);
}

void trap_bg_cross_pos(u32* v) {
    u32 c = v[2];
    u32 b = v[1];
    v[0] = func_001a7588(v[0], b, c, v[3]);
}

s32 func_00179c80(u8* p) {
    s32 r = 0;
    if (*(s32*)(p + 2896) == 7) {
        s32 x = *(s32*)(p + 340);
        if (x == 203) goto yes;
        if (x == 204) goto yes;
        goto no;
    yes:
        r = 1;
    }
no:
    return r;
}

u32 func_00180408(void* a0, void* a1) {
    u8* v;
    if (a1 && (v = (u8*)func_00168b38(a1, 9, 0)) != 0) return *(u32*)(v + 8);  // entry_array_find_nth
    return 0;
}

void func_00188430(u8* p, u32 a1, u32 a2) {
    u32* t = D_01c60bd0;
    t[0] = *(u32*)(p + 136);
    t[1] = a1;
    t[2] = a2;
    func_00188340(p, 7, t, 3);
}

void func_0019c970(void* p) {
    func_0019cc20(p);
    D_00350444 = (D_00350444 == p) ? 0 : D_00350444;
}

u8* func_0019f8c0(void) {
    u8* v = func_0019f7d0();
    if (v) {
        u16 t = *(u16*)(v + 2);
        if (t) return v + t;
    }
    return 0;
}

void func_001a6c90(u32 n) {  // set_bit_in_array_b
    D_0032dec0[n >> 5] |= 1 << (n & 31);
    func_001d59b0();
}

void func_001b0210(u8* p, s32 a1, s32 a2, s32 a3) {
    if ((*(s32*)(p + 8) < 0 && *(s32*)(p + 16) == 0) || a2 >= *(s32*)(p + 12)) {
        *(s32*)(p + 8) = a1;
        *(s32*)(p + 12) = a2;
        *(s32*)(p + 24) = a3;
    }
}

void func_001b2488(u8* p) {
    func_00105110(*(void**)(p + 20));
    func_003201e8(&D_01d48c80, p);
}

s32 func_001bb9b0(void) {
    s32 r = 0;
    if (func_001bb4a0()) {
        u32 h = *(u16*)(*(u8**)(D_01d49320 + 8) + 4);
        r = (h >> 4) & 1;
    }
    return r;
}

void MANAGER_exec_zsort(u8* self) {
    func_0016a9a0(self);  // to_16a950
    func_001c14e0(*(void**)(self + 2548));
}

void func_001c8750(void) {
    func_001c8d98(&D_00351ec0, 3);
    func_0014c9f0(16);
    func_001bbe78(1);
    func_0016c640(2);
}

void func_001c9080(void* a0, void* a1, Q128* a2) {
    Q128 t;
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&t), "r"(a2) : "$8", "memory");
    func_0017c4c8(a1, &t);
    func_0016bd60(a1, 20);
}

void func_001ca718(void** p) {
    *p = &D_00351f78;
    D_00351f68 = 0;
    func_001a4e30(p);
    func_00105110(p);
}

void func_001d2070(void** p) {
    *p = &D_003525e8;
    func_001d2210(p);
    func_00106420(p);
}

void func_001dcfb0(void) {
    u8* p = D_00352ae0;
    while (p) {
        u8* n = *(u8**)(p + 40);
        func_001dc878(p);
        p = n;
    }
}

typedef void (*VFnP)(void*, void*);
void func_001e0158(void* a) {
    u8* o = D_01d9e340;
    (*(VFnP*)(*(u8**)o + 4))(o, a);
}

void func_001e27c0(u8* p) {
    *(s32*)(p + 3584) = -1;
    *(s32*)(p + 3524) = 0;
    *(s32*)(p + 3532) = 0;
    *(s32*)(p + 3536) = 0;
    *(s32*)(p + 3556) = 0;
    *(s32*)(p + 3564) = 0;
    *(s32*)(p + 3520) = 0;
    func_001e17b8(p);
}

void func_0022dd40(u8* p) {
    if (func_002282f0(*(s16*)(p + 4)) == 0) {
        func_00102c18(1, 0x17318, (void*)func_0022dc30);
    }
}

u32* func_00232e60(void) {
    u32* p = D_0035dcf8;
    s32 i;
    for (i = 0; i < 64; i++) {
        if (*p == (u32)-1) return p;
        p += 16;
    }
    return 0;
}

void func_00236148(void) {
    D_0035e380[D_0035e370]();
}

void SEQUENCE_D0(void* self) {
    *(void**)self = &D_0035eaf8;
    func_00237238(self);
    func_00106420(self);
}


void func_002835d8(void) {
    if (func_00139d78(D_0035f2b8 + 852)) {
        func_00139510(D_0035f2b8 + 852);
    }
    func_00283960(1);
}

void func_00287b30(void) {
    D_0035f2f0 = 0;
    D_0035f2f4 = 0;
    D_0035f2f8 = 0;
    D_0035f2fc = -1;
    func_00287c78(0);
}

u8 func_0028b7f8(void** p) {
    *p = &D_0035f3a0;
    func_0028b8a0(p);
    return func_0023f820(p);
}


void func_002bd538(void) {
    D_003617e4 = 0;
    D_003617e0 = func_002b823c();
    D_003617e8 = 1;
}

Q128* func_002cb7c8(Q128* out, void* a, void* b) {
    Q128* s = func_002cb890(a, b);  // hash_bucket_get
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(out), "r"(s) : "$8", "memory");
    return out;
}

void* func_002cd910_f(void* r, u32 a1, f32 f) {
    s32 i = (s32)f;
    func_002cd878(r, a1, i, f - (f32)i);
    return r;
}

void func_002de810(void** p) {
    *p = &D_00362ad8;
    func_002cff98(p);
    func_00105110(p);
}

void func_002e7ff8(u32* p) {
    Q128 t;
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&t), "r"(p[1]) : "$8", "memory");
    *(f32*)p = func_001906f0((void*)p[0], &t);
}

u32 func_002f1898(void) {
    return *(u32*)((u8*)func_00168b38(D_01e2c0d0, 25, 0) + 8);  // entry_array_find_nth
}


// fdlibm isnan(): 1 if x is NaN
union DblBits { double d; u64 u; };
s32 func_00304db0(double d) {
    DblBits u;
    u.d = d;
    s32 hx = (s32)(u.u >> 32);
    s32 lx = (s32)u.u;
    hx &= 0x7fffffff;
    hx |= (u32)(lx | (-lx)) >> 31;
    hx = 0x7ff00000 - hx;
    return (s32)((u32)hx >> 31);
}

u8 func_0031c8e8(void** p) {
    *p = &D_00347e60;
    func_00239870((u8*)p + 24);
    return func_0031a840(p);
}

void func_00320050(void** p) {
    *p = &D_00350e60;
    func_001b0188(p);
    func_00106420(p);
}

void func_00325678(void** p) {
    *p = &D_00362c18;
    func_002dea80(p);  // set_vtbl_362d20
    func_00106420(p);
}

}
