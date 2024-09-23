#include "HouseHandler.h"
#include <iostream>
#include <limits>
#include <conio.h>

using namespace std;

void menu(){
    cout << "\n\nHOUSE MANAGER" << endl;
    cout << "\n1. Add Houses" << endl;
    cout << "2. Filter Houses" << endl;
    cout << "3. Display Houses" << endl;
    cout << "4. Exit" << endl;
    cout << "Press thy desire command, Master.\n\n";
}

int main() {
    HouseHandler houseHandler;
    menu();
    
    char choice;

    while(choice!='4'){
        choice = _getch();
        if (isdigit(choice)){
            switch (choice)
            {
            case '1':
                houseHandler.addHouse();
                menu();
                break;
            case '2': {
                int minBedroom, maxPrice;
                cout << "\nEnter Maximum Price : ";
                cin >> maxPrice;
                cout << "Enter Minimum Number of Bedrooms : ";
                cin >> minBedroom;
                cout << "Do you prefer a city? (? to ignore) : ";
                std::string city;
                cin >> city;
                houseHandler.fitlerHouse(maxPrice, minBedroom, city);
                menu();
                break;
            }
            case '3':
                houseHandler.displayData();
                menu();
                break;
            case '4':
                cout << "Exiting...." << endl;
                break;
            default:
                cout << "\nInvalid choice" << endl;
                menu();
                break;
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
    
}