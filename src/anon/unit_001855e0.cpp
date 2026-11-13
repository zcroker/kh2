#include "../common/types.h"

// 0x1855e0-0x185d10: YS::OBJ, between src/anon/unit_00183088.cpp and src/anon/unit_00185d10.cpp: OBJ vtable
// entries (incl. the never-written 0x1855e0, 0x185658, 0x185688 and 0x185cb8) and helpers. Each function
// keeps the declarations of the source it was matched in (namespace rN); every symbol is bound by asm label.

// 001855e0 .. 00185688 (never written before; OBJ vtable entries)
namespace r_gap {
s32 func_001c0cd8(u8*) asm("func_001c0cd8");
void func_001c0e60(u8*) asm("func_001c0e60");
void func_0017fd60(u8*, u8*) asm("func_0017fd60");
void func_0016b668(u8*) asm("func_0016b668");
void func_0017ebf0(u8*) asm("func_0017ebf0");
void func_001984b8(u8*) asm("func_001984b8");
u32 motion_is_no_motion(u8*) asm("_ZN2YS6MOTION12is_no_motionEv");
void func_001940b8(u8*, s32, s32, s32, f32, f32) asm("func_001940b8");
void func_001775f8(u8*) asm("func_001775f8");
s32 func_0019c5d0(u8*) asm("func_0019c5d0");
void func_00185770(u8*) asm("func_00185770");
void func_0016a9a0(u8*) asm("func_0016a9a0");
void func_00185988(u8*) asm("func_00185988");
struct Flags72 { u16 lo : 7; u16 b7 : 1; u16 hi : 8; };
static inline u8 B7(u8* p) { return ((Flags72*)p)->b7; }

void func_001855e0(u8* o) asm("func_001855e0");
void func_001855e0(u8* o) {
    u8* m = o + 320;
    if (*(u32*)m && func_001c0cd8(o)) {
        func_001c0e60(o);
        func_0017fd60(*(u8**)(o + 2548) + 320, m);
    }
    ((u32*)(*(u8**)(o + 2548) + 2808))[*(s32*)(o + 2556)] = 0;
    func_0016b668(o);
}

void func_00185658(u8* o) asm("func_00185658");
void func_00185658(u8* o) {
    func_0017ebf0(o + 320);
    func_001984b8(o);
}

void func_00185688(u8* o) asm("func_00185688");
void func_00185688(u8* o) {
    if (motion_is_no_motion(o + 320)) {
        func_001940b8(o, 255, 255, 255, 1.0f, 0.0f);
        ((void (*)(u8*))(*(void***)o)[17])(o);
        if (B7(*(u8**)(o + 8) + 72)) func_001775f8(*(u8**)(o + 2548));
    } else if (func_001c0cd8(o)) {
        s32 t = *(s32*)(*(u8**)(o + 1392) + 348);
        if (t == 0 || t == 3) {
            if (func_0019c5d0(o)) func_00185770(o);
        }
    } else {
        func_0016a9a0(o);
    }
    func_00185988(o);
}
}  // namespace r_gap

// 00185770 (src/anon/batch_w99.cpp)
namespace r0 {
void func_0016ac38(u8*, s32, s32, s32, s32) asm("func_0016ac38");
struct Info1857 { s32 id; u8 pad[68]; u16 bits; };
struct Obj1857;
struct VT1857 { u8 pad[72]; void (*f72)(Obj1857*); };
struct Obj1857 { VT1857* vt; u32 pad; Info1857* info; u8 pad2[256]; u32 flags; u8 pad3[2276]; u32 w2548; };
void func_0016ac38_185770(Obj1857*, s32, s32, s32, s32) asm("func_0016ac38");
void func_001940b8(Obj1857*, s32, s32, s32, f32, f32) asm("func_001940b8");  // obj_set_bytes_and_lerp
s32 func_0019c650(u32) asm("func_0019c650");
void func_00177638(u32) asm("func_00177638");
static inline bool Flag1857(Obj1857* o) { return (o->info->bits >> 7) & 1; }

void func_00185770(Obj1857* o)
{
    func_0016ac38_185770(o, 0, 1, 0, 0);
    if (o->info->id == 114) {
        func_001940b8(o, 255, 255, 255, 1.0f, 0.0f);  // obj_set_bytes_and_lerp
    } else {
        func_001940b8(o, 255, 255, 255, 0.0f, 0.0f);  // obj_set_bytes_and_lerp
        func_001940b8(o, 255, 255, 255, 1.0f, 16.0f);  // obj_set_bytes_and_lerp
    }
    if (func_0019c650(o->w2548)) {
        o->flags &= ~0x100;
        o->flags &= ~0x400;
    }
    else o->vt->f72(o);
    if (Flag1857(o)) func_00177638(o->w2548);
}
}  // namespace r0

