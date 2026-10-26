#include "../common/types.h"
extern "C" {
struct Ent2a3 { u8 b0; u8 n; u8 b2; u8 b3; u8 pad[4]; };
struct G2a3 { u8 pad[0x1000]; Ent2a3 ent[15]; u8 pad2[0x1084 - 0x1078]; s32 lim; };
extern G2a3* D_0035f5e4;
extern u8* D_0035f5e8;
extern s32 D_0035f214;
extern u32 D_00374ba0;
extern u32 D_00374ba4;
extern s32 D_00374b9c;
extern s32 D_00374b98;
u8* func_002766d0(void);
void func_0028be78(s32, s32);
void func_002fde18(void*, s32, s32);
void func_00138c10(void*, s32);
u32 func_00295430(s32, s32);
s32 func_002954e0(s32);
void* func_00192048(u32);
void* func_0028de08(u32, void*, s32);
s32 func_002a43f0(void);
void func_002a3648(void);
void func_002a3950(void);

void func_002a3318(void) {
    s32 i, k, sum;
    u32 t;
    u8* o;
    u8* base = func_002766d0();
    func_0028be78(D_0035f214, D_0035f5e4->lim);
    func_002fde18(D_0035f5e8 + 0x982c, 0, 32);
    for (i = 0; i < 9; i++) {
        o = D_0035f5e8 + i * 0x1b4 + 0x7974;
        func_00138c10(o, 2);
        *(s32*)(o + 0x198) = 0;
        o = D_0035f5e8 + i * 0x1b4 + 0x88c8;
        func_00138c10(o, 2);
        *(s32*)(o + 0x198) = 0;
        func_00138c10(base + 0xa998 + i * 0x198, 2);
    }
    func_002fde18(base + 0x110a0, 0, 640);
    sum = 0;
    {
        for (i = 0; i < 15; i++) {
            if (D_0035f5e4->ent[i].n) {
                if (sum >= D_0035f5e4->lim) break;
                sum += D_0035f5e4->ent[i].n;
            }
        }
        k = i;
    }
    for (i = 0; i < 9 && k < 15; i++) {
        if (i + D_0035f5e4->lim != sum) continue;
        o = D_0035f5e8 + i * 0x1b4 + 0x7974;
        func_00138c10(o, 72);
        t = func_00295430(k, 1);
        if (func_002954e0(k)) *(void**)(o + 0x198) = func_00192048(t);
        else *(void**)(o + 0x198) = func_0028de08(t, base + i * 64 + 0x110a0, 64);
        if (!D_0035f5e4->ent[k].b0) {
            t = (u32)(D_0035f5e8 + i * 0x1b4 + 0x88c8);
            *(void**)((u8*)t + 0x198) = func_00192048(func_002a43f0() ? D_00374ba0 : D_00374ba4);
        }
        if (func_002954e0(k)) {
            if (D_0035f5e4->ent[k].b2) {
                if (D_0035f5e4->ent[k].b3) t = D_00374b9c;
                else t = D_00374b98;
                func_00138c10(base + i * 0x198 + 0xa998, t);
            }
        }
        sum += D_0035f5e4->ent[k].n;
        {
            s32 j;
            for (j = k + 1; j < 15; j++) {
                if (D_0035f5e4->ent[j].n) break;
            }
            k = j;
        }
    }
    func_002a3648();
    func_002a3950();
}
}
