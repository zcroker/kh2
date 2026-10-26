#include "../common/types.h"
extern "C" {
struct V2cfb30 {
    f32 x, y, z, w;
    V2cfb30() {}
    V2cfb30(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
} __attribute__((aligned(16)));
struct Obj2cfb30 { u8 pad[1416]; u32 flags; u8 pad2[2800 - 1420]; u8 lflag[32]; s32 balloons; };
struct Ref2cfb30 { u8 pad[16]; u16* id; u8 pad2[16]; s32 refs; };
struct Item2cfb30 { s32 kind; f32 px, py, pz; f32 rx, ry, rz; };
struct Ent2cfb30 {
    s32 id;
    u8 lflag[4];
    s32 arg;
    Item2cfb30* item;
    u8 pad[8];
    Ref2cfb30* ref0;
    Ref2cfb30* ref1;
    f32 timer;
    u8 pad2[4];
};
struct Cnt2cfb30 { s32 n; Ent2cfb30* ent; s32 spawned; };
struct Game2cfb30;
struct Game2cfb30Vt { void* f[6]; s32 (*check)(Game2cfb30*, Ent2cfb30*); };
struct Game2cfb30 { Game2cfb30Vt* vt; u8 pad[88]; s32 table; };
struct Rec2cfb30 { u8 pad[16]; s16 time; };
extern s32 D_00361fa0;
extern Ent2cfb30* D_00361fa4;
extern s32 D_00361fa8;
extern Game2cfb30* D_00361f60;
extern f32 D_00349e10;
s32 g2cfb30_be_ready(void) asm("_ZN2Ti8MiniGame8be_readyEv");
s32 g2cfb30_IsExec(void) asm("_ZN2YS5EVENT6IsExecEv");
Obj2cfb30* g2cfb30_next(Obj2cfb30*) asm("_Z16ctarget_001b9bc8jjjj");
s32 g2cfb30_is_ghost(Obj2cfb30*) asm("_ZN2YS3OBJ8is_ghostEv");
s32 g2cfb30_check(void*, u32) asm("_ZN2Ti5LFlag5checkEj");
void g2cfb30_set(void*, u32, s32) asm("_Z16wtarget_002cf280jjjj");
Obj2cfb30* func_002cf4a8(Ent2cfb30*);
Obj2cfb30* func_0016f000(s32, V2cfb30*, f32);
void g2cfb30_set_balloon(Obj2cfb30*, Obj2cfb30*) asm("_ZN2Ti18MGHachimitsuGopher11set_balloonEPNS_5MGObjE");
void func_001cbcf0(V2cfb30*, V2cfb30*, s32);
s32 g2cfb30_type(void) asm("_ZN2Ti8MiniGame4typeEv");
Rec2cfb30* func_002e3260(s32, s32, u16);
s32 g2cfb30_001c0d38s(Obj2cfb30*, Obj2cfb30*, s32, s32) asm("_Z16u_tail4_001c0d38jjjj");
void func_002cfb30(void)
{
    if (!g2cfb30_be_ready() || g2cfb30_IsExec()) return;
    Obj2cfb30* o = 0;
    while ((o = g2cfb30_next(o)) != 0) {
        if ((o->flags & 0x08000000) && g2cfb30_is_ghost(o) && g2cfb30_check(o->lflag, 0x1000)) {
            if (o->balloons > 0) o->balloons--;
        }
    }
    for (s32 i = 0; i < D_00361fa0; i++) {
        Ent2cfb30* e = &D_00361fa4[i];
        if (!e->id) continue;
        if (!e->item) continue;
        if (g2cfb30_check(e->lflag, 2)) continue;
        s32 fire = 0;
        if (g2cfb30_check(e->lflag, 64)) {
            e->timer -= D_00349e10;
            if (e->timer <= 0.0f) fire = 1;
        } else if (D_00361f60->vt->check(D_00361f60, e)) {
            fire = 1;
            if (g2cfb30_type() == 0 || g2cfb30_type() == 2) {
                Ref2cfb30* r = e->ref0;
                if (r) {
                    Rec2cfb30* rec = func_002e3260(D_00361f60->table, e->id, *r->id);
                    if (rec && rec->time > 0) {
                        fire = 0;
                        g2cfb30_set(e->lflag, 64, 0);
                        e->timer = rec->time * 60.0f;
                    }
                }
            }
        }
        if (!fire) continue;
        if (g2cfb30_check(e->lflag, 4)) {
            V2cfb30 pos(e->item->px, e->item->py, e->item->pz, 0.0f);
            V2cfb30 rot(e->item->rx, -e->item->ry, -e->item->rz, 0.0f);
            func_001cbcf0(&pos, &rot, e->arg);
        } else {
            Obj2cfb30* owner = func_002cf4a8(e);
            if (e->item->kind == 1631) {
                V2cfb30 z(0.0f, 0.0f, 0.0f, 0.0f);
                Obj2cfb30* b = func_0016f000(1634, &z, 0.0f);
                g2cfb30_001c0d38s(b, owner, 0x4000, 0);
                g2cfb30_set_balloon(owner, b);
                D_00361fa8++;
                g2cfb30_set(owner->lflag, 64, 0);
                g2cfb30_set(b->lflag, 64, 0);
            }
        }
        g2cfb30_set(e->lflag, 2, 0);
        if (e->ref0) e->ref0->refs--;
        if (e->ref1) e->ref1->refs--;
    }
}
}
