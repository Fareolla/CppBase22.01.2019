#include "mylib.h"
#include <cmath>
#include <limits>

namespace Mylib {

double Exponentiation (double digit, double exponent)
{
    // При 0 степени результат будет 1
    double result {1.0};

    if (fuzzyCompare (exponent, 0.0))
    {
        return result;
    }

    double temp_exp {(exponent > 0) ? exponent : -exponent};

    for (int i {0}; i< temp_exp; ++i)
    {
        result *= digit;
    }
    if (exponent < 0)
    {
        result = 1 / result;
    }
    return result;
}

    bool fuzzyCompare (double left, double right)
    {
        bool result {false};

        double diff{std::fabs(left - right)};

        result = diff < std::numeric_limits<double>::epsilon();

        return result;
    }

} // namespace Mylib
