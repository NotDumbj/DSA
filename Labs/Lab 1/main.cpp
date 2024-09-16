#include <iostream>
#include <string>
#include <limits>
#include "House.h"
using std::cout, std::cin, std::endl, std::max, std::numeric_limits, std::streamsize;
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
        int price;

        House house;

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
    for (int i = 0; i < houseCounter; i++)
    {
        if (houseCounter == 0)
        {
            cout << "No houses available" << endl;
            return;
        }
        if (houseCounter <= 99)
        {
            cout << "Owner : " << available[i].getOwner() << endl;
            cout << "Address : " << available[i].getAddress() << endl;
            cout << "Bedrooms : " << available[i].getBedrooms() << endl;
            cout << "Price : " << available[i].getPrice() << endl;
        }
    }
}
int main() {
    addHouse();
    displayHouse();
}