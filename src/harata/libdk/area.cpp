#include "area.hpp"
#include "mapfile.hpp"

// dk::Area (0x149be8-0x149fa8): reads the current area's map file and starts and ends the
// area's systems.

extern "C" {
extern u8 D_0032bae0;     // the current area (AREA; first byte is the world)
extern u8 D_0032bb10;     // the previous area
extern u32 D_0034b278;
void func_0013a600(void);
void func_0013a4c8(void);
void func_0015c228(u32);
u32 func_001050c8(void);
void func_0015eba8(dk::MapFile*, u32, u32, u32);
void func_0013dd28(void);
void func_0013a6f8(void);
void func_00103bb0(s32);
void func_00139f38(u32);
void func_00153c60(void);
void func_001385c0(void);
void func_00109e18(void);
void func_0015df68(void);
void func_00140ce8(void);
void func_00161ee8(void);
void func_001618f0(void);
void func_001618b8(void);
void func_0015a810(void);
void func_0014f268(dk::MapFile*);
void func_0014f1c8(dk::MapFile*);
void func_0014f208(void);
void func_0014f118(void);
void func_0013d7d0(void);
s32 func_001051a0(void*, void*);
s32 func_001bc130(void);
void func_0015b2d0(void);
void func_0013d7c0(void);
u32 func_0015dfd8(void);
s32 func_00242ea8(void);
void func_001703a8(s32);
void func_002bea00(void);
void func_002bea10(void);
void func_0015a850(void);
void func_00153c80(void);
void func_0014f148(void);
void func_0014f220(void);
void func_0014f1e0(void);
void func_0014f288(void);
void func_0015edb8(void);
void func_00165968(void);
}

dk::MapFile D_00348d68;
#define s_mapFile D_00348d68

namespace dk {

void Area::setMapFile(char* name) {
    s_mapFile.setMapFile(name);
}

void Area::readData(void) {
    func_0013a600();
    func_0013a4c8();
    s_mapFile.setMapFile();
    s_mapFile.readRequest();
}

void Area::initMap(u32 a) {
    s_mapFile.init();
    func_0015c228(s_mapFile.getPlxAddress());
    func_0015eba8(&s_mapFile, func_001050c8(), 1, a);
}

void Area::init(void) {
    func_0013dd28();
}

void Area::start(void) {
    func_0013a6f8();
    func_00103bb0(-1);
    func_00139f38(func_001050c8());
    D_0034b278 = func_001050c8();
    func_00153c60();
    func_001385c0();
    func_00109e18();
    func_0015df68();
    func_00140ce8();
    func_00161ee8();
    func_001618f0();
    func_001618b8();
    func_0015a810();
    func_0014f268(&s_mapFile);
    func_0014f1c8(&s_mapFile);
    func_0014f208();
    func_0014f118();
    func_0013d7d0();
    if (func_001051a0(&D_0032bae0, &D_0032bb10) == 0 && func_001bc130() != 0) {
        func_0015b2d0();
        func_0013d7c0();
    }
}

void Area::exit(void) {
    func_0015dfd8();
    D_0034b278 = 0;
}

void Area::cacheBuffDestroy(AREA* a) {
    u8* p = (u8*)a;
    if (func_00242ea8()) return;
    if (!func_001051a0(&D_0032bae0, p)) func_001703a8(1070);
    if (*p != D_0032bae0) {
        func_001703a8(900);
        func_001703a8(950);
        func_001703a8(1080);
        func_001703a8(1090);
    }
    func_002bea00();
    if (D_0032bae0 != 15) return;
    if (*p != D_0032bae0) {
        func_001703a8(1040);
        func_001703a8(1040);
        func_001703a8(2500);
    } else {
        func_002bea10();
    }
}

void Area::finalizer(AREA* a) {
    func_0015a850();
    func_00153c80();
    func_0014f148();
    func_0014f220();
    func_0014f1e0();
    func_0014f288();
    func_0015edb8();
    func_00165968();
    s_mapFile.exit();
    cacheBuffDestroy(a);
}

}  // namespace dk
