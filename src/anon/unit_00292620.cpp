#include "../common/types.h"
#include "../tozawa/load_data.hpp"

// 00292620 (gap: unwritten in the old code; the task end callback that LoadDataFlush installs)
namespace n00292620 {
extern u8 D_0035f4b8 asm("D_0035f4b8");
void func_00292620() asm("func_00292620");
void func_00292620() { D_0035f4b8 = 0; }
}  // namespace n00292620

// 00292630 (from src/anon/batch_w44.cpp)
namespace n00292630 {
s32 LoadDataIsFlushing(void) asm("_ZN2Tz18LoadDataIsFlushingEv");
u8* func_00103eb0(void) asm("func_00103eb0");
s32 func_00102a38(void*, void*) asm("func_00102a38");
void func_00292608(void) asm("func_00292608");
s32 func_00170cd0(void) asm("func_00170cd0");
extern u8 D_0035f4b8 asm("D_0035f4b8");
// Tz::LoadDataIsFlushing(): true while load data is still being flushed.
s32 LoadDataIsFlushing(void) {
    s32 r = D_0035f4b8;
    if (func_00102a38(*(void**)(func_00103eb0() + 4), (void*)func_00292608)) return 1;
    if (!r) r = func_00170cd0();
    return r;
}
}  // namespace n00292630


// 00292690 (from src/tozawa/load_data.cpp)
namespace n00292690 {
// plain functions bound by asm label: other files define methods named Clear
void YS_CACHE_BUFF_Clear(s32) asm("_ZN2YS10CACHE_BUFF5ClearEi");
void LoadData_Clear(s32 priority) asm("_ZN2Tz8LoadData5ClearEi");
void LoadData_Clear(s32 priority) { YS_CACHE_BUFF_Clear(priority); }
}  // namespace n00292690

// 002926a8 (from src/tozawa/load_data.cpp)
namespace n002926a8 {
void* YS_CACHE_BUFF_Alloc(char const*, s32) asm("_ZN2YS10CACHE_BUFF5AllocEPKci");
void* LoadData_CacheAlloc(const char* path) asm("_ZN2Tz8LoadData10CacheAllocEPKc");
void* LoadData_CacheAlloc(const char* path) {
    return YS_CACHE_BUFF_Alloc(path, -1);
}
}  // namespace n002926a8

// 002926c0 (from src/anon/batch_w85.cpp)
namespace n002926c0 {
extern s32 D_0035f4c4 asm("D_0035f4c4");
extern s32 D_0035f4bc asm("D_0035f4bc");
extern s32 D_0035f4c0 asm("D_0035f4c0");
extern s32 D_0035f4c8 asm("D_0035f4c8");
extern s32 D_0035f4cc asm("D_0035f4cc");
extern s32 D_0035f4d0 asm("D_0035f4d0");
extern void* D_0035f4d4 asm("D_0035f4d4");
extern void* D_0035f4dc asm("D_0035f4dc");
extern void* D_0035f4e4 asm("D_0035f4e4");
extern "C" s8 D_00374590[][2];
u32 func_00103570(void) asm("func_00103570");
void* func_001063f0(s32, u32) asm("func_001063f0");
void func_002fde18(void*, s32, s32) asm("func_002fde18");
void func_002926c0(s32 idx) asm("func_002926c0");
void func_002926c0(s32 idx) {
    D_0035f4c4 = idx;
    D_0035f4bc = D_00374590[idx][0];
    D_0035f4c0 = D_00374590[idx][1] << 11;
    D_0035f4c8 = 0;
    D_0035f4cc = 0;
    D_0035f4d0 = 0;
    D_0035f4d4 = func_001063f0(D_0035f4bc * 16, func_00103570());
    func_002fde18(D_0035f4d4, 0, D_0035f4bc * 16);
    D_0035f4dc = func_001063f0(D_0035f4bc * 4, func_00103570());
    func_002fde18(D_0035f4dc, 0, D_0035f4bc * 4);
    D_0035f4e4 = func_001063f0(128, func_00103570());
    func_002fde18(D_0035f4e4, 0, 128);
}
}  // namespace n002926c0

