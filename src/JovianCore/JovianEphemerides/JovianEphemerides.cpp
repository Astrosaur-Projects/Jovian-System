#include "JovianCore/JovianEphemerides/JovianEphemerides.h"
#include <cmath>
#include <cstdio>
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

void JovianEphemerides::Jupiter(double jde)
{
	double d = jde - 2451545.0;

	double V = 172.74 + (0.00111588 * d);

	double M = 357.529 + (0.9856003 * d);

	double N = 20.020 + (0.0830853 * d) + (0.329 * std::sin(V));

	double J = 66.115 + (0.9025179 * d) - (0.329 * std::sin(V));

	double A = (1.915 * std::sin(M)) + (0.020 * std::sin(2 * M));

	double B = (5.555 * std::sin(N)) + (0.168 * std::sin(2 * N));

	double K = J + A - B;

	double R = 1.00014 - (0.01671 * std::cos(M)) - (0.00014 * std::cos(2 * M));

	double r = 5.20872 - (0.25208 * std::cos(N)) - (0.00611 * std::cos(2 * N));

	double delta = std::sqrt((r * r) + (R * R) - (2 * R * r * std::cos(K)));

	double psi = std::asin((R / delta) * std::sin(K));

	double lambda = 34.35 + (0.083091 * d) + (0.329 * std::sin(V + B));

	double Ds = 3.12 * std::sin(lambda + 42.8);

	double De = Ds - (2.22 * std::sin(psi) * std::cos(lambda + 22.0)) - (1.30 * ((r - delta) / delta) * std::sin(lambda - 100.5));
}
