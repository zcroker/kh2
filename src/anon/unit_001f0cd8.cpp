// Linked unit 0x001f0a38-0x001f1978 (model render request, ppp matrix and spline programs; one namespace per old matched source, gap functions written for the unit).
#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));

// 001f0a38 (was whole asm, src/anon/batch_w3899.s): model render request (twin of 0x1f0600 with an optional
// w68 pointer). w12/w28 go through casts; the rest in plain field order.
namespace n001f0a38 {
typedef struct { f32 m[4][4]; } __attribute__((aligned(16))) M1f0a38;
typedef struct {
    u32 flags;
    void* p4;
    u16 tex;
    u8 b10;
    u8 pad11;
    s32 w12;
    s32 y;
    s32 x;
    u8 rgba[4];
    s32 w28;
    void* p32;
    void* p36;
    void* p40;
    void* p44;
    M1f0a38* mtx;
    s32 p52;
    s32 p56;
    s32 p60;
    s32 w64;
    s32 w68;
    u8 pad72[4];
    u8 b76;
    u8 b77;
    u8 pad78[18];
} Req1f0a38;
typedef struct { u32 flags; u8 pad[18]; u16 tex; } Mdl1f0a38;
typedef struct { u8 pad0[4]; s32 set; u8 pad1[24]; union { u16 tex; u8 texlo; } t; u8 mode; u8 b35; u8 b36; u8 b37; u8 b38; } Ent1f0a38;
typedef struct { u8 pad0[12]; s32* off; } Ctx1f0a38;
typedef struct { u8 pad0[28]; Mdl1f0a38* m; s32 p32; } Set1f0a38;
typedef struct { u8 pad0[16]; Set1f0a38* sets; } Res1f0a38;
typedef struct { u8 pad0[16]; M1f0a38 m16; u8 pad1[80 - 80]; u8 m80[64]; s32 p144; s32 p148; } Ovr1f0a38;
extern Res1f0a38* D_01d9e6e4 asm("D_01d9e6e4");
extern Ovr1f0a38* D_01d9e6e8 asm("D_01d9e6e8");
extern M1f0a38 D_01d9e840 asm("D_01d9e840");
extern u8 D_01d9eac0[] asm("D_01d9eac0");
extern u8 D_01d9e9c0[] asm("D_01d9e9c0");
extern u8 D_01d9e980[] asm("D_01d9e980");
extern s32 D_01d9eaa4 asm("D_01d9eaa4");
void sceVu0MulMatrix(M1f0a38*, M1f0a38*, M1f0a38*) asm("sceVu0MulMatrix");
s32 func_0020f1e0(Mdl1f0a38*, Req1f0a38*, s32) asm("func_0020f1e0");
//@a
void func_001f0a38(u8* base, Ent1f0a38* e, Ctx1f0a38* c) asm("func_001f0a38");
void func_001f0a38(u8* base, Ent1f0a38* e, Ctx1f0a38* c)
{
    f32* pos = (f32*)(base + c->off[2] + 160);
    Mdl1f0a38* m;
    u8* col;
    Req1f0a38 r;
    M1f0a38 tmp;
    if (e->set == 0xffff) return;
    m = D_01d9e6e4->sets[e->set].m;
    col = base + c->off[0] + 160;
    r.rgba[0] = col[8];
    r.rgba[1] = col[9];
    r.rgba[3] = col[11];
    r.rgba[2] = col[10];
    if (col[11] == 0) return;
    r.flags = 0;
    if (e->mode & 2) r.flags = 4;
    else if (e->mode & 1) r.flags = 128;
    if ((m->flags & 1) == 0) r.flags |= 8;
    if (!(m->flags & 2)) r.flags |= 16;
    if (e->b35) r.flags |= 0x200;
    if (e->b36) r.flags |= 0x100;
    if (e->b37) {
        r.flags = (r.flags & ~16) | 0x2000;
        r.mtx = &tmp;
        sceVu0MulMatrix(&tmp, &D_01d9e840, &D_01d9e6e8->m16);
    } else {
        r.mtx = 0;
    }
    r.p4 = D_01d9eac0;
    if (e->t.texlo == 255) r.tex = m->tex;
    else r.tex = e->t.tex;
    r.b10 = 0;
    *(s32*)((u8*)&r + 12) = 0;
    r.y = (s32)(pos[1] * 65536.0f);
    r.x = (s32)(pos[4] * 65536.0f);
    if (e->b38) r.w68 = (s32)(base + c->off[3] + 160);
    else r.w68 = 0;
    *(s32*)((u8*)&r + 28) = 0;
    Ovr1f0a38* ov = D_01d9e6e8;
    r.p32 = ov->m80;
    r.p36 = D_01d9e9c0;
    r.p40 = D_01d9e980;
    r.p44 = &ov->m16;
    r.p52 = D_01d9eaa4;
    r.p56 = ov->p144;
    r.p60 = ov->p148;
    r.w64 = 0;
    r.b76 = 0;
    r.b77 = 0;
    D_01d9eaa4 = func_0020f1e0(m, &r, D_01d9e6e4->sets[e->set].p32);
}
}  // namespace n001f0a38

