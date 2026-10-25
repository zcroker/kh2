#pragma once

#include "../../common/types.h"

namespace YS {

    class MUTEX {
    public:
        MUTEX() : m_bits(0) {}
        void lock(s32);
        void unlock(s32);
        u32 is_lock(s32);
        void clear() { m_bits = 0; }

    private:
        u32 m_bits;
    };

}  // namespace YS
