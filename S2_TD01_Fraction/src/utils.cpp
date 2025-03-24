#include "utils.hpp"

unsigned int gcd(unsigned int a, unsigned int b) {
    while (b != 0) {
        unsigned int modulo {a % b};
        a = b;
        b = modulo;
    }

    return a;
}
// recursive version
// unsigned int gcd(unsigned int a, unsigned int b) {
//     if (b == 0) {
//         return a;
//     }
//
//     return gcd(b, a % b);
// }
// ternary operator version
// unsigned int gcd(unsigned int a, unsigned int b) {
//     return b == 0 ? a : gcd(b, a % b);
// }

Fraction simplify(Fraction const& f) {
    const unsigned int divisor { gcd(f.numerator, f.denominator) };

    return {
        f.numerator / divisor,
        f.denominator / divisor
    };
}

// This fonction work on reference instead of return a copy
void simplify_ref(Fraction& f) {
    unsigned int divisor { gcd(f.numerator, f.denominator) };

    f.numerator /= divisor;
    f.denominator /= divisor;
}