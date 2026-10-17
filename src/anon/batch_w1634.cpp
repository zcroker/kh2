#include "../common/types.h"

struct W1634CharaData {
    u32 id;
    u8 type;
    u8 pad5[79];
    u8 cost;
    u8 pad55[2];
    s8 level;
};

extern "C" {
extern u8 D_0032f054;
void* W1634_AREA_Alloc(u32) asm("_ZN4AREA5AllocEj");
W1634CharaData* W1634_GetCharaData(u32) asm("_ZN2Tz6JmInfo12GetCharaDataEj");
u32 W1634_SORA_GetEntryId(s32) asm("_ZN2YS4SORA10GetEntryIdEi");
s32 W1634_AREADATA_CanAddCost(f32) asm("_ZN2YS8AREADATA10CanAddCostEf");
s32 func_0016f6f8(u32);
s32 func_0016f770(u32);
s32 func_0016f7a0(u32);
void func_00197fe0(void*, W1634CharaData*, s32, void*, f32);
void* func_00179fd0(W1634CharaData*, s32, void*, f32);
void* func_0017e418(W1634CharaData*, void*, f32);
void func_001aea00(void*, W1634CharaData*, void*, f32);
void func_001b1d60(void*, W1634CharaData*, void*, f32);
void func_00195ed8(void*, W1634CharaData*, void*, f32);
void func_001b3a90(void*, W1634CharaData*, void*, f32);
void func_001a8618(void*, W1634CharaData*, void*, f32);
void func_001aeb40(void*, W1634CharaData*, void*, f32);
void func_001b20a0(void*, W1634CharaData*, void*, f32);
void func_001a6bc8(void*, W1634CharaData*, void*, f32);
void func_0018aba0(void*, W1634CharaData*, s32, void*, f32);
void* func_002d0290(W1634CharaData*, void*, f32);
void* func_002be800(W1634CharaData*, void*, f32);
void func_001bf270(void*, W1634CharaData*, void*, s32, f32);
void func_001c7fb8(void*, W1634CharaData*, void*, f32);
void func_001c2338(void*, W1634CharaData*, void*, f32);
void func_001c4120(void*, W1634CharaData*, void*, f32);
void* func_001c25e8(W1634CharaData*, void*, f32);
void func_001c2ce8(void*, W1634CharaData*, void*, f32);
void func_001d9ef0(void*, W1634CharaData*, void*, f32);

}

// Allocates an SZ-byte object from the area heap and runs its constructor F on it.
typedef void (*W1634Ctor)(void*, W1634CharaData*, void*, f32);
template <W1634Ctor F, u32 SZ>
static inline void* W1634New(W1634CharaData* cd, void* pos, f32 rot) {
    void* p = W1634_AREA_Alloc(SZ);
    F(p, cd, pos, rot);
    return p;
}

// Builds the object for a chara data entry of the given type (0 if the type creates nothing).
static inline __attribute__((always_inline)) void* W1634Create(W1634CharaData* cd, void* pos, f32 rot) {
    switch (cd->type) {
    case 0:
        return (void*)func_00179fd0(cd, cd->level, pos, rot);
    case 1:
        return (void*)func_0017e418(cd, pos, rot);
    case 3:
        return (void*)W1634New<func_001aea00, 0xb00>(cd, pos, rot);
    case 4:
        return (void*)W1634New<func_001b1d60, 0xb00>(cd, pos, rot);
    case 7:
        return (void*)W1634New<func_00195ed8, 0xa00>(cd, pos, rot);
    case 9:
        return (void*)W1634New<func_001b3a90, 0xaf0>(cd, pos, rot);
    case 10:
        return (void*)W1634New<func_001a8618, 0xa00>(cd, pos, rot);
    case 12:
        return (void*)W1634New<func_001aeb40, 0xb00>(cd, pos, rot);
    case 13:
        return (void*)W1634New<func_001b20a0, 0xaf0>(cd, pos, rot);
    default:
        return (void*)W1634New<func_001a6bc8, 0xaf0>(cd, pos, rot);
    case 15:
        { void* p = W1634_AREA_Alloc(0xb40); func_0018aba0(p, cd, 5, pos, rot); return p; }
    case 16:
        return (void*)func_002d0290(cd, pos, rot);
    case 17:
        return (void*)func_002be800(cd, pos, rot);
    case 18:
        { void* p = W1634_AREA_Alloc(0x9f0); func_001bf270(p, cd, pos, 0, 1.0f); return p; }
    case 19:
        return (void*)W1634New<func_001c7fb8, 0xd00>(cd, pos, rot);
    case 20:
        return (void*)W1634New<func_001c2338, 0xa00>(cd, pos, rot);
    case 21:
        return (void*)W1634New<func_001c4120, 0xb00>(cd, pos, rot);
    case 22:
        return (void*)func_001c25e8(cd, pos, rot);
    case 23:
        return (void*)W1634New<func_001c2ce8, 0xaf0>(cd, pos, rot);
    case 24:
        return (void*)W1634New<func_001d9ef0, 0xa00>(cd, pos, rot);
    case 14:  // same as default; this extra copy reproduces the original's aligned default label
        return (void*)W1634New<func_001a6bc8, 0xaf0>(cd, pos, rot);
    }
    return 0;
}

extern "C" {
// Creates the object for chara id at pos with rotation rot (class picked by the chara data type).
// The original keeps the result in the id register, so id doubles as the result variable here.
void* func_0016f000(u32 id, void* pos, f32 rot) {
    W1634CharaData* cd;
    if (func_0016f6f8(id)) {
        cd = W1634_GetCharaData(id);
        id = (u32)W1634_AREA_Alloc(0x9c0);
        func_00197fe0((void*)id, cd, 6, pos, rot);
    } else if (func_0016f770(id)) {
        id = 0;
    } else if (func_0016f7a0(id)) {
        id = 0;
    } else if (id == 566) {
        cd = W1634_GetCharaData(W1634_SORA_GetEntryId(0));
        id = cd->level;
        if (id == 0) {
            id = D_0032f054;
            cd = W1634_GetCharaData(W1634_SORA_GetEntryId(id));
        }
        id = (u32)func_00179fd0(cd, id, pos, rot);
    } else {
        cd = W1634_GetCharaData(id);
        id = 0;
        if (W1634_AREADATA_CanAddCost(cd->cost)) {
            id = (u32)W1634Create(cd, pos, rot);
        }
    }
    return (void*)id;
}
}
