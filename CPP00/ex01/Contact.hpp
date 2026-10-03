#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iomanip>

class Contact
{
public:
	Contact();
	~Contact();

	void	put_first_name(const std::string &value);
	void	put_last_name(const std::string &value);
	void	put_surname(const std::string &value);
	void	put_phone_nb(const std::string &value);
	void	put_dark_secret(const std::string &value);


	const std::string& get_first_name() const;
	const std::string& get_last_name() const;
	const std::string& get_surname() const;
	const std::string& get_phone_nb() const;
	const std::string& get_dark_secret() const;

private:
	std::string first_name;
	std::string last_name;
	std::string surname;
	std::string	phone_nb;
	std::string	dark_secret;
};
#endif
