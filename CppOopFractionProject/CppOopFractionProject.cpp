#include <iostream>

#include "Fraction.h"

int main()
{
    try
    {
        Fraction f1(5, 6), f2(3,4), f3(7, 11), f4(3, 32);
        
        Fraction res = 5 + f1;

        res.Print('\n');

    }
    catch (FractionException ex)
    {
        std::cout << ex.Message() << "\n";
    }
}
