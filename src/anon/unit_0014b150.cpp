#include "../common/types.h"

// dk::RectParamBase and the filled rectangle (0x14b150-0x14b518): the rectangle parameter
// constructor (both clones), its setters and getters, the filled rectangle constructor and its GS
// packet, and two UV helpers. The vtables (0x348698, 0x349b40) stay retail data. Each function
// keeps the declarations of the source it was matched in (namespace kN). The rest of the file:
// 0x14b518 (UV swap, matched as C, stays a separate function) and src/harata/libdk/rect.cpp.

// 14b150, 14b198: RectParamBase constructor (C1 and C2 clones; the second was never written)
namespace k0 {
struct Obj_0014b150 { u32 p; u16 h4; u16 h6; u16 h8; u16 h10; u32 w12; s8 b16, b17, b18, b19; };
extern u8 D_00348698 asm("D_00348698");
void func_0014b150(u32 a0) asm("func_0014b150");
void func_0014b150(u32 a0) {  // obj_init_fields_14b150
    Obj_0014b150* s = (Obj_0014b150*)a0;
    s->h8 = 0;
    s->h10 = 0;
    s->p = (u32)&D_00348698;
    s->h4 = 512;
    s8 n = -128;
    u16 k = 416;
    u32 one = 1;
    s->b16 = n;
    s->h6 = k;
    s->w12 = one;
    s->b17 = n;
    s->b18 = n;
    s->b19 = n;
}
void func_0014b198(u32 a0) asm("func_0014b198");
void func_0014b198(u32 a0) {
    Obj_0014b150* s = (Obj_0014b150*)a0;
    s->h8 = 0;
    s->h10 = 0;
    s->p = (u32)&D_00348698;
    s->h4 = 512;
    s8 n = -128;
    u16 k = 416;
    u32 one = 1;
    s->b16 = n;
    s->h6 = k;
    s->w12 = one;
    s->b17 = n;
    s->b18 = n;
    s->b19 = n;
}
}  // namespace k0

// 14b1e0 .. 14b258: RectParamBase setters
namespace dk {
struct RectParamBaseLayout { char _pad0[8]; s16 x; s16 y; u32 z; };
class RectParamBase {
public:
    void setXY(s16 x, s16 y);
    void setZ(u32 v);
};
void RectParamBase::setXY(s16 x, s16 y) {
    reinterpret_cast<RectParamBaseLayout*>(this)->x = x;
    reinterpret_cast<RectParamBaseLayout*>(this)->y = y;
}
void RectParamBase::setZ(u32 v) { reinterpret_cast<RectParamBaseLayout*>(this)->z = v; }
}  // namespace dk

