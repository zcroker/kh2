#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "tiny_auto80_solver_structs.hpp"
#include "../yasui/libys/obj.hpp"

// 001c0638 (from src/anon/tiny.cpp)
namespace n001c0638 {
void func_001c0638(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001c0638jjjj");
void func_001c0638(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x01d5u << 16);
    *(u32*)((u32)b + (-27816)) = (u32)a0;
}
} // n001c0638

// 001c0648 (from src/anon/batch_w65.cpp)
namespace n001c0648 {
extern u8* D_01d49358 asm("D_01d49358");
u8* func_001c0648(u32 key) asm("func_001c0648");
u8* func_001c0648(u32 key) {
    u8* t = D_01d49358;
    s32 n = *(s32*)(t + 4);
    u8* e = t + 8;
    s32 i;
    for (i = 0; i < n; i++, e += 16)
        if (*e == key) return e;
    return 0;
}
} // n001c0648

// 001c0690 (from src/anon/batch_w299.cpp)
namespace n001c0690 {
extern s32 D_0032dfc8 asm("D_0032dfc8");
extern u8 D_0032f230 asm("D_0032f230");
void func_001b74b8(void*) asm("func_001b74b8");
void YS__SHEET__add_hp(void*, s32, s32, s32) asm("YS__SHEET__add_hp");
void YS__SHEET__add_mp(void*, s32, s32) asm("YS__SHEET__add_mp");
void YS__SHEET__add_drive(void*, s32) asm("YS__SHEET__add_drive");
void YS__PARTRAM__set_item_max(void*, s32) asm("YS__PARTRAM__set_item_max");
void func_001b7508(void*, s32, s32) asm("func_001b7508");
void YS__ITEM__Get(s32, s32, s32) asm("YS__ITEM__Get");
void func_001b7538(void*, s32) asm("func_001b7538");
void YS__LEVELUP__ShowEffect(s32) asm("YS__LEVELUP__ShowEffect");
void func_001b7658(void*, s32, s32) asm("func_001b7658");
struct Sub1c0 { u8 pad[16]; u8 f16; u8 f17; u8 f18; };
struct Obj1c0 { u8 pad0[4]; s32 f4; u8 pad8[388-8]; s32 f388; u8 pad392[434-392]; u8 f434; u8 pad435[580-435]; Sub1c0* f580; u8 pad584[596-584]; s32 f596; u8 pad600[4]; s32 f604; };
void func_001c0690(u8* p, Obj1c0* o) asm("func_001c0690");
void func_001c0690(u8* p, Obj1c0* o) {
    u8 buf[80];
    func_001b74b8(buf);
    s32 a = p[2];
    s32 b = p[3];
    if (D_0032dfc8 == 3) {
        s32 t = p[1];
        if (t != 0 && (t < 4 || t == 14)) {
            a /= 2;
            b /= 2;
        }
    }
    o->f4 += a;
    o->f388 += b;
    YS__SHEET__add_hp(o, a, 0, 0);
    YS__SHEET__add_mp(o, b, 0);
    s32 n = o->f434 + p[4];
    if (n >= 10) n = 9;
    o->f434 = n;
    YS__SHEET__add_drive(o, 0);  // ring_buffer_index
    if (o->f580) {
        YS__PARTRAM__set_item_max(o->f580, o->f580->f18 + p[5]);
        o->f580->f17 += p[6];
        o->f580->f16 += p[7];
    }
    func_001b7508(buf, a, 0x8ae2);
    func_001b7508(buf, b, 0x8ae3);
    func_001b7508(buf, p[4], 0x8ae4);
    func_001b7508(buf, p[5], 0x8ae5);
    func_001b7508(buf, p[6], 0x8ae6);
    func_001b7508(buf, p[7], 0x8ae7);
    u8* q = p;
    s32 i = 1;
    do {
        if (*(u16*)(q+8)) {
            YS__ITEM__Get(*(u16*)(q+8), o->f596, 0);
            func_001b7538(buf, *(u16*)(q+8));
        }
        i--;
        q += 2;
    } while (i >= 0);
    if (o->f604) YS__LEVELUP__ShowEffect(o->f604);
    func_001b7658(buf, p[1], D_0032f230);
}
} // n001c0690

// 001c0890 (from src/anon/batch_w99.cpp)
namespace n001c0890 {
struct BL1c08 { u8 pad[14080]; u8 count; u8 pad2[3]; u32 bits[1]; };
struct T1c08 { u32 pad; s32 n; u8 e[1]; };
extern BL1c08 D_0032bb30 asm("D_0032bb30");
extern T1c08* D_01d49358 asm("D_01d49358");
u8* func_001c0648(u32) asm("func_001c0648");
s32 func_001c09c0(u32) asm("func_001c09c0");
u32 func_001a1658(u8, s32) asm("func_001a1658");
void func_001c0690(u8*, u32) asm("func_001c0690");
void YS__SHEET__Free(u32) asm("YS__SHEET__Free");
void YS__PROGRESS__CheckLM(void) asm("YS__PROGRESS__CheckLM");
void bonuslevel_up(u32) asm("_ZN2YS10BONUSLEVEL2UpEi");
void bonuslevel_up(u32 id) asm("bonuslevel_up");
void bonuslevel_up(u32 id)
{
    u8* e = func_001c0648(id);
    if (func_001c09c0(id)) return;
    BL1c08* bl = &D_0032bb30;
    bl->count++;
    u32* bits = bl->bits;
    bits[id >> 5] |= 1 << (id & 31);
    while (e < D_01d49358->e + D_01d49358->n * 16 && e[0] == id) {
        u32 x = func_001a1658(e[1], -1);  // state_dispatch_0_1_14
        func_001c0690(e, x);
        e += 16;
        YS__SHEET__Free(x);
    }
    YS__PROGRESS__CheckLM();
}
} // n001c0890

// 001c09c0 (from src/anon/auto200_999.cpp)
namespace n001c09c0 {
extern u8 D_0032f234 asm("D_0032f234");
u32 func_001c09c0(u32 a0) asm("_Z13func_001c09c0j");
u32 func_001c09c0(u32 a0) {
    u32 idx = a0 >> 5;
    u32 *p = (u32 *)((u8 *)&D_0032f234 + (idx << 2));
    u32 bit = a0 & 31;
    u32 val = *p;
    u32 mask = 1u << bit;
    return (val & mask) != 0;
}
} // n001c09c0

// 001c09f0 (from src/anon/tiny.cpp)
namespace n001c09f0 {
void func_001c09f0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001c09f0jjjj");
void func_001c09f0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x01d5u << 16);
    *(u32*)((u32)b + (-27808)) = (u32)a0;
}
} // n001c09f0

// 001c0a00 (from src/anon/batch_w54.cpp)
namespace n001c0a00 {
void func_001c0ae0(void*) asm("func_001c0ae0");
void func_001c0ca0(s32) asm("func_001c0ca0");
extern u8 D_01d49368[] asm("D_01d49368");
extern void* D_00351338 asm("D_00351338");
extern s32 D_01d4937c asm("D_01d4937c");
extern u8 D_0032bae0 asm("D_0032bae0");
void func_001c0a00(s32 a) asm("func_001c0a00");
void func_001c0a00(s32 a) {
    if (a == 0) {
        func_001c0ae0(D_01d49368);
        D_00351338 = D_01d49368;
        D_01d4937c = D_01d49368[D_0032bae0];
    } else {
        D_01d4937c = a;
        D_00351338 = 0;
    }

    if (D_01d4937c == 0) {
        D_01d4937c = 1;

    }
    func_001c0ca0(D_01d4937c);
}
} // n001c0a00

// 001c0a80 (from src/anon/batch_w9.cpp)
namespace n001c0a80 {
void func_001c0a80(u8* p) asm("func_001c0a80");
void func_001c0a80(u8* p) {
    s32 i;
    for (i = 0; i < 19; i++) p[i] = 0;
}
} // n001c0a80

// 001c0ab0 (from src/anon/tiny_auto80_queue.cpp)
namespace n001c0ab0 {
void func_001c0ab0(u8* a0, u8* a1) asm("_Z13func_001c0ab0PhS_");
void func_001c0ab0(u8* a0, u8* a1) {
    s32 t3 = 0;
    while (1) {
        u8* t7 = a1 + t3;
        u8* t4 = a0 + t3;
        u32 t5 = t7[0];
        t3 = t3 + 1;
        u32 t6 = (u32)(t3 < 19);
        u32 t7v = t4[0];
        t7v = t7v + t5;
        t4[0] = (u8)t7v;
        if (t6 != 0) {
            continue;
        }
        return;
    }
}
} // n001c0ab0

