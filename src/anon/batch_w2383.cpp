#include "../common/types.h"
// batch w2383

// Cache-buffer entry: b1 is a busy flag, f28 the id, f38 the saved id.
struct W2383CacheEnt { u8 b0; u8 b1; u8 pad[0x26]; s32 f28; s32 f2c; s32 f30; s32 f34; s32 f38; };

extern "C" {
extern u8 D_0034dca0[];
W2383CacheEnt* w2383_find(u32, u32) asm("_Z16ctarget_00170240jjjj");
s32 w2383_file_size(u32) asm("_ZN2YS4FILE7GetSizeEPKc");
void w2383_header_ctor(W2383CacheEnt*, u32, u32, u32) asm("_ZN2YS10CACHE_BUFF6HEADERC1EPKcij");
void func_0031e328(void*, W2383CacheEnt*);
W2383CacheEnt* func_0016fac8(u32);
void func_00170188(W2383CacheEnt*);

// Finds the cache entry for (name, id); otherwise reuses a free entry (id >= 10000) or
// allocates a new header whose size is the file size rounded up to 2048, then 128 bytes.
W2383CacheEnt* wtarget_00170400(u32 name, u32 id, u32 size, u32 d) asm("_Z16wtarget_00170400jjjj");
W2383CacheEnt* wtarget_00170400(u32 name, u32 id, u32 size, u32 d);  // 0x00170400: definition moved into src/anon/unit_0016e8f8.cpp
}
