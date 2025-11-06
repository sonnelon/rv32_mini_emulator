#pragma once

#include <stdbool.h>

#define VERSION_FLAG "--version"
#define V_FLAG "-v"
#define H_FLAG "-h"
#define HELP_FLAG "--help"

static inline bool check_flag (const char * val, const char * flag_one, const char * flag_two);
void display_help ();
void display_version ();
int parse_args (int argc, char ** argv);
