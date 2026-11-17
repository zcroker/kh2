// Linked unit (see linked_units.tsv); one namespace per old matched source.
#include "../common/types.h"

// 002b6f28 (was src/anon/batch_wcx2_O0.cpp)
namespace n002b6f28 {
// ---- 002b6f28
s32 func_002b6708_6f28(s32, s32, u32, u32, u32) asm("func_002b6708");
/*TARGET 002b6f28*/
s32 func_002b6f28(u32 a0, u32 a1, u32 a2) asm("func_002b6f28");
s32 func_002b6f28(u32 a0, u32 a1, u32 a2) {
    return func_002b6708_6f28(4, 14, a0, a1, a2);
}
}  // namespace n002b6f28

// 002b6f78 (was src/anon/batch_w50_O0.cpp)
namespace n002b6f78 {
void func_003058a0(s32) asm("func_003058a0");
struct Ent64 { s32 kind; u8 pad[60]; };
extern Ent64 D_01e22080[] asm("D_01e22080");
/*TARGET 002b6f78*/
// Counts table entries of kind 11..14.
s32 func_002b6f78(void) asm("func_002b6f78");
// Counts table entries of kind 11..14.
s32 func_002b6f78(void) {
    s32 i;
    s32 n = 0;
    func_003058a0(0);
    for (i = 0; i < 512; i++) {
        switch (D_01e22080[i].kind) { case 11: case 12: case 13: case 14: n++; }
    }
    return n;
}
}  // namespace n002b6f78

// 002b7010 (was src/anon/batch_w42_O0.cpp)
namespace n002b7010 {
s32 func_002b6708(s32, s32, u32, u32, u32, u32, u32, u32) asm("func_002b6708");
/*TARGET 002b7010*/
s32 func_002b7010(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f) asm("func_002b7010");
s32 func_002b7010(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f)
{
    return func_002b6708(7, 15, a, b, c, d, e, f);
}
}  // namespace n002b7010

// 002b7078 (was src/anon/batch_w207_O0.cpp)
namespace n002b7078 {
u32 func_002b6708(u32, u32, u32) asm("func_002b6708");
u32 w_002b7078(u32 a) asm("_Z16wtarget_002b7078jjjj");
/*TARGET 002b7078*/
u32 w_002b7078(u32 a) asm("_Z16wtarget_002b7078jjjj");
u32 w_002b7078(u32 a) { return func_002b6708(2, 16, a); }
}  // namespace n002b7078

// 002b70b8 (was src/anon/batch_wcx2_O0.cpp)
namespace n002b70b8 {
// ---- 002b6f28
s32 func_002b6708_6f28(s32, s32, u32, u32, u32) asm("func_002b6708");
// ---- 002b70b8
s32 wt_002b70b8(u32 a0, u32 a1, u32 a2) asm("_Z16wtarget_002b70b8jjjj");
/*TARGET 002b70b8*/
s32 wt_002b70b8(u32 a0, u32 a1, u32 a2) asm("_Z16wtarget_002b70b8jjjj");
s32 wt_002b70b8(u32 a0, u32 a1, u32 a2) {
    return func_002b6708_6f28(4, 17, a0, a1, a2);
}
}  // namespace n002b70b8

// 002b7108 (was src/anon/batch_w208_O0.cpp)
namespace n002b7108 {
extern void* func_002b6708(int, int, void*) asm("func_002b6708");
void* func_002b7108(void*) asm("_Z13func_002b7108Pv");
/*TARGET 002b7108*/
void* func_002b7108(void* a) asm("_Z13func_002b7108Pv");
void* func_002b7108(void* a) { return func_002b6708(2, 18, a); }
}  // namespace n002b7108

// 002b7148 (was src/anon/batch_w96_O0.cpp)
namespace n002b7148 {
struct Slot64_w96 { s32 state; s32 owner; u8 pad[56]; };
extern Slot64_w96 D_01e22080[] asm("D_01e22080");
extern Slot64_w96 D_01e22084[] asm("D_01e22084");
void func_003058a0(u32) asm("func_003058a0");
/*TARGET 002b7148*/
// Counts slots (owner read via the +4 view of the table, as the original addresses it) in state 15 (optionally only those owned by who).
s32 func_002b7148(s32 who) asm("func_002b7148");
// Counts slots (owner read via the +4 view of the table, as the original addresses it) in state 15 (optionally only those owned by who).
s32 func_002b7148(s32 who) {
    s32 i;
    s32 n = 0;
    func_003058a0(0);
    if (who < 0) {
        for (i = 0; i < 512; i++) {
            if (D_01e22080[i].state == 15) n++;
        }
    } else {
        for (i = 0; i < 512; i++) {
            if (D_01e22080[i].state == 15 && D_01e22084[i].state == who) n++;
        }
    }
    return n;
}
}  // namespace n002b7148

