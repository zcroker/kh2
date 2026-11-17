#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../tozawa/cmenu_selector.hpp"
#include "../tozawa/cmenu_slbase.hpp"
#include "../tz/ui_accessors.hpp"
#include "../tozawa/jm_info.hpp"
#include "../tozawa/file_address_layout.hpp"
#include "../tozawa/item_stat.hpp"
#include "../harata/libdk/obj2d.hpp"
#include "../tozawa/load_data.hpp"

// 0028f1e0 (from src/anon/batch_wcx.cpp)
namespace n0028f1e0 {
f32 func_0028f1e0(f32* a, f32* b, f32 x) asm("func_0028f1e0");
f32 func_0028f1e0(f32* a, f32* b, f32 x)
{
    f32 dx = b[0] - a[0];
    f32 t = (x - a[0]) / dx;
    f32 t2 = t * t;
    f32 t3 = t2 * t;
    f32 h00 = t3 + t3 - t2 * 3.0f + 1.0f;
    f32 h01 = t3 * -2.0f + t2 * 3.0f;
    f32 h10 = t3 - (t2 + t2) + t;
    f32 h11 = t3 - t2;
    return h00 * a[1] + h01 * b[1] + (h10 * a[3] + h11 * b[2]) * dx;
}
}  // namespace n0028f1e0

// 0028f280 (from src/anon/batch_w1601.cpp)
namespace n0028f280 {
// ---- c4.cpp
union UG_0028f280 { u8* p; u32 i; };
extern UG_0028f280 D_0035f480 asm("D_0035f480");
extern u32 D_0035f458 asm("D_0035f458");
extern u32 D_0035f45c asm("D_0035f45c");
extern u32 D_0035f460 asm("D_0035f460");
extern u16 D_0035f468[] asm("D_0035f468");
extern u16 D_0035f470[] asm("D_0035f470");
extern u16 D_0035f478[] asm("D_0035f478");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347e40[] asm("D_00347e40");
u32 func_00103570(void) asm("func_00103570");
void* func_001063f0(u32, u32) asm("func_001063f0");
void func_00239700(u8*) asm("func_00239700");
void func_0028d140(u8*) asm("func_0028d140");
struct Rec0028f280 {
    u8 a[436];
    u8 b[444];
    u32 f880;
    void* operator new[](unsigned int sz, u32 h) { return func_001063f0(sz, h); }
    inline Rec0028f280() __attribute__((always_inline));
    ~Rec0028f280() {}
};
inline Rec0028f280::Rec0028f280() {
        *(u32*)(a + 12) = 0;
        *(u32*)a = (u32)D_00347e60;
        func_00239700(a + 24);
        *(u32*)a = (u32)D_00347e40;
        *(u32*)(a + 408) = 0;
        func_0028d140(b);
}
void func_0028f280(u32 a, u32 b, u32 c, u16* d, u16* e) asm("func_0028f280");
void func_0028f280(u32 a, u32 b, u32 c, u16* d, u16* e)
{
    s32 k;
    D_0035f458 = a;
    D_0035f45c = b;
    D_0035f460 = c;
    D_0035f480.p = (u8*)new (func_00103570()) Rec0028f280[4];
    for (k = 0; k < 4; k++) ((Rec0028f280*)D_0035f480.p)[k].f880 = 0;
    for (k = 0; k < 3; k++) {
        D_0035f468[k] = d[k];
        D_0035f470[k] = d[k];
        D_0035f478[k] = e[k];
    }
}
}  // namespace n0028f280

// 0028f3e8 (from src/anon/batch_w8023.cpp)
namespace n0028f3e8 {
extern s32 D_0035f458 asm("D_0035f458");
extern s32 D_0035f45c asm("D_0035f45c");
extern s32 D_0035f460 asm("D_0035f460");
extern u8 D_00347e60[] asm("D_00347e60");
void func_0031a840(void*) asm("func_0031a840");
void func_00323d30(void*) asm("func_00323d30");
void yi_sequence_dtor_28f3e8(void*) asm("_ZN2YI8SEQUENCED1Ev");
struct A0_28f3e8 { ~A0_28f3e8() { func_0031a840(this); } };
struct M18_28f3e8 { u8 d[0x1b4 - 0x18]; ~M18_28f3e8() { yi_sequence_dtor_28f3e8(this); } };
struct B0_28f3e8 : A0_28f3e8 { void* vt; u8 pad[20]; M18_28f3e8 m; ~B0_28f3e8() { vt = D_00347e60; } };
struct M1b4_28f3e8 { u8 d[884 - 436]; ~M1b4_28f3e8() { func_00323d30(this); } };
struct C0_28f3e8 : B0_28f3e8 { M1b4_28f3e8 m2; ~C0_28f3e8() {} };
extern "C" C0_28f3e8* D_0035f480;
extern C0_28f3e8* D_0035f480_b asm("D_0035f480");
void func_0028f3e8(void) asm("func_0028f3e8");
void func_0028f3e8(void) {
    D_0035f458 = -1;
    D_0035f45c = -1;
    D_0035f460 = 0;
    if (D_0035f480) {
        C0_28f3e8* p = D_0035f480 + ((s32*)D_0035f480)[-1];
        for (;;) {
            if (D_0035f480 == p) break;
            --p;
            p->~C0_28f3e8();
        }
        operator delete[]((s32*)D_0035f480_b - 1);
        D_0035f480_b = 0;
    }
}
}  // namespace n0028f3e8

// 0028f4a0 (from src/anon/batch_w15.cpp)
namespace n0028f4a0 {
extern u16 D_0035f470[3] asm("D_0035f470");
void func_0028f4a0(u16* src) asm("func_0028f4a0");
void func_0028f4a0(u16* src) {
    for (int i = 0; i < 3; i++) D_0035f470[i] = src[i];
}
}  // namespace n0028f4a0

