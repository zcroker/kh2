#include "../common/types.h"
// zl90 w2407 2026-10-26: 00154558 matched (separate inner-loop counter j lets the range pass split root into s7).
extern "C" {
struct W1632Seq { u8 pad[344]; };
struct W1632Sprite {
    u8 pad0[24];
    W1632Seq seq;       // 24
    u8 pad1[28];
    void* parent;       // 396
    s32 flag;           // 400
    u8 pad2[4];
};
struct W1632Menu {
    u8 pad0[32];
    s32 x;                      // 32
    u8 pad1[12];
    W1632Sprite parts[6];       // 48
    W1632Sprite grid[16][2];    // 2496
};
void func_00154b18(W1632Menu*);
void func_0014fc40(W1632Menu*, u32, s32, u32, u32, s32);
u32 func_0013a7e8(s32);
u32 func_0013d7e0(void);
void func_001386e0(W1632Sprite*, u32, u32, u32, u32, u32);
void func_001396b0(W1632Sprite*);
void func_0031a260(W1632Sprite*, u32);
void func_00138c68(W1632Sprite*, s32, s32);
s32 func_0023aa98(W1632Seq*);
void func_001399c0(s32);

static inline void W1632_setParent(W1632Sprite* obj, W1632Sprite* parent) {
    obj->parent = parent;
    func_001396b0(obj);
    if (obj->parent != 0) {
        obj->flag = 0;
        func_001396b0(obj);
        if (obj->flag != 0) {
            func_0031a260(obj, 0);
        }
    }
}
// 00154558: moved to src/anon/unit_00153ea0.cpp
void func_00154558(W1632Menu* self);
}
