#include "../common/types.h"

// 128-bit copies (lq/sq) are hand-written asm in the original.
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
// Same, but in a noreorder region so gas doesn't move the sq into a following branch delay slot.
#define QCOPYN(d, s) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(d), "r"(s) : "$8", "memory")

struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));

extern "C" {

struct Rec20 { u32 w[5]; };
u32 func_0010f8c0(u32 a0);
void func_0010f880(f32 a0, f32 a1, u32 a2);
u32 func_0010f8e0(u32 a0);
f32 func_0010f8a8(u32 a0);
u32 func_0010ef48(u32 a0);
u32 func_0010f9e0(u32 a0, u32 a1);
u32 func_0010cc80(u32 a0);
u8* func_0010cc70(u32 a0);
void func_0016b010(u32, Vec4*);
void func_0016af58(Vec4*, u8*);
void func_0010f9f0(u32, Vec4*, s32);

u8 func_00113848(u32 param_1, u32 param_2, Rec20* param_3, u32* param_4, u8 param_5) {
    if (param_5 != 0) {
        *param_4 = 0;
        u32 o = *(u32*)(param_1 + 4);
        param_3->w[0] = *(u32*)(o + 2548);
        param_3->w[1] = *(u32*)(o + 2552);
        param_3->w[2] = *(u32*)(o + 2556);
        param_3->w[3] = *(u32*)(o + 2560);
        param_3->w[4] = *(u32*)(o + 2564);
        if (func_0010f8c0(*(u32*)(param_1 + 4)) != 0) {
            if (func_0010f8e0(*(u32*)(param_1 + 4)) != 0) {
                return 0;
            }
            if (func_0010f8a8(*(u32*)(param_1 + 4)) <= 0.0f) {
                return 0;
            }
        } else if (func_0010f9e0(*(u32*)(param_1 + 4), param_2) != 0) {
            return 0;
        }
        return (u8)(func_0010ef48(*(u32*)(param_1 + 4)) ^ 1);
    }

    if (func_0010f8c0(*(u32*)(param_1 + 4)) == 0) {
        u32 obj = *(u32*)(param_1 + 8);
        f32 f12 = *(f32*)(obj + 112);
        f32 f13 = *(f32*)(obj + 116);
        func_0010f880(f12, f13, *(u32*)(param_1 + 4));
    }
    Vec4 v;
    if (func_0010cc80(*(u32*)(param_1 + 4)) != 0) {
        u8* q = func_0010cc70(*(u32*)(param_1 + 4));
        // 128-bit copy (hand-written lq/sq)
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&v), "r"(q + 32) : "$8", "memory");
        func_0016b010(*(u32*)(param_1 + 4), &v);
    }
    func_0016af58(&v, *(u8**)(param_1 + 4));
    *(u32*)&v.w = 0;
    func_0010f9f0(*(u32*)(param_1 + 4), &v, 0);
    return 1;
}

typedef s32 (*Fn5)(void*, void*, u32, void*, u32, u32, u8, u32);
struct Obj5 { void** vt; };
s32 func_00132338(u8*);
void func_00132cb8(u8*);
u8* func_00132350(u8*);
s32 func_0011c8f8(u8* p, u8* a1, u8 flag, Obj5* o, u32 a4, u32 a5)
{
    s32 r = ((Fn5)o->vt[19])(o, p + 64, a4, a1, a5, *(u32*)(p + 56), flag, *(u32*)(a1 + 52));
    if (!flag && (*(u32*)(p + 12) & 2))
        ((Fn5)o->vt[21])(o, p + 64, a4, a1, a5, *(u32*)(p + 56), 0, *(u32*)(a1 + 52));
    if (r || flag) {
        for (u8* q = *(u8**)(p + 56); q; q = func_00132350(q)) {
            if (func_00132338(q) == 1) func_00132cb8(q);
        }
    }
    return r;
}

struct V4f { f32 x, y, z, w; };
// 00144be0: eight corners of the box min(0,1,2)/max(3,4,5), y and z negated
void func_00144be0(f32* b, V4f* v)
{
    v[0].w = v[1].w = v[2].w = v[3].w = v[4].w = v[5].w = v[6].w = v[7].w = 1.0f;
    v[0].x = b[0]; v[0].y = -b[4]; v[0].z = -b[5];
    v[1].x = b[0]; v[1].y = -b[1]; v[1].z = -b[5];
    v[2].x = b[3]; v[2].y = -b[1]; v[2].z = -b[5];
    v[3].x = b[3]; v[3].y = -b[4]; v[3].z = -b[5];
    v[4].x = b[0]; v[4].y = -b[4]; v[4].z = -b[2];
    v[5].x = b[0]; v[5].y = -b[1]; v[5].z = -b[2];
    v[6].x = b[3]; v[6].y = -b[1]; v[6].z = -b[2];
    v[7].x = b[3]; v[7].y = -b[4]; v[7].z = -b[2];
}

void func_00158050(u8*, s32, u32, u32, s32, s32, u32);
void func_00139598(u8*);
void func_00156880(u8* p, u32 a1, u32 a2, u32 a3)
{
    func_00158050(p + 10000, 7000, a1, a2, 116, 0, a3);
    func_00158050(p + 10412, 7000, a1, a2, 119, 0, a3);
    func_00158050(p + 10824, 7000, a1, a2, 115, 0, a3);
    func_00158050(p + 11236, 7000, a1, a2, 120, 0, a3);
    u8* o = *(u8**)(p + 52);
    if (o && (*(u32*)(*(u8**)(o + 1164) + 592) & 4)) {
        func_00139598(p + 10000);
        func_00139598(p + 10412);
        func_00139598(p + 10824);
        func_00139598(p + 11236);
    }
}

u8* func_00177860(u8*);
void func_00176970(u8*);
void func_00177a28(u8*);
u8* func_00176fb0(u8*, s32);
s32 func_001a0920(u8*, u8*);
void func_00177008(u8*, u8*, u32);
s32 func_00176868(u8* p, u8* a1)
{
    u32 f = *(u32*)(*(u8**)(p + 12) + 8);
    u8* t = *(u8**)(p + 304);
    if (f & 0x40) {
        if (f & 0x800) return 0;
        if (*(f32*)(p + 248) < *(f32*)(t + 88)) return 0;
        if (*(u32*)(p + 2040) & 4) return 0;
        if (*(u32*)(a1 + 4) & 2) {
            if (*(u32*)func_00177860(p) & 0x100000) {
                func_00176970(p);
                return 1;
            }
        }
        if (!(*(u32*)(a1 + 4) & 8)) return 0;
        func_00177a28(p);
        u8* q = func_00176fb0(p, 40);
        if (q) {
            if (func_001a0920(q, p)) {
                func_00177008(p, q, *(u32*)(p + 2880) + 4);
                return 1;
            }
        }
    }
    return 0;
}

