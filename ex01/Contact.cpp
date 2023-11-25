#include "Contact.hpp"

Contact::Contact(void)
	:	m_index(-1),
		m_first_name(""),
		m_last_name(""),
		m_nickname(""),
		m_phone_number(""),
		m_darkest_secret("") {}

int			Contact::GetIndex(void) const { return (m_index); }
std::string	Contact::GetFirstName(void) const { return (m_first_name); }
std::string	Contact::GetLastName(void) const { return (m_last_name); }
std::string	Contact::GetNickName(void) const { return (m_nickname); }
std::string	Contact::GetPhoneNumber(void) const { return (m_phone_number); }
std::string	Contact::GetDarkestSecret(void) const { return (m_darkest_secret); }

void		Contact::WriteIndex(int num) { m_index = num; }
void		Contact::WriteFirstName(std::string str) { m_first_name = str; }
void		Contact::WriteLastName(std::string str) { m_last_name = str; }
void		Contact::WriteNickName(std::string str) { m_nickname = str; }
void		Contact::WritePhoneNumber(std::string str) { m_phone_number = str; }
void		Contact::WriteDarkestSecret(std::string str) { m_darkest_secret = str; }
