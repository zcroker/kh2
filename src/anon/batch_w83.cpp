#include "../common/types.h"

// 128-bit copy through $t0.
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

// 16-byte value whose assignment is a single lq/sq.
struct QWord {
    u32 v[4];
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));

struct Vec4 {
    f32 x, y, z, w;
    Vec4() {}
    Vec4(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    Vec4(const Vec4& o) { QCOPY(this, &o); }
    Vec4& operator=(const Vec4& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));

// Local with a non-trivial destructor: keeps the final call a jal.
struct NoTail { ~NoTail() {} };

extern "C" {
extern u32 D_0034d850[];
void func_001a17c8(void*);
void func_001b78b8(void*);  // to_105110
void func_002cb708(void*);
void func_00105110(void*);
void func_001b3098(void*);
void func_001a9350(void*);
void func_001a6d68(void*);
void func_00187b90(void*);
void func_0017eb98(void*);
void func_001ddd88(void*);

// Destructor body: reset vtable, release owned objects and members.
void func_0016a420(u8* p) {
    NoTail nt;
    *(u32*)p = (u32)D_0034d850;
    if (*(void**)(p + 1164)) func_001a17c8(*(void**)(p + 1164));
    if (*(void**)(p + 2088)) func_001b78b8(*(void**)(p + 2088));  // to_105110
    if (*(void**)(p + 1296)) func_001b78b8(*(void**)(p + 1296));  // to_105110
    void* s = *(void**)(p + 1288);
    if (s) {
        func_002cb708(s);
        func_00105110(s);
    }
    func_001b3098(p + 2048);
    func_001a9350(p + 1952);
    func_001a6d68(p + 1280);
    func_00187b90(p + 768);
    func_0017eb98(p + 320);
    func_001ddd88(p + 156);
    func_001ddd88(p + 128);
}

struct Entry600 {
    u8 pad[452];
    s32 f452;
    s32 f456;
    s32 f460;
    s32 f464;
    s32 f468;
    char name[128];
};
struct Ring600 {
    s32 head;
    s32 tail;
    Entry600 e[4];
};
extern u8* D_0034a6f0;
void func_00192c90(char*, char*);
void func_00192b30(char*);

// Push an entry into a 4-slot ring buffer if there is room.
void func_00153468(s32 a, char* name, s32 b) {
    Ring600* r = (Ring600*)(D_0034a6f0 + 12076);
    s32 idx = r->head;
    s32 n = (idx - r->tail + 4) % 4;
    if (n < 3) {
        r->head = (idx + 1) % 4;
        Entry600* e = &r->e[idx];
        func_00192c90(name, e->name);
        func_00192b30(name);
        e->f456 = a;
        e->f464 = b;
        e->f452 = 0;
        e->f460 = 0;
        e->f468 = 0;
    }
}

s32 func_00181500(s32);
s32 func_001a3570(s32);
void func_00181178(s32);
extern u8 D_0032f05a;

// 00181670: moved to src/yasui/libys/progress.cpp

struct Name10 { u16 c[5]; };
extern Name10 D_01c60530;
extern void* D_0034ecf4;
extern char D_0036c7b8[];
s32 func_001051a0(void*, const char*);
void func_00170c00(void*);
s32 func_00105140(const char*, s32);
void func_002fee78(char*, const char*, ...);
s32 func_001688c8(const char*);
void* func_00170b30(s32);  // alloc_align128
void func_001684c0(const char*, void*, s32, s32);

// Load a named file into a 2 KB-aligned buffer unless it is already loaded.
// 00181ad0: moved to src/yasui/libys/areadata.cpp

struct Info32 {
    u32 f0, f4, f8, f12;
    u32 pad[4];
    Info32() { f12 = 0; }
};
void* func_0016bc20(void*, void*, s32);
void func_0018a818(Info32*, void*, void*);
void* func_001b9bc8(void*);
s32 func_0016bff0(void*);
s32 func_0018a550(Info32*, Info32*);  // state_dispatch_0_1_3

void* func_0018bc60(void* a, void* b);  // 0x0018bc60: definition moved into src/yasui/libys/npc.cpp

void func_0018a958(void*, s32, f32, f32);
s32 func_0019ba60(void*);
void* func_0016bc20b(void*, s32, void*) asm("func_0016bc20");
void func_0018a818b(void*, void*, void*) asm("func_0018a818");
void func_001902a8(void*, void*);

void func_001903d0(void** p, u8* out);  // 0x001903d0: definition moved into src/anon/unit_001900d0.cpp

struct VTest { virtual void f0(); virtual void f4(); virtual s32 test(QWord*); u8 pad[92]; VTest* next; };
u8* func_00186078(u8*);
QWord* func_0016c028(u8*);  // obj_get_attach_or_alt
void func_001991a8(s32, u32);

void func_0019b180(u8* p);  // 0x0019b180: definition moved into src/anon/unit_00199688.cpp

u32* func_00177860(void);
s32 func_001bc2a8(void*, void*, s32);
static inline bool lt4(void* c, void* a) { return func_001bc2a8(c, a, 0) < 4; }

bool func_0019ea10(void* a, u8* b, void* c);  // 0x0019ea10: definition moved into src/anon/unit_0019ea10.cpp

extern f32 D_00349e10;
f32 func_0017c930(void*, void*);
Vec4 func_00184540(f32, f32);
s32 func_00180618(void*);

Vec4 func_001a0a48(void* a, u8* o);  // 0x001a0a48: definition moved into src/anon/unit_0019fb70.cpp

struct Rgba8 { s8 r, g, b, a; };
extern Rgba8 D_0036da98;
void* func_00168b88(void*, s32, u32, s32);  // find_entry16_by_half_word
void func_001bdb70(void*, void*, void*, void*, s32);
static inline u32 packRgba(const Rgba8& c) { return c.r | (c.g << 8) | (c.b << 16) | (c.a << 24); }
struct R8 { u8 pad[8]; void* p; };
struct Obj1b5708 { u32 pad; void* d; };

void func_001b5708(Obj1b5708* p, void* a);  // 0x001b5708: definition moved into src/anon/unit_001b2780.cpp

extern u8 D_01d49520[];
extern u32 D_00351408[];
void func_001980d0(void*, void*, s32, void*, f32);
void* func_001de168b(void*, void*, s32, s32, s32, s32) asm("func_001de168");
void func_001dcc00(void*, void*);  // to_1e34e0_field28
void* func_001050d8(u32);
void func_001c1308(void*, void*, void*, void*, void*);

// Constructor: base init, vtable, then create the owned 56-byte helper.
// 001c23a8: moved to src/anon/unit_001c0638.cpp
void func_001c23a8(u8* p, void* a1, void* a2, void* a3, void* t0, void* t1, void* t2);

s32 func_00186ce8(u8*);
s32 func_00186d18(u8*);  // check_size140to150
s32 func_001c7950(void*, void*, f32, f32);  // copy_quad_if_flag
void func_001c79a0(void*, void*, s32);
void func_001d86a0(s32, s32);
struct Fl40 { u32 on:1; u32 rest:31; };

// 001ccfa0: moved to src/anon/unit_001cc868.cpp

struct Trig { f32 x, y, z; u8 pad[8]; u8 cnt; u8 pad2[2]; u8 flag; u8 pad3[68]; s32* ref; };
void* func_0016e920(s32);
u8* func_001dba18(void*);
Trig* func_001c16f0(void*, Trig*);

// Bump the counter of every trigger whose XZ position lies inside box.
void func_001d6790(f32* box);  // 0x001d6790: definition moved into src/anon/unit_001d63a8.cpp

// r = m * v (4x4 matrix at m, column vectors), via VU0.
static inline Vec4 xform(const void* m, const Vec4& v) {
    Vec4 r;
    asm volatile(
        "lqc2 $vf5, 0(%1)\n\t"
        "lqc2 $vf1, 0(%2)\n\t"
        "lqc2 $vf2, 16(%2)\n\t"
        "lqc2 $vf3, 32(%2)\n\t"
        "lqc2 $vf4, 48(%2)\n\t"
        "vmulax.xyzw ACC, $vf1, $vf5x\n\t"
        "vmadday.xyzw ACC, $vf2, $vf5y\n\t"
        "vmaddaz.xyzw ACC, $vf3, $vf5z\n\t"
        "vmaddw.xyzw $vf5, $vf4, $vf5w\n\t"
        "sqc2 $vf5, 0(%0)"
        : : "r"(&r), "r"(&v), "r"(m) : "memory");
    return r;
}
struct XBox { u8 pad[16]; f32 m[16]; f32 ex, ey, ez; };

// Is point inside the box's local half-extents after transforming by its matrix?
bool func_001db298(XBox* p, const Vec4* in) {
    Vec4 v;
    v = *in;
    v.w = 1.0f;
    v = xform(p->m, v);
    bool r = false;
    if (-p->ex <= v.x && v.x <= p->ex && -p->ey <= v.y && v.y <= p->ey && -p->ez <= v.z && v.z <= p->ez) r = true;
    return r;
}

extern s32 D_01d9eab4;
extern s32 D_01d9ea9c;
extern u8* D_01d9e6e0;
void func_001f5f10();
s32 func_00222568(void);  // vu_const_5f_d
void func_0021ee48(void*, void*, void (*)(), void*, s32, u32, u32);

void func_001f6030(u8* p, u8* e, u8* c) {
    if (D_01d9eab4) return;
    if (D_01d9ea9c) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ull) return;
    if (e[7] == 255) return;
    if ((func_00222568() >> 8) & e[7]) return;
    if (*(s32*)(e + 12) == -1) return;
    if (*(s32*)(e + 20) == -1) return;
    func_0021ee48(p, e, func_001f5f10, p + **(s32**)(c + 12) + 160, *(s16*)(e + 4), e[8], e[6]);
}

extern f32 D_00354bd0[3];
extern f32 D_00354bc0[3];
void func_0021ebe8(void*, s32*);

// Radians -> 16-bit angle units (32768 per pi).
void func_00201208(u8* p, u8* c) {
    u8* s = p + *(s32*)(*(u8**)(c + 12) + 12) + 160;
    s32 a[3];
    a[0] = (s32)(D_00354bd0[0] * 32768.0f / 3.1415927f);
    a[1] = (s32)(D_00354bd0[1] * 32768.0f / 3.1415927f);
    a[2] = (s32)(D_00354bd0[2] * 32768.0f / 3.1415927f);
    func_0021ebe8(s, a);
    *(f32*)(s + 48) = D_00354bc0[0];
    *(f32*)(s + 52) = D_00354bc0[1];
    *(f32*)(s + 56) = D_00354bc0[2];
}

s32 func_002282f0(s32);
u8* func_00227d10(s32);
void func_001ba028(void*);  // list_contains_ptr
double func_00313b80(f32);  // float_to_double
double func_002f83f0(double);
f32 __truncdfsf2(double);  // double_trunc
struct Rot { s16 pad0, pad1; s16 a, b, nx, ny, nz; };
struct Hold { u8 pad[8]; f32* o; };

// Wrap each rotation component through double helpers, optionally negating it.
void func_0022e4f0(Rot* r) {
    if (func_002282f0(r->a)) return;
    Hold* v = (Hold*)func_00227d10(r->b);
    func_001ba028(v->o);  // list_contains_ptr
    f32* o = v->o;
    o[12] = __truncdfsf2(func_002f83f0(func_00313b80(o[12])));  // double_trunc
    if (r->nx) { v->o[12] = -v->o[12]; asm volatile("" ::: "memory"); }
    o = v->o;
    o[13] = __truncdfsf2(func_002f83f0(func_00313b80(o[13])));  // double_trunc
    if (r->ny) { v->o[13] = -v->o[13]; asm volatile("" ::: "memory"); }
    o = v->o;
    o[14] = __truncdfsf2(func_002f83f0(func_00313b80(o[14])));  // double_trunc
    if (r->nz) v->o[14] = -v->o[14];
}

struct VObj20 { virtual void f0(); virtual void f4(); virtual void f8(); virtual void f12(); virtual void f16(); virtual void f20(); };
extern VObj20* D_0035ee3c;
extern VObj20* D_0035ee44;
extern VObj20* D_0035ee40;
extern void* D_0035ee34;
extern void* D_0035ee38;
s32 func_00139d78(void*);
s32 func_0028acc8(void*);
void func_0028abe0(void*);
void func_00250928(void);
void func_0028ce38(void);

void func_0024fe30(void) {
    if (func_00139d78(D_0035ee3c)) D_0035ee3c->f20();
    if (func_00139d78(D_0035ee44)) D_0035ee44->f20();
    if (func_00139d78(D_0035ee40)) D_0035ee40->f20();
    if (func_0028acc8(D_0035ee34)) func_0028abe0(D_0035ee34);
    if (func_0028acc8(D_0035ee38)) func_0028abe0(D_0035ee38);
    func_00250928();
    func_0028ce38();
}

u8* func_00257770(void);
extern void* D_0035f01c;
extern void* D_0035f020;
extern void* D_0035f024;
u8 func_00139d78c(void*) asm("func_00139d78");
u8 func_0028acc8c(void*) asm("func_0028acc8");

// Is anything in this menu still busy?
u8 func_00262e30(void);  // 0x00262e30: definition moved into src/anon/unit_0025f6b8.cpp

void func_00139510(void*);
s32 func_0027e920(void);
void func_0027e770(void);
// Tz CmItem LeaveHelp
void LeaveHelp(void*) asm("_ZN2Tz6CmItem9LeaveHelpEv");
void LeaveHelp(void*);  // 0x00262ff8: definition moved into src/anon/unit_0025f6b8.cpp

extern void* D_0035f010;
extern void* D_0035f0ec;
void* func_00257070(s32);
u8* func_00281180(void*, void*);
void func_001a3188(u32, s32, s32);
u8* func_00281f20(void*);
u32 func_0028b040(void*);
void func_001a3458(u32, s32);
struct Six { u8 b0, b1, b2, b3, b4, b5; };

s32 func_0026af30(s32 idx, u32 id);  // 0x0026af30: definition moved into src/anon/unit_0026a900.cpp

extern VObj20* D_0035f208;
extern void* D_0035f218;
void func_00274ac8(void);
void func_0028f878(void);
void func_0028d620(void*);
void func_00276e28(void);
void func_002945a8(void);
void func_00295868(void);
void func_00297010(void);
void func_00297e00(s32);
void func_002995a8(void);
void func_0029aac0(s32);
void func_0029ee38(void);
void func_002a07f0(s32);
void func_002a2150(void);
void func_002a4df8(void);
void func_002a6a18(void);
void func_002a7760(void);
void func_002a8a88(void);
void func_002aecf0(s32);
void func_00275cb8(void);
void func_002763c8(void);

void func_002749f0(void);  // 0x002749f0: definition moved into src/anon/unit_002748a0.cpp

void func_00288c58(void*, s16);
void func_00288f48(void*, s32, s32, s32, s32);
void func_0028af18(void*, s32);
void func_0028b1b0(void*, s32);
union S16Ptr { s16* p; s16 h; };
struct Grid { s16 h0, h2, h4, pad6, pad8, pad10, pad12, h14, h16, h18, h20, h22, h24, h26, h28, pad30, pad32, pad34; u8 b36, b37, b38, b39; u32 pad40; S16Ptr f44; S16Ptr f48; };

void func_002888f8(Grid* g, s32 n, u8 kind);  // 0x002888f8: definition moved into src/anon/unit_002880b8.cpp

void* func_0023f1b0(s32);
void* func_0023c4b8(void*, s32);
u8* func_00236ca8(void*, s32);
void func_001386e0(void*, s32, void*, void*, s32, s32);
// Tz Pause CreateFadeObject
void CreateFadeObject(u8*, s32, s32, s32, s32, s32, s32, s32) asm("_ZN2Tz5Pause16CreateFadeObjectEz");
// 0028d8c0: moved to src/anon/unit_0028c878.cpp

struct Flags236 { u8 pad[236]; u32 bits[42]; };
extern Flags236* D_0035f610;
Flags236* func_002a9d68(void);
u8* func_001a82b0(u8*);
void* func_002764b0(u8);
s32 func_002954e0(void*);

void func_002ab448(void);  // 0x002ab448: definition moved into src/anon/unit_002a99c8.cpp

u8* func_002d73f0(void);
s32 func_002cee58(void*, void*);

// d = a - b (xyzw) via VU0.
static inline void vsub(Vec4* d, const void* a, const void* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(d), "r"(a), "r"(b) : "memory");
}
// |v.xyz| via VU0.
static inline f32 vlen(const Vec4* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\t"
                 "vaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2 $8, $vi22\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
struct Pt4 {
    f32 x, y, z, w;
    Pt4(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
} __attribute__((aligned(16)));

s32 func_002d89b0(u8* p, u8* a);  // 0x002d89b0: definition moved into src/anon/unit_002d6f70.cpp

extern void* D_00361f60;
void* func_002d9210(void*);
s32 func_001c0cd8(void*);
u8* func_0016bc20c(void*, s32, s32) asm("func_0016bc20");
Vec4* func_0016c028b(void*) asm("func_0016c028");

// Is p within the target's radius?
bool func_002da308(u8* p) {
    void* v = func_002d9210(D_00361f60);
    if (!v) return false;
    if (func_001c0cd8(v)) return false;
    u8* pos = p + 1344;
    f32 r = *(s16*)(func_0016bc20c(v, 5, -1) + 16);
    Vec4* q = func_0016c028b(v);
    Vec4 d;
    vsub(&d, pos, q);
    return vlen(&d) < r;
}

s32 func_002e0fe8(void*);

// Direction (scaled xy, normalized) with its length in w; zero if a is not ready.
Vec4 func_002e17a0(void* a, f32* b) {
    if (!func_002e0fe8(a)) {
        return Vec4(0.0f, 0.0f, 0.0f, 0.0f);
    }
    Vec4 t;
    t.x = b[0];
    t.y = b[1];
    t.w = t.z = 0.0f;
    f32 k = 25.0f;
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&t), "f"(k) : "$8", "memory");
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\t"
                 "vaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2 $8, $vi22\n\t"
                 "vaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\t"
                 "vmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(len) : "r"(&t) : "$8", "memory");
    t.w = len;
    return t;
}

