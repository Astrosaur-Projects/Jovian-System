#include "JovianApp/JovianRender/JovianRender.h"
#include <CLI/App.hpp>

JovianRender::JovianRender()
{}

void JovianRender::Initialize(CLI::App& app)
{
	CLI::App* render_command = app.add_subcommand(
		"render",
		"Generates a visualization of a planetary system"
	);

	render_command->add_option("planet", render_planet, "Selects the planetary system")
		->required();

	render_command->add_option("-d, --date", render_date, "Sets the observation epoch. Accepts an ISO 8601 formatted string")
		->expected(1);
}
