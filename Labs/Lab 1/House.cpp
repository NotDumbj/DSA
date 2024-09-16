#include "House.h"
#include <string>
using std::string;

void House::setOwner(string name){
	owner = name.length() > 20 ? name.substr(0, 20) : name;
}
void House::setAddress(string location) {
	address = location.length() > 20 ? location.substr(0, 20) : location;
}
void House::setBedrooms(int noOfBedroom) {
	bedrooms = noOfBedroom;
}
void House::setPrice(float amount) {
	price = amount;
}
string House::getOwner() const {
	return owner;
}
string House::getAddress() const {
	return address;
}
int House::getBedrooms() const {
	return bedrooms;
}
float House::getPrice() const {
	return price;
}