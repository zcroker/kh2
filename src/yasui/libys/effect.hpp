#pragma once

#include "../../common/types.h"

namespace ryj { struct PAX; class EFFECT; }

namespace YS {

class EFFECT {
public:
    static void Read(void);
    static ryj::PAX* GetSystemPax(void);
    static void Init(void);
    static void Ensure(void);
    static void Exec(void);
    static void AddDeadEffect(ryj::EFFECT* a0);
};

} // namespace YS
