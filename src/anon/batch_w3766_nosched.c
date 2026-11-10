#include "../common/types.h"
typedef struct { u64 d0; u64 d1; } __attribute__((aligned(16))) Q;
typedef struct {
    Q giftag0;
    union { Q q; struct { u16 a, b; u16 dbp; u16 c; u64 d; } f; } bitblt;
    Q trxpos;
    Q trxreg;
    Q trxdir;
    Q giftag1;
} LoadImage;
typedef unsigned int u128 __attribute__((mode(TI)));
typedef union { u128 q; u32 w[4]; } Tag;
typedef struct {
    Tag cnt;
    u64 tag[2];
    union { Q q; struct { u16 a, b; u16 dbp; u16 c; u64 d; } f; } bitblt;
    Q giftag;
    Tag ref;
} Chunk;
typedef struct {
    LoadImage li;
    u8 pad[256 - 96];
    u32 tag, addr, pad2[2];
    Chunk c[16];
} Pkt;
void* func_0020eaf8(s32);
void* func_0020eaf8(s32);
void func_0020ebd8(s32);
void sceGsSetDefLoadImage(void*, s32, s32, s32, s32, s32, s32, s32);
void sceGsSyncPath(s32, s32);

/* Hand-written DMA tag macros: clear the quadword, then write the tag word (and the address word). */
#define DMA_TAG(T, id) do { u32 _k; asm volatile("sq $0, %0\n\tli %2, %3\n\tsw %2, %1" : "=m"((T).q), "=m"((T).w[0]), "=r"(_k) : "i"(id)); } while (0)
#define DMA_TAG2(T, id, a) do { register u32 _k asm("$15"); asm volatile("sq $0, %0\n\tli %3, %4\n\tsw %3, %1\n\tsw %5, %2" : "=m"((T).q), "=m"((T).w[0]), "=m"((T).w[1]), "=r"(_k) : "i"(id), "r"(a)); } while (0)

/* Partial asm (w3766): register pins for the chunk pointer (t6), the countdown (t5) and the dbp+4 temp (t7),
 * plus a one-instruction addiu for the first chunk so it stays in the blez delay slot. */
static inline __attribute__((always_inline)) void fill_0020e2e8(u32 addr0, u16 dbp0, LoadImage* li, s32 n)
{
    u16 dbp = dbp0;
    u32 addr = addr0;
    register Chunk* c asm("$14");
    asm("addiu %0, %1, 272" : "=r"(c) : "r"(li), "r"(addr));
    if (n > 0) { register s32 k asm("$13") = n; do {
        DMA_TAG(c->cnt, 0x10000003);
        c->tag[0] = (1UL << 60) | 0x8001;
        c->tag[1] = 14;
        c->bitblt.q = li->bitblt.q;
        c->bitblt.f.dbp = dbp;
        c->giftag = li->giftag1;
        DMA_TAG2(c->ref, 0x30000040, addr);
        { register u32 d4 asm("$15") = dbp + 4; dbp = d4; }
        addr += 1024;
        c++;
    } while (--k != 0); }
    DMA_TAG(c->cnt, 0x70000000);
}
/* Uploads up to 16 1 KB image blocks to GS memory: builds a DMA REF chain of LoadImage packets and kicks DMA channel 2. */
void func_0020e2e8(u32 addr, s32 n, u16 dbp, s32 sync)
{
    Pkt* p;
    volatile Tag* t;
    if (n > 16) return;
    p = func_0020eaf8(2048);
    sceGsSetDefLoadImage(p, (s16)dbp, 1, 0, 0, 0, 16, 16);
    t = (Tag*)&p->tag;
    asm("" : "+r"(t));
    t->w[0] = 0x30000005;
    asm volatile("");
    t->w[1] = (u32)&p->li + 0x80000000;
    asm volatile("");
    fill_0020e2e8(addr, dbp, &p->li, n);
    while (*(volatile u32*)0x1000a000 & 0x100);
    asm volatile("lui $2, 0x1000\n\tori $2, $2, 0x8000\n\tli $3, 4\n\tli $4, 0x105\n\tsw $0, 0x2020($2)\n\tsw %0, 0x2030($2)\n\tsw $4, 0x2000($2)" : : "r"((u32)&p->tag + 0x80000000) : "$2", "$3", "$4", "memory");
    if (sync) sceGsSyncPath(0, 0);
    func_0020ebd8(2048);
}
