#include "../common/types.h"

struct Pair {
    u32 a, b;
};
struct Vec3u {
    u32 x, y, z;
};

extern "C" {

void func_0011ee98(void*, void*);
void* func_00140df0(void);
void func_00139858(s32);
void func_00139ab0(s32);
void* func_00102c80(void);
void func_00102688(u32, u32, u32);
void func_00183768(u32, u32, f32);  // copy_quad_at16_and_len
void func_001b1be0(u32, f32);
void func_001cc9c8(u32, f32);
void func_00153e28(u32, f32, f32);
void func_001a6490(u32, f32);
u32 YS__DATABUFF__Read(u32);
void func_002bea60(void);
void func_0021fbc0(void*);
void func_00220070(void*);
void* func_00257770(void);
void func_0028da70(void*, s32);
void* func_002766d0(void);
u8 func_00139d78(void*);
void AREA__MapJump(u32, u32, u32, u32, u32);
void func_002e9cb8(u32, u32, u32);
void Ts__TARGET_SEARCHER__add(u32, u32, u32);
void func_003053e0(void);

extern u32 D_00347ce0;
extern u32 D_0034aa08;
extern u32 D_004f3800;
extern u32 D_004f6288;
extern Pair D_004f6290;
extern u32 D_00350330;
extern u32 D_01c61b00;
extern Pair D_01c6cba0;
extern u32* D_01d49320;
extern s32 D_00351604;
extern s32 D_00351608;
extern s32 D_01dad910[2];
extern s32 D_003617d8;
extern s32 D_003617dc;

// 00101d38: crtend.o call stub (its jal is in .init), now in src/libgcc/crtend.c

struct Obj0011eef8 {
    u32 pad[2];
    u32 f8;
    u32 fc;
    u32 f10;
    void* f14;
};
void func_0011eef8(void* a, Obj0011eef8* b);  // 0x0011eef8: definition moved into src/anon/unit_0011c128.cpp

// Quadword copy from p+0x50 into dst (unless they alias).
// 00107368: moved to src/naka/libkn/camera.cpp

// 00135670: moved to src/anon/unit_00134668.cpp

// Quadword copy of src into p+0x1a0.
void func_001391a8(u8* p, void* src);  // 0x001391a8: definition moved into src/anon/unit_00138480.cpp

// 00159700: moved to src/anon/unit_00159240.cpp

void dk__Exp__on(void);  // 0x0015b780: definition moved into src/anon/unit_0015b100.cpp

// 0015cea0: moved to src/anon/unit_0015cdb0.cpp

void func_001623b0(void);  // 0x001623b0: definition moved into src/anon/unit_001614e8.cpp

void func_0016c750(u32 a);  // 0x0016c750: definition moved into src/anon/unit_00169f98.cpp

struct Obj00174168 {
    u32 x;
    u32 m;
};
struct Args00174168 {
    Obj00174168* o;
    u32 a;
    f32 f;
};
void func_00174168(Args00174168* p);  // 0x00174168: definition moved into src/anon/unit_00171e58.cpp

struct ArgsUF {
    u32 a;
    f32 f;
};
void func_00174b88(ArgsUF* p);  // 0x00174b88: definition moved into src/anon/unit_00171e58.cpp

void func_001752e0(u32* p);  // 0x001752e0: definition moved into src/anon/unit_00171e58.cpp

void func_00175480(u32* p);  // 0x00175480: definition moved into src/anon/unit_00171e58.cpp

// 00185a98: moved to src/anon/unit_001855e0.cpp

void func_0018fcc0(ArgsUF* p);  // 0x0018fcc0: definition moved into src/anon/unit_0018f140.cpp

void func_00196170(void);  // 0x00196170: definition moved into src/anon/unit_00195d00.cpp

// Virtual call: o->vfunc[9](a, 0).
void func_0019fd88(void** o, u32 a);  // 0x0019fd88: definition moved into src/anon/unit_0019fb70.cpp

// 001a8498: moved to src/anon/unit_001a82f0.cpp

// 001bbb08: moved to src/yasui/libys/mission.cpp

s32 func_001c4170(void);  // 0x001c4170: definition moved into src/anon/unit_001c4120.cpp

void func_001d71f0(s32 a);  // 0x001d71f0: definition moved into src/anon/unit_001d68e0.cpp

void func_001efc28(u8* p, u8* q);  // 0x001efc28: definition moved into src/anon/unit_001ef780.cpp

void func_001fa928(u8* p, u8* q);  // 0x001fa928: definition moved into src/anon/unit_001fa1b8.cpp

void func_001fbc78(u8* p, u8* q);  // 0x001fbc78: definition moved into src/anon/unit_001fb350.cpp

// d.xyz = a.xyz - b.xyz (VU0 macro mode).
void func_00222730(void* d, void* a, void* b);  // 0x00222730: definition moved into src/anon/unit_00222548.cpp

void func_00225298(void);  // 0x00225298: definition moved into src/anon/unit_00224780.cpp

void func_00265c50(void);  // 0x00265c50: definition moved into src/anon/unit_00265580.cpp

u32 func_0029e0d0(void);  // 0x0029e0d0: definition moved into src/anon/unit_0029d008.cpp

// Stores the new value and reports whether it was unchanged.
u32 func_002bd230(s32 a, s32 b);  // 0x002bd230: definition moved into src/anon/unit_002bc978.cpp

void func_002c5460(u32 a);  // 0x002c5460: definition moved into src/anon/unit_002c53c8.cpp

f32* func_002d5c20(f32* v);  // 0x002d5c20: definition moved into src/anon/unit_002d4548.cpp

struct Args002e8070 {
    u32 a, b, c;
};
void func_002e8070(Args002e8070* p);  // 0x002e8070: definition moved into src/anon/unit_002e7b10.cpp

void func_002e9c98(u32 x, Pair* p);  // 002e9c98: moved to src/anon/unit_002e9a00.cpp

// Dot product of a.xyz and b.xyz (VU0 macro mode).
f32 sceVu0InnerProduct(void* a, void* b);  // 0x002f3d70: definition moved into src/sdk/libvu0_002f3cd8.s

// d = a * s (VU0 macro mode).
void sceVu0ScaleVector(void* d, void* a, f32 s);  // 0x002f3f40: definition moved into src/sdk/libvu0_002f3cd8.s

// Library code: the original compiler allocated v0 for the temporary.
s32 func_00305dd8(u32 a, u8* p);  // 0x00305dd8: definition moved into src/sdk/glue.c

void iEnableDmac(void);  // 0x003062e0: definition moved into src/sdk/libkernl_00306058.c

void Tz__Select__SetSelectMax(u8* p, s32 a);  // 0x0028af90: definition moved into src/anon/unit_00288b00.cpp

// Tests bit `bit` of the mask at +0x20.
u32 func_0028b1c0(u8* p, s32 bit);  // 0x0028b1c0: definition moved into src/anon/unit_00288b00.cpp

}  // extern "C"

