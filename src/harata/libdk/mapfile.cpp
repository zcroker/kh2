#include "mapfile.hpp"

// dk::MapFile (0x1491a8-0x149be8): builds the map file name for an area, reads the file through
// the cache buffer, and finds its entries.

struct BAR_ENT { u8 pad[8]; u32 data; };

extern "C" {
extern AREA D_0032bae0;          // the current area
extern const char* D_0033caf4;   // the voice language ("jp", "us", ...)
const char* func_00105140(const AREA*, s32);  // AREA::GetName
void func_002fee78(char*, const char*, ...);  // sprintf
u32 func_002ff3fc(const char*);              // strlen
void func_002ff2e8(char*, const char*);      // strcpy
s32 func_00168aa0(u32, s32);
void func_00168ad8(u32, s32*, s32, u32);
BAR_ENT* func_00168b38(u32, s32, s32);
BAR_ENT* func_00168b88(u32, s32, u32, s32);
}
u32 CacheBuffAlloc(const char*, s32) asm("_ZN2YS10CACHE_BUFF5AllocEPKci");
void CacheBuffReadRequest(const char*, s32, s32) asm("func_00170518");
void CacheBuffFree(u32) asm("func_00170950");

static inline u32 Tag(const char* s) { return s[0] | s[1] << 8 | s[2] << 16 | s[3] << 24; }
static inline BAR_ENT* GetEnt(u32 bar, s32 t, const char* s, s32 i) { return func_00168b88(bar, t, Tag(s), i); }

namespace dk {

MapFile::MapFile() {
    clear();
}

void MapFile::clear(void) {
    model = 0;
    tex = 0;
    ocd = 0;
    occ = 0;
    och = 0;
    ocl = 0;
    owa = 0;
    mon = 0;
    bop = 0;
    plx = 0;
    telopImd = 0;
    telopSqd = 0;
    pax = 0;
    mcl = 0;
    f104 = 0;
    nSk0 = 0;
    nSk1 = 0;
    nBob = 0;
    nRadar = 0;
    name[0] = 0;
    for (s32 i = 0; i < 96; i++) {
        bgObj[i].model = 0;
        bgObj[i].tex = 0;
        bgObj[i].motionSet = 0;
    }
    for (s32 i = 0; i < 4; i++) radar[i] = 0;
}

u32 MapFile::getMapModelAddress(void) { return model; }
u32 MapFile::getMapTexAddress(void) { return tex; }
u32 MapFile::getOcdAddress(void) { return ocd; }
u32 MapFile::getOccAddress(void) { return occ; }
u32 MapFile::getOchAddress(void) { return och; }
u32 MapFile::getOclAddress(void) { return ocl; }
u32 MapFile::getOwaAddress(void) { return owa; }
u32 MapFile::getMonAddress(void) { return mon; }
u32 MapFile::getBopAddress(void) { return bop; }
u32 MapFile::getPlxAddress(void) { return plx; }
u32 MapFile::getTelopImdAddress(void) { return telopImd; }
u32 MapFile::getTelopSqdAddress(void) { return telopSqd; }
u32 MapFile::getPaxAddress(void) { return pax; }
u32 MapFile::getRadarAddress(s32 i) { return radar[i]; }
u32 MapFile::getMclAddress(void) { return mcl; }
u32 MapFile::get104(void) { return f104; }
s32 MapFile::getBgObjModelAddress(s32 i) { return bgObj[i].model; }
u32 MapFile::getBgObjTexAddress(s32 i) { return bgObj[i].tex; }
u32 MapFile::getBgObjMotionSetAddress(s32 i) { return bgObj[i].motionSet; }

void MapFile::setAreaName(char* buf) {
    buildMapFileName(&D_0032bae0, buf);
}

void MapFile::buildMapFileName(const AREA* area, char* buf) {
    func_002fee78(buf, "map/%s/%s.map", D_0033caf4, func_00105140(area, 0));
    func_002ff3fc(buf);
}

void MapFile::setMapFile(void) {
    if (!name[0]) setAreaName(name);
}

void MapFile::setMapFile(const char* s) {
    func_002ff3fc(s);
    func_002ff2e8(name, s);
}

void MapFile::readRequest(void) {
    CacheBuffReadRequest(name, 1070, 0);
}

// Reads the MAP/SK0/SK1/BOB entries and the other typed entries and the radar list.
void MapFile::init(void) {
    char map[4] = "MAP";
    char sk0[4] = "SK0";
    char sk1[4] = "SK1";
    char bob[4] = "BOB";
    u32 bar = CacheBuffAlloc(name, -1);
    clear();
    model = bar;
    func_00168b88(bar, 4, Tag(map), 0);
    GetEnt(model, 4, map, 0);
    tex = GetEnt(model, 4, map, 0)->data;
    if (GetEnt(model, 7, map, 0)) ocd = GetEnt(model, 7, map, 0)->data;
    func_00168b38(model, 5, 0);
    func_00168b38(model, 5, 0);
    occ = func_00168b38(model, 5, 0)->data;
    if (func_00168b38(model, 6, 0)) och = func_00168b38(model, 6, 0)->data;
    if (func_00168b38(model, 11, 0)) ocl = func_00168b38(model, 11, 0)->data;
    func_00168ad8(model, &nBob, 4, Tag(bob));
    func_00168ad8(model, &nSk0, 4, Tag(sk0));
    func_00168ad8(model, &nSk1, 4, Tag(sk1));
    s32 n = 0;
    s32 i;
    s32 j;
    for (i = 0; i < nSk0; i++, n++) {
        bgObj[n].model = GetEnt(model, 4, sk0, 0)->data;
        bgObj[n].tex = GetEnt(model, 7, sk0, 0)->data;
    }
    for (i = 0; i < nSk1; i++, n++) {
        bgObj[n].model = GetEnt(model, 4, sk1, 0)->data;
        bgObj[n].tex = GetEnt(model, 7, sk1, 0)->data;
    }
    for (j = 0; j < nBob; j++, n++) {
        bgObj[n].model = GetEnt(model, 4, bob, j)->data;
        if (GetEnt(model, 7, bob, j)) bgObj[n].tex = GetEnt(model, 7, bob, j)->data;
        if (GetEnt(model, 30, bob, j)) bgObj[n].motionSet = GetEnt(model, 30, bob, j)->data;
    }
    if (func_00168b38(model, 14, 0)) telopSqd = func_00168b38(model, 14, 0)->data;
    if (func_00168b38(model, 15, 0)) owa = func_00168b38(model, 15, 0)->data;
    if (func_00168b38(model, 19, 0)) mon = func_00168b38(model, 19, 0)->data;
    if (func_00168b38(model, 39, 0)) bop = func_00168b38(model, 39, 0)->data;
    if (func_00168b38(model, 18, 0)) pax = func_00168b38(model, 18, 0)->data;
    if (func_00168b38(model, 21, 0)) plx = func_00168b38(model, 21, 0)->data;
    if (func_00168b38(model, 27, 0)) telopImd = func_00168b38(model, 27, 0)->data;
    if (func_00168b38(model, 24, 0)) mcl = func_00168b38(model, 24, 0)->data;
    if (func_00168b38(model, 25, 0)) f104 = func_00168b38(model, 25, 0)->data;
    nRadar = func_00168aa0(model, 10);
    for (s32 t = 0; t < nRadar; t++) radar[t] = func_00168b38(model, 10, t)->data;
}

void MapFile::exit(void) {
    CacheBuffFree(model);
}

}  // namespace dk
