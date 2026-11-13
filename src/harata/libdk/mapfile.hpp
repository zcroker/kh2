#pragma once

#include "../../common/types.h"

class AREA;

namespace dk {

    // The map file of the current area (map/<lang>/<area>.map): a BAR whose entries hold the map
    // model, textures, collision and the background objects.
    class MapFile {
    public:
        struct BgObj { s32 model; s32 tex; s32 motionSet; };

        char name[32];       // 0
        u32 model;           // 32: the whole BAR (MAP model)
        u32 tex;             // 36
        u32 ocd, occ, och, ocl, owa, mon, bop, plx;  // 40-68
        u32 telopImd;        // 72
        u32 telopSqd;        // 76
        u32 pax;             // 80
        u32 radar[4];        // 84
        u32 mcl;             // 100
        u32 f104;            // 104
        s32 nSk0;            // 108
        s32 nSk1;            // 112
        s32 nBob;            // 116
        BgObj bgObj[96];     // 120
        s32 nRadar;          // 1272

        MapFile();
        ~MapFile() {}
        void clear(void);
        u32 getMapModelAddress(void);
        u32 getMapTexAddress(void);
        u32 getOcdAddress(void);
        u32 getOccAddress(void);
        u32 getOchAddress(void);
        u32 getOclAddress(void);
        u32 getOwaAddress(void);
        u32 getMonAddress(void);
        u32 getBopAddress(void);
        u32 getPlxAddress(void);
        u32 getTelopImdAddress(void);
        u32 getTelopSqdAddress(void);
        u32 getPaxAddress(void);
        u32 getRadarAddress(s32 a0);
        u32 getMclAddress(void);
        u32 get104(void);
        s32 getBgObjModelAddress(s32 a0);
        u32 getBgObjTexAddress(s32 a0);
        u32 getBgObjMotionSetAddress(s32 a0);
        void setAreaName(char* buf);
        static void buildMapFileName(const AREA* a0, char* a1);
        void setMapFile(void);
        void setMapFile(const char* s);
        void readRequest(void);
        void init(void);
        void exit(void);
    };

}  // namespace dk
