// Linked unit 0x00168aa0-0x00169398.
#include "../common/types.h"
#include <stdarg.h>
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// 00168aa0 (was src/anon/batch_w23.cpp)
namespace n00168aa0 {
// 00157aa0: moved to src/anon/unit_00157688.cpp

struct E16 { u16 id; u8 pad[14]; };
struct T168 { u32 pad; s32 n; u32 pad2[2]; E16 e[1]; };
/*TARGET 00168aa0*/
s32 func_00168aa0(T168* t, u32 id) asm("func_00168aa0");
s32 func_00168aa0(T168* t, u32 id) {
    s32 c = 0;
    s32 i;
    for (i = 0; i < t->n; i++) {
        if (t->e[i].id == id) c++;
    }
    return c;
}
}  // namespace n00168aa0

// 00168ad8 (was src/anon/batch_w40.cpp)
namespace n00168ad8 {
// 0x00166968: definition moved into src/anon/unit_001664c0.cpp

struct E168 { u16 id; u16 pad; s32 val; u32 x, y; };
struct T168 { u32 f0; s32 count; u32 f8, fc; E168 e[1]; };
/*TARGET 00168ad8*/
// Counts entries matching (id, val); id -1 matches any id.
void func_00168ad8(T168* t, s32* out, s32 id, s32 v) asm("func_00168ad8");
// Counts entries matching (id, val); id -1 matches any id.
void func_00168ad8(T168* t, s32* out, s32 id, s32 v) {  // scan_entries_to_out
    *out = 0;
    for (s32 i = 0; i < t->count; i++) {
        if ((id == -1 || t->e[i].id == id) && t->e[i].val == v) (*out)++;
    }
}
}  // namespace n00168ad8

// 00168b38 (was src/anon/batch_w63.cpp)
namespace n00168b38 {
// 00167f38: moved to src/anon/unit_00167358.cpp

struct E16 { u16 id; u16 pad; u32 w[3]; };
struct H16 { u32 f0; s32 count; u32 pad[2]; E16 e[1]; };
/*TARGET 00168b38*/
// Returns the n-th entry with the given id (id -1 matches any).
E16* func_00168b38(H16* h, s32 id, s32 n) asm("func_00168b38");
// Returns the n-th entry with the given id (id -1 matches any).
E16* func_00168b38(H16* h, s32 id, s32 n) {  // entry_array_find_nth
    s32 i = 0;
    if (h->count > 0) {
        E16* e = h->e;
        do {
            if (id == -1 || e->id == id) {
                if (--n == -1) return e;
            }
            i++;
            e++;
        } while (i < h->count);
    }
    return 0;
}
}  // namespace n00168b38

// 00168b88 (was src/anon/batch_w41.cpp)
namespace n00168b88 {
struct W41Ent16 { u16 id; u16 pad; s32 val; u32 x, y; };
struct W41Tbl { u32 f0; s32 n; u32 f8, fc; W41Ent16 e[1]; };
/*TARGET 00168b88*/
// 0x00139b28: definition moved into src/anon/unit_001393c8.cpp

// 0014d478: moved to src/anon/unit_0014d298.cpp

// 00159130: moved to src/harata/libdk/lightcyclecamera.cpp

W41Ent16* func_00168b88(W41Tbl* t, s32 id, s32 val, s32 k) asm("func_00168b88");
// 0x00139b28: definition moved into src/anon/unit_001393c8.cpp

// 0014d478: moved to src/anon/unit_0014d298.cpp

// 00159130: moved to src/harata/libdk/lightcyclecamera.cpp

W41Ent16* func_00168b88(W41Tbl* t, s32 id, s32 val, s32 k) {  // find_entry16_by_half_word
    for (s32 i = 0; i < t->n; i++) {
        if (id == -1 || t->e[i].id == id) {
            if (t->e[i].val == val) {
                if (--k == -1) return &t->e[i];
            }
        }
    }
    return 0;
}
}  // namespace n00168b88

