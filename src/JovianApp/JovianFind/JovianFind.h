#ifndef JOVIAN_FIND_COMMAND_H
#define JOVIAN_FIND_COMMAND_H

#include "JovianCore/JovianCommandInterface.h"
#include <CLI/App.hpp>
#include <string>

class JovianFind : public JovianCommandInterface
{
public:
	JovianFind();

	void Initialize(CLI::App& app);

private:
	std::string target;
	std::string observation_range;
};

#endif