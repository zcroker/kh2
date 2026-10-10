#include "../common/types.h"

extern "C" {

union PtrF247 { u8* p; f32 f; };
extern PtrF247 D_01d9e6e8;
void func_001e8fe0(u8*, u8*);
void func_0021ec80(u8*, u8*);
void func_0021ebe8(u8*, u8*);
void func_0021ed18(u8*, u8*);
void func_0021edb0(u8*, u8*);
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
void func_001ea970(u8* base, u32 unused, u8* desc)
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
void func_001eac28(u8* base, u32 unused, u8* desc)
{
    u32* d = *(u32**)(desc + 12);
    u8* p0 = base + d[0];
    u8* p1 = base + d[1];
    u8* p2 = base + d[2];
    f32* t = (f32*)(p0 + 160);
    f32* s = (f32*)(p2 + 160);
    func_0021ec80(D_01d9e6e8.p + 16, p1 + 160);
    ScaleRow247(D_01d9e6e8.p + 16, s[0]);
    ScaleRow247(D_01d9e6e8.p + 32, s[1]);
    ScaleRow247(D_01d9e6e8.p + 48, s[2]);
    *(f32*)(D_01d9e6e8.p + 64) = t[0];
    *(f32*)(D_01d9e6e8.p + 68) = t[1];
    *(f32*)(D_01d9e6e8.p + 72) = t[2];
}
void func_001efe48(u8* base, u32 unused, u8* desc)
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

extern u8 D_0035eae8;
struct Sub6_247 { u32 a, b, c, d, e, f; };
struct Obj237 {
    u32 vt; u32 f4, f8, f12;
    u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1;
    u32 f20, f24, f28, f32, f36, f40, f44, f48, f52, f56, f60, f64, f68, f72, f76;
    Sub6_247 s;
    u32 g[14];
};
// Constructor: vtable, clear every field and seven flag bits.
void func_00237068(Obj237* o)
{
    o->s.a = 0;
    o->vt = (u32)&D_0035eae8;
    Sub6_247* s = &o->s;
    s->b = 0; s->c = 0; s->d = 0; s->e = 0; s->f = 0;
    o->f4 = 0; o->f8 = 0; o->f12 = 0;
    o->b0 = 0; o->b1 = 0; o->b2 = 0; o->b3 = 0; o->b4 = 0; o->b5 = 0; o->b6 = 0;
    o->f20 = 0; o->f24 = 0; o->f28 = 0; o->f32 = 0; o->f36 = 0; o->f40 = 0; o->f44 = 0;
    o->f52 = 0; o->f56 = 0; o->f60 = 0; o->f64 = 0; o->f68 = 0; o->f72 = 0; o->f76 = 0;
    o->g[0] = 0; o->g[1] = 0; o->g[2] = 0; o->g[3] = 0; o->g[4] = 0; o->g[5] = 0; o->g[6] = 0; o->g[7] = 0;
    o->g[8] = 0; o->g[9] = 0; o->g[10] = 0; o->g[11] = 0; o->g[12] = 0; o->g[13] = 0;
}

u32 func_002bc988(void*) asm("_Z13func_002bc988Pv");
s32 func_002bc9d8(u8*, u32);
void func_002bc9a8(u8*, s32, u32);  // find_entry12_set_field
s32 func_002bc978(void*);
void func_002bcda8(u8*, s32);
void func_002bd188(u8*, s32);
// Allocates a run of slots; on a fresh id (-1) assigns ids starting at o+328.
s32 func_002bca78(u8* o, void* a, void* b, s32* out, u32* out2)
{
    *out2 = func_002bc988(a);
    s32 r = func_002bc9d8(o, *out2);
    *out = r;
    if (r == -1) {
        s32 v = *(s32*)(o + 328);
        *out = v;
        func_002bc9a8(o, v, *out2);  // find_entry12_set_field
        s32 n = func_002bc978(b);
        for (s32 i = 0; i < n - 1; i++) {
            s32 x = *(s32*)(o + 328) + i + 1;
            func_002bcda8(o, x);
            func_002bd188(o, x);
        }
        *(s32*)(o + 328) += n;
        return 1;
    }
    return 0;
}

}
