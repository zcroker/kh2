#include "../common/types.h"

// 128-bit copy (lq/sq through t0).
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

// A local of this type keeps gcc from turning the final call into a sibling call.
struct NoTail { ~NoTail() {} };

// Word accessed through a union: gcc treats it as aliasing everything, which
// reproduces the reloads / ordering the original shows at these sites.
union Word { f32 f; u32 u; };

// 16-byte aligned vector; assignment copies a quadword unless self-assigned.
struct Vec4 {
    f32 x, y, z, w;
    Vec4& operator=(const Vec4& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));

extern "C" {

// --- 00100228
// crt0 helper: zero [v0, v1) (bytes up to 16-byte alignment, then quadwords,
// then the tail). Hand-written assembly: register inputs v0/v1, sq loop.
void func_00100228(void) {  // align_and_zero_fill
    asm volatile(
        ".set noreorder\n"
        "1:\n\t"
        "andi $4, $2, 0xf\n\t"
        "beqz $4, 2f\n\t"
        "nop\n\t"
        "sb $0, 0($2)\n\t"
        "addiu $2, $2, 1\n\t"
        "nop\n\t"
        "j 1b\n\t"
        "nop\n"
        "2:\n\t"
        "lui $4, 0xffff\n\t"
        "ori $4, $4, 0xfff0\n\t"
        "and $4, $3, $4\n"
        "3:\n\t"
        "beq $2, $4, 4f\n\t"
        "nop\n\t"
        "sq $0, 0($2)\n\t"
        "addiu $2, $2, 16\n\t"
        "nop\n\t"
        "nop\n\t"
        "j 3b\n\t"
        "nop\n"
        "4:\n\t"
        "beq $2, $3, 5f\n\t"
        "nop\n\t"
        "sb $0, 0($2)\n\t"
        "addiu $2, $2, 1\n\t"
        "nop\n\t"
        "nop\n\t"
        "j 4b\n\t"
        "nop\n"
        "5:\n"
        ".set reorder"
        ::: "$4", "memory");
}

// --- 00105550
// setjmp: saves gp/sp/fp/ra/s0-s7 (128-bit) and f20-f31. Hand-written assembly.
int func_00105550(void* jb) {
    asm volatile(
        "sq $28, 0(%0)\n\t"
        "sq $29, 16(%0)\n\t"
        "sq $30, 32(%0)\n\t"
        "sq $31, 48(%0)\n\t"
        "sq $16, 64(%0)\n\t"
        "sq $17, 80(%0)\n\t"
        "sq $18, 96(%0)\n\t"
        "sq $19, 112(%0)\n\t"
        "sq $20, 128(%0)\n\t"
        "sq $21, 144(%0)\n\t"
        "sq $22, 160(%0)\n\t"
        "sq $23, 176(%0)\n\t"
        "swc1 $f20, 192(%0)\n\t"
        "swc1 $f21, 196(%0)\n\t"
        "swc1 $f22, 200(%0)\n\t"
        "swc1 $f23, 204(%0)\n\t"
        "swc1 $f24, 208(%0)\n\t"
        "swc1 $f25, 212(%0)\n\t"
        "swc1 $f26, 216(%0)\n\t"
        "swc1 $f27, 220(%0)\n\t"
        "swc1 $f28, 224(%0)\n\t"
        "swc1 $f29, 228(%0)\n\t"
        "swc1 $f30, 232(%0)\n\t"
        "swc1 $f31, 236(%0)"
        : : "r"(jb) : "memory");
    return 0;
}

// --- 0010ab08
extern u8 D_00341060[];
extern u8 D_00341270[];
extern u8 D_00341480[];
void func_001342c8(void*, int, u32);
void func_0010ab08(int n) {
    switch (n) {
    case 0: func_001342c8(D_00341060, 33, 0x13000000); break;
    case 1: func_001342c8(D_00341270, 33, 0x13000000); break;
    case 2: func_001342c8(D_00341480, 33, 0x13000000); break;
    }
}

// --- 0014ba20
// Constructor: base ctor, vtable, then two GS register packets.
extern u64 D_0036b0d8;
extern void* D_00349da8[];
void func_0014b290(u8*);
void func_0014ba20(u8* p) {
    func_0014b290(p);
    u64 d = D_0036b0d8;
    *(void**)p = D_00349da8;
    *(u64*)(p + 288) = 0x1000000000008001ULL;
    *(u64*)(p + 296) = 14;
    *(u64*)(p + 304) = d;
    *(u64*)(p + 312) = 64;
    *(u64*)(p + 256) = 0x1000000000008001ULL;
    *(u64*)(p + 264) = 14;
    *(u64*)(p + 272) = d;
    *(u64*)(p + 280) = 64;
}

// --- 001576e8
u32 func_00155d58(u8*, int);  // table_word_indexed_by_3
void func_00138c10(u8*, u32);
void func_00154408(u8*, u32);
void func_001576e8(u8* p) {
    func_00138c10(p + 6704, func_00155d58(p, 0));
    func_00138c10(p + 7116, func_00155d58(p, 1));
    func_00138c10(p + 8352, func_00155d58(p, 2));
    func_00154408(p + 64, *(u32*)(p + 24));
}

// --- 0015a768
extern f32 D_004f3604;
extern u8 D_0034aa70[];
void func_00190128(void*);
void func_0015a768(int a, int b) asm("_Z13func_0015a768ii");
void func_0015a768(int a, int b) {
    NoTail nt;
    if (b == 0xffff && a == 1) D_004f3604 = 0.052359875f;  // 3 degrees
    if (b == 0xffff && a == 1) func_00190128(D_0034aa70);
}

// --- 00166880
void func_001666f0(u8*, u16, u32, u16, u16);  // obj_store_masked
void func_00166880(u8* p, u8 c, u16 a, u32 b, u16 d, u16 e, s16 x, s16 y) {
    func_001666f0(p, a, b, d, e);  // obj_store_masked
    *(s16*)(p + 10) = x;
    *(s16*)(p + 12) = y;
    p[14] = c;
}

// --- 001675b0
void func_00167638(f32, f32, f32);
void func_00167b98(void);
void func_00167c30(void);
void func_00167618(void);
extern u32 D_0032b91c;
void func_00102788(u32, u32, u32, void (*)(void));
void func_001675b0(void) {
    func_00167638(60.0f, 30.0f, 4.0f);
    func_00167b98();
    func_00167c30();
    func_00102788(D_0032b91c, 0, 0x1adb0, func_00167618);
}

// --- 00167c30
struct S167a { u8 pad[68]; void* p; u8 pad2[24]; };
struct S167b { u8 pad[384]; };
extern S167a D_0034d6c0[];
extern S167b D_0034d3c0[];
extern s32 D_004f5250;
extern u32 D_0034d780;
void func_00167f38(int);
void func_00167c30(void) {
    for (int i = 0; i < 2; i++) D_0034d6c0[i].p = &D_0034d3c0[i];
    D_004f5250 = -1;
    D_0034d780 = 0;
    func_00167f38(0);
}

// --- 0016f970
extern u32 D_0034dc98;
extern u32 D_01c5f460[];
u32 func_00106178(void*, int);
extern u8 D_004f6440[];
void func_0016f970(void) {
    D_0034dc98 = func_00106178(D_004f6440, 16384);
    for (int i = 0; i < 7; i++) D_01c5f460[i] = 0;
    D_01c5f460[1] = 0xe0000;
    D_01c5f460[5] = 0x300000;
    D_01c5f460[6] = 0xc0000;
}

// --- 00173348
// Lazily registers the cleanup of a static vector, fills it and hands it out.
extern s8 D_01c5f4d0;
extern Vec4 D_01c5f4e0;
void func_00175538(void);
void func_002fd188(void (*)(void));  // pool_alloc_block
Vec4 func_00143e50(u16, int);
void func_00173348(void* p) {
    if (!D_01c5f4d0) {
        D_01c5f4d0 = 1;
        func_002fd188(func_00175538);  // pool_alloc_block
    }
    D_01c5f4e0 = func_00143e50(*(u16*)p, 0);
    *(Vec4**)p = &D_01c5f4e0;
}

// --- 00188670
struct S188 { u32 a; u32 b; u32 c; };
extern S188 D_01c608c0[];
extern u32 D_01c60bc0;
extern u32 D_00351214;
void func_00188550(void);
void func_00188670(void) {
    for (int i = 0; i < 64; i++) D_01c608c0[i].a = 0;
    D_01c60bc0 = 0;
    func_00102788(D_00351214, 0, 0, func_00188550);
}

// --- 00196b88
extern u8 D_00350378;
extern u8 D_00350379;
extern u32 D_01c61b40;
u32 func_00198d20(int);
void func_00196b88(void) {
    u32 v = func_00198d20(0);
    D_00350379 = 0;
    if ((v & 0x3f) - 2 < 2) {
        D_00350378 = 1;
        if (!(v & 0xc0)) D_00350379 = 1;
    } else {
        D_00350378 = 0;
    }
    D_01c61b40 = 1;
}

// --- 00196e98
int func_00227118(u32);
void func_001d30f8(u8*, int, int);
void func_00196e98(u8* p, int x) {
    if (!x) return;
    if (func_00227118(*(u32*)(p + 4)) == 2) func_001d30f8(p + 64, 3, x);
    else func_001d30f8(p + 64, 2, x);
}

// --- 001a67e0
// Walks the list up to n (result unused), then destroys and frees n.
struct Node1a6 { u8 pad[12]; Node1a6* next; };
extern Node1a6* D_01c6cb20;
void func_001a5d48(Node1a6*);
void func_00105110(void*);
void func_001a67e0(Node1a6* n) {
    NoTail nt;
    if (!n) return;
    Node1a6* it = 0;
    while ((it = it ? it->next : D_01c6cb20) != 0) {
        if (it == n) break;
    }
    if (n) {
        func_001a5d48(n);
        func_00105110(n);
    }
}

// --- 001aea00
// Constructor: base ctor, vtable, flags and a sub-object's defaults.
extern void* D_00350ce0[];
void func_00185b00(u8*);
void func_001aea00(u8* p) {
    func_00185b00(p);
    *(u32*)p = (u32)D_00350ce0;
    *(u32*)(p + 1416) |= 0x400;
    u8* m = p + 1648;
    *(u32*)(m + 264) = 0;
    ((Word*)(m + 260))->f = 2000.0f;
    *(u32*)(p + 2748) |= 0x8404;
}

// --- 001afe70
u8* func_001aff90(u32, u32, u32);
int func_001affe0(u8*, u32, u32);
int func_001afe70(u32 a, u32 b, u32 c, u32* out) {
    u8* r = func_001aff90(a, b, c);
    if (!r) return -1;
    *out = r[2];
    return func_001affe0(r, a, c);
}

// --- 001d1fa8
// Constructor: base part (vtable 0x3525c8), then derived vtable 0x3525e8.
extern void* D_003525c8[];
extern void* D_003525e8[];
void func_00320400(u8*);
void func_001d1678(u8*, int);  // obj_init_28bytes
void func_001d19e8(u8*, int);
void func_001d16e8(u8*, int, int);
void func_001d1fa8(u8* p) {  // obj_ctor_3525c8
    *(u32*)(p + 4) = 0;
    *(u32*)p = (u32)D_003525c8;
    *(u32*)(p + 8) = 0;
    func_00320400(p + 12);
    func_001d1678(p, -1);  // obj_init_28bytes
    *(u32*)(p + 48) = 0;
    *(u32*)p = (u32)D_003525e8;
    func_001d19e8(p, -1);
    *(u32*)(p + 44) = 0;
    *(u32*)(p + 56) = 0;
    func_001d16e8(p, 0, 12);
}

// --- 001d5ec0
// Replaces the first entry of p[0..n) whose low 15 bits equal table[a-1][b-1]
// with table[a-1][b] (keeping bit 15).
struct Row1d5 { u16 v[5]; };
extern Row1d5 D_0036e5a0[];
u16 func_001d5ec0(u16* p, int n, int a, int b) {  // halfword_table_lookup
    Row1d5* r = &D_0036e5a0[a - 1];
    u16* e = &r->v[b];
    u16 from = e[-1];
    u16 to = e[0];
    for (int i = 0; i < n; i++, p++) {
        if ((*p & 0x7fff) == from) {
            *p = (*p & 0x8000) | (to & 0x7fff);
            return to;
        }
    }
    return to;
}

// --- 001d6e60
struct S1d6 { u32 a; u32 n; };
extern S1d6* D_01d5ba98;
void func_001d6da8(u16*);
int func_001d6e60(void) {
    u16 buf[D_01d5ba98->n + 1];
    func_001d6da8(buf);
    return buf[0] != 0;
}

// --- 001db5a8
struct S1db { u32 a; u32 n; u8 data[1]; };
extern S1db* D_01d5baac;
extern char D_00321b28[];
int func_002fd248(int, void*, u32, int, const char*);
void func_001db5a8(int id) {
    NoTail nt;
    if (!func_002fd248(id, D_01d5baac->data, D_01d5baac->n, 92, D_00321b28))
        func_002fd248(69, D_01d5baac->data, D_01d5baac->n, 92, D_00321b28);
}

// --- 00200638
extern u8* D_01d9e6e8;
extern u8 D_01d9e730[];
extern u8 D_01d9e8c0[];
void func_002f3d08(u8*, u8*, u8*);
void func_00200638(u8* a, u32 unused, u8* c) {
    NoTail nt;
    func_002f3d08(D_01d9e6e8 + 80, D_01d9e730, a + *(s32*)(*(u8**)(c + 12) + 4) + 160);
    func_002f3d08(D_01d9e6e8 + 80, D_01d9e8c0, D_01d9e6e8 + 80);
    func_002f3d08(D_01d9e6e8 + 80, D_01d9e6e8 + 80, D_01d9e6e8 + 16);
}

// --- 00222800
// VU0: d.xy = ftoi4(s.xy), d.zw = ftoi0(s.zw); if s.xy falls outside
// [0, 4096) (clip flags), d.w is replaced by 0x8000.
void func_00222800(void* d, void* s) {  // vec2_ftoi_round_pack
    asm volatile(
        ".set noreorder\n\t"
        "lqc2 $vf1, 0(%1)\n\t"
        "vftoi4.xy $vf2, $vf1\n\t"
        "vftoi0.zw $vf2, $vf1\n\t"
        "lui $2, 0x4580\n\t"
        "dsll $2, $2, 16\n\t"
        "ori $2, $2, 0x4580\n\t"
        "dsll $2, $2, 16\n\t"
        "qmtc2 $2, $vf29\n\t"
        "ctc2 $0, $vi16\n\t"
        "vsub.xyw $vf0, $vf1, $vf0\n\t"
        "vsub.xy $vf0, $vf29, $vf1\n\t"
        "vnop\n\t"
        "vnop\n\t"
        "vnop\n\t"
        "vnop\n\t"
        "cfc2 $2, $vi16\n\t"
        "andi $2, $2, 0xc0\n\t"
        "beqz $2, 1f\n\t"
        "nop\n\t"
        "li $2, 0\n\t"
        "li $2, 0x8000\n\t"
        "ctc2 $2, $vi1\n\t"
        "vmfir.w $vf2, $vi1\n"
        "1:\n\t"
        "sqc2 $vf2, 0(%0)\n\t"
        ".set reorder"
        : : "r"(d), "r"(s) : "$2", "memory");
}

// --- 0022e188
// Builds prefix + s + suffix in a static buffer.
extern char D_01dadac0[];
extern char D_003711e8[];
extern char D_003711f8[];
void func_002feee8(char*, const char*);
void func_002ff3fc(char*);  // strlen
char* func_0022e188(const char* s) {
    D_01dadac0[0] = 0;
    func_002feee8(D_01dadac0, D_003711e8);
    func_002feee8(D_01dadac0, s);
    func_002feee8(D_01dadac0, D_003711f8);
    func_002ff3fc(D_01dadac0);  // strlen
    return D_01dadac0;
}

// --- 00239eb8
// Sets the scale x and flags whether the scale differs from (1, 1, 1).
struct S239 {
    u8 pad[184];
    u32 b0 : 1;
    u32 scaled : 1;
    u8 pad2[308 - 188];
    f32 x, y, z;
};
void func_00239eb8(S239* p, f32 v) {
    p->x = v;
    p->scaled = !(v == 1.0f && p->y == 1.0f && p->z == 1.0f);
}

// --- 0023fcd0
// Pops the top entry of a stack and makes its first word current.
struct S23f { u32 a; u32 b; };
extern u32 D_0035ebe8;
extern s32 D_0035ebec;
extern S23f* D_0035ebf0;
void func_002fdd68(u32, u32, u32);
void func_0023fcd0(u32 x) {
    S23f* e = &D_0035ebf0[D_0035ebec];
    func_002fdd68(x, e[-1].a, e[-1].b);
    D_0035ebe8 = e[-1].a;
    D_0035ebec--;
}

// --- 00240a08
struct S240 { u32 a; u32 b; u32 c; };
extern S240* D_0035ec90;
u32 func_002409b8(S240*);
u32 func_00105870(void);
int func_00240a08(S240* p) {
    if (!p) p = D_0035ec90;
    if (func_002409b8(p) != p->c) return 0;
    if (p->a != func_00105870()) return 0;
    return p->b == 0x3a;
}

// --- 00267320
extern u32 D_0035f010;
extern u32* D_0035f0e4;
u32 func_002811b0(u32, int);
u32 func_001a1728(u32, int);
void func_00267320(void) {
    u32 h = func_002811b0(D_0035f010, 0);
    for (int i = 0; i < 6; i++) ((Word*)&D_0035f0e4[i])->u = func_001a1728(h, i);
}

// --- 00272a00
u8* func_00257770(void);
u32 func_00257140(int);
u16* func_00273180(int, int);  // state_dispatch_2_3
u32 func_00192048(u16);
void func_00272a00(void) {
    u8* p = func_00257770() + 24740;
    for (int i = 0; i < 6; i++, p += 436) {
        func_00138c10(p, func_00257140(0));
        *(u32*)(p + 408) = func_00192048(*func_00273180(3, i));
    }
}

// --- 00276438
extern u32 D_0035f200;
int func_002892f8(u32);
int func_0028acc8(u32);
void func_00288e88(u32);
void func_00276438(void) {
    if (!D_0035f200) return;
    int a = func_002892f8(D_0035f200);
    if (func_0028acc8(D_0035f200)) return;
    if (!a) return;
    func_00288e88(D_0035f200);
}

// --- 00288fd8
// Fills the 4 entries of row i of both tables (second one with w, or v if w is 0).
struct S288 { u8 pad[44]; u16* volatile a; u16* volatile b; };
void func_00288fd8(S288* p, int i, int v, int w) {  // anim_store4
    for (int j = 0; j < 4; j++) p->a[i * 4 + j] = v;
    for (int j = 0; j < 4; j++) p->b[i * 4 + j] = w ? w : v;
}

// --- 0028ae28
struct S28a { u8 pad[40]; u8** items; };
void func_00139d78(u8*);
s16* func_0028ac98(S28a*, int);  // lookup_by_index_align
int IsSeqDone_impl(S28a* p, int i) asm("_ZN2Tz6Select9IsSeqDoneEz");
int IsSeqDone_impl(S28a* p, int i) {
    func_00139d78(p->items[i]);
    s16* r = func_0028ac98(p, i);  // lookup_by_index_align
    return *(s32*)(p->items[i] + 388) == r[2];
}

// --- 0028eb88
struct I28e { u8 pad[368]; Word x, y; u8 pad2[4]; };
struct S28e { u8 pad[56]; I28e* items; };
void func_00139d78_28e(S28e*, int) asm("func_00139d78");
void func_0028eb88(S28e* p, int i, f32 a, f32 b) {
    func_00139d78_28e(p, i);
    p->items[i].x.f = a;
    p->items[i].y.f = b;
}

// --- 002b5768
struct VObj { void** vt; u8 pad[432]; VObj* f436; };
extern VObj* D_0035f680[4];
int func_00139d78_2b5(VObj*) asm("func_00139d78");
void LeaveListItemImpl_impl(void) asm("_ZN2Tz8CmSLBase17LeaveListItemImplEv");
void LeaveListItemImpl_impl(void) {
    for (int i = 0; i < 4; i++) {
        if (D_0035f680[i]) {
            if (func_00139d78_2b5(D_0035f680[i])) {
                D_0035f680[i]->f436 = 0;
                (*(void (**)(VObj*))((*(u8**)D_0035f680[i]) + 20))(D_0035f680[i]);
            }
            D_0035f680[i] = 0;
        }
    }
}

// --- 002bc518
struct Node2bc { u8 pad[28]; Node2bc* next; u8 pad2[17]; u8 kind; };
extern Node2bc* D_01e2aa80;
void func_002bbf68(Node2bc*, int);
static inline Node2bc* next2bc(Node2bc* n) {
    if (!n) return D_01e2aa80;
    return n->next;
}
void func_002bc518(void) {
    Node2bc* n = 0;
    while ((n = next2bc(n)) != 0) {
        if (n->kind == 3) func_002bbf68(n, 1);
    }
}

// --- 002bd7d8
extern u32 D_003617ec;
extern u32 D_003617f0;
extern u32 D_003617f4;
extern u8 D_003617f8;
void func_002b8a70(u32);
void func_00102670(u32, u32);  // to_1025f8
void func_002bd7d8(void) {
    func_002b8a70(D_003617ec);
    D_003617ec = 0;
    D_003617f0 = 0;
    func_00102670(D_0032b91c, D_003617f4);  // to_1025f8
    D_003617f4 = 0;
    D_003617f8 = 0;
}

// --- 002cf8c0
union U2cf { u32 w; u16 h[2]; };
struct S2cf { u32 a; u32 b; u32 c; u32 d; U2cf* e; u32 f; u32 pad[3]; u32 g; };
extern S2cf* D_00361fa4;
void func_002cf280(u32*, int, int);
S2cf* func_002cf8c0(int idx, u32 a, u32 b, U2cf* c) {
    S2cf* e = &D_00361fa4[idx];
    e->a = a;
    e->f = b;
    e->c = 0;
    e->e = c;
    e->d = 0;
    e->g = 0;
    if (c->h[1] == 3) func_002cf280(&e->b, 16, 0);
    return e;
}

// --- 002d4a30
void func_0016aef0(u8*, f32*);
void func_002d4a30(u8* p, Vec4* v) {
    f32 t[4];
    t[0] = 1.0f;
    t[3] = t[2] = t[1] = 0.0f;
    func_0016aef0(p, t);
    *(Vec4*)(p + 1344) = *v;
    *(f32*)(p + 1352) = *(f32*)(p + 3056);
}

// --- 002f0b60
struct S2f0 { u8 pad[16]; Vec4 a; Vec4 b; };
void func_00110618(S2f0*);
Vec4* func_0010fa28(S2f0*);  // ptr_add3072
Vec4* func_0010fa58(S2f0*);
void func_002f0b60(u8** pp) {
    S2f0* s = *(S2f0**)(*pp + 4);
    func_00110618(s);
    s->a = *func_0010fa28(s);  // ptr_add3072
    s->b = *func_0010fa58(s);
}

// --- 00304de8
// newlib __sread: read through the reentrant hook, track the offset.
struct File304 { u8 pad[12]; u16 flags; s16 file; u8 pad2[80 - 16]; s32 offset; u32 data; };
long func_00305168(u32, int, void*, int);
int func_00304de8(File304* fp, void* buf, int n) {
    int ret = func_00305168(fp->data, fp->file, buf, n);
    if (ret >= 0) fp->offset += ret;
    else fp->flags &= ~0x1000;
    return ret;
}

// --- 00302c28
// newlib std(): initialise a standard stream.
int func_00304e48(void*, void*, int);
int func_00304ec8(void*, int, int);
int func_00304f30(void*);
struct File302 {
    u8* p; int r; int w;
    short flags; short file;
    u8* base; int size; int lbfsize;
    void* cookie;
    int (*rd)(File304*, void*, int);
    int (*wr)(void*, void*, int);
    int (*sk)(void*, int, int);
    int (*cl)(void*);
    u8 pad[84 - 48];
    void* data;
};
void func_00302c28(File302* f, int flags, int file, void* data) {
    f->p = 0;
    f->r = 0;
    f->w = 0;
    f->flags = flags;
    f->file = file;
    f->base = 0;
    f->size = 0;
    f->lbfsize = 0;
    f->cookie = f;
    f->rd = func_00304de8;
    f->wr = func_00304e48;
    f->sk = func_00304ec8;
    f->cl = func_00304f30;
    f->data = data;
}

// --- 0031bf50
// Constructor: two vtables (multiple inheritance), a member and a member array[7].
struct VT31b { u32 a[4]; };
extern VT31b D_0034a618;
extern VT31b D_00347e60;
void func_00239700(u8*);
void func_0031bf50(u8* p) {
    *(u32*)p = (u32)&D_0034a618;
    *(u32*)(p + 48) = (u32)&D_00347e60;
    *(u32*)(p + 12) = 0;
    *(u32*)(p + 60) = 0;
    func_00239700(p + 72);
    u8* q = p + 456;
    for (int i = 6; i != -1; i--, q += 344) func_00239700(q);
}

}  // extern "C"
