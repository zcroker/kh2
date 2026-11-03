#include "../common/types.h"
extern "C" {
// VU0 macro-mode vector helpers (hand-written asm in the original math library)
struct V110c90 {
    f32 x, y, z, w;
    V110c90() {}
    V110c90(const V110c90& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V110c90& operator=(const V110c90& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V110c90 operator-(const V110c90& b) const
    {
        V110c90 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 lengthSq() const
    {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(r) : "r"(this) : "$8");
        return r;
    }
} __attribute__((aligned(16)));
struct Box110c90;
void func_00144450(Box110c90*);
struct Box110c90 {
    f32 lx, ly, lz, hx, hy, hz;
    Box110c90() { func_00144450(this); }
};
struct Pts110c90 { u8 on; u8 pad[3]; s32 count; u8 pad2[8]; V110c90 pts[32]; };
struct O110c90 {
    u8 pad0[1856];
    Box110c90 box;
    const Box110c90& getBox() const { return box; }
    u8 pad1[2940 - 1880];
    u32 flags;
    u8 pad2[3288 - 2944];
    s32 f3288;
    f32 f3292;
    s32 f3296;
};
extern Pts110c90 D_003a9040;
extern u8 D_003a9250[];
extern O110c90* D_00341708;
s32 func_00146730(u8*, Box110c90*);
V110c90* f110c90_attach(O110c90*) asm("func_0016c028");
s32 func_00110b00(O110c90*, V110c90*, Box110c90*);
s32 f110c90_rand(s32) asm("func_0010f648");
// Picks a free warp point near o (pb pins &b to s7; gcc swaps it with best otherwise).
s32 func_00110c90(O110c90* o)
{
    Pts110c90* w = &D_003a9040;
    if (D_003a9040.count < 0) return -1;
    if (0.0f < o->f3292) return -1;
    if (__builtin_expect(!!(o->f3288 < 40), 1)) return -1;
    Box110c90 box = o->getBox();
    if (func_00146730(D_003a9250, &box)) return -1;
    V110c90 p = *f110c90_attach(o);
    Box110c90 b;
    register Box110c90* pb asm("$23") = &b;
    s32 best = -1;
    V110c90 d;
    if (o->flags & 0x8000) {
        V110c90 q = *f110c90_attach(D_00341708);
        f32 bestDist = 0.0f;
        for (s32 i = 0; i < 32; i++) {
            d = w->pts[i] - p;
            b = box;
            b.lx += d.x;
            b.ly += d.y;
            b.lz += d.z;
            b.hx += d.x;
            b.hy += d.y;
            b.hz += d.z;
            s32 ok = func_00110b00(o, &w->pts[i], pb);
            if (__builtin_expect(ok, 1)) {
                f32 dist = (w->pts[i] - q).lengthSq();
                if (best == -1 || dist < bestDist) {
                    bestDist = dist;
                    best = i;
                }
            }
        }
    } else {
        s32 idx = o->f3296;
        register s32 four asm("$4") = 4;
        V110c90* pts;
        // pts = w->pts, built by hand after the li a0,4 (as in the original schedule)
        asm volatile("addiu %0,%1,16" : "=r"(pts) : "r"(w));
        s32 n = 0;
        asm("" : "+r"(idx) : "r"(n), "r"(pts), "r"(four));
        idx += 28;
        idx += f110c90_rand(four);
        // barrier keeps the sp+96 setup after the call; two asms delay the &31 after the &d setup
        asm volatile(""); asm("" : "+r"(idx)); asm("" : "+r"(idx));
        idx &= 31;
        for (; n < 11; n++) {
            d = *(V110c90*)((idx << 4) + (u32)pts) - p;
            b = box;
            b.lx += d.x;
            b.ly += d.y;
            b.lz += d.z;
            b.hx += d.x;
            b.hy += d.y;
            b.hz += d.z;
            if (func_00110b00(o, &*(V110c90*)((idx << 4) + (u32)pts), pb)) {
                best = idx;
                break;
            }
            idx += 3;
            if (idx >= 32) idx -= 32;
        }
    }
    return best;
}
}
extern "C" {
void func_00138c68(u8*, s32, s32);
void func_001395f8(u8*);
void func_00139620(u8*);
u8* func_00276348(void);
u8* func_002766d0(void);
void func_00276e78(void);
s32 func_00287bc0(void);
void func_0028d8c0(u8*, s32, s32, s32, s32, s32, s32, s32);
void func_0028d980(u8*, s32, s32, s32, s32, s32, s32, s32, s32);
void func_0028dcc0(u8*, u8*);
void func_0028f4d8(s32, s32, s32);
s32 func_0028f930(s32);
void func_002a17e8(void);
void func_002a18d0(s32, s32);
u8* func_002a1bc0(u16);
void func_002a1cd8(void);
void func_002a1f40(void);
s32 func_002a9e98(u16);
s32 func_002a9f50(u16);
extern s32 D_0035f148;
extern s32 D_0035f14c;
extern s32 D_0035f210;
extern s32 D_0035f3d4;
union U5d4 { u8* p; s16 h; u8 c; };
union U5d8 { u8* p; s32 i; };
extern U5d4 D_0035f5d4;
extern U5d8 D_0035f5d8;
extern s32 D_00374b4c;
extern s32 D_00374b50;
extern s32 D_00374b54;
extern s32 D_00374b58;
extern s16 D_00374b70[];

struct It8 { u16 id; s16 x; s16 y; s16 pad; };
struct Sel5d4 { s8 n; u8 sel; s8 kind; u8 pad[77]; It8 it[1]; };
// Builds the selection menu items. Register pins: loop index i in s7, the loop-end
// count pointer/value in t5/t7 and the 408 stride constant in a1 (gcc swaps s6/s7 otherwise).
void func_002a0908(s32 sel)
{
    u8* w = func_00276348();
    u8* base = func_002766d0();
    func_002a18d0(func_00287bc0() != 6, -1);
    func_002a1cd8();
    if (!func_0028f930(0)) func_0028f4d8(0, -1, 0);
    s32 z = D_0035f3d4;
    s32 zm = z - 1;
    D_0035f5d4.p[1] = sel;
    if (sel < 0) {
        *(s16*)(D_0035f5d4.p + 68) = 0;
        *(s16*)(D_0035f5d4.p + 70) = 0;
    }
    func_00276e78();
    func_0028d8c0(base, zm, D_0035f14c, D_0035f148, D_0035f210, 83, -1, 0);
    register s32 i asm("$23") = 0;
    func_00139620(base);
    func_0028dcc0(base, w);
    func_0028d8c0(D_0035f5d8.p, z, D_0035f14c, D_0035f148, D_0035f210, 84, -1, 0);
    *(s16*)(D_0035f5d4.p + 72) = -999;
    *(s16*)(D_0035f5d4.p + 76) = -999;
    *(s16*)(D_0035f5d4.p + 74) = -999;
    *(s16*)(D_0035f5d4.p + 78) = -999;
    func_0028d980(D_0035f5d8.p + 1224, z, D_0035f14c, D_0035f148, D_0035f210, 85, -1, -1, 0);
    func_0028dcc0(D_0035f5d8.p + 1224, w);
    func_00139620(D_0035f5d8.p + 1224);
    *(s32*)(D_0035f5d8.p + 1656) = 2;
    *(s32*)(D_0035f5d8.p + 1652) = 3;
    *(u32*)(D_0035f5d8.p + 1644) = 0x60000008;
    func_001395f8(D_0035f5d8.p + 1224);
    s32 y = D_0035f3d4;
    zm = y + 2;
    s32 flag = ((s8*)D_0035f5d4.p)[2] == 16;
    if (((s8*)D_0035f5d4.p)[0] > 0) {
        s32 f6 = flag * 6;
        s32 z6 = y + 6;
        u8* q = base;
        register s8* np asm("$13"); register s32 nn asm("$15");
        do {
            u8* o1 = q + 4248;
            u8* it = func_002a1bc0(((Sel5d4*)D_0035f5d4.p)->it[i].id);
            s32 c = D_00374b70[f6 + (s8)it[2]];
            func_0028d8c0(o1, zm, D_0035f14c, D_0035f148, D_0035f210, c, -1, 0);
            c = 2;
            func_0028dcc0(o1, base);
            func_00138c68(o1, ((Sel5d4*)D_0035f5d4.p)->it[i].x, ((Sel5d4*)D_0035f5d4.p)->it[i].y);
            u8* o2 = q + 0xa998;
            u16 id = ((Sel5d4*)D_0035f5d4.p)->it[i].id;
            if (func_002a9e98(id)) {
                if (func_002a9f50(id)) {
                    if (flag) c = D_00374b58; else c = D_00374b50;
                } else {
                    if (flag) c = D_00374b54; else c = D_00374b4c;
                }
            }
            q += 408;
            func_0028d8c0(o2, z6, D_0035f14c, D_0035f148, D_0035f210, c, -1, 0);
            { register s32 m asm("$5") = 408; m = i * m; i++; func_0028dcc0(o2, base + m + 4248); }
            { u8* s = o2 + 24; *(s32*)(s + 184) |= 8; }
            np = (s8*)D_0035f5d4.p; nn = np[0];
        } while (i < nn);
    }
    func_002a17e8();
    func_002a1f40();
}
}
