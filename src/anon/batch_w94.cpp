#include "../common/types.h"
// ---- 00103590
extern "C" {
void func_001036d0(void*, u32);
void* func_00106178(void*, u32);
void* func_00104288(void);
u8* func_00170b30(u32);  // alloc_align128
extern void* D_0032ba14;
extern void* D_0032ba18;
extern s32 D_0032ba24;
extern u8 D_0032ba30;
extern s32 D_003a6a50;
extern u8 D_01f18014[];
extern u8 D_01f4a014[];

// Sets up the menu allocator: uses the given buffer, or picks one by menu mode.
void func_00103590(s32 lock, void* buf) {
    if (buf) {
        D_0032ba14 = buf;
        D_0032ba30 = 1;
        return;
    }
    s32 m = D_0032ba24;
    u8* p;
    if ((m == 1 && D_003a6a50 != 6) || m == 6) {
        p = D_01f18014;
        func_001036d0(p, 0xa0000);
    } else if (D_003a6a50 == 6) {
        p = D_01f4a014;
        D_0032ba14 = func_00106178(p, 0x40000);
        D_0032ba18 = func_00106178(p + 0x40000, 0x2e000);
    } else if (m == 2) {
        D_0032ba14 = func_00104288();
        D_0032ba18 = 0;
    } else {
        p = func_00170b30(0xa0000);  // alloc_align128
        D_0032ba14 = func_00106178(p, 0x38000);
        D_0032ba18 = func_00106178(p + 0x38000, 0x68000);
    }
    D_0032ba30 = lock != 0;
}
}
// ---- 00110500
extern "C" {
void func_0010e810(u8*, u8*);
f32 func_0010e7e0(u8*, s32);  // float2_get_by_index
extern u8* D_00341708;

static inline f32 vlen(void* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\t"
                 "vaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2 $8, $vi22\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(v) : "$8");
    return r;
}

void func_00110500(u8* p) {
    func_0010e810(p, p + 2944);
    switch (*(s32*)(p + 2924)) {
    case 12:
    case 15:
    case 16:
        if (func_0010e7e0(p, 1) < *(f32*)(p + 3084)) {  // float2_get_by_index
            f32 l = vlen(D_00341708 + 0x860);
            if (*(f32*)(p + 3084) < l) *(f32*)(p + 3084) = l + 2.0f;
        }
        break;
    case 13:
        if (func_0010e7e0(p, 1) < *(f32*)(p + 3084)) {  // float2_get_by_index
            f32 l = vlen(D_00341708 + 0x860);
            if (*(f32*)(p + 3084) < l) *(f32*)(p + 3084) = l;
        }
        break;
    }
}
}
// ---- 00136560
extern "C" {
s16* func_001aec40(void);  // get_global_1c9408c
void* func_002ba0f8(s32);
void* func_00136790(void*, u32*);
void func_001367e0(void*, void*, void*);
void func_002ba5d0(void*, u32);
void func_002ba7c8(void*);
void func_001367c8(void*);
void func_001364b8(void*, s32, s32);
extern s16 D_003b8b2c[];

void func_00136560(void* self) {
    s16* v = func_001aec40();  // get_global_1c9408c
    if (v[6] != D_003b8b2c[0]) {
        void* a = func_002ba0f8(v[6]);
        u32 n;
        void* b = func_00136790(a, &n);
        if (n) {
            func_001367e0(self, a, b);
            func_002ba5d0(b, n);
            func_002ba7c8(self);
        }
        func_001367c8(b);
    }
    if (v[7] != -1 && v[7] != D_003b8b2c[1]) func_001364b8(self, v[7], 10);
    if (v[8] != -1 && v[8] != D_003b8b2c[2]) func_001364b8(self, v[8], 11);
    if (v[9] != -1 && v[9] != D_003b8b2c[3]) func_001364b8(self, v[9], 12);
    if (v[10] != -1 && v[10] != D_003b8b2c[4]) func_001364b8(self, v[10], 13);
    if (v[11] != -1 && v[11] != D_003b8b2c[5]) func_001364b8(self, v[11], 14);
}
}
// ---- 00137fb8
extern "C" {
void func_0031a830(void*);
void func_0031a838(void*);
void func_0031a350(void*);
void func_00239700(void*);
void func_00137c50(void*);
extern u8* D_00347f80;
extern u32 D_00347d70[];
extern u32 D_00347f98[];
extern u32 D_00347e60[];
extern u32 D_00347db0[];
extern u8* volatile D_00347d64;
}
typedef u8* (*AllocFn)(void*, u32, u32);

