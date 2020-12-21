//See LICENSE for license details.
#include <gd32vf103.h>
#include "n22_func.h"
#include "riscv_encoding.h"

void _init() {
}

void _fini() {
}

void riscv_clock_init(void) {
    SystemInit();

    //ECLIC init
    eclic_init(ECLIC_NUM_INTERRUPTS);
    eclic_mode_enable();

//    set_csr(mstatus, MSTATUS_MIE);
}
