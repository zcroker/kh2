/* Sony PS2 Runtime Library: libgraph. Built with ee-gcc 2.9-991111 -O2 -G0.
 * Third-party code notice: rebuilt to match Sony Computer Entertainment's PS2 SDK library code that
 * the game links. It is not covered by this project's MIT License. */
typedef unsigned int u_long128 __attribute__((mode(TI)));
extern unsigned int D_00363c50[];

/* sceGsResetPath: resets VIF1 (FBRST, ERR), sets the VU1 reset bit in vi28 (FBRST via cfc2/ctc2),
 * sends the two init quadwords to the VIF1 FIFO and resets GIF (GIF_CTRL = 1).
 * The last store goes through a plain pointer pinned to v1 after a memory barrier: a volatile
 * store never fills the jr ra delay slot under 2.9, the original's does (partial asm, see asm_review.tsv). */
void sceGsResetPath(void);  // 0x002f1fb8: definition moved into src/sdk/libgraph_002f1e18.c
