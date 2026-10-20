#include "../common/types.h"

struct V4 {
    u32 w[4];
} __attribute__((aligned(16)));

namespace Tz {
struct Munny {
    static u32 Add(u32 n);
};
}

extern "C" {
u32 func_0030edb0(void);
void func_0030ee00(void);  // ee_intr_get_enable
extern u32 D_0037aa2c;
extern void* D_0037aa30;
u8* func_0016a070(void);
s32 func_001a35f8(u32, u8*);
void func_00135d88(void);
extern u8* D_00341708[];
void func_001128d0(u32, s32);
extern s32 D_003417a8;
extern u32 D_00341788[];
void* func_00132350(void*);
void func_00124bb8(void*);  // obj_ctor_347b88
extern void* D_00347bb0[];
struct E64 { u8 b[64]; };
extern E64 D_003a99f0[];
void func_0011ed90(u8*, s32);
s32 func_00139d78(void*);
void func_0014c050(void*);
extern u8 D_004f3820[];
extern void* D_00348698[];
extern u32 D_0034e948;
u32 func_0016e920(u32);
u8* func_001b9bc8(u8*);
s32 func_0016c008(u8*, u32);
void func_00190128(void*);
void func_00190878(void*, u32, u32);
void func_001d6ab0(u32);
void func_0019ca90(u32, u32, void*);
u32 func_0016c028(void*);  // obj_get_attach_or_alt
s32 func_001a7610(u32, void*, s32, f32, f32);
void func_0016ace0(void*, void*);
s32 func_001883d8(u8*, void*);
void func_001880b0(u8*, void*);
extern u8 D_0036cbb0[];
void func_001902a8(void*, void*);
extern s32 D_01c6cb70;
struct P8 { u32 a; u32 b; };
extern P8 D_01c6cb30[];
void func_00105110(u32);
void func_001ac970(void*, s32, s32, u32, s32, s32, s32, s32);
extern void* D_00350b30[];
void func_001ac078(void*, s32, s32, s32);
void func_001aa388(void*, u32);
extern f32 D_00349e10;
void* func_00168b38(u32, s32, s32);  // entry_array_find_nth
s32 func_001dcd38(void*);
s32 func_001c8ab0(void);
s32 func_001dc790(u32);
s32 func_001dcc60(u8*);
u32 func_001dc5f8(u32);
void func_002bc398(u32, u32);
void func_002bc3f0(u32);
u8* func_00102c80(void);
u8* func_00102788(u32, s32, s32, void*);
void* func_001050d8(u32);
void func_001e7be0(void*);
void func_001e7798(u32, u32);
extern u32 D_01d9e6e4;
void func_00225530(void*);
void func_00225280(u32, u32);
extern u32 D_00370d88[];
extern void* D_0035eb08[];
s32 func_002424c0(u32);
u8* func_001058e8(void);
extern u8* D_0035f0e4;
s32 func_00257780(void);
extern void* D_0035f04c;
extern void* D_0035f01c;
s32 func_0028be58(void*);
s32 func_0028acc8(void*);
void func_0028e510(void*, s32, s32);
extern u8* D_0035f480;
struct Ent8 { s16 ids[3]; s16 pad; };
extern Ent8 D_0035f468[];
s32 func_00276638(s32);
extern u8* D_0035f5ac;
u8* func_0029da68(s32);
s32 func_00292a90(s32);
s32 func_00292af0(s32);
void func_002bd998(void*, u32);
u8* func_00102c48(s32, s32, void*, s32);
void func_002be3a8(void);
void task_end_002be3c8(void*) asm("_ZN8worldmap8Libretto14finalizeThreadEP4TASK");
void func_002be428(void);
void func_00102c18(s32, s32, void*);
s32 func_002c1b48(void*);
struct B3 { u8 b[3]; };
extern B3 D_00375518[];
u32 func_001c2b58(s32);
void func_002c1b60(void*, u32);
void func_00198450(void*);
extern V4 D_01e2bca0;
extern V4 D_01e2bcb0;
struct M4 { V4 r[4]; };
extern M4 D_01e2bcc0;
void func_00177dc8(void*, u32, s32, u32, u32);
extern void* D_00361d00[];
void func_001befd8(u32, s32, s32);
void func_002cbec0(u32, u32);
void func_002eaf48(V4*, u32, s32);
extern V4 D_01e2c050;
void func_0016bd60(u32, s32);
void func_002eb6f8(u32, s32, f32);
extern f32 D_01e2c060;
extern V4 D_00363550;
V4* func_0016c028_v(u32) asm("func_0016c028");

// 128-bit copy (lq/sq), as the original
static inline void cpq(void* d, const void* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}

// Local with a destructor: keeps the final call from becoming a tail call.
struct NoTail { ~NoTail() {} };
void func_0017d8c0(M4*, V4*, V4*);
void func_0029dd60(void);
struct P199 { u32 f0; u32 flag : 1; u32 rest : 31; u32 f8; u8* o; u32 f16; };
struct O408 { void** vt; u8 pad[404]; };
extern O408* D_0035ed64;
struct H3 { u8 pad[16]; u32 lo : 16; u32 hi : 16; u32 pad2; u32 off; };
struct P3 { u32 vt; H3* h; u32 base; u32 a; u32 b; u32 c; };
struct Ent32 { u32 key; u16 id; u8 pad[26]; };
struct NdB { u8 q[16]; u32 f16; bool b20; s8 b21; u8 b22; s8 b23; bool b24; u8 pad[3]; void* owner; u32 f32; NdB* next; };
struct LLB { NdB* head; NdB* tail; };
struct LsB { u8 pad[8]; u8 b8; u8 pad2[3]; LLB list; };

s32 func_0010f748(u8* p, u32 b) {
    u8* q = *(u8**)(p + 12);
    if (!q) return 0;
    s32 t = *(s32*)(q + 4);
    if (t != 0 && t != 31) return 0;
    if (!(*(u32*)(p + 352) & 4)) return 0;
    return func_001a35f8(b, func_0016a070()) > 0;
}

void func_00112388(void) {
    func_00135d88();
    for (s32 i = 0; i < 2; i++) {
        u8* e = D_00341708[i + 1];
        if (e) {
            u8* o = *(u8**)(e + 2912);
            (*(void (**)(void*))(*(u8**)o + 36))(o);
        }
    }
}

void func_001129d8(u32 a) {
    func_001128d0(a, 1);
    if (D_003417a8 >= 8) func_001128d0(D_00341788[0], 1);
    D_00341788[D_003417a8++] = a;
}

void func_00127f40(P3* p) {
    func_00124bb8(p);  // obj_ctor_347b88
    p->vt = (u32)D_00347bb0;
    H3* h = p->h;
    s32 n = h->hi - h->lo;
    p->base = (u32)D_003a99f0;
    p->a = (u32)(D_003a99f0 + h->hi);
    p->b = (u32)((E64*)p->a + n);
    p->c = (u32)((E64*)p->b + n);
    func_0011ed90((u8*)h + h->off, n);
}

u32 func_0016b740(u32 id) {
    if (id == 566) return D_0034e948;
    u32 key = func_0016e920(id);
    u8* v = 0;
    while ((v = func_001b9bc8(v)) != 0) {
        if (*(u32*)(v + 8) == key) break;
    }
    return (u32)v;
}

s32 func_0016f6f8(u32 id) {  // check_flag_4000_type
    if (!(id & 0x40000000)) return 0;
    u8* p = (u8*)func_0016e920(id);
    if (!p) return 0;
    switch (p[4]) {
    case 7: case 22: case 24: return 0;
    default: return 1;
    }
}

void func_00172c38(u8* p) {
    u8* v = 0;
    while ((v = func_001b9bc8(v)) != 0) {
        if (func_0016c008(v, *(u32*)(p + 4)) == *(s32*)(p + 8)) break;
    }
    *(u8**)(*(u8**)p + 4) = v;
}

void func_00174290(u8* p) {
    u8 buf[32];
    u32 x = *(u32*)(*(u8**)(p + 8) + 4);
    func_00190128(buf);
    func_00190878(buf, x, 0);
    u8* o = *(u8**)(*(u8**)p + 4);
    func_001d6ab0(*(u32*)(o + 2876));
    func_0019ca90(*(u32*)(o + 2880), *(u32*)(p + 4), buf);
}

void func_001852b8(u8* p) {
    u8 buf[16];
    u32 v = func_0016c028(p);  // obj_get_attach_or_alt
    if (func_001a7610(v, buf, (((s32)(*(s64*)(p + 1536) << 29 >> 32)) & 0xf) | 0x10000, 100000.0f, 200.0f))
        func_0016ace0(p, buf);
}

void func_0018b200(u8* p) {
    u8* s = p + 768;
    if (*(u8*)(*(u8**)(p + 8) + 4) == 15) {
        if (func_001883d8(s, D_0036cbb0)) func_001880b0(s, D_0036cbb0);
    }
}

// Mark dead and destroy every child in the list.
void func_00199cd0(P199* p) {
    p->flag = 1;
    u8* o = p->o;
    while (o) {
        u8* n = *(u8**)(o + 96);
        if (o) (*(void (**)(void*))(*(u8**)o + 4))(o);
        o = n;
    }
    p->f16 = 0;
    p->o = 0;
}

void func_0019ca28(u8* p, u32* s) {
    u32 buf[8];
    buf[3] = 0;
    *(u32*)(p + 4) = s[0];
    *(u32*)(p + 8) = s[1];
    *(u32*)(p + 12) = s[2];
    *(u32*)(p + 16) = s[3];
    *(u32*)(p + 20) = s[4];
    func_001902a8(p + 4, buf);
    *(u32*)(p + 36) = ((u8*)buf[3])[1];
}

void func_001ad430(u8* p, u32 a) {
    func_001ac970(p, 3, 5, a, 0, 256, 336, 0);
    *(u32*)(p + 104) = 0;
    *(u32*)(p + 100) = 3;
    *(void***)p = D_00350b30;
    func_001ac078(p + 1196, 1, 1, 0);
    u8* q = p + 12;
    func_001aa388(q, *(u32*)(q + 12));
}

s32 func_001ad9c8(f32* p) {  // float_accumulate_clamped
    if (p[1] == 0.0f) return 0;
    f32 v = p[0] + p[1] * D_00349e10;
    p[0] = v;
    if (v <= 0.0f) {
        p[0] = 0.0f;
        p[1] = 0.0f;
    } else if (1.0f <= v) {
        p[0] = 1.0f;
        p[1] = 0.0f;
    }
    return 1;
}

// Init a node from a 16-byte header and append it to the owner's list.
void func_001c1748(NdB* n, LsB* l, void* src, u32 a3) {  // obj_init_from_src
    cpq(n, src);
    n->f16 = a3;
    n->b21 = -128;
    n->b20 = false;
    n->b22 = l->b8;
    n->b23 = -1;
    n->b24 = false;
    n->owner = l;
    n->f32 = 0;
    LLB* L = &l->list;
    if (!L->tail) { L->tail = n; L->head = n; n->next = 0; } else { L->tail->next = n; n->next = 0; L->tail = n; }
}

void func_001d5370(u32* out, u32 a, s32 b) {
    u8* v = (u8*)func_00168b38(a, -1, b);  // entry_array_find_nth
    u8* w = (u8*)func_00168b38(a, -1, b + 1);  // entry_array_find_nth
    u32 x = *(u32*)(v + 8);
    u32 y = *(u32*)(w + 8);
    out[0] = x;
    out[1] = y;
}

u8* func_001dba18(u32 id) {
    u8* v = 0;
    while ((v = func_001b9bc8(v)) != 0) {
        if (!(*(u32*)(v + 1416) & 0x10000000)) continue;
        if (*(u32*)(v + 8) == id) return v;
    }
    return 0;
}

s32 func_001dcc60(u8* p) {
    s32 r = 0;
    if (func_001dcd38(p) == 1 || func_001c8ab0() != 1) {
        u32 m = *(u32*)(p + 8) & 0x800000;
        r = m == 0;
    }
    return r;
}

void func_001e00b0(u8* p) {
    if (*(s32*)(p + 84) < 0) return;
    if (!func_001dc790(*(u32*)(p + 64)) && func_001dcc60(*(u8**)(p + 64))) {
        func_002bc398(*(u32*)(p + 84), func_001dc5f8(*(u32*)(p + 64)));
        return;
    }
    func_002bc3f0(*(u32*)(p + 84));
}

void func_001e7cc0(u8* p) {
    u8* o = *(u8**)(p + 116);
    while (o) {
        u8* n = *(u8**)o;
        func_001e7be0(o);
        o = n;
    }
    *(u32*)(p + 116) = 0;
    if (*(u32*)(p + 128)) {
        func_001e7798(D_01d9e6e4, *(u32*)(p + 128));
        *(u32*)(p + 128) = 0;
    }
}

void func_00225328(u8* p) {
    if (*(u16*)(p + 6)) func_00225530(p);
    u16 t = *(u16*)(p + 8);
    if (t == 0) func_00225280(p[11], 12288);
    else if (t == 257) func_00225280(p[11], 6144);
    else func_00225280(p[11], D_00370d88[p[9]]);
}

void func_0023c008(u32* p) {  // obj_ctor_36eae8
    *(void***)p = D_0035eb08;
    p[1] = 0;
    p[2] = 0; p[3] = 0; p[4] = 0; p[5] = 0; p[6] = 0; p[7] = 0; p[8] = 0; p[9] = 0;
    p[10] = 0; p[11] = 0; p[12] = 0; p[13] = 0; p[14] = 0; p[15] = 0; p[16] = 0;
    p[17] = 0; p[18] = 0; p[19] = 0;
    *(u8*)(p + 20) = 0;
    p[21] = 0;
    p[22] = 0;
}

void func_00249358(void) {
    for (s32 i = 0; i < 3; i++) {
        if (func_00139d78(&D_0035ed64[i])) ((void (*)(void*))D_0035ed64[i].vt[5])(&D_0035ed64[i]);
    }
}

s32 func_002671e8(s32 n) {  // find_free_bit_index
    s32 r = -1;
    s32 cnt = 0;
    u8* g = D_0035f0e4;
    s32 base = *(s8*)(g + 32) * 10;
    u32 bits = *(u32*)(g + 24);
    for (s32 i = 0; i < 10; i++) {
        s32 b = base + i;
        if (bits & (1 << b)) {
            if (cnt == n) { r = b; break; }
            cnt++;
        }
    }
    return r;
}

s32 func_00269f58(void) {
    s32 r = func_00257780();
    if (r) return r;
    if (D_0035f04c) r = func_0028be58(D_0035f04c) != 0;
    if (r) return r;
    if (D_0035f01c) r = func_0028acc8(D_0035f01c) != 0;
    return r;
}

void func_0028e5e0(void* a, s16* l, s32 n) {
    func_00139d78(a);
    for (s32 i = 0; i < n; i++) func_0028e510(a, i, l[i]);
}

Ent8* func_0028f690(s32 i) {  // record884_type_index
    u8* q = D_0035f480;
    q += i * 884;
    s32 v = *(s32*)(q + 388);
    Ent8* r = 0;
    for (s32 k = 0; k < 3; k++)
        if (v == D_0035f468[0].ids[k]) r = &D_0035f468[0];
    if (!r) r = &D_0035f468[1];
    return r;
}

void func_0029dda8(void) {
    s32 i = func_00276638(15);
    u8* e = func_0029da68(*(s16*)(D_0035f5ac + i * 2 + 8));
    s32 s = *(s8*)(e + 1);
    if (func_00292a90(s)) return;
    if (func_00292af0(s)) return;
    func_0029dd60();
}

void func_002be340(u32 a) {  // alloc_and_start_task
    void* o = func_001050d8(108);
    func_002bd998(o, a);
    u8* r = func_00102c48(1, 15000, (void*)func_002be3a8, 8192);
    *(void**)(r + 48) = (void*)task_end_002be3c8;
    func_00102c18(1, 61000, (void*)func_002be428);
}

void func_002c1ae8(u8* p) {
    *(B3**)(p + 2788) = &D_00375518[func_002c1b48(p) - 1];
    func_002c1b60(p, func_001c2b58(func_002c1b48(p)));
    func_00198450(p);
}

void func_002c20f8(V4* a) {
    if (a != &D_01e2bca0) cpq(&D_01e2bca0, a);
    M4 m;
    func_0017d8c0(&m, &D_01e2bcb0, &D_01e2bca0);
    if (&m != &D_01e2bcc0)
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(&D_01e2bcc0), "r"(&m) : "$8", "$9", "$10", "$11", "memory");
}

