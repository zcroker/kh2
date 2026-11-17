#include "obj.hpp"

namespace kn {
class FMatrix;
}

namespace YS {



u32 OBJ::GetPlayer() {
    u32 b = (0x0035u << 16);
    return (u32)(*(u32*)((u32)b + (-5816)));
}

extern "C" void func_0016c460(u32, u32);

void OBJ::get_jump_height() {
    struct {
        u32 w0;
        u32 w1;
        u32 w2;
        u32 w3;
    } sp;
    func_0016c460((u32)this, (u32)&sp);
}

u32 OBJ::get_appear_way() {
    u32 r15 = *(volatile u32*)((u32)this + 2076);
    u32 r2 = (u32)((s32)0u + (-1));
    if (r15 != 0u) {
        r2 = (u32)(*(u8*)((u32)r15 + 28));
    }
    return r2;
}

u32 OBJ::get_serial() {
    u32 r15 = *(volatile u32*)((u32)this + 2076);
    u32 r2 = 0u;
    if (r15 != 0u) {
        r2 = (u32)(*(u16*)((u32)r15 + 30));
    }
    return r2;
}

void OBJ::set_unit_arg(int idx, int value) {
    u32 r5 = (u32)(idx << 2);
    r5 = (u32)(r5 + (u32)this);
    *(u32*)((u32)r5 + 2076) = (u32)value;
}

extern "C" u32 func_001a7790(...);

// 0x0019c410: definition moved into src/anon/unit_0019ba60.cpp

u32 OBJ::get_type() {
    u32 flags = *(u32*)((u32)this + 1416);
    flags &= 0x80u;
    u32 r = 0;
    if (flags == 0u) {
        u32 p = *(u32*)((u32)this + 8);
        r = *(u8*)((u32)p + 4);
    }
    return r;
}

u32 OBJ::get_entry_id() {
    u32 p = *(u32*)((u32)this + 8);
    return *(u32*)((u32)p + 0);
}

u32 OBJ::get_part_num() {
    u32 p = *(u32*)((u32)this + 8);
    return (u32)(*(u16*)((u32)p + 76));
}

u32 OBJ::get_sub_type() {
    u32 p = *(u32*)((u32)this + 8);
    return *(u8*)((u32)p + 5);
}

u32 OBJ::get_skeleton_num() {
    u32 p = *(u32*)((u32)this + 8);
    return *(u8*)((u32)p + 7);
}

// 0x0019c400: definition moved into src/anon/unit_0019ba60.cpp

// 0x0019c4e8: definition moved into src/anon/unit_0019ba60.cpp

// 0x0019c768: definition moved into src/anon/unit_0019ba60.cpp

// 001c0cd8: moved to src/anon/unit_001c0638.cpp

// 0x0019baa8: definition moved into src/anon/unit_0019ba60.cpp


// 0x001a0798: definition moved into src/anon/unit_0019fb70.cpp

// 0x00194648: definition moved into src/anon/unit_00193be8.cpp

// 0x0019c4d0: definition moved into src/anon/unit_0019ba60.cpp

// 0x0019c898: definition moved into src/anon/unit_0019ba60.cpp

}  // namespace YS
