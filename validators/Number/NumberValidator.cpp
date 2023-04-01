//
// Created by mohamed on 3/30/23.
//

#include "NumberValidator.h"

Type NumberValidator::validateAndGetType(std::string token) {
    for (auto x: token) {
        if(x == '-')
            continue;
        if (x > '9' || x < '0')
            return Undefined;
    }
    return Number;
}