#include "./types.h"

// Title mode (0x102d10-0x103100): loads the ovl_title.x overlay and keeps the title flags.

struct TASK;

struct Allocator {
    struct VT {
        void* (*alloc)(Allocator*, u32, void*);
        void (*free)(Allocator*, void*);
    }* vt;
};

// The title mode object (0x32b9a0). Its vtable is TASK's (0x32b930).
extern u32 D_0032b930;
struct TitleMode {
    u32 vt;          // 0
    u32 manager;     // 4 (TASK_MANAGER*)
    u8 f8;           // 8
    u8 pad9[11];
    u32 f14, f18, f1c;
    void* setup;     // 32
    void* ensure;    // 36
    u32 f28;         // 40
    TitleMode() {
        manager = 0; f1c = 0; setup = 0; ensure = 0;
        f28 = 0x1000; f8 = 84; f18 = 0x1fbd0; f14 = 1;
        vt = (u32)&D_0032b930;
    }
};

struct TitleSave { u8 b[8]; };


TitleMode D_0032b9a0;
Allocator* D_0032b9cc = 0;
TitleSave D_0032b9d0 = {{0}};
union TitleFlags {
    s32 w;
    struct {
        u32 active : 1;
        u32 bit1 : 1;
        u32 bit2 : 1;
        u32 bit3 : 1;
    } b;
};
TitleFlags D_0032b9d8 __attribute__((aligned(4))) = {1};  // title flags
s8 D_0032b9dc = 0;

extern "C" {
void func_0014df98(void);
void func_0014e140(s32, s32, s32);
void func_00167ea8(void);
u32 func_00170b30(u32);
Allocator* func_00106178(u32, u32);
void func_00168548(const char*, s32, s32);
s32 func_001688b8(void);
void func_00102448(TASK*, s32);  // Tz::TaskYield
void func_003058a0(u32);  // FlushCache
void func_01f18014(u32, void*);
void func_00170c00(Allocator*);
void func_00170320(u32);
void func_002fde18(void*, s32, u32);  // memset
u32 func_00102788(u32, s32, s32, void*);  // TASK_MANAGER::create_task
u32 func_00102818(u32, s32, s32, void*, u32);
}

namespace TITLE {

void Setup(TASK* t) {
    func_0014df98();
    func_0014e140(0, 0, 0);
    func_00167ea8();
    D_0032b9cc = func_00106178(func_00170b30(0x400000), 0x400000);
    func_00168548("ovl_title.x", 0, 0);
    while (func_001688b8()) func_00102448(t, 0);
    func_003058a0(2);
    D_0032b9dc = 1;
    func_01f18014(0, &D_0032b9a0);
}

void Ensure(TASK*) {
    func_003058a0(2);
    func_01f18014(1, &D_0032b9a0);
    Allocator* a = D_0032b9cc;
    D_0032b9dc = 0;
    func_00170c00(a);
    func_00170320(0);
    D_0032b9cc = 0;
}

}  // namespace TITLE

extern "C" {

void func_00102e18(void) {
    D_0032b9a0.setup = (void*)TITLE::Setup;
    D_0032b9a0.ensure = (void*)TITLE::Ensure;
}

void func_00102e40(void) {
    D_0032b9d8.w |= 1;
    D_0032b9d8.w &= ~4;
    D_0032b9d8.w &= ~8;
    D_0032b9d8.w &= ~16;
    func_002fde18(&D_0032b9d0, 0, sizeof(D_0032b9d0));
}

Allocator* func_00102e90(void) { return D_0032b9cc; }

void* func_00102ea0(u32 size) {
    return D_0032b9cc->vt->alloc(D_0032b9cc, size, __builtin_return_address(0));
}

void func_00102ed8(void* p) {
    D_0032b9cc->vt->free(D_0032b9cc, p);
}

u32 func_00102f08(s32 a, s32 b, void* fn) {
    return func_00102788(D_0032b9a0.manager, a, b, fn);
}

u32 func_00102f38(s32 a, s32 b, void* fn, u32 d) {
    return func_00102818(D_0032b9a0.manager, a, b, fn, d);
}

u32 func_00102f70(void) { return D_0032b9d8.w & 1; }
void func_00102f80(void) { D_0032b9d8.w &= ~1; }
s32 func_00102f98(void) { return 1; }
s32 func_00102fa0(void) { return D_0032b9dc != 0; }
void func_00102fb0(TitleSave* p) { D_0032b9d0 = *p; }
void func_00102fd0(TitleSave* p) { *p = D_0032b9d0; }
void func_00102ff0(u8 on) { D_0032b9d8.b.bit2 = on != 0; }
void func_00103018(u8 on) { D_0032b9d8.b.bit3 = on != 0; }
u32 func_00103040(void) { return (D_0032b9d8.w >> 2) & 1; }
u32 func_00103058(void) { return (D_0032b9d8.w >> 3) & 1; }

}

TitleMode* getTitleMode() {
    return &D_0032b9a0;
}
