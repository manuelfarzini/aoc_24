#ifndef DAY_03
#define DAY_03

#pragma once
#include "utils.hpp"
#include <print>
#include <string>

enum {
    _on,
    _mul,
    _op1,
    _op2,
    _off,
};

class Cursor {
private:
    std::string s_;
    char * curs_;
    std::string muls_;
    std::array<int, 2> ops_;
    uint8_t state_;
    int ans_;

public:
    explicit Cursor(std::string && str) : s_(std::move(str) + '\0'), curs_(s_.data()), ans_(0) {
        state_ = _on;
    }
    uint8_t state() {
        return state_;
    }
    void next() {
        curs_++;
    }
    void advance(size_t steps) {
        curs_ += steps;
    }
    bool empty() {
        return *curs_ == '\0';
    }
    char operator()() {
        return *curs_;
    }
    void isTokenMul() {
        std::string t("mul(");
        for (auto & c : t) {
            if (c != *curs_) {
                state_ = _on;
                return;
            }
            next();
        }
        state_ = _mul;
    }
    void isTokenNumeral() {
        int num = 0;
        while (std::isdigit(*curs_)) {
            num = num * 10 + (*curs_ - '0');
            next();
        }
        if (*curs_ == ',' && state_ == _mul) {
            ops_[0] = num;
            state_ = _op1;
            next();
        } else if (*curs_ == ')' && state_ == _op1) {
            ops_[1] = num;
            state_ = _op2;
            next();
        } else {
            state_ = _on;
        }
    }
    void multiply() {
        ans_ += ops_[0] * ops_[1];
        state_ = _on;
        return;
    }
    void isTokenSwitch() {
        if (state_ == _off) {
            std::string t = "do()";
            size_t i = 0;
            for (; i < t.size(); i++) {
                if (t[i] != *curs_) {
                    return;
                }
                next();
            }
            state_ = _on;
        } else { // state_ == _on
            std::string t = "don't()";
            size_t i = 0;
            for (; i < t.size(); i++) {
                if (t[i] != *curs_) {
                    return;
                }
                next();
            }
            state_ = _off;
        }
    }
    std::string toString() {
        return std::to_string(ans_);
    }
};

inline void day_03(int argc, char ** argv) {
    if (argc != 2) {
        return;
    }
    std::string test_string = read_input(argv[1]);
    Cursor c(std::move(test_string));
    while (!c.empty()) {
        switch (c.state()) {
        case _on:
            if (c() == 'm') c.isTokenMul();
            else if (c() == 'd') c.isTokenSwitch();
            else c.next();
            break;
        case _mul:
        case _op1:
            c.isTokenNumeral();
            break;
        case _op2:
            c.multiply();
            break;
        case _off:
            c.isTokenSwitch();
            c.next();
            break;
        }
    }
    std::println("{:s}", c.toString());
}

#endif // DAY_03
