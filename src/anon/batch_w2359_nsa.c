#include "../common/types.h"

/* Plain C (partMng family), built with -fno-strict-aliasing.
   00203b48: partMng particle birth: clear the particle, pick a direction, an emit shape
   (point / sphere shell / box / model vertex) with a random radius curve, colours, angle, uv
   scroll, scale, fades and the owner-relative position. */
typedef struct Pr203b48 Pr203b48; typedef struct Pt203b48 Pt203b48; typedef struct Cf203b48 Cf203b48;
typedef struct Ob203b48 Ob203b48; typedef struct Wk203b48 Wk203b48; typedef struct Bk203b48 Bk203b48;
struct Pr203b48 {
    u8 pad0[34]; u16 h34; u8 b36, b37, b38, b39;
    f32 f40, f44, f48, f52; u8 pad56[72 - 56]; u8 b72, b73, b74, b75;
    f32 f76, f80, f84, f88, f92; u8 pad96[112 - 96]; f32 f112, f116; u8 pad120[124 - 120];
    f32 f124, f128, f132, f136, f140, f144, f148; u8 pad152[164 - 152]; f32 f164, f168, f172, f176, f180;
    f32 f184, f188, f192, f196; u8 b200, b201, b202, b203, b204, pad205[3]; s16 h208; u8 b210, b211, b212;
    u8 pad213[216 - 213]; f32 f216;
};
struct Pt203b48 {
    f32 pos[4]; f32 vel[4]; u8 pad32[38 - 32]; s16 h38; s8 b40, b41, b42, b43; u8 b44; u8 pad45; s16 h46; s16 h48; s16 h50;
    f32 f52, f56, f60, f64, f68, f72, f76, f80, f84, f88; u8 b92, b93, b94, b95;
};
struct Cf203b48 { f32 x, y, z, w, vx, vy, vz, vw; };
struct Ob203b48 { u8 pad0[98]; u16 h98; };
struct Wk203b48 { u8 pad0[16]; f32 v16[4]; u8 pad32[144 - 32]; s16* verts; };
typedef struct { u8 pad0[20]; s16* verts; u8 pad24[36 - 24]; } Md203b48;
typedef struct { s16 model; s16 count; u16* idx; } Vs203b48;
struct Bk203b48 { u8 pad0[16]; Md203b48* models; u8 pad20[4]; Vs203b48* sets; };
typedef struct { s16 x, y, z; } Vx203b48;
extern Wk203b48* D_01d9e6e8;
extern Bk203b48* D_01d9e6e4;
f32 func_00203a40(void);
s8 func_00203a88(u8);
void func_001e7188(void*, s32, s32);
void sceVu0UnitMatrix(f32*);
void sceVu0RotMatrix(f32*, f32*, f32*);
void sceVu0ApplyMatrix(f32*, f32*, f32*);
void sceVu0Normalize(f32*, f32*);
void func_002f4870(f32, f32*, f32*);
void sceVu0CopyMatrix(f32*, f32*);
void sceVu0MulMatrix(f32*, f32*, f32*);
double func_00313b80(f32);
double __subdf3(double, double);
f32 __truncdfsf2(double);

void func_00203b48(void* e, Ob203b48* ob, Pr203b48* p, u8* col, Pt203b48* pt, f32* base, Cf203b48* cf);  // 0x00203b48: definition moved into src/anon/unit_00203b48.c
