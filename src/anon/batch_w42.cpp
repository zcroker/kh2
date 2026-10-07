#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));

extern "C" {

void LoadDataFree(...) asm("_ZN2Tz12LoadDataFreeEz");
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void change_action(void*, s32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
void vm_call(u32, s32, void*, s32) asm("_ZN2YS2VM4callEiP8BD_VALUEi");
void vm_callback(u32, s32, void*, s32, void*) asm("_ZN2YS2VM8callbackEiP8BD_VALUEiPS0_");
u32 vm_start(void*, void*) asm("_ZN2YS2VM5StartEPvPNS_3OBJE");
void btlobj_pre_exec(void*) asm("_ZN2YS6BTLOBJ13_OVR_pre_execEv");
void collision_make(void*, s32, f32, f32) asm("_ZN2YS9COLLISION4makeEiff");
s32 has_ansem_entry(u32) asm("_ZN2Tz6JmInfo13HasAnsemEntryEj");
u8* item_each(void*) asm("_ZN2YS10ITEM_TABLE4EachEPKS0_");
void command_menu_clear(void*) asm("_ZN2YS12COMMAND_MENU5clearEv");
void mission_add_count(s32, s32) asm("_ZN2YS7MISSION8AddCountEii");
u128* effect_color(void*) asm("_ZN3ryj6EFFECT5colorEv");
void wtarget_00239bf8(void*, s32) asm("_Z16wtarget_00239bf8jjjj");
void menu_help_leave(void) asm("_ZN2Tz9CMenuHelp5LeaveEv");
void wtarget_002b7078(void) asm("_Z16wtarget_002b7078jjjj");
u8* oarashi_config(void*) asm("_ZN2Ti9MGOarashi6configEv");
f32 acos_2f8aa0(f32) asm("_ZN3Axa15InnerProductXYZERKNS_8FVECTOR4ES2_");
void lay_file_build_data(void*, void*) asm("_ZN2Tz16LayFileBuildDataEPvj");
void select_begin_leave(void*) asm("_ZN2Tz6Select10BeginLeaveEz");
void select_set_flag(void*, s32) asm("_ZN2Tz6Select7SetFlagEz");

// 00105af8: select a mode and its parameters from a table
extern u32 D_0033cafc;
extern u32 D_0033caf0;
extern u32 D_0033caf4;
extern u32 D_0033cb00[];
void func_00105af8(s32 mode)
{
    D_0033cafc = mode;
    D_0033caf0 = D_0033cb00[mode - 1];
    switch (mode) {
    case 3: D_0033caf4 = D_0033cb00[1]; break;
    case 8: D_0033caf4 = D_0033cb00[0]; break;
    default: D_0033caf4 = D_0033caf0; break;
    }
}

// 00109360: switch to entry `id`, issuing its command pair if both are set
struct Pair109 { u32 a; u32 b; };
extern s32 D_00340eac;
extern Pair109 D_003a8ea0[];
void func_00133c78(u32, u32, u32, u32, u32);
void func_00109360(u32 a0, s32 id)
{
    if (D_00340eac != id) {
        Pair109* e = &D_003a8ea0[id];
        if (e->a && e->b) func_00133c78(a0, e->a, e->b, 0, 0);
        D_00340eac = id;
    }
}

// 0010fea0: common value of three slots, or 0
s32 func_00112720(void*);
s32 func_0010fea0(u8* p)
{
    if (func_00112720(p)) return 0;
    s32* a = (s32*)(p + 3156);
    for (s32 i = 1; i < 3; i++) {
        if (a[0] != a[i]) return 0;
    }
    return a[0];
}

// 001538d8: flag every entry whose id matches
extern u8* D_0034a790;
extern s32 D_0034a77c;
extern u8* D_0034a778;
void func_001538d8(u8 id)
{
    if (!D_0034a790) return;
    s32 n = D_0034a77c;
    for (s32 i = 0; i < n; i++) {
        if (*(u32*)(D_0034a778 + i * 24) == id) D_0034a790[i * 64 + 48] = 1;
    }
}

// 0015def8: allocate (heap vcall with caller address), construct and init the singleton
extern void* D_0034b244;
extern void** D_0034b278;
void func_0031dd50(void*);
void func_0015def8(void)
{
    void** heap = D_0034b278;
    void** o = (void**)((void* (*)(void*, u32, void*))(*(void***)heap)[0])(heap, 4928, __builtin_return_address(0));
    func_0031dd50(o);
    D_0034b244 = o;
    ((void (*)(void*))(*(void***)o)[0])(o);
    ((u8*)D_0034b244)[4] = 1;
}

// 00168958: init a layout node and push it onto the global list
struct L168 { L168* next; u32 f4; u8 lay[40]; u32 f48; u8 pad[16]; u32 f68; u16 pad72; u16 f74; };
struct List168 { L168* head; L168* tail; };
extern List168 D_0034d840;
void func_002ff3fc(void*);
void func_00168958(L168* p, u32 a1, void* data)
{
    p->f48 = a1;
    p->f4 = 0;
    p->f68 = 0;
    p->f74 = 0;
    func_002ff3fc(data);
    lay_file_build_data(p->lay, data);
    if (!D_0034d840.head) {
        D_0034d840.tail = p;
        D_0034d840.head = p;
        p->next = 0;
    } else {
        p->next = D_0034d840.head;
        D_0034d840.head = p;
    }
}

// 0016a158: start a script VM for this object and run its entry
void func_0016a158(u8* self, void* code)
{
    u32 vm = vm_start(code, self);
    *(u32*)(self + 1156) = vm;
    u32 arg = (u32)self;
    vm_callback(vm, 0, &arg, 1, 0);
    vm_call(*(u32*)(self + 1156), 1, 0, 0);
}

// 00170e80: free space between the last allocated block and the next reserved one
struct Node170 { u8 pad[40]; s32 type; s32 size; s32 addr; u8 pad2[8]; Node170* next; };
extern s32 D_0034dc9c;
extern Node170* D_0034dca0;
extern u8 D_004fa440[];
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

// 001739b8: static 16-byte value, copied from the object's data
extern s8 D_01c5f510;
extern u128 D_01c5f520;
extern u8 D_00175548[];
void func_002fd188(void*);
void func_001739b8(u128** out)
{
    if (!D_01c5f510) {
        D_01c5f510 = 1;
        func_002fd188(D_00175548);
    }
    u128* src = (u128*)(*(u8**)((u8*)*out + 4) + 2128);
    u128* dst = &D_01c5f520;
    if (src != dst) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(dst), "r"(src) : "$8", "memory");
    *out = dst;
}

// 0017d160: angle between two vectors (VU0 dot product, clamped acos)
f32 func_0017d160(void* a, void* b)
{
    f32 d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
        : "=f"(d) : "r"(a), "r"(b) : "$8");
    if (1.0f <= d) return 0.0f;
    if (d <= -1.0f) return 3.1415927f;
    return acos_2f8aa0(d);
}

