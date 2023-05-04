//
// Created by mohamed on 3/31/23.
//



#include "../Validator.h"

class IdentifierValidator : public Validator {
public:
    Types validateAndGetType(std::string token) override;

};


