#pragma once
#include "Contact.hpp"

class	PhoneBook
{
	public:
		int		AddContact(void);
		int		SearchContact(void) const;
	private:
		Contact	m_list[8];
		void	printContactList(void) const;
		void	rotateContactList(Contact &new_contact);
		void	rewriteIndexNumber(void);
};
