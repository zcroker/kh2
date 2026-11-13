#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/menu_sound.hpp"

// 001d3c08 (from src/anon/tiny.cpp)
namespace n001d3c08 {
void func_001d3c08(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001d3c08");
void func_001d3c08(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x01d6u << 16);
    *(u32*)((u32)b + (-17880)) = (u32)a0;
}
} // n001d3c08

// 001d3c18 (from src/anon/auto80_199_queue.cpp)
namespace n001d3c18 {
void func_001d3c18(u32 a0) asm("func_001d3c18");
void func_001d3c18(u32 a0) {
    u32 s0 = a0;
    u32 v0 = func_001d3f98(s0);
    func_00170530(v0, 5000, 7, 0);

    u32 p = *(u32*)(s0 + 36);
    if (p != 0) {
        func_0016ed50(p, 5000, 7);
    }
}
} // n001d3c18

// 001d3c78 (from src/anon/perm_001d3c78.cpp)
namespace n001d3c78 {
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
struct O3c_sub
{
  u8 pad[8];
  s32 f8;
};
struct O3c
{
  u8 pad0[0xc];
  O3c_sub *f0c;
  u8 pad1[0x588 - 0x10];
  s32 f588;
  u8 pad2[0xb50 - 0x58c];
  s32 fb50;
};
struct V3c
{
  u8 b0;
  u8 b1;
  u8 b2;
  u8 b3;
  u16 h4;
};
extern O3c *D_0034e948 asm("D_0034e948");
extern u8 D_0032bae0 asm("D_0032bae0");
s32 func_00176b58(u8) asm("func_00176b58");
u32 *func_00177860(s32) asm("_ZN2YS5PARTY11get_abilityEv");
s32 func_0019ba60(s32) asm("_Z16ctarget_0019ba60jjjj");
V3c *func_001a80c8(u16) asm("func_001a80c8");
s32 func_001c8ab0() asm("_ZN2YS6SUMMON7GetModeEv");
s32 func_001d3f80(u8 *) asm("_ZN2YS7MISSION12GetLimitCostEi");
inline static u32 bit3c(u32 *b, u32 n)
{
  return b[n >> 5] & (1 << (n & 31));
}
s32 func_001d3c78(u8 *p) asm("func_001d3c78");
s32 func_001d3c78(u8 *p)
{
  O3c *o = D_0034e948;
  s32 i;
  u16 id;
  V3c *v;
  s32 r;
  if (!(o->f588 & 0x1000000))
  {
    goto ret0;
  }
  {
    u8 k = p[0x2c];
    if ((k != 0) && (D_0032bae0 != k))
    {
      r = 0;
      goto ret0;
    }
    if ((!func_001d3f80(p)) && func_001c8ab0())
    {
      r = 0;
      goto out;
    }
    if (o->f0c->f8 & 0x20)
    {
      r = 0;
      goto out;
    }
    for (i = 0; i < 3; i++)
    {
      s32 c = p[i + 1];
      if ((u8) c)
      {
        if ((o->fb50 == 7) && (((u32) (c - 2)) < 2))
        {
          r = 0;
          goto out;
        }
        if (!func_0019ba60(func_00176b58(c)))
        {
          r = 0;
          goto out;
        }
      }
    }

    id = *((u16 *) (p + 0x2a));
    if (!id)
    {
      r = 1;
      goto out;
    }
    v = func_001a80c8(id);
    if (v->b2 != 0x13)
    {
      goto ret1;
    }
    if (!bit3c(func_00177860(func_00176b58(p[1])), v->h4))
    {
      r = 0;
      goto out;
    }
    ret1:
    r = 1;

    goto out;
  }
  ret0:
  r = 0;

  out:
  return r;

}
} // n001d3c78

