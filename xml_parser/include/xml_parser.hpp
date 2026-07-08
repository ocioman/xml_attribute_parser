//
// Created by Lorenzo Andreotta on 06/07/2026.
//
#pragma once
#include <string>
#include <unordered_map>

class XMLParser {
    static void content(std::istream &is, std::unordered_map<std::string, std::string>& uMap);
    static void attributes(std::istream &is, std::unordered_map<std::string, std::string>& uMap);
public:
    XMLParser()=delete;
    static void parse(std::istream &is, std::unordered_map<std::string, std::string>& uMap);
};
