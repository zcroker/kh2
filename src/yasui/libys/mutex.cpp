
#include "mutex.hpp"

namespace YS {

void MUTEX::lock(s32 index) {
    m_bits |= 1u << index;
}

void MUTEX::unlock(s32 index) {
    m_bits &= ~(1u << index);
}

u32 MUTEX::is_lock(s32 index) {
    if (index == 0) {
        return (m_bits != 0);
    }
    u32 mask = 1u;
    mask <<= index;
    return ((m_bits & mask) != 0);
}

}  // namespace YS

// Three global mutexes (0x351eb8, 0x351ec0, 0x351ec8). Their constructors run from this
// file's static initialiser (0x1c8e00), called by _GLOBAL__I_D_00351eb8 (0x1c8e60, a .ctors entry).
YS::MUTEX D_00351eb8;
YS::MUTEX D_00351ec0;
YS::MUTEX D_00351ec8;

// Clears all three mutexes.
void func_001c8de0(void) {
    D_00351eb8.clear();
    D_00351ec0.clear();
    D_00351ec8.clear();
}