// 001f0cd8 (gap, written for the unit: byte-identical twin of 0x1ea970)
namespace n001f0cd8 {
union PtrF247 { u8* p; f32 f; };
extern PtrF247 D_01d9e6e8 asm("D_01d9e6e8");
void func_001e8fe0(u8*, u8*) asm("func_001e8fe0");
// VU0 macro: scale row xyz by k.
static inline void ScaleRow247(u8* row, f32 k)
{
    asm volatile(
        "qmtc2 %1, $vf9\n\t"
        "lqc2 $vf10, 0(%0)\n\t"
        "vmulx.xyz $vf10, $vf10, $vf9x\n\t"
        "sqc2 $vf10, 0(%0)"
        : : "r"(row), "r"(k) : "memory");
}
/*TARGET 001f0cd8*/
void func_001f0cd8(u8* base, u32 unused, u8* desc) asm("func_001f0cd8");
void func_001f0cd8(u8* base, u32 unused, u8* desc)
{
    u32* d = *(u32**)(desc + 12);
    u8* p0 = base + d[0];
    u8* p1 = base + d[1];
    u8* p2 = base + d[2];
    f32* t = (f32*)(p0 + 160);
    f32* s = (f32*)(p2 + 160);
    func_001e8fe0(D_01d9e6e8.p + 16, p1 + 160);
    ScaleRow247(D_01d9e6e8.p + 16, s[0]);
    ScaleRow247(D_01d9e6e8.p + 32, s[1]);
    ScaleRow247(D_01d9e6e8.p + 48, s[2]);
    *(f32*)(D_01d9e6e8.p + 64) = t[0];
    *(f32*)(D_01d9e6e8.p + 68) = t[1];
    *(f32*)(D_01d9e6e8.p + 72) = t[2];
}
}  // namespace n001f0cd8

// 001f0dc0 (was src/anon/batch_w248.cpp)
namespace n001f0dc0 {
union W248Cam { u8* p; f32 f; };
extern W248Cam D_01d9e6e8 asm("D_01d9e6e8");
void func_0021eb50(void*, void*) asm("func_0021eb50");
static inline void W248Scale(void* row, f32 s) {
    asm volatile("qmtc2 %1, $vf9\n\tlqc2 $vf10, 0(%0)\n\tvmulx.xyz $vf10, $vf10, $vf9x\n\tsqc2 $vf10, 0(%0)" : : "r"(row), "r"(s) : "memory");
}
/*TARGET 001f0dc0*/
// 0x001eab40: definition moved into src/anon/unit_001e8ac8.cpp
void func_001f0dc0(u8* o, u32 a1, u8* x) asm("func_001f0dc0");
// 0x001eab40: definition moved into src/anon/unit_001e8ac8.cpp
void func_001f0dc0(u8* o, u32 a1, u8* x) {
    s32* off = *(s32**)(x + 12);
    f32* pos = (f32*)(o + off[0] + 160);
    f32* rot = (f32*)(o + off[1] + 160);
    f32* scl = (f32*)(o + off[2] + 160);
    func_0021eb50(D_01d9e6e8.p + 16, rot);
    W248Scale(D_01d9e6e8.p + 16, scl[0]);
    W248Scale(D_01d9e6e8.p + 32, scl[1]);
    W248Scale(D_01d9e6e8.p + 48, scl[2]);
    *(f32*)(D_01d9e6e8.p + 64) = pos[0];
    *(f32*)(D_01d9e6e8.p + 68) = pos[1];
    *(f32*)(D_01d9e6e8.p + 72) = pos[2];
}
}  // namespace n001f0dc0

