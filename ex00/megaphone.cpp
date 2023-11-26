#include <iostream>

namespace
{
	void	print_in_upper_case(char *str);
}

int	main(int ac, char *av[])
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < ac; ++i)
		print_in_upper_case(av[i]);
	std::cout << std::endl;
	return (0);
}

namespace
{
	void	print_in_upper_case(char *str)
	{
		for (char *ptr = str; *ptr; ++ptr)
			*ptr = std::toupper(*ptr);
		std::cout << str;
	}
}
