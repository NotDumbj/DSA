#pragma once
#include <iostream>
using std::string;

class House {

	private:
		string owner;
		string address;
		int bedrooms;
		float price;

	public:
		House(); // default contructor
		void setOwner(string name);
		void setAddress(string location);
		void setBedrooms(int noOfBedroom);
		void setPrice(float amount);
		string getOwner() const;
		string getAddress() const;
		int getBedrooms() const;
		float getPrice() const;
};