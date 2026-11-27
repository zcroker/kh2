#include "./types.h"

// WORLD (0x105ee8-0x1060b8): the world id table (two-letter world names) and the area
// helpers that read it. Linked as one unit.

// World names (0x33cbb8, .data), the strings are in .rodata from 0x369f60.
const char* D_0033cbb8_def[19] asm("D_0033cbb8") = {
    "zz", "es", "tt", "di", "hb", "bb", "he", "al", "mu", "po",
    "lk", "lm", "dc", "wi", "nm", "wm", "ca", "tr", "eh",
};

// .rodata tables after the strings.
extern const u32 D_00369ff8_def[19] asm("D_00369ff8") = {
    0x8211, 0x8212, 0x8213, 0x8214, 0x8215, 0x8216, 0x8217, 0x8218, 0x8219, 0x821a,
    0x821b, 0x821c, 0x821d, 0x821e, 0x821f, 0x8220, 0x8221, 0x8222, 0x8223,
};
extern const u32 D_0036a048_def[9] asm("D_0036a048") = { 13, 14, 15, 16, 17, 18, 19, 20, 21 };
extern const u32 D_0036a070_def[9] asm("D_0036a070") = { 13, 14, 15, 16, 17, 18, 19, 20, 21 };

namespace WORLD {

extern u32 D_0033cbb8 asm("D_0033cbb8");

u32 GetName(s32 world_id) { return *(u32*)((u32)&D_0033cbb8 + ((u32)world_id << 2)); }

}  // namespace WORLD

// ---- 00105f00 (from src/anon/batch_w64.cpp)
namespace n00105f00 {
s32 strlen(void*) asm("strlen");
s32 strncmp(void*, u32, s32) asm("strncmp");
extern u32 D_0033cbb8[] asm("D_0033cbb8");
s32 func_00105f00(void* p) asm("func_00105f00");
s32 func_00105f00(void* p) {
    if (strlen(p) == 2) {  
        for (s32 i = 0; i < 19; i++) {
            if (strncmp(p, D_0033cbb8[i], 2) == 0) return i;
        }
    }
    return 0;
}
}  // namespace n00105f00

// ---- 00105f80 (from src/anon/tiny_more2.cpp)
namespace n00105f80 {
extern u32 D_00369ff8 asm("D_00369ff8");
u32 func_00105f80(u32 a0,u32 a1,u32 a2,u32 a3) asm("func_00105f80");
u32 func_00105f80(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; return *(u32*)((u32)&D_00369ff8 + ((u32)a0 << 2) + (0)); }
}  // namespace n00105f80

// ---- 00105f98 (from src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n00105f98 {
u32 func_001041a0(u32, u32, u32, u32) asm("func_001041a0");
extern u8 D_0036a070 asm("D_0036a070");
u32 func_00105f98(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00105f98");
u32 func_00105f98(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u;
    r2 = func_001041a0(r4, r5, r6, r7);
    r15 = (u32)&D_0036a070;
    r2 = (u32)(r2 << 2);
    r2 = (u32)(r2 + r15);
    r2 = *(u32*)((u32)r2 + (s32)(0));
    return r2;
}
}  // namespace n00105f98

// ---- 00105fc8 (from src/anon/batch_w41.cpp)
namespace n00105fc8 {
u8* func_001058e8(void) asm("func_001058e8");
u8 func_00105f98(void) asm("func_00105f98");
struct W41VObj { void (**vt)(W41VObj*); };
W41VObj* func_00102c80(void) asm("func_00102c80");
struct W41S10 { u8 a, b, c; u16 d, e, f; };
static inline void w41InitS10(W41S10* s, u16 v) { s->a = v; s->b = v; s->c = v; s->d = v; s->e = v; s->f = v; }
void WORLDMAP__gumiToWorldMap(void) asm("WORLDMAP__gumiToWorldMap");
void WORLDMAP__gumiToWorldMap(void) {
    W41S10 s;
    w41InitS10(&s, 0xffff);
    func_001058e8()[12] = 15;
    s.a = 15;
    func_001058e8()[13] = 0;
    s.b = 0;
    u8* p = func_001058e8();
    u8 v = func_00105f98();
    p[14] = v;
    s.c = v;
    W41VObj* o = func_00102c80();
    o->vt[0](o);
}
}  // namespace n00105fc8

// ---- 00106048 (from src/anon/batch_w46.cpp)
namespace n00106048 {
struct VObj { void (**vt)(VObj*); };
struct Col106 { u8 a, b, c; u8 pad; u16 d, e, f; };
u8* func_001058e8(void) asm("func_001058e8");
VObj* func_00102c80(void) asm("func_00102c80");
void func_00106048(void) asm("func_00106048");
void func_00106048(void) {
    Col106 c;
    u16 v = 0xffff;
    c.a = v; c.b = v; c.c = v; c.d = v; c.e = v; c.f = v;
    func_001058e8()[12] = 15; c.a = 15;
    func_001058e8()[13] = 0; c.b = 0;
    func_001058e8()[14] = 0; c.c = 0;
    VObj* o = func_00102c80();
    o->vt[0](o);
}
}  // namespace n00106048

