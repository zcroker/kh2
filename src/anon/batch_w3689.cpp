#include "../common/types.h"
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
void func_0014dd60(Spr14d*, u32, u32, u32);
void func_0014dda0(Spr14d*, u32);
void func_0014dd18(Spr14d*);
void func_0014ddb0(Spr14d*);

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
extern "C" {
s32 func_00103570();
void* func_001063c0(s32, s32);
void func_002fde18(void*, s32, s32);
void func_00239700(void*);
struct Heap2a4c;
struct Heap2a4cVt { void* (*alloc)(Heap2a4c*, s32, s32); };
struct Heap2a4c { Heap2a4cVt* vt; };
struct Sys2a4c { u8 pad[20]; Heap2a4c* heap; };
extern Sys2a4c* D_00347f80;
extern u8 D_00347e60[];
extern u8 D_00347e40[];
extern void* D_0035f5ec;
extern void* D_0035f5f0;
struct Obj2a4c {
    void* vt; s32 f4, f8, f12; u8 pad[8]; u8 m24[384]; s32 f408; u8 pad2[24];
};

// Allocates a 192-byte buffer, then a counted array of 10 objects (new[] with an
// inlined constructor: base vtable, member init, derived vtable).
void func_002a4c68(void) {
    s32 n;
    register s32 end asm("$20"); // pinned: keeps li 9 / li -1 where the original has them
    void* v60;
    void* v40;
    Obj2a4c* q;
    void* p = func_001063c0(192, func_00103570());
    D_0035f5ec = p;
    func_002fde18(p, 0, 192);
    Heap2a4c* h = D_00347f80->heap;
    s32* c = (s32*)h->vt->alloc(h, 4364, 0);
    c[0] = 10;
    Obj2a4c* a = (Obj2a4c*)(c + 1);
    end = -1;
    n = 9;
    v60 = D_00347e60;
    v40 = D_00347e40;
    q = a;
    while (n != end) {
        q->f12 = 0;
        q->vt = v60;
        func_00239700(q->m24);
        q->vt = v40;
        q->f408 = 0;
        n--;
        q++;
    }
    D_0035f5f0 = a;
}
}
