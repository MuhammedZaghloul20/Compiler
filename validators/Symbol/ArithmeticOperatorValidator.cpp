//
// Created by mohamed on 3/30/23.
//

#include "ArithmeticOperatorValidator.h"

Type ArithmeticOperatorValidator::validateAndGetType(std::string token) {
    for(auto x: symbols){
        if(x == token[0])
            return ArithmeticOperator;
    }
    return Undefined;
}
