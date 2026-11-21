// Linked unit 0x0020e490-0x0020e758: texture/CLUT upload wrappers and the GS clear packet builder.
#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));
typedef unsigned int w3728_u128 __attribute__((mode(TI)));
#include "tiny_auto80_solver_structs.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// 0020e490 (was src/anon/batch_w1791.cpp)
namespace n0020e490 {
// 0x001d22e0: definition moved into src/anon/unit_001d14e0.cpp

void puts(const char*) asm("puts");
void func_002fd348(s32)  asm("func_002fd348")__attribute__((noreturn));
extern char D_00370720[] asm("D_00370720");
void sceGsSetDefLoadImage(void*, s32, s32, s32, s32, s32, s32, s32) asm("sceGsSetDefLoadImage");
void sceGsSyncPath(s32, s32) asm("sceGsSyncPath");
void func_003058a0(s32) asm("func_003058a0");
void sceGsExecLoadImage(void*, u32) asm("sceGsExecLoadImage");
struct Tex {
    u16 w : 14;
    u16 pad0 : 2;
    u8 pad2[6];
    u8 b8;
    u8 b9;
    u8 b10;
    u8 pad11;
    s16 h12;
    s16 h14;
    u8 pad16[4];
    u32 data;
    u8 b24;
};
/*TARGET 0020e490*/
void func_0020e490(Tex* t, u32 flag) asm("func_0020e490");
void func_0020e490(Tex* t, u32 flag) {
    u8 buf[96];
    if (!t->data) {
        puts(D_00370720);
        func_002fd348(1);
    }
    sceGsSetDefLoadImage(buf, (s16)t->w, t->b10 >> 2, t->b24, t->b8 << 4, t->b9 << 4, t->h12, t->h14);
    sceGsSyncPath(0, 0);
    func_003058a0(0);
    sceGsExecLoadImage(buf, t->data);
    if (flag) sceGsSyncPath(0, 0);
}
}  // namespace n0020e490

// 0020e548 (was src/anon/batch_w52.cpp)
namespace n0020e548 {
// 0x001dc558: definition moved into src/anon/unit_001dbfd8.cpp

void puts(const char*) asm("puts");
void func_002fd348(s32)  asm("func_002fd348")__attribute__((noreturn));
extern char D_00370748[] asm("D_00370748");
void func_0020e2e8(u32, u8, u16, u32) asm("func_0020e2e8");
/*TARGET 0020e548*/
void func_0020e548(u8* p, u32 b) asm("func_0020e548");
void func_0020e548(u8* p, u32 b) {
    if (!*(u32*)(p + 4)) {
        puts(D_00370748);
        func_002fd348(1);
    }
    func_0020e2e8(*(u32*)(p + 4), p[9], *(u16*)p, b);
}
}  // namespace n0020e548


// 0020e590 (was whole asm, src/anon/asm_0020e590.s)
namespace n0020e590 {
void* func_0020eaf8(s32) asm("func_0020eaf8");
void func_0020ebd8(s32) asm("func_0020ebd8");
void sceGsSetDefLoadImage(void*, s32, s32, s32, s32, s32, s32, s32) asm("sceGsSetDefLoadImage");
void sceGsSyncPath(s32, s32) asm("sceGsSyncPath");
extern u128 D_00370770 asm("D_00370770");

struct Q { u64 d0; u64 d1; } __attribute__((aligned(16)));
union Bitblt { Q q; struct { u16 sbp, sbw; u16 dbp; u16 dbw; u64 addr; } f; };
struct LoadImage {
    Q giftag0;
    Bitblt bitblt;
    Q trxpos;
    Q trxreg;
    Q trxdir;
    Q giftag1;
};
union Tag { u128 q; u32 w[4]; };
struct Chunk {
    Tag cnt;        // DMA cnt tag, 4 qwords follow
    u64 tag[2];     // GIF tag: A+D, 1 register
    Bitblt bitblt;
    Q trxdir;
    Q giftag;       // image GIF tag
    Tag ref;        // DMA ref tag to the fill data
};
struct Pkt {
    LoadImage li;
    u8 pad[256 - 96];
    Tag tag;        // head tag: ref to li
    Chunk c[8];
    Tag end;
    u8 pad2[2048 - 1056];
    u128 data[64];
};

// Every scalar store to the packet goes through one of these (each is a scheduling barrier).
#define ZQ(m) asm volatile("sq $0, %0" : : "m"(m) : "memory")
#define SW(m, v) asm volatile("sw %1, %0" : : "m"(m), "r"(v) : "memory")
#define SH(m, v) asm volatile("sh %1, %0" : : "m"(m), "r"(v) : "memory")

/*TARGET 0020e590*/
void func_0020e590(u32 a, s32 size) asm("func_0020e590");
void func_0020e590(u32 a, s32 size) {
    Pkt* p = (Pkt*)func_0020eaf8(3072);
    u16 dbp = a;
    sceGsSetDefLoadImage(p, (s16)dbp, 1, 0, 0, 0, 16, 16);
    u32 buf = (u32)p->data + 0x80000000;
    Chunk* c = (Chunk*)&p->tag;
    u32 v = 0x30000005;
    SW(c->cnt.w[0], v);
    SW(c->cnt.w[1], (u32)p + 0x80000000);
    u128 z = D_00370770;
    s32 i;
    for (i = 0; i < 1024; i += 16) *(u128*)((buf & 0x7fffffff) + i) = z;
    s32 n = size / 32;
    u32 tag = (u32)p + 0x80000100;
    for (s32 j = 0;; j++) {
        if (j >= n) {
            sceGsSyncPath(0, 0);
            func_0020ebd8(3072);
            return;
        }
        sceGsSyncPath(0, 0);
        c = p->c;
        for (i = 0; i < 8; i++) {
            ZQ(c->cnt.q);
            v = 0x10000004;
            SW(c->cnt.w[0], v);
            c->tag[0] = (1UL << 61) | 1;
            c->tag[1] = 0xeeee;
            c->bitblt.q = p->li.bitblt.q;
            c->trxdir = p->li.trxdir;
            SH(c->bitblt.f.dbp, dbp);
            c->giftag = p->li.giftag1;
            ZQ(c->ref.q);
            v = 0x30000040;
            SW(c->ref.w[0], v);
            SW(c->ref.w[1], buf);
            dbp += 4;
            c++;
        }
        ZQ(c->cnt.q);
        v = 0x70000000;
        SW(c->cnt.w[0], v);
        // start the GIF channel (D2) in chain mode on the head tag
        asm volatile("lui $2, 0x1000\n\tori $2, $2, 0x8000\n\tli $3, 4\n\tli $4, 0x105\n\tsw $0, 0x2020($2)\n\tsw %0, 0x2030($2)\n\tsw $4, 0x2000($2)" : : "r"(tag) : "$2", "$3", "$4", "memory");
    }
}
}  // namespace n0020e590
