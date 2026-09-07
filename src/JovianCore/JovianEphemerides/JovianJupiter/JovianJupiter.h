#ifndef JOVAIN_JUPITER_H
#define JOVAIN_JUPITER_H

#include <numbers>

class JovianJupiter
{
public:
	JovianJupiter(double julian_day);

	void Planet();
	void Satellites();

private:
	const double degrees_to_radians = std::numbers::pi / 180.0;

	double julian_day;
	double d, V, M, N, J, A, B, K, R, r, delta, psi, lambda, Ds, De;
	double u1, u2, u3, u4, G, H, r1, r2, r3, r4;
	double x1, y1;
	double x2, y2;
	double x3, y3;
	double x4, y4;
};

#endif