// 001c0ae0 (from src/anon/batch_w86.cpp)
namespace n001c0ae0 {
namespace n0010b620 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    u32 v[4];
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct Obj { f32 f0; u32 pad[3]; QWord a; QWord b; };
}
namespace n001110e8 {
struct Obj;
typedef s32 (*VFn)(Obj*);
struct Obj { VFn* vt; u8 pad[2936]; u32 b0:1; u32 b1:1; u32 b2:13; u32 b15:1; u32 rest:16; };
struct Ent { u32 v[4]; };
}
namespace n00117b38 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
union FU { f32 f; s32 i; };
struct Obj {
    void* vt; u8 p4[8]; s32 f12; void* f16; FU* f20; u8 p24[8]; u8 sub32[1536]; s32 f1568; u8 p1572[4];
    f32 f1576; f32 f1580; s32 f1584; u8 p1588[12]; V4 a; V4 b; u8 p1632[16]; s32 f1648; f32 f1652; u8 p1656[72];
    u8 sub1728[200]; s32 f1928;
};
}
namespace n00123ac0 {
struct Elem;
typedef s32 (*EFn)(Elem*);
struct Elem { s32 vt; };
struct Obj { void* vt; u32* tbl; u8 p8[8]; s32 n; s32 a[3]; s32 b[3]; };
}
namespace n0016b668 {
struct Obj;
typedef void (*VFn)(Obj*);
struct Obj { VFn* vt; u8 p4[152]; s32 f156; u8 p160[104]; u32 f264; u8 p268[500]; u8 sub768[388]; void* f1156; };
}
namespace n00175bb8 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    f32 v[4];
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
} __attribute__((aligned(16)));
struct Info { u8 p0[8]; u32 f8; };
struct Obj { u8 p0[12]; Info* info; QWord pos; u8 p32[320]; s32 f352; u8 p356[4]; u32 f360; };
}
namespace n001829b0 {
struct Def { u8 p0[12]; u16 f12; };
struct Item { u8 p0[8]; Def* def; u8 p12[40]; u8* f52; };
}
namespace n00184308 {
struct Obj;
struct Ctl;
typedef void (*CFn)(Ctl*, Obj*);
typedef void (*OFn)(Obj*);
struct Ctl { CFn* vt; };
struct Obj { OFn* vt; u8 p4[8]; Ctl* ctl; u8 p16[248]; u32 f264; u8 p268[500]; u8 sub768[388]; void* f1156; };
}
namespace n0018ee60 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    u32 v[4];
    QWord() {}
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
}
namespace n00195d00 {
struct Ent { u8 p0[20]; f32 f20; u8 p24[296]; u8 sub320[2548]; u16 f2868; };
struct Obj;
typedef void (*OFn)(Obj*, Ent*, s32);
struct Obj { OFn* vt; };
}
namespace n001b7a18 {
struct QWord { f32 v[4]; } __attribute__((aligned(16)));
struct Item { u8 p0[16]; u8 key[16]; };
}
namespace n001c0ae0 {
struct E { u32 id; u32 f4; u8 data[24]; };
struct Tbl { u32 f0; s32 n; E e[1]; };
extern Tbl* D_01d49360 asm("D_01d49360");
extern u32 D_0032f254[] asm("D_0032f254");
void func_001c0a80(void*) asm("func_001c0a80");
void func_001c0ab0(void*, void*) asm("func_001c0ab0");
void func_001c0ae0(void* o) asm("func_001c0ae0");
void func_001c0ae0(void* o)
{
    func_001c0a80(o);
    E* e = D_01d49360->e;
    for (s32 i = 0; i < D_01d49360->n; i++, e++) {
        if (D_0032f254[e->id >> 5] & (1 << (e->id & 31))) func_001c0ab0(o, e->data);
    }
}
}
namespace n001da070 {
struct QWord { f32 x, y, z, w; } __attribute__((aligned(16)));
}
namespace n0022ca00 {
struct Ent { s16 id; s16 start; s16 end; s16 f6; u8 data[84]; };
struct Tbl { u32 f0; s16 n; s16 f6; Ent e[1]; };
struct Act { u8 p0[1704]; s32 f1704; u8 p1708[196]; void* f1904; };
union AP { Act* p; s32 i; };
struct Obj { u8 p0[8]; AP act; };
}
namespace n00232988 {
struct Obj { s32 type; u8 p4[16]; s32 f20; };
struct Ent { Obj* obj; s16 f4; s8 kind; u8 p7[25]; };
struct Tbl { u32 f0; s16 n; s16 f6; Ent e[1]; };
}
namespace n0023c5f0 {
struct Grp { u16 first; u16 n; u8 p4[16]; };
struct Ent { s32 f0; s32 idx; s32 arg; s32 add; u8 p16[8]; };
struct Item { u8 p0[344]; };
struct Obj { u8 p0[16]; Ent* ents; Grp* grps; u8 p24[20]; Item* items; };
}
namespace n0023e9f0 {
struct Obj { u8 p0[2924]; s32 n; u8 p2928[2368]; u8* a[4]; u8* b[4]; u8* c[4]; };
}
namespace n00245be8 {
struct Info { u8 p0[4]; s16 anim; };
}
namespace n00284650 {
struct Item { u8 p[436]; };
}
namespace n0028a980 {
struct Spr { u8 p0[392]; s32 f392; };
struct Def { s16 anim; s16 f2; s16 f4; };
union N16 { s16 v; s32 i; };
struct Obj { u8 p0[4]; N16 n; u8 p8[6]; s16 f14; u8 p16[24]; Spr** sprs; };
}
namespace n0028c4f8 {
struct Elem;
typedef void (*EFn)(Elem*);
struct Elem { EFn* vt; u8 p4[436]; };
}
namespace n002b3d00 {
struct Obj { u32 a; u32 b; u32 c; };
}
namespace n002cd428 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    f32 v[4];
    QWord() {}
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct Obj { u8 p0[8]; s32 f8; };
}
namespace n0031d030 {
struct Elem;
typedef void (*EFn)(Elem*);
struct Elem { EFn* vt; u8 p4[404]; };
struct Obj { u32 vt; u8 p4[44]; Elem a[6]; Elem b[32]; };
}
} // n001c0ae0
#undef QCOPY
#undef QCOPY
#undef QCOPY
#undef QCOPY

// 001c0ba0 (from src/anon/perm_001c0ba0.cpp)
namespace n001c0ba0 {
typedef struct Ent Ent;
typedef struct Tab Tab;
typedef struct Ent
{
  u32 id;
  s32 key;
  u8 pad[24];
} Ent;
typedef struct Tab
{
  s32 x;
  s32 n;
  Ent e[1];
} Tab;
extern Tab *D_01d49360 asm("D_01d49360");
extern u32 D_0032f254[] asm("D_0032f254");
void func_001c0ba0(s32 key) asm("func_001c0ba0");
void func_001c0ba0(s32 key)
{
  s32 i;
  Ent *e = D_01d49360->e;
  Tab *t;
  for (i = 0; i < D_01d49360->n; i++)
  {
    if (e->key == key)
    {
      u32 id = e->id;
      u32 *w = &D_0032f254[id >> 5];
      *w |= 1 << (id & 0x1f);
    }
    e++;
  }

}
} // n001c0ba0

// 001c0c18 (from src/anon/tiny.cpp)
namespace n001c0c18 {
u32 func_001c0c18(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001c0c18jjjj");
u32 func_001c0c18(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_global_35c638
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0035u << 16);
    return (u32)(*(u32*)((u32)b + (4920)));
}
} // n001c0c18

// 001c0c28 (gap)
namespace n001c0c28 {
u32 func_001c0c28() asm("func_001c0c28");
u32 func_001c0c28() {
    u32 b = (0x01d5u << 16);
    return *(u32*)(b + (-27780));
}
} // n001c0c28

// 001c0c38 (from src/anon/batch_w23.cpp)
namespace n001c0c38 {
extern u8* D_01d49360 asm("D_01d49360");
extern u32 D_00320888 asm("D_00320888");
u8 func_002fd248(void*, void*, u32, s32, void*) asm("func_002fd248");
s32 func_001c0c38(void* a) asm("func_001c0c38");
s32 func_001c0c38(void* a) {
    return func_002fd248(a, D_01d49360 + 8, *(u32*)(D_01d49360 + 4), 32, &D_00320888);
}
} // n001c0c38

// 001c0c70 (from src/anon/tiny.cpp)
namespace n001c0c70 {
void func_001c0c70(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001c0c70jjjj");
void func_001c0c70(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x01d5u << 16);
    *(u32*)((u32)b + (-27776)) = (u32)a0;
}
} // n001c0c70

