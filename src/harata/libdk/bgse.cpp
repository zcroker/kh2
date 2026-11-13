// dk::BGSE (0x1363a0-0x136a98): the map's sound-effect banks and its background sound.
// The map's sound record (func_001aec40) names the banks; the last loaded record is kept so that
// a bank is only reloaded when it changed.
#include "../../common/types.h"

struct SeInfo { s16 f0, f2, f4, f6, f8, f10; s16 r[6]; };

extern "C" {
SeInfo* func_001aec40(...);
u32 func_002ba0b0(s32);
u32 func_002ba0f8(s32);
void func_002ba3e8(u32, u32, u32, u32, u32, s32*, u32, u32);
void func_002ba3b8(u32, u32, u32, u32, u32, u32, u32);
void func_002ba5d0(u32, u32);
void func_002ba7c8(u32);
void func_002b9ab8(s32);
void func_002b9ed0(void);
void func_002ba040(void);
u32 func_002bc288(u32, u32);
void func_00168388(u32, u32, u32, u32);
s32 func_00170cd0(void);
void* func_00170b30(u32);
}
void SOUND_setReverb(s32) asm("_ZN5SOUND9setReverbEi");
void TaskYield(u32, u32) asm("func_00102448");
u32 YS_FILE_GetSize(const char*) asm("_ZN2YS4FILE7GetSizeEPKc");
void YS_CACHE_BUFF_FixFree(void*) asm("_ZN2YS10CACHE_BUFF7FixFreeEPv");
void StopBgSeHandle(u32, u32) asm("func_002bc358");

extern "C" {
extern u8 D_0032bae0;
s32 D_00347d20 = -1;
s32 D_00347d24 = -1;
u8 D_00347d28;
static SeInfo D_003b8b20;
static s32 D_003b8b38;
}

namespace dk {
class BGSE {
public:
    static u32 alloc(char* name, u32& size);
    static void free(void* p);
    static void clearOff();
};
}

extern "C" {
void func_001367e0(u32 p, u32 a, u32 b);
void func_00136840(void);
u32 func_00136778(s32 a, s32 b);
void func_001369d0(void);
void func_001369f0(void);
void func_00136a40(void);
void func_00136a60(void);

// Loads the two banks of the record (f6, f4) unless they are the current ones.
void func_001363a0(u32 p) {
    u32 sz[2];
    SeInfo* v = func_001aec40(p);
    if (v->f6 == D_003b8b20.f6 && v->f4 == D_003b8b20.f4) return;
    if (v->f6 == -1) return;
    if (v->f4 == -1) return;
    u32 h0 = func_002ba0b0(v->f6);
    u32 d0 = dk::BGSE::alloc((char*)h0, sz[0]);
    func_001367e0(p, h0, d0);
    u32 h1 = func_002ba0f8(v->f4);
    u32 d1 = dk::BGSE::alloc((char*)h1, sz[1]);
    func_001367e0(p, h1, d1);
    func_002ba3e8(20, d0, sz[0], d1, sz[1], &D_003b8b38, 0, 0);
    func_002ba7c8(p);
    dk::BGSE::free((void*)d1);
    dk::BGSE::free((void*)d0);
}

void func_001364b8(u32 p, s32 id, u32 slot) {
    u32 size;
    u32 h = func_002ba0b0(id);
    u32 d = dk::BGSE::alloc((char*)h, size);
    if (size != 0) {
        func_001367e0(p, h, d);
        func_002ba3b8(slot, d, size, 0, 0, 0, 0);
        func_002ba7c8(p);
    }
    dk::BGSE::free((void*)d);
}

void func_00136560(u32 self) {
    SeInfo* v = func_001aec40(self);
    if (v->r[0] != D_003b8b20.r[0]) {
        u32 a = func_002ba0f8(v->r[0]);
        u32 n;
        u32 b = dk::BGSE::alloc((char*)a, n);
        if (n) {
            func_001367e0(self, a, b);
            func_002ba5d0(b, n);
            func_002ba7c8(self);
        }
        dk::BGSE::free((void*)b);
    }
    if (v->r[1] != -1 && v->r[1] != D_003b8b20.r[1]) func_001364b8(self, v->r[1], 10);
    if (v->r[2] != -1 && v->r[2] != D_003b8b20.r[2]) func_001364b8(self, v->r[2], 11);
    if (v->r[3] != -1 && v->r[3] != D_003b8b20.r[3]) func_001364b8(self, v->r[3], 12);
    if (v->r[4] != -1 && v->r[4] != D_003b8b20.r[4]) func_001364b8(self, v->r[4], 13);
    if (v->r[5] != -1 && v->r[5] != D_003b8b20.r[5]) func_001364b8(self, v->r[5], 14);
}

void func_001366b8(u32 a) {
    SeInfo* r = func_001aec40(a);
    if (!r) return;
    if (r->f0 == -1) func_002b9ab8(20);
    else func_002b9ab8(r->f0);
    SOUND_setReverb(r->f2);
    if (D_0032bae0 != D_00347d20) {
        func_001369d0();
        func_001369f0();
        D_00347d20 = D_0032bae0;
        func_002b9ed0();
    }
    func_00136a60();
    func_001363a0(a);
    func_00136560(a);
}

u32 func_00136778(s32 a, s32 b) { return a * 1000 + b; }
}

