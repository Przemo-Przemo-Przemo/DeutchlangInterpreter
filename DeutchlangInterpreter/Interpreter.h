#pragma once
#include<iostream>
#include<string>
#include "Token.h"
#include "Lexer.h"

using namespace std;

class Interpreter
{
public:
    string type;
    string value;
    Lexer lexer;
    Token currentToken;

    Interpreter(string text)
    {
        lexer = Lexer(text);
        currentToken = lexer.getNextToken();
    }

    void updateCurrentToken();

    ///<summary>"eat" token and then update</summary>
    void eatAndUpdateCurrentToken(TokenType tokenType);

    void validateCurrentToken(TokenType tokenType);

    int eatAndUpdateNumberToken();

    int exprPrecedenceTwo();

    int exprPrecedenceOne();

    int expr();

    bool isOperationPrecedenceOne(TokenType tokenType);

    bool isOperationPrecedenceZero(TokenType tokenType);
};