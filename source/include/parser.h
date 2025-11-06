#pragma once

#include <stdbool.h>

typedef unsigned short imm_t;
typedef unsigned int upper_imm_t;

struct regs_state_t {};

struct i_instr_t {
    struct { imm_t imm; unsigned char rs1; unsigned char rd; } operands;
    unsigned char func3;
    unsigned char opcode;
};

struct r_instr_t {
    struct { unsigned char rs1, rs2, rd; } operands;
    unsigned char func7, func3, opcode;
};

struct u_instr_t { upper_imm_t imm; unsigned char rd, opcode; };
struct s_instr_t {
    struct { imm_t imm1, imm2; unsigned char rs2, rs1; } operands;
    unsigned char func3, opcode;
};

static void define_instr_type(const char instr);

int parser(const char * file_dir);

struct i_instr_t parse_i_instr(char * instr, struct regs_state_t * state);
struct r_instr_t parse_r_instr(char * instr, struct regs_state_t * state);
struct u_instr_t parse_u_instr(char * instr, struct regs_state_t * state);
struct s_instr_t parse_s_instr(char * instr, struct regs_state_t * state);
