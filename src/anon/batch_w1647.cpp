#include "../common/types.h"
struct W1647V4 {
    f32 x, y, z, w;
    W1647V4() {}
    W1647V4(f32 a, f32 b, f32 c, f32 d) : x(a), y(b), z(c), w(d) {}
    W1647V4& operator=(const W1647V4& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    W1647V4 operator-(const W1647V4& o) const {
        W1647V4 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    W1647V4& operator-=(const W1647V4& o) {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "memory");
        return *this;
    }
    f32 dot(const W1647V4& o) const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(this), "r"(&o) : "$8", "memory");
        return r;
    }
    f32 normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));

// UNIT_DATA_OBJ entries (0x40 bytes each)
struct W1647V3 { f32 x, y, z; };
struct W1647Unit { u8 pad0[4]; W1647V3 pos; u8 pad10[0xe]; u16 id; u8 pad20[0x20]; };
struct W1647UnitHdr { u8 pad0[4]; u16 count; u8 pad6[0x16]; f32 range; u8 pad20[0xc]; W1647Unit units[1]; };
struct W1647Group { u8 pad0[8]; W1647UnitHdr* hdr; };
struct W1647Obj;
struct W1647ObjVt { void* f[8]; void (*kill)(W1647Obj*); };
struct W1647Obj { W1647ObjVt* vt; };

extern "C" {
W1647Obj* func_0016b7a0(u16);
W1647V4* func_0016c028(void*);
void func_0016af58(W1647V4*, void*);
s32 func_00195700(void*, u16);
f32 func_002f8870(f32);
void W1647_appear(W1647Unit*, W1647Group*) asm("_ZNK2YS13UNIT_DATA_OBJ6appearEPNS_10UNIT_GROUPE");
extern void* D_0034e948;
extern u8 D_0034f250[];

/* 0019b668: per frame, despawns live units of a YS::UNIT_GROUP that are far away or behind the player, and spawns (appear) nearby dead ones in front. */
void func_0019b668(W1647Group* g)
{
    s32 i = 0;
    W1647UnitHdr* h = g->hdr;
    void* player = D_0034e948;
    W1647Unit* u = h->units;
    for (; i < h->count; i++, u++) {
        W1647V4 d;
        W1647Obj* o = func_0016b7a0(u->id);
        if (o != 0) {
            d = *func_0016c028(o) - *func_0016c028(player);
            f32 dist = func_002f8870((func_002f8870(d.x) > func_002f8870(d.z)) ? d.x : d.z);
            if (g->hdr->range < dist) {
                o->vt->kill(o);
            } else if (1000.0f < dist) {
                d.normalize();
                W1647V4 t;
                func_0016af58(&t, player);
                if (d.dot(t) < -0.7f) o->vt->kill(o);
            }
        } else if (func_00195700(D_0034f250, u->id) == 0) {
            f32 px = u->pos.x, py = u->pos.y, pz = u->pos.z;
            d.x = px; d.y = py; d.z = pz; d.w = 0.0f;
            d -= *func_0016c028(player);
            if (func_002f8870(d.x) > func_002f8870(d.z)) {
                if (!(func_002f8870(d.x) < g->hdr->range)) goto next;
            } else {
                if (!(func_002f8870(d.z) < g->hdr->range)) goto next;
            }
            {
                d.normalize();
                W1647V4 t;
                func_0016af58(&t, player);
                if (-0.7f < d.dot(t)) W1647_appear(u, g);
            }
        }
    next:
        h = g->hdr;
    }
}
}
