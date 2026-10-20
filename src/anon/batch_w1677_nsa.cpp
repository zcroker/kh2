#include "../common/types.h"

// 00142c90: builds the scene objects described by a setup block.
// Needs -fno-strict-aliasing (the heap store stays before the m->res reload).

struct W1677ResVtbl { void* fn[10]; };
struct W1677Res { W1677ResVtbl* vt; };

// 0x90-byte model object allocated from the caller's heap.
struct W1677Model {
    s32 handle;          // 0x00: returned by res->vt->fn[9]
    W1677Res* res;       // 0x04
    u8 pad08[8];
    u8 work[0x40];       // 0x10: filled by func_0011b6a8
    u8 sub50[0x24];      // 0x50: initialised by func_00108698
    void* tex;           // 0x74
    u8 pad78[0x10];
    s32 heap;            // 0x88
    u8 flag;             // 0x8c
};

extern "C" {
extern void* D_00348800;
extern void* D_00348804;
extern void* D_00348808;
extern void* D_0034880c;
extern void* D_00348810;
extern void* D_00348814;
extern W1677Model* D_00348818;
extern u8 D_0034881c;
extern u8 D_0034881d;
void* func_001063c0(s32 size, s32 heap);
void func_00108698(void*);
void func_0011b6a8(void*);
void func_0011e260(s32, void*);
void func_0011e880(s32, s32, s32, s32);
void func_0011eb08(s32, s32);
void func_001415e8(void*, s32, u64);
void func_00142bf8(void*);
void func_00143278(void);
void func_00143298(void);
void func_00145830(void*, s32, u8, u64);
W1677Res* func_00149288(void*);
void* func_00149290(void*);
s32 func_00149298(void*);
s32 func_001492a0(void*);
s32 func_001492a8(void*);
s32 func_001492b0(void*);
s32 func_001492b8(void*);
s32 func_001492c0(void*);
s32 func_001492d0(void*);
s32 func_001492d8(void*);
void func_0014ecb8(void);
void func_00153678(s32, u64, s32);
void func_0015c500(void);
void func_0015c6d0(s32);

void func_00142c90(void* setup, s32 heap, u8 flag, u64 mask) {
    D_0034881c = flag;
    D_0034881d = 0;
    func_00143298();
    func_00143278();

    void* p = func_001063c0(0x5380, heap);
    func_00145830(p, func_00149298(setup), flag, mask);
    D_00348800 = p;

    W1677Model* m = (W1677Model*)func_001063c0(0x90, heap);
    W1677Res* res = func_00149288(setup);
    u8* work = m->work;
    void* tex = func_00149290(setup);
    m->res = res;
    func_00108698(m->sub50);
    m->heap = heap;
    m->handle = ((s32 (*)(W1677Res*, s32))m->res->vt->fn[9])(m->res, heap);
    if (tex) {
        m->tex = tex;
        func_0011e260(m->handle, tex);
    }
    func_0011b6a8(work);
    func_0011eb08(m->handle, 0);
    func_0011e880(m->handle, 2, 0, 0);
    m->flag = 0;
    D_00348818 = m;

    void* q;
    func_0014ecb8();
    if (func_001492a0(setup)) {
        q = func_001063c0(0xe0, heap);
        func_001415e8(q, func_001492a0(setup), mask);
        D_00348804 = q;
        func_00142bf8(q);
    }
    if (func_001492a8(setup)) {
        q = func_001063c0(0xe0, heap);
        func_001415e8(q, func_001492a8(setup), mask);
        D_00348808 = q;
    }
    if (func_001492b0(setup)) {
        q = func_001063c0(0xe0, heap);
        func_001415e8(q, func_001492b0(setup), mask);
        D_0034880c = q;
    }
    if (func_001492b8(setup)) {
        q = func_001063c0(0xe0, heap);
        func_001415e8(q, func_001492b8(setup), mask);
        D_00348810 = q;
    }
    if (func_001492c0(setup)) {
        q = func_001063c0(0xe0, heap);
        func_001415e8(q, func_001492c0(setup), mask);
        D_00348814 = q;
    }
    func_0015c500();
    if (func_001492d8(setup)) func_0015c6d0(func_001492d8(setup));
    func_00153678(func_001492d0(setup), mask, heap);
}
}
