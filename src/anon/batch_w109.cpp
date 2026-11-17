#include "../common/types.h"
extern "C" {
// ---- f2.cpp
s32 func_002282f0(u16);
void func_00225530(void);
s32 func_002ba200(void);
void func_002259f0(void);
void func_00225a00(void);  // zero_global_byte_e
void func_00102448(s32, s32);
void func_002ba220(u8, s32, s32, s32, s32, s32);
void func_002ba830(u8, s32, s32);
s32 func_002b7148(s32);
void func_00136b78(u8, s32);  // entry16_set_field8
extern s32 D_00370d88[];
extern s32 D_00370d78[];
void func_002253a0(u8* p, s32 arg);  // 0x002253a0: definition moved into src/anon/unit_00224780.cpp

// ---- f3.cpp
u8* func_001a1658(s32, s32);  // state_dispatch_0_1_14
void func_001a17c8(u8*);
bool func_001a1de0(u8*);
bool func_001a2758(u8*);
bool func_001a2778(u8*);
bool func_001a2798(u8*);
bool func_001a27b8(u8*);
static inline bool IsFullA(u8* p) { return *(s32*)(p + 0) >= *(s32*)(p + 4); }
static inline bool HasC(u8* p) { return p[433] < p[434]; }
static inline bool IsFullB(u8* p) { return !func_001a1de0(p) && *(s32*)(p + 384) >= *(s32*)(p + 388); }
// 001a2e50: moved to src/anon/unit_001a2a50.cpp

// ---- f4.cpp
s32 func_001a9528(u8*);
void func_001dddd0(s32, s32);
s32 func_001de168(s32, s32, s32, s32, s32, s32);  // scan_list_by_half
void func_001a9560(u8* self, s32 a1, s32 a2, s32* out);  // 0x001a9560: definition moved into src/anon/unit_001a9130.cpp

// ---- f5.cpp
extern char D_0036e978[];
extern char D_0036e998[];
extern char D_0036e9d0[];
extern char D_0036edb0[];
extern char D_0036edc0[];
extern char D_0036ede0[];
extern u8 D_01d9e450[];
u32 func_002fdfc8(const char*, ...);  // device_vprintf_va
void sceGsSetDefLoadImage(void*, s32, s32, s32, s32, s32, s32, s32);
void func_003058a0(s32);
void sceGsExecLoadImage(void*, void*);
static inline void assert_fail_1e52b8(const char* e, const char* f, s32 l) {
    func_002fdfc8(D_0036e978, e);  // device_vprintf_va
    func_002fdfc8(D_0036e998, f, l);  // device_vprintf_va
    asm volatile("break");
}
struct NoTail52b8 { ~NoTail52b8() {} };
void func_001e52b8(u8* p, s16 off);  // 0x001e52b8: definition moved into src/anon/unit_001e0cb8.cpp

// ---- f8.cpp
void func_00236d60(u8*);  // clear_64_entries_24
s32 func_00139d78(u8*);
void func_00139510(u8*);
s32 func_00139538(u8*);
void func_0014cbe0(s32*, s32*, s32*, s32*);
s32 func_002c5238(s32, s32, s32*);
s32 func_0023aa98(u8*);
s32 func_001396c0(u8*);
void func_00138c10(u8*, s32);
void func_00138c68(u8*, s32, s32);
void func_00139580(u8*);
void func_00139570(u8*);
void func_0023f0c0(u8*);
void func_002c1460(u8*, s32);
typedef void (*VFn2c14e8)(u8*);
struct F2c14e8 { u32 f : 1; };
void func_002c14e8(u8* self);  // 0x002c14e8: definition moved into src/anon/unit_002c10e0.cpp

// ---- f9.cpp
extern void* D_0034a920[];
extern void* D_00348678[];
extern void* D_003486d8[];
extern void* D_00347f98[];
extern void* D_00347e60[];
extern void* D_00348608[];
void func_0031d6b0(u8*);  // set_vtbl_3486a8_c
void func_00239870(u8*);
void func_0031cec0(u8*);
typedef void (*Dtor31d290)(u8*);
#define DestroyArr31d290(B, E, SZ) \
    if ((B) != 0) { \
        u8* e = (E); \
        u8* b = (B); \
        for (;;) { \
            if (b == e) break; \
            e -= (SZ); \
            (*(Dtor31d290*)(*(u8**)e + 12))(e); \
        } \
    }
static inline __attribute__((always_inline)) void Body31d290(u8* p) {
    *(void***)p = D_0034a920;
    DestroyArr31d290(p + 13232, p + 15600, 592);
    *(void***)(p + 12896) = D_00348678;
    *(void***)(p + 12928) = D_003486d8;
    func_0031d6b0(p + 12928);  // set_vtbl_3486a8_c
    *(void***)(p + 12896) = D_00347f98;
    DestroyArr31d290(p + 6704, p + 12884, 412);
    DestroyArr31d290(p + 5008, p + 6704, 848);
    DestroyArr31d290(p + 4180, p + 4996, 408);
    DestroyArr31d290(p + 3364, p + 4180, 408);
    DestroyArr31d290(p + 2548, p + 3364, 408);
    DestroyArr31d290(p + 1732, p + 2548, 408);
    *(void***)(p + 1324) = D_00347e60;
    func_00239870(p + 1348);
    *(void***)(p + 1324) = D_00347f98;
    *(void***)(p + 916) = D_00347e60;
    func_00239870(p + 940);
    *(void***)(p + 916) = D_00347f98;
    *(void***)p = D_00348608;
    func_0031cec0(p + 64);
    *(void***)p = D_00347f98;
}
// Destructor: resets vtables and destroys the member object arrays (last to first).
void func_0031d290(u8* p) {
    Body31d290(p);
}
typedef void (*Free31d290)(u8*, u8*);
extern u8* D_00347f80;
// Deleting destructor: same, then frees through the global allocator.
void func_0031d490(u8* p) {
    Body31d290(p);
    asm volatile("" ::: "memory");  // keeps the final vtable store ahead of the allocator lookup
    u8* a = *(u8**)(D_00347f80 + 20);
    (*(Free31d290*)(*(u8**)a + 4))(a, p);
}

// ---- f12.cpp
struct List27ff00 {
    u8 pad[4];
    u8 count;
    u8 b5;
    s8 b6;
    s8 b7;
    s8 ids[40];
    s8 keys[40];
};
struct Ent27ff00 {
    s32 id;
    s32 flag;
    u8 pad[12];
    s32 key;
};
extern List27ff00* D_0035f260;
void func_002fde18(void*, s32, s32);
s32 func_002f1ab8(void);
Ent27ff00* func_002f1ac8(s32);
s32 func_002f1ae0(s32);
void func_0027ff00(void);  // 0x0027ff00: definition moved into src/anon/unit_0027f2b0.cpp

// ---- f14.cpp
extern s32 D_0035f200;
s32 func_00289380(s32);
s32 func_00287cd0(void);
s32 func_00287bc0(void);
s32 func_00276368(void);
s32 func_0028acc8(s32);
s32 func_00276888(void);
void func_00287f90(s32);
void func_00297010(void);
s32 func_00292630(void);
void func_00276690(s32);
void func_00287c30(void);
void func_0028af18(s32, s32);
void func_0028b1e8(s32, s32);
void func_00274cf0(s32);  // state_dispatch_0_1_2
void func_002925c0(void);
s32 func_00276358(void);
void func_00276220(s32, s32);
void func_002958b0(void);
s32 func_00289310(s32);
s32 func_00276398(void);  // state_is_150
void func_00275b60(void);
void func_00287c90(s32);
s32 func_00287df0(s32, s32, s32, s32, s32);
s32 func_00242848(s32);
void func_00287da0(void);
s32 func_00288040(void);
void func_00288018(void);  // global_zero_4dwords
void func_0028f6f0(s32);  // record884_refresh_by_index
void func_00297008(void);
void func_00276dc0(void);
void func_00287c00(s32);
void func_00287cc0(s32);
void func_00297630(void);  // 0x00297630: definition moved into src/anon/unit_00295d28.cpp

// ---- f17.cpp
struct G139f38 { s32 x0; s32 x4; s32 x8; u8 pad[8]; G139f38* x20; };
union U139f38 { G139f38* p; void* q; };
extern U139f38 D_00347f80_u asm("D_00347f80");
struct T139f38 { u8 pad[4]; void* x4; u8 pad2[40]; void* x48; };
void func_00139dc0(s32);
s32 func_00102c80(void);
s32 func_00103070(void);
s32 func_001045f0(void);
void func_00102180(s32*);
T139f38* func_00102c18(s32, s32, void*);
T139f38* func_00102f08(s32, s32, void*);
T139f38* func_00104588(s32, s32, void*);
s32 func_001024b0(G139f38*);
T139f38* func_00102788(s32, s32, s32, void*);
void func_00139de8(void);
void func_00139390(void);
void func_001393c8(void);
void func_001394c0(void);
void func_001394d8(void);
void func_00139308(void);
void func_00139f38(G139f38* arg);  // 0x00139f38: definition moved into src/anon/unit_001393c8.cpp

// ---- f18.cpp
struct D1ddef0 { u16 id; u8 pad[14]; u32 flags; f32 radius; u8 pad2[4]; f32 v[12]; };
u8* func_001dcff0(u8*, u16, f32);
f32* func_001dc5f8(u8*);
f32* func_001dc648(u8*);
f32* func_001dc620(u8*);
u8* func_001de948(s32);
void func_001dea80(u8*, u8*, D1ddef0*, u8*, f32);
void func_001df670(u8*);
void func_00180df8(u8*, u8*);
extern s32 D_00352b50;
// Builds an entry from a descriptor and pushes its node onto the owner list head.
u8* func_001ddef0(u8* self, D1ddef0* d, s32 a2, s32 a3, s32 a4, u8* w);  // 0x001ddef0: definition moved into src/anon/unit_001ddcf0.cpp

// ---- f19.cpp
extern s32 D_0035f01c;
extern s32 D_0035ef6c;
extern s32 D_0035f04c;
extern s32 D_00373278;
extern s32 D_0037327c;
u8* func_00257770(void);
s32 func_00257130(void);
s32 func_00281f18(s32);
s32 func_002892f8(s32);
u8* func_002891b8(s32, s32);
void func_00138c10(u8*, s32);
s32 func_00192048(s32);
void func_00262af8(void);
s32 func_0028b038(s32);
void func_002827f0(s32, s32, s32);
u8* func_00281f30(s32);
struct E262820 { u16 id; u16 pad[2]; };
E262820* func_00281f20(s32);
void func_0028be78(s32, s32);
s32 func_00285d58(u16);
s32 func_00285e30(u16);
void func_00262820(void);  // 0x00262820: definition moved into src/anon/unit_0025f6b8.cpp

// ---- f20.cpp
extern u8* D_0035f60c;
extern s32 D_0035f3d4;
extern s32 D_0035f148;
extern s32 D_0035f14c;
extern s32 D_0035f210;
u8* func_002766d0(void);
void func_0028d980(u8*, s32, s32, s32, s32, s32, s32, s32, s32);
void func_0028d8c0(u8*, s32, s32, s32, s32, s32, s32, s32);
s32 func_0023aa78(u8*);
s32 func_0023aa18(u8*);
s32 func_0023aa38(u8*);
void func_00139620(u8*);
void func_00138c68(u8*, s32, s32);
void func_0028dcc0(u8*, u8*);
void func_00138c10(u8*, s32);
void func_002a92d8(void);  // 0x002a92d8: definition moved into src/anon/unit_002a92a0.cpp

// ---- f21.cpp
struct V4dcf90 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct V3dcf90 { f32 x, y, z; };
void func_002dcf90_i(u8* self) asm("_Z13func_002dcf90i");
void func_002dcf18(u8*);
s32 func_002dc7f8(u8*);  // get_global_35e958
s32 func_00106a18(s32);  // buffer_get_256
void func_00106de8(s32, s32, f32);
void func_00106c08(s32);
s32 func_00106a60(s32);  // buffer_get_by_index
V4dcf90* func_0016c028(s32);  // obj_get_attach_or_alt
u8* func_002dc7c8(u8*);
f32 func_002dceb0(u8*);
f32 sinf(f32);
f32 cosf(f32);
void func_00107340_c(s32, f32, f32, f32) asm("_ZN2kn6Camera12setReferenceEfff");
void func_00107330_c(s32, f32, f32, f32) asm("_ZN2kn6Camera11setPositionEfff");
// Sets the view reference point and orbit position from the interpolated angle.
void func_002dcf90_i(u8* self);  // 0x002dcf90: definition moved into src/anon/unit_002da040.cpp

}
