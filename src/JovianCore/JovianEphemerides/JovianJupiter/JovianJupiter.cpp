#include "JovianCore/JovianEphemerides/JovianJupiter/JovianJupiter.h"
#include <cmath>

JovianJupiter::JovianJupiter(double julian_day) : julian_day(julian_day)
{
	JovianJupiter::Planet();
	JovianJupiter::Satellites();
}

void JovianJupiter::Planet()
{
	d = julian_day - 2451545.0;

	V = std::fmod(172.74 + (0.00111588 * d), 360.0);
	M = std::fmod(357.529 + (0.9856003 * d), 360.0);
	N = std::fmod(20.020 + (0.0830853 * d) + (0.329 * std::sin(V * degrees_to_radians)), 360.0);
	J = std::fmod(66.115 + (0.9025179 * d) - (0.329 * std::sin(V * degrees_to_radians)), 360.0);
	
	A = (1.915 * std::sin(M * degrees_to_radians)) + (0.020 * std::sin(2 * M * degrees_to_radians));
	B = (5.555 * std::sin(N * degrees_to_radians)) + (0.168 * std::sin(2 * N * degrees_to_radians));
	K = J + A - B;
	R = 1.00014 - (0.01671 * std::cos(M * degrees_to_radians)) - (0.00014 * std::cos(2 * M * degrees_to_radians));
	r = 5.20872 - (0.25208 * std::cos(N * degrees_to_radians)) - (0.00611 * std::cos(2 * N * degrees_to_radians));
	delta = std::sqrt((r * r) + (R * R) - (2 * R * r * std::cos(K * degrees_to_radians)));
	psi = std::asin((R / delta) * std::sin(K * degrees_to_radians)) / degrees_to_radians;

	lambda = 34.35 + (0.083091 * d) + (0.329 * std::sin((V) * degrees_to_radians)) + B;
	Ds = 3.12 * std::sin((lambda + 42.8) * degrees_to_radians);
	De = Ds - (2.22 * std::sin(psi * degrees_to_radians) * std::cos((lambda + 22.0) * degrees_to_radians)) - (1.30 * ((r - delta) / delta) * std::sin((lambda - 100.5) * degrees_to_radians));
}

void JovianJupiter::Satellites()
{
	u1 = std::fmod(163.8069 + (203.4058646 * (d - (delta / 173))) + psi - B, 360.0);
	u2 = std::fmod(358.4140 + (101.2916335 * (d - (delta / 173))) + psi - B, 360.0);
	u3 = std::fmod(5.7176 + (50.2345180 * (d - (delta / 173))) + psi - B, 360.0);
	u4 = std::fmod(224.8092 + (21.4879800 * (d - (delta / 173))) + psi - B, 360.0);

	G = std::fmod(331.18 + (50.310482 * (d - (delta) / 173)), 360.0);
	H = std::fmod(87.45 + (21.569231 * (d - (delta) / 173)), 360.0);

	r1 = 5.9057 - (0.0244 * std::cos(2 * (u1 - u2) * degrees_to_radians));
	r2 = 9.3966 - (0.0882 * std::cos(2 * (u2 - u3) * degrees_to_radians));
	r3 = 14.9883 - (0.0216 * std::cos(G * degrees_to_radians));
	r4 = 26.3627 - (0.1939 * std::cos(H * degrees_to_radians));

	u1 = u1 + 0.473 * std::sin(2 * (u1 - u2) * degrees_to_radians);
	u2 = u2 + 1.065 * std::sin(2 * (u2 - u3) * degrees_to_radians);
	u3 = u3 + 0.165 * std::sin(G * degrees_to_radians);
	u4 = u4 + 0.843 * std::sin(H * degrees_to_radians);

	auto to_x = [&](double r, double u) { return r * std::sin(u * degrees_to_radians); };
	auto to_y = [&](double r, double u) { return (-1 * r) * std::cos(u * degrees_to_radians) * std::sin(De * degrees_to_radians); };

	x1 = to_x(r1, u1); y1 = to_y(r1, u1);
	x2 = to_x(r2, u2); y2 = to_y(r2, u2);
	x3 = to_x(r3, u3); y3 = to_y(r3, u3);
	x4 = to_x(r4, u4); y4 = to_y(r4, u4);
}
