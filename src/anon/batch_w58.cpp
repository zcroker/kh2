#include "../common/types.h"

struct VObj { void** vt; };
typedef void (*VFn)(void*);
struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));

// 128-bit copy.
static inline void cpq(void* d, const void* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}

// An empty-destructor local keeps a cleanup pending, which stops gcc from
// turning the final call into a sibling call.
struct NoTail { ~NoTail() {} };

extern "C" {

extern u8 D_00347e60[];
extern u8 D_00347f98[];
void func_00239870(void*);
s32 func_001bb4a0(void);

// Dispatch on a state byte (2: virtual call on an object, 3: helper), then notify.
u8* func_001040f8(void);
VObj* func_001045f0(void);
void func_00105fc8(void);
u32 func_0014aba8(void);
void func_0014aa58(u32, s32, s32);
void func_00104108(void) {
    switch ((s8)func_001040f8()[3]) {
    case 0:
    case 1:
        return;
    case 2: {
        VObj* o = func_001045f0();
        ((VFn)o->vt[0])(o);
        break;
    }
    case 3:
        func_00105fc8();
        break;
    default:
        return;
    }
    func_0014aa58(func_0014aba8(), 15, 0);
}

// Returns one of two 144-byte table entries indexed by the current slot.
extern u8 D_0033cc44;
extern s32 D_0033cc40;
struct E144 { u8 pad[144]; };
extern E144 D_003a7f70[];
extern E144 D_003a8090[];
E144* func_00106a60(u8 a) {  // buffer_get_by_index
    if (a || D_0033cc44) return &D_003a7f70[D_0033cc40];
    return &D_003a8090[D_0033cc40];
}

// Walks a chunk chain until a chunk with the given tag (or the "_KN5" end tag).
s32 func_00132208(void*);
u32 func_001320b0(void*);  // read_u32_be
void* func_00132130(void*);
void* func_00132180(void* p, u32 tag) {
    for (;;) {
        if (!func_00132208(p) || func_001320b0(p) == 0x354e4b5f) return 0;
        if (func_001320b0(p) == tag) return p;
        p = func_00132130(p);
    }
}

extern u8 D_00348590[];
void func_00239700(void*);
void func_0013b088(u8* p) {
    *(void**)p = D_00348590;
    *(u32*)(p + 12) = 0;
    *(s32*)(p + 236) = -1;
    *(u32*)(p + 240) = 0;
    *(s32*)(p + 244) = -1;
    *(s32*)(p + 248) = -1;
    p[252] = 0;
    p[253] = 0;
    p[254] = 0;
    p[255] = 0;
    *(u32*)(p + 256) = 0;
    *(void**)(p + 260) = D_00347e60;
    *(u32*)(p + 272) = 0;
    func_00239700(p + 284);
    *(u32*)(p + 668) = 0;
    *(u32*)(p + 672) = 0;
    *(u32*)(p + 676) = 0;
    p[680] = 0;
    p[681] = 0;
    *(f32*)(p + 684) = 1.0f;
    *(u32*)(p + 688) = 0;
    *(f32*)(p + 692) = 1.0f;
}

VObj* func_0016b0d0(void);
u8* func_00167f18(s32);
s32 func_0013c698(u8*);
s32 func_0013c8b0(u8*);
s32 func_0013c738(u8* p) {
    if (!p[681]) {
        p[681] = 1;
        return 0;
    }
    VObj* o = func_0016b0d0();
    if (o && ((s32 (*)(void*))o->vt[16])(o)) {
        if (*(u64*)(func_00167f18(0) + 8)) return 1;
    }
    if (func_0013c698(p)) return 1;
    return func_0013c8b0(p) != 0;
}

// Axis-aligned box (min xyz, max xyz) around a sphere (center xyz, radius at +16).
void func_00144570(f32* box, u8* s) {
    Vec4 v;
    if ((void*)&v != s) cpq(&v, s);
    f32 r = *(f32*)(s + 16);
    box[0] = v.x - r;
    box[1] = v.y - r;
    box[2] = v.z - r;
    box[3] = v.x + r;
    box[4] = v.y + r;
    box[5] = v.z + r;
}

// Clip-tests 8 points against the matrix m: 0 = all outside one plane,
// 2 = partially clipped, 1 = all inside.
s32 func_001466b0(Vec4* m, Vec4* v) {  // mat4_transform_vecs
    u32 orr = 0, andd = 63;
    for (s32 i = 0; i < 8; i++, v++) {
        u32 c;
        asm volatile("lqc2 $vf8,0(%1)\n\tlqc2 $vf4,0(%2)\n\tlqc2 $vf5,16(%2)\n\tlqc2 $vf6,32(%2)\n\tlqc2 $vf7,48(%2)\n\t"
            "vmulax.wxyz ACC,$vf4,$vf8x\n\tvmadday.wxyz ACC,$vf5,$vf8y\n\tvmaddaz.wxyz ACC,$vf6,$vf8z\n\tvmaddw.wxyz $vf12,$vf7,$vf8w\n\t"
            "vclipw.xyz $vf12,$vf12w\n\tvnop\n\tvnop\n\tvnop\n\tvnop\n\tcfc2.ni %0,$vi18"
            : "=r"(c) : "r"(v), "r"(m));
        c &= 0x3f;
        orr |= c;
        andd &= c;
        if (andd == 0 && orr != 0) return 2;
    }
    return andd == 0;
}

void func_00141010(f32);
u8* func_00140df0(void);
void func_0014e658(u8*);
void func_0014e6f8(u8*);
void func_0014e8b8(u8*);
extern u32 D_0034a3f4;
extern u32 D_0034a3f0;
extern f32 D_0034a3f8;
void func_0014eb48(u32 a, u32 b, f32 c) {
    func_00141010(30.0f);
    u8* o = func_00140df0();
    *(s32*)(o + 64) = 9;
    D_0034a3f0 = a;
    D_0034a3f4 = b;
    D_0034a3f8 = c;
    func_0014e658(o);
    func_0014e6f8(o);
    func_0014e8b8(o);
}

// Init a node and append it to the global list.
struct Nd12 { u32 f0; void* f4; u32 f8; Nd12* next; };
struct L12 { Nd12* head; Nd12* tail; };
extern L12 D_004f41c0;
extern union { u32 v; u8 c; } D_0034c7a4;
void func_001656c0(Nd12*);
void* func_001063c0(u32, u32);
void func_001415e8(void*, u32, s32);
void func_001656d0(Nd12* n, u32 a1, u32 a2) {
    func_001656c0(n);
    n->f0 = a2;
    void* o = func_001063c0(224, D_0034c7a4.v);
    func_001415e8(o, a1, -1);
    n->f4 = o;
    asm volatile("" ::: "memory");
    if (!D_004f41c0.tail) { D_004f41c0.tail = n; D_004f41c0.head = n; n->next = 0; }
    else { D_004f41c0.tail->next = n; n->next = 0; D_004f41c0.tail = n; }
}

// p[0] = p[0] + p[1] (vector), returned through a function-local static.
extern s8 D_004f62b0;
extern Vec4 D_004f62c0;
void func_002fd188(void (*)(void));  // pool_alloc_block
void func_0016e878(void);
void func_0016d340(Vec4** p) {
    Vec4* a = p[0];
    Vec4* b = p[1];
    if (!D_004f62b0) {
        D_004f62b0 = 1;
        func_002fd188(func_0016e878);  // pool_alloc_block
    }
    Vec4 t;
    asm volatile("lqc2 $vf1,0(%1)\n\tlqc2 $vf2,0(%2)\n\tvadd.xyzw $vf1,$vf1,$vf2\n\tsqc2 $vf1,0(%0)"
        : : "r"(&t), "r"(a), "r"(b) : "memory");
    if (&t != &D_004f62c0) cpq(&D_004f62c0, &t);
    p[0] = &D_004f62c0;
}

u32 func_001de168(u32, u32, u32, u32, u32, u32);  // scan_list_by_half
void func_00174858(u32* p) {
    p[0] = func_001de168(p[0], p[1], p[3], 1, p[4], ((u32*)p[2])[1]);  // scan_list_by_half
}

void func_0016b668(u8*);
void func_00175a70(u8* p) {
    if (!(*(u32*)(p + 264) & 0x10000000)) ((VFn)(*(VObj*)p).vt[8])(p);
    VObj** a = (VObj**)(p + 2808);
    for (s32 i = 1; i >= 0; i--) {
        VObj* o = *a++;
        if (o) ((VFn)o->vt[10])(o);
    }
    func_0016b668(p);
}

extern u32* D_01c60888;
u8* func_001a80c8(u32);  // table24_find_by_id
u32 func_00185890(s32 a, u32 b) {
    if (a == 0 || b == 0 || D_01c60888[a] == 0) return 0;
    u8* v = func_001a80c8(b);  // table24_find_by_id
    u32* t = D_01c60888;
    u32* q = &t[t[a]];
    return q[*(u16*)(v + 4)];
}

void func_00114580(u8*);
void func_001888c8(u8* p) {
    p[4] = 100;
    p[5] = 100;
    p[6] = 100;
    p[7] = 100;
    p[9] = 0;
    p[10] = 0;
    p[11] = 0;
    p[12] = 0;
    p[13] = 0;
    p[14] = 0;
    p[15] = 1;
    p[16] = 1;
    p[17] = 1;
    p[18] = 0;
    u16* h = (u16*)(p + 84);
    for (s32 i = 79; i != -1; i--) *h++ = 0;
    func_00114580(p + 244);
}

// Puts id v into the first free slot of a, borrowing it from b if present.
struct S188 { u8 pad[18]; u8 n; u8 pad2[33]; u16 a[8]; u16 b[8]; };
void func_00188a28(S188* p, u32 v) {
    s32 i, j;
    for (i = 0; i < p->n; i++) {
        if (p->a[i] == 0) {
            if (p->b[i] == v) { p->a[i] = v; return; }
            if (p->b[i] == 0) {
                for (j = 0; j < p->n; j++) {
                    if (p->b[j] == v) { p->b[i] = v; break; }
                }
                p->a[i] = v;
                return;
            }
        }
    }
}

u32* func_001b6fb0(u32, u32);
extern u32 D_0032f210;
s32 func_00188bb0(u8* p, u32 a) {
    u8 n = p[15];
    if (n >= 99) return 0;
    return *func_001b6fb0(a, n) - D_0032f210;
}

void* func_00186078(void*);
u8* func_0016bba8(void*, s32, u8*);
void func_001a4388(void) {
    VObj* o = 0;
    while ((o = (VObj*)func_00186078(o)) != 0) {
        if (*(u32*)((u8*)o + 268) & 0x100000) continue;
        u8* e = 0;
        while ((e = func_0016bba8(o, 13, e)) != 0)
            ((void (*)(void*, u16, u8, void*, s32))o->vt[20])(o, *(u16*)(e + 2), e[0], o, 0);
    }
}

// CRC-16/CCITT of a string, processed from the last character backwards.
u32 func_002ff3fc(const char*);  // strlen
u16 func_001ae270(const char* s) {
    u16 crc = 0xffff;
    u32 n = func_002ff3fc(s);  // strlen
    const s8* p = (const s8*)s + n - 1;
    for (u32 i = 0; i < n; i++) {
        crc ^= *p-- << 8;
        for (s32 j = 7; j >= 0; j--) {
            if (crc & 0x8000) crc = (crc << 1) ^ 0x1021;
            else crc = crc << 1;
        }
    }
    crc = ~crc;
    return crc;
}

struct Nd20 { f32 f0; u32 f4; u32 f8; u32 f12; u32 f16; Nd20* next; };
struct L20 { Nd20* head; Nd20* tail; };
extern L20 D_01d48de0;
u32 func_0016a070(u32);
s32 func_001a3888(u32);  // id_in_range_5_7_131
void func_001ba1f8(Nd20* n, u32 a1, u32 a2, u32 a3) {
    n->f4 = a2;
    n->f8 = a1;
    n->f0 = 30.0f;
    n->f12 = func_0016a070(a1);
    if (func_001a3888(n->f4)) a3 = 0;
    asm volatile("" ::: "memory");
    n->f16 = a3;
    if (!D_01d48de0.tail) { D_01d48de0.tail = n; D_01d48de0.head = n; n->next = 0; }
    else { D_01d48de0.tail->next = n; n->next = 0; D_01d48de0.tail = n; }
}

u32 func_001b8e88(u16);
void func_001bd918(u8*, u32, s32);
void func_001bd8c8(u8* p) {
    NoTail g;
    u8* t = **(u8***)(p + 2240);
    s32 off = *(s32*)(t + 108) * 12;
    func_001bd918(p, func_001b8e88(*(u16*)(t + off + 14)), 0);
}

// Fills 8 angles (k * 2pi/8) into a 16-byte-stride table.
void func_001db8f8(void*, u32, s32, s32);
extern u8 D_00351618[];
struct E16f { u8 pad[12]; f32 v; };
extern E16f D_01d49590[];
void func_001c4498(u8* p, u32 a1) {
    func_001db8f8(p, a1, 0, 1500);
    *(void**)p = D_00351618;
    for (s32 i = 0; i < 8; i++) D_01d49590[i].v = (f32)i * 0.125f * 6.2831855f;
}

u32* func_001d3350(void*, s32);
void func_001d3388(u32);
extern u8 D_01d5ba10[];
u32 func_001d3390(u32 a) {
    u32* r = func_001d3350(D_01d5ba10, 0);
    func_001d3388(a);
    *r = a;
    return a;
}

void func_001d6a28(u8*);
void func_0019ca20(u8*);
void func_0013dde8(s32);
void func_001befa8(u8*);
extern u32 D_003527e0;
void func_001d69d0(u8* p) {
    func_001d6a28(p);
    func_0019ca20(p + 2752);
    if (*(u32*)(*(u8**)(p + 2804) + 1164)) func_0013dde8(0);
    func_001befa8(p);
    *(u32*)(p + 2804) = 0;
    D_003527e0 = 0;
}

struct E16b { u8 pad[16]; };
extern E16b D_0036e600[];
extern u32 D_0036e620[];
extern u32 D_003527e4;
u8* func_001a5420(u32, void*, u32);
void func_001d76c8(void);
void func_001d8718(u32, s32);
u8* func_001ba158(void);
void func_001d7638(u32 a0, s32 i) {
    u8* r = func_001a5420(D_003527e4, &D_0036e600[i], a0);
    if (!r) return;
    u32 v = D_0036e620[i];
    *(void**)(r + 16) = (void*)func_001d76c8;
    if (!func_001bb4a0()) return;
    func_001d8718(v, 0);
    *(u32*)(func_001ba158() + 4) += v;
}

u8* func_001bbcb0(void);
void func_001d8fa8(u8 on, s32 i) {
    if (!func_001bb4a0()) return;
    u8* e = func_001bbcb0() + i * 52;
    u8 f = *(volatile u32*)(e + 412) & 1;
    if (!f) return;
    VObj* o = (VObj*)(e + 400);
    if (on) ((VFn)o->vt[3])(o);
    else ((VFn)o->vt[4])(o);
}

void func_001dcfb0(void);
void func_001dd208(s32);
extern VObj* D_01d5bb00;
extern u32 D_01d5bb04;
extern u32 D_01d5bb08;
extern u8 D_00352af0;
void func_001dced0(void) {
    func_001dcfb0();
    if (D_01d5bb04) {
        ((void (*)(void*, u32))D_01d5bb00->vt[1])(D_01d5bb00, D_01d5bb04);
        D_01d5bb04 = 0;
    }
    if (D_01d5bb08) {
        ((void (*)(void*, u32))D_01d5bb00->vt[1])(D_01d5bb00, D_01d5bb08);
        D_01d5bb08 = 0;
    }
    func_001dd208(0);
    D_00352af0 = 0;
}

void func_002bc358(s32, s32);
void func_001dee10(u8*);
void func_001de978(u8*);
void func_001e0058(u8* p) {
    s32 h = *(s32*)(p + 84);
    if (h >= 0) func_002bc358(h, 120);
    if (p) {
        func_001dee10(p);
        func_001de978(p);
    }
}

// Frees up to three buffers from the current heap, then clears the heap.
void func_00102670(u32, u32);  // to_1025f8
extern u32 D_0035de3c;
extern u32 D_0035de30;
extern u32 D_0035de34;
extern u32 D_0035de38;
extern u8 D_0035de27;
void func_00228240(void) {
    if (!D_0035de3c) return;
    if (D_0035de30) {
        func_00102670(D_0035de3c, D_0035de30);  // to_1025f8
        D_0035de30 = 0;
    }
    if (D_0035de34) {
        func_00102670(D_0035de3c, D_0035de34);  // to_1025f8
        D_0035de34 = 0;
    }
    if (D_0035de38 && !D_0035de27) {
        func_00102670(D_0035de3c, D_0035de38);  // to_1025f8
        D_0035de38 = 0;
    }
    D_0035de3c = 0;
}

// Selects the first entry flagged 0x10 and copies its name; returns its index or -1.
struct Ent40 { u32 flags; u32 pad; u8 name[32]; };
struct Tbl40 { s32 n; s32 cur; Ent40 e[1]; };
extern union { Tbl40* p; s32 i; } D_0035ec98;
extern union { u32 v; u8 c; } D_0035ec88;
void func_002ff2e8(u32, void*);
s32 func_00241358(void) {
    s32 n = D_0035ec98.p->n;
    s32 i;
    for (i = 0; i < n; i++) {
        if (D_0035ec98.p->e[i].flags & 0x10) {
            D_0035ec98.p->cur = i;
            func_002ff2e8(D_0035ec88.v, D_0035ec98.p->e[i].name);
            break;
        }
    }
    return i < n ? i : -1;
}

// Tz::PauseTaskIsDone
s32 func_00287bc0(void);
s32 func_00287db0(void);
void func_001039f8(void);
void func_0026e638(void*);
void func_0026e8a0(void);
s32 PauseTaskIsDone(void* a) asm("_ZN2Tz15PauseTaskIsDoneEz");
s32 PauseTaskIsDone(void* a) {
    s32 m = func_00287bc0();
    if (func_00287db0()) {
        func_001039f8();
        return 1;
    }
    switch (m) {
    case 0: func_0026e638(a); break;
    case 1: func_0026e8a0(); break;
    }
    return 0;
}

s32 func_0027ae20(void);
void func_0027aed8(s32 a, s32* o1, s32* o2) {
    if (a == 0) {
        *o1 = 0;
        *o2 = 0;
        return;
    }
    s32 n = func_0027ae20();
    if (n != 0 && a < n + 1) {
        *o1 = 1;
        *o2 = a - 1;
    } else {
        *o1 = 0;
        *o2 = a - n;
    }
}

s32 func_00168aa0(u32, u32);
u8* func_00168b38(u32, u32, s32);  // entry_array_find_nth
void func_00290960(u8* p, u32 a, u32 b) {
    *(u32*)(p + 4) = a;
    *(s32*)(p + 8) = func_00168aa0(a, b);
    for (s32 i = 0; i < *(s32*)(p + 8); i++)
        (*(u32**)(p + 20))[i] = *(u32*)(func_00168b38(*(u32*)(p + 4), b, i) + 8);  // entry_array_find_nth
}

void func_002b7fbc(s32);
void func_002bced8(void*);
void func_002bcee8(void*);
void func_002b9b78(void);
void func_002ba390(void);
void func_002bc798(void);
void func_002ba9c0(void);
void func_002bc470(s32);
void func_002baa60(void);
void func_002bc608(s32);
void func_002bbf98(void);
extern u8 D_01e2a410[];
void func_002b9fb0(void) {
    func_002b7fbc(1);
    func_002bced8(D_01e2a410);
    func_002bcee8(D_01e2a410);
    func_002b9b78();
    func_002ba390();
    func_002bc798();
    func_002ba9c0();
    func_002bc470(2);
    func_002bc470(3);
    func_002baa60();
    func_002bc608(0);
    func_002bc608(1);
    func_002bc608(2);
    func_002bbf98();
}

// Init a node with a fresh nonzero id and append it to the global list.
struct Nd28 { u8 pad[20]; s32 id; u8 pad2[4]; Nd28* next; u8 pad3[4]; s32 f36; u16 h40 : 16; u8 pad4[2]; u16 h44 : 16; u8 pad5[2]; u8 b48; u8 b49; };
struct L28 { Nd28* head; Nd28* tail; };
extern L28 D_01e2aa80;
extern s32 D_003616e8;
void func_002bb100(Nd28* n, s32 a1, s32 a2) {  // next_global_id
    s32 id = D_003616e8;
    n->id = id;
    D_003616e8 = ++id;
    if (id == 0) D_003616e8 = 1;
    n->b49 = a2;
    n->f36 = 0;
    n->b48 = 1;
    if (a1 == 1) n->f36 = 2;
    n->h40 = 16383;
    n->h44 = 64;
    L28* L = &D_01e2aa80;
    if (!L->tail) { L->tail = n; L->head = n; n->next = 0; } else { L->tail->next = n; n->next = 0; L->tail = n; }
}

void func_002be770(u8*);
extern u8 D_00361b20[];
void func_002c1a58(u8* p) {
    func_002be770(p);
    p[2792] = 0;
    *(void**)p = D_00361b20;
    *(u32*)(p + 1420) |= 1;
    *(u32*)(p + 2788) = 0;
}

void func_002df160(u32);
Vec4* func_0016c028(u32);  // obj_get_attach_or_alt
f32 func_002df1a0(u32);
void func_0016ace0(u32, Vec4*);
extern f32 D_00375d40;
void func_002deb18(u32 a0, u32 a1) {
    Vec4 v;
    func_002df160(a0);
    cpq(&v, func_0016c028(a1));  // obj_get_attach_or_alt
    f32 r = func_002df1a0(a0);
    v.z = 0;
    v.y = -r * 100.0f - D_00375d40;
    func_0016ace0(a1, &v);
}

s32 func_002eb3b8(u32);
s32 func_002eb098(u32);
void func_002eb1a0(u32);
extern f32 D_01e2c060;
extern f32 D_00349e10;
void func_002ecb10(u32 a0, u32 a1) {
    if (func_002eb3b8(a1)) return;
    D_01e2c060 += D_00349e10;
    if (10.0f < D_01e2c060 || func_002eb098(a1)) func_002eb1a0(a1);
}

extern u32 D_00363748;
u8* func_002ed350(u32, u32, u32, Vec4*, Vec4*);
u8* func_002ed4b8(u32 a0, u32 a1, Vec4* a2, Vec4* a3) {
    Vec4 b, c;
    cpq(&b, a3);
    cpq(&c, a2);
    u8* r = func_002ed350(D_00363748, a0, a1, &c, &b);
    return r ? r + 48 : 0;
}

// Destructor chain: own vtable, members, base parts, then unregister.
struct Mgr { u8 pad[20]; VObj* f20; };
extern u8 D_003486b0[];
extern union { Mgr* p; u8 c; } D_00347f80;
void func_0031b858(u8* p) {
    *(void**)p = D_003486b0;
    *(void**)(p + 448) = D_00347e60;
    func_00239870(p + 472);
    *(void**)p = D_00347e60;
    *(void**)(p + 448) = D_00347f98;
    func_00239870(p + 24);
    *(void**)p = D_00347f98;
    VObj* o = D_00347f80.p->f20;
    ((void (*)(void*, void*))o->vt[1])(o, p);
}

// Destructor: 7 344-byte members destroyed in reverse through their vtables.
extern u8 D_0034a618[];
void func_0031c668(u8* p) {
    *(void**)p = D_0034a618;
    if ((s32)p != -456) {
        u8* e = p + 2864;
        for (;;) {
            if (p + 456 == e) break;
            e -= 344;
            ((VFn)(*(VObj*)e).vt[0])(e);
        }
    }
    *(void**)(p + 48) = D_00347e60;
    func_00239870(p + 72);
    *(void**)(p + 48) = D_00347f98;
    *(void**)p = D_00347f98;
}

extern u8 D_0034aad8[];
void func_002361d0(void*);
void func_0031d8a0(u8* p) {
    *(void**)p = D_0034aad8;
    func_002361d0(p + 416);
    *(void**)p = D_00347e60;
    func_00239870(p + 24);
    *(void**)p = D_00347f98;
}

}
