#pragma once

#include "../../common/types.h"

namespace YS {

    class FILE {
    public:
        static u32 ReadBar(const char*, void*);
        static u32 IsReading(void);
        static u32 GetSize(const char*);
    };

}  // namespace YS

