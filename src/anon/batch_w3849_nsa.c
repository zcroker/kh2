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
s32 func_001e5a00(VCache* pVcache, s32 nBlockMax, ParInfo* pPar, u8 nBlock);  // 0x001e5a00: definition moved into src/anon/unit_001e0cb8.cpp

// 001e4320: turn every model's vertex colours to grey; returns the end of the model list.
s32* func_001e4320(s32* pData);  // 0x001e4320: definition moved into src/anon/unit_001e0cb8.cpp
