#include "JovianCore/JovianSchema/JovianCommandInterface.h"
#include "JovianCore/JovianSchema/JovianRegistry/JovianRegistry.h"
#include <CLI/App.hpp>
#include <memory>
#include <utility>

JovianRegistry::JovianRegistry()
{}

void JovianRegistry::AddCommand(std::unique_ptr<JovianCommandInterface> command)
{
	commands.push_back(std::move(command));
}

void JovianRegistry::Register(CLI::App& app)
{
	for (const std::unique_ptr<JovianCommandInterface>& command : commands) {
		command->Initialize(app);
	}
}