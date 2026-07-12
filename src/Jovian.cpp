#include "JovianApp/JovianCommands/JovianRender/JovianRender.h"
#include "JovianApp/JovianCommands/JovianShow/JovianShow.h"
#include "JovianCore/JovianRegistry/JovianRegistry.h"
#include <CLI/App.hpp>
#include <memory>
#include <string>

/*
*   Project: Jovian System
*
*   Author: Sean Maloney (Astrosaur Projects)
*
*	Date: July 7, 2026
*
*   Description: A C++ CLI tool for calculating the positions of Jupiter's moons and Great Red Spot to plan astrophotography sessions.
*
*	License: MIT License
*/
int main(int argc, char* argv[])
{
	std::string app_name = "jovian";

	std::string app_description = R"(
     __         _             ____         __
 __ / /__ _  __(_)__ ____    / __/_ _____ / /____ __ _
/ // / _ \ |/ / / _ `/ _ \  _\ \/ // (_-</ __/ -_)  ' \
\___/\___/___/_/\_,_/_//_/ /___/\_, /___/\__/\__/_/_/_/
                               /___/

Planetary Ephemerides Viewer
Version 0.0.1
    )";

	CLI::App app { app_description, app_name };

	auto app_formatter = app.get_formatter();

	app_formatter->enable_description_formatting(false);

	std::unique_ptr<JovianRegistry> command_registry = std::make_unique<JovianRegistry>();

	command_registry->AddCommand(std::make_unique<JovianRender>());
	command_registry->AddCommand(std::make_unique<JovianShow>());

	command_registry->Register(app);

	CLI11_PARSE(app, argc, argv);

	return 0;
}