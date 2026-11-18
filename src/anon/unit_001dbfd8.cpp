#include "../common/types.h"
#include "../ryj/effect.hpp"
#include "../ryj/effect_data.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "tiny_auto80_solver_structs.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"

// ---- 001dbfd0 manual (gap: plain word setter)
namespace n001dbfd0 {
void func_001dbfd0(s32* p, s32 v) asm("func_001dbfd0");
void func_001dbfd0(s32* p, s32 v) { *p = v; }
}  // namespace n001dbfd0

// ---- 001dbfd8 from src/anon/tiny.cpp
namespace n001dbfd8 {
void func_001e4f40(void*) asm("_Z13func_001e4f40Pv");
void func_001dbfd8(BD_VALUE* bd) asm("_Z13func_001dbfd8P8BD_VALUE");
void func_001dbfd8(BD_VALUE* bd) { func_001e4f40(bd); }
}  // namespace n001dbfd8

// ---- 001dbff0 manual (gap: relocate by a1 - offset)
namespace n001dbff0 {
void func_001e50a8(u32, s32) asm("func_001e50a8");
void func_001dbff0(u32 a, u32 b) asm("func_001dbff0");
void func_001dbff0(u32 a, u32 b) { func_001e50a8(a, a - b); }
}  // namespace n001dbff0

// ---- 001dc010 manual
namespace ryj {
void EFFECT_DATA::set(void* v) { reinterpret_cast<EFFECT_DATA_Layout*>(this)->value = v; }
}  // namespace ryj

// ---- 001dc018 from src/anon/batch_w31.cpp
namespace n001dc018 {
bool func_001dc018(u8** p, s32 key, u32* a, u32* b) asm("func_001dc018");
bool func_001dc018(u8** p, s32 key, u32* a, u32* b) {
    u8* t = *p;
    s32 n = *(s32*)(t + 12);
    u8* e = t + 16;
    int r = 0;
    for (s32 i = 0; i < n; i++, e += 32) {
        if (*(s32*)(e + 8) == key) {
            *a = *(u32*)e;
            *b = *(u32*)(e + 4);
            r = 1;
            break;
        }
    }
    return r;
}
}  // namespace n001dc018

// ---- 001dc070 manual (gap: entry field / entry count)
namespace n001dc070 {
s32 func_001dc070(u8** p, s32 i) asm("func_001dc070");
s32 func_001dc070(u8** p, s32 i) { u8* t = *p; t += i * 32; return *(s32*)(t + 24); }
s32 func_001dc088(u8** p) asm("func_001dc088");
s32 func_001dc088(u8** p) { return *(s32*)(*p + 12); }
}  // namespace n001dc070

