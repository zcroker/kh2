#include "../common/types.h"
#define QCOPY257(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV257 {
    f32 x, y, z, w;
    QV257() {}
    QV257(const QV257& o) { QCOPY257(this, &o); }
} __attribute__((aligned(16)));
static inline QV257 operator*(const QV257& a, f32 k) {
    QV257 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
static inline QV257 operator+(const QV257& a, const QV257& b) {
    QV257 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}

static inline QV257 operator-(const QV257& a, const QV257& b) {
    QV257 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 normalize257(QV257* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline __attribute__((always_inline)) void set4_257(QV257* v, f32 x, f32 y, f32 z, f32 w) { v->x = x; v->y = y; v->z = z; v->w = w; }
extern "C" {
extern u8* D_0035f634;
s32 func_00139d78(u8*);
void func_002b1660(void);
void func_002b2220(void);  // 0x002b2220: definition moved into src/anon/unit_002b1db8.cpp
extern u8* D_00361f60;
void func_00198690(u8*);
s32 func_001c0cd8(u8*);
void func_0016b070(u8*, f32*);
void func_0016ace0(u8*, f32*);
s32 func_002d8d68(u8*, u8*, u8*, u8*);
u8* func_002d73f0(u8*);
void func_001d86a0(s32, s32);
union UF { f32 f; s32 i; u8 c; };
void func_002dbb88(u8* a0);  // 0x002dbb88: definition moved into src/anon/unit_002da040.cpp
extern u8* D_0035f610;
u8* func_00294000(s32);
s32 func_002abf40(s32, s32);
static inline s32 tst_002abff0(s32 a0, s32 b) {
    u32* p = (u32*)(D_0035f610 + a0 * 4) + 43; return (p[(u32)b >> 5] & (1 << (b & 31))) != 0;
}
s32 Tz__JmNewInfo__isStoryNew(s32 a0, s32 a1);  // 0x002abff0: definition moved into src/anon/unit_002a99c8.cpp
QV257 func_002cd950(void* self, f32 t, const QV257* p, const QV257* q);  // 0x002cd950: definition moved into src/taito/path.cpp
extern s8 D_01e2bd80;
extern QV257 D_01e2bd90;
void YS__PLAYER__move_stop(u8*);  // clear_vecs_three
QV257 func_00190388(u32*);  // vec4_from_arg
QV257* YS__OBJ__get_pos(u8*);  // obj_get_attach_or_alt
void func_0016aef0(u8*, QV257*);
void func_002c6118(void);
void func_002fd188(void (*)(void));  // pool_alloc_block
void func_002cb0e8(u32*, QV257*, f32);
u32 func_002c1b48(u32);
void func_002cab98(u32);
void func_002c17a0(void);
void func_002c5dc0(u8* a0, u32* a1);  // 0x002c5dc0: definition moved into src/anon/unit_002c53c8.cpp
extern u8* D_00352130;
struct S32bb { u8 pad[0x3db0]; u16 h; };
extern S32bb D_0032bb30;
extern u32 D_003638d0;
u8* func_0017df58(s32);
s32 YS__OBJ__is_exist(u8*);
s32 YS__FRIEND__can_sacrifice_leave(u8*);
f32 func_002f8b30(f32, f32);
#define MAX257(a, b) ((a) > (b) ? (a) : (b))
void func_001aefa0(u8* a0);  // 0x001aefa0: definition moved into src/anon/unit_001ada38.cpp
}
