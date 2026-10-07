#include "../common/types.h"

typedef s32 (*IFn)(void*);
typedef void (*VFn)(void*);
typedef void (*VFn3)(void*, u32, u32);
typedef u32 (*AllocFn)(void*, u32, s32);

struct Q16 { u32 w[4]; } __attribute__((aligned(16)));

// A local whose (empty) destructor keeps the final call from becoming a sibcall.
struct NoTail { ~NoTail() {} };

extern "C" {
void MENU_DestoryAllocator(void) asm("_ZN4MENU16DestoryAllocatorEv");
u32 wtarget_00127d40(u32, u32, u32, u32) asm("_Z16wtarget_00127d40jjjj");
void f1340e8(void*) asm("_Z13func_001340e8Pv");
void wtarget_0013a820(u32, u32, u32, u32) asm("_Z16wtarget_0013a820jjjj");
void wtarget_001ac2a8(u32, u32, u32, u32) asm("_Z16wtarget_001ac2a8jjjj");
u32 u_call4_002ed830(u32, u32, u32, u32) asm("_Z16u_call4_002ed830jjjj");
s32 LoadDataIsFlushing(void) asm("_ZN2Tz18LoadDataIsFlushingEv");
s32 LoadDataIsFlushing_at(void) asm("func_00292630");  // same function, by its fixed address

void func_00170c00(void*);
s32 func_0019ba60(void*);
void func_0011f3b8(void*);
void func_0011ee58(void*);
void func_00127f40(u32, u32);
void func_001316f0(u32, u32);
s32 func_001341e8(void*);
s32 func_00134020(void);
void func_00134030(void);
void* func_001b9bc8(void*);
s32 func_0016f930(s32);
void func_0016fb00(void*);
s32 func_0019c5d0(void*);
void func_00177638(void*);
void func_001dc978(void*, f32);
void* func_001de168(u32, u32, u32, u32, u32, void*);
s32 func_001b58a8(void);
s32 func_001a6850(void);
void* func_00102c18(u32, u32, void*);
void func_00196888(void);
void func_00196a08(void);
void func_0019d228(void*);
void func_0019cbe8(void*);
void func_0019d480(void*);
void func_00190128(void*);
s32 func_00239bf8(void*, u32);
void func_001ac970(void*, u32, u32, u32, u32, u32, u32, u32);
void func_001ac078(void*, u32, u32, u32);
void func_001aa388(void*, u32);
void func_001ad990(void*, f32, f32, f32);
u8 func_00181500(u16);
u8 func_001b8958(u16);
u8 func_001a6d08(u16);
void func_001e2c00(void*);
void func_001e6c00(void*);
void func_00321c50(void*, void*);
void func_001dc4b8(void*);
void* func_00106a18(s32);
void* func_00106a60(s32);
void func_001dd320(void*, void*, s32);
void func_002f4000(void*);
void func_002f3d08(void*, void*, void*);
void func_002247e8(s32);
s32 func_002249b8(void);
void func_002248f8(s32);
s32 func_002ef7b8(void);
void* func_0014abd8(void);
void func_0014aa58(void*, s32, s32);
void func_002ef7a0(s32, void*);
void func_002fde18(void*, s32, s32);
u8* func_001058e8(void);
s32 func_00139d78(void*);
void func_002579e0(void);
s32 func_0028be58(void*);
void func_0028be18(void*);
s32 func_0028acc8(void*);
void func_0028abe0(void*);
void* func_00103580(void);
void func_002bd788(u32);
void func_002bd730(void*, s32, s32, s32);
void func_00139570(void*);
u8* func_00103eb0(void);
s32 func_00102a38(void*, void*);
void func_00292608(void);
void func_002933b8(void);
s32 func_00170cd0(void);
s32 func_0023f900(void*);
void func_0023fad0(void*);
void func_00293d80(s32);
void func_0017f540(void*, s32, f32, f32);
void func_0017d8c0(void*, void*, void*);
void func_00182f38(void);
void func_00182f28(s32);
void func_00319f88(void*);
void func_0019f9a8(void*);
void func_001c0248(void*);
void func_00319fb0(void*);
void func_00105110(void*);
void func_002cbed8(void*, void*);
void func_0017f5f8(void*, s32, s32, f32, f32);
u8* func_002eaf40(void*);
void func_0017f5e0(void*, s32, s32, f32, f32);
void func_002ed630(void*);
void func_002ed720(void*);
void func_001991a8(s32);
void func_00239870(void*);

extern u8 D_0032ba30;
extern s32 D_0032ba24;
extern void* D_0032ba14;
extern u32 D_0032ba18;

// Frees the menu allocator unless it is locked or the menu mode is 1, 2 or 6.
void MENU_DestoryAllocator(void) {
    if (!D_0032ba30) {
        s32 m = D_0032ba24;
        if (m == 1) goto done;
        if (m == 2) goto done;
        if (m == 6) goto done;
        func_00170c00(D_0032ba14);
    }
done:
    D_0032ba14 = 0;
    D_0032ba18 = 0;
    D_0032ba30 = 0;
}

s32 func_00112d28(u8* p) {
    s32 r = 0;
    if (p == 0) return r;
    if (!func_0019ba60(p)) return 0;
    if (!(*(u32*)(p + 1416) & 0x10)) return 0;
    if (*(u32*)(p + 2040) & 4) return 0;
    u32 m = *(u32*)(p + 264) & 0x8000;
    return m == 0;
}

// Any of the first count() flag bytes has bit 2 set.
s32 func_0011f078(void** o, u8* flags) {
    for (s32 i = 0; i < (*(IFn*)((u8*)*o + 48))(o); i++) {
        if (flags[i] & 4) return 1;
    }
    return 0;
}

// Destructor: release each offset-listed entry of the attached table.
extern u32 D_00347a90;
void func_00123ba8(u32* self) {
    u8* a = (u8*)self[1];
    self[0] = (u32)&D_00347a90;
    for (u32* p = (u32*)(a + 16); *p; p++) func_0011f3b8(a + *p);
    NoTail g;
    func_0011ee58(self);
}

u32 wtarget_00127d40(u32 a, u32, u32, u32) {
    u32 r = 0;
    u32 s = a + 144;
    switch (*(s32*)s) {
    case 0: func_00127f40(a, s); r = a; break;
    case 1: func_001316f0(a, s); r = a; break;
    }
    return r;
}

extern volatile u8 D_00347cb4;
void f1340e8(void* p) {
    if (func_001341e8(p) >= 0) {
        while (func_00134020()) func_00134030();
    } else {
        func_00134030();
        D_00347cb4 = 0;
    }
    *(volatile u32*)0x10003010 = 0;  // GIF_MODE
}

struct Pair { u32 a, b; };
struct S347fb0 { u32 x, y; Pair e[4]; };
extern S347fb0 D_00347fb0;
extern Pair D_00347fd8[2];
void wtarget_0013a820(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        D_00347fb0.x = 0;
        D_00347fb0.y = 0;
        for (s32 i = 0; i < 4; i++) {
            D_00347fb0.e[i].a = 0;
            D_00347fb0.e[i].b = 0;
        }
    }
    if (b == 0xffff && a == 1) {
        Pair* q = D_00347fd8;
        q[0].a = 0;
        q[1].b = 0;
        q[1].a = 0;
        q[0].b = 0;
    }
}

