// Linked unit 0x00247198-0x00247ff0
#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../tozawa/munny.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../tozawa/config.hpp"
#include "../tozawa/sub_menu.hpp"
#include "../tozawa/smenu_he.hpp"
#include "../tozawa/smenu_heco.hpp"

// .rodata words read by other code (retail bytes, in place)
namespace r00371ab4 {
extern const u32 R_00371ab4[1] asm("D_00371ab4") __attribute__((aligned(4))) = { 0x16 };
extern const u32 R_00371ab8[1] asm("D_00371ab8") __attribute__((aligned(4))) = { 0x6425 };
}  // namespace r00371ab4

// 00247198 (was src/anon/batch_w3699_nsa.cpp)
namespace n00247198 {
struct El { u8 pad[408]; };
struct Ek { u8 pad[408]; s32 f408; u8 pad2[24]; };
struct Tx { u8 pad[32]; };
struct Big {
    u8 pad[4360]; Ek c[4]; u8 pad2[7848 - 4360 - 4 * 436];
    El e[4]; El f[4]; El g[4]; El h[4]; Tx t[4]; Tx u[4];
};
struct Inf { u8 kind; u8 pad[3]; u32 n; };
extern Big* D_0035ed40 asm("D_0035ed40");
extern u8 D_00371ca8[] asm("D_00371ca8");
extern u8 D_00371cb0[] asm("D_00371cb0");
extern u8 D_00371cb8[] asm("D_00371cb8");
extern u8 D_00371cc0[] asm("D_00371cc0");
extern s16 D_00371cd0[] asm("D_00371cd0");
extern char D_00371ab8[] asm("D_00371ab8");
extern s32 D_00371ac4 asm("D_00371ac4");
extern s32 D_00371ac8 asm("D_00371ac8");
s32 func_00246968(s32) asm("func_00246968");
s32 func_00246840(void) asm("func_00246840");
Inf* func_001d56c8(u8) asm("func_001d56c8");
void YI__SEQUENCE__SetScaleX(f32, void*) asm("YI__SEQUENCE__SetScaleX");
void* func_00192048(s32) asm("func_00192048");
void func_00192c90(void*, void*) asm("func_00192c90");
s32 func_00192c40(void*, void*) asm("func_00192c40");
void* func_00192cc0(void*, char*, u32) asm("func_00192cc0");
s32 func_00192b30(void*) asm("func_00192b30");
s32 func_002474e0(s32) asm("func_002474e0");
void func_00138c10(void*, s32) asm("func_00138c10");
s32 func_00105c30(void) asm("func_00105c30");
static inline void* fmt247198(void* s, char* f, u32 n) { return func_00192cc0(s, f, n); }
/*TARGET 00247198*/
void Tz__HECO__UpdateScore(void) asm("Tz__HECO__UpdateScore");
void Tz__HECO__UpdateScore(void) {
    s32 i;
    s32 k = 0;
    s16* sp = D_00371cd0;
    for (i = 0; i < 4; i++, sp++) {
        if (func_00246968(i)) {
            Inf* inf = func_001d56c8((func_00246840() ? D_00371cb0 : D_00371ca8)[i]);
            u8* s2;
            u8* e;
            s32 d;
            s32 flag;
            if (inf->kind < 2) {
                YI__SEQUENCE__SetScaleX(0.0f, (u8*)&D_0035ed40->f[k] + 24);
                s2 = (u8*)&D_0035ed40->t[k];
                func_00192c90(func_00192048(0xcb9b), s2);
            } else if (inf->kind == 2) {
                e = (u8*)&D_0035ed40->f[k];
                d = (func_00246840() ? D_00371cc0 : D_00371cb8)[i];
                d--;
                YI__SEQUENCE__SetScaleX((f32)inf->n / (f32)d, e + 24);
                flag = 0;
                Ek* ck = &D_0035ed40->c[k];
                ck->f408 = (s32)func_00192048(0xcc0b);
                s2 = (u8*)&D_0035ed40->u[k];
                if (func_00105c30() == 1 || func_00105c30() == 8) flag = 1;
                if ((u8)flag) {
                    e = (u8*)func_00192b30(fmt247198(s2, D_00371ab8, inf->n));
                    func_00192c90(func_00192048(0xcb9a), s2 + (s32)e);
                } else {
                    func_00192cc0(s2 + func_00192c40(func_00192048(0xcb9a), s2), D_00371ab8, inf->n);
                }
                s2 = (u8*)&D_0035ed40->t[k];
                func_00192c90(func_00192048(0xcb9b), s2);
            } else if (inf->kind == 3) {
                YI__SEQUENCE__SetScaleX(1.0f, (u8*)&D_0035ed40->f[k] + 24);
                s2 = (u8*)&D_0035ed40->t[k];
                func_00192cc0(s2, D_00371ab8, inf->n);
                e = (u8*)&D_0035ed40->h[k];
                func_00138c10(e, *sp);
            }
            El* g = &D_0035ed40->g[k];
            func_00138c10(g, func_002474e0(k) ? D_00371ac4 : D_00371ac8);
            k++;
        }
    }
}
}  // namespace n00247198

