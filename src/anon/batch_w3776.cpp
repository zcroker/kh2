#include "../common/types.h"
extern "C" {
struct Ent149448 { u8 pad[8]; s32 data; };
struct Part149448 { s32 a; s32 b; s32 c; };
struct Map149448 {
    char name[32];
    s32 bar;
    s32 f24, f28, f2c, f30, f34, f38, f3c, f40, f44, f48, f4c, f50;
    s32 tex[4];
    s32 f64, f68;
    s32 nSk0, nSk1, nBob;
    Part149448 parts[96];
    s32 nTex;
};
s32 m149448_Alloc(const char*, s32) asm("_ZN2YS10CACHE_BUFF5AllocEPKci");
void func_001491d8(Map149448*);
s32 func_00168aa0(s32, s32);
void func_00168ad8(s32, s32*, s32, u32);
Ent149448* func_00168b38(s32, s32, s32);
Ent149448* func_00168b88(s32, s32, u32, s32);
}
static inline u32 Tag149448(const char* s) { return s[0] | s[1] << 8 | s[2] << 16 | s[3] << 24; }
static inline Ent149448* GetEnt149448(s32 bar, s32 t, const char* s, s32 i) { return func_00168b88(bar, t, Tag149448(s), i); }
// Map resource setup: allocates the map BAR, then reads the MAP/SK0/SK1/BOB entries and the
// remaining typed entries and texture list into the map record.
extern "C" {
void func_00149448(Map149448* m) {
    char map[4] = "MAP";
    char sk0[4] = "SK0";
    char sk1[4] = "SK1";
    char bob[4] = "BOB";
    s32 bar = m149448_Alloc(m->name, -1);
    func_001491d8(m);
    m->bar = bar;
    func_00168b88(bar, 4, Tag149448(map), 0);
    GetEnt149448(m->bar, 4, map, 0);
    m->f24 = GetEnt149448(m->bar, 4, map, 0)->data;
    if (GetEnt149448(m->bar, 7, map, 0)) m->f28 = GetEnt149448(m->bar, 7, map, 0)->data;
    func_00168b38(m->bar, 5, 0);
    func_00168b38(m->bar, 5, 0);
    m->f2c = func_00168b38(m->bar, 5, 0)->data;
    if (func_00168b38(m->bar, 6, 0)) m->f30 = func_00168b38(m->bar, 6, 0)->data;
    if (func_00168b38(m->bar, 11, 0)) m->f34 = func_00168b38(m->bar, 11, 0)->data;
    func_00168ad8(m->bar, &m->nBob, 4, Tag149448(bob));
    func_00168ad8(m->bar, &m->nSk0, 4, Tag149448(sk0));
    func_00168ad8(m->bar, &m->nSk1, 4, Tag149448(sk1));
    s32 n = 0;
    s32 i;
    s32 j;
    for (i = 0; i < m->nSk0; i++, n++) {
        m->parts[n].a = GetEnt149448(m->bar, 4, sk0, 0)->data;
        m->parts[n].b = GetEnt149448(m->bar, 7, sk0, 0)->data;
    }
    for (i = 0; i < m->nSk1; i++, n++) {
        m->parts[n].a = GetEnt149448(m->bar, 4, sk1, 0)->data;
        m->parts[n].b = GetEnt149448(m->bar, 7, sk1, 0)->data;
    }
    for (j = 0; j < m->nBob; j++, n++) {
        m->parts[n].a = GetEnt149448(m->bar, 4, bob, j)->data;
        if (GetEnt149448(m->bar, 7, bob, j)) m->parts[n].b = GetEnt149448(m->bar, 7, bob, j)->data;
        if (GetEnt149448(m->bar, 30, bob, j)) m->parts[n].c = GetEnt149448(m->bar, 30, bob, j)->data;
    }
    if (func_00168b38(m->bar, 14, 0)) m->f4c = func_00168b38(m->bar, 14, 0)->data;
    if (func_00168b38(m->bar, 15, 0)) m->f38 = func_00168b38(m->bar, 15, 0)->data;
    if (func_00168b38(m->bar, 19, 0)) m->f3c = func_00168b38(m->bar, 19, 0)->data;
    if (func_00168b38(m->bar, 39, 0)) m->f40 = func_00168b38(m->bar, 39, 0)->data;
    if (func_00168b38(m->bar, 18, 0)) m->f50 = func_00168b38(m->bar, 18, 0)->data;
    if (func_00168b38(m->bar, 21, 0)) m->f44 = func_00168b38(m->bar, 21, 0)->data;
    if (func_00168b38(m->bar, 27, 0)) m->f48 = func_00168b38(m->bar, 27, 0)->data;
    if (func_00168b38(m->bar, 24, 0)) m->f64 = func_00168b38(m->bar, 24, 0)->data;
    if (func_00168b38(m->bar, 25, 0)) m->f68 = func_00168b38(m->bar, 25, 0)->data;
    m->nTex = func_00168aa0(m->bar, 10);
    for (s32 t = 0; t < m->nTex; t++) m->tex[t] = func_00168b38(m->bar, 10, t)->data;
}
}