// 001f0ea8 (was src/anon/batch_w248.cpp)
namespace n001f0ea8 {
union W248Cam { u8* p; f32 f; };
extern W248Cam D_01d9e6e8 asm("D_01d9e6e8");
void func_0021ec80(void*, void*) asm("func_0021ec80");
static inline void W248Scale(void* row, f32 s) {
    asm volatile("qmtc2 %1, $vf9\n\tlqc2 $vf10, 0(%0)\n\tvmulx.xyz $vf10, $vf10, $vf9x\n\tsqc2 $vf10, 0(%0)" : : "r"(row), "r"(s) : "memory");
}
/*TARGET 001f0ea8*/
void func_001f0ea8(u8* o, u32 a1, u8* x) asm("func_001f0ea8");
void func_001f0ea8(u8* o, u32 a1, u8* x) {
    s32* off = *(s32**)(x + 12);
    f32* pos = (f32*)(o + off[0] + 160);
    f32* rot = (f32*)(o + off[1] + 160);
    f32* scl = (f32*)(o + off[2] + 160);
    func_0021ec80(D_01d9e6e8.p + 16, rot);
    W248Scale(D_01d9e6e8.p + 16, scl[0]);
    W248Scale(D_01d9e6e8.p + 32, scl[1]);
    W248Scale(D_01d9e6e8.p + 48, scl[2]);
    *(f32*)(D_01d9e6e8.p + 64) = pos[0];
    *(f32*)(D_01d9e6e8.p + 68) = pos[1];
    *(f32*)(D_01d9e6e8.p + 72) = pos[2];
}
}  // namespace n001f0ea8

// 001f0f90 (was src/anon/batch_w247.cpp)
namespace n001f0f90 {
union PtrF247 { u8* p; f32 f; };
extern PtrF247 D_01d9e6e8 asm("D_01d9e6e8");
void func_0021ebe8(u8*, u8*) asm("func_0021ebe8");
// VU0 macro: scale row xyz by k.
static inline void ScaleRow247(u8* row, f32 k)
{
    asm volatile(
        "qmtc2 %1, $vf9\n\t"
        "lqc2 $vf10, 0(%0)\n\t"
        "vmulx.xyz $vf10, $vf10, $vf9x\n\t"
        "sqc2 $vf10, 0(%0)"
        : : "r"(row), "r"(k) : "memory");
}
/*TARGET 001f0f90*/
void func_001f0f90(u8* base, u32 unused, u8* desc) asm("func_001f0f90");
void func_001f0f90(u8* base, u32 unused, u8* desc)
{
    u32* d = *(u32**)(desc + 12);
    u8* p0 = base + d[0];
    u8* p1 = base + d[1];
    u8* p2 = base + d[2];
    f32* t = (f32*)(p0 + 160);
    f32* s = (f32*)(p2 + 160);
    func_0021ebe8(D_01d9e6e8.p + 16, p1 + 160);
    ScaleRow247(D_01d9e6e8.p + 16, s[0]);
    ScaleRow247(D_01d9e6e8.p + 32, s[1]);
    ScaleRow247(D_01d9e6e8.p + 48, s[2]);
    *(f32*)(D_01d9e6e8.p + 64) = t[0];
    *(f32*)(D_01d9e6e8.p + 68) = t[1];
    *(f32*)(D_01d9e6e8.p + 72) = t[2];
}
}  // namespace n001f0f90

// 001f1078 (was src/anon/batch_w247.cpp)
namespace n001f1078 {
union PtrF247 { u8* p; f32 f; };
extern PtrF247 D_01d9e6e8 asm("D_01d9e6e8");
void func_0021ed18(u8*, u8*) asm("func_0021ed18");
// VU0 macro: scale row xyz by k.
static inline void ScaleRow247(u8* row, f32 k)
{
    asm volatile(
        "qmtc2 %1, $vf9\n\t"
        "lqc2 $vf10, 0(%0)\n\t"
        "vmulx.xyz $vf10, $vf10, $vf9x\n\t"
        "sqc2 $vf10, 0(%0)"
        : : "r"(row), "r"(k) : "memory");
}
/*TARGET 001f1078*/
void func_001f1078(u8* base, u32 unused, u8* desc) asm("func_001f1078");
void func_001f1078(u8* base, u32 unused, u8* desc)
{
    u32* d = *(u32**)(desc + 12);
    u8* p0 = base + d[0];
    u8* p1 = base + d[1];
    u8* p2 = base + d[2];
    f32* t = (f32*)(p0 + 160);
    f32* s = (f32*)(p2 + 160);
    func_0021ed18(D_01d9e6e8.p + 16, p1 + 160);
    ScaleRow247(D_01d9e6e8.p + 16, s[0]);
    ScaleRow247(D_01d9e6e8.p + 32, s[1]);
    ScaleRow247(D_01d9e6e8.p + 48, s[2]);
    *(f32*)(D_01d9e6e8.p + 64) = t[0];
    *(f32*)(D_01d9e6e8.p + 68) = t[1];
    *(f32*)(D_01d9e6e8.p + 72) = t[2];
}
}  // namespace n001f1078

