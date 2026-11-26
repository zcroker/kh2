// 002bdb70: worldmap Libretto command dispatcher. Built with -fno-strength-reduce (_nsr): the case 0x100 loop keeps
// its index (sll/addu each pass). One register pin (cmd in s1) fixes the self/cmd s-reg swap that flag causes.
#include "../common/types.h"
extern "C" {
struct Area {
    u8 world;
    u8 area;
    u8 entrance;
    u8 pad3;
    u16 layout;
    u16 event;
    u16 btl;
};
struct Vec4 {
    f32 x, y, z, w;
};
struct LibCmd {
    u16 id;
    u16 count;
    union {
        u32 args[7];
        f32 f[7];
    };
};
struct LibTask {
    u8 pad[16];
    u32 task;
};
struct Libretto {
    u8 pad0[4];
    LibTask* owner;   // 0x04
    u8 widgets[52];   // 0x08
    s32 flag;         // 0x3c
};
struct MsgWidget {
    void** vt;
};

void func_00102448(u32, s32);
void func_00102470(f32, u32);
MsgWidget* func_001050d8(s32);
void worldmap__MessageWidget__MessageWidget(MsgWidget*, s32, u32);
void func_002edfa8(void*, MsgWidget*);
void func_002edfd8(void*, MsgWidget*);
s32 func_002befa8(MsgWidget*);
void func_002be020(Libretto*, u32, u32);
void worldmap__Libretto__flush(Libretto*);
void YS__OBJENTRY__ReadRequest(u32, s32, s32);
void func_002be960(Libretto*);
void func_002be9b0(void);
void func_002bc1e8(s32);
void func_002c0130(f32, Vec4*, Vec4*);
void func_002be520(Libretto*);
void func_002be568(Libretto*, u32);
void func_002be190(Libretto*, u32, u32*, s32);
void func_002be258(Libretto*, u32, u32*, s32);
void worldmap__Libretto__leaveObj(Libretto*, u32);
void func_002c2168(Vec4*);
void func_002c20f8(Vec4*);
void func_002be318(Libretto*, u32, Vec4*);
void func_002be2d8(Libretto*, u32, Vec4*);
void func_002be630(Libretto*);
void func_00199718(Area*, u32, u32);
void AREA__MapJump(Area*, u32, s32, s32, s32);
void func_002be148(Libretto*);

static inline void Vec4_set(Vec4* v, f32 x, f32 y, f32 z, f32 w)
{
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
}

static inline void Vec3_set(Vec4* v, f32 x, f32 y, f32 z)
{
    v->x = x;
    v->y = y;
    v->z = z;
    *(u32*)&v->w = 0;
}

static inline void Area_set(Area* a, u32 w, u32 ar, u32 e, u32 v)
{
    a->world = w;
    a->area = ar;
    a->entrance = e;
    a->layout = v;
    a->event = v;
    a->btl = v;
}

u32 worldmap__Libretto__parse(Libretto* self, LibCmd* cmd, u32 a2, u32 a3) asm("_Z25worldmap__Libretto__parsejjjj");
// 0x002bdb70: definition moved into src/anon/unit_002bdb70.cpp
}
