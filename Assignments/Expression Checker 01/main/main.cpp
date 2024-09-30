#include <iostream>
#include <conio.h>
#include <Windows.h>
#undef max
#include <limits>
#include "../libraries/ExpressionHandler.h"

using namespace std;

bool isRunning = true;

void userUI(ExpressionHandler expressionHandler){
    cout << "\n" << "EXPRESSION VALIDATOR" << endl;
    cout << string(15, '=') << endl;
    cout << "1. Enter an expression" << endl;
    cout << "2. Check expression from file" << endl;
    cout << "3. Exit" << endl;
    cout << string(15, '=') << endl;
    cout << "Press the desire option number." << endl;
    char choice;
    while(isRunning){
        if(!isRunning){
            break;
        }
        choice = _getch();
        if(isdigit(choice)){
            bool isValid = true;
            string expression = "";

            switch(choice){
                case '1':
                    cout << "\n";
                    cout << "Enter your expression: ";
                    cin >> expression;
                    isValid = expressionHandler.isValid(expression);
                    break;
                case '2':
                    if(expressionHandler.isfileReadable){
                        cout << "\n";
                        expressionHandler.displayData();
                        cout << "Enter the Line Number: ";
                        int lineNumber;
                        cout << "\n";
                        if(cin >> lineNumber){
                            if (0 < lineNumber && lineNumber <= expressionHandler.dataSize){
                                isValid = expressionHandler.checkExpression(lineNumber);
                            }
                            else{
                                cerr << "Error: Line Number Out of Range\n";
                            }
                        }
                        else{
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore other characters in int that can cause malfunctioning
                        }
                    } else{
                        cerr << "\nError: Cannot Read Expression File\n";
                    }
                    break;
                case '3':
                    clog << "Exiting..." << endl;
                    isRunning = false;
                    break;
                default:
                    cerr << "Error: Invalid choice." << endl;
                    userUI(expressionHandler);
                    break;
            }
            if(choice == '1' || choice == '2'){
                cout << "\nThe Expression is ";
                cout << (isValid ? "valid" : "not valid") << endl;
                system("pause");
                userUI(expressionHandler);
            }
        }
        else{
            cin.clear();
            while(_kbhit()){
                _getch();
            }
        }
    }


}
int main(){
    SetConsoleTitleA("Expression Validator");
    ExpressionHandler expHandler;

    userUI(expHandler);
    return 0;

}