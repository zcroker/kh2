// 00247198: -O2 -fno-strict-aliasing (zl90 w2421 draft). The flag-true path formats through an inline wrapper
// taking the format string as a parameter (inline args evaluate left to right: lui before the lw of n).
#include "../common/types.h"
namespace n00247198 {
struct El { u8 pad[408]; };
struct Ek { u8 pad[408]; s32 f408; u8 pad2[24]; };
struct Tx { u8 pad[32]; };
struct Big {
    u8 pad[4360]; Ek c[4]; u8 pad2[7848 - 4360 - 4 * 436];
    El e[4]; El f[4]; El g[4]; El h[4]; Tx t[4]; Tx u[4];
};
struct Inf { u8 kind; u8 pad[3]; u32 n; };
extern "C" {
extern Big* D_0035ed40;
extern u8 D_00371ca8[];
extern u8 D_00371cb0[];
extern u8 D_00371cb8[];
extern u8 D_00371cc0[];
extern s16 D_00371cd0[];
extern char D_00371ab8[];

extern s32 D_00371ac4;
extern s32 D_00371ac8;
s32 func_00246968(s32);
s32 func_00246840(void);
Inf* func_001d56c8(u8);
void func_00239f18(f32, void*);
void* func_00192048(s32);
void func_00192c90(void*, void*);
s32 func_00192c40(void*, void*);
void* func_00192cc0(void*, char*, u32);
s32 func_00192b30(void*);
s32 func_002474e0(s32);
void func_00138c10(void*, s32);
s32 func_00105c30(void);
static inline void* fmt247198(void* s, char* f, u32 n) { return func_00192cc0(s, f, n); }
static inline __attribute__((always_inline)) void* fmtA(void* s, char* f, u32 n) { return func_00192cc0(s, f, n); }
static inline s32 put247198(u8* s, u32 n) { return func_00192b30(func_00192cc0(s, D_00371ab8, n)); }
static inline bool chk247198(void) {
    bool r = false;
    if (func_00105c30() == 1 || func_00105c30() == 8) r = true;
    return r;
}

void func_00247198(void) {
    s32 i;
    s32 k = 0;
    s16* sp = D_00371cd0;
    for (i = 0; i < 4; i++, sp++) {
        if (func_00246968(i)) {
            Inf* inf = func_001d56c8((func_00246840() ? D_00371cb0 : D_00371ca8)[i]);
            u8* s2;
            u8* e;
            s32 d;
            s32 flag;
            if (inf->kind < 2) {
                func_00239f18(0.0f, (u8*)&D_0035ed40->f[k] + 24);
                s2 = (u8*)&D_0035ed40->t[k];
                func_00192c90(func_00192048(0xcb9b), s2);
            } else if (inf->kind == 2) {
                e = (u8*)&D_0035ed40->f[k];
                d = (func_00246840() ? D_00371cc0 : D_00371cb8)[i];
                d--;
                func_00239f18((f32)inf->n / (f32)d, e + 24);
                flag = 0;
                Ek* ck = &D_0035ed40->c[k];
                ck->f408 = (s32)func_00192048(0xcc0b);
                s2 = (u8*)&D_0035ed40->u[k];
                if (func_00105c30() == 1 || func_00105c30() == 8) flag = 1;
                if ((u8)flag) {
                    e = (u8*)func_00192b30(fmt247198(s2, D_00371ab8, inf->n));
                    func_00192c90(func_00192048(0xcb9a), s2 + (s32)e);
                } else {
                    func_00192cc0(s2 + func_00192c40(func_00192048(0xcb9a), s2), D_00371ab8, inf->n);
                }
                s2 = (u8*)&D_0035ed40->t[k];
                func_00192c90(func_00192048(0xcb9b), s2);
            } else if (inf->kind == 3) {
                func_00239f18(1.0f, (u8*)&D_0035ed40->f[k] + 24);
                s2 = (u8*)&D_0035ed40->t[k];
                func_00192cc0(s2, D_00371ab8, inf->n);
                e = (u8*)&D_0035ed40->h[k];
                func_00138c10(e, *sp);
            }
            El* g = &D_0035ed40->g[k];
            func_00138c10(g, func_002474e0(k) ? D_00371ac4 : D_00371ac8);
            k++;
        }
    }
}
}
}
