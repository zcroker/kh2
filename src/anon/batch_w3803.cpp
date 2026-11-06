#include "../common/types.h"
extern "C" {
struct Slot272 { u8 p0[3]; s8 b3; u8 p4[7]; s8 bb; };
struct Pair272 { u16 a; u16 b; u16 c; u16 d; };
struct Rec272 { u16 a; u16 id; };
extern s32 D_0035f01c;
extern s32 D_0035f014;
extern u8* D_0035f12c;
extern s32 D_003739c4;
extern s32 D_003739c8;
extern u16 D_00373a80[];
extern u16 D_00373a90[];
extern Pair272 D_00373af8[];
s32 func_00287bc0(void);
u8* func_00257770(void);
s32 func_0028b040(s32);
s32 func_002570a0(s32);
s32 func_00272b60(s32);
Rec272* func_00273180(s32, s32);
u8* func_00273140(s32);
u8* func_00281f20(s32);
u8* func_001a80c8(u32);
u32 func_00192048(s32);
s32 func_00192c90(u32, u8*);
void func_00263a90(u8*, s32);
struct S2b2 { u8 pad[0x34]; s32 idx:8; u32 flag:1; u32 rest:23; };
struct I2b2 { u32 lo:26; u32 b26:1; u32 b27:1; u32 hi:4; };
struct L2b2 { s8 cols; s8 rows; s16 step; };
struct F2b2 { u32 b0:3; u32 b3:1; u32 b4:9; u32 b13:1; u32 hi:18; };
struct Sub2b2 { u8 pad[0xb8]; F2b2 f; };
struct O2b2 { u8 pad[0x18]; Sub2b2 sub; u8 pad2[0x195 - 0x18 - 0xbc]; u8 b195; u8 pad3[2]; };
extern S2b2* D_0035f638;
extern O2b2* D_0035f634;
extern s32 D_0035f3d4;
extern s32 D_0035f210;
extern const L2b2 D_00374cd0[];
void func_002b2428(s32);
s32 func_00292630(void);
u8* func_002766d0(void);
I2b2* func_002b23e0(s32);
void func_002b27c8(void);
s32 func_0023f1b0(s32);
s32 func_0023c4b8(s32, s32);
s32 func_0023f988(void*, s32);
void func_002362b0(void*, s32);
void func_001386e0(void*, s32, s32, void*, s32, s32);
void func_00139620(void*);
void func_0028dcc0(void*, void*);
void func_00138c68(void*, s32, s32);
void func_002b28b0(u32, s32, s32, void*);
void func_00239558(void*, void*, void*);
void func_002b1bd0(s32);
void func_002b2a18(void);
void func_002b2da8(s32);
void func_002b3050(s32);

}

extern "C" {
// Looks up the message id for the current menu mode and draws that message.
// Partial inline asm (asm_review.tsv): register pins for id/mode/has/k/t/i/o and one pinned subu.
void func_00272c90(void)
{
    register s32 id asm("$19") = -1;
    s32 id2 = -1;
    register s32 mode asm("$18") = func_00287bc0();
    u8* base = func_00257770();
    register s32 has asm("$22");
    s32 v;
    s32 r;
    if (mode == 25) has = func_0028b040(D_0035f01c);
    else has = func_002570a0(25);
    if (mode == 25) {
        if (!func_0028b040(D_0035f01c)) id = D_003739c4;
        else id = D_003739c8;
    } else if ((u32)(mode - 26) < 3) {
        v = func_0028b040(D_0035f01c);
        register s32 k asm("$20") = func_00272b60(v);
        if (k == 3) {
            id = func_00273180(3, ((Slot272*)D_0035f12c)->b3)->id;
        } else {
            asm("" : "+r"(k));
            register s32 t asm("$15") = has != 0;
            register s32 i asm("$17");
            asm("subu %0,%1,%2" : "=r"(i) : "r"(v), "r"(t));
            u8* p = func_00273140(i);
            if (p) id = *(u16*)(p + 10);
            if (mode == 27) { register u32 o asm("$14") = i * 8; o += (u32)D_0035f12c; id2 = func_00273180(k, ((Slot272*)o)->bb)->id; }
        }
    } else if (mode == 29) {
        v = func_0028b040(D_0035f01c);
        if (v) id = *(u16*)(func_001a80c8(*(u16*)(func_00281f20(D_0035f014) + v * 6 - 6)) + 10);
        else id = 0x9df7;
    } else if (mode == 30) {
        v = func_0028b040(D_0035f01c);
        register u16* o asm("$14") = &D_00373a80[v];
        id = *o;
    } else if (mode == 31) {
        v = func_0028b040(D_0035f01c);
        id = D_00373a90[v % 2];
        if (has) id2 = D_00373af8[v / 2].b;
    } else if (mode == 32) {
        v = func_0028b040(D_0035f01c);
        id = func_00273180(3, v)->id;
    } else {
        v = func_0028b040(D_0035f01c);
        id = func_00273180(4, v)->id;
    }
    r = 0;
    if (id > 0) r = func_00192c90(func_00192048(id), base + 0xb1d0);
    if (id2 > 0) {
        s32 t = r - (r != 0);
        r = t + func_00192c90(func_00192048(id2), base + t + 0xb1d0);
    }
    func_00263a90(r ? base + 0xb1d0 : 0, 1);
}

// Builds a grid of menu entries (rows x cols from the D_00374cd0 layout table) and lays them out.
void func_002b24c8(void) {
    if (!D_0035f638->flag) {
        if (D_0035f638->idx >= 0) func_002b2428(D_0035f638->idx);
        return;
    }
    if (D_0035f638->idx < 0) return;
    if (func_00292630()) return;
    {
        u8 b0[16];
        u8* base;
        s32 row;
        s32 v;
        s32 rows;
        s32 step;
        void* name;
        I2b2* info;
        s32 font;
        s32 cols;
        base = func_002766d0();
        row = 0;
        info = func_002b23e0(-1);
        func_002b27c8();
        v = D_0035f3d4 + 2;
        name = (u8*)D_0035f634 + 0x52e0;
        font = func_0023c4b8(func_0023f1b0(D_0035f210), 6);
        s32 r = func_0023f988(D_0035f638, 0);
        u8* w = base + 0xdca0;
        func_002362b0(w, r);
        w[400] = 1;
        u32 k = info->b27;
        step = D_00374cd0[k].step;
        rows = D_00374cd0[k].rows;
        cols = D_00374cd0[k].cols;
        for (; row < rows; row++) {
            s32 col;
            for (col = 0; col < cols; col++) {
                O2b2* o = &D_0035f634[row * cols + col];
                func_001386e0(o, v, font, base + 0xdca0, 0, 0);
                s32 n = row * cols + col;
                if (row == 0 && col == 0) {
                    Sub2b2* t = &o->sub;
                    t->f.b3 = 1;
                    o->b195 = 1;
                }
                Sub2b2* s = &o->sub;
                func_00139620(o);
                func_0028dcc0(o, name);
                s32 one = 1;
                s->f.b13 = one;
                func_00138c68(o, col * step, row * step);
                func_002b28b0(info->b27, n, 0, b0);
                func_00239558(s, b0, b0 + 8);
            }
        }
        func_002b1bd0(1);
        func_002b2a18();
        if (!info->b26) {
            func_002b2da8(0);
            func_002b3050(1);
        }
        D_0035f638->idx = -1;
        D_0035f638->flag = 0;
    }
}
}
