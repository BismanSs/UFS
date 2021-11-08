#pragma once

#include <vector>
#include <iostream>

#include <boost/range/iterator_range.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>

// a collection of utility methods, utilizes Boost C++ libraries
// only talk to Boost libraries through this class
class Util {
public: // public methods
    // split string at string delimiter, returning as vector
    static std::vector<std::string> splitString(std::string rawText, std::string delimiter);

    // remove all instances of a char in a string, returns string
    static std::string removeAllChar(std::string rawText, char removed);
};