#include "../common/types.h"
extern "C" {
struct Ent8 { u8 pad[8]; s16 h; };
u8* func_00257770(void);
void func_00139d78(u8*);
s32 func_0028b038(s32);
void func_0028be78(s32, s32);
s32 func_00257070(s32);
void func_002713a0(s32, s8**, s32*);
s32 func_00257140(s32);
s32 func_002892f8(s32);
u8* func_002891b8(s32, s32);
void func_0028b040(s32);
s32 func_00257158(s32, s32, s32);
void func_00138c10(u8*, s32);
s32 func_00272c20(s32);
s32 func_00192048(u32);
s32 func_00286068(s32);
s32 func_00286160(s32);
extern s32 D_0035ef6c;
extern s32 D_0035f01c;
extern s32 D_0035f04c;
extern u8* D_0035f12c;
extern s8* D_01e21ed8;
extern s32 D_003739ec;
extern s32 D_003739f0;
extern s16 D_003739f8[];
extern s16 D_00373a08[];
extern u16 D_00373a18[];
extern u16 D_00373a28[];

// Sets up the 9 sprite rows and fills them from the current list.
void func_00271ee8(void) {
    s32 vals[8];
    s32 cnt;
    s32 v;
    s32 i;
    u8* b = func_00257770();
    func_00139d78(b);
    s32 nEnt = func_0028b038(D_0035f01c);
    func_0028be78(D_0035f04c, nEnt);
    func_002713a0(func_00257070(25), &D_01e21ed8, &cnt);
    v = func_00257140(0);
    for (i = 0; i < func_002892f8(D_0035f01c); i++)
        func_00138c10(func_002891b8(D_0035f01c, i), D_0035ef6c);
    for (i = 0; i < 9; i++) {
        s32 id = v;
        func_00138c10(b + i * 436 + 24304, id);
        *(s32*)(b + i * 436 + 24712) = 0;
        func_00138c10(b + i * 436 + 3376, D_0035ef6c);
        *(s32*)(b + i * 436 + 3784) = 0;
        func_00138c10(b + i * 408 + 0x87d0, D_0035ef6c);
    }
    func_0028b040(D_0035f01c);
    for (i = 0; i < cnt; i++) vals[i] = func_00272c20(D_01e21ed8[i]);
    s32 lim = ((s8*)D_0035f12c)[4];
    if (func_00257070(25)) lim++;
    if (lim >= 10) lim = 9;
    s32 idx = 0;
    s32 k = 0;
    for (i = 0; i < cnt && k < lim; i++) {
        for (s32 j = 0; j < vals[i] && k < lim; j++, idx++) {
            if (idx < nEnt) continue;
            if (j == 0 || D_01e21ed8[i] == 0) {
                u8* e = b + k * 436 + 3376;
                v = D_00373a08[D_01e21ed8[i]];
                func_00138c10(e, v);
                s8 t = D_01e21ed8[i];
                // pin: the original keeps the label id in a1 and copies it to a0 in the jal delay slot
                register u32 x asm("$5") = D_00373a18[t];
                if (!t) x = D_00373a28[idx];
                *(s32*)(e + 408) = func_00192048(x);
            }
            v = D_003739f8[D_01e21ed8[i]];
            func_00138c10(func_002891b8(D_0035f01c, k), v);
            s8 type = D_01e21ed8[i];
            s32 r;
            if (type != 3) r = func_00257140(func_00257158(((Ent8*)(D_0035f12c + idx * 8))->h, 1, type == 1)); else r = func_00257140(0);
            u8* f = b + k * 436 + 24304;
            func_00138c10(f, r);
            *(u8**)(f + 408) = b + idx * 32 + 0xae10;
            if (func_00286068(((Ent8*)(D_0035f12c + idx * 8))->h))
                func_00138c10(b + k * 408 + 0x87d0, func_00286160(((Ent8*)(D_0035f12c + idx * 8))->h) ? D_003739f0 : D_003739ec);
            k++;
        }
    }
}

extern s32 D_0035ed20;
extern u8* D_0035ed40;
extern u8 D_00371ab8[];
extern u8 D_00371ac0[];
extern u8 D_00371cb8[];
extern u8 D_00371cc0[];
s32 func_002891e8(s32);
s32 func_002474e0(s32);
void func_0028dcc0(void*, void*);
void func_002fde18(void*, s32, s32);
s32 func_00105c30(void);
s32 func_00192cc0(u8*, u8*, s32);
s32 func_00192b30(s32);
void func_00192c90(s32, u8*);
s32 func_00192c40(s32, u8*);
s32 func_0023aa98(void*);
s32 func_002469a0(s32);
s32 func_00246840(void);
void func_00138c68(void*, s32, s32);
u32 func_0028af88(s32);
void func_0028af18(s32, u32);
// true for the Japanese-style layouts (system language 1 or 8)
static inline u8 isjp() { u8 r = 0; if (func_00105c30() == 1 || func_00105c30() == 8) r = 1; return r; }
// Refreshes the selection rows and the gauge/caption of the selected entry.
void func_00247580(u8 flag) {
    s32 cnt;
    s32 k;
    s32 sel = func_002891e8(D_0035ed20);
    cnt = func_002892f8(D_0035ed20);
    u8* e;
    s32 c;
    if (flag) {
        for (s32 i = 0; i < cnt; i++) {
            e = D_0035ed40 + i * 408 + 11112;
            c = func_002474e0(i) ? 31 : 96;
            func_00138c10(e, c);
        }
    }
    u8* cap = D_0035ed40 + 436;
    if (func_002474e0(sel)) {
        e = D_0035ed40 + sel * 408 + 11112;
        if (flag) {
            func_00138c10(cap, 33);
            func_00138c10(e, 32);
            func_0028dcc0(cap, D_0035ed40 + func_002891e8(D_0035ed20) * 408 + 11112);
        }
        u8* buf = D_0035ed40 + 14632;
        c = ((s8*)(sel + (u32)D_0035ed40))[14664];
        if (isjp()) {
            k = func_00192b30(func_00192cc0(buf, D_00371ab8, c + 1));
            func_00192c90(func_00192048(19468), buf + k);
        } else {
            func_00192cc0(buf + func_00192c40(func_00192048(19468), buf), D_00371ac0, c + 1);
        }
        s32 v = func_0023aa98(D_0035ed40 + sel * 408 + 7872);
        k = func_002469a0(sel);
        cnt = (func_00246840() ? D_00371cc0 : D_00371cb8)[k];
        func_00138c68(e, (s32)((f32)v / (f32)(cnt - 1) * (f32)c), 0);
    } else {
        func_00138c10(cap, 96);
        func_002fde18(D_0035ed40 + 14632, 0, 32);
    }
    u32 f = func_0028af88(D_0035ed20);
    if (func_002474e0(sel)) f |= 0xc0000;
    else f &= 0xfff3ffff;
    func_0028af18(D_0035ed20, f);
}
}
