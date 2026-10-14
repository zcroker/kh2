#include "../common/types.h"
extern "C" {
typedef struct MChunk MChunk;
struct MChunk { u32 prev_size; u32 size; MChunk* fd; MChunk* bk; };
extern MChunk* D_00365c50[];
extern u8* D_00366068;
typedef struct MI { u32 arena; u32 ordblks; u32 smblks; u32 hblks; u32 hblkhd; u32 usmblks; u32 fsmblks; u32 uordblks; u32 fordblks; u32 keepcost; } MI;
extern MI D_00366080;
void func_002fded8(void*);
void func_002fdf30(void*);
u8* func_002fea70(void*, s32);
// newlib _malloc_trim_r: give unused memory at the top of the heap back to sbrk.
s32 func_00303170(void* r, u32 pad) {
    s64 top_size;
    s64 extra;
    u8* current_brk;
    u8* new_brk;
    u64 pagesz = 4096;
    func_002fded8(r);
    top_size = D_00365c50[2]->size & ~3;
    extra = ((top_size - pad - 16 + (pagesz - 1)) / pagesz - 1) * pagesz;
    if (extra < (s64)pagesz) {
        func_002fdf30(r);
        return 0;
    } else {
        current_brk = func_002fea70(r, 0);
        if (current_brk != (u8*)D_00365c50[2] + (s32)top_size) {
            func_002fdf30(r);
            return 0;
        } else {
            new_brk = func_002fea70(r, -(s32)extra);
            if (new_brk == (u8*)-1) {
                current_brk = func_002fea70(r, 0);
                top_size = current_brk - (u8*)D_00365c50[2];
                if (top_size >= 16) {
                    D_00366080.arena = current_brk - D_00366068;
                    D_00365c50[2]->size = top_size | 1;
                }
                func_002fdf30(r);
                return 0;
            } else {
                D_00365c50[2]->size = (top_size - extra) | 1;
                D_00366080.arena -= extra;
                func_002fdf30(r);
                return 1;
            }
        }
    }
}

}
