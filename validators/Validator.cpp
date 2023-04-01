//
// Created by mohamed on 3/30/23.
//
#include "Validator.h"

Type Validator::validateAndGetType(std::string token) { return validateAndGetTypeFromChildren(token); }

std::pair<Validator **, int> Validator::getChildren() {
    Validator *temp[children.size()];
    std::copy(children.begin(), children.end(), temp);
    return std::pair(temp, children.size());
}

void Validator::addChild(Validator *validator) { children.emplace_back(validator); }

Type Validator::validateAndGetTypeFromChildren(const std::string &token) {
    for (auto x: children) {
        Type result = x->validateAndGetType(token);
        if (result != Undefined)
            return result;
    }
    return Undefined;
}

