#include "../common/types.h"

// 16-byte vector; assignment copies with a 128-bit lq/sq.
struct W1638Vq {
    f32 x, y, z, w;
    W1638Vq& operator=(const W1638Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    void zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); }
    void add(const W1638Vq& b) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "r"(&b) : "memory");
    }
};

// 4x4 matrix; assignment copies with four 128-bit lq/sq.
struct W1638Mtx {
    f32 m[4][4];
    W1638Mtx& operator=(const W1638Mtx& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
};

extern "C" void func_0011c138(void*);
// 32-byte work node built by func_0011c138 (array of these handed to the model update).
struct W1638Node {
    u8 pad[32];
    W1638Node() { func_0011c138(this); }
    ~W1638Node() {}
};

struct W1638Anim;
struct W1638AnimVt { void* pad[7]; f32 (*length)(W1638Anim*); };
struct W1638Anim { W1638AnimVt* vt; };

// queued motion request (20 bytes)
struct W1638Req {
    s32 id;
    f32 blend;
    f32 start;
    void (*fn)(u8*);
    s32 flags;
};
struct W1638Queue {
    s32 tail;
    union { s32 head; u8 head_c; };
    W1638Req e[4];
    bool empty() { return head == tail; }
    s32 pop() { s32 h = head; head = (h + 1) % 4; return h; }
};

struct W1638Motion {
    u8 pad0[8];
    u8* obj;               // 0x08
    W1638Anim* anim;       // 0x0c
    u32 anmatr;            // 0x10
    s32 cur;               // 0x14
    u32 pad18;
    u32 f1c;               // 0x1c
    union {
        u32 flags;         // 0x20
        struct {
            u32 fstop : 1;
            u32 floop : 1;
            u32 fb2 : 5;
            u32 fb7 : 1;
            u32 fb8 : 1;
            u32 fb9 : 3;
            u32 fb12 : 1;
            u32 fb13 : 1;
            u32 fb14 : 18;
        };
    };
    u32 pad24[2];
    f32 end;               // 0x2c
    f32 time;              // 0x30
    f32 hold;              // 0x34
    f32 loop_start;        // 0x38
    W1638Queue q;          // 0x3c
    u8 pad94[0xa0 - 0x94];
    W1638Vq pos;           // 0xa0
    W1638Vq rot;           // 0xb0
    W1638Vq prev;          // 0xc0
    u32 fd0;               // 0xd0
    u32 fd4;
    u8 padd8[0xf0 - 0xd8];
    u32 ff0;               // 0xf0
    f32 speed;             // 0xf4
    u8 bf8;
    u8 bf9;                // 0xf9
    u8 padfa[2];
    u32 ffc;               // 0xfc
    u32 f100;              // 0x100
    u32 f104;              // 0x104
    bool has_hold() { return hold > 0.0f; }
};

extern "C" {
s32 W1638_is_no_motion(W1638Motion*) asm("_ZN2YS6MOTION12is_no_motionEv");
void W1638_exec_trigger(W1638Motion*, f32, f32) asm("_ZNK2YS6ANMATR12exec_triggerEPNS_6MOTIONEff");
void W1638_check_range(W1638Motion*, f32) asm("_ZNK2YS6ANMATR11check_rangeEPNS_6MOTIONEf");
u32 W1638_is_player(u32, s32) asm("_ZNK2YS9MOTIONSET9is_playerEv");
void func_0017fef0(W1638Motion*, f32);
void func_00189258(W1638Motion*);
void func_0019be88(u8*);
void func_001801b0(u32, u32, u32, u8*, u32, f32);
void func_0017f268(W1638Motion*, s32, f32, f32);
void W1638_identity(W1638Mtx*) asm("_Z13func_0011b6a8Pv");
W1638Mtx& W1638_rotateY(W1638Mtx*, f32) asm("_ZN2kn7FMatrix7rotateYEf");
u32 W1638_get_allocator(void) asm("_ZN4AREA12GetAllocatorEv");
u32 W1638_copy_pose(u32, u32) asm("_Z13func_00127a88Pv");
void W1638_matrix_swap(u32) asm("_ZN2kn8ModelObj10matrixSwapEv");
void func_0017ee68(W1638Motion*);
void func_0017fff8(W1638Motion*);
void func_0017fdf8(W1638Motion*);
void func_001808c0(W1638Motion*, W1638Node*);
void func_00124b10(u32, W1638Mtx*);
u32 func_001b0580(u8*);
void func_0011c4e8(u32, u8*, W1638Anim*, u32, W1638Node*, u32, f32);
void func_00180b98(W1638Motion*);
void func_00180e28(W1638Motion*);

// ---- 0017f620: advance the motion by dt: hold/loop handling, end of clip, next queued request, triggers.
void func_0017f620(W1638Motion* m, f32 dt) {
    m->bf9 = 0;
    if (W1638_is_no_motion(m)) return;
    W1638Vq* rot = &m->rot;
    rot->zero();
    if (m->fstop) return;
    m->floop = 0;
    m->fb8 = 0;
    f32 old = m->time;
    m->time += dt * m->speed;
    if (m->has_hold()) {
        if (m->hold <= m->time) {
            m->time = (m->time - m->hold) + m->loop_start;
            m->hold = 0.0f;
            m->fstop = 1;
            W1638_exec_trigger(m, m->loop_start, -1.0f);
            W1638_exec_trigger(m, m->loop_start, m->time);
        }
    } else if (m->end <= m->time) {
        W1638Vq tmp;
        W1638_exec_trigger(m, old, m->end);
        func_0017fef0(m, m->end);
        tmp = *rot;
        m->time -= m->end;
        W1638Queue* q = &m->q;
        if (q->empty()) {
            func_0017fef0(m, m->anim->vt->length(m->anim));
            m->time += m->anim->vt->length(m->anim);
            if (m->end < m->time) {
                m->time = m->end;
            } else {
                W1638_exec_trigger(m, m->anim->vt->length(m->anim), m->time);
            }
            rot->zero();
            func_0017fef0(m, m->time);
            rot->add(tmp);
            func_0019be88(m->obj);
        } else {
            if (m->f1c) func_0019be88(m->obj);
            s32 h = q->pop();
            W1638Req* e = &q->e[h];
            if (e->fn) e->fn(m->obj);
            if (q->e[h].flags % 2) {
                m->cur = e->id;
                u32 sv = m->f100;
                func_001801b0(m->ffc, W1638_is_player(sv, e->id), m->ff0, m->obj, 0, e->blend);
                m->f100 = sv;
            } else {
                func_0017f268(m, e->id, e->blend, e->start);
            }
        }
        m->floop = 1;
    } else {
        W1638_exec_trigger(m, old, m->time);
    }
    func_00189258(m);
    W1638_check_range(m, m->has_hold() ? m->loop_start : m->time);
}
}
