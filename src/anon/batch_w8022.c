#include "../common/types.h"

/* 0026d208 */


extern s32 D_0035f0f8;
extern u8* D_0035f0f4;
extern char D_00373828[];
s32 func_00293bc0(void);
u32 func_001a8c10(s32, s32);
s32 func_001a8c78(s32, s32);
void func_002fde18(void*, s32, s32);
char* func_00192cc0(char*, char*);
s32 func_002595e8(char*, char*);
s32 func_00192b30(char*);
void func_002595b8(s32, char*, s32);
s32 func_002595e0(void);
char* func_001b77a8(u32);

void func_0026d208(void);  // 0x0026d208: definition moved into src/anon/unit_0026c450.cpp

/* 00233ce0 */
typedef struct W8022_S420 { u8 b; s32 x4; s32 x8; s32 xc; s32 x10; } W8022_S420;
typedef struct W8022_E480 { s32 a, b, c, d, e, f, g, h; } W8022_E480;
s32 func_002fbc78(s32);
extern s32 D_01dae580[2];
extern s32 D_01dae588[2];
extern s32 D_0035e360, D_0035e364, D_0035e368, D_0035e36c, D_0035e370, D_0035e374;
extern W8022_S420 D_01dae420;
typedef struct W8022_438 { void* p; s32 a[12]; } W8022_438;
extern W8022_438 D_01dae438;
extern s32 D_01dae478, D_01dae47c;
extern W8022_E480 D_01dae480[2][4];
void func_00233ce0(void) {
    s32 i, j;
    for (i = 0; i < 2; i++) {
        D_01dae580[i] = 1;
        D_01dae588[i] = func_002fbc78(i);
    }
    D_0035e370 = 0;
    D_0035e374 = 0;
    D_01dae420.x4 = 300;
    D_0035e360 = 0;
    D_0035e364 = 0;
    D_0035e368 = 1;
    D_01dae420.b = 0;
    D_01dae478 = 0;
    D_0035e36c = 1;
    D_01dae47c = 0;
    D_01dae420.xc = 0;
    D_01dae420.x8 = 300;
    D_01dae420.x10 = 0;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            W8022_E480* e = &D_01dae480[i][j];
            e->a = -1; e->b = -1; e->c = 0; e->d = -1;
            e->e = -1; e->f = -1; e->g = -1; e->h = 0;
        }
    }
    D_01dae438.p = (void*)-1;
    D_01dae438.a[0] = -1;
    D_01dae438.a[1] = -1;
    D_01dae438.a[2] = -1;
    D_01dae438.a[3] = -1;
    D_01dae438.a[4] = -1;
    D_01dae438.a[5] = -1;
    D_01dae438.a[6] = -1;
    D_01dae438.a[7] = -1;
    D_01dae438.a[8] = -1;
    D_01dae438.a[9] = -1;
    D_01dae438.a[10] = -1;
    D_01dae438.a[11] = -1;
}