// 001d3de0 (from src/anon/auto80_199_queue.cpp)
namespace n001d3de0 {
u32 func_00170978(u32 a0) asm("func_00170978");
u32 func_001d3de0(u32 a0) asm("func_001d3de0");
u32 func_001d3de0(u32 a0) {
    u32 s0 = a0;
    u32 t15;
    u32 b;
    u8 c;

    if (func_00170978(func_001d3f98(s0)) == 0) {
        t15 = 0;
        goto end;
    }

    t15 = *(u32*)(s0 + 36);
    if (t15 == 0) {
        goto set1;
    }

    b = func_0016f7d0(t15, 0);
    b = b & 1u;
    c = (u8)b;
    b = c;
    if (b != 0) {
        t15 = 0;
        goto end;
    }

set1:
    t15 = 1;
end:
    return t15;
}
} // n001d3de0

// 001d3e40 (from src/anon/batch_w90.cpp)
namespace n001d3e40 {
s32 func_0019ba60(void*) asm("func_0019ba60");
u32 func_001d3f98(void*) asm("func_001d3f98");
s32 func_00170978(u32) asm("func_00170978");
s32 func_001a9758(u32, s32) asm("func_001a9758");
u32 func_0017df58(s32) asm("func_0017df58");
s32 func_0017e280(u32) asm("func_0017e280");
u8* func_00176b58(u8) asm("func_00176b58");
s32 func_0017e310(void*) asm("func_0017e310");
s32 func_001d3e40(u8* self) asm("func_001d3e40");
s32 func_001d3e40(u8* self)
{
    if (func_00170978(func_001d3f98(self)) != 2) return 0;
    if (*(u32*)(self + 36) && !func_001a9758(*(u32*)(self + 36), 0)) return 0;
    for (s32 i = 0; i < 2; i++) {
        u32 o = func_0017df58(i);
        if (func_0019ba60((void*)o) && !func_0017e280(o)) return 0;
    }
    for (s32 i = 0; i < 3; i++) {
        u8 c = self[1 + i];
        if (c) {
            u8* p = func_00176b58(c);
            if ((*(u32*)(p + 1416) & 0x4000) && !func_0017e310(p)) return 0;
        }
    }
    return 1;
}
} // n001d3e40

// 001d3f38 (from src/anon/batch_w27.cpp)
namespace n001d3f38 {
s32 func_001d3f38(u8* p) asm("func_001d3f38");
s32 func_001d3f38(u8* p) {                        
    switch (*(u16*)(p + 40)) {
    case 282:
    case 344:
    case 484:
        return 0;
    }
    return 1;
}
} // n001d3f38

// 001d3f80 (from src/anon/tiny_leaf.cpp)
namespace n001d3f80 {
u32 func_001d3f80(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001d3f80");
u32 func_001d3f80(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = (u32)(*(u8*)((u32)r4 + (s32)(2)));
    r2 = (u32)((s32)r2 + (56));
    r2 = (u32)(r2 & 0x00ffu);
    r2 = ((u32)r2 < 0x00000005u);
    return r2;
}
} // n001d3f80

// 001d3f98 (from src/anon/batch_w28.cpp)
namespace n001d3f98 {
void func_002fee78(void*, const char*, u32, void*) asm("func_002fee78");
extern u8 D_01d5ba30[] asm("D_01d5ba30");
extern char D_0036e448[] asm("D_0036e448");
extern u32 D_0033caf0 asm("D_0033caf0");
u8* func_001d3f98(u8* p) asm("func_001d3f98");
u8* func_001d3f98(u8* p) {
    func_002fee78(D_01d5ba30, D_0036e448, D_0033caf0, p + 4);
    return D_01d5ba30;
}
} // n001d3f98

// 001d3fe0 (from src/anon/batch_w63.cpp)
namespace n001d3fe0 {
s32 func_001d3c78(void*) asm("func_001d3c78");
struct T64 { u32 f0; s32 count; u8 e[1][64]; };
extern T64* D_01d5ba28 asm("D_01d5ba28");
u8* func_001d3fe0(u32 id) asm("func_001d3fe0");
u8* func_001d3fe0(u32 id) {
    for (s32 i = 0; i < D_01d5ba28->count; i++) {
        u8* e = D_01d5ba28->e[i];
        if (func_001d3c78(e) && *(u16*)(e + 40) == id) return e;
    }
    return 0;
}
} // n001d3fe0

// 001d4078 (from src/anon/batch_w98.cpp)
namespace n001d4078 {
struct E1d4 { u8 kind; u8 pad[39]; u16 id; u8 pad2[22]; };
struct T1d4 { u32 f0; s32 n; E1d4 e[1]; };
extern T1d4* D_01d5ba28 asm("D_01d5ba28");
extern u32 D_00352738[4] asm("D_00352738");
void func_001d3c18(E1d4*) asm("func_001d3c18");
void func_001d4078(u32 id) asm("func_001d4078");
void func_001d4078(u32 id) {
    s32 i, j;
    if (id == 609) {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < D_01d5ba28->n; j++) {
                E1d4* e = &D_01d5ba28->e[j];
                if (e->id == D_00352738[i]) {
                    func_001d3c18(e);
                    break;
                }
            }
        }
        return;
    }
    for (i = 0; i < D_01d5ba28->n; i++) {
        E1d4* e = &D_01d5ba28->e[i];
        if (e->id == id) {
            func_001d3c18(e);
            return;
        }
    }
}
} // n001d4078

