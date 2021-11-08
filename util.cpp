#include "util.h"

using namespace boost::algorithm;
using namespace boost;

// splits string at string delimiter, returns as vector
std::vector<std::string> Util::splitString(std::string rawText, std::string delimiters) {

    std::vector<std::string> splitVec;
    split( splitVec, rawText, is_any_of(delimiters), token_compress_on ); // boost split function
    return splitVec;
}

// removes all instances of a char, returns string
std::string Util::removeAllChar(std::string rawText, char removed) {
    erase_all(rawText, std::string(1, removed)); // boost erase_all function
    return rawText;
}