#include "../common/types.h"

#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct Q16 { u32 w[4]; } __attribute__((aligned(16)));

extern "C" {
u32 func_001524e8(u32, u32);
void func_00152498(u32, u32);
u32 func_0013e678(void);
u32 func_0013a7e8(u32);
void func_001386e0(u32, u32, u32, u32, u32, u32);
void func_001396b0(u32);
void func_0031a260(u32, u32);
void func_00138c40(u32, u32, u32);
void func_00239988(u32, u32, u32);
void func_00239bf8(u32, u32);
void func_00152120(u32);
u32 func_0023aa78(u32);
void func_0014fc40(u32, u32, u32, u32, u32, u32);
void func_00139598(u32);
s32 func_00155758(u32, s32*, s32*, s32*, s32*, f32*);
s32 func_00139d78(u8*);
void func_0013edd0(u32, f32);
void func_0014b1e0(u32, s16, s16);
void func_0014b208(u32, u32, u32);
void func_001395a8(u32);
void func_00138d30(u32, f32);
s32 func_0015b4f8(void*, u32, s32*);
s32 func_0023aa98(u32);
extern u8 D_0034ab50[];
void func_0014b7f0(u32);
void func_0014c050(u32);
void func_0014b610(u32, u64);
void func_0014b608(u32, u64);
void func_0014b5e0(u32, u32);
void func_0014b630(u32, u32);
void func_0014b618(u32, u32);
void func_0014b5e8(u32, u64, u64);
void func_0014b468(u32, u32, u32);
void func_0014b628(u32, u64);
void func_0014b220(u32, u32, u32, u32, u32);
extern u8 D_0034c6e0[];
extern u8 D_0034c6c8[];
extern u8 D_004f3820[];
u8* func_00186078(u8*);
s32 func_0019ba60(u8*);
Q16* func_0016c028(u8*);  // obj_get_attach_or_alt
void func_00182980(void*, Q16*);
extern u8* D_0034ed04;
extern s32 D_0034ed00;
struct Ent12_w96 { u32 w[3]; };
extern Ent12_w96 D_01c60588[];
struct Vq_w96 {
    f32 x, y, z, w;
    Vq_w96& operator=(const Vq_w96& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline Vq_w96 vsubn_w96(const Vq_w96& a, const Vq_w96& b) {
    Vq_w96 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 vlen_w96(const Vq_w96& a) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(&a) : "$8", "memory");
    return r;
}
u8* func_00177860(void);
f32 func_002f8870(f32);  // fabsf
void func_002fee78(char*, const char*, ...);
u32 func_00170b30(u32);  // alloc_align128
void func_00168328(char*, u32);
u8* func_00168b38(u32, u32, u32);  // entry_array_find_nth
void func_001aad28(u32, u32, u32, u32, u32, u32);
void func_00170c00(u32);
extern const char* D_00350a2c;
extern u32 D_0033caf4;
void func_001ac378(u32, u32, u32, u32, u32, u32, u32);
void func_002395b8(u32);
void func_001abd90(u32);
void func_001ac028(u32);
void func_00239700(u32);
u32 func_001ab810(void);  // get_global_1c7cec0
u32 func_001ab800(void);
void func_001aa668(u32, u32);
extern u8 D_00350bb0[];
extern u8 D_0034e8a8[];
struct Rgb_w96 { u8 c[3]; };
extern Rgb_w96 D_00350a38[];
struct Ent_w96 { u16 id; u8 kind; u8 pad[5]; };
struct EntTbl_w96 { u32 hdr; s32 count; Ent_w96 ents[1]; };
extern EntTbl_w96* D_01d49560;
s32 func_001c3850(Ent_w96*);
union FU_w96 { f32 f; u32 u; };
struct Item36_w96 { u8 pad[8]; u8 name[8]; s8 sel; u8 pad17; u16 icon; u8 pad20[16]; };
extern Item36_w96 D_003719e8[];
extern u32 D_0035ecec;
extern u32 D_0035ecf0;
extern u32 D_0035ed08;
void func_00288d80(u32, s32, u32, u32, u32, u32, Item36_w96*, u8*);
u8* func_002891b8(u32, s32);
void func_00288e08(u32, s32, s32, u32);
u32 func_0028dd90(s32);  // mod10_classify_012
u32 func_0028ddd8(s32);
void func_001395f8(u8*);
void func_002891f0(u32, s32, u32, u32, u32);
void func_002b4388(u32, Item36_w96*, u32);
typedef u8* (*AllocFn_w96)(void*, u32, u32);
extern u8* D_00347f80;
extern u8 D_00347e80[];
extern u8 D_00347e60[];
void func_002361a0(u8*);
void func_0023f800(u32);
extern char D_01e21ef8[];
extern char D_003743f8[];
void func_0023fa90(u32, char*);
u32 func_0023f988(u32, u32);
void func_00138650(u8*, u32, u32, u32);
static inline u8* heap_alloc_w96(u32 size) {
    void* h = *(void**)(D_00347f80 + 20);
    return (**(AllocFn_w96**)h)(h, size, 0);
}
void func_0028e710(u8*, u32);
void func_0028ebf0(u8*, u32);
void func_0028e748(u8*, s32, u32);
struct Ch_w96 {
    u8 pad[344];
    s32 a;
    s32 b;
    u8 c;
    u8 pad2[3];
    f32 d;
    s32 e;
    s32 f;
    f32 g;
    f32 h;
    u8 pad3[4];
};
union ChU_w96 { Ch_w96* p; u32 u; u16 h; };
extern u8* D_0035f5e8;
s32 func_00103b38(void);
u32 func_00103570(void);
u32 func_00106178(u32, u32);
s32 func_00293fb0(void);
void func_00293e00(u32);
void func_00293fc0(void);
u8* func_001063c0(u32, u32);
void func_00319a60(u8*);  // clear_fixed_blocks
u8* func_001063f0(u32, u32);
extern u32 D_0035f628;
extern u32 D_0035f62c;
extern u8 D_0035f614;
extern u32 D_0035f618;
extern u32 D_0035f61c;
extern u8* D_0035f620;
extern u8* D_0035f624;
struct Pair_w96 { u32 a; u32 b; };
u8* func_002a9d68(void);
u32* func_002b23e0(s32);  // list_entry_by_index_checked
s32 func_002b3ac8(u32);
void func_002b2f28(u32);
union EU_w96 { u32 u; u16 h; };
static inline __attribute__((always_inline)) void setbit_w96(u16* bits, u32 n) { u16* p = &bits[n >> 4]; *p |= 1 << (n & 15); }
void func_002b6adc(u32, u32);
struct QEnt_w96 { u32 id; f32 len; };
struct SeqQ_w96 { s32 tail; s32 head; QEnt_w96 q[4]; };
struct Seq_w96 {
    u32 busy : 1;
    u32 rest : 31;
    u32 user;
    u8* src;
    u32 target;
    f32 t;
    f32 len;
    SeqQ_w96 queue;
};
typedef f32 (*LenFn_w96)(u8*);
void func_002ef180(Seq_w96*, f32, f32);
void func_002eef08(Seq_w96*, u32, f32);
void func_00189f20(u32, void (*)(void), u32, f32);
void func_002ef148(void);
struct Bigint_w96 { Bigint_w96* next; s32 k; s32 maxwds; s32 sign; s32 wds; u32 x[1]; };
Bigint_w96* func_00303b70(void*, s32);
void func_00303c18(void*, Bigint_w96*);  // push_entry_onto_slot_list

// Builds the widget: icons, 7 child panels, then hands off to the shared init.
void wtarget_001521c8(u32 a0, u32 a1, u32, u32) asm("_Z16wtarget_001521c8jjjj");
void wtarget_001521c8(u32 self, u32 id, u32, u32) {
    u32 obj, s3, s4, p;
    s32 i;
    if (func_001524e8(self, id)) {
        func_00152498(self, id);
        return;
    }
    *(u32*)(self + 2892) = id;
    s4 = func_0013e678();
    s3 = func_0013a7e8(0);
    obj = self + 48;
    func_001386e0(obj, 4500, s3, s4, 48, 7);
    *(u32*)(obj + 396) = 0;
    func_001396b0(obj);
    if (*(u32*)(obj + 396) != 0) {
        *(u32*)(obj + 400) = 0;
        func_001396b0(obj);
        if (*(u32*)(obj + 400) != 0) {
            func_0031a260(obj, 0);
        }
    }
    func_00138c40(obj, 0, *(u32*)(self + 36));
    p = self + 456;
    for (i = 6; i >= 0; i--) {
        func_00239988(p, s3, s4);
        func_00239bf8(p, 38);
        p += 344;
    }
    func_00152120(self);
    func_0014fc40(self, 14, func_0023aa78(self + 72), 4500, 7, 0);
}

void func_001558b8(u32 self, u32 a1, s32 idx) {  // entry592_process
    u32 e = self + idx * 592;
    u32 obj = e + 13232;
    u32 s7 = e + 13552;
    s32 x, y, w, h;
    f32 f;
    func_00139598(obj);
    if (func_00155758(a1, &x, &y, &w, &h, &f) == 0) {
        f32 scale = f;
        s32 sx, sy, sw, sh;
        func_00139d78((u8*)obj);
        func_0013edd0(e + 13264, scale);
        sx = x;
        sy = y;
        sw = w;
        sh = h;
        func_00139d78((u8*)obj);
        func_0014b1e0(s7, sx, sy);
        func_0014b208(s7, (u16)sw, (u16)sh);
        func_001395a8(obj);
        if (idx == 1) {
            func_00138d30(self + 9588, -f);
        }
    }
}

// Sets up a row of up to 8 child panels and centres them horizontally.
void func_0015b368(u32 self, u32 a1, u32 a2, u32 a3) {
    s32 ids[8];
    s32 sum = 0;
    s32 i = 0;
    s32 half, v;
    u32 s5 = func_0013a7e8(0);
    func_001386e0(self, 3800, s5, a2, a1, 15);
    *(s32*)(self + 436) = func_0015b4f8(D_0034ab50, a3, ids);
    for (; i < *(s32*)(self + 436); i++) {
        u32 p = self + 440 + i * 344;
        func_00239988(p, s5, a2);
        func_00239bf8(p, ids[i]);
        sum += func_0023aa98(p);
    }
    v = func_0023aa98(self + 24);
    i = 0;
    sum += v;
    half = sum / 2;
    sum = 0;
    *(s32*)(self + 376) = half - v;
    for (; i < *(s32*)(self + 436); i++) {
        ((s32*)(self + 2848))[i] = sum - half;
        sum += func_0023aa98(self + 440 + i * 344);
    }
}

// Constructor: vtable + two sprite members, then their draw state.
void func_0015e4e0(u32 p) {
    u32 s1, s2;
    *(u32*)(p + 4) = 0;
    *(u32*)p = (u32)D_0034c6e0;
    s1 = p + 144;
    func_0014b7f0(s1);
    s2 = p + 416;
    func_0014c050(s2);
    *(u32*)(p + 1200) = 0;
    func_0014b610(s1, 0x131000070ULL);
    func_0014b608(s1, 0x00ffffff00080140ULL);
    func_0014b5e0(s1, 278);
    func_0014b630(s1, 96);
    func_0014b618(s1, 0x3cfe5);
    func_0014b5e8(s1, 0x80008, 0x4080408);
    func_0014b610(s2, 0x131000070ULL);
    func_0014b5e0(s2, 342);
    func_0014b630(s2, 96);
    func_0014b618(s2, 0x3001d);
    func_0014b208(s2, 512, 416);
    func_0014b468(s2, 512, 416);
    func_0014b628(s2, 0x2006a00664022800ULL);
}

// Constructor: vtable + one sprite member; also sets up a shared global sprite.
void func_0015e9e0(u32 p) {
    u32 s2;
    u32 g;
    *(u32*)(p + 4) = 0;
    *(u32*)p = (u32)D_0034c6c8;
    s2 = p + 80;
    func_0014c050(s2);
    *(u32*)(p + 864) = 0;
    g = (u32)D_004f3820;
    func_0014b610(g, 0x131000070ULL);
    func_0014b608(g, 0x80140);
    func_0014b5e0(g, 6);
    func_0014b220(g, 0, 0, 0, 0);
    func_0014b208(g, 512, 416);
    func_0014b610(s2, 0x131000070ULL);
    func_0014b5e0(s2, 342);
    func_0014b630(s2, 96);
    func_0014b618(s2, 0x3001d);
    func_0014b208(s2, 512, 416);
    func_0014b468(s2, 512, 416);
    func_0014b628(s2, 0x2006a00664022800ULL);
}

// 00182c60: moved to src/anon/unit_00182780.cpp

// Is point p within (radius r, height h) of actor o?
s32 func_001a4ff8(u8* o, Vq_w96* p, f32 r, f32 h) {
    Vq_w96 d;
    if (*(u32*)(o + 2040) & 4) return 0;
    if (*(u32*)(*(u8**)(o + 12) + 8) & 0x40000) return 1;
    if (r <= 0.0f) {
        r = 120.0f;
        if (*(u32*)(o + 1416) & 4) r = *(f32*)(func_00177860() + 52) + r;
    }
    if (*(u8**)(o + 1164)) r = r + *(f32*)(*(u8**)(o + 1164) + 452);
    if (h <= 0.0f) h = 30.0f;
    d = vsubn_w96(*p, *(Vq_w96*)func_0016c028(o));  // obj_get_attach_or_alt
    if (h < func_002f8870(d.y)) return 0;
    d.y = 0.0f;
    if (vlen_w96(d) <= r) return 1;
    return 0;
}

// Loads a texture archive by name and uploads its images to VRAM.
void func_001aabd8(void) {
    char path[48];
    u32 h;
    u32 p;
    func_002fee78(path, D_00350a2c, D_0033caf4);
    h = func_00170b30(0x80000);  // alloc_align128
    func_00168328(path, h);
    p = *(u32*)(func_00168b38(h, 36, 0) + 8);  // entry_array_find_nth
    func_001aad28(0, 8, 36, 512, 256, p);
    func_001aad28(0, 8, 44, 512, 256, p + 0x10000);
    p = *(u32*)(func_00168b38(h, 36, 1) + 8);  // entry_array_find_nth
    func_001aad28(2048, 8, 36, 512, 512, p);
    func_001aad28(2048, 8, 44, 512, 512, p + 0x20000);
    p = *(u32*)(func_00168b38(h, 36, 2) + 8);  // entry_array_find_nth
    func_001aad28(6144, 4, 27, 256, 160, p);
    func_001aad28(16380, 1, 0, 16, 16, p + 0xa000);
    func_00170c00(h);
}

// Constructor: base init, vtables, four child panels, colour from a kind table.
void func_001ac970(u32 self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 kind) {
    u32 p;
    func_001ac378(self, a1, a2, a3, a4, a5, a6);
    *(u32*)self = (u32)D_00350bb0;
    func_002395b8(self + 132);
    *(u32*)(self + 476) = kind;
    *(u32*)(self + 132) = (u32)D_0034e8a8;
    func_001abd90(self + 480);
    *(u32*)(self + 1192) = 0;
    func_001ac028(self + 1196);
    p = self + 1544;
    for (s32 k = 3; k != -1; k--) {
        func_00239700(p);
        p += 344;
    }
    *(u32*)(self + 2920) = 0;
    {
        u32 a = func_001ab810();  // get_global_1c7cec0
        func_00239988(self + 132, a, func_001ab800());
    }
    func_00239bf8(self + 132, D_00350a38[*(u32*)(self + 476)].c[0]);
    for (s32 i = 0; i < 4; i++) {
        u32 a = func_001ab810();  // get_global_1c7cec0
        func_00239988(self + 1544 + i * 344, a, func_001ab800());
    }
    func_001aa668(self + 12, self);
}

// Finds the next entry of the given kind (after prev) that passes func_001c3850.
Ent_w96* func_001c3748(u32 kind, Ent_w96* e) {
    if (e == 0) {
        s32 i;
        for (i = 0; i < D_01d49560->count; i++) {
            if (D_01d49560->ents[i].kind == kind) {
                e = &D_01d49560->ents[i];
                break;
            }
        }
    } else {
        e++;
    }
    for (; e != 0 && e < &D_01d49560->ents[D_01d49560->count] && e->kind == kind; e++) {
        if (func_001c3850(e)) return e;
    }
    return 0;
}

// Quicksort keys (descending) in [lo, hi], permuting the parallel ids array alongside.
void func_001dd568(u32* ids, FU_w96* keys, s32 lo, s32 hi) {
    s32 i = lo;
    s32 j = hi;
    f32 pivot = keys[(lo + hi) / 2].f;
    for (;;) {
        while (pivot < keys[i].f) i++;
        while (keys[j].f < pivot) j--;
        if (i >= j) break;
        {
            f32 t = keys[i].f;
            u32 u;
            keys[i].f = keys[j].f;
            keys[j].f = t;
            u = ids[i];
            ids[i] = ids[j];
            ids[j] = u;
        }
        i++;
        j--;
    }
    if (lo < i - 1) func_001dd568(ids, keys, lo, i - 1);
    if (j + 1 < hi) func_001dd568(ids, keys, j + 1, hi);
}

// Quicksort keys (descending) in [lo, hi], permuting the parallel ids array alongside.

// Builds the two-entry choice list and focuses the preselected entry.
void func_00243cd8(void) {
    s32 i;
    s32 sel = 0;
    for (i = 0; i < 2; i++) {
        u8* w;
        s32 h;
        if (D_003719e8[i].sel) sel = i;
        func_00288d80(D_0035ecec, i, 0, 0, D_0035ecf0, D_003719e8[i].icon, &D_003719e8[i], D_003719e8[i].name);
        w = func_002891b8(D_0035ecec, i);
        func_00288e08(D_0035ecec, i, func_0023aa78((u32)w + 24), 0);
        h = func_0023aa98((u32)w + 24);
        *(u32*)(w + 432) = func_0028dd90(h);
        *(u32*)(w + 428) = func_0028ddd8(h);
        func_001395f8(w);
    }
    func_002891f0(D_0035ecec, sel, 1, 0, 2);
    func_002b4388(D_0035ed08, &D_003719e8[sel], 0);
}

void func_002874b0(u8* self) {
    u8* o;
    s32 i;
    o = heap_alloc_w96(448);
    *(u32*)(o + 12) = 0;
    *(u32*)o = (u32)D_00347e80;
    func_002361a0(o + 32);
    *(u8**)self = o;
    func_0023f800((u32)self + 12);
    for (i = 0; i < 2; i++) {
        o = heap_alloc_w96(408);
        *(u32*)(o + 12) = 0;
        *(u32*)o = (u32)D_00347e60;
        func_00239700((u32)o + 24);
        ((u8**)(self + 4))[i] = o;
    }
    func_002fee78(D_01e21ef8, D_003743f8, D_0033caf4);
    func_0023fa90((u32)self + 12, D_01e21ef8);
    func_00138650(*(u8**)self, 26000, func_0023f988((u32)self + 12, 0), 0);
}

// Resets the channel table: n channels back to defaults.
void func_0028e190(u8* self, s32 n) {
    s32 i;
    *(s32*)(self + 28) = 0;
    *(s32*)(self + 32) = 0;
    *(s32*)(self + 36) = 0;
    *(s32*)(self + 40) = 0;
    *(f32*)(self + 44) = 1.0f;
    func_0028e710(self, 0);
    func_0028ebf0(self, 0);
    for (i = 0; i < n; i++) {
        ChU_w96* arr = (ChU_w96*)(self + 56);
        arr->p[i].a = -1;
        arr->p[i].b = -1;
        arr->p[i].c = 0;
        arr->p[i].d = 1.0f;
        arr->p[i].e = 0;
        arr->p[i].f = 0;
        arr->p[i].g = 1.0f;
        arr->p[i].h = 1.0f;
        func_0028e748(self, i, 0);
    }
}

// Returns nonzero if any of the screen's widgets is still busy.
s32 func_002a40c8(void) {
    s32 r;
    s32 i, j;
    if ((r = func_00139d78(D_0035f5e8 + 29376)) != 0) return r;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 8; j++) {
            if ((r = func_00139d78(D_0035f5e8 + i * 3264 + j * 408)) != 0) return r;
        }
    }
    if ((r = func_00139d78(D_0035f5e8 + 29784)) != 0) return r;
    if ((r = func_00139d78(D_0035f5e8 + 30220)) != 0) return r;
    if ((r = func_00139d78(D_0035f5e8 + 30656)) != 0) return r;
    for (i = 0; i < 9; i++) {
        if ((r = func_00139d78(D_0035f5e8 + i * 436 + 31092)) != 0) return r;
        if ((r = func_00139d78(D_0035f5e8 + i * 436 + 0x88c8)) != 0) return r;
    }
    return r;
}