// 002b726c (was src/anon/batch_w40_O0.cpp)
namespace n002b726c {
s32 func_002b6708(s32, s32, s32, s32, s32, s32, s32) asm("func_002b6708");
/*TARGET 002b726c*/
s32 func_002b726c(s32 a, s32 b, s32 c, s32 d, s32 e) asm("func_002b726c");
s32 func_002b726c(s32 a, s32 b, s32 c, s32 d, s32 e) {
    if (d >= 14848) e = 64;
    return func_002b6708(6, 19, a, b, c, d, e);
}
}  // namespace n002b726c

// 002b72e4 (was src/anon/batch_w34_O0.cpp)
namespace n002b72e4 {
u32 wtarget_002b72e4(u32, u32, u32) asm("_Z16wtarget_002b72e4jjjj");
u32 func_002b6708(u32, u32, ...) asm("func_002b6708");
/*TARGET 002b72e4*/
u32 wtarget_002b72e4(u32 a, u32 b, u32 c) asm("_Z16wtarget_002b72e4jjjj");
u32 wtarget_002b72e4(u32 a, u32 b, u32 c) {
    return func_002b6708(4, 20, a, b, c);
}
}  // namespace n002b72e4

// 002b7334 (was src/anon/batch_w41_O0.cpp)
namespace n002b7334 {
s32 func_002b6708(s32, s32, s32, s32, s32, s32, s32) asm("func_002b6708");
/*TARGET 002b7334*/
s32 func_002b7334(s32 a, s32 b, s32 c, s32 d, s32 e) asm("func_002b7334");
s32 func_002b7334(s32 a, s32 b, s32 c, s32 d, s32 e) {
    if (d >= 14848) e = 64;
    return func_002b6708(6, 21, a, b, c, d, e);
}
}  // namespace n002b7334

// 002b73ac (was src/anon/batch_w38_O0.cpp)
namespace n002b73ac {
s32 func_002b6708(s32, s32, u32, u32, u32, u32, u32) asm("func_002b6708");
/*TARGET 002b73ac*/
s32 func_002b73ac(u32 a, u32 b, u32 c, u32 d, u32 e) asm("func_002b73ac");
s32 func_002b73ac(u32 a, u32 b, u32 c, u32 d, u32 e) {
    return func_002b6708(6, 22, a, b, c, d, e);
}
}  // namespace n002b73ac

// 002b740c (was src/anon/batch_w203_O0.cpp)
namespace n002b740c {
/*TARGET 002b740c*/
u32 func_002b740c(u32 a, u32 b, u32 c, u32 d) asm("func_002b740c");
u32 func_002b740c(u32 a, u32 b, u32 c, u32 d) { return 0; }
}  // namespace n002b740c

// 002b7440 (was src/anon/batch_wcx2_O0.cpp)
namespace n002b7440 {
// ---- 002b7440
struct Ent2b7 { s32 type; s32 a; s32 b; s32 c; u8 pad[48]; };
extern Ent2b7 D_01e22080[] asm("D_01e22080");
/*AMBIG-MULTI*/ // The same table viewed from its a/b/c fields (how the original addresses them).
extern Ent2b7 D_01e22084[] asm("D_01e22084"), D_01e22088[] asm("D_01e22088"), D_01e2208c[] asm("D_01e2208c");
s32 func_003058a0(s32 a) asm("func_003058a0");
/*TARGET 002b7440*/
// Count type-19/43 entries matching the given keys (negative key = wildcard).
s32 func_002b7440(s32 a, s32 b, s32 c) asm("func_002b7440");
// Count type-19/43 entries matching the given keys (negative key = wildcard).
s32 func_002b7440(s32 a, s32 b, s32 c) {
    s32 i;
    s32 n = 0;
    func_003058a0(0);
    if (a < -99) {
        for (i = 0; i < 512; i++) {
            if (D_01e22080[i].type == 19) n++;
            if (D_01e22080[i].type == 43) n++;
        }
    } else if (b < 0) {
        for (i = 0; i < 512; i++) {
            if (D_01e22080[i].type == 19 && D_01e22084[i].type == a) n++;
            if (D_01e22080[i].type == 43 && D_01e22084[i].type == a) n++;
        }
    } else if (c < 0) {
        for (i = 0; i < 512; i++) {
            if (D_01e22080[i].type == 19 && D_01e22084[i].type == a && D_01e22088[i].type == b) n++;
            if (D_01e22080[i].type == 43 && D_01e22084[i].type == a && D_01e22088[i].type == b) n++;
        }
    } else {
        for (i = 0; i < 512; i++) {
            if (D_01e22080[i].type == 19 && D_01e22084[i].type == a && D_01e22088[i].type == b && D_01e2208c[i].type == c) n++;
            if (D_01e22080[i].type == 43 && D_01e22084[i].type == a && D_01e22088[i].type == b && D_01e2208c[i].type == c) n++;
        }
    }
    return n;
}
}  // namespace n002b7440

