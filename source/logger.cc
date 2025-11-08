#include <iostream>
#include <stdlib.h>
#include "color.h"
#include "logger.h"

inline void Logger::err(const std::string& msg) { 
    std::cerr << RED << "error:" << RESET_COLOR << msg << std::endl; 
    exit(-1);
}

inline void Logger::warning(const std::string& msg) {
    std::cerr << PURPLE << "warning:" << RESET_COLOR << msg << std::endl; 
}
