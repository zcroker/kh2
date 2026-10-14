#include "../common/types.h"
#include <stdarg.h>

// 128-bit copies (lq/sq) are hand-written asm in the original.
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
// Same, but in a noreorder region so gas doesn't move the sq into a following branch delay slot.
#define QCOPYN(d, s) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(d), "r"(s) : "$8", "memory")

struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));

struct HeapE;
void* operator new[](unsigned int, HeapE*) asm("func_001063f0");

extern "C" {

struct Rec20 { u32 w[5]; };
u32 func_0010f8c0(u32 a0);  // test_field2940_bit2
void func_0010f880(f32 a0, f32 a1, u32 a2);
u32 func_0010f8e0(u32 a0);  // get_bit3_of_field2940
f32 func_0010f8a8(u32 a0);  // get_float_3284
u32 func_0010ef48(u32 a0);
u32 func_0010f9e0(u32 a0, u32 a1);
u32 func_0010cc80(u32 a0);
u8* func_0010cc70(u32 a0);
void func_0016b010(u32, Vec4*);  // obj_set_float1644_from_pair
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
        if (func_0010f8c0(*(u32*)(param_1 + 4)) != 0) {  // test_field2940_bit2
            if (func_0010f8e0(*(u32*)(param_1 + 4)) != 0) {  // get_bit3_of_field2940
                return 0;
            }
            if (func_0010f8a8(*(u32*)(param_1 + 4)) <= 0.0f) {  // get_float_3284
                return 0;
            }
        } else if (func_0010f9e0(*(u32*)(param_1 + 4), param_2) != 0) {
            return 0;
        }
        return (u8)(func_0010ef48(*(u32*)(param_1 + 4)) ^ 1);
    }

    if (func_0010f8c0(*(u32*)(param_1 + 4)) == 0) {  // test_field2940_bit2
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
        func_0016b010(*(u32*)(param_1 + 4), &v);  // obj_set_float1644_from_pair
    }
    func_0016af58(&v, *(u8**)(param_1 + 4));
    *(u32*)&v.w = 0;
    func_0010f9f0(*(u32*)(param_1 + 4), &v, 0);
    return 1;
}

typedef s32 (*Fn5)(void*, void*, u32, void*, u32, u32, u8, u32);
struct Obj5 { void** vt; };
s32 func_00132338(u8*);  // get_field8
void func_00132cb8(u8*);
u8* func_00132350(u8*);
s32 func_0011c8f8(u8* p, u8* a1, u8 flag, Obj5* o, u32 a4, u32 a5)
{
    s32 r = ((Fn5)o->vt[19])(o, p + 64, a4, a1, a5, *(u32*)(p + 56), flag, *(u32*)(a1 + 52));
    if (!flag && (*(u32*)(p + 12) & 2))
        ((Fn5)o->vt[21])(o, p + 64, a4, a1, a5, *(u32*)(p + 56), 0, *(u32*)(a1 + 52));
    if (r || flag) {
        for (u8* q = *(u8**)(p + 56); q; q = func_00132350(q)) {
            if (func_00132338(q) == 1) func_00132cb8(q);  // get_field8
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
void func_00177a28(u8*);  // set_bytes_2820_2821
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
        func_00177a28(p);  // set_bytes_2820_2821
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
u32 func_001de168(u32*, s32, s32, s32, s32, s32);  // scan_list_by_half
Vec4* func_001dc5f8(u32);
Vec4* func_0016c028(u8*);  // obj_get_attach_or_alt
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
                    h = *(u32*)(p + 2912) = func_001de168(o, k, 1, 2, 10001, 0);  // scan_list_by_half
                    goto have;
                }
            }
            h = *(u32*)(p + 2912);
        have:
            if (!h) return;
        }
        Vec4* d = func_001dc5f8(h);
        Vec4* s = func_0016c028(p);  // obj_get_attach_or_alt
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
f32 func_002f8870(f32);  // fabsf
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
        if (func_002f8870(p->pos.x) < 100000000.0f && func_002f8870(p->pos.y) < 100000000.0f && func_002f8870(p->pos.z) < 100000000.0f) {  // fabsf
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
Vec4* func_0016c028(u8*);  // obj_get_attach_or_alt
void func_00143928(Ray12*);
static inline void Copy12(Vec4* d, Vec4* s)
{
    if (d != s) QCOPY(d, s);
}
s32 func_00185138(u8* p, Vec4* out, u8 flag, f32 dist)
{
    Ray12 r;
    func_00319e90(&r, p + 1424);
    Copy12(&r.a, func_0016c028(p));  // obj_get_attach_or_alt
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
u32 func_0014abe8(void);  // get_data_3595a0
u32 func_0014abf8(void);  // get_data_3596b0
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
u8* func_00168b88(u32, s32, u32, s32);  // find_entry16_by_half_word
void func_001bdb70(u8*, s32, u32, u32, u8*);
void func_0019d720(u8*);
#define ID4(s) ((s)[0] | ((s)[1] << 8) | ((s)[2] << 16) | ((s)[3] << 24))
void set_special_command(u8* self, s32 cmd) asm("_ZN2YS6STDOBJ19set_special_commandEi");
void set_special_command(u8* self, s32 cmd)
{
    wtarget_00198970(self);
    u8* sub = self + 1952;
    u8* r1 = func_00168b88(*(u32*)(sub + 16), 24, ID4(D_0036d0c8), 0);  // find_entry16_by_half_word
    u32 h = *(u32*)(sub + 16);
    u32 a = *(u32*)(r1 + 8);
    u8* r2 = func_00168b88(h, 25, ID4(D_0036d0c8), 0);  // find_entry16_by_half_word
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
void func_001ae678(void);  // to_306698_arg10
s32 func_002f7dc8(void);
u32 func_001ae0a0(u32 a0, u32 a1, u32 a2, u16 a3)
{
    u8* h = func_001ae460(a0);
    if (!h) return 0;
    u8* tbl = func_001ae010(a0) ? D_00350ca8 : D_00350ca0;
    for (;;) {
        if (func_002f79c8(1) != 2 || func_002f7be8(*(u32*)(h + 8) + a2, a3, a1, tbl) != 1) {
            func_001ae678();  // to_306698_arg10
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
u32 func_0028dd90(u32);  // mod10_classify_012
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
f32 func_002f8870(f32);  // fabsf
// 002d1bf8: clamp v (relative to the camera at +208) inside the view frustum, with margins lo/hi
void func_002d1bf8(u8* cam, Vec4* v, f32* hi, f32* lo)
{
    Vec4* c = (Vec4*)(cam + 208);
    asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(v), "r"(c) : "memory");
    f32 h = func_002f8a18(*(f32*)(cam + 112) * 0.5f * 0.017453292f);
    h *= func_002f8870(v->z);  // fabsf
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
void func_002ff3fc(char*);  // strlen
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
    func_002ff3fc(D_003b8ba0);  // strlen
    func_001688c8(D_003b8ba0);
    func_001684c0(D_003b8ba0, D_004193c0, 0, 0);
    return 1;
}

extern u32 D_00348470[][3];
extern u32 D_00348440[][3];
u32 func_0013b808(u32, u32);  // entry168_by_index
struct Fl6 { u16 on : 1; u16 rest : 15; u8 On() { return on; } };
void func_0013c080(u32 a0, Fl6* fl, u32 a2, s32 col, u8* changed, s32 row, u32* outA, u32* outB)
{
    if (fl->On()) {
        *outA = D_00348470[row][col];
        if (func_0013b808(a0, a2) != fl->on) {  // entry168_by_index
            *outA = D_00348440[row][col];
            *outB = D_00348470[row][col];
            *changed = 1;
        }
    }
    if (func_0013b808(a0, a2)) {  // entry168_by_index
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
s32 func_001b9d40(u8*);  // vtable_call_slot64_flags
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
    if (func_001b9d40(p)) {  // vtable_call_slot64_flags
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
Vec4* func_0016c028(u8*);  // obj_get_attach_or_alt
void func_001c2858(It18*, Vec4*, u32, u32);  // copy_2quads_and_ratio
s32 func_001c28f8(It18*, VB18*, s32);
Pt18* func_001db888(u8*, s32, void*);  // record_index_calc
void func_001dbc58(Pt18*, u8*, VB18*, u32);
void func_001ce618();
void func_001ce508(u8* p, u32 a1, u32 a2)
{
    f32 life = 1.0f;
    It18 it;
    VB18 pos;
    func_001c2858(&it, func_0016c028(p), a1, a2);  // copy_2quads_and_ratio
    u8* pool = *(u8**)(*(u8**)(p + 2548) + 2548);
    while (func_001c28f8(&it, &pos, 1)) {
        Pt18* o = func_001db888(pool + 20, 96, __builtin_return_address(0));  // record_index_calc
        func_001dbc58(o, pool, &pos, *(u32*)(p + 2552));
        o->rel = pos - *func_0016c028(p);  // obj_get_attach_or_alt
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
void func_002f4000(f32 (*)[4]);  // vu_store_w_splat
void func_002f40a0(f32 (*)[4], f32 (*)[4], f32);
void func_002f3f88(f32*, u8*);  // memcpy16
void func_002f3cd8(f32*, u8*, f32*);
void func_002f3d08(f32 (*)[4], u8*, f32 (*)[4]);
f32 func_0020aec8(u32 a0, f32 (*m)[4], u8* a2, u32 a3, u8* s)
{
    func_002f4000(m);  // vu_store_w_splat
    m[0][0] = *(f32*)(s + 56) * D_00354be0[0];
    m[1][1] = *(f32*)(s + 60) * D_00354be0[1];
    m[2][2] = *(f32*)(s + 56) * D_00354be0[0];
    if (*(f32*)(s + 44) != 0.0f) func_002f40a0(m, m, *(f32*)(s + 44) * 3.14159274f / 180.0f);
    func_002f3f88(m[3], s);  // memcpy16
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
void func_0023f778(Snd23*, u32);  // copy_3halfwords_44
void func_0023f7a8(Snd23*, u32);  // copy_3halfwords_50
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
    func_0023f778(p, a3);  // copy_3halfwords_44
    func_0023f7a8(p, t0);  // copy_3halfwords_50
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
u32 func_0028dd90(u32);  // mod10_classify_012
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
u32 func_0028dd90(u32);  // mod10_classify_012
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
void func_001ba340_x1290(Fx16*) asm("func_001ba340");
u8* func_001a80c8(u32);  // table24_find_by_id
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
    if (30.0f <= t) func_001ba340_x1290(p);
    p->t -= D_00349e10;
    if (p->t <= 0.0f) {
    u8* d = func_001a80c8(p->id);  // table24_find_by_id
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
void func_00102350_x1325(Task2*) asm("func_00102350");
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
        func_00102350_x1325(t);
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

struct Sub4 { u8 pad[396]; void* owner; s32 f400; };
extern f32 D_00349e14;
void func_00139598(u8*);
s32 func_001b1fc8(s32);
u32 func_001b1ff0(s32);
u32 func_001b1e70(void);
void func_00138650(u8*, s32, u32, s32);
void func_001386e0(Sub4*, s32, u32, u8*, s32, s32);
void func_00236410(u8*, s32);  // obj_set4_then_call
void func_00236428(u8*, s32);  // obj_set32_then_call
void func_002367c8(u8*);  // obj_dispatch_bitfield64
void func_001396b0(Sub4*);
void func_0031a260(Sub4*, s32);
void func_002ba2e8(s32, s32);
void func_001395a8(u8*);
void func_00138840__43679(u8*) asm("func_00138840");
void func_001376b8(u8* p)
{
    if (0.0f < *(f32*)(p + 436)) {
        *(f32*)(p + 436) -= D_00349e14;
        func_00139598(p);
        return;
    }
    if (*(s32*)(p + 440) != -1 && !*(u32*)(p + 1304)) {
        if (!func_001b1fc8(*(s32*)(p + 440))) {
            func_00139598(p);
            return;
        }
        u8* w = p + 480;
        *(u32*)(p + 1304) = func_001b1ff0(*(s32*)(p + 440));
        u32 h = func_001b1e70();
        func_00138650(p + 448, 11100, *(u32*)(p + 1304), 0);
        func_001386e0((Sub4*)(p + 896), 11100, h, w, 6, 0);
        func_00236410(w, 14080);  // obj_set4_then_call
        func_00236428(w, 10752);  // obj_set32_then_call
        func_002367c8(w);  // obj_dispatch_bitfield64
        Sub4* s = (Sub4*)(p + 896);
        s->owner = p;
        func_001396b0(s);
        if (s->owner) {
            s->f400 = 0;
            func_001396b0(s);
            if (s->f400) func_0031a260(s, 0);
        }
    }
    if (-20000.0f < *(f32*)(p + 436)) {
        func_002ba2e8(10, 0);
        *(f32*)(p + 436) = -20000.0f;
    }
    func_001395a8(p);
    func_00138840__43679(p);
}

typedef unsigned int u128 __attribute__((mode(TI)));
struct Mtx5 { u128 r[4]; };
struct Hdr5 { u8 pad[24]; u32 o24, n28, o32, n36, o40, n44, o48, n52, o56, n60, o64, n68, o72, n76; };
struct Mdl5 {
    u32 h;
    u32 p4, p8, p12, p16, p20, p24, p28;
    u32 n32, n36, n40, n44, n48, n52, n56, f60, f64, f68;
    u8 pad[136];
    u8 b208, b209, b210, b211;
    u32 f212, f216, f220;
};
void func_00141850(Mdl5*, u32);
void func_0011b6a8(Mtx5*);
void func_00142940(Mdl5*, Mtx5*);
void func_00141808(Mdl5*);
void func_001415e8(Mdl5* m, u32 hp, u32 a2)
{
    Hdr5* h = (Hdr5*)hp;
    m->p4 = 0;
    m->p8 = 0; m->p12 = 0; m->p16 = 0; m->p20 = 0; m->p24 = 0; m->p28 = 0;
    m->n32 = 0; m->n36 = 0; m->n40 = 0; m->n44 = 0; m->n48 = 0; m->n52 = 0; m->n56 = 0;
    m->f60 = 0; m->f64 = 0; m->f68 = 0;
    m->b208 = 0; m->b209 = 0; m->b210 = 0; m->b211 = 0;
    m->f212 = 0; m->f216 = 0; m->f220 = 0;
    m->h = hp;
    m->p4 = (u32)h + h->o24;
    m->p8 = (u32)h + h->o32;
    m->p12 = (u32)h + h->o40;
    m->p16 = (u32)h + h->o48;
    m->p24 = (u32)h + h->o56;
    m->p28 = (u32)h + h->o64;
    m->p20 = (u32)h + h->o72;
    m->n32 = h->n28 / 32;
    m->n36 = h->n36 / 20;
    m->n40 = h->n44 / 16;
    m->n44 = h->n52 / 16;
    m->n52 = h->n60 / 16;
    m->n56 = h->n68 / 12;
    m->n48 = h->n76 / 4;
    func_00141850(m, a2);
    Mtx5 a;
    func_0011b6a8(&a);
    Mtx5 b;
    // sceVu0CopyMatrix (hand-written lq/sq)
    asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                 : : "r"(&b), "r"(&a) : "$8", "$9", "$10", "$11", "memory");
    func_00142940(m, &b);
    func_00141808(m);
}

struct VB6 {
    f32 x, y, z, w;
    VB6() {}
    VB6(const VB6& s) { QCOPY(this, &s); }
    VB6& operator=(const VB6& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
struct Tri6 { VB6 v[2]; };
struct Face6 { u8 pad[10]; u16 n; u8 pad2[4]; };
struct Mesh6 { u8 pad[12]; Face6* faces; u8 pad2[8]; VB6* norms; u8 pad3[32]; u16* list; };
void func_00141988(Mesh6*, Face6*, Tri6*);  // collect_entry_ptrs_by_halves
s32 func_001628d8(VB6*, Tri6*, VB6*, VB6*);
// squared distance |b - a| (VU0, hand-written)
static inline f32 Dist2_6(const VB6& b, const VB6& a)
{
    f32 r;
    asm volatile("lqc2 $vf6, 0(%1)\n\tlqc2 $vf4, 0(%2)\n\tvsub.xyzw $vf5, $vf6, $vf4\n\tvmove.xyzw $vf4, $vf5\n\tvmul.xyz $vf5, $vf4, $vf5\n\t"
                 "vaddy.x $vf5, $vf5, $vf5y\n\tvaddz.x $vf5, $vf5, $vf5z\n\tqmfc2 $2, $vf5\n\tmtc1 $2, %0"
                 : "=f"(r) : "r"(&b), "r"(&a) : "$2", "memory");
    return r;
}
u32 func_00141e78(Mesh6* m, VB6* ray, s32 n, VB6* out)
{
    f32 best = 9.99999920e13f;
    u32 id = 0xffff;
    VB6 hit;
    Tri6 tri;
    for (s32 i = 0; i < n; i++) {
        u32 k = m->list[i];
        Face6* f = &m->faces[k];
        func_00141988(m, f, &tri);  // collect_entry_ptrs_by_halves
        VB6 nrm(m->norms[f->n]);
        if (func_001628d8(ray, &tri, &nrm, &hit)) {
            VB6 a, b;
            a = *ray;
            b = hit;
            f32 d = Dist2_6(b, a);
            if (d < best) {
                best = d;
                *out = hit;
                id = (u16)k;
            }
        }
    }
    return id;
}

extern u8 D_0034e958[];
extern u8 D_01c5f530[];
extern u32 D_0034e948__48451 asm("D_0034e948");
void func_00175670(u8*, u32, s32, u32);
s32 func_0016a070__48451(u8*) asm("func_0016a070");
u8* func_001a15d0(s32, s32);
s32 func_001818a0(void);
u32 func_0016f6a0(u32, s32);
void func_00176168(u8*, u32, s32);
void func_001781a8(u8*);
static inline bool HasSub7(s32 k)
{
    return k != 0 && k < 7;
}
void func_00177dc8(u8* p, u32 res, s32 kind, u32 a3, u32 t0)
{
    func_00175670(p, res, 0, t0);
    *(u32*)(p + 2872) = a3;
    *(u32*)p = (u32)D_0034e958;
    *(s32*)(p + 2896) = kind;
    *(u32*)(p + 2884) = (u32)D_01c5f530;
    *(s32*)(p + 2892) = -1;
    *(u32*)(p + 2876) = (u32)D_01c5f530;
    *(u32*)(p + 2880) = (u32)(D_01c5f530 + 2752);
    *(u32*)(p + 2904) = 0xffff;
    *(u32*)(p + 1416) |= 0x80;
    *(u32*)(p + 2888) = 0;
    *(u32*)(p + 2900) = 0;
    *(u32*)(p + 2912) = 0;
    p[2916] = 0;
    D_0034e948__48451 = (u32)p;
    *(u32*)(p + 1896) |= 0x10;
    u8* o = func_001a15d0(func_0016a070__48451(p), *(s32*)(p + 2896));
    *(u32*)(p + 1164) = (u32)o;
    if (o) {
        *(u32*)(o + 604) = (u32)p;
        ((u8*)*(u32*)(p + 1164))[431] = 0;
        if (!func_001818a0()) {
            *(u32*)(*(u32*)(p + 1164) + 592) |= 2;
            *(u32*)(*(u32*)(p + 1164) + 592) |= 4;
        }
    }
    u32 x = func_0016f6a0(res, 0);
    if (x) func_00176168(p, x, 0);
    s32 k = *(s32*)(p + 2896);
    if (HasSub7(k) || k == 10) {
        x = func_0016f6a0(res, 1);
        if (x) func_00176168(p, x, 1);
    }
    func_001781a8(p);
}

struct Kind9 { u8 pad[4]; u8 k; };
struct Obj9 { u8 pad[12]; u8* owner; u8 pad2[24]; Kind9* kind; u8 team; };
struct Ent9 { Obj9* obj; u8 pad[12]; u8 sub[32]; };
struct List9 { s32 n; u8 pad[12]; Ent9 e[1]; };
extern u8 D_0036cce0[][7];
s32 func_001c0298(u8*, Obj9*);  // state_check5or6
s32 func_0018a550(u8*, u8*);  // state_dispatch_0_1_3
s32 func_0018e698(Ent9*, Ent9*);
void func_0018ea40(Ent9*, Ent9*);
void func_0018e7c0(Ent9*, Ent9*);
void func_0018eb98(List9* l, Ent9* q)
{
    for (s32 i = 0; i < l->n; i++) {
        Ent9* e = (Ent9*)((u8*)(i * 48) + (u32)l + 16);
        Obj9* a = e->obj;
        Obj9* b = q->obj;
        if (a->team == b->team) continue;
        if (!D_0036cce0[a->kind->k][b->kind->k]) continue;
        if (!func_001c0298((u8*)a + 48, b)) continue;
        if (!func_001c0298((u8*)q->obj + 48, e->obj)) continue;
        if (!func_001c0298(e->obj->owner + 2640, q->obj)) continue;
        if (!func_001c0298(q->obj->owner + 2640, e->obj)) continue;
        if (!func_0018a550(e->sub, q->sub)) continue;
        if (!func_0018e698(e, q)) continue;
        if (!func_0018e698(q, e)) continue;
        func_0018ea40(e, q);
        func_0018ea40(q, e);
        func_0018e7c0(e, q);
        func_0018e7c0(q, e);
    }
}

struct Mask11 { u32 on, set, off; u32 Get() { return (on | set) & ~off; } };
struct Hit11 { u8 pad[24]; u32 flags; u32 src; u32* def; };
struct Chr11 { void** vt; };
s32 func_001b58a8(void);
s32 func_0018cdd0(Hit11*);
void func_001b5ab0(void);
void func_001b3e88(Chr11*, Hit11*);
void func_001b3cb0(Chr11*, u32);
void func_00186d48(Chr11*, Hit11*);
void func_001c20e8(u32, Hit11*, Chr11*);
void func_001883f8(u8*, Hit11*);
void func_0016cce8(u32, s32, Hit11**, s32, s32);
void func_00186148(Chr11*, Hit11*);
void func_001b3d00(Chr11* p, Hit11* h)
{
    u8* b = (u8*)p;
    Mask11* m = (Mask11*)(b + 2748);
    if (m->Get() & 0x2000) {
        func_00186148(p, h);
        return;
    }
    {
        if (func_001b58a8() && func_0018cdd0(h)) func_001b5ab0();
        if (!(h->flags & 4)) func_001b3e88(p, h);
        if (*(u32*)(b + 2040) & 4) return;
        if (((s32 (*)(Chr11*))p->vt[24])(p)) return;
        *(u32*)(b + 2792) = *h->def;
        func_001b3cb0(p, *(u32*)(h->src + 8));
        func_00186d48(p, h);
        if (!(*(u32*)(b + 2040) & 4) || !(*(u32*)(b + 1416) & 0x800)) func_001c20e8((*(u32*)(b + 2748) | m->set) & ~m->off, h, p);
        if (*(u32*)(b + 1156)) {
            func_001883f8(b + 768, h);
            u32 t = (u32)h;
            func_0016cce8(*(u32*)(b + 1156), 6, (Hit11**)&t, 1, 0);
        }
        ((void (*)(Chr11*, Hit11*))p->vt[26])(p, h);
    }
    func_00186148(p, h);
}

struct VB13 {
    f32 x, y, z, w;
    VB13() {}
    VB13(const VB13& s) { QCOPY(this, &s); }
    VB13& operator=(const VB13& s) { QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
struct Shk13 { u32 a; f32 b, c; u32 d; VB13 pos; };
s32 func_001b5858(u8*);
u8* func_00168b88(u32, s32, u32, s32);  // find_entry16_by_half_word
u32 func_00198738(u32, s8*);
void func_00185278(u32, u8, f32);
void func_0016af58__52620(VB13*, u32) asm("func_0016af58");
void func_0016b010__52620(u32, VB13*) asm("func_0016b010");
double func_00313b80(f32);  // float_to_double
s32 func_003142e0(double, double);  // double_compare
VB13* func_0016c028__52620(u32) asm("func_0016c028");
void func_00185e78(Shk13*);
u8* func_001050d8(s32);
void func_00196ca8(u8*, s32, u32);
void func_00196e98(u8*, u32);
void func_00196f00(u8*);
#define ID4(s) ((s)[0] | ((s)[1] << 8) | ((s)[2] << 16) | ((s)[3] << 24))
static inline bool Valid13(u8* r) { return r && *(u32*)(r + 8); }
void func_001b50e0(u8* p, s8* id, u8 flag, f32 shake)
{
    u32 v = 0;
    if (func_001b5858(p)) {
        v = func_00198738(*(u32*)(p + 16), id);
    } else {
        u8* r = func_00168b88(*(u32*)(p + 4), 22, ID4(id), 0);  // find_entry16_by_half_word
        if (Valid13(r)) v = *(u32*)(r + 8);
    }
    if (!v) return;
    func_00185278(*(u32*)(p + 12), flag, 500.0f);
    VB13 t;
    func_0016af58__52620(&t, *(u32*)(p + 12));
    func_0016b010__52620(*(u32*)(p + 12), &t);
    if (func_003142e0(0.0, func_00313b80(shake)) < 0) {  // double_compare
        Shk13 s;
        VB13* q = func_0016c028__52620(*(u32*)(p + 12));
        s.a = 0;
        s.b = shake;
        s.c = shake;
        s.d = 0;
        s.pos = *q;
        func_00185e78(&s);
    }
    u8* o = func_001050d8(176);
    func_00196ca8(o, 11, v);
    func_00196e98(o, *(u32*)(p + 12));
    func_00196f00(o);
}

extern u32 D_01d48cb0;
extern u8 D_00351eb8[];
extern u8 D_00352560[];
extern u8 D_00350e48[];
s32 func_0019ba60(u8*);
void func_0016cab8(u8*);
void func_0016c7d8(u8*);
void func_001dde40(u8*);
void func_001b1c10(u32, f32);
void func_0016c640(s32);
void func_001d4570(u32, u32);
void func_00170950(u32);
s32 func_001b5858(u8*);
s32 func_001b5cb8(u8*);
void func_001c8d98(u8*, s32);
void func_001d1ed0(u8*);
void func_001d2048(u8*);
void func_001b0188(u8*);
void func_001ddd88(u8*);
struct NoTail14 { ~NoTail14() {} };
void func_001b4dd0(u8* p)
{
    NoTail14 nt;
    *(u32*)(*(u8**)(p + 12) + 268) &= ~0x10000;
    u8* q = p;
    for (s32 i = 0; i < 2; i++, q += 4) {
        if (func_0019ba60(*(u8**)(q + 16))) {
            *(u32*)(*(u32*)(q + 16) + 268) &= ~0x10000;
            ((u8*)*(u32*)(q + 16))[2892] = 0;
        }
    }
    u8* o = *(u8**)(p + 52);
    if (o) {
        func_0016cab8(o);
        func_0016c7d8(o);
    }
    u8* a = p + 24;
    if (*(u32*)(p + 24)) func_001dde40(a);
    u8* w = p + 104;
    func_001b1c10(*(u32*)(p + 56), 30.0f);
    func_0016c640(1);
    func_001d4570(*(u32*)p, *(u32*)(w + 56));
    if (*(u32*)(p + 4)) func_00170950(*(u32*)(p + 4));
    D_01d48cb0 = 0;
    if (!func_001b5858(p) && !func_001b5cb8(p)) func_001c8d98(D_00351eb8, 0);
    *(u32*)(p + 168) = (u32)D_00352560;
    func_001d1ed0(p + 168);
    func_001d2048(w);
    *(u32*)(p + 72) = (u32)D_00350e48;
    func_001b0188(p + 72);
    func_001ddd88(a);
}

struct Ev18 { u32 res; u8 pad[4]; u8* obj; };
struct Sn18 { u8 pad[4]; u16 id; u8 pad2[2]; u16 sy; u8 pad3[4]; s16 kind; s16 sx; u8 arg[2]; };
s32 func_002282f0(u16);
Ev18* func_00227d10(s16);
u8* func_0016f000(u32, Vec4*, f32);
void func_001ba028(u8*);  // list_contains_ptr
void func_00233280(u8*);
u32 func_00232e60(void);
u32 func_00232e18(s16);
u32 func_0022f4f0(u32);
u8* func_00227b00(u32, s32, u8*);
u8* func_00102c18(s32, s32, void (*)());
void func_00227950();
void func_00227a08();
void func_0017f430(u8*, u32, f32, f32);
void func_00232ea0(u32, Sn18*, Ev18*, u8*);
void func_002332a8(Sn18* p)
{
    if (func_002282f0(p->id)) return;
    Ev18* e = func_00227d10(p->kind);
    u32 h;
    if (!e->obj) {
        Vec4 v;
        asm volatile("sqc2 $vf0, 0(%0)" : : "r"(&v) : "memory");
        e->obj = func_0016f000(e->res | 0x40000000, &v, 3.1415925f);
        func_001ba028(e->obj);  // list_contains_ptr
        func_00233280(e->obj);
        h = func_00232e60();
    } else {
        h = func_00232e18(p->kind);
    }
    u8* s = func_00227b00(func_0022f4f0(e->res), 1, p->arg);
    *(s32*)(func_00102c18(1, 0xa7ee, func_00227950) + 4) = p->kind;
    if (!s[8]) *(u8**)(func_00102c18(1, 0xa7f3, func_00227a08) + 4) = s;
    u8* o = e->obj;
    func_001ba028(o);  // list_contains_ptr
    func_0017f430(o + 320, *(u32*)(s + 20), (f32)p->sx * 2.0f, (f32)p->sy * 2.0f);
    func_00232ea0(h, p, e, s);
}

void func_00177f50(u8* p, u32 res, s32 kind, u32 a3, u32 t0)
{
    func_00175670(p, res, 0, t0);
    *(u32*)(p + 2872) = a3;
    *(u32*)p = (u32)D_0034e958;
    *(s32*)(p + 2896) = kind;
    *(u32*)(p + 2884) = (u32)D_01c5f530;
    *(s32*)(p + 2892) = -1;
    *(u32*)(p + 2876) = (u32)D_01c5f530;
    *(u32*)(p + 2880) = (u32)(D_01c5f530 + 2752);
    *(u32*)(p + 2904) = 0xffff;
    *(u32*)(p + 1416) |= 0x80;
    *(u32*)(p + 2888) = 0;
    *(u32*)(p + 2900) = 0;
    *(u32*)(p + 2912) = 0;
    p[2916] = 0;
    D_0034e948__48451 = (u32)p;
    *(u32*)(p + 1896) |= 0x10;
    u8* o = func_001a15d0(func_0016a070__48451(p), *(s32*)(p + 2896));
    *(u32*)(p + 1164) = (u32)o;
    if (o) {
        *(u32*)(o + 604) = (u32)p;
        ((u8*)*(u32*)(p + 1164))[431] = 0;
        if (!func_001818a0()) {
            *(u32*)(*(u32*)(p + 1164) + 592) |= 2;
            *(u32*)(*(u32*)(p + 1164) + 592) |= 4;
        }
    }
    u32 x = func_0016f6a0(res, 0);
    if (x) func_00176168(p, x, 0);
    s32 k = *(s32*)(p + 2896);
    if (HasSub7(k) || k == 10) {
        x = func_0016f6a0(res, 1);
        if (x) func_00176168(p, x, 1);
    }
    func_001781a8(p);
}

extern s8 D_0035ed69;
extern u8* D_0035ed64;
extern s32 D_0035f3d4;
extern u32 D_0035ed4c;
extern u32 D_0035ed54;
s32 func_00139d78(void*);
s32 func_0028afa8(u32);
u8* func_002891b8(u32, s32);
void func_0028d8c0__58307(u8*, s32, s32, s32, u32, s32, s32, s32) asm("func_0028d8c0");
void func_0028dcc0__58307(u8*, u8*) asm("func_0028dcc0");
void func_00139648(u8*);
u32 func_0023aa18(u8*);
u32 func_0023aa38(u8*);
void func_00138c68(u8*, u32, u32);
void func_002493c8(void);
void func_002491d0(void)
{
    if (!D_0035ed69) return;
    if (func_00139d78(D_0035ed64)) return;
    s32 id = D_0035f3d4 + 1;
    s32 n = func_0028afa8(D_0035ed4c);
    for (s32 i = 0; i < n; i++) {
        u8* o = func_002891b8(D_0035ed4c, i);
        u8* a = o + 24;
        if ((u8)((D_0035ed69 >> i) & 1)) {
            func_0028d8c0__58307(D_0035ed64 + i * 408, id, 0, 0, D_0035ed54, 38, -1, 0);
            func_0028dcc0__58307(D_0035ed64 + i * 408, o);
            func_00139648(D_0035ed64 + i * 408);
            u32 x = func_0023aa18(a);
            func_00138c68(D_0035ed64 + i * 408, x, func_0023aa38(a));
        }
    }
    func_002493c8();
}

extern s8 D_0035edfc;
extern u8* D_0035ede8;
extern s32 D_0035f3d4;
extern u32 D_0035edcc;
extern u32 D_0035edd4;
s32 func_00139d78(void*);
s32 func_0028afa8(u32);
u8* func_002891b8(u32, s32);
void func_0028d8c0__59439(u8*, s32, s32, s32, u32, s32, s32, s32) asm("func_0028d8c0");
void func_0028dcc0__59439(u8*, u8*) asm("func_0028dcc0");
void func_00139648(u8*);
u32 func_0023aa18(u8*);
u32 func_0023aa38(u8*);
void func_00138c68(u8*, u32, u32);
void func_0024e5b0(void);
void func_0024e3a8(void)
{
    if (!D_0035edfc) return;
    if (func_00139d78(D_0035ede8)) return;
    s32 id = D_0035f3d4 + 1;
    s32 n = func_0028afa8(D_0035edcc);
    for (s32 i = 0; i < n; i++) {
        u8* o = func_002891b8(D_0035edcc, i);
        u8* a = o + 24;
        if ((u8)((D_0035edfc >> i) & 1)) {
            func_0028d8c0__59439(D_0035ede8 + i * 408, id, 0, 0, D_0035edd4, 38, -1, 0);
            func_0028dcc0__59439(D_0035ede8 + i * 408, o);
            func_00139648(D_0035ede8 + i * 408);
            u32 x = func_0023aa18(a);
            func_00138c68(D_0035ede8 + i * 408, x, func_0023aa38(a));
        }
    }
    func_0024e5b0();
}

extern u8 D_0035f0b0;
s32 func_00287cd0(void);
u32 func_00240ba0(void);
s32 func_002b4ff8(void);
void func_00287cc0(s32);
s32 func_00287d30(void);
s32 func_00233e70(s32);
s32 func_00234778(void);
void func_002419d0(s32);  // store_global_bool_converted
void func_00234570(u32, s32);
void func_00287d20(s32);
s32 func_002348a8(u32, s32);
u32 func_00234888(u32, s32);  // entry32_word
void func_00240bb0(u32);  // global_store_half2
void func_00241450(s32);
void func_002b5108(s32, u32);
void func_00287bd0(s32, s32);
void func_002400f8(s32);
void func_002b4c88(s32);
s32 func_00288040(void);
void func_00288018(void);  // global_zero_4dwords
void func_0025adf0(void)
{
    s32 open = func_00287cd0();
    u32 w = func_00240ba0();
    if (!func_002b4ff8()) return;
    if (!open) func_00287cc0(1);
    s32 done = 0;
    switch (func_00287d30()) {
    case 20:
        if (func_00233e70(0)) break;
        if (func_00234778()) {
            done = 1;
            break;
        }
        func_002419d0(0);  // store_global_bool_converted
        func_00234570(w, 0);
        func_00287d20(21);
        break;
    case 21:
        if (func_00233e70(0)) break;
        w = func_00240ba0();
        if (func_002348a8(w, 0) != 3) {
            func_00240bb0(func_00234888(w, 0));  // global_store_half2
            func_00241450(1);
            func_002b5108(0x8a90, w);
            func_00287bd0(14, 0);
            func_00287d20(70);
            func_002400f8(1);
        } else {
            done = 1;
        }
        break;
    }
    if (done) {
        func_002b5108(0x8a95, w);
        func_00287bd0(7, 0);
        func_002b4c88(0);
        D_0035f0b0 = 0;
    }
    if (func_00288040()) func_00288018();
}

void func_00281b30(u32);
s32 func_00289358(u32);
void func_00269658(void);
void func_0026a5a0(void);
void func_0026a900(void);
void func_00269a60(void);
u32 func_0028b040(u32);
s32 func_00269508(u32);
u32 func_0028af88(u32);
s32 func_00283ab8(s32);
s32 func_00258068(s32);  // get_global_bit
void func_00256cc0(s32, s32, s32);
void func_0028af18(u32, u32);
void func_0026a238(u32 p, s32 k)
{
    func_00281b30(p);
    if (func_00289358(p)) {
        if (k == 2) {
            func_00269658();
        } else if ((u32)(k - 5) < 5) {
            func_0026a5a0();
            func_0026a900();
        }
    } else if ((u32)(k - 5) < 5) {
        func_0026a900();
    }
    func_00269a60();
    if (k != 2) return;
    s32 st = func_00269508(func_0028b040(p));
    u32 f = func_0028af88(p);
    if (st == 4) f |= 0x200;
    else f &= ~0x200;
    s32 snd = -1;
    if ((st == 4 && func_00283ab8(0)) || (st == 1 && func_00283ab8(3))) {
        f |= 0x400;
        snd = 0xcbdd;
    } else {
        f &= ~0x400;
    }
    if (func_00258068(1)) func_00256cc0(0xb619, 0xb61a, snd);  // get_global_bit
    else if (snd >= 0) func_00256cc0(snd, -1, -1);
    func_0028af18(p, f);
}

s32 func_002a9f50(s32);
s32 func_002aa378(s32);
s32 func_002aaab8(s32);
s32 func_002aaf40(s32);
s32 func_002ab368(s32);
s32 func_002ab620(s32);
s32 func_002ab9c8(s32);
s32 func_002abce8(s32);
s32 func_002ac538(s32);
s32 func_002ac800(s32);
s32 func_002aa788(s32, s32);
s32 func_002ac110(s32, s32);
s32 func_002a1b18(s32, s32);
s32 func_002acb20(s32 a)
{
    if (a == 15) {
        if (!func_002a9f50(-1)) return 0;
        if (!func_002aa378(-1)) return 0;
        if (!func_002aaab8(-1)) return 0;
        if (!func_002aaf40(-1)) return 0;
        if (!func_002ab368(-1)) return 0;
        if (!func_002ab620(-1)) return 0;
        if (!func_002ab9c8(-1)) return 0;
        if (!func_002abce8(-1)) return 0;
        if (!func_002ac538(-1)) return 0;
        if (!func_002ac800(-1)) return 0;
    } else {
        if (!func_002aa788(a, -1)) return 0;
        if (!func_002aaf40(a)) return 0;
        if (!func_002ab368(a)) return 0;
        if (!func_002ab620(a)) return 0;
        if (!func_002ab9c8(a)) return 0;
        if (!func_002ac110(a, -1)) return 0;
        if (func_002a1b18(0, a) == 1) return 0;
        if (func_002a1b18(1, -1) == 1) return 0;
        if (!func_002ac800(a)) return 0;
    }
    return 1;
}

struct Ob31;
extern Ob31* D_0035f634;
s32 func_00139d78(void*);
void func_00139510(u8*);
s32 func_00281be0(void);
void func_00281c50(void);
void func_002b2c80(void);
struct Ob31 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    u8 pad[404];
};
static inline void Kill31(s32 off)
{
    if (func_00139d78((u8*)D_0035f634 + off)) func_00139510((u8*)D_0035f634 + off);
}
void func_002b20b8(void)
{
    for (s32 i = 0; i < 48; i++) {
        if (func_00139d78(&D_0035f634[i])) D_0035f634[i].v5();
    }
    Kill31(21216);
    Kill31(22032);
    Kill31(22468);
    Kill31(24212);
    Kill31(21624);
    Kill31(23340);
    Kill31(23776);
    Kill31(22904);
    if (func_00281be0()) func_00281c50();
    func_002b2c80();
}

struct V33 {
    f32 x, y, z, w;
    V33& operator=(const V33& o) { if (this != &o) QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
V33 func_00163650(const V33*, const V33*, const V33*);
void func_00146788(V33* out, V33* p)
{
    out[0] = func_00163650(&p[0], &p[1], &p[2]);
    out[1] = func_00163650(&p[7], &p[6], &p[5]);
    out[2] = func_00163650(&p[3], &p[2], &p[6]);
    out[3] = func_00163650(&p[0], &p[4], &p[5]);
    out[4] = func_00163650(&p[4], &p[0], &p[3]);
    out[5] = func_00163650(&p[6], &p[2], &p[1]);
}

struct V34 {
    f32 x, y, z, w;
    V34() {}
    V34& operator=(const V34& o) { if (this != &o) QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct Ent34 { u8 pad[192]; V34 pos; u8 pad2[40]; u32 fl; };
void func_00148638(f32);
void func_00148690(u8*, Ent34*, f32);
// VU0 vector helpers: hand-written macro code in the original.
#define DIST34(r, p, q) { a = p; b = q; r = Dist34(a, b, c); }
static inline f32 Dist34(V34& a, V34& b, V34& c)
{
    asm volatile("lqc2 $vf1,0(%1)\n\tlqc2 $vf2,0(%2)\n\tvsub.wxyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,0(%0)"
                 : : "r"(&c), "r"(&b), "r"(&a) : "memory");
    f32 r;
    asm volatile("lqc2 $vf1,0(%1)\n\tvmul.xyz $vf1,$vf1,$vf1\n\tvaddy.x $vf1,$vf1,$vf1y\n\tvaddz.x $vf1,$vf1,$vf1z\n\t"
                 "vsqrt Q,$vf1x\n\tvwaitq\n\tcfc2.ni $8,$vi22\n\tmtc1 $8,%0"
                 : "=f"(r) : "r"(&c) : "$8", "memory");
    return r;
}
f32 func_00148890(u8* o, Ent34* e, const V34* q)
{
    f32 d = 0.0f;
    V34 p;
    V34 a, b, c;
    asm volatile("lqc2 $vf5,0(%1)\n\tlqc2 $vf1,0(%2)\n\tlqc2 $vf2,16(%2)\n\tlqc2 $vf3,32(%2)\n\tlqc2 $vf4,48(%2)\n\t"
                 "vmulax.xyz ACC,$vf1,$vf5x\n\tvmadday.xyz ACC,$vf2,$vf5y\n\tvmaddaz.xyz ACC,$vf3,$vf5z\n\t"
                 "vmaddw.xyz $vf5,$vf4,$vf0w\n\tvmove.w $vf5,$vf0\n\tsqc2 $vf5,0(%0)"
                 : : "r"(&p), "r"(&e->pos), "r"(o + 304) : "memory");
    if (e->fl & 0x80) {
        DIST34(d, e->pos, *q);
        func_00148638(d);
    }
    if (e->fl & 0x100) {
        if (d == 0.0f) DIST34(d, e->pos, *q);
        func_00148690(o, e, d);
    }
    return p.z;
}

struct Tune37 { u8 pad[96]; f32 f96; f32 f100; u8 pad2[12]; f32 f116; };
extern Tune37* D_00352130__67414 asm("D_00352130");
struct Sub37 { u8 pad[431]; u8 st; u8 pad2[4]; f32 f436; };
struct Arg37 { u8 pad[41]; u8 k; };
u8* func_0017df58(s32);
s32 func_0019ba60(u8*);
void func_0016cce8__67414(u32, s32, u32*, s32, s32) asm("func_0016cce8");
void func_00179a68(u8*, f32);
void func_001a1b68__67414(Sub37*, f32) asm("func_001a1b68");
void func_00177760(u8*, u8*, u32, Arg37*);
void func_001798d8(u8* o, u8* t, u32 v, Arg37* a)
{
    for (s32 i = 0; i < 2; i++) {
        u8* e = func_0017df58(i);
        if (!e) continue;
        if (!func_0019ba60(e)) continue;
        if (!*(u32*)(e + 1156)) continue;
        u32 m[2];
        m[0] = (u32)t;
        m[1] = v;
        func_0016cce8__67414(*(u32*)(e + 1156), 15, m, 2, 0);
    }
    if (a->k && (*(u32*)(t + 1416) & 0x10)) {
        u32 fl = *(u32*)(t + 1416);
        f32 f = a->k;
        Sub37* s = *(Sub37**)(o + 1164);
        switch (s->st) {
        case 3:
            if (s->f436 == 0.0f) break;
        case 1:
            if (fl & 0x800) f *= D_00352130__67414->f96;
            func_00179a68(o, f);
            break;
        case 2:
            f = -f * D_00352130__67414->f116;
            if (fl & 0x800) f *= D_00352130__67414->f100;
            func_001a1b68__67414(s, f);
            break;
        }
    }
    func_00177760(o, t, v, a);
}

struct V38 {
    f32 x, y, z, w;
    V38() {}
    V38& operator=(const V38& o) { if (this != &o) QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
// VU0 vector helpers: hand-written macro code in the original.
static inline V38 Sub38(const V38& a, const V38& b)
{
    V38 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1,0(%1)\n\tlqc2 $vf2,0(%2)\n\tvsub.wxyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 Len38(const V38& v)
{
    f32 r;
    asm volatile("lqc2 $vf1,0(%1)\n\tvmul.xyz $vf1,$vf1,$vf1\n\tvaddy.x $vf1,$vf1,$vf1y\n\tvaddz.x $vf1,$vf1,$vf1z\n\t"
                 "vsqrt Q,$vf1x\n\tvwaitq\n\tcfc2.ni $8,$vi22\n\tmtc1 $8,%0"
                 : "=f"(r) : "r"(&v) : "$8", "memory");
    return r;
}
struct Hit38 { u8 pad[12]; s32 n; V38 pos; };
struct Node38 { u8 id; u8 pad; u16 fl; };
struct Out38 { u8* e; u32 id; };
void func_00190128__68827(void) asm("func_00190128");
u8* func_00185da8(u8*);
s32 func_0019bc38(u8*);
s32 func_0019bb58(u8*);
Node38* func_0016bba8__68827(u8*, s32, Node38*) asm("func_0016bba8");
void func_0018a818__68827(Hit38*, u8*, Node38*) asm("func_0018a818");
V38* func_0016c028__68827(u32) asm("func_0016c028");
s32 func_00190140(Out38*);
void func_00191218(Out38* out, u32 cam, f32 range)
{
    f32 best = 0.0f;
    Hit38 h;
    h.n = 0;
    func_00190128__68827();
    u8* e = 0;
    while ((e = func_00185da8(e))) {
        if (!func_0019bc38(e)) continue;
        if (!func_0019bb58(e)) continue;
        Node38* n = 0;
        while ((n = func_0016bba8__68827(e, 3, n))) {
            if (n->fl & 1) continue;
            func_0018a818__68827(&h, e, n);
            V38 d;
            d = Sub38(h.pos, *func_0016c028__68827(cam));
            f32 dist = Len38(d);
            f32 r = dist;
            if (*(u32*)(e + 1416) & 0x400) r = dist - range;
            if (!func_00190140(out) || r < best) {
                out->e = e;
                best = r;
                out->id = n->id;
            }
        }
    }
}

struct Hdr39 { u8 pad[4]; u16 nb; u16 na; };
struct Ref39 { u8 pad[44]; u16 k; };
struct Item39 { u8 pad[16]; Ref39* r; u8 pad2[16]; s32 cnt; u8 pad3[0]; };
struct It40 { u8 pad[16]; Ref39* r; u8 pad2[16]; s32 cnt; };
struct Ent39 { u8 pad[32]; s32 k; };
struct Obj39 { u32 p0; u32 pad; u32 hh; u8 pad2[28]; u8* p40; };
s32 func_002ceb08(Obj39*);
s32 func_002cebc8(u32);
u8* func_002cf638(u32);
It40* func_002cf8c0(u8*, u32, Obj39*, u8*);
void func_002cf750__39(u32, Obj39*, Ent39*, It40*, It40*) asm("func_002cf750");
void func_0019a308(Obj39* o)
{
    if (func_002ceb08(o) == 4) return;
    if (!func_002cebc8(o->p0)) return;
    It40* first = 0;
    u8* base = func_002cf638(((Hdr39*)o->hh)->na);
    for (s32 i = 0; i < ((Hdr39*)o->hh)->na; i++) {
        It40* it = func_002cf8c0(base + i, o->p0, o, o->p40 + i * 64);
        it->cnt = 1;
        if (i == 0) first = it;
    }
    for (s32 i = 0; i < ((Hdr39*)o->hh)->nb; i++) {
        Ent39* e = (Ent39*)((u8*)o->hh + i * 64 + 44);
        It40* a = 0;
        It40* b = 0;
        if (first && e->k) {
            a = &first[e->k - 1];
            if (a->r->k) b = &first[a->r->k - 1];
        }
        func_002cf750__39(o->p0, o, e, a, b);
    }
    for (s32 i = 0; i < ((Hdr39*)o->hh)->na; i++) first[i].cnt--;
}

struct Act40 { u8 pad[20]; u8 kind; u8 pad2[19]; u32 fl; u8 pad3[24]; u8 lv; };
extern u8* D_0034e948;
s32 func_001919f8(void);
s32 func_001919d0(void);
void func_001a5380(u8*, u8*, Act40*);
u8* func_00176b20(s32);
s32 func_0019ba60(u8*);
s32 func_001c7950(Act40*, u8*, f32, f32);  // copy_quad_if_flag
static inline bool Is40(u8* e) { return *(s32*)(e + 2896) == 6; }
struct Vec4x { f32 a,b,c,d; } __attribute__((aligned(16)));
struct NoTail40 { Vec4x v; ~NoTail40() {} };
void func_001a5140(u8* o, Act40* a)
{
    NoTail40 nt;
    if (func_001919f8()) a->fl |= 8;
    if (func_001919d0()) {
        func_001a5380(o, D_0034e948, a);
        return;
    }
    if ((a->fl & 8) && a->lv >= 3) func_001a5380(o, D_0034e948, a);
    for (s32 i = 0; i < 3; i++) {
        u8* e = func_00176b20(i);
        if (!func_0019ba60(e)) continue;
        if (*(u32*)(e + 2040) & 4) continue;
        if (*(u32*)(e + 1416) & 0x80) {
            if (Is40(e) && a->kind < 2) continue;
        } else {
            if ((u32)(a->kind - 7) < 2) continue;
        }
        if (func_001c7950(a, e, 0.0f, 0.0f)) {  // copy_quad_if_flag
            func_001a5380(o, e, a);
            return;
        }
    }
}

struct Obj41 { u8 pad[92]; u32 p92; u32 p96; u8 pad2[12]; s32 n112; u8 pad3[2920 - 116]; s32 n2920; };
u32 func_001ab800(void);
void func_00236788(u32);  // to_236830
void func_002367a0(void);
void func_0023bc58(u8*, u32, u32);
void func_0023acd8(u8*);
void func_0023ade0(u8*);
void func_001ac108(u8*, u32, u32, u32, u32);
void func_001ac6d0(Obj41*);
void func_001abf38(u8*, u32, u32);
void func_00239bf8(u8*, s32);
void func_001acdc0(Obj41* o, u32 a, u32 b, u32 c, u32 d, u32 e)
{
    func_00236788(func_001ab800());  // to_236830
    if (!e) e = o->p92;
    u8* s = (u8*)o + 132;
    func_0023bc58(s, e, o->p96);
    func_0023acd8(s);
    *(u32*)(s + 328) = a;
    *(u32*)(s + 332) = b;
    func_0023ade0(s);
    if (o->n112 > 0) func_001ac108((u8*)o + 1196, a, b, o->p92, o->p96);
    if ((u32)(o->n112 - 1) < 5) {
        func_001ac6d0(o);
        if (o->n112 >= 2) func_001abf38((u8*)o + 480, c, d);
        s32 i;
        for (i = 0; i < o->n2920; i++) {
            func_0023acd8((u8*)o + 1544 + i * 344);
            func_0023ade0((u8*)o + 1544 + i * 344);
        }
        for (i = o->n2920; i < 4; i++) func_00239bf8((u8*)o + 1544 + i * 344, 0);
        o->n2920 = 0;
    }
    func_001ab800();
    func_002367a0();
}

extern u32 D_003638d0;
struct Ent42 { s8 id; s8 w; };
struct Tab42 { u8 pad[4]; Ent42 e[5]; };
s32 func_001b0148(Tab42*, u32, s32, u32);
static inline u32 Rand42(void) { return D_003638d0 *= 0x10dcd; }
u64 func_00312db8(u64, u64);  // the game's own 64-bit unsigned divide (libgcc __udivdi3)
static inline s32 RandN42(u32 n)
{
    u32 r = Rand42();
    return (s32)func_00312db8((u64)r, func_00312db8((u64)(n - 1) + 0x100000000ULL, n));
}
// func_001affe0: not yet matching (scheduling around the game's 64-bit divide calls); left as asm.

// Entire body is hand-written VU0 macro code in the original.
void func_00224600(void* out, const void* m, const void* v)
{
    asm volatile(".set noreorder\n\tmove $13,$4\n\tmove $14,$5\n\tmove $15,$6\n\tlui $2,0xbf80\n\tqmtc2 $2,$vf19\n\tlqc2 $vf28,0($14)\n\tlqc2 $vf29,16($14)\n\tlqc2 $vf30,32($14)\n\tlqc2 $vf31,48($14)\n\tvmulx.xyz $vf28,$vf28,$vf19x\n\tvmulx.xyz $vf29,$vf29,$vf19x\n\tvmulx.xyz $vf30,$vf30,$vf19x\n\tvmulx.xyz $vf31,$vf31,$vf19x\n\tvmul.xyz $vf18,$vf28,$vf28\n\tvaddy.x $vf18,$vf18,$vf18y\n\tvaddz.x $vf18,$vf18,$vf18z\n\tvsqrt Q,$vf18x\n\tvwaitq\n\tvaddq.x $vf18,$vf0,Q\n\tvdiv Q,$vf0w,$vf18x\n\tvwaitq\n\tvmulq.xyz $vf28,$vf28,Q\n\tvmul.xyz $vf18,$vf29,$vf29\n\tvaddy.x $vf18,$vf18,$vf18y\n\tvaddz.x $vf18,$vf18,$vf18z\n\tvsqrt Q,$vf18x\n\tvwaitq\n\tvaddq.x $vf18,$vf0,Q\n\tvdiv Q,$vf0w,$vf18x\n\tvwaitq\n\tvmulq.xyz $vf29,$vf29,Q\n\tvmul.xyz $vf18,$vf30,$vf30\n\tvaddy.x $vf18,$vf18,$vf18y\n\tvaddz.x $vf18,$vf18,$vf18z\n\tvsqrt Q,$vf18x\n\tvwaitq\n\tvaddq.x $vf18,$vf0,Q\n\tvdiv Q,$vf0w,$vf18x\n\tvwaitq\n\tvmulq.xyz $vf30,$vf30,Q\n\tvmul.xyz $vf18,$vf31,$vf31\n\tvaddy.x $vf18,$vf18,$vf18y\n\tvaddz.x $vf18,$vf18,$vf18z\n\tvsqrt Q,$vf18x\n\tvwaitq\n\tvaddq.x $vf18,$vf0,Q\n\tvdiv Q,$vf0w,$vf18x\n\tvwaitq\n\tvmulq.xyz $vf31,$vf31,Q\n\tqmtc2 $0,$vf18\n\tvmulw.xyz $vf28,$vf28,$vf28w\n\tvmulw.xyz $vf29,$vf29,$vf29w\n\tvmulw.xyz $vf30,$vf30,$vf30w\n\tvmulw.xyz $vf31,$vf31,$vf31w\n\tvmove.w $vf28,$vf18\n\tvmove.w $vf29,$vf18\n\tvmove.w $vf30,$vf18\n\tvmove.w $vf31,$vf18\n\tqmfc2 $2,$vf28\n\tqmfc2 $3,$vf29\n\tqmfc2 $4,$vf30\n\tqmfc2 $5,$vf31\n\tpextlw $6,$3,$2\n\tpextuw $7,$3,$2\n\tpextlw $8,$5,$4\n\tpextuw $9,$5,$4\n\tpcpyld $2,$8,$6\n\tpcpyud $3,$6,$8\n\tpcpyld $4,$9,$7\n\tpcpyud $5,$7,$9\n\tqmtc2 $2,$vf28\n\tqmtc2 $3,$vf29\n\tqmtc2 $4,$vf30\n\tqmtc2 $5,$vf31\n\tlqc2 $vf24,0($15)\n\tlqc2 $vf25,16($15)\n\tlqc2 $vf26,32($15)\n\tvmove.w $vf24,$vf18\n\tvmove.w $vf25,$vf18\n\tvmove.w $vf26,$vf18\n\tvmulax.wxyz ACC,$vf28,$vf24x\n\tvmadday.wxyz ACC,$vf29,$vf24y\n\tvmaddz.wxyz $vf20,$vf30,$vf24z\n\tvmulax.wxyz ACC,$vf28,$vf25x\n\tvmadday.wxyz ACC,$vf29,$vf25y\n\tvmaddz.wxyz $vf21,$vf30,$vf25z\n\tvmulax.wxyz ACC,$vf28,$vf26x\n\tvmadday.wxyz ACC,$vf29,$vf26y\n\tvmaddz.wxyz $vf22,$vf30,$vf26z\n\tsqc2 $vf20,0($13)\n\tsqc2 $vf21,16($13)\n\tsqc2 $vf22,32($13)\n\tsqc2 $vf31,48($13)\n\t.set reorder"
                 : : : "$2", "$3", "$4", "$5", "$6", "$7", "$8", "$9", "$13", "$14", "$15", "memory");
}

struct Obj48 { u8 pad[4]; s16 id; char name[1]; };
extern char D_00371150[];
extern char D_00371168[];
extern char D_00371170[];
extern u32 D_0033caf0;
extern u8 D_0035e2ec;
s32 func_002282f0__77693(s32) asm("func_002282f0");
s32 func_00225b00(s32);  // flag_query_by_index
u32 func_0014abd8(void);
void func_0014aa58(u32, s32, s32);
void func_0014aa80(u32, s32, s32);
void func_00226ed0(void);
void func_002fee78(char*, const char*, ...);
void func_0022bd80(void);
s32 func_002ff538(const char*, const char*, s32);
void func_002ff3fc(char*);  // strlen
s32 func_002ef7a0(s32, char*);
void func_0014a1f0__77693(void) asm("func_0014a1f0");
void func_00102448(u32, s32);
void func_00102c18__77693(s32, s32, void*) asm("func_00102c18");
void func_0022ba88(void);
void func_0022bc08(Obj48* o, u32 w)
{
    if (func_002282f0__77693(o->id)) return;
    if (func_00225b00(o->id)) return;
    char* name = o->name;
    func_0014aa58(func_0014abd8(), 0, 0);
    func_00226ed0();
    char buf[48];
    func_002fee78(buf, D_00371150, D_0033caf0, name);
    func_0022bd80();
    if (!func_002ff538(name, D_00371168, 3) || !func_002ff538(name, D_00371170, 4)) D_0035e2ec = 1;
    func_002ff3fc(buf);  // strlen
    func_002ef7a0(0, buf);
    while (func_002ef7a0(5, 0) != 2) {
        func_0014a1f0__77693();
        func_00102448(w, 0);
    }
    while (func_002ef7a0(1, 0)) {
        func_0014a1f0__77693();
        func_00102448(w, 0);
    }
    func_0014aa80(func_0014abd8(), 0, 0);
    func_00102c18__77693(1, 0x16f30, (void*)func_0022ba88);
}

struct Hdr49 { u8 pad[8]; s32 n0; s32 o0; s32 n1; s32 o1; };
struct Thr49 { u8 pad[48]; void* fn; };
struct Th49 { u32 pad; u32 id; };
union U49 { Hdr49* p; u8 c; };
extern U49 D_0035eb10;
extern s32 D_0035eb20[2];
extern s32 D_0035eb18[2];
extern s32 D_0035eb28;
extern s32 D_0035eb2c;
extern s32 D_0035eb30;
extern s32 D_01dae680;
s32 func_00102c80(void);
Th49* func_00104190(void);
void func_00102180(s32*);
Thr49* func_00102c18__79184(s32, s32, void*) asm("func_00102c18");
Thr49* func_00102788(u32, s32, s32, void*);
void func_0023cf60(void);
void func_0023cdd8(void);
s32 func_0023cde8(Hdr49* h)
{
    D_0035eb10.p = h;
    D_0035eb20[0] = (s32)h + h->o0;
    D_0035eb20[1] = (s32)h + h->o1;
    D_0035eb18[0] = h->n0;
    D_0035eb18[1] = h->n1;
    D_0035eb28 = 1;
    D_0035eb2c = 0;
    D_0035eb30 = 0;
    for (s32 i = 0; i < 2; i++) {
        s32* p = (s32*)D_0035eb20[i];
        for (s32 n = D_0035eb18[i]; n > 0; n--, p += 2) {
            if (D_0035eb30 < *p) D_0035eb30 = *p;
        }
    }
    if (D_01dae680) return 1;
    Thr49* t = 0;
    s32 cur[4];
    s32 a = func_00102c80();
    Th49* b = func_00104190();
    D_01dae680 = 1;
    func_00102180(cur);
    if (cur[0] == a) t = func_00102c18__79184(0, 15000, (void*)func_0023cf60);
    else if (cur[0] == (s32)b) t = func_00102788(b->id, 0, 15000, (void*)func_0023cf60);
    t->fn = (void*)func_0023cdd8;
    return 1;
}

struct Ob50 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
};
extern Ob50* D_0035f03c__80579 asm("D_0035f03c");
extern Ob50* D_0035f030;
extern u32 D_0035f01c;
extern u32 D_0035f020;
extern u32 D_0035f024;
extern u32 D_0035f050;
extern u32 D_0035f044;
extern u32 D_0035f048;
s32 func_00139d78(void*);
s32 func_0028acc8(u32);
void func_0028abe0(u32);
void func_00254f08(void);
void func_0028f878(void);
void func_0028d620(u32);
void func_00263d28(void);
void func_002579e0(void);
void func_00256c40(void);
void func_00256ea8(void);
void func_0028ff68(u32);
void func_00290488(u32);
void func_00288018(void);  // global_zero_4dwords
void func_0028ce38(void);
void func_00256aa0(void);
void func_0025f750(void);
void func_00267768(void);
void func_0026bbf8(void);
void func_0026ee30(void);
void func_00277128(void);
void func_0027c570(void);
void func_002831b0(void);
void func_0027e770(void);
void func_00264458(void);
void func_00254f80(void)
{
    if (func_00139d78(D_0035f03c__80579)) D_0035f03c__80579->v5();
    if (func_0028acc8(D_0035f01c)) func_0028abe0(D_0035f01c);
    if (func_0028acc8(D_0035f020)) func_0028abe0(D_0035f020);
    if (func_0028acc8(D_0035f024)) func_0028abe0(D_0035f024);
    if (func_00139d78(D_0035f030)) D_0035f030->v5();
    func_00254f08();
    func_0028f878();
    func_0028d620(D_0035f050);
    func_00263d28();
    func_002579e0();
    func_00256c40();
    func_00256ea8();
    func_0028ff68(D_0035f044);
    func_00290488(D_0035f048);
    func_00288018();  // global_zero_4dwords
    func_0028ce38();
    func_00256aa0();
    func_0025f750();
    func_00267768();
    func_0026bbf8();
    func_0026ee30();
    func_00277128();
    func_0027c570();
    func_002831b0();
    func_0027e770();
    func_00264458();
}

struct ObA51 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    u8 pad[404];
};
struct ObB51 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    u8 pad[432];
};
struct Mgr51 {
    ObA51 grp[9][8];
    ObA51 a;
    ObB51 b, c, d;
    ObB51 e[9];
    ObB51 f[9];
};
extern Mgr51* D_0035f5e8;
s32 func_00139d78(void*);
void func_00139510__82352(void*) asm("func_00139510");
void func_002a41f0(void)
{
    if (func_00139d78(&D_0035f5e8->a)) func_00139510__82352(&D_0035f5e8->a);
    s32 j;
    for (j = 0; j < 9; j++) {
        for (s32 i = 0; i < 8; i++) {
            if (func_00139d78(&D_0035f5e8->grp[j][i])) D_0035f5e8->grp[j][i].v5();
        }
    }
    if (func_00139d78(&D_0035f5e8->b)) func_00139510__82352(&D_0035f5e8->b);
    if (func_00139d78(&D_0035f5e8->c)) func_00139510__82352(&D_0035f5e8->c);
    if (func_00139d78(&D_0035f5e8->d)) func_00139510__82352(&D_0035f5e8->d);
    for (j = 0; j < 9; j++) {
        if (func_00139d78(&D_0035f5e8->e[j])) D_0035f5e8->e[j].v5();
        if (func_00139d78(&D_0035f5e8->f[j])) D_0035f5e8->f[j].v5();
    }
}

struct Pad53 { u8 pad[8]; u64 trg; };
extern u8* D_0035f634__83558 asm("D_0035f634");
Pad53* func_00167f18(s32);
s32 func_00287cd0(void);
void func_00281d48(void);
s32 func_002b1660(void);
u16* func_002b23e0(s32);  // list_entry_by_index_checked
void func_001a3188(u16, s32, s32);
u32 func_002b1aa0(void);
u32 func_00192048__83558(u32) asm("func_00192048");
void func_002b1af0(void);
void func_00139580(u8*);
void func_002817b8(void);
void func_00287c30(void);
void func_00287cc0(s32);
void func_002b1a00(void);
void func_00281e20(void);
s32 func_002b16d8(void);
void func_00287c90(s32);
void func_00242618(s32, s32);
void func_0028dac8(u8*, s32);
void func_00281b30__83558(void) asm("func_00281b30");
void func_00287c00(s32);
void func_002b14f0(void)
{
    Pad53* pad = func_00167f18(0);
    s32 st = func_00287cd0();
    func_00281d48();
    if (st == 2) {
        if (func_002b1660()) return;
        func_001a3188(*func_002b23e0(-1), 100, 0);
        u8* o = D_0035f634__83558 + 22468;
        *(u32*)(o + 408) = func_00192048__83558(func_002b1aa0());
        func_002b1af0();
        func_00139580(D_0035f634__83558 + 24212);
        func_002817b8();
        func_00287c30();
        func_00287cc0(1);
        func_002b1a00();
        return;
    }
    func_00281e20();
    if (!st && func_002b16d8()) func_00287c90(1);
    if (st != 1) return;
    if (!(pad->trg & 4)) return;
    func_00242618(2, 1);
    func_0028dac8(D_0035f634__83558 + 23776, 124);
    func_0028dac8(D_0035f634__83558 + 21624, 127);
    func_0028dac8(D_0035f634__83558 + 22904, 130);
    func_00281b30__83558();
    func_00287c00(29);
    func_00287cc0(2);
}

struct Ent54 { u8 b[432]; };
struct Lyt54 { u8 b[76]; };
struct Prm54 { u8 b[32]; };
struct Obj54 {
    u8 pad[188];
    Lyt54 lyt[9];
    u8 pad2[1320 - 188 - 9 * 76];
    Ent54 a[8];
    Ent54 b[8];
    u8 pad3[8244 - 4776 - 8 * 432];
    s32 st;
    u32 pad4;
    s32 na;
    s32 nb;
};
extern u8 D_003755b0[];
extern u8 D_003755b8[];
extern Prm54 D_00375638[];
extern u8 D_01e2bd40[];
u32 func_002c3268(Obj54*);
void func_0028b4c0(Ent54*, u32);  // copy_3halfwords_416
void func_0028b4f0(Ent54*, u8*);  // copy_3halfwords_422
void func_0023f778__84943(Lyt54*, u32) asm("func_0023f778");
void func_0023f7a8__84943(Lyt54*, Prm54*) asm("func_0023f7a8");
s32 func_00139d78(void*);
void func_00138c10__84943(u8*, s32) asm("func_00138c10");
void func_002cb0e8(u8*, u8*, f32);
void func_002c3368(Obj54* o)
{
    if (o->st != 2) o->st = 2;
    for (s32 i = 0; i < o->na; i++) {
        func_0028b4c0(&o->a[i], func_002c3268(o));  // copy_3halfwords_416
        func_0028b4f0(&o->a[i], D_003755b0);  // copy_3halfwords_422
    }
    for (s32 i = 0; i < o->nb; i++) {
        func_0028b4c0(&o->b[i], func_002c3268(o));  // copy_3halfwords_416
        func_0028b4f0(&o->b[i], D_003755b8);  // copy_3halfwords_422
    }
    for (s32 i = 0; i < 9; i++) {
        func_0023f778__84943(&o->lyt[i], func_002c3268(o));
        func_0023f7a8__84943(&o->lyt[i], &D_00375638[i]);
    }
    u8* t = (u8*)o + 11872;
    if (func_00139d78(t)) {
        func_00138c10__84943(t, 94);
        *(s32*)(t + 392) = 95;
    }
    func_002cb0e8((u8*)o + 13620, D_01e2bd40, 0.0f);
}

struct Grid55 { s8 cols; u8 pad; s16 size; };
struct UV55 { s16 u[4]; s16 v[4]; };
extern Grid55 D_00374cd0[];
u32* func_002b23e0__86355(s32) asm("func_002b23e0");
static inline void Put55(UV55* o, const UV55& t, s32 a, s32 b, s32 c, s32 d)
{
    o->u[0] = t.u[a]; o->v[0] = t.v[a];
    o->u[1] = t.u[b]; o->v[1] = t.v[b];
    o->u[2] = t.u[c]; o->v[2] = t.v[c];
    o->u[3] = t.u[d]; o->v[3] = t.v[d];
}
void func_002b28b0(u32 a0, s32 idx, s32 mode, UV55* out)
{
    Grid55* g = &D_00374cd0[(*func_002b23e0__86355(-1) >> 27) & 1];
    s32 cols = g->cols;
    s32 sz = g->size;
    s32 row = idx / cols;
    s32 col = idx % cols;
    UV55 t;
    t.u[0] = col * sz;
    t.v[0] = row * sz;
    t.u[3] = (col + 1) * sz;
    t.v[3] = (row + 1) * sz;
    t.u[2] = col * sz;
    t.u[1] = (col + 1) * sz;
    t.v[1] = row * sz;
    t.v[2] = (row + 1) * sz;
    switch (mode) {
    case 0: *out = t; break;
    case 1: Put55(out, t, 2, 0, 3, 1); break;
    case 2: Put55(out, t, 3, 2, 1, 0); break;
    case 3: Put55(out, t, 1, 3, 0, 2); break;
    }
}

struct Rec57 { u8 pad[8]; u32 v; };
struct Obj57 { u32 vt; u8 pad[84]; u8 b88; u8 pad2[7]; u32 h; u32 pad3; u8 sub[4]; void* m; };
extern u8 D_00362eb8[];
extern u8 D_00375f18[];
extern u8 D_00362e80[];
extern u8* D_0034e948;
void func_002ce958(Obj57*, s32, u32, s32);
void func_002e34b8(u8*);
void func_002ceae8(Obj57*, char*, u8*);
u32 func_001708f8(char*, s32);
Rec57* func_00168b38(u32, s32, s32);  // entry_array_find_nth
void func_002e34c0(u8*, u32);
void func_002e64b0(u32);
u32 func_001050c8(void);
void* func_001063c0(s32, u32);
void func_002e6fc0(void*, u32);
void func_002cedd0(s32, u8*);
void func_0016bd60(u8*, s32);
u8* func_0016b740(s32);
void func_002e2350(Obj57*);
void func_002e1f70(Obj57* o, u32 a)
{
    func_002ce958(o, 5, a, 0);
    o->vt = (u32)D_00362eb8;
    func_002e34b8(o->sub);
    char name[64];
    func_002ceae8(o, name, D_00375f18);
    u32 h = func_001708f8(name, -1);
    o->h = h;
    func_00168b38(h, 42, 0);  // entry_array_find_nth
    func_002e34c0(o->sub, func_00168b38(h, 42, 0)->v);
    func_00168b38(h, 42, 1);  // entry_array_find_nth
    u32 x = func_00168b38(h, 42, 1)->v;
    func_002e64b0(x);
    void* m = func_001063c0(12, func_001050c8());
    func_002e6fc0(m, x);
    o->m = m;
    func_002cedd0(3, D_00362e80);
    u8* p = D_0034e948;
    func_0016bd60(p, 53);
    *(u32*)(p + 264) |= 1;
    p = func_0016b740(2113);
    func_0016bd60(p, 54);
    *(u32*)(p + 264) |= 1;
    func_002e2350(o);
    o->b88 = 1;
}

V33 func_00163650(const V33*, const V33*, const V33*);
void func_001468f0(V33* out, V33* p)
{
    out[0] = func_00163650(&p[0], &p[1], &p[2]);
    out[1] = func_00163650(&p[7], &p[6], &p[5]);
    out[2] = func_00163650(&p[3], &p[2], &p[6]);
    out[3] = func_00163650(&p[0], &p[4], &p[5]);
    out[4] = func_00163650(&p[4], &p[0], &p[3]);
    out[5] = func_00163650(&p[6], &p[2], &p[1]);
}

struct V62 {
    f32 x, y, z, w;
    V62() {}
    V62(const V62& o) { QCOPY(this, &o); }
} __attribute__((aligned(16)));
struct Obj62 { u8 pad[86]; u16 pow; u8 pad2[2]; u16 se; };
struct Itm62 { u8 pad[10]; u16 atk; };
struct Hp62 { s32 hp; s32 max; };
struct Tune62 { u8 pad[324]; f32 thr; };
extern u8* D_0034e948;
extern s32 D_0032dfc8;
extern Tune62* D_00352130__89182 asm("D_00352130");
s32 func_001b7038(Obj62*);
u8* func_00177860(u8*);
Itm62* func_001c0cc8(void);  // get_global_35c63c
s32 func_0019ba60(u8*);
s32 func_001b70d0(s32);
void func_0015b680(V62*, s32, s32);
void func_001c0890(u16);
void func_001b4198(Obj62* o, u8* e, const V62* pos)
{
    if (func_001b7038(o)) {
        u8* pl = D_0034e948;
        u8* st = func_00177860(pl);
        s32 dmg = (func_001c0cc8()->atk * o->pow + 99) / 100;
        if (dmg > 0) {
            if (D_0032dfc8 == 3) {
                dmg = dmg * 75 / 100;
                if (!dmg) dmg = 1;
            }
            if (func_0019ba60(e) && (*(u32*)(e + 1416) & 0x80)) {
                Hp62* h = *(Hp62**)(pl + 1164);
                if ((f32)h->hp / (f32)h->max <= D_00352130__89182->thr) dmg *= st[47];
            }
            s32 r = func_001b70d0(dmg);
            if (r > 0) {
                V62 p = *pos;
                func_0015b680(&p, dmg, r);
            }
        }
    }
    if (o->se) func_001c0890(o->se);
}

struct Snd63 { u8 pad[5]; u8 pri; };
struct Obj63 { u8 pad[32]; u32 fl; u8 m[2492]; u8* pl; };
s32 func_001bd590(Obj63*);
void func_001be890(Obj63*, u8*);
void func_001bc778(u8*);
void func_001be540(Obj63*, u8*);
void func_001bf0c8(Obj63*);
s32 func_001bdfe0(Obj63*);
Snd63* func_001bc780(u8*, s32, s32, s32);
s32 func_001bdd20(Obj63*);
s32 func_0017a538(u8*);
s32 func_001917c0(void);
static inline bool Is63(u8* p) { return *(s32*)(p + 2896) == 6; }
void func_001be5f0(Obj63* o)
{
    u8* m = o->m;
    if (func_001bd590(o)) {
        func_001be890(o, m);
        return;
    }
    func_001bc778(m);
    func_001be540(o, m);
    if (*(s32*)(o->pl + 2896) == 3) {
        func_001bf0c8(o);
        func_001bc780(m, 707, 0, 1);
    } else {
        func_001bc780(m, func_001bdfe0(o) ? 2 : 104, 0, 1);
    }
    if (func_001bdd20(o)) func_001bc780(m, 104, 0, 1);
    else func_001bc780(m, 3, 0, 1);
    u8 pri = 5;
    if (o->fl & 0x20) {
        func_001bc780(m, 104, 0, 1);
        return;
    }
    if (func_0017a538(o->pl)) {
        Snd63* s = func_001bc780(m, 5, 0, 1);
        if (Is63(o->pl) && func_001917c0()) s->pri = pri;
    } else {
        Snd63* s = func_001bc780(m, 4, 0, 1);
        if (*(s32*)(o->pl + 2896)) s->pri = pri;
    }
}

struct Snd64 { u8 pad[5]; u8 pri; };
struct Obj64 { u8 pad[32]; u32 fl; u8 pad2[348]; u8 m[2144]; u8* pl; };
extern u8 D_00351ec0[];
extern u8 D_00351eb8[];
void func_001bc778(u8*);
s32 func_001c8db8(u8*, s32);
s32 func_001bbf40(void);
s32 func_001a36e0(s32);
s32 func_001a3570(s32);
u16* func_001a3868(s32);
s32 func_001c9b38(u16*);
Snd64* func_001bc780__91789(u8*, s32, s32, s32) asm("func_001bc780");
void func_001beb00(Obj64* o)
{
    if (o->fl & 0x20) return;
    u8* m = o->m;
    func_001bc778(m);
    if (func_001c8db8(D_00351ec0, 1)) return;
    if (func_001c8db8(D_00351eb8, 0)) return;
    if (*(u32*)(*(u8**)(o->pl + 12) + 8) & 0x20) return;
    if (func_001bbf40()) return;
    o->fl |= 0x20;
    for (s32 i = 1; i < 7; i++) {
        s32 x = func_001a36e0(i);
        if (func_001a3570(x) <= 0) continue;
        u16* it = func_001a3868(x);
        s32 k = func_001c9b38(it);
        if (k != 2) {
            Snd64* s = func_001bc780__91789(m, *it, 0, 1);
            if (k == 1) s->pri = 5;
        }
        o->fl &= ~0x20;
    }
}

void func_002d1270(s32, s32);
void func_002d6f28(s32, s32);
void func_002dc278(s32, s32);
void func_002bea88(void);
void func_001cebb0(void);
void func_002e0bb0(s32);
void func_002e1f40(s32);
void func_001d7218(s32 k)
{
    switch (k) {
    case 3: func_002d1270(1, 0); break;
    case 4: func_002d6f28(1, 0); break;
    case 5: func_002dc278(1, 0); break;
    case 12: func_002bea88(); break;
    case 50:
    case 51:
    case 52: func_001cebb0(); break;
    case 58: func_002d1270(0, 0); break;
    case 59: func_002d6f28(0, 0); break;
    case 60: func_002dc278(0, 0); break;
    case 226: func_002e0bb0(0); break;
    case 255: func_002d1270(2, 0); break;
    case 256: func_002d6f28(2, 0); break;
    case 257: func_002dc278(2, 0); break;
    case 271:
    case 310: func_002e1f40(0); break;
    case 349: func_002dc278(2, 0); break;
    case 367: func_002e0bb0(0); break;
    }
}

extern s8 D_0035ed9c;
extern u8* D_0035ed8c;
extern s32 D_0035f3d4;
extern u32 D_0035ed70;
extern u32 D_0035ed78;
s32 func_00139d78(void*);
s32 func_0028afa8(u32);
u8* func_002891b8(u32, s32);
void func_0028d8c0__93727(u8*, s32, s32, s32, u32, s32, s32, s32) asm("func_0028d8c0");
void func_0028dcc0__93727(u8*, u8*) asm("func_0028dcc0");
void func_00139648(u8*);
u32 func_0023aa18(u8*);
u32 func_0023aa38(u8*);
void func_00138c68(u8*, u32, u32);
void func_0024b0e8(void);
void func_0024aef0(void)
{
    if (!D_0035ed9c) return;
    if (func_00139d78(D_0035ed8c)) return;
    s32 id = D_0035f3d4 + 1;
    s32 n = func_0028afa8(D_0035ed70);
    for (s32 i = 0; i < n; i++) {
        u8* o = func_002891b8(D_0035ed70, i);
        u8* a = o + 24;
        if ((u8)((D_0035ed9c >> i) & 1)) {
            func_0028d8c0__93727(D_0035ed8c + i * 408, id, 0, 0, D_0035ed78, 38, -1, 0);
            func_0028dcc0__93727(D_0035ed8c + i * 408, o);
            func_00139648(D_0035ed8c + i * 408);
            u32 x = func_0023aa18(a);
            func_00138c68(D_0035ed8c + i * 408, x, func_0023aa38(a));
        }
    }
    func_0024b0e8();
}

struct It70 { u8 type; u8 pad[3]; u32 v; };
extern u8* D_0035ede4;
extern char* D_0035edf8;
extern u32 D_0035edcc;
extern s32 D_0035edf4;
extern u8 D_003722e0[];
extern u8 D_003722e8[];
extern char D_00372140[];
extern char D_00372150[];
s32 func_00139d78(void*);
void func_002fde18(void*, s32, s32);
s32 func_002891e8(u32);
It70* func_001d56c8(u8);
u32 func_00192048__94859(s32) asm("func_00192048");
s32 func_00192c40(u32, char*);
void func_0014ca80(u32, s32*, s32*, s32*, s32*);
char* func_00192cc0(char*, const char*, ...);
s32 func_00192b30(char*);
void func_00192c90(u32, char*);
void func_0024e228(void)
{
    if (!func_00139d78(D_0035ede4)) return;
    func_002fde18(D_0035edf8, 0, 32);
    char* buf = D_0035edf8;
    s32 n;
    s32 i = func_002891e8(D_0035edcc);
    It70* it = func_001d56c8((!D_0035edf4 ? D_003722e0 : D_003722e8)[i]);
    if (it->type == 4) {
        n = func_00192c40(func_00192048__94859(0xcb99), buf);
        s32 a, b, c, d;
        func_0014ca80(it->v, &a, &b, &c, &d);
        func_00192cc0(buf + n, D_00372140, b, c, d);
    } else if (it->type == 3) {
        n = func_00192b30(func_00192cc0(buf, D_00372150, it->v));
        u32 msg = func_00192048__94859(0xcb98);
        func_00192c90(msg, buf + n);
    } else if (it->type == 6) {
        n = func_00192b30(func_00192cc0(buf, D_00372150, it->v));
        u32 msg = func_00192048__94859(0xcc90);
        func_00192c90(msg, buf + n);
    } else {
        func_00192c90(func_00192048__94859(0xcb9b), buf);
    }
}

extern s8 D_0035ee51;
extern u8* D_0035ee48;
extern s32 D_0035f3d4;
extern u32 D_0035ee34;
extern u32 D_0035ee3c;
s32 func_00139d78(void*);
s32 func_002892f8(u32);
u8* func_002891b8(u32, s32);
void func_0028d8c0__96362(u8*, s32, s32, s32, u32, s32, s32, s32) asm("func_0028d8c0");
void func_0028dcc0__96362(u8*, u8*) asm("func_0028dcc0");
void func_00139648(u8*);
u32 func_0023aa18(u8*);
u32 func_0023aa38(u8*);
void func_00138c68(u8*, u32, u32);
void func_00250998(void);
void func_002507a0(void)
{
    if (!D_0035ee51) return;
    if (func_00139d78(D_0035ee48)) return;
    s32 id = D_0035f3d4 + 1;
    s32 n = func_002892f8(D_0035ee34);
    for (s32 i = 0; i < n; i++) {
        u8* o = func_002891b8(D_0035ee34, i);
        u8* a = o + 24;
        if ((u8)((D_0035ee51 >> i) & 1)) {
            func_0028d8c0__96362(D_0035ee48 + i * 408, id, 0, 0, D_0035ee3c, 35, -1, 0);
            func_0028dcc0__96362(D_0035ee48 + i * 408, o);
            func_00139648(D_0035ee48 + i * 408);
            u32 x = func_0023aa18(a);
            func_00138c68(D_0035ee48 + i * 408, x, func_0023aa38(a));
        }
    }
    func_00250998();
}

struct ObB74 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    u8 pad[432];
};
struct Sys74 {
    u8 w0[816];
    u8 w1[816];
    u8 w2[3376 - 1632];
    ObB74 a[24];
    u8 pad[24304 - 3376 - 24 * 436];
    ObB74 b[24];
};
extern u32 D_0035f01c;
extern u32 D_0035f020;
extern u32 D_0035f024;
Sys74* func_00257770(void);
s32 func_00139d78(void*);
void func_00139510__97494(void*) asm("func_00139510");
s32 func_0028acc8(u32);
void func_0028abe0(u32);
void LeaveWarn74(void) asm("_ZN2Tz6CmItem9LeaveWarnEv");
void LeaveWarn74(void)
{
    Sys74* s = func_00257770();
    if (func_00139d78(s)) func_00139510__97494(s);
    if (func_00139d78(s->w2)) func_00139510__97494(s->w2);
    u8* x = (u8*)s + 0xb350;
    if (func_00139d78(x)) func_00139510__97494(x);
    if (func_0028acc8(D_0035f01c)) func_0028abe0(D_0035f01c);
    if (func_0028acc8(D_0035f020)) func_0028abe0(D_0035f020);
    if (func_0028acc8(D_0035f024)) func_0028abe0(D_0035f024);
    for (s32 i = 0; i < 24; i++) {
        if (func_00139d78(&s->a[i])) s->a[i].v5();
        if (func_00139d78(&s->b[i])) s->b[i].v5();
    }
    if (func_00139d78(s->w1)) func_00139510__97494(s->w1);
}

s32 func_002aa098(s32);
s32 func_002aa2f8(s32);  // test_bit_global_b
s32 func_002aaa38(s32);  // test_bit_global_a
s32 func_002aae88(s32);
s32 func_002ab2b0(s32);
s32 func_002ab540(s32);
s32 func_002ab8e8(s32);
s32 func_002abc60(s32);
s32 func_002ac420(s32);
s32 func_002ac748(s32);
s32 func_002aa668(s32, s32);
s32 func_002abff0(s32, s32);
s32 func_002a1b18(s32, s32);
s32 func_002ac9b0(s32 a)
{
    if (a == 15) {
        if (func_002aa098(-1)) return 1;
        if (func_002aa2f8(-1)) return 1;
        if (func_002aaa38(-1)) return 1;
        if (func_002aae88(-1)) return 1;
        if (func_002ab2b0(-1)) return 1;
        if (func_002ab540(-1)) return 1;
        if (func_002ab8e8(-1)) return 1;
        if (func_002abc60(-1)) return 1;
        if (func_002ac420(-1)) return 1;
        if (func_002ac748(-1)) return 1;
    } else {
        if (func_002aa668(a, -1)) return 1;
        if (func_002aae88(a)) return 1;
        if (func_002ab2b0(a)) return 1;
        if (func_002ab540(a)) return 1;
        if (func_002ab8e8(a)) return 1;
        if (func_002abff0(a, -1)) return 1;
        if (func_002a1b18(0, a)) return 1;
        if (func_002a1b18(1, -1)) return 1;
        if (func_002ac748(a)) return 1;
    }
    return 0;
}

struct Ent80 { u8 b[432]; };
struct Lyt80 { u8 b[76]; };
struct Prm80 { u8 b[32]; };
struct Obj80 {
    u8 pad[188];
    Lyt80 lyt[9];
    u8 pad2[1320 - 188 - 9 * 76];
    Ent80 a[8];
    Ent80 b[8];
    u8 pad3[8244 - 4776 - 8 * 432];
    s32 st;
    u32 pad4;
    s32 na;
    s32 nb;
};
extern u8 D_003755a0[];
extern u8 D_003755a8[];
extern Prm80 D_00375640[];
extern u8 D_01e2bd30[];
u32 func_002c3268__99908(Obj80*) asm("func_002c3268");
void func_0028b4c0__99908(Ent80*, u32) asm("func_0028b4c0");
void func_0028b4f0__99908(Ent80*, u8*) asm("func_0028b4f0");
void func_0023f778__99908(Lyt80*, u32) asm("func_0023f778");
void func_0023f7a8__99908(Lyt80*, Prm80*) asm("func_0023f7a8");
s32 func_00139d78(void*);
void func_00138c10__99908(u8*, s32) asm("func_00138c10");
void func_002cb0e8(u8*, u8*, f32);
void func_002c34d0(Obj80* o)
{
    if (o->st != 3) o->st = 3;
    for (s32 i = 0; i < o->na; i++) {
        func_0028b4c0__99908(&o->a[i], func_002c3268__99908(o));
        func_0028b4f0__99908(&o->a[i], D_003755a0);
    }
    for (s32 i = 0; i < o->nb; i++) {
        func_0028b4c0__99908(&o->b[i], func_002c3268__99908(o));
        func_0028b4f0__99908(&o->b[i], D_003755a8);
    }
    for (s32 i = 0; i < 9; i++) {
        func_0023f778__99908(&o->lyt[i], func_002c3268__99908(o));
        func_0023f7a8__99908(&o->lyt[i], &D_00375640[i]);
    }
    u8* t = (u8*)o + 11872;
    if (func_00139d78(t)) {
        func_00138c10__99908(t, 96);
        *(s32*)(t + 392) = 1;
    }
    func_002cb0e8((u8*)o + 13620, D_01e2bd30, 0.0f);
}

struct Obj81 { u32 p0; u32 p4; };
struct Ent81 { u8 pad[8]; u32 k; };
void func_002bfd48(Obj81*, u32);
u32 func_002c6218(void);
void func_002c6280(u32, s32);
s32 func_001b8d60(u8*);
void func_00102448(u32, s32);
Ent81* func_001b8800_101452(u8) asm("func_001b8800");
void func_001b8988(Ent81*, s32);
void func_002fe0c0(void*, s32, s32, void*);
s32 func_002bfcf8(const void*, const void*);
void func_002bfb90(Obj81* o)
{
    if (o->p4) {
        func_002bfd48(o, o->p4);
    } else {
        u8 ids[256];
        u32 seen[256];
        s32 n = func_001b8d60(ids);
        if (!n) return;
        func_00102448(o->p0, 0);
        s32 i;
        s32 cnt = 0;
        for (i = 0; i < n; i++) func_001b8988(func_001b8800_101452(ids[i]), 1);
        func_002fe0c0(ids, n, 1, (void*)func_002bfcf8);
        for (s32 j = 0; j < n; j++) {
            Ent81* e = func_001b8800_101452(ids[j]);
            u32 k = e->k;
            if (!k) continue;
            s32 t;
            for (t = 0; t < cnt; t++) {
                if (seen[t] == k) break;
            }
            if (t != cnt) continue;
            func_002bfd48(o, e->k);
            seen[cnt++] = e->k;
        }
    }
    func_002c6280(func_002c6218(), 2);
}

struct Rec83 { u8 pad[8]; u32 v; };
struct Obj83 { u32 vt; u8 pad[84]; u8 b88; u8 pad2[7]; u32 h; u32 pad3; u8 sub[4]; void* m; };
extern u8 D_00362eb8[];
extern u8 D_00375f18[];
extern u8 D_00362e80[];
extern u8* D_0034e948;
void func_002ce958_102666(Obj83*, s32, u32, s32) asm("func_002ce958");
void func_002e34b8(u8*);
void func_002ceae8_102666(Obj83*, char*, u8*) asm("func_002ceae8");
u32 func_001708f8(char*, s32);
Rec83* func_00168b38_102666(u32, s32, s32) asm("func_00168b38");
void func_002e34c0(u8*, u32);
void func_002e64b0(u32);
u32 func_001050c8(void);
void* func_001063c0(s32, u32);
void func_002e6fc0(void*, u32);
void func_002cedd0(s32, u8*);
void func_0016bd60(u8*, s32);
u8* func_0016b740(s32);
void func_002e2350_102666(Obj83*) asm("func_002e2350");
void func_002e20d8(Obj83* o, u32 a)
{
    func_002ce958_102666(o, 5, a, 0);
    o->vt = (u32)D_00362eb8;
    func_002e34b8(o->sub);
    char name[64];
    func_002ceae8_102666(o, name, D_00375f18);
    u32 h = func_001708f8(name, -1);
    o->h = h;
    func_00168b38_102666(h, 42, 0);
    func_002e34c0(o->sub, func_00168b38_102666(h, 42, 0)->v);
    func_00168b38_102666(h, 42, 1);
    u32 x = func_00168b38_102666(h, 42, 1)->v;
    func_002e64b0(x);
    void* m = func_001063c0(12, func_001050c8());
    func_002e6fc0(m, x);
    o->m = m;
    func_002cedd0(3, D_00362e80);
    u8* p = D_0034e948;
    func_0016bd60(p, 53);
    *(u32*)(p + 264) |= 1;
    p = func_0016b740(2113);
    func_0016bd60(p, 54);
    *(u32*)(p + 264) |= 1;
    func_002e2350_102666(o);
    o->b88 = 1;
}

struct Pr84 { s32 x, y; };
struct St84 {
    s32 a[16]; s32 f64; s32 b[16]; s32 f132; s32 c[3]; s32 d[6]; s32 e[16]; s32 f[16]; s32 g[4];
    s32 f316, f320; Pr84 h[10]; Pr84 k[10]; s16 f484, f486;
};
void func_00319a60(St84* s)
{
    s32 i;
    for (i = 0; i < 16; i++) s->a[i] = 0;
    s->f64 = 0;
    { s32* p = s->b; i = 16; while (i--) *p++ = 0; }
    s->f132 = 0;
    for (i = 0; i < 3; i++) s->c[i] = 0;
    for (i = 0; i < 6; i++) s->d[i] = 0;
    { s32* p = s->e; i = 16; while (i--) *p++ = 0; }
    for (i = 0; i < 16; i++) s->f[i] = 0;
    for (i = 0; i < 4; i++) s->g[i] = 0;
    s->f316 = 0;
    s->f320 = 0;
    { Pr84* p = s->h; i = 10; while (i--) { p->x = 0; p->y = 0; p++; } }
    { Pr84* p = s->k; i = 10; while (i--) { p->x = 0; p->y = 0; p++; } }
    s->f484 = 0;
    s->f486 = 0;
}

struct V86 {
    f32 x, y, z, w;
    V86() {}
    V86& operator=(const V86& o) { if (this != &o) QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
// VU0 vector helpers: hand-written macro code in the original.
static inline V86 Sub86(const V86& a, const V86& b)
{
    V86 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1,0(%1)\n\tlqc2 $vf2,0(%2)\n\tvsub.wxyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline void Norm86(V86& v)
{
    asm volatile("lqc2 $vf1,0(%0)\n\tvmul.xyz $vf2,$vf1,$vf1\n\tvaddy.x $vf2,$vf2,$vf2y\n\tvaddz.x $vf2,$vf2,$vf2z\n\t"
                 "vsqrt Q,$vf2x\n\tvwaitq\n\tcfc2.ni $8,$vi22\n\tvaddq.x $vf2,$vf0,Q\n\tmtc1 $8,$f0\n\tvnop\n\t"
                 "vdiv Q,$vf0w,$vf2x\n\tvwaitq\n\tvmulq.xyz $vf1,$vf1,Q\n\tsqc2 $vf1,0(%0)"
                 : : "r"(&v) : "$8", "$f0", "memory");
}
static inline void Cross86(V86& r, const V86& a, const V86& b)
{
    asm volatile("lqc2 $vf1,0(%1)\n\tlqc2 $vf2,0(%2)\n\tvsub.wxyz $vf3,$vf0,$vf0\n\t"
                 "vopmula.xyz ACC,$vf1,$vf2\n\tvopmsub.xyz $vf3,$vf2,$vf1\n\tsqc2 $vf3,0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
}
static inline void AddTo86(V86& a, const V86& b)
{
    asm volatile("lqc2 $vf1,0(%0)\n\tlqc2 $vf2,0(%1)\n\tvadd.wxyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,0(%0)"
                 : : "r"(&a), "r"(&b) : "memory");
}
struct Cam86 { u8 pad[80]; V86 eye; V86 at; V86 up; };
void func_00107700(Cam86* c, f32 dx, f32 dy)
{
    V86 side, up, fwd;
    fwd = Sub86(c->eye, c->at);
    Norm86(fwd);
    up = c->up;
    Norm86(up);
    Cross86(side, up, fwd);
    Norm86(side);
    Cross86(up, fwd, side);
    fwd.x = side.x * dx + up.x * dy;
    fwd.y = side.y * dx + up.y * dy;
    fwd.z = side.z * dx + up.z * dy;
    AddTo86(c->eye, fwd);
    AddTo86(c->at, fwd);
}

struct Rec91 { u16 id; u8 pad[26]; u8 b28; u8 pad2[3]; u16 h32; };
struct Dat91 { u8 pad; u8 kind; };
struct Wk91 { u8 pad[52]; u32 snd; };
union U91 { Wk91* p; u8 c; };
extern U91 D_01d48cb0_106899 asm("D_01d48cb0");
Rec91* func_001b8e88(u32);
Dat91* func_001d3fe0(u16);
Wk91* func_001050d8_106899(s32) asm("func_001050d8");
void func_001b47d8(Wk91*, Dat91*, u8*, f32);
s32 func_001d3f80(Dat91*);
void func_00179a68(u8*, f32);
s32 func_001b5c60(Rec91*);  // to_1bbf80_field28
void func_00187650(u8*, s32, s32);
void func_00176d68(u8*, u8);
u8* func_0017df58(s32);
s32 func_0019ba60(u8*);
void func_001c9780(u8*, f32);
void func_001b5250(Wk91*, s32);
void func_001d6148(u8*, u32);
void func_0016cce8_106899(u32, s32, u32*, s32, s32) asm("func_0016cce8");
void func_001b4430(u32 id, u8* e)
{
    Rec91* r = func_001b8e88(id);
    Dat91* d = func_001d3fe0(r->id);
    if (d) {
        Wk91* w = func_001050d8_106899(220);
        func_001b47d8(w, d, e, r->h32);
        D_01d48cb0_106899.p = w;
        if (func_001d3f80(d)) func_00179a68(e, -r->b28);
        else func_00187650(e, -func_001b5c60(r), 0);
        if (d->kind != 1) func_00176d68(e, d->kind);
        for (s32 i = 0; i < 2; i++) {
            u8* p = func_0017df58(i);
            if (!func_0019ba60(p)) continue;
            if (*(u32*)(p + 1416) & 0x400000) continue;
            if (p[2892]) continue;
            func_001c9780(p, 0.0f);
        }
        func_001b5250(D_01d48cb0_106899.p, 1);
    } else {
        func_001d6148(e, id);
        u32 arg[1];
        arg[0] = id;
        func_0016cce8_106899(D_01d48cb0_106899.p->snd, 23, arg, 1, 0);
    }
}

struct Sp90 { f32 r; f32 h; u32 pad; f32 x, y, z; u8 pad2[8]; };
struct Obj90 { union { s32 n; f32 nf; }; u8 pad[16]; Sp90 s[1]; };
void func_00144450(f32*);
void func_001447c0(f32*, f32, f32, f32, f32, f32, f32);
#define MIN90(a, b) ((a) < (b) ? (a) : (b))
void func_001b7c80(Obj90* o, f32* b)
{
    if (!o->n) {
        func_00144450(b);
        return;
    }
    func_001447c0(b, o->s[0].x - o->s[0].r, o->s[0].y - o->s[0].h, o->s[0].z - o->s[0].r,
                  o->s[0].x + o->s[0].r, o->s[0].y + o->s[0].h, o->s[0].z + o->s[0].r);
    for (s32 i = 1; i < o->n; i++) {
        Sp90* s = &o->s[i];
        b[0] = MIN90(b[0], s->x - s->r);
        b[1] = MIN90(b[1], s->y - s->h);
        b[2] = MIN90(b[2], s->z - s->r);
        b[3] = MIN90(b[3], s->x + s->r);
        b[4] = MIN90(b[4], s->y + s->h);
        b[5] = MIN90(b[5], s->z + s->r);
    }
}

struct Gs100 { u8 pad[128]; u8* tab; u8 pad2[36]; u64 st; };
struct Idx100 { s32 f0; s32 f4; s32 f8; };
struct Ctx100 { u8 pad[12]; Idx100* idx; };
struct Req100 { s32 id; s32 snd; s32 off; u8 on; };
extern s32 D_01d9ea9c;
extern Gs100* D_01d9e6e0;
u8* func_001e7a98(Gs100*, u8*);
void func_002226b8(u8*, u8*);  // vec3_copy
void func_001fc1a0(u8* o, Req100* r, Ctx100* c)
{
    u8* sa = o + c->idx->f8 + 160;
    if (*sa & 2) return;
    if (*(s32*)(o + 12) == r->id) {
        if (r->on) *sa |= 1;
        else *sa &= ~1;
    }
    if (D_01d9ea9c) return;
    if (D_01d9e6e0->st & 0xff0000ff00ULL) return;
    u8* sb = o + c->idx->f4 + 160;
    u8 en = sb[16] & 1;
    if (!en) return;
    if (r->snd == -1) return;
    u8* w = 0;
    u8* q = D_01d9e6e0->tab + r->snd * 16;
    if (q) {
        w = func_001e7a98(D_01d9e6e0, q);
        *(u8**)(w + 4) = o;
    }
    u8* sc = o + c->idx->f0 + 160;
    u8* dst = w + r->off + 160;
    u8 hit = *sa & 1;
    if (!hit) {
        *sa |= 2;
        sc = sb;
    }
    func_002226b8(dst, sc);  // vec3_copy
}

extern s8 D_0035ed14;
extern u8* D_0035ed04;
extern s32 D_0035f3d4;
extern u32 D_0035ece8;
extern u32 D_0035ecf0;
s32 func_00139d78(void*);
s32 func_00244938(s32);
u8* func_002891b8(u32, s32);
void func_0028d8c0_110390(u8*, s32, s32, s32, u32, s32, s32, s32) asm("func_0028d8c0");
void func_0028dcc0_110390(u8*, u8*) asm("func_0028dcc0");
void func_00139648(u8*);
u32 func_0023aa18(u8*);
u32 func_0023aa38(u8*);
void func_00138c68(u8*, u32, u32);
void func_00244e28(void);
void func_00244c30(void)
{
    if (!D_0035ed14) return;
    if (func_00139d78(D_0035ed04)) return;
    s32 id = D_0035f3d4 + 1;
    s32 k = 0;
    for (s32 i = 0; i < 2; i++) {
        if (!func_00244938(i)) continue;
        u8* o = func_002891b8(D_0035ece8, k);
        u8* a = o + 24;
        if ((u8)((D_0035ed14 >> i) & 1)) {
            func_0028d8c0_110390(D_0035ed04 + k * 408, id, 0, 0, D_0035ecf0, 38, -1, 0);
            func_0028dcc0_110390(D_0035ed04 + k * 408, o);
            func_00139648(D_0035ed04 + k * 408);
            u32 x = func_0023aa18(a);
            func_00138c68(D_0035ed04 + k * 408, x, func_0023aa38(a));
        }
        k++;
    }
    func_00244e28();
}

extern s8 D_0035edc5;
extern u8* D_0035edbc;
extern s32 D_0035f3d4;
extern u32 D_0035eda8;
extern u32 D_0035edb0;
s32 func_00139d78(void*);
s32 func_0028afa8(u32);
u8* func_002891b8(u32, s32);
void func_0028d8c0_111552(u8*, s32, s32, s32, u32, s32, s32, s32) asm("func_0028d8c0");
void func_0028dcc0_111552(u8*, u8*) asm("func_0028dcc0");
void func_00139648(u8*);
u32 func_0023aa18(u8*);
u32 func_0023aa38(u8*);
void func_00138c68(u8*, u32, u32);
void func_0024c898(void);
void func_0024c6a0(void)
{
    if (!D_0035edc5) return;
    if (func_00139d78(D_0035edbc)) return;
    s32 id = D_0035f3d4 + 1;
    s32 n = func_0028afa8(D_0035eda8);
    for (s32 i = 0; i < n; i++) {
        u8* o = func_002891b8(D_0035eda8, i);
        u8* a = o + 24;
        if ((u8)((D_0035edc5 >> i) & 1)) {
            func_0028d8c0_111552(D_0035edbc + i * 408, id, 0, 0, D_0035edb0, 38, -1, 0);
            func_0028dcc0_111552(D_0035edbc + i * 408, o);
            func_00139648(D_0035edbc + i * 408);
            u32 x = func_0023aa18(a);
            func_00138c68(D_0035edbc + i * 408, x, func_0023aa38(a));
        }
    }
    func_0024c898();
}

extern u32 D_0035f010;
extern s8 D_0035f058;
extern s8 D_0035f059;
extern s8 D_0035f05a;
extern s8 D_0035f064;
extern u8 D_0035f060[];
s32 func_00281100(u32);
s32 func_002813b8(void);
s32 func_0027aa78(void);
u8* func_001a8bd0(s32);
s32 func_001a8bf8(u8*, s32);  // get_bits5_at
void func_00257000(void);
void func_00257c78(void)
{
    s32 i = 0;
    s32 cnt = 0;
    s32 cur = func_00281100(D_0035f010);
    s32 m = func_002813b8();
    for (; i < 7; i++) cnt += (m >> i) & 1;
    s32 flag = func_0027aa78() != 0;
    s32 d = 0;
    if (cur != D_0035f058 || D_0035f059 != cnt || D_0035f05a != flag || D_0035f064 != D_0032bae0) d = 1;
    s32 chg = d;
    if (!d && cur == D_0035f058) {
        u8* a = func_001a8bd0(-1);
        for (i = 0; i < 4; i++) {
            if (func_001a8bf8(D_0035f060, i) != func_001a8bf8(a, i)) {  // get_bits5_at
                chg = 1;
                break;
            }
        }
    }
    if (chg) func_00257000();
    D_0035f059 = cnt;
    D_0035f05a = flag;
    D_0035f058 = cur;
    D_0035f064 = D_0032bae0;
}

struct Sub96 { u8 pad[184]; u32 fl; };
union UA96 { u8* p; u32 u; };
union UB96 { s8* p; u32 u; };
extern UA96 D_0035f5d8;
extern UB96 D_0035f5d4;
extern s32 D_0035f3d4;
extern u32 D_0035f14c;
extern u32 D_0035f148;
extern u32 D_0035f210;
extern u32 D_00374b3c;
extern u32 D_00374b40;
s32 func_00139d78(void*);
void func_00139510_113723(void*) asm("func_00139510");
u8* func_002766d0(void);
s32 func_00287bc0(void);
void func_0028d8c0_113723(u8*, s32, u32, u32, u32, u32, s32, s32) asm("func_0028d8c0");
void func_0028dcc0_113723(u8*, u8*) asm("func_0028dcc0");
static inline void Flag96(u8* e) { Sub96* sb = (Sub96*)(e + 24); sb->fl |= 8; }
void func_002a1220(void)
{
    s32 a = func_00139d78(D_0035f5d8.p + 816);
    s32 b = func_00139d78(D_0035f5d8.p + 408);
    u8* w = func_002766d0();
    if (!a) {
        if (b) func_00139510_113723(D_0035f5d8.p + 408);
        return;
    }
    if (!b) {
        if (D_0035f5d4.p[1] < 0) return;
        s32 id = D_0035f3d4 + 4;
        u32 x = func_00287bc0() == 6 ? D_00374b3c : D_00374b40;
        func_0028d8c0_113723(D_0035f5d8.p + 408, id, D_0035f14c, D_0035f148, D_0035f210, x, -1, 0);
        Flag96(D_0035f5d8.p + 408);
        func_0028dcc0_113723(D_0035f5d8.p + 408, w + D_0035f5d4.p[1] * 408 + 17304);
    } else {
        s32 k = D_0035f5d4.p[1];
        if (k < 0) {
            func_00139510_113723(D_0035f5d8.p + 408);
            return;
        }
        func_0028dcc0_113723(D_0035f5d8.p + 408, w + k * 408 + 17304);
        return;
    }
}

struct Ref99 { u8 pad[36]; s32 ref; };
struct Hdr99 { u32 type; u8 pad; u8 kind; };
struct Node99 { u32 a; u8 sub[4]; s32 cat; u32* p; u32 f16; u32 b; Ref99* r0; Ref99* r1; u32 pad; s32 f36; };
extern Node99* D_00361fa4;
extern s32 D_00361fb0[];
Hdr99* func_0016e920(u32);
s32 func_002d0200(Hdr99*);
s32 func_002cf638_115228(s32) asm("func_002cf638");
void func_002cf2d0(u8*);
void func_002cf280(u8*, s32, s32);
Node99* func_002cf750(u32 a, u32 b, u32* p, Ref99* r0, Ref99* r1)
{
    Hdr99* h = func_0016e920(*p);
    if (func_002d0200(h)) return 0;
    s32 idx = func_002cf638_115228(1);
    Node99* n = D_00361fa4 + idx;
    n->a = a;
    n->b = b;
    n->p = p;
    n->cat = 0;
    n->f16 = 0;
    n->r0 = r0;
    if (r0) r0->ref++;
    n->r1 = r1;
    if (r1) r1->ref++;
    func_002cf2d0(n->sub);
    n->f36 = 0;
    if (h->kind == 51) {
        func_002cf280(n->sub, 4, 0);
        switch (h->type) {
        case 2055: n->cat = 1; break;
        case 2054: n->cat = 2; break;
        case 2056: n->cat = 0; break;
        }
        D_00361fb0[n->cat]++;
    }
    return n;
}

struct Obj98 { u8 pad[28]; u8 pos[844]; u32 lst; u8 m[4]; };
s32 func_0028d008_116312(s32) asm("func_0028d008");
void func_0028cc78(s32, s32, s32, u8*, s32, s32);
u32 func_002891d0(u32);
void func_0028cf28(s32, u32);  // record408_set_and_refresh
s32 func_00289310(u32);
s32 func_002891e8(u32);
void func_002890e0(u32, s32, s32, s32, s32);
void func_00289038(u32, s32, s32, s32, s32, s32, s32);
void func_0028d660(u8*, u32);  // record_set_value_refresh
void func_001396b0_116312(u8*) asm("func_001396b0");
void func_002c40d8(Obj98* o)
{
    u32 lst = o->lst;
    if (!func_0028d008_116312(0)) {
        func_0028cc78(0, 1, 1, o->pos, 54, 54);
        func_0028cf28(0, func_002891d0(lst));  // record408_set_and_refresh
    }
    if (!func_0028d008_116312(1)) {
        func_0028cc78(1, 1, 1, o->pos, 13, 13);
        func_0028cf28(1, func_002891d0(lst));  // record408_set_and_refresh
    }
    if (!func_00289310(lst)) return;
    s32 k = func_002891e8(lst);
    func_002890e0(lst, 1, 2, 0, -1);
    func_00289038(lst, k, 1, 1, 2, 0, -1);
    func_0028cf28(0, func_002891d0(lst));  // record408_set_and_refresh
    func_0028cf28(1, func_002891d0(lst));  // record408_set_and_refresh
    func_0028d660(o->m, func_002891d0(lst));  // record_set_value_refresh
    func_001396b0_116312(o->m);
}

// ---- 00226478
HeapE* GetAllocatorE(void) asm("_ZN4AREA12GetAllocatorEv");
void* AllocE(u32 n) asm("_ZN4AREA5AllocEj");
void PaxCtorE(void* p) asm("_ZN3ryj3PAXC1Ev");
void EvAllocInitE(void* self, void* buf, s32 n) asm("_ZN2sa11EVENT_ALLOC4initEPvi");
void* func_00170b30(s32 n);  // alloc_align128
void func_00134668(void* p);
struct PoolA { u32 v; PoolA() { v = 0; } };
struct PoolB { s32 id; u32 v; PoolB() { id = -1; } };
struct PoolC { u32 a, b; PoolC() { a = 0; b = 0; } };
struct PoolD { u32 a, b, c; PoolD() { a = 0; b = 0; c = 0; } };
struct PoolE {
    u32 f0; s32 f4; u8 pad8[8]; u8 pax[32]; s16 f48; s16 pad50;
    PoolE() { PaxCtorE(pax); f4 = -1; f48 = -1; }
    ~PoolE() {}
    static void* operator new[](unsigned int n) { return AllocE(n); }
};
struct PoolF {
    s32 f0; u32 f4; u8 f8; u8 pad9[7]; s32 f16; u32 f20; u32 f24; u32 f28; u8 f32; u8 pad33[15]; u8 f48; u8 pad49[35];
    PoolF() { f16 = -1; f0 = -1; f4 = 0; f20 = 0; f28 = 0; f8 = 0; f32 = 0; f48 = 0; }
    static void* operator new[](unsigned int n) { return AllocE(n); }
};
struct PoolG {
    s32 f0; s32 f4; u32 f8; u8 pad[52];
    PoolG() { f0 = -1; f4 = -1; f8 = 0; }
    ~PoolG() {}
    static void* operator new[](unsigned int n) { return AllocE(n); }
} __attribute__((aligned(16)));
struct PoolH {
    s32 f0; s32 f4; u32 f8; u8 pad[10]; u8 f22; u8 f23; u8 pad2[16];
    PoolH() { f0 = -1; f4 = -1; f8 = 0; f22 = 0; f23 = 0; }
    static void* operator new[](unsigned int n) { return AllocE(n); }
};
struct PoolI {
    u8 d[112];
    PoolI() { func_00134668(this); }
    ~PoolI() {}
} __attribute__((aligned(16)));

extern PoolA* D_0035dce0;
extern PoolB* D_0035dce4;
extern PoolC* D_0035dce8;
extern PoolD* D_0035dcec;
extern u8 D_0035db00[];
extern void* D_0035db14;
extern s32 D_0035db18;
extern PoolF* D_0035dcf0;
extern PoolE* D_0035dcf4;
extern PoolG* D_0035dcf8;
extern PoolH* D_0035dcfc;
extern PoolI* D_0035dd00;

// Allocate and construct the event/effect object pools.
void func_00226478(void) {
    HeapE* heap = GetAllocatorE();
    if (!D_0035dce0) D_0035dce0 = new (heap) PoolA[128];
    if (!D_0035dce4) D_0035dce4 = new (heap) PoolB[128];
    if (!D_0035dce8) D_0035dce8 = new (heap) PoolC[64];
    if (!D_0035dcec) D_0035dcec = new (heap) PoolD[64];
    if (!D_0035db18) {
        D_0035db14 = 0;
        D_0035dcf4 = 0;
        D_0035dcf0 = 0;
        D_0035dcf8 = 0;
        D_0035dcfc = 0;
        D_0035dd00 = 0;
        return;
    }
    void* buf = func_00170b30(D_0035db18);  // alloc_align128
    EvAllocInitE(D_0035db00, buf, D_0035db18);
    D_0035db14 = buf;
    D_0035dcf4 = new PoolE[96];
    D_0035dcf0 = new PoolF[128];
    D_0035dcf8 = new PoolG[64];
    D_0035dcfc = new PoolH[96];
    D_0035dd00 = new (heap) PoolI[96];
}

// ---- 00254770
struct AllocVt254 { void* (*alloc)(void* self, u32 size, void* ra); };
struct AllocObj254 { AllocVt254* vt; };
struct Holder254 { u8 pad[20]; AllocObj254* al; };
extern u8 D_0035f057;
extern u8* g_menuObj254 asm("D_0035f03c");
extern u8* D_0035f040;
extern void* g_sel0_254 asm("D_0035f044");
extern void* g_sel1_254 asm("D_0035f048");
extern u32 D_0035ef68;
extern u32 D_0035ef64;
extern s32 D_0035f3d4;
extern u32 D_0035f018;
extern Holder254* D_00347f80;
extern AllocObj254* D_0032ba14;
extern u8 D_00347f98[];
extern u8 D_0035eb98[];
extern u8 D_0035ebb8[];
extern u8 D_00372988[], D_00372a18[], D_00372978[], D_003729a8[], D_003729b0[], D_003729b8[], D_00372990[], D_00372998[];
extern u16 D_00372aa6;
u8* func_0023ee30(u32 size);
void func_0031a838(u8* p);
void func_002369a0(u8* p);  // obj_ctor_36eac8
void func_0023c008(u8* p);  // obj_ctor_36eae8
void func_0028d7f0(u8* a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i);
void func_0023ef50(u8* p);
void func_00290cf0(u32 a, u8* b, u32 c, u32 d, s32 e, u8* f, u8* g);
void func_0028f280(u32 a, u32 b, u8* c, u8* d, u8* e);
void func_00263960(u32 a, u32 b, u8* c, u8* d, u8* e);  // store_globals_and_init
void func_002590b0(u8* a, u32 b, u8* c, u8* d, u8* e, s32 f, u32 g, u32 h);
u8* GetLayout254(u8* p) asm("func_0023f1b0");
u32 func_0023c4b8(u8* p, u32 a);
u32 func_00236ca8(u32 p, u32 a);
void func_0028fc78(void* p, u32 a, u32 b, u8* c);
void func_0028fe38(void* p, u32 a, u32 b, u32 c, u32 d);
void func_00290198(void* p, u32 a, u32 b, u32 c, u8* d);
void func_00290368(void* p, u32 a, u32 b, u32 c, u32 d);
void func_00292870(void);
s32 func_00287bc0(void);
void func_0028fb28(u32 a, u32 b);
void func_00257050(u32 a, u32 b, u32 c);
void func_0026bc10(void);
void func_0026c9c8(void);
void func_002551b8(void);
s32 func_002887c8(void);
void func_002550e8(void);
void func_002551a8(void);
void func_00288750(void (*fn)(void));

static inline void* Alloc254(u32 size) { return D_0032ba14->vt->alloc(D_0032ba14, size, __builtin_return_address(0)); }

// Build the menu layout objects for this screen and start its fade.
void func_00254770(void) {
    D_0035f057 = 0;
    u8* o = func_0023ee30(160);
    *(u8**)o = D_00347f98;
    func_0031a838(o + 12);
    *(u8**)o = D_0035eb98;
    func_002369a0(o + 24);  // obj_ctor_36eac8
    func_0023c008(o + 48);  // obj_ctor_36eae8
    g_menuObj254 = o;
    AllocObj254* al = D_00347f80->al;
    u8* m = (u8*)al->vt->alloc(al, 76, 0);
    *(u32*)(m + 12) = 0;
    *(u8**)m = D_0035ebb8;
    D_0035f040 = m;
    func_0028d7f0(g_menuObj254, 30002, 0, 0, 0, 1, 0, 0, 0);
    func_0023ef50(g_menuObj254);
    func_00290cf0(D_0035f018, g_menuObj254, D_0035ef68, D_0035ef64, D_0035f3d4 + 3, D_00372a18, D_00372978);
    func_0028f280(D_0035ef64, D_0035ef68, g_menuObj254, D_003729a8, D_003729b0);
    func_00263960(D_0035ef64, D_0035ef68, g_menuObj254, D_00372988, D_003729b8);  // store_globals_and_init
    func_002590b0(D_0035f040, 30003, g_menuObj254, D_00372988, D_00372990, -1, 0, 0);
    u32 seq = func_0023c4b8(GetLayout254(g_menuObj254), D_0035ef68);
    u8* lay = GetLayout254(g_menuObj254);
    u32 id = D_0035ef64;
    u32 img = func_00236ca8(*(u32*)(lay + 40), id);
    void* p = Alloc254(20);
    func_0028fc78(p, 31, 51, D_00372998);
    g_sel0_254 = p;
    func_0028fe38(p, 30011, seq, img, 0);
    p = Alloc254(20);
    func_00290198(p, 31, 71, 61, D_00372998 + 6);
    g_sel1_254 = p;
    func_00290368(p, 30011, seq, img, 0);
    func_00292870();
    s32 mode = func_00287bc0();
    if (mode == 20 || mode == 21) {
        func_0028fb28(0, D_00372aa6);
        func_00257050(0, 3, 0);
        if (mode == 20) func_0026bc10();
        else func_0026c9c8();
    } else {
        func_002551b8();
    }
    if (func_002887c8()) {
        func_002550e8();
        D_0035f057 = 1;
        func_00288750(func_002551a8);
    }
}

// ---- 0025a660
extern void* D_0035f650;
extern u8 D_0035f0b0;
s32 func_00287cd0(void);
s32 func_00289380(void* s);
s32 func_00287c10(void);
s32 func_0028acc8_a660(void* s) asm("func_0028acc8");
s32 func_00289310_a660(void* s) asm("func_00289310");
void func_0028abe0_a660(void* s) asm("func_0028abe0");
void func_002b4f50(void);
bool func_002b55e0(void);
s32 func_00233e70(s32 a);
s32 func_00233e60(void);
void func_00287c30(void);
void func_00287d20(s32 a);
s32 func_00287bc0(void);
void func_002b5af0(void);
void func_0028f7e8(s32 a);
void func_0025a1d0(void);
void func_00288018(void);  // global_zero_4dwords
void func_00240be0(void);
s32 func_002b4fb8(void);
void func_002b50f8(void);  // zero_global_byte_c
s32 func_00240ba0_a660(void) asm("func_00240ba0");
s32 func_002348a8_a660(s32 slot, s32 a) asm("func_002348a8");
void func_002b5108_a660(u32 msg, s32 slot) asm("func_002b5108");
void func_00287c00(s32 m);
void func_002b5558(void);
void func_00287cc0(s32 s);
void func_00234570_a660(s32 slot, void* p) asm("func_00234570");
void func_00287bd0(s32 a, s32 b);
s32 func_002b50e8(void);  // get_global_byte_c
s32 func_0028ae28(void* s, s32 a);
s32 func_00287df0(s32 a, s32 b, s32 c, s32 d, s32 e);
s32 func_00242848(s32 a);
void func_002b4ee0(void);
void func_0028f6f0(s32 a);  // record884_refresh_by_index

// Memory-card menu: per-frame state update.
void func_0025a660(void) {
    s32 cur;
    s32 st = func_00287cd0();
    if (st == 2) {
        cur = func_00289380(D_0035f650);
        s32 next = func_00287c10();
        s32 r;
        if (next == st) r = func_0028acc8_a660(D_0035f650);
        else r = func_002b4fb8();
        if (r) {
            if (cur == -1 && !func_00289310_a660(D_0035f650)) return;
            if (next == 2) func_0028abe0_a660(D_0035f650);
            else func_002b4f50();
            return;
        }
        bool ok = 1;
        if (next == 1 || next == 2) ok = !func_002b55e0();
        if (ok) {
            if (next == 1) {
                func_00233e70(0);
                if (!func_00233e60()) return;
            }
            func_00287c30();
            func_00287d20(0);
            s32 m = func_00287bc0();
            if (m == 1) {
                func_002b5af0();
                func_0028f7e8(1);
                func_0025a1d0();
            } else if (m == 2) {
                func_00240be0();
            }
            func_00288018();  // global_zero_4dwords
        }
        D_0035f0b0 = 1;
        return;
    }
    func_0028acc8_a660(D_0035f650);
    if (!func_00233e70(0)) {
        func_002b50f8();  // zero_global_byte_c
        if (D_0035f0b0) {
            s32 slot = func_00240ba0_a660();
            if (func_002348a8_a660(slot, 0) != 3) {
                if (func_00287bc0() == 5) {
                    func_002b5108_a660(0x8a89, slot);
                    func_00287c00(2);
                    func_0028abe0_a660(D_0035f650);
                    func_002b5558();
                    func_00287cc0(2);
                }
                func_00234570_a660(slot, 0);
                return;
            }
            if (func_00287bc0() != 5) {
                func_002b5108_a660(0xb85d, slot);
                func_00287bd0(5, func_00287cd0());
                func_00234570_a660(slot, 0);
                return;
            }
            func_00234570_a660(slot, 0);
        }
    }
    if (func_002b50e8()) return;
    if (st == 0 && func_0028ae28(D_0035f650, 0)) func_00287cc0(1);
    if (st != 1) return;
    cur = func_00289380(D_0035f650);
    if (func_00242848(func_00287df0(cur, func_00289310_a660(D_0035f650), 0, 0, 1))) return;
    s32 m = func_00287bc0();
    switch (cur) {
    case -1:
        break;
    case -2:
    case 0:
        if (m == 10 || m == 22) {
            func_00287c00(12);
        } else {
            func_002b5558();
            func_00287c00(1);
            func_0028f6f0(1);  // record884_refresh_by_index
        }
        func_002b4ee0();
        func_00287cc0(2);
        break;
    }
}

// ---- 0025b7b8
extern void* D_0035f64c;
s32 func_00287cd0(void);
s32 func_00289380(void* s);
s32 func_00289310_b7b8(void* s) asm("func_00289310");
s32 func_00233e70(s32 a);
bool func_002b55e0(void);
void func_002b5658(void);
void func_00287c30(void);
s32 func_00287bc0(void);
void func_0028af18_b7b8(void* s, u32 a) asm("func_0028af18");
void func_0028f7e8(s32 a);
void func_0025a1d0(void);
s32 func_00240ba0_b7b8(void) asm("func_00240ba0");
s32 func_002b5490(void);
void func_002b54f8(void);
void func_00287cc0(s32 s);
void func_0025d560(void);
s32 func_002348a8_b7b8(s32 slot, s32 a) asm("func_002348a8");
void func_00234570_b7b8(s32 slot, void* p) asm("func_00234570");
void func_0025d620(void);
s32 func_00287df0_b7b8(s32 a, s32 b, s32 c, void (*d)(void), s32 e) asm("func_00287df0");
s32 func_00242848(s32 a);
s32 func_0028afa8_b7b8(void* s) asm("func_0028afa8");
void func_00240bc0(s32 a);
void func_002b4dd0(s32 a);
s32 func_002419e8(void);
void func_002b5108_b7b8(u32 msg, s32 slot) asm("func_002b5108");
void func_002b4c88(s32 a);
void func_00287bd0(s32 a, s32 b);
void func_00263c60(void);  // sync_global_index_if_changed
s32 func_00288040(void);
void func_00288018(void);  // global_zero_4dwords
s32 func_00241c20(s32 a);
struct SaveEnt { u16 a; s16 b; u8 pad[4]; u32 flags; u8 pad2[20]; };
SaveEnt* func_00241f10(void);
s32 func_002408d0(s32 a);
void func_00241450(s32 a);
void func_00287d20(s32 a);
s32 func_00241770(s32 a);
void func_002400f8(s32 a);
void func_00287da0(void);
void func_002b5558(void);
void func_00287c00(s32 m);
void func_0028f6f0(s32 a);  // record884_refresh_by_index

// Memory-card load menu: per-frame state update.
void func_0025b7b8(void) {
    s32 cur = func_00289380(D_0035f64c);
    s32 st = func_00287cd0();
    s32 slot = func_00240ba0_b7b8();
    if (st == 2) {
        func_00233e70(0);
        if (func_002b55e0()) {
            if (cur == -1 && !func_00289310_b7b8(D_0035f64c)) return;
            func_002b5658();
            return;
        }
        func_00287c30();
        s32 m = func_00287bc0();
        func_0028af18_b7b8(D_0035f64c, 115);
        if (m == 1) {
            func_0028f7e8(1);
            func_0025a1d0();
        }
        return;
    }
    if (cur != -1 || func_00289310_b7b8(D_0035f64c)) {
        if (!func_002b5490()) func_002b54f8();
    }
    if (st == 0 && func_002b5490()) {
        func_00287cc0(1);
        func_0025d560();
    }
    if (!func_00233e70(0)) {
        if (func_002348a8_b7b8(slot, 0) != 3) {
            func_00234570_b7b8(slot, 0);
        } else {
            func_002b4dd0(-1);
            func_002b4c88(0);
            func_002b5108_b7b8(0xb85d, slot);
            func_00287bd0(5, 0);
            func_00234570_b7b8(slot, 0);
            func_00263c60();  // sync_global_index_if_changed
            return;
        }
    }
    if (!func_00242848(func_00287df0_b7b8(cur, func_00289310_b7b8(D_0035f64c), 1, func_0025d620, 1))) {
        switch (cur) {
        case -2:
            func_002b5558();
            func_00287cc0(2);
            func_00287c00(1);
            func_0028f6f0(1);  // record884_refresh_by_index
            func_00263c60();  // sync_global_index_if_changed
            break;
        case -4:
            func_00263c60();  // sync_global_index_if_changed
            func_00287da0();
            break;
        case -1:
            break;
        default:
            if (cur >= 0 && cur < func_0028afa8_b7b8(D_0035f64c)) {
                func_00240bc0(cur);
                func_002b4dd0(-1);
                if (func_002419e8()) {
                    func_002b5108_b7b8(0x8aa6, slot);
                    func_002b4c88(1);
                    func_00287bd0(8, 0);
                    func_00234570_b7b8(slot, 0);
                } else if (func_00241c20(cur) && func_00241f10()->b < func_002408d0(0)) {
                    func_00241450(1);
                    func_002b5108_b7b8(0x8a90, slot);
                    func_00287bd0(20, 0);
                    func_00287d20(60);
                } else if (func_00241770(cur)) {
                    func_00241450(1);
                    func_002b5108_b7b8(0x8aa4, slot);
                    func_00287bd0(13, 0);
                    func_002b4c88(1);
                    func_00234570_b7b8(slot, 0);
                } else if (*(u32*)((u8*)func_00241f10() + (cur << 5) + 8) & 0x40) {
                    func_002b5108_b7b8(0xc6c8, slot);
                    func_00287bd0(22, 0);
                    func_002b4c88(0);
                } else {
                    func_00241450(1);
                    func_002b5108_b7b8(0x8a90, slot);
                    func_00287bd0(14, 0);
                    func_00287d20(70);
                    func_002400f8(1);
                }
                func_00263c60();  // sync_global_index_if_changed
            }
            break;
        }
    }
    if (func_00288040()) func_00288018();
}

// ---- 002648b8
extern void* D_0035f01c_48b8 asm("D_0035f01c");
s32 func_00287cd0(void);
s32 func_00289380(void* s);
s32 func_00289310_48b8(void* s) asm("func_00289310");
s32 func_00287c10(void);
s32 func_0028f930(s32 a);
s32 func_002656c0(void);
s32 func_00257970(void);
void func_00287f90(s32 a);
void func_002655e8(void);
void func_0028f7e8(s32 a);
void func_00287c30(void);
s32 func_00287bc0(void);
void func_00267398(void);
void func_002551b8(void);
void func_00264be0(void);
s32 func_0028ae28(void* s, s32 a);
s32 func_00265740(void);
void func_0028ab20(void* s);
void func_00265780(void);
void func_0028fa98(s32 a);
void func_00287cc0(s32 s);
s32 func_00287df0_48b8(s32 a, s32 b, s32 c, void (*d)(void), s32 e) asm("func_00287df0");
s32 func_00242848(s32 a);
void func_00263c60(void);  // sync_global_index_if_changed
void func_00265580(void);
u8* func_002891b8_48b8(void* p, s32 n) asm("func_002891b8");
void func_0028fb68(s32 a, u32 b);
u32 func_002891e8_48b8(void* s) asm("func_002891e8");
u32 func_002670a0(u32 a);
void func_00257050_48b8(s32 a, u32 b, s32 c) asm("func_00257050");
void func_00287c00(s32 m);
void func_00287c90(s32 a);
void func_00287da0(void);
void func_0028f6f0(s32 a);  // record884_refresh_by_index
s32 func_00288040(void);
void func_00288018(void);  // global_zero_4dwords

// Party/item menu: per-frame state update.
void func_002648b8(void) {
    s32 cur = func_00289380(D_0035f01c_48b8);
    s32 st = func_00287cd0();
    if (st == 2) {
        s32 r = 0;
        s32 next = func_00287c10();
        if (next == 0) r = func_0028f930(0);
        if (func_002656c0() || r || func_00257970()) {
            if (cur == -1 && !func_00289310_48b8(D_0035f01c_48b8)) return;
            func_00287f90(0);
            func_002655e8();
            if (next == 0) func_0028f7e8(0);
            return;
        }
        func_00287c30();
        s32 m = func_00287bc0();
        if (m == 0) {
            func_0028f7e8(0);
            func_00267398();
            func_002551b8();
        } else if (m == 24) {
            func_00264be0();
        }
        return;
    }
    if (cur != -1 || func_00289310_48b8(D_0035f01c_48b8)) {
        if (!func_0028ae28(D_0035f01c_48b8, 0) || !func_00265740()) {
            func_0028ab20(D_0035f01c_48b8);
            func_00265780();
            func_0028fa98(-1);
        }
    }
    if (st == 0 && func_0028ae28(D_0035f01c_48b8, 0) && func_00265740()) func_00287cc0(1);
    if (!func_00242848(func_00287df0_48b8(cur, func_00289310_48b8(D_0035f01c_48b8), 1, 0, 1))) {
        switch (cur) {
        case -2:
            func_00263c60();  // sync_global_index_if_changed
            func_0028f6f0(0);  // record884_refresh_by_index
            func_00265580();
            func_00257050_48b8(23, func_002670a0(func_002891e8_48b8(D_0035f01c_48b8)), 0);
            func_00287c90(1);
            func_00287c00(0);
            break;
        case -4:
            func_00257050_48b8(23, func_002670a0(func_002891e8_48b8(D_0035f01c_48b8)), 0);
            func_00267398();
            func_00287da0();
            break;
        case -1:
            break;
        default:
            func_00263c60();  // sync_global_index_if_changed
            func_00265580();
            func_0028fb68(1, *(u32*)(func_002891b8_48b8(D_0035f01c_48b8, cur) + 408));
            func_00257050_48b8(23, func_002670a0(func_002891e8_48b8(D_0035f01c_48b8)), 0);
            func_00287c00(24);
            func_00287c90(1);
            break;
        }
    }
    if (func_00288040()) func_00288018();
}

// ---- 00268db8
extern void* D_0035f01c_8db8 asm("D_0035f01c");
extern void* D_0035f018_8db8 asm("D_0035f018");
extern void* D_0035f010_8db8 asm("D_0035f010");
extern void* D_0035f0ec;
s32 func_00287cd0(void);
s32 func_00289380(void* s);
s32 func_00289310_8db8(void* s) asm("func_00289310");
s32 func_00287bc0(void);
s32 func_00269f58(void);
s32 func_002911f8(void* p);
s32 func_0028f930(s32 a);
s32 func_00256ef0(void);
s32 func_00257970(void);
void func_00287f90(s32 a);
void func_00256c40(void);
void func_00269ef8(void);
void func_00291288(void* p);
s32 func_00287c10(void);
void func_00287c30(void);
void func_0028f7e8(s32 a);
void func_0026b008(void);
s32 func_00257070(s32 a);
u8* func_00281180(void* p, s32 i);
void func_00188ac8(u32 a);
void func_002678a8(void);
s32 func_00269fc0(void);
void func_0026a060(void);
void func_0028fa98(s32 a);
void func_00269a60(void);
void func_00287c90(s32 a);
s32 func_0028afa8_8db8(void* s) asm("func_0028afa8");
void func_0026b8f0(void);
s32 func_00287df0_8db8(s32 a, s32 b, s32 c, void (*d)(void), s32 e) asm("func_00287df0");
s32 func_00242848(s32 a);
struct Ent268 { u16 id; u8 pad[4]; };
Ent268* func_00281f20(void* p);
s32 func_0026b2c0(void);
void func_00269378(void);
void func_00287bd0(s32 a, s32 b);
void func_00287c00(s32 m);
void func_00281d48(void);
void func_00281e20(void);
s32 func_00288040(void);
void func_00288018(void);  // global_zero_4dwords
void func_0026ab18(u32 id);
void func_0028f6f0(s32 a);  // record884_refresh_by_index
void func_00256e80(void);
void func_00263c60(void);  // sync_global_index_if_changed
void func_00269e20(void);
void func_00281b30_8db8(void) asm("func_00281b30");
void func_002831e0(s32 a, s32 b);
void func_00287cc0(s32 s);
void func_0026b448(void);
void func_00287da0(void);

// Item-list menu: per-frame state update.
void func_00268db8(void) {
    s32 busy = 0;
    s32 cur = func_00289380(D_0035f01c_8db8);
    s32 st = func_00287cd0();
    s32 mode = func_00287bc0();
    if (st == 2) {
        if (func_00269f58() || func_002911f8(D_0035f018_8db8) || func_0028f930(2) || func_00256ef0()) busy = 1;
        if (busy || func_00257970()) {
            if (cur == -1 && !func_00289310_8db8(D_0035f01c_8db8)) return;
            func_00287f90(0);
            func_00256c40();
            func_00269ef8();
            func_00291288(D_0035f018_8db8);
            return;
        }
        func_00287c10();
        func_00287c30();
        func_0028f7e8(2);
        func_0026b008();
        func_00188ac8(*(u32*)(func_00281180(D_0035f010_8db8, func_00257070(1)) + 580));
        func_002678a8();
        return;
    }
    if (cur != -1 || func_00289310_8db8(D_0035f01c_8db8)) {
        if (!func_00269fc0()) {
            func_0026a060();
            func_0028fa98(-1);
        }
    }
    if (st == 0 && func_00269fc0()) {
        func_00269a60();
        func_00287c90(1);
    }
    s32 max = func_0028afa8_8db8(D_0035f01c_8db8);
    if (!func_00242848(func_00287df0_8db8(cur, func_00289310_8db8(D_0035f01c_8db8), 1, func_0026b8f0, 1))) {
        switch (cur) {
        case -4:
            func_0026b448();
            func_00291288(D_0035f018_8db8);
            func_0026b008();
            func_00188ac8(*(u32*)(func_00281180(D_0035f010_8db8, func_00257070(1)) + 580));
            func_00287da0();
            break;
        case -7:
            func_00287bd0(37, 0);
            if (mode == 9) func_002831e0(0, 9);
            else if (mode == 6) func_002831e0(3, 6);
            break;
        case -2:
            func_00263c60();  // sync_global_index_if_changed
            func_0028f6f0(2);  // record884_refresh_by_index
            func_00256e80();
            func_00269e20();
            func_00281b30_8db8();
            func_00287cc0(2);
            func_00287c00(2);
            break;
        case -1:
            break;
        default:
            if (cur >= 0 && cur < max) {
                Ent268* tbl = func_00281f20(D_0035f0ec);
                if (func_0026b2c0()) {
                    func_00269378();
                    func_00287bd0(4, 0);
                    func_00287c00(mode);
                } else {
                    s32 idx = cur - (mode != 5 && mode != 6);
                    func_0026ab18(idx >= 0 ? tbl[idx].id : 0);
                    func_0028f6f0(2);  // record884_refresh_by_index
                    func_00256e80();
                    func_00263c60();  // sync_global_index_if_changed
                    func_00269e20();
                    func_00281b30_8db8();
                    func_00287c90(1);
                    func_00287c00(2);
                }
            }
            break;
        }
    }
    if (func_00287cd0() == 1) {
        func_00281d48();
        func_00281e20();
    }
    if (func_00288040()) func_00288018();
}

// ---- 002d0290
struct Src2d0 { s32 id; u8 pad; u8 type; };
struct Vec2d0 { f32 x, y, z, w; };
u8* AllocR(u32 size) asm("_ZN4AREA5AllocEj");
u32 func_00167f18_0290(s32 a) asm("func_00167f18");
void func_002d49c0(u8* p, Src2d0* s, u32 v, u32 a, f32 f);
void func_002dd700(u8* p, Src2d0* s, u32 v, u32 a, f32 f);
void func_002d9730(u8* p, Src2d0* s, u32 v, u32 a, f32 f);
void func_002cff00(u8* p, Src2d0* s, s32 k, u32 a, f32 f);
void func_002db858(u8* p, Src2d0* s, u32 a, f32 f);
void func_002db4f0(u8* p, Src2d0* s, u32 a, f32 f);
void func_002d5d50(u8* p, Src2d0* s, u32 a, f32 f);
void func_002d69c8(u8* p, Src2d0* s, u32 a, f32 f);
void func_002d4200(u8* p, Src2d0* s, u32 a, f32 f);
void func_00177f50_0290(u8* p, Src2d0* s, s32 k, u32 v, u32 a, f32 f) asm("func_00177f50");
void func_002d29a8(u8* p, Src2d0* s, s32 k, u32 a, f32 f);
void func_002dda88(u8* p, Src2d0* s, u32 a, f32 f);
void func_002daca0(u8* p, Src2d0* s, u32 a, f32 f);
void func_002daa98(u8* p, Src2d0* s, u32 a, f32 f);
void func_002db6b0(u8* p, Src2d0* s, u32 a, f32 f);
void func_002de788(u8* p, Src2d0* s, Vec2d0* v, f32 f);

// Create the effect object for a source entry according to its type.
u8* func_002d0290(Src2d0* s, u32 a, f32 f) {
    u8* r = 0;
    u8* p;
    switch (s->type) {
    case 0:
        p = AllocR(3136);
        func_002d49c0(p, s, func_00167f18_0290(0), a, f);
        r = p;
        break;
    case 1:
        p = AllocR(3360);
        func_002d9730(p, s, func_00167f18_0290(0), a, f);
        r = p;
        break;
    case 2:
        p = AllocR(3088);
        func_002dd700(p, s, func_00167f18_0290(0), a, f);
        r = p;
        break;
    case 5:
    case 200:
        p = AllocR(2928);
        func_00177f50_0290(p, s, 11, func_00167f18_0290(0), a, f);
        r = p;
        break;
    case 6:
    case 100:
    case 201:
        p = AllocR(2848);
        func_002cff00(p, s, 1, a, f);
        r = p;
        break;
    case 15:
        if (s->id == 1565) {
            p = AllocR(2912);
            func_002d5d50(p, s, a, f);
        } else if (s->id == 1628) {
            p = AllocR(2848);
            func_002d69c8(p, s, a, f);
        } else if (s->id == 1566) {
            p = AllocR(3248);
            func_002d4200(p, s, a, f);
        } else {
            p = AllocR(2848);
            func_002cff00(p, s, 0, a, f);
        }
        *(s32*)(p + 944) = 1;
        r = p;
        break;
    case 16:
        if (s->id == 1630) {
            p = AllocR(3072);
            func_002db858(p, s, a, f);
        } else {
            p = AllocR(2848);
            func_002db4f0(p, s, a, f);
        }
        *(s32*)(p + 944) = 1;
        r = p;
        break;
    case 17:
        if (s->id == 1635) {
            p = AllocR(2848);
            Vec2d0 v;
            f32 z = 0.0f;
            v.x = z;
            v.y = -300.0f;
            v.z = z;
            v.w = z;
            func_002de788(p, s, &v, z);
        } else {
            p = AllocR(2848);
            func_002cff00(p, s, 1, a, f);
        }
        *(s32*)(p + 944) = 1;
        r = p;
        break;
    case 20:
        p = AllocR(3216);
        func_002d29a8(p, s, 3, a, f);
        r = p;
        break;
    case 21:
        if (s->id == 1631) {
            p = AllocR(2912);
            func_002daca0(p, s, a, f);
        } else {
            p = AllocR(2848);
            func_002daa98(p, s, a, f);
        }
        r = p;
        break;
    case 22:
        p = AllocR(3072);
        func_002dda88(p, s, a, f);
        r = p;
        break;
    case 26:
        p = AllocR(2848);
        func_002db6b0(p, s, a, f);
        r = p;
        break;
    }
    return r;
}

// ---- 00254ab8
struct ListVt254 { void* f[6]; void (*setItem)(void* self, s32 i, u32 a, s32 b, s32 c, s32 y, u32 col); };
struct List254 { ListVt254* vt; };
extern u8* D_0035f02c;
extern u8* D_0035f030_4ab8 asm("D_0035f030");
extern void* D_0035f010_4ab8 asm("D_0035f010");
extern u32 D_0035ef68;
extern u32 D_0035ef64;
extern u32 D_0035f03c;
extern u8 D_0035f056;
extern u8 D_0035ef60;
extern u32 D_00372974;
extern u32 D_00372970;
s32 func_00139d78_4ab8(u8* p) asm("func_00139d78");
void func_0028d8c0(u8* q, s32 id, u32 a, u32 b, u32 c, s32 d, s32 e, s32 f);
u8* func_00256b68_4ab8(s32 a) asm("func_00256b68");
List254* func_00287dc0_4ab8(void) asm("func_00287dc0");
void func_0023d808(List254* l, s32 id);
s32 func_00281100_4ab8(void* p) asm("func_00281100");
s32 func_00281128(void* p, s32 i);  // get_entry20_field16
s32 func_00281538(void* p, s32 i);
s32 func_0023ec18(List254* l, s32 i);
s32 func_002811e0(void* p, s32 i);
u32 func_00281238(void* p, s32 i);
s32 func_0027aa78(void);
void func_0023e858(List254* l, s32 i, f32 f);
void func_0023e8b8(List254* l, s32 i, f32 f);
void func_0023e8d8(List254* l, s32 i, f32 f);
s32 func_002811b0(void* p, s32 i);
void func_0023eae0(List254* l, s32 i, s32 a, s32 b);
void func_0023eac0(List254* l, s32 i, s32 k);  // store_byte_2912
void func_0023e958(List254* l, s32 i, s32 a, s32 b, s32 c, s32 d);
void func_0023e9c8(List254* l, s32 i, u8* p);
void func_0023e9e0(List254* l, s32 i, u8* p);

void func_00254ab8(void) {
    u8 any = 0;
    s32 y = 0;
    if (!func_00139d78_4ab8(D_0035f02c)) func_0028d8c0(D_0035f02c, 30003, D_0035ef68, D_0035ef64, D_0035f03c, 46, 47, 0);
    u8* o = func_00256b68_4ab8(0);
    if (!func_00139d78_4ab8(o)) func_0028d8c0(o, 30002, D_0035ef68, D_0035ef64, D_0035f03c, 116, -1, 0);
    List254* lst = func_00287dc0_4ab8();
    if (!func_00139d78_4ab8((u8*)lst)) func_0023d808(lst, 30008);
    s32 n = func_00281100_4ab8(D_0035f010_4ab8);
    if (n >= 4) n = 3;
    s32 step = (n * 98 - 98) / n;
    for (s32 i = 0; i < 4; i++) {
        if (i == 3) break;
        s32 k = 16;
        switch (i) {
        case 0:
            y = 47;
            k = 17;
            break;
        case 1:
            y = 145;
            break;
        case 2:
            y = 243;
            break;
        }
        if (!func_00281128(D_0035f010_4ab8, i)) continue;
        if (!func_00281538(D_0035f010_4ab8, i) || func_0023ec18(lst, i)) {
            if (!func_00281538(D_0035f010_4ab8, i)) any = 1;
            continue;
        }
        if (i != 0 && func_002811e0(D_0035f010_4ab8, i) == 3) k = 0;
        y -= step;
        u32 a = func_00281238(D_0035f010_4ab8, i);
        u32 col = func_0027aa78() ? D_00372974 : D_00372970;
        lst->vt->setItem(lst, i, a | 0x20000000, 139, 2, y, col);
        func_0023e858(lst, i, -100.0f);
        func_0023e8b8(lst, i, 0.0f);
        func_0023e8d8(lst, i, 0.0f);
        if (func_002811b0(D_0035f010_4ab8, i) == 8) func_0023eae0(lst, i, 20, 32);
        func_0023eac0(lst, i, k);  // store_byte_2912
        func_0023e958(lst, i, 96, 96, 96, -1);
        func_0023e9c8(lst, i, D_0035f02c);
        if (D_0035ef60) {
            if (!func_00139d78_4ab8(D_0035f030_4ab8)) func_0028d8c0(D_0035f030_4ab8, k, D_0035ef68, D_0035ef64, D_0035f03c, 125, -1, 0);
            func_0023e9e0(lst, i, D_0035f030_4ab8);
        }
    }
    if (!any && !D_0035f056) D_0035f056 = 1;
    D_0035ef60 = any;
}

// ---- 0025fb48
extern void* D_0035f01c_fb48 asm("D_0035f01c");
extern void* D_0035f010_fb48 asm("D_0035f010");
s32 func_00287cd0(void);
s32 func_00289380(void* s);
s32 func_00289310_fb48(void* s) asm("func_00289310");
s32 func_00287c10(void);
s32 func_00262160(void);
s32 func_00257970(void);
s32 func_00256ef0(void);
s32 func_0028f930(s32 a);
void func_00287f90(s32 a);
void func_00256ea8(void);
void func_00262118(void);
void func_0028f878(void);
void func_00287c30(void);
void func_0028af18_fb48(void* s, u32 a) asm("func_0028af18");
void func_0028f7e8(s32 a);
void func_002551b8(void);
void func_002678a8(void);
s32 func_002570a0(s32 a);
s32 func_00281100_fb48(void* p) asm("func_00281100");
void func_00277178(s32 a, s32 b);
void func_002634c8(s32 a);
void func_00257050_fb48(s32 a, s32 b, s32 c) asm("func_00257050");
void func_0025ffd0(void);
s32 func_0028ae28(void* s, s32 a);
void func_0028ab20(void* s);
void func_00256e30(void);
void func_0028fa98(s32 a);
void func_00287c90(s32 a);
s32 func_0028afa8_fb48(void* s) asm("func_0028afa8");
void func_002638e0(void);
s32 func_00287df0_fb48(s32 a, s32 b, s32 c, void (*d)(void), s32 e) asm("func_00287df0");
s32 func_00242848(s32 a);
s32 func_00257070(s32 a);
s32 func_002891e8_fb48(void* s) asm("func_002891e8");
void func_00287da0(void);
void func_00256e80(void);
void func_00263c60(void);  // sync_global_index_if_changed
void func_0028f6f0(s32 a);  // record884_refresh_by_index
void func_002620a0(void);
void func_00287c00(s32 m);
u8* func_002891b8_fb48(void* p, s32 n) asm("func_002891b8");
void func_0028fb68(s32 a, u32 b);
s32 func_00288040(void);
void func_00288018(void);  // global_zero_4dwords

void func_0025fb48(void) {
    s32 cur = func_00289380(D_0035f01c_fb48);
    s32 st = func_00287cd0();
    if (st == 2) {
        s32 busy = 0;
        s32 next = func_00287c10();
        if (func_00262160() || func_00257970()) busy = 1;
        if (next != 2) busy = busy || func_00256ef0();
        if (busy || ((next == 0 || next == 15) && func_0028f930(0))) {
            if (cur == -1 && !func_00289310_fb48(D_0035f01c_fb48)) return;
            func_00287f90(0);
            if (next != 2) func_00256ea8();
            func_00262118();
            if (next == 0 || next == 15) func_0028f878();
            return;
        }
        func_00287c30();
        func_0028af18_fb48(D_0035f01c_fb48, 115);
        if (next == 0) {
            func_0028f7e8(0);
            func_002551b8();
        } else if (next == 2) {
            func_002678a8();
        } else if (next == 15) {
            s32 c = func_002570a0(1);
            if (!(c < func_00281100_fb48(D_0035f010_fb48))) c = 0;
            func_00277178(15, c);
        } else {
            func_00256ea8();
            func_002634c8(0);
            func_00257050_fb48(10, 0, 0);
            func_0025ffd0();
        }
        return;
    }
    if (cur != -1 || func_00289310_fb48(D_0035f01c_fb48)) {
        if (!func_0028ae28(D_0035f01c_fb48, 0)) {
            func_0028ab20(D_0035f01c_fb48);
            func_00256e30();
            func_0028fa98(-1);
        }
    }
    if (st == 0 && func_0028ae28(D_0035f01c_fb48, 0)) func_00287c90(1);
    s32 max = func_0028afa8_fb48(D_0035f01c_fb48);
    if (!func_00242848(func_00287df0_fb48(cur, func_00289310_fb48(D_0035f01c_fb48), 1, func_002638e0, 1))) {
        s32 m;
        switch (cur) {
        case -4: {
            s32 c = func_00257070(1);
            if (func_002891e8_fb48(D_0035f01c_fb48) != c) func_00257050_fb48(2, 0, 0);
            func_00257050_fb48(1, func_002891e8_fb48(D_0035f01c_fb48), 0);
            func_00287da0();
            break;
        }
        case -5:
            func_00256e80();
            func_00263c60();  // sync_global_index_if_changed
            func_0028f6f0(0);  // record884_refresh_by_index
            func_002620a0();
            func_00287c90(1);
            func_00287c00(15);
            {
                s32 c = func_00257070(1);
                if (func_002891e8_fb48(D_0035f01c_fb48) != c) func_00257050_fb48(2, 0, 0);
                func_00257050_fb48(1, func_002891e8_fb48(D_0035f01c_fb48), 0);
            }
            break;
        case -2:
            func_00256e80();
            func_00263c60();  // sync_global_index_if_changed
            func_0028f6f0(0);  // record884_refresh_by_index
            func_002620a0();
            func_00287c90(1);
            func_00287c00(0);
            {
                s32 c = func_00257070(1);
                if (func_002891e8_fb48(D_0035f01c_fb48) != c) func_00257050_fb48(2, 0, 0);
                func_00257050_fb48(1, func_002891e8_fb48(D_0035f01c_fb48), 0);
            }
            break;
        case -1:
            break;
        default:
            if (cur >= 0 && cur < max) {
                if (cur == max - 1) {
                    func_00256e80();
                    m = 10;
                } else {
                    m = 2;
                }
                func_0028fb68(1, *(u32*)(func_002891b8_fb48(D_0035f01c_fb48, cur) + 408));
                func_00263c60();  // sync_global_index_if_changed
                func_002620a0();
                func_00287c90(1);
                func_00287c00(m);
                s32 c = func_00257070(1);
                if (func_002891e8_fb48(D_0035f01c_fb48) != c) func_00257050_fb48(2, 0, 0);
                func_00257050_fb48(1, func_002891e8_fb48(D_0035f01c_fb48), 0);
            }
            break;
        }
    }
    if (func_00288040()) func_00288018();
}

// ---- 002a0cb8
struct Pad2a0 { u64 trig; u64 rep; };
struct Ent2a0 { u16 a; u16 b; u16 c; u16 d; };
struct Win2a0 { u8 pad0; s8 idx; u8 pad1[70]; s16 x; s16 w; s16 y; s16 h; Ent2a0 ent[1]; };
extern u8 D_0035f5e1;
extern u8 D_0035f5e0;
// Read through a union: the original reloads it after every halfword store (no strict aliasing).
extern union { Win2a0* p; s16 h; } D_0035f5d4_0cb8 asm("D_0035f5d4");
extern union { u8* p; s16 h; } D_0035f5d8_0cb8 asm("D_0035f5d8");
Pad2a0* func_00167f18_0cb8(s32 a) asm("func_00167f18");
s32 func_00287cd0(void);
s32 func_00287bc0(void);
void func_002a1cd8(void);
void func_002a1bf8(void);
void func_002a1d38(void);
s32 func_00276368(void);
s32 func_00276888(void);
void func_00287f90(s32 a);
s32 func_00287c10(void);
void func_002a07f0(s32 m);
s32 func_00292630(void);
void func_002a1c68(void);
void func_00287c30(void);
s32 func_00276358(void);
void func_00276220(s32 a, s32 b);
void func_00274cf0(s32 a);  // state_dispatch_0_1_2
void func_002925c0(void);
void func_002958b0(void);
void func_002995e8(void);
void func_002aa048(u16 a);
void func_0029c880(Win2a0* w, s32 m);
void func_00138cb8(u8* p, s32* x, s32* y);
s16 func_0023aa18_0cb8(u8* p) asm("func_0023aa18");
s16 func_0023aa38_0cb8(u8* p) asm("func_0023aa38");
s32 func_00276398(void);  // state_is_150
void func_00275b60(void);
void func_00287c90(s32 a);
s32 func_00139d78_0cb8(u8* p) asm("func_00139d78");
void func_002a10e0(void);
void func_002a16b8(void);
void func_002a17e8(void);
void func_002a1220(void);
void func_002a13e0(Pad2a0* p);
s32 func_00242618_0cb8(s32 a, s32 b) asm("func_00242618");
void func_002a1398(void);
void func_00287da0(void);
void func_0028f6f0(s32 a);  // record884_refresh_by_index
void func_002a0780(void);
void func_00276dc0(void);
void func_00287c00(s32 m);
void func_00287cc0(s32 s);
s32 func_00242848(s32 a);
s32 func_00288040(void);
void func_00288018(void);  // global_zero_4dwords

void func_002a0cb8(void) {
    Pad2a0* pad = func_00167f18_0cb8(0);
    s32 st = func_00287cd0();
    s32 mode = func_00287bc0();
    if (st != 2) {
        if (!D_0035f5e1) func_002a1cd8();
        if (!D_0035f5e0) func_002a1bf8();
        if (D_0035f5e0) func_002a1d38();
    }
    if (st == 2) {
        if (func_00276368() || func_00276888()) {
            if (pad->rep & 0x1fc) {
                func_00287f90(0);
                func_002a07f0(func_00287c10());
            }
            return;
        }
        if (func_00292630()) return;
        func_002a1c68();
        func_002a07f0(func_00287c10());
        s32 prev = func_00287bc0();
        func_00287c30();
        mode = func_00287bc0();
        func_00276220(func_00276358(), 0);
        if (mode == 2) {
            func_00274cf0(2);  // state_dispatch_0_1_2
            func_002925c0();
            func_002958b0();
        } else if (mode == 13) {
            func_00274cf0(13);  // state_dispatch_0_1_2
            func_002925c0();
            func_002995e8();
        } else if (mode == 16) {
            func_002aa048(D_0035f5d4_0cb8.p->ent[D_0035f5d4_0cb8.p->idx].a);
            func_0029c880(D_0035f5d4_0cb8.p, prev);
        }
        return;
    }
    if (D_0035f5d4_0cb8.p->x == -999) {
        union { s32 v; s16 h; } x, y;
        func_00138cb8(D_0035f5d8_0cb8.p, &x.v, &y.v);
        D_0035f5d4_0cb8.p->x = x.v;
        D_0035f5d4_0cb8.p->y = y.v;
        D_0035f5d4_0cb8.p->w = func_0023aa18_0cb8(D_0035f5d8_0cb8.p + 24);
        D_0035f5d4_0cb8.p->h = func_0023aa38_0cb8(D_0035f5d8_0cb8.p + 24);
    }
    if (pad->rep & 0x1fc) {
        if (!func_00276398()) {  // state_is_150
            func_00276220(0, 2);
            func_00275b60();
        }
    }
    if (st == 0 && func_00276398()) {  // state_is_150
        func_00287c90(1);
    } else {
        if (!func_00139d78_0cb8(D_0035f5d8_0cb8.p + 816)) func_002a10e0();
        s8 idx = D_0035f5d4_0cb8.p->idx;
        func_002a16b8();
        func_002a17e8();
        if (idx < 0 && D_0035f5d4_0cb8.p->idx != 0) func_002a1220();
        if (pad->trig & 0xf0) {
            func_002a13e0(pad);
        } else if (pad->rep & 0x100) {
            func_00242618_0cb8(5, 1);
            func_002a1398();
            func_00287da0();
        } else if (pad->rep & 8) {
            func_00242618_0cb8(3, 1);
            func_0028f6f0(0);  // record884_refresh_by_index
            func_002a0780();
            func_00276dc0();
            func_002a1398();
            func_00276220(1, 1);
            func_00287c00(mode == 40 ? 13 : 2);
            func_00287cc0(2);
        } else if (pad->rep & 4) {
            if (func_00242848(func_00242618_0cb8(D_0035f5d4_0cb8.p->idx < 0 ? 4 : 2, 1))) return;
            func_002a1398();
            func_00276dc0();
            func_002a0780();
            func_00276220(0, 1);
            func_00287c00(16);
            func_00287cc0(2);
        }
    }
    if (func_00288040()) func_00288018();
}

// ---- 002f8e58
f32 func_002faa10(f32 x);
typedef union { f32 value; u32 word; } FloatShape2f8;
#define GET_FLOAT_WORD_2F8(i, d) do { FloatShape2f8 gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD_2F8(d, i) do { FloatShape2f8 sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
f32 acosf_2f8e58(f32 x) asm("_Z16wtarget_002f8e58jjjj");

// fdlibm/newlib __ieee754_acosf (sqrtf is func_002faa10).
static const f32 one = 1.0f, pi = 3.1415925f, pio2_hi = 1.57079625f, pio2_lo = 7.54978942e-08f,
    pS0 = 0.166666657f, pS1 = -0.325565785f, pS2 = 0.201212525f, pS3 = -0.0400555357f,
    pS4 = 0.000791535014f, pS5 = 3.47933092e-05f, qS1 = -2.4033947f, qS2 = 2.02094555f,
    qS3 = -0.68828392f, qS4 = 0.0770381466f;

f32 acosf_2f8e58(f32 x) {
    f32 z, p, q, r, w, s, c, df;
    s32 hx, ix;
    GET_FLOAT_WORD_2F8(hx, x);
    ix = hx & 0x7fffffff;
    if (ix == 0x3f800000) {
        if (hx > 0) return 0.0f;
        else return pi + 2.0f * pio2_lo;
    } else if (ix > 0x3f800000) {
        return (x - x) / (x - x);
    }
    if (ix < 0x3f000000) {
        if (ix <= 0x23000000) return pio2_hi + pio2_lo;
        z = x * x;
        p = z * (pS0 + z * (pS1 + z * (pS2 + z * (pS3 + z * (pS4 + z * pS5)))));
        q = one + z * (qS1 + z * (qS2 + z * (qS3 + z * qS4)));
        r = p / q;
        return pio2_hi - (x - (pio2_lo - x * r));
    } else if (hx < 0) {
        z = (one + x) * 0.5f;
        p = z * (pS0 + z * (pS1 + z * (pS2 + z * (pS3 + z * (pS4 + z * pS5)))));
        q = one + z * (qS1 + z * (qS2 + z * (qS3 + z * qS4)));
        s = func_002faa10(z);
        r = p / q;
        w = r * s - pio2_lo;
        return pi - 2.0f * (s + w);
    } else {
        s32 idf;
        z = (one - x) * 0.5f;
        s = func_002faa10(z);
        df = s;
        GET_FLOAT_WORD_2F8(idf, df);
        SET_FLOAT_WORD_2F8(df, idf & 0xfffff000);
        c = (z - df * df) / (s + df);
        p = z * (pS0 + z * (pS1 + z * (pS2 + z * (pS3 + z * (pS4 + z * pS5)))));
        q = one + z * (qS1 + z * (qS2 + z * (qS3 + z * qS4)));
        r = p / q;
        w = r * s + c;
        return 2.0f * (df + w);
    }
}

// ---- 0029ba88
extern void* D_0035f200;
extern s8 D_0035f5c4;
s32 func_00289380(void* s);
s32 func_00287cd0(void);
s32 func_00287bc0(void);
s32 func_00276368(void);
s32 func_0028acc8_ba88(void* s) asm("func_0028acc8");
s32 func_00276888(void);
void func_00287f90(s32 a);
s32 func_00287c10(void);
void func_0029aac0(s32 m);
s32 func_00292630(void);
s32 func_00293200(void);
void func_00276690(s32 a);
void func_002766b0(s32 a);
void func_00287c30(void);
void func_0028af18_ba88(void* s, u32 a) asm("func_0028af18");
s32 func_00276358(void);
void func_00276220(s32 a, s32 b);
void func_00274cf0(s32 a);  // state_dispatch_0_1_2
void func_002925c0(void);
void func_002995e8(void);
void func_0029af20(void);
void func_0029be08(void);
s32 func_00289310_ba88(void* s) asm("func_00289310");
s32 func_00276398(void);  // state_is_150
void func_00275b60(void);
void func_00287c90(s32 a);
void func_0029ecf0_x5029(void) asm("func_0029ecf0");
s32 func_00287df0_ba88(s32 a, s32 b, s32 c, void (*d)(void), s32 e) asm("func_00287df0");
s32 func_00242848(s32 a);
void func_0028f6f0(s32 a);  // record884_refresh_by_index
void func_0029aa30(void);
void func_00276dc0(void);
s32 func_002891e8_ba88(void* s) asm("func_002891e8");
s32 func_0028b038(void* s);
void func_002765e8(s32 a, s32 b, s32 c);
void func_00287c00(s32 m);
void func_00287cc0(s32 s);
void func_00287da0(void);
s32 func_00288040(void);
void func_00288018(void);  // global_zero_4dwords

void func_0029ba88(void) {
    s32 cur = func_00289380(D_0035f200);
    s32 st = func_00287cd0();
    s32 mode = func_00287bc0();
    if (st == 2) {
        if (func_00276368() || func_0028acc8_ba88(D_0035f200) || func_00276888()) {
            if (cur == -1) return;
            func_00287f90(0);
            func_0029aac0(func_00287c10());
            return;
        }
        if (func_00292630()) return;
        if (func_00293200()) return;
        func_00276690(0);
        func_002766b0(1);
        func_0029aac0(func_00287c10());
        func_00287c30();
        mode = func_00287bc0();
        func_0028af18_ba88(D_0035f200, 115);
        func_00276220(func_00276358(), 0);
        if (mode == 13) {
            func_00274cf0(13);  // state_dispatch_0_1_2
            func_002925c0();
            func_002766b0(0);
            func_002995e8();
        } else if (mode == 14) {
            func_0029af20();
        } else if (mode == 16 || mode == 19 || mode == 22) {
            D_0035f5c4 = -1;
            func_0029be08();
        }
        return;
    }
    if (cur != -1 || func_00289310_ba88(D_0035f200)) {
        if (!func_00276398()) {  // state_is_150
            func_00276220(0, 2);
            func_00275b60();
        }
    }
    if (st == 0 && func_00276398()) func_00287c90(1);  // state_is_150
    if (!func_00242848(func_00287df0_ba88(cur, func_00289310_ba88(D_0035f200), 1, func_0029ecf0_x5029, 1))) {
        s32 next;
        switch (cur) {
        case -2:
            if (mode == 15) {
                func_0028f6f0(1);  // record884_refresh_by_index
                next = 14;
            } else {
                func_0028f6f0(0);  // record884_refresh_by_index
                next = 13;
            }
            func_0029aa30();
            func_00276dc0();
            func_00276220(1, 1);
            func_00287c00(next);
            func_00287cc0(2);
            break;
        case -4:
            func_00287da0();
            break;
        case -1:
            break;
        default: {
            if (mode == 15) next = 16;
            else next = mode == 18 ? 19 : 22;
            func_0029aa30();
            func_00276dc0();
            s32 a = func_002891e8_ba88(D_0035f200);
            func_002765e8(15, a, func_0028b038(D_0035f200));
            func_00276220(0, 1);
            func_00287c00(next);
            func_00287cc0(2);
            break;
        }
        }
    }
    if (func_00288040()) func_00288018();
}

// ---- 002af748
struct Win2af { u8 pad[486]; u16 flags; };
extern void* D_0035f200;
Win2af* func_002a9d68(void);
s32 func_00289380(void* s);
s32 func_00287cd0(void);
s32 func_00287bc0(void);
s32 func_00287c10(void);
s32 func_00276368(void);
s32 func_0028acc8_f748(void* s) asm("func_0028acc8");
s32 func_00276888(void);
void func_00287f90(s32 a);
void func_002aecf0(s32 a);
void func_00287c30(void);
void func_0028af18_f748(void* s, u32 a) asm("func_0028af18");
s32 func_00276358(void);
void func_00276220(s32 a, s32 b);
void func_002aed60(void);
void func_002afaf0(void);
void func_002b01d8(void);
s32 func_00289310_f748(void* s) asm("func_00289310");
s32 func_00276398(void);  // state_is_150
void func_00275b60(void);
void func_00287c90(s32 a);
void func_002b3b78_x5147(void) asm("func_002b3b78");
s32 func_00287df0_f748(s32 a, s32 b, s32 c, void (*d)(void), s32 e) asm("func_00287df0");
s32 func_00242848(s32 a);
void func_0028f6f0(s32 a);  // record884_refresh_by_index
void func_002aece8(void);
void func_00276dc0(void);
void func_00287c00(s32 m);
void func_00287cc0(s32 s);
s32 func_002891e8_f748(void* s) asm("func_002891e8");
s32 func_0028b038(void* s);
void func_002765e8(s32 a, s32 b, s32 c);
void func_00287da0(void);
s32 func_002b2338(s32 a);
void func_002b2428(s32 a);
s32 func_00288040(void);
void func_00288018(void);  // global_zero_4dwords

void func_002af748(void) {
    Win2af* w = func_002a9d68();
    s32 cur = func_00289380(D_0035f200);
    s32 st = func_00287cd0();
    func_00287bc0();
    if (st == 2) {
        s32 next = func_00287c10();
        if (func_00276368() || func_0028acc8_f748(D_0035f200) || func_00276888()) {
            if (cur == -1) return;
            func_00287f90(0);
            func_002aecf0(next != 29);
            return;
        }
        func_002aecf0(next != 29);
        func_00287c30();
        s32 mode = func_00287bc0();
        func_0028af18_f748(D_0035f200, 115);
        func_00276220(func_00276358(), 0);
        switch (mode) {
        case 27: func_002aed60(); break;
        case 29: func_002afaf0(); break;
        case 30: func_002b01d8(); break;
        }
        return;
    }
    if (cur != -1 || func_00289310_f748(D_0035f200)) {
        if (!func_00276398()) {  // state_is_150
            func_00276220(0, 2);
            func_00275b60();
        }
    }
    if (st == 0 && func_00276398()) func_00287c90(1);  // state_is_150
    if (!func_00242848(func_00287df0_f748(cur, func_00289310_f748(D_0035f200), 1, func_002b3b78_x5147, 1))) {
        switch (cur) {
        case -2: {
            func_0028f6f0(1);  // record884_refresh_by_index
            func_002aece8();
            func_00276dc0();
            func_00276220(1, 1);
            func_00287c00(27);
            func_00287cc0(2);
            s32 m = func_00287bc0();
            s32 a = func_002891e8_f748(D_0035f200);
            func_002765e8(m, a, func_0028b038(D_0035f200));
            break;
        }
        case -4: {
            s32 m = func_00287bc0();
            s32 a = func_002891e8_f748(D_0035f200);
            func_002765e8(m, a, func_0028b038(D_0035f200));
            func_00287da0();
            break;
        }
        case -1:
            break;
        default: {
            func_002aece8();
            func_00276dc0();
            func_00276220(0, 1);
            func_00287cc0(2);
            s32 m = func_00287bc0();
            s32 a = func_002891e8_f748(D_0035f200);
            func_002765e8(m, a, func_0028b038(D_0035f200));
            if (w->flags & 1) {
                func_00287c00(29);
                func_002b2428(func_002b2338(func_002891e8_f748(D_0035f200)));
            } else {
                func_00287c00(30);
            }
            break;
        }
        }
    }
    if (func_00288040()) func_00288018();
}

// ---- 001c3150
struct Stat1c3 {
    u32 abil[11];
    u8 c44, c45, c46, c47, c48;
    u8 pad49[3];
    f32 f52, f56, f60, f64;
    u16 h68, h70, h72, h74, h76, h78, h80, h82;
    f32 f84, f88, f92, f96, f100, f104, f108, f112, f116;
};
struct Prm1c3 {
    u8 pad[284];
    u16 h284; u16 pad286;
    f32 f288, f292, f296, f300;
    u16 h304; u16 pad306;
    u16 h308; u16 pad310;
    f32 f312, f316, f320;
    u8 pad324[4];
    u8 b328; u8 pad329[3];
    u16 h332; u16 pad334;
    f32 f336, f340, f344, f348, f352;
    u16 h356; u16 pad358;
    u8 pad360[4];
    f32 f364, f368, f372;
};
struct Item1c3 { u8 pad[4]; u16 abil; };
extern Prm1c3* D_00352130_3150 asm("D_00352130");
Item1c3* func_001a80c8_3150(s32 id) asm("func_001a80c8");

// Apply one equipped ability/item id to the character's stat block, then mark the ability as held.
void func_001c3150(Stat1c3* s, s32 id) {
    switch (id) {
    case 0:
        return;
    case 162: s->c44++; break;
    case 163: s->c45++; break;
    case 393: s->c46++; break;
    case 401: s->c47++; break;
    case 390: s->h74 += D_00352130_3150->h304; break;
    case 391: s->h76 += D_00352130_3150->h304; break;
    case 392: s->h78 += D_00352130_3150->h308; break;
    case 394:
        s->c44--;
        s->c45--;
        break;
    case 395: s->h82 += D_00352130_3150->h284; break;
    case 396: s->f84 += D_00352130_3150->f312; break;
    case 397: s->f60 += D_00352130_3150->f316; break;
    case 398: s->f64 *= D_00352130_3150->f320; break;
    case 399: s->f108 *= D_00352130_3150->f364; break;
    case 400: s->f96 *= D_00352130_3150->f344; break;
    case 405: s->f52 += D_00352130_3150->f300; break;
    case 406: s->f100 += D_00352130_3150->f348; break;
    case 407: s->f104 += D_00352130_3150->f352; break;
    case 408: s->h68 += D_00352130_3150->h332; break;
    case 409: s->h70 += D_00352130_3150->h332; break;
    case 410: s->h72 += D_00352130_3150->h332; break;
    case 411: s->h80 += D_00352130_3150->h356; break;
    case 412: s->f88 += D_00352130_3150->f336; break;
    case 413: s->f56 += D_00352130_3150->f288; break;
    case 414: s->c48 += D_00352130_3150->b328; break;
    case 419: s->f92 *= D_00352130_3150->f340; break;
    case 421: s->f56 += D_00352130_3150->f292; break;
    case 422: s->f56 += D_00352130_3150->f296; break;
    case 540: s->f112 *= D_00352130_3150->f368; break;
    case 542: s->f116 += D_00352130_3150->f372; break;
    }
    u32 a = func_001a80c8_3150(id)->abil;
    u32* p = s->abil;
    p += a >> 5;
    *p |= 1 << (a & 31);
}

// ---- 002859f0
struct Save285 { u32 seen[51]; u32 fresh[64]; };
// Reloaded after every u32 store in the original (no strict aliasing).
extern union { Save285* p; u32 u; } D_0035f2e4;
u32* func_002859a0(void);
void* func_001a8bd0_59f0(s32 a) asm("func_001a8bd0");
u32 func_001a8c10(void* p, s32 i);
u8* func_001a1658(u32 m, s32 a);  // state_dispatch_0_1_14
void func_001a17c8(u8* c);
u32 func_00281420(void);
u32 func_002814b0(s32 i);
u16* func_001a8110(u16* it);
s32 func_00285d18(u8 a);
s32 func_001a3570_59f0(u16 id) asm("func_001a3570");
void ucall_2859f0(void) asm("_Z16u_call0_002859f0v");

static inline void MarkFresh(u32* have, u32 id) {
    if (id && !(have[id >> 5] & (1 << (id & 31)))) {
        u32* f = D_0035f2e4.p->fresh;
        f += id >> 5;
        *f |= 1 << (id & 31);
    }
}

static inline void MarkSeen(u32* have, u32 id) {
    if (!(have[id >> 5] & (1 << (id & 31)))) {
        u32* f = D_0035f2e4.p->seen;
        f += id >> 5;
        *f |= 1 << (id & 31);
    }
}

// Flag equipment/items the player now holds that were not owned before.
void ucall_2859f0(void) {
    s32 i;
    u16* it = 0;
    u32* have = func_002859a0();
    void* party = func_001a8bd0_59f0(-1);
    for (i = 0; i < 4; i++) {
        u32 m = func_001a8c10(party, i);
        if (!m) continue;
        u8* c = func_001a1658(m, -1);  // state_dispatch_0_1_14
        u16* eq = *(u16**)(c + 580);
        s32 k;
        for (k = 0; k < 2; k++) MarkFresh(have, eq[k]);
        for (k = 0; k < 8; k++) MarkFresh(have, eq[10 + k]);
        for (k = 0; k < 8; k++) MarkFresh(have, eq[18 + k]);
        for (k = 0; k < 8; k++) MarkFresh(have, eq[26 + k]);
        func_001a17c8(c);
    }
    s32 mask = func_00281420();
    for (i = 0; i < 7; i++) {
        if ((mask >> i) & 1) MarkFresh(have, func_002814b0(i));
    }
    for (;;) {
        it = func_001a8110(it);
        if (!it) break;
        if (!func_00285d18(((u8*)it)[2])) continue;
        if (!func_001a3570_59f0(it[0])) continue;
        MarkSeen(have, it[0]);
    }
}

// ---- 002b47a0
struct VObj2b4 { void (**vt)(VObj2b4*); };
struct Heap2b4 { void (**vt)(Heap2b4*, void*); };
extern s32 D_0035f648, D_0035f640, D_0035f644;
extern u32 D_0035f6cc;
extern void* D_0035f64c;
extern void* D_0035f650;
extern VObj2b4* D_0035f654;
extern VObj2b4* D_0035f658;
extern void* D_0035f65c;
extern void* D_0035f660;
extern u32 D_0035f680[4];
extern u32 D_0035f690[3][4];
extern VObj2b4* D_0035f664;
extern VObj2b4* D_0035f668;
extern void* D_0035f66c;
extern void* D_0035f670;
extern VObj2b4* D_0035f674;
extern void* D_0035f678;
extern VObj2b4* D_0035f67c;
extern VObj2b4* D_0035f6c0;
extern void* D_0035f6c4;
extern void* D_0035f6c8;
extern Heap2b4* D_0032ba14_47a0 asm("D_0032ba14");
void SelectDtor2b4(void* p) asm("_ZN2Tz6SelectD1Ev");
void func_00288c20(void* p);
void DeleteArr2b4(void* p) asm("_ZdaPv");
void func_0028fdd0(void* p);
void func_00290300(void* p);
void func_0028ba80(void* p);
void func_00258ce8(s32 a);
void func_0028f3e8(void);
void func_002639f8(void);
void func_0023fdc0(void);
void func_00233e58(void);
void func_0014a4c0(void);

void ttarget_2b47a0(void) asm("_Z17ttarget0_002b47a0v");

// Tear down everything the memory-card menu created.
void ttarget_2b47a0(void) {
    D_0035f640 = -1;
    D_0035f644 = -1;
    D_0035f648 = -1;
    D_0035f6cc = 0;
    if (D_0035f64c) {
        void* p = D_0035f64c;
        SelectDtor2b4(p);
        func_00288c20(p);
        D_0035f64c = 0;
    }
    if (D_0035f650) {
        void* p = D_0035f650;
        SelectDtor2b4(p);
        func_00288c20(p);
        D_0035f650 = 0;
    }
    if (D_0035f654) {
        D_0035f654->vt[4](D_0035f654);
        D_0035f654 = 0;
    }
    if (D_0035f658) {
        D_0035f658->vt[4](D_0035f658);
        D_0035f658 = 0;
    }
    if (D_0035f65c) {
        DeleteArr2b4(D_0035f65c);
        D_0035f65c = 0;
    }
    if (D_0035f660) {
        DeleteArr2b4(D_0035f660);
        D_0035f660 = 0;
    }
    s32 i, j;
    for (j = 0; j < 4; j++) D_0035f680[j] = 0;
    for (j = 0; j < 3; j++)
        for (i = 0; i < 4; i++) D_0035f690[j][i] = 0;
    if (D_0035f664) {
        D_0035f664->vt[4](D_0035f664);
        D_0035f664 = 0;
    }
    if (D_0035f668) {
        D_0035f668->vt[4](D_0035f668);
        D_0035f668 = 0;
    }
    if (D_0035f66c) {
        void* p = D_0035f66c;
        func_0028fdd0(p);
        D_0032ba14_47a0->vt[1](D_0032ba14_47a0, p);
        D_0035f66c = 0;
    }
    if (D_0035f670) {
        void* p = D_0035f670;
        func_00290300(p);
        D_0032ba14_47a0->vt[1](D_0032ba14_47a0, p);
        D_0035f670 = 0;
    }
    if (D_0035f674) {
        D_0035f674->vt[1](D_0035f674);
        D_0035f674 = 0;
    }
    if (D_0035f678) {
        void* p = D_0035f678;
        func_0028ba80(p);
        D_0032ba14_47a0->vt[1](D_0032ba14_47a0, p);
        D_0035f678 = 0;
    }
    if (D_0035f67c) {
        D_0035f67c->vt[4](D_0035f67c);
        D_0035f67c = 0;
    }
    if (D_0035f6c0) {
        D_0035f6c0->vt[4](D_0035f6c0);
        D_0035f6c0 = 0;
    }
    if (D_0035f6c4) {
        DeleteArr2b4(D_0035f6c4);
        D_0035f6c4 = 0;
    }
    if (D_0035f6c8) {
        DeleteArr2b4(D_0035f6c8);
        D_0035f6c8 = 0;
    }
    func_00258ce8(0);
    func_0028f3e8();
    func_002639f8();
    func_0023fdc0();
    func_00233e58();
    func_0014a4c0();
}

// ---- 002fe0c0
typedef int qs_cmp_t(const void*, const void*);
#define min(a, b) (a) < (b) ? a : b
#define swapcode(TYPE, parmi, parmj, n) { \
    long i = (n) / sizeof (TYPE); \
    register TYPE *pi = (TYPE *) (parmi); \
    register TYPE *pj = (TYPE *) (parmj); \
    do { \
        register TYPE t = *pi; \
        *pi++ = *pj; \
        *pj++ = t; \
    } while (--i > 0); \
}
#define SWAPINIT(a, es) swaptype = ((char *)a - (char *)0) % sizeof(long) || \
    es % sizeof(long) ? 2 : es == sizeof(long)? 0 : 1;
static inline __attribute__((always_inline)) void qs_swapfunc(char *a, char *b, int n, int swaptype)
{
    if (swaptype <= 1)
        swapcode(long, a, b, n)
    else
        swapcode(char, a, b, n)
}
#define swap(a, b) \
    if (swaptype == 0) { \
        long t = *(long *)(a); \
        *(long *)(a) = *(long *)(b); \
        *(long *)(b) = t; \
    } else \
        qs_swapfunc(a, b, es, swaptype)
#define vecswap(a, b, n) if ((n) > 0) qs_swapfunc(a, b, n, swaptype)
static inline __attribute__((always_inline)) char *qs_med3(char *a, char *b, char *c, qs_cmp_t *cmp)
{
    return cmp(a, b) < 0 ?
           (cmp(b, c) < 0 ? b : (cmp(a, c) < 0 ? c : a ))
          :(cmp(b, c) > 0 ? b : (cmp(a, c) < 0 ? a : c ));
}
// newlib qsort (med3/swapfunc inlined)
void qsort_2fe0c0(void *a, unsigned int n, unsigned int es, qs_cmp_t *cmp) asm("func_002fe0c0");
void qsort_2fe0c0(void *a, unsigned int n, unsigned int es, qs_cmp_t *cmp)
{
    char *pa, *pb, *pc, *pd, *pl, *pm, *pn;
    int d, r, swaptype, swap_cnt;

loop:   SWAPINIT(a, es);
    swap_cnt = 0;
    if (n < 7) {
        for (pm = (char *) a + es; pm < (char *) a + n * es; pm += es)
            for (pl = pm; pl > (char *) a && cmp(pl - es, pl) > 0;
                 pl -= es)
                swap(pl, pl - es);
        return;
    }
    pm = (char *) a + (n / 2) * es;
    if (n > 7) {
        pl = (char *) a;
        pn = (char *) a + (n - 1) * es;
        if (n > 40) {
            d = (n / 8) * es;
            pl = qs_med3(pl, pl + d, pl + 2 * d, cmp);
            pm = qs_med3(pm - d, pm, pm + d, cmp);
            pn = qs_med3(pn - 2 * d, pn - d, pn, cmp);
        }
        pm = qs_med3(pl, pm, pn, cmp);
    }
    swap((char *)a, pm);
    pa = pb = (char *) a + es;

    pc = pd = (char *) a + (n - 1) * es;
    for (;;) {
        while (pb <= pc && (r = cmp(pb, a)) <= 0) {
            if (r == 0) {
                swap_cnt = 1;
                swap(pa, pb);
                pa += es;
            }
            pb += es;
        }
        while (pb <= pc && (r = cmp(pc, a)) >= 0) {
            if (r == 0) {
                swap_cnt = 1;
                swap(pc, pd);
                pd -= es;
            }
            pc -= es;
        }
        if (pb > pc)
            break;
        swap(pb, pc);
        swap_cnt = 1;
        pb += es;
        pc -= es;
    }
    if (swap_cnt == 0) {  /* Switch to insertion sort */
        for (pm = (char *) a + es; pm < (char *) a + n * es; pm += es)
            for (pl = pm; pl > (char *) a && cmp(pl - es, pl) > 0;
                 pl -= es)
                swap(pl, pl - es);
        return;
    }

    pn = (char *) a + n * es;
    r = min(pa - (char *)a, pb - pa);
    vecswap((char *)a, pb - r, r);
    r = min(pd - pc, pn - pd - es);
    vecswap(pb, pn - r, r);
    if ((r = pb - pa) > es)
        qsort_2fe0c0(a, r / es, es, cmp);
    if ((r = pd - pc) > es) {
        a = pn - r;
        n = r / es;
        goto loop;
    }
}
#undef min
#undef swapcode
#undef SWAPINIT
#undef swap
#undef vecswap

// ---- 003191f8
extern u8 D_01e4c7b8;
extern u8 D_01e4c7b9;
extern u8 D_01e4c7ba;
extern u8 D_01e4c7bb;
extern u8 D_01e4c7bc;
extern u8 D_01e4c7bd;
extern u8 D_01e4c7be;
extern u8 D_01e4c7bf;
extern u8 D_01e4c7c0;
extern u8 D_01e4c7c1;
extern u8 D_01e4c7c2;
extern u8 D_01e4c7c3;
extern u8 D_01e4c7c4;
extern u8 D_01e4c7c5;
extern u8 D_01e4c7c6;
extern u8 D_01e4c7c7;
extern u8 D_01e4c7c8;
extern u8 D_01e4c7c9;
extern u8 D_01e4c7ca;
extern u8 D_01e4c7cb;
extern u8 D_01e4c7cc;
extern u8 D_01e4c7cd;
extern u8 D_01e4c7ce;
extern u8 D_01e4c7cf;
extern u8 D_01e4c7d0;
extern u8 D_01e4c7d1;
extern u8 D_01e4c7d2;
extern u8 D_01e4c7d3;
extern u8 D_01e4c7d4;
extern u8 D_01e4c7d5;
extern u8 D_01e4c7d6;
extern u8 D_01e4c7d7;
extern u8 D_01e4c7d8;
extern u8 D_01e4c7d9;
extern u8 D_01e4c7da;
extern u8 D_01e4c7db;
extern u8 D_01e4c7dc;
extern u8 D_01e4c7dd;
extern u8 D_01e4c7de;
extern u8 D_01e4c7df;
extern u8 D_01e4c7e0;
extern u8 D_01e4c7e1;
extern u8 D_01e4c7e2;
extern u8 D_01e4c7e3;
extern u8 D_01e4c7e4;
extern u8 D_01e4c7e5;
extern u8 D_01e4c7e6;
extern u8 D_01e4c7e7;
extern u8 D_01e4c7e8;
extern u8 D_01e4c7e9;
extern u8 D_01e4c7ea;
extern u8 D_01e4c7eb;
extern u8 D_01e4c7ec;
extern u8 D_01e4c7ed;
extern u8 D_01e4c7ee;
extern u8 D_01e4c7ef;
extern u8 D_01e4c7f0;
extern u8 D_01e4c7f1;
extern u8 D_01e4c7f2;
extern u8 D_01e4c7f3;
extern u8 D_01e4c7f4;
extern u8 D_01e4c7f5;
extern u8 D_01e4c7f6;
extern u8 D_01e4c7f7;
extern u8 D_01e4c7f8;
extern u8 D_01e4c7f9;
extern u8 D_01e4c7fa;
extern u8 D_01e4c7fb;
extern u8 D_01e4c7fc;
extern u8 D_01e4c7fd;
extern u8 D_01e4c7fe;
extern u8 D_01e4c7ff;
extern u8 D_01e4c800;
extern u8 D_01e4c801;
extern u8 D_01e4c802;
extern u8 D_01e4c803;
extern u8 D_01e4c804;
extern u8 D_01e4c805;
extern u8 D_01e4c806;
extern u8 D_01e4c807;
extern u8 D_01e4c808;
extern u8 D_01e4c809;
extern u8 D_01e4c80a;
extern u8 D_01e4c80b;
extern u8 D_01e4c80c;
extern u8 D_01e4c80d;
extern u8 D_01e4c80e;
extern u8 D_01e4c80f;
extern u8 D_01e4c810;
extern u8 D_01e4c811;
extern u8 D_01e4c812;
extern u8 D_01e4c813;
extern u8 D_01e4c814;
extern u8 D_01e4c815;
extern u8 D_01e4c816;
extern u8 D_01e4c817;
extern u8 D_01e4c818;
extern u8 D_01e4c819;
extern u8 D_01e4c81a;
extern u8 D_01e4c81b;
extern u8 D_01e4c81c;
extern u8 D_01e4c81d;
extern u8 D_01e4c81e;
extern u8 D_01e4c81f;
extern u8 D_01e4c820;
extern u8 D_01e4c821;
extern u8 D_01e4c822;
extern u8 D_01e4c823;
extern u8 D_01e4c824;
extern u8 D_01e4c825;
extern u8 D_01e4c826;
extern u8 D_01e4c827;
extern u8 D_01e4c828;
extern u8 D_01e4c829;
extern u8 D_01e4c82a;
extern u8 D_01e4c82b;
extern u8 D_01e4c82c;
extern u8 D_01e4c82d;
extern u8 D_01e4c82e;
extern u8 D_01e4c82f;
extern u8 D_01e4c830;
extern u8 D_01e4c831;
extern u8 D_01e4c832;
extern u8 D_01e4c833;
extern u8 D_01e4c834;
extern u8 D_01e4c835;
extern u8 D_01e4c836;
extern u8 D_01e4c837;
extern u8 D_01e4c838;
extern u8 D_01e4c839;
extern u8 D_01e4c83a;
extern u8 D_01e4c83b;
extern u8 D_01e4c83c;
extern u8 D_01e4c83d;
extern u8 D_01e4c83e;
extern u8 D_01e4c83f;
extern u8 D_01e4c840;
extern u8 D_01e4c841;
extern u8 D_01e4c842;
extern u8 D_01e4c843;
extern u8 D_01e4c844;
extern u8 D_01e4c845;
extern u8 D_01e4c846;
extern u8 D_01e4c847;
extern u8 D_01e4c848;
extern u8 D_01e4c849;
extern u8 D_01e4c84a;
extern u8 D_01e4c84b;
extern u8 D_01e4c84c;
extern u8 D_01e4c84d;
extern u8 D_01e4c84e;
extern u8 D_01e4c84f;
extern u8 D_01e4c850;
extern u8 D_01e4c851;
extern u8 D_01e4c852;
extern u8 D_01e4c853;
extern u8 D_01e4c854;
extern u8 D_01e4c855;
extern u8 D_01e4c856;
extern u8 D_01e4c857;
extern u8 D_01e4c858;
extern u8 D_01e4c859;
extern u8 D_01e4c85a;
extern u8 D_01e4c85b;
extern u8 D_01e4c85c;
extern u8 D_01e4c85d;
extern u8 D_01e4c85e;
extern u8 D_01e4c85f;
extern u8 D_01e4c860;
extern u8 D_01e4c861;
extern u8 D_01e4c862;
extern u8 D_01e4c863;
extern u8 D_01e4c864;
extern u8 D_01e4c865;
extern u8 D_01e4c866;
extern u8 D_01e4c867;
void func_003191f8(void) {
    D_01e4c7b8 = 8;
    D_01e4c7b9 = 8;
    D_01e4c7ba = 8;
    D_01e4c7bb = 8;
    D_01e4c7bc = 8;
    D_01e4c7bd = 8;
    D_01e4c7be = 8;
    D_01e4c7bf = 8;
    D_01e4c7c0 = 8;
    D_01e4c7c1 = 8;
    D_01e4c7c2 = 8;
    D_01e4c7c3 = 8;
    D_01e4c7c4 = 8;
    D_01e4c7c5 = 8;
    D_01e4c7c6 = 8;
    D_01e4c7c7 = 8;
    D_01e4c7c8 = 8;
    D_01e4c7c9 = 8;
    D_01e4c7ca = 8;
    D_01e4c7cb = 8;
    D_01e4c7cc = 8;
    D_01e4c7cd = 8;
    D_01e4c7ce = 8;
    D_01e4c7cf = 8;
    D_01e4c7d0 = 8;
    D_01e4c7d1 = 8;
    D_01e4c7d2 = 8;
    D_01e4c7d3 = 8;
    D_01e4c7d4 = 8;
    D_01e4c7d5 = 8;
    D_01e4c7d6 = 8;
    D_01e4c7d7 = 8;
    D_01e4c7d8 = 4;
    D_01e4c7d9 = 4;
    D_01e4c7da = 4;
    D_01e4c7db = 4;
    D_01e4c7dc = 4;
    D_01e4c7dd = 4;
    D_01e4c7de = 4;
    D_01e4c7df = 4;
    D_01e4c7e0 = 4;
    D_01e4c7e1 = 4;
    D_01e4c7e2 = 4;
    D_01e4c7e3 = 4;
    D_01e4c7e4 = 4;
    D_01e4c7e5 = 4;
    D_01e4c7e6 = 4;
    D_01e4c7e7 = 4;
    D_01e4c7e8 = 4;
    D_01e4c7e9 = 4;
    D_01e4c7ea = 4;
    D_01e4c7eb = 4;
    D_01e4c7ec = 4;
    D_01e4c7ed = 4;
    D_01e4c7ee = 4;
    D_01e4c7ef = 4;
    D_01e4c7f0 = 4;
    D_01e4c7f1 = 4;
    D_01e4c7f2 = 4;
    D_01e4c7f3 = 4;
    D_01e4c7f4 = 4;
    D_01e4c7f5 = 4;
    D_01e4c7f6 = 4;
    D_01e4c7f7 = 4;
    D_01e4c7f8 = 4;
    D_01e4c7f9 = 4;
    D_01e4c7fa = 4;
    D_01e4c7fb = 4;
    D_01e4c7fc = 4;
    D_01e4c7fd = 4;
    D_01e4c7fe = 4;
    D_01e4c7ff = 4;
    D_01e4c800 = 4;
    D_01e4c801 = 4;
    D_01e4c802 = 4;
    D_01e4c803 = 4;
    D_01e4c804 = 16;
    D_01e4c805 = 4;
    D_01e4c806 = 4;
    D_01e4c807 = 4;
    D_01e4c808 = 4;
    D_01e4c809 = 4;
    D_01e4c80a = 4;
    D_01e4c80b = 4;
    D_01e4c80c = 4;
    D_01e4c80d = 4;
    D_01e4c80e = 4;
    D_01e4c80f = 4;
    D_01e4c810 = 4;
    D_01e4c811 = 4;
    D_01e4c812 = 4;
    D_01e4c813 = 4;
    D_01e4c814 = 4;
    D_01e4c815 = 4;
    D_01e4c816 = 4;
    D_01e4c817 = 4;
    D_01e4c818 = 4;
    D_01e4c819 = 4;
    D_01e4c81a = 4;
    D_01e4c81b = 4;
    D_01e4c81c = 4;
    D_01e4c81d = 4;
    D_01e4c81e = 4;
    D_01e4c81f = 4;
    D_01e4c820 = 4;
    D_01e4c821 = 4;
    D_01e4c822 = 4;
    D_01e4c823 = 4;
    D_01e4c824 = 4;
    D_01e4c825 = 4;
    D_01e4c826 = 4;
    D_01e4c827 = 4;
    D_01e4c828 = 16;
    D_01e4c829 = 16;
    D_01e4c82a = 16;
    D_01e4c82b = 16;
    D_01e4c82c = 16;
    D_01e4c82d = 16;
    D_01e4c82e = 16;
    D_01e4c82f = 16;
    D_01e4c830 = 16;
    D_01e4c831 = 16;
    D_01e4c832 = 16;
    D_01e4c833 = 16;
    D_01e4c834 = 16;
    D_01e4c835 = 16;
    D_01e4c836 = 16;
    D_01e4c837 = 16;
    D_01e4c838 = 16;
    D_01e4c839 = 16;
    D_01e4c83a = 16;
    D_01e4c83b = 16;
    D_01e4c83c = 16;
    D_01e4c83d = 16;
    D_01e4c83e = 16;
    D_01e4c83f = 16;
    D_01e4c840 = 16;
    D_01e4c841 = 16;
    D_01e4c842 = 16;
    D_01e4c843 = 16;
    D_01e4c844 = 16;
    D_01e4c845 = 16;
    D_01e4c846 = 16;
    D_01e4c847 = 16;
    D_01e4c848 = 8;
    D_01e4c849 = 8;
    D_01e4c84a = 8;
    D_01e4c84b = 8;
    D_01e4c84c = 8;
    D_01e4c84d = 8;
    D_01e4c84e = 8;
    D_01e4c84f = 8;
    D_01e4c850 = 8;
    D_01e4c851 = 8;
    D_01e4c852 = 8;
    D_01e4c853 = 8;
    D_01e4c854 = 8;
    D_01e4c855 = 8;
    D_01e4c856 = 8;
    D_01e4c857 = 8;
    D_01e4c858 = 8;
    D_01e4c859 = 8;
    D_01e4c85a = 8;
    D_01e4c85b = 8;
    D_01e4c85c = 8;
    D_01e4c85d = 8;
    D_01e4c85e = 8;
    D_01e4c85f = 8;
    D_01e4c860 = 8;
    D_01e4c861 = 8;
    D_01e4c862 = 8;
    D_01e4c863 = 8;
    D_01e4c864 = 8;
    D_01e4c865 = 8;
    D_01e4c866 = 8;
    D_01e4c867 = 8;
}

// ---- 002fac40
f32 func_002fb850(f32, s32);  // float_round_abs
f32 func_002f8888(f32);
extern const s32 D_003776e0[];
extern const f32 D_003776f0[];
static const f32 zero_krp = 0.0f, one_krp = 1.0f, two8 = 2.5600000000e+02f, twon8 = 3.9062500000e-03f;
// fdlibm/newlib __kernel_rem_pio2f (scalbnf is func_002fb850, floorf is func_002f8888).
s32 func_002fac40(f32 *x, f32 *y, s32 e0, s32 nx, s32 prec, const s32 *ipio2)
{
    s32 jz, jx, jv, jp, jk, carry, n, iq[20], i, j, k, m, q0, ih;
    f32 z, fw, f[20], fq[20], q[20];

    jk = D_003776e0[prec];
    jp = jk;

    jx = nx - 1;
    jv = (e0 - 3) / 8; if (jv < 0) jv = 0;
    q0 = e0 - 8 * (jv + 1);

    j = jv - jx; m = jx + jk;
    for (i = 0; i <= m; i++, j++) f[i] = (j < 0) ? zero_krp : (f32)ipio2[j];

    for (i = 0; i <= jk; i++) {
        for (j = 0, fw = 0.0f; j <= jx; j++) fw += x[j] * f[jx + i - j]; q[i] = fw;
    }

    jz = jk;
recompute:
    for (i = 0, j = jz, z = q[jz]; j > 0; i++, j--) {
        fw    = (f32)((s32)(twon8 * z));
        iq[i] = (s32)(z - two8 * fw);
        z     = q[j - 1] + fw;
    }

    z  = func_002fb850(z, (s32)q0);  // float_round_abs
    z -= (f32)8.0 * func_002f8888(z * (f32)0.125);
    n  = (s32)z;
    z -= (f32)n;
    ih = 0;
    if (q0 > 0) {
        i  = (iq[jz - 1] >> (8 - q0)); n += i;
        iq[jz - 1] -= i << (8 - q0);
        ih = iq[jz - 1] >> (7 - q0);
    }
    else if (q0 == 0) ih = iq[jz - 1] >> 8;
    else if (z >= (f32)0.5) ih = 2;

    if (ih > 0) {
        n += 1; carry = 0;
        for (i = 0; i < jz; i++) {
            j = iq[i];
            if (carry == 0) {
                if (j != 0) {
                    carry = 1; iq[i] = 0x100 - j;
                }
            } else iq[i] = 0xff - j;
        }
        if (q0 > 0) {
            switch (q0) {
            case 1:
                iq[jz - 1] &= 0x7f; break;
            case 2:
                iq[jz - 1] &= 0x3f; break;
            }
        }
        if (ih == 2) {
            z = one_krp - z;
            if (carry != 0) z -= func_002fb850(one_krp, (s32)q0);  // float_round_abs
        }
    }

    if (z == zero_krp) {
        j = 0;
        for (i = jz - 1; i >= jk; i--) j |= iq[i];
        if (j == 0) {
            for (k = 1; iq[jk - k] == 0; k++);

            for (i = jz + 1; i <= jz + k; i++) {
                f[jx + i] = (f32)ipio2[jv + i];
                for (j = 0, fw = 0.0f; j <= jx; j++) fw += x[j] * f[jx + i - j];
                q[i] = fw;
            }
            jz += k;
            goto recompute;
        }
    }

    if (z == (f32)0.0) {
        jz -= 1; q0 -= 8;
        while (iq[jz] == 0) { jz--; q0 -= 8; }
    } else {
        z = func_002fb850(z, -(s32)q0);  // float_round_abs
        if (z >= two8) {
            fw = (f32)((s32)(twon8 * z));
            iq[jz] = (s32)(z - two8 * fw);
            jz += 1; q0 += 8;
            iq[jz] = (s32)fw;
        } else iq[jz] = (s32)z;
    }

    fw = func_002fb850(one_krp, (s32)q0);  // float_round_abs
    for (i = jz; i >= 0; i--) {
        q[i] = fw * (f32)iq[i]; fw *= twon8;
    }

    for (i = jz; i >= 0; i--) {
        for (fw = 0.0f, k = 0; k <= jp && k <= jz - i; k++) fw += D_003776f0[k] * q[i + k];
        fq[jz - i] = fw;
    }

    switch (prec) {
    case 0:
        fw = 0.0f;
        for (i = jz; i >= 0; i--) fw += fq[i];
        y[0] = (ih == 0) ? fw : -fw;
        break;
    case 1:
    case 2:
        fw = 0.0f;
        for (i = jz; i >= 0; i--) fw += fq[i];
        y[0] = (ih == 0) ? fw : -fw;
        fw = fq[0] - fw;
        for (i = 1; i <= jz; i++) fw += fq[i];
        y[1] = (ih == 0) ? fw : -fw;
        break;
    case 3:
        for (i = jz; i > 0; i--) {
            fw      = fq[i - 1] + fq[i];
            fq[i]  += fq[i - 1] - fw;
            fq[i - 1] = fw;
        }
        for (i = jz; i > 1; i--) {
            fw      = fq[i - 1] + fq[i];
            fq[i]  += fq[i - 1] - fw;
            fq[i - 1] = fw;
        }
        for (fw = 0.0f, i = jz; i >= 2; i--) fw += fq[i];
        if (ih == 0) {
            y[0] =  fq[0]; y[1] =  fq[1]; y[2] =  fw;
        } else {
            y[0] = -fq[0]; y[1] = -fq[1]; y[2] = -fw;
        }
    }
    return n & 7;
}

// ---- 002f9e78
f32 func_002faa10(f32 x);
f32 func_002f8870(f32 x);  // fabsf
f32 func_002fb850(f32 x, s32 n);  // float_round_abs
extern const f32 D_003771b0[];
extern const f32 D_003771b8[];
extern const f32 D_003771c0[];
typedef union { f32 value; u32 word; } FloatShapePw;
#define GET_FLOAT_WORD_PW(i, d) do { FloatShapePw gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD_PW(d, i) do { FloatShapePw sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
#define bp D_003771b0
#define dp_h D_003771b8
#define dp_l D_003771c0
static const f32
zero_pw =  0.0,
one_pw  =  1.0,
two_pw  =  2.0,
two24_pw =  16777216.0,
huge_pw =  1.0e30,
tiny_pw =  1.0e-30,
L1_pw  =  6.0000002384e-01,
L2_pw  =  4.2857143283e-01,
L3_pw  =  3.3333334327e-01,
L4_pw  =  2.7272811532e-01,
L5_pw  =  2.3066075146e-01,
L6_pw  =  2.0697501302e-01,
P1_pw   =  1.6666667163e-01,
P2_pw   = -2.7777778450e-03,
P3_pw   =  6.6137559770e-05,
P4_pw   = -1.6533901999e-06,
P5_pw   =  4.1381369442e-08,
lg2_pw  =  6.9314718246e-01,
lg2_h_pw  =  6.93145752e-01,
lg2_l_pw  =  1.42860654e-06,
ovt_pw =  4.2995665694e-08,
cp_pw    =  9.6179670095e-01,
cp_h_pw  =  9.6179199219e-01,
cp_l_pw  =  4.7017383622e-06,
ivln2_pw    =  1.4426950216e+00,
ivln2_h_pw  =  1.4426879883e+00,
ivln2_l_pw  =  7.0526075433e-06;

// fdlibm/newlib __ieee754_powf, EE build (_FLT_NO_DENORMALS, _FLT_LARGEST_EXPONENT_IS_NORMAL).
f32 powf_2f9e78(f32 x, f32 y) asm("_Z13func_002f9e78Pv");
f32 powf_2f9e78(f32 x, f32 y)
{
    f32 z, ax, z_h, z_l, p_h, p_l;
    f32 y1, t1, t2, r, s, t, u, v, w;
    s32 i, j, k, yisint, n;
    s32 hx, hy, ix, iy, is;

    GET_FLOAT_WORD_PW(hx, x);
    GET_FLOAT_WORD_PW(hy, y);
    ix = hx & 0x7fffffff;  iy = hy & 0x7fffffff;

    if (iy < 0x00800000) return one_pw;

    yisint = 0;
    if (hx < 0) {
        if (iy >= 0x4b800000) yisint = 2;
        else if (iy >= 0x3f800000) {
            k = (iy >> 23) - 0x7f;
            j = iy >> (23 - k);
            if ((j << (23 - k)) == iy) yisint = 2 - (j & 1);
        }
    }

    if (iy == 0x3f800000) {
        if (hy < 0) return one_pw / x; else return x;
    }
    if (hy == 0x40000000) return x * x;
    if (hy == 0x3f000000) {
        if (hx >= 0)
            return func_002faa10(x);
    }

    ax = func_002f8870(x);  // fabsf
    if (ix < 0x00800000 || ix == 0x3f800000) {
        z = ax;
        if (hy < 0) z = one_pw / z;
        if (hx < 0) {
            if (((ix - 0x3f800000) | yisint) == 0) {
                z = (z - z) / (z - z);
            } else if (yisint == 1)
                z = -z;
        }
        return z;
    }

    if (((((u32)hx >> 31) - 1) | yisint) == 0) return (x - x) / (x - x);

    if (iy > 0x4d000000) {
        if (ix < 0x3f7ffff8) return (hy < 0) ? huge_pw * huge_pw : tiny_pw * tiny_pw;
        if (ix > 0x3f800007) return (hy > 0) ? huge_pw * huge_pw : tiny_pw * tiny_pw;
        t = x - 1;
        w = (t * t) * ((f32)0.5 - t * ((f32)0.333333333333 - t * (f32)0.25));
        u = ivln2_h_pw * t;
        v = t * ivln2_l_pw - w * ivln2_pw;
        t1 = u + v;
        GET_FLOAT_WORD_PW(is, t1);
        SET_FLOAT_WORD_PW(t1, is & 0xfffff000);
        t2 = v - (t1 - u);
    } else {
        f32 s2, s_h, s_l, t_h, t_l;
        n = 0;
        n  += ((ix) >> 23) - 0x7f;
        j  = ix & 0x007fffff;
        ix = j | 0x3f800000;
        if (j <= 0x1cc471) k = 0;
        else if (j < 0x5db3d7) k = 1;
        else { k = 0; n += 1; ix -= 0x00800000; }
        SET_FLOAT_WORD_PW(ax, ix);

        u = ax - bp[k];
        v = one_pw / (ax + bp[k]);
        s = u * v;
        s_h = s;
        GET_FLOAT_WORD_PW(is, s_h);
        SET_FLOAT_WORD_PW(s_h, is & 0xfffff000);
        SET_FLOAT_WORD_PW(t_h, ((ix >> 1) | 0x20000000) + 0x0040000 + (k << 21));
        t_l = ax - (t_h - bp[k]);
        s_l = v * ((u - s_h * t_h) - s_h * t_l);
        s2 = s * s;
        r = s2 * s2 * (L1_pw + s2 * (L2_pw + s2 * (L3_pw + s2 * (L4_pw + s2 * (L5_pw + s2 * L6_pw)))));
        r += s_l * (s_h + s);
        s2  = s_h * s_h;
        t_h = (f32)3.0 + s2 + r;
        GET_FLOAT_WORD_PW(is, t_h);
        SET_FLOAT_WORD_PW(t_h, is & 0xfffff000);
        t_l = r - ((t_h - (f32)3.0) - s2);
        u = s_h * t_h;
        v = s_l * t_h + t_l * s;
        p_h = u + v;
        GET_FLOAT_WORD_PW(is, p_h);
        SET_FLOAT_WORD_PW(p_h, is & 0xfffff000);
        p_l = v - (p_h - u);
        z_h = cp_h_pw * p_h;
        z_l = cp_l_pw * p_h + p_l * cp_pw + dp_l[k];
        t = (f32)n;
        t1 = (((z_h + z_l) + dp_h[k]) + t);
        GET_FLOAT_WORD_PW(is, t1);
        SET_FLOAT_WORD_PW(t1, is & 0xfffff000);
        t2 = z_l - (((t1 - t) - dp_h[k]) - z_h);
    }

    s = one_pw;
    if (((((u32)hx >> 31) - 1) | (yisint - 1)) == 0)
        s = -one_pw;

    GET_FLOAT_WORD_PW(is, y);
    SET_FLOAT_WORD_PW(y1, is & 0xfffff000);
    p_l = (y - y1) * t1 + y * t2;
    p_h = y1 * t1;
    z = p_l + p_h;
    GET_FLOAT_WORD_PW(j, z);
    i = j & 0x7fffffff;
    if (j > 0) {
        if (i > 0x43010000)
            return s * huge_pw * huge_pw;
        else if (i == 0x43010000)
            if (p_l + ovt_pw > z - p_h) return s * huge_pw * huge_pw;
    } else {
        if (i > 0x42fc0000)
            return s * tiny_pw * tiny_pw;
        else if (i == 0x42fc0000)
            if (p_l <= z - p_h) return s * tiny_pw * tiny_pw;
    }
    k = (i >> 23) - 0x7f;
    n = 0;
    if (i > 0x3f000000) {
        n = j + (0x00800000 >> (k + 1));
        k = ((n & 0x7fffffff) >> 23) - 0x7f;
        SET_FLOAT_WORD_PW(t, n & ~(0x007fffff >> k));
        n = ((n & 0x007fffff) | 0x00800000) >> (23 - k);
        if (j < 0) n = -n;
        p_h -= t;
    }
    t = p_l + p_h;
    GET_FLOAT_WORD_PW(is, t);
    SET_FLOAT_WORD_PW(t, is & 0xfffff000);
    u = t * lg2_h_pw;
    v = (p_l - (t - p_h)) * lg2_pw + t * lg2_l_pw;
    z = u + v;
    w = v - (z - u);
    t  = z * z;
    t1  = z - t * (P1_pw + t * (P2_pw + t * (P3_pw + t * (P4_pw + t * P5_pw))));
    r  = (z * t1) / (t1 - two_pw) - (w + z * w);
    z  = one_pw - (r - z);
    GET_FLOAT_WORD_PW(j, z);
    j += (n << 23);
    if ((j >> 23) <= 0) z = func_002fb850(z, (s32)n);  // float_round_abs
    else SET_FLOAT_WORD_PW(z, j);
    return s * z;
}
#undef bp
#undef dp_h
#undef dp_l

// ---- 00107a90
extern u8 D_003a7b70[];
extern u8 D_003a7f70[];
void func_00106998(s32);
void func_001069b8(s32);  // swap_global_word
void func_001069f8(s32);
void func_00106d40(void*, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32);
void func_00106de8(void*, s32, f32);
void func_00107330(void*, f32, f32, f32);
void func_00107340(void*, f32, f32, f32);
void func_00107350(void*, f32, f32, f32);
void func_00107360(void*, f32);
void func_00107a90(void) {
    func_00106998(0);
    func_001069b8(0);  // swap_global_word
    func_001069f8(0);
    func_00106d40(D_003a7b70, 512.0f, 0.7999999523162842f, 0.8666666150093079f, 2048.0f, 2048.0f, 1.0f, 16770000.0f, 1.0f, 4000000.0f, 256.0f, 208.0f);
    func_00106d40(D_003a7b70 + 256, 512.0f, 0.7999999523162842f, 0.8666666150093079f, 2048.0f, 2048.0f, 1.0f, 16770000.0f, 1.0f, 4000000.0f, 256.0f, 208.0f);
    func_00107330(D_003a7f70, 0.0f, -600.0f, -10000.0f);
    func_00107340(D_003a7f70, 1000.0f, -1000.0f, 0.0f);
    func_00107350(D_003a7f70, 0.0f, -1.0f, 0.0f);
    func_00107360(D_003a7f70, 0.0f);
    func_00107330(D_003a7f70 + 144, 0.0f, -600.0f, -10000.0f);
    func_00107340(D_003a7f70 + 144, 1000.0f, -1000.0f, 0.0f);
    func_00107350(D_003a7f70 + 144, 0.0f, -1.0f, 0.0f);
    func_00107360(D_003a7f70 + 144, 0.0f);
    func_00106de8(D_003a7b70, 0, 1.5f);
    func_00106de8(D_003a7b70 + 256, 0, 1.5f);
}

// ---- 00157c88
void func_001396b0(Sub4*);
void func_0031a260(Sub4*, s32);
void func_00156408(u8*);
s32 func_00156010(u8*);
s32 func_00156030(u8*);
s32 func_00156058(u8*);  // state_code_is_2
s32 func_00156080(u8*);  // state_code_is_3
void func_00155d80(u8*);
void func_001560a8(u8*, s32*, s32*);
void func_00155cb0(u8*, s32, s32);
s32 func_00155e30(u8*);
void func_00138c10_7c88(u8*, s32) asm("func_00138c10");
void func_00139598(u8*);
void func_00155bf0(u8*, u8);
s32 func_00105300(void);
void func_002ba2e8(s32, s32);
void func_001395a8(u8*);
u32 func_00158290(u8*);
u32 func_0013a7e8(s32);
u32 func_0013d7e0(void);
s32 func_00139c18(u8*);
s32 func_00139d78_7c88(Sub4*) asm("func_00139d78");
void func_001386e0_7c88(Sub4*, s32, u32, u32, s32, u32) asm("func_001386e0");
void func_00157c88(u8* p)
{
    func_00156408(p);
    if (func_00156010(p)) return;
    if (!func_00156030(p)) {
        if (func_00156058(p) || func_00156080(p)) {  // state_code_is_2
            s32 a = 0;
            s32 b = 0;
            func_00155d80(p);
            func_001560a8(p, &a, &b);
            func_00155cb0(p, a, b);
            if (p[15607] == 1) {
                p[15607] = 0;
                func_00138c10_7c88(p + 12472, func_00155e30(p));
            }
        } else {
            func_00155bf0(p, (*(u8**)(*(u8**)(p + 52) + 1164))[432]);
            func_00155d80(p);
            u8* q = *(u8**)(*(u8**)(p + 52) + 1164);
            bool full = q[433] >= q[434];
            if (full) {
                if (!p[15609]) {
                    if (p[15608] == 1 && !func_00105300()) func_002ba2e8(33, 0);
                    func_00138c10_7c88(p + 916, 20);
                    p[15609] = 1;
                }
                func_001395a8(p + 916);
            } else {
                p[15609] = 0;
                func_00139598(p + 916);
            }
            u8 f = p[15606];
            if (f != 1) return;
            p[15606] = 0;
            func_00138c10_7c88(p + 12472, func_00155e30(p));
            if (p[15608] != f) return;
            if (!p[15609]) func_002ba2e8(32, 0);
            u32 c = func_00158290(p);
            u32 h = func_0013a7e8(1);
            u32 w = func_0013d7e0();
            Sub4* s = (Sub4*)(p + func_00139c18(p + 2548) * 408 + 2548);
            if (!func_00139d78_7c88(s)) {
                func_001386e0_7c88(s, 7000, h, w, 22, c);
                s->owner = p + 11648;
                func_001396b0(s);
                if (s->owner) {
                    s->f400 = 0;
                    func_001396b0(s);
                    if (s->f400) func_0031a260(s, 0);
                }
            }
            p[15608] = 0;
            return;
        }
    }
    func_00139598(p + 916);
}

// ---- 001823d0
extern s32 D_0034ecd0;
extern s32 D_0034ecd4;
extern s32 D_0034ecec;
extern s32 D_0034ecf0;
extern s32 D_0034ece4;
extern s64 D_0034ecc0;
extern s64 D_0034ecc8;
extern s32 D_0034ecdc;
extern s32 D_0034ecd8;
extern s32 D_0034ece8;
extern s32 D_0034ece0;
extern u32 D_0034ecf4;
extern f32 D_01c6053c;
extern s32 D_01c60540;
extern s64 D_01c60548;
extern s64 D_01c60550;
extern s32 D_01c60558;
extern const char D_0036c878[];
extern const char D_0036c880[];
extern const char D_0036c888[];
extern u8 D_0034f250[];
extern u8 D_0034fa78[];
void func_00182df0(void);
u8* func_00168b88(u32, s32, u32, s32);  // find_entry16_by_half_word
void func_00181cc0(u32, u16);
void func_001955a8(void*, s32);
void func_001c0a00(s32);
#define FCC_3d0(s) ((s)[0] | ((s)[1] << 8) | ((s)[2] << 16) | ((s)[3] << 24))
void func_001823d0(u16* p)
{
    u8* e;
    D_0034ecd0 = 0;
    D_01c6053c = 10000.0f;
    D_0034ecd4 = 0;
    D_0034ecec = 0;
    D_0034ecf0 = 0;
    D_0034ece4 = -1;
    D_0034ecc0 = -1;
    D_0034ecc8 = 0;
    D_01c60540 = 0;
    D_0034ecd8 = 3;
    D_0034ecdc = 4;
    D_0034ece0 = 0;
    D_0034ece8 = 0;
    D_01c60548 = 0;
    D_01c60550 = 0;
    D_01c60558 = 0;
    func_00182df0();
    if ((e = func_00168b88(D_0034ecf4, 13, FCC_3d0(D_0036c878), 0)) != 0) { u32 v = *(u32*)(e + 8); func_00181cc0(v, p[0]); }
    if ((e = func_00168b88(D_0034ecf4, 13, FCC_3d0(D_0036c880), 0)) != 0) { u32 v = *(u32*)(e + 8); func_00181cc0(v, p[1]); }
    if ((e = func_00168b88(D_0034ecf4, 13, FCC_3d0(D_0036c888), 0)) != 0) { u32 v = *(u32*)(e + 8); func_00181cc0(v, p[2]); }
    if (!D_0034ecd0) D_0034ecd0 = 0x280000;
    if (!D_0034ecd4) D_0034ecd4 = 0x100000;
    if (!D_0034ecec) D_0034ecec = 0x80000;
    if (!D_0034ecf0) D_0034ecf0 = 0x20000;
    bool big = p[0] >= 51;
    if (big) {
        D_0034ecd8 = 0;
        D_0034ecdc = 0;
    }
    func_001955a8(D_0034f250, D_0034ecd8);
    func_001955a8(D_0034fa78, D_0034ecdc);
    func_001c0a00(D_01c60558);
    D_0034ecc0 = (D_0034ecc0 | D_01c60548) & ~D_01c60550;
}
#undef FCC_3d0

// ---- 002f9bc0
typedef union { f32 value; u32 word; } FloatShapeLg;
#define GET_FLOAT_WORD_LG(i, d) do { FloatShapeLg gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD_LG(d, i) do { FloatShapeLg sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
static const f32
ln2_hi_lg =   6.9313812256e-01,
ln2_lo_lg =   9.0580006145e-06,
two25_lg =    3.355443200e+07,
Lg1_lg = 6.6666668653e-01,
Lg2_lg = 4.0000000596e-01,
Lg3_lg = 2.8571429849e-01,
Lg4_lg = 2.2222198546e-01,
Lg5_lg = 1.8183572590e-01,
Lg6_lg = 1.5313838422e-01,
Lg7_lg = 1.4798198640e-01;
static const f32 zero_lg = 0.0;

// fdlibm/newlib __ieee754_logf, EE build (_FLT_NO_DENORMALS, _FLT_LARGEST_EXPONENT_IS_NORMAL).
f32 logf_2f9bc0(f32 x) asm("_Z16wtarget_002f9bc0jjjj");
f32 logf_2f9bc0(f32 x)
{
    f32 hfsq, f, s, z, R, w, t1, t2, dk;
    s32 k, ix, i, j;

    GET_FLOAT_WORD_LG(ix, x);

    k = 0;
    if ((ix & 0x7fffffff) < 0x00800000)
        return -two25_lg / zero_lg;
    if (ix < 0) return (x - x) / zero_lg;
    k += (ix >> 23) - 127;
    ix &= 0x007fffff;
    i = (ix + (0x95f64 << 3)) & 0x800000;
    SET_FLOAT_WORD_LG(x, ix | (i ^ 0x3f800000));
    k += (i >> 23);
    f = x - (f32)1.0;
    if ((0x007fffff & (15 + ix)) < 16) {
        if (f == zero_lg) { if (k == 0) return zero_lg; else { dk = (f32)k;
                             return dk * ln2_hi_lg + dk * ln2_lo_lg; } }
        R = f * f * ((f32)0.5 - (f32)0.33333333333333333 * f);
        if (k == 0) return f - R; else { dk = (f32)k;
                 return dk * ln2_hi_lg - ((R - dk * ln2_lo_lg) - f); }
    }
    s = f / ((f32)2.0 + f);
    dk = (f32)k;
    z = s * s;
    i = ix - (0x6147a << 3);
    w = z * z;
    j = (0x6b851 << 3) - ix;
    t1 = w * (Lg2_lg + w * (Lg4_lg + w * Lg6_lg));
    t2 = z * (Lg1_lg + w * (Lg3_lg + w * (Lg5_lg + w * Lg7_lg)));
    i |= j;
    R = t2 + t1;
    if (i > 0) {
        hfsq = (f32)0.5 * f * f;
        if (k == 0) return f - (hfsq - s * (hfsq + R)); else
                 return dk * ln2_hi_lg - ((hfsq - (s * (hfsq + R) + dk * ln2_lo_lg)) - f);
    } else {
        if (k == 0) return f - s * (f - R); else
                 return dk * ln2_hi_lg - ((s * (f - R) - dk * ln2_lo_lg) - f);
    }
}

// ---- 001620a8
void func_00107888(void);
void func_001433e8(void);
void func_00144250(void);
void func_0014df48(void);
void func_0015de18(void);
void func_00161868(void);
void func_00161880(void);
void func_001618a0(void);
void func_00161a10(void);
void func_00161a28(void);
void func_00161a40(void);
void func_00161c70(void);
void func_00167228(void);
void func_001dd2b8(void);
void func_001dd920(void);
void func_00106998(s32);
u8* func_00102c18(s32, s32, void (*)(void));
void func_001620a8(void)
{
    func_00106998(1);
    func_00102c18(5, 6000, func_00161868);
    func_00102c18(5, 6001, func_001433e8);
    func_00102c18(5, 6002, func_00161a10);
    func_00102c18(5, 29999, func_00161a28);
    func_00102c18(5, 30000, func_00107888);
    func_00102c18(5, 40999, func_00161a10);
    func_00102c18(5, 41000, func_001dd2b8);
    func_00102c18(5, 42999, func_00161a28);
    func_00102c18(5, 43000, func_00144250);
    func_00102c18(5, 49999, func_00161880);
    func_00102c18(5, 50000, func_001618a0);
    func_00102c18(5, 60000, func_00161a10);
    func_00102c18(5, 60001, func_001dd920);
    func_00102c18(5, 71000, func_00167228)[4] = 0;
    func_00102c18(5, 65000, func_0015de18);
    func_00102c18(5, 90000, func_00161a40);
    func_00102c18(5, 90005, func_0014df48);
    func_00102c18(5, 90010, func_00161868);
    func_00102c18(5, 90020, func_00161a10);
    func_00102c18(5, 90030, func_00107888);
    func_00102c18(5, 90039, func_00161a28);
    func_00102c18(5, 90040, func_001dd2b8);
    func_00102c18(5, 90049, func_00161a10);
    func_00102c18(5, 90050, func_00144250);
    func_00102c18(5, 90060, func_00161880);
    func_00102c18(5, 90070, func_001618a0);
    func_00102c18(5, 90079, func_00161a28);
    func_00102c18(5, 90080, func_001dd920);
    func_00102c18(5, 90100, func_00167228)[4] = 0;
    func_00102c18(5, 90110, func_0015de18);
    func_00102c18(5, 90130, func_00161c70);
}

// ---- 002c3e58
typedef void (*VFn58)(void*);
#define VCALL5_e58(o) ((VFn58)(*(void***)(o))[5])(o)
void func_00236d60(void);  // clear_64_entries_24
void func_002c3368_3e58(u8*) asm("func_002c3368");
void func_002c34d0_3e58(u8*) asm("func_002c34d0");
s32 func_00139d78_3e58(u8*) asm("func_00139d78");
s32 func_00139538(u8*);
s32 func_0028acc8(u32);
void func_0028abe0(u32);
s32 func_002c5120(u8*);
void func_00139510(u8*);
void func_002c85c8(u32);
s32 func_0023f0c0_3e58(u8*) asm("func_0023f0c0");
s32 func_002c3240(u8*, s32);
void func_002c3638(u8*);
void func_002c3c90(u8*);
void func_002c3e58(u8* p)
{
    func_00236d60();  // clear_64_entries_24
    switch (*(s32*)(p + 8260)) {
    case 1:
        func_002c3368_3e58(p);
        *(s32*)(p + 8260) = 0;
        break;
    case 2:
        func_002c34d0_3e58(p);
        *(s32*)(p + 8260) = 0;
        break;
    case 0:
        break;
    }
    u8* lay = p + 28;
    if (func_00139d78_3e58(lay) && func_00139538(lay)) {
        if (func_0028acc8(*(u32*)(p + 872))) func_0028abe0(*(u32*)(p + 872));
        if (func_002c5120(p)) {
            for (s32 i = 0; i < 9; i++) VCALL5_e58(p + 188 + i * 76);
            for (s32 i = 0; i < *(s32*)(p + 8252); i++) {
                u8* o = p + 1320 + i * 432;
                if (func_00139d78_3e58(o)) VCALL5_e58(o);
            }
            for (s32 i = 0; i < *(s32*)(p + 8256); i++) {
                u8* o = p + 4776 + i * 432;
                if (func_00139d78_3e58(o)) VCALL5_e58(o);
            }
            if (*(s32*)(p + 12368) && func_0028acc8(*(u32*)(p + 12360))) func_0028abe0(*(u32*)(p + 12360));
            if (func_00139d78_3e58(p + 13648)) func_00139510(p + 13648);
        }
    }
    if (!func_00139d78_3e58(p + 11872) && !func_00139d78_3e58(lay)) {
        VCALL5_e58(p);
        return;
    }
    func_002c85c8(*(u32*)(p + 8236));
    if (func_0023f0c0_3e58(lay) != func_002c3240(p, 2)) return;
    if (func_002c5120(p)) func_002c3638(p);
    else func_002c3c90(p);
}
#undef VCALL5_e58

// ---- 002f97c8
typedef union { f32 value; u32 word; } FloatShapeEx;
#define GET_FLOAT_WORD_EX(i, d) do { FloatShapeEx gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD_EX(d, i) do { FloatShapeEx sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
extern const f32 D_003770c8[];
extern const f32 D_003770d8[];
extern const f32 D_003770e0[];
#define halF_ex D_003770c8
#define ln2HI_ex D_003770d8
#define ln2LO_ex D_003770e0
static const f32
one_ex = 1.0,
huge_ex = 1.0e+30,
twom100_ex = 7.8886090522e-31,
invln2_ex = 1.4426950216e+00,
P1_ex = 1.6666667163e-01,
P2_ex = -2.7777778450e-03,
P3_ex = 6.6137559770e-05,
P4_ex = -1.6533901999e-06,
P5_ex = 4.1381369442e-08,
ln2HI0_ex = 6.9313812256e-01,
ln2LO0_ex = 9.0580006145e-06;

// fdlibm/newlib __ieee754_expf, EE build (_FLT_NO_DENORMALS, _FLT_LARGEST_EXPONENT_IS_NORMAL).
f32 expf_2f97c8(f32 x) asm("_Z16wtarget_002f97c8jjjj");
f32 expf_2f97c8(f32 x)
{
    f32 y, hi, lo, c, t;
    s32 k, xsb, sx;
    u32 hx;

    GET_FLOAT_WORD_EX(sx, x);
    xsb = (sx >> 31) & 1;
    hx = sx & 0x7fffffff;

    if (sx > 0x42b2d4fc)
        return huge_ex * huge_ex;
    if (sx < 0 && hx > 0x42aeac50)
        return twom100_ex * twom100_ex;

    if (hx > 0x3eb17218) {
        if (hx < 0x3F851592) {
            hi = x - ln2HI_ex[xsb]; lo = ln2LO_ex[xsb]; k = 1 - xsb - xsb;
        } else {
            k = (s32)(invln2_ex * x + halF_ex[xsb]);
            t = k;
            hi = x - t * ln2HI0_ex;
            lo = t * ln2LO0_ex;
        }
        x = hi - lo;
    }
    else if (hx < 0x31800000) {
        if (huge_ex + x > one_ex) return one_ex + x;
    }
    else k = 0;

    t = x * x;
    c = x - t * (P1_ex + t * (P2_ex + t * (P3_ex + t * (P4_ex + t * P5_ex))));
    if (k == 0) return one_ex - ((x * c) / (c - (f32)2.0) - x);
    else y = one_ex - ((lo - (x * c) / ((f32)2.0 - c)) - hi);
    if (k >= -125) {
        u32 hy;
        GET_FLOAT_WORD_EX(hy, y);
        SET_FLOAT_WORD_EX(y, hy + (k << 23));
        return y;
    } else {
        u32 hy;
        GET_FLOAT_WORD_EX(hy, y);
        SET_FLOAT_WORD_EX(y, hy + ((k + 100) << 23));
        return y * twom100_ex;
    }
}
#undef halF_ex
#undef ln2HI_ex
#undef ln2LO_ex

// ---- 002fb558
typedef union { f32 value; u32 word; } FloatShapeTn;
#define GET_FLOAT_WORD_TN(i, d) do { FloatShapeTn gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD_TN(d, i) do { FloatShapeTn sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
f32 func_002f8870(f32 x);  // fabsf
static const f32
one_tn   =  1.0000000000e+00,
pio4_tn  =  7.8539812565e-01,
pio4lo_tn =  3.7748947079e-08,
T_tn[] = {
  3.3333334327e-01,
  1.3333334029e-01,
  5.3968254477e-02,
  2.1869488060e-02,
  8.8632395491e-03,
  3.5920790397e-03,
  1.4562094584e-03,
  5.8804126456e-04,
  2.4646313977e-04,
  7.8179444245e-05,
  7.1407252108e-05,
 -1.8558637748e-05,
  2.5907305826e-05,
};

// fdlibm/newlib __kernel_tanf (fabsf is func_002f8870).
f32 func_002fb558(f32 x, f32 y, s32 iy)
{
    f32 z, r, v, w, s;
    s32 ix, hx;
    GET_FLOAT_WORD_TN(hx, x);
    ix = hx & 0x7fffffff;
    if (ix < 0x31800000)
        {if ((int)x == 0) {
            if ((ix | (iy + 1)) == 0) return one_tn / func_002f8870(x);  // fabsf
            else return (iy == 1) ? x : -one_tn / x;
        }
        }
    if (ix >= 0x3f2ca140) {
        if (hx < 0) {x = -x; y = -y;}
        z = pio4_tn - x;
        w = pio4lo_tn - y;
        x = z + w; y = 0.0;
    }
    z = x * x;
    w = z * z;
    r = T_tn[1] + w * (T_tn[3] + w * (T_tn[5] + w * (T_tn[7] + w * (T_tn[9] + w * T_tn[11]))));
    v = z * (T_tn[2] + w * (T_tn[4] + w * (T_tn[6] + w * (T_tn[8] + w * (T_tn[10] + w * T_tn[12])))));
    s = z * x;
    r = y + z * (s * (r + v) + y);
    r += T_tn[0] * s;
    w = x + r;
    if (ix >= 0x3f2ca140) {
        v = (f32)iy;
        return (f32)(1 - ((hx >> 30) & 2)) * (v - (f32)2.0 * (x - (w * w / (w + v) - r)));
    }
    if (iy == 1) return w;
    else {
        f32 a, t;
        s32 i;
        z = w;
        GET_FLOAT_WORD_TN(i, z);
        SET_FLOAT_WORD_TN(z, i & 0xfffff000);
        v = r - (z - x);
        t = a = -(f32)1.0 / w;
        GET_FLOAT_WORD_TN(i, t);
        SET_FLOAT_WORD_TN(t, i & 0xfffff000);
        s = (f32)1.0 + t * z;
        return t + a * (s + t * v);
    }
}

// ---- 001219b8
void func_001217a0(u8*, u32, u32, u32, u32);
void func_00134408(void);
void func_00134428(s32, u64);
void func_00134450(s32);
u32 func_00109f58(s32, u32, u8);
u32 func_00109ea8(s32, u32, u8);
u32 func_0010ae90(void);  // get_table_34ed8
void func_00108ae0(u32, s32, u64, u64, u32, u32, s32, s32);
void func_00109670(void);
void func_001219b8(u8* p, u32 a1, u32 a2, u8* q, u32 a4, u8 flag, u32 a6, u32 a7)
{
    func_001217a0(p, a1, a2, a4, a6);
    func_00134408();
    func_00134428(76, 0x40140);
    func_00134428(78, *(u64*)(q + 24) | (1ull << 32));
    func_00134428(71, 0x30003);
    func_00134428(8, 5);
    func_00134428(24, (15ull << 43) | 0x7800);
    func_00134428(64, 0xff000000ff0000ull);
    func_00134428(66, (1ull << 39) | 0x44);
    func_00134428(0, 86);
    func_00134428(1, 0x3f80000080808080ull);
    func_00134428(2, 0);
    func_00134428(5, 0x78007800);
    func_00134428(2, 0x3f8000003f800000ull);
    func_00134428(5, (17ull << 27) | 0x8800);
    func_00134450(1);
    func_001217a0(p, a1, a2, a4, a7);
    func_00134408();
    func_00134428(76, 0xff00000000040140ull);
    func_00134428(8, 5);
    func_00134428(0, 86);
    func_00134428(1, ((u64)((q[40] >> 1) & 0xff) << 24) | 0x3f80000000808080ull);
    func_00134428(2, 0);
    func_00134428(5, 0x78007800);
    func_00134428(2, 0x3f8000003f800000ull);
    func_00134428(5, (17ull << 27) | 0x8800);
    func_00134428(24, (115ull << 40) | 0x7000);
    func_00134428(64, 0x19f000001ff0000ull);
    func_00134428(6, 0x2000000620012800ull);
    func_00134450(1);
    if (!flag) {
        u32 x = func_00109f58(7, *(u32*)(*(u8**)(p + 4) + 4), q[7]);
        u32 y = func_00109ea8(7, *(u32*)(*(u8**)(p + 4) + 4), q[7]);
        func_00108ae0(func_0010ae90(), 15, *(u64*)(q + 16), *(u64*)(q + 24) & ~(1ull << 32), y, x, 0, 0);
    } else {
        u32 x = func_00109f58(11, *(u32*)(*(u8**)(p + 4) + 4), q[7]);
        u32 y = func_00109ea8(11, *(u32*)(*(u8**)(p + 4) + 4), q[7]);
        func_00108ae0(func_0010ae90(), 15, *(u64*)(q + 16) | (0xffull << 56), *(u64*)(q + 24) | (1ull << 32), y, x, 0, 0);
    }
    func_00109670();
}

// ---- 002f8420
typedef union { f32 value; u32 word; } FloatShapeAt;
#define GET_FLOAT_WORD_AT(i, d) do { FloatShapeAt gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
f32 func_002f8870(f32 x);  // fabsf
extern const f32 D_00376ed8[];
extern const f32 D_00376ee8[];
#define atanhi_at D_00376ed8
#define atanlo_at D_00376ee8
static const f32 atanhi3_at = 1.5707962513e+00, atanlo3_at = 7.5497894159e-08;
static const f32 aT_at[] = {
  3.3333334327e-01,
 -2.0000000298e-01,
  1.4285714924e-01,
 -1.1111110449e-01,
  9.0908870101e-02,
 -7.6918758452e-02,
  6.6610731184e-02,
 -5.8335702866e-02,
  4.9768779427e-02,
 -3.6531571299e-02,
  1.6285819933e-02,
};
static const f32 one_at = 1.0, huge_at = 1.0e30;

// fdlibm/newlib atanf (fabsf is func_002f8870), EE build.
f32 func_002f8420(f32 x)
{
    f32 w, s1, s2, z;
    s32 ix, hx, id;

    GET_FLOAT_WORD_AT(hx, x);
    ix = hx & 0x7fffffff;
    if (ix >= 0x50800000) {
        if (hx > 0) return atanhi3_at + atanlo3_at;
        else return -atanhi3_at - atanlo3_at;
    } if (ix < 0x3ee00000) {
        if (ix < 0x31000000) {
            if (huge_at + x > one_at) return x;
        }
        id = -1;
    } else {
    x = func_002f8870(x);  // fabsf
    if (ix < 0x3f980000) {
        if (ix < 0x3f300000) {
            id = 0; x = ((f32)2.0 * x - one_at) / ((f32)2.0 + x);
        } else {
            id = 1; x = (x - one_at) / (x + one_at);
        }
    } else {
        if (ix < 0x401c0000) {
            id = 2; x = (x - (f32)1.5) / (one_at + (f32)1.5 * x);
        } else {
            id = 3; x = -(f32)1.0 / x;
        }
    }}
    z = x * x;
    w = z * z;
    s1 = z * (aT_at[0] + w * (aT_at[2] + w * (aT_at[4] + w * (aT_at[6] + w * (aT_at[8] + w * aT_at[10])))));
    s2 = w * (aT_at[1] + w * (aT_at[3] + w * (aT_at[5] + w * (aT_at[7] + w * aT_at[9]))));
    if (id < 0) return x - x * (s1 + s2);
    else {
        z = atanhi_at[id] - ((x * (s1 + s2) - atanlo_at[id]) - x);
        return (hx < 0) ? -z : z;
    }
}
#undef atanhi_at
#undef atanlo_at

// ---- 002c4e98
struct Init5_98 { u8* obj; u32 w[4]; };
struct La98 { u8 d[32]; };
struct Ent98 { u8 pad[24]; u32 a; u32 b; };
extern u8 D_01e2bd30[];
extern u8 D_01e2bd20[];
extern Ent98 D_00375630[];
s32 func_002cb200(u8*, u8, u8*);
void func_0023f800(La98*);
u32 func_001708f8_4e98(u32, s32) asm("func_001708f8");
void func_0023fa08(La98*, u32);
u32 func_0023f948(La98*, s32);
u32 func_0023f908(La98*, s32);
u32 func_002c3240_4e98(u8*, s32) asm("func_002c3240");
void func_0023eea0(u8*, s32, u32, u32, u32, s32);
void func_0023ef50(u8*);
void func_0023f0c8(u8*, u32);
u8* func_0023f1b0_4e98(u8*) asm("func_0023f1b0");
u32 func_0023c4b8_4e98(u8*, s32) asm("func_0023c4b8");
u32 func_00236ca8_4e98(u32, s32) asm("func_00236ca8");
s32 func_002c5120(u8*);
void func_002cb0e8_4e98(Init5_98*, u8*, f32) asm("func_002cb0e8");
void func_002c44b8(u8*);
void func_002c4ca8(u8*);
u32 func_002c3268_4e98(u8*) asm("func_002c3268");
void func_0023f1e0_4e98(u8*, s32, u8*, u32, Ent98*, u32, s32, s32) asm("func_0023f1e0");
void func_00139620(u8*);
void func_001395e8_4e98(u8*) asm("func_001395e8");
void func_001395f8(u8*);
void func_0023f6c0_4e98(u8*, u32) asm("func_0023f6c0");
u32 func_002c24e0(u32);
u32 func_002c2518(u32);
void func_0023f618(u8*, u32);
void func_00139638_4e98(u8*) asm("func_00139638");
void func_001391c8_4e98(u8*, s32, s32) asm("func_001391c8");
void func_0023f848(La98*);
void func_002c4e98(u8* p, u32 res, Init5_98* arg)
{
    La98 la;
    *(Init5_98*)(p + 13620) = *arg;
    u8 kind = (*(u8**)(arg->obj + 2808))[4];
    *(u32*)(p + 8236) = kind;
    if (func_002cb200(p + 8272, kind, p + 8248)) *(s32*)(p + 8244) = 1;
    else *(s32*)(p + 8244) = 0;
    func_0023f800(&la);
    u8* lay = p + 28;
    *(u32*)(p + 8232) = func_001708f8_4e98(res, -1);
    func_0023fa08(&la, *(u32*)(p + 8232));
    u32 w = func_0023f948(&la, 0);
    u32 h = func_0023f908(&la, 0);
    func_0023eea0(lay, 30001, w, h, func_002c3240_4e98(p, 0), 0);
    func_0023ef50(lay);
    func_0023f0c8(lay, func_002c3240_4e98(p, 2));
    *(u32*)(p + 13640) = func_0023c4b8_4e98(func_0023f1b0_4e98(lay), 1);
    *(u32*)(p + 13644) = func_00236ca8_4e98(*(u32*)(func_0023f1b0_4e98(lay) + 40), 1);
    if (func_002c5120(p)) {
        func_002cb0e8_4e98(arg, D_01e2bd30, 0.0f);
        func_002c44b8(p);
    } else {
        func_002cb0e8_4e98(arg, D_01e2bd20, 0.0f);
        func_002c4ca8(p);
    }
    if (func_002c5120(p)) {
        u8* o = p + 188;
        Ent98* e = D_00375630;
        s32 i;
        for (i = 0; i < 9; i++) {
            func_0023f1e0_4e98(o, 30005, lay, func_002c3268_4e98(p), e, e->a, 0, 0);
            func_00139620(o);
            func_001395e8_4e98(o);
            func_001395f8(o);
            func_0023f6c0_4e98(o, e->b);
            o += 76;
            e++;
        }
        func_0023f618(p + 720, func_002c24e0(*(u32*)(p + 8236)));
        func_00139638_4e98(p + 720);
        func_0023f618(p + 796, func_002c2518(*(u32*)(p + 8236)));
        func_00139638_4e98(p + 796);
    }
    func_001391c8_4e98(p, 30002, 0);
    func_0023f848(&la);
}

// ---- 0013c820
u32 func_0013b5d0(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, f32);
void func_00139570_c820(u32) asm("func_00139570");
void func_0013c820(u32 a0, u32 a1) {
    func_00139570_c820(func_0013b5d0(a0, a1, 2, 0, 0, 0, 0, 0, 0x80e6e6e6, 2, 1.0f));
}

// ---- 00176818
void func_0017f540(u8*, u32, f32, f32);
void func_001842c0(u8*);
void func_00176818(u8* p) {
    if (!(*(u32*)(p + 360) & 0x10)) func_0017f540(p + 320, 4, 16.0f, 0.0f);
    func_001842c0(p);
}

// ---- 0017c108
static inline __attribute__((always_inline)) void h_0017c108(u8* q, u32 f, u32 v) {
    if ((f & 4) || ((f & 0x10) && v)) func_0017f540(q, v, 8.0f, 0.0f);
}
void func_0017c108(u32 a0, u8* p, u32 a2) { h_0017c108(p + 320, *(u32*)(p + 352), a2); }

// ---- 001d5cd0
s32 func_001d6ec8();
s32 func_001d5b78(u32, u32);
struct G_001d5cd0 { u8 pad[4150]; u8 c; };
extern G_001d5cd0 D_0032e020;
s32 func_001d5cd0() {
    G_001d5cd0* g = &D_0032e020;
    s32 n = func_001d6ec8();
    if (g->c < n) return func_001d5b78(0, g->c);
    return 0;
}

// ---- 001d79b8
struct E_001d79b8 { s32 key; f32 v; };
struct P_001d79b8 { u32 x; E_001d79b8 e[4]; };
void func_001d7b10(P_001d79b8*);
void func_001d79b8(P_001d79b8* p, s32 key, f32 v) {
    E_001d79b8* r = 0;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (p->e[i].key == key) { r = &p->e[i]; break; }
        if (p->e[i].key == 0) r = &p->e[i];
    }
    r->key = key;
    r->v = v;
    func_001d7b10(p);
}

// ---- 001ddd30
struct Nd_001ddd30 { u8 pad[20]; Nd_001ddd30* next; };
extern Nd_001ddd30* D_01d9e348;
static inline Nd_001ddd30* Next_001ddd30(Nd_001ddd30* n) { if (!n) return D_01d9e348; return n->next; }
static inline bool Has_001ddd30(Nd_001ddd30* x) {
    Nd_001ddd30* n = 0;
    while ((n = Next_001ddd30(n))) { if (n == x) return true; }
    return false;
}
void func_001dde40_dd30(Nd_001ddd30*) asm("func_001dde40");
void func_001ddd30(Nd_001ddd30* a0) {
    if (Has_001ddd30(a0)) func_001dde40_dd30(a0);
}

// ---- 002e7518
struct Nd_002e7518 { Nd_002e7518* next; };
extern Nd_002e7518* D_01e2bf00;
void func_002e73d8(Nd_002e7518*);
static inline Nd_002e7518* Next_002e7518(Nd_002e7518* n) { if (!n) return D_01e2bf00; return n->next; }
void wt_002e7518() asm("_Z16wtarget_002e7518jjjj");
void wt_002e7518() {
    Nd_002e7518* n = 0;
    while ((n = Next_002e7518(n))) func_002e73d8(n);
}

// ---- 001b9bc8
extern u8* D_01d48da0;
s32 func_0019baa8(u8*);
static inline u8* Next_001b9bc8(u8* n) { if (!n) return D_01d48da0; return *(u8**)(n + 2228); }
u8* ct_001b9bc8(u8* p) asm("_Z16ctarget_001b9bc8jjjj");
u8* ct_001b9bc8(u8* p) {
    while ((p = Next_001b9bc8(p)) && func_0019baa8(p)) {}
    return p;
}

// ---- 00304f50
struct Reent_00304f50 { s32 _errno; };
extern s32 D_00378ae4;
s32 func_00305be8(u32, u32, u32);
long func_00304f50(Reent_00304f50* ptr, u32 a, u32 b, u32 c) {
    long ret;
    D_00378ae4 = 0;
    if ((ret = (long)func_00305be8(a, b, c)) == -1 && D_00378ae4 != 0) ptr->_errno = D_00378ae4;
    return ret;
}

} // extern "C"
// ---- 001b3208
namespace YS {
struct OEnt_001b3208 { s32 id; u32 y; };
struct OTab_001b3208 { u32 x; s32 n; OEnt_001b3208 e[1]; };
union OFl_001b3208 { u32 f; OTab_001b3208* t; };
struct OObj_001b3208 { u8 pad[128]; OFl_001b3208* p; u8 pad2[12]; };
struct OBJOCC { OTab_001b3208* tab; OObj_001b3208* objs; void disable(int); };
void OBJOCC::disable(int id) {
    for (s32 i = 0; i < tab->n; i++) {
        if (tab->e[i].id == id) objs[i].p[2].f |= 2;
    }
}
}
extern "C" {

// ---- 001055b8
s32 func_001055b8(void* a0) {
    // Hand-written longjmp in the original.
    asm volatile(
        "lq $28, 0(%0)\n\tlq $29, 16(%0)\n\tlq $30, 32(%0)\n\tlq $31, 48(%0)\n\t"
        "lq $16, 64(%0)\n\tlq $17, 80(%0)\n\tlq $18, 96(%0)\n\tlq $19, 112(%0)\n\t"
        "lq $20, 128(%0)\n\tlq $21, 144(%0)\n\tlq $22, 160(%0)\n\tlq $23, 176(%0)\n\t"
        "lwc1 $f20, 192(%0)\n\tlwc1 $f21, 196(%0)\n\tlwc1 $f22, 200(%0)\n\tlwc1 $f23, 204(%0)\n\t"
        "lwc1 $f24, 208(%0)\n\tlwc1 $f25, 212(%0)\n\tlwc1 $f26, 216(%0)\n\tlwc1 $f27, 220(%0)\n\t"
        "lwc1 $f28, 224(%0)\n\tlwc1 $f29, 228(%0)\n\tlwc1 $f30, 232(%0)\n\tlwc1 $f31, 236(%0)"
        : : "r"(a0));
    return 1;
}

// ---- 00123c20
extern u8 D_00347a90[];
void func_0011f3b8(u8*);
void func_0011ee58(u32*);  // set_vtbl_347940
struct NoTail_00123c20 { ~NoTail_00123c20() {} };
void func_00123c20(u32* p) {
    NoTail_00123c20 nt;
    u8* q = (u8*)p[1];
    *p = (u32)D_00347a90;
    for (s32* s = (s32*)(q + 16); *s; s++) func_0011f3b8(q + *s);
    func_0011ee58(p);  // set_vtbl_347940
}

// ---- 001fb720
void func_001fa950(u8*, u8*, u8*);
union UH_001fb720 { u16 h; f32 f; };
void func_001fb720(u8* a0, u8* a1, u8* a2) {
    u8* q = a0 + **(s32**)(a2 + 12) + 160;
    func_001fa950(a0, a1, a2);
    if (*(u32*)a1 == *(u32*)(a0 + 12)) {
        *(f32*)(q + 68) = *(f32*)(a1 + 12);
        *(f32*)(q + 64) = ((UH_001fb720*)(a1 + 20))->h;
    }
}

// ---- 00294f00
extern bool D_0035f580;
extern bool D_0035f581;
void func_00294e48();
void func_00294f78(u32);
void func_00294f00() {
    if (D_0035f580 && D_0035f581) return;
    if (!D_0035f580) func_00294e48();
    if (D_0035f580 && !D_0035f581) func_00294f78(1);
}

// ---- 0029a368
extern bool D_0035f5a8;
extern bool D_0035f5a9;
void func_0029a2a0();
void func_0029a3e0(u32);
void func_0029a368() {
    if (D_0035f5a8 && D_0035f5a9) return;
    if (!D_0035f5a8) func_0029a2a0();
    if (D_0035f5a8 && !D_0035f5a9) func_0029a3e0(1);
}

// ---- 00123c98
void func_00106420_3c98(u32*) asm("func_00106420");
void func_00123c98(u32* p) {
    u8* q = (u8*)p[1];
    *p = (u32)D_00347a90;
    for (s32* s = (s32*)(q + 16); *s; s++) func_0011f3b8(q + *s);
    func_0011ee58(p);  // set_vtbl_347940
    func_00106420_3c98(p);
}

// ---- 00143520
struct S_00143520 { u8 pad[48]; Vec4 pos; u8 pad2[32]; s16 h96, h98, h100; u8 pad3[6]; f32 f108; u8 pad4[8]; u32 w120; u8 pad5[20]; };
void func_0031b9e0(S_00143520*);
void func_00143648(S_00143520*, u32);
void func_00143520(Vec4* v, u32 a1) {
    S_00143520 s;
    func_0031b9e0(&s);
    if (&s.pos != v) QCOPY(&s.pos, v);
    s.w120 = 0;
    s.h96 = -1;
    s.f108 = 100.0f;
    s.h100 = -1;
    s.h98 = -1;
    func_00143648(&s, a1);
}

// ---- 00197318
void func_00170320(u32);
void func_00196e88_7318(u32*, u32, u32, f32) asm("func_00196e88");
union UH_00197318 { u16 h; u32 i; };
void func_00197318(u32* p) {
    func_00170320(2000);
    u32 fl = p[0];
    p[0] = fl | 1;
    u8 b = (((UH_00197318*)(p[15] + 2))->h >> 1) & 1;
    if (b) { func_00196e88_7318(p, 3, 0, 0.0f); return; }
    p[0] = fl | 3;
    func_00196e88_7318(p, 4, 0, 0.0f);
}

// ---- 001b5ef0
extern u32 D_00351214;
union UDf_001b5ef0 { u8* p; void (*f)(); u32 i; };
extern UDf_001b5ef0 D_00351180;
extern u8 D_00351ec0[];
void func_001b5f68();
void func_001b5fe0();
u8* func_00102818(u32, u32, u32, void (*)(), u32);
void func_001c8d80(u8*, u32);
void func_001b5ef0(u8* p) {
    u8* t = func_00102818(D_00351214, 0, 2, func_001b5f68, 8192);
    *(u8**)(t + 4) = p;
    *(void (**)())(t + 48) = func_001b5fe0;
    D_00351180.p = t;
    func_001c8d80(D_00351ec0, 2);
    *(u32*)(p + 264) |= 0x100;
}

// ---- 001c3670
struct E_001c3670 { u16 id; u8 pad[6]; };
struct T_001c3670 { u32 x; s32 n; E_001c3670 e[1]; };
extern T_001c3670* D_01d49560;
extern u32 D_0032fca8[];
void func_001c3670(u32 id) {
    T_001c3670* t = D_01d49560;
    E_001c3670* e = t->e;
    for (s32 i = 0; i < t->n; i++, e++) {
        if (e->id == id) break;
    }
    u32 m = 1 << (id & 31);
    u32* b = D_0032fca8;
    b[id >> 5] |= m;
    b += 4;
    b[id >> 5] |= m;
}

// ---- 001b14d8
struct T2_001b14d8 { u32 a, b; };
extern T2_001b14d8 D_01d44100;
struct Sub_001b14d8 { u8 pad[640]; s32 arr[16]; };
extern Sub_001b14d8 D_01d44108;
extern s32 D_01d443c8;
extern u8 D_00350e8c;
void func_001b1560();
void func_001b18e8();
u8* func_00102c18_14d8(u32, u32, void (*)()) asm("func_00102c18");
void func_001b14d8() {
    D_01d44100.a = 0;
    D_01d44100.b = 0;
    for (s32 i = 0; i < 16; i++) D_01d44108.arr[i] = i;
    D_01d443c8 = 16;
    D_00350e8c = 0;
    *(void (**)())(func_00102c18_14d8(1, 42000, func_001b1560) + 48) = func_001b18e8;
}

// ---- 001de590
extern u8* D_00352b58;
s32 func_001dc9e0(u8*);
void func_001dfa38(u8*);
void func_001de590(u8* p) {
    u8* o = *(u8**)(p + 12);
    while (o) {
        u8* nx = *(u8**)(o + 96);
        if (func_001dc9e0(*(u8**)(o + 64))) {
            u8 b = (*(s32*)(*(u8**)(o + 64) + 8) >> 26) & 1;
            if (!b) {
                D_00352b58 = o;
                func_001dfa38(o);
                D_00352b58 = 0;
            }
        }
        o = nx;
    }
}

// ---- 0022e368
union UA_0022e368 { s32 i; s16 s; u16 h; };
struct E_0022e368 { UA_0022e368 a; UA_0022e368 b; UA_0022e368 c; UA_0022e368 d; u8 pad2[30]; u16 e; u8 pad3[4]; };
union UG_0022e368 { E_0022e368* p; s32 i; u16 h; };
extern UG_0022e368 D_0035dcf4_e368 asm("D_0035dcf4");
void func_0022e368(UA_0022e368* a0) {
    for (s32 i = 0; i < 96; i++) {
        if (D_0035dcf4_e368.p[i].b.i == -1) {
            D_0035dcf4_e368.p[i].b.i = ((UA_0022e368*)((u8*)a0 + 8))->s;
            D_0035dcf4_e368.p[i].a.i = ((UA_0022e368*)((u8*)a0 + 10))->s;
            D_0035dcf4_e368.p[i].c.h = ((UA_0022e368*)((u8*)a0 + 12))->h;
            ((UA_0022e368*)&D_0035dcf4_e368.p[i].e)->h = ((UA_0022e368*)((u8*)a0 + 4))->h;
            D_0035dcf4_e368.p[i].d.i = 0;
            return;
        }
    }
}

// ---- 002aaa38
struct B_002aaa38 { u8 pad[132]; u32 bits[1]; };
extern B_002aaa38* D_0035f610;
static inline bool Bit_002aaa38(u32* b, u32 i) { b += i >> 5; return (*b & (1 << (i & 31))) != 0; }
bool f_002aaa38(s32 n) asm("func_002aaa38");
bool f_002aaa38(s32 n) {
    if (n < 0) {
        u32* b = D_0035f610->bits;
        bool r;
        s32 i = 0;
        do { r = (b[(u32)i >> 5] & (1 << (i & 31))) != 0; if (r) break; } while (++i < 32);
        return r;
    }
    return Bit_002aaa38(D_0035f610->bits, n);
}

// ---- 002e0698
extern u8* D_00361f60;
struct VT_002e0698 { u8 pad[48]; u32 (*f)(void*); };
void func_00180c88(u8*, u32, f32);
s32 func_00197920();
void func_001d86a0(s32, u32);
void func_002dd4f8(u8*);
void func_002e0698(VT_002e0698** o, u8* p) {
    u32 t = (*o)->f(o);
    func_00180c88(p + 320, t, 0.0f);
    u8* g = D_00361f60;
    if (*(s32*)(g + 0x8000 + 116) > 0 && *(s32*)(g + 128) == 2 && !func_00197920()) func_001d86a0(-1, 1);
    func_002dd4f8(g);
}

// ---- 002eb6f8
u8* func_002eaf40(u8*);
void func_0017f488(u8*, s32, f32, f32);
void func_002eb6f8(u8* p, s32 id, f32 x) {
    if (id < 0) return;
    func_00180c88(p + 320, id, x);
    func_002eaf40(p);
    func_0017f488(func_002eaf40(p) + 320, id - 101, x, 0.0f);
}

// ---- 0011f4b8
union UC_0011f4b8 { u16 h; u32 i; };
void func_0011ee18(u8*);  // obj_ctor_347940
extern u8 D_003479a8[];
void func_0011f4b8(u8* p) {
    func_0011ee18(p);  // obj_ctor_347940
    u8* t = *(u8**)(p + 4);
    *(u32*)p = (u32)D_003479a8;
    for (s32 i = 0; i < ((UC_0011f4b8*)(t + 16))->h; i++) {
        u8* e = t + i * 16;
        if (*(u32*)(e + 40) > 0xffff) *(u32*)(p + 12) |= 1;
        u16 f = *(u16*)(e + 38) & 1;
        if (f) *(u32*)(p + 12) |= 2;
    }
}

// ---- 00142bf8
void func_0014ed28(u32, s32);
void func_00142bf8(u8* p) {
    for (s32 i = 0; i < *(s32*)(p + 40); i++) {
        u8* e = *(u8**)(p + 12);
        e += i * 16;
        u32* t = *(u32**)(p + 20);
        t += *(u16*)(e + 14);
        u32 w = *t;
        if (w & 0x60000) func_0014ed28((w >> 17) & 3, i);
    }
}

// ---- 00180378
void func_0017f380(u8*);  // obj_walk_children
u32 func_0017ec98(u8*, u32);
u32 func_0017edf0(u8*, u32);
void func_001801b0(u32, u32, u32, u8*, u32, f32);
void func_00180378(u8* p, u8* a1, u32 a2, f32 x) {
    func_0017f380(a1 + 320);  // obj_walk_children
    u32 r = func_0017edf0(p, func_0017ec98(p, a2));
    u32 o = *(u32*)(p + 8);
    func_001801b0(o, r, *(u32*)(p + 240), a1, o + 1160, x);
    *(u32*)(a1 + 340) = a2;
    *(u8**)(a1 + 576) = *(u8**)p;
}

// ---- 001b1a30
struct C4_001b1a30 { u8 r, g, b, a; };
f32* func_0015cc70();
void func_001b1a30(u8* p, s32 a1) {
    *(s32*)p = a1;
    *(u32*)(p + 12) = 0;
    s32 m = 128;
    *(u32*)(p + 16) = 0;
    *(f32*)(p + 8) = 1.0f;
    C4_001b1a30* c = (C4_001b1a30*)(p + 20);
    c->r = m;
    c->g = m;
    c->b = m;
    c->a = m;
    if (*(s32*)p == 1) {
        f32* v = func_0015cc70();
        *(f32*)(p + 24) = v[1];
        *(f32*)(p + 28) = v[2];
        *(f32*)(p + 32) = v[3];
        *(f32*)(p + 36) = v[4];
    }
}

// ---- 001c0150
struct L_001c0150 { u8* head; u8* tail; };
extern L_001c0150 D_01d49350;
void func_001c0150(u8* p, u32 a1) {  // obj_init_fields_1c0150
    *(u32*)p = a1;
    for (s32 i = 0; i < 8; i++) ((u32*)(p + 4))[i] = 0;
    *(u32*)(p + 36) = 0;
    *(u32*)(p + 40) = 0;
    *(u32*)(p + 44) = 0;
    u8* q = p + 48;
    for (s32 n = 3; n != -1; n--) { *(u32*)q = 0; q += 8; }
    L_001c0150* l = &D_01d49350;
    if (!l->tail) {
        l->tail = p;
        l->head = p;
        *(u8**)(p + 80) = 0;
    } else {
        *(u8**)(l->tail + 80) = p;
        *(u8**)(p + 80) = 0;
        l->tail = p;
    }
}

// ---- 00265b88
u8* func_00257770_5b88() asm("func_00257770");
s32 func_00139d78_5b88(u8*) asm("func_00139d78");
extern u32 D_0035f01c, D_0035f020;
s32 func_0028acc8(u32);
struct NoTail_00265b88 { ~NoTail_00265b88() {} };
void func_00265b88() {
    NoTail_00265b88 nt;
    u8* o = func_00257770_5b88();
    if (func_00139d78_5b88(o)) return;
    o += 24304;
    for (s32 i = 0; i < 20; i++, o += 436) {
        if (func_00139d78_5b88(o)) return;
    }
    if (func_0028acc8(D_0035f01c)) return;
    func_0028acc8(D_0035f020);
}

// ---- 00225550
s32 func_00224e90();
u32 func_001050c8();
u32* func_001063c0_5550(u32, u32) asm("func_001063c0");
u32 func_00170b30_5550(u32) asm("func_00170b30");
void func_00225e70(u32*, u32, u32);
union UP_00225550 { u32* p; u32 i; };
extern u32 D_0035db18_5550 asm("D_0035db18"); extern UP_00225550 D_0035dae4; extern u32 D_0035dae8;
void func_00225550() {
    if (func_00224e90()) return;
    if (D_0035db18_5550 != 0x400000) return;
    if (D_0035dae4.p) return;
    u32* o = func_001063c0_5550(12, func_001050c8());
    o[0] = 0;
    o[1] = 0;
    o[2] = 0;
    D_0035dae4.p = o;
    D_0035dae8 = func_00170b30_5550(0x200000);
    func_00225e70(D_0035dae4.p, D_0035dae8, 0x200000);
}

// ---- 0028e2a8
HeapE* func_0013a1d8();
void func_00239700_e2a8(void*) asm("func_00239700");
struct T380_0028e2a8 { T380_0028e2a8() { func_00239700_e2a8(this); } ~T380_0028e2a8() {} u8 pad[380]; };
void func_0028e2a8(u8* p, s32 n) {
    if (!*(u32*)(p + 56)) *(T380_0028e2a8**)(p + 56) = new (func_0013a1d8()) T380_0028e2a8[n];
    *(s32*)(p + 24) = n;
}

// ---- 002ef7f0
s32 func_002ef7b8();
void func_002ef7a0_f7f0(u32, u32) asm("func_002ef7a0");
extern s8 D_003638c8;
void func_002ef7f0(s32 on) {
    if (!func_002ef7b8()) return;
    if (on) {
        if (D_003638c8 == 0) func_002ef7a0_f7f0(3, 0);
        D_003638c8++;
    } else if (D_003638c8 != 0) {
        if (--D_003638c8 == 0) func_002ef7a0_f7f0(4, 0);
    }
}

// ---- 00176f00
s32 func_001a1de0(u32);
s32 func_001b58a8();
u8* func_00177860(u8*);
void func_001a1d50(u32, f32);
extern f32 D_00349e10;
void func_00176f00(u8* p) {
    if (!*(u32*)(p + 1164)) return;
    if (!func_001a1de0(*(u32*)(p + 1164))) return;
    if (*(u32*)(p + 2040) & 4) return;
    if ((*(u32*)(p + 1416) & 0x80) && func_001b58a8()) return;
    f32 k = -D_00349e10;
    u8* r = func_00177860(p);
    func_001a1d50(*(u32*)(p + 1164), k * *(f32*)(r + 56));
}

// ---- 0018cd28
union UP_0018cd28 { u8* p; f32 f; };
extern UP_0018cd28 D_00352130_cd28 asm("D_00352130");
s32 func_0018ca48(u8);
void func_0018cd28(u8* p, f32* x, f32* y) {
    *x = *(f32*)(D_00352130_cd28.p + 36);
    *y = *(f32*)(D_00352130_cd28.p + 40);
    if (func_0018ca48(p[39]) != 4) return;
    UP_0018cd28* f = (UP_0018cd28*)(p + 32);
    if (!f->p) return;
    if (!*(u32*)(f->p + 12)) return;
    *x = (f32)*(s16*)(f->p + 12);
    *y = (f32)*(s16*)(f->p + 14);
}

// ---- 001ab750
void func_001b7e68(u8*, u32);
u32 func_001aaea8(u8*, u32);
void func_001b8010(u8*, u32, u32, u32, u32, u32, u32, u32, s32, u64, s32, u64, s32, u64, u64);
void func_001b80d8_b750(u8*) asm("func_001b80d8");
void func_001ab750(u8* p, u8* q) {
    func_001b7e68(q, 8);
    u32 r = func_001aaea8(p, 0);
    func_001b8010(q, 1, 71, 0x3000d, 63, 0, 6, r, 20, 96, 22, 0x4007ff8001300000ull, 66, 68, 0xffff);
    func_001b80d8_b750(q);
}

// ---- 001d5470
u8* func_00168b38_5470(u32, s32, u32) asm("func_00168b38");
void func_001d5370(u32*, u32, s32);
union UA_001d5470 { u32 i; u16 h; u8 b; };
void func_001d5470(u32* s, u32 a1, u8* a2) {
    s[1] = *(u32*)(func_00168b38_5470(a1, -1, ((UA_001d5470*)(a2 + 4))->b) + 8);
    s[2] = ((UA_001d5470*)(a2 + 6))->h;
    if (!((UA_001d5470*)(a2 + 5))->b) return;
    if (s[0] == 12) s[0] = 13;
    func_001d5370(s + 3, a1, ((UA_001d5470*)(a2 + 5))->b - 1);
}

// ---- 002c0370
union UA_002c0370 { u32 i; f32 f; u8* p; };
void func_0031cc28(u8*);
void func_002c6420(u8*);
extern u8 D_00361da8[];
extern u8 D_00361a80[];
extern UA_002c0370 D_00361a70;
void func_002c0370(u8* p, u32 a1, UA_002c0370* a2) {
    *(u32*)p = (u32)D_00361da8;
    func_0031cc28(p + 84);
    ((UA_002c0370*)(p + 92))->i = 0;
    func_002c6420(p);
    ((UA_002c0370*)(p + 96))->i = a1;
    *(u32*)p = (u32)D_00361a80;
    ((UA_002c0370*)(p + 100))->i = a2[0].i;
    ((UA_002c0370*)(p + 104))->i = a2[1].i;
    ((UA_002c0370*)(p + 108))->i = a2[2].i;
    ((UA_002c0370*)(p + 112))->i = a2[3].i;
    ((UA_002c0370*)(p + 116))->i = a2[4].i;
    D_00361a70.p = p;
    ((UA_002c0370*)(p + 92))->f = 30.0f;
}

// ---- 002fb850
f32 func_002fb900(f32, f32);
union FW_002fb850 { f32 f; s32 i; };
static const f32 huge_002fb850 = 1.0e+30, tiny_002fb850 = 1.0e-30;
f32 func_002fb850(f32 x, s32 n) {  // float_round_abs
    s32 k, ix;
    u32 hx;
    FW_002fb850 u; u.f = x; ix = u.i;
    hx = ix & 0x7fffffff;
    k = hx >> 23;
    if (hx < 0x00800000) return x;
    k = k + n;
    if (k > 255) return huge_002fb850 * func_002fb900(huge_002fb850, x);
    if (k > 0) { FW_002fb850 v; v.i = (ix & 0x807fffff) | (k << 23); return v.f; }
    if (n > 50000) return huge_002fb850 * func_002fb900(huge_002fb850, x);
    return tiny_002fb850 * func_002fb900(tiny_002fb850, x);
}

// ---- 001091c8
struct AlVt_001091c8 { void* (*alloc)(void*, u32, void*); };
struct Al_001091c8 { AlVt_001091c8* vt; };
union UG_001091c8 { s32 i; void* p; };
extern UG_001091c8 D_0033cc68;
extern UG_001091c8 D_0033cc64;
extern UG_001091c8 D_0033cc6c;
extern UG_001091c8 D_0033cc70;
void func_00133cf0(void*, u32);
void func_00109070();
void func_001091c8(Al_001091c8* o, s32 n, u32 sz) {
    D_0033cc68.i = n;
    void* m = o->vt->alloc(o, sz, __builtin_return_address(0));
    D_0033cc64.p = m;
    func_00133cf0(m, sz);
    D_0033cc6c.p = o->vt->alloc(o, D_0033cc68.i * 88, __builtin_return_address(0));
    D_0033cc70.p = o->vt->alloc(o, D_0033cc68.i * 288, __builtin_return_address(0));
    func_00109070();
}

// ---- 00252760
void func_00287b18(u32, u32);
union UG_00252760 { u32 i; u16 h; u8* p; };
extern UG_00252760 D_0035ee9c_2760 asm("D_0035ee9c");
extern UG_00252760 D_0035eea0_2760 asm("D_0035eea0");
extern UG_00252760 D_0035eea4_2760 asm("D_0035eea4");
extern UG_00252760 D_0035eea8_2760 asm("D_0035eea8");
extern u8* D_00347f80_2760 asm("D_00347f80");
struct VT_00252760 { void* (*f)(void*, u32, u32); };
extern u8 D_00347e60[];
extern u8 D_00347e40[];
void func_00239700(u8*);
u8* func_00103eb0();
void func_00252890();
void func_00102818_2760(u32, u32, u32, void (*)(), u32) asm("func_00102818");
void func_00252760() {
    func_00287b18(5, 3);
    D_0035ee9c_2760.i = 0;
    D_0035eea0_2760.h = 0;
    D_0035eea4_2760.i = 0;
    VT_00252760** al = *(VT_00252760***)(D_00347f80_2760 + 20);
    u8* o = (u8*)(*al)->f(al, 436, 0);
    *(u32*)(o + 12) = 0;
    *(u32*)o = (u32)D_00347e60;
    func_00239700(o + 24);
    *(u32*)(o + 408) = 0;
    *(u32*)o = (u32)D_00347e40;
    D_0035eea8_2760.p = o;
    func_00102818_2760(*(u32*)(func_00103eb0() + 4), 0, 2000, func_00252890, 4096);
}

// ---- 0028f6f0
union UG_0028f6f0 { u8* p; u32 i; };
extern UG_0028f6f0 D_0035f480;
s32 func_00139d78_f6f0(u8*) asm("func_00139d78");
s16* func_0028f690(s32);  // record884_type_index
void func_00138c10_f6f0(u8*, s32) asm("func_00138c10");
void func_0028d5d0(u8*);
void func_0028f6f0(s32 i) {  // record884_refresh_by_index
    if (!D_0035f480.p) return;
    s32 off = i * 884;
    if (!func_00139d78_f6f0(D_0035f480.p + off)) return;
    s16* v = func_0028f690(i);  // record884_type_index
    if (*(s32*)(D_0035f480.p + off + 388) == v[1]) return;
    func_00138c10_f6f0(D_0035f480.p + off, v[1]);
    *(s32*)(D_0035f480.p + off + 392) = -1;
    func_0028d5d0(D_0035f480.p + off + 436);
}

// ---- 00304fb0
void* func_002fd680(void*, u32);
void* func_002fde18_4fb0(void*, s32, u32) asm("func_002fde18");
void* calloc_r_00304fb0(void* ptr, u32 n, u32 elem) asm("func_00304fb0");
void* calloc_r_00304fb0(void* ptr, u32 n, u32 elem) {
    u32* mem = (u32*)func_002fd680(ptr, n * elem);
    if (mem == 0) return 0;
    u32 csz = mem[-1] & ~3;
    u32 mzsz = csz - 4;
    if (mzsz <= 9 * sizeof(mzsz)) {
        u32* mz = mem;
        if (mzsz >= 5 * sizeof(mzsz)) {
            *mz++ = 0;
            *mz++ = 0;
            if (mzsz >= 7 * sizeof(mzsz)) {
                *mz++ = 0;
                *mz++ = 0;
                if (mzsz >= 9 * sizeof(mzsz)) {
                    *mz++ = 0;
                    *mz++ = 0;
                }
            }
        }
        *mz++ = 0;
        *mz++ = 0;
        *mz = 0;
    } else func_002fde18_4fb0(mem, 0, mzsz);
    return mem;
}

// ---- 001cedc0
void func_001780d8(u8*);
u8* func_0016b740_edc0(u32) asm("func_0016b740");
void func_001c0d38(u8*, u8*, u32, u32);
void func_0017fd30(u8*, u8*);
void func_0017f488_edc0(u8*, u32, f32, f32) asm("func_0017f488");
void func_0017f5e0(u8*, u32, u32, f32, f32);
void func_0016bd60_edc0(u8*, u32) asm("func_0016bd60");
void func_00198860(u8*, u32);
void func_001cedc0(u8* p) {
    func_001780d8(p);
    u8* r = func_0016b740_edc0(1620);
    *(u8**)(p + 2924) = r;
    if (r) {
        func_001c0d38(r, p, 16386, 0);
        func_0017fd30(p + 320, *(u8**)(p + 2924) + 320);
    }
    f32 z = 0.0f;
    func_0017f488_edc0(p + 320, 44, z, z);
    func_0017f5e0(p + 320, 0, 0, z, z);
    func_0016bd60_edc0(p, 23);
    func_00198860(p, 9);
}
// ---- 002f8960 (newlib sinf)
f32 func_002fb460(f32, f32, s32);  // float_to_int
f32 func_002faaf0(f32, f32);  // float_to_int_b
s32 func_002fa678(f32, f32*);
union FWs_2f8960 { f32 f; s32 i; };
f32 func_002f8960(f32 x) {
    f32 y[2], z = 0.0;
    s32 n, ix;
    FWs_2f8960 u; u.f = x; ix = u.i;
    ix &= 0x7fffffff;
    if (ix <= 0x3f490fd8) return func_002fb460(x, z, 0);  // float_to_int
    n = func_002fa678(x, y);
    switch (n & 3) {
    case 0: return func_002fb460(y[0], y[1], 1);  // float_to_int
    case 1: return func_002faaf0(y[0], y[1]);  // float_to_int_b
    case 2: return -func_002fb460(y[0], y[1], 1);  // float_to_int
    default: return -func_002faaf0(y[0], y[1]);  // float_to_int_b
    }
}

// ---- 001b4c48
u8* func_00168b88_4c48(u32, u32, s32, u32) asm("func_00168b88");
static inline s32 rd4_1b4c48(s8* b) { return b[0] | (b[1] << 8) | (b[2] << 16) | (b[3] << 24); }
void func_001b4c48(u8* p, u32* out, s8* b) {
    u8* x = func_00168b88_4c48(*(u32*)(p + 4), 24, rd4_1b4c48(b), 0);
    u8* y = func_00168b88_4c48(*(u32*)(p + 4), 25, rd4_1b4c48(b), 0);
    u32 a = *(u32*)(x + 8);
    u32 c = *(u32*)(y + 8);
    out[0] = a;
    out[1] = c;
}
// ---- 00197828
struct G197 { u8 pad[60]; u8* o; u8 pad2[80]; f32 f144; };
union U197 { G197* g; u8** p; };
extern U197 D_0035037c;
void func_0014ce60();
s32 func_00242ea8();
s32 func_00224e90();
void func_00138480(u32);
void func_001c1130(u32);  // copy_record_block_to_table
void func_002bc798();
void func_00196e88_7828(G197*, u32, u32, f32) asm("func_00196e88");
struct F197 { u16 pad; u16 b0:1; u16 b1:1; u16 b2:1; u16 b3:1; u16 b4:1; u16 b5:1; };
static inline u8 b0_197828() { return ((F197*)(*(G197* volatile*)&D_0035037c.g)->o)->b0; }
static inline u8 b5_197828() { return ((F197*)(*(G197* volatile*)&D_0035037c.g)->o)->b5; }
void func_00197828(f32 f) {
    func_0014ce60();
    if (b0_197828()) {
        if (!func_00242ea8()) func_001c1130(4);
        else {
            if (func_00224e90()) func_00138480(0);
            func_001c1130(36);  // copy_record_block_to_table
        }
    }
    if (!b5_197828()) func_002bc798();
    func_00196e88_7828(D_0035037c.g, 5, 0, 0.0f);
    D_0035037c.g->f144 = f;
}
// ---- 001cf8d0
void func_001d86a0(s32, u32);
void func_001d8820(s32);
void func_0017f488_f8d0(u8*, u32, f32, f32) asm("func_0017f488");
void func_0017f5e0(u8*, u32, u32, f32, f32);
void func_001cf8d0(u8* p, u8* a1) {
    f32 z;
    switch (*(u16*)(a1 + 2)) {
    case 411:
        z = 0.0f;
        func_001d86a0(-1, 1);
        func_0017f488_f8d0(p + 320, 201, z, z);
        func_0017f5e0(p + 320, 0, 0, z, z);
        break;
    case 412:
        z = 0.0f;
        func_001d8820(1);
        func_0017f488_f8d0(p + 320, 161, z, z);
        func_0017f5e0(p + 320, 0, 0, z, z);
        break;
    }
}
// ---- 0028fe38
void func_00290060(u8*, u32, u32, u32);
void func_001386e0_fe38(u32, u32, u32, u32, s32, u32) asm("func_001386e0");
void func_00259020(u32, u32, u32, u32, u32, u16*, u32, u32);
void func_0028ff00(u8*);
union UH28f { u16 h; s32 i; };
void func_0028fe38_fe38(u8* p, u32 a1, u32 a2, u32 a3) asm("func_0028fe38");
void func_0028fe38_fe38(u8* p, u32 a1, u32 a2, u32 a3) {
    func_00290060(p, a1, a2, a3);
    func_001386e0_fe38(*(u32*)p, a1, a2, a3, *(s16*)(p + 8), 0);
    *(s32*)(*(u8**)p + 392) = *(s16*)(p + 12);
    u16 buf[6];
    u16* d = buf;
    for (s32 i = 5; i >= 0; i--) *d++ = ((UH28f*)(p + 16))->h;
    func_00259020(*(u32*)(p + 4), *(u32*)p, a1, a2, a3, buf, 6, 0);
    func_0028ff00(p);
}
// ---- 0024e5b0
extern u32 D_0035edcc;
extern s8 D_0035edfc;
extern u8* D_0035ede8;
extern s32 D_0035edf4;
s32 func_002891e8(u32);
s32 func_00139d78_e5b0(u8*) asm("func_00139d78");
void func_00138c10_e5b0(u8*, u32) asm("func_00138c10");
void func_00243230(u32, s32);
void func_0024e5b0() {
    s32 i = func_002891e8(D_0035edcc);
    if (!((D_0035edfc >> i) & 1)) return;
    if (func_00139d78_e5b0(D_0035ede8 + i * 408)) {
        u8* a = D_0035ede8 + i * 408;
        if (*(s32*)(a + 388) != 37) func_00138c10_e5b0(a, 37);
    }
    func_00243230(0, D_0035edf4 ? i + 3 : i);
}
// ---- 00295158
u8* func_00294000(u32);
s32 func_002941a8(u8*);
s32 func_00276c18();
s32 func_00295158(s32 k) {
    s32 cnt = -1;
    s32 res = -1;
    u8* t = func_00294000(0);
    u8* base = t + 16;
    for (s32 i = 0; i < *(s32*)(t + 8); i++) {
        u8* e = base + i * 16;
        if (*(s8*)e < 16 && (func_002941a8(e) || func_00276c18())) {
            cnt++;
            if (k == cnt) { res = i; break; }
        }
    }
    return res;
}
// ---- 0029fbf0
s32 func_002943e8(u8*);
extern u8* D_0035f5d0;
void func_0029fbf0() {
    s32 i = 0;
    s32 n = 0;
    u8* t = func_00294000(4);
    D_0035f5d0[0] = 0;
    u8* base = t + 16;
    for (; i < *(s32*)(t + 8); i++) {
        if (func_002943e8(base + i * 8) || func_00276c18()) {
            D_0035f5d0[n + 6] = i;
            n++;
        }
    }
    D_0035f5d0[0] = n;
}
// ---- 002a5d30
s32 func_002944d0(u8*);
extern u8* D_0035f5ec;
void func_002a5d30() {
    s32 i = 0;
    s32 n = 0;
    u8* t = func_00294000(6);
    D_0035f5ec[0] = 0;
    u8* base = t + 16;
    for (; i < *(s32*)(t + 8); i++) {
        if (func_002944d0(base + i * 8) || func_00276c18()) {
            D_0035f5ec[n + 6] = i;
            n++;
        }
    }
    D_0035f5ec[0] = n;
}
// ---- 00294288
union UH_294288 { u16 h; u32 i; };
s32 func_00294268(u8*);
void func_00294288(s32 id, u32* a, u32* b) {
    u8* t = func_00294000(1);
    *b = 0x8adc;
    *a = 0x8adc;
    u8* base = t + 16;
    for (s32 i = 0; i < *(s32*)(t + 8); i++) {
        u8* e = base + i * 12;
        if (*(s8*)e == id && func_00294268(e)) {
            *a = ((UH_294288*)(e + 4))->h;
            *b = ((UH_294288*)(e + 6))->h;
        }
    }
}

// --------------------
union unaligned {
    void* ptr;
    u16 u2;
    u32 u4;
    u64 u8;
    s16 s2;
    s32 s4;
    s64 s8;
} __attribute__((__packed__));
const u8* func_00100430(const u8* p, u64* val);
const u8* func_00100468(const u8* p, s64* val);
void func_002fd160(void) __attribute__((noreturn));

const u8* func_001004c0(u8 encoding, u32 base, const u8* p, u32* val) {
    const union unaligned* u = (const union unaligned*)p;
    u32 result;

    if (encoding == 0x50) {
        u32 a = (u32)p;
        a = (a + 3) & -4;
        result = *(u32*)a;
        p = (const u8*)(a + 4);
    } else {
        switch (encoding & 0x0f) {
        case 0x00:
            result = (u32)u->ptr;
            p += 4;
            break;
        case 0x01: {
            u64 tmp;
            p = func_00100430(p, &tmp);
            result = (u32)tmp;
        } break;
        case 0x09: {
            s64 tmp;
            p = func_00100468(p, &tmp);
            result = (u32)tmp;
        } break;
        case 0x02: result = u->u2; p += 2; break;
        case 0x03: result = u->u4; p += 4; break;
        case 0x04: result = u->u8; p += 8; break;
        case 0x0a: result = u->s2; p += 2; break;
        case 0x0b: result = u->s4; p += 4; break;
        case 0x0c: result = u->s8; p += 8; break;
        default: func_002fd160();
        }
        if (result != 0) {
            result += ((encoding & 0x70) == 0x10 ? (u32)u : base);
            if (encoding & 0x80)
                result = *(u32*)result;
        }
    }
    *val = result;
    return p;
}

// --------------------
u32 func_001069e8(void);
void func_00140850(u8*);
void func_001403b0(u8*);
void func_0013f608(u8*);
void func_00140f30(u8*);
void func_001407d0(u8*);
void func_001408a0(u8*, u8);
void func_00140760(u8*);
void func_0015a5a8(u8*);
void func_00159070_x8002(u8*) asm("func_00159070");
void func_00159b00(u8*);
void func_00159368(u8*);
void func_00158dc0(u8*);
void func_00158708(u8*);
void func_00158658(u8*);
void func_0014e8b8(u8*);
void func_001589d0(u8*);

void wtarget_00140b68(u8* p, u8 flag) asm("_Z16wtarget_00140b68jjjj");
void wtarget_00140b68(u8* p, u8 flag) {
    if (*(u32*)(p + 68) == 0) return;
    if (flag == 0 && func_001069e8() != 0) return;
    func_00140850(p);
    switch (*(u32*)(p + 64)) {
    case 0: func_001403b0(p); break;
    case 1: func_00140760(p); break;
    case 2: func_0015a5a8(p); break;
    case 3: func_00159070_x8002(p); break;
    case 4: func_00159b00(p); break;
    case 5: func_00159368(p); break;
    case 6: func_00158dc0(p); break;
    case 7: func_00158708(p); break;
    case 8: func_00158658(p); break;
    case 9: func_0014e8b8(p); break;
    case 10: func_001589d0(p); break;
    case 11: break;
    }
    func_0013f608(p);
    func_00140f30(p);
    func_001407d0(p);
    func_001408a0(p, flag);
}

// --------------------
extern f32 D_00349e14;  // 1.0f
struct W14aaa8 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    u8 pad[15];
    u8 alpha;
    u8 pad2[228];
    s32 count;
    s32 state;
    f32 t;
    f32 scale;
};
void wtarget_0014aaa8(W14aaa8* p) asm("_Z16wtarget_0014aaa8jjjj");
void wtarget_0014aaa8(W14aaa8* p) {
    switch (p->state) {
    case 0:
        return;
    case 1:
        if (p->count == 0) p->state = 2;
        p->count--;
        p->alpha = 0x80;
        break;
    case 2:
        p->t -= D_00349e14;
        p->alpha = (s32)(p->scale * p->t);
        if (p->t <= 0.0f) {
            p->alpha = 0;
            p->state = 0;
        }
        break;
    case 3:
        p->t -= D_00349e14;
        p->alpha = 0x80 - (s32)(p->scale * p->t);
        if (p->t <= 0.0f) {
            p->alpha = 0x80;
            p->state = 4;
        }
        break;
    case 4:
        break;
    }
    p->v2();
}

// --------------------
s32 func_00155d80_r(u8*) asm("func_00155d80");
extern s32 D_0034a8f0[];
extern s32 D_0034a8a0[];
extern s32 D_0034a8c8[];
s32 func_00155e30(u8* p) {
    u8* o = *(u8**)(p + 52);
    if (o != 0) {
        switch (*(*(u8**)(o + 1164) + 431)) {
        case 2:
            func_00155d80_r(p);
            return D_0034a8f0[func_00155d80_r(p)];
        case 0: case 1: case 4:
            break;
        case 3:
            func_00155d80_r(p);
            return D_0034a8a0[func_00155d80_r(p)];
        }
    }
    func_00155d80_r(p);
    return D_0034a8c8[func_00155d80_r(p)];
}

// --------------------
struct Rel168Ent { u16 type; u16 flags; u32 pad; u32 ofs; u32 size; };
struct Rel168Hdr { u32 pad; s32 count; u32 base; u32 pad2; Rel168Ent e[1]; };
void func_0011f2f0(u32);
void func_00131e80(u32);
void func_0013a8b8(u32);
void func_001dc098(u32);
void func_00127d40(u32);
void func_001de750(u32);
void func_00168be8(Rel168Hdr* h) {
    s32 i;
    if (h->base != 0) return;
    h->base = (u32)h;
    for (i = 0; i < h->count; i++) {
        if (h->e[i].size == 0) {
            h->e[i].ofs = 0;
            continue;
        }
        u32 p = h->base + h->e[i].ofs;
        h->e[i].ofs = p;
        if (h->e[i].flags & 1) continue;
        switch (h->e[i].type) {
        case 1: case 17: case 20: case 30: case 46:
            func_00168be8((Rel168Hdr*)p);
            break;
        case 4:
            func_0011f2f0(p);
            break;
        case 7:
            func_00131e80(p);
            func_0013a8b8(p);
            break;
        case 8:
            func_001dc098(p);
            break;
        case 9:
            func_00127d40(p);
            break;
        case 18:
            func_001de750(p);
            break;
        }
    }
}

// --------------------
struct Rel168eEnt { u16 type; u16 flags; u32 pad; u32 ofs; u32 size; };
struct Rel168eHdr { u32 pad; s32 count; u32 base; u32 pad2; Rel168eEnt e[1]; };
void func_0011f3b8_x8152(u32) asm("func_0011f3b8");
void func_00131f40(u32);
void func_00127da0(u32);
void func_002bc708(u32);
void func_00168e30(Rel168eHdr* h) {
    s32 i;
    h->base = (u32)h;
    for (i = 0; i < h->count; i++) {
        if (h->e[i].size == 0) continue;
        if (h->e[i].flags & 1) continue;
        u32 p = h->e[i].ofs;
        switch (h->e[i].type) {
        case 1: case 17: case 20: case 30: case 46:
            func_00168e30((Rel168eHdr*)p);
            break;
        case 4:
            func_0011f3b8_x8152(p);
            break;
        case 7:
            func_00131f40(p);
            break;
        case 9:
            func_00127da0(p);
            break;
        case 34:
            func_002bc708(p);
            break;
        }
    }
}

// --------------------
struct T16c168 { u8 pad[14]; s16 a; s16 b; s16 c; s16 d; s16 e; };
s32 func_001849b8(u8*);
T16c168* func_001aec40();
s32 func_0016a070_x8187(u8*) asm("func_0016a070");
void* func_0016c028_x8188(u8*) asm("func_0016c028");
void func_002bc188(s32, void*);
void func_0016c168(u8* obj, s32 n) {
    s32 id = func_001849b8(obj);
    if (id == 0) return;
    T16c168* t = func_001aec40();
    if (t == 0) return;
    s32 v;
    switch (func_0016a070_x8187(obj)) {
    case 1: case 14:
        v = t->a;
        break;
    case 2:
        v = t->b;
        break;
    case 3:
        v = t->c;
        break;
    case 4:
        v = t->e;
        break;
    default:
        if (func_0016a070_x8187(obj) < 16) v = t->d;
        else v = t->e;
        break;
    }
    if (n == 4 || n == 0) {
        n += obj[2044]++ & 3;
    } else if (n == 13) {
        n = (obj[2044]++ & 1) + 13;
    }
    func_002bc188(v * 1000 + id * 16 + n, func_0016c028_x8188(obj));
}

// --------------------
struct T182280 { u8 pad[72]; s32 a; s32 b; s32 c; u32 flags; };
T182280* func_00198c28(s32, s32);
void func_00198e50(T182280*, u32, s32);
void func_0019ef90_x8227(void*, u8*) asm("func_0019ef90");
void func_00198e40(T182280*, s32);
void func_00198e48(T182280*, s32);
void func_00198e60(T182280*, s32, u8*);
void func_00182280(void* unused, u8* p) {
    u8* end = p + *(s16*)(p + 2) * 4 + 4;
    T182280* o = func_00198c28(*(s16*)(p + 4), *(s16*)(p + 6));
    p += 8;
    while (p < end) {
        switch (*(u16*)p) {
        case 0:
            func_00198e50(o, *(u32*)(p + 4), *(s16*)(p + 2));
            p += 8;
            break;
        case 1:
            func_0019ef90_x8227((u8*)o + 52, p + 4);
            p += 16;
            break;
        case 2:
            func_00198e40(o, *(s16*)(p + 2));
            p += 4;
            break;
        case 3:
            func_00198e48(o, *(s16*)(p + 2));
            p += 4;
            break;
        case 4:
            o->a = *(s16*)(p + 2);
            p += 4;
            break;
        case 5:
            o->b = *(s16*)(p + 2);
            p += 4;
            break;
        case 6:
            func_00198e60(o, *(s16*)(p + 2), p + 4);
            p = p + *(s16*)(p + 2) * 4 + 4;
            break;
        case 7:
            o->c = *(s16*)(p + 2);
            p += 4;
            break;
        case 8:
            o->flags |= 1;
            p += 4;
            break;
        }
    }
}

// --------------------
s32 func_00301550(char*, const char*, va_list);
char* func_00192cc0(char* buf, const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    s32 n = func_00301550(buf, fmt, ap);
    s32 i;
    for (i = 0; i < n; i++) {
        s8 c = buf[i];
        if ((u32)(c - '0') < 10) c = c - 15;
        else if ((u32)(c - 'A') < 26) c = c - 19;
        else switch (c) {
        case ' ': c = 1; break;
        case '!': c = 72; break;
        case '"': c = 97; break;
        case '%': c = 74; break;
        case '\'': c = 87; break;
        case '*': c = 45; break;
        case '+': c = 43; break;
        case '-': c = 44; break;
        case '.': c = 79; break;
        case '/': c = 75; break;
        case ':': c = 82; break;
        case '?': c = 73; break;
        default: c = 127; break;
        }
        buf[i] = c;
    }
    buf[n] = 0;
    return buf;
}

// --------------------
extern f32 D_00349e10;
struct T197028 { u8 pad[48]; s32 state; s32 wait; f32 fwait; };
s32 func_002ee530(T197028*);
void func_00197148(T197028*);
void func_00197280(T197028*);
void func_00197318_x8314(T197028*) asm("func_00197318");
void func_00197390(T197028*);
void func_001973f0(T197028*);
void func_00197430_x8317(T197028*) asm("func_00197430");
void func_00197568(T197028*);
void func_001975a0(T197028*);
s32 func_00197028(T197028* p) {
    if (func_002ee530(p)) return 1;
    for (;;) {
        if (p->wait > 0) {
            p->wait--;
            return 1;
        }
        if (p->fwait > 0.0f) {
            p->fwait -= D_00349e10;
            return 1;
        }
        switch (p->state) {
        case 0: func_00197148(p); break;
        case 1: func_00197280(p); break;
        case 2: func_00197318_x8314(p); break;
        case 3: func_00197390(p); break;
        case 5: func_001973f0(p); break;
        case 6: func_00197430_x8317(p); break;
        case 7: func_00197568(p); break;
        case 9: func_001975a0(p); return 0;
        default: return 1;
        }
    }
}

// --------------------
extern s32 D_00350438;
void func_001993a0(s32, s32);
void func_00105de0(s32);
void func_002430b0(s32);
s32 func_0016b7a0(s32);
void func_00196b28(s32, s32);
void func_0016bb38(s32, s32);
s32 func_00198cb8(s32, s32);
s32 func_001991a8(s32 n, s32 a) {
    s32 r = 1;
    func_001993a0(n, a);
    switch (n) {
    case 19:
    case 102: case 103: case 104: case 105: case 106: case 107: case 108: case 109:
    case 110: case 111: case 112: case 113: case 114: case 115: case 116: case 117:
    case 131: case 132: case 133: case 138:
        func_00105de0(n);
        break;
    case 22: case 70: case 79: case 87: case 88: case 89: case 98: case 100: case 101:
    case 118: case 129:
        func_002430b0(n);
        break;
    default:
        if ((n == 8 || n == 130) && a != 0) D_00350438 = func_0016b7a0(a);
        func_00196b28(n, a);
        func_0016bb38(n, a);
        r = func_00198cb8(n, a);
        break;
    }
    return r;
}

// --------------------
struct S19ef90 { u8 a; u8 b; u8 c; u8 pad; s16 x; s16 y; s16 z; };
struct T19ef90 { s32 type; S19ef90 s; s32 w; };
union U19ef90 { s16 h; u16 uh; s32 i; };
S19ef90 func_00199718(s32, s32);
void func_0019ef90(T19ef90* d, u8* s) {
    d->type = ((U19ef90*)s)->h;
    d->w = ((U19ef90*)(s + 10))->h;
    switch (((U19ef90*)s)->uh) {
    case 4:
        d->s.a = s[2];
        break;
    case 1:
        d->s.a = s[2];
        d->s.b = s[4];
        d->s.c = s[6];
        d->s.z = -1;
        d->s.y = -1;
        d->s.x = -1;
        break;
    case 2:
        d->s = func_00199718(*(s16*)(s + 8), *(s16*)(s + 2));
        d->s.c = s[6];
        break;
    case 0: case 6:
        break;
    }
}

// --------------------
extern u64 D_0032f050;
extern u8 D_0032bb30[];
extern u32 D_0034f240;
void func_001c9770();
void func_001adbc0();
s32 func_001a1658_x8414(s32, s32) asm("func_001a1658");
void func_001adb80(s32, s32);
void func_001a17c8_x8416(s32) asm("func_001a17c8");
void func_001ada38(s32 n) {
    s32 i;
    if (n == 0) return;
    switch (n) {
    case 1:
        if (!(D_0032f050 & 0xffff00000000ULL)) break;
    case 2: case 12:
        func_001c9770();
    case 10:
        func_001adbc0();
        break;
    case 5:
        D_0034f240 |= 0x40000;
    case 4:
        if (!(D_0032f050 & 0xffff00000000ULL)) return;
    case 6:
        func_001c9770();
        func_001adbc0();
        return;
    case 11:
        if (D_0032bb30[13604] == 6) {
            D_0032bb30[13604] = 0;
            func_001c9770();
        }
        return;
    }
    for (i = 1; i < 16; i++) {
        s32 o = func_001a1658_x8414(i, -1);
        func_001adb80(n, o);
        func_001a17c8_x8416(o);
    }
}

// --------------------
struct C1b8520 { u16 type; u16 pad; union { f32 f; s32 i; } v; };
struct X1b8520 { u8 pad[12]; s32 (*fn)(C1b8520*, X1b8520*); s32 id; };
void func_00102470_x8453(f32, s32) asm("func_00102470");
s32 func_001991a8(s32, s32);
s32 func_0014aba8_x8455() asm("func_0014aba8");
void func_0014aa58_x8456(s32, s32, s32) asm("func_0014aa58");
void func_0014aa80_x8457(s32, s32, s32) asm("func_0014aa80");
s32 func_001b8520(C1b8520* c, X1b8520* x) {
    s32 t;
    switch (c->type) {
    case 2:
        func_00102470_x8453(c->v.f, x->id);
        return 1;
    case 3:
        func_001991a8(c->v.i, 0);
        return 1;
    case 4:
        return 0;
    case 5:
        t = (s32)(c->v.f * 0.5f);
        func_0014aa58_x8456(func_0014aba8_x8455(), t, 0);
        return 1;
    case 6:
        t = (s32)(c->v.f * 0.5f);
        func_0014aa80_x8457(func_0014aba8_x8455(), t, 0);
        return 1;
    case 7:
        t = (s32)(c->v.f * 0.5f);
        func_0014aa58_x8456(func_0014aba8_x8455(), t, 1);
        return 1;
    case 8:
        t = (s32)(c->v.f * 0.5f);
        func_0014aa80_x8457(func_0014aba8_x8455(), t, 1);
        return 1;
    default:
        return x->fn(c, x);
    }
}

// --------------------
struct C1bb2c8 { u16 type; u16 pad; union { f32 f; s32 i; } a; s32 b; s32 c; u16 n; };
extern u8* D_0034e948;
void func_001d5470_x8493(u8*, s32, C1bb2c8*) asm("func_001d5470");
void func_001d8248(u8*, C1bb2c8*);
void func_001d8550(u8*, C1bb2c8*);
void func_001d8b68(u8*, C1bb2c8*);
void func_001d9028(u8*, C1bb2c8*);
void func_001d93f0(u8*, C1bb2c8*);
void func_001d5370_x8499(u8*, s32, s32) asm("func_001d5370");
void func_001d4dc0(u8*, s32, s32, s32);
void func_0019ba60_x8501(u8*) asm("func_0019ba60");
void func_001a1aa0(u8*, s32);
s32 func_001bb2c8(C1bb2c8* c, u8* x) {
    switch (c->type) {
    case 1:
        func_001d5470_x8493(x + 76, *(s32*)(x + 72), c);
        break;
    case 2:
        func_001d5470_x8493(x + 104, *(s32*)(x + 72), c);
        break;
    case 3:
        func_001d5470_x8493(x + 160, *(s32*)(x + 72), c);
        break;
    case 4:
        func_001d8248(x, c);
        break;
    case 5:
        func_001d8550(x, c);
        break;
    case 6:
        func_001d8b68(x, c);
        break;
    case 7:
        func_001d9028(x, c);
        break;
    case 8: {
        u8* q = x + 740;
        func_001d5370_x8499(x + 744, *(s32*)(x + 72), c->n - 1);
        func_001d4dc0(q, c->a.i, c->b, c->c);
        break;
    }
    case 9:
        func_001d93f0(x, c);
        break;
    case 10:
        *(s32*)(x + 1324) = c->a.i;
        break;
    case 11:
        *(f32*)(x + 1328) = c->a.f;
        break;
    case 12: {
        u8* o = D_0034e948;
        func_0019ba60_x8501(o);
        if ((*(u8**)(o + 1164))[431] == 1) func_001a1aa0(*(u8**)(o + 1164), c->a.i);
        break;
    }
    case 13:
        func_001d5470_x8493(x + 132, *(s32*)(x + 72), c);
        break;
    }
    return 1;
}

// --------------------
struct V1cd078 { f32 x, y, z, w; };
extern s32 D_003520c0;
s32 func_0018ca48_x8557(s32) asm("func_0018ca48");
s32 func_001d87b8(s32);
void func_001d86a0_x8559(s32, s32) asm("func_001d86a0");
void func_0016be98(V1cd078*, u8*);
void func_001ccf18(V1cd078*, s32, s32);
void func_001cd078(u8* p) {
    V1cd078 v;
    s32 n, a, b;
    if (D_003520c0 == 0) return;
    n = 0;
    if (*(u32*)(*(u8**)(p + 20) + 1416) & 0x80) {
        a = 0;
        b = 0;
    } else {
        a = 1;
        b = 2;
    }
    switch (func_0018ca48_x8557(p[38])) {
    case 0: case 2: case 3:
        n = 3;
        break;
    case 4: case 5: case 14:
        n = 15;
        break;
    }
    if (func_001d87b8(a) < n) n = func_001d87b8(a);
    if (n <= 0) return;
    func_001d86a0_x8559(-n, a);
    func_0016be98(&v, *(u8**)(p + 20));
    func_001ccf18(&v, b, n);
}

// --------------------
extern f32 D_00349e10;
s32 func_0019ba60(u8*);
void func_001e1ce0(u8*);
void func_001e1d20(u8*);
void func_001e1df0(u8*);
void func_001e1df8(u8*);
void func_001e1e40(u8*);
void func_001e2130(u8*);
void func_001e21f0(u8*);
void func_001e21f8(u8*);
void func_001e2238(u8*);
void func_001e2620(u8*);
void func_001e2640(u8*);
void func_001e2298(u8* p) {
    if (!func_0019ba60(*(u8**)(p + 3536))) *(s32*)(p + 3520) = 7;
    switch (*(u32*)(p + 3520)) {
    case 0: func_001e1ce0(p); break;
    case 1: func_001e1d20(p); break;
    case 2: func_001e1df0(p); break;
    case 3: func_001e1df8(p); break;
    case 4: func_001e1e40(p); break;
    case 5: func_001e2130(p); break;
    case 6: func_001e21f0(p); break;
    case 7: func_001e21f8(p); break;
    }
    func_001e2238(p);
    func_001e2620(p);
    func_001e2640(p);
    *(f32*)(p + 3556) += D_00349e10;
    *(f32*)(p + 3560) += D_00349e10;
}

// --------------------
extern u8 D_01d9e840[];
extern u8* D_01d9e6e8;
void func_002f4000_x8625(void*, u8*, u8*) asm("func_002f4000");
void func_002f3d08_x8626(void*, u8*, u8*) asm("func_002f3d08");
void func_00208978(void* a, u8* b, u8* c) {
    s32 n = *(s32*)(c + 20);
    func_002f4000_x8625(a, b, c);
    switch (b[38]) {
    case 0: case 2: case 4: case 6: case 8:
    default:
        if (n == 0) func_002f3d08_x8626(a, D_01d9e840, D_01d9e6e8 + 16);
        break;
    case 1: case 3: case 5: case 7: case 9:
        func_002f3d08_x8626(a, D_01d9e840, D_01d9e6e8 + 16);
        break;
    }
}

// --------------------
struct C22cc38 { u8 pad[4]; s16 id; s16 v; u16 type; };
s32 func_002282f0_x8643(s32) asm("func_002282f0");
s32 func_0014ac08();
s32 func_0014abd8_x8645() asm("func_0014abd8");
s32 func_0014aba8_x8646() asm("func_0014aba8");
void func_0014aa58_x8647(s32, s32, s32) asm("func_0014aa58");
void func_0014aa80_x8648(s32, s32, s32) asm("func_0014aa80");
void func_0022cc38(C22cc38* c) {
    if (func_002282f0_x8643(c->id)) return;
    switch (c->type) {
    case 0: func_0014aa80_x8648(func_0014ac08(), c->v, 0); break;
    case 1: func_0014aa58_x8647(func_0014ac08(), c->v, 0); break;
    case 2: func_0014aa58_x8647(func_0014ac08(), c->v, 1); break;
    case 3: func_0014aa80_x8648(func_0014abd8_x8645(), c->v, 0); break;
    case 4: func_0014aa58_x8647(func_0014abd8_x8645(), c->v, 0); break;
    case 5: func_0014aa80_x8648(func_0014ac08(), c->v, 1); break;
    case 6: func_0014aa58_x8647(func_0014aba8_x8646(), c->v, 1); break;
    case 7: func_0014aa80_x8648(func_0014aba8_x8646(), c->v, 1); break;
    }
}

// --------------------
extern u8 D_0035ed0c;
s32 func_00287cd0();
s32 func_00289380_x8667(s32) asm("func_00289380");
s32 func_00289310_x8668(s32) asm("func_00289310");
s32 func_0028ae28_x8669(s32, s32) asm("func_0028ae28");
void func_00243e30();
void func_00287c90(s32);
void func_00244c30();
void func_00287df0_x8673(s32, s32, s32, s32, s32) asm("func_00287df0");
void func_00244988();
void func_002535b0(s32);
void func_00288658(s32, s32);
void func_00243f48();
void func_00288670(void (*)());
void func_00287da0();
void func_00243cd8();
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
void func_00244148() {
    s32 a = func_00287cd0();
    s32 r = func_00289380_x8667(D_0035ece8);
    if (D_0035ed0c) return;
    if (r != -1 || func_00289310_x8668(D_0035ece8)) {
        if (!func_0028ae28_x8669(D_0035ece8, 0)) func_00243e30();
    }
    if (!a && func_0028ae28_x8669(D_0035ece8, 0)) {
        func_00287c90(1);
        func_00244c30();
    }
    func_00287df0_x8673(r, func_00289310_x8668(D_0035ece8), 1, 0, 1);
    switch (r) {
    case -6:
        func_00244988();
        func_002535b0(3);
        func_00288658(2, 100);
        func_00288670(func_00243f48);
    case -4: case -2:
        func_00287da0();
        break;
    case 0: case 1:
        func_00243cd8();
        func_00287bd0(1, 0);
        func_00287cc0(0);
        break;
    }
}

// --------------------
extern u32 D_0035ed4c;
extern u8 D_0035ed68;
s32 func_00287cd0();
s32 func_00289380_x8715(s32) asm("func_00289380");
s32 func_00289310_x8716(s32) asm("func_00289310");
s32 func_0028ae28_x8717(s32, s32) asm("func_0028ae28");
void func_00248720();
void func_00287c90(s32);
void func_002491d0();
void func_00249480();
s32 func_00287df0_b(s32, s32, s32, void (*)(), s32) asm("func_00287df0");
void func_00287da0();
s32 func_002427d8(s32);
void func_002485c8();
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
void func_002489d8() {
    s32 a = func_00287cd0();
    s32 r = func_00289380_x8715(D_0035ed4c);
    if (D_0035ed68) return;
    if (r != -1 || func_00289310_x8716(D_0035ed4c)) {
        if (!func_0028ae28_x8717(D_0035ed4c, 0)) func_00248720();
    }
    if (!a && func_0028ae28_x8717(D_0035ed4c, 0)) {
        func_00287c90(1);
        func_002491d0();
    }
    s32 k = func_00287df0_b(r, func_00289310_x8716(D_0035ed4c), 1, func_00249480, 1);
    switch (r) {
    case -3: case -1:
        break;
    case -4: case -2:
        func_00287da0();
        break;
    case 0: case 1: case 2: case 3: case 4:
        if (func_002427d8(k)) {
            func_002485c8();
            func_00287bd0(1, 0);
            func_00287cc0(0);
        }
        break;
    }
}

// --------------------
extern u8 D_0035edc4;
s32 func_00287cd0();
s32 func_00289380_x8759(s32) asm("func_00289380");
s32 func_00289310_x8760(s32) asm("func_00289310");
s32 func_0028ae28_x8761(s32, s32) asm("func_0028ae28");
void func_002426a0(s32);
void func_0024bbb0();
void func_0024ba58();
void func_00287c90(s32);
void func_0024c6a0();
void func_00287df0_x8767(s32, s32, s32, s32, s32) asm("func_00287df0");
void func_00244988();
void func_002535b0(s32);
void func_00288658(s32, s32);
void func_00243f48();
void func_00288670(void (*)());
void func_00287da0();
void func_00243cd8();
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
void func_0024be68() {
    s32 a = func_00287cd0();
    s32 r = func_00289380_x8759(D_0035eda8);
    if (D_0035edc4) return;
    if (r != -1 || func_00289310_x8760(D_0035eda8)) {
        if (!func_0028ae28_x8761(D_0035eda8, 0)) {
            func_002426a0(0);
            func_0024bbb0();
        }
    }
    if (!a && func_0028ae28_x8761(D_0035eda8, 0)) {
        func_00287c90(1);
        func_0024c6a0();
    }
    func_00287df0_x8767(r, func_00289310_x8760(D_0035eda8), 1, 0, 1);
    switch (r) {
    case -3: case -1:
        break;
    case -4: case -2:
        func_00287da0();
        break;
    case 0: case 1: case 2:
        func_0024ba58();
        func_00287bd0(1, 0);
        func_00287cc0(0);
        break;
    }
}

// --------------------
extern u8 D_0035edf0;
s32 func_00287cd0();
s32 func_00289380_x8809(s32) asm("func_00289380");
s32 func_00289310_x8810(s32) asm("func_00289310");
s32 func_0028ae28_x8811(s32, s32) asm("func_0028ae28");
void func_0024d4a0();
void func_00287c90(s32);
void func_0024e3a8();
void func_00287df0_x8815(s32, s32, s32, s32, s32) asm("func_00287df0");
void func_0024df58();
void func_002535b0(s32);
void func_00288658(s32, s32);
void func_0024d5a8();
void func_00288670(void (*)());
void func_00287da0();
void func_0024d348();
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
void func_0024d7a0() {
    s32 a = func_00287cd0();
    s32 r = func_00289380_x8809(D_0035edcc);
    if (D_0035edf0) return;
    if (r != -1 || func_00289310_x8810(D_0035edcc)) {
        if (!func_0028ae28_x8811(D_0035edcc, 0)) func_0024d4a0();
    }
    if (!a && func_0028ae28_x8811(D_0035edcc, 0)) {
        func_00287c90(1);
        func_0024e3a8();
    }
    func_00287df0_x8815(r, func_00289310_x8810(D_0035edcc), 1, 0, 1);
    switch (r) {
    case -6:
        func_0024df58();
        func_002535b0(3);
        func_00288658(2, 106);
        func_00288670(func_0024d5a8);
    case -4: case -2:
        func_00287da0();
        break;
    case -5: case -3: case -1:
        break;
    case 0: case 1: case 2:
        func_0024d348();
        func_00287bd0(1, 0);
        func_00287cc0(0);
        break;
    }
}

// --------------------
extern u8 D_0035ee50;
s32 func_00287cd0();
s32 func_00289380_x8859(s32) asm("func_00289380");
s32 func_00289310_x8860(s32) asm("func_00289310");
s32 func_0028ae28_x8861(s32, s32) asm("func_0028ae28");
void func_002426a0(s32);
void func_0024fd28();
void func_0024fbd0();
void func_00287c90(s32);
void func_002507a0();
void func_00287df0_x8867(s32, s32, s32, s32, s32) asm("func_00287df0");
void func_00244988();
void func_002535b0(s32);
void func_00288658(s32, s32);
void func_00243f48();
void func_00288670(void (*)());
void func_00287da0();
void func_00243cd8();
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
void func_0024ffe0() {
    s32 a = func_00287cd0();
    s32 r = func_00289380_x8859(D_0035ee34);
    if (D_0035ee50) return;
    if (r != -1 || func_00289310_x8860(D_0035ee34)) {
        if (!func_0028ae28_x8861(D_0035ee34, 0)) {
            func_002426a0(0);
            func_0024fd28();
        }
    }
    if (!a && func_0028ae28_x8861(D_0035ee34, 0)) {
        func_00287c90(1);
        func_002507a0();
    }
    func_00287df0_x8867(r, func_00289310_x8860(D_0035ee34), 1, 0, 1);
    switch (r) {
    case -3: case -1:
        break;
    case -4: case -2:
        func_00287da0();
        break;
    case 0: case 1: case 2: case 3: case 4:
        func_0024fbd0();
        func_00287bd0(1, 0);
        func_00287cc0(0);
        break;
    }
}

// --------------------
struct T266c90 { u8 pad[28]; u16 flags; s8 b30; u8 b31; };
union U266c90 { T266c90* p; u32 i; u16 h; u8 b; };
extern U266c90 D_0035f0e4;
extern s32 D_0035f010_x8910 asm("D_0035f010");
s32 func_00281100_x8911(s32) asm("func_00281100");
s32 func_00281340(s32);
s8 func_00266c00();
void func_00266c90() {
    s32 i, n;
    D_0035f0e4.p->flags = 0;
    D_0035f0e4.p->b31 = 0;
    n = func_00281100_x8911(D_0035f010_x8910);
    if (n) D_0035f0e4.p->flags |= 1;
    for (i = 1; i < n; i++) D_0035f0e4.p->flags |= 1 << (i + 6);
    for (i = 0; i < 7; i++) {
        if (i == 0 || i == 6) continue;
        if (!func_00281340(i)) continue;
        n = -1;
        switch (i) {
        case 1: n = 1; break;
        case 2: n = 2; break;
        case 3: n = 3; break;
        case 4: n = 4; break;
        case 5: n = 5; break;
        }
        D_0035f0e4.p->flags |= 1 << n;
        D_0035f0e4.p->b31 |= 1 << i;
    }
    D_0035f0e4.p->b30 = func_00266c00();
    if (D_0035f0e4.p->b30) D_0035f0e4.p->flags |= 0x40;
}

// --------------------
extern s32 D_0035f010_x8940 asm("D_0035f010");
u16* func_0026b850(s32);
s32 func_002670a0_x8942(s32) asm("func_002670a0");
s32 func_00281158(s32, s32);
s32 func_00267408(s32 a) {
    u16* t = func_0026b850(a);
    s32 n = func_002670a0_x8942(a);
    s32 r = 0;
    switch (n) {
    case 0: r = func_00281158(D_0035f010_x8940, 0); break;
    case 1: r = t[1]; break;
    case 2: r = t[2]; break;
    case 3: r = t[3]; break;
    case 4: r = t[4]; break;
    case 5: r = t[5]; break;
    case 6: r = 0xc5b1; break;
    case 7: case 8: case 9: r = func_00281158(D_0035f010_x8940, n - 6); break;
    }
    return r;
}

// --------------------
s32 func_00289380_x8962(s32) asm("func_00289380");
s32 func_00287cd0();
void func_00287bc0_x8964() asm("func_00287bc0");
s32 func_002576d0();
void func_002575a8();
void func_00287c30();
void func_00287cc0(s32);
s32 func_00289310_x8969(s32) asm("func_00289310");
s32 func_00257610(s32);
void func_00257670(s32);
void func_00287c90(s32);
s32 func_00287df0(s32, s32, s32, s32, s32);
s32 func_00242848(s32);
void func_0026b0f8();
void func_00269658();
void func_00257530(s32);
void func_00287c00(s32);
void func_00281d48();
void func_00281e20();
void func_002691f8() {
    s32 r = func_00289380_x8962(D_0035f024);
    s32 a = func_00287cd0();
    func_00287bc0_x8964();
    if (a == 2) {
        if (!func_002576d0()) {
            func_002575a8();
            func_00287c30();
            func_00287cc0(1);
        }
        return;
    }
    if (r != -1 || func_00289310_x8969(D_0035f024)) {
        if (!func_00257610(0)) func_00257670(0);
    }
    if (!a && func_00257610(0)) func_00287c90(1);
    if (!func_00242848(func_00287df0(r, func_00289310_x8969(D_0035f024), 0, 0, 1))) {
        switch (r) {
        case 1:
            func_0026b0f8();
            func_00269658();
        case -2: case 0:
            func_00257530(0);
            func_00287cc0(2);
            func_00287c00(2);
            break;
        case -4: case -3: case -1:
            break;
        }
    }
    func_00281d48();
    func_00281e20();
}

// --------------------
struct E273530 { u8 pad[2]; s8 a; s8 b; u8 pad2[4]; };
extern E273530* D_0035f12c;
s32 func_002570a0(s32);
s32 func_00272b60(s32);
s32 func_0028b040_x9020(s32) asm("func_0028b040");
void func_00273678();
void func_002736f8();
void func_00273818();
void func_00273c40(s32);
void func_00273cb8(s32);
void func_00270c70(s32);
void func_00273530() {
    s32 i = func_002570a0(26);
    s32 m = func_00272b60(i);
    s32 cur = func_0028b040_x9020(D_0035f01c);
    s32 k;
    switch (m) {
    case 0:
        func_00273678();
        break;
    case 1:
        k = D_0035f12c[i + 1].a != 0;
        if (k != cur) func_002736f8();
        break;
    case 2:
        if (func_002570a0(25)) i = i - 1;
        k = D_0035f12c[i + 1].a != 0;
        if (func_002570a0(25) && D_0035f12c[i + 1].b == 2) k += 2;
        if (k != cur) func_00273818();
        break;
    case 3:
        func_00273c40(cur);
        break;
    case 4:
        func_00273cb8(cur);
        break;
    }
    func_00270c70(func_002570a0(25));
}

// --------------------
u8* func_00281180_x9057(s32) asm("func_00281180");
s32 func_00281480(s32, s32);
s32 func_002813b8();
s32 func_00281420_x9060() asm("func_00281420");
s32 func_002826f8(u8* p, s32 a, s32 k) {
    s32 r = 0;
    u8* t = *(u8**)(func_00281180_x9057(*(s32*)(p + 4100)) + 580);
    switch (k) {
    case 0:
        r = 1;
        break;
    case 1:
        if (func_00281480(*(s32*)(p + 4100), a)) {
            s32 m = func_002813b8();
            m &= func_00281420_x9060();
            s32 i;
            for (i = 0; i < 7; i++) r += (m >> i) & 1;
        }
        break;
    case 2: r = t[16]; break;
    case 3: r = t[17]; break;
    case 4: r = t[18]; break;
    }
    return r;
}

// --------------------
extern s32 D_0035f200_x9084 asm("D_0035f200");
extern u8 D_00374ad8[];
extern s8 D_0035f5c4;
void func_00288e88(s32);
s32 func_00287bc0();
void func_0028f4a0(void*);
void func_0029ae30();
void func_0029af20();
void func_0029e950(s32);
void func_002765e8(s32, s32, s32);
void func_0029b698();
void func_0029be08();
void func_0029ae40() {
    func_00288e88(D_0035f200_x9084);
    s32 n = func_00287bc0();
    func_0028f4a0(D_00374ad8);
    func_0029ae30();
    switch (n) {
    case 14:
        func_0029af20();
        break;
    case 15: case 18: case 21:
        if (n == 18) func_0029e950(17);
        else if (n == 21) func_0029e950(18);
        func_002765e8(15, 0, 0);
        func_0029b698();
        break;
    case 16: case 19: case 22:
        D_0035f5c4 = -1;
        func_0029be08();
        break;
    }
}

// --------------------
struct T29ecf0 { u8 pad[8]; s16 idx[1]; };
extern T29ecf0* D_0035f5ac;
s32 func_00287bc0();
u8* func_00294000_x9122(s32) asm("func_00294000");
s32 func_0029c9d8(s32);
s32 func_002954e0(s32);
s32 func_002943b0(u8*);
s32 func_0029ecf0(s32 a) {
    s32 n = func_00287bc0();
    u8* base = func_00294000_x9122(3) + 16;
    switch (n) {
    case 14:
        if (a < 0) return 1;
        return func_002954e0(func_0029c9d8(a)) != 0;
    case 15: case 18: case 21:
        if (a < 0) return 1;
        return func_002943b0(base + D_0035f5ac->idx[a] * 36) != 0;
    case 16: case 19: case 22:
        return 1;
    }
    return 0;
}

// --------------------
struct E2b3b78 { s32 flags; u8 pad[32]; };
extern E2b3b78* D_0035f630;
s32 func_00287bc0();
s32 func_002b3b78(s32 a) {
    s32 r = 0;
    if (a < 0) return 1;
    switch (func_00287bc0()) {
    case 28: {
        E2b3b78* e = D_0035f630;
        s32 j = 0;
        s32 i;
        for (i = 0; i < 10; i++, e++) {
            if (e->flags & 0x1000000) {
                if (j == a) {
                    r = (e->flags >> 25) & 1;
                    break;
                }
                j++;
            }
        }
        break;
    }
    case 27: case 30:
        r = 1;
        break;
    case 29: case 31: case 32: case 33:
        r = 0;
        break;
    }
    return r;
}

// --------------------
union unaligned3 {
    void* ptr;
    u16 u2;
    u32 u4;
    u64 u8;
    s16 s2;
    s32 s4;
    s64 s8;
} __attribute__((__packed__));
const u8* func_00316f38(const u8* p, u64* val);
const u8* func_00316f70(const u8* p, s64* val);
void func_002fd160(void) __attribute__((noreturn));

const u8* func_00316fc8(u8 encoding, u32 base, const u8* p, u32* val) {
    const union unaligned3* u = (const union unaligned3*)p;
    u32 result;

    if (encoding == 0x50) {
        u32 a = (u32)p;
        a = (a + 3) & -4;
        result = *(u32*)a;
        p = (const u8*)(a + 4);
    } else {
        switch (encoding & 0x0f) {
        case 0x00:
            result = (u32)u->ptr;
            p += 4;
            break;
        case 0x01: {
            u64 tmp;
            p = func_00316f38(p, &tmp);
            result = (u32)tmp;
        } break;
        case 0x09: {
            s64 tmp;
            p = func_00316f70(p, &tmp);
            result = (u32)tmp;
        } break;
        case 0x02: result = u->u2; p += 2; break;
        case 0x03: result = u->u4; p += 4; break;
        case 0x04: result = u->u8; p += 8; break;
        case 0x0a: result = u->s2; p += 2; break;
        case 0x0b: result = u->s4; p += 4; break;
        case 0x0c: result = u->s8; p += 8; break;
        default: func_002fd160();
        }
        if (result != 0) {
            result += ((encoding & 0x70) == 0x10 ? (u32)u : base);
            if (encoding & 0x80)
                result = *(u32*)result;
        }
    }
    *val = result;
    return p;
}

// --------------------
void* func_001050d8_x9233(u32) asm("func_001050d8");
void* func_001c4520(u8*);
void* func_001c51d8(u8*);
void* func_001ce488(u8*);
void* func_001d6578(u8*);
void func_001c7bc8(void*, u8*);
void func_001cc048(void*, u8*);
void func_001ca678(void*, u8*);
void func_001cce38(void*, u8*);
void func_001cbb58(void*, u8*);
void func_001d2850(void*, u8*);
void func_001d7458(void*, u8*);
void func_001da1d8(void*, u8*);
void* func_001c25e8(u8* d) {

    switch (d[5]) {
    case 2: return func_001c4520(d);
    case 3: return func_001c51d8(d);
    case 4: { void* p = func_001050d8_x9233(2560); func_001c7bc8(p, d); return p; }
    case 6: { void* p = func_001050d8_x9233(2560); func_001cc048(p, d); return p; }
    case 7: { void* p = func_001050d8_x9233(2560); func_001ca678(p, d); return p; }
    case 8: { void* p = func_001050d8_x9233(2560); func_001cce38(p, d); return p; }
    case 9: { void* p = func_001050d8_x9233(2560); func_001cbb58(p, d); return p; }
    case 12: { void* p = func_001050d8_x9233(2560); func_001d2850(p, d); return p; }
    case 13: { void* p = func_001050d8_x9233(2560); func_001d7458(p, d); return p; }
    case 10: case 11: case 14: return func_001ce488(d);
    case 15: return func_001d6578(d);
    case 16: { void* p = func_001050d8_x9233(2560); func_001da1d8(p, d); return p; }
    }
    return 0;
}

// --------------------
typedef unsigned int Q1d3148 __attribute__((mode(TI)));
struct V1d3148 {
    union { Q1d3148 q; f32 f[4]; };
    V1d3148& operator=(const V1d3148& o) {
        // 128-bit lq/sq copy: hand-written asm in the original
        if (this != &o) asm volatile("lq $8,0(%1)\n\tsq $8,0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
};
struct M1d3148 {
    Q1d3148 r[3];
    V1d3148 t;
    M1d3148& operator=(const M1d3148& o) {
        // 128-bit lq/sq matrix copy: hand-written asm in the original
        if (this != &o) {
            asm volatile("lq $8,0(%1)\n\tlq $9,16(%1)\n\tlq $10,32(%1)\n\tlq $11,48(%1)\n\tsq $8,0(%0)\n\tsq $9,16(%0)\n\tsq $10,32(%0)\n\tsq $11,48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        }
        return *this;
    }
};
struct O1d3148 { s32 state; u8* obj; u8 pad[8]; M1d3148 m; };
extern u8* D_00350cc8;
extern u8* D_00350ccc;
s32 func_0019ba60(u8*);
V1d3148* func_0016c028_x9291(u8*) asm("func_0016c028");
s32 func_001dc9e0(u8*);
V1d3148* func_001dc5f8_x9293(u8*) asm("func_001dc5f8");
void func_001d3148(O1d3148* o) {
    switch (o->state) {
    case 2:
        if (func_0019ba60(o->obj)) o->m = *(M1d3148*)(o->obj + 1712);
        o->state = 0;
        break;
    case 3:
        if (func_0019ba60(o->obj)) o->m = *(M1d3148*)(o->obj + 64);
        o->state = 7;
    case 7:
        if (!func_0019ba60(o->obj)) {
            o->state = 0;
            break;
        }
        (o->m.t = *func_0016c028_x9291(o->obj)).f[3] = 1.0f;
        break;
    case 4:
        if (func_0019ba60(D_00350cc8)) o->m = *(M1d3148*)(D_00350cc8 + 64);
        o->state = 8;
    case 8:
        if (!D_00350ccc || !func_001dc9e0(D_00350ccc)) {
            o->state = 0;
            break;
        }
        (o->m.t = *func_001dc5f8_x9293(D_00350ccc)).f[3] = 1.0f;
        break;
    }
}

// --------------------
struct S227e30 { u8* base; s32 pad; s32 ofs; };
struct C227e30 { u16 size; s16 type; };
extern S227e30 D_0035db50[];
extern s32 D_0035dd04;
extern s32 D_0035db18;
extern u8 D_0035de24;
extern u8 D_0035de55;
void func_00226090();
void func_00170888(void*);
void func_00224d48();
void func_00102448_x9334(void*, s32) asm("func_00102448");
void func_0022f528(C227e30*, void*);
void func_0022d3b8(C227e30*);
void func_0022d358(void*);
void func_0022d3a8(C227e30*, void*);
void func_00231928(C227e30*);
void func_00230838_x9340(C227e30*) asm("func_00230838");
void func_00230878_x9341(C227e30*) asm("func_00230878");
void func_00232398(C227e30*);
void func_00226050(C227e30*);
void func_00232a48(C227e30*, void*);
void func_00225328(C227e30*, void*);
void func_00225788(C227e30*, void*);
void func_00224b60(C227e30*, void*);
void func_0022ba08(C227e30*, void*);
void func_00232110(C227e30*, void*);
void func_00232100(C227e30*, void*);
void func_0022c9f0(C227e30*);
void func_00227e30(void* th) {
    s32 cnt = 0;
    for (;;) {
        s32 i;
        for (i = 0; i < 1; i++) {
            if (!D_0035db50[i].base) continue;
            C227e30* c = (C227e30*)(D_0035db50[i].base + D_0035db50[i].ofs);
            u32 size = c->size;
            cnt++;
            if (size == 0) {
                D_0035dd04 = 0;
                if (D_0035db18) {
                    func_00226090();
                    func_00170888(th);
                }
                func_00224d48();
                D_0035de24 = 1;
                for (;;) func_00102448_x9334(th, 0);
            }
            switch (c->type + 0) {
            case 1: func_0022f528(c, th); break;
            case 8: func_0022d3b8(c); break;
            case 15: func_0022d358(th); break;
            case 16: func_0022d3a8(c, th); break;
            case 19: func_00231928(c); D_0035de55 = 1; break;
            case 29: func_00230838_x9340(c); break;
            case 30: func_00230878_x9341(c); break;
            case 35: func_00232398(c); break;
            case 36: func_00226050(c); break;
            case 42: func_00232a48(c, th); break;
            case 46: func_00225328(c, th); break;
            case 47: func_00225788(c, th); break;
            case 50: func_00224b60(c, th); break;
            case 68: func_0022ba08(c, th); break;
            case 70: func_00232110(c, th); break;
            case 76: func_00232100(c, th); break;
            case 78: func_0022c9f0(c); break;
            }
            D_0035db50[i].ofs += size;
        }
        if (cnt == 0) func_00102448_x9334(th, 0);
        cnt = 0;
    }
}

// --------------------
extern u32 D_0035ed20;
extern u8 D_0035ed3c;
s32 func_00287cd0();
s32 func_00289380_x9401(s32) asm("func_00289380");
s32 func_00289310_x9402(s32) asm("func_00289310");
s32 func_0028ae28_x9403(s32, s32) asm("func_0028ae28");
void func_00245be8();
void func_00287c90(s32);
void func_00247a20();
void func_00287df0_x9407(s32, s32, s32, s32, s32) asm("func_00287df0");
s32 func_00247870(s32);
void func_00242618(s32, s32);
void func_00247580(s32);
void func_002467b8();
void func_002535b0(s32);
void func_00288658(s32, s32);
void func_00245ce8();
void func_00288670(void (*)());
void func_00287da0();
void func_00245a90();
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
void func_00245eb8() {
    s32 a = func_00287cd0();
    s32 r = func_00289380_x9401(D_0035ed20);
    if (D_0035ed3c) return;
    if (r != -1 || func_00289310_x9402(D_0035ed20)) {
        if (!func_0028ae28_x9403(D_0035ed20, 0)) func_00245be8();
    }
    if (!a && func_0028ae28_x9403(D_0035ed20, 0)) {
        func_00287c90(1);
        func_00247a20();
    }
    if (r != -13 && r != -12) func_00287df0_x9407(r, func_00289310_x9402(D_0035ed20), 1, 0, 1);
    switch (r) {
    case -6:
        func_002467b8();
        func_002535b0(3);
        func_00288658(2, 101);
        func_00288670(func_00245ce8);
    case -4: case -2:
        func_00287da0();
        break;
    case -13: case -12:
        if (func_00247870(r == -12)) {
            func_00242618(7, 1);
            func_00247580(0);
        }
        break;
    case -11: case -10: case -9: case -8: case -7: case -5: case -3: case -1:
        break;
    case 0: case 1: case 2: case 3:
        func_00245a90();
        func_00287bd0(1, 0);
        func_00287cc0(0);
        break;
    }
}

// --------------------
extern u8 D_0035ed94;
s32 func_00287cd0();
s32 func_00289380_x9460(s32) asm("func_00289380");
s32 func_00289310_x9461(s32) asm("func_00289310");
s32 func_0028ae28_x9462(s32, s32) asm("func_0028ae28");
void func_002426a0(s32);
void func_0024a048();
void func_00287c90(s32);
void func_0024aef0();
void func_0024b1f8();
s32 func_00287df0_k5(s32, s32, s32, void (*)(), s32) asm("func_00287df0");
s32 func_00242848(s32);
void func_0024abb0();
void func_002535b0(s32);
void func_00288658(s32, s32);
void func_0024a150();
void func_00288670(void (*)());
void func_00287da0();
void func_00249ef0();
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
void func_0024a348() {
    s32 a = func_00287cd0();
    s32 r = func_00289380_x9460(D_0035ed70);
    if (D_0035ed94) return;
    if (r != -1 || func_00289310_x9461(D_0035ed70)) {
        if (!func_0028ae28_x9462(D_0035ed70, 0)) {
            func_002426a0(0);
            func_0024a048();
        }
    }
    if (!a && func_0028ae28_x9462(D_0035ed70, 0)) {
        func_00287c90(1);
        func_0024aef0();
    }
    if (func_00242848(func_00287df0_k5(r, func_00289310_x9461(D_0035ed70), 1, func_0024b1f8, 1))) return;
    switch (r) {
    case -6:
        func_0024abb0();
        func_002535b0(3);
        func_00288658(2, 104);
        func_00288670(func_0024a150);
    case -4: case -2:
        func_00287da0();
        break;
    case -5: case -3: case -1:
        break;
    case 0: case 1: case 2:
        func_00249ef0();
        func_00287bd0(1, 0);
        func_00287cc0(0);
        break;
    }
}

// --------------------
extern u32 D_0035ee04;
extern u32 D_0035ee08;
s32 func_00289380_x9516(s32) asm("func_00289380");
void func_00287bc0_x9517() asm("func_00287bc0");
s32 func_00287cd0();
s32 func_00289310_x9519(s32) asm("func_00289310");
s32 func_0023f0c0_x9520(s32) asm("func_0023f0c0");
void func_0023f070(s32, s32, s32);
void func_00287f90(s32);
s32 func_002891e8_x9523(s32) asm("func_002891e8");
void func_0024e9c0();
void func_0024eff8(s32);
void func_00287c90(s32);
void func_00287df0_x9527(s32, s32, s32, s32, s32) asm("func_00287df0");
s32 func_0024f240();
void func_00287da0();
void func_0024f1a0();
void func_0024f070(s32);
s32 func_00288040();
void func_00288018();
void func_0024ec50() {
    s32 r = func_00289380_x9516(D_0035ee04);
    func_00287bc0_x9517();
    s32 a = func_00287cd0();
    if (r != -1 || func_00289310_x9519(D_0035ee04)) {
        if (func_0023f0c0_x9520(D_0035ee08) != 1) {
            func_0023f070(D_0035ee08, 1, -1);
            func_00287f90(0);
            return;
        }
    }
    if (!a && func_0023f0c0_x9520(D_0035ee08) == 1) {
        s32 n = func_002891e8_x9523(D_0035ee04);
        func_0024e9c0();
        func_0024eff8(n);
        func_00287c90(1);
    }
    func_00287df0_x9527(r, func_00289310_x9519(D_0035ee04), 1, 0, 1);
    switch (r) {
    case -2:
        if (!func_0024f240()) goto f1a0;
    case -4:
        func_00287da0();
        break;
    case -3: case -1:
        break;
    f1a0:
        func_0024f1a0();
        break;
    case 0: case 1: case 2: case 3: case 4: case 5: case 6:
        func_0024f070(r);
        break;
    }
    if (func_00288040()) func_00288018();
}


// --------------------
struct O2513b0;
struct VT2513b0 { u8 pad[20]; void (*f20)(O2513b0*); };
struct O2513b0 { VT2513b0* vt; };
extern u32 D_0035ee58;
extern O2513b0* D_0035ee68;
s32 func_00287cd0();
void func_00139d78_x9577(s32) asm("func_00139d78");
s32 func_00289380_x9578(s32) asm("func_00289380");
s32 func_00289310_x9579(s32) asm("func_00289310");
s32 func_0023f0c0_x9580(s32) asm("func_0023f0c0");
void func_0023f070(s32, s32, s32);
void func_002426a0(s32);
void func_00287c90(s32);
void func_00252540();
s32 func_002891e8_x9585(s32) asm("func_002891e8");
s32 func_00252110(s32);
void func_00251ec8(s32);
s32 func_00287df0_x9589(s32, s32, s32, s32, s32) asm("func_00287df0");
s32 func_00242848(s32);
s32 func_00252000();
void func_00251fe0();
void func_00252618();
void func_00287da0();
s32 func_00252710(s32);
void func_00251f40();
void func_002515a0();
void func_00287bd0(s32, s32);
s32 func_00288040();
void func_00288018();
void func_002513b0() {
    s32 a = func_00287cd0();
    func_00139d78_x9577(D_0035ee60);
    s32 r = func_00289380_x9578(D_0035ee58);
    if (r != -1 || func_00289310_x9579(D_0035ee58)) {
        if (func_0023f0c0_x9580(D_0035ee60) != 1) {
            func_0023f070(D_0035ee60, 1, -1);
            func_002426a0(0);
        }
    }
    if (!a && func_0023f0c0_x9580(D_0035ee60) == 1) {
        func_00287c90(1);
        func_00252540();
        func_00251ec8(func_00252110(func_002891e8_x9585(D_0035ee58)));
    }
    if (!func_00242848(func_00287df0_x9589(r, func_00289310_x9579(D_0035ee58), 1, 0, 1))) {
        switch (r) {
        case -4: case -2:
            if (!func_00252000()) {
                func_00252618();
                func_00287da0();
            } else {
                func_00251fe0();
            }
            break;
        case -3: case -1:
            break;
        case 0: case 1: case 2: case 3:
            if (func_00252710(r)) {
                func_00251f40();
            } else {
                if (func_00252000()) D_0035ee68->vt->f20(D_0035ee68);
                func_002515a0();
                func_00287bd0(1, 0);
            }
            break;
        }
    }
    if (func_00288040()) func_00288018();
}

// --------------------
extern s32 D_0035f64c_259 asm("D_0035f64c");
s32 func_00289380_x9644(s32) asm("func_00289380");
s32 func_00287cd0();
s32 func_0028acc8_x9646(s32) asm("func_0028acc8");
s32 func_00289310_x9647(s32) asm("func_00289310");
void func_00287f90(s32);
void func_0028abe0_x9649(s32) asm("func_0028abe0");
void func_00287c30();
s32 func_00287bc0();
void func_002b5af0();
void func_0028f7e8(s32);
void func_0025a1d0();
s32 func_0028ae28_x9655(s32, s32) asm("func_0028ae28");
void func_0028ab20_x9656(s32) asm("func_0028ab20");
void func_00287cc0(s32);
void func_0025d560();
void func_0025d620();
s32 func_00287df0_259(s32, s32, s32, void (*)(), s32) asm("func_00287df0");
s32 func_00242848(s32);
void func_00263c60();
void func_00287da0();
void func_0028aa40(s32);
void func_00287c00(s32);
void func_00287bd0(s32, s32);
void func_0025ca78();
s32 func_00288040();
void func_00288018();
void func_00259fb8() {
    s32 r = func_00289380_x9644(D_0035f64c_259);
    s32 a = func_00287cd0();
    if (a == 2) {
        if (func_0028acc8_x9646(D_0035f64c_259)) {
            if (r != -1 || func_00289310_x9647(D_0035f64c_259)) {
                func_00287f90(0);
                func_0028abe0_x9649(D_0035f64c_259);
            }
            return;
        }
        func_00287c30();
        if (func_00287bc0() != 1) return;
        func_002b5af0();
        func_0028f7e8(1);
        func_0025a1d0();
        return;
    }
    if (r != -1 || func_00289310_x9647(D_0035f64c_259)) {
        if (!func_0028ae28_x9655(D_0035f64c_259, 0)) func_0028ab20_x9656(D_0035f64c_259);
    }
    if (!a && func_0028ae28_x9655(D_0035f64c_259, 0)) {
        func_00287cc0(1);
        func_0025d560();
    }
    if (!func_00242848(func_00287df0_259(r, func_00289310_x9647(D_0035f64c_259), 1, func_0025d620, 1))) {
        switch (r) {
        case -4: case -2:
            func_00263c60();
            func_00287da0();
            break;
        case -3: case -1:
            break;
        case 0:
            func_0028aa40(D_0035f64c_259);
            func_00287cc0(2);
            func_00287c00(1);
            func_00263c60();
            break;
        case 1:
            func_00287bd0(19, 0);
            func_0025ca78();
            break;
        }
    }
    if (func_00288040()) func_00288018();
}

// --------------------
extern s32 D_0035f024_261 asm("D_0035f024");
s32 func_00289380_x9720(s32) asm("func_00289380");
s32 func_00287cd0();
s32 func_00287c10();
s32 func_002576d0();
s32 func_00262e30();
s32 func_00289310_x9725(s32) asm("func_00289310");
void func_00287f90(s32);
void func_002575a8();
void func_00262cb8();
void func_00287c30();
s32 func_00287bc0();
void func_0028af18_x9731(s32, s32) asm("func_0028af18");
void func_0025ffd0();
void func_00260808();
s32 func_00257610(s32);
void func_00257670(s32);
void func_00287c90(s32);
s32 func_00287df0(s32, s32, s32, s32, s32);
s32 func_00242848(s32);
void func_00257530(s32);
void func_00287c00(s32);
s32 func_002570a0(s32);
u16* func_002632d0(s32);
void func_001a3458(s32, s32);
void func_00262c40();
void func_002618d8() {
    s32 r = func_00289380_x9720(D_0035f024_261);
    s32 a = func_00287cd0();
    if (a == 2) {
        s32 st = func_00287c10();
        s32 v = func_002576d0();
        if (v == 0) {
            if (st == 10) v = func_00262e30();
            if (v == 0) goto idle;
        }
        if (r != -1 || func_00289310_x9725(D_0035f024_261)) {
            func_00287f90(0);
            func_002575a8();
            if (st == 10) func_00262cb8();
        }
        return;
    idle: {
        func_00287c30();
        s32 s = func_00287bc0();
        func_0028af18_x9731(D_0035f024_261, 115);
        if (s == 10) func_0025ffd0();
        else if (s == 11) func_00260808();
        return;
    }
    }
    if (r != -1 || func_00289310_x9725(D_0035f024_261)) {
        if (!func_00257610(0)) func_00257670(0);
    }
    if (!a && func_00257610(0)) func_00287c90(1);
    if (func_00242848(func_00287df0(r, func_00289310_x9725(D_0035f024_261), 0, 0, 1))) return;
    switch (r) {
    case -2: case 0:
        func_00257530(0);
        func_00287c90(1);
        func_00287c00(11);
        break;
    case 1:
        func_001a3458(*func_002632d0(func_002570a0(10)), 100);
        func_00257530(0);
        func_00262c40();
        func_00287c90(1);
        func_00287c00(10);
        break;
    case -4: case -3: case -1:
        break;
    }
}

// --------------------
extern s32 D_0035f200_29f asm("D_0035f200");
s32 func_00289380_x9795(s32) asm("func_00289380");
s32 func_00287cd0();
s32 func_00287bc0();
s32 func_00276368();
s32 func_0028acc8_x9799(s32) asm("func_0028acc8");
s32 func_00276888();
void func_00287f90(s32);
void func_0029ee38();
void func_00287c30();
void func_0028af18_x9804(s32, s32) asm("func_0028af18");
s32 func_00276358();
void func_00276220(s32, s32);
void func_00276690(s32);
void func_002766b0(s32);
void func_0028b1e8(s32, s32);
void func_0029ee68();
void func_0029f520();
s32 func_00289310_x9812(s32) asm("func_00289310");
s32 func_00276398();
void func_00275b60();
void func_00287c90(s32);
void func_002a0518();
s32 func_00287df0_29f(s32, s32, s32, void (*)(), s32) asm("func_00287df0");
s32 func_00242848(s32);
void func_0029fee8(s32);
void func_0029ee30();
void func_00287c00(s32);
void func_00287cc0(s32);
s32 func_002891e8_x9823(s32) asm("func_002891e8");
s32 func_0028b038_x9824(s32) asm("func_0028b038");
void func_002765e8(s32, s32, s32);
void func_00287da0();
void func_00276dc0();
s32 func_00288040();
void func_00288018();
void func_0029f938() {
    s32 r = func_00289380_x9795(D_0035f200_29f);
    s32 a = func_00287cd0();
    func_00287bc0();
    if (a == 2) {
        if (func_00276368() || func_0028acc8_x9799(D_0035f200_29f) || func_00276888()) {
            if (r != -1) {
                func_00287f90(0);
                func_0029ee38();
            }
            return;
        }
        func_0029ee38();
        func_00287c30();
        s32 s = func_00287bc0();
        func_0028af18_x9804(D_0035f200_29f, 115);
        func_00276220(func_00276358(), 0);
        func_00276690(0);
        func_002766b0(1);
        if (s == 24) {
            func_0028b1e8(D_0035f200_29f, 1);
            func_0029ee68();
        } else if (s == 25) {
            func_0029f520();
        }
        return;
    }
    if (r != -1 || func_00289310_x9812(D_0035f200_29f)) {
        if (!func_00276398()) {
            func_00276220(0, 2);
            func_00275b60();
        }
    }
    if (!a && func_00276398()) func_00287c90(1);
    if (!func_00242848(func_00287df0_29f(r, func_00289310_x9812(D_0035f200_29f), 1, func_002a0518, 1))) {
        switch (r) {
        case -4: {
            s32 s = func_00287bc0();
            s32 n = func_002891e8_x9823(D_0035f200_29f);
            func_002765e8(s, n, func_0028b038_x9824(D_0035f200_29f));
            func_00287da0();
            break;
        }
        case -9: case -8: case -7: case -6: case -5: case -3: case -1:
            break;
        case -11: case -10:
            func_0029fee8(r);
            func_0029ee30();
            func_00276220(r != -10, 1);
            func_00287c00(25);
            func_00287cc0(2);
            break;
        case -2:
            func_0029ee30();
            func_00276dc0();
            func_00276220(1, 1);
            func_00287c00(24);
            func_00287cc0(2);
            break;
        }
    }
    if (func_00288040()) func_00288018();
}

// --------------------
extern s8* D_0035f234;
void func_00242b88(s32);
void func_00242c00(s32);
void func_00242d80(s32);
void func_00242d10(s32);
void func_00242df0(s32);
void func_00242b10(s32);
void func_00242a28(s32);
void func_00242a90(s32);
void func_00242ca0(s32);
void func_0027cb48() {
    s32 i;
    for (i = 0; i < 10; i++) {
        switch (i) {
        case 0: func_00242b88(D_0035f234[i] == 0); break;
        case 1: func_00242c00(D_0035f234[i] == 0); break;
        case 2: func_00242d80(D_0035f234[i] == 1); break;
        case 3: func_00242d10(D_0035f234[i] == 1); break;
        case 4: {
            s8 t = D_0035f234[i];
            s32 v;
            if (t == 2) v = 0;
            else if (t == 0) v = 2;
            else v = 1;
            func_00242df0(v);
            break;
        }
        case 5: func_00242b10(D_0035f234[i] == 0); break;
        case 6: func_00242a28(D_0035f234[i] == 0); break;
        case 7: {
            s8 t = D_0035f234[i];
            s32 v;
            if (t == 2) v = 0;
            else if (t == 1) v = 2;
            else v = 1;
            func_00242a90(v);
            break;
        }
        case 8: func_00242ca0(D_0035f234[i] == 0); break;
        case 9: break;
        }
    }
}

// --------------------
extern s8* D_0035f234;
s32 func_00242b58();
s32 func_00242bd0();
s32 func_00242d58();
s32 func_00242ce8();
s32 func_00242dc8();
s32 func_00242ae8();
s32 func_00242a00();
s32 func_00242a68();
s32 func_00242c70();
s32 func_001058e8_x9950() asm("func_001058e8");
s8 func_00105868(s32);
void func_0027c9a8() {
    s32 i;
    for (i = 0; i < 10; i++) {
        switch (i) {
        case 0: D_0035f234[i] = func_00242b58() == 0; break;
        case 1: D_0035f234[i] = func_00242bd0() == 0; break;
        case 2: D_0035f234[i] = func_00242d58() != 0; break;
        case 3: D_0035f234[i] = func_00242ce8() != 0; break;
        case 4: {
            s32 v = func_00242dc8();
            if (v == 0) D_0035f234[i] = 2;
            else if (v == 2) D_0035f234[i] = 0;
            else D_0035f234[i] = 1;
            break;
        }
        case 5: D_0035f234[i] = func_00242ae8() == 0; break;
        case 6: D_0035f234[i] = func_00242a00() == 0; break;
        case 7: {
            s32 v = func_00242a68();
            if (v == 0) D_0035f234[i] = 2;
            else if (v == 2) D_0035f234[i] = 1;
            else D_0035f234[i] = 0;
            break;
        }
        case 8: D_0035f234[i] = func_00242c70() == 0; break;
        case 9: {
            s8* p = &D_0035f234[i];
            *p = func_00105868(func_001058e8_x9950());
            break;
        }
        }
    }
}

// --------------------
extern s32 D_0035f01c_27c asm("D_0035f01c");
s32 func_00289380_x9988(s32) asm("func_00289380");
s32 func_00287cd0();
s32 func_00287c10();
s32 func_0027d3b0();
s32 func_0028f930(s32);
s32 func_00289310_x9993(s32) asm("func_00289310");
void func_00287f90(s32);
void func_0027d350();
void func_00287c30();
void func_0028af18_x9997(s32, s32) asm("func_0028af18");
void func_0028f7e8(s32);
void func_002551b8();
s32 func_0027d408();
void func_0027d450();
void func_0028ab20_x10002(s32) asm("func_0028ab20");
void func_0028fa98(s32);
void func_00287c90(s32);
void func_0027d540();
void func_0027d5d8();
void func_0028afa8_x10007(s32) asm("func_0028afa8");
void func_0027d9e8();
s32 func_00287df0_27c(s32, s32, s32, void (*)(), s32) asm("func_00287df0");
s32 func_00242848(s32);
void func_0027d868(s32);
void func_0027d008();
void func_0027cb48();
void func_0013a460();
void func_00287da0();
s32 func_002891e8_x10016(s32) asm("func_002891e8");
s32 func_0028b038_x10017(s32) asm("func_0028b038");
void func_00257050_x10018(s32, s32, s32) asm("func_00257050");
void func_00263c60();
void func_00256e80();
void func_0028f6f0(s32);
void func_0027d2e8();
void func_00287c00(s32);
s32 func_00288040();
void func_00288018();
void func_0027c700() {
    s32 r = func_00289380_x9988(D_0035f01c_27c);
    s32 a = func_00287cd0();
    if (a == 2) {
        s32 st = func_00287c10();
        if (!func_0027d3b0() && !func_0028f930(0)) goto idle;
        if (r != -1 || func_00289310_x9993(D_0035f01c_27c)) {
            func_00287f90(0);
            func_0027d350();
        }
        return;
    idle:
        func_00287c30();
        func_0028af18_x9997(D_0035f01c_27c, 115);
        if (st) return;
        func_0028f7e8(0);
        func_002551b8();
        return;
    }
    if (r != -1 || func_00289310_x9993(D_0035f01c_27c)) {
        if (!func_0027d408()) {
            func_0027d450();
            func_0028ab20_x10002(D_0035f01c_27c);
            func_0028fa98(-1);
        }
    }
    if (!a && func_0027d408()) {
        func_00287c90(1);
        func_0027d540();
        func_0027d5d8();
    }
    func_0028afa8_x10007(D_0035f01c_27c);
    if (!func_00242848(func_00287df0_27c(r, func_00289310_x9993(D_0035f01c_27c), 1, func_0027d9e8, 1))) {
        switch (r) {
        case -4: {
            func_0027cb48();
            func_0013a460();
            func_00287da0();
            s32 n = func_002891e8_x10016(D_0035f01c_27c);
            func_00257050_x10018(36, n, func_0028b038_x10017(D_0035f01c_27c));
            break;
        }
        case -11: case -10: case -9: case -8: case -7: case -6: case -5: case -3: case -1:
            break;
        case -13: case -12:
            func_0027d868(r == -12);
            func_0027d008();
            func_0027d540();
            break;
        case -2: {
            func_0027cb48();
            func_0013a460();
            func_00263c60();
            func_00256e80();
            func_0028f6f0(0);
            func_0027d2e8();
            func_00287c90(1);
            func_00287c00(0);
            s32 n = func_002891e8_x10016(D_0035f01c_27c);
            func_00257050_x10018(36, n, func_0028b038_x10017(D_0035f01c_27c));
            break;
        }
        }
    }
    if (func_00288040()) func_00288018();
}

// --------------------
extern s32 D_0035f200_2a5 asm("D_0035f200");
s32 func_00289380_x10095(s32) asm("func_00289380");
s32 func_00287cd0();
s32 func_00287bc0();
s32 func_002a6718();
void func_002a67a8();
void func_002a4df8();
void func_002a4e38();
void func_002a5590();
s32 func_0028acc8_x10103(s32) asm("func_0028acc8");
s32 func_00276888();
void func_00287f90(s32);
void func_0029ee38();
void func_00287c30();
void func_0028af18_x10108(s32, s32) asm("func_0028af18");
s32 func_00276358();
void func_00276220(s32, s32);
void func_00276690(s32);
void func_002766b0(s32);
void func_0028b1e8(s32, s32);
void func_0029ee68();
void func_0029f520();
s32 func_00289310_x10116(s32) asm("func_00289310");
s32 func_00276398();
void func_00275b60();
void func_00287c90(s32);
void func_002a6878();
s32 func_00287df0_2a5(s32, s32, s32, void (*)(), s32) asm("func_00287df0");
s32 func_00242848(s32);
void func_002a6088(s32);
void func_002a4df0();
void func_00287c00(s32);
void func_00287cc0(s32);
s32 func_002891e8_x10127(s32) asm("func_002891e8");
s32 func_0028b038_x10128(s32) asm("func_0028b038");
void func_002765e8(s32, s32, s32);
void func_00287da0();
void func_00276dc0();
s32 func_00288040();
void func_00288018();
void func_002a5a90() {
    s32 r = func_00289380_x10095(D_0035f200_2a5);
    s32 a = func_00287cd0();
    func_00287bc0();
    if (a == 2) {
        if (func_002a6718()) {
            if (r != -1) {
                func_00287f90(0);
                func_002a67a8();
            }
            return;
        }
        func_002a4df8();
        func_00287c30();
        s32 s = func_00287bc0();
        func_0028af18_x10108(D_0035f200_2a5, 115);
        func_00276220(func_00276358(), 0);
        func_00276690(0);
        func_002766b0(1);
        if (s == 37) {
            func_0028b1e8(D_0035f200_2a5, 1);
            func_002a4e38();
        } else if (s == 38) {
            func_002a5590();
        }
        return;
    }
    if (r != -1 || func_00289310_x10116(D_0035f200_2a5)) {
        if (!func_00276398()) {
            func_00276220(0, 2);
            func_00275b60();
        }
    }
    if (!a && func_00276398()) func_00287c90(1);
    if (!func_00242848(func_00287df0_2a5(r, func_00289310_x10116(D_0035f200_2a5), 1, func_002a6878, 1))) {
        switch (r) {
        case -4: {
            s32 s = func_00287bc0();
            s32 n = func_002891e8_x10127(D_0035f200_2a5);
            func_002765e8(s, n, func_0028b038_x10128(D_0035f200_2a5));
            func_00287da0();
            break;
        }
        case -9: case -8: case -7: case -6: case -5: case -3: case -1:
            break;
        case -11: case -10:
            func_002a6088(r);
            func_002a4df0();
            func_00276220(r != -10, 1);
            func_00287c00(38);
            func_00287cc0(2);
            break;
        case -2:
            func_002a4df0();
            func_00276dc0();
            func_00276220(1, 1);
            func_00287c00(37);
            func_00287cc0(2);
            break;
        }
    }
    if (func_00288040()) func_00288018();
}

// --------------------
struct E24bfb8 { u8 b[36]; };
extern s32 D_0035edac_24b asm("D_0035edac");
extern s32 D_0035eda8_24b asm("D_0035eda8");
extern s32 D_0035edc0_24b asm("D_0035edc0");
extern E24bfb8 D_00372030[];
extern s16 D_00371fc8[];
s32 func_00287cd0();
s32 func_00289380_x10206(s32) asm("func_00289380");
s32 func_0028acc8_x10207(s32) asm("func_0028acc8");
s32 func_00289310_x10208(s32) asm("func_00289310");
void func_0028abe0_x10209(s32) asm("func_0028abe0");
s32 func_002891e8_x10210(s32) asm("func_002891e8");
s32 func_00244ee8(s32);
void func_002b4388_x10212(s32, void*, s32) asm("func_002b4388");
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
s32 func_0028ae28_x10215(s32, s32) asm("func_0028ae28");
void func_0028ab20_x10216(s32) asm("func_0028ab20");
void func_00287c90(s32);
void func_00287df0_x10218(s32, s32, s32, s32, s32) asm("func_00287df0");
void func_0028aa40(s32);
void func_00287b08(s32);
void func_00287da0();
void func_0024bfb8() {
    s32 a = func_00287cd0();
    s32 r = func_00289380_x10206(D_0035edac_24b);
    if (a == 2) {
        if (func_0028acc8_x10207(D_0035edac_24b)) {
            if (r != -1 || func_00289310_x10208(D_0035edac_24b)) func_0028abe0_x10209(D_0035edac_24b);
            return;
        }
        func_002b4388_x10212(D_0035edc0_24b, &D_00372030[func_002891e8_x10210(D_0035eda8_24b)], 0);
        func_00287bd0(0, 0);
        func_00287cc0(1);
        return;
    }
    if (r != -1 || func_00289310_x10208(D_0035edac_24b)) {
        if (!func_0028ae28_x10215(D_0035edac_24b, 0)) func_0028ab20_x10216(D_0035edac_24b);
    }
    if (!a && func_0028ae28_x10215(D_0035edac_24b, 0)) func_00287c90(1);
    func_00287df0_x10218(r, func_00289310_x10208(D_0035edac_24b), 0, 0, 1);
    switch (r) {
    case -2: case 1:
        func_0028aa40(D_0035edac_24b);
        func_00287c90(1);
        break;
    case 0:
        func_00287b08(D_00371fc8[func_002891e8_x10210(D_0035eda8_24b)]);
        func_00287da0();
        break;
    case -4: case -3: case -1:
        break;
    }
}

// --------------------
struct E24d910 { u8 b[36]; };
extern s32 D_0035edd0_24d asm("D_0035edd0");
extern s32 D_0035edcc_24d asm("D_0035edcc");
extern s32 D_0035edec_24d asm("D_0035edec");
extern s32 D_0035edf4_24d asm("D_0035edf4");
extern s16 D_00372118[];
extern s16 D_00372120[];
u8* func_0024e058();
s32 func_00287cd0();
s32 func_00289380_x10264(s32) asm("func_00289380");
s32 func_0028acc8_x10265(s32) asm("func_0028acc8");
s32 func_00289310_x10266(s32) asm("func_00289310");
void func_0028abe0_x10267(s32) asm("func_0028abe0");
s32 func_002891e8_x10268(s32) asm("func_002891e8");
s32 func_00244ee8(s32);
void func_002b4388_x10270(s32, void*, s32) asm("func_002b4388");
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
s32 func_0028ae28_x10273(s32, s32) asm("func_0028ae28");
void func_0028ab20_x10274(s32) asm("func_0028ab20");
void func_00287c90(s32);
void func_00287df0_x10276(s32, s32, s32, s32, s32) asm("func_00287df0");
void func_0028aa40(s32);
void func_00287b08(s32);
void func_00287da0();
void func_0024d910() {
    s32 a = func_00287cd0();
    s32 r = func_00289380_x10264(D_0035edd0_24d);
    if (a == 2) {
        if (func_0028acc8_x10265(D_0035edd0_24d)) {
            if (r != -1 || func_00289310_x10266(D_0035edd0_24d)) func_0028abe0_x10267(D_0035edd0_24d);
            return;
        }
        u8* base = func_0024e058();
        func_002b4388_x10270(D_0035edec_24d, base + func_002891e8_x10268(D_0035edcc_24d) * 36, 0);
        func_00287bd0(0, 0);
        func_00287cc0(1);
        return;
    }
    if (r != -1 || func_00289310_x10266(D_0035edd0_24d)) {
        if (!func_0028ae28_x10273(D_0035edd0_24d, 0)) func_0028ab20_x10274(D_0035edd0_24d);
    }
    if (!a && func_0028ae28_x10273(D_0035edd0_24d, 0)) func_00287c90(1);
    func_00287df0_x10276(r, func_00289310_x10266(D_0035edd0_24d), 0, 0, 1);
    switch (r) {
    case -2: case 1:
        func_0028aa40(D_0035edd0_24d);
        func_00287c90(1);
        break;
    case 0: {
        s32 n = func_002891e8_x10268(D_0035edcc_24d);
        func_00287b08((D_0035edf4_24d == 0 ? D_00372118 : D_00372120)[n]);
        func_00287da0();
        break;
    }
    case -4: case -3: case -1:
        break;
    }
}

// --------------------
struct E250130 { u8 b[36]; };
extern s32 D_0035ee38_250 asm("D_0035ee38");
extern s32 D_0035ee34_250 asm("D_0035ee34");
extern s32 D_0035ee4c_250 asm("D_0035ee4c");
extern E250130 D_00372490[];
extern s16 D_00372410[];
s32 func_00287cd0();
s32 func_00289380_x10323(s32) asm("func_00289380");
s32 func_0028acc8_x10324(s32) asm("func_0028acc8");
s32 func_00289310_x10325(s32) asm("func_00289310");
void func_0028abe0_x10326(s32) asm("func_0028abe0");
s32 func_002891e8_x10327(s32) asm("func_002891e8");
s32 func_00244ee8(s32);
void func_002b4388_x10329(s32, void*, s32) asm("func_002b4388");
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
s32 func_0028ae28_x10332(s32, s32) asm("func_0028ae28");
void func_0028ab20_x10333(s32) asm("func_0028ab20");
void func_00287c90(s32);
void func_00287df0_x10335(s32, s32, s32, s32, s32) asm("func_00287df0");
void func_0028aa40(s32);
void func_00287b08(s32);
void func_00287da0();
void func_00250748();
void func_00250130() {
    s32 a = func_00287cd0();
    s32 r = func_00289380_x10323(D_0035ee38_250);
    if (a == 2) {
        if (func_0028acc8_x10324(D_0035ee38_250)) {
            if (r != -1 || func_00289310_x10325(D_0035ee38_250)) func_0028abe0_x10326(D_0035ee38_250);
            return;
        }
        func_002b4388_x10329(D_0035ee4c_250, &D_00372490[func_002891e8_x10327(D_0035ee34_250)], 0);
        func_00287bd0(0, 0);
        func_00287cc0(1);
        return;
    }
    if (r != -1 || func_00289310_x10325(D_0035ee38_250)) {
        if (!func_0028ae28_x10332(D_0035ee38_250, 0)) func_0028ab20_x10333(D_0035ee38_250);
    }
    if (!a && func_0028ae28_x10332(D_0035ee38_250, 0)) func_00287c90(1);
    func_00287df0_x10335(r, func_00289310_x10325(D_0035ee38_250), 0, 0, 1);
    switch (r) {
    case -2: case 1:
        func_0028aa40(D_0035ee38_250);
        func_00287c90(1);
        break;
    case 0:
        func_00250748();
        func_00287b08(D_00372410[func_002891e8_x10327(D_0035ee34_250)]);
        func_00287da0();
        break;
    case -4: case -3: case -1:
        break;
    }
}

// --------------------
extern s32 D_0035f64c_25a asm("D_0035f64c");
s32 func_00289380_x10375(s32) asm("func_00289380");
s32 func_00287cd0();
s32 func_0028acc8_x10377(s32) asm("func_0028acc8");
s32 func_00289310_x10378(s32) asm("func_00289310");
void func_00287f90(s32);
void func_0028abe0_x10380(s32) asm("func_0028abe0");
void func_00287c30();
s32 func_00287bc0();
void func_002b5af0();
void func_0028f7e8(s32);
void func_00259e90();
void func_00240be0();
void func_002b4c10();
extern u8 D_0035f0b2;
void func_0028f6f0(s32);
void func_00240b90(s32);
s32 func_0028ae28_x10391(s32, s32) asm("func_0028ae28");
void func_0028ab20_x10392(s32) asm("func_0028ab20");
void func_00287cc0(s32);
void func_0025d560();
void func_0025d620();
s32 func_00287df0_25a(s32, s32, s32, void (*)(), s32) asm("func_00287df0");
s32 func_00242848(s32);
void func_00263c60();
void func_00287da0();
void func_0028aa40(s32);
void func_00287c00(s32);
void func_00287bd0(s32, s32);
void func_0025ca78();
s32 func_00288040();
void func_00288018();
void func_0025a200() {
    s32 r = func_00289380_x10375(D_0035f64c_25a);
    s32 a = func_00287cd0();
    if (a == 2) {
        if (func_0028acc8_x10377(D_0035f64c_25a)) {
            if (r != -1 || func_00289310_x10378(D_0035f64c_25a)) {
                func_00287f90(0);
                func_0028abe0_x10380(D_0035f64c_25a);
            }
            return;
        }
        func_00287c30();
        s32 s = func_00287bc0();
        if (s == 0) {
            func_0028f7e8(0);
            func_00259e90();
        } else if (s == 2) {
            func_002b5af0();
            func_0028f7e8(1);
            func_00240be0();
            func_002b4c10();
        }
        return;
    }
    if (r != -1 || func_00289310_x10378(D_0035f64c_25a)) {
        if (!func_0028ae28_x10391(D_0035f64c_25a, 0)) func_0028ab20_x10392(D_0035f64c_25a);
    }
    if (!a && func_0028ae28_x10391(D_0035f64c_25a, 0)) {
        func_00287cc0(1);
        func_0025d560();
    }
    if (!func_00242848(func_00287df0_25a(r, func_00289310_x10378(D_0035f64c_25a), 1, func_0025d620, 1))) {
        switch (r) {
        case -2:
            if (!D_0035f0b2) goto other;
        case -4:
            func_00263c60();
            func_00287da0();
            break;
        case -3: case -1:
            break;
        other:
            func_0028aa40(D_0035f64c_25a);
            func_00287cc0(2);
            func_00287c00(0);
            func_0028f6f0(0);
            func_00263c60();
            break;
        case 0: case 1:
            func_00240b90(r);
            func_00287c00(2);
            func_0028aa40(D_0035f64c_25a);
            func_00287cc0(2);
            func_00263c60();
            break;
        }
    }
    if (func_00288040()) func_00288018();
}

// --------------------
extern s32 D_0035f64c_25d asm("D_0035f64c");
s32 func_00289380_x10468(s32) asm("func_00289380");
s32 func_00287cd0();
s32 func_0028acc8_x10470(s32) asm("func_0028acc8");
s32 func_00289310_x10471(s32) asm("func_00289310");
void func_00287f90(s32);
void func_0028abe0_x10473(s32) asm("func_0028abe0");
void func_00287c30();
s32 func_00287bc0();
void func_002b5af0();
void func_0028f7e8(s32);
void func_00259e90();
void func_00240be0();
void func_002b4c10();
extern u8 D_0035f0b2;
void func_0028f6f0(s32);
void func_00240b90(s32);
s32 func_0028ae28_x10484(s32, s32) asm("func_0028ae28");
void func_0028ab20_x10485(s32) asm("func_0028ab20");
void func_00287cc0(s32);
void func_00287c90(s32);
void func_0025f588();
void func_0025f610();
s32 func_00287df0_25d(s32, s32, s32, void (*)(), s32) asm("func_00287df0");
s32 func_00242848(s32);
void func_00263c60();
void func_00287da0();
void func_0028aa40(s32);
void func_00287c00(s32);
void func_00287bd0(s32, s32);
void func_0025ca78();
s32 func_00288040();
void func_00288018();
void func_0025dbd8() {
    s32 r = func_00289380_x10468(D_0035f64c_25d);
    s32 a = func_00287cd0();
    if (a == 2) {
        if (func_0028acc8_x10470(D_0035f64c_25d)) {
            if (r != -1 || func_00289310_x10471(D_0035f64c_25d)) {
                func_00287f90(0);
                func_0028abe0_x10473(D_0035f64c_25d);
            }
            return;
        }
        func_00287c30();
        if (func_00287bc0() == 2) {
            func_002b5af0();
            func_0028f7e8(1);
            func_00240be0();
            func_002b4c10();
        }
        return;
    }
    if (r != -1 || func_00289310_x10471(D_0035f64c_25d)) {
        if (!func_0028ae28_x10484(D_0035f64c_25d, 0)) func_0028ab20_x10485(D_0035f64c_25d);
    }
    if (!a && func_0028ae28_x10484(D_0035f64c_25d, 0)) {
        func_00287c90(1);
        func_0025f588();
    }
    if (!func_00242848(func_00287df0_25d(r, func_00289310_x10471(D_0035f64c_25d), 1, func_0025f610, 1))) {
        switch (r) {
        case -4: case -2:
            func_0028f6f0(0);
            func_00263c60();
            func_00287da0();
            break;
        case -3: case -1:
            break;
        case 0: case 1:
            func_00240b90(r);
            func_00287c00(2);
            func_0028aa40(D_0035f64c_25d);
            func_00287c90(1);
            func_00263c60();
            break;
        }
    }
    if (func_00288040()) func_00288018();
}

// --------------------
extern s32 D_0035f024_261b asm("D_0035f024");
s32 func_00289380_x10550(s32) asm("func_00289380");
s32 func_00287cd0();
s32 func_00287c10();
s32 func_002576d0();
s32 func_00289310_x10554(s32) asm("func_00289310");
void func_00287f90(s32);
void func_002575a8();
void func_00287c30();
s32 func_00287bc0();
void func_0028af18_x10559(s32, s32) asm("func_0028af18");
void func_00287cc0(s32);
s32 func_00257610(s32);
void func_00257670(s32);
void func_00287c90(s32);
s32 func_00287df0(s32, s32, s32, s32, s32);
s32 func_00242848(s32);
void func_00257530(s32);
void func_00287c00(s32);
void func_00261668() {
    s32 r = func_00289380_x10550(D_0035f024_261b);
    s32 a = func_00287cd0();
    if (a == 2) {
        func_00287c10();
        if (!func_002576d0()) goto idle;
        if (r != -1 || func_00289310_x10554(D_0035f024_261b)) {
            func_00287f90(0);
            func_002575a8();
        }
        return;
    idle:
        func_00287c30();
        func_00287bc0();
        func_0028af18_x10559(D_0035f024_261b, 115);
        func_00287cc0(1);
        return;
    }
    if (r != -1 || func_00289310_x10554(D_0035f024_261b)) {
        if (!func_00257610(0)) func_00257670(0);
    }
    if (!a && func_00257610(0)) func_00287c90(1);
    if (func_00242848(func_00287df0(r, func_00289310_x10554(D_0035f024_261b), 0, 0, 1))) return;
    switch (r) {
    case -4: case -3: case -1:
        break;
    case -2: case 0: case 1:
        func_00257530(0);
        func_00287c90(1);
        func_00287c00(12);
        break;
    }
}

// --------------------
struct V2e4a08 { f32 x, y; };
void func_002e4a08(V2e4a08* v) {
    v->x = 15.0f;
    v->y = 6.0f;
}

// --------------------
struct S246070 { u8 b[26]; u16 h26; u8 c[8]; };
extern s32 D_0035ed24_246 asm("D_0035ed24");
extern s32 D_0035ed20_246 asm("D_0035ed20");
extern s32 D_0035ed38_246 asm("D_0035ed38");
extern u8* D_0035ed40_246 asm("D_0035ed40");
extern u8 D_00371ca8[];
extern u8 D_00371cb0[];
s32 func_00287cd0();
s32 func_00289380_x10618(s32) asm("func_00289380");
s32 func_0028acc8_x10619(s32) asm("func_0028acc8");
s32 func_00289310_x10620(s32) asm("func_00289310");
void func_0028abe0_x10621(s32) asm("func_0028abe0");
u8* func_00246868();
s32 func_002891e8_x10623(s32) asm("func_002891e8");
s32 func_002469a0(s32);
s32 func_002474e0(s32);
s32 func_00246840();
void func_002b4388_x10627(s32, void*, s32) asm("func_002b4388");
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
s32 func_0028ae28_x10630(s32, s32) asm("func_0028ae28");
void func_0028ab20_x10631(s32) asm("func_0028ab20");
void func_00287c90(s32);
void func_00287df0_x10633(s32, s32, s32, s32, s32) asm("func_00287df0");
void func_0028aa40(s32);
void func_002468e8(s32, s32);
void func_001d7940();
void func_00287da0();
void func_00246070() {
    s32 n;
    s32 a = func_00287cd0();
    s32 r = func_00289380_x10618(D_0035ed24_246);
    if (a == 2) {
        if (func_0028acc8_x10619(D_0035ed24_246)) {
            if (r != -1 || func_00289310_x10620(D_0035ed24_246)) func_0028abe0_x10621(D_0035ed24_246);
            return;
        }
        u8* base = func_00246868();
        n = func_002891e8_x10623(D_0035ed20_246);
        S246070 tmp = *(S246070*)(func_002469a0(n) * 36 + (u32)base);
        if (func_002474e0(n)) {
            s32 k = func_002469a0(n);
            u8 v = (func_00246840() ? D_00371cb0 : D_00371ca8)[k];
            tmp.h26 = v == 7 ? 4044 : 4045;
        }
        func_002b4388_x10627(D_0035ed38_246, &tmp, 0);
        func_00287bd0(0, 0);
        func_00287cc0(1);
        return;
    }
    if (r != -1 || func_00289310_x10620(D_0035ed24_246)) {
        if (!func_0028ae28_x10630(D_0035ed24_246, 0)) func_0028ab20_x10631(D_0035ed24_246);
    }
    if (!a && func_0028ae28_x10630(D_0035ed24_246, 0)) func_00287c90(1);
    func_00287df0_x10633(r, func_00289310_x10620(D_0035ed24_246), 0, 0, 1);
    switch (r) {
    case -2: case 1:
        func_0028aa40(D_0035ed24_246);
        func_00287c90(1);
        break;
    case 0: {
        n = func_002891e8_x10623(D_0035ed20_246);
        func_002468e8(func_002469a0(n), *(s8*)((u32)n + (u32)D_0035ed40_246 + 14664) + 1);
        func_001d7940();
        func_00287da0();
        break;
    }
    case -4: case -3: case -1:
        break;
    }
}

// --------------------
extern s32 D_0035f200_298 asm("D_0035f200");
s32 func_00289380_x10684(s32) asm("func_00289380");
s32 func_00287cd0();
s32 func_00287bc0();
s32 func_00276368();
s32 func_0028acc8_x10688(s32) asm("func_0028acc8");
s32 func_00276888();
void func_00287f90(s32);
s32 func_00287c10();
void func_00297e00(s32);
void func_00297e68();
void func_002986e0();
extern s8 D_0035f5a0;
void func_00299090();
void func_00298c60(s32);
void func_00297df8();
void func_00287c30();
void func_0028af18_x10700(s32, s32) asm("func_0028af18");
s32 func_00276358();
void func_00276220(s32, s32);
void func_00276690(s32);
void func_002766b0(s32);
void func_0028b1e8(s32, s32);
void func_0029ee68();
void func_0029f520();
s32 func_00289310_x10708(s32) asm("func_00289310");
s32 func_00276398();
void func_00275b60();
void func_00287c90(s32);
void func_00299408();
s32 func_00287df0_298(s32, s32, s32, void (*)(), s32) asm("func_00287df0");
s32 func_00242848(s32);
void func_0029fee8(s32);
void func_0029ee30();
void func_00287c00(s32);
void func_00287cc0(s32);
s32 func_002891e8_x10719(s32) asm("func_002891e8");
s32 func_0028b038_x10720(s32) asm("func_0028b038");
void func_002765e8(s32, s32, s32);
void func_00287da0();
void func_00276dc0();
s32 func_00288040();
void func_00288018();
void func_00298988() {
    s32 r = func_00289380_x10684(D_0035f200_298);
    s32 a = func_00287cd0();
    func_00287bc0();
    if (a == 2) {
        if (func_00276368() || func_0028acc8_x10688(D_0035f200_298) || func_00276888()) {
            if (r != -1) {
                func_00287f90(0);
                func_00297e00(func_00287c10());
            }
            return;
        }
        func_00276690(0);
        func_002766b0(1);
        func_00297e00(func_00287c10());
        func_00287c30();
        s32 s = func_00287bc0();
        func_0028af18_x10700(D_0035f200_298, 115);
        if (s == 4) {
            func_00276220(func_00276358(), 0);
            func_002765e8(func_00287bc0(), D_0035f5a0, 0);
            func_00297e68();
        } else if (s == 5) {
            func_00276220(func_00276358(), 0);
            func_002986e0();
        }
        return;
    }
    func_00299090();
    if (r != -1 || func_00289310_x10708(D_0035f200_298)) {
        if (!func_00276398()) {
            func_00276220(0, 2);
            func_00275b60();
        }
    }
    if (!a && func_00276398()) func_00287c90(1);
    if (!func_00242848(func_00287df0_298(r, func_00289310_x10708(D_0035f200_298), 1, func_00299408, 1))) {
        switch (r) {
        case -4:
            func_00287da0();
            break;
        case -9: case -8: case -7: case -6: case -5: case -3: case -1:
            break;
        case -11: case -10:
            func_00298c60(r);
            func_00297df8();
            func_00276220(r != -10, 1);
            func_00287c00(func_00287bc0());
            func_00287cc0(2);
            break;
        case -2:
            func_00297df8();
            func_00276dc0();
            func_00276220(1, 1);
            func_00287c00(4);
            func_00287cc0(2);
            break;
        }
    }
    if (func_00288040()) func_00288018();
}

// --------------------
extern f32 D_00349e10;
void func_00105620(u8*, u8*);
union U102470 { u8* p; f32 f; };
void func_00102470(u8* p, f32 x) {
    ((U102470*)(((U102470*)(p + 52))->p + 248))->f = x - D_00349e10;
    func_00105620(((U102470*)(p + 52))->p, ((U102470*)(p + 36))->p + 32);
}

// --------------------
extern u64 D_0036b0d0;
void func_0014b920(u64* p) {
    p[0] = 0x1000000000008001ULL;
    p[1] = 14;
    p[2] = 0x19f000001ff0000ULL;
    p[3] = 64;
}

// --------------------
extern f32 D_01c60be8;
void wtarget_0018c868(u32, u32, u32, u32) asm("_Z16wtarget_0018c868jjjj");
void wtarget_0018c868(u32 a0, u32 a1, u32, u32) {
    if (a1 == 0xffff && a0 == 1) D_01c60be8 = 0.34906584f;
}

// --------------------
struct YS_DAMAGE { u8 pad[39]; u8 type; };
s32 YS_DAMAGE_is_normal(const YS_DAMAGE*) asm("_ZNK2YS6DAMAGE9is_normalEv");
s32 YS_DAMAGE_is_normal(const YS_DAMAGE* d) {
    switch (d->type) {
    case 0: case 1: case 3: case 4: case 6: case 7: case 15: case 16:
        return 1;
    case 2: case 5: case 8: case 9: case 10: case 11: case 12: case 13: case 14:
        return 0;
    }
    return 0;
}

// --------------------
void func_001ad990(u8*, f32, f32, f32);
void func_001b1be0(u8* p, f32 x) {
    func_001ad990(p + 8, 0.0f, 1.0f, x);
}

// --------------------
void func_001cfac0(u8* p, f32 a, f32 b, f32 c, f32 d) {
    *(f32*)(p + 2960) = a * 0.017453292f;
    *(f32*)(p + 2964) = b * 0.017453292f;
    *(f32*)(p + 2968) = c * 0.017453292f;
    *(f32*)(p + 2972) = d * 0.017453292f;
}

// --------------------
void func_001a5990(u8*, f32, s32);
void func_001d29a0(u8* a, u8* b) {
    func_001a5990(b, 1.0f, 0);
}

// --------------------
extern f32 D_01d5ba08;
void wtarget_001d3060(u32, u32, u32, u32) asm("_Z16wtarget_001d3060jjjj");
void wtarget_001d3060(u32 a0, u32 a1, u32, u32) {
    if (a1 == 0xffff && a0 == 1) D_01d5ba08 = 1.57079625f;
}

// --------------------
void func_002cd260(u8* p) {
    if (p[135]) {
        *(s32*)(p + 136) = 0;
        *(s32*)(p + 4) = 0;
        *(f32*)(p + 28) = -2.0f;
        *(s32*)(p + 8) = 0;
        *(s32*)(p + 24) = 0;
    }
}

// --------------------
extern f32 D_003634f0;
void wtarget_002eaee8(u32, u32, u32, u32) asm("_Z16wtarget_002eaee8jjjj");
void wtarget_002eaee8(u32 a0, u32 a1, u32, u32) {
    if (a1 == 0xffff && a0 == 1) D_003634f0 = 0.392699063f;
}

// --------------------
s32 func_00186110(void*, u8* p) {
    switch (p[36]) {
    case 0: case 2: case 3: case 4: case 5:
        return 1;
    case 1: case 6: case 7: case 8: case 9:
        return 0;
    }
    return 0;
}

// --------------------
struct E256a58 { u8 pad[20]; u16 id; u8 pad2[14]; };
extern s32 D_0035f01c_256 asm("D_0035f01c");
extern E256a58 D_00372a28[];
s32 func_0028b040_x10886(s32) asm("func_0028b040");
s32 func_00257fa8(s32);
void func_00263a58(s32, s32);
void func_00256a58() {
    func_00263a58(D_00372a28[func_00257fa8(func_0028b040_x10886(D_0035f01c_256))].id, 1);
}

// --------------------
struct O2e0720;
struct VT2e0720 { u8 pad[44]; s32 (*f44)(O2e0720*); };
struct O2e0720 { VT2e0720* vt; };
void func_0017f488(u8*, s32, f32, f32);
void func_002e0720(O2e0720* o, u8* p) {
    u8* q = p + 320;
    func_0017f488(q, o->vt->f44(o), 8.0f, 0.0f);
}

// --------------------
struct E230838 { s32 a; s32 b; };
union U230838 { E230838* p; s32 i; };
extern U230838 D_0035dce8_x10906 asm("D_0035dce8");
void func_00230838(s32 v) {
    s32 i;
    for (i = 0; i < 64; i++) {
        E230838* e = (E230838*)((i << 3) + (u32)D_0035dce8_x10906.p);
        if (e->a == 0) {
            e->a = v;
            return;
        }
    }
}

// --------------------
s32 func_00155fc0(u8* p) {
    u8* o = *(u8**)(p + 52);
    if (o) {
        switch ((*(u8**)(o + 1164))[431]) {
        case 2: return 49;
        case 3: return 139;
        case 0: case 1: case 4: break;
        }
    }
    return 25;
}

// --------------------
struct E230878 { u8* a; u8* b; };
union U230878 { E230878* p; s32 i; };
extern U230878 D_0035dce8_878 asm("D_0035dce8");
void func_00230878(u8* q) {
    s32 i;
    s16 id = *(s16*)(q + 4);
    for (i = 0; i < 64; i++) {
        E230878* e = (E230878*)((i << 3) + (u32)D_0035dce8_878.p);
        if (e->a && *(s16*)(e->a + 4) == id) {
            e->b = q;
            return;
        }
    }
}

// --------------------
extern void* D_0035f324;
void func_00167658(void*, s32);
void func_00288018();
void* func_001063c0_x10951(s32, s32) asm("func_001063c0");
void func_00287ed8(s32 a) {
    if (!D_0035f324) {
        void* p = func_001063c0_x10951(80, a);
        func_00167658(p, 0);
        D_0035f324 = p;
    }
    func_00288018();
}

// --------------------
s32 func_00155ee8(u8* p) {
    u8* o = *(u8**)(p + 52);
    if (!o) goto def;
    switch ((*(u8**)(o + 1164))[431]) {
    case 4: return 18;
    case 0: case 1:
    def:
        return 21;
    case 2: return 50;
    case 3: return 140;
    }
    return 21;
}

// --------------------
void func_001e0fe0(u8*);
void func_001e0fe8(u8*);
void func_001e1068(u8*);
void func_001e15a8(u8*);
void func_001e1638(u8*);
void func_001e1698(u8*);
void func_001e16c0(u8*);
void func_001e1728(u8* p) {
    switch (*(s32*)(p + 36)) {
    case 0: func_001e0fe0(p); break;
    case 1: func_001e0fe8(p); break;
    case 2: func_001e1068(p); break;
    case 3: func_001e15a8(p); break;
    case 4: func_001e1638(p); break;
    case 5: func_001e1698(p); break;
    case 6: func_001e16c0(p); break;
    }
}

// --------------------
struct E1815d0 { s32 a; s32 b; };
extern E1815d0 D_0036c668[];
void func_001a3458(s32, s32);
s32 func_001a3570(s32);
void func_00181570(s32, s32);
void func_001815d0(s32 id) {
    switch (id) {
    case 9225: case 9233: case 9241: case 9249: case 9256:
        func_001a3458(32, 100);
        return;
    }
    if (func_001a3570(32)) {
        E1815d0* e = D_0036c668;
        s32 i;
        for (i = 4; i >= 0; i--, e++) func_00181570(e->a, e->b);
    }
}

// --------------------
extern s32 D_0035ece0;
extern s32 D_003718d0[];
void func_0023d320(s32);
void func_00242740(s32);
void func_00287910(s32, s32, s32);
s32 func_00103570();
void func_0028c878(s32, s32);
void func_002425d0(s32);
void func_00242fa0();
struct VT242f00 { void* a; void (*b)(); };
VT242f00* func_00243150(s32);
void func_00242f00(s32 n) {
    func_0023d320(n);
    func_00242740(-1);
    func_00287910(n, 2, 0);
    func_0028c878(func_00103570(), 2);
    func_002425d0(2);
    func_00242fa0();
    if (D_0035ece0 < 0) D_0035ece0 = D_003718d0[n];
    func_00243150(n)->b();
}

// --------------------
struct V15a098 {
    f32 x, y, z, w;
    V15a098() {}
    V15a098(const V15a098& o) { if (this != &o) QCOPY(this, &o); }
    V15a098& operator=(const V15a098& o) { if (this != &o) QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
// VU0 vector helper: hand-written macro code in the original.
static inline V15a098 Sub15a098(const V15a098& a, const V15a098& b)
{
    V15a098 r;
    asm volatile("lqc2 $vf1,0(%1)\n\tlqc2 $vf2,0(%2)\n\tvsub.wxyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
f32 func_002f8ad0__15a098(f32, f32) asm("func_002f8ad0");
extern V15a098 D_0034aa50[2];
static inline f32 Yaw15a098(V15a098 v) { return func_002f8ad0__15a098(v.x, v.z); }
void func_0015a098(void)
{
    V15a098 a, d;
    V15a098* p = D_0034aa50;
    a = p[0];
    d = Sub15a098(p[1], p[0]);
    d.w = 1.0f;
    a.w = 1.0f;
    Yaw15a098(d);
}

// --------------------
struct V2e2f08 {
    f32 x, y, z, w;
    V2e2f08() {}
    V2e2f08(const V2e2f08& o) { if (this != &o) QCOPY(this, &o); }
    V2e2f08& operator=(const V2e2f08& o) { if (this != &o) QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
// VU0 matrix * vector: hand-written macro code in the original.
static inline V2e2f08 Mul2e2f08(const f32* m, const V2e2f08& v)
{
    V2e2f08 r;
    asm volatile("lqc2 $vf5,0(%2)\n\tlqc2 $vf1,0(%1)\n\tlqc2 $vf2,16(%1)\n\tlqc2 $vf3,32(%1)\n\tlqc2 $vf4,48(%1)\n\t"
                 "vmulax.wxyz ACC,$vf1,$vf5x\n\tvmadday.wxyz ACC,$vf2,$vf5y\n\tvmaddaz.wxyz ACC,$vf3,$vf5z\n\t"
                 "vmaddw.wxyz $vf5,$vf4,$vf5w\n\tsqc2 $vf5,0(%0)"
                 : : "r"(&r), "r"(m), "r"(&v) : "memory");
    return r;
}
V2e2f08 func_00184540__2e2f08(u32, f32, f32) asm("func_00184540");
f32* func_002e2930__2e2f08(u32) asm("func_002e2930");
extern u32 D_00361f60__2e2f08 asm("D_00361f60");
V2e2f08 func_002e2f08(u32 self, u32 a)
{
    V2e2f08 v = func_00184540__2e2f08(a, 0.8f, 0.8f);
    f32* m = func_002e2930__2e2f08(D_00361f60__2e2f08);
    v.w = 0.0f;
    v = Mul2e2f08(m, v);
    return v;
}

// --------------------
struct N102688 { u8 pad[40]; u32 fl; u8 pad2[12]; N102688* next; };
struct M102688 { u32 f0; u32 f4; N102688* head; };
void func_001025f8__102688(M102688*, N102688*) asm("func_001025f8");
static inline N102688* Next102688(M102688* m, N102688* p, u32 mask, u32 v)
{
    do {
        p = !p ? m->head : p->next;
    } while (p && (p->fl & mask) != v);
    return p;
}
void wtarget_00102688(M102688* m, u32 mask, u32 v, u32) asm("_Z16wtarget_00102688jjjj");
void wtarget_00102688(M102688* m, u32 mask, u32 v, u32)
{
    N102688* p = Next102688(m, 0, mask, v);
    while (p) {
        N102688* n = Next102688(m, p, mask, v);
        func_001025f8__102688(m, p);
        p = n;
    }
}

// --------------------
struct E182fa0 { u32 a; u32 b; u32 c; };
extern E182fa0 D_01c60588[64];
void func_001828b8__182fa0(E182fa0*) asm("func_001828b8");
static inline void Del182fa0(E182fa0* a)
{
    if (a != 0) {
        E182fa0* p = a + 64;
        E182fa0* b = a;
    top:
        if (p == b) return;
        --p;
        func_001828b8__182fa0(p);
        goto top;
    }
}
void wtarget_00182fa0(s32 init, s32 prio, u32, u32) asm("_Z16wtarget_00182fa0jjjj");
void wtarget_00182fa0(s32 init, s32 prio, u32, u32)
{
    if (prio == 0xffff && init == 1) {
        E182fa0* p = D_01c60588;
        s32 n;
        for (n = 63; n != -1; n--) {
            p->b = 0;
            p++;
        }
    }
    if (prio == 0xffff && init == 0) {
        Del182fa0(D_01c60588);
    }
}

// --------------------
extern u8 D_00351e18[];
extern u8 D_00345c08[];
extern u8 D_0034ebc8[];
extern void* D_01d49960[2];
extern u32 D_01d49968;
struct L0_1c8118;
void func_00320fa8__1c8118(L0_1c8118*) asm("func_00320fa8");
struct L0_1c8118 { u32 vt; };
struct L1_1c8118 : L0_1c8118 {
    ~L1_1c8118() { *(u32*)this = (u32)D_0034ebc8; func_00320fa8__1c8118(this); }
};
struct M1c8118 { u8 d[16]; ~M1c8118() {} };
struct L2_1c8118 : L1_1c8118 {
    u8 pad[3180];
    M1c8118 arr[6];
    ~L2_1c8118() { *(u32*)this = (u32)D_00345c08; }
};
struct L3_1c8118 : L2_1c8118 {
    __attribute__((always_inline)) ~L3_1c8118()
    {
        s32 i, n;
        *(u32*)this = (u32)D_00351e18;
        n = 0;
        for (i = 0; i < 2; i++) {
            if (D_01d49960[i]) {
                if (D_01d49960[i] == this) D_01d49960[i] = 0;
                else n++;
            }
        }
        if (n == 0) D_01d49968 = 0;
    }
};
void func_001c8118(L3_1c8118* p)
{
    p->~L3_1c8118();
}

// --------------------
struct X2c62c8;
struct VT2c62c8 { u32 a, b; s32 (*f8)(X2c62c8*); };
struct X2c62c8 { VT2c62c8* vt; };
struct O2c62c8 { u8 pad[16]; X2c62c8* slot[3]; X2c62c8* cur; };
void func_002c65f8__2c62c8(X2c62c8*) asm("func_002c65f8");
void func_002c6280__2c62c8(O2c62c8*, s32) asm("func_002c6280");
s32 func_002c62c8(O2c62c8* o)
{
    s32 found = 0;
    s32 i;
    o->cur = 0;
    for (i = 2; i >= 0; i--) {
        X2c62c8* x = o->slot[i];
        if (!x) continue;
        if (!found) {
            if (x->vt->f8(x)) { found = 1; o->cur = o->slot[i]; }
            else func_002c6280__2c62c8(o, i);
        } else func_002c65f8__2c62c8(x);
    }
    return found;
}

// --------------------
struct V159070 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct C159070;
struct VTC159070 { u8 pad[64]; s32 (*f64)(C159070*); };
struct C159070 { VTC159070* vt; };
struct O159070 { u8 pad[68]; C159070* c; };
s32 func_001b9d40__159070(C159070*) asm("func_001b9d40");
s32 func_00190140__159070(void*) asm("func_00190140");
void func_001591a0__159070(void) asm("func_001591a0");
V159070 func_001904a8__159070(void*) asm("func_001904a8");
void func_0015a260__159070(O159070*, V159070*, f32) asm("func_0015a260");
u32 func_00167f18__159070(u32) asm("func_00167f18");
void func_0015a158__159070(u32, O159070*) asm("func_0015a158");
void func_0015a528__159070(O159070*) asm("func_0015a528");
extern u8 D_0034a9f0[];
void func_00159070(O159070* o)
{
    if (func_001b9d40__159070(o->c) || !func_00190140__159070(D_0034a9f0)) {
        func_001591a0__159070();
    } else {
        V159070 v = func_001904a8__159070(D_0034a9f0);
        func_0015a260__159070(o, &v, 1.0f);
        u32 k = func_00167f18__159070(0);
        if (o->c->vt->f64(o->c)) func_0015a158__159070(k, o);
        func_0015a528__159070(o);
    }
}

// --------------------
struct E1a6a20 { u32 key; u8* buf; };
union U1a6a20 { u8* p; u32 u; };
extern E1a6a20 D_01c6cb30[8];
extern s32 D_01c6cb70;
void* func_001050d8__1a6a20(u32) asm("func_001050d8");
void func_002fd310__1a6a20(void*, u32) asm("func_002fd310");
u8* func_001a6a20(u32 key, u32 n)
{
    s32 i;
    E1a6a20* e;
    u8* b;
    for (i = 0; i < D_01c6cb70; i++) {
        if (D_01c6cb30[i].key == key) {
            D_01c6cb30[i].buf[0] = 1;
            return D_01c6cb30[i].buf;
        }
    }
    n++;
    b = (u8*)func_001050d8__1a6a20(n);
    func_002fd310__1a6a20(b, n);
    e = &D_01c6cb30[D_01c6cb70++];
    e->key = key;
    ((U1a6a20*)&e->buf)->u = (u32)b;
    return b;
}

// --------------------
extern u8* D_01d49960__1c89a8[2] asm("D_01d49960");
extern char D_0036e080[];
s32 func_0019ba60__1c89a8(u8*) asm("func_0019ba60");
void func_001880b0__1c89a8(u8*, char*) asm("func_001880b0");
void func_00102448__1c89a8(u32, u32) asm("func_00102448");
void func_001c9e50__1c89a8(u32) asm("func_001c9e50");
void func_001c9b90__1c89a8(void) asm("func_001c9b90");
void func_001c89a8(u32 t)
{
    if (func_0019ba60__1c89a8(D_01d49960__1c89a8[0])) {
        s32 i;
        func_001880b0__1c89a8(D_01d49960__1c89a8[0] + 768, D_0036e080);
        for (i = 0; i < 2; i++) {
            while (D_01d49960__1c89a8[i]) func_00102448__1c89a8(t, 0);
        }
    }
    func_00102448__1c89a8(t, 2);
    func_001c9e50__1c89a8(t);
    func_001c9b90__1c89a8();
}

// --------------------
struct V1ba340 {
    f32 x, y, z, w;
    V1ba340() {}
    V1ba340& operator=(const V1ba340& o) { if (this != &o) QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct Hit1ba340 { u8 pad[12]; s32 n; V1ba340 pos; };
struct O1ba340 { u32 f0; u32 f4; u8* e; };
u32 func_001a3a78__1ba340(void) asm("func_001a3a78");
u32 func_001de168__1ba340(u32, u32, u32, u32, u32, u32) asm("func_001de168");
void* func_0016bc20__1ba340(u8*, u32, s32) asm("func_0016bc20");
void func_0018a818__1ba340(Hit1ba340*, u8*, void*) asm("func_0018a818");
V1ba340* func_001dc5f8__1ba340(u32) asm("func_001dc5f8");
V1ba340* func_0016c028__1ba340(u8*) asm("func_0016c028");
void func_001ba340(O1ba340* o)
{
    Hit1ba340 h;
    h.n = 0;
    u32 m = func_001de168__1ba340(func_001a3a78__1ba340(), 0, 1, 1, 10002, 0);
    void* nd = func_0016bc20__1ba340(o->e, 8, -1);
    if (nd) {
        func_0018a818__1ba340(&h, o->e, nd);
        *func_001dc5f8__1ba340(m) = h.pos;
    } else {
        *func_001dc5f8__1ba340(m) = *func_0016c028__1ba340(o->e);
    }
}

// --------------------
extern u64 D_0034c710;
extern u8 D_0034c70c;
extern u8 D_0034c6f0[];
void func_00143248__15f548(void) asm("func_00143248");
void func_00160e50__15f548(s32) asm("func_00160e50");
void* func_001de4b0__15f548(void*, s32, void*) asm("func_001de4b0");
s32 func_001dc9e0__15f548(void*) asm("func_001dc9e0");
void func_001dcc48__15f548(void*) asm("func_001dcc48");
void func_0015f548(void)
{
    s32 i;
    u64 one = 1;
    void* p;
    func_00143248__15f548();
    for (i = 0; i < 64; i++) {
        if ((D_0034c710 & (one << i)) != 0) func_00160e50__15f548(i);
    }
    p = 0;
    if (D_0034c70c == 1) {
        s32 j;
        for (j = 0; j < 64; j++) {
            while ((p = func_001de4b0__15f548(D_0034c6f0, j, p)) != 0) {
                if (func_001dc9e0__15f548(p)) func_001dcc48__15f548(p);
            }
        }
    }
}

// --------------------
struct V2e8d08 {
    f32 x, y, z, w;
    V2e8d08() {}
    V2e8d08& operator=(const V2e8d08& o) { if (this != &o) QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct E2e8d08 { u32 f0; u8* e; };
struct Hit2e8d08 { u32 f0; u32 f4; f32 f8; union { s32 n; u8* p; E2e8d08* q; V2e8d08* v; }; V2e8d08 pos; };
extern V2e8d08 D_01e2bf90;
void* func_0016bba8__2e8d08(u8*, u32, u32) asm("func_0016bba8");
void func_0018a818__2e8d08(Hit2e8d08*, u8*, void*) asm("func_0018a818");
V2e8d08* func_0016c028__2e8d08(u8*) asm("func_0016c028");
void func_002e8d08(V2e8d08** out)
{
    Hit2e8d08 h;
    void* nd;
    u8* e = ((E2e8d08*)*out)->e;
    h.n = 0;
    nd = func_0016bba8__2e8d08(e, 0, 0);
    if (nd || (nd = func_0016bba8__2e8d08(e, 1, 0)) != 0) {
        func_0018a818__2e8d08(&h, e, nd);
        D_01e2bf90 = h.pos;
        D_01e2bf90.y -= h.f8 + 30.0f;
    } else {
        D_01e2bf90 = *func_0016c028__2e8d08(e);
    }
    *out = &D_01e2bf90;
}

// --------------------
struct P1a68e0 { u32 a; u32 b; };
struct E1a68e0 { u32 f0; u32 pad[2]; u8 m[28]; u32 f40; };
extern P1a68e0 D_01c6cb20;
extern E1a68e0 D_00350800[6];
void func_001ddd10__1a68e0(void*) asm("func_001ddd10");
void func_001ddd88__1a68e0(void*) asm("func_001ddd88");
static inline void Del1a68e0(E1a68e0* a)
{
    if (a != 0) {
        E1a68e0* p = a + 6;
        E1a68e0* b = a;
    top:
        if (p == b) return;
        --p;
        func_001ddd88__1a68e0(p->m);
        goto top;
    }
}
void wtarget_001a68e0(s32 init, s32 prio, u32, u32) asm("_Z16wtarget_001a68e0jjjj");
void wtarget_001a68e0(s32 init, s32 prio, u32, u32)
{
    if (prio == 0xffff && init == 1) {
        D_01c6cb20.a = 0;
        D_01c6cb20.b = 0;
    }
    if (prio == 0xffff && init == 1) {
        E1a68e0* p = D_00350800;
        s32 n;
        for (n = 5; n != -1; n--) {
            p->f0 = 0;
            func_001ddd10__1a68e0(p->m);
            p->f40 = 0;
            p++;
        }
    }
    if (prio == 0xffff && init == 0) {
        Del1a68e0(D_00350800);
    }
}

// --------------------
struct C102350 { u8 pad[240]; u8 started; u8 pad2[3]; s32 wait; f32 timer; s32 size; u8 stack[1]; };
struct T102350;
struct T102350 { void (*fn)(T102350*); u8 pad[32]; u8* q; u8 pad2[12]; C102350* co; };
extern f32 D_00349e10;
void func_001056e8__102350(u8*) asm("func_001056e8");
s32 func_00105550__102350(u8*) asm("func_00105550");
void func_00105710__102350(void) asm("func_00105710");
void func_001055b8__102350(C102350*) asm("_Z13func_001055b8Pv");
C102350* func_00105728__102350(void) asm("func_00105728");
void func_00102350(T102350* t)
{
    C102350* c;
    s32 r;
    if (t->co == 0) {
        t->fn(t);
        return;
    }
    func_001056e8__102350(t->q + 32);
    r = func_00105550__102350(t->q + 32);
    if (r != 0) {
        if (r == 1) t->fn = 0;
    } else {
        c = t->co;
        if (!c->started) {
            c->started = 1;
            // Switch to the coroutine's own stack (hand-written stack swap).
            asm volatile("move $sp,%0" : : "r"((u8*)t->co + t->co->size + 256));
            t->fn(t);
            func_001055b8__102350(func_00105728__102350());
        } else if (c->wait > 0) {
            c->wait--;
        } else if (c->timer > 0.0f) {
            c->timer -= D_00349e10;
        } else {
            func_001055b8__102350(c);
        }
    }
    func_00105710__102350();
}

// --------------------
struct A105400 { u8 a, b, c; };
struct X105400 { u16 d, e, f; };
extern X105400 D_0032bae4;
extern X105400 D_0032baf4;
extern X105400 D_0032bb04;
extern X105400 D_0032bb14;
extern X105400 D_003a7b0c;
static inline void Init105400(X105400* x, s32 v)
{
    A105400* p = (A105400*)((u8*)x - 4);
    p->a = v; p->b = v; p->c = v; x->d = v; x->e = v; x->f = v;
}
void wtarget_00105400(s32 init, s32 prio, u32, u32) asm("_Z16wtarget_00105400jjjj");
void wtarget_00105400(s32 init, s32 prio, u32, u32)
{
    if (prio == 0xffff && init == 1) Init105400(&D_0032bae4, 0xffff);
    if (prio == 0xffff && init == 1) Init105400(&D_0032baf4, 0xffff);
    if (prio == 0xffff && init == 1) Init105400(&D_0032bb04, 0xffff);
    if (prio == 0xffff && init == 1) Init105400(&D_0032bb14, 0xffff);
    if (prio == 0xffff && init == 1) Init105400(&D_003a7b0c, 0xffff);
}

// --------------------
struct V104640 {
    f32 x, y, z, w;
};
struct C104640 { u32 vt; u32 f4; u8 b8; u8 pad[11]; u32 f20; u32 f24; u32 f28; u32 f32; u32 f36; u32 f40; };
extern V104640 D_003a6a80;
extern V104640 D_003a6a90;
extern V104640 D_003a6aa0;
extern V104640 D_003a6ab0;
extern V104640 D_003a6ac0;
extern V104640 D_003a6ad0;
extern f32 D_003a6ae0;
extern f32 D_003a6ae4;
extern f32 D_003a6ae8;
extern f32 D_003a6aec;
extern C104640 D_0032ba90;
extern u8 D_0032b930[];
static inline void Set104640(V104640* v, f32 a, f32 b, f32 c, f32 d) { v->x = a; v->y = b; v->z = c; v->w = d; }
void wtarget_00104640(s32 init, s32 prio, u32, u32) asm("_Z16wtarget_00104640jjjj");
void wtarget_00104640(s32 init, s32 prio, u32, u32)
{
    if (prio == 0xffff && init == 1) Set104640(&D_003a6a80, 0.0f, 1.0f, 0.0f, 0.0f);
    if (prio == 0xffff && init == 1) Set104640(&D_003a6a90, 0.0f, -1.0f, 0.0f, 0.0f);
    if (prio == 0xffff && init == 1) Set104640(&D_003a6aa0, -1.0f, 0.0f, 0.0f, 0.0f);
    if (prio == 0xffff && init == 1) Set104640(&D_003a6ab0, 1.0f, 0.0f, 0.0f, 0.0f);
    if (prio == 0xffff && init == 1) Set104640(&D_003a6ac0, 0.0f, 0.0f, 1.0f, 0.0f);
    if (prio == 0xffff && init == 1) Set104640(&D_003a6ad0, 0.0f, 0.0f, -1.0f, 0.0f);
    if (prio == 0xffff && init == 1) D_003a6ae0 = 1.5707962f;
    if (prio == 0xffff && init == 1) D_003a6ae4 = -1.5707962f;
    if (prio == 0xffff && init == 1) D_003a6ae8 = -1.5707962f;
    if (prio == 0xffff && init == 1) D_003a6aec = 1.5707962f;
    if (prio == 0xffff && init == 1) {
        D_0032ba90.vt = (u32)D_0032b930;
        D_0032ba90.f4 = 0;
        D_0032ba90.b8 = 71;
        D_0032ba90.f20 = init;
        D_0032ba90.f24 = 160000;
        D_0032ba90.f28 = 0;
        D_0032ba90.f32 = 0;
        D_0032ba90.f36 = 0;
        D_0032ba90.f40 = 12288;
    }
}

// --------------------
// Bind the battle/system table entries (BAR tags) to their owners.
struct BarEnt194a30 { u32 f0; u32 f4; void* data; };
void* func_001b1490__194a30(void*) asm("func_001b1490");
BarEnt194a30* func_00168b88__194a30(void*, s32, s32, s32) asm("func_00168b88");
BarEnt194a30* func_00168b38__194a30(void*, s32, s32) asm("func_00168b38");
void func_00264318__194a30(void*) asm("func_00264318");
extern void* D_0034f248;
extern void* D_0034f24c;
extern void* D_01c61af8;
extern void* D_01c61afc;
void func_00185880__194a30(void*) asm("func_00185880");
void func_00185910__194a30(void*) asm("func_00185910");
void func_00194790__194a30(void*) asm("func_00194790");
void func_0019fe80__194a30(void*) asm("func_0019fe80");
void func_001a5b58__194a30(void*) asm("func_001a5b58");
void func_001a6648__194a30(void*) asm("func_001a6648");
void func_001a8098__194a30(void*) asm("func_001a8098");
void func_001a81e0__194a30(void*) asm("func_001a81e0");
void func_001a8908__194a30(void*) asm("func_001a8908");
void func_001a97e8__194a30(void*) asm("func_001a97e8");
void func_001afa30__194a30(void*) asm("func_001afa30");
void func_001b1e58__194a30(void*) asm("func_001b1e58");
void func_001b6fa0__194a30(void*) asm("func_001b6fa0");
void func_001b8e78__194a30(void*) asm("func_001b8e78");
void func_001c0638__194a30(void*) asm("func_001c0638");
void func_001c09f0__194a30(void*) asm("func_001c09f0");
void func_001c0c70__194a30(void*) asm("func_001c0c70");
void func_001c20d8__194a30(void*) asm("func_001c20d8");
void func_001c2d38__194a30(void*) asm("func_001c2d38");
void func_001c2d78__194a30(void*) asm("func_001c2d78");
void func_001ce1a0__194a30(void*) asm("func_001ce1a0");
void func_001d23d0__194a30(void*) asm("func_001d23d0");
void func_001d30b0__194a30(void*) asm("func_001d30b0");
void func_001d3c08__194a30(void*) asm("func_001d3c08");
void func_001d5030__194a30(void*) asm("func_001d5030");
void func_001d5b68__194a30(void*) asm("func_001d5b68");
void func_001d6cb8__194a30(void*) asm("func_001d6cb8");
void func_001d7970__194a30(void*) asm("func_001d7970");
void func_001d7eb8__194a30(void*) asm("func_001d7eb8");
void func_001db598__194a30(void*) asm("func_001db598");
extern char D_0036cf28[];
extern char D_0036cf30[];
extern char D_0036cf38[];
extern char D_0036cf40[];
extern char D_0036cf48[];
extern char D_0036cf50[];
extern char D_0036cf58[];
extern char D_0036cf60[];
extern char D_0036cf68[];
extern char D_0036cf70[];
extern char D_0036cf78[];
extern char D_0036cf80[];
extern char D_0036cf88[];
extern char D_0036cf90[];
extern char D_0036cf98[];
extern char D_0036cfa0[];
extern char D_0036cfa8[];
extern char D_0036cfb0[];
extern char D_0036cfb8[];
extern char D_0036cfc0[];
extern char D_0036cfc8[];
extern char D_0036cfd0[];
extern char D_0036cfd8[];
extern char D_0036cfe0[];
extern char D_0036cfe8[];
extern char D_0036cff0[];
extern char D_0036cff8[];
extern char D_0036d000[];
extern char D_0036d008[];
extern char D_0036d010[];
static inline s32 Tag194a30(char* s) { return s[0] | (s[1] << 8) | (s[2] << 16) | (s[3] << 24); }
void func_00194a30(void)
{
    void* b;
    BarEnt194a30* e;
    D_01c61af8 = b = func_001b1490__194a30(D_0034f248);
    func_001ce1a0__194a30(func_00168b88__194a30(b, 1, Tag194a30(D_0036cf28), 0)->data);
    func_001d23d0__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cf30), 0)->data);
    func_001b8e78__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cf38), 0)->data);
    func_00185880__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cf40), 0)->data);
    func_00185910__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cf48), 0)->data);
    func_00194790__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cf50), 0)->data);
    func_001a8098__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cf58), 0)->data);
    func_001a81e0__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cf60), 0)->data);
    func_001a8908__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cf68), 0)->data);
    func_001a97e8__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cf70), 0)->data);
    func_001b1e58__194a30(func_00168b88__194a30(b, 25, Tag194a30(D_0036cf78), 0)->data);
    e = func_00168b38__194a30(b, 41, 0);
    if (e && e->data) func_00264318__194a30(e->data);
    func_001c2d38__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cf80), 0)->data);
    func_001d30b0__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cf88), 0)->data);
    D_01c61afc = b = func_001b1490__194a30(D_0034f24c);
    func_0019fe80__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cf90), 0)->data);
    func_001d7eb8__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cf98), 0)->data);
    func_001db598__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cfa0), 0)->data);
    func_001a5b58__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cfa8), 0)->data);
    func_001afa30__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cfb0), 0)->data);
    func_001b6fa0__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cfb8), 0)->data);
    func_001c0638__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cfc0), 0)->data);
    func_001c09f0__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cfc8), 0)->data);
    func_001c0c70__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cfd0), 0)->data);
    func_001c20d8__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cfd8), 0)->data);
    func_001c2d78__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cfe0), 0)->data);
    func_001d3c08__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cfe8), 0)->data);
    func_001d6cb8__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cff0), 0)->data);
    func_001a6648__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036cff8), 0)->data);
    func_001d5030__194a30(func_00168b88__194a30(b, 1, Tag194a30(D_0036d000), 0)->data);
    func_001d5b68__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036d008), 0)->data);
    func_001d7970__194a30(func_00168b88__194a30(b, 2, Tag194a30(D_0036d010), 0)->data);
}

// --------------------
// Player constructor body: sets up state, then creates the per-character controller.
struct Pair10b978 { u32 a; u32 b; };
struct Mdl10b978 { u8 pad[78]; u16 id; };
struct Pl10b978 {
    u32 vt; u32 f4; Mdl10b978* mdl; u8 pad0[2748 - 12]; u32 flags2; u8 pad1[2896 - 2752];
    s32 f2896; u32 f2900; u32 f2904; u32 f2908; void* ctl; Pair10b978 pair; s32 kind; s32 pad; u32 f2932;
    u32 f2936; u32 flags; u8 pad2[3120 - 2944]; u8 m3120[8]; u8 m3128[40]; u32 f3168; u32 f3172;
    u8 pad3[3280 - 3176]; s32 f3280; u32 f3284[7]; u8 pad4[3324 - 3312]; u32 f3324;
};
extern u8 D_00345c08[];
extern s32 D_00341800[];
extern const Pair10b978 D_0036a440;
extern const Pair10b978 D_0036a448;
extern const Pair10b978 D_0036a450;
void func_0017d968__10b978(Pl10b978*) asm("func_0017d968");
void func_00190128__10b978(void*) asm("func_00190128");
void func_0017bf40__10b978(void*) asm("func_0017bf40");
void func_0010eee8__10b978(Pl10b978*) asm("func_0010eee8");
Pl10b978* func_0017df58__10b978(s32) asm("func_0017df58");
s32 func_0016a070__10b978(Pl10b978*) asm("func_0016a070");
void* func_001050d8__10b978(u32) asm("func_001050d8");
s32 func_00112720__10b978(Pl10b978*) asm("func_00112720");
void func_001136b8__10b978(void*) asm("func_001136b8");
void func_001133f8__10b978(Pl10b978*) asm("func_001133f8");
#define CTL10b978(fn) void fn##__10b978(void*, Pl10b978*, void*) asm(#fn);
CTL10b978(func_00113648) CTL10b978(func_001148d0) CTL10b978(func_001147b8) CTL10b978(func_001151f8)
CTL10b978(func_00114ff8) CTL10b978(func_00114d48) CTL10b978(func_00114ea0) CTL10b978(func_00114af8)
CTL10b978(func_00115738) CTL10b978(func_001154c8) CTL10b978(func_00115620) CTL10b978(func_00119c40)
CTL10b978(func_00117c28) CTL10b978(func_0011a6b0) CTL10b978(func_0011a490) CTL10b978(func_0011a2a8)
CTL10b978(func_00114c30) CTL10b978(func_00115350)
static inline void* Tab10b978(s32 k) { return (u8*)D_00341800 + D_00341800[k]; }
#define NEW10b978(sz, fn) { void* c = func_001050d8__10b978(sz); fn##__10b978(c, p, Tab10b978(p->kind)); p->ctl = c; }
static inline void CtorM10b978(u8* m) { func_00190128__10b978(m + 8); func_0017bf40__10b978(m); }
void func_0010b978(Pl10b978* p)
{
    func_0017d968__10b978(p);
    p->vt = (u32)D_00345c08;
    CtorM10b978(p->m3120);
    p->f2896 = 0;
    p->pair.a = D_0036a440.a;
    p->pair.b = D_0036a440.b;
    p->flags = 0x10000000;
    p->f3280 = -1;
    p->f2900 = 0;
    p->f2904 = 0;
    p->f2908 = 0;
    p->f2936 = 0;
    p->f3168 = 0;
    p->f3172 = 0;
    func_0010eee8__10b978(p);
    p->f3284[0] = 0; p->f3284[1] = 0; p->f3284[2] = 0; p->f3284[3] = 0;
    p->f3284[4] = 0; p->f3284[5] = 0; p->f3284[6] = 0;
    p->kind = 0;
    p->f3324 = 0;
    if (func_0017df58__10b978(0) == p) p->pad = 1;
    else if (func_0017df58__10b978(1) == p) p->pad = 2;
    s32 id = func_0016a070__10b978(p);
    p->ctl = 0;
    switch (id) {
    case 1: case 4: case 14:
        break;
    case 2:
        if (p->mdl->id == 18) p->kind = 12;
        else p->kind = 0;
        NEW10b978(20, func_001147b8)
        break;
    case 3:
        if (p->mdl->id == 21) p->kind = 13;
        else p->kind = 1;
        NEW10b978(48, func_001148d0)
        break;
    case 5: p->kind = 2; NEW10b978(20, func_00114af8) break;
    case 6: p->kind = 4; NEW10b978(20, func_00114d48) break;
    case 7: p->kind = 5; NEW10b978(20, func_00114ea0) break;
    case 8: p->kind = 6; NEW10b978(20, func_00114ff8) break;
    case 9: p->kind = 7; NEW10b978(20, func_001151f8) break;
    case 10: p->kind = 8; NEW10b978(20, func_00115350) break;
    case 11: p->kind = 9; NEW10b978(20, func_001154c8) break;
    case 12: p->kind = 10; NEW10b978(20, func_00115620) break;
    case 13: p->kind = 11; NEW10b978(20, func_00115738) break;
    case 15: p->kind = 3; NEW10b978(20, func_00114c30) break;
    case 200: {
        p->kind = 14;
        void* c = func_001050d8__10b978(1936);
        func_00117c28__10b978(c, p, Tab10b978(p->kind));
        p->ctl = c;
        p->pair.a = D_0036a448.a;
        p->pair.b = D_0036a448.b;
        p->flags |= 2;
        break;
    }
    case 201: p->kind = 15; { void* c = func_001050d8__10b978(24); func_00119c40__10b978(c, p, Tab10b978(p->kind)); p->ctl = c; p->flags |= 0x800; } break;
    case 202: p->kind = 16; { void* c = func_001050d8__10b978(20); func_0011a2a8__10b978(c, p, Tab10b978(p->kind)); p->ctl = c; p->flags |= 0x800; } break;
    case 203: p->kind = 17; { void* c = func_001050d8__10b978(20); func_0011a490__10b978(c, p, Tab10b978(p->kind)); p->ctl = c; p->flags |= 0x802; } break;
    case 204: {
        p->kind = 18;
        void* c = func_001050d8__10b978(80);
        func_0011a6b0__10b978(c, p, Tab10b978(p->kind));
        p->ctl = c;
        p->pair.a = D_0036a450.a;
        p->pair.b = D_0036a450.b;
        func_001133f8__10b978(p);
        break;
    }
    default: {
        void* c = func_001050d8__10b978(20);
        func_00113648__10b978(c, p, Tab10b978(0));
        p->ctl = c;
        break;
    }
    }
    if (func_00112720__10b978(p)) p->flags2 |= 2;
    func_001136b8__10b978(p->ctl);
}

// --------------------
// Player constructor body: sets up state, then creates the per-character controller.
struct Pair10c078 { u32 a; u32 b; };
struct Mdl10c078 { u8 pad[78]; u16 id; };
struct Pl10c078 {
    u32 vt; u32 f4; Mdl10c078* mdl; u8 pad0[2748 - 12]; u32 flags2; u8 pad1[2896 - 2752];
    s32 f2896; u32 f2900; u32 f2904; u32 f2908; void* ctl; Pair10c078 pair; s32 kind; s32 pad; u32 f2932;
    u32 f2936; u32 flags; u8 pad2[3120 - 2944]; u8 m3120[8]; u8 m3128[40]; u32 f3168; u32 f3172;
    u8 pad3[3280 - 3176]; s32 f3280; u32 f3284[7]; u8 pad4[3324 - 3312]; u32 f3324;
};
extern u8 D_00345c08[];
extern s32 D_00341800[];
extern const Pair10c078 D_0036a440_x11763 asm("D_0036a440");
extern const Pair10c078 D_0036a448_x11764 asm("D_0036a448");
extern const Pair10c078 D_0036a450_x11765 asm("D_0036a450");
void func_0017d968__10c078(Pl10c078*) asm("func_0017d968");
void func_00190128__10c078(void*) asm("func_00190128");
void func_0017bf40__10c078(void*) asm("func_0017bf40");
void func_0010eee8__10c078(Pl10c078*) asm("func_0010eee8");
Pl10c078* func_0017df58__10c078(s32) asm("func_0017df58");
s32 func_0016a070__10c078(Pl10c078*) asm("func_0016a070");
void* func_001050d8__10c078(u32) asm("func_001050d8");
s32 func_00112720__10c078(Pl10c078*) asm("func_00112720");
void func_001136b8__10c078(void*) asm("func_001136b8");
void func_001133f8__10c078(Pl10c078*) asm("func_001133f8");
#define CTL10c078(fn) void fn##__10c078(void*, Pl10c078*, void*) asm(#fn);
CTL10c078(func_00113648) CTL10c078(func_001148d0) CTL10c078(func_001147b8) CTL10c078(func_001151f8)
CTL10c078(func_00114ff8) CTL10c078(func_00114d48) CTL10c078(func_00114ea0) CTL10c078(func_00114af8)
CTL10c078(func_00115738) CTL10c078(func_001154c8) CTL10c078(func_00115620) CTL10c078(func_00119c40)
CTL10c078(func_00117c28) CTL10c078(func_0011a6b0) CTL10c078(func_0011a490) CTL10c078(func_0011a2a8)
CTL10c078(func_00114c30) CTL10c078(func_00115350)
static inline void* Tab10c078(s32 k) { return (u8*)D_00341800 + D_00341800[k]; }
#define NEW10c078(sz, fn) { void* c = func_001050d8__10c078(sz); fn##__10c078(c, p, Tab10c078(p->kind)); p->ctl = c; }
static inline void CtorM10c078(u8* m) { func_00190128__10c078(m + 8); func_0017bf40__10c078(m); }
void func_0010c078(Pl10c078* p)
{
    func_0017d968__10c078(p);
    p->vt = (u32)D_00345c08;
    CtorM10c078(p->m3120);
    p->f2896 = 0;
    p->pair.a = D_0036a440_x11763.a;
    p->pair.b = D_0036a440_x11763.b;
    p->flags = 0x10000000;
    p->f3280 = -1;
    p->f2900 = 0;
    p->f2904 = 0;
    p->f2908 = 0;
    p->f2936 = 0;
    p->f3168 = 0;
    p->f3172 = 0;
    func_0010eee8__10c078(p);
    p->f3284[0] = 0; p->f3284[1] = 0; p->f3284[2] = 0; p->f3284[3] = 0;
    p->f3284[4] = 0; p->f3284[5] = 0; p->f3284[6] = 0;
    p->kind = 0;
    p->f3324 = 0;
    if (func_0017df58__10c078(0) == p) p->pad = 1;
    else if (func_0017df58__10c078(1) == p) p->pad = 2;
    s32 id = func_0016a070__10c078(p);
    p->ctl = 0;
    switch (id) {
    case 1: case 4: case 14:
        break;
    case 2:
        if (p->mdl->id == 18) p->kind = 12;
        else p->kind = 0;
        NEW10c078(20, func_001147b8)
        break;
    case 3:
        if (p->mdl->id == 21) p->kind = 13;
        else p->kind = 1;
        NEW10c078(48, func_001148d0)
        break;
    case 5: p->kind = 2; NEW10c078(20, func_00114af8) break;
    case 6: p->kind = 4; NEW10c078(20, func_00114d48) break;
    case 7: p->kind = 5; NEW10c078(20, func_00114ea0) break;
    case 8: p->kind = 6; NEW10c078(20, func_00114ff8) break;
    case 9: p->kind = 7; NEW10c078(20, func_001151f8) break;
    case 10: p->kind = 8; NEW10c078(20, func_00115350) break;
    case 11: p->kind = 9; NEW10c078(20, func_001154c8) break;
    case 12: p->kind = 10; NEW10c078(20, func_00115620) break;
    case 13: p->kind = 11; NEW10c078(20, func_00115738) break;
    case 15: p->kind = 3; NEW10c078(20, func_00114c30) break;
    case 200: {
        p->kind = 14;
        void* c = func_001050d8__10c078(1936);
        func_00117c28__10c078(c, p, Tab10c078(p->kind));
        p->ctl = c;
        p->pair.a = D_0036a448_x11764.a;
        p->pair.b = D_0036a448_x11764.b;
        p->flags |= 2;
        break;
    }
    case 201: p->kind = 15; { void* c = func_001050d8__10c078(24); func_00119c40__10c078(c, p, Tab10c078(p->kind)); p->ctl = c; p->flags |= 0x800; } break;
    case 202: p->kind = 16; { void* c = func_001050d8__10c078(20); func_0011a2a8__10c078(c, p, Tab10c078(p->kind)); p->ctl = c; p->flags |= 0x800; } break;
    case 203: p->kind = 17; { void* c = func_001050d8__10c078(20); func_0011a490__10c078(c, p, Tab10c078(p->kind)); p->ctl = c; p->flags |= 0x802; } break;
    case 204: {
        p->kind = 18;
        void* c = func_001050d8__10c078(80);
        func_0011a6b0__10c078(c, p, Tab10c078(p->kind));
        p->ctl = c;
        p->pair.a = D_0036a450_x11765.a;
        p->pair.b = D_0036a450_x11765.b;
        func_001133f8__10c078(p);
        break;
    }
    default: {
        void* c = func_001050d8__10c078(20);
        func_00113648__10c078(c, p, Tab10c078(0));
        p->ctl = c;
        break;
    }
    }
    if (func_00112720__10c078(p)) p->flags2 |= 2;
    func_001136b8__10c078(p->ctl);
}

// --------------------
// newlib _malloc_r (dlmalloc 2.6.x mALLOc; EE: 64-bit long, MALLOC_ALIGN 16).
typedef struct MChunk2fd680 MChunk2fd680;
struct MChunk2fd680 { u32 prev_size; u32 size; MChunk2fd680* fd; MChunk2fd680* bk; };
typedef MChunk2fd680* mchunkptr2fd680;
extern u8 D_00365c50[];
void func_002fded8__2fd680(void*) asm("func_002fded8");
void func_002fdf30__2fd680(void*) asm("func_002fdf30");
void func_002fd428(void*, u32);
#define M_SIZE_SZ 4
#define M_ALIGN_MASK 15
#define M_MINSIZE 16
#define M_PREV_INUSE 1
#define M_SIZE_BITS 3
#define M_MAX_SMALLBIN 63
#define M_MAX_SMALLBIN_SIZE 512
#define M_SMALLBIN_WIDTH 8
#define M_BINBLOCKWIDTH 4
#define bin_at(i) ((mchunkptr2fd680)(D_00365c50 + 8 * (i)))
#define next_bin(b) ((mchunkptr2fd680)((char*)(b) + 8))
#define prev_bin(b) ((mchunkptr2fd680)((char*)(b) - 8))
#define first(b) ((b)->fd)
#define last(b) ((b)->bk)
#define top (bin_at(0)->fd)
#define last_remainder (bin_at(1))
#define binblocks (bin_at(0)->size)
#define chunksize(p) ((p)->size & ~(M_SIZE_BITS))
#define chunk2mem(p) ((void*)((char*)(p) + 2 * M_SIZE_SZ))
#define chunk_at_offset(p, s) ((mchunkptr2fd680)(((char*)(p)) + (s)))
#define set_head(p, s) ((p)->size = (s))
#define set_foot(p, s) (((mchunkptr2fd680)((char*)(p) + (s)))->prev_size = (s))
#define set_inuse_bit_at_offset(p, s) (((mchunkptr2fd680)(((char*)(p)) + (s)))->size |= M_PREV_INUSE)
#define request2size(req) (((long)((req) + (M_SIZE_SZ + M_ALIGN_MASK)) < (long)(M_MINSIZE + M_ALIGN_MASK)) ? M_MINSIZE : \
    (((req) + (M_SIZE_SZ + M_ALIGN_MASK)) & ~(M_ALIGN_MASK)))
#define is_small_request(nb) (nb < M_MAX_SMALLBIN_SIZE - M_SMALLBIN_WIDTH)
#define smallbin_index(sz) (((unsigned long)(sz)) >> 3)
#define bin_index(sz) \
(((((unsigned long)(sz)) >> 9) ==    0) ?       (((unsigned long)(sz)) >>  3): \
 ((((unsigned long)(sz)) >> 9) <=    4) ?  56 + (((unsigned long)(sz)) >>  6): \
 ((((unsigned long)(sz)) >> 9) <=   20) ?  91 + (((unsigned long)(sz)) >>  9): \
 ((((unsigned long)(sz)) >> 9) <=   84) ? 110 + (((unsigned long)(sz)) >> 12): \
 ((((unsigned long)(sz)) >> 9) <=  340) ? 119 + (((unsigned long)(sz)) >> 15): \
 ((((unsigned long)(sz)) >> 9) <= 1364) ? 124 + (((unsigned long)(sz)) >> 18): \
                                          126)
#define idx2binblock(ix) ((unsigned long)1 << (ix / M_BINBLOCKWIDTH))
#define mark_binblock(ii) (binblocks |= idx2binblock(ii))
#define unlink(P, BK, FD) { BK = P->bk; FD = P->fd; FD->bk = BK; BK->fd = FD; }
#define link_last_remainder(P) { last_remainder->fd = last_remainder->bk = P; P->fd = P->bk = last_remainder; }
#define clear_last_remainder (last_remainder->fd = last_remainder->bk = last_remainder)
#define long_sub_size_t(x, y) (((x) < (y)) ? -(long)((y) - (x)) : (long)((x) - (y)))
#define frontlink(P, S, IDX, BK, FD) \
{ \
  if (S < M_MAX_SMALLBIN_SIZE) \
  { \
    IDX = smallbin_index(S); \
    mark_binblock(IDX); \
    BK = bin_at(IDX); \
    FD = BK->fd; \
    P->bk = BK; \
    P->fd = FD; \
    FD->bk = BK->fd = P; \
  } \
  else \
  { \
    IDX = bin_index(S); \
    BK = bin_at(IDX); \
    FD = BK->fd; \
    if (FD == BK) mark_binblock(IDX); \
    else \
    { \
      while (FD != BK && S < chunksize(FD)) FD = FD->fd; \
      BK = FD->bk; \
    } \
    P->bk = BK; \
    P->fd = FD; \
    FD->bk = BK->fd = P; \
  } \
}
void* wtarget_002fd680(void* reent_ptr, u32 bytes) asm("_Z16wtarget_002fd680jjjj");
void* wtarget_002fd680(void* reent_ptr, u32 bytes)
{
  mchunkptr2fd680 victim;
  u32 victim_size;
  int idx;
  mchunkptr2fd680 bin;
  mchunkptr2fd680 remainder;
  long remainder_size;
  int remainder_index;
  unsigned long block;
  int startidx;
  mchunkptr2fd680 fwd;
  mchunkptr2fd680 bck;
  mchunkptr2fd680 q;

  u32 nb = request2size(bytes);

  func_002fded8__2fd680(reent_ptr);

  if (is_small_request(nb))
  {
    idx = smallbin_index(nb);
    q = bin_at(idx);
    victim = last(q);
    if (victim != q)
    {
      victim_size = chunksize(victim);
      unlink(victim, bck, fwd);
      set_inuse_bit_at_offset(victim, victim_size);
      func_002fdf30__2fd680(reent_ptr);
      return chunk2mem(victim);
    }
    idx += 2;
  }
  else
  {
    idx = bin_index(nb);
    bin = bin_at(idx);
    for (victim = last(bin); victim != bin; victim = victim->bk)
    {
      victim_size = chunksize(victim);
      remainder_size = long_sub_size_t(victim_size, nb);
      if (remainder_size >= (long)M_MINSIZE)
      {
        --idx;
        break;
      }
      else if (remainder_size >= 0)
      {
        unlink(victim, bck, fwd);
        set_inuse_bit_at_offset(victim, victim_size);
        func_002fdf30__2fd680(reent_ptr);
        return chunk2mem(victim);
      }
    }
    ++idx;
  }

  if ((victim = last_remainder->fd) != last_remainder)
  {
    victim_size = chunksize(victim);
    remainder_size = long_sub_size_t(victim_size, nb);
    if (remainder_size >= (long)M_MINSIZE)
    {
      remainder = chunk_at_offset(victim, nb);
      set_head(victim, nb | M_PREV_INUSE);
      link_last_remainder(remainder);
      set_head(remainder, remainder_size | M_PREV_INUSE);
      set_foot(remainder, remainder_size);
      func_002fdf30__2fd680(reent_ptr);
      return chunk2mem(victim);
    }
    clear_last_remainder;
    if (remainder_size >= 0)
    {
      set_inuse_bit_at_offset(victim, victim_size);
      func_002fdf30__2fd680(reent_ptr);
      return chunk2mem(victim);
    }
    frontlink(victim, victim_size, remainder_index, bck, fwd);
  }

  if ((block = idx2binblock(idx)) <= binblocks)
  {
    if ((block & binblocks) == 0)
    {
      idx = (idx & ~(M_BINBLOCKWIDTH - 1)) + M_BINBLOCKWIDTH;
      block <<= 1;
      while ((block & binblocks) == 0)
      {
        idx += M_BINBLOCKWIDTH;
        block <<= 1;
      }
    }
    for (;;)
    {
      startidx = idx;
      q = bin = bin_at(idx);
      do
      {
        for (victim = last(bin); victim != bin; victim = victim->bk)
        {
          victim_size = chunksize(victim);
          remainder_size = long_sub_size_t(victim_size, nb);
          if (remainder_size >= (long)M_MINSIZE)
          {
            remainder = chunk_at_offset(victim, nb);
            set_head(victim, nb | M_PREV_INUSE);
            unlink(victim, bck, fwd);
            link_last_remainder(remainder);
            set_head(remainder, remainder_size | M_PREV_INUSE);
            set_foot(remainder, remainder_size);
            func_002fdf30__2fd680(reent_ptr);
            return chunk2mem(victim);
          }
          else if (remainder_size >= 0)
          {
            set_inuse_bit_at_offset(victim, victim_size);
            unlink(victim, bck, fwd);
            func_002fdf30__2fd680(reent_ptr);
            return chunk2mem(victim);
          }
        }
        bin = next_bin(bin);
        if (idx < M_MAX_SMALLBIN)
        {
          bin = next_bin(bin);
          ++idx;
        }
      } while ((++idx & (M_BINBLOCKWIDTH - 1)) != 0);

      do
      {
        if ((startidx & (M_BINBLOCKWIDTH - 1)) == 0)
        {
          binblocks &= ~block;
          break;
        }
        --startidx;
        q = prev_bin(q);
      } while (first(q) == q);

      if ((block <<= 1) <= binblocks && (block != 0))
      {
        while ((block & binblocks) == 0)
        {
          idx += M_BINBLOCKWIDTH;
          block <<= 1;
        }
      }
      else
        break;
    }
  }

  remainder_size = long_sub_size_t(chunksize(top), nb);
  if (chunksize(top) < nb || remainder_size < (long)M_MINSIZE)
  {
    func_002fd428(reent_ptr, nb);
    remainder_size = long_sub_size_t(chunksize(top), nb);
    if (chunksize(top) < nb || remainder_size < (long)M_MINSIZE)
    {
      func_002fdf30__2fd680(reent_ptr);
      return 0;
    }
  }

  victim = top;
  set_head(victim, nb | M_PREV_INUSE);
  top = chunk_at_offset(victim, nb);
  set_head(top, remainder_size | M_PREV_INUSE);
  func_002fdf30__2fd680(reent_ptr);
  return chunk2mem(victim);
}
#undef M_SIZE_SZ
#undef M_ALIGN_MASK
#undef M_MINSIZE
#undef M_PREV_INUSE
#undef M_SIZE_BITS
#undef M_MAX_SMALLBIN
#undef M_MAX_SMALLBIN_SIZE
#undef M_SMALLBIN_WIDTH
#undef M_BINBLOCKWIDTH
#undef bin_at
#undef next_bin
#undef prev_bin
#undef first
#undef last
#undef top
#undef last_remainder
#undef binblocks
#undef chunksize
#undef chunk2mem
#undef chunk_at_offset
#undef set_head
#undef set_foot
#undef set_inuse_bit_at_offset
#undef request2size
#undef is_small_request
#undef smallbin_index
#undef bin_index
#undef idx2binblock
#undef mark_binblock
#undef unlink
#undef link_last_remainder
#undef clear_last_remainder
#undef long_sub_size_t
#undef frontlink

// --------------------
// Copy a context block field by field using a lazily built table of field sizes.
struct Ctx318290 { void* fld[177]; u8 pad[708 - 177 * 4]; s32 f708; u8 pad2[24]; s64 f736; };
extern u8 D_01e4c7b8_x12158[176] asm("D_01e4c7b8");
extern u8 D_01e4c7b9;
extern u8 D_01e4c7ba;
extern u8 D_01e4c7bb;
extern u8 D_01e4c7bc;
extern u8 D_01e4c7bd;
extern u8 D_01e4c7be;
extern u8 D_01e4c7bf;
extern u8 D_01e4c7c0;
extern u8 D_01e4c7c1;
extern u8 D_01e4c7c2;
extern u8 D_01e4c7c3;
extern u8 D_01e4c7c4;
extern u8 D_01e4c7c5;
extern u8 D_01e4c7c6;
extern u8 D_01e4c7c7;
extern u8 D_01e4c7c8;
extern u8 D_01e4c7c9;
extern u8 D_01e4c7ca;
extern u8 D_01e4c7cb;
extern u8 D_01e4c7cc;
extern u8 D_01e4c7cd;
extern u8 D_01e4c7ce;
extern u8 D_01e4c7cf;
extern u8 D_01e4c7d0;
extern u8 D_01e4c7d1;
extern u8 D_01e4c7d2;
extern u8 D_01e4c7d3;
extern u8 D_01e4c7d4;
extern u8 D_01e4c7d5;
extern u8 D_01e4c7d6;
extern u8 D_01e4c7d7;
extern u8 D_01e4c7d8;
extern u8 D_01e4c7d9;
extern u8 D_01e4c7da;
extern u8 D_01e4c7db;
extern u8 D_01e4c7dc;
extern u8 D_01e4c7dd;
extern u8 D_01e4c7de;
extern u8 D_01e4c7df;
extern u8 D_01e4c7e0;
extern u8 D_01e4c7e1;
extern u8 D_01e4c7e2;
extern u8 D_01e4c7e3;
extern u8 D_01e4c7e4;
extern u8 D_01e4c7e5;
extern u8 D_01e4c7e6;
extern u8 D_01e4c7e7;
extern u8 D_01e4c7e8;
extern u8 D_01e4c7e9;
extern u8 D_01e4c7ea;
extern u8 D_01e4c7eb;
extern u8 D_01e4c7ec;
extern u8 D_01e4c7ed;
extern u8 D_01e4c7ee;
extern u8 D_01e4c7ef;
extern u8 D_01e4c7f0;
extern u8 D_01e4c7f1;
extern u8 D_01e4c7f2;
extern u8 D_01e4c7f3;
extern u8 D_01e4c7f4;
extern u8 D_01e4c7f5;
extern u8 D_01e4c7f6;
extern u8 D_01e4c7f7;
extern u8 D_01e4c7f8;
extern u8 D_01e4c7f9;
extern u8 D_01e4c7fa;
extern u8 D_01e4c7fb;
extern u8 D_01e4c7fc;
extern u8 D_01e4c7fd;
extern u8 D_01e4c7fe;
extern u8 D_01e4c7ff;
extern u8 D_01e4c800;
extern u8 D_01e4c801;
extern u8 D_01e4c802;
extern u8 D_01e4c803;
extern u8 D_01e4c804;
extern u8 D_01e4c805;
extern u8 D_01e4c806;
extern u8 D_01e4c807;
extern u8 D_01e4c808;
extern u8 D_01e4c809;
extern u8 D_01e4c80a;
extern u8 D_01e4c80b;
extern u8 D_01e4c80c;
extern u8 D_01e4c80d;
extern u8 D_01e4c80e;
extern u8 D_01e4c80f;
extern u8 D_01e4c810;
extern u8 D_01e4c811;
extern u8 D_01e4c812;
extern u8 D_01e4c813;
extern u8 D_01e4c814;
extern u8 D_01e4c815;
extern u8 D_01e4c816;
extern u8 D_01e4c817;
extern u8 D_01e4c818;
extern u8 D_01e4c819;
extern u8 D_01e4c81a;
extern u8 D_01e4c81b;
extern u8 D_01e4c81c;
extern u8 D_01e4c81d;
extern u8 D_01e4c81e;
extern u8 D_01e4c81f;
extern u8 D_01e4c820;
extern u8 D_01e4c821;
extern u8 D_01e4c822;
extern u8 D_01e4c823;
extern u8 D_01e4c824;
extern u8 D_01e4c825;
extern u8 D_01e4c826;
extern u8 D_01e4c827;
extern u8 D_01e4c828;
extern u8 D_01e4c829;
extern u8 D_01e4c82a;
extern u8 D_01e4c82b;
extern u8 D_01e4c82c;
extern u8 D_01e4c82d;
extern u8 D_01e4c82e;
extern u8 D_01e4c82f;
extern u8 D_01e4c830;
extern u8 D_01e4c831;
extern u8 D_01e4c832;
extern u8 D_01e4c833;
extern u8 D_01e4c834;
extern u8 D_01e4c835;
extern u8 D_01e4c836;
extern u8 D_01e4c837;
extern u8 D_01e4c838;
extern u8 D_01e4c839;
extern u8 D_01e4c83a;
extern u8 D_01e4c83b;
extern u8 D_01e4c83c;
extern u8 D_01e4c83d;
extern u8 D_01e4c83e;
extern u8 D_01e4c83f;
extern u8 D_01e4c840;
extern u8 D_01e4c841;
extern u8 D_01e4c842;
extern u8 D_01e4c843;
extern u8 D_01e4c844;
extern u8 D_01e4c845;
extern u8 D_01e4c846;
extern u8 D_01e4c847;
extern u8 D_01e4c848;
extern u8 D_01e4c849;
extern u8 D_01e4c84a;
extern u8 D_01e4c84b;
extern u8 D_01e4c84c;
extern u8 D_01e4c84d;
extern u8 D_01e4c84e;
extern u8 D_01e4c84f;
extern u8 D_01e4c850;
extern u8 D_01e4c851;
extern u8 D_01e4c852;
extern u8 D_01e4c853;
extern u8 D_01e4c854;
extern u8 D_01e4c855;
extern u8 D_01e4c856;
extern u8 D_01e4c857;
extern u8 D_01e4c858;
extern u8 D_01e4c859;
extern u8 D_01e4c85a;
extern u8 D_01e4c85b;
extern u8 D_01e4c85c;
extern u8 D_01e4c85d;
extern u8 D_01e4c85e;
extern u8 D_01e4c85f;
extern u8 D_01e4c860;
extern u8 D_01e4c861;
extern u8 D_01e4c862;
extern u8 D_01e4c863;
extern u8 D_01e4c864;
extern u8 D_01e4c865;
extern u8 D_01e4c866;
extern u8 D_01e4c867;
extern s32 D_00369d50;
s32 func_0030edb0__318290(void) asm("func_0030edb0");
void func_0030ee00__318290(void) asm("func_0030ee00");
extern u8 D_003191f0[];
void func_002fdd68__318290(void*, void*, u32) asm("func_002fdd68");
s64 func_00318290(Ctx318290* dst, Ctx318290* src)
{
    s32 first = 0;
    s32 r = func_0030edb0__318290();
    long i;
    if (D_00369d50 == 0) {
        D_00369d50 = 1;
        first = 1;
    }
    if (r) func_0030ee00__318290();
    // Called through a computed address (jalr in the original), not a direct jal.
    if (first) ((void (*)(void))(D_003191f0 + 8))();
    if (D_01e4c7b8_x12158[0] == 0) {
        D_01e4c7b8_x12158[0] = 8;
        D_01e4c7b9 = 8;
        D_01e4c7ba = 8;
        D_01e4c7bb = 8;
        D_01e4c7bc = 8;
        D_01e4c7bd = 8;
        D_01e4c7be = 8;
        D_01e4c7bf = 8;
        D_01e4c7c0 = 8;
        D_01e4c7c1 = 8;
        D_01e4c7c2 = 8;
        D_01e4c7c3 = 8;
        D_01e4c7c4 = 8;
        D_01e4c7c5 = 8;
        D_01e4c7c6 = 8;
        D_01e4c7c7 = 8;
        D_01e4c7c8 = 8;
        D_01e4c7c9 = 8;
        D_01e4c7ca = 8;
        D_01e4c7cb = 8;
        D_01e4c7cc = 8;
        D_01e4c7cd = 8;
        D_01e4c7ce = 8;
        D_01e4c7cf = 8;
        D_01e4c7d0 = 8;
        D_01e4c7d1 = 8;
        D_01e4c7d2 = 8;
        D_01e4c7d3 = 8;
        D_01e4c7d4 = 8;
        D_01e4c7d5 = 8;
        D_01e4c7d6 = 8;
        D_01e4c7d7 = 8;
        D_01e4c7d8 = 4;
        D_01e4c7d9 = 4;
        D_01e4c7da = 4;
        D_01e4c7db = 4;
        D_01e4c7dc = 4;
        D_01e4c7dd = 4;
        D_01e4c7de = 4;
        D_01e4c7df = 4;
        D_01e4c7e0 = 4;
        D_01e4c7e1 = 4;
        D_01e4c7e2 = 4;
        D_01e4c7e3 = 4;
        D_01e4c7e4 = 4;
        D_01e4c7e5 = 4;
        D_01e4c7e6 = 4;
        D_01e4c7e7 = 4;
        D_01e4c7e8 = 4;
        D_01e4c7e9 = 4;
        D_01e4c7ea = 4;
        D_01e4c7eb = 4;
        D_01e4c7ec = 4;
        D_01e4c7ed = 4;
        D_01e4c7ee = 4;
        D_01e4c7ef = 4;
        D_01e4c7f0 = 4;
        D_01e4c7f1 = 4;
        D_01e4c7f2 = 4;
        D_01e4c7f3 = 4;
        D_01e4c7f4 = 4;
        D_01e4c7f5 = 4;
        D_01e4c7f6 = 4;
        D_01e4c7f7 = 4;
        D_01e4c7f8 = 4;
        D_01e4c7f9 = 4;
        D_01e4c7fa = 4;
        D_01e4c7fb = 4;
        D_01e4c7fc = 4;
        D_01e4c7fd = 4;
        D_01e4c7fe = 4;
        D_01e4c7ff = 4;
        D_01e4c800 = 4;
        D_01e4c801 = 4;
        D_01e4c802 = 4;
        D_01e4c803 = 4;
        D_01e4c804 = 16;
        D_01e4c805 = 4;
        D_01e4c806 = 4;
        D_01e4c807 = 4;
        D_01e4c808 = 4;
        D_01e4c809 = 4;
        D_01e4c80a = 4;
        D_01e4c80b = 4;
        D_01e4c80c = 4;
        D_01e4c80d = 4;
        D_01e4c80e = 4;
        D_01e4c80f = 4;
        D_01e4c810 = 4;
        D_01e4c811 = 4;
        D_01e4c812 = 4;
        D_01e4c813 = 4;
        D_01e4c814 = 4;
        D_01e4c815 = 4;
        D_01e4c816 = 4;
        D_01e4c817 = 4;
        D_01e4c818 = 4;
        D_01e4c819 = 4;
        D_01e4c81a = 4;
        D_01e4c81b = 4;
        D_01e4c81c = 4;
        D_01e4c81d = 4;
        D_01e4c81e = 4;
        D_01e4c81f = 4;
        D_01e4c820 = 4;
        D_01e4c821 = 4;
        D_01e4c822 = 4;
        D_01e4c823 = 4;
        D_01e4c824 = 4;
        D_01e4c825 = 4;
        D_01e4c826 = 4;
        D_01e4c827 = 4;
        D_01e4c828 = 16;
        D_01e4c829 = 16;
        D_01e4c82a = 16;
        D_01e4c82b = 16;
        D_01e4c82c = 16;
        D_01e4c82d = 16;
        D_01e4c82e = 16;
        D_01e4c82f = 16;
        D_01e4c830 = 16;
        D_01e4c831 = 16;
        D_01e4c832 = 16;
        D_01e4c833 = 16;
        D_01e4c834 = 16;
        D_01e4c835 = 16;
        D_01e4c836 = 16;
        D_01e4c837 = 16;
        D_01e4c838 = 16;
        D_01e4c839 = 16;
        D_01e4c83a = 16;
        D_01e4c83b = 16;
        D_01e4c83c = 16;
        D_01e4c83d = 16;
        D_01e4c83e = 16;
        D_01e4c83f = 16;
        D_01e4c840 = 16;
        D_01e4c841 = 16;
        D_01e4c842 = 16;
        D_01e4c843 = 16;
        D_01e4c844 = 16;
        D_01e4c845 = 16;
        D_01e4c846 = 16;
        D_01e4c847 = 16;
        D_01e4c848 = 8;
        D_01e4c849 = 8;
        D_01e4c84a = 8;
        D_01e4c84b = 8;
        D_01e4c84c = 8;
        D_01e4c84d = 8;
        D_01e4c84e = 8;
        D_01e4c84f = 8;
        D_01e4c850 = 8;
        D_01e4c851 = 8;
        D_01e4c852 = 8;
        D_01e4c853 = 8;
        D_01e4c854 = 8;
        D_01e4c855 = 8;
        D_01e4c856 = 8;
        D_01e4c857 = 8;
        D_01e4c858 = 8;
        D_01e4c859 = 8;
        D_01e4c85a = 8;
        D_01e4c85b = 8;
        D_01e4c85c = 8;
        D_01e4c85d = 8;
        D_01e4c85e = 8;
        D_01e4c85f = 8;
        D_01e4c860 = 8;
        D_01e4c861 = 8;
        D_01e4c862 = 8;
        D_01e4c863 = 8;
        D_01e4c864 = 8;
        D_01e4c865 = 8;
        D_01e4c866 = 8;
        D_01e4c867 = 8;
    }
    for (i = 0; i < 176; i++) {
        void* d = dst->fld[i];
        void* s = src->fld[i];
        if (s && d && s != d) func_002fdd68__318290(d, s, D_01e4c7b8_x12158[i]);
    }
    return src->f708 - dst->f708 + src->f736;
}

// --------------------
// libgcc unwind-dw2.c execute_stack_op (early GCC 3.x version: DW_OP_swap/shl/shr/shra/xor
// are missing from the outer case list, and results are pushed with stack[++stack_elt]).
typedef u64 UWord3172f0;
typedef s64 USword3172f0;
struct UCtx3172f0 { void* reg[1]; };
union Unal3172f0 {
    void* p;
    unsigned u2 __attribute__((mode(HI)));
    unsigned u4 __attribute__((mode(SI)));
    unsigned u8 __attribute__((mode(DI)));
    signed s2 __attribute__((mode(HI)));
    signed s4 __attribute__((mode(SI)));
    signed s8 __attribute__((mode(DI)));
} __attribute__((packed));
static inline void* read_pointer3172f0(const void* p) { const Unal3172f0* up = (const Unal3172f0*)p; return up->p; }
static inline int read_1u3172f0(const void* p) { return *(const unsigned char*)p; }
static inline int read_1s3172f0(const void* p) { return *(const signed char*)p; }
static inline int read_2u3172f0(const void* p) { const Unal3172f0* up = (const Unal3172f0*)p; return up->u2; }
static inline int read_2s3172f0(const void* p) { const Unal3172f0* up = (const Unal3172f0*)p; return up->s2; }
static inline unsigned int read_4u3172f0(const void* p) { const Unal3172f0* up = (const Unal3172f0*)p; return up->u4; }
static inline int read_4s3172f0(const void* p) { const Unal3172f0* up = (const Unal3172f0*)p; return up->s4; }
static inline unsigned long read_8u3172f0(const void* p) { const Unal3172f0* up = (const Unal3172f0*)p; return up->u8; }
static inline unsigned long read_8s3172f0(const void* p) { const Unal3172f0* up = (const Unal3172f0*)p; return up->s8; }
const unsigned char* func_00316f38__3172f0(const unsigned char*, UWord3172f0*) asm("func_00316f38");
const unsigned char* func_00316f70__3172f0(const unsigned char*, USword3172f0*) asm("func_00316f70");
void func_002fd160__3172f0(void) asm("func_002fd160") __attribute__((noreturn));
s64 func_00311dd0__3172f0(s64, s64) asm("func_00311dd0");
s64 func_003125c0__3172f0(s64, s64) asm("func_003125c0");
#define read_uleb128 func_00316f38__3172f0
#define read_sleb128 func_00316f70__3172f0
#define abort func_002fd160__3172f0
static inline UWord3172f0 GetGR3172f0(UCtx3172f0* context, int index) { return *(UWord3172f0*)context->reg[index]; }
UWord3172f0 func_003172f0(const unsigned char* op_ptr, const unsigned char* op_end, UCtx3172f0* context, UWord3172f0 initial)
{
  UWord3172f0 stack[64];
  int stack_elt;

  stack[0] = initial;
  stack_elt = 1;

  while (op_ptr < op_end)
    {
      unsigned int op = *op_ptr++;
      UWord3172f0 result, reg, utmp;
      USword3172f0 offset, stmp;

      switch (op)
	{
	case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37:
	case 0x38: case 0x39: case 0x3a: case 0x3b: case 0x3c: case 0x3d: case 0x3e: case 0x3f:
	case 0x40: case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47:
	case 0x48: case 0x49: case 0x4a: case 0x4b: case 0x4c: case 0x4d: case 0x4e: case 0x4f:
	  result = op - 0x30;
	  break;

	case 0x03:
	  result = (UWord3172f0)(u32)read_pointer3172f0(op_ptr);
	  op_ptr += sizeof(void*);
	  break;

	case 0x08:
	  result = read_1u3172f0(op_ptr);
	  op_ptr += 1;
	  break;
	case 0x09:
	  result = read_1s3172f0(op_ptr);
	  op_ptr += 1;
	  break;
	case 0x0a:
	  result = read_2u3172f0(op_ptr);
	  op_ptr += 2;
	  break;
	case 0x0b:
	  result = read_2s3172f0(op_ptr);
	  op_ptr += 2;
	  break;
	case 0x0c:
	  result = read_4u3172f0(op_ptr);
	  op_ptr += 4;
	  break;
	case 0x0d:
	  result = read_4s3172f0(op_ptr);
	  op_ptr += 4;
	  break;
	case 0x0e:
	  result = read_8u3172f0(op_ptr);
	  op_ptr += 8;
	  break;
	case 0x0f:
	  result = read_8s3172f0(op_ptr);
	  op_ptr += 8;
	  break;
	case 0x10:
	  op_ptr = read_uleb128(op_ptr, &result);
	  break;
	case 0x11:
	  op_ptr = read_sleb128(op_ptr, &stmp);
	  result = stmp;
	  break;

	case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57:
	case 0x58: case 0x59: case 0x5a: case 0x5b: case 0x5c: case 0x5d: case 0x5e: case 0x5f:
	case 0x60: case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67:
	case 0x68: case 0x69: case 0x6a: case 0x6b: case 0x6c: case 0x6d: case 0x6e: case 0x6f:
	  result = GetGR3172f0(context, op - 0x50);
	  break;
	case 0x90:
	  op_ptr = read_uleb128(op_ptr, &reg);
	  result = GetGR3172f0(context, reg);
	  break;

	case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77:
	case 0x78: case 0x79: case 0x7a: case 0x7b: case 0x7c: case 0x7d: case 0x7e: case 0x7f:
	case 0x80: case 0x81: case 0x82: case 0x83: case 0x84: case 0x85: case 0x86: case 0x87:
	case 0x88: case 0x89: case 0x8a: case 0x8b: case 0x8c: case 0x8d: case 0x8e: case 0x8f:
	  op_ptr = read_sleb128(op_ptr, &offset);
	  result = GetGR3172f0(context, op - 0x70) + offset;
	  break;
	case 0x92:
	  op_ptr = read_uleb128(op_ptr, &reg);
	  op_ptr = read_sleb128(op_ptr, &offset);
	  result = GetGR3172f0(context, reg) + offset;
	  break;

	case 0x12:
	  if (stack_elt < 1)
	    abort();
	  result = stack[stack_elt - 1];
	  break;

	case 0x13:
	  if (--stack_elt < 0)
	    abort();
	  goto no_push;

	case 0x15:
	  offset = *op_ptr++;
	  if (offset >= stack_elt - 1)
	    abort();
	  result = stack[stack_elt - 1 - offset];
	  break;

	case 0x14:
	  if (stack_elt < 2)
	    abort();
	  result = stack[stack_elt - 2];
	  break;

	case 0x17:
	  {
	    UWord3172f0 t1, t2, t3;

	    if (stack_elt < 3)
	      abort();
	    t1 = stack[stack_elt - 1];
	    t2 = stack[stack_elt - 2];
	    t3 = stack[stack_elt - 3];
	    stack[stack_elt - 1] = t2;
	    stack[stack_elt - 2] = t3;
	    stack[stack_elt - 3] = t1;
	    goto no_push;
	  }

	case 0x06:
	case 0x94:
	case 0x19:
	case 0x1f:
	case 0x20:
	case 0x23:
	  if (--stack_elt < 0)
	    abort();
	  result = stack[stack_elt];

	  switch (op)
	    {
	    case 0x06:
	      {
		void* ptr = (void*)(u32)result;
		result = (u32)read_pointer3172f0(ptr);
	      }
	      break;

	    case 0x94:
	      {
		void* ptr = (void*)(u32)result;
		switch (*op_ptr++)
		  {
		  case 1:
		    result = read_1u3172f0(ptr);
		    break;
		  case 2:
		    result = read_2u3172f0(ptr);
		    break;
		  case 4:
		    result = read_4u3172f0(ptr);
		    break;
		  case 8:
		    result = read_8u3172f0(ptr);
		    break;
		  default:
		    abort();
		  }
	      }
	      break;

	    case 0x19:
	      if ((USword3172f0)result < 0)
		result = -result;
	      break;
	    case 0x1f:
	      result = -result;
	      break;
	    case 0x20:
	      result = ~result;
	      break;
	    case 0x23:
	      op_ptr = read_uleb128(op_ptr, &utmp);
	      result += utmp;
	      break;

	    default:
	      abort();
	    }
	  break;

	case 0x1a:
	case 0x1b:
	case 0x1c:
	case 0x1d:
	case 0x1e:
	case 0x21:
	case 0x22:
	case 0x2c:
	case 0x2a:
	case 0x29:
	case 0x2d:
	case 0x2b:
	case 0x2e:
	  {
	    UWord3172f0 first, second;
	    if ((stack_elt -= 2) < 0)
	      abort();
	    second = stack[stack_elt];
	    first = stack[stack_elt + 1];

	    switch (op)
	      {
	      case 0x1a:
		result = second & first;
		break;
	      case 0x1b:
		result = func_00311dd0__3172f0((USword3172f0)second, (USword3172f0)first);
		break;
	      case 0x1c:
		result = second - first;
		break;
	      case 0x1d:
		result = func_003125c0__3172f0((USword3172f0)second, (USword3172f0)first);
		break;
	      case 0x1e:
		result = second * first;
		break;
	      case 0x21:
		result = second | first;
		break;
	      case 0x22:
		result = second + first;
		break;
	      case 0x24:
		result = second << first;
		break;
	      case 0x25:
		result = second >> first;
		break;
	      case 0x26:
		result = (USword3172f0)second >> first;
		break;
	      case 0x27:
		result = second ^ first;
		break;
	      case 0x2c:
		result = (USword3172f0)first <= (USword3172f0)second;
		break;
	      case 0x2a:
		result = (USword3172f0)first >= (USword3172f0)second;
		break;
	      case 0x29:
		result = (USword3172f0)first == (USword3172f0)second;
		break;
	      case 0x2d:
		result = (USword3172f0)first < (USword3172f0)second;
		break;
	      case 0x2b:
		result = (USword3172f0)first > (USword3172f0)second;
		break;
	      case 0x2e:
		result = (USword3172f0)first != (USword3172f0)second;
		break;

	      default:
		abort();
	      }
	  }
	  break;

	case 0x2f:
	  offset = read_2s3172f0(op_ptr);
	  op_ptr += 2;
	  op_ptr += offset;
	  goto no_push;

	case 0x28:
	  if (--stack_elt < 0)
	    abort();
	  offset = read_2s3172f0(op_ptr);
	  op_ptr += 2;
	  if (stack[stack_elt] != 0)
	    op_ptr += offset;
	  goto no_push;

	case 0x96:
	  goto no_push;

	default:
	  abort();
	}

      /* Most things push a result value.  */
      if ((u32)stack_elt >= sizeof(stack) / sizeof(*stack))
	abort();
      stack[++stack_elt] = result;
    no_push:;
    }

  if (--stack_elt < 0)
    abort();
  return stack[stack_elt];
}
#undef read_uleb128
#undef read_sleb128
#undef abort

} // extern "C"
