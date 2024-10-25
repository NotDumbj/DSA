#include<iostream>
#include<string>
#include <Windows.h>
#undef max
#include<limits>
#include<conio.h>
#include<fstream>
#include"../libraries/pq1d.h"
using namespace std;
 
#define filename "data/data.txt"



bool isRunning = true;
void userUI(PriorityQueue1D &pQueue);
void loadData(PriorityQueue1D &pQ);

int main()
{
    SetConsoleTitleA("Priority Queue Manager");
    PriorityQueue1D pQueue;
    loadData(pQueue);
    userUI(pQueue);
    clog << "Exiting..." << endl;
    return 0;
}

void loadData(PriorityQueue1D &pQ)
{
    ifstream file(filename);
    if (!file.is_open()) 
    {
        throw std::runtime_error("Error opening file");
    }

    Node* pq = nullptr;
    string role, name;
    
    while (file >> role >> ws && getline(file, name)) 
    {
        int priority = pQ.getPriority(role);
        pQ.insert(name, role, priority);
    }

    file.close();
}

void userUI(PriorityQueue1D &pQueue)
{
    cout << "\n" << "PRIORITY QUEUE 1D" << endl;
    cout << string(15, '=') << endl;
    cout << "1. Display Items" << endl;
    cout << "2. Insert" << endl;
    cout << "3. Remove" << endl;
    cout << "4. Exit" << endl;
    cout << string(15, '=') << endl;
    cout << "Press the desire option number." << endl;
    char choice;
    while(isRunning)
    {
        if(!isRunning)
        {
            break;
        }
        choice = _getch();
        if(isdigit(choice))
        {
            bool isValid = true;
            string expression = "";

            switch(choice)
            {
                case '1':
                    cout << "\nItems: " << endl;
                    pQueue.display();
                    userUI(pQueue);
                    break;
                case '2':
                    cout << "\nInserting an Item: " << endl;
                    cout << "Choose the Priority Level: " << endl;
                    cout << "1. Student" << endl;
                    cout << "2. Teacher" << endl;
                    cout << "3. Parent" << endl;
                    cout << "=> ";
                    int priorityLevel;
                    if (cin >> priorityLevel)
                    {
                        cout << "\nEnter Name: " << endl;
                        string name;
                        cin.ignore();
                        getline(cin, name);
                        if (priorityLevel == 3)
                        {
                            pQueue.insert(name, "Parent", priorityLevel);
                        }
                        else if (priorityLevel == 2)
                        {
                            pQueue.insert(name, "Teacher", priorityLevel);
                        }
                        else if (priorityLevel == 1)
                        {
                            pQueue.insert(name, "Student", priorityLevel);
                        }
                    }
                    else
                    {
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
        else
        {
            cin.clear();
            while(_kbhit())
            {
                _getch();
            }
        }
    }


}