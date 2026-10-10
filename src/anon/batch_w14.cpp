#include "../common/types.h"

extern "C" {
void func_00102730(void*);
void* func_00124748(void*, s32);  // list_nth_node_rel
void func_00113668(void*);
void func_00105110(void*);
void func_00124c08(void*);  // set_vtbl_347b88
void func_00106420(void*);
void func_001391c8(void*, s32, s32);
void func_001666a0(void*);  // zero_fields_0_4_6_8
void func_00138c10(void*, s32);
void* func_001dc648(void*);
void func_0014d358(void*, s32, void (*)(void), s32);
void func_0016f9e8(void);
void func_00140db0(void*);
void func_00182f28(s32);  // store_global_35ed04
void func_001d69d0(void*);
s32 func_0017ec98(void*, s32);
s32 func_0017edf0(void*, s32);
s32 func_00180408(void*, s32);
void* func_00188fe0(void*, void*);
void func_00188948(void*, void*, void*);
void func_0019cc20(void*);
void* func_001d5af8(void*, void*, void*);
void* func_00102c18(s32, s32, void (*)(void));
void func_001b4340(void);
void func_001b43e0(void);
void func_0016cfa0(void*, s32, void*, void*, void*);
s32 func_001bb4a0(void);
void func_001c6fa8(void*, void*, void*, void*, void*);
void func_001a4e30(void*);
void func_001d2710(void*);
void func_002f25a0(s32, s32);
u8 func_002f3918(void*, void*);
void func_00228918(void*);
void func_002f2be0(void*, void*);
void func_0023c300(void*);
u8* func_001058e8(void);
void func_002fde18(void*, s32, s32);
void func_00242880(void);
void func_0023d410(void);
void func_00257000(void);
void func_002878c8(void*);
u8 func_0023f848(void*);
void func_0028b8a0(void*);
void func_0023f820(void*);
void func_00292998(void);
s32 func_001b6d70(u8);  // table_entry_ptr_b
void func_002bf650(void*, s32);
void func_002d2948(void*, void*, s32, void*);
void func_002e7308(void*);
void func_0031fec0(void*);

struct ChangeFlag { u8 changed; };

extern u8 D_00346960[];
extern u8 D_00347bb0[];
extern u8 D_01c5c460[];
extern u32 D_0034aa70[5];
extern ChangeFlag D_0034aa40;
extern void* D_00350444;
extern void* D_01d48cb0;
extern u8* D_01d49320;
extern void* D_00351ff0[];
extern void* D_00351fe4;
extern u16 D_0032fafe[];
extern u8* D_00352ae0;
extern void* D_003591c8;
extern u8 D_003598e0[];
extern u8 D_0035eb08[];
extern void** D_0035ecbc;
extern u8 D_0035f3a0[];
extern u16 D_0035f4d8;
extern void* D_0035f4d4;
extern s32 D_0035f4bc;
extern u8 D_003621a0[];
extern s32 D_01e2bfa4;
extern u8* D_01e2bfa0;
extern u8 D_0034b268[];
extern void** D_0034b278;
extern u8 D_00351100[];

void LOCKON_dtor(void*) asm("_ZN2YS6LOCKOND1Ev");
void TargetCamera_change(u32*) asm("_ZN2dk12TargetCamera6changeEPN2YS6TARGETE");
s32 MOTION_is_exist(void*, s32) asm("_ZN2YS6MOTION8is_existEi");
void INDICATION_disable(u8*) asm("_ZN2YS10INDICATION7disableEv");
void u_call4_001d2210(u32, u32, u32, u32) asm("_Z16u_call4_001d2210jjjj");
void u_call4_00139d78(u32) asm("_Z16u_call4_00139d78jjjj");

// Virtual call: slot 1 with (this, this) after a helper.
void func_00102750(void** p) {
    func_00102730(p);
    (*(void (**)(void*, void*))(*(u8**)p + 4))(p, p);
}

// Counts the nodes of the list headed at p+8 (linked through +56).
static inline u8* next_node(u8* p, u8* q) {
    if (!q) return *(u8**)(p + 8);
    return *(u8**)(q + 56);
}

s32 func_00102a08(u8* p) {
    s32 n = 0;
    u8* q = 0;
    while ((q = next_node(p, q))) n++;
    return n;
}

void func_00114de0(u8* p) {
    *(u8**)p = D_00346960;
    func_00113668(p);
    func_00105110(p);
}

void func_00124100(void* a, s32 b) {
    void** o = (void**)func_00124748(a, 0);  // list_nth_node_rel
    (*(void (**)(void*, s32))(*(u8**)o + 44))(o, b);
}

void func_00128008(u8* p) {
    *(u8**)p = D_00347bb0;
    func_00124c08(p);  // set_vtbl_347b88
    func_00106420(p);
}

void func_00137c50(u8* p) {
    *(s32*)(p + 10696) = 0;
    *(s32*)(p + 32) = 1;
    *(s32*)(p + 48) = 0;
    *(s32*)(p + 52) = 0;
    *(s32*)(p + 10692) = 0;
    *(s32*)(p + 10688) = 1;
    func_001391c8(p, 11100, 0);
}

struct Entry20 { u8 pad[16]; u8 on; u8 id; u8 pad2[2]; };

// Clears the 'on' flag of every entry whose id matches.
void func_001418e8(u8* p, u8 id) {  // clear_records_by_index
    s32 n = *(s32*)(p + 36);
    s32 i;
    for (i = 0; i < n; i++) {
        if ((*(Entry20**)(p + 8))[i].id == id) (*(Entry20**)(p + 8))[i].on = 0;
    }
}

void func_0014dc08(u8* p) {
    func_001666a0(p);  // zero_fields_0_4_6_8
    *(s32*)(p + 464) = 0;
    *(s16*)(p + 468) = 0;
    p[470] = 0;
    p[471] = 0;
    p[472] = 0;
    p[473] = 0;
}

void func_00151b40(u8* p) {
    func_00138c10(p + 840, 0);
    func_00138c10(p + 2472, 6);
}

// Copies the new target into the camera state and flags the change.
void TargetCamera_change(u32* t) {
    D_0034aa70[0] = t[0];
    D_0034aa70[1] = t[1];
    D_0034aa70[2] = t[2];
    D_0034aa70[3] = t[3];
    D_0034aa70[4] = t[4];
    D_0034aa40.changed = 1;
}

void func_001668f8(u8* p) {
    func_001666a0(p);  // zero_fields_0_4_6_8
    *(s16*)(p + 12) = 0;
    p[14] = 1;
    *(s16*)(p + 10) = 0;
}

// 128-bit copy of p[1] into the quadword returned for p[0] (skipped on self-copy).
void func_0016e200(void** p) {
    u8* d = (u8*)func_001dc648(p[0]);
    u8* s = (u8*)p[1];
    if (d != s) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
    }
}

