#include "Contact.hpp"
#include <iostream>
#include "PhoneBook.hpp"


int	add_contact(PhoneBook &pb)
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

std::string	ten_element(const std::string &str)
{
	std::string string;

	if (str.length() > 10)
	{
		string = str.substr(0, 9) + ".";
		return (string);
	}
	return (str);
}

void	display_contact(PhoneBook &pb)
{
	int	count;
	int	i;

	i = 0;
	count = pb.get_count();
	if (count == 0)
	{
		std::cout << "Phonebook is empty" << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
	while (i < count)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << ten_element(pb.get_contact(i).get_first_name()) << "|";
		std::cout << std::setw(10) << ten_element(pb.get_contact(i).get_last_name()) << "|";
		std::cout << std::setw(10) << ten_element(pb.get_contact(i).get_surname()) << "|" << std::endl;
		i++;
	}
}

int	display_index(PhoneBook &pb)
{
	int			count;
	int			index;
	std::string line;

	count = pb.get_count();
	std::cout << "Enter index : ";
	if (!std::getline(std::cin, line))
		return (1);
	index = line[0] - '0';
	if (line.length() != 1 || line[0] < '0' || line[0] >'9' || index >= count)
	{
		std::cout << "Invalid index" << std::endl;
		return (0);
	}
	std::cout << "First name : " << pb.get_contact(index).get_first_name() << std::endl;
	std::cout << "Last name : " << pb.get_contact(index).get_last_name() << std::endl;
	std::cout << "Nickname : " << pb.get_contact(index).get_surname() << std::endl;
	std::cout << "Phone number : " << pb.get_contact(index).get_phone_nb() << std::endl;
	std::cout << "Darkest secret : " << pb.get_contact(index).get_dark_secret() << std::endl;
	return (0);
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
			display_contact(pb);
			if (display_index(pb) == 1)
				return (1);
		}
		else
		{
			std::cout << "Unknown command" << std::endl;
		}
	}
	return (0);
}
