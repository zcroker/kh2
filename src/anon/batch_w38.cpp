#include "../common/types.h"

// An empty-destructor local keeps a cleanup pending, which stops gcc from
// turning the final call into a sibling call.
struct NoTail { ~NoTail() {} };

// 16-byte element with an empty destructor; arrays of it get a destructor loop.
struct E16 { u8 d[16]; ~E16() {} };
struct Q128 { u32 w[4]; } __attribute__((aligned(16)));

extern "C" void func_00106420(void*);
extern "C" void func_00105110(void*);
extern "C" void func_0018d420(void*);
extern "C" void func_002d0f38(void*);
extern "C" void* D_00350758[];
extern "C" void* D_003625e0[];

// Base-part destructors run last, after the member arrays.
struct Head18d420 { u32 vt; ~Head18d420() { func_0018d420(this); } };
struct Obj1a4060 {
    Head18d420 head;
    u8 pad4[204];
    E16 arr[32];
    u32* f720;
    ~Obj1a4060() { *(void**)this = D_00350758; *f720 = 0; }
    static void operator delete(void* p) { func_00105110(p); }
};

struct Head2d0f38 { u32 vt; ~Head2d0f38() { func_002d0f38(this); } };
struct Obj325498 {
    Head2d0f38 head;
    u8 pad4[3228];
    E16 arr[8];
    ~Obj325498() { *(void**)this = D_003625e0; }
    static void operator delete(void* p) { func_00105110(p); }
};

struct Obj287f30 {
    u8 pad[32];
    E16 arr[2];
    static void operator delete(void* p) { func_00106420(p); }
};

void func_001064a8(void*) asm("_Z13func_001064a8Pv");  // int_to_float_scaled

extern "C" {

void LeadDataSetText(u8*, u32) asm("_ZN2Tz15LeadDataSetTextEPvj");
void CmItem_FadeOutTop(void*) asm("_ZN2Tz6CmItem10FadeOutTopEv");
void CmItem_FadeOutWarn(void*) asm("_ZN2Tz6CmItem11FadeOutWarnEv");
void Select_End(void*) asm("_ZN2Tz6Select3EndEv");
void MenuCursor_AttachSprite(u8*, u32) asm("_ZN2Tz10MenuCursor12AttachSpriteEz");

s32 func_002fea18(void);
void __fixunssfsi(f32);

// Deleting destructor.
// 001a4060: moved to src/anon/unit_001a3e70.cpp

// Deleting destructor.
void func_00325498(Obj325498* p);  // 0x00325498: definition moved into src/anon/unit_00324808.cpp

extern Obj287f30* D_0035f324;
void func_00287f30(void);  // 0x00287f30: definition moved into src/anon/unit_00286d28.cpp

}

// Scales n by a random fraction.
// 001064a8: moved to src/anon/unit_00106490.cpp

