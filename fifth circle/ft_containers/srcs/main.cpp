#include "../includes/stack.hpp"
#include "../includes/color.hpp"
#include "../includes/equal.hpp"
#include "../includes/lexicographical_compare.hpp"
#include "../includes/is_integral.hpp"
#include "../includes/pair.hpp"
#include "../includes/make_pair.hpp"
#include "../includes/enable_if.hpp"
#include "../includes/iterator_traits.hpp"
#include "../includes/reverse_iterator.hpp"
#include "../includes/vector.hpp"

//##### Pour tests :
#include <vector>
// #include <type_traits>
#include <utility>  //pour pair
#include <stack>
// MAIN
#define TESTED_TYPE int

// map::key_comp
#include <iostream>
#include <map> // A SUPP
#include "../includes/map.hpp"


#include <list>

#define TESTED_TYPE int

int		main(void)
{
	std::list<TESTED_TYPE> lst;
	std::list<TESTED_TYPE>::iterator lst_it;
	for (int i = 1; i < 5; ++i)
		lst.push_back(i * 3);

	ft::vector<TESTED_TYPE> vct(lst.begin(), lst.end());

	lst_it = lst.begin();
	for (int i = 1; lst_it != lst.end(); ++i)
		*lst_it++ = i * 5;
	vct.assign(lst.begin(), lst.end());

	vct.insert(vct.end(), lst.rbegin(), lst.rend());
	return (0);
}
/*int		main(void)
{
	const int size = 5;
	ft::vector<TESTED_TYPE> vct(size);
	ft::vector<TESTED_TYPE>::iterator it_ = vct.begin();
	ft::vector<TESTED_TYPE>::reverse_iterator it(it_);

	for (int i = 0; i < size; ++i)
		vct[i] = (i + 1) * 5;
	std::cout << "size : " << vct.size() << std::endl;

	std::cout << (it_ == it.base()) << std::endl;
	std::cout << (it_ == (it + 3).base()) << std::endl;

	std::cout << *(it.base() + 1) << std::endl;
	std::cout << *(it - 3) << std::endl;
	std::cout << *(it - 3).base() << std::endl;
	it -= 3;
	std::cout << *it.base() << std::endl;

	std::cout << "TEST OFFSET" << std::endl;
	std::cout << *(it) << std::endl;
	std::cout << *(it).base() << std::endl;
	std::cout << *(it - 0) << std::endl;
	std::cout << *(it - 0).base() << std::endl;
	std::cout << *(it - 1).base() << std::endl;

	return (0);
}*/

/*#define TESTED_TYPE int

int		main(void)
{
	{
    const int size = 5;
	ft::vector<TESTED_TYPE> vct(size);
	ft::vector<TESTED_TYPE> vct2(10);
	ft::vector<TESTED_TYPE>::reverse_iterator it = vct.rbegin();
	ft::vector<TESTED_TYPE>::reverse_iterator ite = vct2.rbegin();
	// ft::vector<TESTED_TYPE>::const_reverse_iterator ite = vct.rbegin();

	for (int i = 0; i < size; ++i)
	{
    it[i] = (size - i) * 5;
    std::cout << " it[" << i << "] : " <<  it[i]<< std::endl;

  }
  std::cout << GREEN << " start it:" << *it << END <<std::endl;
	it = it + 5;
  std::cout << GREEN << " it:" << *it << END <<std::endl;
	it = 1 + it;
  std::cout << GREEN << " it:" << *it << END <<std::endl;
	it = it - 4;
  std::cout << GREEN << " it:" << *it << END <<std::endl;

	std::cout << RED << *(it += 2) << std::endl;
	std::cout << *(it -= 1) << END << std::endl;

	*(it -= 2) = 42;
	*(it += 2) = 21;

  for (int i = 0; i < size; ++i)
  std::cout << YELLOW " it[" << i << "] : " <<  it[i]<< END << std::endl;

	std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

	std::cout << "(it == const_it): " << (ite == it) << std::endl;
	std::cout << "(const_ite - it): " << (ite - it) << std::endl;
	std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

	std::cout << vct.size() << std::endl;
  }


  {
    const int size = 5;
	std::vector<TESTED_TYPE> vct(size);
	std::vector<TESTED_TYPE> vct2(10);
	std::vector<TESTED_TYPE>::reverse_iterator it = vct.rbegin();
	std::vector<TESTED_TYPE>::reverse_iterator ite = vct2.rbegin();
	// ft::vector<TESTED_TYPE>::const_reverse_iterator ite = vct.rbegin();

	for (int i = 0; i < size; ++i)
	{
    it[i] = (size - i) * 5;
    std::cout << " it[" << i << "] : " <<  it[i]<< std::endl;

  }

  std::cout << GREEN << " start it:" << *it << END <<std::endl;

	it = it + 5;
  std::cout << GREEN << " it:" << *it << END <<std::endl;
	it = 1 + it;
  std::cout << GREEN << " it:" << *it << END <<std::endl;
	it = it - 4;
  std::cout << GREEN << " it:" << *it << END <<std::endl;

	std::cout <<  RED << *(it += 2) << std::endl;
	std::cout << *(it -= 1) << END << std::endl;

	*(it -= 2) = 42;
	*(it += 2) = 21;

  for (int i = 0; i < size; ++i)
  std::cout << CYAN " it[" << i << "] : " <<  it[i]<< END << std::endl;

	std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

	std::cout << "(it == const_it): " << (ite == it) << std::endl;
	std::cout << "(const_ite - it): " << (ite - it) << std::endl;
	std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

	std::cout << vct.size() << std::endl;}
	return (0);
}


*/





















