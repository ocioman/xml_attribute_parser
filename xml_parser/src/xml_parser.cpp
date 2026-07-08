//
// Created by Lorenzo Andreotta on 06/07/2026.
//
#include "../include/xml_parser.hpp"
#include "../include/parse_exception.hpp"
#include <istream>
#include <sstream>

void XMLParser::content(std::istream &is, std::unordered_map<std::string, std::string>& uMap){
    std::ws(is);
    is.get(); // consumo '<'
    if (is.peek() != '/') {
        is.putback('<'); // non è un closing tag, rimetto '<' e parso il fratello
        parse(is, uMap); // consumo il tag (se non c'è un annidamento tiro fuori il contenuto e mi metto all'inizio del prossimo possibile fratello)
        content(is, uMap); // continuo a cercare altri fratelli -> se la chiamata ritorna, ho trovato il tag del padre
    } else { //tag di chiusura che verrà consumato dalla chiamata di tag che ha chiamato content
        is.putback('<'); // rimetto '<'
    }
}

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
    if (is.peek()=='<') {
        parse(is, uMap);
        content(is, uMap);
        is.get(); // consuma < (rimesso da putback)
        is.get(); // consuma /
    }else {
        std::string contained;
        std::ws(is);
        std::getline(is, contained,'<');
        is.get(); // ho consumato già < per tirare fuori il contenuto testuale, mi basta consumare '/'
    }

    std::string closingTagName;
    std::getline(is, closingTagName, '>'); //lo stato della stream si trova dopo la fine del tag di chisurua

    if (openingTagName!=closingTagName)
        throw ParseException("Exception:\nOpening Tag Name: "+openingTagName+"\nIs Different From Closing Tag Name: "+closingTagName+"\n");
}
