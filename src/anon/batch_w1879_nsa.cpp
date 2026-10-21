#include "../common/types.h"
struct V4 { f32 x, y, z, w; V4() {} V4(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; } } __attribute__((aligned(16)));
struct Node { void* vt; s32 f4; s32 f8; u8 sub[0x58]; s32 f64; s32 pad68; s32 f6c; s32 f70; s32 f74; s32 f78; Node* next; s32 f80; };
struct List { Node* head; Node* tail; };
extern "C" {
extern u8 D_00350c50[];
extern List D_01c6ced0;
s32 func_00192048(s32);
void func_001a98e8(void*, s32, s32, s32, s32);
s32 func_001a9808(s32, s32);
static inline Node* nextOf(Node* p) { return p ? p->next : D_01c6ced0.head; }
void func_001ac378(Node* self, s32 a1, s32 a2, s32 a3, s32 pri, s32 b4, s32 b8) {
    self->f4 = b4;
    self->f8 = b8;
    self->vt = D_00350c50;
    func_001a98e8(self->sub, a1, func_00192048(a3), 0, 0);
    self->f6c = func_001a9808(a2, -1);
    self->f64 = 3;
    self->f80 = a3;
    self->f70 = 0;
    self->f74 = 0;
    self->f78 = pri;
    Node* p = 0;
    Node* prev = 0;
    for (; (p = nextOf(p)) != 0; prev = p) {
        if (pri < p->f78) break;
    }
    if (prev == 0) {
        if (D_01c6ced0.head == 0) {
            D_01c6ced0.tail = self;
            D_01c6ced0.head = self;
            self->next = 0;
        } else {
            self->next = D_01c6ced0.head;
            D_01c6ced0.head = self;
        }
    } else if (prev == D_01c6ced0.tail) {
        prev->next = self;
        self->next = 0;
        D_01c6ced0.tail = self;
    } else {
        self->next = prev->next;
        prev->next = self;
    }
}

// VU0 macro asm (vector subtract, normalize, dot product), as in the original.
extern void* D_0034e948;
V4* func_0016c028(void*);
void func_0016af58(V4*, void*);
void func_0015b1b0(u8, u8, u8);
void func_0015b268(f32, s32);
s32 func_001967f0(u8, u8, s32);
static inline f32 vnorm(V4* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
s32 func_0019a6c0(void* self, u8* ids, f32* pos, u8 flag, u8 arg) {
    f32 z = 0.0f;
    void* obj = D_0034e948;
    V4 v(pos[1], z, pos[3], z);
    V4* r = func_0016c028(obj);
    asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&v), "r"(r) : "memory");
    v.y = z;
    vnorm(&v);
    V4 w;
    func_0016af58(&w, obj);
    f32 dot;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(dot) : "r"(&v), "r"(&w) : "$8", "memory");
    if (dot >= z) {
        if (flag) func_0015b1b0(ids[1], ids[0], arg);
        else func_0015b268(6.0f, func_001967f0(ids[0], ids[1], 0));
        return 1;
    }
    return 0;
}
}
