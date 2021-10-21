// DeutchlangInterpreter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Interpreter.h"
using namespace std;

int main()
{
    while (true)
    {
        string text; getline(cin, text);
        Interpreter interpreter = Interpreter(text);
        cout << interpreter.expr() << endl;
    }
}