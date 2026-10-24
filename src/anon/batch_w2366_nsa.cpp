#include "../common/types.h"

struct In1be { u8 pad[0x6c]; u32 x6c; };
struct Sub1be { u8 b[116]; };
struct S1be {
    u8 pad[0x24];
    Sub1be sub[19];
    u8 pad2[0x8c0 - 0x24 - 19 * 116];
    In1be** p8c0;
    u8 pad3[0xaa4 - 0x8c4];
    u32 aa4;
};

extern "C" {
void func_001bc730(Sub1be*, u32);
void func_001bd618(S1be*, u32);
void func_001bd5b0(S1be*, u32, u32);
void wtarget_001be4e0(u32, u32, u32, u32) asm("_Z16wtarget_001be4e0jjjj");

// Selects entry a1: records the index, sets up sub-entry a1, then refreshes (needs -fno-strict-aliasing).
void wtarget_001be4e0(u32 a0, u32 a1, u32, u32) {
    S1be* s = (S1be*)a0;
    s->aa4 = a1;
    Sub1be* p = &s->sub[a1];
    u32 v = (*s->p8c0)->x6c;
    func_001bc730(p, v);
    func_001bd618(s, 0);
    func_001bd5b0(s, s->aa4, 0);
}
}
