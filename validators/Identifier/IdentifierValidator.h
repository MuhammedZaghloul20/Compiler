//
// Created by mohamed on 3/31/23.
//

#ifndef COMPILERPROJECT_IDENTIFIERVALIDATOR_H
#define COMPILERPROJECT_IDENTIFIERVALIDATOR_H


#include "../Validator.h"

class IdentifierValidator : public Validator {
public:
    Type validateAndGetType(std::string token) override;

};


#endif //COMPILERPROJECT_IDENTIFIERVALIDATOR_H
