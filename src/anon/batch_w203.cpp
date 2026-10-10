#include "../common/types.h"

struct W203Vq {
  u32 a, b, c, d;
  W203Vq() {}
  W203Vq(const W203Vq& o) { asm("lq $8,0(%1)\n\tsq $8,0(%0)" :: "r"(this), "r"(&o) : "$8", "memory"); }
  W203Vq& operator=(const W203Vq& o) { if (this != &o) { asm("lq $8,0(%1)\n\tsq $8,0(%0)" :: "r"(this), "r"(&o) : "$8", "memory"); } return *this; }
} __attribute__((aligned(16)));
extern W203Vq D_01e2bf90;

extern "C" {
void func_00152508(void*, u32, u32, u32, u32);
void func_00162058(float);  // to_161f48_arg1
void func_0023fad0(void*);
void w203_createTask(int, int, void (*)(void*)) asm("_ZN5FIELD10CreateTaskEiiPFvP4TASKE");
void w203_ensureTask(void*) asm("_ZN2dk10TalkCamera10ensureTaskEP4TASK");
struct W203Fl { u8 pad[0x70]; float f; };
W203Fl* w203_config(void) asm("_ZN2Ti6MGJump6configEv");

struct W203C { u8 p[0x1b4]; u32 a, b, c, d; };
void func_00152ab8(W203C* a, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
  a->c = a5; a->b = a4; a->a = a2; a->d = a6;
  func_00152508(a, 108, a2, a3, a7);
}

void func_00159c20(void) {
  w203_createTask(1, 25990, w203_ensureTask);
  func_00162058(8.0f);  // to_161f48_arg1
}

void u_call4_0023f8c8(u8* a) asm("_Z16u_call4_0023f8c8jjjj");
void u_call4_0023f8c8(u8* a) {
  if (a[24]) func_0023fad0(a);
  *(u32*)(a + 4) = 0;
}

float func_002dc248(void) { return -300.0f - w203_config()->f; }

void func_002e8ca8(W203Vq** a) { W203Vq t(**a); D_01e2bf90 = t; *a = &D_01e2bf90; }
}