void u_call0_00137fb8(void) {
    void** a = *(void***)(D_00347f80 + 20);
    u8* p = (*(AllocFn*)*a)(a, 18320, 0);
    *(u32*)(p + 12) = 0;
    *(u32**)p = D_00347d70;
    u32* r = (u32*)(p + 48);
    func_0031a830(p + 32);
    u8* q = p + 64;
    for (s32 i = 7; i != -1; i--) {
        func_0031a350(q);
        q += 1328;
    }
    r[0] = 0;
    r[1] = 0;
    u8** r2 = (u8**)(p + 10692);
    func_0031a830(p + 10688);
    q = p + 10700;
    for (s32 i = 15; i != -1; i--) {
        *(u32**)q = D_00347f98;
        func_0031a838(q + 12);
        *(u32**)q = D_00347e60;
        func_00239700(q + 24);
        *(u32*)(q + 408) = 0;
        *(u32**)q = D_00347db0;
        q += 476;
    }
    r2[0] = 0;
    r2[1] = 0;
    D_00347d64 = p;
    func_00137c50(D_00347d64);
}
// ---- 00140500
extern "C" {
f32 func_0017ce10(f32);
void func_0011b6a8(f32*);
void func_0011b6d8(f32*, f32);
void func_0011b720(f32*, f32);
extern f32 D_004573f0;
extern f32 D_004573f4;
}
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));

static inline void qcopy(V4* d, V4* s) {
    if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
static inline void mulv(V4* out, f32* m, V4* v) {
    V4 t;
    asm volatile("lqc2 $vf5, 0(%1)\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tlqc2 $vf4, 48(%0)\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\t"
                 "vmaddw.xyzw $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%2)" : : "r"(m), "r"(v), "r"(&t) : "memory");
    qcopy(out, &t);
}
static inline void addv(V4* out, V4* a, V4* b) {
    V4 t;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&t), "r"(a), "r"(b) : "memory");
    qcopy(out, &t);
}

