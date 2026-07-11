#ifndef JOVIAN_RENDER_COMMAND_H
#define JOVIAN_RENDER_COMMAND_H

#include "JovianCore/JovianSchema/JovianCommandInterface.h"
#include <CLI/App.hpp>
#include <string>

class JovianRender : public JovianCommandInterface
{
public:
	JovianRender();

	void Initialize(CLI::App& app);

private:
	std::string target_planet;
	std::string render_date;
};

#endif