#include "../common/types.h"

extern "C" {

void func_00103ea0(s32);  // set_hook_ptr
void func_00103500(s32);
void func_00103c70(void);  // clear_hook_ptr
void func_00103e78(void);
void func_0023ed90(void);  // set_global_byte1
u8 func_001384c0(void);  // get_global_347e08
void func_001031d0(void);
void func_00103100(void);
struct S32b9e8 { u8 pad[0x20]; void* f20; void* f24; };
extern S32b9e8 D_0032b9e8;
extern u8 D_0032ba28;
extern s32 D_0032ba20;
extern u8 D_0032ba1c;

void func_00103480(void) {
    D_0032ba28 = 0;
    func_00103ea0(0);  // set_hook_ptr
    D_0032b9e8.f20 = (void*)func_00103100;
    D_0032b9e8.f24 = (void*)func_001031d0;
    func_00103500(-1);
    func_00103c70();  // clear_hook_ptr
    func_00103e78();
    func_0023ed90();  // set_global_byte1
    D_0032ba20 = -1;
    D_0032ba1c = func_001384c0();  // get_global_347e08
}

void func_0014b290(u8*);
extern void* D_00349da8[];
extern u64 D_0036b0e0;
// Constructor: two GIF-tag style 4-qword blocks at +0x100.
void func_0014ba90(u8* p) {
    func_0014b290(p);
    u64 d = D_0036b0e0;
    *(void**)p = D_00349da8;
    *(u64*)(p + 288) = 0x1000000000008001ULL;
    *(u64*)(p + 296) = 14;
    *(u64*)(p + 304) = d;
    *(u64*)(p + 312) = 64;
    *(u64*)(p + 256) = 0x1000000000008001ULL;
    *(u64*)(p + 264) = 14;
    *(u64*)(p + 272) = d;
    *(u64*)(p + 280) = 64;
}

struct S15b { u8 pad[436]; f32 f; };
union U15b { S15b* p; f32 f; };
extern s32 D_0034aa98;
extern U15b D_0034aa9c;
void func_0015ad80(S15b*, u32);
void func_0015aea8(S15b*, u32);
void func_0015b268(u32 a, f32 f) {
    if (D_0034aa98 == 0) {
        func_0015ad80(D_0034aa9c.p, a);
        D_0034aa98++;
    } else {
        D_0034aa9c.p->f = f;
        func_0015aea8(D_0034aa9c.p, a);
    }
}

void func_001666d0(u8*, u16, u32, u16, u16);
void func_00166968(u8* p, u8 b, u16 c, u32 d, u16 e, u16 g, s16 h, s16 i) {
    func_001666d0(p, c, d, e, g);
    p[14] = b;
    *(s16*)(p + 10) = h;
    *(s16*)(p + 12) = i;
}

struct E168 { u16 id; u16 pad; s32 val; u32 x, y; };
struct T168 { u32 f0; s32 count; u32 f8, fc; E168 e[1]; };
// Counts entries matching (id, val); id -1 matches any id.
void func_00168ad8(T168* t, s32* out, s32 id, s32 v) {  // scan_entries_to_out
    *out = 0;
    for (s32 i = 0; i < t->count; i++) {
        if ((id == -1 || t->e[i].id == id) && t->e[i].val == v) (*out)++;
    }
}

u8* func_001b9bc8(u8*);
u32 func_0016a020(u8*);
s32 obj_count_entry(u32 id) asm("_ZN2YS3OBJ10CountEntryEj");
// Counts objects whose entry id equals id.
s32 obj_count_entry(u32 id) {
    u8* o = 0;
    s32 n = 0;
    while ((o = func_001b9bc8(o)) != 0)
        if (func_0016a020(o) == id) n++;
    return n;
}

extern s32 D_01c5f478;
s32 func_00170d38(s32 x) {
    if (x == 1010) return 1;
    if ((u32)(x - 2300) < 100) return 2;
    if ((u32)(x - 2410) < 10) return 3;
    if ((u32)(x - 2420) < 10) return 4;
    if ((u32)(x - 5000) < 100) return 5;
    if ((u32)(x - 5100) < 100 && D_01c5f478 > 0) return 6;
    return 0;
}

u8* func_001050d8(u32);
void func_002ee220(u8*);
void func_002ee5d8(u8*, u32);
void func_002edfa8(u8*, u8*);
extern void* D_0034e888[];
void func_00175370(u32* a) {
    u8* o = func_001050d8(4736);
    u32 v = *a;
    func_002ee220(o);
    *(void**)o = D_0034e888;
    func_002ee5d8(o + 36, v);
    func_002edfa8(o, o + 36);
}

s32 func_00181a70(u32, u32);
u32* func_00189068(u32, u32);
// Increments a counter, saturating at 9999.
void func_001890a8(u32 a, u32 b) {
    if (func_00181a70(a, b)) {
        u32* c = func_00189068(a, b);
        if (c && *c < 9999) (*c)++;
    }
}

union U195 { u8* p; f32 f; };
extern U195 D_00352130;
void func_001957e8(f32* p) {
    p[0] = 2.0f;
    p[1] = 8.0f;
    p[2] = 160.0f;
    p[3] = 0.19634955f;
    p[4] = *(f32*)(D_00352130.p + 20);
    p[6] = 0.95f;
    p[5] = 0;
    p[7] = 0;
    p[8] = 0;
}

bool func_0013ef80(void);  // get_global_byte_358700
u8* func_0014aba8(void);
bool func_00197c28(u8* p) {
    s32 t = (*(u8**)(p + 60))[1];
    switch (t) {
    case 1: case 2: return *(s32*)(func_0014aba8() + 252) != 4;
    case 3: return !func_0013ef80();  // get_global_byte_358700
    }
    return 0;
}

void func_00197930(u32, u32, u8*);
void func_0019f070(u8*, u32);
u8 func_0019f060(u8*);
s32 func_00199030(u8* p) {
    if (p[48]) return 1;
    if (*(u32*)(p + 16)) {
        func_00197930(*(u32*)(p + 16), *(u32*)(p + 20), p + 52);
        return 1;
    }
    func_0019f070(p + 52, 0);
    return func_0019f060(p + 52);
}

s32 func_001ab820(u32);
f32 func_00192fb8(u32*);  // mul_float4x8
// Picks a 16-byte table entry by rounding count * ratio.
u8* func_001aa310(u32 a0, u32* a, u8* tbl) {
    f32 s = (f32)func_001ab820(*a);
    return tbl + (s32)(s * func_00192fb8(a + 8) + 0.5f) * 16;
}

void func_001b3b70(u8*, u32, u32, u32);
extern void* D_00350910[];
struct B600 { u32 lo : 3; u32 m : 4; u32 rest : 25; };
void func_001a6b58(u8* p, u32 a, u32 b) {
    func_001b3b70(p, a, 4, b);
    *(void**)p = D_00350910;
    *(u32*)(p + 1416) |= 0x100;
    *(u32*)(p + 944) = 3;
    ((B600*)(p + 1536))->m = 1;
    *(u32*)(p + 2748) |= 4;
}

struct S1bb { u32 f0; u32 flags; };
union U1bb { S1bb* p; u32 w; };
extern U1bb D_01d49320;
extern u32 D_0034f240;
void func_0014ca20(void);
void func_001d6c58(void);
void func_001c11a8(u32);
void func_001c1130(u32);  // copy_record_block_to_table
void func_001af9f8(void);
void func_001bb890(void) {
    D_01d49320.p->flags |= 4;
    D_01d49320.p->flags |= 0x10;
    func_0014ca20();
    D_0034f240 |= 2;
    func_001d6c58();
    func_001c11a8(8);
    func_001c1130(5);  // copy_record_block_to_table
    func_001af9f8();
}

void func_001d5f30(u8*, u32);
void func_001d6148(u8* p, s32 id) {
    if (*(s32*)(p + 2896) == 3) {
        switch (id) {
        case 686: case 700: case 703: case 706:
            func_001d5f30(p, 1);
        }
    }
}

u8* func_001d7980(u32);
// ORs together the flags of up to four referenced entries.
void func_001d7b10(u16* p) {
    *p = 0;
    u32* e = (u32*)(p + 2);
    for (s32 i = 3; i >= 0; i--, e += 2) {
        if (*e) *p |= *(u16*)(func_001d7980(*e) + 2);
    }
}

s32 func_001bb4b0(void);
s32 func_001bb4a0(void);
u8* func_001bbcb0(void);
void func_001d8718(s32, s32);
struct MissionFlag { u32 on : 1; u32 rest : 31; };
static inline bool mission_entry_on(s32 i) {
    u8* b = func_001bbcb0();
    u32 off = i * 56;
    return ((MissionFlag*)(b + off + 244))->on;
}
void mission_add_count(s32 a, s32 i) asm("_ZN2YS7MISSION8AddCountEii");
void mission_add_count(s32 a, s32 i) {
    if (func_001bb4b0() && mission_entry_on(i))
        func_001d8718(a, i);
}
s32 mission_get_count(s32 i) asm("_ZN2YS7MISSION8GetCountEi");
s32 mission_get_count(s32 i) {
    if (func_001bb4a0()) {
        if (mission_entry_on(i)) return *(s32*)(i * 56 + func_001bbcb0() + 276);
    }
    return 0;
}

s32 func_0019ba60(u32);
u8* func_0016c028(u32);  // obj_get_attach_or_alt
void func_001dbcd0(void);
void func_001c2578(u32);
extern u32 D_0034e948;
extern u8 D_00352a60[];
void func_001dbad0(u32 a) {
    if (func_0019ba60(D_0034e948)) {
        u8* v = func_0016c028(D_0034e948);  // obj_get_attach_or_alt
        if (v != D_00352a60)
            asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(D_00352a60), "r"(v) : "$8", "memory");
    }
    func_001dbcd0();
    func_001c2578(a);
}

