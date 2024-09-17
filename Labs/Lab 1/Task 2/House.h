#pragma once
#include <iostream>
using std::string;

class House {

	private:
		string owner;
		string address;
		int bedrooms;
		long double price;

	public:
		House(){} // default contructor
		void setOwner(string name);
		void setAddress(string location);
		void setBedrooms(int noOfBedroom);
		void setPrice(long double amount);
		string getOwner() const;
		string getAddress() const;
		int getBedrooms() const;
		long double getPrice() const;
};