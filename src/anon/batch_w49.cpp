#include "../common/types.h"

extern "C" {
void Obj2D_showGroup(int) asm("_ZN2dk5Obj2D9showGroupEi");
void ttarget0_001bfc28(void) asm("_Z17ttarget0_001bfc28v");
void wtarget_001c05b0(u32, u32, u32, u32) asm("_Z16wtarget_001c05b0jjjj");

void func_0011c798(u32, u32);
void func_0011ca20(u32, u32, u32, u32, u32);
void func_0011cd80(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f) {
    func_0011c798(a, e);
    func_0011ca20(a, b, c, d, f);
}

struct Node139858 { u32 f0; Node139858* next; u8 pad8[8]; s32 group; };
struct List139858 { u32 f0; Node139858* head; };
extern List139858* D_00347f80;
void func_00139580(Node139858*);
static inline Node139858* next139858(Node139858* o) {
    List139858* l = D_00347f80;
    if (!o) return l->head;
    return o->next;
}
void Obj2D_showGroup(int group) {
    Node139858* o = 0;
    while ((o = next139858(o)) != 0)
        if (o->group == group) func_00139580(o);
}

s32 func_00141080(f32);
void func_001ad990(u32, f32, f32, f32);
struct S348710 { u8 pad[64]; u32 f64; u32 f68; };
extern S348710 D_00348710;
void func_00141010(f32 x) {
    if (func_00141080(x)) {
        S348710* s = &D_00348710;
        if (s->f68) {
            func_001ad990(s->f68 + 2100, 0.0f, 1.0f, x);
            s->f64 = 0;
        }
    }
}



void func_0014b5e8(u32, u64, u64);
void func_0014b4b0(u32 a, u16 x0, u16 y0, u16 x1, u16 y1) {
    func_0014b5e8(a, (u64)(s32)(x0 * 16 + 8) | ((u64)(s32)(x1 * 16 + 8) << 16),
                     (u64)(s32)(y0 * 16 + 8) | ((u64)(s32)(y1 * 16 + 8) << 16));
}


struct E34a790 { u8 pad[48]; u8 f48; u8 pad2[15]; };
struct E34a778 { u32 id; u8 pad[20]; };
extern E34a790* D_0034a790;
extern s32 D_0034a77c;
extern E34a778* D_0034a778;
void func_00153948(u8 id) {
    if (D_0034a790 == 0) return;
    s32 n = D_0034a77c;
    for (s32 i = 0; i < n; i++)
        if (D_0034a778[i].id == id) D_0034a790[i].f48 = 0;
}

void func_00138c10(u8*, s32);
void func_00154b98(u8* p, s32 n) {
    s32 m = *(s32*)(p + 15556);
    if (m < n) n = m;
    *(s32*)(p + 15552) = n;
    *(s32*)(p + 15564) = n;
    *(s32*)(p + 15560) = n;
    s32 k = (n - 1) / 200;
    for (s32 i = 0; i < k; i++) func_00138c10(p + 2904 + i * 816, 44);
}

struct Node161248 { u8 pad[128]; Node161248* next; };
extern Node161248* D_004f3b38;
void func_00160940(Node161248*, u32, f32);
static inline Node161248* next161248(Node161248* n) {
    if (!n) return D_004f3b38;
    return n->next;
}
void func_00161248(f32 x, u32 a) {
    Node161248* n = 0;
    while ((n = next161248(n)) != 0) func_00160940(n, a, x);
}

u8* func_001a6a20(u32, u32);
s32 func_00176a90(u32);
s32 func_00179b68(u32 a) {
    s32 r = 0;
    if (*(u32*)(func_001a6a20(0x10002, 12) + 4) || func_00176a90(a)) r = 1;
    return r;
}

extern s32 D_0034ed00;
struct E1c60588 { u32 a, b, c; };
extern E1c60588 D_01c60588[];
void func_00182910(E1c60588*);
// 00182ab0: moved to src/anon/unit_00182780.cpp

typedef s32 (*Fn184478)(void*);
s32 func_00184478(u8* o) {
    s32 r = 0;
    if ((*(Fn184478*)(*(u8**)o + 64))(o)) {
        if (*(f32*)(o + 2112) != *(f32*)(o + 1344) || *(f32*)(o + 2120) != *(f32*)(o + 1352)) r = 1;
    }
    return r;
}




void func_00239700(u8*);
void func_001abb28(u8*);
u32 func_001ab810(void);  // get_global_1c7cec0
u32 func_001ab800(void);
void func_00239988(u8*, u32, u32);
void func_001abd30(u8* p) {
    *(u32*)p = 0;
    func_00239700(p + 4);
    func_001abb28(p + 348);
    u32 a = func_001ab810();  // get_global_1c7cec0
    func_00239988(p + 4, a, func_001ab800());
}

u8* func_001b9bc8(u8*);
typedef void (*Fn1bf6a8)(u8*);
void func_001bf6a8(void) {
    u8* n = 0;
    while ((n = func_001b9bc8(n)) != 0)
        if (*(u32*)(n + 1416) & 0x40000) (*(Fn1bf6a8*)(*(u8**)n + 40))(n);
}

extern u32 D_0034e948;
void func_001bf378(u8*, u32);
void ttarget0_001bfc28(void) {
    u32 v = D_0034e948;
    u8* n = 0;
    while ((n = func_001b9bc8(n)) != 0)
        if (*(u32*)(n + 1416) & 0x40000) func_001bf378(n, v);
}

extern u32 D_01d49328[8];
struct S1d49350 { u32 a, b; };
extern S1d49350 D_01d49350;
void wtarget_001c05b0(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        u32* p = D_01d49328;
        for (s32 i = 7; i >= 0; i--) *p++ = 0;
    }
    if (b == 0xffff && a == 1) {
        D_01d49350.a = 0;
        D_01d49350.b = 0;
    }
}

