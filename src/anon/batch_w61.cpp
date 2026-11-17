#include "../common/types.h"

struct Vq {
    f32 x, y, z, w;
    Vq() {}
    Vq(const Vq& o) { *this = o; }
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

union FU { f32 f; void* p; u32 u; };

struct M64 {
    u8 b[64];
    M64& operator=(const M64& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

union HP;
u8* wtarget_00133980(HP*, u32, u32, u32, u32) asm("_Z16wtarget_00133980jjjj");
u32 ctarget_00188fe0(u32, u32, u32, u32) asm("_Z16ctarget_00188fe0jjjj");
void wtarget_002eccd0(u32, u32, u32, u32) asm("_Z16wtarget_002eccd0jjjj");

extern "C" {
void func_00104d30(u8*, u32);
extern u8 D_0032bae0[];
extern u8 D_0032bb30[];

// 001052a8: moved to src/common/area.cpp

void func_0010a800(u8*, u8*, u8*);  // copy_global_3bytes
void func_00108600(u8* p);  // 00108600: moved to src/anon/unit_001085a8.cpp

struct VObj { s32 (**vt)(...); };
extern u64 D_0036a930;

void func_0011b6a8(u8*);
s32 func_001317a8(void*);
s32 func_00131918(u8** a0, M64* dst) {
    u8* base = a0[1];
    s32 off = *(s32*)(base + 44);
    u8* t = base + off;
    if (off == 0) {
        func_0011b6a8((u8*)dst);
        return 1;
    }
    M64* src = (M64*)(t + (func_001317a8(a0) << 6));
    *dst = *src;
    return 0;
}

void func_00145c68(void*, u8);
struct E28 { u8 b0; u8 pad[27]; };
struct S145 { u8 pad[8]; E28* arr; u8 pad2[8]; s32 n; };
void func_00145b90(S145* a0, u64 mask);  // 0x00145b90: definition moved into src/anon/unit_00145600.cpp

void func_00147c78(u8*, u8*);  // copy_bytes_232_to_12
void func_0011cd80(u32, u8*, u8*, u8*, void*, u32);
struct B148 { s16 a, b; u8 pad[12]; };
void func_00148598(u8* a0, u8* a1);  // 0x00148598: definition moved into src/anon/unit_00147140.cpp

void func_00141010(f32);
u8* func_00140df0(void);
extern s32 D_0034a990;
extern f32 D_0034a994;
extern f32 D_0034a998;
extern f32 D_0034a99c;
extern Vq D_0034a9a0;
// 00158870: moved to src/harata/libdk/scopecamera.cpp

void func_001391c8(void*, u32, u32);
void func_0015aa98(u8* p, u32 a, u32 b, f32 f);  // 0x0015aa98: definition moved into src/anon/unit_0015a810.cpp

void* func_00161548(void*);
void func_00161770(void*);
void func_001616d8(void*);
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

void func_0014d358(void*, u32, void*, u32);
void func_00102788(u32, u32, u32, void*);
void func_001adcf8(s32);
extern u8 D_004f5280[];
extern u8 D_001685f0[];
extern u8 D_00168678[];
extern u32 D_0032b91c;
struct E16 { u32 a, b, c, d; };
extern E16 D_0034d800[];
// 00168808: moved to src/yasui/libys/file.cpp

u8* func_00176fb0(u8*, u32);
s32 func_001a0920(u8*, u8*);
s32 func_001b9d40(u8*);  // vtable_call_slot64_flags
void func_00177008(u8*, u8*, u32);
// 001790c0: moved to src/yasui/libys/player.cpp

s32 func_0019ba60(void*);
s32 func_0019c6f0(void*);
u8* func_001b9bc8(u8*);
// 0017e280: moved to src/yasui/libys/friend.cpp

u32 func_0016a070(void*);
void func_001d6088(u32, u8*);
void func_001890a8(void*, u32);
void func_001d7e78(void*);
extern u8* D_01c608b8;
extern u8 D_0032e020[];
// 00185d10: moved to src/anon/unit_00185d10.cpp
void func_00185d10(u8* a0);

void func_0018eb98(void*, void*);
struct S18 {
    u32 a; f32 b, c; u32 d;
    S18& operator=(const S18& o) { a = o.a; b = o.b; c = o.c; d = o.d; return *this; }
};
struct Ent48 { u32 id; u32 pad[3]; S18 s; Vq v; };
struct Tbl48 { s32 n; u32 pad[3]; Ent48 e[256]; };

u32 func_0016bc20(u32, u32, u32);
void func_0018a818(u8*, u32, u32);
void func_001902a8(u32*, u8*);


u8* func_0016e920(u32);
s32 func_0016f448(u8);
extern u8 D_00350378;
extern u8 D_0032bae2;

f32* func_0015cc70(void);

extern u32 D_01d49328[8];
extern u32 D_01d4934c;
extern u32 D_01d49348;
extern u32 D_01d49350[2];

void func_0019fbe0(Vq*);
s32 func_001b2d10(void*, Vq*);

void func_001c8d98(void*, u32);
void func_001c9b90(void);
void func_001d2710(void*);
void func_00319f88(void*);
void func_0019f9a8(void*);  // array8_free_slots
void func_001c0248(void*);
void func_00319fb0(void*);  // big_obj_dtor
extern u8 D_00352360[];
extern u8 D_00351eb8[];
extern u8 D_00351ec0[];
extern u8 D_0034e8b8[];
extern u8 D_0034ee08[];
struct NoTail { ~NoTail() {} };
void func_001cfe18(u8* p);  // 0x001cfe18: definition moved into src/anon/unit_001cf0b0.cpp

u32 func_002fd248(u32, u8*, u32, u32, void*);
extern u8* D_01d5ba10[3];
extern u8 D_003216b8[];
// 001d3408: moved to src/anon/unit_001d30b0.cpp

u32* func_001ba158(void);
void func_001963c8(u32);
struct Pair { s32 id; u32 val; };
extern Pair D_0036e548[4];
void func_001d5218(s32 id);  // 0x001d5218: definition moved into src/anon/unit_001d4f40.cpp

s32 func_001d6ec8(void);
s32 func_001d5b78(u32, u32);

struct Node { void* vt; u32 f4, f8, f12, f16, f20, f24, f28; f32 f32_; u32 f36; Node* next; };
struct NList { Node* head; Node* tail; s32 count; };
extern NList D_00352ae0;
extern s32 D_00352ae8;
extern u8 D_00352b48[];

s32 func_001dc018(u32, u32, void*, void*);
s32 func_001dc4e8(u8* p, u32 a, u32 b, u32 c);  // 0x001dc4e8: definition moved into src/anon/unit_001dbfd8.cpp

void func_001e1500(void*);
s32 func_001e1350(void*, u32);
u32 func_0017df58(u32);
extern u32 D_0034e948;
extern f32 D_00349e10;
void func_001e15a8(u8* p);  // 0x001e15a8: definition moved into src/anon/unit_001e0cb8.cpp

void func_0021f620(void*, u32);
extern u8 D_01d9e8c0[];
struct A1fb { u8* p; u32 v; void* fn; f32 b; f32 a; u8* q; };

void func_001e7798(u32, u32);
extern u32 D_01d9e6e4;
void func_00205718(u8* a0, u8* a1) {
    u8* s = a0 + *(u32*)(*(u8**)(a1 + 12) + 8) + 160;
    if (*(u32*)(s + 80)) { func_001e7798(D_01d9e6e4, *(u32*)(s + 80)); *(u32*)(s + 80) = 0; }
    if (*(u32*)(s + 84)) { func_001e7798(D_01d9e6e4, *(u32*)(s + 84)); *(u32*)(s + 84) = 0; }
    if (*(u32*)(s + 88)) { func_001e7798(D_01d9e6e4, *(u32*)(s + 88)); *(u32*)(s + 88) = 0; }
}

void func_00102448(u32, u32);
s32 func_00225b50(s32);
extern s32 D_0035db10;
extern s32 D_0035de20;
s32 func_002282f0(s32 a, u32 b);  // 0x002282f0: definition moved into src/anon/unit_00224780.cpp

s32 func_00139d78(void*);
void func_00139510(void*);
extern u8* D_0035f038;
void func_00257be0(void*) asm("_Z13func_00257be0Pv");
void func_00257be0(void*) {
    if (func_00139d78(D_0035f038 + 0xb350)) func_00139510(D_0035f038 + 0xb350);
    if (func_00139d78(D_0035f038 + 0xb504)) func_00139510(D_0035f038 + 0xb504);
    if (func_00139d78(D_0035f038 + 0xb6b8)) func_00139510(D_0035f038 + 0xb6b8);
}

u32 func_00257070(u32);
u8* func_00281180(u32, u32);
extern u32 D_0035f010;
struct T26 { u8 pad[17]; u8 n; u8 pad2[18]; u16 a[1]; };
void func_0026b508(void);  // 0x0026b508: definition moved into src/anon/unit_0026a900.cpp

extern u8* D_0035f21c;
void func_00276b10(void);  // 0x00276b10: definition moved into src/anon/unit_002748a0.cpp

s32 func_00276a90(void);
void func_00276b90(void);
extern u8* D_0035f60c;
s32 func_002a9470(void);  // 0x002a9470: definition moved into src/anon/unit_002a92a0.cpp

u8* func_00294000(u32);
extern u8* D_0035f620;
s32 func_002ad660(void);  // 0x002ad660: definition moved into src/anon/unit_002a99c8.cpp

void func_002c1cb0(u32, u8);
void func_002c1b60(u8* p, u8* a);  // 0x002c1b60: definition moved into src/anon/unit_002c10e0.cpp

void func_002c6280(u8* p, s32 i);  // 0x002c6280: definition moved into src/worldmap/cameramanager.cpp

s32 func_002d0200(u8* p);  // 0x002d0200: definition moved into src/anon/unit_002cf260.cpp

void sceVu0RotMatrixZ(void*, f32);
void sceVu0RotMatrixY(void*, void*, f32);
void sceVu0RotMatrixX(void*, void*, f32);

union DW { double d; u64 u; struct { u32 lo; s32 hi; } w; };
// fdlibm isinf
s32 func_00304d68(double x) {
    DW u; u.d = x;
    s32 hx = u.w.hi;
    s32 lx = u.w.lo;
    hx &= 0x7fffffff;
    hx |= (u32)(lx | (-lx)) >> 31;
    hx = 0x7ff00000 - hx;
    return 1 - (s32)((u32)(hx | (-hx)) >> 31);
}

u64 func_00314330(s32);
u64 func_00313f40(u64, u64);  // double_mul
u64 func_00313e80(u64, u64);  // double_div

s32 DIntr(void);
void EIntr(void);  // ee_intr_get_enable
void func_00316998(void);
extern s32 D_00367924;
extern s32 D_00367920;

void func_002f8ad0(f32, f32);
extern Vq D_0034aa50[2];

static inline f32 lsq(const void* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(v) : "$8");
    return r;
}
s32 func_00142b70(u8* p);  // 0x00142b70: definition moved into src/anon/unit_00141458.cpp
}

struct Hd { u16 n; u8 b2; u8 b3; u32 a; u32 c; u32 d; };
union HP { Hd* h; u8* b; };
// Appends a 16-byte header plus n*16 bytes to a packet cursor; the fifth word arrives in t0.
u8* wtarget_00133980(HP* pp, u32 a1, u32 a2, u32 a3, u32 t0) {
    pp->h->b2 = 0;
    pp->h->c = a3;
    pp->h->d = t0;
    pp->h->b3 = 80;
    pp->h->a = a1;
    pp->h->n = a2;
    u8* r = pp->b;
    pp->b = r + (a2 << 4) + 16;
    return r + 16;
}

extern "C" u32 func_001b7818(u32);
u32 ctarget_00188fe0(u32 a0, u32 a1, u32, u32);  // 0x00188fe0: definition moved into src/anon/unit_00188848.cpp

extern "C" f32 D_01e2c040;
extern "C" f32 D_01e2c044;
extern "C" f32 D_01e2c048;
// 002eccd0: moved to src/anon/unit_002ec5f8.cpp