// 001f1160 (was src/anon/batch_w247.cpp)
namespace n001f1160 {
union PtrF247 { u8* p; f32 f; };
extern PtrF247 D_01d9e6e8 asm("D_01d9e6e8");
void func_0021edb0(u8*, u8*) asm("func_0021edb0");
// VU0 macro: scale row xyz by k.
static inline void ScaleRow247(u8* row, f32 k)
{
    asm volatile(
        "qmtc2 %1, $vf9\n\t"
        "lqc2 $vf10, 0(%0)\n\t"
        "vmulx.xyz $vf10, $vf10, $vf9x\n\t"
        "sqc2 $vf10, 0(%0)"
        : : "r"(row), "r"(k) : "memory");
}
/*TARGET 001f1160*/
void func_001f1160(u8* base, u32 unused, u8* desc) asm("func_001f1160");
void func_001f1160(u8* base, u32 unused, u8* desc)
{
    u32* d = *(u32**)(desc + 12);
    u8* p0 = base + d[0];
    u8* p1 = base + d[1];
    u8* p2 = base + d[2];
    f32* t = (f32*)(p0 + 160);
    f32* s = (f32*)(p2 + 160);
    func_0021edb0(D_01d9e6e8.p + 16, p1 + 160);
    ScaleRow247(D_01d9e6e8.p + 16, s[0]);
    ScaleRow247(D_01d9e6e8.p + 32, s[1]);
    ScaleRow247(D_01d9e6e8.p + 48, s[2]);
    *(f32*)(D_01d9e6e8.p + 64) = t[0];
    *(f32*)(D_01d9e6e8.p + 68) = t[1];
    *(f32*)(D_01d9e6e8.p + 72) = t[2];
}
}  // namespace n001f1160

