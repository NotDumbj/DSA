#include<iostream>
#include<conio.h>
#include<string>
#include<limits>
#include<fstream>
#include"../libraries/pq2d.h"
using namespace std;

bool isRunning = true;

void userUI(PriorityQueue2d<string> pQueue);
void loadData(PriorityQueue2d<string> &pQueue);

int main()
{   
    PriorityQueue2d<string> pQueue;
    loadData(pQueue);
    userUI(pQueue);
    clog << "Exiting..." << endl;
    return 0;
}

void loadData(PriorityQueue2d<string> &pQueue){
    std::string path = "Assignments/Priority Queue 02/data/data.txt";
    std::ifstream inputFile(path);
    
    if(!inputFile.is_open())
    {
        std::cerr << "Error Msg: File not Opening." << std::endl;
        return;
    }

    string lineData;
    string name;
    while(std::getline(inputFile, lineData))
    {
        if (lineData == "Student")
        {
            std::getline(inputFile, lineData);
            pQueue.insert(3, lineData);  
        }
        else if (lineData == "Teacher")
        {
            std::getline(inputFile, lineData);
            pQueue.insert(2, lineData);  
        }
        else if (lineData == "Parent")
        {
            std::getline(inputFile, lineData);
            pQueue.insert(1, lineData);            
        }
    }
}

void userUI(PriorityQueue2d<string> pQueue){
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
                    pQueue.display();
                    userUI(pQueue);
                    break;
                case '2':
                    cout << "\nInserting an Item: " << endl;
                    cout << "Choose the Priority Level: " << endl;
                    cout << "1. Parent" << endl;
                    cout << "2. Teacher" << endl;
                    cout << "3. Student" << endl;
                    cout << "=> ";
                    int priorityLevel;
                    if (cin >> priorityLevel){
                        cout << "\nEnter Name: " << endl;
                        string name;
                        cin.ignore();
                        getline(cin, name);
                        pQueue.insert(priorityLevel, name);
                    }
                    else{
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cerr << "Error Msg: Invalid input" << endl;
                        break;
                    }
                    userUI(pQueue);
                    break;
                case '3':
                    cout << "\nDeleting... " << endl;
                    cout << "\nItem deleted: " << pQueue.remove() << endl;
                    userUI(pQueue);
                case '4':
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