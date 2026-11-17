// Unit 0x165f70-0x166148: polygon gather (one function). 0x166148 (whole asm, batch_w3933.s) follows; the
// rest of the file is unit_001664c0.cpp.
#include "../common/types.h"

// ---- 00165f70 from src/anon/batch_w1964.cpp
namespace n00165f70 {
struct V5 { f32 x, y, z, w; V5() {} ~V5() {} } __attribute__((aligned(16)));
struct P5 { f32 x, y, z, d; } __attribute__((aligned(16)));
struct X5 { u8 b[32]; } __attribute__((aligned(16)));
struct G5 { u8 p[28]; u16 start, end; };
struct I5 { u8 p[12]; u16 start, end; u8 flag; u8 q[3]; };
struct T5 { u8 p[10]; u16 idx; u8 q[4]; };
struct O5 {
    s32 f0;
    G5* grp;        
    I5* item;       
    T5* tri;        
    s32 f10, f14;
    P5* pl;          
    s32 f1c;
    s32 n;           
};
void func_00141988(O5*, T5*, X5*) asm("func_00141988");
void func_001626e0(X5*, V5*) asm("func_001626e0");
s32 func_001466b0(void*, V5*) asm("func_001466b0");
void func_00146ab0(u8*, P5*, V5*) asm("func_00146ab0");
static inline __attribute__((always_inline)) f32 dot(const P5* a, const P5* b) {
    f32 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder"
        : "=f"(r) : "r"(a), "r"(b) : "$8", "memory");
    return r;
}
void func_00165f70(O5* o, P5* p, u8* out, s32* cnt, void* a4) asm("func_00165f70");
void func_00165f70(O5* o, P5* p, u8* out, s32* cnt, void* a4) {
    V5 poly[8];
    X5 x;
    s32 n = o->n;
    for (s32 i = 0; i < n; i++) {
        G5* g = &o->grp[i];
        s32 je = g->end;
        s32 j = g->start;
        for (; j < je; j++) {
            I5* it = &o->item[j];
            if (it->flag) {
                s32 ke = it->end;
                s32 k = it->start;
                for (; k < ke; k++) {
                    T5* t = &o->tri[k];
                    P5* pl = &o->pl[t->idx];
                    if (dot(p, pl) + pl->d < 0.0f) continue;
                    func_00141988(o, t, &x);
                    func_001626e0(&x, poly);
                    if (func_001466b0(a4, poly)) {
                        func_00146ab0(out, p, poly);
                        out += 80;
                        (*cnt)++;
                    }
                }
            }
        }
    }
}
}  // namespace n00165f70

