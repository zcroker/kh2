#include "../common/types.h"

#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

extern "C" {
u32 wtarget_00109450(s32, s32, u32, u32) asm("_Z16wtarget_00109450jjjj");
void wtarget_002e2e50(u32, u32, u32, u32) asm("_Z16wtarget_002e2e50jjjj");

struct Obj;
typedef void (*ObjFn)(Obj*, ...);
struct Obj {
    ObjFn* vt;
};
struct NoTail {
    ~NoTail() {}
};
struct Vec4 {
    f32 x, y, z, w;
} __attribute__((aligned(16)));

void func_0011e350(u8*, u32);
void func_0011c438(u8*);
Obj* func_0011e7e0(u32, Obj*, u32, u32, u32);
void func_00135c50(u8*, u32);
void func_00135ad0(u8*);
void func_001391c8(u8*, u32, u32);
void func_002362b0(u8*, u32);
void func_002367c8(u8*);
u32 func_00140dc0(void);
extern u8 D_00348710[];
void func_0013fd78(u8*);
void func_0013f558(u8*);
void func_00140b68(u8*, u32);
extern u8 D_004574d0[];
void func_002f2aa0(u8*, s16, u32, u32, u32, u32, s16, s16);
void func_003058a0(u32);
void func_002f25a0(u32, u32);
void func_002f2d60(u8*, u32);

struct Node11c {
    u8 pad[12];
    Node11c* next;
};

// Releases the pending handle and every queued node, then tears down.
void func_0011c328(u8* p) {
    if (*(u32*)(p + 40)) {
        Obj* o = *(Obj**)(p + 16);
        o->vt[1](o, *(u32*)(p + 40));
        *(u32*)(p + 40) = 0;
    }
    Node11c* n = *(Node11c**)(p + 292);
    while (n) {
        Obj* o = *(Obj**)(p + 16);
        Node11c* next = n->next;
        o->vt[1](o, n);
        n = next;
    }
    NoTail nt;  // keeps the last call a jal
    func_0011e350(p, *(u32*)(p + 56));
    func_0011c438(p);
}

// Visits every match from func_0011e7e0 and calls its slot-4 virtual.
void func_0011e880(u32 a, u32 b, u32 c, u32 d) {
    Obj* o = 0;
    while ((o = func_0011e7e0(a, o, b, c, d)) != 0) o->vt[4](o, c, d);
}

struct Stack135 {
    u8 pad[12];
    s32 count;
    u32 items[32];
};
// Pushes v; when full (32), flushes first.
void func_00135bd0(Stack135* p, u32 v) {
    func_00135c50((u8*)p, v);
    s32 n = p->count;
    if (n == 32) {
        func_00135ad0((u8*)p);
        if (p->count == n) func_00135c50((u8*)p, p->items[0]);
    }
    p->items[p->count++] = v;
}

void func_00138650(u8* p, u32 a, u32 b, u32 c) {
    func_001391c8(p, a, c);
    func_002362b0(p + 32, b);
    func_002367c8(p + 32);
}

void func_00140f78(u8* a, u8* b) {
    u32 v = func_00140dc0();
    u8* g = D_00348710;
    *(u32*)(g + 64) = 0;
    func_0013fd78(g);
    func_0013f558(g);
    func_00140b68(g, 1);
    if (a != g + 16) QCOPY(a, g + 16);
    if (b != g) QCOPY(b, g);
    *(u32*)(g + 64) = v;
}

void func_0014dec0(s16* a, u32 b) {
    func_002f2aa0(D_004574d0, (u16)a[0] << 5, (u16)a[2] >> 6, 1, 0, 0, a[2], a[3]);
    func_003058a0(0);
    func_002f25a0(0, 0);
    func_002f2d60(D_004574d0, b);
}

struct Job168 {
    u8 pad0[4];
    s32 state;
    u8 ctx[44];
    u32 f52;
    u8 pad56[8];
    u32 result;
    u32 f68;
    u16 pad72;
    u16 n;
};
Job168* func_00168218(void);
void func_0014d430(void);
u32 func_001682f0(void*, u32, u32, u32);
u32 func_001682b8(void*, u32);

// Worker loop: runs queued jobs forever.
void func_001685f0(void) {
    for (;;) {
        func_003058a0(0);
        Job168* j;
        while ((j = func_00168218()) != 0) {
            j->state = 1;
            if (j->n) j->result = func_001682f0(j->ctx, j->f52, j->f68, j->n);
            else j->result = func_001682b8(j->ctx, j->f52);
            j->state = 2;
        }
        func_0014d430();
    }
}

void func_0016ace0(u8*);
void func_0016adc8(u8* p) {
    *(u32*)(p + 264) |= 0x200000;
    func_0016ace0(p);
    if (*(u32*)(p + 1416) & 2) {
        // zero the 128-bit vector at +2768
        asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(p + 2768) : "memory");
    }
}

