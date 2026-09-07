#include "JovianApp/JovianView/JovianView.h"
#include <CLI/App.hpp>

JovianView::JovianView()
{}

void JovianView::Initialize(CLI::App& app)
{
	CLI::App* view_command = app.add_subcommand(
		"view",
		"Generates a visualization of a planetary system"
	);

	view_command->add_option("planet", planet, "Selects the planetary system")
		->required();

	view_command->add_option("-d, --date", observation_date, "Sets the observation epoch")
		->expected(1);
}
