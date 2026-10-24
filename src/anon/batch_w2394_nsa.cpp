#include "../common/types.h"
extern "C" {
struct VT { u8 pad[76]; u16 id; };
struct VO { u8 pad[48]; u16 sub; };
struct Slot { u32 flags; u32 id; u32 sub; };
extern Slot D_01c94090[3];
extern char* D_0033caf4;
extern char D_0036d938[];
extern char D_0036d940[];
extern u8 D_0032bae0;
extern u32 D_00350e00[];
extern u8* D_00350df8;
VT* func_0016e920(u32);
VO* func_001947c0(s32, s32);
s32 func_00105c30(void);
u32 func_00105ee8(u8);
void func_002fee78(char*, const char*, ...);
void func_00168388(char*, void*, void (*)(void), s32);
void func_001afdd0(void);
void func_00102448(u8*, s32);

static inline bool same(Slot* e, u32 id, u32 sub) { return e->id == id && e->sub == sub; }

/* 001afc00: register an (id, sub) pair in the 3-slot table (re-flag it if already present), format its
   label string and open it, then wait until the handler clears its busy flag.
   The __builtin_expect hints reproduce the original's register allocation (block frequencies). */
void func_001afc00(u32 a, void* b)
{
    char buf[48];
    if (__builtin_expect(a == 0,0)) return;
    VT* v = func_0016e920(a);
    if (__builtin_expect(v == 0,0)) return;
    u32 id = v->id;
    if (__builtin_expect(id - 1 >= 15,1)) return;
    u32 sub = func_001947c0(-1, -1)->sub;
    s32 i;
    for (i = 0; i < 3; i++) {
        if (same(&D_01c94090[i], id, sub)) {
            D_01c94090[i].flags |= 1;
            return;
        }
    }
    for (i = 0; i < 3; i++) {
        if ((D_01c94090[i].flags & 1) == 0) break;
    }
    char* lang = D_0033caf4;
    D_01c94090[i].flags |= 1;
    D_01c94090[i].id = id;
    D_01c94090[i].sub = sub;
    if (func_00105c30() == 8) lang = D_0036d938;
    func_002fee78(buf, D_0036d940, lang, func_00105ee8(D_0032bae0), sub, D_00350e00[id]);
    func_00168388(buf, b, func_001afdd0, i);
    *(u32*)(D_00350df8 + 4) = 1;
    while (*(u32*)(D_00350df8 + 4)) func_00102448(D_00350df8, 0);
}
}
