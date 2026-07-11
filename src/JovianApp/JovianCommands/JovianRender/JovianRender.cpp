#include "JovianApp/JovianCommands/JovianRender/JovianRender.h"
#include <CLI/App.hpp>
#include <string>

JovianRender::JovianRender()
{}

void JovianRender::Initialize(CLI::App& app)
{
	CLI::App* render_command = app.add_subcommand(
		"render",
		"Generates a visualization of a planetary system at a discrete observation epoch"
	);

	std::string target_planet;

	render_command->add_option("planet", target_planet, "Selects the planetary system")
		->required();

	render_command->add_option("-d, --date", render_date, "Sets the observation epoch by an ISO 8601 formatted string; Defaults to now")
		->expected(1);
}
