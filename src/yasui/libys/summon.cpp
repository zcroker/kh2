#include "summon.hpp"

// YS::SUMMON (0x1c7f10-0x1c8d80): the summon object (C2/C1 ctor, D2/D1/D0 dtors; its vtable
// D_00351e18 stays retail .data), the summon start / appear / leave threads and the summon
// state: D_01d49960 (the two summon objects), D_01d49968 (mode), D_01d49970 (seen flags).
// The data stays where it is (no definitions here); the static initialiser 0x1c8d40 and its
// _GLOBAL__I_ stub 0x1c8d60 are plain functions, so the retail .ctors entry stays.

struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct Vq {
    f32 x, y, z, w;
    Vq() {}
    Vq(const Vq& o) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
    }
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

extern "C" {
extern u8 D_00351e18[];
extern u8 D_00345c08[];
extern u8 D_0034ebc8[];
extern u8* D_01d49960[2];
extern s32 D_01d49968;
extern u32 D_01d49970[];
extern u8 D_0032bb30[];
extern u32 D_00351214;
extern u8* D_00351e08;
extern u8* D_00352130;
extern u8* D_0034e948;
extern f32 D_00349e10;
extern u32 D_003638d0;
extern u8 D_00351eb8;
extern u8 D_00351ec0;

void func_0010b978(void*);
void func_001e02a0(u8*, u8*);
void func_0010c7f0(void*);
void func_00320fa8(void*);
void func_00105110(void*);
void YS__SHEET__add_drive_time(u32, f32);
u8 func_001d6d00(s32);
void func_001c8d80(void*, s32);
void func_001c8d98(void*, s32);
u8* TASK_MANAGER__create_thread(u32, s32, s32, void*, s32);
void func_001c98f0(f32);
void func_001d9820(u8);
void func_0014c9d8(s32);
void func_0014c9f0(s32);
void func_001bbe38(s32);
void func_001bbe78(s32);
void func_0016c5b8(s32, u32);
void func_0016c640(s32);
s32 func_00242dc8(u32);
u8* func_001d6d88(void);
void func_001d6e08(u8*);
void func_001d4078(u16);
u8* func_001050d8(s32);
u32 func_0016e920(u32);
void func_00188120(u8*, const char*);
void func_001880b0(u8*, const char*);
s32 YS__OBJ__is_exist(u8*);
void func_00102448(u32, s32);
void YS__SACRIFICE__WaitStable(u32);
void func_001c9b90(void);
u32 func_0016a070(u8*);
void func_00198630(void*);
u32 func_001a36e0(s32);
s32 func_001a3570(u32);
u64 func_00312db8(u64, u64);
void func_00102670(u32, u8*);
u8* func_001d6d58(u8);
u8* func_001d14a0(void);
s32 YS__CACHE_BUFF__IsFlushing(void);
void func_00170320(s32);
void func_00170888(s32);
s32 func_0017e6d8(void);
void func_001a1c90(u8*, s32, s32);
const Vq* YS__OBJ__get_pos(u8*);
void func_001dc920(u32);
void func_001dc840(u32);
void func_0014f250(void);
void func_0014f238(void);
s32 func_00197920(void);
void func_0017f488(u8*, s32, f32, f32);
void func_0017f5e0(u8*, s32, s32, f32, f32);
Vq func_001a7888(const Vq*, u32, f32, f32);
void func_0016ace0(u8*, Vq*);
}

extern "C" {
void YS__SUMMON__SUMMON(u8* o, u32 model, void* pos, f32 ang);
s32 func_001c8788(u32 id, u8* o);
void func_001c8710(void);
void func_001c8750(void);
s8 func_001c8c38(void);
void func_001c83f8(u32 th);
void func_001c86e8(void);
void func_001c89a8(u32 t);
void func_001c8a70(void);
}
u32 SUMMON_GetMode(void) asm("_ZN2YS6SUMMON7GetModeEv");
void SUMMON_Read(bool) asm("_ZN2YS6SUMMON4ReadEb");

