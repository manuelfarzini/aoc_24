#ifndef AOC_24_UTILS
#define AOC_24_UTILS

#pragma once
#include <fstream>
#include <sstream>
#include <string>

inline std::string read_input(const std::string & path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        return "";
    }
    std::stringstream buf;
    buf << file.rdbuf();
    return buf.str();
}

#endif // AOC_24_UTILS
