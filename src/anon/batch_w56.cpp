#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));

// Local type whose non-trivial destructor keeps gcc from emitting a sibling call.
struct NoTail { ~NoTail() {} };

extern "C" {

void wtarget_0014ce88(void) asm("_Z16wtarget_0014ce88jjjj");
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");

// 00132e28: look up an entry, flag the owner and hand the entry's data to 00132720
u8* func_00132c68(void*, u32);
s32 func_001325c8(void*, s32, u32);
void func_00132720(void*, u8*);
void func_00132e28(u8* a, u32 b)
{
    u8* h = func_00132c68(a, b);
    if (h) {
        s32 i = func_001325c8(a, 0xffff, b);
        if (i >= 0) {
            u8* t = h + *(u32*)(h + *(u32*)(h + 28) + i * 4);
            *(u32*)(a + 20) |= 4;
            func_00132720(a, t);
        }
    }
}

// 00133938: write a 16-byte packet header at the cursor and advance the cursor
struct PktHdr { u16 id; u8 b2; u8 b3; PktHdr* next; PktHdr* p8; PktHdr* p12; };
PktHdr* wtarget_00133938(PktHdr** pp, PktHdr* next, u32 id, u32 a3, u32 a4) asm("_Z16wtarget_00133938jjjj");
PktHdr* wtarget_00133938(PktHdr** pp, PktHdr* next, u32 id, u32 a3, u32 a4)
{
    (*pp)->b2 = 0;
    (*pp)->p8 = (PktHdr*)a3;
    (*pp)->p12 = (PktHdr*)a4;
    (*pp)->b3 = 32;
    (*pp)->next = next;
    *(u16*)*pp = id;
    asm volatile("" ::: "memory");
    PktHdr* r = *pp;
    *pp = next;
    return r + 1;
}

// 00143ae0
extern void* D_00348804;
void func_00141c18(void*, u32, u32, u32, u32);
void func_00141ff0(void*, u32, u32, u32, u32);
void func_00143ae0(u32 a, u32 b, u32 c, u32 d)
{
    NoTail g;
    func_00141c18(D_00348804, 0, 0, 0, 0);
    func_00141ff0(D_00348804, a, b, c, d);
}

// 0014ce88: count frames then derive a scaled time step and its reciprocal
extern s32 D_00349e1c;
extern f32 D_00349e10;
extern f32 D_00349e0c;
extern f32 D_00349e14;
extern f32 D_00349e18;
void wtarget_0014ce88(void)
{
    D_00349e10 = 0.0f;
    for (s32 i = 0; i < D_00349e1c + 1; i++) D_00349e10 += 1.0f;
    f32 s = D_00349e10;
    D_00349e14 = s;
    D_00349e10 = s * D_00349e0c;
    D_00349e18 = 1.0f / D_00349e10;
}

// 00153840: mark every slot, then process each bit set in a 64-bit mask
extern s32 D_0034a77c;
extern u8* D_0034a790;
void func_00153948(u8);
void func_00153840(u64 mask)
{
    s32 n = D_0034a77c;
    for (s32 i = 0; i < n; i++) D_0034a790[i * 64 + 48] = 1;
    for (s32 i = 0; i < 64; i++) {
        u64 bit = 1ULL << i;
        if (mask & bit) func_00153948(i);
    }
}

// 0015c068
s32 func_001665d8(void*, f32*, f32*, f32*, f32*, f32*, f32*);
void func_0015c068(u8* p, void* a)
{
    u32 n = func_001665d8(a, (f32*)(p + 3000), (f32*)(p + 3004), (f32*)(p + 3016), (f32*)(p + 3020), (f32*)(p + 3008), (f32*)(p + 3012));
    *(f32*)(p + 2996) = (f32)n * 100.0f * 0.001953125f;
}

// 0016be98: returns a 128-bit value by hidden pointer
struct L16be98 { u32 a, b, c, d; u128 v; };
void* func_0016bc20(u8*, s32, s32);
void func_0018a818(void*, u8*, void*);
u128* func_0016be98(u128* out, u8* a)
{
    L16be98 l;
    u128* src = &l.v;
    l.d = 0;
    void* r = func_0016bc20(a, 1, -1);
    if (r) {
        func_0018a818(&l, a, r);
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(out), "r"(src) : "$8", "memory");
    } else {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(out), "r"(a + 1344) : "$8", "memory");
    }
    return out;
}

