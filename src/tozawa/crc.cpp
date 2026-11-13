// Tz::Crc: table-driven CRC-32 (poly 0x04c11db7) with its own allocator. Linked unit 0x2422b8-0x242478.
#include "../common/types.h"

struct ALLOCATOR;
struct ALLOCATOR_VT { void* (*alloc)(ALLOCATOR*, u32, void*); void (*free)(ALLOCATOR*, void*); };
struct ALLOCATOR { ALLOCATOR_VT* vt; };

extern "C" {
u32* func_001063f0(u32, ALLOCATOR*);
void func_00106450(u32*);
}

ALLOCATOR* D_0035ecbc;
u32* D_0035ecc0;
u32 D_0035ecc4;

void func_002423a0(void);
void func_00242408(void);

namespace Tz { struct Crc { static void Init(ALLOCATOR*); }; }

void Tz::Crc::Init(ALLOCATOR* a) {
    D_0035ecbc = a;
    D_0035ecc0 = func_001063f0(1024, a);
    func_002423a0();
    func_00242408();
}

void func_002422f0_impl(void) asm("_Z16u_call0_002422f0v");
void func_002422f0_impl(void) {
    D_0035ecbc = 0;
    u32* t = D_0035ecc0;
    if (t != 0) {
        func_00106450(t);
        D_0035ecc0 = 0;
    }
}

void* func_00242330(u32 size) {
    return D_0035ecbc->vt->alloc(D_0035ecbc, size, __builtin_return_address(0));
}

void func_00242368(void* p) {
    if (p) {
        D_0035ecbc->vt->free(D_0035ecbc, p);
    }
}

void func_002423a0(void) {
    u32 t2 = 0x04C10000u;
    u32 t1 = 0;
    u32 t3 = 0x80000000u;
    t2 = t2 | 0x1DB7u;
    do {
        u32 t4 = t1 << 24;
        u32 t6 = 0;
        do {
            u32 t7 = t4 & t3;
            if (t7 != 0) {
                t7 = t4 << 1;
                t4 = t7 ^ t2;
            } else {
                t4 = t4 << 1;
            }
            t6 += 1;
        } while (t6 < 255);
        u32 t15 = (u32)D_0035ecc0;
        u32 t14 = t1 << 2;
        t1 += 1;
        t14 = t14 + t15;
        *(u32*)t14 = t4;
    } while (t1 < 256);
}

void func_00242408(void) { D_0035ecc4 = (u32)-1; }

u32 func_00242418(u8* p, s32 n)
{
    while (--n >= 0) {
        D_0035ecc4 = (D_0035ecc4 << 8) ^ D_0035ecc0[(D_0035ecc4 >> 24) ^ *p++];
    }
    return ~D_0035ecc4;
}
