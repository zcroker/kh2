/* libvu0_002f4310.c: Sony PS2 Runtime Library 3.0.0 libvu0: camera, normal-light and light-colour matrices,
 * 0x2f4310-0x2f44e8. ee-gcc 2.9-991111 -O2 -G0, linked unit (part of the original libvu0 object).
 * Third-party code notice: this is a routine from Sony Computer
 * Entertainment's PlayStation 2 Runtime Library that the game links, rebuilt to match. It is not covered by
 * this project's MIT License. */
typedef float V4[4] __attribute__((aligned(16)));
extern void sceVu0UnitMatrix(V4 *);
extern void sceVu0OuterProduct(float *, float *, float *);
extern void sceVu0Normalize(float *, float *);
extern void sceVu0TransMatrix(V4 *, V4 *, float *);
extern void sceVu0InversMatrix(V4 *, V4 *);
extern void sceVu0ScaleVector(float *, float *, float);
extern void sceVu0TransposeMatrix(V4 *, V4 *);
extern void sceVu0CopyVector(float *, float *);

/* ---- 0x2f4310 (camera matrix) */
void func_002f4310(V4 *m, float *p, float *zd, float *yd)
{
    V4 m0[4];
    V4 xd;
    sceVu0UnitMatrix(m0);
    sceVu0OuterProduct(xd, yd, zd);
    sceVu0Normalize(m0[0], xd);
    sceVu0Normalize(m0[2], zd);
    sceVu0OuterProduct(m0[1], m0[2], m0[0]);
    sceVu0TransMatrix(m0, m0, p);
    sceVu0InversMatrix(m, m0);
}

/* ---- 0x2f43c0 (normal light matrix) */
void func_002f43c0(V4 *m, float *l0, float *l1, float *l2)
{
    V4 t;
    sceVu0ScaleVector(t, l0, -1.0f);
    sceVu0Normalize(m[0], t);
    sceVu0ScaleVector(t, l1, -1.0f);
    sceVu0Normalize(m[1], t);
    sceVu0ScaleVector(t, l2, -1.0f);
    sceVu0Normalize(m[2], t);
    m[3][0] = m[3][1] = m[3][2] = 0.0f;
    m[3][3] = 1.0f;
    sceVu0TransposeMatrix(m, m);
}

/* ---- 0x2f4480 (light colour matrix) */
void func_002f4480(V4 *m, float *c0, float *c1, float *c2, float *a)
{
    sceVu0CopyVector(m[0], c0);
    sceVu0CopyVector(m[1], c1);
    sceVu0CopyVector(m[2], c2);
    sceVu0CopyVector(m[3], a);
}
