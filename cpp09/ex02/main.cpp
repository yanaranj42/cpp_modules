#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	PmergeMe pg;

	if (ac > 1){
		try{
			pg.parse_input(ac, av);
		}
		catch (std::exception &ex){
			std::cout << "Exception: " << &ex.what();
			return 0;
		}
	}
	else
		std::runtime_error ("Please introduce values");
	return (0);
}
