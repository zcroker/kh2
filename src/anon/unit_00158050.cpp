#include "../common/types.h"

// dk gauge parts (0x158050-0x158450): a gauge sprite with a sound handle (0x158050-0x158138) and
// dk::GAUGE_PARTY (0x158138-0x158450), the party member gauges. Their vtables are retail data
// (0x34a950 and the GAUGE_PARTY one). Each function keeps the declarations of the source it was
// matched in (namespace hN); every external symbol is bound by asm label.

// 158050 .. 1580e0
namespace h0 {
void func_001386e0(u8*, u32, u32, u32, u32, u32) asm("func_001386e0");

void func_00158050(u8* p, u32 a1, u32 a2, u32 a3, u32 a4, u32 x, u32 y) asm("func_00158050");
void func_00158050(u8* p, u32 a1, u32 a2, u32 a3, u32 a4, u32 x, u32 y) {
    func_001386e0(p, a1, a2, a3, a4, y);
    *(u32*)(p + 408) = x;
}

u32 func_001b7e68(...) asm("func_001b7e68");
void func_001b8010(u32, u32, u32, u32, u32) asm("func_001b8010");
void func_001b80d8(u32) asm("func_001b80d8");
void func_001b7f30(u32) asm("func_001b7f30");
void func_00237ad8(u32, u32) asm("func_00237ad8");
void func_00138988(u32) asm("func_00138988");

void func_00158088() asm("func_00158088");
void func_00158088() {
    u32 s[4];
    u32 p = (u32)s;

    s[2] = 0;
    s[1] = 0;
    func_001b7e68(p, (s[0] = 0, 16));
    func_001b8010(p, 1, 71, 0x00070000, 0xffff);
    func_001b80d8(p);
    func_001b7f30(p);
}

void func_001580e0(u32 a0) asm("func_001580e0");
void func_001580e0(u32 a0) {
    u32 s0 = a0;
    if (*(u32*)(a0 + 408) != 0) {
        func_00158088();
        u32 p = s0 + 24;
        u32 m = 0xfffffffd;
        u32 x = *(u32*)(p + 16);
        *(u32*)(p + 16) = x & m;
        func_00237ad8(p, *(u32*)(s0 + 408));
    }
    return func_00138988(s0);
}
}  // namespace h0

