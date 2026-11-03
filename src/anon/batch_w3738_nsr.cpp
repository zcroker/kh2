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
void func_002bed48(MsgWidget*, s32, u32);
void func_002edfa8(void*, MsgWidget*);
void func_002edfd8(void*, MsgWidget*);
s32 func_002befa8(MsgWidget*);
void func_002be020(Libretto*, u32, u32);
void func_002be4b0(Libretto*);
void func_0016ed50(u32, s32, s32);
void func_002be960(Libretto*);
void func_002be9b0(void);
void func_002bc1e8(s32);
void func_002c0130(f32, Vec4*, Vec4*);
void func_002be520(Libretto*);
void func_002be568(Libretto*, u32);
void func_002be190(Libretto*, u32, u32*, s32);
void func_002be258(Libretto*, u32, u32*, s32);
void func_002be0b0(Libretto*, u32);
void func_002c2168(Vec4*);
void func_002c20f8(Vec4*);
void func_002be318(Libretto*, u32, Vec4*);
void func_002be2d8(Libretto*, u32, Vec4*);
void func_002be630(Libretto*);
void func_00199718(Area*, u32, u32);
void func_00104f58(Area*, u32, s32, s32, s32);
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

u32 wtarget_002bdb70(Libretto* self, LibCmd* cmd, u32 a2, u32 a3) asm("_Z16wtarget_002bdb70jjjj");
u32 wtarget_002bdb70(Libretto* self, LibCmd* cmd_, u32 a2, u32 a3)
{
    register LibCmd* cmd asm("$17") = cmd_; // pin: original keeps cmd in s1, self in s0
    u32 task = self->owner->task;
    union {
        Vec4 v[2];
        Area area;
    } u;

    switch (cmd->id) {
    case 1: {
        MsgWidget* w = func_001050d8(44);
        func_002bed48(w, self->flag, cmd->args[0]);
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
                func_0016ed50(((u32*)cmd)[i] | 0x40000000, -200, 30);
            } while (i < cmd->count);
        }
        break;
    }
    case 0x101:
        func_002be4b0(self);
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
        func_002be0b0(self, cmd->args[0]);
        break;
    case 0x10e: {
        Area_set(&u.area, cmd->args[0], cmd->args[1], 0, 0xffff);
        func_00104f58(&u.area, 0x80000001, 0, 0, 0);
        break;
    }
    case 0x10f: {
        func_00199718(&u.area, cmd->args[1], cmd->args[0]);
        func_00104f58(&u.area, 0x80000001, 0, 0, 0);
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
}
