#include "../common/types.h"
struct H1881 { u16 a; s16 h2; s16 h4; u8 pad[646]; u8 body[1]; };
extern "C" {
extern s32 D_0035f3d4;
extern u32 D_0035f03c;
extern u32 D_0035ef68;
extern u32 D_0035ef64;
extern H1881* D_0035f230;
extern u8 D_00373de8[];
u8* func_00257770(void);
s32 func_00139d78(u8*);
void func_0028d980(u8*, s32, u32, u32, u32, s32, s32, s32, s32);
s32 func_00192cc0(u8*, u8*, s32, s32);
void func_0028d8c0(u8*, s32, u32, u32, u32, s32, s32, s32);
void func_0028dcc0(u8*, u8*);
void func_0027b248(s32);
void func_0027b0f8(void) {
    u8* base = func_00257770();
    u8* w = base + 0xb350;
    if (!func_00139d78(w)) {
        s32 id = D_0035f3d4;
        func_0028d980(w, id, D_0035ef68, D_0035ef64, D_0035f03c, 272, 273, -1, 0);
        H1881* h = D_0035f230;
        s32 a2 = h->h4; s32 a3 = h->h2; *(s32*)(w + 408) = func_00192cc0(h->body, D_00373de8, a2, a3);
        *(s32*)(w + 432) = 1;
        u8* w2 = base + 0xb504;
        func_0028d8c0(w2, id + 1, D_0035ef68, D_0035ef64, D_0035f03c, 269, -1, 100);
        func_0028dcc0(w2, w);
        u8* w3 = base + 0xb6b8;
        func_0028d8c0(w3, id + 2, D_0035ef68, D_0035ef64, D_0035f03c, 270, -1, 0);
        func_0028dcc0(w3, w);
    }
    func_0027b248(1);
}
}