// 001d4180 (from src/anon/batch_w97.cpp)
namespace n001d4180 {
struct Ent1d4 { u8 id; u8 pad[63]; };
struct Mgr1d4 { u32 f0; s32 count; Ent1d4 ent[1]; };
extern Mgr1d4* D_01d5ba28 asm("D_01d5ba28");
s32 func_00170cd0(void) asm("func_00170cd0");
s32 func_001d4808(Ent1d4*) asm("func_001d4808");
s32 func_001d3c78(Ent1d4*) asm("func_001d3c78");
s32 func_001d3de0(Ent1d4*) asm("func_001d3de0");
void func_00170320(s32) asm("func_00170320");
void func_001d3c18(Ent1d4*) asm("func_001d3c18");
void func_00170888(u32) asm("func_00170888");
void func_001d4180(void) asm("func_001d4180");
void func_001d4180(void) {
    u32 mask = 0;
    s32 n = 0;
    s32 any = 0;
    u8 idx[16];
    if (func_00170cd0()) return;
    s32 i;
    for (i = 0; i < D_01d5ba28->count; i++) {
        Ent1d4* e = &D_01d5ba28->ent[i];
        if (mask & (1 << e->id)) continue;
        if (func_001d4808(e)) continue;
        if (!func_001d3c78(e)) continue;
        mask |= 1 << e->id;
        idx[n++] = i;
        if (!func_001d3de0(e)) any = 1;
    }
    if (!any) return;
    func_00170320(5000);
    for (i = 0; i < n; i++) func_001d3c18(&D_01d5ba28->ent[idx[i]]);
    func_00170888(0);
}
} // n001d4180

// 001d42d0 (from src/anon/batch_w98.cpp)
namespace n001d42d0 {
struct E1d4 { u8 kind; u8 pad[39]; u16 id; u8 pad2[22]; };
struct T1d4 { u32 f0; s32 n; E1d4 e[1]; };
extern T1d4* D_01d5ba28 asm("D_01d5ba28");
struct Ent1d4 { u8 pad[2]; u16 id; u8 cnt; u8 kind; u8 pad2[6]; };
struct List1d4 { u8 pad[8]; s32 n; Ent1d4 e[1]; };
void func_001bc778(void*) asm("func_001bc778");
void func_001bc780(void*, u16, s32, s32) asm("func_001bc780");
s32 func_001d4420(void) asm("func_001d4420");
s32 func_001b58a8(void) asm("func_001b58a8");
s32 func_001d3f80(E1d4*) asm("func_001d3f80");
s32 func_001d4808(E1d4*) asm("func_001d4808");
s32 func_001d3c78(E1d4*) asm("func_001d3c78");
s32 func_001d3e40(E1d4*) asm("func_001d3e40");
void wtarget_001d42d0(List1d4*, u32, u32, u32) asm("_Z16wtarget_001d42d0jjjj");
void wtarget_001d42d0(List1d4* L, u32, u32, u32) {
    u32 mask = 0;
    s32 x = func_001d4420();
    func_001bc778(L);
    if (func_001b58a8()) return;
    for (s32 i = 0; i < D_01d5ba28->n; i++) {
        E1d4* e = &D_01d5ba28->e[i];
        if (func_001d3f80(e)) continue;
        if (func_001d4808(e)) continue;
        if (!func_001d3c78(e)) continue;
        u32 b = 1 << e->kind;
        if (mask & b) continue;
        mask |= b;
        func_001bc780(L, e->id, 0, 1);
        if (x && func_001d3e40(e)) continue;
        *(s8*)&L->e[L->n - 1].kind = 5;
    }
}
} // n001d42d0

