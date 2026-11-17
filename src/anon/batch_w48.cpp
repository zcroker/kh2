#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));

struct Vq {
    f32 x, y, z, w;
    Vq() {}
    Vq(const Vq& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

extern "C" {
s32 func_00112c48(void);
f32 func_00112c28(void);
f32 func_00112c38(void);
s32 func_00111e38(s32);
void func_0011ac10(s32);
u8* func_00106a60(s32);  // buffer_get_by_index
void func_0016aef0(s32, f32*);
void func_001391a8(void*, Vq);  // vec_copy_at416_if_diff
s32 func_00139d78(void*);
Vq func_0016af58(u32);
void func_0013fcd8(void*, Vq);
void func_00107368(void*, void*);  // vec_copy_at80_if_diff
void func_00165f70(void*, void*, void*, void*, void*);
extern u8* D_00348800;
extern u32 D_00348810;
extern u8 D_0034881f;

/* wrap a signed index into [0, n) and fetch that slot */
// 00135d00: moved to src/naka/libkn/obj_observer.cpp

void func_0011b038(s32 a);  // 0x0011b038: definition moved into src/anon/unit_0011a660.cpp

void func_0013e3b0(u8* o, Vq* v);  // 0x0013e3b0: definition moved into src/anon/unit_0013dfb8.cpp

void func_0013fd10(u8* o);  // 0x0013fd10: definition moved into src/anon/unit_0013fca8.cpp

void func_00144060(void);  // 0x00144060: definition moved into src/anon/unit_00142c90.cpp

s32 func_00150bc0(void*);
s32 func_00150be0(void*);
void func_00150b68(void*);
extern void* D_0034a42c;
void func_0014f5d0(s32 id) {
    if (!func_00150bc0(D_0034a42c)) return;
    if (id != 0 && func_00150be0(D_0034a42c) != id) return;
    if (!func_00139d78(D_0034a42c)) return;
    func_00150b68(D_0034a42c);
}

extern u8* D_004f3b38;
void func_001604d8(u8*);
static inline u8* next160(u8* p) {
    if (!p) return D_004f3b38;
    return *(u8**)(p + 128);
}
// 00160f10: moved to src/harata/libdk/bgobj.cpp

struct S10 { u8 a; u8 b; s16 c[4]; };
extern S10 D_0032bae0;
extern S10 D_0032bb10;
void func_0019ee80(s32, s32);
void func_001d5198(S10*);
// 00178220: moved to src/yasui/libys/player.cpp

struct E1817 { s32 id; s32 a; s32 b; };
extern E1817 D_0036c710[14];
// 001817f0: moved to src/yasui/libys/progress.cpp

s32 func_001c0cd8(void*);
s32 func_0019c090(void*);  // obj_is_enabled
// 001886d0: moved to src/anon/unit_00188550.cpp
s32 func_001886d0(u8* o);
}

f32* func_001ce328(u32);
u32 func_001ce2d8(u32);
void u_call4_00195858(u32 a0, u32 a1, u32, u32);  // 0x00195858: definition moved into src/anon/unit_00194790.cpp

extern "C" {
void func_0016c750(u32);
void* func_0016d080(u32, s32);
void func_0016cbc8(void*, s32, s32, s32);
void func_0016cd48(void*, s32);
void func_0016cab8(void*);
void func_0016c7d8(void*);
void func_0016c770(void);
extern u32 D_0032b91c;
extern u32 D_01c61b00;
void func_00196198(void);  // 0x00196198: definition moved into src/anon/unit_00195d00.cpp

u8* func_00168b88(void*, s32, s32, s32);  // find_entry16_by_half_word
// 00198738: moved to src/anon/unit_00197fe0.cpp

void func_0018f028(void*);
void func_0019f9a8(u8* o);  // 0x0019f9a8: definition moved into src/anon/unit_0019ee80.cpp

void func_0023acd8(u8*);
void func_0023ade0(u8*);
// 001ac310: moved to src/anon/unit_001abb28.cpp

s32 func_00181550(s32);
s32 func_001b8958(s32);
void func_001b8838(s32);
extern s16 D_0036dbb0[][2];
void func_001b8e00(s32 i);  // 0x001b8e00: definition moved into src/anon/unit_001b87a0.cpp

void func_002ba2e8(s32, s32);
struct Obj1bd5b0 { u8 pad[2240]; u8** p; u8 pad2[2536 - 2244]; u8* q; };
void func_001bd5b0(Obj1bd5b0* o, s32 i, u8 flag);  // 0x001bd5b0: definition moved into src/anon/unit_001bc568.cpp

struct G32bb30 { u8 pad[13606]; u8 n; u8 pad2[14052 - 13607]; s32 total; u8 pad3[8]; u8 pad4[8]; u16 cur[4]; };
extern G32bb30 D_0032bb30;
u8* func_001b8e88(u32);
u16 func_001a67b0(s32);
void func_001bdff0(void);  // 0x001bdff0: definition moved into src/anon/unit_001bc568.cpp

void func_001bc778(void*);
u8* func_001bd570(void*, s32);
void func_001bc780(void*, u32, void*, u32);
void func_001be890(void* o, void* b);  // 0x001be890: definition moved into src/anon/unit_001bc568.cpp

u8* func_001d5b78(s32, s32);
/* sum of the 'count' fields of the first n-1 entries; the nops are the R5900 short-loop padding */
s32 func_001d5d20(void);  // 0x001d5d20: definition moved into src/anon/unit_001d4f40.cpp

extern u8 D_01d9e370[];
extern u8 D_01d9e6f0[];
void sceVu0ApplyMatrix(void*, void*, void*);
u8* func_001e3468(u8* o);  // 0x001e3468: definition moved into src/anon/unit_001e0cb8.cpp



/* wait until VIF0/VIF1/GIF are idle and VU0 has stopped */
void func_001e7538(void);  // 0x001e7538: definition moved into src/anon/unit_001e0cb8.cpp

s32 func_002282f0(s32);
void* func_00227ca8(void*);
void func_001671e8(void*, s32);
void func_00167218(void);


f32 func_002f8ad0(f32, f32);
f32 func_0017ce10(f32);


struct E232 { s32 a; s32 b; s32 c; u8 pad[52]; };
union U232 { E232* p; s32 i; };
extern U232 D_0035dcf8;
/* release the slot owned by id */
void func_00232db0(s32 id) {
    for (s32 i = 0; i < 64; i++) {
        if (D_0035dcf8.p[i].a != -1 && D_0035dcf8.p[i].b == id) {
            D_0035dcf8.p[i].a = -1;
            D_0035dcf8.p[i].b = -1;
            D_0035dcf8.p[i].c = 0;
            return;
        }
    }
}

extern void* D_0035ee0c;
extern u32 D_003723a0[];
void func_0023f5b8(void*, u32, s32);
void func_0024eff8(s32 i) {
    if (!D_0035ee0c) return;
    if (!func_00139d78(D_0035ee0c)) return;
    u32 v = D_003723a0[i];
    func_0023f5b8(D_0035ee0c, v, 0);
}

struct Obj253410 { u8 pad[37]; u8 active : 1; };
u8* func_0014aba8(void);
void func_00258b00(void*, s32);
void* func_002535d0(s32);
void func_00242740(void*);
void func_00253180(s32, s32);
static inline u8 isOff253410(Obj253410* o) { return !o->active; }
void func_00253410(Obj253410* o, s32 a1) {
    if (!isOff253410(o)) *(u32*)(func_0014aba8() + 252) = 0;
    func_00258b00(o, a1);
    func_00242740(func_002535d0(8));
    func_00253180(8, -1);
}

struct E2538 { s32 a; s32 b; s32 c; u8* d; };
extern E2538 D_0035eee0[7];
extern u8 D_01dae6c0[];
extern s32 D_0035ef50;
extern s32 D_0035ef54;
void func_00253888(s32 a) {
    u8* base = D_01dae6c0;
    E2538* e = D_0035eee0;
    s32 r = 0;
    for (s32 i = 6; i >= 0; i--, e++) {
        if (e->d) {
            if (!(e->a < a)) {
                if (e->a == a) r = e->d - base;
                e->a = 0;
                e->b = 0;
                e->d = 0;
                e->c = 0;
            }
        }
    }
    D_0035ef50 = r;
    D_0035ef54 = a;
}
}

extern "C" {
s32 GetMode287bc0(void) asm("_ZN2Tz8MenuBase7GetModeEv");
void* func_00256b68(s32);
void func_0028dac8(void*, s32);
s32 func_0028be58(void*);
void func_0028bdb8(void*);
extern void* D_0035f04c;
void FadeOutCategory2621a0(void) asm("_ZN2Tz6CmItem15FadeOutCategoryEv");
void FadeOutCategory2621a0(void);  // 0x002621a0: definition moved into src/anon/unit_0025f6b8.cpp

extern u8* D_0035f20c;
s32 func_00192048(s32);
struct S275 { u8 pad[408]; s32 v; };
static inline S275* sub275() { return (S275*)(D_0035f20c + 1308); }
void func_00275f08(s32 i);  // 0x00275f08: definition moved into src/anon/unit_002748a0.cpp

u8* func_00294000(s32);
u8 func_002941d8(u8*);
s32 func_00294208(s32 id);  // 0x00294208: definition moved into src/anon/unit_00292e60.cpp

struct E2953 { s8 id; u8 pad[15]; };
E2953* func_002953c8(s32 id);  // 0x002953c8: definition moved into src/anon/unit_00292e60.cpp

void func_0029fcb0(void*);
void func_002a03d0(void);
s32 func_0028b038(void*);
void func_0028be78(void*, s32);
extern void* D_0035f200;
extern void* D_0035f214;
void func_002a0168(void* o, s32 msg);  // 0x002a0168: definition moved into src/anon/unit_0029f938.cpp

struct T2a1 { s16 a; s16 b; s16 c; };
extern T2a1 D_00374b60[2];
extern s8* D_0035f5d4;
void* func_002766d0(void);
void func_002a1ec8(void);  // 0x002a1ec8: definition moved into src/anon/unit_002a1d38.cpp

extern u8* D_0035f638;
s32 func_0023f900(void*);
void func_0023fad0(void*);
void func_00293d80(s32);
void func_002b2840(void) {
    if (*(u32*)(D_0035f638 + 52) & 0x200) {
        if (func_0023f900(D_0035f638)) func_0023fad0(D_0035f638);
    }
    func_00293d80(5101);
    *(u32*)(D_0035f638 + 52) &= ~0x200;
}

s32 func_002bc988(s32);
void func_002bc9a8(void*, s32, s32);  // find_entry12_set_field
void func_002bcbf0(u8* o, s32 a1, s32 a2, s32* a3, s32* t0);  // 0x002bcbf0: definition moved into src/anon/unit_002bc978.cpp

struct VObj { s32 (**vt)(VObj*); };
s32 func_002df0d8(VObj* o, u8* b);  // 0x002df0d8: definition moved into src/anon/unit_002de3c8.cpp

Vq func_002cb7c8(u32, u32);
extern Vq D_01e2be20;
// 002e3b88: moved to src/anon/unit_002e2f08.cpp

void func_002e9d08(u32, u32, const Vq&, const Vq&, s32, s32, s32);
void func_002e7c18(u32* o) {
    u32 a = o[0];
    Vq d = *(Vq*)o[3];
    Vq c = *(Vq*)o[2];
    s32 g = o[6] != 0;
    s32 e = o[4] != 0;
    s32 f = o[5] != 0;
    func_002e9d08(a, o[1], c, d, e, f, g);
}

struct Bigint { void* next; s32 k; s32 maxwds; s32 sign; s32 wds; u32 x[1]; };
/* newlib __mcmp: compare two bigints */
s32 __mcmp(Bigint* a, Bigint* b) {  // cmp_entries_16_then_words
    u32 *xa, *xa0, *xb, *xb0;
    s32 i = a->wds, j = b->wds;
    if ((i -= j)) return i;
    xa0 = a->x;
    xa = xa0 + j;
    xb0 = b->x;
    xb = xb0 + j;
    for (;;) {
        if (*--xa != *--xb) return *xa < *xb ? -1 : 1;
        if (xa <= xa0) break;
    }
    return 0;
}
}

// 002e76c8: moved to src/anon/unit_002e7658.cpp
