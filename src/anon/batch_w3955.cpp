#include "../common/types.h"
extern "C" {
void func_001081c8(void*);
void func_00108990(void*);
extern u8 D_003a8cd0[];
extern u8 D_003a8db0[];
extern u8 D_00340ed8[];
extern u8 D_00325c00[], D_003273a0[], D_00327400[], D_00329790[];
extern u8 D_00329800[], D_00329b40[], D_00329b80[], D_0032a720[];
extern u32 D_003a8e90, D_003a8e94, D_003a8e98, D_003a8e9c;
struct TblE10aef0 { void* p; u32 n; };
struct Tbl10aef0 { u64 z; TblE10aef0 e[4]; };
extern Tbl10aef0 D_003a8ea0;
extern u32 D_00341690, D_00341694;
extern u32 D_003a8ec8, D_003a8ecc;
extern u64 D_003a8ed0[46];
#define GSXYZ_aef0(x,y,z) ((u64)(x) | ((u64)(y) << 16) | ((u64)(z) << 32))
#define GSXYOFS_aef0(x,y) ((u64)(x) | ((u64)(y) << 32))
#define GSSCIS_aef0(x0,x1,y0,y1) ((u64)(x0) | ((u64)(x1) << 16) | ((u64)(y0) << 32) | ((u64)(y1) << 48))
#define GSFRAME_aef0(a,b,c,d) ((u64)(a) | ((u64)(b) << 16) | ((u64)(c) << 24) | ((u64)(d) << 32))
#define GSCLAMP_aef0(a,b,c,d,e,f) ((u64)(a) | ((u64)(b) << 2) | ((u64)(c) << 4) | ((u64)(d) << 14) | ((u64)(e) << 24) | ((u64)(f) << 34))
#define GSTEX0_aef0(tbp,tbw,psm,tw,th,tcc,tfx) ((u64)(tbp) | ((u64)(tbw) << 14) | ((u64)(psm) << 20) | ((u64)(tw) << 26) | ((u64)(th) << 30) | ((u64)(tcc) << 34) | ((u64)(tfx) << 35))
// g++ static init (priority 0xffff) of a TU: table sizes, GS register packet.
void func_0010aef0(int a0, int a1) asm("_Z13func_0010aef0ii");
void func_0010aef0(int a0, int a1);  // 0010aef0: moved to src/anon/unit_0010aef0.cpp
} // extern "C"
