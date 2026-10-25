#include "../common/types.h"

struct TASK;

extern "C" {

// --- 00104da0
extern u8 D_003a7b00;
extern u32 D_0032b96c;
void func_001052a8(void);
void func_00104a48(void);
void func_00102818(u32, u32, u32, void (*)(void), u32);
void GUMIMENU_CreateThread(int, int, void (*)(TASK*), int) asm("_ZN8GUMIMENU12CreateThreadEiiPFvP4TASKEi");
void GUMIMENU_CreateThread(int, int, void (*)(TASK*), int) {
    D_003a7b00 = 0;
    func_001052a8();
    func_00102818(D_0032b96c, 1, 5000, func_00104a48, 8192);
}

// --- 0010c7f0
void func_0017dbb8(void*);
struct VObj { void (**vt)(VObj*); };
typedef void (*VFn)(void*);
void func_0010c7f0(u8* p) {
    func_0017dbb8(p);
    void* o = *(void**)(p + 2912);
    (*(VFn*)((*(u8**)o) + 20))(o);
}

// --- 0010f9f0
void func_0010f9f0(u8* p, u8* src, u8 flag) {  // obj_set_vec_flag
    u8* dst = p + 3072;
    if (dst != src) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(dst), "r"(src) : "$8", "memory");
    }
    if (flag) *(u32*)(p + 2940) |= 0x80;
    else *(u32*)(p + 2940) &= ~0x80;
}

// --- 00119d08
extern u32 D_003477a0;
void func_00113668(void*);
void func_00105110(void*);
void func_00119d08(void** p) {
    *p = &D_003477a0;
    func_00113668(p);
    func_00105110(p);
}

// --- 00124748
u8* func_00124748(u8* a, s32 n) {  // list_nth_node_rel
    u8* base = *(u8**)(a + 4);
    u8* r = 0;
    for (u32* q = (u32*)(base + 16); *q; q++) {
        r = base + *q;
        if (--n == -1) break;
    }
    return r;
}

// --- 0013f608
f32 func_0017ce10(f32);
void func_0013f608(f32* p) {
    f32 a = p[13];
    p[41] = a;
    p[40] = p[12];
    p[41] = func_0017ce10(a);
}

// --- 0014d910
extern u32 D_00349ef8;
void func_002f25a0(u32, u32);
void func_002f3918(u32, u32);
void func_0014d910(u32 a) {
    func_002f25a0(0, 0);
    func_002f3918(D_00349ef8, a);
}

// --- 00153310
extern u8* D_0034a6f0;
void func_0031cc30(u8*, u32, u32, u32, u32, u32, u32);
void func_00153310(u32 a, u32 b, u32 c, u32 d, u32 e) {
    func_0031cc30(D_0034a6f0 + 24, 1, a, b, c, d, e);
}

// --- 00154b40
u32 func_0013d810(void);
void func_00154450(u32, u32, u32);
void func_00154b40(u32 a, u32 b) {
    func_00154450(func_0013d810(), a, b);
}

// --- 00157068
u32 func_00155f40(void*);
void func_00138c10(void*, u32);
void func_00156408(void*);
void GAUGE_PLAYER_update(u8*) asm("_ZN2dk12GAUGE_PLAYER6updateEv");
void GAUGE_PLAYER_update(u8* self) {
    func_00138c10(self + 11648, func_00155f40(self));
    func_00156408(self);
}

// --- 00168008
extern s32 D_0034d780;
extern u32 D_004f5258[];
void func_00167f38(u32);
void func_00168008(void) {
    func_00167f38(D_004f5258[--D_0034d780]);
}

// --- 00172368
void func_001a0710(u32, void*, f32);
void func_00172368(u32** p) {
    u32 v[4] __attribute__((aligned(16)));
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(v), "r"(p[1]) : "$8", "memory");
    func_001a0710(p[0][1], v, *(f32*)&p[2]);
}

// --- 00173518
// Spawn a task and seed its float parameter.
void func_001734b0(void);
u8* func_00102c18(u32, u32, void (*)(void));
struct T173 { u32 pad; f32 a; f32 b; };
void func_00173518(f32* p) {
    T173* t = (T173*)func_00102c18(1, 14002, func_001734b0);
    t->a = 0;
    t->b = *p;
}

// --- 0017a1c8
void func_001762f8(void*);
void func_00112ab8(u32, void*);
void BTLOBJ_exec_damage(u8*, void*) asm("_ZN2YS6BTLOBJ6VTABLEINS_6PLAYEREE11exec_damageEPS0_PNS_6DAMAGEE");
void BTLOBJ_exec_damage(u8* o, void* dmg) {
    *(u32*)(o + 268) &= ~2;
    func_001762f8(o);
    func_00112ab8(0, dmg);
}

// --- 00192290
u32 func_001921d8(void);
u32 func_001708f8(u32, s32);
void func_00191f78(int, u32);
void MESSAGE_Init(int, int) asm("_ZN2YS7MESSAGE4InitEii");
void MESSAGE_Init(int a, int b) {
    func_00191f78(b, func_001708f8(func_001921d8(), -1));
}