extern s32 D_00359780;
extern s32 D_00359788[];
extern s32 D_00359808;
extern s32 D_00359810[];
// Stack allocator push: returns the current top and records top + size.
s32 func_0020eaf8(s32 size) {
    s32 i = D_00359780;
    if (i < 31) {
        s32 cur = D_00359788[i];
        s32 end = cur + size;
        if (!(D_00359810[D_00359808] < end)) {
            D_00359780 = ++i;
            D_00359788[i] = end;
            return cur;
        }
    }
    *(s32*)0 = 0;
    return 0;
}

struct F239 { u32 b0 : 1; u32 b1 : 1; u32 rest : 30; };
void func_00239f18(u8* p, f32 f) {  // obj_set_float312_and_flags
    *(f32*)(p + 312) = f;
    ((F239*)(p + 184))->b1 = !(*(f32*)(p + 308) == 1.0f && f == 1.0f && *(f32*)(p + 316) == 1.0f);
}

union U241 { u32 w; u8 b; };
struct E241 { U241 f; u8 pad[28]; };
struct T241 { s8 f0; s8 start; u8 pad[6]; E241 e[99]; };
extern T241* D_0035ec94;
static inline bool e241_off(E241* e) { return !(e->f.b & 1); }
// First entry from start that is enabled and not busy, or -1.
s32 func_002413f0(void) {  // find_next_free_slot
    T241* t = D_0035ec94;
    s32 i;
    for (i = t->start; i < 99; i++) {
        if (e241_off(&t->e[i])) continue;
        if (!(t->e[i].f.w & 2)) break;
    }
    return i < 99 ? i : -1;
}