// 001f1248 (was src/anon/spline_vu0_owner1025.c)
namespace n001f1248 {
#define SPLINE_SOLVE(in, n, out, tab, work) \
    asm volatile( \
        ".set noreorder\n\t" \
        "addi $9,%1,-1\n\t" \
        "addi $10,%1,-2\n\t" \
        "lqc2 $vf1,0(%3)\n\t" \
        "sqc2 $vf0,0(%2)\n\t" \
        "sll $11,$9,0x4\n\t" \
        "add $11,$11,%2\n\t" \
        "sqc2 $vf0,0($11)\n\t" \
        "move $8,$9\n\t" \
        "move $11,$0\n\t" \
        ".Lspl%=_delta_loop:\n\t" \
        "blez $8,.Lspl%=_delta_done\n\t" \
        "addi $8,$8,-1\n\t" \
        "sll $12,$11,0x4\n\t" \
        "addi $13,$12,16\n\t" \
        "add $14,$12,%0\n\t" \
        "add $15,$13,%0\n\t" \
        "add $16,$13,%4\n\t" \
        "lqc2 $vf10,0($14)\n\t" \
        "lqc2 $vf11,0($15)\n\t" \
        "vsub.xyzw $vf10,$vf11,$vf10\n\t" \
        "sqc2 $vf10,0($16)\n\t" \
        "b .Lspl%=_delta_loop\n\t" \
        "addi $11,$11,1\n\t" \
        ".Lspl%=_delta_done:\n\t" \
        "lqc2 $vf10,32(%4)\n\t" \
        "lqc2 $vf11,16(%4)\n\t" \
        "lqc2 $vf12,0(%2)\n\t" \
        "vsub.xyzw $vf10,$vf10,$vf11\n\t" \
        "vsub.xyzw $vf10,$vf10,$vf12\n\t" \
        "sqc2 $vf10,16(%2)\n\t" \
        "vaddx.xyzw $vf11,$vf0,$vf1x\n\t" \
        "sqc2 $vf11,16(%4)\n\t" \
        "move $8,$10\n\t" \
        "addi $8,$8,-1\n\t" \
        "addi $11,$0,1\n\t" \
        ".Lspl%=_fwd_loop:\n\t" \
        "blez $8,.Lspl%=_fwd_done\n\t" \
        "addi $8,$8,-1\n\t" \
        "sll $12,$11,0x4\n\t" \
        "addi $13,$12,16\n\t" \
        "addi $14,$13,16\n\t" \
        "add $15,$12,%4\n\t" \
        "add $16,$13,%4\n\t" \
        "add $17,$14,%4\n\t" \
        "add $18,$13,%2\n\t" \
        "add $19,$12,%2\n\t" \
        "lqc2 $vf10,0($15)\n\t" \
        "lqc2 $vf11,0($16)\n\t" \
        "lqc2 $vf12,0($17)\n\t" \
        "lqc2 $vf13,0($19)\n\t" \
        "vdiv Q,$vf0w,$vf10x\n\t" \
        "vwaitq\n\t" \
        "vaddq.x $vf15,$vf0,Q\n\t" \
        "vdiv Q,$vf0w,$vf10y\n\t" \
        "vwaitq\n\t" \
        "vaddq.y $vf15,$vf0,Q\n\t" \
        "vdiv Q,$vf0w,$vf10z\n\t" \
        "vwaitq\n\t" \
        "vaddq.z $vf15,$vf0,Q\n\t" \
        "vsub.xyzw $vf16,$vf12,$vf11\n\t" \
        "vmul.xyzw $vf17,$vf13,$vf15\n\t" \
        "vsub.xyzw $vf17,$vf16,$vf17\n\t" \
        "sqc2 $vf17,0($18)\n\t" \
        "vmuly.xyzw $vf18,$vf15,$vf1y\n\t" \
        "vaddx.xyzw $vf18,$vf18,$vf1x\n\t" \
        "sqc2 $vf18,0($16)\n\t" \
        "b .Lspl%=_fwd_loop\n\t" \
        "addi $11,$11,1\n\t" \
        ".Lspl%=_fwd_done:\n\t" \
        "sll $11,$9,0x4\n\t" \
        "add $11,$11,%2\n\t" \
        "sll $12,$10,0x4\n\t" \
        "add $12,$12,%2\n\t" \
        "lqc2 $vf10,0($11)\n\t" \
        "lqc2 $vf11,0($12)\n\t" \
        "vsub.xyzw $vf11,$vf11,$vf10\n\t" \
        "sqc2 $vf11,0($12)\n\t" \
        "move $11,$10\n\t" \
        ".Lspl%=_back_loop:\n\t" \
        "blezl $11,.Lspl%=_done\n\t" \
        "nop\n\t" \
        "sll $12,$11,0x4\n\t" \
        "addi $13,$12,16\n\t" \
        "add $15,$12,%4\n\t" \
        "add $16,$12,%2\n\t" \
        "add $17,$13,%2\n\t" \
        "lqc2 $vf10,0($15)\n\t" \
        "lqc2 $vf11,0($16)\n\t" \
        "lqc2 $vf12,0($17)\n\t" \
        "vsub.xyzw $vf11,$vf11,$vf12\n\t" \
        "vdiv Q,$vf11x,$vf10x\n\t" \
        "vwaitq\n\t" \
        "vaddq.x $vf15,$vf0,Q\n\t" \
        "vdiv Q,$vf11y,$vf10y\n\t" \
        "vwaitq\n\t" \
        "vaddq.y $vf15,$vf0,Q\n\t" \
        "vdiv Q,$vf11z,$vf10z\n\t" \
        "vwaitq\n\t" \
        "vaddq.z $vf15,$vf0,Q\n\t" \
        "sqc2 $vf15,0($16)\n\t" \
        "b .Lspl%=_back_loop\n\t" \
        "addi $11,$11,-1\n\t" \
        ".Lspl%=_done:\n\t" \
        ".set reorder" \
        : : "r"(in), "r"(n), "r"(out), "r"(tab), "r"(work) \
        : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "$16", "$17", "$18", "$19", "memory")
extern u8 D_00359090[] asm("D_00359090");
/*TARGET 001f1248*/
void func_001f1248(void* in, s32 n, void* out) asm("func_001f1248");
void func_001f1248(void* in, s32 n, void* out)
{
    SPLINE_SOLVE(in, n, out, D_00359090, (u128*)0x70002000);
}
}  // namespace n001f1248

