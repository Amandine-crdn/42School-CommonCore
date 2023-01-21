#pragma once

#include <iostream>

/*Test whether the elements in two ranges are equal.
Compares the elements in the range [first1,last1) 
with those in the range beginning at first2, and 
returns true if all of the elements in both ranges match.*/

namespace ft
{
	template <typename InputIterator1, typename InputIterator2>
bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
{
	while (first1 != last1)
	{
		if (*first1 != *first2)
			return (false);
		first1++;
		first2++;
	}
	return (true);
}

	template <typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
{
	while (first1 != last1)
	{
		if (pred(*first1, *first2) == false)
			return (false);
		first1++;
		first2++;
	}
	return (true);
}

}