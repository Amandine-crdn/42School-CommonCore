#include "../includes/utils/color.hpp"

#include "../includes/stack.hpp"
#include <stack>

#include "../includes/vector.hpp"
#include <vector>

#include "../includes/map.hpp"
#include <map>

// #include <type_traits>
#include <iostream>
#include <utility>  //pour pair
// MAIN
#define TESTED_TYPE int

// map::key_comp
#include <iterator>



// 🔥 MAIN map 🔥 //

// constructing maps
#include <iostream>
#include <map>

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

int main ()
{
	//constructors
	{
		std::cout << YELLOW "\nmap constructors std" END << std::endl;
		std::map<char,int> first;
		first['a']=10;
		first['b']=30;
		first['c']=50;
		first['d']=70;
		std::map<char,int> second (first.begin(),first.end());
		std::map<char,int> third (second);
		std::map<char,int,classcomp> fourth;				     // class as Compare
		bool(*fn_pt)(char,char) = fncomp;
		std::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
		std::cout << "everything went well" << std::endl;
	}
	{
		std::cout << MAGENTA "\nmap constructors ft" END << std::endl;
		ft::map<char,int> first;
		first['a']=10;
		first['b']=30;
		first['c']=50;
		first['d']=70;
		ft::map<char,int> second (first.begin(),first.end());
		ft::map<char,int> third (second);
		ft::map<char,int,classcomp> fourth;                 // class as Compare
		bool(*fn_pt)(char,char) = fncomp;
		ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
		std::cout << "everything went well" << std::endl;
	}
	//operator=
	{
		std::cout << YELLOW "\nmap operator= std\n" END << std::endl;
		std::map<char,int> first;
		std::map<char,int> second;
		first['x']=8;
		first['y']=16;
		first['z']=32;
		second=first;                // second now contains 3 ints
		first=std::map<char,int>();  // and first is now empty
		std::cout << "Size of first: " << first.size() << '\n';
		std::cout << "Size of second: " << second.size() << '\n';
	}
	{
		std::cout << MAGENTA "\nmap operator= ft\n" END << std::endl;
		ft::map<char,int> first;
		ft::map<char,int> second;
		first['x']=8;
		first['y']=16;
		first['z']=32;
		second=first;                // second now contains 3 ints
		first=ft::map<char,int>();  // and first is now empty
		std::cout << "Size of first: " << first.size() << '\n';
		std::cout << "Size of second: " << second.size() << '\n';
	}
	// iterators
	{
		std::cout << YELLOW "\nmap iterators std" END << std::endl;
		std::cout << YELLOW "begin std" END << std::endl;
		std::map<char,int> mymap;
		mymap['b'] = 100;
		mymap['a'] = 200;
		mymap['c'] = 300;
		// show content:
		for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		std::cout << YELLOW "end std" END << std::endl;
		for (std::map<char,int>::iterator itt=mymap.begin(); itt!=mymap.end(); ++itt)
			std::cout << itt->first << " => " << itt->second << '\n';
		std::cout << YELLOW "rbegin std" END << std::endl;
		std::map<char,int>::reverse_iterator rit;
		for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
			std::cout << rit->first << " => " << rit->second << '\n';
		std::cout << YELLOW "rend std" END << std::endl;
		std::map<char,int>::reverse_iterator riton;
		for (riton=mymap.rbegin(); riton!=mymap.rend(); ++riton)
			std::cout << riton->first << " => " << riton->second << '\n';	
	}
		{
		std::cout << MAGENTA "\nmap iterators ft" END << std::endl;
		std::cout << MAGENTA "begin ft" END << std::endl;
		ft::map<char,int> mymap;
		mymap['b'] = 100;
		mymap['a'] = 200;
		mymap['c'] = 300;
		// show content:
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		std::cout << MAGENTA "end ft" END << std::endl;
		for (ft::map<char,int>::iterator itt=mymap.begin(); itt!=mymap.end(); ++itt)
			std::cout << itt->first << " => " << itt->second << '\n';
		std::cout << MAGENTA "rbegin ft" END << std::endl;
		ft::map<char,int>::reverse_iterator rit;
		for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
			std::cout << rit->first << " => " << rit->second << '\n';
		std::cout << MAGENTA "rend ft" END << std::endl;
		ft::map<char,int>::reverse_iterator riton;
		for (riton=mymap.rbegin(); riton!=mymap.rend(); ++riton)
		std::cout << riton->first << " => " << riton->second << '\n';
		}

	//empty
{
		std::cout << YELLOW "\nmap empty std\n" END << std::endl;
		std::map<char,int> mymap;
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		while (!mymap.empty())
		{
			std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
			mymap.erase(mymap.begin());
		}
}
{
		std::cout << MAGENTA "\nmap empty ft\n" END << std::endl;
		ft::map<char,int> mymap;
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		while (!mymap.empty())
		{
			std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
			mymap.erase(mymap.begin());
		}
}
//size
{
		std::cout << YELLOW "\nmap size std\n" END << std::endl;
		std::map<char,int> mymap;
		mymap['a']=101;
		mymap['b']=202;
		mymap['c']=302;
		std::cout << "mymap.size() is " << mymap.size() << '\n';
}
{
		std::cout << MAGENTA "\nmap size ft\n" END << std::endl;
	  	ft::map<char,int> mymap;
		mymap['a']=101;
		mymap['b']=202;
		mymap['c']=302;
		std::cout << "mymap.size() is " << mymap.size() << '\n';
}
//max size
{
		std::cout << YELLOW "\nmax size std\n" END << std::endl;
		int i;
		std::map<int,int> mymap;
		if (mymap.max_size()>1000)
		{
			for (i=0; i<1000; i++) mymap[i]=0;
			std::cout << "The map contains 1000 elements.\n";
		}
		else std::cout << "The map could not hold 1000 elements.\n";
}
{
		std::cout << MAGENTA "\nmax size ft\n" END << std::endl;
		int i;
		ft::map<int,int> mymap;
		if (mymap.max_size()>1000)
		{
			for (i=0; i<1000; i++) mymap[i]=0;
			std::cout << "The map contains 1000 elements.\n";
		}
		else std::cout << "The map could not hold 1000 elements.\n";
}
//operator[]
{
		std::cout << YELLOW "\nmap operator[] std\n" END << std::endl;
		std::map<char,std::string> mymap;
		mymap['a']="an element";
		mymap['b']="another element";
		mymap['c']=mymap['b'];
		std::cout << "mymap['a'] is " << mymap['a'] << '\n';
		std::cout << "mymap['b'] is " << mymap['b'] << '\n';
		std::cout << "mymap['c'] is " << mymap['c'] << '\n';
		std::cout << "mymap['d'] is " << mymap['d'] << '\n';
		std::cout << "mymap now contains " << mymap.size() << " elements.\n";
}
{
		std::cout << MAGENTA "\nmap operator[] ft\n" END << std::endl;
 		ft::map<char,std::string> mymap;
		mymap['a']="an element";
		mymap['b']="another element";
		mymap['c']=mymap['b'];
		std::cout << "mymap['a'] is " << mymap['a'] << '\n';
		std::cout << "mymap['b'] is " << mymap['b'] << '\n';
		std::cout << "mymap['c'] is " << mymap['c'] << '\n';
		std::cout << "mymap['d'] is " << mymap['d'] << '\n';
		std::cout << "mymap now contains " << mymap.size() << " elements.\n";

}
//insert
{
		std::cout << YELLOW "\nmap insert std\n" END << std::endl;
	  	std::map<char,int> mymap;
		// first insert function version (single parameter):
		mymap.insert ( std::pair<char,int>('a',100) );
		mymap.insert ( std::pair<char,int>('z',200) );
		std::pair<std::map<char,int>::iterator,bool> ret;
		ret = mymap.insert ( std::pair<char,int>('z',500) );
		if (ret.second==false) {
			std::cout << "element 'z' already existed";
			std::cout << " with a value of " << ret.first->second << '\n';
		}
		// second insert function version (with hint position):
		std::map<char,int>::iterator it = mymap.begin();
		mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
		mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting
		// third insert function version (range insertion):
		std::map<char,int> anothermap;
		anothermap.insert(mymap.begin(),mymap.find('c'));
		// showing contents:
		std::cout << "mymap contains:\n";
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		std::cout << "anothermap contains:\n";
		for (it=anothermap.begin(); it!=anothermap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
}
{
		std::cout << MAGENTA "\nmap insert ft\n" END << std::endl;
	  	ft::map<char,int> mymap;
		// first insert function version (single parameter):
		mymap.insert ( ft::pair<char,int>('a',100) );
		mymap.insert ( ft::pair<char,int>('z',200) );
		ft::pair<ft::map<char,int>::iterator,bool> ret;
		ret = mymap.insert ( ft::pair<char,int>('z',500) );
		if (ret.second==false) {
			std::cout << "element 'z' already existed";
			std::cout << " with a value of " << ret.first->second << '\n';
		}
		// second insert function version (with hint position):
		ft::map<char,int>::iterator it = mymap.begin();
		mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
		mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting
		// third insert function version (range insertion):
		ft::map<char,int> anothermap;
		anothermap.insert(mymap.begin(),mymap.find('c'));
		// showing contents:
		std::cout << "mymap contains:\n";
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		std::cout << "anothermap contains:\n";
		for (it=anothermap.begin(); it!=anothermap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
}
//erase
{
		std::cout << YELLOW "\nmap erase std\n" END << std::endl;
		std::map<char,int> mymap;
		std::map<char,int>::iterator it;
		// insert some values:
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;
		it=mymap.find('b');
		mymap.erase (it);                   // erasing by iterator
		mymap.erase ('c');                  // erasing by key
		it=mymap.find ('e');
		mymap.erase ( it, mymap.end() );    // erasing by range
		// show content:
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
}
{
		std::cout << MAGENTA "\nmap erase ft\n" END << std::endl;
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator it;
		// insert some values:
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;
		it=mymap.find('b');
		mymap.erase (it);                   // erasing by iterator
		mymap.erase ('c');                  // erasing by key
		it=mymap.find ('e');
		mymap.erase ( it, mymap.end() );    // erasing by range
		// show content:
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
}
//swap
{
		std::cout << YELLOW "\nmap swap std\n" END << std::endl;
		std::map<char,int> foo,bar;
		foo['x']=100;
		foo['y']=200;
		bar['a']=11;
		bar['b']=22;
		bar['c']=33;
		foo.swap(bar);
		std::cout << "foo contains:\n";
		for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		std::cout << "bar contains:\n";
		for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
}
{
		std::cout << MAGENTA "\nmap swap ft\n" END << std::endl;
		ft::map<char,int> foo,bar;
		foo['x']=100;
		foo['y']=200;
		bar['a']=11;
		bar['b']=22;
		bar['c']=33;
		foo.swap(bar);
		std::cout << "foo contains:\n";
		for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		std::cout << "bar contains:\n";
		for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
}
//clear
{
		std::cout << YELLOW "\nmap clear std\n" END << std::endl;
	  	std::map<char,int> mymap;
		mymap['x']=100;
		mymap['y']=200;
		mymap['z']=300;
		std::cout << "mymap contains:\n";
		for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		mymap.clear();
		mymap['a']=1101;
		mymap['b']=2202;
		std::cout << "mymap contains:\n";
		for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
}
{
		std::cout << MAGENTA "\nmap clear ft\n" END << std::endl;
		ft::map<char,int> mymap;
		mymap['x']=100;
		mymap['y']=200;
		mymap['z']=300;
		std::cout << "mymap contains:\n";
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		mymap.clear();
		mymap['a']=1101;
		mymap['b']=2202;
		std::cout << "mymap contains:\n";
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
}
//key comp
{
		std::cout << YELLOW "\nmap key_comp std\n" END << std::endl;
		std::map<char,int> mymap;
		std::map<char,int>::key_compare mycomp = mymap.key_comp();
		mymap['a']=100;
		mymap['b']=200;
		mymap['c']=300;
		std::cout << "mymap contains:\n";
		char highest = mymap.rbegin()->first;     // key value of last element
		std::map<char,int>::iterator it = mymap.begin();
		do {
			std::cout << it->first << " => " << it->second << '\n';
		} while ( mycomp((*it++).first, highest) );
		std::cout << '\n';
}
{
		std::cout << MAGENTA "\nmap key_comp ft\n" END << std::endl;
		ft::map<char,int> mymap;
		ft::map<char,int>::key_compare mycomp = mymap.key_comp();
		mymap['a']=100;
		mymap['b']=200;
		mymap['c']=300;
		std::cout << "mymap contains:\n";
		char highest = mymap.rbegin()->first;     // key value of last element
		ft::map<char,int>::iterator it = mymap.begin();
		do {
			std::cout << it->first << " => " << it->second << '\n';
		} while ( mycomp((*it++).first, highest) );
		std::cout << '\n';
}
// value comp
{
		std::cout << YELLOW "\nmap value_comp std\n" END << std::endl;
		std::map<char,int> mymap;
		mymap['x']=1001;
		mymap['y']=2002;
		mymap['z']=3003;
		std::cout << "mymap contains:\n";
		std::pair<char,int> highest = *mymap.rbegin();          // last element
		std::map<char,int>::iterator it = mymap.begin();
		do {
			std::cout << it->first << " => " << it->second << '\n';
		} while ( mymap.value_comp()(*it++, highest) );
}
{
		std::cout << MAGENTA "\nmap value_comp ft\n" END << std::endl;
		ft::map<char,int> mymap;
		mymap['x']=1001;
		mymap['y']=2002;
		mymap['z']=3003;
		std::cout << "mymap contains:\n";
		ft::pair<char,int> highest = *mymap.rbegin();          // last element
		ft::map<char,int>::iterator it = mymap.begin();
		do {
			std::cout << it->first << " => " << it->second << '\n';
		} while ( mymap.value_comp()(*it++, highest) );
}
//find
{
		std::cout << YELLOW "\nmap find std\n" END << std::endl;
		std::map<char,int> mymap;
		std::map<char,int>::iterator it;
		mymap['a']=50;
		mymap['b']=100;
		mymap['c']=150;
		mymap['d']=200;
		it = mymap.find('b');
		if (it != mymap.end())
			mymap.erase (it);
		// print content:
		std::cout << "elements in mymap:" << '\n';
		std::cout << "a => " << mymap.find('a')->second << '\n';
		std::cout << "c => " << mymap.find('c')->second << '\n';
		std::cout << "d => " << mymap.find('d')->second << '\n';
}
{
		std::cout << MAGENTA "\nmap find ft\n" END << std::endl;
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator it;
		mymap['a']=50;
		mymap['b']=100;
		mymap['c']=150;
		mymap['d']=200;
		it = mymap.find('b');
		if (it != mymap.end())
			mymap.erase (it);
		// print content:
		std::cout << "elements in mymap:" << '\n';
		std::cout << "a => " << mymap.find('a')->second << '\n';
		std::cout << "c => " << mymap.find('c')->second << '\n';
		std::cout << "d => " << mymap.find('d')->second << '\n';
}
//count
{
		std::cout << YELLOW "\nmap count std\n" END << std::endl;
		std::map<char,int> mymap;
		char c;
		mymap ['a']=101;
		mymap ['c']=202;
		mymap ['f']=303;
		for (c='a'; c<'h'; c++)
		{
			std::cout << c;
			if (mymap.count(c)>0)
			std::cout << " is an element of mymap.\n";
			else 
			std::cout << " is not an element of mymap.\n";
		}
}
{
		std::cout << MAGENTA "\nmap count ft\n" END << std::endl;
		ft::map<char,int> mymap;
		char c;
		mymap ['a']=101;
		mymap ['c']=202;
		mymap ['f']=303;
		for (c='a'; c<'h'; c++)
		{
			std::cout << c;
			if (mymap.count(c)>0)
			std::cout << " is an element of mymap.\n";
			else 
			std::cout << " is not an element of mymap.\n";
		}
}
//lower bound
{
		std::cout << YELLOW "\nmap lower_bound std\n" END << std::endl;
		std::map<char,int> mymap;
		std::map<char,int>::iterator itlow,itup;
		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;
		itlow=mymap.lower_bound ('b');  // itlow points to b
		itup=mymap.upper_bound ('d');   // itup points to e (not d!)
		mymap.erase(itlow,itup);        // erases [itlow,itup)
		// print content:
		for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
}
{
		std::cout << MAGENTA "\nmap lower_bound ft\n" END << std::endl;
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator itlow,itup;
		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;
		itlow=mymap.lower_bound ('b');  // itlow points to b
		itup=mymap.upper_bound ('d');   // itup points to e (not d!)
		mymap.erase(itlow,itup);        // erases [itlow,itup)
		// print content:
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
}
//upper bound
{
		std::cout << YELLOW "\nmap upper_bound std\n" END << std::endl;
		std::map<char,int> mymap;
		std::map<char,int>::iterator itlow,itup;
		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;
		itlow=mymap.lower_bound ('b');  // itlow points to b
		itup=mymap.upper_bound ('d');   // itup points to e (not d!)
		mymap.erase(itlow,itup);        // erases [itlow,itup)
		// print content:
		for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
}
{
		std::cout << MAGENTA "\nmap upper_bound ft\n" END << std::endl;
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator itlow,itup;
		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;
		itlow=mymap.lower_bound ('b');  // itlow points to b
		itup=mymap.upper_bound ('d');   // itup points to e (not d!)
		mymap.erase(itlow,itup);        // erases [itlow,itup)
		// print content:
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
}
//equal range
{
		std::cout << YELLOW "\nmap equal_range std\n" END << std::endl;
		std::map<char,int> mymap;
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
		ret = mymap.equal_range('b');
		std::cout << "lower bound points to: ";
		std::cout << ret.first->first << " => " << ret.first->second << '\n';
		std::cout << "upper bound points to: ";
		std::cout << ret.second->first << " => " << ret.second->second << '\n';
}
{
		std::cout << MAGENTA "\nmap equal_range ft\n" END << std::endl;
		ft::map<char,int> mymap;
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
		ret = mymap.equal_range('b');
		std::cout << "lower bound points to: ";
		std::cout << ret.first->first << " => " << ret.first->second << '\n';
		std::cout << "upper bound points to: ";
		std::cout << ret.second->first << " => " << ret.second->second << '\n';
}
// get allocator
{
		std::cout << YELLOW "\nmap get_allocator std\n" END << std::endl;
		int psize;
		std::map<char,int> mymap;
		std::pair<const char,int>* p;
		// allocate an array of 5 elements using mymap's allocator:
		p=mymap.get_allocator().allocate(5);
		// assign some values to array
		psize = sizeof(std::map<char,int>::value_type)*5;
		std::cout << "The allocated array has a size of " << psize << " bytes.\n";
		mymap.get_allocator().deallocate(p,5);
}
{
		std::cout << MAGENTA "\nmap get_allocator ft\n" END << std::endl;
		int psize;
		ft::map<char,int> mymap;
		ft::pair<const char,int>* p;
		// allocate an array of 5 elements using mymap's allocator:
		p=mymap.get_allocator().allocate(5);
		// assign some values to array
		psize = sizeof(ft::map<char,int>::value_type)*5;
		std::cout << "The allocated array has a size of " << psize << " bytes.\n";
		mymap.get_allocator().deallocate(p,5);
}


	return 0;
}




// int main () {

//   ft::map<int,int> mymap;

//   std::cout  << CYAN << "main " << END << std::endl;
//   mymap[2] = 5;
//   std::cout  << CYAN << "main " << END << std::endl;
//   mymap[3] = 15;
//     std::cout  << CYAN << "main " << END << std::endl;
//   mymap[3] = 15;
//   // mymap.insert(2,5);
//   // mymap.insert(3,5);
//   // mymap.insert(4,5);
//   // mymap.insert(5,5);
//  // ft::map<int,int>::iterator it = mymap.begin();


// 🔥 MAIN vector 🔥 //
/*

// swap vectors
#include <iostream>
#include <vector>
{
  std::cout << YELLOW "\nvector swap std\n" END << std::endl;;
  std::vector<int> foo (3,100);   // three ints with a value of 100
  std::vector<int> bar (5,200);   // five ints with a value of 200
  foo.swap(bar);
  std::cout << "foo contains:";
  for (unsigned i=0; i<foo.size(); i++)
    std::cout << ' ' << foo[i];
  std::cout << '\n';
  std::cout << "bar contains:";
  for (unsigned i=0; i<bar.size(); i++)
    std::cout << ' ' << bar[i];
  std::cout << '\n';
}
{
  std::cout << MAGENTA "\nvector swap ft\n" END << std::endl;;
  ft::vector<int> foo (3,100);   // three ints with a value of 100
  ft::vector<int> bar (5,200);   // five ints with a value of 200
  foo.swap(bar);
  std::cout << "foo contains:";
  for (unsigned i=0; i<foo.size(); i++)
    std::cout << ' ' << foo[i];
  std::cout << '\n';
  std::cout << "bar contains:";
  for (unsigned i=0; i<bar.size(); i++)
    std::cout << ' ' << bar[i];
  std::cout << '\n';
}


// vector::size
#include <iostream>
#include <vector>
{
  std::cout << YELLOW "\nvector size std\n" END << std::endl;;
  std::vector<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';
  for (int i=0; i<10; i++) myints.push_back(i);
  std::cout << "1. size: " << myints.size() << '\n';
  myints.insert (myints.end(),10,100);
  std::cout << "2. size: " << myints.size() << '\n';
  myints.pop_back();
  std::cout << "3. size: " << myints.size() << '\n';
}
{
  std::cout << MAGENTA "\nvector size ft\n" END << std::endl;;
  ft::vector<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';
  for (int i=0; i<10; i++) myints.push_back(i);
  std::cout << "1. size: " << myints.size() << '\n';
  myints.insert (myints.end(),10,100);
  std::cout << "2. size: " << myints.size() << '\n';
  myints.pop_back();
  std::cout << "3. size: " << myints.size() << '\n';
}

*/
//🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅    BUG   🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅
// resizing vector
/*#include <iostream>
#include <vector>
{
  std::cout << YELLOW "\nvector resizing std\n" END << std::endl;;
  std::vector<int> myvector;
  // set some initial content:
  for (int i=1;i<10;i++) myvector.push_back(i);
  myvector.resize(5);
  myvector.resize(8,100);
  myvector.resize(12);
  std::cout << "myvector contains:";
  for (int i=0;i<myvector.size();i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
}
{
  std::cout << MAGENTA "\nvector resizing ft\n" END << std::endl;;
  ft::vector<int> myvector;
  // set some initial content:
  for (int i=1;i<10;i++) myvector.push_back(i);
  myvector.resize(5);
  myvector.resize(8,100);
  myvector.resize(12);
  std::cout << "myvector contains:";
  for (int i=0;i<myvector.size();i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
}*/
//🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅

/*
//🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅
// vector::reserve
#include <iostream>
#include <vector>
{
  std::cout << YELLOW "\nvector reserve std\n" END << std::endl;;
  std::vector<int>::size_type sz;
  std::vector<int> foo;
  sz = foo.capacity();
  std::cout << "making foo grow:\n";
  for (int i=0; i<100; ++i) {
    foo.push_back(i);
    if (sz!=foo.capacity()) {
      sz = foo.capacity();
      std::cout << "capacity changed: " << sz << '\n';
    }
  }
  std::vector<int> bar;
  sz = bar.capacity();
  bar.reserve(100);   // this is the only difference with foo above
  std::cout << "making bar grow:\n";
  for (int i=0; i<100; ++i) {
    bar.push_back(i);
    if (sz!=bar.capacity()) {
      sz = bar.capacity();
      std::cout << "capacity changed: " << sz << '\n';
    }
  }
}
{
  std::cout << MAGENTA "\nvector reserve ft\n" END << std::endl;;
  ft::vector<int>::size_type sz;
  ft::vector<int> foo;
  sz = foo.capacity();
  std::cout << "making foo grow:\n";
  for (int i=0; i<100; ++i) {
    foo.push_back(i);
    if (sz!=foo.capacity()) {
      sz = foo.capacity();
      std::cout << "capacity changed: " << sz << '\n';
    }
  }
  ft::vector<int> bar;
  sz = bar.capacity();
  bar.reserve(100);   // this is the only difference with foo above
  std::cout << "making bar grow:\n";
  for (int i=0; i<100; ++i) {
    bar.push_back(i);
    if (sz!=bar.capacity()) {
      sz = bar.capacity();
      std::cout << "capacity changed: " << sz << '\n';
    }
  }
}
//🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅


// vector::rbegin/rend
#include <iostream>
#include <vector>
{
  std::cout << YELLOW "\nvector rbegin/rend std\n" END << std::endl;;
  std::vector<int> myvector (5);  // 5 default-constructed ints
  int i=0;
  std::vector<int>::reverse_iterator rit = myvector.rbegin();
  for (; rit!= myvector.rend(); ++rit)
    *rit = ++i;
  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
{
  std::cout << MAGENTA "\nvector rbegin/rend ft\n" END << std::endl;;
  ft::vector<int> myvector (5);  // 5 default-constructed ints
  int i=0;
  ft::vector<int>::reverse_iterator rit = myvector.rbegin();
  for (; rit!= myvector.rend(); ++rit)
    *rit = ++i;
  std::cout << "myvector contains:";
  for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}


// vector::pop_back
#include <iostream>
#include <vector>
{
  std::cout << YELLOW "\nvector pop_back/push_back std\n" END << std::endl;;
  std::vector<int> myvector;
  int sum (0);
  myvector.push_back (100);
  myvector.push_back (200);
  myvector.push_back (300);

  while (!myvector.empty())
  {
    sum+=myvector.back();
    myvector.pop_back();
  }
  std::cout << "The elements of myvector add up to " << sum << '\n';
}
{
  std::cout << MAGENTA "\nvector pop_back/push_back ft\n" END << std::endl;;
  ft::vector<int> myvector;
  int sum (0);
  myvector.push_back (100);
  myvector.push_back (200);
  myvector.push_back (300);

  while (!myvector.empty())
  {
    sum+=myvector.back();
    myvector.pop_back();
  }
  std::cout << "The elements of myvector add up to " << sum << '\n';
}

// vector assignment
#include <iostream>
#include <vector>
{
  std::cout << YELLOW "\nvector assignment std\n" END << std::endl;;

  std::vector<int> foo (3,0);
  std::vector<int> bar (5,0);
  bar = foo;
  foo = std::vector<int>();
  std::cout << "Size of foo: " << int(foo.size()) << '\n';
  std::cout << "Size of bar: " << int(bar.size()) << '\n';
}
{
  std::cout << MAGENTA "\nvector assignment ft\n" END << std::endl;;
  ft::vector<int> foo (3,0);
  ft::vector<int> bar (5,0);
  bar = foo;
  foo = ft::vector<int>();
  std::cout << "Size of foo: " << int(foo.size()) << '\n';
  std::cout << "Size of bar: " << int(bar.size()) << '\n';
}


// vector::operator[]
#include <iostream>
#include <vector>
{
  std::cout << YELLOW "\nvector [] std\n" END << std::endl;;
  std::vector<int> myvector (10);   // 10 zero-initialized elements
  std::vector<int>::size_type sz = myvector.size();
  // assign some values:
  for (unsigned i=0; i<sz; i++) myvector[i]=i;
  // reverse vector using operator[]:
  for (unsigned i=0; i<sz/2; i++)
  {
    int temp;
    temp = myvector[sz-1-i];
    myvector[sz-1-i]=myvector[i];
    myvector[i]=temp;
  }
  std::cout << "myvector contains:";
  for (unsigned i=0; i<sz; i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
}
{
  std::cout << MAGENTA "\nvector [] ft\n" END << std::endl;;
  ft::vector<int> myvector (10);   // 10 zero-initialized elements
  ft::vector<int>::size_type sz = myvector.size();
  // assign some values:
  for (unsigned i=0; i<sz; i++) myvector[i]=i;
  // reverse vector using operator[]:
  for (unsigned i=0; i<sz/2; i++)
  {
    int temp;
    temp = myvector[sz-1-i];
    myvector[sz-1-i]=myvector[i];
    myvector[i]=temp;
  }
  std::cout << "myvector contains:";
  for (unsigned i=0; i<sz; i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
}



//🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅
// comparing size, capacity and max_size
#include <iostream>
#include <vector>
{
  std::cout << YELLOW "\nvector comparing size, capacity and max_size std\n" END << std::endl;;
  std::vector<int> myvector;

  // set some content in the vector:
  for (int i=0; i<100; i++) myvector.push_back(i);

  std::cout << "size: " << myvector.size() << "\n";
  std::cout << "capacity: " << myvector.capacity() << "\n";
  std::cout << "max_size: " << myvector.max_size() << "\n";
}
{
  std::cout << MAGENTA "\nvector comparing size, capacity and max_size ft\n" END << std::endl;;

  ft::vector<int> myvector;

  // set some content in the vector:
  for (int i=0; i<100; i++) myvector.push_back(i);

  std::cout << "size: " << myvector.size() << "\n";
  std::cout << "capacity: " << myvector.capacity() << "\n";
  std::cout << "max_size: " << myvector.max_size() << "\n";
}
//🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅



// inserting into a vector
#include <iostream>
#include <vector>
{
  std::cout << YELLOW "\nvector inserting std\n" END << std::endl;;
  std::vector<int> myvector (3,100);
  std::vector<int>::iterator it;
  it = myvector.begin();
  it = myvector.insert ( it , 200 );
  myvector.insert (it,2,300);
  // "it" no longer valid, get a new one:
  it = myvector.begin();

  std::vector<int> anothervector (2,400);
  myvector.insert (it+2,anothervector.begin(),anothervector.end());

  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
{
  std::cout << MAGENTA "\nvector inserting ft\n" END << std::endl;;

  ft::vector<int> myvector (3,100);
  ft::vector<int>::iterator it;
  it = myvector.begin();
  it = myvector.insert ( it , 200 );
  myvector.insert (it,2,300);
  // "it" no longer valid, get a new one:
  it = myvector.begin();

  ft::vector<int> anothervector (2,400);
  myvector.insert (it+2,anothervector.begin(),anothervector.end());

  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';
}


// vector::get_allocator
#include <iostream>
#include <vector>
{
  std::cout << YELLOW "\nvector get_allocator std\n" END << std::endl;;
  std::vector<int> myvector;
  int * p;
  unsigned int i;
  // allocate an array with space for 5 elements using vector's allocator:
  p = myvector.get_allocator().allocate(5);
  // construct values in-place on the array:
  for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);
  std::cout << "The allocated array contains:";
  for (i=0; i<5; i++) std::cout << ' ' << p[i];
  std::cout << '\n';
  // destroy and deallocate:
  for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
  myvector.get_allocator().deallocate(p,5);
}
{
  std::cout << MAGENTA "\nvector get_allocator ft\n" END << std::endl;;
  ft::vector<int> myvector;
  int * p;
  unsigned int i;
  // allocate an array with space for 5 elements using vector's allocator:
  p = myvector.get_allocator().allocate(5);
  // construct values in-place on the array:
  for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);
  std::cout << "The allocated array contains:";
  for (i=0; i<5; i++) std::cout << ' ' << p[i];
  std::cout << '\n';
  // destroy and deallocate:
  for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
  myvector.get_allocator().deallocate(p,5);
}


// vector::front
#include <iostream>
#include <vector>
{
  std::cout << YELLOW "\nvector front std\n" END << std::endl;;
  std::vector<int> myvector;
  myvector.push_back(78);
  myvector.push_back(16);
  // now front equals 78, and back 16
  myvector.front() -= myvector.back();
  std::cout << "myvector.front() is now " << myvector.front() << '\n';
}
{
  std::cout << MAGENTA "\nvector front ft\n" END << std::endl;;
  ft::vector<int> myvector;
  myvector.push_back(78);
  myvector.push_back(16);
  // now front equals 78, and back 16
  myvector.front() -= myvector.back();
  std::cout << "myvector.front() is now " << myvector.front() << '\n';
}

// erasing from vector
#include <iostream>
#include <vector>
{
  std::cout << YELLOW "\nvector erasing std\n" END << std::endl;;
  std::vector<int> myvector;
  // set some values (from 1 to 10)
  for (int i=1; i<=10; i++) myvector.push_back(i);

  // erase the 6th element
  myvector.erase (myvector.begin()+5);

  // erase the first 3 elements:
  myvector.erase (myvector.begin(),myvector.begin()+3);

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); ++i)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
}
{
  std::cout << MAGENTA "\nvector erasing ft\n" END << std::endl;;
  ft::vector<int> myvector;
  // set some values (from 1 to 10)
  for (int i=1; i<=10; i++) myvector.push_back(i);

  // erase the 6th element
  myvector.erase (myvector.begin()+5);

  // erase the first 3 elements:
  myvector.erase (myvector.begin(),myvector.begin()+3);

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); ++i)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
}


// vector::empty
#include <iostream>
#include <vector>
{
  std::cout << YELLOW "\nvector empty std\n" END << std::endl;;
  std::vector<int> myvector;
  int sum (0);
  for (int i=1;i<=10;i++) myvector.push_back(i);
  while (!myvector.empty())
  {
     sum += myvector.back();
     myvector.pop_back();
  }
  std::cout << "total: " << sum << '\n';
}
{
  std::cout << MAGENTA "\nvector empty ft\n" END << std::endl;;
  ft::vector<int> myvector;
  int sum (0);
  for (int i=1;i<=10;i++) myvector.push_back(i);
  while (!myvector.empty())
  {
     sum += myvector.back();
     myvector.pop_back();
  }
  std::cout << "total: " << sum << '\n';
}


// clearing vectors
#include <iostream>
#include <vector>
{
  std::cout << YELLOW "\nvector clearing std\n" END << std::endl;;
  std::vector<int> myvector;
  myvector.push_back (100);
  myvector.push_back (200);
  myvector.push_back (300);

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

  myvector.clear();
  myvector.push_back (1101);
  myvector.push_back (2202);

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
}
{
  std::cout << MAGENTA "\nvector clearing ft\n" END << std::endl;;
  ft::vector<int> myvector;
  myvector.push_back (100);
  myvector.push_back (200);
  myvector.push_back (300);

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

  myvector.clear();
  myvector.push_back (1101);
  myvector.push_back (2202);

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
}


//🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅
// comparing size, capacity and max_size 
#include <iostream>
#include <vector>
{
  std::cout << YELLOW "\nvector begin/end std\n" END << std::endl;;
  std::vector<int> myvector;
  // set some content in the vector:
  for (int i=0; i<100; i++) myvector.push_back(i);

  std::cout << "size: " << (int) myvector.size() << '\n';
  std::cout << "capacity: " << (int) myvector.capacity() << '\n';
  std::cout << "max_size: " << (int) myvector.max_size() << '\n';
}
{
  std::cout << MAGENTA "\nvector begin/end ft\n" END << std::endl;;
  ft::vector<int> myvector;
  // set some content in the vector:
  for (int i=0; i<100; i++) myvector.push_back(i);

  std::cout << "size: " << (int) myvector.size() << '\n';
  std::cout << "capacity: " << (int) myvector.capacity() << '\n';
  std::cout << "max_size: " << (int) myvector.max_size() << '\n';
}
//🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅🍅

// vector::begin/end
#include <iostream>
#include <vector>
{
  std::cout << YELLOW "\nvector begin/end std\n" END << std::endl;;

  std::vector<int> myvector;
  for (int i=1; i<=5; i++) myvector.push_back(i);

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
{
  std::cout << MAGENTA "\nvector begin/end ft\n" END << std::endl;;

  ft::vector<int> myvector;
  for (int i=1; i<=5; i++) myvector.push_back(i);

  std::cout << "myvector contains:";
  for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

// vector::back
#include <iostream>
#include <vector>
{
  std::cout << YELLOW "\nvector back std\n" END << std::endl;;

  std::vector<int> myvector;

  myvector.push_back(10);

  while (myvector.back() != 0)
  {
    myvector.push_back ( myvector.back() -1 );
  }

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size() ; i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
}
{
  std::cout << MAGENTA "\nvector back ft\n" END << std::endl;;

  ft::vector<int> myvector;

  myvector.push_back(10);

  while (myvector.back() != 0)
  {
    myvector.push_back ( myvector.back() -1 );
  }

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size() ; i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
}


// vector::at
#include <iostream>
#include <vector>
{
  std::cout << YELLOW "\nvector at std\n" END << std::endl;;

  std::vector<int> myvector (10);   // 10 zero-initialized ints

  // assign some values:
  for (unsigned i=0; i<myvector.size(); i++)
    myvector.at(i)=i;

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    std::cout << ' ' << myvector.at(i);
  std::cout << '\n';
}
{
  std::cout << MAGENTA "\nvector at ft\n" END << std::endl;;

  ft::vector<int> myvector (10);   // 10 zero-initialized ints

  // assign some values:
  for (unsigned i=0; i<myvector.size(); i++)
    myvector.at(i)=i;

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    std::cout << ' ' << myvector.at(i);
  std::cout << '\n';
}


// vector assign
#include <iostream>
#include <vector>
{
  std::cout << YELLOW "\nvector assign std\n" END << std::endl;;

  std::vector<int> first;
  std::vector<int> second;
  std::vector<int> third;

  first.assign (7,100);             // 7 ints with a value of 100

  std::vector<int>::iterator it;
  it=first.begin()+1;

  second.assign (it,first.end()-1); // the 5 central values of first

  int myints[] = {1776,7,4};
  third.assign (myints,myints+3);   // assigning from array.

  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
  std::cout << "Size of third: " << int (third.size()) << '\n';
}
{
  std::cout << MAGENTA "\nvector assign ft\n" END << std::endl;;

  ft::vector<int> first;
  ft::vector<int> second;
  ft::vector<int> third;

  first.assign (7,100);             // 7 ints with a value of 100

  ft::vector<int>::iterator it;
  it=first.begin()+1;

  second.assign (it,first.end()-1); // the 5 central values of first

  int myints[] = {1776,7,4};
  third.assign (myints,myints+3);   // assigning from array.

  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
  std::cout << "Size of third: " << int (third.size()) << '\n';
}

	


*/

// 🔥 MAIN stack 🔥 //
/*
// stack::top
#include <iostream>       // std::cout
#include <stack>          // std::stack
{
  std::cout << YELLOW "\nstack top std\n" END << std::endl;;
  std::stack<int> mystack;
  mystack.push(10);
  mystack.push(20);
  mystack.top() -= 5;
  std::cout << "mystack.top() is now " << mystack.top() << '\n';
}
{
  std::cout << MAGENTA "\nstack top std\n" END << std::endl;;
  ft::stack<int> mystack;
  mystack.push(10);
  mystack.push(20);
  mystack.top() -= 5;
  std::cout << "mystack.top() is now " << mystack.top() << '\n';
}


// stack::size
#include <iostream>       // std::cout
#include <stack>          // std::stack
{
  std::cout << YELLOW "\nstack size std\n" END << std::endl;;
  std::stack<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';
  for (int i=0; i<5; i++) myints.push(i);
  std::cout << "1. size: " << myints.size() << '\n';
  myints.pop();
  std::cout << "2. size: " << myints.size() << '\n';
}
{
  std::cout << MAGENTA "\nstack size ft\n" END << std::endl;;
  ft::stack<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';
  for (int i=0; i<5; i++) myints.push(i);
  std::cout << "1. size: " << myints.size() << '\n';
  myints.pop();
  std::cout << "2. size: " << myints.size() << '\n';
}


// stack::push/pop
#include <iostream>       // std::cout
#include <stack>          // std::stack
{
  std::cout << YELLOW "\nstack push/pop std\n" END << std::endl;;
  std::stack<int> mystack;
  for (int i=0; i<5; ++i) mystack.push(i);
  std::cout << "Popping out elements...";
  while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  std::cout << '\n';
}
{
  std::cout << MAGENTA "\nstack push/pop ft\n" END << std::endl;;

  ft::stack<int> mystack;
  for (int i=0; i<5; ++i) mystack.push(i);
  std::cout << "Popping out elements...";
  while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  std::cout << '\n';
}



// stack::empty
#include <iostream>       // std::cout
#include <stack>          // std::stack
{
  std::cout << YELLOW "\nstack empty std\n" END << std::endl;;
  std::stack<int> mystack;
  int sum (0);
  for (int i=1;i<=10;i++) mystack.push(i);
  while (!mystack.empty())
  {
     sum += mystack.top();
     mystack.pop();
  }
  std::cout << "total: " << sum << '\n';
}
{
  std::cout << MAGENTA "\nstack empty ft\n" END << std::endl;;
  ft::stack<int> mystack;
  int sum (0);
  for (int i=1;i<=10;i++) mystack.push(i);
  while (!mystack.empty())
  {
     sum += mystack.top();
     mystack.pop();
  }
  std::cout << "total: " << sum << '\n';
}*/




// 🔥 iterator_traits 🔥
// MAIN POUR is_integral C++ 11//
/*#include <iostream>     // std::cout
#include <iterator>     // std::iterator_traits
#include <typeinfo>     // typeid

{
  typedef std::iterator_traits<int*> traits;
  if (typeid(traits::iterator_category)==typeid(std::random_access_iterator_tag))
    std::cout << "int* is a random-access iterator";
}*/
 


// 🔥 MAIN enable_if 🔥
// MAIN POUR is_integral C++ 11//
/*{
  std::cout << YELLOW "\nenable_if std\n" END << std::endl;;

  short int i = 1;    // code does not compile if type of i is not integral

  std::cout << std::boolalpha;
  std::cout << "i is odd: " << is_odd(i) << std::endl;
  std::cout << "i is even: " << is_even(i) << std::endl;
}
{
  std::cout << MAGENTA "\nenable_if std\n" END << std::endl;;

  short int i = 1;    // code does not compile if type of i is not integral

  std::cout << std::boolalpha;
  std::cout << "i is odd: " << is_odd(i) << std::endl;
  std::cout << "i is even: " << is_even(i) << std::endl;
}*/


// 🔥MAIN make pair 🔥//
/*#include <utility>      // std::pair
#include <iostream>     // std::cout

{
  std::cout << YELLOW "\nmake pair std\n" END << std::endl;;

  std::pair <int,int> foo;
  std::pair <int,int> bar;

  foo = std::make_pair (10,20);
  bar = std::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>

  std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
  std::cout << "bar: " << bar.first << ", " << bar.second << '\n';
}
{
  std::cout << MAGENTA "\nmake pair ft\n" END << std::endl;;

  ft::pair <int,int> foo;
  ft::pair <int,int> bar;

  foo = ft::make_pair (10,20);
  bar = ft::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>

  std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
  std::cout << "bar: " << bar.first << ", " << bar.second << '\n';
}


// 🔥 MAIN PAIR 🔥//
#include <utility>      // std::pair, std::make_pair
#include <string>       // std::string
#include <iostream>     // std::cout
 {
  std::cout << YELLOW "\npair std\n" END << std::endl;;

  std::pair <std::string,double> product1;                     // default constructor
  std::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
  std::pair <std::string,double> product3 (product2);          // copy constructor

  product1 = std::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)

  product2.first = "shoes";                  // the type of first is string
  product2.second = 39.90;                   // the type of second is double

  std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
  std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
  std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
}
 {
  std::cout << MAGENTA "\npair ft\n" END << std::endl;;

  ft::pair <std::string,double> product1;                     // default constructor
  ft::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
  ft::pair <std::string,double> product3 (product2);          // copy constructor

  product1 = ft::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)

  product2.first = "shoes";                  // the type of first is string
  product2.second = 39.90;                   // the type of second is double

  std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
  std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
  std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
}*/



// 🔥 MAIN is_integral 🔥
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

// 🔥 MAIN lexicographie 🔥 
/*#include <iostream>     // std::cout, std::boolalpha
#include <algorithm>    // std::lexicographical_compare
#include <cctype>       // std::tolower
  {
	std::cout << YELLOW "\nlexicographie std\n" END << std::endl;;

	char foo[]="Apple";
	char bar[]="apartment";

	std::cout << std::boolalpha;

	std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

	std::cout << "Using default comparison (operator<): ";
	std::cout << std::lexicographical_compare(foo,foo+5,bar,bar+9);
	std::cout << '\n';

	std::cout << "Using mycomp as comparison object: ";
	std::cout << std::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp);
	std::cout << '\n';
  }
  {
	std::cout << MAGENTA  "\nlexicographie ft\n" END << std::endl;;

	char foo[]="Apple";
	char bar[]="apartment";

	std::cout << std::boolalpha;

	std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

	std::cout << "Using default comparison (operator<): ";
	std::cout << ft::lexicographical_compare(foo,foo+5,bar,bar+9);
	std::cout << '\n';

	std::cout << "Using mycomp as comparison object: ";
	std::cout << ft::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp);
	std::cout << '\n';

  }


// 🔥 MAIN equal 🔥 
  {
	std::cout << YELLOW "\nequal std\n" END << std::endl;;

	int myints[] = {20,40,60,80,100};               //   myints: 20 40 60 80 100
	std::vector<int>myvector (myints,myints+5);     // myvector: 20 40 60 80 100

	// using default comparison:
	if ( std::equal (myvector.begin(), myvector.end(), myints) )
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n";

	myvector[3]=81;                                 // myvector: 20 40 60 81 100

	// using predicate comparison:
	if ( std::equal (myvector.begin(), myvector.end(), myints, mypredicate) )
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n";
  }
  {
	std::cout << MAGENTA  "\nequal ft\n" END << std::endl;;

	int myints[] = {20,40,60,80,100};               //   myints: 20 40 60 80 100
	ft::vector<int>myvector (myints,myints+5);     // myvector: 20 40 60 80 100

	// using default comparison:
	if ( ft::equal (myvector.begin(), myvector.end(), myints) )
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n";

	myvector[3]=81;                                 // myvector: 20 40 60 81 100

	// using predicate comparison:
	if ( ft::equal (myvector.begin(), myvector.end(), myints, mypredicate) )
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n";

  }

*/
//   return 0;
// }