// 0016e000
void* func_0014aba8(void);
void func_0014aa58(void*, s32, s32);
void func_0016e000(f32* a)
{
    s32 v = (s32)(*a * 0.5f);
    func_0014aa58(func_0014aba8(), v, 0);
}

// 0017cb78
void func_0017f488(u8*, s32, f32, f32);
void func_00180c88(u8*, s32, f32);
void func_0017cb78(void* unused, u8* p)
{
    s32 s = *(s32*)(p + 256);
    if (s == 4) func_0017f488(p + 320, 4, 8.0f, 0.0f);
    else if (s >= 0) func_00180c88(p + 320, s, 8.0f);
    *(u32*)(p + 268) &= ~1;
}

// 001884d0
union U188 { u16 h; u32 w; };
extern u32 D_01c60be0[];
u8* func_00187ab8(void*, u32);
void func_00188398(u8*, u16, u32*, s32);
void func_001884d0(u8* a, u32* b)
{
    void* q = *(void**)(a + 140);
    if (!q) return;
    u8* r = func_00187ab8(q, b[0]);
    if (!r) return;
    D_01c60be0[0] = *(u32*)(a + 136);
    D_01c60be0[1] = b[1];
    func_00188398(a, ((U188*)(r + 20))->h, D_01c60be0, 2);
}

// 00196e00
struct Fl196 { u16 h0; u16 b0 : 1; u16 b1 : 4; u16 b5 : 1; };
inline u8 fl196_b5(Fl196* f) { return f->b5; }
inline u8 fl196_b0(Fl196* f) { return f->b0; }
struct O196 { u8 pad[60]; Fl196* fl; };
void func_00226da8(O196*);
void func_0014c9f0(s32);
void func_001c11a8(s32);
void func_001384a0(s32);
void func_002bc798(void);
void func_002ba610(void);
extern u32 D_0035037c;
void func_00196e00(O196* a)
{
    func_00226da8(a);
    func_0014c9f0(4);
    func_001c11a8(12);
    func_001384a0(1);
    if (!fl196_b5(a->fl)) func_002bc798();
    if (fl196_b0(a->fl)) func_002ba610();
    D_0035037c = 0;
}

// 0019ecb0: start the blur effect
void func_0014a7e8(s32);
void func_0014a768(u8);
void func_0014a788(u16, u16);
void func_0014a7b8(f32, u32);
void func_0014a7f8(s32);
void func_001ad990(u8*, f32, f32, f32);
struct BlurState { u32 started : 1; u32 rest : 31; void* on; u8 b8; u8 p9[3]; u16 x; u16 p0e; u16 y; u16 p12; f32 f20; u32 i24; u8 tail[4]; };
void blur_start(BlurState* self, f32 t) asm("_ZN2YS4BLUR5startEf");
void blur_start(BlurState* self, f32 t)
{
    self->started = 1;
    func_0014a7e8(self->on != 0);
    func_0014a768(self->b8);
    func_0014a788(self->x + 256, self->y + 208);
    func_0014a7b8(self->f20, self->i24);
    func_0014a7f8(1);
    func_001ad990((u8*)self + 28, 0.0f, 1.0f, t);
}

// 001a60c8
struct S1a6 { u8 pad[40]; u32 v; };
extern S1a6 D_00350800[];
u32 func_001a6658(s32);
void func_001bdff0(void);
void func_001a60c8(void)
{
    for (s32 i = 0; i < 6; i++) D_00350800[i].v = func_001a6658(i);
    func_001bdff0();
}

