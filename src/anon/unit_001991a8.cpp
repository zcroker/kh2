#include "../common/types.h"

// Event watches (0x1991a8-0x199688): up to four pending events, each fired once a watched
// object's HP ratio falls to a limit (type 0) or its gauge fills (type 1). A task polls them.

struct WATCH {
    s32 type;       // 0: hp ratio <= rate, 1: gauge full
    s32 event;      // 4
    s32 arg;        // 8
    u32 obj;        // 12
    f32 rate;       // 16
    WATCH* next;    // 20
};

struct WATCH_POOL {
    WATCH e[4];
    s32 free[4];
    s32 n;
    WATCH_POOL() {
        WATCH_POOL* p = this;
        s32 i;
        for (i = 0; i < 4; i++) p->free[i] = i;
        p->n = 4;
    }
    void reset() {
        for (s32 i = 0; i < 4; i++) free[i] = i;
        n = 4;
    }
    WATCH* alloc() { return &e[free[--n]]; }
};

struct WATCH_LIST {
    WATCH* head;
    WATCH* tail;
    WATCH_LIST() { clear(); }
    void clear() { head = 0; tail = 0; }
    void push_front(WATCH* p) {
        if (head == 0) {
            tail = p;
            head = p;
            p->next = 0;
        } else {
            p->next = head;
            head = p;
        }
    }
    WATCH* next(WATCH* p) {
        if (!p) return head;
        return p->next;
    }
};

static WATCH_POOL s_pool;
static WATCH_LIST s_list;

extern "C" {
extern s32 D_00350438;
void func_00105de0(s32);
void func_002430b0(s32);
s32 func_0016b7a0(s32);
void func_00196b28(s32, s32);
void func_0016bb38(s32, s32);
s32 func_00198cb8(s32, s32);
s32 func_0019ba60(u32) asm("_Z16ctarget_0019ba60jjjj");
void func_00102c18(s32, s32, void*);

void func_001993a0(s32 event);
void func_00199280(void);

s32 func_001991a8(s32 n, s32 a) {
    s32 r = 1;
    func_001993a0(n);
    switch (n) {
    case 19:
    case 102: case 103: case 104: case 105: case 106: case 107: case 108: case 109:
    case 110: case 111: case 112: case 113: case 114: case 115: case 116: case 117:
    case 131: case 132: case 133: case 138:
        func_00105de0(n);
        break;
    case 22: case 70: case 79: case 87: case 88: case 89: case 98: case 100: case 101:
    case 118: case 129:
        func_002430b0(n);
        break;
    default:
        if ((n == 8 || n == 130) && a != 0) D_00350438 = func_0016b7a0(a);
        func_00196b28(n, a);
        func_0016bb38(n, a);
        r = func_00198cb8(n, a);
        break;
    }
    return r;
}

void func_00199280(void) {
    WATCH* e = 0;
    while ((e = s_list.next(e)) != 0) {
        u32 o;
        s32* st;
        switch (e->type) {
        case 1:
            o = e->obj;
            if (!func_0019ba60(o)) continue;
            st = *(s32**)(o + 1164);
            if (!st) continue;
            if (st[0] > st[2]) continue;
            break;
        case 0:
            o = e->obj;
            if (!func_0019ba60(o)) continue;
            st = *(s32**)(o + 1164);
            if (!st) continue;
            if (!((f32)st[0] / (f32)st[1] <= e->rate)) continue;
            break;
        default:
            continue;
        }
        func_001991a8(e->event, e->arg);
        return;
    }
}

// Takes a watch out of the list and gives its slot back to the pool.
// The register pins keep prev in t3 and the list head in t7, as in the original.
static inline __attribute__((always_inline)) void watch_remove(WATCH* n) {
    register WATCH* prev asm("$11");
    register WATCH* h asm("$15") = s_list.head;
    if (n == h) {
        s_list.head = *(WATCH* volatile*)&n->next;
        prev = 0;
    } else {
        WATCH* it;
        for (it = h; it->next != n; it = it->next) ;
        prev = it;
        prev->next = *(WATCH* volatile*)&n->next;
    }
    WATCH_LIST* l = &s_list;
    if (__builtin_expect(n == l->tail, 0)) l->tail = prev;
    n->next = 0;
    s_pool.free[s_pool.n++] = (s32)(n - s_pool.e);
}

// Removes every watch for this event.
void func_001993a0(s32 event) {
    WATCH* c;
    WATCH* n;
    for (c = s_list.head; __builtin_expect(c != 0, 0); c = n) {
        n = c->next;
        if (c->event == event) watch_remove(c);
    }
}

void func_00199468(u32 obj, s32 event, s32 arg, f32 rate) {
    WATCH* e = s_pool.alloc();
    e->event = event;
    e->arg = arg;
    e->obj = obj;
    e->rate = rate;
    e->type = 0;
    s_list.push_front(e);
}

void func_001994d8(u32 obj, s32 event, s32 arg) {
    WATCH* e = s_pool.alloc();
    e->type = 1;
    e->event = event;
    e->arg = arg;
    e->obj = obj;
    s_list.push_front(e);
}

void func_00199548(void) {
    s_pool.reset();
    s_list.clear();
    func_00102c18(1, 14500, (void*)func_00199280);
}

void func_001995b8(u32 a, u32 b) {
    WATCH* e = 0;
    while ((e = s_list.next(e)) != 0) {
        if (e->obj == a) e->obj = b;
    }
}

}
