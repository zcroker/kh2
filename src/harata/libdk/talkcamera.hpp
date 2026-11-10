#pragma once

#include "../../common/types.h"
#include "../../common/task.hpp"

namespace dk {

    class ObjCamera;

    class TalkCamera {
    public:
     static void update(ObjCamera* a0);
     static void ensureTask(TASK* a0);
    };

}  // namespace dk

