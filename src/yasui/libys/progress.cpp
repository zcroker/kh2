#include "../../common/types.h"

// YS::PROGRESS (0x180f28-0x181ad0): the story progress flags. Loading 00progress.bin (the per-world
// flag scripts and the progress tables), SetFlag with its flag scripts, the clear/test helpers and the
// "can the player do X" checks. Each function keeps the declarations of the source it was matched in
// (namespace gN); every symbol is bound by asm label.

// ---- .data (0x34ec68)
extern "C" {
void* D_0034ec68 = (void*)"00progress.bin";
u32 D_0034ec70[19] = { 0 };
}

// ---- .rodata: chunk ids in 00progress.bin
extern "C" {
extern const s8 D_0036c600[8] = "dsa";
extern const s8 D_0036c608[8] = "wldf";
extern const s8 D_0036c610[8] = "epsd";
extern const s8 D_0036c618[8] = "wlds";
extern const s8 D_0036c620[8] = "link";
extern const s8 D_0036c628[8] = "wmky";
}

// 180f28: load 00progress.bin
namespace g0 {
struct Res { u32 f0; u32 f4; u32 data; };
extern void* D_0034ec68 asm("D_0034ec68");
extern u32 D_0034ec70[19] asm("D_0034ec70");
extern s8 D_0036c600[8] asm("D_0036c600");
extern s8 D_0036c608[8] asm("D_0036c608");
extern s8 D_0036c610[8] asm("D_0036c610");
extern s8 D_0036c618[8] asm("D_0036c618");
extern s8 D_0036c620[8] asm("D_0036c620");
extern s8 D_0036c628[8] asm("D_0036c628");
void* func_001b1490(void*) asm("func_001b1490");
Res* func_00168b38(void*, s32, s32) asm("func_00168b38");  // entry_array_find_nth
Res* func_00168b88(void*, s32, s32, s32) asm("func_00168b88");  // find_entry16_by_half_word
void func_00196608(u32) asm("func_00196608");
void func_001b87a0(u32) asm("func_001b87a0");
void func_001c3660(u32) asm("func_001c3660");
void func_001c3f48(u32) asm("func_001c3f48");
void func_001c8e80(u32) asm("func_001c8e80");
void func_001d58e0(u32) asm("func_001d58e0");
void func_002c22a8(u32) asm("func_002c22a8");

static inline u32 TAG(const s8* s) { return s[0] | (s[1] << 8) | (s[2] << 16) | (s[3] << 24); }

void func_00180f28(void) asm("func_00180f28");
void func_00180f28(void)
{
    void* h = func_001b1490(D_0034ec68);
    s32 i;
    for (i = 0; i < 19; i++) {
        Res* r = func_00168b38(h, 2, i);  // entry_array_find_nth
        if (!r) D_0034ec70[i] = 0;
        else D_0034ec70[i] = r->data;
    }
    func_00196608(func_00168b88(h, 2, TAG(D_0036c600), 0)->data);
    func_001b87a0(func_00168b88(h, 2, TAG(D_0036c608), 0)->data);
    func_001c3660(func_00168b88(h, 2, TAG(D_0036c610), 0)->data);
    func_001c3f48(func_00168b88(h, 2, TAG(D_0036c618), 0)->data);
    func_001c8e80(func_00168b38(h, 44, 0)->data);
    func_001d58e0(func_00168b88(h, 2, TAG(D_0036c620), 0)->data);
    func_002c22a8(func_00168b88(h, 2, TAG(D_0036c628), 0)->data);
}
}  // namespace g0

