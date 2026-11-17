#include "../common/types.h"

// ---- 001c4050 gap (calls 001c3f58, then publishes the record pointer)
namespace n001c4050 {
void func_001c3f58(void) asm("func_001c3f58");
extern u8 D_01d49570[] asm("D_01d49570");
extern u8* D_0032b994 asm("D_0032b994");
void func_001c4050(void) asm("func_001c4050");
void func_001c4050(void) {
    func_001c3f58();
    D_0032b994 = D_01d49570;
}
}  // namespace n001c4050

// ---- 001c4080 from src/anon/batch_w23.cpp
namespace n001c4080 {
void wtarget_001c4080(u32, u32, u32, u32) asm("_Z16wtarget_001c4080jjjj");
struct Flags3 { u8 a[3]; u8 pad; u16 h[3]; };
extern Flags3 D_01d49570 asm("D_01d49570");
void wtarget_001c4080(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        u16* h = D_01d49570.h;
        u8* c = D_01d49570.a;
        c[1] = b; c[0] = b; c[2] = b;
        h[0] = b; h[1] = b; h[2] = b;
    }
}
}  // namespace n001c4080

// ---- 001c40c0 from src/anon/tiny_wrappers_more.cpp
namespace n001c40c0 {
u32 func_001c4080(u32, u32, u32, u32) asm("_Z16wtarget_001c4080jjjj");
u32 func_001c40c0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001c40c0jjjj");
u32 func_001c40c0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001c4080(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n001c40c0

