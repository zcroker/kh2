#include "../common/types.h"

struct W1746CallArg { void* obj; u32 v4; void* tbl; f32 f; void* sub; };
struct W1746Node { u8 pad[28]; W1746Node* next; u32 pad2; u32 flags; u8 pad3[9]; u8 type; };

extern "C" {
extern u8 D_01d9e8c0[];
extern W1746Node* D_01e2aa80;
void func_0021fa28(W1746CallArg*, s32);

void func_001fb508(u8* o);  // 0x001fb508: definition moved into src/anon/unit_001fb350.cpp

static inline W1746Node* w1746_next(W1746Node* p) {
    if (!p) return D_01e2aa80;
    return p->next;
}

void SOUND__silentBgSeOff(void);  // 0x002bbf18: definition moved into src/anon/unit_002bb8b0.cpp
}
