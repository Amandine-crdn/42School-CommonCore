#include "Base.hpp"
#include "A.hpp"

Base * generate(void)
{
    int x = (std::rand() % 3);
    switch (x)
    {
        case (0) : return (new A);
        case (1) : return (new B);
        case (2) : return (new C);
    }
    return (NULL);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	Base a;
	Base b;
	Base c;
	try
	{
		a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}catch(std::exception & e){}
	try
	{
		b = dynamic_cast<C&>(p);
		std::cout << "B" << std::endl;
	}catch(std::exception & e){std::cout << "error\n";}
	try
	{
		c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}catch(std::exception & e){}
}

int main()
{
    srand((unsigned)time(0));
	Base * ptr = generate();
	Base * ref = generate();

	identify(ptr);
	identify(*ref);
	delete ptr;
	delete ref;
	return (0);
}