void func_002acda8(void) {
    Pair_w96* q;
    s32 i;
    D_0035f628 = 0;
    D_0035f62c = 0;
    D_0035f614 = 0;
    D_0035f618 = 0;
    if (func_00103b38()) {
        D_0035f618 = func_00103570();
    } else {
        u32 v = func_00170b30(0x10000);  // alloc_align128
        D_0035f61c = v;
        D_0035f618 = func_00106178(v, 0x10000);
        if (!func_00293fb0()) {
            func_00293e00(D_0035f618);
            func_00293fc0();
            D_0035f614 = 1;
        }
    }
    {
        u8* p = func_001063c0(2408, D_0035f618);
        func_00319a60(p);  // clear_fixed_blocks
        D_0035f620 = p;
    }
    q = (Pair_w96*)func_001063f0(80, D_0035f618);
    {
        Pair_w96* e = q;
        for (i = 9; i != -1; i--) {
            e->a = 0;
            e->b = 0;
            e++;
        }
    }
    D_0035f624 = (u8*)q;
}

s32 func_002b3318(void) {
    u8* g = func_002a9d68();
    s32 ok = 1;
    u32* e = func_002b23e0(-1);  // list_entry_by_index_checked
    u8 k;
    s32 n, i;
    if (*e & 0x4000000) return 0;
    k = ((u8*)e)[2];
    n = func_002b3ac8((*e >> 27) & 1);
    for (i = 0; i < n; i++) {
        s8* slot = (s8*)(g + k * 192 + 480 + i * 4);
        if (slot[8] != i || slot[9] != 0) {
            ok = 0;
            break;
        }
    }
    if (!ok) return 0;
    setbit_w96((u16*)(g + 484), k);
    ((EU_w96*)e)->u |= 0x4000000;
    func_002b2f28(0);
    return 1;
}

