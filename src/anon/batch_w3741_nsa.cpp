// 002bbf98: walks the active list, moves state-4 nodes to a kill list, then unlinks them and returns them to the pool.
#include "../common/types.h"
extern "C" {
struct LNode { u8 pad[0x1c]; LNode* next; LNode* next2; u8 pad24[0xc]; u8 state; u8 pad31[0xf]; };
struct LList { LNode* head; LNode* tail; };
struct LPool { LNode nodes[64]; s32 free[64]; s32 count; };
extern LList D_01e2aa80;
extern LList D_01e2aa88;
extern LPool D_01e2aa90;
extern s32 D_003616f4;
void func_002bbd58(LNode*);
static inline LNode* nextA(LNode* n) { return !n ? D_01e2aa80.head : n->next; }
static inline LNode* nextB(LNode* n) { return !n ? D_01e2aa88.head : n->next2; }



void func_002bbf98(void);  // 0x002bbf98: definition moved into src/anon/unit_002bb8b0.cpp
}
