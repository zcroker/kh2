/* Sony PS2 Runtime Library 3.0.0: libcdvd (libcdvd.a), 0x2f6698-0x2f6870: the callback setter, the end-of-command
 * callback and the callback thread loop (0x2f67a0). Built with ee-gcc 2.9-991111 -O2 -G0.
 * Third-party code notice: rebuilt to match Sony Computer Entertainment's PS2 SDK library code that
 * the game links. It is not covered by this project's MIT License.
 * Linked unit (linked_units.tsv): a part of the object (it starts at 0x2f6698, after libvib), compiled as one
 * file; its .data stays outside, reached by name. Partial inline asm only for the $gp save and one empty scheduling barrier (asm_review.tsv). */
extern int DIntr(void);
extern int EIntr(void);
extern int func_00305650(int s);
extern int func_002f71b0(int);
extern int D_01e331c0;
extern int D_01e331c4;
extern int D_00363de0;
extern int D_00363de4;
extern int D_00363db4;
extern int D_00363da8;
extern int D_00363da0;
extern int D_00363d94;
extern int D_00363d90;
extern int D_01e331d4;
extern char D_00376b48[];
extern int func_00305660(int);
extern void func_00305460(void);
extern void func_003080d0(const char *, ...);

/* sceCdCallback: installs the end-of-command callback, returns the old one (0 while the drive is busy). */
int func_002f6698(int a)
{
    int old, s;
    if (func_002f71b0(1) != 0)
        return 0;
    s = DIntr();
    old = D_01e331c0;
    D_01e331c0 = a;
    asm volatile("sw $gp, %0" : "=m"(D_01e331c4));
    if (s)
        EIntr();
    return old;
}

#define V(x) (*(volatile int *)&(x))
void func_002f6700(int *p)
{
    V(D_00363de0) = *p;
    V(D_00363de4) = V(D_00363de0);
    if (V(D_00363de0) == 11) {
        V(D_00363de0) = 0;
        V(D_00363db4) = 0;
        return;
    }
    func_00305650(V(D_00363da8));
    if (V(D_00363d94) != 0 && V(D_01e331c0) != 0) {
        func_00305650(V(D_00363da0));
    } else {
        V(D_00363db4) = 0;
    }
    V(D_00363de0) = 0;
}

/* Callback thread: waits on the semaphore, resets the command state when it reads -1, then calls the user callback
 * with the library's $gp swapped in. The empty asm after the first store pins sched2's order (store, lui, stores). */
void func_002f67a0(void)
{
    void (*cb)(int);
    int old;
    while (1) {
        func_00305660(D_00363da0);
        if (D_00363de0 == -1) {
            D_00363db4 = 0;
            asm volatile("");
            D_00363de0 = 0;
            D_00363d94 = 0;
            D_01e331d4 = 0;
            func_00305460();
        }
        if (D_00363d90 > 0)
            func_003080d0(D_00376b48, D_01e331c0, D_00363de4);
        cb = (void (*)(int))D_01e331c0;
        if (cb && V(D_00363de4)) {
            asm volatile("move %0,$28\n\tlw $28,%1" : "=r"(old) : "m"(D_01e331c4) : "memory");
            cb(D_00363de4);
            asm volatile("move $28,%0" : : "r"(old));
        }
        V(D_00363db4) = 0;
    }
}