// 00168be8 (was src/anon/batch_wcx2.cpp)
namespace n00168be8 {
// --------------------
struct Rel168Ent { u16 type; u16 flags; u32 pad; u32 ofs; u32 size; };
struct Rel168Hdr { u32 pad; s32 count; u32 base; u32 pad2; Rel168Ent e[1]; };
void func_0011f2f0(u32) asm("func_0011f2f0");
void func_00131e80(u32) asm("func_00131e80");
void func_0013a8b8(u32) asm("func_0013a8b8");
void func_001dc098(u32) asm("func_001dc098");
void func_00127d40(u32) asm("func_00127d40");
void func_001de750(u32) asm("func_001de750");
/*TARGET 00168be8*/
void func_00168be8(Rel168Hdr* h) asm("func_00168be8");
void func_00168be8(Rel168Hdr* h) {
    s32 i;
    if (h->base != 0) return;
    h->base = (u32)h;
    for (i = 0; i < h->count; i++) {
        if (h->e[i].size == 0) {
            h->e[i].ofs = 0;
            continue;
        }
        u32 p = h->base + h->e[i].ofs;
        h->e[i].ofs = p;
        if (h->e[i].flags & 1) continue;
        switch (h->e[i].type) {
        case 1: case 17: case 20: case 30: case 46:
            func_00168be8((Rel168Hdr*)p);
            break;
        case 4:
            func_0011f2f0(p);
            break;
        case 7:
            func_00131e80(p);
            func_0013a8b8(p);
            break;
        case 8:
            func_001dc098(p);
            break;
        case 9:
            func_00127d40(p);
            break;
        case 18:
            func_001de750(p);
            break;
        }
    }
}
}  // namespace n00168be8

// 00168d08 (was src/anon/batch_w1831_nsa.cpp)
namespace n00168d08 {
// 00168d08: relocates a block's entry pointers after a move and recurses into sub-blocks.
struct W1831Ent { u8 hdr[16]; u16 type; u16 flags; u32 pad; u8* ptr; u32 size; };
struct W1831Blk { u32 f0; s32 count; W1831Blk* base; u32 fc; };
void func_0011f3e0(u8*) asm("func_0011f3e0");
void func_00131f48(u8*) asm("func_00131f48");
void func_0013a8b8(u8*) asm("func_0013a8b8");
void func_001dc140(u8*) asm("func_001dc140");
void func_00127dc8(u8*) asm("func_00127dc8");
void func_001de770(u8*) asm("func_001de770");
void func_002bc708(u8*) asm("func_002bc708");
/*TARGET 00168d08*/
// The second argument is the entry's old pointer; the code never reads it but passes it on.
void func_00168d08(W1831Blk* b, u8* x) asm("func_00168d08");
// The second argument is the entry's old pointer; the code never reads it but passes it on.
void func_00168d08(W1831Blk* b, u8* x) {
    s32 i;
    s32 d = (u8*)b - (u8*)b->base;
    b->base = b;
    for (i = 0; i < b->count; i++) {
        W1831Ent* e = (W1831Ent*)(i * 16 + (u32)b);
        s32 used = e->size != 0;  // signed "< 1" test on the 0/1 value: needed for the register order
        if (used < 1) continue;
        u8* o = e->ptr;
        u8* p = o + d;
        e->ptr = p;
        if (e->flags & 1) continue;
        switch (e->type) {
        case 1: case 17: case 20: case 30: case 46:
            func_00168d08((W1831Blk*)p, o);
            break;
        case 4:
            func_0011f3e0(p);
            break;
        case 7:
            func_00131f48(p);
            func_0013a8b8(p);
            break;
        case 8:
            func_001dc140(p);
            break;
        case 9:
            func_00127dc8(p);
            break;
        case 18:
            func_001de770(p);
            break;
        case 34:
            func_002bc708(p);
            break;
        }
    }
}
}  // namespace n00168d08

// 00168e30 (was src/anon/batch_wcx2.cpp)
namespace n00168e30 {
// --------------------
struct Rel168eEnt { u16 type; u16 flags; u32 pad; u32 ofs; u32 size; };
struct Rel168eHdr { u32 pad; s32 count; u32 base; u32 pad2; Rel168eEnt e[1]; };
void func_0011f3b8_x8152(u32) asm("kn__modelDestroy");
void func_00131f40(u32) asm("func_00131f40");
void func_00127da0(u32) asm("func_00127da0");
void func_002bc708(u32) asm("func_002bc708");
/*TARGET 00168e30*/
void func_00168e30(Rel168eHdr* h) asm("func_00168e30");
void func_00168e30(Rel168eHdr* h) {
    s32 i;
    h->base = (u32)h;
    for (i = 0; i < h->count; i++) {
        if (h->e[i].size == 0) continue;
        if (h->e[i].flags & 1) continue;
        u32 p = h->e[i].ofs;
        switch (h->e[i].type) {
        case 1: case 17: case 20: case 30: case 46:
            func_00168e30((Rel168eHdr*)p);
            break;
        case 4:
            func_0011f3b8_x8152(p);
            break;
        case 7:
            func_00131f40(p);
            break;
        case 9:
            func_00127da0(p);
            break;
        case 34:
            func_002bc708(p);
            break;
        }
    }
}
}  // namespace n00168e30