// 00185c48: count down a timer, then run the base pre-exec
s32 func_00188758(void*);
extern f32 D_00349e10;
void func_00185c48(u8* p)
{
    if (func_00188758(p + 768) && !(*(u32*)(p + 924) & 4)) {
        f32* t = (f32*)(p + 2800);
        if (0.0f < *t) {
            *t -= D_00349e10;
            if (*t < 0.0f) *t = 0.0f;
        }
    }
    btlobj_pre_exec(p);
}

// 0018a1b8: next entry after `e` whose bit is in `mask`
struct E20 { u32 a; u8 bit; u8 pad[15]; };
E20* func_0018a1b8(u8* p, u32 mask, E20* e)
{
    E20* end = (E20*)(p + 64) + *(s32*)p;
    e = !e ? (E20*)(p + 64) : e + 1;
    for (; e < end; e++) {
        if (mask & (1 << e->bit)) return e;
    }
    return 0;
}

// 00198970
extern u8* D_0034e948;
void wtarget_00198970(u8* p, u32, u32, u32) asm("_Z16wtarget_00198970jjjj");
void wtarget_00198970(u8* p, u32, u32, u32)
{
    if (*(u32*)(p + 268) & 0x800) {
        u8* o = *(u8**)(D_0034e948 + 2884);
        ((void (*)(void*))(*(void***)o)[6])(o);
        *(s32*)(p + 1160) -= 1;
        *(u32*)(p + 268) &= ~0x800;
    }
}

