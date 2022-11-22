#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

std::string zfill(unsigned long long number, int length)
{
    std::ostringstream str;
    str << std::setw(length) << std::setfill('0') << number;
    return str.str();
}