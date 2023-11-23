#include <iostream>
#include "PhoneBook.hpp"

void	PhoneBook::AddContact(void)
{
	Contact		new_contact;
	std::string	temp_str;

	std::cout << "AddContact" << std::endl;

	std::cout << "first name:" << std::flush;
	std::cin >> temp_str;
	new_contact.WriteFirstName(temp_str);

	std::cout << "last name:" << std::flush;
	std::cin >> temp_str;
	new_contact.WriteLastName(temp_str);

	std::cout << "nickname:" << std::flush;
	std::cin >> temp_str;
	new_contact.WriteNickName(temp_str);

	std::cout << "phone number:" << std::flush;
	std::cin >> temp_str;
	new_contact.WritePhoneNumber(temp_str);

	std::cout << "darkest secret:" << std::flush;
	std::cin >> temp_str;
	new_contact.WriteDarkestSecret(temp_str);

	rotateContactList(new_contact);
	rewriteIndexNumber();
}

void	PhoneBook::rotateContactList(Contact &new_contact)
{
	for (int i = 1; i < 8; i++)
		list[i] = list[i - 1];
	list[0] = new_contact;
}

void	PhoneBook::rewriteIndexNumber(void)
{
	for (int i = 0; i < 8; i++)
		if (list[i].GetIndex() >= 0)
			list[i].WriteIndex(i);
}

void	PhoneBook::SearchContact(void)
{
	PhoneBook::printContactList();
}
