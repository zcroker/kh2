#include "../common/types.h"

// 0x15d828-0x15e070: a full-screen 2D overlay panel (0x1340 bytes) built from dk rects: a clear rect at +16,
// a texture rect at +544, two rows of six 256-byte cells (+1072, +2608) and a blend rect at +4144. Two
// instances live at 0x34b240 and 0x34b244. The class vtable (0x34b250: init 0x15d8b0, draw 0x15d828, D1/D0
// at 0x31ddf0/0x31dee8) and its out-of-line ctor (0x31dd50) stay retail; the methods are plain functions here.

struct Panel;
struct PanelVt {
    void (*init)(Panel*);
    void (*draw)(Panel*);
    void (*d1)(Panel*);
    void (*d0)(Panel*);
};
struct Panel {
    PanelVt* vt;
    u8 active;
};

extern "C" {
void** D_0034b240 = 0;
void** D_0034b244 = 0;
}

extern void** D_0034b278 asm("D_0034b278");

void rb_setGsZbuf(u8*, u64) asm("_ZN2dk8RectBase9setGsZbufEy");
void rb_setGsFrame(u8*, u64) asm("_ZN2dk8RectBase10setGsFrameEy");
void rb_setGsPrim(u8*, u64) asm("_ZN2dk8RectBase9setGsPrimEy");
void rb_setGsUV(u8*, u64, u64) asm("_ZN2dk8RectBase7setGsUVEyy");
void rb_setGsTest(u8*, u64) asm("_ZN2dk8RectBase9setGsTestEy");
void rb_setGsAlpha(u8*, u64) asm("_ZN2dk8RectBase10setGsAlphaEy");
void rb_setGsTex0(u8*, u64) asm("_ZN2dk8RectBase9setGsTex0Ey");
void rp_setColor(u8*, u8, u8, u8, u8) asm("_ZN2dk13RectParamBase8setColorEhhhh");
void rp_setWidthHeight(u8*, u16, u16) asm("_ZN2dk13RectParamBase14setWidthHeightEtt");
void rp_setXY(u8*, s16, s16) asm("_ZN2dk13RectParamBase5setXYEss");
void rp_setUVSize(u8*, s32, s32) asm("func_0014b468");
void rp_setUVRect(u8*, s32, s32, s32, s32) asm("func_0014b4b0");
u32 tbp_alloc(s32) asm("func_001667d0");
void rect_draw(u8*) asm("func_0014c738");
void rect_draw2(u8*) asm("func_0014c350");
void Panel_ctor(Panel*) asm("func_0031dd50");
u32 func_00194908_d(void) asm("func_00194908");

extern "C" {
void func_0015d828(u8* p);
void func_0015d8b0(u8* p);
void func_0015de98(void);
void func_0015e018(void);
void func_0015e038(void);
}

