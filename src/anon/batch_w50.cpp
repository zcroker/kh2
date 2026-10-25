#include "../common/types.h"

// 128-bit copy (lq/sq through t0).
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

typedef unsigned int u128 __attribute__((mode(TI)));
typedef void (*VFn)(void*);
typedef void (*VFn3)(void*, void*, void*);

// 16-byte aligned vector: copies are one quadword; assignment skips self-copies.
struct Vec4 {
    f32 x, y, z, w;
    Vec4() {}
    Vec4(const Vec4& o) { QCOPY(this, &o); }
    Vec4& operator=(const Vec4& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));

// Plain 16-byte aligned vector (copied explicitly with QCOPY).
struct Q16 { f32 x, y, z, w; } __attribute__((aligned(16)));

struct Ctl0 { void* p; u32 f4; u8 f8; u8 pad[11]; u32 f20; u32 f24; u32 f28; u32 f32; u32 f36; u32 f40; };
struct Ctl1 { u16 a; u16 b; u16 c; };
extern Ctl0 D_0032b9e8;
extern u8 D_0032b930[];
extern Ctl1 D_0032ba3c;

void wtarget_00103ec0(u32, u32, u32, u32) asm("_Z16wtarget_00103ec0jjjj");
void ctarget0_001a5a48(void) asm("_Z17ctarget0_001a5a48v");

void wtarget_00103ec0(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        D_0032b9e8.p = D_0032b930;
        D_0032b9e8.f4 = 0;
        D_0032b9e8.f8 = 77;
        D_0032b9e8.f20 = 2;
        D_0032b9e8.f24 = 0x222e0;
        D_0032b9e8.f28 = 0;
        D_0032b9e8.f32 = 0;
        D_0032b9e8.f36 = 0;
        D_0032b9e8.f40 = 4096;
    }
    if (b == 0xffff && a == 1) {
        D_0032ba3c.a = 0;
        D_0032ba3c.b = 0;
        D_0032ba3c.c = 0;
    }
}

// GS GIFtag (two 64-bit words, bitfields).
struct GifTag {
    u64 nloop : 15; u64 eop : 1; u64 pad : 30; u64 pre : 1; u64 prim : 11; u64 flg : 2; u64 nreg : 4;
    u64 regs0 : 4; u64 regs : 60;
};
struct Pkt {
    GifTag tag;
    u64 d0, a0, d1, a1, d2, a2, d3, a3;
    GifTag tag2;
};

struct E8 { u32 a; f32 v; };
struct Tbl { u32 f0; u32 f4; E8* e; };
struct Bone { u32 f0; s16 parent; s16 f6; u64 flags; u8 pad[48]; };
typedef Bone* (*BoneFn)(void*);
struct KV { s32 key; u32 val; };
struct KVList { u32 f0, f4, f8; s32 count; KV e[1]; };
typedef void* (*AllocFn)(void*, u32, void*);
struct S172 { u8* o; Q16* v; u32 n; f32 f; u32 flag; };
union VP { u8* vt; f32 f; };
struct Scaled { Vec4* v; f32 s; };
struct Arr144 { u8* hdr; u8* arr; };
struct Bits1536 { u32 lo : 3; u32 kind : 4; u32 hi : 25; };
struct F8 { f32 a, b, t, d; };
struct Flags { u16 a; u16 b; u32 f0 : 1; u32 f1 : 2; u32 f3 : 1; u32 f4 : 1; u32 f5 : 1; u32 f6 : 1; u32 f7 : 1; u32 f8 : 1; u32 f9 : 2; };
struct List64 { u32 f0; u8* arr; s32 n; };
struct Slot { u8 b[64]; };
struct Ent { u8 pad[40]; u32 on : 1; };

