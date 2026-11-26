#include "../common/types.h"
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct E { u8 b0; u8 b1; u8 pad[38]; u16 h28; u8 pad2[22]; };
struct Tbl { u32 a; s32 n; E e[1]; };
struct X { u8 pad[16]; u32 w10; };
struct Z { u16 h0; };
extern "C" {
extern u32 D_003638d0;
extern Tbl* D_01d5ba28;
extern f32 D_0036e454;
s32 func_001d4420(void);
s32 func_001d3c78(E*);
s32 func_001d3e40(E*);
void* func_0017e668(u8);
X* func_00177860(void*);
V4* YS__OBJ__get_pos(void*);  // obj_get_attach_or_alt
Z* YS__COMMAND_ELEM__Get(u16);
s32 YS__COMMAND_SLOT__GetStatus(Z*, void*, s32);
}
static inline bool Near(Z* z, void* a) { return YS__COMMAND_SLOT__GetStatus(z, a, 0) < 4; }
extern "C" {
Z* func_001d45a0(void* self, u32 id);  // 0x001d45a0: definition moved into src/anon/unit_001d3c08.cpp
}
// 0x002ff970 _strtol_r: definition moved into src/newlib/libc/strtol.c