extern "C" {
void func_00140500(u8* p) {
    *(f32*)(p + 192) = func_0017ce10(*(f32*)(p + 192));
    f32 v = func_0017ce10(*(f32*)(p + 196));
    *(f32*)(p + 196) = v;
    if (D_004573f4 < v) *(f32*)(p + 196) = D_004573f4;
    else if (v < D_004573f0) *(f32*)(p + 196) = D_004573f0;
    V4 d;
    f32 m[16] __attribute__((aligned(16)));
    d.w = d.y = d.x = 0.0f;
    d.z = 350.0f;
    func_0011b6a8(m);
    func_0011b6d8(m, *(f32*)(p + 196));
    func_0011b720(m, *(f32*)(p + 192));
    mulv(&d, m, &d);
    addv((V4*)(p + 128), (V4*)(p + 96), &d);
}
}
// ---- 00156d20
extern "C" {
u32 func_00158290(u8*);
u32 func_0013a7e8(s32);
u32 func_0013d7e0(void);
u32 func_00155f40(u8*);
u32 func_00155fc0(u8*);
void func_00138c10(u8*, u32);
s32 func_00139c18(u8*);
void func_001386e0(u8*, s32, u32, u32, s32, u32);
void func_001396b0(u8*);
void func_0031a260(u8*, s32);

void func_00156d20(u8* p) {
    u8* q = p + 11648;
    u32 a = func_00158290(p);
    u32 b = func_0013a7e8(1);
    u32 c = func_0013d7e0();
    func_00138c10(q, func_00155f40(p));
    func_00138c10(p + 12060, func_00155fc0(p));
    p[15606] = 1;
    if (p[15611] == 1) {
        u8* e = p + func_00139c18(p + 4180) * 408 + 4180;
        func_001386e0(e, 7000, b, c, 53, a);
        *(u8**)(e + 396) = q;
        func_001396b0(e);
        if (*(u32*)(e + 396)) {
            *(u32*)(e + 400) = 0;
            func_001396b0(e);
            if (*(u32*)(e + 400)) func_0031a260(e, 0);
        }
    }
}
}
// ---- 0015bab8
extern "C" {
void func_0014b1e0(u8*, s32, s16);
void func_0014bb00(u8*, s32, s16, s32, s32);

void func_0015bab8(u8* p) {
    func_0014b1e0(p + 624, 408, *(s16*)(p + 2932) + 8);
    func_0014b1e0(p + 880, 408, *(s16*)(p + 2932));
    func_0014b1e0(p + 1136, 408, *(s16*)(p + 2932) + 88);
    func_0014b1e0(p + 1392, 400, *(s16*)(p + 2932) + 8);
    func_0014b1e0(p + 1648, 488, *(s16*)(p + 2932) + 8);
    func_0014b1e0(p + 1904, 400, *(s16*)(p + 2932));
    func_0014b1e0(p + 2160, 488, *(s16*)(p + 2932));
    func_0014b1e0(p + 2416, 400, *(s16*)(p + 2932) + 88);
    func_0014b1e0(p + 2672, 488, *(s16*)(p + 2932) + 88);
    func_0014bb00(p, 400, *(s16*)(p + 2932), 96, 96);
}
}
// ---- 00179308
extern "C" {
u32 func_00177860(u8*);
s32 func_001c3618(u32, s32);
s32 func_0019c090(u8*);  // obj_is_enabled
s32 func_001b9d40(u8*);  // vtable_call_slot64_flags
u8* func_001ce300(s32);  // to_1ce2a0_index_minus1
f32 func_00184a90(u8*);
u8* func_0016c028(u8*);  // obj_get_attach_or_alt
void func_0016bd60(u8*, s32);

static inline u8 busy(u8* p) {
    u8 r = 0;
    if ((*(u32*)(*(u8**)(p + 12) + 8) & 2) || (*(u32*)(p + 352) & 0x40)) r = 1;
    return r;
}

s32 func_00179308(u8* p) {
    s32 r = func_001c3618(func_00177860(p), 3);
    if (r > 0 && !busy(p) && func_0019c090(p) && func_001b9d40(p)) {  // obj_is_enabled
        u8* e = func_001ce300(r);  // to_1ce2a0_index_minus1
        f32 d = func_00184a90(p) - *(f32*)(func_0016c028(p) + 4) > 0.0f
                    ? func_00184a90(p) - *(f32*)(func_0016c028(p) + 4) : 0.0f;
        if (*(f32*)(e + 52) < d) {
            *(u8**)(p + 240) = e;
            if (*(f32*)(p + 28) == 0.0f) func_0016bd60(p, 17);
            else func_0016bd60(p, 18);
            *(u32*)(p + 268) |= 4;
            return 1;
        }
    }
    return 0;
}
}
// ---- 00198ee8
extern "C" {
s32 func_00181500(u32);
void func_00181178(u32);
void func_001a6c90(s32);  // set_bit_in_array_b
u32 func_001a8258(u32);
void func_001a8438(u32);
void func_0019b2b0(u32);
void func_0019b2d8(u32);

struct Ent198 {
    u16 type : 2;
    u16 id : 13;
};

struct Obj198 {
    s32 state;
    u32 _4;
    u32 se;
    s32 bgm;
    u8 _10[8];
    s32 nres;
    u32* res;
    Ent198 ents[7];
    s16 nents;
};

void func_00198ee8(Obj198* o) {
    if (o->se != 0xffff && !func_00181500(o->se)) func_00181178(o->se);
    if (o->bgm >= 0) func_001a6c90(o->bgm);  // set_bit_in_array_b
    if (o->nres > 0)
        for (s32 i = 0; i < o->nres; i++) func_001a8438(func_001a8258(o->res[i]));
    for (s32 i = 0; i < o->nents; i++) {
        switch (o->ents[i].type) {
        case 0: func_0019b2d8(o->ents[i].id); break;
        case 1: func_0019b2b0(o->ents[i].id); break;
        }
    }
    o->state = -1;
}
}
// ---- 001bf168
extern "C" {
void func_00169398(u8*, u32, u32*, s32, u32, f32);
void func_0016bd60(u8*, s32);
extern u32 D_003638d0;
extern u32 D_003512e8[];

static inline f32 frand(void) {
    u32 s = D_003638d0 * 69069;
    D_003638d0 = s;
    return (f32)s * 2.3283064e-10f;
}
static inline f32 rrange(f32 lo, f32 hi) {
    return lo + frand() * (hi - lo);
}

void func_001bf168(u8* p, u32* src, u32 arg, u32 owner, f32 f) {
    func_00169398(p, *src, src, 4, arg, rrange(-3.1415927f, 3.1415927f));
    *(u32*)(p + 1416) |= 0x40000;
    *(u32*)(p + 2484) = owner;
    *(f32*)(p + 2488) = f;
    *(f32*)(p + 60) = f;
    *(u32*)p = (u32)D_003512e8;
    *(u32*)(p + 264) |= 2;
    *(u32*)(p + 2528) = 0;
    *(u32*)(p + 2532) = 0;
    *(u32*)(p + 2536) = 0;
    func_0016bd60(p, 12);
}
}
// ---- 001c0d38
extern "C" {
s32 func_001c0cd8(u8*);
void func_001c0e60(u8*);
void func_0016bd60(u8*, s32);
}