extern "C" {
u32 func_001dc5f0(s32);
void func_00136020(void*);
u32 func_0013a800(void);
void func_00138650(void*, s32, u32, s32);
s32 func_00242c70(void);
s32 func_0013a9d0(void);
void func_002368e8(void*, f32);
void func_002367c8(void*);  // obj_dispatch_bitfield64
extern u8* D_00348050;
s32 func_001991a8(s32, s32);
void func_0013f030(void);
void func_0013f048(void);
extern u32 D_00348704;
void func_0013f288(void);
void func_0015d690(void);
void func_0013f3d0(void);
void func_0013f4d8(void);
void func_001069b8(s32);  // swap_global_word
void func_00140f78(void*, void*);
void* func_00106a60(s32);  // buffer_get_by_index
void* func_00106a18(s32);  // buffer_get_256
void func_00107368(void*, void*);  // vec_copy_at80_if_diff
void func_00107478(void*, void*);  // vec_copy_at96_if_diff
f32 func_001074b8(void*);
f32 func_00106f30(void*, s32);
extern u8 D_0034af38;
extern u8 D_004f3800[];
extern u8 D_004f37f0[];
extern f32 D_004f3814;
extern f32 D_004f3810;
void* func_00102788(void*, s32, u32, void*);
void func_001609e0(void);
void func_00160a90(void);
extern void* D_004f3b30;
extern void* D_0032b91c;
void func_00168958(void*, s32, u32);  // obj_init_name_string
Vec4 func_0016bda8(void*);
s32 func_001d35e0(Vec4*, Vec4*, Vec4*, s32);
void func_001a55a8(Vec4*, s32);
void YS_OBJ_scatter_prize(u8*, s32) asm("_ZN2YS3OBJ13scatter_prizeEi");
extern s8 D_004f62f0;
extern Vec4 D_004f6300;
void func_0016e888(void);
void func_002fd188(void*);  // pool_alloc_block
void func_001b6dd0(void*, void*);
void func_0017f488(void*, u32, f32, f32);
f32 func_002f8ad0(f32, f32);
s32 func_00181500(s32);
s32 func_0019c400(void*);
void func_0016ae58(void*, f32);
f32 func_0017ce10(f32);
s32 func_0019c838(void*);
extern u8* D_00352130;
extern u8 D_0032bae0[];
extern u8 D_0032bb30[];
u8* func_001947c0(u32, u32);
void func_001a9110(void*);
Ent* func_001c16f0(void*, Ent*);
void func_001a53d0(void*, u32, Ent*);
extern u8* D_00350790;
extern u32 D_0034e948;
void func_00165768(u32);
void func_00105110(void*);
s32 func_001bb4a0(void);
s32 func_00198d00(s32, s32);
extern u8* D_01d49320;
void func_001bdab0(void*);
void func_001bd3e0(void*, s32, u32, u32, s32, s32);
extern void* D_003527e0;
void func_0019c9e0(void*);
void func_0013ddc0(s32, void*);
void func_001bdf38(void*, void*, u32);
void func_001d6ab0(void*);
void func_001b3b70(void*, void*, s32, u32);
s32 func_0019c8a8(void*);
extern u8 D_00352878[];
extern F8 D_003590f0;
extern f32 D_00359a20[];
double func_00313b80(f32);  // float_to_double
void func_002fdfc8(const char*, u32, double, double, double, double);  // device_vprintf_va
extern const char D_00370c68[];
void func_0016ed50(u32, s32, s32);
u8* func_00227d10(u32);
u8* func_001058e8(void);
void func_002fde18(void*, s32, s32);
extern u8 D_0035ecd8[];
u32 func_00288be8(s32);
s32 func_002954e0(s32);
s32 func_00276c18(void);
extern u32* D_0035f5ac;
extern u16 D_00374aa0[];
void func_00106420(void*);
extern void* D_0035f600;
extern u8* D_0035f604;
s32 func_002b8ac0(u8*);
extern u8* D_003617ec;
extern u8* D_003617f0;
extern u8 D_003617f8;
void func_00168410(u8*, u8*, u32, s32, void*, s32);
void func_002bd838(void);
void func_002c6280(u8*, s32, u32);
void func_002ef8d0(u8*, u32);
extern u32 D_0032b96c;
f32* func_002cba88(f32*, u8*, f32, f32);
s32 func_001c0cd8(u8*);
void func_001dc818(u32);
u32 func_0016ac38(u8*, s32, s32, s32, s32);
extern u8 D_00362d20[];
u32 func_002e64b8(s32, u32);  // list_advance_count
void func_002e6ab0(u32, u8*, f32);
extern u8* D_01e2bfa0;

// Clears a 3-quadword GS packet and fills in its GIFtags and A+D register ids.
void func_00108398(Pkt* p) {  // clear_quads_set_flags
    p->d3 = 0;
    *(u128*)&p->tag = 0;
    *(u128*)&p->tag2 = 0;
    p->tag.nloop = 4;
    p->tag.nreg = 1;
    p->tag.regs0 = 0xe;
    p->a0 = 80;
    p->a1 = 81;
    p->a2 = 82;
    p->a3 = 83;
    p->tag2.eop = 1;
    p->tag2.flg = 2;
}

f32 func_00114328(Tbl* t, s32 i, u8 a, u8 b) {
    if (a) {
        if (b) return t->e[i + 4].v;
        return t->e[i + 8].v;
    }
    return t->e[i].v;
}

// Walks up the bone hierarchy past bones with flag bit 32 set.
s32 func_0011f270(void* o, s32 n) {
    Bone* b = (*(BoneFn*)((*(u8**)o) + 32))(o);
    s32 i = b[n].parent;
    while (i >= 0 && (b[i].flags & 0x100000000ull)) i = b[i].parent;
    return i;
}

// Removes the entry for key (if its value is still current), then refreshes.
void func_00136200(KVList* l, s32 key) {
    for (s32 i = 0; i < l->count; i++) {
        if (l->e[i].key == key && l->e[i].val == func_001dc5f0(key)) {
            l->e[i].key = 0;
            l->e[i].val = 0;
            break;
        }
    }
    func_00136020(l);
}

void func_0013b1d0(void) {
    func_00138650(D_00348050, 5200, func_0013a800(), 1);
    if (func_00242c70()) return;
    if (!func_0013a9d0()) return;
    u8* p = D_00348050 + 32;
    func_002368e8(p, 0.8f);
    func_002367c8(p);  // obj_dispatch_bitfield64
}

void func_0013f0d0(void) {
    if (func_001991a8(0, 0)) {
        func_0013f030();
        func_0013f048();
        return;
    }
    switch (D_00348704 & 0x3fffffff) {
    case 1: func_0013f288(); break;
    case 0: func_0015d690(); break;
    case 2: func_0013f3d0(); break;
    case 3: func_0013f4d8(); break;
    }
}

// 0015cde0: moved to src/anon/unit_0015cdb0.cpp

void func_00160ac0(u32 a, u32 b) {
    u8* v = (u8*)func_00102788(D_004f3b30, 0, b, (void*)func_001609e0);
    *(u32*)(v + 4) = a;
    *(void**)(v + 48) = (void*)func_00160a90;
}

// Allocates a 76-byte object from the heap (tagged with the caller) and initialises it.
void func_00168388(u32 a, u32 b, u32 c, u32 d) {
    void* h = D_0032b91c;
    u8* o = (u8*)(*(AllocFn*)(*(u8**)h))(h, 76, __builtin_return_address(0));
    func_00168958(o, 0, a);  // obj_init_name_string
    *(u32*)(o + 52) = b;
    *(u32*)(o + 56) = c;
    *(u32*)(o + 60) = d;
}

// YS::OBJ::scatter_prize(int)
void YS_OBJ_scatter_prize(u8* self, s32 n) {
    Vec4 c;
    Vec4 t;
    Vec4 a(*(Vec4*)(self + 1344));
    a.y -= *(f32*)(self + 1532);
    Vec4 b = func_0016bda8(self);
    if (func_001d35e0(&c, &a, &b, 6)) b = c;
    func_001a55a8(&b, n);
}

// Scales o->v by o->s into a function-static vector (guard byte + atexit
// registration of its destructor spelled out) and points o->v at it.
void func_0016d450(Scaled* o) {
    Vec4* v = o->v;
    if (!D_004f62f0) {
        D_004f62f0 = 1;
        func_002fd188((void*)func_0016e888);  // pool_alloc_block
    }
    Vec4 t;
    asm("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
        : : "r"(&t), "r"(v), "f"(o->s) : "$8", "memory");
    D_004f6300 = t;
    o->v = &D_004f6300;
}

void func_001722e8(S172* s) {
    u8* o = *(u8**)(s->o + 4);
    Q16 t;
    QCOPY(&t, s->v);
    func_001b6dd0(o, &t);
    func_0017f488(o + 320, s->n, s->f, 0.0f);
    if (s->flag) {
        u32 n = s->n;
        *(u32*)(o + 256) = n + 1;
        *(u32*)(o + 260) = n + 2;
    }
}

// Direction vector -> (pitch, yaw, 0, 1) angles.
Vec4* func_0017d050(Vec4* out, Vec4* in) {
    Vec4 t;
    t = *in;
    f32 len;
    t.y = 0;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0"
                 : "=f"(len) : "r"(&t) : "$8", "memory");
    out->x = func_002f8ad0(-in->y, len);
    out->y = func_002f8ad0(in->x, in->z);
    out->z = 0;
    out->w = 1.0f;
    return out;
}

