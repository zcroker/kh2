#include "../common/types.h"

extern "C" {

struct E24 { s16 id; s16 k; u8 pad4[10]; u16 f14; u16 n; u16 pad18; u32 off; };
struct H16 { u8 pad0[6]; s16 count; u8 pad8[8]; E24 e[1]; };
struct Sub8 { s16 a; u16 b; u32 off; };
H16* func_00263ea8(void);
u32 func_001a6d08(s32);
void func_002641c8(u32, u8*, u32, u32);

void func_002640a8(s32 a0, u16 a1, u32 a2) {
    s32 i;
    H16* h = func_00263ea8();
    E24* e;
    for (i = 0, e = h->e; i < h->count; i++, e++) {
        if (e->id == a0) continue;
        if (!func_001a6d08(e->k)) continue;
        if (e->f14 & 0x80) continue;
        Sub8* s = (Sub8*)((u8*)h + e->off);
        s32 j;
        for (j = 0; j < e->n; j++, s++) {
            if (s->a < 0) func_002641c8(a2, (u8*)h + s->off, s->b, a1);
        }
    }
}

s32 func_00287cd0(void);
s32 func_00289310(u32);
void func_002890e0(u32, s32, s32, s32, s32);
u32 func_002891e8(u32);
void func_00289038(u32, u32, s32, s32, s32, s32, s32);
s32 func_00289358(u32);
void func_002b5c30(s32);
s32 func_0028d008(u32);
u32 func_002891d0(u32);
void func_0028cf28(u32, u32);
s32 func_0028d6e8(u32);
void func_0028d660(u32, u32);
void func_0025d560(void);
void func_0025f588(void);
extern u32 D_0035f67c;
extern u32 D_0035f64c;

void func_0025d3c8(u32 a0, s32 a1, u32 a2) {
    if (func_00287cd0() != 1) return;
    if (!func_00289310(a0)) return;
    func_002890e0(a0, 1, 2, 0, -1);
    func_00289038(a0, func_002891e8(a0), 1, 1, 2, 0, -1);
    if (a1 == 12 && func_00289358(a0)) func_002b5c30(0);
    if (func_0028d008(a2)) func_0028cf28(a2, func_002891d0(a0));
    if (func_0028d6e8(D_0035f67c)) func_0028d660(D_0035f67c, func_002891d0(a0));
    func_0025d560();
}

void func_0025f430(u32 a0, s32 a1, u32 a2) {
    if (func_00287cd0() != 1) return;
    if (!func_00289310(a0)) return;
    func_002890e0(a0, 1, 2, 0, -1);
    func_00289038(a0, func_002891e8(a0), 1, 1, 2, 0, -1);
    if (a1 == 12 && func_00289358(D_0035f64c)) func_002b5c30(1);
    if (func_0028d008(a2)) func_0028cf28(a2, func_002891d0(a0));
    if (func_0028d6e8(D_0035f67c)) func_0028d660(D_0035f67c, func_002891d0(a0));
    func_0025f588();
}

struct P6 { s16 x, y, z; };
extern P6* D_0035f4e8;
union UP6 { P6* p; s16 h; };
extern UP6 D_0035f4ec_ asm("D_0035f4ec");
#define D_0035f4ec D_0035f4ec_.p

void func_002933d8(s32 a0, s32 a1, s32 a2, P6* a3) {  // table_find_pair
    s32 i;
    s32 found = -1;
    if (!a3) a3 = D_0035f4e8;
    for (i = 0; i < 8; i++) {
        if (a3[i].x == a0 && a3[i].y == a1) {
            a3[i].x = a0;
            a3[i].y = a1;
            a3[i].z = a2;
            found = i;
            break;
        }
    }
    if (found < 0) {
        for (i = 0; i < 8; i++) {
            if (a3[i].x < 0) {
                a3[i].x = a0;
                a3[i].y = a1;
                a3[i].z = a2;
                found = i;
                break;
            }
        }
    }
    if (a3 == D_0035f4ec) return;
    for (i = 0; i < 8; i++) {
        if (D_0035f4ec[i].x == a3[found].x && D_0035f4ec[i].y == a3[found].y && D_0035f4ec[i].z == a3[found].z) {
            a3[found].x = -1;
            a3[found].y = -1;
            a3[found].z = -1;
            return;
        }
    }
}

union UN { s32 n; u16 h; };
struct T9 { u8 pad[8]; UN n; };
struct G { u8 pad[484]; u16 bits[1]; };
union UPg { G* p; u16 h; };
G* func_002a9d68(void);
T9* func_00294000(s32);
extern UPg D_0035f620;

static inline u32 bt(u16* b, s32 i) { return b[(u32)i >> 4] & (1 << (i & 15)); }
static inline void bs(u16* b, s32 i) {
    if (!bt(b, i)) b[(u32)i >> 4] |= 1 << (i & 15);
}

s32 func_002ae768(s32 a0) {
    s32 ret = 1;
    G* p = func_002a9d68();
    T9* t = func_00294000(9);
    s32 i;
    for (i = 0; i < t->n.n; i++) {
        if (bt(p->bits, i)) bs(D_0035f620.p->bits, i);
    }
    for (i = 0; i < t->n.n; i++) {
        if (a0 >= 0 && a0 != i) continue;
        if (!bt(D_0035f620.p->bits, i)) {
            ret = 0;
            break;
        }
    }
    return ret;
}

}