void func_001980d0(u8*, u32, s32, u32);
s32 func_0016a020(u8*);
extern u8 D_003513a8[];
void func_001c2338(u8* p, u32 a, u32 b) {
    func_001980d0(p, a, 9, b);
    *(u32*)p = (u32)D_003513a8;
    *(u32*)(p + 1416) |= 0x80000;
    p[943] = 64;
    if (func_0016a020(p) == 1185) *(u32*)(p + 1896) |= 0x10;
}

struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct M1c7148 { Vq a, b; };
extern M1c7148 D_01d498d0;
void func_00143928(M1c7148*);
void func_001c7148(u8* p) {
    M1c7148* m = &D_01d498d0;
    m->a = *(Vq*)p;
    m->a.y += *(f32*)(*(u8**)(p + 76) + 4);
    m->a.w = 1.0f;
    m->b = *(Vq*)(p + 48);
    m->b.w = 1.0f;
    func_00143928(m);
}

u8* func_001d6cc8(u8*);
s32 func_001a3570(u16);
void func_001d6da8(u16* out) {
    u8* n = 0;
    while ((n = func_001d6cc8(n)) != 0)
        if (func_001a3570(*(u16*)(n + 2)) > 0) *out++ = *(u16*)n;
    *out = 0;
}

void func_001e6000(u8*);  // obj_dec_timer



void func_002ff2e8(char*, const char*);


extern u8* D_0035ee10;
extern u32 D_0035ee2c;
s32 func_00139d78(void*);
s32 func_0024f2b8(u32);  // word_table_372368
struct E372390 { s16 a, b, c; };
extern E372390 D_00372390[];
s32 func_0024f240(void) {
    if (D_0035ee10 == 0 || !func_00139d78(D_0035ee10)) return 1;
    s32 i = func_0024f2b8(D_0035ee2c);  // word_table_372368
    return *(s32*)(D_0035ee10 + 388) == D_00372390[i].b;
}

extern u8* D_0035f038;
void func_00257970(void) {
    for (s32 i = 0; i < 24; i++)
        if (func_00139d78(D_0035f038 + i * 408 + 0x87d0)) break;
}


void func_0028da70(u32, s32);

extern s16* D_0035f230;
s32 func_0027ae78(s32 n) {
    s32 k = 0;
    s32 i;
    for (i = 0; i < 8; i++) {
        if (i == 6) continue;
        if (!((*D_0035f230 >> i) & 1)) continue;
        if (n == k) break;
        k++;
    }
    return i;
}

extern s8* D_0035f5ac;
extern char* D_0035f5c8;
extern char* D_0035f5cc;
u32 func_00293de8(s32);
void func_00293cb8(char*, s32, u32);
char* func_002ff918(char*, const char*);
void func_002931a8(char*);
void func_0029dd00(void) {
    char buf[128];
    func_00293cb8(buf, 4, func_00293de8(D_0035f5ac[4]));
    char* r = func_002ff918(buf, D_0035f5c8);
    if (r) func_002ff2e8(r, D_0035f5cc);
    func_002931a8(buf);
}

