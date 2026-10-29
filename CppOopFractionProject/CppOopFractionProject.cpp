#include <iostream>

#include "Fraction.h"

int main()
{
    try
    {
        Fraction f(23, 78);
        f.Print();
    }
    catch (FractionException ex)
    {
        std::cout << ex.Message() << "\n";
    }
}