// 002b788c (was src/anon/batch_w39_O0.cpp)
namespace n002b788c {
// --- 002b788c (built without optimisation)
int func_002b6708(int, int, int, int, int, int, int, int) asm("func_002b6708");
int func_002b788c(int a, int b, int c, int d) asm("_Z13func_002b788cPv");
/*TARGET 002b788c*/
int func_002b788c(int a, int b, int c, int d) asm("_Z13func_002b788cPv");
int func_002b788c(int a, int b, int c, int d) {
    return func_002b6708(7, 25, a, b, c, d, 1, 1);
}
}  // namespace n002b788c

// 002b78ec (was src/anon/batch_w207_O0.cpp)
namespace n002b78ec {
u32 func_002b6708(u32, u32, u32) asm("func_002b6708");
u32 w_002b78ec(u32 a) asm("_Z16wtarget_002b78ecjjjj");
/*TARGET 002b78ec*/
u32 w_002b78ec(u32 a) asm("_Z16wtarget_002b78ecjjjj");
u32 w_002b78ec(u32 a) { return func_002b6708(2, 26, a); }
}  // namespace n002b78ec

// 002b792c (was src/anon/batch_w35_O0.cpp)
namespace n002b792c {
s32 func_002b6708(s32, s32, ...) asm("func_002b6708");
/*TARGET 002b792c*/
s32 func_002b792c(u32 a, u32 b, u32 c) asm("func_002b792c");
s32 func_002b792c(u32 a, u32 b, u32 c) {
    return func_002b6708(4, 27, a, b, c);
}
}  // namespace n002b792c

// 002b797c (was src/anon/batch_w54_O0.cpp)
namespace n002b797c {
s32 func_002b6708(s32, s32, ...) asm("func_002b6708");
/*TARGET 002b797c*/
s32 func_002b797c(s32 a, s32 b, s32 c) asm("func_002b797c");
s32 func_002b797c(s32 a, s32 b, s32 c) {
    return func_002b6708(4, 28, a, b, c);
}
}  // namespace n002b797c

// 002b79cc (was src/anon/batch_w120_O0.cpp)
namespace n002b79cc {
struct Ent64 { s32 h[3]; u8 pad[52]; };
extern Ent64 D_01e22080[512] asm("D_01e22080");
void func_003058a0(s32) asm("func_003058a0");
s32 ctarget_002b79cc(s32 a, s32 b, s32 c) asm("_Z16ctarget_002b79ccjjjj");
/*TARGET 002b79cc*/
s32 ctarget_002b79cc(s32 a, s32 b, s32 c) asm("_Z16ctarget_002b79ccjjjj");
s32 ctarget_002b79cc(s32 a, s32 b, s32 c)
{
    s32 i;
    s32 cnt = 0;
    func_003058a0(0);
    if (c == 0) {
        if (b < 0) {
            for (i = 0; i < 512; i++)
                if (D_01e22080[i].h[0] == 29 && D_01e22080[i].h[1] == a) cnt++;
        } else {
            for (i = 0; i < 512; i++)
                if (D_01e22080[i].h[0] == 29 && D_01e22080[i].h[1] == a && D_01e22080[i].h[2] == b) cnt++;
        }
    } else if (c < 0) {
        for (i = 0; i < 512; i++)
            if (D_01e22080[i].h[0] == 25) cnt++;
    } else {
        for (i = 0; i < 512; i++)
            if (D_01e22080[i].h[0] == 25 && D_01e22080[i].h[1] == c) cnt++;
    }
    return cnt;
}
}  // namespace n002b79cc

