#pragma once

#include "../../common/types.h"

namespace YS { class OBJ; }

namespace dk {

    class CannonCamera {
    public:
     static void create(YS::OBJ* obj);
     static void destroy();
    };

}  // namespace dk