// int main ()
// {
// try
// {
//  // STD
//   {
//   std::cout << YELLOW "STD : \n" END ;
    
//   std::vector<int> myvector;

//   // set some values (from 1 to 10)
//   for (int i=1; i<=10; i++) myvector.push_back(i);

//   // erase the 6th element

//   // erase the first 3 elements:
//   myvector.erase (myvector.begin(),myvector.end());

//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<myvector.size(); ++i)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';

//   }
// //FT
//   {
//   std::cout << MAGENTA "FT : \n" END ;
//    ft::vector<int> myvector;

//   // set some values (from 1 to 10)
//   for (int i=1; i<=10; i++) myvector.push_back(i);

//   // erase the 6th element

//   // erase the first 3 elements:
//   myvector.erase (myvector.begin(),myvector.end());

//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<myvector.size(); ++i)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';

//   }


// 	// if (amande < claire)
// 	// 	std::cout << HIGHBLUE "<\n" END;
// 	// else
// 	// 	std::cout << RED "=\n" END;



// 	/*for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
// 		std::cout << ' ' << *it;*/
 	
// //   ft::vector<int> nous(5, 2);
// // 	std::cout << MAGENTA << "valeur du premier nb: "<< *(nous.begin()) << END << std::endl;

//   // std::cout << YELLOW << "On a " << nous.size() << " elements et non vide => " << nous.empty() << END << std::endl;
//   // std::cout << MAGENTA << "On a " << youhou.size() << " elements et non vide => " << youhou.empty() << END << std::endl;
  
// }
// catch (const std::out_of_range& oor)
// {
//   std::cerr << "Out of Range error: " << oor.what() << '\n';
// }
// catch (std::bad_alloc& ba) // pour proteger allocate()
// {
//   std::cerr << "bad_alloc caught: " << ba.what() << '\n';
// }
// catch (std::exception &e)
// {
//   std::cerr << "exception caught\n";
// }

//   return 0;
// }





























// MAIN stack //
/*int main () {
  std::cout << CYAN "****STD****\n";
  std::stack<int> stackstd;
  stackstd.push(1);
  std::cout <<  GREEN "push 1 elem" END << std::endl; 
  std::cout <<  CYAN "valeur: " << stackstd.top() << END << std::endl; 
  std::cout << "size: " << stackstd.size() << std::endl; 
  stackstd.push(2);
  stackstd.push(3);
  std::cout <<  GREEN "push 2 elem" END << std::endl; 
  std::cout <<  CYAN "valeur: " << stackstd.top() << END << std::endl; 
  std::cout << "size: " << stackstd.size() << std::endl; 
  stackstd.pop();
  std::cout <<  GREEN "pop 1 elem" END << std::endl; 
  std::cout <<  CYAN "valeur: " << stackstd.top() << END << std::endl; 
  std::cout << "size: " << stackstd.size() << std::endl; 

  std::cout << YELLOW "\n****FT****\n";
  ft::stack<int> stackint;
  stackint.push(1);
  std::cout <<  MAGENTA "push 1 elem" END << std::endl; 
  std::cout <<  YELLOW "valeur: " << stackint.top() << END << std::endl; 
  std::cout << "size: " << stackint.size() << std::endl; 
  stackint.push(2);
  stackint.push(3);
  std::cout <<  MAGENTA "push 2 elem" END << std::endl; 
  std::cout <<  YELLOW "valeur: " << stackint.top() << END << std::endl; 
  std::cout << "size: " << stackint.size() << std::endl; 
  stackint.pop();
  std::cout <<  MAGENTA "pop 1 elem" END << std::endl; 
  std::cout <<  YELLOW "valeur: " << stackint.top() << END << std::endl; 
  std::cout << "size: " << stackint.size() << std::endl; 
  return 0;
}*/


// MAIN iterator_traits //
/*int main() {
  typedef ft::iterator_traits<int*> traits;
  if (typeid(traits::iterator_category)==typeid(std::random_access_iterator_tag))
    std::cout << "int* is a random-access iterator";
  std::cout << std::endl;
  return 0;
}*/


// MAIN enable if//
// 1. the return type (bool) is only valid if T is an integral type:
/*template <class T>
typename ft::enable_if<ft::is_integral<T>::value,bool>::type is_odd (T i) {return bool(i%2);}
// 2. the second template argument is only valid if T is an integral type:
template < class T, class = typename ft::enable_if<ft::is_integral<T>::value>::type>
bool is_even (T i) {return !bool(i%2);}
int main() {
  short int i = 1;    // code does not compile if type of i is not integral
  std::cout << std::boolalpha;
  std::cout << "i is odd: " << is_odd(i) << std::endl;
  std::cout << "i is even: " << is_even(i) << std::endl;
  return 0;
}*/


