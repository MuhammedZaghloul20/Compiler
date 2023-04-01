//
// Created by mohamed on 3/31/23.
//

#include "IdentifierValidator.h"

Type IdentifierValidator::validateAndGetType(std::string token) {
    if (token[0] >= '0' && token[0] <= '9')
        return Undefined;
    Type childType = validateAndGetTypeFromChildren(token);
    if (childType != Undefined)
        return childType;
    return Identifier;
}
