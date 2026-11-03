#include "../common/types.h"
// Two 16-byte slots at 0x347d30 (setters 0x136b48/0x136b60/0x136b78 write fields 0/4/8 by index).
struct Slot347d30 {
    s32 id;
    void* p4;
    void* p8;
    s32 flags;
    // id is cleared through a plain int store (no field info), which only aliases the int fields
    void Clear() { *(s32*)this = 0; p4 = 0; p8 = 0; }
};
extern "C" {
extern Slot347d30 D_00347d30[2];
void func_00136a98(void);
// Clears both slots, then resets the rest of the block.
void func_00136ab8(void) {
    D_00347d30[0].flags = 0;
    D_00347d30[0].Clear();
    D_00347d30[1].Clear();
    D_00347d30[1].flags = 0;
    func_00136a98();
}
}
