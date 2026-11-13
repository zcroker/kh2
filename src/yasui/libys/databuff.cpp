#include "databuff.hpp"

// YS::DATABUFF (0x1b13d8-0x1b14d8): a bump allocator over one 704 KB buffer for loaded files.
// Alloc rounds each file size up to 64 bytes; Read/ReadBar load a file into a fresh block.

u8* D_00350e88 = 0;  // next free byte (0 while closed)

static u8 s_buff[0xb0000] __attribute__((aligned(64)));

namespace YS {
class FILE {
public:
    static u32 GetSize(const char* name);
    static u32 ReadBar(const char* name, void* buf);
};
}  // namespace YS

extern "C" {
u32 func_001682b8(const char* name, void* buf);  // YS::FILE::Read

void func_001b13d8(void) { D_00350e88 = s_buff; }

void func_001b13f0(void) { D_00350e88 = 0; }
}

namespace YS {

u8* DATABUFF::Alloc(const char* name, int) {
    u32 size = (FILE::GetSize(name) + 63) & ~63;
    u8* p = 0;
    if (size) {
        u8* cur = D_00350e88;
        u8* keep = cur;
        D_00350e88 = cur + size;
        p = keep;
    }
    return p;
}

}  // namespace YS

extern "C" {

u8* func_001b1448(const char* name, int x) {
    u8* p = YS::DATABUFF::Alloc(name, x);
    if (p) func_001682b8(name, p);
    return p;
}

u8* func_001b1490(const char* name, int x) {
    u8* p = YS::DATABUFF::Alloc(name, x);
    if (p) YS::FILE::ReadBar(name, p);
    return p;
}

}
