#include "../common/types.h"

// ---- 0019ad00: does the table hold a type-2 entry with this id?
struct W2365_Ent { u8 type; u8 pad1[0x13]; u8 id; u8 pad2[0x2b]; };          // 64 bytes
struct W2365_Tbl { u8 pad0[4]; u16 count; u8 pad1[0x42]; W2365_Ent e[1]; };    // entries at +0x48
struct W2365_Own { u8 pad0[8]; W2365_Tbl* tbl; };

// ---- 001ce248: look up a resource by its 4-character tag
struct W2365_Res { u32 f0; u32 f4; u32 data; };
extern u32 D_00352134;

// ---- 001cebb0: create the object and its task
struct TASK;
typedef void (*W2365_TaskFn)(TASK*);
struct W2365_Task { u8 pad[0x30]; W2365_TaskFn next; };
void* W2365_AreaAlloc(u32) asm("_ZN4AREA5AllocEj");
W2365_Task* W2365_CreateTask(s32, s32, W2365_TaskFn) asm("_ZN5FIELD10CreateTaskEiiPFvP4TASKE");
struct W2365_Obj;

extern "C" {
W2365_Res* func_00168b88(u32, s32, s32, s32);  // find_entry16_by_half_word
void func_001ce8b8(W2365_Obj*);
void func_001cec08(TASK*);
void func_001cec28(TASK*);
}

struct W2365_Obj {
    u8 data[60];
    static void* operator new(unsigned int n) { return W2365_AreaAlloc(n); }
    W2365_Obj() { func_001ce8b8(this); }
};
extern W2365_Obj* D_003521d0;

// Arguments of an inline wrapper are evaluated left to right (the global first).
static inline __attribute__((always_inline)) W2365_Res* W2365_Find(u32 h, s32 kind, s32 tag)
{
    return func_00168b88(h, kind, tag, 0);
}

extern "C" {

s32 func_0019ad00(W2365_Own* o, s32 id)
{
    for (s32 i = 0; i < o->tbl->count; i++) {
        if (o->tbl->e[i].type == 2 && o->tbl->e[i].id == id) return 1;
    }
    return 0;
}

u32 func_001ce248(s32 kind, const s8* p)
{
    return W2365_Find(D_00352134, kind, p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24))->data;
}

void func_001cebb0(void)
{
    D_003521d0 = new W2365_Obj;
    W2365_CreateTask(1, 14001, func_001cec08)->next = func_001cec28;
}

}