// 181178 YS::PROGRESS::SetFlag
namespace g1 {
// Progress-flag script record: opcode, argument count, then the arguments.
struct W3721FlagCmd {
    u8 op;
    u8 n;
    u16 arg[1];
};
// Script table: halfword offsets of each flag's record (shares the flag words' alias set).
union W3721FlagTbl {
    u16 off[1];
    u32 w;
};
// 6-byte per-world entry handed to func_00104cf0 by opcode 1.
struct W3721WorldEnt {
    u16 v[3];
};

extern u32 D_0032d7c0[][8] asm("D_0032d7c0");          // progress flag bits, 32 bytes per world
extern W3721FlagTbl* D_0034ec70[] asm("D_0034ec70");   // per-world flag script tables
extern W3721WorldEnt D_0032bb40[][64] asm("D_0032bb40");

s32 W3721_CheckFlag(s32) asm("_ZN2YS8PROGRESS9CheckFlagEi");
void W3721_SetFlag(s32) asm("_ZN2YS8PROGRESS7SetFlagEi");
void W3721_MenuFlagReset(s32) asm("_ZN2YS8MENUFLAG5ResetEi");
void W3721_ColosseumCheck(void) asm("_ZN2YS12HE_COLOSSEUM5CheckEv");
void func_00104cf0(W3721WorldEnt*, u16*) asm("func_00104cf0");
void func_00196670(u32, u32, u32) asm("func_00196670");
void func_00196698(u32) asm("func_00196698");
void func_001966b0(u32) asm("func_001966b0");
void func_00196710(u32) asm("func_00196710");
void func_001a9140(s32, u32) asm("func_001a9140");
void func_001814b8(u32) asm("func_001814b8");
void func_001a6c90(u32) asm("func_001a6c90");
u8* func_001b6d70(s32) asm("func_001b6d70");
void func_001815d0(s32) asm("func_001815d0");
void func_00181670(void) asm("func_00181670");
void func_001817f0(s32) asm("func_001817f0");
void func_00181778(void) asm("func_00181778");
void func_001d59b0(void) asm("func_001d59b0");
void func_001d5218(s32) asm("func_001d5218");
void func_001b8ce0(s32) asm("func_001b8ce0");
void func_001c0ba0(s32) asm("func_001c0ba0");
void func_0019ef30(void) asm("func_0019ef30");
void func_00196540(s32) asm("func_00196540");
// Sets progress flag `flag` (world = flag >> 10) and runs the flag's script.
void W3721_SetFlag(s32 flag) {
    s32 world = flag >> 10;
    u32 bit = flag & 0x3ff;
    u32* row = D_0032d7c0[world];
    u32* p = &row[bit >> 5];
    *p = *p | (1 << (flag & 0x1f));
    W3721FlagTbl* tbl = D_0034ec70[world];
    W3721FlagCmd* c = (W3721FlagCmd*)((u8*)tbl + tbl->off[bit]);
    while (c->op) {
        u16* a = c->arg;
        s32 i;
        switch (c->op) {
        case 1:
            for (i = 0; i < (c->n >> 2); i++)
                func_00104cf0(&D_0032bb40[world][a[i * 4]], &a[i * 4 + 1]);
            break;
        case 2:
            func_00196670(a[0], a[1], a[2]);
            break;
        case 3:
            func_00196698(a[0]);
            break;
        case 4:
            func_001966b0(a[0]);
            break;
        case 5:
            func_00196710(a[0]);
            break;
        case 6:
            func_001a9140(world, a[0]);
            break;
        case 7:
            for (i = 0; i < c->n; i++) func_001814b8(a[i]);
            break;
        case 8:
            for (i = 0; i < c->n; i++) func_001a6c90(a[i]);
            break;
        case 9:
            for (i = 0; i < c->n; i++) W3721_MenuFlagReset(a[i]);
            break;
        case 12:
            for (i = 0; i < c->n; i++)
                if (!W3721_CheckFlag(a[i])) W3721_SetFlag(a[i]);
            break;
        case 13: {
            u8* p = func_001b6d70(world);
            p[1] = a[0] >> 8;
            p[2] = a[0];
            break;
        }
        }
        c = (W3721FlagCmd*)&c->arg[c->n];
    }
    func_001815d0(flag);
    func_00181670();
    func_001817f0(flag);
    func_00181778();
    func_001d59b0();
    func_001d5218(flag);
    func_001b8ce0(flag);
    func_001c0ba0(flag);
    W3721_ColosseumCheck();
    if (flag == 0x8d0) func_0019ef30();
    func_00196540(flag);
}
}  // namespace g1

// flag pairs checked by 0x1815d0: set `a` when `b` is set (0x36c668)
struct E1815d0 { s32 a; s32 b; };
extern "C" const E1815d0 D_0036c668[5] = {
    { 0x2408, 0x103b }, { 0x2410, 0x2434 }, { 0x2418, 0x2435 }, { 0x2420, 0x2436 }, { 0x2427, 0x2437 },
};

// 1814b8: clear a flag
namespace g2 {
extern u32 D_0032d7c0[][8] asm("D_0032d7c0");

// Clears flag bit `id` (1024 bits per row).
void func_001814b8(s32 id) asm("func_001814b8");
void func_001814b8(s32 id) {
    u32* r = (u32*)((u8*)D_0032d7c0 + (id >> 10) * 32);
    id &= 0x3ff;
    r += (u32)id >> 5;
    *r &= ~(1 << (id & 31));
}
}  // namespace g2

