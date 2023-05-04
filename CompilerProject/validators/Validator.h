//
// Created by mohamed on 3/30/23.
//
#include<vector>
#include <string>
#include "Types.h"



class Validator {
private:
    std::vector<Validator *> children = std::vector<Validator *>();
public:
    virtual Types validateAndGetType(std::string token);
    std::pair<Validator **, int> getChildren();

    void addChild(Validator *validator);

protected:
    Types validateAndGetTypeFromChildren(const std::string &token);

};

