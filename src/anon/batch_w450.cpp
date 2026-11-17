#include "../common/types.h"
extern "C" {
typedef struct MChunk MChunk;
struct MChunk { u32 prev_size; u32 size; MChunk* fd; MChunk* bk; };
extern MChunk* D_00365c50[];
extern u8* D_00366068;
typedef struct MI { u32 arena; u32 ordblks; u32 smblks; u32 hblks; u32 hblkhd; u32 usmblks; u32 fsmblks; u32 uordblks; u32 fordblks; u32 keepcost; } MI;
extern MI D_00366080;
void __malloc_lock(void*);
void __malloc_unlock(void*);
u8* func_002fea70(void*, s32);
// newlib _malloc_trim_r: give unused memory at the top of the heap back to sbrk.
s32 _malloc_trim_r(void* r, u32 pad);  // 0x00303170: definition moved into src/newlib/libc/freer.c

}
