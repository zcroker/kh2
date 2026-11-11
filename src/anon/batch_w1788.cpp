#include "../common/types.h"

struct W1788V4 {
    f32 x, y, z, w;
    W1788V4() {}
    W1788V4& operator=(const W1788V4& o) {
        // 128-bit copy (lq/sq), skipped for self-assignment
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1788M4 { W1788V4 r[4]; };
struct W1788Hit { W1788V4 pos; W1788V4 nrm; };

// VU0 macro code: vector subtract, normalize, matrix row scale
static inline W1788V4 operator-(const W1788V4& a, const W1788V4& b) {
    W1788V4 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 W1788_norm(W1788V4* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline void W1788_scaleM(W1788M4* m, W1788V4* s) {
    asm volatile(".set noreorder\n\tlqc2 $vf4, 0(%1)\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tvmulx.wxyz $vf1, $vf1, $vf4x\n\tvmuly.wxyz $vf2, $vf2, $vf4y\n\tvmulz.wxyz $vf3, $vf3, $vf4z\n\tsqc2 $vf1, 0(%0)\n\tsqc2 $vf2, 16(%0)\n\tsqc2 $vf3, 32(%0)\n\t.set reorder" : : "r"(m), "r"(s) : "memory");
}

struct W1788Obj { W1788V4* pos; f32 scale; };
struct W1788Node { u8 pad[0x28]; s32 pri; u8 pad2[0x3c - 0x2c]; W1788Node* next; };
struct W1788List { W1788Node* first; W1788Node* last; };
extern W1788List D_0034dca0;
struct W1788QEnt { s32* p; s32 flags; };
struct W1788Q { s32 rd; s32 wr; W1788QEnt e[16]; u8 pad[0x98 - 0x88]; s32 busy; };

extern "C" {
void func_0011b6a8(W1788M4*);
W1788V4* func_0016c028();
void func_0018b008(void*, W1788V4*, void*, W1788V4*);
void* func_002edbf8(s32);
void func_001880b0(void*, s32);
void func_00187fd8(W1788Q*, s32*);
s32 func_001d35e0(W1788Hit*, W1788V4*, W1788V4*, u32);

static inline __attribute__((always_inline)) void W1788_link(W1788Node* n, W1788Node* prev) {
    if (!prev) {
        if (!D_0034dca0.first) {
            D_0034dca0.last = n;
            D_0034dca0.first = n;
            n->next = 0;
        } else {
            n->next = D_0034dca0.first;
            D_0034dca0.first = n;
        }
    } else if (prev == D_0034dca0.last) {
        prev->next = n;
        n->next = 0;
        D_0034dca0.last = n;
    } else {
        n->next = prev->next;
        prev->next = n;
    }
}

void func_00170188(W1788Node* n) {
    W1788Node* prev = 0;
    W1788Node* cur;
    while ((cur = prev ? prev->next : D_0034dca0.first) != 0) {
        if (n->pri >= 0) {
            if (n->pri < cur->pri) break;
        } else {
            if (cur->pri < 0 && n->pri < cur->pri) break;
        }
        prev = cur;
    }
    W1788_link(n, prev);
}

// 00187be8: moved to src/anon/unit_00185d10.cpp
s32 func_00187be8(W1788Q* q);

void func_0018b010(void* a, W1788V4* p, void* c) {
    W1788V4 d;
    d = *p - *func_0016c028();
    W1788_norm(&d);
    func_0018b008(a, &d, c, p);
}
}

// 001a7610: moved to src/yasui/libys/bg.cpp