// 001c0c80 (from src/anon/tiny_auto80_solver.cpp)
namespace n001c0c80 {
u32 func_001c0c80(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_001c0c80jjjjjjjj");
u32 func_001c0c80(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001c0c80jjjjjjjj");
u32 func_001c0c80(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15;
    r15 = (u32)((s32)0u + (12));
    r4 = (u32)(r4 * r15);
    r14 = (u32)(0x01d5u << 16);
    r2 = *(u32*)((u32)r14 + (s32)(-27776));
    r2 = (u32)(r2 + r4);
    r2 = (u32)((s32)r2 + (-12));
    return r2;
}
} // n001c0c80

// 001c0ca0 (from src/anon/tiny_jal_wrappers.cpp)
namespace n001c0ca0 {
u32 func_001c0c80(u32, u32, u32, u32) asm("_Z13func_001c0c80jjjj");
u32 func_001c0ca0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001c0ca0jjjj");
u32 func_001c0ca0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u;
    r2 = func_001c0c80(r4, r5, r6, r7);
    r15 = (u32)(0x0035u << 16);
    *(u32*)((u32)r15 + (s32)(4924)) = r2;
    return r2;
}
} // n001c0ca0

// 001c0cc8 (from src/anon/tiny.cpp)
namespace n001c0cc8 {
u32 func_001c0cc8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001c0cc8jjjj");
u32 func_001c0cc8(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_global_35c63c
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0035u << 16);
    return (u32)(*(u32*)((u32)b + (4924)));
}
} // n001c0cc8

// 001c0cd8 (from src/yasui/libys/obj.cpp)
namespace YS {
u32 OBJ::is_attach() {
    return (*(u32*)((u32)this + 1392) != 0);
}
}

// 001c0ce8 (from src/anon/batch_w26.cpp)
namespace n001c0ce8 {
s32 obj_is_attach(void*) asm("_ZN2YS3OBJ9is_attachEv");
s32 func_001c0ce8(u8* o) asm("func_001c0ce8");
s32 func_001c0ce8(u8* o) {
    s32 r = 0;
    if (obj_is_attach(o)) {
        u32 m = *(u32*)(*(u8**)(o + 1392) + 1416) & 0x80;
        r = m != 0;
    }
    return r;
}
} // n001c0ce8

// 001c0d38 (from src/anon/batch_w94.cpp)
namespace n001c0d38 {
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
s32 func_001c0cd8(u8*) asm("func_001c0cd8");
void func_001c0e60(u8*) asm("func_001c0e60");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
struct Node1c0 {
    u8 _0[236];
    Node1c0* next;
};
struct List1c0 {
    Node1c0* head;
    Node1c0* tail;
};
static inline u8 busy2(u8* p) {
    u8 r = 0;
    if ((*(u32*)(*(u8**)(p + 12) + 8) & 2) || (*(u32*)(p + 352) & 0x40)) r = 1;
    return r;
}
#define p ((u8*)self)
#define owner ((u8*)own)
u8* YS__OBJ__attach(u32 self, u32 own, u32 a, u32 b) asm("_Z15YS__OBJ__attachjjjj");
u8* YS__OBJ__attach(u32 self, u32 own, u32 a, u32 b) {
    if (func_001c0cd8(p)) func_001c0e60(p);
    *(u16*)(p + 1396) = a;
    *(u8**)(p + 1392) = owner;
    *(u16*)(p + 1398) = b;

    u32 st = busy2(p) ? 5 : 0;
    *(u32*)(p + 1404) = 0;
    *(u32*)(p + 1400) = st;
    asm volatile("sqc2 $vf0, 0(%0)" : : "r"(p + 1344) : "memory");
    if (!(b & 2)) {
        asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(p + 1360) : "memory");
        *(u32*)(p + 2040) |= 8;
    }
    func_0016bd60(p, 3);
    List1c0* l = (List1c0*)(owner + 1888);
    Node1c0* n = (Node1c0*)(p + 1648);
    if (l->tail == 0) { l->tail = n; l->head = n; *(u32*)(p + 1884) = 0; } else { l->tail->next = n; *(u32*)(p + 1884) = 0; l->tail = n; }
    if (*(u32*)(p + 2060) == 0) *(u32*)(p + 1548) = *(u32*)(owner + 2060);
    else if (*(u32*)(owner + 2060) == 0) *(u32*)(owner + 1548) = *(u32*)(p + 2060);
    return p + 1392;
}
} // n001c0d38
#undef p
#undef owner

// 001c0e60 (from src/anon/batch_w3726_nsa.cpp)
namespace n001c0e60 {
#define QCP(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV {
    f32 x, y, z, w;
    QV() {}
    QV(const QV& o) { QCP(this, &o); }
    QV& operator=(const QV& o) { if (this != &o) QCP(this, &o); return *this; }
    QV operator-(const QV& b) const {
        QV o;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&o), "r"(this), "r"(&b) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct YNode { u8 pad[0xec]; YNode* next; };
struct YList { YNode* head; YNode* tail; };
s32 func_001c0cd8(u8*) asm("func_001c0cd8");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
QV* YS__OBJ__get_pos(u8*) asm("YS__OBJ__get_pos");
f32 func_002f8ad0(f32, f32) asm("func_002f8ad0");
void func_0016aeb8(u8*, f32) asm("func_0016aeb8");
s32 func_0019bad8(u8*) asm("func_0019bad8");
void dk__Octree__collisionToMap(QV*, QV*) asm("dk__Octree__collisionToMap");
void func_0016ace0(u8*, QV*) asm("func_0016ace0");
void func_0016cc18(s32, s32, s32*, s32, s32) asm("func_0016cc18");
void YS__OBJ__make_matrix(u8*) asm("YS__OBJ__make_matrix");
} // n001c0e60
void YS::OBJ::detach() {
    using namespace n001c0e60;
    u8* o = (u8*)this;
    QV p;
    QV unused;
    if (!func_001c0cd8(o)) return;
    u8* par;
    YList* l = (YList*)(*(u8**)(o + 0x570) + 0x760);
    YNode* node = (YNode*)(o + 0x670);
    YNode* prev;
    if (node == l->head) {
        prev = 0;
        l->head = *(YNode**)(o + 0x75c);
    } else {
        for (prev = l->head; prev->next != node; prev = prev->next) {}
        prev->next = node->next;
    }
    if (node == l->tail) l->tail = prev;
    node->next = 0;
    if (*(s32*)(*(u8**)(o + 0xc) + 4) != *(s32*)(o + 0x578))
        func_0016bd60(o, *(s32*)(o + 0x578));
    p = *YS__OBJ__get_pos(*(u8**)(o + 0x570));
    *(s32*)(o + 0x60c) = *(s32*)(o + 0x80c);
    par = (u8*)*(s32*)(o + 0x570);
    *(s32*)(par + 0x60c) = *(s32*)(par + 0x80c);
    *(u8**)(o + 0x570) = 0;
    asm volatile("" ::: "memory");
    u8 b = (*(u16*)(o + 0x576) >> 1) & 1;
    if (!b) {
        *(u32*)(o + 0x7f8) &= ~8;
        func_0016aeb8(o, func_002f8ad0(-*(f32*)(o + 0x60), -*(f32*)(o + 0x68)));
    }
    if (func_0019bad8(o)) {
        QV* pos = (QV*)(o + 0x70);
        asm volatile("");
        *(QV*)(o + 0x590) = p;
        QV* dst = (QV*)(o + 0x5a0);
        QV t;
        QV* src; asm("addiu %0,%1,112" : "=r"(src) : "r"(o), "r"(dst));
        QV* tp; asm("la %0,%1" : "=r"(tp) : "m"(t), "r"(src));
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(tp), "r"(src), "r"(&p) : "memory");
        *dst = *tp;
        *(u64*)(o + 0x600) |= 1;
        dk__Octree__collisionToMap((QV*)(o + 0x590), pos);
        func_0016ace0(o, (QV*)(o + 0x5c0));
    } else {
        func_0016ace0(o, (QV*)(o + 0x70));
    }
    if (*(s32*)(o + 0x57c)) {
        s32 t = *(s32*)(o + 0x584);
        func_0016cc18(*(s32*)(o + 0x57c), *(s32*)(o + 0x580), &t, 1, 0);
    }
    YS__OBJ__make_matrix(o);
}
#undef QCP

// 001c1020 (from src/anon/tiny_auto80_fptr4.cpp)
namespace n001c1020 {
u32 func_001c0cd8(u32, u32, u32, u32) asm("_Z13func_001c0cd8jjjj");
u32 YS__OBJ__attach(u32, u32, u32, u32) asm("_Z15YS__OBJ__attachjjjj");
u32 func_001c1020(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001c1020jjjj");
u32 func_001c1020(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r16, r17;
    r16 = r4;
    r17 = r5;
    u32 (*fp_call4_001c0cd8)(u32, u32, u32, u32) = func_001c0cd8;
    r2 = fp_call4_001c0cd8(r4, r5, r6, r7);
    r6 = (u32)(*(u16*)((u32)r16 + (s32)(1396)));
    r4 = r16;
    r7 = (u32)(*(u16*)((u32)r16 + (s32)(1398)));
    r5 = r17;
    return YS__OBJ__attach(r4, r5, r6, r7);
}
} // n001c1020

// 001c1060 (from src/anon/batch_w28.cpp)
namespace n001c1060 {
void* YS__OBJ__Each(void*) asm("YS__OBJ__Each");
u32 func_001c0cd8(void*) asm("func_001c0cd8");
void func_001c0e60(void*) asm("func_001c0e60");
void YS__OBJ__DetachAll(void) asm("YS__OBJ__DetachAll");
void YS__OBJ__DetachAll(void) {
    void* p = 0;
    while ((p = YS__OBJ__Each(p)) != 0) {
        if (func_001c0cd8(p)) func_001c0e60(p);
    }
}
} // n001c1060

// 001c10b8 (from src/anon/tiny.cpp)
namespace n001c10b8 {
void func_001c10b8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001c10b8jjjj");
void func_001c10b8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x01d5u << 16);
    *(u32*)((u32)b + (-27384)) = (u32)a0;
}
} // n001c10b8

