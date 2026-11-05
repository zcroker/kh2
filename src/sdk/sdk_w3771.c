/* Sony PS2 Runtime Library: libkernl (sce fileio RPC end callback). Built with ee-gcc 2.9-991111 -O2 -G0.
 * Third-party code notice: rebuilt to match Sony Computer Entertainment's PS2 SDK library code that
 * the game links. It is not covered by this project's MIT License. */
typedef struct { int sema; int fno; void *dst; int size; void *p; unsigned int len; } EndHdr;
typedef struct { int n1; int n2; char *p1; char *p2; char d1[64]; char d2[64]; } RdTail;
typedef struct { void *dst; int len; } DstLen;
typedef struct { char b[1088]; } B1088;
extern B1088 D_01e37f00[];
extern int D_00366160;
extern int D_00366168;
extern int D_003660e0[32];
extern void *func_002fdd68(void *, const void *, unsigned int);
extern int func_00305650(int);

/* sce fileio RPC end callback: copies each request's results back to the caller (by fno, jump
 * table 2..26), then either signals the request's semaphore or, for async requests (negated sema),
 * frees its slot. The compare value is pinned to a1 (one register asm) to reproduce the original's
 * negu v0 + move a1,v0 copy; the slot table is read through a volatile pointer, which keeps its
 * stores out of the branch delay slots like the original. */
void func_00309ec0(int *arg)
{
    EndHdr h;
    char *b;
    int idx, i, s;
    D_00366160 = idx = D_00366168 ? arg[3] : 0;
    b = (char *)((unsigned int)&D_01e37f00[idx] | 0x20000000);
    __builtin_memcpy(&h.sema, b, 4);
    __builtin_memcpy(&h.fno, b + 4, 4);
    __builtin_memcpy(&h.dst, b + 8, 4);
    __builtin_memcpy(&h.size, b + 12, 4);
    if (h.sema >= 0)
        func_002fdd68(h.dst, b + 16, h.size);
    switch (h.fno) {
    case 2: {
        RdTail *t = (RdTail *)(b + 20);
        char *d, *u;
        if (t->n1 > 0) {
            d = t->p1;
            u = (char *)((unsigned int)d | 0x20000000);
            for (i = 0; i < t->n1; i++) {
                d[i] = u[i] = t->d1[i];
            }
        }
        if (t->n2 > 0) {
            d = t->p2;
            u = (char *)((unsigned int)d | 0x20000000);
            for (i = 0; i < t->n2; i++) {
                d[i] = u[i] = t->d2[i];
            }
        }
        break;
    }
    case 11:
        if (*(int *)h.dst > 0) {
            __builtin_memcpy(&h.p, b + 20, 4);
            __builtin_memcpy(h.p, b + 24, 324);
        }
        break;
    case 12:
        __builtin_memcpy(&h.p, b + 20, 4);
        __builtin_memcpy(h.p, b + 24, 64);
        break;
    case 23:
    case 25:
    case 26:
        __builtin_memcpy(&h.p, b + 20, 4);
        __builtin_memcpy(&h.len, b + 24, 4);
        s = h.len;
        if (h.len > 1024) {
            h.len = 1024;
            s = 1024;
        }
        func_002fdd68(h.p, b + 28, s);
        break;
    }
    if (h.sema < 0) {
        register int k asm("$5");
        h.sema = -h.sema;
        k = h.sema;
        for (i = 0; i < 32; i++) {
            if (((volatile int *)D_003660e0)[i] == k) {
                ((volatile int *)D_003660e0)[i] = -1;
                break;
            }
        }
    } else
        func_00305650(h.sema);
}



