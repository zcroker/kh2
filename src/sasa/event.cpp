#include "event.hpp"

namespace sa {

extern u32 D_0032bae0 asm("D_0032bae0");
extern u8 D_00360000 asm("D_00360000");
extern "C" u32 func_0014abb8(...);  // get_data_359840
extern "C" u32 func_0014abc8(...);  // get_data_359950
extern "C" void func_0014aa58(...);

extern "C" u32 func_00197920(...) asm("_ZN2YS5EVENT6IsExecEv");
extern "C" u32 func_002ba620(...);

// 0x002283b0: definition moved into src/anon/unit_00224780.cpp

// 0x002283c8: definition moved into src/anon/unit_00224780.cpp

// 0x00228378: definition moved into src/anon/unit_00224780.cpp

void EVENT::wide_on() {
    u32 v0 = func_0014abb8();  // get_data_359840
    func_0014aa58(v0, 1, 0);
    v0 = func_0014abc8();  // get_data_359950
    func_0014aa58(v0, 1, 0);
    *(u8*)((u8*)&D_00360000 - 7336u) = 1;
}

// 0x00226ed0: definition moved into src/anon/unit_00224780.cpp

void EVENT::setActorParam(YS::OBJ* obj) {
    u32 v0 = *(u32*)((u32)this + 264);
    u32 v1 = *(u32*)((u32)this + 1896);
    v0 |= 0x40000003u;
    v1 |= 0x6010u;
    *(u32*)((u32)this + 264) = v0;
    *(u32*)((u32)this + 1896) = v1;
    (void)obj;
}

}  // namespace sa