// Default material check: no alpha offset, 255 scale, neutral 0x808080 colour.
extern u8 D_00340eb0;
s32 func_0015cc80(u8* p) {
    if (*(f32*)(p + 12) == 0.0f && *(f32*)(p + 16) == 255.0f && (*(u32*)p & 0xffffff) == 0x808080) {
        D_00340eb0 = 0;
        return 1;
    }
    D_00340eb0 = 1;
    return 0;
}

// Calls virtual slot 13 on every object of the iterator.
void func_0016bb38(u32 a, u32 b) {
    void* o = 0;
    while ((o = func_001b9bc8(o)) != 0) (*(VFn3*)(*(u8**)o + 52))(o, a, b);
}

extern void* D_004f63a8;
extern void* D_004f63ac;
void func_0016f8d0(void* p) {
    s32 v = func_0016f930((s32)p);
    if (v == 2400) v = func_0016f930(0);
    switch (v) {
    case 2410: D_004f63a8 = p; break;
    case 2420: D_004f63ac = p; break;
    }
}

// Unlinks a node from the global singly linked list, then releases it.
struct Node { u8 pad[60]; Node* next; };
struct List { Node* head; Node* tail; };
extern List D_0034dca0;
void func_001700e8(Node* n) {
    Node* prev;
    Node* h = D_0034dca0.head;
    if (n == h) {
        D_0034dca0.head = n->next;
        prev = 0;
    } else {
        prev = h;
        while (prev->next != n) prev = prev->next;
        prev->next = n->next;
    }
    if (n == D_0034dca0.tail) D_0034dca0.tail = prev;
    n->next = 0;
    func_0016fb00(n);
}

