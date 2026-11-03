// 0024c950 (_nsa): partial inline asm. The flag-byte stores to D_0035edf0/D_0035edfc are
// written as single instructions because gcc moves their lui down to the store
// (local-alloc REG_EQUIV); the third heap holder is pinned to $15 (t7).
#include "../common/types.h"
extern "C" {
struct Alloc;
struct AllocVt { u8* (*alloc)(Alloc*, u32, void*); };
struct Alloc { AllocVt* vt; };
struct HeapHolder { u8 pad[0x14]; Alloc* heap; };
extern Alloc* D_0032ba14;
extern HeapHolder* D_00347f80;
extern u8 D_0032bae1;
extern u32 D_00347e40;
extern u32 D_00347e60;
extern u32 D_00347f98;
extern u32 D_0024cda8;
extern u32 D_0035edcc;
extern u32 D_0035edd0;
extern s32 D_0035edd4;
extern s32 D_0035edd8;
extern s32 D_0035eddc;
extern u8* D_0035ede0;
extern u8* D_0035ede4;
extern u8* D_0035ede8;
extern u8* D_0035edec;
extern u8 D_0035edf0;
extern s32 D_0035edf4;
extern u32 D_0035edf8;
extern u8 D_0035edfc;
s32 func_0024dfe0(void);
void func_00287b18(s32, s32);
u32 func_00288be8(s32);
void func_002889f0(u32, s32, s32);
void func_00288f48(u32, s32, s32, s32, s32);
void func_002b3df8(u8*);
void func_00239700(u8*);
void func_0031a838(u8*);
u32 func_00103570(void);
u32 func_001063f0(s32, u32);
void func_002fde18(u32, s32, s32);
void func_0028d068(s32, s32);
u8* func_00103eb0(void);
void func_00102818(u32, s32, s32, u32*, s32);

void func_0024c950(void) {
    D_0035edf4 = D_0032bae1 != 6;
    s32 n = func_0024dfe0();
        func_00287b18(n, 3);
    u32 a = func_00288be8(56);
    func_002889f0(a, n, 1);
    D_0035edcc = a;
    u32 b = func_00288be8(56);
    func_002889f0(b, 2, 0);
    D_0035edd0 = b;
    func_00288f48(b, 64, 128, 0, 0);
    D_0035edd4 = 0;
    D_0035edd8 = 0;
    D_0035eddc = 0;
    u8* c = D_0032ba14->vt->alloc(D_0032ba14, 12, __builtin_return_address(0));
    func_002b3df8(c);
    register u8* f7 asm("$15"); register u8* f0 asm("$14");
    asm("lui %0,%%hi(D_0035edec)\n\tlui %1,%%hi(D_0035edf0)" : "=r"(f7), "=r"(f0));
    asm("sw %1,%%lo(D_0035edec)(%2)" : "=m"(*(u8**)f7) : "r"(c), "r"(f7));
    register s32 a1 asm("$5");
    asm("li %1,436\n\tsb $0,%%lo(D_0035edf0)(%2)" : "=m"(*f0), "=r"(a1) : "r"(f0));
    Alloc* h = D_00347f80->heap;
    u8* p = h->vt->alloc(h, a1, 0);
    *(s32*)(p + 0xc) = 0;
    *(u32**)p = &D_00347e60;
    func_00239700(p + 0x18);
    *(s32*)(p + 0x198) = 0;
    *(u32**)p = &D_00347e40;
    D_0035ede0 = p;
    Alloc* h2 = D_00347f80->heap;
    u8* q = h2->vt->alloc(h2, 436, 0);
    *(u32**)q = &D_00347f98;
    func_0031a838(q + 0xc);
    *(u32**)q = &D_00347e60;
    func_00239700(q + 0x18);
    *(u32**)q = &D_00347e40;
    *(s32*)(q + 0x198) = 0;
    D_0035ede4 = q;
    u32 w = func_001063f0(32, func_00103570());
    D_0035edf8 = w;
    func_002fde18(w, 0, 32);
    register HeapHolder* hp asm("$15") = D_00347f80;
    Alloc* h3 = hp->heap;
    s32 i = n - 1;
    u8* r = h3->vt->alloc(h3, n * 408 + 4, 0);
    u8* arr = r + 4;
    *(s32*)r = n;
    u8* e = arr;
    if (n != 0) {
        do {
            *(s32*)(e + 0xc) = 0;
            *(u32**)e = &D_00347e60;
            func_00239700(e + 0x18);
            i--;
            e += 408;
        } while (i != -1);
    }
    register u8* t7 asm("$15");
    asm volatile("lui %0,%%hi(D_0035ede8)" : "=r"(t7));
    register u8* fc asm("$14");
    asm volatile("lui %0,%%hi(D_0035edfc)" : "=r"(fc));
    {register u8* ar asm("$19") = arr; asm volatile("sw %0,%%lo(D_0035ede8)(%1)" : : "r"(ar), "r"(t7));}
    register s32 a0 asm("$4");
    asm volatile("li %0,30026" : "=r"(a0));
    asm volatile("sb $0,%%lo(D_0035edfc)(%0)" : : "r"(fc));
    func_0028d068(a0, -1);
    func_00102818(*(u32*)(func_00103eb0() + 4), 0, 2000, &D_0024cda8, 4096);
}
}
