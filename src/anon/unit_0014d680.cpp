#include "../common/types.h"

// Display set-up file (0x14d680-0x14e2c0): GS reset and init packet, the draw-environment and
// sprite-strip packet objects (464-byte base + zbuf/colour fields), the frame-capture
// load/store helpers on the buffer D_00457580, and the static init of the global D_00349f00
// (members at +0x2e0 and +0x2f0, flag byte at +0x4d0).
// Each function keeps the declarations of the old file it was matched in.

// sceGsResetPath is whole-body asm that links elsewhere: C++ linkage makes the call bind to
// the absolute alias _Z14sceGsResetPathv.
void sceGsResetPath();

// --- 0014d680
namespace n0014d680 {
extern "C" {
void func_002f1e18(s32, s32, s32, s32);
void func_0014d6b0();
}
void u_call0_0014d680(void) asm("_Z16u_call0_0014d680v");
void u_call0_0014d680(void) {
    sceGsResetPath();
    func_002f1e18(0, 1, 2, 0);
    func_0014d6b0();
}
}  // namespace n0014d680

// --- 0014d6b0
namespace n0014d6b0 {
struct GsPkHdr14d { u16 qwc; u8 pad2; u8 flag; u64* data; };
struct Spr14d;
void spr14d_ctor(Spr14d*, u16, u32, u16, u16, u16, u32) asm("func_0014dca8");
void spr14d_dtor(void*) asm("_Z13func_0014dd10Pv");
struct Spr14d {
    u8 pad[480];
    Spr14d(u16 a, u32 b, u16 c, u16 d, u16 e, u32 f) { spr14d_ctor(this, a, b, c, d, e, f); }
    ~Spr14d() { spr14d_dtor(this); }
};
extern "C" {
extern u64 D_0036b1a0[];
extern u64 D_0036b120[];
extern u64 D_0036b160[];
void func_0014d8d0(GsPkHdr14d*);
void sceGsSyncPath(s32, s32);
void func_0014dd60(Spr14d*, u32, u32, u32) asm("_Z13func_0014dd60jjjj");
void func_0014dda0(Spr14d*, u32) asm("_Z13func_0014dda0jjjj");
void func_0014dd18(Spr14d*) asm("_Z13func_0014dd18j");
void func_0014ddb0(Spr14d*) asm("_Z13func_0014ddb0j");

static inline __attribute__((always_inline)) void gsInit14d() {
    u64 pk[44];
    GsPkHdr14d hdr;
    pk[0] = 0x1000000000008015ULL;
    pk[1] = 0xe;
    for (s32 i = 0; i < 7; i++) {
        pk[2 + i * 2] = pk[16 + i * 2] = D_0036b1a0[i];
        pk[3 + i * 2] = D_0036b120[i];
        pk[17 + i * 2] = D_0036b160[i];
    }
    pk[30] = 1;
    pk[31] = 0x1a;
    pk[32] = 1;
    pk[33] = 0x46;
    pk[34] = 0;
    pk[35] = 0x45;
    pk[36] = 0;
    pk[37] = 0x49;
    pk[38] = -4;
    pk[39] = 0x44;
    pk[40] = 0x8000000080ULL;
    pk[41] = 0x3b;
    pk[42] = 0;
    pk[43] = 0x22;
    hdr.qwc = 0x16;
    hdr.flag = 0;
    hdr.data = pk;
    func_0014d8d0(&hdr);
    register s32 a1 asm("$5") = 0; // pinned: the original sets a1 before a0
    sceGsSyncPath(0, a1);
}
// GS init packet, then two sprite objects drawn with a path sync after each.
void func_0014d6b0(void) {
    gsInit14d();
    Spr14d a(1, 0, 512, 448, 49, 112);
    func_0014dd60(&a, 0, 0, 0);
    func_0014dda0(&a, 1);
    func_0014dd18(&a);
    func_0014ddb0(&a);
    sceGsSyncPath(0, 0);
    Spr14d b(0, 216, 512, 416, 49, 112);
    func_0014dd60(&b, 0, 0, 0);
    func_0014dda0(&b, 1);
    func_0014dd18(&b);
    func_0014ddb0(&b);
    sceGsSyncPath(0, 0);
}
}
}  // namespace n0014d6b0

