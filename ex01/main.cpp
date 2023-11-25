#include "PhoneBook.hpp"
#include <iostream>

namespace
{
	int	action(std::string str);
}

int	main(void)
{
	std::string	input;

	std::cout << "\033[32m[PhoneBook]\033[0m" << std::endl;
	while(1)
	{
		std::cout << "\033[33mEnter ADD or SEARCH or EXIT: \033[0m" << std::flush;
		std::getline(std::cin, input);
		if (std::cin.eof() || action(input))
			return (0);
	}
	return (0);
}

namespace
{
	int	action(std::string str)
	{
		static PhoneBook	list;

		if (str == "ADD")
		{
			if (list.AddContact())
				return (1);
		}
		else if (str == "SEARCH")
		{
			if (list.SearchContact())
				return (1);
		}
		else if (str == "EXIT")
			return (1);
		return (0);
	}
}
