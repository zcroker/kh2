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

s32 func_00257e00(void);  // 0x00257e00: definition moved into src/anon/unit_00254020.cpp
}
