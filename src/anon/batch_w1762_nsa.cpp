#include "../common/types.h"

struct Node1762 { Node1762* next; s32 a; s32 b; u8* p; f32 x; f32 y; s32 c; };
struct List1762 { Node1762* head; Node1762* tail; };
extern List1762 D_01e2bf00;

typedef struct Key1762 { s32 a; s32 b; } Key1762;
typedef struct E1762 { s32 x; s32 a; s32 b; u8 pad[24]; } E1762;
typedef struct T1762 { u8 pad[12]; s32 n; E1762* e; } T1762;

extern "C" {
void func_002e73a8(Node1762*);

void func_002e7340(Node1762* n, s32 a, s32 b, u8* p, f32 x, f32 y);  // 0x002e7340: definition moved into src/anon/unit_002e5f70.cpp

E1762* func_001144e8(T1762* p, Key1762 k);  // 0x001144e8: definition moved into src/anon/unit_001142a0.cpp
}
