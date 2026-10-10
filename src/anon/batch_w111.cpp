#include "../common/types.h"
extern "C" {
struct EhFde { u32 length; s32 CIE_delta; u32 pc_begin[1]; };
struct EhFdeVec { void* orig; u32 count; EhFde* array[1]; };
struct EhAccu { EhFdeVec* linear; };
struct EhObj { u32 pc_begin; u32 tbase; u32 dbase; u32 u; union { struct { unsigned long sorted:1; unsigned long from_array:1; unsigned long mixed_encoding:1; unsigned long encoding:8; unsigned long count:21; } b; u32 i; } s; EhObj* next; };
u32 func_00100920(u8, EhObj*);  // classify_subtype
s32 func_001009a0(u8*);
u8* func_001004c0(u8, u32, u32*, u32*);
u32 func_001003c8(u8);  // classify_arg_masked3
// add_fdes: insert every live FDE of an object into the accumulator.
void func_00101050(EhObj* ob, EhAccu* accu, EhFde* this_fde)
{
    u8* last_cie = 0;
    int encoding = ob->s.b.encoding;
    u32 base = func_00100920(ob->s.b.encoding, ob);  // classify_subtype
    for (; this_fde->length != 0; this_fde = (EhFde*)((u8*)this_fde + this_fde->length + 4)) {
        u8* this_cie;
        if (this_fde->CIE_delta == 0) continue;
        if ((int)ob->s.b.mixed_encoding) {
            this_cie = (u8*)&this_fde->CIE_delta - this_fde->CIE_delta;
            if (this_cie != last_cie) {
                last_cie = this_cie;
                encoding = func_001009a0(this_cie);
                base = func_00100920(encoding, ob);  // classify_subtype
            }
        }
        if (encoding == 0) {
            if (this_fde->pc_begin[0] == 0) continue;
        } else {
            u32 pc_begin, mask;
            func_001004c0(encoding, base, this_fde->pc_begin, &pc_begin);
            mask = func_001003c8(encoding);  // classify_arg_masked3
            if (mask < 4) mask = (1L << (mask << 3)) - 1;
            else mask = -1;
            if ((pc_begin & mask) == 0) continue;
        }
        if (accu->linear) accu->linear->array[accu->linear->count++] = this_fde;
    }
}
struct EhObj2 { u32 pc_begin; u32 tbase; u32 dbase; u32 u; union { struct { unsigned long sorted:1; unsigned long from_array:1; unsigned long mixed_encoding:1; unsigned long encoding:8; unsigned long count:21; } b; u32 i; } s; EhObj* next; };
struct EhBases { u32 tbase; u32 dbase; u32 func; };
EhFde* func_00101388(EhObj*, void*);
s32 func_0030edb0(void);
void func_0030ee00(void);  // ee_intr_get_enable
extern s32 D_0037aa2c;
extern EhObj* D_0037aa30;
extern EhObj* D_0037aa34;
// _Unwind_Find_FDE: find the FDE covering pc, classifying unseen objects on the way.
EhFde* func_00101698(void* pc, EhBases* bases)
{
    EhObj* ob;
    EhFde* f = 0;
    D_0037aa2c = func_0030edb0();
    for (ob = D_0037aa34; ob; ob = ob->next)
        if ((u32)pc >= ob->pc_begin) {
            f = func_00101388(ob, pc);
            if (f) goto fini;
            break;
        }
    while ((ob = D_0037aa30)) {
        EhObj** p;
        D_0037aa30 = ob->next;
        f = func_00101388(ob, pc);
        for (p = &D_0037aa34; *p; p = &(*p)->next)
            if ((*p)->pc_begin < ob->pc_begin) break;
        ob->next = *p;
        *p = ob;
        if (f) goto fini;
    }
fini:
    if (D_0037aa2c) func_0030ee00();  // ee_intr_get_enable
    if (f) {
        int encoding;
        bases->tbase = ob->tbase;
        bases->dbase = ob->dbase;
        encoding = ob->s.b.encoding;
        if ((int)ob->s.b.mixed_encoding)
            encoding = func_001009a0((u8*)&f->CIE_delta - f->CIE_delta);
        func_001004c0(encoding, func_00100920(encoding, ob), f->pc_begin, &bases->func);
    }
    return f;
}


void func_00103ea0(s32);  // set_hook_ptr
void func_0014c9d8(s32);
void func_0014df88(void);
void func_0014e0d8(void);
void func_0023ed90(void);  // set_global_byte1
s32 func_001050c8(void);
s32 func_00104288(void);
s32 func_00104600(void);
s32 func_00102e90(void);
void func_0023fb00(s32);
void func_00103c70(void);  // clear_hook_ptr
void func_00103e78(void);
void func_00102080(void*);
void func_00167ea8(void);
void func_001024a8(void*);
extern s32 D_0032ba24;
extern s32 D_0032b984;
extern s32 D_0032b9bc;
extern s32 D_0032ba64;
extern s32 D_003a6a50;
struct St32 { u8 pad[28]; s32 f28; };
extern St32 D_0032b968;
extern St32 D_0032ba48;
extern u8 D_0032b9e8[];
#define IsMode156(m) ((m) == 1 || (m) == 5 || (m) == 6)
static inline bool Is984Two() { return D_0032b984 == 2; }
static inline bool Is9bcTwo() { return D_0032b9bc == 2; }
static inline bool Isa64Two() { return D_0032ba64 == 2; }
// Mode-dependent setup step, then common tail work.
void func_001037f8(void* a0)
{
    s32 skip = 0;
    func_00103ea0(0);  // set_hook_ptr
    if (IsMode156(D_0032ba24) && Is984Two()) skip = 1;
    else if (D_0032ba24 == 4 && Is9bcTwo()) skip = 1;
    else if (D_0032ba24 == 2) skip = Isa64Two();
    if (!skip) {
        s32 r;
        func_0014c9d8(1);
        if (IsMode156(D_0032ba24)) {
            if (D_003a6a50 != 10) { func_0014df88(); func_0014e0d8(); }
            if (D_0032b968.f28) D_0032b968.f28 = 2;
        } else if (D_0032ba24 == 2) {
            func_0014df88(); func_0014e0d8();
            if (D_0032ba48.f28) D_0032ba48.f28 = 2;
        }
        func_0023ed90();  // set_global_byte1
        if (IsMode156(D_0032ba24)) r = func_001050c8();
        else if (D_0032ba24 == 2) r = func_00104288();
        else if (D_0032ba24 == 3) r = func_00104600();
        else r = func_00102e90();
        func_0023fb00(r);
        func_00103c70();  // clear_hook_ptr
        func_00103e78();
    }
    func_00102080(D_0032b9e8);
    func_00167ea8();
    func_001024a8(a0);
}
}

