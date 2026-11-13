#include "../common/types.h"

#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));

#define MCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct Mtx {
    QWord r[4];
    Mtx() {}
    Mtx(const Mtx& o) { MCOPY(this, &o); }
    Mtx& operator=(const Mtx& o) {
        if (this != &o) MCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));

struct Light {
    QWord dir;
    QWord neg;
    u8 rgb[4];
    u32 mask;
    u32 a, b, c;
    u8 d;
    Light() { mask = 0xffff; a = 0; b = 0; c = 0; d = 0; }
};

#define LIGHT_INIT(l) do { asm volatile("sqc2 $vf0, 0(%0)" : : "r"(&(l).dir) : "memory"); \
    asm volatile("lqc2 $vf4, 0(%1)\n\tvsub.xyz $vf5, $vf0, $vf4\n\tsqc2 $vf5, 0(%0)" : : "r"(&(l).neg), "r"(&(l).dir) : "memory"); } while (0)
struct Box { QWord a, b; };
struct Ent { u32 mask; u8 c[4]; };
struct Model;
struct ModelVt { void* f[16]; };
struct Model { ModelVt* vt; s32* p4; };

struct Obj;
struct ObjList { Obj* head; Obj* tail; };

struct Obj {
    void* vt;               // 0
    Model* model;           // 4
    u8 pad8[8];
    Mtx mtx;                // 16
    QWord pos;              // 80
    QWord rot;              // 96
    QWord scale;            // 112
    Obj* next;              // 128
    u8 pad132[12];
    u8 bound[128];          // 144
    u8 sub[112];            // 272
    u32 f384;               // 384
    Ent ent[4];             // 388
    u8 pad420[0];
    struct Col { u32 r:8; u32 g:8; u32 b:8; u32 a:8; } color; // 420
    u32 f424, f428, f432;   // 424
    u8 pad436[12];
    void* gfx;              // 448
    u8 pad452[4];
    u32 f456;               // 456
    u8 pad460[32];
    u32 f492;               // 492
    u8 pad496[4];
    Ent* ents;              // 500
    u8 pad504[8];
    Mtx mtx2;               // 512
    Mtx pad576;
    QWord pos2;             // 640
    u8 pad656[40];
    u32 flags;              // 696
    void* pbound;           // 700
    u8 pad704[20];
    u32 f724;               // 724
};

extern "C" {
extern u8 D_0034c750[];
extern void* D_0034c73c;
extern void* D_0034c738;
extern ObjList D_004f3b38;
void func_001614e8(void*, Obj*);
void func_0031e158(void*);
Model* func_00149308(void*, u32);
u32 func_00149320(void*, u32);
void* func_00149338(void*, u32);
void func_0011e260(void*, u32);
void func_001604f8(Obj*);
void func_001444c8(Box*, QWord*, QWord*);
void func_00144be0(Box*, void*);
void func_001605a0(Obj*, Mtx);
void func_00143348(void*);
void func_0011eb08(void*, s32);
void func_0011e880(void*, s32, s32, s32);
void func_001608c0(Obj*);
void func_00143520(QWord*, Light*);
void func_00160488(Obj*, s32, s32, s32);
void func_00161540(void*, void*);
void func_001615e8(void*, s32, f32);
void func_00160ac0(Obj*, u32);

static inline void SetColor(Obj::Col& c, u32 r, u32 g, u32 b, u32 a) { c.r = r; c.g = g; c.b = b; c.a = a; }

// Model-object constructor (vtable D_0034c750): copies pos/rot/scale, binds the model of `kind`, sets up
// bounds, colour, optional light and effect, then appends the object to the list at D_004f3b38.
// Twin of func_0015fe18 (same body).
// 0015f9c8: moved to src/harata/libdk/bgobj.cpp
}
