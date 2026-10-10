#include "../common/types.h"

// ---- 1007c0 ----
extern "C" {
u32 func_0030edb0(void);
void func_0030ee00(void);  // ee_intr_get_enable
void func_002fd160(void) __attribute__((noreturn));
void func_002fd408(void*);

struct Obj100 {
    void* pc_begin;
    void* tbase;
    void* dbase;
    union { void* single; void** array; struct { void* pad; void* single; }* sort; } u;
    union { struct { unsigned long sorted : 1; unsigned long rest : 63; } b; unsigned long i; } s;
    Obj100* next;
};
extern u32 D_0037aa2c;
extern Obj100* D_0037aa30;
extern Obj100* D_0037aa34;

void* f_001007c0(void* begin) asm("_Z13func_001007c0Pv");
// libgcc __deregister_frame_info_bases: unlinks the object registered for this .eh_frame
void* f_001007c0(void* begin) {
    Obj100** p;
    Obj100* ob = 0;
    if (*(u32*)begin == 0)
        return ob;
    D_0037aa2c = func_0030edb0();
    for (p = &D_0037aa30; *p; p = &(*p)->next)
        if ((*p)->u.single == begin) {
            ob = *p;
            *p = ob->next;
            goto out;
        }
    for (p = &D_0037aa34; *p; p = &(*p)->next)
        if ((int)(*p)->s.b.sorted) {
            if ((*p)->u.sort->pad == begin) {
                ob = *p;
                *p = ob->next;
                func_002fd408(ob->u.sort);
                goto out;
            }
        } else {
            if ((*p)->u.single == begin) {
                ob = *p;
                *p = ob->next;
                goto out;
            }
        }
    if (D_0037aa2c) func_0030ee00();  // ee_intr_get_enable
    func_002fd160();
out:
    if (D_0037aa2c) func_0030ee00();  // ee_intr_get_enable
    return ob;
}
}

// ---- 105748 ----
extern "C" {
void func_002fd310(void*, u32);
void func_00319bd0(void*);  // clear_18x64_entries
void func_00188e08(void*);
void func_00319870(void*);  // init_18x4_entries
void func_00319930(void*);
void func_003199d0(void*);
void func_00319a60(void*);  // clear_fixed_blocks
void func_002e7768(void*);
void func_001e0868(void*);
u32 func_00105870(void);
void func_00188fc0(void*);
void func_002be760(void*);
void func_001e0998(void*);
void func_0014cb58(void);
void func_00105860(void*, s32);
void func_00196198(void);
void func_0023d3d0(void);

struct Q { u32 w[4]; u8 b; };
void func_00105748(u8* p) {
    u8* a = p + 9456;
    func_002fd310(p, 0x10fc0);
    u8* d = p + 16796;
    u8* b = p + 16364;
    func_00319bd0(p + 12);  // clear_18x64_entries
    func_00188e08(a);
    func_00319870(b);  // init_18x4_entries
    func_00319930(p + 16808);
    *(u32*)(p + 18904) = 0;
    *(u32*)(p + 18908) = 0;
    Q* q = (Q*)(p + 18912);
    u32* w = q->w;
    for (s32 i = 3; i >= 0; i--) *w++ = 0;
    q->b = 0;
    func_003199d0(d + 2136);
    func_00319a60(d + 2716);  // clear_fixed_blocks
    func_002e7768(p + 21920);
    u8* c = p + 0x100e0;
    func_001e0868(c);
    *(u32*)(p + 0) = func_00105870();
    *(u32*)(p + 4) = 58;
    func_00188fc0(a);
    func_002be760(b);
    func_001e0998(c);
    func_0014cb58();
    func_00105860(p, 1);
    func_00196198();
    func_0023d3d0();
}
}

// ---- 136020 ----
extern "C" {
struct Ent { void* obj; u32 id; };
struct List { u32 pad[3]; s32 count; Ent e[32]; };
s32 func_001dca20(void*);  // get_bit20_of_field8
u32 func_001dc5f0(void*);

// drops dead/stale entries from a 32-slot handle list
void func_00136020(List* l) {
    Ent tmp[32];
    s32 n = 0;
    s32 i;
    for (i = 0; i < l->count; i++) {
        void* o = l->e[i].obj;
        u32 id = l->e[i].id;
        if (o && !func_001dca20(o) && func_001dc5f0(o) == id) {  // get_bit20_of_field8
            tmp[n] = l->e[i];
            n++;
        }
    }
    for (i = 0; i < n; i++) l->e[i] = tmp[i];
    for (; i < 32; i++) {
        l->e[i].obj = 0;
        l->e[i].id = 0;
    }
    l->count = n;
}
}

