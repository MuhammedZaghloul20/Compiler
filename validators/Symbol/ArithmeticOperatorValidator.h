//
// Created by mohamed on 3/30/23.
//

#ifndef COMPILERPROJECT_ARITHMETICOPERATORVALIDATOR_H
#define COMPILERPROJECT_ARITHMETICOPERATORVALIDATOR_H


#include "SymbolValidator.h"

class ArithmeticOperatorValidator : public SymbolValidator {
private:
    char symbols[4] = {'*', '+', '/', '-'};
public:
    Type validateAndGetType(std::string token) override;

};


#endif //COMPILERPROJECT_ARITHMETICOPERATORVALIDATOR_H
