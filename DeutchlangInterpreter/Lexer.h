#pragma once
#include<string>
#include "Token.h"
class Lexer {
public:
    std::string text;
    size_t textReadingIndex = 0;
    char currentTextChar = text[textReadingIndex];

    Lexer(std::string text = "") : text(text) {}

    bool isInTextsBounds();

    std::string handleNumberInput();

    void advanceTextChar();

    void skipWhitespaces();

    Token getNextToken();
};