// 181500 YS::PROGRESS::CheckFlag
namespace g3 {
extern u32 D_0032d7c0[][8] asm("D_0032d7c0");

// Story progress flag test (0xffff = none).
u32 progress_CheckFlag(s32 f) asm("_ZN2YS8PROGRESS9CheckFlagEi");
u32 progress_CheckFlag(s32 f) {
    u32 r = 0;
    if (f != 0xffff) {
        u32* row = D_0032d7c0[f >> 10];
        f &= 0x3ff;
        r = (row[(u32)f >> 5] & (1 << (f & 31))) != 0;
    }
    return r;
}
}  // namespace g3

// 181550 YS::PROGRESS::IsSecond
namespace g4 {
u32 func_00181500(u32, u32, u32, u32) asm("_ZN2YS8PROGRESS9CheckFlagEi");

u32 func_00181550(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS8PROGRESS8IsSecondEv");
u32 func_00181550(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r4 = (u32)((s32)0u + (4139));
    u32 (*fp_call4_00181500)(u32, u32, u32, u32) = func_00181500;
    r2 = fp_call4_00181500(r4, r5, r6, r7);
    return r2;
}
}  // namespace g4

// 181570: set flag a when flag b is set
namespace g5 {
s32 func_00181500(void*) asm("_ZN2YS8PROGRESS9CheckFlagEi");
void func_00181178(void*) asm("_ZN2YS8PROGRESS7SetFlagEi");

s32 func_00181570(void* a, void* b) asm("func_00181570");
s32 func_00181570(void* a, void* b) {
    if (!func_00181500(a) && func_00181500(b)) {
        func_00181178(a);
        return 1;
    }
    return 0;
}
}  // namespace g5

// 1815d0
namespace g6 {
struct E1815d0 { s32 a; s32 b; };
extern E1815d0 D_0036c668[] asm("D_0036c668");
void func_001a3458(s32, s32) asm("func_001a3458");
s32 func_001a3570(s32) asm("func_001a3570");
void func_00181570(s32, s32) asm("func_00181570");

void func_001815d0(s32 id) asm("func_001815d0");
void func_001815d0(s32 id) {
    switch (id) {
    case 9225: case 9233: case 9241: case 9249: case 9256:
        func_001a3458(32, 100);
        return;
    }
    if (func_001a3570(32)) {
        E1815d0* e = D_0036c668;
        s32 i;
        for (i = 4; i >= 0; i--, e++) func_00181570(e->a, e->b);
    }
}
}  // namespace g6

// 181670
namespace g7 {
s32 func_00181500(s32) asm("_ZN2YS8PROGRESS9CheckFlagEi");
s32 func_001a3570(s32) asm("func_001a3570");
void func_00181178(s32) asm("_ZN2YS8PROGRESS7SetFlagEi");
extern u8 D_0032f05a asm("D_0032f05a");

void func_00181670(void) asm("func_00181670");
void func_00181670(void) {
    if (!func_00181500(11302)) {
        if (func_00181500(11313) && func_001a3570(87) > 0) func_00181178(11302);
        return;
    }
    if (!func_00181500(11303)) {
        if (func_00181500(11316) && D_0032f05a >= 5) func_00181178(11303);
        return;
    }
    if (!func_00181500(11304)) {
        if (func_00181500(11319) && func_001a3570(87) >= 2) func_00181178(11304);
        return;
    }
    if (!func_00181500(11309)) {
        if (func_00181500(11322) && func_001a3570(23) >= 3) func_00181178(11309);
    }
}
}  // namespace g7

// 181778
namespace g8 {
u32 func_00181550(void) asm("_ZN2YS8PROGRESS8IsSecondEv");
u32 func_00181500(...) asm("_ZN2YS8PROGRESS9CheckFlagEi");
void func_00181178(u32 a0) asm("_ZN2YS8PROGRESS7SetFlagEi");

void func_00181778(void) asm("func_00181778");
void func_00181778(void) {
    if (func_00181550() == 0) {
        return;
    }
    if (func_00181500(6151) != 0) {
        return;
    }
    if (func_00181500(6153) != 0) {
        return;
    }
    if (func_00181500(6178) == 0) {
        return;
    }

    if (func_00181500(6245) != 0) {
        func_00181178(6153);
    } else {
        func_00181178(6151);
    }
}
}  // namespace g8

// flag -> (a, b) handed to func_0019ee80 by 0x1817f0 (0x36c710)
struct E1817 { s32 id; s32 a; s32 b; };
extern "C" const E1817 D_0036c710[14] = {
    { 0x1409, 5, 7 }, { 0x1425, 5, 6 }, { 0x2827, 10, 13 }, { 0x899, 2, 3 }, { 0x899, 2, 4 },
    { 0x899, 2, 6 }, { 0x899, 2, 7 }, { 0x899, 2, 13 }, { 0x3804, 14, 0 }, { 0x380f, 14, 9 },
    { 0x102b, 4, 2 }, { 0x1c25, 7, 3 }, { 0x1415, 5, 4 }, { 0x8df, 2, 8 },
};

// 1817f0
namespace g9 {
struct E1817 { s32 id; s32 a; s32 b; };
extern E1817 D_0036c710[14] asm("D_0036c710");
void func_0019ee80(s32, s32) asm("func_0019ee80");

void func_001817f0(s32 id) asm("func_001817f0");
void func_001817f0(s32 id) {
    for (E1817* e = D_0036c710; (s32)e < (s32)(D_0036c710 + 14); e++) {
        if (e->id == id) func_0019ee80(e->a, e->b);
    }
}
}  // namespace g9

// 181858 .. 181978: the "can" checks
namespace g10 {
u32 func_00181500(...) asm("_ZN2YS8PROGRESS9CheckFlagEi");

u32 func_00181858(void) asm("func_00181858");
u32 func_00181858(void) {
    s32 s0 = (u32)0u;
    if (func_00181500(2071u) == 0u) goto L1;
    if (func_00181500(2076u) == 0u) goto L0;
L1:
    s0 = 1u;
L0:
    return (u32)s0;
}

u32 func_001818a0(void) asm("_ZN2YS8PROGRESS9CanBattleEv");
u32 func_001818a0(void) {
    s32 s0 = (u32)0u;
    if (func_00181500(2071u) == 0u) goto L1;
    if (func_00181500(2081u) == 0u) goto L0;
L1:
    s0 = 1u;
L0:
    return (u32)s0;
}

u32 func_001818e8(void) asm("_ZN2YS8PROGRESS17CanCommandControlEv");
u32 func_001818e8(void) {
    s32 s0 = (u32)0u;
    if (func_00181500(2071u) == 0u) goto L1;
    if (func_00181500(2121u) == 0u) goto L0;
L1:
    s0 = 1u;
L0:
    return (u32)s0;
}
}  // namespace g10

namespace YS {
u32 func_00181500(...) asm("_ZN2YS8PROGRESS9CheckFlagEi");

class PROGRESS {
public:
    static u32 CanOpenCampMenu() asm("_ZN2YS8PROGRESS15CanOpenCampMenuEv");
    static u32 CanDrive() asm("_ZN2YS8PROGRESS8CanDriveEv");
};

u32 PROGRESS::CanOpenCampMenu() {
    s32 s0 = 0u;
    if (func_00181500(2071u) == 0u) goto L1;
    if (func_00181500(2100u) == 0u) goto L0;
L1:
    s0 = 1u;
L0:
    return (u32)s0;
}

u32 PROGRESS::CanDrive() {
    s32 s0 = 0u;
    if (func_00181500(2071u) == 0u) goto L1;
    if (func_00181500(2218u) == 0u) goto L0;
L1:
    s0 = 1u;
L0:
    return (u32)s0;
}
}  // namespace YS

// 1819c0
namespace g11 {
s32 func_00181500(s32) asm("_ZN2YS8PROGRESS9CheckFlagEi");

s32 func_001819c0(void) asm("func_001819c0");
s32 func_001819c0(void) {
    s32 r = 0;
    if (func_00181500(2071) == 0 || func_00181500(5163) != 0 || func_00181500(8193) != 0) r = 1;
    return r;
}

// 181a18
s32 func_00181a18(void) asm("func_00181a18");
s32 func_00181a18(void) {
    s32 r = 0;
    if (!func_00181500(2071) || func_00181500(5163) || func_00181500(8216)) r = 1;
    return r;
}
}  // namespace g11

// 181a70 YS::PROGRESS::IsChapterSora
namespace g12 {
u32 func_00181500(u32, u32, u32, u32) asm("_ZN2YS8PROGRESS9CheckFlagEi");

u32 func_00181a70(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS8PROGRESS13IsChapterSoraEv");
u32 func_00181a70(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r4 = (u32)((s32)0u + (2256));
    u32 (*fp_call4_00181500)(u32, u32, u32, u32) = func_00181500;
    r2 = fp_call4_00181500(r4, r5, r6, r7);
    return r2;
}
}  // namespace g12

// 181a90 YS::TEST_PROGRESS::set_flag
namespace g13 {
void func_00181178(u32) asm("_ZN2YS8PROGRESS7SetFlagEi");
extern u8 D_0032bb30[] asm("D_0032bb30");

void set_flag_impl(void* self, int) asm("_ZN2YS13TEST_PROGRESS8set_flagEi");
void set_flag_impl(void* self, int) {
    func_00181178(0x4848);
    func_00181178(0x4849);
    D_0032bb30[12] = 18;
    D_0032bb30[14] = 99;
    D_0032bb30[13] = 18;
}
}  // namespace g13
