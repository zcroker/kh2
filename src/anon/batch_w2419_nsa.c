#include "../common/types.h"

/* 002065b0: partMng-style render list (twin of 00206be8 in batch_w1674_nsa.cpp), plain C. */
typedef f32 FMTX65b[4][4] __attribute__((aligned(16)));
typedef struct Work65b Work65b;
struct Work65b { u8 pad0[0x10]; FMTX65b world; FMTX65b view; };
typedef struct State65b State65b;
struct State65b { u8 pad0[0xa8]; u64 flags; };
typedef struct Frame65b Frame65b;
struct Frame65b { s16 dataOfs; s16 duration; s8 flags; u8 pad5[3]; };
typedef struct Anim65b Anim65b;
struct Anim65b { u8 pad0[6]; s16 count; u8 pad8[8]; Frame65b frames[1]; };
typedef struct AnimRef65b AnimRef65b;
struct AnimRef65b { Anim65b* anim; s32 x4; };
typedef struct Bank65b Bank65b;
struct Bank65b { u8 pad0[0x14]; AnimRef65b* anims; };
typedef struct DrawParam65b DrawParam65b;
struct DrawParam65b {
    u16 x00;
    u16 flags;          // 0x02
    u8 rgba[4];         // 0x04
    u32 x08[2];            // 0x08
    f32 (*viewMtx)[4];  // 0x10
    u8* packet;         // 0x14
    s8 x18;             // 0x18
    u8 pad19[3];
    f32 (*localMtx)[4]; // 0x1c
    u8 pad20[0x10];
};
typedef struct Elem65b Elem65b;
struct Elem65b {
    u8 pad0[8];
    s32 anim;       // 0x08
    u16 speed;      // 0x0c
    u8 pad0e[2];
    u8 x10;         // 0x10
    u8 x11;         // 0x11
    u8 pad12;
    u8 hasOffset;   // 0x13
    f32 offset[3];  // 0x14
    u8 pad20[0xc];
    f32 scale[3];   // 0x2c
    u8 rgba[4];     // 0x38
    u8 x3c;         // 0x3c
};
typedef struct Slot65b Slot65b;
struct Slot65b {
    f32 pos[4];
    Elem65b* elem;     // 0x10
    u8 pad14[4];
    u16 time;           // 0x18
    u16 frame;          // 0x1a
    u8 timerA;          // 0x1c
    u8 timerB;          // 0x1d
    u16 decay;          // 0x1e
};
typedef struct List65b List65b;
struct List65b { u32 count; u8 pad4[8]; Slot65b* slots; };
extern Work65b* D_01d9e6e8;
extern Bank65b* D_01d9e6e4;
extern State65b* D_01d9e6e0;
extern s32 D_01d9ea9c;
extern u8* D_01d9eaa4;
extern FMTX65b D_01d9e730;
extern FMTX65b D_01d9e8c0;
void sceVu0ApplyMatrix(f32* out, f32 (*m)[4], f32* in);
void sceVu0MulMatrix(f32 (*out)[4], f32 (*a)[4], f32 (*b)[4]);
void sceVu0CopyVector(f32* out, f32* in);
void sceVu0CopyMatrix(f32 (*out)[4], f32 (*in)[4]);
void sceVu0UnitMatrix(f32 (*m)[4]);
u8* func_0021d048(u8* data, DrawParam65b* p, s32 x);
void draw_shape(List65b* list);  // 0x002065b0: definition moved into src/anon/unit_00206388.c

/* 002068d0: model render list, plain C. */
typedef f32 FMTX206[4][4] __attribute__((aligned(16)));
typedef struct Work206 Work206; struct Work206 { u8 pad0[0x10]; FMTX206 world; FMTX206 view; s32 x90; s32 x94; };
typedef struct DrawParam206 DrawParam206; struct DrawParam206 {
    s32 flags;          // 0x00
    void* tex;          // 0x04
    u16 x08;            // 0x08
    s8 x0a;             // 0x0a
    u8 pad0b;
    s32 x0c;            // 0x0c
    s64 x10;            // 0x10
    u8 rgba[4];         // 0x18
    s32 x1c;            // 0x1c
    f32 (*viewMtx)[4];  // 0x20
    s32 x24;            // 0x24
    s32 x28;            // 0x28
    s32 x2c;            // 0x2c
    u8 pad30[4];
    u8* packet;         // 0x34
    s32 x38;            // 0x38
    s32 x3c;            // 0x3c
    s32 x40;            // 0x40
    f32 (*localMtx)[4]; // 0x44
    u8 pad48[4];
    u8 x4c;             // 0x4c
    u8 x4d;             // 0x4d
    u8 pad4e[2];
    u8 pad50[16];
};
typedef struct Model206 Model206; struct Model206 { s32 flags; u8 pad4[0x12]; u16 x16; };
typedef struct ModelEnt206 ModelEnt206; struct ModelEnt206 { u8 pad0[0x1c]; Model206* model; s32 x20; };
typedef struct ModelTab206 ModelTab206; struct ModelTab206 { u8 pad0[0x10]; ModelEnt206* ents; };
typedef struct Elem206 Elem206; struct Elem206 {
    u8 pad0[8];
    s32 model;      // 0x08
    u8 flags;       // 0x0c
    u8 x0d;         // 0x0d
    u8 pad0e;
    u8 x0f;         // 0x0f
    u8 x10;         // 0x10
    u8 hasOffset;   // 0x11
    u8 pad12[2];
    f32 offset[3];  // 0x14
    u8 pad20[0xc];
    f32 rot[3];     // 0x2c
    f32 scale[3];   // 0x38
    u8 rgba[4];     // 0x44
    u8 x48;         // 0x48
};
typedef struct Slot206 Slot206; struct Slot206 { f32 pos[4]; Elem206* elem; u8 pad14[0xc]; };
typedef struct List206 List206; struct List206 { u32 pad0; u32 count; u8 pad8[8]; Slot206* slots; };
static inline void scaleRow206(f32* row, f32 s) {
    asm volatile("qmtc2 %1, $vf9\n\tlqc2 $vf10, 0(%0)\n\tvmulx.xyz $vf10, $vf10, $vf9x\n\tsqc2 $vf10, 0(%0)" : : "r"(row), "r"(s) : "memory");
}
extern Work206* D_e6e8_206 asm("D_01d9e6e8");
extern ModelTab206* D_e6e4_206 asm("D_01d9e6e4");
extern u8* D_01d9eaa4;
extern u8 D_01d9eac0[];
extern FMTX206 D_01d9e730;
extern FMTX206 D_01d9e8c0;
extern FMTX206 D_01d9ea00;
void func_001e8fe0(f32 (*m)[4], f32* rot);
void sceVu0MulMatrix(f32 (*out)[4], f32 (*a)[4], f32 (*b)[4]); // sceVu0MulMatrix
void sceVu0CopyVector(f32* out, f32* in);                  // sceVu0CopyVector
u8* func_0020f1e0(Model206* m, DrawParam206* p, s32 x);

void draw_model(List206* list);  // 0x002068d0: definition moved into src/anon/unit_00206388.c