// 00168f18 (was src/anon/auto80_199_queue.cpp)
namespace n00168f18 {
/*TARGET 00168f18*/
u32 func_00168f18() asm("_Z13func_00168f18v");
u32 func_00168f18() {
    func_00168808(0xFFFFFFFFu);
    func_001675b0();
    func_001b13d8();
    func_0016e8f8();
    YS__PROGRESS__Read();
    YS__BATTLE__SysInit();
    func_00196170();
    func_00196300();
    func_00199688();
    func_001aeb80();
    YS__MISSION_TABLE__Init();
    func_001aaa08();
    func_0019f790();
    YS__MESSAGE__SysInit();
    YS__JIGSAW__Init();
    return func_001b13f0();
}
}  // namespace n00168f18

// 00168fa8 (was src/anon/tiny_auto80_fptr0.cpp)
namespace n00168fa8 {
u32 func_00179bc8() asm("_Z13func_00179bc8v");
u32 func_0019ef60() asm("_Z13func_0019ef60v");
u32 func_001d5a20() asm("_Z13func_001d5a20v");
/*TARGET 00168fa8*/
// 0x0014f2d8: definition moved into src/anon/unit_0014ecb8.cpp

u32 func_00168fa8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00168fa8jjjj");
// 0x0014f2d8: definition moved into src/anon/unit_0014ecb8.cpp

u32 func_00168fa8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r14, r15;
    r14 = (u32)((s32)0u + (-1));
    r15 = (u32)(0x004fu << 16);
    *(u32*)((u32)r15 + (s32)(25216)) = r14;
    u32 (*fp_call0_00179bc8)() = func_00179bc8;
    r2 = fp_call0_00179bc8();
    u32 (*fp_call0_0019ef60)() = func_0019ef60;
    r2 = fp_call0_0019ef60();
    return func_001d5a20();
}
}  // namespace n00168fa8

// 00168fd8 (was src/anon/auto80_199_queue.cpp)
namespace n00168fd8 {
/*TARGET 00168fd8*/
void func_00168fd8(u32 a0) asm("_Z13func_00168fd8j");
void func_00168fd8(u32 a0) {
    func_00195738();
    func_001afa50();
    func_001ba138();  // to_2fd310_block

    s32 t5 = 13;
    if ((s32)a0 == t5) {
        func_00170a50();
        return;
    }
    if ((s32)D_004f6280 == t5) {
        func_00170a50();
    }
}
}  // namespace n00168fd8

// 00169030 (was src/anon/batch_w97.cpp)
namespace n00169030 {
// 00158300: moved to src/anon/unit_00158050.cpp

// ---- 00169030
struct Area169 { u8 id; u8 pad[3]; u8 f4[1]; };
extern Area169 D_0032bae0 asm("D_0032bae0");
extern u32 D_004f6280 asm("D_004f6280");
void func_00168808(u32) asm("func_00168808");
s32 func_001688b8(void) asm("func_001688b8");
void func_00102448(u32, s32) asm("func_00102448");
void func_00168fd8(u32) asm("func_00168fd8");
void func_0016f7b0(void) asm("func_0016f7b0");
void func_00181ad0(Area169*) asm("func_00181ad0");
void func_00170320(s32) asm("func_00170320");
void func_001c10c8(void) asm("func_001c10c8");
void func_00191758(void) asm("func_00191758");
void func_001bb270(void) asm("func_001bb270");
void func_00198b88(void) asm("func_00198b88");
void func_001aebf0(Area169*) asm("func_001aebf0");
void func_001947a0(void) asm("func_001947a0");
void func_001823d0(void*) asm("func_001823d0");
void func_001a89f0(void) asm("func_001a89f0");
void func_00196b88(void) asm("func_00196b88");
void func_001a8498(void) asm("func_001a8498");
void func_001c8de0(void) asm("func_001c8de0");
void YS__RECOV__Exec(u32) asm("YS__RECOV__Exec");
/*TARGET 00169030*/
void func_00169030(u32 a) asm("func_00169030");
void func_00169030(u32 a) {
    Area169* ar = &D_0032bae0;
    if (ar->id != D_004f6280) {
        func_00168808(ar->id);
        while (func_001688b8()) func_00102448(a, 0);
        func_00168fd8(ar->id);
        D_004f6280 = ar->id;
    }
    func_0016f7b0();
    func_00181ad0(ar);
    while (func_001688b8()) func_00102448(a, 0);
    func_00170320(-200);
    func_001c10c8();
    func_00191758();
    func_001bb270();
    func_00198b88();
    func_001aebf0(ar);
    func_001947a0();
    func_001823d0(ar->f4);
    func_001a89f0();
    func_00196b88();
    func_001a8498();
    func_001c8de0();
    YS__RECOV__Exec(11);
}
}  // namespace n00169030

