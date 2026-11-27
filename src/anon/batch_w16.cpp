#include "../common/types.h"

namespace Tz {
class Select {
public:
    u8 pad[24];
    u16 f24;
    u16 f26;
    u8 pad2[9];
    u8 f37;
    u8 f38;
    void Reset2DMode();
    void SetEnableButton(u32);
    void SetSelectDisable(u32);
};
}  // namespace Tz

u32 YS__ENEMY__Each(u32, u32, u32, u32);
u32 wtarget_001ce2a0(u32, u32, u32, u32);
void wtarget_001d9ca0(u32, u32, u32, u32);
void wtarget_002eaab0(u32, u32, u32, u32);

extern "C" {

typedef void (*VFn)(void*);
typedef void (*VFn1)(void*, void*);
typedef u32 (*VFnR)(void*);

void TASK_MANAGER__create_thread(u32, u32, u32, u32, u32);
void func_00105110(void*);
u8 func_00106420(void*);
void func_00113668(void*);
void* func_00124748(void*, u32);  // list_nth_node_rel
s32 func_001320f0(u8*);
u32 func_00132208(u8*);
void func_001322f0(void*);  // set_vtbl_347c00
void func_0013b258(void*);
void func_0013b1d0(void*);
void func_0013d208(void*);
void func_0013b1a0(void*);
u32 func_00139d78(void*);
void dk__COUNTER__close(void*);
void* func_001050c8(void*);
void func_00142940(u32, void*);
void func_001bdab0(u32);
void func_001776f8(void*);
void func_0016a2e0(void*);
u32 func_00196e88(void*, u32, u32, f32);
u8 YS__COMMAND_ELEM__Get(void);
u8 YS__OBJ__can_decide(u8*, u32);
u8 func_001ab598(u32, void*, u32, u32, u32, u32);
u32 func_001a3a78(void*);
void ryj__PAX__start(u32, u32, u32, u32, u32, void*);  // scan_list_by_half
u8 func_002fd248(u32, void*, u32, u32, void*);
u32 func_001bb4a0(void);
void func_001a4e30(void*);
u8* func_001bbcb0(void);
void* func_001e3650(void);  // ptr_add4
void* func_001e3660(void*, u32);
void* func_001e4248(void*);
void* func_001e4e18(void*);
void func_001e4320(void*);
void func_00226030(u32, u32, u8*);
void func_001de750(u32);
void func_002fde18(void*, u32, u32);
u8* func_001058e8(void);
void Tz__MenuUtil__GetLaySeq(u32, void*, void*);
void OvlShop__ItemShop__SetupConfirm(void);
void func_00240be0(void);
void func_0028f4d8(u32, u32, u32);
void func_002908f0(void*);
u8* func_002766d0(s32);
void func_0028dac8(void*, u32);
u8 func_002e7328(void*);  // to_2e7458
u8 func_002d2a08(void*);
u8 func_003167f8(void*);  // set_vtbl_367910
void func_003155e8(void*);  // set_vtbl_367878
void func_0031ffc0(void*);
void YS__OBJ__prepare_jump(u32, void*);
void func_0016bd60(u32, u32);
void func_001d9a18(void*, s32);
u32 YS__OBJ__Each(u32);

extern u32 D_0032b96c;
extern u8 D_00346cd8;
extern u8 D_00347c30;
extern u8* D_01c6cb78;
extern u32* D_01d48d90;
extern u8 D_00320448;
extern u32* D_01d5ba04;
extern u8 D_00321698;
extern u8* D_0035ec98;
extern u32 D_0035ee60;
extern u8 D_00372608[8];
extern u8 D_00372610[][8];
extern u8 D_0035f4b0;
extern u32* D_01e2bd00;
extern u8 D_00324bb0;
extern u8 D_003621a0;
extern u8 D_00367848;
extern u8 D_00367818;
extern u8 D_00352878;
extern u8 D_01d5baa0;
extern u8 D_003520d0;
extern void* D_003520c0;

// 00102c48: moved to src/common/unit_00102a70.cpp

// Destructor body: set vtable, destroy members, chain to the base.
void func_00115090(void* p);  // 0x00115090: definition moved into src/anon/unit_00114a90.cpp

u32 kn__ModelMulti__getHrc(void* a);  // 0x00123e00: definition moved into src/anon/unit_00123990.cpp

// Skips a header (size from func_001320f0 plus 8); 0 when the rest is invalid.
u8* func_00132130(u8* p);  // 0x00132130: definition moved into src/anon/unit_00131418.cpp

void func_00132590(void* p);  // 0x00132590: definition moved into src/anon/unit_00131418.cpp

void func_0013b260(void* p);  // 0x0013b260: definition moved into src/anon/unit_0013a8b8.cpp

// Deactivates every 28-byte entry whose id matches.
struct Ent28 {
    u8 active;
    u8 id;
    u8 pad[26];
};
void func_00145c28(u8* p, u8 id);  // 0x00145c28: definition moved into src/anon/unit_00145600.cpp

void func_0014f9a8(void* p);  // 0x0014f9a8: definition moved into src/anon/unit_0014ecb8.cpp

void func_0015b4c0(void* p);  // 0x0015b4c0: definition moved into src/anon/unit_0015b100.cpp

// Passes a stack copy of a 4x4 matrix.
void func_00165830(u8* p, void* m);  // 0x00165830: definition moved into src/anon/unit_001656b8.cpp

// 0017a230: moved to src/yasui/libys/player.cpp

// 00185a28: moved to src/anon/unit_001855e0.cpp

struct Flags2 {
    u16 a;
    u16 on : 1;
};
static inline u8 is_on(u8* p) { return (*(Flags2**)(p + 60))->on; }
void func_001973f0(u8* p);  // 0x001973f0: definition moved into src/anon/unit_00195d00.cpp

// 001a74f8: moved to src/anon/unit_001a6a10.cpp

u8 func_001aa940(u8* p, u32 a, u32 b, u32 c, u32 d);  // 0x001aa940: definition moved into src/anon/unit_001a9130.cpp

void YS__LEVELUP__ShowEffectDrive(void* p);  // 0x001b7468: definition moved into src/anon/unit_001b6a50.cpp

u8 func_001b8800(u32 a);  // 0x001b8800: definition moved into src/anon/unit_001b87a0.cpp

// 001bbf00: moved to src/yasui/libys/mission.cpp

// 001cced8: moved to src/anon/unit_001cc868.cpp

u8 func_001d23e0(u32 a);  // 0x001d23e0: definition moved into src/anon/unit_001d14e0.cpp

void func_001e4f00(void);  // 0x001e4f00: definition moved into src/anon/unit_001e0cb8.cpp

// 3D vector length (VU0).
f32 func_002229a0(void* v);  // 0x002229a0: definition moved into src/anon/unit_00222548.cpp

void func_0022e160(u32 a, u32 b, u8* c);  // 0x0022e160: definition moved into src/anon/unit_0022d358.cpp

// Offsets a 20-byte point: out = pos + (dx, dy).
struct Ent20 {
    s32 x, y;
    s32 ox, oy;
    u32 pad;
};
struct IdxEnt {
    u16 base;
    u16 pad;
};
void func_00237640(u8* p, s32 i, s32 j, s32 dx, s32 dy);  // 0x00237640: definition moved into src/anon/unit_00237068.cpp

void func_0023f0c8(u8* p, u32 v);  // 0x0023f0c8: definition moved into src/anon/unit_0023e5d0.cpp

// Clears the current 40-byte slot.
void func_00241320(void);  // 0x00241320: definition moved into src/anon/unit_0023f5b8.cpp

// Whether adding a to the counter stays within 999999.
u32 func_002424c0(u32 a);  // 0x002424c0: definition moved into src/anon/unit_00242478.cpp

void func_00251e90(s32 i);  // 0x00251e90: definition moved into src/anon/unit_00250fb8.cpp

void func_0025dba8(void);  // 0x0025dba8: definition moved into src/anon/unit_0025da20.cpp

void func_00290870(void* p);  // 00290870: moved to src/anon/unit_0028f1e0.cpp

void func_0029e258(s32 i);  // 0x0029e258: definition moved into src/anon/unit_0029d008.cpp

u8 func_002c22b8(u32 a);  // 0x002c22b8: definition moved into src/anon/unit_002c2228.cpp

u8 func_002d47e8(u8* p);  // 0x002d47e8: definition moved into src/anon/unit_002d4548.cpp

u8 func_00315700(void* p);  // 0x00315700: definition moved into src/libsupc++/tinfo.cpp

void func_003157b8(void* p);  // 0x003157b8: definition moved into src/libsupc++/tinfo.cpp

void func_00320c80(void* p);  // 0x00320c80: definition moved into src/anon/unit_00320528.cpp

}  // extern "C"

// Walks to the next object whose flag 0x10 (at +1416) is set.
// 00185da8: moved to src/anon/unit_00185d10.cpp

// Offset table lookup: entry a1 if in range and non-zero, else entry a2.
// 001ce2a0: moved to src/anon/unit_001cd660.cpp
u32 wtarget_001ce2a0(u32 a0, u32 a1, u32 a2, u32);

void wtarget_001d9ca0(u32 a0, u32 a1, u32, u32);  // 0x001d9ca0: definition moved into src/anon/unit_001d7458.cpp

void wtarget_002eaab0(u32 a0, u32 a1, u32, u32);  // 002eaab0: moved to src/anon/unit_002eaa68.cpp

// 0x0028b0e0: definition moved into src/anon/unit_00288b00.cpp
