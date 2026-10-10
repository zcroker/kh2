#include "../common/types.h"

struct u128 { u32 w[4]; } __attribute__((aligned(16)));
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

// 16-byte vector with a qword copy constructor and a self-checking assignment.
struct Vq {
    union { u128 q; f32 f[4]; };
    Vq() {}
    Vq(const Vq& o) { QCOPY(this, &o); }
    void operator=(const Vq& o) { if (this != &o) QCOPY(this, &o); }
};

// Same, but the copy constructor's qword move is never split by the assembler.
struct Vr {
    union { u128 q; f32 f[4]; };
    Vr() {}
    Vr(const Vr& o) {
        asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder"
                     : : "r"(this), "r"(&o) : "$8", "memory");
    }
    void operator=(const Vr& o) { if (this != &o) QCOPY(this, &o); }
};

// Local whose (empty) destructor keeps the final call from becoming a tail call.
struct NoTail { ~NoTail() {} };

extern "C" {

void func_002fd160(void) __attribute__((noreturn));

struct EhObject { u32 pc_begin; u32 tbase; u32 dbase; };
// base_from_object: base address for a DWARF EH pointer encoding.
u32 func_00100920(u8 encoding, EhObject* ob) {  // classify_subtype
    if (encoding == 0xff) return 0;
    switch (encoding & 0x70) {
    case 0x00:
    case 0x10:
    case 0x50:
        return 0;
    case 0x20:
        return ob->tbase;
    case 0x30:
        return ob->dbase;
    }
    func_002fd160();
}

struct Node2180 { u8 pad[12]; Node2180* next; u8 pad2[12]; s32 state; };
extern Node2180* D_0038aa40;
static inline Node2180* Next2180(Node2180* n) {
    if (!n) return D_0038aa40;
    return n->next;
}
// Collects every list node whose state is 1; returns the count.
s32 func_00102180(Node2180** out) {
    Node2180* n = 0;
    s32 count = 0;
    while ((n = Next2180(n))) {
        if (n->state == 1) {
            *out++ = n;
            count++;
        }
    }
    return count;
}

void func_0010a800(u8*, u8*, u8*);  // copy_global_3bytes
void func_00108698(u8* p) {
    *(u32*)p = 0;
    p[7] = 0x80;
    p[6] = 0x80;
    p[5] = 0x80;
    p[4] = 0x80;
    func_0010a800(p + 8, p + 9, p + 10);  // copy_global_3bytes
    p[11] = 0xff;
    p[43] = 0x80;
    p[42] = 0x80;
    p[41] = 0x80;
    *(u64*)(p + 24) = 0x31000070;
    *(u64*)(p + 16) = 0x800d8;
    *(u32*)(p + 32) = 0;
    *(u32*)(p + 36) = 0;
    p[40] = 0;
    *(u32*)(p + 44) = 0;
    *(u32*)(p + 48) = 0;
    *(u32*)(p + 52) = 0;
}

struct VObj1246 { u32 (**vt)(...); };
VObj1246* func_00124748(u32, u32);  // list_nth_node_rel
typedef u32 (*Fn1246)(VObj1246*, u32, u32, u32, u32, u8, u32);
u32 func_001246b8(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0, u8 t1, u32 t2) {
    VObj1246* o = func_00124748(a0, 0);  // list_nth_node_rel
    return ((Fn1246)o->vt[22])(o, a1, a2, a3, t0, t1, t2);
}

void func_00132270(u8*);  // obj_ctor_347c00
void func_00108398(u8*);  // clear_quads_set_flags
extern u8 D_00347c30[];
// Constructor: base, vtable, four 144-byte members at +48.
void func_00132430(u8* p) {
    func_00132270(p);  // obj_ctor_347c00
    *(u32*)p = (u32)D_00347c30;
    u8* e = p + 48;
    for (s32 i = 3; i != -1; i--) {
        func_00108398(e + 16);  // clear_quads_set_flags
        e += 144;
    }
    *(u32*)(p + 8) = 1;
    *(u32*)(p + 628) = 0;
    *(u32*)(p + 632) = 0;
    *(u32*)(p + 636) = 0;
    *(u32*)(p + 624) = 0;
}

extern u32 D_0034a3f0;
extern f32* D_0034a3f4;
extern f32 D_0034a3f8;
f32* func_0016c028(u32);  // obj_get_attach_or_alt
f32 func_002f8ad0(f32, f32);
// Yaw/pitch (atan2) of the offset between two points.
void func_0014e658(u8* p) {
    f32 d[4] __attribute__((aligned(16)));
    f32* a = D_0034a3f4;
    f32* b = func_0016c028(D_0034a3f0);  // obj_get_attach_or_alt
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(d), "r"(a), "r"(b) : "memory");
    d[1] += D_0034a3f8;
    *(f32*)(p + 192) = func_002f8ad0(d[0], d[2]);
    *(f32*)(p + 196) = -func_002f8ad0(d[1], __builtin_sqrtf(d[0] * d[0] + d[2] * d[2]));
}

