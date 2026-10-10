#include "../common/types.h"

// 64-byte element with an empty destructor; arrays of it get a destructor loop.
struct Elem64 { u8 d[64] __attribute__((aligned(16))); ~Elem64() {} };
struct Elem64b { u8 d[64]; ~Elem64b() {} };
extern "C" void func_00106420(void*);
struct Elem64x30 {
    Elem64b a[30];
    static void operator delete(void* p) { func_00106420(p); }
};

extern "C" {
s32 func_00242d58(void);
extern u64 D_0034a970[];
void func_001a5e38(void);
void func_001ba740(void);
void func_001b24c8(void);
void func_001bb468(void);
void func_001922c8(s32);
void func_001b83d0(void);
void func_00197be8(void);
struct Info2c { s8 pad[0x2c]; s8 limit; };
Info2c* func_00177860(void*);
void func_001781e8(void*);
void func_001dc920(void*);
void func_00175928(void*);
extern void* D_0034e948;
s32 func_0019ba60(void*);
void* func_0018ee10(void*);
s32 func_001a15d0(s32);
s32 func_001a1540(s32);
void func_00239bf8(void*, s32);
void func_001abb78(void*, s32);
void func_001ad280(void*);
void func_001c1130(s32);  // copy_record_block_to_table
void func_0014c9d8(s32);
extern u8 D_00350a70[];
extern u8 D_00350a56;
void func_001c6ee8(void*);
void* func_001c16f0(void*, void*);
void* func_00186078(void*);
extern u32 D_0034f240;
void func_001e7798(void*, void*);
extern void* D_01d9e6e4;
void func_001e2c00(void*);
void func_001e6c00(void*);  // alloc_336_align_171
void func_001dc700(void*, s32);
extern u32 D_0035dad0;
extern u8 D_0035dade;
extern u32 D_0035dad4;
extern u32 D_0035dac4;
extern u8 D_0035dadd;
extern u32 D_0035dacc;
extern u32 D_0035dac8;
extern u32 D_0035dad8;
void func_00224940(void);
struct MaskCfg { u16 pad[14]; u16 mask; };
extern MaskCfg* D_0035f0e4;
struct KeyVal { s16 key, val; };
extern KeyVal D_003741f0[];
s32 func_00276608(s32);
s32 func_002b2338(s32);
extern u8* D_0035f630;
void* func_002bbda0(void*);
void func_002bb5a8(void*, void*);
extern u8 D_00362428[];
void func_002e7328(void*);  // to_2e7458
void func_002cff98(void*);
void func_00105110(void*);
void func_002cfeb0(void*, void*, s32, void*);  // obj_init_field1416_bit800
extern u8 D_003627c8[];
void func_002cf280(void*, s32, s32);
void func_00106420(void*);
extern void* D_01e2bfa0;
extern u32 D_003633c8;
void func_001c23a8(void*, void*, s32, s32, s32, s32, void*);
extern u8 D_00363758[];
extern void* D_00363748;
extern void* D_00347f98[];
extern void* D_00347f80;
extern u8 D_0035eb98[];
void func_0023c098(void*);  // set_vtbl_36eae8_then_call
void func_002369f0(void*);  // set_vtbl_36eac8_then_call
extern u8 D_0034ee08[];
void func_0019f9a8(void*);  // array8_free_slots
void func_001c0248(void*);
u8 func_00319fb0(void*);  // big_obj_dtor
extern u8 D_003638a8[];
extern u8 D_003637e0[];
void func_00239870(void*);
void func_002361d0(void*);

// Picks a state from four thresholds; 1/2 force a value, the others keep the current one.
void func_00148638(u32, u8* o, f32 x) {
    f32* f = *(f32**)(o + 276);
    u8 v = o[269];
    f32 a = f[14], b = f[15], c = f[16], d = f[17];
    u8 r;
    if (d < x) r = 2;
    else if (c < x) r = v;
    else if (b < x) r = 1;
    else if (a < x) r = v;
    else r = 0;
    o[269] = r;
}

// Tests the flag mask for the current entry against a 64-bit flag word.
s32 func_00158450(u64* p) {
    s32 i = func_00242d58();
    return (*p & D_0034a970[i]) != 0;
}

void AreaExit(void) asm("_ZN2YS8AreaExitEv");
void AreaExit(void) {
    func_001a5e38();
    func_001ba740();
    func_001b24c8();
    func_001bb468();
    func_001922c8(2);
    func_001b83d0();
    func_00197be8();
}

// min(count, limit) with the limit re-fetched.
s32 func_00177ba0(u8* p) {
    u8 v = p[0xb04];
    if (v < func_00177860(p)->limit) return p[0xb04];
    return func_00177860(p)->limit;
}

void wtarget_00178280(void*, u32, u32, u32) asm("_Z16wtarget_00178280jjjj");
void wtarget_00178280(void* a0, u32, u32, u32) {
    u8* p = (u8*)a0;
    *(u32*)&D_0034e948 = 0;
    func_001781e8(p);
    void* e = *(void**)(p + 0xb60);
    if (e) {
        func_001dc920(e);
        *(void**)(p + 0xb60) = 0;
    }
    func_00175928(p);
}

u32 func_0017a6c8(void) {
    u32 r = 0;
    if (func_0019ba60(D_0034e948)) {
        u32 m = *(u32*)((u8*)D_0034e948 + 0x160) & 0x4000;
        r = m != 0;
    }
    return r;
}

// Replaces every entry's key `key` with `val`.
void func_0018ef98(s32 key, s32 val) {
    s32* it = 0;
    while ((it = (s32*)func_0018ee10(it)) != 0) {
        if (it[3] == key) it[3] = val;
    }
}

s32 func_001a1658(s32 x) {  // state_dispatch_0_1_14
    switch (x) {
    case 0: return 0;
    case 1: case 14: return func_001a15d0(x);
    default: return func_001a1540(x);
    }
}

// Adds n, capping the sub-object's byte counter at 100.
void func_001a2578(u8* p, s32 n) {
    u8* s = *(u8**)(p + 580);
    if (s) {
        if (s[9] + n > 100) n = 100 - s[9];
        s[9] += n;
    }
    *(u16*)(p + 392) += n;
    *(u16*)(p + 400) += n;
}

void func_001abdf0(s32* p, s32 t) {
    p[0] = t;
    switch (t) {
    case 0: break;
    case 1: func_00239bf8(p + 1, 65); break;
    case 2: func_001abb78((u8*)p + 348, 65); break;
    }
}

void func_001ad5f0(void** p) {
    func_001ad280(p);
    p[0] = D_00350a70;
    D_00350a56 = 1;
    func_001c1130(12);  // copy_record_block_to_table
    func_0014c9d8(8);
}

// Drains two iterators.
void func_001ccda0(u8* p) {
    func_001c6ee8(p);
    for (void* v = 0; (v = func_001c16f0(*(void**)(p + 0x9f4), v)) != 0;) ;
    for (void* w = 0; (w = func_00186078(w)) != 0;) ;
}

bool func_001dc738(u32* p) {  // state_gate_flags
    u32 fl = p[2];
    return (fl & 0x400000) || ((D_0034f240 & 0x20) && p[1] != 3) || (bool)(((s32)fl >> 26) & 1);
}

void func_001ea928(u8* a, u8* b) {
    u8* s = a + **(s32**)(b + 12) + 160;
    void* e = *(void**)(s + 12);
    if (e) {
        func_001e7798(D_01d9e6e4, e);
        *(void**)(s + 12) = 0;
    }
}

void EFFECT_free(u8*) asm("_ZN3ryj6EFFECT4freeEv");
void EFFECT_free(u8* e) {
    *(u32*)(e + 8) |= 0x10000;
    void* h = *(void**)(e + 0x1c);
    if (h) {
        func_001e2c00(h);
        func_001e6c00(*(void**)(e + 0x1c));  // alloc_336_align_171
        *(void**)(e + 0x1c) = 0;
    }
}

struct Binding { u8 pad[0x40]; void* eff; u32 pad44; u32 w48; u8 pad2[0x10]; u32 f5c; Binding* next; };
void PAX_unbind(u8*, void*) asm("_ZN3ryj3PAX6unbindEPNS_6EFFECTE");
void PAX_unbind(u8* pax, void* e) {
    Binding* b = *(Binding**)(pax + 12);
    while (b) {
        Binding* nx = b->next;
        if (b->eff == e) {
            b->w48 = 0;
            b->f5c &= ~1;
            func_001dc700(e, 0);
            return;
        }
        b = nx;
    }
}

void u_call4_00224780(u32, u32, u32, u32) asm("_Z16u_call4_00224780jjjj");
void u_call4_00224780(u32 a0, u32, u32, u32) {
    D_0035dad0 = a0;
    D_0035dade = 0;
    D_0035dad4 = 5;
    D_0035dadd = 0;
    D_0035dac4 = 0;
    D_0035dac8 = 0;
    D_0035dacc = 0;
    D_0035dad8 = 0;
    func_00224940();
}

// Index of the n-th set bit among the low 10 bits of the mask, or -1.
s32 func_002670a0(s32 n) {
    s32 r = -1;
    u16 m = D_0035f0e4->mask;
    s32 c = 0;
    for (s32 i = 0; i < 10; i++) {
        if ((u8)((m >> i) & 1)) {
            if (c == n) { r = i; break; }
            c++;
        }
    }
    return r;
}

// Looks up key in a -1 terminated (key, value) table; last match wins.
s32 func_00282c68(s32 key) {
    s32 r = -1;
    for (s32 i = 0; D_003741f0[i].key >= 0; i++)
        if (D_003741f0[i].key == key) r = D_003741f0[i].val;
    return r;
}

u8* func_002b23e0(s32 i) {  // list_entry_by_index_checked
    if (i < 0) i = func_00276608(28);
    return D_0035f630 + func_002b2338(i) * 36;
}

void func_002bc398(void* a, void* b) {
    u8* n = (u8*)func_002bbda0(a);
    if (n) {
        func_002bb5a8(n, b);
        *(u32*)(n + 36) &= ~8;
    }
}

void func_002d5e10(void** p) {
    p[0] = D_00362428;
    func_002e7328((u8*)p + 0xb38);  // to_2e7458
    func_002cff98(p);
    func_00105110(p);
}

void func_002daca0(u8* p, void* b, void* c) {
    func_002cfeb0(p, b, 3, c);  // obj_init_field1416_bit800
    *(u32*)(p + 0xb14) = 0;
    p[0xb18] = 0;
    *(void**)p = D_003627c8;
    *(u32*)(p + 0xb1c) = 0;
    func_002cf280(p + 0xaf0, 1, 0);
}

// delete[] of the 64-byte element array.
void func_002e70b0(u8* o) {
    delete[] *(Elem64**)(o + 4);
}

void func_002e9338(void) {
    delete (Elem64x30*)D_01e2bfa0;
    D_01e2bfa0 = 0;
    D_003633c8 = 0;
}

// Advances a byte counter and wraps it into [0, max).
struct WrapCtr { s32 max; u8 cur; };
void func_002e9b10(WrapCtr* s) {
    s->cur++;
    while (s->cur >= s->max) s->cur -= *(u8*)&s->max;
}

void func_002ed2b0(void** p, void* b, void* c) {
    func_001c23a8(p, b, 0, 1, 0, 128, c);
    p[0] = D_00363758;
    D_00363748 = p;
}

// Signed LEB128 decode.
u8* func_00314b38(u8* p, s64* out) {  // varint64_decode_b
    u32 shift = 0;
    u64 r = 0;
    u8 b;
    do {
        b = *p++;
        r |= (b & 0x7f) << shift;
        shift += 7;
    } while (b & 0x80);
    if (shift < 64 && (b & 0x40)) r |= -1LL << shift;
    *out = r;
    return p;
}

struct VObj { void** vt; };
void func_0031d770(void** p) {
    *(void**)p = D_00347f98;
    VObj* o = *(VObj**)((u8*)D_00347f80 + 0x14);
    ((void (*)(VObj*, void*))o->vt[1])(o, p);
}

void func_00322d70(void** p) {
    p[0] = D_0035eb98;
    func_0023c098((u8*)p + 48);  // set_vtbl_36eae8_then_call
    func_002369f0((u8*)p + 24);  // set_vtbl_36eac8_then_call
    p[0] = D_00347f98;
}

s32 func_00324938(void** p) {
    p[0] = D_0034ee08;
    func_0019f9a8((u8*)p + 0xa08);  // array8_free_slots
    func_001c0248((u8*)p + 0xa50);
    return func_00319fb0(p);  // big_obj_dtor
}

void func_00325b80(void** p) {
    p[0] = D_003638a8;
    func_00239870((u8*)p + 0x1d4);
    func_002361d0((u8*)p + 48);
    p[0] = D_003637e0;
    func_00106420(p);
}
}