// 001aa8f0
void func_001ab260(u32, u8*, u32, u32, u32, u32, u32, f32, f32);
void func_001aa8f0(u8* p, u32 a1, u32 a2, u32 a3, u32 a4)
{
    NoTail g;
    func_001ab260(*(u32*)p, p + 64, a1, a2, a3, a4, *(u32*)(p + 56), *(f32*)(p + 36), *(f32*)(p + 40));
}

// 001ae010: does the file name's extension match one of two known extensions?
struct P1ae { const char* a[2]; };
extern P1ae D_0036d850;
char* func_002ff8b0(const char*, s32);
s32 func_002ff1a4(const char*, const char*);
s32 func_001ae010(const char* s)
{
    P1ae t = D_0036d850;
    char* e = func_002ff8b0(s, '.');
    if (e) {
        e++;
        for (s32 i = 0; i < 2; i++)
            if (func_002ff1a4(e, t.a[i]) == 0) return 1;
    }
    return 0;
}

// 001b2520: push a 128-bit value into a ring buffer
struct Ring { s32 cap; s32 count; s32 head; u32 pad[2]; u128* buf; };
void func_001b2520(Ring* r, u128* v)
{
    u128* d = r->buf + r->head;
    if (d != v) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(v) : "$8", "memory");
    s32 n = r->head + 1;
    r->count = n < r->count ? r->count : n;
    r->head = n % r->cap;
}

// 001b3330: clear bit 1 on every occluder entry
struct OccS;
struct OccH;
union OccF { u32 v; s32 i; OccS* s; OccH* h; };
struct OccE { u8 pad[8]; OccF fl; };
struct OccS { u8 pad[128]; OccE* e; u8 pad2[12]; };
struct OccH { u32 x; s32 n; };
struct OccSet { OccH* h; OccS* s; };
void occ_enable_all(OccSet* self) asm("_ZN2YS6OBJOCC10enable_allEv");
void occ_enable_all(OccSet* self)
{
    if (!self->h) return;
    for (s32 i = 0; i < self->h->n; i++) self->s[i].e->fl.v &= ~2;
}

// 001bce00
void func_001bc720(u8*);
void func_001bc730(u8*, s32);
struct E1bc { u16 a; u16 id; u32 x[2]; };
void func_001bce00(u8* p)
{
    s32 cur = *(s32*)(p + 108);
    s32 n;
    if (cur < 0 || cur >= (n = *(s32*)(p + 8))) { func_001bc720(p); return; }
    u32 id = *(u32*)(p + 112);
    E1bc* e = (E1bc*)(p + 12);
    if (e[cur].id == id) return;
    s32 i;
    for (i = 0; i < n; i++)
        if (e[i].id == id) { func_001bc730(p, i); return; }
    func_001bc730(p, *(s32*)(p + 108));
}

// 001c0298
inline bool is_kind_5_or_6(u8 v) { return (u8)(v - 5) < 2; }
s32 func_001c0298(u8* a, u8* b)
{
    if (is_kind_5_or_6(*(*(u8**)(b + 40) + 4))) return 1;
    u32 k = *(u32*)(b + 28);
    u32* bits = (u32*)(a + 4);
    if (bits[k >> 5] & (1 << (k & 31))) return 0;
    s32 c = *(s32*)(b + 32);
    if (c == *(s32*)(a + 36) || c == 255) return 1;
    if (0.0f < *(f32*)(a + 44)) return 0;
    return 1;
}

// 001d5198
struct T1d5 { u8 key; u8 val; u16 arg; };
extern T1d5 D_0036e538[];
u32* func_001ba158(u8*);
void func_00181178(u16);
void func_001d5198(u8* p)
{
    if (p[0] != 16) return;
    u32* r = func_001ba158(p);
    for (u32 i = 0; i < 4; i++) {
        if (D_0036e538[i].key == p[1]) { *r = D_0036e538[i].val; func_00181178(D_0036e538[i].arg); return; }
    }
}