extern f32 D_004f3580;
extern f32 D_004f3584;
void wtarget_0014ec40(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_0014ec40jjjj");
void wtarget_0014ec40(u32 a0, u32 a1, u32 a2, u32 a3) {
    if (a1 == 0xffff && a0 == 1) D_004f3580 = -0.523598731f;
    if (a1 == 0xffff && a0 == 1) D_004f3584 = 1.22173035f;
}

void func_00159ce0(u8*, Vq*);
void func_0013f888(u8*, Vq*, u32);
void func_0013fca8(u8*);
void func_0015a528(u8* p) {
    Vq* q = (Vq*)(p + 128);
    Vq saved(*q);
    Vq v;
    func_00159ce0(p, &v);
    func_0013f888(p, &v, 0);
    *q = v;
    func_0013fca8(p);
    *q = saved;
}

void func_00141010(f32);
u8* func_00140df0(void);
s32 func_00140dc0(void);
void func_0015a6c8(u8*);
extern f32 D_0034aa84;
void func_0015a638(u8* p) {
    func_00141010(30.0f);
    u8* o = func_00140df0();
    o[59] = 1;
    s32 m = func_00140dc0();
    if (m == 6 || m == 8) return;
    f32 x = *(f32*)(o + 72);
    *(u32*)(o + 64) = 2;
    D_0034aa84 = x;
    func_0015a6c8(p);
}

extern u8 D_0034c70c;
extern u8 D_0034c6f0[];
s32 func_001de568(u8*);
void func_001dde40(u8*);
void func_00142f50(void);
void func_0015edb8(void) {
    if (D_0034c70c == 1) {
        if (func_001de568(D_0034c6f0)) func_001dde40(D_0034c6f0);
    }
    D_0034c70c = 0;
    func_00142f50();
}

struct Blk64 {
    u128 q[4];
    void operator=(const Blk64& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
};
struct VObj6 { s32 (**vt)(VObj6*, Blk64*); };
void func_001616d8(Blk64*);
void func_001616f0(Blk64* p) {
    Blk64 b;
    VObj6* o = *(VObj6**)((u8*)p + 72);
    if (!o) return;
    if (o->vt[6](o, &b)) {
        func_001616d8(p);
        return;
    }
    *p = b;
}

struct V4 { f32 x, y, z, w; };
extern s8 D_01c5f490;
extern V4 D_01c5f4a0;
void func_00175528(void);
void func_002fd188(void (*)(void));  // pool_alloc_block
u32 func_0016f000(u32, V4*, f32);
// Function-local static vector (0,0,0,1) with its guard and atexit registration.
void func_00170f98(u32* p) {
    if (D_01c5f490 == 0) {
        f32 z = 0.0f;
        D_01c5f4a0.x = z;
        D_01c5f4a0.y = z;
        D_01c5f4a0.z = z;
        D_01c5f4a0.w = 1.0f;
        D_01c5f490 = 1;
        func_002fd188(func_00175528);  // pool_alloc_block
    }
    *p = func_0016f000(*p, &D_01c5f4a0, 3.14159274f);
}

static inline bool isPos(f32 x) { return 0.0f < x; }
struct S17f { u8 pad[48]; f32 f30; f32 f34; u8 pad2[104]; Vr v; };
// Returns v scaled by f30/f34 (w cleared), or v unchanged if f34 <= 0.
Vr func_0017ff68(S17f* s) {
    bool pos = isPos(s->f34);
    if (pos) {
        Vr r;
        Vr t;
        f32 k = s->f30 / s->f34;
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                     : : "r"(&t), "r"(&s->v), "f"(k) : "$8", "memory");
        r = t;
        r.f[3] = 0.0f;
        return r;
    }
    return s->v;
}

struct Slot180 { u32 obj; u32 key; };
u32 func_00198580(u32, u32);  // check_div1000_500
// Ensures `key` has an object in the 8-slot table (filled into the last free slot).
void func_00180b10(u8* t, u32 key) {
    s32 slot = -1;
    s32 i = 0;
    Slot180* e = (Slot180*)(t + 256);
    for (; i < 8; i++, e++) {
        if (e[1].obj == 0) slot = i;
        else if (e[1].key == key) return;
    }
    Slot180* s = (Slot180*)((u8*)(slot * 8) + (u32)t + 256);
    u32 o = func_00198580(*(u32*)(t + 8), key);  // check_div1000_500
    s[1].obj = o;
    s[1].key = key;
}

struct Act { u8 pad[140]; u32 f8c; u8 pad2[8]; s32 f98; u32 f9c; };
struct Pri { u16 h0; u16 h2; u16 h4; };
Pri* func_00187ab8(u32);
void func_00187f90(Act*);
void func_00187fd8(Act*, Pri*);
void act_pri_start(Act* a) asm("_ZN2YS3ACT9pri_startEPc");
void act_pri_start(Act* a) {
    u32 m = a->f9c & 1;
    u8 on = m;
    if (on) return;
    Pri* r = func_00187ab8(a->f8c);
    if (!r) return;
    if (r->h4 < a->f98) return;
    func_00187f90(a);
    func_00187fd8(a, r);
}

s32 func_001c0cd8(u8*);
// Parity of negative components, combined recursively with the linked object.
s32 func_001943e8(u8* p) {
    s32 r = 0;
    f32* v = (f32*)(p + 48);
    for (s32 i = 2; i >= 0; i--) {
        if (*v < 0.0f) r ^= 1;
        v++;
    }
    if (func_001c0cd8(p)) r = (r ^ func_001943e8(*(u8**)(p + 1392))) != 0;
    return r;
}

struct S19b {
    u8 pad[1344];
    Vq a;
    u8 pad2[64];
    Vq b;
    Vq c;
    u8 pad3[80];
    u64 w;
};
void func_00185118(S19b*);
void func_00143928(Vq*);
s32 func_0019bf50(S19b* p, Vq* v) {
    func_00185118(p);
    p->b = p->a;
    p->c = *v;
    p->w &= ~1ULL;
    func_00143928(&p->b);
    return (s32)(p->w >> 32) & 1;
}

void func_001b0330(u32);
void* func_001050d8(u32);
void func_001b6298(void*, u8*, u32, u32);
extern u8 D_0032f054;
void func_001b6c60(u8* p) {
    func_001b0330(*(u32*)(p + 2488));
    D_0032f054 = 0;
    func_001b6298(func_001050d8(32), p, 0, 0);
}

struct Tbl1d5 { u32 f0; u32 n; u8 data[1]; };
extern Tbl1d5* D_01d48d98;
extern u8 D_00320458[];
struct R1b8 { u16 h0; u16 h2; s16 h4; };
R1b8* func_002fd248(u32, u8*, u32, u32, u8*);
u32 func_001a67b0(s32);
void u_call4_001b8e88(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16u_call4_001b8e88jjjj");
void u_call4_001b8e88(u32 a0, u32 a1, u32 a2, u32 a3) {
    NoTail g;
    R1b8* r = func_002fd248(a0, D_01d48d98->data, D_01d48d98->n, 48, D_00320458);
    if (r->h2 != 2) return;
    if (r->h0 == r->h2) return;
    Tbl1d5* t = D_01d48d98;
    func_002fd248(func_001a67b0(r->h4), t->data, t->n, 48, D_00320458);
}

struct E1bc { u8 pad[5]; u8 type; u8 pad2[6]; };
struct S1bc { u8 pad[8]; s32 n; E1bc e[1]; };
static inline bool isLow(E1bc* e) { return e->type < 4; }
s32 func_001bc948(S1bc* s) {
    for (s32 i = 0; i < s->n; i++) {
        if (isLow(&s->e[i])) return 1;
    }
    return 0;
}

// Wraps an angle into [-pi, pi].
f32 func_001cbf50(f32 a) {  // float_bucket_index_c
    if (0.0f < a) {
        if (3.14159274f < a) {
            do a -= 6.28318548f; while (3.14159274f < a);
        }
    } else {
        while (a < -3.14159274f) a += 6.28318548f;
    }
    return a;
}

void func_001c8d98(u8*, u32);
void func_001c9b90(void);
void func_001d2710(u8*);
void func_00319f88(u8*);
void func_0019f9a8(u8*);  // array8_free_slots
void func_001c0248(u8*);
void func_00319fb0(u8*);  // big_obj_dtor
extern u8 D_00352360[];
extern u8 D_0034e8b8[];
extern u8 D_0034ee08[];
extern u8 D_00351eb8[];
extern u8 D_00351ec0[];
// Destructor chain: own vtable, then the two base levels.
void func_001cfeb0(u8* p) {
    NoTail g;
    *(u32*)p = (u32)D_00352360;
    func_001c8d98(D_00351eb8, 0);
    func_001c8d98(D_00351ec0, 4);
    func_001c9b90();
    func_001d2710(p + 2932);
    *(u32*)p = (u32)D_0034e8b8;
    func_00319f88(p + 2824);
    *(u32*)p = (u32)D_0034ee08;
    func_0019f9a8(p + 2568);  // array8_free_slots
    func_001c0248(p + 2640);
    func_00319fb0(p);  // big_obj_dtor
}

void func_001d1678(u8*, s32);  // obj_init_28bytes
void func_001d19e8(u8*, s32);
void func_001d16e8(u8*, u32, u32);
extern u8 D_003525c8[];
extern u8 D_00352750[];
void func_001d4c98(u8* p) {
    *(u32*)(p + 4) = 0;
    *(u32*)p = (u32)D_003525c8;
    *(u32*)(p + 8) = 0;
    *(u32*)(p + 12) = 0;
    func_001d1678(p, -1);  // obj_init_28bytes
    *(u32*)(p + 48) = 0;
    *(u32*)p = (u32)D_00352750;
    u8* e = p + 57;
    for (s32 i = 127; i >= 0; i--) {
        *e = 0;
        e += 4;
    }
    func_001d19e8(p, -1);
    func_001d16e8(p, 0, 12);
}

s32 func_0019c898(u32);
void func_001d5f30(u8*, u32);
void func_001d6088(u32 id, u8* o) {
    switch (*(s32*)(o + 2896)) {
    case 2:
        if (id - 1000 >= 1012) return;
        if (func_0019c898(id)) return;
        break;
    case 5:
        if (id - 3000 >= 1015) return;
        break;
    default:
        return;
    }
    func_001d5f30(o, 1);
}

extern s32 D_00352b50;
s32 func_0019ba60(u8*);
s32 func_001dffd8(u8* p) {
    if (D_00352b50 != 1) return 0;
    s32 r = 0;
    if (!func_0019ba60(*(u8**)(p + 72)) || (*(u32*)(*(u8**)(p + 72) + 352) & 0x20000000) ||
        (*(u32*)(*(u8**)(p + 72) + 268) & 0x400))
        r = 1;
    return r;
}

extern u32 D_01d9e6e4;
void func_001e7798(u32, u32);
// Releases the three handles at +12/+16/+20 of the sub-block.
void func_00207050(u8* p, u8* d) {
    u32* s = (u32*)(p + **(s32**)(d + 12) + 160);
    if (s[3]) { func_001e7798(D_01d9e6e4, s[3]); s[3] = 0; }
    if (s[4]) { func_001e7798(D_01d9e6e4, s[4]); s[4] = 0; }
    if (s[5]) { func_001e7798(D_01d9e6e4, s[5]); s[5] = 0; }
}

extern s32 D_0035dcf0;
extern u8 D_0035db00[];
void func_00225fa0(u8*, u32);
void func_00227930(u8*);
void func_002278e0(u8* p) {
    if (D_0035dcf0 == 0) return;
    func_00225fa0(D_0035db00, *(u32*)(p + 24));
    func_00227930(p);
}

struct E239 { u8 pad[4]; u16 h4; u16 pad2; u32 f8; u8 pad3[24]; };
struct S239 {
    u8 pad[180]; E239* tbl; u8 pad1[4]; u8 bc; u8 pad2[71];
    f32 f104; f32 f108; s32 f10c; u8 pad3[4]; u32 f114; u8 pad4[40]; u32 f140; u32 f144;
};
s32 func_00239af8(S239*, u32);
void ctarget_00239c68(S239* p, u32 a1, u32 a2, u32 a3) asm("_Z16ctarget_00239c68jjjj");
void ctarget_00239c68(S239* p, u32 a1, u32 a2, u32 a3) {
    p->bc = 0;
    E239* e = &p->tbl[a1];
    p->f114 = a1;
    p->f140 = e->h4;
    p->f144 = e->f8;
    f32 v = func_00239af8(p, a1);
    p->f108 = v;
    if (v < p->f104) p->f104 = v;
    p->bc = 0;
    p->f10c = 0;
    p->f108 += 1.0f;
}

s32 func_00287bc0(void);
u8* func_00257770(void);
void func_0028dac8(u8*, u32);
void func_0027e6e0(void);
void cm_FadeOutStock(void* self) asm("_ZN2Tz6CmItem12FadeOutStockEv");
void cm_FadeOutStock(void* self) {
    s32 m = func_00287bc0();
    u8* o = func_00257770();
    if (m == 12) {
        func_0028dac8(o + 408, 301);
        func_0027e6e0();
    }
}

extern u32 D_0035f010;
u8* func_00281180(u32, u32);
u8* func_001a80c8(u16);  // table24_find_by_id
struct Ent267 { u16 id : 15; u16 on : 1; };
// Sums byte 7 of every enabled entry's record over the 80-entry list.
s32 func_00267150(u32 a) {
    u8* o = func_00281180(D_0035f010, a);
    Ent267* p = (Ent267*)(*(u8**)(o + 580) + 84);
    s32 sum = 0;
    for (s32 i = 79; i >= 0; i--) {
        u16 id = p->id;
        if (id && p->on) sum += func_001a80c8(id)[7];
        p++;
    }
    return sum;
}

void func_00139d78(u8*);
s16* func_0028ac98(u8*, u32);  // lookup_by_index_align
s32 func_0028ae98(u8* p, u32 i) {
    u8* o = (*(u8***)(p + 40))[i];
    if (o) func_00139d78(o);
    s16* r = func_0028ac98(p, i);  // lookup_by_index_align
    return *(s32*)((*(u8***)(p + 40))[i] + 388) == r[3];
}

void func_00138840(void);
double func_00313b80(f32);  // float_to_double
s32 func_003142e0(double, double);  // double_compare
extern f32 D_00349e10;
void func_0028d2a0(u8* p) {
    if (*(u32*)(p + 12) & 0x100) return;
    func_00138840();
    if (func_003142e0(0.0, func_00313b80(*(f32*)(p + 416))) > 0) return;
    if (*(f32*)(p + 416) < 30.0f) {
        *(f32*)(p + 416) += D_00349e10;
        if (30.0f < *(f32*)(p + 416)) *(f32*)(p + 416) = 30.0f;
    }
}

struct VObj2b { void (**vt)(VObj2b*); u8 pad[28]; VObj2b* next; };
void func_002be148(u8*);
void func_00170950(u32);
void func_001b86e0(u32);  // alloc_from_pool_magic_c
void func_00170320(s32);
extern u32 D_003617fc;
extern u8 D_003637e0[];
void func_002bda38(u8* p) {
    func_002be148(p);
    VObj2b* o = *(VObj2b**)(p + 16);
    while (o) {
        VObj2b* n = o->next;
        if (o) o->vt[1](o);  // virtual deleting destructor
        o = n;
    }
    if (*(u32*)(p + 104)) func_00170950(*(u32*)(p + 104));
    func_001b86e0(*(u32*)(p + 4));  // alloc_from_pool_magic_c
    func_00170320(-200);
    D_003617fc = 0;
    *(u32*)(p + 8) = (u32)D_003637e0;
}

s32 func_002cf270(u8*, u32);
void func_002cf2b0(u8*, u32);
void func_0016ac38(u8*, u32, u32, u32, u32);
void func_002cf280(u8*, u32, u32);
void func_002d3f18(u8* p) {
    u8* s = p + 2800;
    if (*(s32*)(p + 2924) >= 0) return;
    if (!func_002cf270(s, 256)) return;
    func_002cf2b0(s, 256);
    func_0016ac38(p, 0, 1, 0, 0);
    func_002cf280(s, 4, 0);
}

void func_00198690(u8*);
void func_0016b070(u8*, f32*);
void func_0016ace0(u8*, f32*);
void func_002de8e8(u8* p) {
    f32 a[4];
    f32 b[4];
    func_00198690(p);
    if (!func_001c0cd8(p)) return;
    a[1] = a[0] = -1.57079625f;
    a[3] = a[2] = 0.0f;
    func_0016b070(p, a);
    b[3] = b[2] = b[1] = b[0] = 0.0f;
    func_0016ace0(p, b);
}

extern f32 D_01e2c040;
void func_002eb9d8(u8*, u8*, u32, f32);
void func_002eba78(u8* a, u8* b) {
    *(f32*)(b + 276) = *(f32*)(b + 272) = 16.0f;
    *(f32*)(b + 284) = D_01e2c040;
    func_002eb9d8(a, b, 253, 8.0f);
}

void func_002fde18(void*, s32, u32);
struct UwCtx { u8 pad[708]; void* cfa; u32 ra; u8 pad2[28]; };
struct UwFs { u8 pad[2840]; s64 cfa_offset; u64 cfa_reg; u8 pad2[4]; s32 cfa_how; u8 pad3[32]; };
s32 func_00317d80(UwCtx*, UwFs*);
void func_00317fc8(UwCtx*, UwFs*);
// uw_init_context_1: unwind context for the caller's frame.
void func_003181f8(UwCtx* ctx, void* outer_cfa, u32 outer_ra) {
    UwFs fs;
    u32 ra = (u32)__builtin_return_address(0) & ~1;
    func_002fde18(ctx, 0, sizeof(UwCtx));
    outer_ra &= ~1;
    ctx->ra = ra;
    if (func_00317d80(ctx, &fs)) func_002fd160();
    ctx->cfa = outer_cfa;
    fs.cfa_how = 1;
    fs.cfa_reg = 0;
    fs.cfa_offset = 0;
    func_00317fc8(ctx, &fs);
    ctx->ra = outer_ra;
}

}
