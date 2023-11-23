#pragma once
#include <string>

class	Contact
{
	public:
		Contact(void);
		Contact(Contact &source);
		int			GetIndex(void);
		std::string	GetFirstName(void);
		std::string	GetLastName(void);
		std::string	GetNickName(void);
		std::string	GetPhoneNumber(void);
		std::string	GetDarkestSecret(void);
		void		WriteIndex(int num);
		void		WriteFirstName(std::string str);
		void		WriteLastName(std::string str);
		void		WriteNickName(std::string str);
		void		WritePhoneNumber(std::string str);
		void		WriteDarkestSecret(std::string str);
	private:
		int			index;
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
};
