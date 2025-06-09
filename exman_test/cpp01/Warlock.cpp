#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title) : _name(name), _title(title){
	std::cout << _name << ": This looks like another boring day." << std::endl;
}
Warlock::~Warlock(){
	std::cout << _name << ": My job here is done!" << std::endl;
	this->arr.clear();//habra que iterar todo??
}

const std::string &Warlock::getName() const{
	return (_name);
}
const std::string &Warlock::getTitle() const{
	return (_title);
}

void Warlock::setTitle(const std::string &title){
	_title = title;
}

void Warlock::introduce() const{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *sPtr){
	if (sPtr)
		arr.insert(std::pair<std::string, ASpell *>(sPtr->getName(), sPtr->clone()));
		
}
void Warlock::forgetSpell(std::string spellName){
	std::map<std::string, ASpell *>::iterator it = arr.find(spellName);
	if (it != arr.end())
		delete it->second;
	arr.erase(spellName);
}
void Warlock::launchSpell(std::string spellName, ATarget &ref){
	ASpell *spell = arr[spellName];
	if (spell)
		spell->launch(ref);
}
