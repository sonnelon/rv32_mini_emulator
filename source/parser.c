#include <stdio.h>
#include "parser.h"
#include "error.h"

#define MAX_BUF_SIZE 2056

int parser(const char *file_dir, struct regs_state_t *regs_state) {
    FILE *fp = fopen(file_dir, "r");
    if (fp == NULL) err("failed open file");

    int idx = 0;
    instr_t instrs[MAX_BUF_SIZE];

    while (fscanf(fp, "%x", &instrs[idx]) == 1) { idx++; }

    fclose(fp);

    for (int i = 0; i < idx; i++) distribute_instr(instrs[i]);
}


static void distribute_instr(instr_t instr) {
    unsigned char opcode = instr & 0x000000FF; 
    enum types_instr_t type_instr = define_instr_type(opcode);
    printf("%d %d\n", opcode, type_instr);
}

static inline enum types_instr_t define_instr_type(instr_t opcode) { return S_TYPE; }