typedef unsigned int u128 __attribute__((mode(TI)));
struct Mtx11 { u128 q[4]; };
struct VObj11 { void** vt; };
#define MCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t" \
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" \
                         : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
static inline void VScale(void* v, f32 k) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(v), "f"(k) : "$8", "memory");
}
extern "C" {
extern Mtx11 D_00347af0;
extern Mtx11 D_00347b30;
void func_0011d440(void);
void func_0011b6a8(Mtx11*);
typedef void (*Fn11a)(VObj11*, u8*, Mtx11*, u32, u32, f32);
typedef void (*Fn11b)(VObj11*, u8*);
// Sets the object's work matrix (and negates its two direction vectors), publishes it, then runs the setup hook.
#define WORK_MTX(o) ((Mtx11*)((o) + 128))
void func_0011c4e8(u8* o, Mtx11* m, VObj11* src, u32 a3, u32 a4, Mtx11* m2, f32 f)
{
    func_0011d440();
    if (m) {
        if (WORK_MTX(o) != m) MCOPY(WORK_MTX(o), m);
        VScale(o + 144, -1.0f);
        VScale(o + 160, -1.0f);
    } else func_0011b6a8(WORK_MTX(o));
    if (WORK_MTX(o) != &D_00347af0) MCOPY(&D_00347af0, WORK_MTX(o));
    if (m2) { if (m2 != &D_00347b30) MCOPY(&D_00347b30, m2); }
    else func_0011b6a8(&D_00347b30);
    if (src) ((Fn11a)src->vt[3])(src, o, m, a3, a4, f);
    else { VObj11* p = *(VObj11**)(o + 20); ((Fn11b)p->vt[11])(p, o); }
    *(VObj11**)(o + 24) = src;
    *(u32*)(o + 12) &= ~1;
}
}

