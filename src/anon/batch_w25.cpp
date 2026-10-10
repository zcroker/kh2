#include "../common/types.h"

struct VObj { void (**vt)(...); };
typedef void (*VFn)(void*, void*);

extern "C" {
u32 u_call4_00194830(u32, u32, u32, u32) asm("_Z16u_call4_00194830jjjj");
void u_call0_00233c98(void) asm("_Z16u_call0_00233c98v");
void LayFileReset(void) asm("_ZN2Tz12LayFileResetEv");

// Signed LEB128 decode; returns the pointer past the encoded value.
u8* func_00100468(u8* p, s64* val) {
    u32 shift = 0;
    u64 result = 0;
    u8 byte;
    do {
        byte = *p++;
        result |= (byte & 0x7f) << shift;
        shift += 7;
    } while (byte & 0x80);
    if (shift < 64 && (byte & 0x40) != 0)
        result |= -(1LL << shift);
    *val = result;
    return p;
}

extern void* D_003484a0;
extern u8 D_003484a4;
s32 func_0013c738(void*);
s32 func_0013c7d0(void) {
    void* p = D_003484a0;
    if (p) {
        if (func_0013c738(p)) return 1;
        if (D_003484a4 == 1) return 1;
    }
    return 0;
}

void func_0013d620(void);
void func_0013b128(void*);
void func_0013d7c0(void);
void func_001024a8(u32);
void func_0013d750(u32 a) {
    func_0013d620();
    func_0013b128(D_003484a0);
    *(u32*)((u8*)D_003484a0 + 676) = 0;
    func_0013d7c0();
    func_001024a8(a);
}

struct E20 { u8 pad[16]; u8 flag; u8 id; u8 pad2[2]; };
// Flags every 20-byte entry whose id matches.
void func_00141928(u8* o, u8 id) {  // mark_records_by_index
    s32 n = *(s32*)(o + 36);
    s32 i;
    for (i = 0; i < n; i++) {
        E20* e = (E20*)(i * 20 + *(u32*)(o + 8));
        if (e->id == id) e->flag = 1;
    }
}

struct S384 { u8 d[384]; };
extern S384 D_0034d3c0[];
void func_002f4a78(void);
void func_002f5c70(u32);
void func_00167728(S384*, s32);
void func_00167b98(void) {
    s32 i;
    func_002f4a78();
    func_002f5c70(0);
    for (i = 0; i < 2; i++) func_00167728(&D_0034d3c0[i], i);
}

void* func_0016abf8(u32, u32, u32, u32);
void* func_001dc5f8(void*);
void* func_0016ac80(u32 a, u32 b, void* src, u32 c, u32 d) {
    void* r = func_0016abf8(a, b, c, d);
    if (r) {
        void* dst = func_001dc5f8(r);
        if (dst != src)
            asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(dst), "r"(src) : "$8", "memory");
    }
    return r;
}

struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
extern Q16 D_004f62a0;
void func_0017d5e8(Q16*, u32, float);
void func_0016d640(u32* p) {
    Q16 tmp;
    func_0017d5e8(&tmp, p[0], *(float*)&p[1]);
    if (&tmp != &D_004f62a0)
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&D_004f62a0), "r"(&tmp) : "$8", "memory");
    p[0] = (u32)&D_004f62a0;
}

s32 func_00170cd0(void);
void func_00102448(void*, u32);
void func_00170dd0(void* a) {
    while (func_00170cd0()) func_00102448(a, 0);
}

extern u8 D_01c5f480;
void func_00185138(u32, void*, s32, float);
void func_00171640(u32* p) {
    func_00185138(*(u32*)(p[0] + 4), &D_01c5f480, p[2] != 0, *(float*)&p[1]);
    p[0] = (u32)&D_01c5f480;
}

// bsearch over 8-byte entries; returns p + entry offset.
extern u8 D_0031eec8;
u8* func_002fd248(u32, void*, u32, u32, void*);
u8* func_00191f20(u8* p, u32 key) {
    u32* r = (u32*)func_002fd248(key & 0xffff7fff, p + 8, *(u32*)(p + 4), 8, &D_0031eec8);
    if (r == 0) return 0;
    return p + r[1];
}

u32* func_001947c0(u32, u32, u32, u32);
u32 u_call4_00194830(u32 a, u32 b, u32 c, u32 d) {
    u32* r = func_001947c0(a, b, c, d);
    if (r) {
        if (*r & (1 << c)) return 1;
        return 0;
    }
    return 0;
}

extern u8 D_00350388;
void func_00169398(u8*, u32, u32*, u32, u32);
void func_00197fe0(u8* o, u32* a, u32 b, u32 c) {
    func_00169398(o, *a | 0x40000000, a, b, c);
    *(void**)o = &D_00350388;
    *(u32*)(o + 1416) |= 0x20;
}

