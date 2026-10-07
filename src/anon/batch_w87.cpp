#include "../common/types.h"
#include <stdarg.h>

extern "C" {

// ---- 0x109070: reset of two small tables and two record arrays ----
struct Rec88 { u32 a; u32 b; u8 pad[80]; };
struct Rec288 { u32 a; u32 b; u32 c; u8 pad[276]; };
union P88 { Rec88* p; u32 u; u16 h; };
union P288 { Rec288* p; u32 u; u16 h; };
union I32 { s32 v; u32 u; u16 h; };
extern u32 D_0033cc78[5];
extern u32 D_0033cc90[5];
extern I32 D_0033cc68;
extern P88 D_0033cc6c;
extern P288 D_0033cc70;
extern I32 D_0033cc60;
extern u8 D_0033cca8;
extern void* D_00340ea8;
extern u32 D_0033cca4;

void func_00109070(void) {
    s32 i;
    for (i = 0; i < 5; i++) D_0033cc78[i] = D_0033cc90[i] = 0;
    for (i = 0; i < D_0033cc68.v; i++) {
        D_0033cc6c.p[i].a = 0;
        D_0033cc6c.p[i].b = D_0033cc60.u;
        D_0033cc70.p[i].b = 0;
        D_0033cc70.p[i].a = 0;
        D_0033cc70.p[i].c = 0;
    }
    D_00340ea8 = &D_0033cca8;
    D_0033cca4 = 0;
}

// ---- 0x10e6e0: probe at three heights; returns the agreeing result ----
s32 func_00184780(void*, s32, f32, f32, f32);
s32 func_0010e6e0(u8* p, s32 a, f32 x, f32 y, f32 z) {
    if (*(s32*)(p + 2064) != 0) return 0;
    s32 r0 = func_00184780(p, a, *(f32*)(p + 1456) + x, y * 0.1f, z);
    if (r0 == func_00184780(p, a, *(f32*)(p + 1456) + x, y * 0.9f, z)) return r0;
    return func_00184780(p, a, *(f32*)(p + 1456) + x, y * 0.5f, z);
}

// ---- 0x117c28: constructor ----
union FU { f32 f; s32 i; };
void func_00113628(void*);
void func_0031a060(void*);
void* func_00114490(void*, s32);
void func_0011b6a8(void*);
void func_00117910(void*, s32);
extern u8 D_003476f0[];
extern u8 D_00347588;
void func_00117c28(u8* p) {
    func_00113628(p);
    *(u32*)p = (u32)D_003476f0;
    func_0031a060(p + 32);
    *(s32*)(p + 12) = 7;
    *(void**)(p + 16) = &D_00347588;
    FU* v = (FU*)func_00114490(p, 128);
    *(FU**)(p + 20) = v;
    ((FU*)(p + 1584))->i = 0;
    ((FU*)(p + 1648))->i = 0;
    ((FU*)(p + 1652))->f = v[1].f;
    asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(p + 1600) : "memory");
    asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(p + 1616) : "memory");
    *(f32*)(p + 1608) = *(f32*)(p + 1624) = 1024.0f;
    *(f32*)(p + 1576) = 15.0f;
    *(f32*)(p + 1580) = 0.19634954631328583f;
    func_0011b6a8(p + 1728);
    for (s32 i = 0; i < 24; i++) func_00117910(p, i);
    *(s32*)(p + 1568) = 0;
    *(s32*)(p + 1928) = 0;
}

// ---- 0x1285f8: binary search of x in a sorted float table -> bracketing indices ----
struct Curve { u8 pad[32]; s32 count; u8 pad2[32]; s32 off; };
void func_001285f8(u8* p, f32 x, s32* lo, s32* hi) {
    Curve* c = *(Curve**)(p + 4);
    f32* arr = (f32*)((u8*)c + c->off);
    if (arr[c->count - 1] <= x) {
        *lo = c->count - 1;
        *hi = c->count;
        return;
    }
    if (x <= arr[0]) {
        *lo = -1;
        *hi = 0;
        return;
    }
    *lo = 0;
    *hi = c->count - 1;
    while (*hi - *lo > 1) {
        s32 m = (*lo + *hi) / 2;
        if (x < arr[m]) *hi = m;
        else if (arr[m] < x) *lo = m;
        else { *hi = m; *lo = m; return; }
    }
}

