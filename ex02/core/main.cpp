#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base *generate(void){
	Base *base;

    srand(time(0) ^ clock());
    int r = rand()%3;

	if (r == 0)
		base = new A;
	else if (r== 1)
		base = new B;
	else
		base = new C;
	
	std::cout << r << std::endl;
	return (base);
}

void identify(Base* p){
	if (dynamic_cast <A *>(p) != NULL)
		std::cout << "it was A !" << std::endl;
	else if (dynamic_cast <B *>(p) != NULL)
		std::cout << "it was B !" << std::endl;
	else if (dynamic_cast <C *>(p) != NULL)
		std::cout << "it was C !" << std::endl;
	else
		std::cout << "error, no matching type" << std::endl;
}

void identify(Base& p){

	Base test;

	try {
		test = dynamic_cast <A &>(p);
		std::cout << "it was A !" << std::endl;
	} catch (std::exception &e){
		try{
			test = dynamic_cast <B &>(p);
			std::cout << "it was B !" << std::endl;
		} catch (std::exception &e){
			try{
				test = dynamic_cast <C &>(p);
				std::cout << "it was C !" << std::endl;
			} catch (std::exception &e){
				std::cout << "error, no matching type" << std::endl;
			}
		}
	}

}

int main() {
	A *aaa = new A;
	B *bbb = new B;
	C *ccc = new C;

	identify(aaa);
	identify(bbb);
	identify(ccc);

	Base *base = generate();
	identify(base);

	identify(*aaa);
	identify(*bbb);
	identify(*ccc);
	identify(*base);

	delete aaa;
	delete bbb;
	delete ccc;
	delete base;
}