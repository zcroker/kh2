// Linked unit 0x002a3648-0x002a3ba8 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include <stdarg.h>
#include "../tozawa/jm_diagram.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/layfile.hpp"
#include "../tozawa/file_address_layout.hpp"
#include "../tozawa/jm_treasure.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"

// 002a3648 (was src/anon/batch_w3811_mam.cpp)
namespace n002a3648 {
struct It2a3 { u8 a; u8 on; u8 p[6]; };
struct Grp2a3 { u8 n; u8 cnt; u8 p[2]; It2a3* items; };
struct Big2a3 { u8 p0[0x1000]; Grp2a3 g[16]; u8 p1080[4]; s32 sel; };
extern Big2a3* D_0035f5e4 asm("D_0035f5e4");
extern u8* D_0035f5e8 asm("D_0035f5e8");
void func_00138c10(u8*, s32) asm("func_00138c10");
s32 func_002a4430(void) asm("func_002a4430");
s32 func_002a43f0(void) asm("func_002a43f0");
/*TARGET 002a3648*/
// Redraws a 9-row list of 8 cells: clears every cell, finds the group holding the selected item,
// then draws the items from that group onwards, highlighted ones with a second style.
void func_002a3648(void) asm("func_002a3648");
// Redraws a 9-row list of 8 cells: clears every cell, finds the group holding the selected item,
// then draws the items from that group onwards, highlighted ones with a second style.
void func_002a3648(void)
{
    s32 i, j;
    s32 on, off;
    s32 pos, k, g;
    It2a3* items;
    u8* d;
    for (i = 0; i < 9; i++)
        for (j = 0; j < 8; j++) {
            d = (u8*)(i * 0xcc0 + j * 0x198 + (u32)D_0035f5e8);
            func_00138c10(d, 2);
        }
    if (func_002a4430()) {
        off = 68;
        on = 67;
    } else if (func_002a43f0()) {
        off = 74;
        on = 73;
    } else {
        off = 62;
        on = 61;
    }
    pos = 0;
    k = 0;
    for (i = 0; i < 15; i++) {
        if (D_0035f5e4->g[i].cnt) {
            pos = 0;
            for (j = 0; j < D_0035f5e4->g[i].cnt; j++, k++) {
                if (D_0035f5e4->sel == k) break;
                if (j == D_0035f5e4->g[i].cnt - 1) pos += D_0035f5e4->g[i].n & 7;
                else pos += 8;
            }
            if (j < D_0035f5e4->g[i].cnt) break;
        }
    }
    g = i;
    items = D_0035f5e4->g[g].items;
    for (i = 0; i < 9 && g < 15; i++) {
        s32 n = D_0035f5e4->g[g].n;
        s32 cnt = 8;
        if (n < pos + 8) cnt = n - pos;
        for (j = 0; j < cnt; j++, pos++) {
            d = (u8*)(i * 0xcc0 + j * 0x198 + (u32)D_0035f5e8);
            func_00138c10(d, items[pos].on ? off : on);
        }
        if (pos >= D_0035f5e4->g[g].n) {
            for (j = g + 1; j < 15; j++)
                if (D_0035f5e4->g[j].cnt) break;
            g = j;
            pos = 0;
            items = D_0035f5e4->g[g].items;
        }
    }
}
}  // namespace n002a3648

// 002a3908 (gap: empty function)
namespace g002a3908 {
void func_002a3908(void) asm("func_002a3908");
void func_002a3908(void) {}
}  // namespace g002a3908

// 002a3910 (was src/anon/tiny_auto80_queue.cpp)
namespace n002a3910 {
u32 func_002a43f0(...) asm("func_002a43f0");
u32 func_00276c50(...) asm("func_00276c50");
u32 func_002a4430() asm("func_002a4430");
/*TARGET 002a3910*/
u32 func_002a3910() asm("_Z13func_002a3910v");
u32 func_002a3910() {
    u32 a0;
    u32 v0;

    if (func_002a4430() != 0) {
        a0 = 20346;
        goto call;
    }

    v0 = func_002a43f0();
    a0 = 18676;
    if (v0 == 0) {
        a0 = 18677;
    }

call:
    return func_00276c50(a0, 0);
}
}  // namespace n002a3910

