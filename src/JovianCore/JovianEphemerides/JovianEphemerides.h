#ifndef JOVAIN_EPHEMERIDES_H
#define JOVIAN_EPHEMERIDES_H

#include <string>

class JovianEphemerides
{
public:
	JovianEphemerides();
	
	double JulianDayNumber(std::string date);
	void Jupiter(double jde);
};

#endif