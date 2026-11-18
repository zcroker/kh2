// Linked unit 0x0017e858-0x0017eb68.
#include "../common/types.h"

// 0017e858 (gap: the other constructor clone of 0x17e9d0, with the element constructor inlined)
namespace g0017e858 {
void func_0031cc28(void*) asm("_Z13func_0031cc28Pv");
void func_00144490(f32, f32, f32, f32, f32, f32, void*) asm("func_00144490");
void func_0017fdf8(void*) asm("func_0017fdf8");
struct E7e9d0 { u8 pad[0x10]; u8 sub[4]; };
struct P7e9d0 { s32 f00, f04, f08, f0c, f10, f14, f18, f1c, f20, f24, f28; u8 p2c[0x10];
  s32 f3c[2]; E7e9d0 e44[4]; s32 f94, f98; u8 p9c[0x14]; f32 vb0[4]; u8 pc0[0x10]; s32 fd0, fd4;
  u8 bd8[0x18]; s32 ff0; f32 ff4; s32 ff8; s32 ffc, f100, f104; s32 a108[8][2]; s32 f148; s32 a14c[16];
  s32 f18c, f190, f194; u8 p198[0x20]; s32 f1b8; };
/*TARGET 0017e9d0*/
void func_0017e858(P7e9d0* p, s32 a1) asm("func_0017e858");
void func_0017e858(P7e9d0* p, s32 a1) {
    p->f00 = 0; p->f08 = a1; *(s32*)((u8*)p + 0x04) = 0; p->f0c = 0; p->f10 = 0; p->f14 = -1; p->f18 = -1; p->f1c = -1; p->f20 = 0; p->f24 = 0; p->f28 = 0;
    s32* q = p->f3c;
    {
        E7e9d0* e = p->e44;
        s32 i = 3;
        do {
            *(s32*)e->sub = 0;
            e++;
        } while (--i != -1);
    }
    q[0] = 0; q[1] = 0; p->f98 = 0; p->f94 = 0;
    {
        f32* v = p->vb0;
        f32 z = 0.0f;
        v[1] = z; v[2] = z; v[3] = z; p->fd0 = 0; p->fd4 = 0; v[0] = z;
    }
    func_00144490(-0.5f, -0.5f, -0.5f, 0.5f, 0.5f, 0.5f, p->bd8);
    p->ffc = 0; p->f100 = 0; p->ff0 = a1 + 0x80; p->ff4 = 1.0f; p->f104 = 0;
    {
        s32* e = p->a108[0];
        s32 i = 7;
        do {
            *e = 0;
            e += 2;
        } while (--i != -1);
    }
    p->f148 = 0; p->f190 = 0; p->f18c = 0; p->f194 = 0; p->f1b8 = 0;
    func_0017fdf8(p);
    {
        s32 i;
        for (i = 0; i < 16; i++) p->a14c[i] = -1;
    }
}
}  // namespace g0017e858

// 0017e9d0 (was src/anon/batch_w1947_nsa.cpp)
namespace n0017e9d0 {
void func_0031cc28(void*) asm("_Z13func_0031cc28Pv");
void func_00144490(f32, f32, f32, f32, f32, f32, void*) asm("func_00144490");
void func_0017fdf8(void*) asm("func_0017fdf8");
struct E7e9d0 { u8 pad[0x10]; u8 sub[4]; };
struct P7e9d0 { s32 f00, f04, f08, f0c, f10, f14, f18, f1c, f20, f24, f28; u8 p2c[0x10];
  s32 f3c[2]; E7e9d0 e44[4]; s32 f94, f98; u8 p9c[0x14]; f32 vb0[4]; u8 pc0[0x10]; s32 fd0, fd4;
  u8 bd8[0x18]; s32 ff0; f32 ff4; s32 ff8; s32 ffc, f100, f104; s32 a108[8][2]; s32 f148; s32 a14c[16];
  s32 f18c, f190, f194; u8 p198[0x20]; s32 f1b8; };
/*TARGET 0017e9d0*/
void func_0017e9d0(P7e9d0* p, s32 a1) asm("func_0017e9d0");
void func_0017e9d0(P7e9d0* p, s32 a1) {
    p->f00 = 0; p->f08 = a1; *(s32*)((u8*)p + 0x04) = 0; p->f0c = 0; p->f10 = 0; p->f14 = -1; p->f18 = -1; p->f1c = -1; p->f20 = 0; p->f24 = 0; p->f28 = 0;
    s32* q = p->f3c;
    {
        E7e9d0* e = p->e44;
        s32 i = 3;
        do {
            func_0031cc28(e->sub);
            e++;
        } while (--i != -1);
    }
    q[0] = 0; q[1] = 0; p->f98 = 0; p->f94 = 0;
    {
        f32* v = p->vb0;
        f32 z = 0.0f;
        v[1] = z; v[2] = z; v[3] = z; p->fd0 = 0; p->fd4 = 0; v[0] = z;
    }
    func_00144490(-0.5f, -0.5f, -0.5f, 0.5f, 0.5f, 0.5f, p->bd8);
    p->ffc = 0; p->f100 = 0; p->ff0 = a1 + 0x80; p->ff4 = 1.0f; p->f104 = 0;
    {
        s32* e = p->a108[0];
        s32 i = 7;
        do {
            *e = 0;
            e += 2;
        } while (--i != -1);
    }
    p->f148 = 0; p->f190 = 0; p->f18c = 0; p->f194 = 0; p->f1b8 = 0;
    func_0017fdf8(p);
    {
        s32 i;
        for (i = 0; i < 16; i++) p->a14c[i] = -1;
    }
}
}  // namespace n0017e9d0

