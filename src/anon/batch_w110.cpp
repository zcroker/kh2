#include "../common/types.h"
extern "C" {
void func_00109330(void);  // set_global_3756_return
void func_00109340(void);  // to_109450_zero
void func_001344b8(u32);
void func_00108998(void*);
void func_00108f28(void*, u64);
void func_00109008(void*);
void func_00109fe8(void*);
void func_0010a1d0(void*);
void func_0010a5f0(void);
u64 func_00109050(void*);  // get_field16_64
void func_00108ae0(void*, u32, u64, u64, u64, u64, u64, u64);
void func_0010a580(void*);
void func_0010a4d0(void);
void func_00108a10(void*);
void func_00109070(void);
}
extern void* D_0033cc78[5];
extern u8 D_00340ed0[3];
extern s32 D_00340ed4;
extern u8 D_00340ed8[];
// Runs the scene passes over the four draw lists (pass id in D_00340ed4).
void ctarget0_0010a618(void) {
    func_00109330();  // set_global_3756_return
    func_00109340();  // to_109450_zero
    func_001344b8(64);
    func_00108998(D_00340ed8);
    func_00108f28(D_00340ed8, (u64)D_00340ed0[0] | ((u64)D_00340ed0[1] << 8) | ((u64)D_00340ed0[2] << 16));
    func_00109008(D_00340ed8);
    if (D_0033cc78[0]) {
        D_00340ed4 = 1;
        func_00109fe8(D_0033cc78[0]);
        D_00340ed4 = 2;
        func_0010a1d0(D_0033cc78[0]);
        func_0010a5f0();
        func_00108ae0(D_00340ed8, 4, 0, 0, func_00109050(D_00340ed8), 0, 0, 0);
    }
    if (D_0033cc78[1]) {
        D_00340ed4 = 3;
        func_00109fe8(D_0033cc78[1]);
        D_00340ed4 = 4;
        func_0010a1d0(D_0033cc78[1]);
        func_0010a5f0();
        func_00108ae0(D_00340ed8, 4, 0, 0, func_00109050(D_00340ed8), 0, 0, 0);
    }
    D_00340ed4 = 5;
    func_00109fe8(D_0033cc78[2]);
    D_00340ed4 = 6;
    func_0010a580(0);
    D_00340ed4 = 7;
    func_00109fe8(D_0033cc78[4]);
    D_00340ed4 = 8;
    func_0010a1d0(D_0033cc78[2]);
    D_00340ed4 = 10;
    func_0010a4d0();
    D_00340ed4 = 11;
    func_0010a1d0(D_0033cc78[4]);
    func_00108a10(D_00340ed8);
    D_00340ed4 = 0;
    func_00109070();
}

extern "C" {
void func_0023e738(void*, s32, s32, s32);  // store_2halfwords_2928
void func_0014b610(u8*, u64);
void func_0014b608(u8*, u64);
void func_0014b5e0(u8*, u32);
void func_0014b220(u8*, s32, s32, s32, s32);
void func_0014b208(u8*, s32, s32);
void func_0014b630(u8*, u32);
void func_0014b618(u8*, u32);
void func_0014b468(u8*, s32, s32);
void func_0014b628(u8*, u64);
}
extern u64 D_00371510;
extern u64 D_00371518;
struct Slot { u8 pad0[48]; u32 f30; u8 pad1[60]; u32 f70; u32 f74; u8 pad2[196]; u8 f13c; u8 pad3[3]; };
struct Work {
    u8 pad0[1632];
    Slot slot[4];
    u8 pad1[2912 - 1632 - 1280];
    u8 kind[4];
    u8 index[4];
    u32 f2920;
    s32 count;
    u8 pad2[16];
    u8 gs0[784];
    u8 gs1[784];
    u8 gs2[784];
    u8 pad3[5296 - 5296];
    u32 a[4];
    u32 b[4];
    u32 c[4];
    u8 flag[3];
};
extern "C" {
// Resets the four slots and sets up the three GS draw contexts.
void func_0023d5b8(Work* w) {
    s32 i;
    for (i = 0; i < w->count; i++) {
        Slot* s = &w->slot[i];
        w->index[i] = i;
        w->kind[i] = 16;
        s->f70 = 0;
        s->f74 = 0;
        s->f30 = 0;
        s->f13c = 0;
        w->a[i] = 0;
        w->b[i] = 0;
        w->c[i] = 0;
        func_0023e738(w, i, 0, 0);  // store_2halfwords_2928
    }
    w->f2920 = 0;
    w->flag[0] = 0;
    w->flag[1] = 0;
    w->flag[2] = 0;
    func_0014b610(w->gs0, 0x31000070);
    func_0014b608(w->gs0, 0x80140);
    func_0014b5e0(w->gs0, 6);
    func_0014b220(w->gs0, 0, 0, 0, 0);
    func_0014b208(w->gs0, 512, 416);
    func_0014b608(w->gs1, 0x80140);
    func_0014b610(w->gs1, 0x131000070ULL);
    func_0014b5e0(w->gs1, 342);
    func_0014b630(w->gs1, 96);
    func_0014b618(w->gs1, 0x30003);
    func_0014b208(w->gs1, 512, 416);
    func_0014b468(w->gs1, 512, 416);
    func_0014b628(w->gs1, D_00371510);
    func_0014b610(w->gs2, 0x131000070ULL);
    func_0014b5e0(w->gs2, 342);
    func_0014b630(w->gs2, 96);
    func_0014b618(w->gs2, 13);
    func_0014b208(w->gs2, 512, 416);
    func_0014b468(w->gs2, 512, 416);
    func_0014b628(w->gs2, D_00371518);
}
}

