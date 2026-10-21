#include "../common/types.h"
struct Dat838 { u8 pad0[8]; u8 x8; u8 x9; u16 xa; u8 xc; u8 pad0d[3]; s32 x10; u8 pad14[8]; u8 sub1c[4]; };
struct Prm838 { u8 pad0[8]; s32 x8; };
struct Unit838 { u16 x0; u8 pad2[0x16]; s32 x18; };
struct Sub838 { u8 pad0[0x14]; s32 x14; s32 x18; };
struct Obj838 { s32 x0; u8 pad4[4]; Dat838* data; u8 sub2[0x3c]; s32 x48; Sub838 sub3; u8 pad[0x2cc - 0x4c - sizeof(Sub838)]; s32 x2cc; };
struct Lv838 { u8 pad0[2]; u8 lv; u8 pad3[3]; u16 x6; };
extern "C" {
extern Lv838 D_0032bae0;
extern char D_001bb220[];
void func_001bb2c8(void*);
void func_001db610(void*, void (*)(void*), void*);
Prm838* func_00168b38(s32, s32, s32);
s32 func_00196908(s32);
void eff_1dddd0_1971(void*, s32) asm("_Z16wtarget_001dddd0jjjj");
Unit838* func_001c1130(u8);
s32 tail4_192048_1971(u16) asm("_Z16u_tail4_00192048jjjj");
s32 func_001bbb50(void);
void func_001ada38(s32);
u64 iscol_1971(void) asm("_ZNK2YS13MISSION_TABLE12is_colosseumEv");
s32 func_001d5668(u8);
void func_001d5698(u8);
void func_001bba30(Obj838*);
void func_001bbe18(s32);
void func_001d5518(void*, void*, s32);
void func_001d7218(s32);
void* createtask_1971(s32, s32, void (*)(void*)) asm("_ZN5FIELD10CreateTaskEiiPFvP4TASKE");
void func_001bb958(s32);
static inline bool has838(Prm838* p) { return p && p->x8 != 0; }
void func_001bae38(Obj838* o)
{
    func_001db610(o->data->sub1c, func_001bb2c8, o);
    Prm838* p = func_00168b38(o->x48, 3, 0);
    if (has838(p)) o->x2cc = func_00196908(p->x8);
    p = func_00168b38(o->x48, 18, 0);
    if (has838(p)) eff_1dddd0_1971(o->sub2, p->x8);
    if (o->data->x8) {
        Unit838* u = func_001c1130(o->data->x8);
        if (o->data->xa) u->x18 = tail4_192048_1971(o->data->xa);
        if (func_001bbb50() || u->x0 == 0x23) func_001ada38(9);
        if (iscol_1971()) {
            s32 max = D_0032bae0.x6 != 0xc4 ? 10 : 50;
            u8 lv = D_0032bae0.lv;
            if (lv == max) { Sub838* s3 = &o->sub3; s3->x14 = 3; }
            else if (lv == max - 1) { Sub838* s3 = &o->sub3; s3->x14 = 4; }
            else { Sub838* s3 = &o->sub3; s3->x18 = lv; }
        }
    }
    if (o->data->xc) {
        if (!func_001d5668(o->data->x9)) {
            func_001d5698(o->data->x9);
            func_001bba30(o);
        }
    }
    func_001bbe18(o->data->x10);
    func_001d5518(&o->sub3, o->sub2, 0);
    func_001d7218(o->x0);
    createtask_1971(1, 14000, (void (*)(void*))D_001bb220);
    func_001bb958(0);
}
}
