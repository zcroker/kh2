#include "../common/types.h"

typedef unsigned int u128 __attribute__((mode(TI)));

u32 wtarget_001339d0(u32, u32, u32, u32, u32) asm("_Z16wtarget_001339d0jjjj");
u32 wtarget_00180828(u32, u32, u32, u32) asm("_Z16wtarget_00180828jjjj");
u32 wtarget_001d9980(u32, u32, u32, u32) asm("_Z16wtarget_001d9980jjjj");
void wtarget_002cb188(u32, u32, u32, u32) asm("_Z16wtarget_002cb188jjjj");
void wtarget_002e1878(u32, u32, u32, u32) asm("_Z16wtarget_002e1878jjjj");

extern "C" {

f32 func_001142e0(u32, u32, u32, u32);  // entry8_float_by_flags
s32 func_001917c0(void);

typedef s32 (*VFnI)(void*);
typedef void (*VFn)(void*);
typedef void (*VFn1)(void*, u32);

// Scaled value: base minus half of a field, clamped to >= 1, doubled for state 3 in battle mode.
f32 func_00111808(u8* p) {  // obj_update_sprite_floats
    f32 r = func_001142e0(*(u32*)(p + 2912), 1, 0, 1) - *(f32*)(p + 1464) * 0.5f;
    if (r <= 1.0f) r = 1.0f;
    if (func_001917c0()) {
        if ((*(VFnI*)(*(u8**)p + 152))(p) == 3) r += r;
    }
    return r;
}

// Copy matrix i of the table into m, then negate its Y and Z columns.
void func_0011d468(u8* p, s32 i, f32* m) {
    u8* s = *(u8**)(p + 44) + (i << 6);
    if ((u8*)m != s)
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(m), "r"(s) : "$8", "$9", "$10", "$11", "memory");
    m[1] = -m[1];
    m[5] = -m[5];
    m[9] = -m[9];
    m[13] = -m[13];
    m[2] = -m[2];
    m[6] = -m[6];
    m[10] = -m[10];
    m[14] = -m[14];
}

// Cubic Hermite interpolation between (t0, p0, m0) and (t1, p1, m1).
f32 func_001286d0(f32 t, f32 t0, f32 p0, f32 m0, f32 t1, f32 p1, f32 m1) {
    f32 inv = t1 - t0;
    t = t - t0;
    inv = 1.0f / inv;
    f32 t2 = t * t;
    f32 t3 = t2 * t;
    f32 a = t2 * 3.0f;
    f32 inv2 = inv * inv;
    f32 c = t2 * inv;
    f32 b = t3 * inv2;
    a = a * inv2;
    f32 d = (b + b) * inv;
    return p0 * (d - a + 1.0f) + p1 * (a - d) + m0 * (b - (c + c) + t) + m1 * (b - c);
}

struct Pkt { u16 h0; u8 b2; u8 b3; u32 w4; u32 w8; u32 w12; };
union PktCursor { Pkt* p; u32 u; u16 h; };

}

// Append one 16-byte packet at the cursor and advance it.
u32 wtarget_001339d0(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0) {
    PktCursor* pp = (PktCursor*)a0;
    pp->p->b2 = 0;
    pp->p->w8 = a3;
    pp->p->w12 = t0;
    pp->p->b3 = 48;
    pp->p->w4 = a1;
    pp->p->h0 = a2;
    pp->p++;
    return a1;
}

