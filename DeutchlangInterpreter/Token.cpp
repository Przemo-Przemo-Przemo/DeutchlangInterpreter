#include <string>
#include "Token.h"
using namespace std;

string Token::tokenRepresentation()
{
    return "Token(" + tokenTypeToString(tokenType) + "," + tokenValue + ")";
}

string Token::tokenTypeToString(TokenType tokenType)
{
    return tokenTypesAsStrings[static_cast<int>(tokenType)];
}
