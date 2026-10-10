#include "../common/types.h"

struct V4w258 {
    f32 x, y, z, w;
    V4w258() {}
    V4w258(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    V4w258& operator=(const V4w258& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V4w258 operator-(const V4w258& b) const {
        V4w258 d;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&d), "r"(this), "r"(&b) : "memory");
        return d;
    }
    V4w258 operator*(f32 k) const {
        V4w258 d;
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&d), "r"(this), "f"(k) : "$8", "memory");
        return d;
    }
    f32 len() const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(this) : "$8");
        return r;
    }
} __attribute__((aligned(16)));
struct Seg258 { V4w258 a, b; };
struct Rail258 { u8 p0[8]; s32 n; u8 p1[12]; f32 f18; u8 p2[12]; f32 f28; u8 p3[4]; V4w258 a0, b0, a1, b1; };
struct Box3w258 { f32 mn[3]; f32 mx[3]; };

extern "C" {
extern u8* D_0035f20c;
void u_call4_00139d78(u8*) asm("_Z16u_call4_00139d78jjjj");
s32 func_00259510(s32);
u8* u_tail4_00192048(s32) asm("_Z16u_tail4_00192048jjjj");
void CmComm_FontIcon(s32, char*, bool) asm("_ZN2Tz6CmComm8FontIconEiPcb");
s32 CmComm_GetIconMsgSize(void) asm("_ZN2Tz6CmComm14GetIconMsgSizeEv");
u8* CmComm_CopyMessage(char*, u8*) asm("_ZN2Tz6CmComm11CopyMessageEPcPKN2YS7MESSAGEE");
s32 MESSAGE_get_size(u8*) asm("_ZNK2YS7MESSAGE8get_sizeEv");
void func_00275f68(s32 a, s32 b) {
    char* s;
    s32 m;
    u_call4_00139d78(D_0035f20c + 1308);
    if (a < 0) {
        *(u32*)(D_0035f20c + 408) = 0;
    } else {
        m = func_00259510(1024);
        s = (char*)(D_0035f20c + 1744);
        CmComm_FontIcon(m, s, 1);
        s += CmComm_GetIconMsgSize();
        CmComm_CopyMessage(s, u_tail4_00192048(a));
        *(u8**)(D_0035f20c + 408) = D_0035f20c + 1744;
    }
    if (b < 0) {
        *(u32*)(D_0035f20c + 844) = 0;
    } else {
        m = func_00259510(2048);
        s = (char*)(D_0035f20c + 1808);
        s += MESSAGE_get_size(CmComm_CopyMessage(s, u_tail4_00192048(b)));
        CmComm_FontIcon(m, s, 1);
        *(u8**)(D_0035f20c + 844) = D_0035f20c + 1808;
    }
}
void w_memset(void*, s32, u32) asm("_Z16wtarget_002fde18jjjj");
u8* AREA_Alloc(u32) asm("_ZN4AREA5AllocEj");
s32 ATTACK_CHECK_NewComboGroup(void) asm("_ZN2YS12ATTACK_CHECK13NewComboGroupEv");
void func_001e0cb8(u8*, s32);
struct O17 {
    u8 a[160]; u8 b[160]; u8 c[3200]; u8 pad[3524 - 3520];
    u8* x3524; u8* x3528; s32 x3532; u32 x3536; u32 x3540; u32 x3544; u32 x3548; u32 x3552;
    u8 pad2[3568 - 3556]; s32 x3568; u8 pad3[3584 - 3572]; s32 x3584;
};
void func_001e17b8(O17* p) {
    s32 i, j;
    w_memset(p->a, 0, 160);
    w_memset(p->b, 0, 160);
    w_memset(p->c, 0, 3200);
    p->x3532 = 0;
    { s32 k = 6; for (j = 0; j < 15; j++) { p->x3532 += k; k += 3; } }
    p->x3524 = AREA_Alloc(p->x3532 << 6);
    w_memset(p->x3524, 0, p->x3532 << 6);
    p->x3528 = AREA_Alloc(p->x3532 * 48);
    for (i = 0; i < p->x3532; i++) func_001e0cb8(p->x3528 + i * 48, i);
    p->x3540 = 0;
    p->x3544 = 0;
    p->x3548 = 0;
    p->x3552 = 0;
    p->x3568 = ATTACK_CHECK_NewComboGroup();
    p->x3584 = -1;
}

extern u8 D_00361aa0[];
extern u8* D_00361a90;
extern u8 D_00347e60[];
extern u8 D_00347f98[];
extern u8 D_0035eb98[];
void CACHE_BUFF_Free(void*) asm("_ZN2YS10CACHE_BUFF4FreeEPv");
void SEQUENCE_dtor(u8*) asm("_ZN2YI8SEQUENCED1Ev");
void func_0023c098(u8*);  // set_vtbl_36eae8_then_call
void func_002369f0(u8*);  // set_vtbl_36eac8_then_call
typedef void (*VF12)(u8*);
void func_002c1200(u8* p) {
    u8* e;
    *(u8**)p = D_00361aa0;
    CACHE_BUFF_Free(*(void**)(p + 188));
    D_00361a90 = (D_00361a90 == p) ? 0 : D_00361a90;
    if (p + 2232) {
        e = p + 3048;
    L1:
        if (p + 2232 != e) {
            e -= 408;
            (*(VF12*)(*(u8**)e + 12))(e);
            goto L1;
        }
    }
    e = p + 1824;
    *(u8**)(p + 1824) = D_00347e60;
    SEQUENCE_dtor(p + 1848);
    *(u8**)(p + 1824) = D_00347f98;
    if (p + 600) {
    L2:
        if (p + 600 != e) {
            e -= 408;
            (*(VF12*)(*(u8**)e + 12))(e);
            goto L2;
        }
    }
    *(u8**)(p + 192) = D_00347e60;
    SEQUENCE_dtor(p + 216);
    *(u8**)(p + 192) = D_00347f98;
    *(u8**)(p + 28) = D_0035eb98;
    func_0023c098(p + 76);  // set_vtbl_36eae8_then_call
    func_002369f0(p + 52);  // set_vtbl_36eac8_then_call
    *(u8**)(p + 28) = D_00347f98;
    *(u8**)(p + 0) = D_00347f98;
}

void Aabbox_init(Box3w258*) asm("_ZN2dk6Aabbox4initEv");
void func_0016ac38(u8*, s32, s32, s32, s32);
void func_001b7c80(void*, Box3w258*);
V4w258* func_0016c028(u8*);  // obj_get_attach_or_alt
void func_002de500(u8*, V4w258*);
void wtarget_002cf280(u8*, s32, s32) asm("_Z16wtarget_002cf280jjjj");
void func_002de3e0(u8* p) {
    V4w258 t;
    func_0016ac38(p, 0, 1, 0, 0);
    if (*(void**)(p + 1296) != 0) {
        Box3w258 b;
        Aabbox_init(&b);
        func_001b7c80(*(void**)(p + 1296), &b);
        V4w258 c(b.mn[0] + b.mx[0], b.mn[1] + b.mx[1], b.mn[2] + b.mx[2], 0.0f);
        t = c * 0.5f;
    } else {
        t = *func_0016c028(p);  // obj_get_attach_or_alt
    }
    t.z = 0.0f;
    func_002de500(p, &t);
    wtarget_002cf280(p + 2800, 4, 0);
    wtarget_002cf280(p + 2800, 0x4000, 0);
}

f32 func_002ce2a0(Rail258*, s32*, f32*, u32);
Seg258* func_002cb890(Rail258*, s32);  // hash_bucket_get
f32 wtarget_002ce598(Rail258* p, u32 a1) asm("_Z16wtarget_002ce598jjjj");
f32 wtarget_002ce598(Rail258* p, u32 a1) {
    s32 i;
    f32 fr;
    V4w258* pa = &p->a0;
    f32 r = func_002ce2a0(p, &i, &fr, a1);
    Seg258* s = func_002cb890(p, i);  // hash_bucket_get
    *pa = s->a;
    p->b0 = s->b;
    V4w258* pb = &p->a1;
    s = func_002cb890(p, (i + 1) % p->n);  // hash_bucket_get
    *pb = s->a;
    p->b1 = s->b;
    p->f18 = (f32)i + fr;
    p->f28 = (*pb - *pa).len();
    return r;
}
}
