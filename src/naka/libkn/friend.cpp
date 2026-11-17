#include "friend.hpp"

extern u32 Friend_getPartner_raw(u32) asm("_Z16wtarget_00111d98jjjj");
extern void Friend_followMove(void*, void const*) asm("_ZN2kn6Friend10followMoveEPKNS_6VecSetE");
extern void ObjObserver_Create(void*) asm("_ZN2kn11ObjObserver6CreateEPPS0_");

namespace kn {
class Friend;
class VecSet;
typedef int (*FriendCallback)(Friend*, int);
extern u32 D_00341708 asm("D_00341708");


// 0x0010c778: definition moved into src/anon/unit_0010b978.cpp

// 0x0010c7e8: definition moved into src/anon/unit_0010b978.cpp
// 0x00112758: definition moved into src/anon/unit_001117d8.cpp
// 0x00110618: definition moved into src/anon/unit_0010fea0.cpp
// 0x00111e20: definition moved into src/anon/unit_001117d8.cpp
// 0x00111e38: definition moved into src/anon/unit_001117d8.cpp
// 0x00112778: definition moved into src/anon/unit_001117d8.cpp
}  // namespace kn
