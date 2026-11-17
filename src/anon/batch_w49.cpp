#include "../common/types.h"

extern "C" {
void Obj2D_showGroup(int) asm("_ZN2dk5Obj2D9showGroupEi");
void ttarget0_001bfc28(void) asm("_Z17ttarget0_001bfc28v");
void wtarget_001c05b0(u32, u32, u32, u32) asm("_Z16wtarget_001c05b0jjjj");

void func_0011c798(u32, u32);
void func_0011ca20(u32, u32, u32, u32, u32);
void func_0011cd80(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);  // 0x0011cd80: definition moved into src/anon/unit_0011c128.cpp

struct Node139858 { u32 f0; Node139858* next; u8 pad8[8]; s32 group; };
struct List139858 { u32 f0; Node139858* head; };
extern List139858* D_00347f80;
void func_00139580(Node139858*);
static inline Node139858* next139858(Node139858* o) {
    List139858* l = D_00347f80;
    if (!o) return l->head;
    return o->next;
}
void Obj2D_showGroup(int group);  // 0x00139858: definition moved into src/anon/unit_001393c8.cpp

s32 func_00141080(f32);
void func_001ad990(u32, f32, f32, f32);
struct S348710 { u8 pad[64]; u32 f64; u32 f68; };
extern S348710 D_00348710;
void func_00141010(f32 x);  // 0x00141010: definition moved into src/anon/unit_0013fca8.cpp



void func_0014b5e8(u32, u64, u64);
// 0014b4b0: moved to src/anon/unit_0014b150.cpp


struct E34a790 { u8 pad[48]; u8 f48; u8 pad2[15]; };
struct E34a778 { u32 id; u8 pad[20]; };
extern E34a790* D_0034a790;
extern s32 D_0034a77c;
extern E34a778* D_0034a778;
void func_00153948(u8 id);  // 0x00153948: definition moved into src/anon/unit_00153678.cpp

void func_00138c10(u8*, s32);
// 00154b98: moved to src/anon/unit_00153ea0.cpp
void func_00154b98(u8* p, s32 n);

struct Node161248 { u8 pad[128]; Node161248* next; };
extern Node161248* D_004f3b38;
void func_00160940(Node161248*, u32, f32);
static inline Node161248* next161248(Node161248* n) {
    if (!n) return D_004f3b38;
    return n->next;
}
// 00161248: moved to src/anon/unit_001611a8.cpp

u8* func_001a6a20(u32, u32);
s32 func_00176a90(u32);
// 00179b68: moved to src/yasui/libys/player.cpp

extern s32 D_0034ed00;
struct E1c60588 { u32 a, b, c; };
extern E1c60588 D_01c60588[];
void func_00182910(E1c60588*);
// 00182ab0: moved to src/anon/unit_00182780.cpp

typedef s32 (*Fn184478)(void*);
// 00184478: moved to src/anon/unit_00183088.cpp




void func_00239700(u8*);
void func_001abb28(u8*);
u32 func_001ab810(void);  // get_global_1c7cec0
u32 func_001ab800(void);
void func_00239988(u8*, u32, u32);
// 001abd30: moved to src/anon/unit_001abb28.cpp

u8* func_001b9bc8(u8*);
typedef void (*Fn1bf6a8)(u8*);
void func_001bf6a8(void);  // 0x001bf6a8: definition moved into src/anon/unit_001bc568.cpp

extern u32 D_0034e948;
void func_001bf378(u8*, u32);
void ttarget0_001bfc28(void);  // 0x001bfc28: definition moved into src/anon/unit_001bc568.cpp

extern u32 D_01d49328[8];
struct S1d49350 { u32 a, b; };
extern S1d49350 D_01d49350;
void wtarget_001c05b0(u32 a, u32 b, u32, u32);  // 0x001c05b0: definition moved into src/anon/unit_001bff88.cpp

void func_001980d0(u8*, u32, s32, u32);
s32 func_0016a020(u8*);
extern u8 D_003513a8[];
// 001c2338: moved to src/anon/unit_001c0638.cpp
void func_001c2338(u8* p, u32 a, u32 b);

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
// 001c7148: moved to src/anon/unit_001c7148.cpp (linked unit)

u8* func_001d6cc8(u8*);
s32 func_001a3570(u16);
void func_001d6da8(u16* out);  // 0x001d6da8: definition moved into src/anon/unit_001d68e0.cpp

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
s32 func_0027ae78(s32 n);  // 0x0027ae78: definition moved into src/anon/unit_0027a6d8.cpp

extern s8* D_0035f5ac;
extern char* D_0035f5c8;
extern char* D_0035f5cc;
u32 func_00293de8(s32);
void func_00293cb8(char*, s32, u32);
char* func_002ff918(char*, const char*);
void func_002931a8(char*);
void func_0029dd00(void);  // 0x0029dd00: definition moved into src/anon/unit_0029d008.cpp

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
void func_002bcee8(u32* p);  // 0x002bcee8: definition moved into src/anon/unit_002bc978.cpp

struct B2bf5a0 { u8 b0 : 1; };
u8* func_001b6d70(u8);  // table_entry_ptr_b
void func_0016ac38(u8*, s32, s32, s32, s32);
void func_002bf5a0(u8* p);  // 0x002bf5a0: definition moved into src/anon/unit_002bebd0.cpp


void func_002eb778(u8*, u32, s32, f32);
// 002ec170: moved to src/anon/unit_002eaf38.cpp

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
void func_00141988(u8* o, Idx141988* ix, Out141988* out);  // 0x00141988: definition moved into src/anon/unit_00141458.cpp

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
void func_00196288(u32 a);  // 0x00196288: definition moved into src/anon/unit_00195d00.cpp

// Takes an entry from the 4-slot free list and pushes it on the active list.
struct E199468 { u32 f0, f4, f8, f12; f32 f16; E199468* next; };
struct P199468 { E199468 e[4]; s32 freeIdx[4]; s32 n; };
union H199468 { E199468* p; s32 i; };
struct L199468 { H199468 head; E199468* tail; };
extern P199468 D_01c620c8;
extern L199468 D_01c62140;
// 00199468: moved to src/anon/unit_001991a8.cpp

struct NoTail { ~NoTail() {} };

void func_001e6000(u8*);  // obj_dec_timer
void func_001e6038(u8* p);  // 0x001e6038: definition moved into src/anon/unit_001e0cb8.cpp

// Runs every registered handler's optional callback (slot +16).
typedef void (*Fn1e7810)(u8*);
struct O1e7810 { u8 pad[100]; s32 n; u8 pad2[16]; u8** tbl; };
void func_001e7810(O1e7810* p);  // 0x001e7810: definition moved into src/anon/unit_001e0cb8.cpp

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
void func_001e8bb8(u8* p);  // 0x001e8bb8: definition moved into src/anon/unit_001e8ac8.cpp

void sceGsExecLoadImage(u8*, u32);
void func_002367c8(u8* p) {  // obj_dispatch_bitfield64
    if (((s32)(*(s64*)(p + 48) >> 32) & 1) == 0) sceGsExecLoadImage(p + 64, *(u32*)(p + 56));
    if (((*(u64*)(p + 48) >> 33) & 1) == 0) sceGsExecLoadImage(p + 160, *(u32*)(p + 60));
}

// Returns 1 if the current id is in the -1-terminated list.
u16* func_002632d0(void);
extern s16 D_00373270[];
s32 func_002636b0(void);  // 0x002636b0: definition moved into src/anon/unit_002632d0.cpp

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
void func_0018f940(u32* p);  // 0x0018f940: definition moved into src/anon/unit_0018f140.cpp

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
