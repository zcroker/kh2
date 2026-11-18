// Linked unit 0x001097e8-0x00109c30 (GS image upload; was whole asm in src/anon/asm_001097e8.s).
#include "../common/types.h"

namespace n001097e8 {
struct GifTag97e8 { u64 nloop : 15, eop : 1, pad : 48; u64 regs; };
struct ImgPkt97e8 {
    u64 tag[2];
    u64 bitbltbuf, r0;
    u64 trxpos, r1;
    u64 trxreg, r2;
    u64 trxdir, r3;
    GifTag97e8 img;
};
struct PkCtx97e8 { u32 buf; } __attribute__((aligned(16)));

ImgPkt97e8* func_001337f0(PkCtx97e8*, s32, u32) asm("func_001337f0");
void func_00108398(ImgPkt97e8*) asm("func_00108398");
void func_001337a0(PkCtx97e8*, u8*, s32, s32) asm("func_001337a0");
void func_00133848(PkCtx97e8*, s32, u32, u32) asm("func_00133848");
void func_00133898(PkCtx97e8*, s32, u32, u32) asm("func_00133898");

/*TARGET 001097e8*/
// Uploads an image to GS memory, splitting it in two transfers when it crosses a page row.
// Cases are in 32/16/8/4-bit order and the function leaves early when there is no second part
// (the two end calls are merged by cross-jumping). The empty asm on the tag count keeps one
// scheduling slot between the count's conversion and the call arguments: without it the
// scheduler moves the data argument one packet store early.
void func_001097e8(u32 buf, u32 dbp, u32 dbw, u32 dsax, u32 dsay, u32 w, u32 h, u32 psm, u8* data) asm("func_001097e8");
void func_001097e8(u32 buf, u32 dbp, u32 dbw, u32 dsax, u32 dsay, u32 w, u32 h, u32 psm, u8* data)
{
    PkCtx97e8 pk;
    u32 dbp2 = dbp;
    u32 qwc = 0;
    u32 h2 = 0;
    u8* data2 = 0;
    u32 qwc2 = 0;
    ImgPkt97e8* g;

    switch (psm) {
    case 0: case 1: case 27: case 36: case 44: case 48: case 49:
        while (dsay >= 32) {
            dsay -= 32;
            dbp += dbw * 32;
        }
        if (dsay + h > 32) {
            h2 = dsay + h - 32;
            h -= h2;
            dbp2 = dbp + dbw * 32;
            data2 = data + w * h * 4;
            qwc2 = w * h2 / 4;
        }
        qwc = w * h / 4;
        break;
    case 2: case 10: case 50: case 58:
        while (dsay >= 64) {
            dsay -= 64;
            dbp += dbw * 32;
        }
        if (dsay + h > 64) {
            h2 = dsay + h - 64;
            h -= h2;
            dbp2 = dbp + dbw * 32;
            data2 = data + w * h * 2;
            qwc2 = w * h2 / 8;
        }
        qwc = w * h / 8;
        break;
    case 19:
        while (dsay >= 64) {
            dsay -= 64;
            dbp += (dbw + 1) / 2 * 32;
        }
        if (dsay + h > 64) {
            h2 = dsay + h - 64;
            h -= h2;
            dbp2 = dbp + (dbw + 1) / 2 * 32;
            data2 = data + w * h;
            qwc2 = w * h2 / 16;
        }
        qwc = w * h / 16;
        break;
    case 20:
        while (dsay >= 128) {
            dsay -= 128;
            dbp += (dbw + 1) / 2 * 32;
        }
        if (dsay + h > 128) {
            h2 = dsay + h - 128;
            h -= h2;
            dbp2 = dbp + (dbw + 1) / 2 * 32;
            data2 = data + w * h / 2;
            qwc2 = w * h2 / 32;
        }
        qwc = w * h / 32;
        break;
    }
    pk.buf = buf;
    g = func_001337f0(&pk, 6, 0x13000000);
    func_00108398(g);
    g->bitbltbuf = ((u64)dbp << 32) | ((u64)dbw << 48) | ((u64)psm << 56);
    g->trxpos = ((u64)dsax << 32) | ((u64)dsay << 48);
    g->trxreg = (u64)w | ((u64)h << 32);
    g->img.nloop = qwc;
    {
        s32 n = g->img.nloop;
        asm("" : "+r"(n));
        func_001337a0(&pk, data, n, 0);
    }
    if (!data2) {
        func_00133898(&pk, 0, 0x11000000, 0x13000000);
        return;
    }
    func_00133848(&pk, 0, 0x11000000, 0x13000000);
    g = func_001337f0(&pk, 6, 0x13000000);
    func_00108398(g);
    g->bitbltbuf = ((u64)dbp2 << 32) | ((u64)dbw << 48) | ((u64)psm << 56);
    g->trxpos = (u64)dsax << 32;
    g->trxreg = (u64)w | ((u64)h2 << 32);
    g->img.nloop = qwc2;
    {
        s32 n = g->img.nloop;
        asm("" : "+r"(n));
        func_001337a0(&pk, data2, n, 0);
    }
    func_00133898(&pk, 0, 0x11000000, 0x13000000);
}
}  // namespace n001097e8
