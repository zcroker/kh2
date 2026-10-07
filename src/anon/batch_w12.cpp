#include "../common/types.h"

extern "C" {
void func_00113668(void*);
void func_00105110(void*);
void* func_0011ef70(void*, void*);
void func_0011f2f0(void*);
void func_0011ee58(void*);
void func_00106420(void*);
void func_002362b0(void*, void*);
void func_002367c8(void*);
void func_0014ce20(s32);
void func_0014ce30(s32);
void func_0014ce60(void);
void func_00138c10(void*, s32);
void* func_00140df0(void);
void func_00140f10(void*);
void func_00140dd0(void*);
void func_001024a8(void*);
void* func_001050c8(void);
void func_001ba028(u32);
void func_0016bd60(u32, s32);
void func_00177498(void*);
void func_0016cc18(void*, void*, void*, void*, s32);
s32 func_001afee8(s32, s32);
void func_0016c2b0(void*);
void func_001b1100(u32, void*);
void func_00165898(void*);
void func_001a4e30(void*);
void func_001c8d80(void*, s32);
void func_0014c9d8(s32);
void func_001bbe38(s32);
void func_0016c5b8(s32, s32);
void func_001dc9e0(void*);
s32 func_001e6d08(u32);
void func_001e17b8(void*);
s32 func_00197920(void);
void func_00226dc8(void);
void func_00234670(s32, u32, s32, s32, s32);
void func_0027d008(void*);
void func_0027d540(void);
void func_0027d5d8(void);
void func_0027d810(s32);
void func_002b6adc(s32, u32);
void func_002b6ab8(void);
u8 func_00325320(void*, void*);
void func_002cff98(void*);
void func_002ceb08(void);
void func_0017c430(void*);
void func_00138988(void*);
void func_0014b9a8(void*);
void func_00138de0(void*);
void func_0031ffc0(void*);
void func_002dea80(void*);

extern u8 D_00346658;
extern u8 D_003479a8;
extern volatile s32 D_00349e04;
extern volatile s32 D_00349e08;
extern s32 D_0034aa90;
struct Rgba { u8 r, g, b, a; };
extern Rgba D_004f3704[];
extern s32 D_01d48c90;
extern u8 D_0032fb68[];
struct Slot64 { u16 used; u8 pad[62]; };
extern Slot64 D_01d49388[];
extern s32 D_01d49530[8];
extern s32 D_01d49550;
extern u8 D_00351da8;
extern void* D_00351d98;
extern u8 D_00351ec0;
extern u8 D_0035de0c;
extern u8* D_0035dcfc;
extern s16 D_0035de14;
extern u8 D_0035de15;
extern s8* D_0035ec94;
extern u32 D_0035ec88;
extern void** D_0035f3f8;
extern u8 D_01e2be18;
extern u8 D_00362b68;
extern u8* D_00361f60;
extern u8 D_00352878;
extern u8 D_00362c70;

void SpriteImage_change(void*, void*) asm("_ZN2dk11SpriteImage6changeEPv");
void COUNTER_alertLoop(u8*) asm("_ZN2dk7COUNTER9alertLoopEv");
void TalkCamera_ensureTask(void*, void*) asm("_ZN2dk10TalkCamera10ensureTaskEP4TASK");
void trap_obj_idle(u32**) asm("_ZN2YS13trap_obj_idleEP8BD_VALUE");
void PARTY_hook(u8*, void*) asm("_ZN2YS5PARTY4hookEPNS_2VME");
void ctarget_001b1328(u32, u32, u32, u32) asm("_Z16ctarget_001b1328jjjj");
bool EFFECT_is_waiting(u8*) asm("_ZN3ryj6EFFECT10is_waitingEv");
s32 JmReport_GetData(s16*) asm("_ZN2Tz8JmReport7GetDataEj");
void ScisSpriteMessage_draw(u8*) asm("_ZN2dk17ScisSpriteMessage4drawEv");


// Deleting destructor: reset vtable, run base dtor, free.
void func_00114b90(void** p) {
    *p = &D_00346658;
    func_00113668(p);
    func_00105110(p);
}

void func_0011f3e0(void* p) {
    u8* c = 0;
    while ((c = (u8*)func_0011ef70(p, c)) != 0)
        *(void**)(c + 20) = p;
    func_0011f2f0(p);
}

// Deleting destructor: reset vtable, run base dtor, free.
void func_0011f5a0(void** p) {
    *p = &D_003479a8;
    func_0011ee58(p);
    func_00106420(p);
}

void SpriteImage_change(void* self, void* data) {
    u8* img = (u8*)self + 32;
    func_002362b0(img, data);
    func_002367c8(img);
}

void func_0014cfc8(void) {
    func_0014ce20(1);
    func_0014ce30(1);
    func_0014ce60();
    D_00349e04 = 0;
    D_00349e08 = 0;
}

void COUNTER_alertLoop(u8* self) {
    func_00138c10(self + 840, 1);
    func_00138c10(self + 1248, 7);
}

void TalkCamera_ensureTask(void* self, void* task) {
    func_00140f10(func_00140df0());
    func_00140dd0(func_00140df0());
    func_001024a8(self);
}

void func_0015a810(void) {
    void* a = func_001050c8();
    D_0034aa90 = (*(s32 (**)(void*, s32, s32))*(void**)a)(a, 0x800, 0);
}

// Sets RGBA colour slot i.
void func_0015cc18(s32 i, u8 r, u8 g, u8 b, u8 a) {
    Rgba* c = &D_004f3704[i];
    c->r = r; c->g = g; c->b = b; c->a = a;
}

void trap_obj_idle(u32** bd) {
    func_001ba028((*bd)[1]);
    func_0016bd60((*bd)[1], 0);
}

void PARTY_hook(u8* self, void* vm) {
    func_00177498(self);
    *(void**)(self + 2796) = vm;
}

s32 func_00188398(u8* o, void* a, void* b, void* c) {
    void* w;
    u8* x = *(u8**)(o + 136);
    w = *(void**)(*(u8**)(x + 4) + 1156);
    if (w) {
        if (a) { func_0016cc18(w, a, b, c, 0); return 1; }
    }
    return 0;
}

void func_00198aa8(u8* o, s32 i, s32 v, s32 id) {
    s32 val;
    u8* e;
    if (id == 0) {
        s16* t = *(s16**)(o + 2484);
        id = -1;
        if (t) id = t[1];
    }
    val = id * 1000 + v;
    e = o + i * 12;
    *(s32*)(e + 2532) = val;
}

struct Range { s32 cur, max, min; };
// Adds d to range i and clamps it to [min, max].
s32 func_001a1910(Range* r, s32 d, s32 i) {
    Range* e = &r[i];
    s32 v = e->cur + d;
    return e->cur = v < e->min ? e->min : (e->max < v ? e->max : v);
}

s32 func_001b0148(s32 x, s32 a, s32 v, s32 b) {
    if (v < 0) {
        if (v == -3) return func_001afee8(a, b);
        return -1;
    }
    return v;
}

void ctarget_001b1328(u32 a, u32 b, u32 c, u32 d) {
    u8 buf[16];
    func_0016c2b0(buf);
    func_001b1100(a, buf);
}

void func_001b2f10(void) {
    D_01d48c90 = 1;
    func_00165898(func_001050c8());
}

u8 func_001b8d60(u8* dst) {
    s32 i;
    u8 n = D_0032fb68[287];
    D_0032fb68[287] = 0;
    for (i = 0; i < n; i++) dst[i] = D_0032fb68[32 + i];
    return n;
}

Slot64* func_001c11e0(void) {
    s32 i;
    for (i = 5; i > 0; i--)
        if (D_01d49388[i].used) return &D_01d49388[i];
    return 0;
}

// Clears an 8-word table; the original has a 3-nop pad in the loop (asm).
void func_001c2b70(void) {
    s32* p = D_01d49530;
    s32 i = 7;
    do {
        *p = 0;
        i--;
        asm volatile("nop\n\tnop\n\tnop");
        p++;
    } while (i >= 0);
    D_01d49550 = 0;
}

// Deleting destructor: reset vtable, run base dtor, free.
void func_001c7c68(void** p) {
    *p = &D_00351da8;
    D_00351d98 = 0;
    func_001a4e30(p);
    func_00105110(p);
}

void func_001c8710(void) {
    func_001c8d80(&D_00351ec0, 3);
    func_0014c9d8(16);
    func_001bbe38(1);
    func_0016c5b8(2, 0xfff7ffdc);
}

bool EFFECT_is_waiting(u8* self) {
    func_001dc9e0(self);
    return func_001e6d08(*(u32*)(self + 28)) != 0;
}

void func_001e2788(u8* p) {
    *(s32*)(p + 3520) = 0;
    *(s32*)(p + 3524) = 0;
    *(s32*)(p + 3532) = 0;
    *(s32*)(p + 3536) = 0;
    *(s32*)(p + 3556) = 0;
    *(s32*)(p + 3564) = 0;
    *(s32*)(p + 3584) = -1;
    func_001e17b8(p);
}

void func_00226e60(u8 v) {
    if (func_00197920()) {
        D_0035de0c = v;
        func_00226dc8();
    }
}

u8* func_0022f4f0(s32 id) {
    u8* p = D_0035dcfc;
    s32 i;
    for (i = 0; i < 96; i++, p += 40)
        if (*(s32*)p == id) return p + 23;
    return 0;
}

void func_00232110(s16* p) {
    *(u8*)&D_0035de14 = 1;
    switch (p[3]) {
    case 0: D_0035de15 = 0; break;
    case 1: D_0035de15 = 1; break;
    }
}

void func_002375b0(u8* o, s32 i, s32 j, s32 d) {
    u8* e = *(u8**)(o + 8) + (*(u16*)(*(u8**)(o + 12) + i * 4) + j) * 20;
    *(s32*)(e + 12) = *(s32*)(e + 4) + d;
}

void func_00241568(void) {
    func_00234670(*D_0035ec94, D_0035ec88, 0, 0, 0);
}

void func_0027d598(void* p) {
    func_0027d008(p);
    func_0027d540();
    func_0027d5d8();
    func_0027d810(JmReport_GetData((s16*)p));
}

s32 JmReport_GetData(s16* self) {
    if (self[11] != 0) return (self[0] + self[9]) % self[11];
    return self[0] + self[9];
}

void func_0028cc40(void* a) {
    if (a) {
        void** o = D_0035f3f8;
        (*(void (**)(void*, void*))((u8*)*o + 4))(o, a);
    }
}

void func_002bd188(u32 a, u32 b) {
    func_002b6adc(2, b);
    func_002b6adc(0, b);
    func_002b6ab8();
}

s32 func_002cb708(u8* p) {
    func_00105110(*(void**)(p + 128));
    return func_00325320(&D_01e2be18, p);
}

// Deleting destructor: reset vtable, run base dtor, free.
void func_002ddb80(void** p) {
    *p = &D_00362b68;
    func_002cff98(p);
    func_00105110(p);
}

bool func_002e2dd8(void) {
    u8* p = D_00361f60;
    if (p) func_002ceb08();
    return *(s32*)(p + 272) != 0;
}

void func_002eaaf0(void* p) {
    func_0017c430(p);
    func_0016bd60((u32)p, 44);
}

void ScisSpriteMessage_draw(u8* self) {
    func_00138988(self);
    func_0014b9a8(self + 448);
    func_00138de0(self);
    func_0014b9a8(self + 480);
}

// Deleting destructor: reset vtable, run base dtor, free.
void func_0031ff88(void** p) {
    *p = &D_00352878;
    func_0031ffc0(p);
    func_00105110(p);
}

// Deleting destructor: reset vtable, run base dtor, free.
void func_00325618(void** p) {
    *p = &D_00362c70;
    func_002dea80(p);
    func_00106420(p);
}

}