u32 dk::BGSE::alloc(char* name, u32& size) {
    u32 n = YS_FILE_GetSize(name);
    size = n;
    return (u32)func_00170b30((n + 2047) & ~2047);
}

void dk::BGSE::free(void* p) { YS_CACHE_BUFF_FixFree(p); }

extern "C" {
void func_001367e0(u32 p, u32 a, u32 b) {
    func_00168388(a, b, 0, 0);
    while (func_00170cd0()) TaskYield(p, 0);
}

void func_00136840(void) {
    if (D_00347d24 != -1) StopBgSeHandle(D_00347d24, 480);
}

// Starts the map's background sound (f6, f8) when the map changed; keeps the record.
void func_00136878(void) {
    u64 unused[2];
    SeInfo* p = func_001aec40();
    if (!p) return;
    if (p->f8 == -1) func_00136840();
    else if (p->f8 == D_003b8b20.f8 && p->f4 == D_003b8b20.f4 && p->f6 == D_003b8b20.f6) {}
    else {
        func_00136840();
        D_00347d24 = func_002bc288(func_00136778(p->f6, p->f8), D_003b8b38);
    }
    D_003b8b20 = *p;
}

s32 func_00136958(void) { return D_003b8b38; }

void func_00136968(void) {
    func_001369d0();
    func_001369f0();
    D_003b8b38 = -1;
    D_003b8b20.f2 = -1;
    D_003b8b20.f0 = -1;
    D_00347d24 = -1;
    D_00347d20 = -1;
    dk::BGSE::clearOff();
}

void func_001369b8(void) { func_00136840(); }

void func_001369d0(void) {
    D_003b8b20.f10 = -1;
    D_003b8b20.f8 = -1;
    D_003b8b20.f6 = -1;
    D_003b8b20.f4 = -1;
}

void func_001369f0(void) {
    D_003b8b20.r[5] = -1;
    D_003b8b20.r[4] = -1;
    D_003b8b20.r[3] = -1;
    D_003b8b20.r[2] = -1;
    D_003b8b20.r[1] = -1;
    D_003b8b20.r[0] = -1;
}

void func_00136a18(void) {
    func_00136840();
    func_001369d0();
    func_00136a40();
}

void func_00136a40(void) { D_00347d28 = 1; }
}

void dk::BGSE::clearOff() { D_00347d28 = 0; }

extern "C" void func_00136a60(void) {
    if (D_00347d28 != 1) return;
    func_002ba040();
    dk::BGSE::clearOff();
}
