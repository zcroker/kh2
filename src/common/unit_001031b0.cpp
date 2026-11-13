#include "types.h"

// Menu mode (0x1031b0-0x103f68): set-up and per-frame step of the menu (camp / pause) mode, its
// allocators, the pending map id and warp location, the menu hooks and the static initialiser of
// the menu mode object (0x32b9e8). All globals (0x32b9e8-0x32ba64) are reached as data.
// The set-up hook 0x103100 (before the task manager constructor) stays a separate function.

struct TASK;

u32 func_00102508__b0(u32, u32, u32, u32) asm("func_00102508");
extern u8 D_0039ea50__b0 asm("D_0039ea50");
#define func_00102508 func_00102508__b0
#define D_0039ea50 D_0039ea50__b0
// 0x1031b0: MENU::CreateTaskManager().
u32 func_001031b0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN4MENU17CreateTaskManagerEv");
u32 func_001031b0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00102508((u32)&D_0039ea50, 0x00008000u, a2, a3);
}
#undef func_00102508
#undef D_0039ea50

extern "C" {
extern s32 D_003a6a50__b1 asm("D_003a6a50");
extern u8 D_0032ba30__b1 asm("D_0032ba30");
extern u8 D_0032ba28__b1 asm("D_0032ba28");
extern s32 D_0032b984__b1 asm("D_0032b984");
extern s32 D_0032ba20__b1 asm("D_0032ba20");
extern u8 D_0032ba1c__b1 asm("D_0032ba1c");
extern s32 D_0032ba64__b1 asm("D_0032ba64");
void func_00103a40__b1(void) asm("func_00103a40");
s32 func_001033d8__b1(s32) asm("func_001033d8");
void func_002530f0__b1(s32) asm("func_002530f0");
void func_00242fc8__b1(s32) asm("func_00242fc8");
void func_00103748__b1(void) asm("func_00103748");
s32 func_00103c90__b1(void) asm("func_00103c90");
void func_00103ca0__b1(void) asm("func_00103ca0");
void func_00253180__b1(s32, s32) asm("func_00253180");
void func_00243020__b1(s32) asm("func_00243020");
void func_0014c9f0__b1(s32) asm("func_0014c9f0");
void func_00167ee0__b1(void) asm("func_00167ee0");
void func_001384a0__b1(s32) asm("func_001384a0");
void func_00104108__b1(void) asm("func_00104108");
#define D_003a6a50 D_003a6a50__b1
#define D_0032ba30 D_0032ba30__b1
#define D_0032ba28 D_0032ba28__b1
#define D_0032b984 D_0032b984__b1
#define D_0032ba20 D_0032ba20__b1
#define D_0032ba1c D_0032ba1c__b1
#define D_0032ba64 D_0032ba64__b1
#define func_00103a40 func_00103a40__b1
#define func_001033d8 func_001033d8__b1
#define func_002530f0 func_002530f0__b1
#define func_00242fc8 func_00242fc8__b1
#define func_00103748 func_00103748__b1
#define func_00103c90 func_00103c90__b1
#define func_00103ca0 func_00103ca0__b1
#define func_00253180 func_00253180__b1
#define func_00243020 func_00243020__b1
#define func_0014c9f0 func_0014c9f0__b1
#define func_00167ee0 func_00167ee0__b1
#define func_001384a0 func_001384a0__b1
#define func_00104108 func_00104108__b1
// 0x1031d0: menu per-frame step: dispatches the pending map/scene id and runs post-frame hooks.
void func_001031d0(void)
{
    s32 cur;
    s32 next;
    s32 flag;
    s32 mode;

    func_00103a40();
    cur = D_003a6a50;
    if ((u32)(cur - 100) >= 800) {
        func_002530f0(func_001033d8(cur));
    } else {
        func_00242fc8(func_001033d8(cur));
    }
    if (D_0032ba30 == 0) {
        func_00103748();
    }
    flag = 0;
    D_0032ba28 = 0;
    if (func_00103c90()) {  // get_hook_ptr
        func_00103ca0();
        flag = 1;
    }
    mode = D_0032b984;
    if (mode != 0 && (mode ^ 2) != 0) {
        next = D_0032ba20;
        if (next != -1) {
            s32 v;
            D_0032ba20 = -1;
            D_003a6a50 = -1;
            v = func_001033d8(next);
            if ((u32)(next - 100) >= 800) {
                func_00253180(v, -999);
            } else {
                func_00243020(v);
            }
            return;
        }
        D_003a6a50 = next;
        func_0014c9f0(1);
        if (flag) return;
        func_00167ee0();
        if (D_0032ba1c == 0) {
            func_001384a0(0);
        }
    } else {
        if (D_0032ba64 != 0) {
            D_003a6a50 = -1;
            func_0014c9f0(1);
            func_00167ee0();
            if (D_0032ba1c == 0) {
                func_001384a0(0);
            }
            func_00104108();
            return;
        }
        D_003a6a50 = -1;
        func_0014c9f0(1);
        func_00167ee0();
        if (D_0032ba1c == 0) {
            func_001384a0(0);
        }
    }
}
}
#undef D_003a6a50
#undef D_0032ba30
#undef D_0032ba28
#undef D_0032b984
#undef D_0032ba20
#undef D_0032ba1c
#undef D_0032ba64
#undef func_00103a40
#undef func_001033d8
#undef func_002530f0
#undef func_00242fc8
#undef func_00103748
#undef func_00103c90
#undef func_00103ca0
#undef func_00253180
#undef func_00243020
#undef func_0014c9f0
#undef func_00167ee0
#undef func_001384a0
#undef func_00104108

