#include "../common/types.h"
extern "C" {
struct W2398Lim { u8 pad[0x50]; f32 l50, l54, l58, l5c, l60, l64; };
struct W2398El { u8 b[7]; u8 a; };
struct W2398Own {
    void* h;
    u8 pad4[0x30];
    W2398El* el;
    u8 pad38[0xdc];
    W2398Lim* lim;
};
void func_0011c7c8(void*, s32);
void func_0011c7f8(void*, s32);

/* Sets the alpha of three elements from t against three [low, high] ranges:
   0 above high, 0x80 below low, fading in between. One shared ratio variable. */
void func_00148690(void* self, W2398Own* p, f32 t);  // 0x00148690: definition moved into src/anon/unit_00147140.cpp
}
