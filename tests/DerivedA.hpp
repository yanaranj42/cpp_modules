#ifndef DERIVED_A_HPP
# define DERIVED_A_HPP

#include <iostream>
#include "Test.hpp"

class DerivedA : public Test
{
	public:
		DerivedA();
		DerivedA(const std::string name);
		DerivedA(const DerivedA &cp);
		DerivedA &operator=(const DerivedA &op);
		~DerivedA();
		
		std::string getType() const;
};

#endif
