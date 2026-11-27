// Linked unit 0x002335e8-0x00234f60 (one namespace per old matched source; gap functions written here).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../ishi/mcard.hpp"
#include <stdarg.h>
#include "tiny_auto80_solver_structs.hpp"

// gcc's float-to-unsigned libcall is the game's copy at 0x313bc0 (libgcc would bring its own).
asm("fptoui = _Z12__fixunssfsif");

// 002335e8 (was gap)
namespace n002335e8 {
struct V3 { f32 x, y, z; };
f32 func_002335e8(const V3* v) asm("func_002335e8");
f32 func_002335e8(const V3* v) {
    return __builtin_sqrtf(v->x * v->x + v->y * v->y + v->z * v->z);
}
}  // namespace n002335e8

// 00233618 (was gap)
namespace n00233618 {
struct V3 { f32 x, y, z; };
f32 func_00233618(const V3* a, const V3* b) asm("func_00233618");
f32 func_00233618(const V3* a, const V3* b) {
    V3 d;
    d.x = a->x - b->x;
    d.y = a->y - b->y;
    d.z = a->z - b->z;
    return __builtin_sqrtf(d.x * d.x + d.y * d.y + d.z * d.z);
}
}  // namespace n00233618

// 00233660 (was gap)
namespace n00233660 {
f32 func_00233660(f32 x) asm("func_00233660");
f32 func_00233660(f32 x) {
    if (x >= 3.1415927f) x -= (f32)((s32)(x / 6.2831855f) + 1) * 3.1415927f * 2.0f;
    else if (x < -3.1415927f) x += (f32)((s32)(x / -6.2831855f) + 1) * 3.1415927f * 2.0f;
    return x;
}
}  // namespace n00233660

// 00233708 (was src/anon/batch_w2376.cpp)
namespace n00233708 {
#define MOD_CH_233708(i) \
    if (((u8*)&m)[i] != 128) { \
        u32 v = (((u8*)&c)[i] * ((u8*)&m)[i]) >> 7; \
        if (v >= 256) ((u8*)&c)[i] = 0xff; else ((u8*)&c)[i] = v; \
    }
/*TARGET 00233708*/
u32 func_00233708(u32 c, u32 m) asm("func_00233708");
u32 func_00233708(u32 c, u32 m) {
    MOD_CH_233708(0)
    MOD_CH_233708(1)
    MOD_CH_233708(2)
    MOD_CH_233708(3)
    return c;
}
}  // namespace n00233708
#undef MOD_CH_233708

// 002337d8 (was gap)
namespace n002337d8 {
u32 func_00233708(u32 c, u32 m) asm("func_00233708");
u32 func_002337d8(u32 c, u32 m, f32 k) asm("func_002337d8");
u32 func_002337d8(u32 c, u32 m, f32 k) {
    u32 r = func_00233708(c, m);
    if (k != 1.0f) {
        u32 v = (s32)((f32)(r >> 24) * k);
        if (v >= 256) ((u8*)&r)[3] = 255;
        else ((u8*)&r)[3] = v;
    }
    return r;
}
}  // namespace n002337d8

// 00233868 (was gap)
namespace n00233868 {
u32 func_00233868(u32 c, u32 k) asm("func_00233868");
u32 func_00233868(u32 c, u32 k) {
    if (k != 128) {
        u32 v = ((c >> 24) * k) >> 7;
        if (v >= 256) ((u8*)&c)[3] = 255;
        else ((u8*)&c)[3] = v;
    }
    return c;
}
}  // namespace n00233868

// 002338a8 (was src/anon/batch_w47.cpp)
namespace n002338a8 {
// 0x00230d78: definition moved into src/anon/unit_002302c0.cpp

// Scales the alpha byte of an RGBA colour, clamped to 255.
struct C23 { u8 r, g, b, a; };
/*TARGET 002338a8*/
u32 func_002338a8(C23 c, f32 s) asm("func_002338a8");
u32 func_002338a8(C23 c, f32 s) {
    if (s != 1.0f) {
        u32 v = (s32)((f32)((*(u32*)&c) >> 24) * s);
        if (v >= 256) c.a = 255;
        else c.a = v;
    }
    return *(u32*)&c;
}
}  // namespace n002338a8

// 00233920 (was gap)
namespace n00233920 {
u32 func_00233920(u32 a, u32 b, f32 t) asm("func_00233920");
u32 func_00233920(u32 a, u32 b, f32 t) {
    u32 r;
    u8* pr = (u8*)&r;
    u8* pa = (u8*)&a;
    u8* pb = (u8*)&b;
    u32 v = (u8)(pa[0] + (u32)((f32)(pb[0] - pa[0]) * t));
    r = (r & ~0xff) | v;
    pr[1] = pa[1] + (u32)((f32)(pb[1] - pa[1]) * t);
    pr[2] = pa[2] + (u32)((f32)(pb[2] - pa[2]) * t);
    pr[3] = pa[3] + (u32)((f32)(pb[3] - pa[3]) * t);
    return r;
}
}  // namespace n00233920

// 00233a18 (was src/anon/auto80_199_queue.cpp)
namespace n00233a18 {
/*TARGET 00233a18*/
// 0x00231948: definition moved into src/anon/unit_00231500.cpp

u32 func_00233a18(u32 a0, u32 a1) asm("_Z13func_00233a18jj");
// 0x00231948: definition moved into src/anon/unit_00231500.cpp

u32 func_00233a18(u32 a0, u32 a1) {
    u32 out;
    u8* pb = (u8*)&out;
    u8* a = (u8*)&a0;
    u8* b = (u8*)&a1;
    u32 t12;
    u32 t14;
    u32 t15;

    t14 = (u32)a[0] + (u32)b[0];
    t12 = out;
    t15 = (u32)-256;
    t12 = t12 & t15;
    t14 = t14 >> 1;
    t12 = t12 | t14;
    out = t12;
    pb[1] = (u8)(((s32)((u32)a[1] + (u32)b[1])) >> 1);
    pb[2] = (u8)(((s32)((u32)a[2] + (u32)b[2])) >> 1);
    pb[3] = (u8)(((s32)((u32)a[3] + (u32)b[3])) >> 1);
    return out;
}
}  // namespace n00233a18

// 00233a90 (was gap)
namespace n00233a90 {
u32 func_00233a90(u32 x) asm("func_00233a90");
u32 func_00233a90(u32 x) {
    u32 r = 0, m = 1;
    do {
        r += (x & 0xf) * m;
        x >>= 4;
        m *= 10;
    } while (x);
    return r;
}
}  // namespace n00233a90

