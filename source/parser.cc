#include <iostream>
#include <fstream>
#include "parser.h"
#include "logger.h"

#define MAX_BUF_SIZE 2056

int Parser::parse(const std::string& file_path, regs_state_t& regs_state) {
    Logger logger;
    std::ifstream file(file_path);

    int idx = 0;
    instr_t instrs[MAX_BUF_SIZE];
    if (file.is_open()) { while (file >> instrs[idx]) { idx++; } }
    
    file.close();
    for (int i = 0; i < idx; i++) distribute_instr(instrs[i]);
}


void Parser::distribute_instr(instr_t instr) {
    unsigned char opcode = instr & 0x000000FF; 
    types_instr_t instr_type = define_instr_type(opcode);
    std::cout << opcode << std::endl;
}

inline types_instr_t Parser::define_instr_type(instr_t opcode) { return types_instr_t::S_TYPE; }
