#include "../common/types.h"

// Ti path follow actions (vtables at 0x362ef0/0x362f20 stay retail data) and the Ti path traps
// (0x2e2f08-0x2e3f38; the action method at 0x2e2ed0 before it is not linked yet). Linked unit; trap table .data at 0x362f48, return buffers .bss at 0x1e2be20.


// ---- 2e2f08 (src/anon/batch_wcx2.cpp)
namespace n2e2f08 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define QCOPYN(d, s) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(d), "r"(s) : "$8", "memory")
struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct HeapE;
void* operator new[](unsigned int, HeapE*) asm("func_001063f0");
extern f32 D_00349e10 asm("D_00349e10");
f32 fabsf(f32) asm("fabsf");
static inline void vu_Scale11(Vec4* s, Vec4* d, f32 f)
{
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
                 : : "r"(s), "r"(d), "f"(f) : "$8", "memory");
}
static inline void vu_Interp11(Vec4* a, Vec4* b, Vec4* d, f32 t)
{
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\t"
                 "vaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\t"
                 "vmulax.xyzw ACC, $vf2, $vf3x\n\tvmaddx.xyzw $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(a), "r"(b), "r"(d), "f"(t) : "$8", "memory");
}
static inline void vu_Copy11(Vec4* d, Vec4* s)
{
    if (d != s) QCOPYN(d, s);
}
struct Obj11 { u8 pad[16]; Vec4 dir; Vec4 pos; };
u32 func_00184540(u32 out, u32 a1, f32 t, f32 s) asm("_Z13func_00184540jjff");
u32 func_00184540(u32 out, u32 a1, f32 t, f32 s) asm("func_00184540");
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14;
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
f32 fabsf(f32) asm("fabsf");
extern f32 D_00349e10 asm("D_00349e10");
extern f32 D_00349e10 asm("D_00349e10");
f32 fabsf(f32 x) asm("fabsf");
f32 fabsf(f32 x) asm("fabsf");
f32 fabsf(f32 x) asm("fabsf");
extern u8* D_00361f60 asm("D_00361f60");
extern f32 D_00349e10 asm("D_00349e10");
extern f32 D_00349e10 asm("D_00349e10");
extern f32 D_00349e10 asm("D_00349e10");
extern f32 D_00349e10 asm("D_00349e10");
struct V2e2f08 {
    f32 x, y, z, w;
    V2e2f08() {}
    V2e2f08(const V2e2f08& o) { if (this != &o) QCOPY(this, &o); }
    V2e2f08& operator=(const V2e2f08& o) { if (this != &o) QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
static inline V2e2f08 Mul2e2f08(const f32* m, const V2e2f08& v)
{
    V2e2f08 r;
    asm volatile("lqc2 $vf5,0(%2)\n\tlqc2 $vf1,0(%1)\n\tlqc2 $vf2,16(%1)\n\tlqc2 $vf3,32(%1)\n\tlqc2 $vf4,48(%1)\n\t"
                 "vmulax.wxyz ACC,$vf1,$vf5x\n\tvmadday.wxyz ACC,$vf2,$vf5y\n\tvmaddaz.wxyz ACC,$vf3,$vf5z\n\t"
                 "vmaddw.wxyz $vf5,$vf4,$vf5w\n\tsqc2 $vf5,0(%0)"
                 : : "r"(&r), "r"(m), "r"(&v) : "memory");
    return r;
}
V2e2f08 func_00184540__2e2f08(u32, f32, f32) asm("func_00184540");
f32* func_002e2930__2e2f08(u32) asm("func_002e2930");
extern u32 D_00361f60__2e2f08 asm("D_00361f60");
extern "C" V2e2f08 func_002e2f08(u32 self, u32 a)
{
    V2e2f08 v = func_00184540__2e2f08(a, 0.8f, 0.8f);
    f32* m = func_002e2930__2e2f08(D_00361f60__2e2f08);
    v.w = 0.0f;
    v = Mul2e2f08(m, v);
    return v;
}
}

// ---- 2e2f90
// ---- 2e2f90 (src/anon/batch_w1618_g.cpp)
namespace n2e2f90 {
struct W1618V4 {
    f32 x, y, z, w;
    W1618V4() {}
    W1618V4(const W1618V4& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1618V4& operator=(const W1618V4& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1618M4 {
    W1618V4 r[4];
    W1618M4() {}
    W1618M4(const W1618M4& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    // In-place inverse of a rigid (rotation + translation) matrix.
    void invOrtho() {
        asm volatile("lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)" : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
    W1618V4 operator*(const W1618V4& v) const {
        W1618V4 o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct W1618MG;
struct W1618Ob;
extern W1618MG* D_00361f60 asm("D_00361f60");
extern f32 D_00362e78 asm("D_00362e78");
s32 W1618_IsExec(void) asm("_ZN2YS5EVENT6IsExecEv");
s32 W1618_be_ready(void) asm("_ZN2Ti8MiniGame8be_readyEv");
W1618M4* func_002e2930(W1618MG*) asm("func_002e2930");
W1618M4* func_002e2920(W1618MG*) asm("func_002e2920");
W1618V4* func_0016c028(W1618Ob*) asm("func_0016c028");
void W1618_set_pos(W1618Ob*, const W1618V4&) asm("_ZN2YS3OBJ7set_posERKN2kn7FVectorE");
void W1618_set_dir(W1618Ob*, const W1618V4&) asm("_ZN2YS3OBJ7set_dirERKN2kn7FVectorE");
extern "C" void func_002e2f90(u32 self, W1618Ob* o) {
    if (W1618_IsExec()) return;
    W1618MG* mg = D_00361f60;
    if (!W1618_be_ready()) return;
    W1618M4 a(*func_002e2930(mg));
    W1618M4 b(*func_002e2920(mg));
    b.invOrtho();
    W1618V4 p = b * *func_0016c028(o);
    p.z = D_00362e78;
    W1618V4 q = a * p;
    W1618M4 c(a);
    c.invOrtho();
    W1618V4 r = c * q;
    q = a * r;
    W1618_set_pos(o, q);
    W1618_set_dir(o, a.r[2]);
}
}


// ---- 2e31f0 (src/anon/batch_w47.cpp)
namespace n2e31f0 {
struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));
Vec4* func_0016c028(void*) asm("func_0016c028");
s32 func_002ceb28(u32, u8*) asm("func_002ceb28");
extern void* D_0034e948 asm("D_0034e948");
void func_0016ace0(u8*, Vec4*) asm("func_0016ace0");
void func_0016aeb8(u8*, f32) asm("func_0016aeb8");
extern "C" void func_002e31f0(u32 a, u8* b) {
    if (!func_002ceb28(a, b)) return;
    func_0016ace0(b, func_0016c028(D_0034e948));
    func_0016aeb8(b, 3.1415927f);
}
}

// ---- 2e3250
struct ZV2e3250 { f32 x, y, z, w; } __attribute__((aligned(16)));
ZV2e3250 act_2e3250(void* self) {
    ZV2e3250 r;
    asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(&r) : "memory");
    return r;
}

// ---- 2e3260 (src/anon/batch_w43.cpp)
namespace n2e3260 {
struct Ent32 { u32 key; u16 id; u8 pad[26]; };
extern "C" Ent32* func_002e3260(u8* p, u32 key, u32 id) {
    s32 n = *(s32*)(p + 8);
    Ent32* e = (Ent32*)(p + 16);
    for (s32 i = 0; i < n; i++, e++) {
        if (!key || !e->key || ((e->key & 0xffff0000) == (key & 0xffff0000) && e->id == id)) return e;
    }
    return 0;
}
}

// ---- 2e32c0
struct Hd2e32c0 { u8 c0; u8 c1; u16 n; u32 it[1]; };
Hd2e32c0* find_2e32c0(u8* p, u32 c0, u32 c1) {
    s32 n = *(s32*)(p + 8);
    if (!n) return 0;
    Hd2e32c0* h = (Hd2e32c0*)(p + 16);
    for (s32 i = 0; i < n; i++) {
        if (h->c0 == c0 && h->c1 == c1) return h;
        h = (Hd2e32c0*)((u8*)h + h->n * 8 + 4);
    }
    return 0;
}

// ---- 2e3318 (src/anon/batch_w91.cpp)
namespace n2e3318 {
struct It8 { u16 key; u16 pad; u32 val; };
struct Hd8 { u8 c0; u8 c1; u16 n:16; It8 it[1]; };
extern "C" s32 func_002e3318(u8* p, u32* out, s32 max, u32 key, u32 c0, u32 c1) {
    s32 n = 0;
    if (*(s32*)(p + 8) == 0) return 0;
    Hd8* h = (Hd8*)(p + 16);
    for (s32 i = 0; i < *(s32*)(p + 8); i++) {
        if (h->c0 == c0 && h->c1 == c1) {
            for (s32 j = 0; j < h->n; j++) {
                It8* it = &h->it[j];
                if (it->key == key && n < max) out[n++] = it->val;
            }
        }
        h = (Hd8*)((u8*)h + h->n * 8 + 4);
    }
    return n;
}
}

// ---- 2e33d8
s32 wtarget_002e3418(u8*, u32, u32, u32) asm("_Z16wtarget_002e3418jjjj");
extern "C" s32 func_002e33d8(u8* p, u32 a, u32 b) {
    return wtarget_002e3418(p, a, 1, b);
}
extern "C" s32 func_002e33f8(u8* p, u32 a, u32 b) {
    return wtarget_002e3418(p, a, 2, b);
}

// ---- 2e3418 (src/anon/batch_w55.cpp)
namespace n2e3418 {
struct PairW55 { u16 a; u16 x; u16 b; u16 v; };
struct SecW55 { u8 k; u8 type; u16 cnt; PairW55 p[1]; };
s32 wtarget_002e3418(u32, u32, u32, u32) asm("_Z16wtarget_002e3418jjjj");
s32 wtarget_002e3418(u32 a, u32 b, u32 c, u32 d) {
    u8* h = (u8*)a;
    s32 n = *(s32*)(h + 8);
    if (!n) return -1;
    SecW55* e = (SecW55*)(h + 16);
    s32 i;
    for (i = 0; i < n; i++) {
        if (e->type == d) {
            s32 j;
            for (j = 0; j < e->cnt; j++) {
                PairW55* pr = &e->p[j];
                if (pr->a == b && pr->b == c) return pr->v;
            }
        }
        e = (SecW55*)&e->p[e->cnt];
    }
    return -1;
}
}

// ---- 2e34b0
struct Ref2e34b0 {
    u32 v;
    Ref2e34b0();
    void set(s32 x);
};
Ref2e34b0::Ref2e34b0() { v = 0; }
void Ref2e34b0::set(s32 x) { v = x; }
extern "C" u32 func_002e34c8(u8** p) {
    return *(u32*)(*p + 8);
}

// ---- 2e34d8 (src/anon/batch_w14.cpp)
namespace n2e34d8 {
extern "C" u8* func_002e34d8(u8** p, s32 n) {  // list_walk_stride12
    u8* q = *p;
    q += 16;
    if (n > 0) do {
        q += q[10] * 12 + 64;
    } while (--n);
    return q;
}
}

// ---- 2e3510
// ---- Ti path traps (0x2e3510-0x2e3ef0); the table is .data at 0x362f48.

struct FV2e3 {
    f32 x, y, z, w;
    FV2e3() {}
    ~FV2e3() {}
    FV2e3& operator=(const FV2e3& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct V3_2e3 { u32 a, b, c; };

extern "C" {
s32 func_0018bbf8(void*);
FV2e3 func_0016af58(void*);
FV2e3* func_0016c028(void*);
FV2e3 func_0016c2b0(void*);
s32 func_00184eb8(void*, s32, void*);
s32 func_00184f90(void*, s32);
void func_00185050(void*, void*);
s32 func_0018ac80(void*, s32);
void func_0018aca8(void*, s32);
void func_0018acd8(void*, s32);
s32 func_0018b1b8(void*);
void func_0018c150(void*);
V3_2e3* func_0018c240(void*);
FV2e3 func_0018c258(void*);
void* func_0019b260(s32);
void func_002cb7a0(void*, s32, FV2e3*);
void func_002cb7c0(void*, void*, s32);
FV2e3 func_002cb7c8(void*, s32);
s32 func_002cb800(void*, FV2e3*);
FV2e3* func_002cb8b8(void*);
FV2e3* func_002cb8e0(void*);
FV2e3 func_002cba88(void*, FV2e3*, const FV2e3&, f32, f32);
void func_002cbd08(void*, f32);
void func_002cbec0(void*, FV2e3*);
FV2e3 func_002cbed8(void*);
FV2e3 func_002cbf08(void*);
void func_002cc620(void*, void*, void*);
void func_002cd260(void*);
void func_002cd290(void*, void*, s32);
void func_002e2d50(void);
void func_002e2d88(s32, s32);
s32 func_002e2dd8(void);
}
s32 NPC_is_rtn_change_dir(void*) asm("_ZN2YS3NPC17is_rtn_change_dirEv");
void MG_MoveToBeforePoint(void) asm("_ZN2Ti12MG_EHSidecar17MoveToBeforePointEv");
s32 MG_GetCurrentPoint(void) asm("_ZN2Ti12MG_EHSidecar15GetCurrentPointEv");

static FV2e3 s_vec;      // 0x1e2be20
static V3_2e3 s_v3;      // 0x1e2be30

#define TOBJ(bd) (*(u8**)((u8*)(bd)[0].p + 4))
#define PATH(o) (*(u8**)((o) + 1288))

namespace Ti {

void trap_get_start_rtn_action(BD_VALUE* bd) {
    bd[0].i = func_0018bbf8(TOBJ(bd));
}

static void trap_2e3540(BD_VALUE* bd) {
    u8* o = TOBJ(bd);
    if (PATH(o)) {
        FV2e3* pos = func_0016c028(o);
        s_vec = func_002cba88(PATH(o), pos, func_0016af58(o), bd[1].f, 1.0f);
        bd[0].p = &s_vec;
    }
}

}  // namespace Ti

extern "C" void func_002e35e8(BD_VALUE* bd) {
    u8* o = TOBJ(bd);
    if (PATH(o)) {
        FV2e3* pos = func_0016c028(o);
        s_vec = func_002cba88(PATH(o), pos, func_0016af58(o), bd[1].f, bd[2].f);
        bd[0].p = &s_vec;
    }
}

namespace Ti {

void trap_set_path_way(BD_VALUE* bd) {
    u8* o = TOBJ(bd);
    if (PATH(o)) {
        FV2e3* pos = func_0016c028(o);
        u8* o1 = TOBJ(bd);
        u32 flag = bd[1].u;
        void* path = PATH(o1);
        func_002cb7a0(path, flag != 0, pos);
    }
}

void trap_reverse_path_way(BD_VALUE* bd) {
    u8* o = TOBJ(bd);
    if (PATH(o)) {
        FV2e3* pos = func_0016c028(o);
        bd[0].i = func_002cb800(PATH(TOBJ(bd)), pos);
    } else {
        bd[0].i = 0;
    }
}

static void trap_2e3750(BD_VALUE* bd) {
    func_0018c150(TOBJ(bd));
}

static void trap_2e3770(BD_VALUE* bd) {
    V3_2e3* r = func_0018c240(TOBJ(bd));
    s_v3 = *r;
    bd[0].p = &s_v3;
}

}  // namespace Ti

extern "C" void func_002e37c0(BD_VALUE* bd) {
    s_vec = func_0018c258(TOBJ(bd));
    bd[0].p = &s_vec;
}

namespace Ti {

void trap_is_rtn_change_dir(BD_VALUE* bd) {
    bd[0].i = NPC_is_rtn_change_dir(TOBJ(bd));
}

}  // namespace Ti

extern "C" void func_002e3840(BD_VALUE* bd) {
    s_vec = func_0016c2b0(TOBJ(bd));
    bd[0].p = &s_vec;
}

namespace Ti {

void trap_create_active_path(BD_VALUE* bd) {
    u8* o = TOBJ(bd);
    func_00185050(o, *(void**)((u8*)bd[1].p + 4));
}

static void trap_2e38b8(BD_VALUE* bd) {
    u8* o = TOBJ(bd);
    if (o && PATH(o) && PATH(o)[135]) {
        u8* tgt = *(u8**)((u8*)bd[1].p + 4);
        FV2e3* pos = func_0016c028(tgt);
        s_vec = func_002cba88(PATH(o), pos, func_0016af58(tgt), bd[2].f, 1.0f);
        bd[0].p = &s_vec;
    }
}

void trap_forward_path_current_pointer(BD_VALUE* bd) {
    u8* o = TOBJ(bd);
    if (o && PATH(o))
        func_002cbd08(PATH(o), bd[1].f);
}

void trap_reset_path_current_pointer(BD_VALUE* bd) {
    u8* o = TOBJ(bd);
    if (o && PATH(o))
        func_002cbec0(PATH(o), func_0016c028(o));
}

}  // namespace Ti

extern "C" void func_002e3a18(BD_VALUE* bd) {
    u8* o = TOBJ(bd);
    if (o && PATH(o)) {
        s_vec = func_002cbed8(PATH(o));
        bd[0].p = &s_vec;
    }
}

extern "C" void func_002e3a78(BD_VALUE* bd) {
    u8* o = TOBJ(bd);
    if (o && PATH(o)) {
        s_vec = func_002cbf08(PATH(o));
        bd[0].p = &s_vec;
    }
}

namespace Ti {

void trap_is_end_rtn_action(BD_VALUE* bd) {
    bd[0].i = func_0018b1b8(TOBJ(bd));
}

void trap_reset_active_path(BD_VALUE* bd) {
    u8* o = TOBJ(bd);
    if (o && PATH(o) && PATH(o)[135])
        func_002cd290(PATH(o), o, 0);
}

void trap_set_path_target_point(BD_VALUE* bd) {
    u8* o = TOBJ(bd);
    if (o && PATH(o))
        func_002cb7c0(PATH(o), o, bd[1].i);
}

}  // namespace Ti

extern "C" void func_002e3b88(BD_VALUE* bd) {
    u8* o = TOBJ(bd);
    if (o && PATH(o)) {
        s_vec = func_002cb7c8(PATH(o), bd[1].i);
        bd[0].p = &s_vec;
    }
}

namespace Ti {

void trap_clear_active_path(BD_VALUE* bd) {
    u8* o = TOBJ(bd);
    if (o && PATH(o) && PATH(o)[135])
        func_002cd260(PATH(o));
}

}  // namespace Ti

extern "C" void func_002e3c28(BD_VALUE* bd) {
    u8* o = TOBJ(bd);
    void* t = *(void**)((u8*)bd[1].p + 4);
    if (o && PATH(o) && t)
        func_002cc620(PATH(o), o, t);
}

namespace Ti {

void trap_check_rtn_option_flag(BD_VALUE* bd) {
    bd[0].i = func_0018ac80(TOBJ(bd), bd[1].i);
}

void trap_set_rtn_option_flag(BD_VALUE* bd) {
    func_0018aca8(TOBJ(bd), bd[1].i);
}

void trap_set_rtn_time_param(BD_VALUE* bd) {
    func_0018acd8(TOBJ(bd), bd[1].i);
}

}  // namespace Ti

extern "C" void func_002e3ce8(BD_VALUE* bd) {
    u8* o = TOBJ(bd);
    if (o && PATH(o)) {
        s_vec = *func_002cb8b8(PATH(o));
        bd[0].p = &s_vec;
    }
}

extern "C" void func_002e3d48(BD_VALUE* bd) {
    u8* o = TOBJ(bd);
    if (o && PATH(o)) {
        s_vec = *func_002cb8e0(PATH(o));
        bd[0].p = &s_vec;
    }
}

namespace Ti {

void trap_set_path_by_id(BD_VALUE* bd) {
    bd[0].i = func_00184f90(TOBJ(bd), bd[1].i);
}

void trap_set_path_by_group(BD_VALUE* bd) {
    void* g = func_0019b260(bd[1].i & 0xfffeffff);
    if (g)
        bd[0].i = func_00184eb8(TOBJ(bd), -1, g);
    else
        bd[0].i = 0;
}

static void trap_2e3e38(BD_VALUE* bd) {
    *(u32*)(TOBJ(bd) + 2824) = *(u32*)((u8*)bd[1].p + 4);
}

void trap_eh22_path_move_before(BD_VALUE* bd) {
    MG_MoveToBeforePoint();
}

static void trap_2e3e68(BD_VALUE* bd) {
    func_002e2d50();
}

static void trap_2e3e80(BD_VALUE* bd) {
    bd[0].i = func_002e2dd8();
}

void trap_eh22_path_get_point(BD_VALUE* bd) {
    bd[0].i = MG_GetCurrentPoint();
}

void trap_eh22_path_play(BD_VALUE* bd) {
    func_002e2d88(bd[1].i, bd[2].i != 0);
}

struct TRAP { void (*fn)(BD_VALUE*); u32 flags; };

}  // namespace Ti

extern "C" {
Ti::TRAP D_00362f48[35] = {
    { Ti::trap_get_start_rtn_action, 0x40000001 },
    { Ti::trap_set_path_way, 2 },
    { Ti::trap_reverse_path_way, 0x40000001 },
    { Ti::trap_2e3540, 0x40000002 },
    { Ti::trap_2e3750, 1 },
    { Ti::trap_2e3770, 0x40000001 },
    { func_002e37c0, 0x40000001 },
    { Ti::trap_is_rtn_change_dir, 0x40000001 },
    { Ti::trap_create_active_path, 2 },
    { Ti::trap_2e38b8, 0x40000003 },
    { Ti::trap_forward_path_current_pointer, 2 },
    { Ti::trap_is_end_rtn_action, 0x40000001 },
    { Ti::trap_reset_active_path, 1 },
    { Ti::trap_set_path_target_point, 2 },
    { func_002e3b88, 0x40000002 },
    { Ti::trap_clear_active_path, 1 },
    { func_002e3c28, 2 },
    { Ti::trap_check_rtn_option_flag, 0x40000002 },
    { Ti::trap_reset_path_current_pointer, 1 },
    { func_002e3a18, 0x40000001 },
    { func_002e3a78, 0x40000001 },
    { func_002e3ce8, 0x40000001 },
    { func_002e3d48, 0x40000001 },
    { Ti::trap_set_path_by_id, 0x40000002 },
    { Ti::trap_set_path_by_group, 0x40000002 },
    { func_002e35e8, 0x40000003 },
    { Ti::trap_2e3e38, 2 },
    { Ti::trap_set_rtn_option_flag, 2 },
    { Ti::trap_eh22_path_move_before, 1 },
    { Ti::trap_2e3e68, 1 },
    { Ti::trap_2e3e80, 0x40000001 },
    { Ti::trap_eh22_path_get_point, 0x40000001 },
    { Ti::trap_eh22_path_play, 3 },
    { Ti::trap_set_rtn_time_param, 2 },
    { func_002e3840, 0x40000001 },
};
}