// 00185880 (src/anon/tiny.cpp)
namespace r1 {

void func_00185880(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x01c6u << 16);
    *(u32*)((u32)b + (2184)) = (u32)a0;
}
}  // namespace r1

// 00185890 (src/anon/batch_w58.cpp)
namespace r2 {
extern u32* D_01c60888 asm("D_01c60888");
u8* func_001a80c8(u32) asm("func_001a80c8");  // table24_find_by_id

u32 func_00185890(s32 a, u32 b) {
    if (a == 0 || b == 0 || D_01c60888[a] == 0) return 0;
    u8* v = func_001a80c8(b);  // table24_find_by_id
    u32* t = D_01c60888;
    u32* q = &t[t[a]];
    return q[*(u16*)(v + 4)];
}
}  // namespace r2

// 00185910 (src/anon/tiny.cpp)
namespace r3 {

void func_00185910(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x01c6u << 16);
    *(u32*)((u32)b + (2188)) = (u32)a0;
}
}  // namespace r3

extern "C" const char D_0036c8f0[16] = "obj/%s.mset";

// 00185920 (src/anon/batch_w47.cpp)
namespace r4 {
extern u8* D_01c6088c asm("D_01c6088c");
extern char D_01c60890[] asm("D_01c60890");
extern char D_0036c8f0[] asm("D_0036c8f0");
void func_002fee78(char*, const char*, ...) asm("func_002fee78");

char* func_00185920(s32 i, s32 j, char* buf) {
    u8* row = D_01c6088c + i * 64;
    char* s = (char*)(j * 32 + (u32)row);
    if (!*s) return 0;
    if (!buf) buf = D_01c60890;
    func_002fee78(buf, D_0036c8f0, s);
    return buf;
}
}  // namespace r4

// 00185988 (src/anon/batch_wcx.cpp)
namespace r5 {
typedef void (*VFn)(void*);
#define VDEL(o) if (o) { (*(VFn*)(*(u8**)o + 16))(o); o = 0; }
u32 func_0016ac38(u8*, s32, s32, s32, s32) asm("func_0016ac38");
typedef void (*Fn84)(u8*, s32, s32);
typedef void (*FreeFn)(u8*, u8*);
s32 func_0019c5d0(u8*) asm("func_0019c5d0");
s32 func_001dc9e0(u32) asm("func_001dc9e0");
void func_001dc818(u32) asm("func_001dc818");

void func_00185988(u8* p)
{
    u32 h = *(u32*)(p + 2552);
    if (!h) {
        if (func_0019c5d0(p)) return;
        if (*(u32*)(p + 352) & 0x800) *(u32*)(p + 2552) = func_0016ac38(p, 10, 1, 0, 0);
        return;
    }
    if (func_001dc9e0(h)) {
        if (!func_0019c5d0(p) && (*(u32*)(p + 352) & 0x800)) return;
        func_001dc818(*(u32*)(p + 2552));
    }
    *(u32*)(p + 2552) = 0;
}
}  // namespace r5

// 00185a28 (src/anon/batch_w16.cpp)
namespace r6 {
typedef void (*VFn)(void*);
typedef void (*VFn1)(void*, void*);
void func_0016a2e0(void*) asm("func_0016a2e0");

void func_00185a28(void* p) {
    (*(VFn*)(*(u8**)p + 68))(p);
    (*(VFn*)(*(u8**)p + 40))(p);
    func_0016a2e0(p);
}
}  // namespace r6

// 00185a68 (src/anon/batch_w17.cpp)
namespace r7 {
typedef void (*VFn4)(void*, u32, u32, void*);

void func_00185a68(u8* p, u32 a, u32 b) {
    void* o = *(void**)(p + 2548);
    (*(VFn4*)((*(u8**)o) + 80))(o, a, b, p);
}
}  // namespace r7

// 00185a98 (src/anon/batch_w4.cpp)
namespace r8 {

// Virtual call: (*(p+0x9f4))->vfunc[19]().
void func_00185a98(u8* p) {
    void** o = *(void***)(p + 2548);
    ((void (*)(void*))((void**)*o)[19])(o);
}
}  // namespace r8

