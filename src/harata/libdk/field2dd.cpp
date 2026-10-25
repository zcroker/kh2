#include "field2dd.hpp"

// dk::Field2DD (0x13a368-0x13a8b8): loads the field's 2D-demo files (field2d/<room>/...2dd)
// and keeps their image/sequence tables.

struct Entry2DD {
    u32 imd;  // 0
    u32 sqd;  // 4
};

template <int N>
struct Table2DD {
    u32 res;
    s32 count;
    Entry2DD e[N];
    Table2DD() : res(0), count(0) {
        for (s32 i = 0; i < N; i++) {
            e[i].imd = 0;
            e[i].sqd = 0;
        }
    }
};

Table2DD<4> D_00347fb0;     // field demo images and sequences
Table2DD<1> D_00347fd8;     // command demo
u32 D_00347fe8 = (u32)-1;   // language of the loaded field files
u32 D_00347fec = (u32)-1;   // room of the loaded command file
s32 D_00347ff0 = -1;        // chapter of the loaded command file
u8 D_00347ff4 = 0;          // command demo pending

extern "C" {
extern u8 D_003b8b80[];  // field file name
extern char D_003b8ba0[];  // command file name
extern u8 D_003b8bc0[];  // field file buffer
extern u8 D_004193c0[];  // command file buffer
extern char* D_0033caf4;
extern u8 D_0032bae0;
u32 func_00168aa0(void*, s32);
u8* func_00168b38(void*, s32, s32);  // entry_array_find_nth
s32 func_0013d498(void);
void func_0013b3f8(void);
void func_0013b538(void);
s32 func_00242ea8(void);
s32 func_0014a1f0(void);
s32 func_00242c70(void) asm("_ZN2Tz6Config12isCommandKH2Ev");
s32 func_00194a08(void);
u32 func_00105ee8(u32);
void func_002fee78(char*, const char*, ...);  // sprintf
void func_002ff3fc(char*);  // strlen
void func_001688c8(void*);
void func_001684c0(void*, u8*, s32, s32);
void func_0031ae58(void*, void*);

void func_0013a4a8(void);
s32 func_0013a4c8(void);
void func_0013a6b8(void);

// Builds the command demo table from the (25, 24) resource entries of the command file.
void func_0013a368(void) {
    s32 i;
    D_00347fd8.res = (u32)D_004193c0;
    D_00347fd8.count = func_00168aa0(D_004193c0, 25);
    for (i = 0; i < D_00347fd8.count; i++) {
        D_00347fd8.e[i].sqd = *(u32*)(func_00168b38((void*)D_00347fd8.res, 25, i) + 8);
        if (func_00168b38((void*)D_00347fd8.res, 24, 0))
            D_00347fd8.e[i].imd = *(u32*)(func_00168b38((void*)D_00347fd8.res, 24, i) + 8);
        else
            D_00347fd8.e[i].imd = 0;
    }
    if (func_0013d498()) return;
    func_0013b3f8();
    func_0013a4a8();
}

}

namespace dk {

void Field2DD::readConfigCommand() {
    if (func_0013a4c8()) {
        if (!func_0013d498()) {
            D_00347ff4 = 1;
            func_0013b538();
        }
    }
}

}  // namespace dk

extern "C" {

void func_0013a4a8(void) { D_00347ff4 = 0; }
u8 func_0013a4b8(void) { return D_00347ff4; }

// Loads the command demo file of the current room and chapter when it changed.
s32 func_0013a4c8(void) {
    if (func_00242ea8()) return 0;
    if (func_0014a1f0()) return 0;
    if (!func_00242c70()) {
        if (!D_00347fec) return 0;
        D_00347fec = 0;
        D_00347ff0 = -1;
        func_002fee78(D_003b8ba0, "field2d/%s/zz0command.2dd", D_0033caf4);
    } else {
        u32 room = D_0032bae0;
        s32 n = func_00194a08();
        if (room == D_00347fec && n == D_00347ff0) return 0;
        D_00347ff0 = n;
        D_00347fec = room;
        func_002fee78(D_003b8ba0, "field2d/%s/%s%1dcommand.2dd", D_0033caf4, func_00105ee8(room), n);
    }
    func_002ff3fc(D_003b8ba0);
    func_001688c8(D_003b8ba0);
    func_001684c0(D_003b8ba0, D_004193c0, 0, 0);
    return 1;
}

// Loads the field demo file for the current language when it changed.
void func_0013a600(void) {
    u32 v = D_0032bae0;
    if (v == D_00347fe8) return;
    D_00347fe8 = v;
    func_002fee78((char*)D_003b8b80, "field2d/%s/%s0field.2dd", D_0033caf4, func_00105ee8(v));
    func_001688c8(D_003b8b80);
    func_001684c0(D_003b8b80, D_003b8bc0, 0, 0);
}

}

namespace dk {

void Field2DD::ensureMonochrome() {
    if (!func_00242c70()) func_0013a6b8();
}

}  // namespace dk

extern "C" {

void func_0013a6b8(void) {
    D_00347fec = (u32)-1;
    D_00347ff0 = -1;
}

void func_0013a6d0(void) {
    D_00347fe8 = (u32)-1;
    func_0013a6b8();
    func_0013a4a8();
}

// Builds the field demo table from the (25, 24) resource entries of the field file.
void func_0013a6f8(void) {
    D_00347fb0.res = (u32)D_003b8bc0;
    D_00347fb0.count = func_00168aa0(D_003b8bc0, 25);
    for (s32 i = 0; i < D_00347fb0.count; i++) {
        D_00347fb0.e[i].sqd = *(u32*)(func_00168b38((void*)D_00347fb0.res, 25, i) + 8);
        if (func_00168b38((void*)D_00347fb0.res, 24, 0))
            D_00347fb0.e[i].imd = *(u32*)(func_00168b38((void*)D_00347fb0.res, 24, i) + 8);
        else
            D_00347fb0.e[i].imd = 0;
    }
    func_0031ae58(&D_00347fd8, D_004193c0);
}

}

namespace dk {

u32 Field2DD::getImd(s32 index) { return D_00347fb0.e[index].imd; }
u32 Field2DD::getSqd(s32 index) { return D_00347fb0.e[index].sqd; }

}  // namespace dk

extern "C" u32 func_0013a800(void) { return D_00347fd8.e[0].imd; }

namespace dk {

u32 Field2DD::getSqdCommand() { return D_00347fd8.e[0].sqd; }

}  // namespace dk
