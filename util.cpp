#include "util.h"

using namespace boost::algorithm;
using namespace boost;

std::vector<std::string> Util::splitString(std::string rawText, std::string delimiters) {
    // std::vector<iterator_range<std::string::iterator>> findVector;
    // ifind_all( findVector, rawText, delimiter ); // FindVec == { [abc],[ABC],[aBc] }

    std::vector<std::string> splitVec;
    split( splitVec, rawText, is_any_of(delimiters), token_compress_on );
    return splitVec;
}

std::string Util::removeAllChar(std::string rawText, char removed) {
    erase_all(rawText, std::string(1, removed));
    return rawText;
}