// 00185ac0 (src/anon/tiny_auto80_queue.cpp)
namespace r9 {
typedef u32  (*Fn_002cf1b8)(u32, u32);
extern "C" u32 func_001c0cd8(...) asm("func_001c0cd8");

u32 func_00185ac0(u32 a0) {
    s32 s0 = (u32)0u;
    if (*(u32*)((u32)a0 + (s32)(320)) == 0u) goto L1;
    if (func_001c0cd8() == 0u) goto L0;
L1:
    s0 = 1u;
L0:
    return (u32)s0;
}
}  // namespace r9

// 00185b00 (src/anon/batch_w36.cpp)
namespace r10 {
typedef void (*VFn)(void*);
u32 wtarget_00142208(u32, u32, u32, u32) asm("_Z16wtarget_00142208jjjj");
void ctarget_00185b00(u32, u32, u32, u32) asm("_Z16ctarget_00185b00jjjj");
u32 ctarget_0018bbf8(u32, u32, u32, u32) asm("_Z16ctarget_0018bbf8jjjj");
extern s8 D_00457458 asm("D_00457458");
extern u8 D_00457460[] asm("D_00457460");
void func_002fd188(void*) asm("func_002fd188");  // pool_alloc_block
void func_00142c88(void) asm("func_00142c88");
void func_00141988(u8*, u32, u8*) asm("func_00141988");  // collect_entry_ptrs_by_halves
void func_001d7cd0(u8*) asm("func_001d7cd0");
extern u8 D_0034ed78[] asm("D_0034ed78");
s32 func_0016a090(u8*) asm("func_0016a090");  // get_byte74
u32 wtarget_00142208(u32 a0, u32 a1, u32, u32) asm("func_00142208");

void ctarget_00185b00(u32 a0, u32, u32, u32) {
    u8* p = (u8*)a0;
    func_001d7cd0(p);
    *(u32*)(p + 2800) = 0;
    *(void**)p = D_0034ed78;
    *(u32*)(p + 1416) |= 0x10;
    *(f32*)(p + 2804) = 100.0f;
    if (func_0016a090(p) == 2) *(u32*)(p + 2748) |= 0x8000;
}
}  // namespace r10

// 00185b70 (src/anon/batch_w37.cpp)
namespace r11 {
void func_002fd188(void (*)(void)) asm("func_002fd188");  // pool_alloc_block
typedef s32 (*VFn)(void*);
typedef void (*VFn0)(void*);
void func_001d7cd0(void*) asm("func_001d7cd0");
s32 func_0016a090(void*) asm("func_0016a090");  // get_byte74
extern u8 D_0034ed78[] asm("D_0034ed78");

void func_00185b70(u8* p) {
    func_001d7cd0(p);
    *(u32*)(p + 2800) = 0;
    *(void**)p = D_0034ed78;
    *(u32*)(p + 1416) |= 0x10;
    *(f32*)(p + 2804) = 100.0f;
    if (func_0016a090(p) == 2) *(u32*)(p + 2748) |= 0x8000;
}
}  // namespace r11

// 00185be0 (src/anon/auto80_199_queue.cpp)
namespace r12 {
typedef void (*Fn0)(void);
typedef void (*Fn2)(u32, u32);
typedef u32 (*Fn4)(u32, u32, u32, u32);
typedef u32 (*FnAlloc)(u32, u32, u32);
struct VObj {
    u32* vtbl;

};
typedef u32 (*VCall48)(VObj*);
struct Obj {
    u32* vtbl;

};
typedef void (*VCall4)(Obj*, u32);
u32 func_001050d8(...) asm("func_001050d8");
void func_00185b70(u32 a0, u32 a1, u32 a2, float a3) asm("func_00185b70");
typedef void (*FnA0)(u32);
typedef void (*VirtCall)(u32 a0, u32 a1, u32 a2);
typedef void (*VirtCall2)(u32 a0, u32 a1);
typedef u32 (*Fn001c9110)(u32);
struct Arg {
    u8 pad[40];

u32 flags;

};
typedef u32 (*VirtFn)(Obj*, Arg*);
typedef void (*Cb)(u32);
typedef void (*Fn_001d8270)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d8310)(u32 a0);
typedef void (*Fn_001d8470)(u32 a0);
typedef void (*Fn_001d8578)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d8bd0)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d9288)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef u32 (*Func_001db610_cb)(u32, u32);
typedef void (*Fn1)(u32);
typedef void (*Fn_0028e080)(u32, u32);
typedef void (*VFn)(u32);
typedef void (*VCall20)(void*);
typedef void (*VCall16)(void*);
typedef u32 (*Method1)(u32);
typedef void (*VFn73d8)(u32 a0, u8 a1, u32 a2);
typedef void (*Fn_0031d8f8)(u32, u32);
typedef void (*Fn_0031d9b8)(u32);
typedef void (*Fn_0031f968)(u32);
typedef void (*Fn_0031f9c0)(u32);
typedef void (*Fn_00321de8)(u32);
typedef void (*Fn_00321e60_dtor)(u32);
typedef void (*Fn_00321e60_mgr)(u32, u32);
typedef void (*Fn_00321ef8)(u32);
typedef void (*Fn_00321f70_dtor)(u32);
typedef void (*Fn_00321f70_mgr)(u32, u32);
typedef void (*Fn_00322008)(u32);
typedef void (*Fn_00322080_dtor)(u32);
typedef void (*Fn_00322080_mgr)(u32, u32);
typedef void (*Fn_00322118_dtor)(u32);
typedef void (*Fn_00322118_mgr)(u32, u32);
typedef void (*Fn_003221b0)(u32);
typedef void (*Fn_00322908)(u32, u32);
typedef void (*Fn_00322a98)(u32);
typedef void (*Fn_00322a10)(u32, u32);
typedef void (*Fn_00322b10_dtor)(u32);
typedef void (*Fn_00322b10_mgr)(u32, u32);
typedef void (*FnMgr)(u32, u32);

