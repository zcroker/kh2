#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/menu_sound.hpp"

// 0016e8f8 (from src/anon/batch_w5.cpp)
namespace n0016e8f8 {
u32 func_001b1448(u32) asm("func_001b1448");
void func_001d3390(u32) asm("func_001d3390");
extern u32 D_0034dc28 asm("D_0034dc28");
void func_0016e8f8(void) asm("func_0016e8f8");
void func_0016e8f8(void) {
    func_001d3390(func_001b1448(D_0034dc28));
}
} // n0016e8f8

// 0016e920 (from src/anon/batch_w110.cpp)
namespace n0016e920 {
struct JmSrc { u8 pad[18]; u16 f18; u16 f20; };
extern u32 D_004f63a0 asm("D_004f63a0");
extern u8 D_0032f054 asm("D_0032f054");
extern s32 D_00350cd0 asm("D_00350cd0");
u32 func_001d1438(u32) asm("func_001d1438");
u32 func_0017df70(s32) asm("func_0017df70");
u32 func_00198040(s32) asm("func_00198040");
u32 func_0016eb18(u32, s32) asm("func_0016eb18");
JmSrc* func_001a8b28(void) asm("func_001a8b28");
u32 func_0017dfc8(s32) asm("func_0017dfc8");
void* func_001d3408(u32) asm("func_001d3408");
void* GetCharaData_0016e920(u32 id) asm("_ZN2Tz6JmInfo12GetCharaDataEj");
void* GetCharaData_0016e920(u32 id) {
    u32 r = id;
    switch (id & 0xfffffff) {
    case 566:
        {
            u32 t = D_004f63a0;
            if (t) { r = t; break; }
        }
    case 571:
        r = func_001d1438(D_0032f054);
        if (!r) r = func_001d1438(0);
        break;
    case 567: r = func_0017df70(1); break;
    case 568: r = func_0017df70(2); break;
    case 572: r = func_00198040(1); break;
    case 573: r = func_0016eb18(566, 0); break;
    case 575: r = func_0016eb18(func_001a8b28()->f18, 0); break;
    case 576: r = func_0016eb18(func_001a8b28()->f20, 0); break;
    case 704: r = func_0016eb18(101, 0); break;
    case 793: r = func_0017dfc8(1); break;
    case 794: r = func_0017dfc8(2); break;
    case 1006: r = func_0017dfc8(3); break;
    case 1578: r = D_00350cd0 == 1035 ? 1036 : 1035; break;
    case 1579: r = D_00350cd0 == 1035 ? 1035 : 1036; break;
    }
    if (r == 0) return 0;
    return func_001d3408(r & 0xfffffff);
}
} // n0016e920

// 0016eb18 (from src/anon/batch_w10.cpp)
namespace n0016eb18 {
void* func_0016e920(void*, void*) asm("func_0016e920");
void func_0016f6a0(void*, void*) asm("func_0016f6a0");
void func_0016eb18(void* a, void* b) asm("func_0016eb18");
void func_0016eb18(void* a, void* b) {
    func_0016f6a0(func_0016e920(a, b), b);
}
} // n0016eb18

