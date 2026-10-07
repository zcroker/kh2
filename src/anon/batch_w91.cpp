#include "../common/types.h"

// 16-byte vector; assignment copies with a 128-bit lq/sq.
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

// 16-byte vector whose copy constructor is a 128-bit lq/sq (used for by-value passing).
struct Vc {
    f32 x, y, z, w;
    Vc() {}
    Vc(const Vc& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));

// Same as Vq but with a user default constructor (changes how temporaries are laid out).
struct Vk {
    f32 x, y, z, w;
    Vk() {}
    Vk& operator=(const Vk& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

// 4x4 matrix; assignment copies four quadwords.
struct Mq {
    Vq r[4];
    Mq& operator=(const Mq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

// 4x4 matrix whose copy constructor is four lq/sq (no self check).
struct Mc {
    Vq r[4];
    Mc() {}
    Mc(const Mc& o) { asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory"); }
} __attribute__((aligned(16)));

extern "C" {

u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void func_00139510(void*);

// --- 0010c9f8
// Sets a direction vector from a yaw (degrees, relative to the current one) and resets motion.
f32 func_002f8960(f32);
f32 func_002f87c0(f32);
void func_001b2210(u8*, Vc, f32, f32);
void func_0017f488(u8*, s32, f32, f32);
void func_0010c9f8(u8* p, f32 a, f32 b, f32 c, f32 d, f32 e) {
    a = *(f32*)(p + 1372) + a * 0.017453292f;
    Vc v;
    v.x = func_002f8960(a);
    v.z = func_002f87c0(a);
    v.y = b;
    v.w = c;
    func_001b2210(p, v, e, d);
    func_0017f488(p + 320, 3, 0.0f, 0.0f);
    *(s32*)(p + 256) = 4;
    *(s32*)(p + 260) = 5;
}

// --- 001215b8
// Flags (|= 4) every entry of both tables whose id field matches (or all when id == -1).
u8* func_00120800(u8*);
void func_001215b8(u8* p, u8* flags, s32 id) {
    u8* q = *(u8**)(p + 4);
    u8* r = func_00120800(p);
    s32 i;
    for (i = 0; i < *(s32*)(q + 28); i++) {
        if (id == -1 || ((*(u32*)(q + 32 + i * 32) >> 6) & 0x1f) == id) flags[i] |= 4;
    }
    if (r) {
        for (i = 0; i < *(s32*)(r + 28); i++) {
            if (id == -1 || (*(u32*)(r + 32 + i * 32) & 0x1f) == id) flags[*(s32*)(q + 28) + i] |= 4;
        }
    }
}

// --- 00131810
// Copies the current frame's matrices into the destination's matrix buffer.
void func_00127cf8(u32);
s32 func_001317a8(u8*, f32);
void func_00131810(u8* p, u8* q, u32, u32, u32 x, f32 t) {
    func_00127cf8(x);
    u8* s = *(u8**)(p + 4);
    s32 k = func_001317a8(p, t);
    u8* base = s + *(s32*)(s + 40);
    base += *(s32*)(s + 16) * k * 64;
    for (s32 i = 0; i < *(s32*)(s + 16); i++) {
        (*(Mq**)(q + 44))[i] = ((Mq*)base)[i];
    }
}

// --- 00132f98
// Walks a list and collects (counts) the active entries with the given id/owner.
s32 func_00132338(u8*);
u8* func_00132c68(u8*);
u8* func_00132350(u8*);
s32 func_00132f98(u8* p, u32 id, u8** out, u32, u8* owner) {
    s32 n = 0;
    if (p) do {
        if (func_00132338(p) == 1) {
            u8* d = func_00132c68(p);
            if ((!owner || *(u8**)(p + 4) == owner) && d && *(u16*)(d + 2) == id && *(s32*)(p + 636)) {
                if (out) out[n] = p;
                n++;
            }
        }
    } while ((p = func_00132350(p)) != 0);
    return n;
}

// --- 001506e0
void func_001396b0(void*);
void func_0031a260(void*, s32);
struct Ent506 { void (**vt)(Ent506*); u8 pad[392]; u32 a; u32 b; u8 pad2[4]; };
struct Own506 { void (**vt)(Own506*); u8 pad[44]; u8 sub[792]; Ent506 e[13]; };
void func_001506e0(Own506* p) {
    if (u_call4_00139d78(p)) p->vt[5](p);
    if (u_call4_00139d78(p->sub)) func_00139510(p->sub);
    for (s32 i = 0; i < 13; i++) {
        if (u_call4_00139d78(&p->e[i])) {
            p->e[i].a = 0;
            func_001396b0(&p->e[i]);
            if (p->e[i].a) {
                p->e[i].b = 0;
                func_001396b0(&p->e[i]);
                if (p->e[i].b) func_0031a260(&p->e[i], 0);
            }
            p->e[i].vt[5](&p->e[i]);
        }
    }
}

// --- 001515b0
void func_001515b0(u8* p) {
    s32 i;
    if (u_call4_00139d78(p)) (*(void (**)(u8*))(*(u8**)p + 20))(p);
    if (u_call4_00139d78(p + 48)) func_00139510(p + 48);
    for (i = 0; i < 10; i++) {
        u8* o = p + 496 + i * 408;
        if (u_call4_00139d78(o)) (*(void (**)(u8*))(*(u8**)o + 20))(o);
    }
    for (i = 0; i < 4; i++) {
        u8* o = p + 4576 + i * 408;
        if (u_call4_00139d78(o)) (*(void (**)(u8*))(*(u8**)o + 20))(o);
    }
}

// --- 001525b8
extern char D_0034a678[];
extern char D_0034a698[];
u32 func_00152598(u8*, u32, u32, char*);
void func_00152508(u8*, u32, u32, u32, u32);
void func_001525b8(u8* p, s32 mode, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f) {
    u32 r = 0;
    switch (mode) {
    case 0: r = func_00152598(p, e, c, D_0034a678); break;
    case 1: r = func_00152598(p, e, c, D_0034a698); break;
    }
    *(u32*)(p + 448) = e;
    *(u32*)(p + 444) = d;
    *(u32*)(p + 440) = c;
    *(u32*)(p + 436) = a;
    func_00152508(p, r, a, b, f);
}

// --- 00154de8
f32 func_0017ce10(f32);
void func_0013edd0(u8*, f32);
void func_0014b1e0(u8*, s16, s16);
void func_0014b208(u8*, u16, u16);
extern f32 D_0034a838;
void func_00154de8(u8* p, f32 t) {
    s32 w, h, x, y;
    if (t < D_0034a838) { w = 64; h = 64; x = 0; y = -64; }
    else { w = 1; h = 1; x = -64; y = 0; }
    f32 s = (1.0f - t) * 3.1415925f;
    s = func_0017ce10(s);
    u_call4_00139d78(p + 4944);
    func_0013edd0(p + 4976, s);
    u_call4_00139d78(p + 4944);
    func_0014b1e0(p + 5264, x, y);
    func_0014b208(p + 5264, w, h);
}

// --- 00177ab8
// Picks the matching special-state handler for the party member; clears a flag on success.
u8* func_00177860(u8*);
void func_00177a78(u8*);
void func_00177a38(u8*);
void func_00177a28(u8*);
u8 func_00177ab8(u8* p, u8 force) {
    u32 f;
    if ((*(u32*)(p + 360) & 0x20) && force) {
        u8 lv = p[2821];
        if (lv < func_00177860(p)[46]) {
            func_00177a78(p);
            goto done;
        }
    }
    f = *(u32*)(p + 352);
    if ((f & 0x400) && force) {
        func_00177a38(p);
        goto done;
    }
    {
        s32 b = 0;
        if (f & 4) goto one;
        if (f & 8) goto one;
        if (f & 0x10) one: b = 1;
        if (!(u8)b) return 0;
    }
    func_00177a28(p);
done:
    *(u32*)(p + 264) &= ~0x02000000;
    return 1;
}

// --- 00184f90
// Replaces the lock-on effect with one for the new target.
void func_002cb708(u8*);
void func_00105110(u8*);
u8* func_0019b380(u8*, u32);
u8* func_00182e98(u32);
u32 func_0016c028(u8*);
u8* func_002cd018(u8*, u8*, u32, f32);
u32 ctarget_00184f90(u8* p, u32 a1, u32, u32) asm("_Z16ctarget_00184f90jjjj");
u32 ctarget_00184f90(u8* p, u32 a1, u32, u32) {
    u8* h = *(u8**)(p + 1288);
    if (h) {
        func_002cb708(h);
        func_00105110(h);
        *(u8**)(p + 1288) = 0;
    }
    u8* t;
    if (*(u8**)(p + 2072)) t = func_0019b380(*(u8**)(p + 2072), a1); else t = 0;
    if (!t && (*(u32*)(p + 1416) & 0x80)) t = func_00182e98(a1);
    if (t) {
        *(u8**)(p + 1288) = func_002cd018(p, t, func_0016c028(p), 8.0f);
        return 1;
    }
    return 0;
}

// --- 001a1840
// Mirrors this object's colour/params into its two linked records.
union UF91 { f32 f; u32 u; };
extern u32 D_01c6cabc;
void wtarget_001a1840(u8* p, u32, u32, u32) asm("_Z16wtarget_001a1840jjjj");
void wtarget_001a1840(u8* p, u32, u32, u32) {
    u8* q = *(u8**)(p + 580);
    if (q) {
        q[4] = p[0];
        (*(u8**)(p + 580))[5] = p[4];
        (*(u8**)(p + 580))[6] = p[384];
        (*(u8**)(p + 580))[7] = p[388];
        (*(u8**)(p + 580))[12] = (s32)(*(f32*)(p + 444) / 60.0f);
        (*(u8**)(p + 580))[13] = (s32)(*(f32*)(p + 448) / 60.0f);
    }
    u8* r = *(u8**)(p + 608);
    if (r) {
        r[4152] = p[432];
        r[4153] = p[433];
        r[4154] = p[434];
        r[4155] = p[435];
        ((UF91*)(r + 4156))->f = ((UF91*)(p + 436))->f;
        ((UF91*)(r + 4160))->f = ((UF91*)(p + 440))->f;
        D_01c6cabc = ((UF91*)(p + 8))->u;
    }
}

// --- 001a76c8
// Tests a vertical segment through the point; on no hit, copies the point out.
struct Seg91 { Vk a, b; };
u32 func_00143a48(Seg91*);
u32 func_001a76c8(Vk* a, Vk* out) {
    Vk v0, v1;
    Seg91 s;
    v0 = *a;
    v0.y -= 50.0f;
    v1 = *a;
    v1.y += 100.0f;
    s.a = v0;
    s.b = v1;
    if (func_00143a48(&s)) return 1;
    *out = *a;
    return 0;
}

// --- 001be060
struct E1be { s32 type; };
u32 func_001bc9e8(E1be*);
u32 func_001d48e8(u8*, u32, E1be*);
void func_001be410(u8*);
u32 func_001bdcd0(u8*);
void func_001be4b0(u8*);
void func_001bd618(u8*, s32);
void func_001be060(u8* p) {
    E1be** cur = *(E1be***)(p + 2240);
    E1be* e = *cur;
    if (e && e->type == 10) { func_001bc9e8(e); return; }
    if (!func_001d48e8(p + 2496, *(u32*)(p + 2528), *cur)) func_001be410(p);
    e = **(E1be***)(p + 2240);
    if (!e) return;
    if (!func_001bc9e8(e)) return;
    if (!(*(u64*)(*(u8**)(p + 2532) + 8) & 0x10000)) return;
    E1be** c = *(E1be***)(p + 2240);
    s32 idx = c ? c - (E1be**)(p + 2536) + 1 : 0;
    if (idx < 2) {
        if (!func_001bdcd0(p)) func_001be4b0(p);
    } else {
        func_001bd618(p, 1);
    }
}

// --- 001cc9c8
// Calls func_001ccac0 for every active entry within `r` (XZ distance) of the object.
u8* func_001c16f0(u8*, u8*);
void func_001ccac0(u8*, u8*);
extern u8* D_00352050;
void func_001cc9c8(u8* o, f32 r) {
    Vc pos(*(Vc*)func_0016c028(o));
    u8* e = 0;
    while ((e = func_001c16f0(*(u8**)(D_00352050 + 2548), e)) != 0) {
        if (*(u32*)(e + 72)) continue;
        Vc d;
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&d), "r"(e), "r"(&pos) : "memory");
        d.y = 0.0f;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2 $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(&d) : "$8");
        if (len < r) func_001ccac0(e, o);
    }
}

// --- 001d50b8
struct B36 { u32 w[9]; };
u32 func_001bbb08(void);
u32* func_001ba158(void);
void func_00199098(B36*, s32);
u32 func_001d50b8(u8* p, B36* out) {
    if (p[0] != 16) return 0;
    if (func_001bbb08() != 225) return 0;
    u32* wp = func_001ba158();
    u32 id = p[1];
    u32 w = *wp;
    if (w == id || ((w == 18 || w == 21) && (id == 18 || id == 21))) {
        B36 buf;
        func_00199098(&buf, 7);
        *out = buf;
        return 1;
    }
    return 0;
}

// --- 001d62b0
// Percentage roll: chance from a level table (or 100), using the game's LCG.
u32 func_001c99b0(s32);
struct R8 { u8 a; u8 b; u8 pad[2]; s32 v; };
R8* func_001d5b78(s32, s32);
u8* func_00177860(u8*);
s32 func_001bbcc0(void);
u64 func_00312db8(u64, u64);
extern u32 D_003638d0;
u32 func_001d62b0(u8* who, u8* st) {
    s32 r = 0;
    if (func_001c99b0(6)) return r;
    R8* e = func_001d5b78(6, 1);
    s32 lv = *(s32*)(st + 4);
    while (lv < e->v) e++;
    s32 chance = 100;
    if (!(*(u32*)(func_00177860(who) + 20) & 0x8000)) chance = e->b * func_001bbcc0();
    D_003638d0 = D_003638d0 * 0x10dcd;
    s32 v = func_00312db8(D_003638d0, 42949673);
    *(s32*)(st + 4) += 1;
    r = v < chance;
    return r;
}

// --- 001d7538
extern u32 D_003527e4;
f32 func_00191b70(void);
s32 func_001a5bd0(u8*, s32, f32);
void func_001d7638(u8*, s32);
s32 func_001d9228(s32);
void func_001d7538(u8* p, u8* q) {
    if (!D_003527e4) return;
    f32 x = func_00191b70();
    if ((s32)func_001ba158()[5] > 0) x += x;
    for (s32 k = 0; k < 9; k++)
        for (s32 j = 0; j < func_001a5bd0(q, k, x); j++) func_001d7638(p, 1);
    s32 n = func_001d9228(0) / 2;
    if (n >= 7) n = 6;
    for (s32 i = 0; i < n; i++) func_001d7638(p, 0);
}

// --- 001e1070
u8* func_001050d8(u32);
void func_0018d238(u8*, u32, u32, u32, u32, s32, s32);
UF91* func_0018da18(u8*, u8*, u32, u32);
void func_0018ca10(UF91*);
void func_0018f028(u8*);
extern u8* D_00352bd0;
// Unused 16-byte local with trivial ctor/dtor: reserves the frame slot and blocks the tail call.
struct NT16 { u32 x[4]; NT16() {} ~NT16() {} };
void func_001e1070(u32, u8* a) {
    NT16 nt;
    u8* o = func_001050d8(208);
    func_0018d238(o, *(u32*)(D_00352bd0 + 3536), 0, 1143, 0, -1, -1);
    UF91* m = func_0018da18(o, a, *(u32*)(o + 40), 0);
    if (m) {
        m[3].f = m[2].f = m[0].f = 0.0f;
        m[1].f = 1.0f;
        (*(void (**)(u8*, UF91*))(*(u32*)a + 100))(a, m);
        func_0018ca10(m);
    }
    u8* x = *(u8**)(D_00352bd0 + 3536);
    (*(void (**)(u8*, u8*, u8*, u32))(*(u8**)x + 116))(x, a, o, m[8].u);
    func_0018f028(o);
}

// --- 001ead10
// Scales the work matrix rows by the bone's scale and copies its translation.
union GP91 { u8* p; f32 f; };
extern GP91 D_01d9e6e8;
void func_0021ed18(u8*, u8*);
static inline void vscl91(u8* m, u32 s) {
    asm volatile("qmtc2 %1, $vf9\n\tlqc2 $vf10, 0(%0)\n\tvmulx.xyz $vf10, $vf10, $vf9x\n\tsqc2 $vf10, 0(%0)" : : "r"(m), "r"(s) : "memory");
}
void func_001ead10(u8* base, u32, u8* a2) {
    u32* t = *(u32**)(a2 + 12);
    u8* m = base + t[1] + 160;
    f32* tr = (f32*)(base + t[0] + 160);
    u32* sc = (u32*)(base + t[2] + 160);
    func_0021ed18(D_01d9e6e8.p + 16, m);
    vscl91(D_01d9e6e8.p + 16, sc[0]);
    vscl91(D_01d9e6e8.p + 32, sc[1]);
    vscl91(D_01d9e6e8.p + 48, sc[2]);
    *(f32*)(D_01d9e6e8.p + 64) = tr[0];
    *(f32*)(D_01d9e6e8.p + 68) = tr[1];
    *(f32*)(D_01d9e6e8.p + 72) = tr[2];
}

// --- 001f6778
extern u32 D_01d9eab4;
extern u32 D_01d9ea9c;
extern u8* D_01d9e6e0;
extern u8 D_001f6648[];
struct A1f { u8 pad[4]; s16 h; u8 pad2[6]; u8 b12; u8 b13:8; u8 b14; u8 pad3; s32 w16; u32 pad4; s32 w24; };
struct S1f { u8 pad[2]; u8 cnt:8; };
void func_0021ee48(u8*, A1f*, u8*, S1f*, s32, u32, u32);
void func_001f6778(u8* base, A1f* a1, u8* a2) {
    if (D_01d9eab4) return;
    if (D_01d9ea9c) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0x000000ff0000ff00ULL) return;
    if (!a1->b13) return;
    S1f* s = (S1f*)(base + **(u32**)(a2 + 12) + 160);
    if (s->cnt == 0) {
        s->cnt = a1->b13;
        if (a1->w16 == -1) return;
        if (a1->w24 == -1) return;
        func_0021ee48(base, a1, D_001f6648, s, a1->h, a1->b14, a1->b12);
    }
    s->cnt--;
}

// --- 001fb790
// Sets the RGBA bytes of a node from 0..255 inputs scaled by the global colour.
extern f32 D_00354be0[];
void func_002f3f88(u8*, f32*);
void func_001fb6c8(u8*, u32, u32);
void func_001fb790(u8* base, u8* c, u8* a2) {
    u8* s = base + **(u32**)(a2 + 12) + 160;
    s[72] = (s32)(c[8] * *(f32*)(D_01d9e6e0 + 48));
    s[73] = (s32)(c[9] * *(f32*)(D_01d9e6e0 + 52));
    s[74] = (s32)(c[10] * *(f32*)(D_01d9e6e0 + 56));
    s[75] = (s32)(c[11] * *(f32*)(D_01d9e6e0 + 60));
    func_002f3f88(s + 48, D_00354be0);
    func_001fb6c8(s, 0, 0);
}

// --- 001fcd70
extern u8 D_01dad890[];
extern u8 D_01dad8d0[];
extern u8 D_01d9e840[];
extern u8 D_01d9e8c0[];
void func_002f3d08(u8*, u8*, u8*);
void func_002f3f40(u8*, u8*, f32);
void func_002f3cd8(u8*, u8*, u8*);
void func_001fcd70(void) {
    func_002f3d08(D_01dad890, D_01d9e840, D_01dad8d0);
    func_002f3f40(D_01d9e6e8.p + 80, D_01d9e6e8.p + 16, D_00354be0[0]);
    func_002f3f40(D_01d9e6e8.p + 96, D_01d9e6e8.p + 32, D_00354be0[1]);
    func_002f3f40(D_01d9e6e8.p + 112, D_01d9e6e8.p + 48, D_00354be0[2]);
    func_002f3cd8(D_01d9e6e8.p + 128, D_01d9e840, D_01d9e6e8.p + 64);
    func_002f3d08(D_01d9e6e8.p + 80, D_01d9e8c0, D_01d9e6e8.p + 80);
}

// --- 0024a270
s32 func_00287bc0(void);
void func_00287d68(void);
u32 func_00287db0(void);
u32 func_0028acc8(u32);
void func_001039f8(void);
void func_0024a348(void);
void func_0024a4d0(void);
extern u32 D_0035ed70;
extern u32 D_0035ed74;
extern u8* D_0035ed78;
extern u8* D_0035ed7c;
extern u8* D_0035ed80;
u32 func_0024a270(void) {
    s32 s = func_00287bc0();
    func_00287d68();
    if (func_00287db0()) {
        if (!func_0028acc8(D_0035ed70) && !func_0028acc8(D_0035ed74) && !u_call4_00139d78(D_0035ed78) && !u_call4_00139d78(D_0035ed7c) && !u_call4_00139d78(D_0035ed80)) {
            func_001039f8();
            return 1;
        }
    } else switch (s) {
        case 0: func_0024a348(); break;
        case 1: func_0024a4d0(); break;
    }
    return 0;
}

// --- 00262588  Tz::CmItem::LeaveStock
u8* cmtop_list_buffer(void) asm("_ZN2Tz5CmTop13GetListBufferEv");
void LeaveStock(void*) asm("_ZN2Tz6CmItem10LeaveStockEv");
void LeaveStock(void*) {
    u8* b = cmtop_list_buffer();
    if (u_call4_00139d78(b + 2504)) func_00139510(b + 2504);
    for (s32 i = 0; i < 5; i++) {
        u8* o = b + 3376 + i * 436;
        if (u_call4_00139d78(o)) (*(void (**)(u8*))(*(u8**)o + 20))(o);
    }
    if (u_call4_00139d78(b + 816)) func_00139510(b + 816);
}

// --- 00272468
u8* cmtop_list_buffer2(void) asm("_ZN2Tz5CmTop13GetListBufferEv");
u32 cmtop_select_pos(s32) asm("_ZN2Tz5CmTop12GetSelectPosEi");
s32 func_00272b60(u32);
struct T6 { u16 a, b; s16 c; };
extern T6 D_00373a30[];
void func_00138c10(u8*, s32);
u32 func_0028be58(u32);
void func_0028bd60(u32);
extern u32 D_0035f04c;
void func_00272468(void) {
    s32 v = 228;
    s32 m = func_00287bc0();
    u8* b = cmtop_list_buffer2();
    if (!(m == 26 || m == 27)) v = D_00373a30[func_00272b60(cmtop_select_pos(26))].c;
    if (b && u_call4_00139d78(b) && *(s32*)(b + 388) != v) func_00138c10(b, v);
    if (func_0028be58(D_0035f04c)) func_0028bd60(D_0035f04c);
}

// --- 0027b5d0
extern u32 D_0035f010;
u16* func_0026b850(void);
void func_0027aed8(u32, s32*, s32*);
u32 func_00281140(u32, s32);
u32 func_00192048(u32);
extern s16* D_0035f230;
u32 func_0027b5d0(void) {
    u32 r = 0;
    u16* v = func_0026b850();
    s32 oa, ob;
    func_0027aed8(cmtop_select_pos(15), &oa, &ob);
    if (oa == 0) {
        r = func_00281140(D_0035f010, ob);
    } else {
        s32 n = 0;
        for (s32 i = 0; i < 16; i++) {
            if (i == 6) continue;
            if ((u8)(((*D_0035f230 >> i) ^ 1) & 1)) continue;
            if (ob == n) { r = func_00192048(i == 7 ? 0xb2ec : v[i]); break; }
            n++;
        }
    }
    return r;
}

// --- 00290198
extern u8* D_00347f80;
extern u8 D_00347e60[];
void func_00239700(u8*);
void func_0028dfe8(u8*);
void func_00258d58(u32, u32, u32);
typedef u8* (*AllocFn91)(u8*, u32, u32);
void func_00290198(u8* self, u32 a, u32 b, u32 c, u16* arr) {
    u8* h = *(u8**)(D_00347f80 + 20);
    u8* o = (**(AllocFn91**)h)(h, 408, 0);
    *(u32*)(o + 12) = 0;
    *(u8**)o = D_00347e60;
    func_00239700(o + 24);
    *(u8**)self = o;
    u8* h2 = *(u8**)(D_00347f80 + 20);
    u8* o2 = (**(AllocFn91**)h2)(h2, 60, 0);
    func_0028dfe8(o2);
    *(u8**)(self + 4) = o2;
    for (s32 i = 0; i < 3; i++) ((u16*)(self + 8))[i] = arr[i];
    *(u32*)(self + 16) = a;
    func_00258d58(a, b, c);
}

// --- 00292f18
struct E16 { u32 a; u32 b; u32 c; u32 d; };
union GE91 { E16* p; u32 u; };
union GU91 { u32 v; u8 c; };
union GS91 { s32 v; u8 c; };
extern u32* D_0035f4dc;
extern GE91 D_0035f4d4;
extern GU91 D_0035f4c8;
extern GS91 D_0035f4c0;
extern u8 D_0035f4e2;
extern char D_00374578[];
extern u8 D_00292e60[];
void func_002fee78(char*, char*, ...);
void func_00168388(char*, u32, u8*, E16*);
u32 func_00292f18(void) {
    char buf[32];
    s32 v = *D_0035f4dc;
    u32 lo = v & 0xffff;
    s32 hi = v >> 16;
    func_002fee78(buf, D_00374578, lo);
    D_0035f4d4.p[hi].a = lo;
    D_0035f4d4.p[hi].b = 2;
    D_0035f4d4.p[hi].d = D_0035f4c8.v + hi * D_0035f4c0.v;
    D_0035f4d4.p[hi].c = 0;
    func_00168388(buf, D_0035f4d4.p[hi].d, D_00292e60, &D_0035f4d4.p[hi]);
    D_0035f4e2 = 1;
    return 0;
}

// --- 0029ad40
// Returns early as soon as any of the menu's sprites is still alive.
extern u8* D_0035f5b0;
struct NoTail91 { ~NoTail91() {} };
void func_0029ad40(void) {
    NoTail91 nt;
    if (u_call4_00139d78(D_0035f5b0)) return;
    if (u_call4_00139d78(D_0035f5b0 + 436)) return;
    if (u_call4_00139d78(D_0035f5b0 + 872)) return;
    if (u_call4_00139d78(D_0035f5b0 + 1308)) return;
    for (s32 i = 0; i < 5; i++) {
        if (u_call4_00139d78(D_0035f5b0 + i * 436 + 1744)) return;
        if (u_call4_00139d78(D_0035f5b0 + i * 436 + 3924)) return;
    }
    if (u_call4_00139d78(D_0035f5b0 + 6104)) return;
    u_call4_00139d78(D_0035f5b0 + 6512);
}

// --- 002a17e8
// Shows the help text for the highlighted entry (or clears it when nothing is selected).
extern u8* D_0035f5d8;
extern u8* D_0035f5d4;
u8* func_002a1bc0(u16);
u32 func_00295430(s32, s32);
void func_00192e50(u32, u8*, s32, u32);
void func_002595e8(u8*, u32);
void func_002a17e8(void) {
    u_call4_00139d78(D_0035f5d8 + 1224);
    s8 k = ((s8*)D_0035f5d4)[1];
    if (k < 0) {
        *(u32*)(D_0035f5d8 + 1632) = 0;
        return;
    }
    u8* it = func_002a1bc0(*(u16*)(D_0035f5d4 + k * 8 + 80));
    if (*(u16*)(it + 16) & 0x400) {
        u32 m = func_00192048(*(u16*)(it + 6));
        u32 m2 = func_00192048(func_00295430(((s8*)D_0035f5d4)[2], 1));
        func_00192e50(m, D_0035f5d4 + 4, 64, m2);
    } else {
        func_002595e8(D_0035f5d4 + 4, func_00192048(*(u16*)(it + 6)));
    }
    *(u8**)(D_0035f5d8 + 1632) = D_0035f5d4 + 4;
}

// --- 002ab540
static inline bool tbit91(u32* a, u32 i) { return (a[i >> 5] & (1 << (i & 31))) != 0; }
extern u8* D_0035f610;
u8* func_001a82b0(u8*);
s32 func_002764b0(u8);
u32 func_002ab540(s32 who) {
    u8* p = 0;
    u32 r = 0;
    for (u32 i = 0;; i++) {
        p = func_001a82b0(p);
        if (!p) break;
        if (p[4]) continue;
        u16 t = *(u16*)(p + 8);
        if (t == 0 || t == 2048) continue;
        s32 v = func_002764b0(p[5]);
        if (who >= 0 && v != who) continue;
        if (tbit91((u32*)(D_0035f610 + 236), i)) { r = 1; break; }
    }
    return r;
}

// --- 002ac800
u8* func_002a9d68(void);
u8* func_001d9e30(u8*);
u32 func_002ac800(s32 who) {
    u8* p = 0;
    u32 r = 1;
    u8* x = func_002a9d68();
    for (;;) {
        p = func_001d9e30(p);
        if (!p) break;
        if (who >= 0 && func_002764b0(p[4]) != who) continue;
        if (!tbit91((u32*)(D_0035f610 + p[0] * 8 + 404), p[1])) continue;
        r = tbit91((u32*)(x + p[0] * 8 + 404), p[1]);
        if (!r) break;
    }
    return r;
}

// --- 002ba630
extern u8 D_01e2a410[];
void func_002bcc60(u8*, u32, u32, s32*, s32*);
u32 func_002bccd8(u8*, u32, u32, u32, s32*, s32*);
void func_002baf48(s32, s32, u32, u32, u32, u32);
void func_002bce10(u8*, s32);
s32 func_002ba630(u32 a, u32 b, u32 c, u32 d) {
    s32 h[2];
    h[0] = -1;
    h[1] = -1;
    func_002bcc60(D_01e2a410, a, c, &h[0], &h[1]);
    func_002baf48(h[0], 0, a, b, 0, 0);
    if (c) func_002baf48(h[0], 1, c, d, 0, 0);
    func_002bce10(D_01e2a410, h[0]);
    return h[1];
}

// --- 002ba6f0
s32 func_002ba6f0(u32 a, u32 b, u32 c, u32 d, u32 e, s32* out) {
    *out = -1;
    s32 r = -1;
    if (func_002bccd8(D_01e2a410, a, b, d, out, &r)) {
        func_002baf48(*out, 0, b, c, 0, 0);
        if (d) func_002baf48(*out, 1, d, e, 0, 0);
        func_002bce10(D_01e2a410, *out);
    }
    return r;
}

// --- 002f86f0
// ceilf (newlib, no denormals).
typedef union { f32 value; u32 word; } ieee_float_shape_type91;
f32 ceil91(f32 x) asm("_Z13func_002f86f0f");
f32 ceil91(f32 x) {
    s32 i0, j0;
    u32 i, ix;
    ieee_float_shape_type91 gf;
    gf.value = x;
    i0 = gf.word;
    ix = (i0 & 0x7fffffff);
    j0 = (ix >> 23) - 0x7f;
    if (j0 < 23) {
        if (j0 < 0) {
            if (9.99999939e29f + x > (f32)0.0) {
                if (i0 < 0) { i0 = 0x80000000; }
                else if (!(ix < 0x00800000L)) { i0 = 0x3f800000; }
            }
        } else {
            i = (0x007fffff) >> j0;
            if ((i0 & i) == 0) return x;
            if (9.99999939e29f + x > (f32)0.0) {
                if (i0 > 0) i0 += (0x00800000) >> j0;
                i0 &= (~i);
            }
        }
    } else {
        return x;
    }
    ieee_float_shape_type91 sf;
    sf.word = i0;
    x = sf.value;
    return x;
}

// --- 003141e8
// libgcc fp-bit.c _fpdiv_parts (double).
enum fpc91 { C_SNAN, C_QNAN, C_ZERO, C_NUM, C_INF };
struct fpn91 { fpc91 cls; u32 sign; s32 normal_exp; u32 pad; u64 frac; };
extern fpn91 D_00378498;
static inline int fisnan91(fpn91* x) { return x->cls == C_SNAN || x->cls == C_QNAN; }
static inline int fisinf91(fpn91* x) { return x->cls == C_INF; }
static inline int fiszero91(fpn91* x) { return x->cls == C_ZERO; }
fpn91* func_003141e8(fpn91* a, fpn91* b) {
    u64 bit, numerator, denominator, quotient;
    if (fisnan91(a)) return a;
    if (fisnan91(b)) return b;
    a->sign = a->sign ^ b->sign;
    if (fisinf91(a) || fiszero91(a)) {
        if (a->cls == b->cls) return &D_00378498;
        return a;
    }
    if (fisinf91(b)) {
        a->frac = 0;
        a->normal_exp = 0;
        return a;
    }
    if (fiszero91(b)) {
        a->cls = C_INF;
        return a;
    }
    a->normal_exp = a->normal_exp - b->normal_exp;
    numerator = a->frac;
    denominator = b->frac;
    if (numerator < denominator) {
        numerator *= 2;
        a->normal_exp--;
    }
    bit = 1ULL << 60;
    quotient = 0;
    while (bit) {
        if (numerator >= denominator) {
            quotient |= bit;
            numerator -= denominator;
        }
        bit >>= 1;
        numerator *= 2;
    }
    a->frac = quotient;
    return a;
}

// --- 001422a0
// Fetches a vertex position (w = 1), transforms it by the object's matrix and normalizes it.
Vq* func_001422a0(Vq* out, u8* obj, u16 idx) {
    u8* e = *(u8**)(obj + 12) + idx * 16;
    *out = *(Vq*)(*(u8**)(obj + 24) + *(u16*)(e + 10) * 16);
    out->w = 1.0f;
    if (!obj[209]) {
        Mc m(*(Mc*)(obj + 80));
        asm volatile("sqc2 $vf0, 0(%0)" : : "r"(&m.r[3]) : "memory");
        Vq t;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%1)\n\tlqc2 $vf1, 0(%2)\n\tlqc2 $vf2, 16(%2)\n\tlqc2 $vf3, 32(%2)\n\tlqc2 $vf4, 48(%2)\n\t"
                     "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\t"
                     "sqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&t), "r"(out), "r"(&m) : "memory");
        *out = t;
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2 $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                     : "=f"(len) : "r"(out) : "$8", "memory");
    }
    return out;
}

