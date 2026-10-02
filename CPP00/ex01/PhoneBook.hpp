#ifndef PhoneBook
#define PhoneBook

#include <string>
#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	// Methodes
	public:
	PhoneBook();

	~PhoneBook();

	//attributs
	private:
	Contact contacts[8];

};
#endif
