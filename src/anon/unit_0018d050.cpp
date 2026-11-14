#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/menu_sound.hpp"

// 0018d050 (from src/anon/batch_w296.cpp)
namespace n0018d050 {
extern u8 D_0034ef18[] asm("D_0034ef18");
extern u8* D_0034e948 asm("D_0034e948");
s32 func_001bffd8(void) asm("func_001bffd8");
s32 func_001c0090(void) asm("func_001c0090");
u8* func_0019fe90(s32, s32) asm("func_0019fe90");
void func_001c0150(void*, s32) asm("func_001c0150");
void func_0018e0d8(void*, u32) asm("func_0018e0d8");
s32 func_001b5a10(void) asm("func_001b5a10");
struct W296Obj {
    void* vt;          
    u32 flags;         
    u8* p8;            
    u8* pc;            
    u8* p10;            
    s32 a14;            
    s32 a18;            
    s32 a1c;            
    s32 a20;            
    u8* p24;            
    u8* p28;            
    u8 pad2c[4];
    u8 sub30[0x54];
    s32 a84;
    u8* p88;
    s32 a8c;
    u8 pad90[8];
    s32 a98;
    u8 pad9c[8];
    u8 ba4;
    u8 pada5[0x1b];
    W296Obj* next;          
};
struct W296List { W296Obj* head; W296Obj* tail; };
extern W296List D_list asm("D_01c60cd8");
void func_0018d050(W296Obj* o, u8* a1, u8* a2, s32 a3, s32 a4, s32 a5, s32 a6) asm("func_0018d050");
void func_0018d050(W296Obj* o, u8* a1, u8* a2, s32 a3, s32 a4, s32 a5, s32 a6) {
    s32 v;
    *(volatile u32*)&o->flags = 0;
    o->p10 = a2;
    o->vt = D_0034ef18;
    o->p8 = a1;
    o->pc = a1;
    o->a14 = a3;
    o->a18 = a4;
    o->a1c = a5 >= 0 ? a5 : func_001bffd8();
    o->p24 = a1 ? a1 + 128 : 0;
    o->p28 = func_0019fe90(a3, a4);
    func_001c0150(o->sub30, 0);                           
    o->p88 = a1;
    o->a84 = 0;
    o->a8c = 0;
    o->a98 = 0;
    o->ba4 = 0;
    if (a5 >= 0) o->flags |= 0x400;
    if (o->p28[8] == 0 && o->pc != 0) {
        func_0018e0d8(o, *(u32*)(o->pc + 0x3b0));
    } else {
        if (o->p28[8] == 1) o->pc = D_0034e948;
        func_0018e0d8(o, o->p28[8]);
    }
    if (o->p28[0x12] & 2) {
        o->p24 = (u8*)func_001b5a10();
    } else if (o->p28[0x12] & 8) {
        o->p24 = (u8*)(*(s32*)(o->pc + 0x23c) + 128);
    }
    o->a20 = o->p28[0x2c] ? o->p28[0x2c] : (a6 >= 0 ? a6 : func_001c0090());
    if (o->p8) (*(s32*)(o->p8 + 0x488))++;
    if (o->p10) (*(s32*)(o->p10 + 0x488))++;
    if (D_list.tail == 0) {
        D_list.tail = o;
        D_list.head = o;
        o->next = 0;
    } else {
        D_list.tail->next = o;
        o->next = 0;
        D_list.tail = o;
    }
}
} // n0018d050

// 0018d238 (from src/anon/batch_w296.cpp)
namespace n0018d238 {
extern u8 D_0034ef18[] asm("D_0034ef18");
extern u8* D_0034e948 asm("D_0034e948");
s32 func_001bffd8(void) asm("func_001bffd8");
s32 func_001c0090(void) asm("func_001c0090");
u8* func_0019fe90(s32, s32) asm("func_0019fe90");
void func_001c0150(void*, s32) asm("func_001c0150");
void func_0018e0d8(void*, u32) asm("func_0018e0d8");
s32 func_001b5a10(void) asm("func_001b5a10");
struct W296Obj {
    void* vt;          
    u32 flags;         
    u8* p8;            
    u8* pc;            
    u8* p10;            
    s32 a14;            
    s32 a18;            
    s32 a1c;            
    s32 a20;            
    u8* p24;            
    u8* p28;            
    u8 pad2c[4];
    u8 sub30[0x54];
    s32 a84;
    u8* p88;
    s32 a8c;
    u8 pad90[8];
    s32 a98;
    u8 pad9c[8];
    u8 ba4;
    u8 pada5[0x1b];
    W296Obj* next;          
};
struct W296List { W296Obj* head; W296Obj* tail; };
extern W296List D_list asm("D_01c60cd8");
void func_0018d238(W296Obj* o, u8* a1, u8* a2, s32 a3, s32 a4, s32 a5, s32 a6) asm("func_0018d238");
void func_0018d238(W296Obj* o, u8* a1, u8* a2, s32 a3, s32 a4, s32 a5, s32 a6) {
    s32 v;
    *(volatile u32*)&o->flags = 0;
    o->p10 = a2;
    o->vt = D_0034ef18;
    o->p8 = a1;
    o->pc = a1;
    o->a14 = a3;
    o->a18 = a4;
    o->a1c = a5 >= 0 ? a5 : func_001bffd8();
    o->p24 = a1 ? a1 + 128 : 0;
    o->p28 = func_0019fe90(a3, a4);
    func_001c0150(o->sub30, 0);                           
    o->p88 = a1;
    o->a84 = 0;
    o->a8c = 0;
    o->a98 = 0;
    o->ba4 = 0;
    if (a5 >= 0) o->flags |= 0x400;
    if (o->p28[8] == 0 && o->pc != 0) {
        func_0018e0d8(o, *(u32*)(o->pc + 0x3b0));
    } else {
        if (o->p28[8] == 1) o->pc = D_0034e948;
        func_0018e0d8(o, o->p28[8]);
    }
    if (o->p28[0x12] & 2) {
        o->p24 = (u8*)func_001b5a10();
    } else if (o->p28[0x12] & 8) {
        o->p24 = (u8*)(*(s32*)(o->pc + 0x23c) + 128);
    }
    o->a20 = o->p28[0x2c] ? o->p28[0x2c] : (a6 >= 0 ? a6 : func_001c0090());
    if (o->p8) (*(s32*)(o->p8 + 0x488))++;
    if (o->p10) (*(s32*)(o->p10 + 0x488))++;
    if (D_list.tail == 0) {
        D_list.tail = o;
        D_list.head = o;
        o->next = 0;
    } else {
        D_list.tail->next = o;
        o->next = 0;
        D_list.tail = o;
    }
}
} // n0018d238

