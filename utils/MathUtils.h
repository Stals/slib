#pragma once

class MathUtils{
public:
	static double linear_interpolation(double Kstart, double Kend, double Vstart, double Vend, double K);

	static int round(double v);
	static double round(double x, int precision);
};
