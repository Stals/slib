#include "MathUtils.h"

#include <cmath>

double MathUtils::linear_interpolation(double Kstart, double Kend, double Vstart, double Vend, double K)
{
	if (K <= Kstart)
		return Vstart;
	else if (K >= Kend)
		return Vend;
	else
		return Vstart + ((K - Kstart) / (Kend - Kstart)) * (Vend - Vstart);
}

int MathUtils::round(double v)
{
	return (int)floor(v + 0.5);
}

double MathUtils::round(double x, int precision)
{
    int ex = floor(log10(std::abs(x))) - precision + 1;
	double div = pow(10, ex);
    return floor(x / div  + 0.5) * div;
}
