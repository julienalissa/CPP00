#include "Contact.hpp"
#include <iostream>
#include "PhoneBook.hpp"


int	add_contact(PhoneBook pb)
{
	std::string	texte;
	Contact		contact;

	std::cout << "Insert the First Name : ";
	if (!std::getline(std::cin, texte))
		return (1);
	contact.put_first_name(texte);

	std::cout << "Insert the Last Name : ";
	if (!std::getline(std::cin, texte))
		return (1);
	contact.put_last_name(texte);

	std::cout << "Insert the surname : ";
	if (!std::getline(std::cin, texte))
		return (1);
	contact.put_surname(texte);

	std::cout << "Insert the phone number : ";
	if (!std::getline(std::cin, texte))
		return (1);
	contact.put_phone_nb(texte);

	std::cout << "Insert the dark secret : ";
	if (!std::getline(std::cin, texte))
		return (1);
	contact.put_dark_secret(texte);
	pb.add_contact(contact);
	return (0);
}

void	search(PhoneBook pb)
{
	int	count;
	int	i;

	i = 0;
	count = pb.get_count();
	std::cout << count << std::endl;
	while (i < count)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << pb.get_contact(i).get_first_name() << "|";
		std::cout << pb.get_contact(i).get_last_name() << "|";
		std::cout << pb.get_contact(i).get_surname() << "|";
		i++;
	}
}

int	main(void)
{
	// Contact	a;
	// Contact	b;


	// a.put_first_name("Prenom");
	// a.put_dark_secret("le secret");
	// b.put_first_name("prenom2");
	// b.put_dark_secret("le secret2");
	// pb.add_contact(a);
	// pb.add_contact(b);

	// std::cout << "Le nb de count : " << pb.get_count() << std::endl;
	// std::cout << "le [0] : " << pb.get_contact(0).get_first_name() << std::endl;
	// std::cout << "le [1] : " << pb.get_contact(1).get_first_name() << std::endl;

	PhoneBook pb;
	std::string line;

	std::cout << "Welcome to the phone book !" << std::endl;
	while (1)
	{
		std::cout << "You can enter you command : " << std::endl;
		if (!std::getline(std::cin, line))
			return (1);
		if (line == "Exit" || line == "EXIT" || line == "exit")
			break;
		else if (line == "Add" || line == "ADD" || line == "add")
		{
			if (add_contact(pb) == 1)
				return(1);
		}
		else if (line == "Search" || line == "SEARCH" || line == "search")
		{
			search(pb);
		}
		else
		{
			std::cout << "Unknown command" << std::endl;
		}
	}
	return (0);
}
