#pragma once

#include "../../common/types.h"

namespace YS {

    class DATABUFF {
    public:
     static void Open(void);
     static void Close(void);
     static u8* Alloc(const char* name, int);
    };

}  // namespace YS
