#include "JovianApp/JovianData/JovianData.h"
#include <CLI/App.hpp>

JovianData::JovianData()
{}

void JovianData::Initialize(CLI::App& app)
{
	CLI::App* show_command = app.add_subcommand(
		"info",
		"Returns the target's orbital and physical ephemeris data"
	);

	show_command->add_option("target", target, "Selects the planetary system")
		->required();

	show_command->add_option("-d, --date", observation_date, "Sets the observation epoch. Accepts an ISO 8601 formatted string")
		->expected(1);
}