// 001f1408 (was src/anon/batch_w1672.cpp)
namespace n001f1408 {
// 00161410: moved to src/anon/unit_001611a8.cpp (gcc makes the static init)

/* hand-written VU0 spline interpolation */
extern f32 D_003590a0[4] asm("D_003590a0");
/*TARGET 001f1408*/
void func_001f1408(f32* out, u8* a, u8* b, f32 t) asm("func_001f1408");
void func_001f1408(f32* out, u8* a, u8* b, f32 t) {
    s32 i = (s32)t;
    f32 f = t - (f32)i;
    a += i * 16;
    b += i * 16;
    D_003590a0[2] = f;
    asm volatile(
        ".set noreorder\n"
        "lqc2 $vf1,0(%1)\n"
        "lqc2 $vf2,16(%1)\n"
        "lqc2 $vf3,0(%2)\n"
        "lqc2 $vf4,16(%2)\n"
        "lqc2 $vf5,0(%3)\n"
        "vsub.xyzw $vf10,$vf4,$vf3\n"
        "vmuly.xyzw $vf11,$vf3,$vf5y\n"
        "vmulx.xyzw $vf12,$vf3,$vf5x\n"
        "vsub.xyzw $vf13,$vf2,$vf1\n"
        "vmulz.xyzw $vf10,$vf10,$vf5z\n"
        "vadd.xyzw $vf11,$vf11,$vf4\n"
        "vadd.xyzw $vf10,$vf10,$vf12\n"
        "vsub.xyzw $vf13,$vf13,$vf11\n"
        "vmulz.xyzw $vf10,$vf10,$vf5z\n"
        "vadd.xyzw $vf10,$vf10,$vf13\n"
        "vmulz.xyzw $vf10,$vf10,$vf5z\n"
        "vadd.xyzw $vf10,$vf10,$vf1\n"
        "sqc2 $vf10,0(%0)\n"
        ".set reorder\n"
        : : "r"(out), "r"(a), "r"(b), "r"(D_003590a0) : "memory");
}
}  // namespace n001f1408

// 001f1488 (was src/anon/batch_wcx2_g.c)
namespace n001f1488 {
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V1f1488;
typedef struct { V1f1488 r[4]; } M1f1488;
typedef struct { u8 pad0[17]; u8 mode; } Ob1f1488;
typedef struct { u8 pad0[64]; M1f1488 m; } Cam1f1488;
extern M1f1488 D_01d9e6f0 asm("D_01d9e6f0");
extern M1f1488 D_01d9e7b0 asm("D_01d9e7b0");
extern Cam1f1488* D_00354688 asm("D_00354688");
/* libvu0 sceVu0ApplyMatrix (VU0 macro code) */
static inline void apply1f1488(V1f1488* d, M1f1488* m, V1f1488* v)
{
    asm volatile(".set noreorder\n\tlqc2 $vf27, 0(%2)\n\tlqc2 $vf28, 0(%1)\n\tlqc2 $vf29, 16(%1)\n\tlqc2 $vf30, 32(%1)\n\tlqc2 $vf31, 48(%1)\n\t"
                 "vmulax.wxyz ACC, $vf28, $vf27x\n\tvmadday.wxyz ACC, $vf29, $vf27y\n\tvmaddaz.wxyz ACC, $vf30, $vf27z\n\tvmaddw.wxyz $vf26, $vf31, $vf0w\n\tsqc2 $vf26, 0(%0)\n\t.set reorder"
                 : : "r"(d), "r"(m), "r"(v) : "memory");
}
/*TARGET 001f1488*/
void func_001f1488(Ob1f1488* o, u8* mdl, V1f1488* a, V1f1488* b, f32 h) asm("func_001f1488");
void func_001f1488(Ob1f1488* o, u8* mdl, V1f1488* a, V1f1488* b, f32 h)
{
    V1f1488 v;
    v.x = 0.0f;
    v.z = 0.0f;
    v.w = 1.0f;
    v.y = h * 0.5f;
    apply1f1488(a, (M1f1488*)(mdl + 48), &v);
    v.y = -h * 0.5f;
    apply1f1488(b, (M1f1488*)(mdl + 48), &v);
    switch (o->mode) {
    case 0:
        break;
    case 1:
        apply1f1488(a, &D_01d9e6f0, a);
        apply1f1488(b, &D_01d9e6f0, b);
        break;
    case 2:
        if (D_00354688) {
            apply1f1488(a, &D_01d9e6f0, a);
            apply1f1488(a, &D_00354688->m, a);
            apply1f1488(b, &D_01d9e6f0, b);
            apply1f1488(b, &D_00354688->m, b);
        }
        break;
    case 3:
        apply1f1488(a, &D_01d9e6f0, a);
        apply1f1488(a, &D_01d9e7b0, a);
        apply1f1488(b, &D_01d9e6f0, b);
        apply1f1488(b, &D_01d9e7b0, b);
        break;
    }
}
}  // namespace n001f1488