u32 func_002416d8(u32);
void func_002346c0(s32, u32, u32, u32, u32);
extern u32 D_0035ec88;
extern u32 D_0035ec90;
void func_002415a0(u32 a, u32 b, u32 c) {
    u32 v = func_002416d8(a);
    T241* t = D_0035ec94;
    u32 bb = b ? b : D_0035ec88;
    u32 cc = c ? c : D_0035ec90;
    func_002346c0(t->f0, bb, cc, v, 0);
}

u8* func_001058e8(void);
s32 func_00242bd0(void);
s32 func_00242b58(void);
void func_00242b88(u32);
struct F242 { u32 lo : 5; u32 b5 : 1; u32 rest : 26; };
void func_00242c00(u8 a) {
    u8* v = func_001058e8() + 16800;
    ((F242*)(v + 4))->b5 = a == 0;
    if (!func_00242bd0() && !func_00242b58()) func_00242b88(1);
}

u32 func_00257770(void);
s32 func_00287bc0(void);
void func_0028dac8(u32, u32);
s32 func_0028acc8(u32);
s32 func_0028acb8(u32);
void func_0028aa40(u32);
extern u32 D_0035f01c;
void func_00271e08(void) {
    u32 s = func_00257770();
    if (func_00287bc0() == 25) {
        func_0028dac8(s, 142);
        if (func_0028acc8(D_0035f01c) && !func_0028acb8(D_0035f01c)) func_0028aa40(D_0035f01c);
    }
}

