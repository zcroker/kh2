#include "../common/types.h"
struct W2024d_St { s32 mode; s32 f4; s32 step; u8 flag; u8 pad[3]; s32 f10; u8 f14[0x1c]; u8 f30[4]; };
struct W2024d_Pl { u8 pad[0xfc]; s32 fc; };
extern s32 D_0034e948;
extern u8 D_00351eb8[];
extern u8 D_00351ec0[];
extern "C" {
void func_002bc788(void);
s32 func_00197920(void);
W2024d_Pl* func_0014ac08(void);
void func_002bc798(void);
void func_001852b8(s32);
void func_001af938(void);
void func_001a58f8(void);
void func_00197738(void);
void func_001c8948(void);
s32 func_001c8db8(void*, s32);
s32 func_00170cd0(void);
void func_001c8d80(void*, s32);
void func_001c98f0(f32);
void func_001d0068(void);
void func_001af8d8(W2024d_St*);
void func_00170888(s32);
s32 func_001c9df8(void);
s32 func_001c10f8(s32);
void func_00253410(s32, void*);
void func_001af778(W2024d_St*);
void func_001373d8(void);
void func_001d00a8(void);
s32 func_001af420(W2024d_St* self) {
    switch (self->step) {
    case 1:
        func_002bc788();
        self->step++;
    case 2:
        if (func_00197920() != 0) break;
        if ((func_0014ac08()->fc ^ 4) != 0) break;
        func_002bc798();
        if (self->mode != 1) func_001852b8(D_0034e948);
        if (self->mode == 2) {
            func_001af938();
            return 0;
        }
        if (self->flag) {
            func_001a58f8();
        } else {
            func_00197738();
            func_001c8948();
        }
        self->step++;
        break;
    case 0:
    case 3:
        self->step++;
        break;
    case 4:
        if (func_001c8db8(D_00351eb8, 0) != 0) break;
        if (func_001c8db8(D_00351ec0, 0) != 0) break;
        if (func_00170cd0() != 0) break;
        func_001c8d80(D_00351eb8, 0);
        if (self->flag) {
            func_001c98f0(0.0f);
            func_001d0068();
        } else {
            func_001af8d8(self);
        }
        func_00170888(0);
        self->step++;
        break;
    case 5:
        if (self->flag) {
            if (func_001c9df8() != 0) break;
            func_00253410(func_001c10f8(10), self->f14);
        } else {
            if (func_00170cd0() != 0) break;
            func_001af778(self);
            func_00253410(self->f10, self->f30);
        }
        self->step++;
        break;
    case 7:
        func_001373d8();
        func_001d00a8();
        return 0;
    case 8:
        return 0;
    }
    return 1;
}
}
