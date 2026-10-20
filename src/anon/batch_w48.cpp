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
s32 func_00135d00(u8* p, s32 i) {  // wrap_index
    s32 n = *(s32*)(p + 12);
    if (n == 0) return 0;
    while (i < 0) {
        i += n;
        asm volatile("nop\n\tnop\n\tnop\n\tnop\n\tnop");
    }
    if (i >= n) {
        s32 below;
        do {
            i -= n;
            below = i < n;
            asm volatile("nop\n\tnop\n\tnop\n\tnop" : : "r"(below));
        } while (!below);
    }
    return *(s32*)(p + 16 + i * 4);
}

void func_0011b038(s32 a) {
    s32 h = func_00111e38(0);
    func_0011ac10(a);
    u8* p = func_00106a60(1);  // buffer_get_by_index
    f32 v[4];
    f32 x = *(f32*)(p + 24);
    f32 z = *(f32*)(p + 56);
    v[0] = x;
    v[2] = z;
    v[3] = v[1] = 0.0f;
    func_0016aef0(h, v);
}

void func_0013e3b0(u8* o, Vq* v) {
    func_001391a8(o, *v);  // vec_copy_at416_if_diff
    if (func_00139d78(o + 448)) func_001391a8(o + 448, *v);
}

void func_0013fd10(u8* o) {
    Vq v;
    v = func_0016af58(*(u32*)(o + 68));
    func_0013fcd8(o, v);
}

void func_00144060(void) {
    u8 buf[16];
    *(u32*)(D_00348800 + 1904) = 0;
    if (D_00348810 != 0 && D_0034881f != 0) {
        func_00107368(func_00106a60(1), buf);  // vec_copy_at80_if_diff
        u8* q = D_00348800;
        func_00165f70((void*)D_00348810, buf, q + 624, q + 1904, q + 496);
    }
}

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
void func_00160f10(s32 id) {
    u8* p = 0;
    while ((p = next160(p))) {
        if (*(s32*)(p + 424) == id) func_001604d8(p);
    }
}

struct S10 { u8 a; u8 b; s16 c[4]; };
extern S10 D_0032bae0;
extern S10 D_0032bb10;
void func_0019ee80(s32, s32);
void func_001d5198(S10*);
void func_00178220(void) {
    func_0019ee80(D_0032bae0.a, D_0032bae0.b);
    D_0032bb10 = D_0032bae0;
    func_001d5198(&D_0032bae0);
}

struct E1817 { s32 id; s32 a; s32 b; };
extern E1817 D_0036c710[14];
void func_001817f0(s32 id) {
    for (E1817* e = D_0036c710; (s32)e < (s32)(D_0036c710 + 14); e++) {
        if (e->id == id) func_0019ee80(e->a, e->b);
    }
}

s32 func_001c0cd8(void*);
s32 func_0019c090(void*);  // obj_is_enabled
s32 func_001886d0(u8* o) {
    s32 r = 0;
    if (func_001c0cd8(*(void**)(*(u8**)(o + 136) + 4)) != 0 || func_0019c090(*(void**)(*(u8**)(o + 136) + 4)) == 0) {
        u32 m = *(u32*)(*(u8**)(*(u8**)(o + 136) + 4) + 352) & 0x200;
        r = m == 0;
    }
    return r;
}
}

f32* func_001ce328(u32);
u32 func_001ce2d8(u32);
void u_call4_00195858(u32 a0, u32 a1, u32, u32) {
    f32* o = (f32*)a0;
    *(f32**)(o + 7) = func_001ce328(a1);
    *(f32**)(o + 8) = (f32*)func_001ce2d8(a1);
    asm volatile("" ::: "memory");
    f32* m = *(f32**)(o + 7);
    o[0] = m[0];
    o[1] = m[1];
    o[2] = m[2];
    o[3] = m[3];
    o[5] = m[8];
    o[6] = m[10];
}

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
void func_00196198(void) {
    func_0016c750(D_0032b91c);
    void* h = func_0016d080(D_01c61b00, 0);
    func_0016cbc8(h, 7, 0, 0);
    func_0016cd48(h, 0);
    if (h) {
        func_0016cab8(h);
        func_0016c7d8(h);
    }
    func_0016c770();
}

u8* func_00168b88(void*, s32, s32, s32);  // find_entry16_by_half_word
s32 func_00198738(u8* o, s8* b) {
    void* p = *(void**)(o + 1968);
    u8* r;
    if (p && (r = func_00168b88(p, 22, b[0] | (b[1] << 8) | (b[2] << 16) | (b[3] << 24), 0)) != 0) return *(s32*)(r + 8);  // find_entry16_by_half_word
    return 0;
}

