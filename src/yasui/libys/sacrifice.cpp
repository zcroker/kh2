// YS::SACRIFICE, linked unit 0x1c9770-0x1c9ea0. .rodata at 0x36e0a4. The method names are in
// sacrifice.hpp; the bodies below are the matched code, one namespace per function.

#include "../../common/types.h"
#include "../../anon/auto80_199_queue_decls.hpp"

// ---- 001c9770 from src/anon/tiny.cpp
namespace n001c9770 {
void func_001c9770(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001c9770jjjj");
void func_001c9770(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x0035u << 16);
    *(u32*)((u32)b + (7984)) = (u32)0;
}
}  // namespace n001c9770

// ---- 001c9780 from src/anon/tiny_auto80_queue.cpp
namespace n001c9780 {
void func_001c97b0(void*, f32) asm("_Z13func_001c97b0Pvf");
void* func_0016a070(f32) asm("func_0016a070");
void func_001c9780(f32 f12) asm("_Z13func_001c9780f");
void func_001c9780(f32 f12) {
    f32 f20 = f12;
    void* v0 = func_0016a070(f12);
    func_001c97b0(v0, f20);
}
}  // namespace n001c9780

// ---- 001c97b0 from src/anon/batch_w239.cpp
namespace n001c97b0 {
void func_001ad990(u32, f32, f32, f32) asm("func_001ad990");
void* func_0017e668(void) asm("func_0017e668");
s32 func_0019ba60(void*) asm("func_0019ba60");
void* func_001a8f10(void*) asm("func_001a8f10");
extern s32 D_00351f30 asm("D_00351f30");
extern u32 D_01d49980[] asm("D_01d49980");
void func_001c97b0(void* a, f32 f) asm("_Z13func_001c97b0Pvf");
void func_001c97b0(void* a, f32 f) {
    u8* s0 = (u8*)func_0017e668();
    if (func_0019ba60(s0)) {
        if (!(*(volatile u32*)(s0 + 2040) & 0x10)) {
            func_001ad990((u32)(s0 + 2092), 1.0f, 0.0f, f);
        }
        *(u32*)(s0 + 2040) |= 0x10;
    }
    D_01d49980[D_00351f30++] = (u32)func_001a8f10(a);                  
}
}  // namespace n001c97b0

// ---- 001c9860 from src/anon/batch_w60.cpp
namespace n001c9860 {
s32 func_0019ba60(void*) asm("func_0019ba60");
void* func_0017df58(s32) asm("func_0017df58");
void* func_0016a070(void*) asm("func_0016a070");
s32 func_001c9958(void*, void*) asm("func_001c9958");
void func_001c9780(void*, f32) asm("func_001c9780");
void func_001c9860(void* p) asm("func_001c9860");
void func_001c9860(void* p) {
    s32 i;
    for (i = 0; i < 2; i++) {
        void* o = func_0017df58(i);
        if (func_0019ba60(o) && func_001c9958(p, func_0016a070(o))) func_001c9780(o, 15.0f);
    }
}
}  // namespace n001c9860

// ---- 001c98f0 from src/anon/auto80_199_queue.cpp
namespace n001c98f0 {
void func_001c98f0(f32 a0) asm("_Z13func_001c98f0f");
void func_001c98f0(f32 a0) {
    s32 s17 = 0;
    while (s17 < 2) {
        u32 s16 = func_0017df58((u32)s17);
        s17 = s17 + 1;
        if (func_0019ba60(s16) != 0) {
            func_001c9780(s16, a0);
        }
    }
}
}  // namespace n001c98f0

// ---- 001c9958 from src/anon/batch_w30.cpp
namespace n001c9958 {
static inline bool in_1_6(s32 a) { return a != 0 && a < 7; }
u8 func_001c9958(s32 a, s32 b) asm("func_001c9958");
u8 func_001c9958(s32 a, s32 b) {                     
    if (!in_1_6(a)) return 0;
    switch (a) {
    case 2: return b == 2;
    case 1: return b == 3;
    case 3: return 0;
    }
    return 1;
}
}  // namespace n001c9958

// ---- 001c99b0 from src/anon/batch_w97.cpp
namespace n001c99b0 {
f32 func_001bbfd0(s32) asm("func_001bbfd0");
u32 func_0017df58(s32) asm("func_0017df58");
s32 func_0019ba60(u32) asm("func_0019ba60");
u32 func_0016a070(u32) asm("func_0016a070");
s32 func_001c9958(s32, u32) asm("func_001c9958");
s32 func_0017e358(u32) asm("func_0017e358");
static inline bool tooFar(s32 mode) { return 1.0f < func_001bbfd0(mode); }
s32 func_001c99b0(s32 mode) asm("func_001c99b0");
s32 func_001c99b0(s32 mode) {
    s32 cnt = 0;
    s32 res = 0;
    if (tooFar(mode)) return 0;
    if (mode == 3) return 0;
    for (s32 i = 0; i < 2; i++) {
        u32 m = func_0017df58(i);
        u32 c;
        if (func_0019ba60(m)) c = func_0016a070(m);
        else c = 0;
        if (!func_001c9958(mode, c)) continue;
        if (!c) { res = 2; break; }
        cnt++;
        if (!func_0017e358(m)) res = 1;
    }
    return cnt ? res : 2;
}
}  // namespace n001c99b0

// ---- 001c9ab8 from src/anon/batch_w55.cpp
namespace n001c9ab8 {
s32 func_001bc010(void) asm("func_001bc010");
u32 func_0017df58(s32) asm("func_0017df58");
s32 func_0019ba60(u32) asm("func_0019ba60");
s32 func_0017e3b8(u32) asm("func_0017e3b8");
s32 func_001c9ab8(void) asm("func_001c9ab8");
s32 func_001c9ab8(void) {
    if (func_001bc010()) return 1;
    s32 i;
    for (i = 0; i < 2; i++) {
        u32 o = func_0017df58(i);
        if (!func_0019ba60(o)) return 0;
        if (!func_0017e3b8(o)) return 0;
    }
    return 1;
}
}  // namespace n001c9ab8