// 0028f4d8 (from src/anon/batch_w288.cpp)
namespace n0028f4d8 {
// --- 0028f4d8
struct Lay { u8 p[40]; void* f28; };
extern u32 D_0035f480 asm("D_0035f480");
#define BASE ((u8*)D_0035f480)
extern u32 D_0035f460 asm("D_0035f460");
extern s32 D_0035f45c asm("D_0035f45c");
extern s32 D_0035f458 asm("D_0035f458");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s16 D_0035f470[] asm("D_0035f470");
extern s16 D_0035f468[] asm("D_0035f468");
extern u8 D_0035f478[] asm("D_0035f478");
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
Lay* tz_getLayout(void*) asm("_ZN2Tz6Layout9getLayoutEv");
void* yi_GetSequenceUnit(void*, s32) asm("_ZN2YI6LAYOUT15GetSequenceUnitEi");
void* yi_GetImage(void*, s32) asm("_ZN2YI12IMAGE_FREEZE8GetImageEi");
void dk_SpriteMessage_create(void*, s32, void*, void*, s32, void*, s32) asm("_ZN2dk13SpriteMessage6createEiPvPN2YI5IMAGEEiPKN2YS7MESSAGEEii");
s32 yi_GetParamEx(void*) asm("_ZN2YI8SEQUENCE10GetParamExEv");
void dk_setOffsetPos(void*, s32, s32) asm("_ZN2dk6Sprite12setOffsetPosEii");
void dk_getSeqPraramXYOff(void*) asm("_ZN2dk5Obj2D17getSeqPraramXYOffEv");
void tz_SetMsgId(s32, s32) asm("_ZN2Tz7SelHist8SetMsgIdEii");
void func_0028d1c0(void*, s32, s32, s32, void*, void*, s32) asm("func_0028d1c0");
void func_0028d660(void*, void*) asm("func_0028d660");
// record_set_value_refresh
struct Ent884 { u8 p[436]; u8 sub[444]; u32 f880; };
void func_0028f4d8(s32 idx, s32 msg, u8 sel) asm("func_0028f4d8");
void func_0028f4d8(s32 idx, s32 msg, u8 sel) {
    u8* e = BASE + idx * 884;
    if (u_call4_00139d78(e)) return;
    void* unit = yi_GetSequenceUnit(tz_getLayout((void*)D_0035f460), D_0035f45c);
    void* img = yi_GetImage(tz_getLayout((void*)D_0035f460)->f28, D_0035f458);
    s32 id = D_0035f3d4;
    s16* t = sel ? D_0035f470 : D_0035f468;
    dk_SpriteMessage_create(e, id, unit, img, t[0], 0, 0);
    *(s32*)(e + 392) = t[2];
    dk_setOffsetPos(e, yi_GetParamEx(e + 24) * idx, 0);
    dk_getSeqPraramXYOff(e);
    *(s32*)(e + 428) = 1;
    if (msg >= 0) tz_SetMsgId(idx, msg);
    s32 off = idx * 884;
    *(u32*)(e + 408) = ((Ent884*)D_0035f480)[idx].f880;
    func_0028d1c0(BASE + off + 436, D_0035f3d4 + 1, D_0035f45c, D_0035f458, (void*)D_0035f460, D_0035f478, 0);
    func_0028d660(BASE + off + 436, e);  // record_set_value_refresh
}
}  // namespace n0028f4d8

// 0028f690 (from src/anon/batch_w43.cpp)
namespace n0028f690 {
extern u8* D_0035f480 asm("D_0035f480");
struct Ent8 { s16 ids[3]; s16 pad; };
extern Ent8 D_0035f468[] asm("D_0035f468");
// 0028e5e0: moved to src/anon/unit_0028c878.cpp

Ent8* func_0028f690(s32 i) asm("func_0028f690");
Ent8* func_0028f690(s32 i) {  // record884_type_index
    u8* q = D_0035f480;
    q += i * 884;
    s32 v = *(s32*)(q + 388);
    Ent8* r = 0;
    for (s32 k = 0; k < 3; k++)
        if (v == D_0035f468[0].ids[k]) r = &D_0035f468[0];
    if (!r) r = &D_0035f468[1];
    return r;
}
}  // namespace n0028f690

// 0028f6f0 (from src/anon/batch_wcx2.cpp)
namespace n0028f6f0 {
union UG_0028f6f0 { u8* p; u32 i; };
extern UG_0028f6f0 D_0035f480 asm("D_0035f480");
s32 func_00139d78_f6f0(u8*) asm("func_00139d78");
s16* func_0028f690(s32) asm("func_0028f690");
void func_00138c10_f6f0(u8*, s32) asm("func_00138c10");
void func_0028d5d0(u8*) asm("func_0028d5d0");
void func_0028f6f0(s32 i) asm("func_0028f6f0");
void func_0028f6f0(s32 i) {  // record884_refresh_by_index
    if (!D_0035f480.p) return;
    s32 off = i * 884;
    if (!func_00139d78_f6f0(D_0035f480.p + off)) return;
    s16* v = func_0028f690(i);  // record884_type_index
    if (*(s32*)(D_0035f480.p + off + 388) == v[1]) return;
    func_00138c10_f6f0(D_0035f480.p + off, v[1]);
    *(s32*)(D_0035f480.p + off + 392) = -1;
    func_0028d5d0(D_0035f480.p + off + 436);
}
}  // namespace n0028f6f0

// 0028f7a0 (from src/anon/tiny_auto80_queue.cpp)
namespace n0028f7a0 {
extern "C" void func_0028f6f0(...) asm("func_0028f6f0");
// 0028eb38: moved to src/anon/unit_0028c878.cpp

void func_0028f7a0() asm("_ZN2Tz7SelHist10FadeOutAllEv");
void func_0028f7a0() {
    s32 base = 0x360000;
    s32 s0 = 0;
    if (*(s32*)(base - 2944) != 0) {
        do {
            func_0028f6f0((u32)s0);  // record884_refresh_by_index
            s0 = s0 + 1;
        } while (s0 < 4);
    }
}
}  // namespace n0028f7a0

// 0028f7e8 (from src/anon/batch_w54.cpp)
namespace n0028f7e8 {
extern void (*D_0032ba34)(void) asm("void");
s32 func_00139d78(void*) asm("func_00139d78");
extern u8* D_0035f480 asm("D_0035f480");
void func_00139510(void*) asm("func_00139510");
s32 func_0028d6e8(void*) asm("func_0028d6e8");
// Tz::JmStory::LeaveAllPost(...)
void JmStory_LeaveAllPost(s32 i) asm("_ZN2Tz7JmStory12LeaveAllPostEz");
void JmStory_LeaveAllPost(s32 i) {
    if (!D_0035f480) return;
    s32 off = i * 884;
    if (func_00139d78(D_0035f480 + off)) func_00139510(D_0035f480 + off);
    if (func_0028d6e8(D_0035f480 + off + 436)) func_00139510(D_0035f480 + off + 436);
}
}  // namespace n0028f7e8


