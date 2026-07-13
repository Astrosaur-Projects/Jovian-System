#ifndef JOVIAN_INFO_COMMAND_H
#define JOVIAN_INFO_COMMAND_H

#include "JovianCore/JovianCommandInterface.h"
#include <CLI/App.hpp>
#include <string>

class JovianData : public JovianCommandInterface
{
public:
	JovianData();

	void Initialize(CLI::App& app);

private:
	std::string target; /* E.g., Jupiter, Io, Ganymede, Titan, etc... */
	std::string observation_date;
};

#endif