struct Node1c0 {
    u8 _0[236];
    Node1c0* next;
};
struct List1c0 {
    Node1c0* head;
    Node1c0* tail;
};

static inline u8 busy2(u8* p) {
    u8 r = 0;
    if ((*(u32*)(*(u8**)(p + 12) + 8) & 2) || (*(u32*)(p + 352) & 0x40)) r = 1;
    return r;
}

#define p ((u8*)self)
#define owner ((u8*)own)
u8* u_tail4_001c0d38(u32 self, u32 own, u32 a, u32 b) {
    if (func_001c0cd8(p)) func_001c0e60(p);
    *(u16*)(p + 1396) = a;
    *(u8**)(p + 1392) = owner;
    *(u16*)(p + 1398) = b;
    asm volatile("" ::: "memory");
    u32 st = busy2(p) ? 5 : 0;
    *(u32*)(p + 1404) = 0;
    *(u32*)(p + 1400) = st;
    asm volatile("sqc2 $vf0, 0(%0)" : : "r"(p + 1344) : "memory");
    if (!(b & 2)) {
        asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(p + 1360) : "memory");
        *(u32*)(p + 2040) |= 8;
    }
    func_0016bd60(p, 3);
    List1c0* l = (List1c0*)(owner + 1888);
    Node1c0* n = (Node1c0*)(p + 1648);
    if (l->tail == 0) { l->tail = n; l->head = n; *(u32*)(p + 1884) = 0; } else { l->tail->next = n; *(u32*)(p + 1884) = 0; l->tail = n; }
    if (*(u32*)(p + 2060) == 0) *(u32*)(p + 1548) = *(u32*)(owner + 2060);
    else if (*(u32*)(owner + 2060) == 0) *(u32*)(owner + 1548) = *(u32*)(p + 2060);
    return p + 1392;
}
#undef p
#undef owner
// ---- 001f04a8
extern "C" {
void func_001f0430(u8*, f32*);
f32 func_002f8b00(f32, f32);  // to_2f9a38
extern s32 D_01d9ea9c;
extern u8* D_01d9e6e0;
extern s32 D_01d9eab4;

void func_001f04a8(u8* self, u8* ent, u8* desc) {
    f32* s = (f32*)(self + *(u32*)(*(u8**)(desc + 12) + 8) + 160);
    if (*(u32*)s == 0) func_001f0430(ent, s);
    if (D_01d9ea9c) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) return;
    if (*(u32*)ent == *(u32*)(self + 12)) {
        s[2] += *(f32*)(ent + 12);
        s[3] += *(f32*)(ent + 16);
        s[5] += *(f32*)(ent + 24);
        s[6] += *(f32*)(ent + 28);
    }
    if (D_01d9eab4) return;
    s[2] += s[3];
    s[1] += s[2];
    s[5] += s[6];
    s[4] += s[5];
    s[1] = func_002f8b00(s[1], 32768.0f);  // to_2f9a38
    s[4] = func_002f8b00(s[4], 32768.0f);  // to_2f9a38
}
}
// ---- 00225898
extern "C" {
s32 func_002282f0(s32);
s32 func_002b7148(s32);
void func_002ba298(s32);
u32 func_002bd260(s16);
u8* func_00227a60(u32, s32);
u32 func_002bd2f0(u32, u32*);
void func_002bd230(u32, s16);
void func_00136b48(s32, s16);  // entry16_set_word0
void func_00136b60(s32, s16);
void func_00136b78(s32, s32);  // entry16_set_field8
void func_00225738(void);
void func_002baf48(s32, s32, u32, u32, void (*)(void), u8*);

void func_00225898(u8* p) {
    if (func_002282f0(*(u16*)(p + 4))) return;
    if (func_002b7148(1)) func_002ba298(1);
    u8* a = func_00227a60(func_002bd260(*(s16*)(p + 8)), 6);
    u32 id = 0;
    u32 q = func_002bd2f0(*(u32*)(a + 20), &id);
    func_002bd230(id, *(s16*)(p + 8));
    u8* b = func_00227a60(q, 5);
    s32 m = *(s16*)(p + 6);
    if (m == 2) {
        m = 0;
        func_00136b48(0, *(s16*)(p + 8));  // entry16_set_word0
        func_00136b48(1, *(s16*)(p + 8));  // entry16_set_word0
        func_00136b60(0, *(s16*)(p + 8));
        func_00136b60(1, *(s16*)(p + 8));
    } else {
        func_00136b48(m, *(s16*)(p + 8));  // entry16_set_word0
        func_00136b60(m, *(s16*)(p + 8));
    }
    func_00136b78(m, 0);  // entry16_set_field8
    func_002baf48(m, 2, *(u32*)(a + 20), *(u32*)(a + 28), func_00225738, a);
    func_002baf48(0, 1, *(u32*)(b + 20), *(u32*)(b + 28), func_00225738, b);
}
}
// ---- 00226ac0
extern "C" {
s32 func_00197920(void);
void func_00226ea0(void);
void func_00227200(s32);
void func_00227130(u32);
void func_00228150(s32);
void func_002272a8(void);
extern u32 D_0035de8c;
extern u32 D_0035de18;
extern u32 D_0035de80;
extern u32 D_0035de68;
extern u32 D_0035de6c;
extern u32 D_0035de84;
extern u8 D_0035de14;
extern f32 D_0035de48;
extern u32 D_0035de88;
extern u8 D_0035de15;
extern u8 D_0035de0c;
extern u8 D_0035de44;

s32 func_00226ac0(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    if (func_00197920()) func_00226ea0();
    D_0035de8c = e;
    D_0035de18 = b;
    D_0035de80 = c;
    D_0035de68 = f;
    D_0035de6c = g;
    D_0035de84 = d;
    D_0035de14 = 0;
    D_0035de48 = 1.0f;
    D_0035de15 = 0;
    D_0035de88 = 0;
    D_0035de44 = 0;
    D_0035de0c = 0;
    func_00227200(0);
    func_00227130(a);
    func_00228150(1);
    func_002272a8();
    return 0;
}
}
// ---- 0022ea28
extern "C" {
s32 func_002282f0(s32);
u32 func_002282d8(void);  // limit_15000_or_25000
u8* func_00227d10(s16);
void func_001ba028(u32);  // list_contains_ptr
s32 func_00225b00(s16);  // flag_query_by_index
void func_0022e998(void);
void func_0022e9f8(void);
u8* func_00102c18(s32, u32, void (*)(void));
u32 func_001050c8(void);
u8* func_001063c0(s32, u32);
f32 func_00227c78(u8*);
void func_002f12b0(u8*, u32, s32, f32, f32);
void func_0016aeb8(u32, f32);

union Slot { u8* p; s16 h; };

void func_0022ea28(u8* p) {
    if (func_002282f0(*(s16*)(p + 4))) return;
    u32 parent = func_002282d8();  // limit_15000_or_25000
    u8* m = func_00227d10(*(s16*)(p + 6));
    func_001ba028(*(u32*)(m + 8));  // list_contains_ptr
    if (func_00225b00(*(s16*)(p + 4)) == 0) {  // flag_query_by_index
        u8* o = func_00102c18(1, parent, func_0022e998);
        *(void (**)(void))(o + 48) = func_0022e9f8;
        u8* n = func_001063c0(24, func_001050c8());
        ((Slot*)(o + 8))->p = n;
        func_002f12b0(n, *(u32*)(m + 8), *(s16*)(p + 8), func_00227c78(p + 12), *(s16*)(p + 10) * 2.0f);
    } else {
        func_0016aeb8(*(u32*)(m + 8), 3.1415927f - func_00227c78(p + 12) * 0.017453292f);
    }
}
}
// ---- 00243e30
extern "C" {
s32 func_00139d78(void*);
s32 func_0023f0c0(void*);
void func_0023f070(void*, s32, s32);
s32 func_0028acc8(void*);
void func_0028ab20(void*);
u32 func_002891e8(void*);
s32 func_00244ee8(u32);
void func_0028da70(void*, s32);
extern void* D_0035ecf0;
extern void* D_0035ecf4;
extern void* D_0035ecf8;
extern void* D_0035ecfc;
extern void* D_0035ed00;
extern void* D_0035ece8;
struct Ent243 { s16 a, b, mot; };
extern Ent243 D_00371968[];

void func_00243e30(void) {
    if (func_00139d78(D_0035ecf0) && func_0023f0c0(D_0035ecf0) != 32) func_0023f070(D_0035ecf0, 32, -1);
    if (func_0028acc8(D_0035ece8)) {
        func_0028ab20(D_0035ece8);
        s32 k = func_00244ee8(func_002891e8(D_0035ece8));
        if (func_00139d78(D_0035ecf8) && func_0023f0c0(D_0035ecf8) != D_00371968[k].mot)
            func_0023f070(D_0035ecf8, D_00371968[k].mot, -1);
    }
    if (func_00139d78(D_0035ecf4) && func_0023f0c0(D_0035ecf4) != 35) func_0023f070(D_0035ecf4, 35, -1);
    func_0028da70(D_0035ecfc, 33);
    func_0028da70(D_0035ed00, 41);
}
}
// ---- 00243f48
extern "C" {
s32 func_00139d78(void*);
s32 func_0028acc8(void*);
void func_0028abe0(void*);
void func_00244db8(void);
void func_0028ce38(void);
extern void* D_0035ecf0;
extern void* D_0035ecf4;
extern void* D_0035ecf8;
extern void* D_0035ecfc;
extern void* D_0035ed00;
extern void* D_0035ece8;
extern void* D_0035ecec;
}
typedef void (*VFn243)(void*);
#define VCALL20(o) (*(VFn243*)(*(u8**)(o) + 20))(o)

