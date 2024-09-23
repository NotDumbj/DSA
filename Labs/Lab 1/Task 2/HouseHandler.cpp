#include "HouseHandler.h"  // hmm... 
#include "House.h"        // obv it is a house handler
#include <map>           // for better handling of data
#include <algorithm>    // for sort function
#include <limits>      // for clear inputs
#include <fstream>    // for file handling
#include <sstream>   // for string stream
#include <string>   // for getline
#include <cstring> // for string comparison

using namespace std;

void HouseHandler::readData(){
    std::ifstream file("Labs/Lab 1/Task 2/houses.txt");
    
    if(!(file.is_open())){
        cout << "File not found" << endl;
    }

    std::string line;
    while(getline(file, line)){
        std::string owner, address, bedroomsStr, priceStr;
        int bedrooms;
        long double price;

        std::stringstream iss(line);
        getline(iss, owner, '|');
        getline(iss, address, '|');
        getline(iss, bedroomsStr, '|');
        getline(iss, priceStr, '|');

        bedrooms = stoi(bedroomsStr);
        price = stold(priceStr);

        House house(owner, address, bedrooms, price);
        available.push_back(house);
    }
}
void HouseHandler::writeData(){
    std::ofstream file("Labs/Lab 1/Task 2/houses.txt", ios_base::app);
    
    if(!(file.is_open())){
        cout << "File not found" << endl;
    }

    for(const auto &house : available){
        file << house.getOwner() << "|"
             << house.getAddress() << "|"
             << house.getBedrooms() << "|"
             << house.getPrice() << "\n";
    }
}
HouseHandler::HouseHandler(){
    available.reserve(MAX_HOUSES);
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
   

        cout << "-----------------" << endl;
        cout << "Enter House Details:" << endl;
        cout << "-----------------" << endl;
        cout << "Owner : ";

        getline(cin, ownerName);

        cout << "Address : ";
        getline(cin, address);

        cout << "Bedrooms : ";
        cin >> bedrooms;

        cout << "Price : ";
        cin >> price;

        House house(ownerName, address, bedrooms, price);
        available.push_back(house);

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Do you want to add another house? (y/n) : ";
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
    } while(choice == 'y');
}

void HouseHandler::fitlerHouse(int maxPrice, int minBedrooms, std::string city){
    double priceBedroomRatio = 0;
    if(!(minBedrooms)){
        priceBedroomRatio = maxPrice / (double)minBedrooms;
    }

    std::map<House, double> filterHouse;

    for (const auto& house : available){
        if(house.getPrice() <= maxPrice && house.getBedrooms() >= minBedrooms){
            filterHouse[house] = house.rating;
        }
    }

    if(!(city == "?")){
        for (std::pair<const House, double> &entry : filterHouse){
            size_t commaPos = entry.first.getAddress().find_last_of(", ") == std::string::npos ? entry.first.getAddress().find_last_of(",") : entry.first.getAddress().find_last_of(", ");
            if(commaPos != std::string::npos){
                string cityName = entry.first.getAddress().substr(commaPos + 1);
                if(_stricmp(cityName.c_str(), city.c_str()) == 0){
                    entry.second = 0;
                }
            }
        }
    }

    cout << left << setw(15) << "Owner"
         << left << setw(20) << "Address" 
         << right << setw(10) << "Bedrooms" 
         << right << setw(10) << "Price" 
         << endl;

    cout << setfill('-') << setw(55) << "-" << setfill(' ') << endl;

    bool bestPick = false;

    for (const auto& pair : filterHouse)
    {
        if (!bestPick){
            cout << left << setw(15) << pair.first.getOwner() 
            << left << setw(20) << pair.first.getAddress() 
            << right << setw(10) << pair.first.getBedrooms()
            << right << setw(10) << pair.first.getPrice()
            << "     (BEST PICK)" << endl;
            cout << setfill('*') << setw(55) << "*" << setfill(' ') << endl;
            bestPick = true;
        }
        else {
            cout << left << setw(15) << pair.first.getOwner() 
            << left << setw(20) << pair.first.getAddress() 
            << right << setw(10) << pair.first.getBedrooms()
            << right << setw(10) << pair.first.getPrice()
            << endl;
        }
    }
}

void HouseHandler::displayData(){
        cout << left << setw(15) << "Owner"
         << left << setw(20) << "Address" 
         << right << setw(10) << "Bedrooms" 
         << right << setw(10) << "Price" 
         << endl;

    cout << setfill('-') << setw(55) << "-" << setfill(' ') << endl;

    for (const auto& house : available)
    {
        cout << left << setw(15) << house.getOwner() 
            << left << setw(20) << house.getAddress() 
            << right << setw(10) << house.getBedrooms()
            << right << setw(10) << house.getPrice()
            << endl;
    }

    system("pause");
}