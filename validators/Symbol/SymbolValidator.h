//
// Created by mohamed on 3/30/23.
//

#ifndef COMPILERPROJECT_SYMBOLVALIDATOR_H
#define COMPILERPROJECT_SYMBOLVALIDATOR_H


#include "../Validator.h"

class SymbolValidator : public Validator {
private:
    std::string symbols[8] = {":", "+", "-", "*", "/", "<", "<=", "="};
public:
    Type validateAndGetType(std::string token) override;
};


#endif //COMPILERPROJECT_SYMBOLVALIDATOR_H
