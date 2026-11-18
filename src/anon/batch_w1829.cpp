#include "../common/types.h"
extern "C" {
struct W1829Ent { u8 pad[0x1c4]; void* m4; s32 a2; s32 a1; s32 a5; s32 a6; u8 m1[64]; u8 m2[64]; };
struct W1829R { s32 head; s32 tail; W1829Ent e[16]; };
struct W1829Q { u8 pad[12]; W1829R r; };
void func_00192c90(void*, void*);
void func_00192b30(void*);

/* 0031cc30: push an entry onto a 16-slot ring buffer (600-byte entries), copying one or two matrices. */
void func_0031cc30(W1829Q* q, s32 a1, s32 a2, void* a3, void* a4, s32 a5, s32 a6);  // 0x0031cc30: definition moved into src/anon/unit_0031b9e0.cpp
}
