#include "../common/types.h"

struct W1622Base0 { virtual void w1622k(); u32 a[3]; };
struct W1622Base : W1622Base0 { u32 x, y; };
struct W1622A : W1622Base {
    u8 sub[344];
    u32 f170[4];
    f32 f180;
    u32 f184[4];
    u8 p, q;
    W1622A& operator=(const W1622A&) asm("func_0031a1a0");
};
struct W1622Sub : W1622Base0 { u32 x, y; } __attribute__((aligned(8)));
struct W1622Blk { u32 vt; u8 body[412]; W1622Blk& operator=(const W1622Blk&) asm("func_0031a068"); } __attribute__((aligned(16)));
struct W1622Req0 : W1622A {
    u32 f198, f19c, f1a0, f1a4, f1a8, f1ac, f1b0;
};
struct W1622Req : W1622Req0 {
    f32 rate;
    u32 f1b8;
};
struct W1622Item1Base : W1622Req {
    W1622Sub b;
    W1622Blk blk;
    W1622A a2;
    u32 f518;
};
struct W1622Item1 : W1622Item1Base {
    u32 f520 __attribute__((aligned(8)));
    u32 f524;
};
struct W1622Item2 : W1622Req {
    u32 tail[8];
};
template <class T, int N> struct W1622Ring {
    s32 head;
    s32 tail;
    T item[N];
    bool empty() { return tail == head; }
    T& front() { return item[tail]; }
    T& pop() { T& r = item[tail]; tail = (tail + 1) % N; return r; }
};
struct W1622Flags {
    u32 bits;
    bool busy() { return bits & 1; }
    bool more() { u32 m = bits & 2; return m != 0; }
    void setBusy() { bits |= 1; }
    void clearBusy() { bits &= ~1; }
    void setMore(bool b) { if (b) bits |= 2; else bits &= ~2; }
};
struct W1622Mgr {
    void* vt;
    u8 pad4[28];
    W1622Flags f1;
    u8 pad24[12];
    W1622Ring<W1622Item1, 8> q1;
    W1622Flags f2;
    W1622Ring<W1622Item2, 16> q2;
};

extern "C" {
void func_001375f0(W1622Item1*, u32, u32);
void func_00137840(W1622Item2*, u32*);
s32 func_00139d78(void*);

void func_00137c88(W1622Mgr* m) {
    if (!m->q1.empty()) {
        W1622Item1* cur = &m->q1.front();
        if (m->f1.busy() == true) {
            func_001375f0(cur, cur->f520, cur->f524);
            m->f1.clearBusy();
            if (m->f1.more() == true) cur->rate = 0;
        } else if (!func_00139d78(cur)) {
            *cur = m->q1.pop();
            m->f1.setBusy();
            m->f1.setMore(!m->q1.empty());
        }
    }
    if (!m->q2.empty()) {
        W1622Item2* cur = &m->q2.front();
        if (m->f2.busy() == true) {
            func_00137840(cur, cur->tail);
            m->f2.clearBusy();
            if (m->f2.more() == true) cur->rate = 0;
        } else if (!func_00139d78(cur)) {
            *cur = m->q2.pop();
            m->f2.setBusy();
            m->f2.setMore(!m->q2.empty());
        }
    }
}
}
