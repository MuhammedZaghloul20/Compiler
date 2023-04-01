//
// Created by mohamed on 3/30/23.
//

#include "SymbolValidator.h"

Type SymbolValidator::validateAndGetType(std::string token) {
    bool exists = false;
    for (const auto &x: symbols) {
        if (x == token) {
            exists = true;
            break;
        }
    }
    if (!exists)
        return Undefined;
    Type childType = validateAndGetTypeFromChildren(token);
    if (childType != Undefined)
        return childType;
    return Symbol;
}
