#pragma once

#include "../common/types.h"

struct ATTRACT_VEC {
    f32 x, y, z, w;
    ATTRACT_VEC() {}
    ~ATTRACT_VEC() {}
    ATTRACT_VEC& operator=(const ATTRACT_VEC& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

// A field that pulls (or pushes) objects towards its centre, kept in a file-wide list.
struct ATTRACT {
    ATTRACT_VEC pos;     // 0
    u32 mask;            // 16: object kinds it ignores
    f32 range;           // 20: 0 = unlimited
    f32 power;           // 24
    f32 min;             // 28
    f32 max;             // 32
    f32 swirl;           // 36
    f32 center;          // 40
    f32 falloff;         // 44
    ATTRACT* next;       // 48

    ATTRACT(const ATTRACT_VEC& p, f32 power);
    ~ATTRACT();
    static void* operator new(u32 n);
    static void operator delete(void* p);
};

#include "../yasui/libys/list.hpp"
