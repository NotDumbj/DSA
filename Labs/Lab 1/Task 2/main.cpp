#include "HouseHandler.h"
#include <iostream>
using std::cout, std::endl, std::cin;

void menu(){
    cout << "\n1. Add Houses" << endl;
    cout << "2. Filter Houses" << endl;
    cout << "3. Display Houses" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice : ";
}

int main() {
    HouseHandler houseHandler;
    menu();
    
    int choice;

    while(choice!=4){
        cin >> choice;
        switch (choice)
        {
        case 1:
            houseHandler.addHouse();
            break;
        case 2: {
            int minBedroom, maxPrice;
            cout << "\nEnter Maximum Price : ";
            cin >> maxPrice;
            cout << "Enter Minimum Number of Bedrooms : ";
            cin >> minBedroom;
            cout << "Do you prefer a city? (? to ignore) : ";
            std::string city;
            cin >> city;
            houseHandler.fitlerHouse(maxPrice, minBedroom, city);
            break;
        }
        case 3:
            houseHandler.displayData();
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
        menu();
    }
    
}