// 001a3958: first item of a kind that has an Ansem entry; mark it
void func_001a34e0(u32, s32);
u32 func_001a3958(u32 kind)
{
    u8* it = 0;
    while ((it = item_each(it)) != 0) {
        if (it[2] == kind && has_ansem_entry(*(u16*)it) > 0) {
            func_001a34e0(*(u16*)it, 1);
            return *(u16*)it;
        }
    }
    return 0;
}

// 001a8cd0: slot (0-3) holding the given element, or -1
s32 func_001a8bf8(u32, s32);
s32 func_001a8cd0(u32 a0, u32 a1)
{
    s32 k = a1 & 0x1f;
    if (k == 18) return -1;
    for (s32 i = 0; i < 4; i++) {
        if (func_001a8bf8(a0, i) == k) return i;
    }
    return -1;
}

// 001ad020: append an entry at a 4.4 fixed-point position
struct E344 { u8 pad[328]; s32 x; s32 y; u8 pad2[8]; };
void func_001ad020(u8* p, s32 x, s32 y, s32 a3)
{
    E344* e = &((E344*)(p + 1544))[(*(s32*)(p + 2920))++];
    wtarget_00239bf8(e, a3 + 10);
    e->x = (x - 0x7000) >> 4;
    e->y = (y - 0x7300) >> 4;
}

// 001be940
s32 func_001b9d40(u32);
void func_001d6da8(void*);
void func_001bc990(void*, void*);
void func_001be940(u8* p)
{
    if (func_001b9d40(*(u32*)(p + 2528))) func_001d6da8(p + 2642);
    command_menu_clear(p + 848);
    func_001bc990(p + 848, p + 2642);
}

// 001c35a0: for each of 5 groups, record the highest level whose flag is set
extern u8 D_0036dde8[5][5];
void func_001c35a0(u32* bits)
{
    for (s32 i = 0; i < 5; i++) {
        for (s32 j = 4; j >= 0; j--) {
            u8 id = D_0036dde8[i][j];
            if (bits[id >> 5] & (1 << (id & 31))) {
                *(u8*)(i + (u32)bits + 32) = j + 1;
                break;
            }
        }
    }
}

// 001dca70
void func_001e7070(u32, u32);
void func_001e7088(u32, u32);
void func_001dca70(u8* p)
{
    if (*(u32*)(p + 8) & 0x40000) func_001e7070(*(u32*)(p + 48), *(u32*)(p + 52));
    else func_001e7070(0, 0);
    if (*(u32*)(p + 8) & 0x80000) func_001e7088(*(u32*)(p + 48), *(u32*)(p + 52));
    else func_001e7088(0, 0);
}

// 001dcb98: set an effect's colour from 8-bit RGBA (128 = 1.0)
void func_001dcb98(void* fx, u8* rgba)
{
    f32 c[4] __attribute__((aligned(16)));
    for (s32 i = 0; i < 4; i++) c[i] = rgba[i] * 0.0078125f;
    u128* d = effect_color(fx);
    if (d != (u128*)c) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(c) : "$8", "memory");
}

