#include "HouseHandler.h"
#include "House.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
void HouseHandler::readData(){
    std::ifstream file("houses.csv");
    
    if(!(file.is_open())){
        cout << "File not found" << endl;
    }

    std::string line;
    while(getline(file, line)){
        std::string owner, address, bedroomsStr, priceStr;
        int bedrooms;
        long double price;

        std::stringstream iss(line);
        getline(iss, owner, ',');
        getline(iss, address, ',');
        getline(iss, bedroomsStr, ',');
        getline(iss, priceStr, ',');

        bedrooms = stoi(bedroomsStr);
        price = stold(priceStr);

        House house(owner, address, bedrooms, price);
        houses.push_back(house);
    }
}
void HouseHandler::writeData(){

}
HouseHandler::HouseHandler(){
    readData();
}
HouseHandler::~HouseHandler(){
    writeData();
}
void HouseHandler::addHouse(){  
    char choice;
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

        available->push_back(house);

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Do you want to add another house? (y/n) : ";
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while(choice == 'y');
}
void HouseHandler::fitlerHouse(int minPrice = 0, int maxBedrooms = 0, std::string city = "?"){

}
void HouseHandler::displayData(){
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