// Name: Harsh Shaileshkumar Patel
// Student id: 144928206
// Section: OOP345-ZAA
// Professor: Cornel barna 
// E-mail: hspatel32@myseneca.ca

#ifndef SDDS_CONFIRMORDER_H
#define SDDS_CONFIRMORDER_H
#include "Toy.h"

namespace sdds
{
	class ConfirmOrder {
	private:
		const Toy** m_toy{ nullptr };
		size_t m_num{ 0 };

	public:
		ConfirmOrder() = default;


		ConfirmOrder& operator=(const ConfirmOrder& order);
		ConfirmOrder(ConfirmOrder& order);

		ConfirmOrder& operator=(ConfirmOrder&& order)noexcept;
		ConfirmOrder(ConfirmOrder&& order)noexcept;

		ConfirmOrder& operator+=(const Toy& toy);
		ConfirmOrder& operator-=(const Toy& toy);

		friend std::ostream& operator<<(std::ostream& os, const ConfirmOrder& order);
		~ConfirmOrder();
	};
}
#endif // !SDDS_CONFIRMORDER_H

