#include <iostream>
#include "validators/Symbol/ArithmeticOperatorValidator.h"
#include "validators/Symbol/LogicalOperatorValidator.h"
#include "validators/Number/NumberValidator.h"
#include "validators/Identifier/IdentifierValidator.h"
#include "validators/Identifier/KeyWordValidator.h"


using std::endl;
using std::cout;

std::string getNameFromType(Type);

int main() {

    ArithmeticOperatorValidator arithmeticOperatorValidator = ArithmeticOperatorValidator();
    LogicalOperatorValidator logicalOperatorValidator = LogicalOperatorValidator();
    SymbolValidator symbolValidator = SymbolValidator();
    NumberValidator numberValidator = NumberValidator();
    IdentifierValidator identifierValidator = IdentifierValidator();
    KeyWordValidator keyWordValidator = KeyWordValidator();
    Validator validator = Validator();

    symbolValidator.addChild(&arithmeticOperatorValidator);
    symbolValidator.addChild(&logicalOperatorValidator);

    identifierValidator.addChild(&keyWordValidator);

    validator.addChild(&symbolValidator);
    validator.addChild(&identifierValidator);
    validator.addChild(&numberValidator);

    cout << getNameFromType(validator.validateAndGetType("+")) << endl;
    cout << getNameFromType(validator.validateAndGetType(":")) << endl;
    cout << getNameFromType(validator.validateAndGetType("<")) << endl;
    cout << getNameFromType(validator.validateAndGetType("if")) << endl;
    cout << getNameFromType(validator.validateAndGetType("variableName")) << endl;
    cout << getNameFromType(validator.validateAndGetType("123")) << endl;
    return 0;
}

std::string getNameFromType(Type type) {
    switch (type) {
        case Number:
            return "Number";
        case KeyWord:
            return "Keyword";
        case Identifier:
            return "Identifier";
        case Symbol:
            return "Symbol";
        case ArithmeticOperator:
            return "ArithmeticOperator";
        case LogicalOperator:
            return "LogicalOperator";
        default:
            return "Undefined";
    }
}