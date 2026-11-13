#include "../common/types.h"
extern "C" {
struct Node { u32 pos[4]; u32 f10, f14; f32 f18, f1c, f20; u32 f24; f32 f28, f2c; Node* next; };
struct NodeList { Node* head; Node* tail; };
extern NodeList D_01d5ba20;
// 001d37a0: moved to src/anon/unit_001d35e0.cpp
}
