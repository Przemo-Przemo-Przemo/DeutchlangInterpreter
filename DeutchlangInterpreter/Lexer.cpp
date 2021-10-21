#include "Token.h"
#include "Lexer.h"
#include <iostream>
using namespace std;

bool Lexer::isInTextsBounds()
{
    return textReadingIndex < text.length();
}

string Lexer::handleNumberInput()
{
    string number = string(1, currentTextChar);
    advanceTextChar();

    while (textReadingIndex < text.length() && isdigit(currentTextChar))
    {
        number += currentTextChar;
        advanceTextChar();
    }
    return number;
}

void Lexer::advanceTextChar()
{
    if (isInTextsBounds())
    {
        textReadingIndex++;
        currentTextChar = text[textReadingIndex];
    }
}

void Lexer::skipWhitespaces()
{
    while (text[textReadingIndex] == ' ' && isInTextsBounds())
    {
        advanceTextChar();
    }
}

Token Lexer::getNextToken()
{
    if (!isInTextsBounds())
    {
        return Token(TokenType::eof, "");
    }

    skipWhitespaces();

    if (isdigit(currentTextChar))
    {
        return Token(TokenType::number, handleNumberInput());
    }

    switch (currentTextChar)
    {
    case '+':
        advanceTextChar();
        return Token(TokenType::addition, "+");
    case '-':
        advanceTextChar();
        return Token(TokenType::substraction, "-");
    case '*':
        advanceTextChar();
        return Token(TokenType::multiplication, "*");
    case '/':
        advanceTextChar();
        return Token(TokenType::division, "/");
    case '(':
        advanceTextChar();
        return Token(TokenType::leftParen, "(");
    case ')':
        advanceTextChar();
        return Token(TokenType::rightParen, "(");
    }

    cout << "unidentified symbol at line: " << textReadingIndex;
    throw;
}