#define QCOPY12(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define MCOPY12(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t" \
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" \
                         : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct V12 { f32 x, y, z, w;
    V12& operator=(const V12& o) { if (this != &o) QCOPY12(this, &o); return *this; }
} __attribute__((aligned(16)));
struct M12 { V12 r[4];
    M12& operator=(const M12& o) { if (this != &o) MCOPY12(this, &o); return *this; }
};
struct Heap12 { void** vt; };
typedef void* (*AllocFn12)(Heap12*, s32, void*);
struct Src12Info { u8 pad[4]; s32 kind; };
struct Src12Sub { void** vt; Src12Info* info; };
struct Src12Tbl { u8 pad[8]; s32 n; u8 pad2[4]; u8 data[1]; };
struct Src12 {
    u8 pad[12]; u32 flags; u8 pad2[4]; Src12Sub* shape; Src12Sub* sub; V12* pos; V12* scl; u8 pad3[4]; union { M12* mtx; f32 fx; };
};
struct Dst12 { V12* pos; union { M12* mtx; f32 fx; }; u8 pad[4]; union { s32 f12; Src12Sub* f12p; }; void* tbl; Src12Sub* shape; u8 b24; u8 b25; };
// Builds a runtime pose copy (positions, scales, matrices, optional link table) from a source shape.
extern "C" {
void func_00124828(Dst12*);
void* func_00124c48(Src12Sub*, s32);
void func_002fdd68(void*, void*, s32);
Dst12* func_00127a88(Src12* o, Heap12* heap) asm("_Z13func_00127a88Pv");
typedef s32 (*CountFn12)(Src12Sub*);
typedef s32 (*SubFn12)(Src12Sub*, Src12*, Heap12*);
Dst12* func_00127a88(Src12* o, Heap12* heap)
{
    s32 n = ((CountFn12)o->shape->vt[7])(o->shape);
    Dst12* r = (Dst12*)((AllocFn12)heap->vt[0])(heap, n * 80 + 32, __builtin_return_address(0));
    func_00124828(r);
    r->f12 = 0;
    V12* p = (V12*)((u8*)r + 32);
    r->pos = p;
    r->tbl = 0;
    r->mtx = (M12*)(p + n);
    r->shape = o->shape;
    for (s32 i = 0; i < n; i++) {
        r->pos[i] = o->pos[i];
        V12& d = r->pos[i]; V12& sv = o->scl[i]; d.w = sv.x;
        r->mtx[i] = o->mtx[i];
    }
    if (o->flags & 1) r->b25 = 1;
    if (o->sub) {
        r->f12 = ((SubFn12)o->sub->vt[4])(o->sub, o, heap);
        s32 k = o->sub->info->kind;
        if (k == 1) r->b24 = k; else r->b24 = 0;
        Src12Tbl* t = (Src12Tbl*)func_00124c48(o->sub, 0);
        if (t) {
            s32 sz = t->n * 4;
            r->tbl = ((AllocFn12)heap->vt[0])(heap, sz + 4, 0);
            func_002fdd68(r->tbl, t->data, sz);
            s16* e = (s16*)(sz + (u32)r->tbl);
            e[1] = -1;
            e[0] = -1;
        }
    }
    return r;
}
}

struct Node14 { s16 child[8]; u8 box[24]; s16 first; s16 end; u8 pad[4]; };
struct Item14 { u8 on; u8 pad[3]; u8 box[24]; };
struct Tree14 { u8 pad[4]; Node14* nodes; Item14* items; u8 pad2[484]; u8 view[1]; };
extern "C" {
s32 func_00146730(void*, void*);
void func_00146390(Tree14*, s32, void*);
s32 func_00146088(Tree14*, void*);
void func_00146100(Tree14*, void*, s16);
void func_00146128(Tree14*, void*, s16);
void func_00146250(Tree14*, Node14*);
// Recursively visits a node tree against a view volume, handling items of partly visible nodes.
void func_00146498(Tree14* t, s32 idx, void* arg)
{
    Node14* n = &t->nodes[idx];
    switch (func_00146730(t->view, n->box)) {
    case 1:
        func_00146390(t, idx, arg);
        return;
    case 0:
        return;
    case 2:
        if (func_00146088(t, n->box) == 1) return;
        s32 end = n->end;
        for (s32 i = n->first; i < end; i++) {
            Item14* it = (Item14*)(i * sizeof(Item14) + (u32)t->items);
            if (it->on) {
                switch (func_00146730(t->view, it->box)) {
                case 0: break;
                case 1: func_00146100(t, arg, i); break;
                case 2: func_00146128(t, arg, i); break;
                }
            }
        }
        func_00146250(t, n);
        break;
    }
    for (s32 k = 0; k < 8; k++) {
        s32 c = n->child[k];
        if (c == -1) break;
        func_00146498(t, c, arg);
    }
}
}