// 001d77a0
s32 func_001a6d08(s32);
u8* func_00189200(void*, s32);
void func_001a6c90(s32);
extern u8 D_0032e020[];
void u_call0_001d77a0(void) asm("_Z16u_call0_001d77a0v");
void u_call0_001d77a0(void)
{
    if (func_001a6d08(106)) return;
    if (!func_001a6d08(101)) return;
    for (s32 i = 1; i < 5; i++) {
        if (func_00189200(D_0032e020, i)[2] < 5) return;
    }
    func_001a6c90(106);
}

// 001ef1a0: VU0 random number(s)
static inline f32 vu0_rand(void)
{
    f32 x;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\t"
        "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
        "vitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1" : "=r"(x) : : "$8");
    return x;
}
f32 func_001ef1a0(u8 a)
{
    f32 x = vu0_rand();
    if (a) return x + vu0_rand();
    return x + x;
}

// 00203ae8
s32 func_00203ae8(u8* a, u8* b)
{
    if (!*(u32*)(a + 80)) return 0;
    u8 t = b[204];
    if (t == 1 || t == 3 || t == 2) { if (!*(u32*)(a + 84)) return 0; }
    if (b[201] && !*(u32*)(a + 88)) return 0;
    return 1;
}

// 00226dc8
extern s32 D_0035db10;
extern u8 D_0035de27;
void func_00226d88(void);
void func_00232988(void);
void func_002bc518(void);
s32 func_00228378(void);
void func_0023d230(s32);
u32 func_002282d8(void);
void func_00102c48(s32, u32, void*, s32);
void func_00226ce8(s32);
void func_00226dc8(void)
{
    if (D_0035db10 == 4) return;
    D_0035db10 = 4;
    func_00226d88();
    func_00232988();
    func_002bc518();
    if (func_00228378()) {
        func_0023d230(0);
        func_00102c48(1, func_002282d8(), (void*)func_00226ce8, 4096);
    } else {
        D_0035de27 = 1;
        func_00226ce8(0);
    }
}

// 002530f0
struct Fn253 { u8 pad[8]; void (*fn)(void); };
Fn253* func_00253330(s32);
extern s32 D_0035eeb4;
extern s32 D_0035f3d4;
extern s16 D_01dae6a8[];
void func_00258dc8(void);
void func_0028ca78(void);
void func_00287a28(void);
void func_0028d068(s32, s32);
void func_00242790(void);
void func_0023d368(void);
void func_002530f0(s32 a)
{
    func_00253330(a)->fn();
    D_0035eeb4 = -1;
    func_00258dc8();
    func_0028ca78();
    func_00287a28();
    D_0035f3d4 = D_01dae6a8[0];
    s32 v = D_01dae6a8[1];
    if (v >= 0) func_0028d068(v, -1);
    if (a != 9) func_00242790();
    func_0023d368();
}

// 002656c0
u8* func_00257770(void);
void func_0028acc8(u32);
extern u32 D_0035f01c;
void func_002656c0(void)
{
    NoTail g;
    u8* p = func_00257770();
    if (u_call4_00139d78(p)) return;
    for (s32 i = 0; i < 20; i++) {
        if (u_call4_00139d78(p + 13840)) return;
        if (u_call4_00139d78(p + 24304)) return;
        p += 436;
    }
    func_0028acc8(D_0035f01c);
}

// 0027af58: pick the bucket a value falls into from a table of 4 weights
s32 func_00287bc0(void);
s32 func_0028b040(u32);
s32 func_002570a0(s32);
extern s8* D_0035f230;
s32 func_0027af58(void)
{
    s32 v = func_00287bc0();
    if (v == 16) v = func_0028b040(D_0035f01c);
    else v = func_002570a0(16);
    s32 sum = 0, r = -1;
    for (s32 i = 0; i < 4; i++) {
        sum += D_0035f230[i + 8];
        if (v < sum) { r = i; break; }
    }
    return r;
}