extern s8* D_0035f5ec;
u32 func_002a6368(s32);
s32 func_002944d0(u32);
s32 func_002a6290(void) {
    s32 n = 0;
    for (s32 i = 0; i < D_0035f5ec[0]; i++)
        if (func_002944d0(func_002a6368(D_0035f5ec[6 + i]))) n++;
    return n;
}

extern u32 D_0035f200, D_0035f214;
u32 func_0028b038(u32);
void func_0028be78(u32, u32);
void func_002a5df0(void);
void func_002a65d0(void);
void func_002a6308(u32, s32 m) {
    switch (m) {
    case 37:
        func_002a5df0();
        func_002a65d0();
        break;
    case 38:
        func_0028be78(D_0035f214, func_0028b038(D_0035f200));
        break;
    }
}

extern u8* D_0035f654;
extern u32 D_0035f650;
extern u8 D_0035f6d0;
s32 func_0028acc8(u32);
void func_0028abe0(u32);
typedef void (*Fn2b4f50)(u8*);
void func_002b4f50(void) {
    if (func_00139d78(D_0035f654)) (*(Fn2b4f50*)(*(u8**)D_0035f654 + 20))(D_0035f654);
    if (func_0028acc8(D_0035f650)) func_0028abe0(D_0035f650);
    D_0035f6d0 = 0;
}

extern u8* D_0035f6cc;
void func_0028ab20(u32);
void func_002b5078(void) {
    func_00139d78(D_0035f654);
    func_0028da70((u32)D_0035f654, *(s16*)(*(u8**)(D_0035f6cc + 20) + 4));
    if (func_0028acc8(D_0035f650)) func_0028ab20(D_0035f650);
}

extern u32 D_00361768[];
void func_002bc470(u32);
void func_002bcee8(u32* p) {
    u32* s = D_00361768;
    for (s32 i = 0; i < 27; i++) {
        p[0] = *s;
        p[1] = -1;
        p[2] = 0;
        func_002bc470(*s);
        p += 3;
        s++;
    }
}

struct B2bf5a0 { u8 b0 : 1; };
u8* func_001b6d70(u8);  // table_entry_ptr_b
void func_0016ac38(u8*, s32, s32, s32, s32);
void func_002bf5a0(u8* p) {
    u8* v = func_001b6d70((*(u8**)(p + 2808))[4]);  // table_entry_ptr_b
    if (!((B2bf5a0*)(p + 2791))->b0 && ((B2bf5a0*)(v + 3))->b0) func_0016ac38(p, 0, 1, 0, 0);
}


void func_002eb778(u8*, u32, s32, f32);
void func_002ec170(u32, u8* p) {
    func_002eb778(p, *(u32*)(p + 256), 0, 8.0f);
    *(u32*)(p + 268) &= ~1;
    *(u32*)(p + 264) |= 0x4000000;
}

struct F304ec8 { u8 pad[12]; u16 flags; s16 file; u8 pad2[64]; s32 offset; u32 data; };
long func_00305110(u32, s32, long, s32);
long func_00304ec8(F304ec8* fp, long off, s32 whence) {
    long r = func_00305110(fp->data, fp->file, off, whence);
    if (r == -1L) fp->flags &= ~0x1000;
    else {
        fp->flags |= 0x1000;
        fp->offset = r;
    }
    return r;
}

union U141988 { u32 v; u16 h; };
struct Idx141988 { u16 f0; u16 a, b, c, d; };
struct Out141988 { U141988 v[4]; U141988 n; };
// Fills three (or four, when the fourth index is set) entry pointers from a 16-byte-stride table.
void func_00141988(u8* o, Idx141988* ix, Out141988* out) {  // collect_entry_ptrs_by_halves
    out->v[0].v = *(u32*)(o + 16) + ix->a * 16;
    out->v[1].v = *(u32*)(o + 16) + ix->b * 16;
    out->v[2].v = *(u32*)(o + 16) + ix->c * 16;
    if (ix->d != 0xffff) {
        out->v[3].v = *(u32*)(o + 16) + ix->d * 16;
        out->n.v = 4;
    } else {
        out->n.v = 3;
    }
}