// ---- 001c9b38 from src/anon/batch_w31.cpp
namespace n001c9b38 {
int func_001c9ab8(void*) asm("func_001c9ab8");
int func_001c99b0(int) asm("func_001c99b0");
int func_001c9b38(u8* p) asm("func_001c9b38");
int func_001c9b38(u8* p) {
    int r;
    switch (*(u16*)(p + 2)) {
    case 4:
        return func_001c99b0(*(s16*)(p + 4));
    case 72:
        r = 2;
        if (!func_001c9ab8(p)) goto out;
    default:
        r = 0;
    }
out:
    return r;
}
}  // namespace n001c9b38

// ---- 001c9b90 from src/anon/batch_w36.cpp
namespace n001c9b90 {
void func_001c9c00(void) asm("func_001c9c00");
void func_001c9c78(u32) asm("func_001c9c78");
extern s32 D_00351f30 asm("D_00351f30");
extern u32 D_01d49980[] asm("D_01d49980");
void func_001c9b90(void) asm("func_001c9b90");
void func_001c9b90(void) {
    s32 i;
    func_001c9c00();
    for (i = 0; i < D_00351f30; i++) func_001c9c78(D_01d49980[i]);
    D_00351f30 = 0;
}
}  // namespace n001c9b90

// ---- 001c9c00 from src/anon/batch_w38.cpp
namespace n001c9c00 {
extern s32 D_00351f30 asm("D_00351f30");
extern u32 D_01d49980[] asm("D_01d49980");
s32 func_001c9d88(u32) asm("func_001c9d88");
s32 func_001c9c00(void) asm("func_001c9c00");
s32 func_001c9c00(void) {
    for (s32 i = 0; i < D_00351f30; i++) {
        if (!func_001c9d88(D_01d49980[i])) return 0;
    }
    return 1;
}
}  // namespace n001c9c00

// ---- 001c9c78 from src/anon/batch_w254.cpp
namespace n001c9c78 {
extern s32 D_0034e948 asm("D_0034e948");
s32 func_0019ba60(s32) asm("func_0019ba60");
void* func_001a8bd0(s32) asm("func_001a8bd0");
s32 func_001a8bf8(void*, s32) asm("func_001a8bf8");
u8* func_001a8b28(void) asm("func_001a8b28");
u8* func_0017e4f8(u16, s32, f32, f32, f32) asm("func_0017e4f8");
void func_001ad990(u8*, f32, f32, f32) asm("func_001ad990");
u8* func_001c9c78(s32 a0) asm("func_001c9c78");
u8* func_001c9c78(s32 a0) {
    void* m;
    s32 i;
    u8* r;
    if (func_0019ba60(D_0034e948) == 0) return 0;
    m = func_001a8bd0(-1);
    for (i = 1; i < 3; i++) {
        if (func_001a8bf8(m, i) == a0) break;
    }
    if (i >= 3) return 0;
    r = func_0017e4f8(*(u16*)(func_001a8b28() + a0 * 2 + 16), 0, 100.0f, 200.0f, 300.0f);
    if (r != 0) {
        if (!(*(u32*)(r + 2040) & 0x10)) {
            f32 c = 15.0f;
            f32 b = 1.0f;
            func_001ad990(r + 2092, 0.0f, b, c);
        }
    }
    return r;
}
}  // namespace n001c9c78

// ---- 001c9d88 from src/anon/batch_w6.cpp
namespace n001c9d88 {
u32 ys_can_end(void) asm("_ZN2YS9SACRIFICE6CanEndEv");
u32 func_001a8b68(void) asm("func_001a8b68");
u32 func_0017e668(u32) asm("func_0017e668");
u32 ys_can_end(void) {
    return func_0017e668(func_001a8b68()) == 0;
}
}  // namespace n001c9d88

// ---- 001c9db0 from src/anon/batch_w25.cpp
namespace n001c9db0 {
extern s32 D_00351f30 asm("D_00351f30");
extern u32 D_01d49980[] asm("D_01d49980");
s32 func_001c9db0(u32 x) asm("func_001c9db0");
s32 func_001c9db0(u32 x) {
    s32 i;
    for (i = 0; i < D_00351f30; i++)
        if (D_01d49980[i] == x) return 1;
    return 0;
}
}  // namespace n001c9db0

// ---- 001c9df8 from src/anon/batch_w26.cpp
namespace n001c9df8 {
inline void* operator new(unsigned int, void* p) { return p; }
void* friend_get(s32) asm("_ZN2YS6FRIEND3GetEi");
s32 obj_is_leave(void*) asm("_ZN2YS3OBJ8is_leaveEv");
s32 func_001c9df8(void) asm("func_001c9df8");
s32 func_001c9df8(void) {
    s32 i;
    for (i = 0; i < 2; i++) {
        void* f = friend_get(i);
        if (f && obj_is_leave(f)) return 1;
    }
    return 0;
}
}  // namespace n001c9df8

// ---- 001c9e50 from src/anon/batch_w25.cpp
namespace n001c9e50 {
void func_00102448(void*, u32) asm("func_00102448");
s32 func_00197920(void) asm("func_00197920");
s32 func_0017a6c8(void*) asm("func_0017a6c8");
void func_001c9e50(void* a) asm("func_001c9e50");
void func_001c9e50(void* a) {
    while (func_00197920() || func_0017a6c8(a)) func_00102448(a, 0);
}
}  // namespace n001c9e50

