

#include "SymbolValidator.h"

class LogicalOperatorValidator : public SymbolValidator {
private:
    std::string symbols[3] = {"<", "<=", "="};
public:
    Types validateAndGetType(std::string token) override;

};

