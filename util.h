#pragma once

#include <vector>
#include <iostream>

#include <boost/range/iterator_range.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>


class Util {
public:
    static std::vector<std::string> splitString(std::string rawText, std::string delimiter);
    static std::string removeAllChar(std::string rawText, char removed);
}