struct O19b { u8 pad[8]; u8* hdr; u8 pad2[32]; u8* first; };
// Walks variable-length records (12-byte units) looking for id.
u8* func_0019b380(O19b* o, u32 id) {
    s32 i;
    u8* e = o->first;
    for (i = 0; i < *(u16*)(o->hdr + 8); i++) {
        if (e[5] == id) return e;
        e = e + *(u16*)(e + 2) * 12 + 8;
    }
    return 0;
}

void func_001bc688(void*);
void func_00190128(void*);
void func_0019da20(u8* o, u32 a) {
    *(u32*)o = a;
    *(u16*)(o + 4) = 0;
    func_001bc688(o + 4);
    func_00190128(o + 16);
    *(u32*)(o + 60) = 0;
    *(s32*)(o + 36) = -1;
    *(u32*)(o + 80) = 0;
}

void func_00239700(void*);
u32 func_001ab810(void);  // get_global_1c7cec0
u32 func_001ab800(void);
void func_00239988(void*, u32, u32);
void func_001abfd8(u8* o) {
    o[0] = 0;
    func_00239700(o + 4);
    u32 x = func_001ab810();  // get_global_1c7cec0
    u32 y = func_001ab800();
    func_00239988(o + 4, x, y);
}

void func_001d5370(u32*, u32, s32);
void func_002534e0(u32, u32);
s32 func_001bba30(u8* o) {
    u32 buf[2];
    buf[0] = 0;
    buf[1] = 0;
    u32 a = *(u32*)(o + 72);
    u8 c;
    if (!a || (c = (*(u8**)(o + 8))[12]) == 0) return 0;
    func_001d5370(buf, a, c - 1);
    func_002534e0(buf[1], buf[0]);
    return 1;
}

s32 func_001bb4a0(void);
u8* func_001bbcb0(void);
s32 func_001bc0e0(void) {
    s32 r = 0;
    if (!func_001bb4a0() || !(*(u32*)(func_001bbcb0() + 4) & 0x10)) r = 1;
    return r;
}

struct O1bc { u16 f0; u16 f2; u8 f4; u8 f5; u16 pad; u32 f8; };
u8 func_001bc2a8(u16*, u32, u32);
void func_001bc6a8(O1bc* o, u16* a, u32 b, u32 c, u32 d) {
    o->f2 = *a;
    o->f4 = d;
    o->f5 = func_001bc2a8(a, b, c);
    o->f8 = c;
    o->f0 = 0;
}

extern u8 D_00351d38;
void func_001c23a8(void*, u32, u32, u32, u32, u32, u32);
void func_001c6ea0(void* o, u32 a, u32 b, u32 c) {
    func_001c23a8(o, a, 0, 1, 0, c, b);
    *(void**)o = &D_00351d38;
}

extern s32 D_00351f30;
extern u32 D_01d49980[];
// Returns 1 if x is in the registered list.
s32 func_001c9db0(u32 x) {
    s32 i;
    for (i = 0; i < D_00351f30; i++)
        if (D_01d49980[i] == x) return 1;
    return 0;
}

s32 func_00197920(void);
s32 func_0017a6c8(void*);
void func_001c9e50(void* a) {
    while (func_00197920() || func_0017a6c8(a)) func_00102448(a, 0);
}

extern u8 D_003524b8;
extern u8 D_0036e3a8;
void func_00177dc8(u8*, u32, u32, u32, u32);
void func_001befd8(u32, void*, u32);
void func_001d14e0(u8* o, u32 a, u32 b, u32 c) {
    func_00177dc8(o, a, 8, b, c);
    *(void**)o = &D_003524b8;
    *(u32*)(o + 1416) |= 0x4000000;
    func_001befd8(*(u32*)(o + 2884), &D_0036e3a8, 2);
}

u8 func_001ddef0(u32**, u8*);
u32 func_001de168(u32** o, u32 id) {  // scan_list_by_half
    u32 r = 0;
    s32 n = (*o)[2];
    s32 i;
    for (i = 0; i < n; i++) {
        u8* e = (u8*)o[1] + i * 80;
        if (*(u16*)(e + 2) == id) {
            r = func_001ddef0(o, e);
            break;
        }
    }
    return r;
}

extern u8 D_00354bc0;
extern u8 D_00354be0;
u8 func_002f3f88(void*, void*);  // memcpy16
s32 func_002006b0(u8* a, u8* b) {
    u8* s = a + *(s32*)(*(u8**)(b + 12) + 4);
    func_002f3f88(s + 160, &D_00354bc0);  // memcpy16
    return func_002f3f88(s + 176, &D_00354be0);  // memcpy16
}

