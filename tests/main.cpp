#include "Test.hpp"
#include "DerivedA.hpp"
#include "Inherit.hpp"
int main()
{
	/* Is just a simple test to see how dinamyc memory works*/
	{
		std::cout << BLUE"--------BASIC---------" << END << std::endl;
		std::cout << YELLOW"Stack" << std::endl;
		Test a;
		Test b(a);
		std::cout << "> a type is: " << a.getType() << std::endl;
		std::cout << "> b type is: " << b.getType() << std::endl;
		std::cout << std::endl;
		std::cout << BLUE"Heap" << std::endl;
		Test *c = new Test();
		//Test *d;
		std::cout << "> c type is: " << c->getType() << std::endl;
		std::cout << std::endl;
		delete c;
	}
	{
	/* Test where I see how the copies and dinamyc memory works*/
		std::cout << std::endl << BLUE"---------DERIVED_A---------" << END << std::endl;
		//DerivedA *cp = a;//error de conversion en la inicializacion
		std::cout << YELLOW"[Stack Derived init]\n" << END;
		DerivedA a("a");
		std::cout << YELLOW"[Heap Derived init]\n" << END;
		DerivedA *newA = new DerivedA();//does not generate a copy 'cause is just creatring a new class
		DerivedA *copy = newA;//We can't see the msg of copy because we are not pointing to the object, just the class (INVESTIGATE)
		std::cout << YELLOW"[Copy of stacked]\n" << END;
		DerivedA other = a;//is the copy of the stack class 'a'

		std::cout << GREEN"\na_Type: "  << a.getType() << std::endl;//stack class type
		std::cout << "cp_Type: "  << newA->getType() << std::endl;//heap class type
		std::cout << "copy_Type: "  << copy->getType() << std::endl;//does't have the _COPY.
		std::cout << "other_Type: "  << other.getType() << std::endl;//copy stack class type
		std::cout << END << std::endl;
		delete newA;
		//delete copy;//Is a copy, so we don't have to delete anything;
	}


	{
		/*Test where I interact with virtual method and virtual descructor*/
		std::cout << std::endl << BLUE"---------INHERIT---------" << END << std::endl;
//		Inherit a1 = new Inherit();//Error de conversion
		std::cout << YELLOW"Test class - Inherit class:" << END << std::endl;
		Test *a = new Inherit();
		std::cout << YELLOW"Inherit class - Inherit class:" << END << std::endl;
		Inherit *c = new Inherit("Pinky");
		std::cout << YELLOW"Copy Inherit class:" << END << std::endl;
		Test *cp = new Inherit (*(static_cast<const Inherit*>(c)));//copia del obj del ptr(???)

		std::cout << std::endl;
		std::cout << GREEN"Type: "  << a->getType() << std::endl;
		std::cout << "Type: "  << c->getType() << std::endl;
		std::cout << "Type copy: "  << cp->getType() << std::endl;
		std::cout << END;
		std::cout << BLUE"aWord:\t\t" << a->getWord() << std::endl;
		std::cout << BLUE"cpWord:\t\t" << cp->getWord() << std::endl;
		std::cout << BLUE"c_Word:\t\t" << c->getWord() << std::endl;
		c->setWord("Obrigada");
		std::cout << BLUE"c_newWord:\t" << c->getWord() << std::endl;
		std::cout << END << std::endl;
		delete a;
		delete c;
		delete cp;
	}
}
