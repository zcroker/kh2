/* libvu0_002f4298.c: Sony PS2 Runtime Library 3.0.0 libvu0: sceVu0RotMatrix, 0x2f4298-0x2f42e8.
 * ee-gcc 2.9-991111 -O2 -G0, linked unit (part of the original libvu0 object: the VU0 macro-mode functions
 * around it are .s units). Third-party code notice: this is a routine from Sony Computer
 * Entertainment's PlayStation 2 Runtime Library that the game links, rebuilt to match. It is not covered by
 * this project's MIT License. */
typedef float V4[4] __attribute__((aligned(16)));
extern void sceVu0RotMatrixZ(V4 *, V4 *, float);
extern void sceVu0RotMatrixY(V4 *, V4 *, float);
extern void sceVu0RotMatrixX(V4 *, V4 *, float);

/* ---- 0x2f4298 */
void sceVu0RotMatrix(V4 *m0, V4 *m1, float *rot)
{
    sceVu0RotMatrixZ(m0, m1, rot[2]);
    sceVu0RotMatrixY(m0, m0, rot[1]);
    sceVu0RotMatrixX(m0, m0, rot[0]);
}
