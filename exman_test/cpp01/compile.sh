#!/bin/bash


c++ -Wall -Werror -Wextra -std=c++98 Warlock.hpp Warlock.cpp main.cpp \
	ASpell.hpp ASpell.cpp ATarget.hpp ATarget.cpp \
	Fwoosh.hpp Fwoosh.cpp \
	Dummy.hpp Dummy.cpp

./a.out