// --- 00192388
// Advance past one message token (control codes < 0x20 have table lengths).
extern u8 D_0036cea0[];
u8* func_00192388(u8* p) {  // skip_control_codes
    u8 c = *p;
    if (c >= 32) {
        p++;
    } else {
        if (c == 0) return 0;
        p += D_0036cea0[c];
    }
    return p;
}

// --- 00195468
s32 ctarget_00195468(u32, u32, u32, u32) asm("_Z16ctarget_00195468jjjj");
s32 ctarget_00195468(u32 a, u32 key, u32, u32) {
    s16* q = (s16*)(a + 8);
    for (s32 i = 0; i < 256; i++) {
        if (q[i] == (s32)key) return i;
    }
    return -1;
}

// --- 001aae28
struct S1aae28 { u32 a, b, c, d; u8 e, f, g, h; u32 j; u32 i; };
void func_001aae28(S1aae28* s, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 j, u32 i) {  // obj_init_from_6args
    s->a = a;
    s->b = b;
    s->c = c;
    s->d = d;
    s->e = e;
    s->f = f;
    s->g = g;
    s->h = h;
    s->j = j;
    s->i = i;
}

// --- 001af328
void* func_001050d8(u32);
void func_001aedf8(void*, u32, u32);
void func_001af328(u32 a) {
    func_001aedf8(func_001050d8(80), a, 2);
}

// --- 001b6d00
extern u8* D_00351184;
extern u32 D_00351214;
void func_00102670(u32, u32);  // to_1025f8
void func_001b6d00(void) {
    if (D_00351184) {
        func_00102670(D_00351214, *(u32*)(D_00351184 + 24));  // to_1025f8
        D_00351184 = 0;
    }
}

// --- 001b8228
extern u8 D_003a99f0[];
extern u8* D_01d48cb8;
extern u8* D_003511bc;
extern u8* D_003511b8;
extern u8 D_003511c2;
void func_001b8228(void) {
    u8* p = D_003a99f0;
    D_003511c2 = 0;
    D_003511bc = p + 16384;
    D_003511b8 = p;
    D_01d48cb8 = p;
}

// --- 001b86e0
// Push an entry's index onto the free list.
struct E20 { u32 w[5]; };
struct G1d48cc8 { E20 e[8]; s32 list[8]; s32 n; };
extern G1d48cc8 D_01d48cc8;
// 001b86e0: moved to src/anon/unit_001b82d8.cpp

// --- 001c0458
// Clear bit o->id in the bitset at bits+4.
void func_001c0458(u8* bits, u8* o) {
    u32 i = *(u32*)(o + 28);
    u32* w = (u32*)(bits + 4);
    w += i >> 5;
    *w &= ~(1 << (i & 31));
}

// --- 001c13e8
void func_001dc920(u32);
u8 func_001db7d0(void*);
u32 func_001c13e8(u32* p) {
    func_001dc920(p[0]);
    func_00105110((void*)p[12]);
    return func_001db7d0(p + 5);
}

// --- 001c1708
// Walk a linked list (next at +36) and process each node.
void func_001c1890(u8*);
void func_001c1708(u8* p) {
    u8* n = *(u8**)(p + 12);
    while (n) {
        u8* nx = *(u8**)(n + 36);
        if (n) func_001c1890(n);
        n = nx;
    }
}

// --- 001d7e78
void func_0019aa00(u32, void*);
void func_001b40e0(void*);
void func_001d7e78(u8* p) {
    u32 o = *(u32*)(p + 2072);
    if (o) func_0019aa00(o, p);
    func_001b40e0(p);
}

// --- 001d9688
// Increment a [n][3] byte counter, capped at 99.
struct R3 { u8 v[3]; };
u8 wtarget_001d9688(R3*, u32, u32, u32) asm("_Z16wtarget_001d9688jjjj");
u8 wtarget_001d9688(R3* a, u32 b, u32 c, u32) {
    if (a[b].v[c] < 99) a[b].v[c]++;
    return a[b].v[c];
}

// --- 001e0f90
extern u32 D_00352bd0;
u32 func_001e0cc8(void*);  // entry64_by_field32
void func_001e26b8(u32, u32);
void func_001e0f90(u8* p) {
    func_001e26b8(D_00352bd0, func_001e0cc8(p));
    *(u32*)(p + 36) = 5;
    *(u32*)(p + 40) = 0;
}

// --- 002247e8
extern s32 D_0035de20;
extern s32 D_0035dad8;
extern s32 D_0035dad4;
void func_002247e8(void) {
    if (D_0035dad8 != D_0035de20) {
        s32 n = D_0035dad4;
        if (n < 5) {
            D_0035dad4 = n + 1;
            D_0035dad8 = D_0035de20;
        }
    }
}

// --- 00227a28
extern u8* D_0035dcf0;
u8* func_00227a28(void) {
    u8* p = D_0035dcf0;
    for (s32 i = 0; i < 128; i++) {
        if (*(u32*)(p + 4) == 0) return p;
        p += 84;
    }
    return 0;
}

