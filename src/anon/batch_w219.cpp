#include "../common/types.h"

extern "C" {

/* longjmp-style register restore: hand-written lq/lwc1 sequence */
int func_001055b8(void* p) {
    asm volatile(
    "lq $28,0($4)\n lq $29,16($4)\n lq $30,32($4)\n lq $31,48($4)\n lq $16,64($4)\n lq $17,80($4)\n lq $18,96($4)\n lq $19,112($4)\n lq $20,128($4)\n lq $21,144($4)\n lq $22,160($4)\n lq $23,176($4)\n"
    "lwc1 $f20,192($4)\n lwc1 $f21,196($4)\n lwc1 $f22,200($4)\n lwc1 $f23,204($4)\n lwc1 $f24,208($4)\n lwc1 $f25,212($4)\n lwc1 $f26,216($4)\n lwc1 $f27,220($4)\n lwc1 $f28,224($4)\n lwc1 $f29,228($4)\n lwc1 $f30,232($4)\n lwc1 $f31,236($4)\n");
    return 1;
}

}