extern "C" {
void func_0031a838(u8*);
void func_00239700(u8*);
extern u8 D_00347f98[];
extern u8 D_00347e60[];
extern u8 D_00347e40[];
}
static inline void CtorC(u8* q) {
    *(u32*)q = (u32)D_00347f98;
    func_0031a838(q + 12);
    *(u32*)q = (u32)D_00347e60;
    func_00239700(q + 24);
    *(u32*)(q + 408) = 0;
    *(u32*)q = (u32)D_00347e40;
}
static inline void CtorB(u8* q) {
    *(u32*)(q + 12) = 0;
    *(u32*)q = (u32)D_00347e60;
    func_00239700(q + 24);
}
static inline void CtorArr(u8* q) { for (s32 i = 4; i != -1; i--, q += 436) CtorC(q); }
static inline void CtorC2(u8* q) {
    *(u32*)q = (u32)D_00347f98;
    func_0031a838(q + 12);
    *(u32*)q = (u32)D_00347e60;
    func_00239700(q + 24);
    *(u32*)q = (u32)D_00347e40;
    *(u32*)(q + 408) = 0;
}
extern "C" {
// Constructs the member objects (vtable chain A -> B -> C) of a 6.5 KB container.
void func_00323fd8(u8* p) {
    CtorC(p);
    CtorC(p + 436);
    CtorC(p + 872);
    CtorC(p + 1308);
    CtorArr(p + 1744);
    u8* q = p + 3924;
    for (s32 i = 4; i != -1; i--, q += 436) CtorC2(q);
    CtorB(p + 6104);
    CtorB(p + 6512);
}
}