// ---- 140618 ----
extern "C" {
struct V140 {
    f32 x, y, z, w;
    V140& operator=(const V140& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct In140 { u64 f0; u64 f8; u8 pad[20]; f32 f36; u32 pad2; f32 f44; };
s32 func_0019c498(u32);
s32 func_0019c4d0(u32);
void func_00141010(f32);
f32 func_0013fd10(u8*);
void func_0013f828(u8*);
void func_0013f888(u8*, u8*, s32);
void func_0013fd88(u8*);
V140 func_0016c508(u32);
void func_00140500(u8*);
extern f32 D_004573ec;
extern f32 D_00349e10;

void func_00140618(u8* p, In140* in) {
    if (!func_0019c498(*(u32*)(p + 68)) || (in->f8 & 0x400000)) {
        func_00141010(30.0f);
        *(f32*)(p + 76) = *(f32*)(p + 80) = func_0013fd10(p);
        func_0013f828(p);
        func_0013f888(p, p + 128, 0);
        return;
    }
    if (in->f8 & 0x20000) func_0013fd88(p);
    f32 k = D_00349e10;
    *(V140*)(p + 96) = func_0016c508(*(u32*)(p + 68));
    f32 x = func_0013fd10(p);
    *(f32*)(p + 80) = x;
    *(f32*)(p + 76) = x;
    *(f32*)(p + 192) = x + 3.1415925f;
    if (!func_0019c4d0(*(u32*)(p + 68)) && (in->f0 & 0xc0000)) {
        *(f32*)(p + 196) -= in->f36 * in->f44 * D_004573ec * k;
    }
    func_00140500(p);
}
}

// ---- 146ab0 ----
struct V146 {
    f32 x, y, z, w;
    V146& operator=(const V146& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern "C" {
V146 func_00163650(const V146*, const V146*, const V146*);
void f_00146ab0(V146* pl, const V146* eye, const V146* c) asm("_Z13func_00146ab0Pv");

// builds 5 planes: one from the far corners, four from the eye and corner pairs
void f_00146ab0(V146* pl, const V146* eye, const V146* c) {
    pl[0] = func_00163650(&c[0], &c[1], &c[2]);
    pl[1] = func_00163650(eye, &c[2], &c[3]);
    pl[2] = func_00163650(eye, &c[0], &c[1]);
    pl[3] = func_00163650(eye, &c[3], &c[0]);
    pl[4] = func_00163650(eye, &c[1], &c[2]);
}
}

// ---- 14d530 ----
struct S14d {
    u32 a, one, c, d, e, f;
    S14d() { a = 0; c = 0; one = 1; f = 0; d = 0; e = 0; }
};
struct B14d {
    u32 f0, f4, f8, f12, f16;
    u32 f20;
    u32 f24, f28, f32, f36, f40, f44, f48;
    S14d s;
    u32 pad[3];
};
extern u8 D_0037a800;
extern S14d D_00349e28;
extern B14d D_00349e48[2];
inline void* operator new(unsigned int, void* p) { return p; }
extern "C" {
void wt_0014d530(u32 init, u32 prio, u32, u32) asm("_Z16wtarget_0014d530jjjj");
// static init/teardown for a config record and a 2-entry table
void wt_0014d530(u32 init, u32 prio, u32, u32) ;
void wt_0014d530(u32 init, u32 prio, u32, u32) {
    if (prio == 0xffff && init == 1) new (&D_00349e28) S14d;
    if (prio == 0xffff && init == 1) {
        B14d* p = D_00349e48;
        for (s32 i = 1; i != -1; i--) {
            p->f8 = 0; p->f12 = 0; p->f16 = 0; p->f24 = 0; p->f20 = (u32)&D_0037a800; p->f4 = 0; p->f28 = 0; p->f32 = 0; p->f36 = 0; p->f40 = 0; p->f44 = 0; p->f48 = 0;
            new (&p->s) S14d;
            p++;
        }
    }
    if (prio == 0xffff && init == 0) {
        B14d* p = D_00349e48;
        if (p) {
            B14d* base = p;
            p += 2;
        loop:
            if (p == base) goto out;
            p--;
            goto loop;
        out:;
        }
    }
}
}

// ---- 1571c0 ----
extern "C" {
struct Q157 { u8 pad[396]; void* f396; s32 f400; u32 pad2; };
struct R157 { u32 f0; void* f4; };
R157* func_00102c18(s32, u32, void (*)(void*));
void func_00157160(void*);
s32 func_00156030(u8*);
u32 func_00158290(u8*);
u32 func_0013a7e8(s32);
u32 func_0013d7e0(void);
s32 func_00139c18(u8*);
void func_001386e0(Q157*, s32, u32, u32, s32, u32);
void func_001396b0(Q157*);
void func_0031a260(Q157*, s32);
u32 func_00155f40(u8*);
u32 func_00155fc0(u8*);
void func_00138c10(void*, s32);

void func_001571c0(u8* p) {
    func_00102c18(1, 0x19258, func_00157160)->f4 = p;
    if (func_00156030(p)) return;
    u32 c = func_00158290(p);
    u32 a = func_0013a7e8(1);
    u32 b = func_0013d7e0();
    Q157* q = (Q157*)(p + 3364) + func_00139c18(p + 3364);
    func_001386e0(q, 7000, a, b, 130, c);
    q->f396 = p + 6704;
    func_001396b0(q);
    if (q->f396) {
        q->f400 = 0;
        func_001396b0(q);
        if (q->f400) func_0031a260(q, 0);
    }
    func_00138c10(p + 11648, func_00155f40(p));
    func_00138c10(p + 12060, func_00155fc0(p));
    p[15607] = 1;
}
}

// ---- 159dc0 ----
extern "C" {
struct M159 { f32 m[4][4]; } __attribute__((aligned(16)));
u8* func_00106a18(s32);  // buffer_get_256
u8* func_00106a60(s32);  // buffer_get_by_index
s32* func_0013a178(void*, M159*);

static inline void mulmat159(M159* d, const void* a, const void* b) {
    asm volatile(
        "lqc2 $vf1,0(%1)\n\tlqc2 $vf2,16(%1)\n\tlqc2 $vf3,32(%1)\n\tlqc2 $vf4,48(%1)\n\t"
        "lqc2 $vf5,0(%2)\n\tlqc2 $vf6,16(%2)\n\tlqc2 $vf7,32(%2)\n\tlqc2 $vf8,48(%2)\n\t"
        "vmulax.wxyz ACC,$vf1,$vf5x\n\tvmadday.wxyz ACC,$vf2,$vf5y\n\tvmaddaz.wxyz ACC,$vf3,$vf5z\n\tvmaddw.wxyz $vf5,$vf4,$vf5w\n\t"
        "vmulax.wxyz ACC,$vf1,$vf6x\n\tvmadday.wxyz ACC,$vf2,$vf6y\n\tvmaddaz.wxyz ACC,$vf3,$vf6z\n\tvmaddw.wxyz $vf6,$vf4,$vf6w\n\t"
        "vmulax.wxyz ACC,$vf1,$vf7x\n\tvmadday.wxyz ACC,$vf2,$vf7y\n\tvmaddaz.wxyz ACC,$vf3,$vf7z\n\tvmaddw.wxyz $vf7,$vf4,$vf7w\n\t"
        "vmulax.wxyz ACC,$vf1,$vf8x\n\tvmadday.wxyz ACC,$vf2,$vf8y\n\tvmaddaz.wxyz ACC,$vf3,$vf8z\n\tvmaddw.wxyz $vf8,$vf4,$vf8w\n\t"
        "sqc2 $vf5,0(%0)\n\tsqc2 $vf6,16(%0)\n\tsqc2 $vf7,32(%0)\n\tsqc2 $vf8,48(%0)"
        : : "r"(d), "r"(a), "r"(b) : "memory");
}

// projects through the current view matrices and returns screen-clip outcode bits
u32 func_00159dc0(void* obj, s32* rc) {
    M159 m;
    u8* a = func_00106a18(1);  // buffer_get_256
    u8* b = func_00106a60(1);  // buffer_get_by_index
    mulmat159(&m, a, b ? b + 16 : 0);
    s32* r = func_0013a178(obj, &m);
    u32 f = (r[0] < rc[0]) << 2;
    if (rc[1] < r[0]) f |= 8;
    f |= r[1] < rc[2];
    if (rc[3] < r[1]) f |= 2;
    if (r[2] <= 0) f |= 0x10;
    if (r[2] > 4000000) f |= 0x20;
    return f;
}
}

// ---- 187520 ----
extern "C" {
struct E187 { u32 f0; u32 f4; u32 f8; };
s32 func_0017e138(u8*, s32);
s32 func_001a1910(E187*, s32, s32);  // entry12_add_clamped
void func_0013def8(u8*);
void func_0019d3f8(u8*, s32, s32);
void func_0019d3b8(u8*, s32, s32);
void func_00187818(u8*);

s32 func_00187520(u8* self, s32 n, s32 idx, u8 flag) {
    E187* t = *(E187**)(self + 1164);
    if (!t || !t[idx].f4) return 0;
    if (*(u32*)(self + 1416) & 0x4000) {
        if (n > 0) {
            if (*(u32*)(self + 2040) & 4) {
                n = func_0017e138(self, n);
            } else if (flag) {
                (*(void (**)(u8*, s32, s32))(*(u8**)self + 84))(self, 20, 0);
            }
        }
    }
    if (*(u32*)(self + 2040) & 4) return 0;
    s32 r = func_001a1910(*(E187**)(self + 1164), n, idx);  // entry12_add_clamped
    if (n > 0) {
        func_0013def8(self);
        func_0019d3f8(self, idx, r);
    } else {
        func_0019d3b8(self, idx, r);
    }
    if (!r && !idx) func_00187818(self);
    return r;
}
}

// ---- 196f00 ----
extern "C" {
struct H196 {
    u16 f0;
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
};
static inline u8 bit0_196(H196* h) { return h->b0; }
static inline u8 bit2_196(H196* h) { return h->b2; }
static inline u8 bit3_196(H196* h) { return h->b3; }
struct P196 {
    u32 f0; void* f4; u32 f8; u8 pad[48]; H196* f60; u8 pad2[4]; u32 f68; u8 pad3[8]; u8 f80[76]; u32 f156; u32 f160;
};
struct G196 { u32 f0; u32 f4; };
void func_00226ac0(void*, u8*, u32, u32, void (*)(void), u32, u32);
void func_00197d40(void);
void func_00196e00(P196*);
void func_00105110(P196*);
void func_001c1130(s32);  // copy_record_block_to_table
void func_0014c9d8(s32);
void func_00197760(void);
void func_00197c90(void);
void func_002ef8d0(void*, u32);
void func_00196e88(P196*, s32, s32, f32);
extern P196* D_0035037c;
extern G196 D_0032b968;
extern u8 D_01c61b10;
extern u8 D_01c61b20;

void func_00196f00(P196* p) {
    if (p->f4) func_00226ac0(p->f4, p->f80, p->f68, p->f8, func_00197d40, p->f156, p->f160);
    P196* old = D_0035037c;
    if (old) {
        func_00196e00(old);
        func_00105110(old);
    }
    D_0035037c = p;
    func_001c1130(12);  // copy_record_block_to_table
    func_0014c9d8(4);
    if (!bit3_196(p->f60)) func_00197760();
    if (!bit2_196(p->f60)) func_00197c90();
    func_002ef8d0(&D_01c61b10, D_0032b968.f4);
    func_002ef8d0(&D_01c61b20, D_0032b968.f4);
    if (!bit0_196(p->f60)) p->f0 |= 2;
    func_00196e88(p, 0, 0, 0.0f);
}
}

// ---- 1a9ae8 ----
struct Six1a9 { u32 w[6]; };
struct T1a9 {
    u32 f0, f4, f8, f12, f16, f20;
    f32 f24;
    u32 f28;
    Six1a9 f32_;
    u32 pad[2];
    u8 sub[16];
};
struct S1a9 {
    u32 f0; u32 f4; u32 f8; u8* f12; u8 f16[8]; u32 pad; f32 f28; u32 pad2; Six1a9 f36; u32 f60; u32 pad3; s32 f68; s32 f72; u32 pad4[3]; u32 f88;
};
extern "C" {
extern f32 D_00349e10;
void func_001aa7f0(T1a9*, u32);
void func_001a9a28(u32, u8*, s32*, s32*);
u32 func_001aa6f0(S1a9*, u32);
u32 func_00192a80(u8*);
void func_001aa850(T1a9*, u32);
u8* func_001a9c20(S1a9*, T1a9*, u8*);
void func_001aa980(T1a9*);
void func_001b7f30(void*);
void wt_001a9ae8(S1a9*, s32, s32, u32) asm("_Z16wtarget_001a9ae8jjjj");

void wt_001a9ae8(S1a9* self, s32 x, s32 y, u32 z) {
    u8* it = self->f12;
    if (!it) return;
    T1a9 t;
    func_001aa7f0(&t, self->f4);
    func_001a9a28(self->f88, self->f16, &x, &y);
    f32 f = self->f28 + D_00349e10;
    x = x * 16 + 28672;
    y = y * 16 + 29440;
    self->f28 = f;
    t.f8 = x;
    t.f24 = f;
    t.f12 = y;
    self->f68 = x;
    t.f16 = z;
    self->f72 = y;
    self->f60 = z;
    t.f32_ = self->f36;
    t.f28 = 0;
    t.f20 = func_001aa6f0(self, 0x60000000);
    do {
        func_001aa850(&t, func_00192a80(it));
        it = func_001a9c20(self, &t, it);
        func_001aa980(&t);
    } while (it);
    func_001b7f30(t.sub);
}
}

// ---- 1ae7d0 ----
extern "C" {
struct S1ae { u32 pos; u32 f4; u8* f8; };
s32 func_002f79c8(s32);
s32 func_002f7be8(u32, u32, u8*, void*);
void func_001ae678(void);  // to_306698_arg10
void func_001ae620(void);
s32 func_002f7dc8(void);
void func_001ae650(void);
extern u8 D_00350ca8;
extern s32 D_00350c88;

u32 func_001ae7d0(S1ae* s, u8* buf, u32 size) {
    u32 n = (size + 2047) >> 11;
    u32* sec = (u32*)(s->f8 + 8);
    for (;;) {
        if (func_002f79c8(1) != 2 || func_002f7be8(*sec, n, buf, &D_00350ca8) != 1) {
            func_001ae678();  // to_306698_arg10
            continue;
        }
        func_001ae620();
        D_00350c88 = func_002f7dc8();
        if (!D_00350c88) break;
        func_001ae650();
    }
    s->pos += n << 11;
    *sec += n;
    return size;
}
}

// ---- 1b5b20 ----
extern "C" {
struct C1b5 { u8 pad[384]; s32 f384; u8 pad2[48]; f32 f436; };
void* func_001d3fe0(u16);
s32 func_001b58a8(void);
s32 func_001c8db8(void*, s32);
s32 func_001d3f80(void*);
s32 func_001b5c60(u16*);  // to_1bbf80_field28
s32 func_001a1de0(C1b5*);
void* func_0017df58(s32);
s32 func_0019ba60(void*);
s32 func_0017e280(void*);
extern u8 D_00351ec0;

s32 func_001b5b20(u8* self, u16* ev, s32 r) {
    void* o = func_001d3fe0(ev[0]);
    if (!o) return r;
    if (func_001b58a8()) {
        r = 5;
    } else if (ev[1] == 81 && func_001c8db8(&D_00351ec0, 0)) {
        r = 5;
    } else if (func_001d3f80(o)) {
        if ((*(C1b5**)(self + 1164))->f436 == 0.0f) r = 5;
    } else {
        s32 n = func_001b5c60(ev);  // to_1bbf80_field28
        if (n > 0) {
            if (func_001a1de0(*(C1b5**)(self + 1164))) r = 5;
            else if ((*(C1b5**)(self + 1164))->f384 < n) r = 2;
        }
    }
    if (ev[1] == 707 && r < 4) {
        for (s32 i = 0; i < 2; i++) {
            void* q = func_0017df58(i);
            if (func_0019ba60(q) && !func_0017e280(q)) { r = 5; break; }
        }
    }
    return r;
}
}

// ---- 1cd168 ----
struct A1cd { u16 h[5]; };
struct B1cd { u32 w[522]; };
#ifndef BIG1CD
#define BIG1CD
struct Big1cd { u64 d[0x10fc0 / 8]; } __attribute__((aligned(16)));
#endif
struct Dst1cd { A1cd a; u16 pad; B1cd b; B1cd c; };
struct Src1cd { B1cd b; B1cd c; };
extern "C" {
#ifndef BIG1CD_DECL
#define BIG1CD_DECL
extern Big1cd D_0032bb30;
#endif
extern Big1cd D_01d499b0;
extern A1cd D_0032bae0;
extern Src1cd D_0034f250;
extern Dst1cd D_01d5a970;
s32 func_001cd4c0(void);

// snapshots the live game state into the backup copies
void func_001cd168(void) {
    if (func_001cd4c0()) {
        D_01d499b0 = D_0032bb30;
        D_01d5a970.a = D_0032bae0;
        D_01d5a970.b = D_0034f250.b;
        D_01d5a970.c = D_0034f250.c;
    }
}
}

// ---- 1ce930 ----
extern "C" {
struct S1ce { s32 state; u32 f4; union { struct { u32 r0 : 1; u32 r1 : 1; } b; u32 req; }; };
u32 func_00167f18(s32);
void func_001ceb40(S1ce*, s32);
s32 func_00186ce8(u8*);
void func_001cea48(S1ce*, u8*, u32);
extern u8* D_0034e948;
void wt_001ce930(S1ce*) asm("_Z16wtarget_001ce930jjjj");

void wt_001ce930(S1ce* s) {
    s32 on = 2;
    s32 one = 1;
    u32 v = func_00167f18(0);
    u8* t = D_0034e948;
    if (s->b.r1) {
        s32 st = s->state;
        if (st < 2) {
            func_001ceb40(s, 2);
            s->state = on;
            st = on;
        }
        if (st == on && (!func_00186ce8(t) || (*(u32*)(t + 352) & 0x10))) func_001cea48(s, t, v);
    } else if (s->b.r0) {
        if (s->state <= 0) {
            func_001ceb40(s, 0);
            s->state = one;
        }
    } else {
        switch (s->state) {
        case 1: func_001ceb40(s, 1); break;
        case 2: func_001ceb40(s, 4); break;
        }
        s->state = 0;
    }
    s->req = 0;
}
}

// ---- 1cfcf8 ----
#ifndef BIG1CD
#define BIG1CD
struct Big1cd { u64 d[0x10fc0 / 8]; } __attribute__((aligned(16)));
#endif
extern "C" {
struct Sub1cf { u32 a, b; u32 pad[6]; u32 c; };
static inline void init1cf(Sub1cf* p) { p->a = 0; p->b = 0; p->c = 0; }

struct C1cf { u8 pad[431]; u8 b431; u8 b432; u8 b433; u8 b434; };
struct G1cf { u8 pad[15792]; u16 c0; u16 c1; };
void func_00177dc8(u8*, u32, s32, u32, u32);
void func_0017a480(u8*, u32, s32, s32);
void func_001a1a50(C1cf*, s32);
void func_001d2648(u8*, u32, f32);  // clear_fields_0_4_32
void func_001c8d80(void*, s32);
extern u8 D_00352360;
#ifndef BIG1CD_DECL
#define BIG1CD_DECL
extern Big1cd D_0032bb30;
#endif
extern u8 D_00351ec0;
extern f32 D_0036e3bc;

void func_001cfcf8(u8* self, u32 a, u32 b, u32 c) {
    func_00177dc8(self, a, 11, b, c);
    u8* sub = self + 2932;
    *(u32*)(self + 2920) = 0;
    *(u32*)(self + 2924) = 0;
    *(u32*)self = (u32)&D_00352360;
    self[2928] = 0;
    init1cf((Sub1cf*)sub);
    *(u32*)(self + 1416) |= 0x2000000;
    ((C1cf*)*(u32*)(self + 1164))->b432 = 0;
    ((C1cf*)*(u32*)(self + 1164))->b433 = 0;
    ((C1cf*)*(u32*)(self + 1164))->b434 = 3;
    func_0017a480(self, *(u32*)(*(u32*)(self + 1164) + 4), 0, 0);
    func_001a1a50((C1cf*)*(u32*)(self + 1164), 0);
    f32 k = D_0036e3bc;
    ((C1cf*)*(u32*)(self + 1164))->b431 = 1;
    G1cf* g = (G1cf*)&D_0032bb30;
    if (g->c0 < 999) g->c0++;
    if (g->c1 < 999) g->c1++;
    *(u32*)(self + 2748) |= 0x240;
    func_001d2648(sub, 0xbbc2, k);  // clear_fields_0_4_32
    func_001c8d80(&D_00351ec0, 4);
}
}

// ---- 1d1070 ----
extern "C" {
struct T1d1 { u16 f0, f2, bit; u16 pad[5]; u16 id; };
struct B1d1 { u32 w[8]; };
s32 func_0017a538(u8*);
s32 func_001a2478(u32);  // count_div4_compare
u32* func_00177860(u8*);
T1d1* func_001a80c8(u16);  // table24_find_by_id
void* func_001b8e88(u16);
s32 func_001bc2a8(void*, u8*, s32);
void func_00190128(B1d1*);
void func_001bd3e0(u32, s32, u16, B1d1*, s32, s32);
extern u16 D_0036e390[];

s32 func_001d1070(u8* self) {
    if (func_0017a538(self) || !func_001a2478(*(u32*)(self + 1164))) return 0;
    u32* bits = func_00177860(self);
    u16* ids = D_0036e390;
    for (u32 i = 0; i < 4; i++) {
        T1d1* t = func_001a80c8(*ids++);  // table24_find_by_id
        u32 k = t->bit;
        if (bits[k >> 5] & (1 << (k & 31))) {
            if (func_001bc2a8(func_001b8e88(t->id), self, 0) < 4) {
            B1d1 b;
            func_00190128(&b);
            func_001bd3e0(*(u32*)(self + 2884), 1, t->id, &b, 1, 0);
            return 1;
            }
        }
    }
    return 0;
}
}

// ---- 1d7098 ----
extern "C" {
void func_001ada38(s32);
void func_002bea20(void);
void* func_00188fe0(void*, s32);
void func_00188bf8(void*, s32);
void func_00189028(void*, s32, s32, s32);
extern s32 D_0034ece8;
extern u8 D_0032e020;

void func_001d7098(s32 id) {
    switch (id) {
    case 12:
        func_001ada38(1);
        D_0034ece8 = 4;
        func_002bea20();
        break;
    case 50: case 51: case 52:
        D_0034ece8 = 3;
        break;
    case 176: case 179: case 184:
        func_00188bf8(func_00188fe0(&D_0032e020, 1), 41);
        break;
    case 182: case 183: case 186: case 296: case 297: case 298:
        func_00188bf8(func_00188fe0(&D_0032e020, 1), 384);
        break;
    case 187:
        func_00189028(&D_0032e020, 1, 41, 0);
        break;
    case 189:
        func_00188bf8(func_00188fe0(&D_0032e020, 1), 43);
        break;
    }
}
}

// ---- 1dfca8 ----
extern "C" {
union F1df { f32 f; u32 u; };
struct V1df { F1df x, y, z; };
u8* func_001946f0(u32);
V1df* func_001dc670(u32);
extern s32 D_00352b50;

// sets the model tint from the light colour, optionally as greyscale
void func_001dfca8(u8* self, u8 grey) {
    f32 g = 1.0f;
    f32 r = g;
    f32 b = g;
    if (D_00352b50 == 1) {
        u8* c = func_001946f0(*(u32*)(self + 72));
        r = c[0] * 0.0078125f;
        g = c[1] * 0.0078125f;
        b = c[2] * 0.0078125f;
    }
    if (grey) {
        b = r * 0.3f + g * 0.59f + b * 0.11f;
        g = b;
        r = b;
    }
    func_001dc670(*(u32*)(self + 64))->x.f = r;
    func_001dc670(*(u32*)(self + 64))->y.f = g;
    func_001dc670(*(u32*)(self + 64))->z.f = b;
}
}

// ---- 225788 ----
extern "C" {
union K225 { s32 i; s16 h; };
struct R225 { K225 kind; u32 pad[4]; u32 f20; u32 pad2[6]; char name[16]; };
struct S225 { u32 f0; u16 f4; s16 h6; };
void func_00225550(S225*);
void func_00136cc8(void*, s16);
R225* func_00227a28(void);
u32 func_002bd260(s16);
u32 func_002bd2f0(u32, u32*);
char* func_002ff2e8(char*, u32);
void func_002256c8(R225*, u32);
void func_00168388(u32, u32, void (*)(void), R225*);
void func_00226030(void);
s32 func_001688b8(void);
void func_00102448(void*, s32);

static inline void setup225(R225* r, u32 o) {
    func_002ff2e8(r->name, o);
    func_002256c8(r, o);
    func_00168388(o, r->f20, func_00226030, r);
}

void func_00225788(S225* s, void* x) {
    func_00225550(s);
    func_00136cc8(x, s->h6);
    R225* r = func_00227a28();
    r->kind.i = 6;
    setup225(r, func_002bd260(s->h6));
    while (func_001688b8()) func_00102448(x, 0);
    R225* r2 = func_00227a28();
    r2->kind.i = 5;
    u32 tmp = 0;
    setup225(r2, func_002bd2f0(*(u32*)((u8*)r + 20), &tmp));
}
}

// ---- 22f7c0 ----
struct V22f {
    f32 x, y, z, w;
    V22f() {}
    V22f(const V22f& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
extern "C" {
struct E22f { s32 f0; s32 id; void* obj; u32 pad[7]; };
s32 func_002282f0(u16);
void func_001ba028(void*);  // list_contains_ptr
f32 func_00227c78(u8*);
void func_0016adc8(void*, V22f);
void func_0022f6b8(void*, V22f*);
extern E22f* D_0035dcfc;

void func_0022f7c0(u8* s) {
    if (func_002282f0(*(u16*)(s + 38))) return;
    if (*(s16*)(s + 4)) return;
    f32 one = 1.0f;
    for (s32 i = 0; i < 96; i++) {
        E22f* e = (E22f*)((u32)(i * 40) + (u32)D_0035dcfc);
        if (e->f0 < 0) continue;
        if (*(s16*)(s + 36) != e->id) continue;
        void* o = e->obj;
        func_001ba028(o);  // list_contains_ptr
        V22f a, unused, b;
        (void)&unused;
        a.x = func_00227c78(s + 8);
        a.y = func_00227c78(s + 12);
        a.z = func_00227c78(s + 16);
        a.w = one;
        b.x = func_00227c78(s + 20);
        b.y = func_00227c78(s + 24);
        b.z = func_00227c78(s + 28);
        b.w = one;
        func_0016adc8(o, a);
        func_0022f6b8(o, &b);
        return;
    }
}
}

// ---- 231390 ----
extern "C" {
f32 func_00230f10(u8*, s32, s32, f32);

void func_00231390(f32* out, u8* c, f32 t) {
    out[0] = func_00230f10(c, 2, 0, t);
    out[1] = -func_00230f10(c + 32, 2, 0, t);
    out[2] = -func_00230f10(c + 64, 2, 0, t);
    out[3] = func_00230f10(c + 96, 2, 0, t);
    out[4] = -func_00230f10(c + 128, 2, 0, t);
    out[5] = -func_00230f10(c + 160, 2, 0, t);
    out[6] = func_00230f10(c + 192, 2, 0, t) * 3.14159274f / 180.0f;
    out[7] = func_00230f10(c + 224, 2, 0, t);
}
}

// ---- 2529a8 ----
extern "C" {
u32 func_00103570(void);
s16* func_001063f0(u32, u32);
s32 func_001a6d08(s16);
union P252 { s16* p; u32 u; s16 h; };
extern P252 D_0035ee9c;
extern s16 D_0035eea0;
extern u16* D_0035ee90[];
extern s16 D_003726a8[];

void func_002529a8(void) {
    s32 i;
    D_0035ee9c.p = func_001063f0(24, func_00103570());
    for (i = 0; i < 12; i++) D_0035ee9c.p[i] = -1;
    D_0035ee9c.p[0] = 0;
    s32 n = 1;
    for (i = 0; i < 3; i++) {
        if (func_001a6d08(D_003726a8[i])) {
            u16* t = D_0035ee90[i];
            D_0035ee9c.p[n++] = t[0];
            D_0035ee9c.p[n++] = t[2];
            D_0035ee9c.p[n++] = t[1];
        }
    }
    D_0035ee9c.p[n++] = 1;
    D_0035eea0 = n;
}
}

// ---- 262af8 ----
extern "C" {
struct I262 { u16 h0; u16 pad[4]; u16 h10; u16 pad2[4]; u16 h20; };
s32 func_00287bc0(void);
s32 func_002891e8(u32);
s32 func_00289300(u32);
void func_00263a58(s32, s32);
u32 func_00257130(void);
s32 func_00281f18(u32);
u32 func_0028b040(u32);
I262* func_002632d0(u32);
void func_00281cf0(u16);
s32 func_002570a0(s32);
extern u32 D_0035f01c;

void func_00262af8(void) {
    s32 m = func_00287bc0();
    u32 t;
    if (m == 1) {
        t = func_002891e8(D_0035f01c);
        func_00263a58((s32)t >= func_00289300(D_0035f01c) ? 0xbb87 : 0xbb86, 1);
    } else if (m == 10) {
        if (!func_00281f18(func_00257130())) {
            func_00263a58(-1, 1);
            return;
        }
        t = func_0028b040(D_0035f01c);
        if (!func_002632d0(t)) return;
        if (!func_002632d0(t)->h0) return;
        func_00263a58((u16)(func_002632d0(t)->h10 | 0x8000), 1);
        func_00281cf0(func_002632d0(t)->h20);
    } else if ((u32)(m - 11) < 2) {
        func_00263a58((u16)(func_002632d0(func_002570a0(10))->h10 | 0x8000), 1);
    }
}
}

// ---- 268c68 ----
extern "C" {
struct E268 { u16 id; u16 pad[2]; };
s32 func_002570a0(s32);
u32 func_00269508(s32);
s32 func_00281f18(u32);
u32 func_00257130(void);
E268* func_00281f20(u32);
void func_002891f0(u32, s32, s32, s32, s32);
void func_0028afd0(u32, s32);  // obj_set_signed18
void func_0028be78(u32, s32);
extern u32 D_0035f0ec;
extern u32 D_0035f01c;
extern u32 D_0035f04c;

void func_00268c68(void) {
    s32 cur = 0;
    s32 top = 0;
    s32 k = func_002570a0(2);
    u32 mode = func_00269508(k);
    s32 n = func_00281f18(D_0035f0ec);
    u16 id = func_00281f20(func_00257130())[k].id;
    if (id) {
        E268* p = func_00281f20(D_0035f0ec);
        for (s32 i = 0; i < n; i++, p++) {
            if (p->id == id) {
                cur = i;
                if (mode >= 2) cur = i + 1;
                break;
            }
        }
    }
    if (mode >= 2) n++;
    if (cur >= 8) {
        top = cur - 7;
        cur = 7;
    }
    if (n != 0 && top + cur >= n) {
        top = cur - n + 1;
        cur = n - 1;
    }
    func_002891f0(D_0035f01c, cur, 0, -1, -1);
    func_0028afd0(D_0035f01c, top);  // obj_set_signed18
    func_0028be78(D_0035f04c, top);
}
}

// ---- 275b60 ----
extern "C" {
struct Sub275 { u8 pad[388]; s32 anim; s32 f392; u8 pad2[40]; };
struct Obj275 { Sub275 sub[4]; };
s32 func_00139d78(Sub275*);
void func_00138c10(void*, s32);
extern Obj275* D_0035f20c;

static inline void reset275(s32 i, s32 id) {
    if (func_00139d78(&D_0035f20c->sub[i])) {
        Sub275* s = &D_0035f20c->sub[i];
        if (s->anim != id) {
            func_00138c10(s, id);
            D_0035f20c->sub[i].f392 = -1;
        }
    }
}

// puts the four menu cursors back on their idle animations
void func_00275b60(void) {
    reset275(2, 54);
    reset275(3, 45);
    reset275(0, 48);
    reset275(1, 51);
}
}

// ---- 27c5a0 ----
extern "C" {
u32 func_00257770(void);
void func_0028f4d8(s32, s32, s32);
void func_0027c9a8(void);
void func_0027ccf8(void);
s32 func_00257070(s32);
s32 func_00257088(s32);
void func_002891f0(u32, s32, s32, s32, s32);
void func_0028afd0(u32, s32);  // obj_set_signed18
void func_0028af90(u32, s32);  // obj_set_field22_from_arg
void func_0028b218(u32, s32);  // obj_set_flag39_bits3000
void func_0028b248(u32, s32);  // set_field28_half
u8* func_0023f1b0(u32);
u32 func_0023c4b8(u8*, u32);
u32 func_00236ca8(u32, u32);
u32 func_002570f0(void);
void func_0028bae0(u32, u32, u32, u32, u32, s32, s32, u32, s32);
void func_0028af28(u32, s32);
u32 func_0028b040(u32);
void func_0027d810(u32);
void func_0027d008(void);
void func_00287cc0(s32);
extern u32 D_0035f01c;
extern u32 D_0035f03c;
extern u32 D_0035f04c;
extern u32 D_0035ef68;
extern u32 D_0035ef64;
extern u32 D_0035f3d4;

void func_0027c5a0(void) {
    u32 a = func_00257770();
    func_0028f4d8(0, -1, 0);
    func_0027c9a8();
    func_0027ccf8();
    func_002891f0(D_0035f01c, func_00257070(36), 0, -1, -1);
    func_0028afd0(D_0035f01c, func_00257088(36));  // obj_set_signed18
    func_0028af90(D_0035f01c, 10);  // obj_set_field22_from_arg
    func_0028b218(D_0035f01c, 1);  // obj_set_flag39_bits3000
    func_0028b248(D_0035f01c, 9);  // set_field28_half
    u32 b = func_0023c4b8(func_0023f1b0(D_0035f03c), D_0035ef68);
    u32 c = func_00236ca8(*(u32*)(func_0023f1b0(D_0035f03c) + 40), D_0035ef64);
    u32 d = D_0035f3d4;
    func_0028bae0(D_0035f04c, d, b, c, func_002570f0(), 10, 9, a, 0);
    func_0028af28(D_0035f01c, 16);
    func_0027d810(func_0028b040(D_0035f01c));
    func_0027d008();
    func_00287cc0(0);
}
}

// ---- 288478 ----
extern "C" {
struct VT288 { void (*f0)(void); void (*f4)(void); void (*f8)(void); };
void func_002883f8(void*);
void func_00102448(void*, s32);
s32 func_00103398(s16);
s32 func_001033b0(s16);
void func_00242fa0(void);
VT288* func_00243150(s32);
void func_002530c8(void);  // set_state_30012
VT288* func_00253330(s32);
void func_00103ea0(void (*)(void));  // set_hook_ptr
void func_00288638(void);
void func_00236d60(void);  // clear_64_entries_24
void func_00288870(void);
void func_0023fad0(void*);
extern s16 D_0035f32a;
extern s16 D_0035f32c;
extern s16 D_0035f32e;
extern u8 D_0035f330;
extern u8 D_0035f3a8;

void func_00288478(void* ctx) {
    func_002883f8(ctx);
    func_00102448(ctx, 1);
    s32 id = func_00103398(D_0035f32a);
    s32 kind = func_001033b0(D_0035f32a);
    if (kind != 1) {
        func_002530c8();  // set_state_30012
        func_00253330(id)->f4();
    } else {
        func_00242fa0();
        func_00243150(id)->f4();
    }
    D_0035f330 = 0;
    func_00103ea0(func_00288638);  // set_hook_ptr
    for (;;) {
        func_00236d60();  // clear_64_entries_24
        func_00288870();
        if (D_0035f330) break;
        func_00102448(ctx, 0);
    }
    if (kind != 1) {
        func_00253330(id)->f8();
    } else {
        func_00243150(id)->f8();
        func_0023fad0(&D_0035f3a8);
    }
    D_0035f32a = D_0035f32c;
    D_0035f32c = D_0035f32e;
    D_0035f32e = -1;
}
}

// ---- 2a10e0 ----
extern "C" {
struct T2a1 { u8 f0; s8 slot; u8 pad[66]; s16 x; s16 y; s16 x0, x1, y0, y1; };
union I2a1 { s32 i; s16 h; };
union PT2a1 { T2a1* p; u16 h; };
union PU2a1 { u8* p; u32 w; };
struct Sub2a1 { u8 pad[184]; u32 flags; };
u8* func_002766d0(void);
void func_0028d8c0(u8*, s32, u32, u32, u32, s32, s32, s32);
void func_0028dcc0(u8*, u8*);
void func_00138cd0(u8*, I2a1*, I2a1*);
void func_00138c68(u8*, s32, s32);
void func_002a16b8(void);
void func_002a1220(void);
extern PU2a1 D_0035f5d8;
extern PT2a1 D_0035f5d4;
extern u32 D_0035f14c;
extern u32 D_0035f148;
extern u32 D_0035f210;
static inline Sub2a1* sub2a1(u8* p) { return (Sub2a1*)(p + 840); }

void func_002a10e0(void) {
    u8* r = func_002766d0();
    func_0028d8c0(D_0035f5d8.p + 816, 30065, D_0035f14c, D_0035f148, D_0035f210, 34, -1, 0);
    func_0028dcc0(D_0035f5d8.p + 816, r);
    I2a1 x, y;
    T2a1* t = D_0035f5d4.p;
    if (t->slot < 0) {
        x.i = t->x0 + (t->x1 - t->x0) / 2;
        y.i = t->y0 + (t->y1 - t->y0) / 2;
    } else {
        func_00138cd0(r + t->slot * 408 + 4248, &x, &y);
    }
    sub2a1(D_0035f5d8.p)->flags |= 8;
    func_00138c68(D_0035f5d8.p + 816, x.i, y.i);
    D_0035f5d4.p->x = x.i;
    D_0035f5d4.p->y = y.i;
    func_002a16b8();
    func_002a1220();
}
}

// ---- 2ac538 ----
extern "C" {
struct E2ac { s8 id; u8 lo : 4; u8 hi : 4; u8 pad[14]; };
struct L2ac { u32 f0, f4; s32 count; u32 f12; E2ac e[1]; };
u8* func_002a9d68(void);
L2ac* func_00294000(s32);
s32 func_002b3ac8(s8);
extern u8* D_0035f610;

s32 func_002ac538(s32 kind) {
    s32 res = 1;
    u8* m = func_002a9d68();
    L2ac* l = func_00294000(9);
    E2ac* e = l->e;
    for (s32 i = 0; i < l->count; i++, e++) {
        if (kind >= 0 && e->id != kind) continue;
        s32 n = func_002b3ac8(e->lo);
        for (s32 j = 0; j < n; j++) {
            u32* a = (u32*)(D_0035f610 + e->id * 8 + 324);
            u32* b = (u32*)(m + e->id * 8 + 324);
            u32 bit = 1 << (j & 31);
            if (a[(u32)j >> 5] & bit) {
                res = (b[(u32)j >> 5] & bit) != 0;
                if (!res) break;
            }
        }
        if (kind >= 0 && e->id == kind) return res;
    }
    return res;
}
}

// ---- 2cf058 ----
extern "C" {
struct V2cf {
    f32 x, y, z, w;
    V2cf() {}
    V2cf(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
} __attribute__((aligned(16)));
struct M2cf { V2cf r[4]; };
struct T2cf { u16 f0; u16 kind; f32 x, y, z; };
struct Box2cf { u8 d[32]; } __attribute__((aligned(16)));
void func_0011b6a8(M2cf*);
void func_001444c8(Box2cf*, V2cf*, V2cf*);
void func_001449a8(Box2cf*, M2cf*);
s32 func_002cec08(u8*, Box2cf*);
void wt_002cf058(u8*, u8*) asm("_Z16wtarget_002cf058jjjj");

static inline void trans2cf(M2cf* m, V2cf* v) {
    asm volatile("lqc2 $vf1,48(%0)\n\tlqc2 $vf2,0(%1)\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,48(%0)" : : "r"(m), "r"(v) : "memory");
}

void wt_002cf058(u8* self, u8* obj) {
    T2cf* t = *(T2cf**)(obj + 108);
    if (t->kind != 3) return;
    f32 zero = 0.0f;
    V2cf v(t->x, t->y, t->z, zero);
    M2cf m;
    func_0011b6a8(&m);
    trans2cf(&m, &v);
    V2cf lo, hi;
    Box2cf box;
    lo.x = 1.0f;
    lo.y = 1.0f;
    hi.x = -1.0f;
    hi.y = -1.0f;
    lo.z = 1.0f;
    lo.w = zero;
    hi.z = -1.0f;
    hi.w = zero;
    func_001444c8(&box, &hi, &lo);
    func_001449a8(&box, &m);
    if (func_002cec08(self, &box)) *(u32*)(obj + 104) |= 1;
    else *(u32*)(obj + 104) &= ~1;
}
}

// ---- 2d00e0 ----
extern "C" {
struct Mgr2d0 { s32 (**vt)(Mgr2d0*, u8*); };
u8* func_001b9bc8(u8*);
s32 func_0019c768(u8*);
s32 func_002cf270(u8*, s32);
void func_002cf2b0(u8*, s32);
void func_002d0c28(u8*);
extern Mgr2d0* D_00361f60;
void wt_002d00e0(void) asm("_Z16wtarget_002d00e0jjjj");

void wt_002d00e0(void) {
    u8* o = 0;
    while ((o = func_001b9bc8(o)) != 0) {
        if (!(*(u32*)(o + 1416) & 0x8000000)) continue;
        if (func_0019c768(o)) continue;
        u8* st = o + 2800;
        if (func_002cf270(st, 0x2000)) {
            func_002d0c28(o);
            continue;
        }
        s32 ok = 0;
        if (func_002cf270(st, 4)) ok = 1;
        else if (func_002cf270(st, 1)) ok = D_00361f60->vt[7](D_00361f60, o) != 0;
        if (!ok) continue;
        func_002cf2b0(st, 4);
        func_002cf2b0(st, 1);
        if (func_002cf270(st, 0x1000)) func_002d0c28(o);
        else (*(void (**)(u8*))(*(u8**)o + 32))(o);
    }
}
}

// ---- 319bd0 ----
extern "C" {
struct C319 { u16 a, b, c; };
struct G319 { C319 c[64]; };
struct R319 { u32 w[8]; };
struct P319 { u32 a, b; };
struct S319 {
    u32 f0;
    G319 grid[19];
    R319 rows[19];
    u32 f7908;
    u32 f7912;
    u8 pad[1024];
    P319 pairs[19];
    u32 w9092[7];
    u32 w9120[16];
    u32 pad1[5];
    u32 w9204[16];
    u32 pad2[23];
    u32 f9360;
    P319 tail[10];
};

// constructs the per-map table block (all slots cleared)
void func_00319bd0(void* sp) {  // clear_18x64_entries
    S319* s = (S319*)sp;
    G319* g = s->grid;
    for (s32 n = 18; n != -1; n--) {
        C319* c = g->c;
        for (s32 k = 63; k != -1; k--) {
            c->a = 0;
            c->b = 0;
            c->c = 0;
            c++;
        }
        g++;
    }
    R319* r = s->rows;
    for (s32 n = 18; n != -1; n--) {
        for (s32 i = 0; i < 8; i++) r->w[i] = 0;
        r++;
    }
    s->f7908 = 0;
    s->f7912 = 0;
    P319* p = s->pairs;
    for (s32 n = 18; n != -1; n--) {
        p->a = 0;
        p->b = 0;
        p++;
    }
    for (s32 i = 0; i < 7; i++) s->w9092[i] = 0;
    for (s32 i = 0; i < 16; i++) s->w9120[i] = 0;
    for (s32 i = 0; i < 16; i++) s->w9204[i] = 0;
    s->f9360 = 0;
    P319* q = s->tail;
    for (s32 n = 9; n != -1; n--) {
        q->a = 0;
        q->b = 0;
        q++;
    }
}
}

// ---- 31b3b8 ----
extern "C" {
void func_0031a838(u8*);
void func_00239700(u8*);
void func_002361a0(u8*);
void func_0013ee88(u8*);
void func_0014b668(u8*);
extern u8 D_00348608[];
extern u8 D_00347f98[];
extern u8 D_00347e60[];
extern u8 D_0034a800[];
extern u8 D_0034a848[];
extern u8 D_0034a958[];
extern u8 D_00348658[];

void func_0031b3b8(u8* s) {
    *(u32*)(s + 12) = 0;
    *(u32*)s = (u32)D_00348608;
    *(u32*)(s + 64) = (u32)D_00347f98;
    func_0031a838(s + 76);
    *(u32*)(s + 64) = (u32)D_00347e60;
    func_00239700(s + 88);
    *(u32*)(s + 64) = (u32)D_0034a800;
    func_002361a0(s + 480);
    *(u32*)s = (u32)D_0034a848;
    u8* e = s + 916;
    for (s32 n = 3; n != -1; n--) {
        *(u32*)e = (u32)D_00347f98;
        func_0031a838(e + 12);
        *(u32*)e = (u32)D_00347e60;
        func_00239700(e + 24);
        *(u32*)e = (u32)D_0034a958;
        e += 412;
    }
    e = s + 2576;
    for (s32 n = 4; n != -1; n--) {
        *(u32*)e = (u32)D_00347f98;
        func_0031a838(e + 12);
        *(u32*)e = (u32)D_00348658;
        func_0013ee88(e + 32);
        func_0014b668(e + 320);
        e += 592;
    }
}
}