// 002ac268: set bit k in a per-index bit array (only if not already set)
u8* func_002a9d68(s32, u32);
u32 func_002abf40(s32, u32);
void func_002ac268(s32 a, u32 b)
{
    u8* p = func_002a9d68(a, b);
    u32 k = func_002abf40(a, b);
    u32* w = (u32*)(p + a * 4 + 172);
    u32 m = 1 << (k & 31);
    u32 v = w[k >> 5];
    if (!(v & m)) w[k >> 5] = v | m;
}

// 002c85c8
s32 func_002c5150(u32);
void func_002c8490(u8*);
void* func_001050d8(u32);
void func_002c77b8(void*, u32);
extern u8* D_00361dd8;
void func_002c85c8(u32 a)
{
    if (func_002c5150(a)) return;
    u8* p = D_00361dd8;
    if (p) {
        if (*(u32*)(p + 192) == a) return;
        func_002c8490(p);
        D_00361dd8 = 0;
    }
    func_002c77b8(func_001050d8(5944), a);
}

// 002d3128
u8* func_002d1878(u32);
extern u32 D_00361f60;
void func_002d3128(u8* p, s32 n)
{
    f32 s = *(f32*)(func_002d1878(D_00361f60) + 80);
    for (s32 i = 0; i < 64 && n > 0; i++) {
        f32* a = (f32*)(p + 2944) + i;
        if (a[1] < 0.0f) { n--; a[1] = s * (f32)n; }
    }
}

// 003015a8: vsprintf-style formatting into a string through a fake FILE
struct StrFile { u8* p; s32 r; s32 w; s16 flags; s16 file; u8* base; s32 size; u8 pad[60]; void* data; u8 pad2[8]; };
s32 func_002ffd78(void*, StrFile*, const char*, void*);
s32 func_003015a8(void* ptr, u8* str, const char* fmt, void* ap)
{
    StrFile f;
    f.flags = 520;
    f.base = f.p = str;
    f.size = f.w = 0x7fffffff;
    f.data = ptr;
    s32 r = func_002ffd78(ptr, &f, fmt, ap);
    *f.p = 0;
    return r;
}

// 00313f40: soft-double helper (unpack both operands, combine, pack)
struct FpNum { s32 cls; s32 sign; s32 exp; s32 pad; u64 frac; u8 pad2[8]; };
void func_003147a0(const u64* src, FpNum* dst);
void* func_00313f98(FpNum*, FpNum*, FpNum*);
u64 func_003146c8(void*);
u64 func_00313f40(u64 a, u64 b)
{
    FpNum x, y, z;
    func_003147a0(&a, &x);
    func_003147a0(&b, &y);
    return func_003146c8(func_00313f98(&x, &y, &z));
}

// 0031a3d8 / 0031c248: destructor bodies (vtable resets, member and base teardown)
extern u8 D_00347dd0[];
extern u8 D_00347e60[];
extern u8 D_00347f98[];
extern u8 D_00347e80[];
extern u8 D_0034a568[];
void func_00239870(void*);
void func_002361d0(void*);
void func_0031a840(void*);
void func_0031a3d8(u8* p)
{
    NoTail g;
    *(void**)p = D_00347dd0;
    *(void**)(p + 896) = D_00347e60;
    func_00239870(p + 920);
    *(void**)(p + 896) = D_00347f98;
    *(void**)(p + 448) = D_00347e80;
    func_002361d0(p + 480);
    *(void**)(p + 448) = D_00347f98;
    *(void**)p = D_00347e60;
    func_00239870(p + 24);
    func_0031a840(p);
}
void func_0031c248(u8* p)
{
    *(void**)p = D_0034a568;
    *(void**)(p + 560) = D_00347e60;
    func_00239870(p + 584);
    u8* b = p + 48;
    *(void**)(p + 560) = D_00347f98;
    *(void**)b = D_00347e60;
    func_00239870(p + 72);
    func_0031a840(b);
    *(void**)p = D_00347f98;
}

}
