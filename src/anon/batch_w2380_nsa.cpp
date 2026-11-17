// batch w2380 (built with -O2 -fno-strict-aliasing)
#include "../common/types.h"

struct W2380Ctx { u8 pad[0xaa4]; s32 faa4; };
struct W2380Obj { u8 pad[0x14]; u32 f14; u8 pad18[8]; s32 f20; };
struct W2380Ent { u32 f0; W2380Obj* p4; };
struct W2380Mgr { W2380Ctx* p0; s32 f4; };

extern "C" {
W2380Ent* func_0019fa08(W2380Mgr*, u32, u32);
void func_0018f028(W2380Obj*);
W2380Obj* func_001050d8(u32);
void func_001a3f08(W2380Obj*, W2380Ctx*, u32, u32, W2380Obj**, s32, u32);

// Looks up the slot for (a2, a3); if it already holds an object with the same
// key/tag it is kept, otherwise the old one is released and a new 0x2e0-byte object built.
void wtarget_0019fa58(W2380Mgr* m, u32 key, u32 a2, u32 a3, u32 tag) asm("_Z16wtarget_0019fa58jjjj");
void wtarget_0019fa58(W2380Mgr* m, u32 key, u32 a2, u32 a3, u32 tag);  // 0x0019fa58: definition moved into src/anon/unit_0019ee80.cpp
}

struct W2380Hdr { u8 kind; u8 opts; u16 pad; u16 n0; u16 n1; u16 n2; u16 n3; u8 p10[0x10]; u16 h1c; };
struct W2380Rec { u16 a; u16 n; };
struct W2380Blk {
    int a0; u32 flags; W2380Hdr* volatile hdr; int c; int d; float f; u8 p18[8]; u8 b20; u8 p21[3];
    u8* p24; u8* p28; u8* p2c; u8* p30; u8* p34;
};

extern "C" {
void func_00199b90(W2380Blk*);

// Sets up the section pointers of a block from its header: two 64-byte tables, a run of
// variable-length records (8 bytes + 12 per entry), then a 16-byte table.
void func_00199aa0(W2380Blk* b, int a, W2380Hdr* h);  // 0x00199aa0: definition moved into src/anon/unit_00199688.cpp
}

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
// 0014d948: moved to src/anon/unit_0014d680.cpp
}
