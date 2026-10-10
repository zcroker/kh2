#include "../common/types.h"
extern "C" {
struct Res { u32 f0; u32 f4; u32 data; };
extern void* D_0034ec68;
extern u32 D_0034ec70[19];
extern s8 D_0036c600[8], D_0036c608[8], D_0036c610[8], D_0036c618[8], D_0036c620[8], D_0036c628[8];
void* func_001b1490(void*);
Res* func_00168b38(void*, s32, s32);  // entry_array_find_nth
Res* func_00168b88(void*, s32, s32, s32);  // find_entry16_by_half_word
void func_00196608(u32);
void func_001b87a0(u32);
void func_001c3660(u32);
void func_001c3f48(u32);
void func_001c8e80(u32);
void func_001d58e0(u32);
void func_002c22a8(u32);

static inline u32 TAG(const s8* s) { return s[0] | (s[1] << 8) | (s[2] << 16) | (s[3] << 24); }

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


extern u32 D_0035f200;
s32 func_00289380(u32);
s32 func_00287cd0(void);
s32 func_00287bc0(void);
s32 func_00276368(void);
s32 func_0028acc8(u32);
s32 func_00276888(void);
void func_00287f90(s32);
void func_002a6a18(void);
s32 func_00292630(void);
void func_00287c30(void);
void func_0028af18(u32, s32);
void func_00276690(s32);
s32 func_00276358(void);
void func_00276220(s32, s32);
void func_00274cf0(s32);  // state_dispatch_0_1_2
void func_002925c0(void);
void func_002995e8(void);
s32 func_00289310(u32);
s32 func_00276398(void);  // state_is_150
void func_00275b60(void);
void func_00287c90(s32);
s32 func_00287df0(s32, s32, s32, s32, s32);
s32 func_00242848(s32);
void func_00287da0(void);
s32 func_00288040(void);
void func_00288018(void);  // global_zero_4dwords
void func_0028f6f0(s32);  // record884_refresh_by_index
void func_002a6a10(void);
void func_00276dc0(void);
void func_00287c00(s32);
void func_00287cc0(s32);
s32 func_002891e8(u32);
s32 func_0028b038(u32);
void func_002765e8(s32, s32, s32);

// Menu tick: handles the confirm/cancel states of this page.
void func_002a6be0(void)
{
    s32 sel = func_00289380(D_0035f200);
    s32 st = func_00287cd0();
    func_00287bc0();
    if (st == 2) {
        if (func_00276368() || func_0028acc8(D_0035f200) || func_00276888()) {
            if (sel != -1) {
                func_00287f90(0);
                func_002a6a18();
            }
            return;
        }
        if (func_00292630()) return;
        func_002a6a18();
        func_00287c30();
        s32 k = func_00287bc0();
        func_0028af18(D_0035f200, 115);
        func_00276690(0);
        func_00276220(func_00276358(), 0);
        if (k != 13) return;
        func_00274cf0(13);  // state_dispatch_0_1_2
        func_002925c0();
        func_002995e8();
        return;
    }
    if ((sel != -1 || func_00289310(D_0035f200)) && !func_00276398()) {
        func_00276220(0, 2);
        func_00275b60();
    }
    if (st == 0 && func_00276398()) func_00287c90(1);  // state_is_150
    if (func_00242848(func_00287df0(sel, func_00289310(D_0035f200), 1, 0, 1)) == 0) {
        switch (sel) {
        case -1: break;
        case -4:
            func_00287da0();
            break;
        case -2: {
            func_0028f6f0(0);  // record884_refresh_by_index
            func_002a6a10();
            func_00276dc0();
            func_00276220(1, 1);
            func_00287c00(13);
            func_00287cc0(2);
            s32 a = func_00287bc0();
            s32 b = func_002891e8(D_0035f200);
            func_002765e8(a, b, func_0028b038(D_0035f200));
            break;
        }
        }
    }
    if (func_00288040()) func_00288018();
}


extern u32 D_0035f01c;
extern u32 D_0035f024;
extern u8 D_0035f0f0;
s32 func_002938e0(void);
s32 func_002938f0(void);
void func_0026c140(void);
s32 func_00287dc0(void);
s32 func_0026cda0(void);
s32 func_00139d78(s32);
s32 func_0028f930(s32);
void func_0026cc30(void);
void func_0028b1e8(u32, s32);
void func_0028f7e8(s32);
void func_00257708(s32);
void func_002551b8(void);
void func_0026d828(void);
s32 func_0026d560(void);
void func_0026d5c0(void);
void func_0028fa98(s32);
s32 func_0028afa8(u32);
void func_0026d960(void);
void func_00287bd0(s32, s32);
void func_0026c760(void);
void func_0023d820(s32);
void func_00288e88(u32);
void func_00263c60(void);  // sync_global_index_if_changed
void func_0026cb90(void);

void func_0026c470(void)
{
    s32 sel = func_00289380(D_0035f01c);
    s32 st = func_00287cd0();
    if (st != 2 && func_002938e0() && func_002938f0() && D_0035f0f0) func_0026c140();
    if (func_00287bc0() != 20) return;
    s32 item = func_00287dc0();
    if (st == 2) {
        if (func_0026cda0() || func_00139d78(item) || func_0028f930(0)) {
            if (sel != -1 || func_00289310(D_0035f01c)) {
                func_00287f90(0);
                func_0026cc30();
            }
            return;
        }
        func_0028b1e8(D_0035f024, 0);
        func_00287c30();
        func_0028f7e8(0);
        func_00257708(0);
        func_002551b8();
        func_0026d828();
        return;
    }
    if ((sel != -1 || func_00289310(D_0035f01c)) && !func_0026d560()) {
        func_0026d5c0();
        func_0028fa98(-1);
    }
    if (st == 0 && func_0026d560()) func_00287c90(1);
    s32 n = func_0028afa8(D_0035f01c);
    if (func_00242848(func_00287df0(sel, func_00289310(D_0035f01c), 1, (s32)func_0026d960, 1)) == 0) {
        switch (sel) {
        case -1: break;
        case -4:
            func_00287da0();
            if (func_002938e0() && !func_002938f0()) func_0023d820(item);
            break;
        case -2:
            func_00288e88(D_0035f024);
            func_00263c60();  // sync_global_index_if_changed
            func_0028f6f0(0);  // record884_refresh_by_index
            func_0026cb90();
            func_00287cc0(2);
            func_00287c00(0);
            if (func_002938e0() && !func_002938f0()) func_0023d820(item);
            break;
        default:
            if (sel >= 0 && sel < n) {
                func_00287bd0(22, 0);
                func_0026c760();
            }
            break;
        }
    }
    if (func_00288040()) func_00288018();
}


s32 func_002a6718(void);
void func_002a67a8(void);
void func_002a4df8(void);
void func_002766b0(s32);
void func_002a5590(void);
void func_002a6878(void);
void func_002a4df0(void);

void func_002a52b0(void)
{
    s32 sel = func_00289380(D_0035f200);
    s32 st = func_00287cd0();
    func_00287bc0();
    if (st == 2) {
        if (func_002a6718()) {
            if (sel != -1) {
                func_00287f90(0);
                func_002a67a8();
            }
            return;
        }
        if (func_00292630()) return;
        func_002a4df8();
        func_00287c30();
        s32 k = func_00287bc0();
        func_0028af18(D_0035f200, 115);
        func_00276220(func_00276358(), 0);
        if (k == 13) {
            func_00274cf0(13);  // state_dispatch_0_1_2
            func_002925c0();
            func_002766b0(0);
            func_002995e8();
            return;
        }
        if (k == 38) func_002a5590();
        return;
    }
    if ((sel != -1 || func_00289310(D_0035f200)) && !func_00276398()) {
        func_00276220(0, 2);
        func_00275b60();
    }
    if (st == 0 && func_00276398()) func_00287c90(1);  // state_is_150
    if (func_00242848(func_00287df0(sel, func_00289310(D_0035f200), 1, (s32)func_002a6878, 1)) == 0) {
        switch (sel) {
        case -1: break;
        case -4: {
            s32 a = func_00287bc0();
            s32 b = func_002891e8(D_0035f200);
            func_002765e8(a, b, func_0028b038(D_0035f200));
            func_00287da0();
            break;
        }
        case -2: {
            func_0028f6f0(0);  // record884_refresh_by_index
            func_002a4df0();
            func_00276dc0();
            func_00276220(1, 1);
            func_00287c00(13);
            func_00287cc0(2);
            s32 a = func_00287bc0();
            s32 b = func_002891e8(D_0035f200);
            func_002765e8(a, b, func_0028b038(D_0035f200));
            break;
        }
        default: {
            func_002a4df0();
            func_00276dc0();
            func_00276220(0, 1);
            func_00287c00(38);
            func_00287cc0(2);
            s32 a = func_00287bc0();
            s32 b = func_002891e8(D_0035f200);
            func_002765e8(a, b, func_0028b038(D_0035f200));
            break;
        }
        }
    }
    if (func_00288040()) func_00288018();
}


struct SelState { u32 f0; s8 cur; };
extern SelState* D_0035f5ac;
s32 func_00287c10(void);
void func_0029aac0(s32);
void func_0029b698(void);
void func_0029ecf0(void);
void func_0029aa30(void);
s8 func_0029c9d8(s32);
s32 func_00295430(s32, s32);
void func_0028fb28(s32, s32);

void func_0029b378(void)
{
    s32 sel = func_00289380(D_0035f200);
    s32 st = func_00287cd0();
    func_00287bc0();
    if (st == 2) {
        if (func_00276368() || func_0028acc8(D_0035f200) || func_00276888()) {
            if (sel != -1) {
                func_00287f90(0);
                func_0029aac0(func_00287c10());
            }
            return;
        }
        if (func_00292630()) return;
        func_0029aac0(func_00287c10());
        func_00287c30();
        s32 k = func_00287bc0();
        func_0028af18(D_0035f200, 115);
        func_00276220(func_00276358(), 0);
        if (k == 13) {
            func_00274cf0(13);  // state_dispatch_0_1_2
            func_002925c0();
            func_002766b0(0);
            func_002995e8();
            return;
        }
        if (k == 15) func_0029b698();
        return;
    }
    if ((sel != -1 || func_00289310(D_0035f200)) && !func_00276398()) {
        func_00276220(0, 2);
        func_00275b60();
    }
    if (st == 0 && func_00276398()) func_00287c90(1);  // state_is_150
    if (func_00242848(func_00287df0(sel, func_00289310(D_0035f200), 1, (s32)func_0029ecf0, 1)) == 0) {
        switch (sel) {
        case -1: break;
        case -4:
            func_00287da0();
            break;
        case -2:
            func_0028f6f0(0);  // record884_refresh_by_index
            func_0029aa30();
            func_00276dc0();
            func_00276220(1, 1);
            func_00287c00(13);
            func_00287cc0(2);
            break;
        default: {
            D_0035f5ac->cur = func_0029c9d8(-1);
            func_0028fb28(1, func_00295430(D_0035f5ac->cur, 0));
            func_0029aa30();
            func_00276dc0();
            s32 a = func_00287bc0();
            s32 b = func_002891e8(D_0035f200);
            func_002765e8(a, b, func_0028b038(D_0035f200));
            func_002765e8(15, 0, 0);
            func_00276220(0, 1);
            func_00287c00(15);
            func_00287cc0(2);
            break;
        }
        }
    }
    if (func_00288040()) func_00288018();
}


extern u32 D_0035f64c;
s32 func_00240ba0(void);
s32 func_002b55e0(void);
void func_002b5658(void);
void func_002b5af0(void);
void func_0025dba8(void);
s32 func_002b5490(void);
void func_002b54f8(void);
void func_0025f588(void);
s32 func_00233e70(s32);
s32 func_002348a8(s32, s32);
void func_00234570(s32, s32);
void func_002b4dd0(s32);
void func_002b4c88(s32);
void func_002b5108(s32, s32);
void func_0025f610(void);
void func_002b5558(void);
void func_00240bc0(s32);
s32 func_00241770(s32);
void func_00241450(s32);
void func_00287d20(s32);

void func_0025e8a0(void)
{
    s32 sel = func_00289380(D_0035f64c);
    s32 st = func_00287cd0();
    s32 w = func_00240ba0();
    if (st == 2) {
        if (func_002b55e0()) {
            if (sel != -1 || func_00289310(D_0035f64c)) func_002b5658();
            return;
        }
        func_00287c30();
        s32 k = func_00287bc0();
        func_0028af18(D_0035f64c, 115);
        if (k != 1) return;
        func_002b5af0();
        func_0028f7e8(1);
        func_0025dba8();
        return;
    }
    if ((sel != -1 || func_00289310(D_0035f64c)) && !func_002b5490()) func_002b54f8();
    if (st == 0 && func_002b5490()) {
        func_00287c90(1);
        func_0025f588();
    }
    if (!func_00233e70(0)) {
        if (func_002348a8(w, 0) != 3) {
            func_00234570(w, 0);
        } else {
            func_002b4dd0(-1);
            func_002b4c88(0);
            func_002b5108(0xb85d, w);
            func_00287bd0(5, 0);
            func_00234570(w, 0);
            func_00263c60();  // sync_global_index_if_changed
            return;
        }
    }
    if (func_00242848(func_00287df0(sel, func_00289310(D_0035f64c), 1, (s32)func_0025f610, 1)) == 0) {
        switch (sel) {
        case -1: break;
        case -4:
            func_00263c60();  // sync_global_index_if_changed
            func_00287da0();
            break;
        case -2:
            func_002b5558();
            func_00287c90(1);
            func_00287c00(1);
            func_0028f6f0(1);  // record884_refresh_by_index
            func_00263c60();  // sync_global_index_if_changed
            break;
        default:
            if (sel >= 0 && sel < func_0028afa8(D_0035f64c)) {
                func_00240bc0(sel);
                func_002b4dd0(-1);
                if (func_00241770(sel)) {
                    func_00241450(1);
                    func_002b5108(0x8a91, w);
                    func_00287bd0(18, 0);
                    func_00287d20(50);
                    func_00234570(w, 0);
                }
                func_00263c60();  // sync_global_index_if_changed
            }
            break;
        }
    }
    if (func_00288040()) func_00288018();
}
}
