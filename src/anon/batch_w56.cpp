#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));

// Local type whose non-trivial destructor keeps gcc from emitting a sibling call.
struct NoTail { ~NoTail() {} };

extern "C" {

void wtarget_0014ce88(void) asm("_Z16wtarget_0014ce88jjjj");
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");

// 00132e28: look up an entry, flag the owner and hand the entry's data to 00132720
u8* func_00132c68(void*, u32);
s32 func_001325c8(void*, s32, u32);
void func_00132720(void*, u8*);
void func_00132e28(u8* a, u32 b);  // 0x00132e28: definition moved into src/anon/unit_00131418.cpp

// 00133938: write a 16-byte packet header at the cursor and advance the cursor
struct PktHdr { u16 id; u8 b2; u8 b3; PktHdr* next; PktHdr* p8; PktHdr* p12; };
PktHdr* wtarget_00133938(PktHdr** pp, PktHdr* next, u32 id, u32 a3, u32 a4) asm("_Z16wtarget_00133938jjjj");
PktHdr* wtarget_00133938(PktHdr** pp, PktHdr* next, u32 id, u32 a3, u32 a4);  // 0x00133938: definition moved into src/anon/unit_00131418.cpp

// 00143ae0
extern void* D_00348804;
void func_00141c18(void*, u32, u32, u32, u32);
void func_00141ff0(void*, u32, u32, u32, u32);
void func_00143ae0(u32 a, u32 b, u32 c, u32 d);  // 0x00143ae0: definition moved into src/anon/unit_00142c90.cpp

// 0014ce88: count frames then derive a scaled time step and its reciprocal
extern s32 D_00349e1c;
extern f32 D_00349e10;
extern f32 D_00349e0c;
extern f32 D_00349e14;
extern f32 D_00349e18;
void wtarget_0014ce88(void)
{
    D_00349e10 = 0.0f;
    for (s32 i = 0; i < D_00349e1c + 1; i++) D_00349e10 += 1.0f;
    f32 s = D_00349e10;
    D_00349e14 = s;
    D_00349e10 = s * D_00349e0c;
    D_00349e18 = 1.0f / D_00349e10;
}

// 00153840: mark every slot, then process each bit set in a 64-bit mask
extern s32 D_0034a77c;
extern u8* D_0034a790;
void func_00153948(u8);
void func_00153840(u64 mask);  // 0x00153840: definition moved into src/anon/unit_00153678.cpp

// 0015c068
s32 func_001665d8(void*, f32*, f32*, f32*, f32*, f32*, f32*);
void func_0015c068(u8* p, void* a);  // 0x0015c068: definition moved into src/anon/unit_0015bab8.cpp

// 0016be98: returns a 128-bit value by hidden pointer
struct L16be98 { u32 a, b, c, d; u128 v; };
void* func_0016bc20(u8*, s32, s32);
void func_0018a818(void*, u8*, void*);
u128* func_0016be98(u128* out, u8* a)
{
    L16be98 l;
    u128* src = &l.v;
    l.d = 0;
    void* r = func_0016bc20(a, 1, -1);
    if (r) {
        func_0018a818(&l, a, r);
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(out), "r"(src) : "$8", "memory");
    } else {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(out), "r"(a + 1344) : "$8", "memory");
    }
    return out;
}

// 0016e000
void* func_0014aba8(void);
void func_0014aa58(void*, s32, s32);
// 0016e000: moved to src/anon/unit_0016d2e0.cpp

// 0017cb78
void func_0017f488(u8*, s32, f32, f32);
void func_00180c88(u8*, s32, f32);
// 0017cb78: moved to src/anon/unit_0017c400.cpp

// 001884d0
union U188 { u16 h; u32 w; };
extern u32 D_01c60be0[];
u8* func_00187ab8(void*, u32);
void func_00188398(u8*, u16, u32*, s32);
// 001884d0: moved to src/anon/unit_00185d10.cpp
void func_001884d0(u8* a, u32* b);

// 00196e00
struct Fl196 { u16 h0; u16 b0 : 1; u16 b1 : 4; u16 b5 : 1; };
inline u8 fl196_b5(Fl196* f) { return f->b5; }
inline u8 fl196_b0(Fl196* f) { return f->b0; }
struct O196 { u8 pad[60]; Fl196* fl; };
void func_00226da8(O196*);
void func_0014c9f0(s32);
void func_001c11a8(s32);
void func_001384a0(s32);
void func_002bc798(void);
void func_002ba610(void);  // zero_global_byte_1e3
extern u32 D_0035037c;
void func_00196e00(O196* a);  // 0x00196e00: definition moved into src/anon/unit_00195d00.cpp