typedef unsigned int u128 __attribute__((mode(TI)));
struct Arg4 { u32 v; };
struct Obj6 { u8 pad[16]; void* f16; void* f20; void* f24; };
extern "C" {
extern u32 D_00352be4, D_00352be8, D_00352bec, D_00352bf0, D_00352bf4, D_00352bf8, D_00352bfc;
union C64 { u64 v; struct { u64 lo : 32; u64 hi : 32; } b; };
extern C64 D_00352c00;
extern u64 D_00352c08, D_00352c10, D_00352c18, D_00352c20, D_00352c28, D_00352c30;
extern u32 D_00352c40, D_00352c44;
extern u8 D_00352c48[], D_00353e48[], D_00354248[];
extern Obj6 D_01d9e6b8;
extern Obj6* D_01d9e6e4;
extern u32 D_01d9ea9c, D_01d9eaa0;
extern u8 D_01d9ea40[];
union QU { u128 q; f32 f[4]; };
extern QU D_01d9ea80;
struct NoTail { ~NoTail() {} };
void func_001e2bc8(u32, u32, u32, u32);
void func_001e7650(Obj6*, u32, u32);
void func_002f4000(void*);  // vu_store_w_splat
void func_001e2b50(u32, u32);
void func_001e5fd8(void);
// Stores the draw parameters into the global state block, then resets and starts the pass.
void func_001e6d38(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1, u32 t2, u32 t3, Arg4 s0, u32 s1, u32 s2, u64 c,
                      u64 d0, u64 d1, u64 d2, u64 d3, u64 d4, u64 d5) {
    NoTail nt;
    D_00352c00.v = c;
    D_00352be4 = t0;
    D_00352be8 = t1;
    D_00352bec = t2;
    D_00352bf0 = t3;
    D_00352bf4 = s0.v;
    D_00352bf8 = s1;
    D_00352bfc = s2;
    D_00352c08 = d0;
    D_00352c10 = d1;
    D_00352c18 = d2;
    D_00352c20 = d3;
    D_00352c28 = d4;
    *(volatile u64*)&D_00352c30 = d5;
    D_00352c00.b.hi = 0xff000000;
    func_001e2bc8(a0, a1, a2, a3);
    D_01d9ea9c = 0;
    D_00352c40 = a1;
    D_00352c44 = a3;
    func_001e7650(&D_01d9e6b8, a0, a1);
    D_01d9e6b8.f16 = D_00352c48;
    D_01d9e6b8.f20 = D_00353e48;
    D_01d9e6b8.f24 = D_00354248;
    D_01d9e6e4 = &D_01d9e6b8;
    D_01d9eaa0 = 0;
    func_002f4000(D_01d9ea40);  // vu_store_w_splat
    D_01d9ea80.q = 0;
    D_01d9ea80.f[3] = 1.0f;
    func_001e2b50(a2, a3);
    func_001e5fd8();
}
}
struct Bigint { Bigint* next; s32 k, maxwds, sign, wds; u32 x[1]; };
#define Storeinc(a, b, c) (((u16*)a)[1] = (u16)b, ((u16*)a)[0] = (u16)c, a++)
extern "C" {
Bigint* func_00303b70(void* ptr, s32 k);
// newlib mprec.c multiply(): c = a * b
Bigint* func_00303ff8(void* ptr, Bigint* a, Bigint* b) {
    Bigint* c;
    s32 k, wa, wb, wc;
    u32 carry, y, z;
    u32 *x, *xa, *xae, *xb, *xbe, *xc, *xc0;
    u32 z2;

    if (a->wds < b->wds) {
        c = a;
        a = b;
        b = c;
    }
    k = a->k;
    wa = a->wds;
    wb = b->wds;
    wc = wa + wb;
    if (wc > a->maxwds) k++;
    c = func_00303b70(ptr, k);
    for (x = c->x, xa = x + wc; x < xa; x++) *x = 0;
    xa = a->x;
    xae = xa + wa;
    xb = b->x;
    xbe = xb + wb;
    xc0 = c->x;
    for (; xb < xbe; xb++, xc0++) {
        if ((y = *xb & 0xffff) != 0) {
            x = xa;
            xc = xc0;
            carry = 0;
            do {
                z = (*x & 0xffff) * y + (*xc & 0xffff) + carry;
                carry = z >> 16;
                z2 = (*x++ >> 16) * y + (*xc >> 16) + carry;
                carry = z2 >> 16;
                Storeinc(xc, z2, z);
            } while (x < xae);
            *xc = carry;
        }
        if ((y = *xb >> 16) != 0) {
            x = xa;
            xc = xc0;
            carry = 0;
            z2 = *xc;
            do {
                z = (*x & 0xffff) * y + (*xc >> 16) + carry;
                carry = z >> 16;
                Storeinc(xc, z, z2);
                z2 = (*x++ >> 16) * y + (*xc & 0xffff) + carry;
                carry = z2 >> 16;
            } while (x < xae);
            *xc = z2;
        }
    }
    for (xc0 = c->x, xc = xc0 + wc; wc > 0 && !*--xc; --wc)
        ;
    c->wds = wc;
    return c;
}
}
// libgcc unwind-dw2.c (gcc 3.2): extract_cie_info
struct DwCie { u32 length; s32 CIE_id; u8 version; u8 augmentation[1]; };
struct UwFrameState {
    u8 regs[2864];
    u32 pc;
    void* personality;
    s64 data_align;
    u64 code_align;
    u8 retaddr_column;
    u8 fde_encoding;
    u8 lsda_encoding;
    u8 saw_z;
    void* eh_ptr;
};
union Unaligned { void* p; } __attribute__((packed));
extern "C" {
u32 func_002ff3fc(const u8*);  // strlen
const u8* func_00316f38(const u8*, u64*);  // varint64_decode
const u8* func_00316f70(const u8*, s64*);
u32 func_00316e88(u8, void*);  // classify_subtype_c
const u8* func_00316fc8(u8, u32, const u8*, u32*);
static inline const u8* read_encoded_value(void* context, u8 encoding, const u8* p, u32* val) {
    return func_00316fc8(encoding, func_00316e88(encoding, context), p, val);
}
const u8* func_00317140(DwCie* cie, void* context, UwFrameState* fs) {
    const u8* aug = cie->augmentation;
    const u8* p = aug + func_002ff3fc(aug) + 1;
    const u8* ret = 0;
    u64 utmp;

    if (aug[0] == 'e' && aug[1] == 'h') {
        fs->eh_ptr = ((const Unaligned*)p)->p;
        p += sizeof(void*);
        aug += 2;
    }
    p = func_00316f38(p, &fs->code_align);  // varint64_decode
    p = func_00316f70(p, &fs->data_align);
    fs->retaddr_column = *p++;
    fs->lsda_encoding = 0xff;
    if (*aug == 'z') {
        p = func_00316f38(p, &utmp);  // varint64_decode
        ret = p + utmp;
        fs->saw_z = 1;
        ++aug;
    }
    while (*aug != '\0') {
        if (aug[0] == 'L') {
            fs->lsda_encoding = *p++;
            aug += 1;
        } else if (aug[0] == 'R') {
            fs->fde_encoding = *p++;
            aug += 1;
        } else if (aug[0] == 'P') {
            p = read_encoded_value(context, *p, p + 1, (u32*)&fs->personality);
            aug += 1;
        } else
            return ret;
    }
    return ret ? ret : p;
}
}

