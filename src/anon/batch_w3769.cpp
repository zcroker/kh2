#include "../common/types.h"
struct Nd2Sub { u8 pad[0x7f8]; u32 flags; };
struct Nd2 {
    u8 pad0[0x570];
    Nd2Sub* sub;
    u8 pad1[0x800 - 0x574];
    s32 dead;
    u8 pad2[0x8b8 - 0x804];
    Nd2* next;
};
struct Nd2List { Nd2* head; Nd2* tail; };
extern "C" {
struct Slot { s32 id; s32 st; s32 c; s32 d; };
extern u8 D_0035ef58;
extern u32 D_0035eec0[];
extern Slot D_0035eee0[];
extern s32 D_0035ef54;
u8* func_00253b30(u8*, u32);
void func_002ff2e8(u8*);
s32 func_00253b00();
void func_00253978(void*);
void func_002539d0(void*);
void YS__FILE__ReadBarBack(u8*, s32, void (*)(void*), Slot*);
void YS__FILE__ReadBack(u8*, s32, void (*)(void*), Slot*);

// Starts slot idx's request (idx 6 fills buf itself): records a ticket, sets state 2 and
// queues it with a completion callback.
// key is pinned to s2 (both buffer results share it); the empty asm keeps a label at the
// start of the non-6 arm, so the first beq's delay slot is filled from its target as in the original.
s32 Tz__CMData__BackRead(s32 idx0, u32 key0);  // 0x002539e8: definition moved into src/anon/unit_002530c8.cpp

extern Nd2List D_01d48db0;
void func_001b9b28(Nd2*);
s32 func_001c0cd8(Nd2*);
void func_00320468(Nd2List*, Nd2*);

// Unlinks every node flagged dead, then repeatedly sweeps the list, releasing nodes that
// func_001c0cd8 rejects or whose 0x100 flag is set, until the list is empty.
// Pins: p in s1 and h in t7 give the original's register rotation; hb is the list's high
// half held in s5 before the sweep loop's entry test, as the original hoists it.
void func_001b99d0(void);  // 0x001b99d0: definition moved into src/anon/unit_001b9880.cpp
}