extern "C" {

// Hides every 2D object owned by `owner`.
struct Node1399c0 { u32 f0; Node1399c0* next; u8 pad8[8]; void* owner; };
struct List1399c0 { u32 f0; Node1399c0* head; };
extern List1399c0* D_00347f80;
void func_00139598(Node1399c0*);
static inline Node1399c0* nextNode(Node1399c0* o) {
    List1399c0* l = D_00347f80;
    if (!o) return l->head;
    return o->next;
}
void func_001399c0(void* owner);  // 0x001399c0: definition moved into src/anon/unit_001393c8.cpp

void func_0015a850(void);
void func_00153c80(void);
void func_0014f148(void);
void func_0014f220(void);
void func_0014f1e0(void);
void func_0014f288(void);
void func_0015edb8(void);
void func_00165968(void);
void func_00149bd0(void*);
void func_00149de0(void*);
extern u8 D_00348d68[];
// 00149ec0: moved to src/harata/libdk/area.cpp

void func_001666f0(u8*, u16, u32, u16, u16);  // obj_store_masked
// 0014dca8: moved to src/anon/unit_0014d680.cpp

void func_00166808(u8* p, u8 k, u16 a, u32 b, u16 c, u16 d, s16 x, s16 y);  // 0x00166808: definition moved into src/anon/unit_001664c0.cpp

// RGBA bytes to a float colour normalised by 255 (VU0).
void func_00153540(f32* v, u8 r, u8 g, u8 b, u8 a);  // 0x00153540: definition moved into src/anon/unit_00153158.cpp

f32 func_00166d38(void*);
f32 func_00166d10(void*, u32);
void func_00154cd0(void*, s32, f32);
struct In155658 { u8 pad[4]; u32 f4; };
struct Ob155658 { u8 pad[1164]; In155658* f1164; };
struct P155658 { u8 pad[36]; void* f36; u8 pad2[12]; Ob155658* f52; };
// 00155658: moved to src/anon/unit_00153ea0.cpp
void func_00155658(P155658* p);

extern Q128 D_004f37b0, D_004f37a0, D_004f3790, D_004f3780, D_004f37e0, D_004f37d0;
static inline void qcopy(void* d, const void* s) {
    if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
// 0015cff0: moved to src/anon/unit_0015cdb0.cpp

// Finds the next entry, optionally with a matching id (-1 = any).
u8* func_0016bba8(void*, void*, u8*);
u8* func_0016bc20(void* a, void* b, s32 id);  // 0x0016bc20: definition moved into src/anon/unit_00169f98.cpp

void func_003058a0(s32);
void func_001707d8(void);
void func_0014d430(void);
extern volatile u8 D_0034dcac;
void func_0016f9e8(void);  // 0x0016f9e8: definition moved into src/anon/unit_0016e8f8.cpp

void func_00180c38(void*);
void func_00180ef0(void*);
typedef void (*Fn1)(void*);
// 00180ce0: moved to src/anon/unit_00180408.cpp

void* func_0018c8b8(void);
void func_0018c960(void*, u32, u32, u32, u32);
// 0018c8f0: moved to src/yasui/libys/damage.cpp

struct Pair192320 { u32 a; u32 b; };
extern Pair192320 D_01c61970[3];
extern u32 D_0033caf4;
extern const char D_0036cda0[];
void func_002fee78(char*, const char*, u32);
u32 func_001b1490(const char*);
void func_00191f78(s32, u32);
// 00192320: moved to src/yasui/libys/message.cpp

struct S1964d8 { u8 a, b, c; u16 d, e, f; };
S1964d8 func_00196328(u32);
void func_001967f0(u8, u8, s32);
void func_001964d8(u32 x);  // 0x001964d8: definition moved into src/anon/unit_00195d00.cpp

extern s32 D_00351f30;
extern u32 D_01d49980[];
s32 func_001c9d88(u32);
s32 func_001c9c00(void);  // 0x001c9c00: definition moved into src/yasui/libys/sacrifice.cpp

extern void* D_00352668;
extern u8 D_0036e3d0[];
void func_001a5420(void*, void*, void*);
void func_001d2930(void* a, s32 n);  // 0x001d2930: definition moved into src/anon/unit_001d2810.cpp

extern const char D_0036e598[];
extern u32 D_0035276c;
u8* func_00168b88(u32, s32, u32, s32);  // find_entry16_by_half_word
void func_001c10b8(u32);
void func_001d53e8(void);  // 0x001d53e8: definition moved into src/anon/unit_001d4f40.cpp

struct Item1d59b0 { u8 d[60]; };
struct Tbl1d59b0 { u32 f0; s32 count; Item1d59b0 items[1]; };
extern Tbl1d59b0* D_01d5ba6c;
void func_001d5960(void*);
void func_001d59b0(void);  // 0x001d59b0: definition moved into src/anon/unit_001d4f40.cpp

s32 func_001db200(void*, s32);
s32 func_001db250(void*);
s32 func_001db198(void* p, s32 n);  // 0x001db198: definition moved into src/anon/unit_001d9d00.cpp

void func_001e1728(void*);
void func_001e2238(u8* p);  // 0x001e2238: definition moved into src/anon/unit_001e0cb8.cpp

// Ring-buffered command queue (64 entries).
struct Q234460 { s32 type; s32 id; u32 a[6]; };
extern s32 D_0035e360;
extern s32 D_0035e368;
extern Q234460 D_01dadc00[64];
s32 func_00234460(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);  // 0x00234460: definition moved into src/anon/unit_002335e8.cpp

s32 func_002344c0(u32 a, u32 b, u32 c, u32 d, u32 e);  // 0x002344c0: definition moved into src/anon/unit_002335e8.cpp

u32 func_00168aa0(u32, s32);
void LeadDataSetText(u8* p, u32 id);  // 0x0023fa08: definition moved into src/anon/unit_0023f5b8.cpp

u8* func_00257770(void);
s32 func_00287bc0(void);
void func_0028dac8(void*, s32);
s32 func_0028acc8(void*);
s32 func_0028acb8(void*);
void func_0028aa40(void*);
extern void* D_0035f01c;
void CmItem_FadeOutTop(void*);  // 0x002620a0: definition moved into src/anon/unit_0025f6b8.cpp

void CmItem_FadeOutWarn(void*);  // 0x00262c40: definition moved into src/anon/unit_0025f6b8.cpp

s32 func_00103b38(void);
extern s8 D_0035f348;
extern u32 D_0035f34c;
extern u32 D_0035f350;
void Select_End(void*);  // 0x00288b78: definition moved into src/anon/unit_00288b00.cpp

void func_001396b0(void*);
void func_00139660(void*);
void func_00139688(void*);
void func_0031a260(void*, s32);
// 0028dcc0: moved to src/anon/unit_0028c878.cpp

u8* func_002bc158_0(void) asm("func_002bc158");
u8* func_002bc158_1(u32) asm("func_002bc158");
void func_002bb1c8(void*, u32, u32);
void func_002bb310(void*, u32, u32, u32);
u32 func_002bc188(u32 a, u32 b);  // 0x002bc188: definition moved into src/anon/unit_002bb8b0.cpp

u32 func_002bc2e8(u32 a, u32 b, u32 c);  // 0x002bc2e8: definition moved into src/anon/unit_002bb8b0.cpp

void func_001dc978(void*, f32);
void* func_001de168(u32, u32, s32, s32, s32, void*);  // scan_list_by_half
void func_002c5658(u8* p, u32 a, u32 b);  // 0x002c5658: definition moved into src/anon/unit_002c53c8.cpp

// Pushes a 16-byte value into a ring buffer, overwriting the oldest when full.
struct Ent2cb828 { Q128 v; u8 pad[16]; };
struct Ring2cb828 { u32 f0; s32 head; s32 cnt; s32 cap; u8 pad[112]; Ent2cb828* buf; };
Ent2cb828* func_002cb828(Ring2cb828* r, Q128* src);  // 0x002cb828: definition moved into src/taito/path.cpp

void func_00110500(u8*);
Q128* func_0010fa28(u8*);  // ptr_add3072
Q128* func_0010fa58(u8*);
// 002f0af0: moved to src/naka/libkn/trapfunctions.cpp

extern void* D_0034a800[];
extern void* D_00347f98[];
extern u8 D_00347e60;
void func_002361d0(void*);
void func_00239870(void*);
typedef void (*VFn2)(void*, void*);
extern void* D_00347f80v asm("D_00347f80");
// Destructor body: unwinds the vtables and unregisters from the manager.
void func_0031cf18(u8* p);  // 0x0031cf18: definition moved into src/anon/unit_0031b9e0.cpp


// Bitfield members carry the struct's alias set, so these loads stay after
// the float stores as in the original.
struct Out1fbb20 { u8 pad[32]; f32 f32_; u32 f36; f32 f40; u16 f44; };
struct In1fbb20 { u32 id; u8 pad[8]; f32 f12; u16 f16 : 16; u16 f18 : 16; };
void func_001facf8(u8*, In1fbb20*, u8*);
void func_001fbb20(u8* p, In1fbb20* q, u8* r);  // 0x001fbb20: definition moved into src/anon/unit_001fb350.cpp

void* func_001d9e30(void*);  // record_range_check_or_first
s32 func_001d9d48(void*);
s32 func_00276c18(void);
s32 func_002b3ae8(void);  // 0x002b3ae8: definition moved into src/anon/unit_002b3ac8.cpp

}
