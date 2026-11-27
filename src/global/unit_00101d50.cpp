#include "../common/types.h"

// Game entry (0x101d50-0x102298): main() sets up the task manager on a 64 KB static heap, starts
// every subsystem and runs the task manager once per frame for ever. The rest is the process list:
// a PROC owns its own task manager; PROC::start (vtable slot 0) stops the processes that share one
// of its mask bits and starts a coroutine task (func_00101ea8) that waits until no other process
// with those bits is listed, links the PROC in, calls init, runs its tasks until the state is 3,
// calls end, drains and frees its task manager, then unlinks it.

struct TASK_MANAGER;
struct TASK;
struct PROC;

extern "C" {
void func_002b9bd0(void);
void func_00105a10(void);
TASK_MANAGER* func_00102508(void*, u32);
void func_0016f970(void);
void func_002f3610(u32);
void func_002f49c0(void);
void func_00106490(u32);
void func_001674c8(void);
void func_001385f8(void);
void func_0016fa58(void);
void func_00105b58(void);
void func_00102e40(void);
void func_00168f18(void);
void func_00138620(void);
void func_001dcd50(void);
void func_00226978(void);
void func_00233580(void);
void func_0011b3e0(void);
void func_00102e18(void);
void func_00102bd8(void);
void func_00103480(void);
void func_00105d50(void);
void func_0023d260(void);
void func_00104080(void);
void func_00104560(void);
void func_002cb530(void);
void func_00105748(void*);
void func_001029e8(TASK_MANAGER*);
void func_00102448(TASK*, u32);
void func_00102730(TASK_MANAGER*);
void func_00102750(TASK_MANAGER*);
s32 func_00102a08(TASK_MANAGER*);
TASK* TASK_MANAGER__create_thread(TASK_MANAGER*, u32, u32, void (*)(TASK*), u32);
void func_00167ea8(void);
void func_0014a4b0(void);
void func_00167ee0(void);
void func_0014a4c0(void);

void func_00101d50(void);
void func_00101d68(void);
void func_00101ea8(TASK*);
void func_001021d0(void);
void GAME_MODE__enable(void);
}

struct TASK {
    u32 _0;
    PROC* owner;    // 04
};

struct PROC {
    virtual void start();               // 0x102080
    virtual void init(TASK* t);         // 0x102130
    virtual void end(TASK* t);          // 0x102158
    TASK_MANAGER* tasks;                // 04
    u32 _08;
    PROC* next;                         // 0c
    u32 _10;
    u32 mask;                           // 14
    u32 prio;                           // 18
    s32 state;                          // 1c: 1 running, 3 stopping
    void (*init_fn)(TASK*);             // 20
    void (*end_fn)(TASK*);              // 24
    u32 stack;                          // 28
};

struct PROC_LIST {
    PROC* head;
    PROC* tail;
    PROC_LIST() { head = tail = 0; }
    PROC* next(PROC* p) {
        if (!p) return head;
        return p->next;
    }
    void push_front(PROC* p) {
        if (!head) {
            tail = p;
            head = p;
            p->next = 0;
        } else {
            p->next = head;
            head = p;
        }
    }
    // Inlined into func_00101ea8 like the original.
    __attribute__((always_inline)) void remove(PROC* p) {
        PROC* prev;
        if (p == head) {
            head = p->next;
            prev = 0;
        } else {
            prev = head;
            while (prev->next != p) prev = prev->next;
            prev->next = p->next;
        }
        if (p == tail) tail = prev;
        p->next = 0;
    }
};

TASK_MANAGER* D_0032b91c;
u32 D_0032b920;
static u8 s_heap[0x10000];
static PROC_LIST s_procs;

extern u8 D_0032bb30[];
extern PROC D_0032b9a0;

void func_00101d50(void) {
    func_002b9bd0();
}

void func_00101d68(void) {
    func_00105a10();
    D_0032b91c = func_00102508(s_heap, sizeof(s_heap));
    func_0016f970();
    func_002f3610(1);
    func_002f49c0();
    func_00106490(0x00875b2f);
    func_001674c8();
    func_001385f8();
    func_0016fa58();
    func_00105b58();
    func_00102e40();
    func_00168f18();
    func_00101d50();
    func_00138620();
    func_001dcd50();
    func_00226978();
    func_00233580();
    func_0011b3e0();
    func_00102e18();
    func_00102bd8();
    func_00103480();
    func_00105d50();
    func_0023d260();
    func_00104080();
    func_00104560();
    func_002cb530();
    func_00105748(D_0032bb30);
    D_0032b9a0.start();
    for (;;) {
        func_001029e8(D_0032b91c);
        D_0032b920 = (D_0032b920 + 1) % 1000;
    }
}

void func_00101ea8(TASK* t) {
    PROC* self = t->owner;
    for (;;) {
        PROC* p = 0;
        while ((p = s_procs.next(p)) != 0) {
            if (p->mask & self->mask) break;
        }
        if (!p) break;
        func_00102448(t, 0);
    }
    self->state = 1;
    s_procs.push_front(self);
    self->init(t);
    while (self->state != 3) {
        if (self->state == 1) func_001029e8(self->tasks);
        func_00102448(t, 0);
    }
    func_00102730(self->tasks);
    self->end(t);
    while (func_00102a08(self->tasks) > 0) {
        func_001029e8(self->tasks);
        func_00102448(t, 0);
    }
    func_00102750(self->tasks);
    self->tasks = 0;
    self->state = 0;
    s_procs.remove(self);
}

void PROC::start() {
    if (state != 3) {
        PROC* p = 0;
        while ((p = s_procs.next(p)) != 0) {
            if (p->mask & mask) {
                p->state = 3;
                func_001021d0();
            }
        }
        TASK_MANAGER__create_thread(D_0032b91c, mask, prio, func_00101ea8, stack)->owner = this;
    }
}

void PROC::init(TASK* t) {
    if (init_fn) init_fn(t);
}

void PROC::end(TASK* t) {
    if (end_fn) end_fn(t);
}

// Collects every running process; returns the count.
extern "C" s32 func_00102180(PROC** out) {
    PROC* p = 0;
    s32 count = 0;
    while ((p = s_procs.next(p)) != 0) {
        if (p->state == 1) {
            *out++ = p;
            count++;
        }
    }
    return count;
}

void func_001021d0(void) {
    func_00167ea8();
    func_0014a4b0();
}

void GAME_MODE__enable(void) {
    func_00167ee0();
    func_0014a4c0();
}

// First running process, or 0.
extern "C" PROC* func_00102210(void) {
    PROC* p = 0;
    while ((p = s_procs.next(p)) != 0) {
        if (p->state == 1) return p;
    }
    return 0;
}
