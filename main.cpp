#include <iostream>
#include "validators/Symbol/ArithmeticOperatorValidator.h"
#include "validators/Symbol/LogicalOperatorValidator.h"
#include "validators/Number/NumberValidator.h"
#include "validators/Identifier/IdentifierValidator.h"
#include "validators/Identifier/KeyWordValidator.h"
#include <set>


using std::endl;
using std::cout;

std::string getNameFromType(Type);

std::vector<std::string> split(const std::string &);


int main() {

    Validator validator = Validator();
    ArithmeticOperatorValidator arithmeticOperatorValidator = ArithmeticOperatorValidator();
    LogicalOperatorValidator logicalOperatorValidator = LogicalOperatorValidator();
    SymbolValidator symbolValidator = SymbolValidator();
    NumberValidator numberValidator = NumberValidator();
    IdentifierValidator identifierValidator = IdentifierValidator();
    KeyWordValidator keyWordValidator = KeyWordValidator();

    symbolValidator.addChild(&arithmeticOperatorValidator);
    symbolValidator.addChild(&logicalOperatorValidator);

    identifierValidator.addChild(&keyWordValidator);

    validator.addChild(&symbolValidator);
    validator.addChild(&identifierValidator);
    validator.addChild(&numberValidator);


    std::vector<std::string> tokens;
    std::string code = "if (x <= 20)\n then c = 15;";

    auto lineTokens = split(code);
    for (const auto &token: lineTokens)
        tokens.emplace_back(token);

    for (const auto &token: tokens) {
        cout << token << " " << getNameFromType(validator.validateAndGetType(token)) << endl;
    }
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

std::vector<std::string> split(const std::string &line) {
    auto tokens = std::vector<std::string>();
    auto counter = 0;
    std::set<char> delimiters = {';', '\n', '(', ')', '{', '}', ' '};
    std::string token;
    while (counter < line.length()) {
        if (delimiters.contains(line[counter])) {
            if (!token.empty())
                tokens.emplace_back(token);
            token = "";
        } else
            token += line[counter];
        counter++;
    }
    return tokens;
}