s32 func_00179c80(u8*);
void func_001dc818(u32);
u32* func_0015ef28(void);
s32 func_001de2e0(u32*, u64);
u32 func_001de168(u32*, s32, s32, s32, s32, s32);
Vec4* func_001dc5f8(u32);
Vec4* func_0016c028(u8*);
Vec4* func_001dc648(u32);
void func_0016af58(Vec4*, u8*);
void func_0017d050(Vec4*, Vec4*);
void func_00179cb8(u8* p)
{
    if (func_00179c80(p)) {
        u32 h = *(u32*)(p + 2912);
        if (!h) {
            u32* o = func_0015ef28();
            if (*o) {
                s32 k = func_001de2e0(o, 1LL << 50);
                if (k >= 0) {
                    h = *(u32*)(p + 2912) = func_001de168(o, k, 1, 2, 10001, 0);
                    goto have;
                }
            }
            h = *(u32*)(p + 2912);
        have:
            if (!h) return;
        }
        Vec4* d = func_001dc5f8(h);
        Vec4* s = func_0016c028(p);
        if (d != s) QCOPY(d, s);
        Vec4* m = func_001dc648(*(u32*)(p + 2912));
        Vec4 b, a;
        func_0016af58(&a, p);
        func_0017d050(&b, &a);
        if (m != &b) QCOPY(m, &b);
    } else if (*(u32*)(p + 2912)) {
        func_001dc818(*(u32*)(p + 2912));
        *(u32*)(p + 2912) = 0;
    }
}

extern f32 D_00349e10;
f32 func_002f8870(f32);
// VU0 helpers (hand-written asm in the original)
static inline void vu_Scale11(Vec4* s, Vec4* d, f32 f)
{
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
                 : : "r"(s), "r"(d), "f"(f) : "$8", "memory");
}
static inline void vu_Interp11(Vec4* a, Vec4* b, Vec4* d, f32 t)
{
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\t"
                 "vaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\t"
                 "vmulax.xyzw ACC, $vf2, $vf3x\n\tvmaddx.xyzw $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(a), "r"(b), "r"(d), "f"(t) : "$8", "memory");
}
static inline void vu_Copy11(Vec4* d, Vec4* s)
{
    if (d != s) QCOPYN(d, s);
}
struct Obj11 { u8 pad[16]; Vec4 dir; Vec4 pos; };
u32 func_00184540(u32 out, u32 a1, f32 t, f32 s) asm("_Z13func_00184540jjff");
u32 func_00184540(u32 out, u32 a1, f32 t, f32 s)
{
    Obj11* p = (Obj11*)a1;
    if (t != 0.0f) {
        if (func_002f8870(p->pos.x) < 100000000.0f && func_002f8870(p->pos.y) < 100000000.0f && func_002f8870(p->pos.z) < 100000000.0f) {
        }
    }
    Vec4 r, b, a;
    if (0.0f < p->dir.w) {
        vu_Scale11(&p->dir, &a, p->dir.w);
        vu_Interp11(&a, &p->pos, &b, t);
        vu_Copy11(&r, &b);
    } else {
        vu_Scale11(&p->pos, &b, s);
        vu_Copy11(&r, &b);
    }
    vu_Copy11(&p->pos, &r);
    vu_Scale11(&r, (Vec4*)out, D_00349e10);
    return out;
}

struct Ray12 { Vec4 a, b, c, hit; u8 pad[48]; u64 on:1; u64 mode:2; u64 rest:29; u64 hitflag:1; u64 rest2:31; u8 pad2[24]; };
void func_00319e90(Ray12*, void*);
Vec4* func_0016c028(u8*);
void func_00143928(Ray12*);
static inline void Copy12(Vec4* d, Vec4* s)
{
    if (d != s) QCOPY(d, s);
}
s32 func_00185138(u8* p, Vec4* out, u8 flag, f32 dist)
{
    Ray12 r;
    func_00319e90(&r, p + 1424);
    Copy12(&r.a, func_0016c028(p));
    asm volatile("sqc2 $vf0, 0(%0)" : : "r"(&r.b) : "memory");
    r.mode = 2;
    if (flag) r.on = 1; else r.on = 0;
    s32 ret = 0;
    f32 d = 0.0f;
    while (d < dist) {
        d += 100.0f;
        if (dist < d) d = dist;
        r.c.x = r.c.z = d;
        func_00143928(&r);
        if (!flag && r.hitflag) return ret;
        Copy12(&r.a, &r.hit);
        Copy12(out, &r.hit);
        ret = 1;
    }
    return ret;
}