// 00233ac0 (was src/anon/batch_w37.cpp)
namespace n00233ac0 {
void __fixunssfsi(f32) asm("__fixunssfsi");
// Local with a non-trivial destructor: keeps the call a jal instead of a sibling call.
struct NoTail { ~NoTail() {} };
/*TARGET 00233ac0*/
void func_00233ac0(u32 a) asm("func_00233ac0");
void func_00233ac0(u32 a) {
    NoTail g;
    __fixunssfsi((f32)a / 216000.0f);
}
}  // namespace n00233ac0

// 00233b20 (was gap)
namespace n00233b20 {
u32 func_00233b20(u32 f) asm("func_00233b20");
u32 func_00233b20(u32 f) { return (u32)((f32)f / 3600.0f) % 60; }
}  // namespace n00233b20

// 00233b90 (was gap)
namespace n00233b90 {
u32 func_00233b90(u32 f) asm("func_00233b90");
u32 func_00233b90(u32 f) { return (u32)((f32)f / 60.0f) % 60; }
}  // namespace n00233b90

// 00233c00 (was gap)
namespace n00233c00 {
u32 func_00233c00(u32 f) asm("func_00233c00");
u32 func_00233c00(u32 f) { return (u32)((f32)((u32)(f32)f % 60) * 1.6666666f); }
}  // namespace n00233c00

// 00233c98 (was src/anon/batch_w25.cpp)
namespace n00233c98 {
void u_call0_00233c98(void) asm("_Z16u_call0_00233c98v");
// Clears a 256-entry u64 table; the original has a 3-nop pad in the loop (asm).
extern u64 D_01dadc00[] asm("D_01dadc00");
void sceMcInit(void) asm("sceMcInit");
void func_00233ce0(void) asm("func_00233ce0");
/*TARGET 00233c98*/
void u_call0_00233c98(void) asm("_Z16u_call0_00233c98v");
void u_call0_00233c98(void) {
    s32 i;
    u64* p;
    sceMcInit();
    p = D_01dadc00;
    i = 256;
    do {
        *p = 0;
        i--;

        p++;
    } while (i > 0);
    func_00233ce0();
}
}  // namespace n00233c98

// 00233ce0 (was src/anon/batch_w8022.c)
namespace n00233ce0 {
// 0x0026d208: definition moved into src/anon/unit_0026c450.cpp

/* 00233ce0 */
typedef struct W8022_S420 { u8 b; s32 x4; s32 x8; s32 xc; s32 x10; } W8022_S420;
typedef struct W8022_E480 { s32 a, b, c, d, e, f, g, h; } W8022_E480;
s32 func_002fbc78(s32) asm("func_002fbc78");
extern s32 D_01dae580[2] asm("D_01dae580");
extern s32 D_01dae588[2] asm("D_01dae588");
extern s32 D_0035e360 asm("D_0035e360");
extern s32 D_0035e364 asm("D_0035e364");
extern s32 D_0035e368 asm("D_0035e368");
extern s32 D_0035e36c asm("D_0035e36c");
extern s32 D_0035e370 asm("D_0035e370");
extern s32 D_0035e374 asm("D_0035e374");
extern W8022_S420 D_01dae420 asm("D_01dae420");
typedef struct W8022_438 { void* p; s32 a[12]; } W8022_438;
extern W8022_438 D_01dae438 asm("D_01dae438");
extern s32 D_01dae478 asm("D_01dae478");
extern s32 D_01dae47c asm("D_01dae47c");
extern W8022_E480 D_01dae480[2][4] asm("D_01dae480");
/*TARGET 00233ce0*/
void func_00233ce0(void) asm("func_00233ce0");
void func_00233ce0(void) {
    s32 i, j;
    for (i = 0; i < 2; i++) {
        D_01dae580[i] = 1;
        D_01dae588[i] = func_002fbc78(i);
    }
    D_0035e370 = 0;
    D_0035e374 = 0;
    D_01dae420.x4 = 300;
    D_0035e360 = 0;
    D_0035e364 = 0;
    D_0035e368 = 1;
    D_01dae420.b = 0;
    D_01dae478 = 0;
    D_0035e36c = 1;
    D_01dae47c = 0;
    D_01dae420.xc = 0;
    D_01dae420.x8 = 300;
    D_01dae420.x10 = 0;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            W8022_E480* e = &D_01dae480[i][j];
            e->a = -1; e->b = -1; e->c = 0; e->d = -1;
            e->e = -1; e->f = -1; e->g = -1; e->h = 0;
        }
    }
    D_01dae438.p = (void*)-1;
    D_01dae438.a[0] = -1;
    D_01dae438.a[1] = -1;
    D_01dae438.a[2] = -1;
    D_01dae438.a[3] = -1;
    D_01dae438.a[4] = -1;
    D_01dae438.a[5] = -1;
    D_01dae438.a[6] = -1;
    D_01dae438.a[7] = -1;
    D_01dae438.a[8] = -1;
    D_01dae438.a[9] = -1;
    D_01dae438.a[10] = -1;
    D_01dae438.a[11] = -1;
}
}  // namespace n00233ce0

// 00233e58 (was src/anon/misc_2.cpp)
namespace n00233e58 {
/*TARGET 00233e58*/
void func_00233e58(void* self) asm("_Z13func_00233e58Pv");
void func_00233e58(void* self) {}
}  // namespace n00233e58

// 00233e60 (was src/ishi/mcard.cpp)
namespace YI { // method 00233e60
extern u32 D_0035e370 asm("D_0035e370");
/*TARGET 00233e60*/
u32 MCARD::isIdle() {
    u32 v = D_0035e370;
    return (v < 1u);
}
}  // YI

// 00233e70 (was src/anon/batch_w2436.c)
namespace n00233e70 {
/* 00233e70: is id queued (ring of 64 entries) or current. R0 is the last block
   before the return, so it falls into the bare jr ra that the branches target. */
typedef struct Ent233e70 { s32 a; s32 b; u8 pad[24]; } Ent233e70;
extern Ent233e70 D_01dadc00[64] asm("D_01dadc00");
extern s32 D_0035e360 asm("D_0035e360");
extern s32 D_0035e364 asm("D_0035e364");
extern s32 D_0035e36c asm("D_0035e36c");
extern s32 D_0035e370 asm("D_0035e370");
/*TARGET 00233e70*/
s32 func_00233e70(s32 id) asm("func_00233e70");
s32 func_00233e70(s32 id) {
    s32 r;
    if (id == 0) goto Z;
    {
        s32 i;
        for (i = D_0035e364; i != D_0035e360; ) {
            s32 c = i;
            i++;
            i &= 0x3f;
            if (D_01dadc00[c].b == id) goto F;
        }
    }
    if (D_0035e370 != 0) {
        if (D_0035e36c == id) { r = 1; goto RET; }
    }
    goto R0;
Z:
    if (D_0035e360 != D_0035e364) goto F;
    if (D_0035e370 == 0) goto R0;
F:
    r = 1;
    goto RET;
R0:
    r = 0;
RET:
    return r;
}
}  // namespace n00233e70

