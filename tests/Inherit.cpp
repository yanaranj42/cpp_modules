#include "Inherit.hpp"

/* We have to add ':Test("type")' in order to be able to init the attribbutes of
 * the Base class in our derived class */
Inherit::Inherit() : Test("Default"){
	_type = "Default";
	_type.append("_II");
	_word = "Inherit word";
	std::cout << _type << " Inherit constructor" << std::endl;
}
Inherit::Inherit(const std::string name) : Test(name){
	_word = "Eu sou bonita";
	std::cout << _type << " Inherit constructor" << std::endl;
}

Inherit::Inherit(const Inherit &copy){
	*this = copy;
	std::cout << _type << " Inherit copy Done" << std::endl;
}

Inherit &Inherit::operator=(const Inherit &op){
	if (this != &op)
		_type = op.getType();
	_type.append("_copy");
	return (*this);
}

Inherit::~Inherit(){
	std::cout << "Inherit Destructor" << std::endl;
}

std::string Inherit::getType() const{
	return (_type);
}

std::string Inherit::getWord() const {
	return (_word);
}
void Inherit::setWord(std::string newWord){
	_word = newWord;
}