// --- 0014d8a8
namespace n0014d8a8 {
u32 func_002f35e8(u32, u32, u32, u32) asm("func_002f35e8");
u32 func_0014d8a8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0014d8a8jjjj");
u32 func_0014d8a8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u;
    r4 = (u32)((s32)0u + (2));
    r2 = func_002f35e8(r4, r5, r6, r7);
    r15 = (u32)(0x0035u << 16);
    *(u32*)((u32)r15 + (s32)(-24840)) = r2;
    return r2;
}
}  // namespace n0014d8a8

// --- 0014d8d0
namespace n0014d8d0 {
extern "C" {
extern void* D_00349ef8;
void func_003058a0(u32);
void sceGsSyncPath(u32, u32);
void func_002f3918(void*, void*);
void func_0014d8d0(void* p) {
    func_003058a0(0);
    sceGsSyncPath(0, 0);
    func_002f3918(D_00349ef8, p);
}
}
}  // namespace n0014d8d0

// --- 0014d910
namespace n0014d910 {
extern "C" {
extern u32 D_00349ef8;
void sceGsSyncPath(u32, u32);
void func_002f3918(u32, u32);
void func_0014d910(u32 a) {
    sceGsSyncPath(0, 0);
    func_002f3918(D_00349ef8, a);
}
}
}  // namespace n0014d910

// --- 0014d948 (old copy built with -fno-strict-aliasing)
namespace n0014d948 {
// GS register value builders (same bit layout as the GS manual's ZBUF/FRAME/SCISSOR/XYOFFSET).
#define W2380_GS_ZBUF(zbp, psm, zmsk) ((u64)(zbp) | ((u64)(psm) << 24) | ((u64)(zmsk) << 32))
#define W2380_GS_FRAME(fbp, fbw, psm, fbmsk) \
    ((u64)(fbp) | ((u64)(fbw) << 16) | ((u64)(psm) << 24) | ((u64)(fbmsk) << 32))
#define W2380_GS_SCISSOR(x0, x1, y0, y1) \
    ((u64)(x0) | ((u64)(x1) << 16) | ((u64)(y0) << 32) | ((u64)(y1) << 48))
#define W2380_GS_XYOFFSET(ofx, ofy) ((u64)(ofx) | ((u64)(ofy) << 32))

struct W2380DmaTag {
    u16 qwc; u8 pad; u8 id; void* next;
    void Set(u16 q, void* n) { qwc = q; id = 0; next = n; }
};
struct W2380DrawEnv {
    u32 fbp; u16 w; u16 h; u16 psm; u8 pad0[6];
    W2380DmaTag tag; u8 pad1[8];
    u64 giftag[2];
    u64 zbuf, zbufReg;
    u64 frame, frameReg;
    u64 test, testReg;
    u64 alpha, alphaReg;
    u64 scissor, scissorReg;
    u64 xyoffset, xyoffsetReg;
    u8 pad2[464 - 144];
    u32 zbp; u16 zpsm;
};

extern "C" {
// Builds the draw-environment DMA packet: GIF tag (A+D, 6 regs) for ZBUF, FRAME, TEST, ALPHA,
// SCISSOR and XYOFFSET, centred on the 4096x4096 GS primitive space.
void func_0014d948(W2380DrawEnv* e)
{
    e->giftag[0] = 0x6000000000008001ULL;
    e->giftag[1] = 0xeeeeee;
    e->zbuf = W2380_GS_ZBUF(e->zbp, e->zpsm, 0);
    e->zbufReg = 0x4e;
    e->frame = W2380_GS_FRAME(e->fbp, e->w >> 6, e->psm, 0);
    e->frameReg = 0x4c;
    e->test = 0x30000;
    e->testReg = 0x47;
    e->alpha = 0x44;
    e->alphaReg = 0x42;
    e->scissor = W2380_GS_SCISSOR(0, e->w - 1, 0, e->h - 1);
    e->scissorReg = 0x40;
    e->xyoffset = W2380_GS_XYOFFSET((2048 - (e->w >> 1)) << 4, (2048 - (e->h >> 1)) << 4);
    e->xyoffsetReg = 0x18;
    e->tag.Set(7, e->giftag);
}
}
#undef W2380_GS_ZBUF
#undef W2380_GS_FRAME
#undef W2380_GS_SCISSOR
#undef W2380_GS_XYOFFSET
}  // namespace n0014d948

