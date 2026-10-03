#include "PhoneBook.hpp"


PhoneBook::PhoneBook(): count(0), next(0)
{

}

PhoneBook::~PhoneBook()
{

}

void	PhoneBook::add_contact(const Contact &c)
{
	contacts[next] = c;
	next = (next + 1) % 8;
	if (count < 8)
		count++;
}

int	PhoneBook::get_count()
{
	return (count);
}

const Contact &PhoneBook::get_contact(int index) const
{
	return (contacts[index]);
}
