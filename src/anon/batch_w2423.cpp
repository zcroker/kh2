#include "../common/types.h"
// 00152bd8 (w2423): three ring-buffer queues. Queue reference plus the ready test written through self, expect on the loop-exit test.
struct W1631Entry {
    u8 pad0[0x1c4];
    s32 hasExt;     // 0x1c4
    s32 b;          // 0x1c8
    s32 a;          // 0x1cc
    s32 c;          // 0x1d0
    s32 d;          // 0x1d4
    u8 info[64];    // 0x1d8
    u8 ext[64];     // 0x218
};
extern "C" {
s32 func_00139d78(void*);
s32 func_001525b8(W1631Entry*, s32, s32, void*, void*, s32, s32, s32);
s32 func_00152990(W1631Entry*, s32, s32, void*, void*, s32, s32, s32);
s32 func_00152ab8(W1631Entry*, s32, s32, void*, void*, s32, s32, s32);
}
typedef s32 (*W1631EntryFn)(W1631Entry*, s32, s32, void*, void*, s32, s32, s32);
template <int N> struct W1631Ring {
    s32 w;
    s32 r;
    W1631Entry e[N];
    bool isEmpty() { return r == w; }
    W1631Entry* front() { return &e[r]; }
    W1631Entry* pop() {
        s32 idx = r;
        r = (idx + 1) % N;
        return &e[idx];
    }
};
template <int N> struct W1631Queue {
    W1631Entry* cur;
    s32 acc;
    u32 flags;
    W1631Ring<N> ring;
    template <W1631EntryFn fn> __attribute__((always_inline)) void process() {
        s32 i;
        cur = ring.front();
        for (i = 0; i < 4; i++) {
            W1631Entry* e = ring.pop();
            acc += fn(e, e->a, e->b, e->info, e->hasExt ? e->ext : 0, e->c, e->d, acc);
            s32 em = ring.isEmpty();
            if (__builtin_expect(em, 1)) break;
        }
        flags &= ~1;
    }
    __attribute__((always_inline)) void check() {
        if (cur && !func_00139d78(cur)) {
            cur = 0;
            acc = 0;
            flags |= 1;
        }
    }
};
struct W1631Disp {
    u8 pad0[0x18];
    W1631Queue<16> q0;  // 0x18
    W1631Queue<4> q1;   // 0x25ac
    W1631Queue<4> q2;   // 0x2f20
};
extern "C" {

void func_00152bd8(W1631Disp* self) {
    {
        W1631Queue<16>& q = self->q0;
        if (!self->q0.ring.isEmpty() && (s32)(self->q0.flags & 1) == 1) q.process<func_001525b8>();
        q.check();
    }
    {
        W1631Queue<4>& q = self->q1;
        if (!self->q1.ring.isEmpty() && (s32)(self->q1.flags & 1) == 1) q.process<func_00152990>();
        q.check();
    }
    {
        W1631Queue<4>& q = self->q2;
        if (!self->q2.ring.isEmpty() && (s32)(self->q2.flags & 1) == 1) q.process<func_00152ab8>();
        q.check();
    }
}
}
