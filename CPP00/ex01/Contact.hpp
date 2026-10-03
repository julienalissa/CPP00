#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
public:
	Contact();
	~Contact();

	void put_first_name(const std::string &value);
	const std::string& get_first_name() const;

private:
	std::string first_name;
	std::string last_name;
	std::string surname;
	std::string	phone_nb;
	std::string	dark_secret;
};
#endif
