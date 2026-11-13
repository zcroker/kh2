#include "../common/types.h"

// 0x2ef8d0-0x2ef938: starts a task once and clears the handle when the task ends. Linked unit.

struct TASK;
TASK* TASK_MANAGER_create_task(void*, s32, s32, void (*)(TASK*)) asm("_ZN12TASK_MANAGER11create_taskEiiPFvP4TASKE");

struct TaskOwner2ef8d0 {
    s32 a;
    s32 b;
    void (*fn)(TASK*);
    TASK* task;
};

struct TASK {
    u32 pad0;
    TaskOwner2ef8d0* owner;
    u8 pad8[40];
    void (*on_end)(TASK*);
};

static void on_task_end(TASK* t);

extern "C" void func_002ef8d0(TaskOwner2ef8d0* o, void* mgr) {
    if (!o->task) {
        o->task = TASK_MANAGER_create_task(mgr, o->a, o->b, o->fn);
        o->task->owner = o;
        o->task->on_end = on_task_end;
    }
}

static void on_task_end(TASK* t) {
    t->owner->task = 0;
}