// 001f1728 (was src/anon/batch_w2387_nsa.c)
namespace n001f1728 {
typedef unsigned int u128_1f1728 __attribute__((mode(TI)));
struct A1f1728 { u8 pad[0x11]; u8 mode; };
struct B1f1728 { u8 pad[0x60]; u128_1f1728 v; };
extern u8 D_01d9e6f0[] asm("D_01d9e6f0");
extern u8 D_01d9e7b0[] asm("D_01d9e7b0");
extern u8* D_00354688 asm("D_00354688");
#define MULMAT(v, m) asm volatile( \
        ".set noreorder\n" \
        "lqc2 $vf27,0(%0)\n" \
        "lqc2 $vf28,0(%1)\n" \
        "lqc2 $vf29,16(%1)\n" \
        "lqc2 $vf30,32(%1)\n" \
        "lqc2 $vf31,48(%1)\n" \
        "vmulax.wxyz ACC,$vf28,$vf27x\n" \
        "vmadday.wxyz ACC,$vf29,$vf27y\n" \
        "vmaddaz.wxyz ACC,$vf30,$vf27z\n" \
        "vmaddw.wxyz $vf26,$vf31,$vf0w\n" \
        "sqc2 $vf26,0(%0)\n" \
        ".set reorder\n" : : "r"(v), "r"(m) : "memory")
/*TARGET 001f1728*/
/* Copy the vector at b+0x60 to out, then transform it by the matrices that a->mode selects. */
void func_001f1728(struct A1f1728* a, struct B1f1728* b, u128_1f1728* out) asm("func_001f1728");
/* Copy the vector at b+0x60 to out, then transform it by the matrices that a->mode selects. */
void func_001f1728(struct A1f1728* a, struct B1f1728* b, u128_1f1728* out) {
    *out = b->v;
    switch (a->mode) {
    case 0:
        break;
    case 1:
        MULMAT(out, D_01d9e6f0);
        break;
    case 2:
        if (D_00354688) {
            MULMAT(out, D_01d9e6f0);
            MULMAT(out, D_00354688 + 64);
        }
        break;
    case 3:
        MULMAT(out, D_01d9e6f0);
        MULMAT(out, D_01d9e7b0);
        break;
    }
}
}  // namespace n001f1728

// 001f1870 (was src/anon/batch_w1673.cpp)
namespace n001f1870 {
struct S1f1870 { u8 pad[0x9c]; u8 a; u8 b; u8 c; };
/*TARGET 001f1870*/
void func_001f1870(S1f1870* o, f32* pa, f32* pb, f32* pc, f32* pd) asm("func_001f1870");
void func_001f1870(S1f1870* o, f32* pa, f32* pb, f32* pc, f32* pd) {
    f32 x = 0.0f;
    f32 z = 1.0f;
    f32 y = z;
    switch (o->a) { case 1: y = 0.5f; break; case 2: y = 0.25f; break; }
    switch (o->b) { case 1: z = 0.5f; break; case 2: z = 0.25f; break; }
    switch (o->c) {
    case 1: x = 0.5f; y += 0.25f; break;
    case 2: x = 0.5f; y += x; break;
    case 3: x = 0.75f; y += x; break;
    }
    f32 e = 0.01f;
    *pa = x + e;
    *pb = y - e;
    *pc = e;
    *pd = z - e;
}
}  // namespace n001f1870

