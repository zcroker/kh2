#include "../../common/types.h"

// dk::Map, last part (0x15f268-0x15f7f0): the map's effect set (a ryj::PAX built by the static
// init), effect show/hide/colour over the visible groups. map.cpp has the first part.

namespace ryj {
    class PAX {
    public:
        PAX();
        ~PAX();
        u32 w[7];
    };
}  // namespace ryj

ryj::PAX D_0034c6f0 asm("D_0034c6f0");
u8 D_0034c70c asm("D_0034c70c");  // the PAX holds the map's effects
u8 D_0034c70d asm("D_0034c70d");
u64 D_0034c710 asm("D_0034c710");  // visible groups, one bit each

extern "C" {
void func_001de228(void*, s32, s32, s32, s32, s32);
void func_0015c4a0(u32);
void func_001de3d8(void*, u32);
void func_0015c450(u32);
u8* func_001de4b0(void*, s32, u8*);
s32 func_001dc9e0(u8*) asm("_ZN3ryj6EFFECT9is_activeEv");
void func_001dc698(u8*, s32);
void func_001431c0(void);
void func_001431d0(void);
void func_00161228(void);
void func_00161238(void);
void func_00143248(void);
void func_00143228(void);
void func_00160e50(s32);
void func_00160de0(s32) asm("_Z16wtarget_00160de0jjjj");
void func_001dcc48(u8*) asm("_ZN3ryj6EFFECT13reset_no_drawEv");
void func_001dcc30(u8*) asm("_ZN3ryj6EFFECT11set_no_drawEv");
u32 func_001431e8(u32);
u32 func_00143208(u32);

u8 func_0015f268(void) { return D_0034c70d; }
void func_0015f278(void) { D_0034c70d = 1; }
void func_0015f288(void) { D_0034c70d = 0; }

void func_0015f298(void)
{
    u8* o = 0;
    func_001431c0();
    func_00161228();
    if (D_0034c70c != 1) return;
    for (s32 i = 0; i < 64; i++) {
        while ((o = func_001de4b0(&D_0034c6f0, i, o))) {
            if (func_001dc9e0(o)) func_001dc698(o, 0);
        }
    }
}

void func_0015f340(void)
{
    u8* o = 0;
    func_001431d0();
    func_00161238();
    if (D_0034c70c != 1) return;
    for (s32 i = 0; i < 64; i++) {
        while ((o = func_001de4b0(&D_0034c6f0, i, o))) {
            if (func_001dc9e0(o)) func_001dc698(o, 1);
        }
    }
}

void func_0015f3e8(void)
{
    func_00143248();
    for (s32 i = 0; i < 64; i++) {
        u64 bit = (u64)1 << i;
        if (!(D_0034c710 & bit)) continue;
        func_0015c450(i);
        if (D_0034c70c == 1) func_001de228(&D_0034c6f0, i, 1, 2, 0, 0);
    }
}

void func_0015f4a0(void)
{
    func_00143228();
    for (s32 i = 0; i < 64; i++) {
        u64 bit = (u64)1 << i;
        if (!(D_0034c710 & bit)) continue;
        func_0015c4a0(i);
        if (D_0034c70c == 1) func_001de3d8(&D_0034c6f0, i);
    }
}

void func_0015f548(void)
{
    s32 i;
    u64 one = 1;
    u8* p;
    func_00143248();
    for (i = 0; i < 64; i++) {
        if ((D_0034c710 & (one << i)) != 0) func_00160e50(i);
    }
    p = 0;
    if (D_0034c70c == 1) {
        s32 j;
        for (j = 0; j < 64; j++) {
            while ((p = func_001de4b0(&D_0034c6f0, j, p)) != 0) {
                if (func_001dc9e0(p)) func_001dcc48(p);
            }
        }
    }
}

void func_0015f618(void)
{
    s32 i;
    u64 one = 1;
    u8* p;
    func_00143228();
    for (i = 0; i < 64; i++) {
        if ((D_0034c710 & (one << i)) != 0) func_00160de0(i);
    }
    p = 0;
    if (D_0034c70c == 1) {
        s32 j;
        for (j = 0; j < 64; j++) {
            while ((p = func_001de4b0(&D_0034c6f0, j, p)) != 0) {
                if (func_001dc9e0(p)) func_001dcc30(p);
            }
        }
    }
}

u32 func_0015f6e8(u32 a) { return func_001431e8(a); }
u32 func_0015f700(u32 a) { return func_00143208(a); }

u8 func_0015f718(u32 g) { return (D_0034c710 >> g) & 1; }
}
