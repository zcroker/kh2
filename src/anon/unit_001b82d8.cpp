#include "../common/types.h"

// YS::LIBRETTO (0x1b82d8-0x1b87a0): loads the libretto table for the current language and
// runs its commands through a pool of eight slots.

struct LibrettoSlot {
    u32 key;     // 0
    u32 count;   // 4
    u32 cur;     // 8
    s32 (*fn)(void*, LibrettoSlot*);  // 12
    s32 id;      // 16
    LibrettoSlot() { key = 0; count = 0; }
};

extern "C" void func_00320408(void);           // bsearch compare
extern "C" void func_00320418(void* pool);     // reset the free list

struct LibrettoPool {
    LibrettoSlot slot[8];
    s32 free[8];   // 160
    s32 nfree;     // 192
    LibrettoPool() { func_00320418(this); }
};

extern "C" {
u32 func_00105ee8(u8);
void func_002fee78(char*, const char*, u32);  // sprintf
void func_00170518(char*, s32, s32);
u32 func_001708f8(char*, s32);
u8* func_00168b38(u32, s32, s32);  // entry_array_find_nth
void func_00170950(u32);
u8* func_002fd248(u32, u8*, u32, u32, void (*)(void));  // bsearch
u32 func_001db610(u32, s32 (*)(void*, LibrettoSlot*), LibrettoSlot*);
void func_00102470(f32, s32);
s32 func_001991a8(s32, s32);
s32 func_0014aba8(void);
void func_0014aa58(s32, s32, s32);
void func_0014aa80(s32, s32, s32);
}
extern u8 D_0032bae0;           // language
extern const char* D_003511c4;  // libretto file name format

static u32 D_01d48cc0 __attribute__((aligned(4)));  // table handle
static u8* D_01d48cc4 __attribute__((aligned(4)));  // table data
static LibrettoPool D_01d48cc8;

void func_001b82d8(char* buf) {
    func_002fee78(buf, D_003511c4, func_00105ee8(D_0032bae0));
}

void func_001b8318(void) {
    char buf[48];
    func_001b82d8(buf);
    func_00170518(buf, 1040, 0);
}

namespace YS {
namespace LIBRETTO {

void Init() {
    char buf[48];
    func_001b82d8(buf);
    D_01d48cc0 = func_001708f8(buf, -1);
    D_01d48cc4 = *(u8**)(func_00168b38(D_01d48cc0, 2, 0) + 8);
    for (s32 i = 0; i < 8; i++) D_01d48cc8.free[i] = i;
    D_01d48cc8.nfree = 8;
}

void Ensure() {
    func_00170950(D_01d48cc0);
}

}  // namespace LIBRETTO
}  // namespace YS

extern "C" {

u8* func_001b83f0(u32 key) {
    return func_002fd248(key, D_01d48cc4 + 8, *(u32*)(D_01d48cc4 + 4), 8, func_00320408);
}

u32 func_001b8420(u32 key) {
    u8* e = func_001b83f0(key);
    return (u32)(D_01d48cc4 + *(u32*)(e + 4));
}

void func_001b8450(LibrettoSlot* s, u32 key, s32 (*fn)(void*, LibrettoSlot*)) {
    u8* e = func_001b83f0(key);
    s->key = key;
    if (e) s->count = *(u16*)(e + 2);
    else s->count = 0;
    s->fn = fn;
    s->cur = 0;
    s->id = 0;
}

}

struct LibrettoCmd { u16 type; u16 pad; union { f32 f; s32 i; } v; };

extern "C" s32 func_001b8520(LibrettoCmd* c, LibrettoSlot* x);

u32 func_001b84b8(LibrettoSlot* p, s32 id) {
    if (!p->count) return 0;
    p->id = id;
    if (!p->cur) p->cur = func_001b8420(p->key);
    p->cur = func_001db610(p->cur, (s32 (*)(void*, LibrettoSlot*))func_001b8520, p);
    return p->cur != 0;
}

extern "C" {

s32 func_001b8520(LibrettoCmd* c, LibrettoSlot* x) {
    s32 t;
    switch (c->type) {
    case 2:
        func_00102470(c->v.f, x->id);
        return 1;
    case 3:
        func_001991a8(c->v.i, 0);
        return 1;
    case 4:
        return 0;
    case 5:
        t = (s32)(c->v.f * 0.5f);
        func_0014aa58(func_0014aba8(), t, 0);
        return 1;
    case 6:
        t = (s32)(c->v.f * 0.5f);
        func_0014aa80(func_0014aba8(), t, 0);
        return 1;
    case 7:
        t = (s32)(c->v.f * 0.5f);
        func_0014aa58(func_0014aba8(), t, 1);
        return 1;
    case 8:
        t = (s32)(c->v.f * 0.5f);
        func_0014aa80(func_0014aba8(), t, 1);
        return 1;
    default:
        return x->fn(c, x);
    }
}

LibrettoSlot* func_001b8680(u32 key, s32 (*fn)(void*, LibrettoSlot*)) {
    LibrettoPool* pool = &D_01d48cc8;
    LibrettoSlot* s = &pool->slot[pool->free[--pool->nfree]];
    func_001b8450(s, key, fn);
    return s;
}

void func_001b86e0(LibrettoSlot* e) {
    s32 n = D_01d48cc8.nfree;
    D_01d48cc8.nfree = n + 1;
    D_01d48cc8.free[n] = e - D_01d48cc8.slot;
}

}
