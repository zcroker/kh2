#include "../common/types.h"
extern "C" {
extern u32 D_0035f01c;
extern u32 D_0035f04c;
u8* func_00257770(void);
s32 func_0028b038(u32);
void func_0028be78(u32, s32);
s32 func_00257140(s32);
s32 func_002892f8(u32);
s32 func_002570a0(s32);
u32 func_00272b60(s32);
void func_00138c10(u8*, s32);
void func_00272758(void);
void func_002728c8(void);
void func_00272938(void);
void func_00272a00(void);
void func_00272a70(void);
void func_002725d8(void) {
    s32 i = 0;
    u8* p = func_00257770() + 24740;
    func_0028be78(D_0035f04c, func_0028b038(D_0035f01c));
    s32 s = func_00257140(0);
    func_002892f8(D_0035f01c);
    for (; i < func_002892f8(D_0035f01c); i++) {
        func_00138c10(p, s);
        *(u32*)(p + 408) = 0;
        p += 436;
    }
    switch (func_00272b60(func_002570a0(26))) {
    case 0: func_00272758(); break;
    case 1: func_002728c8(); break;
    case 2: func_00272938(); break;
    case 3: func_00272a00(); break;
    case 4: func_00272a70(); break;
    }
}
extern u32 D_0035f010;
u32 func_00269508(s32);
u32 func_00257130(void);
s32 func_002827e0(u32, s32);
u8* func_00281f20(u32);
u32 func_0026acb8(u32);
s32 func_002695a0(s32);
u32 func_0026ad68(s32, u32);
u32 func_0026ae20(s32, u32);
u32 func_0026aea8(s32, u32);
u32 func_0026af30(s32, u32);
s32 func_00257070(s32);
void func_00281058(u32, s32);
void func_0026ab18(u32 a0) {
    s32 n[5];
    u32 r = 0;
    s32 s;
    s32 c = func_002570a0(2);
    u32 m = func_00269508(c);
    for (s32 i = 0; i < 5; i++) { s32 v = func_002827e0(func_00257130(), i); n[i] = v; }
    if (*(u16*)(func_00281f20(func_00257130()) + c * 6) == a0) return;
    switch (m) {
    case 0: r = func_0026acb8(a0); break;
    case 1: r = func_0026ad68(func_002695a0(c), a0); break;
    case 2: s = n[0] + n[1]; r = func_0026ae20(c - s, a0); break;
    case 3: s = n[0] + n[1]; s += n[2]; r = func_0026aea8(c - s, a0); break;
    case 4: s = n[0] + n[1]; s += n[2] + n[3]; r = func_0026af30(c - s, a0); break;
    }
    if (r) func_00281058(D_0035f010, func_00257070(1));
}
extern u32 D_0035f654;
s32 func_0028db48(u32);
s32 func_00287cd0(void);
void func_00287cc0(s32);
s32 func_00240ba0(void);
s32 func_00287d30(void);
s32 func_00233e70(s32);
s32 func_00234888(s32, s32);
s32 func_002348a8(s32, s32);
s32 func_00234848(s32, s32);
s32 func_00234868(s32, s32);
void func_002b5108(s32, s32);
void func_00287d20(s32);
void func_00240bb0(s32);
s32 func_00288040(void);
void func_00288018(void);
void func_00287bd0(s32, s32);
void func_00241450(s32);
void func_002b4c88(s32);
void func_00234570(s32, s32);
void func_0025dde8(void) {
    if (!func_0028db48(D_0035f654)) return;
    if (func_00287cd0() == 0) func_00287cc0(1);
    s32 slot = func_00240ba0();
    switch (func_00287d30()) {
    case 0:
        if (!func_00233e70(0)) {
            s32 n = func_00234888(slot, 0);
            s32 m;
            switch (func_002348a8(slot, 0)) {
            case 4:
                func_002b5108(0x8aae, slot);
                n = -1;
                m = 6;
                break;
            default:
                if (func_00234848(slot, 0) == 2) goto ok;
            case 3:
                func_002b5108(0xb85d, slot);
                n = -1;
                m = 2;
                break;
            ok:
                m = 5;
                if (func_00234868(slot, 0)) {
                    func_002b5108(0x8a89, slot);
                    m = 1;
                }
                break;
            }
            func_00287d20(m);
            func_00240bb0(n);
        }
        break;
    case 1:
        func_00287bd0(4, 0);
        func_00287d20(10);
        func_00241450(1);
        break;
    case 2:
        func_002b4c88(0);
        func_00287bd0(5, 0);
        func_00234570(slot, 0);
        break;
    case 5:
        func_00287bd0(11, 0);
        break;
    case 6:
        func_002b4c88(0);
        func_00287bd0(7, 0);
        func_00234570(slot, 0);
        break;
    }
    if (func_00288040()) func_00288018();
}
}
