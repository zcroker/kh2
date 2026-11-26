#include "../common/types.h"

// ---- 002abba8 ----
struct W1790Sram { u8 pad[0x140]; u32 bits[4]; };
static inline int w1790_bitTest(u32* p, u32 i) { return p[i >> 5] & (1 << (i & 0x1f)); }
static inline void w1790_bitSet(u32* p, u32 i) { *(u32*)((u8*)p + ((i >> 5) << 2)) |= (1 << (i & 0x1f)); }

// ---- 002be630 ----
struct W1790V4 { f32 x, y, z, w; };

// ---- 0013aba8 ----
struct W1790Pos { u8 pad[328]; s32 x, y; };
struct W1790Obj { u8 p0[24]; u8 seq[344]; s32 a170, a174; u8 p178[60]; W1790Pos pos; u8 p[780 - 436 - 336]; s32 v30c; };

// ---- 00148470 ----
struct W1790Node { u8 p0[235]; u8 eb; struct W1790Node* ec; struct W1790Node* f0; u32 f4; u32 f8; u8 pfc[32]; u16 h11c; u8 b11e; u8 b11f; };
struct W1790Flag { u32 f : 1; u32 r : 31; u32 pad; };
struct W1790Mgr { u8 p[17252]; W1790Flag tbl[1]; };
static inline u32 w1790_tst(u8* base, u32 off) { return ((W1790Flag*)(base + off))->f; }
static inline W1790Node* w1790_next(W1790Node* n, W1790Node* c) { return c == 0 ? n->f0 : c->ec; }

void func_0017f488(int, int, float, float);

extern "C" {
W1790Sram* jm_GetSram(void) asm("_ZN2Tz9JmNewInfo7GetSramEv");
s32 Tz__JmSynthe__isEnableRecipe(void);
s32 Tz__JmSynthe__isEnableMaterial(void);
extern W1790Sram* D_0035f610;

s32 func_0016b740(s32);
void YS__OBJ__attach(u32, u32, u32, u32) asm("_Z15YS__OBJ__attachjjjj");
void wtarget_0016b070(u32, W1790V4*) asm("_Z16wtarget_0016b070jjjj");
void func_002fd188(void (*)());
void D_002be6e8();
extern s8 D_01e2bc20;
extern W1790V4 D_01e2bc30;
extern s32 D_0034e948;

void dk__Sprite__draw(W1790Obj*);
void dk__SpriteMessage__drawMessage(W1790Obj*);
void seq_GetActiveXY(void*, s32*, s32*) asm("_ZN2YI8SEQUENCE11GetActiveXYEPiS1_");
s32 seq_GetParamX(void*) asm("_ZN2YI8SEQUENCE9GetParamXEv");
s32 seq_GetParamY(void*) asm("_ZN2YI8SEQUENCE9GetParamYEv");
void YI__SEQUENCE__Draw(W1790Pos*);
extern s32 D_0034805c;

void func_00148a68(W1790Mgr*, W1790Node*);
void func_00147f08(W1790Mgr*, W1790Node*);

void func_002abba8(void);  // 0x002abba8: definition moved into src/anon/unit_002a99c8.cpp

void func_002be630(void);  // 0x002be630: definition moved into src/anon/unit_002be020.cpp

void dk__COMMAND_ONE__draw(W1790Obj* o);  // 0x0013aba8: definition moved into src/anon/unit_0013a8b8.cpp

void dk__OctDrawFile__drawModel(W1790Mgr* g, W1790Node* n);  // 0x00148470: definition moved into src/anon/unit_00147140.cpp
}
