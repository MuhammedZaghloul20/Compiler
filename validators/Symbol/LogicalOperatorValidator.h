//
// Created by mohamed on 3/30/23.
//

#ifndef COMPILERPROJECT_LOGICALOPERATORVALIDATOR_H
#define COMPILERPROJECT_LOGICALOPERATORVALIDATOR_H


#include "SymbolValidator.h"

class LogicalOperatorValidator : public SymbolValidator {
private:
    std::string symbols[3] = {"<", "<=", "="};
public:
    Type validateAndGetType(std::string token) override;

};


#endif //COMPILERPROJECT_LOGICALOPERATORVALIDATOR_H
