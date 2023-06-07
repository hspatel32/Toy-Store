// Name: Harsh Shaileshkumar Patel
// Student id: 144928206
// Section: OOP345-ZAA
// Professor: Cornel barna 
// E-mail: hspatel32@myseneca.ca

#include <iomanip>
#include <string>
#include "Toy.h"

using namespace std;
namespace sdds 
{
	void sdds::Toy::update(int numItems)
	{
		m_numOfItems = numItems;
	}
	
	Toy::Toy(const string& toy)
	{
		string str = toy;
		string orderID, name, numOfItems, price;

		orderID = str.substr(0, str.find(":"));
		str.erase(0, str.find(":") + 1);
		name = str.substr(0, str.find(":"));
		str.erase(0, str.find(":") + 1);
		numOfItems = str.substr(0, str.find(":"));
		str.erase(0, str.find(":") + 1);
		price = str.substr(0, str.find(":"));
		str.erase(0, str.find(":") + 1);
		name.erase(0, name.find_first_not_of(' '));
		name.erase(name.find_last_not_of(' ') + 1);

		m_orderID = stoi(orderID);
		m_name = name;
		m_numOfItems = stoi(numOfItems);
		m_price = stod(price);
	}
	
	ostream& operator<<(ostream& os, const Toy& toy)
	{
		double subTotal = toy.m_price * double(toy.m_numOfItems);
		double tax = subTotal * toy.m_tax;
		double total = subTotal + tax;

		os << "Toy";
		os << setw(8) << toy.m_orderID << ":";
		os << right << setw(18) << toy.m_name;
		os << setw(3) << toy.m_numOfItems;
		
		os << " items" << setw(8) << fixed << setprecision(2) << toy.m_price;
		os << "/item  subtotal:" << setw(7) << fixed << setprecision(2) << subTotal;
		os << " tax:" << setw(6) << fixed << setprecision(2) << tax;
		os << " total:" << setw(7) << fixed << setprecision(2) << total << endl;

		return os;
	}
}

