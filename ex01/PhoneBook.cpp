#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

namespace
{
	std::string	get_truncated_string(std::string str);
	int			get_input(std::string &str);
}

int	PhoneBook::AddContact(void)
{
	Contact		new_contact;
	std::string	temp_str;

	std::cout << "[AddContact]" << std::endl;
	new_contact.WriteIndex(0);

	std::cout << "first name:" << std::flush;
	if (get_input(temp_str))
		return (1);
	new_contact.WriteFirstName(temp_str);

	std::cout << "last name:" << std::flush;
	if (get_input(temp_str))
		return (1);
	new_contact.WriteLastName(temp_str);

	std::cout << "nickname:" << std::flush;
	if (get_input(temp_str))
		return (1);
	new_contact.WriteNickName(temp_str);

	std::cout << "phone number:" << std::flush;
	if (get_input(temp_str))
		return (1);
	new_contact.WritePhoneNumber(temp_str);

	std::cout << "darkest secret:" << std::flush;
	if (get_input(temp_str))
		return (1);
	new_contact.WriteDarkestSecret(temp_str);

	rotateContactList(new_contact);
	rewriteIndexNumber();
	return (0);
}

void	PhoneBook::rotateContactList(Contact &new_contact)
{
	for (int i = 7; i > 0; --i)
		m_list[i] = m_list[i - 1];
	m_list[0] = new_contact;
}

void	PhoneBook::rewriteIndexNumber(void)
{
	for (int i = 0; i < 8; ++i)
		if (m_list[i].GetIndex() >= 0)
			m_list[i].WriteIndex(i);
}

int	PhoneBook::SearchContact(void) const
{
	int	index;

	printContactList();
	std::cout << "\033[36mEnter index to check: \033[0m" << std::flush;
	std::cin >> index;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input" << std::endl;
		return (0);
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (std::cin.eof())
		return (1);
	--index;

	if (index < 0 || index > 7 || m_list[index].GetIndex() < 0)
		std::cout << "Invalid input" << std::endl;
	else
	{
		std::cout << "FIRST NAME: " << m_list[index].GetFirstName()
		<< "\nLAST NAME: " << m_list[index].GetLastName()
		<< "\nNICKNAME: " << m_list[index].GetNickName()
		<< "\nPHONE NUMBER: " << m_list[index].GetPhoneNumber()
		<< "\nDARKEST SECRET: " << m_list[index].GetDarkestSecret() << std::endl;
	}
	return (0);
}

void	PhoneBook::printContactList(void) const
{
	std::cout << std::right;

	std::cout << "\033[36m" << std::setw(10) << "INDEX" << " | "
	<< std::setw(10) << "FIRST NAME" << " | "
	<< std::setw(10) << "LAST NAME" << " | "
	<< std::setw(10) << "NICKNAME" << "\033[0m" << std::endl;
	std::cout
		<< "\033[36m-------------------------------------------------\033[0m"
		<< std::endl;

	for (int i = 0; i < 8; ++i)
		if (m_list[i].GetIndex() >= 0)
			std::cout
				<< "\033[033m"
				<< std::setw(10)
				<< m_list[i].GetIndex() + 1 << "\033[0m | "
				<< std::setw(10)
				<< get_truncated_string(m_list[i].GetFirstName()) << " | "
				<< std::setw(10)
				<< get_truncated_string(m_list[i].GetLastName()) << " | "
				<< std::setw(10)
				<< get_truncated_string(m_list[i].GetNickName()) << std::endl;
}

namespace
{
	int	get_input(std::string &str)
	{
		std::cin >> str;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (std::cin.eof())
			return (1);
		return (0);
	}

	std::string	get_truncated_string(std::string str)
	{
		std::string	output;

		output = str.substr(0, 10);
		if (str.length() > 10)
			output[9] = '.';
		return (output);
	}
}
