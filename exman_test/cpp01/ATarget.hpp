#ifndef A_TARGET_HPP
# define A_TARGET_HPP

#include <iostream>

class ASpell;

class ATarget
{
	private:
		std::string _type;
	public:
		ATarget();
		ATarget(const std::string &type);
		ATarget(ATarget const &cp);
		ATarget &operator=(ATarget const &op);
		virtual ~ATarget();

		const std::string getType() const;
		void getHitBySpell(ASpell const &ref) const;

		virtual ATarget *clone() const = 0;
};


#include "ASpell.hpp"
#endif
