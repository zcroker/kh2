// 00241160: scans the entry table for flagged entries whose name matches one of the known names
// and returns a mask of which matched (0x10 marks unknown entries). The byte offset written as
// (i * 5) << 3 is a shift giv that loop.c strength-reduces; the else part keeps e[i] (a mult).
#include "../common/types.h"
struct Ent { u32 flags; s32 id; char name[32]; };
struct EntX { u32 pad[2]; u32 flags; s32 id; char name[32]; };
struct Tbl { s32 count; s32 pad; Ent e[1]; };
extern "C" {
s32 func_00240108();
s32 func_002416d8(s32);
s32 strcmp(const char*, const char*);
s32 strlen(const char*);
extern char* D_0035ebf8;
extern char* D_0035ebfc;
extern char* D_0035ec00;
extern char* D_0035ec88;
extern Tbl* D_0035ec98;
s32 func_00241160(void) {
    s32 i;
    s32 r = 0;
    s32 n = D_0035ec98->count;
    for (i = 0; i < n; i++) {
        s32 off = (i * 5) << 3;
        if (!(((EntX*)(off + (u32)D_0035ec98))->flags & 2)) continue;
        if (strlen(((EntX*)(off + (u32)D_0035ec98))->name) == 0) continue;
        if (strcmp(((EntX*)((u32)D_0035ec98 + off))->name, D_0035ebf8) == 0) {
            r |= 1;
            EntX* e = ((EntX*)(off + (u32)D_0035ec98));
            s32 k = 0x3c4;
            if (e->id != k) {
                r |= 0x100;
                e->flags |= 0x10;
            }
        } else {
            const char* s;
            if (func_00240108()) s = D_0035ec00; else s = D_0035ebfc;
            if (strcmp(D_0035ec98->e[i].name, s) == 0) {
                r |= 2;
                if (D_0035ec98->e[i].id != 0x8a58) {
                    r |= 0x200;
                    D_0035ec98->e[i].flags |= 0x10;
                }
            } else if (strcmp(D_0035ec98->e[i].name, D_0035ec88) == 0) {
                r |= 4;
                if (D_0035ec98->e[i].id != func_002416d8(2)) {
                    r |= 0x400;
                    D_0035ec98->e[i].flags |= 0x10;
                }
            } else {
                r |= 0x10;
                D_0035ec98->e[i].flags |= 0x10;
            }
        }
    }
    return r;
}
}
