#include "util.h"

using namespace boost::algorithm;
using namespace boost;

/**
 * \brief Splits string at string delimiter, returns as vector
 * \author Paul Scoropan
 * @param rawText String holding the raw string to be split
 * @param delimiter String holding the delimiter to split the rawText at
 * @return splitVec Vector holding multiple strings from rawText
 */
std::vector<std::string> Util::splitString(std::string rawText, std::string delimiter) {
    std::vector<std::string> splitVec;

    int start = 0;
    int end = 0;
    while(end!=std::string::npos){

        end = rawText.find(delimiter, start);
        splitVec.push_back(rawText.substr(start, end-start));
        start = end + delimiter.length();
        
    }

    return splitVec;
}

/**
 * \brief Removes all instances of a char, returns String
 * @param rawText String to have chars removed
 * @param removed Char holding the removed character
 * @return rawText String with new string without the removed character
 */
std::string Util::removeAllChar(std::string rawText, char removed) {
    erase_all(rawText, std::string(1, removed)); // boost erase_all function
    return rawText;
}
/**
 * \brief Returns whether the String represents a true or false value
 * @param rawText String to be compared as True or False
 * @return Bool either true for 0 or false return value
 */
bool Util::toBool(std::string rawText) {
    return (rawText.compare("true") == 0 || rawText.compare("True") == 0) ? true : false;
}
