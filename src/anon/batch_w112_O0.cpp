#include "../common/types.h"

// ---- 002b8ac0
namespace n002b8ac0 {
struct StrmSt { s32 mode; s32 size; };
struct Strm { u8 pad[0x48000]; StrmSt st; };
extern "C" {
s32 func_002b85e4(u8*);
}
extern "C" {
// Classifies the stream buffer state: 0 idle, 1 small, 2 in range, 3 behind.
s32 func_002b8ac0(Strm* p);  // 0x002b8ac0: definition moved into src/anon/unit_002b8274.cpp
}
}