struct ListCur {
    s16 def_cur;
    u16 pad2;
    s16 rows;
    u8 pad6[12];
    s16 def_top;
    u16 pad20;
    s16 count;
    u8 pad24[12];
    u8 wrap;
};
extern "C" {
s32 func_0028b1c0(ListCur*, s32);  // test_bit_field32
// Moves the cursor up one entry (scrolling / wrapping), skipping entries the check accepts.
s32 func_00289d28(ListCur* o, s16* cur, s16* top) {
    s32 n = o->count;
    s32 lim = n;
    if (o->rows < n) lim = o->rows;
    u32 all = 0;
    s32 idx;
    for (s32 i = 0; i < n; i++) all |= 1 << i;
    u32 seen = 0;
    while (seen != all) {
        if (o->rows >= o->count) {
            if (*cur > 0) (*cur)--;
            else if (o->wrap) *cur = lim - 1;
        } else {
            if (*cur > 0) (*cur)--;
            else if (*top > 0) (*top)--;
            else if (o->wrap) {
                *top = o->count - o->rows;
                *cur = o->rows - 1;
            }
        }
        idx = *top + *cur;
        if (!func_0028b1c0(o, idx)) break;
        seen |= 1 << idx;
    }
    if (seen == all) {
        *cur = o->def_cur;
        *top = o->def_top;
        idx = *top + *cur;
    }
    return idx;
}
}

struct JmSrc { u8 pad[18]; u16 f18; u16 f20; };
extern "C" {
extern u32 D_004f63a0;
extern u8 D_0032f054;
extern s32 D_00350cd0;
u32 func_001d1438(u32);
u32 func_0017df70(s32);
u32 func_00198040(s32);
u32 func_0016eb18(u32, s32);
JmSrc* func_001a8b28(void);  // get_data_1c7cc10
u32 func_0017dfc8(s32);
void* func_001d3408(u32);
void* GetCharaData_0016e920(u32 id) asm("_ZN2Tz6JmInfo12GetCharaDataEj");
// Maps special chara ids (story-dependent) to their data entry.
void* GetCharaData_0016e920(u32 id) {
    u32 r = id;
    switch (id & 0xfffffff) {
    case 566:
        {
            u32 t = D_004f63a0;
            if (t) { r = t; break; }
        }
    case 571:
        r = func_001d1438(D_0032f054);
        if (!r) r = func_001d1438(0);
        break;
    case 567: r = func_0017df70(1); break;
    case 568: r = func_0017df70(2); break;
    case 572: r = func_00198040(1); break;
    case 573: r = func_0016eb18(566, 0); break;
    case 575: r = func_0016eb18(func_001a8b28()->f18, 0); break;
    case 576: r = func_0016eb18(func_001a8b28()->f20, 0); break;
    case 704: r = func_0016eb18(101, 0); break;
    case 793: r = func_0017dfc8(1); break;
    case 794: r = func_0017dfc8(2); break;
    case 1006: r = func_0017dfc8(3); break;
    case 1578: r = D_00350cd0 == 1035 ? 1036 : 1035; break;
    case 1579: r = D_00350cd0 == 1035 ? 1035 : 1036; break;
    }
    if (r == 0) return 0;
    return func_001d3408(r & 0xfffffff);
}
}