// 001d4420 (from src/anon/batch_w3727.cpp)
namespace n001d4420 {
struct O_w3727 { u8 pad[0x48c]; s32 x; };
extern O_w3727* D_0034e948 asm("D_0034e948");
extern u8 D_00351eb8 asm("D_00351eb8");
bool func_0019ba60(O_w3727*) asm("func_0019ba60");
bool func_001b58a8() asm("func_001b58a8");
s32 func_001c8ab0() asm("func_001c8ab0");
bool func_001c8db8(void*, s32) asm("func_001c8db8");
bool func_001410c8() asm("func_001410c8");
bool func_001917c0() asm("func_001917c0");
s32 func_001a1de0(s32) asm("func_001a1de0");
s32 func_001d4420() asm("func_001d4420");
s32 func_001d4420() {
    O_w3727* o = D_0034e948;
    s32 r;
    if (func_0019ba60(o) && o->x) goto body;
fail:
    r = 0;
done:
    return r;
body:
    if (func_001b58a8()) goto fail;
    if (func_001c8ab0() != 2) { bool b = !func_001c8db8(&D_00351eb8, 0); if (!b) goto fail; }
    if (func_001410c8()) goto fail;
    if (!func_001917c0()) { r = 0; goto done; }
    r = !func_001a1de0(o->x);
    goto done;
}
} // n001d4420

// 001d44d8 (from src/anon/batch_w29.cpp)
namespace n001d44d8 {
struct LimitEntry { u8 pad[40]; u16 id; u8 pad2[22]; };
struct LimitTbl { u32 f0; s32 count; LimitEntry e[1]; };
LimitEntry* GetLimitEntry(s32 id) asm("_ZN2Tz6JmInfo13GetLimitEntryEz");
extern LimitTbl* D_01d5ba28 asm("D_01d5ba28");
LimitEntry* GetLimitEntry(s32 id) {
    for (s32 i = 0; i < D_01d5ba28->count; i++) {
        if (D_01d5ba28->e[i].id == id) return &D_01d5ba28->e[i];
    }
    return 0;
}
} // n001d44d8

// 001d4528 (from src/anon/batch_w3.cpp)
namespace n001d4528 {
s32 func_001a35f8(u16, u8) asm("func_001a35f8");
u32 func_001d4528(u8* p) asm("func_001d4528");
u32 func_001d4528(u8* p) { return func_001a35f8(*(u16*)(p + 42), p[1]) > 0; }
} // n001d4528

