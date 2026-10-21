#include "../common/types.h"
struct Obj2c1832 { u8 pad[0x18]; u8 sub[0x174]; void* f18c; };
extern "C" {
void func_00138cb8(void*, s32*, s32*);
void func_001aa728(s32, s32, s32, s32, s32, s32, s32);
s32 func_0023aa18(void*);
s32 func_0023aa38(void*);
s32 func_0023aa58(void*);
s32 func_0023aa98(void*);
s32 func_0028b040(s32);
s32 func_0028b160(s32, Obj2c1832*);
s32 func_002c2610(s32, s32);
extern s32 D_00361c0c;
extern s32 D_01e2bd10;
void func_002c4390(s32 en, s32 a1, s32 a2, s32 a3, Obj2c1832* o) {
    s32 px, py, qx, qy;
    s32 m, n;
    void* sub = o->sub;
    if (en) {
        func_00138cb8(o->f18c, &px, &py);
        func_00138cb8(o, &qx, &qy);
        qx = qx + px + func_0023aa18(sub);
        qy = qy + ((func_0028b160(D_00361c0c, o) * func_0023aa98(sub)) + (func_0023aa38(sub) + py));
        m = func_0023aa58(sub);
        n = func_0028b160(D_00361c0c, o);
        n = n + func_0028b040(D_00361c0c);
        func_001aa728(0, func_002c2610(D_01e2bd10, n), qx, qy, a2, m, 0);
    }
}
}
