#include "../common/types.h"

extern "C" {

int func_00112c48(u32);
float func_00112c28(void);
float func_00112c38(void);

int func_00119f48(u32 a) {
    int r = func_00112c48(a);
    a &= 0x200;
    if (r >= 0) {
        if (a == 0) {
            float t = func_00112c28() + 8.0f;
            float u = func_00112c38();
            if (u <= t) return 1;
        }
    }
    return 0;
}

char* getFieldMode_(void) asm("_Z12getFieldModev");
char* create_task_(void*, int, int, void*) asm("_ZN12TASK_MANAGER11create_taskEiiPFvP4TASKE");
char* area_alloc_(int) asm("_ZN4AREA5AllocEj");
void func_001e27c0(void*);
void func_001e2938(void);
void func_001e2998(void);
extern int D_00352bd0;

void func_001e29e0(int a) {
    char* r = getFieldMode_();
    char* x = create_task_(*(void**)(r + 4), 1, 20500, (void*)func_001e2938);
    *(void**)(x + 48) = (void*)func_001e2998;
    char* s = area_alloc_(3600);
    func_001e27c0(s);
    D_00352bd0 = (int)s;
    *(int*)(s + 3536) = a;
}

}