// 001d4550 (from src/anon/tiny_auto80_fptr4.cpp)
namespace n001d4550 {
extern u8 D_0032bb30 asm("D_0032bb30");
u32 func_001d4550(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001d4550");
u32 func_001d4550(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r14, r15;
    r14 = (u32)(*(u8*)((u32)r4 + (s32)(0)));
    r15 = (u32)&D_0032bb30;
    r14 = (u32)(r14 << 1);
    r14 = (u32)(r14 + r15);
    r2 = (u32)(*(u16*)((u32)r14 + (s32)(15688)));
    return r2;
}
} // n001d4550

// 001d4570 (from src/anon/tiny_auto80_queue.cpp)
namespace n001d4570 {
extern u8 D_0032bb30 asm("D_0032bb30");
void func_001d4570(u8* a0, u32 a1) asm("func_001d4570");
void func_001d4570(u8* a0, u32 a1) {
    u8* t6 = (u8*)((u32)&D_0032bb30 + (a0[0] << 1));
    t6 += 15680;
    if ((s32)*(u16*)(t6 + 8) < (s32)a1) {
        *(u16*)(t6 + 8) = (u16)a1;
    }
}
} // n001d4570

// 001d45a0 (from src/anon/batch_w329.cpp)
namespace n001d45a0 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct E { u8 b0; u8 b1; u8 pad[38]; u16 h28; u8 pad2[22]; };
struct Tbl { u32 a; s32 n; E e[1]; };
struct X { u8 pad[16]; u32 w10; };
struct Z { u16 h0; };
extern u32 D_003638d0 asm("D_003638d0");
extern Tbl* D_01d5ba28 asm("D_01d5ba28");
s32 func_001d4420(void) asm("func_001d4420");
s32 func_001d3c78(E*) asm("func_001d3c78");
s32 func_001d3e40(E*) asm("func_001d3e40");
void* func_0017e668(u8) asm("func_0017e668");
X* func_00177860(void*) asm("func_00177860");
V4* func_0016c028(void*) asm("func_0016c028");
Z* func_001b8e88(u16) asm("func_001b8e88");
s32 func_001bc2a8(Z*, void*, s32) asm("func_001bc2a8");
static inline bool Near(Z* z, void* a) { return func_001bc2a8(z, a, 0) < 4; }
Z* func_001d45a0(void* self, u32 id) asm("func_001d45a0");
Z* func_001d45a0(void* self, u32 id) {
    if (!func_001d4420()) return 0;
    s32 cnt = 0;
    Z* arr[D_01d5ba28->n];

    for (s32 i = 0; i < D_01d5ba28->n; i++) {
        E* e = &D_01d5ba28->e[i];
        if (e->b1 == 1) continue;
        if (!func_001d3c78(e)) continue;
        if (!func_001d3e40(e)) continue;
        void* o = func_0017e668(e->b1);
        if (!(func_00177860(o)->w10 & 2)) continue;
        V4* p1 = func_0016c028(o);                          
        V4* p2 = func_0016c028(self);                          
        V4 d;
        asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)" : : "r"(p1), "r"(p2), "r"(&d) : "memory");
        d.y = 0.0f;
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(&d) : "$8", "memory");
        if (len > 500.0f) continue;
        Z* z = func_001b8e88(e->h28);
        if (!Near(z, self)) continue;
        if (z->h0 == id) return z;
        arr[cnt] = z;
        cnt++;
    }
    if (cnt > 0) {
        D_003638d0 *= 0x10dcd;
        u32 m = cnt;
        s32 idx = (u64)D_003638d0 / ((0x100000000ull + (m - 1)) / m);
        return arr[idx];
    }
    return 0;
}
} // n001d45a0