// ---- 0x13bb58 ----
s32 func_0013ba60(void*, s32, s32, u8*, s32, s32*, s32*);
u8* func_0013b5d0(void*, s32, s32, s32, u8, s32, s32, s32, f32, u32, s32);
u8* func_0013bb58(void* a0, u8* a1, s32 a2, s32 a3, u8 b, s32 c, s32 d) {
    s32 r20 = 0;
    s32 r24 = -1;
    s32 ok = func_0013ba60(a0, a2, a3, &b, d, &r20, &r24);
    u8* r = func_0013b5d0(a0, a2, r20, 0, b, c + 28, 388 - *(s32*)(a1 + 8) * 22, 0, 1.0f, 0x80b4b4b4, 2);
    if (ok) *(s32*)(r + 392) = r24;
    return r;
}

// ---- 0x152820: screen rect of a sprite ----
void func_0023a9c0(void*, s32*, s32*);
u32 func_0023a918(void*);
s32 func_0023aa98(void*);
void func_00152820(u8* p, s32* x, s32* y, s32* r, s32* b, u32* fl) {
    s32 ox = 0;
    s32 oy = 0;
    u8* o = p + 24;
    func_0023a9c0(o, &ox, &oy);
    *fl = *(u32*)(p + 420);
    u32 v = func_0023a918(o);
    *fl = (*fl & 0xffffff) | (v & 0xff000000);
    *x = *(s32*)(p + 368) + ox;
    *y = *(s32*)(p + 372) + oy;
    *r = *x + func_0023aa98(o);
    *b = *y;
}

// ---- 0x154c10 ----
void func_00138c10(void*, s32);
s32 func_00154910(void*);
s32 func_00154930(void*);
struct P154 { u8 pad[15552]; s32 a; s32 pad2; s32 b; s32 c; };
void func_00154c10(u8* p, s32 n) {
    s32 i = 0;
    if (n < 0) n = 0;
    P154* s = (P154*)p;
    s->a = n;
    s->b = s->c;
    s->c = n;
    func_00138c10(p + 1680, 41);
    s32 a = func_00154910(p);
    s32 cnt = func_00154930(p);
    if (cnt > 0) {
        p += 2904;
        do {
            func_00138c10(p, i < a ? 44 : 46);
            i++;
            p += 816;
        } while (i < cnt);
    }
}

// ---- 0x1863a8 ----
void func_001866f0(void*, s32, f32);
void func_001866a0(void*, s32, f32);
s32 func_0019c090(void*);
void func_001a2a18(void*);
void func_00186548(void*, s32, f32);
static inline bool flags_2_and_40(u32 fl) {
    bool b = false;
    if (fl & 2) { u32 m = fl & 0x40; b = m != 0; }
    return b;
}
void func_001863a8(u8* p, s32 a, f32 x) {
    if (*(u32*)(*(u8**)(p + 12) + 8) & 0x10) {
        func_001866f0(p, a, x);
        return;
    }
    s32 r = func_0019c090(p);
    if (r) {
        func_001866a0(p, a, x);
        return;
    }
    u32 fl = *(u32*)(*(u8**)(p + 12) + 8);
    if (flags_2_and_40(fl)) func_001a2a18(p);
    func_00186548(p, a, x);
}

// ---- 0x192e50: expands '\r' markers in a string with formatted varargs ----
s32 func_00192440(char*, s32);
void func_002fdd68(char*, char*, s32);
s32 func_00192c40(s32, char*);
char* func_00192388(char*);
char* func_00192e50(char* s, char* out, s32 unused, ...) {
    va_list ap;
    va_start(ap, unused);
    char* start = s;
    char* ret = out;
    if (s) {
        do {
            if (func_00192440(s, 0)) {
                u8 c = *s;
                s32 n;
                if (c != 0) {
                    if (c == 13) {
                        n = s - start;
                        if (n > 0) {
                            func_002fdd68(out, start, n);
                            out += n;
                        }
                        out += func_00192c40(va_arg(ap, s32), out);
                        start = s + 1;
                    }
                } else {
                    n = s - start + 1;
                    func_002fdd68(out, start, n);
                    out += n;
                }
            }
        } while ((s = func_00192388(s)) != 0);
    }
    va_end(ap);
    return ret;
}

