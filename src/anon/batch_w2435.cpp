#include "../common/types.h"

namespace w2435_002340f0 {
struct Sub { s32 c; s32 d; s32 e; };
struct Ent { s32 type; s32 id; s32 a; s32 b; Sub s; s32 f; };
}

extern "C" {

extern w2435_002340f0::Ent D_01dadc00[];
extern s32 D_0035e360;
extern s32 D_0035e368;
extern s32 D_0035e378;

/* Queue push: fills the next ring entry (64 slots) and returns its id. */
s32 func_002340f0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);  // 0x002340f0: definition moved into src/anon/unit_002335e8.cpp

}