void func_002c5850(u8* p, u32 a, u32 b, u32 c) {
    func_00177dc8(p, a, 11, b, c);
    *(void***)p = D_00361d00;
    *(u32*)(p + 1416) |= 0x20000000;
    *(u32*)(p + 3012) = 0;
    *(u32*)(p + 3024) = 0;
    *(u32*)(p + 3028) = 0;
    *(u32*)(p + 3032) = 0;
    func_001befd8(*(u32*)(p + 2884), 0, 0);
    *(u32*)(p + 2748) |= 0x10;
}

Ent32* func_002e3260(u8* p, u32 key, u32 id) {
    s32 n = *(s32*)(p + 8);
    Ent32* e = (Ent32*)(p + 16);
    for (s32 i = 0; i < n; i++, e++) {
        if (!key || !e->key || ((e->key & 0xffff0000) == (key & 0xffff0000) && e->id == id)) return e;
    }
    return 0;
}

void func_002eca38(u32, u32 b) {
    func_002eb6f8(b, 269, 0.0f);
    D_01e2c060 = 0.0f;
    V4* v = func_0016c028_v(b);
    if (v != &D_00363550) cpq(&D_00363550, v);
}

}

struct WT { s32 a; u32 b, c, d; union { u32 w; u64 q; } u; void* next; };

