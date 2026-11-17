#include "../common/types.h"
extern "C" {

typedef void (*VF1593)(void*);
struct VT1593 { void* f[8]; };
struct Obj1593 { VT1593* vt; };

// ---- 0026ebc0
struct Big1593 { Obj1593 o; u8 pad[0x1b4 - 4]; };
s32 func_00139d78(void*);
void func_0026e340();
void func_0028abe0(void*);
s32 func_0028acc8(void*);
s32 func_0028d6e8(void*);
extern Big1593* D_0035f104;
extern void* D_0035f10c;
extern Obj1593* D_0035f110;

void func_0026ebc0(void);  // 0x0026ebc0: definition moved into src/anon/unit_0026c450.cpp

// ---- 00258630
struct MenuMode1593 { u32 a; u32 list; };
MenuMode1593* getMenuMode1593() asm("_Z11getMenuModev");
s32 func_00102a38(u32, u32);
void func_00102818(u32, u32, u32, u32, u32);
void func_001039f8();
void func_002530c8();
void func_00258a30();
void func_00287ad0();
s32 func_00287db0();
extern u8 D_002586e0[];
extern s16 D_0035f06c;

s32 func_00258630(void);  // 0x00258630: definition moved into src/anon/unit_002584c8.cpp

// ---- 002695a0
u32 func_00257130();
s32 func_002827e0(u32, s32);
s32 func_002813b8();
s32 func_00281420();

s32 func_002695a0(s32 a);  // 0x002695a0: definition moved into src/anon/unit_00268b30.cpp

// ---- 0028abe0 Tz::Select::Destroy
union ItemU1593 { Obj1593* p; s16 h; u8 c; };
struct Sel1593 { u32 a; s16 n; u8 pad[0x22]; ItemU1593* items; };
void sel_destroy1593(Sel1593* p) asm("_ZN2Tz6Select7DestroyEz");
void sel_destroy1593(Sel1593* p);  // 0x0028abe0: definition moved into src/anon/unit_00288b00.cpp

// ---- 0028c2c8
struct S28c2c8 { u8 pad[184]; u32 flags; void Set() { flags |= 8; } void Clr() { flags &= ~8; } };
struct W28c2c8 { u8 pad[24]; S28c2c8 sub; u8 pad2[436 - 24 - 188]; u32 f436; };
struct P28c2c8 { u8 pad[14080]; s32 free[32]; s32 n; };
extern P28c2c8* D_0035f3c4;
union C28c2c8 { s32 i; u32 u; };
extern C28c2c8 D_0035f3cc;
void func_0028c0a0(W28c2c8*, u32, u32, u8*, u32, u32);
W28c2c8* func_0028c2c8(u32 h, u8* z, u32 id, u32 c, u32 d);  // 0x0028c2c8: definition moved into src/anon/unit_0028bfc0.cpp

} // extern "C"
