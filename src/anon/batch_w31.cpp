#include "../common/types.h"

typedef void (*VFn)(void*);

extern "C" {
u8* func_00102818(u32, s32, u32, void*, s32);
void func_0014a0a0(void);
extern u32 D_0032b96c;
void TitleStart(bool) asm("_ZN2dk5Field10TitleStartEb");

extern void* D_0034a42c;
int func_00150bc0(void*);
void func_00150940(void*, u32);
void func_001507b8(void*, u32);

u32 func_00154ee8(void*);  // field24_state_code
void func_00138c10(void*, u32);
void func_00154408(void*, u32);

void func_00167658(void*, int);
u64 func_00167cd0(void*);



extern u8 D_01c5f480[];
void func_001a7888(void*, u32, int, f32, f32);
void* func_001a78c0(void*, u32, int, f32, f32, f32, f32);
void func_001a7a48(void*, u32, int, f32, f32);
void func_001a7da8(void*, void*, f32, f32);

void* func_0016a070(void*);
u32 func_001afee8(void*, int);
void func_00198630(void*, u32, int);
void voice_part(void*, int) asm("_ZN2YS5PARTY10voice_partEi");

void func_00179f10(void*);
void func_001d6ab0(u32);


void** func_0017aab8(int);

extern u8* D_01c6cb90;

void func_001ad280(void*);
extern void* D_00350a70[];
extern u8 D_00350a56;
void func_001c1130(int);  // copy_record_block_to_table
void func_0014c9d8(int);

int func_001c9ab8(void*);
int func_001c99b0(int);

extern u8* D_01d5baa8;
void* func_00185da8(void*);
int func_0019c410(void*);

extern void* D_00352bd0;
void func_001e2898(void*);
void func_00105110(void*);

extern char D_00370bd8[];
extern char D_00370bf8[];
void func_002fdfc8(const char*, ...);  // device_vprintf_va

extern u32 D_0033caf4;
extern char D_01dad960[];
extern char D_00371190[];
void func_002fee78(char*, const char*, ...);
void func_002ff3fc(char*);  // strlen
}

// Queue a target-event entry into the 64-slot ring; returns its serial number.
extern "C" {
extern u32 D_0035e360;
extern u32 D_0035e368;
struct TargetEv { u32 active, serial, a, b, c, pad[3]; };
extern TargetEv D_01dadc00[];
}
u32 wtarget_00234098(u32 a, u32 b, u32 c, u32 d) {
    u32 idx = D_0035e360;
    u32 serial = D_0035e368;
    TargetEv* e = &D_01dadc00[idx];
    e->active = 1;
    e->a = a;
    e->b = b;
    e->serial = serial;
    e->c = c;
    D_0035e360 = (idx + 1) & 63;
    D_0035e368 = serial + 1;
    return serial;
}

extern "C" {
u8* func_00294000(int);
int func_00295158(u32);
u32* func_002b23e0(int);  // list_entry_by_index_checked
extern u32 D_00374ca4;
extern u32 D_00374ca8;
extern char D_01e2a5a8[];
extern char D_00374f80[];
extern void* D_003621a0[];
void func_002e7328(void*);  // to_2e7458
void func_002d2a08(void*);
void func_002cfeb0(void*, u32, int, u32);  // obj_init_field1416_bit800
extern void* D_003627c8[];
void func_002cf280(void*, int, int);
u8* func_002dc7c8(void*);
extern void* D_00362eb8[];
void func_002e70b0(void*);
void func_00106420(void*);
void func_002cea28(void*);
void func_00106450(void*);
void func_001d3698(void*, u32);
extern u8 D_01e2bf80[];
void func_00195858(void*, int);
extern void* D_00347f98[];
extern u8* D_00347f80;
extern void* D_0034ee08[];
void func_0019f9a8(void*);  // array8_free_slots
void func_001c0248(void*);
void func_00319fb0(void*);  // big_obj_dtor
extern void* D_00363880[];
extern void* D_003637e0[];
void func_0023c098(void*);  // set_vtbl_36eae8_then_call
void func_002369f0(void*);  // set_vtbl_36eac8_then_call


// dk Field: start the title task.
void TitleStart(bool flag) {
    u8* t = func_00102818(D_0032b96c, 0, 0x493e0, (void*)func_0014a0a0, 4096);
    t[4] = flag;
}

void func_0014f578(u32 a) {
    if (func_00150bc0(D_0034a42c)) {
        func_00150940(D_0034a42c, a);
    } else {
        func_001507b8(D_0034a42c, a);
    }
}

void func_00155410(u8* p) {
    u32 v = **(u32**)(*(u8**)(p + 52) + 1164);
    *(u32*)(p + 40) = v;
    *(u32*)(p + 36) = v;
    func_00138c10(p + 916, func_00154ee8(p));
    func_00154408(p + 64, *(u32*)(p + 24));
}

void func_00167e28(u8* p) {
    *(u32*)(p + 72) &= ~1;
    func_00167658(p, 0);
    *(u64*)p = func_00167cd0(p);
}

void func_00173558(u8* p) {
    u32 tmp[4] __attribute__((aligned(16)));
    func_001a7888(tmp, *(u32*)p, 1, *(f32*)(p + 4), *(f32*)(p + 8));
    u8* d = D_01c5f480;
    if ((u8*)tmp != d) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(tmp) : "$8", "memory");
    }
    *(u8**)p = d;
}

