// Linked unit 0x2c53c8-0x2c6120: the worldmap object file that holds the task starter
// 0x2c5418, two world-object classes (vtables 0x361c40 / 0x361ca0, kept as retail data),
// their factory 0x2c5710 and worldmap::Player (vtable 0x361d00). The file ends with the
// empty __tcf_0 (0x2c6118) of the local static vector in 0x2c5dc0.
// Bodies come from the old split files named above each function. Every callee and global
// is bound by asm label, one namespace per old file, so prototypes from different old files
// do not clash.
#include "../common/types.h"

// 002c53c8 (gap, never written): task callback started by 0x2c5418.
namespace n002c53c8 {
struct VT53c8 { void (*f0)(void*); };
struct M53c8 { VT53c8* vt; };
void clearDrawFrameDisable() asm("_ZN2dk21clearDrawFrameDisableEv");
void storeImage() asm("_ZN2dk10storeImageEv");
void func_001041f0(u32) asm("func_001041f0");
M53c8* getGumiMenuMode() asm("_Z15getGumiMenuModev");
void func_001024a8(u8*) asm("func_001024a8");
void func_002c53c8(u8* t) asm("func_002c53c8");
void func_002c53c8(u8* t) {
    clearDrawFrameDisable();
    storeImage();
    func_001041f0(*(u32*)(t + 4));
    M53c8* m = getGumiMenuMode();
    m->vt->f0(m);
    func_001024a8(t);
}
}  // namespace n002c53c8

// 002c5418 (from src/anon/batch_w60.cpp)
namespace n002c5418 {
extern u32 D_0032b96c asm("D_0032b96c");
u8* func_00102788(u32, s32, u32, void (*)()) asm("_ZN12TASK_MANAGER11create_taskEiiPFvP4TASKE");
void func_002c53c8() asm("func_002c53c8");
void func_002c5418(u32 x) asm("func_002c5418");
void func_002c5418(u32 x) {
    *(u32*)(func_00102788(D_0032b96c, 0, 0x493e0, func_002c53c8) + 4) = x;
}
}  // namespace n002c5418

// 002c5460 (from src/anon/batch_w4.cpp)
namespace n002c5460 {
void AREA__MapJump(u32, u32, u32, u32, u32) asm("AREA__MapJump");
void func_002c5460(u32 a) asm("func_002c5460");
void func_002c5460(u32 a) {
    AREA__MapJump(a, 1, 0, 0, 0);
}
}  // namespace n002c5460