extern "C" {

f32 func_0013fd10(void*);
void func_0013f828(void*);
void func_0013f888(void*, void*, u32);
void func_0013f5f0(void*);  // copy_float_220_to_48
void func_0013f608(void*);
void func_0013f648(void*);

void func_0013f558(u8* p) {
    p[57] = 0;
    p[58] = 1;
    p[56] = 0;
    p[59] = 0;
    asm volatile("sqc2 $vf0, 0(%0)" : : "r"(p + 160) : "memory");
    *(u32*)(p + 52) = 0;
    if (*(u32*)(p + 68)) {
        f32 x = func_0013fd10(p);
        *(f32*)(p + 80) = x;
        *(f32*)(p + 76) = x;
        func_0013f828(p);
        func_0013f888(p, p + 128, 0);
        func_0013f5f0(p);  // copy_float_220_to_48
        func_0013f608(p);
        func_0013f648(p);
    }
}

extern u32 D_00349394;
extern u8 D_0034939d;
extern u8 D_00349270[];
extern u32 D_00349390;
extern u32 D_00349398;
extern u8 D_0034939c;
void func_0014b208(void*, u32, u32);
void func_0013edd0(void*, f32);
void func_0014b248(void*, u32);
void func_0013ee38(void*, u32);

void func_0014a6e0(void) {
    D_00349394 = 1;
    D_0034939d = 0;
    D_00349390 = 0;
    D_00349398 = 0;
    func_0014b208(D_00349270, 256, 208);
    func_0013edd0(D_00349270, 0.0f);
    func_0014b248(D_00349270, 112);
    func_0013ee38(D_00349270, 340);
    D_0034939c = 0;
}

u8* func_00168b38(void*, u32, s32);  // entry_array_find_nth
u32 func_001667d0(u16);  // ilog2
struct TexInfo { u32 w0; u16 h4; u16 h6; u16 h8; };

// Build a GS TEX0 register value.
u64 func_00166730(TexInfo* t) {
    u32 lg = func_001667d0(t->h4);  // ilog2
    return (u64)(u32)(t->w0 << 5) | ((u64)(u16)(t->h4 >> 6) << 14) | ((u64)t->h8 << 20) |
           ((u64)lg << 26) | ((u64)9 << 30) | ((u64)1 << 34) | ((u64)1 << 51) | ((u64)1 << 61);
}

struct Allocator;
struct AllocVt { void* (*alloc)(Allocator*, u32, void*); };
struct Allocator { AllocVt* vt; };
extern Allocator* D_0032b91c;
void func_00168958(void*, u32, u32);  // obj_init_name_string

void func_001684c0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u8* o = (u8*)D_0032b91c->vt->alloc(D_0032b91c, 76, __builtin_return_address(0));
    func_00168958(o, 1, a0);  // obj_init_name_string
    *(u32*)(o + 52) = a1;
    *(u32*)(o + 56) = a2;
    *(u32*)(o + 60) = a3;
}

extern u32 D_0034d8a8;
u64 func_00312db8(u64, u64);

// Advance the LCG seed and scale it into [0, *p).
void func_0016dd28(u32* p) {
    u32 seed = D_0034d8a8 * 0x10dcd;
    u32 n = *p;
    D_0034d8a8 = seed;
    *p = (u64)seed / (((u64)(n - 1) + 0x100000000ull) / n);
}

struct Pad10 {
    u8 a, b, c;
    u16 d, e, f;
    Pad10() { u16 m = 0xffff; a = m; b = m; c = m; d = m; e = m; f = m; }
};
Pad10 func_00199718(u32, s32);
void func_00104f58(Pad10*, u32, u32, u32, u32);
union U32x { u32 u; u16 h; u8 b; };

void func_00173008(U32x* p) {
    Pad10 s;
    s = func_00199718(p[0].u, -1);
    func_00104f58(&s, p[1].u, 0, 0, 0);
}

s32 func_0019ba60(u32);
u32 func_0016a070(void*);
s32 func_001afe70(u32, u32, u32, u32*);
void func_00198630(void*, s32, u32);

void func_00176cd0(u8* p, u32 a1, u32 a2) {
    if (*(u32*)(p + 2488) == 0) return;
    u32 s2;
    if (func_0019ba60(*(u32*)(p + 2548)) && *(u8**)(p + 2548) != p) s2 = func_0016a070(*(u8**)(p + 2548));
    else s2 = 0;
    s32 r = func_001afe70(func_0016a070(p), a1, s2, &a2);
    if (r >= 0) func_00198630(p, r, a2);
}

s32 func_0017ebc8(void*);
u32 func_001a97b8(u32, s32);
u32 func_00180408(void*, u32);
extern s32 D_0036c5b8[];
extern s32 D_0036c5cc[];

}

u32 wtarget_00180828(u32 a0, u32, u32, u32) {
    u32* p = (u32*)a0;
    if (*p == 0) return 0;
    s32* t = func_0017ebc8(p) ? D_0036c5b8 : D_0036c5cc;
    s32 id;
    while ((id = *t++) >= 0) {
        u32 r = func_001a97b8(*p, id);
        if (r) return func_00180408(p, r);
    }
    return 0;
}