// ---- 0x196540: id -> message ----
void func_001963c8(s32);
void func_00196540(s32 id) {
    switch (id) {
    case 2232: func_001963c8(47); return;
    case 4193: func_001963c8(30); return;
    case 5151: func_001963c8(9); return;
    case 6178:
    case 6263: func_001963c8(31); return;
    case 8227: func_001963c8(41); return;
    case 10274: func_001963c8(38); return;
    case 12306: func_001963c8(19); return;
    case 16414: func_001963c8(16); return;
    }
}

// ---- 0x1b90f0 ----
s32 func_0016a080(void*);
s32 func_001b90f0(u8* o, u8* p) {
    if (*(s32*)(p + 2896) == 12) return 0;
    if ((*(u32*)(p + 1416) & 0x1000000) && *(s32*)(p + 2928)) {
        if (*(u32*)(o + 12) & 0x8000) return 0;
    } else {
        switch (func_0016a080(p)) {
        case 1: if (*(u32*)(o + 12) & 0x400) return 0; break;
        case 14: if (*(u32*)(o + 12) & 0x800) return 0; break;
        case 20: if (*(u32*)(o + 12) & 0x1000) return 0; break;
        case 27: if (*(u32*)(o + 12) & 0x2000) return 0; break;
        }
    }
    return 1;
}

// ---- 0x1bcd08: unwinds a stack of entries once none are busy ----
s32 func_001bcf18(void*);
s32 func_001bcf38(void*);
void func_001bc720(void*);
void func_001bd618(void*, s32);
void func_002ba2e8(s32, s32);
struct S2240 { u8 pad[2240]; void** sp; };
static inline bool entry_busy(void* e) {
    bool b = false;
    if (func_001bcf18(e) || func_001bcf38(e)) b = true;
    return b;
}
s32 func_001bcd08(u8* p) {
    void** s = (*(S2240**)(p + 4))->sp;
    while (!entry_busy(*s)) {
        if (*(s32*)((u8*)*s + 8) == 0) {
            while (!((*(S2240**)(p + 4))->sp < s)) {
                func_001bc720(*(*(S2240**)(p + 4))->sp);
                func_001bd618(*(void**)(p + 4), 0);
            }
            func_002ba2e8(4, 0);
            return 1;
        }
        s--;
    }
    return 0;
}

// ---- 0x1c91c8 ----
void func_0017f488(void*, s32, f32, f32);
void func_0017f5e0(void*, s32, s32, f32, f32);
extern u8* D_00352130;
void func_001c91c8(void* unused, u8* p) {
    f32 tmp[4] __attribute__((aligned(16)));
    f32* dst = (f32*)(p + 32);
    f32 s = *(f32*)(*(u8**)(p + 300) + 36);
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(tmp), "r"(p + 16), "f"(s) : "$8", "memory");
    if (dst != tmp)
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(dst), "r"(tmp) : "$8", "memory");
    *(u32*)(p + 268) = (*(u32*)(p + 268) | 0x10) & ~0x20;
    func_0017f488(p + 320, 202, 0.0f, 0.0f);
    func_0017f5e0(p + 320, 201, 0, 0.0f, 0.0f);
    *(f32*)(p + 240) = *(f32*)(D_00352130 + 192);
}

// ---- 0x222080: allocates a node and links it at the head of a list ----
u8* func_00221f98(u8*);
struct Key { void* p; u8 b; };
void func_00221e28(Key*);
void func_002226b8(void*, s32);
void func_00222080(u8* list, u8* a1, s32 a2, s32 a3) {
    u8* n = func_00221f98(a1);
    if (!n) return;
    Key k;
    k.p = n;
    k.b = a1[1];
    u32 fl = 256;
    func_00221e28(&k);
    *(s32*)(n + 92) = 0;
    *(s32*)(n + 48) = 0;
    u8 c = list[4];
    if (c & 4) fl = 384;
    if (c & 0x10) fl |= 0x200;
    if (c & 8) fl |= 0x400;
    if (c & 0x20) fl |= 0x1000;
    *(u16*)(n + 62) |= fl;
    func_002226b8(n + 64, a2);
    func_002226b8(n + 96, a3);
    u8* h = *(u8**)list;
    if (h) *(u8**)(h + 4) = n;
    *(u8**)n = h;
    *(u8**)(n + 4) = list;
    *(u8**)list = n;
}