// Local whose (empty) destructor keeps the final call from becoming a tail call.
struct NoTail14 { ~NoTail14() {} };
struct SObj14 { void** vt; u8 pad[268]; };
extern "C" {
extern SObj14 D_003493a0;
extern SObj14 D_003494b0;
extern SObj14 D_003495c0;
extern SObj14 D_003496d0;
extern SObj14 D_003497e0;
extern SObj14 D_003498f0;
extern SObj14 D_00349a00;
extern void* D_00349b40[];
void func_0014a950(SObj14*);
void func_0031bb08(SObj14*);  // set_vtbl_3486a8
void func_0014aed0(int init, int prio) asm("_Z13func_0014aed0ii");
}
// Static construction / destruction of this unit's seven global objects.
void func_0014aed0(int init, int prio)
{
    NoTail14 g;
    if (prio == 0xffff && init == 1) func_0014a950(&D_003493a0);
    if (prio == 0xffff && init == 1) func_0014a950(&D_003494b0);
    if (prio == 0xffff && init == 1) func_0014a950(&D_003495c0);
    if (prio == 0xffff && init == 1) func_0014a950(&D_003496d0);
    if (prio == 0xffff && init == 1) func_0014a950(&D_003497e0);
    if (prio == 0xffff && init == 1) func_0014a950(&D_003498f0);
    if (prio == 0xffff && init == 1) func_0014a950(&D_00349a00);
    if (prio == 0xffff && init == 0) { D_00349a00.vt = D_00349b40; func_0031bb08(&D_00349a00); }
    if (prio == 0xffff && init == 0) { D_003498f0.vt = D_00349b40; func_0031bb08(&D_003498f0); }
    if (prio == 0xffff && init == 0) { D_003497e0.vt = D_00349b40; func_0031bb08(&D_003497e0); }
    if (prio == 0xffff && init == 0) { D_003496d0.vt = D_00349b40; func_0031bb08(&D_003496d0); }
    if (prio == 0xffff && init == 0) { D_003495c0.vt = D_00349b40; func_0031bb08(&D_003495c0); }
    if (prio == 0xffff && init == 0) { D_003494b0.vt = D_00349b40; func_0031bb08(&D_003494b0); }
    if (prio == 0xffff && init == 0) { D_003493a0.vt = D_00349b40; func_0031bb08(&D_003493a0); }
}

extern "C" {
extern u8 D_00349e20;
extern u32 D_00349e1c;
extern u32 D_00349e08;
extern f32 D_00349e10;
extern f32 D_00349e0c;
extern f32 D_00349e14;
extern f32 D_00349e18;
void func_0014d478(void);
void u_tail0_0014d060(void) asm("_Z16u_tail0_0014d060v");
}
// Per-frame timing step: catch up on missed ticks, then derive the clamped frame delta and its rate.
void u_tail0_0014d060(void)
{
    func_0014d478();
    if (!D_00349e20) {
        D_00349e10 = 2.0f;
        if (D_00349e08 < D_00349e1c + 1)
            for (u32 i = 0; i < D_00349e1c; i++) func_0014d478();
    } else {
        D_00349e10 = D_00349e08;
        if (D_00349e08 < D_00349e1c + 1)
            for (u32 i = 0; i < D_00349e1c; i++) {
                func_0014d478();
                D_00349e10 = D_00349e08;
            }
    }
    D_00349e14 = D_00349e10;
    D_00349e10 = D_00349e10 * D_00349e0c;
    if (6.0f < D_00349e10) D_00349e10 = 6.0f;
    if (6.0f < D_00349e14) D_00349e14 = 6.0f;
    D_00349e08 = 0;
    D_00349e18 = 1.0f / D_00349e10;
}

