#include "../common/types.h"
struct W1610Cur { u8 pad[0x44]; s16 x, y, xmin, xmax, ymin, ymax; };
struct W1610Pad { u64 btn; u8 pad[0x28]; f32 lx; f32 ly; u8 pad2[4]; f32 mag; };
struct W1610Ob { u8 pad[408]; s32 id; };
struct W1610Sl { u8 pad[408]; u8* name; u8 pad2[432 - 412]; s32 on; };
struct W1610Mdl;
struct W1610MdlVt { u8 pad[24]; void (*set)(W1610Mdl*, s32, u32, u32, s32, s32, s32); };
struct W1610Mdl { W1610MdlVt* vt; };
struct W1610Fx { u8 pad[12]; u16 id; u16 sub; u16 fl; s16 x0; s16 y0; s16 z0; s16 x1; s16 y1; f32 s0; f32 s1; };
union W1610Fl { u16 w; struct { u16 v : 10; u16 pad : 2; u16 on : 1; u16 hi : 1; u16 r : 2; } b; };
struct W1610Tb { u8 pad[8]; s16 idx[1]; };
extern "C" {
union W1610CU { W1610Cur* p; s16 h; }; extern W1610CU D_0035f5d4;
extern u8* D_0035f5d8;
s32 func_00139d78(void*);
void func_00138c68(void*, s32, s32);
void func_002a16b8(void);
void func_002a17e8(void);
void func_002a1220(void);
void func_002a13e0(W1610Pad* p) {
    if (!func_00139d78(D_0035f5d8 + 0x330)) return;
    u64 b = p->btn;
    s32 x = D_0035f5d4.p->x;
    s32 y = D_0035f5d4.p->y;
    if (b & 0x40) {
        if (p->mag != 0.0f && p->lx < 0.0f) {
            x += (s32)(p->lx * 6.0f - 0.5f);
        } else {
            if (D_0035f5d4.p->xmin < x) x -= 3;
        }
        if (x < D_0035f5d4.p->xmin) x = D_0035f5d4.p->xmin;
    } else if (b & 0x80) {
        if (p->mag != 0.0f && 0.0f < p->lx) {
            x += (s32)(p->lx * 6.0f + 0.5f);
        } else {
            if (x < D_0035f5d4.p->xmax) x += 3;
        }
        if (D_0035f5d4.p->xmax < x) x = D_0035f5d4.p->xmax;
    }
    if (b & 0x10) {
        if (p->mag != 0.0f && p->ly < 0.0f) {
            y += (s32)(p->ly * 6.0f - 0.5f);
        } else {
            if (D_0035f5d4.p->ymin < y) y -= 3;
        }
        if (y < D_0035f5d4.p->ymin) y = D_0035f5d4.p->ymin;
    } else if (b & 0x20) {
        if (p->mag != 0.0f && 0.0f < p->ly) {
            y += (s32)(p->ly * 6.0f + 0.5f);
        } else {
            if (y < D_0035f5d4.p->ymax) y += 3;
        }
        if (D_0035f5d4.p->ymax < y) y = D_0035f5d4.p->ymax;
    }
    if (x != D_0035f5d4.p->x || y != D_0035f5d4.p->y) {
        func_00138c68(D_0035f5d8 + 0x330, x, y);
        D_0035f5d4.p->x = x;
        D_0035f5d4.p->y = y;
    }
    func_002a16b8();
    func_002a17e8();
    func_002a1220();
}
extern s32 D_0035f01c;
s32 func_00289380(s32);
s32 func_00287cd0(void);
s32 func_00287c10(void);
s32 func_00271ec8(void);
s32 func_0028f930(s32);
s32 func_00257970(void);
s32 func_00289310(s32);
void func_00287f90(s32);
void func_00271e80(void);
void func_00287c30(void);
void func_0028f7e8(s32);
void func_002551b8(void);
void func_0026f388(void);
s32 func_0028ae28(s32, s32);
void func_0028ab20(s32);
void func_0028fa98(s32);
void func_00272c90(s32);
void func_00287c90(s32);
s32 func_0028afa8(s32);
void func_00273e88(void);
s32 func_00287df0(s32, s32, s32, void (*)(void), s32);
s32 func_00242848(s32);
W1610Ob* func_002891b8(s32, s32);
void func_0028fb68(s32, s32);
void func_00263c60(void);
void func_00271e08(void);
void func_00287c00(s32);
s32 func_00257070(s32);
s32 func_002891e8(s32);
void func_00257050(s32, s32, s32);
s32 func_00288040(void);
void func_00288018(void);
void func_00287da0(void);
void func_0028f6f0(s32);
void func_0026f0a0(void) {
    s32 r = func_00289380(D_0035f01c);
    s32 v;
    s32 st = func_00287cd0();
    if (st == 2) {
        v = func_00287c10();
        if (func_00271ec8() || (v == 0 && func_0028f930(0)) || func_00257970()) {
            if (r != -1 || func_00289310(D_0035f01c)) {
                func_00287f90(0);
                func_00271e80();
            }
        } else {
            func_00287c30();
            if (v == 0) {
                func_0028f7e8(0);
                func_002551b8();
            } else if ((u32)(v - 26) < 2) {
                func_0026f388();
            }
        }
        return;
    }
    if ((r != -1 || func_00289310(D_0035f01c)) && func_0028ae28(D_0035f01c, 0) == 0) {
        func_0028ab20(D_0035f01c);
        func_0028fa98(-1);
    }
    if (st == 0 && func_0028ae28(D_0035f01c, 0)) {
        func_00272c90(1);
        func_00287c90(1);
    }
    {
        v = func_0028afa8(D_0035f01c);
        if (func_00242848(func_00287df0(r, func_00289310(D_0035f01c), 1, func_00273e88, 1)) == 0) {
            switch (r) {
            case -2: {
                func_00263c60();
                func_0028f6f0(0);
                func_00271e08();
                func_00287c90(1);
                func_00287c00(0);
                v = func_00257070(25);
                if (func_002891e8(D_0035f01c) != v) func_00257050(26, 0, 0);
                func_00257050(25, func_002891e8(D_0035f01c), 0);
                break;
            }
            default: {
                if (r < 0 || r >= v) break;
                v = 26;
                if (r) v = 27;
                func_0028fb68(1, func_002891b8(D_0035f01c, r)->id);
                func_00263c60();
                func_00271e08();
                func_00287c90(1);
                func_00287c00(v);
                v = func_00257070(25);
                if (func_002891e8(D_0035f01c) != v) func_00257050(26, 0, 0);
                func_00257050(25, func_002891e8(D_0035f01c), 0);
                break;
            }
            case -4: {
                func_00287da0();
                v = func_00257070(25);
                if (func_002891e8(D_0035f01c) != v) func_00257050(26, 0, 0);
                func_00257050(25, func_002891e8(D_0035f01c), 0);
                break;
            }
            case -1:
                break;
            }
        }
    }
    if (func_00288040()) {
        func_00288018();
    }
}
extern s32 D_0035f020;
s32 func_002630d8(void);
s32 func_00262e30(void);
void func_00262ff8(void);
void func_00262cb8(void);
s32 func_00287bc0(void);
void func_0028b1e8(s32, s32);
void func_0028af18(s32, s32);
void func_0025ffd0(void);
void func_00260808(void);
s32 func_00263160(void);
void func_00263188(void);
s32 func_002638e0(s32);
s32 func_00263720(s32);
void func_00242618(s32, s32);
void func_00263778(s32);
void func_00262fa0(void);
void func_00262c40(void);
void func_00257728(void);
void func_00287bd0(s32, s32);
void func_002615b0(void);
void func_00287cc0(s32);
void func_0027e6e0(void);
void func_002612c8(void) {
    s32 r = func_00289380(D_0035f020);
    s32 st = func_00287cd0();
    if (st == 2) {
        s32 m = func_00287c10();
        s32 v = func_002630d8();
        if (!v && m == 10) v = func_00262e30();
        if (v) {
            if (r != -1 || func_00289310(D_0035f020)) {
                func_00287f90(0);
                func_00262ff8();
                if (m == 10) func_00262cb8();
            }
        } else {
            func_00287c30();
            r = func_00287bc0();
            func_0028b1e8(D_0035f020, 0);
            func_0028af18(D_0035f020, 115);
            if (r == 10) func_0025ffd0();
            else if (r == 11) func_00260808();
        }
        return;
    }
    if ((r != -1 || func_00289310(D_0035f020)) && func_00263160() == 0) {
        func_00263188();
    }
    if (st == 0 && func_00263160()) {
        func_00287c90(1);
    }
    if ((r >= 0 && func_002638e0(r)) || func_00242848(func_00287df0(r, func_00289310(D_0035f020), 1, (void (*)(void))func_002638e0, 1)) == 0) {
        switch (r) {
        case -2:
            func_00262fa0();
            func_00287c90(1);
            func_00287c00(11);
            break;
        default:
            if (func_00263720(r)) {
                func_00242618(17, 1);
                func_00263778(r);
                func_00262fa0();
                func_00262c40();
                func_00287c90(1);
                func_00257728();
                func_00287c00(10);
            } else {
                func_00242618(8, 1);
                func_00287bd0(13, 0);
                func_002615b0();
                func_00287cc0(1);
            }
            break;
        case -4:
            func_0027e6e0();
            func_00287da0();
            break;
        case -1:
            break;
        }
    }
    if (func_00288040()) {
        func_00288018();
    }
}
extern u8 D_00374498[];
extern u8 D_003744a0[];
s32 func_001a1728(s32, s32);
void func_001a17c8(s32);
s32 func_00291370(u8*, s32);
s32 func_0023aa18(void*);
s32 func_0023aa38(void*);
void func_0028dcc0(void*, void*);
void func_00138c10(void*, s32);
void func_00192cc0(u8*, u8*, s32);
s32 func_002920c0(u8*, s32*, s32, s32, s32);
s32 func_00292148(u8*, s32*, s32, s32, s32);
s32 func_002921d0(u8*, s32*, s32, s32, s32);
s32 func_00292258(u8*, s32*, s32, s32, s32);
s32 func_002922e0(u8*, s32*, s32, s32, s32, s32);
void func_00291de0(u8* w, s32 mode, s32 p2, s32 p3, s32 p4, s32 p5, s32 mask) {
    s32 h = func_001a1728(p4, p5);
    if (mode != 2) func_00291370(w, 2);
    s32 n = 0;
    for (s32 i = 0; i < 9; i++) {
        if (!((mask >> i) & 1)) continue;
        if (i == 8) continue;
        W1610Sl* s;
        if (mode == 2) s = (W1610Sl*)(w + n * 436 + 2184);
        else s = (W1610Sl*)(w + n * 436 + 4);
        s32 k = n + 10;
        s32 x = func_0023aa18((u8*)s + 24);
        s32 y = func_0023aa38((u8*)s + 24);
        W1610Sl* d = (W1610Sl*)(w + k * 436 + 4364);
        func_0028dcc0(d, s);
        func_00138c68(d, x, y);
        s32 sel = -1;
        s32 res = 1;
        switch (i) {
        case 0: res = func_002920c0(w, &sel, p2, p3, h); d->on = 1; break;
        case 1: res = func_00292148(w, &sel, p2, p3, h); d->on = 1; break;
        case 2: res = func_002921d0(w, &sel, p2, p3, h); d->on = 1; break;
        case 3: res = func_00292258(w, &sel, p2, p3, h); d->on = 1; break;
        case 4: res = func_002922e0(w, &sel, p2, p3, 1, h); d->on = 1; break;
        case 5: res = func_002922e0(w, &sel, p2, p3, 2, h); d->on = 1; break;
        case 6: res = func_002922e0(w, &sel, p2, p3, 3, h); d->on = 1; break;
        case 7: res = func_002922e0(w, &sel, p2, p3, 4, h); d->on = 1; break;
        case 8: default: { s32 one = 1; d->on = one; } break;
        }
        s32 a = 6;
        if (res != 2) a = res ? 0 : 3;
        func_00138c10(d, func_00291370(w, a));
        if ((u32)(i - 4) < 4) func_00192cc0(w + k * 8 + 10904, D_00374498, sel);
        else func_00192cc0(w + k * 8 + 10904, D_003744a0, sel);
        n++;
        d->name = w + k * 8 + 10904;
    }
    func_001a17c8(h);
}
extern W1610Tb* D_0035f5ac;
extern s16 D_0035f5b6;
extern W1610Mdl* D_0035f5bc;
u8* func_002766d0(void);
s32 func_0029e2f8(s32);
s32 func_00292630(void);
s32 func_00293200(void);
s32 func_00276638(s32);
W1610Fx* func_0029da68(s32);
void func_0029e3e0(u16);
void func_0029e170(s32);
W1610Mdl* func_00287dc0(void);
void func_0023d808(W1610Mdl*, s32);
s32 func_0029ec98(u16);
void func_0023e858(W1610Mdl*, s32, f32);
void func_0023e8d8(W1610Mdl*, s32, f32);
void func_0023e918(W1610Mdl*, s32, f32, f32, f32);
void func_0023e9c8(W1610Mdl*, s32, u8*);
void func_0023ec38(W1610Mdl*, s32);
void func_0023eb50(W1610Mdl*, s32, s32);
s32 func_0029e7b0(u16);
void func_0023e660(W1610Mdl*, s32, s32);
void func_0029e4c8(s32 n) {
    u8* base = func_002766d0();
    if (func_0029e2f8(n)) return;
    if (func_00292630()) return;
    if (func_00293200()) return;
    s32 k = func_00276638(15);
    W1610Fx* fx = func_0029da68(D_0035f5ac->idx[k]);
    if (D_0035f5b6 < 0) {
        func_0029e3e0(fx->id);
        return;
    }
    func_0029e170(n);
    W1610Mdl* m;
    if (n == 0) {
        m = func_00287dc0();
        if (!func_00139d78(m)) func_0023d808(m, 30051);
    } else {
        m = D_0035f5bc;
        if (!func_00139d78(m)) func_0023d808(m, 30056);
    }
    f32 y = -100.0f;
    f32 z;
    f32 s;
    s32 a, b;
    if (n == 0) {
        z = fx->z0;
        a = fx->x0;
        b = fx->y0;
        s = fx->s0;
    } else {
        a = fx->x1;
        b = fx->y1;
        s = fx->s1;
        z = 0.0f;
    }
    u16 id = fx->id;
    if (func_0029ec98(id)) {
        y = (n == 0 ? fx->s0 : fx->s1) + -100.0f;
        s = 1.0f;
    }
    m->vt->set(m, 0, id | 0x30000000, fx->sub, 2, a, b);
    func_0023e858(m, 0, y);
    func_0023e8d8(m, 0, z);
    func_0023e918(m, 0, s, s, s);
    func_0023e9c8(m, 0, base + n * 408 + 17712);
    func_0023ec38(m, 1);
    W1610Fl fl;
    fl.w = fx->fl;
    s32 v = fl.b.v;
    if (fl.w & 0x1000) {
        if (fl.w & 0x2000) v = v << 10;
        else v = v << 20;
    }
    func_0023eb50(m, 0, v);
    s32 r = func_0029e7b0(id);
    if (r >= 0) func_0023e660(m, 0, r);
}
}
