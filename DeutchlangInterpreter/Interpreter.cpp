#include<iostream>
#include<string>
#include "Token.h"
#include "Lexer.h"
#include "Interpreter.h"

using namespace std;


void Interpreter::updateCurrentToken()
{
    currentToken = lexer.getNextToken();
}

///<summary>"eat" token and then update</summary>
void Interpreter::eatAndUpdateCurrentToken(TokenType tokenType)
{
    validateCurrentToken(tokenType);
    currentToken = lexer.getNextToken();
}

void Interpreter::validateCurrentToken(TokenType tokenType)
{
    if (currentToken.tokenType != tokenType)
    {
        cout << "current token is different than given tokenType" << endl;
    }
}

int Interpreter::eatAndUpdateNumberToken()
{
    eatAndUpdateCurrentToken(TokenType::number);
    return stoi(currentToken.tokenValue);
}

int Interpreter::exprPrecedenceTwo()
{
    Token element = currentToken;

    if (element.tokenType == TokenType::number)
    {
        eatAndUpdateCurrentToken(TokenType::number);
        return stoi(element.tokenValue);
    }

    if (element.tokenType == TokenType::leftParen)
    {
        eatAndUpdateCurrentToken(TokenType::leftParen);
        int result = expr();
        eatAndUpdateCurrentToken(TokenType::rightParen);
        return result;
    }
}

int Interpreter::exprPrecedenceOne()
{
    int result = exprPrecedenceTwo();

    while (isOperationPrecedenceOne(currentToken.tokenType))
    {
        Token operation = currentToken;

        switch (operation.tokenType)
        {
        case TokenType::multiplication:
            eatAndUpdateCurrentToken(TokenType::multiplication);
            result *= exprPrecedenceTwo();
            break;
        case TokenType::division:
            eatAndUpdateCurrentToken(TokenType::division);
            result /= exprPrecedenceTwo();
            break;
        default:
            cout << "unknown operation" << endl;
            throw;
        }
    }

    return result;
}

int Interpreter::expr()
{
    int result = exprPrecedenceOne();

    while (isOperationPrecedenceZero(currentToken.tokenType)) //refactor not to use boilerplate method
    {
        Token operation = currentToken;

        switch (operation.tokenType)
        {
        case TokenType::addition:
            eatAndUpdateCurrentToken(TokenType::addition);
            result += exprPrecedenceOne();
            break;
        case TokenType::substraction:
            eatAndUpdateCurrentToken(TokenType::substraction);
            result -= exprPrecedenceOne();
            break;
        default:
            cout << "unknown operation" << endl;
            throw;
        }
    }

    return result;
}

bool Interpreter::isOperationPrecedenceOne(TokenType tokenType)
{
    return
        tokenType == TokenType::multiplication ||
        tokenType == TokenType::division;
}

bool Interpreter::isOperationPrecedenceZero(TokenType tokenType)
{
    return
        tokenType == TokenType::addition ||
        tokenType == TokenType::substraction;
}