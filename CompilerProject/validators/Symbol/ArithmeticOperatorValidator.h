
#include "SymbolValidator.h"

class ArithmeticOperatorValidator : public SymbolValidator {
private:
    char symbols[4] = {'*', '+', '/', '-'};
public:
    Types validateAndGetType(std::string token) override;

};


