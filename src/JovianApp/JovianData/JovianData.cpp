#include "JovianApp/JovianData/JovianData.h"
#include "JovianCore/JovianEphemerides/JovianJupiter/JovianJupiter.h"
#include <CLI/App.hpp>
#include <CLI/Validators.hpp>
#include <cstdio>
#include <cstdlib>
#include <memory>
#include <string>
#include <tuple>

JovianData::JovianData()
{}

void JovianData::Initialize(CLI::App& app)
{
	auto to_julian_day_number = CLI::Validator(
		[](std::string& input) {
		int year, month, day, hour, minute, second;

		std::ignore = std::sscanf(input.c_str(), "%d-%d-%dT%d:%d:%dZ", &year, &month, &day, &hour, &minute, &second);

		double time = (((hour * 60.0 * 60.0) + (minute * 60.0) + second) / 86400);

		if (month <= 2) {
			year = year - 1;
			month = month + 12;
		}

		int a = year / 100;
		int b = 2 - a + (int)(a / 4);

		double julian_day = (int)(365.25 * (year + 4716)) + (int)(30.6001 * (month + 1)) + day + time + b - 1524.5;
		input = std::to_string(julian_day);

		return "";
	}, "ISO 8601 DATE (YYYY-MM-DDTHH:MM:SSZ)", "UTC_DATE");

	CLI::App* info_command = app.add_subcommand(
		"info",
		"Returns a planetary body's ephemeris data"
	);

	info_command->add_option("target", target, "Selects the planetary body")
		->required();

	info_command->add_option("-d, --date", observation_date, "Sets the observation epoch")
		->expected(1)
		->transform(to_julian_day_number);

	info_command->callback([&]() {
		double jde = strtod(observation_date.c_str(), nullptr);

		if (target == "jupiter") {
			auto ephemeris = std::make_unique<JovianJupiter>(jde);
		}
	});
}