// --- 0022be28
void func_00226e60(u32);
void func_001024a8(u32);
void func_0022be28(u32 a) {
    func_00226e60(0);
    func_001024a8(a);
}

// --- 00237508
struct E237 { s32 a, b, c, d, e; };
struct T237 { u32 pad[2]; E237* ent; u16* idx; };
s32 func_00237508(T237* t, s32 i, s32 j) {  // entry20_field8_minus0
    E237* e = &t->ent[t->idx[i * 2] + j];
    return e->c - e->a;
}

// --- 00243150
// Last table entry whose id matches (table ends with a negative id).
struct E243 { s16 id; s16 pad; u32 a, b; };
extern E243 D_00371840[];
E243* func_00243150(s32 id) {
    E243* r = 0;
    for (s32 i = 0; D_00371840[i].id >= 0; i++) {
        if (D_00371840[i].id == id) r = &D_00371840[i];
    }
    return r;
}

// --- 00276c50
// Tz JmReport DrawMessage
u32 func_00192048(u32);
u32 func_00276c88(u32, u8);
u32 JmReport_DrawMessage(s32, u8) asm("_ZN2Tz8JmReport11DrawMessageEjj");
u32 JmReport_DrawMessage(s32 a, u8 b) {
    u32 p = 0;
    if (a >= 0) p = func_00192048(a);
    return func_00276c88(p, b);
}

// --- 002811f8
// Index of the entry with the given id, or -1.
struct E281 { s16 id; s16 pad; u32 x[4]; };
struct T281 { s32 n; E281 e[1]; };
s32 func_002811f8(T281* t, s32 key) {  // find_halfword_index
    s32 i;
    for (i = 0; i < t->n; i++) {
        if (t->e[i].id == key) break;
    }
    if (i < t->n) return i;
    return -1;
}

// --- 0028b750
extern u32 D_0035f3a0;
void func_0023f7e0(void*);
void func_0028b870(void*);
void func_0028b750(void** p) {
    func_0023f7e0(p);
    *p = &D_0035f3a0;
    func_0028b870(p);
}

// --- 002ba8a8
void func_002b7078(u32);
void func_002b72e4(s32, s32, u32);
void func_002baa60(void);
void func_002b83b4(void);
void func_002ba8a8(void) {
    func_002b7078(0);
    func_002b7078(1);
    func_002b72e4(-100, -1, 0);
    func_002baa60();
    func_002b83b4();
}

// --- 002bc358
u32 func_002bbda0(u32);
void func_002bbf68(u32, u32);
void MenuSound_StopBgSeHandle(u32, u32) asm("_ZN2Tz9MenuSound14StopBgSeHandleEz");
void MenuSound_StopBgSeHandle(u32 a, u32 b) {
    u32 h = func_002bbda0(a);
    if (h) func_002bbf68(h, b);
}

// --- 002bca10
struct E2bc { s32 b; s32 a; s32 c; };
s32 func_002bca10(E2bc* t, s32 a, s32 b) {  // table_find_two_words
    E2bc* e = t;
    do {
        if (e->a == a && e->b == b) return b;
        e++;
    } while ((s32)e < (s32)(t + 11));
    return -1;
}

// --- 002dad40
extern u32 D_003627c8;
void func_002cff98(void*);
void func_002dad40(void** p) {
    *p = &D_003627c8;
    func_002cff98(p);
    func_00105110(p);
}

// --- 002dc708
extern u32 D_003629e8;
void func_002e4a90(void*);  // in_even_range
u8 func_002cea28(void*);
u32 func_002dc708(void** p) {
    *p = &D_003629e8;
    func_002e4a90(p + 64);  // in_even_range
    return func_002cea28(p);
}

// --- 002efb60
void func_002efb08(void*);
void func_002efa98(void*);
void func_002efb60(void* p) {
    func_002efb08(p);
    func_002efa98(p);
}

// --- 002f10c0
u32 func_0010c7e8(u32);
void func_0011a938(u32, u32, f32, f32);
struct P2f1 { u32* a; u32 b; f32 x; f32 y; };
void func_002f10c0(P2f1* p) {
    u32 v = func_0010c7e8(p->a[1]);
    u32 b = p->b;
    func_0011a938(v, b, p->x, p->y);
}

// --- 002f1130
u32 func_0010c7b0(u32);
u32 func_00136158(u32, u32);
u32 trap_btlobj_is_reflect_motion(u32**) asm("_ZN2kn29trap_btlobj_is_reflect_motionEP8BD_VALUE");
u32 trap_btlobj_is_reflect_motion(u32** p) {
    return func_00136158(func_0010c7b0(p[0][1]), (u32)p[1]);
}

// --- 0031f4b8
extern u32 D_00350bf0;
void func_001ac5b8(void*);
void func_0031f4b8(void** p) {
    *p = &D_00350bf0;
    func_001ac5b8(p);
    func_00105110(p);
}

// --- 00325408
extern u32 D_003622c0;
void func_002d0f38(void*);
void func_00325408(void** p) {
    *p = &D_003622c0;
    func_002d0f38(p);
    func_00105110(p);
}

}
