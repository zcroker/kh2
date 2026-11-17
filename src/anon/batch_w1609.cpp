#include "../common/types.h"
extern "C" {
extern u8 D_0035f0b3;
void func_001cd2b8(void);
s32 func_00233e60(void);
s32 func_00233e70(s32);
void func_00234570(s32, s32);
s32 func_00234798(void);
s32 func_002347d8(void);
void func_0023d2c8(s32, s32);
void func_00240360(s32);
void func_00240b48(s32);
s32 func_00240ba0(void);
s32 func_00240bd0(void);
void func_00241450(s32);
void func_002415a0(s32, s32, s32);
void func_00242618(s32, s32);
void func_00242908(void);
void func_00257000(void);
void func_0025ee58(void);
s32 func_00287bc0(void);
void func_00287bd0(s32, s32);
void func_00287c00(s32);
s32 func_00287c10(void);
void func_00287c30(void);
void func_00287c90(s32);
void func_00287cc0(s32);
s32 func_00287cd0(void);
void func_00287d20(s32);
s32 func_00287d30(void);
void func_002b4c88(s32);
void func_002b4ee0(void);
s32 func_002b4fb8(void);
s32 func_002b4ff8(void);
void func_002b5108(s32, s32);
void func_002b5c30(s32);
void func_0025ebb0(void);  // 0x0025ebb0: definition moved into src/anon/unit_0025da20.cpp
struct AllocVt259 { void* (*alloc)(void* self, u32 size, void* ra); };
struct AllocObj259 { AllocVt259* vt; };
struct Holder259 { u8 pad[20]; AllocObj259* al; };
extern Holder259* D_00347f80;
extern AllocObj259* D_0032ba14;
extern u8 D_0035eb98[];
extern u8 D_0035ebb8[];
extern u8* D_0035f664;
extern u8* D_0035f668;
extern void* D_0035f66c;
extern void* D_0035f670;
extern s32 D_0035f674;
extern u8 D_0035f0b2;
extern u8 D_00372e70[], D_00372e78[], D_00372e80[], D_00372e88[], D_00372ec0[], D_00372ec8[];
u8* func_0023ee30(u32 size);
void func_002369a0(u8* p);
void func_0023c008(u8* p);
s32 func_0023f948(s32, s32);
void func_0028d7f0(u8* a, u32 b, u32 c, u32 d, u32 e, u32 f, s32 g, u32 h, u32 i);
void func_0023ef50(u8* p);
void func_0028f280(u32 a, u32 b, u8* c, u8* d, u8* e);
void func_00263960(u32 a, u32 b, u8* c, u8* d, u8* e);
void func_002590b0(u8* a, u32 b, u8* c, u8* d, u8* e, s32 f, u32 g, u32 h);
void func_0023f618(u8*, s32);
s32 func_00192048(u32);
u8* GetLayout259(u8* p) asm("func_0023f1b0");
u32 func_0023c4b8(u8* p, u32 a);
u32 func_00236ca8(u32 p, u32 a);
void func_0028fc78(void* p, u32 a, u32 b, u8* c);
void func_0028fe38(void* p, u32 a, u32 b, u32 c, u32 d);
void func_00290198(void* p, u32 a, u32 b, u32 c, u8* d);
void func_00290368(void* p, u32 a, u32 b, u32 c, u32 d);
void func_0023d2e0(s32*);
void func_00240b90(s32);
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
s32 func_00287bc0(void);
void func_0025a1d0(void);
void func_00259e90(void);

static inline void* Alloc259(u32 size) { return D_0032ba14->vt->alloc(D_0032ba14, size, __builtin_return_address(0)); }

enum E259 { E0, E1, E2 };
void func_00259998(void);  // 0x00259998: definition moved into src/anon/unit_002588e8.cpp
extern s32 D_0035f3d4;
extern s32 D_0035ef68;
extern s32 D_0035ef64;
extern s32 D_0035f03c;
extern s32 D_0035f020;
extern s32 D_0035f010;
u8* func_00257770(void);
void func_0028d8c0(u8*, s32, s32, s32, s32, s32, s32, s32);
void func_0028d980(u8*, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_00257130(void);
void func_00281f30(s32);
void func_00139620(u8*);
void func_0028dcc0(u8*, u8*);
s32 func_002570a0(s32);
s32 func_00263688(s32);
s32 func_002636b0(s32);
s32 func_00281100(s32);
s32 func_00281140(s32, s32);
void func_00288d80(s32, s32, s32, s32, s32, s32, s16*, s16*);
u8* func_002891b8(s32, s32);
s32 func_0023aa78(u8*);
void func_00138c68(u8*, s32, s32);
void func_0028b1e8(s32, s32);
void func_002891f0(s32, s32, s32, s32, s32);
void func_00288f48(s32, s32, s32, s32, s32);
u8* func_00281f20(s32);
s32 func_0027ed48(u16);
void func_0027dee8(s32, s32, s32);
void func_00261000(void)
{
    s16 h[2][4];
    s32 i, j, n, k, cnt;
    u8* base = func_00257770();
    for (i = 0; i < 2; i++)
        for (j = 0; j < 4; j++)
            h[i][j] = 291;
    n = D_0035f3d4;
    u8* a = base + 408;
    u8* b = base + 2068;
    func_0028d8c0(a, n - 1, D_0035ef68, D_0035ef64, D_0035f03c, 299, 300, 0);
    func_0028d980(b, n, D_0035ef68, D_0035ef64, D_0035f03c, 292, -1, -1, 0);
    func_00281f30(func_00257130());
    func_00139620(b);
    func_0028dcc0(b, a);
    *(s32*)(b + 408) = func_00192048(0xb943);
    k = func_002570a0(10);
    if (func_00263688(k) || func_002636b0(k)) cnt = 1;
    else cnt = func_00281100(D_0035f010);
    for (i = 0; i < cnt; i++) {
        func_00288d80(D_0035f020, i, D_0035ef68, D_0035ef64, D_0035f03c, -1, h[0], h[1]);
        u8* p = func_002891b8(D_0035f020, i);
        *(s32*)(p + 392) = -1;
        func_00138c68(p, 0, func_0023aa78(p + 24) * i);
        func_00139620(p);
        func_0028dcc0(p, a);
        *(s32*)(p + 408) = func_00263688(k) ? func_00192048(0xb944) : func_00281140(D_0035f010, i);
    }
    func_0028b1e8(D_0035f020, 1);
    func_002891f0(D_0035f020, 0, 1, 0, 2);
    func_00288f48(D_0035f020, 16, 32, 0, 0);
    s32 t = func_0027ed48(*(u16*)(func_00281f20(func_00257130()) + k * 6));
    func_0027dee8(1, t, func_002636b0(k) ? 0 : 4);
    func_00287cc0(0);
}
}
