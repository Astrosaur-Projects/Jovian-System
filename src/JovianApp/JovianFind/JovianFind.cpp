#include "JovianApp/JovianFind/JovianFind.h"
#include <CLI/App.hpp>

JovianFind::JovianFind()
{}

void JovianFind::Initialize(CLI::App& app)
{
	CLI::App* find_command = app.add_subcommand(
		"find",
		"Finds all occurrences of a planetary arrangement"
	);

	find_command->add_option("target", target, "Selects the planetary body")
		->required();

	find_command->add_option("-d, --date-range", observation_range, "Sets the observation epoch range. Accepts two ISO 8601 formatted strings")
		->expected(1);
}
