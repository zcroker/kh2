#include "../common/types.h"
struct V4 { f32 a,b,c,d; };
struct T218 { u32* o; u32 z; f32 x, y; };
union UF218 { u32 u; f32 f; u8 c; };
extern "C" {
u32 func_00190140(void);
u32 func_00112d28(u32);
u32 func_0016a020(u32);
void func_0019b0e8(V4*, u32, u32, f32, f32);
void func_0016ace0(u32, V4*);
void func_00185b00(void*);
extern u8 D_00350ce0[];

u32 func_00112d90(u32* p) {
    u32 ok = 0; u32 r = 0;
    if (func_00190140()) ok = *p != 0;
    if ((u8)ok) r = func_00112d28(*p);
    return r;
}

void func_00172928(T218* t) {
    u32 s = t->o[1];
    V4 v;
    u32 q = func_0016a020(s);
    u32 z = t->z;
    func_0019b0e8(&v, q, z, t->x, t->y);
    func_0016ace0(s, &v);
}

void ctarget_001ae9a0(u8* p) asm("_Z16ctarget_001ae9a0jjjj");
void ctarget_001ae9a0(u8* p) {
    func_00185b00(p);
    *(u32*)p = (u32)D_00350ce0;
    *(u32*)(p + 1416) |= 0x400;
    UF218* q = (UF218*)(p + 1648);
    q[66].u = 0;
    q[65].f = 2000.0f;
    ((UF218*)(p + 2748))->u |= 0x8404;
}
}