void func_001033d8__b2(BD_VALUE*) asm("func_001033d8");
#define func_001033d8 func_001033d8__b2
// 0x103398: Tz::MenuBasic::GetMenuNameId(unsigned int).
void func_00103398(BD_VALUE* bd) asm("_ZN2Tz9MenuBasic13GetMenuNameIdEj");
void func_00103398(BD_VALUE* bd) { func_001033d8(bd); }
#undef func_001033d8


// 0x1033b0: Tz::MenuBase::Reset(): id range 0..99 / 100..899 / 900+.
u32 func_001033b0(s32 a0) asm("_ZN2Tz8MenuBase5ResetEv");
u32 func_001033b0(s32 a0) {
    u32 v0 = 0;
    if (a0 >= 100) {
        v0 = 1;
        if (a0 >= 900) {
            v0 = 2;
        }
    }
    return v0;
}

extern "C" {
struct KeyVal { s16 key; s16 val; };
extern KeyVal D_00369da8__b4[] asm("D_00369da8");
#define D_00369da8 D_00369da8__b4
// 0x1033d8: map id -> menu name id.
s32 lookup_001033d8(void* k) asm("_Z13func_001033d8Pv");
s32 lookup_001033d8(void* k) {
    s32 r = -1;
    for (s32 i = 0; D_00369da8[i].key >= 0; i++)
        if (D_00369da8[i].key == (s32)k) r = D_00369da8[i].val;
    return r;
}
}
#undef D_00369da8

extern "C" {
extern s16 D_00369d98__b5[] asm("D_00369d98");
#define D_00369d98 D_00369d98__b5
// 0x103428: is `id` in the -1-terminated id table?
s32 func_00103428(s32 id) {
    s32 i;
    s32 r = 0;
    for (i = 0; D_00369d98[i] >= 0; i++) {
        if (id == D_00369d98[i]) {
            r = 1;
            break;
        }
    }
    return r;
}
}
#undef D_00369d98

extern "C" {
void func_00103ea0__b6(s32) asm("func_00103ea0");
void func_00103500__b6(s32) asm("func_00103500");
void func_00103c70__b6(void) asm("func_00103c70");
void func_00103e78__b6(void) asm("func_00103e78");
void func_0023ed90__b6(void) asm("func_0023ed90");
u8 func_001384c0__b6(void) asm("func_001384c0");
void func_001031d0__b6(void) asm("func_001031d0");
void func_00103100__b6(void) asm("func_00103100");
struct S32b9e8 { u8 pad[0x20]; void* f20; void* f24; };
extern S32b9e8 D_0032b9e8__b6 asm("D_0032b9e8");
extern u8 D_0032ba28__b6 asm("D_0032ba28");
extern s32 D_0032ba20__b6 asm("D_0032ba20");
extern u8 D_0032ba1c__b6 asm("D_0032ba1c");
#define func_00103ea0 func_00103ea0__b6
#define func_00103500 func_00103500__b6
#define func_00103c70 func_00103c70__b6
#define func_00103e78 func_00103e78__b6
#define func_0023ed90 func_0023ed90__b6
#define func_001384c0 func_001384c0__b6
#define func_001031d0 func_001031d0__b6
#define func_00103100 func_00103100__b6
#define D_0032b9e8 D_0032b9e8__b6
#define D_0032ba28 D_0032ba28__b6
#define D_0032ba20 D_0032ba20__b6
#define D_0032ba1c D_0032ba1c__b6
// 0x103480: menu mode init: installs the set-up and step hooks.
void func_00103480(void) {
    D_0032ba28 = 0;
    func_00103ea0(0);  // set_hook_ptr
    D_0032b9e8.f20 = (void*)func_00103100;
    D_0032b9e8.f24 = (void*)func_001031d0;
    func_00103500(-1);
    func_00103c70();  // clear_hook_ptr
    func_00103e78();
    func_0023ed90();  // set_global_byte1
    D_0032ba20 = -1;
    D_0032ba1c = func_001384c0();  // get_global_347e08
}
}
#undef func_00103ea0
#undef func_00103500
#undef func_00103c70
#undef func_00103e78
#undef func_0023ed90
#undef func_001384c0
#undef func_001031d0
#undef func_00103100
#undef D_0032b9e8
#undef D_0032ba28
#undef D_0032ba20
#undef D_0032ba1c