// Overlap test of two s16 boxes {min xyz, max xyz}.
s32 func_00145580(s16* a, s16* b) {  // cmp_halfword_triples
    if (a[3] < b[0]) return 0;
    if (a[0] > b[3]) return 0;
    if (a[4] < b[1]) return 0;
    if (a[1] > b[4]) return 0;
    if (a[5] < b[2]) return 0;
    if (a[2] > b[5]) return 0;
    return 1;
}

u8* func_0016d080(u32, s32);
void func_0016cbc8(u8*, s32, u32*, s32);
void func_0016cd48(u8*, s32);
void func_0016cab8(u8*);
void func_0016c7d8(u8*);
extern u32 D_01c61b00;
void func_00196288(u32 a) {
    u8* v = func_0016d080(D_01c61b00, 0);
    u32 t = a;
    func_0016cbc8(v, 12, &t, 1);
    func_0016cd48(v, 0);
    if (v) {
        func_0016cab8(v);
        func_0016c7d8(v);
    }
}

// Takes an entry from the 4-slot free list and pushes it on the active list.
struct E199468 { u32 f0, f4, f8, f12; f32 f16; E199468* next; };
struct P199468 { E199468 e[4]; s32 freeIdx[4]; s32 n; };
union H199468 { E199468* p; s32 i; };
struct L199468 { H199468 head; E199468* tail; };
extern P199468 D_01c620c8;
extern L199468 D_01c62140;
void func_00199468(u32 a, u32 b, u32 c, f32 f) {
    P199468* P = &D_01c620c8;
    s32 n = --P->n;
    E199468* e = &P->e[P->freeIdx[n]];
    E199468* h = D_01c62140.head.p;
    e->f4 = b;
    e->f8 = c;
    e->f12 = a;
    e->f16 = f;
    e->f0 = 0;
    if (!h) {
        D_01c62140.tail = e;
        D_01c62140.head.p = e;
        e->next = 0;
    } else {
        e->next = h;
        D_01c62140.head.p = e;
    }
}

struct NoTail { ~NoTail() {} };

void func_001e6000(u8*);  // obj_dec_timer
void func_001e6038(u8* p) {
    NoTail g;
    func_001e6000(p + 176);  // obj_dec_timer
    func_001e6000(p + 192);  // obj_dec_timer
    func_001e6000(p + 208);  // obj_dec_timer
    func_001e6000(p + 224);  // obj_dec_timer
    func_001e6000(p + 240);  // obj_dec_timer
    func_001e6000(p + 256);  // obj_dec_timer
    func_001e6000(p + 272);  // obj_dec_timer
    func_001e6000(p + 288);  // obj_dec_timer
    func_001e6000(p + 304);  // obj_dec_timer
    func_001e6000(p + 320);  // obj_dec_timer
}

// Runs every registered handler's optional callback (slot +16).
typedef void (*Fn1e7810)(u8*);
struct O1e7810 { u8 pad[100]; s32 n; u8 pad2[16]; u8** tbl; };
void func_001e7810(O1e7810* p) {
    for (s32 i = 0; i < p->n; i++) {
        u8* x = p->tbl[i];
        if (*(Fn1e7810*)(x + 16)) (*(Fn1e7810*)(x + 16))((u8*)p);
    }
}

void func_002fdfc8(const char*, ...);  // device_vprintf_va
extern char D_0036ef58[], D_0036efc8[], D_0036ef88[], D_0036ef98[];
void func_001e7878(u8*);
void func_001e8ac8(u8*);
void func_001e8330(u8*);
static inline void assert1e8bb8(const char* e, const char* f, s32 l) {
    func_002fdfc8(D_0036ef58, e);  // device_vprintf_va
    func_002fdfc8(D_0036ef98, f, l);  // device_vprintf_va
    asm volatile("break");
}
void func_001e8bb8(u8* p) {
    NoTail g;
    if (!p) assert1e8bb8(D_0036efc8, D_0036ef88, 982);
    func_001e7878(p);
    func_001e8ac8(p);
    func_001e8330(p);
}

void func_002f2be0(u8*, u32);
void func_002367c8(u8* p) {  // obj_dispatch_bitfield64
    if (((s32)(*(s64*)(p + 48) >> 32) & 1) == 0) func_002f2be0(p + 64, *(u32*)(p + 56));
    if (((*(u64*)(p + 48) >> 33) & 1) == 0) func_002f2be0(p + 160, *(u32*)(p + 60));
}

