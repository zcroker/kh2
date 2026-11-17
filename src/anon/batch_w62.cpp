#include "../common/types.h"

struct u128 { u32 w[4]; } __attribute__((aligned(16)));
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

// 16-byte vector with a qword copy constructor and a self-checking assignment.
struct Vq {
    union { u128 q; f32 f[4]; };
    Vq() {}
    Vq(const Vq& o) { QCOPY(this, &o); }
    void operator=(const Vq& o) { if (this != &o) QCOPY(this, &o); }
};

// Same, but the copy constructor's qword move is never split by the assembler.
struct Vr {
    union { u128 q; f32 f[4]; };
    Vr() {}
    Vr(const Vr& o) {
        asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder"
                     : : "r"(this), "r"(&o) : "$8", "memory");
    }
    void operator=(const Vr& o) { if (this != &o) QCOPY(this, &o); }
};

// Local whose (empty) destructor keeps the final call from becoming a tail call.
struct NoTail { ~NoTail() {} };

extern "C" {

void func_002fd160(void) __attribute__((noreturn));

struct EhObject { u32 pc_begin; u32 tbase; u32 dbase; };
// base_from_object: base address for a DWARF EH pointer encoding.
u32 func_00100920(u8 encoding, EhObject* ob);  // 0x00100920: definition moved into src/libgcc/unwind-dw2-fde.c

struct Node2180 { u8 pad[12]; Node2180* next; u8 pad2[12]; s32 state; };
extern Node2180* D_0038aa40;
static inline Node2180* Next2180(Node2180* n) {
    if (!n) return D_0038aa40;
    return n->next;
}
// Collects every list node whose state is 1; returns the count.
s32 func_00102180(Node2180** out) {
    Node2180* n = 0;
    s32 count = 0;
    while ((n = Next2180(n))) {
        if (n->state == 1) {
            *out++ = n;
            count++;
        }
    }
    return count;
}

void func_0010a800(u8*, u8*, u8*);  // copy_global_3bytes
void func_00108698(u8* p);  // 00108698: moved to src/anon/unit_001085a8.cpp

struct VObj1246 { u32 (**vt)(...); };
VObj1246* func_00124748(u32, u32);  // list_nth_node_rel
typedef u32 (*Fn1246)(VObj1246*, u32, u32, u32, u32, u8, u32);
u32 func_001246b8(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0, u8 t1, u32 t2);  // 0x001246b8: definition moved into src/anon/unit_00123990.cpp

void func_00132270(u8*);  // obj_ctor_347c00
void func_00108398(u8*);  // clear_quads_set_flags
extern u8 D_00347c30[];
// Constructor: base, vtable, four 144-byte members at +48.
void func_00132430(u8* p);  // 0x00132430: definition moved into src/anon/unit_00131418.cpp

extern u32 D_0034a3f0;
extern f32* D_0034a3f4;
extern f32 D_0034a3f8;
f32* func_0016c028(u32);  // obj_get_attach_or_alt
f32 func_002f8ad0(f32, f32);
// Yaw/pitch (atan2) of the offset between two points.
// 0014e658: moved to src/harata/libdk/fpscamera.cpp

extern f32 D_004f3580;
extern f32 D_004f3584;
void wtarget_0014ec40(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_0014ec40jjjj");
// 0014ec40: static initialiser, now made by gcc in src/harata/libdk/fpscamera.cpp

void func_00159ce0(u8*, Vq*);
void func_0013f888(u8*, Vq*, u32);
void func_0013fca8(u8*);
// 0015a528: moved to src/harata/libdk/targetcamera.cpp

void func_00141010(f32);
u8* func_00140df0(void);
s32 func_00140dc0(void);
void func_0015a6c8(u8*);
extern f32 D_0034aa84;
// 0015a638: moved to src/harata/libdk/targetcamera.cpp

extern u8 D_0034c70c;
extern u8 D_0034c6f0[];
s32 func_001de568(u8*);
void func_001dde40(u8*);
void func_00142f50(void);
// 0015edb8: moved to src/harata/libdk/map.cpp

struct Blk64 {
    u128 q[4];
    void operator=(const Blk64& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
};
struct VObj6 { s32 (**vt)(VObj6*, Blk64*); };
void func_001616d8(Blk64*);
void func_001616f0(Blk64* p) {
    Blk64 b;
    VObj6* o = *(VObj6**)((u8*)p + 72);
    if (!o) return;
    if (o->vt[6](o, &b)) {
        func_001616d8(p);
        return;
    }
    *p = b;
}

struct V4 { f32 x, y, z, w; };
extern s8 D_01c5f490;
extern V4 D_01c5f4a0;
void func_00175528(void);
void func_002fd188(void (*)(void));  // pool_alloc_block
u32 func_0016f000(u32, V4*, f32);
// Function-local static vector (0,0,0,1) with its guard and atexit registration.
void func_00170f98(u32* p);  // 0x00170f98: definition moved into src/anon/unit_00170f58.cpp

static inline bool isPos(f32 x) { return 0.0f < x; }
struct S17f { u8 pad[48]; f32 f30; f32 f34; u8 pad2[104]; Vr v; };
// 0017ff68: moved to src/yasui/libys/motion.cpp

struct Slot180 { u32 obj; u32 key; };
u32 func_00198580(u32, u32);  // check_div1000_500
// 00180b10: moved to src/anon/unit_00180408.cpp

struct Act { u8 pad[140]; u32 f8c; u8 pad2[8]; s32 f98; u32 f9c; };
struct Pri { u16 h0; u16 h2; u16 h4; };
Pri* func_00187ab8(u32);
void func_00187f90(Act*);
void func_00187fd8(Act*, Pri*);
void act_pri_start(Act* a) asm("_ZN2YS3ACT9pri_startEPc");
// 00188170: moved to src/anon/unit_00185d10.cpp

s32 func_001c0cd8(u8*);
// Parity of negative components, combined recursively with the linked object.
s32 func_001943e8(u8* p);  // 0x001943e8: definition moved into src/anon/unit_00193be8.cpp

struct S19b {
    u8 pad[1344];
    Vq a;
    u8 pad2[64];
    Vq b;
    Vq c;
    u8 pad3[80];
    u64 w;
};
void func_00185118(S19b*);
void func_00143928(Vq*);
s32 func_0019bf50(S19b* p, Vq* v);  // 0x0019bf50: definition moved into src/anon/unit_0019ba60.cpp

void func_001b0330(u32);
void* func_001050d8(u32);
void func_001b6298(void*, u8*, u32, u32);
extern u8 D_0032f054;
void func_001b6c60(u8* p);  // 0x001b6c60: definition moved into src/anon/unit_001b6a50.cpp

struct Tbl1d5 { u32 f0; u32 n; u8 data[1]; };
extern Tbl1d5* D_01d48d98;
extern u8 D_00320458[];
struct R1b8 { u16 h0; u16 h2; s16 h4; };
R1b8* func_002fd248(u32, u8*, u32, u32, u8*);
u32 func_001a67b0(s32);
void u_call4_001b8e88(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16u_call4_001b8e88jjjj");
void u_call4_001b8e88(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001b8e88: definition moved into src/anon/unit_001b87a0.cpp

struct E1bc { u8 pad[5]; u8 type; u8 pad2[6]; };
struct S1bc { u8 pad[8]; s32 n; E1bc e[1]; };
static inline bool isLow(E1bc* e) { return e->type < 4; }
s32 func_001bc948(S1bc* s);  // 0x001bc948: definition moved into src/anon/unit_001bc568.cpp

// Wraps an angle into [-pi, pi].
f32 func_001cbf50(f32 a);  // 0x001cbf50: definition moved into src/anon/unit_001ca8e0.cpp

void func_001c8d98(u8*, u32);
void func_001c9b90(void);
void func_001d2710(u8*);
void func_00319f88(u8*);
void func_0019f9a8(u8*);  // array8_free_slots
void func_001c0248(u8*);
void func_00319fb0(u8*);  // big_obj_dtor
extern u8 D_00352360[];
extern u8 D_0034e8b8[];
extern u8 D_0034ee08[];
extern u8 D_00351eb8[];
extern u8 D_00351ec0[];
// Destructor chain: own vtable, then the two base levels.
void func_001cfeb0(u8* p);  // 0x001cfeb0: definition moved into src/anon/unit_001cf0b0.cpp

void func_001d1678(u8*, s32);  // obj_init_28bytes
void func_001d19e8(u8*, s32);
void func_001d16e8(u8*, u32, u32);
extern u8 D_003525c8[];
extern u8 D_00352750[];
void func_001d4c98(u8* p);  // 0x001d4c98: definition moved into src/anon/unit_001d3c08.cpp

s32 func_0019c898(u32);
void func_001d5f30(u8*, u32);
void func_001d6088(u32 id, u8* o);  // 0x001d6088: definition moved into src/anon/unit_001d4f40.cpp

extern s32 D_00352b50;
s32 func_0019ba60(u8*);
s32 func_001dffd8(u8* p);  // 0x001dffd8: definition moved into src/anon/unit_001deb58.cpp

extern u32 D_01d9e6e4;
void func_001e7798(u32, u32);
// Releases the three handles at +12/+16/+20 of the sub-block.
void func_00207050(u8* p, u8* d);  // 0x00207050: definition moved into src/anon/unit_00206be8.cpp

extern s32 D_0035dcf0;
extern u8 D_0035db00[];
void func_00225fa0(u8*, u32);
void func_00227930(u8*);
void func_002278e0(u8* p);  // 0x002278e0: definition moved into src/anon/unit_00224780.cpp

struct E239 { u8 pad[4]; u16 h4; u16 pad2; u32 f8; u8 pad3[24]; };
struct S239 {
    u8 pad[180]; E239* tbl; u8 pad1[4]; u8 bc; u8 pad2[71];
    f32 f104; f32 f108; s32 f10c; u8 pad3[4]; u32 f114; u8 pad4[40]; u32 f140; u32 f144;
};
s32 func_00239af8(S239*, u32);
void ctarget_00239c68(S239* p, u32 a1, u32 a2, u32 a3) asm("_Z16ctarget_00239c68jjjj");
void ctarget_00239c68(S239* p, u32 a1, u32 a2, u32 a3);  // 0x00239c68: definition moved into src/anon/unit_00239988.cpp

s32 func_00287bc0(void);
u8* func_00257770(void);
void func_0028dac8(u8*, u32);
void func_0027e6e0(void);
void cm_FadeOutStock(void* self) asm("_ZN2Tz6CmItem12FadeOutStockEv");
void cm_FadeOutStock(void* self);  // 0x00262fa0: definition moved into src/anon/unit_0025f6b8.cpp

extern u32 D_0035f010;
u8* func_00281180(u32, u32);
u8* func_001a80c8(u16);  // table24_find_by_id
struct Ent267 { u16 id : 15; u16 on : 1; };
// Sums byte 7 of every enabled entry's record over the 80-entry list.
s32 func_00267150(u32 a);  // 0x00267150: definition moved into src/anon/unit_00265580.cpp

void func_00139d78(u8*);
s16* func_0028ac98(u8*, u32);  // lookup_by_index_align
s32 func_0028ae98(u8* p, u32 i);  // 0x0028ae98: definition moved into src/anon/unit_00288b00.cpp

void func_00138840(void);
double func_00313b80(f32);  // float_to_double
s32 func_003142e0(double, double);  // double_compare
extern f32 D_00349e10;
void func_0028d2a0(u8* p);  // 0028d2a0: moved to src/anon/unit_0028c878.cpp

struct VObj2b { void (**vt)(VObj2b*); u8 pad[28]; VObj2b* next; };
void func_002be148(u8*);
void func_00170950(u32);
void func_001b86e0(u32);  // alloc_from_pool_magic_c
void func_00170320(s32);
extern u32 D_003617fc;
extern u8 D_003637e0[];
void func_002bda38(u8* p);  // 0x002bda38: definition moved into src/anon/unit_002bc978.cpp

s32 func_002cf270(u8*, u32);
void func_002cf2b0(u8*, u32);
void func_0016ac38(u8*, u32, u32, u32, u32);
void func_002cf280(u8*, u32, u32);
void func_002d3f18(u8* p);  // 0x002d3f18: definition moved into src/anon/unit_002d2498.cpp

void func_00198690(u8*);
void func_0016b070(u8*, f32*);
void func_0016ace0(u8*, f32*);
void func_002de8e8(u8* p);  // 0x002de8e8: definition moved into src/anon/unit_002de3c8.cpp

extern f32 D_01e2c040;
void func_002eb9d8(u8*, u8*, u32, f32);
// 002eba78: moved to src/anon/unit_002eaf38.cpp

void func_002fde18(void*, s32, u32);
struct UwCtx { u8 pad[708]; void* cfa; u32 ra; u8 pad2[28]; };
struct UwFs { u8 pad[2840]; s64 cfa_offset; u64 cfa_reg; u8 pad2[4]; s32 cfa_how; u8 pad3[32]; };
s32 func_00317d80(UwCtx*, UwFs*);
void func_00317fc8(UwCtx*, UwFs*);
// uw_init_context_1: unwind context for the caller's frame.
void func_003181f8(UwCtx* ctx, void* outer_cfa, u32 outer_ra) {
    UwFs fs;
    u32 ra = (u32)__builtin_return_address(0) & ~1;
    func_002fde18(ctx, 0, sizeof(UwCtx));
    outer_ra &= ~1;
    ctx->ra = ra;
    if (func_00317d80(ctx, &fs)) func_002fd160();
    ctx->cfa = outer_cfa;
    fs.cfa_how = 1;
    fs.cfa_reg = 0;
    fs.cfa_offset = 0;
    func_00317fc8(ctx, &fs);
    ctx->ra = outer_ra;
}

}
