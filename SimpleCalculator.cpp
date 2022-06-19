#include "SimpleCalculator.h"

long long int SimpleCalculator::add(int in1, int in2)
{
    return (static_cast<long long int>(in1) + in2);
}

long long int SimpleCalculator::add(int in1, int in2, int in3, int in4)
{
    return (static_cast<long long int>(in1) + in2 + in3 + in4);
}

double SimpleCalculator::add(float fn1, float fn2)
{
    return (static_cast<double>(fn1) + fn2);
}

long long int SimpleCalculator::multi(int in1, int in2)
{
    return (static_cast<long long int>(in1) * in2);
}

long double SimpleCalculator::multi(double dn1, double dn2)
{
    return (static_cast<long double>(dn1) * dn2);
}

double SimpleCalculator::multi(float fn1, float fn2)
{
    return (static_cast<double>(fn1) * fn2);
}


double divide(int in1, int in2)
{
    return (static_cast<double>(in1) / in2);
}

long double divide(double dn1, double dn2)
{
    return (static_cast<long double>(dn1) / dn2);
}

double divide(float fn1, float fn2)
{
    return (static_cast<double>(fn1) / fn2);
}