#include "Contact.hpp"

Contact::Contact(void)
	:	index(-1),
		first_name(""),
		last_name(""),
		nickname(""),
		phone_number(""),
		darkest_secret("") {}

int			Contact::GetIndex(void) { return (index); }
std::string	Contact::GetFirstName(void) { return (first_name); }
std::string	Contact::GetLastName(void) { return (last_name); }
std::string	Contact::GetNickName(void) { return (nickname); }
std::string	Contact::GetPhoneNumber(void) { return (phone_number); }
std::string	Contact::GetDarkestSecret(void) { return (darkest_secret); }

void		Contact::WriteIndex(int num) { index = num; }
void		Contact::WriteFirstName(std::string str) { first_name = str; }
void		Contact::WriteLastName(std::string str) { last_name = str; }
void		Contact::WriteNickName(std::string str) { nickname = str; }
void		Contact::WritePhoneNumber(std::string str) { phone_number = str; }
void		Contact::WriteDarkestSecret(std::string str) { darkest_secret = str; }
