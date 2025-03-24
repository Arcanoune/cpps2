#include "fraction.hpp"
#include "utils.hpp"
#include <iostream>

// void Fraction::display()
// {
//     std::cout << numerator << "/" << denominator;
// }


std::ostream &operator<<(std::ostream &os, Fraction const &p)
{
    return os << '(' << p.numerator << "/" << p.denominator << ')';
}

//
//

Fraction add(Fraction const &f1, Fraction const &f2)
{
    return simplify({f1.numerator * f2.denominator + f2.numerator * f1.denominator,
                     f1.denominator * f2.denominator});
}

Fraction operator+(Fraction const &f1, Fraction const &f2)
{
    return simplify({f1.numerator * f2.denominator + f2.numerator * f1.denominator,
                     f1.denominator * f2.denominator});
}

Fraction operator+=(Fraction const &f1, Fraction const &f2)
{
    return simplify({f1.numerator * f2.denominator + f2.numerator * f1.denominator,
                     f1.denominator * f2.denominator});
}

Fraction sub(Fraction const &f1, Fraction const &f2)
{
    return simplify({f1.numerator * f2.denominator - f2.numerator * f1.denominator,
                     f1.denominator * f2.denominator});
}

Fraction operator-(Fraction const &f1, Fraction const &f2)
{
    return simplify({f1.numerator * f2.denominator - f2.numerator * f1.denominator,
                     f1.denominator * f2.denominator});
}

Fraction mul(Fraction const &f1, Fraction const &f2)
{
    return simplify({f1.numerator * f2.numerator,
                     f1.denominator * f2.denominator});
}

Fraction operator*(Fraction const &f1, Fraction const &f2)
{
    return simplify({f1.numerator * f2.numerator,
                     f1.denominator * f2.denominator});
}

Fraction div(Fraction const &f1, Fraction const &f2)
{
    return simplify({f1.numerator * f2.denominator,
                     f1.denominator * f2.numerator});
}

Fraction operator/(Fraction const &f1, Fraction const &f2)
{
    return simplify({f1.numerator * f2.denominator,
                     f1.denominator * f2.numerator});
}

bool operator==(Fraction const &a, Fraction const &b)
{
    return a.numerator == b.numerator && a.denominator == b.denominator;
}

bool operator!=(Fraction const &a, Fraction const &b)
{
    return !(a.numerator == b.numerator) || !(a.denominator == b.denominator);
}

bool operator<(Fraction const &a, Fraction const &b)
{
    return a.numerator < b.numerator || a.numerator == b.numerator && a.denominator < b.denominator;
}

bool operator<=(Fraction const &a, Fraction const &b)
{
    return a.numerator < b.numerator || a.numerator == b.numerator && a.denominator < b.denominator || a.numerator == b.numerator && a.denominator == b.denominator;
}

bool operator>(Fraction const &a, Fraction const &b)
{
    return a.numerator > b.numerator || a.numerator == b.numerator && a.denominator > b.denominator;
}

bool operator>=(Fraction const &a, Fraction const &b)
{
    return a.numerator > b.numerator || a.numerator == b.numerator && a.denominator > b.denominator || a.numerator == b.numerator && a.denominator == b.denominator;
}

Fraction operator+=(Fraction& f1, Fraction const& f2) {
    f1.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    f1.denominator *= f2.denominator;
    return f1 = simplify(f1);
}

Fraction operator-=(Fraction& f1, Fraction const& f2) {
    f1.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    f1.denominator *= f2.denominator;
    return f1 = simplify(f1);
}

Fraction operator*=(Fraction& f1, Fraction const& f2) {
    f1.numerator *= f2.numerator;
    f1.denominator *= f2.denominator;
    return f1 = simplify(f1);
}

Fraction operator/=(Fraction& f1, Fraction const& f2) {
    f1.numerator *= f2.denominator;
    f1.denominator *= f2.numerator;
    return f1 = simplify(f1);
}


float Fraction::to_float() const {
    return static_cast<float>(numerator) / static_cast<float>(denominator);
}

Fraction::operator float() const {
    return to_float();
}