extern "C" {
s32 func_00103b38__b7(s32) asm("func_00103b38");
extern s32 D_0032ba20__b7 asm("D_0032ba20");
extern s32 D_003a6a50__b7 asm("D_003a6a50");
#define func_00103b38 func_00103b38__b7
#define D_0032ba20 D_0032ba20__b7
#define D_003a6a50 D_003a6a50__b7
// 0x103500: selects the current id; falls back to a saved slot when the id is unknown.
void func_00103500(s32 id) {
    if (func_00103b38(id)) {
        if (D_0032ba20 != id) D_0032ba20 = id;
    } else {
        D_003a6a50 = id;
        D_0032ba20 = -1;
    }
}
}
#undef func_00103b38
#undef D_0032ba20
#undef D_003a6a50


// 0x103550: MENU::getType().
namespace MENU {
u32 getType() {
    u32 b = (0x003au << 16);
    return (u32)(*(u32*)((u32)b + 27216));
}
}  // namespace MENU

u32 func_00103560(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0033u << 16);
    return (u32)(*(u32*)((u32)b + (-17888)));
}

// 0x103570: Tz::LoadDataGetSystem().
u32 func_00103570(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2Tz17LoadDataGetSystemEv");
u32 func_00103570(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0033u << 16);
    return (u32)(*(u32*)((u32)b + (-17900)));
}

// 0x103580: MENU::GetObjAllocator().
u32 func_00103580(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN4MENU15GetObjAllocatorEv");
u32 func_00103580(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0033u << 16);
    return (u32)(*(u32*)((u32)b + (-17896)));
}

extern "C" {
void func_001036d0__b9(void*, u32) asm("func_001036d0");
void* func_00106178__b9(void*, u32) asm("func_00106178");
void* func_00104288__b9(void) asm("func_00104288");
u8* func_00170b30__b9(u32) asm("func_00170b30");
extern void* D_0032ba14__b9 asm("D_0032ba14");
extern void* D_0032ba18__b9 asm("D_0032ba18");
extern s32 D_0032ba24__b9 asm("D_0032ba24");
extern u8 D_0032ba30__b9 asm("D_0032ba30");
extern s32 D_003a6a50__b9 asm("D_003a6a50");
extern u8 D_01f18014__b9[] asm("D_01f18014");
extern u8 D_01f4a014__b9[] asm("D_01f4a014");
#define func_001036d0 func_001036d0__b9
#define func_00106178 func_00106178__b9
#define func_00104288 func_00104288__b9
#define func_00170b30 func_00170b30__b9
#define D_0032ba14 D_0032ba14__b9
#define D_0032ba18 D_0032ba18__b9
#define D_0032ba24 D_0032ba24__b9
#define D_0032ba30 D_0032ba30__b9
#define D_003a6a50 D_003a6a50__b9
#define D_01f18014 D_01f18014__b9
#define D_01f4a014 D_01f4a014__b9
// 0x103590: sets up the menu allocators: the given buffer, or one picked by the menu mode.
void func_00103590(s32 lock, void* buf) {
    if (buf) {
        D_0032ba14 = buf;
        D_0032ba30 = 1;
        return;
    }
    s32 m = D_0032ba24;
    u8* p;
    if ((m == 1 && D_003a6a50 != 6) || m == 6) {
        p = D_01f18014;
        func_001036d0(p, 0xa0000);
    } else if (D_003a6a50 == 6) {
        p = D_01f4a014;
        D_0032ba14 = func_00106178(p, 0x40000);
        D_0032ba18 = func_00106178(p + 0x40000, 0x2e000);
    } else if (m == 2) {
        D_0032ba14 = func_00104288();
        D_0032ba18 = 0;
    } else {
        p = func_00170b30(0xa0000);  // alloc_align128
        D_0032ba14 = func_00106178(p, 0x38000);
        D_0032ba18 = func_00106178(p + 0x38000, 0x68000);
    }
    D_0032ba30 = lock != 0;
}
}
#undef func_001036d0
#undef func_00106178
#undef func_00104288
#undef func_00170b30
#undef D_0032ba14
#undef D_0032ba18
#undef D_0032ba24
#undef D_0032ba30
#undef D_003a6a50
#undef D_01f18014
#undef D_01f4a014

