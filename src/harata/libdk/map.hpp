#pragma once

#include "../../common/types.h"
#include "../../naka/libkn/animation.hpp"

namespace dk {

    class Map {
    public:
        static void setHideGroup(u32 group);
        static void setVisibleGroup(u32 group);
        static u32 isPaxExist();
        static void* getPax();
        static void setAnimationSpeedRatio(kn::AnimationWork::TYPE type, f32 ratio);
    };

}  // namespace dk
