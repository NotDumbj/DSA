#include <iostream>
#include <limits>
#include "list.h"

using namespace std;

void takeInput(int &input);
void printMenu();
void useList(LinkedStr &list);

main()
{
    LinkedStr list;
    useList(list);
    system("pause");
    return 0;
}

void printMenu()
{
    cout << "LIST MANAGER" << endl;
    cout << "1. Make List" << endl;
    cout << "2. Remove First" << endl;
    cout << "3. Remove Last" << endl;
    cout << "4. Remove First and Last Element" << endl;
    cout << "5. Remove a specific element" << endl;
    cout << "6. Display the list" << endl;
    cout << "7. Exit" << endl;
}

void takeInput(int &input)
{
    bool check = false;
    do
    {
        system("cls");
        printMenu();
        cout << "Enter the input: ";
        if(cin >> input)
        {
            check = false;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Invalid input. Please enter a valid integer." << endl;
            check = true;
            system("pause");
        }
    }
    while(check);
}

void useList(LinkedStr &list)
{
    int choice, input, index; // inputList used to input in list 
    do
    {
        takeInput(choice);
        if (choice == 1)
        {
            cout << "Enter the length of the list: ";
            cin >> input;
            list.makeStr(input);
        }
        else if (choice == 2)
        {
            list.removeFirst();
            cout << "List after first element removed: ";
            list.displayStr();
        }
        else if (choice == 3)
        {
            list.removeLast();
            cout << "List after last element removed: ";
            list.displayStr();
        }
        else if (choice == 4)
        {
            list.removeFirst();
            list.removeLast();
            cout << "List after first and last element removed: ";
            list.displayStr();
        }
        else if (choice == 5)
        {
            cout << "Enter the element to delete from list: ";
            cin >> input;
            list.remove(input);
            cout << "List after element \"" << input << "\" removed: ";
            list.displayStr();
        }
        else if (choice == 6)
        {
            cout << "Values in the Linked List are: ";
            list.displayStr();
        }
        system("pause");
    }
    while(choice != 7);
}