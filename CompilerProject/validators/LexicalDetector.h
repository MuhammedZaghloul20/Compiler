#include<unordered_map>
#include <vector>
#include<iostream>

using std::string;

class LexicalDetector {
public:
    LexicalDetector() { initializeTokens(); }

private:
    std::unordered_map<string, std::vector<string>> tokens;

    void initializeTokens();

    void addOperatorsToTokens();

    void addArithmeticOperators();

    void addLogicalOperators();

    void addReservedWords();
};

void LexicalDetector::initializeTokens() {
    addOperatorsToTokens();
    addReservedWords();
}

void LexicalDetector::addOperatorsToTokens() {
    addArithmeticOperators();
    addLogicalOperators();
}

void LexicalDetector::addArithmeticOperators() {
    std::vector<string> operators = std::vector<string>();
    operators.emplace_back("+");
    operators.emplace_back("-");
    operators.emplace_back("*");
    operators.emplace_back("/");
    tokens["arithmetic operator"] = operators;
}

void LexicalDetector::addLogicalOperators() {
    std::vector<string> operators = std::vector<string>();
    operators.emplace_back("<=");
    operators.emplace_back("=");
    tokens["logical operator"] = operators;
}

void LexicalDetector::addReservedWords() {
    auto words = std::vector<string>();
    words.emplace_back("if");
    words.emplace_back("else");
    words.emplace_back("end");
    words.emplace_back("repeat");
    words.emplace_back("until");
    words.emplace_back("write");
    words.emplace_back("read");
    words.emplace_back("then");
    tokens["key word"] = words;
}

