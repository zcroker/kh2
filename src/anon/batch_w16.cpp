#include "../common/types.h"

namespace Tz {
class Select {
public:
    u8 pad[24];
    u16 f24;
    u16 f26;
    u8 pad2[9];
    u8 f37;
    u8 f38;
    void Reset2DMode();
    void SetEnableButton(u32);
    void SetSelectDisable(u32);
};
}  // namespace Tz

u32 ctarget_00185da8(u32, u32, u32, u32);
u32 wtarget_001ce2a0(u32, u32, u32, u32);
void wtarget_001d9ca0(u32, u32, u32, u32);
void wtarget_002eaab0(u32, u32, u32, u32);

extern "C" {

typedef void (*VFn)(void*);
typedef void (*VFn1)(void*, void*);
typedef u32 (*VFnR)(void*);

void func_00102818(u32, u32, u32, u32, u32);
void func_00105110(void*);
u8 func_00106420(void*);
void func_00113668(void*);
void* func_00124748(void*, u32);
s32 func_001320f0(u8*);
u32 func_00132208(u8*);
void func_001322f0(void*);
void func_0013b258(void*);
void func_0013b1d0(void*);
void func_0013d208(void*);
void func_0013b1a0(void*);
u32 func_00139d78(void*);
void func_00150678(void*);
void* func_001050c8(void*);
void func_00142940(u32, void*);
void func_001bdab0(u32);
void func_001776f8(void*);
void func_0016a2e0(void*);
u32 func_00196e88(void*, u32, u32, f32);
u8 func_001b8e88(void);
u8 func_0019c218(u8*, u32);
u8 func_001ab598(u32, void*, u32, u32, u32, u32);
u32 func_001a3a78(void*);
void func_001de168(u32, u32, u32, u32, u32, void*);
u8 func_002fd248(u32, void*, u32, u32, void*);
u32 func_001bb4a0(void);
void func_001a4e30(void*);
u8* func_001bbcb0(void);
void* func_001e3650(void);
void* func_001e3660(void*, u32);
void* func_001e4248(void*);
void* func_001e4e18(void*);
void func_001e4320(void*);
void func_00226030(u32, u32, u8*);
void func_001de750(u32);
void func_002fde18(void*, u32, u32);
u8* func_001058e8(void);
void func_0028dbf8(u32, void*, void*);
void func_002b4b00(void);
void func_00240be0(void);
void func_0028f4d8(u32, u32, u32);
void func_002908f0(void*);
u8* func_002766d0(s32);
void func_0028dac8(void*, u32);
u8 func_002e7328(void*);
u8 func_002d2a08(void*);
u8 func_003167f8(void*);
void func_003155e8(void*);
void func_0031ffc0(void*);
void func_0017c4c8(u32, void*);
void func_0016bd60(u32, u32);
void func_001d9a18(void*, s32);
u32 func_001b9bc8(u32);

extern u32 D_0032b96c;
extern u8 D_00346cd8;
extern u8 D_00347c30;
extern u8* D_01c6cb78;
extern u32* D_01d48d90;
extern u8 D_00320448;
extern u32* D_01d5ba04;
extern u8 D_00321698;
extern u8* D_0035ec98;
extern u32 D_0035ee60;
extern u8 D_00372608[8];
extern u8 D_00372610[][8];
extern u8 D_0035f4b0;
extern u32* D_01e2bd00;
extern u8 D_00324bb0;
extern u8 D_003621a0;
extern u8 D_00367848;
extern u8 D_00367818;
extern u8 D_00352878;
extern u8 D_01d5baa0;
extern u8 D_003520d0;
extern void* D_003520c0;

void func_00102c48(u32 a, u32 b, u32 c, u32 d) {
    func_00102818(D_0032b96c, a, b, c, d);
}

// Destructor body: set vtable, destroy members, chain to the base.
void func_00115090(void* p) {
    *(void**)p = &D_00346cd8;
    func_00113668(p);
    func_00105110(p);
}

u32 func_00123e00(void* a) {
    void* o = func_00124748(a, 0);
    return (*(VFnR*)(*(u8**)o + 32))(o);
}

// Skips a header (size from func_001320f0 plus 8); 0 when the rest is invalid.
u8* func_00132130(u8* p) {
    s32 off = func_001320f0(p) + 8;
    p += off;
    if (!func_00132208(p)) p = 0;
    return p;
}

void func_00132590(void* p) {
    *(void**)p = &D_00347c30;
    func_001322f0(p);
    func_00106420(p);
}

void func_0013b260(void* p) {
    func_0013b258(p);
    func_0013b1d0(p);
    func_0013d208(p);
    func_0013b1a0(p);
}

// Deactivates every 28-byte entry whose id matches.
struct Ent28 {
    u8 active;
    u8 id;
    u8 pad[26];
};
void func_00145c28(u8* p, u8 id) {
    s32 n = *(s32*)(p + 20);
    for (s32 i = 0; i < n; i++) {
        Ent28* e = (Ent28*)(i * 28 + *(u32*)(p + 8));
        if (e->id == id) e->active = 0;
    }
}

void func_0014f9a8(void* p) {
    if (func_00139d78(p)) func_00150678(p);
}

void func_0015b4c0(void* p) {
    void* o = func_001050c8(p);
    (*(VFn1*)(*(u8**)o + 4))(o, p);
}

// Passes a stack copy of a 4x4 matrix.
void func_00165830(u8* p, void* m) {
    u32 tmp[16] __attribute__((aligned(16)));
    asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                 "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                 : : "r"(tmp), "r"(m) : "$8", "$9", "$10", "$11", "memory");
    func_00142940(*(u32*)(p + 4), tmp);
}

void func_0017a230(u8* p) {
    func_001bdab0(*(u32*)(p + 2884));
    func_001776f8(p);
}

void func_00185a28(void* p) {
    (*(VFn*)(*(u8**)p + 68))(p);
    (*(VFn*)(*(u8**)p + 40))(p);
    func_0016a2e0(p);
}

struct Flags2 {
    u16 a;
    u16 on : 1;
};
static inline u8 is_on(u8* p) { return (*(Flags2**)(p + 60))->on; }
void func_001973f0(u8* p) {
    if (is_on(p)) func_00196e88(p, 6, 2, 0.0f);
    else func_00196e88(p, 6, 0, 0.0f);
}

u8 func_001a74f8(void) {
    u32 v = func_001b8e88();
    *(u8**)(D_01c6cb78 + 2480) = 0;
    return func_0019c218(D_01c6cb78, v);
}

u8 func_001aa940(u8* p, u32 a, u32 b, u32 c, u32 d) {
    return func_001ab598(*(u32*)p, p + 64, a, b, c, d);
}

void func_001b7468(void* p) {
    func_001de168(func_001a3a78(p), 16, 1, 1, 10005, p);
}

u8 func_001b8800(u32 a) {
    u32* p = D_01d48d90;
    return func_002fd248(a, p + 2, p[1], 16, &D_00320448);
}

u32 func_001bbf00(void) {
    if (!func_001bb4a0()) return 0;
    u32 v = *(u16*)(*(u8**)(func_001bbcb0() + 8) + 4);
    return (v >> 12) & 1;
}

void func_001cced8(void* p) {
    *(void**)p = &D_003520d0;
    D_003520c0 = 0;
    func_001a4e30(p);
    func_00105110(p);
}

u8 func_001d23e0(u32 a) {
    u32* p = D_01d5ba04;
    return func_002fd248(a, p + 2, p[1], 12, &D_00321698);
}

void func_001e4f00(void) {
    func_001e4320(func_001e4e18(func_001e4248(func_001e3660(func_001e3650(), 1))));
}

// 3D vector length (VU0).
f32 func_002229a0(void* v) {
    f32 r[4] __attribute__((aligned(16)));
    asm volatile("lqc2 $vf10, 0(%1)\n\tvmul.xyz $vf10, $vf10, $vf10\n\tvmove.xyz $vf9, $vf10\n\t"
                 "vaddx.y $vf9, $vf9, $vf9x\n\tvaddy.z $vf9, $vf9, $vf9y\n\tvsqrt Q, $vf9z\n\tvwaitq\n\t"
                 "vaddq.x $vf10, $vf0, Q\n\tsqc2 $vf10, %0"
                 : "=m"(r) : "r"(v));
    return r[0];
}

void func_0022e160(u32 a, u32 b, u8* c) {
    func_00226030(a, b, c);
    func_001de750(*(u32*)(c + 20));
}

// Offsets a 20-byte point: out = pos + (dx, dy).
struct Ent20 {
    s32 x, y;
    s32 ox, oy;
    u32 pad;
};
struct IdxEnt {
    u16 base;
    u16 pad;
};
void func_00237640(u8* p, s32 i, s32 j, s32 dx, s32 dy) {
    Ent20* e = *(Ent20**)(p + 8) + ((*(IdxEnt**)(p + 12))[i].base + j);
    e->ox = e->x + dx;
    e->oy = e->y + dy;
}

void func_0023f0c8(u8* p, u32 v) {
    func_00139d78(p);
    *(u32*)(p + 144) = v;
}

// Clears the current 40-byte slot.
void func_00241320(void) {
    u8* p = D_0035ec98;
    func_002fde18(p + *(s32*)(p + 4) * 40 + 8, 0, 40);
}

// Whether adding a to the counter stays within 999999.
u32 func_002424c0(u32 a) {
    return *(u32*)(func_001058e8() + 9280) + a <= 999999;
}

void func_00251e90(s32 i) {
    func_0028dbf8(D_0035ee60, D_00372608, D_00372610[i]);
}

void func_0025dba8(void) {
    func_002b4b00();
    func_00240be0();
    func_0028f4d8(0, 0x8a7f, 0);
}

void func_00290870(void* p) {
    *(void**)p = &D_0035f4b0;
    func_002908f0(p);
    func_00106420(p);
}

void func_0029e258(s32 i) {
    u8* b = func_002766d0(i);
    i++;
    func_0028dac8(b + i * 408 + 17304, 9);
}

u8 func_002c22b8(u32 a) {
    u32* p = D_01e2bd00;
    return func_002fd248(a, p + 2, p[1], 16, &D_00324bb0);
}

u8 func_002d47e8(u8* p) {
    *(void**)p = &D_003621a0;
    func_002e7328(p + 3208);
    return func_002d2a08(p);
}

u8 func_00315700(void* p) {
    *(void**)p = &D_00367848;
    func_003167f8(p);
    return func_00106420(p);
}

void func_003157b8(void* p) {
    *(void**)p = &D_00367818;
    func_003155e8(p);
    func_00106420(p);
}

void func_00320c80(void* p) {
    *(void**)p = &D_00352878;
    func_0031ffc0(p);
    func_00105110(p);
}

}  // extern "C"