u32 func_00257140(u32);
void func_00138c10(u8*, u32);
u16* func_00273180(u32, s32);  // state_dispatch_2_3
u32 func_00192048(u16);
void func_00272a70(void) {
    u8* s = (u8*)func_00257770() + 24740;
    for (s32 i = 0; i < 3; i++, s += 436) {
        func_00138c10(s, func_00257140(0));
        *(u32*)(s + 408) = func_00192048(*func_00273180(4, i));
    }
}

struct VObj28 { struct VT { u32 (*f0)(VObj28*, u32, u32); }* vt; };
struct G28 { u8 pad[20]; VObj28* o; };
extern G28* D_00347f80;
void func_0028dfe8(u32);  // obj_ctor_36f440
void func_0028b940(u32* p) {
    VObj28* o = D_00347f80->o;
    u32 v = o->vt->f0(o, 60, 0);
    func_0028dfe8(v);  // obj_ctor_36f440
    p[0] = v;
    p[1] = 0;
    p[8] = 0;
    p[9] = 0;
    p[10] = 0;
    p[11] = 0;
    p[12] = 0;
}

s32 func_0028be58(u32);
s16 func_0028e4c8(u32, u32);
void func_0028e560(u32, void*, u32, s32);
void lead_data_leave(u32 a) asm("_ZN2Tz13LeadDataLeaveEj");
void lead_data_leave(u32 a) {
    u32* s = (u32*)a;
    if (func_0028be58(a)) {
        if (func_0028e4c8(s[0], 0) != *(s16*)(s + 4)) func_0028e560(s[0], s + 4, 4, -1);
    }
}

u8* func_001a80c8(u32);  // table24_find_by_id
extern s8 D_00374488[];
// Is the item's kind byte in the -1 terminated list?
s32 func_002914a8(u32 a0, u32 a1) {
    s32 r = 0;
    u8* v = func_001a80c8(a1);  // table24_find_by_id
    for (s32 i = 0; D_00374488[i] >= 0; i++) {
        if (v[2] == D_00374488[i]) { r = 1; break; }
    }
    return r;
}

s32 func_00181500(u16);
s32 func_001a3570(u16);
s32 func_00294408(u16* p) {
    s32 r = 0;
    if (*(s8*)(p + 3) != 2) { if (func_00181500(p[0])) r = 1; }
    else r = func_001a3570(p[0]) > 0;
    if (p[1] && func_00181500(p[1])) r = 0;
    return r;
}

s32 func_00105c30(void);
void func_002fee78(u32*, const char*, const char*, u32);
void func_00170518(u32*, s32, u32);
void func_00170888(u32);
extern char D_00375000[];
extern char D_00374fe8[];
extern const char* D_0033caf4;
void func_002be4b0(u32* p) {
    const char* s = func_00105c30() == 8 ? D_00375000 : D_0033caf4;
    func_002fee78(p + 16, D_00374fe8, s, p[0]);
    func_00170518(p + 16, -200, 0);
    func_00170888(0);
}