// ---- 0x2378c8: rotation matrix rows from Euler angles at +112 ----
f32 func_002f8960(f32);
f32 func_002f87c0(f32);
void func_002378c8(f32* p, f32 z) {
    p[29] = z;
    f32 sx = func_002f8960(p[28]);
    f32 cx = func_002f87c0(p[28]);
    f32 sy = func_002f8960(p[29]);
    f32 cy = func_002f87c0(p[29]);
    f32 sz = func_002f8960(p[30]);
    f32 cz = func_002f87c0(p[30]);
    p[7] = cy * cz;
    p[9] = sx * sy * cz + cx * sz;
    p[8] = cy * -sz;
    p[10] = sx * sy * -sz + cx * cz;
}

// ---- 0x23dd28 ----
void func_00106d40(void*, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32);
void func_00106de8(void*, s32, f32);
void func_00106c08(void*);
void func_0023dd28(u8* p, s32 i, s32 x, s32 y) {
    u8* o = p + i * 400 + 32;
    func_00106d40(o, 512.0f, 0.7999999523162842f, 0.8666666150093079f, (f32)(x + 2048), (f32)(y + 2048), 1.0f, 16770000.0f, 1.0f, 4000000.0f, 256.0f, 208.0f);
    func_00106de8(o, 0, 0.6981316804885864f);
    func_00106c08(o);
}

// ---- 0x240360 ----
extern void* D_0035ec88;
extern char D_003716b8[];
extern char* D_0035ebf8;
extern char* D_0035ebfc;
extern char* D_0035ec00;
void func_002ff2e8(void*, const char*);
s32 func_00240108(void);
void func_00240118(void*, s32, s32);
void func_00240360(s32 k) {
    if (k == -5) return;
    if (k == -4) { func_002ff2e8(D_0035ec88, D_003716b8); return; }
    if (k == -3) { func_002ff2e8(D_0035ec88, D_0035ebf8); return; }
    if (k == -2) {
        const char* s;
        if (func_00240108()) s = D_0035ec00; else s = D_0035ebfc;
        func_002ff2e8(D_0035ec88, s);
        return;
    }
    func_00240118(D_0035ec88, k, func_00240108());
}

// ---- 0x247c20 ----
extern void* D_0035ed20;
extern s8 D_0035ed44;
struct E408 { u8 pad[388]; s32 st; u8 pad2[16]; };
extern E408* D_0035ed34;
s32 func_002891e8(void*);
s32 func_002469a0(s32);
s32 func_00139d78(void*);
s32 func_00246840(void);
void func_00243230(s32, s32);
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

// ---- 0x24bbb0 ----
extern void* D_0035edb0;
extern void* D_0035eda8;
extern void* D_0035edb8;
extern void* D_0035edb4;
struct E6 { s16 a, b, c; };
extern E6 D_00371ff0[];
s32 func_0023f0c0(void*);
void func_0023f070(void*, s32, s32);
s32 func_0028acc8(void*);
void func_0028ab20(void*);
void func_0024bbb0(void) {
    if (func_00139d78(D_0035edb0)) {
        if (func_0023f0c0(D_0035edb0) != 32) func_0023f070(D_0035edb0, 32, -1);
    }
    if (func_0028acc8(D_0035eda8)) {
        func_0028ab20(D_0035eda8);
        s32 k = func_002891e8(D_0035eda8);
        if (func_00139d78(D_0035edb8)) {
            if (func_0023f0c0(D_0035edb8) != D_00371ff0[k].c) func_0023f070(D_0035edb8, D_00371ff0[k].c, -1);
        }
    }
    if (func_00139d78(D_0035edb4)) {
        if (func_0023f0c0(D_0035edb4) != 35) func_0023f070(D_0035edb4, 35, -1);
    }
}

// ---- 0x24e9c0 ----
s32 func_001a6d08(s32);
union UP { u8* p; s32 i; };
extern s32 D_00372308[];
extern UP D_0035ee18[];
extern s32 D_0035ee08;
u8* func_0028c198(s32, s32, s32, s32, s32, s32);
s32 func_0024efc0(s32);
void func_001396b0(void*);
void func_0031ac78(void*, s32);
void func_0024e9c0(void) {
    for (s32 i = 0; i < 5; i++) {
        s32 id = D_00372308[i];
        if (id == 0 || func_001a6d08(id)) {
            D_0035ee18[i].p = func_0028c198(0, 2, 2, D_0035ee08, -1, 0);
            ((UP*)(D_0035ee18[i].p + 392))->i = 1;
            u8* o = D_0035ee18[i].p;
            *(s32*)(o + 400) = func_0024efc0(i);
            func_001396b0(o);
            if (*(s32*)(o + 400)) {
                *(s32*)(o + 396) = 0;
                func_001396b0(o);
                if (*(s32*)(o + 396)) func_0031ac78(o, 0);
            }
        }
    }
}

