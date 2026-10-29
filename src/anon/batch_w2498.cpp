// func_0022c1f8: init three sub-objects from a2 and lay them out (x/y from a2+0x18 helpers).
#include "../common/types.h"
struct Sub {
    u8 pad0[0x18];
    u8 obj[0x16c];
    s32 state; /* 0x184 */
    s32 pad188;
    s32 f18c;
    s32 f190;
    u8 pad194[4];
};
struct Obj {
    u8 pad0[0x18];
    s32 f18;
    Sub sub[3];
};
struct Inp { u8 pad[0x18]; u8 cur[0x1a8]; u8 tail[1]; };
struct Th { u8 pad[4]; s32 f4; };
extern char D_0035e2f0[];
extern "C" {
Th* func_00197df8();
void func_00150260(void*, void*, s32, s32*);
void func_0023a9c0(void*, s32*, s32*);
s32 func_0023aa18(void*);
s32 func_0023aa38(void*);
void func_001386e0(Sub*, s32, s32, void*, s32, s32);
void func_001396b0(Sub*);
void func_0031a260(Sub*, s32);
void func_00139660(Sub*);
void func_00139688(Sub*);
void func_00138c10(Sub*, s32);
void func_00139598(Sub*);
s32 func_0023aa98(void*);
void func_00138c68(Sub*, s32, s32);

void func_0022c1f8(Obj* self, void* a1, u8* a2) {
    s32 buf[3];
    s32 x, y;
    s32 i;
    s32 sum;
    Th* t;
    u8* p = a2 + 0x1c0;
    self->f18 = (s32)a2;
    sum = 0;
    t = func_00197df8();
    func_00150260(D_0035e2f0, a1, 3, buf);
    func_0023a9c0(a2 + 0x18, &x, &y);
    x += func_0023aa18(a2 + 0x18);
    y += func_0023aa38(a2 + 0x18);
    {
        // Counting down with explicit stepping pointers (an index loop gets an iteration-count
        // prediction that swaps two saved registers).
        Sub* s = self->sub;
        s32* bp = buf;
        for (i = 2; i >= 0; i--) {
        func_001386e0(s, 26000, t->f4, p, *bp, 16);
        s->f18c = (s32)a2;
        func_001396b0(s);
        if (s->f18c != 0) {
            s->f190 = 0;
            func_001396b0(s);
            if (s->f190 != 0) {
                func_0031a260(s, 0);
            }
        }
        func_00139660(s);
        func_00139688(s);
        s++; bp++;
    }
    }
    for (i = 2; i > 0; i--) {
        if (buf[i] != 7) break;
        func_00138c10(&self->sub[i], 17);
        func_00139598(&self->sub[i]);
    }
    for (i = 0; i < 3; i++) {
        if (self->sub[i].state != 17) {
            sum += func_0023aa98(self->sub[i].obj);
        }
    }
    x += sum / 2;
    for (i = 0; i < 3; i++) {
        Sub* s = &self->sub[i];
        if (s->state != 17) {
            x -= func_0023aa98(s->obj);
            func_00138c68(s, x, y);
        }
    }
}

}
