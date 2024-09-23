#include <iostream>
#include <iomanip>
#include "House.h"
#include <vector>
#define MAX_HOUSES 100

class HouseHandler{
private:
    std::vector<House> available;
    void readData();
    void writeData();
public:
    HouseHandler();
    ~HouseHandler();
    void addHouse();
    void fitlerHouse(int minPrice=0, int maxBedrooms=0, std::string city="?");
    void displayData();
};
