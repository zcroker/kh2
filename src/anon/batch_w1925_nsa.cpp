#include "../common/types.h"

/* func_001a32c8 */
typedef struct W1925_It { u8 pad[2]; u8 type; u8 flags; u8 pad2[0xc]; u16 v; u16 id; } W1925_It;
typedef struct W1925_G1 { u8 pad[0x1090]; u8 cnt[0x140]; u32 bits[1]; } W1925_G1;
typedef struct W1925_G2s { u8 pad[8]; u16 slot[3]; } W1925_G2s;
typedef struct W1925_G2 { u8 pad[0x36f0]; W1925_G2s s; } W1925_G2;
extern "C" {
extern W1925_G1 D_0032e020;
extern W1925_G2 D_0032bb30;
W1925_It* func_001a80c8(s32);
void func_001a3168(s32, s32, s32);
void func_001815d0(s32);
void func_001a39c8(s32);
void func_001a38b8(W1925_It*);
void func_00181670(void);
static inline bool W1925_isf(W1925_It* it) { return it->flags & 1; }
void func_001a32c8(s32 id, s32 n)
{
    s32 had = 0;
    W1925_It* it = func_001a80c8(id);
    func_001a3168(id, 100, n);
    W1925_G1* g = &D_0032e020;
    if (W1925_isf(it)) {
        u16 k = it->id;
        u32* bits = g->bits;
        bits[k >> 5] |= 1 << (k & 0x1f);
    } else {
        had = g->cnt[it->id];
        g->cnt[it->id] += n;
    }
    if (id == 32) func_001815d0(-1);
    switch (it->type) {
    case 0: func_001a39c8(id); return;
    case 21: func_001a38b8(it); return;
    case 18:
        if (had == 0) {
            W1925_G2* g2 = &D_0032bb30;
            W1925_G2s* s = &g2->s;
            for (s32 i = 0; i < 3; i++) {
                if (s->slot[i] == 0) { s->slot[i] = it->v; break; }
            }
        }
        func_00181670();
        return;
    }
}
}

/* func_0024b210 */
struct W1925_Al { virtual void* alloc(u32, void*); };
inline void* operator new[](unsigned int sz, W1925_Al* a) { return a->alloc(sz, 0); }
extern "C" {
void func_00239700(void*);
extern u8 D_00347e60;
}
struct W1925_T {
    u32 vt; u8 p4[8]; u32 f12; u8 p16[8]; u8 sub[384];
    W1925_T() { f12 = 0; vt = (u32)&D_00347e60; func_00239700(sub); }
    ~W1925_T();
};
extern "C" {
void func_00287b18(s32, s32);
void* func_00288be8(s32);
void func_002889f0(void*, s32, s32);
void func_00288f48(void*, s32, s32, s32, s32);
void func_002b3df8(void*);
void func_0028d068(s32, s32);
u8* func_00103eb0(void);
void func_00102818(u32, s32, s32, void*, s32);
void func_0024b510(void);
typedef void* (*AllocFn)(void*, u32, void*);
extern void** D_0032ba14;
extern u8* D_00347f80;
extern void* D_0035eda8;
extern void* D_0035edac;
extern s32 D_0035edb0, D_0035edb4, D_0035edb8;
extern W1925_T* D_0035edbc;
extern void* D_0035edc0;
extern u8 D_0035edc4, D_0035edc5;
void func_0024b210(void) {
    void* o;
    func_00287b18(3, 3);
    o = func_00288be8(56);
    func_002889f0(o, 3, 1);
    D_0035eda8 = o;
    o = func_00288be8(56);
    func_002889f0(o, 2, 0);
    D_0035edac = o;
    func_00288f48(o, 64, 128, 0, 0);
    D_0035edb0 = 0;
    D_0035edb4 = 0;
    D_0035edb8 = 0;
    o = (**(AllocFn**)D_0032ba14)(D_0032ba14, 12, __builtin_return_address(0));
    func_002b3df8(o);
    D_0035edc0 = o;
    D_0035edc4 = 0;
    D_0035edbc = new (*(W1925_Al**)(D_00347f80 + 20)) W1925_T[3];
    D_0035edc5 = 0;
    func_0028d068(30026, -1);
    func_00102818(*(u32*)(func_00103eb0() + 4), 0, 2000, (void*)func_0024b510, 4096);
}
}
