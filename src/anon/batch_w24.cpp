#include "../common/types.h"

// Batch w24: small wrappers, list searches, constructors and leaf helpers.

extern "C" {

// 3x3 determinant of a row-major matrix.
f32 func_0011bd70(f32* m) {
    f32 a = m[4] * m[8] - m[5] * m[7];
    f32 b = m[3] * m[8] - m[5] * m[6];
    f32 c = m[3] * m[7] - m[4] * m[6];
    return m[0] * a - m[1] * b + m[2] * c;
}

void func_001369d0(void);
void func_001369f0(void);
void func_00136a50(void);
extern s32 D_00347d20;
extern s32 D_00347d24;
struct S16x2 { s16 a; s16 b; };
extern S16x2 D_003b8b20;
extern s32 D_003b8b38;
void func_00136968(void) {
    func_001369d0();
    func_001369f0();
    D_003b8b38 = -1;
    D_003b8b20.b = -1;
    D_003b8b20.a = -1;
    D_00347d24 = -1;
    D_00347d20 = -1;
    func_00136a50();
}

// Is node `a` linked into the current manager's list (also records it as current).
struct LNode { u32 _0; LNode* next; };
struct LMgr { u32 _0; LNode* head; u8 _8[92]; volatile u32 cur; };
extern LMgr* volatile D_00347f80;
static inline s32 list_has(LNode** hp, u32 a) {
    LNode* n = 0;
    while ((n = !n ? *(LNode* volatile*)hp : n->next) != 0) {
        if ((u32)n == a) return 1;
    }
    return 0;
}
u8 u_call4_00139d78(u32, u32, u32, u32) asm("_Z16u_call4_00139d78jjjj");
u8 u_call4_00139d78(u32 a, u32, u32, u32) {
    D_00347f80->cur = a;
    return list_has(&D_00347f80->head, a);
}

// Apply func_00167ad0 to both 384-byte slots.
void u_call4_00167b08(u32, u32, u32, u32) asm("_Z16u_call4_00167b08jjjj");
void func_00167ad0(u8*, u32);
extern u8 D_0034d3c0[];
void u_call4_00167b08(u32 a, u32, u32, u32) {
    for (u8* p = D_0034d3c0; (s32)p < (s32)(D_0034d3c0 + 768); p += 384)
        func_00167ad0(p, a);
}

void wtarget_0016d230(u32, u32, u32, u32) asm("_Z16wtarget_0016d230jjjj");
extern u32 D_004f6288;
extern u32 D_0032b91c;
struct W2 { u32 a; u32 b; };
extern W2 D_004f6290;
void wtarget_0016d230(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) D_004f6288 = D_0032b91c;
    if (b == 0xffff && a == 1) {
        D_004f6290.b = 0;
        D_004f6290.a = 0;
    }
}

// Fall back to the id at +56 when it lies in one of the special ranges.
s32 func_0016ffc8(u8* p) {
    s32 v = *(s32*)(p + 40);
    if (v < 0 && *p == 0) {
        s32 id = *(s32*)(p + 56);
        if ((u32)(id - 2300) < 100 || (u32)(id - 2410) < 10 || (u32)(id - 2420) < 10) return id;
    }
    return v;
}

u8 func_001688b8(void);
u8 func_002ba200(void);
u8 func_00170c50(void);
u8 func_00170cd0(void) {
    if (func_001688b8() || func_002ba200()) return 1;
    return func_00170c50();
}

// YS::FORMRAM::set_ability: store an ability id into the first free slot (bit 15 = equipped).
struct FormRam { u8 _0[8]; u16 ab[24]; };
void formram_set_ability(FormRam*, int) asm("_ZN2YS7FORMRAM11set_abilityEi");
void formram_set_ability(FormRam* self, int id) {
    id &= 0x7fff;
    for (s32 i = 0; i < 24; i++) {
        u16 v = self->ab[i];
        if ((v & 0x7fff) == 0) {
            self->ab[i] = (v & 0x8000) | id | 0x8000;
            return;
        }
    }
}

