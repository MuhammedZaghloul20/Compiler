//
// Created by mohamed on 3/31/23.
//




#include "IdentifierValidator.h"

class KeyWordValidator : public IdentifierValidator {
private:
    std::string symbols[8] = {"if", "else", "end", "repeat", "until", "read", "write", "then"};
public:
    Types validateAndGetType(std::string token) override;
};


