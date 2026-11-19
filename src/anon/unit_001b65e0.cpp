// Linked unit 0x001b65e0-0x001b6a50 (drive form change task; was whole asm in src/anon/asm_001b65e0.s).
// Notes for the next reader:
//  - func_001c9df8 takes no argument (see its definition in src/yasui/libys/sacrifice.cpp). Old drafts passed the task
//    to it, which made the scheduler pull the wait call's arguments of the first loop into the last test block.
//  - func_001ba028 is declared with a 64-bit (long) parameter here. This is a guess that only changes register
//    allocation order: the load of c->obj becomes a load plus a tied copy inside the second wait loop, which keeps the
//    live-range copy of `task` for that loop behind `task` itself, so both stay in s3. The emitted code for the call is
//    the same `lw a0,0(s2)` either way.
//  - zero is read through an int so that gcse does not turn the later `mov.s f12,f20` into a constant load.
//  - The 16-byte copies use the lq/sq operator= idiom of the neighbouring units.
#include "../common/types.h"

namespace n001b65e0 {
extern "C" {
struct __attribute__((aligned(16))) W1624Q { f32 f[4];
    inline W1624Q& operator=(const W1624Q& rhs) {
        if (this == &rhs) return *this;
        asm("lq $8, 0(%1);sq $8, 0(%0);" : : "r"(this), "r"(&rhs) : "t0", "memory");
        return *this; } };
struct W1624Cam { W1624Q pos; f32 a, b, c, d, e; };
typedef struct W1624Obj W1624Obj;
typedef struct W1624ObjVt { void* _00[8]; void (*release)(W1624Obj*); } W1624ObjVt;
typedef struct W1624SubVt { void* _00[3]; void (*init)(void*, W1624Obj*, f32); } W1624SubVt;
typedef struct W1624Sub { W1624SubVt* vt; } W1624Sub;
struct W1624Obj {
    W1624ObjVt* vt; u8 _004[8]; W1624Sub* sub; u8 _010[16]; W1624Q pos; u8 _030[0x90];
    W1624Cam cam; u8 _0f0[0x50]; u8 motion[0x41c]; f32 f55c; u8 _560[0x298]; u32 f7f8; u8 _7fc[0x2cc];
    s32 fac8; s32 facc; u8 _ad0[0x68]; s32 fb38; u8 _b3c[4]; s32 fb40; u8 _b44[0x28]; s32 mode;
};
typedef struct W1624Eff { u8 _00[0x10]; u32 flags; } W1624Eff;
typedef struct W1624Change { W1624Obj* obj; s32 form; s32 id; u32 flags; W1624Eff* eff; u8 _14[8]; u8 restore; } W1624Change;
typedef struct W1624Fade { u8 _00[0x0c]; s32 f0c; s32 f10; } W1624Fade;
extern u8 D_00351eb8[];
extern W1624Fade D_00350448;
bool func_001c8db8(void*, s32);
void func_001c8d80(void*, s32);
W1624Eff* func_001b1928(s32);
void func_001b1bb8(W1624Eff*, s32, s32, s32, s32, f32);
void func_00102470(void*, f32);
void func_0019ec88(W1624Fade*);
void func_0019ecb0(W1624Fade*, f32);
void func_00170dd0(void*);
void func_00170320(s32);
void func_0016ef28(s32);
void func_00170888(void*);
s32 func_0019ba60(W1624Obj*);
s32 func_00180618(void*);
s32 func_001c9df8(void);
void func_00102448(void*, s32);
void func_001b1c10(W1624Eff*, f32);
void func_0019ed78(W1624Fade*, f32);
void func_0019ca20(s32);
void* func_001050d8(u32);
void* func_0016e920(s32);
s32 func_0016c028(W1624Obj*);
void func_001d0980(W1624Obj*, void*, s32, s32, s32, f32);
void func_0017f488(void*, s32, f32, f32);
void func_001b6ab8(W1624Change*);
void func_00190570(W1624Obj*, W1624Obj*);
void func_001995b8(W1624Obj*, W1624Obj*);
void func_001e0230(W1624Obj*, W1624Obj*);
void func_0018ef98(W1624Obj*, W1624Obj*);
void func_00197e08(W1624Obj*, W1624Obj*);
void func_001b1360(W1624Obj*, W1624Obj*);
void func_002edca0(W1624Obj*, W1624Obj*);
void func_00111e50(void);
s32 func_001ba028(long);
void func_001c9e50(void*);

static inline bool W1624IsForm(W1624Change* c) { if (c->form == 0) return 0; if (c->form < 7) return 1; return 0; }
static inline bool W1624NoFlag(void* p, s32 i) { return !func_001c8db8(p, i); }

/*TARGET 001b65e0*/
void wtarget_001b65e0(W1624Change* c, void* task, u32 x, u32 y) asm("_Z16wtarget_001b65e0jjjj");
void wtarget_001b65e0(W1624Change* c, void* task, u32 x, u32 y)
{
    f32 zero;
    s32 two;
    W1624Cam cam;
    W1624Q pos;
    W1624Obj* n;
    void* info;
    s32 m;
    s32 iz = 0; zero = *(f32*)&iz;
    cam.pos.f[0] = zero; cam.pos.f[1] = zero; cam.pos.f[2] = zero; cam.pos.f[3] = zero;
    cam.a = zero; cam.b = zero; cam.c = zero; cam.d = zero; cam.e = zero;

    if (W1624IsForm(c)) {
        if (W1624NoFlag(D_00351eb8, 0)) func_001c8d80(D_00351eb8, 0);
        c->eff = func_001b1928(0);
        c->eff->flags |= 2;
        two = 2;
        func_001b1bb8(c->eff, 48, 48, 48, 128, 12.0f);
        func_00102470(task, 30.0f);
        func_0019ec88(&D_00350448);
        D_00350448.f0c = two;
        D_00350448.f10 = two;
        func_0019ecb0(&D_00350448, zero);
        func_00170dd0(task);
        func_00170320(5000);
        func_0016ef28(c->form);
        func_00170888(task);
        
                while (func_0019ba60(c->obj) && !func_00180618(c->obj->motion) && func_001c9df8())
                func_00102448(task, 0);

        func_00102448(task, 2);
        func_001b1c10(c->eff, 15.0f);
        c->eff = 0;
        func_0019ed78(&D_00350448, 20.0f);
    }
    if (!func_0019ba60(c->obj)) return;

    cam = c->obj->cam;
    pos = c->obj->pos;
    if (c->obj->fb40) {
        func_0019ca20(c->obj->fb40);
        c->obj->fb40 = 0;
    }
    c->obj->vt->release(c->obj);
    n = (W1624Obj*)func_001050d8(0xb80);
    info = func_0016e920(c->id);
    m = func_0016c028(c->obj);
    func_001d0980(n, info, c->form, c->obj->fb38, m, c->obj->f55c);
    c->flags |= 8;
    n->fac8 = c->obj->fac8;
    c->obj->fac8 = 0;
    n->facc = c->obj->facc;
    c->obj->facc = 0;
    if (c->obj->f7f8 & 4) {
        func_0017f488(c->obj->motion, 0, 0.0f, 0.0f);
        n->mode = 3;
    } else if (c->form < 7) {
        u32 fl = c->flags & 1;
        if (fl) {
            if (c->form == 0) {
                n->sub->vt->init(n->sub, n, 0.0f);
                if (c->flags & 2) n->cam = cam;
                n->pos = pos;
                n->pos.f[1] = 0.0f;
            }
            n->mode = 2;
        } else {
            n->mode = 1;
        }
    }
    func_001b6ab8(c);
    func_00190570(c->obj, n);
    func_001995b8(c->obj, n);
    func_001e0230(c->obj, n);
    func_0018ef98(c->obj, n);
    func_00197e08(c->obj, n);
    func_001b1360(c->obj, n);
    func_002edca0(c->obj, n);
    func_00111e50();
    c->flags |= 4;
    while (func_001ba028((long)c->obj)) func_00102448(task, 0);
    func_00102448(task, 2);
    if (c->restore) {
        func_00170888(task);
        func_001c9e50(task);
    }
}
}
}  // namespace n001b65e0
