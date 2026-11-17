// Linked unit 0x00200578-0x00201bb0 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));

// 00200578 (was gap)
namespace n00200578 {
struct S { u64 a, b, c, d, e, f; u8 pad[496 - 48]; s32 w; s16 h; u8 p2[2]; s16 r; u8 b6; };
s32 func_002fea18(void) asm("func_002fea18");
void func_00200578(u8* self, u8* t) asm("func_00200578");
void func_00200578(u8* self, u8* t) {
    u8* b = self + **(s32**)(t + 12);
    S* s = (S*)(b + 0xa0);
    s->b6 = 0;
    s->h = 0;
    s->w = 0;
    s->r = func_002fea18();
    *(u64*)(b + 160) = 0;
    s->b = 0;
    s->c = 0;
    s->d = 0;
    s->e = 0;
    s->f = 0;
}
}  // namespace n00200578

// 002005d8 (was gap)
namespace n002005d8 {
struct S { u64 a, b, c, d, e, f; };
void func_002005d8(u8* self, u8* t) asm("func_002005d8");
void func_002005d8(u8* self, u8* t) {
    u8* b = self + **(s32**)(t + 12);
    S* s = (S*)(b + 0xa0);
    *(u64*)(b + 160) = 0;
    s->b = 0;
    s->c = 0;
    s->d = 0;
    s->e = 0;
    s->f = 0;
}
}  // namespace n002005d8

// 00200608 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00200608 {
u32 sceVu0CopyMatrix(u32, u32, u32, u32) asm("_Z16sceVu0CopyMatrixjjjj");
extern u8 D_01d9e6f0 asm("D_01d9e6f0");
/*TARGET 00200608*/
// 0x001de568: definition moved into src/anon/unit_001ddcf0.cpp

// 001e09a0: moved to src/rikeda/saveram_gumibattle.cpp

