#include "JovianApp/JovianShow/JovianShow.h"
#include <CLI/App.hpp>

JovianShow::JovianShow()
{}

void JovianShow::Initialize(CLI::App& app)
{
	CLI::App* show_command = app.add_subcommand(
		"show",
		"Displays the details of planetary satellites and features"
	);

	show_command->add_option("planet", show_planet, "Selects the planetary system")
		->required();

	show_command->add_option("-d, --date", show_date, "Sets the observation epoch. Accepts an ISO 8601 formatted string")
		->expected(1);

	show_command->add_option("-s, --satellites", show_satellites, "Filters planetary satellites (E.g., Callisto, Ganymede)")
		->delimiter(',')
		->expected(1);
}
