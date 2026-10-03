#include "Contact.hpp"
#include <iostream>
#include "PhoneBook.hpp"

int	read_line(const std::string &msg, std::string &texte)
{
	while (1)
	{
		std::cout << msg;
		if (!std::getline(std::cin, texte))
			return (1);
		if (!texte.empty())
			return (0);
		std::cout << "It can't be empty" << std::endl;
	}
}

int	add_contact(PhoneBook &pb)
{
	std::string	texte;
	Contact		contact;

	if (read_line("Insert First Name : ", texte) == 1)
		return (1);
	contact.put_first_name(texte);

	if (read_line("Insert the Last Name : ", texte) == 1)
		return (1);
	contact.put_last_name(texte);

	if (read_line("Insert the surname : ", texte) == 1)
		return (1);
	contact.put_surname(texte);

	if (read_line("Insert the phone number : ", texte) == 1)
		return (1);
	contact.put_phone_nb(texte);

	if (read_line("Insert the dark secret : ", texte) == 1)
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
	if (line.length() != 1 || line[0] < '0' || line[0] >'9' || index >= count)
	{
		std::cout << "Invalid index" << std::endl;
		return (0);
	}
	index = line[0] - '0';
	if (index >= count)
	{
		std::cout << "Invlalid index" << std::endl;
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
	PhoneBook pb;
	std::string line;

	std::cout << "Welcome to the phone book !" << std::endl;
	while (1)
	{
		std::cout << "You can enter your command : " << std::endl;
		if (!std::getline(std::cin, line))
			break;
		if (line == "EXIT")
			break;
		else if (line == "ADD")
		{
			if (add_contact(pb) == 1)
				break;
		}
		else if (line == "SEARCH")
		{
			display_contact(pb);
			if (display_index(pb) == 1)
				break;
		}
		else
		{
			std::cout << "Unknown command" << std::endl;
		}
	}
	return (0);
}
