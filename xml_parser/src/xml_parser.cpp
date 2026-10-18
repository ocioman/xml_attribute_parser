//
// Created by Lorenzo Andreotta on 06/07/2026.
//
#include "../include/xml_parser.hpp"
#include "../include/parse_exception.hpp"
#include <istream>
#include <sstream>

void XMLParser::attributes(std::istream &is, std::unordered_map<std::string, std::string> &uMap) {
    std::string key;
    std::string val;

    std::getline(is, key, '=');
    char c;
    is>>c; //consuma ' oppure "

    if (c=='\'')
        std::getline(is, val, '\'' );
    else
        std::getline(is, val, '\"');

    uMap[key]=val;

    std::ws(is);

    if (is.peek()=='/' || is.peek()=='>')
        return; //fine attributi, niente da fare

    if (is)
        attributes(is, uMap);
}

void XMLParser::parse(std::istream &is, std::unordered_map<std::string, std::string> &uMap) {
    std::ws(is);

    is.get(); // consuma '<' del tag di apertura

    std::string openingTag;
    std::getline(is, openingTag, '>');
    std::istringstream tagStream(openingTag);

    std::string openingTagName;

    if (openingTag.back()=='\'' || openingTag.back()=='"'){
        std::getline(tagStream, openingTagName, ' ');
        attributes(tagStream, uMap);
    }else if (openingTag.back()=='/') {
        if(openingTag.at(openingTag.size()-2)=='\'' || openingTag.at(openingTag.size()-2)=='"') {
            std::getline(tagStream, openingTagName, ' ');
            attributes(tagStream, uMap);
        }
        return;
    }else
        std::getline(tagStream, openingTagName, '>');

    std::ws(is);

    char c;

    c=static_cast<char>(is.get());

    if (c=='<') {
        if (is.peek()=='/')
            throw ParseException("Exception: unexpected closing tag");

        while (is.peek()!='/') {
            is.putback(c);
            parse(is, uMap);

            std::ws(is);

            if (is.eof())
                throw ParseException("Exception: missing closing tag\n");

            c=static_cast<char>(is.get());
        }

        is.get(); // "/"
    }else {
        std::string contained;
        std::ws(is);
        std::getline(is, contained,'<');
        is.get(); // ho consumato già < per tirare fuori il contenuto testuale, mi basta consumare '/'
    }

    std::string closingTagName;
    std::getline(is, closingTagName, '>'); //lo stato della stream si trova dopo la fine del tag di chiusura

    if (openingTagName!=closingTagName)
        throw ParseException("Exception: opening tag name: "+openingTagName+" is different from closing tag name: "+closingTagName+"\n");
}
