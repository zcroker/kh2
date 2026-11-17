#include "../common/types.h"

extern "C" {

// 2D sprite keyframe animation (func_0023ade0 draws one animated sprite).
// One keyframe of the track (0x90 bytes).
struct SprKey {
    u32 flags;        // 0x00
    s32 image;        // 0x04
    s32 start;        // 0x08 first frame
    s32 end;          // 0x0c last frame
    s32 x[2];         // 0x10
    s32 y[2];         // 0x18
    s32 u[2];         // 0x20
    s32 v[2];         // 0x28
    f32 pos[3][2];    // 0x30 (x0,x1,y0,y1,z0,z1)
    f32 scale[3][2];  // 0x48
    f32 ease[2][2];   // 0x60
    f32 amp[2][2];    // 0x70 wobble amplitude x, y
    u16 freq[2];      // 0x80 wobble frequency x, y
    s32 blend;        // 0x84
    u8 rgba[2][4];    // 0x88
};

struct SprAnim;
typedef void (*SprAnimCb)(SprAnim*, s32);

struct SprAnim {
    u8 pad00[0x10];
    union { u32 state; f32 stateF; };        // 0x10
    u8 pad14[0x40 - 0x14];
    void* image;      // 0x40
    u8 pad44[0x68 - 0x44];
    s32 imageNo;      // 0x68
    u8 pad6c[0x88 - 0x6c];
    u32 color;        // 0x88
    u8 pad8c[0xb8 - 0x8c];
    s32 mode;         // 0xb8
    u8 padbc[0xc4 - 0xbc];
    SprKey* keys;     // 0xc4
    s32 nkeys;        // 0xc8
    f32 time;         // 0xcc
    u32 baseColor;    // 0xd0
    u8 padd4[0xf0 - 0xd4];
    SprAnimCb cb;     // 0xf0
    u8 padf4[0xfc - 0xf4];
    s32 visible;      // 0xfc
    u8 pad100[0x110 - 0x100];
    s32 cbCount;      // 0x110
    u8 pad114[0x118 - 0x114];
    f32 colorMul[4];  // 0x118 r,g,b,a
    f32 ofs[3];       // 0x128
    f32 scl[3];       // 0x134
    u8 pad140[0x148 - 0x140];
    s32 px;           // 0x148
    s32 py;           // 0x14c
};

void YI_IMAGE_LoadImage(void*) asm("_ZN2YI5IMAGE9LoadImageEv");
u32 func_002f35e8(s32);
void func_002f3918(u32, void*);
void func_002376d8(SprAnim*, s32);
void func_00237740(SprAnim*, f32, f32, f32);
void func_00237a68(SprAnim*, f32, f32, f32);
void func_00238570(SprAnim*, s32, s32, s32, s32);
void func_00238c90(SprAnim*, s32, s32, s32, s32);
f32 sinf(f32);
f32 cosf(f32);
u32 __fixunssfsi(f32) __attribute__((const)); // __fixunssfsi (float -> u32)

extern u8 D_0035e3c0[];
extern u8 D_01dae590[][0x30];
extern u8 D_01dae5f0[][0x30];

#define ILERP(a, b, t) ((a) + (s32)((f32)((b) - (a)) * (t)))
#define FLERP(a, b, t) ((a) + ((b) - (a)) * (t))

void func_0023ade0(SprAnim* o);  // 0x0023ade0: definition moved into src/anon/unit_00239988.cpp

}