f32 func_002f8ad0(f32, f32);
f32 func_0017ce10(f32);
Vec4 func_0017d0e8(f32);

// Turn cur's heading toward tgt by at most lim.
Vec4 func_002ea360(f32 lim, f32* cur, f32* tgt);  // 002ea360: moved to src/anon/unit_002ea2b8.cpp

typedef s32 (*SigFn)(s32);
s32 func_002feac0(void*);
s32 func_002fedf0(void*);
s32 func_002fed98(void*, s32, s32);
s32 raise_r(u8*, u32, u32, u32) asm("_Z16wtarget_002febb0jjjj");
// newlib _raise_r(reent, sig): errno at +0, signal table at +468.
s32 raise_r(u8* r, u32 sig, u32, u32) {
    if (sig >= 32) {
        *(s32*)r = 22;
        return -1;
    }
    if (*(SigFn**)(r + 468) == 0 && func_002feac0(r) != 0) return -1;
    SigFn* tab = *(SigFn**)(r + 468);
    SigFn f = tab[sig];
    if (f == (SigFn)0) return func_002fed98(r, func_002fedf0(r), sig);
    if (f == (SigFn)1) return 0;
    if (f == (SigFn)-1) {
        *(s32*)r = 22;
        return 1;
    }
    tab[sig] = 0;
    f(sig);
    return 0;
}

