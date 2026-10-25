#pragma once

#include "../../common/types.h"

namespace YS {

    class TARGET {
    public:
        TARGET();  // 0x190128
        u32 is_valid() const;
        u32 is_exist() const;  // 0x190140

        u32 m_obj;   // 0
        u32 m_4;     // 4
        u32 m_8;     // 8
        s32 m_id;    // 12 (-1 when empty)
        u32 m_10;    // 16
    };

}  // namespace YS