s32 func_00176258(u8* o) {
    void** p = (void**)(o + 2808);
    for (s32 i = 0; i < 2; i++) {
        void* e = *p++;
        if (e && !func_0019c5d0(e)) return 1;
    }
    return 0;
}

void func_00177540(u8* o) {
    void** p = (void**)(o + 2808);
    for (s32 i = 0; i < 2; i++) {
        void* e = *p++;
        if (e) (*(VFn*)(*(u8**)e + 72))(e);
    }
    func_00177638(o);
}

void func_001877a0(u8* o, u32 a, u32 b) {
    if (*(void**)(o + 2784)) func_001dc978(*(void**)(o + 2784), 10.0f);
    *(void**)(o + 2784) = func_001de168(a, b, 0, 1, 10000, o);
}

extern void* D_0034e948;
extern u32 D_01c61960;
extern u32 D_0034f240;
s32 func_001918c8(void) {
    if (!func_0019ba60(D_0034e948)) {
        D_01c61960 = 0;
        return 0;
    }
    if (func_001b58a8()) return 1;
    if (D_0034f240 & 0x10000) return 1;
    return func_001a6850() != 0;
}

extern Pair D_00350338[8];
void func_00196a40(void) {
    for (s32 i = 0; i < 8; i++) D_00350338[i].b = 0;
    u8* t = (u8*)func_00102c18(1, 14002, (void*)func_00196888);
    *(void**)(t + 48) = (void*)func_00196a08;
}

void func_0019cc20(s32* p) {
    if (*p) {
        func_0019d228(p);
        func_0019cbe8(p);
        if (*p == 2) func_0019d480(p);
        *p = 0;
        func_00190128(p + 1);
    }
}

void wtarget_001ac2a8(u32 a, u32 b, u32 c, u32 d) {
    u32* p = (u32*)a;
    if (b) func_00239bf8(p + 3, b + 1);
    p[0] = b;
    p[1] = c;
    p[2] = d;
}

// Only the first arm is a tail call: the function falls off the end otherwise.
struct B3 { u8 a, b, c; };
extern B3 D_00350a38[];
s32 func_001acfb0(u8* o, s32 n) {
    if (n == *(s32*)(o + 476)) return;
    *(s32*)(o + 476) = n;
    if (*(u32*)(o + 112) == 0) return func_00239bf8(o + 132, D_00350a38[n].a);
    func_00239bf8(o + 132, D_00350a38[n].b);
}

extern u8 D_00350b30[];
void func_001ad4a8(u8* o, u32 a) {
    func_001ac970(o, 3, 5, a, 0, 256, 336, 0);
    *(u32*)(o + 104) = 0;
    *(u32*)(o + 100) = 3;
    *(void**)o = D_00350b30;
    func_001ac078(o + 1196, 1, 1, 0);
    u8* b = o + 12;
    func_001aa388(b, *(u32*)(b + 12));
}

void func_001b0728(u8* o, Q16* q, u32 c, f32 f) {
    if (*(s32*)(o + 12) >= 0) {
        *(u32*)(o + 4) = 1;
        Q16* d = (Q16*)(o + 32);
        if (d != q) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(q) : "$8", "memory");
        func_001ad990(o + 16, 0.0f, 1.0f, f);
        *(u32*)(o + 8) = c;
    }
}

u8 func_001d5868(u16* p) {
    switch (p[0]) {
    case 1: return func_00181500(p[1]);
    case 2: return func_001b8958(p[1]);
    case 3: return func_001a6d08(p[1]);
    }
    return 0;
}

extern u8 D_00352ae0[];
extern s32 D_00352ae8;
extern u8 D_00352b48[];
void func_001dc418(u8* o) {
    *(void**)o = D_00352b48;
    if (*(void**)(o + 28)) {
        func_001e2c00(*(void**)(o + 28));
        func_001e6c00(*(void**)(o + 28));
    }
    func_00321c50(D_00352ae0, o);
    D_00352ae8--;
    func_001dc4b8(o);
}

