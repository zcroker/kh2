#include "../common/types.h"
extern "C" {
extern u32 D_0035f140;
extern u8 D_0035f222;
void func_002593b8(s32, s32);
void func_00276410(void);
void func_00293bd0(s32, s32, s32);
void func_00274db8(void);
void func_002a7588(void);
void func_002925c0(void);
void func_00102448(s32, s32);
void func_00170dd0(s32);
void func_00274e08(void);
void func_00293fc0(void);
void func_00294020(s32);
void func_002a75c0(void);
s32 func_00292630(void);
s32 func_00287bc0(void);
void func_00274cf0(s32);
void func_002b3440(void);
void func_002a9d88(void);
void func_002acf48(void);
void func_00274fa8(void);
void func_00292870(void);
void func_00242618(s32, s32);
void func_00236d60(void);
s32 func_00275180(void);
void func_00275438(void);
void func_00274e50(void);
void func_00274b40(s32 a0) {
    func_002593b8(3, a0);
    func_00276410();
    func_00293bd0(0, 0, 0);
    func_00274db8();
    func_002a7588();
    func_002925c0();
    func_00102448(a0, 1);
    func_00170dd0(a0);
    func_00274e08();
    if (!(D_0035f140 & 4)) {
        func_00293fc0();
        func_00294020(0);
    }
    func_002a75c0();
    while (func_00292630()) func_00102448(a0, 0);
    func_00274cf0(func_00287bc0());
    func_002925c0();
    func_00102448(a0, 0);
    func_00170dd0(a0);
    for (;;) { if (!D_0035f222) break; func_00102448(a0, 0); }
    func_002b3440();
    func_002a9d88();
    func_002acf48();
    func_00274fa8();
    func_00292870();
    func_00242618(11, 1);
    for (;;) {
        func_00236d60();
        if (func_00275180()) break;
        func_00275438();
        func_00102448(a0, 0);
    }
    func_00274e50();
    while (func_00292630()) func_00102448(a0, 0);
    return;
}
}
struct Ent253 { s16 a; s16 id; s32 pad[2]; s32* val; };
extern "C" {
extern u8 D_0033cbb0;
void func_00197c90(void);
Ent253* func_00253330(u32);
s32 func_00103550(void);
s32 func_00103b38(void);
u8 func_00103428(s32);
s32 func_00103560(void);
void func_00103500(s32);
s32 func_00253380(u32);
void func_00253538(s32);
void func_001037b8(void);
void wtarget_00253180(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_00253180jjjj");
void wtarget_00253180(u32 a0, u32 a1, u32 a2, u32 a3) {
    s32 v1 = a1;
    s32 flag = 0;
    if (D_0033cbb0) return;
    if (a0 == 5) func_00197c90();
    Ent253* e = func_00253330(a0);
    s32 cur = func_00103550();
    if (func_00103b38() || cur != -1) {
        if (func_00103428(cur) && !func_00103428(e->id)) {
            func_00103500(e->id);
        } else if (!func_00103428(e->id)) {
            if (func_00103560() == -1) func_00103500(e->id);
        } else if (func_00103428(cur)) {
            u32 v = func_00103428(e->id);
            if (e->id == 50 && (u8)(v & 1)) func_00103500(e->id);
        }
        flag = 1;
    }
    s32* p = e->val;
    if (p && v1 != -999) {
        if (a0 == 0) {
            if (v1 < 0) v1 = 1;
            *p = v1;
        } else *p = v1;
    }
    if (flag) return;
    if (!func_00253380(a0)) {
        func_00103500(e->id);
        func_001037b8();
        return;
    }
    func_00253538(e->id);
}
}
struct E27 { u8 pad[5]; u8 key; u8 pad2[2]; };
extern "C" {
extern u8* D_0035f230;
extern s32 D_0035f01c;
extern s32 D_0035f010;
s32 func_002570a0(s32);
void func_0027aed8(s32, s32*, s32*);
s32 func_0027af58(void);
s32 func_0028b040(s32);
s32 func_0027c3b8(s32);
E27* func_00273180(s32, s32);
u8* func_001145b0(u16);
u8* func_00281180(s32, s32);
void func_0027c118(s32, s32);
#define REC(i) (D_0035f230 + (i) * 8)
void func_0027bf68(void) {
    s32 a, b;
    func_0027aed8(func_002570a0(15), &a, &b);
    s32 busy = func_0027af58();
    s32 idx = func_0028b040(D_0035f01c);
    s8 f16 = *(s8*)(REC(idx) + 16);
    s32 ok;
    E27* v;
    s32 i;
    u8* sp_;
    u8* w;
    if (a != 0 || b == 0 || busy != 0 || f16 != 0 || func_0027c3b8(idx)) goto early;
    v = func_00273180(4, -1);
    if (*(s8*)(REC(idx) + 14) != 0) {
        for (i = 0; i < 3; i++) {
            if (v[i].key == *(s8*)(REC(idx) + 18)) break;
        }
    } else {
        i = -1;
    }
    if (i + 1 < 3) {
        REC(idx)[18] = v[i + 1].key;
        sp_ = func_001145b0(*(u16*)(REC(idx) + 12));
        w = func_00281180(D_0035f010, b);
        (sp_ + *(s32*)(w + 580))[245] = REC(idx)[18];
        ok = 1;
    } else {
        REC(idx)[18] = -1;
        ok = 0;
    }
    func_0027c118(idx, ok);
    return;
early:
    ok = *(s8*)(REC(idx) + 14) == 0;
    func_0027c118(idx, ok);
}
}
struct T15 { u8 id; u8 b1; u8 b2; u8 pad; f32 f4; f32 f8; f32 f12; f32 f16; };
struct S15 { u8 pad[68]; T15 t; };
extern "C" {
extern S15 D_004f36a8;
extern S15 D_004f3650;
extern S15 D_004f3700;
extern T15 D_004f3744;
void func_0015c4b8(void);
s32 func_0015cc80(T15*);
void func_0010a8a8(f32, f32);
void func_0010a828(f32, f32);
void func_0010a7d8(u8, u8, u8);
void func_001dd1e8(u8, u8);
void func_001dd1b0(f32, f32);
void func_001dd1c8(u8, u8, u8);
void func_0015c6d0(S15* a0) {
    D_004f36a8 = *a0;
    D_004f3650 = D_004f36a8;
    D_004f3700 = *a0;
    func_0015c4b8();
    S15* p = &D_004f3700;
    if (p->t.f16 == 0.0f) p->t.f16 = 255.0f;
    T15* t = &p->t;
    T15* g = &D_004f3744;
    if (!func_0015cc80(t)) {
        func_0010a8a8(t->f12, t->f16);
        func_0010a828(t->f4, t->f8);
        func_0010a7d8(g->id, t->b1, t->b2);
    }
    func_001dd1e8((s32)t->f12, (s32)t->f16);
    func_001dd1b0(t->f4, t->f8);
    func_001dd1c8(g->id, t->b1, t->b2);
}
}
struct V287 {
    f32 x, y, z, w;
    V287() {}
    V287(const V287& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V287& operator=(const V287& o) {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline void v287_sub(V287* d, const V287* a, const V287* b) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline f32 v287_normalize(V287* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
struct R287 { f32 x, y, z; s32 w; V287 b; R287() { w = 0; } };
void func_0018a818(R287*, u8*, s32);
extern "C" {
extern u8* D_00352130;
extern f32 D_00349e10;
s32 func_001917b0(void);
void func_0017de70(u8*);
s32 func_001b9d40(u8*);
s32 func_0019c090(u8*);
s32 func_001a3a78(void);
s32 func_001de168(s32, s32, s32, s32, s32, s32);
void func_0017f540(u8*, s32, f32, f32);
s32 func_0016bc20(u8*, s32, s32);
V287* func_001dc5f8(s32);
void func_001dc818(s32);
static inline bool l287_idle(u8* o);
static inline bool l287_flag(u8* o) { return (*(u32*)(*(u8**)(o + 12) + 8) & 2) || (*(u32*)(o + 352) & 0x40); }
static inline bool l287_idle(u8* o) {
    bool b = false;
    if (func_0019c090(o) || l287_flag(o)) b = true;
    return !b;
}
void func_0017dcc0(u8* o) {
    R287 res;
    if (*(u32*)(o + 2040) & 4) {
        f32 dt = D_00349e10;
        if (!func_001917b0()) dt *= *(f32*)(D_00352130 + 92);
        *(f32*)(o + 2880) -= dt;
        if (*(f32*)(o + 2880) <= 0.0f) func_0017de70(o);
    }
    if ((*(u32*)(o + 2040) & 4) && func_001b9d40(o)) {
        if (l287_idle(o)) {
            if (*(s32*)(o + 2884) == 0) *(s32*)(o + 2884) = func_001de168(func_001a3a78(), 14, 1, 1, 0, 0);
            func_0017f540(o + 320, 54, 0.0f, 0.0f);
            goto out;
        }
    }
    if (*(s32*)(o + 340) != 54 && *(s32*)(o + 2884)) {
        func_001dc818(*(s32*)(o + 2884));
        *(s32*)(o + 2884) = 0;
    }
out:
    if (*(s32*)(o + 2884)) {
        func_0018a818(&res, o, func_0016bc20(o, 16, -1));
        *func_001dc5f8(*(s32*)(o + 2884)) = res.b;
    }
}
}

struct M287 {
    V287 r[4];
    M287() {}
    M287(const M287& o) {
        asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)\n\t.set reorder"
            : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    // In-place inverse of an orthonormal transform (transpose rotation, negate rotated translation).
    void invert() {
        asm volatile(".set noreorder\n\tlq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\tpextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\tpcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\tqmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\tvmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
} __attribute__((aligned(16)));
static inline void o287_apply(V287* d, const M287* m, const V287* v) {
    asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder"
        : : "r"(d), "r"(m), "r"(v) : "memory");
}
extern "C" {
extern u8* D_00361f60;
extern f32 D_00349e10;
s32 func_001c0cd8(void);
V287* func_0016c028(u8*);
u8* func_002d73f0(u8*);
static inline void o287_tick(u8* self, f32 s) {
    *(f32*)(self + 2840) += s * D_00349e10;
    *(f32*)(self + 3056) -= D_00349e10;
}
f32 func_002dbf50(u8* a0) {
    if (func_001c0cd8()) return 0.0f;
    u8* cam = D_00361f60;
    if (!cam) return 0.0f;
    *(f32*)(a0 + 2840) = 0.0f;
    M287 m = *(M287*)(cam + 336);
    m.invert();
    V287 p = *func_0016c028(a0);
    p.w = 1.0f;
    V287 r;
    o287_apply(&r, &m, &p);
    r.w = 1.0f;
    r.y = 0.0f;
    r.z = 0.0f;
    if (a0[3008]) {
        *(f32*)(a0 + 2840) = r.x + *(f32*)(a0 + 3024) * D_00349e10;
    } else if (*(f32*)(a0 + 3056) > r.y) {
        f32 s = *(f32*)(func_002d73f0(cam) + 48);
        f32 dt = D_00349e10;
        *(f32*)(a0 + 2840) = r.x + (a0[2844] ? s : -s) * dt;
        *(f32*)(a0 + 3056) -= D_00349e10;
    } else {
        *(f32*)(a0 + 2840) = r.x;
    }
    return *(f32*)(a0 + 2840);
}
}
