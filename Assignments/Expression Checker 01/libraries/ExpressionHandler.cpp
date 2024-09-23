#include "ExpressionHandler.h"
#include <Stack.h>
#include <fstream>
#include <iostream>

ExpressionHandler::ExpressionHandler(){
    loadData();
}

void ExpressionHandler::loadData(){
    std::ifstream expressionFile("../data/expressions.txt", std::ios::in);
    
    if(!expressionFile.is_open()){
        std::cerr << "Error opening expressions file" << std::endl;
        exit(1);
    }

    std::string expression;
    int lineIndex = 1;
    while(std::getline(expressionFile, expression)){
        data[lineIndex] = expression;
        lineIndex++;
    }
}

bool ExpressionHandler::checkExpression(int lineNumber){
    return isValid(data[lineNumber]);
}

bool ExpressionHandler::isValid(string expression)
{
    Stack stack;
    bool isValid;
    char exp;
    for (int i = 0; i < length(expression); i++)
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
                exp = stack.pop();
                if (exp == '(' && expression[i] == ')')
                {
                    isValid = true;
                }
                else if (exp == '{' && expression[i] == '}')
                {
                    isValid = true;
                }
                else if (exp == '[' && expression[i] == ']')
                {
                    isValid = true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
}

void ExpressionHandler::displayData(){
    for(auto& entry : data){
        std::cout << entry.first << ". " << entry.second << std::endl;
    }
}