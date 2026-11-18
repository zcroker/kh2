#include "../common/types.h"
#include <stdarg.h>

// 128-bit copies (lq/sq) are hand-written asm in the original.
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
// Same, but in a noreorder region so gas doesn't move the sq into a following branch delay slot.
#define QCOPYN(d, s) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(d), "r"(s) : "$8", "memory")

struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));

struct HeapE;
void* operator new[](unsigned int, HeapE*) asm("func_001063f0");

extern "C" {

struct Rec20 { u32 w[5]; };
u32 func_0010f8c0(u32 a0);  // test_field2940_bit2
void func_0010f880(f32 a0, f32 a1, u32 a2);
u32 func_0010f8e0(u32 a0);  // get_bit3_of_field2940
f32 func_0010f8a8(u32 a0);  // get_float_3284
u32 func_0010ef48(u32 a0);
u32 func_0010f9e0(u32 a0, u32 a1);
u32 func_0010cc80(u32 a0);
u8* func_0010cc70(u32 a0);
void func_0016b010(u32, Vec4*);  // obj_set_float1644_from_pair
void func_0016af58(Vec4*, u8*);
void func_0010f9f0(u32, Vec4*, s32);

u8 func_00113848(u32 param_1, u32 param_2, Rec20* param_3, u32* param_4, u8 param_5);  // 0x00113848: definition moved into src/anon/unit_00113628.cpp

typedef s32 (*Fn5)(void*, void*, u32, void*, u32, u32, u8, u32);
struct Obj5 { void** vt; };
s32 func_00132338(u8*);  // get_field8
void func_00132cb8(u8*);
u8* func_00132350(u8*);
s32 func_0011c8f8(u8* p, u8* a1, u8 flag, Obj5* o, u32 a4, u32 a5);  // 0x0011c8f8: definition moved into src/anon/unit_0011c128.cpp

struct V4f { f32 x, y, z, w; };
// 00144be0: eight corners of the box min(0,1,2)/max(3,4,5), y and z negated
void func_00144be0(f32* b, V4f* v);  // 0x00144be0: definition moved into src/anon/unit_00144450.cpp

void func_00158050(u8*, s32, u32, u32, s32, s32, u32);
void func_00139598(u8*);
// 00156880: moved to src/anon/unit_00153ea0.cpp
void func_00156880(u8* p, u32 a1, u32 a2, u32 a3);

u8* func_00177860(u8*);
void func_00176970(u8*);
void func_00177a28(u8*);  // set_bytes_2820_2821
u8* func_00176fb0(u8*, s32);
s32 func_001a0920(u8*, u8*);
void func_00177008(u8*, u8*, u32);
// 00176868: moved to src/yasui/libys/party.cpp

s32 func_00179c80(u8*);
void func_001dc818(u32);
u32* func_0015ef28(void);
s32 func_001de2e0(u32*, u64);
u32 func_001de168(u32*, s32, s32, s32, s32, s32);  // scan_list_by_half
Vec4* func_001dc5f8(u32);
Vec4* func_0016c028(u8*);  // obj_get_attach_or_alt
Vec4* func_001dc648(u32);
void func_0016af58(Vec4*, u8*);
void func_0017d050(Vec4*, Vec4*);
// 00179cb8: moved to src/yasui/libys/player.cpp

extern f32 D_00349e10;
f32 fabsf(f32);  // fabsf
// VU0 helpers (hand-written asm in the original)
static inline void vu_Scale11(Vec4* s, Vec4* d, f32 f)
{
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
                 : : "r"(s), "r"(d), "f"(f) : "$8", "memory");
}
static inline void vu_Interp11(Vec4* a, Vec4* b, Vec4* d, f32 t)
{
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\t"
                 "vaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\t"
                 "vmulax.xyzw ACC, $vf2, $vf3x\n\tvmaddx.xyzw $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(a), "r"(b), "r"(d), "f"(t) : "$8", "memory");
}
static inline void vu_Copy11(Vec4* d, Vec4* s)
{
    if (d != s) QCOPYN(d, s);
}
struct Obj11 { u8 pad[16]; Vec4 dir; Vec4 pos; };
// 00184540: moved to src/anon/unit_00183088.cpp

struct Ray12 { Vec4 a, b, c, hit; u8 pad[48]; u64 on:1; u64 mode:2; u64 rest:29; u64 hitflag:1; u64 rest2:31; u8 pad2[24]; };
void func_00319e90(Ray12*, void*);
Vec4* func_0016c028(u8*);  // obj_get_attach_or_alt
void func_00143928(Ray12*);
static inline void Copy12(Vec4* d, Vec4* s)
{
    if (d != s) QCOPY(d, s);
}
// 00185138: moved to src/anon/unit_00183088.cpp

struct B32 { f32 a, y, c; u32 d; Vec4 pos; };
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
void func_0018a818(B32*, u8*, u32);
s32 func_001a7610(Vec4*, VecD*, s32, f32, f32);
struct VA14;
void func_00193be8(u8*, VA14*, void*, u32);
extern u8 D_01c61ae0[];
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
void func_00193d38(u8* p, u32 a1);  // 0x00193d38: definition moved into src/anon/unit_00193be8.cpp

struct Def15 {
    u8 pad; u8 mode; u16 b0:4; u16 snd:1; u16 alt:1;
    bool Snd() { return snd; }
    bool Alt() { return alt; }
};
struct Obj15 { u8 pad[60]; Def15* def; u8 pad2[80]; f32 vol; };
u32 func_0014abe8(void);  // get_data_3595a0
u32 func_0014abf8(void);  // get_data_3596b0
u32 func_0014aba8(void);
void func_0014aa58(u32, s32, s32);
void func_0014aa80(u32, s32, s32);
void func_0013f160(void);
void func_00196e88(Obj15*, s32, s32, f32);
void func_00197430(Obj15* p);  // 0x00197430: definition moved into src/anon/unit_00195d00.cpp

extern s8 D_0036d0c8[];
extern u8* D_0034e948;
void wtarget_00198970(u8*) asm("_Z16wtarget_00198970jjjj");
u8* func_00168b88(u32, s32, u32, s32);  // find_entry16_by_half_word
void func_001bdb70(u8*, s32, u32, u32, u8*);
void func_0019d720(u8*);
#define ID4(s) ((s)[0] | ((s)[1] << 8) | ((s)[2] << 16) | ((s)[3] << 24))
void set_special_command(u8* self, s32 cmd) asm("_ZN2YS6STDOBJ19set_special_commandEi");
// command: moved to src/anon/unit_00197fe0.cpp

extern u8 D_00350ca8[];
extern u8 D_00350ca0[];
extern s32 D_00350c88;
u8* func_001ae460(u32);
s32 func_001ae010(u32);
s32 func_002f79c8(s32);
s32 func_002f7be8(u32, u32, u32, u8*);
void func_001ae620(void);
void func_001ae650(void);
void func_001ae678(void);  // to_306698_arg10
s32 func_002f7dc8(void);
u32 func_001ae0a0(u32 a0, u32 a1, u32 a2, u16 a3);  // 0x001ae0a0: definition moved into src/anon/unit_001ada38.cpp

struct Q18 { u32 bits[8]; u8 queue[255]; u8 count; };
extern Q18 D_0032fb68;
s32 func_001b8958(s32);
u8* func_001b8800(s32);
s32 func_00181550(void);
void func_001b8838(s32 code);  // 0x001b8838: definition moved into src/anon/unit_001b87a0.cpp

extern f32 D_00349e14;
void func_0023aab8(u8*);
void func_00237ae8_x421(u8*) asm("func_00237ae8");
void func_0023acd8(u8* p);  // 0x0023acd8: definition moved into src/anon/unit_00239988.cpp

struct Opt28 { u8 pad[8]; u8 text[8]; s8 def; u8 pad2; u16 id; u8 pad3[16]; };
extern Opt28 D_00372298[];
extern u32 D_0035edd0;
extern u32 D_0035edd4;
extern u32 D_0035edec;
void func_00288d80(u32, s32, s32, s32, u32, u16, Opt28*, u8*);
u8* func_002891b8(u32, s32);
u32 func_0023aa78(u8*);
u32 func_0023aa98(u8*);
void func_00288e08(u32, s32, u32, s32);
u32 func_0028dd90(u32);  // mod10_classify_012
u32 func_0028ddd8(u32);
void func_001395f8(u8*);
void func_002891f0(u32, s32, s32, s32, s32);
void func_002b4388(u32, Opt28*, s32);
void func_0024d348(void);  // 0x0024d348: definition moved into src/anon/unit_0024cda8.cpp

struct Sub30 { u8 pad[184]; u32 flags; void SetF() { flags |= 8; } };
struct Obj30 { u8 pad[24]; Sub30 sub; u8 pad2[405 - 24 - 188]; u8 on; u8 pad3[26]; void SetOn() { on = 1; } };
extern Obj30* D_0035ee70;
extern u32 D_0035ee60;
extern u8 D_00372608[];
extern u8 D_00372610[][8];
u8* func_001058e8(void);
s32 func_00252098(s32);
void func_0028b300(Obj30*, s32, s32, s32, u32, u8*, u8*, s32, s32);
void func_00252208(void);  // 0x00252208: definition moved into src/anon/unit_00250fb8.cpp

f32 func_002f8a18(f32);
f32 fabsf(f32);  // fabsf
// 002d1bf8: clamp v (relative to the camera at +208) inside the view frustum, with margins lo/hi
void func_002d1bf8(u8* cam, Vec4* v, f32* hi, f32* lo);  // 0x002d1bf8: definition moved into src/anon/unit_002cf260.cpp

struct VB36 {
    f32 x, y, z, w;
    VB36& operator=(const VB36& s) { if (this != &s) QCOPY(this, &s); return *this; }
    VB36 operator-(const Vec4& b) const
    {
        VB36 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                     : : "r"(this), "r"(&b), "r"(&r) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct B36 { f32 a, rad, c; u32 d; VB36 pos; };
struct It36 { u32 cur; u8 pad[28]; };
void func_00190128(It36*);
u8* func_0016bba8(u8*, s32, u8*);
void func_00190878(It36*, u8*, u8);
void func_002e9fe0(It36* it, u8* obj, Vec4* pos);  // 002e9fe0: moved to src/anon/unit_002e9a00.cpp

// fdlibm __kernel_cosf
f32 __kernel_cosf(f32 x, f32 y);  // 0x002faaf0: definition moved into src/newlib/libm/kf_cos.c

struct Cam1 {
    u8 pad[1584];
    u32 on : 1;
    u32 rest : 31;
    u8 pad2[12];
    f32 ax, ay, pad3[2];
    f32 bx, by;
    bool On() { return on; }
};
// 00116798: keep the two (x, y) pairs inside their wrap ranges
void func_00116798(Cam1* p);  // 0x00116798: definition moved into src/anon/unit_00114a90.cpp

struct Anm3 { u8 pad[276]; s32 cur; };
struct Obj3 {
    void** vt;
    u8 pad[8];
    u32 flags;
    u8 pad2[8];
    Anm3 anm;
    u8 pad3[384 - 24 - 280];
    f32 speed;
    u8 pad4[4];
    s32 next;
    void* wait0;
    void* wait1;
    u8 dirty;
};
s32 func_00139d78(void*);
s32 func_00239d10(void*);
void func_00239eb8(Anm3*, f32);
s32 func_00239d30(Anm3*, s32);
void func_00138c10(Obj3*, s32);
void func_00139570(Obj3*);
static inline void Idle3(Obj3* p)
{
    if (p->flags & 0x80) func_00139570(p);
    else ((void (*)(Obj3*))p->vt[5])(p);
}
void func_00138840(Obj3* p) asm("_Z13func_00138840Pv");
void func_00138840(Obj3* p);  // 0x00138840: definition moved into src/anon/unit_00138480.cpp

extern u32 D_00347fec;
extern s32 D_00347ff0;
extern char D_003b8ba0[];
extern char D_0036acb0[];
extern char D_0036acd0[];
extern char* D_0033caf4;
extern u8 D_0032bae0;
extern u8 D_004193c0[];
s32 func_00242ea8(void);
s32 func_0014a1f0(void);
s32 func_00242c70(void);
s32 func_00194a08(void);
u32 func_00105ee8(u32);
void func_002fee78(char*, const char*, ...);
void strlen(char*);  // strlen
void func_001688c8(char*);
void func_001684c0(char*, u8*, s32, s32);
// 0013a4c8: moved to src/harata/libdk/field2dd.cpp

extern u32 D_00348470[][3];
extern u32 D_00348440[][3];
u32 func_0013b808(u32, u32);  // entry168_by_index
struct Fl6 { u16 on : 1; u16 rest : 15; u8 On() { return on; } };
void func_0013c080(u32 a0, Fl6* fl, u32 a2, s32 col, u8* changed, s32 row, u32* outA, u32* outB);  // 0x0013c080: definition moved into src/anon/unit_0013a8b8.cpp

extern f32 D_00349e14;
void func_0014fcd8(u8*);
s32 func_00139538(u8*);
void func_00139510(u8*);
void func_0014b950(u8*, s32, s16, u32, s32);
void func_00138c40(u8*, s32, s32);
u32 func_0023aa98(u8*);
void func_00150b68(u8*);
struct NoTail7 { ~NoTail7() {} };
struct Fl7 { u32 busy : 1; u32 alt : 1; u32 rest : 30; };
struct Obj7 { u8 pad[972]; Fl7 fl; };
void func_00150a18(u8* p);  // 0x00150a18: definition moved into src/anon/unit_0014ecb8.cpp

extern f32 D_00349e10;
extern u8* D_00352130;
void func_00175af8(u8*);
void func_00179718(u8*);
s32 func_00197920(void);
s32 func_001917c0(void);
void func_001a1b68(u8*, f32);
void func_00179cb8(u8*);
s32 func_001b9d40(u8*);  // vtable_call_slot64_flags
void func_00178220(u8*);
void func_0017a3b0(u8*);
// 00178758: moved to src/yasui/libys/player.cpp

struct Ent13 { u32 key; union { s32 v; u16 sub; }; u32 a, b; };
struct Tbl13 { s32 n; Ent13 e[1]; };
u32 func_001ae210(u32);
u16 func_001ae270(u32);
Ent13* func_001ae308(Tbl13* t, u32 name);  // 0x001ae308: definition moved into src/anon/unit_001ada38.cpp

extern u8 D_003511c2;
extern u8 D_003511c0;
struct Pkt15 { u64* start; u32 pad; u8* cur; };
s32 func_001b7fd0(Pkt15*);
u32 func_002f35e8(s32);
void func_002f3918(u32, u64*);
void func_003058a0(s32);
void sceGsSyncPath(s32, s32);
static inline u64 Tag15(s32 qwc, s32 irq)
{
    return (s64)qwc | (u64)(s64)irq << 63 | 0x70000000;
}
void func_001b80d8(Pkt15* p);  // 0x001b80d8: definition moved into src/anon/unit_001b6a50.cpp

extern u32 D_00351d98;
extern f32 D_0036dff0[];
extern f32 D_0036e030[];
extern u8 D_0036e000[][16];
void func_001a5420(u32, u8*, u32);
// 0x1c7d90: moved to src/anon/unit_001c7bc8.cpp

struct VB18 {
    f32 x, y, z, w;
    VB18& operator=(const VB18& s) { if (this != &s) QCOPY(this, &s); return *this; }
    VB18 operator-(const Vec4& b) const
    {
        VB18 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                     : : "r"(this), "r"(&b), "r"(&r) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct It18 { u8 d[80]; };
struct Pt18 { u8 pad[64]; VB18 rel; u32 pad2; void* fn; u8* owner; };
Vec4* func_0016c028(u8*);  // obj_get_attach_or_alt
void func_001c2858(It18*, Vec4*, u32, u32);  // copy_2quads_and_ratio
s32 func_001c28f8(It18*, VB18*, s32);
Pt18* func_001db888(u8*, s32, void*);  // record_index_calc
void func_001dbc58(Pt18*, u8*, VB18*, u32);
void func_001ce618();
// 001ce508: moved to src/anon/unit_001cd660.cpp
void func_001ce508(u8* p, u32 a1, u32 a2);

extern u8 D_01d5baa0[5];
extern u32 D_003638d0;
s32 func_001d9af8(void);
u64 func_00312db8(u64, u64);
s32 func_001d9c68(u8*);
void func_001d9ad8(s32);
bool func_001d9b40(void);  // 0x001d9b40: definition moved into src/anon/unit_001d7458.cpp

extern f32 D_00354be0[3];
extern u8 D_01d9e730[];
extern u8 D_01d9e8c0[];
void sceVu0UnitMatrix(f32 (*)[4]);  // vu_store_w_splat
void sceVu0RotMatrixZ(f32 (*)[4], f32 (*)[4], f32);
void sceVu0CopyVector(f32*, u8*);  // memcpy16
void sceVu0ApplyMatrix(f32*, u8*, f32*);
void sceVu0MulMatrix(f32 (*)[4], u8*, f32 (*)[4]);
f32 func_0020aec8(u32 a0, f32 (*m)[4], u8* a2, u32 a3, u8* s);  // 0x0020aec8: definition moved into src/anon/unit_0020ad28.cpp

extern u8 D_0035eaf8[];
void func_00237068(void*);
struct Obj20 {
    void* vt;
    u8 base[172];
    u32 f176, f180;
    u32 b0 : 1, b1 : 1, b2 : 1, b3 : 1, b4 : 1, b5 : 1, b6 : 1, b7 : 1, b8 : 1, b9 : 1, b10 : 1, b11 : 1, b12 : 1, b13 : 1, rest : 18;
    u8 f188;
    u32 f192, f196, f200, f204, f208;
    u8 f212;
    u32 f216, f220, f224, f228, f232, f236, f240, f244, f248, f252, f256, f260, f264, f268, f272, f276, f280, f284, f288;
    u32 f292, f296, f300, f304, f308, f312, f316, f320, f324, f328, f332;
};
// 002395b8: constructor (base init, then clear all state)
void func_002395b8(Obj20* p);  // 0x002395b8: definition moved into src/anon/unit_002384f8.cpp

struct Snd23 {
    u8 pad[24];
    u32 bank;
    u32 voice;
    u32 f32_;
    s32 f36;
    u8 pad2[4];
    s16 ids[3];
    s16 sel[3];
    s16 cur;
    u8 pad3[2];
    u32 color;
    s32 len;
    u32 f68;
};
void func_001391c8(Snd23*, u32, u32);
void func_0023f778(Snd23*, u32);  // copy_3halfwords_44
void func_0023f7a8(Snd23*, u32);  // copy_3halfwords_50
u8* func_0023f1b0(u32);
u32 func_0023c3e0(u8*, s16, s32);
void func_0023f5b8(Snd23*, u32, u32);
s32 func_0023aa58(u32);
void func_0023f6c0(Snd23*, s32);
void func_0023f688(Snd23*, s32);
void func_0023f740(Snd23*, u32);
void func_001395e8(Snd23*);
void func_00139610(Snd23*);
void func_00139638(Snd23*);
void func_0023f1e0(Snd23* p, u32 a1, u32 bank, u32 a3, u32 t0, u32 t1, u32 t2, u32 t3);  // 0x0023f1e0: definition moved into src/anon/unit_0023e5d0.cpp

extern Opt28 D_00372548[];
extern u32 D_0035ee38;
extern u32 D_0035ee3c;
extern u32 D_0035ee4c;
void func_00288d80(u32, s32, s32, s32, u32, u16, Opt28*, u8*);
u8* func_002891b8(u32, s32);
u32 func_0023aa78(u8*);
u32 func_0023aa98(u8*);
void func_00288e08(u32, s32, u32, s32);
u32 func_0028dd90(u32);  // mod10_classify_012
u32 func_0028ddd8(u32);
void func_001395f8(u8*);
void func_002891f0(u32, s32, s32, s32, s32);
void func_002b4388(u32, Opt28*, s32);
void func_0024fbd0(void);  // 0x0024fbd0: definition moved into src/anon/unit_0024fbd0.cpp

extern u32 D_0035eea4;
extern s16 D_0035eea0;
extern s16* D_0035ee9c;
extern u8* D_0035eea8;
s16 func_0023f0c0(u32);
s32 func_00139d78(void*);
struct Obj3;
void func_00138c10(Obj3*, s32);
void func_0028d980(u8*, s32, s32, s32, u32, s32, s32, s32, s32);
u32 func_0023aa98(u8*);
u32 func_0028dd90(u32);  // mod10_classify_012
s32 func_00192048(s32);
void func_00252e50(void);  // 0x00252e50: definition moved into src/anon/unit_00250fb8.cpp

extern u8* D_0035f0f4;
extern u32 D_0035ef68;
extern u32 D_0035ef64;
extern u32 D_0035f03c;
s32 func_00139d78(void*);
u32 func_00256b68(s32);
s32 func_00287bc0(void);
s32 func_0028d008(u32);
void func_0028d8c0(u8*, s32, u32, u32, u32, s32, s32, s32);
void func_0028dcc0(u8*, u32);
u8* func_0028d0e0(u32);
void func_00138c78(u32, u32*, u32*);
void func_00138c68(u8*, u32, u32);
void func_00139510(u8*);
void func_0026d620(u32 w, u8 sync);  // 0x0026d620: definition moved into src/anon/unit_0026c450.cpp

extern u8* D_0035f5bc;
s32 func_00287bc0(void);
void func_00274ac8(void);
void func_0028f7e8(s32);
void func_0029ac00(void);
u8* func_00287dc0(void);
s32 func_00139d78(void*);
void func_0023d820(u8*);
void func_0029e9d0(void);
void func_0029aac0(s32 k);  // 0x0029aac0: definition moved into src/anon/unit_00299920.cpp

struct VB30 {
    f32 x, y, z, w;
    VB30& operator=(const VB30& s) { if (this != &s) QCOPY(this, &s); return *this; }
    VB30 operator-(const VB30& b) const
    {
        VB30 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                     : : "r"(this), "r"(&b), "r"(&r) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
union UD30 { u32 u; u8* p; VB30* v; };
struct B30 { f32 a, rad, c; UD30 d; VB30 pos; };
void func_0018a818(B32*, u8*, u32);
s32 func_0019ba60(u8*);
u8* func_0016bba8(u8*, s32, u8*);
struct Find30 { s32 idx; VB30* target; };
void func_002e7d20(Find30* f);  // 0x002e7d20: definition moved into src/anon/unit_002e7b10.cpp

union UD16 { u32 u; f32 f; };
struct B16 { f32 a, y, c; UD16 d; f32 pos[4]; };
struct Fx16 { f32 t; u32 id; u8 pad[8]; u32 target; };
extern f32 D_00349e10;
void func_001ba340_x1290(Fx16*) asm("func_001ba340");
u8* func_001a80c8(u32);  // table24_find_by_id
void func_001ba528(Fx16*, u16, u32);
void func_001ba598(Fx16*);
u8* func_00176b20(s32);
s32 func_0019ba60(u8*);
u32 func_0016a070(u8*);
// 001ba408: moved to src/yasui/libys/itemeffect.cpp

struct Task2 { s32 state; u8 pad[36]; u32 flags; u8 pad2[12]; Task2* next; };
struct Mgr2 { u8 pad[8]; Task2* head; u8 pad2[4]; Task2* cur; u8 pad3[252]; Task2* it; };
union UT2 { Task2* p; u8 c; };
extern UT2 D_0032b940;
void func_00102350_x1325(Task2*) asm("func_00102350");
void func_001025f8(Mgr2*, Task2*);
static inline Task2* Next2(Mgr2* m, Task2* t, u32 mask, u32 val)
{
    do {
        t = !t ? m->head : t->next;
    } while (t && (t->flags & mask) != val);
    return t;
}
void wtarget_001028b0(Mgr2* m, u32 mask, u32 val) asm("_Z16wtarget_001028b0jjjj");
// 001028b0: moved to src/global/unit_001022c0.cpp

struct VObj5 { void** vt; };
struct Snd5 { u32 a; VObj5* dev; u8 pad[128]; u32 h; };
extern void* D_00348814;
extern void* D_00348810;
extern void* D_0034880c;
extern void* D_00348808;
extern Snd5* D_00348818;
extern void* D_00348804;
extern u8* D_00348800;
void func_0014eda8(void);
void func_001537f8(void);
void func_00106420(void*);
void func_00145ab8(u8*);
void func_00142f50(void);  // 0x00142f50: definition moved into src/anon/unit_00142c90.cpp

struct Node6 { u8 pad[236]; Node6* sib; Node6* child; u8 pad2[4]; u32 flags; u8 pad3[28]; s16 h280; s16 h282; };
struct St6 { u32 f; u32 pad; };
struct Tree6 { u8 pad[17252]; St6 st[511]; u8 pad2[21344 - 17252 - 4088]; s32 cur; };
s32 func_00146ed8(Tree6*, Node6*);
void func_00147140(Tree6*, Node6*);
void func_00146e28(Tree6*, Node6*);
void wtarget_00146f28(Tree6* t, Node6* n, u8 flag) asm("_Z16wtarget_00146f28jjjj");
static inline __attribute__((always_inline)) u32* StP6(Tree6* t, s32 i) { return &t->st[i].f; }
#define ST6(t) (*StP6((t), (t)->cur))
void wtarget_00146f28(Tree6* t, Node6* n, u8 flag);  // 0x00146f28: definition moved into src/anon/unit_00145600.cpp

struct Pg7 { u8 pad[15552]; s32 total; s32 count; s32 last; u8 pad2[4]; s32 page; s32 n0; s32 n1; s32 n2; u8 pad3; u8 one; };
void func_00139948(s32);
s32 func_00154910(Pg7*);
s32 func_00154930(Pg7*);
void func_00139598(u8*);
void func_001544b0(Pg7*);
void func_001547e0(Pg7*, s32, s32);
void func_001548a8(Pg7*, s32);
// 00154950: moved to src/anon/unit_00153ea0.cpp
void func_00154950(Pg7* p);

struct Sub4 { u8 pad[396]; void* owner; s32 f400; };
extern f32 D_00349e14;
void func_00139598(u8*);
s32 func_001b1fc8(s32);
u32 func_001b1ff0(s32);
u32 func_001b1e70(void);
void func_00138650(u8*, s32, u32, s32);
void func_001386e0(Sub4*, s32, u32, u8*, s32, s32);
void func_00236410(u8*, s32);  // obj_set4_then_call
void func_00236428(u8*, s32);  // obj_set32_then_call
void func_002367c8(u8*);  // obj_dispatch_bitfield64
void func_001396b0(Sub4*);
void func_0031a260(Sub4*, s32);
void func_002ba2e8(s32, s32);
void func_001395a8(u8*);
void func_00138840__43679(u8*) asm("func_00138840");
void func_001376b8(u8* p);  // 0x001376b8: definition moved into src/anon/unit_001374c8.cpp

typedef unsigned int u128 __attribute__((mode(TI)));
struct Mtx5 { u128 r[4]; };
struct Hdr5 { u8 pad[24]; u32 o24, n28, o32, n36, o40, n44, o48, n52, o56, n60, o64, n68, o72, n76; };
struct Mdl5 {
    u32 h;
    u32 p4, p8, p12, p16, p20, p24, p28;
    u32 n32, n36, n40, n44, n48, n52, n56, f60, f64, f68;
    u8 pad[136];
    u8 b208, b209, b210, b211;
    u32 f212, f216, f220;
};
void func_00141850(Mdl5*, u32);
void func_0011b6a8(Mtx5*);
void func_00142940(Mdl5*, Mtx5*);
void func_00141808(Mdl5*);
void func_001415e8(Mdl5* m, u32 hp, u32 a2);  // 0x001415e8: definition moved into src/anon/unit_00141458.cpp

struct VB6 {
    f32 x, y, z, w;
    VB6() {}
    VB6(const VB6& s) { QCOPY(this, &s); }
    VB6& operator=(const VB6& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
struct Tri6 { VB6 v[2]; };
struct Face6 { u8 pad[10]; u16 n; u8 pad2[4]; };
struct Mesh6 { u8 pad[12]; Face6* faces; u8 pad2[8]; VB6* norms; u8 pad3[32]; u16* list; };
void func_00141988(Mesh6*, Face6*, Tri6*);  // collect_entry_ptrs_by_halves
s32 func_001628d8(VB6*, Tri6*, VB6*, VB6*);
// squared distance |b - a| (VU0, hand-written)
static inline f32 Dist2_6(const VB6& b, const VB6& a)
{
    f32 r;
    asm volatile("lqc2 $vf6, 0(%1)\n\tlqc2 $vf4, 0(%2)\n\tvsub.xyzw $vf5, $vf6, $vf4\n\tvmove.xyzw $vf4, $vf5\n\tvmul.xyz $vf5, $vf4, $vf5\n\t"
                 "vaddy.x $vf5, $vf5, $vf5y\n\tvaddz.x $vf5, $vf5, $vf5z\n\tqmfc2 $2, $vf5\n\tmtc1 $2, %0"
                 : "=f"(r) : "r"(&b), "r"(&a) : "$2", "memory");
    return r;
}
u32 func_00141e78(Mesh6* m, VB6* ray, s32 n, VB6* out);  // 0x00141e78: definition moved into src/anon/unit_00141458.cpp

extern u8 D_0034e958[];
extern u8 D_01c5f530[];
extern u32 D_0034e948__48451 asm("D_0034e948");
void func_00175670(u8*, u32, s32, u32);
s32 func_0016a070__48451(u8*) asm("func_0016a070");
u8* func_001a15d0(s32, s32);
s32 func_001818a0(void);
u32 func_0016f6a0(u32, s32);
void func_00176168(u8*, u32, s32);
void func_001781a8(u8*);
static inline bool HasSub7(s32 k)
{
    return k != 0 && k < 7;
}
// 00177dc8: moved to src/yasui/libys/player.cpp

struct Kind9 { u8 pad[4]; u8 k; };
struct Obj9 { u8 pad[12]; u8* owner; u8 pad2[24]; Kind9* kind; u8 team; };
struct Ent9 { Obj9* obj; u8 pad[12]; u8 sub[32]; };
struct List9 { s32 n; u8 pad[12]; Ent9 e[1]; };
extern u8 D_0036cce0[][7];
s32 func_001c0298(u8*, Obj9*);  // state_check5or6
s32 func_0018a550(u8*, u8*);  // state_dispatch_0_1_3
s32 func_0018e698(Ent9*, Ent9*);
void func_0018ea40(Ent9*, Ent9*);
void func_0018e7c0(Ent9*, Ent9*);
void func_0018eb98(List9* l, Ent9* q);  // 0x0018eb98: definition moved into src/anon/unit_0018d050.cpp

struct Mask11 { u32 on, set, off; u32 Get() { return (on | set) & ~off; } };
struct Hit11 { u8 pad[24]; u32 flags; u32 src; u32* def; };
struct Chr11 { void** vt; };
s32 func_001b58a8(void);
s32 func_0018cdd0(Hit11*);
void func_001b5ab0(void);
void func_001b3e88(Chr11*, Hit11*);
void func_001b3cb0(Chr11*, u32);
void func_00186d48(Chr11*, Hit11*);
void func_001c20e8(u32, Hit11*, Chr11*);
void func_001883f8(u8*, Hit11*);
void func_0016cce8(u32, s32, Hit11**, s32, s32);
void func_00186148(Chr11*, Hit11*);
void func_001b3d00(Chr11* p, Hit11* h);  // 0x001b3d00: definition moved into src/anon/unit_001b2780.cpp

struct VB13 {
    f32 x, y, z, w;
    VB13() {}
    VB13(const VB13& s) { QCOPY(this, &s); }
    VB13& operator=(const VB13& s) { QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
struct Shk13 { u32 a; f32 b, c; u32 d; VB13 pos; };
s32 func_001b5858(u8*);
u8* func_00168b88(u32, s32, u32, s32);  // find_entry16_by_half_word
u32 func_00198738(u32, s8*);
void func_00185278(u32, u8, f32);
void func_0016af58__52620(VB13*, u32) asm("func_0016af58");
void func_0016b010__52620(u32, VB13*) asm("func_0016b010");
double func_00313b80(f32);  // float_to_double
s32 func_003142e0(double, double);  // double_compare
VB13* func_0016c028__52620(u32) asm("func_0016c028");
void func_00185e78(Shk13*);
u8* func_001050d8(s32);
void func_00196ca8(u8*, s32, u32);
void func_00196e98(u8*, u32);
void func_00196f00(u8*);
#define ID4(s) ((s)[0] | ((s)[1] << 8) | ((s)[2] << 16) | ((s)[3] << 24))
static inline bool Valid13(u8* r) { return r && *(u32*)(r + 8); }
void func_001b50e0(u8* p, s8* id, u8 flag, f32 shake);  // 0x001b50e0: definition moved into src/anon/unit_001b2780.cpp

extern u32 D_01d48cb0;
extern u8 D_00351eb8[];
extern u8 D_00352560[];
extern u8 D_00350e48[];
s32 func_0019ba60(u8*);
void func_0016cab8(u8*);
void func_0016c7d8(u8*);
void func_001dde40(u8*);
void func_001b1c10(u32, f32);
void func_0016c640(s32);
void func_001d4570(u32, u32);
void func_00170950(u32);
s32 func_001b5858(u8*);
s32 func_001b5cb8(u8*);
void func_001c8d98(u8*, s32);
void func_001d1ed0(u8*);
void func_001d2048(u8*);
void func_001b0188(u8*);
void func_001ddd88(u8*);
struct NoTail14 { ~NoTail14() {} };
void func_001b4dd0(u8* p);  // 0x001b4dd0: definition moved into src/anon/unit_001b2780.cpp

struct Ev18 { u32 res; u8 pad[4]; u8* obj; };
struct Sn18 { u8 pad[4]; u16 id; u8 pad2[2]; u16 sy; u8 pad3[4]; s16 kind; s16 sx; u8 arg[2]; };
s32 func_002282f0(u16);
Ev18* func_00227d10(s16);
u8* func_0016f000(u32, Vec4*, f32);
void func_001ba028(u8*);  // list_contains_ptr
void func_00233280(u8*);
u32 func_00232e60(void);
u32 func_00232e18(s16);
u32 func_0022f4f0(u32);
u8* func_00227b00(u32, s32, u8*);
u8* func_00102c18(s32, s32, void (*)());
void func_00227950();
void func_00227a08();
void func_0017f430(u8*, u32, f32, f32);
void func_00232ea0(u32, Sn18*, Ev18*, u8*);
void func_002332a8(Sn18* p);  // 0x002332a8: definition moved into src/anon/unit_00232f08.cpp

// 00177f50: moved to src/yasui/libys/player.cpp

extern s8 D_0035ed69;
extern u8* D_0035ed64;
extern s32 D_0035f3d4;
extern u32 D_0035ed4c;
extern u32 D_0035ed54;
s32 func_00139d78(void*);
s32 func_0028afa8(u32);
u8* func_002891b8(u32, s32);
void func_0028d8c0__58307(u8*, s32, s32, s32, u32, s32, s32, s32) asm("func_0028d8c0");
void func_0028dcc0__58307(u8*, u8*) asm("func_0028dcc0");
void func_00139648(u8*);
u32 func_0023aa18(u8*);
u32 func_0023aa38(u8*);
void func_00138c68(u8*, u32, u32);
void func_002493c8(void);
void func_002491d0(void);  // 0x002491d0: definition moved into src/anon/unit_00247ff0.cpp

extern s8 D_0035edfc;
extern u8* D_0035ede8;
extern s32 D_0035f3d4;
extern u32 D_0035edcc;
extern u32 D_0035edd4;
s32 func_00139d78(void*);
s32 func_0028afa8(u32);
u8* func_002891b8(u32, s32);
void func_0028d8c0__59439(u8*, s32, s32, s32, u32, s32, s32, s32) asm("func_0028d8c0");
void func_0028dcc0__59439(u8*, u8*) asm("func_0028dcc0");
void func_00139648(u8*);
u32 func_0023aa18(u8*);
u32 func_0023aa38(u8*);
void func_00138c68(u8*, u32, u32);
void func_0024e5b0(void);
void func_0024e3a8(void);  // 0x0024e3a8: definition moved into src/anon/unit_0024cda8.cpp

extern u8 D_0035f0b0;
s32 func_00287cd0(void);
u32 func_00240ba0(void);
s32 func_002b4ff8(void);
void func_00287cc0(s32);
s32 func_00287d30(void);
s32 func_00233e70(s32);
s32 func_00234778(void);
void func_002419d0(s32);  // store_global_bool_converted
void func_00234570(u32, s32);
void func_00287d20(s32);
s32 func_002348a8(u32, s32);
u32 func_00234888(u32, s32);  // entry32_word
void func_00240bb0(u32);  // global_store_half2
void func_00241450(s32);
void func_002b5108(s32, u32);
void func_00287bd0(s32, s32);
void func_002400f8(s32);
void func_002b4c88(s32);
s32 func_00288040(void);
void func_00288018(void);  // global_zero_4dwords
void func_0025adf0(void);  // 0x0025adf0: definition moved into src/anon/unit_002588e8.cpp

void func_00281b30(u32);
s32 func_00289358(u32);
void func_00269658(void);
void func_0026a5a0(void);
void func_0026a900(void);
void func_00269a60(void);
u32 func_0028b040(u32);
s32 func_00269508(u32);
u32 func_0028af88(u32);
s32 func_00283ab8(s32);
s32 func_00258068(s32);  // get_global_bit
void func_00256cc0(s32, s32, s32);
void func_0028af18(u32, u32);
void func_0026a238(u32 p, s32 k);  // 0x0026a238: definition moved into src/anon/unit_00269a60.cpp

s32 func_002a9f50(s32);
s32 func_002aa378(s32);
s32 func_002aaab8(s32);
s32 func_002aaf40(s32);
s32 func_002ab368(s32);
s32 func_002ab620(s32);
s32 func_002ab9c8(s32);
s32 func_002abce8(s32);
s32 func_002ac538(s32);
s32 func_002ac800(s32);
s32 func_002aa788(s32, s32);
s32 func_002ac110(s32, s32);
s32 func_002a1b18(s32, s32);
s32 func_002acb20(s32 a);  // 0x002acb20: definition moved into src/anon/unit_002a99c8.cpp

struct Ob31;
extern Ob31* D_0035f634;
s32 func_00139d78(void*);
void func_00139510(u8*);
s32 func_00281be0(void);
void func_00281c50(void);
void func_002b2c80(void);
struct Ob31 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    u8 pad[404];
};
static inline void Kill31(s32 off)
{
    if (func_00139d78((u8*)D_0035f634 + off)) func_00139510((u8*)D_0035f634 + off);
}
void func_002b20b8(void);  // 0x002b20b8: definition moved into src/anon/unit_002b1db8.cpp

struct V33 {
    f32 x, y, z, w;
    V33& operator=(const V33& o) { if (this != &o) QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
V33 func_00163650(const V33*, const V33*, const V33*);
void func_00146788(V33* out, V33* p);  // 0x00146788: definition moved into src/anon/unit_00145600.cpp

struct V34 {
    f32 x, y, z, w;
    V34() {}
    V34& operator=(const V34& o) { if (this != &o) QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct Ent34 { u8 pad[192]; V34 pos; u8 pad2[40]; u32 fl; };
void func_00148638(f32);
void func_00148690(u8*, Ent34*, f32);
// VU0 vector helpers: hand-written macro code in the original.
#define DIST34(r, p, q) { a = p; b = q; r = Dist34(a, b, c); }
static inline f32 Dist34(V34& a, V34& b, V34& c)
{
    asm volatile("lqc2 $vf1,0(%1)\n\tlqc2 $vf2,0(%2)\n\tvsub.wxyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,0(%0)"
                 : : "r"(&c), "r"(&b), "r"(&a) : "memory");
    f32 r;
    asm volatile("lqc2 $vf1,0(%1)\n\tvmul.xyz $vf1,$vf1,$vf1\n\tvaddy.x $vf1,$vf1,$vf1y\n\tvaddz.x $vf1,$vf1,$vf1z\n\t"
                 "vsqrt Q,$vf1x\n\tvwaitq\n\tcfc2.ni $8,$vi22\n\tmtc1 $8,%0"
                 : "=f"(r) : "r"(&c) : "$8", "memory");
    return r;
}
f32 func_00148890(u8* o, Ent34* e, const V34* q);  // 0x00148890: definition moved into src/anon/unit_00147140.cpp

struct Tune37 { u8 pad[96]; f32 f96; f32 f100; u8 pad2[12]; f32 f116; };
extern Tune37* D_00352130__67414 asm("D_00352130");
struct Sub37 { u8 pad[431]; u8 st; u8 pad2[4]; f32 f436; };
struct Arg37 { u8 pad[41]; u8 k; };
u8* func_0017df58(s32);
s32 func_0019ba60(u8*);
void func_0016cce8__67414(u32, s32, u32*, s32, s32) asm("func_0016cce8");
void func_00179a68(u8*, f32);
void func_001a1b68__67414(Sub37*, f32) asm("func_001a1b68");
void func_00177760(u8*, u8*, u32, Arg37*);
// 001798d8: moved to src/yasui/libys/player.cpp

struct V38 {
    f32 x, y, z, w;
    V38() {}
    V38& operator=(const V38& o) { if (this != &o) QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
// VU0 vector helpers: hand-written macro code in the original.
static inline V38 Sub38(const V38& a, const V38& b)
{
    V38 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1,0(%1)\n\tlqc2 $vf2,0(%2)\n\tvsub.wxyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 Len38(const V38& v)
{
    f32 r;
    asm volatile("lqc2 $vf1,0(%1)\n\tvmul.xyz $vf1,$vf1,$vf1\n\tvaddy.x $vf1,$vf1,$vf1y\n\tvaddz.x $vf1,$vf1,$vf1z\n\t"
                 "vsqrt Q,$vf1x\n\tvwaitq\n\tcfc2.ni $8,$vi22\n\tmtc1 $8,%0"
                 : "=f"(r) : "r"(&v) : "$8", "memory");
    return r;
}
struct Hit38 { u8 pad[12]; s32 n; V38 pos; };
struct Node38 { u8 id; u8 pad; u16 fl; };
struct Out38 { u8* e; u32 id; };
void func_00190128__68827(void) asm("func_00190128");
u8* func_00185da8(u8*);
s32 func_0019bc38(u8*);
s32 func_0019bb58(u8*);
Node38* func_0016bba8__68827(u8*, s32, Node38*) asm("func_0016bba8");
void func_0018a818__68827(Hit38*, u8*, Node38*) asm("func_0018a818");
V38* func_0016c028__68827(u32) asm("func_0016c028");
s32 func_00190140(Out38*);
void func_00191218(Out38* out, u32 cam, f32 range);  // 0x00191218: definition moved into src/anon/unit_001900d0.cpp

struct Hdr39 { u8 pad[4]; u16 nb; u16 na; };
struct Ref39 { u8 pad[44]; u16 k; };
struct Item39 { u8 pad[16]; Ref39* r; u8 pad2[16]; s32 cnt; u8 pad3[0]; };
struct It40 { u8 pad[16]; Ref39* r; u8 pad2[16]; s32 cnt; };
struct Ent39 { u8 pad[32]; s32 k; };
struct Obj39 { u32 p0; u32 pad; u32 hh; u8 pad2[28]; u8* p40; };
s32 func_002ceb08(Obj39*);
s32 func_002cebc8(u32);
u8* func_002cf638(u32);
It40* func_002cf8c0(u8*, u32, Obj39*, u8*);
void func_002cf750__39(u32, Obj39*, Ent39*, It40*, It40*) asm("func_002cf750");
void func_0019a308(Obj39* o);  // 0x0019a308: definition moved into src/anon/unit_00199688.cpp

struct Act40 { u8 pad[20]; u8 kind; u8 pad2[19]; u32 fl; u8 pad3[24]; u8 lv; };
extern u8* D_0034e948;
s32 func_001919f8(void);
s32 func_001919d0(void);
void func_001a5380(u8*, u8*, Act40*);
u8* func_00176b20(s32);
s32 func_0019ba60(u8*);
s32 func_001c7950(Act40*, u8*, f32, f32);  // copy_quad_if_flag
static inline bool Is40(u8* e) { return *(s32*)(e + 2896) == 6; }
struct Vec4x { f32 a,b,c,d; } __attribute__((aligned(16)));
struct NoTail40 { Vec4x v; ~NoTail40() {} };
// 001a5140: moved to src/anon/unit_001a4db0.cpp

struct Obj41 { u8 pad[92]; u32 p92; u32 p96; u8 pad2[12]; s32 n112; u8 pad3[2920 - 116]; s32 n2920; };
u32 func_001ab800(void);
void func_00236788(u32);  // to_236830
void func_002367a0(void);
void func_0023bc58(u8*, u32, u32);
void func_0023acd8(u8*);
void func_0023ade0(u8*);
void func_001ac108(u8*, u32, u32, u32, u32);
void func_001ac6d0(Obj41*);
void func_001abf38(u8*, u32, u32);
void func_00239bf8(u8*, s32);
// 001acdc0: moved to src/anon/unit_001abb28.cpp

extern u32 D_003638d0;
struct Ent42 { s8 id; s8 w; };
struct Tab42 { u8 pad[4]; Ent42 e[5]; };
s32 func_001b0148(Tab42*, u32, s32, u32);
static inline u32 Rand42(void) { return D_003638d0 *= 0x10dcd; }
u64 func_00312db8(u64, u64);  // the game's own 64-bit unsigned divide (libgcc __udivdi3)
static inline s32 RandN42(u32 n)
{
    u32 r = Rand42();
    return (s32)func_00312db8((u64)r, func_00312db8((u64)(n - 1) + 0x100000000ULL, n));
}
// func_001affe0: not yet matching (scheduling around the game's 64-bit divide calls); left as asm.

// Entire body is hand-written VU0 macro code in the original.
void func_00224600(void* out, const void* m, const void* v);  // 0x00224600: definition moved into src/anon/unit_00222aa8.cpp

struct Obj48 { u8 pad[4]; s16 id; char name[1]; };
extern char D_00371150[];
extern char D_00371168[];
extern char D_00371170[];
extern u32 D_0033caf0;
extern u8 D_0035e2ec;
s32 func_002282f0__77693(s32) asm("func_002282f0");
s32 func_00225b00(s32);  // flag_query_by_index
u32 func_0014abd8(void);
void func_0014aa58(u32, s32, s32);
void func_0014aa80(u32, s32, s32);
void func_00226ed0(void);
void func_002fee78(char*, const char*, ...);
void func_0022bd80(void);
s32 strncmp(const char*, const char*, s32);
void strlen(char*);  // strlen
s32 func_002ef7a0(s32, char*);
void func_0014a1f0__77693(void) asm("func_0014a1f0");
void func_00102448(u32, s32);
void func_00102c18__77693(s32, s32, void*) asm("func_00102c18");
void func_0022ba88(void);
void func_0022bc08(Obj48* o, u32 w);  // 0022bc08: moved to src/sasa/event_movie.cpp (linked unit)

struct Hdr49 { u8 pad[8]; s32 n0; s32 o0; s32 n1; s32 o1; };
struct Thr49 { u8 pad[48]; void* fn; };
struct Th49 { u32 pad; u32 id; };
union U49 { Hdr49* p; u8 c; };
extern U49 D_0035eb10;
extern s32 D_0035eb20[2];
extern s32 D_0035eb18[2];
extern s32 D_0035eb28;
extern s32 D_0035eb2c;
extern s32 D_0035eb30;
extern s32 D_01dae680;
s32 func_00102c80(void);
Th49* func_00104190(void);
void func_00102180(s32*);
Thr49* func_00102c18__79184(s32, s32, void*) asm("func_00102c18");
Thr49* func_00102788(u32, s32, s32, void*);
void func_0023cf60(void);
void func_0023cdd8(void);
s32 func_0023cde8(Hdr49* h);  // 0x0023cde8: definition moved into src/anon/unit_0023c968.cpp

struct Ob50 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
};
extern Ob50* D_0035f03c__80579 asm("D_0035f03c");
extern Ob50* D_0035f030;
extern u32 D_0035f01c;
extern u32 D_0035f020;
extern u32 D_0035f024;
extern u32 D_0035f050;
extern u32 D_0035f044;
extern u32 D_0035f048;
s32 func_00139d78(void*);
s32 func_0028acc8(u32);
void func_0028abe0(u32);
void func_00254f08(void);
void func_0028f878(void);
void func_0028d620(u32);
void func_00263d28(void);
void func_002579e0(void);
void func_00256c40(void);
void func_00256ea8(void);
void func_0028ff68(u32);
void func_00290488(u32);
void func_00288018(void);  // global_zero_4dwords
void func_0028ce38(void);
void func_00256aa0(void);
void func_0025f750(void);
void func_00267768(void);
void func_0026bbf8(void);
void func_0026ee30(void);
void func_00277128(void);
void func_0027c570(void);
void func_002831b0(void);
void func_0027e770(void);
void func_00264458(void);
void func_00254f80(void);  // 0x00254f80: definition moved into src/anon/unit_00254020.cpp

struct ObA51 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    u8 pad[404];
};
struct ObB51 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    u8 pad[432];
};
struct Mgr51 {
    ObA51 grp[9][8];
    ObA51 a;
    ObB51 b, c, d;
    ObB51 e[9];
    ObB51 f[9];
};
extern Mgr51* D_0035f5e8;
s32 func_00139d78(void*);
void func_00139510__82352(void*) asm("func_00139510");
void func_002a41f0(void);  // 0x002a41f0: definition moved into src/anon/unit_002a40c8.cpp

struct Pad53 { u8 pad[8]; u64 trg; };
extern u8* D_0035f634__83558 asm("D_0035f634");
Pad53* func_00167f18(s32);
s32 func_00287cd0(void);
void func_00281d48(void);
s32 func_002b1660(void);
u16* func_002b23e0(s32);  // list_entry_by_index_checked
void func_001a3188(u16, s32, s32);
u32 func_002b1aa0(void);
u32 func_00192048__83558(u32) asm("func_00192048");
void func_002b1af0(void);
void func_00139580(u8*);
void func_002817b8(void);
void func_00287c30(void);
void func_00287cc0(s32);
void func_002b1a00(void);
void func_00281e20(void);
s32 func_002b16d8(void);
void func_00287c90(s32);
void func_00242618(s32, s32);
void func_0028dac8(u8*, s32);
void func_00281b30__83558(void) asm("func_00281b30");
void func_00287c00(s32);
void func_002b14f0(void);  // 0x002b14f0: definition moved into src/anon/unit_002b0950.cpp

struct Ent54 { u8 b[432]; };
struct Lyt54 { u8 b[76]; };
struct Prm54 { u8 b[32]; };
struct Obj54 {
    u8 pad[188];
    Lyt54 lyt[9];
    u8 pad2[1320 - 188 - 9 * 76];
    Ent54 a[8];
    Ent54 b[8];
    u8 pad3[8244 - 4776 - 8 * 432];
    s32 st;
    u32 pad4;
    s32 na;
    s32 nb;
};
extern u8 D_003755b0[];
extern u8 D_003755b8[];
extern Prm54 D_00375638[];
extern u8 D_01e2bd40[];
u32 func_002c3268(Obj54*);
void func_0028b4c0(Ent54*, u32);  // copy_3halfwords_416
void func_0028b4f0(Ent54*, u8*);  // copy_3halfwords_422
void func_0023f778__84943(Lyt54*, u32) asm("func_0023f778");
void func_0023f7a8__84943(Lyt54*, Prm54*) asm("func_0023f7a8");
s32 func_00139d78(void*);
void func_00138c10__84943(u8*, s32) asm("func_00138c10");
void func_002cb0e8(u8*, u8*, f32);
void func_002c3368(Obj54* o);  // 0x002c3368: definition moved into src/anon/unit_002c2228.cpp

struct Grid55 { s8 cols; u8 pad; s16 size; };
struct UV55 { s16 u[4]; s16 v[4]; };
extern Grid55 D_00374cd0[];
u32* func_002b23e0__86355(s32) asm("func_002b23e0");
static inline void Put55(UV55* o, const UV55& t, s32 a, s32 b, s32 c, s32 d)
{
    o->u[0] = t.u[a]; o->v[0] = t.v[a];
    o->u[1] = t.u[b]; o->v[1] = t.v[b];
    o->u[2] = t.u[c]; o->v[2] = t.v[c];
    o->u[3] = t.u[d]; o->v[3] = t.v[d];
}
void func_002b28b0(u32 a0, s32 idx, s32 mode, UV55* out);  // 0x002b28b0: definition moved into src/anon/unit_002b1db8.cpp

struct Rec57 { u8 pad[8]; u32 v; };
struct Obj57 { u32 vt; u8 pad[84]; u8 b88; u8 pad2[7]; u32 h; u32 pad3; u8 sub[4]; void* m; };
extern u8 D_00362eb8[];
extern u8 D_00375f18[];
extern u8 D_00362e80[];
extern u8* D_0034e948;
void func_002ce958(Obj57*, s32, u32, s32);
void func_002e34b8(u8*);
void func_002ceae8(Obj57*, char*, u8*);
u32 func_001708f8(char*, s32);
Rec57* func_00168b38(u32, s32, s32);  // entry_array_find_nth
void func_002e34c0(u8*, u32);
void func_002e64b0(u32);
u32 func_001050c8(void);
void* func_001063c0(s32, u32);
void func_002e6fc0(void*, u32);
void func_002cedd0(s32, u8*);
void func_0016bd60(u8*, s32);
u8* func_0016b740(s32);
void func_002e2350(Obj57*);
// 002e1f70: moved to src/anon/unit_002e1908.cpp

V33 func_00163650(const V33*, const V33*, const V33*);
void func_001468f0(V33* out, V33* p);  // 0x001468f0: definition moved into src/anon/unit_00145600.cpp

struct V62 {
    f32 x, y, z, w;
    V62() {}
    V62(const V62& o) { QCOPY(this, &o); }
} __attribute__((aligned(16)));
struct Obj62 { u8 pad[86]; u16 pow; u8 pad2[2]; u16 se; };
struct Itm62 { u8 pad[10]; u16 atk; };
struct Hp62 { s32 hp; s32 max; };
struct Tune62 { u8 pad[324]; f32 thr; };
extern u8* D_0034e948;
extern s32 D_0032dfc8;
extern Tune62* D_00352130__89182 asm("D_00352130");
s32 func_001b7038(Obj62*);
u8* func_00177860(u8*);
Itm62* func_001c0cc8(void);  // get_global_35c63c
s32 func_0019ba60(u8*);
s32 func_001b70d0(s32);
void func_0015b680(V62*, s32, s32);
void func_001c0890(u16);
void func_001b4198(Obj62* o, u8* e, const V62* pos);  // 0x001b4198: definition moved into src/anon/unit_001b2780.cpp

struct Snd63 { u8 pad[5]; u8 pri; };
struct Obj63 { u8 pad[32]; u32 fl; u8 m[2492]; u8* pl; };
s32 func_001bd590(Obj63*);
void func_001be890(Obj63*, u8*);
void func_001bc778(u8*);
void func_001be540(Obj63*, u8*);
void func_001bf0c8(Obj63*);
s32 func_001bdfe0(Obj63*);
Snd63* func_001bc780(u8*, s32, s32, s32);
s32 func_001bdd20(Obj63*);
s32 func_0017a538(u8*);
s32 func_001917c0(void);
static inline bool Is63(u8* p) { return *(s32*)(p + 2896) == 6; }
void func_001be5f0(Obj63* o);  // 0x001be5f0: definition moved into src/anon/unit_001bc568.cpp

struct Snd64 { u8 pad[5]; u8 pri; };
struct Obj64 { u8 pad[32]; u32 fl; u8 pad2[348]; u8 m[2144]; u8* pl; };
extern u8 D_00351ec0[];
extern u8 D_00351eb8[];
void func_001bc778(u8*);
s32 func_001c8db8(u8*, s32);
s32 func_001bbf40(void);
s32 func_001a36e0(s32);
s32 func_001a3570(s32);
u16* func_001a3868(s32);
s32 func_001c9b38(u16*);
Snd64* func_001bc780__91789(u8*, s32, s32, s32) asm("func_001bc780");
void func_001beb00(Obj64* o);  // 0x001beb00: definition moved into src/anon/unit_001bc568.cpp

void func_002d1270(s32, s32);
void func_002d6f28(s32, s32);
void func_002dc278(s32, s32);
void func_002bea88(void);
void func_001cebb0(void);
void func_002e0bb0(s32);
void func_002e1f40(s32);
void func_001d7218(s32 k);  // 0x001d7218: definition moved into src/anon/unit_001d68e0.cpp

extern s8 D_0035ed9c;
extern u8* D_0035ed8c;
extern s32 D_0035f3d4;
extern u32 D_0035ed70;
extern u32 D_0035ed78;
s32 func_00139d78(void*);
s32 func_0028afa8(u32);
u8* func_002891b8(u32, s32);
void func_0028d8c0__93727(u8*, s32, s32, s32, u32, s32, s32, s32) asm("func_0028d8c0");
void func_0028dcc0__93727(u8*, u8*) asm("func_0028dcc0");
void func_00139648(u8*);
u32 func_0023aa18(u8*);
u32 func_0023aa38(u8*);
void func_00138c68(u8*, u32, u32);
void func_0024b0e8(void);
void func_0024aef0(void);  // 0x0024aef0: definition moved into src/anon/unit_00249ef0.cpp

struct It70 { u8 type; u8 pad[3]; u32 v; };
extern u8* D_0035ede4;
extern char* D_0035edf8;
extern u32 D_0035edcc;
extern s32 D_0035edf4;
extern u8 D_003722e0[];
extern u8 D_003722e8[];
extern char D_00372140[];
extern char D_00372150[];
s32 func_00139d78(void*);
void func_002fde18(void*, s32, s32);
s32 func_002891e8(u32);
It70* func_001d56c8(u8);
u32 func_00192048__94859(s32) asm("func_00192048");
s32 func_00192c40(u32, char*);
void func_0014ca80(u32, s32*, s32*, s32*, s32*);
char* func_00192cc0(char*, const char*, ...);
s32 func_00192b30(char*);
void func_00192c90(u32, char*);
void func_0024e228(void);  // 0x0024e228: definition moved into src/anon/unit_0024cda8.cpp

extern s8 D_0035ee51;
extern u8* D_0035ee48;
extern s32 D_0035f3d4;
extern u32 D_0035ee34;
extern u32 D_0035ee3c;
s32 func_00139d78(void*);
s32 func_002892f8(u32);
u8* func_002891b8(u32, s32);
void func_0028d8c0__96362(u8*, s32, s32, s32, u32, s32, s32, s32) asm("func_0028d8c0");
void func_0028dcc0__96362(u8*, u8*) asm("func_0028dcc0");
void func_00139648(u8*);
u32 func_0023aa18(u8*);
u32 func_0023aa38(u8*);
void func_00138c68(u8*, u32, u32);
void func_00250998(void);
void func_002507a0(void);  // 0x002507a0: definition moved into src/anon/unit_0024fbd0.cpp

struct ObB74 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    u8 pad[432];
};
struct Sys74 {
    u8 w0[816];
    u8 w1[816];
    u8 w2[3376 - 1632];
    ObB74 a[24];
    u8 pad[24304 - 3376 - 24 * 436];
    ObB74 b[24];
};
extern u32 D_0035f01c;
extern u32 D_0035f020;
extern u32 D_0035f024;
Sys74* func_00257770(void);
s32 func_00139d78(void*);
void func_00139510__97494(void*) asm("func_00139510");
s32 func_0028acc8(u32);
void func_0028abe0(u32);
void LeaveWarn74(void) asm("_ZN2Tz6CmItem9LeaveWarnEv");
void LeaveWarn74(void);  // 0x00262cb8: definition moved into src/anon/unit_0025f6b8.cpp

s32 func_002aa098(s32);
s32 func_002aa2f8(s32);  // test_bit_global_b
s32 func_002aaa38(s32);  // test_bit_global_a
s32 func_002aae88(s32);
s32 func_002ab2b0(s32);
s32 func_002ab540(s32);
s32 func_002ab8e8(s32);
s32 func_002abc60(s32);
s32 func_002ac420(s32);
s32 func_002ac748(s32);
s32 func_002aa668(s32, s32);
s32 func_002abff0(s32, s32);
s32 func_002a1b18(s32, s32);
s32 func_002ac9b0(s32 a);  // 0x002ac9b0: definition moved into src/anon/unit_002a99c8.cpp

struct Ent80 { u8 b[432]; };
struct Lyt80 { u8 b[76]; };
struct Prm80 { u8 b[32]; };
struct Obj80 {
    u8 pad[188];
    Lyt80 lyt[9];
    u8 pad2[1320 - 188 - 9 * 76];
    Ent80 a[8];
    Ent80 b[8];
    u8 pad3[8244 - 4776 - 8 * 432];
    s32 st;
    u32 pad4;
    s32 na;
    s32 nb;
};
extern u8 D_003755a0[];
extern u8 D_003755a8[];
extern Prm80 D_00375640[];
extern u8 D_01e2bd30[];
u32 func_002c3268__99908(Obj80*) asm("func_002c3268");
void func_0028b4c0__99908(Ent80*, u32) asm("func_0028b4c0");
void func_0028b4f0__99908(Ent80*, u8*) asm("func_0028b4f0");
void func_0023f778__99908(Lyt80*, u32) asm("func_0023f778");
void func_0023f7a8__99908(Lyt80*, Prm80*) asm("func_0023f7a8");
s32 func_00139d78(void*);
void func_00138c10__99908(u8*, s32) asm("func_00138c10");
void func_002cb0e8(u8*, u8*, f32);
void func_002c34d0(Obj80* o);  // 0x002c34d0: definition moved into src/anon/unit_002c2228.cpp

struct Obj81 { u32 p0; u32 p4; };
struct Ent81 { u8 pad[8]; u32 k; };
void func_002bfd48(Obj81*, u32);
u32 func_002c6218(void);
void func_002c6280(u32, s32);
s32 func_001b8d60(u8*);
void func_00102448(u32, s32);
Ent81* func_001b8800_101452(u8) asm("func_001b8800");
void func_001b8988(Ent81*, s32);
void qsort(void*, s32, s32, void*);
s32 func_002bfcf8(const void*, const void*);
void func_002bfb90(Obj81* o);  // 0x002bfb90: definition moved into src/anon/unit_002bebd0.cpp

struct Rec83 { u8 pad[8]; u32 v; };
struct Obj83 { u32 vt; u8 pad[84]; u8 b88; u8 pad2[7]; u32 h; u32 pad3; u8 sub[4]; void* m; };
extern u8 D_00362eb8[];
extern u8 D_00375f18[];
extern u8 D_00362e80[];
extern u8* D_0034e948;
void func_002ce958_102666(Obj83*, s32, u32, s32) asm("func_002ce958");
void func_002e34b8(u8*);
void func_002ceae8_102666(Obj83*, char*, u8*) asm("func_002ceae8");
u32 func_001708f8(char*, s32);
Rec83* func_00168b38_102666(u32, s32, s32) asm("func_00168b38");
void func_002e34c0(u8*, u32);
void func_002e64b0(u32);
u32 func_001050c8(void);
void* func_001063c0(s32, u32);
void func_002e6fc0(void*, u32);
void func_002cedd0(s32, u8*);
void func_0016bd60(u8*, s32);
u8* func_0016b740(s32);
void func_002e2350_102666(Obj83*) asm("func_002e2350");
// 002e20d8: moved to src/anon/unit_002e1908.cpp

struct Pr84 { s32 x, y; };
struct St84 {
    s32 a[16]; s32 f64; s32 b[16]; s32 f132; s32 c[3]; s32 d[6]; s32 e[16]; s32 f[16]; s32 g[4];
    s32 f316, f320; Pr84 h[10]; Pr84 k[10]; s16 f484, f486;
};
void func_00319a60(St84* s);  // 0x00319a60: definition moved into src/anon/unit_003197d0.cpp

struct V86 {
    f32 x, y, z, w;
    V86() {}
    V86& operator=(const V86& o) { if (this != &o) QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
// VU0 vector helpers: hand-written macro code in the original.
static inline V86 Sub86(const V86& a, const V86& b)
{
    V86 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1,0(%1)\n\tlqc2 $vf2,0(%2)\n\tvsub.wxyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline void Norm86(V86& v)
{
    asm volatile("lqc2 $vf1,0(%0)\n\tvmul.xyz $vf2,$vf1,$vf1\n\tvaddy.x $vf2,$vf2,$vf2y\n\tvaddz.x $vf2,$vf2,$vf2z\n\t"
                 "vsqrt Q,$vf2x\n\tvwaitq\n\tcfc2.ni $8,$vi22\n\tvaddq.x $vf2,$vf0,Q\n\tmtc1 $8,$f0\n\tvnop\n\t"
                 "vdiv Q,$vf0w,$vf2x\n\tvwaitq\n\tvmulq.xyz $vf1,$vf1,Q\n\tsqc2 $vf1,0(%0)"
                 : : "r"(&v) : "$8", "$f0", "memory");
}
static inline void Cross86(V86& r, const V86& a, const V86& b)
{
    asm volatile("lqc2 $vf1,0(%1)\n\tlqc2 $vf2,0(%2)\n\tvsub.wxyz $vf3,$vf0,$vf0\n\t"
                 "vopmula.xyz ACC,$vf1,$vf2\n\tvopmsub.xyz $vf3,$vf2,$vf1\n\tsqc2 $vf3,0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
}
static inline void AddTo86(V86& a, const V86& b)
{
    asm volatile("lqc2 $vf1,0(%0)\n\tlqc2 $vf2,0(%1)\n\tvadd.wxyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,0(%0)"
                 : : "r"(&a), "r"(&b) : "memory");
}
struct Cam86 { u8 pad[80]; V86 eye; V86 at; V86 up; };
// 00107700: moved to src/naka/libkn/camera.cpp

struct Rec91 { u16 id; u8 pad[26]; u8 b28; u8 pad2[3]; u16 h32; };
struct Dat91 { u8 pad; u8 kind; };
struct Wk91 { u8 pad[52]; u32 snd; };
union U91 { Wk91* p; u8 c; };
extern U91 D_01d48cb0_106899 asm("D_01d48cb0");
Rec91* func_001b8e88(u32);
Dat91* func_001d3fe0(u16);
Wk91* func_001050d8_106899(s32) asm("func_001050d8");
void func_001b47d8(Wk91*, Dat91*, u8*, f32);
s32 func_001d3f80(Dat91*);
void func_00179a68(u8*, f32);
s32 func_001b5c60(Rec91*);  // to_1bbf80_field28
void func_00187650(u8*, s32, s32);
void func_00176d68(u8*, u8);
u8* func_0017df58(s32);
s32 func_0019ba60(u8*);
void func_001c9780(u8*, f32);
void func_001b5250(Wk91*, s32);
void func_001d6148(u8*, u32);
void func_0016cce8_106899(u32, s32, u32*, s32, s32) asm("func_0016cce8");
void func_001b4430(u32 id, u8* e);  // 0x001b4430: definition moved into src/anon/unit_001b2780.cpp

struct Sp90 { f32 r; f32 h; u32 pad; f32 x, y, z; u8 pad2[8]; };
struct Obj90 { union { s32 n; f32 nf; }; u8 pad[16]; Sp90 s[1]; };
void func_00144450(f32*);
void func_001447c0(f32*, f32, f32, f32, f32, f32, f32);
#define MIN90(a, b) ((a) < (b) ? (a) : (b))
void func_001b7c80(Obj90* o, f32* b);  // 0x001b7c80: definition moved into src/anon/unit_001b6a50.cpp

struct Gs100 { u8 pad[128]; u8* tab; u8 pad2[36]; u64 st; };
struct Idx100 { s32 f0; s32 f4; s32 f8; };
struct Ctx100 { u8 pad[12]; Idx100* idx; };
struct Req100 { s32 id; s32 snd; s32 off; u8 on; };
extern s32 D_01d9ea9c;
extern Gs100* D_01d9e6e0;
u8* func_001e7a98(Gs100*, u8*);
void func_002226b8(u8*, u8*);  // vec3_copy
void func_001fc1a0(u8* o, Req100* r, Ctx100* c);  // 0x001fc1a0: definition moved into src/anon/unit_001fb350.cpp

extern s8 D_0035ed14;
extern u8* D_0035ed04;
extern s32 D_0035f3d4;
extern u32 D_0035ece8;
extern u32 D_0035ecf0;
s32 func_00139d78(void*);
s32 func_00244938(s32);
u8* func_002891b8(u32, s32);
void func_0028d8c0_110390(u8*, s32, s32, s32, u32, s32, s32, s32) asm("func_0028d8c0");
void func_0028dcc0_110390(u8*, u8*) asm("func_0028dcc0");
void func_00139648(u8*);
u32 func_0023aa18(u8*);
u32 func_0023aa38(u8*);
void func_00138c68(u8*, u32, u32);
void func_00244e28(void);
void func_00244c30(void);  // 0x00244c30: definition moved into src/anon/unit_00242478.cpp

extern s8 D_0035edc5;
extern u8* D_0035edbc;
extern s32 D_0035f3d4;
extern u32 D_0035eda8;
extern u32 D_0035edb0;
s32 func_00139d78(void*);
s32 func_0028afa8(u32);
u8* func_002891b8(u32, s32);
void func_0028d8c0_111552(u8*, s32, s32, s32, u32, s32, s32, s32) asm("func_0028d8c0");
void func_0028dcc0_111552(u8*, u8*) asm("func_0028dcc0");
void func_00139648(u8*);
u32 func_0023aa18(u8*);
u32 func_0023aa38(u8*);
void func_00138c68(u8*, u32, u32);
void func_0024c898(void);
void func_0024c6a0(void);  // 0x0024c6a0: definition moved into src/anon/unit_0024ba58.cpp

extern u32 D_0035f010;
extern s8 D_0035f058;
extern s8 D_0035f059;
extern s8 D_0035f05a;
extern s8 D_0035f064;
extern u8 D_0035f060[];
s32 func_00281100(u32);
s32 func_002813b8(void);
s32 func_0027aa78(void);
u8* func_001a8bd0(s32);
s32 func_001a8bf8(u8*, s32);  // get_bits5_at
void func_00257000(void);
void func_00257c78(void);  // 0x00257c78: definition moved into src/anon/unit_00254020.cpp

struct Sub96 { u8 pad[184]; u32 fl; };
union UA96 { u8* p; u32 u; };
union UB96 { s8* p; u32 u; };
extern UA96 D_0035f5d8;
extern UB96 D_0035f5d4;
extern s32 D_0035f3d4;
extern u32 D_0035f14c;
extern u32 D_0035f148;
extern u32 D_0035f210;
extern u32 D_00374b3c;
extern u32 D_00374b40;
s32 func_00139d78(void*);
void func_00139510_113723(void*) asm("func_00139510");
u8* func_002766d0(void);
s32 func_00287bc0(void);
void func_0028d8c0_113723(u8*, s32, u32, u32, u32, u32, s32, s32) asm("func_0028d8c0");
void func_0028dcc0_113723(u8*, u8*) asm("func_0028dcc0");
static inline void Flag96(u8* e) { Sub96* sb = (Sub96*)(e + 24); sb->fl |= 8; }
void func_002a1220(void);  // 0x002a1220: definition moved into src/anon/unit_002a0908.cpp

struct Ref99 { u8 pad[36]; s32 ref; };
struct Hdr99 { u32 type; u8 pad; u8 kind; };
struct Node99 { u32 a; u8 sub[4]; s32 cat; u32* p; u32 f16; u32 b; Ref99* r0; Ref99* r1; u32 pad; s32 f36; };
extern Node99* D_00361fa4;
extern s32 D_00361fb0[];
Hdr99* func_0016e920(u32);
s32 func_002d0200(Hdr99*);
s32 func_002cf638_115228(s32) asm("func_002cf638");
void func_002cf2d0(u8*);
void func_002cf280(u8*, s32, s32);
Node99* func_002cf750(u32 a, u32 b, u32* p, Ref99* r0, Ref99* r1);  // 0x002cf750: definition moved into src/anon/unit_002cf260.cpp

struct Obj98 { u8 pad[28]; u8 pos[844]; u32 lst; u8 m[4]; };
s32 func_0028d008_116312(s32) asm("func_0028d008");
void func_0028cc78(s32, s32, s32, u8*, s32, s32);
u32 func_002891d0(u32);
void func_0028cf28(s32, u32);  // record408_set_and_refresh
s32 func_00289310(u32);
s32 func_002891e8(u32);
void func_002890e0(u32, s32, s32, s32, s32);
void func_00289038(u32, s32, s32, s32, s32, s32, s32);
void func_0028d660(u8*, u32);  // record_set_value_refresh
void func_001396b0_116312(u8*) asm("func_001396b0");
void func_002c40d8(Obj98* o);  // 0x002c40d8: definition moved into src/anon/unit_002c3c90.cpp

// ---- 00226478
HeapE* GetAllocatorE(void) asm("_ZN4AREA12GetAllocatorEv");
void* AllocE(u32 n) asm("_ZN4AREA5AllocEj");
void PaxCtorE(void* p) asm("_ZN3ryj3PAXC1Ev");
void EvAllocInitE(void* self, void* buf, s32 n) asm("_ZN2sa11EVENT_ALLOC4initEPvi");
void* func_00170b30(s32 n);  // alloc_align128
void func_00134668(void* p);
struct PoolA { u32 v; PoolA() { v = 0; } };
struct PoolB { s32 id; u32 v; PoolB() { id = -1; } };
struct PoolC { u32 a, b; PoolC() { a = 0; b = 0; } };
struct PoolD { u32 a, b, c; PoolD() { a = 0; b = 0; c = 0; } };
struct PoolE {
    u32 f0; s32 f4; u8 pad8[8]; u8 pax[32]; s16 f48; s16 pad50;
    PoolE() { PaxCtorE(pax); f4 = -1; f48 = -1; }
    ~PoolE() {}
    static void* operator new[](unsigned int n) { return AllocE(n); }
};
struct PoolF {
    s32 f0; u32 f4; u8 f8; u8 pad9[7]; s32 f16; u32 f20; u32 f24; u32 f28; u8 f32; u8 pad33[15]; u8 f48; u8 pad49[35];
    PoolF() { f16 = -1; f0 = -1; f4 = 0; f20 = 0; f28 = 0; f8 = 0; f32 = 0; f48 = 0; }
    static void* operator new[](unsigned int n) { return AllocE(n); }
};
struct PoolG {
    s32 f0; s32 f4; u32 f8; u8 pad[52];
    PoolG() { f0 = -1; f4 = -1; f8 = 0; }
    ~PoolG() {}
    static void* operator new[](unsigned int n) { return AllocE(n); }
} __attribute__((aligned(16)));
struct PoolH {
    s32 f0; s32 f4; u32 f8; u8 pad[10]; u8 f22; u8 f23; u8 pad2[16];
    PoolH() { f0 = -1; f4 = -1; f8 = 0; f22 = 0; f23 = 0; }
    static void* operator new[](unsigned int n) { return AllocE(n); }
};
struct PoolI {
    u8 d[112];
    PoolI() { func_00134668(this); }
    ~PoolI() {}
} __attribute__((aligned(16)));

extern PoolA* D_0035dce0;
extern PoolB* D_0035dce4;
extern PoolC* D_0035dce8;
extern PoolD* D_0035dcec;
extern u8 D_0035db00[];
extern void* D_0035db14;
extern s32 D_0035db18;
extern PoolF* D_0035dcf0;
extern PoolE* D_0035dcf4;
extern PoolG* D_0035dcf8;
extern PoolH* D_0035dcfc;
extern PoolI* D_0035dd00;

// Allocate and construct the event/effect object pools.
void func_00226478(void);  // 0x00226478: definition moved into src/anon/unit_00224780.cpp

// ---- 00254770
struct AllocVt254 { void* (*alloc)(void* self, u32 size, void* ra); };
struct AllocObj254 { AllocVt254* vt; };
struct Holder254 { u8 pad[20]; AllocObj254* al; };
extern u8 D_0035f057;
extern u8* g_menuObj254 asm("D_0035f03c");
extern u8* D_0035f040;
extern void* g_sel0_254 asm("D_0035f044");
extern void* g_sel1_254 asm("D_0035f048");
extern u32 D_0035ef68;
extern u32 D_0035ef64;
extern s32 D_0035f3d4;
extern u32 D_0035f018;
extern Holder254* D_00347f80;
extern AllocObj254* D_0032ba14;
extern u8 D_00347f98[];
extern u8 D_0035eb98[];
extern u8 D_0035ebb8[];
extern u8 D_00372988[], D_00372a18[], D_00372978[], D_003729a8[], D_003729b0[], D_003729b8[], D_00372990[], D_00372998[];
extern u16 D_00372aa6;
u8* func_0023ee30(u32 size);
void func_0031a838(u8* p);
void func_002369a0(u8* p);  // obj_ctor_36eac8
void func_0023c008(u8* p);  // obj_ctor_36eae8
void func_0028d7f0(u8* a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i);
void func_0023ef50(u8* p);
void func_00290cf0(u32 a, u8* b, u32 c, u32 d, s32 e, u8* f, u8* g);
void func_0028f280(u32 a, u32 b, u8* c, u8* d, u8* e);
void func_00263960(u32 a, u32 b, u8* c, u8* d, u8* e);  // store_globals_and_init
void func_002590b0(u8* a, u32 b, u8* c, u8* d, u8* e, s32 f, u32 g, u32 h);
u8* GetLayout254(u8* p) asm("func_0023f1b0");
u32 func_0023c4b8(u8* p, u32 a);
u32 func_00236ca8(u32 p, u32 a);
void func_0028fc78(void* p, u32 a, u32 b, u8* c);
void func_0028fe38(void* p, u32 a, u32 b, u32 c, u32 d);
void func_00290198(void* p, u32 a, u32 b, u32 c, u8* d);
void func_00290368(void* p, u32 a, u32 b, u32 c, u32 d);
void func_00292870(void);
s32 func_00287bc0(void);
void func_0028fb28(u32 a, u32 b);
void func_00257050(u32 a, u32 b, u32 c);
void func_0026bc10(void);
void func_0026c9c8(void);
void func_002551b8(void);
s32 func_002887c8(void);
void func_002550e8(void);
void func_002551a8(void);
void func_00288750(void (*fn)(void));

static inline void* Alloc254(u32 size) { return D_0032ba14->vt->alloc(D_0032ba14, size, __builtin_return_address(0)); }

// Build the menu layout objects for this screen and start its fade.
void func_00254770(void);  // 0x00254770: definition moved into src/anon/unit_00254020.cpp

// ---- 0025a660
extern void* D_0035f650;
extern u8 D_0035f0b0;
s32 func_00287cd0(void);
s32 func_00289380(void* s);
s32 func_00287c10(void);
s32 func_0028acc8_a660(void* s) asm("func_0028acc8");
s32 func_00289310_a660(void* s) asm("func_00289310");
void func_0028abe0_a660(void* s) asm("func_0028abe0");
void func_002b4f50(void);
bool func_002b55e0(void);
s32 func_00233e70(s32 a);
s32 func_00233e60(void);
void func_00287c30(void);
void func_00287d20(s32 a);
s32 func_00287bc0(void);
void func_002b5af0(void);
void func_0028f7e8(s32 a);
void func_0025a1d0(void);
void func_00288018(void);  // global_zero_4dwords
void func_00240be0(void);
s32 func_002b4fb8(void);
void func_002b50f8(void);  // zero_global_byte_c
s32 func_00240ba0_a660(void) asm("func_00240ba0");
s32 func_002348a8_a660(s32 slot, s32 a) asm("func_002348a8");
void func_002b5108_a660(u32 msg, s32 slot) asm("func_002b5108");
void func_00287c00(s32 m);
void func_002b5558(void);
void func_00287cc0(s32 s);
void func_00234570_a660(s32 slot, void* p) asm("func_00234570");
void func_00287bd0(s32 a, s32 b);
s32 func_002b50e8(void);  // get_global_byte_c
s32 func_0028ae28(void* s, s32 a);
s32 func_00287df0(s32 a, s32 b, s32 c, s32 d, s32 e);
s32 func_00242848(s32 a);
void func_002b4ee0(void);
void func_0028f6f0(s32 a);  // record884_refresh_by_index

// Memory-card menu: per-frame state update.
void func_0025a660(void);  // 0x0025a660: definition moved into src/anon/unit_002588e8.cpp

// ---- 0025b7b8
extern void* D_0035f64c;
s32 func_00287cd0(void);
s32 func_00289380(void* s);
s32 func_00289310_b7b8(void* s) asm("func_00289310");
s32 func_00233e70(s32 a);
bool func_002b55e0(void);
void func_002b5658(void);
void func_00287c30(void);
s32 func_00287bc0(void);
void func_0028af18_b7b8(void* s, u32 a) asm("func_0028af18");
void func_0028f7e8(s32 a);
void func_0025a1d0(void);
s32 func_00240ba0_b7b8(void) asm("func_00240ba0");
s32 func_002b5490(void);
void func_002b54f8(void);
void func_00287cc0(s32 s);
void func_0025d560(void);
s32 func_002348a8_b7b8(s32 slot, s32 a) asm("func_002348a8");
void func_00234570_b7b8(s32 slot, void* p) asm("func_00234570");
void func_0025d620(void);
s32 func_00287df0_b7b8(s32 a, s32 b, s32 c, void (*d)(void), s32 e) asm("func_00287df0");
s32 func_00242848(s32 a);
s32 func_0028afa8_b7b8(void* s) asm("func_0028afa8");
void func_00240bc0(s32 a);
void func_002b4dd0(s32 a);
s32 func_002419e8(void);
void func_002b5108_b7b8(u32 msg, s32 slot) asm("func_002b5108");
void func_002b4c88(s32 a);
void func_00287bd0(s32 a, s32 b);
void func_00263c60(void);  // sync_global_index_if_changed
s32 func_00288040(void);
void func_00288018(void);  // global_zero_4dwords
s32 func_00241c20(s32 a);
struct SaveEnt { u16 a; s16 b; u8 pad[4]; u32 flags; u8 pad2[20]; };
SaveEnt* func_00241f10(void);
s32 func_002408d0(s32 a);
void func_00241450(s32 a);
void func_00287d20(s32 a);
s32 func_00241770(s32 a);
void func_002400f8(s32 a);
void func_00287da0(void);
void func_002b5558(void);
void func_00287c00(s32 m);
void func_0028f6f0(s32 a);  // record884_refresh_by_index

// Memory-card load menu: per-frame state update.
void func_0025b7b8(void);  // 0x0025b7b8: definition moved into src/anon/unit_002588e8.cpp

// ---- 002648b8
extern void* D_0035f01c_48b8 asm("D_0035f01c");
s32 func_00287cd0(void);
s32 func_00289380(void* s);
s32 func_00289310_48b8(void* s) asm("func_00289310");
s32 func_00287c10(void);
s32 func_0028f930(s32 a);
s32 func_002656c0(void);
s32 func_00257970(void);
void func_00287f90(s32 a);
void func_002655e8(void);
void func_0028f7e8(s32 a);
void func_00287c30(void);
s32 func_00287bc0(void);
void func_00267398(void);
void func_002551b8(void);
void func_00264be0(void);
s32 func_0028ae28(void* s, s32 a);
s32 func_00265740(void);
void func_0028ab20(void* s);
void func_00265780(void);
void func_0028fa98(s32 a);
void func_00287cc0(s32 s);
s32 func_00287df0_48b8(s32 a, s32 b, s32 c, void (*d)(void), s32 e) asm("func_00287df0");
s32 func_00242848(s32 a);
void func_00263c60(void);  // sync_global_index_if_changed
void func_00265580(void);
u8* func_002891b8_48b8(void* p, s32 n) asm("func_002891b8");
void func_0028fb68(s32 a, u32 b);
u32 func_002891e8_48b8(void* s) asm("func_002891e8");
u32 func_002670a0(u32 a);
void func_00257050_48b8(s32 a, u32 b, s32 c) asm("func_00257050");
void func_00287c00(s32 m);
void func_00287c90(s32 a);
void func_00287da0(void);
void func_0028f6f0(s32 a);  // record884_refresh_by_index
s32 func_00288040(void);
void func_00288018(void);  // global_zero_4dwords

// Party/item menu: per-frame state update.
void func_002648b8(void);  // 0x002648b8: definition moved into src/anon/unit_002640a8.cpp

// ---- 00268db8
extern void* D_0035f01c_8db8 asm("D_0035f01c");
extern void* D_0035f018_8db8 asm("D_0035f018");
extern void* D_0035f010_8db8 asm("D_0035f010");
extern void* D_0035f0ec;
s32 func_00287cd0(void);
s32 func_00289380(void* s);
s32 func_00289310_8db8(void* s) asm("func_00289310");
s32 func_00287bc0(void);
s32 func_00269f58(void);
s32 func_002911f8(void* p);
s32 func_0028f930(s32 a);
s32 func_00256ef0(void);
s32 func_00257970(void);
void func_00287f90(s32 a);
void func_00256c40(void);
void func_00269ef8(void);
void func_00291288(void* p);
s32 func_00287c10(void);
void func_00287c30(void);
void func_0028f7e8(s32 a);
void func_0026b008(void);
s32 func_00257070(s32 a);
u8* func_00281180(void* p, s32 i);
void func_00188ac8(u32 a);
void func_002678a8(void);
s32 func_00269fc0(void);
void func_0026a060(void);
void func_0028fa98(s32 a);
void func_00269a60(void);
void func_00287c90(s32 a);
s32 func_0028afa8_8db8(void* s) asm("func_0028afa8");
void func_0026b8f0(void);
s32 func_00287df0_8db8(s32 a, s32 b, s32 c, void (*d)(void), s32 e) asm("func_00287df0");
s32 func_00242848(s32 a);
struct Ent268 { u16 id; u8 pad[4]; };
Ent268* func_00281f20(void* p);
s32 func_0026b2c0(void);
void func_00269378(void);
void func_00287bd0(s32 a, s32 b);
void func_00287c00(s32 m);
void func_00281d48(void);
void func_00281e20(void);
s32 func_00288040(void);
void func_00288018(void);  // global_zero_4dwords
void func_0026ab18(u32 id);
void func_0028f6f0(s32 a);  // record884_refresh_by_index
void func_00256e80(void);
void func_00263c60(void);  // sync_global_index_if_changed
void func_00269e20(void);
void func_00281b30_8db8(void) asm("func_00281b30");
void func_002831e0(s32 a, s32 b);
void func_00287cc0(s32 s);
void func_0026b448(void);
void func_00287da0(void);

// Item-list menu: per-frame state update.
void func_00268db8(void);  // 0x00268db8: definition moved into src/anon/unit_00268b30.cpp

// ---- 002d0290
struct Src2d0 { s32 id; u8 pad; u8 type; };
struct Vec2d0 { f32 x, y, z, w; };
u8* AllocR(u32 size) asm("_ZN4AREA5AllocEj");
u32 func_00167f18_0290(s32 a) asm("func_00167f18");
void func_002d49c0(u8* p, Src2d0* s, u32 v, u32 a, f32 f);
void func_002dd700(u8* p, Src2d0* s, u32 v, u32 a, f32 f);
void func_002d9730(u8* p, Src2d0* s, u32 v, u32 a, f32 f);
void func_002cff00(u8* p, Src2d0* s, s32 k, u32 a, f32 f);
void func_002db858(u8* p, Src2d0* s, u32 a, f32 f);
void func_002db4f0(u8* p, Src2d0* s, u32 a, f32 f);
void func_002d5d50(u8* p, Src2d0* s, u32 a, f32 f);
void func_002d69c8(u8* p, Src2d0* s, u32 a, f32 f);
void func_002d4200(u8* p, Src2d0* s, u32 a, f32 f);
void func_00177f50_0290(u8* p, Src2d0* s, s32 k, u32 v, u32 a, f32 f) asm("func_00177f50");
void func_002d29a8(u8* p, Src2d0* s, s32 k, u32 a, f32 f);
void func_002dda88(u8* p, Src2d0* s, u32 a, f32 f);
void func_002daca0(u8* p, Src2d0* s, u32 a, f32 f);
void func_002daa98(u8* p, Src2d0* s, u32 a, f32 f);
void func_002db6b0(u8* p, Src2d0* s, u32 a, f32 f);
void func_002de788(u8* p, Src2d0* s, Vec2d0* v, f32 f);

// Create the effect object for a source entry according to its type.
u8* func_002d0290(Src2d0* s, u32 a, f32 f);  // 0x002d0290: definition moved into src/anon/unit_002cf260.cpp

// ---- 00254ab8
struct ListVt254 { void* f[6]; void (*setItem)(void* self, s32 i, u32 a, s32 b, s32 c, s32 y, u32 col); };
struct List254 { ListVt254* vt; };
extern u8* D_0035f02c;
extern u8* D_0035f030_4ab8 asm("D_0035f030");
extern void* D_0035f010_4ab8 asm("D_0035f010");
extern u32 D_0035ef68;
extern u32 D_0035ef64;
extern u32 D_0035f03c;
extern u8 D_0035f056;
extern u8 D_0035ef60;
extern u32 D_00372974;
extern u32 D_00372970;
s32 func_00139d78_4ab8(u8* p) asm("func_00139d78");
void func_0028d8c0(u8* q, s32 id, u32 a, u32 b, u32 c, s32 d, s32 e, s32 f);
u8* func_00256b68_4ab8(s32 a) asm("func_00256b68");
List254* func_00287dc0_4ab8(void) asm("func_00287dc0");
void func_0023d808(List254* l, s32 id);
s32 func_00281100_4ab8(void* p) asm("func_00281100");
s32 func_00281128(void* p, s32 i);  // get_entry20_field16
s32 func_00281538(void* p, s32 i);
s32 func_0023ec18(List254* l, s32 i);
s32 func_002811e0(void* p, s32 i);
u32 func_00281238(void* p, s32 i);
s32 func_0027aa78(void);
void func_0023e858(List254* l, s32 i, f32 f);
void func_0023e8b8(List254* l, s32 i, f32 f);
void func_0023e8d8(List254* l, s32 i, f32 f);
s32 func_002811b0(void* p, s32 i);
void func_0023eae0(List254* l, s32 i, s32 a, s32 b);
void func_0023eac0(List254* l, s32 i, s32 k);  // store_byte_2912
void func_0023e958(List254* l, s32 i, s32 a, s32 b, s32 c, s32 d);
void func_0023e9c8(List254* l, s32 i, u8* p);
void func_0023e9e0(List254* l, s32 i, u8* p);

void func_00254ab8(void);  // 0x00254ab8: definition moved into src/anon/unit_00254020.cpp

// ---- 0025fb48
extern void* D_0035f01c_fb48 asm("D_0035f01c");
extern void* D_0035f010_fb48 asm("D_0035f010");
s32 func_00287cd0(void);
s32 func_00289380(void* s);
s32 func_00289310_fb48(void* s) asm("func_00289310");
s32 func_00287c10(void);
s32 func_00262160(void);
s32 func_00257970(void);
s32 func_00256ef0(void);
s32 func_0028f930(s32 a);
void func_00287f90(s32 a);
void func_00256ea8(void);
void func_00262118(void);
void func_0028f878(void);
void func_00287c30(void);
void func_0028af18_fb48(void* s, u32 a) asm("func_0028af18");
void func_0028f7e8(s32 a);
void func_002551b8(void);
void func_002678a8(void);
s32 func_002570a0(s32 a);
s32 func_00281100_fb48(void* p) asm("func_00281100");
void func_00277178(s32 a, s32 b);
void func_002634c8(s32 a);
void func_00257050_fb48(s32 a, s32 b, s32 c) asm("func_00257050");
void func_0025ffd0(void);
s32 func_0028ae28(void* s, s32 a);
void func_0028ab20(void* s);
void func_00256e30(void);
void func_0028fa98(s32 a);
void func_00287c90(s32 a);
s32 func_0028afa8_fb48(void* s) asm("func_0028afa8");
void func_002638e0(void);
s32 func_00287df0_fb48(s32 a, s32 b, s32 c, void (*d)(void), s32 e) asm("func_00287df0");
s32 func_00242848(s32 a);
s32 func_00257070(s32 a);
s32 func_002891e8_fb48(void* s) asm("func_002891e8");
void func_00287da0(void);
void func_00256e80(void);
void func_00263c60(void);  // sync_global_index_if_changed
void func_0028f6f0(s32 a);  // record884_refresh_by_index
void func_002620a0(void);
void func_00287c00(s32 m);
u8* func_002891b8_fb48(void* p, s32 n) asm("func_002891b8");
void func_0028fb68(s32 a, u32 b);
s32 func_00288040(void);
void func_00288018(void);  // global_zero_4dwords

void func_0025fb48(void);  // 0x0025fb48: definition moved into src/anon/unit_0025f6b8.cpp

// ---- 002a0cb8
struct Pad2a0 { u64 trig; u64 rep; };
struct Ent2a0 { u16 a; u16 b; u16 c; u16 d; };
struct Win2a0 { u8 pad0; s8 idx; u8 pad1[70]; s16 x; s16 w; s16 y; s16 h; Ent2a0 ent[1]; };
extern u8 D_0035f5e1;
extern u8 D_0035f5e0;
// Read through a union: the original reloads it after every halfword store (no strict aliasing).
extern union { Win2a0* p; s16 h; } D_0035f5d4_0cb8 asm("D_0035f5d4");
extern union { u8* p; s16 h; } D_0035f5d8_0cb8 asm("D_0035f5d8");
Pad2a0* func_00167f18_0cb8(s32 a) asm("func_00167f18");
s32 func_00287cd0(void);
s32 func_00287bc0(void);
void func_002a1cd8(void);
void func_002a1bf8(void);
void func_002a1d38(void);
s32 func_00276368(void);
s32 func_00276888(void);
void func_00287f90(s32 a);
s32 func_00287c10(void);
void func_002a07f0(s32 m);
s32 func_00292630(void);
void func_002a1c68(void);
void func_00287c30(void);
s32 func_00276358(void);
void func_00276220(s32 a, s32 b);
void func_00274cf0(s32 a);  // state_dispatch_0_1_2
void func_002925c0(void);
void func_002958b0(void);
void func_002995e8(void);
void func_002aa048(u16 a);
void func_0029c880(Win2a0* w, s32 m);
void func_00138cb8(u8* p, s32* x, s32* y);
s16 func_0023aa18_0cb8(u8* p) asm("func_0023aa18");
s16 func_0023aa38_0cb8(u8* p) asm("func_0023aa38");
s32 func_00276398(void);  // state_is_150
void func_00275b60(void);
void func_00287c90(s32 a);
s32 func_00139d78_0cb8(u8* p) asm("func_00139d78");
void func_002a10e0(void);
void func_002a16b8(void);
void func_002a17e8(void);
void func_002a1220(void);
void func_002a13e0(Pad2a0* p);
s32 func_00242618_0cb8(s32 a, s32 b) asm("func_00242618");
void func_002a1398(void);
void func_00287da0(void);
void func_0028f6f0(s32 a);  // record884_refresh_by_index
void func_002a0780(void);
void func_00276dc0(void);
void func_00287c00(s32 m);
void func_00287cc0(s32 s);
s32 func_00242848(s32 a);
s32 func_00288040(void);
void func_00288018(void);  // global_zero_4dwords

void func_002a0cb8(void);  // 0x002a0cb8: definition moved into src/anon/unit_002a0908.cpp

// ---- 002f8e58
f32 __ieee754_sqrtf(f32 x);
typedef union { f32 value; u32 word; } FloatShape2f8;
#define GET_FLOAT_WORD_2F8(i, d) do { FloatShape2f8 gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD_2F8(d, i) do { FloatShape2f8 sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
f32 acosf_2f8e58(f32 x) asm("_Z15__ieee754_acosfjjjj");

// fdlibm/newlib __ieee754_acosf (sqrtf is __ieee754_sqrtf).
static const f32 one = 1.0f, pi = 3.1415925f, pio2_hi = 1.57079625f, pio2_lo = 7.54978942e-08f,
    pS0 = 0.166666657f, pS1 = -0.325565785f, pS2 = 0.201212525f, pS3 = -0.0400555357f,
    pS4 = 0.000791535014f, pS5 = 3.47933092e-05f, qS1 = -2.4033947f, qS2 = 2.02094555f,
    qS3 = -0.68828392f, qS4 = 0.0770381466f;

f32 acosf_2f8e58(f32 x);  // 0x002f8e58: definition moved into src/newlib/libm/ef_acos.c

// ---- 0029ba88
extern void* D_0035f200;
extern s8 D_0035f5c4;
s32 func_00289380(void* s);
s32 func_00287cd0(void);
s32 func_00287bc0(void);
s32 func_00276368(void);
s32 func_0028acc8_ba88(void* s) asm("func_0028acc8");
s32 func_00276888(void);
void func_00287f90(s32 a);
s32 func_00287c10(void);
void func_0029aac0(s32 m);
s32 func_00292630(void);
s32 func_00293200(void);
void func_00276690(s32 a);
void func_002766b0(s32 a);
void func_00287c30(void);
void func_0028af18_ba88(void* s, u32 a) asm("func_0028af18");
s32 func_00276358(void);
void func_00276220(s32 a, s32 b);
void func_00274cf0(s32 a);  // state_dispatch_0_1_2
void func_002925c0(void);
void func_002995e8(void);
void func_0029af20(void);
void func_0029be08(void);
s32 func_00289310_ba88(void* s) asm("func_00289310");
s32 func_00276398(void);  // state_is_150
void func_00275b60(void);
void func_00287c90(s32 a);
void func_0029ecf0_x5029(void) asm("func_0029ecf0");
s32 func_00287df0_ba88(s32 a, s32 b, s32 c, void (*d)(void), s32 e) asm("func_00287df0");
s32 func_00242848(s32 a);
void func_0028f6f0(s32 a);  // record884_refresh_by_index
void func_0029aa30(void);
void func_00276dc0(void);
s32 func_002891e8_ba88(void* s) asm("func_002891e8");
s32 func_0028b038(void* s);
void func_002765e8(s32 a, s32 b, s32 c);
void func_00287c00(s32 m);
void func_00287cc0(s32 s);
void func_00287da0(void);
s32 func_00288040(void);
void func_00288018(void);  // global_zero_4dwords

void func_0029ba88(void);  // 0x0029ba88: definition moved into src/anon/unit_0029ba88.cpp

// ---- 002af748
struct Win2af { u8 pad[486]; u16 flags; };
extern void* D_0035f200;
Win2af* func_002a9d68(void);
s32 func_00289380(void* s);
s32 func_00287cd0(void);
s32 func_00287bc0(void);
s32 func_00287c10(void);
s32 func_00276368(void);
s32 func_0028acc8_f748(void* s) asm("func_0028acc8");
s32 func_00276888(void);
void func_00287f90(s32 a);
void func_002aecf0(s32 a);
void func_00287c30(void);
void func_0028af18_f748(void* s, u32 a) asm("func_0028af18");
s32 func_00276358(void);
void func_00276220(s32 a, s32 b);
void func_002aed60(void);
void func_002afaf0(void);
void func_002b01d8(void);
s32 func_00289310_f748(void* s) asm("func_00289310");
s32 func_00276398(void);  // state_is_150
void func_00275b60(void);
void func_00287c90(s32 a);
void func_002b3b78_x5147(void) asm("func_002b3b78");
s32 func_00287df0_f748(s32 a, s32 b, s32 c, void (*d)(void), s32 e) asm("func_00287df0");
s32 func_00242848(s32 a);
void func_0028f6f0(s32 a);  // record884_refresh_by_index
void func_002aece8(void);
void func_00276dc0(void);
void func_00287c00(s32 m);
void func_00287cc0(s32 s);
s32 func_002891e8_f748(void* s) asm("func_002891e8");
s32 func_0028b038(void* s);
void func_002765e8(s32 a, s32 b, s32 c);
void func_00287da0(void);
s32 func_002b2338(s32 a);
void func_002b2428(s32 a);
s32 func_00288040(void);
void func_00288018(void);  // global_zero_4dwords

void func_002af748(void);  // 0x002af748: definition moved into src/anon/unit_002af748.cpp

// ---- 001c3150
struct Stat1c3 {
    u32 abil[11];
    u8 c44, c45, c46, c47, c48;
    u8 pad49[3];
    f32 f52, f56, f60, f64;
    u16 h68, h70, h72, h74, h76, h78, h80, h82;
    f32 f84, f88, f92, f96, f100, f104, f108, f112, f116;
};
struct Prm1c3 {
    u8 pad[284];
    u16 h284; u16 pad286;
    f32 f288, f292, f296, f300;
    u16 h304; u16 pad306;
    u16 h308; u16 pad310;
    f32 f312, f316, f320;
    u8 pad324[4];
    u8 b328; u8 pad329[3];
    u16 h332; u16 pad334;
    f32 f336, f340, f344, f348, f352;
    u16 h356; u16 pad358;
    u8 pad360[4];
    f32 f364, f368, f372;
};
struct Item1c3 { u8 pad[4]; u16 abil; };
extern Prm1c3* D_00352130_3150 asm("D_00352130");
Item1c3* func_001a80c8_3150(s32 id) asm("func_001a80c8");

// Apply one equipped ability/item id to the character's stat block, then mark the ability as held.
void func_001c3150(Stat1c3* s, s32 id);  // 0x001c3150: definition moved into src/anon/unit_001c2b58.cpp

// ---- 002859f0
struct Save285 { u32 seen[51]; u32 fresh[64]; };
// Reloaded after every u32 store in the original (no strict aliasing).
extern union { Save285* p; u32 u; } D_0035f2e4;
u32* func_002859a0(void);
void* func_001a8bd0_59f0(s32 a) asm("func_001a8bd0");
u32 func_001a8c10(void* p, s32 i);
u8* func_001a1658(u32 m, s32 a);  // state_dispatch_0_1_14
void func_001a17c8(u8* c);
u32 func_00281420(void);
u32 func_002814b0(s32 i);
u16* func_001a8110(u16* it);
s32 func_00285d18(u8 a);
s32 func_001a3570_59f0(u16 id) asm("func_001a3570");
void ucall_2859f0(void) asm("_Z16u_call0_002859f0v");

static inline void MarkFresh(u32* have, u32 id) {
    if (id && !(have[id >> 5] & (1 << (id & 31)))) {
        u32* f = D_0035f2e4.p->fresh;
        f += id >> 5;
        *f |= 1 << (id & 31);
    }
}

static inline void MarkSeen(u32* have, u32 id) {
    if (!(have[id >> 5] & (1 << (id & 31)))) {
        u32* f = D_0035f2e4.p->seen;
        f += id >> 5;
        *f |= 1 << (id & 31);
    }
}

// Flag equipment/items the player now holds that were not owned before.
void ucall_2859f0(void);  // 0x002859f0: definition moved into src/anon/unit_002853b8.cpp

// ---- 002b47a0
struct VObj2b4 { void (**vt)(VObj2b4*); };
struct Heap2b4 { void (**vt)(Heap2b4*, void*); };
extern s32 D_0035f648, D_0035f640, D_0035f644;
extern u32 D_0035f6cc;
extern void* D_0035f64c;
extern void* D_0035f650;
extern VObj2b4* D_0035f654;
extern VObj2b4* D_0035f658;
extern void* D_0035f65c;
extern void* D_0035f660;
extern u32 D_0035f680[4];
extern u32 D_0035f690[3][4];
extern VObj2b4* D_0035f664;
extern VObj2b4* D_0035f668;
extern void* D_0035f66c;
extern void* D_0035f670;
extern VObj2b4* D_0035f674;
extern void* D_0035f678;
extern VObj2b4* D_0035f67c;
extern VObj2b4* D_0035f6c0;
extern void* D_0035f6c4;
extern void* D_0035f6c8;
extern Heap2b4* D_0032ba14_47a0 asm("D_0032ba14");
void SelectDtor2b4(void* p) asm("_ZN2Tz6SelectD1Ev");
void func_00288c20(void* p);
void DeleteArr2b4(void* p) asm("_ZdaPv");
void func_0028fdd0(void* p);
void func_00290300(void* p);
void func_0028ba80(void* p);
void func_00258ce8(s32 a);
void func_0028f3e8(void);
void func_002639f8(void);
void func_0023fdc0(void);
void func_00233e58(void);
void func_0014a4c0(void);

void ttarget_2b47a0(void) asm("_Z17ttarget0_002b47a0v");

// Tear down everything the memory-card menu created.
void ttarget_2b47a0(void);  // 0x002b47a0: definition moved into src/anon/unit_002b3ac8.cpp

// ---- 002fe0c0
typedef int qs_cmp_t(const void*, const void*);
#define min(a, b) (a) < (b) ? a : b
#define swapcode(TYPE, parmi, parmj, n) { \
    long i = (n) / sizeof (TYPE); \
    register TYPE *pi = (TYPE *) (parmi); \
    register TYPE *pj = (TYPE *) (parmj); \
    do { \
        register TYPE t = *pi; \
        *pi++ = *pj; \
        *pj++ = t; \
    } while (--i > 0); \
}
#define SWAPINIT(a, es) swaptype = ((char *)a - (char *)0) % sizeof(long) || \
    es % sizeof(long) ? 2 : es == sizeof(long)? 0 : 1;
static inline __attribute__((always_inline)) void qs_swapfunc(char *a, char *b, int n, int swaptype)
{
    if (swaptype <= 1)
        swapcode(long, a, b, n)
    else
        swapcode(char, a, b, n)
}
#define swap(a, b) \
    if (swaptype == 0) { \
        long t = *(long *)(a); \
        *(long *)(a) = *(long *)(b); \
        *(long *)(b) = t; \
    } else \
        qs_swapfunc(a, b, es, swaptype)
#define vecswap(a, b, n) if ((n) > 0) qs_swapfunc(a, b, n, swaptype)
static inline __attribute__((always_inline)) char *qs_med3(char *a, char *b, char *c, qs_cmp_t *cmp)
{
    return cmp(a, b) < 0 ?
           (cmp(b, c) < 0 ? b : (cmp(a, c) < 0 ? c : a ))
          :(cmp(b, c) > 0 ? b : (cmp(a, c) < 0 ? a : c ));
}
// newlib qsort (med3/swapfunc inlined)
void qsort_2fe0c0(void *a, unsigned int n, unsigned int es, qs_cmp_t *cmp) asm("qsort");
void qsort_2fe0c0(void *a, unsigned int n, unsigned int es, qs_cmp_t *cmp);  // 0x002fe0c0: definition moved into src/newlib/libc/qsort.c
#undef min
#undef swapcode
#undef SWAPINIT
#undef swap
#undef vecswap

// ---- 003191f8
extern u8 D_01e4c7b8;
extern u8 D_01e4c7b9;
extern u8 D_01e4c7ba;
extern u8 D_01e4c7bb;
extern u8 D_01e4c7bc;
extern u8 D_01e4c7bd;
extern u8 D_01e4c7be;
extern u8 D_01e4c7bf;
extern u8 D_01e4c7c0;
extern u8 D_01e4c7c1;
extern u8 D_01e4c7c2;
extern u8 D_01e4c7c3;
extern u8 D_01e4c7c4;
extern u8 D_01e4c7c5;
extern u8 D_01e4c7c6;
extern u8 D_01e4c7c7;
extern u8 D_01e4c7c8;
extern u8 D_01e4c7c9;
extern u8 D_01e4c7ca;
extern u8 D_01e4c7cb;
extern u8 D_01e4c7cc;
extern u8 D_01e4c7cd;
extern u8 D_01e4c7ce;
extern u8 D_01e4c7cf;
extern u8 D_01e4c7d0;
extern u8 D_01e4c7d1;
extern u8 D_01e4c7d2;
extern u8 D_01e4c7d3;
extern u8 D_01e4c7d4;
extern u8 D_01e4c7d5;
extern u8 D_01e4c7d6;
extern u8 D_01e4c7d7;
extern u8 D_01e4c7d8;
extern u8 D_01e4c7d9;
extern u8 D_01e4c7da;
extern u8 D_01e4c7db;
extern u8 D_01e4c7dc;
extern u8 D_01e4c7dd;
extern u8 D_01e4c7de;
extern u8 D_01e4c7df;
extern u8 D_01e4c7e0;
extern u8 D_01e4c7e1;
extern u8 D_01e4c7e2;
extern u8 D_01e4c7e3;
extern u8 D_01e4c7e4;
extern u8 D_01e4c7e5;
extern u8 D_01e4c7e6;
extern u8 D_01e4c7e7;
extern u8 D_01e4c7e8;
extern u8 D_01e4c7e9;
extern u8 D_01e4c7ea;
extern u8 D_01e4c7eb;
extern u8 D_01e4c7ec;
extern u8 D_01e4c7ed;
extern u8 D_01e4c7ee;
extern u8 D_01e4c7ef;
extern u8 D_01e4c7f0;
extern u8 D_01e4c7f1;
extern u8 D_01e4c7f2;
extern u8 D_01e4c7f3;
extern u8 D_01e4c7f4;
extern u8 D_01e4c7f5;
extern u8 D_01e4c7f6;
extern u8 D_01e4c7f7;
extern u8 D_01e4c7f8;
extern u8 D_01e4c7f9;
extern u8 D_01e4c7fa;
extern u8 D_01e4c7fb;
extern u8 D_01e4c7fc;
extern u8 D_01e4c7fd;
extern u8 D_01e4c7fe;
extern u8 D_01e4c7ff;
extern u8 D_01e4c800;
extern u8 D_01e4c801;
extern u8 D_01e4c802;
extern u8 D_01e4c803;
extern u8 D_01e4c804;
extern u8 D_01e4c805;
extern u8 D_01e4c806;
extern u8 D_01e4c807;
extern u8 D_01e4c808;
extern u8 D_01e4c809;
extern u8 D_01e4c80a;
extern u8 D_01e4c80b;
extern u8 D_01e4c80c;
extern u8 D_01e4c80d;
extern u8 D_01e4c80e;
extern u8 D_01e4c80f;
extern u8 D_01e4c810;
extern u8 D_01e4c811;
extern u8 D_01e4c812;
extern u8 D_01e4c813;
extern u8 D_01e4c814;
extern u8 D_01e4c815;
extern u8 D_01e4c816;
extern u8 D_01e4c817;
extern u8 D_01e4c818;
extern u8 D_01e4c819;
extern u8 D_01e4c81a;
extern u8 D_01e4c81b;
extern u8 D_01e4c81c;
extern u8 D_01e4c81d;
extern u8 D_01e4c81e;
extern u8 D_01e4c81f;
extern u8 D_01e4c820;
extern u8 D_01e4c821;
extern u8 D_01e4c822;
extern u8 D_01e4c823;
extern u8 D_01e4c824;
extern u8 D_01e4c825;
extern u8 D_01e4c826;
extern u8 D_01e4c827;
extern u8 D_01e4c828;
extern u8 D_01e4c829;
extern u8 D_01e4c82a;
extern u8 D_01e4c82b;
extern u8 D_01e4c82c;
extern u8 D_01e4c82d;
extern u8 D_01e4c82e;
extern u8 D_01e4c82f;
extern u8 D_01e4c830;
extern u8 D_01e4c831;
extern u8 D_01e4c832;
extern u8 D_01e4c833;
extern u8 D_01e4c834;
extern u8 D_01e4c835;
extern u8 D_01e4c836;
extern u8 D_01e4c837;
extern u8 D_01e4c838;
extern u8 D_01e4c839;
extern u8 D_01e4c83a;
extern u8 D_01e4c83b;
extern u8 D_01e4c83c;
extern u8 D_01e4c83d;
extern u8 D_01e4c83e;
extern u8 D_01e4c83f;
extern u8 D_01e4c840;
extern u8 D_01e4c841;
extern u8 D_01e4c842;
extern u8 D_01e4c843;
extern u8 D_01e4c844;
extern u8 D_01e4c845;
extern u8 D_01e4c846;
extern u8 D_01e4c847;
extern u8 D_01e4c848;
extern u8 D_01e4c849;
extern u8 D_01e4c84a;
extern u8 D_01e4c84b;
extern u8 D_01e4c84c;
extern u8 D_01e4c84d;
extern u8 D_01e4c84e;
extern u8 D_01e4c84f;
extern u8 D_01e4c850;
extern u8 D_01e4c851;
extern u8 D_01e4c852;
extern u8 D_01e4c853;
extern u8 D_01e4c854;
extern u8 D_01e4c855;
extern u8 D_01e4c856;
extern u8 D_01e4c857;
extern u8 D_01e4c858;
extern u8 D_01e4c859;
extern u8 D_01e4c85a;
extern u8 D_01e4c85b;
extern u8 D_01e4c85c;
extern u8 D_01e4c85d;
extern u8 D_01e4c85e;
extern u8 D_01e4c85f;
extern u8 D_01e4c860;
extern u8 D_01e4c861;
extern u8 D_01e4c862;
extern u8 D_01e4c863;
extern u8 D_01e4c864;
extern u8 D_01e4c865;
extern u8 D_01e4c866;
extern u8 D_01e4c867;
void func_003191f8(void);  // 0x003191f8: definition moved into src/libgcc/unwind-dw2.c

// ---- 002fac40
f32 scalbnf(f32, s32);  // float_round_abs
f32 floorf(f32);
extern const s32 D_003776e0[];
extern const f32 D_003776f0[];
static const f32 zero_krp = 0.0f, one_krp = 1.0f, two8 = 2.5600000000e+02f, twon8 = 3.9062500000e-03f;
// fdlibm/newlib __kernel_rem_pio2f (scalbnf is scalbnf, floorf is floorf).
s32 __kernel_rem_pio2f(f32 *x, f32 *y, s32 e0, s32 nx, s32 prec, const s32 *ipio2);  // 0x002fac40: definition moved into src/newlib/libm/kf_rem_pio2.c

// ---- 002f9e78
f32 __ieee754_sqrtf(f32 x);
f32 fabsf(f32 x);  // fabsf
f32 scalbnf(f32 x, s32 n);  // float_round_abs
extern const f32 D_003771b0[];
extern const f32 D_003771b8[];
extern const f32 D_003771c0[];
typedef union { f32 value; u32 word; } FloatShapePw;
#define GET_FLOAT_WORD_PW(i, d) do { FloatShapePw gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD_PW(d, i) do { FloatShapePw sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
#define bp D_003771b0
#define dp_h D_003771b8
#define dp_l D_003771c0
static const f32
zero_pw =  0.0,
one_pw  =  1.0,
two_pw  =  2.0,
two24_pw =  16777216.0,
huge_pw =  1.0e30,
tiny_pw =  1.0e-30,
L1_pw  =  6.0000002384e-01,
L2_pw  =  4.2857143283e-01,
L3_pw  =  3.3333334327e-01,
L4_pw  =  2.7272811532e-01,
L5_pw  =  2.3066075146e-01,
L6_pw  =  2.0697501302e-01,
P1_pw   =  1.6666667163e-01,
P2_pw   = -2.7777778450e-03,
P3_pw   =  6.6137559770e-05,
P4_pw   = -1.6533901999e-06,
P5_pw   =  4.1381369442e-08,
lg2_pw  =  6.9314718246e-01,
lg2_h_pw  =  6.93145752e-01,
lg2_l_pw  =  1.42860654e-06,
ovt_pw =  4.2995665694e-08,
cp_pw    =  9.6179670095e-01,
cp_h_pw  =  9.6179199219e-01,
cp_l_pw  =  4.7017383622e-06,
ivln2_pw    =  1.4426950216e+00,
ivln2_h_pw  =  1.4426879883e+00,
ivln2_l_pw  =  7.0526075433e-06;

// fdlibm/newlib __ieee754_powf, EE build (_FLT_NO_DENORMALS, _FLT_LARGEST_EXPONENT_IS_NORMAL).
f32 powf_2f9e78(f32 x, f32 y) asm("_Z14__ieee754_powfPv");
f32 powf_2f9e78(f32 x, f32 y);  // 0x002f9e78: definition moved into src/newlib/libm/ef_pow.c
#undef bp
#undef dp_h
#undef dp_l

// ---- 00107a90
extern u8 D_003a7b70[];
extern u8 D_003a7f70[];
void func_00106998(s32);
void func_001069b8(s32);  // swap_global_word
void func_001069f8(s32);
void func_00106d40(void*, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32);
void func_00106de8(void*, s32, f32);
void func_00107330(void*, f32, f32, f32);
void func_00107340(void*, f32, f32, f32);
void func_00107350(void*, f32, f32, f32);
void func_00107360(void*, f32);
// 00107a90: moved to src/naka/libkn/camera.cpp

// ---- 00157c88
void func_001396b0(Sub4*);
void func_0031a260(Sub4*, s32);
void func_00156408(u8*);
s32 func_00156010(u8*);
s32 func_00156030(u8*);
s32 func_00156058(u8*);  // state_code_is_2
s32 func_00156080(u8*);  // state_code_is_3
void func_00155d80(u8*);
void func_001560a8(u8*, s32*, s32*);
void func_00155cb0(u8*, s32, s32);
s32 func_00155e30(u8*);
void func_00138c10_7c88(u8*, s32) asm("func_00138c10");
void func_00139598(u8*);
void func_00155bf0(u8*, u8);
s32 func_00105300(void);
void func_002ba2e8(s32, s32);
void func_001395a8(u8*);
u32 func_00158290(u8*);
u32 func_0013a7e8(s32);
u32 func_0013d7e0(void);
s32 func_00139c18(u8*);
s32 func_00139d78_7c88(Sub4*) asm("func_00139d78");
void func_001386e0_7c88(Sub4*, s32, u32, u32, s32, u32) asm("func_001386e0");
// 00157c88: moved to src/anon/unit_00157688.cpp

// ---- 001823d0
extern s32 D_0034ecd0;
extern s32 D_0034ecd4;
extern s32 D_0034ecec;
extern s32 D_0034ecf0;
extern s32 D_0034ece4;
extern s64 D_0034ecc0;
extern s64 D_0034ecc8;
extern s32 D_0034ecdc;
extern s32 D_0034ecd8;
extern s32 D_0034ece8;
extern s32 D_0034ece0;
extern u32 D_0034ecf4;
extern f32 D_01c6053c;
extern s32 D_01c60540;
extern s64 D_01c60548;
extern s64 D_01c60550;
extern s32 D_01c60558;
extern const char D_0036c878[];
extern const char D_0036c880[];
extern const char D_0036c888[];
extern u8 D_0034f250[];
extern u8 D_0034fa78[];
void func_00182df0(void);
u8* func_00168b88(u32, s32, u32, s32);  // find_entry16_by_half_word
void func_00181cc0(u32, u16);
void func_001955a8(void*, s32);
void func_001c0a00(s32);
#define FCC_3d0(s) ((s)[0] | ((s)[1] << 8) | ((s)[2] << 16) | ((s)[3] << 24))
// 001823d0: moved to src/yasui/libys/areadata.cpp
#undef FCC_3d0

// ---- 002f9bc0
typedef union { f32 value; u32 word; } FloatShapeLg;
#define GET_FLOAT_WORD_LG(i, d) do { FloatShapeLg gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD_LG(d, i) do { FloatShapeLg sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
static const f32
ln2_hi_lg =   6.9313812256e-01,
ln2_lo_lg =   9.0580006145e-06,
two25_lg =    3.355443200e+07,
Lg1_lg = 6.6666668653e-01,
Lg2_lg = 4.0000000596e-01,
Lg3_lg = 2.8571429849e-01,
Lg4_lg = 2.2222198546e-01,
Lg5_lg = 1.8183572590e-01,
Lg6_lg = 1.5313838422e-01,
Lg7_lg = 1.4798198640e-01;
static const f32 zero_lg = 0.0;

// fdlibm/newlib __ieee754_logf, EE build (_FLT_NO_DENORMALS, _FLT_LARGEST_EXPONENT_IS_NORMAL).
f32 logf_2f9bc0(f32 x) asm("_Z14__ieee754_logfjjjj");
f32 logf_2f9bc0(f32 x);  // 0x002f9bc0: definition moved into src/newlib/libm/ef_log.c

// ---- 001620a8
void func_00107888(void);
void func_001433e8(void);
void func_00144250(void);
void func_0014df48(void);
void func_0015de18(void);
void func_00161868(void);
void func_00161880(void);
void func_001618a0(void);
void func_00161a10(void);
void func_00161a28(void);
void func_00161a40(void);
void func_00161c70(void);
void func_00167228(void);
void func_001dd2b8(void);
void func_001dd920(void);
void func_00106998(s32);
u8* func_00102c18(s32, s32, void (*)(void));
void func_001620a8(void);  // 0x001620a8: definition moved into src/anon/unit_001614e8.cpp

// ---- 002c3e58
typedef void (*VFn58)(void*);
#define VCALL5_e58(o) ((VFn58)(*(void***)(o))[5])(o)
void func_00236d60(void);  // clear_64_entries_24
void func_002c3368_3e58(u8*) asm("func_002c3368");
void func_002c34d0_3e58(u8*) asm("func_002c34d0");
s32 func_00139d78_3e58(u8*) asm("func_00139d78");
s32 func_00139538(u8*);
s32 func_0028acc8(u32);
void func_0028abe0(u32);
s32 func_002c5120(u8*);
void func_00139510(u8*);
void func_002c85c8(u32);
s32 func_0023f0c0_3e58(u8*) asm("func_0023f0c0");
s32 func_002c3240(u8*, s32);
void func_002c3638(u8*);
void func_002c3c90(u8*);
void func_002c3e58(u8* p);  // 0x002c3e58: definition moved into src/anon/unit_002c3c90.cpp
#undef VCALL5_e58

// ---- 002f97c8
typedef union { f32 value; u32 word; } FloatShapeEx;
#define GET_FLOAT_WORD_EX(i, d) do { FloatShapeEx gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD_EX(d, i) do { FloatShapeEx sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
extern const f32 D_003770c8[];
extern const f32 D_003770d8[];
extern const f32 D_003770e0[];
#define halF_ex D_003770c8
#define ln2HI_ex D_003770d8
#define ln2LO_ex D_003770e0
static const f32
one_ex = 1.0,
huge_ex = 1.0e+30,
twom100_ex = 7.8886090522e-31,
invln2_ex = 1.4426950216e+00,
P1_ex = 1.6666667163e-01,
P2_ex = -2.7777778450e-03,
P3_ex = 6.6137559770e-05,
P4_ex = -1.6533901999e-06,
P5_ex = 4.1381369442e-08,
ln2HI0_ex = 6.9313812256e-01,
ln2LO0_ex = 9.0580006145e-06;

// fdlibm/newlib __ieee754_expf, EE build (_FLT_NO_DENORMALS, _FLT_LARGEST_EXPONENT_IS_NORMAL).
f32 expf_2f97c8(f32 x) asm("_Z14__ieee754_expfjjjj");
f32 expf_2f97c8(f32 x);  // 0x002f97c8: definition moved into src/newlib/libm/ef_exp.c
#undef halF_ex
#undef ln2HI_ex
#undef ln2LO_ex

// ---- 002fb558
typedef union { f32 value; u32 word; } FloatShapeTn;
#define GET_FLOAT_WORD_TN(i, d) do { FloatShapeTn gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD_TN(d, i) do { FloatShapeTn sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
f32 fabsf(f32 x);  // fabsf
static const f32
one_tn   =  1.0000000000e+00,
pio4_tn  =  7.8539812565e-01,
pio4lo_tn =  3.7748947079e-08,
T_tn[] = {
  3.3333334327e-01,
  1.3333334029e-01,
  5.3968254477e-02,
  2.1869488060e-02,
  8.8632395491e-03,
  3.5920790397e-03,
  1.4562094584e-03,
  5.8804126456e-04,
  2.4646313977e-04,
  7.8179444245e-05,
  7.1407252108e-05,
 -1.8558637748e-05,
  2.5907305826e-05,
};

// fdlibm/newlib __kernel_tanf (fabsf is fabsf).
f32 __kernel_tanf(f32 x, f32 y, s32 iy);  // 0x002fb558: definition moved into src/newlib/libm/kf_tan.c

// ---- 001219b8
void func_001217a0(u8*, u32, u32, u32, u32);
void func_00134408(void);
void func_00134428(s32, u64);
void func_00134450(s32);
u32 func_00109f58(s32, u32, u8);
u32 func_00109ea8(s32, u32, u8);
u32 func_0010ae90(void);  // get_table_34ed8
void func_00108ae0(u32, s32, u64, u64, u32, u32, s32, s32);
void func_00109670(void);
void func_001219b8(u8* p, u32 a1, u32 a2, u8* q, u32 a4, u8 flag, u32 a6, u32 a7);  // 0x001219b8: definition moved into src/anon/unit_00120520.cpp

// ---- 002f8420
typedef union { f32 value; u32 word; } FloatShapeAt;
#define GET_FLOAT_WORD_AT(i, d) do { FloatShapeAt gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
f32 fabsf(f32 x);  // fabsf
extern const f32 D_00376ed8[];
extern const f32 D_00376ee8[];
#define atanhi_at D_00376ed8
#define atanlo_at D_00376ee8
static const f32 atanhi3_at = 1.5707962513e+00, atanlo3_at = 7.5497894159e-08;
static const f32 aT_at[] = {
  3.3333334327e-01,
 -2.0000000298e-01,
  1.4285714924e-01,
 -1.1111110449e-01,
  9.0908870101e-02,
 -7.6918758452e-02,
  6.6610731184e-02,
 -5.8335702866e-02,
  4.9768779427e-02,
 -3.6531571299e-02,
  1.6285819933e-02,
};
static const f32 one_at = 1.0, huge_at = 1.0e30;

// fdlibm/newlib atanf (fabsf is fabsf), EE build.
f32 atanf(f32 x);  // 0x002f8420: definition moved into src/newlib/libm/sf_atan.c
#undef atanhi_at
#undef atanlo_at

// ---- 002c4e98
struct Init5_98 { u8* obj; u32 w[4]; };
struct La98 { u8 d[32]; };
struct Ent98 { u8 pad[24]; u32 a; u32 b; };
extern u8 D_01e2bd30[];
extern u8 D_01e2bd20[];
extern Ent98 D_00375630[];
s32 func_002cb200(u8*, u8, u8*);
void func_0023f800(La98*);
u32 func_001708f8_4e98(u32, s32) asm("func_001708f8");
void func_0023fa08(La98*, u32);
u32 func_0023f948(La98*, s32);
u32 func_0023f908(La98*, s32);
u32 func_002c3240_4e98(u8*, s32) asm("func_002c3240");
void func_0023eea0(u8*, s32, u32, u32, u32, s32);
void func_0023ef50(u8*);
void func_0023f0c8(u8*, u32);
u8* func_0023f1b0_4e98(u8*) asm("func_0023f1b0");
u32 func_0023c4b8_4e98(u8*, s32) asm("func_0023c4b8");
u32 func_00236ca8_4e98(u32, s32) asm("func_00236ca8");
s32 func_002c5120(u8*);
void func_002cb0e8_4e98(Init5_98*, u8*, f32) asm("func_002cb0e8");
void func_002c44b8(u8*);
void func_002c4ca8(u8*);
u32 func_002c3268_4e98(u8*) asm("func_002c3268");
void func_0023f1e0_4e98(u8*, s32, u8*, u32, Ent98*, u32, s32, s32) asm("func_0023f1e0");
void func_00139620(u8*);
void func_001395e8_4e98(u8*) asm("func_001395e8");
void func_001395f8(u8*);
void func_0023f6c0_4e98(u8*, u32) asm("func_0023f6c0");
u32 func_002c24e0(u32);
u32 func_002c2518(u32);
void func_0023f618(u8*, u32);
void func_00139638_4e98(u8*) asm("func_00139638");
void func_001391c8_4e98(u8*, s32, s32) asm("func_001391c8");
void func_0023f848(La98*);
void func_002c4e98(u8* p, u32 res, Init5_98* arg);  // 0x002c4e98: definition moved into src/anon/unit_002c4ca8.cpp

// ---- 0013c820
u32 func_0013b5d0(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, f32);
void func_00139570_c820(u32) asm("func_00139570");
void func_0013c820(u32 a0, u32 a1);  // 0x0013c820: definition moved into src/anon/unit_0013a8b8.cpp

// ---- 00176818
void func_0017f540(u8*, u32, f32, f32);
void func_001842c0(u8*);
// 00176818: moved to src/yasui/libys/party.cpp

// ---- 0017c108
static inline __attribute__((always_inline)) void h_0017c108(u8* q, u32 f, u32 v) {
    if ((f & 4) || ((f & 0x10) && v)) func_0017f540(q, v, 8.0f, 0.0f);
}
// 0017c108: moved to src/anon/unit_0017bf40.cpp

// ---- 001d5cd0
s32 func_001d6ec8();
s32 func_001d5b78(u32, u32);
struct G_001d5cd0 { u8 pad[4150]; u8 c; };
extern G_001d5cd0 D_0032e020;
s32 func_001d5cd0();  // 0x001d5cd0: definition moved into src/anon/unit_001d4f40.cpp

// ---- 001d79b8
struct E_001d79b8 { s32 key; f32 v; };
struct P_001d79b8 { u32 x; E_001d79b8 e[4]; };
void func_001d7b10(P_001d79b8*);
void func_001d79b8(P_001d79b8* p, s32 key, f32 v);  // 0x001d79b8: definition moved into src/anon/unit_001d7458.cpp

// ---- 001ddd30
struct Nd_001ddd30 { u8 pad[20]; Nd_001ddd30* next; };
extern Nd_001ddd30* D_01d9e348;
static inline Nd_001ddd30* Next_001ddd30(Nd_001ddd30* n) { if (!n) return D_01d9e348; return n->next; }
static inline bool Has_001ddd30(Nd_001ddd30* x) {
    Nd_001ddd30* n = 0;
    while ((n = Next_001ddd30(n))) { if (n == x) return true; }
    return false;
}
void func_001dde40_dd30(Nd_001ddd30*) asm("func_001dde40");
void func_001ddd30(Nd_001ddd30* a0);  // 0x001ddd30: definition moved into src/anon/unit_001ddcf0.cpp

// ---- 002e7518
struct Nd_002e7518 { Nd_002e7518* next; };
extern Nd_002e7518* D_01e2bf00;
void func_002e73d8(Nd_002e7518*);
static inline Nd_002e7518* Next_002e7518(Nd_002e7518* n) { if (!n) return D_01e2bf00; return n->next; }
void wt_002e7518() asm("_Z16wtarget_002e7518jjjj");
void wt_002e7518();  // 0x002e7518: definition moved into src/anon/unit_002e5f70.cpp

// ---- 001b9bc8
extern u8* D_01d48da0;
s32 func_0019baa8(u8*);
static inline u8* Next_001b9bc8(u8* n) { if (!n) return D_01d48da0; return *(u8**)(n + 2228); }
u8* ct_001b9bc8(u8* p) asm("_Z16ctarget_001b9bc8jjjj");
u8* ct_001b9bc8(u8* p);  // 0x001b9bc8: definition moved into src/anon/unit_001b9880.cpp

// ---- 00304f50
struct Reent_00304f50 { s32 _errno; };
extern s32 D_00378ae4;
s32 func_00305be8(u32, u32, u32);
long func_00304f50(Reent_00304f50* ptr, u32 a, u32 b, u32 c);  // 0x00304f50: definition moved into src/newlib/libc/writer.c

} // extern "C"
// ---- 001b3208
namespace YS {
struct OEnt_001b3208 { s32 id; u32 y; };
struct OTab_001b3208 { u32 x; s32 n; OEnt_001b3208 e[1]; };
union OFl_001b3208 { u32 f; OTab_001b3208* t; };
struct OObj_001b3208 { u8 pad[128]; OFl_001b3208* p; u8 pad2[12]; };
struct OBJOCC { OTab_001b3208* tab; OObj_001b3208* objs; void disable(int); };
// 0x001b3208: definition moved into src/anon/unit_001b2780.cpp
}
extern "C" {

// ---- 001055b8
s32 func_001055b8(void* a0) {
    // Hand-written longjmp in the original.
    asm volatile(
        "lq $28, 0(%0)\n\tlq $29, 16(%0)\n\tlq $30, 32(%0)\n\tlq $31, 48(%0)\n\t"
        "lq $16, 64(%0)\n\tlq $17, 80(%0)\n\tlq $18, 96(%0)\n\tlq $19, 112(%0)\n\t"
        "lq $20, 128(%0)\n\tlq $21, 144(%0)\n\tlq $22, 160(%0)\n\tlq $23, 176(%0)\n\t"
        "lwc1 $f20, 192(%0)\n\tlwc1 $f21, 196(%0)\n\tlwc1 $f22, 200(%0)\n\tlwc1 $f23, 204(%0)\n\t"
        "lwc1 $f24, 208(%0)\n\tlwc1 $f25, 212(%0)\n\tlwc1 $f26, 216(%0)\n\tlwc1 $f27, 220(%0)\n\t"
        "lwc1 $f28, 224(%0)\n\tlwc1 $f29, 228(%0)\n\tlwc1 $f30, 232(%0)\n\tlwc1 $f31, 236(%0)"
        : : "r"(a0));
    return 1;
}

// ---- 00123c20
extern u8 D_00347a90[];
void func_0011f3b8(u8*);
void func_0011ee58(u32*);  // set_vtbl_347940
struct NoTail_00123c20 { ~NoTail_00123c20() {} };
void func_00123c20(u32* p);  // 0x00123c20: definition moved into src/anon/unit_00123990.cpp

// ---- 001fb720
void func_001fa950(u8*, u8*, u8*);
union UH_001fb720 { u16 h; f32 f; };
void func_001fb720(u8* a0, u8* a1, u8* a2);  // 0x001fb720: definition moved into src/anon/unit_001fb350.cpp

// ---- 00294f00
extern bool D_0035f580;
extern bool D_0035f581;
void func_00294e48();
void func_00294f78(u32);
void func_00294f00();  // 0x00294f00: definition moved into src/anon/unit_00292e60.cpp

// ---- 0029a368
extern bool D_0035f5a8;
extern bool D_0035f5a9;
void func_0029a2a0();
void func_0029a3e0(u32);
void func_0029a368();  // 0x0029a368: definition moved into src/anon/unit_00299920.cpp

// ---- 00123c98
void func_00106420_3c98(u32*) asm("func_00106420");
void func_00123c98(u32* p);  // 0x00123c98: definition moved into src/anon/unit_00123990.cpp

// ---- 00143520
struct S_00143520 { u8 pad[48]; Vec4 pos; u8 pad2[32]; s16 h96, h98, h100; u8 pad3[6]; f32 f108; u8 pad4[8]; u32 w120; u8 pad5[20]; };
void func_0031b9e0(S_00143520*);
void func_00143648(S_00143520*, u32);
void func_00143520(Vec4* v, u32 a1);  // 0x00143520: definition moved into src/anon/unit_00142c90.cpp

// ---- 00197318
void func_00170320(u32);
void func_00196e88_7318(u32*, u32, u32, f32) asm("func_00196e88");
union UH_00197318 { u16 h; u32 i; };
void func_00197318(u32* p);  // 0x00197318: definition moved into src/anon/unit_00195d00.cpp

// ---- 001b5ef0
extern u32 D_00351214;
union UDf_001b5ef0 { u8* p; void (*f)(); u32 i; };
extern UDf_001b5ef0 D_00351180;
extern u8 D_00351ec0[];
void func_001b5f68();
void func_001b5fe0();
u8* func_00102818(u32, u32, u32, void (*)(), u32);
void func_001c8d80(u8*, u32);
void func_001b5ef0(u8* p);  // 0x001b5ef0: definition moved into src/anon/unit_001b2780.cpp

// ---- 001c3670
struct E_001c3670 { u16 id; u8 pad[6]; };
struct T_001c3670 { u32 x; s32 n; E_001c3670 e[1]; };
extern T_001c3670* D_01d49560;
extern u32 D_0032fca8[];
void func_001c3670(u32 id);  // 0x001c3670: definition moved into src/anon/unit_001c2b58.cpp

// ---- 001b14d8
struct T2_001b14d8 { u32 a, b; };
extern T2_001b14d8 D_01d44100;
struct Sub_001b14d8 { u8 pad[640]; s32 arr[16]; };
extern Sub_001b14d8 D_01d44108;
extern s32 D_01d443c8;
extern u8 D_00350e8c;
void func_001b1560();
void func_001b18e8();
u8* func_00102c18_14d8(u32, u32, void (*)()) asm("func_00102c18");
// 001b14d8: moved to src/anon/unit_001b14d8.cpp

// ---- 001de590
extern u8* D_00352b58;
s32 func_001dc9e0(u8*);
void f1de590_update(u8*) asm("func_001dfa38");
void func_001de590(u8* p);  // 0x001de590: definition moved into src/anon/unit_001ddcf0.cpp

// ---- 0022e368
union UA_0022e368 { s32 i; s16 s; u16 h; };
struct E_0022e368 { UA_0022e368 a; UA_0022e368 b; UA_0022e368 c; UA_0022e368 d; u8 pad2[30]; u16 e; u8 pad3[4]; };
union UG_0022e368 { E_0022e368* p; s32 i; u16 h; };
extern UG_0022e368 D_0035dcf4_e368 asm("D_0035dcf4");
void func_0022e368(UA_0022e368* a0);  // 0x0022e368: definition moved into src/anon/unit_0022d358.cpp

// ---- 002aaa38
struct B_002aaa38 { u8 pad[132]; u32 bits[1]; };
extern B_002aaa38* D_0035f610;
static inline bool Bit_002aaa38(u32* b, u32 i) { b += i >> 5; return (*b & (1 << (i & 31))) != 0; }
bool f_002aaa38(s32 n) asm("func_002aaa38");
bool f_002aaa38(s32 n);  // 0x002aaa38: definition moved into src/anon/unit_002a99c8.cpp

// ---- 002e0698
extern u8* D_00361f60;
struct VT_002e0698 { u8 pad[48]; u32 (*f)(void*); };
void func_00180c88(u8*, u32, f32);
s32 func_00197920();
void func_001d86a0(s32, u32);
void func_002dd4f8(u8*);
void func_002e0698(VT_002e0698** o, u8* p);  // 0x002e0698: definition moved into src/anon/unit_002de3c8.cpp

// ---- 002eb6f8
u8* func_002eaf40(u8*);
void func_0017f488(u8*, s32, f32, f32);
// 002eb6f8: moved to src/anon/unit_002eaf38.cpp

// ---- 0011f4b8
union UC_0011f4b8 { u16 h; u32 i; };
void func_0011ee18(u8*);  // obj_ctor_347940
extern u8 D_003479a8[];
void func_0011f4b8(u8* p);  // 0x0011f4b8: definition moved into src/anon/unit_0011c128.cpp

// ---- 00142bf8
void func_0014ed28(u32, s32);
void func_00142bf8(u8* p);  // 0x00142bf8: definition moved into src/anon/unit_00141458.cpp

// ---- 00180378
void func_0017f380(u8*);  // obj_walk_children
u32 func_0017ec98(u8*, u32);
u32 func_0017edf0(u8*, u32);
void func_001801b0(u32, u32, u32, u8*, u32, f32);
void func_00180378(u8* p, u8* a1, u32 a2, f32 x);  // 0x00180378: definition moved into src/anon/unit_00180408.cpp

// ---- 001b1a30
struct C4_001b1a30 { u8 r, g, b, a; };
f32* func_0015cc70();
// 001b1a30: moved to src/anon/unit_001b14d8.cpp

// ---- 001c0150
struct L_001c0150 { u8* head; u8* tail; };
extern L_001c0150 D_01d49350;
void func_001c0150(u8* p, u32 a1);  // 0x001c0150: definition moved into src/anon/unit_001bff88.cpp

// ---- 00265b88
u8* func_00257770_5b88() asm("func_00257770");
s32 func_00139d78_5b88(u8*) asm("func_00139d78");
extern u32 D_0035f01c, D_0035f020;
s32 func_0028acc8(u32);
struct NoTail_00265b88 { ~NoTail_00265b88() {} };
void func_00265b88();  // 0x00265b88: definition moved into src/anon/unit_00265580.cpp

// ---- 00225550
s32 func_00224e90();
u32 func_001050c8();
u32* func_001063c0_5550(u32, u32) asm("func_001063c0");
u32 func_00170b30_5550(u32) asm("func_00170b30");
void func_00225e70(u32*, u32, u32);
union UP_00225550 { u32* p; u32 i; };
extern u32 D_0035db18_5550 asm("D_0035db18"); extern UP_00225550 D_0035dae4; extern u32 D_0035dae8;
void func_00225550();  // 0x00225550: definition moved into src/anon/unit_00224780.cpp

// ---- 0028e2a8
HeapE* func_0013a1d8();
void func_00239700_e2a8(void*) asm("func_00239700");
struct T380_0028e2a8 { T380_0028e2a8() { func_00239700_e2a8(this); } ~T380_0028e2a8() {} u8 pad[380]; };
void func_0028e2a8(u8* p, s32 n);  // 0028e2a8: moved to src/anon/unit_0028c878.cpp

// ---- 002ef7f0
s32 func_002ef7b8();
void func_002ef7a0_f7f0(u32, u32) asm("func_002ef7a0");
extern s8 D_003638c8;
// 002ef7f0: moved to src/anon/unit_002ef6b0.cpp

// ---- 00176f00
s32 func_001a1de0(u32);
s32 func_001b58a8();
u8* func_00177860(u8*);
void func_001a1d50(u32, f32);
extern f32 D_00349e10;
// 00176f00: moved to src/yasui/libys/party.cpp

// ---- 0018cd28
union UP_0018cd28 { u8* p; f32 f; };
extern UP_0018cd28 D_00352130_cd28 asm("D_00352130");
s32 func_0018ca48(u8);
// 0018cd28: moved to src/yasui/libys/damage.cpp

// ---- 001ab750
void func_001b7e68(u8*, u32);
u32 func_001aaea8(u8*, u32);
void func_001b8010(u8*, u32, u32, u32, u32, u32, u32, u32, s32, u64, s32, u64, s32, u64, u64);
void func_001b80d8_b750(u8*) asm("func_001b80d8");
void func_001ab750(u8* p, u8* q);  // 0x001ab750: definition moved into src/anon/unit_001ab598.cpp

// ---- 001d5470
u8* func_00168b38_5470(u32, s32, u32) asm("func_00168b38");
void func_001d5370(u32*, u32, s32);
union UA_001d5470 { u32 i; u16 h; u8 b; };
void func_001d5470(u32* s, u32 a1, u8* a2);  // 0x001d5470: definition moved into src/anon/unit_001d4f40.cpp

// ---- 002c0370
union UA_002c0370 { u32 i; f32 f; u8* p; };
void func_0031cc28(u8*);
void func_002c6420(u8*);
extern u8 D_00361da8[];
extern u8 D_00361a80[];
extern UA_002c0370 D_00361a70;
void func_002c0370(u8* p, u32 a1, UA_002c0370* a2);  // 0x002c0370: definition moved into src/anon/unit_002bebd0.cpp

// ---- 002fb850
f32 copysignf(f32, f32);
union FW_002fb850 { f32 f; s32 i; };
static const f32 huge_002fb850 = 1.0e+30, tiny_002fb850 = 1.0e-30;
f32 scalbnf(f32 x, s32 n);  // 0x002fb850: definition moved into src/newlib/libm/sf_scalbn.c

// ---- 001091c8
struct AlVt_001091c8 { void* (*alloc)(void*, u32, void*); };
struct Al_001091c8 { AlVt_001091c8* vt; };
union UG_001091c8 { s32 i; void* p; };
extern UG_001091c8 D_0033cc68;
extern UG_001091c8 D_0033cc64;
extern UG_001091c8 D_0033cc6c;
extern UG_001091c8 D_0033cc70;
void func_00133cf0(void*, u32);
void func_00109070();
void func_001091c8(Al_001091c8* o, s32 n, u32 sz);  // 001091c8: moved to src/anon/unit_001085a8.cpp

// ---- 00252760
void func_00287b18(u32, u32);
union UG_00252760 { u32 i; u16 h; u8* p; };
extern UG_00252760 D_0035ee9c_2760 asm("D_0035ee9c");
extern UG_00252760 D_0035eea0_2760 asm("D_0035eea0");
extern UG_00252760 D_0035eea4_2760 asm("D_0035eea4");
extern UG_00252760 D_0035eea8_2760 asm("D_0035eea8");
extern u8* D_00347f80_2760 asm("D_00347f80");
struct VT_00252760 { void* (*f)(void*, u32, u32); };
extern u8 D_00347e60[];
extern u8 D_00347e40[];
void func_00239700(u8*);
u8* func_00103eb0();
void func_00252890();
void func_00102818_2760(u32, u32, u32, void (*)(), u32) asm("func_00102818");
void func_00252760();  // 0x00252760: definition moved into src/anon/unit_00250fb8.cpp

// ---- 0028f6f0
union UG_0028f6f0 { u8* p; u32 i; };
extern UG_0028f6f0 D_0035f480;
s32 func_00139d78_f6f0(u8*) asm("func_00139d78");
s16* func_0028f690(s32);  // record884_type_index
void func_00138c10_f6f0(u8*, s32) asm("func_00138c10");
void func_0028d5d0(u8*);
void func_0028f6f0(s32 i);  // 0028f6f0: moved to src/anon/unit_0028f1e0.cpp

// ---- 00304fb0
void* _malloc_r(void*, u32);
void* func_002fde18_4fb0(void*, s32, u32) asm("func_002fde18");
void* calloc_r_00304fb0(void* ptr, u32 n, u32 elem) asm("func_00304fb0");
void* calloc_r_00304fb0(void* ptr, u32 n, u32 elem);  // 0x00304fb0: definition moved into src/newlib/libc/callocr.c

// ---- 001cedc0
void func_001780d8(u8*);
u8* func_0016b740_edc0(u32) asm("func_0016b740");
void func_001c0d38(u8*, u8*, u32, u32);
void func_0017fd30(u8*, u8*);
void func_0017f488_edc0(u8*, u32, f32, f32) asm("func_0017f488");
void func_0017f5e0(u8*, u32, u32, f32, f32);
void func_0016bd60_edc0(u8*, u32) asm("func_0016bd60");
void func_00198860(u8*, u32);
void func_001cedc0(u8* p);  // 0x001cedc0: definition moved into src/anon/unit_001ce6e8.cpp
// ---- 002f8960 (newlib sinf)
f32 func_002fb460(f32, f32, s32);  // float_to_int
f32 __kernel_cosf(f32, f32);  // float_to_int_b
s32 __ieee754_rem_pio2f(f32, f32*);
union FWs_2f8960 { f32 f; s32 i; };
f32 sinf(f32 x);  // 0x002f8960: definition moved into src/newlib/libm/sf_sin.c

// ---- 001b4c48
u8* func_00168b88_4c48(u32, u32, s32, u32) asm("func_00168b88");
static inline s32 rd4_1b4c48(s8* b) { return b[0] | (b[1] << 8) | (b[2] << 16) | (b[3] << 24); }
void func_001b4c48(u8* p, u32* out, s8* b);  // 0x001b4c48: definition moved into src/anon/unit_001b2780.cpp
// ---- 00197828
struct G197 { u8 pad[60]; u8* o; u8 pad2[80]; f32 f144; };
union U197 { G197* g; u8** p; };
extern U197 D_0035037c;
void func_0014ce60();
s32 func_00242ea8();
s32 func_00224e90();
void func_00138480(u32);
void func_001c1130(u32);  // copy_record_block_to_table
void func_002bc798();
void func_00196e88_7828(G197*, u32, u32, f32) asm("func_00196e88");
struct F197 { u16 pad; u16 b0:1; u16 b1:1; u16 b2:1; u16 b3:1; u16 b4:1; u16 b5:1; };
static inline u8 b0_197828() { return ((F197*)(*(G197* volatile*)&D_0035037c.g)->o)->b0; }
static inline u8 b5_197828() { return ((F197*)(*(G197* volatile*)&D_0035037c.g)->o)->b5; }
void func_00197828(f32 f);  // 0x00197828: definition moved into src/anon/unit_00195d00.cpp
// ---- 001cf8d0
void func_001d86a0(s32, u32);
void func_001d8820(s32);
void func_0017f488_f8d0(u8*, u32, f32, f32) asm("func_0017f488");
void func_0017f5e0(u8*, u32, u32, f32, f32);
void func_001cf8d0(u8* p, u8* a1);  // 0x001cf8d0: definition moved into src/anon/unit_001cf0b0.cpp
// ---- 0028fe38
void func_00290060(u8*, u32, u32, u32);
void func_001386e0_fe38(u32, u32, u32, u32, s32, u32) asm("func_001386e0");
void func_00259020(u32, u32, u32, u32, u32, u16*, u32, u32);
void func_0028ff00(u8*);
union UH28f { u16 h; s32 i; };
void func_0028fe38_fe38(u8* p, u32 a1, u32 a2, u32 a3) asm("func_0028fe38");
// 0028fe38: moved to src/anon/unit_0028f1e0.cpp
// ---- 0024e5b0
extern u32 D_0035edcc;
extern s8 D_0035edfc;
extern u8* D_0035ede8;
extern s32 D_0035edf4;
s32 func_002891e8(u32);
s32 func_00139d78_e5b0(u8*) asm("func_00139d78");
void func_00138c10_e5b0(u8*, u32) asm("func_00138c10");
void func_00243230(u32, s32);
void func_0024e5b0();  // 0x0024e5b0: definition moved into src/anon/unit_0024cda8.cpp
// ---- 00295158
u8* func_00294000(u32);
s32 func_002941a8(u8*);
s32 func_00276c18();
s32 func_00295158(s32 k);  // 0x00295158: definition moved into src/anon/unit_00292e60.cpp
// ---- 0029fbf0
s32 func_002943e8(u8*);
extern u8* D_0035f5d0;
void func_0029fbf0();  // 0x0029fbf0: definition moved into src/anon/unit_0029f938.cpp
// ---- 002a5d30
s32 func_002944d0(u8*);
extern u8* D_0035f5ec;
void func_002a5d30();  // 0x002a5d30: definition moved into src/anon/unit_002a5a90.cpp
// ---- 00294288
union UH_294288 { u16 h; u32 i; };
s32 func_00294268(u8*);
void func_00294288(s32 id, u32* a, u32* b);  // 0x00294288: definition moved into src/anon/unit_00292e60.cpp

// --------------------
union unaligned {
    void* ptr;
    u16 u2;
    u32 u4;
    u64 u8;
    s16 s2;
    s32 s4;
    s64 s8;
} __attribute__((__packed__));
const u8* func_00100430(const u8* p, u64* val);
const u8* func_00100468(const u8* p, s64* val);
void func_002fd160(void) __attribute__((noreturn));

const u8* func_001004c0(u8 encoding, u32 base, const u8* p, u32* val);  // 0x001004c0: definition moved into src/libgcc/unwind-dw2-fde.c

// --------------------
u32 func_001069e8(void);
void func_00140850(u8*);
void func_001403b0(u8*);
void func_0013f608(u8*);
void func_00140f30(u8*);
void func_001407d0(u8*);
void func_001408a0(u8*, u8);
void func_00140760(u8*);
void func_0015a5a8(u8*);
void func_00159070_x8002(u8*) asm("func_00159070");
void func_00159b00(u8*);
void func_00159368(u8*);
void func_00158dc0(u8*);
void func_00158708(u8*);
void func_00158658(u8*);
void func_0014e8b8(u8*);
void func_001589d0(u8*);

void wtarget_00140b68(u8* p, u8 flag) asm("_Z16wtarget_00140b68jjjj");
void wtarget_00140b68(u8* p, u8 flag);  // 0x00140b68: definition moved into src/anon/unit_0013fca8.cpp

// --------------------
extern f32 D_00349e14;  // 1.0f
struct W14aaa8 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    u8 pad[15];
    u8 alpha;
    u8 pad2[228];
    s32 count;
    s32 state;
    f32 t;
    f32 scale;
};
void wtarget_0014aaa8(W14aaa8* p) asm("_Z16wtarget_0014aaa8jjjj");
// 0x0014aaa8: definition moved into src/harata/libdk/fade.cpp

// --------------------
s32 func_00155d80_r(u8*) asm("func_00155d80");
extern s32 D_0034a8f0[];
extern s32 D_0034a8a0[];
extern s32 D_0034a8c8[];
// 00155e30: moved to src/anon/unit_00153ea0.cpp
s32 func_00155e30(u8* p);

// --------------------
struct Rel168Ent { u16 type; u16 flags; u32 pad; u32 ofs; u32 size; };
struct Rel168Hdr { u32 pad; s32 count; u32 base; u32 pad2; Rel168Ent e[1]; };
void func_0011f2f0(u32);
void func_00131e80(u32);
void func_0013a8b8(u32);
void func_001dc098(u32);
void func_00127d40(u32);
void func_001de750(u32);
void func_00168be8(Rel168Hdr* h);  // 0x00168be8: definition moved into src/anon/unit_00168aa0.cpp

// --------------------
struct Rel168eEnt { u16 type; u16 flags; u32 pad; u32 ofs; u32 size; };
struct Rel168eHdr { u32 pad; s32 count; u32 base; u32 pad2; Rel168eEnt e[1]; };
void func_0011f3b8_x8152(u32) asm("func_0011f3b8");
void func_00131f40(u32);
void func_00127da0(u32);
void func_002bc708(u32);
void func_00168e30(Rel168eHdr* h);  // 0x00168e30: definition moved into src/anon/unit_00168aa0.cpp

// --------------------
struct T16c168 { u8 pad[14]; s16 a; s16 b; s16 c; s16 d; s16 e; };
s32 func_001849b8(u8*);
T16c168* func_001aec40();
s32 func_0016a070_x8187(u8*) asm("func_0016a070");
void* func_0016c028_x8188(u8*) asm("func_0016c028");
void func_002bc188(s32, void*);
void func_0016c168(u8* obj, s32 n);  // 0x0016c168: definition moved into src/anon/unit_00169f98.cpp

// --------------------
struct T182280 { u8 pad[72]; s32 a; s32 b; s32 c; u32 flags; };
T182280* func_00198c28(s32, s32);
void func_00198e50(T182280*, u32, s32);
void func_0019ef90_x8227(void*, u8*) asm("func_0019ef90");
void func_00198e40(T182280*, s32);
void func_00198e48(T182280*, s32);
void func_00198e60(T182280*, s32, u8*);
// 00182280: moved to src/yasui/libys/areadata.cpp

// --------------------
s32 func_00301550(char*, const char*, va_list);
// 00192cc0: moved to src/yasui/libys/message.cpp

// --------------------
extern f32 D_00349e10;
struct T197028 { u8 pad[48]; s32 state; s32 wait; f32 fwait; };
s32 func_002ee530(T197028*);
void func_00197148(T197028*);
void func_00197280(T197028*);
void func_00197318_x8314(T197028*) asm("func_00197318");
void func_00197390(T197028*);
void func_001973f0(T197028*);
void func_00197430_x8317(T197028*) asm("func_00197430");
void func_00197568(T197028*);
void func_001975a0(T197028*);
s32 func_00197028(T197028* p);  // 0x00197028: definition moved into src/anon/unit_00195d00.cpp

// --------------------
extern s32 D_00350438;
void func_001993a0(s32, s32);
void func_00105de0(s32);
void func_002430b0(s32);
s32 func_0016b7a0(s32);
void func_00196b28(s32, s32);
void func_0016bb38(s32, s32);
s32 func_00198cb8(s32, s32);
// 001991a8: moved to src/anon/unit_001991a8.cpp

// --------------------
struct S19ef90 { u8 a; u8 b; u8 c; u8 pad; s16 x; s16 y; s16 z; };
struct T19ef90 { s32 type; S19ef90 s; s32 w; };
union U19ef90 { s16 h; u16 uh; s32 i; };
S19ef90 func_00199718(s32, s32);
void func_0019ef90(T19ef90* d, u8* s);  // 0x0019ef90: definition moved into src/anon/unit_0019ee80.cpp

// --------------------
extern u64 D_0032f050;
extern u8 D_0032bb30[];
extern u32 D_0034f240;
void func_001c9770();
void func_001adbc0();
s32 func_001a1658_x8414(s32, s32) asm("func_001a1658");
void func_001adb80(s32, s32);
void func_001a17c8_x8416(s32) asm("func_001a17c8");
void func_001ada38(s32 n);  // 0x001ada38: definition moved into src/anon/unit_001ada38.cpp

// --------------------
struct C1b8520 { u16 type; u16 pad; union { f32 f; s32 i; } v; };
struct X1b8520 { u8 pad[12]; s32 (*fn)(C1b8520*, X1b8520*); s32 id; };
void func_00102470_x8453(f32, s32) asm("func_00102470");
s32 func_001991a8(s32, s32);
s32 func_0014aba8_x8455() asm("func_0014aba8");
void func_0014aa58_x8456(s32, s32, s32) asm("func_0014aa58");
void func_0014aa80_x8457(s32, s32, s32) asm("func_0014aa80");
// 001b8520: moved to src/anon/unit_001b82d8.cpp

// --------------------
struct C1bb2c8 { u16 type; u16 pad; union { f32 f; s32 i; } a; s32 b; s32 c; u16 n; };
extern u8* D_0034e948;
void func_001d5470_x8493(u8*, s32, C1bb2c8*) asm("func_001d5470");
void func_001d8248(u8*, C1bb2c8*);
void func_001d8550(u8*, C1bb2c8*);
void func_001d8b68(u8*, C1bb2c8*);
void func_001d9028(u8*, C1bb2c8*);
void func_001d93f0(u8*, C1bb2c8*);
void func_001d5370_x8499(u8*, s32, s32) asm("func_001d5370");
void func_001d4dc0(u8*, s32, s32, s32);
void func_0019ba60_x8501(u8*) asm("func_0019ba60");
void func_001a1aa0(u8*, s32);
// 001bb2c8: moved to src/yasui/libys/mission.cpp

// --------------------
struct V1cd078 { f32 x, y, z, w; };
extern s32 D_003520c0;
s32 func_0018ca48_x8557(s32) asm("func_0018ca48");
s32 func_001d87b8(s32);
void func_001d86a0_x8559(s32, s32) asm("func_001d86a0");
void func_0016be98(V1cd078*, u8*);
void func_001ccf18(V1cd078*, s32, s32);
// 001cd078: moved to src/anon/unit_001cd078.cpp

// --------------------
extern f32 D_00349e10;
s32 func_0019ba60(u8*);
void func_001e1ce0(u8*);
void func_001e1d20(u8*);
void func_001e1df0(u8*);
void func_001e1df8(u8*);
void func_001e1e40(u8*);
void func_001e2130(u8*);
void func_001e21f0(u8*);
void func_001e21f8(u8*);
void func_001e2238(u8*);
void func_001e2620(u8*);
void func_001e2640(u8*);
void func_001e2298(u8* p);  // 0x001e2298: definition moved into src/anon/unit_001e0cb8.cpp

// --------------------
extern u8 D_01d9e840[];
extern u8* D_01d9e6e8;
void func_002f4000_x8625(void*, u8*, u8*) asm("sceVu0UnitMatrix");
void func_002f3d08_x8626(void*, u8*, u8*) asm("sceVu0MulMatrix");
void func_00208978(void* a, u8* b, u8* c);  // 0x00208978: definition moved into src/anon/unit_002086e0.cpp

// --------------------
struct C22cc38 { u8 pad[4]; s16 id; s16 v; u16 type; };
s32 func_002282f0_x8643(s32) asm("func_002282f0");
s32 func_0014ac08();
s32 func_0014abd8_x8645() asm("func_0014abd8");
s32 func_0014aba8_x8646() asm("func_0014aba8");
void func_0014aa58_x8647(s32, s32, s32) asm("func_0014aa58");
void func_0014aa80_x8648(s32, s32, s32) asm("func_0014aa80");
void func_0022cc38(C22cc38* c);  // 0022cc38: moved to src/sasa/event_layout.cpp (linked unit)

// --------------------
extern u8 D_0035ed0c;
s32 func_00287cd0();
s32 func_00289380_x8667(s32) asm("func_00289380");
s32 func_00289310_x8668(s32) asm("func_00289310");
s32 func_0028ae28_x8669(s32, s32) asm("func_0028ae28");
void func_00243e30();
void func_00287c90(s32);
void func_00244c30();
void func_00287df0_x8673(s32, s32, s32, s32, s32) asm("func_00287df0");
void func_00244988();
void func_002535b0(s32);
void func_00288658(s32, s32);
void func_00243f48();
void func_00288670(void (*)());
void func_00287da0();
void func_00243cd8();
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
void func_00244148();  // 0x00244148: definition moved into src/anon/unit_00242478.cpp

// --------------------
extern u32 D_0035ed4c;
extern u8 D_0035ed68;
s32 func_00287cd0();
s32 func_00289380_x8715(s32) asm("func_00289380");
s32 func_00289310_x8716(s32) asm("func_00289310");
s32 func_0028ae28_x8717(s32, s32) asm("func_0028ae28");
void func_00248720();
void func_00287c90(s32);
void func_002491d0();
void func_00249480();
s32 func_00287df0_b(s32, s32, s32, void (*)(), s32) asm("func_00287df0");
void func_00287da0();
s32 func_002427d8(s32);
void func_002485c8();
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
void func_002489d8();  // 0x002489d8: definition moved into src/anon/unit_00247ff0.cpp

// --------------------
extern u8 D_0035edc4;
s32 func_00287cd0();
s32 func_00289380_x8759(s32) asm("func_00289380");
s32 func_00289310_x8760(s32) asm("func_00289310");
s32 func_0028ae28_x8761(s32, s32) asm("func_0028ae28");
void func_002426a0(s32);
void func_0024bbb0();
void func_0024ba58();
void func_00287c90(s32);
void func_0024c6a0();
void func_00287df0_x8767(s32, s32, s32, s32, s32) asm("func_00287df0");
void func_00244988();
void func_002535b0(s32);
void func_00288658(s32, s32);
void func_00243f48();
void func_00288670(void (*)());
void func_00287da0();
void func_00243cd8();
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
void func_0024be68();  // 0x0024be68: definition moved into src/anon/unit_0024ba58.cpp

// --------------------
extern u8 D_0035edf0;
s32 func_00287cd0();
s32 func_00289380_x8809(s32) asm("func_00289380");
s32 func_00289310_x8810(s32) asm("func_00289310");
s32 func_0028ae28_x8811(s32, s32) asm("func_0028ae28");
void func_0024d4a0();
void func_00287c90(s32);
void func_0024e3a8();
void func_00287df0_x8815(s32, s32, s32, s32, s32) asm("func_00287df0");
void func_0024df58();
void func_002535b0(s32);
void func_00288658(s32, s32);
void func_0024d5a8();
void func_00288670(void (*)());
void func_00287da0();
void func_0024d348();
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
void func_0024d7a0();  // 0x0024d7a0: definition moved into src/anon/unit_0024cda8.cpp

// --------------------
extern u8 D_0035ee50;
s32 func_00287cd0();
s32 func_00289380_x8859(s32) asm("func_00289380");
s32 func_00289310_x8860(s32) asm("func_00289310");
s32 func_0028ae28_x8861(s32, s32) asm("func_0028ae28");
void func_002426a0(s32);
void func_0024fd28();
void func_0024fbd0();
void func_00287c90(s32);
void func_002507a0();
void func_00287df0_x8867(s32, s32, s32, s32, s32) asm("func_00287df0");
void func_00244988();
void func_002535b0(s32);
void func_00288658(s32, s32);
void func_00243f48();
void func_00288670(void (*)());
void func_00287da0();
void func_00243cd8();
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
void func_0024ffe0();  // 0x0024ffe0: definition moved into src/anon/unit_0024fbd0.cpp

// --------------------
struct T266c90 { u8 pad[28]; u16 flags; s8 b30; u8 b31; };
union U266c90 { T266c90* p; u32 i; u16 h; u8 b; };
extern U266c90 D_0035f0e4;
extern s32 D_0035f010_x8910 asm("D_0035f010");
s32 func_00281100_x8911(s32) asm("func_00281100");
s32 func_00281340(s32);
s8 func_00266c00();
void func_00266c90();  // 0x00266c90: definition moved into src/anon/unit_00265580.cpp

// --------------------
extern s32 D_0035f010_x8940 asm("D_0035f010");
u16* func_0026b850(s32);
s32 func_002670a0_x8942(s32) asm("func_002670a0");
s32 func_00281158(s32, s32);
s32 func_00267408(s32 a);  // 0x00267408: definition moved into src/anon/unit_00265580.cpp

// --------------------
s32 func_00289380_x8962(s32) asm("func_00289380");
s32 func_00287cd0();
void func_00287bc0_x8964() asm("func_00287bc0");
s32 func_002576d0();
void func_002575a8();
void func_00287c30();
void func_00287cc0(s32);
s32 func_00289310_x8969(s32) asm("func_00289310");
s32 func_00257610(s32);
void func_00257670(s32);
void func_00287c90(s32);
s32 func_00287df0(s32, s32, s32, s32, s32);
s32 func_00242848(s32);
void func_0026b0f8();
void func_00269658();
void func_00257530(s32);
void func_00287c00(s32);
void func_00281d48();
void func_00281e20();
void func_002691f8();  // 0x002691f8: definition moved into src/anon/unit_00268b30.cpp

// --------------------
struct E273530 { u8 pad[2]; s8 a; s8 b; u8 pad2[4]; };
extern E273530* D_0035f12c;
s32 func_002570a0(s32);
s32 func_00272b60(s32);
s32 func_0028b040_x9020(s32) asm("func_0028b040");
void func_00273678();
void func_002736f8();
void func_00273818();
void func_00273c40(s32);
void func_00273cb8(s32);
void func_00270c70(s32);
void func_00273530();  // 0x00273530: definition moved into src/anon/unit_00271e08.cpp

// --------------------
u8* func_00281180_x9057(s32) asm("func_00281180");
s32 func_00281480(s32, s32);
s32 func_002813b8();
s32 func_00281420_x9060() asm("func_00281420");
s32 func_002826f8(u8* p, s32 a, s32 k);  // 0x002826f8: definition moved into src/anon/unit_00282620.cpp

// --------------------
extern s32 D_0035f200_x9084 asm("D_0035f200");
extern u8 D_00374ad8[];
extern s8 D_0035f5c4;
void func_00288e88(s32);
s32 func_00287bc0();
void func_0028f4a0(void*);
void func_0029ae30();
void func_0029af20();
void func_0029e950(s32);
void func_002765e8(s32, s32, s32);
void func_0029b698();
void func_0029be08();
void func_0029ae40();  // 0x0029ae40: definition moved into src/anon/unit_00299920.cpp

// --------------------
struct T29ecf0 { u8 pad[8]; s16 idx[1]; };
extern T29ecf0* D_0035f5ac;
s32 func_00287bc0();
u8* func_00294000_x9122(s32) asm("func_00294000");
s32 func_0029c9d8(s32);
s32 func_002954e0(s32);
s32 func_002943b0(u8*);
s32 func_0029ecf0(s32 a);  // 0x0029ecf0: definition moved into src/anon/unit_0029d008.cpp

// --------------------
struct E2b3b78 { s32 flags; u8 pad[32]; };
extern E2b3b78* D_0035f630;
s32 func_00287bc0();
s32 func_002b3b78(s32 a);  // 0x002b3b78: definition moved into src/anon/unit_002b3ac8.cpp

// --------------------
union unaligned3 {
    void* ptr;
    u16 u2;
    u32 u4;
    u64 u8;
    s16 s2;
    s32 s4;
    s64 s8;
} __attribute__((__packed__));
const u8* func_00316f38(const u8* p, u64* val);
const u8* func_00316f70(const u8* p, s64* val);
void func_002fd160(void) __attribute__((noreturn));

const u8* func_00316fc8(u8 encoding, u32 base, const u8* p, u32* val);  // 0x00316fc8: definition moved into src/libgcc/unwind-dw2.c

// --------------------
void* func_001050d8_x9233(u32) asm("func_001050d8");
void* func_001c4520(u8*);
void* func_001c51d8(u8*);
void* func_001ce488(u8*);
void* func_001d6578(u8*);
void func_001c7bc8(void*, u8*);
void func_001cc048(void*, u8*);
void func_001ca678(void*, u8*);
void func_001cce38(void*, u8*);
void func_001cbb58(void*, u8*);
void func_001d2850(void*, u8*);
void func_001d7458(void*, u8*);
void func_001da1d8(void*, u8*);
// 001c25e8: moved to src/anon/unit_001c0638.cpp
void* func_001c25e8(u8* d);

// --------------------
typedef unsigned int Q1d3148 __attribute__((mode(TI)));
struct V1d3148 {
    union { Q1d3148 q; f32 f[4]; };
    V1d3148& operator=(const V1d3148& o) {
        // 128-bit lq/sq copy: hand-written asm in the original
        if (this != &o) asm volatile("lq $8,0(%1)\n\tsq $8,0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
};
struct M1d3148 {
    Q1d3148 r[3];
    V1d3148 t;
    M1d3148& operator=(const M1d3148& o) {
        // 128-bit lq/sq matrix copy: hand-written asm in the original
        if (this != &o) {
            asm volatile("lq $8,0(%1)\n\tlq $9,16(%1)\n\tlq $10,32(%1)\n\tlq $11,48(%1)\n\tsq $8,0(%0)\n\tsq $9,16(%0)\n\tsq $10,32(%0)\n\tsq $11,48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        }
        return *this;
    }
};
struct O1d3148 { s32 state; u8* obj; u8 pad[8]; M1d3148 m; };
extern u8* D_00350cc8;
extern u8* D_00350ccc;
s32 func_0019ba60(u8*);
V1d3148* func_0016c028_x9291(u8*) asm("func_0016c028");
s32 func_001dc9e0(u8*);
V1d3148* func_001dc5f8_x9293(u8*) asm("func_001dc5f8");
// 001d3148: moved to src/anon/unit_001d30b0.cpp

// --------------------
struct S227e30 { u8* base; s32 pad; s32 ofs; };
struct C227e30 { u16 size; s16 type; };
extern S227e30 D_0035db50[];
extern s32 D_0035dd04;
extern s32 D_0035db18;
extern u8 D_0035de24;
extern u8 D_0035de55;
void func_00226090();
void func_00170888(void*);
void func_00224d48();
void func_00102448_x9334(void*, s32) asm("func_00102448");
void func_0022f528(C227e30*, void*);
void func_0022d3b8(C227e30*);
void func_0022d358(void*);
void func_0022d3a8(C227e30*, void*);
void func_00231928(C227e30*);
void func_00230838_x9340(C227e30*) asm("func_00230838");
void func_00230878_x9341(C227e30*) asm("func_00230878");
void func_00232398(C227e30*);
void func_00226050(C227e30*);
void func_00232a48(C227e30*, void*);
void func_00225328(C227e30*, void*);
void func_00225788(C227e30*, void*);
void func_00224b60(C227e30*, void*);
void func_0022ba08(C227e30*, void*);
void func_00232110(C227e30*, void*);
void func_00232100(C227e30*, void*);
void func_0022c9f0(C227e30*);
void func_00227e30(void* th);  // 0x00227e30: definition moved into src/anon/unit_00224780.cpp

// --------------------
extern u32 D_0035ed20;
extern u8 D_0035ed3c;
s32 func_00287cd0();
s32 func_00289380_x9401(s32) asm("func_00289380");
s32 func_00289310_x9402(s32) asm("func_00289310");
s32 func_0028ae28_x9403(s32, s32) asm("func_0028ae28");
void func_00245be8();
void func_00287c90(s32);
void func_00247a20();
void func_00287df0_x9407(s32, s32, s32, s32, s32) asm("func_00287df0");
s32 func_00247870(s32);
void func_00242618(s32, s32);
void func_00247580(s32);
void func_002467b8();
void func_002535b0(s32);
void func_00288658(s32, s32);
void func_00245ce8();
void func_00288670(void (*)());
void func_00287da0();
void func_00245a90();
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
void func_00245eb8();  // 0x00245eb8: definition moved into src/anon/unit_00242478.cpp

// --------------------
extern u8 D_0035ed94;
s32 func_00287cd0();
s32 func_00289380_x9460(s32) asm("func_00289380");
s32 func_00289310_x9461(s32) asm("func_00289310");
s32 func_0028ae28_x9462(s32, s32) asm("func_0028ae28");
void func_002426a0(s32);
void func_0024a048();
void func_00287c90(s32);
void func_0024aef0();
void func_0024b1f8();
s32 func_00287df0_k5(s32, s32, s32, void (*)(), s32) asm("func_00287df0");
s32 func_00242848(s32);
void func_0024abb0();
void func_002535b0(s32);
void func_00288658(s32, s32);
void func_0024a150();
void func_00288670(void (*)());
void func_00287da0();
void func_00249ef0();
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
void func_0024a348();  // 0x0024a348: definition moved into src/anon/unit_00249ef0.cpp

// --------------------
extern u32 D_0035ee04;
extern u32 D_0035ee08;
s32 func_00289380_x9516(s32) asm("func_00289380");
void func_00287bc0_x9517() asm("func_00287bc0");
s32 func_00287cd0();
s32 func_00289310_x9519(s32) asm("func_00289310");
s32 func_0023f0c0_x9520(s32) asm("func_0023f0c0");
void func_0023f070(s32, s32, s32);
void func_00287f90(s32);
s32 func_002891e8_x9523(s32) asm("func_002891e8");
void func_0024e9c0();
void func_0024eff8(s32);
void func_00287c90(s32);
void func_00287df0_x9527(s32, s32, s32, s32, s32) asm("func_00287df0");
s32 func_0024f240();
void func_00287da0();
void func_0024f1a0();
void func_0024f070(s32);
s32 func_00288040();
void func_00288018();
void func_0024ec50();  // 0x0024ec50: definition moved into src/anon/unit_0024e7e8.cpp


// --------------------
struct O2513b0;
struct VT2513b0 { u8 pad[20]; void (*f20)(O2513b0*); };
struct O2513b0 { VT2513b0* vt; };
extern u32 D_0035ee58;
extern O2513b0* D_0035ee68;
s32 func_00287cd0();
void func_00139d78_x9577(s32) asm("func_00139d78");
s32 func_00289380_x9578(s32) asm("func_00289380");
s32 func_00289310_x9579(s32) asm("func_00289310");
s32 func_0023f0c0_x9580(s32) asm("func_0023f0c0");
void func_0023f070(s32, s32, s32);
void func_002426a0(s32);
void func_00287c90(s32);
void func_00252540();
s32 func_002891e8_x9585(s32) asm("func_002891e8");
s32 func_00252110(s32);
void func_00251ec8(s32);
s32 func_00287df0_x9589(s32, s32, s32, s32, s32) asm("func_00287df0");
s32 func_00242848(s32);
s32 func_00252000();
void func_00251fe0();
void func_00252618();
void func_00287da0();
s32 func_00252710(s32);
void func_00251f40();
void func_002515a0();
void func_00287bd0(s32, s32);
s32 func_00288040();
void func_00288018();
void func_002513b0();  // 0x002513b0: definition moved into src/anon/unit_00250fb8.cpp

// --------------------
extern s32 D_0035f64c_259 asm("D_0035f64c");
s32 func_00289380_x9644(s32) asm("func_00289380");
s32 func_00287cd0();
s32 func_0028acc8_x9646(s32) asm("func_0028acc8");
s32 func_00289310_x9647(s32) asm("func_00289310");
void func_00287f90(s32);
void func_0028abe0_x9649(s32) asm("func_0028abe0");
void func_00287c30();
s32 func_00287bc0();
void func_002b5af0();
void func_0028f7e8(s32);
void func_0025a1d0();
s32 func_0028ae28_x9655(s32, s32) asm("func_0028ae28");
void func_0028ab20_x9656(s32) asm("func_0028ab20");
void func_00287cc0(s32);
void func_0025d560();
void func_0025d620();
s32 func_00287df0_259(s32, s32, s32, void (*)(), s32) asm("func_00287df0");
s32 func_00242848(s32);
void func_00263c60();
void func_00287da0();
void func_0028aa40(s32);
void func_00287c00(s32);
void func_00287bd0(s32, s32);
void func_0025ca78();
s32 func_00288040();
void func_00288018();
void func_00259fb8();  // 0x00259fb8: definition moved into src/anon/unit_002588e8.cpp

// --------------------
extern s32 D_0035f024_261 asm("D_0035f024");
s32 func_00289380_x9720(s32) asm("func_00289380");
s32 func_00287cd0();
s32 func_00287c10();
s32 func_002576d0();
s32 func_00262e30();
s32 func_00289310_x9725(s32) asm("func_00289310");
void func_00287f90(s32);
void func_002575a8();
void func_00262cb8();
void func_00287c30();
s32 func_00287bc0();
void func_0028af18_x9731(s32, s32) asm("func_0028af18");
void func_0025ffd0();
void func_00260808();
s32 func_00257610(s32);
void func_00257670(s32);
void func_00287c90(s32);
s32 func_00287df0(s32, s32, s32, s32, s32);
s32 func_00242848(s32);
void func_00257530(s32);
void func_00287c00(s32);
s32 func_002570a0(s32);
u16* func_002632d0(s32);
void func_001a3458(s32, s32);
void func_00262c40();
void func_002618d8();  // 0x002618d8: definition moved into src/anon/unit_0025f6b8.cpp

// --------------------
extern s32 D_0035f200_29f asm("D_0035f200");
s32 func_00289380_x9795(s32) asm("func_00289380");
s32 func_00287cd0();
s32 func_00287bc0();
s32 func_00276368();
s32 func_0028acc8_x9799(s32) asm("func_0028acc8");
s32 func_00276888();
void func_00287f90(s32);
void func_0029ee38();
void func_00287c30();
void func_0028af18_x9804(s32, s32) asm("func_0028af18");
s32 func_00276358();
void func_00276220(s32, s32);
void func_00276690(s32);
void func_002766b0(s32);
void func_0028b1e8(s32, s32);
void func_0029ee68();
void func_0029f520();
s32 func_00289310_x9812(s32) asm("func_00289310");
s32 func_00276398();
void func_00275b60();
void func_00287c90(s32);
void func_002a0518();
s32 func_00287df0_29f(s32, s32, s32, void (*)(), s32) asm("func_00287df0");
s32 func_00242848(s32);
void func_0029fee8(s32);
void func_0029ee30();
void func_00287c00(s32);
void func_00287cc0(s32);
s32 func_002891e8_x9823(s32) asm("func_002891e8");
s32 func_0028b038_x9824(s32) asm("func_0028b038");
void func_002765e8(s32, s32, s32);
void func_00287da0();
void func_00276dc0();
s32 func_00288040();
void func_00288018();
void func_0029f938();  // 0x0029f938: definition moved into src/anon/unit_0029f938.cpp

// --------------------
extern s8* D_0035f234;
void func_00242b88(s32);
void func_00242c00(s32);
void func_00242d80(s32);
void func_00242d10(s32);
void func_00242df0(s32);
void func_00242b10(s32);
void func_00242a28(s32);
void func_00242a90(s32);
void func_00242ca0(s32);
void func_0027cb48();  // 0x0027cb48: definition moved into src/anon/unit_0027a6d8.cpp

// --------------------
extern s8* D_0035f234;
s32 func_00242b58();
s32 func_00242bd0();
s32 func_00242d58();
s32 func_00242ce8();
s32 func_00242dc8();
s32 func_00242ae8();
s32 func_00242a00();
s32 func_00242a68();
s32 func_00242c70();
s32 func_001058e8_x9950() asm("func_001058e8");
s8 func_00105868(s32);
void func_0027c9a8();  // 0x0027c9a8: definition moved into src/anon/unit_0027a6d8.cpp

// --------------------
extern s32 D_0035f01c_27c asm("D_0035f01c");
s32 func_00289380_x9988(s32) asm("func_00289380");
s32 func_00287cd0();
s32 func_00287c10();
s32 func_0027d3b0();
s32 func_0028f930(s32);
s32 func_00289310_x9993(s32) asm("func_00289310");
void func_00287f90(s32);
void func_0027d350();
void func_00287c30();
void func_0028af18_x9997(s32, s32) asm("func_0028af18");
void func_0028f7e8(s32);
void func_002551b8();
s32 func_0027d408();
void func_0027d450();
void func_0028ab20_x10002(s32) asm("func_0028ab20");
void func_0028fa98(s32);
void func_00287c90(s32);
void func_0027d540();
void func_0027d5d8();
void func_0028afa8_x10007(s32) asm("func_0028afa8");
void func_0027d9e8();
s32 func_00287df0_27c(s32, s32, s32, void (*)(), s32) asm("func_00287df0");
s32 func_00242848(s32);
void func_0027d868(s32);
void func_0027d008();
void func_0027cb48();
void func_0013a460();
void func_00287da0();
s32 func_002891e8_x10016(s32) asm("func_002891e8");
s32 func_0028b038_x10017(s32) asm("func_0028b038");
void func_00257050_x10018(s32, s32, s32) asm("func_00257050");
void func_00263c60();
void func_00256e80();
void func_0028f6f0(s32);
void func_0027d2e8();
void func_00287c00(s32);
s32 func_00288040();
void func_00288018();
void func_0027c700();  // 0x0027c700: definition moved into src/anon/unit_0027a6d8.cpp

// --------------------
extern s32 D_0035f200_2a5 asm("D_0035f200");
s32 func_00289380_x10095(s32) asm("func_00289380");
s32 func_00287cd0();
s32 func_00287bc0();
s32 func_002a6718();
void func_002a67a8();
void func_002a4df8();
void func_002a4e38();
void func_002a5590();
s32 func_0028acc8_x10103(s32) asm("func_0028acc8");
s32 func_00276888();
void func_00287f90(s32);
void func_0029ee38();
void func_00287c30();
void func_0028af18_x10108(s32, s32) asm("func_0028af18");
s32 func_00276358();
void func_00276220(s32, s32);
void func_00276690(s32);
void func_002766b0(s32);
void func_0028b1e8(s32, s32);
void func_0029ee68();
void func_0029f520();
s32 func_00289310_x10116(s32) asm("func_00289310");
s32 func_00276398();
void func_00275b60();
void func_00287c90(s32);
void func_002a6878();
s32 func_00287df0_2a5(s32, s32, s32, void (*)(), s32) asm("func_00287df0");
s32 func_00242848(s32);
void func_002a6088(s32);
void func_002a4df0();
void func_00287c00(s32);
void func_00287cc0(s32);
s32 func_002891e8_x10127(s32) asm("func_002891e8");
s32 func_0028b038_x10128(s32) asm("func_0028b038");
void func_002765e8(s32, s32, s32);
void func_00287da0();
void func_00276dc0();
s32 func_00288040();
void func_00288018();
void func_002a5a90();  // 0x002a5a90: definition moved into src/anon/unit_002a5a90.cpp

// --------------------
struct E24bfb8 { u8 b[36]; };
extern s32 D_0035edac_24b asm("D_0035edac");
extern s32 D_0035eda8_24b asm("D_0035eda8");
extern s32 D_0035edc0_24b asm("D_0035edc0");
extern E24bfb8 D_00372030[];
extern s16 D_00371fc8[];
s32 func_00287cd0();
s32 func_00289380_x10206(s32) asm("func_00289380");
s32 func_0028acc8_x10207(s32) asm("func_0028acc8");
s32 func_00289310_x10208(s32) asm("func_00289310");
void func_0028abe0_x10209(s32) asm("func_0028abe0");
s32 func_002891e8_x10210(s32) asm("func_002891e8");
s32 func_00244ee8(s32);
void func_002b4388_x10212(s32, void*, s32) asm("func_002b4388");
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
s32 func_0028ae28_x10215(s32, s32) asm("func_0028ae28");
void func_0028ab20_x10216(s32) asm("func_0028ab20");
void func_00287c90(s32);
void func_00287df0_x10218(s32, s32, s32, s32, s32) asm("func_00287df0");
void func_0028aa40(s32);
void func_00287b08(s32);
void func_00287da0();
void func_0024bfb8();  // 0x0024bfb8: definition moved into src/anon/unit_0024ba58.cpp

// --------------------
struct E24d910 { u8 b[36]; };
extern s32 D_0035edd0_24d asm("D_0035edd0");
extern s32 D_0035edcc_24d asm("D_0035edcc");
extern s32 D_0035edec_24d asm("D_0035edec");
extern s32 D_0035edf4_24d asm("D_0035edf4");
extern s16 D_00372118[];
extern s16 D_00372120[];
u8* func_0024e058();
s32 func_00287cd0();
s32 func_00289380_x10264(s32) asm("func_00289380");
s32 func_0028acc8_x10265(s32) asm("func_0028acc8");
s32 func_00289310_x10266(s32) asm("func_00289310");
void func_0028abe0_x10267(s32) asm("func_0028abe0");
s32 func_002891e8_x10268(s32) asm("func_002891e8");
s32 func_00244ee8(s32);
void func_002b4388_x10270(s32, void*, s32) asm("func_002b4388");
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
s32 func_0028ae28_x10273(s32, s32) asm("func_0028ae28");
void func_0028ab20_x10274(s32) asm("func_0028ab20");
void func_00287c90(s32);
void func_00287df0_x10276(s32, s32, s32, s32, s32) asm("func_00287df0");
void func_0028aa40(s32);
void func_00287b08(s32);
void func_00287da0();
void func_0024d910();  // 0x0024d910: definition moved into src/anon/unit_0024cda8.cpp

// --------------------
struct E250130 { u8 b[36]; };
extern s32 D_0035ee38_250 asm("D_0035ee38");
extern s32 D_0035ee34_250 asm("D_0035ee34");
extern s32 D_0035ee4c_250 asm("D_0035ee4c");
extern E250130 D_00372490[];
extern s16 D_00372410[];
s32 func_00287cd0();
s32 func_00289380_x10323(s32) asm("func_00289380");
s32 func_0028acc8_x10324(s32) asm("func_0028acc8");
s32 func_00289310_x10325(s32) asm("func_00289310");
void func_0028abe0_x10326(s32) asm("func_0028abe0");
s32 func_002891e8_x10327(s32) asm("func_002891e8");
s32 func_00244ee8(s32);
void func_002b4388_x10329(s32, void*, s32) asm("func_002b4388");
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
s32 func_0028ae28_x10332(s32, s32) asm("func_0028ae28");
void func_0028ab20_x10333(s32) asm("func_0028ab20");
void func_00287c90(s32);
void func_00287df0_x10335(s32, s32, s32, s32, s32) asm("func_00287df0");
void func_0028aa40(s32);
void func_00287b08(s32);
void func_00287da0();
void func_00250748();
void func_00250130();  // 0x00250130: definition moved into src/anon/unit_0024fbd0.cpp

// --------------------
extern s32 D_0035f64c_25a asm("D_0035f64c");
s32 func_00289380_x10375(s32) asm("func_00289380");
s32 func_00287cd0();
s32 func_0028acc8_x10377(s32) asm("func_0028acc8");
s32 func_00289310_x10378(s32) asm("func_00289310");
void func_00287f90(s32);
void func_0028abe0_x10380(s32) asm("func_0028abe0");
void func_00287c30();
s32 func_00287bc0();
void func_002b5af0();
void func_0028f7e8(s32);
void func_00259e90();
void func_00240be0();
void func_002b4c10();
extern u8 D_0035f0b2;
void func_0028f6f0(s32);
void func_00240b90(s32);
s32 func_0028ae28_x10391(s32, s32) asm("func_0028ae28");
void func_0028ab20_x10392(s32) asm("func_0028ab20");
void func_00287cc0(s32);
void func_0025d560();
void func_0025d620();
s32 func_00287df0_25a(s32, s32, s32, void (*)(), s32) asm("func_00287df0");
s32 func_00242848(s32);
void func_00263c60();
void func_00287da0();
void func_0028aa40(s32);
void func_00287c00(s32);
void func_00287bd0(s32, s32);
void func_0025ca78();
s32 func_00288040();
void func_00288018();
void func_0025a200();  // 0x0025a200: definition moved into src/anon/unit_002588e8.cpp

// --------------------
extern s32 D_0035f64c_25d asm("D_0035f64c");
s32 func_00289380_x10468(s32) asm("func_00289380");
s32 func_00287cd0();
s32 func_0028acc8_x10470(s32) asm("func_0028acc8");
s32 func_00289310_x10471(s32) asm("func_00289310");
void func_00287f90(s32);
void func_0028abe0_x10473(s32) asm("func_0028abe0");
void func_00287c30();
s32 func_00287bc0();
void func_002b5af0();
void func_0028f7e8(s32);
void func_00259e90();
void func_00240be0();
void func_002b4c10();
extern u8 D_0035f0b2;
void func_0028f6f0(s32);
void func_00240b90(s32);
s32 func_0028ae28_x10484(s32, s32) asm("func_0028ae28");
void func_0028ab20_x10485(s32) asm("func_0028ab20");
void func_00287cc0(s32);
void func_00287c90(s32);
void func_0025f588();
void func_0025f610();
s32 func_00287df0_25d(s32, s32, s32, void (*)(), s32) asm("func_00287df0");
s32 func_00242848(s32);
void func_00263c60();
void func_00287da0();
void func_0028aa40(s32);
void func_00287c00(s32);
void func_00287bd0(s32, s32);
void func_0025ca78();
s32 func_00288040();
void func_00288018();
void func_0025dbd8();  // 0x0025dbd8: definition moved into src/anon/unit_0025da20.cpp

// --------------------
extern s32 D_0035f024_261b asm("D_0035f024");
s32 func_00289380_x10550(s32) asm("func_00289380");
s32 func_00287cd0();
s32 func_00287c10();
s32 func_002576d0();
s32 func_00289310_x10554(s32) asm("func_00289310");
void func_00287f90(s32);
void func_002575a8();
void func_00287c30();
s32 func_00287bc0();
void func_0028af18_x10559(s32, s32) asm("func_0028af18");
void func_00287cc0(s32);
s32 func_00257610(s32);
void func_00257670(s32);
void func_00287c90(s32);
s32 func_00287df0(s32, s32, s32, s32, s32);
s32 func_00242848(s32);
void func_00257530(s32);
void func_00287c00(s32);
void func_00261668();  // 0x00261668: definition moved into src/anon/unit_0025f6b8.cpp

// --------------------
struct V2e4a08 { f32 x, y; };
void func_002e4a08(V2e4a08* v);  // 0x002e4a08: definition moved into src/anon/unit_002e3f58.cpp

// --------------------
struct S246070 { u8 b[26]; u16 h26; u8 c[8]; };
extern s32 D_0035ed24_246 asm("D_0035ed24");
extern s32 D_0035ed20_246 asm("D_0035ed20");
extern s32 D_0035ed38_246 asm("D_0035ed38");
extern u8* D_0035ed40_246 asm("D_0035ed40");
extern u8 D_00371ca8[];
extern u8 D_00371cb0[];
s32 func_00287cd0();
s32 func_00289380_x10618(s32) asm("func_00289380");
s32 func_0028acc8_x10619(s32) asm("func_0028acc8");
s32 func_00289310_x10620(s32) asm("func_00289310");
void func_0028abe0_x10621(s32) asm("func_0028abe0");
u8* func_00246868();
s32 func_002891e8_x10623(s32) asm("func_002891e8");
s32 func_002469a0(s32);
s32 func_002474e0(s32);
s32 func_00246840();
void func_002b4388_x10627(s32, void*, s32) asm("func_002b4388");
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
s32 func_0028ae28_x10630(s32, s32) asm("func_0028ae28");
void func_0028ab20_x10631(s32) asm("func_0028ab20");
void func_00287c90(s32);
void func_00287df0_x10633(s32, s32, s32, s32, s32) asm("func_00287df0");
void func_0028aa40(s32);
void func_002468e8(s32, s32);
void func_001d7940();
void func_00287da0();
void func_00246070();  // 0x00246070: definition moved into src/anon/unit_00242478.cpp

// --------------------
extern s32 D_0035f200_298 asm("D_0035f200");
s32 func_00289380_x10684(s32) asm("func_00289380");
s32 func_00287cd0();
s32 func_00287bc0();
s32 func_00276368();
s32 func_0028acc8_x10688(s32) asm("func_0028acc8");
s32 func_00276888();
void func_00287f90(s32);
s32 func_00287c10();
void func_00297e00(s32);
void func_00297e68();
void func_002986e0();
extern s8 D_0035f5a0;
void func_00299090();
void func_00298c60(s32);
void func_00297df8();
void func_00287c30();
void func_0028af18_x10700(s32, s32) asm("func_0028af18");
s32 func_00276358();
void func_00276220(s32, s32);
void func_00276690(s32);
void func_002766b0(s32);
void func_0028b1e8(s32, s32);
void func_0029ee68();
void func_0029f520();
s32 func_00289310_x10708(s32) asm("func_00289310");
s32 func_00276398();
void func_00275b60();
void func_00287c90(s32);
void func_00299408();
s32 func_00287df0_298(s32, s32, s32, void (*)(), s32) asm("func_00287df0");
s32 func_00242848(s32);
void func_0029fee8(s32);
void func_0029ee30();
void func_00287c00(s32);
void func_00287cc0(s32);
s32 func_002891e8_x10719(s32) asm("func_002891e8");
s32 func_0028b038_x10720(s32) asm("func_0028b038");
void func_002765e8(s32, s32, s32);
void func_00287da0();
void func_00276dc0();
s32 func_00288040();
void func_00288018();
void func_00298988();  // 0x00298988: definition moved into src/anon/unit_002982f0.cpp

// --------------------
extern f32 D_00349e10;
void func_00105620(u8*, u8*);
union U102470 { u8* p; f32 f; };
// 00102470: moved to src/global/unit_001022c0.cpp

// --------------------
extern u64 D_0036b0d0;
void func_0014b920(u64* p);  // 0x0014b920: definition moved into src/anon/unit_0014b838.cpp

// --------------------
extern f32 D_01c60be8;
void wtarget_0018c868(u32, u32, u32, u32) asm("_Z16wtarget_0018c868jjjj");
void wtarget_0018c868(u32 a0, u32 a1, u32, u32);  // 0x0018c868: definition moved into src/yasui/libys/npc.cpp

// --------------------
struct YS_DAMAGE { u8 pad[39]; u8 type; };
s32 YS_DAMAGE_is_normal(const YS_DAMAGE*) asm("_ZNK2YS6DAMAGE9is_normalEv");
// 0018caf8: moved to src/yasui/libys/damage.cpp

// --------------------
void func_001ad990(u8*, f32, f32, f32);
// 001b1be0: moved to src/anon/unit_001b14d8.cpp

// --------------------
void func_001cfac0(u8* p, f32 a, f32 b, f32 c, f32 d);  // 0x001cfac0: definition moved into src/anon/unit_001cf0b0.cpp

// --------------------
void func_001a5990(u8*, f32, s32);
void func_001d29a0(u8* a, u8* b);  // 0x001d29a0: definition moved into src/anon/unit_001d2810.cpp

// --------------------
extern f32 D_01d5ba08;
void wtarget_001d3060(u32, u32, u32, u32) asm("_Z16wtarget_001d3060jjjj");
void wtarget_001d3060(u32 a0, u32 a1, u32, u32);  // 0x001d3060: definition moved into src/anon/unit_001d2810.cpp

// --------------------
void func_002cd260(u8* p);  // 0x002cd260: definition moved into src/taito/path.cpp

// --------------------
// 002eaee8: static initialiser, now made by gcc in src/anon/unit_002eae08.cpp

// --------------------
// 00186110: moved to src/anon/unit_00185d10.cpp
s32 func_00186110(void*, u8* p);

// --------------------
struct E256a58 { u8 pad[20]; u16 id; u8 pad2[14]; };
extern s32 D_0035f01c_256 asm("D_0035f01c");
extern E256a58 D_00372a28[];
s32 func_0028b040_x10886(s32) asm("func_0028b040");
s32 func_00257fa8(s32);
void func_00263a58(s32, s32);
void func_00256a58();  // 0x00256a58: definition moved into src/anon/unit_00254020.cpp

// --------------------
struct O2e0720;
struct VT2e0720 { u8 pad[44]; s32 (*f44)(O2e0720*); };
struct O2e0720 { VT2e0720* vt; };
void func_0017f488(u8*, s32, f32, f32);
void func_002e0720(O2e0720* o, u8* p);  // 0x002e0720: definition moved into src/anon/unit_002de3c8.cpp

// --------------------
struct E230838 { s32 a; s32 b; };
union U230838 { E230838* p; s32 i; };
extern U230838 D_0035dce8_x10906 asm("D_0035dce8");
void func_00230838(s32 v);  // 0x00230838: definition moved into src/anon/unit_002302c0.cpp

// --------------------
// 00155fc0: moved to src/anon/unit_00153ea0.cpp
s32 func_00155fc0(u8* p);

// --------------------
struct E230878 { u8* a; u8* b; };
union U230878 { E230878* p; s32 i; };
extern U230878 D_0035dce8_878 asm("D_0035dce8");
void func_00230878(u8* q);  // 0x00230878: definition moved into src/anon/unit_002302c0.cpp

// --------------------
extern void* D_0035f324;
void func_00167658(void*, s32);
void func_00288018();
void* func_001063c0_x10951(s32, s32) asm("func_001063c0");
void func_00287ed8(s32 a);  // 0x00287ed8: definition moved into src/anon/unit_00286d28.cpp

// --------------------
// 00155ee8: moved to src/anon/unit_00153ea0.cpp
s32 func_00155ee8(u8* p);

// --------------------
void func_001e0fe0(u8*);
void func_001e0fe8(u8*);
void func_001e1068(u8*);
void func_001e15a8(u8*);
void func_001e1638(u8*);
void func_001e1698(u8*);
void func_001e16c0(u8*);
void func_001e1728(u8* p);  // 0x001e1728: definition moved into src/anon/unit_001e0cb8.cpp

// --------------------
struct E1815d0 { s32 a; s32 b; };
extern E1815d0 D_0036c668[];
void func_001a3458(s32, s32);
s32 func_001a3570(s32);
void func_00181570(s32, s32);
// 001815d0: moved to src/yasui/libys/progress.cpp

// --------------------
extern s32 D_0035ece0;
extern s32 D_003718d0[];
void func_0023d320(s32);
void func_00242740(s32);
void func_00287910(s32, s32, s32);
s32 func_00103570();
void func_0028c878(s32, s32);
void func_002425d0(s32);
void func_00242fa0();
struct VT242f00 { void* a; void (*b)(); };
VT242f00* func_00243150(s32);
void func_00242f00(s32 n);  // 0x00242f00: definition moved into src/anon/unit_00242478.cpp

// --------------------
struct V15a098 {
    f32 x, y, z, w;
    V15a098() {}
    V15a098(const V15a098& o) { if (this != &o) QCOPY(this, &o); }
    V15a098& operator=(const V15a098& o) { if (this != &o) QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
// VU0 vector helper: hand-written macro code in the original.
static inline V15a098 Sub15a098(const V15a098& a, const V15a098& b)
{
    V15a098 r;
    asm volatile("lqc2 $vf1,0(%1)\n\tlqc2 $vf2,0(%2)\n\tvsub.wxyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
f32 func_002f8ad0__15a098(f32, f32) asm("func_002f8ad0");
extern V15a098 D_0034aa50[2];
static inline f32 Yaw15a098(V15a098 v) { return func_002f8ad0__15a098(v.x, v.z); }
// 0015a098: moved to src/harata/libdk/targetcamera.cpp

// --------------------
struct V2e2f08 {
    f32 x, y, z, w;
    V2e2f08() {}
    V2e2f08(const V2e2f08& o) { if (this != &o) QCOPY(this, &o); }
    V2e2f08& operator=(const V2e2f08& o) { if (this != &o) QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
// VU0 matrix * vector: hand-written macro code in the original.
static inline V2e2f08 Mul2e2f08(const f32* m, const V2e2f08& v)
{
    V2e2f08 r;
    asm volatile("lqc2 $vf5,0(%2)\n\tlqc2 $vf1,0(%1)\n\tlqc2 $vf2,16(%1)\n\tlqc2 $vf3,32(%1)\n\tlqc2 $vf4,48(%1)\n\t"
                 "vmulax.wxyz ACC,$vf1,$vf5x\n\tvmadday.wxyz ACC,$vf2,$vf5y\n\tvmaddaz.wxyz ACC,$vf3,$vf5z\n\t"
                 "vmaddw.wxyz $vf5,$vf4,$vf5w\n\tsqc2 $vf5,0(%0)"
                 : : "r"(&r), "r"(m), "r"(&v) : "memory");
    return r;
}
V2e2f08 func_00184540__2e2f08(u32, f32, f32) asm("func_00184540");
f32* func_002e2930__2e2f08(u32) asm("func_002e2930");
extern u32 D_00361f60__2e2f08 asm("D_00361f60");
// 002e2f08: moved to src/anon/unit_002e2f08.cpp

// --------------------
struct N102688 { u8 pad[40]; u32 fl; u8 pad2[12]; N102688* next; };
struct M102688 { u32 f0; u32 f4; N102688* head; };
void func_001025f8__102688(M102688*, N102688*) asm("func_001025f8");
static inline N102688* Next102688(M102688* m, N102688* p, u32 mask, u32 v)
{
    do {
        p = !p ? m->head : p->next;
    } while (p && (p->fl & mask) != v);
    return p;
}
void wtarget_00102688(M102688* m, u32 mask, u32 v, u32) asm("_Z16wtarget_00102688jjjj");
// 00102688: moved to src/global/unit_001022c0.cpp

// --------------------
struct E182fa0 { u32 a; u32 b; u32 c; };
extern E182fa0 D_01c60588[64];
void func_001828b8__182fa0(E182fa0*) asm("func_001828b8");
static inline void Del182fa0(E182fa0* a)
{
    if (a != 0) {
        E182fa0* p = a + 64;
        E182fa0* b = a;
    top:
        if (p == b) return;
        --p;
        func_001828b8__182fa0(p);
        goto top;
    }
}
void wtarget_00182fa0(s32 init, s32 prio, u32, u32) asm("_Z16wtarget_00182fa0jjjj");
// 00182fa0: static initialiser, now made by gcc in src/anon/unit_00182780.cpp

// --------------------
extern u8 D_00351e18[];
extern u8 D_00345c08[];
extern u8 D_0034ebc8[];
extern void* D_01d49960[2];
extern u32 D_01d49968;
struct L0_1c8118;
void func_00320fa8__1c8118(L0_1c8118*) asm("func_00320fa8");
struct L0_1c8118 { u32 vt; };
struct L1_1c8118 : L0_1c8118 {
    ~L1_1c8118() { *(u32*)this = (u32)D_0034ebc8; func_00320fa8__1c8118(this); }
};
struct M1c8118 { u8 d[16]; ~M1c8118() {} };
struct L2_1c8118 : L1_1c8118 {
    u8 pad[3180];
    M1c8118 arr[6];
    ~L2_1c8118() { *(u32*)this = (u32)D_00345c08; }
};
struct L3_1c8118 : L2_1c8118 {
    __attribute__((always_inline)) ~L3_1c8118()
    {
        s32 i, n;
        *(u32*)this = (u32)D_00351e18;
        n = 0;
        for (i = 0; i < 2; i++) {
            if (D_01d49960[i]) {
                if (D_01d49960[i] == this) D_01d49960[i] = 0;
                else n++;
            }
        }
        if (n == 0) D_01d49968 = 0;
    }
};
// 0x1c8118: moved to src/yasui/libys/summon.cpp

// --------------------
struct X2c62c8;
struct VT2c62c8 { u32 a, b; s32 (*f8)(X2c62c8*); };
struct X2c62c8 { VT2c62c8* vt; };
struct O2c62c8 { u8 pad[16]; X2c62c8* slot[3]; X2c62c8* cur; };
void func_002c65f8__2c62c8(X2c62c8*) asm("func_002c65f8");
void func_002c6280__2c62c8(O2c62c8*, s32) asm("func_002c6280");
s32 func_002c62c8(O2c62c8* o);  // 0x002c62c8: definition moved into src/worldmap/cameramanager.cpp

// --------------------
// 00159070: moved to src/harata/libdk/lightcyclecamera.cpp

// --------------------
struct E1a6a20 { u32 key; u8* buf; };
union U1a6a20 { u8* p; u32 u; };
extern E1a6a20 D_01c6cb30[8];
extern s32 D_01c6cb70;
void* func_001050d8__1a6a20(u32) asm("func_001050d8");
void func_002fd310__1a6a20(void*, u32) asm("func_002fd310");
// 001a6a20: moved to src/anon/unit_001a6a10.cpp

// --------------------
extern u8* D_01d49960__1c89a8[2] asm("D_01d49960");
extern char D_0036e080[];
s32 func_0019ba60__1c89a8(u8*) asm("func_0019ba60");
void func_001880b0__1c89a8(u8*, char*) asm("func_001880b0");
void func_00102448__1c89a8(u32, u32) asm("func_00102448");
void func_001c9e50__1c89a8(u32) asm("func_001c9e50");
void func_001c9b90__1c89a8(void) asm("func_001c9b90");
// 0x1c89a8: moved to src/yasui/libys/summon.cpp

// --------------------
struct V1ba340 {
    f32 x, y, z, w;
    V1ba340() {}
    V1ba340& operator=(const V1ba340& o) { if (this != &o) QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct Hit1ba340 { u8 pad[12]; s32 n; V1ba340 pos; };
struct O1ba340 { u32 f0; u32 f4; u8* e; };
u32 func_001a3a78__1ba340(void) asm("func_001a3a78");
u32 func_001de168__1ba340(u32, u32, u32, u32, u32, u32) asm("func_001de168");
void* func_0016bc20__1ba340(u8*, u32, s32) asm("func_0016bc20");
void func_0018a818__1ba340(Hit1ba340*, u8*, void*) asm("func_0018a818");
V1ba340* func_001dc5f8__1ba340(u32) asm("func_001dc5f8");
V1ba340* func_0016c028__1ba340(u8*) asm("func_0016c028");
// 001ba340: moved to src/yasui/libys/itemeffect.cpp

// --------------------
extern u64 D_0034c710;
extern u8 D_0034c70c;
extern u8 D_0034c6f0[];
void func_00143248__15f548(void) asm("func_00143248");
void func_00160e50__15f548(s32) asm("func_00160e50");
void* func_001de4b0__15f548(void*, s32, void*) asm("func_001de4b0");
s32 func_001dc9e0__15f548(void*) asm("func_001dc9e0");
void func_001dcc48__15f548(void*) asm("func_001dcc48");
// 0015f548: moved to src/harata/libdk/map_effect.cpp

// --------------------
struct V2e8d08 {
    f32 x, y, z, w;
    V2e8d08() {}
    V2e8d08& operator=(const V2e8d08& o) { if (this != &o) QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct E2e8d08 { u32 f0; u8* e; };
struct Hit2e8d08 { u32 f0; u32 f4; f32 f8; union { s32 n; u8* p; E2e8d08* q; V2e8d08* v; }; V2e8d08 pos; };
extern V2e8d08 D_01e2bf90;
void* func_0016bba8__2e8d08(u8*, u32, u32) asm("func_0016bba8");
void func_0018a818__2e8d08(Hit2e8d08*, u8*, void*) asm("func_0018a818");
V2e8d08* func_0016c028__2e8d08(u8*) asm("func_0016c028");
// 002e8d08: moved to src/anon/unit_002e8b50.cpp

// --------------------
struct P1a68e0 { u32 a; u32 b; };
struct E1a68e0 { u32 f0; u32 pad[2]; u8 m[28]; u32 f40; };
extern P1a68e0 D_01c6cb20;
extern E1a68e0 D_00350800[6];
void func_001ddd10__1a68e0(void*) asm("func_001ddd10");
void func_001ddd88__1a68e0(void*) asm("func_001ddd88");
static inline void Del1a68e0(E1a68e0* a)
{
    if (a != 0) {
        E1a68e0* p = a + 6;
        E1a68e0* b = a;
    top:
        if (p == b) return;
        --p;
        func_001ddd88__1a68e0(p->m);
        goto top;
    }
}
void wtarget_001a68e0(s32 init, s32 prio, u32, u32) asm("_Z16wtarget_001a68e0jjjj");
// 001a68e0: static initialiser, now made by gcc in src/yasui/libys/magic.cpp

// --------------------
struct C102350 { u8 pad[240]; u8 started; u8 pad2[3]; s32 wait; f32 timer; s32 size; u8 stack[1]; };
struct T102350;
struct T102350 { void (*fn)(T102350*); u8 pad[32]; u8* q; u8 pad2[12]; C102350* co; };
extern f32 D_00349e10;
void func_001056e8__102350(u8*) asm("func_001056e8");
s32 func_00105550__102350(u8*) asm("func_00105550");
void func_00105710__102350(void) asm("func_00105710");
void func_001055b8__102350(C102350*) asm("_Z13func_001055b8Pv");
C102350* func_00105728__102350(void) asm("func_00105728");
// 00102350: moved to src/global/unit_001022c0.cpp

// --------------------
// 00105400: static initialiser, now made by gcc in src/common/area.cpp

// --------------------
struct V104640 {
    f32 x, y, z, w;
};
struct C104640 { u32 vt; u32 f4; u8 b8; u8 pad[11]; u32 f20; u32 f24; u32 f28; u32 f32; u32 f36; u32 f40; };
extern V104640 D_003a6a80;
extern V104640 D_003a6a90;
extern V104640 D_003a6aa0;
extern V104640 D_003a6ab0;
extern V104640 D_003a6ac0;
extern V104640 D_003a6ad0;
extern f32 D_003a6ae0;
extern f32 D_003a6ae4;
extern f32 D_003a6ae8;
extern f32 D_003a6aec;
extern C104640 D_0032ba90;
extern u8 D_0032b930[];
static inline void Set104640(V104640* v, f32 a, f32 b, f32 c, f32 d) { v->x = a; v->y = b; v->z = c; v->w = d; }
void wtarget_00104640(s32 init, s32 prio, u32, u32) asm("_Z16wtarget_00104640jjjj");
// 00104640: static initialiser, now made by gcc in src/common/gumimenu.cpp

// --------------------
// Bind the battle/system table entries (BAR tags) to their owners.
struct BarEnt194a30 { u32 f0; u32 f4; void* data; };
void* func_001b1490__194a30(void*) asm("func_001b1490");
BarEnt194a30* func_00168b88__194a30(void*, s32, s32, s32) asm("func_00168b88");
BarEnt194a30* func_00168b38__194a30(void*, s32, s32) asm("func_00168b38");
void func_00264318__194a30(void*) asm("func_00264318");
extern void* D_0034f248;
extern void* D_0034f24c;
extern void* D_01c61af8;
extern void* D_01c61afc;
void func_00185880__194a30(void*) asm("func_00185880");
void func_00185910__194a30(void*) asm("func_00185910");
void func_00194790__194a30(void*) asm("func_00194790");
void func_0019fe80__194a30(void*) asm("func_0019fe80");
void func_001a5b58__194a30(void*) asm("func_001a5b58");
void func_001a6648__194a30(void*) asm("func_001a6648");
void func_001a8098__194a30(void*) asm("func_001a8098");
void func_001a81e0__194a30(void*) asm("func_001a81e0");
void func_001a8908__194a30(void*) asm("func_001a8908");
void func_001a97e8__194a30(void*) asm("func_001a97e8");
void func_001afa30__194a30(void*) asm("func_001afa30");
void func_001b1e58__194a30(void*) asm("func_001b1e58");
void func_001b6fa0__194a30(void*) asm("func_001b6fa0");
void func_001b8e78__194a30(void*) asm("func_001b8e78");
void func_001c0638__194a30(void*) asm("func_001c0638");
void func_001c09f0__194a30(void*) asm("func_001c09f0");
void func_001c0c70__194a30(void*) asm("func_001c0c70");
void func_001c20d8__194a30(void*) asm("func_001c20d8");
void func_001c2d38__194a30(void*) asm("func_001c2d38");
void func_001c2d78__194a30(void*) asm("func_001c2d78");
void func_001ce1a0__194a30(void*) asm("func_001ce1a0");
void func_001d23d0__194a30(void*) asm("func_001d23d0");
void func_001d30b0__194a30(void*) asm("func_001d30b0");
void func_001d3c08__194a30(void*) asm("func_001d3c08");
void func_001d5030__194a30(void*) asm("func_001d5030");
void func_001d5b68__194a30(void*) asm("func_001d5b68");
void func_001d6cb8__194a30(void*) asm("func_001d6cb8");
void func_001d7970__194a30(void*) asm("func_001d7970");
void func_001d7eb8__194a30(void*) asm("func_001d7eb8");
void func_001db598__194a30(void*) asm("func_001db598");
extern char D_0036cf28[];
extern char D_0036cf30[];
extern char D_0036cf38[];
extern char D_0036cf40[];
extern char D_0036cf48[];
extern char D_0036cf50[];
extern char D_0036cf58[];
extern char D_0036cf60[];
extern char D_0036cf68[];
extern char D_0036cf70[];
extern char D_0036cf78[];
extern char D_0036cf80[];
extern char D_0036cf88[];
extern char D_0036cf90[];
extern char D_0036cf98[];
extern char D_0036cfa0[];
extern char D_0036cfa8[];
extern char D_0036cfb0[];
extern char D_0036cfb8[];
extern char D_0036cfc0[];
extern char D_0036cfc8[];
extern char D_0036cfd0[];
extern char D_0036cfd8[];
extern char D_0036cfe0[];
extern char D_0036cfe8[];
extern char D_0036cff0[];
extern char D_0036cff8[];
extern char D_0036d000[];
extern char D_0036d008[];
extern char D_0036d010[];
static inline s32 Tag194a30(char* s) { return s[0] | (s[1] << 8) | (s[2] << 16) | (s[3] << 24); }
void func_00194a30(void);  // 0x00194a30: definition moved into src/anon/unit_00194790.cpp

// --------------------
// Player constructor body: sets up state, then creates the per-character controller.
struct Pair10b978 { u32 a; u32 b; };
struct Mdl10b978 { u8 pad[78]; u16 id; };
struct Pl10b978 {
    u32 vt; u32 f4; Mdl10b978* mdl; u8 pad0[2748 - 12]; u32 flags2; u8 pad1[2896 - 2752];
    s32 f2896; u32 f2900; u32 f2904; u32 f2908; void* ctl; Pair10b978 pair; s32 kind; s32 pad; u32 f2932;
    u32 f2936; u32 flags; u8 pad2[3120 - 2944]; u8 m3120[8]; u8 m3128[40]; u32 f3168; u32 f3172;
    u8 pad3[3280 - 3176]; s32 f3280; u32 f3284[7]; u8 pad4[3324 - 3312]; u32 f3324;
};
extern u8 D_00345c08[];
extern s32 D_00341800[];
extern const Pair10b978 D_0036a440;
extern const Pair10b978 D_0036a448;
extern const Pair10b978 D_0036a450;
void func_0017d968__10b978(Pl10b978*) asm("func_0017d968");
void func_00190128__10b978(void*) asm("func_00190128");
void func_0017bf40__10b978(void*) asm("func_0017bf40");
void func_0010eee8__10b978(Pl10b978*) asm("func_0010eee8");
Pl10b978* func_0017df58__10b978(s32) asm("func_0017df58");
s32 func_0016a070__10b978(Pl10b978*) asm("func_0016a070");
void* func_001050d8__10b978(u32) asm("func_001050d8");
s32 func_00112720__10b978(Pl10b978*) asm("func_00112720");
void func_001136b8__10b978(void*) asm("func_001136b8");
void func_001133f8__10b978(Pl10b978*) asm("func_001133f8");
#define CTL10b978(fn) void fn##__10b978(void*, Pl10b978*, void*) asm(#fn);
CTL10b978(func_00113648) CTL10b978(func_001148d0) CTL10b978(func_001147b8) CTL10b978(func_001151f8)
CTL10b978(func_00114ff8) CTL10b978(func_00114d48) CTL10b978(func_00114ea0) CTL10b978(func_00114af8)
CTL10b978(func_00115738) CTL10b978(func_001154c8) CTL10b978(func_00115620) CTL10b978(func_00119c40)
CTL10b978(func_00117c28) CTL10b978(func_0011a6b0) CTL10b978(func_0011a490) CTL10b978(func_0011a2a8)
CTL10b978(func_00114c30) CTL10b978(func_00115350)
static inline void* Tab10b978(s32 k) { return (u8*)D_00341800 + D_00341800[k]; }
#define NEW10b978(sz, fn) { void* c = func_001050d8__10b978(sz); fn##__10b978(c, p, Tab10b978(p->kind)); p->ctl = c; }
static inline void CtorM10b978(u8* m) { func_00190128__10b978(m + 8); func_0017bf40__10b978(m); }
void func_0010b978(Pl10b978* p);  // 0x0010b978: definition moved into src/anon/unit_0010b978.cpp

// --------------------
// Player constructor body: sets up state, then creates the per-character controller.
struct Pair10c078 { u32 a; u32 b; };
struct Mdl10c078 { u8 pad[78]; u16 id; };
struct Pl10c078 {
    u32 vt; u32 f4; Mdl10c078* mdl; u8 pad0[2748 - 12]; u32 flags2; u8 pad1[2896 - 2752];
    s32 f2896; u32 f2900; u32 f2904; u32 f2908; void* ctl; Pair10c078 pair; s32 kind; s32 pad; u32 f2932;
    u32 f2936; u32 flags; u8 pad2[3120 - 2944]; u8 m3120[8]; u8 m3128[40]; u32 f3168; u32 f3172;
    u8 pad3[3280 - 3176]; s32 f3280; u32 f3284[7]; u8 pad4[3324 - 3312]; u32 f3324;
};
extern u8 D_00345c08[];
extern s32 D_00341800[];
extern const Pair10c078 D_0036a440_x11763 asm("D_0036a440");
extern const Pair10c078 D_0036a448_x11764 asm("D_0036a448");
extern const Pair10c078 D_0036a450_x11765 asm("D_0036a450");
void func_0017d968__10c078(Pl10c078*) asm("func_0017d968");
void func_00190128__10c078(void*) asm("func_00190128");
void func_0017bf40__10c078(void*) asm("func_0017bf40");
void func_0010eee8__10c078(Pl10c078*) asm("func_0010eee8");
Pl10c078* func_0017df58__10c078(s32) asm("func_0017df58");
s32 func_0016a070__10c078(Pl10c078*) asm("func_0016a070");
void* func_001050d8__10c078(u32) asm("func_001050d8");
s32 func_00112720__10c078(Pl10c078*) asm("func_00112720");
void func_001136b8__10c078(void*) asm("func_001136b8");
void func_001133f8__10c078(Pl10c078*) asm("func_001133f8");
#define CTL10c078(fn) void fn##__10c078(void*, Pl10c078*, void*) asm(#fn);
CTL10c078(func_00113648) CTL10c078(func_001148d0) CTL10c078(func_001147b8) CTL10c078(func_001151f8)
CTL10c078(func_00114ff8) CTL10c078(func_00114d48) CTL10c078(func_00114ea0) CTL10c078(func_00114af8)
CTL10c078(func_00115738) CTL10c078(func_001154c8) CTL10c078(func_00115620) CTL10c078(func_00119c40)
CTL10c078(func_00117c28) CTL10c078(func_0011a6b0) CTL10c078(func_0011a490) CTL10c078(func_0011a2a8)
CTL10c078(func_00114c30) CTL10c078(func_00115350)
static inline void* Tab10c078(s32 k) { return (u8*)D_00341800 + D_00341800[k]; }
#define NEW10c078(sz, fn) { void* c = func_001050d8__10c078(sz); fn##__10c078(c, p, Tab10c078(p->kind)); p->ctl = c; }
static inline void CtorM10c078(u8* m) { func_00190128__10c078(m + 8); func_0017bf40__10c078(m); }
void func_0010c078(Pl10c078* p);  // 0x0010c078: definition moved into src/anon/unit_0010b978.cpp

// --------------------
// newlib _malloc_r (dlmalloc 2.6.x mALLOc; EE: 64-bit long, MALLOC_ALIGN 16).
typedef struct MChunk2fd680 MChunk2fd680;
struct MChunk2fd680 { u32 prev_size; u32 size; MChunk2fd680* fd; MChunk2fd680* bk; };
typedef MChunk2fd680* mchunkptr2fd680;
extern u8 D_00365c50[];
void func_002fded8__2fd680(void*) asm("__malloc_lock");
void func_002fdf30__2fd680(void*) asm("__malloc_unlock");
void func_002fd428(void*, u32);
#define M_SIZE_SZ 4
#define M_ALIGN_MASK 15
#define M_MINSIZE 16
#define M_PREV_INUSE 1
#define M_SIZE_BITS 3
#define M_MAX_SMALLBIN 63
#define M_MAX_SMALLBIN_SIZE 512
#define M_SMALLBIN_WIDTH 8
#define M_BINBLOCKWIDTH 4
#define bin_at(i) ((mchunkptr2fd680)(D_00365c50 + 8 * (i)))
#define next_bin(b) ((mchunkptr2fd680)((char*)(b) + 8))
#define prev_bin(b) ((mchunkptr2fd680)((char*)(b) - 8))
#define first(b) ((b)->fd)
#define last(b) ((b)->bk)
#define top (bin_at(0)->fd)
#define last_remainder (bin_at(1))
#define binblocks (bin_at(0)->size)
#define chunksize(p) ((p)->size & ~(M_SIZE_BITS))
#define chunk2mem(p) ((void*)((char*)(p) + 2 * M_SIZE_SZ))
#define chunk_at_offset(p, s) ((mchunkptr2fd680)(((char*)(p)) + (s)))
#define set_head(p, s) ((p)->size = (s))
#define set_foot(p, s) (((mchunkptr2fd680)((char*)(p) + (s)))->prev_size = (s))
#define set_inuse_bit_at_offset(p, s) (((mchunkptr2fd680)(((char*)(p)) + (s)))->size |= M_PREV_INUSE)
#define request2size(req) (((long)((req) + (M_SIZE_SZ + M_ALIGN_MASK)) < (long)(M_MINSIZE + M_ALIGN_MASK)) ? M_MINSIZE : \
    (((req) + (M_SIZE_SZ + M_ALIGN_MASK)) & ~(M_ALIGN_MASK)))
#define is_small_request(nb) (nb < M_MAX_SMALLBIN_SIZE - M_SMALLBIN_WIDTH)
#define smallbin_index(sz) (((unsigned long)(sz)) >> 3)
#define bin_index(sz) \
(((((unsigned long)(sz)) >> 9) ==    0) ?       (((unsigned long)(sz)) >>  3): \
 ((((unsigned long)(sz)) >> 9) <=    4) ?  56 + (((unsigned long)(sz)) >>  6): \
 ((((unsigned long)(sz)) >> 9) <=   20) ?  91 + (((unsigned long)(sz)) >>  9): \
 ((((unsigned long)(sz)) >> 9) <=   84) ? 110 + (((unsigned long)(sz)) >> 12): \
 ((((unsigned long)(sz)) >> 9) <=  340) ? 119 + (((unsigned long)(sz)) >> 15): \
 ((((unsigned long)(sz)) >> 9) <= 1364) ? 124 + (((unsigned long)(sz)) >> 18): \
                                          126)
#define idx2binblock(ix) ((unsigned long)1 << (ix / M_BINBLOCKWIDTH))
#define mark_binblock(ii) (binblocks |= idx2binblock(ii))
#define unlink(P, BK, FD) { BK = P->bk; FD = P->fd; FD->bk = BK; BK->fd = FD; }
#define link_last_remainder(P) { last_remainder->fd = last_remainder->bk = P; P->fd = P->bk = last_remainder; }
#define clear_last_remainder (last_remainder->fd = last_remainder->bk = last_remainder)
#define long_sub_size_t(x, y) (((x) < (y)) ? -(long)((y) - (x)) : (long)((x) - (y)))
#define frontlink(P, S, IDX, BK, FD) \
{ \
  if (S < M_MAX_SMALLBIN_SIZE) \
  { \
    IDX = smallbin_index(S); \
    mark_binblock(IDX); \
    BK = bin_at(IDX); \
    FD = BK->fd; \
    P->bk = BK; \
    P->fd = FD; \
    FD->bk = BK->fd = P; \
  } \
  else \
  { \
    IDX = bin_index(S); \
    BK = bin_at(IDX); \
    FD = BK->fd; \
    if (FD == BK) mark_binblock(IDX); \
    else \
    { \
      while (FD != BK && S < chunksize(FD)) FD = FD->fd; \
      BK = FD->bk; \
    } \
    P->bk = BK; \
    P->fd = FD; \
    FD->bk = BK->fd = P; \
  } \
}
void* _malloc_r(void* reent_ptr, u32 bytes) asm("_Z9_malloc_rjjjj");
void* _malloc_r(void* reent_ptr, u32 bytes);  // 0x002fd680: definition moved into src/newlib/libc/mallocr.c
#undef M_SIZE_SZ
#undef M_ALIGN_MASK
#undef M_MINSIZE
#undef M_PREV_INUSE
#undef M_SIZE_BITS
#undef M_MAX_SMALLBIN
#undef M_MAX_SMALLBIN_SIZE
#undef M_SMALLBIN_WIDTH
#undef M_BINBLOCKWIDTH
#undef bin_at
#undef next_bin
#undef prev_bin
#undef first
#undef last
#undef top
#undef last_remainder
#undef binblocks
#undef chunksize
#undef chunk2mem
#undef chunk_at_offset
#undef set_head
#undef set_foot
#undef set_inuse_bit_at_offset
#undef request2size
#undef is_small_request
#undef smallbin_index
#undef bin_index
#undef idx2binblock
#undef mark_binblock
#undef unlink
#undef link_last_remainder
#undef clear_last_remainder
#undef long_sub_size_t
#undef frontlink

// --------------------
// Copy a context block field by field using a lazily built table of field sizes.
struct Ctx318290 { void* fld[177]; u8 pad[708 - 177 * 4]; s32 f708; u8 pad2[24]; s64 f736; };
extern u8 D_01e4c7b8_x12158[176] asm("D_01e4c7b8");
extern u8 D_01e4c7b9;
extern u8 D_01e4c7ba;
extern u8 D_01e4c7bb;
extern u8 D_01e4c7bc;
extern u8 D_01e4c7bd;
extern u8 D_01e4c7be;
extern u8 D_01e4c7bf;
extern u8 D_01e4c7c0;
extern u8 D_01e4c7c1;
extern u8 D_01e4c7c2;
extern u8 D_01e4c7c3;
extern u8 D_01e4c7c4;
extern u8 D_01e4c7c5;
extern u8 D_01e4c7c6;
extern u8 D_01e4c7c7;
extern u8 D_01e4c7c8;
extern u8 D_01e4c7c9;
extern u8 D_01e4c7ca;
extern u8 D_01e4c7cb;
extern u8 D_01e4c7cc;
extern u8 D_01e4c7cd;
extern u8 D_01e4c7ce;
extern u8 D_01e4c7cf;
extern u8 D_01e4c7d0;
extern u8 D_01e4c7d1;
extern u8 D_01e4c7d2;
extern u8 D_01e4c7d3;
extern u8 D_01e4c7d4;
extern u8 D_01e4c7d5;
extern u8 D_01e4c7d6;
extern u8 D_01e4c7d7;
extern u8 D_01e4c7d8;
extern u8 D_01e4c7d9;
extern u8 D_01e4c7da;
extern u8 D_01e4c7db;
extern u8 D_01e4c7dc;
extern u8 D_01e4c7dd;
extern u8 D_01e4c7de;
extern u8 D_01e4c7df;
extern u8 D_01e4c7e0;
extern u8 D_01e4c7e1;
extern u8 D_01e4c7e2;
extern u8 D_01e4c7e3;
extern u8 D_01e4c7e4;
extern u8 D_01e4c7e5;
extern u8 D_01e4c7e6;
extern u8 D_01e4c7e7;
extern u8 D_01e4c7e8;
extern u8 D_01e4c7e9;
extern u8 D_01e4c7ea;
extern u8 D_01e4c7eb;
extern u8 D_01e4c7ec;
extern u8 D_01e4c7ed;
extern u8 D_01e4c7ee;
extern u8 D_01e4c7ef;
extern u8 D_01e4c7f0;
extern u8 D_01e4c7f1;
extern u8 D_01e4c7f2;
extern u8 D_01e4c7f3;
extern u8 D_01e4c7f4;
extern u8 D_01e4c7f5;
extern u8 D_01e4c7f6;
extern u8 D_01e4c7f7;
extern u8 D_01e4c7f8;
extern u8 D_01e4c7f9;
extern u8 D_01e4c7fa;
extern u8 D_01e4c7fb;
extern u8 D_01e4c7fc;
extern u8 D_01e4c7fd;
extern u8 D_01e4c7fe;
extern u8 D_01e4c7ff;
extern u8 D_01e4c800;
extern u8 D_01e4c801;
extern u8 D_01e4c802;
extern u8 D_01e4c803;
extern u8 D_01e4c804;
extern u8 D_01e4c805;
extern u8 D_01e4c806;
extern u8 D_01e4c807;
extern u8 D_01e4c808;
extern u8 D_01e4c809;
extern u8 D_01e4c80a;
extern u8 D_01e4c80b;
extern u8 D_01e4c80c;
extern u8 D_01e4c80d;
extern u8 D_01e4c80e;
extern u8 D_01e4c80f;
extern u8 D_01e4c810;
extern u8 D_01e4c811;
extern u8 D_01e4c812;
extern u8 D_01e4c813;
extern u8 D_01e4c814;
extern u8 D_01e4c815;
extern u8 D_01e4c816;
extern u8 D_01e4c817;
extern u8 D_01e4c818;
extern u8 D_01e4c819;
extern u8 D_01e4c81a;
extern u8 D_01e4c81b;
extern u8 D_01e4c81c;
extern u8 D_01e4c81d;
extern u8 D_01e4c81e;
extern u8 D_01e4c81f;
extern u8 D_01e4c820;
extern u8 D_01e4c821;
extern u8 D_01e4c822;
extern u8 D_01e4c823;
extern u8 D_01e4c824;
extern u8 D_01e4c825;
extern u8 D_01e4c826;
extern u8 D_01e4c827;
extern u8 D_01e4c828;
extern u8 D_01e4c829;
extern u8 D_01e4c82a;
extern u8 D_01e4c82b;
extern u8 D_01e4c82c;
extern u8 D_01e4c82d;
extern u8 D_01e4c82e;
extern u8 D_01e4c82f;
extern u8 D_01e4c830;
extern u8 D_01e4c831;
extern u8 D_01e4c832;
extern u8 D_01e4c833;
extern u8 D_01e4c834;
extern u8 D_01e4c835;
extern u8 D_01e4c836;
extern u8 D_01e4c837;
extern u8 D_01e4c838;
extern u8 D_01e4c839;
extern u8 D_01e4c83a;
extern u8 D_01e4c83b;
extern u8 D_01e4c83c;
extern u8 D_01e4c83d;
extern u8 D_01e4c83e;
extern u8 D_01e4c83f;
extern u8 D_01e4c840;
extern u8 D_01e4c841;
extern u8 D_01e4c842;
extern u8 D_01e4c843;
extern u8 D_01e4c844;
extern u8 D_01e4c845;
extern u8 D_01e4c846;
extern u8 D_01e4c847;
extern u8 D_01e4c848;
extern u8 D_01e4c849;
extern u8 D_01e4c84a;
extern u8 D_01e4c84b;
extern u8 D_01e4c84c;
extern u8 D_01e4c84d;
extern u8 D_01e4c84e;
extern u8 D_01e4c84f;
extern u8 D_01e4c850;
extern u8 D_01e4c851;
extern u8 D_01e4c852;
extern u8 D_01e4c853;
extern u8 D_01e4c854;
extern u8 D_01e4c855;
extern u8 D_01e4c856;
extern u8 D_01e4c857;
extern u8 D_01e4c858;
extern u8 D_01e4c859;
extern u8 D_01e4c85a;
extern u8 D_01e4c85b;
extern u8 D_01e4c85c;
extern u8 D_01e4c85d;
extern u8 D_01e4c85e;
extern u8 D_01e4c85f;
extern u8 D_01e4c860;
extern u8 D_01e4c861;
extern u8 D_01e4c862;
extern u8 D_01e4c863;
extern u8 D_01e4c864;
extern u8 D_01e4c865;
extern u8 D_01e4c866;
extern u8 D_01e4c867;
extern s32 D_00369d50;
s32 func_0030edb0__318290(void) asm("DIntr");
void func_0030ee00__318290(void) asm("EIntr");
extern u8 D_003191f0[];
void func_002fdd68__318290(void*, void*, u32) asm("memcpy");
s64 func_00318290(Ctx318290* dst, Ctx318290* src);  // 0x00318290: definition moved into src/libgcc/unwind-dw2.c

// --------------------
// libgcc unwind-dw2.c execute_stack_op (early GCC 3.x version: DW_OP_swap/shl/shr/shra/xor
// are missing from the outer case list, and results are pushed with stack[++stack_elt]).
typedef u64 UWord3172f0;
typedef s64 USword3172f0;
struct UCtx3172f0 { void* reg[1]; };
union Unal3172f0 {
    void* p;
    unsigned u2 __attribute__((mode(HI)));
    unsigned u4 __attribute__((mode(SI)));
    unsigned u8 __attribute__((mode(DI)));
    signed s2 __attribute__((mode(HI)));
    signed s4 __attribute__((mode(SI)));
    signed s8 __attribute__((mode(DI)));
} __attribute__((packed));
static inline void* read_pointer3172f0(const void* p) { const Unal3172f0* up = (const Unal3172f0*)p; return up->p; }
static inline int read_1u3172f0(const void* p) { return *(const unsigned char*)p; }
static inline int read_1s3172f0(const void* p) { return *(const signed char*)p; }
static inline int read_2u3172f0(const void* p) { const Unal3172f0* up = (const Unal3172f0*)p; return up->u2; }
static inline int read_2s3172f0(const void* p) { const Unal3172f0* up = (const Unal3172f0*)p; return up->s2; }
static inline unsigned int read_4u3172f0(const void* p) { const Unal3172f0* up = (const Unal3172f0*)p; return up->u4; }
static inline int read_4s3172f0(const void* p) { const Unal3172f0* up = (const Unal3172f0*)p; return up->s4; }
static inline unsigned long read_8u3172f0(const void* p) { const Unal3172f0* up = (const Unal3172f0*)p; return up->u8; }
static inline unsigned long read_8s3172f0(const void* p) { const Unal3172f0* up = (const Unal3172f0*)p; return up->s8; }
const unsigned char* func_00316f38__3172f0(const unsigned char*, UWord3172f0*) asm("func_00316f38");
const unsigned char* func_00316f70__3172f0(const unsigned char*, USword3172f0*) asm("func_00316f70");
void func_002fd160__3172f0(void) asm("func_002fd160") __attribute__((noreturn));
s64 func_00311dd0(s64, s64);
s64 __moddi3(s64, s64);
#define read_uleb128 func_00316f38__3172f0
#define read_sleb128 func_00316f70__3172f0
#define abort func_002fd160__3172f0
static inline UWord3172f0 GetGR3172f0(UCtx3172f0* context, int index) { return *(UWord3172f0*)context->reg[index]; }
UWord3172f0 func_003172f0(const unsigned char* op_ptr, const unsigned char* op_end, UCtx3172f0* context, UWord3172f0 initial);  // 0x003172f0: definition moved into src/libgcc/unwind-dw2.c
#undef read_uleb128
#undef read_sleb128
#undef abort

// --------------------
// libgcc unwind-dw2.c execute_cfa_program (GCC 3.2).
typedef u64 UWord317868;
typedef s64 USword317868;
struct RegInfo317868 {
    struct {
        union { UWord317868 reg; USword317868 offset; const unsigned char* exp; } loc;
        int how;
    } reg[177];
    RegInfo317868* prev;
};
struct FState317868 {
    RegInfo317868 regs;
    USword317868 cfa_offset;
    UWord317868 cfa_reg;
    const unsigned char* cfa_exp;
    int cfa_how;
    void* pc;
    void* personality;
    USword317868 data_align;
    UWord317868 code_align;
    unsigned char retaddr_column;
    unsigned char fde_encoding;
    unsigned char lsda_encoding;
    unsigned char saw_z;
    void* eh_ptr;
};
struct UCtx317868 { void* reg[178]; void* ra; u8 pad[20]; UWord317868 args_size; };
union Unal317868 {
    void* p;
    unsigned u2 __attribute__((mode(HI)));
    unsigned u4 __attribute__((mode(SI)));
} __attribute__((packed));
static inline int read_1u317868(const void* p) { return *(const unsigned char*)p; }
static inline int read_2u317868(const void* p) { const Unal317868* up = (const Unal317868*)p; return up->u2; }
static inline unsigned int read_4u317868(const void* p) { const Unal317868* up = (const Unal317868*)p; return up->u4; }
const unsigned char* func_00316f38(const unsigned char*, UWord317868*);
const unsigned char* func_00316f70(const unsigned char*, USword317868*);
u32 func_00316e88(unsigned char, UCtx317868*);
const unsigned char* func_00316fc8(unsigned char, u32, const unsigned char*, u32*);
void func_002fd160__317868(void) asm("func_002fd160") __attribute__((noreturn));
static inline const unsigned char* read_encoded_value317868(UCtx317868* context, unsigned char encoding,
                                                            const unsigned char* p, u32* val)
{
    return func_00316fc8(encoding, func_00316e88(encoding, context), p, val);
}
#define read_uleb128 func_00316f38
#define read_sleb128 func_00316f70
#define abort func_002fd160__317868
void func_00317868(const unsigned char* insn_ptr, const unsigned char* insn_end, UCtx317868* context, FState317868* fs);  // 0x00317868: definition moved into src/libgcc/unwind-dw2.c
#undef read_uleb128
#undef read_sleb128
#undef abort

// --------------------
// newlib (BSD) __sfvwrite: write a uio scatter list to a stdio stream.
struct Siov3032d0 { const char* iov_base; u32 iov_len; };
struct Suio3032d0 { Siov3032d0* uio_iov; s32 uio_iovcnt; s32 uio_resid; };
struct Sbuf3032d0 { u8* _base; s32 _size; };
struct File3032d0 {
    u8* _p; s32 _r; s32 _w; s16 _flags; s16 _file; Sbuf3032d0 _bf; s32 _lbfsize;
    void* _cookie; s32 (*_read)(void*, char*, s32); s32 (*_write)(void*, const char*, s32);
};
s32 __swsetup(File3032d0*);
s32 fflush(File3032d0*);
void* memmove(void*, const void*, u32);
void* memchr(const void*, s32, u32);
s32 __sfvwrite(File3032d0* fp, Suio3032d0* uio);  // 0x003032d0: definition moved into src/newlib/libc/fvwrite.c

// --------------------
// fdlibm/newlib __ieee754_rem_pio2f, EE build (_FLT_LARGEST_EXPONENT_IS_NORMAL: no inf/NaN case).
// npio2_hw is D_003775c8, two_over_pi is D_003772b0.
extern const s32 D_003775c8[];
extern const s32 D_003772b0[];
typedef union { f32 value; u32 word; } FloatShapeRp;
#define GET_FLOAT_WORD_RP(i, d) do { FloatShapeRp gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD_RP(d, i) do { FloatShapeRp sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
static const f32 zero_rp = 0.0f, half_rp = 5.0000000000e-01f, two8_rp = 2.5600000000e+02f,
    invpio2_rp = 6.3661980629e-01f,
    pio2_1_rp = 1.5707855225e+00f, pio2_1t_rp = 1.0804333214764483e-05f,
    pio2_2_rp = 1.0804272278619464e-05f, pio2_2t_rp = 6.0770999344e-11f,
    pio2_3_rp = 6.0770943833e-11f, pio2_3t_rp = 6.123233601181349e-17f;
s32 __ieee754_rem_pio2f(f32 x, f32 *y);  // 0x002fa678: definition moved into src/newlib/libm/ef_rem_pio2.c

// --------------------
// Sort the item list by kind, then by id within each kind; build per-kind groups and page counts.
struct Item2a2ff8 { u8 kind; u8 b1; u8 b2; u8 b3; u16 id; u16 x6; };
struct Grp2a2ff8 { u8 count; u8 pages; u16 pad; Item2a2ff8* first; };
struct Mgr2a2ff8 { Item2a2ff8 items[512]; Grp2a2ff8 grp[15]; s32 num; s32 x4220; s32 total; };
union MgrP2a2ff8 { Mgr2a2ff8* p; u32 u; u8 c; };
extern MgrP2a2ff8 D_0035f5e4;
#define G2a2ff8 D_0035f5e4.p
s32 func_002a43f0(void);
s32 func_002a4380(s32 i);
s32 func_002954e0(s32 i);
void func_002a2ff8(void);  // 0x002a2ff8: definition moved into src/anon/unit_002a1d38.cpp

// --------------------
// Assign ring slots to the requested ids that are not already resident.
union Ent292b40 { s16 v; u8 c; };
union Slot292b40 { u32 w; struct { u16 id; u16 slot; } h; };
struct Res292b40 { s32 id; s32 used; s32 pad[2]; };
union U0035f4bc { s32 v; u8 c; };
extern U0035f4bc D_0035f4bc;
union U0035f4d0 { s32 v; u8 c; };
extern U0035f4d0 D_0035f4d0;
union U0035f4d4 { Res292b40* v; u8 c; };
extern U0035f4d4 D_0035f4d4;
union U0035f4d8 { s16 v; u8 c; };
extern U0035f4d8 D_0035f4d8;
union U0035f4dc { Slot292b40* v; u8 c; };
extern U0035f4dc D_0035f4dc;
union U0035f4e0 { s16 v; u8 c; };
extern U0035f4e0 D_0035f4e0;
s32 func_00292a90(s16 id);
s32 func_00292af0(s16 id);
void func_00292998(void);
void func_00292eb0(void);
void func_00292b40(s16* list, s32 n);  // 00292b40: moved to src/anon/unit_00292998.cpp

// --------------------
// Pick the offset position for the given mode (random for unknown modes).
struct Obj1169e8 { u8 pad[1600]; f32 dir; u8 pad2[12]; f32 x; f32 y; f32 z; };
void func_00116938(Obj1169e8* p, f32* px, f32* py);
void func_00116990(Obj1169e8* p, f32* px, f32* py);
f32 func_0010f660(void);
u32 func_0010f648(s32 n);
void func_001169e8(Obj1169e8* p, s32 mode);  // 0x001169e8: definition moved into src/anon/unit_00114a90.cpp

// --------------------
// Sort the slot list by kind, then by the order the ids appear in the 0x13-type entry list.
struct Item279a10 { u16 id; u8 b2; u8 b3; s8 kind; u8 pad[3]; };
struct Mgr279a10 { u8 pad[7]; s8 count; u8 pad2[4]; Item279a10 items[1]; };
struct Ent279a10 { u16 id; u8 type; };
union MgrP279a10 { Mgr279a10* p; u32 u; u8 c; };
extern MgrP279a10 D_0035f230;
Ent279a10* func_001a8110_x13535(Ent279a10* p) asm("func_001a8110");
void func_00279a10(void);  // 0x00279a10: definition moved into src/anon/unit_002793b0.cpp

// --------------------
// newlib _free_r (dlmalloc 2.6.x fREe; no mmap; EE: 64-bit long).
typedef struct MChunk302e90 MChunk302e90;
struct MChunk302e90 { u32 prev_size; u32 size; MChunk302e90* fd; MChunk302e90* bk; };
typedef MChunk302e90* mchunkptr302e90;
extern u8 D_00365c50[];
void func_002fded8__302e90(void*) asm("__malloc_lock");
void func_002fdf30__302e90(void*) asm("__malloc_unlock");
#define M_SIZE_SZ 4
#define M_ALIGN_MASK 15
#define M_MINSIZE 16
#define M_PREV_INUSE 1
#define M_SIZE_BITS 3
#define M_MAX_SMALLBIN 63
#define M_MAX_SMALLBIN_SIZE 512
#define M_SMALLBIN_WIDTH 8
#define M_BINBLOCKWIDTH 4
#define bin_at(i) ((mchunkptr302e90)(D_00365c50 + 8 * (i)))
#define next_bin(b) ((mchunkptr302e90)((char*)(b) + 8))
#define prev_bin(b) ((mchunkptr302e90)((char*)(b) - 8))
#define first(b) ((b)->fd)
#define last(b) ((b)->bk)
#define top (bin_at(0)->fd)
#define last_remainder (bin_at(1))
#define binblocks (bin_at(0)->size)
#define chunksize(p) ((p)->size & ~(M_SIZE_BITS))
#define chunk2mem(p) ((void*)((char*)(p) + 2 * M_SIZE_SZ))
#define chunk_at_offset(p, s) ((mchunkptr302e90)(((char*)(p)) + (s)))
#define set_head(p, s) ((p)->size = (s))
#define set_foot(p, s) (((mchunkptr302e90)((char*)(p) + (s)))->prev_size = (s))
#define set_inuse_bit_at_offset(p, s) (((mchunkptr302e90)(((char*)(p)) + (s)))->size |= M_PREV_INUSE)
#define request2size(req) (((long)((req) + (M_SIZE_SZ + M_ALIGN_MASK)) < (long)(M_MINSIZE + M_ALIGN_MASK)) ? M_MINSIZE : \
    (((req) + (M_SIZE_SZ + M_ALIGN_MASK)) & ~(M_ALIGN_MASK)))
#define is_small_request(nb) (nb < M_MAX_SMALLBIN_SIZE - M_SMALLBIN_WIDTH)
#define smallbin_index(sz) (((unsigned long)(sz)) >> 3)
#define bin_index(sz) \
(((((unsigned long)(sz)) >> 9) ==    0) ?       (((unsigned long)(sz)) >>  3): \
 ((((unsigned long)(sz)) >> 9) <=    4) ?  56 + (((unsigned long)(sz)) >>  6): \
 ((((unsigned long)(sz)) >> 9) <=   20) ?  91 + (((unsigned long)(sz)) >>  9): \
 ((((unsigned long)(sz)) >> 9) <=   84) ? 110 + (((unsigned long)(sz)) >> 12): \
 ((((unsigned long)(sz)) >> 9) <=  340) ? 119 + (((unsigned long)(sz)) >> 15): \
 ((((unsigned long)(sz)) >> 9) <= 1364) ? 124 + (((unsigned long)(sz)) >> 18): \
                                          126)
#define idx2binblock(ix) ((unsigned long)1 << (ix / M_BINBLOCKWIDTH))
#define mark_binblock(ii) (binblocks |= idx2binblock(ii))
#define unlink(P, BK, FD) { BK = P->bk; FD = P->fd; FD->bk = BK; BK->fd = FD; }
#define link_last_remainder(P) { last_remainder->fd = last_remainder->bk = P; P->fd = P->bk = last_remainder; }
#define clear_last_remainder (last_remainder->fd = last_remainder->bk = last_remainder)
#define long_sub_size_t(x, y) (((x) < (y)) ? -(long)((y) - (x)) : (long)((x) - (y)))
#define frontlink(P, S, IDX, BK, FD) \
{ \
  if (S < M_MAX_SMALLBIN_SIZE) \
  { \
    IDX = smallbin_index(S); \
    mark_binblock(IDX); \
    BK = bin_at(IDX); \
    FD = BK->fd; \
    P->bk = BK; \
    P->fd = FD; \
    FD->bk = BK->fd = P; \
  } \
  else \
  { \
    IDX = bin_index(S); \
    BK = bin_at(IDX); \
    FD = BK->fd; \
    if (FD == BK) mark_binblock(IDX); \
    else \
    { \
      while (FD != BK && S < chunksize(FD)) FD = FD->fd; \
      BK = FD->bk; \
    } \
    P->bk = BK; \
    P->fd = FD; \
    FD->bk = BK->fd = P; \
  } \
}
extern u64 D_00366058;
extern u64 D_00366060;
s32 func_00303170__302e90(void*, u32) asm("_malloc_trim_r");
#define trim_threshold D_00366058
#define top_pad D_00366060
void _free_r(void* reent_ptr, void* mem) asm("_Z7_free_rjjjj");
void _free_r(void* reent_ptr, void* mem);  // 0x00302e90: definition moved into src/newlib/libc/freer.c
#undef trim_threshold
#undef top_pad
#undef M_SIZE_SZ
#undef M_ALIGN_MASK
#undef M_MINSIZE
#undef M_PREV_INUSE
#undef M_SIZE_BITS
#undef M_MAX_SMALLBIN
#undef M_MAX_SMALLBIN_SIZE
#undef M_SMALLBIN_WIDTH
#undef M_BINBLOCKWIDTH
#undef bin_at
#undef next_bin
#undef prev_bin
#undef first
#undef last
#undef top
#undef last_remainder
#undef binblocks
#undef chunksize
#undef chunk2mem
#undef chunk_at_offset
#undef set_head
#undef set_foot
#undef set_inuse_bit_at_offset
#undef request2size
#undef is_small_request
#undef smallbin_index
#undef bin_index
#undef idx2binblock
#undef mark_binblock
#undef unlink
#undef link_last_remainder
#undef clear_last_remainder
#undef long_sub_size_t
#undef frontlink

// --------------------
// libgcc unwind.inc _Unwind_RaiseException (GCC 3.2).
typedef u64 UWord3189e0;
typedef s64 USword3189e0;
struct RegInfo3189e0 {
    struct {
        union { UWord3189e0 reg; USword3189e0 offset; const unsigned char* exp; } loc;
        int how;
    } reg[177];
    RegInfo3189e0* prev;
};
struct UCtx3189e0;
struct UExc3189e0;
typedef int (*UPers3189e0)(int, int, u64, UExc3189e0*, UCtx3189e0*);
struct FState3189e0 {
    RegInfo3189e0 regs;
    USword3189e0 cfa_offset;
    UWord3189e0 cfa_reg;
    const unsigned char* cfa_exp;
    int cfa_how;
    void* pc;
    UPers3189e0 personality;
    USword3189e0 data_align;
    UWord3189e0 code_align;
    unsigned char retaddr_column;
    unsigned char fde_encoding;
    unsigned char lsda_encoding;
    unsigned char saw_z;
    void* eh_ptr;
};
struct UBases3189e0 { void* tbase; void* dbase; void* func; };
struct UCtx3189e0 {
    void* reg[177];
    void* cfa;
    void* ra;
    void* lsda;
    UBases3189e0 bases;
    UWord3189e0 args_size;
};
struct UExc3189e0 { u64 exception_class; void (*cleanup)(int, UExc3189e0*); UWord3189e0 private_1; UWord3189e0 private_2; };
int func_00317d80_x13824(UCtx3189e0* context, FState3189e0* fs) asm("func_00317d80");
void func_003181a0(UCtx3189e0* context, FState3189e0* fs);
void func_003181f8(UCtx3189e0* context, void* outer_cfa, void* outer_ra);
int func_00318908(UExc3189e0* exc, UCtx3189e0* context);
long func_00318290__3189e0(UCtx3189e0* current, UCtx3189e0* target) asm("func_00318290");
static inline u32 uw_identify_context3189e0 (UCtx3189e0 *context) { return (u32)context->ra; }
int func_003189e0(UExc3189e0* exc);  // 0x003189e0: definition moved into src/libgcc/unwind-dw2.c

// --------------------
// 4x4 matrix copy: hand-written lq/sq through t0-t3 (as in the original).
#define MCOPY10abf0(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t" \
    "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct Mtx10abf0 {
    f32 m[16];
    Mtx10abf0& operator=(const Mtx10abf0& o) {
        if (this != &o) MCOPY10abf0(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct Blk10abf0 { u32 flags; u32 f4; u64 q[6]; };
union BlkU10abf0 { Blk10abf0 b; u8 c; };
union LP10abf0 { u32* p; u8 c; };
union Id10abf0 { s16 v; u8 c; };
union IP10abf0 { Id10abf0* p; u8 c; };
struct Ent10abf0 {
    LP10abf0 list;
    union { void* p; u8 c; } key;
    IP10abf0 ids;
    u32 pad12;
    Blk10abf0 blk;
    u8 pad72[8];
    Mtx10abf0 m1;
    Mtx10abf0 m2;
    Mtx10abf0 m3;
    u32 f272;
    u8 pad276[12];
};
extern u32 D_0033cc68_x13907 asm("D_0033cc68");
extern Ent10abf0* D_0033cc70_x13908 asm("D_0033cc70");
void* func_0010abc8(u32 size);
void func_0010abf0(void* key, Mtx10abf0* m1, BlkU10abf0* blk, Id10abf0* ids, Mtx10abf0* m2, Mtx10abf0* m3, u32* list, u32 v);  // 0010abf0: moved to src/anon/unit_0010a918.cpp

// --------------------
// Quantise six floats to s16 with the per-mode bias/scale tables.
extern f32 D_00348d30[];
extern f32 D_00348d40[];
#define Q144e50(f) do { \
    if (!(-32768.0f < (f))) { \
        (f) = ((f) < -32767.0f) ? -32767.0f : ((32767.0f < (f)) ? 32767.0f : (f)); \
    } \
} while (0)
#define R144e50(f) do { \
    if (!((f) < 32768.0f)) { \
        (f) = ((f) < -32767.0f) ? -32767.0f : ((32767.0f < (f)) ? 32767.0f : (f)); \
    } \
} while (0)
union O144e50 { s16 v; u8 c; };
void func_00144e50(O144e50* out, f32* in, s32 mode);  // 0x00144e50: definition moved into src/anon/unit_00144450.cpp

// --------------------
// Effect particle: integrate motion, apply the per-frame delta, then emit its sprite.
struct Gs1f7398 { u8 pad[16]; u8* ent; u8 pad2[148]; u64 st; };
struct Idx1f7398 { s32 f0; s32 f4; s32 f8; };
struct Ctx1f7398 { u8 pad[12]; Idx1f7398* idx; };
struct Mot1f7398 { f32 x, vx, ax, pad; f32 y, vy, ay, z, vz, az; };
struct Req1f7398 {
    s32 id; s32 tex; f32 dx, dvx, dax; s32 sx; s32 sy; u8 frame; u8 pad29[3];
    f32 dy, dvy, day, dz, dvz, daz; u8 f56;
};
struct Tex1f7398 { u8 pad[16]; u32 bits; u8 pad2[16]; };
extern s32 D_01d9ea9c;
extern Gs1f7398* D_01d9e6e0_x13984 asm("D_01d9e6e0");
extern Gs1f7398* D_01d9e6e4;
extern u8* D_01d9eaa4;
union IdU1f7398 { s32 v; u8 c; };
union TagU1f7398 { u64 v; u8 c; };
union PkU1f7398 { u8* p; u8 c; };
void sceGsSetDefLoadImage(u8* p, u32 a, s32 b, u32 c, s32 d, s32 e, s32 f, s32 g);
void func_00222aa8(s32 a, s32 b, u8* p, f32 x);
void func_0020e7a8(u8* p, s32 a, s32 b, s32 c);
void func_00222d40(s32 tex, u8* pos, u32 frame, s32 y, s32 z, s32 a, s32 b);
void func_001f7398(u8* o, Req1f7398* r, Ctx1f7398* c);  // 0x001f7398: definition moved into src/anon/unit_001f7010.cpp

// --------------------
// Effect particle: integrate motion, apply the per-frame delta, then emit its sprite.
struct Gs1f7878 { u8 pad[16]; u8* ent; u8 pad2[148]; u64 st; };
struct Idx1f7878 { s32 f0; s32 f4; s32 f8; };
struct Ctx1f7878 { u8 pad[12]; Idx1f7878* idx; };
struct Mot1f7878 { f32 x, vx, ax, pad; f32 y, vy, ay, z, vz, az; };
struct Req1f7878 {
    s32 id; s32 tex; f32 dx, dvx, dax; s32 sx; s32 sy; u8 frame; u8 pad29[3];
    f32 dy, dvy, day, dz, dvz, daz; u8 f56;
};
struct Tex1f7878 { u8 pad[16]; u32 bits; u8 pad2[16]; };
extern s32 D_01d9ea9c;
extern Gs1f7878* D_01d9e6e0_x14045 asm("D_01d9e6e0");
extern Gs1f7878* D_01d9e6e4_x14046 asm("D_01d9e6e4");
extern u8* D_01d9eaa4;
union IdU1f7878 { s32 v; u8 c; };
union TagU1f7878 { u64 v; u8 c; };
union PkU1f7878 { u8* p; u8 c; };
void sceGsSetDefLoadImage(u8* p, u32 a, s32 b, u32 c, s32 d, s32 e, s32 f, s32 g);
void func_00222aa8(s32 a, s32 b, u8* p, f32 x);
void func_0020e7a8(u8* p, s32 a, s32 b, s32 c);
void func_00222d40(s32 tex, u8* pos, u32 frame, s32 y, s32 z, s32 a, s32 b);
void func_001f7878(u8* o, Req1f7878* r, Ctx1f7878* c);  // 0x001f7878: definition moved into src/anon/unit_001f7010.cpp

// --------------------
// Effect particle: integrate motion, apply the per-frame delta, then emit its sprite.
struct Gs1fe398 { u8 pad[16]; u8* ent; u8 pad2[148]; u64 st; };
struct Idx1fe398 { s32 f0; s32 f4; s32 f8; s32 f12; };
struct Ctx1fe398 { u8 pad[12]; Idx1fe398* idx; };
struct Mot1fe398 { f32 x, vx, ax, pad; f32 y, vy, ay, z, vz, az; };
struct Req1fe398 {
    s32 id; s32 tex; f32 dx, dvx, dax; s32 sx; s32 sy; u8 frame; u8 pad29[3];
    f32 dy, dvy, day, dz, dvz, daz; u8 b56, b57, b58, b59, b60;
};
struct Tex1fe398 { u8 pad[16]; u32 bits; u8 pad2[16]; };
extern s32 D_01d9ea9c;
extern Gs1fe398* D_01d9e6e0_x14106 asm("D_01d9e6e0");
extern Gs1fe398* D_01d9e6e4_x14107 asm("D_01d9e6e4");
extern u8* D_01d9eaa4;
union IdU1fe398 { s32 v; u8 c; };
union TagU1fe398 { u64 v; u8 c; };
union PkU1fe398 { u8* p; u8 c; };
void sceGsSetDefLoadImage(u8* p, u32 a, s32 b, u32 c, s32 d, s32 e, s32 f, s32 g);
void func_00222aa8(s32 a, s32 b, u8* p, f32 x);
void func_0020e7a8(u8* p, s32 a, s32 b, s32 c);
void func_00222d40_x14115(s32 tex, u8* pos, u32 frame, s32 y, s32 z, s32 a, u8* b) asm("func_00222d40");
void func_001fe398(u8* o, Req1fe398* r, Ctx1fe398* c);  // 0x001fe398: definition moved into src/anon/unit_001fe158.cpp

// --------------------
// newlib malloc_extend_top (dlmalloc 2.6.x; no mmap; EE: 64-bit long).
typedef struct MChunk2fd428 MChunk2fd428;
struct MChunk2fd428 { u32 prev_size; u32 size; MChunk2fd428* fd; MChunk2fd428* bk; };
typedef MChunk2fd428* mchunkptr2fd428;
extern u8 D_00365c50[];
void func_002fded8__2fd428(void*) asm("__malloc_lock");
void func_002fdf30__2fd428(void*) asm("__malloc_unlock");
#define M_SIZE_SZ 4
#define M_ALIGN_MASK 15
#define M_MINSIZE 16
#define M_PREV_INUSE 1
#define M_SIZE_BITS 3
#define M_MAX_SMALLBIN 63
#define M_MAX_SMALLBIN_SIZE 512
#define M_SMALLBIN_WIDTH 8
#define M_BINBLOCKWIDTH 4
#define bin_at(i) ((mchunkptr2fd428)(D_00365c50 + 8 * (i)))
#define next_bin(b) ((mchunkptr2fd428)((char*)(b) + 8))
#define prev_bin(b) ((mchunkptr2fd428)((char*)(b) - 8))
#define first(b) ((b)->fd)
#define last(b) ((b)->bk)
#define top (bin_at(0)->fd)
#define last_remainder (bin_at(1))
#define binblocks (bin_at(0)->size)
#define chunksize(p) ((p)->size & ~(M_SIZE_BITS))
#define chunk2mem(p) ((void*)((char*)(p) + 2 * M_SIZE_SZ))
#define chunk_at_offset(p, s) ((mchunkptr2fd428)(((char*)(p)) + (s)))
#define set_head(p, s) ((p)->size = (s))
#define set_foot(p, s) (((mchunkptr2fd428)((char*)(p) + (s)))->prev_size = (s))
#define set_inuse_bit_at_offset(p, s) (((mchunkptr2fd428)(((char*)(p)) + (s)))->size |= M_PREV_INUSE)
#define request2size(req) (((long)((req) + (M_SIZE_SZ + M_ALIGN_MASK)) < (long)(M_MINSIZE + M_ALIGN_MASK)) ? M_MINSIZE : \
    (((req) + (M_SIZE_SZ + M_ALIGN_MASK)) & ~(M_ALIGN_MASK)))
#define is_small_request(nb) (nb < M_MAX_SMALLBIN_SIZE - M_SMALLBIN_WIDTH)
#define smallbin_index(sz) (((unsigned long)(sz)) >> 3)
#define bin_index(sz) \
(((((unsigned long)(sz)) >> 9) ==    0) ?       (((unsigned long)(sz)) >>  3): \
 ((((unsigned long)(sz)) >> 9) <=    4) ?  56 + (((unsigned long)(sz)) >>  6): \
 ((((unsigned long)(sz)) >> 9) <=   20) ?  91 + (((unsigned long)(sz)) >>  9): \
 ((((unsigned long)(sz)) >> 9) <=   84) ? 110 + (((unsigned long)(sz)) >> 12): \
 ((((unsigned long)(sz)) >> 9) <=  340) ? 119 + (((unsigned long)(sz)) >> 15): \
 ((((unsigned long)(sz)) >> 9) <= 1364) ? 124 + (((unsigned long)(sz)) >> 18): \
                                          126)
#define idx2binblock(ix) ((unsigned long)1 << (ix / M_BINBLOCKWIDTH))
#define mark_binblock(ii) (binblocks |= idx2binblock(ii))
#define unlink(P, BK, FD) { BK = P->bk; FD = P->fd; FD->bk = BK; BK->fd = FD; }
#define link_last_remainder(P) { last_remainder->fd = last_remainder->bk = P; P->fd = P->bk = last_remainder; }
#define clear_last_remainder (last_remainder->fd = last_remainder->bk = last_remainder)
#define long_sub_size_t(x, y) (((x) < (y)) ? -(long)((y) - (x)) : (long)((x) - (y)))
#define frontlink(P, S, IDX, BK, FD) \
{ \
  if (S < M_MAX_SMALLBIN_SIZE) \
  { \
    IDX = smallbin_index(S); \
    mark_binblock(IDX); \
    BK = bin_at(IDX); \
    FD = BK->fd; \
    P->bk = BK; \
    P->fd = FD; \
    FD->bk = BK->fd = P; \
  } \
  else \
  { \
    IDX = bin_index(S); \
    BK = bin_at(IDX); \
    FD = BK->fd; \
    if (FD == BK) mark_binblock(IDX); \
    else \
    { \
      while (FD != BK && S < chunksize(FD)) FD = FD->fd; \
      BK = FD->bk; \
    } \
    P->bk = BK; \
    P->fd = FD; \
    FD->bk = BK->fd = P; \
  } \
}
extern u64 D_00366060;
extern char* D_00366068;
extern u64 D_00366070;
extern u64 D_00366078;
extern s32 D_00366080;
char* func_002fea70(void* reent, s32 size);
void _free_r(void* reent_ptr, void* mem) asm("_Z7_free_rjjjj");
#define top_pad D_00366060
#define sbrk_base D_00366068
#define max_sbrked_mem D_00366070
#define max_total_mem D_00366078
#define sbrked_mem D_00366080
#define initial_top ((mchunkptr2fd428)(bin_at(0)))
void func_002fd428(void* reent_ptr, u32 nb);  // 0x002fd428: definition moved into src/newlib/libc/mallocr.c
#undef top_pad
#undef sbrk_base
#undef max_sbrked_mem
#undef max_total_mem
#undef sbrked_mem
#undef initial_top
#undef M_SIZE_SZ
#undef M_ALIGN_MASK
#undef M_MINSIZE
#undef M_PREV_INUSE
#undef M_SIZE_BITS
#undef M_MAX_SMALLBIN
#undef M_MAX_SMALLBIN_SIZE
#undef M_SMALLBIN_WIDTH
#undef M_BINBLOCKWIDTH
#undef bin_at
#undef next_bin
#undef prev_bin
#undef first
#undef last
#undef top
#undef last_remainder
#undef binblocks
#undef chunksize
#undef chunk2mem
#undef chunk_at_offset
#undef set_head
#undef set_foot
#undef set_inuse_bit_at_offset
#undef request2size
#undef is_small_request
#undef smallbin_index
#undef bin_index
#undef idx2binblock
#undef mark_binblock
#undef unlink
#undef link_last_remainder
#undef clear_last_remainder
#undef long_sub_size_t
#undef frontlink

// --------------------
// Fade controller: advance the timer for the current fade state and update the output level.
struct Fade237ae8 {
    u8 pad[68]; f32 speed; f32 time; u8 pad76[4]; s32 state; f32 t; f32 dur; f32 wait;
    s32 dur_init; s32 wait_init; u8 pad104[4]; f32 out;
};
extern f32 D_00349e14;
f32 sinf(f32 x);
void func_00237ae8(Fade237ae8* p);  // 0x00237ae8: definition moved into src/anon/unit_00237068.cpp

// --------------------
// newlib dtoa.c quorem (Pack_32, IEEE_8087).
struct Bigint301708 { Bigint301708* _next; s32 _k, _maxwds, _sign, _wds; u32 _x[1]; };
s32 __mcmp(Bigint301708* a, Bigint301708* b);
#define Storeinc301708(a, b, c) (((unsigned short*)a)[1] = (unsigned short)b, ((unsigned short*)a)[0] = (unsigned short)c, a++)
s32 func_00301708(Bigint301708* b, Bigint301708* S);  // 0x00301708: definition moved into src/newlib/libc/dtoa.c
#undef Storeinc301708

// --------------------
// libgcc fp-bit.c _fpadd_parts (DFmode; GCC 3.2).
typedef enum { CLASS_SNAN313c58, CLASS_QNAN313c58, CLASS_ZERO313c58, CLASS_NUMBER313c58, CLASS_INFINITY313c58 } fp_class313c58;
struct Fp313c58 {
    u32 fclass;
    unsigned int sign;
    int normal_exp;
    union { u64 ll; u32 l[2]; } fraction;
};
extern const Fp313c58 D_00378498;
static inline int isnan313c58(Fp313c58* x) { return x->fclass == CLASS_SNAN313c58 || x->fclass == CLASS_QNAN313c58; }
static inline int isinf313c58(Fp313c58* x) { return x->fclass == CLASS_INFINITY313c58; }
static inline int iszero313c58(Fp313c58* x) { return x->fclass == CLASS_ZERO313c58; }
#define LSHIFT313c58(a) { a = (a & 1) | (a >> 1); }
#define IMPLICIT_1_313c58 ((u64)1 << 60)
#define IMPLICIT_2_313c58 ((u64)1 << 61)
Fp313c58* func_00313c58(Fp313c58* a, Fp313c58* b, Fp313c58* tmp);  // 0x00313c58: definition moved into src/libgcc/_addsub_df.c
#undef LSHIFT313c58
#undef IMPLICIT_1_313c58
#undef IMPLICIT_2_313c58

// --------------------
// libgcc fp-bit.c _fpmul_parts (DFmode; GCC 3.2).
typedef enum { CLASS_SNAN313f98, CLASS_QNAN313f98, CLASS_ZERO313f98, CLASS_NUMBER313f98, CLASS_INFINITY313f98 } fp_class313f98;
struct Fp313f98 {
    u32 fclass;
    unsigned int sign;
    int normal_exp;
    union { u64 ll; u32 l[2]; } fraction;
};
extern const Fp313f98 D_00378498_x14674 asm("D_00378498");
static inline int isnan313f98(Fp313f98* x) { return x->fclass == CLASS_SNAN313f98 || x->fclass == CLASS_QNAN313f98; }
static inline int isinf313f98(Fp313f98* x) { return x->fclass == CLASS_INFINITY313f98; }
static inline int iszero313f98(Fp313f98* x) { return x->fclass == CLASS_ZERO313f98; }
#define LSHIFT313f98(a) { a = (a & 1) | (a >> 1); }
#define IMPLICIT_1_313f98 ((u64)1 << 60)
#define IMPLICIT_2_313f98 ((u64)1 << 61)
Fp313f98* func_00313f98(Fp313f98* a, Fp313f98* b, Fp313f98* tmp);  // 0x00313f98: definition moved into src/libgcc/_mul_df.c
#undef LSHIFT313f98
#undef IMPLICIT_1_313f98
#undef IMPLICIT_2_313f98

// --------------------
// libgcc unwind-dw2.c uw_update_context_1 (GCC 3.2).
typedef u64 UWord317fc8;
typedef s64 USword317fc8;
struct RegInfo317fc8 {
    struct {
        union { UWord317fc8 reg; USword317fc8 offset; const unsigned char* exp; } loc;
        u32 how;
    } reg[177];
    RegInfo317fc8* prev;
};
struct UCtx317fc8;
struct UExc317fc8;
typedef int (*UPers317fc8)(int, int, u64, UExc317fc8*, UCtx317fc8*);
struct FState317fc8 {
    RegInfo317fc8 regs;
    USword317fc8 cfa_offset;
    UWord317fc8 cfa_reg;
    const unsigned char* cfa_exp;
    int cfa_how;
    void* pc;
    UPers317fc8 personality;
    USword317fc8 data_align;
    UWord317fc8 code_align;
    unsigned char retaddr_column;
    unsigned char fde_encoding;
    unsigned char lsda_encoding;
    unsigned char saw_z;
    void* eh_ptr;
};
struct UBases317fc8 { void* tbase; void* dbase; void* func; };
struct UCtx317fc8 {
    void* reg[177];
    void* cfa;
    void* ra;
    void* lsda;
    UBases317fc8 bases;
    UWord317fc8 args_size;
};
struct UExc317fc8 { u64 exception_class; void (*cleanup)(int, UExc317fc8*); UWord317fc8 private_1; UWord317fc8 private_2; };
const unsigned char* func_00316f38(const unsigned char*, UWord317fc8*);
UWord317fc8 func_003172f0_x14819(const unsigned char* op_ptr, const unsigned char* op_end, UCtx317fc8* context, UWord317fc8 initial) asm("func_003172f0");
void func_002fd160__317fc8(void) asm("func_002fd160") __attribute__((noreturn));
static inline UWord317fc8 _Unwind_GetGR317fc8 (UCtx317fc8 *context, int index)
{
  return * (UWord317fc8 *) context->reg[index];
}
void func_00317fc8(UCtx317fc8* context, FState317fc8* fs);  // 0x00317fc8: definition moved into src/libgcc/unwind-dw2.c

// --------------------
// libgcc unwind.inc _Unwind_Resume (GCC 3.2).
typedef u64 UWord318fc0;
typedef s64 USword318fc0;
struct RegInfo318fc0 {
    struct {
        union { UWord318fc0 reg; USword318fc0 offset; const unsigned char* exp; } loc;
        int how;
    } reg[177];
    RegInfo318fc0* prev;
};
struct UCtx318fc0;
struct UExc318fc0;
typedef int (*UPers318fc0)(int, int, u64, UExc318fc0*, UCtx318fc0*);
struct FState318fc0 {
    RegInfo318fc0 regs;
    USword318fc0 cfa_offset;
    UWord318fc0 cfa_reg;
    const unsigned char* cfa_exp;
    int cfa_how;
    void* pc;
    UPers318fc0 personality;
    USword318fc0 data_align;
    UWord318fc0 code_align;
    unsigned char retaddr_column;
    unsigned char fde_encoding;
    unsigned char lsda_encoding;
    unsigned char saw_z;
    void* eh_ptr;
};
struct UBases318fc0 { void* tbase; void* dbase; void* func; };
struct UCtx318fc0 {
    void* reg[177];
    void* cfa;
    void* ra;
    void* lsda;
    UBases318fc0 bases;
    UWord318fc0 args_size;
};
struct UExc318fc0 { u64 exception_class; void (*cleanup)(int, UExc318fc0*); UWord318fc0 private_1; UWord318fc0 private_2; };
void func_003181f8_x14925(UCtx318fc0* context, void* outer_cfa, void* outer_ra) asm("func_003181f8");
int func_00318908_x14926(UExc318fc0* exc, UCtx318fc0* context) asm("func_00318908");
int func_00318ca0(UExc318fc0* exc, UCtx318fc0* context);
long func_00318290__318fc0(UCtx318fc0* current, UCtx318fc0* target) asm("func_00318290");
void func_002fd160__318fc0(void) asm("func_002fd160") __attribute__((noreturn));
void func_00318fc0(UExc318fc0* exc);  // 0x00318fc0: definition moved into src/libgcc/unwind-dw2.c

// --------------------
// Model instance setup: construct members, point at the model data tables and reset the bounds.
struct Hdr145830 { u8 pad[20]; s32 o20; u32 n24; s32 o28; u32 n32; s32 o36; u32 n40; };
union P145830 { u8* p; u8 c; };
union H145830 { struct Hdr145830* p; u8 c; };
struct E8_145830 { s32 a; u32 b; };
struct Obj145830 {
    H145830 hdr; P145830 t4; P145830 t8; P145830 t12; u32 n16, n20, n24, f28;
    u8 m32[256]; u8 m288[1624]; u8 f1912; u8 f1913; u8 pad1914[22]; u8 m1936[1232];
    u8 e3168[16][880]; E8_145830 e17248[512];
    s32 f21344, f21348, f21352, f21356, f21360, f21364, f21368, f21372;
};
void func_00106ab8(u8* p);
void func_001070c8(u8* p);
void func_0015e4e0(u8* p);
void func_0015e9e0(u8* p);
void func_0031a830(u32* p);
void func_001447c0_x14971(u8* p, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f) asm("func_001447c0");
void func_00145b90(Obj145830* o, s32 a);
void func_00146d28(Obj145830* o);
void func_00145830(Obj145830* o, Hdr145830* h, u8 flag, s32 a);  // 0x00145830: definition moved into src/anon/unit_00145600.cpp

// --------------------
// Copy constructor: base part, vtable, then the member data.
union W324bc0 { s32 v; u8 c; };
struct Obj324bc0 {
    u32 vt;
    u8 pad4[172];
    s32 f176;
    s32 f180;
    W324bc0 a184[13];
    s32 f236;
    s32 f240;
    s32 f244;
    s32 f248;
    s32 f252;
    f32 f256;
    f32 f260;
    f32 f264;
    s32 f268;
    s32 f272;
    s32 f276;
    f32 f280;
    f32 f284;
    f32 f288;
    f32 f292;
    f32 f296;
    f32 f300;
    f32 f304;
    f32 f308;
    f32 f312;
    f32 f316;
    s32 f320;
    s32 f324;
    s32 f328;
    s32 f332;
    s32 f336;
    s32 f340;
};
extern u8 D_0035eaf8[];
void func_00324d50(Obj324bc0* d, Obj324bc0* s);
void func_00324bc0(Obj324bc0* d, Obj324bc0* s);  // 0x00324bc0: definition moved into src/anon/unit_00324808.cpp

// --------------------
// dk::Camera::draw2Camera: lazily construct the two full-screen fade sprites, then draw them.
extern s8 D_004f3b50;
extern s8 D_004f3b58;
extern u8 D_004f3b60[];
extern u8 D_004f3e70[];
extern u8 D_0034c768;
extern u8 D_0034c76c;
void func_0014c050(u8* s);
void func_002fd188(void (*fn)(void));
void func_001623d8(void);
void func_001623f0(void);
void func_0014b5e0(u8* s, s32 tex);
void func_0014b630(u8* s, s32 a);
void func_0014b208(u8* s, u16 w, u16 h);
void func_0014b5e8(u8* s, u64 uv0, u64 uv1);
void func_0014b628(u8* s, u64 a);
void func_0014b220(u8* s, u8 r, u8 g, u8 b, u8 a);
void func_0014c350(u8* s);
void func_0014e098(s32 a);
void draw2Camera_161aa8(void) asm("_ZN2dk6Camera11draw2CameraEv");
void draw2Camera_161aa8(void);  // 0x00161aa8: definition moved into src/anon/unit_001614e8.cpp

// --------------------
// libgcc unwind-dw2.c uw_frame_state_for (GCC 3.2).
typedef u64 UWord317d80;
typedef s64 USword317d80;
struct RegInfo317d80 {
    struct {
        union { UWord317d80 reg; USword317d80 offset; const unsigned char* exp; } loc;
        u32 how;
    } reg[177];
    RegInfo317d80* prev;
};
struct UCtx317d80;
struct UExc317d80;
typedef int (*UPers317d80)(int, int, u64, UExc317d80*, UCtx317d80*);
struct FState317d80 {
    RegInfo317d80 regs;
    USword317d80 cfa_offset;
    UWord317d80 cfa_reg;
    const unsigned char* cfa_exp;
    int cfa_how;
    void* pc;
    UPers317d80 personality;
    USword317d80 data_align;
    UWord317d80 code_align;
    unsigned char retaddr_column;
    unsigned char fde_encoding;
    unsigned char lsda_encoding;
    unsigned char saw_z;
    void* eh_ptr;
};
struct UBases317d80 { void* tbase; void* dbase; void* func; };
struct UCtx317d80 {
    void* reg[177];
    void* cfa;
    void* ra;
    void* lsda;
    UBases317d80 bases;
    UWord317d80 args_size;
};
struct UExc317d80 { u64 exception_class; void (*cleanup)(int, UExc317d80*); UWord317d80 private_1; UWord317d80 private_2; };
struct Fde317d80 { u32 length; s32 CIE_delta; unsigned char pc_begin[1]; };
struct Cie317d80 { u32 length; s32 CIE_id; u8 version; unsigned char augmentation[1]; };
void* func_002fde18__317d80(void* p, s32 c, u32 n) asm("func_002fde18");
Fde317d80* func_00101698(void* pc, UBases317d80* bases);
const unsigned char* func_00317140(Cie317d80* cie, UCtx317d80* context, FState317d80* fs);
void func_00317868__317d80(const unsigned char* insn, const unsigned char* end, UCtx317d80* context, FState317d80* fs) asm("func_00317868");
u32 func_00316e20(unsigned char encoding);
const unsigned char* func_00316f38(const unsigned char*, UWord317d80*);
u32 func_00316e88__317d80(unsigned char, UCtx317d80*) asm("func_00316e88");
const unsigned char* func_00316fc8(unsigned char, u32, const unsigned char*, u32*);
static inline const unsigned char* read_encoded_value317d80(UCtx317d80* context, unsigned char encoding, const unsigned char* p, u32* val)
{
  return func_00316fc8 (encoding, func_00316e88__317d80 (encoding, context), p, val);
}
static inline Cie317d80* get_cie317d80(Fde317d80* f)
{
  return (Cie317d80*) ((char*) &f->CIE_delta - f->CIE_delta);
}
int func_00317d80(UCtx317d80* context, FState317d80* fs);  // 0x00317d80: definition moved into src/libgcc/unwind-dw2.c

// --------------------
// Menu teardown: free the windows, delete the helper objects and the item panel array.
struct VObj00247e80 { struct { void* f0; void* f4; void* f8; void (*dtor)(VObj00247e80*); void (*del)(VObj00247e80*); }* vt; };
struct Panel00247e80 { struct { void* f0; void* f4; void* f8; void (*dtor)(Panel00247e80*); }* vt; u8 pad[404]; };
struct Alloc00247e80 { struct { void* f0; void (*free)(Alloc00247e80*, void*); }* vt; };
struct Heap00247e80 { u8 pad[20]; Alloc00247e80* a; };
extern void* D_0035ed4c_x15274 asm("D_0035ed4c");
extern void* D_0035ed50;
extern VObj00247e80* D_0035ed54_x15276 asm("D_0035ed54");
extern VObj00247e80* D_0035ed58;
extern VObj00247e80* D_0035ed5c;
extern void* D_0035ed60;
extern Panel00247e80* D_0035ed64_x15280 asm("D_0035ed64");
extern Alloc00247e80* D_0032ba14_x15281 asm("D_0032ba14");
extern Heap00247e80* D_00347f80_x15282 asm("D_00347f80");
void func_00288b00(void* w);
void func_00288c20(void* w);
void func_002b3fb0(void* o);
void func_00247e80(void);  // 0x00247e80: definition moved into src/anon/unit_00242478.cpp

// --------------------

// --------------------

// --------------------
// Menu teardown: free the windows, delete the helper objects and the item panel array.
struct VObj0024b3a0 { struct { void* f0; void* f4; void* f8; void (*dtor)(VObj0024b3a0*); void (*del)(VObj0024b3a0*); }* vt; };
struct Panel0024b3a0 { struct { void* f0; void* f4; void* f8; void (*dtor)(Panel0024b3a0*); }* vt; u8 pad[404]; };
struct Alloc0024b3a0 { struct { void* f0; void (*free)(Alloc0024b3a0*, void*); }* vt; };
struct Heap0024b3a0 { u8 pad[20]; Alloc0024b3a0* a; };
extern void* D_0035eda8_x15319 asm("D_0035eda8");
extern void* D_0035edac;
extern VObj0024b3a0* D_0035edb0_x15321 asm("D_0035edb0");
extern VObj0024b3a0* D_0035edb4;
extern VObj0024b3a0* D_0035edb8;
extern void* D_0035edc0;
extern Panel0024b3a0* D_0035edbc_x15325 asm("D_0035edbc");
extern Alloc0024b3a0* D_0032ba14_x15326 asm("D_0032ba14");
extern Heap0024b3a0* D_00347f80_x15327 asm("D_00347f80");
void func_00288b00(void* w);
void func_00288c20(void* w);
void func_002b3fb0(void* o);
void func_0024b3a0(void);  // 0x0024b3a0: definition moved into src/anon/unit_00249ef0.cpp

// --------------------
// Menu teardown: free the windows, delete the helper objects and the item panel array.
struct VObj0024f528 { struct { void* f0; void* f4; void* f8; void (*dtor)(VObj0024f528*); void (*del)(VObj0024f528*); }* vt; };
struct Panel0024f528 { struct { void* f0; void* f4; void* f8; void (*dtor)(Panel0024f528*); }* vt; u8 pad[404]; };
struct Alloc0024f528 { struct { void* f0; void (*free)(Alloc0024f528*, void*); }* vt; };
struct Heap0024f528 { u8 pad[20]; Alloc0024f528* a; };
extern void* D_0035ee34_x15360 asm("D_0035ee34");
extern void* D_0035ee38_x15361 asm("D_0035ee38");
extern VObj0024f528* D_0035ee3c_x15362 asm("D_0035ee3c");
extern VObj0024f528* D_0035ee40;
extern VObj0024f528* D_0035ee44;
extern void* D_0035ee4c_x15365 asm("D_0035ee4c");
extern Panel0024f528* D_0035ee48_x15366 asm("D_0035ee48");
extern Alloc0024f528* D_0032ba14_x15367 asm("D_0032ba14");
extern Heap0024f528* D_00347f80_x15368 asm("D_00347f80");
void func_00288b00(void* w);
void func_00288c20(void* w);
void func_002b3fb0(void* o);
void func_0024f528(void);  // 0x0024f528: definition moved into src/anon/unit_0024e7e8.cpp

// --------------------
// Build an object's world matrix: rotation (fixed-point angles), per-axis scale, translation, then the height offset.
struct Src20c860 { f32 pos[4]; u8 pad16[24]; union { u64 xy; s32 r[2]; } rot; s32 rz; u8 pad52[32]; f32 scl[3]; };
struct Par20c860 { u8 pad[224]; f32 hs; f32 ho; };
extern u8 D_01d9ea40[];
extern u8 D_01d9e730[];
extern u8 D_01d9e8c0[];
void func_002f4000_x15402(f32* m) asm("sceVu0UnitMatrix");
void sceVu0RotMatrix(f32* o, void* a, f32* v);
void func_002f3d08_x15404(f32* o, void* a, void* b) asm("sceVu0MulMatrix");
void sceVu0ScaleVector(f32* o, f32* a, f32 s);
void func_002f3f88_x15406(f32* o, Src20c860* a) asm("sceVu0CopyVector");
void func_002f3cd8_x15407(f32* o, void* a, f32* b) asm("sceVu0ApplyMatrix");
f32 func_0020c860(void* self, f32* m, Par20c860* par, void* a3, Src20c860* src);  // 0x0020c860: definition moved into src/anon/unit_0020c580.cpp

// --------------------
s32 func_001c0cd8(u8*);
s32 func_001c0ce8(u8*);
s32 func_002e9a78(void* self, u8* o, s32 k);  // 002e9a78: moved to src/anon/unit_002e9a00.cpp

// --------------------
// lq/sq 128-bit copy (hand-written VU-style copy), source operand first
#define QCOPYS_2c6780(d, s) asm volatile("lq $8, 0(%0)\n\tsq $8, 0(%1)" : : "r"(s), "r"(d) : "$8", "memory")
union UA_002c6780 { u32 i; f32 f; u8* p; };
extern u8 D_00361dc8[];
extern UA_002c6780 D_00361db8;
extern u8 D_01e2bdd0[];
extern u8 D_01e2bdc0[];
// 002c6780: moved to src/anon/unit_002c6420.cpp (linked unit)

// --------------------
// lq/sq 128-bit copy and VU0 vf0 store (hand-written VU idioms)
#define QCOPY_15eba8(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V15eba8 {
    f32 x, y, z, w;
    V15eba8() {}
    V15eba8(const V15eba8& o) { QCOPY_15eba8(this, &o); }
    void Set15eba8(const V15eba8& o) { QCOPY_15eba8(this, &o); }
} __attribute__((aligned(16)));
static inline void Unit15eba8(V15eba8* v) { asm volatile("sqc2 $vf0, 0(%0)" : : "r"(v) : "memory"); }
struct A15eba8;
struct AV15eba8 { void* (*alloc)(A15eba8*, u32, void*); };
struct A15eba8 { AV15eba8* vt; };
extern A15eba8* D_0034c738;
void func_0015f288();
void func_001612b8(u8*, u8*);
void func_00142c90(u8*, u8*, u8, u64);
void func_0015f8d8(void*, s32, V15eba8*, V15eba8*, V15eba8*, s32, s32);
void func_0015c2a0(s32, u64);
u32 func_001492e0(u8*);
void func_001dddd0(u8*, u32);
void func_001de228(u8*, s32, s32, s32, s32, s32);
// 0015eba8: moved to src/harata/libdk/map.cpp

// --------------------
// VU0 macro-mode vector helpers (hand-written vu0 library idioms) and lq/sq copy
struct V1d38a0 {
    f32 x, y, z, w;
    V1d38a0() {}
    V1d38a0& operator=(const V1d38a0& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline void VSub1d38a0(V1d38a0* d, const V1d38a0* a, const V1d38a0* b)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline void VAdd1d38a0(V1d38a0* d, const V1d38a0* a, const V1d38a0* b)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline void VScale1d38a0(V1d38a0* d, const V1d38a0* a, f32 k)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(d), "r"(a), "f"(k) : "$8", "memory");
}
static inline f32 VNormalize1d38a0(V1d38a0* v)
{
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\t"
                 "vsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\t"
                 "vdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
struct F1d38a0 { V1d38a0 pos; u32 mask; f32 f14, f18, f1c, f20, f24, f28, f2c; };
s32 func_0019bb98(u8*);
s32 func_0016a040(u8*);
V1d38a0* func_0016c028_1d38a0(u8*) asm("func_0016c028");
f32 func_0016a0a0(u8*);
void func_0017d538(f32, V1d38a0*, V1d38a0*);
// 001d38a0: moved to src/anon/unit_001d35e0.cpp

// --------------------
// VU0 macro-mode vector helpers (hand-written vu0 library idioms) and lq/sq copy
#define QCOPY_2e87e0(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V2e87e0 {
    f32 x, y, z, w;
    V2e87e0() {}
    V2e87e0(const V2e87e0& o) { QCOPY_2e87e0(this, &o); }
    V2e87e0& operator=(const V2e87e0& o) { if (this != &o) QCOPY_2e87e0(this, &o); return *this; }
} __attribute__((aligned(16)));
static inline V2e87e0 Cross2e87e0(const V2e87e0& a, const V2e87e0& b)
{
    V2e87e0 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf3, $vf0, $vf0\n\t"
                 "vopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline V2e87e0 Scale2e87e0(const V2e87e0& a, f32 k)
{
    V2e87e0 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
static inline f32 Normalize2e87e0(V2e87e0* v)
{
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\t"
                 "vsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\t"
                 "vdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
struct M2e87e0 { V2e87e0 r[4]; V2e87e0 t; };
struct A2e87e0 { V2e87e0* dir; V2e87e0* up; };
extern V2e87e0 D_01e2bf80;
void func_0011b6a8_2e87e0(M2e87e0*) asm("func_0011b6a8");
void func_0011bac8(M2e87e0*, V2e87e0*);
void func_002e87e0(A2e87e0* a);  // 0x002e87e0: definition moved into src/anon/unit_002e7b10.cpp

// --------------------
// VU0 macro-mode vector helpers (hand-written vu0 library idioms) and lq/sq copy
struct V2e9d08 {
    f32 x, y, z, w;
    V2e9d08() {}
    V2e9d08& operator=(const V2e9d08& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline V2e9d08 Sub2e9d08(const V2e9d08& a, const V2e9d08& b)
{
    V2e9d08 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 Length2e9d08(const V2e9d08& v)
{
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\t"
                 "vsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0"
                 : "=f"(len) : "r"(&v) : "$8", "memory");
    return len;
}
struct B2e9d08 { f32 a, y, c; u32 d; V2e9d08 pos; };
struct S2e9d08 { u8 pad[4]; u32 flags; u8 pad8[4]; s32 fc; f32 minDist, maxDist, maxAng; };
void func_0018a818_2e9d08(B2e9d08*, u8*, u8*) asm("func_0018a818");
void func_00190128_2e9d08(u32*) asm("func_00190128");
void func_00190878_2e9d08(u32*, u8*, u8) asm("func_00190878");
u8* func_001b9bc8(u8*);
s32 func_002e9a38(S2e9d08*, u8*, u8);
s32 func_002e9c58(S2e9d08*, u8*);
void func_002e9c98(S2e9d08*, u32*);
f32 func_002f8ad0(f32, f32);
f32 func_0017ce10(f32);
void func_002e9d08(S2e9d08* s, u32* res, V2e9d08* origin, V2e9d08* dir, u8 nearest, u8 flat, u8 check);  // 002e9d08: moved to src/anon/unit_002e9a00.cpp

// --------------------
extern u8 D_00350758[];
void func_0018d050(u8*, u8*, u32, u32, u32, s32, u32);
static inline u32 K1a3f08(u8* p)
{
    u8* q;
    if (p != 0 && (q = *(u8**)(p + 0x48c)) != 0) return q[0x24c];
    return 0;
}
// 001a3f08: moved to src/anon/unit_001a3e70.cpp

// --------------------
struct N170a90 { u8 pad0[4]; char name[0x24]; s32 f28; u8 pad2c[0x10]; N170a90* next; };
extern N170a90* D_0034dca0;
s32 strcmp(const char*, const char*);
void func_001700e8(N170a90*, s32);
static inline N170a90* Next170a90(N170a90* n) { if (n == 0) return D_0034dca0; return n->next; }
static inline bool Ok170a90(N170a90* n) { return n->f28 >= 10000; }
void func_00170a90(const char* name);  // 0x00170a90: definition moved into src/anon/unit_0016e8f8.cpp

// --------------------
// libgcc fp-bit.c (double): float_to_si / float_to_usi
enum FpC3143e0 { FPC_SNAN, FPC_QNAN, FPC_ZERO, FPC_NUMBER, FPC_INFINITY };
struct FpN3143e0 { FpC3143e0 cls; u32 sign; s32 normal_exp; u64 fraction; };
static inline s32 iszero3143e0(FpN3143e0* x) { return x->cls == FPC_ZERO; }
static inline s32 isnan3143e0(FpN3143e0* x) { return x->cls == FPC_SNAN || x->cls == FPC_QNAN; }
static inline s32 isinf3143e0(FpN3143e0* x) { return x->cls == FPC_INFINITY; }
void func_003147a0_3143e0(u64*, FpN3143e0*) asm("func_003147a0");
s32 func_003143e0(u64 arg_a);  // 0x003143e0: definition moved into src/libgcc/_df_to_si.c
u32 func_00314508(u64 arg_a);  // 0x00314508: definition moved into src/libgcc/_df_to_usi.c

// --------------------
// Wait for VIF1 DMA / GIF DMA / VIF1 / VU1 idle, then start VIF1 DMA (chain mode) at tadr.
void func_001e75a8(u32 tadr);  // 0x001e75a8: definition moved into src/anon/unit_001e0cb8.cpp

// --------------------
struct R2e2728 { s32 a, b; };
struct O2e2728 { u8 pad[0x64]; R2e2728* r; u8 m68[0x98]; s32 idx; f32 v; s32 n; u8 pad10c[4]; s32 state; };
void func_002e34c8(u8*);
R2e2728* func_002e34d8(u8*, s32);
// 002e2728: moved to src/anon/unit_002e1908.cpp

// --------------------
// lq/sq 128-bit copy (hand-written VU-style copy)
#define QCOPY_11bfa0(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V11bfa0 {
    f32 x, y, z, w;
    void Set(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    V11bfa0& operator=(const V11bfa0& o) { if (this != &o) QCOPY_11bfa0(this, &o); return *this; }
} __attribute__((aligned(16)));
struct M11bfa0 { V11bfa0 r[4]; };
extern M11bfa0 D_003478f0;
void wtarget_0011bfa0(s32 init, s32 prio, u32, u32) asm("_Z16wtarget_0011bfa0jjjj");
void wtarget_0011bfa0(s32 init, s32 prio, u32, u32);  // 0x0011bfa0: definition moved into src/anon/unit_0011b3f8.cpp

// --------------------
struct P1eaf50 { f32 x, y, z; };
struct M1eaf50 { u8 pad[16]; f32 m[4][4]; };
union G1eaf50 { M1eaf50* p; u32 u; };
extern G1eaf50 D_01d9e6e8_1eaf50 asm("D_01d9e6e8");
struct O1eaf50 { u32 a; u32 b; };
struct H1eaf50 { u8 pad[0xc]; O1eaf50* ofs; };
void sceVu0UnitMatrix(f32 (*)[4]);
void func_001eaf50(u8* base, u32, H1eaf50* h);  // 0x001eaf50: definition moved into src/anon/unit_001e8ac8.cpp

// --------------------
struct E295430 { s8 key; u8 pad[3]; u16 a, b; u8 pad8[2]; u16 c, d; u8 pade[2]; };
struct T295430 { u8 pad[8]; s32 n; u8 pad2[4]; E295430 e[1]; };
T295430* func_00294000_295430(s32) asm("func_00294000");
s32 func_002941d8(E295430*);
u16 func_00295430(s32 key, u8 alt);  // 0x00295430: definition moved into src/anon/unit_00292e60.cpp

// --------------------
struct E2a9c40 { u16 a; u16 id; u8 pad[12]; };
struct T2a9c40 { u8 pad[8]; s32 n; u8 pad2[4]; E2a9c40 e[1]; };
T2a9c40* func_00294000_2a9c40(s32) asm("func_00294000");
s32 func_002a99c8(E2a9c40*);
s32 func_002a9c40(u32 id);  // 0x002a9c40: definition moved into src/anon/unit_002a99c8.cpp

// --------------------
struct E2ae280 { u8 b[12]; };
struct T2ae280 { u8 pad[8]; s32 n; u8 pad2[4]; E2ae280 e[1]; };
T2ae280* func_00294000_2ae280(s32) asm("func_00294000");
s32 func_00294480(E2ae280*);
void func_002ae280(s32* cnt, s32* total);  // 0x002ae280: definition moved into src/anon/unit_002a99c8.cpp

// --------------------
struct I1de328 { u16 a; u16 id; };
struct N1de328 { u8 pad[0x40]; u32 f40; I1de328* info; u8 pad48[0x18]; N1de328* next; };
struct L1de328 { N1de328* head; N1de328* tail; };
struct O1de328 { u8 pad[0xc]; L1de328 list; };
void func_001dc920(u32);
void func_001e0058(N1de328*);
void func_001de328(O1de328* o, u32 id);  // 0x001de328: definition moved into src/anon/unit_001ddcf0.cpp

// --------------------
struct E2417a0 { u8 pad[8]; u32 f8; u8 pad2[20]; };
struct T2417a0 { u8 pad[2]; s16 lim; u8 pad4; s8 b5; };
union G2417a0 { T2417a0* p; u32 u; };
extern G2417a0 D_0035ec94;
s32 func_002408d0(s32);
void func_002417a0();  // 0x002417a0: definition moved into src/anon/unit_0023f5b8.cpp

// --------------------
// libgcc fp-bit.c (double): si_int_to_float
enum FpC314330 { FPC2_SNAN, FPC2_QNAN, FPC2_ZERO, FPC2_NUMBER, FPC2_INFINITY };
struct FpN314330 { FpC314330 cls; u32 sign; s32 normal_exp; u64 fraction; };
u64 func_003146c8_314330(FpN314330*) asm("func_003146c8");
u64 func_00314330(s32 arg_a);  // 0x00314330: definition moved into src/libgcc/_si_to_df.c

// --------------------
struct E2abf40 { s8 key; u8 pad[11]; };
struct T2abf40 { u8 pad[8]; s32 n; u8 pad2[4]; E2abf40 e[1]; };
T2abf40* func_00294000_2abf40(s32) asm("func_00294000");
s32 func_002abf40(s32 key, s32 nth);  // 0x002abf40: definition moved into src/anon/unit_002a99c8.cpp

// --------------------
struct E2aa5b8 { s8 key; u8 pad[11]; };
struct T2aa5b8 { u8 pad[8]; s32 n; u8 pad2[4]; E2aa5b8 e[1]; };
T2aa5b8* func_00294000_2aa5b8(s32) asm("func_00294000");
s32 func_002aa5b8(s32 key, s32 nth);  // 0x002aa5b8: definition moved into src/anon/unit_002a99c8.cpp

// --------------------
struct E2aae88 { u16 id; u8 pad[14]; };
struct T2aae88 { u8 pad[8]; s32 n; u8 pad2[4]; E2aae88 e[1]; };
T2aae88* func_00294000_2aae88(s32) asm("func_00294000");
s32 func_002aacd8(s32);
extern u8* D_0035f610_2aae88 asm("D_0035f610");
s32 func_002aae88(s32 id);  // 0x002aae88: definition moved into src/anon/unit_002a99c8.cpp

// --------------------
extern u8* D_0035f610_2ac748 asm("D_0035f610");
u8* func_001d9e30(u8*);
s32 func_002764b0(u8);
s32 func_002ac748(s32 key);  // 0x002ac748: definition moved into src/anon/unit_002a99c8.cpp

// --------------------
struct O2e50f8 { u8 pad[4]; f32 w; u8 pad8[0x1148]; f32 tbl[22]; };
f32 func_002e51b0(O2e50f8*, f32);
f32 func_002e50f8(O2e50f8* o, f32 a, f32 b);  // 0x002e50f8: definition moved into src/anon/unit_002e3f58.cpp

// --------------------
struct E131e80 { u8 pad[0x74]; u32 ptr; u8 pad78[0x18]; };
struct N131e80 { s16 type; u16 done; u32 nkids; s32 last; u8 padc[8]; u32 tbl; };
N131e80* Reloc131e80(N131e80* n) asm("func_00131e80");
N131e80* Reloc131e80(N131e80* n);  // 0x00131e80: definition moved into src/anon/unit_00131418.cpp

// --------------------
struct A31a6d0 { u8 b[476]; };
struct B31a6d0 { u8 b[1328]; };
void func_0031a508(A31a6d0*);
void func_0031a3d8(B31a6d0*);
struct SB31a6d0 { u8 pad[16]; B31a6d0 b[8]; };
struct SA31a6d0 { u8 pad[8]; A31a6d0 a[16]; };
struct O31a6d0 { u32 vt; u8 pad[44]; SB31a6d0 sb; u8 pad2[4]; SA31a6d0 sa; };
static inline __attribute__((always_inline)) void DelA31a6d0(SA31a6d0* s)
{
    if (s->a != 0) {
        A31a6d0* p = s->a + 16;
        A31a6d0* b = s->a;
        for (;;) {
            if (b == p) break;
            --p;
            func_0031a508(p);
        }
    }
}
static inline __attribute__((always_inline)) void DelB31a6d0(SB31a6d0* s)
{
    if (s->b != 0) {
        B31a6d0* p = s->b + 8;
        B31a6d0* b = s->b;
        for (;;) {
            if (b == p) break;
            --p;
            func_0031a3d8(p);
        }
    }
}
struct AL31a6d0;
struct ALV31a6d0 { void* f0; void (*free)(AL31a6d0*, void*); };
struct AL31a6d0 { ALV31a6d0* vt; };
union G31a6d0 { u8* p; u32 u; };
extern G31a6d0 D_00347f80_31a6d0 asm("D_00347f80");
extern u8 D_00347d70_31a6d0[] asm("D_00347d70");
extern u8 D_00347f98_31a6d0[] asm("D_00347f98");
void func_0031a6d0(O31a6d0* o);  // 0x0031a6d0: definition moved into src/anon/unit_003197d0.cpp

// --------------------
struct E31c450;
struct EV31c450 { void* f[3]; void (*dtor)(E31c450*); };
struct E31c450 { EV31c450* vt; u8 pad[404]; };
struct O31c450 { u32 vt; u8 pad4[44]; u32 vt2; u8 pad34[28]; u8 m50[416]; E31c450 b[10]; E31c450 a[4]; u8 m1840[4]; };
extern u8 D_0034a5b0_31c450[] asm("D_0034a5b0");
extern u8 D_00347e80_31c450[] asm("D_00347e80");
extern u8 D_00347f98_31c450[] asm("D_00347f98");
void func_00239870(u8*);
void func_002361d0(u8*);
static inline __attribute__((always_inline)) void DelA31c450(O31c450* o)
{
    if ((u8*)o + 4576 != 0) {
        E31c450* p = o->a + 4;
        E31c450* b = o->a;
        for (;;) {
            if (b == p) break;
            --p;
            p->vt->dtor(p);
        }
    }
}
static inline __attribute__((always_inline)) void DelB31c450(O31c450* o)
{
    if ((u8*)o + 496 != 0) {
        E31c450* p = o->b + 10;
        E31c450* b = o->b;
        for (;;) {
            if (b == p) break;
            --p;
            p->vt->dtor(p);
        }
    }
}
void func_0031c450(O31c450* o);  // 0x0031c450: definition moved into src/anon/unit_0031b9e0.cpp

// --------------------
struct F11c148 { u64 lo : 51; u64 b51 : 1; u64 b52 : 1; u64 b53 : 1; u64 hi : 10; };
struct O11c148 { u8 pad[0x10]; F11c148 fl; f32 k; u16 h; u16 id; };
u16 func_0011f238(u32, u32);
void func_0011c148(O11c148* o, u32 a, u32 id, u8 x, u8 y, f32 k);  // 0x0011c148: definition moved into src/anon/unit_0011c128.cpp

// --------------------
struct A196ca8 { u8 a, b, c; };
struct X196ca8 { u16 d, e, f; };
struct O196ca8 {
    u32 f0; union { u32 u; u16 h; u8 b; } f4; u32 f8; u8 m0c[4]; A196ca8 bytes; u8 pad13; X196ca8 shorts; u8 pad1a[0x12];
    u8 m2c[0x10]; u32 f3c, f40; u8 pad44[0xc]; u8 m50[0x44]; u32 f94, f98, f9c, fa0;
};
void func_0019ef70(u8*);
u32 func_001d30c0(u32);
void func_0011b6a8_196ca8(u8*) asm("func_0011b6a8");
void func_00138480(u32);
static inline void Init196ca8(X196ca8* x, s32 v)
{
    A196ca8* p = (A196ca8*)((u8*)x - 4);
    p->a = v; p->b = v; p->c = v; x->d = v; x->e = v; x->f = v;
}
void func_00196ca8(u8* p, s32 flags, u32 v);  // 0x00196ca8: definition moved into src/anon/unit_00195d00.cpp

// --------------------
// libgcc fp-bit.c (double): pack_d (no rounding, denormals flushed)
union FpU3146c8 { u64 value; struct { u64 fraction : 52; u32 exp : 11; u32 sign : 1; } bits; };
static inline s32 isnan_3146c8(FpN314330* x) { return x->cls == FPC2_SNAN || x->cls == FPC2_QNAN; }
static inline s32 isinf_3146c8(FpN314330* x) { return x->cls == FPC2_INFINITY; }
static inline s32 iszero_3146c8(FpN314330* x) { return x->cls == FPC2_ZERO; }
u64 func_003146c8(FpN314330* src);  // 0x003146c8: definition moved into src/libgcc/_pack_df.c

// --------------------
struct V2e2350 {
    f32 x, y, z, w;
    V2e2350() {}
    V2e2350(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    // 128-bit lq/sq copy (hand-written)
    V2e2350& operator=(const V2e2350& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
union U2e2350 { s32* p; s32 i; u32 u; };
struct O2e2350 {
    u8 pad[100]; U2e2350 cur; u8 b104[152]; u32 f256; f32 f260; u32 f264; u8 f268; u8 p269[3];
    U2e2350 f272; U2e2350 f276; u8 p280[8]; V2e2350 v288; V2e2350 v304;
};
extern "C" {
s32* func_002e34d8_2e2350(u8*, s32) asm("func_002e34d8");
void func_002e24e0(O2e2350*);
void Init2e2350(O2e2350* o) asm("func_002e2350");// 002e2350: moved to src/anon/unit_002e1908.cpp
}

// --------------------
struct AVt322c98 { void* alloc; void (*free)(void* self, void* p); };
struct AO322c98 { AVt322c98* vt; };
struct H322c98 { u8 pad[20]; AO322c98* al; };
union HU322c98 { H322c98* h; u32 u; };
extern HU322c98 D_00347f80_322c98 asm("D_00347f80");
extern u8 D_0035eb60_322c98[] asm("D_0035eb60");
extern u8 D_00348698_322c98[] asm("D_00348698");
extern u8 D_00347f98_322c98[] asm("D_00347f98");
void func_0023d7c8(void*);
void func_001070e8(u8*);
void func_00106ac8(void*);
struct EA322c98 { u8 pad[256]; u8 m[144]; };
struct EB322c98 { u8 pad[192]; u8 m[128]; };
struct O322c98 { u32 vt; u8 pad4[28]; EA322c98 a[4]; EB322c98 b[4]; u8 pad2[32]; u32 v1; u8 p1[780]; u32 v2; u8 p2[780]; u32 v3; };
static inline __attribute__((always_inline)) void DelB322c98(O322c98* o)
{
    if ((u8*)o + 1632 != 0) {
        EB322c98* p = o->b + 4;
        EB322c98* b = o->b;
        for (;;) {
            if (b == p) break;
            --p;
            func_001ddd88(p->m);
        }
    }
}
static inline __attribute__((always_inline)) void DelA322c98(O322c98* o)
{
    if ((u8*)o + 32 != 0) {
        EA322c98* p = o->a + 4;
        EA322c98* b = o->a;
        for (;;) {
            if (b == p) break;
            --p;
            func_001070e8(p->m);
            func_00106ac8(p);
        }
    }
}
void func_00322c98(O322c98* o);  // 0x00322c98: definition moved into src/anon/unit_00321728.cpp

// --------------------
u8* func_002a9d68_2ab180() asm("func_002a9d68");
extern u8* D_0035f610_2ab180 asm("D_0035f610");
s32 func_002ab180(s32 id);  // 0x002ab180: definition moved into src/anon/unit_002a99c8.cpp

// --------------------
struct E2aa220 { u8 d[8]; };
struct T2aa220 { u8 pad[8]; s32 n; u8 pad2[4]; E2aa220 e[1]; };
T2aa220* func_00294000_2aa220(s32) asm("func_00294000");
u8* func_002a9d68_2aa220() asm("func_002a9d68");
s32 func_002943e8_2aa220(E2aa220*) asm("func_002943e8");
extern u8* D_0035f610_2aa220 asm("D_0035f610");
void func_002aa220();  // 0x002aa220: definition moved into src/anon/unit_002a99c8.cpp

// --------------------
struct E2aa960 { u8 d[8]; };
struct T2aa960 { u8 pad[8]; s32 n; u8 pad2[4]; E2aa960 e[1]; };
T2aa960* func_00294000_2aa960(s32) asm("func_00294000");
u8* func_002a9d68_2aa960() asm("func_002a9d68");
s32 func_002944d0_2aa960(E2aa960*) asm("func_002944d0");
extern u8* D_0035f610_2aa960 asm("D_0035f610");
void func_002aa960();  // 0x002aa960: definition moved into src/anon/unit_002a99c8.cpp

// --------------------
struct E2ad258 { u8 d[8]; };
struct T2ad258 { u8 pad[8]; s32 n; u8 pad2[4]; E2ad258 e[1]; };
T2ad258* func_00294000_2ad258(s32) asm("func_00294000");
u8* func_002a9d68_2ad258() asm("func_002a9d68");
s32 func_002943e8_2ad258(E2ad258*) asm("func_002943e8");
extern u8* D_0035f620;
union C2ad258 { s32 i; u32 u; };
extern C2ad258 D_0035f628;
extern s32 D_0035f62c;
void func_002ad258();  // 0x002ad258: definition moved into src/anon/unit_002a99c8.cpp

// --------------------
struct E2ad580 { u8 d[8]; };
struct T2ad580 { u8 pad[8]; s32 n; u8 pad2[4]; E2ad580 e[1]; };
T2ad580* func_00294000_2ad580(s32) asm("func_00294000");
u8* func_002a9d68_2ad580() asm("func_002a9d68");
s32 func_002944d0_2ad580(E2ad580*) asm("func_002944d0");
extern u8* D_0035f620_2ad580 asm("D_0035f620");
union C2ad580 { s32 i; u32 u; };
extern C2ad580 D_0035f628_2ad580 asm("D_0035f628");
extern s32 D_0035f62c_2ad580 asm("D_0035f62c");
void func_002ad580();  // 0x002ad580: definition moved into src/anon/unit_002a99c8.cpp

// --------------------
u8* func_002a9d68_2abac8() asm("func_002a9d68");
extern u8* D_0035f610_2abac8 asm("D_0035f610");
u8* func_001a82b0_2abac8(u8*) asm("func_001a82b0");
u8* func_001a80c8_2abac8(u16) asm("func_001a80c8");
s32 func_002764b0_2abac8(u8) asm("func_002764b0");
void func_002abac8(s32 key);  // 0x002abac8: definition moved into src/anon/unit_002a99c8.cpp

// --------------------
extern u8* D_0035f610_2ac8e0 asm("D_0035f610");
u8* func_001d9e30_2ac8e0(u8*) asm("func_001d9e30");
s32 func_002764b0_2ac8e0(u8) asm("func_002764b0");
u8* func_002a9d68_2ac8e0() asm("func_002a9d68");
void func_002ac8e0(s32 key);  // 0x002ac8e0: definition moved into src/anon/unit_002a99c8.cpp

// --------------------
struct O28d1c0 { u8 pad[392]; s32 f392; u8 pad2[10]; s16 h[3]; };
void func_0028d6e8(O28d1c0*);
u32 func_0023c4b8(u8*, u32);
u8* func_00236ca8_28d1c0(u32, u32) asm("func_00236ca8");
void func_0028d188(O28d1c0*);
void func_001386e0_28d1c0(O28d1c0*, s32, u32, u8*, s32, s32) asm("func_001386e0");
void func_0028d1c0(O28d1c0* o, s32 id, u32 a, u32 b, u32 bank, s16* src);  // 0028d1c0: moved to src/anon/unit_0028c878.cpp

// --------------------
struct E2ad6e8 { u8 d[16]; };
struct T2ad6e8 { u8 pad[8]; s32 n; u8 pad2[4]; E2ad6e8 e[1]; };
T2ad6e8* func_00294000_2ad6e8(s32) asm("func_00294000");
u8* func_002a9d68_2ad6e8() asm("func_002a9d68");
s32 func_002a99c8_2ad6e8(E2ad6e8*) asm("func_002a99c8");
extern u8* D_0035f620_2ad6e8 asm("D_0035f620");
union C2ad6e8 { s32 i; u32 u; };
extern C2ad6e8 D_0035f628_2ad6e8 asm("D_0035f628");
extern s32 D_0035f62c_2ad6e8 asm("D_0035f62c");
void func_002ad6e8();  // 0x002ad6e8: definition moved into src/anon/unit_002a99c8.cpp

// --------------------
struct E2aabe8 { u8 d[16]; };
struct T2aabe8 { u8 pad[8]; s32 n; u8 pad2[4]; E2aabe8 e[1]; };
T2aabe8* func_00294000_2aabe8(s32) asm("func_00294000");
u8* func_002a9d68_2aabe8() asm("func_002a9d68");
s32 func_002a99c8_2aabe8(E2aabe8*) asm("func_002a99c8");
extern u8* D_0035f610_2aabe8 asm("D_0035f610");
void func_002aabe8();  // 0x002aabe8: definition moved into src/anon/unit_002a99c8.cpp

// --------------------
struct AVt31ca70 { void* alloc; void (*free)(void* self, void* p); };
struct AO31ca70 { AVt31ca70* vt; };
struct H31ca70 { u8 pad[20]; AO31ca70* al; };
union HU31ca70 { H31ca70* h; u32 u; };
extern HU31ca70 D_00347f80_31ca70 asm("D_00347f80");
extern u8 D_0034a700_31ca70[] asm("D_0034a700");
extern u8 D_00347f98_31ca70[] asm("D_00347f98");
struct E31ca70 { u8 d[600]; };
void func_0031c9f8(E31ca70*);
void func_0031c980(E31ca70*);
void func_0031c8e8(E31ca70*);
struct MA31ca70 { u8 hdr[8]; E31ca70 e[16]; };
struct MB31ca70 { u8 hdr[8]; E31ca70 e[4]; };
struct O31ca70 { u32 vt; u8 pad[32]; MA31ca70 a; u8 p2[12]; MB31ca70 b; u8 p3[12]; MB31ca70 c; };
#define DEL31ca70(name, M, n, fn) \
static inline __attribute__((always_inline)) void name(M* m) \
{ \
    if (m->e != 0) { E31ca70* p = m->e + n; E31ca70* b = m->e; for (;;) { if (b == p) break; --p; fn(p); } } \
}
DEL31ca70(DelC31ca70, MB31ca70, 4, func_0031c9f8)
DEL31ca70(DelB31ca70, MB31ca70, 4, func_0031c980)
DEL31ca70(DelA31ca70, MA31ca70, 16, func_0031c8e8)
void func_0031ca70(O31ca70* o);  // 0x0031ca70: definition moved into src/anon/unit_0031b9e0.cpp

// --------------------
u8* func_00177860_19e758(u8*) asm("func_00177860");
u8* func_0017df58_19e758(s32) asm("func_0017df58");
s32 func_0019ba60_19e758(u8*) asm("func_0019ba60");
u8 func_0019e848_19e758(u8*, u8*, u8*, s32) asm("func_0019e848");
extern u8 D_0036d400[];
s32 func_0019e758(u8* o, u8* t);  // 0x0019e758: definition moved into src/anon/unit_0019ba60.cpp

// --------------------
struct Q26b008 { u8 pad[18]; u8 n; u8 pad2[33]; u16 h52[8]; u16 h68[8]; };
struct P26b008 { u8 pad[580]; Q26b008* q; };
extern u32 D_0035f010_26b008 asm("D_0035f010");
s32 func_00257070_26b008(s32) asm("func_00257070");
P26b008* func_00281180_26b008(u32, s32) asm("func_00281180");
void func_0026b008();  // 0x0026b008: definition moved into src/anon/unit_0026a900.cpp

// --------------------
struct E2adfd0 { s8 k; u8 pad[11]; };
struct T2adfd0 { u8 pad[8]; s32 n; u8 pad2[4]; E2adfd0 e[1]; };
T2adfd0* func_00294000_2adfd0(s32) asm("func_00294000");
s32 func_00294268_2adfd0(E2adfd0*) asm("func_00294268");
extern u8* D_0035f620_2adfd0 asm("D_0035f620");
void func_002adfd0();  // 0x002adfd0: definition moved into src/anon/unit_002a99c8.cpp

// --------------------
struct AVt31db80 { void* alloc; void (*free)(void* self, void* p); };
struct AO31db80 { AVt31db80* vt; };
struct H31db80 { u8 pad[20]; AO31db80* al; };
union HU31db80 { H31db80* h; u32 u; };
extern HU31db80 D_00347f80_31db80 asm("D_00347f80");
extern u8 D_0034af08_31db80[] asm("D_0034af08");
extern u8 D_00349b40_31db80[] asm("D_00349b40");
extern u8 D_00347f98_31db80[] asm("D_00347f98");
struct E31db80;
struct EVt31db80 { void (*dtor)(E31db80*); };
struct E31db80 { EVt31db80* vt; u8 pad[252]; };
struct M31db80 { u32 vt; u8 pad[332]; u8 m336[288]; u8 m624[256]; E31db80 a[4]; E31db80 b[4]; };
struct O31db80 { u32 vt; u8 pad[44]; M31db80 m; };
void func_0031bbc8(u8*);
void func_0031b910(u8*);
void func_0031bb08(M31db80*);
#define DELARR31db80(name, fld) \
static inline __attribute__((always_inline)) void name(M31db80* m) \
{ \
    if (m->fld != 0) { E31db80* p = m->fld + 4; E31db80* b = m->fld; for (;;) { if (b == p) break; --p; p->vt->dtor(p); } } \
}
DELARR31db80(DelB31db80, b)
DELARR31db80(DelA31db80, a)
static inline __attribute__((always_inline)) void DelM31db80(M31db80* m)
{
    DelB31db80(m);
    DelA31db80(m);
    func_0031bbc8(m->m624);
    func_0031b910(m->m336);
    m->vt = (u32)D_00349b40_31db80;
    func_0031bb08(m);
}
void func_0031db80(O31db80* o);  // 0x0031db80: definition moved into src/anon/unit_0031b9e0.cpp

// --------------------
struct AVt322300 { void* alloc; void (*free)(void* self, void* p); };
struct AO322300 { AVt322300* vt; };
struct H322300 { u8 pad[20]; AO322300* al; };
union HU322300 { H322300* h; u32 u; };
extern HU322300 D_00347f80_322300 asm("D_00347f80");
extern u8 D_0035e1b8_322300[] asm("D_0035e1b8");
extern u8 D_00347e60_322300[] asm("D_00347e60");
extern u8 D_00347f98_322300[] asm("D_00347f98");
struct EA322300;
struct EAVt322300 { void* p[3]; void (*dtor)(EA322300*); };
struct EA322300 { EAVt322300* vt; u8 pad[408]; };
struct EB322300;
struct EBVt322300 { void* p[3]; void (*dtor)(EB322300*); };
struct EB322300 { EBVt322300* vt; u8 pad[844]; };
struct X322300 { u32 vt; u8 pad[20]; u8 y[16]; };
struct O322300 { u32 vt; u8 pad[20]; u8 m24[416]; EA322300 a[1]; u8 p2[12]; EB322300 b[2]; X322300 x; };
void func_0031a840(O322300*);
void func_00322300(O322300* o);  // 0x00322300: definition moved into src/anon/unit_00321728.cpp

// --------------------
u8* func_002a9d68_2ab9c8() asm("func_002a9d68");
extern u8* D_0035f610_2ab9c8 asm("D_0035f610");
u8* func_001a82b0_2ab9c8(u8*) asm("func_001a82b0");
u8* func_001a80c8_2ab9c8(u16) asm("func_001a80c8");
s32 func_002764b0_2ab9c8(u8) asm("func_002764b0");
s32 func_002ab9c8(s32 key);  // 0x002ab9c8: definition moved into src/anon/unit_002a99c8.cpp

// --------------------
struct W2891f0 { u8 pad[392]; s32 f392; };
struct O2891f0 { s16 cur; u8 p2[2]; s16 n; u8 p6[12]; s16 off; u8 p20[2]; s16 max; u8 p24[13]; u8 b37; u8 p38[2]; W2891f0** w; u8 p44[4]; s16 (*tab)[4]; };
s32 func_0028b1c0(O2891f0*);
void func_00289b30(O2891f0*, O2891f0*, s16*);
void func_00138c10_2891f0(W2891f0*, s32) asm("func_00138c10");
void func_002891f0_def(O2891f0* o, s32 v, u8 flag, s32 a, s32 b) asm("func_002891f0");
void func_002891f0_def(O2891f0* o, s32 v, u8 flag, s32 a, s32 b);  // 0x002891f0: definition moved into src/anon/unit_00288b00.cpp

// --------------------
struct E2aa4a8 { s8 k; u8 pad[11]; };
struct T2aa4a8 { u8 pad[8]; s32 n; u8 pad2[4]; E2aa4a8 e[1]; };
T2aa4a8* func_00294000_2aa4a8(s32) asm("func_00294000");
s32 func_00294268_2aa4a8(E2aa4a8*) asm("func_00294348");
extern u8* D_0035f610_2aa4a8 asm("D_0035f610");
u8* func_002a9d68_2aa4a8() asm("func_002a9d68");
void func_002aa4a8();  // 0x002aa4a8: definition moved into src/anon/unit_002a99c8.cpp

// --------------------
struct T2b4dd0 { s16 h0; s16 h2; s16 h4; };
struct C2b4dd0 { u8 pad[20]; T2b4dd0* t; };
union G2b4dd0 { u8* p; u32 u; };
extern G2b4dd0 D_0035f654_2b4dd0 asm("D_0035f654");
extern C2b4dd0* D_0035f6cc_2b4dd0 asm("D_0035f6cc");
extern s32 D_0035f640_2b4dd0 asm("D_0035f640");
extern s32 D_0035f644_2b4dd0 asm("D_0035f644");
extern u32 D_0035f664_2b4dd0 asm("D_0035f664");
union B2b4dd0 { u8 b; u32 u; };
extern B2b4dd0 D_0035f6d0_2b4dd0 asm("D_0035f6d0");
void func_00139620(u8*);
void func_002b4dd0(s32 code);  // 0x002b4dd0: definition moved into src/anon/unit_002b3ac8.cpp

// --------------------
struct E2ad390 { s8 k; u8 pad[11]; };
struct T2ad390 { u8 pad[8]; s32 n; u8 pad2[4]; E2ad390 e[1]; };
T2ad390* func_00294000_2ad390(s32) asm("func_00294000");
s32 func_00294268_2ad390(E2ad390*) asm("func_00294348");
extern u8* D_0035f620_2ad390 asm("D_0035f620");
union C2ad390 { s32 i; u32 u; };
extern C2ad390 D_0035f628_2ad390 asm("D_0035f628");
extern s32 D_0035f62c_2ad390 asm("D_0035f62c");
void func_002ad390();  // 0x002ad390: definition moved into src/anon/unit_002a99c8.cpp

// --------------------
struct E2abe28 { s8 k; u8 pad[11]; };
struct T2abe28 { u8 pad[8]; s32 n; u8 pad2[4]; E2abe28 e[1]; };
T2abe28* func_00294000_2abe28(s32) asm("func_00294000");
s32 func_00294268_2abe28(E2abe28*) asm("func_00294268");
extern u8* D_0035f610_2abe28 asm("D_0035f610");
u8* func_002a9d68_2abe28() asm("func_002a9d68");
void func_002abe28();  // 0x002abe28: definition moved into src/anon/unit_002a99c8.cpp

// --------------------
struct T2aa668 { u8 pad[8]; s32 n; };
T2aa668* func_00294000_2aa668(s32) asm("func_00294000");
s32 func_002aa5b8_2aa668(s32, s32) asm("func_002aa5b8");
extern u8* D_0035f610_2aa668 asm("D_0035f610");
s32 func_002aa668(s32 key, s32 nth);  // 0x002aa668: definition moved into src/anon/unit_002a99c8.cpp

// --------------------
extern u8 D_00361aa0_2c10e0[] asm("D_00361aa0");
extern u8 D_00347e60_2c10e0[] asm("D_00347e60");
extern u8 D_00347f98_2c10e0[] asm("D_00347f98");
extern u8 D_0035eb98_2c10e0[] asm("D_0035eb98");
struct E2c10e0;
struct EVt2c10e0 { void* p[3]; void (*dtor)(E2c10e0*); };
struct E2c10e0 { EVt2c10e0* vt; u8 pad[404]; };
struct X2c10e0 { u32 vt; u8 pad[20]; u8 y[16]; };
struct Z2c10e0 { u32 vt; u8 pad[20]; u8 m24[24]; u8 m48[112]; u32 f160; };
struct O2c10e0 { u32 vt; u8 pad[24]; Z2c10e0 z; X2c10e0 y; u8 p2[368]; E2c10e0 b[3]; X2c10e0 x; u8 p3[368]; E2c10e0 a[2]; u8 p4[188 - 188]; };
extern struct O2c10e0* D_00361a90;
void func_00170950(u32);
void func_0023c098(u8*);
void func_002369f0(u8*);
void func_002c10e0(O2c10e0* o);  // 0x002c10e0: definition moved into src/anon/unit_002c10e0.cpp

// --------------------
struct S28c198 { u8 pad[184]; u32 flags; void Set() { flags |= 8; } void Clr() { flags &= ~8; } };
struct W28c198 { u8 pad[24]; S28c198 sub; u8 pad2[436 - 24 - 188]; u32 f436; };
struct P28c198 { u8 pad[14080]; s32 free[32]; s32 n; };
extern P28c198* D_0035f3c4;
union C28c198 { s32 i; u32 u; };
extern C28c198 D_0035f3cc;
u32 func_0023c4b8_28c198(u8*, u32) asm("func_0023c4b8");
u8* func_00236ca8_28c198(u32, u32) asm("func_00236ca8");
void func_0028c0a0(W28c198*, u32, u32, u8*, u32, u32);
W28c198* func_0028c198(u32 id, u32 a, u32 b, u32 bank, u32 c, u32 d);  // 0x0028c198: definition moved into src/anon/unit_0028bfc0.cpp


// --------------------
// 001cc220: find the first object in range that can be targeted and hand it over
struct O1cc220 { u8 pad[0x588]; u32 flags; u8 pad2[0x7f8 - 0x58c]; u32 flags2; };
s32 o1cc220_get_entry_id(void*) asm("_ZN2YS3OBJ12get_entry_idEv");
O1cc220* func_00186078(O1cc220*);
s32 c1cc220_00186ce8(O1cc220*) asm("_Z16ctarget_00186ce8jjjj");
s32 func_00186d18(O1cc220*);
s32 c1cc220_001c7950(void*, O1cc220*, f32, f32) asm("func_001c7950");
s32 func_001cc310(O1cc220*, void*);
extern f32 D_0036d4a8;
// 001cc220: moved to src/anon/unit_001cc048.cpp


// --------------------
// 0014a500: per-frame update of the full-screen Ft4 sprite (store/load image, UVs, rotation)
extern u8 D_00349270[];
extern f32 D_00349390;
extern s32 D_00349394;
extern f32 D_00349398;
extern u8 D_0034939c;
extern u8 D_0034939d;
extern u8 D_0034939e;
extern f32 D_00349e10;
void f14a500_setRot(void*, f32) asm("_ZN2dk7Ft4Base6setRotEf");
f32 func_0013edd8(void*);
void f14a500_setGsTex0(void*, u64) asm("_ZN2dk7Ft4Base9setGsTex0Ey");
void func_0013ee30(void*, s64);
void f14a500_setGsUV(void*, u64, u64, u64, u64) asm("_ZN2dk7Ft4Base7setGsUVEyyyy");
void func_0013eeb8(void*);
void f14a500_setXY(void*, s16, s16) asm("_ZN2dk13RectParamBase5setXYEss");
void f14a500_loadImage(u32) asm("_ZN2dk9loadImageEj");
void f14a500_storeImage(void) asm("_ZN2dk10storeImageEv");
f32 f14a500_FixRadian(f32) asm("_ZN2YS4MATH9FixRadianEf");
void func_0014a500(void);  // 0014a500: moved to src/anon/unit_00149fa8.cpp


// --------------------
// 0015e070 / 0015e608: draw the queued 3D models with a snapshot of the current kn::Projection
// and kn::Camera (copied by value), then the overlay rects. Matrix product and lq/sq copies are VU0 asm.
// 4x4 float matrix (16-byte aligned rows), copied with lq/sq.
struct M15e608 {
    f32 m[4][4];
    M15e608() {}
    M15e608(const M15e608& o)
    {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
} __attribute__((aligned(16)));
struct V15e608 {
    f32 x, y, z, w;
    V15e608(const V15e608& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
static inline M15e608 Mul15e608(const M15e608& l, const M15e608& r)
{
    M15e608 d;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
                 "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder"
                 : : "r"(&d), "r"(&l), "r"(&r) : "memory");
    return d;
}
// kn::Projection members at 128/192 (out-of-line copy ctor).
struct PM15e608;
void b15e_0031bae0(PM15e608*, const PM15e608*) asm("func_0031bae0");
struct PM15e608 {
    M15e608 m;
    PM15e608(const PM15e608& o) { b15e_0031bae0(this, &o); }
};
// Field types reproduce the original's alias sets (see batch_w1681.cpp).
struct H15e608 { void* p; };
union U15e608 { s32 i; s32* p; };
struct R15e608 { s32* begin; s32* end; } __attribute__((aligned(8)));
struct Proj15e608 {
    M15e608 world;
    f32 f40;
    H15e608 h44;
    void* p48;
    s32 i4c;
    U15e608 v50;
    void* p54;
    R15e608 r58;
    s32* p60;
    f32 f64, f68, f6c, f70, f74, f78;
    PM15e608 view;
    PM15e608 clip;
    Proj15e608(const Proj15e608& o) __attribute__((always_inline));
    ~Proj15e608();
};
void b15e_projDtor(Proj15e608*) asm("_ZN2kn10ProjectionD1Ev");
inline Proj15e608::~Proj15e608() { b15e_projDtor(this); }
inline Proj15e608::Proj15e608(const Proj15e608& o)
    : world(o.world), f40(o.f40), h44(o.h44), p48(o.p48), i4c(o.i4c), v50(o.v50), p54(o.p54), r58(o.r58), p60(o.p60),
      f64(o.f64), f68(o.f68), f6c(o.f6c), f70(o.f70), f74(o.f74), f78(o.f78), view(o.view), clip(o.clip) {}
extern u8 D_0033cc50;
struct Cam15e608 {
    u32 vt;
    M15e608 m;
    V15e608 a, b, c;
    f32 d;
    Cam15e608(const Cam15e608& o) : m(o.m), a((vt = (u32)&D_0033cc50, o.a)), b(o.b), c(o.c), d(o.d) {}
    ~Cam15e608();
} __attribute__((aligned(16)));
void b15e_camDtor(Cam15e608*) asm("_ZN2kn6CameraD1Ev");
inline Cam15e608::~Cam15e608() { b15e_camDtor(this); }
struct Model15e608 { u32 handle; u8 pad0[4]; u8 f8[16]; u64 f24; u64 f32; u8 pad1[88]; u8 f128[107]; u8 f235; u8 f236[33]; u8 f269; };
struct Rect15e608 { u8 pad[16]; };
struct Owner15e608 {
    u8 pad0[4];
    f32 z;
    Model15e608* models[18];
    Rect15e608 rect;
    u8 pad1[864 - 96];
    s32 nModels;
};
extern Rect15e608 D_004f3820;
extern u8 D_0034b280[];
Proj15e608* b15e_00106a18(s32) asm("func_00106a18");
Cam15e608* b15e_00106a60(s32) asm("func_00106a60");
void m15e608_swap(u32) asm("_ZN2kn8ModelObj10matrixSwapEv");
void b15e_0011cdf0(u32, M15e608*, void*, void*, u8) asm("func_0011cdf0");
void r15e608_setXY(Rect15e608*, s16, s16) asm("_ZN2dk13RectParamBase5setXYEss");
void r15e608_setZ(Rect15e608*, u32) asm("_ZN2dk13RectParamBase4setZEj");
void r15e608_setWH(Rect15e608*, u16, u16) asm("_ZN2dk13RectParamBase14setWidthHeightEtt");
void r15e608_setColor(Rect15e608*, u8, u8, u8, u8) asm("_ZN2dk13RectParamBase8setColorEhhhh");
void r15e608_setPrim(Rect15e608*, u64) asm("_ZN2dk8RectBase9setGsPrimEy");
void r15e608_setFrame(Rect15e608*, u64) asm("_ZN2dk8RectBase10setGsFrameEy");
void r15e608_setZbuf(Rect15e608*, u64) asm("_ZN2dk8RectBase9setGsZbufEy");
void r15e608_setTex0(Rect15e608*, u64) asm("_ZN2dk8RectBase9setGsTex0Ey");
void b15e_0014b838(Rect15e608*) asm("func_0014b838");
void b15e_0014c350(Rect15e608*) asm("func_0014c350");
u64 b15e_00166148(u8*, s32, s32) asm("func_00166148");
u32 b15e_00313bc0(f32) asm("__fixunssfsi");
// 0015e608: moved to src/anon/unit_0015e070.cpp

struct Owner15e070 {
    u8 pad0[4];
    f32 z;
    Model15e608* models[34];
    Rect15e608 rect;
    u8 pad1[416 - 160];
    Rect15e608 rect2;
    u8 pad2[1200 - 432];
    s32 nModels;
    s16 x; u8 pad3[2];
    s16 y; u8 pad4[2];
    u16 size;
};
// 0015e070: moved to src/anon/unit_0015e070.cpp


// --------------------
// 001a9c20: message window text layout: walk the encoded string, run control codes (colour, scale, icons, line feeds) and place characters
struct Font1a9c20 { s32 kind; u8 pad[13]; u8 height; u8 pad2[2]; s32 lineGap; bool IsRuby() { return kind == 4; } };
struct Style1a9c20 { s32 a; f32 scale; f32 alpha; s32 shift; s32 e, f; };
struct Ctx1a9c20 {
    Font1a9c20* font;
    s32 lines;
    s32 x;
    u32 y;
    s32 color;
    u8 pad0[4];
    f32 width;
    s32 count;
    Style1a9c20 style;
    s32 tab;
};
struct Cb1a9c20;
struct Cb1a9c20Vt { void* f[6]; void (*icon)(Cb1a9c20*, s32, s32, s32, u32); void* f7[4]; void (*sprite)(Cb1a9c20*, s32, s32, s32); void (*mark)(Cb1a9c20*, s32, u32, s32); };
struct Cb1a9c20 { Cb1a9c20Vt* vt; };
struct Out1a9c20 { s32 a, lines; };
struct Win1a9c20 {
    u32 flags;
    s32 msg;
    u8 pad0[16];
    Cb1a9c20* cb;
    u8 pad1[32];
    s32 defColor;
    u8 pad2[4];
    s32 baseX;
    u32 baseY;
    u8 pad3[16];
    f32 charW;
};
void func_00192818(u8*, s32, Style1a9c20*, Out1a9c20*);
s32 func_00192440(u8*, s32);
u8* func_00192388(u8*);
s32 func_001aa310(Win1a9c20*, Ctx1a9c20*, s32);
void func_00192f98(Style1a9c20*);
s32* w1a9c20_FontStyleGet(s32, s32) asm("_ZN2YS9FONTSTYLE3GetEii");
s32 func_001aa6f0(Win1a9c20*, s32);
s32 func_001aa940(Ctx1a9c20*, s32, u32, s32, s32);
s32 func_001aae90(s32);
s32 func_00192498(u8*, s32);
s32 func_00192450(u8*, s32);
f32 func_00192fb8(Style1a9c20*);
s32 func_001aa0a8(Win1a9c20*, Ctx1a9c20*, s32, u32, s32);
u8* func_001a9c20(Win1a9c20* w, Ctx1a9c20* c, u8* p);  // 0x001a9c20: definition moved into src/anon/unit_001a9130.cpp



// --------------------
// 0010e368: camera/look-direction update by state (aim at a point or follow the message direction, zoom level hysteresis)
// VU0 macro-mode vector helpers (hand-written asm in the original math library)
struct V10e368 {
    f32 x, y, z, w;
    V10e368() {}
    V10e368& operator=(const V10e368& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V10e368 operator-(const V10e368& b) const
    {
        V10e368 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V10e368 operator*(f32 k) const
    {
        V10e368 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    V10e368& operator+=(const V10e368& b)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory");
        return *this;
    }
    f32 dot(const V10e368& o) const
    {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(r) : "r"(this), "r"(&o) : "$8");
        return r;
    }
    f32 normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct Msg10e368 { f32 x; u8 pad[12]; V10e368 dir; V10e368 up; };
struct St10e368 { s32 f0; u32 state; };
struct O10e368 {
    u8 pad0[12];
    St10e368* st;
    u8 pad1[1360 - 16];
    V10e368 fwd;
    u8 pad2[2912 - 1376];
    s32 f2912;
    u8 pad3[2928 - 2916];
    s32 point;
    u8 pad4[4];
    s32 level;
    u32 flags;
    Msg10e368 msg;
    u8 pad5[3072 - 2992];
    V10e368 dir;
};
extern V10e368 D_00341720[];
void func_0010cac8(O10e368*, s32, f32);
V10e368* f10e368_attach(O10e368*) asm("func_0016c028");
f32 func_00114328(s32, s32, s32, s32);
f32 func_001142e0(s32, s32, s32, s32);
f32 func_0010e7e0(O10e368*, s32);
s32 func_0010e368(O10e368* o, Msg10e368* m);  // 0x0010e368: definition moved into src/anon/unit_0010dee8.cpp


// --------------------
// 001112a8: party member AI tick (state fixups, choose a target, copy the camera vectors)
struct V1112a8 {
    f32 x, y, z, w;
    V1112a8& operator=(const V1112a8& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct St1112a8 { s32 f0; u32 state; };
struct Fr1112a8 {
    u8 pad0[12];
    St1112a8* st;
    V1112a8 pos;
    V1112a8 rot;
    u8 pad1[352 - 48];
    u32 f352;
    u8 pad2[1632 - 356];
    u64 f1632;
    u8 pad3[2040 - 1640];
    u32 f2040;
    u8 pad4[2064 - 2044];
    s32 f2064;
    u8 pad5[2924 - 2068];
    s32 f2924;
    u8 pad6[2940 - 2928];
    u32 flags;
    f32 f2944;
    u8 pad7[3072 - 2948];
    V1112a8 dir;
    u8 pad8[3104 - 3088];
    V1112a8 up;
    u8 pad9[3288 - 3120];
    s32 f3288;
    bool isA() { if (f352 & 4) return true; return false; }
    bool isB() { if (f352 & 8) return true; return false; }
    bool isC() { if (f352 & 0x10) return true; return false; }
    bool busy() { return isA() || isB() || isC(); }
};
extern Fr1112a8* g1112a8_leader asm("D_00341708");
void f1112a8_setState(Fr1112a8*, s32) asm("func_0016bd60");
s32 func_00111278(Fr1112a8*);
s32 func_0010f8d0(Fr1112a8*);
void func_0010e130(Fr1112a8*, s32);
f32 fabsf(f32);
s32 func_001917c0(void);
void func_001111c8(Fr1112a8*);
void func_0010fa68(Fr1112a8*);
s32 func_0010fb10(Fr1112a8*);
void func_0010ff08(Fr1112a8*);
void func_00110500(Fr1112a8*);
void func_001106a0(Fr1112a8*);
void func_00140dc0(void);
void func_001112a8(Fr1112a8* o);  // 0x001112a8: definition moved into src/anon/unit_00110b00.cpp


// --------------------
// 001dfa38: effect object per-frame update (attach/transform, spawn the linked effect after the delay, end conditions)
struct H1dfa38 { u8 pad[8]; s32 bits; };
struct Def1dfa38 { u8 pad[16]; u32 flags; u8 pad2[4]; s32 effect; };
struct Src1dfa38 { u16 f0; u16 flags; };
struct O1dfa38 {
    u8 pad[64];
    H1dfa38* h;
    Def1dfa38* def;
    s32 f72;
    f32 time;
    f32 delay;
    s32 effect;
    Src1dfa38* src;
    union { u32 flags; struct { u32 local : 1; u32 rest : 31; } fb; };
};
void func_001df2c0(O1dfa38*);
void func_001df670(O1dfa38*);
void func_001dee88(O1dfa38*);
s32 func_001dc9f0(H1dfa38*);
void func_001dfca8(O1dfa38*, s32);
void func_001dfe88(O1dfa38*, s32);
void func_001dfdb8(O1dfa38*);
void func_001e00b0(O1dfa38*);
void* f1dfa38_pos(H1dfa38*) asm("func_001dc5f8");
s32 f1dfa38_effect(s32, void*) asm("func_002bc188");
s32 func_001dffd8(O1dfa38*);
void func_001df9c8(O1dfa38*);
void func_001dfa38(O1dfa38* o);  // 0x001dfa38: definition moved into src/anon/unit_001deb58.cpp


// --------------------
// 0010a1d0: draw queued 2D image entries (GS alpha/test setup with libgraph-style register packing, pre/post callbacks)
#define GS_SET_RGBAQ(r, g, b, a, q) ((u64)(r) | ((u64)(g) << 8) | ((u64)(b) << 16) | ((u64)(a) << 24) | ((u64)(q) << 32))
#define GS_SET_FOGCOL(r, g, b) ((u64)(r) | ((u64)(g) << 8) | ((u64)(b) << 16))
struct L4_10a1d0 { u8 pad[4]; s32 id; };
struct L3_10a1d0 { u8 pad[4]; L4_10a1d0* l4; };
struct Img10a1d0 { u8 pad[20]; L3_10a1d0* l3; };
struct E10a1d0;
typedef void (*Cb10a1d0)(E10a1d0*, s32);
struct E10a1d0 {
    Img10a1d0* img;
    s32 f4, f8, f12;
    E10a1d0* next;
    u8 pad0[4];
    s32 f24;
    u8 r, g, b, a;
    u8 fr, fg, fb;
    u8 pad1[5];
    u64 alpha;
    u64 test;
    u8 pad2[24];
    Cb10a1d0 pre;
    Cb10a1d0 post;
};
extern s32 D_00340ed4;
extern u8 D_00340ed8[];
u32 f10a1d0_w(s32, s32, u8) asm("func_00109f58");
u32 f10a1d0_h(s32, s32, u8) asm("func_00109ea8");
void func_00108c00(u8*, s32, u64, u64, u32, u32, u64, u64);
s32 f10a1d0_draw(Img10a1d0*, s32*, s32, s32, s32, s32) asm("func_0011c8f8");
void func_00134490(void);
void func_0010a1d0(E10a1d0* e);  // 0010a1d0: moved to src/anon/unit_00109c30.cpp


// --------------------
// 00115c08: decompose a model node into screen-space scale / rotation / position (inverse node * matrix, view, camera)
#define W115c08_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W115c08Vec {
    f32 x, y, z, w;
    W115c08Vec() {}
    W115c08Vec(const W115c08Vec& o) { W115c08_QCOPY(this, &o); }
    W115c08Vec& operator=(const W115c08Vec& o) { if (this != &o) W115c08_QCOPY(this, &o); return *this; }
    void zero() { asm volatile(".set noreorder\n\tvsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this) : "memory"); }
    void unit() { asm volatile("sqc2 $vf0, 0(%0)" : : "r"(this) : "memory"); }
    f32 normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct W115c08Mtx {
    W115c08Vec r0, r1, r2, r3;
    W115c08Mtx() {}
    W115c08Mtx(const W115c08Mtx& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    W115c08Mtx& operator=(const W115c08Mtx& o) {
        if (this != &o) {
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        }
        return *this;
    }
    // inverse of a rigid (orthonormal) transform in place: transpose + negated translation
    void invOrtho() {
        asm volatile(".set noreorder\n\t"
                 "lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\t"
            "vsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
    // VU0 matrix * matrix (each column of b transformed by this).
    W115c08Mtx operator*(const W115c08Mtx& b) const {
        W115c08Mtx o;
        const W115c08Mtx& a = *this;
        asm volatile(".set noreorder\n\t"
                     "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                     "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
                     "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder"
                     : : "r"(&o), "r"(&a), "r"(&b) : "memory");
        return o;
    }
    // general 4x4 inverse in place (affine: cofactors via outer products, 1/det in Q)
    void inverse() {
        asm volatile(".set noreorder\n\t"
            "lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tlqc2 $vf4, 48(%0)\n\t"
            "vopmula.xyz ACC, $vf2, $vf3\n\tvopmsub.xyz $vf5, $vf3, $vf2\n\t"
            "vopmula.xyz ACC, $vf3, $vf1\n\tvopmsub.xyz $vf6, $vf1, $vf3\n\t"
            "vopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf7, $vf2, $vf1\n\t"
            "vmul.xyz $vf8, $vf1, $vf5\n\tvmul.xyz $vf1, $vf4, $vf5\n\tvmul.xyz $vf2, $vf4, $vf6\n\tvmul.xyz $vf3, $vf4, $vf7\n\t"
            "vaddy.x $vf8, $vf8, $vf8y\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddx.y $vf2, $vf2, $vf2x\n\tvaddx.z $vf3, $vf3, $vf3x\n\t"
            "vaddz.x $vf8, $vf8, $vf8z\n\tvaddz.x $vf4, $vf1, $vf1z\n\tvaddz.y $vf4, $vf2, $vf2z\n\tvaddy.z $vf4, $vf3, $vf3y\n\t"
            "vdiv Q, $vf0w, $vf8x\n\t"
            "qmfc2 $8, $vf5\n\tqmfc2 $9, $vf6\n\tqmfc2 $10, $vf7\n\tqmfc2 $11, $vf0\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vsub.xyz $vf4, $vf0, $vf4\n\tvwaitq\n\t"
            "vmulq.wxyz $vf1, $vf1, Q\n\tvmulq.wxyz $vf2, $vf2, Q\n\tvmulq.wxyz $vf3, $vf3, Q\n\tvmulq.xyz $vf4, $vf4, Q\n\t"
            "sqc2 $vf1, 0(%0)\n\tsqc2 $vf2, 16(%0)\n\tsqc2 $vf3, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
    // VU0 matrix * column vector.
    W115c08Vec operator*(const W115c08Vec& v) const {
        W115c08Vec o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct O115c08 { u8 pad0[4]; void* model; u8 pad1[1656]; W115c08Mtx view; };
void f115c08_node(void*, s32, W115c08Mtx*) asm("func_0016b0e0");
s32 func_00106a18(u8);
f32 func_001070a0(s32);
u8* func_00106a60(u8);
void f115c08_euler(W115c08Mtx*, W115c08Vec*) asm("func_0011bac8");
f32 func_0017ce10(f32);
void func_00115c08(O115c08* o, W115c08Mtx* m, W115c08Vec* scaleOut, W115c08Vec* rotOut, W115c08Vec* posOut, u8 cam);  // 0x00115c08: definition moved into src/anon/unit_00114a90.cpp


// --------------------
// 001161c8: like 00115c08 for the party leader model (scale normalised before the camera inverse)
#define W1161c8_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1161c8Vec {
    f32 x, y, z, w;
    W1161c8Vec() {}
    W1161c8Vec(const W1161c8Vec& o) { W1161c8_QCOPY(this, &o); }
    W1161c8Vec& operator=(const W1161c8Vec& o) { if (this != &o) W1161c8_QCOPY(this, &o); return *this; }
    void zero() { asm volatile(".set noreorder\n\tvsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this) : "memory"); }
    void unit() { asm volatile("sqc2 $vf0, 0(%0)" : : "r"(this) : "memory"); }
    f32 normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct W1161c8Mtx {
    W1161c8Vec r0, r1, r2, r3;
    W1161c8Mtx() {}
    W1161c8Mtx(const W1161c8Mtx& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    W1161c8Mtx& operator=(const W1161c8Mtx& o) {
        if (this != &o) {
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        }
        return *this;
    }
    // inverse of a rigid (orthonormal) transform in place: transpose + negated translation
    void invOrtho() {
        asm volatile(".set noreorder\n\t"
                 "lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\t"
            "vsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
    // VU0 matrix * matrix (each column of b transformed by this).
    W1161c8Mtx operator*(const W1161c8Mtx& b) const {
        W1161c8Mtx o;
        const W1161c8Mtx& a = *this;
        asm volatile(".set noreorder\n\t"
                     "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                     "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
                     "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder"
                     : : "r"(&o), "r"(&a), "r"(&b) : "memory");
        return o;
    }
    // general 4x4 inverse in place (affine: cofactors via outer products, 1/det in Q)
    void inverse() {
        asm volatile(".set noreorder\n\t"
            "lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tlqc2 $vf4, 48(%0)\n\t"
            "vopmula.xyz ACC, $vf2, $vf3\n\tvopmsub.xyz $vf5, $vf3, $vf2\n\t"
            "vopmula.xyz ACC, $vf3, $vf1\n\tvopmsub.xyz $vf6, $vf1, $vf3\n\t"
            "vopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf7, $vf2, $vf1\n\t"
            "vmul.xyz $vf8, $vf1, $vf5\n\tvmul.xyz $vf1, $vf4, $vf5\n\tvmul.xyz $vf2, $vf4, $vf6\n\tvmul.xyz $vf3, $vf4, $vf7\n\t"
            "vaddy.x $vf8, $vf8, $vf8y\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddx.y $vf2, $vf2, $vf2x\n\tvaddx.z $vf3, $vf3, $vf3x\n\t"
            "vaddz.x $vf8, $vf8, $vf8z\n\tvaddz.x $vf4, $vf1, $vf1z\n\tvaddz.y $vf4, $vf2, $vf2z\n\tvaddy.z $vf4, $vf3, $vf3y\n\t"
            "vdiv Q, $vf0w, $vf8x\n\t"
            "qmfc2 $8, $vf5\n\tqmfc2 $9, $vf6\n\tqmfc2 $10, $vf7\n\tqmfc2 $11, $vf0\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vsub.xyz $vf4, $vf0, $vf4\n\tvwaitq\n\t"
            "vmulq.wxyz $vf1, $vf1, Q\n\tvmulq.wxyz $vf2, $vf2, Q\n\tvmulq.wxyz $vf3, $vf3, Q\n\tvmulq.xyz $vf4, $vf4, Q\n\t"
            "sqc2 $vf1, 0(%0)\n\tsqc2 $vf2, 16(%0)\n\tsqc2 $vf3, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
    // VU0 matrix * column vector.
    W1161c8Vec operator*(const W1161c8Vec& v) const {
        W1161c8Vec o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
s32 f1161c8_cam(u8) asm("func_00106a18");
f32 f1161c8_fov(s32) asm("func_001070a0");
u8* f1161c8_camm(u8) asm("func_00106a60");
struct O1161c8 { u8 pad0[1792]; W1161c8Mtx view; };
void* func_00111e38(s32);
void f1161c8_node(void*, s32, W1161c8Mtx*) asm("func_0016b0e0");
void f1161c8_euler(W1161c8Mtx*, W1161c8Vec*) asm("func_0011bac8");
void func_001161c8(O1161c8* o, W1161c8Mtx* m, W1161c8Vec* scaleOut, W1161c8Vec* rotOut, W1161c8Vec* posOut, u8 cam);  // 0x001161c8: definition moved into src/anon/unit_00114a90.cpp


// --------------------
// 00119830: spawn the attack effects for a party move kind and scatter extra hits around the camera target
struct V119830 {
    f32 x, y, z, w;
    V119830() {}
    V119830(const V119830& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V119830& operator=(const V119830& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Handle119830;
s32 f119830_ok(Handle119830*) asm("func_00190140");
s32 func_001901c0(Handle119830*);
struct Handle119830 {
    s32 id;
    bool valid() { return f119830_ok(this) && id != 0; }
};
struct Model119830 { u8 pad0[268]; u32 f268; u8 pad1[2548 - 272]; Handle119830 h; };
struct Who119830 { u8 pad0[4]; Model119830* model; u8 pad1[1928 - 8]; s32 count; };
void* func_00111e38(s32);
void* func_00117970(Who119830*, s32, void*, s32, s32, s32, s32, s32);
void func_00117b20(Who119830*, void*);
void func_00118da0(Who119830*);
void* f119830_cam(s32) asm("func_00106a60");
void func_00107368(void*, V119830*);
f32 func_0010f660(void);
void func_00113338(Model119830*, V119830*, Handle119830*, s32, s32, s32);
void func_00119830(Who119830* w, s32 kind);  // 0x00119830: definition moved into src/anon/unit_001195a8.cpp


struct V11ca20 {
    f32 x, y, z, w;
    V11ca20() {}
    V11ca20(const V11ca20& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V11ca20& operator*=(f32 s) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "f"(s) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct M11ca20 {
    V11ca20 r[4];
    M11ca20() {}
    M11ca20(const M11ca20& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    M11ca20& operator=(const M11ca20& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    static void mul(M11ca20* o, const M11ca20* a, const M11ca20* b) {
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
            "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
            "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)" : : "r"(o), "r"(a), "r"(b) : "memory");
    }
    M11ca20 operator*(const M11ca20& b) const {
        M11ca20 o;
        mul(&o, this, &b);
        return o;
    }
} __attribute__((aligned(16)));
struct XfB11ca20 {
    u32 vt;
    M11ca20 m;
    XfB11ca20(const XfB11ca20& o) : m(o.m) { vt = (u32)&D_0033cc50; }
};
struct Xf11ca20 : XfB11ca20 {
    V11ca20 a, b, c;
    f32 s;
};
struct Hdr11ca20 { s16 kind; u8 pad[2]; u32 count; s32 off[1]; };
struct Res11ca20 { u8 pad0[60]; Hdr11ca20* hdr; u8 b64; u8 pad1[11]; M11ca20* xf; };
struct Seq11ca20 { s32 id; };
struct Mdl11ca20;
struct Mdl11ca20 {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5();
    virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17();
    virtual void f18(); virtual void f19(); virtual void f20(); virtual void f21(); virtual void f22();
    virtual s32 frames(s32);
    Seq11ca20* seq;
    u8 pad[4];
    u32 flags;
};
struct Self11ca20 {
    u8 pad0[20];
    Mdl11ca20* mdl;
    u8 pad1[64 - 24];
    M11ca20 world;
    M11ca20 local;
    M11ca20 xf;
    u8 pad2[256 - 256];
    s32 nframes;
    s32 base;
    s32* tbl;
};
Mdl11ca20* func_00124748(Mdl11ca20*, u32);
s32 func_00124788(Mdl11ca20*, u32);
Res11ca20* func_00109d00(Self11ca20*, s32, Mdl11ca20*, s32*, s32);
Xf11ca20* f11ca20_get(s32) asm("func_00106a60");
void f11ca20_submit(Xf11ca20*) asm("func_001070e8");
Res11ca20* func_0011ca20(Self11ca20* s, const M11ca20* w, const M11ca20* l, s32 arg, u32 idx);  // 0x0011ca20: definition moved into src/anon/unit_0011c128.cpp

struct V125860 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct M125860 { V125860 r[4]; };
static inline void lerp125860(V125860* d, const V125860* a, const V125860* b, f32 t)
{
    asm volatile(".set noreorder
	lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\tvaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\tvmulax.wxyz ACC, $vf2, $vf3x\n\tvmaddx.wxyz $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(d), "r"(a), "r"(b), "f"(t) : "$8", "memory");
}
static inline f32 dot125860(const V125860* a, const V125860* b)
{
    f32 r;
    asm volatile(".set noreorder
	lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(r) : "r"(a), "r"(b) : "$8");
    return r;
}
static inline f32 norm125860(V125860* v)
{
    f32 r;
    asm volatile(".set noreorder
	lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
static inline void cross125860(V125860* d, const V125860* a, const V125860* b)
{
    asm volatile(".set noreorder
	lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)\n\t.set reorder"
                 : : "r"(d), "r"(a), "r"(b) : "memory");
}
void func_00125860(M125860* d, const M125860* a, const M125860* b, f32 t);  // 0x00125860: definition moved into src/anon/unit_00123990.cpp

struct V14e8b8 {
    f32 x, y, z, w;
    V14e8b8() {}
    V14e8b8& operator=(const V14e8b8& o) {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V14e8b8 operator+(const V14e8b8& o) const {
        V14e8b8 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct M14e8b8 {
    V14e8b8 r[4];
    V14e8b8 operator*(const V14e8b8& v) const {
        V14e8b8 o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct Pad14e8b8 { u8 pad0[8]; u64 flags; u8 pad1[36 - 16]; f32 stick; u8 pad2[4]; f32 scale; };
struct Cam14e8b8 {
    V14e8b8 eye;
    V14e8b8 at;
    u8 pad32[76 - 32];
    f32 f76;
    f32 f80;
    u8 pad84[96 - 84];
    V14e8b8 tgt;
    u8 pad112[128 - 112];
    V14e8b8 pos;
    u8 pad144[192 - 144];
    f32 yaw;
    f32 pitch;
};
extern void* D_0034a3f0;
extern f32 D_0034a3f8;
extern f32 D_00349e10;
s32 c14e8b8_19ba60(void*) asm("func_0019ba60");
void func_0014ebd8();
void func_0013f5f0(Cam14e8b8*);
V14e8b8* c14e8b8_16c028(void*) asm("func_0016c028");
Pad14e8b8* c14e8b8_167f18(s32) asm("func_00167f18");
void func_0014e658(Cam14e8b8*);
void func_0014e6f8(Cam14e8b8*);
void c14e8b8_11b6a8(M14e8b8*) asm("func_0011b6a8");
void c14e8b8_11b6d8(M14e8b8*, f32) asm("func_0011b6d8");
void c14e8b8_11b720(M14e8b8*, f32) asm("func_0011b720");
s32 func_001584f8(Pad14e8b8*);
s32 func_00158548(Pad14e8b8*);
s32 func_00158450(Pad14e8b8*);
s32 func_001584a0(Pad14e8b8*);
f32 func_0017ce10(f32);
f32 fabsf(f32);
void c14e8b8_def(Cam14e8b8* c) asm("func_0014e8b8");
// 0014e8b8: moved to src/harata/libdk/fpscamera.cpp

// Static init/destroy of six 2-element global arrays (gcc's __static_initialization_and_destruction_0).
struct W1633Big { u8 pad[256]; };                       // ctor 00106ab8, dtor 00106ac8
struct W1633Virt { void (**vtbl)(W1633Virt*); u8 pad[140]; }; // ctor 001070c8, virtual dtor
extern W1633Big w1633_003a7b70[2] asm("D_003a7b70");
extern W1633Big w1633_003a7d70[2] asm("D_003a7d70");
extern W1633Virt w1633_003a7f70[2] asm("D_003a7f70");
extern W1633Virt w1633_003a8090[2] asm("D_003a8090");
extern W1633Big w1633_003a81b0[2] asm("D_003a81b0");
extern W1633Virt w1633_003a83b0[2] asm("D_003a83b0");
void w1633_00106ab8(W1633Big*) asm("func_00106ab8");
void w1633_00106ac8(W1633Big*) asm("func_00106ac8");
void w1633_001070c8(W1633Virt*) asm("func_001070c8");

void func_00107d20(int init, int prio) asm("_Z13func_00107d20ii");
// 00107d20: moved to src/naka/libkn/camera.cpp


} // extern "C"

extern "C" {
struct Font1aa0a8 { s32 kind; bool IsRuby() { return kind == 4; } };
struct Style1aa0a8 { s32 a; f32 scale; f32 alpha; s32 shift; s32 e, f; };
struct Ctx1aa0a8 {
    Font1aa0a8* font;
    s32 lines;
    s32 x;
    u32 y;
    u32 color;
    u32 shadow;
    f32 width;
    s32 count;
    Style1aa0a8 style;
};
struct Win1aa0a8 { u8 pad[76]; f32 fade; };
extern s32 D_00350a18[4];
s32 a0a8_001aa310(Win1aa0a8*, Ctx1aa0a8*, s32) asm("func_001aa310");
s32 func_001aa8a8(Ctx1aa0a8*, s32, u32, u32, s32);
s32 func_001aa8f0(Ctx1aa0a8*, s32, u32, u32, s32);
u32 func_001aae80(Font1aa0a8*, s32);
f32 a0a8_00192fb8(Style1aa0a8*) asm("func_00192fb8");
u32 __fixunssfsi(f32);
s32 func_001aa0a8(Win1a9c20* w_, Ctx1a9c20* c_, s32 x, u32 y, s32 ch);  // 0x001aa0a8: definition moved into src/anon/unit_001a9130.cpp
} // extern "C"