extern "C" {
void func_00243f48(void) {
    if (func_00139d78(D_0035ecf0)) VCALL20(D_0035ecf0);
    if (func_00139d78(D_0035ecf8)) VCALL20(D_0035ecf8);
    if (func_00139d78(D_0035ecf4)) VCALL20(D_0035ecf4);
    if (func_0028acc8(D_0035ece8)) func_0028abe0(D_0035ece8);
    if (func_0028acc8(D_0035ecec)) func_0028abe0(D_0035ecec);
    if (func_00139d78(D_0035ecfc)) VCALL20(D_0035ecfc);
    if (func_00139d78(D_0035ed00)) VCALL20(D_0035ed00);
    func_00244db8();
    func_0028ce38();
}
}
// ---- 00268b30
extern "C" {
u8* func_00257770(void);
s32 func_00287bc0(void);
u32 func_002570a0(s32);
u32 func_0026a178(u32, s32);
u16* func_001a8190(u32);
u16* func_001a80c8(u16);  // table24_find_by_id
u32 func_00257140(s32);
void func_0028d980(u8*, s32, u32, u32, u32, u32, s32, s32, s32);
u32 func_00192048(u16);
void func_0028dcc0(u8*, u8*);
void func_00139620(u8*);
void func_001395f8(u8*);
u32 func_0023aa18(u8*);
u32 func_0023aa38(u8*);
u32 func_0023aa98(u8*);
void func_00138c68(u8*, u32, u32);
extern u32 D_0035ef64;
extern u32 D_0035ef68;
extern u32 D_0035f03c;

void func_00268b30(s32 idx) {
    u8* w = func_00257770();
    u32 st = func_00287bc0();
    if (st - 5 >= 2) return;
    u16 id = func_001a8190(func_0026a178(func_002570a0(2), 2))[1];
    if (!id) return;
    u8* o = w + 2504;
    id = func_001a80c8(id)[4];
    u8* m = w + 1656;
    func_0028d980(o, idx + 1, D_0035ef68, D_0035ef64, D_0035f03c, func_00257140(2), -1, -1, 0);
    *(u32*)(o + 408) = func_00192048(id);
    func_0028dcc0(o, w + 1632);
    func_00139620(o);
    func_001395f8(o);
    u32 a = func_0023aa18(m);
    u32 b = func_0023aa38(m);
    u32 c = func_0023aa98(m);
    func_00138c68(o, a, b);
    *(u32*)(o + 424) = c;
    *(u32*)(o + 432) = 1;
}
}
// ---- 00284538
extern "C" {
s32 func_00139d78(void*);
s32 func_0028acc8(void*);
extern u8* D_0035f2c8;
extern u8* D_0035f2cc;
extern u8* D_0035f2d8;
extern u8* D_0035f2dc;
}
typedef void (*VFn284)(u8*);
#undef VCALL20
#define VCALL20(o) (*(VFn284*)(*(u8**)(o) + 20))(o)

