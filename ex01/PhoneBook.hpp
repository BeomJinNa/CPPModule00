#pragma once
#include "Contact.hpp"

class	PhoneBook
{
	public:
		void	AddContact(void);
		void	SearchContact(void);
	private:
		Contact	list[8];
		void	rewriteIndexNumber(void);
		void	rotateContactList(Contact &new_contact);
		void	printContactList(void);
		void	printContact(void);
};