// 00233f18 (was gap)
namespace n00233f18 {
struct Ent233f18 { s32 a; s32 b; u8 pad[24]; };
extern Ent233f18 D_01dadc00[64] asm("D_01dadc00");
extern s32 D_0035e360 asm("D_0035e360");
extern s32 D_0035e364 asm("D_0035e364");
extern s32 D_0035e36c asm("D_0035e36c");
extern s32 D_0035e370 asm("D_0035e370");
void func_00236148(void) asm("func_00236148");
void func_002f2508(s32) asm("func_002f2508");
void func_00233f18(s32 id) asm("func_00233f18");
void func_00233f18(s32 id) {
    if (id != 0) {
    retry:
        for (s32 i = D_0035e364; i != D_0035e360; ) {
            s32 c = i;
            i++;
            i &= 0x3f;
            if (D_01dadc00[c].b == id) {
                func_00236148();
                func_002f2508(0);
                goto retry;
            }
        }
        if (D_0035e370 != 0 && D_0035e36c == id) {
            do {
                func_00236148();
                func_002f2508(0);
            } while (D_0035e370 != 0);
        }
    } else {
        while (D_0035e360 != D_0035e364 || D_0035e370 != 0) {
            func_00236148();
            func_002f2508(0);
        }
    }
}
}  // namespace n00233f18

// 00234040 (was gap)
namespace n00234040 {
struct McReq { u8 busy; u8 pad[3]; s32 a; s32 b; s32 c; s32 d; };
extern McReq D_01dae420 asm("D_01dae420");
u8 func_00234040(void) asm("func_00234040");
u8 func_00234040(void) { return D_01dae420.busy; }
void func_00234050(s32 a) asm("func_00234050");
void func_00234050(s32 a) { D_01dae420.busy = 1; D_01dae420.a = a; D_01dae420.b = 0; }
void func_00234070(void) asm("func_00234070");
void func_00234070(void) { D_01dae420.busy = 0; }
void func_00234080(s32 c, s32 d) asm("func_00234080");
void func_00234080(s32 c, s32 d) { D_01dae420.c = c; D_01dae420.d = d; }
}  // namespace n00234040

// 00234098 (was src/anon/batch_w31.cpp)
namespace n00234098 {
extern u32 D_0035e360 asm("D_0035e360");
extern u32 D_0035e368 asm("D_0035e368");
struct TargetEv { u32 active, serial, a, b, c, pad[3]; };
extern TargetEv D_01dadc00[] asm("D_01dadc00");
/*TARGET 00234098*/
u32 wtarget_00234098(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_00234098jjjj");
u32 wtarget_00234098(u32 a, u32 b, u32 c, u32 d) {
    u32 idx = D_0035e360;
    u32 serial = D_0035e368;
    TargetEv* e = &D_01dadc00[idx];
    e->active = 1;
    e->a = a;
    e->b = b;
    e->serial = serial;
    e->c = c;
    D_0035e360 = (idx + 1) & 63;
    D_0035e368 = serial + 1;
    return serial;
}
}  // namespace n00234098

// 002340f0 (was src/anon/batch_w2435.cpp)
namespace n002340f0 {
struct Sub { s32 c; s32 d; s32 e; };
struct Ent { s32 type; s32 id; s32 a; s32 b; Sub s; s32 f; };
extern Ent D_01dadc00[] asm("D_01dadc00");
extern s32 D_0035e360 asm("D_0035e360");
extern s32 D_0035e368 asm("D_0035e368");
extern s32 D_0035e378 asm("D_0035e378");
/*TARGET 002340f0*/
/* Queue push: fills the next ring entry (64 slots) and returns its id. */
s32 func_002340f0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) asm("func_002340f0");
/* Queue push: fills the next ring entry (64 slots) and returns its id. */
s32 func_002340f0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {

    Ent* p = &D_01dadc00[D_0035e360];
    Sub* q = &p->s;
    s32 v;
    p->type = 2;
    p->a = a;
    p->b = b;
    q->c = c;
    p->id = D_0035e368;
    p->s.d = d;
    if (e) v = e; else v = D_0035e378;
    q->e = v;
    D_01dadc00[D_0035e360].f = f;
    D_0035e360 = (D_0035e360 + 1) & 63;
    return D_0035e368++;
}
}  // namespace n002340f0

// 00234188 (was src/anon/batch_w1761_nsa.cpp)
namespace n00234188 {
struct W1761Ev { s32 type; s32 id; s32 a[6]; };
extern s32 D_0035e360 asm("D_0035e360");
extern s32 D_0035e368 asm("D_0035e368");
extern W1761Ev D_01dadc00[64] asm("D_01dadc00");
/*TARGET 00234188*/
s32 func_00234188(s32 p0, s32 p1, s32 p2, s32 p3, s32 p4, s32 p5) asm("func_00234188");
s32 func_00234188(s32 p0, s32 p1, s32 p2, s32 p3, s32 p4, s32 p5) {
    W1761Ev* e = &D_01dadc00[D_0035e360];
    s32 id = D_0035e368;
    e->type = 3;
    e->id = id;
    e->a[0] = p0;
    e->a[1] = p1;
    e->a[2] = p2;
    e->a[3] = p3;
    e->a[4] = p4;
    e->a[5] = p5;
    D_0035e360 = (D_0035e360 + 1) & 63;
    D_0035e368 = id + 1;
    return id;
}
}  // namespace n00234188

// 002341e8 (was src/anon/batch_w1756.cpp)
namespace n002341e8 {
struct WTarget_w1756 { u32 type; u32 id; u32 a; u32 b; u32 c; u32 pad[3]; };
extern s32 D_0035e360 asm("D_0035e360");
extern s32 D_0035e368 asm("D_0035e368");
extern WTarget_w1756 D_01dadc00[] asm("D_01dadc00");
u32 wtarget_002341e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_002341e8jjjj");
/*TARGET 002341e8*/
u32 wtarget_002341e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_002341e8jjjj");
u32 wtarget_002341e8(u32 a0, u32 a1, u32 a2, u32 a3)
{
    s32 i = D_0035e360;
    u32 id = D_0035e368;
    WTarget_w1756* e = &D_01dadc00[i];
    e->type = 4;
    e->id = id;
    e->a = a0;
    e->b = a1;
    e->c = a2;
    D_0035e360 = (i + 1) & 63;
    D_0035e368 = id + 1;
    return id;
}
}  // namespace n002341e8

