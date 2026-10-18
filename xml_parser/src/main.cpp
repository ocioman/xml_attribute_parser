#include <iostream>
#include <sstream>

#include "../include/parse_exception.hpp"
#include "../include/xml_parser.hpp"

int main() {
    std::unordered_map<std::string, std::string> uMap;

    std::string s="<tag1><tag2>content</tag2><tag3 attr='1'>content</tag3></tag1>";

    std::istringstream is(s);

    try {
        XMLParser::parse(is, uMap);
    }catch (ParseException& e) {
        std::cout<<e.what();
    }

    for (const auto& i : uMap) {
        std::cout<<i.first<<": ";
        std::cout<<i.second<<std::endl;
    }

    return 0;
}