// 0018d420 (from src/anon/batch_w81.cpp)
namespace n0018d420 {
struct NoTail81 { ~NoTail81() {} };
struct Node18d { u32 vt; u32 flags; u8* a; u32 p; u8* b; u8 pad[8]; u32 h; u8 pad2[16]; u8 sub[144]; Node18d* next; };
struct List18d { Node18d* head; Node18d* tail; };
extern List18d D_01c60cd8 asm("D_01c60cd8");
extern u8 D_0034ef18[] asm("D_0034ef18");
void func_0018e040(Node18d*) asm("func_0018e040");
void func_001c0058(u32) asm("func_001c0058");
void func_001c0248(u8*) asm("func_001c0248");
void func_0018d420(Node18d* o) asm("func_0018d420");
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
        func_001c0058(o->h);                       
    }
    func_001c0248(o->sub);
}
} // n0018d420

// 0018d500 (never written before)
namespace n0018d500 {
extern u8 D_0034ef18 asm("D_0034ef18");
extern u8 D_01c60cd8 asm("D_01c60cd8");
void func_0031ee68(void*, u8*) asm("func_0031ee68");
void func_0018e040(u8*) asm("func_0018e040");
void func_001c0058(u32) asm("func_001c0058");
void func_001c0248(u8*) asm("func_001c0248");
void func_0018d500(u8* p) asm("func_0018d500");
struct NoTail { ~NoTail() {} };
void func_0018d500(u8* p) {
    NoTail nt;
    *(void**)p = &D_0034ef18;
    u8* o = *(u8**)(p + 8);
    if (o) (*(s32*)(o + 1160))--;
    o = *(u8**)(p + 16);
    if (o) (*(s32*)(o + 1160))--;
    func_0031ee68(&D_01c60cd8, p);
    if (!(*(u32*)(p + 4) & 0x400)) {
        func_0018e040(p);
        func_001c0058(*(u32*)(p + 28));
    }
    func_001c0248(p + 48);
}
} // n0018d500

// 0018d590 (from src/anon/batch_w65.cpp)
namespace n0018d590 {
void func_00105110(void*) asm("func_00105110");
extern u8 D_0034ef18[] asm("D_0034ef18");
extern u8 D_01c60cd8[] asm("D_01c60cd8");
void func_0031ee68(void*, void*) asm("func_0031ee68");
void func_0018e040(void*) asm("func_0018e040");
void func_001c0058(u32) asm("func_001c0058");
void func_001c0248(void*) asm("func_001c0248");
void func_0018d590(u32* p) asm("func_0018d590");
void func_0018d590(u32* p) {
    p[0] = (u32)D_0034ef18;
    if (p[2]) (*(s32*)(p[2] + 1160))--;
    if (p[4]) (*(s32*)(p[4] + 1160))--;
    func_0031ee68(D_01c60cd8, p);
    if (!(p[1] & 0x400)) {
        func_0018e040(p);
        func_001c0058(p[7]);                       
    }
    func_001c0248(p + 12);
    func_00105110(p);
}
} // n0018d590

// 0018d620 (from src/anon/batch_w1578_g.cpp)
namespace n0018d620 {
struct W1578Elem {
    u8 pad[0x1c];
    s32 x1c;
    u8 pad2[0x10];
    W1578Elem() { x1c = 0; }
    ~W1578Elem() {}
} __attribute__((aligned(16)));
void* W1578_AREA_Alloc(u32) asm("_ZN4AREA5AllocEj");
void W1578_AREA_Free(void*) asm("_ZN4AREA4FreeEPv");
struct W1578Cont {
    s32 n;
    W1578Elem e[256];
    W1578Cont() : n(0) {}
    ~W1578Cont() {}
    static void* operator new(unsigned int s) { return W1578_AREA_Alloc(s); }
    static void operator delete(void* p) { W1578_AREA_Free(p); }
};
struct W1578Obj {
    virtual ~W1578Obj();
    virtual void v2();
    virtual void v3();
    virtual void v4(W1578Cont*);
    u32 flags;
    u8 pad[0xc0 - 8];
    W1578Obj* next;
};
void func_001c2ba8(void) asm("func_001c2ba8");
void func_001c0560(void) asm("func_001c0560");
void func_001a4388(void) asm("func_001a4388");
void func_0018ed18(W1578Cont*) asm("func_0018ed18");
extern W1578Obj* D_01c60cd8 asm("D_01c60cd8");
void func_0018d620(void) asm("func_0018d620");
void func_0018d620(void) {
    func_001c2ba8();
    func_001c0560();
    func_001a4388();
    W1578Cont* c = new W1578Cont;
    W1578Obj* o = D_01c60cd8;
    while (o) {
        W1578Obj* nx = o->next;
        if (o->flags & 0x800) {
            delete o;
        } else {
            o->v4(c);
        }
        o = nx;
    }
    func_0018ed18(c);
    delete c;
}
} // n0018d620

// 0018d738 (from src/anon/batch_w24.cpp)
namespace n0018d738 {
struct W2 { u32 a; u32 b; };
void func_001bff88(void) asm("func_001bff88");
void func_001c2b70(void) asm("func_001c2b70");
void func_00102c18(s32, s32, void (*)(void)) asm("func_00102c18");
void func_0018d620(void) asm("func_0018d620");
extern W2 D_01c60cd8 asm("D_01c60cd8");
extern u8 D_01c60ce0 asm("D_01c60ce0");
void func_0018d738(void) asm("func_0018d738");
void func_0018d738(void) {
    func_001bff88();
    func_001c2b70();
    D_01c60cd8.a = 0;
    D_01c60cd8.b = 0;
    func_00102c18(1, 21000, func_0018d620);
    D_01c60ce0 = 1;
}
} // n0018d738

// 0018d790 (from src/anon/batch_w47.cpp)
namespace n0018d790 {
void u_call0_0018d790(void) asm("_Z16u_call0_0018d790v");
struct O18d { void** vt; u8 pad[188]; O18d* next; };
extern O18d* D_01c60cd8 asm("D_01c60cd8");
extern u8 D_01c60ce0 asm("D_01c60ce0");
static inline O18d* Next18d(O18d* n) { if (!n) return D_01c60cd8; return n->next; }
void u_call0_0018d790(void) {
    O18d* o = Next18d(0);
    O18d* it = o;
    while (o) {
        it = Next18d(it);
        if (o) ((void (*)(O18d*))o->vt[1])(o);
        o = it;
    }
    D_01c60ce0 = 0;
}
} // n0018d790

// 0018d808 (from src/anon/batch_w18.cpp)
namespace n0018d808 {
struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));
Vec4* func_0016c028(void*) asm("func_0016c028");
Vec4 func_0018d808(u8* b) asm("func_0018d808");
Vec4 func_0018d808(u8* b) {
    Vec4 r;
    Vec4* s = func_0016c028(*(void**)(b + 8));                          
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&r), "r"(s) : "$8", "memory");
    return r;
}
} // n0018d808