// 00234240 (was src/anon/batch_w1671.cpp)
namespace n00234240 {
struct RE_w1671 { s32 type; s32 id; s32 a; s32 b; s32 c; s32 pad[3]; };
extern s32 D_0035e360 asm("D_0035e360");
extern s32 D_0035e368 asm("D_0035e368");
extern RE_w1671 D_01dadc00[] asm("D_01dadc00");
/*TARGET 00234240*/
s32 func_00234240(s32 a0, s32 a1, s32 a2) asm("func_00234240");
s32 func_00234240(s32 a0, s32 a1, s32 a2) {
    s32 i = D_0035e360;
    s32 id = D_0035e368;
    RE_w1671* e = &D_01dadc00[i];
    e->type = 5;
    e->a = a0;
    e->b = a1;
    e->id = id;
    e->c = a2;
    D_0035e360 = (i + 1) & 0x3f;
    D_0035e368 = id + 1;
    return id;
}
}  // namespace n00234240

// 00234298 (was src/anon/batch_w33.cpp)
namespace n00234298 {
struct Ev234 { s32 type; s32 id; u32 a, b, c, d; u32 pad[2]; };
extern Ev234 D_01dadc00[] asm("D_01dadc00");
extern s32 D_0035e360 asm("D_0035e360");
extern s32 D_0035e368 asm("D_0035e368");
u32 wtarget_00234298(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_00234298jjjj");
/*TARGET 00234298*/
u32 wtarget_00234298(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_00234298jjjj");
u32 wtarget_00234298(u32 a, u32 b, u32 c, u32 d) {
    s32 i = D_0035e360;
    s32 id = D_0035e368;
    Ev234* e = &D_01dadc00[i];
    e->type = 6;
    e->a = a;
    e->b = b;
    e->c = c;
    e->id = id;
    e->d = d;
    D_0035e360 = (i + 1) & 63;
    D_0035e368 = id + 1;
    return id;
}
}  // namespace n00234298

// 002342f0 (was src/anon/batch_w34.cpp)
namespace n002342f0 {
u32 wtarget_002342f0(u32, u32, u32, u32) asm("_Z16wtarget_002342f0jjjj");
extern s32 D_0035e360 asm("D_0035e360");
extern s32 D_0035e368 asm("D_0035e368");
struct Event32 {
    u32 type;
    u32 id;
    u32 a, b, c, d;
    u32 pad[2];
};
extern Event32 D_01dadc00[] asm("D_01dadc00");
/*TARGET 002342f0*/
// 0x001dc920: definition moved into src/anon/unit_001dbfd8.cpp

u32 wtarget_002342f0(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_002342f0jjjj");
// 0x001dc920: definition moved into src/anon/unit_001dbfd8.cpp

u32 wtarget_002342f0(u32 a, u32 b, u32 c, u32 d) {
    s32 i = D_0035e360;
    s32 id = D_0035e368;
    Event32* e = &D_01dadc00[i];
    e->type = 7;
    e->a = a;
    e->b = b;
    e->c = c;
    e->id = id;
    e->d = d;
    D_0035e360 = (i + 1) & 63;
    D_0035e368 = id + 1;
    return id;
}
}  // namespace n002342f0

// 00234348 (was src/anon/batch_w36.cpp)
namespace n00234348 {
extern s32 D_0035e360 asm("D_0035e360");
extern s32 D_0035e368 asm("D_0035e368");
struct Ev32 { s32 type, id, a, b, c, d, e, f; };
extern Ev32 D_01dadc00[] asm("D_01dadc00");
/*TARGET 00234348*/
// 0x00232590: definition moved into src/anon/unit_00231500.cpp

// Queues an event record in a 64-entry ring; returns its serial number.
s32 func_00234348(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) asm("func_00234348");
// 0x00232590: definition moved into src/anon/unit_00231500.cpp

// Queues an event record in a 64-entry ring; returns its serial number.
s32 func_00234348(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    s32 idx = D_0035e360;
    s32 id = D_0035e368;
    Ev32* ev = &D_01dadc00[idx];
    ev->type = 8;
    ev->id = id;
    ev->a = a;
    ev->b = b;
    ev->c = c;
    ev->d = d;
    ev->e = e;
    ev->f = f;
    D_0035e360 = (idx + 1) & 63;
    D_0035e368 = id + 1;
    return id;
}
}  // namespace n00234348

// 002343a8 (was src/anon/batch_w35.cpp)
namespace n002343a8 {
// 0022b7f0: moved to src/sasa/musical_2d.cpp (linked unit)

// Appends a type-9 record to the 64-entry ring buffer; returns its serial.
struct REnt { u32 type, id, a, b, c, d; u32 pad[2]; };
extern s32 D_0035e360 asm("D_0035e360");
extern u32 D_0035e368 asm("D_0035e368");
extern REnt D_01dadc00[] asm("D_01dadc00");
u32 wtarget_002343a8(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_002343a8jjjj");
/*TARGET 002343a8*/
u32 wtarget_002343a8(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_002343a8jjjj");
u32 wtarget_002343a8(u32 a, u32 b, u32 c, u32 d) {
    s32 i = D_0035e360;
    u32 id = D_0035e368;
    REnt* e = &D_01dadc00[i];
    e->type = 9;
    e->a = a;
    e->b = b;
    e->c = c;
    e->id = id;
    e->d = d;
    D_0035e360 = (i + 1) & 63;
    D_0035e368 = id + 1;
    return id;
}
}  // namespace n002343a8

// 00234400 (was src/anon/batch_w37.cpp)
namespace n00234400 {
struct Ev234 { s32 type; s32 seq; u32 a, b, c, d, e, f; };
extern Ev234 D_01dadc00[64] asm("D_01dadc00");
extern s32 D_0035e360 asm("D_0035e360");
extern s32 D_0035e368 asm("D_0035e368");
/*TARGET 00234400*/
s32 func_00234400(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f) asm("func_00234400");
s32 func_00234400(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f) {
    s32 i = D_0035e360;
    s32 seq = D_0035e368;
    Ev234* ev = &D_01dadc00[i];
    ev->type = 10;
    ev->a = a; ev->b = b; ev->c = c; ev->d = d; ev->e = e;
    ev->seq = seq;
    ev->f = f;
    D_0035e360 = (i + 1) & 63;
    D_0035e368 = seq + 1;
    return seq;
}
}  // namespace n00234400

// 00234460 (was src/anon/batch_w38.cpp)
namespace n00234460 {
// 0x001e2238: definition moved into src/anon/unit_001e0cb8.cpp

// Ring-buffered command queue (64 entries).
struct Q234460 { s32 type; s32 id; u32 a[6]; };
extern s32 D_0035e360 asm("D_0035e360");
extern s32 D_0035e368 asm("D_0035e368");
extern Q234460 D_01dadc00[64] asm("D_01dadc00");
/*TARGET 00234460*/
s32 func_00234460(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f) asm("func_00234460");
s32 func_00234460(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f) {
    s32 i = D_0035e360;
    s32 id = D_0035e368;
    Q234460* q = &D_01dadc00[i];
    q->type = 11;
    q->a[0] = a;
    q->a[1] = b;
    q->a[2] = c;
    q->a[3] = d;
    q->a[4] = e;
    q->id = id;
    q->a[5] = f;
    D_0035e360 = (i + 1) & 63;
    D_0035e368 = id + 1;
    return id;
}
}  // namespace n00234460

// 002344c0 (was src/anon/batch_w38.cpp)
namespace n002344c0 {
// 0x001e2238: definition moved into src/anon/unit_001e0cb8.cpp

// Ring-buffered command queue (64 entries).
struct Q234460 { s32 type; s32 id; u32 a[6]; };
extern s32 D_0035e360 asm("D_0035e360");
extern s32 D_0035e368 asm("D_0035e368");
extern Q234460 D_01dadc00[64] asm("D_01dadc00");
/*TARGET 002344c0*/
s32 func_002344c0(u32 a, u32 b, u32 c, u32 d, u32 e) asm("func_002344c0");
s32 func_002344c0(u32 a, u32 b, u32 c, u32 d, u32 e) {
    s32 i = D_0035e360;
    s32 id = D_0035e368;
    Q234460* q = &D_01dadc00[i];
    q->type = 9;
    q->a[0] = a;
    q->a[1] = b;
    q->a[2] = c;
    q->a[3] = d;
    q->id = id;
    q->a[4] = e;
    D_0035e360 = (i + 1) & 63;
    D_0035e368 = id + 1;
    return id;
}
}  // namespace n002344c0

// 00234520 (was gap)
namespace n00234520 {
struct REnt234520 { u32 type, id, a, b, c, d; u32 pad[2]; };
extern s32 D_0035e360 asm("D_0035e360");
extern u32 D_0035e368 asm("D_0035e368");
extern REnt234520 D_01dadc00[] asm("D_01dadc00");
u32 func_00234520(u32 a) asm("func_00234520");
u32 func_00234520(u32 a) {
    s32 i = D_0035e360;
    u32 id = D_0035e368;
    REnt234520* e = &D_01dadc00[i];
    e->type = 13;
    e->id = id;
    e->a = a;
    D_0035e360 = (i + 1) & 63;
    D_0035e368 = id + 1;
    return id;
}
}  // namespace n00234520

// 00234570 (was src/anon/tiny_wrappers_more.cpp)
namespace n00234570 {
u32 func_00234098(u32, u32, u32, u32) asm("_Z13func_00234098jjjj");
/*TARGET 00234570*/
// 0022d318: moved to src/sasa/event_layout.cpp (linked unit)

u32 func_00234570(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00234570jjjj");
// 0022d318: moved to src/sasa/event_layout.cpp (linked unit)

u32 func_00234570(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00234098(a0, 0x00000000u, a1, a3);
}
}  // namespace n00234570

// 00234590 (was src/anon/batch_w7.cpp)
namespace n00234590 {
void func_002340f0(u32, u32, u32, u32, u32, u32) asm("func_002340f0");
/*TARGET 00234590*/
// 00229d40: moved to src/sasa/musical_combo.cpp (linked unit)

void func_00234590(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0) asm("func_00234590");
// 00229d40: moved to src/sasa/musical_combo.cpp (linked unit)

void func_00234590(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0) {
    func_002340f0(a0, 0, a1, a2, a3, t0);
}
}  // namespace n00234590

// 002345c0 (was src/anon/batch_w8.cpp)
namespace n002345c0 {
// 00229d68: moved to src/sasa/musical_combo.cpp (linked unit)

void func_00234188(u32, u32, u32, u32, u32, u32) asm("func_00234188");
/*TARGET 002345c0*/
void func_002345c0(u32 a, u32 b, u32 c, u32 d, u32 e) asm("func_002345c0");
void func_002345c0(u32 a, u32 b, u32 c, u32 d, u32 e) {
    func_00234188(a, 0, b, c, d, e);
}
}  // namespace n002345c0

// 002345f0 (was src/anon/tiny_wrappers_more.cpp)
namespace n002345f0 {
u32 func_002341e8(u32, u32, u32, u32) asm("_Z13func_002341e8jjjj");
/*TARGET 002345f0*/
u32 func_002345f0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002345f0jjjj");
u32 func_002345f0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002341e8(a0, 0x00000000u, a1, a3);
}
}  // namespace n002345f0

// 00234610 (was gap)
namespace n00234610 {
u32 func_00234240(u32, u32, u32) asm("func_00234240");
u32 func_00234610(u32 a0, u32 a1) asm("func_00234610");
u32 func_00234610(u32 a0, u32 a1) { return func_00234240(a0, 0, a1); }
}  // namespace n00234610

// 00234630 (was src/anon/tiny_wrappers_more.cpp)
namespace n00234630 {
u32 func_00234298(u32, u32, u32, u32) asm("_Z13func_00234298jjjj");
/*TARGET 00234630*/
u32 func_00234630(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00234630jjjj");
u32 func_00234630(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00234298(a0, 0x00000000u, a1, a2);
}
}  // namespace n00234630

// 00234650 (was src/anon/tiny_wrappers_more.cpp)
namespace n00234650 {
u32 func_002342f0(u32, u32, u32, u32) asm("_Z13func_002342f0jjjj");
/*TARGET 00234650*/
u32 func_00234650(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00234650jjjj");
u32 func_00234650(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002342f0(a0, 0x00000000u, a1, a2);
}
}  // namespace n00234650

// 00234670 (was src/anon/batch_w9.cpp)
namespace n00234670 {
void func_00234348(u32, u32, u32, u32, u32, u32) asm("func_00234348");
/*TARGET 00234670*/
// 0022acd0: moved to src/sasa/musical_input.cpp (linked unit)

void func_00234670(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0) asm("func_00234670");
// 0022acd0: moved to src/sasa/musical_input.cpp (linked unit)

void func_00234670(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0) {
    func_00234348(a0, 0, a1, a2, a3, t0);
}
}  // namespace n00234670

// 002346a0 (was src/anon/tiny_wrappers_more.cpp)
namespace n002346a0 {
u32 func_002343a8(u32, u32, u32, u32) asm("_Z13func_002343a8jjjj");
/*TARGET 002346a0*/
u32 func_002346a0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002346a0jjjj");
u32 func_002346a0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002343a8(a0, 0x00000000u, a1, a2);
}
}  // namespace n002346a0

// 002346c0 (was src/anon/batch_w10.cpp)
namespace n002346c0 {
void func_00234400(void*, s32, void*, void*, void*, void*) asm("func_00234400");
/*TARGET 002346c0*/
// 0022c508: moved to src/sasa/event_layout.cpp (linked unit)

void func_002346c0(void* a, void* b, void* c, void* d, void* e) asm("func_002346c0");
// 0022c508: moved to src/sasa/event_layout.cpp (linked unit)

void func_002346c0(void* a, void* b, void* c, void* d, void* e) {
    func_00234400(a, 0, b, c, d, e);
}
}  // namespace n002346c0

// 002346f0 (was src/anon/batch_w15.cpp)
namespace n002346f0 {
void func_00234460(u32, u32, u32, u32, u32, u32) asm("func_00234460");
/*TARGET 002346f0*/
void func_002346f0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) asm("func_002346f0");
void func_002346f0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    func_00234460(a0, 0, a1, a2, a3, a4);
}
}  // namespace n002346f0

// 00234720 (was src/anon/batch_w6.cpp)
namespace n00234720 {
// 00228e28: moved to src/anon/unit_00228618.cpp (linked unit)

void func_002344c0(u32, u32, u32, u32, u32) asm("func_002344c0");
/*TARGET 00234720*/
void func_00234720(u32 a, u32 b, u32 c, u32 d) asm("func_00234720");
void func_00234720(u32 a, u32 b, u32 c, u32 d) {
    func_002344c0(a, 0, b, c, d);
}
}  // namespace n00234720

// 00234748 (was gap)
namespace n00234748 {
extern u32 D_01dae438 asm("D_01dae438");
u32 func_00234748(void) asm("func_00234748");
u32 func_00234748(void) { return D_01dae438; }
}  // namespace n00234748

// 00234758 (was src/ishi/mcard.cpp)
namespace YI { // method 00234758
/*TARGET 00234758*/
u32 MCARD::GetResultInfoRoot() {
    u32 b = (0x01dbu << 16);
    return (u32)(*(u32*)((u32)b + (-7108)));
}
}  // YI

// 00234768 (was gap)
namespace n00234768 {
extern u32 D_01dae440 asm("D_01dae440");
u32 func_00234768(void) asm("func_00234768");
u32 func_00234768(void) { return D_01dae440; }
}  // namespace n00234768

// 00234778 (was src/anon/tiny.cpp)
namespace n00234778 {
/*TARGET 00234778*/
// 0x0022d7d8: definition moved into src/anon/unit_0022d358.cpp

u32 func_00234778(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00234778jjjj");
// 0x0022d7d8: definition moved into src/anon/unit_0022d358.cpp

u32 func_00234778(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x01dbu << 16);
    return (u32)(*(u32*)((u32)b + (-7100)));
}
}  // namespace n00234778

// 00234788 (was gap)
namespace n00234788 {
extern u32 D_01dae448 asm("D_01dae448");
u32 func_00234788(void) asm("func_00234788");
u32 func_00234788(void) { return D_01dae448; }
}  // namespace n00234788

// 00234798 (was src/ishi/mcard.cpp)
namespace YI { // method 00234798
/*TARGET 00234798*/
u32 MCARD::GetResultChangeDir() {
    u32 b = (0x01dbu << 16);
    return (u32)(*(u32*)((u32)b + (-7092)));
}
}  // YI

// 002347a8 (was src/anon/tiny.cpp)
namespace n002347a8 {
/*TARGET 002347a8*/
u32 func_002347a8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002347a8jjjj");
u32 func_002347a8(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_global_1dbe468
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x01dbu << 16);
    return (u32)(*(u32*)((u32)b + (-7088)));
}
}  // namespace n002347a8

// 002347b8 (was src/anon/tiny.cpp)
namespace n002347b8 {
/*TARGET 002347b8*/
u32 func_002347b8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002347b8jjjj");
u32 func_002347b8(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_global_1dbe454
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x01dbu << 16);
    return (u32)(*(u32*)((u32)b + (-7084)));
}
}  // namespace n002347b8

// 002347c8 (was src/anon/tiny.cpp)
namespace n002347c8 {
/*TARGET 002347c8*/
u32 func_002347c8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002347c8jjjj");
u32 func_002347c8(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_global_1dbe470
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x01dbu << 16);
    return (u32)(*(u32*)((u32)b + (-7080)));
}
}  // namespace n002347c8

// 002347d8 (was src/anon/tiny.cpp)
namespace n002347d8 {
/*TARGET 002347d8*/
u32 func_002347d8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002347d8jjjj");
u32 func_002347d8(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_global_1dbe45c
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x01dbu << 16);
    return (u32)(*(u32*)((u32)b + (-7076)));
}
}  // namespace n002347d8

