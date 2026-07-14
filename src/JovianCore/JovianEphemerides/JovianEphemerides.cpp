#include "JovianCore/JovianEphemerides/JovianEphemerides.h"
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

void JovianEphemerides::Jupiter()
{}
