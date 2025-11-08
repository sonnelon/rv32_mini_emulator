#include <iostream>
#include <string>
#include "cli.h"
#include "config.h"
#include "parser.h"

inline bool CLI::check_flag(const std::string& val, const std::string& flag_one, const std::string& flag_two) {
    return ((val == flag_one) || (val == flag_two)) ? true : false;
}

int CLI::parse_args(int argc, char ** argv, regs_state_t& regs_state) {
    Parser parser;
    for (int i = 1; i < argc; i++) {
        if (check_flag(argv[i], H_FLAG, HELP_FLAG)) display_help();
        if (check_flag(argv[i], V_FLAG, VERSION_FLAG)) display_version();
    }

    parser.parse(argv[argc-1], regs_state);

    return 0;
}

inline void CLI::display_help() {
    std::cout << "Usage: mini-riscv-qemu [options]... [file_dir]" << std::endl;
    std::cout << "    --help/-h     Display this info and exit." << std::endl;
    std::cout << "    --version/-v  Display app version." << std::endl;
    exit(0);
}

inline void CLI::display_version() { std::cout << "mini-risc-v-qemu version: " <<  VERSION << std::endl; exit(0); }
