#include "util.h"

using namespace boost::algorithm;
using namespace boost;

// splits string at string delimiter, returns as vector
std::vector<std::string> Util::splitString(std::string rawText, std::string delimiter) {
    std::vector<std::string> splitVec;

    int start = 0;
    int end = 0;
    while(end!=std::string::npos){
        // TODO remove this if not needed
        // std::cout << delimiter << std::endl;
        // if (delimiter.compare(",") == 0) {
        //     std::cout << rawText.substr(rawText.find(delimiter, start), rawText.find(delimiter, start)+2) << "hhhhhhhh" << std::endl;
        // }
        // std::cout << "ok" << rawText.find(delimiter, start) << " " << std::string::npos << std::endl;
        // if (rawText.find(delimiter, start)+2 < std::string::npos && rawText.find(delimiter, start) < std::string::npos && rawText.substr(rawText.find(delimiter, start), rawText.find(delimiter, start)+2).compare(", ") == 0) {
        //     std::cout << "wh" << std::endl;
        //     end = rawText.find(delimiter, start);
        //     int start2 = end + delimiter.length();
        //     end = rawText.find(delimiter, start2);
        //     splitVec.push_back(rawText.substr(start, end-start));
        //     start = end + delimiter.length();
        //     std::cout << "fix" << std::endl;
        // } else {
        //     end = rawText.find(delimiter, start);
        //     splitVec.push_back(rawText.substr(start, end-start));
        //     start = end + delimiter.length();
        // }

        end = rawText.find(delimiter, start);
        splitVec.push_back(rawText.substr(start, end-start));
        start = end + delimiter.length();
        
    }
    // TODO remove this if not needed
    // split(splitVec, "1,2000000,3", is_any_of(","), token_compress_on);
    // std::cout << "SPLIT" << rawText << std::endl;
    // split( splitVec, rawText, delimiter, token_compress_on ); // boost split function
    return splitVec;
}

// removes all instances of a char, returns string
std::string Util::removeAllChar(std::string rawText, char removed) {
    erase_all(rawText, std::string(1, removed)); // boost erase_all function
    return rawText;
}

// turns a string into the bool it was representing
bool Util::toBool(std::string rawText) {
    return (rawText.compare("true") == 0 || rawText.compare("True") == 0) ? true : false; // return false unless string is "true" or "True"
}
