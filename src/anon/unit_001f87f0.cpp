// Linked unit 0x001f87f0-0x001f8dd0: ppp trail draw (plain variant). Walks the position ring of the trail work (owner + ofs[0] + 160)
// from the newest entry and draws one sprite per step along the path, fading the colour from the work colour to the parameter
// colour and the size from 1 to p->w1. The VU0 helpers are the original's inline VU0 code (fixed vf26-vf31 and v0); vcopy/vsub/vadd
// have no clobber list, as in the sibling unit 0x1f9010.
#include "../common/types.h"
namespace n001f87f0 {
struct V { f32 x, y, z, w; } __attribute__((aligned(16)));
struct M { V r[4]; } __attribute__((aligned(16)));
struct K8 { s16 f0; u16 f2; s8 f4; u8 f5; u16 f6; };
struct T1 { u8 p[6]; s16 f6; u8 p2[8]; K8 k[1]; };
struct Ent { T1* t; s32 f4; };
struct G4 { u8 p[20]; u8* f20; };
struct G8 { u8 p[16]; M m; };
struct Ring { u8 n; u8 cur; u16 f2; u16 f4; u16 f6; u8 pad[8]; V arr[1]; };
struct Prm { u8 p0[4]; s32 id; u8 p8[4]; s16 c1[4]; f32 w1; f32 len; u16 num; u8 world; u8 noadd; u8 f32_; };
struct Ctx { u8 p[12]; s32* ofs; };
struct Draw { u16 f0; u16 flags; u8 rgba[4]; u16 f8, fa, fc, fe; M* mtx; s32 f14; u8 f18; u8 p19[3]; s32 f1c; u8 pad[16]; };
extern G4* D_01d9e6e4 asm("D_01d9e6e4");
extern G8* D_01d9e6e8 asm("D_01d9e6e8");
extern M D_01d9e730 asm("D_01d9e730");
extern M D_01d9e840 asm("D_01d9e840");
extern M D_01d9e8c0 asm("D_01d9e8c0");
extern s32 D_01d9eaa4 asm("D_01d9eaa4");
extern f32 D_00354be0[] asm("D_00354be0");
void sceVu0SubVector(V*, V*, V*) asm("sceVu0SubVector");
void sceVu0DivVector(V*, V*, f32) asm("sceVu0DivVector");
void sceVu0CopyMatrix(M*, M*) asm("sceVu0CopyMatrix");
void sceVu0UnitMatrix(M*) asm("sceVu0UnitMatrix");
void sceVu0CopyVector(V*, V*) asm("sceVu0CopyVector");
f32 func_002229a0(V*) asm("func_002229a0");
s32 func_0021d048(u8*, Draw*, s32) asm("func_0021d048");

static inline void vftoi_rgba(u8* d, V* s) {
    asm volatile(".set noreorder\n\tlqc2 $vf31,0(%0)\n\tvftoi0.xyzw $vf31,$vf31\n\tqmfc2 $2,$vf31\n\tsb $2,0(%1)\n\t"
                 "mtsab $0,4\n\tqfsrv $2,$2,$2\n\tsb $2,1(%1)\n\tqfsrv $2,$2,$2\n\tsb $2,2(%1)\n\t"
                 "qfsrv $2,$2,$2\n\tsb $2,3(%1)\n\t.set reorder" : : "r"(s), "r"(d) : "$2", "memory");
}
static inline void vscale_xyz(V* d, V* s, f32 k) {
    asm volatile(".set noreorder\n\tlqc2 $vf31,0(%1)\n\tlqc2 $vf29,0(%0)\n\tmfc1 $2,%2\n\tqmtc2 $2,$vf30\n\t"
                 "vmulx.xyz $vf29,$vf31,$vf30x\n\tsqc2 $vf29,0(%0)\n\t.set reorder" : : "r"(d), "r"(s), "f"(k) : "$2", "memory");
}
static inline void vapply(V* d, M* m, V* v) {
    asm volatile(".set noreorder\n\tlqc2 $vf27,0(%1)\n\tlqc2 $vf28,16(%1)\n\tlqc2 $vf29,32(%1)\n\tlqc2 $vf30,48(%1)\n\t"
                 "lqc2 $vf31,0(%2)\n\tvmulax.xyzw ACC,$vf27,$vf31x\n\tvmadday.xyzw ACC,$vf28,$vf31y\n\t"
                 "vmaddaz.xyzw ACC,$vf29,$vf31z\n\tvmaddw.xyzw $vf27,$vf30,$vf31w\n\tsqc2 $vf27,0(%0)\n\t.set reorder"
                 : : "r"(d), "r"(m), "r"(v) : "memory");
}
static inline void vmulmat(M* d, M* a, M* b) {
    asm volatile(".set noreorder\n\tlqc2 $vf27,0(%1)\n\tlqc2 $vf28,16(%1)\n\tlqc2 $vf29,32(%1)\n\tlqc2 $vf30,48(%1)\n\t"
                 "lqc2 $vf31,0(%2)\n\tvmulax.xyzw ACC,$vf27,$vf31x\n\tvmadday.xyzw ACC,$vf28,$vf31y\n\t"
                 "vmaddaz.xyzw ACC,$vf29,$vf31z\n\tvmaddw.xyzw $vf26,$vf30,$vf31w\n\tsqc2 $vf26,0(%0)\n\t"
                 "lqc2 $vf31,16(%2)\n\tvmulax.xyzw ACC,$vf27,$vf31x\n\tvmadday.xyzw ACC,$vf28,$vf31y\n\t"
                 "vmaddaz.xyzw ACC,$vf29,$vf31z\n\tvmaddw.xyzw $vf26,$vf30,$vf31w\n\tsqc2 $vf26,16(%0)\n\t"
                 "lqc2 $vf31,32(%2)\n\tvmulax.xyzw ACC,$vf27,$vf31x\n\tvmadday.xyzw ACC,$vf28,$vf31y\n\t"
                 "vmaddaz.xyzw ACC,$vf29,$vf31z\n\tvmaddw.xyzw $vf26,$vf30,$vf31w\n\tsqc2 $vf26,32(%0)\n\t"
                 "lqc2 $vf31,48(%2)\n\tvmulax.xyzw ACC,$vf27,$vf31x\n\tvmadday.xyzw ACC,$vf28,$vf31y\n\t"
                 "vmaddaz.xyzw ACC,$vf29,$vf31z\n\tvmaddw.xyzw $vf26,$vf30,$vf31w\n\tsqc2 $vf26,48(%0)\n\t.set reorder"
                 : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline void vcopy(V* d, V* s) {
    asm volatile(".set noreorder\n\tlqc2 $vf31,0(%1)\n\tsqc2 $vf31,0(%0)\n\t.set reorder" : : "r"(d), "r"(s));
}
static inline void vsub(V* d, V* a, V* b) {
    asm volatile(".set noreorder\n\tlqc2 $vf31,0(%1)\n\tlqc2 $vf30,0(%2)\n\tvsub.xyzw $vf31,$vf31,$vf30\n\tsqc2 $vf31,0(%0)\n\t.set reorder"
                 : : "r"(d), "r"(a), "r"(b));
}
static inline void vadd(V* d, V* a, V* b) {
    asm volatile(".set noreorder\n\tlqc2 $vf31,0(%1)\n\tlqc2 $vf30,0(%2)\n\tvadd.xyzw $vf31,$vf31,$vf30\n\tsqc2 $vf31,0(%0)\n\t.set reorder"
                 : : "r"(d), "r"(a), "r"(b));
}
static inline void vscale(V* d, V* s, f32 k) {
    asm volatile(".set noreorder\n\tlqc2 $vf31,0(%1)\n\tmfc1 $2,%2\n\tqmtc2 $2,$vf30\n\tvmulx.xyzw $vf31,$vf31,$vf30x\n\t"
                 "sqc2 $vf31,0(%0)\n\t.set reorder" : : "r"(d), "r"(s), "f"(k) : "$2", "memory");
}
static inline f32 vlength(V* v) {
    f32 r;
    asm volatile(".set noreorder\n\tlqc2 $vf31,0(%1)\n\tvmul.xyz $vf31,$vf31,$vf31\n\tvaddy.x $vf31,$vf31,$vf31y\n\t"
                 "vaddz.x $vf31,$vf31,$vf31z\n\tvsqrt Q,$vf31x\n\tvwaitq\n\tvaddq.x $vf31,$vf0,Q\n\tqmfc2 $2,$vf31\n\t"
                 "mtc1 $2,%0\n\t.set reorder" : "=f"(r) : "r"(v) : "$2", "memory");
    return r;
}

void func_001f87f0(u8* o, Prm* p, Ctx* c) asm("func_001f87f0");
void func_001f87f0(u8* o, Prm* p, Ctx* c)
{
    M mc;
    M mw;
    V pos;
    V a;
    V d;
    V b;
    V col;
    V step;
    Draw dr;
    f32 w, dw, len, dl, seg, at, sum;
    Ring* r;
    V* arr;
    u8* spr;
    Ent* e;
    s32 last, i;
    s32 start;
    s32 cnt;
    M* pm;
    u8* cb;
    if (p->id == 0xffff) return;
    pm = &mw;
    cb = o + c->ofs[1] + 160;
    col.x = cb[8]; col.y = cb[9]; col.z = cb[10]; col.w = cb[11];
    { s16* q = p->c1; pos.x = q[0] >> 7; pos.y = q[1] >> 7; pos.z = q[2] >> 7; pos.w = q[3] >> 7; }
    cnt = p->num - 1;
    seg = cnt;
    sceVu0SubVector(&a, &col, &pos);
    sceVu0DivVector(&step, &a, seg);
    e = (Ent*)(D_01d9e6e4->f20 + p->id * 8);
    r = (Ring*)(o + c->ofs[0] + 160);
    *(s32*)&dr.f8 = 0;
    dr.f18 = 0;
    dr.mtx = pm;
    dr.f1c = 0;
    if (!p->noadd) dr.flags = 128; else dr.flags = 0;
    if (p->f32_ == 1) dr.flags |= 0x10;
    dr.fc = 0; dr.fe = 0;
    K8* kk = e->t->k; spr = (u8*)e->t + kk[r->f6].f0;
    sceVu0CopyMatrix(&mc, &D_01d9e6e8->m);
    vscale_xyz(&mc.r[0], &mc.r[0], D_00354be0[0]);
    vscale_xyz(&mc.r[1], &mc.r[1], D_00354be0[1]);
    
    sceVu0UnitMatrix(pm);
    w = 1.0f;
    dw = (w - p->w1) / seg;
    len = p->len;
    dl = len * dw;
    if (len == 0.0f) cnt = -1;
    arr = r->arr;
    last = r->n - 1;
    i = r->cur;
    start = i;
    
    sceVu0CopyVector(&pos, &arr[i]);
    sceVu0CopyVector(&a, &pos);
    if (i++ == last) i = 0;
    sceVu0CopyVector(&b, &arr[i]);
    sceVu0SubVector(&d, &b, &a);
    at = len;
    seg = func_002229a0(&d);
    sum = seg;
    for (;;) {
        vftoi_rgba(dr.rgba, &col);
        vscale_xyz(&pm->r[0], &mc.r[0], w);
        vscale_xyz(&mw.r[1], &mc.r[1], w);
        if (p->world) vapply(&mw.r[3], &D_01d9e730, &pos); else vapply(&mw.r[3], &D_01d9e840, &pos);
        vmulmat(pm, &D_01d9e8c0, pm);
        dr.f14 = D_01d9eaa4;
        D_01d9eaa4 = func_0021d048(spr, &dr, e->f4);
        if (cnt == 0) return;
        vsub(&col, &col, &step);
        len -= dl; w -= dw; if (len <= 0.0f) return;
        for (;;) {
            if (len <= sum) {
                vscale(&pos, &d, at / seg);
                vadd(&pos, &a, &pos);
                at += len;
                sum -= len;
                cnt--;
                break;
            }
            if (i++ == last) i = 0;
            if (i == start) return;
            vcopy(&a, &b);
            vcopy(&b, &arr[i]);
            vsub(&d, &b, &a);
            at -= seg;
            seg = vlength(&d);
            sum += seg;
        }
    }
}
void func_001f8da0(u8* o, Ctx* c) asm("func_001f8da0");
void func_001f8da0(u8* o, Ctx* c)
{
    Ring* r = (Ring*)(o + c->ofs[0] + 160);
    r->f2 = 0; r->f4 = 0; r->f6 = 0; r->cur = 0; r->n = 31;
}
}  // namespace n001f87f0