// Elements of member arrays, destroyed through their vtables.
struct E408 { virtual void f0(); virtual void f4(); virtual void f8(); virtual void f12(); u8 pad[404]; };
struct E592 { virtual void f0(); virtual void f4(); virtual void f8(); virtual void f12(); u8 pad[588]; };
struct E412 { virtual void f0(); virtual void f4(); virtual void f8(); virtual void f12(); u8 pad[408]; };
struct E344 { virtual void f0(); u8 pad[340]; };
struct VReg { virtual void f0(); virtual void f4(void*); };
union RegPtr { u8* p; u32 v; };
extern u32 D_0034a5b0[];
extern u32 D_00347e80[];
extern u32 D_00347f98[];
extern RegPtr D_00347f80;
void func_00239870(void*);
void func_002361d0(void*);

void func_0031c368(u8* p) {
    *(u32*)p = (u32)D_0034a5b0;
    func_00239870(p + 6208);
    if (p + 4576) {
        E408* e = (E408*)(p + 6208);
        for (;;) {
            if ((E408*)(p + 4576) == e) break;
            --e;
            e->f12();
        }
    }
    if (p + 496) {
        E408* e = (E408*)(p + 4576);
        for (;;) {
            if ((E408*)(p + 496) == e) break;
            --e;
            e->f12();
        }
    }
    *(u32*)(p + 48) = (u32)D_00347e80;
    func_002361d0(p + 80);
    *(u32*)(p + 48) = (u32)D_00347f98;
    *(u32*)p = (u32)D_00347f98;
    (*(VReg**)(D_00347f80.p + 20))->f4(p);
}

