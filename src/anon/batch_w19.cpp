#include "../common/types.h"

extern "C" {
void func_00102818(u32, u32, u32, u32, u32);
void func_0016bd60(void*, s32);
void func_00113668(void*);
void func_00105110(void*);
u32 func_001688c8(char*);
void* func_00170b30(u32);
void func_0013f030(void);
void func_0013f048(void);
void* func_0014aba8(void);
void func_0014aa80(void*, s32, s32);
void func_00150dc0(u32, u32, u32, u32, u32, u32);
u8 func_00139d78(void*);
void func_00151c70(void*);
u8 func_00167d68(void*);
void* func_0016f610(const void*, s32);
void* func_00185890(u32, void*);
u32 func_001a8258(u32);
u32 func_001a8418(u32);
u32 func_001a8510(void);
void func_001382b8(u32);
void func_001940f0(void*, s32);
void func_00186740(u32, u32, u32, u32, f32, f32);
void func_001991a8(u32, u32);
u8 func_00239d10(void*);
s32 func_001bb4a0(void);
void* func_001bbcb0(void);
void* func_00168b38(u32, s32, s32);
void func_001980d0(void*, u32, s32, u32);
void func_0021fa10(void*);
void func_00240360(void);
void func_00234590(s32, u32, s32, u32, s32);
void func_0014aa58(void*, s32, s32);
void func_002bd760(s32);
void func_00287cc0(s32);
void func_00287c78(void);
void func_00287c20(void);
s32 func_00276c18(void);
u8* func_00294000(s32);
u8 func_0028acc8(u32);
u8 func_002cff98(void*);
u8 func_002e7328(void*);
void func_002e7670(void*);
void func_002e76b0(void*);
void func_002e77a8(void*);
void func_002ee730(void*);
s32 func_002bc1e8(s32);
u32 func_0010c7e8(u32);
void func_00119830(u32, u32);
void func_00239848(void*);
void func_00106420(void*);
void func_001d48b0(void*);
u8 func_00108698(void*);
u8 func_001ddd10(void*);

extern u32 D_0032ba94;
extern u8 D_00347220[];
extern u32 D_0034a428;
extern u8 D_0034d6c0[];
extern void* D_0034dc98;
extern u32 D_00352768;
extern u32 D_01d5ba68;
extern u8 D_00352908[];
extern s8* D_0035ec94;
extern u32 D_0035ec9c;
extern u32 D_0035ec88;
extern s32 D_0035f2f8;
extern s32 D_0035f2fc;
extern s32 D_0035f304;
extern s32 D_0035f308;
extern s32 D_0035f30c;
extern s32 D_0035f310;
extern s8* D_0035f5d0;
extern void* D_0035f654;
extern u32 D_0035f650;
extern u8 D_00362230[];
extern u8 D_00362428[];
extern u8 D_01e2c088[];
extern u8 D_0034e8a8[];
extern u8 D_00351228[];
struct Trio { s32 a, b, c; };
extern Trio D_01c94090[3];
struct Slot8 { u32 a; s16 b, c; };
extern Slot8 D_01dad9c0[32];

u32 bgse_alloc(char* name, u32& size) asm("_ZN2dk4BGSE5allocEPcRj");
void jumpeffect_outclear(void) asm("_ZN2dk10JumpEffect8outClearEv");
void force_leave_mission_gauge(void* g) asm("_ZN2dk11INFORMATION22forceLeaveMissionGaugeEPNS_13MISSION_GAUGEE");
void* get_weapon_entry(const void* self, s32 i) asm("_ZNK2YS8OBJENTRY16get_weapon_entryEi");
void trap_treasure_get(u32* v) asm("_ZN2YS17trap_treasure_getEP8BD_VALUE");
void trap_stitch_shot_effect(u32* v) asm("_ZN2kn23trap_stitch_shot_effectEP8BD_VALUE");

void func_001045b8(u32 a, u32 b, u32 c, u32 d) {
    func_00102818(D_0032ba94, a, b, c, d);
}

void func_0010f960(u8* p) {
    if (*(s32*)(*(u8**)(p + 12) + 4) == 31) {
        func_0016bd60(p, 32);
        return;
    }
    *(u32*)(p + 0xb7c) |= 0x4000;
}

void func_00115560(void** p) {
    *p = D_00347220;
    func_00113668(p);
    func_00105110(p);
}

u32 bgse_alloc(char* name, u32& size) {
    u32 n = func_001688c8(name);
    size = n;
    return (u32)func_00170b30((n + 2047) & ~2047);
}

void jumpeffect_outclear(void) {
    func_0013f030();
    func_0013f048();
    func_0014aa80(func_0014aba8(), 1, 0);
}

void func_0014f688(u32 a, u32 b, u32 c, u32 d, u32 e) {
    func_00150dc0(D_0034a428, a, b, c, d, e);
}

void force_leave_mission_gauge(void* g) {
    if (func_00139d78(g)) func_00151c70(g);
}

u32 func_00167e70(void) {
    func_00167d68(D_0034d6c0);
    return func_00167d68(D_0034d6c0 + 96);
}

void* get_weapon_entry(const void* self, s32 i) {
    void* e = func_0016f610(self, i);
    if (!e) return 0;
    return func_00185890(*(const u16*)((const u8*)self + 78), e);
}

u32 func_0016fac8(u32 a) {
    void* o = D_0034dc98;
    return (*(u32 (**)(void*, u32, void*))*(u8**)o)(o, a, __builtin_return_address(0));
}

void trap_treasure_get(u32* v) {
    func_001a8418(func_001a8258(*v));
    func_001382b8(func_001a8510());
}

void func_001775f8(void* p) {
    func_001940f0(p, 2);
    func_001940f0(p, 12);
    func_001940f0(p, 22);
}

struct Args18 { u32* a; u32 b, c, d; f32 e, f; };
void func_0018f248(Args18* p) {
    u32 b = p->b;
    func_00186740(p->a[1], b, p->c, p->d, p->e, p->f);
}

void func_0019af98(u8* p) {
    u8* t = *(u8**)(p + 8);
    func_001991a8(*(u32*)(t + 28), *(u16*)(t + 2));
    *(u32*)(p + 4) |= 1;
}

u32 func_001abf00(s32* p) {
    if (*p == 1) return func_00239d10(p + 1);
    return 0;
}

struct Ref0498 { u8* o; u32 x; bool f; };
bool func_001b0498(Ref0498* p) {
    u8* o = p->o;
    if (!o) return false;
    return (u8)(!p->f & 1) || (*(u32*)(o + 352) & 0x4000000) != 0;
}

s32 func_001bbcc0(void) {
    if (func_001bb4a0()) return *(*(u8**)((u8*)func_001bbcb0() + 8) + 14);
    return 1;
}

struct Flags1bc { u16 a : 14; u16 b : 1; u16 c : 1; };
bool func_001bc050(void) {
    if (!func_001bb4a0()) return 0;
    return ((Flags1bc*)(*(u8**)((u8*)func_001bbcb0() + 8) + 4))->b;
}

void func_001d4dc0(u32* p, u32 a, u32 b, u32 c) {
    p[0x238 / 4] = a;
    p[0x18 / 4] = 9999;
    p[0x23c / 4] = b;
    p[0x240 / 4] = c;
    p[0x2c / 4] = 0;
    ((void (*)(u32*))((u32*)p[0])[1])(p);
}

void func_001d5030(u32 a) {
    D_00352768 = a;
    D_01d5ba68 = *(u32*)((u8*)func_00168b38(a, 2, 0) + 8);
}

void func_001d9ef0(u8* p, u32 a, u32 b) {
    func_001980d0(p, a, 10, b);
    *(u32*)(p + 0x9f8) = 0;
    *(u32*)(p + 0x9f4) = 0;
    *(void**)p = D_00352908;
}

void func_001fab08(u8* p, u8* q) {
    u8* s = p + **(s32**)(q + 12) + 160;
    func_0021fa10(s);
    s[8] = 4;
}

void func_0023f6c0(u8* p, u32 a) {
    func_00139d78(p);
    *(u32*)(p + 0x48) = a;
}

void func_00240e10(void) {
    func_00240360();
    func_00234590(*D_0035ec94, D_0035ec9c, 99, D_0035ec88, 0);
}

void func_0025cd40(void) {
    func_0014aa58(func_0014aba8(), 15, 0);
    func_002bd760(60);
    func_00287cc0(0);
}

void func_00287b98(void) {
    D_0035f2f8--;
    func_00287c78();
    func_00287c20();
}

void func_00287d68(void) {
    D_0035f2fc = D_0035f2f8;
    D_0035f308 = D_0035f304;
    D_0035f310 = D_0035f30c;
}

s32 func_002a0360(void) {
    s8 c = *D_0035f5d0;
    if (func_00276c18()) return 1;
    return c != 0;
}

u8* func_002a6368(s32 i) {
    u8* b = func_00294000(6) + 16;
    return b + i * 8;
}

u32 func_002b4fb8(void) {
    void* o = D_0035f654;
    u32 v = 0;
    if (o) v = func_00139d78(o);
    if (v) v = func_0028acc8(D_0035f650);
    return v;
}

void func_002d2a58(void** p) {
    *p = D_00362230;
    func_002cff98(p);
    func_00105110(p);
}

u32 func_002d5dd0(u8* p) {
    *(void**)p = D_00362428;
    func_002e7328(p + 0xb38);
    return func_002cff98(p);
}

void func_002e7738(u8* p) {
    func_002e7670(p);
    func_002e76b0(p + 4);
    func_002e77a8(p);
}

// Returns the callee's result when p[2] == 8 (result undefined otherwise, as in the original).
s32 func_002ef1b8(u8* p) {
    s32 r;
    if (p[2] == 8) r = func_002bc1e8(*(u16*)(p + 4) * 1000 + *(u16*)(p + 6));
    return r;
}

void trap_stitch_shot_effect(u32* v) {
    func_00119830(func_0010c7e8(((u32*)v[0])[1]), v[1]);
}

void func_0031e630(void** p) {
    *p = D_0034e8a8;
    func_00239848(p);
    func_00106420(p);
}

void func_00320768(u8* p) {
    *(void**)p = D_00351228;
    func_001d48b0(p + 0x9c0);
    func_00106420(p);
}

u32 func_00322ba8(u8* p) {
    func_00108698(p + 56);
    return func_001ddd10(p + 192);
}

void func_0022d7e8(void) {
    s32 i;
    for (i = 0; i < 32; i++) {
        D_01dad9c0[i].a = 0;
        D_01dad9c0[i].b = -1;
        D_01dad9c0[i].c = -1;
    }
}
}

void wtarget_001afa50(u32, u32, u32, u32) {
    Trio* p;
    for (p = D_01c94090; (s32)p < (s32)(D_01c94090 + 3); p++) {
        p->a = 0;
        p->b = -1;
        p->c = -1;
    }
}

struct KeyVal { u32 k, v; };
// Looks up key in a zero-terminated {key, value} table at (*a)+28.
u32 wtarget_001da420(u32 a, u32 key, u32, u32) {
    KeyVal* e = (KeyVal*)(*(u32*)a + 28);
    for (; e->v; e++)
        if (e->k == key) return e->v;
    return 0;
}

void wtarget_002ee850(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) func_002ee730(D_01e2c088);
}
