#include "../common/types.h"

typedef void (*VFn)(void*);

extern "C" {
u8* func_00102818(u32, s32, u32, void*, s32);
void func_0014a0a0(void);
extern u32 D_0032b96c;
void TitleStart(bool) asm("_ZN2dk5Field10TitleStartEb");

extern void* D_0034a42c;
int func_00150bc0(void*);
void func_00150940(void*, u32);
void func_001507b8(void*, u32);

u32 func_00154ee8(void*);  // field24_state_code
void func_00138c10(void*, u32);
void func_00154408(void*, u32);

void func_00167658(void*, int);
u64 func_00167cd0(void*);



extern u8 D_01c5f480[];
void func_001a7888(void*, u32, int, f32, f32);
void* func_001a78c0(void*, u32, int, f32, f32, f32, f32);
void func_001a7a48(void*, u32, int, f32, f32);
void func_001a7da8(void*, void*, f32, f32);

void* func_0016a070(void*);
u32 func_001afee8(void*, int);
void func_00198630(void*, u32, int);
void voice_part(void*, int) asm("_ZN2YS5PARTY10voice_partEi");

void func_00179f10(void*);
void func_001d6ab0(u32);


void** func_0017aab8(int);

extern u8* D_01c6cb90;

void func_001ad280(void*);
extern void* D_00350a70[];
extern u8 D_00350a56;
void func_001c1130(int);  // copy_record_block_to_table
void func_0014c9d8(int);

int func_001c9ab8(void*);
int func_001c99b0(int);

extern u8* D_01d5baa8;
void* func_00185da8(void*);
int func_0019c410(void*);

extern void* D_00352bd0;
void func_001e2898(void*);
void func_00105110(void*);

extern char D_00370bd8[];
extern char D_00370bf8[];
void func_002fdfc8(const char*, ...);  // device_vprintf_va

extern u32 D_0033caf4;
extern char D_01dad960[];
extern char D_00371190[];
void func_002fee78(char*, const char*, ...);
void strlen(char*);  // strlen
}

// Queue a target-event entry into the 64-slot ring; returns its serial number.
extern "C" {
extern u32 D_0035e360;
extern u32 D_0035e368;
struct TargetEv { u32 active, serial, a, b, c, pad[3]; };
extern TargetEv D_01dadc00[];
}
u32 wtarget_00234098(u32 a, u32 b, u32 c, u32 d);  // 0x00234098: definition moved into src/anon/unit_002335e8.cpp

