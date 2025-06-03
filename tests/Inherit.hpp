#ifndef INHERIT_HPP
# define INHERIT_HPP

#include <iostream>
#include "Test.hpp"

class Inherit : public Test
{
	public:
		Inherit();
		Inherit(const std::string name);
		Inherit(const Inherit &cp);
		Inherit &operator=(const Inherit &op);
		~Inherit();
		
		std::string getType() const;
		std::string getWord() const;
		void setWord(std::string newWord);
};

#endif
