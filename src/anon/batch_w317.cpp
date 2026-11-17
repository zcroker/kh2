#include "../common/types.h"
union W317YM { u8* p; u8 c; };
struct W317OF { s32 o0; s32 o4; s32 o8; };
struct W317Q { u8 pad[12]; W317OF* of; };
struct W317P { s32 a; s32 k; s32 off; u8 flag; };
struct W317Y { f32 f; W317YM m4; };
struct W317X { f32 v[4]; u8 flags; u8 pad[3]; u32 y; };
struct W317E16 { s32 a; s32 b; s32 c; s32 d; };
struct W317L { f32 a[4]; f32 b[4]; f32 t; f32 u; f32 pad[2]; f32 c[4]; };
struct W317E { u16 a; u16 id; u8 x; u8 b; u8 c; u8 d; u32 e; };
struct W317H { s32 kind; s32 pad; s32 count; W317E e[1]; };
struct W317Obj;
struct W317VT { void* f[5]; void (*f20)(W317Obj*); };
struct W317Obj { W317VT* vt; };
struct W317A { u8 d[408]; };
struct W317B { u8 d[436]; };
struct W317G { W317B b0; W317B b1; W317B b[4][4]; u8 pad[7848 - 872 - 436 * 16]; W317A a[4][4]; };
extern "C" {
extern u8* D_01d9e6e0;
extern s32 D_01d9ea9c;
extern W317Y D_01d9e360;
void sceVu0SubVector(void*, void*, void*);  // vec4_sub
void sceVu0CopyVector(void*, void*);  // memcpy16
s32 func_002225a8(void*);
void sceVu0ScaleVector(void*, void*, f32);  // vec_scale_by_f12
void sceVu0AddVector(void*, void*, void*);  // vec4_add
void func_00222730(void*, void*, void*);
void func_001fc320(u8* self, W317P* p, W317Q* q);  // 0x001fc320: definition moved into src/anon/unit_001fb350.cpp

s32 func_0013cb90(void);
u32 func_001b8e88(u32);
s32 func_0013b988(u8*, W317H*, u32, s32, s32, s32);  // table_by_arg_flags
u32 func_00192048(u32);
void func_0013b5d0(u8*, s32, s32, void*, u32, s32, s32, u32, f32, u32, s32);
void func_0013c820(u8*, s32);
void func_0013ce08(u8*, s32);
extern s32 D_00348520[][5];
void func_0013cbb8(u8* self, W317H* h, u8 a2);  // 0x0013cbb8: definition moved into src/anon/unit_0013a8b8.cpp

s32 func_00139d78(W317Obj*);
extern W317G* D_0035ed40;
static inline void w317upd(void* p) {
    W317Obj* o = (W317Obj*)p;
    if (func_00139d78(o)) o->vt->f20(o);
}
void func_00246f80(void);  // 0x00246f80: definition moved into src/anon/unit_00242478.cpp
}
