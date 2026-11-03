// func_0029c5c8: register pins + empty asm (live-range keepers); see coord/asm_review.tsv.
#include "../common/types.h"
extern "C" {
struct S29c { u8 p0[5]; s8 b5; };
extern s32 D_0035f200;
extern S29c* D_0035f5ac;
s32 func_00289380(s32);
s32 func_00287cd0(void);
s32 func_00287bc0(void);
s32 func_0029e2f8(s32);
void func_0029e4c8(s32);
s32 func_00292630(void);
void func_0029e430(void);
void func_00287c30(void);
void func_0028af18(s32, s32);
void func_0028af28(s32, s32);
s32 func_0028af88(s32);
void func_0028b1e8(s32, s32);
s32 func_0028afa8(s32);
void func_0028b218(s32, s32);
void func_0028b248(s32, s32);
void func_0029ea30(void);
void func_00287cc0(s32);
void func_00287f90(s32);
void func_0029e298(s32);
s32 func_00289310(s32);
s32 func_0029e0f8(void);
void func_0029e148(void);
void func_00287c90(s32);
void func_00242618(s32, s32);
void func_0029e050(void);
void func_0029e258(s32);
void func_00287c00(s32);
void func_0029e808(s32);
s32 func_00288040(void);
void func_00288018(void);
void func_0029c5c8(void)
{
    register s32 r asm("$17") = func_00289380(D_0035f200);
    s32 mode = func_00287cd0();
    register s32 m asm("$18") = func_00287bc0();
    register s32 i asm("$16");
    if (mode != 2 && !func_0029e2f8(1)) func_0029e4c8(1);
    if (__builtin_expect(mode == 2, 1)) {
        for (i = 0; i < 2; i++)
            if (func_0029e2f8(i)) goto found;
        if (func_00292630()) return;
        func_0029e430();
        func_00287c30();
        m = func_00287bc0();
        func_0028af18(D_0035f200, 115);
        if (m == 16 || m == 19 || m == 22) {
            s32 f;
            func_0028af28(D_0035f200, 16);
            f = func_0028af88(D_0035f200);
            {
                s32 g = f;
                S29c* q = D_0035f5ac;
                s32 h = f | 0xc000;
                if (q->b5 >= 2) g = h;
                asm("" : "+r"(g) : "r"(h), "r"(q));
                func_0028af18(D_0035f200, g | 0x200);
            }
            func_0028b1e8(D_0035f200, 0);
            if (func_0028afa8(D_0035f200) >= 2) {
                func_0028b218(D_0035f200, 1);
                func_0028b248(D_0035f200, 7);
            }
            func_0029ea30();
            func_00287cc0(0);
        }
        return;
    found:
        if (r != -1) {
            func_00287f90(0);
            for (i = 0; i < 2; i++) func_0029e298(i);
        }
    } else {
        if ((r != -1 || func_00289310(D_0035f200)) && !func_0029e0f8()) func_0029e148();
        if (mode == 0 && func_0029e0f8()) func_00287c90(1);
        if (r == -2) func_00242618(3, 1);
        switch (r) {
        case -2: {
            s32 id = 16;
            if (m != 17) id = (m != 17) ? 22 : 16;
            asm("" : : "r"(m));
            func_0029e050();
            func_0029e258(1);
            func_00287c00(id);
            func_00287cc0(2);
            break;
        }
        case -11: case -10: case -9: case -8: case -7: case -6: case -5: case -4: case -3: case -1:
            break;
        case -13:
        case -12:
            func_0029e808(r);
            break;
        }
        if (func_00288040()) func_00288018();
    }
}
}

// func_0020e198: empty asm keeps the shifted value live so the srl is not tied to a1; see coord/asm_review.tsv.
struct B1882 { u8 b[96]; };
struct BF4 { u32 :6; u32 f:26; };
struct BF28 { u32 :5; u32 f:14; u32 :13; };
struct T1882 {
    u8 p0[4]; union { u32 w4; BF4 bf4; }; u32 w8; u8 p12[6]; u8 b18; u8 b19; u16 h20; s16 h22; u16 h24; u8 p26[2]; union { u32 w28; BF28 bf28; }; u8 p32[8]; u8 b40; u8 b41; u8 b42; u8 b43;
};
struct O1882 { u8 p0[15]; u8 b15; T1882 t; };
extern "C" {
extern u8 D_00359100[];
void func_002f28b8(B1882*, s32, s32, u8, s32, s32, s32, s32);
void func_002f25a0(s32, s32);
void func_003058a0(s32);
void func_002f2be0(B1882*, u8*);
void func_0020e198(O1882* o) {
    T1882* t = &o->t;
    u8* p = 0;
    B1882 a, b;
    if (t->w8) {
        u8 a3 = D_00359100[t->b19];
        s16 a1 = t->h24 & 0x3fff;
        s32 a2, t0, t1;
        if (o->b15 == 111) {
            a2 = t->b40 >> 2; t0 = t->b42 << 4; t1 = t->b43 << 4;
        } else {
            a2 = t->h20 >> 6; t0 = 0; t1 = 0;
        }
        func_002f28b8(&a, a1, a2, a3, t0, t1, (s16)t->h20, t->h22);
        func_002f25a0(0, 0);
        func_003058a0(0);
        func_002f2be0(&a, p = (u8*)t + 48);
    }
    if (t->w4) {
        u8 i3 = t->b18;
        u32 w = t->w28 >> 5;
        u8 c3 = D_00359100[i3];
        u32 c1 = w & 0x3fff;
        s16 c3x = t->bf4.f;
        asm("" : "+r"(c1) : "r"(w));
        func_002f28b8(&b, c1, 1, c3, 0, 0, 16, c3x);
        func_002f25a0(0, 0);
        func_003058a0(0);
        p += t->w8;
        func_002f2be0(&b, p);
    }
}
}