// 0028f878 (from src/anon/batch_w8004.cpp)
namespace n0028f878 {
extern "C" u8* D_0035f480;
union GPi_w8004 { u8* p; s32 i; };
extern GPi_w8004 D_0035f480u_w8004 asm("D_0035f480");
s32 func_00139d78(void*) asm("func_00139d78");
void func_00139510(void*) asm("func_00139510");
s32 func_0028d6e8(void*) asm("func_0028d6e8");
// The exit test inside a for(;;) with break keeps the loop counting up (slti 4).
void func_0028f878(void*) asm("func_0028f878");
void func_0028f878(void*) {
    s32 i;
    if (D_0035f480) {
        for (i = 0;;) {
            if (func_00139d78(D_0035f480 + i * 884)) func_00139510(D_0035f480 + i * 884);
            *(u32*)(i * 884 + D_0035f480 + 880) = 0;
            if (func_0028d6e8(D_0035f480u_w8004.p + i * 884 + 436)) func_00139510(D_0035f480u_w8004.p + i * 884 + 436);
            i++;
            if (i >= 4) break;
        }
    }
}
}  // namespace n0028f878

// 0028f930 (from src/anon/batch_wcx.cpp)
namespace n0028f930 {
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
extern u8* D_0035f480 asm("D_0035f480");
s32 func_0028d6e8(u8*) asm("func_0028d6e8");
s32 func_0028f930(s32 k) asm("func_0028f930");
s32 func_0028f930(s32 k)
{
    s32 r = 0;
    for (s32 i = 0; i < 4; i++) {
        if (k >= 0 && k != i) continue;
        if (u_call4_00139d78(D_0035f480 + i * 884) || func_0028d6e8(D_0035f480 + i * 884 + 436)) { r = 1; break; }
    }
    return r;
}
}  // namespace n0028f930

// 0028f9d8 (gap: unwritten in the old code)
namespace n0028f9d8 {
extern u8* D_0035f480 asm("D_0035f480");
s32 f_139d78(u8*) asm("func_00139d78");
u8* f_28f690(s32) asm("func_0028f690");
u32 f_28d6e8(u8*) asm("_ZN2Tz8LightCur7isExistEv");
s32 func_0028f9d8(s32 idx) {
    s32 r = 1;
    s32 off = 0;
    for (s32 i = 0; i < 4; i++, off += 884) {
        if (idx >= 0 && idx != i) continue;
        if (!f_139d78(D_0035f480 + off)) continue;
        u8* e = f_28f690(i);
        u8* o = D_0035f480 + off;
        if (*(s32*)(o + 388) != *(s16*)(e + 4)) { r = 0; break; }
        f_28d6e8(o + 436);
    }
    return r;
}
}  // namespace n0028f9d8

// 0028fa98 (from src/anon/auto80_199_queue.cpp)
namespace n0028fa98 {
u32 func_00139d78(...) asm("func_00139d78");
u32 func_0028da70(...) asm("func_0028da70");
extern u32 D_0035f480 asm("D_0035f480");
u32 func_0028f690(u32) asm("func_0028f690");
// 0028ea30: moved to src/anon/unit_0028c878.cpp

void func_0028fa98(s32 which) asm("_ZN2Tz5CmTop12LeaveListAllEv");
void func_0028fa98(s32 which) {
    u32 i = 0;
    u32 off = 0;
    do {
        if (which < 0 || which == (s32)i) {
            if (func_00139d78(D_0035f480 + off) != 0) {
                u32 p = func_0028f690(i);  // record884_type_index
                func_0028da70(D_0035f480 + off, (u32)*(s16*)(p + 4));
            }
        }
        i += 1;
        off += 884;
    } while ((s32)i < 4);
}
}  // namespace n0028fa98

// 0028fb28 (from src/anon/batch_w15.cpp)
namespace n0028fb28 {
void SetMsgId_impl(void* self, int id, int) asm("_ZN2Tz7SelHist8SetMsgIdEii");
u32 get_msg_00192048(int) asm("_Z16u_tail4_00192048jjjj");
void set_msg_0028fb68(void*, u32) asm("_ZN2Tz7SelHist6SetMsgEiPKN2YS7MESSAGEE");
void SetMsgId_impl(void* self, int id, int) {
    u32 m = 0;
    if (id >= 0) m = get_msg_00192048(id);
    set_msg_0028fb68(self, m);
}
}  // namespace n0028fb28


