#ifndef JOVIAN_COMMAND_INTERFACE_H
#define JOVIAN_COMMAND_INTERFACE_H

#include <CLI/App.hpp>

class JovianCommandInterface
{
public:
	virtual ~JovianCommandInterface() = default;

	virtual void Initialize(CLI::App& app) {};
};

#endif