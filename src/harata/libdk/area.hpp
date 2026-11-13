#pragma once

#include "../../common/types.h"

class AREA;

namespace dk {

class Area {
public:
    static void setMapFile(char* a0);
    static void readData(void);
    static void initMap(u32 a0);
    static void init(void);
    static void start(void);
    static void exit(void);
    static void cacheBuffDestroy(AREA* a0);
    static void finalizer(AREA* a0);
};

}  // namespace dk
