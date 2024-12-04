#ifndef AOC_24_HPP
#define AOC_24_HPP

#pragma once
#include <format>
#include <print>

#define DEBUG std::println("+-------------------- DEBUG --------------------+")

/**
 * @class
 *
 * A typical `Aoc24` is …
 *
 * @note …
 */
class Aoc24 {
public:
    explicit Aoc24(int x);              ///< State constructor.
    const std::string toString() const; ///< Implements the Abstraction Function.
    static void sayHello() noexcept;    ///< Example method.

private:
    int _state;                         ///< Represents the internal state.
};

/**
 * @brief Constructor.
 *
 * Builds a `Aoc24` from a provided integer that becomes the internal state.
 *
 * @param x The state that will be hold by the object.
 */
inline Aoc24::Aoc24(int x) : _state(x) {}

/**
 * @brief Returns a formatted description.
 *
 * Returns a description of `this` as formatted std::string. Implements the Abstraction Function.
 */
inline const std::string Aoc24::toString() const {
    return std::format("Aoc24 – The internal state is: {:d}", _state);
}

/**
 * @brief Just say 'Hello'.
 *
 * It just prints on stdout 'Hello from the Aoc24's World'.
 */
inline void Aoc24::sayHello() noexcept {
    std::println("Hello from the Aoc24's World");
}
#endif // AOC_24_HP