void func_001bff88(void);
void func_001c2b70(void);
void func_00102c18(s32, s32, void (*)(void));
void func_0018d620(void);
extern W2 D_01c60cd8;
extern u8 D_01c60ce0;
void func_0018d738(void) {
    func_001bff88();
    func_001c2b70();
    D_01c60cd8.a = 0;
    D_01c60cd8.b = 0;
    func_00102c18(1, 21000, func_0018d620);
    D_01c60ce0 = 1;
}

void wtarget_00191938(s32, u32, u32, u32) asm("_Z16wtarget_00191938jjjj");
void func_001c1130(s32);  // copy_record_block_to_table
void func_001c11a8(s32);
extern s32 D_01c61958;
void wtarget_00191938(s32 v, u32, u32, u32) {
    switch (v) {
    case 0: func_001c11a8(6); break;
    case 1: case 2: func_001c1130(6); break;
    }
    D_01c61958 = v;
}

s32 func_00197c28(u32*);
void func_00196e88(u32*, s32, s32, f32);
void func_00197390(u32* p) {
    if (func_00197c28(p)) {
        p[13] = 1;
        return;
    }
    p[0] |= 2;
    func_00196e88(p, 4, 0, 0.0f);
}

s32 func_00195700(void*);
extern u8 D_0034f250;
s32 func_0019ab30(s32* p) {
    if (!func_00195700(&D_0034f250)) {
        s32 v = p[7] + 1;
        p[7] = v;
        p[6] = v;
        return 1;
    }
    return 0;
}

s32 func_00181858(u32*);
s32 func_0019d748(u32* p) {
    s32 r = 0;
    if (func_00181858(p)) {
        u32 m = p[8] & 1;
        r = m != 0;
    }
    return r;
}

void func_00239700(u32*);
s32 func_001ab810(void);  // get_global_1c7cec0
s32 func_001ab800(void);
void func_00239988(u32*, s32, s32);
void func_001abb28(u32* p) {
    p[0] = 0;
    func_00239700(p + 5);
    s32 a = func_001ab810();  // get_global_1c7cec0
    s32 b = func_001ab800();
    func_00239988(p + 5, a, b);
}

u8* func_00189200(void*, u32);
void func_001a1cc0(u32, u32, u8);
void func_001a17c8(u32);
extern u8 D_0032e020;
void func_001b6ab8(u32* p) {
    if (p[5]) {
        u8* e = func_00189200(&D_0032e020, p[1]);
        func_001a1cc0(p[5], p[1], e[2]);
        func_001a17c8(p[5]);
        p[5] = 0;
    }
}

void u_tail0_001b87b0(void) asm("_Z16u_tail0_001b87b0v");
void func_001b8838(s32);
void func_001b8da0(void);
struct B288 { u32 w[8]; u8 _20[255]; u8 flag; };
extern B288 D_0032fb68;
void u_tail0_001b87b0(void) {
    B288* b = &D_0032fb68;
    u32* w = b->w;
    for (s32 i = 7; i >= 0;) {
        *w = 0;
        i--;
        // the assembler's R5900 short-loop padding
        asm volatile("nop\n\tnop\n\tnop");
        w++;
    }
    b->flag = 0;
    func_001b8838(0);
    func_001b8da0();
}

// ids 5, 10 and 13..18
s32 func_001bcf38(s32* p) {  // state_in_set_5_10_13to18
    switch (*p) {
    case 5: case 10: case 13: case 14: case 15: case 16: case 17: case 18:
        return 1;
    }
    return 0;
}

struct N80 { u8 _0[80]; N80* next; };
extern N80* D_01d49350;
void func_001c0490(N80*);
void func_001c0560(void) {
    N80* n = 0;
    while ((n = !n ? *(N80* volatile*)&D_01d49350 : n->next) != 0) func_001c0490(n);
}

