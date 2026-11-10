#pragma once

#include "../../common/types.h"

namespace YS {

    class DAMAGE {
    public:
        static s32 GetReactionType(s32);
        u32 is_finish() const;
        s32 is_normal() const;
        u32 is_count_combo() const;
        u32 is_player_attack() const;
    };

}  // namespace YS

