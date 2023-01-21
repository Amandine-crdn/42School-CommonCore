#pragma once

#include <iterator>

#include "../includes/vector.hpp"
#include <algorithm>
#include "Traits_iterators.hpp"
#include "ReverseIterator.hpp"

namespace ft
{
/*
**==========================
** CLASS VECTOR ITERATOR
**==========================
*/
	template <class T>
	class vector_iterator
	{
		public :
			typedef std::random_access_iterator_tag iterator_category; //tag of our iterator
			typedef std::ptrdiff_t					difference_type; // use to identify distance between iterators steps
			typedef T								value_type;
			typedef value_type*						pointer;
			typedef value_type&						reference;
			typedef vector_iterator 				iterator;

		/*
		**==========================
		**    CANONICAL FORM
		**==========================
		*/
		vector_iterator()
		{
			this->_ptr = NULL;
		}

		vector_iterator(pointer const ptr)
		{
			this->_ptr = ptr;
		}

		vector_iterator(const vector_iterator &x)
		{
			this->_ptr = x._ptr;
		}

		template<class Iter>
		vector_iterator(const vector_iterator<Iter>& i) : _ptr(i.base()) {};

		~vector_iterator() {}

		pointer	base() const
		{
			return (this->_ptr);
		}


		/*
		**==========================
		**   IMPLEMENT OPERATORS
		**==========================
		*/

		//renvoie la valeur pointé par l'iterator
		reference operator*() const
		{
			return *this->_ptr;
		}

		//renvoie l'addresse du pointer de l'iterator
		pointer operator->() const
		{
			return this->_ptr;
		}

		iterator& operator++() // prefix incrementation
		{
			this->_ptr++;
			return *this;
		}

		iterator operator++(int) // postfix incrementation
		{
			iterator tmp = *this;
			++this->_ptr;
			return (tmp);
		}

		iterator& operator--()
		{
			this->_ptr--;
			return (*this);
		}

		iterator operator--(int)
		{
			iterator tmp = *this;
			--this->_ptr;
			return tmp;
		}

		iterator& operator=(const iterator &other)
		{
			if (this != &other)
				this->_ptr = other._ptr;
			return (*this);
		}

		iterator& operator+=(difference_type n)
		{
			this->_ptr += n;
			return (*this);
		}

		iterator& operator-=(difference_type n)
		{
			this->_ptr -= n;
			return *this;
		}

		reference operator[](size_t n) //access to the element n
		{
			return (this->_ptr[n]);
		}

		difference_type operator-(const iterator &other) const // take 2 operators and do the difference between iterators
		{
			difference_type res = this->_ptr - other._ptr;
			return(res);
		}

		iterator	operator+(const difference_type &n) const {
			return iterator(_ptr + n);
		}

		difference_type operator+(const iterator &other) const // take 2 operators and do the addition between the 2iterators
		{
			difference_type res = this->_ptr + other._ptr;
			return(res);
		}

		iterator	operator-(const difference_type &n) const {
			return iterator(_ptr - n);
		}

		private :
			pointer _ptr;
	};

/*
**==========================
** NON MEMBER FUNCTION BOOL
**==========================
*/
	template<typename IteratorL, typename IteratorR>
	inline bool
	operator==(const vector_iterator<IteratorL>& lhs,
			   const vector_iterator<IteratorR>& rhs) {
		return lhs.base() == rhs.base(); }

	template<typename IteratorL, typename IteratorR>
	inline bool
	operator!=(const vector_iterator<IteratorL>& lhs,
			   const vector_iterator<IteratorR>& rhs) {
		return lhs.base() != rhs.base(); }

	template<typename IteratorL, typename IteratorR>
	inline bool
	operator<(const vector_iterator<IteratorL>& lhs,
			  const vector_iterator<IteratorR>& rhs) {
		return lhs.base() < rhs.base(); }

	template<typename IteratorL, typename IteratorR>
	inline bool
	operator>(const vector_iterator<IteratorL>& lhs,
			  const vector_iterator<IteratorR>& rhs)
	{ return lhs.base() > rhs.base(); }

	template<typename IteratorL, typename IteratorR>
	inline bool
	operator<=(const vector_iterator<IteratorL>& lhs,
			   const vector_iterator<IteratorR>& rhs)
	{ return lhs.base() <= rhs.base(); }

	template<typename IteratorL, typename IteratorR>
	inline bool
	operator>=(const vector_iterator<IteratorL>& lhs,
			   const vector_iterator<IteratorR>& rhs)
	{ return lhs.base() >= rhs.base(); }

	template<class IteratorL, class IteratorR>
	inline typename vector_iterator<IteratorL>::difference_type
	operator-(const vector_iterator<IteratorL>& lhs,
				const vector_iterator<IteratorR>& rhs) {
		return lhs.base() - rhs.base();
	}

	template<class IteratorL, class IteratorR>
	inline typename vector_iterator<IteratorL>::difference_type
	operator+(const vector_iterator<IteratorL>& lhs,
			  const vector_iterator<IteratorR>& rhs) {
		return lhs.base() + rhs.base();
	}

	template<typename Iterator>
	inline vector_iterator<Iterator>
	operator+(typename vector_iterator<Iterator>::difference_type lhs,
				const vector_iterator<Iterator>& rhs) {
		return vector_iterator<Iterator>(rhs.base() + lhs);
	}

	template<typename Iterator>
	inline vector_iterator<Iterator>
	operator-(typename vector_iterator<Iterator>::difference_type lhs,
			  const vector_iterator<Iterator>& rhs) {
		return vector_iterator<Iterator>(rhs.base() - lhs);
	}
}
