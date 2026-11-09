#include "../common/types.h"
extern "C" {
extern u8 D_00347f98[];
extern u8 D_00347e60[];
extern u8 D_0034a700[];
extern u8 D_0034a760[];
extern u8 D_0034a740[];
extern u8 D_0034a720[];
void func_0031a838(void*);
void func_00239700(void*);
void func_0031cc28(void*);
void func_00152b50(void*);
}
inline void* operator new(unsigned int, void* p) { return p; }
inline void* operator new[](unsigned int, void* p) { return p; }
struct HeapA1577 { virtual void* Alloc(u32, u32); };
struct SysA1577 { u8 pad[20]; HeapA1577* heap; };
extern "C" SysA1577* D_00347f80;
struct M1_1577 { u8 d[12]; M1_1577() { func_0031a838(this); } };
struct M2_1577 { u8 d[384]; M2_1577() { func_00239700(this); } };
struct M3_1577 { u32 d; M3_1577() { func_0031cc28(this); } };
struct EA0_1577 { u32 vt; EA0_1577() { vt = (u32)D_00347f98; } };
struct EA1577 : EA0_1577 { u32 f4, f8; M1_1577 m12; };
struct EBv1577 : EA1577 { EBv1577() { vt = (u32)D_00347e60; } };
struct EB1577 : EBv1577 {
    M2_1577 m24;
    u32 f408;
    u8 pad[188];
    EB1577() { f408 = 0; }
};
template <int K> struct EC1577 : EB1577 { EC1577(); };
template <> inline EC1577<0>::EC1577() { vt = (u32)D_0034a760; }
template <> inline EC1577<1>::EC1577() { vt = (u32)D_0034a740; }
template <> inline EC1577<2>::EC1577() { vt = (u32)D_0034a720; }
struct P1577 { u32 a, b; void clr() { a = 0; b = 0; } };
static inline void clrP(P1577& r) { r.b = 0; r.a = 0; }
template <int K, int N> struct In1577 {
    P1577 p;
    EC1577<K> e[N];
    In1577() { p.clr(); }
};
template <int K, int N> struct Grp1577 {
    M3_1577 s;
    In1577<K, N> in;
    u8 pad[8];
};
struct ObjB1577 { u32 vt; u32 f4, f8, f12; ObjB1577() { f12 = 0; vt = (u32)D_0034a700; } };
struct Obj152f40 : ObjB1577 {
    u8 pad[16];
    Grp1577<0, 16> g0;
    Grp1577<1, 4> g1;
    Grp1577<2, 4> g2;
};
extern "C" {
extern Obj152f40* volatile D_0034a6f0;
}
void u_tail0_00152f40(void) { register Obj152f40* o asm("$20") = (Obj152f40*)D_00347f80->heap->Alloc(14484, 0); new (o) ObjB1577; {EC1577<0>* eb; asm("addiu %0,%1,44" : "=r"(eb) : "r"(o));P1577* p; asm("addiu %0,%1,36" : "=r"(p) : "r"(o)); func_0031cc28(&o->g0.s); new (eb) EC1577<0>[16]; p->clr();} {P1577* p=&o->g1.in.p; func_0031cc28(&o->g1.s); new (o->g1.in.e) EC1577<1>[4]; p->clr();} {P1577* p=&o->g2.in.p; func_0031cc28(&o->g2.s); new (o->g2.in.e) EC1577<2>[4]; p->clr();} D_0034a6f0 = o; func_00152b50(D_0034a6f0); }
