#include "../common/types.h"
struct Alloc278 { virtual void* Alloc(int, int); virtual void Free(void*); };
struct Heap278 { u8 pad[20]; Alloc278* a; };
extern "C" Heap278* D_00347f80;
struct MCObj278 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual ~MCObj278();
    static void operator delete[](void* p) { D_00347f80->a->Free(p); }
    u8 pad[404];
};
union F278 { s32 i; void* p; MCObj278* o; u8 c; };
struct MCSave278 { F278 a0, a4, a8, ac, a10, a14, a18; };
extern "C" {
extern s32 D_0035f3f8;
extern MCObj278* D_0035f3fc;
extern void* D_0035f400;
extern s32 D_0035f404;
extern void* D_0035f408;
extern void* D_0035f40c;
extern s32 D_0035f410;
extern MCSave278* D_0035f414;
void func_0028cdb8(s32);  // record408_alloc_init
void DelArr278(void*) asm("_ZdaPv");
void LoadDataFree278(...) asm("_ZN2Tz12LoadDataFreeEz");
void Exit278() asm("_ZN2Tz10MenuCursor4ExitEv");
// 0028ca78: moved to src/anon/unit_0028c878.cpp
}
struct CurItem278 { u8 pad[388]; s32 num; u8 pad2[16]; };
struct CurOwn278 { u8 pad[19584]; CurItem278 item[4]; };
struct CurTbl278 { s16 a, b, c; };
struct CurSt278 { u32 pad:27; u32 bit:1; u32 pad2:4; };
extern "C" {
extern CurOwn278* D_0035f634;
extern CurTbl278 D_00374cd8[];
CurSt278* func_002b23e0(s32);  // list_entry_by_index_checked
void Call4_278(CurItem278*) asm("_Z16u_call4_00139d78jjjj");
s32 IsHide278(CurItem278*) asm("_ZN2dk5Obj2D6isHideEv");
void Show278(CurItem278*) asm("_ZN2dk5Obj2D4showEv");
void SetNum278(CurItem278*, s32) asm("_ZN2dk6Sprite6setNumEi");
void Attach278(CurItem278*, CurItem278*) asm("_ZN2Tz10MenuCursor12AttachSpriteEz");
void func_002b2da8(s32 idx);  // 0x002b2da8: definition moved into src/anon/unit_002b2a18.cpp
}
struct Big278 { Big278* next; s32 k, maxwds, sign, wds; u32 x[1]; };
extern "C" {
s32 __mcmp(Big278*, Big278*);  // cmp_entries_16_then_words
Big278* _Balloc(void*, s32);
Big278* __mdiff(void* ptr, Big278* a, Big278* b);  // 0x003044d0: definition moved into src/newlib/libc/mprec.c
}
struct Vq278 {
    f32 x, y, z, w;
    Vq278& operator=(const Vq278& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Res278 { Vq278 v; u64 id:16; u64 flag:1; u64 rest:47; };
struct Src278 { u8 pad[4]; s32 type; u8 pad2[4]; u16 id; u8 pad3[2]; f32 t; u8 pad4[12]; Vq278 v; };
extern "C" {
extern s8 D_01c940c0;
extern Res278 D_01c940d0;
void func_001b13d0();
void func_002fd188(void (*)());  // pool_alloc_block
s32 func_001b0498(Src278*);  // obj_check_ready_flags
f32 cosf(f32);
// 001b0580: moved to src/yasui/libys/lookat.cpp
}
struct ITbl278 { s16 max; u8 pad[18]; };
extern "C" {
extern s32 D_0035f01c;
extern s8* D_0035f234;
extern ITbl278 D_00373f10[];
s32 func_0028b040(s32);
void func_0023d1d0();  // set_global_word1
void func_0023d1e0();  // zero_global_d
void func_002b6bc4(s32);
void func_0027d868(u8 dir);  // 0x0027d868: definition moved into src/anon/unit_0027d2e8.cpp
}
/* VU0 random float in [0,1): vrnext chain seeded by vf2 = -1 (hand-written asm macro) */
#define VRAND278(out) asm volatile( \
    "addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\t" \
    "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t" \
    "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t" \
    "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t" \
    "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t" \
    "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t" \
    "vitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1" \
    : "=r"(out) : : "$8")
union JF278 { f32 f; s32 i; u8 c; };
struct JEnt278 { s32 id; s32 off; void* a; void* b; void* c; u8 flag; };
struct JOwn278 { u8 pad[12]; s32 id; };
struct JSt278 { u8 pad[168]; u64 bits; };
struct JRef278 { u8 pad[12]; s32* off; };
extern "C" {
extern s32 D_01d9ea9c;
extern JSt278* D_01d9e6e0;
extern s32 D_01d9e360[];
s32 func_001ed638(f32, void*);  // int_float_mul_sub
void func_001ed658(u8* o, JEnt278* e, JRef278* r);  // 0x001ed658: definition moved into src/anon/unit_001ec098.cpp
}