// --- 001a7790
struct Ob64 { u8 b[64]; } __attribute__((aligned(16)));
u8* func_00106a18(s32);
Mc* func_00106ad0(u8*);
u8* func_00106a60(s32);
void func_00146680(Ob64*, Mc*);
u32 func_00146730(Ob64*, u8*);
static inline void mmul91(Mc* r, Mc* a, Mc* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf6x\n\tvmadday.xyzw ACC, $vf2, $vf6y\n\tvmaddaz.xyzw ACC, $vf3, $vf6z\n\tvmaddw.xyzw $vf6, $vf4, $vf6w\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf7x\n\tvmadday.xyzw ACC, $vf2, $vf7y\n\tvmaddaz.xyzw ACC, $vf3, $vf7z\n\tvmaddw.xyzw $vf7, $vf4, $vf7w\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf8x\n\tvmadday.xyzw ACC, $vf2, $vf8y\n\tvmaddaz.xyzw ACC, $vf3, $vf8z\n\tvmaddw.xyzw $vf8, $vf4, $vf8w\n\t"
                 "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)"
                 : : "r"(r), "r"(a), "r"(b) : "memory");
}
u32 func_001a7790(u8* a) {
    Ob64 ob;
    Mc m(*func_00106ad0(func_00106a18(1)));
    u8* t = func_00106a60(1);
    Mc* n = t ? (Mc*)(t + 16) : 0;
    Mc r;
    mmul91(&r, &m, n);
    func_00146680(&ob, &r);
    return func_00146730(&ob, a) == 0;
}

// --- 002e3318
// Collects the values of all items with `key` in the block tagged (c0, c1), up to max.
struct It8 { u16 key; u16 pad; u32 val; };
struct Hd8 { u8 c0; u8 c1; u16 n:16; It8 it[1]; };
s32 func_002e3318(u8* p, u32* out, s32 max, u32 key, u32 c0, u32 c1) {
    s32 n = 0;
    if (*(s32*)(p + 8) == 0) return 0;
    Hd8* h = (Hd8*)(p + 16);
    for (s32 i = 0; i < *(s32*)(p + 8); i++) {
        if (h->c0 == c0 && h->c1 == c1) {
            for (s32 j = 0; j < h->n; j++) {
                It8* it = &h->it[j];
                if (it->key == key && n < max) out[n++] = it->val;
            }
        }
        h = (Hd8*)((u8*)h + h->n * 8 + 4);
    }
    return n;
}

}