// 001c10c8 (from src/anon/batch_w23.cpp)
namespace n001c10c8 {
struct E64 { u16 h; u8 pad[62]; };
extern E64 D_01d49388[6] asm("D_01d49388");
void func_001c10c8(void) asm("func_001c10c8");
void func_001c10c8(void) {
    s32 i;
    E64* e = D_01d49388;
    for (i = 5; i >= 0; i--) {
        e->h = 0;
        e++;
    }
}
} // n001c10c8

// 001c10f8 (from src/anon/batch_w11.cpp)
namespace n001c10f8 {
extern u8* D_01d49508 asm("D_01d49508");
extern u32 D_00320898 asm("D_00320898");
u8 func_002fd248(void*, void*, u32, s32, void*) asm("func_002fd248");
s32 func_001c10f8(void* a) asm("func_001c10f8");
s32 func_001c10f8(void* a) {  // request_pool_block64
    u8* g = D_01d49508;
    return func_002fd248(a, g + 8, *(u32*)(g + 4), 64, &D_00320898);
}
} // n001c10f8

// 001c1130 (from src/anon/batch_w36.cpp)
namespace n001c1130 {
struct Blk64 { u32 w[16]; };
u8* func_001c10f8(void) asm("func_001c10f8");
extern Blk64 D_01d49388[] asm("D_01d49388");
Blk64* func_001c1130(void) asm("func_001c1130");
Blk64* func_001c1130(void) {  // copy_record_block_to_table
    u8* p = func_001c10f8();  // request_pool_block64
    D_01d49388[p[36]] = *(Blk64*)p;
    return &D_01d49388[p[36]];
}
} // n001c1130

// 001c11a8 (from src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n001c11a8 {
u32 func_001c10f8(u32, u32, u32, u32) asm("_Z13func_001c10f8jjjj");
extern u8 D_01d49388 asm("D_01d49388");
u32 func_001c11a8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001c11a8jjjj");
u32 func_001c11a8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u;
    r2 = func_001c10f8(r4, r5, r6, r7);  // request_pool_block64
    r14 = (u32)(*(u8*)((u32)r2 + (s32)(36)));
    r15 = (u32)&D_01d49388;
    r14 = (u32)(r14 << 6);
    r14 = (u32)(r14 + r15);
    *(u16*)((u32)r14 + (s32)(0)) = (u16)0u;
    return r2;
}
} // n001c11a8

// 001c11e0 (from src/anon/batch_w12.cpp)
namespace n001c11e0 {
struct Slot64 { u16 used; u8 pad[62]; };
extern Slot64 D_01d49388[] asm("D_01d49388");
Slot64* func_001c11e0(void) asm("func_001c11e0");
Slot64* func_001c11e0(void) {
    s32 i;
    for (i = 5; i > 0; i--)
        if (D_01d49388[i].used) return &D_01d49388[i];
    return 0;
}
} // n001c11e0

// 001c1218 (from src/anon/tiny_auto80_queue.cpp)
namespace n001c1218 {
u32 YS__STATUS__IsDisableCampMenu(...) asm("YS__STATUS__IsDisableCampMenu");
u32 func_001c11e0(...) asm("func_001c11e0");
u32 func_001c10f8(...) asm("func_001c10f8");
u32 func_001c1218() asm("_Z13func_001c1218v");
u32 func_001c1218() {
    u32 s0 = func_001c11e0();
    if (s0 == 0) {
        if (YS__STATUS__IsDisableCampMenu() != 0) {
            s0 = func_001c10f8(6);  // request_pool_block64
        }
    }
    return s0;
}
} // n001c1218

// 001c1268 (from src/anon/batch_w8021.cpp)
namespace n001c1268 {
inline void* operator new(unsigned int, void* p) { return p; }
struct W8021Pool { u8 pad[0x1c]; };
s32 func_001050c8(void) asm("func_001050c8");
void func_001db710(W8021Pool*, s32, s32, s32) asm("func_001db710");
void* func_001050d8(s32) asm("func_001050d8");
struct W8021Buf {
    s32 a; const s32 mode; s32 sz; s32 c; s32 d; W8021Pool pool; void* buf; s32 e;
    inline __attribute__((always_inline)) W8021Buf(s32 a_, s32 mode_, s32 b, s32 n)
        : mode(mode_) {
        a = a_;
        sz = 16;
        d = 0;
        c = 0;
        func_001db710(&pool, func_001050c8(), b, n);
        e = 0;
        switch (mode_) {
        case 0: buf = func_001050d8(n << 4); break;
        case 1: buf = func_001050d8(n << 4); break;
        }
    }
};
void func_001c1268(W8021Buf* o, s32 a, s32 mode, s32 b, s32 n) asm("func_001c1268");
void func_001c1268(W8021Buf* o, s32 a, s32 mode, s32 b, s32 n) {
    new (o) W8021Buf(a, mode, b, n);
}
} // n001c1268

// 001c1308 (from src/anon/batch_w8021.cpp)
namespace n001c1308 {
inline void* operator new(unsigned int, void* p) { return p; }
struct W8021Pool { u8 pad[0x1c]; };
s32 func_001050c8(void) asm("func_001050c8");
void func_001db710(W8021Pool*, s32, s32, s32) asm("func_001db710");
void* func_001050d8(s32) asm("func_001050d8");
struct W8021Buf {
    s32 a; const s32 mode; s32 sz; s32 c; s32 d; W8021Pool pool; void* buf; s32 e;
    inline __attribute__((always_inline)) W8021Buf(s32 a_, s32 mode_, s32 b, s32 n)
        : mode(mode_) {
        a = a_;
        sz = 16;
        d = 0;
        c = 0;
        func_001db710(&pool, func_001050c8(), b, n);
        e = 0;
        switch (mode_) {
        case 0: buf = func_001050d8(n << 4); break;
        case 1: buf = func_001050d8(n << 4); break;
        }
    }
};
void YS__MASSEFFECT__MANAGER__MANAGER(W8021Buf* o, s32 a, s32 mode, s32 b, s32 n) asm("YS__MASSEFFECT__MANAGER__MANAGER");
void YS__MASSEFFECT__MANAGER__MANAGER(W8021Buf* o, s32 a, s32 mode, s32 b, s32 n) {
    new (o) W8021Buf(a, mode, b, n);
}
} // n001c1308

// 001c13a8 (from src/anon/batch_w21.cpp)
namespace n001c13a8 {
void func_00105110(void*) asm("func_00105110");
void func_001dc920(u32) asm("func_001dc920");
void func_001db7d0(void*) asm("func_001db7d0");
struct Member20Dtor { u32* self; ~Member20Dtor() { func_001db7d0(self + 5); } };
void func_001c13a8(u32* p) asm("func_001c13a8");
void func_001c13a8(u32* p) {
    Member20Dtor g = { p };
    func_001dc920(p[0]);
    func_00105110((void*)p[12]);
}
} // n001c13a8

// 001c13e8 (from src/anon/batch_w22.cpp)
namespace n001c13e8 {
void func_00105110(void*) asm("func_00105110");
void func_001dc920(u32) asm("func_001dc920");
u8 func_001db7d0(void*) asm("func_001db7d0");
u32 func_001c13e8(u32* p) asm("func_001c13e8");
u32 func_001c13e8(u32* p) {
    func_001dc920(p[0]);
    func_00105110((void*)p[12]);
    return func_001db7d0(p + 5);
}
} // n001c13e8

// 001c1428 (from src/anon/batch_w1789_nsa.cpp)
namespace n001c1428 {
struct W1789Ctx { u32 v; };
struct W1789Node { u8 pad[0x24]; W1789Node* next; };
struct W1789List { u8 pad[0xc]; W1789Node* head; u8 pad2[0x30 - 0x10]; W1789Ctx ctx; s32 count; };
s32 func_001c18d0(W1789Node*) asm("func_001c18d0");
void func_001c1a30(W1789Node*, W1789Ctx*) asm("func_001c1a30");
void func_001c1890(W1789Node*) asm("func_001c1890");
void func_001c16a0(W1789List*, s32) asm("func_001c16a0");
void func_001c1428(W1789List* l) asm("func_001c1428");
void func_001c1428(W1789List* l) {
    W1789Node* n = l->head;
    W1789Ctx c = l->ctx;
    W1789Node* it = n;
    l->count = 0;
    while (n) {
        W1789Node* next = !it ? l->head : it->next;
        it = next;
        if (func_001c18d0(n)) { func_001c1a30(n, &c); l->count++; }
        else if (n) func_001c1890(n);
        n = next;
    }
    func_001c16a0(l, l->count);
}
} // n001c1428

