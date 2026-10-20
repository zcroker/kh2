#include "../common/types.h"

// Batch w2: small leaf / wrapper functions.

struct Rgb8 { u8 r, g, b; };
extern Rgb8 D_00340ed0;
extern void* D_00348804;
extern u32 D_00349df8;
extern u32 D_00349dfc;
extern s32 D_0034c76c;
extern u8 D_0034c770;
extern u8 D_0034c771;
extern u32 D_0034c774;
extern u32 D_0034c778;
extern u8 D_0034f250[];
extern u8 D_0034fa78[];
extern s32 D_0035eb48;
extern s16 D_0035f090;
extern s16 D_0035f092;
extern s16 D_0035f096;
extern u8* D_0035f21c;
extern u8 D_0035f440[];
extern u8 D_00377b68[];
extern u32 D_01e35980[];
extern f32 D_01c6053c;
extern f32 D_01c60540;
extern u32 D_00349dec;

// BD_VALUE argument block whose first slot points at an object holder.
struct ObjRef { u32 pad0; void* obj; };
struct BdObjFloat { ObjRef* ref; f32 value; };

struct Pair32 { u32 a, b; };
struct Vec16 { u32 x[4]; };
struct Cursor16 { u32 a, b; Vec16* p; };
struct Entry8 { u32 x, y; };
struct Table8 {
    s16 id;
    u8 pad[0x2a];
    Entry8* other;  // 0x2c
    Entry8* self;   // 0x30
};
struct OffsetHolder { u32 pad[3]; u32* offsets; };
struct TRAP;

extern "C" {
void* func_00106178(void* mem, u32 size);
void func_001024b0(void* alloc);
void func_00134730(u32, u32, u32, u32, u32);
u8 func_00141778(void*, u16);
void func_0016aeb8(void* obj, f32 v);
void func_00158870(void* obj, f32 v);
void func_001a2438(u32, u32, u32);
void func_0017dcc0(void*);
void func_00175af8(void*);
s32 func_0018e0d8(TRAP*, s32);
void func_001a49a0(u32, u32, u32);
void func_00195558(void*);
u8* func_001a80c8(s32);  // table24_find_by_id
void func_001b8e88(u32);
void func_001de168(void*, u32, u32, u32, u32, u32);  // scan_list_by_half
void func_001d2690(void*);
void func_0021fbc0(u32);
u16* func_002632d0();
u8 func_001a3888(u16);  // id_in_range_5_7_131
u8 func_00139d78(u8*);
u8* func_002766d0();
void func_0028dac8(u8*, s32);
void func_002b73ac(u32, u32, u32, u32, u32);
void func_001a55a8(u32, u32);
void func_003053c0(u32);
void* func_001050c8();
void func_0023edb0(void*);

// Empty function that still saves ra (clobber forces the frame).
void func_00100338(void) {
    asm volatile("" : : : "$31");
}

// Set the current RGB colour.
void func_0010a7d8(u8 r, u8 g, u8 b) {  // store_triple_bytes
    u8* c = (u8*)&D_00340ed0;
    c[0] = r;
    c[1] = g;
    c[2] = b;
}

// Copy the 16-byte block at src+16 to dst unless they alias.
void func_00134db0(u8* src, u8* dst) {
    src += 16;
    if (dst != src) {
        asm volatile("lq $8, 0(%0)\n\tsq $8, 0(%1)" : : "r"(src), "r"(dst) : "$8", "memory");
    }
}

void func_00134dd0(u32 a0, u32 a1, u32 a2) {
    func_00134730(a2, a1, a0, 0, 0);
}

u8 func_00143448(u16 id) {
    return func_00141778(D_00348804, id);
}

u32 func_0014ca20(void) {
    u32 r = D_00349df8;
    D_00349dfc = 0;
    return r;
}

u32 func_00152598(u32 a0, s32 i, s32 second, Pair32* tbl) {  // pair_get
    if (!second) return tbl[i].a;
    return tbl[i].b;
}

// Clamp to 0..128 and store.
void func_00161a80(s32 v) {
    s32 r;
    if (v >= 0) {
        r = v;
        if (v > 128) r = 128;
    } else {
        r = 0;
    }
    D_0034c76c = r;
}

void func_00161ee8(void) {
    D_0034c770 = 0;
    D_0034c771 = 0;
    D_0034c774 = 0;
    D_0034c778 = 0;
}

void func_00171910(BdObjFloat* a) {
    func_0016aeb8(a->ref->obj, a->value);  // YS::OBJ::set_rot
}

void func_00174d18(BdObjFloat* a) {
    func_00158870(a->ref->obj, a->value);
}

void func_00175108(u32* v) {
    u32 a = v[0];
    func_001a2438(a, v[1], v[2]);
}

void func_0018fb70(u32* v) {
    u32 a = v[0];
    func_001a49a0(a, v[1], v[2]);
}

void func_00195750(void) {
    func_00195558(D_0034f250);
    func_00195558(D_0034fa78);
}

void func_001a91f8(s32* p) {  // obj_init_24bytes
    p[0] = -1;
    p[1] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
}

void func_001b58f0(u8* p, u32 a1, u32 a2, u32 a3) {
    func_001de168(p + 24, a1, a2, 1, 30000, a3);  // scan_list_by_half
}

// Advance the cursor by n 16-byte entries; returns the old position.
Vec16* func_001b7ff8(Cursor16* c, s32 n) {  // bump_field8_alloc
    Vec16* r = c->p;
    c->p = r + n;
    return r;
}

void func_001d1678(s32* p, s32 a1) {  // obj_init_28bytes
    p[4] = a1;
    p[3] = 1;
    p[1] = 0;
    p[6] = 0;
    p[10] = 0;
}

void func_001d2648(s32* p) {  // clear_fields_0_4_32
    p[0] = 0;
    p[1] = 0;
    p[8] = 0;
    func_001d2690(p);
}

void func_001fb698(u32 base, OffsetHolder* h) {
    func_0021fbc0(base + *h->offsets + 160);
}

// VU0 macro: d.xyz = s.xyz.
void func_002226b8(void* d, void* s) {  // vec3_copy
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvmove.xyz $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(d), "r"(s) : "memory");
}