void func_0018f028(void*);
void func_0019f9a8(u8* o) {  // array8_free_slots
    u8* p = o;
    for (s32 i = 7; i >= 0; i--) {
        if (*(void**)(p + 12)) {
            func_0018f028(*(void**)(p + 12));
            *(u32*)(p + 12) = 0;
        }
        p += 8;
    }
    *(u32*)o = 0;
}

void func_0023acd8(u8*);
void func_0023ade0(u8*);
void func_001ac310(u8* o) {
    if (*(u32*)o == 0) return;
    u8* s = o + 12;
    func_0023acd8(s);
    u32 a = *(u32*)(o + 4);
    u32 b = *(u32*)(o + 8);
    *(u32*)(s + 328) = a;
    *(u32*)(s + 332) = b;
    func_0023ade0(s);
}

s32 func_00181550(s32);
s32 func_001b8958(s32);
void func_001b8838(s32);
extern s16 D_0036dbb0[][2];
void func_001b8e00(s32 i) {
    s32 v;
    if (func_00181550(i)) v = D_0036dbb0[i][1];
    else v = D_0036dbb0[i][0];
    if (v < 0) return;
    if (func_001b8958(v)) return;
    func_001b8838(v);
}

void func_002ba2e8(s32, s32);
struct Obj1bd5b0 { u8 pad[2240]; u8** p; u8 pad2[2536 - 2244]; u8* q; };
void func_001bd5b0(Obj1bd5b0* o, s32 i, u8 flag) {
    if (o->p == 0) o->p = (u8**)&o->q;
    else o->p++;
    *o->p = (u8*)o + i * 116 + 36;
    if (flag) func_002ba2e8(3, 0);
}

struct G32bb30 { u8 pad[13606]; u8 n; u8 pad2[14052 - 13607]; s32 total; u8 pad3[8]; u8 pad4[8]; u16 cur[4]; };
extern G32bb30 D_0032bb30;
u8* func_001b8e88(u32);
u16 func_001a67b0(s32);
void func_001bdff0(void) {
    for (s32 i = 0; i < 4; i++) {
        u8* e = func_001b8e88(D_0032bb30.cur[i]);
        if (*(u16*)(e + 2) == 2) D_0032bb30.cur[i] = func_001a67b0(*(s16*)(e + 4));
    }
}

void func_001bc778(void*);
u8* func_001bd570(void*, s32);
void func_001bc780(void*, u32, void*, u32);
void func_001be890(void* o, void* b) {
    func_001bc778(b);
    for (s32 i = 0; i < 4; i++) {
        u8* e = func_001bd570(o, i + 3);
        func_001bc780(b, *(u16*)(e + 2), e + 12, *(u8*)(e + 4));
    }
}

u8* func_001d5b78(s32, s32);
/* sum of the 'count' fields of the first n-1 entries; the nops are the R5900 short-loop padding */
s32 func_001d5d20(void) {
    u8* e = func_001d5b78(0, 1);
    s32 v = D_0032bb30.total;
    s32 n = D_0032bb30.n;
    s32 i = 1;
    if (i < n) {
        i = n - 1;
        do {
            v += *(s32*)(e + 4);
            i--;
            asm volatile("nop\n\tnop");
            e += 8;
        } while (i != 0);
    }
    return v;
}

extern u8 D_01d9e370[];
extern u8 D_01d9e6f0[];
void func_002f3cd8(void*, void*, void*);
u8* func_001e3468(u8* o) {
    u8* b = *(u8**)(o + 140);
    for (s32 i = 0; i < 8; i++) func_002f3cd8(D_01d9e370 + i * 16, D_01d9e6f0, b + i * 16);
    return D_01d9e370;
}



/* wait until VIF0/VIF1/GIF are idle and VU0 has stopped */
void func_001e7538(void) {  // hw_regs_setup
    do {
        s32 busy;
        u32 m = *(volatile u32*)0x10009000 & 0x100;
        busy = m != 0;
        if (*(volatile u32*)0x1000a000 & 0x100) busy = 2;
        if (*(volatile u32*)0x10003c00 & 0x1f000003) busy = 4;
        u32 st;
        asm volatile("cfc2.ni %0, $vi29" : "=r"(st));
        if (st & 0x100) busy = 8;
        if (!busy) break;
    } while (1);
}

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
void FadeOutCategory2621a0(void) {
    if (GetMode287bc0() != 10) return;
    func_0028dac8(func_00256b68(1), 295);
    if (func_0028be58(D_0035f04c)) func_0028bdb8(D_0035f04c);
}