f32 func_0016b0e0(u32, u32, f32*);
// out = m * v (VU0 matrix * vector)
#define MULV(m, v, out) asm volatile( \
    "lqc2 $vf5, 0(%1)\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tlqc2 $vf4, 48(%0)\n\t" \
    "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\t" \
    "vmaddw.xyzw $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%2)" : : "r"(m), "r"(v), "r"(out) : "memory")

Vec4* func_0016b478(Vec4* out, f32 s, u32 a, u32 b) {
    f32 m[16] __attribute__((aligned(16)));
    Vec4 t;
    f32 f = func_0016b0e0(a, b, m);
    out->y = 0.0f;
    out->z = 0.0f;
    out->w = 1.0f;
    out->x = f * s;
    MULV(m, out, &t);
    if (out != &t) QCOPY(out, &t);
    return out;
}

extern Vec4 D_01c5f480;
struct Ref173 {
    u32* a;
    u32 b;
    Vec4* v;
};
void func_00173ce8(Ref173* p) {
    f32 m[16] __attribute__((aligned(16)));
    Vec4 t;
    func_0016b0e0(*(u32*)((u8*)p->a + 4), p->b, m);
    MULV(m, p->v, &t);
    if (&t != &D_01c5f480) QCOPY(&D_01c5f480, &t);
    p->a = (u32*)&D_01c5f480;
}

u32 func_00198510(u8*);
u32 func_001759f0(u8* p) {
    if (!func_00198510(p)) return 0;
    u32** a = (u32**)(p + 2808);
    s32 i;
    for (i = 0; i < 2; i++) {
        u32* o = *a++;
        if (o && !((u32 (*)(void*))(((u32*)*o)[9]))(o)) return 0;
    }
    return 1;
}

