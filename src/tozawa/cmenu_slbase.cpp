#include "cmenu_slbase.hpp"

namespace Tz {

extern u32 D_0035f2e8 asm("D_0035f2e8");
extern u32 D_0035f2f0 asm("D_0035f2f0");
extern u32 D_0035f2f4 asm("D_0035f2f4");
extern u32 D_0035f2f8 asm("D_0035f2f8");
extern u32 D_0035f300 asm("D_0035f300");
extern u32 D_0035f304 asm("D_0035f304");
extern u32 D_0035f30c asm("D_0035f30c");
extern u32 D_0035f31c asm("D_0035f31c");
extern u32 D_0035f334 asm("D_0035f334");
extern u32 D_0035f33c asm("D_0035f33c");
extern u32 D_0035f340 asm("D_0035f340");
extern u16 D_0035f32a asm("D_0035f32a");
extern u32 D_0035f32c asm("D_0035f32c");
extern u32 D_0035f32e asm("D_0035f32e");
extern u8 D_0035f314 asm("D_0035f314");
extern u32 D_0035f64c asm("D_0035f64c");
extern u32 D_0035f650 asm("D_0035f650");
extern u8* D_0035f654 asm("D_0035f654");
extern u8* D_0035f658 asm("D_0035f658");
extern u32 D_0035f678 asm("D_0035f678");
extern u8* D_0035f6cc asm("D_0035f6cc");
extern u8 D_0035f6d0 asm("D_0035f6d0");

// 0x00287da0: definition moved into src/anon/unit_00286d28.cpp

extern "C" u32 func_00287bd0(...);
extern "C" u32 func_0023f948(...);
extern "C" u32 func_0023f908(...);
extern "C" u32 func_00103570(...);
extern "C" void func_00236a58(...);
extern "C" void func_0023c100(...);

// 0x00287c30: definition moved into src/anon/unit_00286d28.cpp

// 0x00287b08: definition moved into src/anon/unit_00286d28.cpp

// 0x00287b18: definition moved into src/anon/unit_00286d28.cpp

// 0x00287bc0: definition moved into src/anon/unit_00286d28.cpp

// 0x00287c00: definition moved into src/anon/unit_00286d28.cpp

// 0x00287c10: definition moved into src/anon/unit_00286d28.cpp

// 0x00287c90: definition moved into src/anon/unit_00286d28.cpp

// 0x00287d20: definition moved into src/anon/unit_00286d28.cpp

// 0x00287d30: definition moved into src/anon/unit_00286d28.cpp

// 0x00287dc0: definition moved into src/anon/unit_00286d28.cpp

// 0x00288658: definition moved into src/anon/unit_002880b8.cpp

extern u32 D_0035f2fc asm("D_0035f2fc");
extern u64* D_0035f324 asm("D_0035f324");
extern u32 D_0035f338 asm("D_0035f338");
extern u32 D_0035f344 asm("D_0035f344");
extern "C" u32 func_00139d78(u32);
extern "C" void func_00138c10(u32, u32);
extern "C" s32 func_00103398(u32);
extern "C" u32 func_00258cd8(...);
extern "C" u32 func_00258c18(...);
extern "C" u32 func_00258c48(...);
extern "C" void func_00258bc0(u32);
extern u8 D_00360000 asm("D_00360000");
extern "C" u32 func_0028acc8(u32);
extern "C" u32 func_0028acb8(...);
extern "C" void func_0028aa40(u32);
extern "C" u32 func_0028ae28(u32, u32);
extern "C" void func_0028dac8(u8*, s32);
extern "C" void func_0028da70(void*, s32);
extern "C" void func_0028ab20(u32);
extern "C" void func_0028bd60(u32);
extern "C" u32 func_0028be58(u32);
extern "C" void func_0028bdb8(u32);
extern "C" void func_002b5a20();
extern "C" u32 func_002b5a50();
extern "C" u32 func_002b5768();
extern "C" void* func_001063c0(u32, u32);
extern "C" void func_0028b788(void*);
extern "C" u32 func_002537c8(u32);
extern "C" void func_0023fa08(void*, u32);
extern "C" void func_0028b8e0(void*, u32);
extern void* D_0035f674 asm("D_0035f674");
extern u8 D_0035f3a8 asm("D_0035f3a8");

// 0x00287c50: definition moved into src/anon/unit_00286d28.cpp

// 0x00288040: definition moved into src/anon/unit_00286d28.cpp

// 0x00288370: definition moved into src/anon/unit_002880b8.cpp

// 0x00288750: definition moved into src/anon/unit_002880b8.cpp

// 0x002887c8: definition moved into src/anon/unit_002880b8.cpp

// 0x00288820: definition moved into src/anon/unit_002880b8.cpp

// 0x002888c8: definition moved into src/anon/unit_002880b8.cpp

void CmSLBase::FadeOutWarningWin() {
    u8* t5 = D_0035f6cc;
    u8* t6 = *(u8**)(t5 + 20);
    func_0028dac8(D_0035f654, (s32)*(s16*)(t6 + 2));

    if (func_0028acc8(D_0035f650) != 0) {
        if (func_0028acb8(D_0035f650) == 0) {
            func_0028aa40(D_0035f650);
        }
    }

    D_0035f6d0 = 0;
}

u32 CmSLBase::isLoopWarningWin() {
    func_00139d78((void*)D_0035f654);

    u8* t3 = D_0035f654;
    u8* t5 = D_0035f6cc;
    u32 t6 = *(u32*)(t3 + 388);
    u8* t4 = *(u8**)(t5 + 20);
    s32 t7 = (s32)*(s16*)(t4 + 4);

    u32 s0 = ((t6 ^ (u32)t7) < 1u);
    if (func_0028acc8(D_0035f650) != 0) {
        if (s0 != 0) {
            s0 = func_0028ae28(D_0035f650, 0);
        }
    }

    return s0;
}

u32 CmSLBase::isLoopList() {
    u8* t7 = D_0035f658;
    if (t7 != 0) {
        func_00139d78((void*)t7);
        t7 = D_0035f658;
    }

    u32 t4 = *(u32*)(t7 + 388);
    u8* t6 = D_0035f6cc;
    u8* t5 = *(u8**)(t6 + 24);
    s32 t7i = (s32)*(s16*)(t5 + 4);

    u32 v0 = ((t4 ^ (u32)t7i) < 1u);
    if (v0 != 0) {
        v0 = func_0028ae28(D_0035f64c, 0);
    }
    return v0;
}

void CmSLBase::LoopList() {
    u8* t7 = D_0035f658;
    if (t7 != 0) {
        func_00139d78((void*)t7);
    }

    u8* t6 = D_0035f6cc;
    u8* t5 = *(u8**)(t6 + 24);
    func_00138c10((void*)D_0035f658, (s32)*(s16*)(t5 + 4));

    func_0028ab20(D_0035f64c);
    func_0028bd60(D_0035f678);
}

void CmSLBase::FadeOutList() {
    u8* t5 = D_0035f6cc;
    u8* t6 = *(u8**)(t5 + 24);
    func_0028dac8(D_0035f658, (s32)*(s16*)(t6 + 2));

    if (func_0028acc8(D_0035f64c) != 0) {
        if (func_0028acb8(D_0035f64c) == 0) {
            func_0028aa40(D_0035f64c);
        }
    }

    if (func_0028be58(D_0035f678) != 0) {
        func_0028bdb8(D_0035f678);
    }
}

void CmSLBase::isExistList() {
    u32 v0 = 0;

    if (D_0035f658 != 0) {
        v0 = func_00139d78(D_0035f658);
    }
    if (v0 != 0) {
        return;
    }

    if (D_0035f64c != 0) {
        v0 = func_0028acc8(D_0035f64c);
    }
    if (v0 != 0) {
        return;
    }

    v0 = func_0028be58(D_0035f678);
    if (v0 != 0) {
        return;
    }

    func_002b5a20();
    v0 = 0;
}

void CmSLBase::LeaveListItem() {
    u32 r2 = 0u;
    r2 = func_002b5a50();
    (void)r2;
    func_002b5768();
}

void CmSLBase::SetLeadData() {
    u32 v0 = func_00103570();
    void* s0 = func_001063c0(36, v0);
    func_0028b788(s0);
    D_0035f674 = s0;

    u32 s0i = func_002537c8(1);
    func_0023fa08(&D_0035f3a8, s0i);
    func_0028b8e0(D_0035f674, s0i);
}

}  // namespace Tz
