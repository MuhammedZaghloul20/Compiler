//
// Created by mohamed on 3/31/23.
//

#include "KeyWordValidator.h"

Type KeyWordValidator::validateAndGetType(std::string token) {
    for (const auto &x: symbols) {
        if (x == token)
            return KeyWord;
    }
    return Identifier;
}