// 0016eb48 (from src/anon/batch_w1992.cpp)
namespace n0016eb48 {
struct P16eb48 { u32 w0; u8 b4; u8 pad[0x48 - 5]; u8 b48; u8 pad2[0x4e - 0x49]; u16 h4e; u8 pad3[0x58 - 0x50]; u16 sub[4]; };
P16eb48* func_0016e920(u32) asm("func_0016e920");
s32 func_0016f6f8(u32) asm("func_0016f6f8");
s32 func_0016f770(u32) asm("func_0016f770");
s32 func_0016f8d0(u32) asm("func_0016f8d0");
u32 func_0016f470(P16eb48*, s32) asm("func_0016f470");
u32 func_0016f4b8(P16eb48*, s32) asm("func_0016f4b8");
u32 func_0016f520(P16eb48*, u32, s32) asm("func_0016f520");
u32 func_0016f6a0(P16eb48*, s32) asm("func_0016f6a0");
void func_00170518(u32, s32, s32) asm("func_00170518");
void func_00170530(u32, s32, s32, s32) asm("func_00170530");
void func_0016ef58(u16, s32, u32, s32, s32) asm("func_0016ef58");
extern s32 D_0036c278[] asm("D_0036c278");
static inline s32 w1992_off2(P16eb48* p) { return !(p->b48 & 1); }
void w1992_tail4_16eb48(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16u_tail4_0016eb48jjjj");
void w1992_tail4_16eb48(u32 a0, u32 a1, u32 a2, u32 a3) {
    P16eb48* p = func_0016e920(a0);
    if (p == 0) return;
    if ((s32)a1 == -1) {
        a1 = (u32)-200;
        if (!func_0016f6f8(a0)) a1 = D_0036c278[p->b4];
        if (!func_0016f770(a0) && a1 == 2400) a1 = func_0016f8d0(p->w0);
    }
    func_00170518(func_0016f470(p, 0), a1, 0);
    if (!func_0016f6f8(a0)) {
        if (!func_0016f770(a0)) {
            if (w1992_off2(p)) func_00170530(func_0016f4b8(p, 0), a1, a2, 0);
        }
    }
    if (!func_0016f6f8(a0)) {
        u32 r = func_0016f520(p, a0, 0);
        if (r) func_00170518(r, a1, 0);
    }
    if (func_0016f770(a0)) return;
    for (s32 i = 0; i < 2; ) {
        if ((s32)a1 >= 0) a1++;
        u32 r = func_0016f6a0(p, i);
        s32 k = i++;
        u32 c = a2;
        if ((s32)a3 >= 0) a2 = a3;
        if (r) { r |= a0 & 0x40000000; func_0016ef58(p->h4e, k, r, a1, c); }
    }
    for (s32 j = 3; j >= 0; j--) {
        u16* q = &p->sub[3 - j];
        if (*q) w1992_tail4_16eb48(*q, a1, a2, a3);
    }
}
} // n0016eb48

// 0016ed50 (from src/anon/batch_w110.cpp)
namespace n0016ed50 {
void* GetCharaData_0016e920(u32 id) asm("_ZN2Tz6JmInfo12GetCharaDataEj");
struct JmEnt { u32 id; u8 type; u8 pad[82]; s8 f87; };
extern u32 D_004f63a0 asm("D_004f63a0");
extern u32 D_004f63a8 asm("D_004f63a8");
extern u32 D_004f63ac asm("D_004f63ac");
extern u8 D_0032f054 asm("D_0032f054");
u32 func_001d1438(u32) asm("func_001d1438");
s32 func_0016f6f8(u32) asm("func_0016f6f8");
s32 func_0016f770(u32) asm("func_0016f770");
u32 func_0016eb48(u32, u32, u32, s32) asm("func_0016eb48");
u32 func_0016ef28(u8) asm("func_0016ef28");
u32 wtarget_0016ed50(u32 id, u32 kind, u32 mode, u32) asm("func_0016ed50");
u32 wtarget_0016ed50(u32 id, u32 kind, u32 mode, u32) {
    switch (id) {
    case 568: return func_0016eb48(id, kind, 6, -1);
    case 567: return func_0016eb48(id, kind, 5, -1);
    case 566:
        if (D_004f63a0) {
            return func_0016eb48(D_004f63a0, kind, 4, -1);
        } else {
            JmEnt* e = (JmEnt*)GetCharaData_0016e920(func_001d1438(0));
            u32 r = func_0016eb48(e->id, kind, 4, 7);
            if (e->f87 < 7 && D_0032f054) return func_0016ef28(D_0032f054);
            return r;
        }
    case 793: return func_0016eb48(0x20000237, kind, 5, -1);
    case 794: return func_0016eb48(0x20000238, kind, 6, -1);
    }
    if (!func_0016f6f8(id) && !func_0016f770(id) && mode == 30) {                         
        JmEnt* e = (JmEnt*)GetCharaData_0016e920(id);
        if (!e) return;
        switch (e->type) {
        case 1: mode = 5; break;
        case 0: D_004f63a0 = id; mode = 4; break;
        case 19: mode = 7; break;
        }
    }
    switch (kind) {
    case 2410: D_004f63a8 = id; break;
    case 2420: D_004f63ac = id; break;
    }
    func_0016eb48(id, kind, mode, -1);
}
} // n0016ed50

// 0016ef28 (from src/anon/tiny_auto80_fptr4.cpp)
namespace n0016ef28 {
u32 func_001d1438(u32, u32, u32, u32) asm("func_001d1438");
u32 func_0016eb48(u32, u32, u32, u32) asm("func_0016eb48");
u32 func_0016ef28(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0016ef28");
u32 func_0016ef28(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call4_001d1438)(u32, u32, u32, u32) = func_001d1438;
    r2 = fp_call4_001d1438(r4, r5, r6, r7);
    r4 = r2;
    r5 = (u32)((s32)0u + (5000));
    r6 = (u32)((s32)0u + (4));
    r7 = (u32)((s32)0u + (7));
    return func_0016eb48(r4, r5, r6, r7);
}
} // n0016ef28

// 0016ef58 (from src/anon/auto80_199_queue.cpp)
namespace n0016ef58 {
void func_0016ef58(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) asm("func_0016ef58");
void func_0016ef58(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    u32 s0 = a2;
    u32 s1 = a0;
    u32 s2 = a1;
    u32 s3 = a3;

    func_0016eb48(s0, s3, a4, -1);
    if (func_0016f6f8(s0) != 0) {                         
        return;
    }

    u32 v0 = func_00185920(s1, s2, 0);
    if (v0 != 0) {
        func_00170518(v0, s3, 0);
    }
}
} // n0016ef58

// 0016f000 (from src/anon/batch_w1634.cpp)
namespace n0016f000 {
struct W1634CharaData {
    u32 id;
    u8 type;
    u8 pad5[79];
    u8 cost;
    u8 pad55[2];
    s8 level;
};
extern u8 D_0032f054 asm("D_0032f054");
void* W1634_AREA_Alloc(u32) asm("_ZN4AREA5AllocEj");
W1634CharaData* W1634_GetCharaData(u32) asm("_ZN2Tz6JmInfo12GetCharaDataEj");
u32 W1634_SORA_GetEntryId(s32) asm("_ZN2YS4SORA10GetEntryIdEi");
s32 W1634_AREADATA_CanAddCost(f32) asm("_ZN2YS8AREADATA10CanAddCostEf");
s32 func_0016f6f8(u32) asm("func_0016f6f8");
s32 func_0016f770(u32) asm("func_0016f770");
s32 func_0016f7a0(u32) asm("func_0016f7a0");
void func_00197fe0(void*, W1634CharaData*, s32, void*, f32) asm("func_00197fe0");
void* func_00179fd0(W1634CharaData*, s32, void*, f32) asm("func_00179fd0");
void* func_0017e418(W1634CharaData*, void*, f32) asm("func_0017e418");
void func_001aea00(void*, W1634CharaData*, void*, f32) asm("func_001aea00");
void func_001b1d60(void*, W1634CharaData*, void*, f32) asm("func_001b1d60");
void func_00195ed8(void*, W1634CharaData*, void*, f32) asm("func_00195ed8");
void func_001b3a90(void*, W1634CharaData*, void*, f32) asm("func_001b3a90");
void func_001a8618(void*, W1634CharaData*, void*, f32) asm("func_001a8618");
void func_001aeb40(void*, W1634CharaData*, void*, f32) asm("func_001aeb40");
void func_001b20a0(void*, W1634CharaData*, void*, f32) asm("func_001b20a0");
void func_001a6bc8(void*, W1634CharaData*, void*, f32) asm("func_001a6bc8");
void func_0018aba0(void*, W1634CharaData*, s32, void*, f32) asm("func_0018aba0");
void* func_002d0290(W1634CharaData*, void*, f32) asm("func_002d0290");
void* func_002be800(W1634CharaData*, void*, f32) asm("func_002be800");
void func_001bf270(void*, W1634CharaData*, void*, s32, f32) asm("func_001bf270");
void func_001c7fb8(void*, W1634CharaData*, void*, f32) asm("func_001c7fb8");
void func_001c2338(void*, W1634CharaData*, void*, f32) asm("func_001c2338");
void func_001c4120(void*, W1634CharaData*, void*, f32) asm("func_001c4120");
void* func_001c25e8(W1634CharaData*, void*, f32) asm("func_001c25e8");
void func_001c2ce8(void*, W1634CharaData*, void*, f32) asm("func_001c2ce8");
void func_001d9ef0(void*, W1634CharaData*, void*, f32) asm("func_001d9ef0");
typedef void (*W1634Ctor)(void*, W1634CharaData*, void*, f32);
template <W1634Ctor F, u32 SZ>
static inline void* W1634New(W1634CharaData* cd, void* pos, f32 rot) {
    void* p = W1634_AREA_Alloc(SZ);
    F(p, cd, pos, rot);
    return p;
}
static inline __attribute__((always_inline)) void* W1634Create(W1634CharaData* cd, void* pos, f32 rot) {
    switch (cd->type) {
    case 0:
        return (void*)func_00179fd0(cd, cd->level, pos, rot);
    case 1:
        return (void*)func_0017e418(cd, pos, rot);
    case 3:
        return (void*)W1634New<func_001aea00, 0xb00>(cd, pos, rot);
    case 4:
        return (void*)W1634New<func_001b1d60, 0xb00>(cd, pos, rot);
    case 7:
        return (void*)W1634New<func_00195ed8, 0xa00>(cd, pos, rot);
    case 9:
        return (void*)W1634New<func_001b3a90, 0xaf0>(cd, pos, rot);
    case 10:
        return (void*)W1634New<func_001a8618, 0xa00>(cd, pos, rot);
    case 12:
        return (void*)W1634New<func_001aeb40, 0xb00>(cd, pos, rot);
    case 13:
        return (void*)W1634New<func_001b20a0, 0xaf0>(cd, pos, rot);
    default:
        return (void*)W1634New<func_001a6bc8, 0xaf0>(cd, pos, rot);
    case 15:
        { void* p = W1634_AREA_Alloc(0xb40); func_0018aba0(p, cd, 5, pos, rot); return p; }
    case 16:
        return (void*)func_002d0290(cd, pos, rot);
    case 17:
        return (void*)func_002be800(cd, pos, rot);
    case 18:
        { void* p = W1634_AREA_Alloc(0x9f0); func_001bf270(p, cd, pos, 0, 1.0f); return p; }
    case 19:
        return (void*)W1634New<func_001c7fb8, 0xd00>(cd, pos, rot);
    case 20:
        return (void*)W1634New<func_001c2338, 0xa00>(cd, pos, rot);
    case 21:
        return (void*)W1634New<func_001c4120, 0xb00>(cd, pos, rot);
    case 22:
        return (void*)func_001c25e8(cd, pos, rot);
    case 23:
        return (void*)W1634New<func_001c2ce8, 0xaf0>(cd, pos, rot);
    case 24:
        return (void*)W1634New<func_001d9ef0, 0xa00>(cd, pos, rot);
    case 14:                                                                                     
        return (void*)W1634New<func_001a6bc8, 0xaf0>(cd, pos, rot);
    }
    return 0;
}
void* func_0016f000(u32 id, void* pos, f32 rot) asm("func_0016f000");
void* func_0016f000(u32 id, void* pos, f32 rot) {                 
    W1634CharaData* cd;
    if (func_0016f6f8(id)) {
        cd = W1634_GetCharaData(id);
        id = (u32)W1634_AREA_Alloc(0x9c0);
        func_00197fe0((void*)id, cd, 6, pos, rot);
    } else if (func_0016f770(id)) {
        id = 0;
    } else if (func_0016f7a0(id)) {
        id = 0;
    } else if (id == 566) {
        cd = W1634_GetCharaData(W1634_SORA_GetEntryId(0));
        id = cd->level;
        if (id == 0) {
            id = D_0032f054;
            cd = W1634_GetCharaData(W1634_SORA_GetEntryId(id));
        }
        id = (u32)func_00179fd0(cd, id, pos, rot);
    } else {
        cd = W1634_GetCharaData(id);
        id = 0;
        if (W1634_AREADATA_CanAddCost(cd->cost)) {
            id = (u32)W1634Create(cd, pos, rot);
        }
    }
    return (void*)id;
}
} // n0016f000

// 0016f430 (never written before)
namespace n0016f430 {
void func_001d34d0() asm("func_001d34d0");
void func_0016f430() asm("func_0016f430");
void func_0016f430() { func_001d34d0(); }
} // n0016f430

// 0016f448 (from src/anon/tiny_more2.cpp)
namespace n0016f448 {
extern u32 D_0036c278 asm("D_0036c278");
u32 func_0016f448(u32 a0,u32 a1,u32 a2,u32 a3) asm("func_0016f448");
u32 func_0016f448(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; return *(u32*)((u32)&D_0036c278 + ((u32)a0 << 2) + (0)); }
} // n0016f448

// 0016f460 (from src/anon/tiny_leaf.cpp)
namespace n0016f460 {
u32 func_0016f460(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0016f460");
u32 func_0016f460(u32 a0, u32 a1, u32 a2, u32 a3) {                     
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = (u32)(s32)(*(s8*)((u32)r4 + (s32)(40)));
    r2 = ((u32)0u < (u32)r2);
    return r2;
}
} // n0016f460

// 0016f470 (from src/anon/batch_w34.cpp)
namespace n0016f470 {
void func_002fee78(char*, const char*, void*) asm("func_002fee78");
extern char D_004f63b0[] asm("D_004f63b0");
extern const char D_0036c440[] asm("D_0036c440");
char* func_0016f470(u8* e, char* buf) asm("func_0016f470");
char* func_0016f470(u8* e, char* buf) {
    if (!buf) buf = D_004f63b0;
    func_002fee78(buf, D_0036c440, e + 8);
    return buf;
}
} // n0016f470

// 0016f4b8 (from src/anon/batch_w41.cpp)
namespace n0016f4b8 {
extern char D_004f63d8[] asm("D_004f63d8");
extern char D_0036c450[] asm("D_0036c450");
extern u32 D_0033caf0 asm("D_0033caf0");
void func_002fee78(char*, const char*, ...) asm("func_002fee78");
struct W41SP { u8 pad[72]; u8 flag; };
char* func_0016f4b8(W41SP* p, char* buf) asm("func_0016f4b8");
char* func_0016f4b8(W41SP* p, char* buf) {
    s32 notSet = !(p->flag & 1);
    if (notSet) {
        if (!buf) buf = D_004f63d8;
        func_002fee78(buf, D_0036c450, (u8*)p + 8, D_0033caf0);
        return buf;
    }
    return 0;
}
} // n0016f4b8

// 0016f520 (from src/anon/batch_w80.cpp)
namespace n0016f520 {
struct U0_Res { u8 pad[4]; u8 f4; u8 pad2[3]; char f8[32]; char f40[32]; };
extern char D_004f6400[] asm("D_004f6400");
extern char D_0036c460[] asm("D_0036c460");
extern char D_0036c468[] asm("D_0036c468");
extern char D_0036c478[] asm("D_0036c478");
s32 func_0016f460(void) asm("func_0016f460");
void func_002fee78(char*, const char*, ...) asm("func_002fee78");
s32 func_0016f7a0(u32) asm("func_0016f7a0");
s32 func_0016f770(u32) asm("func_0016f770");
s32 func_00170978(char*) asm("func_00170978");
char* func_002ff8b0(char*, s32) asm("func_002ff8b0");
void func_002ff2e8(char*, const char*) asm("func_002ff2e8");
char* func_0016f520(U0_Res* r, u32 key, char* buf) asm("func_0016f520");
char* func_0016f520(U0_Res* r, u32 key, char* buf) {
    if (!buf) buf = D_004f6400;
    if (func_0016f460()) {
        func_002fee78(buf, D_0036c460, r->f40);
        if (func_0016f7a0(key) || (func_0016f770(key) && r->f4 && func_00170978(buf) < 2)) {              
            func_002ff2e8(func_002ff8b0(buf, '.'), D_0036c468);
        }
        return buf;
    }
    if (func_0016f7a0(key)) {              
        func_002fee78(buf, D_0036c478, r->f8);
    } else buf = 0;
    return buf;
}
} // n0016f520

// 0016f610 (from src/anon/batch_w2434.c)
namespace n0016f610 {
typedef struct O_0016f610 {
    u8 pad[0x4c];
    u16 h4c;
    u16 h4e;
    u8 p50[7];
    s8 b57;
} O_0016f610;
extern u8 D_0032e020[] asm("D_0032e020");
u16* func_00189200(void*, s32) asm("func_00189200");
u16* func_00188fe0(void*, u16) asm("func_00188fe0");
static inline __attribute__((always_inline)) u16 getK_0016f610(O_0016f610* o) { return o->h4c; }
u16 func_0016f610(O_0016f610* o, s32 a1) asm("func_0016f610");
u16 func_0016f610(O_0016f610* o, s32 a1) {
    u16 r;
    u16* p;
    if (o->h4e == 0) r = 0;
    else {
        if ((getK_0016f610(o) == 1 || getK_0016f610(o) == 14) && a1 == 1) {
            p = func_00189200(D_0032e020, o->b57);
            r = 0; if (p) r = *p;
        } else {
            p = func_00188fe0(D_0032e020, getK_0016f610(o));
            r = 0; if (p) r = p[a1];
        }
    }
    return r;
}
} // n0016f610

// 0016f6a0 (from src/anon/batch_w19.cpp)
namespace n0016f6a0 {
void* func_0016f610(const void*, s32) asm("func_0016f610");
void* func_00185890(u32, void*) asm("func_00185890");
void* get_weapon_entry(const void* self, s32 i) asm("_ZNK2YS8OBJENTRY16get_weapon_entryEi");
void* get_weapon_entry(const void* self, s32 i) {
    void* e = func_0016f610(self, i);
    if (!e) return 0;
    return func_00185890(*(const u16*)((const u8*)self + 78), e);
}
} // n0016f6a0

// 0016f6e0 (never written before)
namespace n0016f6e0 {
extern u32 D_0034dc30[] asm("D_0034dc30");
u32 func_0016f6e0(s32 i) asm("func_0016f6e0");
u32 func_0016f6e0(s32 i) { return D_0034dc30[i]; }
} // n0016f6e0

// 0016f6f8 (from src/anon/batch_w43.cpp)
namespace n0016f6f8 {
u32 func_0016e920(u32) asm("func_0016e920");
s32 func_0016f6f8(u32 id) asm("func_0016f6f8");
s32 func_0016f6f8(u32 id) {                         
    if (!(id & 0x40000000)) return 0;
    u8* p = (u8*)func_0016e920(id);
    if (!p) return 0;
    switch (p[4]) {
    case 7: case 22: case 24: return 0;
    default: return 1;
    }
}
} // n0016f6f8

// 0016f770 (from src/anon/batch_w8.cpp)
namespace n0016f770 {
u32 func_0016f770(s32 x) asm("func_0016f770");
u32 func_0016f770(s32 x) {                        
    switch ((u32)x) {
    case 793:
    case 794:
    case 1006:
        return 1;
    }
    return (x >> 29) & 1;
}
} // n0016f770

// 0016f7a0 (from src/anon/tiny_leaf.cpp)
namespace n0016f7a0 {
u32 func_0016f7a0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0016f7a0");
u32 func_0016f7a0(u32 a0, u32 a1, u32 a2, u32 a3) {              
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r4 = (u32)((s32)r4 >> 28);
    r4 = (u32)(r4 & 0x0001u);
    r2 = r4;
    return r2;
}
} // n0016f7a0

// 0016f7b0 (from src/anon/batch_w5.cpp)
namespace n0016f7b0 {
extern u32 D_004f63a8[2] asm("D_004f63a8");
extern u32 D_004f63a0 asm("D_004f63a0");
void func_0016f7b0(void) asm("func_0016f7b0");
void func_0016f7b0(void) {
    D_004f63a8[0] = 0;
    D_004f63a0 = 0;
    D_004f63a8[1] = 0;
}
} // n0016f7b0

// 0016f7d0 (from src/anon/batch_w82.cpp)
namespace n0016f7d0 {
u32 func_0016e920(void) asm("func_0016e920");
u32 func_0016f470(u32, u32) asm("func_0016f470");
u32 func_0016f4b8(u32, u32) asm("func_0016f4b8");
u32 func_0016f520(u32, u32, u32) asm("func_0016f520");
s32 func_00170978(u32) asm("func_00170978");
s32 func_0016f6f8(u32) asm("func_0016f6f8");
s32 func_0016f770(u32) asm("func_0016f770");
s32 func_0016f460(u32) asm("func_0016f460");
static inline s32 FlagOff0016(u32 a) { return !(*(u8*)(a + 72) & 1); }
u32 ctarget_0016f7d0(u32, u32, u32, u32) asm("_Z16ctarget_0016f7d0jjjj");
u32 ctarget_0016f7d0(u32 a0, u32 a1, u32, u32)
{
    u32 mask;
    if (!a1) a1 = func_0016e920();
    mask = 1 << func_00170978(func_0016f470(a1, 0));
    if (!func_0016f6f8(a0) && !func_0016f770(a0) && FlagOff0016(a1))
        mask |= 1 << func_00170978(func_0016f4b8(a1, 0));
    if (!func_0016f6f8(a0) && func_0016f460(a1))
        mask |= 1 << func_00170978(func_0016f520(a1, a0, 0));
    return mask;
}
} // n0016f7d0

// 0016f8d0 (from src/anon/batch_w44.cpp)
namespace n0016f8d0 {
s32 func_0016f930(s32) asm("func_0016f930");
extern void* D_004f63a8 asm("D_004f63a8");
extern void* D_004f63ac asm("D_004f63ac");
void func_0016f8d0(void* p) asm("func_0016f8d0");
void func_0016f8d0(void* p) {
    s32 v = func_0016f930((s32)p);
    if (v == 2400) v = func_0016f930(0);
    switch (v) {
    case 2410: D_004f63a8 = p; break;
    case 2420: D_004f63ac = p; break;
    }
}
} // n0016f8d0

// 0016f930 (from src/anon/batch_w20.cpp)
namespace n0016f930 {
extern s32 D_004f63a8[] asm("D_004f63a8");
s32 func_0016f930(s32 a) asm("func_0016f930");
s32 func_0016f930(s32 a) {
    for (s32 i = 0; i < 2; i++) {
        if (D_004f63a8[i] == a) return 2410 + i * 10;
    }
    return 2400;
}
} // n0016f930

// 0016f970 (from src/anon/batch_w39.cpp)
namespace n0016f970 {
extern u32 D_0034dc98 asm("D_0034dc98");
extern u32 D_01c5f460[] asm("D_01c5f460");
u32 func_00106178(void*, int) asm("func_00106178");
extern u8 D_004f6440[] asm("D_004f6440");
void func_0016f970(void) asm("func_0016f970");
void func_0016f970(void) {
    D_0034dc98 = func_00106178(D_004f6440, 16384);
    for (int i = 0; i < 7; i++) D_01c5f460[i] = 0;
    D_01c5f460[1] = 0xe0000;
    D_01c5f460[5] = 0x300000;
    D_01c5f460[6] = 0xc0000;
}
} // n0016f970

// 0016f9e8 (from src/anon/batch_w38.cpp)
namespace n0016f9e8 {
void func_003058a0(s32) asm("func_003058a0");
void func_001707d8(void) asm("func_001707d8");
void func_0014d430(void) asm("func_0014d430");
extern volatile u8 D_0034dcac asm("D_0034dcac");
void func_0016f9e8(void) asm("func_0016f9e8");
void func_0016f9e8(void) {
    for (;;) {
        func_003058a0(0);
        if (D_0034dcac == 1) {
            do {
                func_001707d8();
                D_0034dcac = 0;
            } while (D_0034dcac == 1);
        }
        func_0014d430();
    }
}
} // n0016f9e8

// 0016fa58 (from src/anon/batch_w14.cpp)
namespace n0016fa58 {
void func_0014d358(void*, s32, void (*)(void), s32) asm("func_0014d358");
void func_0016f9e8(void) asm("func_0016f9e8");
extern u8 D_01c5c460[] asm("D_01c5c460");
void func_0016fa58(void) asm("func_0016fa58");
void func_0016fa58(void) {
    func_0014d358(D_01c5c460, 0x3000, func_0016f9e8, 0);
}
} // n0016fa58

// 0016fa88 (never written before)
namespace n0016fa88 {
u32 func_0016fa88() asm("func_0016fa88");
u32 func_0016fa88() { return 0x01762000; }
} // n0016fa88

// 0016fa98 (from src/anon/tiny.cpp)
namespace n0016fa98 {
extern u32 D_01c5f460 asm("D_01c5f460");
void func_0016fa98(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0016fa98");
void func_0016fa98(u32 a0, u32 a1, u32 a2, u32 a3) {                   
    (void)a2;
    (void)a3;
    *(u32*)((u32)&D_01c5f460 + ((u32)a0 << 2) + (0)) = a1;
}
} // n0016fa98

// 0016fab0 (from src/anon/tiny_auto80.cpp)
namespace n0016fab0 {
extern u8 D_01c5f460 asm("D_01c5f460");
void func_0016fab0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0016fab0");
void func_0016fab0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15;
    r15 = (u32)&D_01c5f460;
    *(volatile u32*)((u32)r15 + (s32)(12)) = r5;
    *(volatile u32*)((u32)r15 + (s32)(8)) = r4;
    *(volatile u32*)((u32)r15 + (s32)(16)) = r5;
}
} // n0016fab0

// 0016fac8 (from src/anon/batch_w19.cpp)
namespace n0016fac8 {
extern void* D_0034dc98 asm("D_0034dc98");
u32 func_0016fac8(u32 a) asm("func_0016fac8");
u32 func_0016fac8(u32 a) {
    void* o = D_0034dc98;
    return (*(u32 (**)(void*, u32, void*))*(u8**)o)(o, a, __builtin_return_address(0));
}
} // n0016fac8

// 0016fb00 (from src/anon/batch_w9.cpp)
namespace n0016fb00 {
extern void* D_0034dc98 asm("D_0034dc98");
void func_0016fb00(u32 a) asm("func_0016fb00");
void func_0016fb00(u32 a) {
    void* o = D_0034dc98;
    (*(void (**)(void*, u32))(*(u8**)o + 4))(o, a);
}
} // n0016fb00

// 0016fb30 (from src/anon/auto80_199_queue.cpp)
namespace n0016fb30 {
void func_0016fb30(u8* a0, u32 a1, u32 a2, u32 a3) asm("func_0016fb30");
void func_0016fb30(u8* a0, u32 a1, u32 a2, u32 a3) {
    u8* s0 = a0;
    u32 s1 = a2;
    u32 s2 = a1;

    *(u32*)(s0 + 44) = a3;
    *(u32*)(s0 + 40) = s1;
    *(u8*)(s0 + 0) = 0;
    *(u8*)(s0 + 1) = 0;
    *(u16*)(s0 + 2) = 0;
    *(u32*)(s0 + 36) = 0;
    *(u32*)(s0 + 48) = 0;
    *(u32*)(s0 + 52) = 0;

    strlen(s2);           
    *(u32*)(s0 + 56) = s1;

    func_002ff2e8(s0 + 4, s2);
}
} // n0016fb30

// 0016fba0 (from src/anon/auto80_199_queue.cpp)
namespace n0016fba0 {
void func_0016fba0(u8* a0, u32 a1, u32 a2, u32 a3) asm("func_0016fba0");
void func_0016fba0(u8* a0, u32 a1, u32 a2, u32 a3) {
    u8* s0 = a0;
    u32 s1 = a2;
    u32 s2 = a1;

    *(u32*)(s0 + 44) = a3;
    *(u32*)(s0 + 40) = s1;
    *(u8*)(s0 + 0) = 0;
    *(u8*)(s0 + 1) = 0;
    *(u16*)(s0 + 2) = 0;
    *(u32*)(s0 + 36) = 0;
    *(u32*)(s0 + 48) = 0;
    *(u32*)(s0 + 52) = 0;

    strlen(s2);           
    *(u32*)(s0 + 56) = s1;

    func_002ff2e8(s0 + 4, s2);
}
} // n0016fba0

// 0016fc10 (from src/anon/batch_w1947_nsa.cpp)
namespace n0016fc10 {
struct O16fc10 { u8 f0; u8 f1; u8 p2[2]; u8 sub[0x20]; u32 flags; s32 f28; s32 size; u32 start; u32 cur; u32 f38; O16fc10* next; };
void func_001684c0(void*, u32, void*, void*) asm("func_001684c0");
void func_00168d08(u32) asm("func_00168d08");
void func_00168e30(u32) asm("func_00168e30");
void func_0016fda8(O16fc10*) asm("func_0016fda8");
void func_001755a4(void*, const void*, s32) asm("_Z13func_001755a4PvPKvi");
extern u8 D_00170160 asm("D_00170160");
extern O16fc10* D_0034dca0 asm("D_0034dca0");
static inline O16fc10* nx16fc10(O16fc10* o) { if (o == 0) return D_0034dca0; return o->next; }
static inline bool big16fc10(O16fc10* a) { return a->f28 >= 10000; }
static inline u8 ovl16fc10(O16fc10* o, O16fc10* a) {
    u8 ov = 0;
    if (o->cur < a->start + a->size) ov = a->start < o->cur + o->size;
    return ov;
}
void func_0016fc10(O16fc10* a) asm("func_0016fc10");
void func_0016fc10(O16fc10* a) {
    O16fc10* o;
    u32 fl = a->flags;
    if ((fl & 1) == 1) return;
    if (fl & 2) return;
    a->flags = fl | 1;
    o = 0;
    if (a->start == a->cur) {
        func_0016fda8(a);
        return;
    }
    while ((o = nx16fc10(o)) != 0) {
        if (o == a) continue;
        fl = o->flags;
        if (fl & 2) continue;
        if (!ovl16fc10(o, a)) continue;
        if ((fl & 1) == 1) break;
        func_0016fc10(o);
    }
    if (o == 0 && a->cur != 0) {
        if (a->size != 0) {
            a->f1 = 1;
            func_00168e30(a->cur);
            func_001755a4((void*)a->start, (const void*)a->cur, a->size);
            func_00168d08(a->start);
            func_0016fda8(a);
        }
    } else if (!big16fc10(a)) {
        a->f1 = 1;
        func_001684c0(a->sub, a->start, &D_00170160, a);
    } else {
        a->flags |= 2;
    }
    a->cur = a->start;
}
} // n0016fc10

// 0016fda8 (from src/anon/batch_w3766.cpp)
namespace n0016fda8 {
struct CEnt { u32 a, b; s32 x8; s32 xc; };
struct CArr { u32 a; s32 n; };
struct CHdr { u8 pad[0x28]; s32 x28; u8 pad2[4]; s32 x30; s32 x34; };
struct CObj {
    u8 state; u8 next; u8 pad[0x26];
    s32 x28;
    u8 pad2c[4];
    CArr* arr;
    u8 pad34[4];
    union { u32* ids; struct { s16 id; s16 res; } s; } u;
};
static inline int ge10k(s32 v) { return v >= 10000; }
CEnt* func_00168b38(CArr*, s32, s32) asm("func_00168b38");
void func_00168be8(s32) asm("func_00168be8");
CHdr* func_0016fac8(s32) asm("func_0016fac8");
void cbh_ctor_0016fba0(CHdr*, u32, s32, s32) asm("_ZN2YS10CACHE_BUFF6HEADERC1EPKcij");
void* cbh_find_00170240(u32, s32) asm("_Z16ctarget_00170240jjjj");
void func_001700e8(void*, s32) asm("func_001700e8");
void func_00170188(CHdr*) asm("func_00170188");
void func_00170178(void) asm("func_00170178");
s16 func_002ba3b8(s16, s32, s32, s32, s32, void (*)(void), CObj*) asm("func_002ba3b8");
void func_0016fda8(CObj* o) asm("func_0016fda8");
void func_0016fda8(CObj* o) {
    switch (o->state) {
    case 0:
        break;
    case 1: {
        if (o->u.s.id < 0) break;
        if (ge10k(o->x28)) break;
        register CArr* a asm("$21") = o->arr;
        register CEnt* e1 asm("$17") = func_00168b38(a, 32, 0);
        if (e1 == 0 || e1->x8 == 0) break;
        CEnt* e2 = func_00168b38(a, 31, 0);
        if (e2 == 0 || e2->x8 == 0) break;
        o->next = 2;
        o->u.s.res = func_002ba3b8(o->u.s.id, e2->x8, e2->xc, e1->x8, e1->xc, func_00170178, o);
        return;
    }
    case 2: {
        register CArr* a asm("$21") = o->arr;
        register s32 n asm("$22") = a->n;
        register u32* p asm("$18") = o->u.ids;
        s32 i;
        for (i = 0; i < n; i++) {
            void* t = cbh_find_00170240(*p, -1);
            if (t) func_001700e8(t, 0);
            CEnt* e = func_00168b38(a, -1, i);
            u32 sz = (e->xc + 0x7ff) & ~0x7ff;
            sz = (sz + 0x7f) & ~0x7f;
            CHdr* nh = func_0016fac8(0x40);
            u32 q = *p++;
            register u32 a3 asm("$7") = sz;
            register CHdr* h asm("$16");
            asm("move %0, %1" : "=r"(h) : "r"(nh), "r"(a3));
            register CHdr* a0r asm("$4");
            asm("move %0, %1" : "=r"(a0r) : "r"(nh), "r"(h));
            register s32 a2r asm("$6");
            asm("li %0, 5300" : "=r"(a2r) : "r"(a0r));
            cbh_ctor_0016fba0(a0r, q, a2r, a3);
            s32 v = e->x8;
            h->x28 = 10000;
            h->x30 = h->x34 = v;
            func_00168be8(e->x8);
            func_00170188(h);
        }
        o->next = 3;
        func_001700e8(o, 0);
        return;
    }
    }
    o->next = 3;
}
} // n0016fda8

// 0016ffc8 (from src/anon/batch_w24.cpp)
namespace n0016ffc8 {
s32 func_0016ffc8(u8* p) asm("func_0016ffc8");
s32 func_0016ffc8(u8* p) {
    s32 v = *(s32*)(p + 40);
    if (v < 0 && *p == 0) {
        s32 id = *(s32*)(p + 56);
        if ((u32)(id - 2300) < 100 || (u32)(id - 2410) < 10 || (u32)(id - 2420) < 10) return id;
    }
    return v;
}
} // n0016ffc8

// 00170018 (from src/anon/batch_w79.cpp)
namespace n00170018 {
extern s32 D_0034dcc0[] asm("D_0034dcc0");
extern s32 D_0034dcc8[] asm("D_0034dcc8");
s32 func_0016ffc8(void*) asm("func_0016ffc8");
static inline bool is_big(s32 id) { return id >= 10000; }
void func_00170018(u8* p) asm("func_00170018");
void func_00170018(u8* p) {
    s32 i = 0;
    s32 id = *(s32*)(p + 40);
    s32 v;
    if (!is_big(id)) {
        for (; i < 2; i++) {
            if (id == D_0034dcc0[i]) { *(s32*)(p + 40) = 29000; return; }
        }
        i = 0;
        v = func_0016ffc8(p);
        *(s32*)(p + 40) = v;
        for (; i < 13; i++) {
            if (v == D_0034dcc8[i]) { *(s32*)(p + 40) = i + 15400; return; }
        }
        if (v >= 0) *(s32*)(p + 40) = v + 10000;
        else *(s32*)(p + 40) = 30000;
    } else if (id < 30000) {
        *(s32*)(p + 40) = id + 50;
    }
}
} // n00170018

// 001700e8 (from src/anon/batch_w44.cpp)
namespace n001700e8 {
void func_0016fb00(void*) asm("func_0016fb00");
struct Node { u8 pad[60]; Node* next; };
struct List { Node* head; Node* tail; };
extern List D_0034dca0 asm("D_0034dca0");
void func_001700e8(Node* n) asm("func_001700e8");
void func_001700e8(Node* n) {
    Node* prev;
    Node* h = D_0034dca0.head;
    if (n == h) {
        D_0034dca0.head = n->next;
        prev = 0;
    } else {
        prev = h;
        while (prev->next != n) prev = prev->next;
        prev->next = n->next;
    }
    if (n == D_0034dca0.tail) D_0034dca0.tail = prev;
    n->next = 0;
    func_0016fb00(n);
}
} // n001700e8

// 00170160, 00170178 (never written before)
namespace n00170160 {
void func_0016fda8(u32) asm("func_0016fda8");
void func_00170160(u32 a0, u32 a1, u32 a2) asm("func_00170160");
void func_00170160(u32 a0, u32 a1, u32 a2) { func_0016fda8(a2); }
void func_00170178(u8* p) asm("func_00170178");
void func_00170178(u8* p) { p[1] = 3; }
} // n00170160

// 00170188 (from src/anon/batch_w1788.cpp)
namespace n00170188 {
struct W1788Node { u8 pad[0x28]; s32 pri; u8 pad2[0x3c - 0x2c]; W1788Node* next; };
struct W1788List { W1788Node* first; W1788Node* last; };
extern W1788List D_0034dca0 asm("D_0034dca0");
static inline __attribute__((always_inline)) void W1788_link(W1788Node* n, W1788Node* prev) {
    if (!prev) {
        if (!D_0034dca0.first) {
            D_0034dca0.last = n;
            D_0034dca0.first = n;
            n->next = 0;
        } else {
            n->next = D_0034dca0.first;
            D_0034dca0.first = n;
        }
    } else if (prev == D_0034dca0.last) {
        prev->next = n;
        n->next = 0;
        D_0034dca0.last = n;
    } else {
        n->next = prev->next;
        prev->next = n;
    }
}
void func_00170188(W1788Node* n) asm("func_00170188");
void func_00170188(W1788Node* n) {
    W1788Node* prev = 0;
    W1788Node* cur;
    while ((cur = prev ? prev->next : D_0034dca0.first) != 0) {
        if (n->pri >= 0) {
            if (n->pri < cur->pri) break;
        } else {
            if (cur->pri < 0 && n->pri < cur->pri) break;
        }
        prev = cur;
    }
    W1788_link(n, prev);
}
} // n00170188

// 00170240 (from src/anon/batch_wcx.cpp)
namespace n00170240 {
extern u8* D_0034dca0 asm("D_0034dca0");
s32 strcmp(u8*, u32) asm("strcmp");
static inline u8* NextA(u8* n) { if (!n) return D_0034dca0; return *(u8**)(n + 60); }
u8* ctarget_00170240(u32, u32, u32, u32) asm("_Z16ctarget_00170240jjjj");
u8* ctarget_00170240(u32 name, u32 id, u32, u32)
{
    u8* n = 0;
    while ((n = NextA(n))) {
        if (strcmp(n + 4, name)) continue;
        if ((s32)id == -1 || id == *(u32*)(n + 40)) return n;
    }
    return 0;
}
} // n00170240

// 001702e0 (from src/anon/batch_w206.cpp)
namespace n001702e0 {
struct M1702e0 { char p0[48]; u32 f48; char p1[8]; M1702e0* next; };
extern M1702e0* D_0034dca0 asm("D_0034dca0");
static inline __attribute__((always_inline)) M1702e0* nxt1702e0(M1702e0* p) {
    if (p == 0) return D_0034dca0;
    return p->next;
}
M1702e0* ctarget_001702e0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16ctarget_001702e0jjjj");
M1702e0* ctarget_001702e0(u32 a0, u32 a1, u32 a2, u32 a3) {
    M1702e0* p = 0;
    while ((p = nxt1702e0(p))) {
        if (p->f48 == a0) return p;
    }
    return 0;
}
} // n001702e0

// 00170320 (from src/anon/batch_w57.cpp)
namespace n00170320 {
void func_00170018(void*) asm("func_00170018");
struct CacheNode { u8 p[40]; s32 v; u8 q[16]; CacheNode* next; };
extern CacheNode* D_0034dca0 asm("D_0034dca0");
static inline CacheNode* CacheNext(CacheNode* n) { if (!n) return D_0034dca0; return n->next; }
void CacheBuffClear(s32 n) asm("_ZN2YS10CACHE_BUFF5ClearEi");
void CacheBuffClear(s32 n) {
    CacheNode* cur = 0;
    while ((cur = CacheNext(cur))) {
        if (n >= 0 ? cur->v >= n : cur->v <= n) func_00170018(cur);
    }
}
} // n00170320

// 001703a8 (from src/anon/batch_w8007.cpp)
namespace n001703a8 {
struct W8007Tgt { u8 pad[0x28]; u32 id; u8 pad2[0x10]; W8007Tgt* next; };
extern W8007Tgt* D_0034dca0 asm("D_0034dca0");
void func_001700e8(W8007Tgt*, s32) asm("func_001700e8");
void w8007_wtarget_001703a8(u32 id) asm("_Z16wtarget_001703a8jjjj");
void w8007_wtarget_001703a8(u32 id) {
    W8007Tgt* n;
    for (W8007Tgt* p = D_0034dca0; __builtin_expect(p != 0, 0); p = n) {
        n = p->next;
        if (p->id == id) func_001700e8(p, 1);
    }
}
} // n001703a8

// 00170400 (from src/anon/batch_w2383.cpp)
namespace n00170400 {
struct W2383CacheEnt { u8 b0; u8 b1; u8 pad[0x26]; s32 f28; s32 f2c; s32 f30; s32 f34; s32 f38; };
extern u8 D_0034dca0[] asm("D_0034dca0");
W2383CacheEnt* w2383_find(u32, u32) asm("_Z16ctarget_00170240jjjj");
s32 w2383_file_size(u32) asm("_ZN2YS4FILE7GetSizeEPKc");
void w2383_header_ctor(W2383CacheEnt*, u32, u32, u32) asm("_ZN2YS10CACHE_BUFF6HEADERC1EPKcij");
void func_0031e328(void*, W2383CacheEnt*) asm("func_0031e328");
W2383CacheEnt* func_0016fac8(u32) asm("func_0016fac8");
void func_00170188(W2383CacheEnt*) asm("func_00170188");
W2383CacheEnt* wtarget_00170400(u32 name, u32 id, u32 size, u32 d) asm("_Z16wtarget_00170400jjjj");
W2383CacheEnt* wtarget_00170400(u32 name, u32 id, u32 size, u32 d)
{
    W2383CacheEnt* p = w2383_find(name, id);
    if (p) { p->b1 = 0; return p; }
    p = w2383_find(name, (u32)-1);
    if (p) {
        bool spare = p->f28 >= 10000;
        if (!spare) {
            if (id == 2301 || id == 5002) p = 0;
            else { p->b1 = 0; return p; }
        } else {
            func_0031e328(D_0034dca0, p);
            p->b1 = 0;
            p->f38 = p->f28;
            p->f28 = id;
        }
    }
    if (!p) {
        if (size == 0) size = (w2383_file_size(name) + 2047) & ~2047;
        size = (size + 127) & ~127;
        W2383CacheEnt* n = func_0016fac8(64);
        w2383_header_ctor(n, name, id, size);
        p = n;
    }
    p->f30 = 0;
    func_00170188(p);
    return p;
}
} // n00170400

// 00170518 (from src/anon/tiny_wrappers_more.cpp)
namespace n00170518 {
u32 func_00170400(u32, u32, u32, u32) asm("func_00170400");
u32 func_00170518(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00170518");
u32 func_00170518(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00170400(a0, a1, a2, a3);
}
} // n00170518

// 00170530 (from src/anon/batch_w17.cpp)
namespace n00170530 {
u8* func_00170400(u32, u32, u32) asm("func_00170400");
u8* func_00170530(u32 a, u32 b, s32 c, u32 d) asm("func_00170530");
u8* func_00170530(u32 a, u32 b, s32 c, u32 d) {
    u8* v = func_00170400(a, b, d);
    *v = 1;
    *(s16*)(v + 56) = c;
    *(s16*)(v + 58) = -1;
    return v;
}
} // n00170530

// 00170570 (from src/anon/tiny_jal_wrappers_flex.cpp)
namespace n00170570 {
u32 func_00170400(u32, u32, u32, u32) asm("func_00170400");
u32 func_00170570(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00170570");
u32 func_00170570(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r5;
    r5 = (u32)((s32)0u + (5300));
    r2 = func_00170400(r4, r5, r6, r7);
    *(u32*)((u32)r2 + (s32)(56)) = r16;
    r15 = (u32)((s32)0u + (2));
    *(u8*)((u32)r2 + (s32)(0)) = (u8)r15;
    return r2;
}
} // n00170570

// 001705a8 (from src/anon/batch_w82.cpp)
namespace n001705a8 {
struct Node0017 { u8 pad[40]; s32 val; u8 pad2[16]; Node0017* next; };
struct Q0017 { Node0017* head; Node0017* tail; };
extern Q0017 D_0034dcb8 asm("D_0034dcb8");
extern struct { Node0017* first; } D_0034dca0 asm("D_0034dca0");
void func_0031e328(void*, Node0017*) asm("func_0031e328");
void func_00170188(Node0017*) asm("func_00170188");
static inline bool Expired0017(Node0017* p) { return !(p->val < 10000); }
static inline Node0017* Step0017(Node0017* c)
{
    Node0017* n = c->next;
    func_00170188(c);
    return n;
}
void func_001705a8(void) asm("func_001705a8");
void func_001705a8(void)
{
    Node0017* p;
    Node0017* n;
    D_0034dcb8.head = 0;
    D_0034dcb8.tail = 0;
    p = D_0034dca0.first;
    if (p) {
        do {
            n = p->next;
            if (Expired0017(p)) {
                func_0031e328(&D_0034dca0, p);
                if (!D_0034dcb8.tail) {
                    D_0034dcb8.tail = p;
                    D_0034dcb8.head = p;
                    p->next = 0;
                } else {
                    D_0034dcb8.tail->next = p;
                    p->next = 0;
                    D_0034dcb8.tail = p;
                }
            }
            p = n;
        } while (n);
    }
    for (p = D_0034dcb8.head; p; ) p = Step0017(p);
}
} // n001705a8

// 00170670 (from src/anon/batch_w273.cpp)
namespace n00170670 {
struct N273 { u8 pad[36]; s32 f36; s32 f40; u32 f44; u32 f48; u8 pad2[8]; N273* next; };
extern u32 D_0034dc9c asm("D_0034dc9c");
extern N273* D_0034dca0 asm("D_0034dca0");
extern u32 D_0034dcb0 asm("D_0034dcb0");
extern u32 D_01c5f460[] asm("D_01c5f460");
extern u8 D_004fa440[] asm("D_004fa440");
void func_001705a8(void) asm("func_001705a8");
s32 func_00170d38(s32) asm("func_00170d38");
void func_001700e8(N273*, s32) asm("func_001700e8");
void func_00170670(void) asm("func_00170670");
void func_00170670(void) {
  u32 a[7];
  s32 i;
  s32 n = 0;
  func_001705a8();
  for (i = 1; i < 7; i++) a[i] = 0;
  a[0] = (u32)D_004fa440;
  u32 lim = D_0034dc9c;
  N273* p = D_0034dca0;
  while (p) {
    s32 t = p->f40;
    p->f36 = 0;
    N273* nx = p->next;
    if (t >= 0) {
      s32 k = func_00170d38(t);
      if (a[k] == 0) {
        a[k] = a[0];
        a[0] += D_01c5f460[k];
      }
      p->f48 = a[k];
      a[k] += p->f44;
      if (a[0] < a[k]) a[0] = a[k];
      u8 big = p->f40 >= 10000;
      if (big) {
        if (lim < a[k] || n >= 128) func_001700e8(p, 0);
      }
    } else {
      lim -= p->f44;
      p->f48 = lim;
    }
    p = nx;
    n++;
  }
  D_0034dcb0 = lim;
}
} // n00170670

// 001707d8 (from src/anon/batch_wcx.cpp)
namespace n001707d8 {
extern u8* D_0034dca0 asm("D_0034dca0");
extern u32 D_0034dcb0 asm("D_0034dcb0");
void func_001700e8(u8*, s32) asm("func_001700e8");
void func_0016fc10(u8*) asm("func_0016fc10");
void func_001707d8(void) asm("func_001707d8");
void func_001707d8(void)
{
    u32 lim = D_0034dcb0;
    u8* n = D_0034dca0;
    while (n) {
        u8* nx = *(u8**)(n + 60);
        if (*(s32*)(n + 40) >= 0 && lim < *(u32*)(n + 48) + *(u32*)(n + 44)) func_001700e8(n, 0);
        else func_0016fc10(n);
        n = nx;
    }
    n = D_0034dca0;
    while (n) {
        u8* nx = *(u8**)(n + 60);
        if (*(u32*)(n + 36) & 2) func_001700e8(n, 0);
        n = nx;
    }
}
} // n001707d8

// 00170888 (from src/anon/auto80_199_queue.cpp)
namespace n00170888 {
void func_00170888(u32 a0) asm("func_00170888");
void func_00170888(u32 a0) {
    u32 s0 = a0;

    if (a0 != 0) {
        func_00170dd0(a0);
    }

    func_00170c50();
    if (func_00170e18() != 0) {
        return;
    }

    func_00170670();
    D_0034dcac = 1;

    if (s0 != 0) {
        func_00170dd0(s0);
    }
}
} // n00170888

// 001708f8 (from src/anon/batch_w28.cpp)
namespace n001708f8 {
u32 cache_buff_alloc(const char*, s32) asm("_ZN2YS10CACHE_BUFF5AllocEPKci");
u8* func_00170240(const char*, s32) asm("func_00170240");
void func_00170e58(void) asm("func_00170e58");
static inline bool cache_header_full(u8* h) { return *(s32*)(h + 0x28) >= 10000; }
u32 cache_buff_alloc(const char* name, s32 n) {
    u8* h = func_00170240(name, n);
    if (h == 0 || cache_header_full(h)) func_00170e58();
    (*(u16*)(h + 2))++;
    return *(u32*)(h + 0x30);
}
} // n001708f8

// 00170950 (from src/anon/tiny_jal_wrappers.cpp)
namespace n00170950 {
u32 func_001702e0(u32, u32, u32, u32) asm("func_001702e0");
u32 func_00170950(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00170950");
u32 func_00170950(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u;
    r2 = func_001702e0(r4, r5, r6, r7);
    r15 = (u32)(*(u16*)((u32)r2 + (s32)(2)));
    r15 = (u32)((s32)r15 + (-1));
    *(u16*)((u32)r2 + (s32)(2)) = (u16)r15;
    return r2;
}
} // n00170950

// 00170978 (from src/anon/auto80_199_queue.cpp)
namespace n00170978 {
u32 func_00170978(u32 a0) asm("func_00170978");
u32 func_00170978(u32 a0) {
    u8* v0 = (u8*)func_00170240(a0, (u32)-1);
    u32 t6 = 0;

    if (v0 != 0) {
        u32 t7 = (u32)(*(s32*)(v0 + 40) < 10000);
        t7 ^= 1;
        if (t7 == 0) {
            u32 t5 = *(u8*)(v0 + 1);
            if (t5 != 3) {
                return 1;
            }

            u16 t7h = *(u16*)(v0 + 2);
            t6 = 2;
            if (t7h != 0) {
                t6 = t5;
            }
        }
    }

    return t6;
}
} // n00170978

// 001709d0 (from src/anon/auto80_199_queue.cpp)
namespace n001709d0 {
void func_001709d0(s32 a0) asm("func_001709d0");
void func_001709d0(s32 a0) {
    s32 s0 = a0;
    u32 a0v = D_0034dca0;

    if (a0v == 0) {
        return;
    }

loop:
    u32 s1 = *(u32*)(a0v + 60);

    if (s0 >= 0) {
        if (*(s32*)(a0v + 40) < s0) {
            goto next;
        }
    } else {
        if (s0 < *(s32*)(a0v + 40)) {
            goto next;
        }
    }

    func_001700e8(a0v, 1);

next:
    if (s1 != 0) {
        a0v = s1;
        goto loop;
    }
}
} // n001709d0

// 00170a50 (from src/anon/tiny_auto80_queue.cpp)
namespace n00170a50 {
u32 func_001700e8(...) asm("func_001700e8");
extern u8 D_0034dca0 asm("D_0034dca0");
void func_00170a50(void) asm("func_00170a50");
void func_00170a50(void) {
    u32 a0 = *(u32*)&D_0034dca0;
    while (a0 != 0u) {
        u32 s0 = *(u32*)((u32)a0 + (s32)(60));
        func_001700e8(a0, 1u);
        a0 = s0;
    }
}
} // n00170a50

// 00170a90 (from src/anon/batch_wcx2.cpp)
namespace n00170a90 {
struct N170a90 { u8 pad0[4]; char name[0x24]; s32 f28; u8 pad2c[0x10]; N170a90* next; };
extern N170a90* D_0034dca0 asm("D_0034dca0");
s32 strcmp(const char*, const char*) asm("strcmp");
void func_001700e8(N170a90*, s32) asm("func_001700e8");
static inline N170a90* Next170a90(N170a90* n) { if (n == 0) return D_0034dca0; return n->next; }
static inline bool Ok170a90(N170a90* n) { return n->f28 >= 10000; }
void func_00170a90(const char* name) asm("func_00170a90");
void func_00170a90(const char* name)
{
    N170a90* n = 0;
    while ((n = Next170a90(n)) != 0) {
        if (strcmp(n->name, name) == 0 && Ok170a90(n)) {
            func_001700e8(n, 1);
            return;
        }
    }
}
} // n00170a90

// 00170b30 (from src/anon/batch_w80.cpp)
namespace n00170b30 {
struct U0_Blk { u8 f0; u8 f1; u8 pad[38]; s32 f40; u32 f44; u32 pad48; u32 f52; u32 pad56; U0_Blk* next; };
extern s32 D_0034dca8 asm("D_0034dca8");
extern u32 D_01c5c440[] asm("D_01c5c440");
extern u32 D_0034dc9c asm("D_0034dc9c");
extern U0_Blk* D_0034dca0 asm("D_0034dca0");
void func_001700e8(U0_Blk*, u32) asm("func_001700e8");
static inline bool func_00170b30_locked(U0_Blk* b) { return b->f40 >= 10000; }
u32 func_00170b30(u32 size) asm("func_00170b30");
u32 func_00170b30(u32 size) {                   
    U0_Blk* b;
    size += 127; size &= ~127;
    D_0034dca8--;
    D_01c5c440[D_0034dca8] = size;
    D_0034dc9c -= size;
    for (b = D_0034dca0; b; ) {
        U0_Blk* next = b->next;
        if (D_0034dc9c < b->f52 + b->f44) {
            if (!func_00170b30_locked(b)) { b->f1 = 0; b->f52 = 0; }
            else func_001700e8(b, 0);
        }
        b = next;
    }
    return D_0034dc9c;
}
} // n00170b30

// 00170c00 (from src/anon/tiny_auto80_solver.cpp)
namespace n00170c00 {
void func_00170c00(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_00170c00");
extern u32 D_0034dca8 asm("D_0034dca8");
extern u32 D_0034dc9c asm("D_0034dc9c");
extern u8 D_01c5c440 asm("D_01c5c440");
void func_00170c00(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_00170c00");
void func_00170c00(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 idx = *(volatile u32*)&D_0034dca8;
    u32* values = (u32*)&D_01c5c440;
    u32 sum = *(volatile u32*)&D_0034dc9c;
    u32 value = values[idx];
    *(volatile u32*)&D_0034dca8 = idx + 1;
    *(volatile u32*)&D_0034dc9c = sum + value;
}
} // n00170c00

// 00170c38 (from src/anon/tiny_auto80.cpp)
namespace n00170c38 {
u32 func_00170c38(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00170c38");
u32 func_00170c38(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)(0x0035u << 16);
    r2 = (u32)(*(volatile u8*)((u32)r15 + (s32)(-9044)));
    r2 = (u32)(r2 & 0x00ffu);
    r2 = (u32)(r2 ^ 0x0001u);
    r2 = ((u32)r2 < 0x00000001u);
    return r2;
}
} // n00170c38

// 00170c50 (from src/anon/batch_w64.cpp)
namespace n00170c50 {
s32 func_00170c38(void) asm("func_00170c38");
extern u8* D_0034dca0 asm("D_0034dca0");
static inline u8* next_70c50(u8* n) {
    if (!n) return D_0034dca0;
    return *(u8**)(n + 60);
}
s32 func_00170c50(void) asm("func_00170c50");
s32 func_00170c50(void) {
    if (func_00170c38()) return 1;
    u8* n = 0;
    while ((n = next_70c50(n))) {
        bool dead = !(*(s32*)(n + 40) < 10000);
        if (dead) continue;
        u8 k = n[1];
        if (!k) continue;
        if (k != 3) return 1;
    }
    return 0;
}
} // n00170c50

// 00170cd0 (from src/anon/batch_w24.cpp)
namespace n00170cd0 {
u8 func_001688b8(void) asm("func_001688b8");
u8 func_002ba200(void) asm("func_002ba200");
u8 func_00170c50(void) asm("func_00170c50");
u8 func_00170cd0(void) asm("func_00170cd0");
u8 func_00170cd0(void) {
    if (func_001688b8() || func_002ba200()) return 1;
    return func_00170c50();
}
} // n00170cd0

// 00170d18 (from src/anon/tiny_jal_wrappers.cpp)
namespace n00170d18 {
u32 func_001702e0(u32, u32, u32, u32) asm("func_001702e0");
u32 func_00170d18(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00170d18");
u32 func_00170d18(u32 a0, u32 a1, u32 a2, u32 a3) {                    
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_001702e0(r4, r5, r6, r7);
    r2 = (u32)((s32)r2 + (56));
    return r2;
}
} // n00170d18

// 00170d38 (from src/anon/batch_w40.cpp)
namespace n00170d38 {
extern s32 D_01c5f478 asm("D_01c5f478");
s32 func_00170d38(s32 x) asm("func_00170d38");
s32 func_00170d38(s32 x) {
    if (x == 1010) return 1;
    if ((u32)(x - 2300) < 100) return 2;
    if ((u32)(x - 2410) < 10) return 3;
    if ((u32)(x - 2420) < 10) return 4;
    if ((u32)(x - 5000) < 100) return 5;
    if ((u32)(x - 5100) < 100 && D_01c5f478 > 0) return 6;
    return 0;
}
} // n00170d38

// 00170db0 (from src/anon/tiny_jal_wrappers.cpp)
namespace n00170db0 {
u32 func_00170240(u32, u32, u32, u32) asm("func_00170240");
u32 func_00170db0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00170db0");
u32 func_00170db0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r5 = (u32)((s32)0u + (-1));
    r2 = func_00170240(r4, r5, r6, r7);
    r2 = *(u32*)((u32)r2 + (s32)(40));
    return r2;
}
} // n00170db0

// 00170dd0 (from src/anon/batch_w25.cpp)
namespace n00170dd0 {
s32 func_00170cd0(void) asm("func_00170cd0");
void func_00102448(void*, u32) asm("func_00102448");
void func_00170dd0(void* a) asm("func_00170dd0");
void func_00170dd0(void* a) {
    while (func_00170cd0()) func_00102448(a, 0);
}
} // n00170dd0

// 00170e18 (from src/anon/auto200_999.cpp)
namespace n00170e18 {
extern u32 D_0034dca0 asm("D_0034dca0");
u32 func_00170e18() asm("func_00170e18");
u32 func_00170e18() {
    register u32 p asm("$14") = D_0034dca0;
    u32 ret = 1;
    if (p != 0) {
        while (1) {
            register s32 v asm("$15") = *(s32 *)(p + 40);
            ret = 0;
            v = v < 10000;
            v ^= 1;
            u32 next = *(u32 *)(p + 60);
            if (v == 0) {
                break;
            }
            p = next;
            if (p != 0) {
                continue;
            }
            ret = 1;
            break;
        }
    }
    return ret;
}
} // n00170e18

// 00170e58 (from src/anon/tiny_auto80_queue.cpp)
namespace n00170e58 {
extern u8 D_0034dca0 asm("D_0034dca0");
void func_00170e58(void) asm("func_00170e58");
void func_00170e58(void) {
    u32 t6 = 0u;
    u32 t5 = *(u32*)((u32)&D_0034dca0 + (s32)(0));
    while (1) {
        u32 t7 = t5;
        if (t6 != 0u) {
            t7 = *(u32*)((u32)t6 + (s32)(60));
        }
        if (t7 == 0u) break;
        t6 = t7;
    }
}
} // n00170e58

// 00170e80 (from src/anon/batch_w42.cpp)
namespace n00170e80 {
struct Node170 { u8 pad[40]; s32 type; s32 size; s32 addr; u8 pad2[8]; Node170* next; };
extern s32 D_0034dc9c asm("D_0034dc9c");
extern Node170* D_0034dca0 asm("D_0034dca0");
extern u8 D_004fa440[] asm("D_004fa440");
s32 func_00170e80(void) asm("func_00170e80");
s32 func_00170e80(void)
{
    s32 end = D_0034dc9c;
    s32 start = (s32)D_004fa440;
    Node170* n = 0;
    while ((n = n ? n->next : D_0034dca0) != 0) {
        bool big = n->type >= 10000;
        if (big) continue;
        if (n->type >= 0) start = n->addr + n->size;
        else end = n->addr;
    }
    return end - start;
}
} // n00170e80

// 00170ee8 (from src/anon/batch_w26.cpp)
namespace n00170ee8 {
struct Pair { u32 a, b; };
extern Pair D_0034dca0 asm("D_0034dca0");
extern Pair D_0034dcb8 asm("D_0034dcb8");
void func_00170ee8(s32 a, s32 b) asm("func_00170ee8");
void func_00170ee8(s32 a, s32 b) {
    if (b == 0xffff && a == 1) {
        D_0034dca0.b = 0;
        D_0034dca0.a = 0;
    }
    if (b == 0xffff && a == 1) {
        D_0034dcb8.b = 0;
        D_0034dcb8.a = 0;
    }
}
} // n00170ee8

// 00170f38 (from src/ys/traps.cpp)
struct BD_VALUE;
namespace n00170f38 {
void func_00170ee8(s32, s32) asm("func_00170ee8");
}
namespace YS {
void trap_sysobj_is_exist(BD_VALUE* bd) {
    (void)bd;
    n00170f38::func_00170ee8(1, 0xffff);
}
}
