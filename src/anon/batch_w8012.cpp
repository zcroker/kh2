#include "../common/types.h"
struct Alloc { void (**vt)(Alloc*, ...); };
struct Holder { u8 pad[0x14]; Alloc* al; };
typedef void (*DtorFn)(u8*);
extern "C" {
extern void* D_00347f80;
extern u8 D_00347e60, D_00347f98, D_0035eb98, D_00361e10;
extern u8* D_00361e00;
void func_00170950(s32);
void func_00239870(u8*);
void func_0023c098(u8*);
void func_002369f0(u8*);


static inline void Free(void* p) { Alloc* al = ((Holder*)D_00347f80)->al; al->vt[1](al, p); }
void func_002c9cd8(u8* self) {
    *(void**)self = &D_00361e10;
    func_00170950(*(s32*)(self + 0x2584));
    D_00361e00 = (D_00361e00 == self) ? 0 : D_00361e00;
    if (self + 0x20b8) {
        u8* p = self + 0x2580;
    top0x20b8:
        if (self + 0x20b8 == p) goto out0x20b8;
        p -= 0x198;
        (*(DtorFn*)(*(u8**)p + 12))(p);
        goto top0x20b8;
    }
out0x20b8:;
    if (self + 0x1260) {
        u8* p = self + 0x20b8;
    top0x1260:
        if (self + 0x1260 == p) goto out0x1260;
        p -= 0x198;
        (*(DtorFn*)(*(u8**)p + 12))(p);
        goto top0x1260;
    }
out0x1260:;
    if (self + 0xd98) {
        u8* p = self + 0x1260;
    top0xd98:
        if (self + 0xd98 == p) goto out0xd98;
        p -= 0x198;
        (*(DtorFn*)(*(u8**)p + 12))(p);
        goto top0xd98;
    }
out0xd98:;
    if (self + 0x8d0) {
        u8* p = self + 0xd98;
    top0x8d0:
        if (self + 0x8d0 == p) goto out0x8d0;
        p -= 0x198;
        (*(DtorFn*)(*(u8**)p + 12))(p);
        goto top0x8d0;
    }
out0x8d0:;
    if (self + 0x408) {
        u8* p = self + 0x8d0;
    top0x408:
        if (self + 0x408 == p) goto out0x408;
        p -= 0x198;
        (*(DtorFn*)(*(u8**)p + 12))(p);
        goto top0x408;
    }
out0x408:;
    *(void**)(self + 0x270) = &D_00347e60;
    func_00239870(self + 0x288);
    *(void**)(self + 0x270) = &D_00347f98;
    *(void**)(self + 0xbc) = &D_00347e60;
    func_00239870(self + 0xd4);
    *(void**)(self + 0xbc) = &D_00347f98;
    *(void**)(self + 0x1c) = &D_0035eb98;
    func_0023c098(self + 0x4c);
    func_002369f0(self + 0x34);
    *(void**)(self + 0x1c) = &D_00347f98;
    *(void**)self = &D_00347f98;
    Free(self);
}
}
