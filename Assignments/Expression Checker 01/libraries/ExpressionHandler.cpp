#include "ExpressionHandler.h"
#include "Stack.h"
#include <fstream>
#include <string>
#include <iostream>

ExpressionHandler::ExpressionHandler(){
    isfileReadable = true;
    dataSize = 0;
    loadData();
}

void ExpressionHandler::loadData(){
    std::ifstream expressionFile("data/expressions.txt");
    
    if(!expressionFile.is_open()){
        isfileReadable = false;
        std::cerr << "Error: Expressions file not Opening." << std::endl;
    }

    std::string expression;
    int lineIndex = 1;
    while(std::getline(expressionFile, expression)){
        data[lineIndex] = expression;
        lineIndex++;
        dataSize++;
    }
}

bool ExpressionHandler::checkExpression(int lineNumber){
    std::cout << data[lineNumber];
    return isValid(data[lineNumber]);
}

bool ExpressionHandler::isValid(string expression)
{
    int length = expression.length();
    Stack stack(length);
    char character;
    for (int i = 0; i < length; i++)
    {
        if(expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            stack.push(expression[i]);
        }
        else if(expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
        {
            if(stack.isEmpty())
            {
                return false;
            }
            else
            {
                character = stack.pop();
                if (!((character == '(' && expression[i] == ')')
                    || (character == '{' && expression[i] == '}')
                    || (character == '[' && expression[i] == ']'))){
                    return false;
                }
            }
        }
    }
    return true;
}

void ExpressionHandler::displayData(){
    for(auto& entry : data){
        std::cout << entry.first << ". " << entry.second << std::endl;
    }
}