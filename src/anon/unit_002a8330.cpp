// Linked unit 0x002a8330-0x002a8748: list page setup (was whole asm in src/anon/batch_w3880.s).
// Flags: -G0 -g -fno-strict-aliasing. .rodata@00374c18: the two format strings.
// Notes: (1) the format pointer is a local set before the v[] reads, so the %hi of the string lives 6 insns and
// loop.c hoists it (rematerialised by reload in t6); (2) RowOff() does the same for %hi(D_0035f604) at the loop head;
// (3) w pinned to $17 (o in s1, a in s2).
#include "../common/types.h"
extern "C" {
struct LEnt { s16 a; s16 b; };
struct LList { s32 n; LEnt e[1]; };
struct It { u16 h0; u16 name; u16 h4; u16 id; };
struct Dat { u8 kind; u8 pad[3]; u32 v; };
extern u32 D_0035f200;
extern u32 D_0035f214;
extern u8* D_0035f604;
extern LList* D_0035f600;
extern s32 D_00374c2c;
extern s32 D_00374c30;
u8* func_002766d0(void);
s32 func_0028b038(u32);
void func_0028be78(u32, s32);
void func_002fde18(void*, s32, s32);
void func_00138c10(u8*, s32);
s32 func_00295430(s32, s32);
s32 func_002954e0(s32);
s32 func_00192048(s32);
s32 func_0028de08(s32, u8*, s32);
It* func_002a7f20(s32);
Dat* func_001d56c8(u16);
s32 func_002a8920(u16);
void func_00192c90(s32, u8*);
s32 func_00192c40(s32, u8*);
void func_0014ca80(u32, s32*, s32*, s32*, s32*);
s32 func_00192cc0(u8*, const void*, ...);
s32 func_00105c30(void);
s32 func_00192b30(s32);
s32 func_002ab100(s32);
s32 func_002ab180(s32);
// Row offset in the 872-byte row table. The inline call keeps %hi(D_0035f604) live long enough
// (loop.c counts the inline block notes) for loop.c to hoist it; reload then rematerialises it.
static inline s32 RowOff(s32 i) { return i * 872; }
/*TARGET 002a8330*/
void func_002a8330(void) asm("func_002a8330");
void func_002a8330(void)
{
    s32 i;
    s32 t;
    register s32 w asm("$17");
    u8* base = func_002766d0();
    s32 top = func_0028b038(D_0035f200);
    func_0028be78(D_0035f214, top);
    func_002fde18(D_0035f604 + 8720, 0, 320);
    func_002fde18(base + 0x110a0, 0, 640);
    for (i = 0; i < 10; i++) {
        u8* p = D_0035f604 + i * 872;
        func_00138c10(p, 2);
        *(u32*)(p + 408) = 0;
        func_00138c10(base + i * 408 + 0xa998, 2);
    }
    s32 n = D_0035f600->n;
    if (n >= 11) n = 10;
    for (i = 0; i < n; i++) {
        s32 k = top + i;
        s32 a = D_0035f600->e[k].a;
        s32 b = D_0035f600->e[k].b;
        u8* o = D_0035f604 + RowOff(i);
        u8* buf = base + i * 64 + 0x110a0;
#define it ((It*)a)
        if (b < 0) {
            func_00138c10(o, 102);
            t = func_00295430(a, 1);
            if (func_002954e0(a)) *(s32*)(o + 408) = func_00192048(t);
            else *(s32*)(o + 408) = func_0028de08(t, buf, 64);
            continue;
        }
        a = (s32)func_002a7f20(b);
        Dat* d = func_001d56c8(it->id);
        func_00138c10(o, 108);
        t = it->name;
        if (!func_002a8920(it->id)) *(s32*)(o + 408) = func_0028de08(t, buf, 64);
        else *(s32*)(o + 408) = func_00192048(t);
        buf = D_0035f604 + i * 32 + 8720;
        if (d->kind < 2) {
            func_00192c90(func_00192048(19313), buf);
            if (!d->kind) continue;
        } else if (d->kind == 4) {
            w = func_00192c40(func_00192048(it->h4), buf);
            s32 v[4];
            func_0014ca80(d->v, &v[0], &v[1], &v[2], &v[3]);
            const char* fmt = "%02d'%02d\"%02d";
            s32 x = v[1], y = v[2], z = v[3];
            func_00192cc0(buf + w, fmt, x, y, z);
        } else {
            t = 0;
            if (func_00105c30() == 1 || func_00105c30() == 8) t = 1;
            if ((u8)t) {
                w = func_00192b30(func_00192cc0(buf, "%d", d->v));
                t = 19328;
                if (d->kind != 2) t = it->h4;
                func_00192c90(func_00192048(t), buf + w);
            } else if (d->kind == 2) {
                w = func_00192c40(func_00192048(19328), buf);
                func_00192cc0(buf + w, "%d", d->v);
            } else {
                w = func_00192b30(func_00192cc0(buf, "%d", d->v));
                func_00192c90(func_00192048(it->h4), buf + w);
            }
        }
        if (func_002ab100(D_0035f600->e[k].b)) {
            if (func_002ab180(D_0035f600->e[k].b)) t = D_00374c30;
            else t = D_00374c2c;
            func_00138c10(base + i * 408 + 0xa998, t);
        }
    }
}
#undef it
}
