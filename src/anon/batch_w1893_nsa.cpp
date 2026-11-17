#include "../common/types.h"
struct O1893;
struct E1893;
typedef void (*Fn1893)(O1893*, u8*, E1893*);
struct H1893 { u32 x0; Fn1893 fn; };
struct E1893 { H1893* h; u16 off; u16 pad; u32 x8, xc; };
struct Hd1893 { u8 pad[0x20]; s32 x20; u16 x24; s16 n; E1893 e[1]; };
struct O1893 { u32 x0, x4; Hd1893** x8; s32 xc; };
struct G1893 { u8 pad[0xa8]; u64 xa8; };
extern "C" {
extern Fn1893 D_00354bb0[];
extern O1893* D_01d9e6e8;
extern G1893* D_01d9e6e0;
extern s32 D_01d9ea9c;
static inline s32 inL_w1893(Fn1893 f) {
    Fn1893* p = D_00354bb0;
    s32 r = 0;
    for (; *p != 0; p++) {
        if (f == *p) { r = 1; break; }
    }
    return r;
}
void func_001e8e28(void* a, O1893* o);  // 0x001e8e28: definition moved into src/anon/unit_001e8ac8.cpp

}