// ---- 001dc098 from src/anon/batch_w2370_gnsa_nogcse.cpp
namespace n001dc098 {
struct WHdr_w2370 { u8 pad[12]; s32 count; };
void func_001e4f40(u32) asm("_Z13func_001e4f40j");
void wtarget_001dc098(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_001dc098jjjj");
void wtarget_001dc098(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 base = a0;
    WHdr_w2370* h = (WHdr_w2370*)a0;
    u32* p = (u32*)(a0 + 16);
    s32 i;
    for (i = 0; i < h->count; i++) {
        base = a0;
        if (*p) *p += base;
        p += 8;
    }
    s32 n = *p++;
    for (i = 0; i < n; i++) {
        func_001e4f40(*p++ + base);
    }
}
}  // namespace n001dc098

// ---- 001dc140 from src/anon/batch_w3727.cpp
namespace n001dc140 {
struct WHdr_w3727 { u8 pad[12]; s32 count; };
void func_001e50a8(u32, s32) asm("func_001e50a8");
void wtarget_001dc140(u32* a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_001dc140jjjj");
void wtarget_001dc140(u32* a0, u32 a1, u32 a2, u32 a3) {
    s32 d = (u32)a0 - a1;
    WHdr_w3727* h = (WHdr_w3727*)a0;
    register u32 base0 asm("$12") = (u32)a0;
    asm("" : "+r"(base0));
    s32 i = 0;
    if (((WHdr_w3727*)a0)->count > 0) {
        a0 += 4;
        register u32* p asm("$13") = a0;
        do {
            if (*p) *p += d;
            p += 8;
            i++;
        } while (i < h->count);
        asm("" : "+r"(p));
        a0 = p;
    } else {
        a0 += 4;
    }
    s32 n = *a0++;
    u32 base = base0;
    asm("" : "+r"(base));
    for (i = 0; i < n; i++) func_001e50a8(*a0++ + base, d);
}
}  // namespace n001dc140

// ---- 001dc1f8 manual (gap: C2 copy of the ctor 0x1dc278)
namespace n001dc1f8 {
extern void* D_00352ae0[2] asm("D_00352ae0");
extern s32 D_00352ae8 asm("D_00352ae8");
extern u8 D_00352b48 asm("D_00352b48");
void func_001dc1f8(u8* p, s32 a1, s32 a2) asm("func_001dc1f8");
void func_001dc1f8(u8* p, s32 a1, s32 a2) {
    *(s32*)(p + 0xc) = 0;
    *(s32*)(p + 0x10) = 0;
    *(u32*)p = (u32)&D_00352b48;
    *(s32*)(p + 0x14) = 0;
    *(s32*)(p + 0x18) = 0;
    *(s32*)(p + 0x1c) = 0;
    *(s32*)(p + 0x24) = 0;
    *(f32*)(p + 0x20) = 1.0f;
    if (!D_00352ae0[1]) {
        D_00352ae0[1] = p;
        D_00352ae0[0] = p;
        *(s32*)(p + 0x28) = 0;
    } else {
        *(u8**)((u8*)D_00352ae0[1] + 0x28) = p;
        *(s32*)(p + 0x28) = 0;
        D_00352ae0[1] = p;
    }
    *(s32*)(p + 8) = a1;
    *(s32*)(p + 4) = a2;
    D_00352ae8++;
}
}  // namespace n001dc1f8

// ---- 001dc278 from src/anon/sweep_001dc278_nsa.cpp
namespace n001dc278 {
extern void* D_00352ae0[2] asm("D_00352ae0");
extern s32 D_00352ae8 asm("D_00352ae8");
extern u8 D_00352b48 asm("D_00352b48");
void func_001dc278(u8* p, s32 a1, s32 a2) asm("_Z13func_001dc278Phii");
void func_001dc278(u8* p, s32 a1, s32 a2) {                    
    *(s32*)(p + 0xc) = 0;
    *(s32*)(p + 0x10) = 0;
    *(u32*)p = (u32)&D_00352b48;
    *(s32*)(p + 0x14) = 0;
    *(s32*)(p + 0x18) = 0;
    *(s32*)(p + 0x1c) = 0;
    *(s32*)(p + 0x24) = 0;
    *(f32*)(p + 0x20) = 1.0f;
    if (!D_00352ae0[1]) {
        D_00352ae0[1] = p;
        D_00352ae0[0] = p;
        *(s32*)(p + 0x28) = 0;
    } else {
        *(u8**)((u8*)D_00352ae0[1] + 0x28) = p;
        *(s32*)(p + 0x28) = 0;
        D_00352ae0[1] = p;
    }
    *(s32*)(p + 8) = a1;
    *(s32*)(p + 4) = a2;
    D_00352ae8++;
}
}  // namespace n001dc278

// ---- 001dc2f8 manual (gap: D2 and D1 dtors)
namespace n001dc2f8 {
struct EFF { void* vt; u8 pad4[24]; void* f28; u8 pad32[8]; EFF* next; };
struct EFFLIST {
    EFF* head;
    EFF* tail;
    void Remove(EFF* p) __attribute__((always_inline));
};
inline void EFFLIST::Remove(EFF* p) {
    EFF* prev;
    if (p == head) { head = p->next; prev = 0; }
    else { prev = head; while (prev->next != p) prev = prev->next; prev->next = p->next; }
    if (p == tail) tail = prev;
    p->next = 0;
}
void func_001e2c00(void*) asm("func_001e2c00");
void func_001e6c00(void*) asm("func_001e6c00");
void func_00321c50(void*, void*) asm("func_00321c50");
extern EFFLIST D_00352ae0 asm("D_00352ae0");
extern s32 D_00352ae8 asm("D_00352ae8");
extern u8 D_00352b48[] asm("D_00352b48");
void func_001dc2f8(EFF* o) asm("func_001dc2f8");
void func_001dc2f8(EFF* o) {
    o->vt = D_00352b48;
    if (o->f28) {
        func_001e2c00(o->f28);
        func_001e6c00(o->f28);
    }
    D_00352ae0.Remove(o);
    D_00352ae8--;
}
void func_001dc3b0(u8* o) asm("func_001dc3b0");
void func_001dc3b0(u8* o) {
    *(void**)o = D_00352b48;
    if (*(void**)(o + 28)) {
        func_001e2c00(*(void**)(o + 28));
        func_001e6c00(*(void**)(o + 28));
    }
    func_00321c50(&D_00352ae0, o);
    D_00352ae8--;
}
}  // namespace n001dc2f8

// ---- 001dc418 from src/anon/batch_w44.cpp
namespace n001dc418 {
void func_001e2c00(void*) asm("func_001e2c00");
void func_001e6c00(void*) asm("func_001e6c00");
void func_00321c50(void*, void*) asm("func_00321c50");
void func_001dc4b8(void*) asm("func_001dc4b8");
extern u8 D_00352ae0[] asm("D_00352ae0");
extern s32 D_00352ae8 asm("D_00352ae8");
extern u8 D_00352b48[] asm("D_00352b48");
void func_001dc418(u8* o) asm("func_001dc418");
void func_001dc418(u8* o) {
    *(void**)o = D_00352b48;
    if (*(void**)(o + 28)) {
        func_001e2c00(*(void**)(o + 28));
        func_001e6c00(*(void**)(o + 28));                        
    }
    func_00321c50(D_00352ae0, o);
    D_00352ae8--;
    func_001dc4b8(o);
}
}  // namespace n001dc418

// ---- 001dc488 from src/anon/batch_w8.cpp
namespace n001dc488 {
typedef u32 (*VR3)(void*, u32, u32);
extern void** D_01d5bb00 asm("D_01d5bb00");
u32 func_001dc488(u32 x) asm("func_001dc488");
u32 func_001dc488(u32 x) {
    void** o = D_01d5bb00;
    return ((VR3)(*(void***)o)[0])(o, x, 0);
}
}  // namespace n001dc488

// ---- 001dc4b8 from src/anon/batch_w9.cpp
namespace n001dc4b8 {
extern void* D_01d5bb00 asm("D_01d5bb00");
void func_001dc4b8(u32 a) asm("func_001dc4b8");
void func_001dc4b8(u32 a) {
    void* o = D_01d5bb00;
    (*(void (**)(void*, u32))(*(u8**)o + 4))(o, a);
}
}  // namespace n001dc4b8

// ---- 001dc4e8 from src/anon/batch_w61.cpp
namespace n001dc4e8 {
s32 func_001dc018(u32, u32, void*, void*) asm("func_001dc018");
s32 func_001dc4e8(u8* p, u32 a, u32 b, u32 c) asm("func_001dc4e8");
s32 func_001dc4e8(u8* p, u32 a, u32 b, u32 c) {
    s32 r = 0;
    if (func_001dc018(a, b, p + 20, p + 24)) {
        *(u32*)(p + 16) = c;
        r = 1;
    }
    return r;
}
}  // namespace n001dc4e8

// ---- 001dc540 from src/anon/tiny_auto80.cpp
namespace n001dc540 {
u32 func_001dc540(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001dc540jjjj");
u32 func_001dc540(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = *(volatile u32*)((u32)r5 + (s32)(0));
    r2 = (u32)((s32)0u + (1));
    *(volatile u32*)((u32)r4 + (s32)(16)) = r7;
    *(volatile u32*)((u32)r4 + (s32)(20)) = r15;
    *(volatile u32*)((u32)r4 + (s32)(24)) = r6;
    return r2;
}
}  // namespace n001dc540

// ---- 001dc558 from src/anon/batch_w52.cpp
namespace n001dc558 {
u32 func_001e6b90(void) asm("func_001e6b90");
u32 func_001e6c40(u32, u32, u32, u32, f32) asm("func_001e6c40");
void func_001e2c00(u32) asm("func_001e2c00");
void func_001e6c00(u32) asm("func_001e6c00");
s32 func_001dc558(u32* p, f32 f) asm("func_001dc558");
s32 func_001dc558(u32* p, f32 f) {
    s32 ok = 1;
    if (p[1] != 4) {
        p[7] = func_001e6b90();
        ok = func_001e6c40(p[7], p[5], p[6], p[4], f) != 0;
    }
    if (!ok && p[7]) {
        func_001e2c00(p[7]);
        func_001e6c00(p[7]);                        
        p[7] = 0;
    }
    return ok;
}
}  // namespace n001dc558

// ---- 001dc5f0 from src/anon/misc_1.cpp
namespace n001dc5f0 {
s32 func_001dc5f0(void* self) asm("_Z13func_001dc5f0Pv");
s32 func_001dc5f0(void* self) { return (s32)(*(s32*)((char*)self + 20)); }
}  // namespace n001dc5f0

// ---- 001dc5f8 from src/anon/batch_w7.cpp
namespace n001dc5f8 {
void func_001dc9e0(u32) asm("func_001dc9e0");
u32 func_001e6cd0(u32) asm("func_001e6cd0");
u32 effect_pos(u32 self) asm("_ZN3ryj6EFFECT3posEv");
u32 effect_pos(u32 self) {
    func_001dc9e0(self);
    return func_001e6cd0(*(u32*)(self + 28));
}
}  // namespace n001dc5f8

// ---- 001dc620 from src/anon/batch_w8.cpp
namespace n001dc620 {
void func_001dc9e0(void*) asm("func_001dc9e0");
void func_001e6cd8(u32) asm("func_001e6cd8");
void ryj_effect_scale(u8* self) asm("_ZN3ryj6EFFECT5scaleEv");
void ryj_effect_scale(u8* self) {
    func_001dc9e0(self);
    func_001e6cd8(*(u32*)(self + 28));
}
}  // namespace n001dc620

// ---- 001dc648 from src/anon/batch_w9.cpp
namespace n001dc648 {
void func_001dc9e0(void*) asm("func_001dc9e0");
void func_001e6ce8(u32) asm("func_001e6ce8");
void effect_angle(u8* e) asm("_ZN3ryj6EFFECT5angleEv");
void effect_angle(u8* e) {
    func_001dc9e0(e);
    func_001e6ce8(*(u32*)(e + 28));
}
}  // namespace n001dc648

// ---- 001dc670 from src/anon/batch_w10.cpp
namespace n001dc670 {
void func_001dc9e0(void*) asm("func_001dc9e0");
void func_001e6cf8(void*) asm("func_001e6cf8");
void EFFECT_color(void*) asm("_ZN3ryj6EFFECT5colorEv");
void EFFECT_color(void* e) {
    func_001dc9e0(e);
    func_001e6cf8(*(void**)((u8*)e + 28));
}
}  // namespace n001dc670

// ---- 001dc698 from src/anon/tiny_auto80_queue.cpp
namespace n001dc698 {
void func_001dc698(u8* a0, u32 a1) asm("_Z13func_001dc698Phj");
void func_001dc698(u8* a0, u32 a1) {
    a1 &= 0xFF;
    if (a1 != 0) {
        u32 t15 = *(u32*)(a0 + 8);
        t15 |= 0x00200000;
        *(u32*)(a0 + 8) = t15;
        return;
    }
    u32 t14 = *(u32*)(a0 + 8);
    t14 &= 0xFFDFFFFF;
    *(u32*)(a0 + 8) = t14;
}
}  // namespace n001dc698

// ---- 001dc6d0 manual (gap: toggle bit 0x200000)
namespace n001dc6d0 {
void func_001dc6d0(u8* o) asm("func_001dc6d0");
void func_001dc6d0(u8* o) {
    u32 v = *(u32*)(o + 8);
    if (v & 0x200000) *(u32*)(o + 8) = v & ~0x200000;
    else *(u32*)(o + 8) = v | 0x200000;
}
}  // namespace n001dc6d0

// ---- 001dc700 from src/anon/tiny_auto80_queue.cpp
namespace n001dc700 {
void func_001dc700(u8* a0, u32 a1) asm("_Z13func_001dc700Phj");
void func_001dc700(u8* a0, u32 a1) {
    a1 &= 0xFF;
    if (a1 != 0) {
        u32 t15 = *(u32*)(a0 + 8);
        t15 |= 0x00400000;
        *(u32*)(a0 + 8) = t15;
        return;
    }
    u32 t14 = *(u32*)(a0 + 8);
    t14 &= 0xFFBFFFFF;
    *(u32*)(a0 + 8) = t14;
}
}  // namespace n001dc700

// ---- 001dc738 from src/anon/batch_w32.cpp
namespace n001dc738 {
extern u32 D_0034f240 asm("D_0034f240");
bool func_001dc738(u32* p) asm("func_001dc738");
bool func_001dc738(u32* p) {                     
    u32 fl = p[2];
    return (fl & 0x400000) || ((D_0034f240 & 0x20) && p[1] != 3) || (bool)(((s32)fl >> 26) & 1);
}
}  // namespace n001dc738

// ---- 001dc790 from src/anon/batch_w33.cpp
namespace n001dc790 {
s32 func_001dc738(void*) asm("func_001dc738");
s32 func_001dc790(u32* p) asm("func_001dc790");
s32 func_001dc790(u32* p) {
    s32 r = 0;
    if (func_001dc738(p) || (p[2] & 0x200000)) r = 1;
    return r;
}
}  // namespace n001dc790

// ---- 001dc7e8 from src/anon/batch_w10.cpp
namespace n001dc7e8 {
void func_001dc9e0(void*) asm("func_001dc9e0");
s32 func_001e2c78(void*) asm("func_001e2c78");
bool EFFECT_is_loop(void*) asm("_ZN3ryj6EFFECT7is_loopEv");
bool EFFECT_is_loop(void* e) {
    func_001dc9e0(e);
    return func_001e2c78(*(void**)((u8*)e + 28)) != 0;
}
}  // namespace n001dc7e8

// ---- 001dc818 from src/anon/tiny_auto80_solver.cpp
namespace n001dc818 {
u32 func_001dc9e0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_001dc9e0jjjjjjjj");
u32 func_001e2c80(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_001e2c80jjjjjjjj");
u32 func_001dc818(u32 a0) asm("_Z13func_001dc818j");
u32 func_001dc818(u32 a0) {
    u32 s0 = a0;
    ((u32(*)(u32))func_001dc9e0)(a0);
    return ((u32(*)(u32))func_001e2c80)(*(u32*)(s0 + 28));
}
}  // namespace n001dc818

// ---- 001dc840 from src/anon/tiny_auto80_solver.cpp
namespace n001dc840 {
u32 func_001dc9e0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_001dc9e0jjjjjjjj");
u32 func_001e2c80(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_001e2c80jjjjjjjj");
u32 func_001dc840(u32 a0) asm("_Z13func_001dc840j");
u32 func_001dc840(u32 a0) {
    u32 s0 = a0;
    *(u32*)(a0 + 8) |= 1;
    ((u32(*)(u32))func_001dc9e0)(a0);
    return ((u32(*)(u32))func_001e2c80)(*(u32*)(s0 + 28));
}
}  // namespace n001dc840

// ---- 001dc878 from src/anon/batch_w32.cpp
namespace n001dc878 {
void func_001e2c00(void*) asm("func_001e2c00");
void func_001e6c00(void*) asm("func_001e6c00");
void EFFECT_free(u8*) asm("_ZN3ryj6EFFECT4freeEv");
void EFFECT_free(u8* e) {
    *(u32*)(e + 8) |= 0x10000;
    void* h = *(void**)(e + 0x1c);
    if (h) {
        func_001e2c00(h);
        func_001e6c00(*(void**)(e + 0x1c));                        
        *(void**)(e + 0x1c) = 0;
    }
}
}  // namespace n001dc878

// ---- 001dc8c8 from src/anon/auto80_199_queue.cpp
namespace n001dc8c8 {
void func_001dc8c8(u32 a0, f32 a1) asm("_Z13func_001dc8c8jf");
void func_001dc8c8(u32 a0, f32 a1) {
    if (0.0f < a1) {
        f32 f0 = *(f32*)(a0 + 32);
        u32 t7 = *(u32*)(a0 + 8);
        f0 = f0 / a1;
        t7 = t7 | 0x00020000u;
        *(u32*)(a0 + 8) = t7;
        f0 = -f0;
        *(f32*)(a0 + 36) = f0;
        return;
    }
    ((void(*)(u32, f32))func_001dc878)(a0, a1);
}
}  // namespace n001dc8c8

// ---- 001dc920 from src/anon/batch_w34.cpp
namespace n001dc920 {
void EFFECT_kill(void*) asm("_ZN3ryj6EFFECT4killEv");
void func_001e2c00(u32) asm("func_001e2c00");
void func_001e6c00(u32) asm("func_001e6c00");
void EFFECT_kill(void* e) {
    u8* p = (u8*)e;
    *(u32*)(p + 8) |= 0x10001;
    if (*(u32*)(p + 28)) {
        func_001e2c00(*(u32*)(p + 28));
        func_001e6c00(*(u32*)(p + 28));                        
        *(u32*)(p + 28) = 0;
    }
}
}  // namespace n001dc920

// ---- 001dc978 from src/anon/auto80_199_queue.cpp
namespace n001dc978 {
void func_001dc978(u32 a0, f32 a1) asm("_Z13func_001dc978jf");
void func_001dc978(u32 a0, f32 a1) {
    if (0.0f < a1) {
        f32 f0 = *(f32*)(a0 + 32);
        u32 t6 = *(u32*)(a0 + 8);
        u32 t7 = 0x00020000u;
        t7 = t7 | 1u;
        f0 = f0 / a1;
        t6 = t6 | t7;
        *(u32*)(a0 + 8) = t6;
        f0 = -f0;
        *(f32*)(a0 + 36) = f0;
        return;
    }
    func_001dc920(a0);
}
}  // namespace n001dc978

// ---- 001dc9d0 manual
namespace ryj {
u32 EFFECT::is_alive() {
    u32 r2 = (u32)(s32)(*(s16*)((u32)this + (s32)(10)));
    r2 = (u32)(r2 ^ 0x0001u);
    r2 = (u32)(r2 & 0x0001u);
    return r2;
}
}  // namespace ryj

// ---- 001dc9e0 from src/anon/tiny.cpp
namespace n001dc9e0 {
u32 func_001dc9e0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001dc9e0jjjj");
u32 func_001dc9e0(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    return (*(u32*)((u32)a0 + (28)) != 0);
}
}  // namespace n001dc9e0

// ---- 001dc9f0 from src/anon/batch_w12.cpp
namespace n001dc9f0 {
void func_001dc9e0(void*) asm("func_001dc9e0");
s32 func_001e6d08(u32) asm("func_001e6d08");
bool EFFECT_is_waiting(u8*) asm("_ZN3ryj6EFFECT10is_waitingEv");
bool EFFECT_is_waiting(u8* self) {
    func_001dc9e0(self);
    return func_001e6d08(*(u32*)(self + 28)) != 0;
}
}  // namespace n001dc9f0

// ---- 001dca20 from src/anon/tiny_leaf.cpp
namespace n001dca20 {
u32 func_001dca20(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001dca20jjjj");
u32 func_001dca20(u32 a0, u32 a1, u32 a2, u32 a3) {                        
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = *(u32*)((u32)r4 + (s32)(8));
    r2 = (u32)((s32)r2 >> 20);
    r2 = (u32)(r2 & 0x0001u);
    return r2;
}
}  // namespace n001dca20

// ---- 001dca30 from src/anon/tiny_leaf.cpp
namespace n001dca30 {
void func_001dca30(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001dca30jjjj");
void func_001dca30(u32 a0, u32 a1, u32 a2, u32 a3) {                           
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14 = 0u, r15 = 0u;
    r14 = *(u32*)((u32)r4 + (s32)(8));
    r15 = (u32)(0x0004u << 16);
    *(u32*)((u32)r4 + (s32)(48)) = r5;
    r14 = (u32)(r14 | r15);
    *(u32*)((u32)r4 + (s32)(52)) = r6;
    *(u32*)((u32)r4 + (s32)(8)) = r14;
}
}  // namespace n001dca30

// ---- 001dca50 from src/anon/tiny_leaf.cpp
namespace n001dca50 {
void func_001dca50(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001dca50jjjj");
void func_001dca50(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14 = 0u, r15 = 0u;
    r14 = *(u32*)((u32)r4 + (s32)(8));
    r15 = (u32)(0x0008u << 16);
    *(u32*)((u32)r4 + (s32)(48)) = r5;
    r14 = (u32)(r14 | r15);
    *(u32*)((u32)r4 + (s32)(52)) = r6;
    *(u32*)((u32)r4 + (s32)(8)) = r14;
}
}  // namespace n001dca50

// ---- 001dca70 from src/anon/batch_w42.cpp
namespace n001dca70 {
void func_001e7070(u32, u32) asm("func_001e7070");
void func_001e7088(u32, u32) asm("func_001e7088");
void func_001dca70(u8* p) asm("func_001dca70");
void func_001dca70(u8* p)
{
    if (*(u32*)(p + 8) & 0x40000) func_001e7070(*(u32*)(p + 48), *(u32*)(p + 52));
    else func_001e7070(0, 0);
    if (*(u32*)(p + 8) & 0x80000) func_001e7088(*(u32*)(p + 48), *(u32*)(p + 52));
    else func_001e7088(0, 0);
}
}  // namespace n001dca70

// ---- 001dcae0 from src/anon/batch_wcx.cpp
namespace n001dcae0 {
extern f32 D_00349e10 asm("D_00349e10");
f32* func_001dc670(u8*) asm("func_001dc670");
void func_001dc878(u8*) asm("func_001dc878");
void func_001dcae0(u8* p) asm("func_001dcae0");
void func_001dcae0(u8* p)
{
    f32 v = *(f32*)(p + 36);
    if (v != 0.0f) {
        f32 a = *(f32*)(p + 32) + v * D_00349e10;
        *(f32*)(p + 32) = a;
        if (a < 0.0f) { *(f32*)(p + 32) = 0.0f; *(f32*)(p + 36) = 0.0f; }
        if (0.0f < *(f32*)(p + 32)) {
            f32* q = func_001dc670(p);
            q[3] *= *(f32*)(p + 32);
        }
    }
    if ((*(u32*)(p + 8) & 0x20000) && *(f32*)(p + 32) <= 0.0f) func_001dc878(p);
}
}  // namespace n001dcae0

// ---- 001dcb98 from src/anon/batch_w42.cpp
namespace n001dcb98 {
typedef unsigned int u128 __attribute__((mode(TI)));
u128* effect_color(void*) asm("_ZN3ryj6EFFECT5colorEv");
struct E16 { u8 d[16]; ~E16() {} } __attribute__((aligned(16)));
void func_001dcb98(void* fx, u8* rgba) asm("func_001dcb98");
void func_001dcb98(void* fx, u8* rgba)
{
    f32 c[4] __attribute__((aligned(16)));
    for (s32 i = 0; i < 4; i++) c[i] = rgba[i] * 0.0078125f;
    u128* d = effect_color(fx);
    if (d != (u128*)c) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(c) : "$8", "memory");
}
}  // namespace n001dcb98

// ---- 001dcc00 from src/anon/tiny_wrappers_more.cpp
namespace n001dcc00 {
u32 func_001e34e0(u32, u32, u32, u32) asm("_Z13func_001e34e0jjjj");
u32 func_001dcc00(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001dcc00jjjj");
u32 func_001dcc00(u32 a0, u32 a1, u32 a2, u32 a3) {                      
    return func_001e34e0(((u32)(*(u32*)((u32)(a0) + 28u))), a1, a2, a3);
}
}  // namespace n001dcc00

// ---- 001dcc18 from src/anon/tiny_wrappers_more.cpp
namespace n001dcc18 {
u32 func_001e3538(u32, u32, u32, u32) asm("_Z13func_001e3538jjjj");
u32 func_001dcc18(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001dcc18jjjj");
u32 func_001dcc18(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001e3538(((u32)(*(u32*)((u32)(a0) + 28u))), a1, a2, a3);
}
}  // namespace n001dcc18

// ---- 001dcc30 manual
namespace ryj {
void EFFECT::set_no_draw() {
    u32 v = *(u32*)((u32)this + 8);
    v |= (u32)0x800000u;
    *(u32*)((u32)this + 8) = v;
}
}  // namespace ryj

// ---- 001dcc48 from src/anon/tiny_auto80_fptr4.cpp
namespace n001dcc48 {
void func_001dcc48(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001dcc48jjjj");
void func_001dcc48(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14, r15;
    r15 = *(u32*)((u32)r4 + (s32)(8));
    r14 = (u32)(0xff7fu << 16);
    r14 = (u32)(r14 | 0xffffu);
    r15 = (u32)(r15 & r14);
    *(u32*)((u32)r4 + (s32)(8)) = r15;
}
}  // namespace n001dcc48

// ---- 001dcc60 from src/anon/batch_w43.cpp
namespace n001dcc60 {
s32 func_001dcd38(void*) asm("func_001dcd38");
s32 func_001c8ab0(void) asm("func_001c8ab0");
s32 func_001dcc60(u8*) asm("func_001dcc60");
s32 func_001dcc60(u8* p) asm("func_001dcc60");
s32 func_001dcc60(u8* p) {
    s32 r = 0;
    if (func_001dcd38(p) == 1 || func_001c8ab0() != 1) {
        u32 m = *(u32*)(p + 8) & 0x800000;
        r = m == 0;
    }
    return r;
}
}  // namespace n001dcc60

// ---- 001dccc8 from src/anon/batch_w24.cpp
namespace n001dccc8 {
u32 func_001e3468(u32) asm("func_001e3468");
s32 func_00143fc8(void*, u32) asm("func_00143fc8");
extern u8 D_00352b00 asm("D_00352b00");
s32 func_001dccc8(u32* p, u8 flag) asm("func_001dccc8");
s32 func_001dccc8(u32* p, u8 flag) {
    s32 r = 0;
    if (p[2] & 0x1000000) return 0;
    if (flag) r = func_00143fc8(&D_00352b00, func_001e3468(p[7]));
    return r;
}
}  // namespace n001dccc8

// ---- 001dcd20 manual (gap: set bit 0x1000000)
namespace n001dcd20 {
void func_001dcd20(u8* o) asm("func_001dcd20");
void func_001dcd20(u8* o) { *(u32*)(o + 8) |= 0x1000000; }
}  // namespace n001dcd20

// ---- 001dcd38 from src/anon/tiny_auto80_queue.cpp
namespace n001dcd38 {
u32 func_001dcd38(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001dcd38jjjjjjjj");
u32 func_001dcd38(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r15 = *(volatile u32*)((u32)r4 + (s32)(12));
    r2 = 0u;
    if (r15 != 0u) {
        r2 = *(volatile u32*)((u32)r15 + (s32)(24));
    }
    return r2;
}
}  // namespace n001dcd38

// ---- 001dcd50 from src/anon/tiny.cpp
namespace n001dcd50 {
void func_001dcd50(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001dcd50jjjj");
void func_001dcd50(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
}
}  // namespace n001dcd50

// ---- 001dcd58 from src/anon/tiny.cpp
namespace n001dcd58 {
extern u32 D_00352af0 asm("D_00352af0");
void func_001dcd58(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001dcd58jjjj");
void func_001dcd58(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = (u32)((s32)1);
    *(u8*)&D_00352af0 = (u8)v;
}
}  // namespace n001dcd58

// ---- 001dcd68 from src/anon/tiny_jal_tail_wrappers.cpp
namespace n001dcd68 {
u32 func_001e51f0() asm("_Z13func_001e51f0v");
u32 func_001dcd58() asm("_Z13func_001dcd58v");
u32 func_001dcd68(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001dcd68jjjj");
u32 func_001dcd68(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_001e51f0();
    return func_001dcd58();
}
}  // namespace n001dcd68

// ---- 001dcd88 from src/anon/batch_w6.cpp
namespace n001dcd88 {
void func_00168388(u32, void*, void (*)(void), u32) asm("func_00168388");
extern u32 D_00352aec asm("D_00352aec");
extern u8 D_01d5bb40 asm("D_01d5bb40");
void func_001dcd68(void) asm("func_001dcd68");
void func_001dcd88(void) asm("func_001dcd88");
void func_001dcd88(void) {
    func_00168388(D_00352aec, &D_01d5bb40, func_001dcd68, 0);
}
}  // namespace n001dcd88

// ---- 001dcdb8 from src/anon/batch_w1828_nsa.cpp
namespace n001dcdb8 {
struct Obj1dc;
struct Vt1dc { s32 (*f0)(Obj1dc*, s32, s32); };
struct Obj1dc { Vt1dc* vt; };
struct Pair1dc { s32 a; s32 b; };
extern Obj1dc* D_01d5bb00 asm("D_01d5bb00");
extern s32 D_01d5bb04 asm("D_01d5bb04");
extern s32 D_01d5bb08 asm("D_01d5bb08");
extern Pair1dc D_00352ae0 asm("D_00352ae0");
extern s32 D_00352ae8 asm("D_00352ae8");
void func_001e6d38(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1, u32 t2, u32 t3, u32 s0, u32 s1, u32 s2, u64 c,
                   u64 d0, u64 d1, u64 d2, u64 d3, u64 d4, u64 d5) asm("func_001e6d38");
void func_001dcdb8(Obj1dc* o, s32 a, s32 b) asm("func_001dcdb8");
void func_001dcdb8(Obj1dc* o, s32 a, s32 b) {
    D_01d5bb00 = o;
    D_01d5bb04 = o->vt->f0(o, a, 0);
    D_01d5bb08 = D_01d5bb00->vt->f0(D_01d5bb00, b, 0);
    func_001e6d38(D_01d5bb04, a, D_01d5bb08, b, 512, 448, 512, 416, 112, 216, 0, 0x800d8, 0x31000070,
                  0x730000007000ULL, 0x19f000001ff0000ULL, 0x5000d, 0, 1);
    Pair1dc* p = &D_00352ae0;
    p->a = 0;
    p->b = 0;
    D_00352ae8 = 0;
}
}  // namespace n001dcdb8

// ---- 001dced0 from src/anon/batch_w58.cpp
namespace n001dced0 {
struct VObj { void** vt; };
void func_001dcfb0(void) asm("func_001dcfb0");
void func_001dd208(s32) asm("func_001dd208");
extern VObj* D_01d5bb00 asm("D_01d5bb00");
extern u32 D_01d5bb04 asm("D_01d5bb04");
extern u32 D_01d5bb08 asm("D_01d5bb08");
extern u8 D_00352af0 asm("D_00352af0");
void func_001dced0(void) asm("func_001dced0");
void func_001dced0(void) {
    func_001dcfb0();
    if (D_01d5bb04) {
        ((void (*)(void*, u32))D_01d5bb00->vt[1])(D_01d5bb00, D_01d5bb04);
        D_01d5bb04 = 0;
    }
    if (D_01d5bb08) {
        ((void (*)(void*, u32))D_01d5bb00->vt[1])(D_01d5bb00, D_01d5bb08);
        D_01d5bb08 = 0;
    }
    func_001dd208(0);
    D_00352af0 = 0;
}
}  // namespace n001dced0

// ---- 001dcf58 from src/anon/auto80_199_queue.cpp
namespace n001dcf58 {
void func_001dcf58(u32 a0) asm("_Z13func_001dcf58j");
void func_001dcf58(u32 a0) {
    u32 s1 = a0;
    u32 s0;
    u32 t7 = 0x00350000u;
    u32 a0v = *(u32*)(t7 + 10976);
    if (a0v == 0) {
        return;
    }

    while (1) {
        u32 t7 = *(u32*)(a0v + 4);
        s0 = *(u32*)(a0v + 40);
        if (t7 == s1) {
            func_001dc878(a0v);
        }
        if (s0 != 0) {
            a0v = s0;
            continue;
        }
        return;
    }
}
}  // namespace n001dcf58

// ---- 001dcfb0 from src/anon/batch_w13.cpp
namespace n001dcfb0 {
void func_001dc878(void*) asm("func_001dc878");
extern u8* D_00352ae0 asm("D_00352ae0");
void func_001dcfb0(void) asm("func_001dcfb0");
void func_001dcfb0(void) {
    u8* p = D_00352ae0;
    while (p) {
        u8* n = *(u8**)(p + 40);
        func_001dc878(p);
        p = n;
    }
}
}  // namespace n001dcfb0

// ---- 001dcff0 from src/anon/auto80_199_queue.cpp
namespace n001dcff0 {
u32 func_001dcff0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, f32 a5) asm("_Z13func_001dcff0jjjjjf");
u32 func_001dcff0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, f32 a5) {
    f32 f20 = a5;
    u32 s4 = a0;
    u32 s1 = a2;
    u32 s2 = a3;
    u32 s3 = a1;
    u32 s5 = a4;

    u32 s0 = func_001dc488(56);
    func_001dc278(s0, s1, s2);
    func_001dc4e8(s0, s4, s3, s5);
    func_001dc558(s0, f20);
    return s0;
}
}  // namespace n001dcff0

// ---- 001dd098 from src/anon/auto80_199_queue.cpp
namespace n001dd098 {
u32 func_001dd098(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, f32 a5) asm("_Z13func_001dd098jjjjjf");
u32 func_001dd098(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, f32 a5) {
    f32 f20 = a5;
    u32 s4 = a0;
    u32 s1 = a2;
    u32 s2 = a3;
    u32 s3 = a1;
    u32 s5 = a4;

    u32 s0 = func_001dc488(56);
    func_001dc278(s0, s1, s2);
    func_001dc540(s0, s4, s3, s5);
    func_001dc558(s0, f20);
    return s0;
}
}  // namespace n001dd098

// ---- 001dd140 from src/anon/auto80_199_queue.cpp
namespace n001dd140 {
u32 func_001dd140(u32 a0) asm("_Z13func_001dd140j");
u32 func_001dd140(u32 a0) {
    u32 s1 = a0;
    u32 s0 = func_001dc488(56);
    func_001dc278(s0, 1, 4);
    *(u32*)(s0 + 20) = s1;
    func_001dc558(s0, 0.0f);
    return s0;
}
}  // namespace n001dd140

// ---- 001dd198 from src/anon/tiny_wrappers_more.cpp
namespace n001dd198 {
u32 func_001e6d28(u32, u32, u32, u32) asm("_Z13func_001e6d28jjjj");
u32 func_001dd198(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001dd198jjjj");
u32 func_001dd198(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001e6d28(((u32)(a0) & 0xffu), a1, a2, a3);
}
}  // namespace n001dd198

// ---- 001dd1b0 from src/anon/tiny.cpp
namespace n001dd1b0 {
void func_001e7018(void*) asm("_Z13func_001e7018Pv");
void func_001dd1b0(BD_VALUE* bd) asm("_Z13func_001dd1b0P8BD_VALUE");
void func_001dd1b0(BD_VALUE* bd) { func_001e7018(bd); }
}  // namespace n001dd1b0

// ---- 001dd1c8 from src/anon/tiny_wrappers_more.cpp
namespace n001dd1c8 {
u32 func_001e7030(u32, u32, u32, u32) asm("_Z13func_001e7030jjjj");
u32 func_001dd1c8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001dd1c8jjjj");
u32 func_001dd1c8(u32 a0, u32 a1, u32 a2, u32 a3) {                     
    return func_001e7030(((u32)(a0) & 0xffu), ((u32)(a1) & 0xffu), ((u32)(a2) & 0xffu), a3);
}
}  // namespace n001dd1c8

// ---- 001dd1e8 from src/anon/tiny_wrappers_more.cpp
namespace n001dd1e8 {
u32 func_001e7050(u32, u32, u32, u32) asm("_Z13func_001e7050jjjj");
u32 func_001dd1e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001dd1e8jjjj");
u32 func_001dd1e8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001e7050(((u32)(a0) & 0xffu), ((u32)(a1) & 0xffu), a2, a3);
}
}  // namespace n001dd1e8

// ---- 001dd208 from src/anon/tiny_wrappers_more.cpp
namespace n001dd208 {
u32 func_001e70a0(u32, u32, u32, u32) asm("_Z13func_001e70a0jjjj");
u32 func_001dd208(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001dd208jjjj");
u32 func_001dd208(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001e70a0(((u32)(a0) & 0xffu), a1, a2, a3);
}
}  // namespace n001dd208

// ---- 001dd220 manual (gap: effect count, allocator, next/prev in the list)
namespace n001dd220 {
struct EFF { u8 pad[40]; EFF* next; };
extern EFF* D_00352ae0[2] asm("D_00352ae0");
extern s32 D_00352ae8 asm("D_00352ae8");
extern void* D_01d5bb00 asm("D_01d5bb00");
s32 func_001dd220(void) asm("func_001dd220");
s32 func_001dd220(void) { return D_00352ae8; }
void* func_001dd230(void) asm("func_001dd230");
void* func_001dd230(void) { return D_01d5bb00; }
EFF* func_001dd240(EFF* e) asm("func_001dd240");
EFF* func_001dd240(EFF* e) {
    if (!e) e = D_00352ae0[0];
    EFF* h = D_00352ae0[0];
    e = e->next;
    if (!e) e = h;
    return e;
}
// 0x1dd268: the entry before e in the list (count - 1 steps forward, wrapping at the end).
EFF* func_001dd268(EFF* e) asm("func_001dd268");
EFF* func_001dd268(EFF* e) {
    EFF* p;
    if (!e) p = D_00352ae0[0];
    else p = e;
    for (s32 i = 0; i < D_00352ae8 - 1; i++) {
        EFF* h = D_00352ae0[0];
        p = p->next;
        if (!p) p = h;
    }
    return p;
}
}  // namespace n001dd220
