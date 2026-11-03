// w3736 batch.
#include "../common/types.h"
extern "C" {
void func_001386e0(void*, s32, s32, void*, s32, s32);
void func_00139620(void*);
s32 func_00139d78(void*);
void func_002362b0(void*, s32);
s32 func_0023c4b8(s32, s32);
s32 func_0023f1b0(s32);
s32 func_0023f988(s32, s32);
u8* func_002766d0(void);
void func_0028dcc0(void*, void*);
s8* func_002a1bc0(u16);
struct S2a1d38 { s16 a, b, c; };
struct T2a1d38 { s8 n; s8 p1; s8 kind; u8 pad[0x4d]; struct { u16 id; u8 p[6]; } e[1]; };
extern s32 D_0035f210;
extern s32 D_0035f3d4;
extern T2a1d38* D_0035f5d4;
struct G1 { s32 dc; u8 e0; };
extern G1 D_0035f5dc;
extern u8 D_0035f5e0;
extern S2a1d38 D_00374b60[];
// Per-entry setup loop. Partial asm (step 4): the in-loop lui of D_0035f5d4 is hand-written (pinned to t7,
// ordered after p) so loop/cse2 do not hoist it and give it a register; the empty asm around the pre-loop
// load keeps t6 busy so its high half lands in t7. No code is emitted by the empty asm statements.
void func_002a1d38(void) {
    u8* w = func_002766d0();
    if (D_0035f5e0 == 0) return;
    if (func_00139d78(w + 0x4398)) return;
    s32 i = 0;
    s32 k = D_0035f3d4 + 3;
    s32 m = func_0023c4b8(func_0023f1b0(D_0035f210), 0);
    register s32 ph asm("$14"); asm("" : "=r"(ph));
    T2a1d38* t = D_0035f5d4;
    asm("" : : "r"(ph), "r"(t));
    s32 idx = t->kind == 0x10;
    if (t->n > 0) {
        u8* p = w;
        u8* q = w + 0xdca0;
        do {
            u8* o = p + 0x4398;
            func_002362b0(q, func_0023f988(D_0035f5dc.dc, func_002a1bc0(t->e[i++].id)[1]));
            bool on = 1; *(bool*)(q + 400) = on;
            func_001386e0(o, k, m, q, D_00374b60[idx].a, 0);
            q += 0x1a0;
            *(s32*)(p + 0x4520) = D_00374b60[idx].c;
            func_00139620(o);
            *(s8*)(p + 0x452d) = 1;
            *(s32*)(p + 0x4468) |= 8;
            func_0028dcc0(o, p + 0x1098);
            register u32 hi asm("$15"); asm("lui %0,%%hi(D_0035f5d4)" : "=r"(hi) : "r"(p)); t = *(T2a1d38**)(hi - 2604); p += 0x198;
        } while (i < t->n);
    }
}

struct S1b5108 { u8 pad[0x198]; void* x198; };
extern S1b5108* D_0035f654;
extern void* D_0035f6c8;
char* func_00192048(s32);
void func_002b6338(void*, s32, s32, s32);
// Sets the current message: a non-negative b loads it into D_0035f6c8, otherwise a message string by id.
void func_002b5108(s32 a, s32 b) {
    func_00139d78(D_0035f654);
    if (b >= 0) {
        func_002b6338(D_0035f6c8, 0x200, a, b);
        D_0035f654->x198 = D_0035f6c8;
    } else {
        D_0035f654->x198 = func_00192048(a);
    }
}

}