// 002474e0 (was src/anon/auto80_199_queue.cpp)
namespace n002474e0 {
u32 func_002469a0(u32 a0) asm("_Z13func_002469a0j");
/*TARGET 002474e0*/
u32 func_002474e0(u32 a0) asm("_Z13func_002474e0j");
u32 func_002474e0(u32 a0) {
    u32 s1 = 0;
    u32 s0 = func_002469a0(a0);
    if (func_00246840() != 0) {
        s0 = *((u8*)((u32)&D_00371cb0 + s0));
    } else {
        s0 = *((u8*)((u32)&D_00371ca8 + s0));
    }

    u8* p = func_001d56c8(s0);
    u32 t = p[0];
    if (t == 3) {
        s1 = 1;
    }
    else if (t == 2) {
        if (s0 == 7) {
            u32 t0 = *(u32*)(p + 4);
            t0 = (u32)(t0 < 10);
            s1 = (u32)(t0 < 1);
        }
    }

    return s1;
}
}  // namespace n002474e0

// 00247580 (was src/anon/batch_w3816.cpp)
namespace n00247580 {
s32 func_002892f8(s32) asm("func_002892f8");
void func_00138c10(u8*, s32) asm("func_00138c10");
s32 func_00192048(u32) asm("func_00192048");
// 0x00271ee8: definition moved into src/anon/unit_00271e08.cpp

extern s32 D_0035ed20 asm("D_0035ed20");
extern u8* D_0035ed40 asm("D_0035ed40");
extern u8 D_00371ab8[] asm("D_00371ab8");
extern u8 D_00371ac0[] asm("D_00371ac0");
extern u8 D_00371cb8[] asm("D_00371cb8");
extern u8 D_00371cc0[] asm("D_00371cc0");
s32 func_002891e8(s32) asm("func_002891e8");
s32 func_002474e0(s32) asm("func_002474e0");
void func_0028dcc0(void*, void*) asm("func_0028dcc0");
void func_002fde18(void*, s32, s32) asm("func_002fde18");
s32 func_00105c30(void) asm("func_00105c30");
s32 func_00192cc0(u8*, u8*, s32) asm("func_00192cc0");
s32 func_00192b30(s32) asm("func_00192b30");
void func_00192c90(s32, u8*) asm("func_00192c90");
s32 func_00192c40(s32, u8*) asm("func_00192c40");
s32 func_0023aa98(void*) asm("func_0023aa98");
s32 func_002469a0(s32) asm("func_002469a0");
s32 func_00246840(void) asm("func_00246840");
void func_00138c68(void*, s32, s32) asm("func_00138c68");
u32 func_0028af88(s32) asm("func_0028af88");
void func_0028af18(s32, u32) asm("func_0028af18");
// true for the Japanese-style layouts (system language 1 or 8)
static inline u8 isjp() { u8 r = 0; if (func_00105c30() == 1 || func_00105c30() == 8) r = 1; return r; }
/*TARGET 00247580*/
// Refreshes the selection rows and the gauge/caption of the selected entry.
void Tz__HECO__UpdateMaker(u8 flag) asm("Tz__HECO__UpdateMaker");
// Refreshes the selection rows and the gauge/caption of the selected entry.
void Tz__HECO__UpdateMaker(u8 flag) {
    s32 cnt;
    s32 k;
    s32 sel = func_002891e8(D_0035ed20);
    cnt = func_002892f8(D_0035ed20);
    u8* e;
    s32 c;
    if (flag) {
        for (s32 i = 0; i < cnt; i++) {
            e = D_0035ed40 + i * 408 + 11112;
            c = func_002474e0(i) ? 31 : 96;
            func_00138c10(e, c);
        }
    }
    u8* cap = D_0035ed40 + 436;
    if (func_002474e0(sel)) {
        e = D_0035ed40 + sel * 408 + 11112;
        if (flag) {
            func_00138c10(cap, 33);
            func_00138c10(e, 32);
            func_0028dcc0(cap, D_0035ed40 + func_002891e8(D_0035ed20) * 408 + 11112);
        }
        u8* buf = D_0035ed40 + 14632;
        c = ((s8*)(sel + (u32)D_0035ed40))[14664];
        if (isjp()) {
            k = func_00192b30(func_00192cc0(buf, D_00371ab8, c + 1));
            func_00192c90(func_00192048(19468), buf + k);
        } else {
            func_00192cc0(buf + func_00192c40(func_00192048(19468), buf), D_00371ac0, c + 1);
        }
        s32 v = func_0023aa98(D_0035ed40 + sel * 408 + 7872);
        k = func_002469a0(sel);
        cnt = (func_00246840() ? D_00371cc0 : D_00371cb8)[k];
        func_00138c68(e, (s32)((f32)v / (f32)(cnt - 1) * (f32)c), 0);
    } else {
        func_00138c10(cap, 96);
        func_002fde18(D_0035ed40 + 14632, 0, 32);
    }
    u32 f = func_0028af88(D_0035ed20);
    if (func_002474e0(sel)) f |= 0xc0000;
    else f &= 0xfff3ffff;
    func_0028af18(D_0035ed20, f);
}
}  // namespace n00247580

