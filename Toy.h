// Name: Harsh Shaileshkumar Patel
// Student id: 144928206
// Section: OOP345-ZAA
// Professor: Cornel barna 
// E-mail: hspatel32@myseneca.ca

#ifndef SDDS_TOY_H
#define SDDS_TOY_H
#include <string>

namespace sdds {
	class Toy
	{
		unsigned int m_orderID;
		std::string m_name;
		int m_numOfItems;
		double m_price;
		double m_tax = 0.13;

	public:

		Toy() = default;
		void update(int numItems);
		Toy(const std::string& toy);
		friend std::ostream& operator<<(std::ostream& os, const Toy& toy);
	};
}
#endif // !SDDS_TOY_H