extern u32 D_0034a848[];
extern u32 D_00348608[];
void func_0031cec0(void*);

void func_0031d0f8(u8* p) {
    *(u32*)p = (u32)D_0034a848;
    if (p + 2576) {
        E592* e = (E592*)(p + 5536);
        for (;;) {
            if ((E592*)(p + 2576) == e) break;
            --e;
            e->f12();
        }
    }
    if (p + 916) {
        E412* e = (E412*)(p + 2564);
        for (;;) {
            if ((E412*)(p + 916) == e) break;
            --e;
            e->f12();
        }
    }
    *(u32*)p = (u32)D_00348608;
    func_0031cec0(p + 64);
    *(u32*)p = (u32)D_00347f98;
}

extern u32 D_00350ab0[];
extern u32 D_00350bb0[];
extern u32 D_0034e8a8[];
void func_00239848(void*);  // set_vtbl_36eb28_then_call
void func_001ac5b8(void*);

// Deleting destructor.
void func_0031fb90(u8* p) {
    *(u32*)p = (u32)D_00350ab0;
    if (p + 3280) {
        E344* e = (E344*)(p + 4656);
        for (;;) {
            if ((E344*)(p + 3280) == e) break;
            --e;
            e->f0();
        }
    }
    func_00239870(p + 2936);
    *(u32*)p = (u32)D_00350bb0;
    if (p + 1544) {
        E344* e = (E344*)(p + 2920);
        for (;;) {
            if ((E344*)(p + 1544) == e) break;
            --e;
            e->f0();
        }
    }
    func_00239870(p + 1200);
    func_00239870(p + 848);
    func_00239870(p + 484);
    *(u32*)(p + 132) = (u32)D_0034e8a8;
    func_00239848(p + 132);  // set_vtbl_36eb28_then_call
    func_001ac5b8(p);
    func_00105110(p);
}

}