// --- 0014da40 (old copy built with -fno-strict-aliasing)
namespace n0014da40 {
typedef u64 u_long;
#define GIF_TAG(nloop, eop, pre, prim, flg, nreg) \
    ((u_long)(nloop) | ((u_long)(eop)<<15) | ((u_long)(pre) << 46) | \
    ((u_long)(prim)<<47) | ((u_long)(flg)<<58) | ((u_long)(nreg)<<60))
#define GS_RGBAQ(r, g, b, a, q) \
    ((u_long)(r) | ((u_long)(g) << 8) | ((u_long)(b) << 16) | \
    ((u_long)(a) << 24) | ((u_long)(q) << 32))
#define GS_XYZ(x, y, z) ((u_long)(x) | ((u_long)(y) << 16) | ((u_long)(z) << 32))
struct Pk14da40 { u16 qwc; u8 pad2; u8 id; void* addr; u8 pad8[8]; };
struct XY14da40 { u64 a; u64 b; };
struct S14da40 {
    u8 pad0[4]; u16 w; u16 h; u8 pad8[0x88];
    Pk14da40 pk; u64 tag[2]; u64 prim[2]; u64 tag2[2]; XY14da40 xy[0x10]; u8 pad1d0[6]; u8 r, g, b;
};
extern "C" {
void func_0014da40(S14da40* s) {
    int n = s->w >> 5;
    s->tag[0] = GIF_TAG(1, 0, 0, 0, 1, 2);
    s->tag[1] = 0x10;
    s->prim[0] = 6;
    s->prim[1] = GS_RGBAQ(s->r, s->g, s->b, 0x80, 1);
    s->tag2[0] = GIF_TAG(n, 1, 0, 0, 1, 2);
    s->tag2[1] = 0x55;
    u32 x = (s64)(0x800 - (s->w >> 1)) * 16;
    u32 y = (s64)(0x800 - (s->h >> 1)) * 16;
    if (n) {
        u32 xb = x + 512;
        u32 xa = x;
        S14da40* q = s;
        int c = n;
        do {
            q->xy[0].a = GS_XYZ(xa, y, 0);
            q->xy[0].b = GS_XYZ(xb, y + s->h * 16, 0);
            q = (S14da40*)((u8*)q + 16); xb += 512; xa += 512;
        } while (--c);
    }
    Pk14da40* p = &s->pk;
    p->id = 0;
    p->addr = s->tag;
    s->pk.qwc = (n * sizeof(XY14da40) + 0x30) >> 4;
}
}
#undef GIF_TAG
#undef GS_RGBAQ
#undef GS_XYZ
}  // namespace n0014da40

// --- 0014db78
namespace n0014db78 {
extern "C" {
void func_001666d0(u8*, u16, u32, u16, u16);
void func_0014db78(u8* p, u16 a, u32 b, u16 c, u16 d, u16 e, u32 f) {
    func_001666d0(p, a, b, c, d);
    *(u16*)(p + 0x1d4) = e;
    *(u32*)(p + 0x1d0) = f;
}
}
}  // namespace n0014db78

// --- 0014dbc8
namespace n0014dbc8 {
extern "C" {
void func_001666a0(u8*);
void func_0014dbc8(u8* p) {
    func_001666a0(p);  // zero_fields_0_4_6_8
    *(u32*)(p + 464) = 0;
    *(u16*)(p + 468) = 0;
    p[470] = 0;
    p[471] = 0;
    p[472] = 0;
    p[473] = 0;
}
}
}  // namespace n0014dbc8

// --- 0014dc08
namespace n0014dc08 {
extern "C" {
void func_001666a0(u8*);
void func_0014dc08(u8* p) {
    func_001666a0(p);  // zero_fields_0_4_6_8
    *(s32*)(p + 464) = 0;
    *(s16*)(p + 468) = 0;
    p[470] = 0;
    p[471] = 0;
    p[472] = 0;
    p[473] = 0;
}
}
}  // namespace n0014dc08

// --- 0014dc48
namespace n0014dc48 {
extern "C" {
void func_001666f0(void*, u16, u32, u16, u16);  // obj_store_masked
void func_0014dc48(u8* p, u16 a, u32 b, u16 c, u16 d, u16 e, u32 f) {
    func_001666f0(p, a, b, c, d);  // obj_store_masked
    *(u32*)(p + 464) = f;
    *(u16*)(p + 468) = e;
    p[470] = 0;
    p[471] = 0;
    p[472] = 0;
    p[473] = 0;
}
}
}  // namespace n0014dc48

