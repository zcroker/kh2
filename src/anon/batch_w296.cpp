#include "../common/types.h"
extern "C" {
extern u8 D_0034ef18[];
extern u8* D_0034e948;

s32 func_001bffd8(void);
s32 func_001c0090(void);
u8* func_0019fe90(s32, s32);
void func_001c0150(void*, s32);  // obj_init_fields_1c0150
void func_0018e0d8(void*, u32);
s32 func_001b5a10(void);

struct W296Obj {
    void* vt;      // 0
    u32 flags;     // 4
    u8* p8;        // 8
    u8* pc;        // c
    u8* p10;       // 10
    s32 a14;       // 14
    s32 a18;       // 18
    s32 a1c;       // 1c
    s32 a20;       // 20
    u8* p24;       // 24
    u8* p28;       // 28
    u8 pad2c[4];
    u8 sub30[0x54];
    s32 a84;
    u8* p88;
    s32 a8c;
    u8 pad90[8];
    s32 a98;
    u8 pad9c[8];
    u8 ba4;
    u8 pada5[0x1b];
    W296Obj* next;     // c0
};
struct W296List { W296Obj* head; W296Obj* tail; };
extern W296List D_list asm("D_01c60cd8");
void func_0018d050(W296Obj* o, u8* a1, u8* a2, s32 a3, s32 a4, s32 a5, s32 a6);  // 0x0018d050: definition moved into src/anon/unit_0018d050.cpp

void func_0018d238(W296Obj* o, u8* a1, u8* a2, s32 a3, s32 a4, s32 a5, s32 a6);  // 0x0018d238: definition moved into src/anon/unit_0018d050.cpp

extern u8* D_0035ee04;
extern u8* D_0035ee08;
extern u8* D_0035ee0c;
extern u8* D_0035ee10;
s32 func_00287db0(void);
s32 func_00139d78(u8*);
s32 func_0023f0c0(u8*);
void func_0023f070(u8*, s32, s32);
void func_00288e88(u8*);
void func_0024eac0(void);
void func_0024f1a0(void);
void func_0028cdb8(s32);  // record408_alloc_init
void func_0024f2d0(void);
s32 func_002891e8(u8*);
s32 func_00287cd0(void);
s32 func_0028d008(s32);
void func_0028cc78(s32, s32, s32, u8*, s32, s32);
s32 func_0024efc0(s32);  // to_28dbf8_entry6
void func_0028cf98(s32, s32);
s32 func_00289310(u8*);
void func_0024eff8(s32);

typedef void (*VFn)(u8*);

void func_0024edd8(void) {
    if (func_00287db0()) {
        if (!func_00139d78(D_0035ee08)) return;
        if (func_0023f0c0(D_0035ee08) == 2) return;
        if (func_00139d78(D_0035ee08)) {
            if (func_0023f0c0(D_0035ee08) != 2) func_0023f070(D_0035ee08, 2, -1);
        }
        if (D_0035ee0c && func_00139d78(D_0035ee0c)) {
            (*(VFn*)(*(u8**)D_0035ee0c + 20))(D_0035ee0c);
        }
        if (D_0035ee10 && func_00139d78(D_0035ee10)) {
            (*(VFn*)(*(u8**)D_0035ee10 + 20))(D_0035ee10);
        }
        func_00288e88(D_0035ee04);
        func_0024eac0();
        func_0024f1a0();
        func_0028cdb8(0);  // record408_alloc_init
    } else {
        s32 r;
        func_0024f2d0();
        r = func_002891e8(D_0035ee04);
        if (func_00139d78(D_0035ee08) && func_00287cd0() == 1 && func_0028d008(0) == 0) {
            func_0028cc78(0, 2, 2, D_0035ee08, 4, 4);
            func_0028cf98(0, func_0024efc0(r));
        }
        if (!func_00289310(D_0035ee04)) return;
        if (!func_0028d008(0)) return;
        func_0024f1a0();
        func_0028cf98(0, func_0024efc0(r));
        func_0024eff8(r);
    }
}

}
