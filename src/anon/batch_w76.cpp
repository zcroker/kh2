#include "../common/types.h"
extern "C" {
f32* func_0016c028(u8*);  // obj_get_attach_or_alt
struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
s32 func_00114620(u32);
u32 func_0016a070(u32);
s32 func_001a35f8(s32, u32);
u8* func_001058e8(void);
u8* func_00188fe0(u8*, u32);
struct Entry { u16 id : 15; u16 on : 1; };
u32 ctarget_0010f7b0(u32, u32, s32, u32) asm("_Z16ctarget_0010f7b0jjjj");

u32 ctarget_0010f7b0(u32 a, u32 b, s32 id, u32 d);  // 0x0010f7b0: definition moved into src/anon/unit_0010f338.cpp

extern u32 D_00341708[3];
extern u32 D_0034e948;
u8* func_0017df58(s32);
void func_001136b0(u32, u8*);
void func_00135818(u32, u32);
void func_001357d8(void);

void func_00111e50(void);  // 0x00111e50: definition moved into src/anon/unit_001117d8.cpp

s32 func_001384c0(void);  // get_global_347e08
extern u8 D_0032bad8;
s32 func_00103b38(void);
u8* func_0014aba8(void);
s32 func_002ee530(void);
u8* func_00167f18(u32);
u32 func_001c1218(void);
s32 func_001688b8(void);
void func_00253180(u32, s32);
void func_00253410(u32, u32);
void func_00102448(u32, u32);
void* func_001050c8(void);
typedef void (*VFn)(void*);

void func_001384d0(u32 a);  // 0x001384d0: definition moved into src/anon/unit_00138480.cpp

extern void* D_00348050;
extern u8* D_00348058;
extern u8* D_00348054;
void func_00106420(void*);

void func_0013aed8(void);  // 0x0013aed8: definition moved into src/anon/unit_0013a8b8.cpp

extern f32 D_00348d30[];
union HalfOrFloat6 { s16 h[6]; f32 f[6]; };
/* six s16 values to floats, optionally scaled by a table entry */
void func_001450e8(HalfOrFloat6* src, s32 idx, HalfOrFloat6* out);  // 0x001450e8: definition moved into src/anon/unit_00144450.cpp

void func_00239f18(u8*, f32);  // obj_set_float312_and_flags
void func_00138c68(u8*, s32, s32);
// 001547e0: moved to src/anon/unit_00153ea0.cpp
void func_001547e0(u8* a, s32 b, s32 c);

struct V4 {
    f32 x, y, z, w;
    V4() {}
    V4(const V4& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V4& operator=(const V4& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern V4 D_004f37c0;
extern V4 D_004f37d0;
extern V4 D_004f37e0;
V4 func_0013f6e8(V4, V4, V4, f32, f32, f32, f32);
// 0015d208: moved to src/anon/unit_0015cdb0.cpp

void func_001da458(u8*, u32, u32, u32);  // stream_init_fields
void func_001da558(u8*, void*, u32, u32);
extern u8 D_0034dbf8;
void func_0016cab8(u8*);
void func_0016c7d8(u8*);
typedef void (*VFn2)(void*, u32);
extern void* D_004f6288;
void func_0016d1f0(u32);
void func_0016ce90(u8*);
static inline void Kill(u8* n) { if (n) { func_0016cab8(n); func_0016c7d8(n); } }
// 0016c9e8: moved to src/anon/unit_0016c770.cpp

s32 func_001b58a8(u8*, u32, u32, u32);
void func_001b59c0(u8*, u32, u32, u32);
s32 func_0019ba60(u8*);
void func_0016cce8(u32, s32, u32*, s32, s32);
typedef void (*VFn4)(void*, u32, u32, u32);
// 00177760: moved to src/yasui/libys/party.cpp

struct Bits8 { u32 b0 : 1; u32 hi : 31; };
static inline bool InfoFlag(u8* info) { return ((Bits8*)(info + 8))->b0; }
// 0017c578: moved to src/anon/unit_0017c400.cpp

u8 func_0019f6f0(u8*, u32, u32);
u8 func_0019f740(u8*, u32, u32);
u8 func_0019bd08(u8*, u32);
u8 func_0019bdc8(u8* o, u32 a, u32 b);  // 0x0019bdc8: definition moved into src/anon/unit_0019ba60.cpp

struct FV {
    f32 x, y, z, w;
    FV() {}
    FV& operator=(const FV& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline void Normalize(FV* v)
{
    asm volatile(
        "lqc2 $vf1, 0(%0)\n\t"
        "vmul.xyz $vf2, $vf1, $vf1\n\t"
        "vaddy.x $vf2, $vf2, $vf2y\n\t"
        "vaddz.x $vf2, $vf2, $vf2z\n\t"
        "vsqrt Q, $vf2x\n\t"
        "vwaitq\n\t"
        "cfc2.ni $8, $vi22\n\t"
        "vaddq.x $vf2, $vf0, Q\n\t"
        "mtc1 $8, $f1\n\t"
        "vnop\n\t"
        "vdiv Q, $vf0w, $vf2x\n\t"
        "vwaitq\n\t"
        "vmulq.xyz $vf1, $vf1, Q\n\t"
        "sqc2 $vf1, 0(%0)"
        : : "r"(v) : "$8", "$f1", "memory");
}
static inline void Scale(FV* d, const FV* s, f32 k)
{
    asm volatile(
        "lqc2 $vf1, 0(%1)\n\t"
        "mfc1 $8, %2\n\t"
        "qmtc2 $8, $vf2\n\t"
        "vmulx.wxyz $vf1, $vf1, $vf2x\n\t"
        "sqc2 $vf1, 0(%0)"
        : : "r"(d), "r"(s), "f"(k) : "$8", "memory");
}
void func_0017a9e8(u32, u8*);
void btl_blow(u8* self, const FV& v) asm("_ZN2YS6BTLOBJ4blowERKN2kn7FVectorE");
/* knock-back: horizontal unit direction scaled by v.w */
// 00186888: moved to src/anon/unit_00185d10.cpp

extern struct { u32 a, b; } D_01d44100;
extern u8 D_01d44108[];
void func_0031a830(void*) asm("_Z13func_0031a830Pv");
void func_003200c0(void*);
void wtarget_001b1c38(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_001b1c38jjjj");
void wtarget_001b1c38(u32 a, u32 b, u32 c, u32 d)
{
    if (b == 0xffff && a == 1) {
        D_01d44100.a = 0;
        D_01d44100.b = 0;
    }
    if (b == 0xffff && a == 1) {
        u8* p = D_01d44108;
        for (s32 i = 15; i != -1; i--) {
            *(f32*)(p + 12) = *(f32*)(p + 8) = 0.0f;
            func_0031a830(p + 16);
            p += 40;
        }
        func_003200c0(D_01d44108);
    }
}
struct M44 { FV r[4]; };
static inline FV MulMV(const M44* m, const FV* v)
{
    FV out;
    asm volatile(
        "lqc2 $vf5, 0(%1)\n\t"
        "lqc2 $vf1, 0(%2)\n\t"
        "lqc2 $vf2, 16(%2)\n\t"
        "lqc2 $vf3, 32(%2)\n\t"
        "lqc2 $vf4, 48(%2)\n\t"
        "vmulax.wxyz ACC, $vf1, $vf5x\n\t"
        "vmadday.wxyz ACC, $vf2, $vf5y\n\t"
        "vmaddaz.wxyz ACC, $vf3, $vf5z\n\t"
        "vmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
        "sqc2 $vf5, 0(%0)"
        : : "r"(&out), "r"(v), "r"(m) : "memory");
    return out;
}
struct ZNode { f32 key; FV* pos; ZNode* next; };
struct ZList { ZNode* head; ZNode* tail; };
static inline ZNode* NextZ(ZList* l, ZNode* n)
{
    if (!n) return l->head;
    return n->next;
}
/* project v by m and insert n into list sorted by depth z/w */
// 001c1938: moved to src/anon/unit_001c0638.cpp
void func_001c1938(FV* v, ZList* list, ZNode* n, M44* m);

f32 func_00191b70(void);
extern u32 D_00351d98;
extern u8 D_0036dfe0[];
struct E16 { u32 w[4]; };
extern E16 D_0036e000[];
s32 func_001a5bd0(u32, s32, f32);
void func_001a5420(u32, E16*, u32);
// 0x1c7ca8: moved to src/anon/unit_001c7bc8.cpp

void func_00177dc8(u8*, u32, s32);
extern u8 D_00352410[];
extern u32 D_00352400;
s32 func_00181978(void);
extern u32 D_0034f240;
void func_001a1c90(u8*, s32, s32);
s32 func_001d6d88(void);
u8* func_001c1130(s32);  // copy_record_block_to_table
u32 func_00192048(s32);
void func_001c11a8(s32);
void func_001d0878(u8* o, u32 a, s32 kind);  // 0x001d0878: definition moved into src/anon/unit_001cf0b0.cpp

extern u8 D_0032bb30[];
extern u8 D_0033bc10[];
s32 func_00105868(void*);
s32 func_00276fd0(void);
s32 func_001e0a90(void*);
static inline bool Is100() { return func_00276fd0() == 100; }
bool IsFMSecretMovie(void) asm("_ZN2YS13BATTLE_REPORT15IsFMSecretMovieEv");
// 0x001d98a0 IsFMSecretMovie: definition moved into src/anon/unit_001d7458.cpp

f32 func_002f8ad0(f32, f32);
u8* func_0016f000(u32, FV*, f32);
void func_0016c018(u8*, s32, u32);
extern u32 D_003638d0;
extern f32 D_00352ad0;
static inline u32 Rand() { D_003638d0 *= 0x10dcd; return D_003638d0; }
static inline f32 Rand1() { return (f32)Rand() * 2.3283064365386963e-10f; }
static inline f32 RandR(f32 lo, f32 w) { return lo + Rand1() * w; }
// 001dbe78: moved to src/anon/unit_001dbbe0.cpp

union PtrF { u8* p; f32 f; };
extern PtrF D_01d9e6e8;
void func_0021edb0(u8*, u8*);
static inline void ScaleRow(u8* row, f32 k)
{
    asm volatile(
        "qmtc2 %1, $vf9\n\t"
        "lqc2 $vf10, 0(%0)\n\t"
        "vmulx.xyz $vf10, $vf10, $vf9x\n\t"
        "sqc2 $vf10, 0(%0)"
        : : "r"(row), "r"(k) : "memory");
}
void func_001eadf8(u8* base, u32 unused, u8* desc);  // 0x001eadf8: definition moved into src/anon/unit_001e8ac8.cpp

extern u32 D_01d9ea9c;
extern u32 D_01d9eab4;
extern u8* D_01d9e6e0;
void func_001f69c0(void);
void func_0021ee48(u8*, u8*, void*, u8*, s16, u8, u8);
void func_001f6b68(u8* base, u8* in, u8* desc);  // 0x001f6b68: definition moved into src/anon/unit_001f6b68.cpp

extern u8 D_00354be0[];
void sceVu0CopyVector(u8*, void*);  // memcpy16
void func_001fb8b8(u8*, s32, s32);
void func_001fb9a8(u8* base, u8* in, u8* desc);  // 0x001fb9a8: definition moved into src/anon/unit_001fb350.cpp

void func_00201ca0(u8* p, s32* x, s32* w, s32* y, s32* h);  // 0x00201ca0: definition moved into src/anon/unit_00201bb0.cpp
s32 func_00287bc0(void);
void func_00287d68(void);  // copy_globals_3words
s32 func_00287db0(void);
s32 func_0028acc8(u32);
s32 func_00139d78(void*);
void func_001039f8(void);
void func_0024be68(void);
void func_0024bfb8(void);
extern u32 D_0035eda8;
extern u32 D_0035edac;
extern void* D_0035edb0;
extern void* D_0035edb4;
extern void* D_0035edb8;
s32 func_0024bd90(void);  // 0x0024bd90: definition moved into src/anon/unit_0024ba58.cpp
union PtrI { u8* p; s32 i; };
extern PtrI D_0035f20c;
extern u32 D_0035f14c;
extern u32 D_0035f148;
extern u32 D_0035f210;
void func_0028d980(u8*, s32, u32, u32, u32, s32, s32, s32, s32);
void func_00275d10(void);  // 0x00275d10: definition moved into src/anon/unit_002748a0.cpp

void func_00276088(u32, s32*, s32*);
extern u16 D_00373d70[3];
void func_00276150(u32 a, s32* out0, s32* out1);  // 0x00276150: definition moved into src/anon/unit_002748a0.cpp
u8* func_0023f1b0(void*);
u32 func_0023c3e0(u8*, s32, s32);
u32 func_0028dbf8(void* a, s16* keys, s16* vals);  // 0028dbf8: moved to src/anon/unit_0028c878.cpp

s32 func_00192a80(u32);
s32 func_00105c30(void);
extern char D_00374470[];
u32 func_00192cc0(char*, const char*);
s32 func_00192b30(u32);
void memcpy(u8*, char*, s32);
u8* func_0028de08(u32 id, u8* buf);  // 0028de08: moved to src/anon/unit_0028c878.cpp

s8* func_00276568(void);
s32 func_002a4380(s8);
s32 func_002b3ae8(void);
s32 func_002a9b88(s8);
s32 func_002a8870(s8);
s32 JmReport_GetIndex(u32 idx) asm("_ZN2Tz8JmReport8GetIndexEj");
s32 JmReport_GetIndex(u32 idx);  // 0x00296da8: definition moved into src/anon/unit_00295d28.cpp
union GP { u8* p; s32 i; };
extern GP D_0035f5e4;
s8* func_00276568(void);
void func_002a4b78(void);  // 0x002a4b78: definition moved into src/anon/unit_002a40c8.cpp

static inline bool TestBit(u32* bits, u32 i) { return (bits[i >> 5] & (1 << (i & 31))) != 0; }
extern u8* D_0035f610;
extern u8* D_0035f620;
u8* func_001a82b0(u8*);
s32 func_002764b0(u8);
bool func_002adaf0(s32 who);  // 0x002adaf0: definition moved into src/anon/unit_002a99c8.cpp
void func_002edf28(u8*);  // obj_ctor_3637e0
u8* func_001050d8(u32);
void func_001ad0f8(u8*, u32, s32);
void func_001ad330(u8*, u32);
extern u8 D_00361980[];
union PtrS { u8* p; s32 i; };
void func_002bec88(u8* o, s32 kind, u32 arg);  // 0x002bec88: definition moved into src/anon/unit_002bebd0.cpp

void func_002369a0(u8*);  // obj_ctor_36eac8
void func_0023c008(u8*);  // obj_ctor_36eae8
extern u8 D_00363880[];
extern u8 D_003619a8[];
extern u32 D_00361998;
u8* func_002beb90(void);
u32 func_001708f8(u8*, s32);
u8* func_00168b38(u32, s32, s32);  // entry_array_find_nth
void func_002ef1f8(u8*, u32, u32);
void func_002bf308(void);
void func_00102c18(s32, u32, void*);
void func_002befc0(u8* o);  // 0x002befc0: definition moved into src/anon/unit_002bebd0.cpp

struct V4f { f32 x, y, z, w; };
extern V4f D_01e2bc70;
extern V4f D_01e2bc80;
extern V4f D_01e2bc90;
static inline void Set4(V4f* v, f32 x, f32 y, f32 z, f32 w) { v->x = x; v->y = y; v->z = z; v->w = w; }
void wtarget_002c0738(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_002c0738jjjj");
void wtarget_002c0738(u32 a, u32 b, u32 c, u32 d);  // 0x002c0738: definition moved into src/anon/unit_002bebd0.cpp
/* sign + decimal digits of v after prefix char c; returns length */
s32 func_00301480(char* buf, s32 v, s32 c)
{
    char tmp[40];
    char* p = buf;
    *p++ = c;
    if (v < 0) {
        v = -v;
        *p++ = '-';
    } else {
        *p++ = '+';
    }
    char* q = tmp + 40;
    char* end = q;
    if (v >= 10) {
        do {
            *--q = v % 10 + '0';
            v /= 10;
        } while (v >= 10);
        *--q = v + '0';
        while (q < end) *p++ = *q++;
    } else {
        *p++ = '0';
        *p++ = v + '0';
    }
    return p - buf;
}
void func_001af638(void);
void func_001af6f0(void);
void func_001bb468(u8*);
u32 func_001c10f8(s32);  // request_pool_block64
s32 func_0017a538(u8*);
u32 func_001d1438(s32);
u32 func_0016a020(u8*);
static inline bool Is12(u8* p) { return *(s32*)(p + 2896) == 12; }
void func_001af0c0(u8* o);  // 0x001af0c0: definition moved into src/anon/unit_001ada38.cpp
extern char D_0036ef58[];
extern char D_0036efb8[];
extern char D_0036ef98[];
extern char D_0036ef88[];
void func_002fdfc8(const char*, ...);  // device_vprintf_va
u8* func_001e7a98(u8*, u8*);
static inline void AssertFail(const char* expr, const char* file, u32 line)
{
    func_002fdfc8(D_0036ef58, expr);  // device_vprintf_va
    func_002fdfc8(D_0036ef98, file, line);  // device_vprintf_va
    asm volatile("break");
}
void func_001e8ac8(u8* o);  // 0x001e8ac8: definition moved into src/anon/unit_001e8ac8.cpp

u8* func_001a80c8(u16);  // table24_find_by_id
bool func_002ab8e8(s32 who);  // 0x002ab8e8: definition moved into src/anon/unit_002a99c8.cpp
u8* func_002a9d68(s32);
bool func_002aaab8(s32 id);  // 0x002aaab8: definition moved into src/anon/unit_002a99c8.cpp
}