// 00247870 (was src/anon/batch_w111.cpp)
namespace n00247870 {
struct Pad24 { u8 pad[8]; u64 trig; };
struct Info24 { u8 kind; u8 pad[3]; s32 count; };
struct Sel24 { u8 pad[14664]; s8 cur; };
struct Sub24 { u8 pad[8]; s8 cur; };
extern void* D_0035ed20 asm("D_0035ed20");
extern u8* D_0035ed40 asm("D_0035ed40");
extern u8 D_00371ca8[] asm("D_00371ca8");
extern u8 D_00371cb0[] asm("D_00371cb0");
extern u8 D_00371cb8[] asm("D_00371cb8");
extern u8 D_00371cc0[] asm("D_00371cc0");
Pad24* func_00167f18(s32) asm("func_00167f18");
s32 func_002891e8(void*) asm("func_002891e8");
s32 func_002474e0(s32) asm("func_002474e0");
s32 func_002469a0(s32) asm("func_002469a0");
s32 func_00246840(void) asm("func_00246840");
Info24* func_001d56c8(u32) asm("func_001d56c8");
/*TARGET 00247870*/
// Steps the current selection up/down (wrapping on a fresh press); returns whether it changed.
bool Tz__HECO__MoveMaker(u8 down) asm("Tz__HECO__MoveMaker");
// Steps the current selection up/down (wrapping on a fresh press); returns whether it changed.
bool Tz__HECO__MoveMaker(u8 down)
{
    Pad24* pad = func_00167f18(0);
    s32 h = func_002891e8(D_0035ed20);
    if (!func_002474e0(h)) return 0;
    s32 i = func_002469a0(h);
    u32 id = (func_00246840() ? D_00371cb0 : D_00371ca8)[i];
    Info24* info = func_001d56c8(id);
    s32 max = (func_00246840() ? D_00371cc0 : D_00371cb8)[i];
    s32 step = 1;
    if (info->kind == 2 && id == 7) {
        max = info->count;
        max /= 10;
        max *= 10;
        max++;
        step = 10;
    }
    s32 cur = ((Sel24*)(h + (u32)D_0035ed40))->cur;
    if (down) {
        if (cur <= 0) {
            if (pad->trig & 0x40) cur = max - 1;
        } else {
            cur -= step;
            if (cur < 0) cur = 0;
        }
    } else {
        if (cur + 1 >= max) {
            if (pad->trig & 0x80) cur = 0;
        } else {
            cur += step;
            cur = cur < max ? cur : max - 1;
        }
    }
    Sub24* s = (Sub24*)(h + (u32)D_0035ed40 + 14656);
    s32 old = s->cur;
    s->cur = cur;
    return old != cur;
}
}  // namespace n00247870