// 002b7c34 (was src/anon/batch_w46_O0.cpp)
namespace n002b7c34 {
s32 func_002b6708(s32, s32, s32, s32, s32, s32) asm("func_002b6708");
/*TARGET 002b7c34*/
// Forwards to func_002b6708(5, 29, ...), capping d at 64 for large c.
s32 func_002b7c34(s32 a, s32 b, s32 c, s32 d) asm("func_002b7c34");
// Forwards to func_002b6708(5, 29, ...), capping d at 64 for large c.
s32 func_002b7c34(s32 a, s32 b, s32 c, s32 d) {
    if (c >= 14848) d = 64;
    return func_002b6708(5, 29, a, b, c, d);
}
}  // namespace n002b7c34

// 002b7ca4 (was src/anon/batch_w34_O0.cpp)
namespace n002b7ca4 {
u32 func_002b6708(u32, u32, ...) asm("func_002b6708");
/*TARGET 002b7ca4*/
u32 func_002b7ca4(u32 a, u32 b) asm("func_002b7ca4");
u32 func_002b7ca4(u32 a, u32 b) {
    return func_002b6708(3, 30, a, b);
}
}  // namespace n002b7ca4

// 002b7cec (was src/anon/batch_w47_O0.cpp)
namespace n002b7cec {
s32 func_002b6708(s32, s32, s32, s32, s32, s32) asm("func_002b6708");
/*TARGET 002b7cec*/
s32 func_002b7cec(s32 a, s32 b, s32 c, s32 d) asm("func_002b7cec");
s32 func_002b7cec(s32 a, s32 b, s32 c, s32 d) {
    if (c >= 14848) d = 64;
    return func_002b6708(5, 31, a, b, c, d);
}
}  // namespace n002b7cec

// 002b7d5c (was src/anon/batch_w53_O0.cpp)
namespace n002b7d5c {
s32 func_002b6708(s32, s32, s32, s32, s32, s32) asm("func_002b6708");
/*TARGET 002b7d5c*/
s32 func_002b7d5c(s32 a, s32 b, s32 c, s32 d) asm("func_002b7d5c");
s32 func_002b7d5c(s32 a, s32 b, s32 c, s32 d) {
    return func_002b6708(5, 32, a, b, c, d);
}
}  // namespace n002b7d5c

// 002b7db4 (was src/anon/batch_w57_O0.cpp)
namespace n002b7db4 {
u32 func_002b6708(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32) asm("func_002b6708");
/*TARGET 002b7db4*/
// Forward the eight caller arguments to the dispatcher with fixed ids 9/43.
u32 func_002b7db4(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h) asm("func_002b7db4");
// Forward the eight caller arguments to the dispatcher with fixed ids 9/43.
u32 func_002b7db4(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h) {
    return func_002b6708(9, 43, a, b, c, d, e, f, g, h);
}
}  // namespace n002b7db4

// 002b7e34 (was src/anon/batch_w207_O0.cpp)
namespace n002b7e34 {
u32 func_002b6708(u32, u32, u32) asm("func_002b6708");
/*TARGET 002b7e34*/
u32 func_002b7e34(u32 a) asm("func_002b7e34");
u32 func_002b7e34(u32 a) { return func_002b6708(2, 44, a); }
}  // namespace n002b7e34

// 002b7e74 (was src/anon/batch_w35_O0.cpp)
namespace n002b7e74 {
s32 func_002b6708(s32, s32, ...) asm("func_002b6708");
/*TARGET 002b7e74*/
s32 func_002b7e74(u32 a, u32 b) asm("func_002b7e74");
s32 func_002b7e74(u32 a, u32 b) {
    return func_002b6708(3, 45, b, a);
}
}  // namespace n002b7e74

// 002b7ebc (was src/anon/batch_w208_O0.cpp)
namespace n002b7ebc {
extern void* func_002b6708(int, int, void*) asm("func_002b6708");
/*TARGET 002b7ebc*/
void* func_002b7ebc(void* a) asm("func_002b7ebc");
void* func_002b7ebc(void* a) { return func_002b6708(2, 46, a); }
}  // namespace n002b7ebc

// 002b7efc (was src/anon/batch_w208_O0.cpp)
namespace n002b7efc {
extern void* func_002b6708(int, int, void*) asm("func_002b6708");
/*TARGET 002b7efc*/
void* func_002b7efc(void* a) asm("func_002b7efc");
void* func_002b7efc(void* a) { return func_002b6708(2, 47, a); }
}  // namespace n002b7efc

