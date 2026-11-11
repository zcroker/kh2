#include "worldwork.hpp"

// YS::WORLDWORK (0x1ba138-0x1ba168): 28 bytes of per-world work data.

extern "C" void func_002fd310(void*, u32);  // memclr
static u8 s_work[0x1c] __attribute__((aligned(16)));

namespace YS {

void WORLDWORK::Clear() { func_002fd310(s_work, sizeof(s_work)); }

void* WORLDWORK::Get() { return s_work; }

}  // namespace YS
