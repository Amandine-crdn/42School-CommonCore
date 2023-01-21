#pragma once

#include <iostream>

/* lexicographical_compare : strcomp
Lexicographical less-than comparison
Returns true if the range [first1,last1) compares lexicographically
less than the range [first2,last2).*/

namespace ft
{
	template <typename InputIterator1, typename InputIterator2>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2)
{
	while (first1 != last1)
	{
		if (first2 == last2 || *first1 > *first2)
			return (false);
		else if (*first1 < *first2)
			return (true);
		first1++;
		first2++;
	}
	return (first2 != last2);
}

	template <typename InputIterator1, typename InputIterator2, typename Compare>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
{
	while (first1 != last1)
	{
		if (first2 == last2 || comp(*first1,*first2) == false)
			return (false);
		else if (comp(*first1, *first2) == true)
			return (true);
		first1++;
		first2++;
	}
	return (first2 != last2);
}

}