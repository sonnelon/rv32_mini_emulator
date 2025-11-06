#include <stdio.h>
#include "error.h"
#include "color.h"

inline void err(const char * msg) { fprintf(stderr, "%serror%s: %s\n", RED, RESET_COLOR, msg); exit(-1);}
inline void warning(const char * msg) { fprintf(stderr, "%swarning%s: %s\n", PURPLE, RESET_COLOR, msg); }
