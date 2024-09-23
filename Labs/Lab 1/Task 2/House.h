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
		double rating;

		bool operator<(const House& other) const;
		House(){}
		House(std::string name, std::string location, int noOfBedroom, long double amount);
		void setOwner(string name);
		void setAddress(string location);
		void setBedrooms(int noOfBedroom);
		void setPrice(long double amount);
		string getOwner() const;
		string getAddress() const;
		int getBedrooms() const;
		long double getPrice() const;
};