// 001c14e0 (from src/anon/batch_w3760_nsa.cpp)
namespace n001c14e0 {
struct QV { f32 x, y, z, w; } __attribute__((aligned(16)));
struct QM { QV r[4]; } __attribute__((aligned(16)));
static inline void MulMat(QM* r, const QM* a, const QM* b)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tvmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\tvmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\tvmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\tsqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)"
                 : : "r"(r), "r"(a), "r"(b) : "memory");
}
struct Cam { u8 pad[16]; QM m; };
struct ONode { u8 pad[0x24]; ONode* next; };
struct LNode { u8 pad[4]; s32 v; LNode* next; };
struct LList { LNode* head; s32 n; };
struct Mgr { u8 pad[0xc]; ONode* head; u8 pad2[0x1c]; s32 cnt; s32 a30; s32 n34; };
static inline LNode* LNext(LList* l, LNode* q) { return !q ? l->head : q->next; }
static inline ONode* ONext(Mgr* g, ONode* q) { return !q ? g->head : q->next; }
u8* func_001050d8(s32) asm("func_001050d8");
void func_00105110(u8*) asm("func_00105110");
QM* kn__getProjection(s32) asm("kn__getProjection");
Cam* func_00106a60(s32) asm("func_00106a60");
s32 func_001c18d0(ONode*) asm("func_001c18d0");
void func_001c1938(ONode*, LList*, u8*, QM*) asm("func_001c1938");
void func_001c1890(ONode*) asm("func_001c1890");
void func_001c1a30(s32, s32*) asm("func_001c1a30");
void func_001c16a0(Mgr*, s32) asm("func_001c16a0");
void func_001c14e0(Mgr* g) asm("func_001c14e0");
void func_001c14e0(Mgr* g) {
    LList l;
    QM m;
    QM* pm = &m;
    s32 t;
    u8* buf = func_001050d8(g->cnt * 12);
    l.n = 0;
    l.head = 0;
    QM* a = kn__getProjection(1);
    Cam* c = func_00106a60(1);
    MulMat(pm, a, c ? &c->m : 0);
    ONode* cur = g->head;
    u8* w = buf;
    ONode* p = cur;
    t = g->a30;
    g->n34 = 0;
    while (p) {
        cur = ONext(g, cur);
        if (func_001c18d0(p)) {
            func_001c1938(p, &l, w, pm);
            w += 12;
            g->n34++;
        } else if (p) {
            func_001c1890(p);
        }
        p = cur;
    }
    w = 0;
    while ((w = (u8*)LNext(&l, (LNode*)w)) != 0) func_001c1a30(((LNode*)w)->v, &t);
    func_001c16a0(g, g->n34);
    func_00105110(buf);
}
} // n001c14e0

// 001c16a0 (from src/anon/batch_w27.cpp)
namespace n001c16a0 {
void func_001dca30(u32, u32, u32) asm("func_001dca30");
void func_001c16a0(u32* p, u32 x) asm("func_001c16a0");
void func_001c16a0(u32* p, u32 x) {
    switch (p[1]) {
    case 0: func_001dca30(p[0], p[12], x); break;
    case 1: func_001dca30(p[0], p[12], x); break;
    }
}
} // n001c16a0

// 001c16f0 (from src/anon/tiny_auto80_queue.cpp)
namespace n001c16f0 {
u32 func_001c16f0(u32* a0, u32* a1) asm("_Z13func_001c16f0PjS_");
u32 func_001c16f0(u32* a0, u32* a1) {
    if (a1 == 0) {
        return a0[3];
    }
    return a1[9];
}
} // n001c16f0

// 001c1708 (from src/anon/batch_w22.cpp)
namespace n001c1708 {
void func_001c1890(u8*) asm("func_001c1890");
void func_001c1708(u8* p) asm("func_001c1708");
void func_001c1708(u8* p) {
    u8* n = *(u8**)(p + 12);
    while (n) {
        u8* nx = *(u8**)(n + 36);
        if (n) func_001c1890(n);
        n = nx;
    }
}
} // n001c1708

