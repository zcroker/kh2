// Built with -fno-strict-aliasing (_nsa rule).
// 002c90c8: world-map course menu constructor. Partial inline asm, no code emitted:
// asm("" : : "r"(row)) keeps the 2-D row pointer live a little longer (register order of the
// d[3][3] init loop), and asm("" : "+r"(t)) stops gcse reusing the early t+648 for title.seq.
// No register pins, no hand-written instructions.
#include "../common/types.h"
// Local layout-file handle (ctor/dtor in the game).
extern "C" {
void LayFile2c90c8_ctor(void*) asm("_ZN2Tz7LayFileC1Ev");
void LayFile2c90c8_dtor(void*) asm("_ZN2Tz7LayFileD1Ev");
}
struct LayFile2c90c8 {
    u8 pad[32];
    LayFile2c90c8() { LayFile2c90c8_ctor(this); }
    ~LayFile2c90c8() { LayFile2c90c8_dtor(this); }
};
extern "C" {
// 2D-object widget, 408 bytes; member at +24 is its sequence.
struct W2c90c8 {
    u32 vt; u8 pad0[8]; s32 f12; u8 pad1[8]; u8 seq[368];
    s32 f392; W2c90c8* parent; s32 f400; u8 pad2[4];
};
struct WP2c90c8 { W2c90c8 w; s32 f408; s32 f412; s32 f416; u8 pad[12]; s32 f432; };
struct Rec2c90c8 { u8 pad[27]; u8 icon; u8 pad1[2]; u8 flag; u8 pad2; f32 f32_; };
struct M2c90c8 {
    u32 vt; u8 pad0[8]; s32 f12; u8 pad1[8]; s32 f24;
    u8 lay[160];
    WP2c90c8 head;
    W2c90c8 title;
    W2c90c8 a[3];
    W2c90c8 b[3];
    W2c90c8 c[3];
    W2c90c8 d[3][3];
    W2c90c8 e[3];
    s32 img;
    s32 cache;
    s32 course;
    s32 mode;
};
extern u8 D_00361e10[], D_00347f98[], D_0035eb98[], D_00347e60[], D_00347e40[];
extern M2c90c8* D_00361e00;
extern u8 D_0033bc10[];
extern s16 D_003757d8[], D_003757e8[], D_003757f0[];
void func_0031a838(void*);
void func_002369a0(void*);
void func_0023c008(void*);
void func_00239700(void*);
s32 func_002beb90(void);
s32 func_001708f8(s32, s32);
void func_0023fa08(LayFile2c90c8*, s32);
s32 func_0023f948(LayFile2c90c8*, s32);
s32 func_0023f908(LayFile2c90c8*, s32);
s32 func_002c9e90(M2c90c8*, s32);
void func_0023eea0(void*, s32, s32, s32, s32, s32);
void func_0023ef50(void*);
void func_0023f0c8(void*, s32);
void func_00139570(void*);
u8* func_0023f1b0(void*);
s32 func_0023c4b8(u8*, s32);
s32 func_00236ca8(s32, s32);
Rec2c90c8* func_001e09a0(u8*, s32, s32, s32);
s32 func_002c1c88(s32);
void func_00138d60(WP2c90c8*, s32, s32, s32, s32, s32, s32);
void func_00139620(WP2c90c8*);
void func_001386e0(W2c90c8*, s32, s32, s32, s32, s32);
void func_001396b0(W2c90c8*);
void func_0031a260(W2c90c8*, s32);
void func_00139660(W2c90c8*);
void func_00139688(W2c90c8*);
void func_00138c68(W2c90c8*, s32, s32);
s32 func_0023aa18(void*);
s32 func_0023aa58(void*);
s32 func_0023aa78(void*);
s32 func_0023aa98(void*);
s32 func_002c5238(s32, s32, s32*);
void func_001391c8(M2c90c8*, s32, s32);

static inline void Attach2c90c8(W2c90c8* w, W2c90c8* parent)
{
    w->parent = parent;
    func_001396b0(w);
    if (w->parent) {
        w->f400 = 0;
        func_001396b0(w);
        if (w->f400) func_0031a260(w, 0);
    }
}

void func_002c90c8(M2c90c8* t, s32 course);  // 0x2c90c8: moved to src/anon/unit_002c87f8.cpp

}
