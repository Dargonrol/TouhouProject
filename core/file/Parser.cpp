//
// Created by dargonrol on 6/23/2024.
//

#include "Parser.h"

#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
#include <list>

#include "../GameProperties.h"
#include "../language.h"

void Parser::parseLanguage(Languages languageEnum) {
    std::string langDir;
    switch (languageEnum) {
        case ENGLISH:
            langDir = directories.englishLangDir;
            break;

        case GERMAN:
            langDir = directories.germanLangDir;
            break;

        default:
            langDir = directories.englishLangDir;
            break;
    }

    std::ifstream file(langDir);
    if (!file.is_open()) {
        SDL_LogError(1, "Could not open language file");
        SDL_LogError(1, "Language file: %s", langDir.c_str());
        return;
    }

    std::pmr::list<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        if (lineIsEmptyOrComment(&line)) { continue; }
        lines.push_back(line);
    }
    file.close();

    std::string category1;
    std::string category2;
    for (auto & line : lines) {
        if (line.find('}') != std::string::npos) {
            category2.empty() ? category1.clear() : category2.clear();
            continue;
        }

        if (line.find('{') != std::string::npos) {
            if (category1.empty()) {
                category1 = line.substr(0, line.find('{') - 1);
                continue;
            }
            size_t firstChar = line.find_first_not_of(' '); // Find the first character that is not a whitespace
            category2 = line.substr(firstChar, line.find('{') - firstChar - 1);
            continue;
        }

        size_t firstChar = line.find_first_not_of(' ');
        std::string key = line.substr(firstChar, line.find('=') - firstChar - 1);
        std::string value = line.substr(line.find('=') + 1, line.size() - line.find('=') - 1);
        if (category2.empty()) {
            Language::setLanguageValue(key, value, category1);
        } else {
            Language::setLanguageValue(key, value, category1, category2);
        }
    }
}

bool Parser::lineIsEmptyOrComment(std::string* line) {
    return line->empty() ||
           line->at(0) == '#' ||
           std::all_of(line->begin(), line->end(), [](unsigned char c) { return std::isspace(c); });
}