// 001dee10: release the attached object
struct NoTail { ~NoTail() {} };
struct E16 { u8 d[16]; ~E16() {} } __attribute__((aligned(16)));
struct Odee { u8 pad[32]; E16 e[2]; static void operator delete(void* p) asm("func_001e0158"); };
void func_001e01b8(void*);
void func_001dee10(u8* p)
{
    NoTail keep_frame; // forces jal instead of a sibling call
    u32 fl = *(u32*)(p + 92);
    if (fl & 4) delete *(Odee**)(p + 88);
    else if (fl & 8) func_001e01b8(*(void**)(p + 88));
}

// 001e65d0
extern u8 D_00354698[];
extern u32 D_00354648;
extern u32 D_003591c8;
extern u8 D_00354650[];
void func_001e5990(void*);
void func_001e5610(u32);
void func_001e5898(u32);
void func_002f25a0(u32, u32);
void FlushCache(s32);
void func_002f3918(u32, void*);
void func_001e65d0(void)
{
    func_001e5990(D_00354698);
    func_001e5610(D_00354648);
    func_001e5898(D_00354648);
    func_002f25a0(0, 0);
    FlushCache(0);
    func_002f3918(D_003591c8, D_00354650);
}

// 002252b0
extern s32 D_01dad910[2];
s32 func_00225540(void);
void func_00136b78(s32, s32);
void func_002252b0(void)
{
    if (!func_00225540()) return;
    if (D_01dad910[0] != -1) func_00136b78(0, D_01dad910[0]);
    if (D_01dad910[1] != -1) func_00136b78(1, D_01dad910[1]);
}

// 00242418: CRC32 update over a buffer
extern u32* D_0035ecc0;
extern u32 D_0035ecc4;
u32 func_00242418(u8* p, s32 n)
{
    while (--n >= 0) {
        D_0035ecc4 = (D_0035ecc4 << 8) ^ D_0035ecc0[(D_0035ecc4 >> 24) ^ *p++];
    }
    return ~D_0035ecc4;
}

// 00247bb0: update the four active entries
extern u8* D_0035ed34;
void func_00247bb0(void)
{
    for (s32 i = 0; i < 4; i++) {
        if (u_call4_00139d78(D_0035ed34 + i * 408)) {
            u8* o = (u8*)(i * 408 + (u32)D_0035ed34);
            ((void (*)(void*))(*(void***)o)[5])(o);
        }
    }
}

// 00263cc0
extern u8* D_0035f0dc;
extern u8* D_0035f0c0;
u8 func_00263cc0(void)
{
    if (!D_0035f0dc) return 0;
    if (!u_call4_00139d78(D_0035f0c0) && u_call4_00139d78(D_0035f0dc)) menu_help_leave();
    return u_call4_00139d78(D_0035f0dc);
}

// 00264328: index of `id` in the 128-entry table, or -1
u8* func_00263ea8(void);
s32 func_00264328(u32 id)
{
    u8* h = func_00263ea8();
    u16* t = (u16*)(h + *(u32*)(h + 12));
    s32 r = -1;
    for (s32 i = 0; i < 128; i++) {
        if (t[i] == id) { r = i; break; }
    }
    return r;
}

// 0028cf28
extern u8* D_0035f3fc;
void func_0028cf28(s32 i, s32 v)
{
    u8* e = D_0035f3fc + i * 408;
    *(s32*)(e + 396) = v;
    select_begin_leave(e);
    if (*(s32*)(e + 396)) {
        *(s32*)(e + 400) = 0;
        select_begin_leave(e);
        if (*(s32*)(e + 400)) select_set_flag(e, 0);
    }
}

// 0028d008: entry i is active and not masked
extern s32 D_0035f410;
u8 func_0028d008(s32 i)
{
    u8 r = D_0035f3fc ? u_call4_00139d78(D_0035f3fc + i * 408) : 0;
    if (r && ((D_0035f410 >> i) & 1)) r = 0;
    return r;
}

