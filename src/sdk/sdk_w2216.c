/* libkernl small tail-call wrappers (Sony PS2 Runtime Library 3.0.0), built with ee-gcc 2.9 */
extern int D_00367138;
extern int D_0036713c;
extern char D_01e3b308[];
extern void func_0030f620(unsigned int, int);
extern void func_002fde18(void *, int, int);

void func_0030f690(int a) { func_0030f620(0xb0001000, a); }

void func_0030f6a0(int a) { func_0030f620(0xb0001010, a); }

void func_0030f6b0(int a) { func_0030f620(0xb0001020, a); }

void func_00310d80(void) { D_00367138 = 0; D_0036713c = 0; func_002fde18(D_01e3b308, 0, 512); }