void func_001c23a8(u32*, u32, s32, s32, s32, u32, u32);
extern void* D_00351d38[];
void func_001c6e58(u32* p, u32 a, u32 b, u32 c) {
    func_001c23a8(p, a, 0, 1, 0, c, b);
    *(void**)p = D_00351d38;
}

// YS::SUMMON::IsTinkExist
u8 summon_IsTinkExist(void) asm("_ZN2YS6SUMMON11IsTinkExistEv");
u32 func_001d6d00(s32);
s32 func_001c8ab0(void);
extern u8 D_0032bb30[];
u8 summon_IsTinkExist(void) {
    u8 r = 0;
    u32 id = func_001d6d00(306);
    if (func_001c8ab0() && D_0032bb30[13605] == id) r = D_0032bb30[13607] != 0;
    return r;
}

u32 func_001e3468(u32);
s32 func_00143fc8(void*, u32);
extern u8 D_00352b00;
s32 func_001dccc8(u32* p, u8 flag) {
    s32 r = 0;
    if (p[2] & 0x1000000) return 0;
    if (flag) r = func_00143fc8(&D_00352b00, func_001e3468(p[7]));
    return r;
}

s32 func_002f1670(void*);
void func_001024a8(u32);
extern u8 D_01dad990;
void func_0022cf18(u32 a) {
    if (!func_002f1670(&D_01dad990)) func_001024a8(a);
}

struct Bits { u32 b0 : 1; u32 m : 2; u32 rest : 29; };
struct Blk { u32 _0; Bits f; };
u8* func_001058e8(void);
void func_00242a90(s32 a) {
    Blk* b = (Blk*)(func_001058e8() + 16800);
    s32 m = 0;
    if (a) m = a == 2 ? 2 : 1;
    b->f.m = m;
}

void func_0026d968(void);
void func_00287bd0(s32, s32);
u32* func_00103eb0(void);
void func_00102818(u32, s32, s32, void (*)(void), s32);
void func_0026dd40(void);
void func_0026dcb8(void) {
    func_0026d968();
    func_00287bd0(0, 0);
    func_00102818(func_00103eb0()[1], 0, 2000, func_0026dd40, 4096);
}

struct Ent8 { u8 _0[2]; s8 flag; u8 _3[2]; s8 lim; u8 _6[2]; };
struct Hdr8 { s16 _0; s16 a; s16 b; u8 _6[6]; Ent8 e[1]; };
extern Hdr8* D_0035f230;
s32 func_0027bf20(s32 i) {
    Hdr8* h = D_0035f230;
    s32 d = h->a - h->b;
    if (d < 0) d = 0;
    if (h->e[i].flag) return 1;
    return !(d < h->e[i].lim);
}

void func_0028dac8(u8*, s32);
extern u8* D_0035f264;
void func_00280240(void) {
    func_0028dac8(D_0035f264 + 24, 9);
    func_0028dac8(D_0035f264 + 460, 12);
    func_0028dac8(D_0035f264 + 896, 3);
}

extern u8 D_01e2a410;
void func_002bc9a8(void*, s32, s32);  // find_entry12_set_field
void func_002bce10(void*, s32);  // find_entry12_set_flag
void func_002b9b78(void) {
    void* o = &D_01e2a410;
    func_002bc9a8(o, 2, 0);  // find_entry12_set_field
    func_002bce10(o, 2);  // find_entry12_set_flag
    func_002bc9a8(o, 3, 999);  // find_entry12_set_field
    func_002bce10(o, 3);  // find_entry12_set_flag
}

void func_00102448(u32, s32);
void func_002ba7c8(u32 a) {
    while (func_002ba200()) func_00102448(a, 0);
}

void func_002baa60(u8*);
u32* func_00168b38(u32, s32, u32);  // entry_array_find_nth
void func_002baa08(u32, u32, s32, s32);
void func_002be568(u8* p, u32 x) {
    func_002baa60(p);
    u32* r = func_00168b38(*(u32*)(p + 104), -1, x);  // entry_array_find_nth
    func_002baa08(r[2], r[3], 16383, 64);
}

