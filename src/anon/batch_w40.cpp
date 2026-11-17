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

// 00103480: moved to src/common/unit_001031b0.cpp

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
void func_0015b268(u32 a, f32 f);  // 0x0015b268: definition moved into src/anon/unit_0015b100.cpp

void func_001666d0(u8*, u16, u32, u16, u16);
void func_00166968(u8* p, u8 b, u16 c, u32 d, u16 e, u16 g, s16 h, s16 i);  // 0x00166968: definition moved into src/anon/unit_001664c0.cpp

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
s32 func_00170d38(s32 x);  // 0x00170d38: definition moved into src/anon/unit_0016e8f8.cpp

u8* func_001050d8(u32);
void func_002ee220(u8*);
void func_002ee5d8(u8*, u32);
void func_002edfa8(u8*, u8*);
extern void* D_0034e888[];
void func_00175370(u32* a);  // 0x00175370: definition moved into src/anon/unit_00171e58.cpp

s32 func_00181a70(u32, u32);
u32* func_00189068(u32, u32);
// Increments a counter, saturating at 9999.
void func_001890a8(u32 a, u32 b);  // 0x001890a8: definition moved into src/anon/unit_00188848.cpp

union U195 { u8* p; f32 f; };
extern U195 D_00352130;
void func_001957e8(f32* p);  // 0x001957e8: definition moved into src/anon/unit_00194790.cpp

bool func_0013ef80(void);  // get_global_byte_358700
u8* func_0014aba8(void);
bool func_00197c28(u8* p);  // 0x00197c28: definition moved into src/anon/unit_00195d00.cpp

void func_00197930(u32, u32, u8*);
void func_0019f070(u8*, u32);
u8 func_0019f060(u8*);
// 00199030: moved to src/anon/unit_00198e40.cpp

s32 func_001ab820(u32);
f32 func_00192fb8(u32*);  // mul_float4x8
// Picks a 16-byte table entry by rounding count * ratio.
u8* func_001aa310(u32 a0, u32* a, u8* tbl);  // 0x001aa310: definition moved into src/anon/unit_001a9130.cpp

void func_001b3b70(u8*, u32, u32, u32);
extern void* D_00350910[];
struct B600 { u32 lo : 3; u32 m : 4; u32 rest : 25; };
// 001a6b58: moved to src/anon/unit_001a6a10.cpp

struct S1bb { u32 f0; u32 flags; };
union U1bb { S1bb* p; u32 w; };
extern U1bb D_01d49320;
extern u32 D_0034f240;
void func_0014ca20(void);
void func_001d6c58(void);
void func_001c11a8(u32);
void func_001c1130(u32);  // copy_record_block_to_table
void func_001af9f8(void);
// 001bb890: moved to src/yasui/libys/mission.cpp

void func_001d5f30(u8*, u32);
void func_001d6148(u8* p, s32 id);  // 0x001d6148: definition moved into src/anon/unit_001d4f40.cpp

u8* func_001d7980(u32);
// ORs together the flags of up to four referenced entries.
void func_001d7b10(u16* p);  // 0x001d7b10: definition moved into src/anon/unit_001d7458.cpp

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
void mission_add_count(s32 a, s32 i);  // 0x001d86a0: definition moved into src/anon/unit_001d7458.cpp
s32 mission_get_count(s32 i) asm("_ZN2YS7MISSION8GetCountEi");
s32 mission_get_count(s32 i);  // 0x001d87b8: definition moved into src/anon/unit_001d7458.cpp

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
void func_00242c00(u8 a);  // 0x00242c00: definition moved into src/anon/unit_00242478.cpp

u32 func_00257770(void);
s32 func_00287bc0(void);
void func_0028dac8(u32, u32);
s32 func_0028acc8(u32);
s32 func_0028acb8(u32);
void func_0028aa40(u32);
extern u32 D_0035f01c;
void func_00271e08(void);  // 0x00271e08: definition moved into src/anon/unit_00271e08.cpp

u32 func_00257140(u32);
void func_00138c10(u8*, u32);
u16* func_00273180(u32, s32);  // state_dispatch_2_3
u32 func_00192048(u16);
void func_00272a70(void);  // 0x00272a70: definition moved into src/anon/unit_00271e08.cpp

struct VObj28 { struct VT { u32 (*f0)(VObj28*, u32, u32); }* vt; };
struct G28 { u8 pad[20]; VObj28* o; };
extern G28* D_00347f80;
void func_0028dfe8(u32);  // obj_ctor_36f440
void func_0028b940(u32* p);  // 0x0028b940: definition moved into src/anon/unit_00288b00.cpp

s32 func_0028be58(u32);
s16 func_0028e4c8(u32, u32);
void func_0028e560(u32, void*, u32, s32);
void lead_data_leave(u32 a) asm("_ZN2Tz13LeadDataLeaveEj");
void lead_data_leave(u32 a);  // 0x0028bdb8: definition moved into src/anon/unit_00288b00.cpp

u8* func_001a80c8(u32);  // table24_find_by_id
extern s8 D_00374488[];
// Is the item's kind byte in the -1 terminated list?
s32 func_002914a8(u32 a0, u32 a1);  // 002914a8: moved to src/anon/unit_00290f78.cpp

s32 func_00181500(u16);
s32 func_001a3570(u16);
s32 func_00294408(u16* p);  // 0x00294408: definition moved into src/anon/unit_00292e60.cpp

s32 func_00105c30(void);
void func_002fee78(u32*, const char*, const char*, u32);
void func_00170518(u32*, s32, u32);
void func_00170888(u32);
extern char D_00375000[];
extern char D_00374fe8[];
extern const char* D_0033caf4;
void func_002be4b0(u32* p);  // 0x002be4b0: definition moved into src/anon/unit_002be020.cpp

// Splits n into count decimal digits (most significant first); returns digits used (min 1).
s32 func_002c5238(s32 n, s32 count, s32* out);  // 0x002c5238: definition moved into src/anon/unit_002c4ca8.cpp

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
void u_call4_dtor(u32 a, u32, u32, u32);  // 0x002d0f38: definition moved into src/anon/unit_002cf260.cpp

void func_001dc818(u32);
u32 func_0016ac38(u8*, s32, u32, u32, u32);
void func_002db610(u8* p, s32 id);  // 0x002db610: definition moved into src/anon/unit_002da040.cpp

// Inverts an orthonormal 4x4 matrix (transpose 3x3, negate rotated translation).
// Hand-written VU0/MMI asm in the original.
void sceVu0InversMatrix(f32* d, f32* s) {  // convert_vectors_to_scalar
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