extern "C" {

// Store v at p+16 normalized (VU0), set p+28 = x; returns the original length.
f32 func_00183768(u8* p, u128* v, f32 x) {  // copy_quad_at16_and_len
    u128* d = (u128*)(p + 16);
    f32 len;
    if (d != v) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(v) : "$8", "memory");
    asm volatile(
        "lqc2 $vf1, 0(%1)\n\t"
        "vmul.xyz $vf2, $vf1, $vf1\n\t"
        "vaddy.x $vf2, $vf2, $vf2y\n\t"
        "vaddz.x $vf2, $vf2, $vf2z\n\t"
        "vsqrt Q, $vf2x\n\t"
        "vwaitq\n\t"
        "cfc2.ni $8, $vi22\n\t"
        "vaddq.x $vf2, $vf0, Q\n\t"
        "mtc1 $8, %0\n\t"
        "vnop\n\t"
        "vdiv Q, $vf0w, $vf2x\n\t"
        "vwaitq\n\t"
        "vmulq.xyz $vf1, $vf1, Q\n\t"
        "sqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(d) : "$8", "memory");
    *(f32*)(p + 28) = x;
    return len;
}

u32 func_00185da8(u32);
void func_0016c568(u32, u32, f32);

void func_00185e20(u32 a0) {
    u32 o = 0;
    while ((o = func_00185da8(o)) != 0) func_0016c568(o, a0, 0.0f);
}

void func_001ba028(u32);  // list_contains_ptr
u32 func_0018db38(u32, void*, u32, u32);
void func_0018ca10(u32);  // alloc_from_pool_magic

void func_0018fab0(u32* p) {
    func_001ba028(*(u32*)(p[1] + 4));  // list_contains_ptr
    u8* o = *(u8**)(p[1] + 4);
    u32 r = func_0018db38(p[0], o, p[2], p[3]);
    if (r) {
        (*(VFn1*)(*(u8**)o + 100))(o, r);
        func_0018ca10(r);  // alloc_from_pool_magic
    }
}

struct Slot88 { s32 a; s32 b; u8 pad[80]; };
extern Slot88 D_01c61b48[16];
void func_00198dc0(Slot88*);

// Find the slot keyed (a, b), or claim the last free one.
Slot88* func_00198c28(s32 a, s32 b) {
    Slot88* fr = 0;
    for (s32 i = 0; i < 16; i++) {
        Slot88* e = &D_01c61b48[i];
        if (e->a == a && e->b == b) return e;
        if (D_01c61b48[i].a < 0) fr = &D_01c61b48[i];
    }
    func_00198dc0(fr);
    fr->a = a;
    fr->b = b;
    return fr;
}

u32 func_001b1490(u32);
extern u32 D_0035043c;
extern u32 D_01c62148[19];

static inline bool hasValue8(u8* r) { return r && *(u32*)(r + 8); }

void func_00199688(void) {
    u32 o = func_001b1490(D_0035043c);
    for (s32 i = 0; i < 19; i++) {
        u8* r = func_00168b38((void*)o, 2, i);  // entry_array_find_nth
        bool ok = hasValue8(r);
        u32 v = 0;
        if (ok) v = *(u32*)(r + 8);
        D_01c62148[i] = v;
    }
}

struct LNode { u8 pad[12]; LNode* next; };
extern LNode* D_01c6cb20;
void func_001a5d48(LNode*);
void func_00105110(void*);
struct Ent44 { u32 w0; u8 pad[40]; };
extern Ent44 D_0035080c[6];
void func_001de450(Ent44*);

void func_001a5e38(void) {
    LNode* n = D_01c6cb20;
    if (n) {
        do {
            LNode* next = n->next;
            if (n) {
                func_001a5d48(n);
                func_00105110(n);
            }
            n = next;
        } while (n);
    }
    for (s32 i = 0; i < 6; i++) {
        if (D_0035080c[i].w0) func_001de450(&D_0035080c[i]);
    }
}

void func_001b3b70(void*, u32, u32, u32);
extern u8 D_00351078[];
extern void* D_00351068;

void func_001b3a90(u8* p, u32 a1, u32 a2) {
    func_001b3b70(p, a1, 2, a2);
    *(u32*)(p + 1416) |= 0x10000;
    *(void**)p = D_00351078;
    *(u32*)(p + 1536) &= ~0x78;
    *(u32*)(p + 944) = 1;
    if (func_0016a070(p) == 5008) D_00351068 = p;
}

s32 func_0018a550(void*, u32);  // state_dispatch_0_1_3

void* func_001b7998(s32* p, u32 a1) {
    for (s32 i = 0; i < p[0]; i++) {
        u8* e = (u8*)p + 16 + i * 32;
        if (func_0018a550(e, a1)) return e;
    }
    return 0;
}

s32 func_001bb4a0(u32);
u8* func_001bbcb0(void);
void func_001d4fa8(void*, u32);

s32 func_001bbdb8(u32 a0) {
    if (func_001bb4a0(a0)) {
        if (*(u32*)(func_001bbcb0() + 752) & 4) {
            func_001d4fa8(func_001bbcb0() + 740, a0);
            return 1;
        }
    }
    return 0;
}

struct LItem { u8 pad[12]; LItem* head; LItem* tail; u8 pad2[8]; LItem* owner; u32 pad3; LItem* next; };
struct LItemList { LItem* head; LItem* tail; };
struct NoTail { ~NoTail() {} };
void func_001db8b8(void*, LItem*);

// Unlink n from its owner's list.
void func_001c1808(LItem* n) {
    NoTail g;
    LItemList* l = (LItemList*)&n->owner->head;
    LItem* prev;
    if (n == l->head) {
        prev = 0;
        l->head = n->next;
    } else {
        prev = l->head;
        while (prev->next != n) prev = prev->next;
        prev->next = n->next;
    }
    if (n == l->tail) l->tail = prev;
    n->next = 0;
    func_001db8b8((u8*)n->owner + 20, n);
}

void func_002beb28(void);
void func_00188c10(u32, u32);
u32 func_00188fe0(void*, u32);
extern u8 D_0032e020[];

void func_001d7380(s32 a0) {
    switch (a0) {
    case 12:
        func_002beb28();
        break;
    case 176:
    case 181:
    case 182:
    case 183:
    case 185:
    case 186:
    case 189:
    case 296:
    case 297:
    case 298:
        func_00188c10(func_00188fe0(D_0032e020, 1), 2);
        break;
    }
}

s32 func_00105868(void*);
s32 func_00276fd0(void);
extern u8 D_0032bb30[];

}

