#include "../common/types.h"

// GS packet helpers (0x108068-0x108438), incl. the never-written 0x1082f8 (copy of the GIF tag set-up 0x108398). Left outside: the two never-written 7-register packet set-ups 0x108438/0x1084f0.
// Each function keeps the declarations of the source it was matched in (namespace nADDR); every symbol
// is bound by asm label.
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"

// 00108068 (from src/anon/tiny_wrappers_more.cpp)
namespace n00108068 {
u32 func_001124f8(u32, u32, u32, u32) asm("func_001124f8");
// 00105ec8: _GLOBAL__I_ stub, now made by gcc in src/common/shop.cpp

// 00106490: moved to src/anon/unit_00106490.cpp

u32 func_00108068(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00108068");
u32 func_00108068(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001124f8(a0, a1, a2, a3);
}
}  // namespace n00108068

// 00108080 (from src/anon/batch_owner1021b.cpp)
namespace n00108080 {
void func_00112568(void) asm("func_00112568");
void func_00108080(void) asm("func_00108080");
void func_00108080(void) { func_00112568(); }
}  // namespace n00108080

// 00108098 (from src/anon/batch_w1897_nsa.cpp)
namespace n00108098 {
typedef unsigned int u128 __attribute__((mode(TI)));
struct W1897GifTag {
    u64 NLOOP:15; u64 EOP:1; u64 pad16:30; u64 PRE:1; u64 PRIM:11; u64 FLG:2; u64 NREG:4;
    u64 REGS0:4; u64 REGS1:4; u64 REGS2:4; u64 REGS3:4; u64 REGS4:4; u64 REGS5:4; u64 REGS6:4; u64 REGS7:4;
    u64 REGS8:4; u64 REGS9:4; u64 REGS10:4; u64 REGS11:4; u64 REGS12:4; u64 REGS13:4; u64 REGS14:4; u64 REGS15:4;
} __attribute__((aligned(16)));
struct W1897AD { u64 data; u64 addr; };
struct W1897Pkt { W1897GifTag tag; W1897AD ad[13]; };
void func_00108098(W1897Pkt* p) asm("func_00108098");
void func_00108098(W1897Pkt* p) {
    *(u128*)&p->tag = 0;
    p->tag.NLOOP = 13;
    p->tag.EOP = 1;
    p->tag.NREG = 1;
    p->tag.REGS0 = 0xE;
    p->ad[0].addr = 0x3f;
    p->ad[1].addr = 0x4c;
    p->ad[2].addr = 0x4e;
    p->ad[3].addr = 0x34;
    p->ad[4].addr = 0x36;
    p->ad[5].addr = 0x16;
    p->ad[6].addr = 0x14;
    p->ad[7].addr = 6;
    p->ad[8].addr = 0x47;
    p->ad[9].addr = 0x42;
    p->ad[10].addr = 8;
    p->ad[11].addr = 0x3d;
    p->ad[12].addr = 1;
    p->ad[0].data = 0;
    p->ad[1].data = 0x800d8;
    p->ad[2].data = 0x31000070;
    p->ad[3].data = 0;
    p->ad[4].data = 0;
    p->ad[5].data = 0x2000000001300000ULL;
    p->ad[6].data = 0x60;
    p->ad[7].data = 0x2000000664023500ULL;
    p->ad[8].data = 0x5000d;
    p->ad[9].data = 0x44;
    p->ad[10].data = 5;
    p->ad[11].data = 0x808080;
    p->ad[12].data = 0x3f80000080808080ULL;
}
}  // namespace n00108098

// 001081c8 (from src/anon/batch_w1833_nsa.cpp)
namespace n001081c8 {
typedef unsigned int u128 __attribute__((mode(TI)));
struct W1833GifTag {
    u64 NLOOP:15; u64 EOP:1; u64 pad16:30; u64 PRE:1; u64 PRIM:11; u64 FLG:2; u64 NREG:4;
    u64 REGS0:4; u64 REGS1:4; u64 REGS2:4; u64 REGS3:4; u64 REGS4:4; u64 REGS5:4; u64 REGS6:4; u64 REGS7:4;
    u64 REGS8:4; u64 REGS9:4; u64 REGS10:4; u64 REGS11:4; u64 REGS12:4; u64 REGS13:4; u64 REGS14:4; u64 REGS15:4;
} __attribute__((aligned(16)));
struct W1833AD { u64 data; u64 addr; };
struct W1833Pkt { W1833GifTag tag; W1833AD ad[13]; };
void func_001081c8(W1833Pkt* p) asm("func_001081c8");
void func_001081c8(W1833Pkt* p) {
    *(u128*)&p->tag = 0;
    p->tag.NLOOP = 13;
    p->tag.EOP = 1;
    p->tag.NREG = 1;
    p->tag.REGS0 = 0xE;
    p->ad[0].addr = 0x3f;
    p->ad[1].addr = 0x4c;
    p->ad[2].addr = 0x4e;
    p->ad[3].addr = 0x34;
    p->ad[4].addr = 0x36;
    p->ad[5].addr = 0x16;
    p->ad[6].addr = 0x14;
    p->ad[7].addr = 6;
    p->ad[8].addr = 0x47;
    p->ad[9].addr = 0x42;
    p->ad[10].addr = 8;
    p->ad[11].addr = 0x3d;
    p->ad[12].addr = 1;
    p->ad[0].data = 0;
    p->ad[1].data = 0x800d8;
    p->ad[2].data = 0x31000070;
    p->ad[3].data = 0;
    p->ad[4].data = 0;
    p->ad[5].data = 0x2000000001300000ULL;
    p->ad[6].data = 0x60;
    p->ad[7].data = 0x2000000664023500ULL;
    p->ad[8].data = 0x5000d;
    p->ad[9].data = 0x44;
    p->ad[10].data = 5;
    p->ad[11].data = 0x808080;
    p->ad[12].data = 0x3f80000080808080ULL;
}
}  // namespace n001081c8

namespace n001082f8 {
typedef unsigned int u128 __attribute__((mode(TI)));
// 00103ec0: static init, moved to src/common/unit_001031b0.cpp

// GS GIFtag (two 64-bit words, bitfields).
struct GifTag {
    u64 nloop : 15; u64 eop : 1; u64 pad : 30; u64 pre : 1; u64 prim : 11; u64 flg : 2; u64 nreg : 4;
    u64 regs0 : 4; u64 regs : 60;
};
struct Pkt {
    GifTag tag;
    u64 d0, a0, d1, a1, d2, a2, d3, a3;
    GifTag tag2;
};
// 001082f8: copy of 0x108398 (never written before). Clears a 3-quadword GS packet and fills in its GIFtags and A+D register ids.
void func_001082f8(Pkt* p) asm("func_001082f8");
void func_001082f8(Pkt* p) {  // clear_quads_set_flags
    p->d3 = 0;
    *(u128*)&p->tag = 0;
    *(u128*)&p->tag2 = 0;
    p->tag.nloop = 4;
    p->tag.nreg = 1;
    p->tag.regs0 = 0xe;
    p->a0 = 80;
    p->a1 = 81;
    p->a2 = 82;
    p->a3 = 83;
    p->tag2.eop = 1;
    p->tag2.flg = 2;
}
}  // namespace n001082f8

// 00108398 (from src/anon/batch_w50.cpp)
namespace n00108398 {
typedef unsigned int u128 __attribute__((mode(TI)));
// 00103ec0: static init, moved to src/common/unit_001031b0.cpp

// GS GIFtag (two 64-bit words, bitfields).
struct GifTag {
    u64 nloop : 15; u64 eop : 1; u64 pad : 30; u64 pre : 1; u64 prim : 11; u64 flg : 2; u64 nreg : 4;
    u64 regs0 : 4; u64 regs : 60;
};
struct Pkt {
    GifTag tag;
    u64 d0, a0, d1, a1, d2, a2, d3, a3;
    GifTag tag2;
};
// Clears a 3-quadword GS packet and fills in its GIFtags and A+D register ids.
void func_00108398(Pkt* p) asm("func_00108398");
void func_00108398(Pkt* p) {  // clear_quads_set_flags
    p->d3 = 0;
    *(u128*)&p->tag = 0;
    *(u128*)&p->tag2 = 0;
    p->tag.nloop = 4;
    p->tag.nreg = 1;
    p->tag.regs0 = 0xe;
    p->a0 = 80;
    p->a1 = 81;
    p->a2 = 82;
    p->a3 = 83;
    p->tag2.eop = 1;
    p->tag2.flg = 2;
}
}  // namespace n00108398


// 00108438, 001084f0: 7-register A+D GS packets (never written before; same shape as 0x108098).
namespace n00108438 {
typedef unsigned int u128 __attribute__((mode(TI)));
struct GifTag7 {
    u64 NLOOP:15; u64 EOP:1; u64 pad16:30; u64 PRE:1; u64 PRIM:11; u64 FLG:2; u64 NREG:4;
    u64 REGS0:4; u64 REGS1:4; u64 REGS2:4; u64 REGS3:4; u64 REGS4:4; u64 REGS5:4; u64 REGS6:4; u64 REGS7:4;
    u64 REGS8:4; u64 REGS9:4; u64 REGS10:4; u64 REGS11:4; u64 REGS12:4; u64 REGS13:4; u64 REGS14:4; u64 REGS15:4;
} __attribute__((aligned(16)));
struct AD7 { u64 data; u64 addr; };
struct Pkt7 { GifTag7 tag; AD7 ad[7]; };
void func_00108438(Pkt7* p) asm("func_00108438");
void func_00108438(Pkt7* p) {
    *(u128*)&p->tag = 0;
    p->tag.NLOOP = 7;
    p->tag.EOP = 1;
    p->tag.NREG = 1;
    p->tag.REGS0 = 0xE;
    p->ad[0].addr = 0x3f;
    p->ad[1].addr = 0x34;
    p->ad[2].addr = 0x36;
    p->ad[3].addr = 0x16;
    p->ad[4].addr = 0x14;
    p->ad[5].addr = 6;
    p->ad[6].addr = 8;
    p->ad[0].data = 0;
    p->ad[1].data = 0;
    p->ad[2].data = 0;
    p->ad[3].data = 0x2000000001300000ULL;
    p->ad[4].data = 0x60;
    p->ad[5].data = 0x2000000664023500ULL;
    p->ad[6].data = 5;
}
void func_001084f0(Pkt7* p) asm("func_001084f0");
void func_001084f0(Pkt7* p) {
    *(u128*)&p->tag = 0;
    p->tag.NLOOP = 7;
    p->tag.EOP = 1;
    p->tag.NREG = 1;
    p->tag.REGS0 = 0xE;
    p->ad[0].addr = 0x3f;
    p->ad[1].addr = 0x34;
    p->ad[2].addr = 0x36;
    p->ad[3].addr = 0x16;
    p->ad[4].addr = 0x14;
    p->ad[5].addr = 6;
    p->ad[6].addr = 8;
    p->ad[0].data = 0;
    p->ad[1].data = 0;
    p->ad[2].data = 0;
    p->ad[3].data = 0x2000000001300000ULL;
    p->ad[4].data = 0x60;
    p->ad[5].data = 0x2000000664023500ULL;
    p->ad[6].data = 5;
}
}  // namespace n00108438