extern u8 D_00352af0;
extern u8 D_00352af1;
void func_001dd2b8(void) {
    if (D_00352af1) return;
    if (!D_00352af0) return;
    void* a = func_00106a18(0);
    func_001dd320(a, func_00106a60(0), 1);
}

extern u8* D_01d9e6e0;
extern u8* D_01d9e6e8;
void func_001eb140(void*, f32* v) {
    f32 m[4][4];
    func_002f4000(m);
    f32 h = *(f32*)(D_01d9e6e0 + 68);
    f32 y = h + h * v[1];
    m[1][1] = y;
    if (v[2] < y) m[1][1] = v[2];
    u8* p = D_01d9e6e8 + 16;
    func_002f3d08(p, m, p);
}

void func_001eb1b0(void*, f32* v) {
    f32 m[4][4];
    func_002f4000(m);
    f32 h = *(f32*)(D_01d9e6e0 + 68);
    f32 y = h + h * v[1];
    m[1][1] = y;
    if (v[2] < y) m[1][1] = v[2];
    m[0][0] = m[1][1] = m[2][2];
    u8* p = D_01d9e6e8 + 16;
    func_002f3d08(p, m, p);
}

s32 func_0022b028(s32 n) {
    func_002247e8(n);
    if (func_002249b8() == 3) {
        n = -n;
        func_002248f8(n);
    } else if (func_002249b8() == 5) {
        n = -n;
        if (n > 0) func_002248f8(n);
    } else {
        n = 0;
    }
    return n;
}

void func_0022bb60(void* p) {
    if (p && func_002ef7b8()) {
        func_0014aa58(func_0014abd8(), 0, 0);
        func_002ef7a0(2, p);
    }
}

struct B8 { u8 b[8]; };
extern u8* D_0035ec9c;
extern u8* D_0035ec94;
void func_00241850(s32 i, s32 clear) {
    u8* s = D_0035ec9c;
    if (clear) func_002fde18(D_0035ec94 + i * 32 + 32, 255, 8);
    else *(B8*)(i * 32 + D_0035ec94 + 32) = *(B8*)(s + 8);
}

// Bit test in the flag array at +18904.
s32 func_002431d0(s32 a, s32 b) {
    u8* v = func_001058e8();
    u32 i = a * 8 + b;
    v += (i >> 5) * 4;
    return (*(u32*)(v + 18904) & (1 << (i & 31))) != 0;
}

extern u8* D_0035ed8c;
void func_0024b078(void) {
    for (s32 i = 0; i < 2; i++) {
        if (func_00139d78(D_0035ed8c + i * 408)) {
            u8* o = (u8*)(i * 408 + (u32)D_0035ed8c);
            (*(VFn*)(*(u8**)o + 20))(o);
        }
    }
}

extern void* D_0035f04c;
extern void* D_0035f01c;
void func_00269ef8(void) {
    func_002579e0();
    if (func_0028be58(D_0035f04c)) func_0028be18(D_0035f04c);
    if (func_0028acc8(D_0035f01c)) func_0028abe0(D_0035f01c);
}

extern u32 D_0035f2c0;
extern u8 D_00374348[];
void func_00284e40(void) {
    void** o = (void**)func_00103580();
    u32 v = (**(AllocFn**)o)(o, 0x48800, 0);
    u32 a = (v + 63) & ~63;
    D_0035f2c0 = v;
    func_002bd788(a);
    func_002bd730(D_00374348, 16383, 0, 0);
}

void func_0028a908(u8* o) {
    for (s32 i = 0; i < *(s16*)(o + 4); i++) {
        void* e = (*(void***)(o + 40))[i];
        if (e) func_00139570(e);
    }
}

extern u8 D_0035f4b8;
// Tz::LoadDataIsFlushing(): true while load data is still being flushed.
s32 LoadDataIsFlushing(void) {
    s32 r = D_0035f4b8;
    if (func_00102a38(*(void**)(func_00103eb0() + 4), (void*)func_00292608)) return 1;
    if (!r) r = func_00170cd0();
    return r;
}