// 00247a20 (was src/anon/batch_w110.cpp)
namespace n00247a20 {
s32 func_00139d78(u8*) asm("func_00139d78");
void func_0028d8c0(u8*, s32, u32, u32, u32, s32, s32, s32) asm("func_0028d8c0");
extern s8 D_0035ed44 asm("D_0035ed44");
extern u8* D_0035ed34 asm("D_0035ed34");
extern void* D_0035ed20 asm("D_0035ed20");
extern u32 D_0035ed28 asm("D_0035ed28");
extern s32 D_0035f3d4 asm("D_0035f3d4");
s32 func_0028afa8(void*) asm("func_0028afa8");
u8* func_002891b8(void*, s32) asm("func_002891b8");
s32 func_002469a0(s32) asm("func_002469a0");
void func_0028dcc0(u8*, u8*) asm("func_0028dcc0");
void func_00139648(u8*) asm("func_00139648");
s32 func_0023aa18(u8*) asm("func_0023aa18");
s32 func_0023aa38(u8*) asm("func_0023aa38");
void func_00138c68(u8*, s32, s32) asm("func_00138c68");
void func_00247c20(void) asm("func_00247c20");
/*TARGET 00247a20*/
// Re-creates the enabled entry widgets of the list (bit per entry in D_0035ed44).
void Tz__HECO__CreateNewMark(void) asm("Tz__HECO__CreateNewMark");
// Re-creates the enabled entry widgets of the list (bit per entry in D_0035ed44).
void Tz__HECO__CreateNewMark(void) {
    if (!D_0035ed44) return;
    if (func_00139d78(D_0035ed34)) return;
    s32 id = D_0035f3d4 + 1;
    s32 n = func_0028afa8(D_0035ed20);
    for (s32 i = 0; i < n; i++) {
        u8* nd = func_002891b8(D_0035ed20, i);
        u8* sub = nd + 24;
        s32 m = D_0035ed44;
        u8 on = (m >> func_002469a0(i)) & 1;
        if (on) {
            func_0028d8c0(D_0035ed34 + i * 408, id, 0, 0, D_0035ed28, 83, -1, 0);
            func_0028dcc0(D_0035ed34 + i * 408, nd);
            func_00139648(D_0035ed34 + i * 408);
            s32 x = func_0023aa18(sub);
            s32 y = func_0023aa38(sub);
            func_00138c68(D_0035ed34 + i * 408, x, y);
        }
    }
    func_00247c20();
}
}  // namespace n00247a20

// 00247bb0 (was src/anon/batch_w42.cpp)
namespace n00247bb0 {
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
// 00242418: moved to src/tozawa/crc.cpp (linked unit)

// 00247bb0: update the four active entries
extern u8* D_0035ed34 asm("D_0035ed34");
/*TARGET 00247bb0*/
void func_00247bb0(void) asm("func_00247bb0");
void func_00247bb0(void)
{
    for (s32 i = 0; i < 4; i++) {
        if (u_call4_00139d78(D_0035ed34 + i * 408)) {
            u8* o = (u8*)(i * 408 + (u32)D_0035ed34);
            ((void (*)(void*))(*(void***)o)[5])(o);
        }
    }
}
}  // namespace n00247bb0

