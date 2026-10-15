#include "../common/types.h"

// 0031a850: assignment operator of a 0x158-byte object (base part via its own operator=,
// then the derived members). The 13 words at 0xb8 are copied through raw word pointers,
// which keeps their loads/stores in order (the two fields on each side are not).
struct Obj31a850Base {
    u8 base[0xb0];
};
struct Obj31a850 : Obj31a850Base {
    s32 mb0;
    s32 mb4;
    s32 work[13];
    s32 mec;
    s32 mf0;
    s32 mf4;
    s32 mf8;
    s32 mfc;
    f32 m100;
    f32 m104;
    f32 m108;
    s32 m10c;
    s32 m110;
    s32 m114;
    f32 m118;
    f32 m11c;
    f32 m120;
    f32 m124;
    f32 m128;
    f32 m12c;
    f32 m130;
    f32 m134;
    f32 m138;
    f32 m13c;
    s32 m140;
    s32 m144;
    s32 m148;
    s32 m14c;
    s32 m150;
    s32 m154;
};

extern "C" {
void func_0031a9d8(Obj31a850*, Obj31a850*);

Obj31a850* func_0031a850(Obj31a850* d, Obj31a850* s) {
    func_0031a9d8(d, s);
    d->mb0 = s->mb0;
    d->mb4 = s->mb4;
    ((s32*)d)[0x2e] = ((s32*)s)[0x2e];
    ((s32*)d)[0x2f] = ((s32*)s)[0x2f];
    ((s32*)d)[0x30] = ((s32*)s)[0x30];
    ((s32*)d)[0x31] = ((s32*)s)[0x31];
    ((s32*)d)[0x32] = ((s32*)s)[0x32];
    ((s32*)d)[0x33] = ((s32*)s)[0x33];
    ((s32*)d)[0x34] = ((s32*)s)[0x34];
    ((s32*)d)[0x35] = ((s32*)s)[0x35];
    ((s32*)d)[0x36] = ((s32*)s)[0x36];
    ((s32*)d)[0x37] = ((s32*)s)[0x37];
    ((s32*)d)[0x38] = ((s32*)s)[0x38];
    ((s32*)d)[0x39] = ((s32*)s)[0x39];
    ((s32*)d)[0x3a] = ((s32*)s)[0x3a];
    d->mec = s->mec;
    d->mf0 = s->mf0;
    d->mf4 = s->mf4;
    d->mf8 = s->mf8;
    d->mfc = s->mfc;
    d->m100 = s->m100;
    d->m104 = s->m104;
    d->m108 = s->m108;
    d->m10c = s->m10c;
    d->m110 = s->m110;
    d->m114 = s->m114;
    d->m118 = s->m118;
    d->m11c = s->m11c;
    d->m120 = s->m120;
    d->m124 = s->m124;
    d->m128 = s->m128;
    d->m12c = s->m12c;
    d->m130 = s->m130;
    d->m134 = s->m134;
    d->m138 = s->m138;
    d->m13c = s->m13c;
    d->m140 = s->m140;
    d->m144 = s->m144;
    d->m148 = s->m148;
    d->m14c = s->m14c;
    d->m150 = s->m150;
    d->m154 = s->m154;
    return d;
}
}
