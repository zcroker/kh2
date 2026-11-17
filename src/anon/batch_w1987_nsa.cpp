#include "../common/types.h"

// ---- 0023c100 Tz::MenuBasic::SetMesRes: rebuild the message-resource item array (delete[] of a 344-byte class, new[] written out)
struct Elem1987;
extern "C" {
void* znaj1987(u32, u32) asm("_Znaj");
s32 getimg1987(s32, s32) asm("_ZN2YI12IMAGE_FREEZE8GetImageEi");
void func_00239700(Elem1987*);
void func_00239988(Elem1987*, u8*, s32);
}
struct Elem1987 { virtual ~Elem1987(); u8 pad[340]; };
extern "C" {
struct Res1987 { u8 pad[8]; s32 o8; s32 oc; s32 o10; s32 o14; s32 o18; s32 o1c; };
struct MB1987 {
    u32 f0; u32 heap; u8* res; s32 fc; u8* p10; u8* p14; s32* offs; s32 f1c; s32 f20; s32 n;
    s32 img; Elem1987* arr; Elem1987* arr2; s32 f34; s32 f38; s32 f3c; u8 pad40[8]; f32 f48;
};
void f23c598_1987(MB1987*) asm("_Z13func_0023c598Pv");
void setoff1987(MB1987*, s32, s32) asm("_ZN2YI6LAYOUT9SetOffsetEii");
void func_0023c6f8(MB1987*, s32);
s32 v1(MB1987* self, u8* res, s32 img, u32 heap) asm("_ZN2Tz9MenuBasic9SetMesResEz");
s32 v1(MB1987* self, u8* res, s32 img, u32 heap);  // 0x0023c100: definition moved into src/anon/unit_0023bc58.cpp
}
