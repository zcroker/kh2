#include "../common/types.h"
struct W324C4 { u8 r, g, b, a; };
struct W324Sub { u8 pad[4]; u8 kind; u8 id; };
struct W324Obj {
    u8 p0[0x108]; u32 b0:1; u32 b1:1; u32 b2:3; u32 b5:1; u32 b6:1; u32 brest:25;
    u8 p1[0x140 - 0x10c]; u8 mot[0x3ac - 0x140]; W324C4 col;
    u8 p2[0xae4 - 0x3b0]; W324C4 cur;
    u8 p3[0xaf8 - 0xae8]; W324Sub* sub; void* afc; void* b00; u8 p4[4]; u8 eff[4];
};
extern "C" {
extern u32 D_00375480[];
void func_002c2228(u8);  // to_15ee90_if_nonzero
void func_002c2248(u8);  // to_15ee10_if_nonzero
void func_0017f540(void*, s32, f32, f32);
void* func_0016abf8(W324Obj*, s32, s32, s32);
void* func_0016ac38(W324Obj*, s32, s32, s32, s32);
void func_001dc920(void*);
void func_002f1990(void*);
s32 func_00181500(s32);
void func_002f1900(void*, s32, W324Obj*);
static inline bool cf(W324C4* p) { if (p->r < 2) return false; u32 m = p->a & 2; u32 r = m == 0; return r; }
static inline bool big(W324C4* p) { return p->r >= 3; }
void worldmap__Symbol__setState(W324Obj* o, W324C4* p);  // 0x002bf650: definition moved into src/anon/unit_002bebd0.cpp
}
