// Ti::MiniGame constructor pair: 0x2ce958 (C2, called by every minigame's constructor) and
// 0x2ce9c0 (C1, same bytes). First functions of the minigame base file (minigame_base.cpp);
// kept in their own unit because they need -fno-strict-aliasing and the rest of that file does not.
#include "../common/types.h"

struct E16;
struct MG;
struct MGVt { void* f0; void (*dtor)(MG*); };
struct MG {
    MGVt* vt; u8 drawn; u8 pad5[75];
    const s32 kind; const s32 arg;   // const members: their stores stay behind the register saves
    u8 active; u8 pad89[3]; u32 f5c; u32 f60;
    MG(s32 kind, s32 arg, s32 heap);
};

extern "C" {
void func_002cf320(s32);
void func_002e7500(void);
}
void func_002cedd0(s32 n, E16* e);

extern u8 D_00361f70[];
extern u8 D_00361f40[];
extern MG* D_00361f60;

MG::MG(s32 kind_, s32 arg_, s32 heap) : kind(kind_), arg(arg_) {
    vt = (MGVt*)D_00361f70;
    drawn = 0;
    f5c = 0;
    f60 = 0;
    D_00361f60 = this;
    active = 0;
    func_002cedd0(2, (E16*)D_00361f40);
    func_002cf320(heap);
    func_002e7500();
}
