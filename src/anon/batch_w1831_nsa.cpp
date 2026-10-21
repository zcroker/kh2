#include "../common/types.h"

// 00168d08: relocates a block's entry pointers after a move and recurses into sub-blocks.
struct W1831Ent { u8 hdr[16]; u16 type; u16 flags; u32 pad; u8* ptr; u32 size; };
struct W1831Blk { u32 f0; s32 count; W1831Blk* base; u32 fc; };

extern "C" {
void func_0011f3e0(u8*);
void func_00131f48(u8*);
void func_0013a8b8(u8*);
void func_001dc140(u8*);
void func_00127dc8(u8*);
void func_001de770(u8*);
void func_002bc708(u8*);

// The second argument is the entry's old pointer; the code never reads it but passes it on.
void func_00168d08(W1831Blk* b, u8* x) {
    s32 i;
    s32 d = (u8*)b - (u8*)b->base;
    b->base = b;
    for (i = 0; i < b->count; i++) {
        W1831Ent* e = (W1831Ent*)(i * 16 + (u32)b);
        if (__builtin_expect(e->size == 0, 0)) continue;
        u8* o = e->ptr;
        u8* p = o + d;
        e->ptr = p;
        if (e->flags & 1) continue;
        switch (e->type) {
        case 1: case 17: case 20: case 30: case 46:
            func_00168d08((W1831Blk*)p, o);
            break;
        case 4:
            func_0011f3e0(p);
            break;
        case 7:
            func_00131f48(p);
            func_0013a8b8(p);
            break;
        case 8:
            func_001dc140(p);
            break;
        case 9:
            func_00127dc8(p);
            break;
        case 18:
            func_001de770(p);
            break;
        case 34:
            func_002bc708(p);
            break;
        }
    }
}
}
