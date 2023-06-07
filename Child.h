// Name: Harsh Shaileshkumar Patel
// Student id: 144928206
// Section: OOP345-ZAA
// Professor: Cornel barna 
// E-mail: hspatel32@myseneca.ca

#ifndef SDDS_CHILD_H
#define SDDS_CHILD_H

#include <iostream>
#include <string>
#include "Toy.h"

namespace sdds {
	class Child
	{

	private:
		Toy* toy{};
		size_t m_num;
		std::string m_childName;
		int m_age;

	public:
		Child();
		Child& operator=(const Child& child);
		Child(const Child& child);
		Child(Child&& child) noexcept;
		Child& operator=(Child&& child) noexcept;
		~Child();

		Child(std::string name, int age, const Toy* toys[], size_t count);
		size_t size() const;
		friend std::ostream& operator<<(std::ostream& os, const Child& child);
	};
}
#endif // !SDDS_CHILD_H