void func_002baa78(void) {
    s32 i;
    func_002b6adc(2, 4);
    func_002b6adc(0, 4);
    func_002b6adc(2, 5);
    func_002b6adc(0, 5);
    func_002b6adc(2, 6);
    func_002b6adc(0, 6);
    func_002b6adc(2, 7);
    func_002b6adc(0, 7);
    func_002b6adc(0, 10);
    func_002b6adc(2, 10);
    func_002b6adc(2, 11);
    func_002b6adc(2, 12);
    func_002b6adc(2, 13);
    func_002b6adc(2, 14);
    for (i = 0; i < 14; i++) {
        func_002b6adc(2, i + 30);
        func_002b6adc(0, i + 30);
    }
    for (i = 0; i < 2; i++) {
        func_002b6adc(2, i + 20);
        func_002b6adc(0, i + 20);
    }
}

// Advances a queued sequence by dt, pulling the next queued entry when the current one ends.
void func_002ef028(Seq_w96* s, f32 dt) {
    if (!s->src) return;
    if (!s->busy) {
        f32 old = s->t;
        s->t = old + dt;
        func_002ef180(s, old, s->t);
        if (s->t >= s->len) {
            SeqQ_w96* q = &s->queue;
            s32 h = q->head;
            if (h != q->tail) {
                q->head = (h + 1) % 4;
                QEnt_w96* e = q->q + h;
                func_002eef08(s, e->id, e->len);
            } else {
                f32 l = (*(LenFn_w96*)(*(u8**)s->src + 28))(s->src);
                s->t = s->t - s->len + l;
                func_002ef180(s, l, s->t);
            }
        }
    }
    if (s->target) func_00189f20(s->target, func_002ef148, s->user, dt);
    s->busy = 0;
}

// newlib mprec __lshift: b << k as a new Bigint (frees b).
Bigint_w96* func_00304308(void* ptr, Bigint_w96* b, s32 k) {
    s32 i, k1, n, n1;
    Bigint_w96* b1;
    u32 *x, *x1, *xe, z;

    n = k >> 5;
    k1 = b->k;
    n1 = n + b->wds + 1;
    for (i = b->maxwds; n1 > i; i <<= 1)
        k1++;
    b1 = func_00303b70(ptr, k1);
    x1 = b1->x;
    for (i = 0; i < n; i++)
        *x1++ = 0;
    x = b->x;
    xe = x + b->wds;
    if (k &= 0x1f) {
        k1 = 32 - k;
        z = 0;
        do {
            *x1++ = *x << k | z;
            z = *x++ >> k1;
        } while (x < xe);
        if ((*x1 = z) != 0)
            ++n1;
    } else
        do
            *x1++ = *x++;
        while (x < xe);
    b1->wds = n1 - 1;
    func_00303c18(ptr, b);  // push_entry_onto_slot_list
    return b1;
}

}