struct B32 { f32 a, y, c; u32 d; Vec4 pos; };
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
void func_0018a818(B32*, u8*, u32);
s32 func_001a7610(Vec4*, VecD*, s32, f32, f32);
struct VA14;
void func_00193be8(u8*, VA14*, void*, u32);
extern u8 D_01c61ae0[];
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
void func_00193d38(u8* p, u32 a1)
{
    B32 b;
    VecD out[2];
    VA14 dir;
    b.d = 0;
    u32* q = (u32*)(p + 1636);
    for (s32 i = 0; i < 2; i++) {
        func_0018a818(&b, p, *q++);
        func_001a7610(&b.pos, &out[i], ((s32)(*(s64*)(p + 1536) << 29 >> 32)) & 0xf, 0.0f, b.c);
    }
    dir = out[0] - out[1];
    asm volatile("lqc2 $vf1, 0(%0)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\t"
                 "vsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, $f0\n\tvnop\n\t"
                 "vdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&dir) : "$8", "$f0", "memory");
    func_00193be8(p, &dir, D_01c61ae0, a1);
}

struct Def15 {
    u8 pad; u8 mode; u16 b0:4; u16 snd:1; u16 alt:1;
    bool Snd() { return snd; }
    bool Alt() { return alt; }
};
struct Obj15 { u8 pad[60]; Def15* def; u8 pad2[80]; f32 vol; };
u32 func_0014abe8(void);
u32 func_0014abf8(void);
u32 func_0014aba8(void);
void func_0014aa58(u32, s32, s32);
void func_0014aa80(u32, s32, s32);
void func_0013f160(void);
void func_00196e88(Obj15*, s32, s32, f32);
void func_00197430(Obj15* p)
{
    if (p->def->Snd()) {
        func_0014aa58(func_0014abe8(), 0, 0);
        func_0014aa58(func_0014abf8(), 0, 0);
    }
    switch (p->def->mode) {
    case 1:
    case 3:
        func_0013f160();
        func_0014aa80(func_0014aba8(), (s32)(p->vol * 0.5f), 0);
        break;
    case 2:
        func_0013f160();
        func_0014aa80(func_0014aba8(), (s32)(p->vol * 0.5f), 1);
        break;
    }
    if (!p->def->Alt()) func_00196e88(p, 7, 2, 0.0f);
    else func_00196e88(p, 8, 0, 0.0f);
}

extern s8 D_0036d0c8[];
extern u8* D_0034e948;
void wtarget_00198970(u8*) asm("_Z16wtarget_00198970jjjj");
u8* func_00168b88(u32, s32, u32, s32);
void func_001bdb70(u8*, s32, u32, u32, u8*);
void func_0019d720(u8*);
#define ID4(s) ((s)[0] | ((s)[1] << 8) | ((s)[2] << 16) | ((s)[3] << 24))
void set_special_command(u8* self, s32 cmd) asm("_ZN2YS6STDOBJ19set_special_commandEi");
void set_special_command(u8* self, s32 cmd)
{
    wtarget_00198970(self);
    u8* sub = self + 1952;
    u8* r1 = func_00168b88(*(u32*)(sub + 16), 24, ID4(D_0036d0c8), 0);
    u32 h = *(u32*)(sub + 16);
    u32 a = *(u32*)(r1 + 8);
    u8* r2 = func_00168b88(h, 25, ID4(D_0036d0c8), 0);
    u8* o = *(u8**)(D_0034e948 + 2884);
    func_001bdb70(o, cmd, a, *(u32*)(r2 + 8), self);
    func_0019d720(o + 2552);
    *(u32*)(self + 268) |= 0x800;
    *(u32*)(self + 1160) += 1;
}

extern u8 D_00350ca8[];
extern u8 D_00350ca0[];
extern s32 D_00350c88;
u8* func_001ae460(u32);
s32 func_001ae010(u32);
s32 func_002f79c8(s32);
s32 func_002f7be8(u32, u32, u32, u8*);
void func_001ae620(void);
void func_001ae650(void);
void func_001ae678(void);
s32 func_002f7dc8(void);
u32 func_001ae0a0(u32 a0, u32 a1, u32 a2, u16 a3)
{
    u8* h = func_001ae460(a0);
    if (!h) return 0;
    u8* tbl = func_001ae010(a0) ? D_00350ca8 : D_00350ca0;
    for (;;) {
        if (func_002f79c8(1) != 2 || func_002f7be8(*(u32*)(h + 8) + a2, a3, a1, tbl) != 1) {
            func_001ae678();
        } else {
            func_001ae620();
            if ((D_00350c88 = func_002f7dc8()) == 0) return a3 << 11;
            func_001ae650();
        }
    }
}

struct Q18 { u32 bits[8]; u8 queue[255]; u8 count; };
extern Q18 D_0032fb68;
s32 func_001b8958(s32);
u8* func_001b8800(s32);
s32 func_00181550(void);
void func_001b8838(s32 code)
{
    Q18* q = &D_0032fb68;
    switch (code) {
    case 37:
        if (func_001b8958(115)) return;
        break;
    case 42:
        if (func_001b8958(86)) return;
        break;
    case 45:
        if (func_001b8958(84)) return;
        break;
    case 46:
        if (func_001b8958(114)) return;
        break;
    }
    u32* w = &D_0032fb68.bits[(u32)code >> 5];
    u32 v = *w;
    u32 m = 1 << (code & 31);
    if (v & m) return;
    *w = v | m;
    if (func_001b8800(code)[1] == 1 && func_00181550()) return;
    q->queue[q->count++] = code;
}

extern f32 D_00349e14;
void func_0023aab8(u8*);
void func_00237ae8(u8*);
void func_0023acd8(u8* p)
{
    f32 d = D_00349e14 * *(f32*)(p + 68);
    *(f32*)(p + 256) += d;
    switch (*(s32*)(p + 252)) {
    case 1:
        *(f32*)(p + 260) = 0.0f;
        *(s32*)(p + 252) = 2;
        func_0023aab8(p);
        func_00237ae8(p);
        *(s32*)(p + 272) = 0;
        break;
    case 2:
        *(f32*)(p + 260) += d;
        if (*(f32*)(p + 264) <= *(f32*)(p + 260)) {
            *(s32*)(p + 272) = 0;
            *(f32*)(p + 260) = (f32)*(s32*)(p + 324);
            if (*(s32*)(p + 320)) {
                (*(s32*)(p + 320))--;
                (*(s32*)(p + 268))++;
                if (*(s32*)(p + 320) == 0) {
                    *(s32*)(p + 252) = 3;
                    *(f32*)(p + 260) = *(f32*)(p + 264) - 1.0f;
                    void (*cb)(u8*) = *(void (**)(u8*))(p + 236);
                    if (cb) cb(p);
                }
            }
        }
        func_0023aab8(p);
        func_00237ae8(p);
        break;
    case 0:
    default:
        return;
    }
    p[212] = 0;
}

struct Opt28 { u8 pad[8]; u8 text[8]; s8 def; u8 pad2; u16 id; u8 pad3[16]; };
extern Opt28 D_00372298[];
extern u32 D_0035edd0;
extern u32 D_0035edd4;
extern u32 D_0035edec;
void func_00288d80(u32, s32, s32, s32, u32, u16, Opt28*, u8*);
u8* func_002891b8(u32, s32);
u32 func_0023aa78(u8*);
u32 func_0023aa98(u8*);
void func_00288e08(u32, s32, u32, s32);
u32 func_0028dd90(u32);
u32 func_0028ddd8(u32);
void func_001395f8(u8*);
void func_002891f0(u32, s32, s32, s32, s32);
void func_002b4388(u32, Opt28*, s32);
void func_0024d348(void)
{
    s32 sel = 0;
    for (s32 i = 0; i < 2; i++) {
        Opt28* e = (Opt28*)((u8*)(i * 36) + (u32)D_00372298);
        if (e->def) sel = i;
        func_00288d80(D_0035edd0, i, 0, 0, D_0035edd4, e->id, e, (u8*)(i * 36) + (u32)D_00372298[0].text);
        u8* o = func_002891b8(D_0035edd0, i);
        func_00288e08(D_0035edd0, i, func_0023aa78(o + 24), 0);
        u32 x = func_0023aa98(o + 24);
        *(u32*)(o + 432) = func_0028dd90(x);
        *(u32*)(o + 428) = func_0028ddd8(x);
        func_001395f8(o);
    }
    func_002891f0(D_0035edd0, sel, 1, 0, 2);
    func_002b4388(D_0035edec, &D_00372298[sel], 0);
}

struct Sub30 { u8 pad[184]; u32 flags; void SetF() { flags |= 8; } };
struct Obj30 { u8 pad[24]; Sub30 sub; u8 pad2[405 - 24 - 188]; u8 on; u8 pad3[26]; void SetOn() { on = 1; } };
extern Obj30* D_0035ee70;
extern u32 D_0035ee60;
extern u8 D_00372608[];
extern u8 D_00372610[][8];
u8* func_001058e8(void);
s32 func_00252098(s32);
void func_0028b300(Obj30*, s32, s32, s32, u32, u8*, u8*, s32, s32);
void func_00252208(void)
{
    u32* bits = (u32*)(func_001058e8() + 18904);
    for (s32 i = 0; i < 4; i++) {
        if (!func_00252098(i)) continue;
        u32 b = i + 8;
        if (bits[b >> 5] & (1 << (b & 31))) continue;
        func_0028b300(&D_0035ee70[i], 30012, 2, 2, D_0035ee60, D_00372608, D_00372610[i], 23, 0);
        D_0035ee70[i].SetOn();
        Sub30* sb = &D_0035ee70[i].sub;
        sb->SetF();
    }
}

f32 func_002f8a18(f32);
f32 func_002f8870(f32);
// 002d1bf8: clamp v (relative to the camera at +208) inside the view frustum, with margins lo/hi
void func_002d1bf8(u8* cam, Vec4* v, f32* hi, f32* lo)
{
    Vec4* c = (Vec4*)(cam + 208);
    asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(v), "r"(c) : "memory");
    f32 h = func_002f8a18(*(f32*)(cam + 112) * 0.5f * 0.017453292f);
    h *= func_002f8870(v->z);
    f32 w = h * 4.0f / 3.0f;
    if (w - lo[0] < v->x) v->x = w - lo[0];
    if (v->x < hi[0] - w) v->x = hi[0] - w;
    if (h - lo[1] < v->y) v->y = h - lo[1];
    if (v->y < hi[1] - h) v->y = hi[1] - h;
    asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(v), "r"(c) : "memory");
}

