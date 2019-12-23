#pragma once

#include <iostream>
#include <string>

class Convert
{
public:
	Convert(std::string name, std::string cpp);
	std::string toCpp(std::string line);

private:
	std::string m_name;
	std::string m_cpp;
};