// 0028fb68 (from src/anon/tiny_auto80_solver.cpp)
namespace n0028fb68 {
void func_0028fb68(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_0028fb68");
extern u32 D_0035f480 asm("D_0035f480");
void func_0028fb68(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_ZN2Tz7SelHist6SetMsgEiPKN2YS7MESSAGEE");
void func_0028fb68(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 stride = 884u;
    u32 base = D_0035f480;
    u32 p = (u32)(a0 * stride + base);
    *(u32*)(p + 880) = a1;
}
}  // namespace n0028fb68

// 0028fb88 (from src/anon/batch_w81.cpp)
namespace n0028fb88 {
// --- 0028fb88: allocate the two sub-objects through the global allocator
typedef u8* (*VFnP81)(...);
struct VObjP81 { VFnP81* vt; };
extern u8* D_00347f80 asm("D_00347f80");
extern u8 D_00347e60[] asm("D_00347e60");
void func_00239700(u8*) asm("func_00239700");
void func_0028dfe8(u8*) asm("func_0028dfe8");
void func_00258d40(u32, u32) asm("func_00258d40");
void func_0028fb88(u8** o, u32 a, u32 b, u16* c) asm("func_0028fb88");
void func_0028fb88(u8** o, u32 a, u32 b, u16* c) {
    VObjP81* al = *(VObjP81**)(D_00347f80 + 20);
    u8* p = al->vt[0](al, 408, 0);
    *(u32*)(p + 12) = 0;
    *(u32*)p = (u32)D_00347e60;
    func_00239700(p + 24);
    o[0] = p;
    al = *(VObjP81**)(D_00347f80 + 20);
    u8* q = al->vt[0](al, 60, 0);
    func_0028dfe8(q);  // obj_ctor_36f440
    o[1] = q;
    s32 i;
    for (i = 0; i < 3; i++) ((u16*)(o + 2))[i] = c[i];
    o[4] = (u8*)a;
    func_00258d40(a, b);
}
}  // namespace n0028fb88

// 0028fc78 (from src/anon/batch_w82.cpp)
namespace n0028fc78 {
struct Alloc0014 { struct VT { void* (*alloc)(void*, u32, u32); }* vt; };
struct Mgr0014 { u8 pad[20]; Alloc0014* heap; };
extern Mgr0014* D_00347f80 asm("D_00347f80");
extern u8 D_00347e60[] asm("D_00347e60");
void func_00239700(u8*) asm("func_00239700");
void func_0028dfe8(void*) asm("func_0028dfe8");
void func_00258d40(u32, u32) asm("func_00258d40");
static inline void* Alloc82(u32 n) { Alloc0014* h = D_00347f80->heap; return h->vt->alloc(h, n, 0); }
void func_0028fc78(Mgr0014** a0, u32 a1, u32 a2, u16* a3) asm("func_0028fc78");
void func_0028fc78(Mgr0014** a0, u32 a1, u32 a2, u16* a3)
{
    u8* o = (u8*)Alloc82(408);
    s32 i;
    *(u32*)(o + 12) = 0;
    *(u32*)o = (u32)D_00347e60;
    func_00239700(o + 24);
    a0[0] = (Mgr0014*)o;
    o = (u8*)Alloc82(60);
    func_0028dfe8(o);  // obj_ctor_36f440
    a0[1] = (Mgr0014*)o;
    for (i = 0; i < 3; i++) ((u16*)(a0 + 2))[i] = a3[i];
    *(u32*)(a0 + 4) = a1;
    func_00258d40(a1, a2);
}
}  // namespace n0028fc78

// 0028fd68 (from src/anon/auto80_199_queue.cpp)
namespace n0028fd68 {
void func_0028ff68(u32) asm("func_0028ff68");
struct Obj_0028fd68 {
    u32 p0;

u32 p1;

};
void func_0028fd68(Obj_0028fd68* self) asm("func_0028fd68");
void func_0028fd68(Obj_0028fd68* self) {
    func_0028ff68((u32)self);
    if (self->p0 != 0) {
        u32 p = self->p0;
        ((void(*)(u32))(*(u32*)(*(u32*)p + 16)))(p);
        self->p0 = 0;
    }
    if (self->p1 != 0) {
        u32 p = self->p1;
        ((void(*)(u32))(*(u32*)(*(u32*)p + 16)))(p);
        self->p1 = 0;
    }
}
}  // namespace n0028fd68

// 0028fdd0 (from src/anon/auto80_199_queue.cpp)
namespace n0028fdd0 {
void func_0028ff68(u32) asm("func_0028ff68");
struct Obj_0028fdd0 {
    u32 p0;

u32 p1;

};
void func_0028fdd0(Obj_0028fdd0* self) asm("func_0028fdd0");
void func_0028fdd0(Obj_0028fdd0* self) {
    func_0028ff68((u32)self);
    if (self->p0 != 0) {
        u32 p = self->p0;
        ((void(*)(u32))(*(u32*)(*(u32*)p + 16)))(p);
        self->p0 = 0;
    }
    if (self->p1 != 0) {
        u32 p = self->p1;
        ((void(*)(u32))(*(u32*)(*(u32*)p + 16)))(p);
        self->p1 = 0;
    }
}
}  // namespace n0028fdd0

// 0028fe38 (from src/anon/batch_wcx2.cpp)
namespace n0028fe38 {
// 128-bit copies (lq/sq) are hand-written asm in the original.
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14;
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
void func_00290060(u8*, u32, u32, u32) asm("func_00290060");
void func_001386e0_fe38(u32, u32, u32, u32, s32, u32) asm("func_001386e0");
void func_00259020(u32, u32, u32, u32, u32, u16*, u32, u32) asm("func_00259020");
void func_0028ff00(u8*) asm("func_0028ff00");
union UH28f { u16 h; s32 i; };
void func_0028fe38_fe38(u8* p, u32 a1, u32 a2, u32 a3) asm("func_0028fe38");
void func_0028fe38_fe38(u8* p, u32 a1, u32 a2, u32 a3) {
    func_00290060(p, a1, a2, a3);
    func_001386e0_fe38(*(u32*)p, a1, a2, a3, *(s16*)(p + 8), 0);
    *(s32*)(*(u8**)p + 392) = *(s16*)(p + 12);
    u16 buf[6];
    u16* d = buf;
    for (s32 i = 5; i >= 0; i--) *d++ = ((UH28f*)(p + 16))->h;
    func_00259020(*(u32*)(p + 4), *(u32*)p, a1, a2, a3, buf, 6, 0);
    func_0028ff00(p);
}
}  // namespace n0028fe38


// 0028ff00 (from src/anon/tiny.cpp)
namespace n0028ff00 {
void func_00258df0(s32) asm("func_00258df0");
void func_0028ff00(BD_VALUE* bd) asm("_ZN2Tz9MunnyDraw6UpdateEv");
void func_0028ff00(BD_VALUE* bd) { func_00258df0(bd[1].i); }
}  // namespace n0028ff00

// 0028ff18 (from src/anon/batch_w51.cpp)
namespace n0028ff18 {
void func_00290060(void*) asm("func_00290060");
void func_00138c10(void*, s32) asm("func_00138c10");
struct SprRef { u8* o; u32 pad[2]; s16 h12; };
void func_0028ff18(SprRef* p) asm("func_0028ff18");
void func_0028ff18(SprRef* p) {
    func_00290060(p);
    if (*(s32*)(p->o + 388) != p->h12) {
        func_00138c10(p->o, p->h12);
        *(s32*)(p->o + 392) = -1;
    }
}
}  // namespace n0028ff18

// 0028ff68 (from src/anon/batch_w64.cpp)
namespace n0028ff68 {
typedef void (*VFn)(void*);
s32 func_00139d78(void*) asm("func_00139d78");
// 0028cdb8: moved to src/anon/unit_0028c878.cpp

// ---------------------------------------------------------------------------
void func_0028ff68(u8** p) asm("func_0028ff68");
void func_0028ff68(u8** p) {
    if (p[0] && func_00139d78(p[0])) (*(VFn*)(*(u8**)p[0] + 20))(p[0]);
    if (p[1] && func_00139d78(p[1])) (*(VFn*)(*(u8**)p[1] + 20))(p[1]);
}
}  // namespace n0028ff68

// 0028ffe8 (from src/anon/auto80_199_queue.cpp)
namespace n0028ffe8 {
u32 func_00138c10(...) asm("func_00138c10");
u32 func_00139d78(...) asm("func_00139d78");
u32 func_00290060(u32) asm("func_00290060");
struct Obj_0028ffe8 {
    u32 field0;

u8 pad4[4];

s16 arr[6];

};
void func_0028ffe8(Obj_0028ffe8* self, u32 idx) asm("func_0028ffe8");
void func_0028ffe8(Obj_0028ffe8* self, u32 idx) {
    if (func_00290060((u32)self) == 0) {
        return;
    }
    if (func_00139d78(self->field0) != 0) {
        s32 value = (s32)self->arr[idx];
        u32 base = self->field0;
        if (*(s32*)(base + 388) != value) {
            func_00138c10(base, (u32)value);
            *(s32*)(self->field0 + 392) = -1;
        }
    }
}
}  // namespace n0028ffe8

// 00290060 (from src/anon/tiny_auto80_queue.cpp)
namespace n00290060 {
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
u32 func_00290060(void* a0) asm("func_00290060");
u32 func_00290060(void* a0) {
    u8* s0 = (u8*)a0;
    u32 v0 = func_00139d78(*(void**)s0);
    if (v0 == 0u) {
        v0 = func_00139d78(*(void**)(s0 + 4));
    }
    return v0;
}
}  // namespace n00290060

// 00290098 (from src/anon/batch_w90.cpp)
namespace n00290098 {
struct VObj { void** vt; };
// 00290098
union HeapRef { u8* p; u32 w; };
extern HeapRef D_00347f80 asm("D_00347f80");
extern u8 D_00347e60[] asm("D_00347e60");
void func_00239700(void*) asm("func_00239700");
void func_0028dfe8(void*) asm("func_0028dfe8");
void func_00258d58(u32, u32, u32) asm("func_00258d58");
typedef u8* (*AllocFn)(void*, u32, u32);
static inline u8* HeapAlloc(u32 n) { VObj* al = *(VObj**)(D_00347f80.p + 20); return ((AllocFn)al->vt[0])(al, n, 0); }
struct Pair290 { u8* a; u8* b; u16 v[3]; u16 pad; u32 x; };
void func_00290098(Pair290* self, u32 a1, u32 a2, u32 a3, u16* src) asm("func_00290098");
void func_00290098(Pair290* self, u32 a1, u32 a2, u32 a3, u16* src)
{
    u8* a = HeapAlloc(408);
    *(u32*)(a + 12) = 0;
    *(void**)a = D_00347e60;
    func_00239700(a + 24);
    self->a = a;
    u8* b = HeapAlloc(60);
    func_0028dfe8(b);  // obj_ctor_36f440
    self->b = b;
    for (s32 i = 0; i < 3; i++) self->v[i] = src[i];
    self->x = a1;
    func_00258d58(a1, a2, a3);
}
}  // namespace n00290098

// 00290198 (from src/anon/batch_w91.cpp)
namespace n00290198 {
extern u8* D_00347f80 asm("D_00347f80");
extern u8 D_00347e60[] asm("D_00347e60");
void func_00239700(u8*) asm("func_00239700");
void func_0028dfe8(u8*) asm("func_0028dfe8");
void func_00258d58(u32, u32, u32) asm("func_00258d58");
typedef u8* (*AllocFn91)(u8*, u32, u32);
void func_00290198(u8* self, u32 a, u32 b, u32 c, u16* arr) asm("func_00290198");
void func_00290198(u8* self, u32 a, u32 b, u32 c, u16* arr) {
    u8* h = *(u8**)(D_00347f80 + 20);
    u8* o = (**(AllocFn91**)h)(h, 408, 0);
    *(u32*)(o + 12) = 0;
    *(u8**)o = D_00347e60;
    func_00239700(o + 24);
    *(u8**)self = o;
    u8* h2 = *(u8**)(D_00347f80 + 20);
    u8* o2 = (**(AllocFn91**)h2)(h2, 60, 0);
    func_0028dfe8(o2);  // obj_ctor_36f440
    *(u8**)(self + 4) = o2;
    for (s32 i = 0; i < 3; i++) ((u16*)(self + 8))[i] = arr[i];
    *(u32*)(self + 16) = a;
    func_00258d58(a, b, c);
}
}  // namespace n00290198

// 00290298 (from src/anon/auto80_199_queue.cpp)
namespace n00290298 {
void func_00290488(u32) asm("func_00290488");
struct Obj_00290298 {
    u32 p0;

u32 p1;

};
void func_00290298(Obj_00290298* self) asm("func_00290298");
void func_00290298(Obj_00290298* self) {
    func_00290488((u32)self);
    if (self->p0 != 0) {
        u32 p = self->p0;
        ((void(*)(u32))(*(u32*)(*(u32*)p + 16)))(p);
        self->p0 = 0;
    }
    if (self->p1 != 0) {
        u32 p = self->p1;
        ((void(*)(u32))(*(u32*)(*(u32*)p + 16)))(p);
        self->p1 = 0;
    }
}
}  // namespace n00290298

// 00290300 (from src/anon/auto80_199_queue.cpp)
namespace n00290300 {
void func_00290488(u32) asm("func_00290488");
struct Obj_00290300 {
    u32 p0;

u32 p1;

};
void func_00290300(Obj_00290300* self) asm("func_00290300");
void func_00290300(Obj_00290300* self) {
    func_00290488((u32)self);
    if (self->p0 != 0) {
        u32 p = self->p0;
        ((void(*)(u32))(*(u32*)(*(u32*)p + 16)))(p);
        self->p0 = 0;
    }
    if (self->p1 != 0) {
        u32 p = self->p1;
        ((void(*)(u32))(*(u32*)(*(u32*)p + 16)))(p);
        self->p1 = 0;
    }
}
}  // namespace n00290300

// 00290368 (from src/anon/auto80_199_queue.cpp)
namespace n00290368 {
u32 func_001386e0(...) asm("func_001386e0");
u32 func_001395e8(...) asm("func_001395e8");
u32 func_00139610(...) asm("func_00139610");
u32 func_001396b0(...) asm("func_001396b0");
void func_0028e0d8(u32, u32, u32, u32, u32, u32, u32) asm("func_0028e0d8");
void func_0028eab8(u32, u32) asm("func_0028eab8");
void func_0028e710(u32, u32) asm("func_0028e710");
void func_00139660(u32) asm("func_00139660");
void func_00139688(u32) asm("func_00139688");
void func_0028ebf0(u32, s32) asm("func_0028ebf0");
struct Obj_00290368 {
    u32 field0;

u32 field4;

s16 field8;

s16 padA;

s16 field12;

u8 field14;

u8 field15;

u8 field16;

};
void func_00259020(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_00259020");
void func_00290420(u32) asm("func_00290420");
void func_00259020(
    u32 a0,
    u32 a1,
    u32 a2,
    u32 a3,
    u32 a4,
    u32 a5,
    u32 a6,
    u32 a7
) asm("func_00259020");
void func_00290368(Obj_00290368* self, u32 a1, u32 a2, u32 a3) asm("func_00290368");
void func_00290368(Obj_00290368* self, u32 a1, u32 a2, u32 a3) {
    func_001386e0(self->field0, a1, a2, a3, (u32)(s32)self->field8, 0);
    *(s32*)(self->field0 + 392) = (s32)self->field12;

    u16 tmp[9];
    u16 v = self->field16;
    for (s32 i = 0; i < 9; i += 1) {
        tmp[i] = v;
    }

    func_00259020(self->field4, self->field0, a1, a2, a3, (u32)tmp, 9, 0);
    func_00290420((u32)self);
}
}  // namespace n00290368

// 00290420 (from src/anon/tiny.cpp)
namespace n00290420 {
void func_00258eb8(s32) asm("func_00258eb8");
void func_00290420(BD_VALUE* bd) asm("_ZN2Tz8TimeDraw6UpdateEv");
void func_00290420(BD_VALUE* bd) { func_00258eb8(bd[1].i); }
}  // namespace n00290420

// 00290438 (from src/anon/batch_w52.cpp)
namespace n00290438 {
void func_00290580(u8*) asm("func_00290580");
void func_00138c10(u8*, s16) asm("func_00138c10");
void func_00290438(u8* p) asm("func_00290438");
void func_00290438(u8* p) {
    func_00290580(p);
    u8* o = *(u8**)p;
    s16 k = *(s16*)(p + 12);
    if (*(s32*)(o + 388) != k) {
        func_00138c10(o, k);
        *(s32*)(*(u8**)p + 392) = -1;
    }
}
}  // namespace n00290438

// 00290488 (from src/anon/batch_w65.cpp)
namespace n00290488 {
s32 func_00139d78(void*) asm("func_00139d78");
struct VObj { void** vt; };
// 0028da70: moved to src/anon/unit_0028c878.cpp

void func_00290488(VObj** p) asm("func_00290488");
void func_00290488(VObj** p) {
    if (p[0] && func_00139d78(p[0])) ((void (*)(VObj*))p[0]->vt[5])(p[0]);
    if (p[1] && func_00139d78(p[1])) ((void (*)(VObj*))p[1]->vt[5])(p[1]);
}
}  // namespace n00290488

// 00290508 (from src/anon/auto80_199_queue.cpp)
namespace n00290508 {
u32 func_00138c10(...) asm("func_00138c10");
u32 func_00139d78(...) asm("func_00139d78");
u32 func_00290580(u32) asm("func_00290580");
struct Obj_00290508 {
    u32 field0;

u8 pad4[4];

s16 arr[8];

};
void func_00290508(Obj_00290508* self, u32 idx) asm("func_00290508");
void func_00290508(Obj_00290508* self, u32 idx) {
    if (func_00290580((u32)self) == 0) {
        return;
    }
    if (func_00139d78(self->field0) != 0) {
        s32 value = (s32)self->arr[idx];
        u32 base = self->field0;
        if (*(s32*)(base + 388) != value) {
            func_00138c10(base, (u32)value);
            *(s32*)(self->field0 + 392) = -1;
        }
    }
}
}  // namespace n00290508

// 00290580 (from src/anon/tiny_auto80_queue.cpp)
namespace n00290580 {
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
extern "C" u32 func_00139d78(...) asm("func_00139d78");
u32 func_00290580(void* a0) asm("func_00290580");
u32 func_00290580(void* a0) {
    u8* s0 = (u8*)a0;
    u32 v0 = func_00139d78(*(void**)s0);
    if (v0 == 0u) {
        v0 = func_00139d78(*(void**)(s0 + 4));
    }
    return v0;
}
}  // namespace n00290580

// 002905b8 (from src/anon/auto80_199_queue.cpp)
namespace n002905b8 {
u32 func_00239700(...) asm("func_00239700");
extern u8 D_00347e60 asm("D_00347e60");
u32 func_002361a0(...) asm("func_002361a0");
u32 func_00290738(...) asm("func_00290738");
extern u32 D_0035f490 asm("D_0035f490");
void func_002905b8(u32 self) asm("func_002905b8");
void func_002905b8(u32 self) {
    *(u32*)(self + 12) = 0;
    *(u32*)self = (u32)&D_00347e60;
    func_00239700(self + 24);
    *(u32*)self = (u32)&D_0035f490;
    func_002361a0(self + 416);
    func_00290738(self, 30022);
}
}  // namespace n002905b8

// 00290610 (from src/anon/auto200_999.cpp)
namespace n00290610 {
void func_002361a0(...) asm("func_002361a0");
u32 func_00239700(...) asm("func_00239700");
u32 func_00290738(...) asm("func_00290738");
extern u8 D_00347e60 asm("D_00347e60");
extern u32 D_0035f490 asm("D_0035f490");
void func_00290610(u32 self) asm("func_00290610");
void func_00290610(u32 self) {
    *(u32 *)(self + 12) = 0;
    *(u32 *)self = (u32)&D_00347e60;
    func_00239700(self + 24);
    *(u32 *)self = (u32)&D_0035f490;
    func_002361a0(self + 416);
    func_00290738(self, 30022);
}
}  // namespace n00290610

// 00290668 (from src/anon/batch_w228.cpp)
namespace n00290668 {
void func_00290740(u8*) asm("func_00290740");
void func_002362b0(u8*, u32) asm("func_002362b0");
void func_002367c8(u8*) asm("func_002367c8");
void func_001386e0(u8*, u32, u32, u8*, u32, u32) asm("func_001386e0");
// 001843d8: moved to src/anon/unit_00183088.cpp

void Selector_CreateHelpGra(u8* t, u32 a1, u32 a2, u32 a3) asm("_ZN2Tz8Selector13CreateHelpGraEz");
void Selector_CreateHelpGra(u8* t, u32 a1, u32 a2, u32 a3) {
    func_00290740(t);
    u8* s0 = t + 416;
    func_002362b0(s0, a2);
    func_002367c8(s0);  // obj_dispatch_bitfield64
    func_001386e0(t, *(u32*)(t + 408), a1, s0, a3, 0);
    u32* q = (u32*)(t + 24);
    q[46] |= 8;
    t[405] = 1;
}
}  // namespace n00290668


// 00290708 (from src/anon/tiny.cpp)
namespace n00290708 {
void func_00138840(void*) asm("func_00138840");
// 0028dac8: moved to src/anon/unit_0028c878.cpp
void func_00290708(BD_VALUE* bd) asm("func_00290708");
void func_00290708(BD_VALUE* bd) { func_00138840(bd); }
}  // namespace n00290708

// 00290720 (gap: unwritten in the old code)
namespace n00290720 {
void f_138988() asm("func_00138988");
void func_00290720() { f_138988(); }
}  // namespace n00290720

// 00290738 (from src/tozawa/cmenu_selector.cpp)
namespace Tz {
void Selector::SetHelpGraMsg(u32 a0, s32 v) {
    reinterpret_cast<HelpGraLayout*>(a0)->pri = v;
}
}  // namespace Tz

// 00290740 (from src/anon/tiny_auto80_fptr4.cpp)
namespace n00290740 {
u32 func_00139d78(u32, u32, u32, u32) asm("func_00139d78");
u32 func_00290740(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00290740");
u32 func_00290740(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call4_00139d78)(u32, u32, u32, u32) = func_00139d78;
    r2 = fp_call4_00139d78(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00290740

// 00290760 (from src/anon/auto80_199_queue.cpp)
namespace n00290760 {
u32 func_00103570(...) asm("func_00103570");
extern u32 D_0035f4b0 asm("D_0035f4b0");
u32 func_001063f0(u32, u32) asm("func_001063f0");
void func_002908a8(u32) asm("func_002908a8");
void func_00290760(u32 self, u32 base, u32 count) asm("func_00290760");
void func_00290760(u32 self, u32 base, u32 count) {
    *(u32*)self = (u32)&D_0035f4b0;
    if (base == 0) {
        base = func_00103570();
    }
    *(u32*)(self + 12) = count;
    *(u32*)(self + 20) = func_001063f0(count << 2, base);
    func_002908a8(self);
}
}  // namespace n00290760

// 002907c0 (from src/anon/auto80_199_queue.cpp)
namespace n002907c0 {
u32 func_00103570(...) asm("func_00103570");
extern u32 D_0035f4b0 asm("D_0035f4b0");
u32 func_001063f0(u32, u32) asm("func_001063f0");
void func_002908a8(u32) asm("func_002908a8");
void func_002907c0(u32 self, u32 base, u32 count) asm("_ZN2Tz8MenuFileC1EP9ALLOCATORi");
void func_002907c0(u32 self, u32 base, u32 count) {
    *(u32*)self = (u32)&D_0035f4b0;
    if (base == 0) {
        base = func_00103570();
    }
    *(u32*)(self + 12) = count;
    *(u32*)(self + 20) = func_001063f0(count << 2, base);
    func_002908a8(self);
}
}  // namespace n002907c0

// 00290820 (from src/anon/tiny_auto80_fptr4.cpp)
namespace n00290820 {
u32 func_002908f0(u32, u32, u32, u32) asm("func_002908f0");
extern u8 D_0035f4b0 asm("D_0035f4b0");
u32 func_00290820(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00290820");
u32 func_00290820(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_0035f4b0;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_002908f0)(u32, u32, u32, u32) = func_002908f0;
    r2 = fp_call4_002908f0(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00290820

// 00290848 (from src/anon/tiny_auto80_fptr4.cpp)
namespace n00290848 {
u32 func_002908f0(u32, u32, u32, u32) asm("func_002908f0");
extern u8 D_0035f4b0 asm("D_0035f4b0");
u32 func_00290848(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00290848");
u32 func_00290848(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_0035f4b0;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_002908f0)(u32, u32, u32, u32) = func_002908f0;
    r2 = fp_call4_002908f0(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00290848

// 00290870 (from src/anon/batch_w16.cpp)
namespace n00290870 {
u8 func_00106420(void*) asm("func_00106420");
void func_002908f0(void*) asm("func_002908f0");
extern u8 D_0035f4b0 asm("D_0035f4b0");
void func_00290870(void* p) asm("func_00290870");
void func_00290870(void* p) {
    *(void**)p = &D_0035f4b0;
    func_002908f0(p);
    func_00106420(p);
}
}  // namespace n00290870

// 002908a8 (from src/anon/batch_w28.cpp)
namespace n002908a8 {
// 0028d0f8: moved to src/anon/unit_0028c878.cpp

void func_002908a8(u8* p) asm("func_002908a8");
void func_002908a8(u8* p) {
    s32* q = (s32*)p;
    q[1] = 0;
    p[16] = 0;
    q[2] = 0;
    for (s32 i = 0; i < q[3]; i++) ((s32*)q[5])[i] = 0;
}
}  // namespace n002908a8

// 002908f0 (from src/anon/batch_w27.cpp)
namespace n002908f0 {
void u_call4_002908f0(u32, u32, u32, u32) asm("_Z16u_call4_002908f0jjjj");
void func_00290a60(void*) asm("func_00290a60");
void func_00106450(void*) asm("func_00106450");
void u_call4_002908f0(u32 a, u32, u32, u32) asm("_Z16u_call4_002908f0jjjj");
void u_call4_002908f0(u32 a, u32, u32, u32) {
    u8* p = (u8*)a;
    if (p[16]) func_00290a60(p);
    *(u32*)(p + 4) = 0;
    if (*(void**)(p + 20)) {
        func_00106450(*(void**)(p + 20));
        *(void**)(p + 20) = 0;
    }
}
}  // namespace n002908f0

// 00290940 (from src/tozawa/jm_info.cpp)
namespace Tz {
u32 JmInfo::IsLoaded(u32 data) {
    return reinterpret_cast<const FileAddressLayout*>(data)->fileAddress;
}
}  // namespace Tz

// 00290948 (from src/anon/tiny_leaf.cpp)
namespace n00290948 {
// 0028cf10: moved to src/anon/unit_0028c878.cpp

u32 func_00290948(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00290948");
u32 func_00290948(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u;
    r15 = *(u32*)((u32)r4 + (s32)(20));
    r5 = (u32)(r5 << 2);
    r5 = (u32)(r5 + r15);
    r2 = *(u32*)((u32)r5 + (s32)(0));
    return r2;
}
}  // namespace n00290948

// 00290960 (from src/anon/batch_w58.cpp)
namespace n00290960 {
s32 func_00168aa0(u32, u32) asm("func_00168aa0");
u8* func_00168b38(u32, u32, s32) asm("func_00168b38");
// entry_array_find_nth
void func_00290960(u8* p, u32 a, u32 b) asm("func_00290960");
void func_00290960(u8* p, u32 a, u32 b) {
    *(u32*)(p + 4) = a;
    *(s32*)(p + 8) = func_00168aa0(a, b);
    for (s32 i = 0; i < *(s32*)(p + 8); i++)
        (*(u32**)(p + 20))[i] = *(u32*)(func_00168b38(*(u32*)(p + 4), b, i) + 8);  // entry_array_find_nth
}
}  // namespace n00290960

// 002909f0 (from src/anon/tiny_wrappers_more.cpp)
namespace n002909f0 {
extern "C" u32 YS_CACHE_BUFF_ReadRequest(u32, u32, u32, u32) asm("_ZN2YS10CACHE_BUFF11ReadRequestEPKcij");
u32 func_002909f0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002909f0");
u32 func_002909f0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return YS_CACHE_BUFF_ReadRequest(a1, a2, 0x00000000u, a3);
}
}  // namespace n002909f0

// 00290a10 (from src/anon/batch_w53.cpp)
namespace n00290a10 {
u32 func_001708f8(u32, s32) asm("func_001708f8");
void func_00290960(u8*, u32, u32) asm("func_00290960");
// 0028e438: moved to src/anon/unit_0028c878.cpp

void func_00290a10(u8* p, u32 a, u32 b) asm("func_00290a10");
void func_00290a10(u8* p, u32 a, u32 b) {
    func_00290960(p, func_001708f8(a, -1), b);
    p[16] = 1;
}
}  // namespace n00290a10

// 00290a60 (from src/anon/batch_w9.cpp)
namespace n00290a60 {
void func_00170950(u32) asm("func_00170950");
void jm_unload(u8* j) asm("_ZN2Tz6JmInfo6UnloadEz");
// 0028d708: moved to src/anon/unit_0028c878.cpp

void jm_unload(u8* j) {
    func_00170950(*(u32*)(j + 4));
    *(u32*)(j + 4) = 0;
    j[16] = 0;
}
}  // namespace n00290a60


// 00290a90 (from src/anon/auto80_199_queue.cpp)
namespace n00290a90 {
u32 func_002fde18(...) asm("func_002fde18");
void func_00323e98(u32) asm("func_00323e98");
void func_00290a90(u32 self) asm("func_00290a90");
void func_00290a90(u32 self) {
    func_00323e98(self);
    s32 neg1 = -1;
    *(u32*)(self + 11024) = 0;
    *(s32*)(self + 11028) = neg1;
    u32 p = self + 11068;
    *(s32*)(self + 11032) = neg1;
    u32 z = 0;
    *(s32*)(self + 11036) = neg1;
    func_002fde18(p, z, 16);

    self = self + 11076;
    u32 fill = 100;
    s32 n = 6;
    do {
        *(u8*)self = (u8)fill;
        n -= 1;
        self += 1;
    } while (n >= 0);
}
}  // namespace n00290a90

// 00290b00 (from src/anon/auto80_199_queue.cpp)
namespace n00290b00 {
u32 func_002fde18(...) asm("func_002fde18");
void func_00323e98(u32) asm("func_00323e98");
void func_00290b00(u32 self) asm("func_00290b00");
void func_00290b00(u32 self) {
    func_00323e98(self);
    s32 neg1 = -1;
    *(u32*)(self + 11024) = 0;
    *(s32*)(self + 11028) = neg1;
    u32 p = self + 11068;
    *(s32*)(self + 11032) = neg1;
    u32 z = 0;
    *(s32*)(self + 11036) = neg1;
    func_002fde18(p, z, 16);

    self = self + 11076;
    u32 fill = 100;
    s32 n = 6;
    do {
        *(u8*)self = (u8)fill;
        n -= 1;
        self += 1;
    } while (n >= 0);
}
}  // namespace n00290b00

// 00290b70 (from src/anon/auto80_199_queue.cpp)
namespace n00290b70 {
void func_00290b70(u32 self) asm("func_00290b70");
void func_00290b70(u32 self) {
    u32 s18 = self;
    u32 s16;
    u32 s17;

    if (s18 != (u32)-4364) {
        s16 = s18 + 10904;
        s17 = s18 + 4364;
        for (;;) {
            if (s17 == s16) {
                break;
            }
            s16 -= 436;
            ((void (*)(u32))(*(u32*)(*(u32*)s16 + 12)))(s16);
        }
    }

    if (s18 != (u32)-2184) {
        s16 = s18 + 4364;
        s17 = s18 + 2184;
        for (;;) {
            if (s17 == s16) {
                break;
            }
            s16 -= 436;
            ((void (*)(u32))(*(u32*)(*(u32*)s16 + 12)))(s16);
        }
    }

    if (s18 != (u32)-4) {
        s16 = s18 + 2184;
        s17 = s18 + 4;
        for (;;) {
            if (s17 == s16) {
                break;
            }
            s16 -= 436;
            ((void (*)(u32))(*(u32*)(*(u32*)s16 + 12)))(s16);
        }
    }
}
}  // namespace n00290b70

// 00290c30 (from src/anon/auto80_199_queue.cpp)
namespace n00290c30 {
void func_00290c30(u32 self) asm("func_00290c30");
void func_00290c30(u32 self) {
    u32 s18 = self;
    u32 s16;
    u32 s17;

    if (s18 != (u32)-4364) {
        s16 = s18 + 10904;
        s17 = s18 + 4364;
        for (;;) {
            if (s17 == s16) {
                break;
            }
            s16 -= 436;
            ((void (*)(u32))(*(u32*)(*(u32*)s16 + 12)))(s16);
        }
    }

    if (s18 != (u32)-2184) {
        s16 = s18 + 4364;
        s17 = s18 + 2184;
        for (;;) {
            if (s17 == s16) {
                break;
            }
            s16 -= 436;
            ((void (*)(u32))(*(u32*)(*(u32*)s16 + 12)))(s16);
        }
    }

    if (s18 != (u32)-4) {
        s16 = s18 + 2184;
        s17 = s18 + 4;
        for (;;) {
            if (s17 == s16) {
                break;
            }
            s16 -= 436;
            ((void (*)(u32))(*(u32*)(*(u32*)s16 + 12)))(s16);
        }
    }
}
}  // namespace n00290c30

// 00290cf0 (from src/anon/auto80_199_queue.cpp)
namespace n00290cf0 {
u32 func_002fde18(...) asm("func_002fde18");
void func_00290cf0(u32 self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) asm("_ZN2Tz8ItemStat4InitEPNS_6LayoutEiiiPKsS4_");
void func_00290cf0(u32 self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) {
    s32 i;
    u32 dst;

    *(u32*)(self + 11024) = a1;
    i = 0;
    *(u32*)(self + 11028) = a2;
    dst = self + 11054;
    *(u32*)(self + 11032) = a3;
    *(u32*)(self + 11036) = a4;

    for (;;) {
        *(u16*)dst = *(u16*)a5;
        i = i + 1;
        a5 += 2;
        dst += 2;
        if (i >= 7) {
            break;
        }
    }

    i = 0;
    for (;;) {
        u32 off = (u32)(i << 1);
        *(u16*)(off + self + 11040) = *(u16*)(off + a6);
        i = i + 1;
        if (i >= 7) {
            break;
        }
    }

    func_002fde18(self + 10904, 0, 120);
}
}  // namespace n00290cf0

