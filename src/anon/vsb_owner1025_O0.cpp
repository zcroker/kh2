// 002b9404: try.sh-clean at -O0 (_O0.cpp) but DOES NOT LINK: two short strings (ESC[41m, ESC[0m) are gp-relative (.sdata, default -G8); kh2.ld defines no _gp (needs _gp = 0x37a800), so R_MIPS_GPREL16 truncates. Needs a build change.
#include "../common/types.h"
extern "C" {
struct Pak { u8 magic[8]; u16 pad8; u16 f10; s32 count; };
extern s32 D_0032b920;
s32 func_002ff1a4(const void*, const char*);
void func_002fdfc8(const char*, ...);
void func_002b6550(void*, s32);
s32 func_002b9404(void* data, s32 idx, u32* size, u16* kind)
{
    Pak* h;
    u32* p;
    s32 off;
    h = (Pak*)data;
    if (func_002ff1a4(h, "IopVoice")) {
        func_002fdfc8("\x1b[44m%06d:\x1b[0m", D_0032b920);
        func_002fdfc8("Vsb data error ee_buff(%08x)no(%2d)\n", data, idx);
        func_002fdfc8("\x1b[41m");
        func_002b6550(data, 4);
        func_002fdfc8("\x1b[0m");
        return -1;
    }
    if (idx >= h->count) {
        func_002fdfc8("\x1b[44m%06d:\x1b[0m", D_0032b920);
        func_002fdfc8("Vsb voice number error ee_buff(%08x)no(%2d)max(%d)\n", data, idx, h->count);
        return -1;
    }
    *kind = h->f10;
    p = (u32*)((u8*)data + idx * 8 + 16);
    off = *p++;
    *size = *p++;
    if (off < 0) {
        func_002fdfc8("\x1b[44m%06d:\x1b[0m", D_0032b920);
        func_002fdfc8("Vsb voice number error ee_buff(%08x)no(%2d)max(%d)\n", data, idx, h->count);
        return -1;
    }
    return (s32)((u8*)data + h->count * 8 + off + 16);
}
}
