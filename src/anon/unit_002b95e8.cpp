// Linked unit (see linked_units.tsv); one namespace per old matched source.
#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>

// 002b95e8 (was src/anon/batch_w88_O0.cpp)
namespace n002b95e8 {
s32 func_002b9404(u32, u32, u32*, u16*) asm("func_002b9404");
s32 func_002b6708(u32, u32, s32, u32, u32, u32, u32, u32) asm("func_002b6708");
/*TARGET 002b95e8*/
// Look up an entry; on success forward it to func_002b6708 (flag bit 0 forces 16383).
s32 func_002b95e8(u32 a, u32 b, u32 c, u32 d) asm("func_002b95e8");
// Look up an entry; on success forward it to func_002b6708 (flag bit 0 forces 16383).
s32 func_002b95e8(u32 a, u32 b, u32 c, u32 d) {
    s32 r;
    u32 x;
    u16 fl;
    r = func_002b9404(a, b, &x, &fl);
    if (r < 0) return -1;
    if (fl & 1) c = 16383;
    return func_002b6708(7, 25, r, x, c, d, 1, 1);
}
}  // namespace n002b95e8

// 002b96a4 (was src/anon/batch_w64_O0.cpp)
namespace n002b96a4 {
s32 func_002b9404(u32, u32, u32*, u32*) asm("func_002b9404");
s32 func_002b6708(s32, s32, s32) asm("func_002b6708");
/*TARGET 002b96a4*/
s32 func_002b96a4(u32 a, u32 b) asm("func_002b96a4");
s32 func_002b96a4(u32 a, u32 b) {
    s32 r;
    u32 x;
    u32 y;
    r = func_002b9404(a, b, &x, &y);
    if (r < 0) return -1;
    return func_002b6708(2, 26, r);
}
}  // namespace n002b96a4

// 002b9728 (was src/anon/batch_wcx_O0.cpp)
namespace n002b9728 {
s32 func_002b9404(u32, u32, u32*, u16*) asm("func_002b9404");
s32 func_002b6708(s32, s32, s32, s32, u32) asm("func_002b6708");
/*TARGET 002b9728*/
s32 func_002b9728(u32 a, u32 b, s32 c, u32 d) asm("func_002b9728");
s32 func_002b9728(u32 a, u32 b, s32 c, u32 d)
{
    s32 r;
    u32 x;
    u16 f;
    r = func_002b9404(a, b, &x, &f);
    if (r < 0) return -1;
    if (f & 1) c = 16383;
    return func_002b6708(4, 27, r, c, d);
}
}  // namespace n002b9728

// 002b97d8 (was src/anon/batch_w50_O0.cpp)
namespace n002b97d8 {
s32 func_002b9404(s32, s32, s32*, s32*) asm("func_002b9404");
s32 func_002b6708(s32, s32, s32, s32, s32) asm("func_002b6708");
/*TARGET 002b97d8*/
s32 func_002b97d8(s32 a, s32 b, s32 c, s32 d) asm("func_002b97d8");
s32 func_002b97d8(s32 a, s32 b, s32 c, s32 d) {
    s32 r;
    s32 x, y;
    r = func_002b9404(a, b, &x, &y);
    if (r < 0) return -1;
    return func_002b6708(4, 28, r, c, d);
}
}  // namespace n002b97d8

// 002b986c (was src/anon/batch_w83_O0.cpp)
namespace n002b986c {
struct Ent64 { s32 hdr[2]; u8 pad[56]; };
extern Ent64 D_01e22080[512] asm("D_01e22080");
s32 func_002b9404(s32, s32, s32*, s32*) asm("func_002b9404");
void func_003058a0(s32) asm("func_003058a0");
/*TARGET 002b986c*/
// Count type-25 entries whose id matches the looked-up handle.
s32 func_002b986c(s32 a, s32 b) asm("func_002b986c");
// Count type-25 entries whose id matches the looked-up handle.
s32 func_002b986c(s32 a, s32 b) {
    s32 i;
    s32 cnt = 0;
    s32 r;
    s32 x;
    s32 y;
    r = func_002b9404(a, b, &x, &y);
    if (r < 0) return 0;
    func_003058a0(0);
    for (i = 0; i < 512; i++) {
        if (D_01e22080[i].hdr[0] == 25 && D_01e22080[i].hdr[1] == r) cnt++;
    }
    return cnt;
}
}  // namespace n002b986c

// 002b9968 (was src/anon/batch_w205_O0.cpp)
namespace n002b9968 {
void* func_002b6708(s32, s32) asm("func_002b6708");
/*TARGET 002b9968*/
void* func_002b9968() asm("func_002b9968");
void* func_002b9968() { return func_002b6708(1, 24); }
}  // namespace n002b9968

// 002b99a0 (was src/anon/batch_w200_O0.cpp)
namespace n002b99a0 {
extern u32 D_01e2a3c0 asm("D_01e2a3c0");
u32 ctarget_002b99a0() asm("_Z16ctarget_002b99a0jjjj");
/*TARGET 002b99a0*/
u32 ctarget_002b99a0() asm("_Z16ctarget_002b99a0jjjj");
u32 ctarget_002b99a0() { return D_01e2a3c0; }
}  // namespace n002b99a0

// 002b99c8 (was src/anon/batch_w205_O0.cpp)
namespace n002b99c8 {
void* func_002b6708(s32, s32) asm("func_002b6708");
/*TARGET 002b99c8*/
void* func_002b99c8() asm("func_002b99c8");
void* func_002b99c8() { return func_002b6708(1, 41); }
}  // namespace n002b99c8

// 002b9a00 (was src/anon/batch_w205_O0.cpp)
namespace n002b9a00 {
void* func_002b6708(s32, s32) asm("func_002b6708");
/*TARGET 002b9a00*/
void* func_002b9a00() asm("func_002b9a00");
void* func_002b9a00() { return func_002b6708(1, 42); }
}  // namespace n002b9a00

// 002b9a38 (was src/anon/batch_w207_O0.cpp)
namespace n002b9a38 {
u32 func_002b6708(u32, u32, u32) asm("func_002b6708");
/*TARGET 002b9a38*/
u32 func_002b9a38(u32 a) asm("func_002b9a38");
u32 func_002b9a38(u32 a) { return func_002b6708(2, 53, a); }
}  // namespace n002b9a38

// 002b9a78 (was src/anon/batch_w207_O0.cpp)
namespace n002b9a78 {
u32 func_002b6708(u32, u32, u32) asm("func_002b6708");
/*TARGET 002b9a78*/
u32 func_002b9a78(u32 a) asm("func_002b9a78");
u32 func_002b9a78(u32 a) { return func_002b6708(2, 54, a); }
}  // namespace n002b9a78

