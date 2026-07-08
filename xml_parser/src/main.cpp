#include <iostream>
#include "../include/parse_exception.hpp"
#include "../include/xml_parser.hpp"

int main() {
    std::unordered_map<std::string, std::string> uMap;

    try {
        XMLParser::parse(std::cin, uMap);
    }catch (ParseException& e) {
        std::cout<<e.what();
    }

    for (const auto& i : uMap) {
        std::cout<<i.first<<": ";
        std::cout<<i.second<<std::endl;
    }
    return 0;
}
