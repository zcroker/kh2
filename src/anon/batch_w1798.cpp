#include "../common/types.h"

struct Obj_19bc38 { u8 p0[0x108]; u32 f108; u8 p1[0x570 - 0x10c]; u8* p570; u8 p2[0x7f8 - 0x574]; u32 f7f8; };

extern "C" {
u32 get_type_19bc38(Obj_19bc38*) asm("_ZN2YS3OBJ8get_typeEv");
s32 each_coll_19bc38(Obj_19bc38*, s32, void*) asm("_ZN2YS3OBJ14each_collisionEiPKNS_14COLLISION_ELEME");
s32 battle_19bc38(void) asm("_ZN2YS6STATUS12IsBattleModeEv");
s32 attach_19bc38(Obj_19bc38*) asm("_ZN2YS3OBJ9is_attachEv");
extern u32 D_0034f240;

s32 func_0019bc38(Obj_19bc38* p);  // 0x0019bc38: definition moved into src/anon/unit_0019ba60.cpp
}