u32 func_00185be0(u32 a0, u32 a1, float a2) {
    u32 s0 = func_001050d8(2816);
    func_00185b70(s0, a0, a1, a2);
    return s0;
}
}  // namespace r12

// 00185c48 (src/anon/batch_w42.cpp)
namespace r13 {
typedef unsigned int u128  asm("u128")__attribute__((mode(TI)));
void LoadDataFree(...) asm("_ZN2Tz12LoadDataFreeEz");
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void change_action(void*, s32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
void vm_call(u32, s32, void*, s32) asm("_ZN2YS2VM4callEiP8BD_VALUEi");
void vm_callback(u32, s32, void*, s32, void*) asm("_ZN2YS2VM8callbackEiP8BD_VALUEiPS0_");
u32 vm_start(void*, void*) asm("_ZN2YS2VM5StartEPvPNS_3OBJE");
void btlobj_pre_exec(void*) asm("_ZN2YS6BTLOBJ13_OVR_pre_execEv");
void collision_make(void*, s32, f32, f32) asm("_ZN2YS9COLLISION4makeEiff");
s32 has_ansem_entry(u32) asm("_ZN2Tz6JmInfo13HasAnsemEntryEj");
u8* item_each(void*) asm("_ZN2YS10ITEM_TABLE4EachEPKS0_");
void command_menu_clear(void*) asm("_ZN2YS12COMMAND_MENU5clearEv");
void mission_add_count(s32, s32) asm("_ZN2YS7MISSION8AddCountEii");
u128* effect_color(void*) asm("_ZN3ryj6EFFECT5colorEv");
void wtarget_00239bf8(void*, s32) asm("_Z16wtarget_00239bf8jjjj");
void menu_help_leave(void) asm("_ZN2Tz9CMenuHelp5LeaveEv");
void wtarget_002b7078(void) asm("_Z16wtarget_002b7078jjjj");
u8* oarashi_config(void*) asm("_ZN2Ti9MGOarashi6configEv");
f32 acos_2f8aa0(f32) asm("_ZN3Axa15InnerProductXYZERKNS_8FVECTOR4ES2_");
void lay_file_build_data(void*, void*) asm("_ZN2Tz16LayFileBuildDataEPvj");
void select_begin_leave(void*) asm("_ZN2Tz6Select10BeginLeaveEz");
void select_set_flag(void*, s32) asm("_ZN2Tz6Select7SetFlagEz");
s32 func_00188758(void*) asm("func_00188758");
extern f32 D_00349e10 asm("D_00349e10");

void func_00185c48(u8* p)
{
    if (func_00188758(p + 768) && !(*(u32*)(p + 924) & 4)) {
        f32* t = (f32*)(p + 2800);
        if (0.0f < *t) {
            *t -= D_00349e10;
            if (*t < 0.0f) *t = 0.0f;
        }
    }
    btlobj_pre_exec(p);
}
}  // namespace r13

// 00185cb8 (never written before; OBJ vtable entry)
namespace r_cb8 {
void func_001d6020(u8*, u8*) asm("func_001d6020");
void func_001b3d00(u8*, u8*) asm("func_001b3d00");
void func_00185cb8(u8* o, u8* b) asm("func_00185cb8");
void func_00185cb8(u8* o, u8* b) {
    *(f32*)(o + 2800) += (f32)*(u8*)(*(u8**)(b + 32) + 42);
    func_001d6020(o, b);
    func_001b3d00(o, b);
}
}  // namespace r_cb8
