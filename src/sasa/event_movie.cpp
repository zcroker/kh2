// sa::EVENT movie playback (event_movie). Linked unit 0x22ba08-0x22bda0.
#include "../common/types.h"

extern "C" {
u32 func_002bbed0(u32);
void func_0014a4b0(void);
void func_0015e038(void);
void func_002ef6b0(void);
void func_002ef750(void);
s32 func_002ef7b8(void);
s32 func_0014a1f0(void);
void func_00102448(u32, s32);
void func_0022d6d8(void);
void func_001ddb58(void);
void func_00143268(void);
void func_001024a8(u32, s32);
s32 func_002ef7a0(s32, void*);
void func_0014d910(s32);
u64* func_00167f18(s32);
s32 func_00225e48(void);
void func_00225e28(void);
u32 func_0014abd8(void);
void func_0014aa58(u32, s32, s32);
void func_0014aa80(u32, s32, s32);
void func_002ef708(void);
void func_0014a1e0(void);
void func_001ddb68(void);
s32 func_002282f0(s32);
s32 func_00225b00(s32);
void func_00226ed0(void);
void func_002fee78(char*, const char*, ...);  // sprintf
s32 func_002ff538(const char*, const char*, s32);  // strncmp
void func_002ff3fc(char*);
void func_00102c18(s32, s32, void*);
}

extern s32 D_0035de20;
extern u32 D_0033caf0;
u8 D_0035e2ec;

struct Obj48 { u8 pad[4]; s16 id; char name[1]; };

void func_0022ba08(u32 a0, u32 a1) {
    func_002bbed0(a0);
    func_0014a4b0();
    func_0015e038();
    func_002ef6b0();
    func_002ef750();
    while (1) {
        if (func_002ef7b8() != 0) {
            break;
        }
        func_0014a1f0();
        func_00102448(a1, 0);
    }
    func_0022d6d8();
    func_001ddb58();
    func_00143268();
}

void func_0022ba88(u32 a0) {
    if (func_002ef7b8() == 0) {
        func_001024a8(a0, 0);
        return;
    }
    s32 p = func_002ef7a0(6, 0);
    if (p == 0) {
        return;
    }
    func_0014d910(p);
    if (func_0014a1f0() == 0) {
        return;
    }
    u64* q = func_00167f18(0);
    if (D_0035de20 < 10) {
        return;
    }
    if (*q == 0) {
        return;
    }
    if (func_00225e48() != 0) {
        return;
    }
    func_00225e28();
}

s32 func_0022bb38(void) { return func_002ef7a0(5, 0) == 5; }

void func_0022bb60(void* p) {
    if (p && func_002ef7b8()) {
        func_0014aa58(func_0014abd8(), 0, 0);
        func_002ef7a0(2, p);
    }
}

void func_0022bbc8() {
    if (func_002ef7b8() != 0) {
        func_002ef708();
        func_0014a1e0();
        func_001ddb68();
    }
}

void func_0022bd80(void);

void func_0022bc08(Obj48* o, u32 w) {
    if (func_002282f0(o->id)) return;
    if (func_00225b00(o->id)) return;
    char* name = o->name;
    func_0014aa58(func_0014abd8(), 0, 0);
    func_00226ed0();
    char buf[48];
    func_002fee78(buf, "zmovie/%s/%s.pss", D_0033caf0, name);
    func_0022bd80();
    if (!func_002ff538(name, "sec", 3) || !func_002ff538(name, "sec2", 4)) D_0035e2ec = 1;
    func_002ff3fc(buf);
    func_002ef7a0(0, buf);
    while (func_002ef7a0(5, 0) != 2) {
        func_0014a1f0();
        func_00102448(w, 0);
    }
    while (func_002ef7a0(1, 0)) {
        func_0014a1f0();
        func_00102448(w, 0);
    }
    func_0014aa80(func_0014abd8(), 0, 0);
    func_00102c18(1, 0x16f30, (void*)func_0022ba88);
}

void func_0022bd80(void) { D_0035e2ec = 0; }

u32 func_0022bd90(void) { return D_0035e2ec; }