// Sets and normalizes the direction at +2176 (VU0), stores f at +2188.
void func_001846a0(u8* p, Vec4* v, f32 f) {
    Vec4* d = (Vec4*)(p + 2176);
    if (d != v) QCOPY(d, v);
    asm volatile("lqc2 $vf1, 0(%0)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\t"
                 "vsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, $f0\n\tvnop\n\t"
                 "vdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(d) : "$8", "$f0", "memory");
    *(f32*)(p + 2188) = f;
}

u32 func_00188398(u8*, u32, u32*, u32);
u32 func_00188340(u8* p, s32 i, u32* a2, u32 a3) {
    u8* t = *(u8**)(p + 144);
    if (!t) return 0;
    if (*(u32*)(p + 156) & 4) return 0;
    u32 tmp;
    if (!a2) {
        tmp = *(u32*)(p + 136);
        a2 = &tmp;
        a3 = 1;
    }
    return func_00188398(p, *(u16*)(t + i * 2 + 10), a2, a3);
}

void func_00195430(u8*);
void func_00195558(u8* p) {
    u8* q;
    for (q = p; (s32)q < (s32)(p + 2080); q += 520) func_00195430(q);
    *(u32*)(p + 2084) = 0;
}

void func_00190128(void*);
void* func_001d45a0(u32, u16);
void func_00190878(void*, u32, u32);
void func_0019da68(u8*, void*, void*, u32, u32);
u32 func_0019ead0(u8* p, u32 b) {
    u8 buf[32];
    void* o = func_001d45a0(b, *(u16*)(*(u8**)p + 38));
    if (o) {
        func_00190128(buf);
        func_00190878(buf, b, 0);
        func_0019da68(p, o, buf, 0, 0);
        return 1;
    }
    return 0;
}

struct E1b8 {
    u8 id;
    u8 pad[3];
    u32 key;
    u32 c, d;
};
struct T1b8 {
    u32 a;
    s32 n;
    E1b8 e[1];
};
extern T1b8* D_01d48d90;
void func_001b8838(u8);
void func_001b8ce0(u32 key) {
    E1b8* e = D_01d48d90->e;
    s32 i;
    for (i = 0; i < D_01d48d90->n; i++, e++) {
        if (e->key == key) func_001b8838(e->id);
    }
}

extern u8** D_01d49320;
void func_001bb468(void);
void func_001af2e8(void);
void func_001af360(u32);
void func_001bbc30(void) {
    u8 k = (*(u8**)(D_01d49320 + 2))[8];
    func_001bb468();
    switch (k) {
    case 2:
    case 30:
    case 35:
        func_001af360(0);
        break;
    default:
        func_001af2e8();
        break;
    }
}

s32 func_001c8bb8(s8*);
u64 func_00312db8(u64, u64);  // libgcc 64-bit unsigned divide
extern u32 D_003638d0;
// Picks a random entry from the list filled by func_001c8bb8.
s8 func_001c8c38(void) {
    s8 buf[16];
    s32 n = func_001c8bb8(buf);
    u32 seed = D_003638d0 * 69069;
    D_003638d0 = seed;
    u64 step = func_00312db8((u64)(u32)(n - 1) + 0x100000000ULL, (u32)n);
    return buf[(s32)func_00312db8(seed, step)];
}

u32 func_001e6b90(void);
u32 func_001e6c40(u32, u32, u32, u32, f32);
void func_001e2c00(u32);
void func_001e6c00(u32);
s32 func_001dc558(u32* p, f32 f) {
    s32 ok = 1;
    if (p[1] != 4) {
        p[7] = func_001e6b90();
        ok = func_001e6c40(p[7], p[5], p[6], p[4], f) != 0;
    }
    if (!ok && p[7]) {
        func_001e2c00(p[7]);
        func_001e6c00(p[7]);
        p[7] = 0;
    }
    return ok;
}

void func_002fe0a0(const char*);
void func_002fd348(s32) __attribute__((noreturn));
extern char D_00370748[];
void func_0020e2e8(u32, u8, u16, u32);
void func_0020e548(u8* p, u32 b) {
    if (!*(u32*)(p + 4)) {
        func_002fe0a0(D_00370748);
        func_002fd348(1);
    }
    func_0020e2e8(*(u32*)(p + 4), p[9], *(u16*)p, b);
}

extern u8* D_0035dcf0;
void func_002278e0(u8*);
void func_00227078(void) {
    s32 i;
    if (!D_0035dcf0) return;
    for (i = 0; i < 128; i++) {
        u8* e = (u8*)(i * 84 + (u32)D_0035dcf0);
        u32 st = *(u32*)(e + 4);
        if (st == 0) continue;
        if (st == 2) func_002278e0(e);
    }
}

u32 func_002282f0(s16);
u32 func_002ba620(void);
void func_002319c0(s16);
extern u8 D_0035de0a[];
extern u8 D_0035de0c[];
extern s32 D_0035de10;
void func_00232070(s16* p) {
    if (func_002282f0(p[2])) return;
    D_0035de0a[0] = 1;
    s32 m = p[3];
    D_0035de10 = m;
    if (m != 0) {
        if (m == 1) func_002319c0(p[2]);
    } else if (!func_002ba620()) {
        D_0035de0c[0] = 1;
    }
}

void func_002368e8(u8*, f32);
void func_00236bb8(u8* p, f32 f) {
    s32 i;
    for (i = 0; i < *(s32*)(p + 16); i++) {
        func_002368e8(*(u8**)(p + 20) + i * 416, f);
        func_002367c8(*(u8**)(p + 20) + i * 416);
    }
}

extern u32 D_00349e1c;
extern u8 D_00349e20;
extern u32 D_0035eb54;
extern u8 D_0035eb50;
void func_0014ce20(u32);
void func_0014ce30(u32);
void func_0023d320(void) {
    D_0035eb54 = D_00349e1c;
    D_0035eb50 = D_00349e20 == 0;
    if (D_0035eb50) func_0014ce20(1);
    func_0014ce30(0);
}

u8* func_001a80c8(u32);
s32 func_001a6598(u16);
s32 func_00257158(u32 id, s32 a, u8 b) {
    if (!id) return 0;
    u8* e = func_001a80c8(id);
    u8 t = e[2];
    if (t == 0) {
        if (b) {
            s32 r = 3;
            if (a) r = 0;
            return r;
        }
        return 0;
    }
    if (t == 18) return func_001a6598(*(u16*)(e + 4)) == 2 ? b != 0 : 0;
    return 0;
}

u8* func_001a8110(u8*);
u32 func_001a3820(u16);
u32 func_00271870(u32 key) {
    u8* e = 0;
    u32 r = 0;
    if (!key) return 0;
    while ((e = func_001a8110(e)) != 0) {
        if (e[2] == 18 || e[2] == 0) {
            if (func_001a3820(*(u16*)e) == key) {
                r = *(u16*)e;
                break;
            }
        }
    }
    return r;
}

extern u8* D_0035f21c;
u32 func_00139d78(u8*);
u32 func_00276b90(void) {
    s32 i;
    u32 r = 0;
    u8* q;
    for (i = 0; i < 32; i++) {
        q = D_0035f21c;
        if (func_00139d78(q + i * 408 + 0xa998)) {
            r = 1;
            break;
        }
    }
    return r;
}

void func_00290580(u8*);
void func_00138c10(u8*, s16);
void func_00290438(u8* p) {
    func_00290580(p);
    u8* o = *(u8**)p;
    s16 k = *(s16*)(p + 12);
    if (*(s32*)(o + 388) != k) {
        func_00138c10(o, k);
        *(s32*)(*(u8**)p + 392) = -1;
    }
}

u8* func_002a9d68(u32, u32);
u32 func_002aa5b8(u32, u32);
// Sets bit `bit` in row a of the bitmap at +68.
void func_002aa8e0(s32 a, u32 b) {
    u32* base = (u32*)func_002a9d68(a, b);
    u32 bit = func_002aa5b8(a, b);
    u32* row = &base[a + 17];
    u32 m = 1 << (bit & 31);
    if (!(row[bit >> 5] & m)) row[bit >> 5] |= m;
}

extern u8* D_0035f620;
// True when flags 0..12 are all set.
u32 func_002ad338(void) {
    u32* bits = (u32*)(D_0035f620 + 316);
    s32 i;
    u32 r = 1;
    for (i = 0; i < 13; i++) {
        if (!(bits[(u32)i >> 5] & (1 << (i & 31)))) {
            r = 0;
            break;
        }
    }
    return r;
}

extern u8* D_0035f680[4];
u32 func_002b56e8(void) {
    s32 i;
    u32 r = 0;
    for (i = 0; i < 4; i++) {
        u8* o = D_0035f680[i];
        if (o && func_00139d78(o)) {
            r = 1;
            break;
        }
    }
    return r;
}

void func_00161000(u8);
void func_00160fd0(u8);
void func_002c1cb0(u8* c, s32 mode) {
    switch (mode) {
    case 1:
        func_00160fd0(c[0]);
        func_00161000(c[1]);
        func_00161000(c[2]);
        break;
    case 2:
        func_00161000(c[0]);
        func_00160fd0(c[1]);
        func_00160fd0(c[2]);
        break;
    default:
        func_00161000(c[0]);
        func_00161000(c[1]);
        func_00161000(c[2]);
        break;
    }
}

// Wraps an angle into [-pi, pi].
f32 func_002d0e10(f32 a) {
    if (0.0f < a) {
        while (3.1415927f < a) a -= 6.2831855f;
    } else {
        while (a < -3.1415927f) a += 6.2831855f;
    }
    return a;
}

void func_002e7458(u8*);
void func_002e7568(u8*, u32, u8*, f32);
extern u8 D_00362190[];
void func_002d4868(u8* p) {
    func_002e7458(p + 3208);
    func_002e7568(p, 2, D_00362190, 1.0f);
    *(u32*)(p + 2876) = 0;
}

void func_002def70(u8*, u32);
u8* func_002dc7c8(u32);
void func_002deac0(u8*, f32, f32);
void func_002deba0(u8*, u32, f32, f32);
extern u32 D_00361f60;
void func_002df470(u8* p, u32 b) {
    func_002def70(p, b);
    u32 g = D_00361f60;
    u8* a1 = func_002dc7c8(g);
    u8* a2 = func_002dc7c8(g);
    func_002deac0(p, *(f32*)(a1 + 220), *(f32*)(a2 + 224));
    u8* a3 = func_002dc7c8(g);
    u8* a4 = func_002dc7c8(g);
    func_002deba0(p, b, *(f32*)(a3 + 228), *(f32*)(a4 + 232));
}

extern Vec4 D_00362e70;
void wtarget_002e2e50(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        D_00362e70.x = D_00362e70.y = D_00362e70.w = 0.0f;
        D_00362e70.z = 1000.0f;
    }
}

