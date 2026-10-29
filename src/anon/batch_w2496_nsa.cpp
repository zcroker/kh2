#include "../common/types.h"
struct TASK;
extern "C" {
struct Res1a5f50 { u8 pad[8]; s32 val; };
struct Data1a5f50 { s32 id; char name[1]; };
struct Ent1a5f50 { s32 cache; s32 res[2]; u8 arg[0x1c]; Data1a5f50* data; };
struct Task1a5f50 { u8 pad[48]; void (*fin)(TASK*); };
extern Ent1a5f50 D_00350800[6];
struct Pair1a5f50 { u32 a; u32 b; };
extern Pair1a5f50 D_01c6cb20;
Task1a5f50* t1a5f50_CreateTask(s32, s32, void (*)(TASK*)) asm("_ZN5FIELD10CreateTaskEiiPFvP4TASKE");
void t1a5f50_Finalizer(TASK*) asm("_ZN2YS5MAGIC9FinalizerEP4TASK");
void func_001a5db8(TASK*);
Data1a5f50* func_001a6658(s32);
s32 t1a5f50_Alloc(const char*, s32) asm("_ZN2YS10CACHE_BUFF5AllocEPKci");
Res1a5f50* func_00168b38(s32, s32, s32);
void t1a5f50_001dddd0(void*, s32) asm("_Z16wtarget_001dddd0jjjj");
static inline bool Has1a5f50(Res1a5f50* r) { return r && r->val != 0; }

// YS::MAGIC init: create the magic task, then load each of the 6 magic entries' cache/resources.
// Each field is walked by its own stepping pointer (matches the original's 5 separate stride-44 registers).
void func_001a5f50(void)
{
    t1a5f50_CreateTask(1, 0x5014, func_001a5db8)->fin = t1a5f50_Finalizer;
    Pair1a5f50* z = &D_01c6cb20;
    z->b = 0;
    z->a = 0;
    Ent1a5f50* base = D_00350800;
    u8* pa = base->arg;
    Ent1a5f50* pc = base;
    Data1a5f50** pd = &base->data;
    Ent1a5f50* pr = base;
    Ent1a5f50* pe = base;
    for (s32 i = 0; i < 6; i++) {
        Data1a5f50* d = func_001a6658(i);
        if (d) {
            s32 c = t1a5f50_Alloc(d->name, -1);
            pc->cache = c;
            s32* e = pr->res;
            for (s32 k = 0; k < 2; k++) {
                Res1a5f50* r = func_00168b38(c, 3, k);
                e[k] = Has1a5f50(r) ? r->val : 0;
            }
            t1a5f50_001dddd0(pa, func_00168b38(c, 18, 0)->val);
        } else {
            pe->cache = 0;
        }
        *pd = d;
        pa += 44; pd = (Data1a5f50**)((u8*)pd + 44); pe++; pc++; pr++;
    }
}
}
