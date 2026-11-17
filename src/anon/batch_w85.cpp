#include "../common/types.h"

// 128-bit vector with the engine's self-checking quadword copy
struct Vec4 {
    f32 x, y, z, w;
    Vec4& operator=(const Vec4& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

// local with an empty destructor: keeps the final call a jal
struct NoTail { ~NoTail() {} };

struct Slot117 { u32 a, b; void* p; u8 pad[52]; ~Slot117() {} } __attribute__((aligned(16)));
struct SlotArr117 { Slot117 s[24]; };
struct Obj117 {
    void* vtbl; u8 pad[28];
    SlotArr117 slots;
    void* f1568;
};

extern "C" {

void func_001617c8(void);
void func_00106998(s32);
void func_001069f8(s32);
u8* func_00102c18(s32, s32, void (*)(void));
void func_00161818(void);
void func_001433e8(void);
void func_00107888(void);
void func_001dd2b8(void);
void func_00144250(void);
void func_00161880(void);
void func_001618a0(void);
void func_001dd920(void);
void func_00167228(void);
void func_0015de18(void);
// registers this module's handlers
void func_001618f0(void) {
    func_001617c8();
    func_00106998(0);
    func_001069f8(0);
    func_00102c18(3, 6000, func_00161818);
    func_00102c18(3, 6001, func_001433e8);
    func_00102c18(3, 30000, func_00107888);
    func_00102c18(3, 41000, func_001dd2b8);
    func_00102c18(3, 43000, func_00144250);
    func_00102c18(3, 49999, func_00161880);
    func_00102c18(3, 50000, func_001618a0);
    func_00102c18(3, 60001, func_001dd920);
    func_00102c18(3, 71000, func_00167228)[4] = 0;
    func_00102c18(3, 65000, func_0015de18);
}

void func_00102788(u32, s32, s32, void (*)(void));
u8* func_00102c80(void);
void func_00111f50(void);
void func_001122a0(void);
void func_00112388(void);
void func_001127b0(void);
void func_00190128(void*);
void func_001357c8(void);
void func_00135d78(void);
extern u32 D_00351214;
extern u32 D_00341708[3];
extern Vec4 D_00341720[3];
extern Vec4 D_00341750[3];
extern u8 D_00341700;
extern u32 D_00341780;
extern u8 D_003417b0[];
void func_001123f0(void);  // 0x001123f0: definition moved into src/anon/unit_001117d8.cpp

void func_001dc920(void*);
void func_00117910(void*, s32);  // entry64_clear_fields
void func_0018f028(void*);
void func_00113668(void*);
extern u8 D_003476f0[];
// destructor body: release the 24 slots, then the base part
void func_00117dd8(Obj117* o) {
    NoTail g;
    s32 i;
    o->vtbl = D_003476f0;
    for (i = 0; i < 24; i++) {
        if (o->slots.s[i].p) func_001dc920(o->slots.s[i].p);
        func_00117910(o, i);  // entry64_clear_fields
    }
    if (o->f1568) { func_0018f028(o->f1568); o->f1568 = 0; }
    o->slots.~SlotArr117();
    func_00113668(o);
}

void func_0011ee18(void*);  // obj_ctor_347940
void func_0011f2f0(void*);
extern u8 D_00347a90[];
typedef s32 (*PartFn)(void*);
struct Obj123 { void* vtbl; u8* data; u8 pad[8]; s32 n; s32 a[3]; s32 b[3]; };
// constructor: walks the part offset table, accumulating running sizes
void func_001239d8(Obj123* o);  // 0x001239d8: definition moved into src/anon/unit_00123990.cpp

void func_00188340(void*, s32, s32, s32);
void func_0016cce8(void*, s32, s32, s32, s32);
struct Obj184;
struct Obj184vt { u8 pad[44]; void (*f44)(Obj184*); };
struct Sub184vt { u8 pad[16]; void (*f16)(void*, Obj184*); };
struct Sub184 { Sub184vt* vt; };
struct Obj184 { Obj184vt* vt; u8 p4[8]; Sub184* f12; u8 p16[248]; u32 flags; u8 p268[500]; u8 f768[388]; void* f1156; };
// 001841f0: moved to src/anon/unit_00183088.cpp

u32 func_001a80c8(u32);  // table24_find_by_id
u8* func_001a8190(u32);
void func_001c3150(void*, u16);
struct St1a2 { u8 pad[392]; u16 s[4]; u8 p400[24]; u8 r[8]; u8 p432[28]; u8 f460[4]; };
void func_001a24a0(St1a2* o, u32 id);  // 0x001a24a0: definition moved into src/anon/unit_0019fb70.cpp

s32 func_00181500(u32);
u8* func_001947c0(u32, u32);
struct Cond1a8 { u16 id, need, without; u8 lv; };
// checks an entry's requirements (id, required/forbidden flags, level)
s32 func_001a8930(Cond1a8* c, u32 id, u32 a2);  // 0x001a8930: definition moved into src/anon/unit_001a8618.cpp

extern s32 D_00350f18;
extern u32 D_00350f1c;
extern char D_0036d9a8[];
extern u8 D_01d44440[];
extern u32 D_01d44400;
extern u32 D_01d48c44;
void func_00102448(void*, s32);
void func_002fee78(char*, const char*, ...);
void func_001688c8(char*);
void func_00168388(char*, void*, s32, s32);
s32 func_001688b8(void);
// 001b1ee8: moved to src/anon/unit_001b1d20.cpp

s32 func_001bb4a0(void);
u8* func_001bbcb0(void);
void func_001d1b60(void*, s32);
struct Dig1d8 { u8 p0[12]; u32 flags; u8 p16[28]; s32 cur; };
static inline u32 dig1d8_on(Dig1d8* e) { return e->flags & 1; }
// replaces one decimal digit of an entry's value
void func_001d89e8(s32 digit, s32 val, s32 idx);  // 0x001d89e8: definition moved into src/anon/unit_001d7458.cpp

// 001e09d0: moved to src/rikeda/saveram_gumibattle.cpp

struct V3f { f32 x, y, z; };
extern V3f D_00354bd0;
extern V3f D_00354bc0;
void func_0021ebe8(void*, s32*);
// converts the current rotation (radians) to fixed-point angles and applies it
void func_00201668(u8* o, u8* a1) {
    s32 r[3];
    u8* t;
    f32 x = D_00354bd0.x * 32768.0f / 3.1415927f;
    f32 y = D_00354bd0.y * 32768.0f / 3.1415927f;
    f32 z = D_00354bd0.z * 32768.0f / 3.1415927f;
    t = o + *(s32*)(*(u8**)(a1 + 12) + 12) + 160;
    r[0] = (s32)x;
    r[2] = (s32)z;
    r[1] = (s32)y;
    func_0021ebe8(t, r);
    *(f32*)(t + 48) = D_00354bc0.x;
    *(f32*)(t + 52) = D_00354bc0.y;
    *(f32*)(t + 56) = D_00354bc0.z;
}

char* func_00227120(void);  // get_data_1dbd8f8
s32 strncmp(const char*, const char*, s32);
extern char D_00370cd8[];
extern char D_00370ce8[];
extern char D_00370cf8[];
extern char D_00370d08[];
extern char D_00370d18[];
s32 func_00224c20(void);  // 0x00224c20: definition moved into src/anon/unit_00224780.cpp

struct Blk225 { Blk225* next; Blk225* prev; u8 used; u32 size; u8 pad[48]; };
struct Heap225 { u8 pad[8]; Blk225* head; };
// first-fit (mode 1: last fit, carved from the top) block allocator
void* func_00225eb8(Heap225* h, u32 size, s32 mode);  // 0x00225eb8: definition moved into src/anon/unit_00224780.cpp
struct Obj22f;
struct Obj22fvt { u8 pad[40]; void (*f40)(Obj22f*); };
struct Obj22f { Obj22fvt* vt; };
void func_001ba028(Obj22f*);  // list_contains_ptr
void func_00232db0(u32);
struct Ent22f { s32 id; u32 f4; Obj22f* obj; u8 pad[28]; };
union Tbl22f { Ent22f* p; u8 c; };
extern Tbl22f D_0035dcfc;
// releases every live entry; returns whether any was released
s32 func_0022f5e8(void) {
    s32 r = 0;
    s32 i;
    if (!D_0035dcfc.p) return 0;
    for (i = 0; i < 96; i++) {
        if (D_0035dcfc.p[i].obj) {
            func_001ba028(D_0035dcfc.p[i].obj);  // list_contains_ptr
            D_0035dcfc.p[i].obj->vt->f40(D_0035dcfc.p[i].obj);
            D_0035dcfc.p[i].obj = 0;
            func_00232db0(D_0035dcfc.p[i].f4);
            D_0035dcfc.p[i].id = -1;
            r = 1;
        }
    }
    return r;
}

f32 sinf(f32);
f32 cosf(f32);
struct Rot237 { u8 p0[28]; f32 m28, m32, m36, m40; u8 p44[68]; f32 x, y, z; };
// sets euler angles and rebuilds the matrix rows that depend on them
void func_00237740(Rot237* r, f32 x, f32 y, f32 z) {
    f32 sx, cx, sy, cy, sz, cz, sxsy;
    r->y = y;
    r->z = z;
    r->x = x;
    sx = sinf(r->x);
    cx = cosf(r->x);
    sy = sinf(r->y);
    cy = cosf(r->y);
    sz = sinf(r->z);
    cz = cosf(r->z);
    sxsy = sx * sy;
    r->m28 = cy * cz;
    r->m36 = sxsy * cz + cx * sz;
    r->m32 = cy * -sz;
    r->m40 = sxsy * -sz + cx * cz;
}

extern void* D_0035ed54;
extern void* D_0035ed4c;
extern void* D_0035ed5c;
extern void* D_0035ed58;
struct Pair248 { s16 a, b, c; };
extern Pair248 D_00371d40[];
s32 func_00139d78(void*);
s32 func_0023f0c0(void*);
void func_0023f070(void*, s32, s32);
s32 func_0028acc8(void*);
void func_0028ab20(void*);
s32 func_002891e8(void*);
void func_00248720(void) {
    if (func_00139d78(D_0035ed54) && func_0023f0c0(D_0035ed54) != 32)
        func_0023f070(D_0035ed54, 32, -1);
    if (func_0028acc8(D_0035ed4c)) {
        s32 v;
        func_0028ab20(D_0035ed4c);
        v = func_002891e8(D_0035ed4c);
        if (func_00139d78(D_0035ed5c) && func_0023f0c0(D_0035ed5c) != D_00371d40[v].c)
            func_0023f070(D_0035ed5c, D_00371d40[v].c, -1);
    }
    if (func_00139d78(D_0035ed58) && func_0023f0c0(D_0035ed58) != 35)
        func_0023f070(D_0035ed58, 35, -1);
}

extern void* D_0035f01c;
struct Ent273 { u16 id; u8 pad[6]; };
extern Ent273 D_00373af8[];
s32 func_00287bc0(void);
s32 func_0028b160(void*, u8*);  // find_index_in_array
u32 func_00192048(u16);
void func_001a98e8(void*, s32, u32, u32, s32);
s32 func_0023aa98(void*);
u32 func_0023a918(void*);
void func_001a9ae8(void*, u8*, u32, u32);
void func_00273078(u8* base, u32 a1, u32 a2, u32 a3, u8* p);  // 0x00273078: definition moved into src/anon/unit_00271e08.cpp

extern s16 D_00373d60[];
extern s16 D_00373d68[];
extern u8* D_0035f204;
extern u32 D_0035f14c;
extern u32 D_0035f148;
extern u32 D_0035f210;
extern s32 D_0035f144;
s32 func_00276368(void);
void func_00138c10(void*, s32);
void func_0028d8c0(void*, s32, u32, u32, u32, s32, s32, s32);
// plays the selected entry's cue (mode picks the table)
void func_00276220(s32 mode, s32 idx);  // 0x00276220: definition moved into src/anon/unit_002748a0.cpp

extern f32 D_0035f294;
extern f32 D_00349e10;
extern u8 D_0035f298;
struct Snd281 { s16 id; };
extern Snd281 D_0035f280;
double func_00313b80(f32);  // float_to_double
s32 func_003142e0(double, double);  // double_compare
s32 func_001688b8(void);
s32 func_00292a90(s16);
void func_00292b40(Snd281*, s32);
void func_00281d48(void);  // 0x00281d48: definition moved into src/anon/unit_00281cf0.cpp

struct Item282 { u16 id; u8 a, b; u16 pad; };
struct List282 { union { s32 n; u16 h; } u; Item282 e[1]; };
u8* func_001058e8(void);
// appends each nonzero id from the 8-entry table that is not already listed
void func_00282620(List282* l);  // 0x00282620: definition moved into src/anon/unit_00282620.cpp

extern u8 D_003741e8[];
u32 func_00259618(u16, u8*, s32);
void func_00192b30(u32);
void func_00192cc0(u8*, u8*, u8);
void func_00282858(List282* l, s32 first, s32 count);  // 0x00282858: definition moved into src/anon/unit_00282620.cpp
void func_0028af18(void*, s32);
void func_0028b1b0(void*, s32);
void func_0028b218(void*, s32);  // obj_set_flag39_bits3000
void func_0028b248(void*, s32);  // set_field28_half
union S16U { s16 s; u8 c; };
union U32U { u32 w; u8 c; };
struct Obj288 { u8 p0[4]; s16 n; u8 p6[8]; s16 h14; u8 p16[2]; s16 h18; u8 p20[2]; s16 h22; u8 p24[16]; U32U* a; S16U* b; S16U* c; };
void func_00288e88(Obj288* o);  // 0x00288e88: definition moved into src/anon/unit_00288b00.cpp

void func_0028eb88(u32, s32, f32, f32);
void func_0028e8b8(u32, s32, s32, s32);
struct Bar28b { u32 h; u8 p4[28]; s32 cur; s32 max; u8 p40[4]; s32 a; s32 b; };
void func_0028bfc0(Bar28b* o, s32 v);  // 0x0028bfc0: definition moved into src/anon/unit_0028bfc0.cpp

extern s32 D_0035f4c4;
extern s32 D_0035f4bc;
extern s32 D_0035f4c0;
extern s32 D_0035f4c8;
extern s32 D_0035f4cc;
extern s32 D_0035f4d0;
extern void* D_0035f4d4;
extern void* D_0035f4dc;
extern void* D_0035f4e4;
extern s8 D_00374590[][2];
u32 func_00103570(void);
void* func_001063f0(s32, u32);
void func_002fde18(void*, s32, s32);
void func_002926c0(s32 idx);  // 002926c0: moved to src/anon/unit_00292620.cpp

extern void* D_0035f200;
s32 func_0028afa8(void*);
s32 func_0028b040(void*);
u8* func_002891b8(void*, s32);
void func_00138c10(void*, s32);
void func_002955a8(void);  // 0x002955a8: definition moved into src/anon/unit_00292e60.cpp

struct Ev2ad { u8 p0[4]; u8 done; u8 p5[3]; u16 id; };
Ev2ad* func_001a82b0(Ev2ad*);

s32 func_002a4390(Ev2ad*);
extern s32 D_0035f628;
extern s32 D_0035f62c;
extern u8* D_0035f620;
// counts unlocked entries and marks the ones that pass in the bitmask
void func_002ad9f8(void);  // 0x002ad9f8: definition moved into src/anon/unit_002a99c8.cpp
s32 func_002d5578(u8*);  // is_field340_eq151
void func_00178d28(u8*);
void func_0017f488(u8*, s32, f32, f32);
void func_0017f5e0(u8*, s32, s32, f32, f32);
#define TAIL     func_00178d28(o); \
        if (*(u8**)(o + 3096)) { f32 z = 0.0f; \
            func_0017f488(*(u8**)(o + 3096) + 320, 151, z, z); \
            func_0017f5e0(*(u8**)(o + 3096) + 320, 0, 0, z, z); }
void func_002d54a8(u8* o);  // 0x002d54a8: definition moved into src/anon/unit_002d4548.cpp
struct Buf302 { u8* base; s32 size; };
struct File302 {
    u8* p; s32 r; s32 w; s16 flags; s16 file; Buf302 bf; s32 lbfsize;
    u8 p28[20]; Buf302 ub; u8 p56[12]; Buf302 lb; u8 p76[8]; void* data;
};
struct Glue302 { Glue302* next; s32 niobs; File302* iobs; };
struct Ctx302 { s32 err; u8 p4[52]; s32 inited; u8 p60[412]; Glue302 glue; };
void func_00302e10(Ctx302*);
Glue302* func_00302c88(Ctx302*, s32);
// newlib __sfp: find (or make room for) a free FILE slot
File302* __sfp(Ctx302* d) {
    File302* fp;
    s32 n;
    Glue302* g;
    if (!d->inited) func_00302e10(d);
    for (g = &d->glue;; g = g->next) {
        for (fp = g->iobs, n = g->niobs; --n >= 0; fp++)
            if (fp->flags == 0) goto found;
        if (g->next == 0 && (g->next = func_00302c88(d, 4)) == 0) break;
    }
    d->err = 12;
    return 0;
found:
    fp->flags = 1;
    fp->p = 0;
    fp->w = 0;
    fp->r = 0;
    fp->bf.base = 0;
    fp->bf.size = 0;
    fp->lbfsize = 0;
    fp->file = -1;
    fp->ub.base = 0;
    fp->ub.size = 0;
    fp->lb.base = 0;
    fp->lb.size = 0;
    fp->data = d;
    return fp;
}


}

// VU0 helpers
static inline void vu_scale(void* v, f32 s) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(v), "f"(s) : "$8", "memory");
}
static inline f32 vu_len(void* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2 $8, $vi22\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
static inline void vu_scale_to(void* d, const void* s, f32 k) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(d), "r"(s), "f"(k) : "$8", "memory");
}
static inline void vu_zero(void* d) {
    asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(d) : "memory");
}
static inline void vu_mulmv(void* out, const void* m, const void* v) {
    asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)"
                 : : "r"(out), "r"(m), "r"(v) : "memory");
}
static inline f32 vu_normalize(void* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\t"
                 "vsqrt Q, $vf2x\n\tvwaitq\n\tcfc2 $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\t"
                 "vdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline void vu_mcopy(f32 (*d)[4], const u8* s) {
    asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                 : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory");
}
static inline void vu_qcopy(f32* d, const f32* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
static inline void vu_unit(f32* d) {
    asm volatile("sqc2 $vf0, 0(%0)" : : "r"(d) : "memory");
}
// inverse of a rigid (rotation + translation) matrix
static inline void vu_minv(f32 (*d)[4], f32 (*s)[4]) {
    asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%1)\n\t"
                 "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
                 "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
                 "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
                 "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\t"
                 "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)"
                 : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
}
static inline void vu_sub_to(void* d, const void* a, const void* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline f32 vu_dot(const void* a, const void* b) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(a), "r"(b) : "$8", "memory");
    return r;
}

