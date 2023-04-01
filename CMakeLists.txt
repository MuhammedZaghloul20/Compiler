cmake_minimum_required(VERSION 3.24)
project(CompilerProject)

set(CMAKE_CXX_STANDARD 23)

add_executable(CompilerProject main.cpp LexicalDetector.h validators/Validator.h validators/Type.h validators/Number/NumberValidator.cpp validators/Number/NumberValidator.h validators/Validator.cpp validators/Symbol/SymbolValidator.cpp validators/Symbol/SymbolValidator.h validators/Symbol/ArithmeticOperatorValidator.cpp validators/Symbol/ArithmeticOperatorValidator.h validators/Symbol/LogicalOperatorValidator.cpp validators/Symbol/LogicalOperatorValidator.h validators/Identifier/IdentifierValidator.cpp validators/Identifier/IdentifierValidator.h validators/Identifier/KeyWordValidator.cpp validators/Identifier/KeyWordValidator.h)
