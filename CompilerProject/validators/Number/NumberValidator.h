//
// Created by mohamed on 3/30/23.
//


#include "../Validator.h"

class NumberValidator : public Validator {
public:
    Types validateAndGetType(std::string token) override;
};