// 00247c20 (was src/anon/batch_w87.cpp)
namespace n00247c20 {
// ---- 0x154c10 ----
void func_00138c10(void*, s32) asm("func_00138c10");
// ---- 0x247c20 ----
extern void* D_0035ed20 asm("D_0035ed20");
extern s8 D_0035ed44 asm("D_0035ed44");
struct E408 { u8 pad[388]; s32 st; u8 pad2[16]; };
extern E408* D_0035ed34 asm("D_0035ed34");
s32 func_002891e8(void*) asm("func_002891e8");
s32 func_002469a0(s32) asm("func_002469a0");
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_00246840(void) asm("func_00246840");
void func_00243230(s32, s32) asm("func_00243230");
/*TARGET 00247c20*/
void func_00247c20(void) asm("func_00247c20");
void func_00247c20(void) {
    s32 a = func_002891e8(D_0035ed20);
    s32 b = func_002469a0(a);
    bool off = !((D_0035ed44 >> b) & 1);
    if (off) return;
    if (func_00139d78(&D_0035ed34[a])) {
        E408* e = &D_0035ed34[a];
        if (e->st != 82) func_00138c10(e, 82);
    }
    func_00243230(4, func_00246840() ? b + 4 : b);
}
}  // namespace n00247c20

// 00247cf0 (was src/anon/batch_w1947_nsa.cpp)
namespace n00247cf0 {
struct AllocVt7cf0 { void* (*alloc)(void* self, u32 size, void* ra); };
struct AllocObj7cf0 { union { AllocVt7cf0* vt; u8 c; }; };
struct Holder7cf0 { u8 pad[20]; union { AllocObj7cf0* al; u8 c; }; };
struct Ret7cf0 { u8 pad[4]; s32 f4; };
extern AllocObj7cf0* D_0032ba14 asm("D_0032ba14");
extern Holder7cf0* D_00347f80 asm("D_00347f80");
extern s32 D_0035ed4c asm("D_0035ed4c");
extern s32 D_0035ed50 asm("D_0035ed50");
extern s32 D_0035ed54 asm("D_0035ed54");
extern s32 D_0035ed58 asm("D_0035ed58");
extern s32 D_0035ed5c asm("D_0035ed5c");
extern void* D_0035ed60 asm("D_0035ed60");
extern u8 D_00347e60[] asm("D_00347e60");
void func_00239700(void*) asm("func_00239700");
struct Elem7cf0 {
    void* vt; u8 pad4[8]; s32 f12; u8 pad16[8]; u8 sub[408 - 24];
    static void* operator new[](unsigned int sz, AllocObj7cf0* a) { return a->vt->alloc(a, sz, 0); }
    Elem7cf0() { f12 = 0; vt = D_00347e60; func_00239700(sub); }
    ~Elem7cf0();
};
extern Elem7cf0* D_0035ed64 asm("D_0035ed64");
extern u8 D_0035ed68 asm("D_0035ed68");
extern u8 D_0035ed69 asm("D_0035ed69");
void func_00287b18(s32, s32) asm("func_00287b18");
s32 func_00288be8(s32) asm("func_00288be8");
void func_002889f0(s32, s32, s32) asm("func_002889f0");
void func_00288f48(s32, s32, s32, s32, s32) asm("func_00288f48");
void func_002b3df8(void*) asm("func_002b3df8");
void func_0028d068(s32, s32) asm("func_0028d068");
Ret7cf0* func_00103eb0(void) asm("func_00103eb0");
void func_00247ff0(void) asm("func_00247ff0");
void TASK_MANAGER__create_thread(s32, s32, s32, void (*)(void), s32) asm("TASK_MANAGER__create_thread");
/*TARGET 00247cf0*/
void Tz__MUMI__Init(void) asm("Tz__MUMI__Init");
void Tz__MUMI__Init(void) {
    s32 h;
    void* p;
    func_00287b18(2, 3);
    h = func_00288be8(56);
    func_002889f0(h, 3, 1);
    D_0035ed4c = h;
    h = func_00288be8(56);
    func_002889f0(h, 2, 0);
    D_0035ed50 = h;
    func_00288f48(h, 64, 128, 0, 0);
    D_0035ed54 = 0;
    D_0035ed58 = 0;
    D_0035ed5c = 0;
    p = D_0032ba14->vt->alloc(D_0032ba14, 12, __builtin_return_address(0));
    func_002b3df8(p);
    D_0035ed60 = p;
    D_0035ed68 = 0;
    D_0035ed64 = new (D_00347f80->al) Elem7cf0[3];
    D_0035ed69 = 0;
    func_0028d068(30026, -1);
    TASK_MANAGER__create_thread(func_00103eb0()->f4, 0, 2000, func_00247ff0, 4096);
}
}  // namespace n00247cf0