extern "C" {

// 0x1c7f10 / 0x1c7fb8: C2 / C1 constructors of the summon object.
void func_001c7f10(u8* o, u32 model, void* pos, f32 ang)
{
    func_0010b978(o);
    *(u32*)o = (u32)D_00351e18;
    *(u32*)(o + 1416) |= 0x400000;
    *(u32*)(o + 1896) &= ~0x10;
    s32 i;
    for (i = 0; i < 2; i++) {
        if (!D_01d49960[i]) { D_01d49960[i] = o; break; }
    }
    if (i > 0) func_001e02a0(o + 128, D_01d49960[0] + 128);
    *(s32*)(o + 152) = 1;
    func_0010c7f0(o);
}

void YS__SUMMON__SUMMON(u8* o, u32 model, void* pos, f32 ang)
{
    func_0010b978(o);
    *(u32*)o = (u32)D_00351e18;
    *(u32*)(o + 1416) |= 0x400000;
    *(u32*)(o + 1896) &= ~0x10;
    s32 i;
    for (i = 0; i < 2; i++) {
        if (!D_01d49960[i]) { D_01d49960[i] = o; break; }
    }
    if (i > 0) func_001e02a0(o + 128, D_01d49960[0] + 128);
    *(s32*)(o + 152) = 1;
    func_0010c7f0(o);
}

}  // extern "C"

// Destructor chain: summon object -> 0x345c08 class (6 vectors at +3184) -> 0x34ebc8 base.
struct SumBase0 { u32 vt; };
struct SumBase1 : SumBase0 {
    ~SumBase1() { *(u32*)this = (u32)D_0034ebc8; func_00320fa8(this); }
};
struct SumVec { u8 d[16]; ~SumVec() {} };
struct SumBase2 : SumBase1 {
    u8 pad[3180];
    SumVec arr[6];
    ~SumBase2() { *(u32*)this = (u32)D_00345c08; }
};
struct SumObj : SumBase2 {
    __attribute__((always_inline)) ~SumObj()
    {
        s32 i, n;
        *(u32*)this = (u32)D_00351e18;
        n = 0;
        for (i = 0; i < 2; i++) {
            if (D_01d49960[i]) {
                if (D_01d49960[i] == (u8*)this) D_01d49960[i] = 0;
                else n++;
            }
        }
        if (n == 0) D_01d49968 = 0;
    }
};