// dk::WM_TOTAL_INFO::fadeout
void wm_total_info_fadeout(void*) asm("_ZN2dk13WM_TOTAL_INFO7fadeoutEv");
void func_00138c10(u8*, s32);
void wm_total_info_fadeout(void* self) {
    u8* s = (u8*)self + 192;
    if (*(s32*)(s + 388) != 77) {
        func_00138c10(s, 77);
        *(s32*)(s + 392) = -1;
    }
}

// Clear the vector at q+32, then scale p.xyzw by p.w and zero p.z.
void func_002d5c20(f32*, u8*);
f32* func_002d6e08(f32* p, u32, u8* q) {
    asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(q + 32) : "memory");
    func_002d5c20(p, q);
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(p), "f"(p[3]) : "$8", "memory");
    p[2] = 0;
    return p;
}

void func_002cfeb0(u8*, u32, s32, u32);  // obj_init_field1416_bit800
u8 func_002e7308(u8*);
extern void* D_00362908[];
s32 func_002db858(u8* p, u32 a, u32 b) {
    func_002cfeb0(p, a, 3, b);  // obj_init_field1416_bit800
    *(s32*)(p + 2836) = -1;
    *(void**)p = D_00362908;
    return func_002e7308(p + 2976);
}

void func_00195858(u8*, s32);
void func_002ece98(u32, u8* o) {
    func_00195858(o + 272, 62);
    asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(o + 32) : "memory");
    *(f32*)(o + 240) = *(f32*)(o + 296);
}

// menu::Mode::start
void menu_mode_start(void*) asm("_ZN4menu4Mode5startEv");
u32 func_00102210(void);
void func_00102080(void*);
u8* func_002ee840(void);  // get_data_1e2c088
u32 func_001031b0(void);
void menu_mode_start(void* self) {
    *(u32*)((u8*)self + 44) = func_00102210();
    func_00102080(self);
    u8* s = func_002ee840();  // get_data_1e2c088
    *(u32*)(s + 4) = func_001031b0();
}

struct P2 { u32 a; u32 b; };
struct P3 { P2* p; s32 n; u32 v; };
u32 func_002ff3fc(void);  // strlen
void func_003032d0(u32, P3*);
void func_00316d18(u32 a, u32 b) {
    P3 s;
    P2 x;
    x.a = a;
    u32 v = func_002ff3fc();  // strlen
    s.v = v;
    x.b = v;
    s.p = &x;
    s.n = 1;
    func_003032d0(b, &s);
}

struct VObj { void** vt; };
struct Mgr20 { u8 _0[20]; VObj* o; };
extern Mgr20* D_00347f80m asm("D_00347f80");
extern void* D_00347e60[];
void func_00239870(u8*);
void func_0031a840(u8*);
void func_0031a548(u8* p) {
    *(void**)p = D_00347e60;
    func_00239870(p + 24);
    func_0031a840(p);
    VObj* o = D_00347f80m->o;
    ((void (*)(VObj*, u8*))o->vt[1])(o, p);
}

extern void* D_00348590[];
extern void* D_00347f98[];
void func_0031b070(u8* p) {
    *(void**)p = D_00348590;
    *(void**)(p + 260) = D_00347e60;
    func_00239870(p + 284);
    *(void**)(p + 260) = D_00347f98;
    *(void**)p = D_00347f98;
}

extern void* D_0035eb98[];
void func_0023c098(u8*);  // set_vtbl_36eae8_then_call
void func_002369f0(u8*);  // set_vtbl_36eac8_then_call
void func_0031cd90(u8* p) {
    *(void**)p = D_0035eb98;
    func_0023c098(p + 48);  // set_vtbl_36eae8_then_call
    func_002369f0(p + 24);  // set_vtbl_36eac8_then_call
    *(void**)p = D_00347f98;
}

}