void func_001735b0(u8* p) {
    u32 tmp[4] __attribute__((aligned(16)));
    func_001a78c0(tmp, *(u32*)p, 2, *(f32*)(p + 4), *(f32*)(p + 8), *(f32*)(p + 12), *(f32*)(p + 16));
    u8* d = D_01c5f480;
    if ((u8*)tmp != d) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(tmp) : "$8", "memory");
    }
    *(u8**)p = d;
}

// YS PARTY: play a party member's voice.
void voice_part(void* self, int n) {
    func_00198630(self, func_001afee8(func_0016a070(self), n), 0);
}

typedef int (*VFn4)(void*, u32, int, int);
int func_00179f80(u8* p) {
    func_00179f10(p);
    func_001d6ab0(*(u32*)(p + 2876));
    u32 a = *(u32*)(*(u8**)(p + 1164) + 4);
    return (*(VFn4*)(*(u8**)p + 120))(p, a, 0, 0);
}

typedef void (*VFn3)(void*, void*, u32);
void* func_001a07b0(void* p, u32 a, u32 b) {
    void** o = func_0017aab8(5);
    (*(VFn3*)(*(u8**)o + 28))(p, o, b);
    return p;
}

void* func_001a78c0(void* out, u32 a, int b, f32 x, f32 y, f32 z, f32 w) {
    u8 tmp[48];
    func_001a7a48(tmp, a, b, x, y);
    func_001a7da8(out, tmp, z, w);
    return out;
}

// Find the 24-byte table entry whose u16 id matches.
u8* func_001a80c8(int id) {  // table24_find_by_id
    u8* t = D_01c6cb90;
    s32 n = *(s32*)(t + 4);
    u8* e = t + 8;
    for (s32 i = 0; i < n; i++, e += 24) {
        if (*(u16*)e == id) return e;
    }
    return 0;
}

void func_001ad5a8(void** p) {
    func_001ad280(p);
    *p = D_00350a70;
    D_00350a56 = 1;
    func_001c1130(12);  // copy_record_block_to_table
    func_0014c9d8(8);
}

int func_001c9b38(u8* p) {
    int r;
    switch (*(u16*)(p + 2)) {
    case 4:
        return func_001c99b0(*(s16*)(p + 4));
    case 72:
        r = 2;
        if (!func_001c9ab8(p)) goto out;
    default:
        r = 0;
    }
out:
    return r;
}

int func_001ca448(u8* p) {  // type_is_16_44_161
    switch (*(s32*)(p + 340)) {
    case 16:
    case 44:
        return 0;
    case 161: {
        u32 m = *(u32*)(p + 1416) & 0x80;
        return m == 0;
    }
    default:
        return 1;
    }
}

// Next 10-byte entry after e (or the first when e is null); null past the end.
u8* func_001d9e30(u8* e) {  // record_range_check_or_first
    if (e == 0) return D_01d5baa8 + 8;
    e += 10;
    u8* t = D_01d5baa8;
    return e < t + *(s32*)(t + 4) * 10 + 8 ? e : 0;
}

void func_001dbb38(void) {
    void* o = 0;
    while ((o = func_00185da8(o)) != 0) {
        if (func_0019c410(o)) {
            (*(VFn*)(*(u8**)o + 32))(o);
            return;
        }
    }
}

// Look up key in a 32-byte record table; outputs the record's first two words.
bool func_001dc018(u8** p, s32 key, u32* a, u32* b) {
    u8* t = *p;
    s32 n = *(s32*)(t + 12);
    u8* e = t + 16;
    int r = 0;
    for (s32 i = 0; i < n; i++, e += 32) {
        if (*(s32*)(e + 8) == key) {
            *a = *(u32*)e;
            *b = *(u32*)(e + 4);
            r = 1;
            break;
        }
    }
    return r;
}

void func_001e2998(void) {
    void* o = D_00352bd0;
    if (o) {
        func_001e2898(o);
        func_00105110(o);
    }
    D_00352bd0 = 0;
}

// Print two messages and trap.
void func_002233f0(u32 a, u32 b, u32 c) {
    func_002fdfc8(D_00370bd8, a);  // device_vprintf_va
    func_002fdfc8(D_00370bf8, b, c);  // device_vprintf_va
    asm volatile("break");
}

char* func_0022c4b8(u32 x) {
    func_002fee78(D_01dad960, D_00371190, D_0033caf4, x);
    func_002ff3fc(D_01dad960);  // strlen
    return D_01dad960;
}

struct KV { s16 k; u16 v; };
extern KV D_00372be0[];
// Map key to value through a table terminated by a negative key; -1 if absent.
int func_002594b8(int k) {
    int r = -1;
    for (s32 i = 0; D_00372be0[i].k >= 0; i++) {
        if (D_00372be0[i].k == k) {
            r = D_00372be0[i].v;
            break;
        }
    }
    return r;
}