// 002347e8 (was src/anon/tiny.cpp)
namespace n002347e8 {
/*TARGET 002347e8*/
u32 func_002347e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002347e8jjjj");
u32 func_002347e8(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_global_1dbe460
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x01dbu << 16);
    return (u32)(*(u32*)((u32)b + (-7072)));
}
}  // namespace n002347e8

// 002347f8 (was gap)
namespace n002347f8 {
extern u32 D_01dae464 asm("D_01dae464");
u32 func_002347f8(void) asm("func_002347f8");
u32 func_002347f8(void) { return D_01dae464; }
}  // namespace n002347f8

// 00234808 (was gap)
namespace n00234808 {
extern u32 D_01dae468 asm("D_01dae468");
u32 func_00234808(void) asm("func_00234808");
u32 func_00234808(void) { return D_01dae468; }
}  // namespace n00234808

// 00234818 (was gap)
namespace n00234818 {
extern u32 D_01dae580[] asm("D_01dae580");
u32 func_00234818(s32 i) asm("func_00234818");
u32 func_00234818(s32 i) { return D_01dae580[i]; }
}  // namespace n00234818

// 00234830 (was gap)
namespace n00234830 {
extern u32 D_01dae588[] asm("D_01dae588");
u32 func_00234830(s32 i) asm("func_00234830");
u32 func_00234830(s32 i) { return D_01dae588[i]; }
}  // namespace n00234830

