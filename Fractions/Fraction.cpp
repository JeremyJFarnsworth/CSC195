// Fractions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Fraction.h"
using namespace mathlib;

int main()
{
    Fraction fraction1{ 15, 5 };
    std::cout << fraction1 << std::endl;

    Fraction fraction2{ 15, 6 };
    fraction2.simplify();
    std::cout << fraction2 << std::endl;

    std::cout << fraction1 << " == " << fraction2 << " result: " << (fraction1 == fraction2) << std::endl;
    std::cout << fraction1 << " > " << fraction2 << " result: " << (fraction1 > fraction2) << std::endl;

    std::cout << fraction1 << " + " << fraction2 << " result: " << (fraction1 + fraction2) << std::endl;
    std::cout << fraction1 << " * " << fraction2 << " result: " << (fraction1 * fraction2) << std::endl;

    mathlib::Fraction<int> fraction3;

    std::cout << "Input fraction (format: numerator/denominator): ";
    if (std::cin >> fraction3)
    {
        std::cout << "You entered: " << fraction3 << std::endl;
        std::cout << "Decimal form: " << fraction3.toDouble() << std::endl;
    }
    else
    {
        std::cout << "Invalid input format. Please use 'numerator/denominator'." << std::endl;
    }

    return 0;

}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