// Splits n into count decimal digits (most significant first); returns digits used (min 1).
s32 func_002c5238(s32 n, s32 count, s32* out) {
    s32 nz = 0;
    s32 i = count - 1;
    do {
        if (n == 0) out[i] = 0;
        else { nz++; out[i] = n % 10; n /= 10; }
    } while (--i >= 0);
    return nz ? nz : 1;
}

void func_00182f28(u32);  // store_global_35ed04
void func_00319f88(u8*);
void func_0019f9a8(u8*);  // array8_free_slots
void func_001c0248(u8*);
void func_00319fb0(u8*);  // big_obj_dtor
extern void* D_00362060[];
union U362 { u32 v; void* p; };
extern U362 D_00362050;
extern void* D_0034e8b8[];
extern void* D_0034ee08[];
struct NoTail { ~NoTail() {} };
void u_call4_dtor(u32 a, u32, u32, u32) asm("_Z16u_call4_002d0f38jjjj");
// Destructor chain (vtables reset per base, members destroyed).
void u_call4_dtor(u32 a, u32, u32, u32) {
    NoTail g;
    u8* p = (u8*)a;
    *(void**)p = D_00362060;
    func_00182f28(0);  // store_global_35ed04
    D_00362050.v = 0;
    *(void**)p = D_0034e8b8;
    func_00319f88(p + 2824);
    *(void**)p = D_0034ee08;
    func_0019f9a8(p + 2568);  // array8_free_slots
    func_001c0248(p + 2640);
    func_00319fb0(p);  // big_obj_dtor
}

void func_001dc818(u32);
u32 func_0016ac38(u8*, s32, u32, u32, u32);
void func_002db610(u8* p, s32 id) {
    if (*(u32*)(p + 2828)) {
        if (*(s32*)(p + 2836) == id) return;
        func_001dc818(*(u32*)(p + 2828));
        *(u32*)(p + 2828) = 0;
    }
    if (id >= 0) *(u32*)(p + 2828) = func_0016ac38(p, id, 1, 0, 0);
    *(s32*)(p + 2836) = id;
}

// Inverts an orthonormal 4x4 matrix (transpose 3x3, negate rotated translation).
// Hand-written VU0/MMI asm in the original.
void func_002f3e20(f32* d, f32* s) {  // convert_vectors_to_scalar
    asm volatile(
        "lq $8, 0(%1)\n\t"
        "lq $9, 16(%1)\n\t"
        "lq $10, 32(%1)\n\t"
        "lqc2 $vf4, 48(%1)\n\t"
        "vmove.xyzw $vf5, $vf4\n\t"
        "vsub.xyz $vf4, $vf4, $vf4\n\t"
        "vmove.xyzw $vf9, $vf4\n\t"
        "qmfc2 $11, $vf4\n\t"
        "pextlw $12, $9, $8\n\t"
        "pextuw $13, $9, $8\n\t"
        "pextlw $14, $11, $10\n\t"
        "pextuw $15, $11, $10\n\t"
        "pcpyld $8, $14, $12\n\t"
        "pcpyud $9, $12, $14\n\t"
        "pcpyld $10, $15, $13\n\t"
        "qmtc2 $8, $vf6\n\t"
        "qmtc2 $9, $vf7\n\t"
        "qmtc2 $10, $vf8\n\t"
        "vmulax.xyz ACC, $vf6, $vf5x\n\t"
        "vmadday.xyz ACC, $vf7, $vf5y\n\t"
        "vmaddz.xyz $vf4, $vf8, $vf5z\n\t"
        "vsub.xyz $vf4, $vf9, $vf4\n\t"
        "sq $8, 0(%0)\n\t"
        "sq $9, 16(%0)\n\t"
        "sq $10, 32(%0)\n\t"
        "sqc2 $vf4, 48(%0)"
        : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
}

}