namespace dk {
class SpriteMessage {
public:
    void draw();
};
class Fade {
public:
    void fadeOut(u32 a0, bool a1);
    u8 pad[244];
    bool f_f4;
    u8 pad2[7];
    s32 f_fc;
};
}  // namespace dk

extern "C" void dk__Sprite__draw(dk::SpriteMessage*);
extern "C" void dk__SpriteMessage__drawMessage(dk::SpriteMessage*);
extern "C" void func_0014a9a0(dk::Fade*, u32);

// 0x001390c0: dk::SpriteMessage::draw moved into src/anon/unit_00138480.cpp

// 0x0014aa58 dk::Fade::fadeOut: definition moved into src/harata/libdk/fade.cpp

extern "C" void func_001da458(void*, u32);  // stream_init_fields
extern "C" void func_0016ce90(void*, u32);
// 0016cba0: moved to src/anon/unit_0016c770.cpp

namespace YS {
class SELECTOR {
public:
    class ARGS;
};
}  // namespace YS
namespace Tz {
class CampMenu {
public:
    void RestartSelector(const YS::SELECTOR*, const YS::SELECTOR::ARGS*);
};
}  // namespace Tz
extern "C" void func_00258b00(void);
extern "C" void func_00258af0(s32);

// 0x00253480: definition moved into src/anon/unit_002530c8.cpp
