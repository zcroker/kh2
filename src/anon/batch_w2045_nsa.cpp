#include "../common/types.h"
void func_00226030(void*);
extern "C" {
void func_00102448(void*, s32);
void func_00168388(char*, s32, void (*)(void*), void*);
s32 func_001688b8(void);
s32 func_001688c8(char*);
s32 func_00227870(char*, void*, s32);
void func_002278e0(void*);
void* func_00227a28(void);
void func_002ba630(s32, s32, s32, s32);
void func_002ba7c8(void*);
s32 func_002fee78(char*, const char*, ...);
void func_002ff3fc(char*);
extern s32 D_0035e35c;
extern char D_00371340[];
extern char D_00371350[];
extern char D_00371358[];
}
struct W2045_Ent { s32 type; u8 pad[16]; s32 h; u8 pad2[24]; char name[32]; };
struct W2045_Arg { u8 pad[6]; s16 a; s16 b; };
extern "C" {
// ---- 0x232a48 ----
void func_00232a48(W2045_Arg* p, void* q) {
    char buf[48];
    char buf2[48];
    s32 r2 = 0;
    W2045_Ent* e1 = 0;
    s32 r1 = 0;
    W2045_Ent* e2 = 0;
    D_0035e35c = p->a;
    if (p->a) {
        e1 = (W2045_Ent*)func_00227a28();
        e1->type = 4;
        func_002fee78(e1->name, D_00371340, p->a);
        func_002fee78(buf, D_00371350, e1->name);
        func_002ff3fc(buf);
        r1 = func_001688c8(buf);
        e1->h = func_00227870(buf, e1, 0);
        func_00168388(buf, e1->h, func_00226030, e1);
        if (p->b) {
            e2 = (W2045_Ent*)func_00227a28();
            e1->type = 5;
            func_002fee78(e2->name, D_00371358, p->b);
            func_002fee78(buf2, D_00371350, e2->name);
            func_002ff3fc(buf2);
            r2 = func_001688c8(buf2);
            e2->h = func_00227870(buf2, e2, 0);
            func_00168388(buf2, e2->h, func_00226030, e2);
        }
        while (func_001688b8()) func_00102448(q, 0);
    }
    if (p->a) {
        if (p->b) func_002ba630(e1->h, r1, e2->h, r2);
        else func_002ba630(e1->h, r1, 0, 0);
        func_002ba7c8(q);
    }
    if (p->a) {
        func_002278e0(e1);
        if (p->b) func_002278e0(e2);
    }
}
}