// MAIN make pair //
/*int main() {

int x = 42;
std::string str = "Wouaf";
ft::pair<int, std::string> pairons;
pairons = ft::make_pair(x, str);
  std::cout << "first : " << pairons.getFirst() << " second : " << pairons.getSecond() << std::endl;
  std::cout << std::endl;
  return 0;
}*/


// MAIN PAIR //
/*int main() {

int i = 0;
std::string str = "coucou";
std::cout << MAGENTA "\nFT :\n " END;
ft::pair<int, std::string> toto;
toto.setFirst(i); toto.setSecond(str);
std::cout << "first : " << toto.getFirst() << " second : " << toto.getSecond() << std::endl;
ft::pair<int, std::string> tom(toto);
std::cout << "tom first : " << tom.getFirst() << " tom second : " << tom.getSecond() << std::endl;
ft::pair<int, std::string> linda(42, "je suis lindaaaaaa");
std::cout << "linda first : " << linda.getFirst() << " linda second : " << linda.getSecond() << std::endl;
linda = tom;
std::cout << "POST linda first : " << linda.getFirst() << " POST linda second : " << linda.getSecond() << std::endl;
std::cout << "*************OPERATOR*************  " << std::endl;

  ft::pair<int,char> foo (10,'z');
  ft::pair<int,char> bar (90,'a');

  if (foo==bar) std::cout << "foo and bar are equal\n";
  if (foo!=bar) std::cout << "foo and bar are not equal\n";
  if (foo< bar) std::cout << "foo is less than bar\n";
  if (foo> bar) std::cout << "foo is greater than bar\n";
  if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
  if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

std::cout << YELLOW "STD :\n " END;
std::pair<int, std::string> tutu;
tutu.first = i;
tutu.second = str;
std::pair<int, std::string> tata (tutu);

std::cout << "first : " << tata.first << std::endl;
std::cout << "second : " << tata.second << std::endl;

// std::pair<int, std::string>(i, str);

  std::cout << std::endl;
  return 0;
}*/



// MAIN POUR is_integral C++ 11//
/*int main() {
  std::cout << std::boolalpha;
  std::cout << YELLOW "STD :\n " END;

 std::cout << "is_integral:" << std::endl;
  std::cout << "char: " << std::is_integral<char>::value << std::endl;
  std::cout << "int: " << std::is_integral<int>::value << std::endl;
  std::cout << "float: " << std::is_integral<float>::value << std::endl;
std::cout << MAGENTA "\nFT :\n " END;
  std::cout << "is_integral:" << std::endl;
  std::cout << "char: " << ft::is_integral<char>::value << std::endl;
  std::cout << "int: " << ft::is_integral<int>::value << std::endl;
  std::cout << "float: " << ft::is_integral<float>::value << std::endl;
  return 0;
}*/


/*
// MAIN POUR LEXICO //
bool mycomp (char c1, char c2)
{ return std::tolower(c1)<std::tolower(c2); }

int main () {
  char foo[]="Apple";
  char bar[]="apartment";

  std::cout << std::boolalpha;

  std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

  std::cout << YELLOW "STD : Using default comparison (operator<): " END;
  std::cout << std::lexicographical_compare(foo,foo+5,bar,bar+9);
  std::cout <<  '\n' ;
  std::cout << MAGENTA "FT : Using default comparison (operator<): " END;
  std::cout << ft::lexicographical_compare(foo,foo+5,bar,bar+9);
  std::cout << '\n';

  std::cout << YELLOW "\nSTD : Using mycomp as comparison object: " END;
  std::cout << std::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp);
  std::cout << '\n';
std::cout << MAGENTA "FT : Using mycomp as comparison object: " END;
  std::cout << ft::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp);
  std::cout << '\n';

  return 0;
}


// MAIN POUR EQUAL //
bool mypredicate (int i, int j) {
  return (i==j);
}

int main()
{
	int myints[] = {20,40,60,80,100};               //   myints: 20 40 60 80 100
  	std::vector<int>myvector (myints,myints+5);     // myvector: 20 40 60 80 100
									// int myints[] = {'a', 'b', 'b', 'c'};
									// std::vector<char>myvector (myints,myints+4);

	std::cout << GREY "\n--- Equal --- \n" END;
	if ( std::equal (myvector.begin(), myvector.end(), myints) )
		std::cout << YELLOW "STD : The contents of both sequences are equal.\n" END;
	if ( ft::equal (myvector.begin(), myvector.end(), myints) )
		std::cout << MAGENTA "FT : The contents of both sequences are equal.\n" END;



	if ( std::equal (myvector.begin(), myvector.end(), myints, mypredicate) )
		std::cout << YELLOW "\nSTD : The contents of both sequences are equal.\n" END;
	if ( ft::equal (myvector.begin(), myvector.end(), myints, mypredicate) )
		std::cout << MAGENTA "FT : The contents of both sequences are equal.\n" END;
	//std::cout << MAGENTA "--- lexicographical_compare --- \n" END;
	return (0);
}*/