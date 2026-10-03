#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();
	int		get_count();
	void	add_contact(const Contact &c);
	const Contact &get_contact(int index) const;
private:
	Contact contacts[8];
	int	count;
	int	next;
};

#endif
