#include "../common/types.h"
#include <stdarg.h>

extern "C" {

// ---- 0x109070: reset of two small tables and two record arrays ----
struct Rec88 { u32 a; u32 b; u8 pad[80]; };
struct Rec288 { u32 a; u32 b; u32 c; u8 pad[276]; };
union P88 { Rec88* p; u32 u; u16 h; };
union P288 { Rec288* p; u32 u; u16 h; };
union I32 { s32 v; u32 u; u16 h; };
extern u32 D_0033cc78[5];
extern u32 D_0033cc90[5];
extern I32 D_0033cc68;
extern P88 D_0033cc6c;
extern P288 D_0033cc70;
extern I32 D_0033cc60;
extern u8 D_0033cca8;
extern void* D_00340ea8;
extern u32 D_0033cca4;

void func_00109070(void);  // 00109070: moved to src/anon/unit_001085a8.cpp

// ---- 0x10e6e0: probe at three heights; returns the agreeing result ----
s32 func_00184780(void*, s32, f32, f32, f32);
s32 func_0010e6e0(u8* p, s32 a, f32 x, f32 y, f32 z);  // 0x0010e6e0: definition moved into src/anon/unit_0010dee8.cpp

// ---- 0x117c28: constructor ----
union FU { f32 f; s32 i; };
void func_00113628(void*);
void func_0031a060(void*);
void* func_00114490(void*, s32);
void func_0011b6a8(void*);
void func_00117910(void*, s32);  // entry64_clear_fields
extern u8 D_003476f0[];
extern u8 D_00347588;
void func_00117c28(u8* p);  // 0x00117c28: definition moved into src/anon/unit_001178b8.cpp

// ---- 0x1285f8: binary search of x in a sorted float table -> bracketing indices ----
struct Curve { u8 pad[32]; s32 count; u8 pad2[32]; s32 off; };
void func_001285f8(u8* p, f32 x, s32* lo, s32* hi);  // 0x001285f8: definition moved into src/anon/unit_00128480.cpp

// ---- 0x13bb58 ----
s32 func_0013ba60(void*, s32, s32, u8*, s32, s32*, s32*);
u8* func_0013b5d0(void*, s32, s32, s32, u8, s32, s32, s32, f32, u32, s32);
u8* func_0013bb58(void* a0, u8* a1, s32 a2, s32 a3, u8 b, s32 c, s32 d);  // 0x0013bb58: definition moved into src/anon/unit_0013a8b8.cpp

// ---- 0x152820: screen rect of a sprite ----
void func_0023a9c0(void*, s32*, s32*);
u32 func_0023a918(void*);
s32 func_0023aa98(void*);
void func_00152820(u8* p, s32* x, s32* y, s32* r, s32* b, u32* fl);  // 0x00152820: definition moved into src/anon/unit_0014ecb8.cpp

// ---- 0x154c10 ----
void func_00138c10(void*, s32);
s32 func_00154910(void*);
s32 func_00154930(void*);
struct P154 { u8 pad[15552]; s32 a; s32 pad2; s32 b; s32 c; };
// 00154c10: moved to src/anon/unit_00153ea0.cpp
void func_00154c10(u8* p, s32 n);

// ---- 0x1863a8 ----
void func_001866f0(void*, s32, f32);
void func_001866a0(void*, s32, f32);
s32 func_0019c090(void*);  // obj_is_enabled
void func_001a2a18(void*);
void func_00186548(void*, s32, f32);
static inline bool flags_2_and_40(u32 fl) {
    bool b = false;
    if (fl & 2) { u32 m = fl & 0x40; b = m != 0; }
    return b;
}
// 001863a8: moved to src/anon/unit_00185d10.cpp
void func_001863a8(u8* p, s32 a, f32 x);

// ---- 0x192e50: expands '\r' markers in a string with formatted varargs ----
s32 func_00192440(char*, s32);  // is_byte_lt25
void memcpy(char*, char*, s32);
s32 func_00192c40(s32, char*);
char* func_00192388(char*);  // skip_control_codes
// 00192e50: moved to src/yasui/libys/message.cpp

// ---- 0x196540: id -> message ----
void func_001963c8(s32);
void func_00196540(s32 id);  // 0x00196540: definition moved into src/anon/unit_00195d00.cpp

// ---- 0x1b90f0 ----
s32 func_0016a080(void*);
s32 func_001b90f0(u8* o, u8* p);  // 0x001b90f0: definition moved into src/anon/unit_001b87a0.cpp

// ---- 0x1bcd08: unwinds a stack of entries once none are busy ----
s32 func_001bcf18(void*);
s32 func_001bcf38(void*);  // state_in_set_5_10_13to18
void func_001bc720(void*);
void func_001bd618(void*, s32);
void func_002ba2e8(s32, s32);
struct S2240 { u8 pad[2240]; void** sp; };
static inline bool entry_busy(void* e) {
    bool b = false;
    if (func_001bcf18(e) || func_001bcf38(e)) b = true;
    return b;
}
s32 func_001bcd08(u8* p);  // 0x001bcd08: definition moved into src/anon/unit_001bc568.cpp

// ---- 0x1c91c8 ----
void func_0017f488(void*, s32, f32, f32);
void func_0017f5e0(void*, s32, s32, f32, f32);
extern u8* D_00352130;
void func_001c91c8(void* unused, u8* p);  // 0x001c91c8: definition moved into src/anon/unit_001c91c8.cpp

// ---- 0x222080: allocates a node and links it at the head of a list ----
u8* func_00221f98(u8*);
struct Key { void* p; u8 b; };
void func_00221e28(Key*);
void func_002226b8(void*, s32);  // vec3_copy
void func_00222080(u8* list, u8* a1, s32 a2, s32 a3);  // 0x00222080: definition moved into src/anon/unit_00221e28.cpp

// ---- 0x2378c8: rotation matrix rows from Euler angles at +112 ----
f32 sinf(f32);
f32 cosf(f32);
void func_002378c8(f32* p, f32 z);  // 0x002378c8: definition moved into src/anon/unit_00237068.cpp

// ---- 0x23dd28 ----
void func_00106d40(void*, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32);
void func_00106de8(void*, s32, f32);
void func_00106c08(void*);
void func_0023dd28(u8* p, s32 i, s32 x, s32 y);  // 0x0023dd28: definition moved into src/anon/unit_0023d260.cpp

// ---- 0x240360 ----
extern void* D_0035ec88;
extern char D_003716b8[];
extern char* D_0035ebf8;
extern char* D_0035ebfc;
extern char* D_0035ec00;
void func_002ff2e8(void*, const char*);
s32 func_00240108(void);  // get_global_36eb68
void func_00240118(void*, s32, s32);
void func_00240360(s32 k);  // 0x00240360: definition moved into src/anon/unit_0023f5b8.cpp

// ---- 0x247c20 ----
extern void* D_0035ed20;
extern s8 D_0035ed44;
struct E408 { u8 pad[388]; s32 st; u8 pad2[16]; };
extern E408* D_0035ed34;
s32 func_002891e8(void*);
s32 func_002469a0(s32);
s32 func_00139d78(void*);
s32 func_00246840(void);
void func_00243230(s32, s32);
void func_00247c20(void);  // 0x00247c20: definition moved into src/anon/unit_00242478.cpp

// ---- 0x24bbb0 ----
extern void* D_0035edb0;
extern void* D_0035eda8;
extern void* D_0035edb8;
extern void* D_0035edb4;
struct E6 { s16 a, b, c; };
extern E6 D_00371ff0[];
s32 func_0023f0c0(void*);
void func_0023f070(void*, s32, s32);
s32 func_0028acc8(void*);
void func_0028ab20(void*);
void func_0024bbb0(void);  // 0x0024bbb0: definition moved into src/anon/unit_0024ba58.cpp

// ---- 0x24e9c0 ----
s32 func_001a6d08(s32);
union UP { u8* p; s32 i; };
extern s32 D_00372308[];
extern UP D_0035ee18[];
extern s32 D_0035ee08;
u8* func_0028c198(s32, s32, s32, s32, s32, s32);
s32 func_0024efc0(s32);  // to_28dbf8_entry6
void func_001396b0(void*);
void func_0031ac78(void*, s32);
void func_0024e9c0(void);  // 0x0024e9c0: definition moved into src/anon/unit_0024e7e8.cpp

// ---- 0x2816f0: reset state and release three owned objects ----
typedef void (*VFn)(void*);
extern s16 D_0035f280;
extern s32 D_0035f274;
extern u8 D_0035f299;
extern s32 D_0035f270;
extern s32 D_0035f278;
extern s32 D_0035f27c;
extern s32 D_0035f284;
extern void* D_0035f288;
extern void* D_0035f290;
extern void* D_0035f29c;
void func_002816f0(void);  // 0x002816f0: definition moved into src/anon/unit_0027f2b0.cpp
// ---- 0x284ef0 ----
void func_00287d68(void);  // copy_globals_3words
s32 func_00287db0(void);
extern s32 D_0035f2d4;
extern u8 D_0035f2d0;
s32 func_00284538(void);
u8* func_0014aba8(void);
void func_002843e8(void);
void func_001039f8(void);
s32 func_00287bc0(void);
void func_00285070(void);
void func_00284fd8(void);
s32 func_00284ef0(void);  // 0x00284ef0: definition moved into src/anon/unit_00284220.cpp
// ---- 0x286418 / 0x2864f8: flag-bit queries ----
struct Flags { u8 pad[200]; u32 bits[2]; };
struct Flags2 { u8 pad[204]; u32 bits[2]; };
extern Flags* D_0035f2e4;
s32 func_002812e0(void);
s32 func_00286418(s32 n);  // 0x00286418: definition moved into src/anon/unit_002853b8.cpp
Flags2* func_002859a0(void);
s32 func_002864f8(s32 n);  // 0x002864f8: definition moved into src/anon/unit_002853b8.cpp

// ---- 0x29c880 ----
union GB { u8* p; u16 h; u32 u; };
extern u8 D_0035f5c4;
extern GB D_0035f5ac;
u8* func_00276568(void);
void func_00287bd0(s32, s32);
void func_0029dd00(void);
void func_002765e8(s32, s32, s32);
void func_0029be08(void);
void func_0029c880(s8* p, s32 k);  // 0x0029c880: definition moved into src/anon/unit_0029ba88.cpp

// ---- 0x2b3df8: allocates one object, an array of three, and one more ----
typedef void* (*AllocFn)(void*, s32, s32);
union GA { u8* p; u32 u; void* v; };
extern GA D_00347f80;
extern u8 D_0035ebb8[];
struct T76 { void* vt; u32 f4, f8, f12; u8 pad[60]; };
static inline void* alloc76(s32 n) {
    void* a = *(void**)(D_00347f80.p + 20);
    return (*(AllocFn*)(*(u8**)a))(a, n, 0);
}
void func_002b3df8(GA* p);  // 0x002b3df8: definition moved into src/anon/unit_002b3ac8.cpp

// ---- 0x117e98: deleting destructor ----
struct Elem64 { u8 p8[8]; void* h; u8 d[52]; ~Elem64() {} } __attribute__((aligned(16)));
struct Obj117 { void* vt; u8 pad[28]; Elem64 e[24]; void* f1568; };
void func_001dc920(void*);
void func_0018f028(void*);
void func_00113668(void*);
void func_00105110(void*);
void func_00117e98(u8* p);  // 0x00117e98: definition moved into src/anon/unit_001178b8.cpp

// ---- 0x1ad638: destructor body (two arrays of polymorphic 344-byte members) ----
extern u8 D_00350a70[];
extern u8 D_00350ab0[];
extern u8 D_00350bb0[];
extern u8 D_00350a56;
void func_001c11a8(s32);
void func_0014c9f0(s32);
void func_00239870(void*);
void func_0031e668(void*);
void func_001ac5b8(void*);
struct NoTail { ~NoTail() {} };
// 001ad638: moved to src/anon/unit_001abb28.cpp

// ---- 0x31b4f0: constructor (member arrays of 408-byte objects) ----
extern u8 D_0034a820[];
extern u8 D_00347e60[];
void func_00239700(void*);
struct E408b { void* vt; u32 f4, f8, f12; u8 pad[8]; u8 sub[384]; };
void func_0031b4f0(u8* p) {
    *(u32*)(p + 12) = 0;
    *(void**)p = D_0034a820;
    E408b* e = (E408b*)(p + 48);
    for (s32 n = 5; n != -1; n--) {
        e->f12 = 0;
        e->vt = D_00347e60;
        func_00239700(e->sub);
        e++;
    }
    u8* row = p + 2496;
    for (s32 r = 15; r != -1; r--) {
        E408b* q = (E408b*)row;
        for (s32 n = 1; n != -1; n--) {
            q->f12 = 0;
            q->vt = D_00347e60;
            func_00239700(q->sub);
            q++;
        }
        row += 816;
    }
}
// ---- 0x31e398: deleting destructor ----
extern u8 D_0034e888[];
extern u8 D_00363828[];
extern u8 D_003637e0[];
void func_0031e590(void*);
void func_002ee380(void*);
void func_0031e398(u8* p) {
    void** q36 = (void**)(p + 36);
    u8* o = p + 80;
    *(void**)p = D_0034e888;
    *q36 = D_00363828;
    *(void**)o = D_00350ab0;
    if (o + 3280) {
        u8* e = o + 4656;
        u8* b = o + 3280;
        for (;;) {
            if (b == e) break;
            e -= 344;
            (**(VFn**)e)(e);
        }
    }
    func_00239870(o + 2936);
    func_0031e590(o);
    *q36 = D_003637e0;
    func_002ee380(p);
    func_00105110(p);
}

// ---- 0x2ca4c0 ----
s32 func_00289380(void*);
s32 func_00289310(void*);
void func_00287df0(s32, s32, s32, s32, s32);
void func_002cac40(s32);
void func_002ca5b8(void*);
void func_002ca0a8(void);
void func_002ca4c0(u8* p);  // 0x2ca4c0: moved to src/anon/unit_002ca0e0.cpp

// ---- 0x1c3060: re-registers flagged ids (high bit set) from two slot tables ----
void* func_001a80c8(u16);  // table24_find_by_id
void func_001c3150(void*, u16);
void func_001c35a0(void*);
struct O40 { u8 pad[580]; u8* a; u16* b; };
static inline __attribute__((always_inline)) void slots_a(u8* p, u8* a, u16* b) {
    if (a) {
        u16* e;
        s32 i;
        for (i = 0, e = (u16*)(a + 80); i < 80; i++, e++) {
            if (((u32)e[2] & 0xffff) >> 15) {
                u8* r = (u8*)func_001a80c8(e[2] & 0x7fff);  // table24_find_by_id
                if (!r[6] || !b) func_001c3150(p, e[2] & 0x7fff);
            }
        }
    }
}
static inline __attribute__((always_inline)) void slots_b(u8* p, u16* b) {
    if (b) {
        u16* e;
        s32 i;
        for (i = 0, e = b + 4; i < 24; i++) {
            if (((u32)*e & 0xffff) >> 15) func_001c3150(p, *e & 0x7fff);
            e++;
        }
    }
}
void func_001c3060(u8* p);  // 0x001c3060: definition moved into src/anon/unit_001c2b58.cpp

}
