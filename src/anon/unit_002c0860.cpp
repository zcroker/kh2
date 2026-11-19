// Linked unit 0x2c0860-0x2c0ca0: constructor of a menu object (layout file + 3 + 1 + 2 sprites with parents), written in C++
// from the retail asm (was whole asm, L135 2026-11-18). Needs -fno-gcse: with gcse the &mid.seq address is shared and spilled.
#include "../common/types.h"
struct LayFile { u8 pad[0x1c]; };
struct Sp {
    void* vptr; u8 pad04[0x8]; s32 m0c; u8 pad10[0x8]; u8 seq[0x170];
    s32 m188; Sp* parent; s32 m190; u8 pad194[4];
};
struct Lay { void* vptr; u8 pad04[8]; u8 m0c[0xc]; u8 m18[0x18]; u8 m30[0x70]; };
struct Menu {
    void* vptr; u8 pad04[8]; s32 m0c; u8 pad10[8]; s32 m18;
    Lay lay;          /* 0x1c */
    s32 cache;        /* 0xbc */
    Sp title;         /* 0xc0 */
    Sp icons[3];      /* 0x258 */
    Sp mid;           /* 0x720 */
    Sp tail[2];       /* 0x8b8 */
    s32 image;        /* 0xbe8 */
};
extern u8 D_00361aa0[] asm("D_00361aa0");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_0035eb98[] asm("D_0035eb98");
extern u8 D_00347e60[] asm("D_00347e60");
extern Menu* D_00361a90 asm("D_00361a90");
void func_0031a838(void*) asm("func_0031a838");
void func_002369a0(void*) asm("func_002369a0");
void func_0023c008(void*) asm("func_0023c008");
void func_00239700(void*) asm("func_00239700");
s32 func_002beb90(void) asm("func_002beb90");
s32 func_001708f8(s32, s32) asm("func_001708f8");
void func_0023f800(LayFile*) asm("func_0023f800");
void func_0023f848(LayFile*) asm("func_0023f848");
void func_0023fa08(LayFile*, s32) asm("func_0023fa08");
s32 func_0023f948(LayFile*, s32) asm("func_0023f948");
s32 func_0023f908(LayFile*, s32) asm("func_0023f908");
s32 func_002c1460(Menu*, s32) asm("func_002c1460");
void func_0023eea0(Lay*, s32, s32, s32, s32, s32) asm("func_0023eea0");
void func_0023ef50(Lay*) asm("func_0023ef50");
void func_0023f0c8(Lay*, s32) asm("func_0023f0c8");
void func_00139570(Lay*) asm("func_00139570");
void* func_0023f1b0(Lay*) asm("func_0023f1b0");
s32 func_0023c4b8(void*, s32) asm("func_0023c4b8");
s32 func_00236ca8(s32, s32) asm("func_00236ca8");
void func_001386e0(Sp*, s32, s32, s32, s32, s32) asm("func_001386e0");
void func_001396b0(Sp*) asm("func_001396b0");
void func_0031a260(Sp*, s32) asm("func_0031a260");
void func_00139660(Sp*) asm("func_00139660");
void func_00139688(Sp*) asm("func_00139688");
void func_00138c68(Sp*, s32, s32) asm("func_00138c68");
s32 func_0023aa98(void*) asm("func_0023aa98");
void func_001391c8(Menu*, s32, s32) asm("func_001391c8");
static inline void InitSprite(Sp* s) { s->m0c = 0; s->vptr = D_00347e60; func_00239700(s->seq); }
#define INIT(o) ((o).m0c = 0, (o).vptr = D_00347e60, func_00239700((o).seq))
static inline void InitArray(Sp* s, s32 n) { do { InitSprite(s); n--; s++; } while (n != -1); }
static inline void SetParent(Sp* s, Sp* p) {
    s->parent = p; func_001396b0(s);
    if (s->parent != 0) { s->m190 = 0; func_001396b0(s); if (s->m190 != 0) func_0031a260(s, 0); }
}
void func_002c0860(Menu* self) asm("func_002c0860");
void func_002c0860(Menu* self) {
    LayFile lf;
    s32 gra, mes, unit, x, r;
    Sp* title;
    Sp* mid;
    self->m0c = 0;
    *(u32*)&self->lay.vptr = (u32)D_00347f98;
    *(u32*)&self->vptr = (u32)D_00361aa0;
    self->m18 = 0;
    title = &self->title;
    func_0031a838(self->lay.m0c);
    self->lay.vptr = D_0035eb98;
    func_002369a0(self->lay.m18);
    func_0023c008(self->lay.m30);
    self->cache = 0;
    INIT(self->title);
    InitArray(self->icons, 2);
    INIT(self->mid);
    mid = &self->mid;
    InitArray(self->tail, 1);
    D_00361a90 = self;
    x = 0;
    func_0023f800(&lf);
    self->cache = func_001708f8(func_002beb90(), -1);
    func_0023fa08(&lf, self->cache);
    gra = func_0023f948(&lf, 0);
    mes = func_0023f908(&lf, 0);
    r = func_002c1460(self, 0);
    func_0023eea0(&self->lay, 30101, gra, mes, r, 0);
    func_0023ef50(&self->lay);
    func_0023f0c8(&self->lay, func_002c1460(self, 2));
    func_00139570(&self->lay);
    unit = func_0023c4b8(func_0023f1b0(&self->lay), 1);
    self->image = func_00236ca8(*(s32*)((u8*)func_0023f1b0(&self->lay) + 0x28), 1);
    func_001386e0(title, 30105, unit, self->image, 75, 201);
    title->m188 = 76;
    for (s32 j = 0; j < 3; j++) {
        func_001386e0(&self->icons[j], 30105, unit, self->image, 39, 201);
        SetParent(&self->icons[j], title);
        func_00139660(&self->icons[j]);
        func_00139688(&self->icons[j]);
        func_00138c68(&self->icons[j], x, 0);
        func_001396b0(&self->icons[j]);
        x += func_0023aa98(self->icons[j].seq);
    }
    func_001386e0(mid, 30105, unit, self->image, 49, 201);
    SetParent(mid, title);
    func_00139660(mid);
    func_00139688(mid);
    func_00138c68(mid, x, 0);
    func_001396b0(mid);
    x += func_0023aa98(self->mid.seq);
    for (s32 j = 0; j < 2; j++) {
        func_001386e0(&self->tail[j], 30105, unit, self->image, 39, 201);
        SetParent(&self->tail[j], title);
        func_00139660(&self->tail[j]);
        func_00139688(&self->tail[j]);
        func_00138c68(&self->tail[j], x, 0);
        func_001396b0(&self->tail[j]);
        x += func_0023aa98(self->tail[j].seq);
    }
    func_001391c8(self, 30102, 201);
    func_0023f848(&lf);
}