struct Vq14 {
    f32 x, y, z, w;
    Vq14& operator=(const Vq14& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Sph14 { Vq14 c; f32 r; };
struct Pts14 { Vq14* v[4]; s32 n; };
static inline f32 DistSq14(const void* a, const void* b) {
    f32 d;
    asm volatile("lqc2 $vf6, 0(%1)\n\tlqc2 $vf4, 0(%2)\n\tvsub.xyzw $vf5, $vf6, $vf4\n\tvmove.xyzw $vf4, $vf5\n\t"
                 "vmul.xyz $vf5, $vf4, $vf5\n\tvaddy.x $vf5, $vf5, $vf5y\n\tvaddz.x $vf5, $vf5, $vf5z\n\tqmfc2 $2, $vf5\n\tmtc1 $2, %0"
                 : "=f"(d) : "r"(a), "r"(b) : "$2");
    return d;
}
extern "C" {
void* func_00106a60(s32);  // buffer_get_by_index
void func_00107368(void*, Vq14*);  // vec_copy_at80_if_diff
Vq14* func_00143ec8(u16);
Pts14* func_00143ea8(u16);
s32 func_00162b68(Sph14*, Vq14*, f32*);
s32 func_00162bb0(Sph14*, Pts14*, Vq14*, f32*, Vq14*);
s32 func_00162c28(Sph14*, Pts14*, Vq14*);
s32 func_00163168(Sph14*, Pts14*, Vq14*);
// Picks the point of object `id` nearest the camera (within 5000 units); *direct tells whether it was a direct hit.
s32 func_0014ee28(s32 id, Vq14* out, u8* direct)
{
    Vq14 cam;
    Vq14 hit;
    Sph14 s;
    Vq14 dir;
    Pts14 pts;
    Vq14 alt;
    f32 t;
    func_00107368(func_00106a60(0), &cam);  // vec_copy_at80_if_diff
    s.c = cam;
    s.r = 5000.0f;
    dir = *func_00143ec8(id);
    pts = *func_00143ea8(id);
    if (func_00162b68(&s, &dir, &t)) {
        if (func_00162bb0(&s, &pts, &dir, &t, &hit)) {
            *direct = 1;
            *out = hit;
            return 1;
        }
    }
    f32 d2 = 0.0f;
    if (func_00162c28(&s, &pts, &hit)) {
        f32 d1 = DistSq14(&cam, &hit);
        if (func_00163168(&s, &pts, &alt)) d2 = DistSq14(&cam, &alt);
        if (d2 < d1) { *direct = 0; *out = alt; }
        else { *direct = 0; *out = hit; }
        return 1;
    }
    return 0;
}
}

struct Motor17 { void** vt; };
struct Info17 { u8 pad[4]; f32 f4; };
struct Obj17 {
    u8 pad[12]; Motor17* motor; u8 pad2[192]; f32 t; f32 end; u8 pad3[48]; union { u32 flags; struct { u32 b0:17; u32 b17:1; u32 b18:1; u32 rest:13; } fb; };
    u8 pad4[1148]; u32 mode; u8 pad5[1060]; f32 f2480;
};
typedef void (*MotorFn17)(Motor17*, Obj17*, f32);
extern "C" {
extern Info17* D_00352130;
s32 func_0017ca88(void*, Obj17*);
s32 func_001958d0(Obj17*);
s32 func_0017cb48(void*, Obj17*);  // can_run_when_268_bit0
void func_0017cb78(void*, Obj17*);  // handle_field256_eq4
// Animation-window step: fires the motor callbacks when the play time enters / leaves the active windows.
void func_0017c690(void* self, Obj17* o)
{
    u64 unused[2]; // keeps the original's 48-byte frame
    if ((o->mode & 4) && func_0017ca88(self, o) && func_001958d0(o)) return;
    if (6.0f < o->t && o->t < o->end) {
        if (o->flags & 0x400000) {
            if (func_0017cb48(self, o)) func_0017cb78(self, o);  // can_run_when_268_bit0
            ((MotorFn17)o->motor->vt[3])(o->motor, o, 0.0f);
            o->fb.b17 = 0;
            o->fb.b18 = 0;
            if (o->mode & 4) o->f2480 = D_00352130->f4;
        }
    }
    if ((o->flags & 0x40000) && 6.0f < o->t && o->t < o->end - 5.0f) {
        if (func_0017cb48(self, o)) func_0017cb78(self, o);  // can_run_when_268_bit0
        ((MotorFn17)o->motor->vt[3])(o->motor, o, 5.10204f);
        o->fb.b18 = 0;
    } else if (o->end <= o->t + 5.0f) {
        if (func_0017cb48(self, o)) func_0017cb78(self, o);  // can_run_when_268_bit0
        o->fb.b17 = 0;
    }
}
}

struct E18a { u8 b[276]; };
struct E18b { u8 b[56]; };
struct E18c { u8 b[4]; };
struct E18d { u8 on; u8 pad[3]; s32 v; };
struct Obj18 {
    E18a a[13]; u8 pad0[0]; E18b b[10]; u8 pad1[0];
    u8 c4148, c4149, c4150, c4151, c4152, c4153, c4154; u8 pad2[9];
    E18c c[19]; u8 pad3[320]; s32 w4560[8]; s32 w4592; u8 pad4[20]; s16 h4616[4]; u8 pad5[4];
    s32 w4628[8]; s32 w4660[8]; s32 w4692; u8 pad6[1600]; s32 w6296[10]; u8 pad7[4];
    E18d d[64]; u8 sub6852[26]; u8 sub6878[28]; s16 h6906;
};
extern "C" {
void func_001888c8(E18a*);
void func_00189170(E18b*);
void func_001a8bb8(E18c*);  // obj_set_header_bytes
void func_00319d30(void*);
void func_001d9768(void*);
// Initialises the owner object: constructs its element arrays and clears the tables.
void func_00188e08(Obj18* o)
{
    {
        E18a* p = o->a;
        s32 n = 12;
        do { func_001888c8(p); p++; } while (--n != -1);
    }
    {
        E18b* p = o->b;
        s32 n = 9;
        do { func_00189170(p); p++; } while (--n != -1);
    }
    o->c4148 = 0;
    o->c4150 = 1;
    o->c4152 = 100;
    o->c4149 = 0;
    o->c4153 = 3;
    o->c4154 = 3;
    {
        E18c* p = o->c;
        s32 n = 18;
        do { func_001a8bb8(p); p++; } while (--n != -1);
    }
    s32 i;
    for (i = 0; i < 8; i++) o->w4560[i] = 0;
    o->w4592 = 0;
    for (i = 0; i < 8; i++) o->w4628[i] = 0;
    for (i = 0; i < 8; i++) o->w4660[i] = 0;
    o->w4692 = 0;
    for (i = 0; i < 10; i++) o->w6296[i] = 0;
    E18d* d = o->d;
    {
        E18d* p = d;
        s32 n = 63;
        do { p->on = 0; p->v = 0; p++; } while (--n != -1);
    }
    func_00319d30(d + 64);
    func_001d9768(o->sub6878);
    o->h6906 = 0;
    for (i = 0; i < 4; i++) o->h4616[i] = 0;
}
}

struct Data1c { u16 h0; u16 kind; u8 pad[2]; s8 slot; u8 b7; };
struct Src1c { u8 pad[2]; u16 id; u8 b4; u8 pad2[7]; u8 body[1]; };
struct Ent1c { u16 flags; u8 pad[3]; u8 state; u8 pad2[6]; };
struct Slot1c { u8 pad[8]; s32 busy; };
struct Owner1c { u8 pad[2528]; void* res; };
struct Mgr1c { u8 pad[4]; Owner1c* owner; s32 n; Ent1c ent[1]; };
extern "C" {
Data1c* func_001b8e88(u32);
void func_0019ba60(void*);
Src1c* func_001bd570(Owner1c*, s32);
void func_001bc6a8(Ent1c*, Data1c*, void*, void*, u32);
s32 func_001bc948(Slot1c*);
// Appends an entry for `id` (redirected through a linked source when present) and sets its initial state.
Ent1c* func_001bc780(Mgr1c* o, u32 id, void* body, u32 b)
{
    Src1c* s = 0;
    s32 linked = 0;
    Data1c* d = func_001b8e88(id);
    func_0019ba60(o->owner->res);
    if (d->b7 == 1) s = func_001bd570(o->owner, 0);
    else if (d->h0 == 81) s = func_001bd570(o->owner, 2);
    if (s) {
        body = s->body;
        b = s->b4;
        linked = 1;
        id = s->id;
        d = func_001b8e88(id);
    }
    func_001bc6a8(&o->ent[o->n], d, o->owner->res, body, b);
    if (linked) { Ent1c* e = &o->ent[o->n]; e->flags |= 1; }
    if (d->kind == 3 && b == 0) o->ent[o->n].state = 6;
    s32 v = d->slot;
    if (v >= 0 && v != 4) {
        Slot1c* x = (Slot1c*)((u8*)o->owner + v * 116 + 36);
        if (x->busy == 0) o->ent[o->n].state = 5;
        else if (!func_001bc948(x)) o->ent[o->n].state = 1;
    }
    return &o->ent[o->n++];
}
}

struct Pad24 { u8 pad[8]; u64 trig; };
struct Info24 { u8 kind; u8 pad[3]; s32 count; };
struct Sel24 { u8 pad[14664]; s8 cur; };
struct Sub24 { u8 pad[8]; s8 cur; };
extern "C" {
extern void* D_0035ed20;
extern u8* D_0035ed40;
extern u8 D_00371ca8[];
extern u8 D_00371cb0[];
extern u8 D_00371cb8[];
extern u8 D_00371cc0[];
Pad24* func_00167f18(s32);
s32 func_002891e8(void*);
s32 func_002474e0(s32);
s32 func_002469a0(s32);
s32 func_00246840(void);
Info24* func_001d56c8(u32);
// Steps the current selection up/down (wrapping on a fresh press); returns whether it changed.
bool func_00247870(u8 down)
{
    Pad24* pad = func_00167f18(0);
    s32 h = func_002891e8(D_0035ed20);
    if (!func_002474e0(h)) return 0;
    s32 i = func_002469a0(h);
    u32 id = (func_00246840() ? D_00371cb0 : D_00371ca8)[i];
    Info24* info = func_001d56c8(id);
    s32 max = (func_00246840() ? D_00371cc0 : D_00371cb8)[i];
    s32 step = 1;
    if (info->kind == 2 && id == 7) {
        max = info->count;
        max /= 10;
        max *= 10;
        max++;
        step = 10;
    }
    s32 cur = ((Sel24*)(h + (u32)D_0035ed40))->cur;
    if (down) {
        if (cur <= 0) {
            if (pad->trig & 0x40) cur = max - 1;
        } else {
            cur -= step;
            if (cur < 0) cur = 0;
        }
    } else {
        if (cur + 1 >= max) {
            if (pad->trig & 0x80) cur = 0;
        } else {
            cur += step;
            cur = cur < max ? cur : max - 1;
        }
    }
    Sub24* s = (Sub24*)(h + (u32)D_0035ed40 + 14656);
    s32 old = s->cur;
    s->cur = cur;
    return old != cur;
}
}

extern "C" {
extern void* D_0035ee58;
extern void* D_0035ee5c;
s32 func_00287cd0(void);
s32 func_00289380(void*);
s32 func_002519d0(void);
s32 func_00289310(void*);
void func_00287f90(s32);
void func_00251a08(void);
void func_0028af18(void*, s32);
void func_00287bd0(s32, s32);
s32 func_0028ae28(void*, s32);
void func_0028ab20(void*);
void func_00287c90(s32);
s32 func_00287df0(s32, s32, s32, void (*)(void), s32);
void func_0028aa40(void*);
void func_002519b0(void);
s32 func_002891e8(void*);
s32 func_00252110(s32);
void func_00287b08(s32);
void func_00252618(void);
void func_00287da0(void);
s32 func_00288040(void);
void func_00288018(void);  // global_zero_4dwords
// Menu update: handles the confirm/close states and dispatches the chosen entry.
void func_00251780(void)
{
    s32 st = func_00287cd0();
    s32 sel = func_00289380(D_0035ee5c);
    if (st == 2) {
        if (func_002519d0()) {
            if (sel != -1 || func_00289310(D_0035ee5c)) {
                func_00287f90(0);
                func_00251a08();
            }
            return;
        }
        func_0028af18(D_0035ee5c, 115);
        func_00287bd0(0, 0);
        return;
    }
    if (sel != -1 || func_00289310(D_0035ee5c)) {
        if (!func_0028ae28(D_0035ee5c, 0)) func_0028ab20(D_0035ee5c);
    }
    if (st == 0 && func_0028ae28(D_0035ee5c, 0)) func_00287c90(1);
    func_00287df0(sel, func_00289310(D_0035ee5c), 0, 0, 1);
    switch (sel) {
    case -1:
        break;
    case -2:
    case 1:
        func_0028aa40(D_0035ee5c);
        func_002519b0();
        func_00287c90(1);
        break;
    case 0: {
        s32 k;
        switch (func_00252110(func_002891e8(D_0035ee58))) {
        case 0: k = 60; break;
        case 1: k = 61; break;
        case 2: k = 62; break;
        case 3: k = 63; break;
        default: k = -1; break;
        }
        func_00287b08(k);
        func_00252618();
        func_00287da0();
        break;
    }
    }
    if (func_00288040()) func_00288018();
}
}

extern "C" {
extern void* D_0035f024;
extern u8 D_0035f0f0;
s32 func_00289380(void*);
s32 func_00287cd0(void);
s32 func_002938e0(void);
s32 func_002938f0(void);
void func_0026c140(void);
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
void func_0026cb38(void);
void func_00287c90(s32);
s32 func_002892f8(void*);
s32 func_00289310(void*);
s32 func_00287df0(s32, s32, s32, void (*)(void), s32);
s32 func_00242848(s32);
void func_0026d748(void);
void func_00287da0(void);
s32 func_00287dc0(void);
void func_0023d820(s32);
s32 func_00288040(void);
void func_00288018(void);  // global_zero_4dwords
void func_0026d960(void);
// Menu update for this list: close handling, cursor feedback and entry dispatch.
void func_0026c818(void)
{
    s32 sel = func_00289380(D_0035f024);
    s32 st = func_00287cd0();
    if (func_002938e0() && func_002938f0() && D_0035f0f0) func_0026c140();
    if (st == 2) {
        func_00287bd0(20, 0);
        func_00287cc0(1);
        func_0026cb38();
        return;
    }
    if (st == 0) func_00287c90(1);
    s32 n = func_002892f8(D_0035f024);
    if (!func_00242848(func_00287df0(sel, func_00289310(D_0035f024), 1, func_0026d960, 1))) {
        switch (sel) {
        case -2:
            func_00287c90(1);
            break;
        case -4:
            func_00287da0();
            if (func_002938e0() && !func_002938f0()) func_0023d820(func_00287dc0());
            break;
        case -1:
            break;
        default:
            if (sel >= 0 && sel < n) {
                func_0026d748();
                func_00287c90(1);
            }
            break;
        }
    }
    if (func_00288040()) func_00288018();
}
}

struct Pt27 { s16 x; s16 pad; s16 y; };
struct Heap27 { void** vt; };
typedef void* (*AllocFn27)(Heap27*, s32, void*);
struct Sys27 { u8 pad[20]; Heap27* heap; };
struct Item27 { void* vt; u8 pad[8]; s32 f12; u8 pad2[8]; u8 sub[384]; };
extern "C" {
extern u8 D_00347f98[];
extern u8 D_0035eb98[];
extern u8 D_00347e60[];
extern union { u8* p; s16 h; } D_0035f210;
extern Item27* D_0035f204;
extern void* D_0035f148;
extern void* D_0035f14c;
extern u8 D_00373d78[];
extern u8 D_00373d80[];
extern Sys27* D_00347f80;
Pt27* func_00276fa8(void);  // global_ptr_by_flag2
void* func_0023ee30(s32);
void func_0031a838(void*);
void func_002369a0(void*);  // obj_ctor_36eac8
void func_0023c008(void*);  // obj_ctor_36eae8
void func_0028d7f0(void*, s32, s32, s32, s32, s32, s32, s32, s32);
void func_0023ef50(void*);
void func_0028f280(void*, void*, void*, void*, void*);
void func_00276598(void);
void func_00239700(void*);
void func_00276220(s32, s32);
void func_00275af8(void);
s32 func_00287bc0(void);
void func_002945e8(void);
void func_00296588(void);
void func_002958b0(void);
void func_00276588(s32);
void func_0028fb28(s32, s32);
void func_002a77a0(void);
// Creates this screen's main object and item, then enters the mode-specific setup.
void func_00274fa8(void)
{
    Pt27* p = func_00276fa8();  // global_ptr_by_flag2
    u8* o = (u8*)func_0023ee30(160);
    *(u32*)o = (u32)D_00347f98;
    func_0031a838(o + 12);
    *(u32*)o = (u32)D_0035eb98;
    func_002369a0(o + 24);  // obj_ctor_36eac8
    func_0023c008(o + 48);  // obj_ctor_36eae8
    D_0035f210.p = o;
    func_0028d7f0(o, 30039, 0, 0, p->x, p->y, 0, 0, 0);
    func_0023ef50(D_0035f210.p);
    func_0028f280(D_0035f148, D_0035f14c, D_0035f210.p, D_00373d78, D_00373d80);
    func_00276598();
    Heap27* h = D_00347f80->heap;
    Item27* it = (Item27*)((AllocFn27)h->vt[0])(h, 408, 0);
    it->f12 = 0;
    it->vt = D_00347e60;
    func_00239700(it->sub);
    D_0035f204 = it;
    func_00276220(0, 0);
    func_00275af8();
    switch (func_00287bc0()) {
    case 0: func_002945e8(); break;
    case 1: func_00296588(); break;
    case 2: func_002958b0(); break;
    case 11:
        func_00276588(1);
        func_0028fb28(0, 12881);
        func_002a77a0();
        break;
    }
}
}

extern "C" {
u64 func_00313ed8(u64, u64);
s32 func_003142e0(u64, u64);  // double_compare
char* func_00301938(void*, u64, s32, s32, s32*, s32*, char**);
// cvt (newlib vfprintf): convert a double to digits for %e/%f/%g.
char* func_003012d8(void* data, u64 value, s32 ndigits, s32 flags, char* sign, s32* decpt, s32 ch, s32* length)
{
    s32 mode, dsgn;
    char *digits, *bp, *rve;
    if (ch == 'f') {
        mode = 3;
    } else {
        if (ch == 'e' || ch == 'E') ndigits++;
        mode = 2;
    }
    if ((s32)(value >> 32) < 0) {
        value = func_00313ed8(0, value);
        *sign = '-';
    } else
        *sign = '\0';
    digits = func_00301938(data, value, mode, ndigits, decpt, &dsgn, &rve);
    if ((ch != 'g' && ch != 'G') || (flags & 1) == 1) {
        bp = digits + ndigits;
        if (ch == 'f') {
            if (*digits == '0' && func_003142e0(value, 0))
                *decpt = -ndigits + 1;
            bp += *decpt;
        }
        if (func_003142e0(value, 0) == 0)
            rve = bp;
        while (rve < bp)
            *rve++ = '0';
    }
    *length = rve - digits;
    return digits;
}
}
