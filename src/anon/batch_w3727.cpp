#include "../common/types.h"

// Empty-destructor local: keeps the last call a jal (no sibling call), as in the original.
struct NoTail_w3727 { ~NoTail_w3727() {} };
struct WHdr_w3727 { u8 pad[12]; s32 count; };

extern "C" {
void func_002f28b8(void*, s16, s16, s16, s16, s16, s16, s16);
void func_003058a0(s32);
void func_002f2be0(void*, void*);
void func_001e50a8(u32, s32);
extern u8 D_01d9e3f0;

// Draws an entry: the first value is shifted by d and rebased (12288 or 10752) before the call.
void func_001e5220(s16* p, s16 d) {
    NoTail_w3727 nt;
    s16 a = p[0];
    if (a >= 12288) a = a + d - 12288; else a = a + d - 10752;
    func_002f28b8(&D_01d9e3f0, a, p[2], p[3], p[4], p[5], p[6], p[7]);
    func_003058a0(0);
    func_002f2be0(&D_01d9e3f0, p + 16);
}

void wtarget_001dc140(u32* a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_001dc140jjjj");
// Relocates a loaded data block by (a0 - a1): patches the non-null offsets in its 32-byte entries,
// then hands each listed offset (made absolute) to 001e50a8.
// Register pins and empty asm: the original keeps the block base in t4 (copied first), the header
// in t3 for the first loop, and the first loop's cursor in t5.
void wtarget_001dc140(u32* a0, u32 a1, u32 a2, u32 a3) {
    s32 d = (u32)a0 - a1;
    WHdr_w3727* h = (WHdr_w3727*)a0;
    register u32 base0 asm("$12") = (u32)a0;
    asm("" : "+r"(base0));
    s32 i = 0;
    if (((WHdr_w3727*)a0)->count > 0) {
        a0 += 4;
        register u32* p asm("$13") = a0;
        do {
            if (*p) *p += d;
            p += 8;
            i++;
        } while (i < h->count);
        asm("" : "+r"(p));
        a0 = p;
    } else {
        a0 += 4;
    }
    s32 n = *a0++;
    u32 base = base0;
    asm("" : "+r"(base));
    for (i = 0; i < n; i++) func_001e50a8(*a0++ + base, d);
}

struct O_w3727 { u8 pad[0x48c]; s32 x; };
extern O_w3727* D_0034e948;
extern u8 D_00351eb8;
bool func_0019ba60(O_w3727*);
bool func_001b58a8();
s32 func_001c8ab0();
bool func_001c8db8(void*, s32);
bool func_001410c8();
bool func_001917c0();
s32 func_001a1de0(s32);

// Chain of checks on the current object. All exits go through one return label placed before the
// body (goto form): gcc then merges the epilogue there, as in the original layout.
s32 func_001d4420() {
    O_w3727* o = D_0034e948;
    s32 r;
    if (func_0019ba60(o) && o->x) goto body;
fail:
    r = 0;
done:
    return r;
body:
    if (func_001b58a8()) goto fail;
    if (func_001c8ab0() != 2) { bool b = !func_001c8db8(&D_00351eb8, 0); if (!b) goto fail; }
    if (func_001410c8()) goto fail;
    if (!func_001917c0()) { r = 0; goto done; }
    r = !func_001a1de0(o->x);
    goto done;
}
}
