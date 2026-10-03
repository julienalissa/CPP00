#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::put_first_name(const std::string& value)
{
	first_name = value;
}

const std::string& Contact::get_first_name() const
{
	return (first_name);
}
