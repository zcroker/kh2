#include "../common/types.h"
extern "C" {
struct S64 { u32 w[7]; u32 f; u32 pad[8]; };
extern s32 D_0034d8a4;
extern s32 D_0034d8a0;
void func_0016c8f8(S64*, u32, u32, u32);
void func_001da458(S64*, s32, s32, s32);
void func_0016cd48(S64*, u32*);
void func_0016cab8(S64*);
// 0016cc18: moved to src/anon/unit_0016c770.cpp

struct Sub3e0 { u8 pad[184]; u32 f184; };
struct Spr3e0 { u8 pad[24]; Sub3e0 sub; u8 pad2[392-24-188]; s32 f392; u8 pad3[9]; u8 b405; u8 pad4[2]; };
struct Obj3e0 { u8 pad[400]; u8 b400; u8 pad2[15]; };
struct Menu3e0 { u8 pad[24]; u8 pos[792]; u8 sub[1]; };
struct Big3e0 { u8 pad[0x4398]; Spr3e0 spr[2]; u8 pad2[0xdca0 - 0x4398 - 816]; Obj3e0 obj[2]; };
Big3e0* func_002766d0(void);
s32 func_0023aa18(u8*);
s32 func_0023aa38(u8*);
s32 func_0023f1b0(u32);
s32 func_0023c4b8(s32, u32);
s32 func_0023f988(u32, s32);
void func_002362b0(Obj3e0*, s32);
void func_001386e0(Spr3e0*, u8*, s32, Obj3e0*, u32, s32);
void func_00139620(Spr3e0*);
void func_0028dcc0(void*, void*);
void func_00138c68(void*, s32, s32);
extern u8 D_0035f5a8;
extern u8 D_0035f5a9;
extern u8* D_0035f3d4;
extern u32 D_0035f210;
extern u32 D_0035f5a4;
extern u32 D_003748f0;
extern u32 D_003748f4;
extern u32 D_003748f8;
extern u32 D_003748fc;
extern u32 D_00374900;
extern u32 D_00374904;
// Partial asm: register pins (k1/c1 t7, one t6, spr0 s7), empty asm barriers keeping the original's serial
// lui/lw order, and one hand-written lui so t6 holds the high half across the movz. See asm_review.tsv.
void func_0029a3e0(u8 flag) {
    Big3e0* b = func_002766d0();
    if (D_0035f5a8 && !D_0035f5a9) {
    s32 i;
    u8* base = D_0035f3d4 + 4;
    s32 x = func_0023aa18((u8*)b + 24);
    s32 y = func_0023aa38((u8*)b + 24); register Spr3e0* s0 asm("$23")=b->spr;
    Obj3e0* o = b->obj;
    for (i = 0; i < 2; i++, o++) {
        register u32 k1 asm("$15") = D_003748f4; asm volatile(""); u32 k = D_003748f0; asm volatile(""); register u32 hi asm("$14"); asm volatile("lui $14,%%hi(D_0035f210)" : "=r"(hi)); if (i == 0) k = k1; asm volatile(""); u32 g = *(u32*)(hi - 3568);
        s32 sh = func_0023c4b8(func_0023f1b0(g), k);
        func_002362b0(o, func_0023f988(D_0035f5a4, i));
        {register u8 one asm("$14") = 1; o->b400 = one;}
        u32 col;
        s32 c2;
        if (flag) {
            register u32 c1 asm("$15") = D_00374900; asm volatile(""); u32 c0 = D_003748f8; col = i != 0 ? c0 : c1;
            if (i == 0) c2 = D_00374904; else c2 = D_003748fc;
        } else {
            if (i == 0) col = D_00374904; else col = D_003748fc;
            c2 = -1;
        }
        Spr3e0* s = &b->spr[i];
        Sub3e0* sub = &s->sub;
        func_001386e0(s, base, sh, &b->obj[i], col, 0);
        s->f392 = c2;
        func_00139620(s);
        sub->f184 |= 8;
        s->b405 = 1;
        if (i == 0) {
            func_0028dcc0(s0, b);
            func_00138c68(s0, x, y);
        } else {
            func_0028dcc0(s, (u8*)b + 816);
        }
    }
    D_0035f5a9 = 1;
    }
}
}
