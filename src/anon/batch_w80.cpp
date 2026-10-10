#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));

// ---- unit 0 (final.cpp)
struct U0_Ent { u32 w; u8 pad[28]; };
struct U0_Hdr { u8 pad[28]; s32 n; U0_Ent e[1]; };
struct U0_Obj { u32 f0; U0_Hdr* h; };
struct U0_Node { s16 type; u16 flags; u32 count; u32 offs[6]; u32 valOff; };
struct U0_Ctx { u8 pad[260]; u8 sub[392]; u32 f652; u8 pad2[16]; u32 f672; };
struct U0_Cfg { u32 f0, f4, f8, f12; };
struct U0_Body { u8 pad[72]; f32 y; };
struct U0_Inp { u8 pad[44]; f32 speed; };
extern U0_Ctx* D_003484a0;
extern u8* D_00348050;
extern U0_Cfg D_00348578;
extern f32 D_0034aa84;
extern u8 D_0034aa40;
struct U0_Link { u32 f0; void* buf; u32 f8; U0_Link* next; };
struct U0_LinkList { U0_Link* head; U0_Link* tail; };
struct U0_LinkPool { U0_Link e[64]; s32 freeIdx[64]; s32 nfree; };
extern U0_LinkList D_004f41c0;
extern U0_LinkPool* D_0034c7a0;

struct U0_Info { u8 pad[4]; u8 f4; u8 pad2[9]; s16 f14; s16 f16; s16 f18; };
union U0_FU { f32 f; s16 s; };
struct U0_Chr {
    u8 pad0[1296]; u32 f1296;
    u8 pad1[1456 - 1300]; U0_FU f1456, f1460, f1464;
    u8 pad2[1532 - 1468]; U0_FU f1532;
    u64 b0:1; u64 b1:2; u64 rest:61;
    u8 pad3[1636 - 1544]; U0_Info* f1636; U0_Info* f1640;
    u8 pad4[2040 - 1644]; u32 f2040;
    u8 pad5[2088 - 2044]; u32 f2088;
    u8 pad6[2264 - 2092]; u32 id;
};
struct U0_Res { u8 pad[4]; u8 f4; u8 pad2[3]; char f8[32]; char f40[32]; };
extern char D_004f6400[];
extern char D_0036c460[];
extern char D_0036c468[];
extern char D_0036c478[];

struct U0_Blk { u8 f0; u8 f1; u8 pad[38]; s32 f40; u32 f44; u32 pad48; u32 f52; u32 pad56; U0_Blk* next; };
extern s32 D_0034dca8;
extern u32 D_01c5c440[];
extern u32 D_0034dc9c;
extern U0_Blk* D_0034dca0;

struct U0_Sub { u32 f0; u32 f4; u32 f8; };
struct U0_Act { u8 pad[12]; U0_Sub* sub; u8 pad2[12]; f32 f28; u8 pad3[352 - 32]; u32 f352; u8 pad4[2896 - 356]; s32 state; };
struct U0_Mot { u8 pad[20]; u32 f20; };

// ---- unit 1 (d.cpp)
struct HasF4 { u32 f0; f32 f4; };
struct U1_Turn { u8 pad[284]; f32 f284; u8 pad2[1372 - 288]; f32 yaw; };
extern f32 D_00349e10;
struct U1_Eff { u8 pad[1288]; void* eff; u8 pad2[1416 - 1292]; u32 f1416; u8 pad3[2072 - 1420]; void* tgt; };
extern char D_01c61a88[6][8];
extern char D_01c61988[];
extern char D_0036cd70[];
struct U1_Lock { u8 pad[4]; u32 mask; };
struct U1_Lk { u8 pad[1140]; u8 a[8]; u8 b[8]; u8 pad2[2264 - 1156]; U1_Lock* lock; };

// ---- unit 2 (good1b7.cpp)
struct U2_Lvl { s32 need; };
struct U2_Grow { u8 pad[14]; u8 f14; u8 lv; };
struct U2_GrowOwn { u8 pad[1164]; u32 f1164; };
extern s32 D_0032bb30[];

// ---- unit 3 (good1c0.cpp)
struct U3_Tmr { u32 id; f32 t; };
struct U3_TmrSet { u32 f0; u32 bits[10]; f32 f44; U3_Tmr tm[4]; };
extern f32 D_00349e10;
extern union { f32 f; u32 u; } U3_D_00349e10_u asm("D_00349e10");

// ---- unit 4 (e.cpp)
struct U4_VO;
struct U4_VOVt { void* f0; void* f4; void* f8; void (*f12)(U4_VO*, void*, f32); };
struct U4_VO { U4_VOVt* vt; };
struct U4_Lim { u8 pad[56]; f32 f56; };
struct U4_Mover { u8 pad[12]; U4_VO* f12; u8 pad2[240 - 16]; U4_Lim* f240; u8 pad3[268 - 244]; u32 f268; u8 pad4[320 - 272]; u8 f320[4]; };

#define U4_W80_MAX(a, b) ((a) > (b) ? (a) : (b))

// ---- unit 5 (good200.cpp)
struct U5_PartTbl { u32 f0; u32 f4; u32 f8; u32 f12; };
struct U5_PartRef { u8 pad[12]; U5_PartTbl* tbl; };
extern f32 D_00354bd0[3];
extern f32 D_00354bc0[3];
struct U5_Rot { u8 pad[48]; f32 f48, f52, f56; };

// ---- unit 6 (good21f.cpp)
struct U6_Osc { f32 f0; f32 val; };
struct U6_OscSet { u8 pad[4]; u32 f4; u8 n; u8 flags; u8 pad2[6]; U6_Osc e[1]; };

