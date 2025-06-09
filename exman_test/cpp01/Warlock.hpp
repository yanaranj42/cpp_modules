#pragma once

#include <iostream>
#include "ATarget.hpp"
#include "ASpell.hpp"
#include <map>

class Warlock
{
	private:
		std::string _name;
		std::string _title;
		Warlock();
		Warlock(const Warlock &copy);
		Warlock &operator=(const Warlock &op);

		std::map<std::string, ASpell *> arr;//void map
	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock();

		const std::string &getName() const;
		const std::string &getTitle() const;

		void setTitle(const std::string &title);
		void introduce() const;

		void learnSpell(ASpell *sPtr);
		void forgetSpell(std::string spellName);
		void launchSpell(std::string spellName, ATarget &ref);
};
