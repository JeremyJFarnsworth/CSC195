#pragma once
#include <iostream>
#include <stdexcept> // For std::invalid_argument
#include <type_traits> // For std::make_unsigned (optional)

namespace mathlib
{
    template <typename T>
    class Fraction
    {
    private:
        T numerator;
        T denominator;

        // Pulled from chat gpt
        T gcd(T a, T b) const
        {
            if (a < 0) a = -a;
            if (b < 0) b = -b;
            while (b != 0)
            {
                T temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }
        //
        
        

    public:
        
        Fraction(T num = 0, T denom = 1)
            : numerator(num), denominator(denom)
        {
            if (denom == 0)
                throw std::invalid_argument("Denominator cannot be zero.");
        }

       
        // fed through chat gpt
        void simplify()
        {
            T g = gcd(numerator, denominator);
            numerator /= g;
            denominator /= g;
            if (denominator < 0)
            {
                numerator = -numerator;
                denominator = -denominator;
            }
        }
        //
       
        double toDouble() const
        {
            return static_cast<double>(numerator) / denominator;
        }

        
        Fraction operator+(const Fraction& other) const
        {
            return Fraction(
                numerator * other.denominator + other.numerator * denominator,
                denominator * other.denominator
            );
        }

        Fraction operator-(const Fraction& other) const
        {
            return Fraction(
                numerator * other.denominator - other.numerator * denominator,
                denominator * other.denominator
            );
        }

        Fraction operator*(const Fraction& other) const
        {
            return Fraction(
                numerator * other.numerator,
                denominator * other.denominator
            );
        }

        Fraction operator/(const Fraction& other) const
        {
            if (other.numerator == 0)
                throw std::invalid_argument("Cannot divide by zero fraction.");
            return Fraction(
                numerator * other.denominator,
                denominator * other.numerator
            );
        }

       
        bool operator==(const Fraction& other) const
        {
            return numerator == other.numerator && denominator == other.denominator;
        }

        bool operator!=(const Fraction& other) const
        {
            return !(*this == other);
        }

        bool operator<(const Fraction& other) const
        {
            return numerator * other.denominator < other.numerator * denominator;
        }

        bool operator>(const Fraction& other) const
        {
            return other < *this;
        }

        bool operator<=(const Fraction& other) const
        {
            return !(*this > other);
        }

        bool operator>=(const Fraction& other) const
        {
            return !(*this < other);
        }

        
        friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction)
        {
            out << fraction.numerator << "/" << fraction.denominator;
            return out;
        }

        //Fed through chat gpt
        friend std::istream& operator>>(std::istream& in, Fraction& f)
        {
            T num, denom;
            char slash;
            in >> num >> slash >> denom;
            if (!in || slash != '/' || denom == 0)
            {
                in.setstate(std::ios::failbit);
                return in;
            }
            f.numerator = num;
            f.denominator = denom;
            f.simplify();
            return in;
        }

    };   //
}
