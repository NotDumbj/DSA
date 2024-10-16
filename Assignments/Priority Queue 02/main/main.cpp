#include<iostream>
#include<conio.h>
#include<string>
#include"../libraries/PriorityQueue.h"
using namespace std;

bool isRunning = true;

void userUI(PriorityQueue2D<string> pQueue){
    cout << "\n" << "PRIORITY QUEUE 2D" << endl;
    cout << string(15, '=') << endl;
    cout << "1. Display Items" << endl;
    cout << "2. Insert" << endl;
    cout << "3. Remove" << endl;
    cout << "4. Exit" << endl;
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
                    cout << "\nItems: " << endl;
                    pQueue.displayItems();
                    userUI(pQueue);
                    break;
                case '2':
                    cout << "\nInserting an Item: " << endl;
                    cout << "Choose the Priority Level: " << endl;
                    cout << "1. Student" << endl;
                    cout << "2. Teacher" << endl;
                    cout << "3. Parent" << endl;
                    char priorityLevel;
                    priorityLevel = _getch();
                    if (isdigit(priorityLevel)){
                        cout << "\nEnter Name: " << endl;
                        string name;
                        getline(cin, name);
                        pQueue.insertItem(priorityLevel, name);
                    }
                    else{
                        cin.clear();
                        while(_kbhit()){
                            _getch();
                        }
                    }
                    userUI(pQueue);
                    break;
                case '3':
                    cout << "\nDeleting... " << endl;
                    cout << "\nItem deleted: " << pQueue.removeItem() << endl;
                    userUI(pQueue);
                case '4':
                    clog << "Exiting..." << endl;
                    isRunning = false;
                    break;
                default:
                    cerr << "Error: Invalid choice." << endl;
                    userUI(pQueue);
                    break;
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

int main()
{   
    PriorityQueue2D<string> pQueue;
    pQueue.loadData();
    userUI(pQueue);
    return 0;
}