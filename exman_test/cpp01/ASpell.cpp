#include "ASpell.hpp"

ASpell::ASpell(){}

ASpell::ASpell(ASpell const &cp){
	*this = cp;
}
ASpell &ASpell::operator=(ASpell const &op){
	if (this != &op)
	{
		_name = op.getName();
		_effects = op.getEffects();
	}
	return (*this);
}

ASpell::ASpell(const std::string &name, const std::string &effects) : _name(name), _effects(effects){}

const std::string ASpell::getName() const{
	return _name;
}

const std::string ASpell::getEffects() const{
	return _effects;
}

void ASpell::launch(const ATarget &ref) const{
	ref.getHitBySpell((*this));
}

ASpell::~ASpell(){}
