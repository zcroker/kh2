// Linked unit (see linked_units.tsv).
#include "../common/types.h"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// 002b2a18 (was src/anon/batch_w3798_mam.cpp)
namespace n002b2a18 {
struct St2b2a18 { u32 pad:27; u32 bit:1; u32 pad2:4; };
extern u8* D_0035f634 asm("D_0035f634");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s32 D_0035f14c asm("D_0035f14c");
extern s32 D_0035f148 asm("D_0035f148");
extern s32 D_0035f210 asm("D_0035f210");
extern s16 D_00374cc8[] asm("D_00374cc8");
u8* func_002766d0(void) asm("func_002766d0");
St2b2a18* Tz__JmPuzzle__GetImageInfo(s32) asm("Tz__JmPuzzle__GetImageInfo");
void func_00139d78(u8*) asm("func_00139d78");
s32 func_0023f1b0(s32) asm("func_0023f1b0");
s32 func_0023c4b8(s32, s32) asm("func_0023c4b8");
void dk__Sprite__create(u8*, s32, s32, u8*, s32, s32) asm("dk__Sprite__create");
void func_0028d8c0(u8*, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
void func_00139620(u8*) asm("func_00139620");
void func_0028dcc0(u8*, u8*) asm("func_0028dcc0");
void func_00139570(u8*) asm("func_00139570");
/*TARGET 002b2a18*/
void func_002b2a18(void) asm("func_002b2a18");
void func_002b2a18(void) {
    u8* i = 0;
    s32 off = 0;
    u8* g = func_002766d0();
    St2b2a18* st = Tz__JmPuzzle__GetImageInfo(-1);
    u8* base = D_0035f634;
    s32 id;
    u8* p;
    u8* b;
    u8* q;
    s32 w;
    func_00139d78(base);
    s32 t = D_0035f3d4;
    u32 h; asm("lui %0,0x37" : "=r"(h) : "r"(t));
    id = t + 3;
    s16* tbl = (s16*)(h + 19672);
    register u8 one asm("$23") = 1;
    do {
        if (i != 0) {
            b = D_0035f634;
            id++;
            p = b + 20808;
            b += 20832;
            s32 r = func_0023c4b8(func_0023f1b0(D_0035f210), 6);
            w = D_00374cc8[st->bit];
            dk__Sprite__create(p, id, r, g + 0xdca0, w, 0);
            *(u32*)(b + 184) |= 8;
            func_00139620(p);
            p[405] = 1;
            func_0028dcc0(p, base);
            *(u32*)(b + 184) = (*(u32*)(b + 184) & ~0x2000) | 0x2000;
            func_00139570(p);
        }
        b = D_0035f634;
        b += off;
        p = b + 19992;
        b += 20016;
        w = tbl[st->bit * 3 + (s32)i];
        func_0028d8c0(p, id, D_0035f14c, D_0035f148, D_0035f210, w, -1, 0);
        i++;
        off += 408;
        func_00139620(p);
        *(u32*)(b + 184) |= 8;
        p[405] = one;
        func_0028dcc0(p, base);
        func_00139570(p);
    } while ((s32)i < 2);
    b = D_0035f634;
    p = b + 19584;
    func_0028d8c0(p, 30058, D_0035f14c, D_0035f148, D_0035f210, 115, -1, 0);
    q = b + 19608;
    func_00139620(p);
    *(u32*)(q + 184) |= 8;
    p[405] = 1;
    func_0028dcc0(p, D_0035f634 + 19992);
    func_00139570(p);
}
}  // namespace n002b2a18

// 002b2c80 (was src/anon/batch_w80.cpp)
namespace n002b2c80 {
struct U19_VObj;
struct U19_VObjVt { void* f[5]; void (*f20)(U19_VObj*); };
struct U19_VObj { U19_VObjVt* vt; };
extern u8* D_0035f634 asm("D_0035f634");
s32 func_00139d78(void*) asm("func_00139d78");
void func_00139510(void*) asm("func_00139510");
/*TARGET 002b2c80*/
// 0x002adbd0: definition moved into src/anon/unit_002a99c8.cpp


void func_002b2c80(void) asm("func_002b2c80");
// 0x002adbd0: definition moved into src/anon/unit_002a99c8.cpp


void func_002b2c80(void) {
    s32 i;
    for (i = 0; i < 2; i++) {
        u32 off = i * 408;
        if (func_00139d78(D_0035f634 + off + 19992)) {
            U19_VObj* o = (U19_VObj*)(off + (u32)D_0035f634 + 19992);
            o->vt->f20(o);
        }
    }
    if (func_00139d78(D_0035f634 + 19584)) func_00139510(D_0035f634 + 19584);
    if (func_00139d78(D_0035f634 + 20808)) func_00139510(D_0035f634 + 20808);
}
}  // namespace n002b2c80

// 002b2d48 (was src/anon/batch_w37.cpp)
namespace n002b2d48 {
extern u8* D_0035f634 asm("D_0035f634");
s32 func_00139d78(void*) asm("func_00139d78");
/*TARGET 002b2d48*/
s32 func_002b2d48(void) asm("func_002b2d48");
s32 func_002b2d48(void) {
    s32 r = 0;
    if (func_00139d78(D_0035f634 + 19992) || func_00139d78(D_0035f634 + 20400)) r = 1;
    return r;
}
}  // namespace n002b2d48

// 002b2da8 (was src/anon/batch_w278.cpp)
namespace n002b2da8 {
struct CurItem278 { u8 pad[388]; s32 num; u8 pad2[16]; };
struct CurOwn278 { u8 pad[19584]; CurItem278 item[4]; };
struct CurTbl278 { s16 a, b, c; };
struct CurSt278 { u32 pad:27; u32 bit:1; u32 pad2:4; };
extern CurOwn278* D_0035f634 asm("D_0035f634");
extern CurTbl278 D_00374cd8[] asm("D_00374cd8");
CurSt278* Tz__JmPuzzle__GetImageInfo(s32) asm("Tz__JmPuzzle__GetImageInfo");
// list_entry_by_index_checked
void Call4_278(CurItem278*) asm("_Z16u_call4_00139d78jjjj");
s32 IsHide278(CurItem278*) asm("_ZN2dk5Obj2D6isHideEv");
void Show278(CurItem278*) asm("_ZN2dk5Obj2D4showEv");
void SetNum278(CurItem278*, s32) asm("_ZN2dk6Sprite6setNumEi");
void Attach278(CurItem278*, CurItem278*) asm("_ZN2Tz10MenuCursor12AttachSpriteEz");
/*TARGET 002b2da8*/
void func_002b2da8(s32 idx) asm("func_002b2da8");
void func_002b2da8(s32 idx) {
    CurSt278* st = Tz__JmPuzzle__GetImageInfo(-1);  // list_entry_by_index_checked
    CurItem278* o = &D_0035f634->item[idx + 1];
    Call4_278(o);
    if (IsHide278(o)) Show278(o);
    if (idx != 0) {
        o = &D_0035f634->item[idx];
        if (IsHide278(o)) Show278(o);
        SetNum278(o, D_00374cd8[st->bit].c);
        o = &D_0035f634->item[3];
        if (IsHide278(o)) Show278(o);
    } else {
        o = &D_0035f634->item[1];
        s16 n = D_00374cd8[st->bit].a;
        if (o->num != n) SetNum278(o, n);
    }
    o = &D_0035f634->item[0];
    if (IsHide278(o)) Show278(o);
    Attach278(o, &D_0035f634->item[idx + 1]);
}
}  // namespace n002b2da8

// 002b2f28 (was src/anon/batch_w95.cpp)
namespace n002b2f28 {
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& s) {
        if (this != &s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&s) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline Vq operator*(const Vq& a, f32 s) {
    Vq r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
struct AnmId3 { s16 a, b, c; };
// 0x002a16b8: definition moved into src/anon/unit_002a0908.cpp

extern u8* D_0035f634 asm("D_0035f634");
extern AnmId3 D_00374cd8[] asm("D_00374cd8");
u32* Tz__JmPuzzle__GetImageInfo(s32) asm("Tz__JmPuzzle__GetImageInfo");
// list_entry_by_index_checked
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_001396c0(u8*) asm("func_001396c0");
void func_00139570(u8*) asm("func_00139570");
void func_00138c10(u8*, s16) asm("func_00138c10");
void func_0028dcc0(u8*, u8*) asm("func_0028dcc0");
/*TARGET 002b2f28*/
void func_002b2f28(s32 idx) asm("func_002b2f28");
void func_002b2f28(s32 idx) {
    u32* st = Tz__JmPuzzle__GetImageInfo(-1);  // list_entry_by_index_checked
    u8* p = D_0035f634 + idx * 408 + 19992;
    func_00139d78(p);
    if (!func_001396c0(p)) func_00139570(p);
    p = D_0035f634 + 20808;
    if (!func_001396c0(p)) func_00139570(p);
    if (idx == 0) {
        p = D_0035f634 + 20400;
        if (!func_001396c0(p)) func_00139570(p);
        func_00139570(D_0035f634 + 19584);
        return;
    }
    p = D_0035f634 + 19992;
    func_00138c10(p, D_00374cd8[(st[0] >> 27) & 1].a);
    func_0028dcc0(D_0035f634 + 19584, p);
}
}  // namespace n002b2f28

// 002b3050 (was src/anon/batch_w3764.cpp)
namespace n002b3050 {
struct GEnt { s8 c0; s8 c1; s8 c2; s8 c3; };
struct GSav { u8 pad[488]; GEnt e[1][48]; };
struct GG {
    u8 pad[28]; s16 x[2]; s16 y[2]; u8 pad2[52 - 36];
    u32 : 10; u32 b10 : 1; u32 b11 : 1; u32 b12 : 2;
};
struct GS3 { u32 : 27; u32 b27 : 1; u32 : 4; };
struct GS3b { u8 b0; u8 b1; u8 b2; };
union GS3U { GS3 w; GS3b b; };
struct UV55 { s16 u[4]; s16 v[4]; };
extern GG* D_0035f638 asm("D_0035f638");
extern u8* D_0035f634 asm("D_0035f634");
GSav* func_002a9d68(void) asm("func_002a9d68");
GS3U* Tz__JmPuzzle__GetImageInfo(s32) asm("Tz__JmPuzzle__GetImageInfo");
s32 func_002b2380(s32, s32) asm("func_002b2380");
void func_0028dcc0(u8*, u8*) asm("func_0028dcc0");
void func_002b28b0(u32 a0, s32 idx, s32 mode, UV55* out) asm("func_002b28b0");
void YI__SPRITE__SetDirextUV(u8* p, s16* a, s16* b) asm("YI__SPRITE__SetDirextUV");
// Getter wrapper; the call has to go through an inline for the
// register allocation of q to match.
static inline GS3U* GetCur(s32 i) { return Tz__JmPuzzle__GetImageInfo(i); }
/*TARGET 002b3050*/
void func_002b3050(u8 a0) asm("func_002b3050");
void func_002b3050(u8 a0)
{
    if (a0 != 0 || D_0035f638->b10) {
        u8* q = (u8*)GetCur(-1);
        // t is reused for both lookups (keeps the product out of v0).
        s32 t = func_002b2380(D_0035f638->x[D_0035f638->b11], D_0035f638->y[D_0035f638->b11]);
        s32 off = t * 408;
        u8* s3 = D_0035f634 + off;
        u8* p = D_0035f634 + D_0035f638->b11 * 408 + 19992;
        func_0028dcc0(p, s3);
        if (D_0035f638->b11) {
            UV55 uv;
            p = (u8*)func_002a9d68();
            t = func_002b2380(D_0035f638->x[0], D_0035f638->y[0]);
            u8* base = D_0035f634;
            func_002b28b0(((GS3U*)q)->w.b27, ((GSav*)p)->e[((GS3U*)q)->b.b2][t].c0, D_0035f638->b12, &uv);
            q = base;
            p = q + 20808;
            q += 20832;
            YI__SPRITE__SetDirextUV(q, uv.u, uv.v);
            func_0028dcc0(p, s3);
        }
        D_0035f638->b10 = 0;
    }
}
}  // namespace n002b3050

// 002b31c0 (was src/anon/batch_w3693.c)
namespace n002b31c0 {
/* the $7 pin puts "move a3,v0" before the jal and "addiu a1" into its delay slot, as the original does */
// 001921d8: moved to src/yasui/libys/message.cpp

/* ---- Tz__JmPuzzle__DrawMess ---- */


u8 *func_002766d0(void) asm("func_002766d0");
s32 func_0028b040(s32) asm("func_0028b040");
extern s32 D_0035f200 asm("D_0035f200");
extern u8 *D_0035f224 asm("D_0035f224");
extern u8 *D_0035f638 asm("D_0035f638");
void func_0014b950(u8 *, s16, s16, u16, u16) asm("func_0014b950");
void func_0014b9a8(u8 *) asm("func_0014b9a8");
s32 func_0023aa58(u8 *) asm("func_0023aa58");
s32 func_0023aa78(u8 *) asm("func_0023aa78");
u8 *func_001aae68(s32) asm("func_001aae68");
s32 func_00192048(s32) asm("func_00192048");
void YS__MESSAGEDRAW__MESSAGEDRAW(void *, s32, s32, s32, s32) asm("YS__MESSAGEDRAW__MESSAGEDRAW");
void YS__MESSAGEDRAW__set_line_space(void *, s32) asm("YS__MESSAGEDRAW__set_line_space");
void YS__MESSAGEDRAW__draw(void *, s32, s32, s32) asm("YS__MESSAGEDRAW__draw");
/*TARGET 002b31c0*/
void Tz__JmPuzzle__DrawMess(s32 a0, s32 a1, s32 a2) asm("Tz__JmPuzzle__DrawMess");
void Tz__JmPuzzle__DrawMess(s32 a0, s32 a1, s32 a2)
{
  u8 buf[96];
  s32 h = 15;
  u8 *p = func_002766d0() + 24;
  s32 w = func_0028b040(D_0035f200);
  u16 x2 = 512 - a0;
  s32 *new_var;
  s32 n;
  s32 m;
  s32 y;
  u8 *q;
  func_0014b950(D_0035f224 + 32, a0, a1, x2, (*((s16 *) (D_0035f638 + 40))) * 9);
  func_0014b9a8(D_0035f224 + 32);
  n = func_0023aa58(p);
  m = func_0023aa78(p);
  if (n)
  {
    h = n;
  }
  w = w * m;
  y = m;
  a1 -= w;
  q = func_001aae68(3);
  /* $14 (t6) pin: the original loads q+20 into t6 */
  { register s32 t asm("$14") = *(s32*)(q + 20); y = (y - h) - t; }
  y = (y < 0) ? 0 : y;
  YS__MESSAGEDRAW__MESSAGEDRAW(buf, 3, func_00192048(20298), h, 0);
  new_var = &a1;
  YS__MESSAGEDRAW__set_line_space(buf, y);
  YS__MESSAGEDRAW__draw(buf, a0, *new_var, a2);
  func_0014b9a8(D_0035f224);
}
}  // namespace n002b31c0

// 002b3318 (was src/anon/batch_w96.cpp)
namespace n002b3318 {
u8* func_002a9d68(void) asm("func_002a9d68");
u32* Tz__JmPuzzle__GetImageInfo(s32) asm("Tz__JmPuzzle__GetImageInfo");
// list_entry_by_index_checked
s32 func_002b3ac8(u32) asm("func_002b3ac8");
void func_002b2f28(u32) asm("func_002b2f28");
union EU_w96 { u32 u; u16 h; };
static inline __attribute__((always_inline)) void setbit_w96(u16* bits, u32 n) { u16* p = &bits[n >> 4]; *p |= 1 << (n & 15); }
/*TARGET 002b3318*/
// 0x002acda8: definition moved into src/anon/unit_002a99c8.cpp

s32 func_002b3318(void) asm("func_002b3318");
// 0x002acda8: definition moved into src/anon/unit_002a99c8.cpp

s32 func_002b3318(void) {
    u8* g = func_002a9d68();
    s32 ok = 1;
    u32* e = Tz__JmPuzzle__GetImageInfo(-1);  // list_entry_by_index_checked
    u8 k;
    s32 n, i;
    if (*e & 0x4000000) return 0;
    k = ((u8*)e)[2];
    n = func_002b3ac8((*e >> 27) & 1);
    for (i = 0; i < n; i++) {
        s8* slot = (s8*)(g + k * 192 + 480 + i * 4);
        if (slot[8] != i || slot[9] != 0) {
            ok = 0;
            break;
        }
    }
    if (!ok) return 0;
    setbit_w96((u16*)(g + 484), k);
    ((EU_w96*)e)->u |= 0x4000000;
    func_002b2f28(0);
    return 1;
}
}  // namespace n002b3318

// 002b3420 (was src/anon/batch_w3.cpp)
namespace n002b3420 {
// 0x0029e050: definition moved into src/anon/unit_0029d008.cpp

u8* Tz__JmPuzzle__GetImageInfo() asm("Tz__JmPuzzle__GetImageInfo");
// list_entry_by_index_checked
void func_002ac678(u8) asm("func_002ac678");
/*TARGET 002b3420*/
void func_002b3420() asm("func_002b3420");
void func_002b3420() { func_002ac678(Tz__JmPuzzle__GetImageInfo()[2]); }
}  // namespace n002b3420