// position trail: records a new point once it moved 45 units from the last one
struct Trail10b { u8 moved; u8 changed; u8 p2[2]; s32 cur; u8 p8[8]; Vec4 pts[32]; };
u8 wtarget_0010b468(u32 a0, u32 a1, u32, u32);  // 0x0010b468: definition moved into src/anon/unit_0010b450.cpp

extern "C" {

// inverse(M) * M.translation, negated
// 00107388: moved to src/naka/libkn/camera.cpp

struct Obj180 { u8 p0[8]; void* f8; u8 p12[396]; u16 ids[16]; s32 n; };
struct It180 { u8 p0[16]; u32 flags; u8 p20[12]; };
static inline u32 it180_on(It180* e) { return e->flags & 1; }
s32 func_0011c230(It180*);
u16 func_0011c228(It180*);
void func_0016c698(void*, u16, It180*);
// 00180a10: moved to src/anon/unit_00180408.cpp

extern u8* D_00352130;
u32 func_0019fdb0(u8*);
void func_001a2a18(u8*);
// 001a2910: moved to src/anon/unit_001a28f8.cpp

// transforms a point into the volume's space and tests it against the ellipse/height bounds
s32 func_001db368(u8* o, const Vec4* in) {
    Vec4 v;
    Vec4 t;
    f32 one;
    s32 r;
    v = *in;
    one = 1.0f;
    v.w = one;
    vu_mulmv(&t, o + 16, &v);
    v = t;
    r = 0;
    if (!(v.y < -*(f32*)(o + 84)) && !(*(f32*)(o + 84) < v.y)) {
        r = 1;
        v.x = v.x / *(f32*)(o + 80);
        v.z = v.z / *(f32*)(o + 88);
        if (!(v.x * v.x + v.z * v.z <= one)) r = 0;
    }
    return r;
}

f32 func_002f8b30(f32, f32);
static inline u32 pos186(f32 f) { return 0.0f < f; }
// decaying knockback velocity
// 00186b90: moved to src/anon/unit_00185d10.cpp
Vec4* func_00186b90(Vec4* out, u8* o);

void func_0017c400(u8*, s32);
// launches along a direction: flattened, normalised, with the given speed and height
// 001b2210: moved to src/anon/unit_001b1d20.cpp

}
