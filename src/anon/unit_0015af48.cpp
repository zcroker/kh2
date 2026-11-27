// func_0015af48: allocates the target-system objects through the heap allocator (a 0x24 list, a 0x1b8 object,
// then a 0x340 or 0x24 object depending on func_001492f8 / func_00149300).
typedef unsigned char u8; typedef unsigned int u32; typedef int s32; typedef short s16; typedef float f32;
namespace n0015af48 {
struct Heap { virtual void* Alloc(u32 size, void* ra); };
struct Sys { u8 pad[20]; Heap* heap; };
extern Sys* D_00347f80 asm("D_00347f80");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_0034ab18[] asm("D_0034ab18");
extern u8 D_0034aaf8[] asm("D_0034aaf8");
extern u8 D_0034aab8[] asm("D_0034aab8");
extern u8 D_0034aad8[] asm("D_0034aad8");
void func_0031a838(void*) asm("func_0031a838");
void func_00239700(void*) asm("func_00239700");
void func_002361a0(void*) asm("func_002361a0");
s32 func_001492f8(u32) asm("func_001492f8");
s32 func_00149300(u32) asm("func_00149300");
struct MenuObj {
    static void* operator new(u32 size) { return D_00347f80->heap->Alloc(size, 0); }
    static void* operator new(u32, void* p) { return p; }
    static void* operator new(u32 size, Sys** ps) { return (*ps)->heap->Alloc(size, 0); }
};
struct List : MenuObj { void* vt; u8 pad4[8]; s32 f12; u8 pad16[20]; List() { f12 = 0; vt = D_0034ab18; } };
struct Task : MenuObj { void* vt; u8 pad4[8]; u8 f12[12]; Task(u8* tv) { vt = tv; func_0031a838(f12); } };
struct SeqTask : Task { u8 seq[384]; SeqTask(u8* tv) : Task(tv) { vt = D_00347e60; func_00239700(seq); } };
struct Target : SeqTask { s32 f408; u8 pad[28]; Target(u8* tv) : SeqTask(tv) { f408 = 0; vt = D_0034aaf8; } };
struct Sub416 { u8 b[416]; Sub416() { func_002361a0(this); } };
struct TargetB : SeqTask { u8 pad408[8]; u8 sub[416]; TargetB(u8* tv) : SeqTask(tv) { vt = D_0034aad8; func_002361a0(sub); } };
struct TargetS : Task { u8 pad[12]; TargetS(u8* tv) : Task(tv) { vt = D_0034aab8; } };
extern u32 D_0034aaac asm("D_0034aaac");
extern s32 D_0034aa98 asm("D_0034aa98");
extern List* D_0034aaa0 asm("D_0034aaa0");
extern Target* D_0034aa9c asm("D_0034aa9c");
extern TargetB* D_0034aaa4 asm("D_0034aaa4");
extern TargetS* D_0034aaa8 asm("D_0034aaa8");
void wtarget_0015af48(u32 a0, u32, u32, u32) asm("func_0015af48");
void wtarget_0015af48(u32 a0, u32, u32, u32) {
    D_0034aaac = a0;
    D_0034aa98 = 0;
    D_0034aaa0 = new List;
    u8* tv = D_00347f98;
    u8* tv2;
    Target* t9 = new Target(tv2 = tv);
    D_0034aa9c = t9;
    s32 i; for (i = 0; i != 1; i++) {
        s32 a = func_001492f8(a0);
        s32 b = func_00149300(a0);
        if (!a || !b) D_0034aaa8 = new TargetS(tv2);
        else { TargetB* t = new TargetB(tv2); D_0034aaa4 = t; }
    }
}
}
