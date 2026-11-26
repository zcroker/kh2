#include "./saveram.hpp"

// SAVERAM (0x105748-0x105a10): the game's save block (0x10fc0 bytes of .data at 0x32bb30): its
// re-initialisation (0x105748), small getters/setters, and the file's static initialiser (0x1058f8)
// with its I/D stubs. The block's member ctors (linkonce copies at 0x319xxx, the YS/sasa ones
// elsewhere) are called out of line from the synthesized ctor and inlined in 0x105748.
// 00105748: clears the whole block and builds it again (ctor work inlined), then sets it up.
namespace n00105748 {
void func_002fd310(void*, u32) asm("func_002fd310");
void func_00319bd0(void*) asm("func_00319bd0");  // clear_18x64_entries
void func_00188e08(void*) asm("func_00188e08");
void func_00319870(void*) asm("func_00319870");  // init_18x4_entries
void func_00319930(void*) asm("func_00319930");
void func_003199d0(void*) asm("func_003199d0");
void func_00319a60(void*) asm("func_00319a60");  // clear_fixed_blocks
void func_002e7768(void*) asm("func_002e7768");
void func_001e0868(void*) asm("func_001e0868");
u32 func_00105870(void) asm("func_00105870");
void func_00188fc0(void*) asm("func_00188fc0");
void func_002be760(void*) asm("func_002be760");
void func_001e0998(void*) asm("func_001e0998");
void dk__Clock__newGame(void) asm("dk__Clock__newGame");
void func_00105860(void*, s32) asm("func_00105860");
void YS__VMCOMMON__NewGame(void) asm("YS__VMCOMMON__NewGame");
void func_0023d3d0(void) asm("func_0023d3d0");
struct Q { u32 w[4]; u8 b; };
void func_00105748(u8* p) asm("func_00105748");
void func_00105748(u8* p) {
    u8* a = p + 9456;
    func_002fd310(p, 0x10fc0);
    u8* d = p + 16796;
    u8* b = p + 16364;
    func_00319bd0(p + 12);
    func_00188e08(a);
    func_00319870(b);
    func_00319930(p + 16808);
    *(u32*)(p + 18904) = 0;
    *(u32*)(p + 18908) = 0;
    Q* q = (Q*)(p + 18912);
    u32* w = q->w;
    for (s32 i = 3; i >= 0; i--) *w++ = 0;
    q->b = 0;
    func_003199d0(d + 2136);
    func_00319a60(d + 2716);
    func_002e7768(p + 21920);
    u8* c = p + 0x100e0;
    func_001e0868(c);
    *(u32*)(p + 0) = func_00105870();
    *(u32*)(p + 4) = 58;
    func_00188fc0(a);
    func_002be760(b);
    func_001e0998(c);
    dk__Clock__newGame();
    func_00105860(p, 1);
    YS__VMCOMMON__NewGame();
    func_0023d3d0();
}
}  // namespace n00105748

// 00105860
namespace n00105860 {
void func_00105860(void* self, s32 v) asm("_Z13func_00105860Pvi");
void func_00105860(void* self, s32 v) { *(s32*)((char*)self + 9368) = v; }
}  // namespace n00105860

// 00105868
namespace SAVERAM {
s32 GetGameLevel(void* self) { return reinterpret_cast<Layout*>(self)->gameLevel; }
}  // namespace SAVERAM

// 00105870: the save id ("KH2J", "KH2E" or "KH2U" by region).
namespace n00105870 {
s32 func_00105c30() asm("func_00105c30");
u32 func_00105870() asm("_Z13func_00105870v");
u32 func_00105870() {
    s32 v = func_00105c30();
    s32 c;
    switch (v) {
    case 2:
        c = 85;
        break;
    case 1:
    case 8:
        c = 74;
        break;
    default:
        c = 69;
        break;
    }
    return ((u32)c << 24) | 0x0032484b;
}
}  // namespace n00105870

// 001058d8: SAVERAM::isGameComplete
namespace n001058d8 {
u32 func_001058d8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001058d8jjjj");
u32 func_001058d8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 v = *(u32*)((u32)a0 + (7896));
    v &= 0x0100u;
    return (v != 0);
}
}  // namespace n001058d8

// 001058e8: getSaveRam
namespace n001058e8 {
extern u32 D_0032bb30 asm("D_0032bb30");
u32 func_001058e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001058e8jjjj");
u32 func_001058e8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return (u32)&D_0032bb30;
}
}  // namespace n001058e8

// The save block itself; gcc makes the static initialiser 0x1058f8 and the stubs 0x1059d0/0x1059f0.
namespace n001058f8 {
void func_00319bd0(void*) asm("func_00319bd0");
void func_00188e08(void*) asm("func_00188e08");
void func_00319870(void*) asm("func_00319870");
void func_00319930(void*) asm("func_00319930");
void func_00319d20(void*) asm("func_00319d20");  // zero_two_words
void func_00319d30(void*) asm("func_00319d30");
void func_00319d58(void*) asm("func_00319d58");  // store_zero_byte
void func_003199d0(void*) asm("func_003199d0");
void func_00319a60(void*) asm("func_00319a60");
void func_002e7768(void*) asm("func_002e7768");
void func_001e0868(void*) asm("func_001e0868");
void func_002e77a0(void*) asm("_Z13func_002e77a0Pv");
struct SaveBlock {
    u8 b[0x10fc0];
    SaveBlock()
    {
        func_00319bd0(b + 12);
        func_00188e08(b + 9456);
        func_00319870(b + 16364);
        func_00319930(b + 16808);
        func_00319d20(b + 18904);
        func_00319d30(b + 18912);
        func_00319d58(b + 18928);
        func_003199d0(b + 18932);
        func_00319a60(b + 19512);
        func_002e7768(b + 21920);
        func_001e0868(b + 0x100e0);
    }
    ~SaveBlock()
    {
        void (*d)(void*) = func_002e77a0;  // called, not tail-jumped, as in retail
        d(b + 21920);
    }
};
SaveBlock s_saveram asm("D_0032bb30");
}  // namespace n001058f8
