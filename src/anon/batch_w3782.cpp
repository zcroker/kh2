#include "../common/types.h"

extern "C" {
struct Req2bad20 {
    void (*cb)(s32);
    s32 arg;
    u32 next;     /* pending list link */
    u32 doneNext; /* done list link */
    s32 a;
    s32 type;
    s32 b;
    s32 c;
};
struct List2bad20 { u32 head; u32 tail; };
struct Pool2bad20 { Req2bad20 ent[32]; s32 free[32]; s32 n; };
extern List2bad20 D_01e2a5e8; /* pending requests */
extern List2bad20 D_01e2a5f0; /* requests finished this pass */
extern Pool2bad20 D_01e2a5f8; /* request pool and free-index stack */
void func_00102448(s32, s32);
s32 func_002b6f78(void);
void func_002ba140(s32, s32, s32);
void func_002ba188(s32, s32, s32);
void func_002ba1a0(s32, s32, s32);
void func_002ba1b8(s32, s32, s32);

#define R(x) ((Req2bad20*)(x))

/* Loader task: runs each pending request, waits until it is done, then
   unlinks the finished requests and returns them to the pool. The list
   links are held as integers: pointer-typed links change branch layout. */
// 002bad20: moved to src/anon/unit_002bac78.cpp

#undef R

/* Static init/teardown for this unit: builds six layout entries and the
   image object at D_01c6cd20 (init == 1), destroys the image (init == 0).
   The two empty asm statements keep the code shape: the first hides the
   stack constant 2 from cse (it is reloaded with li for both calls), the
   second keeps the table base live so the last call gets base + 160. */
void func_001aae28(void*, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void image_ctor_001ab890(void*) asm("_ZN2YI5IMAGEC1Ev");
void func_002361d0(void*);
extern u8 D_01c6cc60[];
extern u8 D_01c6cd20[];
void wtarget_001ab890(u32 init, u32 prio, u32 a2, u32 a3) asm("_Z16wtarget_001ab890jjjj");
void wtarget_001ab890(u32 init, u32 prio, u32 a2, u32 a3)
{
    if (prio == 0xffff && init == 1) {
        func_001aae28(D_01c6cc60, 0, 0, 9, 8, 18, 18, 18, 18, 6, 6);
        func_001aae28(D_01c6cc60 + 32, 1, 0, 9, 8, 18, 18, 18, 18, 6, 12);
        func_001aae28(D_01c6cc60 + 64, 2, 0, 9, 8, 18, 18, 18, 18, 6, 30);
        s32 k = 2;
        asm("" : "+r"(k));
        func_001aae28(D_01c6cc60 + 96, 3, 2048, 9, 9, 24, 24, 24, 24, k, 6);
        func_001aae28(D_01c6cc60 + 128, 4, 2048, 9, 9, 24, 24, 24, 24, 2, 10);
        func_001aae28(D_01c6cc60 + 160, 5, 0, 9, 8, 18, 18, 18, 18, 6, 6);
        asm("" :: "r"(D_01c6cc60));
    }
    if (prio == 0xffff && init == 1) {
        image_ctor_001ab890(D_01c6cd20);
    }
    if (prio == 0xffff && init == 0) {
        func_002361d0(D_01c6cd20);
    }
}
}
