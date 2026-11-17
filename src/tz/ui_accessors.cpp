#include "ui_accessors.hpp"
#include "../tozawa/item_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "../tozawa/multi_seq.hpp"
#include "../tozawa/party_info.hpp"

namespace Tz {
extern "C" u32 func_00139d78(...);

// 0x002595e0: definition moved into src/anon/unit_002588e8.cpp
// 0x00281100: definition moved into src/anon/unit_0027f2b0.cpp
// 0x00281198: definition moved into src/anon/unit_0027f2b0.cpp
// 0x00281140: definition moved into src/anon/unit_0027f2b0.cpp
// 0x00281180: definition moved into src/anon/unit_0027f2b0.cpp
extern "C" u32 func_001a8bd0(...);
extern "C" u32 func_001a8bf8(...);  // get_bits5_at
extern u32 D_00374190 asm("D_00374190");
// 0x00281238: definition moved into src/anon/unit_0027f2b0.cpp
extern "C" u32 func_00281180(...);
extern "C" u32 func_00281198(...);
extern "C" u32 func_00281128(...);  // get_entry20_field16
extern "C" u32 func_001a9758(...);
// 0x00281538: definition moved into src/anon/unit_0027f2b0.cpp
extern "C" u32 func_001058e8(...);
// 0x002815b8: definition moved into src/anon/unit_0027f2b0.cpp
// 0x00281480: definition moved into src/anon/unit_0027f2b0.cpp
extern "C" u32 func_00281340(...);
// 0x00281388: definition moved into src/anon/unit_0027f2b0.cpp
// 0x002813b8: definition moved into src/anon/unit_0027f2b0.cpp
// 0x00281420: definition moved into src/anon/unit_0027f2b0.cpp
// 0x00281f18: definition moved into src/anon/unit_00281cf0.cpp
// 0x00281f20: definition moved into src/anon/unit_00281cf0.cpp
// 0x00281f30: definition moved into src/anon/unit_00281cf0.cpp
// 0x00281f40: definition moved into src/anon/unit_00281cf0.cpp
// 0x00282d68: definition moved into src/anon/unit_00282c68.cpp
// 0028ebf0: moved to src/anon/unit_0028c878.cpp
u32 HelpGra::isExist() {
    u32 (*fp_call0_00139d78)() = (u32(*)())func_00139d78;
    return fp_call0_00139d78();
}
}  // namespace Tz