// 00234848 (was src/anon/tiny_auto80_solver.cpp)
namespace n00234848 {
extern u8 D_01dae480 asm("D_01dae480");
/*TARGET 00234848*/
u32 func_00234848(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00234848jjjjjjjj");
u32 func_00234848(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r4 = (u32)(r4 << 2);
    r15 = (u32)&D_01dae480;
    r4 = (u32)(r4 + r5);    r4 = (u32)(r4 << 5);
    r4 = (u32)(r4 + r15);
    r2 = *(u32*)((u32)r4 + (s32)(0));
    return r2;
}
}  // namespace n00234848

// 00234868 (was src/anon/tiny_auto80_solver.cpp)
namespace n00234868 {
extern u8 D_01dae480 asm("D_01dae480");
/*TARGET 00234868*/
u32 func_00234868(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00234868jjjjjjjj");
u32 func_00234868(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r4 = (u32)(r4 << 2);
    r15 = (u32)&D_01dae480;
    r4 = (u32)(r4 + r5);    r4 = (u32)(r4 << 5);
    r4 = (u32)(r4 + r15);
    r2 = *(u32*)((u32)r4 + (s32)(4));
    return r2;
}
}  // namespace n00234868

// 00234888 (was src/anon/tiny_auto80_solver.cpp)
namespace n00234888 {
extern u8 D_01dae480 asm("D_01dae480");
/*TARGET 00234888*/
u32 func_00234888(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00234888jjjjjjjj");
u32 func_00234888(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {  // entry32_word
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r4 = (u32)(r4 << 2);
    r15 = (u32)&D_01dae480;
    r4 = (u32)(r4 + r5);    r4 = (u32)(r4 << 5);
    r4 = (u32)(r4 + r15);
    r2 = *(u32*)((u32)r4 + (s32)(8));
    return r2;
}
}  // namespace n00234888

// 002348a8 (was src/ishi/mcard.cpp)
namespace YI { // method 002348a8
extern u8 D_01dae480[] asm("D_01dae480");
/*TARGET 002348a8*/
u32 MCARD::GetConnectionStatus(s32 a0, s32 a1) {
    u32 r4 = (u32)a0;
    u32 r5 = (u32)a1;
    u32 r15;
    r4 = (u32)(r4 << 2);
    r15 = (u32)&D_01dae480;
    r4 = (u32)(r4 + r5);
    r4 = (u32)(r4 << 5);
    r4 = (u32)(r4 + r15);
    return *(u32*)((u32)r4 + 12);
}
}  // YI

// 002348c8 (was gap)
namespace n002348c8 {
struct McRes { u32 a, b, c; };
struct McSlot { u32 f0, f4, f8, status; McRes res; u32 max; };
extern McSlot D_01dae480[][4] asm("D_01dae480");
void func_002348c8(s32 port, s32 slot) asm("func_002348c8");
void func_002348c8(s32 port, s32 slot) { D_01dae480[port][slot].status = 3; }
u32 func_002348f0(s32 port, s32 slot) asm("func_002348f0");
u32 func_002348f0(s32 port, s32 slot) { McSlot* s = &D_01dae480[port][slot]; McRes* r = &s->res; u32 v = r->a; r->a = 0; return v; }
void func_00234918(s32 port, s32 slot) asm("func_00234918");
void func_00234918(s32 port, s32 slot) { D_01dae480[port][slot].res.a = 0; }
u32 func_00234938(s32 port, s32 slot) asm("func_00234938");
u32 func_00234938(s32 port, s32 slot) { McSlot* s = &D_01dae480[port][slot]; McRes* r = &s->res; u32 v = r->b; r->b = 0; return v; }
void func_00234960(s32 port, s32 slot) asm("func_00234960");
void func_00234960(s32 port, s32 slot) { D_01dae480[port][slot].res.b = 0; }
u32 func_00234980(s32 port, s32 slot) asm("func_00234980");
u32 func_00234980(s32 port, s32 slot) { McSlot* s = &D_01dae480[port][slot]; McRes* r = &s->res; u32 v = r->c; r->c = 0; return v; }
void func_002349a8(s32 port, s32 slot) asm("func_002349a8");
void func_002349a8(s32 port, s32 slot) { D_01dae480[port][slot].res.c = 0; }
}  // namespace n002348c8

// 002349c8 (was src/ishi/mcard.cpp)
namespace YI { // method 002349c8
extern u8 D_01dae480[] asm("D_01dae480");
/*TARGET 002349c8*/
u32 MCARD::GetFileTableMax(s32 a0, s32 a1) {
    u32 r4 = (u32)a0;
    u32 r5 = (u32)a1;
    u32 r15;
    r4 = (u32)(r4 << 2);
    r15 = (u32)&D_01dae480;
    r4 = (u32)(r4 + r5);
    r4 = (u32)(r4 << 5);
    r4 = (u32)(r4 + r15);
    return *(u32*)((u32)r4 + 28);
}
}  // YI

// 002349e8 (was src/anon/batch_w26.cpp)
namespace n002349e8 {
extern u32 D_0035e370 asm("D_0035e370");
extern u32 D_01dae420[3] asm("D_01dae420");
extern void (*D_01dae41c)(u32) asm("D_01dae41c");
extern u32 D_0035e36c asm("D_0035e36c");
/*TARGET 002349e8*/
void func_002349e8(void) asm("func_002349e8");
void func_002349e8(void) {
    D_0035e370 = 0;
    D_01dae420[2] = D_01dae420[1];
    if (D_01dae41c) D_01dae41c(D_0035e36c);
}
}  // namespace n002349e8


// .rodata word at 0x3713c0 that no code loads (sits before the dispatcher's jump table).
extern "C" const s32 D_003713c0 = 42;

// 00234a30 (was gap, then src/anon/asm_00234a30.s)
namespace n00234a30 {
/* Memory card request dispatcher: pops the next request from the 64-entry ring into the work globals
   (D_0035e370 = request type, D_0035e374 = step, D_0035e36c = request id); with an empty ring it runs the
   periodic connection poll. Case 1 clears the step itself and returns (the stores are then scheduled in
   its own block; the shared `D_0035e374 = 0` after the switch is only for the other cases). */
extern s32 D_0035e36c asm("D_0035e36c");
extern s32 D_0035e374 asm("D_0035e374");
extern s32 D_01dae400 asm("D_01dae400");
extern s32 D_01dae404 asm("D_01dae404");
extern s32 D_01dae408 asm("D_01dae408");
extern s32 D_01dae40c asm("D_01dae40c");
extern s32 D_01dae410 asm("D_01dae410");
extern s32 D_01dae414 asm("D_01dae414");
extern s32 D_01dae418 asm("D_01dae418");
extern s32 D_01dae41c asm("D_01dae41c");
extern s32 D_01dae46c asm("D_01dae46c");
extern s32 D_01dae478 asm("D_01dae478");
extern s32 D_01dae47c asm("D_01dae47c");
struct McEnt { s32 type, id, a, b, c, d, e, f; };
struct McPoll { u8 on; s32 interval; s32 timer; s32 port; s32 slot; };
extern McEnt D_01dadc00[64] asm("D_01dadc00");
extern s32 D_0035e360 asm("D_0035e360");
extern s32 D_0035e364 asm("D_0035e364");
extern s32 D_0035e370 asm("D_0035e370");
extern McPoll D_01dae420 asm("D_01dae420");
extern s32 D_01dae588[2] asm("D_01dae588");
void func_00234a30(void) asm("func_00234a30");
void func_00234a30(void) {
    if (D_0035e360 != D_0035e364) {
        switch (D_01dadc00[D_0035e364].type) {
        case 1: {
            s32 t = D_0035e364;
            McEnt* e = &D_01dadc00[t];
            D_0035e370 = 1;
            D_0035e374 = 0;
            D_01dae400 = 3;
            D_01dae404 = 0;
            D_01dae478 = e->a;
            D_01dae47c = e->b;
            D_01dae41c = e->c;
            D_0035e36c = e->id;
            D_0035e364 = (t + 1) & 63;
            return; }
        case 2: {
            s32 t = D_0035e364;
            McEnt* e = &D_01dadc00[t];
            D_0035e370 = 2;
            D_01dae478 = e->a;
            D_01dae47c = e->b;
            D_01dae46c = e->c;
            D_01dae418 = e->d;
            D_01dae408 = e->e;
            D_01dae41c = e->f;
            D_0035e36c = e->id;
            D_0035e364 = (t + 1) & 63;
            break; }
        case 3: {
            s32 t = D_0035e364;
            McEnt* e = &D_01dadc00[t];
            D_0035e370 = 3;
            D_01dae478 = e->a;
            D_01dae47c = e->b;
            D_01dae408 = e->c;
            D_01dae46c = e->d;
            D_01dae418 = e->e;
            D_01dae41c = e->f;
            D_0035e36c = e->id;
            D_0035e364 = (t + 1) & 63;
            break; }
        case 4: {
            s32 t = D_0035e364;
            McEnt* e = &D_01dadc00[t];
            D_0035e370 = 4;
            D_01dae478 = e->a;
            D_01dae47c = e->b;
            D_01dae41c = e->c;
            D_0035e36c = e->id;
            D_0035e374 = 0;
            D_01dae400 = 0;
            D_01dae404 = 0;
            D_0035e364 = (t + 1) & 63;
            return; }
        case 5: {
            s32 t = D_0035e364;
            McEnt* e = &D_01dadc00[t];
            D_0035e370 = 5;
            D_01dae478 = e->a;
            D_01dae47c = e->b;
            D_01dae41c = e->c;
            D_0035e36c = e->id;
            D_0035e374 = 0;
            D_01dae400 = 0;
            D_01dae404 = 0;
            D_0035e364 = (t + 1) & 63;
            return; }
        case 6: {
            s32 t = D_0035e364;
            McEnt* e = &D_01dadc00[t];
            D_0035e370 = 6;
            D_01dae478 = e->a;
            D_01dae47c = e->b;
            D_01dae408 = e->c;
            D_01dae41c = e->d;
            D_0035e36c = e->id;
            D_0035e364 = (t + 1) & 63;
            break; }
        case 7: {
            s32 t = D_0035e364;
            McEnt* e = &D_01dadc00[t];
            D_0035e370 = 7;
            D_01dae478 = e->a;
            D_01dae47c = e->b;
            D_01dae408 = e->c;
            D_01dae41c = e->d;
            D_0035e36c = e->id;
            D_0035e364 = (t + 1) & 63;
            break; }
        case 8: {
            s32 t = D_0035e364;
            McEnt* e = &D_01dadc00[t];
            D_0035e370 = 8;
            D_01dae478 = e->a;
            D_01dae47c = e->b;
            D_01dae408 = e->c;
            D_01dae410 = e->d;
            D_01dae414 = e->e;
            D_01dae41c = e->f;
            D_0035e36c = e->id;
            D_0035e364 = (t + 1) & 63;
            break; }
        case 9: {
            s32 t = D_0035e364;
            McEnt* e = &D_01dadc00[t];
            D_0035e370 = 9;
            D_01dae478 = e->a;
            D_01dae47c = e->b;
            D_01dae408 = e->c;
            D_01dae41c = e->d;
            D_0035e36c = e->id;
            D_0035e364 = (t + 1) & 63;
            break; }
        case 10: {
            s32 t = D_0035e364;
            McEnt* e = &D_01dadc00[t];
            D_0035e370 = 10;
            D_01dae478 = e->a;
            D_01dae47c = e->b;
            D_01dae408 = e->c;
            D_01dae410 = e->d;
            D_01dae414 = e->e;
            D_01dae41c = e->f;
            D_0035e36c = e->id;
            D_0035e364 = (t + 1) & 63;
            break; }
        case 11: {
            s32 t = D_0035e364;
            McEnt* e = &D_01dadc00[t];
            D_0035e370 = 11;
            D_01dae478 = e->a;
            D_01dae47c = e->b;
            D_01dae408 = e->c;
            D_01dae410 = e->d;
            D_01dae414 = e->e;
            D_01dae41c = e->f;
            D_0035e36c = e->id;
            D_0035e364 = (t + 1) & 63;
            break; }
        case 12: {
            s32 t = D_0035e364;
            McEnt* e = &D_01dadc00[t];
            D_0035e370 = 12;
            D_01dae478 = e->a;
            D_01dae47c = e->b;
            D_01dae408 = e->c;
            D_01dae40c = e->d;
            D_01dae41c = e->e;
            D_0035e36c = e->id;
            D_0035e364 = (t + 1) & 63;
            break; }
        case 13: {
            s32 t = D_0035e364;
            McEnt* e = &D_01dadc00[t];
            D_0035e370 = 13;
            D_01dae41c = e->a;
            D_0035e36c = e->id;
            D_0035e364 = (t + 1) & 63;
            return; }
        default: return;
        }
        D_0035e374 = 0;
    } else if (D_01dae420.on) {
        if (D_01dae420.timer != 0) {
            D_01dae420.timer--;
            return;
        }
        s32 port = D_01dae420.port;
        s32 slot = D_01dae420.slot;
        D_0035e370 = 1;
        D_01dae420.timer = D_01dae420.interval;
        D_0035e374 = 0;
        D_01dae400 = 0;
        D_01dae404 = 0;
        D_01dae478 = port;
        D_01dae47c = slot;
        D_01dae41c = 0;
        if (slot == D_01dae588[port] - 1) {
            D_01dae420.slot = 0;
            D_01dae420.port = (port + 1) % 2;
        } else {
            D_01dae420.slot = slot + 1;
        }
    }
}
}  // namespace n00234a30
