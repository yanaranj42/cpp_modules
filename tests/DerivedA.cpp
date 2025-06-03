#include "DerivedA.hpp"

DerivedA::DerivedA() : Test("Default"){
	_type = "Default";
	std::cout << _type << " DerivedA constructor" << std::endl;
}
DerivedA::DerivedA(const std::string name) : Test(name){
	std::cout << _type << " DerivedA constructor" << std::endl;
}

DerivedA::DerivedA(const DerivedA &copy){
	*this = copy;
	std::cout << _type << " DerivedA copy Done" << std::endl;
}

DerivedA &DerivedA::operator=(const DerivedA &op){
	if (this != &op)
		_type = op.getType();
	_type.append("_COPY");
	return (*this);
}

DerivedA::~DerivedA(){
	std::cout << "DerivedA Destructor" << std::endl;
}

std::string DerivedA::getType() const{
	return (_type);
}
