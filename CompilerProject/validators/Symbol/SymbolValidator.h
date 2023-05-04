//
// Created by mohamed on 3/30/23.



#include "../Validator.h"

class SymbolValidator : public Validator {
private:
    std::string symbols[8] = {":", "+", "-", "*", "/", "<", "<=", "="};
public:
    Types validateAndGetType(std::string token) override;
};