extern "C" {

// 0x1c8060 / 0x1c8118 / 0x1c81d0: D2 / D1 / D0 destructors.
void func_001c8060(SumObj* p)
{
    p->~SumObj();
}

void func_001c8118(SumObj* p)
{
    p->~SumObj();
}

void func_001c81d0(SumObj* p)
{
    p->~SumObj();
    func_00105110(p);
}

u32 func_001c8290(u8* a0, s32 a1)
{
    if (a1 < 0) {
        f32 f1 = (f32)a1;
        u8* obj = *(u8**)(a0 + 1164);
        f32 f12 = *(f32*)(D_00352130 + 104);
        f32 f0 = (f32)*(s32*)(obj + 4);
        f12 = f12 * f1;
        f12 = f12 / f0;
        YS__SHEET__add_drive_time(*(u32*)(D_0034e948 + 1164), f12);
    }
    return *(u32*)(*(u8**)(a0 + 1164) + 4);
}

// 0x1c8300: start a summon (id), runs the appear thread 0x1c83f8.
void func_001c8300(u8* o, s32 id)
{
    u8 v = func_001d6d00(id);
    func_001c8d80(&D_00351eb8, 0);
    D_0032bb30[13605] = v;
    D_01d49968 = 2;
    if (id != 89) {
        if (id == 306) D_0032bb30[13607] = 1;
    } else {
        D_0032bb30[13607] = func_001c8c38();
    }
    *(u32*)(o + 264) |= 0x104;
    u8* t = TASK_MANAGER__create_thread(D_00351214, 0, 3, (void*)func_001c83f8, 0x2000);
    D_00351e08 = t;
    *(u8**)(t + 48) = (u8*)func_001c86e8;
    func_001c98f0(15.0f);
    func_001c8710();
    func_001d9820(v);
}

// 0x1c83f8: summon appear thread.
void func_001c83f8(u32 th)
{
    u8 id = D_0032bb30[13605];
    u8* e = func_001d6d58(id);
    u8* pl = func_001d14a0();
    s32 first = func_001c8788(id, pl);
    f32 t;
    if (first) t = *(f32*)(D_00352130 + 132);
    else t = *(f32*)(D_00352130 + 136);
    while (YS__CACHE_BUFF__IsFlushing()) {
        t -= D_00349e10;
        func_00102448(th, 0);
    }
    func_00170320(5000);
    SUMMON_Read(false);
    func_00170888(0);
    while (YS__CACHE_BUFF__IsFlushing() || 0.0f < t || func_0017e6d8()) {
        t -= D_00349e10;
        func_00102448(th, 0);
    }
    *(u32*)(pl + 264) |= 1;
    func_001a1c90(*(u8**)(pl + 1164), 3, D_0032bb30[13606]);
    Vq pos = *YS__OBJ__get_pos(D_0034e948);
    u8* o = func_001050d8(3328);
    YS__SUMMON__SUMMON(o, func_0016e920(*(u32*)(e + 4)), &pos, 0.0f);
    if (first) {
        func_001dc920(*(u32*)(pl + 2920));
        *(u32*)(pl + 2920) = 0;
        func_00188120(o + 768, "appear");
        D_01d49968 = 1;
        func_0014f250();
        while (func_00197920()) func_00102448(th, 0);
        func_0014f238();
    } else {
        func_001dc840(*(u32*)(pl + 2920));
        *(u32*)(pl + 2920) = 0;
        func_0017f488(pl + 320, 130, 0.0f, 0.0f);
        func_0017f5e0(pl + 320, 0, 0, 0.0f, 0.0f);
        pos = func_001a7888(&pos, 0x10000, 200.0f, 300.0f);
        func_0016ace0(o, &pos);
        func_00188120(o + 768, "appear_skip");
    }
    D_01d49968 = 2;
    *(u32*)(pl + 264) &= ~1;
    *(u32*)(pl + 264) &= ~0x100;
    *(u32*)(pl + 264) &= ~4;
    for (s32 i = 0; i < 2; i++) {
        if (D_01d49960[i]) *(u32*)(D_01d49960[i] + 264) &= ~1;
    }
}

// 0x1c86e8: end hook of the appear thread.
void func_001c86e8(void)
{
    func_001c8750();
    D_00351e08 = 0;
}

void func_001c8710(void)
{
    func_001c8d80(&D_00351ec0, 3);
    func_0014c9d8(16);
    func_001bbe38(1);
    func_0016c5b8(2, 0xfff7ffdc);
}

void func_001c8750(void)
{
    func_001c8d98(&D_00351ec0, 3);
    func_0014c9f0(16);
    func_001bbe78(1);
    func_0016c640(2);
}

s32 func_001c8788(u32 id, u8* o)
{
    if (*(u32*)(o + 2064)) return 0;
    s32 r = 0;
    switch (func_00242dc8(id)) {
    case 1: r = 1; break;
    case 2: r = (D_01d49970[id >> 5] & (1 << (id & 31))) == 0; break;
    }
    if (r) D_01d49970[id >> 5] |= 1 << (id & 31);
    return r;
}

}  // extern "C"

void SUMMON_Read(bool lock)
{
    u8* s = func_001d6d88();
    if (s != 0) {
        func_001d6e08(s);
        func_001d4078(*(u16*)(s + 12));
        if (lock) func_001c8d80(&D_00351eb8, 0);
    }
}

extern "C" {

u8* YS__SUMMON__Appear(V4* pos, f32 ang)
{
    u8* e = func_001d6d88();
    if (D_01d49960[0]) return 0;
    D_01d49968 = 2;
    u8* o = func_001050d8(3328);
    YS__SUMMON__SUMMON(o, func_0016e920(*(u32*)(e + 4)), pos, ang);
    func_00188120(o + 768, "appear_area_start");
    return o;
}

}  // extern "C"

void ctarget_001c8948(u32, u32, u32, u32) asm("_Z16ctarget_001c8948jjjj");
void ctarget_001c8948(u32, u32, u32, u32)
{
    if (SUMMON_GetMode()) {
        D_01d49968 = 3;
        D_0032bb30[13605] = 0;
        u8* t = TASK_MANAGER__create_thread(D_00351214, 0, 3, (void*)func_001c89a8, 8192);
        *(void**)(t + 48) = (void*)func_001c8a70;
    }
}

