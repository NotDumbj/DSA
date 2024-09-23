#include <iostream>
#include <conio.h>
#include "ExpressionHandler.h"

using namespace std;

void userUI(ExpressionHandler expressionHandler){
    cout << "\n" << "EXPRESSION VALIDATOR" << endl;
    cout << string("=" , 15);
    cout << "1. Enter an expression";
    cout << "2. Check expression from file";
    cout << "3. Exit" << endl;
    cout << string("=" , 15);
    cout << "Press the desire option number.";
    char choice;
    choice = _getch();
    if(isdigit(choice)){
        bool isValid = false;
        string expression;

        switch(choice){
            case '1':
                cout << "\n";
                cout << "Enter your expression: ";
                cin >> expression;
                isValid = expressionHandler.isValid(expression);
                break;
            case '2':
                cout << "\n";
                expressionHandler.displayData();
                cout << "Select the Line Number (1 - 10)";
                char lineNumberChar;
                lineNumberChar = _getch();
                if(isdigit(lineNumberChar)){
                    int lineNumber = int(lineNumberChar) - '0';
                    if (0 < lineNumber >= 10){
                        isValid = expressionHandler.checkExpression(lineNumber);
                    }
                }
                else{
                    cin.clear();
                    while(_kbhit){
                        _getch();
                        if (choice == '\r' || choice == '\n') {    // check for enter key, usually it's not a problem,
                            continue;                             // but sometimes it freezes the program
                        }
                    }
                }
                break;
            case '3':
                clog << "Exiting..." << endl;
                return;
            default:
                cerr << "Invalid choice." << endl;
                userUI(expressionHandler);
                break;
        }
        if(choice == '1' || choice == '2'){
            cout << "\nThe Expression is ";
            cout << isValid ? "not valid" : "valid";
            cout << endl;
            system("pause");
            userUI(expressionHandler);
        }
    }
    else{
        cin.clear();
        while(_kbhit){
            _getch();
            if (choice == '\r' || choice == '\n') {   
                continue;          
            }
        }
    }

}
int main(){
    ExpressionHandler expHandler;

    userUI(expHandler);
;

}