#include "../common/types.h"
typedef struct Cur68 Cur68; typedef struct Own68 Own68;

struct Cur68 { u8 b[432]; s32 flag; };
struct Own68 { u32 pad; Cur68 c[25]; u8 pad2[120]; u32 x2b10; u32 x2b14; u32 x2b18; s32 id; };
s32 func_00291370(Own68*, s32);
s32 func_0023aa18(u8*);
s32 func_0023aa38(u8*);
s32 func_00139d78(Cur68*);
void func_0028d980(Cur68*, s32, u32, u32, u32, s32, s32, s32, s32);
void func_00139620(Cur68*);
void func_001395f8(Cur68*);
void func_00138c68(Cur68*, s32, s32);
void func_0028dcc0(Cur68*, Cur68*);
void func_00290d68(Own68* o, Cur68* parent) {
    s32 seq = func_00291370(o, 0);
    s32 id = o->id;
    s32 x = func_0023aa18((u8*)parent + 24);
    s32 y = func_0023aa38((u8*)parent + 24);
    s32 i;
    for (i = 0; i < 5; i++) {
        Cur68* c = &o->c[i];
        if (!func_00139d78(c)) {
            func_0028d980(c, id, o->x2b14, o->x2b18, o->x2b10, seq, -1, -1, 0);
            func_00139620(c);
            func_001395f8(c);
            func_00138c68(c, x, y);
        }
        func_0028dcc0(c, parent);
        c = &o->c[i + 5];
        if (!func_00139d78(c)) {
            func_0028d980(c, id, o->x2b14, o->x2b18, o->x2b10, seq, -1, -1, 0);
            func_00139620(c);
            func_001395f8(c);
            func_00138c68(c, x, y);
        }
        func_0028dcc0(c, parent);
    }
    id++;
    for (i = 0; i < 15; i++) {
        Cur68* c = &o->c[i + 10];
        if (!func_00139d78(c)) {
            func_0028d980(c, id, o->x2b14, o->x2b18, o->x2b10, seq, -1, -1, 0);
            func_00139620(c);
            func_001395f8(c);
            c->flag = 1;
        }
        func_0028dcc0(c, &o->c[i % 5]);
    }
}
