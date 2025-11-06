#include <stdio.h>
#include "parser.h"
#include "error.h"

#define MAX_BUF_SIZE 2056

int parser(const char * file_dir) {
    FILE * fp = fopen(file_dir, "r");
    if (fp == NULL) err("failed open file"); 
    
    char ch;
    int idx = 0;
    char instrs[MAX_BUF_SIZE];
    while ((ch = fgetc(fp)) != EOF) { 
        if (ch == '\n' || ch == ' ') continue;
        instrs[idx++] = ch;
    }

    instrs[idx] = '\0';

    for (int i = 0; i < idx; i++) define_instr_type(instrs[i]);
}


