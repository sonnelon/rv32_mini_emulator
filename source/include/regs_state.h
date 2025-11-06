#pragma once

typedef unsigned int reg_t;

struct regs_state_t {
    reg_t zero, ra, sp, gp, tp;
    reg_t t0, t2, s0, fp;
    reg_t s1, a0, a1, a2, a3, a4, a5, a6, a7;
    reg_t s2, s3, s4, s5, s6, s7, s8, s9, s10, s11;
    reg_t t3, t4, t5, t6;
    reg_t ft0, ft1, ft2, ft3, ft4, ft5, ft6, ft7;
    reg_t fs0, fs1;
    reg_t fa0, fa1;
    reg_t fa2, fa3, fa4, fa5, fa6, fa7;
    reg_t fs2, fs3, fs4, fs5, fs6, fs7, fs8, fs9, fs10, fs11;
    reg_t ft8, ft9, ft10, ft11;
};
