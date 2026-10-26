#include "../common/types.h"
// zl90 w2408 2026-10-26: 0027b248 (b0e ? flag : !flag test, separate la/lb locals), 002a5df0 (do-while with ++i < n && k < 10, v reused for the ternary).
extern "C" {
struct W2408Ent { u8 pad[0xe]; s8 b0e; u8 pad2[2]; s8 b11; };
void func_00138c10(u8*, s32);
void func_00139570(u8*);
void func_00139580(u8*);
void func_00139d78(u8*);
s32 func_00192cc0(u8*, u32*, ...);
void func_00239f18(f32, u8*);
void func_0023aa58(u8*);
s32 func_002570a0(s32);
u8* func_00257770(void);
void func_0027aed8(s32, s32*, s32*);
s32 func_00287bc0(void);
s32 func_0028b040(s32);
s32 func_002fd178(s32);
extern s32 D_0035f01c;
extern u8* D_0035f230;
extern u32 D_00373de8;
extern s32 D_00373df4;
extern s32 D_00373df8;

void func_0027b248(s32 arg0) {
    s32 la, lb;
    u8 flag = arg0;
    u8* w = func_00257770();
    u8* o = w + 0xb350;
    func_00139d78(o);
    if (((s8*)D_0035f230)[7] == 0) {
        func_00139570(w + 0xb504);
        func_00139570(w + 0xb6b8);
        return;
    }
    s32 cur = *(s16*)(D_0035f230 + 4);
    s32 max = *(s16*)(D_0035f230 + 2);
    f32 fmax = max;
    *(s32*)(o + 0x198) = func_00192cc0(D_0035f230 + 652, &D_00373de8, cur, max);
    f32 r1 = (f32)cur / fmax;
    if (1.0f < r1) r1 = 1.0f;
    func_0027aed8(func_002570a0(15), &la, &lb);
    s32 m = func_00287bc0();
    s32 idx;
    if (m == 16) idx = func_0028b040(D_0035f01c);
    else idx = func_002570a0(16);
    W2408Ent* e = (W2408Ent*)((u32)(idx * 8) + (u32)D_0035f230);
    s32 delta = e->b11;
    if (m == 16) {
        if (e->b0e && la != 1) delta = -delta;
    } else if (e->b0e ? flag != 0 : flag == 0) {
        delta = 0;
    } else {
        delta = ((W2408Ent*)(D_0035f230 + idx * 8))->b0e ? -delta : delta;
    }
    if (max < cur + delta) delta = max - cur;
    f32 r2 = (f32)func_002fd178(cur + delta) / fmax;
    if (1.0f < r2) r2 = 1.0f;
    if (delta == 0 || la == 1) func_00139570(w + 0xb504);
    else func_00139580(w + 0xb504);
    u8* q = w + 0xb504;
    func_0023aa58(q + 24);
    func_00138c10(q, (r1 <= r2) ? D_00373df4 : D_00373df8);
    f32 f = r1;
    u8* p1 = w + 0xb51c;
    if (!(r2 <= r1)) f = r2;
    func_00239f18(f, p1);
    f32 g = r1;
    u8* p2 = w + 0xb6d0;
    if (!(r1 < r2)) g = r2;
    func_00239f18(g, p2);
}

struct W2408Name { u8 c[16]; };
struct W2408Rec { u16 h0; u16 h2; };
u8* func_002766d0(void);
s32 func_0028b038(s32);
void func_0028be78(s32, s32);
void func_002fde18(u8*, s32, s32);
W2408Rec* func_002a6368(s32);
s32 func_002944d0(W2408Rec*);
s32 func_001d44d8(u16);
s32 func_001d4550(s32);
s32 func_00192048(u16);
void func_00192c90(s32, u8*);
void func_0028de08(u16, u8*, s32);
u8* func_002891b8(s32, s32);
s32 func_00192b30(s32);
s32 func_002aaa38(s32);
s32 func_002aaab8(s32);
extern s32 D_0035f200;
extern s32 D_0035f214;
extern u8* D_0035f5ec;
extern u32 D_00374ba8;
extern s32 D_00374bd8;
extern s32 D_00374bdc;

void func_002a5df0(void) {
    s32 n = 10;
    u8* w = func_002766d0();
    s32 start = func_0028b038(D_0035f200);
    func_0028be78(D_0035f214, start);
    func_002fde18(D_0035f5ec + 0x1f, 0, 160);
    func_002fde18(w + 0x110a0, 0, 640);
    s32 c = *(s8*)D_0035f5ec;
    if (c < 10) n = c;
    for (s32 j = 0; j < n; j++) func_00138c10(w + j * 408 + 0xa998, 2);
    s32 k = 0;
    s32 i = 0;
    n = *(s8*)D_0035f5ec;
    if (n > 0) do {
        if (i < start) continue;
        W2408Rec* r = func_002a6368(((s8*)D_0035f5ec)[i + 6]);
        s32 ok = func_002944d0(r);
        u16 id = r->h2;
        s32 v;
        if (ok) {
            v = func_001d4550(func_001d44d8(r->h0));
            func_00192c90(func_00192048(id), w + k * 64 + 0x110a0);
        } else {
            v = 0;
            func_0028de08(id, w + k * 64 + 0x110a0, 64);
        }
        *(u8**)(func_002891b8(D_0035f200, k) + 0x198) = w + k * 64 + 0x110a0;
        s32 len = func_00192b30(func_00192cc0(((W2408Name*)(D_0035f5ec + 0x1f))[k].c, &D_00374ba8, v));
        func_00192c90(func_00192048(19206), &((W2408Name*)(D_0035f5ec + 0x1f))[k].c[len]);
        if (ok && func_002aaa38(((s8*)D_0035f5ec)[i + 6])) {
            v = func_002aaab8(((s8*)D_0035f5ec)[i + 6]) ? D_00374bdc : D_00374bd8;
            func_00138c10(w + k * 408 + 0xa998, v);
        }
        k++;
    } while (++i < n && k < 10);
}
}