// Returns 1 if the current id is in the -1-terminated list.
u16* func_002632d0(void);
extern s16 D_00373270[];
s32 func_002636b0(void) {
    u16 k = *func_002632d0();
    s32 r = 0;
    for (s32 i = 0; D_00373270[i] >= 0; i++)
        if (D_00373270[i] == k) {
            r = 1;
            break;
        }
    return r;
}

u32 func_00190140(u8*);
u32 func_00176fb0(u8*, u32);
void func_00177008(u8*, u32, u8*);
void func_002e8770(u8** a) {
    NoTail g;
    u8* o = a[0];
    if (*(u32*)(o + 1416) & 0x80) {
        u8* q = *(u8**)(o + 2880) + 4;
        func_00190140(q);
        func_00177008(o, func_00176fb0(o, (u32)a[1]), q);
    }
}

extern s8 D_01c60cf0;
extern Vq D_01c60d00;
void func_002fd188(void (*)(void));  // pool_alloc_block
void func_001900c8(void);
Vq func_001a4b78(u32);
// Function-local static (guarded, destructor registered) refreshed on every call.
void func_0018f940(u32* p) {
    if (!D_01c60cf0) {
        D_01c60cf0 = 1;
        func_002fd188(func_001900c8);  // pool_alloc_block
    }
    D_01c60d00 = func_001a4b78(*p);
    *p = (u32)&D_01c60d00;
}

// Destructor body of an object holding two member arrays with empty element destructors.
struct A2e4a90 { u8 d[16]; ~A2e4a90() {} } __attribute__((aligned(16)));
struct B2e4a90 { u8 d[96]; ~B2e4a90() {} } __attribute__((aligned(16)));
struct C2e4a90 {
    u8 pad[16];
    B2e4a90 b[41];
    u8 pad2[528];
    A2e4a90 a[861];
    ~C2e4a90() {}
};
void func_002e4a90(C2e4a90* c) {  // in_even_range
    c->~C2e4a90();
}

// Hand-written VU0 macro code (uses vf6 / a3 from the caller); kept as asm.
extern u8 D_00363cd0[];
void func_002f4028(u32, u32, u32, u32) {  // build_transform_matrix
    asm volatile(
        ".set noreorder\n\t"
        "lui $8, %%hi(D_00363cd0)\n\t"
        "addiu $8, $8, %%lo(D_00363cd0)\n\t"
        "lqc2 $vf5, 0($8)\n\t"
        "vmr32.w $vf6, $vf6\n\t"
        "vaddx.x $vf4, $vf0, $vf6x\n\t"
        "vmul.x $vf6, $vf6, $vf6\n\t"
        "vmulx.yzw $vf4, $vf4, $vf0x\n\t"
        "vmulw.xyzw $vf8, $vf5, $vf6w\n\t"
        "vsub.xyzw $vf5, $vf0, $vf0\n\t"
        "vmulx.xyzw $vf8, $vf8, $vf6x\n\t"
        "vmulx.xyz $vf8, $vf8, $vf6x\n\t"
        "vaddw.x $vf4, $vf4, $vf8w\n\t"
        "vmulx.xy $vf8, $vf8, $vf6x\n\t"
        "vaddz.x $vf4, $vf4, $vf8z\n\t"
        "vmulx.x $vf8, $vf8, $vf6x\n\t"
        "vaddy.x $vf4, $vf4, $vf8y\n\t"
        "vaddx.x $vf4, $vf4, $vf8x\n\t"
        "vaddx.xy $vf4, $vf5, $vf4x\n\t"
        "vmul.x $vf7, $vf4, $vf4\n\t"
        "vsubx.w $vf7, $vf0, $vf7x\n\t"
        "vsqrt Q, $vf7w\n\t"
        "vwaitq\n\t"
        "bnez $7, 1f\n\t"
        "vaddq.x $vf7, $vf0, Q\n\t"
        "b 2f\n\t"
        "vaddx.x $vf4, $vf5, $vf7x\n"
        "1:\n\t"
        "vsubx.x $vf4, $vf5, $vf7x\n"
        "2:\n\t"
        ".set reorder"
        : : : "$8", "memory");
}

}
