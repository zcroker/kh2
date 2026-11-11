#include "../common/types.h"
extern "C" {

/* 0010cbc8 */
void YS_TARGET_set_obj(void* t, void* o, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
void* YS_ITEM_GetCommandElem(s32) asm("_ZN2YS4ITEM14GetCommandElemEi");
void func_00176dd8(void*, void*, void*, s32);
void func_0010cbc8(u8* p, s32 item, void* obj, s32 d) {
    void* t = p + 0x9f4;
    if (obj == 0) return;
    *(s32*)(p + 0xb78) = 0;
    if (*(void**)(p + 0x9f4) != obj) YS_TARGET_set_obj(t, obj, 0);
    func_00176dd8(p, YS_ITEM_GetCommandElem(item), t, d);
}

/* 00187e58 */
struct W1773Tgt { u8 pad[0x154]; s32 kind; u8 pad2[0x588 - 0x158]; u32 flags; };
struct W1773Link { u32 x0; W1773Tgt* t; };
struct W1773Obj { u8 pad[0x88]; W1773Link* l; u8 pad2[0x9c - 0x8c]; u32 off : 1; u32 rest : 31; };
s32 ctarget_00186ce8(W1773Tgt*) asm("_Z16ctarget_00186ce8jjjj");
s32 func_00186d18(W1773Tgt*);
// 00187e58: moved to src/anon/unit_00185d10.cpp
s32 func_00187e58(W1773Obj* a);

}