// Walks to the next object whose flag 0x10 (at +1416) is set.
u32 ctarget_00185da8(u32 a0, u32, u32, u32) {
    u32 p = a0;
    while ((p = func_001b9bc8(p)) && !(*(u32*)(p + 1416) & 0x10)) {
    }
    return p;
}

// Offset table lookup: entry a1 if in range and non-zero, else entry a2.
u32 wtarget_001ce2a0(u32 a0, u32 a1, u32 a2, u32) {
    s32* t = (s32*)a0;
    if (!((s32)a1 < t[0] && t[a1 + 1] != 0)) a1 = a2;
    s32 off = t[a1 + 1];
    if (off == 0) return 0;
    return a0 + off;
}

void wtarget_001d9ca0(u32 a0, u32 a1, u32, u32) {
    if (a1 == 0xffff && a0 == 1) func_001d9a18(&D_01d5baa0, -1);
}

void wtarget_002eaab0(u32 a0, u32 a1, u32, u32) {
    u32 tmp[4] __attribute__((aligned(16)));
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(tmp), "r"(a1) : "$8", "memory");
    func_0017c4c8(a0, tmp);
    func_0016bd60(a0, 44);
}

void Tz::Select::Reset2DMode() {
    f37 = 0;
    f38 = 0;
    f24 = 0;
    f26 = 0;
    SetEnableButton(115);
    SetSelectDisable(0);
}
