#include "JovianCore/JovianEphemerides/JovianJupiter/JovianJupiter.h"
#include <cmath>
#include <numbers>

JovianJupiter::JovianJupiter(double julian_day) : julian_day(julian_day)
{
	JovianJupiter::Planet();
	JovianJupiter::Satellites();
}

void JovianJupiter::Planet()
{
	const double degrees_to_radians = std::numbers::pi / 180.0;

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
	psi = std::asin((R / delta) * std::sin(K * degrees_to_radians));
	lambda = 34.35 + (0.083091 * d) + (0.329 * std::sin((V)*degrees_to_radians)) + B;
	Ds = 3.12 * std::sin((lambda + 42.8) * degrees_to_radians);
	De = Ds - (2.22 * std::sin(psi) * std::cos((lambda + 22.0) * degrees_to_radians)) - (1.30 * ((r - delta) / delta) * std::sin((lambda - 100.5) * degrees_to_radians));
}

void JovianJupiter::Satellites()
{}
