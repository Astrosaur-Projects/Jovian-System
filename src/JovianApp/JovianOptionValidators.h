#ifndef JOVIAN_OPTION_VALIDATORS_H
#define JOVIAN_OPTION_VALIDATORS_H

#include "JovianCore/JovianCommandInterface.h"
#include <CLI/App.hpp>
#include <cstdio>
#include <string>

namespace JovianOptionValidators
{
	inline const CLI::Validator JovianDateValidator = CLI::Validator(
		[](std::string& input) -> std::string {
			std::istringstream input_stream(input);
			std::chrono::sys_seconds date;

			input_stream >> std::chrono::parse("%FT%TZ", date);

			if (input_stream.fail()) {
				return "Invalid ISO-8601 date. Expected format: YYYY-MM-DDTHH:MM:SSZ (e.g., 1999-12-31T23:59:59Z)";
			}

			double julian_day = 2440587.5 + (std::chrono::duration<double>(date.time_since_epoch()).count() / 86400.0);
			input = std::to_string(julian_day);

			return "";
		},
		"ISO-8601 (YYYY-MM-DDTHH:MM:SSZ)",
		"UTC_DATE"
	);
};

#endif