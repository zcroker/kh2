#include "../common/types.h"

extern "C" {

struct Node139 { u32 f0; Node139* next; u8 pad8[8]; s32 id; };
struct List139 { u32 f0; Node139* head; };
extern List139* D_00347f80;
static inline Node139* nextNode(Node139* o) {
    List139* l = D_00347f80;
    if (!o) return l->head;
    return o->next;
}
void hide139(Node139*) asm("_ZN2dk5Obj2D4hideEv");
void lshow139(Node139*) asm("_ZN2dk5Obj2D9localShowEv");
void func_001396d0(Node139*);
void func_001396e0(Node139*);
void func_00139718(Node139*);
void func_001398d0_i(s32 id) asm("_Z13func_001398d0i");
void func_001398d0_i(s32 id) {
    Node139* o = 0;
    while ((o = nextNode(o)) != 0)
        if (o->id == id) hide139(o);
}
void func_00139948(s32 id) {
    Node139* o = 0;
    while ((o = nextNode(o)) != 0)
        if (o->id == id) lshow139(o);
}
void func_00139a38(s32 id) {
    Node139* o = 0;
    while ((o = nextNode(o)) != 0)
        if (o->id == id) func_001396d0(o);
}
void func_00139ab0(s32 id) {
    Node139* o = 0;
    while ((o = nextNode(o)) != 0)
        if (o->id == id) func_001396e0(o);
}
void func_00139ba0(s32 id) {
    Node139* o = 0;
    while ((o = nextNode(o)) != 0)
        if (o->id == id) func_00139718(o);
}


s32 func_001948c0(s32, s32);
void func_0013a690_x(void) asm("_ZN2dk8Field2DD16ensureMonochromeEv");
void func_0013a9e8(s32);
void destroyAll(void) asm("_ZN2YS10CACHE_BUFF10DestroyAllEv");
extern s32 D_00347ff8;
extern u8 D_00347ffc;
static inline s32 conv2(s32 v) { if (v == 0xffff) v = -1; return v; }
void func_0013a958(u8* p) {
    bool ok = func_001948c0(conv2(p[1]), conv2(p[0]));
    if (D_00347ff8 == 1 && !ok) { func_0013a690_x(); func_0013a9e8(1); destroyAll(); }
    D_00347ffc = 0;
}
}