s32 func_00181a18(void) {
    s32 r = 0;
    if (!func_00181500(2071) || func_00181500(5163) || func_00181500(8216)) r = 1;
    return r;
}

void func_001835a0(u8* o, f32 d) {
    if (func_0019c400(o)) return;
    func_0016ae58(o, *(f32*)(o + 1372) + d);
    *(f32*)(o + 1644) = func_0017ce10(*(f32*)(o + 1644) + d);
}

void func_00186c58(u8* o, Q16* v, f32 s) {
    if (!func_0019c838(o)) return;
    Q16 t;
    QCOPY(&t, v);
    VP* h = *(VP**)(o + 12);
    t.w = s * *(f32*)(D_00352130 + 56);
    t.y = 50.0f;
    (*(VFn3*)(h->vt + 8))(h, o, &t);
}

void func_00194930(void) {
    u8* v = func_001947c0(D_0032bae0[1], D_0032bae0[0]);
    func_001a9110(v + D_0032bb30[D_0032bae0[0] + 9196] * 4 + 16);
}
}

void ctarget0_001a5a48(void) {
    Ent* p = 0;
    Ent* q;
    while ((q = func_001c16f0(*(void**)(D_00350790 + 2548), p)) != 0) {
        p = q;
        if (!q->on) continue;
        u32 k = D_0034e948;
        func_001a53d0(D_00350790, k, q);
    }
}

