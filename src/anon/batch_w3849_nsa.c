// partMng.c, built without strict aliasing (_nsa). Plain C; asm: the assert trap "break", and in
// 001e4320 one empty register tie on the prim pointer (it gives p s0 and the count s1, as in the original).
// 001e5a00: find or allocate VRAM-cache blocks for a part (pchDpd, nParId): reuse an entry already
// holding pchDpd, else take a free run of nBlock blocks, else the closest larger entry, else evict.
#include "../common/types.h"
typedef struct { char* pchDpd; u32 pad4; u64 mask; s8 chBlockStart; s8 chBlockNum; u8 used; u8 pad[5]; } VCache;
typedef struct { u8 pad[136]; char* pchDpd; u8 pad2[7]; u8 nParId; } ParInfo;
typedef struct { u8 r, g, b, a; } RGBA;
typedef struct { u8 pad0; s8 type; s16 count; u8 pad4[12]; } PartPrim;
extern char D_0036e978[];
extern char D_0036e998[];
extern char D_0036e9d0[];
extern char D_0036ea98[];
extern char D_0036ee10[];
extern char D_0036ee28[];
extern char D_0036ee38[];
extern char D_0036ee58[];
extern char D_0036ee80[];
extern char D_0036ee98[];
extern char D_0036eaa0[];
extern char D_0036ed10[];
void func_002fdfc8(const char*, ...);
void func_001e2ad8(const char*, const char*, s32, const char*);
void func_001e5970(VCache*);
static inline void ryj001e5a00(const char* e, const char* f, u32 l)
{
    func_002fdfc8(D_0036e978, e);
    func_002fdfc8(D_0036e998, f, l);
    asm volatile("break"); /* assert trap: hand-written break */
}
#define ASSERT(c, s, line) if (!(c)) ryj001e5a00(s, D_0036e9d0, line)
#define BLOCK_MAX 40
/* Grey a vertex colour: r = g = b = 0.3 r + 0.59 g + 0.11 b. */
#define MONO(c) { fGray = (c).r * 0.3f + (c).g * 0.59f + (c).b * 0.11f; { s32 m = (s32)fGray; (c).r = m; (c).g = m; (c).b = m; } }
#define LOOP3(sz) nSize = sz; for (j = 0; j < nNum; j++) { f32 fGray; MONO(((RGBA*)v)[0]); MONO(((RGBA*)v)[1]); MONO(((RGBA*)v)[2]); v += sz; } break;
#define LOOP4(sz) nSize = sz; for (j = 0; j < nNum; j++) { f32 fGray; MONO(((RGBA*)v)[0]); MONO(((RGBA*)v)[1]); MONO(((RGBA*)v)[2]); MONO(((RGBA*)v)[3]); v += sz; } break;
s32 func_001e5a00(VCache* pVcache, s32 nBlockMax, ParInfo* pPar, u8 nBlock)
{
    const s32 nMax = BLOCK_MAX;
    u8 abUse[nMax];
    char* pchDpd = pPar->pchDpd;
    s32 nParId = pPar->nParId;
    s32 i, j, nCnt, nStartBlock, nBest;
    VCache* pBest;
    VCache* pV;
    VCache* pE;
    VCache* pB;
    ASSERT(nBlockMax <= BLOCK_MAX, D_0036ee10, 1765);
    ASSERT(0 != pchDpd, D_0036ee28, 1766);
    ASSERT(0 <= nParId && nParId < 64, D_0036ee38, 1767);
    for (i = 0; i < nBlockMax; i++) {
        if (pVcache[i].used && pchDpd == pVcache[i].pchDpd) {
            if ((pVcache[i].mask >> nParId) & 1) return -1;
            pVcache[i].mask |= (u64)1 << nParId;
            return pVcache[i].chBlockStart;
        }
    }
    for (i = 0; i < BLOCK_MAX; i++) abUse[i] = 0;
    for (i = 0; i < nBlockMax; i++) {
        pV = &pVcache[i];
        if (pV->used) {
            for (j = 0; j < pV->chBlockNum; j++) {
                ASSERT((pV->chBlockStart + j) < BLOCK_MAX, D_0036ee58, 1795);
                abUse[pV->chBlockStart + j] = 1;
            }
        }
    }
    nCnt = 0;
    nStartBlock = -1;
    for (i = 0; i < nBlockMax; i++) {
        if (abUse[i]) {
            nCnt = 0;
        } else {
            nCnt++;
            if (nCnt == nBlock) {
                nStartBlock = i - nBlock + 1;
                ASSERT(0 <= nStartBlock, D_0036ee98, 1812);
                break;
            }
        }
    }
    pBest = 0;
    if (nStartBlock > 0) {
        for (i = 0; i < nBlockMax; i++) {
            if (!pVcache[i].used) {
                pVcache[i].used = 1;
                pVcache[i].pchDpd = pchDpd;
                pVcache[i].mask = (u64)1 << nParId;
                pVcache[i].chBlockNum = nBlock;
                pVcache[i].chBlockStart = nStartBlock;
                return nStartBlock;
            }
        }
        func_001e2ad8(D_0036ea98, D_0036e9d0, 1835, D_0036ee80);
        pBest = 0;
    }
    nBest = -1;
    for (i = 0; i < nBlockMax; i++) {
        pB = &pVcache[i];
        if (pB->used) {
            if (nBlock == pB->chBlockNum) {
                pB->pchDpd = pchDpd;
                pB->mask = (u64)1 << nParId;
                return pB->chBlockStart;
            }
            if (nBlock < pB->chBlockNum) {
                if (pBest == 0 || pB->chBlockNum - nBlock < nBest) {
                    nBest = pB->chBlockNum - nBlock;
                    pBest = pB;
                }
            }
        }
    }
    if (pBest) {
        pBest->pchDpd = pchDpd;
        pBest->chBlockNum = nBlock;
        pBest->mask = (u64)1 << nParId;
        return pBest->chBlockStart;
    }
    for (i = 0; i < nBlockMax; i++) {
        pE = &pVcache[i];
        if (pE->used && pE->chBlockStart < nBlock) func_001e5970(pE);
    }
    for (i = 0; i < nBlockMax; i++) {
        if (!pVcache[i].used) {
            pVcache[i].used = 1;
            pVcache[i].pchDpd = pchDpd;
            pVcache[i].mask = (u64)1 << nParId;
            pVcache[i].chBlockNum = nBlock;
            pVcache[i].chBlockStart = 0;
            return 0;
        }
    }
    ASSERT(0, D_0036ea98, 1903);
    return -1;
}

// 001e4320: turn every model's vertex colours to grey; returns the end of the model list.
s32* func_001e4320(s32* pData)
{
    s32 nModel = *pData++;
    s32 i, j, nNum, nSize, nType;
    u8* model;
    u8* base;
    u8* v;
    PartPrim* p;
    for (i = 0; i < nModel; i++) {
        model = (u8*)*pData++;
        nSize = 0;
        base = model + 16;
        p = (PartPrim*)(base + ((s32*)base)[1]);
        ASSERT(0 == (int)model % 16, D_0036ed10, 1196);
        while (p->type != -1) {
            nType = p->type;
            nNum = p->count;
            p++;
            asm("" : "+r"(p));
            v = (u8*)p;
            switch (nType) {
            case 0: LOOP3(20)
            case 1: LOOP3(28)
            case 2: LOOP3(32)
            case 3: LOOP3(40)
            case 4: LOOP4(24)
            case 5: LOOP4(32)
            case 6: LOOP4(40)
            case 7: LOOP4(48)
            default:
                func_001e2ad8(D_0036ea98, D_0036e9d0, 1332, D_0036eaa0);
                break;
            }
            p = (PartPrim*)((u8*)p + nSize * nNum);
        }
    }
    return pData;
}
