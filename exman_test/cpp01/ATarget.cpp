#include "ATarget.hpp"

ATarget::ATarget(){}

ATarget::ATarget(ATarget const &cp){
	*this = cp;
}

ATarget &ATarget::operator=(ATarget const &op){
	if (this != &op)
		_type = op.getType();
	return (*this);
}

ATarget::ATarget(const std::string &type) : _type(type){}

const std::string ATarget::getType() const{
	return _type;
}

void ATarget::getHitBySpell(ASpell const &ref) const{
	std::cout << _type << " has been " << ref.getEffects() << "!" << std::endl;
}

ATarget::~ATarget(){}