struct JmEnt { u32 id; u8 type; u8 pad[82]; s8 f87; };
extern "C" {
extern u32 D_004f63a0;
extern u32 D_004f63a8;
extern u32 D_004f63ac;
extern u8 D_0032f054;
u32 func_001d1438(u32);
s32 func_0016f6f8(u32);  // check_flag_4000_type
s32 func_0016f770(u32);  // in_id_special_range
u32 func_0016eb48(u32, u32, u32, s32);
u32 func_0016ef28(u8);
}
// Requests chara data for id (special ids map to story-dependent entries); returns the request result.
u32 wtarget_0016ed50(u32 id, u32 kind, u32 mode, u32) {
    switch (id) {
    case 568: return func_0016eb48(id, kind, 6, -1);
    case 567: return func_0016eb48(id, kind, 5, -1);
    case 566:
        if (D_004f63a0) {
            return func_0016eb48(D_004f63a0, kind, 4, -1);
        } else {
            JmEnt* e = (JmEnt*)GetCharaData_0016e920(func_001d1438(0));
            u32 r = func_0016eb48(e->id, kind, 4, 7);
            if (e->f87 < 7 && D_0032f054) return func_0016ef28(D_0032f054);
            return r;
        }
    case 793: return func_0016eb48(0x20000237, kind, 5, -1);
    case 794: return func_0016eb48(0x20000238, kind, 6, -1);
    }
    if (!func_0016f6f8(id) && !func_0016f770(id) && mode == 30) {  // check_flag_4000_type
        JmEnt* e = (JmEnt*)GetCharaData_0016e920(id);
        if (!e) return;
        switch (e->type) {
        case 1: mode = 5; break;
        case 0: D_004f63a0 = id; mode = 4; break;
        case 19: mode = 7; break;
        }
    }
    switch (kind) {
    case 2410: D_004f63a8 = id; break;
    case 2420: D_004f63ac = id; break;
    }
    func_0016eb48(id, kind, mode, -1);
}

#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV {
    f32 x, y, z, w;
    QV() {}
    QV(const QV& o) { QCOPY(this, &o); }
    QV& operator=(const QV& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline QV ScaleQ(const QV& a, f32 k) {
    QV r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
static inline void ScaleQIn(QV* a, f32 k) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(a), "f"(k) : "$8", "memory");
}
struct CamP { f32 f0, f4, f8, f12, f16, f20, f24; };
struct CamIn { u8 pad[12]; f32 f12; };
extern "C" {
extern void* D_00361f60;
extern f32 D_00349e10;
s32 func_002d5cc8(void*);
CamP* func_002d1878(void*);
QV func_002d4f60(void*);
QV func_002d2740(void*, void*, f32, f32);
// Camera target: clamps the follow distance, refreshes the target vector and returns it scaled.
QV func_002d6b30(CamIn* in, u8* o) {
    void* w = D_00361f60;
    QV r;
    if (func_002d5cc8(o)) {
        CamP* a = func_002d1878(w);
        CamP* b = func_002d1878(w);
        CamP* c = func_002d1878(w);
        f32 d = a->f16 - b->f20 * in->f12;
        if (d < c->f24) d = c->f24;
        QV* v16 = (QV*)(o + 16);
        *v16 = func_002d4f60(o);
        *(f32*)(o + 28) = d;
        r = *v16;
        ScaleQIn(&r, r.w * D_00349e10);
        in->f12 += D_00349e10;
        *(QV*)(o + 32) = ScaleQ(*v16, *(f32*)(o + 28));
    } else {
        CamP* a = func_002d1878(w);
        CamP* b = func_002d1878(w);
        r = func_002d2740(w, o, a->f8, b->f12);
        in->f12 = 0.0f;
    }
    r.z = 0.0f;
    r.w = 1.0f;
    return r;
}
}

struct Ent8 { u8 f0, f1, f2, f3; u16 f4, f6; };
struct EntTbl { Ent8 list[512]; Ent8 sub[15]; s32 count; s32 active; };
struct ItemRec { u8 f0, f1; u16 id; u8 pad4; u8 f5; };
struct ItemDef { u8 f0, f1, type; };
extern "C" {
union TblPtr { EntTbl* p; u32 w; u16 h; u8 b; };
extern TblPtr D_0035f5e4;
u32 func_00276c18(void);
void func_002fde18(void*, s32, s32);
ItemRec* func_001a82b0(ItemRec*);
ItemDef* func_001a80c8(u16);  // table24_find_by_id
s32 func_002a43b0(ItemRec*);
u8 func_002764b0(u8);
void func_002a2ff8(void);
s32 func_002ab8e8(s32);
s32 func_002ab9c8(s32);
// Rebuilds the item list table (entries of type 22) and refreshes the 15 slot flags.
void func_002a2c40(void) {
    ItemRec* it = 0;
    s32 idx = 0;
    s32 n = 0;
    s32 cnt = 0;
    u32 all = func_00276c18();
    func_002fde18(D_0035f5e4.p, 0, 4316);
    for (;;) {
        it = func_001a82b0(it);
        if (!it) break;
        if (func_001a80c8(it->id)->type == 22) {  // table24_find_by_id
            s32 r = func_002a43b0(it);
            if (r || all) {
                u8 v = func_002764b0(it->f5);
                D_0035f5e4.p->list[n].f0 = v;
                if (r) cnt++;
                D_0035f5e4.p->list[n].f4 = idx;
                D_0035f5e4.p->list[n].f6 = it->id;
                D_0035f5e4.p->list[n].f1 = r != 0;
                n++;
            }
        }
        idx++;
    }
    D_0035f5e4.p->count = n;
    D_0035f5e4.p->active = cnt;
    func_002a2ff8();
    for (s32 i = 0; i < 15; i++) {
        Ent8* e = (Ent8*)(i * 8 + (u32)D_0035f5e4.p + 4096);
        if (e->f0 == 0) {
            e->f2 = 0;
            D_0035f5e4.p->sub[i].f3 = 0;
        } else {
            e->f2 = func_002ab8e8(i) != 0;
            D_0035f5e4.p->sub[i].f3 = func_002ab9c8(i) != 0;
        }
    }
}
}

