#include "../common/types.h"
u8* w1967_GetListBuffer(void) asm("_ZN2Tz5CmTop13GetListBufferEv");
s32 w1967_call4(void*) asm("_Z16u_call4_00139d78jjjj");
void w1967_CreateFade(void*, s32, s32, s32, s32, s32, s32, s32) asm("_ZN2Tz5Pause16CreateFadeObjectEz");
void w1967_CurCreate(void*, s32, s32, s32, s32, s32, s32, s32, s32) asm("_ZN2Tz10MenuCursor6CreateEz");
s32 w1967_GetParamEx(void*) asm("_ZN2YI8SEQUENCE10GetParamExEv");
s32 w1967_GetParamCr(void*) asm("_ZN2YI8SEQUENCE10GetParamCrEv");
s32 w1967_GetParamX(void*) asm("_ZN2YI8SEQUENCE9GetParamXEv");
s32 w1967_GetParamY(void*) asm("_ZN2YI8SEQUENCE9GetParamYEv");
void w1967_setNum(void*, s32) asm("_ZN2dk6Sprite6setNumEi");
void w1967_Attach(void*, void*) asm("_ZN2Tz10MenuCursor12AttachSpriteEz");
void w1967_getParentSeqAlpha(void*) asm("_ZN2dk5Obj2D21getParentSeqAlphaOnlyEv");
void w1967_getSeqXYOff(void*) asm("_ZN2dk5Obj2D17getSeqPraramXYOffEv");
void w1967_resetSeqAlpha(void*) asm("_ZN2dk5Obj2D17resetSeqAlphaOnlyEv");
s32 w1967_GetFontColor(s32) asm("_ZN2Tz5CmTop18GetFontColorSeqNumEi");
void w1967_setOffsetPos(void*, s32, s32) asm("_ZN2dk6Sprite12setOffsetPosEii");
extern s32 D_0035ef64;
extern s32 D_0035ef68;
extern s32 D_0035ef6c;
extern s32 D_0035f03c;
extern s32 D_0035f0e4;
extern s16 D_00373500;

void func_002653a0(void) {
    u8* base = w1967_GetListBuffer();
    s32 i;
    s16 c;
    u8* p;
    w1967_call4(base);
    w1967_CreateFade(base, 30013, D_0035ef68, D_0035ef64, D_0035f03c, 140, 141, 0);
    c = D_00373500;
    p = base;
    for (i = 0; i < 20; i++, p += 436) {
        s32 x, y;
        w1967_CurCreate(p + 13840, 30014, D_0035ef68, D_0035ef64, D_0035f03c, c, -1, -1, 0);
        w1967_GetParamEx(p + 13864);
        w1967_GetParamCr(p + 13864);
        x = w1967_GetParamX(p + 13864);
        y = w1967_GetParamY(p + 13864);
        w1967_setNum(p + 13840, D_0035ef6c);
        w1967_Attach(p + 13840, base);
        w1967_getParentSeqAlpha(p + 13840);
        w1967_getSeqXYOff(p + 13840);
        w1967_resetSeqAlpha(p + 13840);
        w1967_CurCreate(p + 24304, 30015, D_0035ef68, D_0035ef64, D_0035f03c, w1967_GetFontColor(2), -1, -1, 0);
        w1967_Attach(p + 24304, p + 13840);
        w1967_getSeqXYOff(p + 24304);
        w1967_resetSeqAlpha(p + 24304);
        *(s32*)(p + 24736) = 1;
        w1967_setOffsetPos(p + 24304, x, y);
        *(s32*)(p + 24712) = D_0035f0e4 + i * 32 + 1316;
    }
}

