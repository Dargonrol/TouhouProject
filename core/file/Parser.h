//
// Created by dargonrol on 6/23/2024.
//

#ifndef PARSER_H
#define PARSER_H
#include <string>

#include "../language.h"

class Parser {
private:
    static bool lineIsEmptyOrComment(std::string* line);

public:
    static void parseLanguage(Languages language);
};

#endif //PARSER_H
