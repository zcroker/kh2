#include "../common/types.h"

// Request queue (0x2bac78-0x2bb070): up to 32 requests, run one after another by a task.
// Each request starts one of four kinds of job, waits until it is done, then calls back.

struct REQ {
    void (*cb)(s32);  // 0
    s32 arg;          // 4
    u32 next;         // 8  queue link (links held as integers, as in the original)
    u32 doneNext;     // 12 done list link
    s32 a;            // 16
    s32 type;         // 20
    s32 b;            // 24
    s32 c;            // 28
};

struct REQ_QUEUE {
    u32 head;
    u32 tail;
    REQ_QUEUE() { clear(); }
    void clear() { tail = 0; head = 0; }
    u32 iter(u32 p) {
        if (!p) return head;
        return ((REQ*)p)->next;
    }
};

struct REQ_DONE {
    u32 head;
    u32 tail;
    REQ_DONE() { clear(); }
    void clear() { tail = 0; head = 0; }
    u32 iter(u32 p) {
        if (!p) return head;
        return ((REQ*)p)->doneNext;
    }
};

struct REQ_POOL {
    REQ e[32];
    s32 free[32];
    s32 n;
    REQ_POOL() {
        REQ_POOL* p = this;
        s32 i;
        for (i = 0; i < 32; i++) p->free[i] = i;
        p->n = 32;
    }
};

static REQ_QUEUE s_queue;
static REQ_DONE s_done;
static REQ_POOL s_pool;

extern "C" {
extern s32 D_0032b91c;
void func_00102818(s32, s32, s32, void (*)(s32), s32);
void func_00102448(s32, s32);  // TaskYield
s32 func_002b6f78(void);
void func_002ba140(s32, s32, s32);
void func_002ba188(s32, s32, s32);
void func_002ba1a0(s32, s32, s32);
void func_002ba1b8(s32, s32, s32);

void func_002bad20(s32 task);

void func_002bac78(REQ* e, s32 a, s32 type, s32 b, s32 c, void (*cb)(s32), s32 arg) {
    e->type = type;
    e->a = a;
    e->b = b;
    e->c = c;
    e->cb = cb;
    e->arg = arg;
    if (!s_queue.tail) {
        s_queue.tail = (u32)e;
        s_queue.head = (u32)e;
        e->next = 0;
    } else {
        ((REQ*)s_queue.tail)->next = (u32)e;
        e->next = 0;
        s_queue.tail = (u32)e;
    }
}

void func_002bacc0(void) {
    s_queue.clear();
    s_done.clear();
    func_00102818(D_0032b91c, 0, 0x7a508, func_002bad20, 0x1800);
}

static void func_002bad18(void) {
}

#define R(x) ((REQ*)(x))

// The task: runs each queued request, waits until it is done, then unlinks the finished
// requests and gives them back to the pool.
void func_002bad20(s32 task) {
    for (;;) {
        s_done.tail = 0;
        s_done.head = 0;
        u32 r = 0;
        while ((r = !r ? s_queue.head : R(r)->next) != 0) {
            switch (R(r)->type) {
            case 0: func_002ba1b8(R(r)->a, R(r)->b, R(r)->c); break;
            case 1: func_002ba188(R(r)->a, R(r)->b, R(r)->c); break;
            case 2: func_002ba1a0(R(r)->a, R(r)->b, R(r)->c); break;
            case 3: func_002ba140(R(r)->a, R(r)->b, R(r)->c); break;
            }
            while (func_002b6f78()) func_00102448(task, 0);
            if (s_done.tail == 0) {
                s_done.tail = r;
                s_done.head = r;
                R(r)->doneNext = 0;
            } else {
                R(s_done.tail)->doneNext = r;
                R(r)->doneNext = 0;
                s_done.tail = r;
            }
            s32 arg = R(r)->arg;
            if (R(r)->cb) R(r)->cb(arg);
        }
        while ((r = !r ? s_done.head : R(r)->doneNext) != 0) {
            u32 prev;
            if (r == s_queue.head) {
                prev = 0;
                s_queue.head = R(r)->next;
            } else {
                prev = s_queue.head;
                while (R(prev)->next != r) prev = R(prev)->next;
                R(prev)->next = R(r)->next;
            }
            if (r == s_queue.tail) s_queue.tail = prev;
            R(r)->next = 0;
            s_pool.free[s_pool.n++] = R(r) - s_pool.e;
        }
        func_00102448(task, 0);
    }
}

s32 func_002baf38(void) {
    return s_queue.head != 0;
}

void func_002baf48(s32 a, s32 type, s32 b, s32 c, void (*cb)(s32), s32 arg) {
    func_002bac78(&s_pool.e[s_pool.free[--s_pool.n]], a, type, b, c, cb, arg);
}

}
