#include "../common/types.h"

// 128-bit copy (lq/sq) when the two addresses differ.
static inline void qcopy(void* d, const void* s) {
    if (d != s) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
    }
}

// 16-byte vector copied with lq/sq.
struct W26Quad {
    u8 v[16] __attribute__((aligned(16)));
    W26Quad(const W26Quad& o) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
    }
};
struct W26Head {
    u64 a, b, c, d;
    W26Head(const W26Head& o) {
        u64 x0 = o.a, x1 = o.b, x2 = o.c, x3 = o.d;
        a = x0; b = x1; c = x2; d = x3;
    }
};
struct W26Blk {
    W26Head h;
    W26Quad q[2];
    f32 f;
    W26Blk(const W26Blk& o) : h(o.h), q(o.q), f(o.f) {}
};
inline void* operator new(unsigned int, void* p) { return p; }

extern "C" {
void* func_0010cce0(void*);
s32 obj_is_culling(void*) asm("_ZN2YS3OBJ10is_cullingEv");
void* func_00124748(void*, s32);
void loadImage(u32) asm("_ZN2dk9loadImageEj");
void TaskYield(...) asm("_ZN2Tz9TaskYieldEz");
void SignalCall(void) asm("_ZN2Tz8DbgSMenu10SignalCallEv");
void jumpEffectIn_task(void*) asm("_ZN2dk14StopJumpEffect17jumpEffectIn_taskEP4TASK");
void* ctarget_001b9bc8(void*) asm("_Z16ctarget_001b9bc8jjjj");
void* obj_get_serial(void*) asm("_ZN2YS3OBJ10get_serialEv");
void ctarget_0019ba60(void*) asm("_Z16ctarget_0019ba60jjjj");
void party_use_mp(void*) asm("_ZN2YS5PARTY6use_mpEv");
void* func_001cd7a8(void*);
void target_set_obj(void*, void*, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
void cache_free(void*) asm("_ZN2YS10CACHE_BUFF4FreeEPv");
void func_00192028(s32);
void func_00198dc0(void*);
void func_0019aec0(void*, u8);
s32 func_0017a538(void*);
void* sheet_ctor(void*) asm("_ZN2YS5SHEETC1Ev");
void* func_001db5a8(void*);
void func_001a0ee0(void*, void*);
void func_00239700(void*);
void* func_001ab810(void);
void* font_get_image(void) asm("_ZN2YS4FONT8GetImageEv");
void func_00239988(void*, void*, void*);
s32 obj_is_attach(void*) asm("_ZN2YS3OBJ9is_attachEv");
void* friend_get(s32) asm("_ZN2YS6FRIEND3GetEi");
s32 obj_is_leave(void*) asm("_ZN2YS3OBJ8is_leaveEv");
s32 func_001ca448(void*);
s32 mission_is_exec(void) asm("_ZN2YS7MISSION6IsExecEv");
s32 mission_get_count(s32) asm("_ZN2YS7MISSION8GetCountEi");
void func_00177dc8(void*, void*, s32, void*, void*);
void func_001befd8(void*, void*, s32);
s32 func_001d7f10(s32);
u8 func_002f3f88(void*, void*);
u8* minigame_get_score(s32) asm("_ZN2YS8MINIGAME8GetScoreEi");
s32 jiminy_is_full_open(void) asm("_ZN2Tz6Jiminy10isFullOpenEv");
s32 select_get_current(void*) asm("_ZN2Tz6Select10GetCurrentEv");
s32 menuflag_check(s32) asm("_ZN2YS8MENUFLAG5CheckEi");
void func_001a6c90(s32);
bool u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
bool select_is_created(...) asm("_ZN2Tz6Select9isCreatedEz");
s32 seq_get_loop_mode(void*, s32) asm("_ZN2YI8SEQUENCE11GetLoopModeEi");
u8* jm_get_sram(s32) asm("_ZN2Tz9JmNewInfo7GetSramEv");
u8 func_002bb9b8(void*);
s32 func_002bbc90(void*);
s32 func_002bbbc8(void*);
void area_free(void*) asm("_ZN4AREA4FreeEPv");
void func_0019f9a8(void*);
void func_001c0248(void*);
u8 func_00319fb0(void*);
void func_002e70b0(void*);
void LoadDataFree(...) asm("_ZN2Tz12LoadDataFreeEz");
u8 func_002cea28(void*);
void func_002d0ea8(void*);
s32 func_003060f0(void);
void func_0030ee00(void);
void func_0031cd50(void*);
void ctrl_sel(void) asm("_ZN2Tz4LMMU7CtrlSelEv");
void wtarget_002f3d08(u32, u32, u32, u32) asm("_Z16wtarget_002f3d08jjjj");

extern u8 D_0032b950[];
struct Pair { u32 a, b; };
extern Pair D_0034dca0;
extern Pair D_0034dcb8;
extern u8 D_01c60d10[];
extern void* D_0034e948;
extern void* D_01c61970[];
extern u8 D_01c61b48[];
extern void* D_01d49320;
extern u8 D_003524b8[];
extern u8 D_0036e3a8[];
extern u8* D_003528f8;
extern u8 D_00354bc0[];
extern u8 D_00354be0[];
extern u32 D_0035e370;
extern u32 D_01dae420[3];
extern void (*D_01dae41c)(u32);
extern u32 D_0035e36c;
extern void* D_0035ee34;
extern u8 D_00372438[];
extern void* D_0035f250;
extern void* D_0035f258;
extern void* D_0035f254;
extern u8 D_0035f580;
extern u8 D_0035f581;
extern void* D_0035f57c;
extern u8 D_00361980[];
extern u8 D_003637e0[];
extern u8 D_0034ee08[];
extern u8 D_003625a8[];
extern u8 D_003625e0[];
extern s32 D_003660a8;
extern s32 D_003660ac;
extern u8 D_00347e40[];
extern u8* D_00347f80;

struct Allocator { void* (**vt)(Allocator*, u32, void*); };
struct Obj { void (**vt)(Obj*); };

// Allocates a 288-byte object from the allocator and initialises it.
u32* func_001024b0(Allocator* a) {
    u32* p = (u32*)a->vt[0](a, 288, __builtin_return_address(0));
    p[1] = (u32)a;
    p[68] = 0;
    p[3] = 0;
    p[2] = 0;
    p[4] = 0;
    p[0] = (u32)D_0032b950;
    return p;
}

// Counts objects that are not culled.
s32 func_001182d0(void) {
    s32 n = 0;
    void* p = 0;
    while ((p = func_0010cce0(p)) != 0) {
        if (!obj_is_culling(p)) n++;
    }
    return n;
}

void func_00123d40(void* a, void* b, void* c) {
    void** o = (void**)func_00124748(a, 0);
    ((void (*)(void*, void*, void*))((void**)*o)[4])(o, b, c);
}

void jumpEffectIn_task(void* task) {
    loadImage(216);
    TaskYield(task, 0);
    loadImage(216);
    TaskYield(task, 0);
    SignalCall();
}

void func_00140850(u8* p) {
    qcopy(p + 144, p + 128);
    qcopy(p + 112, p + 96);
    qcopy(p + 176, p + 160);
}

struct Ent28 { u8 flag; u8 id; u8 pad[26]; };
struct EntList { u8 pad[8]; Ent28* ents; u8 pad2[8]; s32 count; };

// Sets the flag of every entry with the given id.
void func_00145c68(EntList* l, u8 id) {
    s32 n = l->count;
    s32 i;
    for (i = 0; i < n; i++) {
        if (l->ents[i].id == id) l->ents[i].flag = 1;
    }
}

// Finds the object with the given serial.
void* func_0016b7a0(void* serial) {
    void* p = 0;
    while ((p = ctarget_001b9bc8(p)) != 0) {
        if (obj_get_serial(p) == serial) return p;
    }
    return p;
}

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

void func_00171848(void** p) {
    if (*p) ctarget_0019ba60(((void**)*p)[1]);
    u8* o = (u8*)((void**)*p)[1];
    if (*(u32*)(o + 1416) & 4) party_use_mp(o);
}

void func_00190a28(void* t, u8* o) {
    void* v = 0;
    if (!(*(u32*)(o + 264) & 0x800)) v = func_001cd7a8(D_01c60d10);
    if (!v) v = D_0034e948;
    target_set_obj(t, v, 0);
}

void func_001922c8(s32 i) {
    void* p = D_01c61970[i * 2];
    if (p) {
        cache_free(p);
        func_00192028(i);
    }
}

void func_00198b88(void) {
    u8* p;
    for (p = D_01c61b48; (s32)p < (s32)(D_01c61b48 + 1408); p += 88) func_00198dc0(p);
}

void func_0019ae60(u8* p) {
    if (p[32] < 200) {
        p[32]++;
        u8* d = *(u8**)(p + 8);
        if (d[35] && p[32] >= d[35]) func_0019aec0(p, d[36]);
    }
}

s32 func_0019bf00(u8* o) {
    if (*(u32*)(o + 1416) & 0x80) {
        if (func_0017a538(o)) return 1;
    }
    u32 m = *(u32*)(o + 264) & 0x100000;
    return m != 0;
}

void* func_001a1018(void* a) {
    void* s = sheet_ctor(a);
    func_001a0ee0(s, func_001db5a8(a));
    return s;
}

void func_001ac028(u8* p) {
    p[0] = 0;
    func_00239700(p + 4);
    void* a = func_001ab810();
    func_00239988(p + 4, a, font_get_image());
}

s32 func_001bbb50(void) {
    void* p = D_01d49320;
    if (!p) return 0;
    switch (*(u8*)(*(u8**)((u8*)p + 8) + 8)) {
    case 2:
    case 25:
    case 32:
        return 1;
    }
    return 0;
}

s32 func_001c0ce8(u8* o) {
    s32 r = 0;
    if (obj_is_attach(o)) {
        u32 m = *(u32*)(*(u8**)(o + 1392) + 1416) & 0x80;
        r = m != 0;
    }
    return r;
}

// Returns 1 if either friend has left.
s32 func_001c9df8(void) {
    s32 i;
    for (i = 0; i < 2; i++) {
        void* f = friend_get(i);
        if (f && obj_is_leave(f)) return 1;
    }
    return 0;
}

s32 func_001cf560(u8* o) {
    s32 r = 0;
    if (func_001ca448(o) || *(s32*)(o + 340) == 44) r = 1;
    return r;
}

s32 func_001cf998(void) {
    s32 r = 0;
    if (!mission_is_exec() || mission_get_count(1) > 0) r = 1;
    return r;
}

void func_001d1540(u8* o, void* a, void* b, void* c) {
    func_00177dc8(o, a, 8, b, c);
    *(u8**)o = D_003524b8;
    *(u32*)(o + 1416) |= 0x4000000;
    func_001befd8(*(void**)(o + 2884), D_0036e3a8, 2);
}

u8* func_001d7ec8(s32 i) {
    if (!func_001d7f10(i)) return 0;
    u8* b = D_003528f8;
    return b + ((u32*)b)[i + 2];
}

struct DEnt { u8 pad[64]; void* val; u8* info; u8 pad2[24]; DEnt* next; };
struct DList { u8 pad[12]; DEnt* head; };

// Returns the value of the entry (optionally of a type) following `prev`.
void* func_001de4b0(DList* l, s32 type, void* prev) {
    s32 found = 0;
    DEnt* e = l->head;
    while (e) {
        DEnt* nx = e->next;
        if (type < 0 || e->info[4] == type) {
            if (!prev || found) return e->val;
            found = e->val == prev;
        }
        e = nx;
    }
    return 0;
}

u8 func_002007e0(u8* p, u8* q) {
    u8* b = p + *(s32*)(*(u8**)(q + 12) + 4);
    func_002f3f88(b + 160, D_00354bc0);
    return func_002f3f88(b + 176, D_00354be0);
}

void func_002349e8(void) {
    D_0035e370 = 0;
    D_01dae420[2] = D_01dae420[1];
    if (D_01dae41c) D_01dae41c(D_0035e36c);
}

s32 func_0024ad50(void) {
    s32 r = 0;
    if (*minigame_get_score(10) >= 2 || jiminy_is_full_open()) r = 1;
    return r;
}

void ctrl_sel(void) {
    s32 f = D_00372438[select_get_current(D_0035ee34)];
    if (!menuflag_check(f)) func_001a6c90(f);
}

bool func_0027f2b0(void) {
    bool r = u_call4_00139d78(D_0035f250);
    if (!r) {
        r = u_call4_00139d78(D_0035f258);
        if (!r) r = select_is_created(D_0035f254);
    }
    return r;
}

s32 func_0028dd90(s32 x) {
    s32 r = 0;
    s32 m = x % 10;
    switch (m) {
    case 0: break;
    case 1: r = 2; break;
    case 2: r = 1; break;
    }
    return r;
}

u8 func_0028e6c0(u8* o, s32 i) {
    u_call4_00139d78(o);
    u8* s = *(u8**)(o + 56) + i * 380;
    return seq_get_loop_mode(s, *(s32*)(s + 276));
}

void func_00294550(void) {
    D_0035f580 = 0;
    D_0035f581 = 0;
    Obj* o = (Obj*)D_0035f57c;
    if (o) {
        o->vt[1](o);
        D_0035f57c = 0;
    }
}

// Sets bit i in the save-data bit array.
void func_002aa450(u32 i) {
    u32* bits = (u32*)(jm_get_sram(i) + 316);
    u32 bit = 1 << (i & 31);
    if (!(bits[i >> 5] & bit)) bits[i >> 5] |= bit;
}

s32 func_002bbd58(u8* o) {
    switch (o[49]) {
    case 5: return func_002bbbc8(o);
    case 6: return func_002bbc90(o);
    }
    return func_002bb9b8(o);
}

void func_002beea8(u8* o) {
    *(u8**)o = D_00361980;
    Obj* c = *(Obj**)(o + 36);
    (*(void (**)(Obj*))((*(u8**)c) + 12))(c);
    *(u8**)o = D_003637e0;
    area_free(o);
}

u8 func_002cff98(u8* o) {
    *(u8**)o = D_0034ee08;
    func_0019f9a8(o + 2568);
    func_001c0248(o + 2640);
    return func_00319fb0(o);
}

u8 func_002d72e0(u8* o) {
    *(u8**)o = D_003625a8;
    void* p = *(void**)(o + 160);
    if (p) {
        func_002e70b0(p);
        LoadDataFree(p);
    }
    return func_002cea28(o);
}

void func_002d96d8(u8* o) {
    func_002d0ea8(o);
    *(u8**)o = D_003625e0;
    *(u32*)(o + 3056) = 0;
    *(u32*)(o + 3060) = 0;
    o[3068] = 1;
    *(u32*)(o + 3072) = 0;
    o[3076] = 1;
    *(u32*)(o + 3216) = 0;
    *(u32*)(o + 3220) = 0;
    *(u32*)(o + 3224) = 0;
}

// Hand-written VU0 routine: transforms four vectors by a 4x4 matrix.
void wtarget_002f3d08(u32 d, u32 m, u32 v, u32 n) {
    asm volatile(
        ".set noreorder\n\t"
        "lqc2 $vf4, 0($5)\n\t"
        "lqc2 $vf5, 16($5)\n\t"
        "lqc2 $vf6, 32($5)\n\t"
        "lqc2 $vf7, 48($5)\n\t"
        "li $7, 4\n"
        "1:\n\t"
        "lqc2 $vf8, 0($6)\n\t"
        "vmulax.xyzw ACC, $vf4, $vf8x\n\t"
        "vmadday.xyzw ACC, $vf5, $vf8y\n\t"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n\t"
        "vmaddw.xyzw $vf9, $vf7, $vf8w\n\t"
        "sqc2 $vf9, 0($4)\n\t"
        "addi $7, $7, -1\n\t"
        "addi $6, $6, 16\n\t"
        "bne $0, $7, 1b\n\t"
        "addi $4, $4, 16\n\t"
        ".set reorder"
        : : : "memory");
}

void func_002fdf30(void) {
    if (func_003060f0() != 1) {
        if (--D_003660a8 == 0) {
            if (D_003660ac) {
                D_003660ac = 0;
                func_0030ee00();
            }
        }
    }
}

void func_0031ca20(u8* o) {
    *(u8**)o = D_00347e40;
    func_0031cd50(o);
    Obj* m = *(Obj**)(D_00347f80 + 20);
    ((void (*)(Obj*, void*))m->vt[1])(m, o);
}

void func_0031ebb0(u8* o) {
    *(u8**)o = D_0034ee08;
    func_0019f9a8(o + 2568);
    func_001c0248(o + 2640);
    func_00319fb0(o);
    area_free(o);
}
// Copy-constructs a block in place.
void func_00323af8(W26Blk* d, const W26Blk* s) {
    new (d) W26Blk(*s);
}
}