// ---- unit 7 (good232.cpp)
struct U7_SeEnt { u8* obj; u8 pad[2]; s8 state; u8 pad2[25]; };
struct U7_SeTbl { u8 pad[4]; s16 n; u8 pad2[2]; U7_SeEnt e[1]; };
struct U7_SeObj { u8 pad[20]; u32 h; };
struct U7_SeReq { u8 pad[4]; s16 id; s16 fade; };
extern U7_SeTbl* D_0035de4c;

// ---- unit 8 (g.cpp)
struct U8_Rot3 { u8 pad[28]; f32 m00, m01, m02, m03; u8 pad2[112 - 44]; f32 rx, ry, rz; };

// ---- unit 9 (good244.cpp)
extern u32 D_0035ece8;
extern u32 D_0035ecec;
extern u32 D_0035ecf0;
extern u32 D_0035ecf4;
extern u32 D_0035ecf8;

// ---- unit 10 (good244a.cpp)
struct U10_CurSub { u8 pad[184]; u32 f184; };
struct U10_CurObj { u8 pad[24]; U10_CurSub sub; u8 pad2[392 - 212]; u32 f392; u8 pad3[405 - 396]; u8 f405; u8 pad4[2]; u8* f408; u8 pad5[428 - 412]; u32 f428; u32 f432; };
extern union { U10_CurObj* p; u32 u; } U10_D_0035ed00_u asm("D_0035ed00");
#define U10_D_0035ed00 (U10_D_0035ed00_u.p)
extern u32 D_0035ecf0;
extern union { u8* p; u32 u; } U10_D_0035ed10_u asm("D_0035ed10");
#define U10_D_0035ed10 (U10_D_0035ed10_u.p)

// ---- unit 11 (h.cpp)
struct U11_CurObj { u8 pad[24]; u8 sub[184]; u32 f208; u8 pad2[392 - 212]; u32 f392; u8 pad3[405 - 396]; u8 f405; u8 pad4[2]; u8* f408; u8 pad5[428 - 412]; u32 f428; u32 f432; };
struct U11_SprInfo { u8 pad[40]; u32 f40; };

// ---- unit 12 (good2a6.cpp)
struct U12_CurSub { u8 pad[184]; u32 f184; };
struct U12_VObj;
struct U12_VObjVt { void* f[5]; void (*f20)(U12_VObj*); };
struct U12_VObj { U12_VObjVt* vt; };
extern u8* D_0035f5f0;
extern u32 D_0035f200;
extern u32 D_0035f214;

// ---- unit 13 (good24e.cpp)
extern void* D_0035ee04;
extern s32 D_0035ee08;
extern s32 D_0035ee0c;
extern s32 D_0035ee2c;
extern s32 D_0035ee10;
extern s32 D_0035ee18[5];
struct U13_SysInfo { u32 f0; u32 f4; };

// ---- unit 14 (good252.cpp)
struct U14_CurSub { u8 pad[184]; u32 f184; };
struct U14_CurObj { u8 pad[24]; U14_CurSub sub; u8 pad2[392 - 212]; s32 f392; u8 pad3[405 - 396]; u8 f405; };
extern union { U14_CurObj* p; u32 u; } U14_D_0035ee7c_u asm("D_0035ee7c");
extern u32 D_0035ee58;
extern u32 D_0035ee60;
struct U14_CurPos { s16 x, f2, y; };
extern U14_CurPos D_00372650[];

// ---- unit 15 (good27e.cpp)
struct U15_IdMap { s16 val; s16 key; };
struct U15_IdMapTbl { U15_IdMap e[15]; };
extern const U15_IdMapTbl D_00374008;

// ---- unit 16 (i.cpp)
struct U16_ShopEnt { u8 pad[4]; u16 id; u8 type; u8 pad2; };
extern U16_ShopEnt D_003742c8[];

// ---- unit 17 (good2ad.cpp)
struct U17_GotEnt { u8 pad[6]; u16 id; };
struct U17_GotList { u8 pad[8]; s32 n; u8 pad2[4]; U17_GotEnt e[1]; };
struct U17_GotBits { u8 pad[136]; u32 bits[41]; u32 bits300[8]; };
extern union { s32 v; u32* p; } U17_D_0035f628_u asm("D_0035f628");
#define U17_D_0035f628 U17_D_0035f628_u.v
extern union { U17_GotBits* p; s32 v; } U17_D_0035f620_u asm("D_0035f620");
#define U17_D_0035f620 U17_D_0035f620_u.p
extern s32 D_0035f62c;

// ---- unit 18 (good2adb.cpp)
struct U18_GotBits { u8 pad[136]; u32 bits[41]; u32 bits300[8]; };
extern union { s32 v; u32* p; } U18_D_0035f628_u asm("D_0035f628");
#define U18_D_0035f628 U18_D_0035f628_u.v
extern union { U18_GotBits* p; s32 v; } U18_D_0035f620_u asm("D_0035f620");
#define U18_D_0035f620 U18_D_0035f620_u.p
extern s32 D_0035f62c;
struct U18_Evt { u8 pad[2]; u16 id; };
struct U18_EvtInfo { u8 pad[2]; u8 type; };

// ---- unit 19 (j.cpp)
struct U19_VObj;
struct U19_VObjVt { void* f[5]; void (*f20)(U19_VObj*); };
struct U19_VObj { U19_VObjVt* vt; };
extern u8* D_0035f634;

// ---- unit 20 (good2bb.cpp)
struct U20_Fade { u8 pad[16]; u32 f16; u32 f20; u32 f24; u8 pad2[12]; s16 f40; u8 pad3[2]; s16 f44; u8 pad4[2]; u8 state; };