extern "C" {
s32 func_00284538(void) {
    s32 r = func_00139d78(D_0035f2c8);
    if (r) goto out;
    r = func_00139d78(D_0035f2cc);
    if (r) goto out;
    r = func_00139d78(D_0035f2cc + 436);
    if (r) goto out;
    for (s32 i = 0; i < 8; i++) {
        if (func_00139d78(D_0035f2cc + i * 436 + 872)) VCALL20(D_0035f2cc + i * 436 + 872);
        if (func_00139d78(D_0035f2cc + i * 436 + 4360)) VCALL20(D_0035f2cc + i * 436 + 4360);
    }
    if (r) goto out;
    r = func_00139d78(D_0035f2d8);
    if (r) goto out;
    r = func_0028acc8(D_0035f2dc);
out:
    return r;
}
}
// ---- 0029e808
extern "C" {
s32 func_00276638(s32);
u8* func_0029da68(s16);
void func_0023e788(f32*, u32, s32);
s32 func_0029ec40(u16);
double func_00313b80(f32);  // float_to_double
s32 func_003142e0(double, double);  // double_compare
void func_0023e8d8(u32, s32, f32);
extern s16* D_0035f5ac;
extern u32 D_0035f5bc;

void func_0029e808(s32 dir) {
    u8* e = func_0029da68(D_0035f5ac[func_00276638(15) + 4]);
    f32 v[4] __attribute__((aligned(16)));
    func_0023e788(v, D_0035f5bc, 0);
    f32 a = v[1];
    if (dir == -12) {
        a += 2.0f;
        if (func_0029ec40(*(u16*)(e + 12)) && 16.0f < a) a = 16.0f;
    } else {
        a -= 2.0f;
        if (func_0029ec40(*(u16*)(e + 12)) && a < -16.0f) a = -16.0f;
    }
    double d = func_00313b80(a);  // float_to_double
    if (func_003142e0(360.0, d) <= 0) a -= 360.0f;
    else if (func_003142e0(d, -360.0) <= 0) a += 360.0f;
    func_0023e8d8(D_0035f5bc, 0, a);
}
}
// ---- 002a4470
extern "C" {
u8* func_002766d0(void);
void func_00138c78(u8*, u32*, u32*);
void func_0028d8c0(u8*, s32, u32, u32, u32, s32, s32, s32);
void func_00139620(u8*);
void func_0028dcc0(u8*, u8*);
void func_00138c68(u8*, u32, u32);
void func_00275980(s32, u8*);
void func_002759e8(u8*);
s32 func_002a4990(s32);
void func_00138c10(u8*, u32);
extern u8* D_0035f5e4;
extern u8* D_0035f5e8;
extern s32 D_0035f3d4;
extern u32 D_0035f148;
extern u32 D_0035f14c;
extern u32 D_0035f210;

void func_002a4470(void) {
    u8* x = func_002766d0();
    s32 n = *(s32*)(D_0035f5e4 + 4232);
    s32 r = n % 8;
    u8* o = D_0035f5e8 + (n / 8) * 3264 + r * 408;
    u32 t0, t1;
    func_00138c78(o, &t0, &t1);
    o = D_0035f5e8 + 29376;
    func_0028d8c0(o, D_0035f3d4 + 1, D_0035f14c, D_0035f148, D_0035f210, 65, -1, 0);
    func_00139620(o);
    func_0028dcc0(o, x);
    func_00138c68(o, t0, t1);
    func_00275980(0, o);
    func_002759e8(o);
    u8* g = D_0035f5e4;
    if (!g[func_002a4990(-1) * 8 + 4096]) func_00138c10(o, 66);
}
}
// ---- 002eaf48
extern "C" {
void func_002cbf08(void*, u32);
void func_0016af58(void*, u8*);
double func_00313b80(f32);  // float_to_double
s32 func_003142e0(double, double);  // double_compare
void* func_002cb8b8(u32);
void* func_002cb8e0(u32);
u8* func_0016c028(u8*);  // obj_get_attach_or_alt
void func_002cb7a0(u32, s32, void*);
}
struct V4e { f32 x, y, z, w; } __attribute__((aligned(16)));

