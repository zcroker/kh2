#include "../common/types.h"
struct Ent283 { u8 p[6]; u8 idx; u8 p7; };
extern "C" {
s32 u_call4_00139d78_283(u8*) asm("_Z16u_call4_00139d78jjjj");
void func_0028d980(u8*, s32, s32, s32, s32, s32, s32, s32, s32);
void getXY_283(u8*) asm("_ZN2dk5Obj2D17getSeqPraramXYOffEv");
void resetA_283(u8*) asm("_ZN2dk5Obj2D17resetSeqAlphaOnlyEv");
u32 u_tail4_00192048_283(u32) asm("_Z16u_tail4_00192048jjjj");
s32 msgcopy_283(u32, s8*) asm("_ZNK2YS7MESSAGE4copyEPc");
void func_00192cc0(s8*, const char*, s32, s32);
extern u8* D_0035f2b8;
extern s8* D_0035f2b4;
extern s32 D_0035ef68;
extern s32 D_0035ef64;
extern s32 D_0035f03c;
extern char D_00374250[];
extern Ent283 D_003742c8[];
extern u16 D_00374318[];
void func_002833f8(void) {
    if (!u_call4_00139d78_283(D_0035f2b8 + 852)) {
        func_0028d980(D_0035f2b8 + 852, 30022, D_0035ef68, D_0035ef64, D_0035f03c, 18, 19, -1, 0);
        *(s8**)(D_0035f2b8 + 1260) = D_0035f2b4 + 15;
        getXY_283(D_0035f2b8 + 852);
        resetA_283(D_0035f2b8 + 852);
        *(s32*)(D_0035f2b8 + 1284) = 2;
    }
    s8* s = D_0035f2b4 + 15;
    s += msgcopy_283(u_tail4_00192048_283(0xcbd8), s);
    func_00192cc0(s, D_00374250, D_0035f2b4[14] + 1, D_0035f2b4[13]);
    if (!u_call4_00139d78_283(D_0035f2b8 + 416)) {
        func_0028d980(D_0035f2b8 + 416, 30022, D_0035ef68, D_0035ef64, D_0035f03c, 15, 16, -1, 0);
        getXY_283(D_0035f2b8 + 416);
        resetA_283(D_0035f2b8 + 416);
        *(s32*)(D_0035f2b8 + 848) = 2;
    }
    u8* o = D_0035f2b8 + 416;
    *(u32*)(o + 408) = u_tail4_00192048_283(D_00374318[D_003742c8[D_0035f2b4[D_0035f2b4[14] + 4]].idx]);
}
}
