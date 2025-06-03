#include "Test.hpp"

Test::Test() : _type("Default"){
	_type = "Hola";
	_word = "base word";
	std::cout << _type << " Base constructor" << std::endl;
}
Test::Test(const std::string name) : _type(name){
	std::cout << _type << " Base constructor" << std::endl;
}

Test::Test(const Test &copy){
	*this = copy;
	std::cout << _type << " Base copy Done" << std::endl;
}

Test &Test::operator=(const Test &op){
	if (this != &op)
		_type = op.getType();
	_type.append("_COPY");
	return (*this);
}

Test::~Test(){
	//std::cout << _type << " Base Non Virtual Destructor" << std::endl;
	std::cout << _type << " Base Virtual Destructor" << std::endl;
}

std::string Test::getType() const{
	return (_type);
}

std::string Test::getWord() const{
	return _word;
}
