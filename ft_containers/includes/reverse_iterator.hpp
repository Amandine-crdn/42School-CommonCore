#pragma once

#include "iterator_traits.hpp"
#include <iterator>

namespace ft
{
	template <class Iter> 
	class reverse_iterator
	{
		public:
			typedef Iter														iterator_type;
			typedef typename ft::iterator_traits<Iter>::iterator_category		iterator_category;
			typedef typename ft::iterator_traits<Iter>::value_type				value_type;
			typedef typename ft::iterator_traits<Iter>::difference_type			difference_type;
			typedef typename ft::iterator_traits<Iter>::pointer					pointer;
			typedef typename ft::iterator_traits<Iter>::reference				reference;
		
		/* Construtors */ 
			reverse_iterator() : _iter() {};

			explicit reverse_iterator (Iter it) : _iter(it) {};

			reverse_iterator (const reverse_iterator<Iter>& rev_it): _iter(rev_it.base()) {};

		/*	Dereference iterator */
			reference operator*() const
			{
				Iter copy_iterator(this->_iter);

				return *(--copy_iterator);
			}
			pointer operator->() const { return &(operator*()); }
			reference operator[] (difference_type n) const { return this->_iter[-n-1]; } //[n]



			reverse_iterator& operator=( const reverse_iterator<Iter>& other )
			{
				this->_iter = other._iter;
				return *this;
			}
			// reverse_iterator &operator= (reverse_iterator const &copie)
			// {
			// 	this->_iter = copie._iter;
			// 	return *this;
				
			// };
		/*  Operators calculus */
			reverse_iterator operator+(difference_type n) const { return reverse_iterator(this->_iter - n); };
			reverse_iterator operator-(difference_type n) const { return reverse_iterator(this->_iter + n); };

			//operators post et pre incrementation
			reverse_iterator& operator++()
			{
				--this->_iter; 
				return *this; 
			};
			reverse_iterator  operator++(int)
			{
				reverse_iterator temp(*this); 
				++*this;
				return temp;
			}
			reverse_iterator& operator--()
			{
				++this->_iter; 
				return *this; 
			};
			reverse_iterator  operator--(int)
			{
				reverse_iterator temp(*this);
				--*this;
				return temp;
			}

			//operators Retrocede and Advance 
			reverse_iterator& operator+= (difference_type n)
			{
				this->_iter -= n;
				return *this;
			};
			reverse_iterator& operator-= (difference_type n)
			{
				this->_iter += n;
				return *this;
			};

		/* getters & setters */
			iterator_type base() const { return this->_iter; };

		protected:
			iterator_type _iter;
	};


////// No membres functions //////

	//  Relational operators 
template< class Iterator1, class Iterator2 >
bool operator==(reverse_iterator< Iterator1 > const& lhs, reverse_iterator< Iterator2 > const& rhs) { return lhs.base() == rhs.base(); }

template< class Iterator1, class Iterator2 >
bool operator!=(reverse_iterator< Iterator1 > const& lhs, reverse_iterator< Iterator2 > const& rhs) { return lhs.base() != rhs.base(); }

template< class Iterator1, class Iterator2 >
bool operator<(reverse_iterator< Iterator1 > const& lhs, reverse_iterator< Iterator2 > const& rhs) { return lhs.base() > rhs.base(); }

template< class Iterator1, class Iterator2 >
bool operator<=(reverse_iterator< Iterator1 > const& lhs, reverse_iterator< Iterator2 > const& rhs) { return lhs.base() >= rhs.base(); }

template< class Iterator1, class Iterator2 >
bool operator>(reverse_iterator< Iterator1 > const& lhs, reverse_iterator< Iterator2 > const& rhs) { return lhs.base() < rhs.base(); }

template< class Iterator1, class Iterator2 >
bool operator>=(reverse_iterator< Iterator1 > const& lhs, reverse_iterator< Iterator2 > const& rhs) { return lhs.base() <= rhs.base(); }

	// Addition and substraction operator
template< class Iterator >
reverse_iterator< Iterator > operator+(typename reverse_iterator< Iterator >::difference_type n, reverse_iterator< Iterator > const& rev_it) { return rev_it + n; }

template< class Iterator1, class Iterator2 >
typename reverse_iterator< Iterator1 >::difference_type operator-(reverse_iterator< Iterator1 > const& lhs, reverse_iterator< Iterator2 > const& rhs) { return rhs.base() - lhs.base(); }

}
