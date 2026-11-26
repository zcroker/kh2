#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../tozawa/menu_sound.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../worldmap/libretto.hpp"
#include "../worldmap/rootwindow.hpp"
#include "../worldmap/messagewidget.hpp"
#include "../ohori/sebank.hpp"

// ---- 002bdb70 from src/anon/batch_w3738_nsr.cpp
namespace n002bdb70 {
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
    LibTask* owner;          
    u8 widgets[52];          
    s32 flag;                
};
struct MsgWidget {
    void** vt;
};
void func_00102448(u32, s32) asm("func_00102448");
void func_00102470(f32, u32) asm("func_00102470");
MsgWidget* func_001050d8(s32) asm("func_001050d8");
void worldmap__MessageWidget__MessageWidget(MsgWidget*, s32, u32) asm("worldmap__MessageWidget__MessageWidget");
void func_002edfa8(void*, MsgWidget*) asm("func_002edfa8");
void func_002edfd8(void*, MsgWidget*) asm("func_002edfd8");
s32 func_002befa8(MsgWidget*) asm("func_002befa8");
void func_002be020(Libretto*, u32, u32) asm("func_002be020");
void worldmap__Libretto__flush(Libretto*) asm("worldmap__Libretto__flush");
void YS__OBJENTRY__ReadRequest(u32, s32, s32) asm("YS__OBJENTRY__ReadRequest");
void func_002be960(Libretto*) asm("func_002be960");
void func_002be9b0(void) asm("func_002be9b0");
void func_002bc1e8(s32) asm("func_002bc1e8");
void func_002c0130(f32, Vec4*, Vec4*) asm("func_002c0130");
void func_002be520(Libretto*) asm("func_002be520");
void func_002be568(Libretto*, u32) asm("func_002be568");
void func_002be190(Libretto*, u32, u32*, s32) asm("func_002be190");
void func_002be258(Libretto*, u32, u32*, s32) asm("func_002be258");
void worldmap__Libretto__leaveObj(Libretto*, u32) asm("worldmap__Libretto__leaveObj");
void func_002c2168(Vec4*) asm("func_002c2168");
void func_002c20f8(Vec4*) asm("func_002c20f8");
void func_002be318(Libretto*, u32, Vec4*) asm("func_002be318");
void func_002be2d8(Libretto*, u32, Vec4*) asm("func_002be2d8");
void func_002be630(Libretto*) asm("func_002be630");
void func_00199718(Area*, u32, u32) asm("func_00199718");
void AREA__MapJump(Area*, u32, s32, s32, s32) asm("AREA__MapJump");
void func_002be148(Libretto*) asm("func_002be148");
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
u32 worldmap__Libretto__parse(Libretto* self, LibCmd* cmd_, u32 a2, u32 a3)
{
    register LibCmd* cmd asm("$17") = cmd_;                                             
    u32 task = self->owner->task;
    union {
        Vec4 v[2];
        Area area;
    } u;

    switch (cmd->id) {
    case 1: {
        MsgWidget* w = func_001050d8(44);
        worldmap__MessageWidget__MessageWidget(w, self->flag, cmd->args[0]);
        func_002edfa8(self->widgets, w);
        while (!func_002befa8(w)) {
            func_00102448(task, 0);
        }
        func_002edfd8(self->widgets, w);
        if (w) {
            ((void (*)(MsgWidget*))w->vt[1])(w);
        }
        break;
    }
    case 0x100: {
        s32 i;
        if (cmd->count) {
            i = 0;
            do {
                i++;
                YS__OBJENTRY__ReadRequest(((u32*)cmd)[i] | 0x40000000, -200, 30);
            } while (i < cmd->count);
        }
        break;
    }
    case 0x101:
        worldmap__Libretto__flush(self);
        break;
    case 0x102: {
        u32 a = cmd->args[0];
        func_002be020(self, a, cmd->args[1]);
        break;
    }
    case 0x103:
        func_002be190(self, cmd->args[0], &cmd->args[1], cmd->count - 1);
        break;
    case 0x104: {
        f32 t = cmd->f[6];
        f32 l1 = cmd->f[1];
        f32 l2 = cmd->f[2];
        f32 l9 = 0.0f;
        f32 l3 = cmd->f[3];
        f32 l4 = cmd->f[4];
        f32 l5 = cmd->f[5];
        f32 l0 = cmd->f[0];
        Vec4_set(&u.v[0], l0, l1, l2, l9);
        Vec4_set(&u.v[1], l3, l4, l5, l9);
        func_002c0130(t, &u.v[0], &u.v[1]);
        func_00102470(t, task);
        break;
    }
    case 0x105:
        func_002be960(self);
        func_00102470(240.0f, task);
        func_002be9b0();
        func_002bc1e8(16008);
        func_00102470(90.0f, task);
        break;
    case 0x106:
        func_002be520(self);
        break;
    case 0x107:
        self->flag = 1;
        break;
    case 0x108:
        func_002be568(self, cmd->args[0]);
        break;
    case 0x109: {
        u32 id;
        u.v[0].x = cmd->f[1];
        u.v[0].y = cmd->f[2];
        u.v[0].z = cmd->f[3];
        id = cmd->args[0];
        *(u32*)&u.v[0].w = 0;
        func_002be2d8(self, id, &u.v[0]);
        break;
    }
    case 0x10a: {
        u32 id;
        u.v[0].x = cmd->f[1];
        u.v[0].y = cmd->f[2];
        u.v[0].z = cmd->f[3];
        id = cmd->args[0];
        *(u32*)&u.v[0].w = 0;
        func_002be318(self, id, &u.v[0]);
        break;
    }
    case 0x10b: {
        Vec3_set(&u.v[0], cmd->f[0], cmd->f[1], cmd->f[2]);
        func_002c20f8(&u.v[0]);
        break;
    }
    case 0x10c: {
        Vec3_set(&u.v[0], cmd->f[0], cmd->f[1], cmd->f[2]);
        func_002c2168(&u.v[0]);
        break;
    }
    case 0x10d:
        worldmap__Libretto__leaveObj(self, cmd->args[0]);
        break;
    case 0x10e: {
        Area_set(&u.area, cmd->args[0], cmd->args[1], 0, 0xffff);
        AREA__MapJump(&u.area, 0x80000001, 0, 0, 0);
        break;
    }
    case 0x10f: {
        func_00199718(&u.area, cmd->args[1], cmd->args[0]);
        AREA__MapJump(&u.area, 0x80000001, 0, 0, 0);
        break;
    }
    case 0x110:
        func_002be630(self);
        break;
    case 0x111:
        func_002be258(self, cmd->args[0], &cmd->args[1], cmd->count - 1);
        break;
    case 0x112:
        func_002be148(self);
        break;
    case 0x113:
        func_002be9b0();
        break;
    }
    return 1;
}
}  // namespace n002bdb70