extern "C" {
u8* func_00294000(int);
int func_00295158(u32);
u32* func_002b23e0(int);  // list_entry_by_index_checked
extern u32 D_00374ca4;
extern u32 D_00374ca8;
extern char D_01e2a5a8[];
extern char D_00374f80[];
extern void* D_003621a0[];
void func_002e7328(void*);  // to_2e7458
void func_002d2a08(void*);
void func_002cfeb0(void*, u32, int, u32);  // obj_init_field1416_bit800
extern void* D_003627c8[];
void func_002cf280(void*, int, int);
u8* func_002dc7c8(void*);
extern void* D_00362eb8[];
void func_002e70b0(void*);
void func_00106420(void*);
void func_002cea28(void*);
void func_00106450(void*);
void func_001d3698(void*, u32);
extern u8 D_01e2bf80[];
void func_00195858(void*, int);
extern void* D_00347f98[];
extern u8* D_00347f80;
extern void* D_0034ee08[];
void func_0019f9a8(void*);  // array8_free_slots
void func_001c0248(void*);
void func_00319fb0(void*);  // big_obj_dtor
extern void* D_00363880[];
extern void* D_003637e0[];
void func_0023c098(void*);  // set_vtbl_36eae8_then_call
void func_002369f0(void*);  // set_vtbl_36eac8_then_call


// dk Field: start the title task.
void TitleStart(bool flag);  // 0014a138: moved to src/anon/unit_00149fa8.cpp

void func_0014f578(u32 a);  // 0x0014f578: definition moved into src/anon/unit_0014ecb8.cpp

// 00155410: moved to src/anon/unit_00153ea0.cpp
void func_00155410(u8* p);

// 00167e28: moved to src/anon/unit_00167358.cpp

void func_00173558(u8* p);  // 0x00173558: definition moved into src/anon/unit_00171e58.cpp

void func_001735b0(u8* p);  // 0x001735b0: definition moved into src/anon/unit_00171e58.cpp

// 00176d68: moved to src/yasui/libys/party.cpp

typedef int (*VFn4)(void*, u32, int, int);
// 00179f80: moved to src/yasui/libys/player.cpp

typedef void (*VFn3)(void*, void*, u32);
void* func_001a07b0(void* p, u32 a, u32 b);  // 0x001a07b0: definition moved into src/anon/unit_0019fb70.cpp

// 001a78c0: moved to src/yasui/libys/bg.cpp

// Find the 24-byte table entry whose u16 id matches.
// 001a80c8: moved to src/anon/unit_001a8098.cpp

// 001ad5a8: moved to src/anon/unit_001abb28.cpp

int func_001c9b38(u8* p);  // 0x001c9b38: definition moved into src/yasui/libys/sacrifice.cpp

int func_001ca448(u8* p);  // 0x001ca448: definition moved into src/anon/unit_001ca148.cpp

// Next 10-byte entry after e (or the first when e is null); null past the end.
u8* func_001d9e30(u8* e);  // 0x001d9e30: definition moved into src/anon/unit_001d9d00.cpp

void func_001dbb38(void);  // 0x001dbb38: definition moved into src/anon/unit_001d9d00.cpp

// Look up key in a 32-byte record table; outputs the record's first two words.
bool func_001dc018(u8** p, s32 key, u32* a, u32* b);  // 0x001dc018: definition moved into src/anon/unit_001dbfd8.cpp

void func_001e2998(void);  // 0x001e2998: definition moved into src/anon/unit_001e0cb8.cpp

// Print two messages and trap.
void func_002233f0(u32 a, u32 b, u32 c);  // 0x002233f0: definition moved into src/anon/unit_00222aa8.cpp

char* func_0022c4b8(u32 x);  // 0022c4b8: moved to src/sasa/event_layout.cpp (linked unit)

struct KV { s16 k; u16 v; };
extern KV D_00372be0[];
// Map key to value through a table terminated by a negative key; -1 if absent.
int func_002594b8(int k);  // 0x002594b8: definition moved into src/anon/unit_002588e8.cpp

void* memset_(void*, int, u32) asm("func_002fde18");
void func_00281f90(u8* p);  // 0x00281f90: definition moved into src/anon/unit_00281cf0.cpp

s8 func_00295228(u32 x);  // 0x00295228: definition moved into src/anon/unit_00292e60.cpp

u32 func_002b1aa0(void);  // 0x002b1aa0: definition moved into src/anon/unit_002b0950.cpp

char* func_002ba0f8(u32 x);  // 0x002ba0f8: definition moved into src/anon/unit_002b9ab8.cpp

extern u32 D_01e2aa80;
static inline u8* nextNode(u8* n) {
    if (!n) return (u8*)D_01e2aa80;
    return *(u8**)(n + 28);
}
// Clear flag 4 on every list node whose type byte is 2.
void func_002bbe80(void);  // 0x002bbe80: definition moved into src/anon/unit_002bb8b0.cpp

void func_002d4828(void** p);  // 0x002d4828: definition moved into src/anon/unit_002d4548.cpp

void func_002dac50(u8* p, u32 a, u32 b);  // 0x002dac50: definition moved into src/anon/unit_002da040.cpp

f32 func_002dc808(u8* p);  // 0x002dc808: definition moved into src/anon/unit_002da040.cpp

// Empty-destructor local: keeps the final call from becoming a tail call.
struct NoTail { ~NoTail() {} };
// 002e2298: moved to src/anon/unit_002e1908.cpp

void operator delete[](void*) asm("func_00106450");
struct Elem64 { u8 d[64]; ~Elem64() {} } __attribute__((aligned(16)));
// delete[] of an array of 64-byte elements with an empty destructor.
void func_002e7058(u8* p);  // 0x002e7058: definition moved into src/anon/unit_002e5f70.cpp

void func_002e8578(u8* p);  // 0x002e8578: definition moved into src/anon/unit_002e7b10.cpp

typedef void (*VFn2)(void*, void*);
void func_002ece48(void** p, u8* q);  // 0x002ece48: definition moved into src/anon/unit_002ecdb0.cpp

// Unpack a single-precision float into class/sign/exponent/fraction.
void func_00314640(u32* in, s32* out) {
    u32 v = *in;
    u32 frac = v & 0x7fffff;
    out[1] = v >> 31;
    u32 exp = (v >> 23) & 0xff;
    if (exp == 0) {
        out[0] = 2;
        return;
    }
    out[2] = exp - 127;
    out[0] = 3;
    out[3] = (frac << 7) | 0x40000000;
}

void func_0031c0b8(void** p) {
    *p = D_00347f98;
    void* o = *(void**)(D_00347f80 + 20);
    (*(VFn2*)(*(u8**)o + 4))(o, p);
}

void func_003218c8(void** p) {
    NoTail g;
    *p = D_0034ee08;
    func_0019f9a8((u8*)p + 2568);  // array8_free_slots
    func_001c0248((u8*)p + 2640);
    func_00319fb0(p);  // big_obj_dtor
}

void func_00321910(void** p) {
    *p = D_0034ee08;
    func_0019f9a8((u8*)p + 2568);  // array8_free_slots
    func_001c0248((u8*)p + 2640);
    func_00319fb0(p);  // big_obj_dtor
    func_00105110(p);
}

void func_00325ae8(void** p) {
    *p = D_00363880;
    func_0023c098((u8*)p + 64);  // set_vtbl_36eae8_then_call
    func_002369f0((u8*)p + 40);  // set_vtbl_36eac8_then_call
    *p = D_003637e0;
    func_00106420(p);
}
}
