#include "../common/types.h"

extern "C" {

union PtrF247 { u8* p; f32 f; };
extern PtrF247 D_01d9e6e8;
void func_001e8fe0(u8*, u8*);
void func_0021ec80(u8*, u8*);
void func_0021ebe8(u8*, u8*);
void func_0021ed18(u8*, u8*);
void func_0021edb0(u8*, u8*);
// VU0 macro: scale row xyz by k.
static inline void ScaleRow247(u8* row, f32 k)
{
    asm volatile(
        "qmtc2 %1, $vf9\n\t"
        "lqc2 $vf10, 0(%0)\n\t"
        "vmulx.xyz $vf10, $vf10, $vf9x\n\t"
        "sqc2 $vf10, 0(%0)"
        : : "r"(row), "r"(k) : "memory");
}
void func_001ea970(u8* base, u32 unused, u8* desc);  // 0x001ea970: definition moved into src/anon/unit_001e8ac8.cpp
void func_001eac28(u8* base, u32 unused, u8* desc);  // 0x001eac28: definition moved into src/anon/unit_001e8ac8.cpp
void func_001efe48(u8* base, u32 unused, u8* desc)
{
    u32* d = *(u32**)(desc + 12);
    u8* p0 = base + d[0];
    u8* p1 = base + d[1];
    u8* p2 = base + d[2];
    f32* t = (f32*)(p0 + 160);
    f32* s = (f32*)(p2 + 160);
    func_001e8fe0(D_01d9e6e8.p + 16, p1 + 160);
    ScaleRow247(D_01d9e6e8.p + 16, s[0]);
    ScaleRow247(D_01d9e6e8.p + 32, s[1]);
    ScaleRow247(D_01d9e6e8.p + 48, s[2]);
    *(f32*)(D_01d9e6e8.p + 64) = t[0];
    *(f32*)(D_01d9e6e8.p + 68) = t[1];
    *(f32*)(D_01d9e6e8.p + 72) = t[2];
}
void func_001f0f90(u8* base, u32 unused, u8* desc);  // 0x001f0f90: definition moved into src/anon/unit_001f0cd8.cpp
void func_001f1078(u8* base, u32 unused, u8* desc);  // 0x001f1078: definition moved into src/anon/unit_001f0cd8.cpp
void func_001f1160(u8* base, u32 unused, u8* desc);  // 0x001f1160: definition moved into src/anon/unit_001f0cd8.cpp

extern u8 D_0035eae8;
struct Sub6_247 { u32 a, b, c, d, e, f; };
struct Obj237 {
    u32 vt; u32 f4, f8, f12;
    u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1;
    u32 f20, f24, f28, f32, f36, f40, f44, f48, f52, f56, f60, f64, f68, f72, f76;
    Sub6_247 s;
    u32 g[14];
};
// Constructor: vtable, clear every field and seven flag bits.
void func_00237068(Obj237* o);  // 0x00237068: definition moved into src/anon/unit_00237068.cpp

u32 func_002bc988(void*) asm("_Z13func_002bc988Pv");
s32 func_002bc9d8(u8*, u32);
void func_002bc9a8(u8*, s32, u32);  // find_entry12_set_field
s32 func_002bc978(void*);
void func_002bcda8(u8*, s32);
void func_002bd188(u8*, s32);
// Allocates a run of slots; on a fresh id (-1) assigns ids starting at o+328.
s32 func_002bca78(u8* o, void* a, void* b, s32* out, u32* out2);  // 0x002bca78: definition moved into src/anon/unit_002bc978.cpp

}
