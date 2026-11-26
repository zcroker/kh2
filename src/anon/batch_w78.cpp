#include "../common/types.h"
struct W78Vec {
    f32 x, y, z, w;
    W78Vec& operator=(const W78Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W78Mtx {
    W78Vec r[4];
    W78Mtx& operator=(const W78Mtx& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
};
static inline void vsub(W78Vec* d, const W78Vec* a, const W78Vec* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline void vadd(W78Vec* d, const W78Vec* a, const W78Vec* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline f32 vnormalize(W78Vec* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline f32 vlength(const W78Vec* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}

// ---- c1
extern "C" {
u32 strlen(const u8*);  // strlen
u8* func_00100430(u8*, u64*);  // varint64_decode_c
u8* func_00100468(u8*, s64*);
u8* func_001004c0(u8, u32, u8*, u32*);
W78Vec* func_00133bb8(u32, s32, u32, u32);  // forward_sub24_to_133848
void func_0015cb78(void*, u32);
void func_00141c18(void*, u32, u32, u32, u32);
s32 func_00141ff0(void*, void*, void*, void*, s32);
struct W78VecC { f32 x,y,z,w; W78VecC(const W78VecC& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); } } __attribute__((aligned(16)));
void func_001539c0(void*, W78VecC);
void func_00147c78(u8*, u8*, f32);  // copy_bytes_232_to_12
u8* func_001058e8(void);
f32 func_0017ce10(f32);
u32 func_00155d58(u32, s32);  // table_word_indexed_by_3
void func_00138c10(u32, u32);
void func_00154408(u32, u32);
s32 func_001581d0(u32);
s32 func_002ba358(void);
void func_002ba390(void);
extern u8* D_0034880c;
extern f32 D_004f3588;
extern u32 D_0032b984;
extern u8 D_0032bae0[];

// Reads a CIE's augmentation data and returns its FDE pointer encoding.
s32 func_001009a0(u8* cie);  // 0x001009a0: definition moved into src/libgcc/unwind-dw2-fde.c

// 00134c00: moved to src/anon/unit_00134668.cpp

struct W78Ent { u8 b; u8 pad[15]; };
struct W78Hit { u8 pad[12]; u8* tbl; };
void* func_00143860(void* self, W78VecC* v);  // 0x00143860: definition moved into src/anon/unit_00142c90.cpp

static inline u8* next(u8* o, u8* c) { if (!c) return *(u8**)(o + 240); return *(u8**)(c + 236); }
struct W78Flag { u32 f, g; };
struct W78Grp { u32 a; f32 f; u8* ptr[214]; s32 n; u8 pad[12]; };
struct W78World { u8 pad[3168]; W78Grp grp[4]; };

struct W78Pair { u32 a, b; u32 c[19]; };
struct W78Loc { u32 a, b; s32 i; u32 n; };

// 00155758: moved to src/anon/unit_00153ea0.cpp
s32 func_00155758(s32 n, f32* a, s32* b, s32* c, s32* d, f32* ang);
}

void wtarget_001575c0(u8* p) asm("_Z16wtarget_001575c0jjjj");
// 001575c0: moved to src/anon/unit_00153ea0.cpp

// ---- c2
extern "C" {
u8* func_00102c80(void);
void func_00102670(u32, void*);  // to_1025f8
void func_001623b0(void);
void func_001619e8(void);
void func_001620a8(void);
u8* func_00102c18(s32, u32, void*);
void func_001024a8(void*);
void func_00161d48(void);
void func_00161c88(void);
void func_00161de0(void);
union W78Any { u8* p; f32 f; u32 u; };
extern W78Any D_0034c774;

struct W78Snd { u32 x0; f32 f4; u32 x8, x12; s32 mode; };
struct W78Task { u32 x0; f32 f4; f32 f8; f32 inv; s32 mode; u8 pad[28]; W78Any fn; };

static inline W78Vec operator-(const W78Vec& a, const W78Vec& b) { W78Vec r; vsub(&r, &a, &b); return r; }

void func_0016c8f8(void*, u32, u32, u32);
void func_001da458(void*, s32, u32, u32);  // stream_init_fields
void YS__VM__exec(void*, u32*);
void func_0016cab8(void*);
extern u32 D_0034d8a4;
extern u32 D_0034d8a0;

s32 YS__SHEET__is_mpdrive(u32);
u8* func_00177860(void*);
void YS__BTLOBJ__add_mp(void*, s32, s32);
void YS__BTLOBJ___OVR_add_hp(void*, s32, u32, u8);
// 00177c50: moved to src/yasui/libys/party.cpp
}

s32 func_00190180(u32*);
void func_00190388(W78Vec*, u32*);  // vec4_from_arg
W78Vec* YS__OBJ__get_pos(u8*);  // obj_get_attach_or_alt
void YS__OBJ__turn_to_dir(u8*, W78Vec*, f32);
extern "C" {
u32 YS__BTLOBJ___turn_to_target_range(u8* o, u32* tgt, f32 f) asm("_Z33YS__BTLOBJ___turn_to_target_rangejjjj");
}

extern "C" {
static inline bool inRange(u8* p, f32 t) {
    bool r = false;
    if ((f32)*(u16*)p <= t) {
        if (*(u16*)(p + 2) != 0xffff) { if (t < (f32)*(u16*)(p + 2)) r = true; }
        else r = true;
    }
    return r;
}
typedef void (*W78Cb)(u8*, void*);
void func_00189f20(u8* tbl, W78Cb cb, void* arg, f32 t);  // 0x00189f20: definition moved into src/anon/unit_00189d38.cpp

struct W78Hdr { u32 a, b, c, d; };
struct W78St {
    W78Hdr h;
    W78Vec v1;
    u32 x20; u8 x24; f32 x28, x2c; u8 x30, x31;
    W78Vec v2;
    f32 x50;
};
void func_0018c480(W78St*, s32);
void func_0018c438(W78St*);
void func_0018c150(u8* p);  // 0x0018c150: definition moved into src/yasui/libys/npc.cpp
}

// ---- c3
extern "C" {
s32 func_00192440(u8*, s32);  // is_byte_lt25
u8* func_00192388(u8*);  // skip_control_codes
// 00192b80: moved to src/yasui/libys/message.cpp

struct W78Sub { u8 pad[24]; u8 kind; u8 p25; u16 id; u8 pad2[12]; };
struct W78Ent64 { u32 x0; W78Sub s; u8 pad[20]; };
struct W78List { u8 pad[4]; u16 n; u8 pad2[38]; W78Ent64 e[1]; };
s32 func_0016b7a0(u16);
u8* func_00199938(W78Ent64*, void*);
void func_001ad990(u8*, f32, f32, f32);
void func_0019b500(u8* o);  // 0x0019b500: definition moved into src/anon/unit_00199688.cpp

extern u8 D_0032bae0[];
void YS__STDOBJ___OVR_initialize(u8*);
u32 func_0016c008(u8*, s32);
u8* func_001a81f0(u8, u8, u32);
s32 func_001a8450(u8*);
void func_0017f488(u8*, s32, f32, f32);
void func_001a8678(u8*);
void func_001a86b8(u8* o);  // 0x001a86b8: definition moved into src/anon/unit_001a8618.cpp

s32 func_001a9780(u32);
u8* func_001a97b8(u32, s32);
u8* func_00168b38(u8*, s32, s32);  // entry_array_find_nth
u32 YS__OBJDATA__get_kna(u8* o, s32 a, s32 b);  // 0x001a9458: definition moved into src/anon/unit_001a9130.cpp

u8* func_00168b88(u32, s32, s32, s32);  // find_entry16_by_half_word
#define W78_FOURCC(c) ((c)[0] | ((c)[1] << 8) | ((c)[2] << 16) | ((c)[3] << 24))

struct W78Five { u32 w[5]; };
struct W78Slot { u16 x0; u16 cnt; u8 pad[8]; W78Five v; u8 lvl; u8 pad2[3]; };
u32 YS__COMMAND_ELEM__Get(u32);
void YS__COMMAND_SLOT__set(W78Slot*, u32, u32, W78Five*, u32);
W78Slot* func_001bd418(u8* o, s32 idx, u32 key, W78Five* src, u32 arg, s32 lvl);  // 0x001bd418: definition moved into src/anon/unit_001bc568.cpp
}

// ---- c4
extern "C" {
u8 func_001d6d00(s32);
void func_001c8d80(void*, s32);
u8 func_001c8c38(void);
u8* TASK_MANAGER__create_thread(u32, s32, s32, void*, s32);
void func_001c83f8(void);
void func_001c86e8(void);
void func_001c98f0(f32);
void func_001c8710(void);
void func_001d9820(u8);
extern u8 D_00351eb8;
extern u8 D_0032bb30[];
extern s32 D_01d49968;
extern u32 D_00351214;
extern u8* D_00351e08;
// 0x1c8300: moved to src/yasui/libys/summon.cpp

void func_00177dc8(u8*, u32, s32, u32, u32);
void func_00158a90(u8*);
extern u8 D_00352288[];
struct W78V4 {
    f32 x, y, z, w;
    void set(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
};
struct W78Cam { W78V4 a; W78V4 b; f32 r0, r1, r2, r3; u32 z0, z1; };

void func_001d86a0(s32, s32);
void func_001d8820(s32, s32);
void func_0017f488(u8*, s32, f32, f32);
void func_0017f5e0(u8*, s32, s32, f32, f32);

s32 YS__MISSION__IsNoExp(void);
u8* func_001d5cd0(void);
void func_001d7000(u8, u8*);
void YS__LEVELUP__ShowEffectDrive(u32);
extern u8 D_0032e020[];
extern u32 D_0034e948;
void func_001d6f28(s32 n);  // 0x001d6f28: definition moved into src/anon/unit_001d68e0.cpp

void func_002fdfc8(const char*, ...);  // device_vprintf_va
u8* func_001e3650(void*);  // ptr_add4
s32* func_001e3660(u8*, s32);
void func_001e5220(u32, s32);
extern char D_0036e978[];
extern char D_0036ed60[];
extern char D_0036e998[];
extern char D_0036e9d0[];
extern char D_0036ec40[];
// "RyjAssertion failed: %s\n" / "   File %s, Line %u\n" (partMng.c), then break.
static inline void w78_assert(const char* e, const char* f, s32 l) {
    func_002fdfc8(D_0036e978, e);  // device_vprintf_va
    func_002fdfc8(D_0036e998, f, l);  // device_vprintf_va
    asm volatile("break");
}
}

// ---- c5
extern "C" {
struct W78Prm {
    u16 x0;
    u16 flags;
    u8 rgba[4];
    u64 z8;
    u8* mtx;
    u32 tex;
    u8 b24;
    u32 x28;
    u8 pad[16];
};
extern u8* D_01d9e6e4;
extern u8* D_01d9e6e8;
extern u32 D_01d9eaa4;
u32 func_0021d048(u8*, W78Prm*, u32);

extern u8* volatile D_01d9e6e8v asm("D_01d9e6e8");
void func_0021eb50(u8*, u8*);
static inline void w78_scale(u8* v, u32 s) {
    asm volatile("qmtc2 %1, $vf9\n\tlqc2 $vf10, 0(%0)\n\tvmulx.xyz $vf10, $vf10, $vf9x\n\tsqc2 $vf10, 0(%0)" : : "r"(v), "r"(s) : "memory");
}

void sceVu0UnitMatrix(W78Vec*);  // vu_store_w_splat
void sceVu0MulMatrix(W78Vec*, void*, W78Vec*);
void sceVu0ScaleVector(u8*, u8*, f32);  // vec_scale_by_f12
void sceVu0ApplyMatrix(u8*, W78Vec*, u8*);
extern u8 D_01d9e730[];
extern u8 D_01d9e8c0[];
void func_00200700(u8* o, u32 a1, u8* a2);  // 0x00200700: definition moved into src/anon/unit_00200578.cpp

void func_00228240(void);
u32 sa__EVENT__getEventPriority(void);  // limit_15000_or_25000
u8* func_00102c80(void);
u8* func_00102788(u32, u32, u32, void*);
void func_00227e30(void);
void func_002272b8(void);
void func_00228058(void);
void func_002280f8(void);
extern u8* D_0035de30;
extern u8* D_0035de34;
extern u8* D_0035de38;
extern u32 D_0035de3c;
extern u8 D_0035de27;
void func_00228150(u32 a);  // 0x00228150: definition moved into src/anon/unit_00224780.cpp

struct W78Alloc;
typedef u8* (*W78AllocFn)(W78Alloc*, s32, s32);
struct W78Alloc { W78AllocFn* vt; };
struct W78Item { void* vt; u8 p4[8]; u8 m1[12]; u8 m2[384]; };
extern u8* D_00347f80;
extern u8 D_0035e028[];
extern u8 D_00347f98[];
extern u8 D_00347e60[];
void func_0031a838(u8*);
void func_00239700(u8*);
void sa__MUSICAL_GAUGE4__create(u8*);
void func_002289f0(void);  // 002289f0: moved to src/anon/unit_00228618.cpp (linked unit)
}

// ---- c6
extern "C" {
extern u8 D_0035e359;
extern char D_00371300[];
extern char D_00371320[];
u32 func_00232348(void);
void func_002fee78(char*, const char*, ...);
s32 strncmp(const char*, const char*, s32);
void func_002baa08(u32, u32, s32, s32);
// Plays the title voice lines when the event name matches.
s32 func_002325f0(u8* o);  // 0x002325f0: definition moved into src/anon/unit_00231500.cpp

s32 sa__EVENT__checkStart(s16);
s32 func_00227ca8(void*);
s32 sa__EVENT__isJumpMode(s16);  // flag_query_by_index
u32 func_002bc238(s32);
void func_002bc358(u32, s32);
extern s32 D_0035e35c;
extern u32 D_0035db60[];
struct W78Snd2 { s16 x0, x2, slot, kind; u8 name[4]; s16 id; };
void sa__EVENT__set_se_seq(W78Snd2* o);  // 0x00232c88: definition moved into src/anon/unit_00231500.cpp
}

void func_00106450(void*);
void func_00106420(void*);
void func_00242048(void*);
extern void* D_0035ec88;
extern void* D_0035ec8c;
extern void* D_0035ec90;
extern void* D_0035ec94;
extern void* D_0035ec98;
extern u32 D_0035ec9c;
extern void* D_0035eca0;
extern void* D_0035eca4;
void Tz__MCard__End(void) asm("_Z14Tz__MCard__Endv");
void Tz__MCard__End(void);  // 0x00240000: definition moved into src/anon/unit_0023f5b8.cpp

extern "C" {
s32 func_00276c18(void);
u8* func_001d56c8(u8);
extern u32 D_0035edf4;
extern s32 D_003722ec;
extern s32 D_003722f0;
extern u8 D_003722e0[];
extern u8 D_003722e8[];
s32 func_0024e080(void);  // 0x0024e080: definition moved into src/anon/unit_0024cda8.cpp

u32 func_00257770(void);
s32 func_00287bc0(void);
s32 Tz__CmAbility__Cur2AbiltyType(void);  // check_state16_then_loop
void func_0028dac8(u32, s16);
s32 func_0028be58(u32);
void func_0028bdb8(u32);
s32 func_0028acc8(u32);
s32 func_0028acb8(u32);
void func_0028aa40(u32);
extern u32 D_0035f04c;
extern u32 D_0035f01c;
struct W78E6 { s16 a, b, c; };
extern W78E6 D_00373e30[];
}

// ---- c7
extern "C" {
extern u8 D_0035f3a8;
u32 func_0023f948(void*, u32);
u32 func_0023f908(void*, u32);
void Tz__Layout__create(u32, u32, u32, u32, u32, u32);
void func_0023f0c8(u32, u32);
void Tz__MenuUtil__CreateLay(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1, u32 x, u32 y, u32 z);  // 0028d7f0: moved to src/anon/unit_0028c878.cpp

void func_00290060(u8*);
void dk__Sprite__create(u32, u32, u32, u32, s32, s32);
void func_00259020(u32, u32, u32, u32, u32, u16*, s32, s32);
void func_0028ff00(u8*);
struct W78Mot { u32 obj; u32 x4; s16 a8; s16 pad; s16 a12; s16 pad2; u16 a16; };

s32 func_002a4990(s32);
s32 func_002a4430(void);
s32 func_002a43f0(void);
void func_002ac8e0(s32);
void func_002ab728(s32);
void func_002abac8(s32);
void func_002a3318(void);
extern u8* D_0035f5e4;
struct W78Slot8 { u8 a, b, on, done; u8 pad[4]; };
struct W78Tbl { u8 pad[4096]; W78Slot8 e[1]; };
void Tz__JmTreasure__UpdateNewMark(void);  // 0x002a3aa8: definition moved into src/anon/unit_002a3648.cpp

u8* func_002a9d68(s32);
extern u8* D_0035f610;
static inline u32 w78_bit(u32* bits, u32 i) { return bits[i >> 5] & (1 << (i & 31)); }

u8* func_001a82b0(u8*);
s32 Tz__Jiminy__AreaWorld2JmWorld(u8);
void func_002ab728(s32 id);  // 0x002ab728: definition moved into src/anon/unit_002a99c8.cpp

extern s32 D_0035f62c;
extern s32 D_0035f628;
void func_002ad110(void);
void Tz__JmComplete__CheckAnsem(void);
void Tz__JmComplete__CheckAlbum(void);
void Tz__JmComplete__CheckBattle(void);
void Tz__JmComplete__CheckQuest(void);
void func_002ad878(void);
void Tz__JmComplete__CheckTreasure(void);
void func_002adbd0(void);
void Tz__JmComplete__CheckSynthesis(void);
void Tz__JmComplete__CheckPuzzle(void);
void Tz__JmComplete__CheckStory(void);
s32 func_002ae0c0(s32);
void Tz__JmComplete__CheckAll(void);  // 0x002acf48: definition moved into src/anon/unit_002a99c8.cpp
}

// ---- c8
extern "C" {
u8* func_00294000(s32);
s32 func_002943e8(u8*);
extern s32 D_0035f628;
extern s32 D_0035f62c;
extern u8* D_0035f620;

u8* Tz__JmPuzzle__GetImageInfo(s32);  // list_entry_by_index_checked
u8* w78_9d68(void) asm("func_002a9d68");
s32 func_002b2380(s16, s16);
extern u8* D_0035f638;
s32 Tz__JmPuzzle__GameSelCheck(u32 mask);  // 0x002b3c38: definition moved into src/anon/unit_002b3ac8.cpp

u32 func_002bc988(u32);
s32 func_002bc9d8(u8*, u32);
void func_002bc9a8(u8*, s32, u32);  // find_entry12_set_field
s32 func_002bc978(u32);
void func_002bcda8(u8*, s32);
void func_002bd188(u8*, s32);
}

extern W78Vec D_01e2bd20;
extern W78Vec D_01e2bd30;
extern W78Vec D_01e2bd40;
void wtarget_002c5298(u32 a, u32 b) asm("_Z16wtarget_002c5298jjjj");

// ---- c9
extern "C" {
f32 func_002f8a18(f32);
f32 fabsf(f32);  // fabsf
struct W78VecC2 {
    f32 x, y, z, w;
    W78VecC2& operator=(const W78VecC2& o) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
W78VecC2* func_002d1d30(W78VecC2* out, u8* cam, W78VecC2* pos);  // 0x002d1d30: definition moved into src/anon/unit_002cf260.cpp

extern u32 D_00361f60;
extern u8 D_00362380;
extern u8 D_00362388;
void func_0017f540(u8*, s32, f32, f32);
u32 func_002d1260(void);
void YS__OBJ__attach(u8*, u32, s32, s32);
void func_002e7568(u8*, s32, void*, f32);
u8* func_002d1878(u32);
void func_002e7340(u8*, u8*, s32, void*, f32, f32);

u8* YS__OBJ__Each(u8*);
s32 func_0019c768(u8*);
s32 func_0016a060(u8*);
void func_002cf280(u8*, s32, s32);
}
