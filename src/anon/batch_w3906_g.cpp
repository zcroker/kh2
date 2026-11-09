// 00193038: per-frame colour/shadow update of a model object (built with -g).
// Partial asm: the tint*color multiply and the outColor copy; the original
// interleaves their loads, mults and stores in a way the C forms did not reproduce.
#include "../common/types.h"
extern "C" {
struct Rgba193038 {
    u8 r, g, b, a;
    Rgba193038 operator*(Rgba193038 t) const
    {
        /* (this * t) >> 7 per channel; asm keeps the original load/mult interleave */
        Rgba193038 c;
        asm("lbu $13,%4\n\t"
            "la $14,%4\n\t"
            "lbu $15,%5\n\t"
            "lbu $12,1($14)\n\t"
            "mult $13,$13,$15\n\t"
            "lbu $10,3($14)\n\t"
            "lbu $11,2($14)\n\t"
            "lbu $14,%7\n\t"
            "lbu $15,%6\n\t"
            "sra $13,$13,7\n\t"
            "mult $11,$11,$14\n\t"
            "sb $13,%0\n\t"
            "mult $12,$12,$15\n\t"
            "sra $11,$11,7\n\t"
            "lbu $15,%8\n\t"
            "sra $12,$12,7\n\t"
            "sb $12,%1\n\t"
            "mult $10,$10,$15\n\t"
            "sb $11,%2\n\t"
            "sra $10,$10,7\n\t"
            "sb $10,%3"
            : "=m"(c.r), "=m"(c.g), "=m"(c.b), "=m"(c.a)
            : "m"(r), "m"(t.r), "m"(t.g), "m"(t.b), "m"(t.a)
            : "$10", "$11", "$12", "$13", "$14", "$15");
        return c;
    }
};
struct Def193038 { u8 pad[72]; u16 flags; };
struct O193038 {
    u8 pad0[8];
    Def193038* def;
    u8 pad1[940 - 12];
    Rgba193038 color;
    u8 pad2[1348 - 944];
    f32 f1348;
    u8 pad3[1416 - 1352];
    u32 f1416;
    u8 pad4[1536 - 1420];
    u64 f1536;
    bool castsShadow() { return ((f1536 >> 33) & 1) == 0; }
    u8 pad5[1656 - 1544];
    u32 f1656;
    u8 pad6[1667 - 1660];
    u8 b1667;
    u8 pad7[1700 - 1668];
    s32 f1700;
    u8 pad8[1880 - 1704];
    Rgba193038 outColor;
    u8 pad9[1896 - 1884];
    u32 f1896;
    u8 pad10[1908 - 1900];
    f32 fadeDist;
    u8 pad11[4];
    u8 shadow;
    u8 pad12[2236 - 1917];
    Rgba193038 tint;
    f32 f2240;
    u8 pad13[2472 - 2244];
    f32 f2472;
};
void func_00193330(O193038*);
f32 func_00194690(O193038*);
void func_0016a070(O193038*);
s32 func_0019bad8(O193038*);
f32 func_00184a90(O193038*);
s32 func_001bfda0(void*, Rgba193038*);
s32 func_001943e8(O193038*);
s32 func_0019c5d0(O193038*);
s32 func_0019c650(O193038*);
s32 func_001c0cd8(O193038*);
void func_00143398(void*);
void func_00193038(O193038* o)
{
    func_00193330(o);
    u8 work[112] __attribute__((aligned(16)));
    Rgba193038 c __attribute__((aligned(16)));
    if ((o->def->flags & 4) || (o->f1416 & 0x20000000)) {
        c = o->color;
        c.a = (o->color.a * o->tint.a) >> 7;
    } else {
        c = o->color * o->tint;
    }
    f32 k = func_00194690(o);
    {
        /* outColor = c with alpha color.a * k; asm keeps the original interleave */
        register s32 a asm("$15");
        register O193038* arg asm("$4");
        asm("lbu $15,%6\n\t"
            "lbu $13,%8\n\t"
            "move $4,%5\n\t"
            "lbu $14,%9\n\t"
            "mtc1 $15,$f0\n\t"
            "cvt.s.w $f0,$f0\n\t"
            "lbu $15,%7\n\t"
            "sb $15,%0\n\t"
            "sb $13,%1\n\t"
            "mul.s $f0,$f0,%10\n\t"
            "sb $14,%2\n\t"
            "cvt.w.s $f1,$f0\n\t"
            "mfc1 $15,$f1"
            : "=m"(o->outColor.r), "=m"(o->outColor.g), "=m"(o->outColor.b), "=r"(a), "=r"(arg)
            : "r"(o), "m"(o->color.a), "m"(c.r), "m"(c.g), "m"(c.b), "f"(k)
            : "$13", "$14", "$f0", "$f1");
        o->outColor.a = a;
        func_0016a070(arg);
    }
    if (func_0019bad8(o)) {
        o->shadow = 0;
        if (o->castsShadow()) {
            f32 d = func_00184a90(o) - o->f1348;
            if (d < o->fadeDist) o->shadow = (s32)(o->f2472 * (c.a * 0.0078125f) * k * (1.0f - d / o->fadeDist));
        }
    } else {
        o->shadow = (s32)(o->f2472 * (c.a * 0.0078125f) * k);
    }
    if (o->f2240 < 1.0f) {
        o->f1656 |= 2;
        o->b1667 = (s32)(o->f2240 * 256.0f);
    } else {
        o->f1656 &= ~2;
    }
    o->f1700 = func_001bfda0((u8*)o + 2272, &o->outColor);
    if (func_001943e8(o)) o->f1656 |= 8;
    else o->f1656 &= ~8;
    if (func_0019c5d0(o)) o->f1896 &= ~4;
    else o->f1896 |= 4;
    if (func_0019c650(o)) o->f1896 &= ~8;
    else o->f1896 |= 8;
    if (!func_001c0cd8(o)) func_00143398((u8*)o + 1648);
}
}
