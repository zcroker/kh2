#include "../common/types.h"
extern "C" {
struct Area {
    u8 world;
    u8 area;
    u8 entrance;
    u8 pad3;
    u16 layout;
    u16 event;
    u16 btl;
};
struct Jumper {
    u32 f0;
    Area dest;
    u8 pad14[18];
    u32 f32;
    u8 pad36[12];
};
extern Area D_0032bae0;
extern Area D_003a7b08;
extern u8 D_003a7b00;
extern u32 D_0032bb1c;
extern u32 D_0032b968[];
extern s32 D_0034ecd0;
extern s32 D_0034ecd4;
void func_00104cc0(void);
void func_0019ef70(Jumper*);
static inline void Area_init(Area* a, u32 v)
{
    a->world = v;
    a->area = v;
    a->entrance = v;
    a->layout = v;
    a->event = v;
    a->btl = v;
}
void func_0019f070(Jumper*, s32);
void func_0014ce60(void);
void func_00109140(void);
void func_00169030(void*);
s32 func_00105310(Area*, Jumper*);
void func_0016fa98(s32, u32);
void func_00105370(s32, s32);
void func_001de7d8(u32, u32, u32);
s32 func_001a84f0(void);
s32 func_001a8510(Jumper*);
void func_001382b8(s32);
void func_00102448(void*, s32);
void func_00102688(u32, s32, s32);
void func_001de910(void);
void func_001053c0(void);
void func_00182d80(void);
void func_001052a8(Area*);
s32 func_002283b0(void);
void func_002b9f28(s32);
void func_00149ca0(void);
void func_001366b8(void*);
void func_00136fd0(void);
void func_00169148(void*);
void func_0013a8f8(void);
void func_00149c08(void);
s32 func_0013a9f8(void);
void func_001de7b0(s32);
void func_00169178(void);
void func_00170888(void*);
void func_00136878(void);
void func_00136d40(void*);
s32 func_0013ef80(void);
void func_00102c18(s32, s32, void (*)(void));

void func_00104a48(void* task)
{
    Jumper j;

    Area_init(&j.dest, 0xffff);
    j.f32 = 0;
    func_0019ef70(&j);
    func_0014ce60();
    func_00109140();
    for (;;) {
        func_00169030(task);
        if (!func_00105310(&D_0032bae0, &j)) break;
        func_0016fa98(6, 0x8c0000);
        func_00105370(0x380000, 0x100000);
        func_001de7d8(D_0032bb1c, 0x80000, 0x20000);
        while (!func_001a84f0()) {
            func_001382b8(func_001a8510(&j));
            func_00102448(task, 0);
        }
        D_003a7b08 = D_0032bae0;
        D_003a7b00 = 1;
        asm volatile(""); // sched2 barrier: keeps move a1,zero after the sb, for the jal delay slot
        func_0019f070(&j, 0);
        func_00102448(task, 0);
        D_003a7b00 = 0;
        func_00102688(D_0032b968[1], 8, 8);
        func_001de910();
        func_001053c0();
        func_0016fa98(6, 0xc0000);
        func_00182d80();
        func_001052a8(&D_003a7b08);
    }
    func_00105370(D_0034ecd0 + D_0034ecd4, D_0034ecd4);
    func_0016fa98(6, 0xc0000);
    func_002b9f28(func_002283b0());
    func_00149ca0();
    func_001366b8(task);
    func_00136fd0();
    func_00169148(task);
    func_0013a8f8();
    func_00149c08();
    func_001de7b0(func_0013a9f8());
    func_00169178();
    func_00170888(task);
    func_00136878();
    func_00136d40(task);
    while (!func_0013ef80()) {
        func_00102448(task, 0);
    }
    func_00102c18(0, 1000, func_00104cc0);
}
}