// --- 0014dca8
namespace n0014dca8 {
extern "C" {
void func_001666f0(u8*, u16, u32, u16, u16);  // obj_store_masked
void func_0014dca8(u8* p, u16 a, u32 b, u16 c, u16 d, u16 e, u32 f) {
    func_001666f0(p, a, b, c, d);  // obj_store_masked
    *(u32*)(p + 464) = f;
    *(u16*)(p + 468) = e;
    p[470] = 0;
    p[471] = 0;
    p[472] = 0;
    p[473] = 0;
}
}
}  // namespace n0014dca8

// --- 0014dd08 (gap: empty destructor copy before 0x14dd10)
namespace n0014dd08 {
void func_0014dd08(void* self) asm("func_0014dd08");
void func_0014dd08(void* self) {}
}  // namespace n0014dd08

// --- 0014dd10
namespace n0014dd10 {
void func_0014dd10(void* self) asm("_Z13func_0014dd10Pv");
void func_0014dd10(void* self) {}
}  // namespace n0014dd10

// --- 0014dd18
namespace n0014dd18 {
extern "C" u32 func_0014d948(...);
extern "C" u32 func_0014da40(...);
void func_0014dd18(u32 a0) asm("_Z13func_0014dd18j");
void func_0014dd18(u32 a0) {
    u32 s0 = a0;
    func_0014d948(a0);
    if (*(u8*)((u32)s0 + (s32)(473)) == (u8)1u) {
        func_0014da40(s0);
        return;
    }
}
}  // namespace n0014dd18