extern "C" {
void func_001b3098(Arr144* s) {
    if (!s->hdr) return;
    for (s32 i = 0; i < *(s32*)(s->hdr + 4); i++) func_00165768(*(u32*)(s->arr + i * 144 + 128));
    func_00105110(s->arr);
    s->hdr = 0;
}

s32 func_001bb7f8(void) {
    s32 r = 0;
    if (func_001bb4a0() && (func_00198d00(8, -1) || *(u32*)(D_01d49320 + 172))) r = 1;
    return r;
}

void func_001bd4e8(u8* o, u32* v, u32 c) {
    if (*(u32*)(*(u8**)(o + 2528) + 1416) & 0x2000000) return;
    func_001bdab0(o);
    for (s32 i = 0; i < 4; i++) func_001bd3e0(o, i + 3, v[i], c, 1, 100);
}

void func_001d6938(u8* o, u8* p) {
    D_003527e0 = o;
    func_0019c9e0(o + 2752);
    if (*(u32*)(p + 1164)) func_0013ddc0(0, p);
    if (!*(u32*)(o + 2804)) func_001bdf38(o, p, *(u32*)(p + 2872));
    else *(u8**)(o + 2528) = p;
    *(u8**)(o + 2804) = p;
    if (!o[2808]) func_001d6ab0(o);
}

void func_001d7d68(u8* o, u8* a, u32 b) {
    func_001b3b70(o, a, 3, b);
    *(u32*)o = (u32)D_00352878;
    *(u32*)(o + 1416) |= 0x20000;
    if (!func_0019c8a8(o)) *(u32*)(o + 944) = 2;
    ((Bits1536*)(o + 1536))->kind = (*(u16*)(a + 72) >> 3 & 1) ? 2 : 1;
}

// Cubic interpolation between key pairs a[i], b[i] at fraction t (VU0).
void func_00202ba0(Vec4* out, Vec4* a, Vec4* b, f32 t) {
    s32 i = (s32)t;
    a += i;
    b += i;
    D_003590f0.t = t - (f32)i;
    asm volatile(".set noreorder\n\t"
        "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 0(%2)\n\tlqc2 $vf4, 16(%2)\n\tlqc2 $vf5, 0(%3)\n\t"
        "vsub.xyzw $vf10, $vf4, $vf3\n\tvmuly.xyzw $vf11, $vf3, $vf5y\n\tvmulx.xyzw $vf12, $vf3, $vf5x\n\t"
        "vsub.xyzw $vf13, $vf2, $vf1\n\tvmulz.xyzw $vf10, $vf10, $vf5z\n\tvadd.xyzw $vf11, $vf11, $vf4\n\t"
        "vadd.xyzw $vf10, $vf10, $vf12\n\tvsub.xyzw $vf13, $vf13, $vf11\n\tvmulz.xyzw $vf10, $vf10, $vf5z\n\t"
        "vadd.xyzw $vf10, $vf10, $vf13\n\tvmulz.xyzw $vf10, $vf10, $vf5z\n\tvadd.xyzw $vf10, $vf10, $vf1\n\t"
        "sqc2 $vf10, 0(%0)\n\t.set reorder"
        : : "r"(out), "r"(a), "r"(b), "r"(&D_003590f0) : "memory");
}

union FU { u32 u; f32 f; };
// VU0 random float: reseed/step R five times. Hand-written VU0 assembly.
f32 func_00209fb8(void) {  // vu_const_5f_c
    register u32 x asm("$15");
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\t"
        "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\t"
        "qmfc2 %0, $vf1" : "=r"(x) : : "$8");
    FU u;
    u.u = x;
    return u.f;
}

