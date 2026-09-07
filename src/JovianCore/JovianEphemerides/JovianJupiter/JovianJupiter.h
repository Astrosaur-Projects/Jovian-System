#ifndef JOVAIN_JUPITER_H
#define JOVAIN_JUPITER_H

class JovianJupiter
{
public:
	JovianJupiter(double julian_day);

	void Planet();
	void Satellites();

private:
	double julian_day;
	double d, V, M, N, J, A, B, K, R, r, delta, psi, lambda, Ds, De;
};

#endif