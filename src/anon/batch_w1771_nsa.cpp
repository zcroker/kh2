#include "../common/types.h"

extern "C" {
extern u8 D_0034c750[];
extern s32 D_0034c738;
void func_00161530(void*);
}

struct I1602 { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void fa(s32, s32); };
struct E1602 { u8 pad[16]; ~E1602() {} } __attribute__((aligned(16)));
struct M1602 { u8 pad[16]; ~M1602() { func_00161530(this); } };
struct O1602 {
    u32 vt; I1602* x; u8 pad[0x88]; E1602 arr[8]; M1602 m; u8 pad2[0xa0]; s32 v;
    ~O1602() { vt = (u32)D_0034c750; x->fa(D_0034c738, v); }
};

struct Pos2bf3 { s32 x, y; Pos2bf3(s32 a, s32 b) { x = a; y = b; } };
struct Col2bf3 { u8 r, g, b, a; Col2bf3(u8 r_, u8 g_, u8 b_, u8 a_) { r = r_; g = g_; b = b_; a = a_; } };
struct Drw2bf3 { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void draw(Pos2bf3, Col2bf3); };

extern "C" {
extern Drw2bf3* D_00361998;
void func_001024a8(void);
void func_00236d60(void);
s32 func_002ee040(Drw2bf3*);

/* Destructor body: needs -fno-strict-aliasing for the virtual call argument order. */
void func_001602f8(O1602* o) { o->~O1602(); }

/* Needs -fno-strict-aliasing so the stack arguments are stored before the object reload. */
void func_002bf308(void) {
    if (D_00361998 == 0) {
        func_001024a8();
        return;
    }
    func_00236d60();
    if (func_002ee040(D_00361998)) {
        D_00361998->draw(Pos2bf3(0, 0), Col2bf3(0x80, 0x80, 0x80, 0x80));
    }
    func_00236d60();
}
}