// --- 0014dd60
namespace n0014dd60 {
void func_0014dd60(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0014dd60jjjj");
void func_0014dd60(u32 a0, u32 a1, u32 a2, u32 a3) {  // store_3bytes_470
    a1 &= 0xff;
    a2 &= 0xff;
    a3 &= 0xff;
    asm volatile("" : "+r"(a1), "+r"(a2), "+r"(a3));
    *(volatile u8 *)(a0 + 470) = a1;
    *(volatile u8 *)(a0 + 472) = a3;
    *(volatile u8 *)(a0 + 471) = a2;
}
}  // namespace n0014dd60

// --- 0014dd80
namespace n0014dd80 {
extern "C" {
void func_0014dd80(u8* p, u8* a, u8* b, u8* c) {
    *a = p[470];
    *b = p[471];
    *c = p[472];
}
}
}  // namespace n0014dd80

// --- 0014dda0
namespace n0014dda0 {
void func_0014dda0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0014dda0jjjj");
void func_0014dda0(u32 a0, u32 a1, u32 a2, u32 a3) {  // store_byte_473
    (void)a2;
    (void)a3;
    u32 v = a1 & 0x00ffu;
    *(u8*)((u32)a0 + (473)) = (u8)v;
}
}  // namespace n0014dda0

// --- 0014ddb0
namespace n0014ddb0 {
void func_0014d8d0(u32) asm("func_0014d8d0");
void func_0014ddb0(u32 a0) asm("_Z13func_0014ddb0j");
void func_0014ddb0(u32 a0) {
    u32 s0 = a0;
    func_0014d8d0(a0 + 16);
    u32 p = s0 + 144;
    if (*(u8*)(s0 + 473) != 1) {
        return;
    }

    u8 b2 = *(u8*)(s0 + 472);
    u8 b0 = *(u8*)(s0 + 470);
    u8 b1 = *(u8*)(s0 + 471);
    u64 v = ((u64)b0) | (1ULL << 32);
    u64 t = (((u64)b2) << 16) | (1ULL << 31);
    v |= t;
    v |= ((u64)b1) << 8;
    *(u64*)(s0 + 184) = v;
    func_0014d8d0(p);
}
}  // namespace n0014ddb0

// --- 0014de30
namespace n0014de30 {
extern "C" {
void func_00166618(u32, u32, u32, u32, u32, u32, u32);
struct P14d { u32 pad; s16 w; u16 h; };
void func_0014de30(P14d* p, u8* q, s32 n) {
    func_00166618((u32)q, 1, (s16)(n << 5), p->w, (u32)p->h >> 1, 0, 0);
    func_00166618((u32)(q + 0x4e000), 1, (s16)(n << 5), p->w, (u32)p->h >> 1, (u32)p->h >> 1, 1);
}
}
}  // namespace n0014de30

// --- 0014dec0
namespace n0014dec0 {
extern "C" {
extern u8 D_004574d0[];
void sceGsSetDefStoreImage(u8*, s16, u32, u32, u32, u32, s16, s16);
void func_003058a0(u32);
void sceGsSyncPath(u32, u32);
void sceGsExecStoreImage(u8*, u32);
void func_0014dec0(s16* a, u32 b) {
    sceGsSetDefStoreImage(D_004574d0, (u16)a[0] << 5, (u16)a[2] >> 6, 1, 0, 0, a[2], a[3]);
    func_003058a0(0);
    sceGsSyncPath(0, 0);
    sceGsExecStoreImage(D_004574d0, b);
}
}
}  // namespace n0014dec0

// --- 0014df48 (gap: frame task callback registered by 0x14dfa8)
namespace n0014df48 {
extern u8 D_00349f00[] asm("D_00349f00");
extern u8 D_0034a3e0 asm("D_0034a3e0");
void func_0014e620(void*) asm("func_0014e620");
void func_0014e098(u32) asm("_Z13func_0014e098j");
void func_0014df48(void) asm("func_0014df48");
void func_0014df48(void) {
    func_0014e620(D_00349f00);
    if (D_0034a3e0 == 1) {
        func_0014e098(216);
    }
}
}  // namespace n0014df48

// --- 0014df88
namespace n0014df88 {
extern u8 D_0034a3e0 asm("D_0034a3e0");
void func_0014df88(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0014df88jjjj");
void func_0014df88(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = (u32)((s32)1);
    *(u8*)&D_0034a3e0 = (u8)v;
}
}  // namespace n0014df88

// --- 0014df98
namespace n0014df98 {
void func_0014df98(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0014df98jjjj");
void func_0014df98(u32 a0, u32 a1, u32 a2, u32 a3) {  // zero_global_byte
    u32 b = (0x0035u << 16);
    *(u8*)((u32)b + (-23584)) = (u8)0;
}
}  // namespace n0014df98

// --- 0014dfa8
namespace n0014dfa8 {
extern "C" {
void* func_0014e638(void*);
void* func_0014e648(void*);  // ptr_add752
void func_00166968(void*, s32, s32, s32, s32, s32, s32, s32);
void func_0014db78(void*, s32, s32, s32, s32, s32, s32);
void func_0014dd60(void*, s32, s32, s32) asm("_Z13func_0014dd60jjjj");  // store_3bytes_470
void func_0014dda0(void*, s32) asm("_Z13func_0014dda0jjjj");  // store_byte_473
void func_0014dd18(void*) asm("_Z13func_0014dd18j");
void func_0014e2c0(void*);
void func_00102788(u32, s32, s32, void (*)(void));
void func_0014df48(void);
extern u8 D_00349f00[];
extern u32 D_0032b91c;
}
void u_call0_0014dfa8() asm("_Z16u_call0_0014dfa8v");
void u_call0_0014dfa8() {
    void* a = func_0014e638(D_00349f00);
    void* b = func_0014e648(D_00349f00);  // ptr_add752
    func_00166968(a, 1, 1, 0, 512, 448, 0, 0);
    func_0014db78(b, 0, 216, 512, 416, 49, 112);
    func_0014dd60(b, 0, 0, 0);  // store_3bytes_470
    func_0014dda0(b, 1);  // store_byte_473
    func_0014dd18(b);
    func_0014e2c0(D_00349f00);
    func_00102788(D_0032b91c, 0, 100000, func_0014df48);
}
}  // namespace n0014dfa8

// --- 0014e088
namespace n0014e088 {
extern u8 D_00349f00 asm("D_00349f00");
u32 func_0014e088(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0014e088jjjj");
u32 func_0014e088(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    return (u32)&D_00349f00;
}
}  // namespace n0014e088

// --- 0014e098, 0014e0d8
namespace n0014e098 {
extern u8 D_00457580 asm("D_00457580");
extern u8 D_00349f00 asm("D_00349f00");
u32 func_0014de30(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_0014de30");
u32 func_0014dec0(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_0014dec0");
u32 func_0014e648(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_0014e648");  // ptr_add752
u32 func_0014e098(u32 a0) asm("_Z13func_0014e098j");
u32 func_0014e098(u32 a0) {
    u32 s0 = a0;
    u32 v0 = ((u32(*)(u32))func_0014e648)((u32)&D_00349f00);
    return ((u32(*)(u32, u32, u32))func_0014de30)(v0, (u32)&D_00457580, s0);
}

u32 func_0014e0d8(void) asm("_Z13func_0014e0d8v");
u32 func_0014e0d8(void) {
    u32 v0 = ((u32(*)(u32))func_0014e648)((u32)&D_00349f00);
    return ((u32(*)(u32, u32))func_0014dec0)(v0, (u32)&D_00457580);
}
}  // namespace n0014e098

// --- 0014e108 (gap: address of the capture buffer)
namespace n0014e108 {
extern u8 D_00457580[] asm("D_00457580");
u8* func_0014e108(void) asm("func_0014e108");
u8* func_0014e108(void) { return D_00457580; }
}  // namespace n0014e108

// --- 0014e118
namespace n0014e118 {
extern u8 D_00457580 asm("D_00457580");
u32 func_002fde18(u32, u32, u32, u32) asm("func_002fde18");
u32 func_0014e118(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0014e118jjjj");
u32 func_0014e118(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002fde18((u32)&D_00457580, 0x00000000u, 0x0009c000u, a3);
}
}  // namespace n0014e118

// --- 0014e140
namespace n0014e140 {
extern "C" {
extern u8 D_00349f00[];
void* func_0014e648(void*);  // ptr_add752
void func_0014dd60(void*, u8, u8, u8) asm("_Z13func_0014dd60jjjj");  // store_3bytes_470
void func_0014e140(u8 a, u8 b, u8 c) {
    func_0014dd60(func_0014e648(D_00349f00), a, b, c);  // store_3bytes_470
}
}
}  // namespace n0014e140

// --- 0014e198 (gap: read back the three colour bytes)
namespace n0014e198 {
extern u8 D_00349f00[] asm("D_00349f00");
void* func_0014e648(void*) asm("func_0014e648");
void func_0014dd80(void*, u8*, u8*, u8*) asm("func_0014dd80");
void func_0014e198(u8* a, u8* b, u8* c) asm("func_0014e198");
void func_0014e198(u8* a, u8* b, u8* c) {
    func_0014dd80(func_0014e648(D_00349f00), a, b, c);
}
}  // namespace n0014e198

// --- 0014e1f0 (static init, matched as a plain function)
namespace n0014e1f0 {
struct NoTail { ~NoTail() {} };
struct S349 { u8 pad[736]; u8 a[16]; u8 b[480]; u8 c; };
extern S349 D_00349f00 asm("D_00349f00");
void func_00166930(u8*) asm("func_00166930");
void func_0014dc08(u8*) asm("func_0014dc08");
void func_0014dd10(u8*) asm("_Z13func_0014dd10Pv");
void func_0014e1f0(s32 a, s32 b) asm("_Z13func_0014e1f0ii");
void func_0014e1f0(s32 a, s32 b) {
    NoTail g;
    if (b == 0xffff && a == 1) {
        S349* s = &D_00349f00;
        func_00166930(s->a);
        func_0014dc08(s->b);
        s->c = 0x80;
    }
    if (b == 0xffff && a == 0) {
        S349* s = &D_00349f00;
        func_0014dd10(s->b);
    }
}
}  // namespace n0014e1f0

// --- 0014e280, 0014e2a0 (_GLOBAL__I_ / _GLOBAL__D_ stubs as plain functions)
namespace n0014e280 {
struct BD_VALUE;
void func_0014e1f0(s32, s32) asm("_Z13func_0014e1f0ii");
void func_0014e280(BD_VALUE* bd) asm("_Z13func_0014e280P8BD_VALUE");
void func_0014e280(BD_VALUE* bd) { func_0014e1f0(1, 0xffff); }
void func_0014e2a0(BD_VALUE* bd) asm("func_0014e2a0");
void func_0014e2a0(BD_VALUE* bd) { func_0014e1f0(0, 0xffff); }
}  // namespace n0014e280
