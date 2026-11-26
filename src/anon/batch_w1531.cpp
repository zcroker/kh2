#include "../common/types.h"

struct W1531_TT { u8 pad[0x28]; W1531_TT* next; };
struct W1531_TL { W1531_TT* head; s32 count; };
struct W1531_Tab { s32 x; s32 count; s32 tab[1]; };
struct W1531_Ob { u8 pad[0x7f8]; s32 flags; };
struct W1531_E32 { u8 b[32]; };
struct W1531_Lst { s32 n; W1531_Ob* o; s32 k; s32 pad; W1531_E32 arr[1]; };

extern "C" {
extern W1531_TL D_004f6290;
void func_0016cab8(W1531_TT*);
void func_0016c7d8(W1531_TT*);

// 0016d110: moved to src/anon/unit_0016c770.cpp

extern W1531_Tab* D_01d48cb4;
s32 func_001b7818(void*);
u8* YS__LEVELUP__Get(void* self, s32 a);  // 0x001b6fb0: definition moved into src/anon/unit_001b6a50.cpp

s32 func_0016bba8(W1531_Ob*, s32, s32);
void YS__COLLISION__set(W1531_E32*, W1531_Ob*, s32);
void func_001b78d0(W1531_Lst* l);  // 0x001b78d0: definition moved into src/anon/unit_001b6a50.cpp
}
