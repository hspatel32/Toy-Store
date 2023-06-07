// Name: Harsh Shaileshkumar Patel
// Student id: 144928206
// Section: OOP345-ZAA
// Professor: Cornel barna 
// E-mail: hspatel32@myseneca.ca

#include "ConfirmOrder.h"
#include "Toy.h"
#include <iostream>

using namespace std;
namespace sdds {

	ConfirmOrder::~ConfirmOrder() {
		delete[] m_toy;
		m_toy = nullptr;
	}

	ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& order) {
		if (this != &order) {

			m_num = order.m_num;
			delete[] m_toy;
			m_toy = new const Toy * [m_num];

			for (size_t i = 0; i < m_num; i++){
				m_toy[i] = order.m_toy[i];
			}
		}
                    return *this;
		
	}

	ConfirmOrder::ConfirmOrder(ConfirmOrder& order){
			*this = order;
		}

		ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder && order) noexcept
		{
			if (this != &order)
			{
				m_num = order.m_num;
				delete[] m_toy;
				m_toy = order.m_toy;
				order.m_toy = nullptr;
				order.m_num = 0;

			}

			return *this;
		}

		ConfirmOrder::ConfirmOrder(ConfirmOrder && order) noexcept
		{
			*this = move(order);
		}

		ConfirmOrder& ConfirmOrder::operator+=(const Toy & toy)
		{
			bool res = false;

			for (size_t i = 0; i < m_num; i++) {
				if (m_toy[i] == &toy)
					res = true;

			}

			if (!res)
			{
				const Toy** temp = nullptr;

				temp = new const Toy * [m_num + 1];

				for (size_t i = 0; i < m_num; i++)
				{
					temp[i] = m_toy[i];
				}
				temp[m_num] = &toy;
				m_num++;
				delete[] m_toy;
				m_toy = temp;
			}

			return *this;
		}

		ConfirmOrder& ConfirmOrder::operator-=(const Toy & toy)
		{
			bool res = false;

			for (size_t i = 0; i < m_num; i++) {
				if (m_toy[i] == &toy) {
					res = true;
				}
			}

			if (res)
			{

				for (size_t i = 0; i < m_num; i++)
				{
					if (m_toy[i] == &toy)
					{
						m_toy[i] = nullptr;
					}
				}

				m_num--;
			}
			return *this;
		}

		ostream& operator<<(ostream & os, const ConfirmOrder & order) {
			os << "--------------------------" << endl;
			os << "Confirmations to Send" << endl;
			os << "--------------------------" << endl;
			if (order.m_num == 0) {
				os << "There are no confirmations to send!\n";
			}

			else {

				for (size_t i = 0; i < order.m_num; i++) {
					if (order.m_toy[i] != nullptr)
						os << *order.m_toy[i];

				}
			}
			os << "--------------------------\n";

			return os;
		}
	}
	