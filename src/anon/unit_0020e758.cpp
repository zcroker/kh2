// Linked unit 0x0020e758-0x0020e8b0: packet node list inserts.
#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));
typedef unsigned int w3728_u128 __attribute__((mode(TI)));
#include "tiny_auto80_solver_structs.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// 0020e758 (was src/anon/tiny_auto80_solver.cpp)
namespace n0020e758 {
u32 sceGsSyncPath(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13sceGsSyncPathjjjjjjjj");
u32 func_002f3918(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_002f3918jjjjjjjj");
u32 func_003058a0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_003058a0jjjjjjjj");
extern u8 D_01dac450 asm("D_01dac450");
extern u8 D_00360000 asm("D_00360000");
/*TARGET 0020e758*/
u32 func_0020e758(void) asm("_Z13func_0020e758v");
u32 func_0020e758(void) {
    ((u32(*)(u32, u32))sceGsSyncPath)(0, 0);
    ((u32(*)(u32))func_003058a0)(0);
    ((u32(*)(u32, u32))sceGsSyncPath)(0, 0);
    ((u32(*)(u32, u32))func_002f3918)(*(u32*)((u8*)&D_00360000 - 28216), (u32)&D_01dac450);
    return ((u32(*)(u32, u32))sceGsSyncPath)(0, 0);
}
}  // namespace n0020e758

// 0020e7a8 (was src/anon/batch_w3685_g.c)
namespace n0020e7a8 {
/* 16-byte packet node: tag word, link, two spare words. */
typedef struct PktNode347 { u32 tag; struct PktNode347* next; u32 w8; u32 wc; } PktNode347;
/* One of 16 priority lists (circular, tail pointer at +8). */
typedef struct PktList347 { u32 a; u32 b; PktNode347* volatile tail; u32 c; } PktList347;
extern PktList347 D_01dac450[16] asm("D_01dac450");
/*TARGET 0020e7a8*/
/* Clears node n, writes its tag (count - 1, type 0x20000000) and links it after the tail of
   priority list pri (clamped to 0..15). sq $0 zero store: hand asm. The empty asm keeps the
   list address from being scheduled above the tag store (partial asm, see asm_review.tsv). */
void func_0020e7a8(PktNode347* n, s32 count, s32 pri) asm("func_0020e7a8");
/* Clears node n, writes its tag (count - 1, type 0x20000000) and links it after the tail of
   priority list pri (clamped to 0..15). sq $0 zero store: hand asm. The empty asm keeps the
   list address from being scheduled above the tag store (partial asm, see asm_review.tsv). */
void func_0020e7a8(PktNode347* n, s32 count, s32 pri) {
    PktList347* l;
    asm volatile("sq $0, 0(%0)" : : "r"(n) : "memory");
    n->tag = (count - 1) | 0x20000000;
    asm volatile("");
    if (pri <= 0) pri = 0;
    if (pri > 15) pri = 15;
    l = D_01dac450;
    l = &l[pri];
    {
        PktNode347* t = l->tail;
        PktNode347* nx = t->next;
        t->next = n;
        n->next = nx;
    }
    l->tail = n;
}
}  // namespace n0020e7a8

// 0020e800 (was src/anon/batch_w3685_g.c)
namespace n0020e800 {
/* 16-byte packet node: tag word, link, two spare words. */
typedef struct PktNode347 { u32 tag; struct PktNode347* next; u32 w8; u32 wc; } PktNode347;
/* One of 16 priority lists (circular, tail pointer at +8). */
typedef struct PktList347 { u32 a; u32 b; PktNode347* volatile tail; u32 c; } PktList347;
extern PktList347 D_01dad550[16] asm("D_01dad550");
/*TARGET 0020e800*/
/* Same as func_0020e7a8 for the second list set. */
void func_0020e800(PktNode347* n, s32 count, s32 pri) asm("func_0020e800");
/* Same as func_0020e7a8 for the second list set. */
void func_0020e800(PktNode347* n, s32 count, s32 pri) {
    PktList347* l;
    asm volatile("sq $0, 0(%0)" : : "r"(n) : "memory");
    n->tag = (count - 1) | 0x20000000;
    asm volatile("");
    if (pri <= 0) pri = 0;
    if (pri > 15) pri = 15;
    l = D_01dad550;
    l = &l[pri];
    {
        PktNode347* t = l->tail;
        PktNode347* nx = t->next;
        t->next = n;
        n->next = nx;
    }
    l->tail = n;
}
}  // namespace n0020e800

// 0020e858 (was src/anon/batch_w3687_g.c)
namespace n0020e858 {
/* 16-byte packet node: tag word, link, two spare words. */
typedef struct PktNode3687 { u32 tag; struct PktNode3687* next; u32 w8; u32 wc; } PktNode3687;
/* One of 256 priority lists (circular, tail pointer at +8). */
typedef struct PktList3687 { u32 a; u32 b; PktNode3687* volatile tail; u32 c; } PktList3687;
extern PktList3687 D_01dac550[256] asm("D_01dac550");
/*TARGET 0020e858*/
/* Clears node n, writes its tag (count - 1, type 0x20000000) and links it after the tail of
   priority list pri (clamped to 0..255). Twin of func_0020e7a8 (batch_w3685_g.c). sq $0 zero
   store: hand asm. The empty asm keeps the list address from being scheduled above the tag
   store (partial asm, see asm_review.tsv). */
void func_0020e858(PktNode3687* n, s32 count, s32 pri) asm("func_0020e858");
/* Clears node n, writes its tag (count - 1, type 0x20000000) and links it after the tail of
   priority list pri (clamped to 0..255). Twin of func_0020e7a8 (batch_w3685_g.c). sq $0 zero
   store: hand asm. The empty asm keeps the list address from being scheduled above the tag
   store (partial asm, see asm_review.tsv). */
void func_0020e858(PktNode3687* n, s32 count, s32 pri) {
    PktList3687* l;
    asm volatile("sq $0, 0(%0)" : : "r"(n) : "memory");
    n->tag = (count - 1) | 0x20000000;
    asm volatile("");
    if (pri <= 0) pri = 0;
    if (pri > 255) pri = 255;
    l = D_01dac550;
    l = &l[pri];
    {
        PktNode3687* t = l->tail;
        PktNode3687* nx = t->next;
        t->next = n;
        n->next = nx;
    }
    l->tail = n;
}
}  // namespace n0020e858

