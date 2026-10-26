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
s32 func_002340f0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    using namespace w2435_002340f0;
    Ent* p = &D_01dadc00[D_0035e360];
    Sub* q = &p->s;
    s32 v;
    p->type = 2;
    p->a = a;
    p->b = b;
    q->c = c;
    p->id = D_0035e368;
    p->s.d = d;
    if (e) v = e; else v = D_0035e378;
    q->e = v;
    D_01dadc00[D_0035e360].f = f;
    D_0035e360 = (D_0035e360 + 1) & 63;
    return D_0035e368++;
}

}
