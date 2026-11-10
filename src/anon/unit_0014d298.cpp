#include "../common/types.h"

// Two worker threads (0x14d298-0x14d680). Each runs a callback, then waits on its own semaphore;
// a shared semaphore lets the main thread wait for them.

struct SemaParam { s32 currentCount, maxCount, initCount, numWaitThreads; u32 attr, option; };
struct ThreadParam {
    s32 status;
    void (*func)(s32);
    void* stack;
    s32 stackSize;
    void* gpReg;
    s32 initPriority;
    s32 currentPriority;
    u32 attr, option;
    s32 waitType, waitId, wakeupCount;
};

extern "C" {
s32 CreateThread(ThreadParam*);
s32 ChangeThreadPriority(s32, s32);
s32 GetThreadId(void);
s32 CreateSema(SemaParam*);
s32 SignalSema(s32);
s32 iSignalSema(s32);
s32 WaitSema(s32);
s32 ReferSemaStatus(s32, SemaParam*);
s32 iReferSemaStatus(s32, SemaParam*);
s32 func_00306760(s32, s32);  // StartThread
extern u8 D_0037a800;          // _gp
}

struct SEMA {
    SemaParam p;
    s32 id;
    SEMA() {
        p.currentCount = 0;
        p.initCount = 0;
        p.maxCount = 1;
        p.option = 0;
        p.numWaitThreads = 0;
        p.attr = 0;
    }
    void create() { id = CreateSema(&p); }
    void wait() { WaitSema(id); }
    void signal() {
        SemaParam st;
        ReferSemaStatus(id, &st);
        if (st.numWaitThreads) SignalSema(id);
    }
    void isignal() {
        SemaParam st;
        iReferSemaStatus(id, &st);
        if (st.numWaitThreads) iSignalSema(id);
    }
};

struct THREAD {
    s32 tid;
    ThreadParam tp;
    THREAD() {
        tp.func = 0;
        tp.stack = 0;
        tp.stackSize = 0;
        tp.initPriority = 0;
        tp.gpReg = &D_0037a800;
        tp.status = 0;
        tp.currentPriority = 0;
        tp.attr = 0;
        tp.option = 0;
        tp.waitType = 0;
        tp.waitId = 0;
        tp.wakeupCount = 0;
    }
};

struct WORKER : THREAD {
    SEMA sema;
    void (*cb)(void*);
    void* arg;
    ~WORKER() {}
};

extern "C" {
SEMA D_00349e28;
WORKER D_00349e48[2];

static void func_0014d298(s32 i) {
    WORKER* w = &D_00349e48[i];
    for (;;) {
        if (w->cb) w->cb(w->arg);
        D_00349e48[i].sema.wait();
    }
}

void func_0014d2e8(s32 i) {
    D_00349e48[i].cb = 0;
    D_00349e48[i].arg = 0;
}

void func_0014d308(void) {
    struct NoTail { ~NoTail() {} } nt;
    ChangeThreadPriority(GetThreadId(), 30);
    D_00349e28.create();
    func_0014d2e8(0);
    func_0014d2e8(1);
}

void func_0014d358(void* stack, s32 size, void (*func)(void*), void* arg) {
    s32 i;
    s32 off;
    for (i = 0, off = 0; i < 2; i++, off += 88) {
        WORKER* e = &D_00349e48[i];
        if (e->cb == 0) {
            e->cb = func;
            e->arg = arg;
            e->sema.id = CreateSema((SemaParam*)((u8*)&D_00349e48[0].sema.p + off));
            e->tp.func = func_0014d298;
            e->tp.stack = stack;
            e->tp.stackSize = size;
            e->tp.initPriority = i + 40;
            e->tid = CreateThread(&e->tp);
            func_00306760(e->tid, i);
            return;
        }
    }
}

void func_0014d430(void) {
    s32 i;
    for (i = 0; i < 2; i++) D_00349e48[i].sema.wait();
}

void func_0014d478(void) {
    s32 i;
    D_00349e28.wait();
    for (i = 0; i < 2; i++) D_00349e48[i].sema.signal();
}

void func_0014d4e8(void) {
    D_00349e28.isignal();
}

}