// 0018d840 (from src/anon/batch_w79.cpp)
namespace n0018d840 {
typedef unsigned int u128 __attribute__((mode(TI)));
struct Q16 {
    u128 v;
    Q16() {}
    Q16(const Q16& o) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
    }
    Q16& operator=(const Q16& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
};
Q16* func_0016c028(void*) asm("func_0016c028");
void func_0016af58(Q16*, void*) asm("func_0016af58");
static inline void vu0_scaled(Q16& r, const Q16& v, f32 s) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\t"
                 "vmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&v), "f"(s) : "$8", "memory");
}
static inline void vu0_sub(Q16& r, const Q16& a, const Q16& b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
}
static inline void vu0_normalize_f1(Q16& v) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\t"
                 "vaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\t"
                 "vaddq.x $vf2, $vf0, Q\n\tmtc1 $8, $f1\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\t"
                 "vmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&v) : "$8", "$f1", "memory");
}
Q16* func_0018d840(Q16* out, u8* o, void* a) asm("func_0018d840");
Q16* func_0018d840(Q16* out, u8* o, void* a) {
    if (*(u8**)(o + 12) != 0) {
        Q16 d;
        vu0_sub(d, *func_0016c028(a), *(Q16*)(*(u8**)(o + 12) + 1840));                          
        *out = d;
        ((s32*)out)[1] = 0;
        vu0_normalize_f1(*out);
        ((f32*)out)[3] = 1.0f;
    } else {
        Q16 d;
        Q16 t;
        func_0016af58(&t, a);
        vu0_scaled(d, t, -1.0f);
        *out = d;
    }
    return out;
}
} // n0018d840

// 0018d940 (from src/anon/batch_w243.cpp)
namespace n0018d940 {
struct w243_T { u8 pad[4]; u8 kind; };
struct w243_B { u8 pad[0x3b0]; u32 idx; };
struct w243_A { u8 pad[0xc]; w243_B* c; w243_B* d; u8 pad2[0x14]; w243_T* t; u8 pad3; u8 m; };
s32 func_001af9e8(w243_A*, w243_B*) asm("func_001af9e8");
s32 func_001c0268(void*, w243_A*) asm("func_001c0268");
s32 func_0019bb58(w243_B*) asm("func_0019bb58");
s32 func_0019ba60(w243_B*) asm("func_0019ba60");
s32 func_0019c6f0(w243_B*) asm("func_0019c6f0");
static inline bool w243_kind(w243_A* a) { return (u8)(a->t->kind - 5) < 2; }
s32 w243_ctarget(w243_A* a, w243_B* b) asm("_Z16ctarget_0018d940jjjj");
s32 w243_ctarget(w243_A* a, w243_B* b) {
    if (func_001af9e8(a, b)) return 0;
    if (!func_001c0268((u8*)b + 0xa50, a)) return 0;
    if (w243_kind(a)) return 1;
    if (!func_0019bb58(b)) return 0;
    if (a->c == b || a->d == b) return 0;
    if (((a->m >> b->idx) & 1) == 0) return 0;
    if (func_0019ba60(a->c) && func_0019c6f0(a->c)) return 0;
    return 1;
}
} // n0018d940

// 0018da18 (from src/anon/batch_w98.cpp)
namespace n0018da18 {
static inline u32 ActFlags18d(u8* a) {
    u32* f = (u32*)(a + 2748);
    return (f[0] | f[1]) & ~f[2];
}
u8* func_0018c8f0(u8*, u8*, u8*) asm("func_0018c8f0");
void func_00198580(u8*, s32) asm("func_00198580");
s32 func_001de2e0(u32*, u64) asm("func_001de2e0");
void func_001877a0(u8*, u32*, s32) asm("func_001877a0");
u8* func_0018da18(u8* o, u8* act, u8* info) asm("func_0018da18");
u8* func_0018da18(u8* o, u8* act, u8* info) {
    u8* r = func_0018c8f0(o, info, act);
    if (*(u8**)(o + 12)) *(u32*)(*(u8**)(o + 12) + 264) |= 0x2000000;
    *(u32*)(o + 4) |= 2;
    if (*(u32*)(r + 24) & 4) return r;
    if (ActFlags18d(act) & 0x2000) return r;
    if (*(s32*)(info + 28) >= 0) func_00198580(*(u8**)(o + 16), *(s32*)(info + 28));                      
    u32* e = *(u32**)(o + 36);
    if (!e) return r;
    if (!*e) return r;
    u8 n = info[11];
    if (!n) return r;
    u64 bit = (u64)1 << 32 << (n - 1);
    s32 k = func_001de2e0(e, (*(u32*)(act + 1416) & 0x80) ? bit | 0x400 : bit | 0x800);
    if (k >= 0) func_001877a0(act, *(u32**)(o + 36), k);
    return r;
}
} // n0018da18

// 0018db38 (from src/anon/batch_w60.cpp)
namespace n0018db38 {
s32 func_0018d940(void*, void*, s32, void*) asm("func_0018d940");
void* func_001c0320(void*, void*, void*) asm("func_001c0320");
u8* func_0018da18(void*, void*, void*, void*) asm("func_0018da18");
u8* func_0018db38(void* a, u8* b, s32 c, void* d) asm("func_0018db38");
u8* func_0018db38(void* a, u8* b, s32 c, void* d) {
    u8 flag[16];
    if (!func_0018d940(a, b, c, d)) return 0;
    u8* r = func_0018da18(a, b, func_001c0320(b + 2640, a, flag), d);
    r[36] = c;
    if (!flag[0]) *(u32*)(r + 24) |= 3;
    return r;
}
} // n0018db38

// 0018dbd8 (from src/anon/batch_w2363.cpp)
namespace YS {
struct ATTACK {
    u32 pad;
    u32 flags;
    bool hit_flag() const { u32 m = flags & 8; return m || (flags & 0x10); }
    bool is_hit();
};
bool ATTACK::is_hit() { return (flags & 2) || hit_flag() || (flags & 0x200); }
}

