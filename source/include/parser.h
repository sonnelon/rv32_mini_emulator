#pragma once

#include <cstdint>
#include "regs_state.h"

using imm_t = unsigned short;
using upper_imm_t = unsigned int;
using instr_t = uint32_t;

enum class types_instr_t { I_TYPE, R_TYPE, S_TYPE, J_TYPE, U_TYPE };

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

class Parser {
public:
    int parse(const std::string& file_path, regs_state_t& regs_state);
private:
    i_instr_t parse_i_instr(instr_t instr, regs_state_t& state);
    r_instr_t parse_r_instr(instr_t instr, regs_state_t& state);
    u_instr_t parse_u_instr(instr_t instr, regs_state_t& state);
    s_instr_t parse_s_instr(instr_t instr, regs_state_t& state);
    void distribute_instr(instr_t instr);
    inline types_instr_t define_instr_type(instr_t opcode);
};
