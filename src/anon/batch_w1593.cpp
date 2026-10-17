#include "../common/types.h"
extern "C" {

typedef void (*VF1593)(void*);
struct VT1593 { void* f[8]; };
struct Obj1593 { VT1593* vt; };

// ---- 0026ebc0
struct Big1593 { Obj1593 o; u8 pad[0x1b4 - 4]; };
s32 func_00139d78(void*);
void func_0026e340();
void func_0028abe0(void*);
s32 func_0028acc8(void*);
s32 func_0028d6e8(void*);
extern Big1593* D_0035f104;
extern void* D_0035f10c;
extern Obj1593* D_0035f110;

void func_0026ebc0(void) {
    s32 i;
    if (func_0028acc8(D_0035f10c)) func_0028abe0(D_0035f10c);
    for (i = 0; i < 3; i++) {
        if (func_00139d78(&D_0035f104[i])) {
            ((VF1593)D_0035f104[i].o.vt->f[5])(&D_0035f104[i]);
        }
    }
    if (func_0028d6e8(D_0035f110)) ((VF1593)D_0035f110->vt->f[5])(D_0035f110);
    func_0026e340();
}

// ---- 00258630
struct MenuMode1593 { u32 a; u32 list; };
MenuMode1593* getMenuMode1593() asm("_Z11getMenuModev");
s32 func_00102a38(u32, u32);
void func_00102818(u32, u32, u32, u32, u32);
void func_001039f8();
void func_002530c8();
void func_00258a30();
void func_00287ad0();
s32 func_00287db0();
extern u8 D_002586e0[];
extern s16 D_0035f06c;

s32 func_00258630(void) {
    u32 list = getMenuMode1593()->list;
    u32 key = (u32)D_002586e0;
    if (func_00102a38(list, key)) return 0;
    if (D_0035f06c < 0) {
        func_00258a30();
        func_001039f8();
        return 1;
    }
    if (func_00287db0()) func_00287ad0();
    func_002530c8();
    func_00102818(getMenuMode1593()->list, 0, 1999, key, 0x1000);
    return 0;
}

// ---- 002695a0
u32 func_00257130();
s32 func_002827e0(u32, s32);
s32 func_002813b8();
s32 func_00281420();

s32 func_002695a0(s32 a) {
    s32 v[5];
    s32 i, n;
    s32 m;
    for (i = 0; i < 5; i++) v[i] = func_002827e0(func_00257130(), i);
    i = 0;
    m = func_002813b8() & func_00281420();
    a -= v[0];
    n = 0;
    for (; i < 7; i++) {
        if ((u8)((m >> i) & 1)) {
            if (a == n) return i;
            n++;
        }
    }
    return i;
}

// ---- 0028abe0 Tz::Select::Destroy
union ItemU1593 { Obj1593* p; s16 h; u8 c; };
struct Sel1593 { u32 a; s16 n; u8 pad[0x22]; ItemU1593* items; };
void sel_destroy1593(Sel1593* p) asm("_ZN2Tz6Select7DestroyEz");
void sel_destroy1593(Sel1593* p) {
    s32 i;
    if (!func_0028acc8(p)) return;
    for (i = 0; i < p->n; i++) {
        if (p->items[i].p) {
            if (func_00139d78(p->items[i].p)) ((VF1593)p->items[i].p->vt->f[5])(p->items[i].p);
            else p->items[i].p = 0;
        }
    }
}

// ---- 0028c2c8
struct S28c2c8 { u8 pad[184]; u32 flags; void Set() { flags |= 8; } void Clr() { flags &= ~8; } };
struct W28c2c8 { u8 pad[24]; S28c2c8 sub; u8 pad2[436 - 24 - 188]; u32 f436; };
struct P28c2c8 { u8 pad[14080]; s32 free[32]; s32 n; };
extern P28c2c8* D_0035f3c4;
union C28c2c8 { s32 i; u32 u; };
extern C28c2c8 D_0035f3cc;
void func_0028c0a0(W28c2c8*, u32, u32, u8*, u32, u32);
W28c2c8* func_0028c2c8(u32 h, u8* z, u32 id, u32 c, u32 d)
{
    P28c2c8* p = D_0035f3c4;
    p->n--;
    W28c2c8* w = (W28c2c8*)((u8*)p + p->free[p->n] * 440);
    func_0028c0a0(w, id, h, z, c, d);
    if (z[400]) w->sub.Set();
    else w->sub.Clr();
    w->f436 = 0;
    D_0035f3cc.i++;
    return w;
}

} // extern "C"
