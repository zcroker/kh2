#include "../common/types.h"

extern "C" {
extern s32 func_00287cd0(void*);
extern s32 func_00289310(void*);
extern s32 func_002891e8(void*);
extern void func_002890e0(void*, s32, s32, s32, s32);
extern void func_00289038(void*, s32, s32, s32, s32, s32, s32);
extern void func_0023f070(void*, s32, s32);
extern void func_0024c898(void);
extern s32 func_0028d008(s32);
extern s32 func_002891d0(void*);
extern void func_0028cf28(s32, s32);  // record408_set_and_refresh
extern void func_002b4388(void*, void*, s32);
struct W268E6 { s16 a, b, c; };
struct W268E36 { u8 d[36]; };
extern W268E6 D_00371ff0[];
extern void* D_0035edb8;
extern void* D_0035edc0;
extern W268E36 D_00372030[];
extern W268E36 D_003720a0[];
extern void func_00250998(void);
extern W268E6 D_00372448[];
extern void* D_0035ee44;
extern void* D_0035ee4c;
extern W268E36 D_00372490[];
extern W268E36 D_00372548[];

void func_0024c420(void* a0, s32 a1, s32 a2)
{
    s32 cur;
    if (func_00287cd0(a0) != 1) return;
    if (func_00289310(a0) == 0) return;
    cur = func_002891e8(a0);
    func_002890e0(a0, 1, 2, 0, -1);
    func_00289038(a0, cur, 1, 1, 2, 0, -1);
    if (a1 == 0) {
        func_0023f070(D_0035edb8, D_00371ff0[cur].c, -1);
        func_0024c898();
    }
    if (func_0028d008(a2)) func_0028cf28(a2, func_002891d0(a0));
    func_002b4388(D_0035edc0, a1 == 0 ? &D_00372030[cur] : &D_003720a0[cur], 0);
}

void func_00250550(void* a0, s32 a1, s32 a2)
{
    s32 cur;
    if (func_00287cd0(a0) != 1) return;
    if (func_00289310(a0) == 0) return;
    cur = func_002891e8(a0);
    func_002890e0(a0, 1, 2, 0, -1);
    func_00289038(a0, cur, 1, 1, 2, 0, -1);
    if (a1 == 0) {
        func_0023f070(D_0035ee44, D_00372448[cur].c, -1);
        func_00250998();
    }
    if (func_0028d008(a2)) func_0028cf28(a2, func_002891d0(a0));
    func_002b4388(D_0035ee4c, a1 == 0 ? &D_00372490[cur] : &D_00372548[cur], 0);
}

struct W268VObj { void (**vt)(W268VObj*); };
struct W268FnHolder { u8 pad[8]; void (*fn)(void); };
extern u8 D_0035f328;
extern s16 D_0035f32a;
extern s16 D_0035f32c;
extern s16 D_0035f32e;
extern W268VObj* D_0035f334;
extern W268VObj* D_0035f338;
extern W268VObj* D_0035f33c;
extern W268VObj* D_0035f340;
extern s32 D_0035f344;
extern u8 D_0035f3a8[];
extern s32 func_00103398(s32);
extern s32 func_001033b0(s32);
extern W268FnHolder* func_00253330(s32);
extern W268FnHolder* func_00243150(s32);
extern void func_0023fad0(void*);
void func_002881c0(void)
{
    if (D_0035f328) {
        s32 id = func_00103398(D_0035f32a);
        if (func_001033b0(D_0035f32a) != 1) {
            func_00253330(id)->fn();
        } else {
            func_00243150(id)->fn();
            func_0023fad0(D_0035f3a8);
        }
    }
    if (D_0035f334) { D_0035f334->vt[1](D_0035f334); D_0035f334 = 0; }
    if (D_0035f338) { D_0035f338->vt[4](D_0035f338); D_0035f338 = 0; }
    if (D_0035f33c) { D_0035f33c->vt[1](D_0035f33c); D_0035f33c = 0; }
    if (D_0035f340) { D_0035f340->vt[1](D_0035f340); D_0035f340 = 0; }
    D_0035f32a = -1;
    D_0035f344 = 0;
    D_0035f32c = -1;
    D_0035f328 = 0;
    D_0035f32e = -1;
}

s32 func_002fdfc8(const char*, ...);  // device_vprintf_va
extern char D_0036e978[], D_0036ed60[], D_0036e998[], D_0036e9d0[], D_0036ed78[], D_0036ed98[];
void func_001e3898(void*, s32);
s32* func_001e3650(void*);  // ptr_add4
void func_001e8288(s32, s32);
static inline void assert_fail_1e50a8(const char* e, const char* f, s32 l) {
    func_002fdfc8(D_0036e978, e);  // device_vprintf_va
    func_002fdfc8(D_0036e998, f, l);  // device_vprintf_va
    asm volatile("break");
}
void func_001e50a8(s32* a0, s32 a1) {
    s32 v;
    if (!a0) assert_fail_1e50a8(D_0036ed60, D_0036e9d0, 1441);
    if ((u32)a0 & 0xf) assert_fail_1e50a8(D_0036ed78, D_0036e9d0, 1442);
    func_001e3898(a0, a1);
    a0 = func_001e3650(a0);  // ptr_add4
    s32 n = *a0++;
    for (s32 i = 0; i < n; i++) {
        v = *a0++;
        if (v & 0xf) assert_fail_1e50a8(D_0036ed98, D_0036e9d0, 1460);
        func_001e8288(v, a1);
    }
}

extern char D_0036ef58[], D_0036ef70[], D_0036ef98[], D_0036ef88[];
extern void* D_01d9e6e4;
struct W268Desc { u8 pad[0x20]; s32* tbl; s16 pri; s16 idx; };
struct W268Item;
struct W268Owner { W268Desc* desc; W268Item* last; u8 pad8[4]; u16 count; };
struct W268Item { W268Item* next; u8 p4[4]; W268Owner* owner; s32 f0c; u8 p10[0x80]; s32 f90; s32 f94; u8 p98[4]; u8 b9c; u8 b9d; u8 b9e; };
struct W268Mgr { u8 pad[0x74]; W268Item* head; };
W268Item* func_001e7698(void*, s32*);  // alloc_aligned16
void func_001e79f0(W268Item*);
static inline void assert_fail_1e7a98(const char* e, const char* f, s32 l) {
    func_002fdfc8(D_0036ef58, e);  // device_vprintf_va
    func_002fdfc8(D_0036ef98, f, l);  // device_vprintf_va
    asm volatile("break");
}
W268Item* func_001e7a98(W268Mgr* mgr, W268Owner* own) {
    W268Desc* d = own->desc;
    W268Item* it = func_001e7698(D_01d9e6e4, &d->tbl[d->idx]);  // alloc_aligned16
    if ((u32)it & 0xf) assert_fail_1e7a98(D_0036ef70, D_0036ef88, 222);
    it->f0c = 0;
    it->b9c = 1;
    it->f90 = 0;
    it->f94 = 0;
    it->owner = own;
    asm volatile("" ::: "memory");
    it->b9d = 0;
    it->b9e = 0;
    W268Item* n = mgr->head;
    if (n == 0) {
        own->last = it;
        mgr->head = it;
        it->next = 0;
    } else if (own->last) {
        it->next = own->last->next;
        own->last->next = it;
    } else {
        s16 pri = d->pri;
        W268Item** pp = &mgr->head;
        for (;;) {
            if (n->owner->desc->pri >= pri) {
                own->last = it;
                *pp = it;
                it->next = n;
                goto done;
            }
            pp = &n->next;
            n = n->next;
            if (!n) break;
        }
        own->last = it;
        *pp = it;
        it->next = 0;
    }
done:
    own->count++;
    func_001e79f0(it);
    return it;
}

extern void* D_0035f638;
extern u8* D_0035f634;
extern void* D_0035f630;
extern u8 D_00347e60[];
extern u8 D_00347f98[];
void func_0023f848(void*);
void func_00106420(void*);
void func_00106450(void*);
void func_0031acc0(void*);
void func_0031abd8(void*);
void func_00239870(void*);
void func_002816f0(void);
void func_002aeba0(void)
{
    void* lf = D_0035f638;
    if (lf) {
        func_0023f848(lf);
        func_00106420(lf);
        D_0035f638 = 0;
    }
    u8* p = D_0035f634;
    if (p) {
        func_0031acc0(p + 24212);
        func_0031acc0(p + 23776);
        func_0031acc0(p + 23340);
        func_0031acc0(p + 22904);
        func_0031acc0(p + 22468);
        func_0031acc0(p + 22032);
        func_0031abd8(p + 21624);
        func_0031abd8(p + 21216);
        func_0031abd8(p + 20808);
        if (p + 19992) {
            u8* e = p + 20808;
        top1:
            if (p + 19992 == e) goto out1;
            e -= 408;
            ((W268VObj*)e)->vt[3]((W268VObj*)e);
            goto top1;
        out1:;
        }
        u8* e2 = p + 19584;
        *(u32*)(p + 19584) = (u32)D_00347e60;
        func_00239870(p + 19608);
        *(u32*)(p + 19584) = (u32)D_00347f98;
        if (p) {
            u8* e = e2;
        top2:
            if (p == e) goto out2;
            e -= 408;
            ((W268VObj*)e)->vt[3]((W268VObj*)e);
            goto top2;
        out2:;
        }
        func_00106420(p);
        D_0035f634 = 0;
    }
    if (D_0035f630) {
        func_00106450(D_0035f630);
        D_0035f630 = 0;
    }
    func_002816f0();
}

struct W268Vm;
struct W268VmList { W268Vm* head; W268Vm* tail; };
struct W268Vm { u8 pad[0x1c]; u32 flags; u8 p20[8]; W268Vm* next; W268VmList kids; };
extern W268Vm* D_0034d8a4;
extern W268Vm* D_0034d8a0;
extern u8 D_0034dbf8[];
s32 func_001da558(W268Vm*, void*, s32, s32);
void func_0016ce90(W268Vm*);
void func_0016cab8(W268Vm*);
void func_0016c7d8(W268Vm*);
s32 func_0016cd48(W268Vm* vm, W268Vm* parent)
{
    if (!(vm->flags & 2)) {
        D_0034d8a4 = vm;
        D_0034d8a0 = parent ? parent : vm;
        s32 r = func_001da558(vm, D_0034dbf8, 0, 0);
        D_0034d8a4 = 0;
        D_0034d8a0 = 0;
        if (r != 1) func_0016ce90(vm);
    }
    W268Vm* c = vm->kids.head;
    while (c) {
        W268Vm* nx = c->next;
        if (func_0016cd48(c, vm) == 1) {
            W268VmList* l = &vm->kids;
            W268Vm* prev;
            if (c == l->head) {
                l->head = c->next;
                prev = 0;
            } else {
                prev = l->head;
                while (prev->next != c) prev = prev->next;
                prev->next = c->next;
            }
            if (c == l->tail) l->tail = prev;
            c->next = 0;
            if (c) {
                func_0016cab8(c);
                func_0016c7d8(c);
            }
        }
        c = nx;
    }
    if (vm->flags & 2) {
        if (vm->kids.head == 0) return 1;
    }
    return 0;
}

// VU0 macro code (sceVu0MulMatrix / sceVu0ApplyMatrix inlined) kept as inline asm.
struct W268Mtx { f32 m[16]; } __attribute__((aligned(16)));
struct W268V4 {
    f32 v[4];
    W268V4() {}
    W268V4(const W268V4& o) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
    }
    W268V4& operator=(const W268V4& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline void W268MulMtx(W268Mtx* d, const W268Mtx* a, const W268Mtx* b) {
    asm volatile(
        "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
        "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
        "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\t"
        "vmulax.xyzw ACC, $vf1, $vf6x\n\tvmadday.xyzw ACC, $vf2, $vf6y\n\tvmaddaz.xyzw ACC, $vf3, $vf6z\n\tvmaddw.xyzw $vf6, $vf4, $vf6w\n\t"
        "vmulax.xyzw ACC, $vf1, $vf7x\n\tvmadday.xyzw ACC, $vf2, $vf7y\n\tvmaddaz.xyzw ACC, $vf3, $vf7z\n\tvmaddw.xyzw $vf7, $vf4, $vf7w\n\t"
        "vmulax.xyzw ACC, $vf1, $vf8x\n\tvmadday.xyzw ACC, $vf2, $vf8y\n\tvmaddaz.xyzw ACC, $vf3, $vf8z\n\tvmaddw.xyzw $vf8, $vf4, $vf8w\n\t"
        "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)"
        : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline void W268Apply(W268V4* pr, const W268Mtx* m, const W268V4* v) {
    W268V4& r = *pr;
    asm volatile(
        "lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
        "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\t"
        "sqc2 $vf5, 0(%0)"
        : : "r"(&r), "r"(m), "r"(v) : "memory");
}
W268Mtx* func_00106a18(s32);  // buffer_get_256
u8* func_00106a60(s32);  // buffer_get_by_index
W268V4 func_0017cf00(const W268V4& in)
{
    W268V4 r(in);
    f32 one = 1.0f;
    r.v[3] = one;
    W268Mtx* a = func_00106a18(1);  // buffer_get_256
    u8* c = func_00106a60(1);  // buffer_get_by_index
    W268Mtx* b = c ? (W268Mtx*)(c + 16) : 0;
    W268V4 tmp;
    W268Mtx t;
    W268MulMtx(&t, a, b);
    W268Apply(&tmp, &t, &r);
    r = tmp;
    f32 s = one / r.v[3];
    r.v[3] = one;
    r.v[0] *= s;
    r.v[1] *= s;
    r.v[2] *= s;
    return r;
}

}
