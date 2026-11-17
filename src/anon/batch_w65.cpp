#include "../common/types.h"

// 16-byte vector; assignment copies with a 128-bit lq/sq.
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

// 4x4 matrix of Vq rows; assignment copies 64 bytes with lq/sq.
struct Mq {
    Vq r[4];
    Mq& operator=(const Mq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
};

// Vector returned by value: copy construction is a 128-bit lq/sq.
struct Vr {
    f32 x, y, z, w;
    Vr() {}
    Vr(const Vr& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));

// Reset three fade entries (count, alpha 255) when called with (1, 0xffff).
struct FadeEnt { u32 pad[3]; u32 count; f32 alpha; };
extern FadeEnt D_004f3694;
extern FadeEnt D_004f36ec;
extern FadeEnt D_004f3744;
void wtarget_0015ccf0(u32 a, u32 b, u32 c, u32 d);  // 0x0015ccf0: definition moved into src/anon/unit_0015cb18.cpp

extern "C" {
s32 YS_ITEM_Reduce(s32, s32) asm("_ZN2YS4ITEM6ReduceEii");
void SEQ_GetActiveXY(u8* p, s32* x, s32* y) asm("_ZN2YI8SEQUENCE11GetActiveXYEPiS1_");
void Sel_SetSequence(u8* p, s32 a) asm("_ZN2Tz6Select11SetSequenceEz");

s32 func_00139d78(void*);
void func_00105110(void*);
void func_0031a838(void*);

// Index of x in the 7-entry table, else 7 + secondary lookup.
extern s16 D_00345d30[];
s32 func_00114738(s32);
s32 func_001145b0(s32 x);  // 0x001145b0: definition moved into src/anon/unit_001142a0.cpp

// Unlink the node with this key from the list at +292 and hand it to the owner's release method.
struct Node { s32 key; u32 pad; Node* prev; Node* next; };
struct VObj { void** vt; };
void func_0011ecc8(u8* p, s32 key);  // 0x0011ecc8: definition moved into src/anon/unit_0011c128.cpp

// Constructor: base init, vtable, then collect flag bits 0 / 29 of each 32-byte entry.
struct FlagEnt { u32 f; u32 x[7]; };
struct FlagHdr { u8 pad[28]; s32 n; FlagEnt e[1]; };
void func_0011ee18(void*);  // obj_ctor_347940
extern u8 D_00347a28[];
void func_001206e0(u32* p);  // 0x001206e0: definition moved into src/anon/unit_00120520.cpp

void func_00139510(void*);
void func_001b2028(u32);
void func_001991a8(s32, s32);
void func_00137630(u8* p);  // 0x00137630: definition moved into src/anon/unit_001374c8.cpp

// Rebuild the cached text when the current value changes.
extern u8 D_0032bae0;
extern u32 D_00347fe8;
extern u8 D_003b8b80[];
extern u8 D_003b8bc0[];
extern char D_0036acf0[];
extern u32 D_0033caf4;
u32 func_00105ee8(u32);
void func_002fee78(void*, const char*, u32, u32);
void func_001688c8(void*);
void func_001684c0(void*, void*, s32, s32);
// 0013a600: moved to src/harata/libdk/field2dd.cpp

extern f32 D_0034a9e0;
extern f32 D_0034a9e4;
extern Vq D_0034a9c0;
extern Vq D_0034a9d0;
// 00158b20: moved to src/harata/libdk/bookcamera.cpp

// Pop a free 16-byte slot from the pool and initialise it.
struct Pool16 { u8 e[64][16]; s32 idx[64]; s32 n; };
extern u8* D_0034c7a0;
void func_001656d0(void*, u32, u32);
void* func_001659b8(u32 a, u32 b);  // 0x001659b8: definition moved into src/anon/unit_001656b8.cpp

extern u8 D_0034c7b0[];
void sceGsSetDefLoadImage(void*, s32, s32, s32, s32, s32, s32, s32);
void func_003058a0(s32);
void sceGsExecLoadImage(void*, u32);
void func_00166618(u32 a, s16 b, s16 c, s16 d, s16 e, s16 f, s32 i);  // 0x00166618: definition moved into src/anon/unit_001664c0.cpp

extern u32 D_0034f240;
void func_00192260(u32, s32);
void func_001b8318(void);
void func_001a3a50(void);
void func_001a64c0(void);
void func_001a5970(void);
void func_001bfbd8(void);
void func_00182ab0(void);
void func_001c8838(s32);
void func_001bae08(void);
void func_00169178(void);  // 0x00169178: definition moved into src/anon/unit_00168aa0.cpp

Vq* func_001dc648(u32);
Vq func_0017d050(u32);
// 0016e240: moved to src/anon/unit_0016d2e0.cpp

void func_0017c4c8(void*, Vq*);
void func_0017f488(void*, u32, f32, f32);
void func_00172158(u32* p);  // 0x00172158: definition moved into src/anon/unit_00171e58.cpp

// First non-zero result of func_0019b380 over the 12-byte table entries.
struct Ent12 { u32 a, b, c; };
extern s32 D_0034ed00;
extern Ent12 D_01c60588[];
u32 func_0019b380(u32, u32);
// 00182e98: moved to src/anon/unit_00182780.cpp

s32 func_0018b198(void*);
void func_001ad9c8(void*);  // float_accumulate_clamped
void func_0016aeb8(void*, f32);
void func_001b0728(void*, void*, s32, f32);
void func_0018b110(u8* p);  // 0x0018b110: definition moved into src/yasui/libys/npc.cpp

// Destructor: drop references, unlink, release.
extern u8 D_0034ef18[];
extern u8 D_01c60cd8[];
void func_0031ee68(void*, void*);
void func_0018e040(void*);
void func_001c0058(u32);  // clear_bit_in_array
void func_001c0248(void*);
void func_0018d590(u32* p);  // 0x0018d590: definition moved into src/anon/unit_0018d050.cpp

struct S16x2 { s16 a, b; };
struct Tbl7928 { u8 pad[7928]; S16x2 arr[1]; };
extern Tbl7928 D_0032bb30;
extern u8* D_01c61b08;
s32 func_00196388(u32, u32);
void func_001963f8(s32);
void func_001966b0(s32 i);  // 0x001966b0: definition moved into src/anon/unit_00195d00.cpp

// Remove one unit of item `a` (100 = special case).
void func_001a34e0(s32, s32);
u8* func_00188fe0(void*);
extern u8 D_0032e020[];
// 001a3458: moved to src/anon/unit_001a2a50.cpp

extern u32 D_00350748;
extern u32 D_01c6cafc;
extern u8 D_01c6cae0[];
extern u32 D_01c6cb00[4];
extern u32 D_01c6cb10;
u32 func_001708f8(u32, s32);
u8* func_00168b38(u32, s32, s32);  // entry_array_find_nth
void func_001dddd0(void*, u32);
// 001a3a88: moved to src/yasui/libys/effect.cpp

void func_00165768(u32);
void func_001b3018(u32* p);  // 0x001b3018: definition moved into src/anon/unit_001b2780.cpp

extern struct { u8 v; } D_01d48d94;
extern u8* D_01d48d90;
void func_001b89d0(void);
void func_001db610(void*, void (*)(void), s32);
void func_001b8988(u8* p, u8 v);  // 0x001b8988: definition moved into src/anon/unit_001b87a0.cpp

struct Ent4 { u16 id; u8 b; u8 pad; };
void func_001bc778(u32);
u8* func_001bc780(u32, u32, u32, s32);
void func_001bce90(u32 a, Ent4* e, u32 n, u32 c);  // 0x001bce90: definition moved into src/anon/unit_001bc568.cpp

// Find the 16-byte entry whose first byte is `key`.
extern u8* D_01d49358;
// 001c0648: moved to src/anon/unit_001c0638.cpp
u8* func_001c0648(u32 key);

extern u8 D_003525c8[];
extern u8 D_00352750[];
void func_00320400(void*);
void func_001d1678(void*, s32);  // obj_init_28bytes
void func_001d19e8(void*, s32);
void func_001d16e8(void*, s32, s32);
void func_001d4d28(u32* p);  // 0x001d4d28: definition moved into src/anon/unit_001d3c08.cpp

extern u8 D_00352878[];
void func_001b3b70(void*, void*, s32, u32);
s32 func_0019c8a8(void*);
struct Bits1536 { u32 lo:3; u32 v:4; u32 hi:25; };
void func_001d7cd0(u8* p, u8* q, u32 c);  // 0x001d7cd0: definition moved into src/anon/unit_001d7458.cpp

// Y-axis rotation matrix from the sine table (angle in 1/65536 turns).
extern f32 D_00359a20[];
void func_0021ea50(f32* m, u32 a);  // 0x0021ea50: definition moved into src/anon/unit_0021e988.cpp

// Store a copy of the 40-byte record in the first free (-1) slot.
struct Rec40 { s32 id; u8 b[36]; };
extern Rec40* D_0035dcfc;
void func_00227da8(Rec40* src);  // 0x00227da8: definition moved into src/anon/unit_00224780.cpp

void func_0023a0d8(void*);
void SEQ_GetActiveXY(u8* p, s32* x, s32* y);  // 0x0023a9c0: definition moved into src/anon/unit_00239988.cpp

u32 func_002efa40(u32);
extern volatile u32 D_0035ecb8;
s32 func_002421e8(u8* p);  // 0x002421e8: definition moved into src/anon/unit_00241fd0.cpp

void func_00258d40(u32, u32);
void func_00258d58(u32, u32, u32);
void func_00258d78(u32 a, u32 b, u32 c, u32 d);  // 0x00258d78: definition moved into src/anon/unit_002588e8.cpp

void func_00138c10(void*, s32);
// 0028da70: moved to src/anon/unit_0028c878.cpp

void func_00290488(VObj** p);  // 00290488: moved to src/anon/unit_0028f1e0.cpp

s32 func_00253b00(void);  // get_global_ptr_1dae6c0
s32 func_00253b18(void);
void func_00292a58(void);
extern s32 D_0035f4c8;
extern s32 D_0035f4cc;
extern s32 D_0035f4c0;
extern s32 D_0035f4bc;
extern s16 D_0035f4e0;
extern s16 D_0035f4d8;
extern u8 D_0035f4e2;
extern s32 D_0035f4d0;
void func_00292870(void);  // 00292870: moved to src/anon/unit_00292620.cpp

// Step the selection up/down (wrapping) among the entries flagged 0x2000000.
struct Ent36 { u32 f; u32 r[8]; };
extern u32* D_0035f630;
s32 func_00276608(s32);
void func_002765e8(s32, s32, s32);
void func_002b1208(u32 a);  // 0x002b1208: definition moved into src/anon/unit_002b0950.cpp

extern u32 D_003616f8[];
void func_002bc470(u32);
struct Ent12b { u32 a; s32 b; u32 c; };
void func_002bce50(u8* p);  // 0x002bce50: definition moved into src/anon/unit_002bc978.cpp

void func_002e7108(u32, f32);
Mq func_002e71a0(u32, u32, s32);
// 002e24e0: moved to src/anon/unit_002e1908.cpp

u32 func_001dc9e0(u32);
Vq* func_001dc5f8(u32);
// 002e9610: moved to src/sugi/flare.cpp

// 002ee730: moved to src/menu/tutorial_widget.cpp

extern u8 D_00347f98[];
extern u8 D_00347e60[];
extern u8 D_00347dd0[];
extern u8 D_00347e80[];
void func_00239700(void*);
void func_002361a0(void*);
void func_0031a350(u32* p) {
    p[0] = (u32)D_00347f98;
    func_0031a838(p + 3);
    p[0] = (u32)D_00347e60;
    func_00239700(p + 6);
    p[102] = 0;
    p[115] = 0;
    p[0] = (u32)D_00347dd0;
    p[112] = (u32)D_00347e80;
    func_002361a0(p + 120);
    p[224] = (u32)D_00347e60;
    p[227] = 0;
    func_00239700(p + 230);
}

u32 func_0016bc20(u32, s32, s32);
Vr func_0016bda8(u32);
struct Lookup32 { u32 a, b, c, d; Vr v; Lookup32() { d = 0; } };
void func_0018a818(Lookup32*, u32, u32);
Vr func_0016c2b0(u32 a);  // 0x0016c2b0: definition moved into src/anon/unit_00169f98.cpp

// Assertion "pMng"-style failure prints the message and file/line, then breaks.
extern char D_0036e978[];
extern char D_0036ef28[];
extern char D_0036e998[];
extern char D_0036e9d0[];
u32 func_002fdfc8(const char*, ...);  // device_vprintf_va
u32 func_001e3690(void*);
void func_001e8048(void*, u32, s32);
s32 func_001e6c40(u8* p, u32 a, u32 b, u32 c, f32 f);  // 0x001e6c40: definition moved into src/anon/unit_001e0cb8.cpp

// Cubic interpolation between key pairs a[i..i+1] / b[i..i+1] at fractional t (VU0).
extern Vq D_003590d0;
void func_00201b30(Vq* o, Vq* a, Vq* b, f32 t);  // 0x00201b30: definition moved into src/anon/unit_00200578.cpp

extern u8 D_00361e38[];
extern u8 D_0035eb98[];
extern union { u32* v; u8 c; } D_00361e28;
void func_002369a0(void*);  // obj_ctor_36eac8
void func_0023c008(void*);  // obj_ctor_36eae8
void func_0028d140(void*);
void func_00167f38(s32);
void func_002c5f48(void);
void func_002ca170(u32* p);  // 0x2ca170: moved to src/anon/unit_002ca0e0.cpp

}