// Clears a 256-entry u64 table; the original has a 3-nop pad in the loop (asm).
extern u64 D_01dadc00[];
void func_002fb928(void);
void func_00233ce0(void);
void u_call0_00233c98(void) {
    s32 i;
    u64* p;
    func_002fb928();
    p = D_01dadc00;
    i = 256;
    do {
        *p = 0;
        i--;
        asm volatile("nop\n\tnop\n\tnop");
        p++;
    } while (i > 0);
    func_00233ce0();
}

// Sets a 2-bit mode field (bits 9-10).
u8* func_001058e8(void);
void func_00242df0(s32 m) {
    u8* v = func_001058e8() + 16800;
    s32 x;
    if (m == 0) x = 0;
    else x = m == 2 ? 2 : 1;
    *(u32*)(v + 4) = (*(u32*)(v + 4) & ~0x600) | (x << 9);
}

u8* func_001d56c8(u32);
s32 func_00276c18(void);
s32 func_00244a10(void) {
    s32 r = 0;
    if (*func_001d56c8(8) >= 2 || func_00276c18()) r = 1;
    return r;
}

extern u32 D_0035f2c0;
void func_002bd7d8(void);
VObj* func_00103580(void);
void func_00284ea8(void) {
    func_002bd7d8();
    VObj* o = func_00103580();
    ((VFn)o->vt[1])(o, (void*)D_0035f2c0);
    D_0035f2c0 = 0;
}

s32 func_00181500(u16);
s32 func_001a3570(u16);
s32 func_00294480(u16* o) {  // record_lookup_success
    s32 r = 0;
    if (((s8*)o)[6] != 2) {
        if (func_00181500(o[0])) r = 1;
    } else {
        r = func_001a3570(o[0]) > 0;
    }
    return r;
}

extern u8 D_0035f5a2;
extern u32 D_0035f59c;
s32 func_0023f900(u32);
void func_0023fad0(u32);
void func_00293d80(u32);
void LayFileReset(void) {
    if (D_0035f5a2) {
        if (func_0023f900(D_0035f59c)) func_0023fad0(D_0035f59c);
    }
    func_00293d80(5101);
    D_0035f5a2 = 0;
}

extern u32 D_003616f8[];
void func_002b6adc(u32, u32);
void func_002b6ab8(void);
void func_002bd1c0(void) {
    s32 i;
    for (i = 11; i < 25; i++) {
        func_002b6adc(2, D_003616f8[i]);
        func_002b6adc(0, D_003616f8[i]);
    }
    func_002b6ab8();
}

// Calls each object's virtual slot 32 while iterating the list.
VObj* func_002be908(VObj*);
void func_002be960(void) {
    VObj* o = 0;
    while ((o = func_002be908(o)) != 0) ((void (*)(VObj*))o->vt[32])(o);
}

void func_002cf2d0(void*);
void func_002cff50(u8* o) {
    func_002cf2d0(o + 2800);
    *(u32*)(o + 2804) = 0;
    *(u32*)(o + 2808) = 0;
    *(u32*)(o + 2812) = 0;
    *(u32*)(o + 2816) = 0;
    *(u32*)(o + 2820) = 0;
    *(u32*)(o + 2824) = 0;
    *(u32*)(o + 2828) = 0;
}

extern u8 D_003637e0;
struct C4 { u8 r, g, b, a; };
struct O2ed { void* vt; u32 a, b, c, d, e; C4 col; u32 f; };
// Constructor: zeroed fields, colour 128/128/128/128.
void func_002edf28(O2ed* o) {  // obj_ctor_3637e0
    o->a = 0;
    o->c = 0;
    o->vt = &D_003637e0;
    o->b = 0;
    o->d = 0;
    o->e = 0;
    C4* c = &o->col;
    s32 v = 128;
    c->r = v;
    c->g = v;
    c->b = v;
    c->a = v;
    o->f = 0;
}

extern u8 D_00347e60;
extern u8 D_00347e40;
extern u8* D_00347f80;
void func_00239870(void*);
void func_0031a840(void*);
void func_0031cd50(void*);
void func_0031c928(u32* o) {
    o[0] = (u32)&D_00347e60;
    func_00239870(o + 6);
    func_0031a840(o);
    VObj* m = *(VObj**)(D_00347f80 + 20);
    ((VFn)m->vt[1])(m, o);
}

void func_0031c9a8(u32* o) {
    o[0] = (u32)&D_00347e40;
    func_0031cd50(o);
    VObj* m = *(VObj**)(D_00347f80 + 20);
    ((VFn)m->vt[1])(m, o);
}

extern u8 D_0034c720;
extern VObj* D_0034c738;
void func_00160268(void*);
void func_0031e110(u32* o) {
    o[0] = (u32)&D_0034c720;
    func_00160268(o);
    VObj* m = D_0034c738;
    ((VFn)m->vt[1])(m, o);
}
}