struct ReqObj { u32 f0; u32 f4; u32 f8; u32 f12; };
struct SysA { u32 f0; u32 f4; };
struct Tbl16 { u8 pad[16]; u16 v[1]; };
extern "C" {
extern u8 D_0035f4f8;
extern void* D_0035f4f4;
void* func_001a8bd0(s32);
void func_00170320(s32);
s32 func_001a8bf8(void*, s32);  // get_bits5_at
void func_001a8ff8(void*, s32, s32);  // swap_bytes
s32 func_00253598(void);
SysA* func_00103eb0(void);
ReqObj* func_00102818(u32, s32, s32, void*, s32);
u32 func_001a8c10(void*, s32);
u32 func_0017e668(u32);
void func_00293b08(void);
// Starts the party-change request once (flag D_0035f4f8) when the slot setup differs.
u8 func_00293948(void) {
    void* cur = func_001a8bd0(-1);
    if (D_0035f4f8) return D_0035f4f8;
    func_00170320(5100);
    D_0035f4f8 = 1;
    if (func_001a8bf8(cur, 1) != func_001a8bf8(D_0035f4f4, 1) && func_001a8bf8(cur, 2) != func_001a8bf8(D_0035f4f4, 2))
        func_001a8ff8(cur, 1, 2);  // swap_bytes
    s32 k = func_001a8bf8(cur, 3);  // get_bits5_at
    if (k != 18) {
        s32 i;
        for (i = 0; i < 4; i++) {
            if (i != 0 && func_001a8bf8(D_0035f4f4, i) == k) break;
        }
        if (i != 3) {
            if (func_00253598()) {
                ReqObj* o = func_00102818(func_00103eb0()->f4, 0, 0x222e0, (void*)func_00293b08, 6144);
                Tbl16* t = (Tbl16*)func_001a8b28();  // get_data_1c7cc10
                u16 v = t->v[func_001a8bf8(func_001a8bd0(-1), 3)];
                o->f4 = func_0017e668(func_001a8c10(func_001a8bd0(-1), i));
                o->f8 = v;
                o->f12 = func_001a8c10(func_001a8bd0(-1), i);
            } else {
                func_001a8ff8(cur, i, 3);  // swap_bytes
            }
        }
    }
    return D_0035f4f8;
}
}

struct IdList { u8 pad[5]; s8 count; u8 pad6[2]; s16 ids[1]; };
extern "C" {
extern IdList* D_0035f5ac;
u8* func_00294000(s32);
s32 func_00276638(s32);
s32 func_00276620(s32);
s32 func_002943b0(u8*);  // test_bit_global_array
void func_002765e8(s32, s32, s32);
void func_0029eaa8(void);
// Moves the list cursor to the next/previous usable entry (wrapping) and scrolls the 10-row window.
void func_0029cb28(s32 dir) {
    u8* base = func_00294000(3) + 16;
    s32 cur = func_00276638(15);
    s32 top = func_00276620(15);
    s32 i;
    if (dir == -10) {
        for (i = cur + 1; i < D_0035f5ac->count; i++)
            if (func_002943b0(base + D_0035f5ac->ids[i] * 36)) break;
        if (i >= D_0035f5ac->count) {
            for (i = 0; i < cur; i++)
                if (func_002943b0(base + D_0035f5ac->ids[i] * 36)) break;
        }
        if (i < D_0035f5ac->count) {
            cur = i;
        } else {
            cur = 0;
            top = 0;
        }
    } else {
        for (i = cur - 1; i >= 0; i--)
            if (func_002943b0(base + D_0035f5ac->ids[i] * 36)) break;
        if (i < 0) {
            for (i = D_0035f5ac->count - 1; cur < i; i--)
                if (func_002943b0(base + D_0035f5ac->ids[i] * 36)) break;
        }
        cur = i;
        if (i < 0) {
            cur = D_0035f5ac->count - 1;
            top = D_0035f5ac->count - 11;
        }
    }
    if (cur - top >= 10) top += cur - top - 9;
    else if (cur - top < 0) top += cur - top;
    func_002765e8(15, cur - top, top);
    func_0029eaa8();
}
// Moves the list cursor to the next/previous usable entry (wrapping) and scrolls the 10-row window.
}