// 002a3950 (was src/anon/batch_w270.cpp)
namespace n002a3950 {
struct W270Le { u8 b0; u8 b1; u8 pad[4]; u16 h6; };
struct W270Ls { u8 flag; u8 pad[3]; W270Le* list; };
struct W270Lt { u8 pad[4096]; W270Ls ent[1]; };
struct W270It { u8 pad[8]; u16 h8; };
extern W270Lt* D_0035f5e4 asm("D_0035f5e4");
extern u8* D_0035f5e8 asm("D_0035f5e8");
s32 func_002a4990(s32) asm("func_002a4990");
s32 func_002a4ad8(s32) asm("func_002a4ad8");
s32 func_002a4430(void) asm("func_002a4430");
s32 func_002a43f0(void) asm("func_002a43f0");
W270It* func_001a80c8(u32) asm("func_001a80c8");
// table24_find_by_id
void func_0028de08(u32, u8*, s32) asm("func_0028de08");
void* W270_tail4(u32) asm("_Z16u_tail4_00192048jjjj");
void W270_dup(void*, u8*) asm("_ZNK2YS7MESSAGE3dupEPc");
void W270_ctarget2(u8*, u32, s32) asm("_Z16ctarget_001a3788jjjj");
void W270_wtarget(u8*, u32, u32) asm("_Z16wtarget_002fde18jjjj");
/*TARGET 002a3950*/
void func_002a3950(void) asm("func_002a3950");
void func_002a3950(void) {
    s32 a = func_002a4990(-1);
    if (!D_0035f5e4->ent[a].flag) {
        W270_wtarget(D_0035f5e8 + 0x982c, 0, 32);
        return;
    }
    s32 b = func_002a4ad8(-1);
    W270Le* e = (W270Le*)((u32)(b * 8) + (u32)D_0035f5e4->ent[a].list);
    u32 id = e->h6;
    if (e->b1) {
        if (func_002a4430()) {
            W270_dup(W270_tail4(id), D_0035f5e8 + 0x982c);
        } else if (func_002a43f0()) {
            W270_ctarget2(D_0035f5e8 + 0x982c, id, -1);
        } else {
            W270_dup(W270_tail4(func_001a80c8(id)->h8), D_0035f5e8 + 0x982c);  // table24_find_by_id
        }
    } else {
        if (func_002a4430()) func_0028de08(id, D_0035f5e8 + 0x982c, 64);
        else func_0028de08(func_001a80c8(id)->h8, D_0035f5e8 + 0x982c, 64);
    }
}
}  // namespace n002a3950

// 002a3aa8 (was src/anon/batch_w78.cpp)
namespace n002a3aa8 {
struct W78Vec {
    f32 x, y, z, w;
    W78Vec& operator=(const W78Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline void vsub(W78Vec* d, const W78Vec* a, const W78Vec* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline W78Vec operator-(const W78Vec& a, const W78Vec& b) { W78Vec r; vsub(&r, &a, &b); return r; }
s32 func_002a4990(s32) asm("func_002a4990");
s32 func_002a4430(void) asm("func_002a4430");
s32 func_002a43f0(void) asm("func_002a43f0");
void func_002ac8e0(s32) asm("func_002ac8e0");
void func_002ab728(s32) asm("func_002ab728");
void func_002abac8(s32) asm("func_002abac8");
void func_002a3318(void) asm("func_002a3318");
extern u8* D_0035f5e4 asm("D_0035f5e4");
struct W78Slot8 { u8 a, b, on, done; u8 pad[4]; };
/*TARGET 002a3aa8*/
void func_002a3aa8(void) asm("func_002a3aa8");
void func_002a3aa8(void) {
    s32 id = func_002a4990(-1);
    if (func_002a4430()) {
        W78Slot8* e = (W78Slot8*)(id * 8 + (u32)D_0035f5e4 + 4096);
        if (e->on && !e->done) {
            func_002ac8e0(id);
            ((W78Slot8*)(id * 8 + (u32)D_0035f5e4 + 4096))->done = 1;
        }
    } else if (func_002a43f0()) {
        W78Slot8* e = (W78Slot8*)(id * 8 + (u32)D_0035f5e4 + 4096);
        if (e->on && !e->done) {
            func_002ab728(id);
            ((W78Slot8*)(id * 8 + (u32)D_0035f5e4 + 4096))->done = 1;
        }
    } else {
        W78Slot8* e = (W78Slot8*)(id * 8 + (u32)D_0035f5e4 + 4096);
        if (e->on && !e->done) {
            func_002abac8(id);
            ((W78Slot8*)(id * 8 + (u32)D_0035f5e4 + 4096))->done = 1;
        }
    }
    func_002a3318();
}
}  // namespace n002a3aa8