// 158138 .. 158300: dk::GAUGE_PARTY
namespace h1 {
u32 func_001391c8(...) asm("func_001391c8");
u32 func_00158290(u32) asm("_ZN2dk11GAUGE_PARTY8getGroupEv");
u32 func_00166cc8(u32) asm("func_00166cc8");
u32 func_00166cf0(u32) asm("func_00166cf0");
s32 func_001a1de0(u32) asm("_Z16u_call4_001a1de0jjjj");
void func_001399c0(u32) asm("func_001399c0");
void func_00139948(u32) asm("func_00139948");

u32 func_00158138(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2dk11GAUGE_PARTY6createEPN2YS3OBJEii");
u32 func_00158138(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 s0 = a0;
    u32 v;

    *(u32*)(a0 + 44) = a3;
    *(u32*)(a0 + 48) = a2;
    *(u32*)(a0 + 52) = a1;
    *(u32*)(a0 + 28) = 0;
    *(u32*)(a0 + 24) = 0;
    *(u8*)(a0 + 32) = 0;
    *(u8*)(a0 + 33) = 0;

    if (a1 != 0) {
        u32 t6 = *(u32*)(*(u32*)(a1 + 1164));
        *(volatile u32*)(a0 + 36) = t6;
        *(volatile u32*)(a0 + 40) = t6;
    } else {
        *(u32*)(a0 + 40) = 0;
        *(u32*)(a0 + 36) = 0;
    }

    v = func_00158290(s0);
    return func_001391c8(s0, 7000, v);
}

u32 isAlertStart(u8* p) asm("_ZN2dk11GAUGE_PARTY12isAlertStartEv");
u32 isAlertStart(u8* p) {
    u32 t4 = *(u32*)(p + 28);
    u32 v0 = 0;
    if (t4 != 1) {
        if (*(u32*)(p + 24) == 1) {
            return 1;
        }
        v0 = 0;
    }
    return v0;
}

u32 isAlertEnd(u8* p) asm("_ZN2dk11GAUGE_PARTY10isAlertEndEv");
u32 isAlertEnd(u8* p) {
    u32 t4 = *(u32*)(p + 28);
    u32 v0 = 0;
    if (t4 == 1) {
        if (*(u32*)(p + 24) != t4) {
            return 1;
        }
        v0 = 0;
    }
    return v0;
}

void func_001581f8(u32 a0) asm("_ZN2dk11GAUGE_PARTY12calcHPStatusEv");
void func_001581f8(u32 a0) {
    u32 s0 = a0;
    u32 p = *(u32*)(a0 + 52);
    *(u32*)(s0 + 28) = *(u32*)(s0 + 24);
    if (func_00166cf0(p) != 0) {
        *(u32*)(s0 + 24) = 2;
        return;
    }
    if (func_00166cc8(*(u32*)(s0 + 52)) != 0) {
        *(u32*)(s0 + 24) = 1;
        return;
    }
    *(u32*)(s0 + 24) = 0;
}

u32 checkMpDrawTrigger(u8* p) asm("_ZN2dk11GAUGE_PARTY18checkMpDrawTriggerEv");
u32 checkMpDrawTrigger(u8* p) {
    s32 v = func_001a1de0(*(u32*)(*(u32*)(p + 52) + 1164));
    u8 old = p[33];
    p[33] = v;
    return old != (u32)v;
}

u32 getGroup(u8* p) asm("_ZN2dk11GAUGE_PARTY8getGroupEv");
u32 getGroup(u8* p) {
    u32 v = *(u32*)(p + 44) + *(u32*)(p + 48);
    return (u32)((s32)v + 3);
}

void func_001582a8(u32 a0) asm("_ZN2dk11GAUGE_PARTY8checkObjEv");
void func_001582a8(u32 a0) {
    u32 s0 = a0;
    u32 v = func_00158290(s0);
    if (*(u32*)(s0 + 52) == 0) {
        return func_001399c0(v);
    }
    if (v != 3) {
        return func_00139948(v);
    }
}
}  // namespace h1

// 158300: GAUGE_PARTY update (pad-driven sub-gauge calls)
namespace h2 {
struct Menu158;
typedef void (*Menu158Fn)(Menu158*);
struct Menu158 { Menu158Fn* vt; u8 pad[40]; u32 f44; u32 f48; u32 f52; };
void func_001581f8(Menu158*) asm("_ZN2dk11GAUGE_PARTY12calcHPStatusEv");
void func_001582a8(Menu158*) asm("_ZN2dk11GAUGE_PARTY8checkObjEv");
s32 func_0013dd48(u32, s32) asm("func_0013dd48");
void func_0013dd78(u32, s32) asm("func_0013dd78");

void func_00158300(Menu158* m) asm("func_00158300");
void func_00158300(Menu158* m) {
    u32 in = m->f44 + m->f48;
    func_001581f8(m);
    if (func_0013dd48(in, 0)) {
        func_0013dd78(in, 0);
        m->vt[6](m);
        func_001582a8(m);
    }
    if (func_0013dd48(in, 1)) {
        func_0013dd78(in, 1);
        if (!m->f52) return;
        m->vt[7](m);
    }
    if (func_0013dd48(in, 2)) {
        func_0013dd78(in, 2);
        if (!m->f52) return;
        m->vt[8](m);
    }
    if (func_0013dd48(in, 3)) {
        func_0013dd78(in, 3);
        if (!m->f52) return;
        m->vt[9](m);
    }
    if (func_0013dd48(in, 4)) {
        func_0013dd78(in, 4);
        if (!m->f52) return;
        m->vt[10](m);
    }
}
}  // namespace h2
