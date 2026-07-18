#include "JovianCore/JovianEphemerides/JovianEphemerides.h"
#include <cmath>
#include <cstdio>
#include <numbers>
#include <string>
#include <tuple>

JovianEphemerides::JovianEphemerides()
{}

double JovianEphemerides::JulianDayNumber(std::string date)
{
	int year, month, day, hour, minute, second;

	std::ignore = std::sscanf(date.c_str(), "%d-%d-%dT%d:%d:%dZ", &year, &month, &day, &hour, &minute, &second);

	double time = (((hour * 60.0 * 60.0) + (minute * 60.0) + second) / 86400);

	if (month <= 2) {
		year = year - 1;
		month = month + 12;
	}

	int a = year / 100;

	int b = 2 - a + (int)(a / 4);

	double julian_day = (int)(365.25 * (year + 4716)) + (int)(30.6001 * (month + 1)) + day + time + b - 1524.5;

	return julian_day;
}

void JovianEphemerides::Jupiter(double julian_day)
{
	const double degrees_to_radians = std::numbers::pi / 180.0;

	double d = julian_day - 2451545.0;
	double V = std::fmod(172.74 + (0.00111588 * d), 360.0);
	double M = std::fmod(357.529 + (0.9856003 * d), 360.0);
	double N = std::fmod(20.020 + (0.0830853 * d) + (0.329 * std::sin(V * degrees_to_radians)), 360.0);
	double J = std::fmod(66.115 + (0.9025179 * d) - (0.329 * std::sin(V * degrees_to_radians)), 360.0);
	double A = (1.915 * std::sin(M * degrees_to_radians)) + (0.020 * std::sin(2 * M * degrees_to_radians));
	double B = (5.555 * std::sin(N * degrees_to_radians)) + (0.168 * std::sin(2 * N * degrees_to_radians));
	double K = J + A - B;
	double R = 1.00014 - (0.01671 * std::cos(M * degrees_to_radians)) - (0.00014 * std::cos(2 * M * degrees_to_radians));
	double r = 5.20872 - (0.25208 * std::cos(N * degrees_to_radians)) - (0.00611 * std::cos(2 * N * degrees_to_radians));
	double delta = std::sqrt((r * r) + (R * R) - (2 * R * r * std::cos(K * degrees_to_radians)));
	double psi = std::asin((R / delta) * std::sin(K * degrees_to_radians));
	double lambda = 34.35 + (0.083091 * d) + (0.329 * std::sin((V) * degrees_to_radians)) + B;
	double Ds = 3.12 * std::sin((lambda + 42.8) * degrees_to_radians);
	double De = Ds - (2.22 * std::sin(psi) * std::cos((lambda + 22.0) * degrees_to_radians)) - (1.30 * ((r - delta) / delta) * std::sin((lambda - 100.5) * degrees_to_radians));
}