// 002930d8: drop the first element of a global list
union Count293 { s16 n; u32 w; };
union List293 { u32* p; u32 w; };
extern Count293 D_0035f4e0;
extern List293 D_0035f4dc;
void func_002930d8(void)
{
    s16 n = D_0035f4e0.n;
    if (n == 0) return;
    if (n >= 2) {
        for (s32 i = 1; i < D_0035f4e0.n; i++) D_0035f4dc.p[i - 1] = D_0035f4dc.p[i];
    }
    D_0035f4e0.n--;
}

// 00296b08
extern u8 D_0035f590;
extern u8 D_0035f591;
void func_002969e0(void);
void func_00296b80(s32);
void func_00296b08(void)
{
    if (!(D_0035f590 && D_0035f591)) {
        if (!D_0035f590) func_002969e0();
        if (D_0035f590 && !D_0035f591) func_00296b80(1);
    }
}

// 002ba220
s32 func_002b7010(u32, u32, u32, u32, u32, u32);
s32 func_002ba220(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f)
{
    wtarget_002b7078();
    return func_002b7010(a, b, c, d, e, f);
}

// 002bf978: run the handler for every flagged object
u8* func_002be908(void*);
void func_002bf8f0(void*);
void func_002bf978(void)
{
    u8* o = 0;
    while ((o = func_002be908(o)) != 0) {
        if (*(u32*)(o + 1416) & 0x80000000) func_002bf8f0(o);
    }
}

// 002c1860
void func_002c7060(void*);
static inline bool positive(f32 x) { return 0.0f < x; }
void func_002c1860(u32, u8* obj)
{
    u8* s = obj + 2928;
    func_002c7060(s);
    if (!positive(*(f32*)(s + 84))) change_action(obj, 47);
}

// 002d6d10
extern void* D_00361f60;
void func_002d2740(void*, void*, u32, f32, f32);
void* func_002d6d10(void* ret, u32, u32 a2)
{
    void* c = D_00361f60;
    u8* x = oarashi_config(c);
    u8* y = oarashi_config(c);
    func_002d2740(ret, c, a2, *(f32*)(x + 208), *(f32*)(y + 212));
    return ret;
}

// 002dd448: add score (10/5/1 per rank) to the mission counter
struct Score3 { s32 v[3]; };
extern Score3 D_00375dc8;
void func_002dd448(u8* p, s32 mul, s32 idx)
{
    Score3 t = D_00375dc8;
    if (*(s32*)(p + 128) == 2) mission_add_count(t.v[idx] * mul, 0);
}

// 002e95a0: set size and build the collision shape
double func_00313b80(f32);
s32 func_003142e0(double, double);
struct C2e { u8 pad[16]; u8 col[36]; f32 x; f32 y; };
void func_002e95a0(C2e* p, f32 x, f32 y)
{
    p->y = y;
    p->x = x;
    if (func_003142e0(0.0, func_00313b80(y)) < 0) collision_make(p->col, 0, x, y);
    else collision_make(p->col, 3, x, x);
}

// 002ec9d0
void func_0017c4c8(void*, void*);
void func_002eb6f8(void*, s32, f32);
void func_002ec9d0(u8* p, u128* v, s32 n)
{
    u128 tmp;
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&tmp), "r"(v) : "$8", "memory");
    func_0017c4c8(p, &tmp);
    p[1300] = 8;
    func_002eb6f8(p, n, 0.0f);
    *(s32*)(p + 256) = n + 1;
    *(s32*)(p + 260) = n + 2;
}

// 00321728: cache lookup; on miss reuse the entry with the lowest age
struct E4 { u8 a; u8 age; u16 key; };
E4* func_00321728(E4* e, u32 a, u32 k)
{
    E4* best = 0;
    for (s32 i = 0; i < 128; i++, e++) {
        if (e->a == a && e->key == k) return e;
        if (!best || best->age > e->age) best = e;
    }
    best->a = a;
    best->key = k;
    best->age = 0;
    return best;
}

}
