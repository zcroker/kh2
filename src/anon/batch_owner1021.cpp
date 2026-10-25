#include "../common/types.h"
// Owner batch 2026-10-21: functions that needed layout.tsv splits (001e03b0..001e03d8, 0014b290/0014b2c8)
// and the hand-written VU0 rotation routines 002f4148/002f41f0.
extern "C" {

// 001e03b0, 001e03c8, 001e03d0, 001e03d8 (PadWave): moved to src/anon/unit_001e0398.cpp

// ---- 0014b290 / 0014b2c8: two identical copies (C1/C2 of one constructor)
void func_0014b150(void*);
void func_0014b300(void*);
extern u8 D_00349b40[];
void ctarget_0014b290(u32* self, u32, u32, u32) asm("_Z16ctarget_0014b290jjjj");
void ctarget_0014b290(u32* self, u32, u32, u32) {
    func_0014b150(self);
    *self = (u32)D_00349b40;
    func_0014b300(self);
}
void func_0014b2c8(u32* self) {
    func_0014b150(self);
    *self = (u32)D_00349b40;
    func_0014b300(self);
}

// Hand-written VU0 macro code (libvu0-style rotation matrix: calls func_002f4028
// with a non-standard convention, saves ra in a2, trapping addi); kept as asm.
void func_002f4148(u32, u32, f32) {
    asm volatile(
        ".set noreorder\n\t"
        ".set noat\n\t"
        "mtc1 $0, $f0\n\t"
        "c.lt.s $f12, $f0\n\t"
        "lui $1, 0x3fc9\n\t"
        "ori $1, $1, 0xfdb\n\t"
        "mtc1 $1, $f0\n\t"
        "bc1f 1f\n\t"
        "nop\n\t"
        "add.s $f12, $f0, $f12\n\t"
        "j 2f\n\t"
        "li $7, 1\n"
        "1:\n\t"
        "sub.s $f12, $f0, $f12\n\t"
        "move $7, $0\n"
        "2:\n\t"
        "mfc1 $8, $f12\n\t"
        "qmtc2 $8, $vf6\n\t"
        "move $6, $31\n\t"
        "jal func_002f4028\n\t"
        "nop\n\t"
        "move $31, $6\n\t"
        "vmove.xyzw $vf6, $vf5\n\t"
        "vmove.xyzw $vf7, $vf5\n\t"
        "vmove.xyzw $vf8, $vf5\n\t"
        "vmove.xyzw $vf9, $vf5\n\t"
        "vaddw.x $vf6, $vf5, $vf0w\n\t"
        "vaddw.w $vf9, $vf5, $vf0w\n\t"
        "vsub.zw $vf4, $vf4, $vf4\n\t"
        "vaddx.z $vf7, $vf5, $vf4x\n\t"
        "vaddy.y $vf7, $vf5, $vf4y\n\t"
        "vsubx.y $vf8, $vf5, $vf4x\n\t"
        "vaddy.z $vf8, $vf5, $vf4y\n\t"
        "li $7, 4\n"
        "3:\n\t"
        "lqc2 $vf4, 0($5)\n\t"
        "vmulax.xyzw ACC, $vf6, $vf4x\n\t"
        "vmadday.xyzw ACC, $vf7, $vf4y\n\t"
        "vmaddaz.xyzw ACC, $vf8, $vf4z\n\t"
        "vmaddw.xyzw $vf5, $vf9, $vf4w\n\t"
        "sqc2 $vf5, 0($4)\n\t"
        "addi $7, $7, -1\n\t"
        "addi $5, $5, 16\n\t"
        "bne $0, $7, 3b\n\t"
        "addi $4, $4, 16\n\t"
        ".set at\n\t"
        ".set reorder"
        : : : "$1", "$4", "$5", "$6", "$7", "$8", "memory");
}

// Sibling of func_002f4148 (rotation about another axis); hand-written, kept as asm.
void func_002f41f0(u32, u32, f32) {
    asm volatile(
        ".set noreorder\n\t"
        ".set noat\n\t"
        "mtc1 $0, $f0\n\t"
        "c.lt.s $f12, $f0\n\t"
        "lui $1, 0x3fc9\n\t"
        "ori $1, $1, 0xfdb\n\t"
        "mtc1 $1, $f0\n\t"
        "bc1f 1f\n\t"
        "nop\n\t"
        "add.s $f12, $f0, $f12\n\t"
        "j 2f\n\t"
        "li $7, 1\n"
        "1:\n\t"
        "sub.s $f12, $f0, $f12\n\t"
        "move $7, $0\n"
        "2:\n\t"
        "mfc1 $8, $f12\n\t"
        "qmtc2 $8, $vf6\n\t"
        "move $6, $31\n\t"
        "jal func_002f4028\n\t"
        "nop\n\t"
        "move $31, $6\n\t"
        "vmove.xyzw $vf6, $vf5\n\t"
        "vmove.xyzw $vf7, $vf5\n\t"
        "vmove.xyzw $vf8, $vf5\n\t"
        "vmove.xyzw $vf9, $vf5\n\t"
        "vaddw.y $vf7, $vf5, $vf0w\n\t"
        "vaddw.w $vf9, $vf5, $vf0w\n\t"
        "vsub.zw $vf4, $vf4, $vf4\n\t"
        "vsubx.z $vf6, $vf5, $vf4x\n\t"
        "vaddy.x $vf6, $vf5, $vf4y\n\t"
        "vaddx.x $vf8, $vf5, $vf4x\n\t"
        "vaddy.z $vf8, $vf5, $vf4y\n\t"
        "li $7, 4\n"
        "3:\n\t"
        "lqc2 $vf4, 0($5)\n\t"
        "vmulax.xyzw ACC, $vf6, $vf4x\n\t"
        "vmadday.xyzw ACC, $vf7, $vf4y\n\t"
        "vmaddaz.xyzw ACC, $vf8, $vf4z\n\t"
        "vmaddw.xyzw $vf5, $vf9, $vf4w\n\t"
        "sqc2 $vf5, 0($4)\n\t"
        "addi $7, $7, -1\n\t"
        "addi $5, $5, 16\n\t"
        "bne $0, $7, 3b\n\t"
        "addi $4, $4, 16\n\t"
        ".set at\n\t"
        ".set reorder"
        : : : "$1", "$4", "$5", "$6", "$7", "$8", "memory");
}

}