extern "C" {
extern u32 D_0035ef64, D_0035ef68, D_0035ef6c, D_0035f03c;
u8* func_00257770(void);
s32 func_00139d78(u8*);
void func_0028d8c0(u8*, s32, u32, u32, u32, s32, s32, s32);
void func_0028d980(u8*, s32, u32, u32, u32, s32, s32, s32, s32);
s32 func_0023aa98(u8*);
s32 func_0023aa78(u8*);
void func_00138c10(u8*, u32);
void func_00138c68(u8*, s32, s32);
void func_0028dcc0(u8*, u8*);
void func_00139688(u8*);
void func_00139620(u8*);
s32 func_00257140(s32);
void func_001395f8(u8*);
// Builds the 20 grid cells (2 columns) of the window and their labels.
void func_00261b30(void) {
    u8* w = func_00257770();
    func_00139d78(w);
    func_0028d8c0(w, 30013, D_0035ef68, D_0035ef64, D_0035f03c, 140, 141, 100);
    u8* p = w;
    s32 i = 0;
    do {
        u8* cell = p + 13840;
        func_0028d980(cell, 30014, D_0035ef68, D_0035ef64, D_0035f03c, 150, -1, -1, 100);
        u8* label = p + 24304;
        s32 h = func_0023aa98(p + 13864);
        s32 wd = func_0023aa78(p + 13864);
        p += 436;
        func_00138c10(cell, D_0035ef6c);
        func_00138c68(cell, (i % 2) * h, (i / 2) * wd);
        func_0028dcc0(cell, w);
        func_00139688(cell);
        func_00139620(cell);
        func_0028d980(label, 30015, D_0035ef68, D_0035ef64, D_0035f03c, func_00257140(0), -1, -1, 100);
        func_0028dcc0(label, cell);
        func_00139620(label);
        func_001395f8(label);
        i++;
    } while (i < 20);
}
}

extern "C" {
extern s8 D_0035ed44;
extern u8* D_0035ed34;
extern void* D_0035ed20;
extern u32 D_0035ed28;
extern s32 D_0035f3d4;
s32 func_0028afa8(void*);
u8* func_002891b8(void*, s32);
s32 func_002469a0(s32);
void func_0028dcc0(u8*, u8*);
void func_00139648(u8*);
s32 func_0023aa18(u8*);
s32 func_0023aa38(u8*);
void func_00138c68(u8*, s32, s32);
void func_00247c20(void);
}
extern "C" {
// Re-creates the enabled entry widgets of the list (bit per entry in D_0035ed44).
void func_00247a20(void) {
    if (!D_0035ed44) return;
    if (func_00139d78(D_0035ed34)) return;
    s32 id = D_0035f3d4 + 1;
    s32 n = func_0028afa8(D_0035ed20);
    for (s32 i = 0; i < n; i++) {
        u8* nd = func_002891b8(D_0035ed20, i);
        u8* sub = nd + 24;
        s32 m = D_0035ed44;
        u8 on = (m >> func_002469a0(i)) & 1;
        if (on) {
            func_0028d8c0(D_0035ed34 + i * 408, id, 0, 0, D_0035ed28, 83, -1, 0);
            func_0028dcc0(D_0035ed34 + i * 408, nd);
            func_00139648(D_0035ed34 + i * 408);
            s32 x = func_0023aa18(sub);
            s32 y = func_0023aa38(sub);
            func_00138c68(D_0035ed34 + i * 408, x, y);
        }
    }
    func_00247c20();
}
}

