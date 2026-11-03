#include "../common/types.h"

// 0023f5b8: refresh a cached id/value pair after func_00139d78
extern "C" {
s32 func_00139d78(void*);
u32 func_00192048(s32);
}
namespace n0023f5b8 {
struct O24 { u8 pad[0x20]; u32 v; s32 id;
  void set(s32 n) { if (n >= 0 && n != id) { u32 r = func_00192048(n); id = n; v = r; } }
};
}
using n0023f5b8::O24;
void func_0023f5b8(O24* o, s32 id) asm("_Z13func_0023f5b8i");
void func_0023f5b8(O24* o, s32 id) {
    // the original saves s2 without using it (an eliminated pseudo); an s2 pin reproduces the save
    register s32 k asm("$18");
    asm volatile("" : "=r"(k));
    func_00139d78(o);
    o->set(id);
}

// 00257e00: bit mask of available entries (8 table rows checked through func_001a6d08, bit 1 from a list scan)
extern "C" {
struct Ent { u8 pad[0x1c]; s8 a[4]; s8 b[4]; };
struct Sub { u8 pad[0x54]; u16 f54; };
struct Obj2 { u8 pad[0x244]; Sub* p244; };
extern Ent D_00372a28[];
extern void* D_0035f010;
s32 func_001a6d08(s32);
s32 func_00281100(void*);
Obj2* func_00281180(void*, s32);
s32 func_00181500(s32);

s32 func_00257e00(void) {
    s32 i, j;
    s32 ok;
    s32 mask = 0;
    Ent* e = D_00372a28;
    asm("" : "+r"(e));  // hides e == D from cse, so loop2's giv takes D and e copies it (orig move s4,s5)
    for (i = 0; i < 8; i++, e++) {
        if (i == 1) continue;
        ok = 1;
        {
            s8* p;
            j = 0;
            p = e->a;
            for (; j < 4; j++) {
                s8 c = *p++;
                if (c < 0) break;
                if (func_001a6d08(c) == 0) { ok = 0; break; }
            }
        }
        if (!ok) continue;
        for (j = 0; j < 4; j++) {
            s8 c = D_00372a28[i].b[j];
            if (c < 0) break;
            if (func_001a6d08(c) != 0) { ok = 0; break; }
        }
        if (ok) mask |= 1 << i;
    }
    ok = 0;
    for (i = 0; i < func_00281100(D_0035f010); i++) {
        ok = (func_00281180(D_0035f010, i)->p244->f54 & 0x7fff) != 0;
        if (ok) break;
    }
    if (ok) {
        if (func_00181500(0x817) && !func_00181500(0x849)) ok = 0;
        if (ok) mask |= 2;
    }
    return mask;
}
}
