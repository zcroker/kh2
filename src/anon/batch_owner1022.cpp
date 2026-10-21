#include "../common/types.h"
// 00162a58 / 00162a70: two identical stubs that tail-call func_00162a88 (layout row split 2026-10-22).
extern "C" {
void func_00162a88(u8* p, u32 b);
void func_00162a58(u8* p, u32 b) { func_00162a88(p, b); }
void func_00162a70(u8* p, u32 b) { func_00162a88(p, b); }
}