extern s16* D_0035f4e8;
s32 func_00293668(void) {
    s32 r = 0;
    if (!func_00102a38(*(void**)(func_00103eb0() + 4), (void*)func_002933b8)) {
        s16* p = D_0035f4e8;
        for (s32 i = 0; i < 8; i++, p += 3) {
            if (*p >= 0) { r = 1; break; }
        }
    } else {
        r = 1;
    }
    return r;
}

extern u8 D_0035f5e0;
extern u8 D_0035f5e1;
extern void* D_0035f5dc;
void func_002a1c68(void) {
    if (LoadDataIsFlushing_at()) return;
    if (D_0035f5e0 && func_0023f900(D_0035f5dc)) func_0023fad0(D_0035f5dc);
    func_00293d80(5101);
    D_0035f5e0 = 0;
    D_0035f5e1 = 0;
}

void func_002bebd0(void*, u8* o) {
    s32 c = 0;
    f32 f = *(f32*)(o + 28);
    if (0.0f < f && !(f < (*(f32*)(o + 272) + *(f32*)(o + 276)) * 0.5f)) c = 153;
    func_0017f540(o + 320, c, 8.0f, 0.0f);
}

struct M64 { Q16 r[4]; };
extern Q16 D_01e2bcb0;
extern Q16 D_01e2bca0;
extern M64 D_01e2bcc0;
void func_002c2168(Q16* q) {
    Q16* d = &D_01e2bcb0;
    if (q != d) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(q) : "$8", "memory");
    M64 m;
    func_0017d8c0(&m, d, &D_01e2bca0);
    M64* e = &D_01e2bcc0;
    if (&m != e)
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(e), "r"(&m) : "$8", "$9", "$10", "$11", "memory");
}

extern s32 D_00361fa0;
extern u8* volatile D_00361fa4;
void func_002cf938(u8 on) {
    if (on && D_00361fa4) {
        for (s32 i = 0; i < D_00361fa0; i++) *(u32*)(D_00361fa4 + i * 40) = 0;
    }
    func_00182f38();
}

// Destructor chain: vtables reset as each base is torn down.
extern u8 D_00362060[];
extern void* D_00362050;
extern u8 D_0034e8b8[];
extern u8 D_0034ee08[];
void func_002d1028(u8* o) {
    *(void**)o = D_00362060;
    func_00182f28(0);
    D_00362050 = 0;
    *(void**)o = D_0034e8b8;
    func_00319f88(o + 2824);
    *(void**)o = D_0034ee08;
    func_0019f9a8(o + 2568);
    func_001c0248(o + 2640);
    func_00319fb0(o);
    func_00105110(o);
}

extern Q16 D_01e2be20;
void func_002e3a18(Q16** o) {
    u8* p = *(u8**)(*(u8**)o + 4);
    if (p) {
        void* q = *(void**)(p + 1288);
        if (q) {
            Q16 t;
            func_002cbed8(&t, q);
            Q16* d = &D_01e2be20;
            if (&t != d) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(&t) : "$8", "memory");
            *o = d;
        }
    }
}

void func_002eb7f0(void* o, s32 n, f32 f) {
    func_0017f5f8((u8*)o + 320, n, 0, f, 0.0f);
    func_0017f5e0(func_002eaf40(o) + 320, n - 101, 0, f, 0.0f);
}

u32 u_call4_002ed830(u32 a, u32, u32, u32) {
    u8* o = (u8*)a;
    func_002ed630(o);
    func_002ed720(o);
    f32 f = *(f32*)(o + 88);
    if (f < 0.0f) return 0;
    *(u8*)(o + 21) = (s32)(f * 0.125f * 128.0f);
    return 1;
}

void func_002eda90(f32* p, f32 f) {
    func_001991a8(140);
    f32 v = *p;
    if (v < f) *p = v = f;
    *p = (1.0f < v) ? v : 1.0f;
}

// Constructor: primary and secondary vtables, then registers with the manager.
extern u8 D_00348590[];
extern u8 D_00347e60[];
extern u8 D_00347f98[];
extern void* D_00347f80;
void func_0031b0c0(u8* o) {
    *(void**)o = D_00348590;
    *(void**)(o + 260) = D_00347e60;
    func_00239870(o + 284);
    *(void**)(o + 260) = D_00347f98;
    *(void**)o = D_00347f98;
    void** m = *(void***)((u8*)D_00347f80 + 20);
    (*(void (**)(void*, void*))(*(u8**)m + 4))(m, o);
}
}