// Rotation about Z from a 16-bit angle (4096-entry sine table).
void func_0021ead0(f32* m, u32 ang) {  // table_float_pair_lookup
    f32 s = D_00359a20[(ang >> 4) & 0xfff];
    f32 c = D_00359a20[((ang + 0x4000) >> 4) & 0xfff];
    m[0] = c; m[4] = -s; m[8] = 0; m[12] = 0;
    m[1] = s; m[5] = c; m[9] = 0; m[13] = 0;
    m[2] = 0; m[6] = 0; m[10] = 1.0f; m[14] = 0;
    m[3] = 0; m[7] = 0; m[11] = 0; m[15] = 1.0f;
}

// Debug print of a vec4 (floats promoted through the soft-double helper).
void func_00223608(u32 x, f32* v) {
    func_002fdfc8(D_00370c68, x, func_00313b80(v[0]), func_00313b80(v[1]), func_00313b80(v[2]), func_00313b80(v[3]));  // device_vprintf_va
}

void func_0022f5a0(u32 a, u32 b, u32 c) {
    func_0016ed50(b | 0x40000000, -1, 30);
    func_00227d10(c)[22] = 1;
}

void func_00242880(void) {
    Flags* p = (Flags*)(func_001058e8() + 16800);
    p->a = 0;
    p->b = 0;
    p->f0 = 1;
    p->f1 = 1;
    p->f3 = 1;
    p->f4 = 0;
    p->f5 = 0;
    p->f6 = 0;
    p->f7 = 0;
    p->f8 = 0;
    p->f9 = 2;
    func_002fde18(D_0035ecd8, 0, 4);
}

