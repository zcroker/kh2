#include "../common/types.h"
// Built by the original with debug info (-g): see Makefile rule for *_g.cpp.
extern "C" {
extern s32 D_0035f01c;

void func_00287bc0(void);
s32 func_0028b040(s32);
u32 func_00272b60(s32);
u16* func_00273140(s32);
s32 func_00286068(u32);
void func_00286280(u32);
void func_00272ae0(void) {
    func_00287bc0();
    s32 v = func_0028b040(D_0035f01c);
    if (func_00272b60(v) < 2) {
        u16* r = func_00273140(v);
        if (r) {
            u32 id = *r;
            if (func_00286068(id)) {
                func_00286280(id);
            }
        }
    }
}
}
struct E36 { u8 pad[18]; u16 id; u8 pad2[16]; };
struct Tbl { E36* e; };
extern Tbl* D_0035f6cc;
extern "C" {
s32 func_00240ba0(void);
void func_002b4dd0(s32);
void func_002b5108(s32, s32);
void func_0028f4d8(s32, u32, s32);
void func_00287d20(s32);
void func_00234570(s32, s32);
void func_002b4c10(void) {
    s32 i = func_00240ba0();
    func_002b4dd0(-1);
    func_002b5108(0x8a89, i);
    func_0028f4d8(1, D_0035f6cc->e[i].id, 0);
    func_00287d20(0);
    func_00234570(i, 0);
}
}
