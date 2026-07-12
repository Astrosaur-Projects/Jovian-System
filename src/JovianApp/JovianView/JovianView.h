#ifndef JOVIAN_RENDER_COMMAND_H
#define JOVIAN_RENDER_COMMAND_H

#include "JovianCore/JovianCommandInterface.h"
#include <CLI/App.hpp>
#include <string>

class JovianView : public JovianCommandInterface
{
public:
	JovianView();

	void Initialize(CLI::App& app);

private:
	std::string planet;
	std::string observation_date;
};

#endif