// VU0 square root.
f32 func_00222978(f32 x) {  // vu_sqrt_f12
    f32 v[4] __attribute__((aligned(16)));
    f32 r;
    v[1] = x;
    asm volatile("lqc2 $vf10, 0(%1)\n\tvsqrt Q, $vf10y\n\tvwaitq\n\tcfc2 $2, $vi22\n\tmtc1 $2, %0"
                 : "=f"(r) : "r"(v) : "$2", "memory");
    return r;
}

// Returns 0 (and stores 0) when the value is unset (-1).
s32 func_0023d2e0(s32* out) {  // store_global_test_result
    s32 v = D_0035eb48;
    s32 none = (v == -1);
    *out = none ? 0 : v;
    return none ^ 1;
}

void func_00258d58(s32 a, s32 b, s32 c) {
    D_0035f090 = a;
    D_0035f092 = b;
    D_0035f096 = c;
}

u8 func_00263688(void) {
    return func_001a3888(*func_002632d0());  // id_in_range_5_7_131
}

u8 func_00276f38(void) {
    return func_00139d78(D_0035f21c + 408);
}

Entry8* func_0028ac98(Table8* t, s32 id) {  // lookup_by_index_align
    if (id == t->id) return &t->self[id];
    return &t->other[id];
}

void func_0028dfe8(u32* p) {  // obj_ctor_36f440
    p[14] = 0;
    p[3] = 0;
    p[0] = (u32)D_0035f440;
}

void func_0029df98(void) {
    func_0028dac8(func_002766d0() + 17304, 3);  // Tz::Select::FadeOut(Jiminy seq table, 3)
}

