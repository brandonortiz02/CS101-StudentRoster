#pragma once

#include <string>

// enumerated type for the three degree programs
enum DegreeProgram { SECURITY, NETWORK, SOFTWARE };

// helper to convert enum to printable string
static const std::string degreeProgramStrings[] = { "Security", "Network", "Software" };

