//
// Created by mohamed on 3/30/23.
//

#ifndef COMPILERPROJECT_NUMBERVALIDATOR_H
#define COMPILERPROJECT_NUMBERVALIDATOR_H

#include "../Validator.h"

class NumberValidator : public Validator {
public:
    Type validateAndGetType(std::string token) override;
};


#endif //COMPILERPROJECT_NUMBERVALIDATOR_H
