#include "../common/types.h"

struct W8008Ent { u8 pad[8]; s32 f8; };
struct W8008Arg { s32 type; void* f4; };
struct W8008CD { u8 pad[7]; u8 num; };
static inline bool w8008_ok(W8008Ent* e) { return e && e->f8; }

struct W8008Obj;
struct W8008Vt { u8 pad[0x20]; void (*f20)(W8008Obj*); u8 pad2[0x78 - 0x24]; s32 (*f78)(W8008Obj*, s32, s32, s32); };
struct W8008Sub { s32 pad; s32 v; };
struct W8008Obj { W8008Vt* vt; u8 pad[0x140 - 4]; u8 mot[0x48c - 0x140]; W8008Sub* sub; };
struct W8008Sys { u8 pad[0x54]; f32 scale; };

extern "C" {
extern char D_0036d8b0[];
extern char D_0036e370[];
extern char D_0036e378[];
extern W8008Sys* D_00352130;
W8008CD* w8008_GetCharaData(u32) asm("_ZN2Tz6JmInfo12GetCharaDataEj");
s32 w8008_sprintf(char*, const char*, u32) asm("_Z16wtarget_002fee78jjjj");
W8008Ent* func_00168b38(void*, s32, s32);
W8008Ent* func_00168b88(s32, s32, s32, s32);
W8008Obj* w8008_StunEnd(void) asm("_ZN2YS6PLAYER7StunEndEv");
void w8008_motion_push(void*, s32, f32, f32, void*) asm("_ZN2YS6MOTION4pushEiffPFvPNS_3OBJEE");
void w8008_wt1987a8(W8008Obj*, char*, W8008Obj*) asm("_Z16wtarget_001987a8jjjj");
s32 func_00190570(W8008Obj*, W8008Obj*);
void func_00180378(void*, W8008Obj*, s32, f32);
void func_001ada38(s32);

s32 func_001af7c0(W8008Arg* a, u32 id)
{
    W8008CD* cd = w8008_GetCharaData(id);
    s32 k = 0;
    switch (a->type) {
    case 0: k = 0xfc; break;
    case 1: case 3: k = 0xfd; break;
    }
    W8008Ent* e = func_00168b38(a->f4, -1, k);
    if (!w8008_ok(e)) return 0;
    char buf[16];
    const char* fmt = D_0036d8b0;
    u8 num = cd->num;
    s32 h = e->f8;
    w8008_sprintf(buf, fmt, num);
    e = func_00168b88(h, -1, buf[0] | (buf[1] << 8) | (buf[2] << 16) | (buf[3] << 24), 2);
    if (!w8008_ok(e)) return 0;
    return func_00168b38((void*)e->f8, 9, 0)->f8;
}

void w8008_recov_holylight(W8008Obj* m) asm("_ZN2YS6MICKEY15recov_holylightEv");
void w8008_recov_holylight(W8008Obj* m)
{
    m->vt->f20(m);
    W8008Obj* p = w8008_StunEnd();
    func_00190570(m, p);
    func_00180378(m->mot, p, 253, 0.0f);
    w8008_motion_push(p->mot, 0, 0.0f, 0.0f, 0);
    w8008_wt1987a8(m, D_0036e370, p);
    func_001ada38(10);
}

s32 func_001d02c8(W8008Obj* self)
{
    self->vt->f20(self);
    W8008Obj* p = w8008_StunEnd();
    func_00190570(self, p);
    func_00180378(self->mot, p, 0xfe, 0.0f);
    w8008_motion_push(p->mot, 0, 0.0f, 0.0f, 0);
    w8008_wt1987a8(self, D_0036e378, p);
    return p->vt->f78(p, (s32)((f32)p->sub->v * D_00352130->scale), 0, 0);
}
}
