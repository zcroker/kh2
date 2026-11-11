#include "prizetable.hpp"

// YS::PRIZETABLE (0x1a5b58-0x1a5c08): the prize table, 24-byte entries sorted by id.

extern "C" {
void* func_002fd248(s32, void*, s32, s32, void*);  // bsearch
f32 func_002f86f0(f32);
extern char D_0031f288[];   // the id comparator (an out-of-line inline function)
}

struct PRIZE_FILE { u32 magic; s32 n; u8 e[1]; };

static PRIZE_FILE* s_table;

namespace YS {

void PRIZETABLE::Init(void* t) {
    s_table = (PRIZE_FILE*)t;
}

void* PRIZETABLE::Get(s32 id) {
    void* r = func_002fd248(id, s_table->e, s_table->n, 24, D_0031f288);
    if (!r) r = func_002fd248(72, s_table->e, s_table->n, 24, D_0031f288);
    return r;
}

s32 PRIZETABLE::get_num(s32 i, f32 rate) {
    return (s32)func_002f86f0((f32)((u8*)this)[i + 2] * rate);
}

}  // namespace YS
