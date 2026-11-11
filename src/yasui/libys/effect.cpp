#include "effect.hpp"

// YS::EFFECT (0x1a3a50-0x1a3d70): the system effect file (effect.bar, its PAX), effect spawning,
// and a ring of the last four dead effects (released when replaced).
// The static initialiser (0x1a3d70, constructs the PAX and clears the ring) and its stubs stay
// separate functions: gcc keeps the ring's base in a register differently. So the objects here
// are plain data.

namespace ryj {
    struct PAX {
        u8 d[0x1c];
    };
}

struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));

// The last four dead effects.
struct DEAD_RING {
    void* e[4];
    s32 idx;
    void Clear() {
        void** q = e;
        for (s32 i = 3; i >= 0; i--) *q++ = 0;
        idx = 0;
    }
};

extern "C" {
const char* D_00350748 = "00effect.bar";
void func_00170518(const char*, s32, s32);
s32 func_001708f8(const char*, s32);
u8* func_00168b38(s32, s32, s32);
void func_001dddd0(ryj::PAX*, u32);
void func_001de450(ryj::PAX*);
void func_001dde40(ryj::PAX*);
void func_00170950(s32);
s32 func_001de2e0(u32, u32);
u8* func_001de168(u32, s32, u32, u32, u32, u32);
V4* func_001dc5f8(u8*);
s32 func_001dc9d0(void*);
void func_001dc978(void*, f32);
}

static ryj::PAX s_pax;
static s32 s_cache;
static DEAD_RING s_dead;

namespace YS {

void EFFECT::Read(void) {
    func_00170518(D_00350748, 1000, 0);
}

ryj::PAX* EFFECT::GetSystemPax(void) {
    return &s_pax;
}

void EFFECT::Init(void) {
    s_cache = func_001708f8(D_00350748, -1);
    func_001dddd0(&s_pax, *(u32*)(func_00168b38(s_cache, 18, 0) + 8));
    s_dead.Clear();
}

void EFFECT::Ensure(void) {
    func_001de450(&s_pax);
    func_001dde40(&s_pax);
    func_00170950(s_cache);
}

}  // namespace YS

extern "C" {

u8* func_001a3b48(u32 a, u32 b, V4* v, u32 c, u32 d, u32 e)
{
    s32 id = func_001de2e0(a, b);
    u8* r = 0;
    if (id >= 0) {
        u8* o = func_001de168(a, id, c, d, e, 0);
        if (o) {
            V4* dst = func_001dc5f8(o);
            if (dst != v) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(dst), "r"(v) : "$8", "memory");
        }
        r = o;
    }
    return r;
}

u8* func_001a3bf0(u32 a, u32 b, u32 e, u32 c, u32 d, u32 f) {
    s32 r = func_001de2e0(a, b);
    if (r < 0) return 0;
    return func_001de168(a, r, c, d, f, e);
}

}  // extern "C"

namespace YS {

void EFFECT::Exec(void) {
    void** p = s_dead.e;
    s32 i = 3;
    do {
        if (*p) {
            if (!func_001dc9d0(*p)) *p = 0;
        }
        i--;
        p++;
    } while (i >= 0);
}

void EFFECT::AddDeadEffect(ryj::EFFECT* e) {
    if (!e) return;
    DEAD_RING* r = &s_dead;
    void* old = r->e[r->idx];
    if (old) func_001dc978(old, 4.0f);
    r->e[r->idx] = e;
    r->idx = (r->idx + 1) % 4;
}

}  // namespace YS
