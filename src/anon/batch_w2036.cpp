#include "../common/types.h"
struct L2bc7f0 { s32 a; s32 b; };
struct E2bc7f0 { u8 d[0x40]; ~E2bc7f0() {} };
struct P2bc7f0 { E2bc7f0 e[64]; s32 idx[64]; s32 n; };
extern L2bc7f0 D_01e2aa80;
extern L2bc7f0 D_01e2aa88;
extern P2bc7f0 D_01e2aa90;
extern "C" {
void func_00324710(void*);
void wtarget_002bc7f0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_002bc7f0jjjj");
void wtarget_002bc7f0(u32 a0, u32 a1, u32 a2, u32 a3) {
    if (a1 == 0xffff && a0 == 1) {
        D_01e2aa80.a = 0;
        D_01e2aa80.b = 0;
    }
    if (a1 == 0xffff && a0 == 1) {
        D_01e2aa88.a = 0;
        D_01e2aa88.b = 0;
    }
    if (a1 == 0xffff && a0 == 1) {
        E2bc7f0* e = D_01e2aa90.e;
        for (s32 i = 63; i != -1; ) { i--; func_00324710(e->d + 0x24); e++; }
        P2bc7f0* b = &D_01e2aa90;
        s32* q = b->idx;
        for (s32 j = 0; j < 64; j++) *q++ = j;
        b->n = 64;
    }
    if (a1 == 0xffff && a0 == 0) {
        D_01e2aa90.~P2bc7f0();
    }
}
}