// 0019ecb0: start the blur effect
void func_0014a7e8(s32);
void func_0014a768(u8);
void func_0014a788(u16, u16);
void func_0014a7b8(f32, u32);
void func_0014a7f8(s32);
void func_001ad990(u8*, f32, f32, f32);
struct BlurState { u32 started : 1; u32 rest : 31; void* on; u8 b8; u8 p9[3]; u16 x; u16 p0e; u16 y; u16 p12; f32 f20; u32 i24; u8 tail[4]; };
void blur_start(BlurState* self, f32 t) asm("_ZN2YS4BLUR5startEf");
void blur_start(BlurState* self, f32 t);  // 0x0019ecb0: definition moved into src/anon/unit_0019ea10.cpp

// 001a60c8
struct S1a6 { u8 pad[40]; u32 v; };
extern S1a6 D_00350800[];
u32 func_001a6658(s32);
void func_001bdff0(void);
// 001a60c8: moved to src/yasui/libys/magic.cpp

// 001aa8f0
void func_001ab260(u32, u8*, u32, u32, u32, u32, u32, f32, f32);
void func_001aa8f0(u8* p, u32 a1, u32 a2, u32 a3, u32 a4);  // 0x001aa8f0: definition moved into src/anon/unit_001a9130.cpp

// 001ae010: does the file name's extension match one of two known extensions?
struct P1ae { const char* a[2]; };
extern P1ae D_0036d850;
char* func_002ff8b0(const char*, s32);
s32 strcmp(const char*, const char*);  // strcmp
s32 func_001ae010(const char* s);  // 0x001ae010: definition moved into src/anon/unit_001ada38.cpp

// 001b2520: push a 128-bit value into a ring buffer
struct Ring { s32 cap; s32 count; s32 head; u32 pad[2]; u128* buf; };
// 001b2520: moved to src/anon/unit_001b1d20.cpp

// 001b3330: clear bit 1 on every occluder entry
struct OccS;
struct OccH;
union OccF { u32 v; s32 i; OccS* s; OccH* h; };
struct OccE { u8 pad[8]; OccF fl; };
struct OccS { u8 pad[128]; OccE* e; u8 pad2[12]; };
struct OccH { u32 x; s32 n; };
struct OccSet { OccH* h; OccS* s; };
void occ_enable_all(OccSet* self) asm("_ZN2YS6OBJOCC10enable_allEv");
void occ_enable_all(OccSet* self);  // 0x001b3330: definition moved into src/anon/unit_001b2780.cpp

// 001bce00
void func_001bc720(u8*);
void func_001bc730(u8*, s32);
struct E1bc { u16 a; u16 id; u32 x[2]; };
void func_001bce00(u8* p);  // 0x001bce00: definition moved into src/anon/unit_001bc568.cpp

// 001c0298
inline bool is_kind_5_or_6(u8 v) { return (u8)(v - 5) < 2; }
s32 func_001c0298(u8* a, u8* b);  // 0x001c0298: definition moved into src/anon/unit_001bff88.cpp

// 001d5198
struct T1d5 { u8 key; u8 val; u16 arg; };
extern T1d5 D_0036e538[];
u32* func_001ba158(u8*);
void func_00181178(u16);
void func_001d5198(u8* p);  // 0x001d5198: definition moved into src/anon/unit_001d4f40.cpp

// 001d77a0
s32 func_001a6d08(s32);
u8* func_00189200(void*, s32);
void func_001a6c90(s32);  // set_bit_in_array_b
extern u8 D_0032e020[];
void u_call0_001d77a0(void) asm("_Z16u_call0_001d77a0v");
void u_call0_001d77a0(void);  // 0x001d77a0: definition moved into src/anon/unit_001d7458.cpp

// 001ef1a0: VU0 random number(s)
static inline f32 vu0_rand(void)
{
    f32 x;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\t"
        "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
        "vitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1" : "=r"(x) : : "$8");
    return x;
}
f32 func_001ef1a0(u8 a);  // 0x001ef1a0: definition moved into src/anon/unit_001ec098.cpp

// 00203ae8
s32 func_00203ae8(u8* a, u8* b)
{
    if (!*(u32*)(a + 80)) return 0;
    u8 t = b[204];
    if (t == 1 || t == 3 || t == 2) { if (!*(u32*)(a + 84)) return 0; }
    if (b[201] && !*(u32*)(a + 88)) return 0;
    return 1;
}