void func_002ed5a8(u8* p) {
    *(u32*)(p + 96) = 0;
    *(u32*)(p + 120) = 1;
    p[20] = 8;
    p[22] = 0xff;
    *(f32*)(p + 88) = 60.0f;
    *(f32*)(p + 92) = 20.0f;
    p[84] = 7;
    // normalize the vector at +64 (VU0)
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\t"
                 "vsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, $f0\n\tvnop\n\t"
                 "vdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(p + 64) : "$8", "$f0", "memory");
}

extern u32 D_003a84d0[512];
// Fills a run of the 512-entry table with val (val 0 clears it all); 1 if nothing changed.
u32 wtarget_00109450(s32 start, s32 count, u32 val, u32) {
    u32 r = 1;
    if (val == 0) {
        for (start = 0; start < 512; start++) D_003a84d0[start] = 0;
    } else {
        s32 end = start + count;
        for (; start < end && start < 512; start++) {
            if (D_003a84d0[start] != val) {
                D_003a84d0[start] = val;
                r = 0;
            }
        }
    }
    return r;
}

void func_001dc818(u32);
void func_002d0cf0(u8* p) {
    if (*(u32*)(p + 2828)) {
        func_001dc818(*(u32*)(p + 2828));
        *(u32*)(p + 2828) = 0;
    }
    *(u32*)(p + 268) |= 0x80;
    *(u32*)(p + 264) |= 0x403;
    *(u32*)(p + 2832) = 0;
}
}