u32 Tz::Munny::Add(u32 n) {
    if (func_002424c0(n)) *(u32*)(func_001058e8() + 9280) += n;
    else *(u32*)(func_001058e8() + 9280) = 999999;
    return *(u32*)(func_001058e8() + 9280);
}

void ctarget_0011e350(u32 a, u32 b, u32, u32) {
    u8* s = (u8*)a;
    u8* o = (u8*)b;
    while (o) {
        u8* n = (u8*)func_00132350(o);
        (*(void (**)(void*))(*(u8**)o + 0))(o);
        u8* q = *(u8**)(s + 16);
        (*(void (**)(void*, void*))(*(u8**)q + 4))(q, o);
        o = n;
    }
}

void u_tail0_001a6ae8(void) {
    for (s32 i = 0; i < D_01c6cb70; i++) func_00105110(D_01c6cb30[i].b);
    D_01c6cb70 = 0;
}

// Queue a request node: interrupts off, push onto the pending list, restore.
void wtarget_00100700(u32 a, u32 b, u32 c, u32 d) {
    NoTail nt;
    WT* p = (WT*)b;
    p->u.w = 0;
    p->a = -1;
    p->b = c;
    p->u.q |= 0x7fa;
    p->c = d;
    p->d = a;
    u32 s = func_0030edb0();
    D_0037aa2c = s;
    p->next = D_0037aa30;
    D_0037aa30 = p;
    if (s) func_0030ee00();  // ee_intr_get_enable
}

void wtarget_0015eaf8(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) func_0014c050(D_004f3820);
    if (b == 0xffff && a == 0) *(void***)D_004f3820 = D_00348698;
}

void wtarget_002ec960(u32 a, u32, u32, u32) {
    u32 s = *(u32*)(a + 1288);
    func_002cbec0(s, func_0016c028((void*)a));
    V4 t;
    func_002eaf48(&t, a, 1);
    if (&t != &D_01e2c050) cpq(&D_01e2c050, &t);
    func_0016bd60(a, 61);
}
