#include "../common/types.h"

struct NoTail_w256 { ~NoTail_w256() {} };
struct E27 { s8 a; u8 x; s8 b; u8 y; s8 c; u8 z[3]; };
struct T27 { u8 hdr[14]; E27 e[1]; };
struct I27 { u8 p[5]; u8 b5; u8 q[2]; };
struct H2d { u8 p[152]; s32 i152; };
struct R2d { u8 p[28]; f32 f28; };
struct C2d { u8 p[320]; u8 mo[1]; };
struct A2d { u8 p[320]; u8 mo[3056-320]; void* p3056; C2d* p3060; f32 f3064; u8 q[4]; f32 f3072; };
struct M256 { u8 pad[20]; s32 i20; s32 i24; u32 i28; };

extern "C" {
s32 func_0017ec98(M256*, s32);
s32 func_0017ebc8(M256*);
s32 func_0017f178(M256*, s32, f32, f32);
u32 mo_start_num_w256(M256*, s32) asm("_ZN2YS6MOTION9start_numEiff");
s32 mo_is_exist_w256(M256*, s32) asm("_ZN2YS6MOTION8is_existEi");
s32 mo_push_w256(M256*, s32, f32, f32, void*) asm("_ZN2YS6MOTION4pushEiffPFvPNS_3OBJEE");

// 0017f268: moved to src/yasui/libys/motion.cpp


extern u32 D_0035ee60, D_0035ee68, D_0035ee6c, D_0035ee7c, D_0035ee78, D_0035ee80;
extern u32 D_0035ee70, D_0035ee74, D_0035ee58, D_0035ee5c;
s32 call4_w256(u32) asm("_Z16u_call4_00139d78jjjj");
s32 iscreated_w256(u32) asm("_ZN2Tz6Select9isCreatedEz");

void func_00250fb8(void);  // 0x00250fb8: definition moved into src/anon/unit_00250fb8.cpp

extern T27* D_0035f230;
extern u32 D_0035f01c;
u32 getselpos_w256(s32) asm("_ZN2Tz5CmTop12GetSelectPosEi");
s32 getitemtbl_w256(s32) asm("_ZN2Tz9CmAbility10GetItemTblEi");
void func_0027aed8(u32, s32*, s32*);
s32 func_0027af58(void);  // check_state16_then_loop
I27* func_00273180(s32, s32);  // state_dispatch_2_3
void func_002891f0(u32, s32, s32, s32, s32);
void func_0027b248(s32);
void func_0027afe0(void);  // 0x0027afe0: definition moved into src/anon/unit_0027a6d8.cpp


extern H2d* D_00361f60;
void* getgopher_w256(H2d*) asm("_ZN2Ti12MGHachimitsu10get_gopherEv");
s32 isattach_w256(void*) asm("_ZN2YS3OBJ9is_attachEv");
void addcount_w256(s32, s32) asm("_ZN2YS7MISSION8AddCountEii");
R2d* fmat_w256(H2d*) asm("_ZN2kn7FMatrixaSERKS0_");
void f17f488_w256(void*, s32, f32, f32) asm("_Z13func_0017f488iiff");
void func_002db210(void*);
void func_002dbd30(void*, f32);
void func_002da120(A2d* a);  // 0x002da120: definition moved into src/anon/unit_002da040.cpp


void func_00239700(void*);
extern u8 D_00347f98[], D_00347e60[], D_0035e1b8[], D_0034a958[], D_0035e280[];
void func_0031a838(void*);
void func_0013ee88(void*);
void func_0014b668(void*);
void func_00322418(u8* t);  // 0x00322418: definition moved into src/anon/unit_00321728.cpp

}