extern "C" {
extern u8 D_01f18014__b10[] asm("D_01f18014");
extern u32 D_0032ba14__b10 asm("D_0032ba14");
extern u32 D_0032ba18__b10 asm("D_0032ba18");
extern u8 D_0032ba30__b10 asm("D_0032ba30");
u32 func_00106178__b10(void *, int) asm("func_00106178");
#define D_01f18014 D_01f18014__b10
#define D_0032ba14 D_0032ba14__b10
#define D_0032ba18 D_0032ba18__b10
#define D_0032ba30 D_0032ba30__b10
#define func_00106178 func_00106178__b10
// 0x1036d0: splits a buffer into the two menu allocators.
void func_001036d0(u8 *base, int size)
{
  u8 *new_var;
  u8 *p;
  int n;
  u8 *new_var2;
  if (!base)
  {
    new_var2 = D_01f18014;
    base = new_var2;
  }
  new_var2 = base;
  p = new_var2;
  n = size - 0x68000;
  new_var = new_var2;
  D_0032ba14 = func_00106178(new_var, n);
  p += n;
  D_0032ba18 = func_00106178(p, 0x68000);
  D_0032ba30 = 1;
}
}
#undef D_01f18014
#undef D_0032ba14
#undef D_0032ba18
#undef D_0032ba30
#undef func_00106178

extern "C" {
void func_00170c00__b11(void*) asm("func_00170c00");
extern u8 D_0032ba30__b11 asm("D_0032ba30");
extern s32 D_0032ba24__b11 asm("D_0032ba24");
extern void* D_0032ba14__b11 asm("D_0032ba14");
extern u32 D_0032ba18__b11 asm("D_0032ba18");
#define func_00170c00 func_00170c00__b11
#define D_0032ba30 D_0032ba30__b11
#define D_0032ba24 D_0032ba24__b11
#define D_0032ba14 D_0032ba14__b11
#define D_0032ba18 D_0032ba18__b11
// 0x103748: MENU::DestoryAllocator(): frees the menu allocator unless locked or the mode is 1, 2 or 6.
void MENU_DestoryAllocator(void) asm("_ZN4MENU16DestoryAllocatorEv");
void MENU_DestoryAllocator(void) {
    if (!D_0032ba30) {
        s32 m = D_0032ba24;
        if (m == 1) goto done;
        if (m == 2) goto done;
        if (m == 6) goto done;
        func_00170c00(D_0032ba14);
    }
done:
    D_0032ba14 = 0;
    D_0032ba18 = 0;
    D_0032ba30 = 0;
}
}
#undef func_00170c00
#undef D_0032ba30
#undef D_0032ba24
#undef D_0032ba14
#undef D_0032ba18

extern "C" {
extern u32 D_0032b91c__b12 asm("D_0032b91c");
extern u8 D_0032ba28__b12 asm("D_0032ba28");
void func_00102788__b12(u32, u32, u32, void*) asm("func_00102788");
void func_001037f8__b12(void) asm("func_001037f8");
#define D_0032b91c D_0032b91c__b12
#define D_0032ba28 D_0032ba28__b12
#define func_00102788 func_00102788__b12
#define func_001037f8 func_001037f8__b12
// 0x1037b8: starts the menu exit task.
void func_001037b8(void) {
    func_00102788(D_0032b91c, 0, 0x50910, (void*)func_001037f8);
    D_0032ba28 = 1;
}
}
#undef D_0032b91c
#undef D_0032ba28
#undef func_00102788
#undef func_001037f8

