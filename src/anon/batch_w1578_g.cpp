#include "../common/types.h"

// Built with -g (see BRIEF_G): register saves stay ahead of jal with a nop delay slot.

struct W1578Elem {
    u8 pad[0x1c];
    s32 x1c;
    u8 pad2[0x10];
    W1578Elem() { x1c = 0; }
    ~W1578Elem() {}
} __attribute__((aligned(16)));

extern "C" {
void* W1578_AREA_Alloc(u32) asm("_ZN4AREA5AllocEj");
void W1578_AREA_Free(void*) asm("_ZN4AREA4FreeEPv");
}

struct W1578Cont {
    s32 n;
    W1578Elem e[256];
    W1578Cont() : n(0) {}
    ~W1578Cont() {}
    static void* operator new(unsigned int s) { return W1578_AREA_Alloc(s); }
    static void operator delete(void* p) { W1578_AREA_Free(p); }
};

struct W1578Obj {
    virtual ~W1578Obj();
    virtual void v2();
    virtual void v3();
    virtual void v4(W1578Cont*);
    u32 flags;
    u8 pad[0xc0 - 8];
    W1578Obj* next;
};

extern "C" {
struct W1578Mode { s32 pad; s32 id; };
struct W1578Task { u8 pad[0x30]; s32 fn; };
typedef void (*W1578TaskFn)(W1578Task*);

s32 func_00134258(void);
void func_00133f20(void);
s32 func_001adf00(void);
void FlushCache(s32);
void func_001c70e8(void);
void* W1578_JmInfo_GetCharaData(u32) asm("_ZN2Tz6JmInfo12GetCharaDataEj");
void func_001a4df0(void*, void*, s32, s32);
void* W1578_YS_TABLE_Get(void) asm("_ZN2YS6MEMBER5TABLE3GetEv");
void* W1578_YS_CACHE_BUFF_Clear(s32) asm("_ZN2YS10CACHE_BUFF5ClearEi");
void W1578_wtarget_0016ed50(void*, u32, u32) asm("_Z16wtarget_0016ed50jjjj");
W1578Mode* W1578_getFieldMode(void) asm("_Z12getFieldModev");
W1578Mode* W1578_getGumiBattleMode(void) asm("_Z17getGumiBattleModev");
void func_00102180(W1578Mode**);
void func_001e02f8(s32);
void func_001de8a8(s32, s32, s32, s32);
void W1578_YS_SUMMON_LeaveTink(void) asm("_ZN2YS6SUMMON9LeaveTinkEv");
s32 func_0016c028(u32);
f32 W1578_ObjCamera_getObjBackDirection(u32) asm("_ZN2dk9ObjCamera19getObjBackDirectionEv");
void func_001c7fb8(f32, u8*, void*, s32);
void W1578_YS_ACT_push(u8*, char*) asm("_ZN2YS3ACT4pushEPc");
void func_001373d8(void);
void func_001c2ba8(void);
void func_001c0560(void);
void func_001a4388(void);
void func_0018ed18(W1578Cont*);
void func_00161228(void);
W1578Task* W1578_FIELD_CreateTask(s32, s32, W1578TaskFn) asm("_ZN5FIELD10CreateTaskEiiPFvP4TASKE");
W1578Task* W1578_TM_create_task(s32, s32, s32, W1578TaskFn) asm("_ZN12TASK_MANAGER11create_taskEiiPFvP4TASKE");
s32 func_001024b0(s32);
void func_00160b10(W1578Task*);
void func_00160b88(W1578Task*);
void func_00160bb8(W1578Task*);
void func_00160bd8(W1578Task*);
void func_00160cf0(W1578Task*);
extern u32 D_0034e948;
extern u32 D_0034f240;
extern char D_0036d8b8[];
extern W1578Obj* D_01c60cd8;
extern s32 D_0034c738;
extern s32 D_0034c73c;
extern s32 D_004f3b30;

s32 func_00134278(void) {
    s32 r = func_00134258();
    func_00133f20();
    return r;
}

s32 func_001682b8(void) {
    s32 r = func_001adf00();
    FlushCache(0);
    return r;
}

void func_001a5928(void) {
    func_001c70e8();
    void* p = W1578_AREA_Alloc(0xa00);
    func_001a4df0(p, W1578_JmInfo_GetCharaData(0x5c3), 0x100, 0x60);
}

void func_001d0068(void) {
    void* t = W1578_YS_TABLE_Get();
    W1578_YS_CACHE_BUFF_Clear(5000);
    W1578_wtarget_0016ed50(t, 5000, 7);
}

void func_001de808(void) {
    W1578Mode* f = W1578_getFieldMode();
    W1578Mode* g = W1578_getGumiBattleMode();
    W1578Mode* cur;
    func_00102180(&cur);
    W1578Mode* c = cur;
    if (c == f) {
        func_001e02f8(1);
        func_001de8a8(c->id, 9, 20300, 0x16760);
    } else if (c == g) {
        func_001e02f8(2);
        func_001de8a8(g->id, 1, 31000, 0x11940);
    }
}

void func_001af938(void) {
    W1578_YS_SUMMON_LeaveTink();
    u32 obj = D_0034e948;
    u8* p = (u8*)W1578_AREA_Alloc(0xd00);
    void* cd = W1578_JmInfo_GetCharaData(0x4f4);
    s32 r = func_0016c028(obj);
    func_001c7fb8(W1578_ObjCamera_getObjBackDirection(obj), p, cd, r);
    W1578_YS_ACT_push(p + 0x300, D_0036d8b8);
    D_0034f240 &= ~2;
    func_001373d8();
}

void func_0018d620(void) {
    func_001c2ba8();
    func_001c0560();
    func_001a4388();
    W1578Cont* c = new W1578Cont;
    W1578Obj* o = D_01c60cd8;
    while (o) {
        W1578Obj* nx = o->next;
        if (o->flags & 0x800) {
            delete o;
        } else {
            o->v4(c);
        }
        o = nx;
    }
    func_0018ed18(c);
    delete c;
}

void func_001612b8(s32 a0, s32 a1) {
    D_0034c73c = a1;
    D_0034c738 = a0;
    func_00161228();
    W1578Mode* f = W1578_getFieldMode();
    W1578Mode* g = W1578_getGumiBattleMode();
    W1578Mode* cur;
    func_00102180(&cur);
    W1578Mode* c = cur;
    if (c == f) {
        *(s32*)((u8*)W1578_FIELD_CreateTask(1, 28000, func_00160b88) + 0x30) = (s32)func_00160bb8;
        *(s32*)((u8*)W1578_FIELD_CreateTask(1, 0x16378, func_00160bd8) + 0x30) = (s32)func_00160cf0;
        s32 t = func_001024b0(D_0034c738);
        D_004f3b30 = t;
        W1578_TM_create_task(t, 0, 28000, func_00160b10);
    } else if (c == g) {
        *(s32*)((u8*)W1578_TM_create_task(g->id, 0, 0xabe0, func_00160b88) + 0x30) = (s32)func_00160bb8;
        *(s32*)((u8*)W1578_TM_create_task(g->id, 0, 0x11558, func_00160bd8) + 0x30) = (s32)func_00160cf0;
        s32 t = func_001024b0(D_0034c738);
        D_004f3b30 = t;
        W1578_TM_create_task(t, 0, 0xabe0, func_00160b10);
    }
}
}