// 00169148 (was src/anon/batch_w6.cpp)
namespace n00169148 {
void ys_area_read(void* task) asm("_ZN2YS8AreaReadEP4TASK");
// 0x001671e8: definition moved into src/anon/unit_001664c0.cpp

void func_00170888(void*) asm("func_00170888");
void func_001badd8(void) asm("func_001badd8");
void func_001afaf0(void*) asm("func_001afaf0");
/*TARGET 00169148*/
void ys_area_read(void* task) asm("_ZN2YS8AreaReadEP4TASK");
void ys_area_read(void* task) {
    func_00170888(task);
    func_001badd8();
    func_001afaf0(task);
}
}  // namespace n00169148

// 00169178 (was src/anon/batch_w65.cpp)
namespace n00169178 {
// 0x00137630: definition moved into src/anon/unit_001374c8.cpp

// Rebuild the cached text when the current value changes.
extern u8 D_0032bae0 asm("D_0032bae0");
// 0x00166618: definition moved into src/anon/unit_001664c0.cpp

extern u32 D_0034f240 asm("D_0034f240");
void func_00192260(u32, s32) asm("func_00192260");
void func_001b8318(void) asm("func_001b8318");
void func_001a3a50(void) asm("func_001a3a50");
void func_001a64c0(void) asm("func_001a64c0");
void YS__PRIZE__Read(void) asm("YS__PRIZE__Read");
void YS__PRIZEBOX__Read(void) asm("YS__PRIZEBOX__Read");
void func_00182ab0(void) asm("func_00182ab0");
void func_001c8838(s32) asm("func_001c8838");
void func_001bae08(void) asm("func_001bae08");
/*TARGET 00169178*/
void func_00169178(void) asm("func_00169178");
void func_00169178(void) {
    func_00192260(D_0032bae0, 1040);
    func_001b8318();
    func_001a3a50();
    if (!(D_0034f240 & 0x80000)) func_001a64c0();
    YS__PRIZE__Read();
    u32 v = D_0034f240;
    if (v & 0x200) {
    } else if (v & 0x400) {
    } else {
        YS__PRIZEBOX__Read();
    }
    func_00182ab0();
    func_001c8838(1);
    func_001bae08();
}
}  // namespace n00169178