extern "C" {
void func_00103ea0__b13(s32) asm("func_00103ea0");
void func_0014c9d8__b13(s32) asm("func_0014c9d8");
void func_0014df88__b13(void) asm("func_0014df88");
void func_0014e0d8__b13(void) asm("func_0014e0d8");
void func_0023ed90__b13(void) asm("func_0023ed90");
s32 func_001050c8__b13(void) asm("func_001050c8");
s32 func_00104288__b13(void) asm("func_00104288");
s32 func_00104600__b13(void) asm("func_00104600");
s32 func_00102e90__b13(void) asm("func_00102e90");
void func_0023fb00__b13(s32) asm("func_0023fb00");
void func_00103c70__b13(void) asm("func_00103c70");
void func_00103e78__b13(void) asm("func_00103e78");
void func_00102080__b13(void*) asm("func_00102080");
void func_00167ea8__b13(void) asm("func_00167ea8");
void func_001024a8__b13(void*) asm("func_001024a8");
extern s32 D_0032ba24__b13 asm("D_0032ba24");
extern s32 D_0032b984__b13 asm("D_0032b984");
extern s32 D_0032b9bc__b13 asm("D_0032b9bc");
extern s32 D_0032ba64__b13 asm("D_0032ba64");
extern s32 D_003a6a50__b13 asm("D_003a6a50");
struct St32 { u8 pad[28]; s32 f28; };
extern St32 D_0032b968__b13 asm("D_0032b968");
extern St32 D_0032ba48__b13 asm("D_0032ba48");
extern u8 D_0032b9e8__b13[] asm("D_0032b9e8");
#define func_00103ea0 func_00103ea0__b13
#define func_0014c9d8 func_0014c9d8__b13
#define func_0014df88 func_0014df88__b13
#define func_0014e0d8 func_0014e0d8__b13
#define func_0023ed90 func_0023ed90__b13
#define func_001050c8 func_001050c8__b13
#define func_00104288 func_00104288__b13
#define func_00104600 func_00104600__b13
#define func_00102e90 func_00102e90__b13
#define func_0023fb00 func_0023fb00__b13
#define func_00103c70 func_00103c70__b13
#define func_00103e78 func_00103e78__b13
#define func_00102080 func_00102080__b13
#define func_00167ea8 func_00167ea8__b13
#define func_001024a8 func_001024a8__b13
#define D_0032ba24 D_0032ba24__b13
#define D_0032b984 D_0032b984__b13
#define D_0032b9bc D_0032b9bc__b13
#define D_0032ba64 D_0032ba64__b13
#define D_003a6a50 D_003a6a50__b13
#define D_0032b968 D_0032b968__b13
#define D_0032ba48 D_0032ba48__b13
#define D_0032b9e8 D_0032b9e8__b13
#define IsMode156(m) ((m) == 1 || (m) == 5 || (m) == 6)
static inline bool Is984Two() { return D_0032b984 == 2; }
static inline bool Is9bcTwo() { return D_0032b9bc == 2; }
static inline bool Isa64Two() { return D_0032ba64 == 2; }
// 0x1037f8: the menu exit task: mode-dependent clean-up, then back to the previous mode.
void func_001037f8(void* a0)
{
    s32 skip = 0;
    func_00103ea0(0);  // set_hook_ptr
    if (IsMode156(D_0032ba24) && Is984Two()) skip = 1;
    else if (D_0032ba24 == 4 && Is9bcTwo()) skip = 1;
    else if (D_0032ba24 == 2) skip = Isa64Two();
    if (!skip) {
        s32 r;
        func_0014c9d8(1);
        if (IsMode156(D_0032ba24)) {
            if (D_003a6a50 != 10) { func_0014df88(); func_0014e0d8(); }
            if (D_0032b968.f28) D_0032b968.f28 = 2;
        } else if (D_0032ba24 == 2) {
            func_0014df88(); func_0014e0d8();
            if (D_0032ba48.f28) D_0032ba48.f28 = 2;
        }
        func_0023ed90();  // set_global_byte1
        if (IsMode156(D_0032ba24)) r = func_001050c8();
        else if (D_0032ba24 == 2) r = func_00104288();
        else if (D_0032ba24 == 3) r = func_00104600();
        else r = func_00102e90();
        func_0023fb00(r);
        func_00103c70();  // clear_hook_ptr
        func_00103e78();
    }
    func_00102080(D_0032b9e8);
    func_00167ea8();
    func_001024a8(a0);
}
#undef IsMode156
}
#undef func_00103ea0
#undef func_0014c9d8
#undef func_0014df88
#undef func_0014e0d8
#undef func_0023ed90
#undef func_001050c8
#undef func_00104288
#undef func_00104600
#undef func_00102e90
#undef func_0023fb00
#undef func_00103c70
#undef func_00103e78
#undef func_00102080
#undef func_00167ea8
#undef func_001024a8
#undef D_0032ba24
#undef D_0032b984
#undef D_0032b9bc
#undef D_0032ba64
#undef D_003a6a50
#undef D_0032b968
#undef D_0032ba48
#undef D_0032b9e8

extern "C" {
extern void (*D_0032ba34__b14)(void) asm("D_0032ba34");
extern s32 D_0032ba04__b14 asm("D_0032ba04");
void func_00103ea0__b14(s32) asm("func_00103ea0");
#define D_0032ba34 D_0032ba34__b14
#define D_0032ba04 D_0032ba04__b14
#define func_00103ea0 func_00103ea0__b14
// 0x1039f8: runs the registered hook if any, otherwise sets the state to 3.
void func_001039f8(void) {
    if (D_0032ba34) {
        D_0032ba34();
        func_00103ea0(0);  // set_hook_ptr
        return;
    }
    D_0032ba04 = 3;
}
}
#undef D_0032ba34
#undef D_0032ba04
#undef func_00103ea0