void func_0016fa58(void) {
    func_0014d358(D_01c5c460, 0x3000, func_0016f9e8, 0);
}

void func_001781e8(u8* p) {
    func_00140db0(p);
    func_00182f28(0);  // store_global_35ed04
    func_001d69d0(*(void**)(p + 2876));
    *(void**)(p + 2876) = 0;
}

// Number of decimal digits of n (0 for n <= 0).
s32 func_0017d930(s32 n) {
    s32 c = 0;
    s32 t = 1;
    while (t <= n) {
        t *= 10;
        c++;
    }
    return c;
}

s32 MOTION_is_exist(void* m, s32 i) {
    return func_00180408(m, func_0017edf0(m, func_0017ec98(m, i))) != 0;
}

void func_00189028(void* a, void* b, void* c, void* d) {
    func_00188948(func_00188fe0(a, b), c, d);
}

// Destructor: clears the global current-lockon pointer if it is this one.
void LOCKON_dtor(void* l) {
    func_0019cc20(l);
    D_00350444 = D_00350444 == l ? 0 : D_00350444;
}

void func_001a0678(void** p) {
    p[0] = func_001d5af8(p[0], p[1], p[2]);
}

void func_001b4300(void) {
    D_01d48cb0 = 0;
    u8* p = (u8*)func_00102c18(1, 0x5078, func_001b4340);
    *(void (**)(void))(p + 48) = func_001b43e0;
}

void func_001b58b8(void* a, void* b, void* c) {
    func_0016cfa0(*(void**)((u8*)D_01d48cb0 + 52), 0, a, b, c);
}

struct Flags16 { u16 lo:9; u16 bit9:1; u16 hi:6; };

u8 func_001bb9f0(void) {
    u8 r = 0;
    if (func_001bb4a0()) r = ((Flags16*)(*(u8**)(D_01d49320 + 8) + 4))->bit9;
    return r;
}

void func_001ca950(u8* p, void* a, void* b, void* c, void* d, u32 e) {
    func_001c6fa8(p, a, b, c, d);
    *(u32*)(p + 84) = e;
    *(u32*)(p + 88) = 0;
}

void func_001cbbf8(u8* p) {
    *(void**)p = D_00351ff0;
    D_00351fe4 = 0;
    func_001a4e30(p);
    func_00105110(p);
}

