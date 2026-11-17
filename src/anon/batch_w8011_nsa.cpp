#include "../common/types.h"
extern "C" {
struct Ent12 { s8 id; s8 pad[11]; };
struct Tbl { s32 a; s32 b; s32 count; s32 c; Ent12 e[1]; };
struct IdList { s32 count; s16 ids[1]; };
extern IdList* D_0035f598;
void func_002fde18(void*, s32, s32);
Tbl* func_00294000(s32);
s8* func_00276568();
s32 func_00294348(Ent12*);
s32 func_00276c18();
void func_002982f0();  // 0x002982f0: definition moved into src/anon/unit_002982f0.cpp
}