static inline void qcopy(V4e* d, void* s) {
    if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
static inline f32 vdot(V4e* a, V4e* b) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\t"
                 "vaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(a), "r"(b) : "$8", "memory");
    return r;
}

extern "C" {
V4e* func_002eaf48(V4e* out, u8* obj, u8 notify) {
    u32 h = *(u32*)(obj + 1288);
    V4e t;
    func_002cbf08(&t, h);
    qcopy(out, &t);
    *(u32*)&out->y = 0;
    func_0016af58(&t, obj);
    if (func_003142e0(func_00313b80(vdot(out, &t)), 0.0) < 0) {  // double_compare
        qcopy(out, func_002cb8b8(h));
        if (notify) func_002cb7a0(h, 0, func_0016c028(obj));
    } else {
        qcopy(out, func_002cb8e0(h));
        if (notify) func_002cb7a0(h, 1, func_0016c028(obj));
    }
    return out;
}
}
// ---- 002e71a0
extern "C" {
u32 func_002e64e8(u8, u8, u32);
u8* func_002e64b8(u32, u32);  // list_advance_count
}
struct Skel2e7 {
    u32 id;
    u8* mats;
};

static inline void mcopy4(void* d, void* s) {
    asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                 "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                 : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory");
}
static inline void mmul(void* d, void* a, void* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf6x\n\tvmadday.xyzw ACC, $vf2, $vf6y\n\tvmaddaz.xyzw ACC, $vf3, $vf6z\n\tvmaddw.xyzw $vf6, $vf4, $vf6w\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf7x\n\tvmadday.xyzw ACC, $vf2, $vf7y\n\tvmaddaz.xyzw ACC, $vf3, $vf7z\n\tvmaddw.xyzw $vf7, $vf4, $vf7w\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf8x\n\tvmadday.xyzw ACC, $vf2, $vf8y\n\tvmaddaz.xyzw ACC, $vf3, $vf8z\n\tvmaddw.xyzw $vf8, $vf4, $vf8w\n\t"
                 "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)"
                 : : "r"(d), "r"(a), "r"(b) : "memory");
}

// Builds a bone's model matrix by walking up its parent chain.
f32* ctarget_002e71a0(u32 out_, u32 skel_, u32 a, u32 b) {
    f32* out = (f32*)out_;
    Skel2e7* sk = (Skel2e7*)skel_;
    u32 i = func_002e64e8(a, b, sk->id);
    u8* bone = func_002e64b8(i, sk->id);  // list_advance_count
    mcopy4(out, sk->mats + i * 64);
    u32 p;
    while ((p = bone[2]) < 255) {
        f32 tmp[16] __attribute__((aligned(16)));
        bone = func_002e64b8(p, sk->id);  // list_advance_count
        mmul(tmp, sk->mats + p * 64, out);
        if (out != tmp) mcopy4(out, tmp);
    }
    return out;
}