void INDICATION_disable(u8* p) {
    func_001d2710(p + 2932);
    func_0019cc20(*(void**)(p + 2880));
    *(u32*)(p + 268) |= 0x200000;
}

void u_call4_001d2210(u32 a0, u32, u32, u32) {
    u8* p = (u8*)a0;
    if (*(u32*)(p + 12) & 4) {
        (*(void (**)(void*))(*(u8**)p + 8))(p);
    }
}

// Increments the counter, saturating at 999.
void func_001d97c8(void) {
    if (D_0032fafe[1] < 999) D_0032fafe[1]++;
}

void func_001ddc08(void) {
    u8* p;
    for (p = D_00352ae0; p; p = *(u8**)(p + 40)) {
        *(u32*)(p + 8) |= 0x4000000;
    }
}

s32 func_0020f118(void) {
    func_002f25a0(0, 0);
    return func_002f3918(D_003591c8, D_003598e0);
}

void func_002289c0(void** p) {
    (*(void (**)(void*))(*(u8**)p + 28))(p);
    func_00228918(p);
}

void func_002368b0(u8* p) {
    func_002f2be0(p + 64, *(void**)(p + 56));
    func_002f2be0(p + 160, *(void**)(p + 60));
}

void func_00237458(u8* p, u32 i, s32 j, s32 v) {  // entry20_accumulate
    u8* t = *(u8**)(p + 12);
    s32* e = (s32*)(*(u8**)(p + 8) + (*(u16*)(i * 4 + (u32)t) + j) * 20);
    e[2] = v + e[2] - e[0];
    e[0] = v;
}

void func_0023c0c0(u8* p) {
    *(u8**)p = D_0035eb08;
    func_0023c300(p);
    func_00106420(p);
}

void func_0023d3d0(void) {
    func_002fde18(func_001058e8() + 16796, 0, 5124);
    func_00242880();
    func_0023d410();
    func_00257000();
}

void func_00242368(void* a) {
    if (a) {
        void** o = D_0035ecbc;
        (*(void (**)(void*, void*))(*(u8**)o + 4))(o, a);
    }
}

s32 func_00287720(u8* p) {
    func_002878c8(p);
    void** o = *(void***)p;
    (*(void (**)(void*))(*(u8**)o + 20))(o);
    return func_0023f848(p + 12);
}

void func_0028b830(u8* p) {
    *(u8**)p = D_0035f3a0;
    func_0028b8a0(p);
    func_0023f820(p);
    func_00106420(p);
}

void func_0028e710(u32 p, u32 a) {
    u_call4_00139d78(p);
    *(u32*)(p + 48) = a;
}

void func_00292a58(void) {
    D_0035f4d8 = 0;
    func_002fde18(D_0035f4d4, 0, D_0035f4bc << 4);
    func_00292998();
}

void func_002bf618(u8* p) {
    func_002bf650(p, func_001b6d70((*(u8**)(p + 2808))[4]));
}

void func_002d4200(u8* p, void* a, void* b) {
    func_002d2948(p, a, 1, b);
    *(u8**)p = D_003621a0;
    func_002e7308(p + 3208);
}

// Skips n variable-length records (64 bytes + 12 per sub-entry) after a 16-byte header.
u8* func_002e34d8(u8** p, s32 n) {  // list_walk_stride12
    u8* q = *p;
    q += 16;
    if (n > 0) do {
        q += q[10] * 12 + 64;
    } while (--n);
    return q;
}

// Returns a 64-byte block to the pool's free list.
void func_002e98b0(u8* e) {
    u8* b = D_01e2bfa0;
    D_01e2bfa4--;
    s32 n = *(s32*)(b + 2040);
    u8* s = (u8*)(n * 4) + (u32)b;
    n++;
    *(s32*)(b + 2040) = n;
    *(s32*)(s + 1920) = (e - b) >> 6;
}

// Reads a 7-bit varint; returns the pointer past it.
u8* func_00314b00(u8* p, s64* out) {
    s32 shift = 0;
    s64 v = 0;
    u32 b;
    do {
        b = *p++;
        v |= (s32)((b & 0x7f) << shift);
        shift += 7;
    } while (b & ~0x7f);
    *out = v;
    return p;
}

void func_0031e008(u8* p) {
    *(u8**)p = D_0034b268;
    void** o = D_0034b278;
    (*(void (**)(void*, void*))(*(u8**)o + 4))(o, p);
}

void func_00320118(u8* p) {
    *(u8**)p = D_00351100;
    func_0031fec0(p);
    func_00105110(p);
}
}
