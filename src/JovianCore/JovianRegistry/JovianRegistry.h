#ifndef JOVIAN_REGISTRY_H
#define JOVIAN_REGISTRY_H

#include "JovianCore/JovianCommandInterface.h"
#include <CLI/App.hpp>
#include <memory>
#include <vector>

class JovianRegistry
{
public:
	JovianRegistry();

	void AddCommand(std::unique_ptr<JovianCommandInterface> command);

	void Register(CLI::App& app);

private:
	std::vector<std::unique_ptr<JovianCommandInterface>> commands;
};

#endif