// 002b7f3c (was src/anon/batch_w54_O0.cpp)
namespace n002b7f3c {
s32 func_002b6708(s32, s32, ...) asm("func_002b6708");
/*TARGET 002b7f3c*/
s32 func_002b7f3c(s32 a, s32 b) asm("func_002b7f3c");
s32 func_002b7f3c(s32 a, s32 b) {
    return func_002b6708(3, 48, a, b);
}
}  // namespace n002b7f3c

// 002b7f84 (was src/anon/batch_w204_O0.cpp)
namespace n002b7f84 {
extern void* func_002b6708(int, int) asm("func_002b6708");
/*TARGET 002b7f84*/
void* func_002b7f84(void) asm("func_002b7f84");
void* func_002b7f84(void) { return func_002b6708(1, 49); }
}  // namespace n002b7f84

// 002b7fbc (was src/anon/batch_w207_O0.cpp)
namespace n002b7fbc {
u32 func_002b6708(u32, u32, u32) asm("func_002b6708");
/*TARGET 002b7fbc*/
u32 func_002b7fbc(u32 a) asm("func_002b7fbc");
u32 func_002b7fbc(u32 a) { return func_002b6708(2, 50, a); }
}  // namespace n002b7fbc

// 002b7ffc (was src/anon/batch_w207_O0.cpp)
namespace n002b7ffc {
u32 func_002b6708(u32, u32, u32) asm("func_002b6708");
/*TARGET 002b7ffc*/
u32 func_002b7ffc(u32 a) asm("func_002b7ffc");
u32 func_002b7ffc(u32 a) { return func_002b6708(2, 51, a); }
}  // namespace n002b7ffc

// 002b803c (was src/anon/batch_w206_O0.cpp)
namespace n002b803c {
s32 func_002b6708(s32, s32, s32) asm("func_002b6708");
/*TARGET 002b803c*/
s32 func_002b803c(s32 a) asm("func_002b803c");
s32 func_002b803c(s32 a) { return func_002b6708(2, 52, a); }
}  // namespace n002b803c

// 002b807c (was src/anon/batch_w2386_O0.cpp)
namespace n002b807c {
u32 func_002fdfc8(const char*, ...) asm("func_002fdfc8");
s32 func_002b803c(s32 a) asm("func_002b803c");
extern s32 D_01e22080[512][16] asm("D_01e22080");
/*TARGET 002b807c*/
// sound play slots, 64 bytes each

// 002b807c: with a == 0, print every active sound play slot; then forward a to func_002b803c.
void func_002b807c(s32 a) asm("func_002b807c");
// sound play slots, 64 bytes each

// 002b807c: with a == 0, print every active sound play slot; then forward a to func_002b803c.
void func_002b807c(s32 a)
{
    if (a) {
        // nothing extra here: the original jumps straight to the final call
    } else {
        func_002fdfc8("--- sound play list ---\n");
        for (s32 i = 0; i < 512; i++) {
            if (D_01e22080[i][0]) {
                func_002fdfc8("%03d com%2d bank%2d no%6d id%6d %x %x\n", i, D_01e22080[i][0], D_01e22080[i][1],
                              D_01e22080[i][2], D_01e22080[i][3], D_01e22080[i][4], D_01e22080[i][5]);
            }
        }
    }
    func_002b803c(a);
}
}  // namespace n002b807c

// 002b81b8 (was src/anon/batch_w203_O0.cpp)
namespace n002b81b8 {
/*TARGET 002b81b8*/
u32 func_002b81b8(u32 a, u32 b, u32 c, u32 d) asm("func_002b81b8");
u32 func_002b81b8(u32 a, u32 b, u32 c, u32 d) { return 0; }
}  // namespace n002b81b8

// 002b81ec (was src/anon/batch_w200_O0.cpp)
namespace n002b81ec {
/*TARGET 002b81ec*/
u32 func_002b81ec(void* a) asm("func_002b81ec");
u32 func_002b81ec(void* a) { return 0; }
}  // namespace n002b81ec

// 002b8214 (was src/anon/batch_wcx2_O0.cpp)
namespace n002b8214 {
/*TARGET 002b8214*/
// ---- 002b8214
s32 func_002b8214(s32 a) asm("func_002b8214");
// ---- 002b8214
s32 func_002b8214(s32 a) { return 0; }
}  // namespace n002b8214

