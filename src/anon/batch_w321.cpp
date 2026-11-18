#include "../common/types.h"

namespace w321 {
struct V16 { f32 x, y, z, w; };
struct E2 { u8 n; u8 cur; u16 f2; u16 f4; u16 f6; u8 pad[8]; V16 arr[1]; };
struct K8 { u16 f0; u16 f2; s8 f4; u8 f5; u16 f6; };
struct T1 { u8 p[6]; s16 f6; u8 p2[8]; K8 k[1]; };
struct A0 { u8 p[12]; s32 fc; u8 p2[141]; u8 f157; };
struct A1 { u8 p[4]; s32 f4; u16 f8; u8 p2[20]; u8 f30; u8 p3[4]; u8 f35; u8 p4[2]; u8 f38; };
struct A2 { u8 p[12]; s32* fc; };
struct G0 { u8 p[168]; u64 f168; };
struct G8 { u8 p[64]; V16 f64; };
struct G4e { T1* t; u32 pad; };
union U4 { T1* t; u8 c; };
struct G4b { u8 p[20]; U4* f20; };
struct G4 { u8 p[20]; G4e* f20; };
}
using namespace w321;

extern "C" {

extern s32 D_01d9ea9c;
extern G0* D_01d9e6e0;
extern G4b* D_01d9e6e4;
extern G8* D_01d9e6e8;
extern V16 D_01d9e6f0;
void sceVu0ApplyMatrix(V16*, V16*, V16*);
void sceVu0CopyVector(V16*, V16*);  // memcpy16
void func_002226b8(V16*, V16*);  // vec3_copy

void func_001f85b8(A0* a, A1* b, A2* c);  // 0x001f85b8: definition moved into src/anon/unit_001f7b40.cpp

void func_001f8dd0(A0* a, A1* b, A2* c);  // 0x001f8dd0: definition moved into src/anon/unit_001f8dd0.cpp


void func_001ff110(A0* a, A1* b, A2* c);  // 0x001ff110: definition moved into src/anon/unit_001ff110.cpp


}