// 00247e80 (was src/anon/batch_wcx2.cpp)
namespace n00247e80 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
// --------------------
// Menu teardown: free the windows, delete the helper objects and the item panel array.
struct VObj00247e80 { struct { void* f0; void* f4; void* f8; void (*dtor)(VObj00247e80*); void (*del)(VObj00247e80*); }* vt; };
struct Panel00247e80 { struct { void* f0; void* f4; void* f8; void (*dtor)(Panel00247e80*); }* vt; u8 pad[404]; };
struct Alloc00247e80 { struct { void* f0; void (*free)(Alloc00247e80*, void*); }* vt; };
struct Heap00247e80 { u8 pad[20]; Alloc00247e80* a; };
extern void* D_0035ed4c_x15274 asm("D_0035ed4c");
extern void* D_0035ed50 asm("D_0035ed50");
extern VObj00247e80* D_0035ed54_x15276 asm("D_0035ed54");
extern VObj00247e80* D_0035ed58 asm("D_0035ed58");
extern VObj00247e80* D_0035ed5c asm("D_0035ed5c");
extern void* D_0035ed60 asm("D_0035ed60");
extern Panel00247e80* D_0035ed64_x15280 asm("D_0035ed64");
extern Alloc00247e80* D_0032ba14_x15281 asm("D_0032ba14");
extern Heap00247e80* D_00347f80_x15282 asm("D_00347f80");
void func_00288b00(void* w) asm("func_00288b00");
void func_00288c20(void* w) asm("func_00288c20");
void func_002b3fb0(void* o) asm("func_002b3fb0");
/*TARGET 00247e80*/
void func_00247e80(void) asm("func_00247e80");
void func_00247e80(void)
{
    void* w;
    if ((w = D_0035ed4c_x15274) != 0) { func_00288b00(w); func_00288c20(w); D_0035ed4c_x15274 = 0; }
    if ((w = D_0035ed50) != 0) { func_00288b00(w); func_00288c20(w); D_0035ed50 = 0; }
    if (D_0035ed54_x15276) { D_0035ed54_x15276->vt->del(D_0035ed54_x15276); D_0035ed54_x15276 = 0; }
    if (D_0035ed58) { D_0035ed58->vt->del(D_0035ed58); D_0035ed58 = 0; }
    if (D_0035ed5c) { D_0035ed5c->vt->del(D_0035ed5c); D_0035ed5c = 0; }
    if ((w = D_0035ed60) != 0) { func_002b3fb0(w); D_0032ba14_x15281->vt->free(D_0032ba14_x15281, w); D_0035ed60 = 0; }
    if (D_0035ed64_x15280) {
        Panel00247e80* e = D_0035ed64_x15280 + ((s32*)D_0035ed64_x15280)[-1];
        Panel00247e80* q;
        for (;;) {
            q = D_0035ed64_x15280;
            if (q == e) break;
            e--;
            e->vt->dtor(e);
        }
        D_00347f80_x15282->a->vt->free(D_00347f80_x15282->a, (s32*)q - 1);
        D_0035ed64_x15280 = 0;
    }
}
}  // namespace n00247e80

