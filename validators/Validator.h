//
// Created by mohamed on 3/30/23.
//
#include<vector>
#include <string>
#include "Type.h"

#ifndef COMPILERPROJECT_VALIDATOR_H
#define COMPILERPROJECT_VALIDATOR_H

class Validator {
private:
    std::vector<Validator *> children = std::vector<Validator *>();
public:
    virtual Type validateAndGetType(std::string token);

    std::pair<Validator **, int> getChildren();

    void addChild(Validator *validator);

protected:
    Type validateAndGetTypeFromChildren(const std::string &token);
};

#endif //COMPILERPROJECT_VALIDATOR_H
