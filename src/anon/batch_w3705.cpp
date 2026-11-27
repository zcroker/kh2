#include "../common/types.h"
extern "C" {

/* Table entry whose byte at +3 is read as a one-byte struct: the value stays in QImode, so the
 * 0xff test keeps its andi and the s8 conversions keep their sll/sra like the original. */
struct Ent27a6d8Byte { u8 v; };
struct Ent27a6d8 { u8 pad[3]; Ent27a6d8Byte v; u8 pad2[4]; };
struct Tbl27a6d8 { u8 pad[16]; Ent27a6d8 e[1]; };
extern s32 D_0035f01c;
extern Tbl27a6d8* D_0035f230;
s32 func_002570a0(s32);
void func_0027aed8(s32, s32*, s32*);
s32 func_0028b040(s32);
s32 Tz__CmNewFlg__isAbilityNewMember(s32, s32);
s32 func_0027ae78(s32);
s32 Tz__CmNewFlg__isAbilityNewForm(s32, s8);
void Tz__CmNewFlg__SetAbilityFlgMember(s32, s8);
void func_00287430(s32, s8);

void Tz__CmAbility__UpdateNew(void);  // 0x0027a6d8: definition moved into src/anon/unit_0027a6d8.cpp

}
