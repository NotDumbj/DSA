#include <iostream>
#include <limits>
#include "../libraries/list.h"

using namespace std;

void takeInput(int &input);
void printMenu();
void useList(LinkedList &list);

main()
{
    LinkedList list;
    useList(list);
}

void printMenu()
{
    cout << "1. Insertion at the start" << endl;
    cout << "2. Insertion at the end" << endl;
    cout << "3. Insertion at the middle" << endl;
    cout << "4. Deletion from the start" << endl;
    cout << "5. Deletion from the end" << endl;
    cout << "6. Deletion from the middle" << endl;
    cout << "7. Search for an element" << endl;
    cout << "8. Display the list" << endl;
    cout << "9. Exit" << endl;
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

void useList(LinkedList &list)
{
    int choice, input, index; // inputList used to input in list 
    do
    {
        takeInput(choice);
        if (choice == 1)
        {
            cout << "Enter the element to be inserted: ";
            cin >> input;
            list.iAS(input);
        }
        else if (choice == 2)
        {
            cout << "Enter the element to be inserted: ";
            cin >> input;
            list.iAE(input);
        }
        else if (choice == 3)
        {
            cout << "Enter the element to be deleted: ";
            cin >> input;
            cout << "Enter the index of the element: ":
            cin >> index;
            list.iAM(input,index);
        }
        else if (choice == 4)
        {
            cout << "Enter the element to be deleted: ";
            cin >> input;
            list.dAS(input);
        }
        else if (choice == 5)
        {
            cout << "Enter the element to be deleted: ";
            cin >> input;
            list.dAE(input);
        }
        else if (choice == 6)
        {
            cout << "Enter the index of the element: ";
            cin >> index;
            list.dAM(index);
        }
        else if (choice == 7)
        {
            cout << "Enter the element to search for: ";
            cin >> input;
            list.find(input);
        }
        else if (choice == 8)
        {
            list.traverse();
        }
    }
    while(choice != 9);
}