// ---- 0x2816f0: reset state and release three owned objects ----
typedef void (*VFn)(void*);
extern s16 D_0035f280;
extern s32 D_0035f274;
extern u8 D_0035f299;
extern s32 D_0035f270;
extern s32 D_0035f278;
extern s32 D_0035f27c;
extern s32 D_0035f284;
extern void* D_0035f288;
extern void* D_0035f290;
extern void* D_0035f29c;
void func_002816f0(void) {
    D_0035f274 = -1;
    D_0035f270 = -1;
    D_0035f278 = -1;
    D_0035f27c = -1;
    D_0035f280 = -1;
    D_0035f284 = 0;
    D_0035f299 = 1;
    if (D_0035f288) {
        (*(VFn*)((*(u8**)D_0035f288) + 16))(D_0035f288);
        D_0035f288 = 0;
    }
    if (D_0035f290) {
        (*(VFn*)((*(u8**)D_0035f290) + 16))(D_0035f290);
        D_0035f290 = 0;
    }
    if (D_0035f29c) {
        (*(VFn*)((*(u8**)D_0035f29c) + 4))(D_0035f29c);
        D_0035f29c = 0;
    }
}
// ---- 0x284ef0 ----
void func_00287d68(void);
s32 func_00287db0(void);
extern s32 D_0035f2d4;
extern u8 D_0035f2d0;
s32 func_00284538(void);
u8* func_0014aba8(void);
void func_002843e8(void);
void func_001039f8(void);
s32 func_00287bc0(void);
void func_00285070(void);
void func_00284fd8(void);
s32 func_00284ef0(void) {
    func_00287d68();
    if (func_00287db0()) {
        if (D_0035f2d4 == 2 && func_00284538()) {
            if ((*(s32*)(func_0014aba8() + 252) ^ 4) == 0) func_002843e8();
            return 0;
        }
        if (func_00284538()) return 0;
        func_001039f8();
        return 1;
    }
    if (D_0035f2d0) return 0;
    switch (func_00287bc0()) {
    case 0: func_00284fd8(); break;
    case 1: case 2: func_00285070(); break;
    }
    return 0;
}
// ---- 0x286418 / 0x2864f8: flag-bit queries ----
struct Flags { u8 pad[200]; u32 bits[2]; };
struct Flags2 { u8 pad[204]; u32 bits[2]; };
extern Flags* D_0035f2e4;
s32 func_002812e0(void);
s32 func_00286418(s32 n) {
    s32 r;
    if (n >= 0) {
        u32* w = &D_0035f2e4->bits[(u32)n >> 5];
        r = (*w & (1 << (n & 31))) != 0;
        if (func_002812e0() && n < 5) r = 0;
    } else {
        for (s32 i = 0; i < 9; i++) {
            u32* w = &D_0035f2e4->bits[(u32)i >> 5];
            r = (*w & (1 << (i & 31))) != 0;
            if (func_002812e0() && i < 5) r = 0;
            if (r) break;
        }
    }
    return r;
}
Flags2* func_002859a0(void);
s32 func_002864f8(s32 n) {
    Flags2* t = func_002859a0();
    s32 r = 1;
    if (n >= 0) {
        u32 m = 1 << (n & 31);
        u32 w = (u32)n >> 5;
        s32 res = 0;
        u32* pa = &D_0035f2e4->bits[w];
        if (*pa & m) { u32* pb = &t->bits[w]; res = (*pb & m) != 0; }
        return res;
    }
    u32* db = D_0035f2e4->bits;
    u32* tb = t->bits;
    for (s32 i = 0; i < 9; i++) {
        u32 m = 1 << (i & 31);
        if (db[(u32)i >> 5] & m) {
            r = (tb[(u32)i >> 5] & m) != 0;
            if (!r) return r;
        }
    }
    return r;
}