extern "C" {

static inline void vcall8(u8* o) { (*(void (**)(void*))(*(u8**)o + 8))(o); }

// 0x15d828 (vtable slot 1): draw.
void func_0015d828(u8* p) {
    rect_draw(p + 16);
    vcall8(p + 544);
    u8* q = p;
    s32 i;
    for (i = 0; i < 6; i++) {
        vcall8(q + 2608);
        vcall8(q + 1072);
        q += 256;
    }
    rect_draw2(p + 4144);
}

static inline void initCell(u8* r) {
    rb_setGsZbuf(r, 0x131000070ULL);
    rb_setGsFrame(r, 0x1040140);
    rb_setGsPrim(r, 342);
    rb_setGsTest(r, 0x30000);
    rp_setColor(r, 128, 128, 128, 64);
    rb_setGsAlpha(r, 0x4000000064ULL);
    rp_setWidthHeight(r, 256, 208);
    rp_setUVSize(r, 256, 208);
    rb_setGsTex0(r, ((u64)tbp_alloc(256) << 26) | 0x200d000240112800ULL);
    rp_setXY(r, 0, 0);
}

// 0x15d8b0 (vtable slot 0): set up every rect.
void func_0015d8b0(u8* p) {
    u8* c = p + 16;
    u8* r = p + 544;
    rb_setGsZbuf(c, 0x131000070ULL);
    rb_setGsFrame(c, 0x40140);
    rb_setGsPrim(c, 6);
    rb_setGsTest(c, 0x30000);
    rp_setColor(c, 0, 0, 0, 0);
    rp_setWidthHeight(c, 256, 208);
    rb_setGsZbuf(r, 0x131000070ULL);
    rb_setGsFrame(r, 0x1040140);
    rb_setGsPrim(r, 278);
    rb_setGsTest(r, 0x3080d);
    rp_setWidthHeight(r, 256, 208);
    rp_setUVSize(r, 512, 416);
    rb_setGsTex0(r, ((u64)tbp_alloc(512) << 26) | 0x2005000640021b00ULL);
    u8* q = p;
    s32 i;
    for (i = 0; i < 6; i++) {
        initCell(q + 1072);
        initCell(q + 2608);
        q += 256;
    }
    rp_setXY(p + 1072, 1, 0);
    rp_setUVRect(p + 1072, 0, 255, 0, 208);
    rp_setXY(p + 1328, -1, 0);
    rp_setUVRect(p + 1328, 1, 256, 0, 208);
    rp_setXY(p + 1584, 2, 0);
    rp_setUVRect(p + 1584, 0, 254, 0, 208);
    rp_setXY(p + 1840, -2, 0);
    rp_setUVRect(p + 1840, 2, 256, 0, 208);
    rp_setUVRect(p + 2096, 0, 250, 0, 208);
    rp_setUVRect(p + 2352, 6, 256, 0, 208);
    rp_setXY(p + 2608, 0, 1);
    rp_setUVRect(p + 2608, 0, 256, 0, 207);
    rp_setXY(p + 2864, 0, -1);
    rp_setUVRect(p + 2864, 0, 256, 1, 208);
    rp_setXY(p + 3120, 0, 2);
    rp_setUVRect(p + 3120, 0, 256, 0, 206);
    rp_setXY(p + 3376, 0, -2);
    rp_setUVRect(p + 3376, 0, 256, 2, 208);
    rp_setUVRect(p + 3632, 0, 256, 0, 202);
    rp_setUVRect(p + 3888, 0, 256, 6, 208);
    u8* t = p + 4144;
    rb_setGsZbuf(t, 0x131000070ULL);
    rb_setGsFrame(t, 0x10800d8);
    rb_setGsTest(t, 0x30000);
    rb_setGsPrim(t, 342);
    rb_setGsAlpha(t, 0x8000000068ULL);
    rp_setColor(t, 128, 128, 128, 128);
    rp_setWidthHeight(t, 512, 416);
    rb_setGsUV(t, 0x80008, 0xd001000);
    rb_setGsTex0(t, ((u64)tbp_alloc(256) << 26) | 0x200d000240112800ULL);
}

// 0x15de18 / 0x15de58: draw a panel when it is active.
void func_0015de18(void) {
    Panel* o = (Panel*)D_0034b240;
    if (o->active == 1) o->vt->draw(o);
}

void func_0015de58(void) {
    Panel* o = (Panel*)D_0034b244;
    if (o->active == 1) o->vt->draw(o);
}

// 0x15de98 / 0x15def8: create a panel.
void func_0015de98(void) {
    void** heap = D_0034b278;
    void** new_var3;
    void** o = (void**)((void* (*)(void*, u32, void*))(*((void***)D_0034b278))[0])(heap, 4928, __builtin_return_address(0));
    void** new_var;
    void** new_var2;
    Panel_ctor((Panel*)o);
    D_0034b240 = o;
    new_var = o;
    new_var2 = new_var;
    new_var3 = *((void***)new_var2);
    o = new_var3;
    ((void (*)(void*))o[0])(new_var2);
}

void func_0015def8(void) {
    void** heap = D_0034b278;
    void** o = (void**)((void* (*)(void*, u32, void*))(*(void***)heap)[0])(heap, 4928, __builtin_return_address(0));
    Panel_ctor((Panel*)o);
    D_0034b244 = o;
    ((void (*)(void*))(*(void***)o)[0])(o);
    ((u8*)D_0034b244)[4] = 1;
}

void func_0015df68(void) {
    func_0015de98();
    if (func_00194908_d() != 0) {
        func_0015e018();
        return;
    }
    func_0015e038();
}

// 0x15df98 / 0x15dfd8: delete a panel.
void func_0015df98(void) {
    Panel* o = (Panel*)D_0034b244;
    if (o) o->vt->d0(o);
    D_0034b244 = 0;
}

void func_0015dfd8(void) {
    Panel* o = (Panel*)D_0034b240;
    if (o) o->vt->d0(o);
    D_0034b240 = 0;
}

void func_0015e018(void) {
    Panel* o = (Panel*)D_0034b240;
    if (o) o->active = 1;
}

void func_0015e038(void) {
    Panel* o = (Panel*)D_0034b240;
    if (o) o->active = 0;
}

u8 func_0015e050(void) {
    Panel* o = (Panel*)D_0034b240;
    if (o) return o->active;
    return 0;
}

}  // extern "C"
