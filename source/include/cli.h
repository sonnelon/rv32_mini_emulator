#pragma once

#include <string>
#include "regs_state.h"

#define VERSION_FLAG "--version"
#define V_FLAG "-v"
#define H_FLAG "-h"
#define HELP_FLAG "--help"

class CLI {
public:
    int parse_args(int argc, char ** argv, regs_state_t& regs_state);
private:
    inline bool check_flag(const std::string& val, const std::string& flag_one, const std::string& flag_two);
    inline void display_help();
    inline void display_version();
};
