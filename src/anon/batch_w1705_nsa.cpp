#include "../common/types.h"

// 0023de00: per-frame update of the owner's animated props (idle/action motion cycling + matrix build).
// Needs -fno-strict-aliasing (state/time stores stay before the vtable-pointer reloads).

struct W1705Vec { f32 x, y, z, w; } __attribute__((aligned(16)));
struct W1705Mtx { W1705Vec r[4]; };

struct W1705Motion {
    virtual void v0();
    virtual void v1();
    virtual s32 GetEnd();      // +0x08
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual f32 GetStart();    // +0x1c
};

struct W1705Prop {
    W1705Vec rot;          // 0x00 degrees
    W1705Vec pos;          // 0x10
    W1705Vec scale;        // 0x20
    s32 model;             // 0x30
    u8 pad34[0x74 - 0x34];
    W1705Motion* idle;     // 0x74
    W1705Motion* act1;     // 0x78
    W1705Motion* act2;     // 0x7c
    W1705Mtx mtx;          // 0x80
    u8 padC0[0x128 - 0xc0];
    s32 state;             // 0x128
    f32 time;              // 0x12c
    f32 wait;              // 0x130
    f32 waitMax;           // 0x134
    u8 pad138[4];
    u8 active;             // 0x13c
    u8 pad13d[3];

};

struct W1705Owner {
    u8 pad0[0x660];
    W1705Prop props[4];         // 0x660
    u8 padB5C[0xb64 - (0x660 + 4 * 0x140)];
    u8 propIdx[8];              // 0xb64
    s32 count;                  // 0xb6c
    u8 padB70[0x14b0 - 0xb70];
    s32 handleA[4];             // 0x14b0
    s32 handleB[4];             // 0x14c0
};

extern "C" {
s32 func_001064a8(s32);
void func_0011b6a8(W1705Mtx*);
void func_0011b7b0(W1705Mtx*, W1705Vec*);
void func_0011c4e8(f32, s32, W1705Mtx*, W1705Motion*, s32, s32, s32);
void func_0011ea40(f32, s32);
u8 u_call4_00139d78(s32) asm("_Z16u_call4_00139d78jjjj");
f32 func_0014ce78(void);
void func_0023d820(W1705Owner*);
f32 func_0023e700(W1705Owner*);

void func_0023de00(W1705Owner* o)
{
    s32 i;
    for (i = 0; i < o->count; i++) {
        W1705Prop* p = &o->props[o->propIdx[i]];
        if ((o->handleA[i] && !u_call4_00139d78(o->handleA[i])) ||
            (o->handleB[i] && !u_call4_00139d78(o->handleB[i]))) {
            func_0023d820(o);
            return;
        }
        if (p->active) {
            f32 dt = func_0014ce78();
            W1705Motion* m;
            switch (p->state) {
            case 0: m = p->idle; break;
            case 1: m = p->act1; break;
            case 2: m = p->act2; break;
            default: m = p->idle; break;
            }
            p->time += dt;
            if (p->state == 0) {
                p->wait += dt;
                if (p->wait >= p->waitMax && p->act1) {
                    p->state = func_001064a8(2) + 1;
                    if (p->state == 2 && !p->act2) p->state = 1;
                    p->time = p->idle->GetStart();
                } else if ((f32)p->idle->GetEnd() < p->time) {
                    p->time = p->time - (f32)p->idle->GetEnd();
                }
                if (p->time < p->idle->GetStart()) p->time = p->time + p->idle->GetStart();
            } else if ((s32)p->time > m->GetEnd()) {
                p->state = 0;
                p->time = p->idle->GetStart();
                p->wait = p->idle->GetStart();
                p->waitMax = func_0023e700(o);
            }
            switch (p->state) {
            case 0: m = p->idle; break;
            case 1: m = p->act1; break;
            case 2: m = p->act2; break;
            default: m = p->idle; break;
            }
            W1705Mtx* mtx = &p->mtx;
            func_0011b6a8(mtx);
            W1705Vec r;
            asm volatile("sqc2 $vf0, 0(%0)" : : "r"(&r) : "memory");
            r.x = p->rot.x * 0.017453292f;
            r.y = p->rot.y * 0.017453292f;
            r.z = p->rot.z * 0.017453292f;
            func_0011b7b0(mtx, &r);
            asm volatile("lqc2 $vf1, 48(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 48(%0)"
                         : : "r"(mtx), "r"(&p->pos) : "memory");
            asm volatile("lqc2 $vf4, 0(%1)\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\t"
                         "vmulx.wxyz $vf1, $vf1, $vf4x\n\tvmuly.wxyz $vf2, $vf2, $vf4y\n\tvmulz.wxyz $vf3, $vf3, $vf4z\n\t"
                         "sqc2 $vf1, 0(%0)\n\tsqc2 $vf2, 16(%0)\n\tsqc2 $vf3, 32(%0)"
                         : : "r"(mtx), "r"(&p->scale) : "memory");
            func_0011c4e8(p->time, p->model, mtx, m, 0, 0, 0);
            func_0011ea40(dt, p->model);
        }
    }
}
}
