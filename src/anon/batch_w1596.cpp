#include "../common/types.h"

extern "C" {

// ---- 00285828
struct O285828 { s32 a[20]; s32 b[3]; s32 c[18]; s32 d[9]; s32 e; u8 f[0x11c - 0xcc]; };
extern O285828* volatile D_0035f2e4;
s32 func_00103570();
O285828* func_001063c0(s32, s32);
void func_00323ad0(void*);
void func_002fde18(void*, s32, s32);
void func_002859c0();
void func_00285828() {
    s32* p; s32 n;
    O285828* o = func_001063c0(0x11c, func_00103570());
    p = o->a; n = 19; do { *p = 0; n--; p++; } while (n >= 0);
    p = o->b; n = 2; do { *p = 0; n--; p++; } while (n >= 0);
    p = o->c; n = 17; do { *p = 0; n--; p++; } while (n >= 0);
    p = o->d; n = 8; do { *p = 0; n--; p++; } while (n >= 0);
    o->e = 0;
    func_00323ad0(o->f);
    D_0035f2e4 = o;
    func_002fde18(D_0035f2e4, 0, 0x11c);
    func_002859c0();
}

// ---- 002822c0
struct E2822c0 { u16 id; u8 kind; u8 z; s16 v; };
struct L2822c0 { union { s32 n; s16 nh; }; E2822c0 e[682]; s32 pad; s32 h; s32 m; s32 sel; };
void func_00281f90(L2822c0*);
s32 func_002811f8(s32, s32);
u16* func_001a8110(u16*);
s32 func_00282228(L2822c0*, u8, s32);
u8 func_001a3570(u16);
s32 func_00282ec0(u16);
void func_002822c0(L2822c0* l, s32 a1, s32 a2) {
    u16* it = 0;
    E2822c0* e = l->e;
    func_00281f90(l);
    l->m = 0;
    if (a1) l->sel = func_002811f8(l->h, a1 - 1);
    l->n = 0;
    for (;;) {
        it = func_001a8110(it);
        if (!it) break;
        if (!func_00282228(l, ((u8*)it)[2], a2)) continue;
        u8 k = func_001a3570(it[0]);
        if (!k) continue;
        if (func_00282ec0(it[0])) continue;
        e->kind = k;
        e->id = it[0];
        e->z = 0;
        e->v = 999;
        e++;
        l->n++;
    }
}

// ---- 00273a28
struct S273a28 { u8 pad[4]; s8 n; };
extern S273a28* D_0035f12c;
extern s32 D_0035f01c;
extern s32 D_0035f04c;
s32 func_00257070(s32);
s32 func_002891e8(s32);
s32 func_0028b038(s32);
s32 func_002892f8(s32);
void func_0028bfc0(s32, s32);
void func_0028be78(s32, s32);
void func_002891f0(s32, s32, s32, s32, s32);
void func_0028afd0(s32, s32);
void func_0028af90(s32, s32);
void func_00273a28() {
    s32 n = D_0035f12c->n;
    if (func_00257070(25)) n++;
    s32 a = func_002891e8(D_0035f01c);
    s32 b = func_0028b038(D_0035f01c);
    s32 c = func_002892f8(D_0035f01c);
    if (a == 0) {
        if (b != 0) b--;
    } else if (b != 0 && n < b + c) {
        b--;
    } else if (a != 0 && a >= n) {
        a--;
    }
    func_0028bfc0(D_0035f04c, n);
    func_0028be78(D_0035f04c, b);
    func_002891f0(D_0035f01c, a, 0, -1, -1);
    func_0028afd0(D_0035f01c, b);
    func_0028af90(D_0035f01c, n);
}

}
