#pragma once
#include <string>

class	Contact
{
	public:
		Contact(void);
		int			GetIndex(void) const;
		std::string	GetFirstName(void) const;
		std::string	GetLastName(void) const;
		std::string	GetNickName(void) const;
		std::string	GetPhoneNumber(void) const;
		std::string	GetDarkestSecret(void) const;
		void		WriteIndex(int num);
		void		WriteFirstName(std::string str);
		void		WriteLastName(std::string str);
		void		WriteNickName(std::string str);
		void		WritePhoneNumber(std::string str);
		void		WriteDarkestSecret(std::string str);
	private:
		int			m_index;
		std::string	m_first_name;
		std::string	m_last_name;
		std::string	m_nickname;
		std::string	m_phone_number;
		std::string	m_darkest_secret;
};