// 00169210 (was src/anon/batch_w79.cpp)
namespace n00169210 {
u32 func_001050c8(void) asm("func_001050c8");
extern char D_0032bae0[] asm("D_0032bae0");
void func_00192290(u8, s32) asm("func_00192290");
void func_001ac778(void) asm("func_001ac778");
void func_001b8348(void) asm("func_001b8348");
void func_0016c750(u32) asm("func_0016c750");
void func_001900d0(void) asm("func_001900d0");
void func_001b9230(void) asm("func_001b9230");
void func_0017dec0(void) asm("func_0017dec0");
void func_00185d98(void) asm("func_00185d98");
void func_001aeae0(void) asm("func_001aeae0");
void func_00196a40(void) asm("func_00196a40");
void func_001a0bc0(void) asm("func_001a0bc0");
void YS__ATTACK__Init(void) asm("YS__ATTACK__Init");
void func_001a5f50(void) asm("func_001a5f50");
void func_00199548(void) asm("func_00199548");
void func_001a6a10(void) asm("func_001a6a10");
void func_001b14d8(void) asm("func_001b14d8");
void YS__BLUR__Init(void) asm("YS__BLUR__Init");
void YS__LIMIT__Init(void) asm("YS__LIMIT__Init");
void func_00179be8(void) asm("func_00179be8");
void func_001c8a90(void) asm("func_001c8a90");
void func_001d3b60(void) asm("func_001d3b60");
void func_001d5a48(void) asm("func_001d5a48");
void func_001a3a88(void) asm("func_001a3a88");
void func_001ba718(void) asm("func_001ba718");
void YS__PRIZE__Init(void) asm("YS__PRIZE__Init");
void func_001b24c0(void) asm("func_001b24c0");
void YS__UNIT__ActivateAll(void) asm("YS__UNIT__ActivateAll");
/*TARGET 00169210*/
// 00105b58: moved to src/common/region.cpp

// 00149cb8: moved to src/harata/libdk/area.cpp

void func_00169210(void) asm("func_00169210");
// 00105b58: moved to src/common/region.cpp

// 00149cb8: moved to src/harata/libdk/area.cpp

void func_00169210(void) {
    func_00192290(D_0032bae0[0], 2);
    func_001ac778();
    func_001b8348();
    func_0016c750(func_001050c8());
    func_001900d0();
    func_001b9230();
    func_0017dec0();
    func_00185d98();
    func_001aeae0();
    func_00196a40();
    func_001a0bc0();
    YS__ATTACK__Init();
    func_001a5f50();
    func_00199548();
    func_001a6a10();
    func_001b14d8();
    YS__BLUR__Init();
    YS__LIMIT__Init();
    func_00179be8();
    func_001c8a90();
    func_001d3b60();
    func_001d5a48();
    func_001a3a88();
    func_001ba718();
    YS__PRIZE__Init();
    func_001b24c0();
    YS__UNIT__ActivateAll();
}
}  // namespace n00169210

// 00169308 (was src/anon/batch_w32.cpp)
namespace n00169308 {
void func_001a5e38(void) asm("func_001a5e38");
void func_001ba740(void) asm("func_001ba740");
void func_001b24c8(void) asm("func_001b24c8");
void func_001bb468(void) asm("func_001bb468");
void func_001922c8(s32) asm("func_001922c8");
void func_001b83d0(void) asm("func_001b83d0");
void func_00197be8(void) asm("func_00197be8");
// 0x00148638: definition moved into src/anon/unit_00147140.cpp

// 00158450: moved to src/harata/libdk/cameraconfig.cpp

void AreaExit(void) asm("_ZN2YS8AreaExitEv");
/*TARGET 00169308*/
void AreaExit(void) asm("_ZN2YS8AreaExitEv");
void AreaExit(void) {
    func_001a5e38();
    func_001ba740();
    func_001b24c8();
    func_001bb468();
    func_001922c8(2);
    func_001b83d0();
    func_00197be8();
}
}  // namespace n00169308

// 00169350 (was src/anon/tiny_auto80_fptr0.cpp)
namespace n00169350 {
u32 func_0016c770() asm("_Z13func_0016c770v");
u32 func_00182d80() asm("_Z13func_00182d80v");
u32 func_0018d790() asm("_Z13func_0018d790v");
u32 func_001a3b08() asm("_Z13func_001a3b08v");
u32 func_001b5400() asm("_Z13func_001b5400v");
u32 func_001d3b68() asm("_Z13func_001d3b68v");
u32 func_001a6ae8() asm("_Z13func_001a6ae8v");
/*TARGET 00169350*/
u32 func_00169350(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00169350jjjj");
u32 func_00169350(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call0_001b5400)() = func_001b5400;
    r2 = fp_call0_001b5400();
    u32 (*fp_call0_001a3b08)() = func_001a3b08;
    r2 = fp_call0_001a3b08();
    u32 (*fp_call0_0018d790)() = func_0018d790;
    r2 = fp_call0_0018d790();
    u32 (*fp_call0_0016c770)() = func_0016c770;
    r2 = fp_call0_0016c770();
    u32 (*fp_call0_00182d80)() = func_00182d80;
    r2 = fp_call0_00182d80();
    u32 (*fp_call0_001d3b68)() = func_001d3b68;
    r2 = fp_call0_001d3b68();
    return func_001a6ae8();
}
}  // namespace n00169350