// ---- unit 21 (k2.cpp)
struct U21_DObj;
struct U21_DObjVt { void (*dtor)(U21_DObj*); };
struct U21_DObj { U21_DObjVt* vt; u8 pad[340]; };
extern u8 D_00363828[];
extern u8 D_003637e0[];
extern u8 D_00350ab0[];
extern u8 D_00350bb0[];
extern u8 D_00350a70[];
extern u8 D_00350a56;
#define U21_W80_DTOR_ARR(base, off, n) \
    if ((u32)(base) != (u32)-(off)) { \
        U21_DObj* e_ = (U21_DObj*)((base) + (off)) + (n); \
        U21_DObj* b_ = (U21_DObj*)((base) + (off)); \
        for (;;) { \
            if (b_ == e_) break; \
            e_--; \
            e_->vt->dtor(e_); \
        } \
    }

// ---- unit 22 (l.cpp)
struct U22_E16 { u8 pad[16]; };
extern u8 D_00351e18[];
extern u8 D_00345c08[];
extern u8 D_0034ebc8[];
extern u8* D_01d49960[2];
extern u32 D_01d49968;

// ---- unit 23 (n3.cpp)
struct U23_W80Vec {
    f32 x, y, z, w;
    U23_W80Vec() {}
    U23_W80Vec(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    U23_W80Vec operator-(const U23_W80Vec& b) const {
        U23_W80Vec r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    U23_W80Vec operator+(const U23_W80Vec& b) const {
        U23_W80Vec r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    U23_W80Vec& operator=(const U23_W80Vec& v) {
        if (this != &v) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&v) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline void U23_w80_vsub(U23_W80Vec* d, const U23_W80Vec* a, const U23_W80Vec* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline f32 U23_w80_vlen(const U23_W80Vec* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
struct U23_W80Obj { u8 pad[88]; u8 active; u8 pad2[208 - 89]; U23_W80Vec f208; U23_W80Vec f224; };
static inline void U23_w80_vadd(U23_W80Vec* d, const U23_W80Vec* a, const U23_W80Vec* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline void U23_w80_vcopy(U23_W80Vec* d, const U23_W80Vec* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
struct U23_Ai { u8 pad[448]; U23_W80Vec pos; };
struct U23_AiTgt { u8 pad[2820]; f32 f2820; };
struct U23_AiParam { u8 pad[24]; f32 range; };
extern f32 D_00349e10;

// ---- unit 24 (o.cpp)
struct U24_W80Vec {
    f32 x, y, z, w;
    U24_W80Vec& operator=(const U24_W80Vec& v) {
        if (this != &v) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&v) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct U24_W80Param { u32 a, b, c, d, e; };
struct U24_W80Eff { u8 pad[64]; U24_W80Vec pos; u8 pad2[100 - 80]; U24_W80Param prm; };
struct U24_W80Heap { u8 pad[8]; u32 f8; };
struct U24_W80Own { u8 pad[2548]; u8* heap; };

// ---- unit 25 (o_1.cpp)


extern "C" {
U0_Hdr* func_00120800(U0_Obj*);  // obj_get_sub_ptr_by12
u32 func_001319d8(u32, f32);
void func_0013b348(u32);
void func_002362b0(u8*, u32);
s32 func_0013a9d0(void);
void func_002368e8(u8*, f32);
void func_002367c8(u8*);  // obj_dispatch_bitfield64
void func_0013d4c8(void);
u8* func_0013cb80(void);  // get_global_358050
void func_001387f8(u8*, u32, u8*, u32);
void func_0013b2d8(f32);
s32 func_00158450(U0_Inp*);
s32 func_001584a0(U0_Inp*);
void func_0013fda0(U0_Body*);
void func_0013fdc8(U0_Body*);
void func_00106420(void*);
U0_Info* func_0018a1b8(u32, u32, U0_Info*);  // find_byte1_entry
u32 func_001b7850(U0_Chr*, u32, u32);
s32 func_0016f460(void);
void func_002fee78(char*, const char*, ...);
s32 func_0016f7a0(u32);  // get_bit28
s32 func_0016f770(u32);  // in_id_special_range
s32 func_00170978(char*);
char* func_002ff8b0(char*, s32);
void func_002ff2e8(char*, const char*);
void func_001700e8(U0_Blk*, u32);
s32 func_0019c090(U0_Act*);  // obj_is_enabled
s32 func_001b9d40(U0_Act*);  // vtable_call_slot64_flags
U0_Mot* func_00177860(U0_Act*);
void func_0016bd60(U0_Act*, u32);
s32 func_0019c400(U1_Turn*);
f32 func_002f8ad0(f32, f32);
f32 func_0017ce10(f32);
void func_0016aeb8(U1_Turn*, f32);
void func_002cb708(void*);
void func_00105110(void*);
void* func_0019b328(void*, u32);
void* func_00182e08(u32);
HasF4* func_0016c028(void*);  // obj_get_attach_or_alt
void* func_002cd018(U1_Eff*, void*, HasF4*, f32);
s32 func_001d96e8(s32, s32);
void func_00192cc0(char*, const char*, s32);
void func_00192e50(u32, char*, u32, char*, char*, char*, char*, char*, char*);
s32 func_0019f528(u8*, s32);  // test_bit_by_index
s32 func_0019f550(u8*, s32);  // test_bit_addressable
U2_Lvl* func_001b6fb0(void*, u32);
void func_001b72c0(U2_Lvl*, void*, u32, u32);
void func_001b7428(U2_GrowOwn*);
void func_001a1460(u32);
s32 func_00186ce8(u32);
f32 func_00184a90(U4_Mover*);
void func_0017f488(u8*, u32, f32, f32);
void func_001e8fe0(U5_Rot*, s32*);
void func_0021efa8(U6_Osc*, u32);
s32 func_002282f0(s32);
s32 func_002baa20(u32);
void func_002b797c(u32, u32, s32);
f32 func_002f8960(f32);
f32 func_002f87c0(f32);
s32 func_00287bc0(void);
void func_00287d68(void);  // copy_globals_3words
s32 func_00287db0(void);
s32 func_0028acc8(u32);
s32 func_00139d78(void*);
void func_00243f48(void);
void func_001039f8(void);
void func_00244148(void);
void func_002442b8(void);
s32 func_001a6d08(u32);
void func_0028d980(...);
void func_00139620(U10_CurObj*);
void func_001395f8(U10_CurObj*);
void func_002fde18(void*, s32, u32);
void func_00244b38(void);
U11_SprInfo* func_0023f1b0(u32);
u32 func_0023c4b8(U11_SprInfo*, u32);
u32 func_00236ca8(u32, u32);
u32 func_00192048(s32);
void func_00138d60(U11_CurObj*, u32, u32, u32, u32, u32, u32);
void func_0028abe0(u32);
U12_VObj* func_00276348(void);
s32 func_0028be58(u32);
void func_0028be18(u32);
void func_002766e0(void);
void func_00287b18(u32, u32);
void* func_00288be8(u32);
void func_002889f0(void*, u32, u32);
void func_00288f48(void*, u32, u32, u32, u32);
void func_00287bd0(u32, u32);
U13_SysInfo* func_00103eb0(void);
void func_0024e7e8(void);
void func_00102818(u32, u32, u32, void (*)(void), u32);
u32 func_002891e8(u32);
s32 func_00252110(u32);
void func_0028da70(U14_CurObj*, s32);
void func_0028d8c0(U14_CurObj*, u32, u32, u32, u32, s32, s32, u32);
s32 func_00181500(u32);
U17_GotList* func_00294000(u32);
s32 func_002a8920(u32);
U18_Evt* func_001a82b0(U18_Evt*);
U18_EvtInfo* func_001a80c8(u32);  // table24_find_by_id
s32 func_002a43b0(U18_Evt*);
void func_00139510(void*);
s32 func_002bb510(U20_Fade*);
void func_002bb5f8(U20_Fade*);
void func_002bb8b0(U20_Fade*);
void func_002b9728(u32, u32, s32, s32);
void func_002b95e8(u32, u32, s32, s32);
void func_002bc358(u32, u32);
void func_00239870(u8*);
void func_0031e668(u8*);
void func_001ac5b8(u8*);
void func_001c11a8(u32);
void func_0014c9f0(u32);
void func_00320fa8(u8*);
s32 func_00197920(U23_W80Obj*);
void func_002e1440(U23_W80Obj*, U23_W80Vec*, U23_W80Vec*, U23_W80Vec*);
U23_W80Vec* w80_pos_vec(void*) asm("func_0016c028");
U23_AiParam* func_002d73f0(U23_Ai*);
s32 func_002ceef8(U23_Ai*, U23_AiTgt*);
U24_W80Eff* func_001db888(U24_W80Heap*, u32, void*);  // record_index_calc
void func_002ed8a0(void);
void func_002ed558(U24_W80Eff*, U24_W80Own*, u32, u32, void (*)(void));
void func_002ed5a8(U24_W80Eff*);
void func_00319d30(u8*);

void w80_MenuCursor_Create(U11_CurObj* c, u32 a1, u32 a2, u32 a3, u32 sprA, u32 t1, u32 t2, s32 t3, u32 st) asm("_ZN2Tz10MenuCursor6CreateEz");
void w80_JmBattle_LeaveAllInner(void) asm("_ZN2Tz8JmBattle13LeaveAllInnerEv");

static inline bool func_00170b30_locked(U0_Blk* b) { return b->f40 >= 10000; }
static inline bool func_00179450_flag(U0_Act* a) { return (a->sub->f8 & 2) || (a->f352 & 0x40); }
static inline bool func_00179450_busy(U0_Act* a) { bool b = func_0019c090(a) || func_00179450_flag(a); return b == false; }
// clear the low two flag bits of every entry matching id (-1 = all)
void func_001214c0(U0_Obj* p, u8* flags, s32 id) {
    U0_Hdr* h = p->h;
    U0_Hdr* h2 = func_00120800(p);  // obj_get_sub_ptr_by12
    s32 i;
    for (i = 0; i < h->n; i++) {
        if (id == -1 || ((h->e[i].w >> 6) & 0x1f) == (u32)id) flags[i] &= ~3;
    }
    if (h2) {
        for (i = 0; i < h2->n; i++) {
            if (id == -1 || (h2->e[i].w & 0x1f) == (u32)id) flags[h->n + i] &= ~3;
        }
    }
}
void func_00131da8(U0_Node* n) {
    u32 i;
    s16 t;
    if (n->flags & 1) return;
    t = n->type;
    n->flags |= 1;
    if (t != -1) {
        if (t == 0) {
        u32* v = (u32*)((u8*)n + n->valOff);
        for (i = 0; i < n->count; i++, v++) *v = func_001319d8(*v, 1.0f);
        }
    } else {
        u32* o = n->offs;
        for (i = 0; i < n->count; i++, o++) func_00131da8((U0_Node*)((u8*)n + *o));
    }
}
void func_0013d550(u32 a, u32 b) {
    u8* s;
    if (!D_003484a0) func_0013b348(0);
    s = D_00348050 + 32;
    func_002362b0(s, a);
    if (func_0013a9d0()) func_002368e8(s, 0.95f);
    func_002367c8(s);  // obj_dispatch_bitfield64
    D_003484a0->f672 = b;
    func_0013d4c8();
    func_001387f8(D_003484a0->sub, b, func_0013cb80() + 32, D_00348578.f8);
    D_003484a0->f652 = D_00348578.f12;
    func_0013b2d8(0.0f);
}
void func_00159fd0(U0_Body* b, U0_Inp* in, f32 dt) {
    if (func_00158450(in)) {
        D_0034aa84 = b->y -= in->speed * 8.0f * dt;
        func_0013fda0(b);
    } else if (func_001584a0(in)) {
        D_0034aa84 = b->y += in->speed * 8.0f * dt;
        func_0013fdc8(b);
    } else return;
    D_0034aa40 = 0;
}
// unlink n from the active list and return it to the pool
void func_00165768(U0_Link* n) {
    U0_Link* prev;
    U0_LinkPool* pool;
    s32 k;
    if (n == D_004f41c0.head) {
        D_004f41c0.head = n->next;
        prev = 0;
    } else {
        for (prev = D_004f41c0.head; prev->next != n; prev = prev->next) ;
        prev->next = n->next;
    }
    if (n == D_004f41c0.tail) D_004f41c0.tail = prev;
    n->next = 0;
    if (n->buf) func_00106420(n->buf);
    n->buf = 0;
    asm volatile("" ::: "memory");
    pool = D_0034c7a0;
    pool->freeIdx[pool->nfree++] = n - pool->e;
}
void func_0016a1b8(U0_Chr* c, u32 id) {
    U0_Info* v;
    c->id = id;
    v = func_0018a1b8(id, 17, 0);  // find_byte1_entry
    if (v) {
        c->f1456.f = c->f1464.f = (f32)v->f16;
        c->f1460.f = (f32)v->f18;
        c->f1532.f = (f32)v->f14;
        c->b1 = v->f4 != 0;
        c->f2040 |= 1;
        v = func_0018a1b8(c->id, 17, v);  // find_byte1_entry
        if (v) {
            c->f1636 = v;
            c->f1640 = func_0018a1b8(c->id, 17, v);  // find_byte1_entry
        }
    }
    c->f2088 = func_001b7850(c, c->id, 1);
    c->f1296 = func_001b7850(c, c->id, 2);
}
// build a resource path into buf
char* func_0016f520(U0_Res* r, u32 key, char* buf) {
    if (!buf) buf = D_004f6400;
    if (func_0016f460()) {
        func_002fee78(buf, D_0036c460, r->f40);
        if (func_0016f7a0(key) || (func_0016f770(key) && r->f4 && func_00170978(buf) < 2)) {  // get_bit28
            func_002ff2e8(func_002ff8b0(buf, '.'), D_0036c468);
        }
        return buf;
    }
    if (func_0016f7a0(key)) {  // get_bit28
        func_002fee78(buf, D_0036c478, r->f8);
    } else buf = 0;
    return buf;
}
u32 func_00170b30(u32 size) {  // alloc_align128
    U0_Blk* b;
    size += 127; size &= ~127;
    D_0034dca8--;
    D_01c5c440[D_0034dca8] = size;
    D_0034dc9c -= size;
    for (b = D_0034dca0; b; ) {
        U0_Blk* next = b->next;
        if (D_0034dc9c < b->f52 + b->f44) {
            if (!func_00170b30_locked(b)) { b->f1 = 0; b->f52 = 0; }
            else func_001700e8(b, 0);
        }
        b = next;
    }
    return D_0034dc9c;
}
s32 func_00179450(U0_Act* a) {
    if (a->state == 7) {
        if (!func_00179450_busy(a)) return 0;
        if (a->sub->f4 == 0 && func_001b9d40(a)) {  // vtable_call_slot64_flags
            if (!(a->f28 > 0.0f)) return 0;
            if (func_00177860(a)->f20 & 0x40) {
                func_0016bd60(a, 22);
                return 1;
            }
        }
    }
    return 0;
}


// turn toward the direction v, limited by speed
s32 func_00184ad0(U1_Turn* o, f32* v, f32 speed) {
    s32 r = 1;
    f32 ang, d, a;
    if (func_0019c400(o)) return 0;
    if (speed == 0.0f) speed = o->f284;
    speed *= D_00349e10;
    ang = func_002f8ad0(v[0], v[2]);
    d = func_0017ce10(ang - o->yaw);
    if (speed < d) a = func_0017ce10(o->yaw + speed);
    else if (d < -speed) a = func_0017ce10(o->yaw - speed);
    else { a = ang; r = 0; }
    func_0016aeb8(o, a);
    return r;
}
s32 func_00184eb8(U1_Eff* o, u32 id, void* t) {
    void* s;
    if (!t) t = o->tgt;
    s = o->eff;
    if (s) {
        func_002cb708(s);
        func_00105110(s);
        o->eff = 0;
    }
    s = 0;
    if (t) s = func_0019b328(t, id);
    if (!s && (o->f1416 & 0x80)) s = func_00182e08(id);
    if (!s) return 0;
    o->eff = func_002cd018(o, s, func_0016c028(o), 8.0f);
    return 1;
}
void func_001920f0(u32 a) {
    s32 i, j, k = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            func_00192cc0(D_01c61a88[k], D_0036cd70, func_001d96e8(i, j));
            k++;
        }
    }
    func_00192e50(a, D_01c61988, 256, D_01c61a88[0], D_01c61a88[1], D_01c61a88[2], D_01c61a88[3], D_01c61a88[4], D_01c61a88[5]);
}
s32 func_0019bd08(U1_Lk* o, s32 n) {
    if (!o->lock) return 0;
    if (func_0019f528(o->b, n)) return 1;
    if (func_0019f550(o->b, n)) return 0;
    if (func_0019f528(o->a, n)) return 1;
    if (func_0019f550(o->a, n)) return 0;
    return (o->lock->mask & (1 << n)) != 0;
}

#define U2_W80_MAX(a, b) ((a) > (b) ? (a) : (b))
// level up while the experience requirement is met
void func_001b71e8(void* o, U2_Grow* g, U2_GrowOwn* own) {
    s32 first = 1;
    for (;;) {
        if (g->lv >= 99) return;
        if (D_0032bb30[3512] < func_001b6fb0(o, g->lv)->need) return;
        g->lv++;
        func_001b72c0(func_001b6fb0(o, g->lv), o, g->lv, g->f14);
        if (own) {
            if (first) { func_001b7428(own); first = 0; }
            func_001a1460(own->f1164);
        }
    }
}

#define U3_W80_MAX(a, b) ((a) > (b) ? (a) : (b))
void func_001c0490(U3_TmrSet* s) {
    s32 i;
    if (s->f44 > 0.0f) {
        if (!s->f0 || !func_00186ce8(s->f0)) s->f44 -= D_00349e10;
    }
    U3_Tmr* t = s->tm;
    u32* bits = s->bits;
    for (i = 0; i < 4; i++, t++) {
        if (t->id) {
            t->t -= U3_D_00349e10_u.f;
            if (t->t <= 0.0f) {
                u32* w = &bits[t->id >> 5];
                *w &= ~(1 << (t->id & 31));
                t->id = 0;
            }
        }
    }
}


void func_001c39d0(void* self, U4_Mover* m) {
    if (m->f268 & 4) {
        f32 d = U4_W80_MAX(func_00184a90(m) - func_0016c028(m)->f4, 0.0f);
        if (!(d < m->f240->f56)) return;
    }
    func_0017f488(m->f320, 4, 16.0f, 0.0f);
    m->f12->vt->f12(m->f12, m, 0.0f);
}

static inline void U5_w80_scale_row(f32* row, f32 s) {
    asm volatile("qmtc2 %1, $vf9\n\tlqc2 $vf10, 0(%0)\n\tvmulx.xyz $vf10, $vf10, $vf9x\n\tsqc2 $vf10, 0(%0)" : : "r"(row), "r"(s) : "memory");
}
void func_00200b78(u8* base, U5_PartRef* r) {
    s32 v[3];
    U5_Rot* o;
    o = (U5_Rot*)(base + r->tbl->f12 + 160);
    v[0] = (s32)(D_00354bd0[0] * 32768.0f / 3.1415927f);
    v[1] = (s32)(D_00354bd0[1] * 32768.0f / 3.1415927f);
    v[2] = (s32)(D_00354bd0[2] * 32768.0f / 3.1415927f);
    func_001e8fe0(o, v);
    o->f48 = D_00354bc0[0];
    o->f52 = D_00354bc0[1];
    o->f56 = D_00354bc0[2];
}

static inline void U6_w80_scale_row(f32* row, f32 s) {
    asm volatile("qmtc2 %1, $vf9\n\tlqc2 $vf10, 0(%0)\n\tvmulx.xyz $vf10, $vf10, $vf9x\n\tsqc2 $vf10, 0(%0)" : : "r"(row), "r"(s) : "memory");
}
static inline void func_0021f908_seed(U6_OscSet* s, u32 seed) {
    s32 i;
    for (i = 0; i < s->n; i++) {
        seed = (u16)(seed * 2061 + 7);
        s->e[i].val = (f32)(s32)seed / 65535.0f;
    }
}
void func_0021f908(U6_OscSet* s, u32 a, u32 seed) {
    s32 i;
    s->f4 = a;
    for (i = 0; i < s->n; i++) func_0021efa8(&s->e[i], a);
    if (s->flags & 1) return;
    {
        u32 sd = seed;
        for (i = 0; i < s->n; i++) {
            sd = (u16)(sd * 2061 + 7);
            s->e[i].val = (f32)(s32)sd / 65535.0f;
        }
    }
    s->flags |= 1;
}


void func_002328c0(U7_SeReq* r) {
    U7_SeTbl* t;
    s32 sh, i;
    U7_SeEnt* e;
    if (func_002282f0(r->id)) return;
    sh = r->fade << 3;
    t = D_0035de4c;
    if (!t) return;
    e = t->e;
    s32 n = t->n;
    for (i = 0; i < n; i++, e++) {
        if (e->state == 1) {
            U7_SeObj* o = (U7_SeObj*)e->obj;
            if (func_002baa20(o->h) == 1) {
                func_002b797c(o->h, 0, sh);
                e->state = 2;
            }
        }
    }
}


void func_00237808(U8_Rot3* o, f32 rx) {
    f32 sx, cx, sy, cy, sz, cz, sxsy;
    o->rx = rx;
    sx = func_002f8960(o->rx);
    cx = func_002f87c0(o->rx);
    sy = func_002f8960(o->ry);
    cy = func_002f87c0(o->ry);
    sz = func_002f8960(o->rz);
    cz = func_002f87c0(o->rz);
    sxsy = sx * sy;
    o->m00 = cy * cz;
    o->m02 = sxsy * cz + cx * sz;
    o->m01 = cy * -sz;
    o->m03 = sxsy * -sz + cx * cz;
}


s32 func_00244068(void) {
    s32 m = func_00287bc0();
    func_00287d68();  // copy_globals_3words
    if (func_00287db0()) {
        if (func_0028acc8(D_0035ece8) || func_0028acc8(D_0035ecec) || func_00139d78((void*)D_0035ecf0) || func_00139d78((void*)D_0035ecf4) || func_00139d78((void*)D_0035ecf8)) return 0;
        func_00243f48();
        func_001039f8();
        return 1;
    }
    switch (m) {
    case 0: func_00244148(); break;
    case 1: func_002442b8(); break;
    }
    return 0;
}

static inline void U10_w80_cur_setflag(U10_CurSub* s, u32 f) { s->f184 |= f; }
void func_00244a60(void) {
    if (!func_001a6d08(10)) return;
    func_0028d980(U10_D_0035ed00, 30011, 0, 0, D_0035ecf0, 39, 41, -1, 100);
    func_00139620(U10_D_0035ed00);
    func_001395f8(U10_D_0035ed00);
    U10_D_0035ed00->f432 = 2;
    U10_D_0035ed00->f405 = 1;
    U10_w80_cur_setflag(&U10_D_0035ed00->sub, 8);
    func_002fde18(U10_D_0035ed10, 0, 32);
    U10_D_0035ed00->f408 = U10_D_0035ed10;
    func_00244b38();
}


// Tz::MenuCursor::Create
void w80_MenuCursor_Create(U11_CurObj* c, u32 a1, u32 a2, u32 a3, u32 sprA, u32 t1, u32 t2, s32 t3, u32 st) asm("_ZN2Tz10MenuCursor6CreateEz");
void w80_MenuCursor_Create(U11_CurObj* c, u32 a1, u32 a2, u32 a3, u32 sprA, u32 t1, u32 t2, s32 t3, u32 st) {
    u32 x = func_0023c4b8(func_0023f1b0(sprA), a2);
    u32 y = func_00236ca8(func_0023f1b0(sprA)->f40, a3);
    u32 z = 0;
    if (t3 >= 0) z = func_00192048(t3);
    func_00138d60(c, a1, x, y, t1, z, st);
    c->f392 = t2;
    c->f428 = 1;
}

static inline void U12_w80_cur_setflag(U12_CurSub* s, u32 f) { s->f184 |= f; }
// Tz::JmBattle::LeaveAllInner
void w80_JmBattle_LeaveAllInner(void) asm("_ZN2Tz8JmBattle13LeaveAllInnerEv");
void w80_JmBattle_LeaveAllInner(void) {
    s32 i;
    for (i = 0; i < 10; i++) {
        u32 off = i * 436;
        if (func_00139d78(D_0035f5f0 + off)) {
            U12_VObj* o = (U12_VObj*)(off + (u32)D_0035f5f0);
            o->vt->f20(o);
        }
    }
    if (func_0028acc8(D_0035f200)) func_0028abe0(D_0035f200);
    if (func_00139d78(func_00276348())) {
        U12_VObj* o = func_00276348();
        o->vt->f20(o);
    }
    if (func_0028be58(D_0035f214)) func_0028be18(D_0035f214);
    func_002766e0();
}


void func_0024e678(void) {
    void* o;
    s32 i;
    func_00287b18(5, 3);
    o = func_00288be8(56);
    func_002889f0(o, 5, 1);
    D_0035ee04 = o;
    func_00288f48(o, 64, 128, 0, 0);
    D_0035ee08 = 0;
    D_0035ee0c = 0;
    D_0035ee10 = 0;
    D_0035ee2c = -1;
    for (i = 0; i < 5; i++) D_0035ee18[i] = 0;
    func_00287bd0(0, 0);
    func_00102818(func_00103eb0()->f4, 0, 2000, func_0024e7e8, 4096);
}

static inline void U14_w80_cur_setflag(U14_CurSub* s, u32 f) { s->f184 |= f; }
void func_00252540(void) {
    s32 i = func_00252110(func_002891e8(D_0035ee58));
    if (!func_00139d78(U14_D_0035ee7c_u.p)) {
        func_0028d8c0(U14_D_0035ee7c_u.p, 30015, 3, 3, D_0035ee60, D_00372650[i].x, D_00372650[i].y, 0);
        U14_D_0035ee7c_u.p->f405 = 1;
        U14_w80_cur_setflag(&U14_D_0035ee7c_u.p->sub, 8);
    } else {
        func_0028da70(U14_D_0035ee7c_u.p, D_00372650[i].y);
        U14_D_0035ee7c_u.p->f392 = -1;
    }
}


s32 func_0027ed48(s32 key) {
    U15_IdMapTbl t = D_00374008;
    s32 i;
    s32 r = -1;
    for (i = 0; t.e[i].key >= 0; i++) {
        if (t.e[i].key == key) { r = t.e[i].val; break; }
    }
    return r;
}


s32 func_00283ab8(s32 type) {
    s32 i;
    s32 found = 0;
    for (i = 0; D_003742c8[i].id != 0; i++) {
        if (type == -1 || D_003742c8[i].type == type) {
            if (func_00181500(D_003742c8[i].id)) { found = 1; break; }
        }
    }
    return found;
}


void func_002ad878(void) {
    s32 i;
    U17_GotList* l = func_00294000(7);
    U17_D_0035f628 += l->n;
    for (i = 0; i < l->n; i++) {
        if (func_002a8920(l->e[i].id)) {
            u32* b = U17_D_0035f620->bits;
            u32* w = &b[(u32)i >> 5];
            *w |= 1 << (i & 31);
            D_0035f62c++;
        }
    }
}


void func_002adbd0(void) {
    U18_Evt* e = 0;
    s32 n = 0;
    for (;;) {
        e = func_001a82b0(e);
        if (!e) break;
        if (func_001a80c8(e->id)->type != 22) continue;
        U18_D_0035f628++;
        if (func_002a43b0(e)) {
            u32* b = U18_D_0035f620->bits300;
            u32* w = &b[(u32)n >> 5];
            *w |= 1 << (n & 31);
            D_0035f62c++;
        }
        n++;
    }
}


void func_002b2c80(void) {
    s32 i;
    for (i = 0; i < 2; i++) {
        u32 off = i * 408;
        if (func_00139d78(D_0035f634 + off + 19992)) {
            U19_VObj* o = (U19_VObj*)(off + (u32)D_0035f634 + 19992);
            o->vt->f20(o);
        }
    }
    if (func_00139d78(D_0035f634 + 19584)) func_00139510(D_0035f634 + 19584);
    if (func_00139d78(D_0035f634 + 20808)) func_00139510(D_0035f634 + 20808);
}


void func_002bbc90(U20_Fade* f) {
    switch (f->state) {
    case 0:
        break;
    case 1:
        func_002bb8b0(f);
        func_002b95e8(f->f24, f->f16, f->f40, f->f44);
        f->state = 2;
        break;
    case 2:
        if (!func_002bb510(f)) {
            func_002bc358(f->f20, 1);
            break;
        }
        func_002bb5f8(f);
        func_002bb8b0(f);
        func_002b9728(f->f24, f->f16, f->f40, f->f44);
        break;
    case 3:
        func_002bc358(f->f20, 1);
        break;
    }
}


void func_003259a0(u8* o) {
    u8* s = o + 44;
    *(u8**)o = D_00363828;
    *(u8**)s = D_00350ab0;
    U21_W80_DTOR_ARR(s, 3280, 4)
    func_00239870(s + 2936);
    *(u8**)s = D_00350bb0;
    U21_W80_DTOR_ARR(s, 1544, 4)
    func_00239870(s + 1200);
    func_00239870(s + 848);
    func_00239870(s + 484);
    func_0031e668(s + 132);
    func_001ac5b8(s);
    *(u8**)o = D_003637e0;
    func_00106420(o);
}
void func_001ad838(u8* o) {
    *(u8**)o = D_00350a70;
    D_00350a56 = 0;
    func_001c11a8(12);
    func_0014c9f0(8);
    *(u8**)o = D_00350ab0;
    U21_W80_DTOR_ARR(o, 3280, 4)
    func_00239870(o + 2936);
    *(u8**)o = D_00350bb0;
    U21_W80_DTOR_ARR(o, 1544, 4)
    func_00239870(o + 1200);
    func_00239870(o + 848);
    func_00239870(o + 484);
    func_0031e668(o + 132);
    func_001ac5b8(o);
    func_00105110(o);
}


void func_001c81d0(u8* o) {
    s32 i, n;
    *(u8**)o = D_00351e18;
    n = 0;
    for (i = 0; i < 2; i++) {
        if (D_01d49960[i]) {
            if (D_01d49960[i] == o) D_01d49960[i] = 0;
            else n++;
        }
    }
    if (n == 0) D_01d49968 = 0;
    *(u8**)o = D_00345c08;
    if ((u32)o != (u32)-3184) {
        U22_E16* e = (U22_E16*)(o + 3184) + 6;
        U22_E16* b = (U22_E16*)(o + 3184);
        for (;;) {
            if (b == e) break;
            e--;
        }
    }
    *(u8**)o = D_0034ebc8;
    func_00320fa8(o);
    func_00105110(o);
}


s32 func_002d8a78(U23_Ai* a, U23_AiTgt* t) {
    U23_W80Vec d = a->pos - *w80_pos_vec(t);
    f32 dist = U23_w80_vlen(&d);
    if (func_002d73f0(a)->range < dist) return 1;
    if (func_002ceef8(a, t)) t->f2820 = 0;
    else t->f2820 += D_00349e10;
    if (60.0f < t->f2820) return 1;
    return 0;
}
void func_002e1668(U23_W80Obj* o, void* p, const U23_W80Vec* ofs, U23_W80Vec* acc) {
    if (func_00197920(o)) return;
    if (!o->active) return;
    if (!(*(u32*)((u8*)p + 1416) & 0x80)) return;
    {
        U23_W80Vec u, t;
        U23_w80_vadd(&t, w80_pos_vec(p), ofs);
        U23_w80_vadd(&u, &t, acc);
        U23_w80_vcopy(&t, &u);
        func_002e1440(o, &t, &o->f208, &o->f224);
        {
            U23_W80Vec x, w;
            U23_w80_vsub(&w, &t, &u);
            U23_w80_vadd(&x, &w, acc);
            *acc = x;
        }
    }
}


U24_W80Eff* func_002ed350(U24_W80Own* own, u32 a1, const U24_W80Param* prm, u32 a3, const U24_W80Vec* pos) {
    U24_W80Heap* h = (U24_W80Heap*)(own->heap + 20);
    U24_W80Eff* e;
    if (!h->f8) return 0;
    e = func_001db888(h, 128, __builtin_return_address(0));  // record_index_calc
    func_002ed558(e, own, a1, a3, func_002ed8a0);
    e->prm = *prm;
    e->pos = *pos;
    func_002ed5a8(e);
    return e;
}


void func_00319870(u8* p) {  // init_18x4_entries
    s32 i;
    u8* q;
    u8* s;
    u32* w;
    for (i = 18, q = p; i != -1; i--, q += 4) {
        q[0] = 0;
        q[1] = 0;
        q[2] = 0;
        q[3] = 0;
    }
    s = p + 76;
    w = (u32*)s;
    for (i = 0; i < 8; i++) w[i] = 0;
    s[287] = 0;
    q = p + 364;
    for (i = 31; i != -1; i--) *q++ = 0;
    p += 396;
    w = (u32*)p;
    for (i = 0; i < 4; i++) w[i] = 0;
    func_00319d30(p + 16);
}
}
