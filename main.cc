#include "cli.h"
#include "regs_state.h"

int main(int argc, char * argv[]) {
    CLI cli;
    regs_state_t regs;
    cli.parse_args(argc, argv, regs);
}
