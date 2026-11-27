#include "../common/types.h"

// 16-byte vector; assignment copies with a 128-bit lq/sq.
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));


extern "C" {
extern u8 D_0034af40[];
struct G { u8 p0[276]; u32 f114; u8 p1[48]; u32 f148; u32 f14c; };
extern G D_0034b0e0;
void func_00236788(void*);  // to_236830
u32 func_00239d30(void*, u32);
s32 func_00239d10(void*);
u32 func_0014aba8();
void func_0014aa58(u32, s32, s32);
void func_0013f020();
void func_0023acd8(void*);
void YI__SEQUENCE__Draw(void*);
s32 dk__KeyHoleJumpEffect__jumpEffectOut_task();  // 0x0015d440: definition moved into src/anon/unit_0015d440a.cpp

extern u8* D_00347d64;
void func_00192c90(u32, void*);
void func_00192b30(u32);
void dk__TREASURE_INFO__openPrizeInfo(u32 a);  // 0x00138210: definition moved into src/anon/unit_001374c8.cpp

extern f32 D_00349e14;
s32 func_00197920(void*);
void func_00138c10(void*, s32);
void dk__SpriteMessage__update(void*);
struct V15ae { u8 p[20]; void (*f5)(void*); };
void dk__BILLBOARD_DISABLE_REASON__update(u8* a);  // 0x0015ae00: definition moved into src/anon/unit_0015a810.cpp

extern u32 D_003638d0;
s64 func_00312db8(u64, u64);
void func_001e26b8(u8* a, Vq* src);  // 0x001e26b8: definition moved into src/anon/unit_001e0cb8.cpp

extern u8 D_00347f98[];
extern u8 D_0035eb98[];
extern u32* D_0035eea4;
extern s16* D_0035ee9c;
void func_002529a8();
u32* func_0023ee30(u32);
void func_0031a838(u32*);
void YI__IMAGE_FREEZE__IMAGE_FREEZE(u32*);  // obj_ctor_36eac8
void YI__LAYOUT__LAYOUT(u32*);  // obj_ctor_36eae8
void Tz__MenuUtil__CreateLay(u32*, s32, s32, s32, s32, s32, s32, s32, s32);
void Tz__Layout__SetImageCache(u32*);
void Tz__ALCA__ChgMode();
void Tz__ALCA__PauseThread();  // 0x00252900: definition moved into src/anon/unit_00250fb8.cpp

extern u32 D_00367920;
extern u8 D_01e4c798[];
extern s32 D_01e4c7a0;
u32* func_00316e00();  // get_367918
u32* func_00316e10();  // get_data_369928
s32 func_003060f0();  // ee_intr_disabled
s32 func_00305510();
u32 __cxa_get_globals_fast();  // 0x00316a50: definition moved into src/libsupc++/eh_globals.cpp
}