void func_002ba330(u32 a0, u32 a1, u32 a2) {
    func_002b73ac(2, a0, a2, (u32)-1, a1);
}

void func_002e7b10(u32* v) {
    u32 a = v[0];
    func_001a55a8(a, v[1]);
}

typedef void (*VFn3)(void*, u32, u32);
void func_002ead20(void** o, u32 a1) {
    ((VFn3*)*o)[9](o, a1, 43);
}

// VU0 macro: d = a - b.
void func_002f3f10(void* d, void* a, void* b) {  // vec4_sub
    asm volatile("lqc2 $vf4, 0(%0)\n\tlqc2 $vf5, 0(%1)\n\tvsub.xyzw $vf6, $vf4, $vf5\n\tsqc2 $vf6, 0(%2)"
                 : : "r"(a), "r"(b), "r"(d) : "memory");
}

// VU0 macro: d = ftoi0(s).
void func_002f3fd0(void* d, void* s) {  // vec4_ftoi0_trunc
    asm volatile("lqc2 $vf4, 0(%0)\n\tvftoi0.xyzw $vf5, $vf4\n\tsqc2 $vf5, 0(%1)" : : "r"(s), "r"(d) : "memory");
}

// Lower-case to upper-case through the ctype table.
s32 func_002ffbe0(s32 c) {
    if (D_00377b68[c] & 2) c -= 32;
    return c;
}

// EnableIntc followed by sync.l.
void func_003062a0(u32 n) {
    func_003053c0(n);
    asm volatile("sync.l");
}

u32 func_00308200(s32 i) {
    register u32* t asm("$2") = D_01e35980;
    return t[i];
}

typedef void (*VFn1)(void*);
void func_00322968(void** o) {
    ((VFn1*)*o)[5](o);
}
}

// ---- C++ symbols ----
class TASK_MANAGER {
public:
    static void Create(void* mem, u32 size);
};
void TASK_MANAGER::Create(void* mem, u32 size) {
    func_001024b0(func_00106178(mem, size));  // kn::MemoryAllocator::createMemoryAllocator
}

namespace dk {
class Layout {
public:
    void init(void);
};
void Layout::init(void) {
    func_0023edb0(func_001050c8());  // AREA::GetAllocator
}
}  // namespace dk

namespace YS {
struct OBJ;
}  // namespace YS

// YS::OBJ::VTABLE<YS::FRIEND>::pre_exec(YS::OBJ*): common pre-step + PARTY pre_exec.
void friend_pre_exec(YS::OBJ* o) asm("_ZN2YS3OBJ6VTABLEINS_6FRIENDEE8pre_execEPS0_");
void friend_pre_exec(YS::OBJ* o) {
    func_0017dcc0(o);
    func_00175af8(o);  // YS::PARTY::_OVR_pre_exec
}

namespace YS {
// Virtual slot 8 (byte offset 32) of the message object.
typedef void (*MsgFn)(void*);
void method_message_is_end(BD_VALUE* v) {
    void* o = v[0].p;
    (*(MsgFn*)((*(u8**)o) + 32))(o);
}

s32 trap_attack_get_type(BD_VALUE* v) {
    TRAP* t = (TRAP*)v[0].p;
    return func_0018e0d8(t, v[1].i);
}

class ITEM {
public:
    static void GetCommandElem(s32 id);
};
void ITEM::GetCommandElem(s32 id) {
    func_001b8e88(*(u16*)(func_001a80c8(id) + 16));
}
}  // namespace YS

f32 func_001826e0() {  // global_float_diff
    return D_01c6053c - D_01c60540;
}

struct Vec3f { f32 x, y, z; };
void wtarget_001efb18(u32 a0, u32 a1, u32, u32) {
    Vec3f* v = (Vec3f*)(a0 + *(u32*)(*(u32*)(a1 + 12) + 4) + 160);
    f32 z = 0.0f;
    v->x = z;
    v->z = z;
    v->y = z;
}