// 00226dc8
extern s32 D_0035db10;
extern u8 D_0035de27;
void func_00226d88(void);
void func_00232988(void);
void func_002bc518(void);
s32 func_00228378(void);
void func_0023d230(s32);
u32 func_002282d8(void);  // limit_15000_or_25000
void func_00102c48(s32, u32, void*, s32);
void func_00226ce8(s32);
void func_00226dc8(void);  // 0x00226dc8: definition moved into src/anon/unit_00224780.cpp

// 002530f0
struct Fn253 { u8 pad[8]; void (*fn)(void); };
Fn253* func_00253330(s32);
extern s32 D_0035eeb4;
extern s32 D_0035f3d4;
extern s16 D_01dae6a8[];
void func_00258dc8(void);
void func_0028ca78(void);
void func_00287a28(void);
void func_0028d068(s32, s32);
void func_00242790(void);
void func_0023d368(void);
void func_002530f0(s32 a);  // 0x002530f0: definition moved into src/anon/unit_002530c8.cpp

// 002656c0
u8* func_00257770(void);
void func_0028acc8(u32);
extern u32 D_0035f01c;
void func_002656c0(void);  // 0x002656c0: definition moved into src/anon/unit_00265580.cpp

// 0027af58: pick the bucket a value falls into from a table of 4 weights
s32 func_00287bc0(void);
s32 func_0028b040(u32);
s32 func_002570a0(s32);
extern s8* D_0035f230;
s32 func_0027af58(void);  // 0x0027af58: definition moved into src/anon/unit_0027a6d8.cpp

// 002ac268: set bit k in a per-index bit array (only if not already set)
u8* func_002a9d68(s32, u32);
u32 func_002abf40(s32, u32);
void func_002ac268(s32 a, u32 b);  // 0x002ac268: definition moved into src/anon/unit_002a99c8.cpp

// 002c85c8
s32 func_002c5150(u32);
void func_002c8490(u8*);
void* func_001050d8(u32);
void func_002c77b8(void*, u32);
extern u8* D_00361dd8;
void func_002c85c8(u32 a);  // 0x2c85c8: moved to src/anon/unit_002c7e68.cpp


// 002d3128
u8* func_002d1878(u32);
extern u32 D_00361f60;
void func_002d3128(u8* p, s32 n);  // 0x002d3128: definition moved into src/anon/unit_002d2498.cpp

// 003015a8: vsprintf-style formatting into a string through a fake FILE
struct StrFile { u8* p; s32 r; s32 w; s16 flags; s16 file; u8* base; s32 size; u8 pad[60]; void* data; u8 pad2[8]; };
s32 _vfprintf_r(void*, StrFile*, const char*, void*);
s32 func_003015a8(void* ptr, u8* str, const char* fmt, void* ap)
{
    StrFile f;
    f.flags = 520;
    f.base = f.p = str;
    f.size = f.w = 0x7fffffff;
    f.data = ptr;
    s32 r = _vfprintf_r(ptr, &f, fmt, ap);
    *f.p = 0;
    return r;
}

// 00313f40: soft-double helper (unpack both operands, combine, pack)
struct FpNum { s32 cls; s32 sign; s32 exp; s32 pad; u64 frac; u8 pad2[8]; };
void func_003147a0(const u64* src, FpNum* dst);
void* func_00313f98(FpNum*, FpNum*, FpNum*);
u64 func_003146c8(void*);
u64 func_00313f40(u64 a, u64 b)
{
    FpNum x, y, z;
    func_003147a0(&a, &x);
    func_003147a0(&b, &y);
    return func_003146c8(func_00313f98(&x, &y, &z));
}

// 0031a3d8 / 0031c248: destructor bodies (vtable resets, member and base teardown)
extern u8 D_00347dd0[];
extern u8 D_00347e60[];
extern u8 D_00347f98[];
extern u8 D_00347e80[];
extern u8 D_0034a568[];
void func_00239870(void*);
void func_002361d0(void*);
void func_0031a840(void*);
void func_0031a3d8(u8* p)
{
    NoTail g;
    *(void**)p = D_00347dd0;
    *(void**)(p + 896) = D_00347e60;
    func_00239870(p + 920);
    *(void**)(p + 896) = D_00347f98;
    *(void**)(p + 448) = D_00347e80;
    func_002361d0(p + 480);
    *(void**)(p + 448) = D_00347f98;
    *(void**)p = D_00347e60;
    func_00239870(p + 24);
    func_0031a840(p);
}
void func_0031c248(u8* p)
{
    *(void**)p = D_0034a568;
    *(void**)(p + 560) = D_00347e60;
    func_00239870(p + 584);
    u8* b = p + 48;
    *(void**)(p + 560) = D_00347f98;
    *(void**)b = D_00347e60;
    func_00239870(p + 72);
    func_0031a840(b);
    *(void**)p = D_00347f98;
}

}
