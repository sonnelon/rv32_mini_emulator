#include <stdio.h>
#include "cli.h"
#include "regs_state.h"

int main(int argc, char * argv[]) {
    regs_state_t regs;
    parse_args(argc, argv, &regs);
}
