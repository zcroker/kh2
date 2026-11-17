#include "../common/types.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec;
typedef struct Node {
    u8 pad0[4];
    s32 type;
    u8 pad8[0x14];
    s32 id;
    u8 pad20[8];
    struct Node* next;
} Node;
typedef struct { Node* head; Node* tail; } NodeList;
extern s32 D_00352ae8;
struct Alloc;
typedef struct {
    void* (*alloc)(struct Alloc*, s32, s32);
    void (*free)(struct Alloc*, void*);
} AllocVt;
typedef struct Alloc { AllocVt* vt; } Alloc;
extern NodeList D_00352ae0;
extern Alloc* D_01d5bb00;
u8* func_00106a60(s32);
f32* func_001dc5f0(Node*);
Vec* func_001dc5f8(Node*);
s32 func_001dc9d0(Node*);
s32 func_001e3590(s32);
s32 func_001e35f0(s32);
void func_001dd568(Node**, f32*, s32, s32);

static inline Node* nextNode(Node* n) { if (!n) return D_00352ae0.head; return n->next; }

/* Depth-sort the effect node list: compute a key per node, sort, relink. */
void func_001dd6a0(void)
{
    Node** nodes;
    f32* keys;
    Vec* view;
    Node* n;
    s32 i;
    f32 farZ;
    if (D_00352ae8 < 2) return;
    farZ = 1000000.0f;
    n = 0;
    i = 0;
    nodes = (Node**)D_01d5bb00->vt->alloc(D_01d5bb00, D_00352ae8 * 4, 0);
    keys = (f32*)D_01d5bb00->vt->alloc(D_01d5bb00, D_00352ae8 * 4, 0);
    view = (Vec*)(func_00106a60(0) + 16);
    for (; (n = nextNode(n)) != 0; i++) {
        s32 v;
        nodes[i] = n;
        if (n->type == 4) {
            f32* q = func_001dc5f0(n);
            keys[i] = q[1];
        } else if (func_001dc9d0(n)) {
          if ((v = func_001e3590(n->id)) != 0) {
            keys[i] = farZ - (f32)v;
          } else if ((v = func_001e35f0(n->id)) != 0) {
            keys[i] = (f32)v + 0.0f;
          } else {
            Vec r;
            Vec* p = func_001dc5f8(n);
            /* VU0 macro code: transform point by view matrix */
            asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%1)\n\tlqc2 $vf1, 0(%2)\n\tlqc2 $vf2, 16(%2)\n\tlqc2 $vf3, 32(%2)\n\tlqc2 $vf4, 48(%2)\n\t"
                 "vmulax.xyz ACC, $vf1, $vf5x\n\tvmadday.xyz ACC, $vf2, $vf5y\n\tvmaddaz.xyz ACC, $vf3, $vf5z\n\t"
                 "vmaddw.xyz $vf5, $vf4, $vf0w\n\tvmove.w $vf5, $vf0\n\tsqc2 $vf5, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(p), "r"(view) : "memory");
            keys[i] = r.z;
          }
        } else {
            keys[i] = 0.0f;
        }
    }
    func_001dd568(nodes, keys, 0, D_00352ae8 - 1);
    D_00352ae0.head = 0;
    D_00352ae0.tail = 0;
    for (i = 0; i < D_00352ae8; i++) {
        Node* p = nodes[i];
        if (D_00352ae0.tail == 0) {
            D_00352ae0.tail = p;
            D_00352ae0.head = p;
            p->next = 0;
        } else {
            D_00352ae0.tail->next = p;
            p->next = 0;
            D_00352ae0.tail = p;
        }
    }
    D_01d5bb00->vt->free(D_01d5bb00, nodes);
    D_01d5bb00->vt->free(D_01d5bb00, keys);
}