// 0018dc28 (from src/anon/batch_w1337.cpp)
namespace n0018dc28 {
#define QCOPY1337(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV1337 {
    f32 x, y, z, w;
    QV1337() {}
    QV1337(const QV1337& o) { QCOPY1337(this, &o); }
    QV1337& operator=(const QV1337& o) { if (this != &o) QCOPY1337(this, &o); return *this; }
} __attribute__((aligned(16)));
struct Seg1337 {
    QV1337 p0, p1;
    void set(const QV1337& a, const QV1337& b) { p0 = a; p1 = b; p1.w = 1.0f; p0.w = 1.0f; }
};
struct Hit1337 { u8 pad[16]; };
struct CollInfo1337 { u8 pad[0x12]; u8 enable : 1; u8 : 7; u8 pad13[0x15]; u8 height28; };
struct Obj1337 {
    u32 pad0;
    union { struct { u32 b0 : 1, b1 : 1, b2 : 1, b3 : 1, b4 : 1, b5 : 3, b8 : 1, : 23; }; u32 flags; };
    u8 pad8[0x20];
    CollInfo1337* coll;
    bool isB3() { if (flags & 8) return true; return false; }
    bool isB4() { if (flags & 0x10) return true; return false; }
    bool isB1() { if (flags & 2) return true; return false; }
    bool isBusy() { return isB3() || isB4(); }
};
s32 func_00143b88(Seg1337*, Hit1337*, u16*, s32*, s32) asm("func_00143b88");
void func_0018ddc0(Obj1337*, u16, Hit1337*, s32*) asm("func_0018ddc0");
s32 func_0018dc28(Obj1337* self, const QV1337* from, const QV1337* to) asm("func_0018dc28");
s32 func_0018dc28(Obj1337* self, const QV1337* from, const QV1337* to) {
    Seg1337 seg;
    u16 id;
    Hit1337 hit;
    s32 res;
    seg.set(*from, *to);
    res = 0;
    asm volatile("" ::: "memory");
    if (self->coll->enable && !self->isBusy() && (self->b8 || !self->isB1())) {
        if (func_00143b88(&seg, &hit, &id, &res, 4) != 0) {
            goto found;
        }
        if (self->coll->height28 != 0) {
            seg.p0 = *to;
            seg.p1 = *to;
            seg.p1.y += (f32)self->coll->height28;
            seg.p1.w = 1.0f;
            seg.p0.w = 1.0f;
            if (func_00143b88(&seg, &hit, &id, &res, 4) != 0) {
            found:
                func_0018ddc0(self, id, &hit, &res);
                return 1;
            }
        }
    }
    return 0;
}
} // n0018dc28

// 0018ddc0 (from src/anon/batch_w1962.cpp)
namespace n0018ddc0 {
struct W1962QVb {
    f32 x, y, z, w;
    W1962QVb& operator=(const W1962QVb& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
struct W1962OcF;
struct W1962Tri { u32 a; W1962OcF* f; };
struct W1962Hit { W1962Tri* t; };
struct W1962Cnt { u32 n; };
struct W1962Inf { u8 p[11]; u8 lv; };
struct W1962Pl { u8 p[0x588]; u32 fl; };
struct W1962Ob;
typedef void (*W1962VF)(void*, W1962Ob*);
struct W1962Hd { W1962VF* vt; };
struct W1962Ob { u32 f0; u32 fl; u32 f8; W1962Hd* hd; W1962Pl* pl; u8 p14[0x10]; W1962Cnt* cnt; W1962Inf* inf; u8 p2c[0x84]; W1962QVb pos; };
W1962QVb oc_get_normal(u16, bool) asm("_ZN2dk6Octree9getNormalEtb");
s32 oc_get_attr_kind(u16, bool) asm("_ZN2dk6Octree11getAttrKindEtb");
u32* ocf_get_attr(W1962OcF*, u16) asm("_ZN2dk11OctCollFile7getAttrEt");
W1962QVb* w1962_effect_angle(void*) asm("_ZN3ryj6EFFECT5angleEv");
W1962QVb func_001422a0(W1962OcF*, u16) asm("func_001422a0");
void* func_001a3b48(W1962Cnt*, u64, W1962QVb*, s32, s32, s32) asm("func_001a3b48");
W1962QVb func_0017d050(const W1962QVb&) asm("func_0017d050");
void func_001c2c00(void*) asm("func_001c2c00");
void func_00198580(W1962Pl*, s32) asm("func_00198580");
void func_0018ddc0(W1962Ob* o, u16 id, W1962QVb* pos, W1962Hit* h) asm("func_0018ddc0");
void func_0018ddc0(W1962Ob* o, u16 id, W1962QVb* pos, W1962Hit* h) {
    W1962QVb n;
    s32 kind;
    if (h->t == 0) {
        n = oc_get_normal(id, 0);
        kind = oc_get_attr_kind(id, 0);
    } else {
        n = func_001422a0(h->t->f, id);
        kind = *ocf_get_attr(h->t->f, id) & 0xf;
    }
    u64 t;
    if (kind == 1) { o->fl |= 0x10; t = 0x100; }
    else { o->fl |= 8; t = 2; }
    o->pos = *pos;
    if (o->cnt->n != 0) {
        u8 lv = o->inf->lv;
        if (lv != 0) {
            t |= (1ULL << 32) << (lv - 1);
            void* e = func_001a3b48(o->cnt, t, pos, 1, 1, 10000);
            if (e != 0) {
                *w1962_effect_angle(e) = func_0017d050(n);
                func_001c2c00(e);
            }
        }
    }
    if (o->pl->fl & 0x40) func_00198580(o->pl, 0x7a12a);
    if (!(o->fl & 0x100)) o->hd->vt[28](o->hd, o);
}
} // n0018ddc0

// 0018df90 (from src/anon/batch_wcx.cpp)
namespace n0018df90 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline void VCopyChk(V4* d, V4* s)
{
    if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
static inline f32 VNormalize(V4* d, V4* s)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%2)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(d), "r"(s) : "$8", "memory");
    return r;
}
static inline void VSub(V4* d, V4* a, V4* b)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
typedef void (*PosFn)(V4*, u8*);
V4* func_0018df90(V4* out, u8* p, u8* o) asm("func_0018df90");
V4* func_0018df90(V4* out, u8* p, u8* o)
{
    V4 d, a;
    u8* q = *(u8**)(p + 12) + 1840;
    (*(PosFn*)(*(u8**)o + 8))(&a, o);
    VSub(&d, (V4*)q, &a);
    VCopyChk(out, &d);
    *(u32*)&out->y = 0;
    VNormalize(out, out);
    return out;
}
} // n0018df90

// 0018e040 (from src/anon/batch_w1774.cpp)
namespace n0018e040 {
struct W1774Node { u8 pad[0x30]; u8 sub[0x90]; W1774Node* next; };
extern W1774Node* D_01c60cd8 asm("D_01c60cd8");
u8* func_00186078(u8*) asm("func_00186078");
void func_001c0458(void*, s32) asm("func_001c0458");
static inline W1774Node* w1774_next(W1774Node* q) { if (!q) return D_01c60cd8; return q->next; }
void func_0018e040(s32 a0) asm("func_0018e040");
void func_0018e040(s32 a0) {
    u8* p = 0;
    while ((p = func_00186078(p)) != 0) {
        func_001c0458(p + 0xa50, a0);
        if (*(s32*)(p + 0xaac) == a0) *(s32*)(p + 0xaac) = 0;
    }
    W1774Node* q = 0;
    while ((q = w1774_next(q)) != 0) func_001c0458(q->sub, a0);
}
} // n0018e040