u32 func_00105300__b15(void) asm("func_00105300");
u32 func_00103c90__b15(void) asm("func_00103c90");
void func_0014df98__b15(void) asm("func_0014df98");
void func_0023fb28__b15(void) asm("func_0023fb28");
u8 func_001384c0__b15(void) asm("func_001384c0");
void func_001ddc48__b15(void) asm("func_001ddc48");
void func_001e0328__b15(void) asm("func_001e0328");
void func_00103ca0__b15(void) asm("func_00103ca0");
void func_00167ea8__b15(void) asm("func_00167ea8");
void func_0023d368__b15(void) asm("func_0023d368");
extern u32 D_0032ba24__b15 asm("D_0032ba24");
extern u32 D_003a6a50__b15 asm("D_003a6a50");
extern u8 D_0032ba1c__b15 asm("D_0032ba1c");
extern u32 D_0032b968__b15 asm("D_0032b968");
extern u32 D_0032ba48__b15 asm("D_0032ba48");
#define func_00105300 func_00105300__b15
#define func_00103c90 func_00103c90__b15
#define func_0014df98 func_0014df98__b15
#define func_0023fb28 func_0023fb28__b15
#define func_001384c0 func_001384c0__b15
#define func_001ddc48 func_001ddc48__b15
#define func_001e0328 func_001e0328__b15
#define func_00103ca0 func_00103ca0__b15
#define func_00167ea8 func_00167ea8__b15
#define func_0023d368 func_0023d368__b15
#define D_0032ba24 D_0032ba24__b15
#define D_003a6a50 D_003a6a50__b15
#define D_0032ba1c D_0032ba1c__b15
#define D_0032b968 D_0032b968__b15
#define D_0032ba48 D_0032ba48__b15
// 0x103a40: MENU::finalize().
void func_00103a40(void) asm("_ZN4MENU8finalizeEv");
void func_00103a40(void) {
    u8* s0;

    if (func_00105300() == 0) {
        if (func_00103c90() == 0) {  // get_hook_ptr
            u32 t = D_0032ba24;
            if (t == 1 || t == 5 || t == 6) {
                if (D_003a6a50 != 10) {
                    func_0014df98();  // zero_global_byte
                }
            }
        }
    }

    func_0023fb28();
    D_0032ba1c = func_001384c0();  // get_global_347e08
    func_001ddc48();
    func_001e0328();

    if (func_00103c90() != 0) {  // get_hook_ptr
        func_00103ca0();
        func_00167ea8();
    }

    s0 = (u8*)&D_0032b968;
    if (*(u32*)(s0 + 28) == 0) {
        s0 = (u8*)&D_0032ba48;
        if (*(u32*)(s0 + 28) == 0) {
            return;
        }
    }

    func_0023d368();
    func_00167ea8();
    *(u32*)(s0 + 28) = 1;
}
#undef func_00105300
#undef func_00103c90
#undef func_0014df98
#undef func_0023fb28
#undef func_001384c0
#undef func_001ddc48
#undef func_001e0328
#undef func_00103ca0
#undef func_00167ea8
#undef func_0023d368
#undef D_0032ba24
#undef D_003a6a50
#undef D_0032ba1c
#undef D_0032b968
#undef D_0032ba48

u32 func_00102788__b16(u32, u32, u32, u32) asm("func_00102788");
extern u8 D_00330000__b16 asm("D_00330000");
#define func_00102788 func_00102788__b16
#define D_00330000 D_00330000__b16
// 0x103b38: MENU::isRunning().
u32 func_00103b38(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN4MENU9isRunningEv");
u32 func_00103b38(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0033u << 16);
    return (u32)(*(u8*)((u32)b + (-17880)));
}

// 0x103b48: creates a task on the menu's manager.
u32 func_00103b48(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00102788(((u32)(*(u32*)((u32)((u32)&D_00330000) - 17940u))), a0, a1, a2);
}
#undef func_00102788
#undef D_00330000

extern "C" {
extern void* D_0032b9ec__b17 asm("D_0032b9ec");
u32 func_00102818__b17(void*, u32, u32, u32, u32) asm("func_00102818");
#define D_0032b9ec D_0032b9ec__b17
#define func_00102818 func_00102818__b17
// 0x103b78: creates a coroutine task on the menu's manager.
u32 func_00103b78(u32 a, u32 b, u32 c, u32 d) {
    return func_00102818(D_0032b9ec, a, b, c, d);
}
}
#undef D_0032b9ec
#undef func_00102818

