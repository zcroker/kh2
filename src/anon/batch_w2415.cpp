#include "../common/types.h"
// 002c29d8: large constructor (vtable stores, member ctors, D_00361c10 = this).
struct W1610Lc { s16 cur; u8 p2[2]; s16 vis; u8 p6[12]; s16 top; u8 p20[2]; s16 n; s16 cols; s16 rows; s16 step; u8 p30[6]; u8 wrap; u8 grid; u8 p38; u8 on; };
struct W1610Pd { u8 p0[8]; u64 rep; u8 p16[8]; u64 trg; };
extern "C" {
extern u8 D_00361c20[], D_00347f98[], D_0035eb98[], D_0035ebb8[], D_00347e60[], D_0035f380[], D_00347e40[];
extern u8* D_00361c10;
void func_0031a838(void*);
void func_0031a830(void*);
void func_002369a0(void*);
void func_0023c008(void*);
void func_0028d140(void*);
void func_00239700(void*);
void func_002361a0(void*);
void func_0028b9b0(void*);
void func_00190128(void*);
void func_00167f38(s32);
void func_002c5f48(void);
struct Id3b2c29d8 { u8 a, b, c; void Fill(s32 v) { a = v; b = v; c = v; } };
struct Id3h2c29d8 { u16 a, b, c; void Fill(s32 v) { a = v; b = v; c = v; } };
void func_002c29d8(u8* t)
{
    *(u32*)(t + 28) = (u32)D_00347f98;
    *(u32*)(t + 0) = (u32)D_00361c20;
    *(u32*)(t + 12) = 0;
    *(u32*)(t + 24) = 0;
    func_0031a838(t + 40);
    *(u32*)(t + 28) = (u32)D_0035eb98;
    func_002369a0(t + 52);
    func_0023c008(t + 76);
    u32* s1 = (u32*)(t + 188);
    for (s32 i = 8; i != -1; i--) {
        s1[3] = 0;
        s1[0] = (u32)D_0035ebb8;
        s1 = (u32*)((u8*)s1 + 76);
    }
    *(u32*)(t + 872) = 0;
    func_0028d140(t + 876);
    u8* e = t + 1320;
    for (s32 i = 7; i != -1; i--) {
        *(u32*)e = (u32)D_00347f98; func_0031a838(e + 12);
        *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
        *(u32*)e = (u32)D_0035f380;
        e += 432;
    }
    u8* e2 = t + 4776;
    for (s32 i = 7; i != -1; i--) {
        *(u32*)e2 = (u32)D_00347f98; func_0031a838(e2 + 12);
        *(u32*)e2 = (u32)D_00347e60; func_00239700(e2 + 24);
        *(u32*)e2 = (u32)D_0035f380;
        e2 += 432;
    }
    *(u32*)(t + 8232) = 0; *(u32*)(t + 8236) = 0; *(u32*)(t + 8240) = 0; *(u32*)(t + 8244) = 0;
    *(u32*)(t + 8248) = 0; *(u32*)(t + 8252) = 0; *(u32*)(t + 8256) = 0; *(u32*)(t + 8260) = 0;
    u8* e3 = t + 8272;
    for (s32 i = 7; i != -1; i--) {
        *(u32*)(e3 + 0) = 0; *(u32*)(e3 + 4) = 0; *(u32*)(e3 + 8) = 0;
        func_002361a0(e3 + 16);
        func_0031a830(e3 + 432);
        ((Id3b2c29d8*)(e3 + 436))->Fill(0xffff);
        ((Id3h2c29d8*)(e3 + 440))->Fill(0xffff);
        func_0031a830(e3 + 432);
        e3 += 448;
    }
    u8* m1 = t + 11872;
    *(u32*)m1 = (u32)D_00347f98; func_0031a838(m1 + 12);
    *(u32*)m1 = (u32)D_00347e60; func_00239700(m1 + 24);
    *(u32*)(m1 + 408) = 0; *(void**)m1 = D_00347e40;
    func_0028b9b0(t + 12308);
    *(u32*)(t + 12360) = 0;
    u32* s2 = (u32*)(t + 12384);
    for (s32 i = 2; i != -1; i--) {
        s2[3] = 0;
        s2[0] = (u32)D_00347e60;
        func_00239700((u8*)s2 + 24);
        s2 = (u32*)((u8*)s2 + 408);
    }
    ((Id3b2c29d8*)(t + 13608))->Fill(0xffff);
    ((Id3h2c29d8*)(t + 13612))->Fill(0xffff);
    func_00190128(t + 13620);
    u8* m2 = t + 13648;
    *(u32*)m2 = (u32)D_00347f98; func_0031a838(m2 + 12);
    *(u32*)m2 = (u32)D_00347e60; func_00239700(m2 + 24);
    *(u32*)(m2 + 408) = 0; D_00361c10 = t; *(void**)m2 = D_00347e40;
    func_00167f38(3);
    func_002c5f48();
}
// 0028a5a8: list cursor scroll up/down with wrap and grid paging.
s32 func_0028b040(W1610Lc*);
s32 func_0028af78(W1610Lc*, s32);
s32 func_0028a5a8(W1610Lc* l, W1610Pd* p) {
    s32 ret = 0;
    s32 sm;
    s32 vis = l->vis < l->n ? l->vis : l->n;
    if (!l->on) return 0;
    s32 cur = l->cur;
    s32 top = l->top;
    s32 sel = func_0028b040(l);
    if ((p->trg & 0x8000) && func_0028af78(l, 0x2000)) {
        if (sel == 0 && !(p->rep & 0x8000)) return 0;
        if (top - l->step >= 0) {
            top -= l->step;
        } else if (top != 0 || cur != 0) {
            if (top + cur - l->step < 0) {
                cur = 0;
                top = 0;
            } else {
                cur = sel - l->step;
                top = 0;
            }
        } else if (l->wrap) {
            if (l->grid) {
                s32 pg = l->cols * l->rows;
                s32 m = l->n % pg;
                sm = m;
                sm += (pg - m) / l->cols * l->cols;
                top = l->n - sm;
                if (top < 0) top = 0;
            } else {
                top = l->n - vis;
            }
            cur = l->n - top - 1;
        }
    } else if ((p->trg & 0x4000) && func_0028af78(l, 0x1000)) {
        if (sel >= l->n - 1 && !(p->rep & 0x4000)) return 0;
        if (sel >= l->n - 1) {
            if (l->wrap) {
                cur = 0;
                top = 0;
            }
        } else {
            if (top + cur + l->step < l->n) {
                s32 t = top + l->step;
                if (t + vis < l->n) {
                    top = t;
                } else {
                    if (l->grid) {
                        s32 q = l->n / l->cols;
                        if (l->n % l->cols) q++;
                        top = (q - l->rows) * l->cols;
                    } else {
                        top = l->n - vis;
                    }
                    if (top + cur >= l->n) cur = l->n - top - 1;
                }
            } else {
                if (l->grid) {
                    s32 pg = l->cols * l->rows;
                    s32 m = l->n % pg;
                    sm = m;
                sm += (pg - m) / l->cols * l->cols;
                top = l->n - sm;
                    if (top < 0) top = 0;
                } else {
                    top = l->n - vis;
                }
                cur = l->n - top - 1;
            }
        }
    }
    if (func_0028b040(l) != top + cur) {
        l->cur = cur;
        ret = 1;
        l->top = top;
    }
    return ret;
}
}
