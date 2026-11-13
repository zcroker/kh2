#include "../common/types.h"

// Built with -fno-strict-aliasing (_nsa): only then does the flag-word update schedule like the original.

// Progress-flag script record: opcode, argument count, then the arguments.
struct W3721FlagCmd {
    u8 op;
    u8 n;
    u16 arg[1];
};
// Script table: halfword offsets of each flag's record (shares the flag words' alias set).
union W3721FlagTbl {
    u16 off[1];
    u32 w;
};
// 6-byte per-world entry handed to func_00104cf0 by opcode 1.
struct W3721WorldEnt {
    u16 v[3];
};

extern "C" {
extern u32 D_0032d7c0[][8];          // progress flag bits, 32 bytes per world
extern W3721FlagTbl* D_0034ec70[];   // per-world flag script tables
extern W3721WorldEnt D_0032bb40[][64];

s32 W3721_CheckFlag(s32) asm("_ZN2YS8PROGRESS9CheckFlagEi");
void W3721_SetFlag(s32) asm("_ZN2YS8PROGRESS7SetFlagEi");
void W3721_MenuFlagReset(s32) asm("_ZN2YS8MENUFLAG5ResetEi");
void W3721_ColosseumCheck(void) asm("_ZN2YS12HE_COLOSSEUM5CheckEv");
void func_00104cf0(W3721WorldEnt*, u16*);
void func_00196670(u32, u32, u32);
void func_00196698(u32);
void func_001966b0(u32);
void func_00196710(u32);
void func_001a9140(s32, u32);
void func_001814b8(u32);
void func_001a6c90(u32);
u8* func_001b6d70(s32);
void func_001815d0(s32);
void func_00181670(void);
void func_001817f0(s32);
void func_00181778(void);
void func_001d59b0(void);
void func_001d5218(s32);
void func_001b8ce0(s32);
void func_001c0ba0(s32);
void func_0019ef30(void);
void func_00196540(s32);
// Sets progress flag `flag` (world = flag >> 10) and runs the flag's script.
// 00181178: moved to src/yasui/libys/progress.cpp
}
typedef unsigned int W3721bu128 __attribute__((mode(TI)));
struct W3721bTex { u8 pad[3]; u8 vis; };
struct W3721bPart { u32 w0; u8 pad[28]; };
struct W3721bMdl { u8 pad[28]; s32 count; W3721bPart parts[1]; };
struct W3721bObj { u8 pad[4]; W3721bMdl* mdl; };
struct W3721bDesc { u8 pad[4]; u8 r, g, b, a; };
// 64-byte matrix, copied with 128-bit loads/stores (hand-written asm in the original's operator=).
struct W3721bMtx {
    W3721bu128 row[4];
    W3721bMtx& operator=(const W3721bMtx& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W3721bHdr {
    W3721bu128 tag;      // 0
    u8 pad[40];
    f32 depth;          // 56
    u8 pad1[20];
    W3721bMtx mtx;       // 80
};
extern "C" {
extern W3721bu128 D_00347a10;
s32 func_0010ae90(void);
W3721bMdl* func_00120800(W3721bObj*);
W3721bTex* func_00108930(W3721bDesc*, s32);
s32 func_001344f8(void);
void func_00109360(s32, s32);
W3721bHdr* func_00108730(W3721bDesc*, s32);
void func_00133bb8(s32, s32, u32, u32);
void func_00108f98(s32, u64);
void func_00109008(s32);
void func_00133c60(s32, s32, s32, s32, s32);

// Needs -fno-strict-aliasing (_nsa). Register pin (w3721): in three of the four part loops the texture
// pointer is pinned to t5 ($13); without it gcc swaps t5/t6 for the pointer and its vis byte (closest C: 8 diffs).
// Draws the visible parts of an object's model (or of its sub-model) with a per-part mask.
s32 func_00123228(W3721bObj* o, W3721bMtx* mtx, s32* ids, W3721bDesc* d, u8* mask)
{
    W3721bTex* tex[32];
    s32 pk = func_0010ae90();
    W3721bMdl* mdl = o->mdl;
    W3721bMdl* m2 = func_00120800(o);
    s32 n = 0;
    s32 i;
    for (i = 0; i < 32; i++) tex[i] = func_00108930(d, i);
    if (m2) {
        for (i = 0; i < m2->count; i++) {
            u8 f = mask[mdl->count + i] & 0xf;
            if (f && !(f & 4)) {
                register W3721bTex* tp asm("$13") = tex[m2->parts[i].w0 & 0x1f];
                if (tp->vis) n++;
            }
        }
        if (n) {
            s32 g = func_001344f8();
            func_00109360(g, 3);
            W3721bHdr* h = func_00108730(d, g);
            h->tag = D_00347a10;
            h->mtx = *mtx;
            for (i = 0; i < m2->count; i++) {
                u8 f = mask[mdl->count + i] & 0xf;
                if (f && !(f & 4) && tex[m2->parts[i].w0 & 0x1f]->vis) {
                    func_00133bb8(g, 0, 0x11000000, 0x13000000);
                    func_00108f98(pk, (u64)d->r | ((u64)d->g << 8) | ((u64)d->b << 16) | ((u64)d->a << 24) | (127ULL << 55));
                    func_00109008(pk);
                    func_00133c60(g, ids[mdl->count + i], 0, 0, 0);
                }
            }
        }
    } else {
        for (i = 0; i < mdl->count; i++) {
            u8 f = mask[i] & 0xf;
            if (f && !(f & 4)) {
                register W3721bTex* tp asm("$13") = tex[(mdl->parts[i].w0 >> 6) & 0x1f];
                if (tp->vis) n++;
            }
        }
        if (n) {
            s32 g = func_001344f8();
            func_00109360(g, 2);
            W3721bHdr* h = func_00108730(d, g);
            h->mtx = *mtx;
            h->depth = 100000000.0f;
            for (i = 0; i < mdl->count; i++) {
                u8 f = mask[i] & 0xf;
                if (f && !(f & 4)) {
                    register W3721bTex* tp asm("$13") = tex[(mdl->parts[i].w0 >> 6) & 0x1f];
                    if (tp->vis) {
                        func_00133bb8(g, 0, 0x11000000, 0x13000000);
                        func_00108f98(pk, (u64)d->r | ((u64)d->g << 8) | ((u64)d->b << 16) | ((u64)d->a << 24) | (127ULL << 55));
                        func_00109008(pk);
                        func_00133c60(g, ids[i], 0, 0, 0);
                    }
                }
            }
        }
    }
    return 1;
}
}
