#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cli.h"
#include "config.h"
#include "parser.h"

static inline bool check_flag (const char * val, const char * flag_one, const char * flag_two) {
    return ((strcmp(val, flag_one) == 0) || (strcmp(val, flag_two) == 0)) ? true : false;
}

int parse_args (int argc, char ** argv, struct regs_state_t * regs_state) {
    for (int i = 1; i < argc; i++) {
        if (check_flag(argv[i], H_FLAG, HELP_FLAG)) display_help();
        if (check_flag(argv[i], V_FLAG, VERSION_FLAG)) display_version();
    }

    parser(argv[argc-1], regs_state);

    return 0;
}

void display_help () {
    puts("Usage: mini-riscv-qemu [options]... [file_dir]\n");
    puts("    --help/-h     Display this info and exit.");
    puts("    --version/-v  Display app version.");
    exit(0);
}

void display_version () { printf("mini-risc-v-qemu version: %s\n", VERSION); exit(0); }
