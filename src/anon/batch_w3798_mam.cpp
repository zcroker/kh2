// 002b2a18: sets up three entries of a widget table (two in a loop, one after it).
// Built with -fmove-all-movables (_mam). Partial asm (logged in asm_review.tsv):
// - st and the constant 1 are pinned to s6/s7 (global-alloc priority otherwise puts the table pointer there);
// - the table's high half comes from a one-instruction `lui` asm tied to the D_0035f3d4 load, so it is
//   issued after that load and reuses t7 like the original.
#include "../common/types.h"
struct St2b2a18 { u32 pad:27; u32 bit:1; u32 pad2:4; };
extern "C" {
extern u8* D_0035f634;
extern s32 D_0035f3d4;
extern s32 D_0035f14c;
extern s32 D_0035f148;
extern s32 D_0035f210;
extern s16 D_00374cc8[];
extern s16 D_00374cd8[];
u8* func_002766d0(void);
St2b2a18* func_002b23e0(s32);
void func_00139d78(u8*);
s32 func_0023f1b0(s32);
s32 func_0023c4b8(s32, s32);
void func_001386e0(u8*, s32, s32, u8*, s32, s32);
void func_0028d8c0(u8*, s32, s32, s32, s32, s32, s32, s32);
void func_00139620(u8*);
void func_0028dcc0(u8*, u8*);
void func_00139570(u8*);
}

extern "C" {
void func_002b2a18(void) {
    s32 i = 0;
    s32 off = 0;
    u8* g = func_002766d0();
    register St2b2a18* st asm("$22") = func_002b23e0(-1);
    u8* base = D_0035f634;
    s32 id;
    u8* p;
    u8* b;
    u8* q;
    s32 w;
    func_00139d78(base);
    s32 t = D_0035f3d4;
    u32 h; asm("lui %0,0x37" : "=r"(h) : "r"(t));
    id = t + 3;
    s16* tbl = (s16*)(h + 19672);
    register u8 one asm("$23") = 1;
    do {
        if (i != 0) {
            b = D_0035f634;
            id++;
            p = b + 20808;
            b += 20832;
            s32 r = func_0023c4b8(func_0023f1b0(D_0035f210), 6);
            w = D_00374cc8[st->bit];
            func_001386e0(p, id, r, g + 0xdca0, w, 0);
            *(u32*)(b + 184) |= 8;
            func_00139620(p);
            p[405] = 1;
            func_0028dcc0(p, base);
            *(u32*)(b + 184) = (*(u32*)(b + 184) & ~0x2000) | 0x2000;
            func_00139570(p);
        }
        b = D_0035f634;
        b += off;
        p = b + 19992;
        b += 20016;
        w = tbl[st->bit * 3 + i];
        func_0028d8c0(p, id, D_0035f14c, D_0035f148, D_0035f210, w, -1, 0);
        i++;
        off += 408;
        func_00139620(p);
        *(u32*)(b + 184) |= 8;
        p[405] = one;
        func_0028dcc0(p, base);
        func_00139570(p);
    } while (i < 2);
    b = D_0035f634;
    p = b + 19584;
    func_0028d8c0(p, 30058, D_0035f14c, D_0035f148, D_0035f210, 115, -1, 0);
    q = b + 19608;
    func_00139620(p);
    *(u32*)(q + 184) |= 8;
    p[405] = 1;
    func_0028dcc0(p, D_0035f634 + 19992);
    func_00139570(p);
}

}
