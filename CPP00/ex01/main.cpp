#include "Contact.hpp"
#include <iostream>

int	main(void)
{
	Contact contact;
	contact.put_first_name("Poulet");

	if (contact.get_first_name() != "Poulet")
	{
		std::cerr << "First name test failed" << std::endl;
		return (1);
	}
	std::cout << "First name test passed" << std::endl;
}
