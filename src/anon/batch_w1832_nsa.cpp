#include "../common/types.h"
struct Entry1832 { s32 id; s32 time; u8 pad[0x200]; };
struct Cache1832 { Entry1832 e[4]; Entry1832* cur; s32 counter; };
struct FlareItem1832 { u8 d[0x40]; };
struct FlarePool1832 { FlareItem1832 item[30]; s32 free[30]; s32 count; };
struct Heap1832 { void** vt; };
typedef void* (*AllocFn1832)(Heap1832*, s32, s32);
extern "C" {
extern u8 D_0032bae1;
void func_00195430(Entry1832*);
void func_001955a8(Cache1832* c, s32 range) {
    Entry1832* e = c->e;
    Entry1832* found = 0;
    Entry1832* lru = c->e;
    u8 id = D_0032bae1;
    s32 i;
    c->cur = 0;
    for (i = 3; i >= 0; i--, e++) {
        if (e->id == id && e->time >= c->counter - range && (found == 0 || found->time < e->time)) {
            c->cur = e;
            found = e;
        }
        if (e->id < 0 || (lru->id >= 0 && e->time < lru->time)) lru = e;
    }
    if (found == 0) {
        c->cur = lru;
        func_00195430(lru);
        c->cur->id = id;
        found = c->cur;
    } else {
        for (i = 0; i < 4; i++) {
            if (c->e[i].time < found->time) { c->e[i].time++; found = c->cur; }
        }
    }
    found->time = c->counter++;
}

u8* CreateTask1832(s32, s32, void (*)(void*)) asm("_ZN5FIELD10CreateTaskEiiPFvP4TASKE");
Heap1832* GetAllocator1832(void) asm("_ZN4AREA12GetAllocatorEv");
void func_002e92e8(void*);
void func_002e9338(void*);
void func_002e93a0(FlareItem1832*);
extern u8* D_003633c8;
extern FlarePool1832* D_01e2bfa0;
extern s32 D_01e2bfa4;
// Ts::FLARE::Init()
void FlareInit1832(void) asm("_ZN2Ts5FLARE4InitEv");
void FlareInit1832(void) {
    if (D_003633c8 == 0) {
        u8* t = CreateTask1832(1, 0x501e, func_002e92e8);
        D_003633c8 = t;
        *(void (**)(void*))(t + 0x30) = func_002e9338;
        FlarePool1832** pp = &D_01e2bfa0;
        Heap1832* h = GetAllocator1832();
        FlarePool1832* p = (FlarePool1832*)((AllocFn1832)h->vt[0])(h, 0x800, 0);
        FlareItem1832* it = p->item;
        s32 n = 29;
        do {
            func_002e93a0(it);
            n--;
            it++;
        } while (n != -1);
        s32 i;
        for (i = 0; i < 30; i++) p->free[i] = i;
        p->count = 30;
        *pp = p;
    }
    FlarePool1832* q = D_01e2bfa0;
    D_01e2bfa4 = 0;
    s32 j;
    for (j = 0; j < 30; j++) q->free[j] = j;
    q->count = 30;
}
}