u32 func_00200608(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00200608jjjj");
// 0x001de568: definition moved into src/anon/unit_001ddcf0.cpp

// 001e09a0: moved to src/rikeda/saveram_gumibattle.cpp

u32 func_00200608(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r14, r15;
    r15 = *(u32*)((u32)r5 + (s32)(12));
    r14 = *(u32*)((u32)r15 + (s32)(4));
    r5 = (u32)&D_01d9e6f0;
    r4 = (u32)(r4 + r14);
    r4 = (u32)((s32)r4 + (160));
    u32 (*fp_call4_002f3f98)(u32, u32, u32, u32) = sceVu0CopyMatrix;
    r2 = fp_call4_002f3f98(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00200608

// 00200638 (was src/anon/batch_w39.cpp)
namespace n00200638 {
// A local of this type keeps gcc from turning the final call into a sibling call.
struct NoTail { ~NoTail() {} };
// 0x001db5a8: definition moved into src/anon/unit_001d9d00.cpp

// --- 00200638
extern u8* D_01d9e6e8 asm("D_01d9e6e8");
extern u8 D_01d9e730[] asm("D_01d9e730");
extern u8 D_01d9e8c0[] asm("D_01d9e8c0");
void sceVu0MulMatrix(u8*, u8*, u8*) asm("sceVu0MulMatrix");
/*TARGET 00200638*/
void func_00200638(u8* a, u32 unused, u8* c) asm("func_00200638");
void func_00200638(u8* a, u32 unused, u8* c) {
    NoTail nt;
    sceVu0MulMatrix(D_01d9e6e8 + 80, D_01d9e730, a + *(s32*)(*(u8**)(c + 12) + 4) + 160);
    sceVu0MulMatrix(D_01d9e6e8 + 80, D_01d9e8c0, D_01d9e6e8 + 80);
    sceVu0MulMatrix(D_01d9e6e8 + 80, D_01d9e6e8 + 80, D_01d9e6e8 + 16);
}
}  // namespace n00200638

// 002006b0 (was src/anon/batch_w25.cpp)
namespace n002006b0 {
// 0x001de168: definition moved into src/anon/unit_001ddcf0.cpp

extern u8 D_00354bc0 asm("D_00354bc0");
extern u8 D_00354be0 asm("D_00354be0");
u8 sceVu0CopyVector(void*, void*) asm("sceVu0CopyVector");
/*TARGET 002006b0*/
// memcpy16
s32 func_002006b0(u8* a, u8* b) asm("func_002006b0");
// memcpy16
s32 func_002006b0(u8* a, u8* b) {
    u8* s = a + *(s32*)(*(u8**)(b + 12) + 4);
    sceVu0CopyVector(s + 160, &D_00354bc0);  // memcpy16
    return sceVu0CopyVector(s + 176, &D_00354be0);  // memcpy16
}
}  // namespace n002006b0

// 00200700 (was src/anon/batch_w78.cpp)
namespace n00200700 {
struct W78Vec {
    f32 x, y, z, w;
    W78Vec& operator=(const W78Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern u8* D_01d9e6e8 asm("D_01d9e6e8");
void sceVu0UnitMatrix(W78Vec*) asm("sceVu0UnitMatrix");
// vu_store_w_splat
void sceVu0MulMatrix(W78Vec*, void*, W78Vec*) asm("sceVu0MulMatrix");
void sceVu0ScaleVector(u8*, u8*, f32) asm("sceVu0ScaleVector");
// vec_scale_by_f12
void sceVu0ApplyMatrix(u8*, W78Vec*, u8*) asm("sceVu0ApplyMatrix");
extern u8 D_01d9e730[] asm("D_01d9e730");
extern u8 D_01d9e8c0[] asm("D_01d9e8c0");
/*TARGET 00200700*/
void func_00200700(u8* o, u32 a1, u8* a2) asm("func_00200700");
void func_00200700(u8* o, u32 a1, u8* a2) {
    W78Vec m[4];
    u8* p = o + (*(u32**)(a2 + 12))[1];
    sceVu0UnitMatrix(m);  // vu_store_w_splat
    f32* s = (f32*)(p + 160);
    m[3].x = s[0];
    m[3].y = s[1];
    m[3].z = s[2];
    sceVu0MulMatrix(m, D_01d9e730, m);
    sceVu0ScaleVector(D_01d9e6e8 + 80, D_01d9e6e8 + 16, s[4]);  // vec_scale_by_f12
    sceVu0ScaleVector(D_01d9e6e8 + 96, D_01d9e6e8 + 32, s[5]);  // vec_scale_by_f12
    sceVu0ScaleVector(D_01d9e6e8 + 112, D_01d9e6e8 + 48, s[6]);  // vec_scale_by_f12
    sceVu0ApplyMatrix(D_01d9e6e8 + 128, m, D_01d9e6e8 + 64);
    sceVu0MulMatrix((W78Vec*)(D_01d9e6e8 + 80), D_01d9e8c0, (W78Vec*)(D_01d9e6e8 + 80));
}
}  // namespace n00200700

// 002007e0 (was src/anon/batch_w26.cpp)
namespace n002007e0 {
u8 sceVu0CopyVector(void*, void*) asm("sceVu0CopyVector");
extern u8 D_00354bc0[] asm("D_00354bc0");
extern u8 D_00354be0[] asm("D_00354be0");
/*TARGET 002007e0*/
// 0x001de4b0: definition moved into src/anon/unit_001ddcf0.cpp

u8 func_002007e0(u8* p, u8* q) asm("func_002007e0");
// 0x001de4b0: definition moved into src/anon/unit_001ddcf0.cpp

u8 func_002007e0(u8* p, u8* q) {
    u8* b = p + *(s32*)(*(u8**)(q + 12) + 4);
    sceVu0CopyVector(b + 160, D_00354bc0);  // memcpy16
    return sceVu0CopyVector(b + 176, D_00354be0);  // memcpy16
}
}  // namespace n002007e0

// 00200830 (was src/anon/batch_w95.cpp)
namespace n00200830 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct M4 { V4 r[4]; } __attribute__((aligned(16)));
struct XfRec { f32 x, y, z, pad; f32 rx, ry, rz, pad2; f32 s[3]; };
struct XfCtx { u8 pad[12]; u32* offs; };
struct XfMat { u8 pad[16]; f32 r0[4]; f32 r1[4]; f32 r2[4]; f32 r3[4]; f32 m0[4]; f32 m1[4]; f32 m2[4]; f32 m3[4]; };
// 0x001d2a68: definition moved into src/anon/unit_001d2810.cpp

union XfMatPtr { XfMat* p; f32 f; };
extern XfMatPtr D_01d9e6e8 asm("D_01d9e6e8");
extern M4 D_01d9e730 asm("D_01d9e730");
extern M4 D_01d9e8c0 asm("D_01d9e8c0");
void sceVu0UnitMatrix(M4*) asm("sceVu0UnitMatrix");
// vu_store_w_splat
void sceVu0MulMatrix(void*, void*, void*) asm("sceVu0MulMatrix");
void sceVu0ScaleVector(f32*, f32*, f32) asm("sceVu0ScaleVector");
// vec_scale_by_f12
void sceVu0MulVector(f32*, f32*, f32*) asm("sceVu0MulVector");
/*TARGET 00200830*/
void func_00200830(u8* base, u32, XfCtx* c) asm("func_00200830");
void func_00200830(u8* base, u32, XfCtx* c) {
    XfRec* r = (XfRec*)(base + c->offs[1] + 160);
    M4 m;
    sceVu0UnitMatrix(&m);  // vu_store_w_splat
    m.r[3].x = r->x;
    m.r[3].y = r->y;
    m.r[3].z = r->z;
    sceVu0MulMatrix(&m, &D_01d9e730, &m);
    sceVu0ScaleVector(D_01d9e6e8.p->m0, D_01d9e6e8.p->r0, r->rx);  // vec_scale_by_f12
    sceVu0ScaleVector(D_01d9e6e8.p->m1, D_01d9e6e8.p->r1, r->ry);  // vec_scale_by_f12
    sceVu0ScaleVector(D_01d9e6e8.p->m2, D_01d9e6e8.p->r2, r->rz);  // vec_scale_by_f12
    sceVu0MulVector(D_01d9e6e8.p->m3, D_01d9e6e8.p->r3, &r->rx);
    D_01d9e6e8.p->m3[0] += m.r[3].x;
    D_01d9e6e8.p->m3[1] += m.r[3].y;
    D_01d9e6e8.p->m3[2] += m.r[3].z;
    sceVu0MulMatrix(D_01d9e6e8.p->m0, &D_01d9e8c0, D_01d9e6e8.p->m0);
}
}  // namespace n00200830

// 00200950 (was src/anon/batch_w260.cpp)
namespace n00200950 {
struct W260Q { f32 x, y, z, w; } __attribute__((aligned(16)));
struct W260Cam { u8 pad0[16]; f32 x, y, z; };
// 0x0019d5f8: definition moved into src/anon/unit_0019ba60.cpp

u8 sceVu0CopyVector(void*, void*) asm("sceVu0CopyVector");
// memcpy16
void sceVu0Normalize(W260Q*, W260Q*) asm("sceVu0Normalize");
// vec4_normalize
void sceVu0OuterProduct(W260Q*, W260Q*, W260Q*) asm("sceVu0OuterProduct");
// vec3_cross
void w260_mtx(void*, void*, void*) asm("_Z15sceVu0MulMatrixjjjj");
extern u8 D_00354bc0[] asm("D_00354bc0");
extern u8 D_00354be0[] asm("D_00354be0");
extern W260Cam D_01d9e840 asm("D_01d9e840");
extern W260Q D_01d9e870 asm("D_01d9e870");
extern W260Q D_01d9e880 asm("D_01d9e880");
extern W260Q D_01d9e890 asm("D_01d9e890");
extern W260Q D_01d9e8a0 asm("D_01d9e8a0");
extern W260Q D_01d9e8b0 asm("D_01d9e8b0");
extern u8 D_01d9e8c0[] asm("D_01d9e8c0");
extern u8 D_01d9e940[] asm("D_01d9e940");
/*TARGET 00200950*/
void func_00200950(u8* p, u8* q) asm("func_00200950");
void func_00200950(u8* p, u8* q)
{
    W260Q a, b, c;
    u8* s = p + *(s32*)(*(u8**)(q + 12) + 4);
    sceVu0CopyVector(s + 160, D_00354bc0);  // memcpy16
    sceVu0CopyVector(s + 176, D_00354be0);  // memcpy16
    b.x = D_01d9e840.x; b.w = 0; b.y = D_01d9e840.y; b.z = D_01d9e840.z;
    sceVu0Normalize(&b, &b);  // vec4_normalize
    D_01d9e890 = b;
    a.x = b.y; a.y = -b.x; a.z = 0; a.w = 0;
    sceVu0Normalize(&a, &a);  // vec4_normalize
    D_01d9e880 = a;
    sceVu0OuterProduct(&c, &a, &b);  // vec3_cross
    sceVu0Normalize(&c, &c);  // vec4_normalize
    D_01d9e8a0 = c;
    D_01d9e8b0 = D_01d9e870;
    w260_mtx(D_01d9e940, D_01d9e8c0, &D_01d9e880);
}
}  // namespace n00200950

// 00200a78 (was src/anon/batch_w84.cpp)
namespace n00200a78 {
extern u8 D_01d9e730[] asm("D_01d9e730");
extern u8 D_01d9e8c0[] asm("D_01d9e8c0");
void sceVu0UnitMatrix(void*) asm("sceVu0UnitMatrix");
// vu_store_w_splat
void sceVu0MulMatrix(void*, void*, void*) asm("sceVu0MulMatrix");
void sceVu0ScaleVector(void*, void*, f32) asm("sceVu0ScaleVector");
// vec_scale_by_f12
void sceVu0ApplyMatrix(void*, void*, void*) asm("sceVu0ApplyMatrix");
union PQ { u8* p; u128 q; };
extern PQ D_01d9e6e8u asm("D_01d9e6e8");
extern u8 D_01d9e940[] asm("D_01d9e940");
/*TARGET 00200a78*/
void func_00200a78(u8* a, u32, u8* c) asm("func_00200a78");
void func_00200a78(u8* a, u32, u8* c) {
    f32 m[16] __attribute__((aligned(16)));
    u8* s = a + *(u32*)(*(u8**)(c + 12) + 4);
    sceVu0UnitMatrix(m);  // vu_store_w_splat
    f32* v = (f32*)(s + 160);
    m[12] = v[0];
    m[13] = v[1];
    m[14] = v[2];
    sceVu0MulMatrix(m, D_01d9e730, m);
    sceVu0MulMatrix(m, D_01d9e8c0, m);
    sceVu0ScaleVector(D_01d9e6e8u.p + 80, D_01d9e6e8u.p + 16, v[4]);  // vec_scale_by_f12
    sceVu0ScaleVector(D_01d9e6e8u.p + 96, D_01d9e6e8u.p + 32, v[5]);  // vec_scale_by_f12
    sceVu0ScaleVector(D_01d9e6e8u.p + 112, D_01d9e6e8u.p + 48, v[6]);  // vec_scale_by_f12
    *(u128*)(D_01d9e6e8u.p + 128) = *(u128*)(D_01d9e6e8u.p + 64);
    sceVu0MulMatrix(D_01d9e6e8u.p + 80, D_01d9e940, D_01d9e6e8u.p + 80);
    sceVu0ApplyMatrix(D_01d9e6e8u.p + 128, m, D_01d9e6e8u.p + 64);
}
}  // namespace n00200a78

// 00200b78 (was src/anon/batch_w80.cpp)
namespace n00200b78 {
// ---- unit 5 (good200.cpp)
struct U5_PartTbl { u32 f0; u32 f4; u32 f8; u32 f12; };
struct U5_PartRef { u8 pad[12]; U5_PartTbl* tbl; };
extern f32 D_00354bd0[3] asm("D_00354bd0");
extern f32 D_00354bc0[3] asm("D_00354bc0");
struct U5_Rot { u8 pad[48]; f32 f48, f52, f56; };
void func_001e8fe0(U5_Rot*, s32*) asm("func_001e8fe0");
/*TARGET 00200b78*/
void func_00200b78(u8* base, U5_PartRef* r) asm("func_00200b78");
void func_00200b78(u8* base, U5_PartRef* r) {
    s32 v[3];
    U5_Rot* o;
    o = (U5_Rot*)(base + r->tbl->f12 + 160);
    v[0] = (s32)(D_00354bd0[0] * 32768.0f / 3.1415927f);
    v[1] = (s32)(D_00354bd0[1] * 32768.0f / 3.1415927f);
    v[2] = (s32)(D_00354bd0[2] * 32768.0f / 3.1415927f);
    func_001e8fe0(o, v);
    o->f48 = D_00354bc0[0];
    o->f52 = D_00354bc0[1];
    o->f56 = D_00354bc0[2];
}
}  // namespace n00200b78

// 00200c50 (was src/anon/batch_w98.cpp)
namespace n00200c50 {
// 0x001d42d0: definition moved into src/anon/unit_001d3c08.cpp

struct M200 { f32 m[4][4]; } __attribute__((aligned(16)));
struct Cam200 { u8 pad[16]; M200 mat; };
union CamP200 { Cam200* p; f32 f; u32 u; };
extern CamP200 D_01d9e6e8 asm("D_01d9e6e8");
extern u8 D_00354bd0[] asm("D_00354bd0");
extern f32 D_00354bc0[4] asm("D_00354bc0");
void func_001e8fe0(void*, void*) asm("func_001e8fe0");
void sceVu0InversMatrix(M200*, M200*) asm("sceVu0InversMatrix");
// convert_vectors_to_scalar
void sceVu0MulMatrix(void*, void*, void*) asm("sceVu0MulMatrix");
static inline void ScaleRow(f32* row, u32 k) {
    asm volatile("qmtc2 %1, $vf9\n\tlqc2 $vf10, 0(%0)\n\tvmulx.xyz $vf10, $vf10, $vf9x\n\tsqc2 $vf10, 0(%0)" : : "r"(row), "r"(k) : "memory");
}
/*TARGET 00200c50*/
// Builds the camera matrix from rotation/translation/scale channels.
void func_00200c50(u8* base, u8*, u8* c) asm("func_00200c50");
// Builds the camera matrix from rotation/translation/scale channels.
void func_00200c50(u8* base, u8*, u8* c) {
    u32* offs = *(u32**)(c + 12);
    u8* rot = base + offs[1] + 160;
    u8* sc = base + offs[3] + 160;
    f32* pos = (f32*)(base + offs[0] + 160);
    u32* scale = (u32*)(base + offs[2] + 160);
    M200 m;
    func_001e8fe0(&D_01d9e6e8.p->mat, rot);
    D_01d9e6e8.p->mat.m[3][0] = pos[0];
    D_01d9e6e8.p->mat.m[3][1] = pos[1];
    D_01d9e6e8.p->mat.m[3][2] = pos[2];
    func_001e8fe0(&m, D_00354bd0);
    m.m[3][0] = D_00354bc0[0];
    m.m[3][1] = D_00354bc0[1];
    m.m[3][2] = D_00354bc0[2];
    sceVu0InversMatrix(&m, &m);  // convert_vectors_to_scalar
    sceVu0MulMatrix(&D_01d9e6e8.p->mat, &D_01d9e6e8.p->mat, sc);
    sceVu0MulMatrix(&D_01d9e6e8.p->mat, &m, &D_01d9e6e8.p->mat);
    ScaleRow(D_01d9e6e8.p->mat.m[0], scale[0]);
    ScaleRow(D_01d9e6e8.p->mat.m[1], scale[1]);
    ScaleRow(D_01d9e6e8.p->mat.m[2], scale[2]);
}
}  // namespace n00200c50

// 00200da8 (was src/anon/batch_w81.cpp)
namespace n00200da8 {
// 001cc160: moved to src/anon/unit_001cc048.cpp

// --- 00200da8: rotation (radians -> 16-bit angle units) and translation into the node
struct Tbl200 { u8 pad[12]; s32* offs; };
struct V3_81 { f32 x, y, z; };
extern V3_81 D_00354bd0 asm("D_00354bd0");
extern V3_81 D_00354bc0 asm("D_00354bc0");
void func_0021eb50(u8*, s32*) asm("func_0021eb50");
/*TARGET 00200da8*/
void func_00200da8(u8* o, Tbl200* t) asm("func_00200da8");
void func_00200da8(u8* o, Tbl200* t) {
    s32 v[3];
    u8* p = o + t->offs[3] + 160;
    v[0] = (s32)(D_00354bd0.x * 32768.0f / 3.1415927f);
    v[1] = (s32)(D_00354bd0.y * 32768.0f / 3.1415927f);
    v[2] = (s32)(D_00354bd0.z * 32768.0f / 3.1415927f);
    func_0021eb50(p, v);
    *(f32*)(p + 48) = D_00354bc0.x;
    *(f32*)(p + 52) = D_00354bc0.y;
    *(f32*)(p + 56) = D_00354bc0.z;
}
}  // namespace n00200da8

// 00200e80 (was src/anon/batch_w99.cpp)
namespace n00200e80 {
struct M200e { f32 m[16]; } __attribute__((aligned(16)));
struct G200e { u8 pad[16]; M200e mtx; };
union U200e { G200e* p; f32 f; };
extern U200e D_01d9e6e8 asm("D_01d9e6e8");
extern M200e D_00354bd0 asm("D_00354bd0");
extern f32 D_00354bc0[3] asm("D_00354bc0");
void func_0021eb50(M200e*, void*) asm("func_0021eb50");
void sceVu0InversMatrix(M200e*, M200e*) asm("sceVu0InversMatrix");
// convert_vectors_to_scalar
void sceVu0MulMatrix(M200e*, M200e*, void*) asm("sceVu0MulMatrix");
static inline void ScaleRow200e(f32* row, f32 s)
{
    asm("qmtc2 %1, $vf9\n\tlqc2 $vf10, 0(%0)\n\tvmulx.xyz $vf10, $vf10, $vf9x\n\tsqc2 $vf10, 0(%0)"
        : : "r"(row), "r"(s) : "memory");
}
/*TARGET 00200e80*/
void func_00200e80(u8* p, u32, u8* a2) asm("func_00200e80");
void func_00200e80(u8* p, u32, u8* a2)
{
    u32* offs = *(u32**)(a2 + 12);
    f32* pos = (f32*)(p + offs[0] + 160);
    u8* rot = p + offs[1] + 160;
    u8* m = p + offs[3] + 160;
    f32* scl = (f32*)(p + offs[2] + 160);
    M200e t;
    func_0021eb50(&D_01d9e6e8.p->mtx, rot);
    D_01d9e6e8.p->mtx.m[12] = pos[0];
    D_01d9e6e8.p->mtx.m[13] = pos[1];
    D_01d9e6e8.p->mtx.m[14] = pos[2];
    func_0021eb50(&t, &D_00354bd0);
    t.m[12] = D_00354bc0[0];
    t.m[13] = D_00354bc0[1];
    t.m[14] = D_00354bc0[2];
    sceVu0InversMatrix(&t, &t);  // convert_vectors_to_scalar
    sceVu0MulMatrix(&D_01d9e6e8.p->mtx, &D_01d9e6e8.p->mtx, m);
    sceVu0MulMatrix(&D_01d9e6e8.p->mtx, &t, &D_01d9e6e8.p->mtx);
    ScaleRow200e(&D_01d9e6e8.p->mtx.m[0], scl[0]);
    ScaleRow200e(&D_01d9e6e8.p->mtx.m[4], scl[1]);
    ScaleRow200e(&D_01d9e6e8.p->mtx.m[8], scl[2]);
}
}  // namespace n00200e80

// 00200fd8 (was src/anon/batch_w82.cpp)
namespace n00200fd8 {
extern f32 D_00354bd0[3] asm("D_00354bd0");
extern f32 D_00354bc0[3] asm("D_00354bc0");
void func_0021ec80(u8*, s32*) asm("func_0021ec80");
/*TARGET 00200fd8*/
// 0x001fcb90: definition moved into src/anon/unit_001fcaf8.cpp

// Converts the global euler angles (radians) to 16-bit fixed angles and applies them.
void func_00200fd8(u8* a0, u8* a1) asm("func_00200fd8");
// 0x001fcb90: definition moved into src/anon/unit_001fcaf8.cpp

// Converts the global euler angles (radians) to 16-bit fixed angles and applies them.
void func_00200fd8(u8* a0, u8* a1)
{
    s32 v[4];
    u8* p;
    p = a0 + *(u32*)(*(u8**)(a1 + 12) + 12) + 160;
    v[0] = (s32)(D_00354bd0[0] * 32768.0f / 3.14159274f);
    v[1] = (s32)(D_00354bd0[1] * 32768.0f / 3.14159274f);
    v[2] = (s32)(D_00354bd0[2] * 32768.0f / 3.14159274f);
    func_0021ec80(p, v);
    *(f32*)(p + 48) = D_00354bc0[0];
    *(f32*)(p + 52) = D_00354bc0[1];
    *(f32*)(p + 56) = D_00354bc0[2];
}
}  // namespace n00200fd8

// 002010b0 (was src/anon/batch_w100.cpp)
namespace n002010b0 {
struct M22 { f32 m[12]; f32 t[4]; } __attribute__((aligned(16)));
union Cam22 { u8* p; f32 f; };
extern Cam22 D_01d9e6e8 asm("D_01d9e6e8");
extern u8 D_00354bd0[] asm("D_00354bd0");
extern f32 D_00354bc0[3] asm("D_00354bc0");
void func_0021ec80(void*, void*) asm("func_0021ec80");
void sceVu0InversMatrix(M22*, M22*) asm("sceVu0InversMatrix");
// convert_vectors_to_scalar
void sceVu0MulMatrix(void*, void*, void*) asm("sceVu0MulMatrix");
static inline void ScaleRow(void* row, f32 s) {
    asm volatile("qmtc2 %1, $vf9\n\tlqc2 $vf10, 0(%0)\n\tvmulx.xyz $vf10, $vf10, $vf9x\n\tsqc2 $vf10, 0(%0)" : : "r"(row), "r"(s) : "memory");
}
/*TARGET 002010b0*/
void func_002010b0(u8* o, u32 a1, u8* x) asm("func_002010b0");
void func_002010b0(u8* o, u32 a1, u8* x) {
    s32* off = *(s32**)(x + 12);
    M22 m;
    u8* mtx = o + off[3] + 160;
    f32* scl = (f32*)(o + off[2] + 160);
    f32* pos = (f32*)(o + off[0] + 160);
    func_0021ec80(D_01d9e6e8.p + 16, o + off[1] + 160);
    *(f32*)(D_01d9e6e8.p + 64) = pos[0];
    *(f32*)(D_01d9e6e8.p + 68) = pos[1];
    *(f32*)(D_01d9e6e8.p + 72) = pos[2];
    func_0021ec80(&m, D_00354bd0);
    m.t[0] = D_00354bc0[0];
    m.t[1] = D_00354bc0[1];
    m.t[2] = D_00354bc0[2];
    sceVu0InversMatrix(&m, &m);  // convert_vectors_to_scalar
    sceVu0MulMatrix(D_01d9e6e8.p + 16, D_01d9e6e8.p + 16, mtx);
    sceVu0MulMatrix(D_01d9e6e8.p + 16, &m, D_01d9e6e8.p + 16);
    ScaleRow(D_01d9e6e8.p + 16, scl[0]);
    ScaleRow(D_01d9e6e8.p + 32, scl[1]);
    ScaleRow(D_01d9e6e8.p + 48, scl[2]);
}
}  // namespace n002010b0

// 00201208 (was src/anon/batch_w83.cpp)
namespace n00201208 {
// 0x001f6030: definition moved into src/anon/unit_001f5978.cpp

extern f32 D_00354bd0[3] asm("D_00354bd0");
extern f32 D_00354bc0[3] asm("D_00354bc0");
void func_0021ebe8(void*, s32*) asm("func_0021ebe8");
/*TARGET 00201208*/
// Radians -> 16-bit angle units (32768 per pi).
void func_00201208(u8* p, u8* c) asm("func_00201208");
// Radians -> 16-bit angle units (32768 per pi).
void func_00201208(u8* p, u8* c) {
    u8* s = p + *(s32*)(*(u8**)(c + 12) + 12) + 160;
    s32 a[3];
    a[0] = (s32)(D_00354bd0[0] * 32768.0f / 3.1415927f);
    a[1] = (s32)(D_00354bd0[1] * 32768.0f / 3.1415927f);
    a[2] = (s32)(D_00354bd0[2] * 32768.0f / 3.1415927f);
    func_0021ebe8(s, a);
    *(f32*)(s + 48) = D_00354bc0[0];
    *(f32*)(s + 52) = D_00354bc0[1];
    *(f32*)(s + 56) = D_00354bc0[2];
}
}  // namespace n00201208

// 002012e0 (was src/anon/batch_w271.cpp)
namespace n002012e0 {
struct M_w271 { f32 m[12]; f32 t[4]; } __attribute__((aligned(16)));
union Cam_w271 { u8* p; f32 f; };
extern Cam_w271 D_01d9e6e8 asm("D_01d9e6e8");
extern u8 D_00354bd0[] asm("D_00354bd0");
extern f32 D_00354bc0[3] asm("D_00354bc0");
void func_0021ebe8(void*, void*) asm("func_0021ebe8");
void sceVu0InversMatrix(M_w271*, M_w271*) asm("sceVu0InversMatrix");
// convert_vectors_to_scalar
void sceVu0MulMatrix(void*, void*, void*) asm("sceVu0MulMatrix");
static inline void ScaleRow_w271(void* row, f32 s) {
    asm volatile("qmtc2 %1, $vf9\n\tlqc2 $vf10, 0(%0)\n\tvmulx.xyz $vf10, $vf10, $vf9x\n\tsqc2 $vf10, 0(%0)" : : "r"(row), "r"(s) : "memory");
}
#define BODY_W271(ROT) \
    s32* off = *(s32**)(x + 12); \
    M_w271 m; \
    u8* mtx = o + off[3] + 160; \
    f32* scl = (f32*)(o + off[2] + 160); \
    f32* pos = (f32*)(o + off[0] + 160); \
    ROT(D_01d9e6e8.p + 16, o + off[1] + 160); \
    *(f32*)(D_01d9e6e8.p + 64) = pos[0]; \
    *(f32*)(D_01d9e6e8.p + 68) = pos[1]; \
    *(f32*)(D_01d9e6e8.p + 72) = pos[2]; \
    ROT(&m, D_00354bd0); \
    m.t[0] = D_00354bc0[0]; \
    m.t[1] = D_00354bc0[1]; \
    m.t[2] = D_00354bc0[2]; \
    sceVu0InversMatrix(&m, &m); \
    sceVu0MulMatrix(D_01d9e6e8.p + 16, D_01d9e6e8.p + 16, mtx); \
    sceVu0MulMatrix(D_01d9e6e8.p + 16, &m, D_01d9e6e8.p + 16); \
    ScaleRow_w271(D_01d9e6e8.p + 16, scl[0]); \
    ScaleRow_w271(D_01d9e6e8.p + 32, scl[1]); \
    ScaleRow_w271(D_01d9e6e8.p + 48, scl[2]);
/*TARGET 002012e0*/
void func_002012e0(u8* o, u32 a1, u8* x) asm("func_002012e0");
void func_002012e0(u8* o, u32 a1, u8* x) { BODY_W271(func_0021ebe8) }
}  // namespace n002012e0

// 00201438 (was src/anon/batch_w84.cpp)
namespace n00201438 {
// Converts a radian rotation to fixed angles and applies it.
struct V3 { f32 x, y, z; };
extern V3 D_00354bd0 asm("D_00354bd0");
extern V3 D_00354bc0 asm("D_00354bc0");
void func_0021ebe8(void*, s32*) asm("func_0021ebe8");
/*TARGET 00201438*/
void func_00201438(u8* a, u8* c) asm("func_00201438");
void func_00201438(u8* a, u8* c) {
    s32 r[3];
    u8* s = a + *(u32*)(*(u8**)(c + 12) + 12) + 160;
    r[0] = (s32)(D_00354bd0.x * 32768.0f / 3.1415927f);
    r[1] = (s32)(D_00354bd0.y * 32768.0f / 3.1415927f);
    r[2] = (s32)(D_00354bd0.z * 32768.0f / 3.1415927f);
    func_0021ebe8(s, r);
    *(f32*)(s + 48) = D_00354bc0.x;
    *(f32*)(s + 52) = D_00354bc0.y;
    *(f32*)(s + 56) = D_00354bc0.z;
}
}  // namespace n00201438

// 00201510 (was src/anon/batch_w1885.cpp)
namespace n00201510 {
struct M1885 { f32 m[16]; } __attribute__((aligned(16)));
struct G1885 { u8 pad[16]; M1885 mtx; };
union U1885 { G1885* p; f32 f; };
extern U1885 D_01d9e6e8 asm("D_01d9e6e8");
extern M1885 D_00354bd0 asm("D_00354bd0");
extern f32 D_00354bc0[3] asm("D_00354bc0");
void func_0021ed18(M1885*, void*) asm("func_0021ed18");
void sceVu0InversMatrix(M1885*, M1885*) asm("sceVu0InversMatrix");
void sceVu0MulMatrix(M1885*, M1885*, void*) asm("sceVu0MulMatrix");
static inline void ScaleRow1885(f32* row, f32 s)
{
    asm("qmtc2 %1, $vf9\n\tlqc2 $vf10, 0(%0)\n\tvmulx.xyz $vf10, $vf10, $vf9x\n\tsqc2 $vf10, 0(%0)"
        : : "r"(row), "r"(s) : "memory");
}
/*TARGET 00201510*/
// 00201510: model node matrix build (rotate, translate, multiply, VU0 row scale). Same shape as func_00200e80.
void func_00201510(u8* p, u32, u8* a2) asm("func_00201510");
// 00201510: model node matrix build (rotate, translate, multiply, VU0 row scale). Same shape as func_00200e80.
void func_00201510(u8* p, u32, u8* a2)
{
    u32* offs = *(u32**)(a2 + 12);
    f32* pos = (f32*)(p + offs[0] + 160);
    u8* rot = p + offs[1] + 160;
    u8* m = p + offs[3] + 160;
    f32* scl = (f32*)(p + offs[2] + 160);
    M1885 t;
    func_0021ed18(&D_01d9e6e8.p->mtx, rot);
    D_01d9e6e8.p->mtx.m[12] = pos[0];
    D_01d9e6e8.p->mtx.m[13] = pos[1];
    D_01d9e6e8.p->mtx.m[14] = pos[2];
    func_0021ed18(&t, &D_00354bd0);
    t.m[12] = D_00354bc0[0];
    t.m[13] = D_00354bc0[1];
    t.m[14] = D_00354bc0[2];
    sceVu0InversMatrix(&t, &t);
    sceVu0MulMatrix(&D_01d9e6e8.p->mtx, &D_01d9e6e8.p->mtx, m);
    sceVu0MulMatrix(&D_01d9e6e8.p->mtx, &t, &D_01d9e6e8.p->mtx);
    ScaleRow1885(&D_01d9e6e8.p->mtx.m[0], scl[0]);
    ScaleRow1885(&D_01d9e6e8.p->mtx.m[4], scl[1]);
    ScaleRow1885(&D_01d9e6e8.p->mtx.m[8], scl[2]);
}
}  // namespace n00201510

// 00201668 (was src/anon/batch_w85.cpp)
namespace n00201668 {
// 0x001d89e8: definition moved into src/anon/unit_001d7458.cpp

// 001e09d0: moved to src/rikeda/saveram_gumibattle.cpp

struct V3f { f32 x, y, z; };
extern V3f D_00354bd0 asm("D_00354bd0");
extern V3f D_00354bc0 asm("D_00354bc0");
void func_0021ebe8(void*, s32*) asm("func_0021ebe8");
/*TARGET 00201668*/
// converts the current rotation (radians) to fixed-point angles and applies it
void func_00201668(u8* o, u8* a1) asm("func_00201668");
// converts the current rotation (radians) to fixed-point angles and applies it
void func_00201668(u8* o, u8* a1) {
    s32 r[3];
    u8* t;
    f32 x = D_00354bd0.x * 32768.0f / 3.1415927f;
    f32 y = D_00354bd0.y * 32768.0f / 3.1415927f;
    f32 z = D_00354bd0.z * 32768.0f / 3.1415927f;
    t = o + *(s32*)(*(u8**)(a1 + 12) + 12) + 160;
    r[0] = (s32)x;
    r[2] = (s32)z;
    r[1] = (s32)y;
    func_0021ebe8(t, r);
    *(f32*)(t + 48) = D_00354bc0.x;
    *(f32*)(t + 52) = D_00354bc0.y;
    *(f32*)(t + 56) = D_00354bc0.z;
}
}  // namespace n00201668

// 00201740 (was src/anon/batch_w271.cpp)
namespace n00201740 {
struct M_w271 { f32 m[12]; f32 t[4]; } __attribute__((aligned(16)));
union Cam_w271 { u8* p; f32 f; };
extern Cam_w271 D_01d9e6e8 asm("D_01d9e6e8");
extern u8 D_00354bd0[] asm("D_00354bd0");
extern f32 D_00354bc0[3] asm("D_00354bc0");
void func_0021edb0(void*, void*) asm("func_0021edb0");
void sceVu0InversMatrix(M_w271*, M_w271*) asm("sceVu0InversMatrix");
// convert_vectors_to_scalar
void sceVu0MulMatrix(void*, void*, void*) asm("sceVu0MulMatrix");
static inline void ScaleRow_w271(void* row, f32 s) {
    asm volatile("qmtc2 %1, $vf9\n\tlqc2 $vf10, 0(%0)\n\tvmulx.xyz $vf10, $vf10, $vf9x\n\tsqc2 $vf10, 0(%0)" : : "r"(row), "r"(s) : "memory");
}
#define BODY_W271(ROT) \
    s32* off = *(s32**)(x + 12); \
    M_w271 m; \
    u8* mtx = o + off[3] + 160; \
    f32* scl = (f32*)(o + off[2] + 160); \
    f32* pos = (f32*)(o + off[0] + 160); \
    ROT(D_01d9e6e8.p + 16, o + off[1] + 160); \
    *(f32*)(D_01d9e6e8.p + 64) = pos[0]; \
    *(f32*)(D_01d9e6e8.p + 68) = pos[1]; \
    *(f32*)(D_01d9e6e8.p + 72) = pos[2]; \
    ROT(&m, D_00354bd0); \
    m.t[0] = D_00354bc0[0]; \
    m.t[1] = D_00354bc0[1]; \
    m.t[2] = D_00354bc0[2]; \
    sceVu0InversMatrix(&m, &m); \
    sceVu0MulMatrix(D_01d9e6e8.p + 16, D_01d9e6e8.p + 16, mtx); \
    sceVu0MulMatrix(D_01d9e6e8.p + 16, &m, D_01d9e6e8.p + 16); \
    ScaleRow_w271(D_01d9e6e8.p + 16, scl[0]); \
    ScaleRow_w271(D_01d9e6e8.p + 32, scl[1]); \
    ScaleRow_w271(D_01d9e6e8.p + 48, scl[2]);
/*TARGET 00201740*/
void func_00201740(u8* o, u32 a1, u8* x) asm("func_00201740");
void func_00201740(u8* o, u32 a1, u8* x) { BODY_W271(func_0021edb0) }
}  // namespace n00201740

// 00201898 (was src/anon/batch_w245.cpp)
namespace n00201898 {
struct M22 { f32 m[16]; } __attribute__((aligned(16)));
union Cam22 { u8* p; f32 f; };
extern Cam22 D_01d9e6e8 asm("D_01d9e6e8");
extern M22 D_01d9e730 asm("D_01d9e730");
void sceVu0InversMatrix(void*, void*) asm("sceVu0InversMatrix");
static inline void ScaleRow(void* row, f32 s) {
    asm volatile("qmtc2 %1, $vf9\n\tlqc2 $vf10, 0(%0)\n\tvmulx.xyz $vf10, $vf10, $vf9x\n\tsqc2 $vf10, 0(%0)" : : "r"(row), "r"(s) : "memory");
}
/*TARGET 00201898*/
void func_00201898(u8* o, u32 a1, u8* x) asm("func_00201898");
void func_00201898(u8* o, u32 a1, u8* x) {
    s32* off = *(s32**)(x + 12);
    f32* pos = (f32*)(o + off[0] + 160);
    f32* scl = (f32*)(o + off[2] + 160);
    sceVu0InversMatrix(D_01d9e6e8.p + 16, &D_01d9e730);  // convert_vectors_to_scalar
    ScaleRow(D_01d9e6e8.p + 16, scl[0]);
    ScaleRow(D_01d9e6e8.p + 32, scl[1]);
    ScaleRow(D_01d9e6e8.p + 48, scl[2]);
    *(f32*)(D_01d9e6e8.p + 64) = pos[0];
    *(f32*)(D_01d9e6e8.p + 68) = pos[1];
    *(f32*)(D_01d9e6e8.p + 72) = pos[2];
}
}  // namespace n00201898

// 00201978 (was src/anon/spline_vu0_owner1025.c)
namespace n00201978 {
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
extern u8 D_003590c0[] asm("D_003590c0");
/*TARGET 00201978*/
// 0x001f1248: definition moved into src/anon/unit_001f0cd8.cpp

void func_00201978(void* in, s32 n, void* out) asm("func_00201978");
// 0x001f1248: definition moved into src/anon/unit_001f0cd8.cpp

void func_00201978(void* in, s32 n, void* out)
{
    u128 work[32];
    SPLINE_SOLVE(in, n, out, D_003590c0, work);
}
}  // namespace n00201978

// 00201b30 (was src/anon/batch_w65.cpp)
namespace n00201b30 {
// 16-byte vector; assignment copies with a 128-bit lq/sq.
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
// 0x001e6c40: definition moved into src/anon/unit_001e0cb8.cpp

// Cubic interpolation between key pairs a[i..i+1] / b[i..i+1] at fractional t (VU0).
extern Vq D_003590d0 asm("D_003590d0");
/*TARGET 00201b30*/
void func_00201b30(Vq* o, Vq* a, Vq* b, f32 t) asm("func_00201b30");
void func_00201b30(Vq* o, Vq* a, Vq* b, f32 t) {
    s32 i = (s32)t;
    a += i;
    b += i;
    D_003590d0.z = t - (f32)i;
    asm volatile(".set noreorder\n\t"
        "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 0(%2)\n\tlqc2 $vf4, 16(%2)\n\tlqc2 $vf5, 0(%3)\n\t"
        "vsub.xyzw $vf10, $vf4, $vf3\n\tvmuly.xyzw $vf11, $vf3, $vf5y\n\tvmulx.xyzw $vf12, $vf3, $vf5x\n\tvsub.xyzw $vf13, $vf2, $vf1\n\t"
        "vmulz.xyzw $vf10, $vf10, $vf5z\n\tvadd.xyzw $vf11, $vf11, $vf4\n\tvadd.xyzw $vf10, $vf10, $vf12\n\tvsub.xyzw $vf13, $vf13, $vf11\n\t"
        "vmulz.xyzw $vf10, $vf10, $vf5z\n\tvadd.xyzw $vf10, $vf10, $vf13\n\tvmulz.xyzw $vf10, $vf10, $vf5z\n\tvadd.xyzw $vf10, $vf10, $vf1\n\t"
        "sqc2 $vf10, 0(%0)\n\t.set reorder"
        : : "r"(o), "r"(a), "r"(b), "r"(&D_003590d0) : "memory");
}
}  // namespace n00201b30