extern u8* D_0035f20c;
s32 func_00192048(s32);
struct S275 { u8 pad[408]; s32 v; };
static inline S275* sub275() { return (S275*)(D_0035f20c + 1308); }
void func_00275f08(s32 i) {
    func_00139d78(sub275());
    if (i < 0) {
        *(u32*)(D_0035f20c + 1716) = 0;
        return;
    }
    sub275()->v = func_00192048(i);
}

u8* func_00294000(s32);
u8 func_002941d8(u8*);
s32 func_00294208(s32 id) {
    u8* t = func_00294000(0);
    s32 n = *(s32*)(t + 8);
    u8* e = t + 16;
    for (s32 i = 0; i < n; i++, e += 16) {
        if (*(s8*)e == id) return func_002941d8(e);
    }
    return 0;
}

struct E2953 { s8 id; u8 pad[15]; };
E2953* func_002953c8(s32 id) {
    u8* t = func_00294000(0);
    s32 n = *(s32*)(t + 8);
    E2953* e = (E2953*)(t + 16);
    s32 i;
    for (i = 0; i < n; i++) {
        if (e[i].id == id) break;
    }
    return &e[i];
}

void func_0029fcb0(void*);
void func_002a03d0(void);
s32 func_0028b038(void*);
void func_0028be78(void*, s32);
extern void* D_0035f200;
extern void* D_0035f214;
void func_002a0168(void* o, s32 msg) {
    switch (msg) {
    case 24:
        func_0029fcb0(o);
        func_002a03d0();
        break;
    case 25:
        func_0028be78(D_0035f214, func_0028b038(D_0035f200));
        break;
    }
}

struct T2a1 { s16 a; s16 b; s16 c; };
extern T2a1 D_00374b60[2];
extern s8* D_0035f5d4;
void* func_002766d0(void);
void func_002a1ec8(void) {
    u8* p = (u8*)func_002766d0() + 17304;
    s32 idx = D_0035f5d4[2] == 16;
    T2a1* t = &D_00374b60[idx];
    for (s32 i = 31; i >= 0; i--) {
        func_0028dac8(p, t->b);
        p += 408;
    }
}

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
void func_002bcbf0(u8* o, s32 a1, s32 a2, s32* a3, s32* t0) {
    *t0 = func_002bc988(a1);
    s32 m = *(s32*)(o + 332);
    *a3 = m;
    func_002bc9a8(o, m, *t0);  // find_entry12_set_field
    *(s32*)(o + 332) = *(s32*)(o + 332) == 20 ? 21 : 20;
}

struct VObj { s32 (**vt)(VObj*); };
s32 func_002df0d8(VObj* o, u8* b) {
    u8* s = b + 320;
    s32 x = *(s32*)(s + 20);
    s32 r = 0;
    if (x != ((s32 (*)(VObj*))(((void**)o->vt)[12]))(o)) {
        if (*(f32*)(s + 48) >= 8.0f) r = 1;
    }
    return r;
}

Vq func_002cb7c8(u32, u32);
extern Vq D_01e2be20;
void func_002e3b88(u32* o) {
    u8* p = *(u8**)(o[0] + 4);
    if (!p) return;
    u32 q = *(u32*)(p + 1288);
    if (!q) return;
    D_01e2be20 = func_002cb7c8(q, o[1]);
    o[0] = (u32)&D_01e2be20;
}

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
s32 func_00304468(Bigint* a, Bigint* b) {  // cmp_entries_16_then_words
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

void func_002e76c8_(void* v) asm("_Z13func_002e76c8Pv");
void func_002e76c8_(void* v) {
    u8* p = (u8*)v;
    p[0] = 1;
    p[1] = 0;
    p[2] = 0;
    p[138] = 0;
    p[139] = 1;
    p[140] = 1;
    u8* q = p;
    s32 i = 15;
    do {
        q[154] = 0;
        i--;
        q[170] = 0;
        asm volatile("nop\n\tnop"); /* R5900 short-loop padding */
        q++;
    } while (i >= 0);
    p += 186;
    s32 j = 127;
    do {
        *p = 0;
        j--;
        asm volatile("nop\n\tnop\n\tnop"); /* R5900 short-loop padding */
        p++;
    } while (j >= 0);
}
