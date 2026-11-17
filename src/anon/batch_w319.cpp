#include "../common/types.h"
extern "C" {
extern s32 D_00348060[];
extern s32 D_00348420[];
u32 func_0013b988(void*, void*, u8, s32, s32, s32);  // table_by_arg_flags
void func_0013c080(void*, void*, s32, s32, u8*, s32, s32*, s32*);
u32 func_0013bc40(void*, s32);  // is_zero_arg
u32 func_0013b9e0(void*, s32);
u8* func_001b8e88(u16);
u32 func_00192048(u32);
u8* func_0013b5d0(void*, s32, s32, void*, u8, s32, s32, u32, f32, u32, s32);
void func_0013bc50(void*, void*, s32, s32, u8, u32, u8*, u8*);

void func_0013c190(u8* p, u8* a1, s32 a2, s32 a3, u8 t0, s32 t1, s32 t2, s32 t3, u8* s6);  // 0x0013c190: definition moved into src/anon/unit_0013a8b8.cpp

s32 func_002384f8(...);

union W319U { u32 w; u16 h[2]; u8* p; };
struct W319BF { u32 b0:4; u32 b4:1; u32 b5:1; u32 b6:1; u32 b7:1; u32 b8:1; u32 b9:1; u32 b10:1; u32 rest:21; };
void func_0023aab8(u8* p) {
    if (*(u8*)(p + 188) == 0) {
        s32 idx = *(s32*)(p + 276);
        u16* e;
        u8* s1;
        s32 n;
        u32 s0;
        ((W319U*)(p + 192))->w = idx;
        *(u8*)(p + 188) = 1;
        e = (u16*)(*(u8**)(p + 180) + idx * 36);
        s0 = 0;
        ((W319U*)(p + 196))->p = *(u8**)(p + 176) + e[0] * 144;
        ((W319U*)(p + 200))->w = e[1];
        n = e[1];
        s1 = *(u8**)(p + 176) + e[0] * 144;
        if (n > 0) {
            do {
                u32 f = *(u32*)s1;
                if (f & 4) s0 |= 1;
                if (*(u32*)(s1 + 132)) s0 |= 2;
                if (!(f & 0x20)) s0 |= 4;
                if (!(f & 0x40)) s0 |= 8;
                if (!(f & 0x400)) s0 |= 0x10;
                if (func_002384f8(p, *(u32*)(s1 + 4))) s0 |= 0x20;
                if ((*(u32*)s1 & 0x1010) != 0x1010) s0 |= 0x40;
                s1 += 144;
                if (s0 == 127) break;
            } while (--n > 0);
        }
        { W319BF* b = (W319BF*)(p + 184);
        b->b4 = 0; b->b5 = 0; b->b6 = 0; b->b7 = 0; b->b8 = 0; b->b9 = 0; b->b10 = 0;
        if (!(s0 & 1)) b->b4 = 1;
        if (!(s0 & 2)) b->b5 = 1;
        if (!(s0 & 4)) b->b6 = 1;
        if (!(s0 & 8)) b->b7 = 1;
        if (!(s0 & 0x10)) b->b8 = 1;
        if (!(s0 & 0x20)) b->b9 = 1;
        if (!(s0 & 0x40)) b->b10 = 1; }
    }
    *(f32*)(p + 204) = (f32)(s32)*(f32*)(p + 260);
}

extern s32 D_0035f3d4;
extern u16 D_00375850[];
extern u8 D_00375840[];
extern u8 D_00375848[];
extern u8 D_00375838[];
u32 func_00288be8(...);
u8* func_0023f1b0(...);
u32 func_0023c4b8(...);
u32 func_00236ca8(...);
u8* func_0028c2c8(...);
s32 func_0023aa98(...);
u32 func_00138c68(...);
u32 func_00324bc0(...);
s32 func_0023aa18(...);
s32 func_0023aa38(...);
u32 func_00288ce0(...);
u32 func_00239870(...);
u32 func_002891f0(...);
u32 func_0028b078(...);  // obj_setup_from_args
u32 func_0028af90(...);  // obj_set_field22_from_arg
u32 func_00288f48(...);
u32 func_0028d068(...);
u32 func_0028d1c0(...);
u32 func_002891d0(...);
u32 func_0028d660(...);  // record_set_value_refresh
u32 func_001396b0(...);

struct W319C { void f(s32, s32) asm("func_002889f0"); };
void func_002ca828(u8* p);  // 0x2ca828: moved to src/anon/unit_002ca0e0.cpp

}
