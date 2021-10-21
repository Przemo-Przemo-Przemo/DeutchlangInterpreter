#pragma once
#include <string>
enum class TokenType
{
    none,
    eof,
    number,
    addition,
    substraction,
    multiplication,
    division,
    leftParen,
    rightParen
};

inline std::string tokenTypesAsStrings[] = { "eof" };

class Token {
public:
    TokenType tokenType;
    std::string tokenValue; //consider variant/ template

    Token(TokenType tokenType = TokenType::none, std::string tokenValue = "") 
        : tokenType(tokenType), tokenValue(tokenValue)
    {
    }

    std::string tokenRepresentation();
    std::string tokenTypeToString(TokenType tokenType);
};