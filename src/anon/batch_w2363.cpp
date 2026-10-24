#include "../common/types.h"
extern "C" {

/* 002bbde0: reset the sound-event state and the two global node lists, then re-enable 3D SE. */
struct SeList2363 { s32 head; s32 tail; };
extern s32 D_003616f4;
extern s32 D_003616e8;
extern SeList2363 D_01e2aa80;
extern SeList2363 D_01e2aa88;
void func_002bb0c8(s32);
void se3d_enable_w2363() asm("_ZN5SOUND10SE3DEnableEv");
void func_002bbde0()
{
    D_003616f4 = 0;
    D_003616e8 = 1;
    func_002bb0c8(100);
    SeList2363* a = &D_01e2aa80;
    SeList2363* b = &D_01e2aa88;
    a->tail = 0;
    b->tail = 0;
    a->head = 0;
    *(volatile s32*)&b->head = 0;  /* volatile keeps this store last, as in the original */
    se3d_enable_w2363();
}

/* 00194980: set D_01c61af4 when the current entry's id has an Ansem report entry. */
struct Entry2363 { u8 pad[50]; u16 id; };
extern u8 D_01c61af4;
Entry2363* ctarget_001947c0_w2363(s32 a, s32 b) asm("_Z16ctarget_001947c0jjjj");
s32 has_ansem_entry_w2363(u32 id) asm("_ZN2Tz6JmInfo13HasAnsemEntryEj");
void ctarget0_00194980(void) asm("_Z17ctarget0_00194980v");
void ctarget0_00194980(void)
{
    u8 found = 0;
    Entry2363* e = ctarget_001947c0_w2363(-1, -1);
    /* the loop (one pass at most) keeps gcc from if-converting found = 1 */
    while (e->id != 0 && has_ansem_entry_w2363(e->id) > 0) {
        found = 1;
        break;
    }
    D_01c61af4 = found;
}


/* 001443c0: static-destruction hook for the 16-entry table at D_00348830 (each entry holds five
   16-byte members with empty destructors); the compiler-generated array dtor loop is reproduced
   by an explicit destructor call on a wrapper type. */
struct Slot2363 { u8 b[16]; ~Slot2363() {} } __attribute__((aligned(16)));
struct Entry50_2363 { Slot2363 s[5]; };
struct Table2363 { Entry50_2363 e[16]; };
extern Table2363 D_00348830;
void wtarget_001443c0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_001443c0jjjj");
void wtarget_001443c0(u32 a0, u32 a1, u32 a2, u32 a3)
{
    if (a1 == 0xffff && a0 == 0) D_00348830.~Table2363();
}

}

/* 0018dbd8: an attack counts as a hit when flag 0x2, 0x8/0x10 or 0x200 is set. */
namespace YS {
struct ATTACK {
    u32 pad;
    u32 flags;
    bool hit_flag() const { u32 m = flags & 8; return m || (flags & 0x10); }
    bool is_hit();
};
bool ATTACK::is_hit() { return (flags & 2) || hit_flag() || (flags & 0x200); }
}