void* memset_(void*, int, u32) asm("func_002fde18");
void func_00281f90(u8* p) {
    *(s32*)(p + 4104) = -1;
    *(s32*)(p + 4108) = -1;
    u32* q = (u32*)(p + 4112);
    for (s32 i = 4; i >= 0; i--) *q++ = 0;
    memset_(p + 4132, 0, 64);
}

s8 func_00295228(u32 x) {
    u8* base = func_00294000(0) + 16;
    return *(s8*)(base + func_00295158(x) * 16);
}

u32 func_002b1aa0(void) {
    u32 f = *func_002b23e0(-1);  // list_entry_by_index_checked
    if (f & 0x04000000) return 20690;
    if (f & 0x10000000) return D_00374ca4;
    return D_00374ca8;
}

char* func_002ba0f8(u32 x) {
    func_002fee78(D_01e2a5a8, D_00374f80, x);
    func_002ff3fc(D_01e2a5a8);  // strlen
    return D_01e2a5a8;
}

extern u32 D_01e2aa80;
static inline u8* nextNode(u8* n) {
    if (!n) return (u8*)D_01e2aa80;
    return *(u8**)(n + 28);
}
// Clear flag 4 on every list node whose type byte is 2.
void func_002bbe80(void) {
    u8* n = 0;
    while ((n = nextNode(n)) != 0) {
        if (n[49] == 2) *(u32*)(n + 36) &= ~4;
    }
}

void func_002d4828(void** p) {
    *p = D_003621a0;
    func_002e7328((u8*)p + 3208);  // to_2e7458
    func_002d2a08(p);
    func_00105110(p);
}

void func_002dac50(u8* p, u32 a, u32 b) {
    func_002cfeb0(p, a, 3, b);  // obj_init_field1416_bit800
    *(u32*)(p + 2836) = 0;
    *(u8*)(p + 2840) = 0;
    *(void***)p = D_003627c8;
    *(u32*)(p + 2844) = 0;
    func_002cf280(p + 2800, 1, 0);
}

f32 func_002dc808(u8* p) {
    if (*(u32*)(p + 0x8070)) return *(f32*)(func_002dc7c8(p) + 180);
    return *(f32*)func_002dc7c8(p);
}

// Empty-destructor local: keeps the final call from becoming a tail call.
struct NoTail { ~NoTail() {} };
void func_002e2298(void** p) {
    NoTail g;
    *p = D_00362eb8;
    void* o = p[27];
    if (o) {
        func_002e70b0(o);
        func_00106420(o);
    }
    func_002cea28(p);
}

void operator delete[](void*) asm("func_00106450");
struct Elem64 { u8 d[64]; ~Elem64() {} } __attribute__((aligned(16)));
// delete[] of an array of 64-byte elements with an empty destructor.
void func_002e7058(u8* p) {
    delete[] *(Elem64**)(p + 4);
}

void func_002e8578(u8* p) {
    u32 tmp[4] __attribute__((aligned(16)));
    func_001d3698(tmp, *(u32*)p);
    u8* d = D_01e2bf80;
    if ((u8*)tmp != d) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(tmp) : "$8", "memory");
    }
    *(u8**)p = d;
}

typedef void (*VFn2)(void*, void*);
void func_002ece48(void** p, u8* q) {
    func_00195858(q + 272, 63);
    (*(VFn2*)(*(u8**)p + 36))(p, q);
}

// Unpack a single-precision float into class/sign/exponent/fraction.
void func_00314640(u32* in, s32* out) {
    u32 v = *in;
    u32 frac = v & 0x7fffff;
    out[1] = v >> 31;
    u32 exp = (v >> 23) & 0xff;
    if (exp == 0) {
        out[0] = 2;
        return;
    }
    out[2] = exp - 127;
    out[0] = 3;
    out[3] = (frac << 7) | 0x40000000;
}

void func_0031c0b8(void** p) {
    *p = D_00347f98;
    void* o = *(void**)(D_00347f80 + 20);
    (*(VFn2*)(*(u8**)o + 4))(o, p);
}

void func_003218c8(void** p) {
    NoTail g;
    *p = D_0034ee08;
    func_0019f9a8((u8*)p + 2568);  // array8_free_slots
    func_001c0248((u8*)p + 2640);
    func_00319fb0(p);  // big_obj_dtor
}

void func_00321910(void** p) {
    *p = D_0034ee08;
    func_0019f9a8((u8*)p + 2568);  // array8_free_slots
    func_001c0248((u8*)p + 2640);
    func_00319fb0(p);  // big_obj_dtor
    func_00105110(p);
}

void func_00325ae8(void** p) {
    *p = D_00363880;
    func_0023c098((u8*)p + 64);  // set_vtbl_36eae8_then_call
    func_002369f0((u8*)p + 40);  // set_vtbl_36eac8_then_call
    *p = D_003637e0;
    func_00106420(p);
}
}