void func_00288c58(u8* o, s32 n) {
    *(u32*)(o + 40) = func_00288be8(n * 4);
    *(u32*)(o + 44) = func_00288be8(n * 8);
    *(u32*)(o + 48) = func_00288be8(n * 8);
}

void func_0029c958(void) {
    u32 mask = 0;
    for (s32 i = 0; i < 15; i++) {
        if (func_002954e0(i) || func_00276c18()) mask |= 1 << (i + 1);
    }
    mask |= 1;
    *D_0035f5ac = mask;
}

// Is id in the zero-terminated u16 list?
s32 func_0029ec40(u32 id) {
    s32 r = 0;
    for (s32 i = 0; D_00374aa0[i]; i++) {
        if (D_00374aa0[i] == id) { r = 1; break; }
    }
    return r;
}

void func_002a76d8(void) {
    if (D_0035f600) {
        func_00106420(D_0035f600);
        D_0035f600 = 0;
    }
    u8* p = D_0035f604;
    if (p) {
        u8* e = p + 8720;
        for (;;) {
            if (p == e) break;
            e -= 436;
            (*(VFn*)(*(u8**)e + 12))(e);
        }
        func_00106420(p);
        D_0035f604 = 0;
    }
}

void func_002bd870(void) {
    if (!func_002b8ac0(D_003617ec)) return;
    if (D_003617f8) return;
    u8* p = D_003617f0;
    if (!p) return;
    func_00168410(p, D_003617ec, *(u32*)(D_003617ec + 0x4802c), 16, (void*)func_002bd838, 0);
    D_003617f8 = 1;
}

void func_002c6228(u8* o, s32 i, u32 v) {
    func_002c6280(o, i, v);
    ((u32*)(o + 16))[i] = v;
    func_002ef8d0(o, D_0032b96c);
}

f32* func_002cbca0(f32* out, u8* p) {
    func_002cba88(out, p, *(f32*)(p + 36), 1.0f);
    out[3] = *(f32*)(p + 20);
    return out;
}

void func_002dc1b8(u8* o, s32 id) {
    if (func_001c0cd8(o) || o[3008]) id = -1;
    u32 h = *(u32*)(o + 2828);
    if (h) {
        if (*(s32*)(o + 2836) == id) return;
        func_001dc818(h);
        *(u32*)(o + 2828) = 0;
    }
    if (id >= 0) *(u32*)(o + 2828) = func_0016ac38(o, id, 1, 0, 0);
    *(s32*)(o + 2836) = id;
}

void func_002dea00(u8* o, f32 a, f32 b) {  // obj_init_with_floats
    *(u32*)(o + 4) = 30;
    *(u32*)(o + 8) = 256;
    *(u8**)o = D_00362d20;
    *(f32*)(o + 12) = b;
    *(f32*)(o + 16) = 10.0f;
    *(f32*)(o + 20) = a;
    *(s32*)(o + 56) = -1;
}

void func_002e7108(List64* l, f32 x) {
    s32 n = l->n;
    for (s32 i = 0; i < n; i++) {
        u8* e = l->arr + i * 64;
        func_002e6ab0(func_002e64b8(i, l->f0), e, x);
    }
}

// Next 64-byte slot after p (or the first) whose index is not in the in-use list.
Slot* func_002e97b8(Slot* p) {
    Slot* base = (Slot*)D_01e2bfa0;
    Slot* q = p ? p + 1 : base;
    while (q < base + 30) {
        s32 idx = q - base;
        s32 n = *(s32*)((u8*)base + 2040);
        s32 j;
        for (j = 0; j < n; j++) if (((s32*)((u8*)base + 1920))[j] == idx) { q++; break; }
        if (j == n) return q;
    }
    return 0;
}
}