// 002c5488 (gap, C2 copy of 002c54c8) and 002c54c8 (from src/anon/tiny_auto80_solver.cpp)
namespace n002c54c8 {
extern u8 D_00361c40 asm("D_00361c40");
u32 func_002c5508(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_002c5508");
u32 func_002c5488(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_002c5488");
u32 func_002c5488(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15, r16;
    r7 = r6;
    r6 = (u32)((s32)0u + (5));
    r8 = (u32)((s32)0u + (3));
    r16 = r4;
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_002c5508)(r4, r5, r6, r7, r8, r9, r10, r11);
    r15 = (u32)&D_00361c40;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
u32 func_002c54c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_002c54c8");
u32 func_002c54c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15, r16;
    r7 = r6;
    r6 = (u32)((s32)0u + (5));
    r8 = (u32)((s32)0u + (3));
    r16 = r4;
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_002c5508)(r4, r5, r6, r7, r8, r9, r10, r11);
    r15 = (u32)&D_00361c40;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n002c54c8

// 002c5508 / 002c5558 (C2/C1, from src/anon/tiny_auto80_solver.cpp)
namespace n002c5508 {
extern u8 D_00361ca0 asm("D_00361ca0");
u32 func_001980d0(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_001980d0");
u32 func_002c5508(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_002c5508");
u32 func_002c5508(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 s0 = a0;
    u32 s1 = a4;
    u32 ret = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_001980d0)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 flags = *(u32*)(s0 + 268);
    u32 vt = (u32)&D_00361ca0;
    *(u32*)(s0 + 2548) = s1;
    flags |= 0x200;
    *(u32*)s0 = vt;
    *(u32*)(s0 + 268) = flags;
    *(u32*)(s0 + 2552) = 0;
    return ret;
}
u32 func_002c5558(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_002c5558");
u32 func_002c5558(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 s0 = a0;
    u32 s1 = a4;
    u32 ret = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_001980d0)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 flags = *(u32*)(s0 + 268);
    u32 vt = (u32)&D_00361ca0;
    *(u32*)(s0 + 2548) = s1;
    flags |= 0x200;
    *(u32*)s0 = vt;
    *(u32*)(s0 + 268) = flags;
    *(u32*)(s0 + 2552) = 0;
    return ret;
}
}  // namespace n002c5508

// 002c55a8 (gap): getter of the word at +2548.
namespace n002c55a8 {
u32 func_002c55a8(u8* p) asm("func_002c55a8");
u32 func_002c55a8(u8* p) {
    return *(u32*)(p + 2548);
}
}  // namespace n002c55a8

// 002c55b0 (from src/anon/tiny_auto80_queue.cpp)
namespace n002c55b0 {
u32 func_001dc9e0(...) asm("_ZN3ryj6EFFECT9is_activeEv");
u32 YS__OBJ___OVR_pre_exec(...) asm("YS__OBJ___OVR_pre_exec");
void dk__WM_OBJ___OVR_pre_exec(u32 a0) asm("dk__WM_OBJ___OVR_pre_exec");
void dk__WM_OBJ___OVR_pre_exec(u32 a0) {
    u32 v = *(u32*)(a0 + 2552);
    if (v != 0) {
        if (func_001dc9e0(v) == 0) {
            *(u32*)(a0 + 2552) = 0;
        }
    }
    YS__OBJ___OVR_pre_exec(a0);
}
}  // namespace n002c55b0

// 002c55f0 (from src/anon/tiny_wrappers_more.cpp)
namespace n002c55f0 {
u32 func_00198690(u32, u32, u32, u32) asm("_Z16wtarget_00198690jjjj");
u32 func_002c55f0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002c55f0");
u32 func_002c55f0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00198690(a0, a1, a2, a3);
}
}  // namespace n002c55f0

// 002c5608 (from src/anon/tiny_leaf.cpp)
namespace n002c5608 {
void func_002c5608(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002c5608");
void func_002c5608(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14 = 0u, r15 = 0u;
    r15 = *(u32*)((u32)r4 + (s32)(264));
    r14 = *(u32*)((u32)r4 + (s32)(268));
    r15 = (u32)(r15 | 0x0042u);
    r14 = (u32)(r14 | 0x0100u);
    *(u32*)((u32)r4 + (s32)(264)) = r15;
    *(u32*)((u32)r4 + (s32)(268)) = r14;
}
}  // namespace n002c5608

// 002c5628 (from src/anon/auto200_999.cpp)
namespace n002c5628 {
void func_002c5628(u32 a0) asm("func_002c5628");
void func_002c5628(u32 a0) {
    u32 v1 = *(u32 *)(a0 + 264);
    u32 v2 = *(u32 *)(a0 + 268);
    v1 &= 0xfffffffdu;
    v1 &= 0xffffffbfu;
    v2 &= 0xfffffeffu;
    *(u32 *)(a0 + 264) = v1;
    *(u32 *)(a0 + 268) = v2;
}
}  // namespace n002c5628

// 002c5658 (from src/anon/batch_w38.cpp)
namespace n002c5658 {
void func_001dc978(void*, f32) asm("_ZN3ryj6EFFECT12fadeout_killEf");
void* ryj__PAX__start(u32, u32, s32, s32, s32, void*) asm("ryj__PAX__start");
void func_002c5658(u8* p, u32 a, u32 b) asm("func_002c5658");
void func_002c5658(u8* p, u32 a, u32 b) {
    if (*(void**)(p + 2552)) func_001dc978(*(void**)(p + 2552), 10.0f);
    *(void**)(p + 2552) = ryj__PAX__start(a, b, 0, 1, 0x9c41, p);
}
}  // namespace n002c5658

// 002c56d0 (from src/anon/tiny_auto80_queue.cpp)
namespace n002c56d0 {
u32 func_001984b8(...) asm("func_001984b8");
u32 func_001dc920(...) asm("_ZN3ryj6EFFECT4killEv");
u32 dk__WM_OBJ___OVR__destroy(u32 a0) asm("dk__WM_OBJ___OVR__destroy");
u32 dk__WM_OBJ___OVR__destroy(u32 a0) {
    u32 r4 = a0, r2, r15, r16;
    r16 = r4;
    r15 = *(u32*)((u32)r4 + (s32)(2552));
    r4 = r15;
    if (r15 != 0u) {
        r2 = ((u32(*)(u32))func_001dc920)(r4);
        *(u32*)((u32)r16 + (s32)(2552)) = 0u;
    }
    r4 = r16;
    return ((u32(*)(u32))func_001984b8)(r4);
}
}  // namespace n002c56d0

// 002c5710 (gap): factory for the two object classes, by the entry's type byte.
// The classes are real here only for the new-expressions: their C1 constructors are
// 0x2cb3f8 and 0x2c54c8 (equated below), operator new is AREA::Alloc.
namespace n002c5710 {
u8* AREA_Alloc(u32) asm("_ZN4AREA5AllocEj");
struct WObj3 {
    WObj3(u8*, u32, f32);
    static void* operator new(unsigned int s) { return AREA_Alloc(s); }
    u8 pad[2560];
};
struct WObj1 {
    WObj1(u8*, u32, f32);
    static void* operator new(unsigned int s) { return AREA_Alloc(s); }
    u8 pad[2560];
};
asm("_ZN9n002c57105WObj3C1EPhjf = func_002c54c8");
asm("_ZN9n002c57105WObj1C1EPhjf = func_002cb3f8");
u8* func_002c5710(u8* e, u32 a, f32 f) asm("func_002c5710");
u8* func_002c5710(u8* e, u32 a, f32 f) {
    u8* r = 0;
    switch (e[5]) {
    case 0: break;
    case 1: r = (u8*)new WObj1(e, a, f); break;
    case 2: break;
    case 3: r = (u8*)new WObj3(e, a, f); break;
    }
    return r;
}
}  // namespace n002c5710

// 002c57d8 (gap, C2 copy of 002c5850) and 002c5850 (from src/anon/batch_w43.cpp)
namespace n002c5850 {
void func_00177dc8(void*, u32, s32, u32, u32) asm("func_00177dc8");
extern void* D_00361d00[] asm("D_00361d00");
void YS__FIELD_COMMAND__set_minigame(u32, s32, s32) asm("YS__FIELD_COMMAND__set_minigame");
void func_002c57d8(u8* p, u32 a, u32 b, u32 c) asm("func_002c57d8");
void func_002c57d8(u8* p, u32 a, u32 b, u32 c) {
    func_00177dc8(p, a, 11, b, c);
    *(void***)p = D_00361d00;
    *(u32*)(p + 1416) |= 0x20000000;
    *(u32*)(p + 3012) = 0;
    *(u32*)(p + 3024) = 0;
    *(u32*)(p + 3028) = 0;
    *(u32*)(p + 3032) = 0;
    YS__FIELD_COMMAND__set_minigame(*(u32*)(p + 2884), 0, 0);
    *(u32*)(p + 2748) |= 0x10;
}
void func_002c5850(u8* p, u32 a, u32 b, u32 c) asm("func_002c5850");
void func_002c5850(u8* p, u32 a, u32 b, u32 c) {
    func_00177dc8(p, a, 11, b, c);
    *(void***)p = D_00361d00;
    *(u32*)(p + 1416) |= 0x20000000;
    *(u32*)(p + 3012) = 0;
    *(u32*)(p + 3024) = 0;
    *(u32*)(p + 3028) = 0;
    *(u32*)(p + 3032) = 0;
    YS__FIELD_COMMAND__set_minigame(*(u32*)(p + 2884), 0, 0);
    *(u32*)(p + 2748) |= 0x10;
}
}  // namespace n002c5850

// 002c58c8 (from src/anon/batch_w11.cpp)
namespace n002c58c8 {
void func_001780d8(void*, void*, void*) asm("_ZN2YS6PLAYER15_OVR_initializeEv");
void func_0016bd60(void*, s32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
void func_002c6c60(void*, u32) asm("func_002c6c60");
void ObjCamera_start(u8*, void*, void*) asm("_ZN8worldmap9ObjCamera5startEPNS_6PlayerEPN2YS3PADE");
void ObjCamera_start(u8* self, void* pl, void* pad) {
    func_001780d8(self, pl, pad);
    func_0016bd60(self, 47);
    func_002c6c60(self, *(u32*)(self + 2872));
}
}  // namespace n002c58c8

// 002c5900 (from src/anon/batch_w55.cpp)
namespace n002c5900 {
void func_001bc778(u8*) asm("_ZN2YS12COMMAND_MENU5clearEv");
s32 func_00190140(u8*) asm("_ZNK2YS6TARGET8is_existEv");
u8* YS__COMMAND_MENU__add(u8*, s32, s32, s32) asm("YS__COMMAND_MENU__add");
void func_00178888(u8*) asm("_ZN2YS6PLAYER12_OVR_controlEv");
void func_002c5900(u8* p) asm("func_002c5900");
void func_002c5900(u8* p) {
    u8* s = *(u8**)(p + 2884) + 1196;
    func_001bc778(s);
    u8* r;
    if (func_00190140(*(u8**)(p + 2880) + 4)) r = YS__COMMAND_MENU__add(s, 582, 0, 1);
    else r = YS__COMMAND_MENU__add(s, 583, 0, 1);
    r[6] = 4;
    func_00178888(p);
}
}  // namespace n002c5900

// 002c5980 (gap): vtable slot after 002c5900; picks the target id and calls 002c5a48.
namespace n002c5980 {
void YS__PLAYER___OVR_exec(u8*) asm("YS__PLAYER___OVR_exec");
u8* YS__COMMAND_ELEM__Get(u32) asm("_Z21YS__COMMAND_ELEM__Getjjjj");
void func_002c5a48(u8*, s32) asm("func_002c5a48");
void func_002c5980(u8* p) asm("func_002c5980");
void func_002c5980(u8* p) {
    s32 id = 0;
    YS__PLAYER___OVR_exec(p);
    s32* t = *(s32**)(p + 2880);
    if (t[0] == 2) id = t[1];
    u8* s = *(u8**)(p + 2884) + 2552;
    u8* r = YS__COMMAND_ELEM__Get(*(u16*)(s + 38));
    u16 k = *(u16*)(r + 2);
    if (k == 159 || k == 518) id = **(s32**)(s + 44);
    func_002c5a48(p, id);
}
}  // namespace n002c5980

// 002c5a08 (gap): vtable slot after 002c5980.
namespace n002c5a08 {
void func_001789b8(u8*) asm("_Z16wtarget_001789b8jjjj");
void func_002f1940(u8*) asm("func_002f1940");
u32 func_001849b8(u8*) asm("_ZN2YS3OBJ10get_groundEv");
void worldmap__Player__checkDark(u8*, u32) asm("worldmap__Player__checkDark");
void func_002c5a08(u8* p) asm("func_002c5a08");
void func_002c5a08(u8* p) {
    func_001789b8(p);
    func_002f1940(p + 3024);
    worldmap__Player__checkDark(p, func_001849b8(p));
}
}  // namespace n002c5a08

// 002c5a48 (from src/anon/batch_w1673.cpp)
namespace n002c5a48 {
struct S5a48b { u8 pad[4]; u8 v; };
struct S5a48 { u8 pad[0x588]; s32 a; u32 b; u8 pad2[0xaf8-0x590]; S5a48b* p; };
s32 YS__OBJ__is_exist(S5a48*) asm("YS__OBJ__is_exist");
s32 func_002bfdf8() asm("func_002bfdf8");
s32 func_002c1b48(S5a48*) asm("func_002c1b48");
void func_002c85c8(s32) asm("func_002c85c8");
void func_002c8648() asm("func_002c8648");
void dk__WM_GLANDING_INFO__start(s32) asm("dk__WM_GLANDING_INFO__start");
void func_002ca0a8() asm("func_002ca0a8");
void func_002c5a48(void* self, S5a48* o) asm("func_002c5a48");
void func_002c5a48(void* self, S5a48* o) {
    if (func_002bfdf8() != 0) return;
    s32 s1 = -1;
    s32 s2 = -1;
    if (YS__OBJ__is_exist(o) != 0) {
        if (o->a < 0) {
            s1 = o->p->v;
        } else {
            u32 bb = o->b; if ((u8)(bb & 1)) s2 = func_002c1b48(o);
        }
    }
    if (s1 >= 0) func_002c85c8(s1); else func_002c8648();
    if (s2 >= 0) dk__WM_GLANDING_INFO__start(s2); else func_002ca0a8();
}
}  // namespace n002c5a48

// 002c5b20 (from src/anon/batch_w97.cpp)
namespace n002c5b20 {
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline Vq vsub(const Vq& a, const Vq& b) {
    Vq r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct Quad2c5 { u32 v[4]; };
struct Rec2c5 { u32 a; Quad2c5 b; };
struct Src2c5 { u32 f0; Rec2c5 r; };
struct Obj2c5 { u8 pad[2548]; Rec2c5 r; };
struct Msg2c5 { u16 f0; u16 id; };
void func_002c5dc0(u8*, u8*) asm("func_002c5dc0");
void func_002c5c50(u8*, u8*) asm("func_002c5c50");
void func_0016bd60(u8*, s32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
s32 func_00190140(Rec2c5*) asm("_ZNK2YS6TARGET8is_existEv");
void func_002f1990(u8*) asm("func_002f1990");
Vq func_00190388(const void*) asm("func_00190388");
const Vq* YS__OBJ__get_pos(u32) asm("YS__OBJ__get_pos");
void worldmap__Warp__start(u8*, u8*, Rec2c5*) asm("worldmap__Warp__start");
void func_002c5b20(u8* o, Msg2c5* m) asm("func_002c5b20");
void func_002c5b20(u8* o, Msg2c5* m) {
    switch (m->id) {
    case 518:
        func_002c5dc0(o, *(u8**)(o + 2884) + 12);
        break;
    case 159:
        func_002c5c50(o, *(u8**)(o + 2884) + 12);
        break;
    case 582: {
        Rec2c5* sr = &(*(Src2c5**)(o + 2880))->r;
        ((Obj2c5*)o)->r.a = sr->a;
        ((Obj2c5*)o)->r.b = sr->b;
        Rec2c5* r = &((Obj2c5*)o)->r;
        if (func_00190140(r)) {
            func_002f1990(o + 3024);
            Vq d = vsub(func_00190388(r), *YS__OBJ__get_pos((u32)o));
            worldmap__Warp__start(o + 2928, o, r);
        }
        break;
    }
    case 583:
        func_0016bd60(o, 59);
        break;
    }
}
}  // namespace n002c5b20

// 002c5c50 (from src/anon/batch_w79.cpp)
namespace n002c5c50 {
typedef unsigned int u128 __attribute__((mode(TI)));
struct Q16 {
    u128 v;
    Q16() {}
    Q16(const Q16& o) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
    }
    Q16& operator=(const Q16& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
};
Q16* YS__OBJ__get_pos(void*) asm("YS__OBJ__get_pos");
void func_00178cf8_1(void*) asm("YS__PLAYER__move_stop");
u32 func_0016a020(u32) asm("func_0016a020");
s32 func_002c5d38(void*, u32) asm("func_002c5d38");
void func_002c8648(void) asm("func_002c8648");
void func_002ca0a8(void) asm("func_002ca0a8");
void func_00190388(Q16*, void*) asm("func_00190388");
void func_0016aef0(void*, Q16*) asm("func_0016aef0");
void func_002c5190(void*) asm("func_002c5190");
void func_002c17a0(void) asm("func_002c17a0");
void func_002c5c50(void* a, u32* b) asm("func_002c5c50");
void func_002c5c50(void* a, u32* b) {
    func_00178cf8_1(a);
    if (func_002c5d38(a, func_0016a020(*b)) != 0) {
        func_002c8648();
        func_002ca0a8();
        return;
    }
    {
        Q16 d;
        Q16 t;
        func_00190388(&t, b);
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                     : : "r"(&d), "r"(&t), "r"(YS__OBJ__get_pos(a)) : "memory");
        ((s32*)&d)[1] = 0;
        asm volatile("lqc2 $vf1, 0(%0)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\t"
                     "vaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\t"
                     "vaddq.x $vf2, $vf0, Q\n\tmtc1 $8, $f0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\t"
                     "vmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)"
                     : : "r"(&d) : "$8", "$f0", "memory");
        func_0016aef0(a, &d);
        func_002c5190(b);
        func_002c17a0();
    }
}
}  // namespace n002c5c50

// 002c5d38 (from src/anon/auto80_199_queue.cpp)
namespace n002c5d38 {
u32 func_001b8958(u32) asm("func_001b8958");
void worldmap__Event__Event(u32) asm("worldmap__Event__Event");
u32 func_002c5d38(u32 a0, u32 a1) asm("func_002c5d38");
u32 func_002c5d38(u32 a0, u32 a1) {
    (void)a0;
    u32 s0 = a1;

    if (a1 == 930) {
        if (func_001b8958(1) != 0) {
            if (func_001b8958(2) == 0) {
                worldmap__Event__Event(1837);
                return 1;
            }
        }
    }

    if (s0 != 1110) {
        goto fail;
    }

    if (func_001b8958(53) == 0) {
        goto fail;
    }

    if (func_001b8958(55) != 0) {
        goto fail;
    }

    worldmap__Event__Event(1836);
    return 1;

fail:
    return 0;
}
}  // namespace n002c5d38

// 002c5dc0 (from src/anon/batch_w257.cpp)
namespace n002c5dc0 {
#define QCOPY257(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV257 {
    f32 x, y, z, w;
    QV257() {}
    QV257(const QV257& o) { QCOPY257(this, &o); }
} __attribute__((aligned(16)));
static inline QV257 operator-(const QV257& a, const QV257& b) {
    QV257 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 normalize257(QV257* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline __attribute__((always_inline)) void set4_257(QV257* v, f32 x, f32 y, f32 z, f32 w) { v->x = x; v->y = y; v->z = z; v->w = w; }
// The fixed direction is a real local static (guard 0x1e2bd80, object 0x1e2bd90); its empty
// destructor gives the empty __tcf_0 at 0x2c6118, which gcc places at the end of the file.
struct Dir257 : QV257 {
    Dir257(f32 x_, f32 y_, f32 z_, f32 w_) { set4_257(this, x_, y_, z_, w_); }
    ~Dir257() {}
};
void YS__PLAYER__move_stop(u8*) asm("YS__PLAYER__move_stop");
QV257 func_00190388(u32*) asm("func_00190388");
QV257* YS__OBJ__get_pos(u8*) asm("YS__OBJ__get_pos");
void func_0016aef0(u8*, QV257*) asm("func_0016aef0");
void func_002cb0e8(u32*, QV257*, f32) asm("func_002cb0e8");
u32 func_002c1b48(u32) asm("func_002c1b48");
void func_002cab98(u32) asm("func_002cab98");
void func_002c17a0(void) asm("func_002c17a0");
void func_002c5dc0(u8* a0, u32* a1) asm("func_002c5dc0");
void func_002c5dc0(u8* a0, u32* a1) {
    YS__PLAYER__move_stop(a0);
    QV257 d = func_00190388(a1) - *YS__OBJ__get_pos(a0);
    d.y = 0.0f;
    normalize257(&d);
    func_0016aef0(a0, &d);
    static Dir257 dir(0.0f, 0.0f, 1.0f, 0.0f);
    func_002cb0e8(a1, &dir, 0.0f);
    func_002cab98(func_002c1b48(*a1));
    func_002c17a0();
}
#undef QCOPY257
}  // namespace n002c5dc0

// 002c5ed8 (from src/anon/auto80_199_queue.cpp)
namespace n002c5ed8 {
u32 func_001050d8(...) asm("_ZN4AREA5AllocEj");
u32 func_00167f18(...) asm("func_00167f18");
void func_002c5850(f32, u32, u32, u32, u32) asm("func_002c5850");
u32 func_002c5ed8(u32 a0, u32 a1, f32 a2) asm("func_002c5ed8");
u32 func_002c5ed8(u32 a0, u32 a1, f32 a2) {
    u32 s1 = a0;
    u32 s2 = a1;
    f32 f20 = a2;
    u32 s0 = func_001050d8(3040);
    u32 v0 = func_00167f18(0);
    func_002c5850(f20, s0, s1, v0, s2);
    return s0;
}
}  // namespace n002c5ed8

// 002c5f48 .. 002c5fa0 (from src/anon/tiny_wrappers_more.cpp)
namespace n002c5f48 {
u32 YS_OBJ_ControlOff(u32, u32, u32, u32) asm("_ZN2YS3OBJ10ControlOffEi");
u32 YS_OBJ_ControlOn(u32, u32, u32, u32) asm("_ZN2YS3OBJ9ControlOnEi");
u32 func_002f1900(u32, u32, u32, u32) asm("func_002f1900");
u32 func_002f1a38(u32, u32, u32, u32) asm("func_002f1a38");
u32 func_002c5f48(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002c5f48");
u32 func_002c5f48(u32 a0, u32 a1, u32 a2, u32 a3) {
    return YS_OBJ_ControlOff(0x00000000u, a1, a2, a3);
}
u32 func_002c5f60(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002c5f60");
u32 func_002c5f60(u32 a0, u32 a1, u32 a2, u32 a3) {
    return YS_OBJ_ControlOn(0x00000000u, a1, a2, a3);
}
u32 func_002c5f78(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002c5f78");
u32 func_002c5f78(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)((u32)(a0) + 3024u) = (u32)(0x00000000u);
    return func_002f1900(((u32)(a0) + 3024u), 0x00000002u, a0, a3);
}
u32 func_002c5fa0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002c5fa0");
u32 func_002c5fa0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002f1a38(((u32)(a0) + 3024u), a1, a2, a3);
}
}  // namespace n002c5f48

// 002c5fb8 (from src/anon/batch_w207.cpp)
namespace n002c5fb8 {
void YS__OBJ__get_target_pos(void*) asm("_Z23YS__OBJ__get_target_posjjjj");
u32 func_002c5fb8(f32* a) asm("func_002c5fb8");
u32 func_002c5fb8(f32* a) {
    YS__OBJ__get_target_pos(a);
    a[2] = a[2] + 3500.0f;
    return (u32)a;
}
}  // namespace n002c5fb8

// 002c5ff8 (from src/anon/batch_w35.cpp)
namespace n002c5ff8 {
void func_00143e50(void*, u16, u32) asm("func_00143e50");
void YS__BTLOBJ__set_hitback(void*, void*, f32) asm("YS__BTLOBJ__set_hitback");
void func_002c5ff8(u8* p, u32 a) asm("func_002c5ff8");
void func_002c5ff8(u8* p, u32 a) {
    f32 tmp[4] __attribute__((aligned(16)));
    asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(p + 32) : "memory");
    func_00143e50(tmp, a, 0);
    YS__BTLOBJ__set_hitback(p, tmp, 1000.0f);
}
}  // namespace n002c5ff8

// 002c6050 (from src/anon/batch_wcx.cpp)
namespace n002c6050 {
void func_002f1900(u8*, s32, u8*) asm("func_002f1900");
void func_002f19c8(u8*) asm("func_002f19c8");
void worldmap__Player__checkDark(u8* p, s32 k) asm("worldmap__Player__checkDark");
void worldmap__Player__checkDark(u8* p, s32 k)
{
    switch (k) {
    case 1: func_002f1900(p + 3028, 5, p); func_002f19c8(p + 3032); break;
    case 2: func_002f19c8(p + 3028); func_002f1900(p + 3032, 6, p); break;
    default: {
        for (s32 i = 0; i < 2; i++) func_002f19c8(p + 3028 + i * 4);
    }
    }
}
}  // namespace n002c6050

// 002c60f8 (from src/anon/tiny_jal_wrappers.cpp)
namespace n002c60f8 {
u32 func_001849b8(u32, u32, u32, u32) asm("_ZN2YS3OBJ10get_groundEv");
u32 func_002c60f8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002c60f8");
u32 func_002c60f8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_001849b8(r4, r5, r6, r7);
    r2 = ((u32)0u < (u32)r2);
    return r2;
}
}  // namespace n002c60f8

