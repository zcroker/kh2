/* libkernl small stubs and tail-call wrappers (Sony PS2 Runtime Library 3.0.0), built with ee-gcc 2.9 */
extern int D_003660c8;
extern int D_0036616c;
extern void func_0030f468(void);
extern void func_003114f0(void);
extern int SignalSema(int sid);

void func_001002a0(void) { func_0030f468(); }

void func_0030f3a8(void) { func_003114f0(); }

void func_00305aa0(void) { D_003660c8 = 0; }

void func_0030a300(void) { SignalSema(D_0036616c); }
