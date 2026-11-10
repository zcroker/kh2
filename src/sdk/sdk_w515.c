/* Sony PS2 Runtime Library 3.0.0: libkernl (0x30xxxx/0x310xxx) plus libvu0/RPC-client helpers (0x2f4xxx-0x2f6xxx). ee-gcc 2.9-991111 -O2 -G0. */
extern int DIntr(void);
extern int EIntr(void);

extern int func_00310090(int);
int func_00310130(int a)
{
    int s = DIntr();
    int r = func_00310090(a);
    if (s) EIntr();
    return r;
}

extern int func_00310230(int);
int func_003102e0(int a)
{
    int s = DIntr();
    int r = func_00310230(a);
    if (s) EIntr();
    return r;
}

extern int func_00310330(int);
int func_003103f8(int a)
{
    int s = DIntr();
    int r = func_00310330(a);
    if (s) EIntr();
    return r;
}

extern int func_00310518(int);
int func_00310560(int a)
{
    int s = DIntr();
    int r = func_00310518(a);
    if (s) EIntr();
    return r;
}

extern int func_003105b0(int);
int func_00310620(int a)
{
    int s = DIntr();
    int r = func_003105b0(a);
    if (s) EIntr();
    return r;
}

typedef struct E { struct E *next; int a, b, c; } E;
extern E D_01e3af00[64];
extern E *D_01e3b300;
int func_00310990(void)
{
    int i;
    D_01e3b300 = D_01e3af00;
    for (i = 0; i < 64; i++)
        D_01e3af00[i].next = &D_01e3af00[i + 1];
    D_01e3af00[63].next = 0;
    return 0;
}

extern void sceVu0RotMatrixZ(void *, float);
extern void* sceVu0RotMatrixY(void *, void *, float);
extern void sceVu0RotMatrixX(void *, void *, float);
void sceVu0RotMatrix(void *a, void *b, float *v)
{
    sceVu0RotMatrixZ(a, v[2]);
    sceVu0RotMatrixY(a, a, v[1]);
    sceVu0RotMatrixX(a, a, v[0]);
}

extern int func_00305a30(int);
extern int func_00305aa0(void);
extern int func_00310f38(int, int);
int func_0030ec50(void)
{
    if (!(func_00305a30(4) & 0x40000)) return 0;
    func_00305aa0();
    func_00310f38(1, 1);
    func_00310f38(0, 1);
    return 1;
}

struct S7118 { int a, b, c, d, e; };
extern struct S7118 D_00367118;
int func_00310180(int *p, int *q)
{
    volatile struct S7118 *s = &D_00367118;
    if (s->c < 0) return 0x80008001;
    if (p) *p = s->e;
    if (q) *q = 128 - s->e;
    return 0;
}

extern int sceSifCallRpc(void *, int, int, void *, int, void *, int, int, int);
extern char D_01e2d980[];
extern int D_01e2da80[];
int func_002f4a20(void)
{
    sceSifCallRpc(D_01e2d980, 0x80001363, 0, D_01e2da80, 144, D_01e2da80, 144, 0, 0);
    return D_01e2da80[0];
}

typedef struct { int a; int b; int c; int d; char pad[820 - 16]; } Ent;
extern Ent D_01e2fe48[];
extern int sceDbcGetDepNumber(int);
int func_002f62b8(int i)
{
    int r = sceDbcGetDepNumber(i);
    if (r < 0) return r;
    D_01e2fe48[i].d = r;
    D_01e2fe48[i].b = 1;
    return r;
}
