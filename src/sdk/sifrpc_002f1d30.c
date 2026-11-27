/* Sony PS2 Runtime Library: SIF RPC client call 3 (0x2f1d30), part of the client at 0x2f1b48-0x2f1e18
 * (see sifrpc_002f1b48.c). Built with ee-gcc 2.96 -O2 -G8: the semaphore id is a small-data variable at
 * 0x378ae0, read gp-relative (lw -7456(gp)). The row's -G8 flag makes the compiler emit that; the link
 * sets _gp to the game's 0x37a800 (kh2.ld), so the GPREL16 relocation resolves to the original offset.
 * Third-party code notice: rebuilt to match Sony Computer Entertainment's PS2 SDK library code that
 * the game links. It is not covered by this project's MIT License. */
typedef struct { int pad[9]; int serve; } ClientData;

extern int WaitSema(int);
extern int func_003094b8(ClientData *, int, int, void *, int, void *, int, void (*)(void *), void *);
void func_002f1e00(void *);

extern int D_00378ae0;
extern ClientData D_01e2d900;
extern int D_01e2d940[16];

int func_002f1d30(int a, void *r)
{
    WaitSema(D_00378ae0);
    D_01e2d940[0] = a;
    return func_003094b8(&D_01e2d900, 3, 1, D_01e2d940, 32, r, 32, func_002f1e00, 0);
}
