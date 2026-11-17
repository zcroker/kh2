#include "../common/types.h"
extern "C" {

/* 0011f1a8: unpack high nibbles in place (u64 at a time, then bytes) */
struct O5_0011f1a8;
struct O5vt_0011f1a8 { u8 pad[0x30]; s32 (*fn)(O5_0011f1a8*); };
struct O5_0011f1a8 { O5vt_0011f1a8* vt; };
void func_0011f1a8(O5_0011f1a8* o, s8* p);  // 0x0011f1a8: definition moved into src/anon/unit_0011c128.cpp

}
