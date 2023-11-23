#include "PhoneBook.hpp"
#include <iostream>

namespace
{
	int	action(std::string str);
}

int	main(void)
{
	std::string	input;

	std::cout << "PhoneBook" << std::endl;
	while(1)
	{
		std::cout << "Enter ADD or SEARCH or EXIT" << std::endl;
		std::cin >> input;
		if (action(input))
			return (0);
	}
	return (0);
}

namespace
{
	static PhoneBook	list;

	int	action(std::string str)
	{
		if (str == "ADD")
			list.AddContact();
		else if (str == "SEARCH")
			list.SearchContact();
		else if (str == "EXIT")
			return (1);
		return (0);
	}
}