// ---- 0x29c880 ----
union GB { u8* p; u16 h; u32 u; };
extern u8 D_0035f5c4;
extern GB D_0035f5ac;
u8* func_00276568(void);
void func_00287bd0(s32, s32);
void func_0029dd00(void);
void func_002765e8(s32, s32, s32);
void func_0029be08(void);
void func_0029c880(s8* p, s32 k) {
    D_0035f5c4 = k;
    D_0035f5ac.p[5] = p[0];
    u8* o = D_0035f5ac.p;
    o[4] = k == 6 ? *func_00276568() : 16;
    for (s32 i = 0; i < p[0]; i++) ((u16*)(D_0035f5ac.p + 8))[i] = *(u16*)(p + 80 + i * 8);
    func_00287bd0(16, 0);
    func_0029dd00();
    s32 a = p[1];
    s32 b = 0;
    if (a >= 10) { b = a - 9; a = 9; }
    func_002765e8(15, a, b);
    func_0029be08();
}

// ---- 0x2b3df8: allocates one object, an array of three, and one more ----
typedef void* (*AllocFn)(void*, s32, s32);
union GA { u8* p; u32 u; void* v; };
extern GA D_00347f80;
extern u8 D_0035ebb8[];
struct T76 { void* vt; u32 f4, f8, f12; u8 pad[60]; };
static inline void* alloc76(s32 n) {
    void* a = *(void**)(D_00347f80.p + 20);
    return (*(AllocFn*)(*(u8**)a))(a, n, 0);
}
void func_002b3df8(GA* p) {
    p[0].u = 0;
    p[1].u = 0;
    p[2].u = 0;
    T76* o = (T76*)alloc76(76);
    o->f12 = 0;
    *(u32*)o = (u32)D_0035ebb8;
    p[0].v = o;
    u32* q = (u32*)alloc76(232);
    q[0] = 3;
    T76* e = (T76*)(q + 1);
    T76* it = e;
    for (s32 n = 2; n != -1; n--, it++) {
        it->f12 = 0;
        it->vt = D_0035ebb8;
    }
    p[1].v = e;
    o = (T76*)alloc76(76);
    o->f12 = 0;
    o->vt = D_0035ebb8;
    p[2].v = o;
}

// ---- 0x117e98: deleting destructor ----
struct Elem64 { u8 p8[8]; void* h; u8 d[52]; ~Elem64() {} } __attribute__((aligned(16)));
struct Obj117 { void* vt; u8 pad[28]; Elem64 e[24]; void* f1568; };
void func_001dc920(void*);
void func_0018f028(void*);
void func_00113668(void*);
void func_00105110(void*);
void func_00117e98(u8* p) {
    *(u32*)p = (u32)D_003476f0;
    s32 i = 0;
    do {
        void* o = ((Obj117*)p)->e[i].h;
        if (o) func_001dc920(o);
        func_00117910(p, i);
    } while (++i < 24);
    if (*(void**)(p + 1568)) {
        func_0018f028(*(void**)(p + 1568));
        *(void**)(p + 1568) = 0;
    }
    Elem64* b = ((Obj117*)p)->e;
    if (b) {
        Elem64* e = b + 24;
        for (;;) {
            if (b == e) break;
            e--;
            e->~Elem64();
        }
    }
    func_00113668(p);
    func_00105110(p);
}

// ---- 0x1ad638: destructor body (two arrays of polymorphic 344-byte members) ----
extern u8 D_00350a70[];
extern u8 D_00350ab0[];
extern u8 D_00350bb0[];
extern u8 D_00350a56;
void func_001c11a8(s32);
void func_0014c9f0(s32);
void func_00239870(void*);
void func_0031e668(void*);
void func_001ac5b8(void*);
struct NoTail { ~NoTail() {} };
void func_001ad638(u8* p) {
    NoTail keep_frame;
    *(void**)p = D_00350a70;
    D_00350a56 = 0;
    func_001c11a8(12);
    func_0014c9f0(8);
    *(void**)p = D_00350ab0;
    if (p + 3280) {
        u8* e = p + 4656;
        u8* b = p + 3280;
        for (;;) {
            if (b == e) break;
            e -= 344;
            (**(VFn**)e)(e);
        }
    }
    func_00239870(p + 2936);
    *(void**)p = D_00350bb0;
    if (p + 1544) {
        u8* e = p + 2920;
        u8* b = p + 1544;
        for (;;) {
            if (b == e) break;
            e -= 344;
            (**(VFn**)e)(e);
        }
    }
    func_00239870(p + 1200);
    func_00239870(p + 848);
    func_00239870(p + 484);
    func_0031e668(p + 132);
    func_001ac5b8(p);
}

