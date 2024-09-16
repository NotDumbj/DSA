#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include "House.h"
using namespace std;
using std::string;

House available[100];
int houseCounter = 0;

char choice;

void addHouse()
{
    do{
        string ownerName;
        string address;
        int bedrooms;
        long double price;

        House house;   

        cout << "-----------------" << endl;
        cout << "House No. " << houseCounter + 1 << endl;
        cout << "-----------------" << endl;
        cout << "Owner : ";

        getline(cin, ownerName);
        house.setOwner(ownerName);

        cout << "Address : ";
        getline(cin, address);
        house.setAddress(address);

        cout << "Bedrooms : ";
        cin >> bedrooms;
        house.setBedrooms(bedrooms);

        cout << "Price : ";

        cin >> price;
        house.setPrice(price);

        available[houseCounter] = house;
        houseCounter++;


        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Do you want to add another house? (y/n) : ";
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while(choice == 'y');

}
void displayHouse()
{
    cout << left << setw(15) << "Owner"
         << left << setw(20) << "Address" 
         << right << setw(10) << "Bedrooms" 
         << right << setw(10) << "Price" 
         << endl;

    cout << setfill('-') << setw(55) << "-" << setfill(' ') << endl;

    for (int i = 0; i < houseCounter; i++)
    {       
        if (houseCounter <= 99)
        {
            cout << left << setw(15) << available[i].getOwner() 
            << left << setw(20) << available[i].getAddress() 
            << right << setw(10) << available[i].getBedrooms()
            << right << setw(10) << available[i].getPrice()
            << endl;
        }
    }
}
int main() {
    addHouse();
    displayHouse();
}