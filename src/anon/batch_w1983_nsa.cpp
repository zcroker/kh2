#include "../common/types.h"

struct V4_w1983 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct Sub_w1983 { f32 f0; char* p4; };
struct Tbl_w1983 { s32 o0; s32 o4; s32 o8; };
struct A0_w1983 { char pad[0xc]; s32 id; char pad2[0x9d - 0x10]; u8 b9d; };
struct A1_w1983 { s32 id; f32 f4; s32 idx; s32 off; };
struct A2_w1983 { char pad[0xc]; Tbl_w1983* t; };
struct Ent_w1983 { s32 a; char* p; s32 c, d; };
struct G_w1983 { char pad[0x80]; Ent_w1983* e; char pad2[0xa8 - 0x84]; u64 fl; };

struct H_w1983 { char p[0x8064]; s32 h; char p2[0x8074 - 0x8068]; s32 v74; char p3[0x8090 - 0x8078]; u8 b90; };
struct O_w1983 {
    char p0[0x58]; u8 b58; char p1[0x88 - 0x59]; s32 v88; s32 v8c; s32 arr[17]; f32 fd4; f32 fd8;
};
struct Q_w1983 { char p[0x8c]; s32 v8c; };

extern "C" {
s32 func_00222568(void);
void func_002226b8(void*, void*);
f32 func_002229a0(void*);
void sceVu0Normalize(void*, void*);
void sceVu0InterVector(void*, void*, void*, f32);
void sceVu0AddVector(void*, void*, void*);
void sceVu0SubVector(void*, void*, void*);
void sceVu0ScaleVector(void*, void*, f32);
void sceVu0CopyVector(void*, void*);
extern char D_01d9e360[];
extern G_w1983* D_01d9e6e0;
extern s32 D_01d9ea9c;

Q_w1983* func_002dc7c8(void*);
s32 func_002ceb28(void);
s32 func_00197920(void);
s32 func_002e33d8(s32, s32, s32);
s32 func_002e33f8(s32, s32, s32);
s32 func_002e3318(s32, s32*, s32, s32, s32, s32);
void func_002cf938(s32);
void func_002cfb30(void);
extern f32 D_00349e10;

void func_001fbd78(A0_w1983* a0, A1_w1983* a1, A2_w1983* a2);  // 0x001fbd78: definition moved into src/anon/unit_001fb350.cpp
}

#define HH_w1983(o) ((H_w1983*)(o))
void func_002dcc90(int arg);  // 0x002dcc90: definition moved into src/anon/unit_002da040.cpp
