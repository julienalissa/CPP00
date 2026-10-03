#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::put_first_name(const std::string &value)
{
	first_name = value;
}

void	Contact::put_last_name(const std::string &value)
{
	last_name = value;
}

void	Contact::put_surname(const std::string &value)
{
	surname = value;
}

void	Contact::put_phone_nb(const std::string &value)
{
	phone_nb = value;
}

void	Contact::put_dark_secret(const std::string &value)
{
	dark_secret = value;
}


const std::string&	Contact::get_first_name() const
{
	return (first_name);
}

const std::string&	Contact::get_last_name() const
{
	return (last_name);
}

const std::string&	Contact::get_surname() const
{
	return (surname);
}

const std::string&	Contact::get_phone_nb() const
{
	return (phone_nb);
}

const std::string&	Contact::get_dark_secret() const
{
	return (dark_secret);
}
