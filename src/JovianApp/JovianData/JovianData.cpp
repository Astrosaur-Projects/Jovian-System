#include "JovianApp/JovianData/JovianData.h"
#include "JovianApp/JovianOptionValidators.h"
#include "JovianCore/JovianEphemerides/JovianJupiter/JovianJupiter.h"
#include <CLI/App.hpp>
#include <cstdlib>
#include <memory>
#include <string>

JovianData::JovianData()
{}

void JovianData::Initialize(CLI::App& app)
{
	CLI::App* info_command = app.add_subcommand(
		"info",
		"Returns a planetary body's ephemeris data"
	);

	info_command->add_option("target", target, "Selects the planetary body")
		->required();

	info_command->add_option("-d, --date", observation_date, "Sets the observation epoch")
		->expected(1)
		->transform(JovianOptionValidators::JovianDateValidator);

	info_command->callback([&]() {
		double julian_day = strtod(observation_date.c_str(), nullptr);

		if (target == "jupiter") {
			auto ephemeris = std::make_unique<JovianJupiter>(julian_day);
		}
	});
}