// 0018e0d8 (from src/anon/batch_w2361.cpp)
namespace n0018e0d8 {
struct W2361Mode { u8 pad[44]; u8 mode; u8 mask; };
void func_0018e0d8(W2361Mode* p, s32 mode) asm("func_0018e0d8");
void func_0018e0d8(W2361Mode* p, s32 mode) {
    p->mode = (mode == 3) ? (u8)4 : (u8)mode;
    p->mask = ~((1 << p->mode) | 1);
}
} // n0018e0d8

// 0018e108 (from src/anon/batch_w20.cpp)
namespace n0018e108 {
struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
extern Q16 D_0034eef0 asm("D_0034eef0");
extern Q16 D_0034ef00 asm("D_0034ef00");
void func_0018e108(Q16* a, Q16* b) asm("func_0018e108");
void func_0018e108(Q16* a, Q16* b) {
    if (a != &D_0034eef0) QCOPY(&D_0034eef0, a);
    if (b != &D_0034ef00) QCOPY(&D_0034ef00, b);
}
} // n0018e108

// 0018e140 (from src/anon/tiny_auto80_fptr4.cpp)
namespace n0018e140 {
u32 func_0018ca90(u32, u32, u32, u32) asm("func_0018ca90");
u32 func_0018e140(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0018e140");
u32 func_0018e140(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = *(u32*)((u32)r4 + (s32)(40));
    r4 = (u32)(*(u8*)((u32)r15 + (s32)(10)));
    u32 (*fp_call4_0018ca90)(u32, u32, u32, u32) = func_0018ca90;
    r2 = fp_call4_0018ca90(r4, r5, r6, r7);
    return r2;
}
} // n0018e140

// 0018e160 (from src/anon/batch_w93.cpp)
namespace n0018e160 {
struct W93V { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline __attribute__((always_inline)) void W93Set(W93V* d, const W93V* s)
{
    if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
struct W93Vec { W93V v; W93Vec& operator=(const W93Vec& o) { W93Set(&v, &o.v); return *this; } };
static inline __attribute__((always_inline)) W93Vec operator-(const W93Vec& a, const W93Vec& b)
{ W93Vec r; asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory"); return r; }
static inline __attribute__((always_inline)) W93Vec operator+(const W93Vec& a, const W93Vec& b)
{ W93Vec r; asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory"); return r; }
static inline __attribute__((always_inline)) W93Vec operator*(const W93Vec& a, f32 k)
{ W93Vec r; asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory"); return r; }
struct W93Orb { u8 pad[4]; f32 dist; f32 radius; u8 p2[4]; W93V center; };
struct W93Pos { u8 pad[32]; W93V pos; };
f32 fabsf(f32) asm("fabsf");
W93V func_0018e160(const W93Pos* p, const W93Orb* o) asm("func_0018e160");
W93V func_0018e160(const W93Pos* p, const W93Orb* o)
{
    W93V d;
    W93V tmp;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&tmp), "r"(&p->pos), "r"(&o->center) : "memory");
    W93Set(&d, &tmp);
    f32 r = o->radius;
    f32 y;
    if (d.y < -r) y = -r;
    else if (r < d.y) y = r;
    else y = d.y;
    f32 c = fabsf(y / r);          
    f32 s = __builtin_sqrtf(1.0f - c * c);
    d.y = 0;
    asm volatile("lqc2 $vf1, 0(%0)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\t"
                 "vsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, $f2\n\tvnop\n\t"
                 "vdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&d) : "$8", "$f2", "memory");
    f32 k = o->dist * s;
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&d), "f"(k) : "$8", "memory");
    d.y = y;
    W93V out;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&out), "r"(&o->center), "r"(&d) : "memory");
    return out;
}
} // n0018e160

// 0018e298 (from src/anon/batch_w280.cpp)
namespace n0018e298 {
#define F(p,o,T) (*(T*)((u8*)(p)+(o)))
typedef s32 (*VF)(...);
typedef void (*VV)(...);
#define VT(o,i) ((VF)((*(void***)(o))[i]))
#define VTv(o,i) ((VV)((*(void***)(o))[i]))
s32 func_001c0298(void*, void*) asm("func_001c0298");
void* func_0018db38(void*, void*, u32, u32) asm("func_0018db38");
void func_0018e420(void*, void*, void*, void*, s32) asm("func_0018e420");
void func_0018ef68(void*, void*, s32) asm("func_0018ef68");
void func_0018ca10(void*) asm("func_0018ca10");
void func_0018e298(void** a0, void* a1, void* a2) asm("func_0018e298");
void func_0018e298(void** a0, void* a1, void* a2)
{
    s32 mode;
    if (VT(a1, 24)(a1) != 0 || func_001c0298((u8*)a1 + 2640, *a0) == 0) {                    
        mode = 4;
    } else {
        mode = 1;
        F(*a0, 4, u32) |= 0x1000;
    }
    u8* t = F(a2, 12, u8*);
    void* r = func_0018db38(*a0, a1, *(u16*)(t + 2), t[1]);
    u32* f = (u32*)((u8*)a1 + 2748);
    if (!((f[0] | f[1]) & ~f[2] & 0x2000))
        func_0018e420(a0, a1, r, a2, mode);
    {
        void* c = *a0;
        void* o = F(c, 136, void*);
        VTv(o, 29)(o, a1, c, F(r, 32, void*));
    }
    if (F(*a0, 140, void*)) {
        struct { void* a; void* b; void* c; } st;
        st.a = F(*a0, 148, void*);
        st.b = a1;
        st.c = *a0;
        func_0018ef68((u8*)*a0 + 140, &st, 3);
    }
    F(*a0, 4, u32) &= ~0x1000;
    asm volatile("" ::: "memory");
    u8 x = F(F(*a0, 40, u8*), 47, u8);
    if (x) {
        void* o = F(*a0, 12, void*);
        VT(o, 30)(o, x, 0, 0);
    }
    VTv(a1, 25)(a1, r);
    func_0018ca10(r);                          
}
} // n0018e298

// 0018e420 (from src/anon/batch_w2049.cpp)
namespace n0018e420 {
struct W2049Q {
    union { struct { f32 x, y, z, w; }; u8 b[16]; };
    W2049Q() {}
    W2049Q(const W2049Q& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W2049Q& operator=(const W2049Q& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W2049Fx { u8 pad0[11]; u8 count; u8 pad0c[0x24 - 0xc]; u8 slot; u8 pad25[0x2d - 0x25]; u8 spread; };
struct W2049Hit { u8 pad0[0x18]; u32 flags; u8 pad1c[4]; W2049Fx* fx; };
struct W2049List { u32 n; };
struct W2049Ctx { u8 pad0[0x24]; W2049List* list; };
extern W2049Q D_0034eef0 asm("D_0034eef0");
extern s32 D_003638d0 asm("D_003638d0");
W2049Q func_0018e160(W2049Ctx**, void*) asm("func_0018e160");
void func_0018e108(W2049Q*, W2049Hit*) asm("func_0018e108");
s32 func_001a3b48(void*, u64, W2049Q*, s32, s32, s32) asm("func_001a3b48");
void* func_001a3a78(void) asm("func_001a3a78");
s32 func_001de168(void*, s32, s32, s32, s32, s32) asm("func_001de168");
W2049Q* func_001dc5f8(s32) asm("func_001dc5f8");
W2049Q* func_001dc648(s32) asm("func_001dc648");
void func_0017d050(W2049Q*, W2049Hit*) asm("func_0017d050");
void func_001c2c00(s32) asm("func_001c2c00");
u64 func_00312db8(u64, u64) asm("func_00312db8");
void func_0018e420(W2049Ctx** ctx, u8* obj, W2049Hit* hit, void* src, u64 mask) asm("func_0018e420");
void func_0018e420(W2049Ctx** ctx, u8* obj, W2049Hit* hit, void* src, u64 mask)
{
    W2049Fx* fx = hit->fx;
    {
    W2049Q v = func_0018e160(ctx, src);
    func_0018e108(&v, hit);
    if ((*ctx)->list->n) {
        s32 n = fx->count;
        if (__builtin_expect(n != 0, 1)) {
            s32 id;
            if (hit->flags & 4) {
                id = func_001de168(func_001a3a78(), 18, 1, 1, 10000, 0);
                *func_001dc5f8(id) = D_0034eef0;
            } else {
                u32 k = fx->spread;
                if (k) {
                    s32 seed = D_003638d0 * 0x10dcd;
                    u64 bit = 0x100000000ULL;
                    s32 sh = n - 1;
                    D_003638d0 = seed;
                    sh += (s32)func_00312db8((u32)seed, func_00312db8((u64)(k - 1) + bit, (u64)k));
                    bit <<= sh;
                    mask |= bit;
                } else {
                    mask |= 0x100000000ULL << (n - 1);
                }
                id = func_001a3b48((*ctx)->list, mask, &D_0034eef0, 1, 1, 10000);
            }
            if (id) {
                W2049Q* m = func_001dc648(id);
                func_0017d050(&v, hit);
                *m = v;
                func_001c2c00(id);
            }
        }
    }
    }
    u32* lst = (u32*)(obj + 0x80);
    if (*lst && fx->slot && !(*(u32*)(obj + 0x108) & 0x200) && !(hit->flags & 4)) {
        W2049Q v = D_0034eef0;
        v.y -= 1.0f;
        mask = (0x100000000ULL << (fx->slot - 1)) | 0x200;
        func_001a3b48(lst, mask, &v, 1, 1, 10000);
    }
}
} // n0018e420

// 0018e698 (from src/anon/batch_w260.cpp)
namespace n0018e698 {
struct W260V {
    f32 x, y, z, w;
    W260V() {}
    W260V(const W260V& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W260V& operator=(const W260V& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
static inline __attribute__((always_inline)) f32 W260Dot(const W260V& a, const W260V& b)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(&a), "r"(&b) : "$8", "memory");
    return r;
}
struct W260Lim { u8 pad[34]; u8 b34; s8 b35; };
struct W260Own { u8 pad[12]; int f12; u8 pad2[24]; W260Lim* p40; };
struct W260Tgt;
struct W260TgtVT { void* p[3]; W260V (*f12)(W260Tgt*, int); };
struct W260Tgt { W260TgtVT* vt; };
struct W260Ctl { W260Own* own; };
f32 cosf(f32) asm("cosf");
W260V func_0016af58(int) asm("func_0016af58");
W260V func_0017d538(const W260V&, f32) asm("func_0017d538");
int func_0018e698(W260Ctl* c, W260Tgt** t) asm("func_0018e698");
int func_0018e698(W260Ctl* c, W260Tgt** t)
{
    u8 b = c->own->p40->b34;
    if (!b) return 1;
    f32 lim = -cosf((f32)b * 0.017453292f);
    W260V d;
    d = func_0016af58(c->own->f12);
    s8 e = c->own->p40->b35;
    if (e) d = func_0017d538(d, (f32)(e * 2) * 0.017453292f);
    W260V w = (*t)->vt->f12(*t, c->own->f12);
    return W260Dot(w, d) < lim;
}
} // n0018e698

// 0018e7c0 (from src/anon/batch_w2385_nsa.cpp)
namespace n0018e7c0 {
struct W1833Info { u8 pad[0x13]; u8 kind; };
struct W1833Obj;
struct W1833Vt;
struct W1833Sub { W1833Vt* vt; };
struct W1833Vt { void* pad[27]; void (*fn)(W1833Sub*, W1833Obj**, struct W1833B**); };
struct W1833Obj {
    u8 pad0[4]; u32 flags; u8 pad8[4]; W1833Sub* sub; u8 pad10[0x18]; W1833Info* info;
    u8 pad2c[4]; u8 a30[0x54]; s32 v84; u8 pad88[0x10]; s32 v98; u8 pad9c[4]; s32 va0; u8 cnt;
};
struct W1833B { u8 pad[0xc]; s32 vc; u8 pad10[0x18]; W1833Info* info; };
struct W1833Arg { s32 a; W1833Obj* o; W1833B* b; };
s32 func_0018f010(W1833B*) asm("func_0018f010");
void func_001c0320(void*, W1833B*, void*) asm("func_001c0320");
void func_0018ef68(void*, W1833Arg*, s32) asm("func_0018ef68");
void func_0018e7c0(W1833Obj** pp, W1833B** pb) asm("func_0018e7c0");
void func_0018e7c0(W1833Obj** pp, W1833B** pb) {
    u8 buf[16];
    (*pp)->cnt++;
    if (func_0018f010(*pb) == 0 || (*pb)->info->kind != 2) {
        func_001c0320((*pp)->a30, *pb, buf);
        if (!((*pp)->flags & 0x100)) {
            func_001c0320((u8*)(*pp)->sub + 0xa50, *pb, buf);
        }
    }
    if ((*pp)->info->kind != 2) {
        (*pp)->flags |= 0x200;
        (*pp)->v84 = (*pb)->vc;
    }
    if (!((*pp)->flags & 0x100)) {
        W1833Sub* s = (*pp)->sub;
        s->vt->fn(s, pp, pb);
    }
    s32* q = &(*pp)->v98;
    if (*q != 0) {
        W1833B* vb = *pb;
        W1833Arg a;
        a.a = (*pp)->va0;
        a.o = *pp;
        a.b = vb;
        func_0018ef68(q, &a, 3);
    }
}
} // n0018e7c0

// 0018e8f0 (from src/anon/batch_w93.cpp)
namespace n0018e8f0 {
struct W93V { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline __attribute__((always_inline)) void W93Set(W93V* d, const W93V* s)
{
    if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
struct W93Vec { W93V v; W93Vec& operator=(const W93Vec& o) { W93Set(&v, &o.v); return *this; } };
static inline __attribute__((always_inline)) W93Vec operator-(const W93Vec& a, const W93Vec& b)
{ W93Vec r; asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory"); return r; }
static inline __attribute__((always_inline)) W93Vec operator+(const W93Vec& a, const W93Vec& b)
{ W93Vec r; asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory"); return r; }
static inline __attribute__((always_inline)) W93Vec operator*(const W93Vec& a, f32 k)
{ W93Vec r; asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory"); return r; }
static inline __attribute__((always_inline)) void W93Normalize(W93Vec* v)
{
    asm volatile("lqc2 $vf1, 0(%0)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\t"
                 "vsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, $f0\n\tvnop\n\t"
                 "vdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(v) : "$8", "$f0", "memory");
}
struct W93Hdr { u32 p0; u32 flags; };
struct W93Act { W93Hdr* h; u8 pad[16]; f32 f20; u8 p2[8]; W93Vec pos; };
void* func_001de168(u32, u32, s32, s32, s32, s32) asm("func_001de168");
W93Vec* func_001dc5f8(void*) asm("func_001dc5f8");
void func_001c2c00(void*) asm("func_001c2c00");
void func_0018efe8(W93Hdr*) asm("func_0018efe8");
void func_0018e8f0(W93Act* a, u32 x, u32 y, W93Act* b) asm("func_0018e8f0");
void func_0018e8f0(W93Act* a, u32 x, u32 y, W93Act* b)
{
    if (a->h->flags & 0x80) return;
    if (b->h->flags & 0x80) return;
    void* r = func_001de168(x, y, 1, 1, 10000, 0);                      
    if (r) {
        W93Vec d;
        d = b->pos - a->pos;
        W93Normalize(&d);
        *func_001dc5f8(r) = a->pos + d * a->f20;
        func_001c2c00(r);
    }
    func_0018efe8(a->h);
    func_0018efe8(b->h);
}
} // n0018e8f0

// 0018ea40 (from src/anon/auto80_199_queue.cpp)
namespace n0018ea40 {
void func_0018ea40(u32 a0, u32 a1) asm("func_0018ea40");
void func_0018ea40(u32 a0, u32 a1) {
    u32 o0 = *(u32*)a0;
    if ((*(u32*)(o0 + 4) & 0x80) != 0) {
        return;
    }

    u32 o1 = *(u32*)a1;
    if ((*(u32*)(o1 + 4) & 0x80) != 0) {
        return;
    }

    u32 p = *(u32*)(o0 + 36);
    if (*(u32*)p == 0) {
        return;
    }

    u32 q = *(u32*)(o0 + 40);
    u32 idx = (u32)*(u8*)(q + 11);
    if (idx == 0) {
        return;
    }

    u64 mask = 1;
    mask <<= 32;
    mask <<= (idx - 1);
    mask |= 0x10;
    s32 r = func_001de2e0(p, mask);
    if (r < 0) {
        return;
    }

    func_0018e8f0(a0, *(u32*)(*(u32*)a0 + 36), (u32)r, a1);
}
} // n0018ea40

// 0018eaf8 (from src/anon/batch_w1775_nsa.cpp)
namespace n0018eaf8 {
typedef unsigned int u128 __attribute__((mode(TI)));
struct W1775Q { u128 q; W1775Q& operator=(const W1775Q& o) { if (this != &o) asm volatile("lq $8,0(%1)\n\tsq $8,0(%0)" :: "r"(this), "r"(&o) : "$8", "memory"); return *this; } } __attribute__((aligned(16)));
struct W1775B { s32 a; f32 y; f32 z; s32 w; W1775B& operator=(const W1775B& o) { a = o.a; y = o.y; z = o.z; w = o.w; return *this; } } __attribute__((aligned(16)));
struct W1775Ent { s32 id; W1775B b; W1775Q v; };
struct W1775List { s32 n; u8 pad[0xc]; W1775Ent e[256]; };
void func_0018eb98(W1775List*, W1775Ent*) asm("func_0018eb98");
s32 func_0018eaf8(W1775List* l, W1775Ent* e) asm("func_0018eaf8");
s32 func_0018eaf8(W1775List* l, W1775Ent* e) {
    func_0018eb98(l, e);
    if (l->n >= 256) return 0;
    l->e[l->n++] = *e;
    return 1;
}
} // n0018eaf8

// 0018eb98 (from src/anon/batch_wcx2.cpp)
namespace n0018eb98 {
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
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
struct Kind9 { u8 pad[4]; u8 k; };
struct Obj9 { u8 pad[12]; u8* owner; u8 pad2[24]; Kind9* kind; u8 team; };
struct Ent9 { Obj9* obj; u8 pad[12]; u8 sub[32]; };
struct List9 { s32 n; u8 pad[12]; Ent9 e[1]; };
extern u8 D_0036cce0[][7] asm("D_0036cce0");
s32 func_001c0298(u8*, Obj9*) asm("func_001c0298");
s32 func_0018a550(u8*, u8*) asm("func_0018a550");
s32 func_0018e698(Ent9*, Ent9*) asm("func_0018e698");
void func_0018ea40(Ent9*, Ent9*) asm("func_0018ea40");
void func_0018e7c0(Ent9*, Ent9*) asm("func_0018e7c0");
void func_0018eb98(List9* l, Ent9* q) asm("func_0018eb98");
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
} // n0018eb98

// 0018ed18 (from src/anon/batch_w81.cpp)
namespace n0018ed18 {
struct Ent18e { u8* obj; u8 pad[12]; u8 x[32]; };
struct List18e { s32 n; u8 pad[12]; Ent18e e[1]; };
u8* func_00186078(u8*) asm("func_00186078");
s32 func_0019bb58(u8*) asm("func_0019bb58");
s32 func_0018d940(u8*, u8*) asm("func_0018d940");
s32 func_0018f010(u8*) asm("func_0018f010");
u32 func_001b7998(u32, u8*) asm("func_001b7998");
void func_0018e298(Ent18e*, u8*, u32) asm("func_0018e298");
void func_0018ed18(List18e* l) asm("func_0018ed18");
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
} // n0018ed18

// 0018ee10 (from src/anon/tiny_auto80_queue.cpp)
namespace n0018ee10 {
u32 func_0018ee10(u32 a0) asm("func_0018ee10");
u32 func_0018ee10(u32 a0) {                       
    if (a0 == 0u) {
        u32 t7 = (u32)(0x01c6u << 16);
        return *(u32*)((u32)t7 + (s32)(3288));
    }
    return *(u32*)((u32)a0 + (s32)(192));
}
} // n0018ee10

// 0018ee28 (from src/anon/tiny_auto80_queue.cpp)
namespace n0018ee28 {
u32 func_0018ee28(u32 a0) asm("func_0018ee28");
u32 func_0018ee28(u32 a0) {
    u32 t7 = (u32)(0x01c6u << 16);
    u32 t6 = *(u32*)((u32)t7 + (s32)(3288));
L0:
    u32 v0 = t6;
    if (a0 != 0u) {
        v0 = *(u32*)((u32)a0 + (s32)(192));
    }
    if ((a0 = v0) == 0u) goto L2;
    {
        u32 t7b = *(u32*)((u32)a0 + (s32)(4));
        t7b = (u32)(t7b & 0x100u);
        if (t7b == 0u) goto L0;
    }
L2:
    return v0;
}
} // n0018ee28

// 0018ee60 (from src/anon/batch_w86.cpp)
namespace n0018ee60 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    u32 v[4];
    QWord() {}
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct Res { QWord q; u8 p16[8]; u32 f24; };
struct Tgt;
typedef void (*TFn)(Tgt*, Res*);
struct Tgt { TFn* vt; };
struct Q { u8 p0[40]; s32 f40; };
Q* func_001050d8(s32) asm("func_001050d8");
void func_0018d238(Q*, s32, s32, s32, s32, s32, s32) asm("func_0018d238");
Res* func_0018da18(Q*, Tgt*, s32, s32) asm("func_0018da18");
Res* func_0018db38(Q*, Tgt*, s32, s32) asm("func_0018db38");
void func_0018ca10(Res*) asm("func_0018ca10");
void func_0018f028(Q*) asm("func_0018f028");
s32 func_0018ee60(s32 a, s32 b, Tgt* t, QWord* v, u8 flag) asm("func_0018ee60");
s32 func_0018ee60(s32 a, s32 b, Tgt* t, QWord* v, u8 flag)
{
    s32 r = 0;
    Q* q = func_001050d8(208);
    func_0018d238(q, a, 0, b, 0, -1, -1);
    Res* res;
    if (flag) res = func_0018da18(q, t, q->f40, 0);
    else res = func_0018db38(q, t, 0, 0);
    if (res) {
        r = (res->f24 & 1) ^ 1;
        res->q = *v;
        t->vt[25](t, res);
        func_0018ca10(res);                          
    }
    func_0018f028(q);
    return r;
}
} // n0018ee60

// 0018ef68 (from src/anon/batch_w10.cpp)
namespace n0018ef68 {
void func_0016cc18(void*, void*, void*, void*, s32) asm("func_0016cc18");
void func_0018ef68(u8* p, void* a, void* b) asm("func_0018ef68");
void func_0018ef68(u8* p, void* a, void* b) {
    func_0016cc18(*(void**)p, *(void**)(p + 4), a, b, 0);
}
} // n0018ef68

// 0018ef98 (from src/anon/batch_w32.cpp)
namespace n0018ef98 {
void* func_0018ee10(void*) asm("func_0018ee10");
void func_0018ef98(s32 key, s32 val) asm("func_0018ef98");
void func_0018ef98(s32 key, s32 val) {
    s32* it = 0;
    while ((it = (s32*)func_0018ee10(it)) != 0) {
        if (it[3] == key) it[3] = val;
    }
}
} // n0018ef98

// 0018efe8 (from src/anon/tiny_auto80_queue.cpp)
namespace n0018efe8 {
void func_0018efe8(u32 a0) asm("func_0018efe8");
void func_0018efe8(u32 a0) {
    if (*(u8*)((u32)*(u32*)((u32)a0 + (s32)(40)) + (s32)(19)) == (u8)2u) return;
    u32 t7 = *(u32*)((u32)a0 + (s32)(4));
    t7 = (u32)(t7 | 0x80u);
    *(u32*)((u32)a0 + (s32)(4)) = t7;
}
} // n0018efe8

// 0018f010 (from src/anon/auto200_999.cpp)
namespace n0018f010 {
u32 func_0018f010(u32 a0) asm("func_0018f010");
u32 func_0018f010(u32 a0) {                    
    u32 p = *(u32 *)(a0 + 40);
    u32 v = *(u8 *)(p + 4);
    v -= 2;
    v = v < 2;
    u8 ret = (u8)v;
    return ret;
}
} // n0018f010

// 0018f028 (from src/anon/tiny_auto80_queue.cpp)
namespace n0018f028 {
u32 func_0018f070(...) asm("func_0018f070");
void func_0018f028(u32 a0) asm("func_0018f028");
void func_0018f028(u32 a0) {
    u32 t7 = (u32)(0x01c6u << 16);
    u32 s0 = a0;
    u32 t6 = *(u8*)((u32)t7 + (s32)(3296));
    if (t6 == 0u) {
        return;
    }
    if (func_0018f070() == 0u) {                        
        return;
    }
    u32 t7v = *(u32*)((u32)s0 + (s32)(4));
    t7v = (u32)(t7v | 0x800u);
    *(u32*)((u32)s0 + (s32)(4)) = t7v;
}
} // n0018f028

// 0018f070 (from src/anon/batch_w1734.cpp)
namespace n0018f070 {
struct Node_18f070 { u8 pad[0xc0]; Node_18f070* next; };
extern Node_18f070* D_01c60cd8 asm("D_01c60cd8");
static inline Node_18f070* next_18f070(Node_18f070* p) {
    if (p == 0) return D_01c60cd8;
    return p->next;
}
int func_0018f070(Node_18f070* a) asm("func_0018f070");
int func_0018f070(Node_18f070* a) {
    if (!a) return 0;
    Node_18f070* p = 0;
    while ((p = next_18f070(p)) != 0)
        if (p == a) return 1;
    return 0;
}
} // n0018f070

// 0018f0b0 (from src/anon/batch_w212.cpp)
namespace n0018f0b0 {
struct W212P { u32 a, b; void clr() { this->a = 0; this->b = 0; } };
struct W212R { f32 f; u32 pad; W212P p; };
extern W212R D_01c60cd0 asm("D_01c60cd0");
void func_0018f0b0(s32 a, s32 b) asm("func_0018f0b0");
void func_0018f0b0(s32 a, s32 b) {
    if (b == 0xffff) { if (a == 1) { D_01c60cd0.f = 0.7853981256484985f; } }
    if (b == 0xffff) { if (a == 1) { D_01c60cd0.p.clr(); } }
}
} // n0018f0b0

// 0018f100 (from src/ys/traps.cpp; _GLOBAL__I_ stub)
struct BD_VALUE;
namespace n0018f100 {
void func_0018f0b0(s32, s32) asm("func_0018f0b0");
}
namespace YS {
void trap_btlobj_target(BD_VALUE* bd) {
    (void)bd;
    n0018f100::func_0018f0b0(1, 0xffff);
}
}

// 0018f120 (_GLOBAL__D_ stub, never written before)
namespace n0018f120 {
u32 func_0018f0b0(u32, u32, u32, u32) asm("func_0018f0b0");
u32 func_0018f120(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0018f120");
u32 func_0018f120(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0018f0b0(0, 0x0000ffffu, a2, a3);
}
} // n0018f120
