#include "../common/types.h"

// ---- 002b8ac0
namespace n002b8ac0 {
struct StrmSt { s32 mode; s32 size; };
struct Strm { u8 pad[0x48000]; StrmSt st; };
extern "C" {
s32 func_002b85e4(u8*);
}
extern "C" {
// Classifies the stream buffer state: 0 idle, 1 small, 2 in range, 3 behind.
s32 func_002b8ac0(Strm* p) {
    s32 r = 0;
    s32 n = func_002b85e4((u8*)p + 0x8000);
    if (p->st.mode != 0) {
        if (p->st.mode == 1 && p->st.size <= 0x1ffff) r = 1;
        if (p->st.mode == 2 && n > 0x8000 && n < p->st.size && p->st.size <= 0x3ffff) r = 2;
        if (p->st.mode == 2 && n > p->st.size && p->st.size < n - 0x8000) r = 3;
    }
    return r;
}
}
}