// 002927b8 (from src/anon/batch_wcx.cpp)
namespace n002927b8 {
extern u32 D_0035f4bc asm("D_0035f4bc"); extern u32 D_0035f4c0 asm("D_0035f4c0"); extern u32 D_0035f4c4 asm("D_0035f4c4"); extern u32 D_0035f4c8 asm("D_0035f4c8"); extern u32 D_0035f4cc asm("D_0035f4cc"); extern u32 D_0035f4d0 asm("D_0035f4d0");
extern u16 D_0035f4d8 asm("D_0035f4d8"); extern u16 D_0035f4e0 asm("D_0035f4e0");
extern u8 D_0035f4e2 asm("D_0035f4e2");
extern void* D_0035f4d4 asm("D_0035f4d4");
extern void* D_0035f4dc asm("D_0035f4dc");
extern void* D_0035f4e4 asm("D_0035f4e4");
void func_00106450(void*) asm("func_00106450");
void func_002927b8(void) asm("func_002927b8");
void func_002927b8(void)
{
    D_0035f4bc = 0;
    D_0035f4c0 = 0;
    D_0035f4c4 = 0;
    D_0035f4d8 = 0;
    D_0035f4e0 = 0;
    D_0035f4d0 = 0;
    D_0035f4c8 = 0;
    D_0035f4cc = 0;
    D_0035f4e2 = 0;
    if (D_0035f4d4) { func_00106450(D_0035f4d4); D_0035f4d4 = 0; }
    if (D_0035f4dc) { func_00106450(D_0035f4dc); D_0035f4dc = 0; }
    if (D_0035f4e4) { func_00106450(D_0035f4e4); D_0035f4e4 = 0; }
}
}  // namespace n002927b8

// 00292870 (from src/anon/batch_w65.cpp)
namespace n00292870 {
s32 func_00253b00(void) asm("func_00253b00");
s32 func_00253b18(void) asm("func_00253b18");
void func_00292a58(void) asm("func_00292a58");
extern s32 D_0035f4c8 asm("D_0035f4c8");
extern s32 D_0035f4cc asm("D_0035f4cc");
extern s32 D_0035f4c0 asm("D_0035f4c0");
extern s32 D_0035f4bc asm("D_0035f4bc");
extern s16 D_0035f4e0 asm("D_0035f4e0");
extern s16 D_0035f4d8 asm("D_0035f4d8");
extern u8 D_0035f4e2 asm("D_0035f4e2");
extern s32 D_0035f4d0 asm("D_0035f4d0");
void func_00292870(void) asm("func_00292870");
void func_00292870(void) {
    D_0035f4c8 = func_00253b00();  // get_global_ptr_1dae6c0
    D_0035f4cc = func_00253b18();
    D_0035f4d0 = D_0035f4cc / D_0035f4c0;
    if (D_0035f4d0 > D_0035f4bc) D_0035f4d0 = D_0035f4bc;
    D_0035f4cc = 0;
    D_0035f4d8 = 0;
    D_0035f4e0 = 0;
    D_0035f4e2 = 0;
    func_00292a58();
}
}  // namespace n00292870


// 002928f0 (gap function, not written before): count down the load-data step counter; at zero,
// clear the current entry of the 16-byte table
namespace g002928f0 {
struct E16 { s32 a, b, c, d; };
struct E4 { s16 x, y; };
extern u16 D_0035f4e0 asm("D_0035f4e0");
extern E4* D_0035f4dc asm("D_0035f4dc");
extern u8 D_0035f4e2 asm("D_0035f4e2");
extern s16 D_0035f4d8 asm("D_0035f4d8");
extern E16* D_0035f4d4 asm("D_0035f4d4");
void func_002928f0(s32 n) asm("func_002928f0");
void func_002928f0(s32 n) {
    s16 c = D_0035f4e0;
    if (c == 0) return;
    D_0035f4e0 -= n;
    s16 nc = D_0035f4e0;
    s16 y = D_0035f4dc[nc].y;
    D_0035f4d8 = y;
    if (!D_0035f4e2) return;
    if (nc != 0) return;
    D_0035f4d4[y].a = 0;
    D_0035f4d4[D_0035f4d8].b = 0;
    D_0035f4d4[D_0035f4d8].d = 0;
    D_0035f4d4[D_0035f4d8].c = 0;
}
}  // namespace g002928f0