// 001c1748 (from src/anon/batch_w43.cpp)
namespace n001c1748 {
static inline void cpq(void* d, const void* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
struct NdB { u8 q[16]; u32 f16; bool b20; s8 b21; u8 b22; s8 b23; bool b24; u8 pad[3]; void* owner; u32 f32; NdB* next; };
struct LLB { NdB* head; NdB* tail; };
struct LsB { u8 pad[8]; u8 b8; u8 pad2[3]; LLB list; };
void func_001c1748(NdB* n, LsB* l, void* src, u32 a3) asm("func_001c1748");
void func_001c1748(NdB* n, LsB* l, void* src, u32 a3) {  // obj_init_from_src
    cpq(n, src);
    n->f16 = a3;
    n->b21 = -128;
    n->b20 = false;
    n->b22 = l->b8;
    n->b23 = -1;
    n->b24 = false;
    n->owner = l;
    n->f32 = 0;
    LLB* L = &l->list;
    if (!L->tail) { L->tail = n; L->head = n; n->next = 0; } else { L->tail->next = n; n->next = 0; L->tail = n; }
}
} // n001c1748

// 001c17a8 (gap, second copy of 001c1748)
namespace n001c17a8 {
static inline void cpq(void* d, const void* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
struct NdB { u8 q[16]; u32 f16; bool b20; s8 b21; u8 b22; s8 b23; bool b24; u8 pad[3]; void* owner; u32 f32; NdB* next; };
struct LLB { NdB* head; NdB* tail; };
struct LsB { u8 pad[8]; u8 b8; u8 pad2[3]; LLB list; };
void func_001c17a8(NdB* n, LsB* l, void* src, u32 a3) asm("func_001c17a8");
void func_001c17a8(NdB* n, LsB* l, void* src, u32 a3) {  // obj_init_from_src
    cpq(n, src);
    n->f16 = a3;
    n->b21 = -128;
    n->b20 = false;
    n->b22 = l->b8;
    n->b23 = -1;
    n->b24 = false;
    n->owner = l;
    n->f32 = 0;
    LLB* L = &l->list;
    if (!L->tail) { L->tail = n; L->head = n; n->next = 0; } else { L->tail->next = n; n->next = 0; L->tail = n; }
}
} // n001c17a8

// 001c1808 (from src/anon/batch_w51.cpp)
namespace n001c1808 {
struct LItem { u8 pad[12]; LItem* head; LItem* tail; u8 pad2[8]; LItem* owner; u32 pad3; LItem* next; };
struct LItemList { LItem* head; LItem* tail; };
struct NoTail { ~NoTail() {} };
void func_001db8b8(void*, LItem*) asm("func_001db8b8");
void func_001c1808(LItem* n) asm("func_001c1808");
void func_001c1808(LItem* n) {
    NoTail g;
    LItemList* l = (LItemList*)&n->owner->head;
    LItem* prev;
    if (n == l->head) {
        prev = 0;
        l->head = n->next;
    } else {
        prev = l->head;
        while (prev->next != n) prev = prev->next;
        prev->next = n->next;
    }
    if (n == l->tail) l->tail = prev;
    n->next = 0;
    func_001db8b8((u8*)n->owner + 20, n);
}
} // n001c1808

// 001c1890 (from src/anon/batch_w23.cpp)
namespace n001c1890 {
void func_003208a8(void*, void*) asm("func_003208a8");
u8 func_001db8b8(void*, void*) asm("func_001db8b8");
s32 func_001c1890(u8* p) asm("func_001c1890");
s32 func_001c1890(u8* p) {
    func_003208a8(*(u8**)(p + 28) + 12, p);
    return func_001db8b8(*(u8**)(p + 28) + 20, p);
}
} // n001c1890

// 001c18d0 (from src/anon/batch_w36.cpp)
namespace n001c18d0 {
struct Fn18 { u8 pad[16]; s32 (*f)(Fn18*); u8 pad2[3]; u8 b23; u32 pad3; u32* f28; u8* f32; };
s32 func_001c18d0(Fn18* p) asm("func_001c18d0");
s32 func_001c18d0(Fn18* p) {
    if (!p->f(p)) return 0;
    if (!p->f32) return 1;
    u8 v;
    switch (p->f28[1]) {
    case 0: v = p->f32[15]; break;
    case 1: v = p->f32[13]; break;
    default: v = 0; break;
    }
    p->b23 = v;
    return 1;
}
} // n001c18d0

// 001c1938 (from src/anon/batch_w76.cpp)
namespace n001c1938 {
struct FV {
    f32 x, y, z, w;
    FV() {}
    FV& operator=(const FV& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct M44 { FV r[4]; };
static inline FV MulMV(const M44* m, const FV* v)
{
    FV out;
    asm volatile(
        "lqc2 $vf5, 0(%1)\n\t"
        "lqc2 $vf1, 0(%2)\n\t"
        "lqc2 $vf2, 16(%2)\n\t"
        "lqc2 $vf3, 32(%2)\n\t"
        "lqc2 $vf4, 48(%2)\n\t"
        "vmulax.wxyz ACC, $vf1, $vf5x\n\t"
        "vmadday.wxyz ACC, $vf2, $vf5y\n\t"
        "vmaddaz.wxyz ACC, $vf3, $vf5z\n\t"
        "vmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
        "sqc2 $vf5, 0(%0)"
        : : "r"(&out), "r"(v), "r"(m) : "memory");
    return out;
}
struct ZNode { f32 key; FV* pos; ZNode* next; };
struct ZList { ZNode* head; ZNode* tail; };
static inline ZNode* NextZ(ZList* l, ZNode* n)
{
    if (!n) return l->head;
    return n->next;
}
void func_001c1938(FV* v, ZList* list, ZNode* n, M44* m) asm("func_001c1938");
void func_001c1938(FV* v, ZList* list, ZNode* n, M44* m)
{
    v->w = 1.0f;
    FV t;
    t = MulMV(m, v);
    n->pos = v;
    n->key = t.z / t.w;
    ZNode* cur = 0;
    ZNode* prev = 0;
    while ((cur = NextZ(list, cur))) {
        if (cur->key >= n->key) break;
        prev = cur;
    }
    if (!prev) {
        if (!list->head) {
            list->tail = n;
            list->head = n;
            n->next = 0;
        } else {
            n->next = list->head;
            list->head = n;
        }
    } else if (prev == list->tail) {
        prev->next = n;
        n->next = 0;
        list->tail = n;
    } else {
        n->next = prev->next;
        prev->next = n;
    }
}
} // n001c1938

// 001c1a30 (from src/anon/batch_w88.cpp)
namespace n001c1a30 {
union U1c1a30 { f32 f; u8* p; u8 b; };
void func_001c1a30(u8* p, U1c1a30** out) asm("func_001c1a30");
void func_001c1a30(u8* p, U1c1a30** out) {
    *(U1c1a30**)(p + 32) = *out;
    switch (*(s32*)(*(u8**)(p + 28) + 4)) {
    case 0:
        (*out)[0].f = *(f32*)(p + 0);
        (*out)[1].f = *(f32*)(p + 4);
        (*out)[2].f = *(f32*)(p + 8);
        ((u8*)*out)[12] = p[20];
        ((u8*)*out)[13] = p[21];
        ((u8*)*out)[14] = p[22];
        ((u8*)*out)[15] = p[23];
        *out += 4;
        break;
    case 1:
        (*out)[0].f = *(f32*)(p + 0);
        (*out)[1].f = *(f32*)(p + 4);
        (*out)[2].f = *(f32*)(p + 8);
        ((u8*)*out)[12] = p[21];
        ((u8*)*out)[13] = p[23];
        ((u8*)*out)[14] = p[24];
        ((u8*)*out)[15] = p[22];
        *out += 4;
        break;
    }
}
} // n001c1a30

// 001c1b08 (from src/anon/batch_w1957_nsa.cpp)
namespace n001c1b08 {
struct W1957Vec {
    f32 x, y, z, w;
    W1957Vec() {}
    W1957Vec& operator=(const W1957Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
void func_0017f488(int, int, float, float) asm("_Z13func_0017f488iiff");
struct W1957Range { u8 pad[12]; s16 lo, hi, z; };
struct W1957Tgt {
    virtual void v0();
    virtual void v1();
    virtual W1957Vec pos();
    u8 pad[36];
    W1957Range* range;
};
struct W1957Info { u32 f0, f4, flags; };
struct W1957Obj {
    u8 pad0[12];
    W1957Info* info;        // 0x0c
    u8 pad10[320 - 16];
    u8 sub[32];             // 0x140
    u32 flags;              // 0x160
    u8 pad164[2732 - 356];
    W1957Tgt* tgt;          // 0xaac
    f32 dist;               // 0xab0
    f32 f2740;              // 0xab4
    s32 act;                // 0xab8
};
W1957Vec func_0016be98(W1957Obj*) asm("func_0016be98");
void func_001c1fe0(W1957Obj*) asm("func_001c1fe0");
void w1957_change_action(W1957Obj*, s32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
extern s32 D_003638d0 asm("D_003638d0");
static inline W1957Vec w1957_sub(const W1957Vec& a, const W1957Vec& b) {
    W1957Vec r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 w1957_len(const W1957Vec& v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder"
        : "=f"(len) : "r"(&v) : "$8", "memory");
    return len;
}
static inline f32 w1957_frand(void) {
    D_003638d0 = D_003638d0 * 0x10dcd;
    return (f32)(u32)D_003638d0 * 2.3283064e-10f;
}
static inline bool w1957_flag(W1957Obj* o) {
    return (o->info->flags & 2) || (o->flags & 0x40);
}
void YS__BTLOBJ__tornado(W1957Obj* self, W1957Tgt* tgt, u8 on) asm("YS__BTLOBJ__tornado");
void YS__BTLOBJ__tornado(W1957Obj* self, W1957Tgt* tgt, u8 on) {
    self->tgt = tgt;
    W1957Vec d;
    d = w1957_sub(tgt->pos(), func_0016be98(self));
    f32 len = w1957_len(d);
    W1957Range* r = tgt->range;
    f32 lo = r->lo;
    f32 hi = r->hi;
    self->dist = lo + w1957_frand() * (hi - lo);
    s32 act = on ? 20 : 21;
    self->f2740 = tgt->range->z;
    self->act = act;
    func_0017f488((int)self->sub, act, 0.0f, 0.0f);
    func_001c1fe0(self);
    if (w1957_flag(self)) w1957_change_action(self, 15);
    else w1957_change_action(self, 14);
}
} // n001c1b08

// 001c1cc8 (gap)
namespace n001c1cc8 {
extern u32 D_003638d0 asm("D_003638d0");
void func_001c1fe0(u8*) asm("func_001c1fe0");
void func_0017f540(u8*, s32, f32, f32) asm("func_0017f540");
typedef void (*VF1cc8)(u8*, u8*, f32);
void func_001c1cc8(u32, u8* p) asm("func_001c1cc8");
void func_001c1cc8(u32, u8* p) {
    if (*(u32*)(p + 2732) == 0) {
        D_003638d0 = D_003638d0 * 0x10dcd;
        f32 r = (f32)D_003638d0 * 2.3283064e-10f * 20.0f;
        u8* o = *(u8**)(p + 12);
        (*(VF1cc8*)(*(u8**)o + 12))(o, p, r);
        func_0017f540(p + 320, 4, 8.0f, 0.0f);
        return;
    }
    func_001c1fe0(p);
}
} // n001c1cc8

// 001c1d90 (from src/anon/batch_w36.cpp)
namespace n001c1d90 {
void func_0016bd60(u8*, u32) asm("func_0016bd60");
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
void func_001c1fe0(u8*) asm("func_001c1fe0");
void YS__ACTION_FLYTORNADO__control(u32, u8* p) asm("YS__ACTION_FLYTORNADO__control");
void YS__ACTION_FLYTORNADO__control(u32, u8* p) {
    if (*(u32*)(p + 2732) == 0) {
        func_0016bd60(p, 5);
        func_0017f488(p + 320, 0, 8.0f, 0.0f);
        return;
    }
    func_001c1fe0(p);
}
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
} // n001c1d90

// 001c1df8 (from src/anon/batch_w1972_nsa.cpp)
namespace n001c1df8 {
struct W1972Vec {
    f32 x, y, z, w;
    W1972Vec() {}
    W1972Vec& operator=(const W1972Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1972Tgt {
    virtual void v0();
    virtual void v1();
    virtual W1972Vec pos();
};
struct W1972Obj {
    u8 pad0[32];
    W1972Vec p20;           // 0x20
    u8 pad30[2732 - 48];
    W1972Tgt* tgt;          // 0xaac
    f32 dist;               // 0xab0
    f32 f2740;              // 0xab4
};
extern f32 D_00349e10 asm("D_00349e10");
static inline W1972Vec w1972_sub(const W1972Vec& a, const W1972Vec& b) {
    W1972Vec r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 w1972_norm(W1972Vec* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
static inline W1972Vec w1972_scale(const W1972Vec& a, f32 s) {
    W1972Vec r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
        : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
static inline void w1972_addto(W1972Vec& a, const W1972Vec& b) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
        : : "r"(&a), "r"(&b) : "memory");
}
W1972Vec func_0016be98(W1972Obj*) asm("func_0016be98");
W1972Vec YS__MATH__VectorRotY(f32, const W1972Vec&) asm("YS__MATH__VectorRotY");
W1972Vec w1972_ctarget(W1972Obj* self) asm("_Z16ctarget_001c1df8jjjj");
W1972Vec w1972_ctarget(W1972Obj* self) asm("w1972_ctarget");
W1972Vec w1972_ctarget(W1972Obj* self) {
    W1972Vec d;
    W1972Vec u;
    d = w1972_sub(self->tgt->pos(), func_0016be98(self));
    f32 len = w1972_norm(&d);
    f32 t = (len - self->dist) * 0.1f;
    f32 c;
    if (t < -20.0f) c = -20.0f;
    else if (20.0f < t) c = 20.0f;
    else c = t;
    self->p20 = w1972_scale(d, c);
    d = YS__MATH__VectorRotY(1.5707964f, d);
    d.y = 0.0f;
    w1972_norm(&d);
    w1972_addto(self->p20, w1972_scale(d, self->f2740));
    return w1972_scale(self->p20, D_00349e10);
}
} // n001c1df8

// 001c1fe0 (from src/anon/batch_w77.cpp)
namespace n001c1fe0 {
namespace n00124a40 {
struct VObj;
struct VObj { void** vt; };
}
namespace n00151c70 {
struct VObj { void** vt; };
}
namespace n0016cab8 {
struct VObj { void** vt; };
}
namespace n00186a90 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    u32 v[4];
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline f32 Normalize(QWord* v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
}
namespace n001c1fe0 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    u32 v[4];
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline void ScaleIn(QWord* a, f32 k)
{
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(a), "f"(k) : "$8", "memory");
}
static inline QWord Sub(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 Normalize(QWord* v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
struct VObj { void** vt; };
typedef QWord (*PosFn)(VObj*);
QWord func_0016be98(u8*) asm("func_0016be98");
void func_0016aef0(u8*, QWord*) asm("func_0016aef0");
void func_001c1fe0(u8* p) asm("func_001c1fe0");
void func_001c1fe0(u8* p)
{
    QWord n;
    VObj* o = *(VObj**)(p + 2732);
    n = Sub(((PosFn)o->vt[2])(o), func_0016be98(p));
    Normalize(&n);
    f32 k = -1.0f;
    if (*(s32*)(p + 2744) == 21) ScaleIn(&n, k);
    func_0016aef0(p, &n);
}
}
} // n001c1fe0
#undef QCOPY
#undef QCOPY

// 001c20d8 (from src/anon/tiny.cpp)
namespace n001c20d8 {
void func_001c20d8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001c20d8jjjj");
void func_001c20d8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x01d5u << 16);
    *(u32*)((u32)b + (-27376)) = (u32)a0;
}
} // n001c20d8

// 001c20e8 (from src/anon/batch_w3735.cpp)
namespace n001c20e8 {
struct E { u8 type; u8 v[31]; };
struct Tbl { s32 pad; s32 n; E e[1]; };
extern Tbl* D_01d49510 asm("D_01d49510");
struct C { u8 p[8]; u32 f; };
struct Y { u8 p[0xc]; C* c; u8 q[0x160-0x10]; u32 fl; };
struct Z { u8 p[0x588]; u32 f; };
struct X { u8 p[0x10]; Z* a; u8 q[4]; u32 fl; u8 r[0x26-0x1c]; u8 o; u8 idx; };
s32 func_0019c090(void*) asm("func_0019c090");
static inline bool chk2(Y* y) { bool r = false; if ((y->c->f & 2) || (y->fl & 0x40)) r = true; return r; }
static inline bool chk(Y* y) { bool r = false; if (func_0019c090(y) || chk2(y)) r = true; return r; }
static inline bool nchk(Y* y) { return !chk(y); }
void YS__PATTERN__Convert(u32 mask, X* x, Y* y) asm("YS__PATTERN__Convert");
void YS__PATTERN__Convert(u32 mask, X* x, Y* y) {
    if (x->fl & 4) return;
    E* e = D_01d49510->e;
    for (s32 i = 0; i < D_01d49510->n; i++, e++) {
        // Constants held in locals: loop.c then keeps 1/7/8 in s5/s7/s8 like the original.
        s32 one = 1, seven = 7, eight = 8;
        s32 t = e->type;
        if (!(mask & (one << t))) continue;
        if (t == seven) goto c7;
        if (t >= 8) goto g8;
        if (t == 2) goto c2;
    ap: {
        u8 v = e->v[x->idx];
        if (v != 255) x->o = v;
        continue;
        }
    c2:
        if (!x->a) continue;
        if (!(x->a->f & 0x4000)) continue;
        goto ap;
    g8:
        if (t != eight) goto ap;
        if (nchk(y) == false) goto ap;
        continue;
    c7:
        if (chk(y)) continue;
        goto ap;
    }
}
} // n001c20e8

// 001c22c8 (gap, C2 copy of 001c2338)
namespace n001c22c8 {
void func_001980d0(u8*, u32, s32, u32) asm("func_001980d0");
s32 func_0016a020(u8*) asm("func_0016a020");
extern u8 D_003513a8[] asm("D_003513a8");
void func_001c22c8(u8* p, u32 a, u32 b) asm("func_001c22c8");
void func_001c22c8(u8* p, u32 a, u32 b) {
    func_001980d0(p, a, 9, b);
    *(u32*)p = (u32)D_003513a8;
    *(u32*)(p + 1416) |= 0x80000;
    p[943] = 64;
    if (func_0016a020(p) == 1185) *(u32*)(p + 1896) |= 0x10;
}
} // n001c22c8

// 001c2338 (from src/anon/batch_w49.cpp)
namespace n001c2338 {
void func_001980d0(u8*, u32, s32, u32) asm("func_001980d0");
s32 func_0016a020(u8*) asm("func_0016a020");
extern u8 D_003513a8[] asm("D_003513a8");
void func_001c2338(u8* p, u32 a, u32 b) asm("func_001c2338");
void func_001c2338(u8* p, u32 a, u32 b) {
    func_001980d0(p, a, 9, b);
    *(u32*)p = (u32)D_003513a8;
    *(u32*)(p + 1416) |= 0x80000;
    p[943] = 64;
    if (func_0016a020(p) == 1185) *(u32*)(p + 1896) |= 0x10;
}
} // n001c2338

// 001c23a8 (from src/anon/batch_w83.cpp)
namespace n001c23a8 {
extern u8 D_01d49520[] asm("D_01d49520");
extern u32 D_00351408[] asm("D_00351408");
void func_001980d0(void*, void*, s32, void*, f32) asm("func_001980d0");
void* func_001de168b(void*, void*, s32, s32, s32, s32) asm("ryj__PAX__start");
void func_001dcc00(void*, void*) asm("func_001dcc00");
void* func_001050d8(u32) asm("func_001050d8");
void YS__MASSEFFECT__MANAGER__MANAGER(void*, void*, void*, void*, void*) asm("YS__MASSEFFECT__MANAGER__MANAGER");
void func_001c23a8(u8* p, void* a1, void* a2, void* a3, void* t0, void* t1, void* t2) asm("func_001c23a8");
void func_001c23a8(u8* p, void* a1, void* a2, void* a3, void* t0, void* t1, void* t2) {
    func_001980d0(p, a1, 4, D_01d49520, 0.0f);
    *(u32*)p = (u32)D_00351408;
    *(u32*)(p + 1416) |= 0x100000;
    void* h = func_001de168b(p + 156, a2, 0, 1, 0, 0);
    func_001dcc00(h, a3);  // to_1e34e0_field28
    void* o = func_001050d8(56);
    YS__MASSEFFECT__MANAGER__MANAGER(o, h, t0, t1, t2);
    *(void**)(p + 2548) = o;
}
} // n001c23a8

// 001c2490 (from src/anon/batch_w84.cpp)
namespace n001c2490 {
void* func_001050d8(u32) asm("func_001050d8");
void func_001980d0x(void*, u32, s32, void*, f32) asm("func_001980d0");
extern u8 D_01d49520[] asm("D_01d49520");
extern void* D_00351408[] asm("D_00351408");
u32 ryj__PAX__start(void*, u32, s32, s32, s32, s32) asm("ryj__PAX__start");
void func_001dcc00(u32, u32) asm("func_001dcc00");
void* func_001050d8(u32) asm("func_001050d8");
void YS__MASSEFFECT__MANAGER__MANAGER(void*, u32, u32, u32, u32) asm("YS__MASSEFFECT__MANAGER__MANAGER");
void YS__MASSOBJ__MASSOBJ(u8* p, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) asm("YS__MASSOBJ__MASSOBJ");
void YS__MASSOBJ__MASSOBJ(u8* p, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) {
    func_001980d0x(p, a1, 4, D_01d49520, 0.0f);
    *(void**)p = D_00351408;
    *(u32*)(p + 1416) |= 0x100000;
    u32 h = ryj__PAX__start(p + 156, a2, 0, 1, 0, 0);  // scan_list_by_half
    func_001dcc00(h, a3);  // to_1e34e0_field28
    void* o = func_001050d8(56);
    YS__MASSEFFECT__MANAGER__MANAGER(o, h, a4, a5, a6);
    *(void**)(p + 2548) = o;
}
} // n001c2490

// 001c2578 (from src/anon/batch_w10.cpp)
namespace n001c2578 {
void func_0016a9a0(void*) asm("func_0016a9a0");
void func_001c1428(void*) asm("func_001c1428");
void MASSOBJ_OVR_exec(void*) asm("_ZN2YS7MASSOBJ9_OVR_execEv");
void MASSOBJ_OVR_exec(void* o) asm("MASSOBJ_OVR_exec");
void MASSOBJ_OVR_exec(void* o) {
    func_0016a9a0(o);  // to_16a950
    func_001c1428(*(void**)((u8*)o + 2548));
}
} // n001c2578

// 001c25a0 (from src/anon/tiny_auto80_queue.cpp)
namespace n001c25a0 {
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_0016b5b8(...) asm("func_0016b5b8");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_0016b5b8(...) asm("func_0016b5b8");
u32 func_001c13e8(...) asm("func_001c13e8");
u32 YS__MASSOBJ___OVR_leave_req(u32 a0) asm("_Z27YS__MASSOBJ___OVR_leave_reqj");
u32 YS__MASSOBJ___OVR_leave_req(u32 a0) {
    u32 r4 = a0, r2, r16, r17;
    r17 = r4;
    r16 = *(u32*)((u32)r4 + (s32)(2548));
    r4 = r16;
    if (r16 != 0u) {
        r2 = ((u32(*)(u32))func_001c13e8)(r4);
        r4 = r16;
        r2 = ((u32(*)(u32))func_00105110)(r4);
    }
    r4 = r17;
    return ((u32(*)(u32))func_0016b5b8)(r4);
}
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_0016b5b8(...) asm("func_0016b5b8");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
u32 func_0016b5b8(...) asm("func_0016b5b8");
u32 func_00105110(...) asm("func_00105110");
u32 func_00105110(...) asm("func_00105110");
} // n001c25a0

// 001c25e8 (from src/anon/batch_wcx2.cpp)
namespace n001c25e8 {
void* func_001050d8_x9233(u32) asm("func_001050d8");
void* func_001c4520(u8*) asm("func_001c4520");
void* func_001c51d8(u8*) asm("func_001c51d8");
void* func_001ce488(u8*) asm("func_001ce488");
void* func_001d6578(u8*) asm("func_001d6578");
void func_001c7bc8(void*, u8*) asm("func_001c7bc8");
void func_001cc048(void*, u8*) asm("func_001cc048");
void func_001ca678(void*, u8*) asm("func_001ca678");
void func_001cce38(void*, u8*) asm("func_001cce38");
void func_001cbb58(void*, u8*) asm("func_001cbb58");
void func_001d2850(void*, u8*) asm("func_001d2850");
void func_001d7458(void*, u8*) asm("func_001d7458");
void func_001da1d8(void*, u8*) asm("func_001da1d8");
void* YS__MASSOBJ__Create(u8* d) asm("YS__MASSOBJ__Create");
void* YS__MASSOBJ__Create(u8* d) {

    switch (d[5]) {
    case 2: return func_001c4520(d);
    case 3: return func_001c51d8(d);
    case 4: { void* p = func_001050d8_x9233(2560); func_001c7bc8(p, d); return p; }
    case 6: { void* p = func_001050d8_x9233(2560); func_001cc048(p, d); return p; }
    case 7: { void* p = func_001050d8_x9233(2560); func_001ca678(p, d); return p; }
    case 8: { void* p = func_001050d8_x9233(2560); func_001cce38(p, d); return p; }
    case 9: { void* p = func_001050d8_x9233(2560); func_001cbb58(p, d); return p; }
    case 12: { void* p = func_001050d8_x9233(2560); func_001d2850(p, d); return p; }
    case 13: { void* p = func_001050d8_x9233(2560); func_001d7458(p, d); return p; }
    case 10: case 11: case 14: return func_001ce488(d);
    case 15: return func_001d6578(d);
    case 16: { void* p = func_001050d8_x9233(2560); func_001da1d8(p, d); return p; }
    }
    return 0;
}
} // n001c25e8

// 001c2790 (gap)
namespace n001c2790 {
void func_001c2790(u8* o, f32 f) asm("func_001c2790");
void func_001c2790(u8* o, f32 f) {
    *(s32*)(*(u8**)(o + 2548) + 8) = (s32)(f * 16.0f);
}
} // n001c2790

// 001c27b8 (gap, copy of 001c2858)
namespace n001c27b8 {
void func_001c27b8(f32* o, void* a, void* b, s32 n) asm("func_001c27b8");
void func_001c27b8(f32* o, void* a, void* b, s32 n) {  // copy_2quads_and_ratio
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(o), "r"(a) : "$8", "memory");
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(o + 4), "r"(b) : "$8", "memory");
    f32 r = o[6] / o[4];
    ((s32*)o)[14] = 0;
    ((s32*)o)[15] = 0;
    f32 s = __builtin_sqrtf((f32)n / r);
    s32 w = (s32)s;
    s32 h = (s32)(s * r);
    ((s32*)o)[12] = w;
    ((s32*)o)[13] = h;
    o[8] = o[4] / (f32)w;
    o[10] = o[6] / (f32)h;
}
} // n001c27b8

// 001c2858 (from src/anon/batch_w68.cpp)
namespace n001c2858 {
void func_001c2858(f32* o, void* a, void* b, s32 n) asm("func_001c2858");
void func_001c2858(f32* o, void* a, void* b, s32 n) {  // copy_2quads_and_ratio
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(o), "r"(a) : "$8", "memory");
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(o + 4), "r"(b) : "$8", "memory");
    f32 r = o[6] / o[4];
    ((s32*)o)[14] = 0;
    ((s32*)o)[15] = 0;
    f32 s = __builtin_sqrtf((f32)n / r);
    s32 w = (s32)s;
    s32 h = (s32)(s * r);
    ((s32*)o)[12] = w;
    ((s32*)o)[13] = h;
    o[8] = o[4] / (f32)w;
    o[10] = o[6] / (f32)h;
}
} // n001c2858

// 001c28f8 (from src/anon/batch_w3736_nsa.cpp)
namespace n001c28f8 {
struct G { f32 x, y, z, pad0; f32 ox, ry, oz, pad1; f32 sx, pad2, sz, pad3; s32 nx, ny, ix, iy; };
struct V4 { f32 x, y, z, w; };
extern u32 D_003638d0 asm("D_003638d0");
static inline f32 frand(f32 max) { D_003638d0 = D_003638d0 * 0x10dcd; return (f32)D_003638d0 * 2.3283064e-10f * max; }
s32 func_001c28f8(G* g, V4* o, u8 jit) asm("func_001c28f8");
s32 func_001c28f8(G* g, V4* o, u8 jit) {
    if (g->iy >= g->ny) return 0;
    f32 half = 0.5f; register f32 fiy asm("$f7") = (f32)g->iy; register f32 sz asm("$f4") = g->sz; f32 oz = g->oz;
    f32 dx = g->sx * (f32)g->ix - g->ox * half; register f32 dz asm("$f2") = sz * fiy - oz * half; register f32 y asm("$f3") = g->y; f32 x=g->x+dx, z=g->z+dz;
    o->w = 0; asm("" : "+f"(y) : "m"(o->w)); o->y = y; o->x = x; o->z = z;
    if (jit) {
        f32 r = frand(g->sx); f32 ry = g->ry; o->x += r;
        f32 r2 = frand(ry); f32 sz = g->sz; o->y -= r2;
        o->z += frand(sz);
    }
    if (++g->ix >= g->nx) { g->ix = 0; g->iy++; }
    return 1;
}
} // n001c28f8

// 001c2ad8 (from src/anon/batch_w1670.cpp)
namespace n001c2ad8 {
struct F4_w1670 { f32 a, b, c, d; };
extern F4_w1670 D_01d49520 asm("D_01d49520");
void wtarget_001c2ad8(u32 a, u32 b, u32, u32) asm("_Z16wtarget_001c2ad8jjjj");
void wtarget_001c2ad8(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        f32 z = 0.0f, o = 1.0f;
        D_01d49520.a = z;
        D_01d49520.b = z;
        D_01d49520.c = z;
        D_01d49520.d = o;
    }
}
} // n001c2ad8

// 001c2b18 (from src/anon/tiny_wrappers_more.cpp)
namespace n001c2b18 {
u32 func_001c2ad8(u32, u32, u32, u32) asm("_Z13func_001c2ad8jjjj");
u32 func_001c2b18(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001c2b18jjjj");
u32 func_001c2b18(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001c2ad8(0x00000001u, 0x0000ffffu, a2, a3);
}
} // n001c2b18

// 001c2b38 (gap, _GLOBAL__D_ stub)
namespace n001c2b38 {
u32 func_001c2ad8(u32, u32, u32, u32) asm("_Z13func_001c2ad8jjjj");
u32 func_001c2b38(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001c2b38");
u32 func_001c2b38(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001c2ad8(0, 0x0000ffffu, a2, a3);
}
} // n001c2b38