namespace k1 {
void func_0014b208(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2dk13RectParamBase14setWidthHeightEtt");
void func_0014b208(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3;
    r5 = (u32)(r5 & 0xffffu);
    r6 = (u32)(r6 & 0xffffu);
    *(u16*)((u32)r4 + (s32)(4)) = (u16)r5;
    *(u16*)((u32)r4 + (s32)(6)) = (u16)r6;
}

void dk_RectParamBase_setColor(u32, u32, u32, u32, u32) asm("_ZN2dk13RectParamBase8setColorEhhhh");
void dk_RectParamBase_setColor(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0) {
    a1 &= 0xff;
    a2 &= 0xff;
    a3 &= 0xff;
    asm volatile("" : "+r"(a1), "+r"(a2), "+r"(a3));
    *(volatile u8 *)(a0 + 16) = a1;
    t0 &= 0xff;
    *(volatile u8 *)(a0 + 17) = a2;
    *(volatile u8 *)(a0 + 19) = t0;
    *(volatile u8 *)(a0 + 18) = a3;
}

void func_0014b248(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2dk13RectParamBase8setAlphaEh");
void func_0014b248(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a2;
    (void)a3;
    u32 v = a1 & 0x00ffu;
    *(u8*)((u32)a0 + (19)) = (u8)v;
}

void func_0014b258(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0014b258");
void func_0014b258(u32 a0, u32 a1, u32 a2, u32 a3) {  // copy_halfwords_8_10
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14 = 0u, r15 = 0u;
    r14 = (u32)(*(u16*)((u32)r4 + (s32)(8)));
    *(u16*)((u32)r5 + (s32)(0)) = (u16)r14;
    r15 = (u32)(*(u16*)((u32)r4 + (s32)(10)));
    *(u16*)((u32)r6 + (s32)(0)) = (u16)r15;
}

// 14b270, 14b288 (never written before): width/height and alpha getters
void func_0014b270(u32 a0, u16* w, u16* h) asm("func_0014b270");
void func_0014b270(u32 a0, u16* w, u16* h) {
    *w = *(u16*)(a0 + 4);
    *h = *(u16*)(a0 + 6);
}

u8 func_0014b288(u32 a0) asm("func_0014b288");
u8 func_0014b288(u32 a0) { return *(u8*)(a0 + 19); }
}  // namespace k1

// 14b290, 14b2c8: filled rectangle constructor (C1, C2)
namespace k2 {
void func_0014b150(void*) asm("func_0014b150");
void func_0014b300(void*) asm("func_0014b300");
extern u8 D_00349b40[] asm("D_00349b40");
void ctarget_0014b290(u32* self, u32, u32, u32) asm("_Z16ctarget_0014b290jjjj");
void ctarget_0014b290(u32* self, u32, u32, u32) {
    func_0014b150(self);
    *self = (u32)D_00349b40;
    func_0014b300(self);
}
void func_0014b2c8(u32* self) asm("func_0014b2c8");
void func_0014b2c8(u32* self) {
    func_0014b150(self);
    *self = (u32)D_00349b40;
    func_0014b300(self);
}
}  // namespace k2

// 14b300: the rectangle's GS packet
namespace k3 {
#define RGBAQ(r, g, b, a, q) ((u64)(r) | ((u64)(g) << 8) | ((u64)(b) << 16) | ((u64)(a) << 24) | ((u64)(q) << 32))
#define XYZ(x, y, z) ((u64)(x) | ((u64)(y) << 16) | ((u64)(z) << 32))
struct Rect14b { u8 pad0[4]; u16 w; u16 h; s16 x; s16 y; u8 pad1[4]; u8 r, g, b, a; u8 pad2[12]; u64 pk[26]; };
void func_0014b300(Rect14b* p) asm("func_0014b300");
void func_0014b300(Rect14b* p) {
    p->pk[0] = 0x8000000000000001ULL;
    p->pk[1] = 0xEEEEEEEEULL;
    p->pk[2] = 0;
    p->pk[3] = 0x3f;
    p->pk[4] = 0x800d8;
    p->pk[5] = 0x4c;
    p->pk[6] = 0x31000070;
    p->pk[7] = 0x4e;
    p->pk[8] = 0;
    p->pk[9] = 6;
    p->pk[10] = 0x60;
    p->pk[11] = 0x14;
    p->pk[12] = 0x30000;
    p->pk[13] = 0x47;
    p->pk[14] = 0x44;
    p->pk[15] = 0x42;
    p->pk[16] = 5;
    p->pk[17] = 8;
    p->pk[18] = 0x6400000000008001ULL;
    p->pk[19] = 0x535310;
    p->pk[20] = 0x146;
    p->pk[21] = RGBAQ(p->r, p->g, p->b, p->a, 1);
    p->pk[22] = 0x80008;
    p->pk[23] = XYZ(p->x * 16 + 0x7000, p->y * 16 + 0x7300, 1);
    p->pk[24] = 0x80008;
    p->pk[25] = XYZ((p->x + p->w) * 16 + 0x7000, (p->y + p->h) * 16 + 0x7300, 1);
}
#undef RGBAQ
#undef XYZ
}  // namespace k3

// 14b468, 14b4b0: UV helpers
namespace k4 {
void func_0014b5e8(u32, u32, u64) asm("_ZN2dk8RectBase7setGsUVEyy");
void func_0014b468(u32 a, u16 x, u16 y) asm("func_0014b468");
void func_0014b468(u32 a, u16 x, u16 y) {
    func_0014b5e8(a, 0x80008, (u64)(s32)(x * 16 + 8) | ((u64)(s32)(y * 16 + 8) << 16));
}
}  // namespace k4
namespace k5 {
void func_0014b5e8(u32, u64, u64) asm("_ZN2dk8RectBase7setGsUVEyy");
void func_0014b4b0(u32 a, u16 x0, u16 y0, u16 x1, u16 y1) asm("func_0014b4b0");
void func_0014b4b0(u32 a, u16 x0, u16 y0, u16 x1, u16 y1) {
    func_0014b5e8(a, (u64)(s32)(x0 * 16 + 8) | ((u64)(s32)(x1 * 16 + 8) << 16),
                     (u64)(s32)(y0 * 16 + 8) | ((u64)(s32)(y1 * 16 + 8) << 16));
}
}  // namespace k5