extern "C" {

// 0x1c89a8: summon leave thread.
void func_001c89a8(u32 t)
{
    if (YS__OBJ__is_exist(D_01d49960[0])) {
        s32 i;
        func_001880b0(D_01d49960[0] + 768, "leave");
        for (i = 0; i < 2; i++) {
            while (D_01d49960[i]) func_00102448(t, 0);
        }
    }
    func_00102448(t, 2);
    YS__SACRIFICE__WaitStable(t);
    func_001c9b90();
}

// 0x1c8a70: end hook of the leave thread.
void func_001c8a70(void)
{
    func_001c8d98(&D_00351eb8, 0);
}

void func_001c8a90(void)
{
    D_01d49960[0] = 0;
    D_01d49960[1] = 0;
    D_01d49968 = 0;
}

}  // extern "C"

u32 SUMMON_GetMode(void)
{
    return D_01d49968;
}

extern "C" {

// 0x1c8ac0: last slot of the summon object's vtable.
u32 func_001c8ac0(void)
{
    return 0;
}

// 0x1c8ac8: clear the seen flags.
void func_001c8ac8(void)
{
    D_01d49970[0] = 0;
}

}  // extern "C"

u32 SUMMON_GetCurrent(void) asm("_ZN2YS6SUMMON10GetCurrentEv");
u32 SUMMON_GetCurrent(void)
{
    if (SUMMON_GetMode() != 0) {
        if (YS__OBJ__is_exist(D_01d49960[0]) != 0) return func_0016a070(D_01d49960[0]);
    }
    return 0;
}

extern "C" void func_001c8b30(void* bd) { func_00198630(bd); }

namespace YS {

u8 SUMMON::IsTinkExist()
{
    u8 r = 0;
    u32 id = func_001d6d00(306);
    if (SUMMON_GetMode() && D_0032bb30[13605] == id) r = D_0032bb30[13607] != 0;
    return r;
}

void SUMMON::LeaveTink()
{
    D_0032bb30[13607] = 0;
}

s32 SUMMON::MakeGenieFormList(char* list)
{
    s32 n = 0;
    for (s32 i = 1; i < 6; i++) {
        if (i != 3 && func_001a3570(func_001a36e0(i)) > 0) list[n++] = (char)i;
    }
    return n;
}

}  // namespace YS

extern "C" {

s8 func_001c8c38(void)
{
    s8 buf[16];
    s32 n = YS::SUMMON::MakeGenieFormList((char*)buf);
    u32 seed = D_003638d0 * 69069;
    D_003638d0 = seed;
    u64 step = func_00312db8((u64)(u32)(n - 1) + 0x100000000ULL, (u32)n);
    return buf[(s32)func_00312db8(seed, step)];
}

static const u16 s_tink_msg[] = { 0x217, 0x218, 0, 0x219, 0x21a };

u32 func_001c8cc0(u32 i)
{
    return s_tink_msg[i - 1];
}

u32 func_001c8cd8(void)
{
    return func_001c8cc0(D_0032bb30[13607]);
}

void func_001c8cf8(u32 v)
{
    D_0032bb30[13607] = v;
}

void func_001c8d08(void)
{
    u8* t = D_00351e08;
    if (t) func_00102670(D_00351214, t);
}

}  // extern "C"

// 0x1c8d40: static initialiser (clears the seen flags) and its _GLOBAL__I_ stub 0x1c8d60.
void w1c8d40(u32 a, u32 b, u32, u32) asm("_Z16wtarget_001c8d40jjjj");
void w1c8d40(u32 a, u32 b, u32, u32)
{
    if (b == 0xffff && a == 1) D_01d49970[0] = 0;
}

u32 w1c8d40_r(u32, u32, u32, u32) asm("_Z16wtarget_001c8d40jjjj");
extern "C" u32 func_001c8d60(u32 a0, u32 a1, u32 a2, u32 a3)
{
    return w1c8d40_r(1, 0xffff, a2, a3);
}
