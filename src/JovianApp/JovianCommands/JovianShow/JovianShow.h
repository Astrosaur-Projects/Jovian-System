#ifndef JOVIAN_SHOW_COMMAND_H
#define JOVIAN_SHOW_COMMAND_H

#include "JovianCore/JovianCommandInterface.h"
#include <CLI/App.hpp>
#include <string>
#include <vector>

class JovianShow : public JovianCommandInterface
{
public:
	JovianShow();

	void Initialize(CLI::App& app);

private:
	std::string show_date;
	std::string show_planet;
	std::vector<std::string> show_satellites;
};

#endif