// 001d4808 (from src/anon/tiny_leaf.cpp)
namespace n001d4808 {
u32 func_001d4808(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001d4808");
u32 func_001d4808(u32 a0, u32 a1, u32 a2, u32 a3) {                       
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = (u32)(*(u16*)((u32)r4 + (s32)(42)));
    r2 = ((u32)r2 < 0x00000001u);
    return r2;
}
} // n001d4808

// 001d4818 (from src/anon/batch_w64.cpp)
namespace n001d4818 {
struct B4 { u8 b[4]; };
extern B4 D_01d5ba58[] asm("D_01d5ba58");
extern B4 D_0036e4d0[] asm("D_0036e4d0");
void func_0013d550(u32, u32) asm("func_0013d550");
void func_001d4818(u32* p, s32 a1, u32 a2, u32 a3, u32 a4) asm("func_001d4818");
void func_001d4818(u32* p, s32 a1, u32 a2, u32 a3, u32 a4) {
    p[0] = a1;
    func_0013d550(a2, a3);
    p[1] = a4;
    if (a1 == 3) {
        for (u32 i = 0; i < 3; i++) D_01d5ba58[i] = D_0036e4d0[i];
    }
}
} // n001d4818

// 001d48b0 (from src/anon/tiny_auto80_queue.cpp)
namespace n001d48b0 {
u32 func_0013d620(...) asm("func_0013d620");
void func_001d48b0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_001d48b0");
void func_001d48b0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15, r16;
    r15 = *(volatile u32*)((u32)r4 + (s32)(0));
    r16 = r4;
    if (r15 != 0u) {
        ((void(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_0013d620)(r4, r5, r6, r7, r8, r9, r10, r11);
        *(volatile u32*)((u32)r16 + (s32)(4)) = 0u;
        *(volatile u32*)((u32)r16 + (s32)(0)) = 0u;
    }
}
} // n001d48b0

// 001d48e8 (from src/anon/auto80_199_queue.cpp)
namespace n001d48e8 {
u32 func_001d48e8(u32* a0) asm("func_001d48e8");
u32 func_001d48e8(u32* a0) {
    u32* s0 = a0;
    if (s0[0] == 0) {
        return 0;
    }
    if (func_001d4940() != 0) {
        return 1;
    }
    u32 p = s0[1];
    if (p != 0) {
        func_00198970(p);
    }
    return 0;
}
} // n001d48e8

// 001d4940 (from src/anon/batch_w1572.cpp)
namespace n001d4940 {
extern char D_0036e490[] asm("D_0036e490");
extern char D_0036e4e0[] asm("D_0036e4e0");
extern char D_0036e4e8[] asm("D_0036e4e8");
extern char D_0036e4f8[] asm("D_0036e4f8");
extern char D_0036e500[] asm("D_0036e500");
extern char D_0036e508[] asm("D_0036e508");
extern char D_0036e510[] asm("D_0036e510");
extern char D_0036e520[] asm("D_0036e520");
extern char D_01d5ba58[] asm("D_01d5ba58");
void func_00190878(void*, s32, s32) asm("func_00190878");
s32 func_0019ba60(s32) asm("func_0019ba60");
void func_001bc778(void*) asm("func_001bc778");
void func_001bce90(void*, const char*, s32, void*) asm("func_001bce90");
s32 func_001d4ae0(void*, void*, void*) asm("func_001d4ae0");
s32 func_001d4bd8(void*, void*, void*) asm("func_001d4bd8");
struct S { u32 type; s32 id; s32 pad; char buf[1]; };
struct NoTail { ~NoTail(){} };
s32 func_001d4940(S* p, void* a1, void* a2) asm("func_001d4940");
s32 func_001d4940(S* p, void* a1, void* a2) {
    NoTail nt;
    s32 r;
    if (p->id != 0) {
        r = 0;
        if (func_0019ba60(p->id) == 0) return r;
    }
    r = 1;
    if (p->type == 10) return r;
    func_001bc778(a2);
    switch (p->type) {
    case 1: func_001bce90(a2, D_0036e490, 3, 0); break;
    case 2: return func_001d4ae0(p, a1, a2);
    case 3: func_001bce90(a2, D_01d5ba58, 3, 0); break;
    case 4: func_001bce90(a2, D_0036e4e0, 2, 0); break;
    case 5: func_001bce90(a2, D_0036e4e8, 3, 0); break;
    case 6: func_001bce90(a2, D_0036e4f8, 1, 0); break;
    case 7: func_001bce90(a2, D_0036e500, 1, 0); break;
    case 8: func_001bce90(a2, D_0036e508, 1, 0); break;
    case 9: func_001bce90(a2, D_0036e510, 3, 0); break;
    case 11: return func_001d4bd8(p, a1, a2);
    case 12: func_00190878(p->buf, p->id, 0); func_001bce90(a2, D_0036e520, 3, p->buf); break;
    }
    return 1;
}
} // n001d4940

// 001d4ae0 (from src/anon/batch_w77.cpp)
namespace n001d4ae0 {
extern char D_0036e4a0[] asm("D_0036e4a0");
extern char D_0036e4b0[] asm("D_0036e4b0");
extern char D_0036e4c0[] asm("D_0036e4c0");
void func_00190878(u8*, u32, s32) asm("func_00190878");
void func_001bce90(u32, const char*, s32, u8*) asm("func_001bce90");
s32 func_001d4ae0(u8* a, u8* b, u32 c) asm("func_001d4ae0");
s32 func_001d4ae0(u8* a, u8* b, u32 c)
{
    if (!(*(u32*)(b + 352) & 0x4000) || !*(s32*)(b + 2928)) return 0;
    func_00190878(a + 12, *(u32*)(a + 4), 0);
    switch (*(s32*)(b + 2928)) {
    case 1: func_001bce90(c, D_0036e4a0, 3, a + 12); break;
    case 2: func_001bce90(c, D_0036e4b0, 3, a + 12); break;
    case 3: func_001bce90(c, D_0036e4c0, 3, a + 12); break;
    }
    return 1;
}
} // n001d4ae0

// 001d4bb8 (from src/anon/tiny_auto80_solver.cpp)
namespace n001d4bb8 {
void func_001d4bb8(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_001d4bb8");
extern u8 D_01d5ba58 asm("D_01d5ba58");
void func_001d4bb8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_001d4bb8");
void func_001d4bb8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r14, r15;
    r15 = (u32)&D_01d5ba58;
    r4 = (u32)(r4 << 2);    r14 = (u32)((s32)0u + (488));
    r4 = (u32)(r4 + r15);
    *(volatile u16*)((u32)r4 + (s32)(0)) = (u16)r14;
}
} // n001d4bb8

// 001d4bd8 (from src/anon/auto80_199_queue.cpp)
namespace n001d4bd8 {
u32 func_001d4bd8(u32 a0, u32 a1, u32 a2) asm("func_001d4bd8");
u32 func_001d4bd8(u32 a0, u32 a1, u32 a2) {
    u32 s17 = a0 + 12;
    u32 s18 = a2;
    u32 s16 = func_0016b740(2113);
    u32 ret = 0;

    if (func_0019ba60(s16) == 0) {
        return ret;
    }

    func_00190878(s17, s16, 0);

    u8* e0 = func_001bc780(s18, 1, 0, 1);
    e0[6] = 1;

    u8* e1 = func_001bc780(s18, 617, s17, 1);
    e1[6] = 3;

    u8* e2 = func_001bc780(s18, 618, s17, 1);
    e2[6] = 4;

    ret = 1;
    return ret;
}
} // n001d4bd8

// 001d4c98 (from src/anon/batch_w62.cpp)
namespace n001d4c98 {
void func_001d1678(u8*, s32) asm("func_001d1678");
void func_001d19e8(u8*, s32) asm("func_001d19e8");
void func_001d16e8(u8*, u32, u32) asm("func_001d16e8");
extern u8 D_003525c8[] asm("D_003525c8");
extern u8 D_00352750[] asm("D_00352750");
void func_001d4c98(u8* p) asm("func_001d4c98");
void func_001d4c98(u8* p) {
    *(u32*)(p + 4) = 0;
    *(u32*)p = (u32)D_003525c8;
    *(u32*)(p + 8) = 0;
    *(u32*)(p + 12) = 0;
    func_001d1678(p, -1);                     
    *(u32*)(p + 48) = 0;
    *(u32*)p = (u32)D_00352750;
    u8* e = p + 57;
    for (s32 i = 127; i >= 0; i--) {
        *e = 0;
        e += 4;
    }
    func_001d19e8(p, -1);
    func_001d16e8(p, 0, 12);
}
} // n001d4c98

// 001d4d28 (from src/anon/batch_w65.cpp)
namespace n001d4d28 {
extern u8 D_003525c8[] asm("D_003525c8");
extern u8 D_00352750[] asm("D_00352750");
void func_00320400(void*) asm("func_00320400");
void func_001d1678(void*, s32) asm("func_001d1678");
void func_001d19e8(void*, s32) asm("func_001d19e8");
void func_001d16e8(void*, s32, s32) asm("func_001d16e8");
void func_001d4d28(u32* p) asm("func_001d4d28");
void func_001d4d28(u32* p) {
    p[1] = 0;
    p[0] = (u32)D_003525c8;
    p[2] = 0;
    func_00320400(p + 3);
    func_001d1678(p, -1);                     
    p[12] = 0;
    p[0] = (u32)D_00352750;
    u8* q = (u8*)p + 57;
    s32 i;
    for (i = 127; i >= 0; i--) { *q = 0; q += 4; }
    func_001d19e8(p, -1);
    func_001d16e8(p, 0, 12);
}
} // n001d4d28

// 001d4dc0 (from src/anon/batch_w19.cpp)
namespace n001d4dc0 {
void func_001d4dc0(u32* p, u32 a, u32 b, u32 c) asm("func_001d4dc0");
void func_001d4dc0(u32* p, u32 a, u32 b, u32 c) {
    p[0x238 / 4] = a;
    p[0x18 / 4] = 9999;
    p[0x23c / 4] = b;
    p[0x240 / 4] = c;
    p[0x2c / 4] = 0;
    ((void (*)(u32*))((u32*)p[0])[1])(p);
}
} // n001d4dc0

// 001d4e00 (from src/anon/tiny_auto80_solver.cpp)
namespace n001d4e00 {
u32 func_0014f8d0(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_0014f8d0");
u32 func_001d16f8(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_001d16f8");
u32 func_001d4e00(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_001d4e00");
u32 func_001d4e00(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 s0 = a0;
    ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_001d16f8)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 r4 = *(u32*)(s0 + 4);
    u32 r9 = s0 + 44;
    u32 r5 = *(u32*)(s0 + 8);
    u32 r10 = s0 + 24;
    u32 r6 = *(u32*)(s0 + 32);
    u32 r7 = 0;
    u32 r11 = *(u32*)(s0 + 36);
    u32 r8 = 4;
    u32 ret = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_0014f8d0)(r4, r5, r6, r7, r8, r9, r10, r11);
    *(u32*)(s0 + 48) = ret;
    return ret;
}
} // n001d4e00

// 001d4e50 (from src/anon/perm_001d4e50.cpp)
namespace n001d4e50 {
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;
struct S1d4e50
{
  u8 busy;
  u8 age;
  u16 id;
};
struct M1d4e50
{
  u8 pad[56];
  S1d4e50 slot[128];
};
struct K1d4e50
{
  u16 id;
  u8 pad[0x28];
  u16 f2a;
};
void func_001d4f40(M1d4e50 *, u16, u8) asm("func_001d4f40");
void func_001d4e50(M1d4e50 *m, K1d4e50 *k) asm("func_001d4e50");
void func_001d4e50(M1d4e50 *m, K1d4e50 *k)
{
  u16 id;
  S1d4e50 *best;
  s32 i;
  S1d4e50 *s;
  S1d4e50 *hit;
  S1d4e50 *c;
  u8 a;
  if (k->f2a == 0)
  {
    return;
  }
  id = k->id;
  best = 0;
  i = 0;
  s = m->slot;
  for (; i < 128; i++, s++)
  {
    c = s;
    if ((c->busy == 0) && (c->id == id))
    {
      hit = c;
      goto found;
    }
    if ((best == 0) || (best->age > c->age))
    {
      best = c;
    }
  }

  best->id = id;
  best->busy = 0;
  best->age = 0;
  c = best;
  hit = c;
  found:
  a = hit->age;

  hit->age = a + 1;
  func_001d4f40(m, k->f2a, a);
}
} // n001d4e50

// 001d4ef0 (from src/anon/batch_w30.cpp)
namespace n001d4ef0 {
u8* func_00321728(void*, s32, u32) asm("func_00321728");
void func_001d4f40(void*, u32, u32) asm("func_001d4f40");
void func_001d4ef0(u8* p, u8* a) asm("func_001d4ef0");
void func_001d4ef0(u8* p, u8* a) {
    u8* v = func_00321728(p + 56, 1, a[0]);
    u32 c = v[1];
    v[1] = c + 1;
    func_001d4f40(p, *(u16*)(a + 0x42), c);
}
} // n001d4ef0

