#pragma once

#include <iostream>

namespace ft
{
template <typename T1, typename T2> 
struct pair
{
	public:
		//constructors
		pair() : first(), second() {};
		pair (const T1& a, const T2& b) : first(a), second(b) {};
		template<typename U, typename V>
		pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {};
		pair (const pair& pr) : first(pr.first), second(pr.second) {};

		//operator
		pair& operator= (const pair& pr)
		{
			this->first = pr.getFirst();
			this->second = pr.getSecond();
			return (*this);
		};

		//getters and setters
		T1 getFirst() const { return (this->first); };
		T2 getSecond() const { return (this->second); };
		void setFirst(T1 f) { this->first = f; };
		void setSecond(T2 s) { this->second = s; };

	private:
		T1  first;
		T2  second;

};

template <class T1, class T2>
  bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return lhs.getFirst()==rhs.getFirst() && lhs.getSecond()==rhs.getSecond(); }

template <class T1, class T2>
  bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(lhs==rhs); }

template <class T1, class T2>
  bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return lhs.getFirst()<rhs.getFirst() || (!(rhs.getFirst()<lhs.getFirst()) && lhs.getSecond()<rhs.getSecond()); }

template <class T1, class T2>
  bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(rhs<lhs); }

template <class T1, class T2>
  bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return rhs<lhs; }

template <class T1, class T2>
  bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(lhs<rhs); }

}