struct V4r { f32 x, y, z, w; } __attribute__((aligned(16)));
struct M4r { V4r r[4]; };
struct Model {
    u8 pad0[48];
    V4r rows[4];
    u8 pad112[12];
    f32 scale;
    f32 off[3];
    u8 pad140[3];
    u8 noOffset;
    u8 pad144[20];
    f32 size;
};
struct DrawSrc { Model* model; u32 tex; u8 data[1]; };
struct DrawArg { DrawSrc* src; u32 color; void* mtx; f32 len; u16 div; u16 h; f32* scl; };
struct DrawReq {
    u32 tex;
    u32 data;
    u8 pad8[10];
    u16 id;
    union { u32 color; u8 c[4]; };
    u32 f24;
    u16 f28;
    u16 f30;
    M4r* mtx;
    u8 pad36[8];
    u32 f44;
    u8 pad48[16];
};
extern "C" {
extern Model D_01d9e360;
struct CamBlk { u8 pad[48]; f32 pos[3]; };
extern CamBlk D_01d9e840;
void func_002f3f88(V4r*, V4r*);  // memcpy16
void func_002f3f40(V4r*, V4r*, f32);  // vec_scale_by_f12
void func_002f3d08(M4r*, void*, M4r*);
void func_0021efc0(DrawReq*);
void func_0021f060(DrawReq*);
// Builds a billboard matrix from the model rows (scaled by size/length) and queues the draw request.
void func_0021fbd8(DrawArg* a, u32 id) {
    M4r m;
    DrawReq req;
    DrawSrc* src = a->src;
    Model* md = src->model;
    if (md == &D_01d9e360) return;
    if (!src->tex) return;
    if (md->scale == 0.0f) return;
    func_002f3f88(&m.r[0], &md->rows[1]);  // memcpy16
    func_002f3f88(&m.r[1], &md->rows[2]);  // memcpy16
    func_002f3f88(&m.r[2], &md->rows[3]);  // memcpy16
    func_002f3f88(&m.r[3], &md->rows[0]);  // memcpy16
    f32 k = a->len * md->size / (f32)a->div;
    func_002f3f40(&m.r[0], &m.r[0], -k);  // vec_scale_by_f12
    func_002f3f40(&m.r[1], &m.r[1], k);  // vec_scale_by_f12
    if (!md->noOffset) {
        m.r[3].x = D_01d9e840.pos[0] + md->off[0];
        m.r[3].y = D_01d9e840.pos[1] + md->off[1];
        m.r[3].z = D_01d9e840.pos[2] + md->off[2];
    }
    func_002f3f40(&m.r[0], &m.r[0], a->scl[0]);  // vec_scale_by_f12
    func_002f3f40(&m.r[1], &m.r[1], a->scl[1]);  // vec_scale_by_f12
    func_002f3f40(&m.r[2], &m.r[2], a->scl[2]);  // vec_scale_by_f12
    func_002f3d08(&m, a->mtx, &m);
    req.color = a->color;
    k = md->size / (f32)a->h;
    f32 lim = 1.0f;
    if (!(lim < k)) lim = k;
    req.c[3] = (s32)(req.c[3] * md->scale * lim);
    req.tex = src->tex;
    req.data = (u32)src->data;
    func_0021efc0(&req);
    req.id = id;
    req.mtx = &m;
    req.f44 = 0;
    req.f24 = 0;
    req.f28 = 0;
    req.f30 = 0;
    func_0021f060(&req);
}
}

#define QCPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QP {
    f32 x, y, z, w;
    QP() {}
    QP(const QP& o) { QCPY(this, &o); }
    QP& operator=(const QP& o) {
        if (this != &o) QCPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct Sph {
    s32 type;
    f32 r0, r1;
    s32 f12;
    QP c;
    Sph(const QP& p, f32 r) : type(3), r0(r), r1(r), f12(0), c(p) {}
};
struct HitShape { u8 pad[32]; };
struct ActSub { u8 pad[20]; s32 state; };
struct Actor { u8 pad[320]; ActSub sub; u8 pad344[1072]; u32 flags; };
struct HitCtx { u8 pad[36]; s32 mode; };
extern "C" {
extern u32 D_00352bd0;
s32 func_0019ba60(Actor*);
const QP& func_001e0cc8(HitCtx*);  // entry64_by_field32
u32 func_0016bc20(Actor*, s32, s32);
void func_0018a818(HitShape*, Actor*, u32);
s32 func_0018a550(Sph*, HitShape*);  // state_dispatch_0_1_3
s32 func_00180618(ActSub*);
void func_001e2660(u32, QP*);
void func_002bc188(u32, QP*);
void func_001e1070(HitCtx*, Actor*);
void func_001e23b0(u32, QP*);
// Hit check around the context position: big sphere vs downed actor (state 254-256), else small sphere.
s32 func_001e1350(HitCtx* c, Actor* o) {
    if (o && func_0019ba60(o)) {
        QP pos;
        pos = func_001e0cc8(c);  // entry64_by_field32
        Sph near(pos, 50.0f);
        Sph far(pos, 200.0f);
        HitShape sh;
        func_0018a818(&sh, o, func_0016bc20(o, 1, -1));
        if (func_0018a550(&far, &sh)) {  // state_dispatch_0_1_3
            ActSub* q = &o->sub;
            if (q->state == 254) goto down;
            if (q->state == 255) goto down;
            if (q->state != 256) goto skip;
        down:
            if (!func_00180618(q)) {
                func_001e2660(D_00352bd0, &pos);
                if (o->flags & 0x80) func_002bc188(0x5b531, &pos);
                else func_002bc188(0x5b532, &pos);
                c->mode = 6;
                return 1;
            }
        }
    skip:
        if (func_0018a550(&near, &sh)) {  // state_dispatch_0_1_3
            func_001e1070(c, o);
            func_001e23b0(D_00352bd0, &pos);
            func_002bc188(0x5b51f, &pos);
            c->mode = 6;
            return 1;
        }
    }
    return 0;
}
}
