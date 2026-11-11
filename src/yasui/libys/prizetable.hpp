#pragma once

#include "../../common/types.h"

namespace YS {

    class PRIZETABLE {
    public:
        static void Init(void* a0);
        static void* Get(s32 a0);
        s32 get_num(s32 a0, f32 a1);
    };

}  // namespace YS