u32 wtarget_001d9980(u32, u32, u32, u32) {
    s32 v = func_00105868(D_0032bb30);
    switch (v) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return func_00276fd0() == 100 ? 3 : 2;
    case 3:
        return func_00276fd0() == 100 ? 5 : 4;
    }
    return 0;
}

extern "C" {

// VU0 random float (hand-written VU0 asm).
f32 func_0020b410(void) {  // vu_const_5f_b
    register u32 b asm("$15");
    asm volatile(
        "addi $8, $0, -1\n\t"
        "qmtc2 $8, $vf2\n\t"
        "vrxor R, $vf2x\n\t"
        "vrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\t"
        "vrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\t"
        "vrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\t"
        "vrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\t"
        "vrnext.x $vf1, R\n\t"
        "vitof0.x $vf2, $vf2\n\t"
        "vadd.x $vf1, $vf1, $vf2\n\t"
        "qmfc2 %0, $vf1"
        : "=r"(b) : : "$8");
    union { u32 u; f32 f; } c;
    c.u = b;
    return c.f;
}

// Transform v by matrix m, project, store to out; returns screen clip flags (hand-written VU0 asm).
u32 func_00222898(void* out, void* m, void* v) {  // mat4_transform_vec
    register u32 r asm("$2");
    asm volatile(
        ".set noreorder\n\t"
        "lqc2 $vf1, 0(%2)\n\t"
        "lqc2 $vf2, 16(%2)\n\t"
        "lqc2 $vf3, 32(%2)\n\t"
        "lqc2 $vf4, 48(%2)\n\t"
        "lqc2 $vf5, 0(%3)\n\t"
        "vmulax.wxyz ACC, $vf1, $vf5x\n\t"
        "vmadday.wxyz ACC, $vf2, $vf5y\n\t"
        "vmaddaz.wxyz ACC, $vf3, $vf5z\n\t"
        "vmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
        "vdiv Q, $vf0w, $vf5w\n\t"
        "lui $2, 0x4580\n\t"
        "dsll $2, $2, 16\n\t"
        "ori $2, $2, 0x4580\n\t"
        "dsll $2, $2, 16\n\t"
        "qmtc2 $2, $vf29\n\t"
        "vwaitq\n\t"
        "vmulq.xyz $vf5, $vf5, Q\n\t"
        "vnop\n\t"
        "vnop\n\t"
        "vnop\n\t"
        "ctc2.ni $0, $vi16\n\t"
        "vsub.wxy $vf0, $vf5, $vf0\n\t"
        "vsub.xy $vf0, $vf29, $vf5\n\t"
        "vnop\n\t"
        "vnop\n\t"
        "vnop\n\t"
        "vnop\n\t"
        "cfc2.ni $2, $vi16\n\t"
        "andi $2, $2, 0xc0\n\t"
        "sqc2 $vf5, 0(%1)\n\t"
        ".set reorder"
        : "=r"(r) : "r"(out), "r"(m), "r"(v) : "memory");
    return r;
}

u32* func_00227a28(u32);
void func_002ff2e8(void*, u32);
u32 func_0022e188(u32);
u32 func_00227870(u32, void*, u32);
void func_00168388(u32, u32, void*, void*);
void func_0022e160(void);

void func_0022e1f8(u32 a0, u32 a1) {
    u32* o = func_00227a28(a0);
    o[3] = a1;
    o[0] = 2;
    o[4] = (u32)-1;
    func_002ff2e8(o + 12, a0);
    u32 s = func_0022e188(a0);
    u32 r = func_00227870(s, o, 0);
    o[5] = r;
    func_00168388(s, r, (void*)func_0022e160, o);
}

u32 func_002282f0(u16);
u32* func_00227d10(s16);
u32 func_0016f000(u32, void*, f32);
void func_00233280(u32);

void func_00233410(u8* p) {
    if (func_002282f0(*(u16*)(p + 4))) return;
    u32* e = func_00227d10(*(s16*)(p + 6));
    if (e[2]) return;
    u128 v;
    asm volatile("sqc2 $vf0, 0(%0)" : : "r"(&v) : "memory");
    e[2] = func_0016f000(e[0] | 0x40000000, &v, 3.1415925f);
    func_001ba028(e[2]);  // list_contains_ptr
    func_00233280(e[2]);
}

void func_00239558(u8* p, u16* a, u16* b) {  // copy_4halfwords_and_set_flag
    *(u32*)(p + 16) |= 0x40;
    u8* q = p;
    for (s32 i = 0; i < 4; i++) {
        *(u16*)(q + 160) = a[i];
        *(u16*)(q + 168) = b[i];
        q += 2;
    }
}

extern u8 D_0032bad8;
s32 func_00103b38(void);
u32 func_00103550(void);
s32 func_00103428(u32);
u8* func_00243150(u32);
void func_00103500(s16);
void func_00253538(s16);

void func_00243020(u32 a0) {
    if (!D_0032bad8) return;
    if (func_00103b38()) {
        if (func_00103428(func_00103550())) func_00103500(*(s16*)(func_00243150(a0) + 2));
    } else {
        func_00253538(*(s16*)(func_00243150(a0) + 2));
    }
}

struct Ent36 { u8 pad[32]; s8 ids[4]; };
extern Ent36 D_00371d90[];
s32 func_001a6d08(s32);

s32 func_00249480(s32 idx) {
    s32 r = 1;
    for (s32 i = 0; i < 4; i++) {
        s8 c = D_00371d90[idx].ids[i];
        if (c < 0) break;
        if (func_001a6d08(c)) {
            r = 0;
            break;
        }
    }
    return r;
}

s32 func_002576d0(void);
s32 func_00139d78(void*);
extern u8* D_0035f0f4;

s32 func_0026d180(void) {
    s32 r = func_002576d0();
    if (!r) {
        for (s32 i = 0; i < 5; i++) {
            if (func_00139d78(D_0035f0f4 + i * 436 + 3816)) {
                r = 1;
                break;
            }
        }
    }
    return r;
}

void func_00290060(void*);
void func_00138c10(void*, s32);
struct SprRef { u8* o; u32 pad[2]; s16 h12; };

void func_0028ff18(SprRef* p) {
    func_00290060(p);
    if (*(s32*)(p->o + 388) != p->h12) {
        func_00138c10(p->o, p->h12);
        *(s32*)(p->o + 392) = -1;
    }
}

extern u16 D_00374aa8[];

// Is id in the zero-terminated list?
s32 func_0029ec98(u32 id) {  // table_contains_short
    s32 r = 0;
    for (s32 i = 0; D_00374aa8[i] != 0; i++) {
        if (D_00374aa8[i] == id) {
            r = 1;
            break;
        }
    }
    return r;
}

extern u8* D_0035f610;
static inline u32 flagTest(u32 n) {
    u32* f = (u32*)(D_0035f610 + 316);
    return (f[n >> 5] & (1 << (n & 31))) != 0;
}

// Test flag n, or any of flags 0..12 when n < 0.
u32 func_002aa2f8(s32 n) {  // test_bit_global_b
    if (n < 0) {
        u32 r;
        for (s32 i = 0; i < 13; i++) {
            r = flagTest(i);
            if (r) break;
        }
        return r;
    }
    return flagTest(n);
}

extern u8 D_01e2aa80[];
void func_00324718(void*, void*);
u32 func_002b79cc(u32, u32, u32);
u32 func_002b986c(u32, u32);
u32 func_002b7440(u32, u32, u32);

u32 func_002bb510(u8* p) {
    func_00324718(D_01e2aa80, p);
    if (p[48] == 1) return 1;
    switch (p[49]) {
    case 5:
        return func_002b79cc(*(u32*)(p + 24), *(u32*)(p + 16), 0) != 0;
    case 6:
        return func_002b986c(*(u32*)(p + 24), *(u32*)(p + 16)) != 0;
    default:
        return func_002b7440(*(u32*)(p + 24), *(u32*)(p + 16), *(u32*)(p + 20)) != 0;
    }
}

void func_002edfd8(void*, void*);  // list_unlink_and_clear
s32 func_002be5b8(void*);
void func_0015f548(void);
void func_001c8e90(void);
void func_002be9b0(void);

void func_002be0b0(u8* p, s32 i) {  // quad_entry_process
    u8** slot = (u8**)((u8*)(i * 4) + (u32)p + 44);
    if (*slot) {
        func_002edfd8(p + 8, *slot);  // list_unlink_and_clear
        if (*slot) (*(VFn*)(*(u8**)*slot + 4))(*slot);
        *slot = 0;
    }
    if (!func_002be5b8(p)) {
        func_0015f548();
        func_001c8e90();
        func_002be9b0();
    }
}

extern f32 D_01e2be10;
extern f32 D_01e2be14;

}

void wtarget_002cb188(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) D_01e2be10 = 1.1344639f;
    if (b == 0xffff && a == 1) D_01e2be14 = 1.8325956f;
}

extern "C" {

extern u32 D_00361f60;

s32 func_002cf1f8(u8* a, u8* b) {
    if (D_00361f60 && (*(u32*)(a + 1416) & 0x8000000) && (*(u32*)(b + 1416) & 0x8000000))
        return *(u32*)(a + 2804) == *(u32*)(b + 2804);
    return 1;
}

struct Vec4f { f32 x, y, z, w; };
extern Vec4f D_00362d80;

}

void wtarget_002e1878(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        D_00362d80.x = D_00362d80.y = D_00362d80.w = 0.0f;
        D_00362d80.z = 590.0f;
    }
}

extern "C" {

s32 func_001b9bc8(u32);

// Call slot 17 on every other object with the same part number as this one.
void func_002e8a28(u32** p) {
    u32 me = (*p)[1];
    u32 type = func_0016a070((void*)me);
    u32 o = 0;
    while ((o = func_001b9bc8(o)) != 0) {
        if (func_0016a070((void*)o) == type && o != me) (*(VFn*)(*(u8**)o + 68))((void*)o);
    }
}

}
