#include "MutantStack.hpp"

int main()
{
	/* MUTANT STACK */

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "\nsize = " << mstack.size() << std::endl;
	std::cout << "derniere valeur ajoutee : " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size = " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << "\nsize = " << mstack.size() << std::endl;
	std::cout << "derniere valeur ajoutee : " << mstack.top() << std::endl;
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);

	MutantStack<int> copy(mstack);
	//std::cout << "\ncopy constructeur: size = " << copy.size() << std::endl;

	std::cout << "\n-------------------" << std::endl;


	/* VECTOR */
	std::vector<int> vec;
	vec.push_back(5);
	vec.push_back(17);
	std::cout << "size = " << vec.size() << std::endl;
	std::cout << "derniere valeur ajoutee : " << vec.front() << std::endl;
	vec.pop_back();
	std::cout << "size = " << vec.size() << std::endl;
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(737);
	vec.push_back(0);
	std::cout << "\nsize = " << vec.size() << std::endl;
	std::cout << "derniere valeur ajoutee : " << vec.front() << std::endl;
	
	std::vector<int>::iterator itV = vec.begin();
	std::vector<int>::iterator iteV = vec.end();
	++itV;
	--itV;
	std::cout << std::endl;
	while (itV != iteV)
	{
		std::cout << *itV << std::endl;
		++itV;
	}

	

return 0;
}