//
// Created by mohamed on 3/31/23.
//

#include "IdentifierValidator.h"

Types IdentifierValidator::validateAndGetType(std::string token) {
    if (token[0] < 'A' || token[0] > 'z')
        return Undefined;
    Types childType = validateAndGetTypeFromChildren(token);
    if (childType != Undefined)
        return childType;
    return Identifier;
}
