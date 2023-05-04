//
// Created by mohamed on 3/30/23.
//

#include "LogicalOperatorValidator.h"

Types LogicalOperatorValidator::validateAndGetType(std::string token) {
    for(const auto& x: symbols){
        if(x == token)
            return LogicalOperator;
    }
    return Undefined;
}
