#include "layfile.hpp"
#include "file_address_layout.hpp"

namespace Tz {
extern "C" u32 func_00292630();
extern "C" void func_002a1c68();
extern u8* D_0035f5d4 asm("D_0035f5d4");
extern "C" u32 func_00293de8(u32);
extern "C" void func_00293bd0(u32, u32, u32);
extern "C" void func_002925c0();
extern u8 D_0035f5e1 asm("D_0035f5e1");
// 0x002a1cd8: definition moved into src/anon/unit_002a0908.cpp

s32 LayFile::getFileAddress() const {
    return reinterpret_cast<const FileAddressLayout*>(this)->fileAddress;
}
}  // namespace Tz
