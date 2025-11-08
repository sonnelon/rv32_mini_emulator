#pragma once
#include <string>

class Logger {
public:
    inline void err(const std::string& msg);
    inline void warning(const std::string& msg);
};