// ---- 0x31b4f0: constructor (member arrays of 408-byte objects) ----
extern u8 D_0034a820[];
extern u8 D_00347e60[];
void func_00239700(void*);
struct E408b { void* vt; u32 f4, f8, f12; u8 pad[8]; u8 sub[384]; };
void func_0031b4f0(u8* p) {
    *(u32*)(p + 12) = 0;
    *(void**)p = D_0034a820;
    E408b* e = (E408b*)(p + 48);
    for (s32 n = 5; n != -1; n--) {
        e->f12 = 0;
        e->vt = D_00347e60;
        func_00239700(e->sub);
        e++;
    }
    u8* row = p + 2496;
    for (s32 r = 15; r != -1; r--) {
        E408b* q = (E408b*)row;
        for (s32 n = 1; n != -1; n--) {
            q->f12 = 0;
            q->vt = D_00347e60;
            func_00239700(q->sub);
            q++;
        }
        row += 816;
    }
}
// ---- 0x31e398: deleting destructor ----
extern u8 D_0034e888[];
extern u8 D_00363828[];
extern u8 D_003637e0[];
void func_0031e590(void*);
void func_002ee380(void*);
void func_0031e398(u8* p) {
    void** q36 = (void**)(p + 36);
    u8* o = p + 80;
    *(void**)p = D_0034e888;
    *q36 = D_00363828;
    *(void**)o = D_00350ab0;
    if (o + 3280) {
        u8* e = o + 4656;
        u8* b = o + 3280;
        for (;;) {
            if (b == e) break;
            e -= 344;
            (**(VFn**)e)(e);
        }
    }
    func_00239870(o + 2936);
    func_0031e590(o);
    *q36 = D_003637e0;
    func_002ee380(p);
    func_00105110(p);
}

// ---- 0x2ca4c0 ----
s32 func_00289380(void*);
s32 func_00289310(void*);
void func_00287df0(s32, s32, s32, s32, s32);
void func_002cac40(s32);
void func_002ca5b8(void*);
void func_002ca0a8(void);
void func_002ca4c0(u8* p) {
    s32 a = func_00289380(*(void**)(p + 188));
    func_00287df0(a, func_00289310(*(void**)(p + 188)), 0, 0, 1);
    switch (a) {
    case -2:
        func_002cac40(4);
        *(s32*)(p + 644) = 0;
        func_002ca5b8(p);
        break;
    case -4:
    case -1:
        break;
    default:
        if (func_002891e8(*(void**)(p + 188)) == 0) {
            func_002cac40(2);
            *(s32*)(p + 644) = 1;
            *(u32*)(p + 24) |= 1;
            func_002ca5b8(p);
            func_002ca0a8();
        } else {
            func_002cac40(2);
            *(s32*)(p + 644) = 0;
            func_002ca5b8(p);
        }
        break;
    }
}
// ---- 0x1c3060: re-registers flagged ids (high bit set) from two slot tables ----
void* func_001a80c8(u16);
void func_001c3150(void*, u16);
void func_001c35a0(void*);
struct O40 { u8 pad[580]; u8* a; u16* b; };
static inline __attribute__((always_inline)) void slots_a(u8* p, u8* a, u16* b) {
    if (a) {
        u16* e;
        s32 i;
        for (i = 0, e = (u16*)(a + 80); i < 80; i++, e++) {
            if (((u32)e[2] & 0xffff) >> 15) {
                u8* r = (u8*)func_001a80c8(e[2] & 0x7fff);
                if (!r[6] || !b) func_001c3150(p, e[2] & 0x7fff);
            }
        }
    }
}
static inline __attribute__((always_inline)) void slots_b(u8* p, u16* b) {
    if (b) {
        u16* e;
        s32 i;
        for (i = 0, e = b + 4; i < 24; i++) {
            if (((u32)*e & 0xffff) >> 15) func_001c3150(p, *e & 0x7fff);
            e++;
        }
    }
}
void func_001c3060(u8* p) {
    O40* o = *(O40**)(p + 40);
    u8* a = o->a;
    u16* b = o->b;
    slots_a(p, a, b);
    slots_b(p, b);
    func_001c35a0(p);
}

}
