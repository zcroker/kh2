#include "../common/types.h"

// 0031a850: assignment operator of a 0x158-byte object (base part via its own operator=,
// then the derived members). The 13 words at 0xb8 are copied through raw word pointers,
// which keeps their loads/stores in order (the two fields on each side are not).
struct Obj31a850Base {
    u8 base[0xb0];
};
struct Obj31a850 : Obj31a850Base {
    s32 mb0;
    s32 mb4;
    s32 work[13];
    s32 mec;
    s32 mf0;
    s32 mf4;
    s32 mf8;
    s32 mfc;
    f32 m100;
    f32 m104;
    f32 m108;
    s32 m10c;
    s32 m110;
    s32 m114;
    f32 m118;
    f32 m11c;
    f32 m120;
    f32 m124;
    f32 m128;
    f32 m12c;
    f32 m130;
    f32 m134;
    f32 m138;
    f32 m13c;
    s32 m140;
    s32 m144;
    s32 m148;
    s32 m14c;
    s32 m150;
    s32 m154;
};

extern "C" {
void func_0031a9d8(Obj31a850*, Obj31a850*);

Obj31a850* func_0031a850(Obj31a850* d, Obj31a850* s);  // 0x0031a850: definition moved into src/anon/unit_003197d0.cpp
}
