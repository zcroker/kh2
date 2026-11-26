#include "../common/types.h"

// ---- func_00199dc0 (-fno-strict-aliasing)
struct W1962Nd { u8 p[0x60]; W1962Nd* next; };
struct W1962Ent { u16 f0; u16 kind; u8 p4[0x3c]; };
struct W1962Ev { u32 id; u8 p4[0x18]; u8 mode; u8 p1d; u16 arg; u8 p20[0x20]; };
struct W1962Hdr { u8 type; u8 p1; u16 n2; u16 nev; u16 nent; };
struct W1962Chr { u8 p[4]; u8 kind; };
struct W1962Lst { W1962Nd* head; W1962Nd* tail; };
struct W1962Obj { u32 f0; u32 fl; W1962Hdr* hdr; W1962Lst lst; u32 f14; u32 f18; u32 f1c; u32 f20; W1962Ev* ev; W1962Ent* ent; };
extern "C" {
W1962Nd* YS__ZONE__Create(W1962Ent*);
s32 func_00199810(W1962Ev*);
W1962Chr* GetCharaData_0016e920(u32) asm("_ZN2Tz6JmInfo12GetCharaDataEj");
s32 Ti__MGObj__IsInitAppear(W1962Chr*);
void func_00199f90(W1962Obj*, W1962Ev*);
void func_0019ab30(W1962Obj*, u16);
void func_00199dc0(W1962Obj* o);  // 0x00199dc0: definition moved into src/anon/unit_00199688.cpp
}
