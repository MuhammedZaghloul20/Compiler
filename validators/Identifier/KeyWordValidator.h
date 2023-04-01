//
// Created by mohamed on 3/31/23.
//

#ifndef COMPILERPROJECT_KEYWORDVALIDATOR_H
#define COMPILERPROJECT_KEYWORDVALIDATOR_H


#include "IdentifierValidator.h"

class KeyWordValidator : public IdentifierValidator {
private:
    std::string symbols[8] = {"if", "else", "end", "repeat", "until", "read", "write", "then"};
public:
    Type validateAndGetType(std::string token) override;
};


#endif //COMPILERPROJECT_KEYWORDVALIDATOR_H
