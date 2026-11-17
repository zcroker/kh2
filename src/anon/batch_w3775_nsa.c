// Built with -fno-strict-aliasing (_nsa).
// 001e8048: set up an object from a data header (cursor reads, entry table from a linked list).
// Partial asm: an empty tie on the header cursor p keeps it live with an addiu after each read; e pinned to t3.
#include "../common/types.h"
typedef struct Node Node; struct Node { Node* next; u32 pad[3]; s32 v10; };
typedef struct Ent Ent; struct Ent { Node* n; s32 w4; s32 v8; u16 h12; u8 b14; u8 pad; };
typedef struct Obj Obj; struct Obj {
    u8 pad0[0x54]; s32 w54; s32 w58;
    u8 pad1[0x64 - 0x5c]; s32 w64; s32 n68; s32 pad6c; Node* list70; s32 w74; s32* p78; s32* p7c; Ent* ents;
    u8 b84; u8 b85;
    u8 pad2[0x98 - 0x86]; s32 w98;
};
extern Obj* D_01d9e6e0;
extern s32 D_01d9e6e4;
Ent* func_001e7698(s32, s32);
void func_001e7810(Obj*);

void func_001e8048(Obj* o, s32* d, s32 go);  // 0x001e8048: definition moved into src/anon/unit_001e0cb8.cpp




