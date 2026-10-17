#include "../common/types.h"

struct W1626ScriptData {
    u8 type;            // 0x00
    u8 lenUnit;         // 0x01
    u8 pad02[0x24];
    u16 id;             // 0x26
    s16 motA;           // 0x28
    s16 blendA;         // 0x2a
    s16 motB;           // 0x2c
    s16 blendB;         // 0x2e
    s16 motC;           // 0x30
    s16 blendC;         // 0x32
    s8 seA;             // 0x34
    s8 seB;             // 0x35
    s8 seC;             // 0x36
};

struct W1626ScriptEntry {
    u32 m00;
    void* script;       // 0x04
    u32 m08;
    u8 arg0c[0x1c];     // 0x0c
    W1626ScriptData* data; // 0x28
};

struct W1626VObj;
struct W1626VObjVt {
    void* f[24];
};
struct W1626Sub {
    void** vt;
};
struct W1626Tune {
    u8 pad[0x48];
    f32 blendNormal;    // 0x48
    u8 pad4c[0xd0 - 0x4c];
    f32 blendSpecial;   // 0xd0
};
struct W1626Ability {
    u8 pad[0xc];
    u32 flags;          // 0x0c
};
struct W1626VObj {
    W1626VObjVt* vt;
    u8 pad04[8];
    W1626Sub* sub;      // 0x0c
    u8 pad10[0x140 - 0x10];
    u8 motion[0x448];   // 0x140
    u32 flags;          // 0x588
    u8 pad58c[0x9f4 - 0x58c];
    W1626VObj* target;  // 0x9f4
    u8 pad9f8[0xb50 - 0x9f8];
    s32 form;           // 0xb50
};
struct W1626Task {
    u32 vm;
};

extern "C" {
extern W1626ScriptEntry D_00350800[6];
extern W1626Tune* D_00352130;
extern f32 D_0036d5c0;

W1626Ability* W1626_get_ability(W1626VObj*) asm("_ZN2YS5PARTY11get_abilityEv");
void func_0017a600(W1626VObj*);
s32 func_0019c090(W1626VObj*);
void W1626_motion_set(void*, s32, f32, f32) asm("func_0017f488");
void W1626_motion_push(void*, s32, f32, f32, void*) asm("_ZN2YS6MOTION4pushEiffPFvPNS_3OBJEE");
W1626Task* W1626_area_alloc(u32) asm("_ZN4AREA5AllocEj");
u32 W1626_vm_start(void*, W1626VObj*) asm("_ZN2YS2VM5StartEPvPNS_3OBJE");
void func_001a5c48(W1626Task*, u32, W1626VObj*);
u32 func_001ce350(s32);
void W1626_vm_call(u32, s32, u32*, s32) asm("_ZN2YS2VM4callEiP8BD_VALUEi");

W1626Task* func_001a6178(W1626VObj* obj, s32 id, u8 alt)
{
    u32 args[4];
    W1626ScriptEntry* e = D_00350800;
    W1626ScriptData* d = 0;
    s32 i;
    s32 base;
    s32 len;
    s8 se;
    W1626Task* t;

    for (i = 0; i < 6; i++, e++) {
        if (e->data != 0 && e->data->id == id) {
            d = e->data;
            break;
        }
    }
    if (W1626_get_ability(obj)->flags & 0x80000) {
        switch (d->type) {
        case 0: case 1: case 2: case 4:
            func_0017a600(obj);
            break;
        }
    }
    se = d->seA;
    base = d->lenUnit * 2;
    len = base - 2;
    if (func_0019c090(obj) != 0) {
        if ((obj->flags & 0x80) && obj->form == 7) {
            ((void (*)(W1626Sub*, W1626VObj*, f32))obj->sub->vt[3])(obj->sub, obj, D_00352130->blendSpecial);
        } else {
            ((void (*)(W1626Sub*, W1626VObj*, f32))obj->sub->vt[3])(obj->sub, obj, D_00352130->blendNormal);
        }
        W1626_motion_set(obj->motion, d->motC, d->blendC, 0.0f);
        W1626_motion_push(obj->motion, 4, 8.0f, 0.0f, 0);
    } else {
        if (alt && d->motB >= 0) {
            len = base - 1;
            W1626_motion_set(obj->motion, d->motB, d->blendB, 0.0f);
            se = d->seB;
        } else {
            W1626_motion_set(obj->motion, d->motA, d->blendA, 0.0f);
        }
        W1626_motion_push(obj->motion, 0, 0.0f, 0.0f, 0);
    }
    if (obj->target == obj) {
        se = d->seC;
    }
    if (se >= 0) {
        ((void (*)(W1626VObj*, s32, s32))obj->vt->f[21])(obj, se, 0);
    }
    if (obj->flags & 0x80) {
        switch (obj->form) {
        case 2: len += 10; break;
        case 5: len += 30; break;
        case 4: len += 20; break;
        }
    }
    t = W1626_area_alloc(16);
    func_001a5c48(t, W1626_vm_start(e->script, obj), obj);
    args[0] = (u32)obj;
    args[1] = (u32)e->arg0c;
    args[2] = len;
    args[3] = func_001ce350(len);
    W1626_vm_call(t->vm, 20, args, 4);
    return t;
}
}
