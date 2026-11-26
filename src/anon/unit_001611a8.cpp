// dk::BgObj, last part (0x1610c0-0x1614a8; bgobj.cpp has the first part up to 0x1610c0): the re-light
// loop over all objects (VU0 light set-up as in the ctor), colour, show flag, animation speed for every object, dk::BgObj::init (allocator, map file, the tasks), and
// the object lists with the file's static init.
#include "../common/types.h"

// ---- the object lists (the static init clears them)
struct BgList { void* head; void* tail; BgList() { tail = 0; head = 0; } };

static s32 D_004f3b30 asm("D_004f3b30");     // the draw task group
static BgList D_004f3b38 asm("D_004f3b38");  // all objects (link at +128)
static BgList D_004f3b40 asm("D_004f3b40");  // the draw list (link at +132)
static BgList D_004f3b48 asm("D_004f3b48");  // objects to destroy (link at +128)
extern u8 D_0034c740 asm("D_0034c740");

// ---- 001610c0 gap: re-light every object flagged 2 (light colour at its position, alpha 128)
namespace g001610c0 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
} __attribute__((aligned(16)));
struct Light {
    QWord dir;
    QWord neg;
    u8 rgb[4];
    u32 mask;
    u32 a, b, c;
    u8 d;
    Light() { mask = 0xffff; a = 0; b = 0; c = 0; d = 0; }
};
#define LIGHT_INIT(l) do { asm volatile("sqc2 $vf0, 0(%0)" : : "r"(&(l).dir) : "memory"); \
    asm volatile("lqc2 $vf4, 0(%1)\n\tvsub.xyz $vf5, $vf0, $vf4\n\tsqc2 $vf5, 0(%0)" : : "r"(&(l).neg), "r"(&(l).dir) : "memory"); } while (0)
struct Col { u8 r, g, b, a; };
struct Obj {
    u8 pad0[80];
    QWord pos;      // 80
    u8 pad96[32];
    Obj* next;      // 128
    u8 pad132[288];
    Col color;      // 420
    u32 f424, f428; // 424
    u8 pad432[248];
    u8 lit[4];      // 680
};
extern Obj* D_004f3b38 asm("D_004f3b38");
void func_00143520(QWord*, Light*) asm("func_00143520");
static inline Obj* next_obj(Obj* n) {
    if (!n) return D_004f3b38;
    return n->next;
}
static inline void SetColor(Col* c, u8 r, u8 g, u8 b, u8 a) { c->r = r; c->g = g; c->b = b; c->a = a; }
void func_001610c0(void) asm("func_001610c0");
void func_001610c0(void) {
    Obj* o = 0;
    while ((o = next_obj(o))) {
        if (!(o->f428 & 2)) continue;
        Light l; LIGHT_INIT(l);
        func_00143520(&o->pos, &l);
        SetColor(&o->color, l.rgb[0], l.rgb[1], l.rgb[2], 128);
        o->lit[0] = o->color.r;
        o->lit[1] = o->color.g;
        o->lit[2] = o->color.b;
    }
}
#undef QCOPY
#undef LIGHT_INIT
}  // namespace g001610c0

namespace w64 {
extern u8* D_004f3b38 asm("D_004f3b38");
void func_00160488(u8*, u8, u8, u8) asm("func_00160488");
static inline u8* next_611a8(u8* n) {
    if (!n) return D_004f3b38;
    return *(u8**)(n + 128);
}
// Applies func_00160488 to every node of the list.
void func_001611a8(u8 a, u8 b, u8 c) asm("func_001611a8");
void func_001611a8(u8 a, u8 b, u8 c) {
    u8* n = 0;
    while ((n = next_611a8(n))) func_00160488(n, a, b, c);
}
}

namespace flag {
void func_00161228(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00161228");
void func_00161228(u32 a0, u32 a1, u32 a2, u32 a3) { D_0034c740 = 0; }
void func_00161238(void) asm("func_00161238");
void func_00161238(void) { D_0034c740 = 1; }
}

namespace w49 {
struct Node161248 { u8 pad[128]; Node161248* next; };
extern Node161248* D_004f3b38 asm("D_004f3b38");
void func_00160940(Node161248*, u32, f32) asm("func_00160940");
static inline Node161248* next161248(Node161248* n) {
    if (!n) return D_004f3b38;
    return n->next;
}
void func_00161248(f32 x, u32 a) asm("func_00161248");
void func_00161248(f32 x, u32 a) {
    Node161248* n = 0;
    while ((n = next161248(n)) != 0) func_00160940(n, a, x);
}
}

namespace w1578 {
struct W1578Mode { s32 pad; s32 id; };
struct W1578Task { u8 pad[0x30]; s32 fn; };
typedef void (*W1578TaskFn)(W1578Task*);
W1578Mode* W1578_getFieldMode(void) asm("_Z12getFieldModev");
W1578Mode* W1578_getGumiBattleMode(void) asm("_Z17getGumiBattleModev");
void func_00102180(W1578Mode**) asm("func_00102180");
void func_00161228(void) asm("func_00161228");
W1578Task* W1578_FIELD_CreateTask(s32, s32, W1578TaskFn) asm("_ZN5FIELD10CreateTaskEiiPFvP4TASKE");
W1578Task* W1578_TM_create_task(s32, s32, s32, W1578TaskFn) asm("_ZN12TASK_MANAGER11create_taskEiiPFvP4TASKE");
s32 func_001024b0(s32) asm("func_001024b0");
void func_00160b10(W1578Task*) asm("func_00160b10");
void func_00160b88(W1578Task*) asm("func_00160b88");
void func_00160bb8(W1578Task*) asm("func_00160bb8");
void func_00160bd8(W1578Task*) asm("func_00160bd8");
void func_00160cf0(W1578Task*) asm("func_00160cf0");
extern s32 D_0034c738 asm("D_0034c738");
extern s32 D_0034c73c asm("D_0034c73c");
extern s32 D_004f3b30 asm("D_004f3b30");
// dk::BgObj::init(ALLOCATOR*, MapFile*): keep both and start the object tasks for this mode.
void dk__BgObj__init(s32 a0, s32 a1) asm("dk__BgObj__init");
void dk__BgObj__init(s32 a0, s32 a1) {
    D_0034c73c = a1;
    D_0034c738 = a0;
    func_00161228();
    W1578Mode* f = W1578_getFieldMode();
    W1578Mode* g = W1578_getGumiBattleMode();
    W1578Mode* cur;
    func_00102180(&cur);
    W1578Mode* c = cur;
    if (c == f) {
        *(s32*)((u8*)W1578_FIELD_CreateTask(1, 28000, func_00160b88) + 0x30) = (s32)func_00160bb8;
        *(s32*)((u8*)W1578_FIELD_CreateTask(1, 0x16378, func_00160bd8) + 0x30) = (s32)func_00160cf0;
        s32 t = func_001024b0(D_0034c738);
        D_004f3b30 = t;
        W1578_TM_create_task(t, 0, 28000, func_00160b10);
    } else if (c == g) {
        *(s32*)((u8*)W1578_TM_create_task(g->id, 0, 0xabe0, func_00160b88) + 0x30) = (s32)func_00160bb8;
        *(s32*)((u8*)W1578_TM_create_task(g->id, 0, 0x11558, func_00160bd8) + 0x30) = (s32)func_00160cf0;
        s32 t = func_001024b0(D_0034c738);
        D_004f3b30 = t;
        W1578_TM_create_task(t, 0, 0xabe0, func_00160b10);
    }
}
}
