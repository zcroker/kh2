#include "../common/types.h"

/* ---- YS__MESSAGE__GetFilename: formats a name string into the shared buffer D_01c61ab8 ---- */
char* func_00105ee8(void);
s32 func_002fee78(char*, const char*, ...);
extern char D_01c61ab8[];
extern char D_0036cd78[];
extern char D_0036cd80[];
extern char D_0036cd88[];
extern char D_0036cd98[];
extern s32 D_0033caf4;
static inline const char* nm(s32 a) {
    switch (a) {
    case 101: return D_0036cd78;
    case 100: return D_0036cd80;
    case 102: return D_0036cd98;
    }
    return func_00105ee8();
}
/* the $7 pin puts "move a3,v0" before the jal and "addiu a1" into its delay slot, as the original does */
// 001921d8: moved to src/yasui/libys/message.cpp

/* ---- Tz__JmPuzzle__DrawMess ---- */


u8 *func_002766d0(void);
s32 func_0028b040(s32);
extern s32 D_0035f200;
extern u8 *D_0035f224;
extern u8 *D_0035f638;
void func_0014b950(u8 *, s16, s16, u16, u16);
void func_0014b9a8(u8 *);
s32 func_0023aa58(u8 *);
s32 func_0023aa78(u8 *);
u8 *func_001aae68(s32);
s32 func_00192048(s32);
void YS__MESSAGEDRAW__MESSAGEDRAW(void *, s32, s32, s32, s32);
void YS__MESSAGEDRAW__set_line_space(void *, s32);
void YS__MESSAGEDRAW__draw(void *, s32, s32, s32);
void Tz__JmPuzzle__DrawMess(s32 a0, s32 a1, s32 a2);  // 0x002b31c0: definition moved into src/anon/unit_002b2a18.cpp