struct VB36 {
    f32 x, y, z, w;
    VB36& operator=(const VB36& s) { if (this != &s) QCOPY(this, &s); return *this; }
    VB36 operator-(const Vec4& b) const
    {
        VB36 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                     : : "r"(this), "r"(&b), "r"(&r) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct B36 { f32 a, rad, c; u32 d; VB36 pos; };
struct It36 { u32 cur; u8 pad[28]; };
void func_00190128(It36*);
u8* func_0016bba8(u8*, s32, u8*);
void func_00190878(It36*, u8*, u8);
void func_002e9fe0(It36* it, u8* obj, Vec4* pos)
{
    B36 b;
    VB36 d;
    f32 best = 0.0f;
    u8* o = 0;
    b.d = 0;
    func_00190128(it);
    while ((o = func_0016bba8(obj, 3, o)) != 0) {
        func_0018a818((B32*)&b, obj, (u32)o);
        d = b.pos - *pos;
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0"
                     : "=f"(len) : "r"(&d) : "$8", "memory");
        f32 dist = len - b.rad;
        if (it->cur == 0 || dist < best) {
            best = dist;
            func_00190878(it, obj, *o);
        }
    }
}

// fdlibm __kernel_cosf
f32 func_002faaf0(f32 x, f32 y)
{
    union { f32 f; s32 i; } u;
    f32 a, hz, z, r, qx;
    s32 ix;
    u.f = x;
    ix = u.i & 0x7fffffff;
    if (ix < 0x32000000) {
        if ((s32)x == 0) return 1.0f;
    }
    z = x * x;
    r = z * (0.0416666642f + z * (-0.00138888881f + z * (2.48015858e-05f + z * (-2.75573115e-07f + z * (2.08757212e-09f + z * -1.13596476e-11f)))));
    if (ix < 0x3e99999a) {
        return 1.0f - (0.5f * z - (z * r - x * y));
    } else {
        if (ix > 0x3f480000) {
            qx = 0.28125f;
        } else {
            u.i = ix - 0x01000000;
            qx = u.f;
        }
        hz = 0.5f * z - qx;
        a = 1.0f - qx;
        return a - (hz - (z * r - x * y));
    }
}

struct Cam1 {
    u8 pad[1584];
    u32 on : 1;
    u32 rest : 31;
    u8 pad2[12];
    f32 ax, ay, pad3[2];
    f32 bx, by;
    bool On() { return on; }
};
// 00116798: keep the two (x, y) pairs inside their wrap ranges
void func_00116798(Cam1* p)
{
    if (!p->On()) return;
    if (p->ax < -400.0f && p->bx < -400.0f) {
        p->ax += 800.0f;
        p->bx += 800.0f;
    }
    if (400.0f < p->ax && 400.0f < p->bx) {
        p->ax -= 800.0f;
        p->bx -= 800.0f;
    }
    if (p->ay < -320.0f && p->by < -320.0f) {
        p->ay += 640.0f;
        p->by += 640.0f;
    }
    if (320.0f < p->ay && 320.0f < p->by) {
        p->ay -= 640.0f;
        p->by -= 640.0f;
    }
}

struct Anm3 { u8 pad[276]; s32 cur; };
struct Obj3 {
    void** vt;
    u8 pad[8];
    u32 flags;
    u8 pad2[8];
    Anm3 anm;
    u8 pad3[384 - 24 - 280];
    f32 speed;
    u8 pad4[4];
    s32 next;
    void* wait0;
    void* wait1;
    u8 dirty;
};
s32 func_00139d78(void*);
s32 func_00239d10(void*);
void func_00239eb8(Anm3*, f32);
s32 func_00239d30(Anm3*, s32);
void func_00138c10(Obj3*, s32);
void func_00139570(Obj3*);
static inline void Idle3(Obj3* p)
{
    if (p->flags & 0x80) func_00139570(p);
    else ((void (*)(Obj3*))p->vt[5])(p);
}
void func_00138840(Obj3* p) asm("_Z13func_00138840Pv");
void func_00138840(Obj3* p)
{
    if (p->flags & 0x100) return;
    if (!(p->flags & 0x800)) goto update;
    if (p->wait0 && !func_00139d78(p->wait0)) goto fin;
    if (!p->wait1 || func_00239d10(p->wait1)) goto update;
fin:
    Idle3(p);
    return;
update:
    Anm3* a = &p->anm;
    func_00239eb8(a, p->speed);
    func_0023acd8((u8*)a);
    if (p->dirty) p->dirty = 0;
    if ((u8)func_00239d30(a, a->cur)) return;
    if (func_00239d10(a)) return;
    if (p->next != -1) {
        func_00138c10(p, p->next);
        p->next = -1;
        func_0023acd8((u8*)a);
        p->dirty = 1;
        return;
    }
    Idle3(p);
}

extern u32 D_00347fec;
extern s32 D_00347ff0;
extern char D_003b8ba0[];
extern char D_0036acb0[];
extern char D_0036acd0[];
extern char* D_0033caf4;
extern u8 D_0032bae0;
extern u8 D_004193c0[];
s32 func_00242ea8(void);
s32 func_0014a1f0(void);
s32 func_00242c70(void);
s32 func_00194a08(void);
u32 func_00105ee8(u32);
void func_002fee78(char*, const char*, ...);
void func_002ff3fc(char*);
void func_001688c8(char*);
void func_001684c0(char*, u8*, s32, s32);
s32 func_0013a4c8(void)
{
    if (func_00242ea8()) return 0;
    if (func_0014a1f0()) return 0;
    if (!func_00242c70()) {
        if (!D_00347fec) return 0;
        D_00347fec = 0;
        D_00347ff0 = -1;
        func_002fee78(D_003b8ba0, D_0036acb0, D_0033caf4);
    } else {
        u32 room = D_0032bae0;
        s32 n = func_00194a08();
        if (room == D_00347fec && n == D_00347ff0) return 0;
        D_00347ff0 = n;
        D_00347fec = room;
        func_002fee78(D_003b8ba0, D_0036acd0, D_0033caf4, func_00105ee8(room), n);
    }
    func_002ff3fc(D_003b8ba0);
    func_001688c8(D_003b8ba0);
    func_001684c0(D_003b8ba0, D_004193c0, 0, 0);
    return 1;
}

extern u32 D_00348470[][3];
extern u32 D_00348440[][3];
u32 func_0013b808(u32, u32);
struct Fl6 { u16 on : 1; u16 rest : 15; u8 On() { return on; } };
void func_0013c080(u32 a0, Fl6* fl, u32 a2, s32 col, u8* changed, s32 row, u32* outA, u32* outB)
{
    if (fl->On()) {
        *outA = D_00348470[row][col];
        if (func_0013b808(a0, a2) != fl->on) {
            *outA = D_00348440[row][col];
            *outB = D_00348470[row][col];
            *changed = 1;
        }
    }
    if (func_0013b808(a0, a2)) {
        if (func_0013b808(a0, a2) != fl->on) *changed = 1;
    }
}

extern f32 D_00349e14;
void func_0014fcd8(u8*);
s32 func_00139538(u8*);
void func_00139510(u8*);
void func_0014b950(u8*, s32, s16, u32, s32);
void func_00138c40(u8*, s32, s32);
u32 func_0023aa98(u8*);
void func_00150b68(u8*);
struct NoTail7 { ~NoTail7() {} };
struct Fl7 { u32 busy : 1; u32 alt : 1; u32 rest : 30; };
struct Obj7 { u8 pad[972]; Fl7 fl; };
void func_00150a18(u8* p)
{
    NoTail7 nt;
    func_0014fcd8(p);
    u8* m = p + 48;
    if (func_00139538(m)) {
        (*(void (**)(u8*))(*(u8**)p + 20))(p);
        func_00139510(p + 560);
        ((Obj7*)p)->fl.busy = 0;
        return;
    }
    Obj7* o = (Obj7*)p;
    if (o->fl.busy) return;
    if (m[404] && !o->fl.alt) o->fl.alt = 1;
    if (!o->fl.alt) {
        func_0014b950(p + 496, 0, *(s16*)(p + 36), 1, 1);
    } else {
        func_0014b950(p + 496, 0, *(s16*)(p + 36), (u16)func_0023aa98(p + 72), 64);
        if (0.0f < *(f32*)(p + 976)) {
            *(f32*)(p + 976) -= D_00349e14;
        } else {
            if (--*(s32*)(m + 412) < *(s32*)(p + 968)) func_00150b68(p);
        }
    }
    func_00138c40(m, 0, *(s32*)(p + 36));
    func_00138c40(p + 560, 0, *(s32*)(p + 36));
}

extern f32 D_00349e10;
extern u8* D_00352130;
void func_00175af8(u8*);
void func_00179718(u8*);
s32 func_00197920(void);
s32 func_001917c0(void);
void func_001a1b68(u8*, f32);
void func_00179cb8(u8*);
s32 func_001b9d40(u8*);
void func_00178220(u8*);
void func_0017a3b0(u8*);
void func_00178758(u8* p)
{
    func_00175af8(p);
    func_00179718(p);
    if ((*(s32 (**)(u8*))(*(u8**)p + 64))(p) && *(u8**)(p + 1164) && !func_00197920()
        && (u32)((*(u8**)(p + 1164))[431] - 2) < 2) {
        f32 s = D_00349e10;
        if (!func_001917c0()) s *= *(f32*)(D_00352130 + 108);
        switch ((*(u8**)(p + 1164))[431]) {
        case 2:
            s *= *(f32*)(func_00177860(p) + 64);
            break;
        case 3:
            s *= *(f32*)(func_00177860(p) + 108);
            break;
        }
        func_001a1b68(*(u8**)(p + 1164), -s);
    }
    func_00179cb8(p);
    if (func_001b9d40(p)) {
        if (!(*(u32*)(p + 2040) & 0x20)) {
            func_00178220(p);
            *(u32*)(p + 2040) |= 0x20;
        }
        *(u32*)(p + 2888) = 0;
    }
    func_0017a3b0(p);
}

struct Ent13 { u32 key; union { s32 v; u16 sub; }; u32 a, b; };
struct Tbl13 { s32 n; Ent13 e[1]; };
u32 func_001ae210(u32);
u16 func_001ae270(u32);
Ent13* func_001ae308(Tbl13* t, u32 name)
{
    if (!t) return 0;
    u32 key = func_001ae210(name);
    s32 n = t->n;
    if (n <= 0) return 0;
    s32 lo = 0, hi = n - 1;
    Ent13* e;
    do {
        s32 mid = (lo + hi) / 2;
        e = &t->e[mid];
        if (e->key == key) break;
        if (e->key < key) lo = mid + 1;
        else hi = mid - 1;
    } while (hi - lo >= 0);
    if (e->key != key) e = 0;
    if (!e || e->v >= 0) return e;
    u16 sub = func_001ae270(name);
    if (e != &t->e[0]) {
        while (e[-1].key == key) e--;
    }
    while (e->key == key && e->sub != sub) e++;
    if (e->key != key || e->sub != sub) e = 0;
    return e;
}

extern u8 D_003511c2;
extern u8 D_003511c0;
struct Pkt15 { u64* start; u32 pad; u8* cur; };
s32 func_001b7fd0(Pkt15*);
u32 func_002f35e8(s32);
void func_002f3918(u32, u64*);
void func_003058a0(s32);
void func_002f25a0(s32, s32);
static inline u64 Tag15(s32 qwc, s32 irq)
{
    return (s64)qwc | (u64)(s64)irq << 63 | 0x70000000;
}
void func_001b80d8(Pkt15* p)
{
    u64* s = p->start;
    if (!s) return;
    u8* e = p->cur;
    if (!((u8*)s + 16 < e)) return;
    if (D_003511c2 == 1) {
        *s = Tag15(((e - (u8*)s) >> 4) - 1, func_001b7fd0(p) != 0);
    } else {
        *s = Tag15(((e - (u8*)s) >> 4) - 1, 0);
    }
    if (func_001b7fd0(p)) {
        func_002f3918(func_002f35e8(2), p->start);
        D_003511c0 = 1;
    } else {
        func_003058a0(0);
        func_002f3918(func_002f35e8(2), p->start);
        func_002f25a0(0, 0);
    }
}

extern u32 D_00351d98;
extern f32 D_0036dff0[];
extern f32 D_0036e030[];
extern u8 D_0036e000[][16];
void func_001a5420(u32, u8*, u32);
void func_001c7d90(u32 a0, f32 x)
{
    if (!D_00351d98) return;
    for (s32 i = 0; i < 3; i++) {
        s32 n = (s32)(x * D_0036dff0[i] / D_0036e030[i]);
        for (s32 j = 0; j < n; j++) func_001a5420(D_00351d98, D_0036e000[i], a0);
        x -= D_0036e030[i] * (f32)n;
    }
}

struct VB18 {
    f32 x, y, z, w;
    VB18& operator=(const VB18& s) { if (this != &s) QCOPY(this, &s); return *this; }
    VB18 operator-(const Vec4& b) const
    {
        VB18 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                     : : "r"(this), "r"(&b), "r"(&r) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct It18 { u8 d[80]; };
struct Pt18 { u8 pad[64]; VB18 rel; u32 pad2; void* fn; u8* owner; };
Vec4* func_0016c028(u8*);
void func_001c2858(It18*, Vec4*, u32, u32);
s32 func_001c28f8(It18*, VB18*, s32);
Pt18* func_001db888(u8*, s32, void*);
void func_001dbc58(Pt18*, u8*, VB18*, u32);
void func_001ce618();
void func_001ce508(u8* p, u32 a1, u32 a2)
{
    f32 life = 1.0f;
    It18 it;
    VB18 pos;
    func_001c2858(&it, func_0016c028(p), a1, a2);
    u8* pool = *(u8**)(*(u8**)(p + 2548) + 2548);
    while (func_001c28f8(&it, &pos, 1)) {
        Pt18* o = func_001db888(pool + 20, 96, __builtin_return_address(0));
        func_001dbc58(o, pool, &pos, *(u32*)(p + 2552));
        o->rel = pos - *func_0016c028(p);
        o->rel.w = life;
        o->owner = p;
        o->fn = (void*)func_001ce618;
    }
}

extern u8 D_01d5baa0[5];
extern u32 D_003638d0;
s32 func_001d9af8(void);
u64 func_00312db8(u64, u64);
s32 func_001d9c68(u8*);
void func_001d9ad8(s32);
bool func_001d9b40(void)
{
    s32 k = func_001d9af8();
    bool r = D_01d5baa0[k] == 2;
    D_01d5baa0[k] = 1;
    u8 buf[5];
    s32 n = 0;
    for (s32 i = 0; i < 5; i++) {
        if (!D_01d5baa0[i]) buf[n++] = i;
    }
    if (n > 0) {
        u32 seed = D_003638d0 *= 0x10dcd;
        u64 step = func_00312db8((u32)(n - 1) + 0x100000000ULL, (u32)n);
        D_01d5baa0[(s8)buf[(s32)func_00312db8(seed, step)]] = 2;
    }
    if (func_001d9c68(D_01d5baa0)) func_001d9ad8(k);
    return r;
}

extern f32 D_00354be0[3];
extern u8 D_01d9e730[];
extern u8 D_01d9e8c0[];
void func_002f4000(f32 (*)[4]);
void func_002f40a0(f32 (*)[4], f32 (*)[4], f32);
void func_002f3f88(f32*, u8*);
void func_002f3cd8(f32*, u8*, f32*);
void func_002f3d08(f32 (*)[4], u8*, f32 (*)[4]);
f32 func_0020aec8(u32 a0, f32 (*m)[4], u8* a2, u32 a3, u8* s)
{
    func_002f4000(m);
    m[0][0] = *(f32*)(s + 56) * D_00354be0[0];
    m[1][1] = *(f32*)(s + 60) * D_00354be0[1];
    m[2][2] = *(f32*)(s + 56) * D_00354be0[0];
    if (*(f32*)(s + 44) != 0.0f) func_002f40a0(m, m, *(f32*)(s + 44) * 3.14159274f / 180.0f);
    func_002f3f88(m[3], s);
    func_002f3cd8(m[3], D_01d9e730, m[3]);
    f32 z = m[3][2];
    m[3][1] *= *(f32*)(a2 + 164);
    m[3][1] += *(f32*)(a2 + 168);
    func_002f3d08(m, D_01d9e8c0, m);
    return z;
}

extern u8 D_0035eaf8[];
void func_00237068(void*);
struct Obj20 {
    void* vt;
    u8 base[172];
    u32 f176, f180;
    u32 b0 : 1, b1 : 1, b2 : 1, b3 : 1, b4 : 1, b5 : 1, b6 : 1, b7 : 1, b8 : 1, b9 : 1, b10 : 1, b11 : 1, b12 : 1, b13 : 1, rest : 18;
    u8 f188;
    u32 f192, f196, f200, f204, f208;
    u8 f212;
    u32 f216, f220, f224, f228, f232, f236, f240, f244, f248, f252, f256, f260, f264, f268, f272, f276, f280, f284, f288;
    u32 f292, f296, f300, f304, f308, f312, f316, f320, f324, f328, f332;
};
// 002395b8: constructor (base init, then clear all state)
void func_002395b8(Obj20* p)
{
    func_00237068(p);
    p->f176 = 0;
    p->f180 = 0;
    p->b0 = 0;
    p->b1 = 0;
    p->f188 = 0;
    p->b2 = 0;
    p->f192 = 0;
    p->f196 = 0;
    p->b3 = 0;
    p->f200 = 0;
    p->f204 = 0;
    p->b4 = 0;
    p->f208 = 0;
    p->f212 = 0;
    p->b5 = 0;
    p->f216 = 0;
    p->f220 = 0;
    p->b6 = 0;
    p->f224 = 0;
    p->f228 = 0;
    p->b7 = 0;
    p->f232 = 0;
    p->f236 = 0;
    p->b8 = 0;
    p->f240 = 0;
    p->f244 = 0;
    p->b9 = 0;
    p->f248 = 0;
    p->f252 = 0;
    p->b10 = 0;
    p->f256 = 0;
    p->f260 = 0;
    p->b11 = 0;
    p->f264 = 0;
    p->f268 = 0;
    p->b12 = 0;
    p->f272 = 0;
    p->f276 = 0;
    p->b13 = 0;
    p->f280 = 0;
    p->f284 = 0;
    p->f288 = 0;
    *(u32*)&p->vt = (u32)D_0035eaf8;
    p->f292 = 0;
    p->f296 = 0;
    p->f300 = 0;
    p->f304 = 0;
    p->f308 = 0;
    p->f312 = 0;
    p->f316 = 0;
    p->f320 = 0;
    p->f324 = 0;
    p->f328 = 0;
    p->f332 = 0;
}

struct Snd23 {
    u8 pad[24];
    u32 bank;
    u32 voice;
    u32 f32_;
    s32 f36;
    u8 pad2[4];
    s16 ids[3];
    s16 sel[3];
    s16 cur;
    u8 pad3[2];
    u32 color;
    s32 len;
    u32 f68;
};
void func_001391c8(Snd23*, u32, u32);
void func_0023f778(Snd23*, u32);
void func_0023f7a8(Snd23*, u32);
u8* func_0023f1b0(u32);
u32 func_0023c3e0(u8*, s16, s32);
void func_0023f5b8(Snd23*, u32, u32);
s32 func_0023aa58(u32);
void func_0023f6c0(Snd23*, s32);
void func_0023f688(Snd23*, s32);
void func_0023f740(Snd23*, u32);
void func_001395e8(Snd23*);
void func_00139610(Snd23*);
void func_00139638(Snd23*);
void func_0023f1e0(Snd23* p, u32 a1, u32 bank, u32 a3, u32 t0, u32 t1, u32 t2, u32 t3)
{
    func_001391c8(p, a1, t3);
    p->bank = bank;
    func_0023f778(p, a3);
    func_0023f7a8(p, t0);
    s32 id = *(s32*)(func_0023f1b0(p->bank) + 76);
    p->voice = 0;
    for (s32 i = 0; i < 3; i++) {
        if (id == p->ids[i]) p->voice = func_0023c3e0(func_0023f1b0(p->bank), p->sel[i], 0);
    }
    p->cur = id;
    p->f36 = -1;
    p->f32_ = 0;
    func_0023f5b8(p, t1, t2);
    p->color = 0x80e5e5e5;
    s32 n = func_0023aa58(p->voice);
    p->len = n > 0 ? n : 15;
    func_0023f6c0(p, 0);
    func_0023f688(p, 1);
    p->f68 = 0;
    func_0023f740(p, func_0023aa78((u8*)p->voice));
    func_001395e8(p);
    func_00139610(p);
    func_00139638(p);
}

extern Opt28 D_00372548[];
extern u32 D_0035ee38;
extern u32 D_0035ee3c;
extern u32 D_0035ee4c;
void func_00288d80(u32, s32, s32, s32, u32, u16, Opt28*, u8*);
u8* func_002891b8(u32, s32);
u32 func_0023aa78(u8*);
u32 func_0023aa98(u8*);
void func_00288e08(u32, s32, u32, s32);
u32 func_0028dd90(u32);
u32 func_0028ddd8(u32);
void func_001395f8(u8*);
void func_002891f0(u32, s32, s32, s32, s32);
void func_002b4388(u32, Opt28*, s32);
void func_0024fbd0(void)
{
    s32 sel = 0;
    for (s32 i = 0; i < 2; i++) {
        Opt28* e = (Opt28*)((u8*)(i * 36) + (u32)D_00372548);
        if (e->def) sel = i;
        func_00288d80(D_0035ee38, i, 0, 0, D_0035ee3c, e->id, e, (u8*)(i * 36) + (u32)D_00372548[0].text);
        u8* o = func_002891b8(D_0035ee38, i);
        func_00288e08(D_0035ee38, i, func_0023aa78(o + 24), 0);
        u32 x = func_0023aa98(o + 24);
        *(u32*)(o + 432) = func_0028dd90(x);
        *(u32*)(o + 428) = func_0028ddd8(x);
        func_001395f8(o);
    }
    func_002891f0(D_0035ee38, sel, 1, 0, 2);
    func_002b4388(D_0035ee4c, &D_00372548[sel], 0);
}

extern u32 D_0035eea4;
extern s16 D_0035eea0;
extern s16* D_0035ee9c;
extern u8* D_0035eea8;
s16 func_0023f0c0(u32);
s32 func_00139d78(void*);
struct Obj3;
void func_00138c10(Obj3*, s32);
void func_0028d980(u8*, s32, s32, s32, u32, s32, s32, s32, s32);
u32 func_0023aa98(u8*);
u32 func_0028dd90(u32);
s32 func_00192048(s32);
void func_00252e50(void)
{
    s16 v = func_0023f0c0(D_0035eea4);
    s32 idx = -1;
    for (s32 i = 0; i < D_0035eea0; i++) {
        if (v == D_0035ee9c[i]) {
            idx = i;
            break;
        }
    }
    if (idx == D_0035eea0 - 2) {
        func_00139d78(D_0035eea8);
        func_00138c10((Obj3*)D_0035eea8, 15);
        *(s32*)(D_0035eea8 + 392) = -1;
        return;
    }
    s32 code = idx >= D_0035eea0 - 4 ? 4101 : 4100;
    if (!func_00139d78(D_0035eea8)) {
        func_0028d980(D_0035eea8, 30012, 0, 0, D_0035eea4, 13, 14, code, 0);
        u32 x = func_0023aa98(D_0035eea8 + 24);
        u8* o = D_0035eea8;
        *(u32*)(o + 432) = func_0028dd90(x);
    } else if (func_00139d78(D_0035eea8)) {
        s32 r = func_00192048(code);
        if (*(s32*)(D_0035eea8 + 408) != r) *(s32*)(D_0035eea8 + 408) = r;
    }
}

extern u8* D_0035f0f4;
extern u32 D_0035ef68;
extern u32 D_0035ef64;
extern u32 D_0035f03c;
s32 func_00139d78(void*);
u32 func_00256b68(s32);
s32 func_00287bc0(void);
s32 func_0028d008(u32);
void func_0028d8c0(u8*, s32, u32, u32, u32, s32, s32, s32);
void func_0028dcc0(u8*, u32);
u8* func_0028d0e0(u32);
void func_00138c78(u32, u32*, u32*);
void func_00138c68(u8*, u32, u32);
void func_00139510(u8*);
void func_0026d620(u32 w, u8 sync)
{
    s32 busy = func_00139d78(D_0035f0f4);
    u32 snd = func_00256b68(1);
    func_00287bc0();
    u32 a, b;
    if (func_0028d008(w)) {
        if (!busy) {
            func_0028d8c0(D_0035f0f4, 30015, D_0035ef68, D_0035ef64, D_0035f03c, 317, -1, 0);
            func_0028dcc0(D_0035f0f4, snd);
            func_00138c78(*(u32*)(func_0028d0e0(w) + 396), &a, &b);
            func_00138c68(D_0035f0f4, a, b);
        }
        if (sync) {
            func_00138c78(*(u32*)(func_0028d0e0(w) + 396), &a, &b);
            func_00138c68(D_0035f0f4, a, b);
        }
    } else if (busy) {
        func_00139510(D_0035f0f4);
    }
}

extern u8* D_0035f5bc;
s32 func_00287bc0(void);
void func_00274ac8(void);
void func_0028f7e8(s32);
void func_0029ac00(void);
u8* func_00287dc0(void);
s32 func_00139d78(void*);
void func_0023d820(u8*);
void func_0029e9d0(void);
void func_0029aac0(s32 k)
{
    s32 v = func_00287bc0();
    if (!((u32)(v - 14) < 2 || v == 18 || v == 21 || v == 16 || v == 19 || v == 22 || v == 17 || v == 20 || v == 23)) return;
    func_00274ac8();
    if (!((u32)(k - 14) < 2 || k == 18 || k == 21 || k == 16 || k == 19 || k == 22)) func_0028f7e8(0);
    if (!((u32)(k - 15) < 2 || k == 18 || k == 21)) func_0028f7e8(1);
    func_0029ac00();
    u8* o = func_00287dc0();
    if (func_00139d78(o)) func_0023d820(o);
    if (func_00139d78(D_0035f5bc)) func_0023d820(D_0035f5bc);
    func_0029e9d0();
}

struct VB30 {
    f32 x, y, z, w;
    VB30& operator=(const VB30& s) { if (this != &s) QCOPY(this, &s); return *this; }
    VB30 operator-(const VB30& b) const
    {
        VB30 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                     : : "r"(this), "r"(&b), "r"(&r) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
union UD30 { u32 u; u8* p; VB30* v; };
struct B30 { f32 a, rad, c; UD30 d; VB30 pos; };
void func_0018a818(B32*, u8*, u32);
s32 func_0019ba60(u8*);
u8* func_0016bba8(u8*, s32, u8*);
struct Find30 { s32 idx; VB30* target; };
void func_002e7d20(Find30* f)
{
    f32 best = 0.0f;
    s32 idx = -1;
    u8* obj = *(u8**)(*(u8**)f + 4);
    VB30* t = f->target;
    VB30 d;
    B30 b;
    b.d.u = 0;
    func_0019ba60(obj);
    u8* o = 0;
    while ((o = func_0016bba8(obj, 2, o)) != 0) {
        func_0018a818((B32*)&b, obj, (u32)o);
        d = *t - b.pos;
        f32 l2;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
                     : "=f"(l2) : "r"(&d) : "$8", "memory");
        d.w = l2;
        if (idx < 0 || l2 < best) {
            best = l2;
            idx = o[1];
        }
    }
    f->idx = idx;
}

union UD16 { u32 u; f32 f; };
struct B16 { f32 a, y, c; UD16 d; f32 pos[4]; };
struct Fx16 { f32 t; u32 id; u8 pad[8]; u32 target; };
extern f32 D_00349e10;
void func_001ba340(Fx16*);
u8* func_001a80c8(u32);
void func_001ba528(Fx16*, u16, u32);
void func_001ba598(Fx16*);
u8* func_00176b20(s32);
s32 func_0019ba60(u8*);
u32 func_0016a070(u8*);
s32 func_001ba408(Fx16* p)
{
    B16 b;
    f32 t = p->t;
    b.d.u = 0;
    if (30.0f <= t) func_001ba340(p);
    p->t -= D_00349e10;
    if (p->t <= 0.0f) {
    u8* d = func_001a80c8(p->id);
    if (p->target) {
        func_001ba528(p, *(u16*)(d + 6), p->target);
    } else {
        for (s32 i = 0; i < 3; i++) {
            u8* o = func_00176b20(i);
            if (func_0019ba60(o) && !(*(u32*)(o + 1416) & 0x400000))
                func_001ba528(p, *(u16*)(d + 6), func_0016a070(o));
        }
    }
    func_001ba598(p);
    return 0;
    }
    return 1;
}

struct Task2 { s32 state; u8 pad[36]; u32 flags; u8 pad2[12]; Task2* next; };
struct Mgr2 { u8 pad[8]; Task2* head; u8 pad2[4]; Task2* cur; u8 pad3[252]; Task2* it; };
union UT2 { Task2* p; u8 c; };
extern UT2 D_0032b940;
void func_00102350(Task2*);
void func_001025f8(Mgr2*, Task2*);
static inline Task2* Next2(Mgr2* m, Task2* t, u32 mask, u32 val)
{
    do {
        t = !t ? m->head : t->next;
    } while (t && (t->flags & mask) != val);
    return t;
}
void wtarget_001028b0(Mgr2* m, u32 mask, u32 val) asm("_Z16wtarget_001028b0jjjj");
void wtarget_001028b0(Mgr2* m, u32 mask, u32 val)
{
    Task2* t = Next2(m, 0, mask, val);
    while (t) {
        m->it = Next2(m, t, mask, val);
        Task2* saved = D_0032b940.p;
        D_0032b940.p = t;
        m->cur = t;
        func_00102350(t);
        D_0032b940.p = saved;
        m->cur = 0;
        if (!t->state) func_001025f8(m, t);
        Task2* n = m->it;
        if (n && (n->flags & mask) != val) {
            n = Next2(m, n, mask, val);
            m->it = n;
        }
        t = n;
    }
}

struct VObj5 { void** vt; };
struct Snd5 { u32 a; VObj5* dev; u8 pad[128]; u32 h; };
extern void* D_00348814;
extern void* D_00348810;
extern void* D_0034880c;
extern void* D_00348808;
extern Snd5* D_00348818;
extern void* D_00348804;
extern u8* D_00348800;
void func_0014eda8(void);
void func_001537f8(void);
void func_00106420(void*);
void func_00145ab8(u8*);
void func_00142f50(void)
{
    func_0014eda8();
    func_001537f8();
    if (D_00348814) { func_00106420(D_00348814); D_00348814 = 0; }
    if (D_00348810) { func_00106420(D_00348810); D_00348810 = 0; }
    if (D_0034880c) { func_00106420(D_0034880c); D_0034880c = 0; }
    if (D_00348808) { func_00106420(D_00348808); D_00348808 = 0; }
    if (D_00348818) {
        Snd5* s = D_00348818;
        ((void (*)(VObj5*, u32, u32))s->dev->vt[10])(s->dev, s->h, s->a);
        func_00106420(s);
        D_00348818 = 0;
    }
    if (D_00348804) { func_00106420(D_00348804); D_00348804 = 0; }
    u8* o = D_00348800;
    if (o) {
        func_00145ab8(o);
        func_00106420(o);
        D_00348800 = 0;
    }
}

struct Node6 { u8 pad[236]; Node6* sib; Node6* child; u8 pad2[4]; u32 flags; u8 pad3[28]; s16 h280; s16 h282; };
struct St6 { u32 f; u32 pad; };
struct Tree6 { u8 pad[17252]; St6 st[511]; u8 pad2[21344 - 17252 - 4088]; s32 cur; };
s32 func_00146ed8(Tree6*, Node6*);
void func_00147140(Tree6*, Node6*);
void func_00146e28(Tree6*, Node6*);
void wtarget_00146f28(Tree6* t, Node6* n, u8 flag) asm("_Z16wtarget_00146f28jjjj");
static inline __attribute__((always_inline)) u32* StP6(Tree6* t, s32 i) { return &t->st[i].f; }
#define ST6(t) (*StP6((t), (t)->cur))
void wtarget_00146f28(Tree6* t, Node6* n, u8 flag)
{
    u32 fl = n->flags;
    if (fl & 4) goto on;
    if (!(fl & 8)) goto kids;
on:
    if ((fl & 0x1000) || func_00146ed8(t, n)) {
        if (!flag) goto clr;
        ST6(t) |= 2;
    } else {
        if (!flag) goto clr;
        ST6(t) |= 2;
        func_00147140(t, n);
        goto done;
    }
    goto zero;
clr:
    ST6(t) &= ~2;
zero:
    n->h282 = 0;
    n->h280 = 0;
done:
    func_00146e28(t, n);
kids:
    Node6* c = 0;
    while ((c = !c ? n->child : c->sib) != 0) wtarget_00146f28(t, c, 0);
}

struct Pg7 { u8 pad[15552]; s32 total; s32 count; s32 last; u8 pad2[4]; s32 page; s32 n0; s32 n1; s32 n2; u8 pad3; u8 one; };
void func_00139948(s32);
s32 func_00154910(Pg7*);
s32 func_00154930(Pg7*);
void func_00139598(u8*);
void func_001544b0(Pg7*);
void func_001547e0(Pg7*, s32, s32);
void func_001548a8(Pg7*, s32);
void func_00154950(Pg7* p)
{
    func_00139948(6);
    s32 c = p->count;
    p->page = (c - 1) / 200;
    p->n0 = c - p->page * 200;
    s32 a = func_00154910(p);
    p->n2 = p->total - a * 200;
    s32 b = func_00154930(p);
    p->n1 = p->last - b * 200;
    if (p->n2 > p->n0) p->n0 = 200;
    if (p->page != a) p->n0 = 200;
    if (b != a) p->n1 = 200;
    p->one = 0;
    if (a == p->page && a != 0) p->one = 1;
    if (!p->one) func_00139598((u8*)p + 456);
    func_001544b0(p);
    func_001547e0(p, p->n0, 2);
    func_001547e0(p, p->n1, 4);
    func_001547e0(p, p->n2, 5);
    func_001548a8(p, b);
}

} // extern "C"
