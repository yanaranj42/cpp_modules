#ifndef A_SPELL_HPP
# define A_SPELL_HPP

#include <iostream>


class ATarget;

class ASpell
{
	private:
		std::string _name;
		std::string _effects;
	public:
		ASpell();
		ASpell(const std::string &name, const std::string &effects);
		ASpell(ASpell const &cp);
		ASpell &operator=(ASpell const &op);
		virtual ~ASpell();

		const std::string getName() const;
		const std::string getEffects() const;
		void launch(const ATarget &ref) const;
		
		virtual ASpell *clone() const = 0;
};

#include "ATarget.hpp"
#endif
