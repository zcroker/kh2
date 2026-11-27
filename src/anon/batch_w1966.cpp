#include "../common/types.h"

struct W1966Hdr {
    s16 f0, f2;
    s16 count;
    s16 start;
    s16 end;
    s16 fa;
};
struct W1966Cmd {
    u16 op;
    s16 size;
    s16 a4, a6, a8;
};
struct W1966CmdU {
    u16 op;
    u16 size;
    s16 a4, a6, a8;
};


#define W1966_QCOPY4(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
#define W1966_QCOPY1(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

struct W1966Mat {
    f32 m[4][4];
    W1966Mat& operator=(const W1966Mat& o) { if (this != &o) W1966_QCOPY4(this, &o); return *this; }
} __attribute__((aligned(16)));

struct W1966Vec {
    f32 v[4];
    W1966Vec& operator=(const W1966Vec& o) { if (this != &o) W1966_QCOPY1(this, &o); return *this; }
} __attribute__((aligned(16)));

struct W1966Pad {
    u8 b[16];
    W1966Pad& operator=(const W1966Pad&) { return *this; }
} __attribute__((aligned(16)));

struct W1966I3 { s32 a, b, c; };
struct W1966Pair { void* a; void* b; } __attribute__((aligned(8)));

struct W1966A {
    W1966Mat m0;
    f32 f40;
    s32 i44, i48;
    W1966I3 t4c;
    W1966Pair p58;
    void* p60;
    f32 f64, f68, f6c, f70, f74, f78;
    W1966Mat m80;
    W1966Mat mc0;
};

struct W1966B {
    W1966Pad e0;
    W1966Mat m10;
    W1966Vec v50, v60, v70;
    f32 f80;
};

extern W1966A D_003a7b70[2];
extern W1966B D_003a7f70[2];
extern W1966A D_003a81b0[2];
extern W1966B D_003a83b0[2];

extern "C" {
extern s32 D_0035daf0;
extern u32 D_0035dd04;
extern W1966Hdr* D_0035dd08[64];
extern s32 D_0035de20;
extern s32 D_0035de28;
extern u32 D_0035de60;
void func_00170888(s32);
void sa__EVENT__readNextMapFile(void);
void func_0022c508(void*);
void sa__EVENT__effect_read_set(void*, s32);
void func_0022f5a0(void*, s32, s32);
void sa__EVENT__audio_read_set(void*, s32);
void func_002331a0(void*, s32, s32, s32, s32);

void sa__EVENT__read_ctrl(void);  // 0x00226090: definition moved into src/anon/unit_00224780.cpp

// 001065d8: moved to src/naka/libkn/camera.cpp

// 001067b8: moved to src/naka/libkn/camera.cpp
}