extern u32 D_0032ba24__b18 asm("D_0032ba24");
u32 func_00102c80__b18(void) asm("func_00102c80");
u32 func_00103070__b18(void) asm("func_00103070");
u32 func_00104190__b18(void) asm("func_00104190");
u32 func_001045f0__b18(void) asm("func_001045f0");
void func_00102180__b18(void*) asm("func_00102180");
#define D_0032ba24 D_0032ba24__b18
#define func_00102c80 func_00102c80__b18
#define func_00103070 func_00103070__b18
#define func_00104190 func_00104190__b18
#define func_001045f0 func_001045f0__b18
#define func_00102180 func_00102180__b18
// 0x103bb0: MENU::SetGameMode(int): an explicit mode, or the one of the current game mode object.
void func_00103bb0(s32 a0) asm("_ZN4MENU11SetGameModeEi");
void func_00103bb0(s32 a0) {
    u32 v20 = func_00102c80();
    u32 v19 = func_00103070();
    u32 v18 = func_00104190();
    u32 v17 = func_001045f0();

    u32 out;
    func_00102180((void*)&out);

    if (a0 != -1) {
        D_0032ba24 = (u32)a0;
        return;
    }

    u32 v = out;
    if (v == v20) {
        D_0032ba24 = 1;
        return;
    }
    if (v == v19) {
        D_0032ba24 = 4;
        return;
    }
    if (v == v18) {
        D_0032ba24 = 2;
        return;
    }
    if (v == v17) {
        D_0032ba24 = 3;
        return;
    }
}

// 0x103c60 (not in the layout): the menu's game mode.
u32 func_00103c60(void) {
    return D_0032ba24;
}
#undef D_0032ba24
#undef func_00102c80
#undef func_00103070
#undef func_00104190
#undef func_001045f0
#undef func_00102180

extern u32 D_0032ba2c__b19 asm("D_0032ba2c");
#define D_0032ba2c D_0032ba2c__b19
void func_00103c70(u32 a0, u32 a1, u32 a2, u32 a3) {  // clear_hook_ptr
    u32 b = (0x0033u << 16);
    *(u32*)((u32)b + (-17876)) = (u32)0;
}

// 0x103c80: MENU::SetMapJump(int).
void func_00103c80(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN4MENU10SetMapJumpEi");
void func_00103c80(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x0033u << 16);
    *(u32*)((u32)b + (-17876)) = (u32)a0;
}

u32 func_00103c90(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_hook_ptr
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    return (D_0032ba2c != 0);
}
#undef D_0032ba2c

struct Ids103ca0 { u16 x, y, z; };
struct Loc103ca0 {
    u8 a, b, c, pad;
    Ids103ca0 ids;
    Loc103ca0() { Fill(0xffff); }
    void Fill(s32 v) { a = v; b = v; c = v; ids.x = v; ids.y = v; ids.z = v; }
};
struct Cur103ca0 { u8 type; u8 a, b, c; Ids103ca0 ids; u8 f10; };
extern "C" {
extern s32 D_0032ba2c__b20 asm("D_0032ba2c");
extern s32 D_0032ba24__b20 asm("D_0032ba24");
extern Cur103ca0 D_0032ba38__b20 asm("D_0032ba38");
void func_00103c70__b20(void) asm("func_00103c70");
void func_00103e78__b20(void) asm("func_00103e78");
void func_00149fe0__b20(s32, u32) asm("func_00149fe0");
s32 func_0014aba8__b20(void) asm("func_0014aba8");
void func_0014aa58__b20(s32, s32, s32) asm("func_0014aa58");
void func_0014a138__b20(s32) asm("func_0014a138");
Loc103ca0 func_001cd520__b20(void) asm("func_001cd520");
Loc103ca0 func_00199718__b20(u8, s32) asm("func_00199718");
void func_00104f58__b20(Loc103ca0*, s32, s32, s32, s32) asm("func_00104f58");
#define D_0032ba2c D_0032ba2c__b20
#define D_0032ba24 D_0032ba24__b20
#define D_0032ba38 D_0032ba38__b20
#define func_00103c70 func_00103c70__b20
#define func_00103e78 func_00103e78__b20
#define func_00149fe0 func_00149fe0__b20
#define func_0014aba8 func_0014aba8__b20
#define func_0014aa58 func_0014aa58__b20
#define func_0014a138 func_0014a138__b20
#define func_001cd520 func_001cd520__b20
#define func_00199718 func_00199718__b20
#define func_00104f58 func_00104f58__b20
// 0x103ca0: the menu hook step: per-mode handling, then the warp to the pending location.
void func_00103ca0(void)
{
    s32 mode = D_0032ba2c;
    Loc103ca0 l;
    func_00103c70();
    switch (mode) {
    case 1:
        func_00149fe0(-1, 0x80000000);
        break;
    case 3:
        func_0014aa58(func_0014aba8(), 1, 0);
        func_0014a138(0);
        break;
    case 2:
        if (D_0032ba24 == 1) {
            if (D_0032ba38.type == 0) {
                l = func_001cd520();
                func_00104f58(&l, 1, 0, 1, 0);
            } else {
                if (D_0032ba38.type == D_0032ba24) {
                    l.a = D_0032ba38.a;
                    l.b = D_0032ba38.b;
                    l.c = D_0032ba38.c;
                    l.ids = D_0032ba38.ids;
                } else {
                    l = func_00199718(D_0032ba38.f10, -1);
                    l.c = D_0032ba38.c;
                }
                func_00104f58(&l, 1, 0, 0, 0);
            }
        }
        break;
    }
    func_00103e78();
}

// 0x103e28 (not in the layout): sets a pending warp to a location.
void func_00103e28(s32 a, s32 b, s32 c, s32 x, s32 y, s32 z) {
    D_0032ba38.type = 1;
    D_0032ba38.a = a;
    D_0032ba38.b = b;
    D_0032ba38.c = c;
    D_0032ba38.ids.x = x;
    D_0032ba38.ids.y = y;
    D_0032ba38.ids.z = z;
}

// 0x103e58 (not in the layout): sets a pending warp by place number.
void func_00103e58(s32 f10, s32 c) {
    D_0032ba38.type = 2;
    D_0032ba38.f10 = f10;
    D_0032ba38.c = c;
}
}
#undef D_0032ba2c
#undef D_0032ba24
#undef D_0032ba38
#undef func_00103c70
#undef func_00103e78
#undef func_00149fe0
#undef func_0014aba8
#undef func_0014aa58
#undef func_0014a138
#undef func_001cd520
#undef func_00199718
#undef func_00104f58

