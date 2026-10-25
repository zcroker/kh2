#include "../common/types.h"

// 16-byte vector; assignment copies with a 128-bit lq/sq.
struct Vq81 {
    f32 x, y, z, w;
    Vq81& operator=(const Vq81& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
// Same, but the original keeps the asm out of delay slots.
struct Vn81 {
    f32 x, y, z, w;
    Vn81& operator=(const Vn81& o) {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline Vq81 vsub81(const Vq81& a, const Vq81& b) {
    Vq81 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline Vn81 vsub81n(const Vn81& a, const Vn81& b) {
    Vn81 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
// xyz length
static inline f32 vlen81(const Vq81& a) {
    f32 d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2 $8, $vi22\n\tmtc1 $8, %0"
                 : "=f"(d) : "r"(&a) : "$8", "memory");
    return d;
}
// normalise xyz in place
static inline void vnorm81(Vq81& v) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\t"
                 "vsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, $f0\n\tvnop\n\t"
                 "vdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&v) : "$8", "$f0", "memory");
}
static inline Vq81 vscale81(const Vq81& a, f32 s) {
    Vq81 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}

typedef s32 (*VFn81)(...);
struct VObj81 { VFn81* vt; };
typedef void (*VFnV81)(...);
struct VObjV81 { VFnV81* vt; };
struct VObj0 { void (**vt)(VObj0*); };
// local with an empty destructor: keeps the final call a jal (no sibcall)
struct NoTail81 { ~NoTail81() {} };

// 64-byte matrix; copy-construct / assign with four 128-bit lq/sq (assignment checks self)
struct M81 {
    u8 b[64];
    M81() {}
    M81(const M81& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    M81& operator=(const M81& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
union IF81 { s32 i; f32 f; };

// three 16-bit ids set from an int (keeps the 0xffff constant in a 32-bit register)
struct Ids81 {
    u16 a, b, c;
    void Fill81(s32 v) { a = v; b = v; c = v; }
};
extern "C" {

// --- 001216a8: clear bit 2 of the flag byte of every entry (both tables) whose id matches (-1 = all)
struct Ent216 { u32 lo : 5; u32 : 1; u32 hi : 5; u32 : 21; u8 pad[28]; };
struct Tbl216 { u8 pad[28]; s32 n; Ent216 e[1]; };
struct Own216 { u32 a; Tbl216* t; };
Tbl216* func_00120800(Own216*);  // obj_get_sub_ptr_by12
void func_001216a8(Own216* o, u8* flags, s32 id) {
    Tbl216* t = o->t;
    Tbl216* t2 = func_00120800(o);  // obj_get_sub_ptr_by12
    s32 i;
    for (i = 0; i < t->n; i++) {
        if (id == -1 || t->e[i].hi == id) flags[i] &= ~4;
    }
    if (t2) {
        for (i = 0; i < t2->n; i++) {
            if (id == -1 || t2->e[i].lo == id) flags[t->n + i] &= ~4;
        }
    }
}

// --- 0013d9e0: release the five global objects (virtual slot 4) and clear them
extern VObj0* D_003485f8;
extern VObj0* D_003485f4;
extern VObj0* D_003485f0;
extern VObj0* D_003485ec;
extern VObj0* D_003485e8;
void u_call0_0013d9e0(void) asm("_Z16u_call0_0013d9e0v");
void u_call0_0013d9e0(void) {
    if (D_003485f8) { D_003485f8->vt[4](D_003485f8); D_003485f8 = 0; }
    if (D_003485f4) { D_003485f4->vt[4](D_003485f4); D_003485f4 = 0; }
    if (D_003485f0) { D_003485f0->vt[4](D_003485f0); D_003485f0 = 0; }
    if (D_003485ec) { D_003485ec->vt[4](D_003485ec); D_003485ec = 0; }
    if (D_003485e8) { D_003485e8->vt[4](D_003485e8); D_003485e8 = 0; }
}

// --- 00146390: recursive tree walk (node test, visit items, then up to 8 children)
struct Node146 { s16 child[8]; Vq81 v; u8 pad20[8]; s16 start, end; u8 pad[4]; };
struct Tree146 { u32 a; Node146* nodes; u8* items; };
s32 func_00146088(Tree146*, Vq81*);
void func_00146100(Tree146*, u32, s16);
void func_001461f0(Tree146*, Node146*);
void func_00146390(Tree146* t, s32 idx, u32 arg) {
    Node146* n = &t->nodes[idx];
    if (func_00146088(t, &n->v) == 1) return;
    s32 j;
    s32 end = n->end;
    s32 i;
    for (i = n->start; i < end; i++) {
        if (t->items[i * 28]) func_00146100(t, arg, i);
    }
    func_001461f0(t, n);
    for (j = 0; j < 8; j++) {
        if (n->child[j] == -1) break;
        func_00146390(t, n->child[j], arg);
    }
}

// --- 0015cef0: copy three vectors into the triple-buffered globals
extern Vq81 D_004f3760, D_004f3770, D_004f3780, D_004f3790, D_004f37a0, D_004f37b0, D_004f37c0, D_004f37d0, D_004f37e0;
Vq81* func_00140df0(void);
// 0015cef0: moved to src/anon/unit_0015cdb0.cpp

// --- 00165a10: any eligible entity in range? (stores the offset to it)
struct Ent165 { u32 id; u32 obj; u32 flags; };
struct Me165 { Vn81 pos; Vn81 dir; u8 pad[16]; Vn81 tgt; u8 pad2[60]; u32 id; };
Ent165* func_00165ef0(Ent165*);
s32 func_00142b70(u32);  // len_sq_compare_at80
s32 func_00164718(u32, Me165*);
s32 func_00165a10(Me165* m) {
    Ent165* e = 0;
    s32 found = 0;
    while ((e = func_00165ef0(e)) != 0) {
        if (e->id == m->id) continue;
        u32 f = e->flags & 1;
        if (f) continue;
        if (func_00142b70(e->obj)) continue;
        if (!func_00164718(e->obj, m)) continue;
        found = 1;
        m->dir = vsub81n(m->tgt, m->pos);
    }
    return found;
}

// --- 0016a4e8: deleting destructor
extern u8 D_0034d850[];
void func_001a17c8(u32);
void func_001b78b8(u32);  // to_105110
void func_002cb708(u32);
void func_00105110(u32);
void func_001b3098(u8*);
void func_001a9350(u8*);
void func_001a6d68(u8*);
void func_00187b90(u8*);
void func_0017eb98(u8*);
void func_001ddd88(u8*);
void func_0016a4e8(u8* o) {
    *(u8**)o = D_0034d850;
    if (*(u32*)(o + 1164)) func_001a17c8(*(u32*)(o + 1164));
    if (*(u32*)(o + 2088)) func_001b78b8(*(u32*)(o + 2088));  // to_105110
    if (*(u32*)(o + 1296)) func_001b78b8(*(u32*)(o + 1296));  // to_105110
    u32 p = *(u32*)(o + 1288);
    if (p) { func_002cb708(p); func_00105110(p); }
    func_001b3098(o + 2048);
    func_001a9350(o + 1952);
    func_001a6d68(o + 1280);
    func_00187b90(o + 768);
    func_0017eb98(o + 320);
    func_001ddd88(o + 156);
    func_001ddd88(o + 128);
    func_00105110((u32)o);
}

// --- 001755a4: hand-written assembly in the original (frameless lq/sq memmove
// in 128-byte blocks, forward or backward depending on overlap).
void func_001755a4(void* d, const void* s, s32 n) {
    asm volatile(
        ".set noreorder\n\t"
        "sub $2, $4, $5\n\t"
        "beqz $2, 2f\n\t"
        "nop\n\t"
        "bgtz $2, 3f\n\t"
        "nop\n"
        "1:\n\t"
        "lq $8, 0($5)\n\tlq $9, 16($5)\n\tlq $10, 32($5)\n\tlq $11, 48($5)\n\t"
        "lq $12, 64($5)\n\tlq $13, 80($5)\n\tlq $14, 96($5)\n\tlq $15, 112($5)\n\t"
        "sq $8, 0($4)\n\tsq $9, 16($4)\n\tsq $10, 32($4)\n\tsq $11, 48($4)\n\t"
        "sq $12, 64($4)\n\tsq $13, 80($4)\n\tsq $14, 96($4)\n\tsq $15, 112($4)\n\t"
        "addiu $6, $6, -128\n\t"
        "addiu $4, $4, 128\n\t"
        "bgtz $6, 1b\n\t"
        "addiu $5, $5, 128\n"
        "2:\n\t"
        "jr $31\n\t"
        "nop\n"
        "3:\n\t"
        "addu $4, $4, $6\n\t"
        "addu $5, $5, $6\n"
        "4:\n\t"
        "lq $8, -16($5)\n\tlq $9, -32($5)\n\tlq $10, -48($5)\n\tlq $11, -64($5)\n\t"
        "lq $12, -80($5)\n\tlq $13, -96($5)\n\tlq $14, -112($5)\n\tlq $15, -128($5)\n\t"
        "sq $8, -16($4)\n\tsq $9, -32($4)\n\tsq $10, -48($4)\n\tsq $11, -64($4)\n\t"
        "sq $12, -80($4)\n\tsq $13, -96($4)\n\tsq $14, -112($4)\n\tsq $15, -128($4)\n\t"
        "addiu $6, $6, -128\n\t"
        "addiu $4, $4, -128\n\t"
        "bgtz $6, 4b\n\t"
        "addiu $5, $5, -128\n\t"
        ".set reorder"
        : : : "$2", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
}

// --- 0017a2d0: push along the flattened, reversed direction of the target
extern u32 D_0034ece4;
void func_00143e50(Vq81*, u16, u32);
s32 func_0019c778(u8*, Vq81*);
u32 func_00192048(u32);
void func_0015b268(u32, f32);
void func_0017a2d0(u8* o) {
    u32 id = *(u16*)(o + 1524);
    if (id == 0xffff) return;
    if (!D_0034ece4) return;
    Vq81 v;
    func_00143e50(&v, id, 0);
    v.y = 0;
    vnorm81(v);
    Vq81 d = vscale81(v, -1.0f);
    if (func_0019c778(o, &d)) func_0015b268(func_00192048(D_0034ece4), 60.0f);
}

// --- 00187650
void func_00187728(u8*, f32);
s32 func_001a1990(u8*, s32);
s32 ctarget_00187650(u8* o, s32 n, u32 flag, u32) asm("_Z16ctarget_00187650jjjj");
s32 ctarget_00187650(u8* o, s32 n, u32 flag, u32) {
    u8* t = *(u8**)(o + 1164);
    s32 r = 0;
    flag &= 0xff;
    if (t == 0 || (*(u32*)(o + 2040) & 4)) return 0;
    if ((*(u32*)(o + 1416) & 0x4000) && n > 0 && flag && !(*(u32*)(o + 352) & 0x4000)) {
        ((VObjV81*)o)->vt[21](o, 20, 0);
        t = *(u8**)(o + 1164);
    }
    if (*(s32*)(t + 384) + n < 0) {
        func_00187728(o, 1.0f);
    } else {
        r = func_001a1990(t, n);
    }
    return r;
}

// --- 0018ed18
struct Ent18e { u8* obj; u8 pad[12]; u8 x[32]; };
struct List18e { s32 n; u8 pad[12]; Ent18e e[1]; };
u8* func_00186078(u8*);
s32 func_0019bb58(u8*);
s32 func_0018d940(u8*, u8*);
s32 func_0018f010(u8*);  // byte4_is_2_or_3
u32 func_001b7998(u32, u8*);
void func_0018e298(Ent18e*, u8*, u32);
void func_0018ed18(List18e* l) {
    u8* e = 0;
    while ((e = func_00186078(e)) != 0) {
        if (!func_0019bb58(e)) continue;
        s32 i;
        for (i = 0; i < l->n; i++) {
            Ent18e* t = &l->e[i];
            if (!func_0018d940(t->obj, e)) continue;
            if (*(u32*)(t->obj + 4) & 0x40) continue;
            if (func_0018f010(t->obj)) continue;
            u32 v = func_001b7998(*(u32*)(e + 1296), t->x);
            if (v) { func_0018e298(t, e, v); break; }
        }
    }
}


// --- 00229728: refresh the per-slot ids when the current id changes
void func_00150260(u8*, u32, s32, u32*);
void func_00138c10(u8*, u32);
void func_001395a8(u8*);
void func_00229728(u8* o) {
    u32 buf[6];
    s32 i;
    s32 j;
    u32 cur = **(u32**)(o + 2880);
    if (*(u32*)(o + 2884) != cur) {
        func_00150260(*(u8**)(o + 2892), cur, 6, buf);
        for (i = *(s32*)(o + 2888) - 1; i >= 0; i--) {
            u8* e = o + 432 + i * 408;
            func_00138c10(e, buf[i]);
            func_001395a8(e);
        }
        for (j = *(s32*)(o + 2888) - 1; j > 0; j--) {
            u8* t = *(u8**)(o + 2892);
            if (buf[j] != *(u32*)t) break;
            func_00138c10(o + 432 + j * 408, *(u32*)(t + 40));
        }
    }
    *(u32*)(o + 2884) = cur;
}

// --- 00248828
extern VObjV81* D_0035ed54;
extern VObjV81* D_0035ed5c;
extern VObjV81* D_0035ed58;
extern u32 D_0035ed4c;
extern u32 D_0035ed50;
s32 func_00139d78(u32);
s32 func_0028acc8(u32);
void func_0028abe0(u32);
void func_00249358(void);
void func_0028ce38(void);
void func_00248828(void) {
    if (func_00139d78((u32)D_0035ed54)) D_0035ed54->vt[5](D_0035ed54);
    if (func_00139d78((u32)D_0035ed5c)) D_0035ed5c->vt[5](D_0035ed5c);
    if (func_00139d78((u32)D_0035ed58)) D_0035ed58->vt[5](D_0035ed58);
    if (func_0028acc8(D_0035ed4c)) func_0028abe0(D_0035ed4c);
    if (func_0028acc8(D_0035ed50)) func_0028abe0(D_0035ed50);
    func_00249358();
    func_0028ce38();
}

// --- 00252c20
extern u32 D_0035eea4;
extern u8* D_0035ee90[];
s32 func_00287bc0(void);
s32 func_0023f100(u32);
s32 func_0023f0c0(u32);
void func_00252ce0(void);
void func_00252d88(void);
void func_00252e50(void);
u8* func_00167f18(u32);
void func_00242618(u32, u32);
void func_0023f108(u32);
void func_00252c20(void) {
    s32 n = func_00287bc0();
    s16 id = *(s16*)(D_0035ee90[n - 1] + 4);
    if (func_0023f100(D_0035eea4) == -1) {
        func_00252ce0();
        func_00252d88();
        func_00252e50();
    }
    if (func_0023f0c0(D_0035eea4) != id) return;
    if (!(*(u64*)(func_00167f18(0) + 8) & 4)) return;
    func_00242618(2, 1);
    func_0023f108(D_0035eea4);
}

// --- 00257458
extern u32 D_0035f034;
extern u32 D_0035ef68;
extern u32 D_0035ef64;
extern u32 D_0035f03c;
struct P257 { s16 x, y, z, w; };
extern P257 D_00372a00;
extern P257 D_00372a08;
void func_0028d980(u32, u32, u32, u32, u32, s32, s32, s32, u32);
void func_00139620(u32);
void func_00257458(u32 a, s32 b) {
    if (func_00139d78(D_0035f034)) (*(VObjV81*)D_0035f034).vt[5](D_0035f034);
    P257* p;
    if (b == 0) p = &D_00372a00; else p = &D_00372a08;
    func_0028d980(D_0035f034, 30022, D_0035ef68, D_0035ef64, D_0035f03c, p->x, p->z, -1, 0);
    *(u32*)(D_0035f034 + 408) = a;
    func_00139620(D_0035f034);
    *(u32*)(D_0035f034 + 432) = 2;
    u8* q = (u8*)D_0035f034 + 24;
    *(u32*)(q + 184) |= 8;
}

// --- 002584c8: create the global object (inlined constructors) and set it up
extern u8 D_00347f98[];
extern u8 D_0035eb98[];
extern u8* D_0035f078;
extern u32 D_0035f074;
extern u32 D_0035f080;
extern u32 D_0035f084;
u8* func_0023ee30(u32);
void func_0031a838(u8*);
void func_002369a0(u8*);  // obj_ctor_36eac8
void func_0023c008(u8*);  // obj_ctor_36eae8
u32 func_0023f948(u32, u32);
u32 func_0023f908(u32, u32);
void func_0023eea0(u8*, u32, u32, u32, u32, u32);
void func_0023f0c8(u8*, s32);
void func_0023ef50(u8*);
void func_0026dd18(u32, u32, s32);  // store_session_globals
void func_002584c8(void) {
    u8* p = func_0023ee30(160);
    *(u32*)p = (u32)D_00347f98;
    func_0031a838(p + 12);
    *(u32*)p = (u32)D_0035eb98;
    func_002369a0(p + 24);  // obj_ctor_36eac8
    func_0023c008(p + 48);  // obj_ctor_36eae8
    D_0035f078 = p;
    u32 a = func_0023f948(D_0035f074, 0);
    func_0023eea0(D_0035f078, 30000, a, func_0023f908(D_0035f074, 0), 0, 0);
    func_0023f0c8(D_0035f078, -1);
    func_0023ef50(D_0035f078);
    func_0026dd18(D_0035f080, D_0035f084, -1);  // store_session_globals
}

// --- 0025af70
extern u8 D_00372ea0[];
s32 func_00287cd0(void);
s32 func_002b4fb8(void);
s32 func_00287c10(void);
void func_00233e70(u32);
s32 func_00233e60(void);
void func_00287c30(void);
void func_00287d20(u32);
void func_002b5188(u8*, u32);
void func_00287cc0(u32);
void func_00240bb0(u32);  // global_store_half2
void func_002417a0(void);
void func_002b4ee0(void);
void func_00287c00(u32);
void func_0025af70(void) {
    s32 m = func_00287cd0();
    if (m == 2) {
        if (func_002b4fb8()) return;
        if (func_00287c10() == 1) {
            func_00233e70(0);
            if (!func_00233e60()) return;
        }
        func_00287c30();
        func_00287d20(0);
        if (func_00287bc0() == 12) func_002b5188(D_00372ea0, 0);
        return;
    }
    if (m == 0) func_00287cc0(1);
    func_00240bb0(8000);  // global_store_half2
    func_002417a0();
    func_002b4ee0();
    func_00287c00(12);
    func_00287cc0(2);
}

// --- 0026c048
extern u32 D_0035f010;
extern u32 D_0035f01c;
extern u32 D_0035f024;
extern u8* D_0035f0f4;
s32 func_00281180(u32, s32);
u32 func_002891b8(u32, s32);
void func_00288ce0(u32, u32, s32, u8*, u8*);
void func_0028af90(u32, s32);  // obj_set_field22_from_arg
void func_0028b1e8(u32, u32);
void func_00257708(u32);
void func_0026c048(void) {
    s32 i;
    s32 n = 0;
    for (i = 0; i < 4; i++) {
        if (func_00281180(D_0035f010, i)) {
            u32 v = func_002891b8(D_0035f01c, n);
            func_00288ce0(D_0035f024, v, n, D_0035f0f4 + n * 8 + 3784, D_0035f0f4 + n * 8 + 3784);
            n++;
        }
    }
    func_0028af90(D_0035f024, n);  // obj_set_field22_from_arg
    func_0028b1e8(D_0035f024, 1);
    if (n < 3) func_00257708(1);
}

// --- 0027c3e0
extern u8* D_0035f230;
u32 func_0028b040(u32);
u32 func_002570a0(u32);
void func_0027aed8(u32, s32*, s32*);
s32 func_0027bf20(u32);
s32 func_0027c3e0(s32 id) {
    s32 m = func_00287bc0();
    u32 h = func_0028b040(D_0035f01c);
    if (m == 15) return 1;
    if (m != 16) return 1;
    s32 b;
    s32 a;
    func_0027aed8(func_002570a0(15), &a, &b);
    if (id == -7) return 1;
    if (id == -6) return func_0027bf20(h);
    if ((u32)(id + 11) < 2) {
        s32 r = 0;
        if (*(s8*)(D_0035f230 + 6) >= 2) r = 1;
        return r;
    }
    if (id == -5) return 1;
    if (*(s8*)(D_0035f230 + id * 8 + 17) != 0 && a == 0) return func_0027bf20(h);
    return 0;
}

// --- 0028ab20: release every entry's id (-1) and clear the current selection
u8* func_0028ac98(u8*, s32);  // lookup_by_index_align
union Cnt81 { u16 v; u8 c; };
void SelectLeave81(u8* o) asm("_ZN2Tz6Select5LeaveEz");
void SelectLeave81(u8* o) {
    func_0028acc8((u32)o);
    s32 i;
    for (i = 0; i < (s16)((Cnt81*)(o + 4))->v; i++) {
        if ((*(u8***)(o + 40))[i] == 0) continue;
        u8* v = func_0028ac98(o, i);  // lookup_by_index_align
        if (!v) continue;
        func_00138c10((*(u8***)(o + 40))[i], *(s16*)(v + 4));
        *(s32*)((*(u8***)(o + 40))[i] + 392) = -1;
    }
    *(s16*)(o + 14) = 0;
}

// --- 0028b3c0
u8* func_0023f1b0(u32);
u32 func_0023c3e0(u8*, s16, u32);
void func_001396b0(u8*);
void func_0031ac78(u8*, u32);
void func_00138840(u8*);
void func_0028b3c0(u8* o) {
    if (!func_00139d78(*(u32*)(o + 408))) {
        ((VObjV81*)o)->vt[5](o);
        return;
    }
    s32 cur = *(s32*)(func_0023f1b0(*(u32*)(o + 408)) + 76);
    if (cur != *(s16*)(o + 428)) {
        s32 k = 0;
        u8* q = o;
        for (; k < 3; k++, q += 2) {
            if (cur == *(s16*)(q + 416)) {
                *(u32*)(o + 400) = func_0023c3e0(func_0023f1b0(*(u32*)(o + 408)), *(s16*)(q + 422), 0);
                func_001396b0(o);
                if (*(u32*)(o + 400)) {
                    *(u32*)(o + 396) = 0;
                    func_001396b0(o);
                    if (*(u32*)(o + 396)) func_0031ac78(o, 0);
                }
                break;
            }
        }
    }
    *(s16*)(o + 428) = cur;
    func_00138840(o);
}

// --- 0028fb88: allocate the two sub-objects through the global allocator
typedef u8* (*VFnP81)(...);
struct VObjP81 { VFnP81* vt; };
extern u8* D_00347f80;
extern u8 D_00347e60[];
void func_00239700(u8*);
void func_0028dfe8(u8*);  // obj_ctor_36f440
void func_00258d40(u32, u32);
void func_0028fb88(u8** o, u32 a, u32 b, u16* c) {
    VObjP81* al = *(VObjP81**)(D_00347f80 + 20);
    u8* p = al->vt[0](al, 408, 0);
    *(u32*)(p + 12) = 0;
    *(u32*)p = (u32)D_00347e60;
    func_00239700(p + 24);
    o[0] = p;
    al = *(VObjP81**)(D_00347f80 + 20);
    u8* q = al->vt[0](al, 60, 0);
    func_0028dfe8(q);  // obj_ctor_36f440
    o[1] = q;
    s32 i;
    for (i = 0; i < 3; i++) ((u16*)(o + 2))[i] = c[i];
    o[4] = (u8*)a;
    func_00258d40(a, b);
}

// --- 002adcb0: 1 unless an entry of type 22 (matching id, if id >= 0) has its flag bit clear
extern u8* D_0035f620;
u8* func_001a82b0(u8*);
u8* func_001a80c8(u16);  // table24_find_by_id
s32 func_002764b0(u8);
s32 func_002adcb0(s32 id) {
    u8* e = 0;
    u32 i = 0;
    s32 r = 1;
    for (;;) {
        e = func_001a82b0(e);
        if (!e) break;
        if (func_001a80c8(*(u16*)(e + 2))[2] != 22) continue;
        if (id >= 0 && func_002764b0(e[5]) != id) { i++; continue; }
        u32* f = (u32*)(D_0035f620 + 300);
        if (!(f[i >> 5] & (1 << (i & 31)))) { r = 0; break; }
        i++;
    }
    return r;
}

// --- 0018d420: destructor body: drop references, unlink from the global list
struct Node18d { u32 vt; u32 flags; u8* a; u32 p; u8* b; u8 pad[8]; u32 h; u8 pad2[16]; u8 sub[144]; Node18d* next; };
struct List18d { Node18d* head; Node18d* tail; };
extern List18d D_01c60cd8;
extern u8 D_0034ef18[];
void func_0018e040(Node18d*);
void func_001c0058(u32);  // clear_bit_in_array
void func_001c0248(u8*);
void func_0018d420(Node18d* o) {
    NoTail81 nt;
    o->vt = (u32)D_0034ef18;
    if (o->a) (*(s32*)(o->a + 1160))--;
    if (o->b) (*(s32*)(o->b + 1160))--;
    Node18d* prev;
    if (o == D_01c60cd8.head) {
        prev = 0;
        D_01c60cd8.head = o->next;
    } else {
        Node18d* c = D_01c60cd8.head->next;
        prev = D_01c60cd8.head;
        if (c != o) {
            Node18d* n;
            do { n = c->next; prev = c; c = n; } while (n != o);
        }
        prev->next = o->next;
    }
    if (o == D_01c60cd8.tail) D_01c60cd8.tail = prev;
    o->next = 0;
    if (!(o->flags & 0x400)) {
        func_0018e040(o);
        func_001c0058(o->h);  // clear_bit_in_array
    }
    func_001c0248(o->sub);
}

// --- 001cc160: spawn up to n prizes at the object's position
extern u32 D_00352050;
void func_001cc358(void);
Vn81 func_0016bda8(u8*);
u8* func_001cc128(u32, Vn81*);
void PrizeAppear81(u8* obj, s32 n) asm("_ZN2YS8PRIZE_CA6AppearEPNS_6BTLOBJEi");
void PrizeAppear81(u8* obj, s32 n) {
    if (*(s32*)(obj + 2760) < n) n = *(s32*)(obj + 2760);
    if (!D_00352050) return;
    if (n == 0) return;
    Vn81 pos;
    pos = func_0016bda8(obj);
    s32 i;
    for (i = 0; i < n; i++) {
        u8* p = func_001cc128(D_00352050, &pos);
        if (!p) return;
        *(u32*)(p + 16) = (u32)func_001cc358;
        (*(s32*)(obj + 2760))--;
    }
}

// --- 00200da8: rotation (radians -> 16-bit angle units) and translation into the node
struct Tbl200 { u8 pad[12]; s32* offs; };
struct V3_81 { f32 x, y, z; };
extern V3_81 D_00354bd0;
extern V3_81 D_00354bc0;
void func_0021eb50(u8*, s32*);
void func_00200da8(u8* o, Tbl200* t) {
    s32 v[3];
    u8* p = o + t->offs[3] + 160;
    v[0] = (s32)(D_00354bd0.x * 32768.0f / 3.1415927f);
    v[1] = (s32)(D_00354bd0.y * 32768.0f / 3.1415927f);
    v[2] = (s32)(D_00354bd0.z * 32768.0f / 3.1415927f);
    func_0021eb50(p, v);
    *(f32*)(p + 48) = D_00354bc0.x;
    *(f32*)(p + 52) = D_00354bc0.y;
    *(f32*)(p + 56) = D_00354bc0.z;
}

// --- 002be190
u8* func_00168b38(u32, s32, u32);  // entry_array_find_nth
void func_002eedc0(u32, u32, f32);
void func_002eedd8(u32, u32, f32);  // to_2eefc8_sub456
void func_002be190(u8* o, s32 idx, u32* list, s32 n) {
    u32 t = ((u32*)(o + 44))[idx];
    func_002eedc0(t, *(u32*)(func_00168b38(*(u32*)(o + 104), -1, list[0]) + 8), 0.0f);
    s32 i;
    for (i = 1; i < n; i++) {
        func_002eedd8(t, *(u32*)(func_00168b38(*(u32*)(o + 104), -1, list[i]) + 8), 0.0f);  // to_2eefc8_sub456
    }
}

// --- 002d0c28
void func_001dc818(u32);
void func_002cf280(u8*, u32, u32);
s32 func_002cf270(u8*, u32);
void func_002cf2b0(u8*, u32);
void func_002d0cf0(u8*);
void func_002d0c28(u8* o) {
    if (*(s32*)(o + 2832) == 0) {
        if (*(u32*)(o + 2828)) {
            func_001dc818(*(u32*)(o + 2828));
            *(u32*)(o + 2828) = 0;
        }
        *(u32*)(o + 264) |= 3;
        func_002cf280(o + 2800, 8192, 0);
    }
    (*(s32*)(o + 2832))++;
    if (func_002cf270(o + 2800, 16384) && *(s32*)(o + 2832) < 5) return;
    func_002cf2b0(o + 2800, 8192);
    func_002cf2b0(o + 2800, 16384);
    func_002d0cf0(o);
}

// --- 002d1f88: push the inverse of the node's (orthonormal) matrix
u8* func_00106a60(u32);  // buffer_get_by_index
void func_002d1f88(u8* o) {
    M81 m = *(M81*)(*(u8**)(o + 4) + 160);
    // transpose the 3x3 part, translation = -(R^T * t)
    asm volatile(
        "lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
        "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
        "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
        "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
        "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\t"
        "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)"
        : : "r"(&m) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    *(M81*)(func_00106a60(1) + 16) = m;
}

// --- 002e2570: copy the matrix, then fade value 260 up/down towards its limit
extern f32 D_00349e10;
s32 func_00197920(u8*);
void wtarget_002e2570(u8* o, u32, u32, u32) asm("_Z16wtarget_002e2570jjjj");
void wtarget_002e2570(u8* o, u32, u32, u32) {
    if (func_00197920(o)) return;
    *(M81*)(o + 112) = *(M81*)(o + 176);
    s32 st = *(s32*)(o + 272);
    if (st == 1) {
        *(f32*)(o + 260) = *(f32*)(o + 260) + D_00349e10 * 0.5f;
        f32 lim = (f32)((IF81*)*(u8**)(o + 100))[1].i;
        if (lim <= *(f32*)(o + 260)) { *(f32*)(o + 260) = lim; *(s32*)(o + 272) = 0; }
    } else if (st == 2) {
        *(f32*)(o + 260) = *(f32*)(o + 260) - D_00349e10 * 0.5f;
        f32 lim = (f32)((IF81*)*(u8**)(o + 100))[0].i;
        if (*(f32*)(o + 260) <= lim) { *(f32*)(o + 260) = lim; *(s32*)(o + 272) = 0; }
    }
}

// --- 002f1670: progress value for the current fade state
void func_002f1480(u8*, f32);
void func_002f1670(u8* o) {
    NoTail81 nt;
    f32 r = 0.0f;
    switch (*(s32*)(o + 12)) {
    case 0:
        r = 1.0f;
        break;
    case 1:
        r = *(f32*)(o + 20) / *(f32*)(o + 16);
        if (0.5f < r) r = (1.0f - r) + (1.0f - r);
        else r = r + r;
        break;
    case 2:
        r = *(f32*)(o + 20) / *(f32*)(o + 16);
        break;
    case 3:
        r = 1.0f - *(f32*)(o + 20) / *(f32*)(o + 16);
        break;
    }
    func_002f1480(o, r);
}

// --- 0031a1a0: assignment operator (base fields, member at 24 via its operator=, tail fields)
struct Pr31a { u32 x, y; };
struct Obj31a {
    u32 vt;
    u32 a, b, c;
    Pr31a d;
    u8 sub[344];
    u32 f, g, h, i;
    f32 j;
    u32 k, l, m, n;
    u8 p, q;
};
void func_0031a850(u8*, u8*);
Obj31a* func_0031a1a0(Obj31a* d, Obj31a* s) {
    *(u32*)((u8*)d + 4) = *(u32*)((u8*)s + 4);
    *(u32*)((u8*)d + 8) = *(u32*)((u8*)s + 8);
    *(u32*)((u8*)d + 12) = *(u32*)((u8*)s + 12);
    d->d.x = s->d.x;
    d->d.y = s->d.y;
    func_0031a850(d->sub, s->sub);
    d->f = s->f;
    d->g = s->g;
    d->h = s->h;
    d->i = s->i;
    d->j = s->j;
    d->k = s->k;
    d->l = s->l;
    d->m = s->m;
    d->n = s->n;
    d->p = s->p;
    d->q = s->q;
    return d;
}

// --- 001cd2b8: restore the saved block and reset the id state
struct Blk1cd { u64 d[8696]; } __attribute__((aligned(16)));
extern Blk1cd D_0032bb30;
extern Blk1cd D_01d499b0;
struct S1cd { u8 a, b, c, pad; Ids81 q; u8 pad2[2]; u8 s1[2088]; u8 s2[16]; };
extern S1cd D_01d5a970;
void func_00195558(u8*);
void func_001cd2b8(void) {
    D_01d499b0 = D_0032bb30;
    S1cd* s = &D_01d5a970;
    u8* src = (u8*)&D_0032bb30;
    s->q.Fill81(0xffff);
    s->a = src[12];
    s->b = src[13];
    s->c = src[14];
    func_00195558(s->s1);
    func_00195558(s->s2);
}

}
