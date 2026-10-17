#include "../common/types.h"

struct O25;
struct O25V { u8 pad[20]; void (*f)(O25*); };
struct O25 { O25V* vt; u8 pad[384]; s32 id; };
struct V2a { u8 pad[4]; void (*f)(void*); };

extern "C" {
u32 func_00287bc0(void);
u32 func_0028b040(u32);
void func_002b6338(u32, u32, u32, u32);
u32 func_00263a90(u32, u32);
u32 func_00263a58(u32, u32);
u32 func_00263d28(void);
extern u32 D_0035f64c;
extern u32 D_0035f6c4;
extern u16 D_00372f40[];

u32 func_0025d560(void) {
    u32 v0 = func_00287bc0();
    u32 id;
    if (v0 == 0) {
        v0 = func_0028b040(D_0035f64c);
        return func_00263a58(D_00372f40[v0], 1);
    }
    id = 0x8A82;
    if (v0 == 19) {
        return func_00263a58(id, 1);
    }
    if (v0 == 1) {
        u32 a3 = func_0028b040(D_0035f64c);
        func_002b6338(D_0035f6c4, 512, 0xB85A, a3);
        return func_00263a90(D_0035f6c4, 1);
    }
    if (v0 == 12) {
        return func_00263a58(0x8AA1, 1);
    }
    return func_00263d28();
}

u32 func_002424a0(void);
void func_0028e560(s32, u16*, s32, s32);
extern u16 D_0035f090;
extern u16 D_0035f094;

void func_00258df0(s32 a) asm("_Z12func_00258df0i");
void func_00258df0(s32 a) {
    u16 buf[6];
    s32 i;
    for (i = 5; i >= 0; i--) buf[5 - i] = D_0035f090;
    u32 v = func_002424a0();
    for (i = 0; i < 6; i++) {
        u32 d = v % 10;
        v = v / 10;
        if (i != 0 && d == 0 && v == 0) break;
        buf[i] = d + D_0035f094;
    }
    func_0028e560(a, buf, 6, -1);
}

s32 func_00139d78(O25*);
void func_00138c10(O25*, s32);
void func_0028d8c0(O25*, s32, s32, s32, s32, s32, s32, s32);
extern O25* D_0035f07c;
extern s32 D_0035f078;

void func_002588e8(s32 a) {
    if (a >= 0) {
        if (!func_00139d78(D_0035f07c)) {
            func_0028d8c0(D_0035f07c, 30001, 0, 0, D_0035f078, a, -1, 0);
            return;
        }
        if (D_0035f07c->id != a) {
            func_00138c10(D_0035f07c, a);
        }
    } else if (func_00139d78(D_0035f07c)) {
        D_0035f07c->vt->f(D_0035f07c);
    }
}

void func_00106420(void*);
void func_0031acc0(u8*);
void func_0031abd8(u8*);
void func_00239870(u8*);
extern u8 D_00347e60;
extern u8 D_00347f98;
extern void* D_0035f5d4;
extern u8* D_0035f5d8;
extern V2a** D_0035f5dc;
extern u8 D_0035f5e0;
extern u8 D_0035f5e1;

// Frees the three globals and clears two flags; the middle object's destructor is inlined.
void func_002a06b8(void) {
    if (D_0035f5d4) {
        func_00106420(D_0035f5d4);
        D_0035f5d4 = 0;
    }
    u8* p = D_0035f5d8;
    if (p) {
        func_0031acc0(p + 1224);
        func_0031abd8(p + 816);
        func_0031abd8(p + 408);
        *(u32*)p = (u32)&D_00347e60;
        func_00239870(p + 24);
        *(u32*)p = (u32)&D_00347f98;
        func_00106420(p);
        D_0035f5d8 = 0;
    }
    if (D_0035f5dc) {
        (*D_0035f5dc)->f(D_0035f5dc);
        D_0035f5dc = 0;
    }
    D_0035f5e0 = 0;
    D_0035f5e1 = 0;
}
}