u32 func_002fde18__b21(u32, u32, u32, u32) asm("func_002fde18");
extern u8 D_0032ba38__b21 asm("D_0032ba38");
#define func_002fde18 func_002fde18__b21
#define D_0032ba38 D_0032ba38__b21
// 0x103e78: clears the pending warp.
u32 func_00103e78(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002fde18((u32)&D_0032ba38, 0x00000000u, 0x0000000cu, a3);
}
#undef func_002fde18
#undef D_0032ba38

extern u32 D_0032b9e8__b22 asm("D_0032b9e8");
#define D_0032b9e8 D_0032b9e8__b22
void func_00103ea0(u32 a0, u32 a1, u32 a2, u32 a3) {  // set_hook_ptr
    u32 b = (0x0033u << 16);
    *(u32*)((u32)b + (-17868)) = (u32)a0;
}

// 0x103eb0: getMenuMode().
u32 func_00103eb0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z11getMenuModev");
u32 func_00103eb0(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    return (u32)&D_0032b9e8;
}
#undef D_0032b9e8

struct Ctl0 { void* p; u32 f4; u8 f8; u8 pad[11]; u32 f20; u32 f24; u32 f28; u32 f32; u32 f36; u32 f40; };
struct Ctl1 { u16 a; u16 b; u16 c; };
extern Ctl0 D_0032b9e8__b23 asm("D_0032b9e8");
extern u8 D_0032b930__b23[] asm("D_0032b930");
extern Ctl1 D_0032ba3c__b23 asm("D_0032ba3c");
#define D_0032b9e8 D_0032b9e8__b23
#define D_0032b930 D_0032b930__b23
#define D_0032ba3c D_0032ba3c__b23
// 0x103ec0: the static initialiser (menu mode object and the pending warp's ids).
void wtarget_00103ec0(u32, u32, u32, u32) asm("_Z16wtarget_00103ec0jjjj");
void wtarget_00103ec0(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        D_0032b9e8.p = D_0032b930;
        D_0032b9e8.f4 = 0;
        D_0032b9e8.f8 = 77;
        D_0032b9e8.f20 = 2;
        D_0032b9e8.f24 = 0x222e0;
        D_0032b9e8.f28 = 0;
        D_0032b9e8.f32 = 0;
        D_0032b9e8.f36 = 0;
        D_0032b9e8.f40 = 4096;
    }
    if (b == 0xffff && a == 1) {
        D_0032ba3c.a = 0;
        D_0032ba3c.b = 0;
        D_0032ba3c.c = 0;
    }
}
#undef D_0032b9e8
#undef D_0032b930
#undef D_0032ba3c


// 0x103f48: its _GLOBAL__I_ stub.
u32 func_00103ec0_u(u32, u32, u32, u32) asm("_Z16wtarget_00103ec0jjjj");
extern "C" u32 func_00103f48(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00103ec0_u(0x00000001u, 0x0000ffffu, a2, a3);
}

