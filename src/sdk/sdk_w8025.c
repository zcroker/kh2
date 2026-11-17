/* Sony PS2 Runtime Library 3.0.0: libkernl semaphore code (00310c60). Built with ee-gcc 2.9-991111 -O2 -G0. */
typedef struct Sem_w8025 { struct Sem_w8025 *next; volatile int id; } Sem_w8025;
extern int DIntr(void);
extern void EIntr(void);
extern int func_00310130(int);
extern Sem_w8025 *D_01e3b300;

int func_00310c60(unsigned int id);  // 0x00310c60: definition moved into src/sdk/libkernl_00310048.c
